#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Audio_NoteDisable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011F4C: lw          $t6, 0xB0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB0);
    // 0x80011F50: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80011F54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80011F58: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80011F5C: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80011F60: bne         $t8, $at, L_80011F74
    if (ctx->r24 != ctx->r1) {
        // 0x80011F64: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80011F74;
    }
    // 0x80011F64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80011F68: lbu         $t9, 0xB0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0XB0);
    // 0x80011F6C: andi        $t0, $t9, 0xFFBF
    ctx->r8 = ctx->r25 & 0XFFBF;
    // 0x80011F70: sb          $t0, 0xB0($a0)
    MEM_B(0XB0, ctx->r4) = ctx->r8;
L_80011F74:
    // 0x80011F74: lbu         $t1, 0xB0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XB0);
    // 0x80011F78: sb          $zero, 0x30($a0)
    MEM_B(0X30, ctx->r4) = 0;
    // 0x80011F7C: sb          $zero, 0x34($a0)
    MEM_B(0X34, ctx->r4) = 0;
    // 0x80011F80: andi        $t2, $t1, 0xFF7F
    ctx->r10 = ctx->r9 & 0XFF7F;
    // 0x80011F84: sb          $t2, 0xB0($a0)
    MEM_B(0XB0, ctx->r4) = ctx->r10;
    // 0x80011F88: lbu         $t3, 0xB0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XB0);
    // 0x80011F8C: sw          $v0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r2;
    // 0x80011F90: sw          $v0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->r2;
    // 0x80011F94: andi        $t4, $t3, 0xFFDF
    ctx->r12 = ctx->r11 & 0XFFDF;
    // 0x80011F98: sb          $t4, 0xB0($a0)
    MEM_B(0XB0, ctx->r4) = ctx->r12;
    // 0x80011F9C: sb          $zero, 0x59($a0)
    MEM_B(0X59, ctx->r4) = 0;
    // 0x80011FA0: jr          $ra
    // 0x80011FA4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80011FA4: swc1        $f4, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void Effect_Effect382_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B040: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007B044: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007B048: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007B04C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007B050: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007B054: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8007B058: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8007B05C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8007B060: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007B064: jal         0x800A73E4
    // 0x8007B068: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_0;
    // 0x8007B068: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007B06C: beq         $v0, $zero, L_8007B0C8
    if (ctx->r2 == 0) {
        // 0x8007B070: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8007B0C8;
    }
    // 0x8007B070: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B074: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007B078: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007B07C: addiu       $v0, $v0, -0x7D14
    ctx->r2 = ADD32(ctx->r2, -0X7D14);
    // 0x8007B080: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007B084: lwc1        $f6, 0x6C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007B088: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007B08C: lwc1        $f0, 0x73C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73C4);
    // 0x8007B090: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8007B094: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x8007B098: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007B09C: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8007B0A0: sll         $t1, $t7, 2
    ctx->r9 = S32(ctx->r15 << 2);
    // 0x8007B0A4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8007B0A8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007B0AC: sll         $t4, $t7, 2
    ctx->r12 = S32(ctx->r15 << 2);
    // 0x8007B0B0: swc1        $f10, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f10.u32l;
    // 0x8007B0B4: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007B0B8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8007B0BC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8007B0C0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007B0C4: swc1        $f18, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->f18.u32l;
L_8007B0C8:
    // 0x8007B0C8: lhu         $t6, 0x50($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X50);
    // 0x8007B0CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B0D0: bnel        $t6, $zero, L_8007B0E4
    if (ctx->r14 != 0) {
        // 0x8007B0D4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007B0E4;
    }
    goto skip_0;
    // 0x8007B0D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8007B0D8: jal         0x80060FBC
    // 0x8007B0DC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007B0DC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
    // 0x8007B0E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007B0E4:
    // 0x8007B0E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007B0E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007B0EC: jr          $ra
    // 0x8007B0F0: nop

    return;
    // 0x8007B0F0: nop

;}
RECOMP_FUNC void PlayerShot_TorpedoTrail_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035D30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035D34: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80035D38: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80035D3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035D40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80035D44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80035D48: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80035D4C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80035D50: jal         0x80061474
    // 0x80035D54: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80035D54: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80035D58: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80035D5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80035D60: addiu       $t7, $zero, 0x15F
    ctx->r15 = ADD32(0, 0X15F);
    // 0x80035D64: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80035D68: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80035D6C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80035D70: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80035D74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80035D78: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80035D7C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80035D80: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80035D84: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80035D88: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80035D8C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80035D90: swc1        $f10, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f10.u32l;
    // 0x80035D94: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x80035D98: lwc1        $f16, 0x50F0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50F0);
    // 0x80035D9C: sh          $t8, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r24;
    // 0x80035DA0: sh          $t9, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r25;
    // 0x80035DA4: jal         0x80004EB0
    // 0x80035DA8: swc1        $f16, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80035DA8: swc1        $f16, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f16.u32l;
    after_1:
    // 0x80035DAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80035DB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80035DB4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80035DB8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80035DBC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80035DC0: bc1f        L_80035DD4
    if (!c1cs) {
        // 0x80035DC4: nop
    
            goto L_80035DD4;
    }
    // 0x80035DC4: nop

    // 0x80035DC8: lh          $t0, 0x48($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X48);
    // 0x80035DCC: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80035DD0: sh          $t1, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r9;
L_80035DD4:
    // 0x80035DD4: jal         0x800612B8
    // 0x80035DD8: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x80035DD8: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_2:
    // 0x80035DDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035DE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035DE4: jr          $ra
    // 0x80035DE8: nop

    return;
    // 0x80035DE8: nop

;}
RECOMP_FUNC void Effect_Effect357_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007905C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80079060: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079064: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80079068: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007906C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80079070: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x80079074: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80079078: jal         0x80061474
    // 0x8007907C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007907C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80079080: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80079084: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80079088: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007908C: addiu       $t7, $zero, 0x165
    ctx->r15 = ADD32(0, 0X165);
    // 0x80079090: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80079094: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80079098: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8007909C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800790A0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800790A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800790A8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x800790AC: lbu         $t8, 0x77($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X77);
    // 0x800790B0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800790B4: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x800790B8: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    // 0x800790BC: lwc1        $f8, 0x7320($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7320);
    // 0x800790C0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800790C4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800790C8: nop

    // 0x800790CC: bc1f        L_80079100
    if (!c1cs) {
        // 0x800790D0: nop
    
            goto L_80079100;
    }
    // 0x800790D0: nop

    // 0x800790D4: lwc1        $f10, 0x40C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800790D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800790DC: lwc1        $f0, 0x7324($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x800790E0: sub.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800790E4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800790E8: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x800790EC: lwc1        $f8, 0x414($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X414);
    // 0x800790F0: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800790F4: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800790F8: b           L_800793E0
    // 0x800790FC: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
        goto L_800793E0;
    // 0x800790FC: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
L_80079100:
    // 0x80079100: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079104: lwc1        $f8, 0x7328($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7328);
    // 0x80079108: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007910C: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x80079110: nop

    // 0x80079114: bc1f        L_80079180
    if (!c1cs) {
        // 0x80079118: nop
    
            goto L_80079180;
    }
    // 0x80079118: nop

    // 0x8007911C: jal         0x80004EB0
    // 0x80079120: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80079120: nop

    after_1:
    // 0x80079124: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079128: lwc1        $f10, 0x732C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X732C);
    // 0x8007912C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079130: lwc1        $f6, 0x7330($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7330);
    // 0x80079134: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80079138: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007913C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80079140: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80079144: jal         0x80004EB0
    // 0x80079148: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80079148: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8007914C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079150: lwc1        $f4, 0x7334($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7334);
    // 0x80079154: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079158: lwc1        $f8, 0x7338($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7338);
    // 0x8007915C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80079160: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80079164: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80079168: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007916C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80079170: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80079174: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80079178: b           L_800793E0
    // 0x8007917C: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
        goto L_800793E0;
    // 0x8007917C: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
L_80079180:
    // 0x80079180: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079184: lwc1        $f10, 0x733C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X733C);
    // 0x80079188: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007918C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80079190: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80079194: nop

    // 0x80079198: bc1f        L_800791E8
    if (!c1cs) {
        // 0x8007919C: nop
    
            goto L_800791E8;
    }
    // 0x8007919C: nop

    // 0x800791A0: jal         0x80004EB0
    // 0x800791A4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x800791A4: nop

    after_3:
    // 0x800791A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800791AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800791B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800791B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800791B8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800791BC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800791C0: jal         0x80004EB0
    // 0x800791C4: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x800791C4: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x800791C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800791CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800791D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800791D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800791D8: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800791DC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800791E0: b           L_800793E0
    // 0x800791E4: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
        goto L_800793E0;
    // 0x800791E4: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
L_800791E8:
    // 0x800791E8: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800791EC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800791F0: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800791F4: bne         $t9, $at, L_80079348
    if (ctx->r25 != ctx->r1) {
        // 0x800791F8: lui         $t0, 0x8017
        ctx->r8 = S32(0X8017 << 16);
            goto L_80079348;
    }
    // 0x800791F8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800791FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079200: lwc1        $f6, 0x7340($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7340);
    // 0x80079204: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80079208: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8007920C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80079210: nop

    // 0x80079214: bc1t        L_80079230
    if (c1cs) {
        // 0x80079218: nop
    
            goto L_80079230;
    }
    // 0x80079218: nop

    // 0x8007921C: lwc1        $f8, 0x7344($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7344);
    // 0x80079220: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x80079224: nop

    // 0x80079228: bc1f        L_80079348
    if (!c1cs) {
        // 0x8007922C: nop
    
            goto L_80079348;
    }
    // 0x8007922C: nop

L_80079230:
    // 0x80079230: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80079234: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80079238: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8007923C: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80079240: lwc1        $f2, 0x7C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x80079244: sub.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80079248: sub.s       $f14, $f2, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8007924C: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x80079250: jal         0x80005100
    // 0x80079254: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_5;
    // 0x80079254: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x80079258: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007925C: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80079260: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80079264: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80079268: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007926C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80079270: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80079274: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80079278: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8007927C: jal         0x80005100
    // 0x80079280: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_6;
    // 0x80079280: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_6:
    // 0x80079284: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80079288: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007928C: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80079290: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80079294: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80079298: jal         0x80005E90
    // 0x8007929C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x8007929C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800792A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800792A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800792A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800792AC: jal         0x80005D44
    // 0x800792B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x800792B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x800792B4: jal         0x80004EB0
    // 0x800792B8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x800792B8: nop

    after_9:
    // 0x800792BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800792C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800792C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800792C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800792CC: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800792D0: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800792D4: jal         0x80004EB0
    // 0x800792D8: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x800792D8: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x800792DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800792E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800792E4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800792E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800792EC: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800792F0: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800792F4: jal         0x80004EB0
    // 0x800792F8: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x800792F8: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x800792FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80079300: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80079304: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80079308: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007930C: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80079310: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80079314: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80079318: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8007931C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80079320: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80079324: jal         0x80006970
    // 0x80079328: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x80079328: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x8007932C: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80079330: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80079334: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80079338: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8007933C: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80079340: b           L_800793E0
    // 0x80079344: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
        goto L_800793E0;
    // 0x80079344: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
L_80079348:
    // 0x80079348: lbu         $t0, 0x7C98($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X7C98);
    // 0x8007934C: bne         $t0, $zero, L_80079378
    if (ctx->r8 != 0) {
        // 0x80079350: nop
    
            goto L_80079378;
    }
    // 0x80079350: nop

    // 0x80079354: jal         0x80004EB0
    // 0x80079358: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x80079358: nop

    after_13:
    // 0x8007935C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80079360: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80079364: nop

    // 0x80079368: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007936C: add.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80079370: b           L_8007939C
    // 0x80079374: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_8007939C;
    // 0x80079374: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80079378:
    // 0x80079378: jal         0x80004EB0
    // 0x8007937C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x8007937C: nop

    after_14:
    // 0x80079380: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80079384: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80079388: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007938C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80079390: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80079394: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80079398: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_8007939C:
    // 0x8007939C: jal         0x80004EB0
    // 0x800793A0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x800793A0: nop

    after_15:
    // 0x800793A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800793A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800793AC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800793B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800793B4: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800793B8: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800793BC: jal         0x80004EB0
    // 0x800793C0: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x800793C0: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    after_16:
    // 0x800793C4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800793C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800793CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800793D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800793D4: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800793D8: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800793DC: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
L_800793E0:
    // 0x800793E0: jal         0x80004EB0
    // 0x800793E4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_17;
    // 0x800793E4: nop

    after_17:
    // 0x800793E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800793EC: lwc1        $f8, 0x7348($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7348);
    // 0x800793F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800793F4: lwc1        $f6, 0x734C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X734C);
    // 0x800793F8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800793FC: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80079400: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80079404: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80079408: jal         0x80004EB0
    // 0x8007940C: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x8007940C: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    after_18:
    // 0x80079410: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80079414: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80079418: nop

    // 0x8007941C: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80079420: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80079424: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80079428: nop

    // 0x8007942C: addiu       $t3, $t2, 0x46
    ctx->r11 = ADD32(ctx->r10, 0X46);
    // 0x80079430: jal         0x80004EB0
    // 0x80079434: sh          $t3, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r11;
    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x80079434: sh          $t3, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r11;
    after_19:
    // 0x80079438: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007943C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80079440: nop

    // 0x80079444: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80079448: jal         0x80004EB0
    // 0x8007944C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x8007944C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    after_20:
    // 0x80079450: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80079454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80079458: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007945C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80079460: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80079464: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80079468: jal         0x80004EB0
    // 0x8007946C: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x8007946C: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
    after_21:
    // 0x80079470: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80079474: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80079478: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007947C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80079480: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80079484: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80079488: jal         0x80004EB0
    // 0x8007948C: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x8007948C: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    after_22:
    // 0x80079490: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80079494: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80079498: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007949C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800794A0: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800794A4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800794A8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x800794AC: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800794B0: jal         0x800612B8
    // 0x800794B4: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_23;
    // 0x800794B4: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    after_23:
    // 0x800794B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800794BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800794C0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800794C4: jr          $ra
    // 0x800794C8: nop

    return;
    // 0x800794C8: nop

;}
RECOMP_FUNC void Message_PtrFromId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2830: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C2834: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800C2838: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C283C: addiu       $v0, $v0, 0x5CBC
    ctx->r2 = ADD32(ctx->r2, 0X5CBC);
    // 0x800C2840: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800C2844: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800C2848: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C284C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C2850: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C2854: beq         $a2, $t7, L_800C2884
    if (ctx->r6 == ctx->r15) {
        // 0x800C2858: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_800C2884;
    }
    // 0x800C2858: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C285C: addiu       $t8, $t8, 0x5CBC
    ctx->r24 = ADD32(ctx->r24, 0X5CBC);
    // 0x800C2860: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
L_800C2864:
    // 0x800C2864: bnel        $v0, $a1, L_800C2878
    if (ctx->r2 != ctx->r5) {
        // 0x800C2868: lw          $a1, 0x8($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X8);
            goto L_800C2878;
    }
    goto skip_0;
    // 0x800C2868: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    skip_0:
    // 0x800C286C: jr          $ra
    // 0x800C2870: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    return;
    // 0x800C2870: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x800C2874: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
L_800C2878:
    // 0x800C2878: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C287C: bne         $a2, $a1, L_800C2864
    if (ctx->r6 != ctx->r5) {
        // 0x800C2880: nop
    
            goto L_800C2864;
    }
    // 0x800C2880: nop

L_800C2884:
    // 0x800C2884: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C2888: jr          $ra
    // 0x800C288C: nop

    return;
    // 0x800C288C: nop

;}
RECOMP_FUNC void HUD_Texture_Scroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008BD00: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008BD04: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8008BD08: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8008BD0C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8008BD10: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x8008BD14: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8008BD18: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8008BD1C: or          $fp, $a2, $zero
    ctx->r30 = ctx->r6 | 0;
    // 0x8008BD20: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008BD24: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8008BD28: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8008BD2C: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8008BD30: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8008BD34: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8008BD38: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8008BD3C: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8008BD40: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x8008BD44: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x8008BD48: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008BD4C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008BD50: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x8008BD54: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8008BD58: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x8008BD5C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8008BD60: and         $t7, $a0, $at
    ctx->r15 = ctx->r4 & ctx->r1;
    // 0x8008BD64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008BD68: addu        $ra, $t6, $t7
    ctx->r31 = ADD32(ctx->r14, ctx->r15);
    // 0x8008BD6C: beq         $a3, $zero, L_8008BD98
    if (ctx->r7 == 0) {
        // 0x8008BD70: addu        $ra, $ra, $at
        ctx->r31 = ADD32(ctx->r31, ctx->r1);
            goto L_8008BD98;
    }
    // 0x8008BD70: addu        $ra, $ra, $at
    ctx->r31 = ADD32(ctx->r31, ctx->r1);
    // 0x8008BD74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008BD78: beq         $a3, $at, L_8008BF3C
    if (ctx->r7 == ctx->r1) {
        // 0x8008BD7C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008BF3C;
    }
    // 0x8008BD7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008BD80: beq         $a3, $at, L_8008BFCC
    if (ctx->r7 == ctx->r1) {
        // 0x8008BD84: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8008BFCC;
    }
    // 0x8008BD84: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008BD88: beq         $a3, $at, L_8008C030
    if (ctx->r7 == ctx->r1) {
        // 0x8008BD8C: nop
    
            goto L_8008C030;
    }
    // 0x8008BD8C: nop

    // 0x8008BD90: b           L_8008C0D8
    // 0x8008BD94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8008C0D8;
    // 0x8008BD94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8008BD98:
    // 0x8008BD98: blez        $s0, L_8008C0D4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008BD9C: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8008C0D4;
    }
    // 0x8008BD9C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8008BDA0: addiu       $t8, $fp, -0x1
    ctx->r24 = ADD32(ctx->r30, -0X1);
    // 0x8008BDA4: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BDA8: or          $t1, $ra, $zero
    ctx->r9 = ctx->r31 | 0;
    // 0x8008BDAC: mflo        $t9
    ctx->r25 = lo;
    // 0x8008BDB0: addu        $a2, $ra, $t9
    ctx->r6 = ADD32(ctx->r31, ctx->r25);
    // 0x8008BDB4: nop

L_8008BDB8:
    // 0x8008BDB8: lbu         $t6, 0x0($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X0);
    // 0x8008BDBC: slti        $at, $fp, 0x2
    ctx->r1 = SIGNED(ctx->r30) < 0X2 ? 1 : 0;
    // 0x8008BDC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008BDC4: bne         $at, $zero, L_8008BF1C
    if (ctx->r1 != 0) {
        // 0x8008BDC8: sb          $t6, 0x7B($sp)
        MEM_B(0X7B, ctx->r29) = ctx->r14;
            goto L_8008BF1C;
    }
    // 0x8008BDC8: sb          $t6, 0x7B($sp)
    MEM_B(0X7B, ctx->r29) = ctx->r14;
    // 0x8008BDCC: addiu       $t0, $fp, -0x1
    ctx->r8 = ADD32(ctx->r30, -0X1);
    // 0x8008BDD0: andi        $t7, $t0, 0x3
    ctx->r15 = ctx->r8 & 0X3;
    // 0x8008BDD4: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8008BDD8: beq         $t7, $zero, L_8008BE34
    if (ctx->r15 == 0) {
        // 0x8008BDDC: sw          $t1, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r9;
            goto L_8008BE34;
    }
    // 0x8008BDDC: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x8008BDE0: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x8008BDE4: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BDE8: addiu       $a3, $t7, 0x1
    ctx->r7 = ADD32(ctx->r15, 0X1);
    // 0x8008BDEC: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x8008BDF0: mflo        $t9
    ctx->r25 = lo;
    // 0x8008BDF4: addu        $t6, $ra, $t9
    ctx->r14 = ADD32(ctx->r31, ctx->r25);
    // 0x8008BDF8: addu        $v1, $t6, $t3
    ctx->r3 = ADD32(ctx->r14, ctx->r11);
    // 0x8008BDFC: multu       $a1, $s0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE00: mflo        $t7
    ctx->r15 = lo;
    // 0x8008BE04: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x8008BE08: addu        $v0, $t8, $ra
    ctx->r2 = ADD32(ctx->r24, ctx->r31);
L_8008BE0C:
    // 0x8008BE0C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8008BE10: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008BE14: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8008BE18: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x8008BE1C: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x8008BE20: bne         $a3, $a0, L_8008BE0C
    if (ctx->r7 != ctx->r4) {
        // 0x8008BE24: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8008BE0C;
    }
    // 0x8008BE24: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008BE28: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x8008BE2C: beq         $a1, $fp, L_8008BF1C
    if (ctx->r5 == ctx->r30) {
        // 0x8008BE30: sw          $t1, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r9;
            goto L_8008BF1C;
    }
    // 0x8008BE30: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_8008BE34:
    // 0x8008BE34: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8008BE38: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE3C: addiu       $t6, $a1, 0x1
    ctx->r14 = ADD32(ctx->r5, 0X1);
    // 0x8008BE40: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8008BE44: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8008BE48: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x8008BE4C: sll         $s2, $s0, 2
    ctx->r18 = S32(ctx->r16 << 2);
    // 0x8008BE50: sll         $s3, $s0, 2
    ctx->r19 = S32(ctx->r16 << 2);
    // 0x8008BE54: sll         $s4, $s0, 2
    ctx->r20 = S32(ctx->r16 << 2);
    // 0x8008BE58: mflo        $t7
    ctx->r15 = lo;
    // 0x8008BE5C: addu        $t8, $ra, $t7
    ctx->r24 = ADD32(ctx->r31, ctx->r15);
    // 0x8008BE60: addu        $v1, $t8, $t3
    ctx->r3 = ADD32(ctx->r24, ctx->r11);
    // 0x8008BE64: multu       $a1, $s0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE68: mflo        $s7
    ctx->r23 = lo;
    // 0x8008BE6C: addu        $t9, $s7, $t3
    ctx->r25 = ADD32(ctx->r23, ctx->r11);
    // 0x8008BE70: addu        $v0, $t9, $ra
    ctx->r2 = ADD32(ctx->r25, ctx->r31);
    // 0x8008BE74: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE78: addiu       $t6, $a1, 0x2
    ctx->r14 = ADD32(ctx->r5, 0X2);
    // 0x8008BE7C: addu        $t8, $ra, $s7
    ctx->r24 = ADD32(ctx->r31, ctx->r23);
    // 0x8008BE80: addu        $a2, $t8, $t3
    ctx->r6 = ADD32(ctx->r24, ctx->r11);
    // 0x8008BE84: mflo        $s5
    ctx->r21 = lo;
    // 0x8008BE88: addu        $t9, $s5, $t3
    ctx->r25 = ADD32(ctx->r21, ctx->r11);
    // 0x8008BE8C: addu        $a3, $t9, $ra
    ctx->r7 = ADD32(ctx->r25, ctx->r31);
    // 0x8008BE90: multu       $t6, $s0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BE94: addiu       $t9, $a1, 0x3
    ctx->r25 = ADD32(ctx->r5, 0X3);
    // 0x8008BE98: addu        $t7, $ra, $s5
    ctx->r15 = ADD32(ctx->r31, ctx->r21);
    // 0x8008BE9C: addu        $a0, $t7, $t3
    ctx->r4 = ADD32(ctx->r15, ctx->r11);
    // 0x8008BEA0: mflo        $s6
    ctx->r22 = lo;
    // 0x8008BEA4: addu        $t7, $s6, $t3
    ctx->r15 = ADD32(ctx->r22, ctx->r11);
    // 0x8008BEA8: addu        $t0, $t7, $ra
    ctx->r8 = ADD32(ctx->r15, ctx->r31);
    // 0x8008BEAC: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BEB0: addu        $t8, $ra, $s6
    ctx->r24 = ADD32(ctx->r31, ctx->r22);
    // 0x8008BEB4: addu        $t1, $t8, $t3
    ctx->r9 = ADD32(ctx->r24, ctx->r11);
    // 0x8008BEB8: mflo        $t6
    ctx->r14 = lo;
    // 0x8008BEBC: addu        $t7, $t6, $t3
    ctx->r15 = ADD32(ctx->r14, ctx->r11);
    // 0x8008BEC0: addu        $t2, $t7, $ra
    ctx->r10 = ADD32(ctx->r15, ctx->r31);
L_8008BEC4:
    // 0x8008BEC4: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8008BEC8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8008BECC: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x8008BED0: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x8008BED4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8008BED8: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8008BEDC: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x8008BEE0: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x8008BEE4: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8008BEE8: addu        $t0, $t0, $s2
    ctx->r8 = ADD32(ctx->r8, ctx->r18);
    // 0x8008BEEC: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8008BEF0: lbu         $t7, 0x0($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X0);
    // 0x8008BEF4: addu        $t2, $t2, $s4
    ctx->r10 = ADD32(ctx->r10, ctx->r20);
    // 0x8008BEF8: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8008BEFC: sb          $t7, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r15;
    // 0x8008BF00: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
    // 0x8008BF04: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8008BF08: addu        $a3, $a3, $s1
    ctx->r7 = ADD32(ctx->r7, ctx->r17);
    // 0x8008BF0C: bne         $a1, $fp, L_8008BEC4
    if (ctx->r5 != ctx->r30) {
        // 0x8008BF10: addu        $v1, $v1, $t4
        ctx->r3 = ADD32(ctx->r3, ctx->r12);
            goto L_8008BEC4;
    }
    // 0x8008BF10: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8008BF14: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x8008BF18: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
L_8008BF1C:
    // 0x8008BF1C: lbu         $t6, 0x7B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X7B);
    // 0x8008BF20: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008BF24: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8008BF28: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008BF2C: bne         $t3, $s0, L_8008BDB8
    if (ctx->r11 != ctx->r16) {
        // 0x8008BF30: sb          $t6, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r14;
            goto L_8008BDB8;
    }
    // 0x8008BF30: sb          $t6, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r14;
    // 0x8008BF34: b           L_8008C0D8
    // 0x8008BF38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8008C0D8;
    // 0x8008BF38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8008BF3C:
    // 0x8008BF3C: blez        $s0, L_8008C0D4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008BF40: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8008C0D4;
    }
    // 0x8008BF40: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8008BF44: addiu       $t7, $fp, -0x1
    ctx->r15 = ADD32(ctx->r30, -0X1);
    // 0x8008BF48: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BF4C: or          $v1, $ra, $zero
    ctx->r3 = ctx->r31 | 0;
    // 0x8008BF50: addiu       $t0, $fp, -0x2
    ctx->r8 = ADD32(ctx->r30, -0X2);
    // 0x8008BF54: mflo        $t8
    ctx->r24 = lo;
    // 0x8008BF58: addu        $a3, $t8, $ra
    ctx->r7 = ADD32(ctx->r24, ctx->r31);
    // 0x8008BF5C: nop

L_8008BF60:
    // 0x8008BF60: lbu         $t1, 0x0($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X0);
    // 0x8008BF64: bltz        $t0, L_8008BFB0
    if (SIGNED(ctx->r8) < 0) {
        // 0x8008BF68: or          $a1, $t0, $zero
        ctx->r5 = ctx->r8 | 0;
            goto L_8008BFB0;
    }
    // 0x8008BF68: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8008BF6C: multu       $a1, $s0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BF70: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x8008BF74: addiu       $a2, $a1, -0x1
    ctx->r6 = ADD32(ctx->r5, -0X1);
    // 0x8008BF78: mflo        $t9
    ctx->r25 = lo;
    // 0x8008BF7C: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x8008BF80: addu        $v0, $t6, $ra
    ctx->r2 = ADD32(ctx->r14, ctx->r31);
    // 0x8008BF84: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008BF88: mflo        $t8
    ctx->r24 = lo;
    // 0x8008BF8C: addu        $t9, $ra, $t8
    ctx->r25 = ADD32(ctx->r31, ctx->r24);
    // 0x8008BF90: addu        $a0, $t9, $t3
    ctx->r4 = ADD32(ctx->r25, ctx->r11);
L_8008BF94:
    // 0x8008BF94: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8008BF98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8008BF9C: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8008BFA0: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8008BFA4: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    // 0x8008BFA8: bgez        $a2, L_8008BF94
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8008BFAC: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_8008BF94;
    }
    // 0x8008BFAC: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
L_8008BFB0:
    // 0x8008BFB0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008BFB4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008BFB8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8008BFBC: bne         $t3, $s0, L_8008BF60
    if (ctx->r11 != ctx->r16) {
        // 0x8008BFC0: sb          $t1, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r9;
            goto L_8008BF60;
    }
    // 0x8008BFC0: sb          $t1, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r9;
    // 0x8008BFC4: b           L_8008C0D8
    // 0x8008BFC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8008C0D8;
    // 0x8008BFC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8008BFCC:
    // 0x8008BFCC: blez        $fp, L_8008C0D4
    if (SIGNED(ctx->r30) <= 0) {
        // 0x8008BFD0: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8008C0D4;
    }
    // 0x8008BFD0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8008BFD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008BFD8: addu        $v1, $s0, $ra
    ctx->r3 = ADD32(ctx->r16, ctx->r31);
    // 0x8008BFDC: addiu       $a2, $s0, -0x2
    ctx->r6 = ADD32(ctx->r16, -0X2);
    // 0x8008BFE0: addu        $a3, $ra, $zero
    ctx->r7 = ADD32(ctx->r31, 0);
L_8008BFE4:
    // 0x8008BFE4: lbu         $t0, -0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, -0X1);
    // 0x8008BFE8: bltz        $a2, L_8008C00C
    if (SIGNED(ctx->r6) < 0) {
        // 0x8008BFEC: or          $t3, $a2, $zero
        ctx->r11 = ctx->r6 | 0;
            goto L_8008C00C;
    }
    // 0x8008BFEC: or          $t3, $a2, $zero
    ctx->r11 = ctx->r6 | 0;
    // 0x8008BFF0: addu        $t8, $s7, $t3
    ctx->r24 = ADD32(ctx->r23, ctx->r11);
    // 0x8008BFF4: addu        $v0, $t8, $ra
    ctx->r2 = ADD32(ctx->r24, ctx->r31);
L_8008BFF8:
    // 0x8008BFF8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8008BFFC: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x8008C000: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8008C004: bgez        $t3, L_8008BFF8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8008C008: sb          $t9, 0x2($v0)
        MEM_B(0X2, ctx->r2) = ctx->r25;
            goto L_8008BFF8;
    }
    // 0x8008C008: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
L_8008C00C:
    // 0x8008C00C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008C010: sb          $t0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r8;
    // 0x8008C014: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // 0x8008C018: addu        $s7, $s7, $s0
    ctx->r23 = ADD32(ctx->r23, ctx->r16);
    // 0x8008C01C: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x8008C020: bne         $a0, $fp, L_8008BFE4
    if (ctx->r4 != ctx->r30) {
        // 0x8008C024: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8008BFE4;
    }
    // 0x8008C024: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008C028: b           L_8008C0D8
    // 0x8008C02C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8008C0D8;
    // 0x8008C02C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8008C030:
    // 0x8008C030: blez        $fp, L_8008C0D4
    if (SIGNED(ctx->r30) <= 0) {
        // 0x8008C034: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8008C0D4;
    }
    // 0x8008C034: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8008C038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8008C03C: addu        $a3, $ra, $zero
    ctx->r7 = ADD32(ctx->r31, 0);
    // 0x8008C040: addu        $a2, $ra, $s0
    ctx->r6 = ADD32(ctx->r31, ctx->r16);
L_8008C044:
    // 0x8008C044: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8008C048: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8008C04C: bne         $at, $zero, L_8008C0B8
    if (ctx->r1 != 0) {
        // 0x8008C050: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8008C0B8;
    }
    // 0x8008C050: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8008C054: addiu       $t0, $s0, -0x1
    ctx->r8 = ADD32(ctx->r16, -0X1);
    // 0x8008C058: andi        $t7, $t0, 0x3
    ctx->r15 = ctx->r8 & 0X3;
    // 0x8008C05C: beq         $t7, $zero, L_8008C084
    if (ctx->r15 == 0) {
        // 0x8008C060: addiu       $a1, $t7, 0x1
        ctx->r5 = ADD32(ctx->r15, 0X1);
            goto L_8008C084;
    }
    // 0x8008C060: addiu       $a1, $t7, 0x1
    ctx->r5 = ADD32(ctx->r15, 0X1);
    // 0x8008C064: addu        $t8, $s7, $t3
    ctx->r24 = ADD32(ctx->r23, ctx->r11);
    // 0x8008C068: addu        $v0, $t8, $ra
    ctx->r2 = ADD32(ctx->r24, ctx->r31);
L_8008C06C:
    // 0x8008C06C: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8008C070: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8008C074: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008C078: bne         $a1, $t3, L_8008C06C
    if (ctx->r5 != ctx->r11) {
        // 0x8008C07C: sb          $t9, -0x2($v0)
        MEM_B(-0X2, ctx->r2) = ctx->r25;
            goto L_8008C06C;
    }
    // 0x8008C07C: sb          $t9, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r25;
    // 0x8008C080: beq         $t3, $s0, L_8008C0B8
    if (ctx->r11 == ctx->r16) {
        // 0x8008C084: addu        $t6, $s7, $t3
        ctx->r14 = ADD32(ctx->r23, ctx->r11);
            goto L_8008C0B8;
    }
L_8008C084:
    // 0x8008C084: addu        $t6, $s7, $t3
    ctx->r14 = ADD32(ctx->r23, ctx->r11);
    // 0x8008C088: addu        $v0, $t6, $ra
    ctx->r2 = ADD32(ctx->r14, ctx->r31);
L_8008C08C:
    // 0x8008C08C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8008C090: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8008C094: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8008C098: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x8008C09C: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x8008C0A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008C0A4: sb          $t7, -0x5($v0)
    MEM_B(-0X5, ctx->r2) = ctx->r15;
    // 0x8008C0A8: sb          $t8, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r24;
    // 0x8008C0AC: sb          $t9, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r25;
    // 0x8008C0B0: bne         $t3, $s0, L_8008C08C
    if (ctx->r11 != ctx->r16) {
        // 0x8008C0B4: sb          $t6, -0x2($v0)
        MEM_B(-0X2, ctx->r2) = ctx->r14;
            goto L_8008C08C;
    }
    // 0x8008C0B4: sb          $t6, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r14;
L_8008C0B8:
    // 0x8008C0B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8008C0BC: sb          $v1, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r3;
    // 0x8008C0C0: addu        $a2, $a2, $s0
    ctx->r6 = ADD32(ctx->r6, ctx->r16);
    // 0x8008C0C4: addu        $s7, $s7, $s0
    ctx->r23 = ADD32(ctx->r23, ctx->r16);
    // 0x8008C0C8: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    // 0x8008C0CC: bne         $a0, $fp, L_8008C044
    if (ctx->r4 != ctx->r30) {
        // 0x8008C0D0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8008C044;
    }
    // 0x8008C0D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8008C0D4:
    // 0x8008C0D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8008C0D8:
    // 0x8008C0D8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8008C0DC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8008C0E0: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8008C0E4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8008C0E8: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8008C0EC: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C0F0: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8008C0F4: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8008C0F8: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8008C0FC: jr          $ra
    // 0x8008C100: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8008C100: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Player_SmartBomb(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACC7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800ACC80: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800ACC84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800ACC88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800ACC8C: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800ACC90: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800ACC94: addiu       $t7, $t7, 0x7DA0
    ctx->r15 = ADD32(ctx->r15, 0X7DA0);
    // 0x800ACC98: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800ACC9C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800ACCA0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800ACCA4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800ACCA8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800ACCAC: beq         $v1, $zero, L_800ACDAC
    if (ctx->r3 == 0) {
        // 0x800ACCB0: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_800ACDAC;
    }
    // 0x800ACCB0: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800ACCB4: lw          $t0, 0x797C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X797C);
    // 0x800ACCB8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800ACCBC: lhu         $t9, 0x7948($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7948);
    // 0x800ACCC0: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800ACCC4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800ACCC8: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x800ACCCC: beql        $t2, $zero, L_800ACDB0
    if (ctx->r10 == 0) {
        // 0x800ACCD0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800ACDB0;
    }
    goto skip_0;
    // 0x800ACCD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800ACCD4: lbu         $t3, 0x46E0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X46E0);
    // 0x800ACCD8: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800ACCDC: bnel        $t3, $zero, L_800ACDB0
    if (ctx->r11 != 0) {
        // 0x800ACCE0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800ACDB0;
    }
    goto skip_1;
    // 0x800ACCE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800ACCE4: lw          $t4, 0x78E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78E8);
    // 0x800ACCE8: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x800ACCEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ACCF0: beq         $t4, $zero, L_800ACD00
    if (ctx->r12 == 0) {
        // 0x800ACCF4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800ACD00;
    }
    // 0x800ACCF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800ACCF8: b           L_800ACD04
    // 0x800ACCFC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800ACD04;
    // 0x800ACCFC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800ACD00:
    // 0x800ACD00: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800ACD04:
    // 0x800ACD04: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800ACD08: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800ACD0C: addiu       $a1, $a1, 0x46E0
    ctx->r5 = ADD32(ctx->r5, 0X46E0);
    // 0x800ACD10: bne         $v0, $zero, L_800ACD40
    if (ctx->r2 != 0) {
        // 0x800ACD14: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_800ACD40;
    }
    // 0x800ACD14: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800ACD18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ACD1C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800ACD20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ACD24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800ACD28: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800ACD2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800ACD30: jal         0x800AC290
    // 0x800ACD34: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_0;
    // 0x800ACD34: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800ACD38: b           L_800ACD7C
    // 0x800ACD3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_800ACD7C;
    // 0x800ACD3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_800ACD40:
    // 0x800ACD40: bne         $v0, $at, L_800ACD68
    if (ctx->r2 != ctx->r1) {
        // 0x800ACD44: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800ACD68;
    }
    // 0x800ACD44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ACD48: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800ACD4C: addiu       $a1, $a1, 0x46E0
    ctx->r5 = ADD32(ctx->r5, 0X46E0);
    // 0x800ACD50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800ACD54: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800ACD58: jal         0x800AC650
    // 0x800ACD5C: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    Player_SetupTankShot(rdram, ctx);
        goto after_1;
    // 0x800ACD5C: lui         $a3, 0x4334
    ctx->r7 = S32(0X4334 << 16);
    after_1:
    // 0x800ACD60: b           L_800ACD7C
    // 0x800ACD64: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_800ACD7C;
    // 0x800ACD64: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_800ACD68:
    // 0x800ACD68: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800ACD6C: addiu       $a1, $a1, 0x46E0
    ctx->r5 = ADD32(ctx->r5, 0X46E0);
    // 0x800ACD70: jal         0x800ACDC0
    // 0x800ACD74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    Player_SetupOnFootShot(rdram, ctx);
        goto after_2;
    // 0x800ACD74: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x800ACD78: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_800ACD7C:
    // 0x800ACD7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ACD80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ACD84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800ACD88: swc1        $f6, 0x4728($at)
    MEM_W(0X4728, ctx->r1) = ctx->f6.u32l;
    // 0x800ACD8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800ACD90: sw          $zero, 0x4740($at)
    MEM_W(0X4740, ctx->r1) = 0;
    // 0x800ACD94: jal         0x8001CB80
    // 0x800ACD98: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    Audio_InitBombSfx(rdram, ctx);
        goto after_3;
    // 0x800ACD98: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    after_3:
    // 0x800ACD9C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800ACDA0: addiu       $a1, $a1, 0x4718
    ctx->r5 = ADD32(ctx->r5, 0X4718);
    // 0x800ACDA4: jal         0x8001CCDC
    // 0x800ACDA8: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    Audio_PlayBombFlightSfx(rdram, ctx);
        goto after_4;
    // 0x800ACDA8: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    after_4:
L_800ACDAC:
    // 0x800ACDAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800ACDB0:
    // 0x800ACDB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800ACDB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800ACDB8: jr          $ra
    // 0x800ACDBC: nop

    return;
    // 0x800ACDBC: nop

;}
RECOMP_FUNC void AllRange_FortunaIntro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ED60: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002ED64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002ED68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002ED6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002ED70: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8002ED74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002ED78: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8002ED7C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8002ED80: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8002ED84: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002ED88: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x8002ED8C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8002ED90: jal         0x8009F6CC
    // 0x8002ED94: nop

    Math_Vec3fFromAngles(rdram, ctx);
        goto after_0;
    // 0x8002ED94: nop

    after_0:
    // 0x8002ED98: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002ED9C: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8002EDA0: lwc1        $f14, 0x7C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8002EDA4: lwc1        $f12, 0x78($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8002EDA8: swc1        $f18, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f18.u32l;
    // 0x8002EDAC: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002EDB0: lwc1        $f10, 0xC0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8002EDB4: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8002EDB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002EDBC: add.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8002EDC0: swc1        $f18, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f18.u32l;
    // 0x8002EDC4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002EDC8: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8002EDCC: swc1        $f10, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f10.u32l;
    // 0x8002EDD0: swc1        $f18, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f18.u32l;
    // 0x8002EDD4: add.s       $f16, $f14, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8002EDD8: lwc1        $f14, 0xC4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8002EDDC: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8002EDE0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8002EDE4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8002EDE8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002EDEC: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x8002EDF0: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8002EDF4: swc1        $f14, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f14.u32l;
    // 0x8002EDF8: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8002EDFC: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x8002EE00: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    // 0x8002EE04: swc1        $f12, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f12.u32l;
    // 0x8002EE08: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002EE0C: lwc1        $f12, 0x4E80($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X4E80);
    // 0x8002EE10: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x8002EE14: swc1        $f14, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f14.u32l;
    // 0x8002EE18: swc1        $f12, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f12.u32l;
    // 0x8002EE1C: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x8002EE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002EE24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002EE28: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002EE2C: jr          $ra
    // 0x8002EE30: nop

    return;
    // 0x8002EE30: nop

;}
RECOMP_FUNC void func_versus_800BD1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD1B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD1B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BD1B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD1BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BD1C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD1C4: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x800BD1C8: addiu       $a1, $a1, 0x3F10
    ctx->r5 = ADD32(ctx->r5, 0X3F10);
    // 0x800BD1CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD1D0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BD1D4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800BD1D8: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800BD1DC: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800BD1E0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800BD1E4: jal         0x8009D994
    // 0x800BD1E8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BD1E8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD1EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BD1F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BD1F4: jr          $ra
    // 0x800BD1F8: nop

    return;
    // 0x800BD1F8: nop

;}
RECOMP_FUNC void Audio_SetSfxProperties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016FF0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80016FF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80016FF8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80016FFC: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80017000: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80017004: sltiu       $at, $a3, 0x5
    ctx->r1 = ctx->r7 < 0X5 ? 1 : 0;
    // 0x80017008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001700C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80017010: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80017014: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80017018: sb          $zero, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = 0;
    // 0x8001701C: sb          $t6, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r14;
    // 0x80017020: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80017024: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80017028: beq         $at, $zero, L_80017254
    if (ctx->r1 == 0) {
        // 0x8001702C: swc1        $f0, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
            goto L_80017254;
    }
    // 0x8001702C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80017030: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80017034: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80017038: addu        $at, $at, $t7
    gpr jr_addend_80017040 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001703C: lw          $t7, -0x6FE8($at)
    ctx->r15 = ADD32(ctx->r1, -0X6FE8);
    // 0x80017040: jr          $t7
    // 0x80017044: nop

    switch (jr_addend_80017040 >> 2) {
        case 0: goto L_80017048; break;
        case 1: goto L_80017048; break;
        case 2: goto L_80017048; break;
        case 3: goto L_80017048; break;
        case 4: goto L_80017200; break;
        default: switch_error(__func__, 0x80017040, 0x800C9018);
    }
    // 0x80017044: nop

L_80017048:
    // 0x80017048: lbu         $t9, 0x47($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X47);
    // 0x8001704C: sll         $t8, $a3, 4
    ctx->r24 = S32(ctx->r7 << 4);
    // 0x80017050: subu        $t8, $t8, $a3
    ctx->r24 = SUB32(ctx->r24, ctx->r7);
    // 0x80017054: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80017058: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8001705C: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80017060: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x80017064: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80017068: addiu       $t2, $t2, -0x79A0
    ctx->r10 = ADD32(ctx->r10, -0X79A0);
    // 0x8001706C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x80017070: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80017074: lbu         $t3, 0x28($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X28);
    // 0x80017078: lbu         $t4, 0x4B($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X4B);
    // 0x8001707C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80017080: bne         $t3, $at, L_800170B0
    if (ctx->r11 != ctx->r1) {
        // 0x80017084: sll         $t5, $t4, 8
        ctx->r13 = S32(ctx->r12 << 8);
            goto L_800170B0;
    }
    // 0x80017084: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80017088: lui         $at, 0x602
    ctx->r1 = S32(0X602 << 16);
    // 0x8001708C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80017090: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80017094: lb          $a1, 0x7C98($a1)
    ctx->r5 = MEM_B(ctx->r5, 0X7C98);
    // 0x80017098: ori         $a0, $t6, 0x1
    ctx->r4 = ctx->r14 | 0X1;
    // 0x8001709C: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800170A0: jal         0x8001E8F0
    // 0x800170A4: sb          $a3, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r7;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_0;
    // 0x800170A4: sb          $a3, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r7;
    after_0:
    // 0x800170A8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x800170AC: lbu         $a3, 0x43($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X43);
L_800170B0:
    // 0x800170B0: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x800170B4: sll         $t8, $t9, 13
    ctx->r24 = S32(ctx->r25 << 13);
    // 0x800170B8: bgezl       $t8, L_80017110
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800170BC: lwc1        $f0, 0x1C($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_80017110;
    }
    goto skip_0;
    // 0x800170BC: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    skip_0:
    // 0x800170C0: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x800170C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800170C8: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800170CC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800170D0: nop

    // 0x800170D4: bc1fl       L_80017110
    if (!c1cs) {
        // 0x800170D8: lwc1        $f0, 0x1C($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_80017110;
    }
    goto skip_1;
    // 0x800170D8: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    skip_1:
    // 0x800170DC: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x800170E0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800170E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800170E8: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800170EC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800170F0: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800170F4: lwc1        $f2, 0x0($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800170F8: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800170FC: nop

    // 0x80017100: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80017104: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80017108: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x8001710C: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
L_80017110:
    // 0x80017110: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x80017114: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80017118: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
    // 0x8001711C: sb          $a3, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r7;
    // 0x80017120: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80017124: jal         0x80016A58
    // 0x80017128: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    Audio_GetSfxFalloff(rdram, ctx);
        goto after_1;
    // 0x80017128: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    after_1:
    // 0x8001712C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80017130: lbu         $a3, 0x43($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X43);
    // 0x80017134: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80017138: lw          $t4, 0x14($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X14);
    // 0x8001713C: sll         $t3, $a3, 4
    ctx->r11 = S32(ctx->r7 << 4);
    // 0x80017140: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80017144: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80017148: lwc1        $f6, -0x6578($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6578);
    // 0x8001714C: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    // 0x80017150: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80017154: lbu         $a2, 0x4B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X4B);
    // 0x80017158: andi        $a0, $a3, 0xFF
    ctx->r4 = ctx->r7 & 0XFF;
    // 0x8001715C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80017160: jal         0x80016BC0
    // 0x80017164: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    Audio_GetSfxReverb(rdram, ctx);
        goto after_2;
    // 0x80017164: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80017168: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001716C: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x80017170: jal         0x80016EE4
    // 0x80017174: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    Audio_GetSfxFreqMod(rdram, ctx);
        goto after_3;
    // 0x80017174: lbu         $a1, 0x47($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X47);
    after_3:
    // 0x80017178: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001717C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80017180: lw          $t5, 0x10($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X10);
    // 0x80017184: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80017188: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001718C: bne         $t6, $zero, L_800171E0
    if (ctx->r14 != 0) {
        // 0x80017190: swc1        $f4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
            goto L_800171E0;
    }
    // 0x80017190: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80017194: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x80017198: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8001719C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800171A0: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800171A4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800171A8: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800171AC: nop

    // 0x800171B0: bc1fl       L_800171E4
    if (!c1cs) {
        // 0x800171B4: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_800171E4;
    }
    goto skip_2;
    // 0x800171B4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_2:
    // 0x800171B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800171BC: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800171C0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800171C4: nop

    // 0x800171C8: bc1fl       L_800171E4
    if (!c1cs) {
        // 0x800171CC: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_800171E4;
    }
    goto skip_3;
    // 0x800171CC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800171D0: lbu         $t9, 0x5D20($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5D20);
    // 0x800171D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800171D8: bnel        $t9, $at, L_80017258
    if (ctx->r25 != ctx->r1) {
        // 0x800171DC: lbu         $t9, 0x4B($sp)
        ctx->r25 = MEM_BU(ctx->r29, 0X4B);
            goto L_80017258;
    }
    goto skip_4;
    // 0x800171DC: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
    skip_4:
L_800171E0:
    // 0x800171E0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_800171E4:
    // 0x800171E4: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x800171E8: lbu         $a2, 0xC($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0XC);
    // 0x800171EC: lwc1        $f12, 0x0($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800171F0: jal         0x80016CDC
    // 0x800171F4: lwc1        $f14, 0x0($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X0);
    Audio_GetSfxPan(rdram, ctx);
        goto after_4;
    // 0x800171F4: lwc1        $f14, 0x0($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x800171F8: b           L_80017254
    // 0x800171FC: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
        goto L_80017254;
    // 0x800171FC: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
L_80017200:
    // 0x80017200: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80017204: lbu         $t1, 0x5D20($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X5D20);
    // 0x80017208: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001720C: sll         $t2, $a3, 4
    ctx->r10 = S32(ctx->r7 << 4);
    // 0x80017210: bne         $t1, $at, L_80017254
    if (ctx->r9 != ctx->r1) {
        // 0x80017214: subu        $t2, $t2, $a3
        ctx->r10 = SUB32(ctx->r10, ctx->r7);
            goto L_80017254;
    }
    // 0x80017214: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x80017218: lbu         $t3, 0x47($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X47);
    // 0x8001721C: sll         $t2, $t2, 6
    ctx->r10 = S32(ctx->r10 << 6);
    // 0x80017220: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80017224: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80017228: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8001722C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80017230: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80017234: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80017238: lbu         $v0, -0x7994($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7994);
    // 0x8001723C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80017240: beq         $v0, $at, L_80017254
    if (ctx->r2 == ctx->r1) {
        // 0x80017244: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80017254;
    }
    // 0x80017244: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80017248: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x8001724C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80017250: sb          $t7, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r15;
L_80017254:
    // 0x80017254: lbu         $t9, 0x4B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X4B);
L_80017258:
    // 0x80017258: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001725C: addiu       $t0, $t0, -0x4870
    ctx->r8 = ADD32(ctx->r8, -0X4870);
    // 0x80017260: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80017264: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x80017268: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001726C: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80017270: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80017274: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80017278: andi        $a0, $t9, 0xFF
    ctx->r4 = ctx->r25 & 0XFF;
    // 0x8001727C: sll         $t1, $a0, 8
    ctx->r9 = S32(ctx->r4 << 8);
    // 0x80017280: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80017284: lui         $at, 0x102
    ctx->r1 = S32(0X102 << 16);
    // 0x80017288: or          $a0, $t1, $at
    ctx->r4 = ctx->r9 | ctx->r1;
    // 0x8001728C: bc1tl       L_800172B0
    if (c1cs) {
        // 0x80017290: lb          $t2, 0x3B($sp)
        ctx->r10 = MEM_B(ctx->r29, 0X3B);
            goto L_800172B0;
    }
    goto skip_5;
    // 0x80017290: lb          $t2, 0x3B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3B);
    skip_5:
    // 0x80017294: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80017298: jal         0x8001E8A8
    // 0x8001729C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    AudioThread_QueueCmdF32(rdram, ctx);
        goto after_5;
    // 0x8001729C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_5:
    // 0x800172A0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800172A4: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800172A8: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x800172AC: lb          $t2, 0x3B($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3B);
L_800172B0:
    // 0x800172B0: lb          $t4, 0x8($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X8);
    // 0x800172B4: lbu         $t5, 0x4B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4B);
    // 0x800172B8: lui         $at, 0x502
    ctx->r1 = S32(0X502 << 16);
    // 0x800172BC: beq         $t2, $t4, L_800172E0
    if (ctx->r10 == ctx->r12) {
        // 0x800172C0: sll         $t6, $t5, 8
        ctx->r14 = S32(ctx->r13 << 8);
            goto L_800172E0;
    }
    // 0x800172C0: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800172C4: or          $a0, $t6, $at
    ctx->r4 = ctx->r14 | ctx->r1;
    // 0x800172C8: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800172CC: jal         0x8001E8F0
    // 0x800172D0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_6;
    // 0x800172D0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_6:
    // 0x800172D4: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800172D8: lb          $t8, 0x3B($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X3B);
    // 0x800172DC: sb          $t8, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r24;
L_800172E0:
    // 0x800172E0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800172E4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800172E8: lbu         $t0, 0x4B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X4B);
    // 0x800172EC: lui         $at, 0x402
    ctx->r1 = S32(0X402 << 16);
    // 0x800172F0: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800172F4: sll         $t9, $t0, 8
    ctx->r25 = S32(ctx->r8 << 8);
    // 0x800172F8: or          $a0, $t9, $at
    ctx->r4 = ctx->r25 | ctx->r1;
    // 0x800172FC: bc1tl       L_80017320
    if (c1cs) {
        // 0x80017300: lb          $t3, 0x33($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X33);
            goto L_80017320;
    }
    goto skip_6;
    // 0x80017300: lb          $t3, 0x33($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X33);
    skip_6:
    // 0x80017304: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80017308: jal         0x8001E8A8
    // 0x8001730C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    AudioThread_QueueCmdF32(rdram, ctx);
        goto after_7;
    // 0x8001730C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_7:
    // 0x80017310: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80017314: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80017318: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8001731C: lb          $t3, 0x33($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X33);
L_80017320:
    // 0x80017320: lb          $t4, 0x9($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X9);
    // 0x80017324: lbu         $t5, 0x4B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X4B);
    // 0x80017328: lui         $at, 0x302
    ctx->r1 = S32(0X302 << 16);
    // 0x8001732C: beq         $t3, $t4, L_80017350
    if (ctx->r11 == ctx->r12) {
        // 0x80017330: sll         $t6, $t5, 8
        ctx->r14 = S32(ctx->r13 << 8);
            goto L_80017350;
    }
    // 0x80017330: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80017334: or          $a0, $t6, $at
    ctx->r4 = ctx->r14 | ctx->r1;
    // 0x80017338: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x8001733C: jal         0x8001E8F0
    // 0x80017340: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_8;
    // 0x80017340: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_8:
    // 0x80017344: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80017348: lb          $t2, 0x33($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X33);
    // 0x8001734C: sb          $t2, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r10;
L_80017350:
    // 0x80017350: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017354: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80017358: jr          $ra
    // 0x8001735C: nop

    return;
    // 0x8001735C: nop

;}
RECOMP_FUNC void AudioLoad_DiscardFont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F158: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000F15C: addiu       $v0, $v0, -0x3BF0
    ctx->r2 = ADD32(ctx->r2, -0X3BF0);
    // 0x8000F160: lh          $t6, 0x1B2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X1B2);
    // 0x8000F164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F16C: bne         $a0, $t6, L_8000F184
    if (ctx->r4 != ctx->r14) {
        // 0x8000F170: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8000F184;
    }
    // 0x8000F170: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000F174: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000F178: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000F17C: b           L_8000F1A0
    // 0x8000F180: sh          $t7, -0x3A3E($at)
    MEM_H(-0X3A3E, ctx->r1) = ctx->r15;
        goto L_8000F1A0;
    // 0x8000F180: sh          $t7, -0x3A3E($at)
    MEM_H(-0X3A3E, ctx->r1) = ctx->r15;
L_8000F184:
    // 0x8000F184: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000F188: lh          $t8, -0x3A32($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X3A32);
    // 0x8000F18C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000F190: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000F194: bne         $a2, $t8, L_8000F1A0
    if (ctx->r6 != ctx->r24) {
        // 0x8000F198: nop
    
            goto L_8000F1A0;
    }
    // 0x8000F198: nop

    // 0x8000F19C: sh          $t9, -0x3A32($at)
    MEM_H(-0X3A32, ctx->r1) = ctx->r25;
L_8000F1A0:
    // 0x8000F1A0: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8000F1A4: lw          $t0, -0x3BF0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3BF0);
    // 0x8000F1A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000F1AC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000F1B0: beq         $t0, $zero, L_8000F1E8
    if (ctx->r8 == 0) {
        // 0x8000F1B4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000F1E8;
    }
    // 0x8000F1B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000F1B8: addiu       $v0, $v0, -0x3BF0
    ctx->r2 = ADD32(ctx->r2, -0X3BF0);
    // 0x8000F1BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000F1C0: lh          $t1, 0x1E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1E);
L_8000F1C4:
    // 0x8000F1C4: bnel        $a2, $t1, L_8000F1D4
    if (ctx->r6 != ctx->r9) {
        // 0x8000F1C8: lw          $t2, 0x0($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X0);
            goto L_8000F1D4;
    }
    goto skip_0;
    // 0x8000F1C8: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8000F1CC: sh          $a1, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r5;
    // 0x8000F1D0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
L_8000F1D4:
    // 0x8000F1D4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000F1D8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8000F1DC: sltu        $at, $v1, $t2
    ctx->r1 = ctx->r3 < ctx->r10 ? 1 : 0;
    // 0x8000F1E0: bnel        $at, $zero, L_8000F1C4
    if (ctx->r1 != 0) {
        // 0x8000F1E4: lh          $t1, 0x1E($v0)
        ctx->r9 = MEM_H(ctx->r2, 0X1E);
            goto L_8000F1C4;
    }
    goto skip_1;
    // 0x8000F1E4: lh          $t1, 0x1E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X1E);
    skip_1:
L_8000F1E8:
    // 0x8000F1E8: jal         0x8000BD38
    // 0x8000F1EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    AudioHeap_DiscardFont(rdram, ctx);
        goto after_0;
    // 0x8000F1EC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8000F1F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F1F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F1F8: jr          $ra
    // 0x8000F1FC: nop

    return;
    // 0x8000F1FC: nop

;}
RECOMP_FUNC void AudioLoad_SyncDmaUnkMedium(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FB50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000FB54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000FB58: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x8000FB5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FB60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000FB64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000FB68: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000FB6C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8000FB70: jal         0x80021740
    // 0x8000FB74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x8000FB74: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8000FB78: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FB7C: jal         0x8000FC7C
    // 0x8000FB80: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8000FC7C(rdram, ctx);
        goto after_1;
    // 0x8000FB80: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x8000FB84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000FB88: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FB8C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8000FB90: jal         0x8000FC8C
    // 0x8000FB94: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8000FC8C(rdram, ctx);
        goto after_2;
    // 0x8000FB94: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8000FB98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FB9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000FBA0: jr          $ra
    // 0x8000FBA4: nop

    return;
    // 0x8000FBA4: nop

;}
RECOMP_FUNC void Rand_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004E4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004E54: jal         0x80023000
    // 0x80004E58: nop

    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x80004E58: nop

    after_0:
    // 0x80004E5C: addiu       $at, $zero, 0x7530
    ctx->r1 = ADD32(0, 0X7530);
    // 0x80004E60: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80004E64: mfhi        $t7
    ctx->r15 = hi;
    // 0x80004E68: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80004E6C: jal         0x80023000
    // 0x80004E70: sw          $t7, -0x4C5C($at)
    MEM_W(-0X4C5C, ctx->r1) = ctx->r15;
    osGetTime_recomp(rdram, ctx);
        goto after_1;
    // 0x80004E70: sw          $t7, -0x4C5C($at)
    MEM_W(-0X4C5C, ctx->r1) = ctx->r15;
    after_1:
    // 0x80004E74: addiu       $at, $zero, 0x7530
    ctx->r1 = ADD32(0, 0X7530);
    // 0x80004E78: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80004E7C: mfhi        $t9
    ctx->r25 = hi;
    // 0x80004E80: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80004E84: jal         0x80023000
    // 0x80004E88: sw          $t9, -0x4C58($at)
    MEM_W(-0X4C58, ctx->r1) = ctx->r25;
    osGetTime_recomp(rdram, ctx);
        goto after_2;
    // 0x80004E88: sw          $t9, -0x4C58($at)
    MEM_W(-0X4C58, ctx->r1) = ctx->r25;
    after_2:
    // 0x80004E8C: addiu       $at, $zero, 0x7530
    ctx->r1 = ADD32(0, 0X7530);
    // 0x80004E90: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80004E94: mfhi        $t1
    ctx->r9 = hi;
    // 0x80004E98: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80004E9C: sw          $t1, -0x4C54($at)
    MEM_W(-0X4C54, ctx->r1) = ctx->r9;
    // 0x80004EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004EA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80004EA8: jr          $ra
    // 0x80004EAC: nop

    return;
    // 0x80004EAC: nop

;}
RECOMP_FUNC void Display_DrawHelpAlert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80051B30: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80051B34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80051B38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80051B3C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80051B40: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x80051B44: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80051B48: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x80051B4C: beq         $t6, $at, L_800520E8
    if (ctx->r14 == ctx->r1) {
        // 0x80051B50: addiu       $a3, $a3, -0x5DCC
        ctx->r7 = ADD32(ctx->r7, -0X5DCC);
            goto L_800520E8;
    }
    // 0x80051B50: addiu       $a3, $a3, -0x5DCC
    ctx->r7 = ADD32(ctx->r7, -0X5DCC);
    // 0x80051B54: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80051B58: beql        $v0, $zero, L_800520EC
    if (ctx->r2 == 0) {
        // 0x80051B5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800520EC;
    }
    goto skip_0;
    // 0x80051B5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80051B60: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80051B64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051B68: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80051B6C: bne         $t7, $at, L_80051B84
    if (ctx->r15 != ctx->r1) {
        // 0x80051B70: lui         $a0, 0x800D
        ctx->r4 = S32(0X800D << 16);
            goto L_80051B84;
    }
    // 0x80051B70: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80051B74: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x80051B78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80051B7C: lw          $t8, 0x1C8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C8);
    // 0x80051B80: beq         $t8, $at, L_80051B94
    if (ctx->r24 == ctx->r1) {
        // 0x80051B84: addiu       $a0, $a0, -0x5DC8
        ctx->r4 = ADD32(ctx->r4, -0X5DC8);
            goto L_80051B94;
    }
L_80051B84:
    // 0x80051B84: addiu       $a0, $a0, -0x5DC8
    ctx->r4 = ADD32(ctx->r4, -0X5DC8);
    // 0x80051B88: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80051B8C: b           L_800520E8
    // 0x80051B90: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_800520E8;
    // 0x80051B90: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80051B94:
    // 0x80051B94: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80051B98: addiu       $a0, $a0, -0x5DC8
    ctx->r4 = ADD32(ctx->r4, -0X5DC8);
    // 0x80051B9C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80051BA0: beq         $v0, $zero, L_80051BBC
    if (ctx->r2 == 0) {
        // 0x80051BA4: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80051BBC;
    }
    // 0x80051BA4: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80051BA8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80051BAC: bne         $t9, $zero, L_80051BBC
    if (ctx->r25 != 0) {
        // 0x80051BB0: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80051BBC;
    }
    // 0x80051BB0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80051BB4: b           L_800520E8
    // 0x80051BB8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_800520E8;
    // 0x80051BB8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80051BBC:
    // 0x80051BBC: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x80051BC0: bne         $t0, $zero, L_800520E8
    if (ctx->r8 != 0) {
        // 0x80051BC4: lui         $s0, 0x8014
        ctx->r16 = S32(0X8014 << 16);
            goto L_800520E8;
    }
    // 0x80051BC4: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80051BC8: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80051BCC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80051BD0: lw          $a1, 0x58($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X58);
    // 0x80051BD4: jal         0x80005E90
    // 0x80051BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80051BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80051BDC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80051BE0: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80051BE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80051BE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80051BEC: jal         0x80005D44
    // 0x80051BF0: lw          $a1, 0x5C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X5C);
    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80051BF0: lw          $a1, 0x5C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X5C);
    after_1:
    // 0x80051BF4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80051BF8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80051BFC: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x80051C00: lw          $v0, -0x5DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5DCC);
    // 0x80051C04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80051C08: lwc1        $f6, 0x40($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80051C0C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80051C10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80051C14: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80051C18: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80051C1C: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80051C20: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80051C24: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x80051C28: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80051C2C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80051C30: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80051C34: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x80051C38: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80051C3C: lwc1        $f10, 0x48($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X48);
    // 0x80051C40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80051C44: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80051C48: jal         0x80006970
    // 0x80051C4C: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x80051C4C: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80051C50: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80051C54: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80051C58: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80051C5C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80051C60: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80051C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80051C68: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051C6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051C70: bc1f        L_80051CB8
    if (!c1cs) {
        // 0x80051C74: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_80051CB8;
    }
    // 0x80051C74: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80051C78: lwc1        $f4, 0x5DC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5DC0);
    // 0x80051C7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051C80: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80051C84: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x80051C88: nop

    // 0x80051C8C: bc1f        L_80051CB8
    if (!c1cs) {
        // 0x80051C90: nop
    
            goto L_80051CB8;
    }
    // 0x80051C90: nop

    // 0x80051C94: lwc1        $f6, 0x5DC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5DC4);
    // 0x80051C98: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80051C9C: mul.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80051CA0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80051CA4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80051CA8: nop

    // 0x80051CAC: bc1f        L_80051CB8
    if (!c1cs) {
        // 0x80051CB0: nop
    
            goto L_80051CB8;
    }
    // 0x80051CB0: nop

    // 0x80051CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80051CB8:
    // 0x80051CB8: jal         0x800B8DD0
    // 0x80051CBC: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80051CBC: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80051CC0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80051CC4: lw          $t2, -0x5DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5DCC);
    // 0x80051CC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80051CCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80051CD0: lh          $v0, 0xE4($t2)
    ctx->r2 = MEM_H(ctx->r10, 0XE4);
    // 0x80051CD4: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80051CD8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x80051CDC: beq         $v0, $a1, L_80051D40
    if (ctx->r2 == ctx->r5) {
        // 0x80051CE0: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80051D40;
    }
    // 0x80051CE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051CE4: beq         $v0, $at, L_80051D1C
    if (ctx->r2 == ctx->r1) {
        // 0x80051CE8: lui         $t7, 0xFA00
        ctx->r15 = S32(0XFA00 << 16);
            goto L_80051D1C;
    }
    // 0x80051CE8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80051CEC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80051CF0: bne         $v0, $at, L_80051D5C
    if (ctx->r2 != ctx->r1) {
        // 0x80051CF4: lui         $t4, 0xFA00
        ctx->r12 = S32(0XFA00 << 16);
            goto L_80051D5C;
    }
    // 0x80051CF4: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80051CF8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80051CFC: lui         $t5, 0xFF1E
    ctx->r13 = S32(0XFF1E << 16);
    // 0x80051D00: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x80051D04: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80051D08: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80051D0C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80051D10: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80051D14: b           L_80051D60
    // 0x80051D18: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_80051D60;
    // 0x80051D18: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80051D1C:
    // 0x80051D1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80051D20: lui         $t8, 0xB3
    ctx->r24 = S32(0XB3 << 16);
    // 0x80051D24: ori         $t8, $t8, 0x43FF
    ctx->r24 = ctx->r24 | 0X43FF;
    // 0x80051D28: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80051D2C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80051D30: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80051D34: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80051D38: b           L_80051D60
    // 0x80051D3C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_80051D60;
    // 0x80051D3C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80051D40:
    // 0x80051D40: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80051D44: lui         $t1, 0x1E1E
    ctx->r9 = S32(0X1E1E << 16);
    // 0x80051D48: ori         $t1, $t1, 0xFFFF
    ctx->r9 = ctx->r9 | 0XFFFF;
    // 0x80051D4C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80051D50: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80051D54: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80051D58: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_80051D5C:
    // 0x80051D5C: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80051D60:
    // 0x80051D60: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x80051D64: beq         $v0, $zero, L_80051D7C
    if (ctx->r2 == 0) {
        // 0x80051D68: nop
    
            goto L_80051D7C;
    }
    // 0x80051D68: nop

    // 0x80051D6C: beq         $v0, $a1, L_80051E6C
    if (ctx->r2 == ctx->r5) {
        // 0x80051D70: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80051E6C;
    }
    // 0x80051D70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051D74: b           L_80051FBC
    // 0x80051D78: nop

        goto L_80051FBC;
    // 0x80051D78: nop

L_80051D7C:
    // 0x80051D7C: lw          $t2, -0x5DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5DCC);
    // 0x80051D80: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80051D84: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80051D88: lwc1        $f10, 0x100($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X100);
    // 0x80051D8C: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80051D90: nop

    // 0x80051D94: bc1fl       L_80051DB8
    if (!c1cs) {
        // 0x80051D98: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80051DB8;
    }
    goto skip_1;
    // 0x80051D98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x80051D9C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80051DA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80051DA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051DA8: lwc1        $f0, 0x5DC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5DC8);
    // 0x80051DAC: b           L_80051DC4
    // 0x80051DB0: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
        goto L_80051DC4;
    // 0x80051DB0: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    // 0x80051DB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80051DB8:
    // 0x80051DB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051DBC: lwc1        $f0, 0x5DCC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5DCC);
    // 0x80051DC0: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
L_80051DC4:
    // 0x80051DC4: jal         0x80005708
    // 0x80051DC8: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x80051DC8: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80051DCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051DD0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80051DD4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80051DD8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80051DDC: lw          $a1, 0x78($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X78);
    // 0x80051DE0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80051DE4: jal         0x80005B00
    // 0x80051DE8: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x80051DE8: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    after_5:
    // 0x80051DEC: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80051DF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051DF4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80051DF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80051DFC: jal         0x80005FE0
    // 0x80051E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80051E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80051E04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051E08: lwc1        $f0, 0x5DD0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5DD0);
    // 0x80051E0C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051E10: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80051E14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80051E18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80051E1C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80051E20: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80051E24: jal         0x80005C34
    // 0x80051E28: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x80051E28: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_7:
    // 0x80051E2C: jal         0x80006EB8
    // 0x80051E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x80051E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80051E34: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80051E38: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x80051E3C: addiu       $t7, $t7, 0x3700
    ctx->r15 = ADD32(ctx->r15, 0X3700);
    // 0x80051E40: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80051E44: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80051E48: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80051E4C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80051E50: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80051E54: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051E58: jal         0x80005740
    // 0x80051E5C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x80051E5C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_9:
    // 0x80051E60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80051E64: b           L_80051FBC
    // 0x80051E68: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
        goto L_80051FBC;
    // 0x80051E68: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80051E6C:
    // 0x80051E6C: jal         0x80005708
    // 0x80051E70: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_10;
    // 0x80051E70: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_10:
    // 0x80051E74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051E78: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80051E7C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80051E80: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80051E84: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80051E88: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80051E8C: jal         0x80005B00
    // 0x80051E90: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x80051E90: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    after_11:
    // 0x80051E94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051E98: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x80051E9C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80051EA0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80051EA4: jal         0x80005FE0
    // 0x80051EA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_12;
    // 0x80051EA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x80051EAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051EB0: lwc1        $f0, 0x5DD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5DD4);
    // 0x80051EB4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051EB8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80051EBC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80051EC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80051EC4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80051EC8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80051ECC: jal         0x80005C34
    // 0x80051ED0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x80051ED0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_13:
    // 0x80051ED4: jal         0x80006EB8
    // 0x80051ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x80051ED8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80051EDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80051EE0: lui         $a1, 0x102
    ctx->r5 = S32(0X102 << 16);
    // 0x80051EE4: addiu       $a1, $a1, 0x3700
    ctx->r5 = ADD32(ctx->r5, 0X3700);
    // 0x80051EE8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80051EEC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80051EF0: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80051EF4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80051EF8: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80051EFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051F00: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x80051F04: jal         0x80005740
    // 0x80051F08: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x80051F08: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_15:
    // 0x80051F0C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80051F10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80051F14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051F18: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x80051F1C: jal         0x80005708
    // 0x80051F20: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    Matrix_Push(rdram, ctx);
        goto after_16;
    // 0x80051F20: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x80051F24: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051F28: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80051F2C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80051F30: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80051F34: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x80051F38: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80051F3C: jal         0x80005B00
    // 0x80051F40: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_17;
    // 0x80051F40: lui         $a3, 0xC248
    ctx->r7 = S32(0XC248 << 16);
    after_17:
    // 0x80051F44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051F48: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x80051F4C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80051F50: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80051F54: jal         0x80005FE0
    // 0x80051F58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_18;
    // 0x80051F58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x80051F5C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80051F60: lwc1        $f0, 0x5DD8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5DD8);
    // 0x80051F64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051F68: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80051F6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80051F70: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80051F74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80051F78: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80051F7C: jal         0x80005C34
    // 0x80051F80: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_19;
    // 0x80051F80: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_19:
    // 0x80051F84: jal         0x80006EB8
    // 0x80051F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_20;
    // 0x80051F88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x80051F8C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80051F90: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80051F94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80051F98: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80051F9C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80051FA0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80051FA4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80051FA8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80051FAC: jal         0x80005740
    // 0x80051FB0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_21;
    // 0x80051FB0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_21:
    // 0x80051FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80051FB8: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
L_80051FBC:
    // 0x80051FBC: beq         $v0, $zero, L_80051FD4
    if (ctx->r2 == 0) {
        // 0x80051FC0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80051FD4;
    }
    // 0x80051FC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051FC4: beq         $v0, $a1, L_80052070
    if (ctx->r2 == ctx->r5) {
        // 0x80051FC8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80052070;
    }
    // 0x80051FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80051FCC: b           L_800520EC
    // 0x80051FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800520EC;
    // 0x80051FD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80051FD4:
    // 0x80051FD4: jal         0x800B8DD0
    // 0x80051FD8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_22;
    // 0x80051FD8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_22:
    // 0x80051FDC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80051FE0: lui         $t9, 0xFFFF
    ctx->r25 = S32(0XFFFF << 16);
    // 0x80051FE4: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x80051FE8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80051FEC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80051FF0: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80051FF4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80051FF8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80051FFC: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80052000: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80052004: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80052008: addiu       $t0, $t0, 0x5DA0
    ctx->r8 = ADD32(ctx->r8, 0X5DA0);
    // 0x8005200C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80052010: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80052014: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x80052018: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x8005201C: bc1fl       L_80052050
    if (!c1cs) {
        // 0x80052020: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80052050;
    }
    goto skip_2;
    // 0x80052020: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x80052024: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80052028: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005202C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80052030: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    // 0x80052034: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80052038: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005203C: jal         0x800A1200
    // 0x80052040: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_23;
    // 0x80052040: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_23:
    // 0x80052044: b           L_800520EC
    // 0x80052048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800520EC;
    // 0x80052048: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005204C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80052050:
    // 0x80052050: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x80052054: addiu       $t1, $t1, 0x5DA8
    ctx->r9 = ADD32(ctx->r9, 0X5DA8);
    // 0x80052058: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005205C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80052060: jal         0x800A1200
    // 0x80052064: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_24;
    // 0x80052064: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_24:
    // 0x80052068: b           L_800520EC
    // 0x8005206C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800520EC;
    // 0x8005206C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80052070:
    // 0x80052070: jal         0x800B8DD0
    // 0x80052074: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_25;
    // 0x80052074: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_25:
    // 0x80052078: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005207C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80052080: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80052084: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052088: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x8005208C: ori         $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 | 0XFF;
    // 0x80052090: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80052094: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80052098: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005209C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800520A0: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x800520A4: addiu       $t5, $t5, 0x5DB0
    ctx->r13 = ADD32(ctx->r13, 0X5DB0);
    // 0x800520A8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800520AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800520B0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800520B4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800520B8: jal         0x800A1200
    // 0x800520BC: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_26;
    // 0x800520BC: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_26:
    // 0x800520C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800520C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800520C8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800520CC: addiu       $t6, $t6, 0x5DB8
    ctx->r14 = ADD32(ctx->r14, 0X5DB8);
    // 0x800520D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800520D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800520D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800520DC: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    // 0x800520E0: jal         0x800A1200
    // 0x800520E4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_27;
    // 0x800520E4: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_27:
L_800520E8:
    // 0x800520E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800520EC:
    // 0x800520EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800520F0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x800520F4: jr          $ra
    // 0x800520F8: nop

    return;
    // 0x800520F8: nop

;}
RECOMP_FUNC void Effect_Effect375_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DAE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007DAE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007DAEC: jal         0x8005980C
    // 0x8007DAF0: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007DAF0: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x8007DAF4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007DAF8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007DAFC: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x8007DB00: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x8007DB04: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DB08: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DB0C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8007DB10: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8007DB14: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8007DB18: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8007DB1C: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8007DB20: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8007DB24: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8007DB28: jal         0x800BA1D0
    // 0x8007DB2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_29(rdram, ctx);
        goto after_1;
    // 0x8007DB2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x8007DB30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007DB34: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8007DB38: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007DB3C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8007DB40: addiu       $t0, $t0, 0x4900
    ctx->r8 = ADD32(ctx->r8, 0X4900);
    // 0x8007DB44: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8007DB48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007DB4C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8007DB50: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007DB54: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8007DB58: jal         0x800B8DD0
    // 0x8007DB5C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8007DB5C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x8007DB60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007DB64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007DB68: jr          $ra
    // 0x8007DB6C: nop

    return;
    // 0x8007DB6C: nop

;}
RECOMP_FUNC void Audio_ResetActiveSequencesAndVolume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800190E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800190E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800190EC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x800190F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800190F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800190F8: addiu       $a1, $a1, -0x5258
    ctx->r5 = ADD32(ctx->r5, -0X5258);
    // 0x800190FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80019100: addiu       $a2, $zero, 0x258
    ctx->r6 = ADD32(0, 0X258);
    // 0x80019104: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
L_80019108:
    // 0x80019108: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001910C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80019110: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x80019114: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80019118: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8001911C: mflo        $t6
    ctx->r14 = lo;
    // 0x80019120: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x80019124: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80019128: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x8001912C: sb          $zero, 0x12($v0)
    MEM_B(0X12, ctx->r2) = 0;
    // 0x80019130: sb          $v1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r3;
    // 0x80019134: sb          $v1, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r3;
    // 0x80019138: bne         $at, $zero, L_80019108
    if (ctx->r1 != 0) {
        // 0x8001913C: sb          $v1, 0x10($v0)
        MEM_B(0X10, ctx->r2) = ctx->r3;
            goto L_80019108;
    }
    // 0x8001913C: sb          $v1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r3;
    // 0x80019140: jal         0x80019068
    // 0x80019144: nop

    Audio_ResetActiveSequences(rdram, ctx);
        goto after_0;
    // 0x80019144: nop

    after_0:
    // 0x80019148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001914C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80019150: jr          $ra
    // 0x80019154: nop

    return;
    // 0x80019154: nop

;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AFB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002AFB4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002AFB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002AFBC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8002AFC0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002AFC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002AFC8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8002AFCC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8002AFD0: jal         0x80023D9C
    // 0x8002AFD4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x8002AFD4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x8002AFD8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8002AFDC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8002AFE0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8002AFE4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002AFE8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002AFEC: jal         0x80023DF8
    // 0x8002AFF0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x8002AFF0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x8002AFF4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8002AFF8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8002AFFC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002B000: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x8002B004: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x8002B008: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x8002B00C: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x8002B010: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8002B014: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8002B018: bgtz        $t0, L_8002B078
    if (SIGNED(ctx->r8) > 0) {
        // 0x8002B01C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_8002B078;
    }
    // 0x8002B01C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8002B020: bltz        $t0, L_8002B030
    if (SIGNED(ctx->r8) < 0) {
        // 0x8002B024: nop
    
            goto L_8002B030;
    }
    // 0x8002B024: nop

    // 0x8002B028: b           L_8002B07C
    // 0x8002B02C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_8002B07C;
    // 0x8002B02C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_8002B030:
    // 0x8002B030: bltzl       $t8, L_8002B07C
    if (SIGNED(ctx->r24) < 0) {
        // 0x8002B034: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_8002B07C;
    }
    goto skip_0;
    // 0x8002B034: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x8002B038: bgtz        $t8, L_8002B048
    if (SIGNED(ctx->r24) > 0) {
        // 0x8002B03C: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_8002B048;
    }
    // 0x8002B03C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x8002B040: beql        $t9, $zero, L_8002B07C
    if (ctx->r25 == 0) {
        // 0x8002B044: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_8002B07C;
    }
    goto skip_1;
    // 0x8002B044: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_8002B048:
    // 0x8002B048: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002B04C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002B050: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x8002B054: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x8002B058: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x8002B05C: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x8002B060: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x8002B064: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x8002B068: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8002B06C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8002B070: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8002B074: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_8002B078:
    // 0x8002B078: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_8002B07C:
    // 0x8002B07C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8002B080: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8002B084: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x8002B088: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x8002B08C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8002B090: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x8002B094: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x8002B098: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x8002B09C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x8002B0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002B0A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002B0A8: jr          $ra
    // 0x8002B0AC: nop

    return;
    // 0x8002B0AC: nop

;}
RECOMP_FUNC void Cutscene_EnterWarpZone(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80049C0C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80049C10: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80049C14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80049C18: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80049C1C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80049C20: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80049C24: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80049C28: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80049C2C: lwc1        $f16, 0xC4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80049C30: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80049C34: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80049C38: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80049C3C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80049C40: swc1        $f8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f8.u32l;
    // 0x80049C44: sw          $zero, 0x228($s0)
    MEM_W(0X228, ctx->r16) = 0;
    // 0x80049C48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80049C4C: sw          $zero, 0x238($s0)
    MEM_W(0X238, ctx->r16) = 0;
    // 0x80049C50: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80049C54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80049C58: jal         0x8004990C
    // 0x80049C5C: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    Cutscene_PathTexScroll(rdram, ctx);
        goto after_0;
    // 0x80049C5C: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    after_0:
    // 0x80049C60: lwc1        $f0, 0xC8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80049C64: lwc1        $f10, 0x144($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80049C68: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80049C6C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80049C70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80049C74: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80049C78: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
    // 0x80049C7C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049C80: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049C84: swc1        $f16, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f16.u32l;
    // 0x80049C88: lwc1        $f18, 0x144($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80049C8C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049C90: addiu       $a0, $s0, 0x130
    ctx->r4 = ADD32(ctx->r16, 0X130);
    // 0x80049C94: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80049C98: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80049C9C: jal         0x8009BC2C
    // 0x80049CA0: swc1        $f18, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80049CA0: swc1        $f18, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f18.u32l;
    after_1:
    // 0x80049CA4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049CA8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049CAC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049CB0: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x80049CB4: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80049CB8: jal         0x8009BC2C
    // 0x80049CBC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80049CBC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x80049CC0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049CC4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049CC8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049CCC: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x80049CD0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80049CD4: jal         0x8009BC2C
    // 0x80049CD8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80049CD8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80049CDC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049CE0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049CE4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049CE8: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x80049CEC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80049CF0: jal         0x8009BC2C
    // 0x80049CF4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80049CF4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x80049CF8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049CFC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049D00: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049D04: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x80049D08: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80049D0C: jal         0x8009BC2C
    // 0x80049D10: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80049D10: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x80049D14: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049D18: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049D1C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049D20: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x80049D24: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80049D28: jal         0x8009BC2C
    // 0x80049D2C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80049D2C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80049D30: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049D34: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049D38: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049D3C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80049D40: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80049D44: jal         0x8009BC2C
    // 0x80049D48: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80049D48: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x80049D4C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049D50: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049D54: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049D58: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x80049D5C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80049D60: jal         0x8009BC2C
    // 0x80049D64: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80049D64: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80049D68: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80049D6C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049D70: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049D74: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049D78: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80049D7C: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80049D80: jal         0x8009BC2C
    // 0x80049D84: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80049D84: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_9:
    // 0x80049D88: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049D8C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049D90: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049D94: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x80049D98: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80049D9C: jal         0x8009BC2C
    // 0x80049DA0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80049DA0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x80049DA4: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x80049DA8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049DAC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049DB0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049DB4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x80049DB8: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x80049DBC: jal         0x8009BC2C
    // 0x80049DC0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80049DC0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_11:
    // 0x80049DC4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049DC8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049DCC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049DD0: addiu       $a0, $s0, 0x4D8
    ctx->r4 = ADD32(ctx->r16, 0X4D8);
    // 0x80049DD4: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80049DD8: jal         0x8009BD38
    // 0x80049DDC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_12;
    // 0x80049DDC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x80049DE0: lw          $t6, 0x1D0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1D0);
    // 0x80049DE4: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x80049DE8: beq         $at, $zero, L_8004A518
    if (ctx->r1 == 0) {
        // 0x80049DEC: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8004A518;
    }
    // 0x80049DEC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80049DF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049DF4: addu        $at, $at, $t6
    gpr jr_addend_80049DFC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80049DF8: lw          $t6, 0x5898($at)
    ctx->r14 = ADD32(ctx->r1, 0X5898);
    // 0x80049DFC: jr          $t6
    // 0x80049E00: nop

    switch (jr_addend_80049DFC >> 2) {
        case 0: goto L_80049E04; break;
        case 1: goto L_80049EC4; break;
        case 2: goto L_80049F68; break;
        case 3: goto L_8004A518; break;
        case 4: goto L_8004A1C8; break;
        case 5: goto L_8004A358; break;
        case 6: goto L_8004A3BC; break;
        default: switch_error(__func__, 0x80049DFC, 0x800D5898);
    }
    // 0x80049E00: nop

L_80049E04:
    // 0x80049E04: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x80049E08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80049E0C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80049E10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80049E14: sw          $zero, 0x4DC($s0)
    MEM_W(0X4DC, ctx->r16) = 0;
    // 0x80049E18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049E1C: swc1        $f4, -0x7BEC($at)
    MEM_W(-0X7BEC, ctx->r1) = ctx->f4.u32l;
    // 0x80049E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80049E24: sw          $v0, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r2;
    // 0x80049E28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049E2C: sw          $v0, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r2;
    // 0x80049E30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049E34: sw          $zero, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = 0;
    // 0x80049E38: swc1        $f20, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f20.u32l;
    // 0x80049E3C: swc1        $f20, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f20.u32l;
    // 0x80049E40: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80049E44: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x80049E48: swc1        $f0, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f0.u32l;
    // 0x80049E4C: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x80049E50: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80049E54: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x80049E58: blez        $t7, L_80049E68
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80049E5C: nop
    
            goto L_80049E68;
    }
    // 0x80049E5C: nop

    // 0x80049E60: jal         0x80049968
    // 0x80049E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Cutscene_WarpZoneStart_TeamSetup(rdram, ctx);
        goto after_13;
    // 0x80049E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_80049E68:
    // 0x80049E68: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80049E6C: lw          $t8, 0x78B8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78B8);
    // 0x80049E70: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80049E74: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x80049E78: blez        $t8, L_80049E88
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80049E7C: nop
    
            goto L_80049E88;
    }
    // 0x80049E7C: nop

    // 0x80049E80: jal         0x80049968
    // 0x80049E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Cutscene_WarpZoneStart_TeamSetup(rdram, ctx);
        goto after_14;
    // 0x80049E84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
L_80049E88:
    // 0x80049E88: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80049E8C: lw          $t9, 0x78BC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78BC);
    // 0x80049E90: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80049E94: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x80049E98: blez        $t9, L_80049EA8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80049E9C: nop
    
            goto L_80049EA8;
    }
    // 0x80049E9C: nop

    // 0x80049EA0: jal         0x80049968
    // 0x80049EA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Cutscene_WarpZoneStart_TeamSetup(rdram, ctx);
        goto after_15;
    // 0x80049EA4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
L_80049EA8:
    // 0x80049EA8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80049EAC: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x80049EB0: jal         0x80049968
    // 0x80049EB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Cutscene_WarpZoneStart_TeamSetup(rdram, ctx);
        goto after_16;
    // 0x80049EB4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_16:
    // 0x80049EB8: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80049EBC: b           L_8004A518
    // 0x80049EC0: sw          $t2, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r10;
        goto L_8004A518;
    // 0x80049EC0: sw          $t2, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r10;
L_80049EC4:
    // 0x80049EC4: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x80049EC8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80049ECC: addiu       $t5, $t5, 0x79A8
    ctx->r13 = ADD32(ctx->r13, 0X79A8);
    // 0x80049ED0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80049ED4: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x80049ED8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80049EDC: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80049EE0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80049EE4: jal         0x8009BC2C
    // 0x80049EE8: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x80049EE8: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    after_17:
    // 0x80049EEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80049EF0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80049EF4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80049EF8: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80049EFC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80049F00: jal         0x8009BC2C
    // 0x80049F04: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x80049F04: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_18:
    // 0x80049F08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049F0C: lwc1        $f6, -0x7BEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7BEC);
    // 0x80049F10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049F14: lwc1        $f8, 0x58B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X58B4);
    // 0x80049F18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80049F1C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80049F20: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80049F24: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x80049F28: swc1        $f10, -0x7BEC($at)
    MEM_W(-0X7BEC, ctx->r1) = ctx->f10.u32l;
    // 0x80049F2C: lw          $t6, 0x1F8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F8);
    // 0x80049F30: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80049F34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80049F38: bnel        $t6, $zero, L_80049F4C
    if (ctx->r14 != 0) {
        // 0x80049F3C: lwc1        $f16, 0x8C($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
            goto L_80049F4C;
    }
    goto skip_0;
    // 0x80049F3C: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    skip_0:
    // 0x80049F40: sw          $t7, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r15;
    // 0x80049F44: sw          $t8, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r24;
    // 0x80049F48: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
L_80049F4C:
    // 0x80049F4C: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    // 0x80049F50: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80049F54: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80049F58: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80049F5C: swc1        $f18, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f18.u32l;
    // 0x80049F60: b           L_8004A518
    // 0x80049F64: sb          $t9, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r25;
        goto L_8004A518;
    // 0x80049F64: sb          $t9, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r25;
L_80049F68:
    // 0x80049F68: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
    // 0x80049F6C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80049F70: addiu       $t4, $t4, 0x79A8
    ctx->r12 = ADD32(ctx->r12, 0X79A8);
    // 0x80049F74: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80049F78: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80049F7C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80049F80: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80049F84: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80049F88: jal         0x8009BC2C
    // 0x80049F8C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x80049F8C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_19:
    // 0x80049F90: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80049F94: addiu       $v0, $v0, -0x7BEC
    ctx->r2 = ADD32(ctx->r2, -0X7BEC);
    // 0x80049F98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049F9C: lwc1        $f4, 0x58B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X58B8);
    // 0x80049FA0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80049FA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80049FA8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80049FAC: nop

    // 0x80049FB0: bc1fl       L_80049FC8
    if (!c1cs) {
        // 0x80049FB4: lw          $v0, 0x1F8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1F8);
            goto L_80049FC8;
    }
    goto skip_1;
    // 0x80049FB4: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    skip_1:
    // 0x80049FB8: lwc1        $f6, 0x58BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X58BC);
    // 0x80049FBC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80049FC0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80049FC4: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_80049FC8:
    // 0x80049FC8: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x80049FCC: beq         $at, $zero, L_8004A044
    if (ctx->r1 == 0) {
        // 0x80049FD0: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_8004A044;
    }
    // 0x80049FD0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80049FD4: bne         $v0, $at, L_80049FFC
    if (ctx->r2 != ctx->r1) {
        // 0x80049FD8: addiu       $a0, $s0, 0x460
        ctx->r4 = ADD32(ctx->r16, 0X460);
            goto L_80049FFC;
    }
    // 0x80049FD8: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x80049FDC: lui         $a1, 0x940
    ctx->r5 = S32(0X940 << 16);
    // 0x80049FE0: jal         0x800A6028
    // 0x80049FE4: ori         $a1, $a1, 0x802A
    ctx->r5 = ctx->r5 | 0X802A;
    Play_PlaySfxFirstPlayer(rdram, ctx);
        goto after_20;
    // 0x80049FE4: ori         $a1, $a1, 0x802A
    ctx->r5 = ctx->r5 | 0X802A;
    after_20:
    // 0x80049FE8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80049FEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80049FF0: nop

    // 0x80049FF4: swc1        $f0, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f0.u32l;
    // 0x80049FF8: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
L_80049FFC:
    // 0x80049FFC: lwc1        $f0, 0xCC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XCC);
    // 0x8004A000: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004A004: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8004A008: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004A00C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8004A010: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A014: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8004A018: swc1        $f16, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f16.u32l;
    // 0x8004A01C: lwc1        $f6, 0x8C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8004A020: swc1        $f4, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f4.u32l;
    // 0x8004A024: lwc1        $f8, 0x58C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X58C0);
    // 0x8004A028: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8004A02C: nop

    // 0x8004A030: bc1fl       L_8004A048
    if (!c1cs) {
        // 0x8004A034: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8004A048;
    }
    goto skip_2;
    // 0x8004A034: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_2:
    // 0x8004A038: swc1        $f20, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f20.u32l;
    // 0x8004A03C: swc1        $f20, 0xCC($s0)
    MEM_W(0XCC, ctx->r16) = ctx->f20.u32l;
    // 0x8004A040: sw          $zero, 0x234($s0)
    MEM_W(0X234, ctx->r16) = 0;
L_8004A044:
    // 0x8004A044: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8004A048:
    // 0x8004A048: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004A04C: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004A050: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x8004A054: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8004A058: bne         $v0, $at, L_8004A0A8
    if (ctx->r2 != ctx->r1) {
        // 0x8004A05C: swc1        $f0, 0x190($s0)
        MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
            goto L_8004A0A8;
    }
    // 0x8004A05C: swc1        $f0, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f0.u32l;
    // 0x8004A060: lw          $t5, 0x78B4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78B4);
    // 0x8004A064: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004A068: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004A06C: blez        $t5, L_8004A0A8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8004A070: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8004A0A8;
    }
    // 0x8004A070: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004A074: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8004A078: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8004A07C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8004A080: lui         $a0, 0x940
    ctx->r4 = S32(0X940 << 16);
    // 0x8004A084: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8004A088: sh          $t6, 0x4098($at)
    MEM_H(0X4098, ctx->r1) = ctx->r14;
    // 0x8004A08C: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x8004A090: ori         $a0, $a0, 0x802A
    ctx->r4 = ctx->r4 | 0X802A;
    // 0x8004A094: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004A098: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A09C: jal         0x80019218
    // 0x8004A0A0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_21;
    // 0x8004A0A0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_21:
    // 0x8004A0A4: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004A0A8:
    // 0x8004A0A8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004A0AC: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8004A0B0: bne         $v0, $at, L_8004A104
    if (ctx->r2 != ctx->r1) {
        // 0x8004A0B4: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8004A104;
    }
    // 0x8004A0B4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004A0B8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8004A0BC: lw          $t8, 0x78BC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78BC);
    // 0x8004A0C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8004A0C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8004A0C8: blez        $t8, L_8004A104
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8004A0CC: lui         $a0, 0x940
        ctx->r4 = S32(0X940 << 16);
            goto L_8004A104;
    }
    // 0x8004A0CC: lui         $a0, 0x940
    ctx->r4 = S32(0X940 << 16);
    // 0x8004A0D0: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8004A0D4: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8004A0D8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8004A0DC: sh          $t9, 0x4680($at)
    MEM_H(0X4680, ctx->r1) = ctx->r25;
    // 0x8004A0E0: addiu       $a1, $a1, 0x46C8
    ctx->r5 = ADD32(ctx->r5, 0X46C8);
    // 0x8004A0E4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8004A0E8: ori         $a0, $a0, 0x802A
    ctx->r4 = ctx->r4 | 0X802A;
    // 0x8004A0EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A0F0: jal         0x80019218
    // 0x8004A0F4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_22;
    // 0x8004A0F4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_22:
    // 0x8004A0F8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004A0FC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004A100: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004A104:
    // 0x8004A104: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x8004A108: bne         $v0, $at, L_8004A158
    if (ctx->r2 != ctx->r1) {
        // 0x8004A10C: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_8004A158;
    }
    // 0x8004A10C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8004A110: lw          $t3, 0x78B8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78B8);
    // 0x8004A114: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004A118: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8004A11C: blez        $t3, L_8004A158
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8004A120: lui         $a0, 0x940
        ctx->r4 = S32(0X940 << 16);
            goto L_8004A158;
    }
    // 0x8004A120: lui         $a0, 0x940
    ctx->r4 = S32(0X940 << 16);
    // 0x8004A124: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8004A128: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8004A12C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8004A130: sh          $t4, 0x438C($at)
    MEM_H(0X438C, ctx->r1) = ctx->r12;
    // 0x8004A134: addiu       $a1, $a1, 0x43D4
    ctx->r5 = ADD32(ctx->r5, 0X43D4);
    // 0x8004A138: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8004A13C: ori         $a0, $a0, 0x802A
    ctx->r4 = ctx->r4 | 0X802A;
    // 0x8004A140: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A144: jal         0x80019218
    // 0x8004A148: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_23;
    // 0x8004A148: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_23:
    // 0x8004A14C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004A150: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004A154: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004A158:
    // 0x8004A158: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8004A15C: bne         $v0, $at, L_8004A1B0
    if (ctx->r2 != ctx->r1) {
        // 0x8004A160: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8004A1B0;
    }
    // 0x8004A160: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8004A164: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8004A168: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8004A16C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8004A170: lui         $a0, 0x940
    ctx->r4 = S32(0X940 << 16);
    // 0x8004A174: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8004A178: sh          $t6, 0x4974($at)
    MEM_H(0X4974, ctx->r1) = ctx->r14;
    // 0x8004A17C: addiu       $a1, $a1, 0x49BC
    ctx->r5 = ADD32(ctx->r5, 0X49BC);
    // 0x8004A180: ori         $a0, $a0, 0x802A
    ctx->r4 = ctx->r4 | 0X802A;
    // 0x8004A184: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004A188: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A18C: jal         0x80019218
    // 0x8004A190: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_24;
    // 0x8004A190: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_24:
    // 0x8004A194: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x8004A198: jal         0x800182F4
    // 0x8004A19C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_25;
    // 0x8004A19C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_25:
    // 0x8004A1A0: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x8004A1A4: jal         0x800182F4
    // 0x8004A1A8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_26;
    // 0x8004A1A8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_26:
    // 0x8004A1AC: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004A1B0:
    // 0x8004A1B0: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8004A1B4: bne         $v0, $at, L_8004A518
    if (ctx->r2 != ctx->r1) {
        // 0x8004A1B8: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_8004A518;
    }
    // 0x8004A1B8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8004A1BC: sw          $t8, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r24;
    // 0x8004A1C0: b           L_8004A518
    // 0x8004A1C4: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
        goto L_8004A518;
    // 0x8004A1C4: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
L_8004A1C8:
    // 0x8004A1C8: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x8004A1CC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8004A1D0: addiu       $t3, $t3, 0x79A8
    ctx->r11 = ADD32(ctx->r11, 0X79A8);
    // 0x8004A1D4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8004A1D8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8004A1DC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004A1E0: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8004A1E4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004A1E8: jal         0x8009BC2C
    // 0x8004A1EC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_27;
    // 0x8004A1EC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_27:
    // 0x8004A1F0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004A1F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004A1F8: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8004A1FC: lw          $t4, 0x1F8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004A200: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8004A204: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8004A208: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x8004A20C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8004A210: bne         $t4, $zero, L_8004A518
    if (ctx->r12 != 0) {
        // 0x8004A214: swc1        $f18, 0x34($s0)
        MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
            goto L_8004A518;
    }
    // 0x8004A214: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x8004A218: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004A21C: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x8004A220: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8004A224: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8004A228: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A22C: sw          $v0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r2;
    // 0x8004A230: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8004A234: lw          $t8, -0x7CC0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CC0);
    // 0x8004A238: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A23C: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x8004A240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A244: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8004A248: bne         $v0, $t8, L_8004A518
    if (ctx->r2 != ctx->r24) {
        // 0x8004A24C: sw          $t7, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
            goto L_8004A518;
    }
    // 0x8004A24C: sw          $t7, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
    // 0x8004A250: jal         0x800A6148
    // 0x8004A254: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_28;
    // 0x8004A254: nop

    after_28:
    // 0x8004A258: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8004A25C: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8004A260: sw          $t9, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r25;
    // 0x8004A264: sw          $t2, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r10;
    // 0x8004A268: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A26C: lwc1        $f4, 0x58C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X58C4);
    // 0x8004A270: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004A274: addiu       $v1, $v1, 0x7D20
    ctx->r3 = ADD32(ctx->r3, 0X7D20);
    // 0x8004A278: swc1        $f4, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f4.u32l;
    // 0x8004A27C: swc1        $f20, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f20.u32l;
    // 0x8004A280: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004A284: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8004A288: addiu       $v0, $v0, 0x7CB0
    ctx->r2 = ADD32(ctx->r2, 0X7CB0);
    // 0x8004A28C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8004A290: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8004A294: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8004A298: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8004A29C: swc1        $f2, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f2.u32l;
    // 0x8004A2A0: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x8004A2A4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8004A2A8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8004A2AC: addiu       $v1, $v1, 0x7CA0
    ctx->r3 = ADD32(ctx->r3, 0X7CA0);
    // 0x8004A2B0: swc1        $f0, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2B4: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2B8: swc1        $f0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2BC: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2C0: swc1        $f0, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2C4: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2C8: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2CC: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2D0: swc1        $f0, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2D4: swc1        $f0, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2D8: swc1        $f0, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2DC: swc1        $f0, 0xAC($s0)
    MEM_W(0XAC, ctx->r16) = ctx->f0.u32l;
    // 0x8004A2E0: addiu       $t1, $t1, 0x1A9C
    ctx->r9 = ADD32(ctx->r9, 0X1A9C);
    // 0x8004A2E4: addiu       $t0, $t0, 0x7DC8
    ctx->r8 = ADD32(ctx->r8, 0X7DC8);
    // 0x8004A2E8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8004A2EC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8004A2F0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8004A2F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004A2F8: sw          $zero, 0x27C($s0)
    MEM_W(0X27C, ctx->r16) = 0;
    // 0x8004A2FC: sw          $v0, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r2;
    // 0x8004A300: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A304: sw          $v0, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r2;
    // 0x8004A308: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A30C: lwc1        $f8, 0x58C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X58C8);
    // 0x8004A310: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8004A314: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8004A318: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8004A31C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A320: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8004A324: lui         $a0, 0x1140
    ctx->r4 = S32(0X1140 << 16);
    // 0x8004A328: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8004A32C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8004A330: ori         $a0, $a0, 0x7079
    ctx->r4 = ctx->r4 | 0X7079;
    // 0x8004A334: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8004A338: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8004A33C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A340: jal         0x80019218
    // 0x8004A344: swc1        $f8, -0x5DD0($at)
    MEM_W(-0X5DD0, ctx->r1) = ctx->f8.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_29;
    // 0x8004A344: swc1        $f8, -0x5DD0($at)
    MEM_W(-0X5DD0, ctx->r1) = ctx->f8.u32l;
    after_29:
    // 0x8004A348: jal         0x800AB334
    // 0x8004A34C: nop

    Play_InitLevel(rdram, ctx);
        goto after_30;
    // 0x8004A34C: nop

    after_30:
    // 0x8004A350: b           L_8004A51C
    // 0x8004A354: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8004A51C;
    // 0x8004A354: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004A358:
    // 0x8004A358: lw          $t7, 0x1C4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C4);
    // 0x8004A35C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8004A360: addiu       $t9, $t9, 0x79A8
    ctx->r25 = ADD32(ctx->r25, 0X79A8);
    // 0x8004A364: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8004A368: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8004A36C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004A370: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8004A374: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004A378: jal         0x8009BC2C
    // 0x8004A37C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_31;
    // 0x8004A37C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_31:
    // 0x8004A380: lw          $t2, 0x1F8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004A384: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A388: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8004A38C: bne         $t2, $zero, L_8004A518
    if (ctx->r10 != 0) {
        // 0x8004A390: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_8004A518;
    }
    // 0x8004A390: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8004A394: lw          $t4, -0x7CC0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7CC0);
    // 0x8004A398: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8004A39C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A3A0: bne         $t4, $zero, L_8004A518
    if (ctx->r12 != 0) {
        // 0x8004A3A4: sw          $t3, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r11;
            goto L_8004A518;
    }
    // 0x8004A3A4: sw          $t3, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r11;
    // 0x8004A3A8: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x8004A3AC: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x8004A3B0: sw          $t5, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r13;
    // 0x8004A3B4: b           L_8004A518
    // 0x8004A3B8: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
        goto L_8004A518;
    // 0x8004A3B8: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
L_8004A3BC:
    // 0x8004A3BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A3C0: lwc1        $f10, 0x58CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X58CC);
    // 0x8004A3C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8004A3C8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004A3CC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8004A3D0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004A3D4: addiu       $a0, $a0, -0x7BEC
    ctx->r4 = ADD32(ctx->r4, -0X7BEC);
    // 0x8004A3D8: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8004A3DC: jal         0x8009BC2C
    // 0x8004A3E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_32;
    // 0x8004A3E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_32:
    // 0x8004A3E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A3E8: lwc1        $f16, 0x58D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X58D0);
    // 0x8004A3EC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8004A3F0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8004A3F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004A3F8: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x8004A3FC: lui         $a3, 0x43FA
    ctx->r7 = S32(0X43FA << 16);
    // 0x8004A400: jal         0x8009BC2C
    // 0x8004A404: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_33;
    // 0x8004A404: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_33:
    // 0x8004A408: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004A40C: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8004A410: beql        $at, $zero, L_8004A440
    if (ctx->r1 == 0) {
        // 0x8004A414: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_8004A440;
    }
    goto skip_3;
    // 0x8004A414: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    skip_3:
    // 0x8004A418: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004A41C:
    // 0x8004A41C: jal         0x80049B44
    // 0x8004A420: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    Cutscene_EffectSmallRock_Spawn(rdram, ctx);
        goto after_34;
    // 0x8004A420: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_34:
    // 0x8004A424: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x8004A428: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004A42C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8004A430: bne         $v0, $at, L_8004A41C
    if (ctx->r2 != ctx->r1) {
        // 0x8004A434: nop
    
            goto L_8004A41C;
    }
    // 0x8004A434: nop

    // 0x8004A438: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8004A43C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
L_8004A440:
    // 0x8004A440: bne         $v0, $at, L_8004A468
    if (ctx->r2 != ctx->r1) {
        // 0x8004A444: addiu       $t7, $zero, 0x12C
        ctx->r15 = ADD32(0, 0X12C);
            goto L_8004A468;
    }
    // 0x8004A444: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x8004A448: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A44C: sw          $t7, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r15;
    // 0x8004A450: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8004A454: ori         $a1, $zero, 0x803A
    ctx->r5 = 0 | 0X803A;
    // 0x8004A458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A45C: jal         0x8001D444
    // 0x8004A460: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_35;
    // 0x8004A460: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_35:
    // 0x8004A464: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
L_8004A468:
    // 0x8004A468: bne         $v0, $zero, L_8004A4A0
    if (ctx->r2 != 0) {
        // 0x8004A46C: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_8004A4A0;
    }
    // 0x8004A46C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8004A470: swc1        $f20, -0x6A0($at)
    MEM_W(-0X6A0, ctx->r1) = ctx->f20.u32l;
    // 0x8004A474: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A478: swc1        $f20, -0x7BEC($at)
    MEM_W(-0X7BEC, ctx->r1) = ctx->f20.u32l;
    // 0x8004A47C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8004A480: sw          $t8, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r24;
    // 0x8004A484: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x8004A488: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    // 0x8004A48C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A490: sw          $zero, -0x7D48($at)
    MEM_W(-0X7D48, ctx->r1) = 0;
    // 0x8004A494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8004A498: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8004A49C: sw          $v0, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r2;
L_8004A4A0:
    // 0x8004A4A0: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004A4A4: lwc1        $f4, 0x148($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X148);
    // 0x8004A4A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A4AC: lwc1        $f20, 0x58D4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X58D4);
    // 0x8004A4B0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004A4B4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8004A4B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004A4BC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8004A4C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004A4C4: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8004A4C8: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x8004A4CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004A4D0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004A4D4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8004A4D8: jal         0x8009BC2C
    // 0x8004A4DC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_36;
    // 0x8004A4DC: nop

    after_36:
    // 0x8004A4E0: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8004A4E4: lwc1        $f18, 0x14C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x8004A4E8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8004A4EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A4F0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8004A4F4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8004A4F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004A4FC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8004A500: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8004A504: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x8004A508: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004A50C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004A510: jal         0x8009BC2C
    // 0x8004A514: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_37;
    // 0x8004A514: nop

    after_37:
L_8004A518:
    // 0x8004A518: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8004A51C:
    // 0x8004A51C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8004A520: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004A524: jr          $ra
    // 0x8004A528: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8004A528: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_col1_80098860(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098860: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80098864: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80098868: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8009886C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80098870: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80098874: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80098878: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8009887C: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80098880: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80098884: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80098888: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8009888C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80098890: lwc1        $f18, 0x8($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80098894: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80098898: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8009889C: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800988A0: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800988A4: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800988A8: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x800988AC: jr          $ra
    // 0x800988B0: nop

    return;
    // 0x800988B0: nop

;}
RECOMP_FUNC void Math_PursueVec3f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C124: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8009C128: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8009C12C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8009C130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009C134: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8009C138: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009C13C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8009C140: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8009C144: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8009C148: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8009C14C: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    // 0x8009C150: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8009C154: addiu       $t7, $t7, 0x25DC
    ctx->r15 = ADD32(ctx->r15, 0X25DC);
    // 0x8009C158: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8009C15C: addiu       $t6, $sp, 0x98
    ctx->r14 = ADD32(ctx->r29, 0X98);
    // 0x8009C160: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8009C164: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8009C168: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8009C16C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8009C170: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8009C174: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8009C178: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8009C17C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8009C180: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8009C184: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009C188: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009C18C: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8009C190: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8009C194: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8009C198: sub.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8009C19C: jal         0x80005100
    // 0x8009C1A0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8009C1A0: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_0:
    // 0x8009C1A4: jal         0x8009F768
    // 0x8009C1A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_1;
    // 0x8009C1A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8009C1AC: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8009C1B0: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x8009C1B4: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x8009C1B8: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8009C1BC: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009C1C0: jal         0x80005100
    // 0x8009C1C4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x8009C1C4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_2:
    // 0x8009C1C8: jal         0x8009F768
    // 0x8009C1CC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x8009C1CC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_3:
    // 0x8009C1D0: lwc1        $f22, 0xC8($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8009C1D4: lwc1        $f24, 0xCC($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8009C1D8: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x8009C1DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8009C1E0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8009C1E4: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8009C1E8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8009C1EC: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x8009C1F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8009C1F4: jal         0x8009BD38
    // 0x8009C1F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x8009C1F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8009C1FC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8009C200: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8009C204: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8009C208: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8009C20C: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x8009C210: jal         0x8009BD38
    // 0x8009C214: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x8009C214: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x8009C218: lw          $t1, 0xC0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC0);
    // 0x8009C21C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C220: lwc1        $f20, -0x7DC0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X7DC0);
    // 0x8009C224: lwc1        $f16, 0x4($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X4);
    // 0x8009C228: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8009C22C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009C230: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8009C234: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8009C238: jal         0x80005E90
    // 0x8009C23C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8009C23C: nop

    after_6:
    // 0x8009C240: lw          $t2, 0xC0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC0);
    // 0x8009C244: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8009C248: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009C24C: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8009C250: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8009C254: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8009C258: jal         0x80005D44
    // 0x8009C25C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x8009C25C: nop

    after_7:
    // 0x8009C260: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8009C264: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x8009C268: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x8009C26C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x8009C270: jal         0x80006A20
    // 0x8009C274: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x8009C274: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x8009C278: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8009C27C: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8009C280: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009C284: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009C288: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8009C28C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8009C290: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8009C294: lwc1        $f6, 0x90($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8009C298: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009C29C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8009C2A0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8009C2A4: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8009C2A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8009C2AC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009C2B0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8009C2B4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8009C2B8: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8009C2BC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8009C2C0: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8009C2C4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8009C2C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C2CC: sub.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8009C2D0: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8009C2D4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8009C2D8: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8009C2DC: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8009C2E0: lwc1        $f16, 0xD0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8009C2E4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8009C2E8: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8009C2EC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8009C2F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009C2F4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8009C2F8: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8009C2FC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8009C300: nop

    // 0x8009C304: bc1fl       L_8009C314
    if (!c1cs) {
        // 0x8009C308: lw          $s0, 0x34($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X34);
            goto L_8009C314;
    }
    goto skip_0;
    // 0x8009C308: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8009C30C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009C310: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
L_8009C314:
    // 0x8009C314: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8009C318: jr          $ra
    // 0x8009C31C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8009C31C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void Memory_FreeAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006F20: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80006F24: addiu       $t6, $t6, -0x3C30
    ctx->r14 = ADD32(ctx->r14, -0X3C30);
    // 0x80006F28: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80006F2C: sw          $t6, 0x4BD0($at)
    MEM_W(0X4BD0, ctx->r1) = ctx->r14;
    // 0x80006F30: jr          $ra
    // 0x80006F34: nop

    return;
    // 0x80006F34: nop

;}
RECOMP_FUNC void ItemPathChange_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068C88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068C8C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80068C90: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
    // 0x80068C94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80068C98: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x80068C9C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80068CA0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80068CA4: sw          $t6, 0x1680($at)
    MEM_W(0X1680, ctx->r1) = ctx->r14;
    // 0x80068CA8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068CAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80068CB0: lw          $t7, 0x1C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C8);
    // 0x80068CB4: beq         $t7, $at, L_80068CCC
    if (ctx->r15 == ctx->r1) {
        // 0x80068CB8: nop
    
            goto L_80068CCC;
    }
    // 0x80068CB8: nop

    // 0x80068CBC: jal         0x80060FBC
    // 0x80068CC0: addiu       $a1, $a0, 0x5C
    ctx->r5 = ADD32(ctx->r4, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80068CC0: addiu       $a1, $a0, 0x5C
    ctx->r5 = ADD32(ctx->r4, 0X5C);
    after_0:
    // 0x80068CC4: b           L_80068FD4
    // 0x80068CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80068FD4;
    // 0x80068CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068CCC:
    // 0x80068CCC: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x80068CD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80068CD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80068CD8: beq         $a1, $v1, L_80068CE8
    if (ctx->r5 == ctx->r3) {
        // 0x80068CDC: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_80068CE8;
    }
    // 0x80068CDC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80068CE0: bnel        $v1, $at, L_80068D18
    if (ctx->r3 != ctx->r1) {
        // 0x80068CE4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80068D18;
    }
    goto skip_0;
    // 0x80068CE4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_0:
L_80068CE8:
    // 0x80068CE8: lw          $t8, -0x7D84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D84);
    // 0x80068CEC: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80068CF0: bnel        $a1, $t8, L_80068D18
    if (ctx->r5 != ctx->r24) {
        // 0x80068CF4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80068D18;
    }
    goto skip_1;
    // 0x80068CF4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_1:
    // 0x80068CF8: sw          $t9, 0x1C8($v0)
    MEM_W(0X1C8, ctx->r2) = ctx->r25;
    // 0x80068CFC: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80068D00: addiu       $a1, $a0, 0x5C
    ctx->r5 = ADD32(ctx->r4, 0X5C);
    // 0x80068D04: jal         0x80060FBC
    // 0x80068D08: sw          $zero, 0x1D0($t0)
    MEM_W(0X1D0, ctx->r8) = 0;
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x80068D08: sw          $zero, 0x1D0($t0)
    MEM_W(0X1D0, ctx->r8) = 0;
    after_1:
    // 0x80068D0C: b           L_80068FD4
    // 0x80068D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80068FD4;
    // 0x80068D10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068D14: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80068D18:
    // 0x80068D18: bne         $v1, $at, L_80068D3C
    if (ctx->r3 != ctx->r1) {
        // 0x80068D1C: addiu       $t1, $zero, 0x9
        ctx->r9 = ADD32(0, 0X9);
            goto L_80068D3C;
    }
    // 0x80068D1C: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80068D20: sw          $t1, 0x1C8($v0)
    MEM_W(0X1C8, ctx->r2) = ctx->r9;
    // 0x80068D24: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80068D28: addiu       $a1, $a0, 0x5C
    ctx->r5 = ADD32(ctx->r4, 0X5C);
    // 0x80068D2C: jal         0x80060FBC
    // 0x80068D30: sw          $zero, 0x1D0($t2)
    MEM_W(0X1D0, ctx->r10) = 0;
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x80068D30: sw          $zero, 0x1D0($t2)
    MEM_W(0X1D0, ctx->r10) = 0;
    after_2:
    // 0x80068D34: b           L_80068FD4
    // 0x80068D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80068FD4;
    // 0x80068D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068D3C:
    // 0x80068D3C: lbu         $t3, 0x46($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X46);
    // 0x80068D40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068D44: bnel        $t3, $zero, L_80068FD4
    if (ctx->r11 != 0) {
        // 0x80068D48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068FD4;
    }
    goto skip_2;
    // 0x80068D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80068D4C: lwc1        $f4, 0x69A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69A4);
    // 0x80068D50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80068D54: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80068D58: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80068D5C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80068D60: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80068D64: nop

    // 0x80068D68: bc1fl       L_80068DE4
    if (!c1cs) {
        // 0x80068D6C: lb          $t9, 0x4C($a0)
        ctx->r25 = MEM_B(ctx->r4, 0X4C);
            goto L_80068DE4;
    }
    goto skip_3;
    // 0x80068D6C: lb          $t9, 0x4C($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X4C);
    skip_3:
    // 0x80068D70: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80068D74: lwc1        $f18, 0x74($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80068D78: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80068D7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80068D80: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80068D84: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80068D88: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80068D8C: nop

    // 0x80068D90: bc1fl       L_80068DE4
    if (!c1cs) {
        // 0x80068D94: lb          $t9, 0x4C($a0)
        ctx->r25 = MEM_B(ctx->r4, 0X4C);
            goto L_80068DE4;
    }
    goto skip_4;
    // 0x80068D94: lb          $t9, 0x4C($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X4C);
    skip_4:
    // 0x80068D98: lhu         $t4, 0x2($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X2);
    // 0x80068D9C: addiu       $t5, $t4, -0x148
    ctx->r13 = ADD32(ctx->r12, -0X148);
    // 0x80068DA0: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80068DA4: beq         $at, $zero, L_80068DE0
    if (ctx->r1 == 0) {
        // 0x80068DA8: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80068DE0;
    }
    // 0x80068DA8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80068DAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068DB0: addu        $at, $at, $t5
    gpr jr_addend_80068DB8 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80068DB4: lw          $t5, 0x69A8($at)
    ctx->r13 = ADD32(ctx->r1, 0X69A8);
    // 0x80068DB8: jr          $t5
    // 0x80068DBC: nop

    switch (jr_addend_80068DB8 >> 2) {
        case 0: goto L_80068DC0; break;
        case 1: goto L_80068DCC; break;
        case 2: goto L_80068DD8; break;
        case 3: goto L_80068DE0; break;
        case 4: goto L_80068DE0; break;
        case 5: goto L_80068DE0; break;
        default: switch_error(__func__, 0x80068DB8, 0x800D69A8);
    }
    // 0x80068DBC: nop

L_80068DC0:
    // 0x80068DC0: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80068DC4: b           L_80068DE0
    // 0x80068DC8: sw          $t6, 0x228($v0)
    MEM_W(0X228, ctx->r2) = ctx->r14;
        goto L_80068DE0;
    // 0x80068DC8: sw          $t6, 0x228($v0)
    MEM_W(0X228, ctx->r2) = ctx->r14;
L_80068DCC:
    // 0x80068DCC: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80068DD0: b           L_80068DE0
    // 0x80068DD4: sw          $t7, 0x228($v0)
    MEM_W(0X228, ctx->r2) = ctx->r15;
        goto L_80068DE0;
    // 0x80068DD4: sw          $t7, 0x228($v0)
    MEM_W(0X228, ctx->r2) = ctx->r15;
L_80068DD8:
    // 0x80068DD8: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x80068DDC: sw          $t8, 0x228($v0)
    MEM_W(0X228, ctx->r2) = ctx->r24;
L_80068DE0:
    // 0x80068DE0: lb          $t9, 0x4C($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X4C);
L_80068DE4:
    // 0x80068DE4: addiu       $a1, $a0, 0x5C
    ctx->r5 = ADD32(ctx->r4, 0X5C);
    // 0x80068DE8: beql        $t9, $zero, L_80068FD4
    if (ctx->r25 == 0) {
        // 0x80068DEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80068FD4;
    }
    goto skip_5;
    // 0x80068DEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80068DF0: jal         0x80060FBC
    // 0x80068DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x80068DF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_3:
    // 0x80068DF8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80068DFC: addiu       $a2, $a2, -0x7D80
    ctx->r6 = ADD32(ctx->r6, -0X7D80);
    // 0x80068E00: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80068E04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80068E08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80068E0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068E10: swc1        $f8, 0xB4($t0)
    MEM_W(0XB4, ctx->r8) = ctx->f8.u32l;
    // 0x80068E14: lwc1        $f10, 0x69C0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X69C0);
    // 0x80068E18: lwc1        $f4, 0x68($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068E1C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80068E20: mul.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80068E24: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80068E28: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80068E2C: nop

    // 0x80068E30: sw          $t2, 0x210($t3)
    MEM_W(0X210, ctx->r11) = ctx->r10;
    // 0x80068E34: lhu         $t4, 0x2($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X2);
    // 0x80068E38: addiu       $t5, $t4, -0x148
    ctx->r13 = ADD32(ctx->r12, -0X148);
    // 0x80068E3C: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80068E40: beq         $at, $zero, L_80068FD0
    if (ctx->r1 == 0) {
        // 0x80068E44: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80068FD0;
    }
    // 0x80068E44: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80068E48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068E4C: addu        $at, $at, $t5
    gpr jr_addend_80068E54 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80068E50: lw          $t5, 0x69C4($at)
    ctx->r13 = ADD32(ctx->r1, 0X69C4);
    // 0x80068E54: jr          $t5
    // 0x80068E58: nop

    switch (jr_addend_80068E54 >> 2) {
        case 0: goto L_80068E5C; break;
        case 1: goto L_80068EC8; break;
        case 2: goto L_80068EF0; break;
        case 3: goto L_80068F18; break;
        case 4: goto L_80068F84; break;
        case 5: goto L_80068FAC; break;
        default: switch_error(__func__, 0x80068E54, 0x800D69C4);
    }
    // 0x80068E58: nop

L_80068E5C:
    // 0x80068E5C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068E60: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80068E64: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80068E68: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80068E6C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80068E70: nop

    // 0x80068E74: bc1fl       L_80068EA8
    if (!c1cs) {
        // 0x80068E78: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80068EA8;
    }
    goto skip_6;
    // 0x80068E78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_6:
    // 0x80068E7C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80068E80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80068E84: nop

    // 0x80068E88: swc1        $f4, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->f4.u32l;
    // 0x80068E8C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068E90: lwc1        $f16, 0x68($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068E94: lwc1        $f10, 0xAC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x80068E98: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80068E9C: b           L_80068FD0
    // 0x80068EA0: swc1        $f18, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f18.u32l;
        goto L_80068FD0;
    // 0x80068EA0: swc1        $f18, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f18.u32l;
    // 0x80068EA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80068EA8:
    // 0x80068EA8: nop

    // 0x80068EAC: swc1        $f6, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->f6.u32l;
    // 0x80068EB0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068EB4: lwc1        $f4, 0x68($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068EB8: lwc1        $f8, 0xAC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x80068EBC: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80068EC0: b           L_80068FD0
    // 0x80068EC4: swc1        $f10, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f10.u32l;
        goto L_80068FD0;
    // 0x80068EC4: swc1        $f10, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f10.u32l;
L_80068EC8:
    // 0x80068EC8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80068ECC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80068ED0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80068ED4: swc1        $f16, 0x118($t6)
    MEM_W(0X118, ctx->r14) = ctx->f16.u32l;
    // 0x80068ED8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068EDC: lwc1        $f6, 0x68($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068EE0: lwc1        $f18, 0xAC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x80068EE4: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80068EE8: b           L_80068FD0
    // 0x80068EEC: swc1        $f8, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f8.u32l;
        goto L_80068FD0;
    // 0x80068EEC: swc1        $f8, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f8.u32l;
L_80068EF0:
    // 0x80068EF0: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80068EF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80068EF8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80068EFC: swc1        $f4, 0x118($t7)
    MEM_W(0X118, ctx->r15) = ctx->f4.u32l;
    // 0x80068F00: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068F04: lwc1        $f16, 0x68($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068F08: lwc1        $f10, 0xAC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x80068F0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80068F10: b           L_80068FD0
    // 0x80068F14: swc1        $f18, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f18.u32l;
        goto L_80068FD0;
    // 0x80068F14: swc1        $f18, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = ctx->f18.u32l;
L_80068F18:
    // 0x80068F18: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068F1C: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80068F20: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80068F24: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80068F28: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80068F2C: nop

    // 0x80068F30: bc1fl       L_80068F64
    if (!c1cs) {
        // 0x80068F34: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80068F64;
    }
    goto skip_7;
    // 0x80068F34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_7:
    // 0x80068F38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80068F3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80068F40: nop

    // 0x80068F44: swc1        $f4, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f4.u32l;
    // 0x80068F48: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068F4C: lwc1        $f16, 0x68($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068F50: lwc1        $f10, 0xB0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x80068F54: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80068F58: b           L_80068FD0
    // 0x80068F5C: swc1        $f18, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f18.u32l;
        goto L_80068FD0;
    // 0x80068F5C: swc1        $f18, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f18.u32l;
    // 0x80068F60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80068F64:
    // 0x80068F64: nop

    // 0x80068F68: swc1        $f6, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f6.u32l;
    // 0x80068F6C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068F70: lwc1        $f4, 0x68($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068F74: lwc1        $f8, 0xB0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x80068F78: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80068F7C: b           L_80068FD0
    // 0x80068F80: swc1        $f10, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f10.u32l;
        goto L_80068FD0;
    // 0x80068F80: swc1        $f10, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f10.u32l;
L_80068F84:
    // 0x80068F84: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80068F88: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80068F8C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80068F90: swc1        $f16, 0x124($t8)
    MEM_W(0X124, ctx->r24) = ctx->f16.u32l;
    // 0x80068F94: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068F98: lwc1        $f6, 0x68($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068F9C: lwc1        $f18, 0xB0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x80068FA0: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80068FA4: b           L_80068FD0
    // 0x80068FA8: swc1        $f8, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f8.u32l;
        goto L_80068FD0;
    // 0x80068FA8: swc1        $f8, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f8.u32l;
L_80068FAC:
    // 0x80068FAC: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x80068FB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80068FB4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80068FB8: swc1        $f4, 0x124($t9)
    MEM_W(0X124, ctx->r25) = ctx->f4.u32l;
    // 0x80068FBC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80068FC0: lwc1        $f16, 0x68($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X68);
    // 0x80068FC4: lwc1        $f10, 0xB0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x80068FC8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80068FCC: swc1        $f18, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f18.u32l;
L_80068FD0:
    // 0x80068FD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80068FD4:
    // 0x80068FD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80068FD8: jr          $ra
    // 0x80068FDC: nop

    return;
    // 0x80068FDC: nop

;}
RECOMP_FUNC void Audio_StartEngineNoise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CEFC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8001CF00: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8001CF04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001CF08: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CF0C: lbu         $t7, 0x478($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X478);
    // 0x8001CF10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CF14: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001CF18: bne         $t7, $at, L_8001CF2C
    if (ctx->r15 != ctx->r1) {
        // 0x8001CF1C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8001CF2C;
    }
    // 0x8001CF1C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001CF20: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8001CF24: b           L_8001CF34
    // 0x8001CF28: ori         $a0, $a0, 0x40
    ctx->r4 = ctx->r4 | 0X40;
        goto L_8001CF34;
    // 0x8001CF28: ori         $a0, $a0, 0x40
    ctx->r4 = ctx->r4 | 0X40;
L_8001CF2C:
    // 0x8001CF2C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8001CF30: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
L_8001CF34:
    // 0x8001CF34: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001CF38: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8001CF3C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8001CF40: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8001CF44: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8001CF48: jal         0x80019218
    // 0x8001CF4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001CF4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001CF50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CF54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001CF58: jr          $ra
    // 0x8001CF5C: nop

    return;
    // 0x8001CF5C: nop

;}
RECOMP_FUNC void Message_GetCharCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2928: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800C292C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C2930: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C2934: beql        $t6, $zero, L_800C2954
    if (ctx->r14 == 0) {
        // 0x800C2938: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800C2954;
    }
    goto skip_0;
    // 0x800C2938: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x800C293C: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
L_800C2940:
    // 0x800C2940: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C2944: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C2948: bnel        $t7, $zero, L_800C2940
    if (ctx->r15 != 0) {
        // 0x800C294C: lhu         $t7, 0x2($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X2);
            goto L_800C2940;
    }
    goto skip_1;
    // 0x800C294C: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    skip_1:
    // 0x800C2950: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800C2954:
    // 0x800C2954: jr          $ra
    // 0x800C2958: nop

    return;
    // 0x800C2958: nop

;}
RECOMP_FUNC void Audio_ProcessSfxRequests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A988: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001A98C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A990: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A994: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8001A998: lui         $s1, 0x800C
    ctx->r17 = S32(0X800C << 16);
    // 0x8001A99C: addiu       $s1, $s1, 0x5D18
    ctx->r17 = ADD32(ctx->r17, 0X5D18);
    // 0x8001A9A0: addiu       $s0, $s0, 0x5D1C
    ctx->r16 = ADD32(ctx->r16, 0X5D1C);
    // 0x8001A9A4: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8001A9A8: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x8001A9AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A9B0: beql        $t6, $t7, L_8001A9DC
    if (ctx->r14 == ctx->r15) {
        // 0x8001A9B4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001A9DC;
    }
    goto skip_0;
    // 0x8001A9B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8001A9B8:
    // 0x8001A9B8: jal         0x80019434
    // 0x8001A9BC: nop

    Audio_ProcessSfxRequest(rdram, ctx);
        goto after_0;
    // 0x8001A9BC: nop

    after_0:
    // 0x8001A9C0: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8001A9C4: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x8001A9C8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8001A9CC: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8001A9D0: bne         $t0, $t1, L_8001A9B8
    if (ctx->r8 != ctx->r9) {
        // 0x8001A9D4: sb          $t9, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r25;
            goto L_8001A9B8;
    }
    // 0x8001A9D4: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8001A9D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001A9DC:
    // 0x8001A9DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001A9E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001A9E4: jr          $ra
    // 0x8001A9E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001A9E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Audio_SetSfxMapModulation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D15C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001D160: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001D164: slti        $at, $t6, 0xC
    ctx->r1 = SIGNED(ctx->r14) < 0XC ? 1 : 0;
    // 0x8001D168: beq         $at, $zero, L_8001D1B0
    if (ctx->r1 == 0) {
        // 0x8001D16C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_8001D1B0;
    }
    // 0x8001D16C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x8001D170: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x8001D174: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001D178: bgez        $t6, L_8001D18C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001D17C: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001D18C;
    }
    // 0x8001D17C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D180: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D184: nop

    // 0x8001D188: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001D18C:
    // 0x8001D18C: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8001D190: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D194: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8001D198: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D19C: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8001D1A0: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001D1A4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001D1A8: jr          $ra
    // 0x8001D1AC: swc1        $f4, 0x5E74($at)
    MEM_W(0X5E74, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x8001D1AC: swc1        $f4, 0x5E74($at)
    MEM_W(0X5E74, ctx->r1) = ctx->f4.u32l;
L_8001D1B0:
    // 0x8001D1B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8001D1B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D1B8: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001D1BC: swc1        $f8, 0x5E74($at)
    MEM_W(0X5E74, ctx->r1) = ctx->f8.u32l;
    // 0x8001D1C0: jr          $ra
    // 0x8001D1C4: nop

    return;
    // 0x8001D1C4: nop

;}
RECOMP_FUNC void HUD_MsgWindowBg_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800853A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800853A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800853AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800853B0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800853B4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800853B8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800853BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800853C0: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x800853C4: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x800853C8: addiu       $t6, $zero, 0x11
    ctx->r14 = ADD32(0, 0X11);
    // 0x800853CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800853D0: addiu       $a2, $a2, 0x3570
    ctx->r6 = ADD32(ctx->r6, 0X3570);
    // 0x800853D4: addiu       $a1, $a1, 0x3170
    ctx->r5 = ADD32(ctx->r5, 0X3170);
    // 0x800853D8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800853DC: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x800853E0: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800853E4: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800853E8: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800853EC: jal         0x8009D0BC
    // 0x800853F0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800853F0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800853F4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800853F8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800853FC: jr          $ra
    // 0x80085400: nop

    return;
    // 0x80085400: nop

;}
RECOMP_FUNC void ActorTeamBoss_HandleDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091F00: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80091F04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80091F08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80091F0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80091F10: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x80091F14: lbu         $v0, 0xD0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD0);
    // 0x80091F18: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80091F1C: beq         $t6, $at, L_80091F30
    if (ctx->r14 == ctx->r1) {
        // 0x80091F20: sb          $zero, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = 0;
            goto L_80091F30;
    }
    // 0x80091F20: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x80091F24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80091F28: bne         $v0, $at, L_80091F38
    if (ctx->r2 != ctx->r1) {
        // 0x80091F2C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80091F38;
    }
    // 0x80091F2C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
L_80091F30:
    // 0x80091F30: b           L_80092230
    // 0x80091F34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80092230;
    // 0x80091F34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80091F38:
    // 0x80091F38: lh          $t7, 0xCE($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XCE);
    // 0x80091F3C: lhu         $t8, 0xD6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XD6);
    // 0x80091F40: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80091F44: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80091F48: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80091F4C: sh          $t9, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r25;
    // 0x80091F50: lh          $t1, 0xCE($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCE);
    // 0x80091F54: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80091F58: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x80091F5C: bgtz        $t1, L_80091F6C
    if (SIGNED(ctx->r9) > 0) {
        // 0x80091F60: addiu       $a1, $s0, 0x100
        ctx->r5 = ADD32(ctx->r16, 0X100);
            goto L_80091F6C;
    }
    // 0x80091F60: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80091F64: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80091F68: sh          $t2, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r10;
L_80091F6C:
    // 0x80091F6C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80091F70: sh          $t3, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r11;
    // 0x80091F74: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x80091F78: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80091F7C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80091F80: jal         0x80019218
    // 0x80091F84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80091F84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80091F88: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80091F8C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80091F90: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80091F94: jal         0x8007D10C
    // 0x80091F98: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_1;
    // 0x80091F98: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_1:
    // 0x80091F9C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091FA0: lwc1        $f6, 0x7FA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7FA4);
    // 0x80091FA4: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80091FA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80091FAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80091FB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80091FB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80091FB8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80091FBC: jal         0x80005E90
    // 0x80091FC0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80091FC0: nop

    after_2:
    // 0x80091FC4: jal         0x80004EB0
    // 0x80091FC8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80091FC8: nop

    after_3:
    // 0x80091FCC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80091FD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80091FD4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80091FD8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80091FDC: nop

    // 0x80091FE0: bc1fl       L_80091FFC
    if (!c1cs) {
        // 0x80091FE4: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80091FFC;
    }
    goto skip_0;
    // 0x80091FE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x80091FE8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80091FEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80091FF0: b           L_80092004
    // 0x80091FF4: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
        goto L_80092004;
    // 0x80091FF4: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x80091FF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80091FFC:
    // 0x80091FFC: nop

    // 0x80092000: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
L_80092004:
    // 0x80092004: jal         0x80004EB0
    // 0x80092008: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80092008: nop

    after_4:
    // 0x8009200C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80092010: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80092014: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80092018: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009201C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80092020: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80092024: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80092028: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009202C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80092030: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80092034: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    // 0x80092038: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x8009203C: jal         0x80006A20
    // 0x80092040: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x80092040: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80092044: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80092048: lh          $t6, 0xE4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XE4);
    // 0x8009204C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80092050: swc1        $f18, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f18.u32l;
    // 0x80092054: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80092058: lh          $t5, 0xCE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XCE);
    // 0x8009205C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80092060: swc1        $f4, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f4.u32l;
    // 0x80092064: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80092068: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8009206C: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80092070: swc1        $f6, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f6.u32l;
    // 0x80092074: lw          $t8, -0x7D64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D64);
    // 0x80092078: sw          $t5, 0x78B0($at)
    MEM_W(0X78B0, ctx->r1) = ctx->r13;
    // 0x8009207C: beql        $t8, $zero, L_80092090
    if (ctx->r24 == 0) {
        // 0x80092080: lb          $a0, 0xD0($s0)
        ctx->r4 = MEM_B(ctx->r16, 0XD0);
            goto L_80092090;
    }
    goto skip_1;
    // 0x80092080: lb          $a0, 0xD0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XD0);
    skip_1:
    // 0x80092084: b           L_80092230
    // 0x80092088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80092230;
    // 0x80092088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009208C: lb          $a0, 0xD0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XD0);
L_80092090:
    // 0x80092090: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80092094: bnel        $a3, $a0, L_80092120
    if (ctx->r7 != ctx->r4) {
        // 0x80092098: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80092120;
    }
    goto skip_2;
    // 0x80092098: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_2:
    // 0x8009209C: lh          $t9, 0xD4($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XD4);
    // 0x800920A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800920A4: bnel        $a2, $t9, L_80092120
    if (ctx->r6 != ctx->r25) {
        // 0x800920A8: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80092120;
    }
    goto skip_3;
    // 0x800920A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    skip_3:
    // 0x800920AC: lh          $v0, 0xE4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE4);
    // 0x800920B0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800920B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800920B8: beq         $v0, $a2, L_800920D8
    if (ctx->r2 == ctx->r6) {
        // 0x800920BC: nop
    
            goto L_800920D8;
    }
    // 0x800920BC: nop

    // 0x800920C0: beq         $v0, $t0, L_80092108
    if (ctx->r2 == ctx->r8) {
        // 0x800920C4: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_80092108;
    }
    // 0x800920C4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800920C8: beq         $v0, $a3, L_800920F0
    if (ctx->r2 == ctx->r7) {
        // 0x800920CC: addiu       $a1, $zero, 0x1E
        ctx->r5 = ADD32(0, 0X1E);
            goto L_800920F0;
    }
    // 0x800920CC: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800920D0: b           L_80092120
    // 0x800920D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_80092120;
    // 0x800920D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800920D8:
    // 0x800920D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800920DC: jal         0x800BA808
    // 0x800920E0: addiu       $a0, $a0, 0x398C
    ctx->r4 = ADD32(ctx->r4, 0X398C);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x800920E0: addiu       $a0, $a0, 0x398C
    ctx->r4 = ADD32(ctx->r4, 0X398C);
    after_6:
    // 0x800920E4: lb          $a0, 0xD0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XD0);
    // 0x800920E8: b           L_8009211C
    // 0x800920EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_8009211C;
    // 0x800920EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800920F0:
    // 0x800920F0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800920F4: jal         0x800BA808
    // 0x800920F8: addiu       $a0, $a0, 0x3950
    ctx->r4 = ADD32(ctx->r4, 0X3950);
    Radio_PlayMessage(rdram, ctx);
        goto after_7;
    // 0x800920F8: addiu       $a0, $a0, 0x3950
    ctx->r4 = ADD32(ctx->r4, 0X3950);
    after_7:
    // 0x800920FC: lb          $a0, 0xD0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XD0);
    // 0x80092100: b           L_8009211C
    // 0x80092104: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
        goto L_8009211C;
    // 0x80092104: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_80092108:
    // 0x80092108: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8009210C: jal         0x800BA808
    // 0x80092110: addiu       $a0, $a0, 0x3900
    ctx->r4 = ADD32(ctx->r4, 0X3900);
    Radio_PlayMessage(rdram, ctx);
        goto after_8;
    // 0x80092110: addiu       $a0, $a0, 0x3900
    ctx->r4 = ADD32(ctx->r4, 0X3900);
    after_8:
    // 0x80092114: lb          $a0, 0xD0($s0)
    ctx->r4 = MEM_B(ctx->r16, 0XD0);
    // 0x80092118: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_8009211C:
    // 0x8009211C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80092120:
    // 0x80092120: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80092124: beq         $a3, $a0, L_800921B8
    if (ctx->r7 == ctx->r4) {
        // 0x80092128: lh          $v1, 0xD4($s0)
        ctx->r3 = MEM_H(ctx->r16, 0XD4);
            goto L_800921B8;
    }
    // 0x80092128: lh          $v1, 0xD4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XD4);
    // 0x8009212C: bne         $a2, $v1, L_800921B8
    if (ctx->r6 != ctx->r3) {
        // 0x80092130: nop
    
            goto L_800921B8;
    }
    // 0x80092130: nop

    // 0x80092134: lh          $v0, 0xE4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE4);
    // 0x80092138: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8009213C: addiu       $a0, $a0, 0x36B0
    ctx->r4 = ADD32(ctx->r4, 0X36B0);
    // 0x80092140: beq         $v0, $a2, L_80092160
    if (ctx->r2 == ctx->r6) {
        // 0x80092144: nop
    
            goto L_80092160;
    }
    // 0x80092144: nop

    // 0x80092148: beq         $v0, $t0, L_8009219C
    if (ctx->r2 == ctx->r8) {
        // 0x8009214C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8009219C;
    }
    // 0x8009214C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80092150: beq         $v0, $a3, L_8009217C
    if (ctx->r2 == ctx->r7) {
        // 0x80092154: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8009217C;
    }
    // 0x80092154: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80092158: b           L_800921B8
    // 0x8009215C: nop

        goto L_800921B8;
    // 0x8009215C: nop

L_80092160:
    // 0x80092160: jal         0x800BA808
    // 0x80092164: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_9;
    // 0x80092164: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_9:
    // 0x80092168: lh          $v1, 0xD4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XD4);
    // 0x8009216C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80092170: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80092174: b           L_800921B8
    // 0x80092178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800921B8;
    // 0x80092178: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8009217C:
    // 0x8009217C: addiu       $a0, $a0, 0x36F8
    ctx->r4 = ADD32(ctx->r4, 0X36F8);
    // 0x80092180: jal         0x800BA808
    // 0x80092184: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_10;
    // 0x80092184: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_10:
    // 0x80092188: lh          $v1, 0xD4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XD4);
    // 0x8009218C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80092190: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80092194: b           L_800921B8
    // 0x80092198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800921B8;
    // 0x80092198: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8009219C:
    // 0x8009219C: addiu       $a0, $a0, 0x3724
    ctx->r4 = ADD32(ctx->r4, 0X3724);
    // 0x800921A0: jal         0x800BA808
    // 0x800921A4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x800921A4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_11:
    // 0x800921A8: lh          $v1, 0xD4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XD4);
    // 0x800921AC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800921B0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800921B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800921B8:
    // 0x800921B8: beq         $t0, $v1, L_800921C8
    if (ctx->r8 == ctx->r3) {
        // 0x800921BC: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_800921C8;
    }
    // 0x800921BC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800921C0: bnel        $v1, $at, L_80092228
    if (ctx->r3 != ctx->r1) {
        // 0x800921C4: addiu       $t1, $zero, 0x14
        ctx->r9 = ADD32(0, 0X14);
            goto L_80092228;
    }
    goto skip_4;
    // 0x800921C4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    skip_4:
L_800921C8:
    // 0x800921C8: lh          $v0, 0xE4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE4);
    // 0x800921CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800921D0: addiu       $a0, $a0, 0x3630
    ctx->r4 = ADD32(ctx->r4, 0X3630);
    // 0x800921D4: beq         $v0, $a2, L_800921F4
    if (ctx->r2 == ctx->r6) {
        // 0x800921D8: nop
    
            goto L_800921F4;
    }
    // 0x800921D8: nop

    // 0x800921DC: beq         $v0, $t0, L_80092218
    if (ctx->r2 == ctx->r8) {
        // 0x800921E0: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80092218;
    }
    // 0x800921E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800921E4: beq         $v0, $a3, L_80092204
    if (ctx->r2 == ctx->r7) {
        // 0x800921E8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80092204;
    }
    // 0x800921E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800921EC: b           L_80092228
    // 0x800921F0: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
        goto L_80092228;
    // 0x800921F0: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_800921F4:
    // 0x800921F4: jal         0x800BA808
    // 0x800921F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_12;
    // 0x800921F8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_12:
    // 0x800921FC: b           L_80092228
    // 0x80092200: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
        goto L_80092228;
    // 0x80092200: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_80092204:
    // 0x80092204: addiu       $a0, $a0, 0x366C
    ctx->r4 = ADD32(ctx->r4, 0X366C);
    // 0x80092208: jal         0x800BA808
    // 0x8009220C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_13;
    // 0x8009220C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_13:
    // 0x80092210: b           L_80092228
    // 0x80092214: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
        goto L_80092228;
    // 0x80092214: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_80092218:
    // 0x80092218: addiu       $a0, $a0, 0x3690
    ctx->r4 = ADD32(ctx->r4, 0X3690);
    // 0x8009221C: jal         0x800BA808
    // 0x80092220: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_14;
    // 0x80092220: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_14:
    // 0x80092224: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_80092228:
    // 0x80092228: sw          $t1, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r9;
    // 0x8009222C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80092230:
    // 0x80092230: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80092234: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80092238: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8009223C: jr          $ra
    // 0x80092240: nop

    return;
    // 0x80092240: nop

;}
RECOMP_FUNC void Controller_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000291C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002924: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80002928: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8000292C: addiu       $a2, $a2, -0x2710
    ctx->r6 = ADD32(ctx->r6, -0X2710);
    // 0x80002930: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    // 0x80002934: jal         0x8001FFC0
    // 0x80002938: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    osContInit_recomp(rdram, ctx);
        goto after_0;
    // 0x80002938: addiu       $a1, $sp, 0x1F
    ctx->r5 = ADD32(ctx->r29, 0X1F);
    after_0:
    // 0x8000293C: lbu         $v0, 0x1F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1F);
    // 0x80002940: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002948: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8000294C: sb          $t6, -0x2750($at)
    MEM_B(-0X2750, ctx->r1) = ctx->r14;
    // 0x80002950: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002954: sb          $zero, -0x2748($at)
    MEM_B(-0X2748, ctx->r1) = 0;
    // 0x80002958: sra         $t7, $v0, 1
    ctx->r15 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8000295C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80002960: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002964: sb          $t8, -0x274F($at)
    MEM_B(-0X274F, ctx->r1) = ctx->r24;
    // 0x80002968: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000296C: sb          $zero, -0x2747($at)
    MEM_B(-0X2747, ctx->r1) = 0;
    // 0x80002970: sra         $t9, $v0, 2
    ctx->r25 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80002974: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x80002978: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000297C: sb          $t0, -0x274E($at)
    MEM_B(-0X274E, ctx->r1) = ctx->r8;
    // 0x80002980: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002984: sb          $zero, -0x2746($at)
    MEM_B(-0X2746, ctx->r1) = 0;
    // 0x80002988: sra         $t1, $v0, 3
    ctx->r9 = S32(SIGNED(ctx->r2) >> 3);
    // 0x8000298C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80002990: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80002994: sb          $t2, -0x274D($at)
    MEM_B(-0X274D, ctx->r1) = ctx->r10;
    // 0x80002998: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000299C: sb          $zero, -0x2745($at)
    MEM_B(-0X2745, ctx->r1) = 0;
    // 0x800029A0: jr          $ra
    // 0x800029A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800029A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_enmy_8006684C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006684C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80066850: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80066854: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066858: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006685C: lhu         $v0, 0xBE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBE);
    // 0x80066860: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80066864: beql        $v0, $zero, L_80066918
    if (ctx->r2 == 0) {
        // 0x80066868: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_80066918;
    }
    goto skip_0;
    // 0x80066868: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x8006686C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80066870: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80066874: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80066878: swc1        $f0, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f0.u32l;
    // 0x8006687C: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x80066880: bne         $v0, $at, L_8006698C
    if (ctx->r2 != ctx->r1) {
        // 0x80066884: swc1        $f0, 0xEC($s0)
        MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
            goto L_8006698C;
    }
    // 0x80066884: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x80066888: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8006688C: jal         0x80060FBC
    // 0x80066890: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80066890: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_0:
    // 0x80066894: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80066898: sb          $t6, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r14;
    // 0x8006689C: jal         0x80066254
    // 0x800668A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_1;
    // 0x800668A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800668A4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800668A8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800668AC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800668B0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x800668B4: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x800668B8: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x800668BC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800668C0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800668C4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x800668C8: jal         0x80019218
    // 0x800668CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800668CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x800668D0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x800668D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800668D8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800668DC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800668E0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800668E4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800668E8: jal         0x80077240
    // 0x800668EC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    BonusText_Display(rdram, ctx);
        goto after_3;
    // 0x800668EC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_3:
    // 0x800668F0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800668F4: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x800668F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800668FC: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80066900: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80066904: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80066908: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8006690C: b           L_8006698C
    // 0x80066910: sw          $t0, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r8;
        goto L_8006698C;
    // 0x80066910: sw          $t0, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r8;
    // 0x80066914: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_80066918:
    // 0x80066918: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8006691C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066920: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80066924: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80066928: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8006692C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80066930: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80066934: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80066938: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8006693C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80066940: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x80066944: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80066948: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8006694C: bc1f        L_8006698C
    if (!c1cs) {
        // 0x80066950: swc1        $f4, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
            goto L_8006698C;
    }
    // 0x80066950: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80066954: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80066958: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006695C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80066960: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80066964: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80066968: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006696C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80066970: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80066974: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80066978: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8006697C: jal         0x8007BFFC
    // 0x80066980: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_4;
    // 0x80066980: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    after_4:
    // 0x80066984: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80066988: sh          $t2, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r10;
L_8006698C:
    // 0x8006698C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80066990: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80066994: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80066998: jr          $ra
    // 0x8006699C: nop

    return;
    // 0x8006699C: nop

;}
RECOMP_FUNC void Aquas_Effect363_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800933D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800933DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800933E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800933E4: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800933E8: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800933EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800933F0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800933F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800933F8: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x800933FC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80093400: addiu       $s0, $s0, 0x3754
    ctx->r16 = ADD32(ctx->r16, 0X3754);
    // 0x80093404: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80093408: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x8009340C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
L_80093410:
    // 0x80093410: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80093414: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80093418: bne         $t7, $zero, L_800935CC
    if (ctx->r15 != 0) {
        // 0x8009341C: nop
    
            goto L_800935CC;
    }
    // 0x8009341C: nop

    // 0x80093420: jal         0x80061474
    // 0x80093424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80093424: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80093428: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8009342C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80093430: addiu       $t9, $zero, 0x16B
    ctx->r25 = ADD32(0, 0X16B);
    // 0x80093434: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x80093438: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x8009343C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80093440: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80093444: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80093448: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8009344C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80093450: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80093454: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80093458: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8009345C: lw          $t0, 0x1C8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C8);
    // 0x80093460: bne         $t0, $at, L_800934EC
    if (ctx->r8 != ctx->r1) {
        // 0x80093464: nop
    
            goto L_800934EC;
    }
    // 0x80093464: nop

    // 0x80093468: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x8009346C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80093470: bne         $t1, $at, L_800934EC
    if (ctx->r9 != ctx->r1) {
        // 0x80093474: nop
    
            goto L_800934EC;
    }
    // 0x80093474: nop

    // 0x80093478: lw          $t2, 0x1D0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1D0);
    // 0x8009347C: addiu       $t3, $zero, 0x18
    ctx->r11 = ADD32(0, 0X18);
    // 0x80093480: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80093484: beq         $at, $zero, L_800934EC
    if (ctx->r1 == 0) {
        // 0x80093488: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800934EC;
    }
    // 0x80093488: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8009348C: lwc1        $f10, 0x7FF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7FF4);
    // 0x80093490: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
    // 0x80093494: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
    // 0x80093498: jal         0x80004EB0
    // 0x8009349C: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8009349C: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x800934A0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800934A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800934A8: nop

    // 0x800934AC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800934B0: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800934B4: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800934B8: jal         0x80004EB0
    // 0x800934BC: sh          $t5, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r13;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800934BC: sh          $t5, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r13;
    after_2:
    // 0x800934C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800934C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800934C8: nop

    // 0x800934CC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800934D0: nop

    // 0x800934D4: bc1f        L_80093590
    if (!c1cs) {
        // 0x800934D8: nop
    
            goto L_80093590;
    }
    // 0x800934D8: nop

    // 0x800934DC: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x800934E0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800934E4: b           L_80093590
    // 0x800934E8: sh          $t7, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r15;
        goto L_80093590;
    // 0x800934E8: sh          $t7, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r15;
L_800934EC:
    // 0x800934EC: jal         0x80004EB0
    // 0x800934F0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x800934F0: nop

    after_3:
    // 0x800934F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800934F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800934FC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80093500: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80093504: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80093508: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009350C: jal         0x80004EB0
    // 0x80093510: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80093510: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x80093514: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80093518: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009351C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80093520: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80093524: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80093528: sh          $zero, 0x48($s0)
    MEM_H(0X48, ctx->r16) = 0;
    // 0x8009352C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80093530: jal         0x80004EB0
    // 0x80093534: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x80093534: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x80093538: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8009353C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80093540: addiu       $t2, $zero, 0x60
    ctx->r10 = ADD32(0, 0X60);
    // 0x80093544: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80093548: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8009354C: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80093550: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80093554: bc1fl       L_8009356C
    if (!c1cs) {
        // 0x80093558: lw          $t0, 0x24($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X24);
            goto L_8009356C;
    }
    goto skip_0;
    // 0x80093558: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8009355C: lh          $t8, 0x48($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X48);
    // 0x80093560: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80093564: sh          $t9, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r25;
    // 0x80093568: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_8009356C:
    // 0x8009356C: lw          $t1, 0x1D0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1D0);
    // 0x80093570: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x80093574: bnel        $at, $zero, L_8009358C
    if (ctx->r1 != 0) {
        // 0x80093578: sh          $t4, 0x4A($s0)
        MEM_H(0X4A, ctx->r16) = ctx->r12;
            goto L_8009358C;
    }
    goto skip_1;
    // 0x80093578: sh          $t4, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r12;
    skip_1:
    // 0x8009357C: sh          $t2, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r10;
    // 0x80093580: b           L_80093590
    // 0x80093584: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
        goto L_80093590;
    // 0x80093584: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
    // 0x80093588: sh          $t4, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r12;
L_8009358C:
    // 0x8009358C: sh          $t5, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r13;
L_80093590:
    // 0x80093590: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80093594: lwc1        $f4, 0x7FF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7FF8);
    // 0x80093598: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009359C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800935A0: jal         0x80004EB0
    // 0x800935A4: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800935A4: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x800935A8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800935AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800935B0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800935B4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x800935B8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800935BC: jal         0x800612B8
    // 0x800935C0: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_7;
    // 0x800935C0: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_7:
    // 0x800935C4: b           L_800935D8
    // 0x800935C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800935D8;
    // 0x800935C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800935CC:
    // 0x800935CC: bne         $v0, $v1, L_80093410
    if (ctx->r2 != ctx->r3) {
        // 0x800935D0: addiu       $s0, $s0, -0x8C
        ctx->r16 = ADD32(ctx->r16, -0X8C);
            goto L_80093410;
    }
    // 0x800935D0: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
    // 0x800935D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800935D8:
    // 0x800935D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800935DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800935E0: jr          $ra
    // 0x800935E4: nop

    return;
    // 0x800935E4: nop

;}
RECOMP_FUNC void HUD_BoostGaugeFrame_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085740: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80085744: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80085748: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8008574C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80085750: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80085754: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x80085758: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008575C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80085760: beq         $t6, $zero, L_800857A4
    if (ctx->r14 == 0) {
        // 0x80085764: lui         $a1, 0x100
        ctx->r5 = S32(0X100 << 16);
            goto L_800857A4;
    }
    // 0x80085764: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x80085768: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008576C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80085770: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085774: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x80085778: addiu       $a1, $a1, 0xB20
    ctx->r5 = ADD32(ctx->r5, 0XB20);
    // 0x8008577C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80085780: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x80085784: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80085788: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8008578C: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x80085790: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80085794: jal         0x8009D994
    // 0x80085798: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x80085798: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8008579C: b           L_800857D0
    // 0x800857A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800857D0;
    // 0x800857A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800857A4:
    // 0x800857A4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800857A8: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800857AC: addiu       $a1, $a1, 0xE80
    ctx->r5 = ADD32(ctx->r5, 0XE80);
    // 0x800857B0: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x800857B4: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x800857B8: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800857BC: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800857C0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800857C4: jal         0x8009D994
    // 0x800857C8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x800857C8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800857CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800857D0:
    // 0x800857D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800857D4: jr          $ra
    // 0x800857D8: nop

    return;
    // 0x800857D8: nop

;}
RECOMP_FUNC void Display_DrawPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054280: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80054284: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054288: lw          $v0, 0x1CC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1CC);
    // 0x8005428C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80054290: beq         $v0, $zero, L_800542B8
    if (ctx->r2 == 0) {
        // 0x80054294: nop
    
            goto L_800542B8;
    }
    // 0x80054294: nop

    // 0x80054298: beq         $v0, $at, L_800542C8
    if (ctx->r2 == ctx->r1) {
        // 0x8005429C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800542C8;
    }
    // 0x8005429C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800542A0: beq         $v0, $at, L_800542D8
    if (ctx->r2 == ctx->r1) {
        // 0x800542A4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800542D8;
    }
    // 0x800542A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800542A8: beq         $v0, $at, L_800542E8
    if (ctx->r2 == ctx->r1) {
        // 0x800542AC: nop
    
            goto L_800542E8;
    }
    // 0x800542AC: nop

    // 0x800542B0: b           L_800542F4
    // 0x800542B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800542F4;
    // 0x800542B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800542B8:
    // 0x800542B8: jal         0x80053C38
    // 0x800542BC: nop

    Display_Arwing(rdram, ctx);
        goto after_0;
    // 0x800542BC: nop

    after_0:
    // 0x800542C0: b           L_800542F4
    // 0x800542C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800542F4;
    // 0x800542C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800542C8:
    // 0x800542C8: jal         0x80052884
    // 0x800542CC: nop

    Display_Landmaster(rdram, ctx);
        goto after_1;
    // 0x800542CC: nop

    after_1:
    // 0x800542D0: b           L_800542F4
    // 0x800542D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800542F4;
    // 0x800542D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800542D8:
    // 0x800542D8: jal         0x801ACBB4
    // 0x800542DC: nop

    Aquas_BlueMarine_Draw(rdram, ctx);
        goto after_2;
    // 0x800542DC: nop

    after_2:
    // 0x800542E0: b           L_800542F4
    // 0x800542E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800542F4;
    // 0x800542E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800542E8:
    // 0x800542E8: jal         0x800526B8
    // 0x800542EC: nop

    Display_OnFootCharacter(rdram, ctx);
        goto after_3;
    // 0x800542EC: nop

    after_3:
    // 0x800542F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800542F4:
    // 0x800542F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800542F8: jr          $ra
    // 0x800542FC: nop

    return;
    // 0x800542FC: nop

;}
RECOMP_FUNC void Save_ReadBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007130: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007134: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007138: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000713C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80007140: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80007144: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    // 0x80007148: jal         0x800234B0
    // 0x8000714C: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    osEepromRead_recomp(rdram, ctx);
        goto after_0;
    // 0x8000714C: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
    // 0x80007150: beq         $v0, $zero, L_80007160
    if (ctx->r2 == 0) {
        // 0x80007154: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80007160;
    }
    // 0x80007154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007158: b           L_80007164
    // 0x8000715C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007164;
    // 0x8000715C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007160:
    // 0x80007160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007164:
    // 0x80007164: jr          $ra
    // 0x80007168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80007168: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Effect_Effect385_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007803C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80078044: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80078048: jal         0x8005980C
    // 0x8007804C: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007804C: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    after_0:
    // 0x80078050: jal         0x800BA5B0
    // 0x80078054: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_1;
    // 0x80078054: nop

    after_1:
    // 0x80078058: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007805C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80078060: jal         0x800B8DD0
    // 0x80078064: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80078064: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_2:
    // 0x80078068: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007806C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80078070: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80078074: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80078078: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007807C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80078080: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80078084: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80078088: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007808C: lh          $t9, 0x44($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X44);
    // 0x80078090: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80078094: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80078098: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8007809C: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800780A0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800780A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800780A8: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800780AC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800780B0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800780B4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800780B8: lh          $t5, 0x44($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X44);
    // 0x800780BC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800780C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800780C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800780C8: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x800780CC: addiu       $t9, $t9, 0x4AC0
    ctx->r25 = ADD32(ctx->r25, 0X4AC0);
    // 0x800780D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800780D4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800780D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800780DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800780E0: jal         0x800B8DD0
    // 0x800780E4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x800780E4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x800780E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800780EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800780F0: jr          $ra
    // 0x800780F4: nop

    return;
    // 0x800780F4: nop

;}
RECOMP_FUNC void func_versus_800C0294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0294: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C0298: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C029C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C02A0: addiu       $t0, $sp, 0x3C
    ctx->r8 = ADD32(ctx->r29, 0X3C);
    // 0x800C02A4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800C02A8: addiu       $t6, $t6, 0x4C6C
    ctx->r14 = ADD32(ctx->r14, 0X4C6C);
    // 0x800C02AC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800C02B0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800C02B4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800C02B8: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x800C02BC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x800C02C0: addiu       $t1, $t1, -0x7844
    ctx->r9 = ADD32(ctx->r9, -0X7844);
    // 0x800C02C4: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800C02C8: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800C02CC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x800C02D0: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x800C02D4: lw          $t9, 0xC($t6)
    ctx->r25 = MEM_W(ctx->r14, 0XC);
    // 0x800C02D8: sw          $t9, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r25;
    // 0x800C02DC: lw          $at, 0x10($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X10);
    // 0x800C02E0: sw          $at, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r1;
    // 0x800C02E4: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800C02E8: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x800C02EC: bnel        $t3, $at, L_800C02FC
    if (ctx->r11 != ctx->r1) {
        // 0x800C02F0: lw          $v0, 0x0($t1)
        ctx->r2 = MEM_W(ctx->r9, 0X0);
            goto L_800C02FC;
    }
    goto skip_0;
    // 0x800C02F0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    skip_0:
    // 0x800C02F4: sw          $t4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r12;
    // 0x800C02F8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
L_800C02FC:
    // 0x800C02FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C0300: beql        $v0, $zero, L_800C04CC
    if (ctx->r2 == 0) {
        // 0x800C0304: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800C04CC;
    }
    goto skip_1;
    // 0x800C0304: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    skip_1:
    // 0x800C0308: beq         $v0, $at, L_800C0330
    if (ctx->r2 == ctx->r1) {
        // 0x800C030C: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800C0330;
    }
    // 0x800C030C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C0310: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C0314: beq         $v0, $at, L_800C0398
    if (ctx->r2 == ctx->r1) {
        // 0x800C0318: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800C0398;
    }
    // 0x800C0318: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C031C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C0320: beq         $v0, $at, L_800C03F4
    if (ctx->r2 == ctx->r1) {
        // 0x800C0324: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_800C03F4;
    }
    // 0x800C0324: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C0328: b           L_800C04C8
    // 0x800C032C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_800C04C8;
    // 0x800C032C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800C0330:
    // 0x800C0330: addiu       $v1, $v1, -0x783C
    ctx->r3 = ADD32(ctx->r3, -0X783C);
    // 0x800C0334: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800C0338: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C033C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C0340: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C0344: addiu       $v0, $v0, -0x7840
    ctx->r2 = ADD32(ctx->r2, -0X7840);
    // 0x800C0348: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C034C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C0350: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x800C0354: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0358: sub.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800C035C: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800C0360: addu        $t7, $t0, $t8
    ctx->r15 = ADD32(ctx->r8, ctx->r24);
    // 0x800C0364: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x800C0368: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800C036C: lwc1        $f16, -0x6D74($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6D74);
    // 0x800C0370: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800C0374: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C0378: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C037C: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    // 0x800C0380: nop

    // 0x800C0384: bc1fl       L_800C04CC
    if (!c1cs) {
        // 0x800C0388: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800C04CC;
    }
    goto skip_2;
    // 0x800C0388: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    skip_2:
    // 0x800C038C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800C0390: b           L_800C04C8
    // 0x800C0394: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
        goto L_800C04C8;
    // 0x800C0394: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_800C0398:
    // 0x800C0398: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C039C: lwc1        $f18, -0x6D70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6D70);
    // 0x800C03A0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x800C03A4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x800C03A8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800C03AC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800C03B0: addiu       $a0, $a0, -0x7838
    ctx->r4 = ADD32(ctx->r4, -0X7838);
    // 0x800C03B4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800C03B8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800C03BC: jal         0x8009BC2C
    // 0x800C03C0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800C03C0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800C03C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C03C8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800C03CC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C03D0: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800C03D4: addiu       $v1, $v1, -0x783C
    ctx->r3 = ADD32(ctx->r3, -0X783C);
    // 0x800C03D8: addiu       $t1, $t1, -0x7844
    ctx->r9 = ADD32(ctx->r9, -0X7844);
    // 0x800C03DC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800C03E0: bc1f        L_800C04C8
    if (!c1cs) {
        // 0x800C03E4: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_800C04C8;
    }
    // 0x800C03E4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800C03E8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800C03EC: b           L_800C04C8
    // 0x800C03F0: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
        goto L_800C04C8;
    // 0x800C03F0: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_800C03F4:
    // 0x800C03F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C03F8: lwc1        $f4, -0x6D6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D6C);
    // 0x800C03FC: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x800C0400: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800C0404: addiu       $a0, $a0, -0x7838
    ctx->r4 = ADD32(ctx->r4, -0X7838);
    // 0x800C0408: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x800C040C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800C0410: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800C0414: jal         0x8009BC2C
    // 0x800C0418: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800C0418: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800C041C: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800C0420: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C0424: addiu       $t0, $sp, 0x3C
    ctx->r8 = ADD32(ctx->r29, 0X3C);
    // 0x800C0428: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800C042C: addiu       $v0, $v0, -0x7840
    ctx->r2 = ADD32(ctx->r2, -0X7840);
    // 0x800C0430: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800C0434: lwc1        $f12, 0x0($t5)
    ctx->f12.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800C0438: lwc1        $f14, 0x0($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C043C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800C0440: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C0444: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800C0448: addiu       $t1, $t1, -0x7844
    ctx->r9 = ADD32(ctx->r9, -0X7844);
    // 0x800C044C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800C0450: addiu       $v1, $v1, -0x783C
    ctx->r3 = ADD32(ctx->r3, -0X783C);
    // 0x800C0454: bc1f        L_800C047C
    if (!c1cs) {
        // 0x800C0458: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800C047C;
    }
    // 0x800C0458: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800C045C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C0460: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C0464: nop

    // 0x800C0468: add.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800C046C: add.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x800C0470: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    // 0x800C0474: b           L_800C0480
    // 0x800C0478: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_800C0480;
    // 0x800C0478: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_800C047C:
    // 0x800C047C: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
L_800C0480:
    // 0x800C0480: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C0484: c.eq.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl == ctx->f12.fl;
    // 0x800C0488: nop

    // 0x800C048C: bc1fl       L_800C04CC
    if (!c1cs) {
        // 0x800C0490: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800C04CC;
    }
    goto skip_3;
    // 0x800C0490: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    skip_3:
    // 0x800C0494: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C0498: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C049C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800C04A0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800C04A4: nop

    // 0x800C04A8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800C04AC: nop

    // 0x800C04B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C04B4: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x800C04B8: nop

    // 0x800C04BC: bc1fl       L_800C04CC
    if (!c1cs) {
        // 0x800C04C0: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800C04CC;
    }
    goto skip_4;
    // 0x800C04C0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    skip_4:
    // 0x800C04C4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_800C04C8:
    // 0x800C04C8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800C04CC:
    // 0x800C04CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C04D0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800C04D4: jr          $ra
    // 0x800C04D8: nop

    return;
    // 0x800C04D8: nop

;}
RECOMP_FUNC void func_versus_800BC88C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC88C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BC890: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BC894: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800BC898: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800BC89C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BC8A0: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x800BC8A4: addiu       $a1, $a1, 0x3830
    ctx->r5 = ADD32(ctx->r5, 0X3830);
    // 0x800BC8A8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BC8AC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800BC8B0: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    // 0x800BC8B4: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800BC8B8: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800BC8BC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800BC8C0: jal         0x8009D994
    // 0x800BC8C4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BC8C4: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800BC8C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BC8CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BC8D0: jr          $ra
    // 0x800BC8D4: nop

    return;
    // 0x800BC8D4: nop

;}
RECOMP_FUNC void ActorEvent_DamageWarpGate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800720E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800720EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800720F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800720F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800720F8: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
    // 0x800720FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80072100: beql        $v0, $zero, L_80072128
    if (ctx->r2 == 0) {
        // 0x80072104: lb          $v0, 0xD0($s0)
        ctx->r2 = MEM_B(ctx->r16, 0XD0);
            goto L_80072128;
    }
    goto skip_0;
    // 0x80072104: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
    skip_0:
    // 0x80072108: beq         $v0, $at, L_8007227C
    if (ctx->r2 == ctx->r1) {
        // 0x8007210C: addiu       $a0, $s0, 0x154
        ctx->r4 = ADD32(ctx->r16, 0X154);
            goto L_8007227C;
    }
    // 0x8007210C: addiu       $a0, $s0, 0x154
    ctx->r4 = ADD32(ctx->r16, 0X154);
    // 0x80072110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80072114: beq         $v0, $at, L_8007227C
    if (ctx->r2 == ctx->r1) {
        // 0x80072118: nop
    
            goto L_8007227C;
    }
    // 0x80072118: nop

    // 0x8007211C: b           L_800722DC
    // 0x80072120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800722DC;
    // 0x80072120: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80072124: lb          $v0, 0xD0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0XD0);
L_80072128:
    // 0x80072128: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007212C: beql        $v0, $zero, L_800722DC
    if (ctx->r2 == 0) {
        // 0x80072130: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800722DC;
    }
    goto skip_1;
    // 0x80072130: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80072134: bne         $v0, $at, L_80072140
    if (ctx->r2 != ctx->r1) {
        // 0x80072138: addiu       $t6, $zero, 0x3
        ctx->r14 = ADD32(0, 0X3);
            goto L_80072140;
    }
    // 0x80072138: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8007213C: sh          $t6, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r14;
L_80072140:
    // 0x80072140: lh          $v0, 0xD4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XD4);
    // 0x80072144: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80072148: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007214C: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x80072150: bne         $at, $zero, L_8007218C
    if (ctx->r1 != 0) {
        // 0x80072154: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_8007218C;
    }
    // 0x80072154: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80072158: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8007215C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80072160: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80072164: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80072168: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8007216C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80072170: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80072174: lh          $t8, 0x1650($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X1650);
    // 0x80072178: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x8007217C: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80072180: bnel        $t8, $at, L_80072190
    if (ctx->r24 != ctx->r1) {
        // 0x80072184: lh          $t0, 0xCE($s0)
        ctx->r8 = MEM_H(ctx->r16, 0XCE);
            goto L_80072190;
    }
    goto skip_2;
    // 0x80072184: lh          $t0, 0xCE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCE);
    skip_2:
    // 0x80072188: sh          $t9, 0xD6($s0)
    MEM_H(0XD6, ctx->r16) = ctx->r25;
L_8007218C:
    // 0x8007218C: lh          $t0, 0xCE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCE);
L_80072190:
    // 0x80072190: lhu         $t1, 0xD6($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XD6);
    // 0x80072194: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072198: lwc1        $f4, 0x154($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X154);
    // 0x8007219C: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800721A0: sh          $t2, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r10;
    // 0x800721A4: lwc1        $f6, 0x6D90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D90);
    // 0x800721A8: lhu         $v0, 0xBE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBE);
    // 0x800721AC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x800721B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800721B4: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x800721B8: sh          $t3, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r11;
    // 0x800721BC: beq         $at, $zero, L_800721CC
    if (ctx->r1 == 0) {
        // 0x800721C0: swc1        $f8, 0x154($s0)
        MEM_W(0X154, ctx->r16) = ctx->f8.u32l;
            goto L_800721CC;
    }
    // 0x800721C0: swc1        $f8, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f8.u32l;
    // 0x800721C4: addiu       $t4, $v0, 0x5
    ctx->r12 = ADD32(ctx->r2, 0X5);
    // 0x800721C8: sh          $t4, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r12;
L_800721CC:
    // 0x800721CC: lh          $t5, 0xCE($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XCE);
    // 0x800721D0: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x800721D4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800721D8: bgtz        $t5, L_80072258
    if (SIGNED(ctx->r13) > 0) {
        // 0x800721DC: ori         $a0, $a0, 0x300E
        ctx->r4 = ctx->r4 | 0X300E;
            goto L_80072258;
    }
    // 0x800721DC: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x800721E0: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x800721E4: addiu       $v0, $v0, 0x2408
    ctx->r2 = ADD32(ctx->r2, 0X2408);
    // 0x800721E8: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800721EC: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800721F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800721F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800721F8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800721FC: sh          $t6, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r14;
    // 0x80072200: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80072204: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80072208: lw          $t0, 0x1FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FD0);
    // 0x8007220C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80072210: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80072214: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80072218: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8007221C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80072220: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x80072224: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80072228: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007222C: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
    // 0x80072230: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x80072234: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x80072238: ori         $a0, $a0, 0xD
    ctx->r4 = ctx->r4 | 0XD;
    // 0x8007223C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80072240: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80072244: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80072248: jal         0x80019218
    // 0x8007224C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8007224C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80072250: b           L_80072274
    // 0x80072254: nop

        goto L_80072274;
    // 0x80072254: nop

L_80072258:
    // 0x80072258: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8007225C: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80072260: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80072264: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80072268: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007226C: jal         0x80019218
    // 0x80072270: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80072270: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
L_80072274:
    // 0x80072274: b           L_800722D8
    // 0x80072278: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
        goto L_800722D8;
    // 0x80072278: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
L_8007227C:
    // 0x8007227C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072280: lwc1        $f10, 0x6D94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D94);
    // 0x80072284: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80072288: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007228C: lui         $a1, 0x4302
    ctx->r5 = S32(0X4302 << 16);
    // 0x80072290: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x80072294: jal         0x8009BC2C
    // 0x80072298: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80072298: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8007229C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800722A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800722A4: lwc1        $f18, 0x154($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X154);
    // 0x800722A8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800722AC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800722B0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800722B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800722B8: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x800722BC: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800722C0: bc1fl       L_800722DC
    if (!c1cs) {
        // 0x800722C4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800722DC;
    }
    goto skip_3;
    // 0x800722C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x800722C8: lwc1        $f4, 0x6D98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D98);
    // 0x800722CC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800722D0: jal         0x8009BC2C
    // 0x800722D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800722D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
L_800722D8:
    // 0x800722D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800722DC:
    // 0x800722DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800722E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800722E4: jr          $ra
    // 0x800722E8: nop

    return;
    // 0x800722E8: nop

;}
RECOMP_FUNC void Load_InitDmaAndMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005949C: lui         $a0, 0xE
    ctx->r4 = S32(0XE << 16);
    // 0x800594A0: addiu       $a0, $a0, -0x1B80
    ctx->r4 = ADD32(ctx->r4, -0X1B80);
    // 0x800594A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800594A8: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x800594AC: addiu       $t6, $t6, -0x15E0
    ctx->r14 = ADD32(ctx->r14, -0X15E0);
    // 0x800594B0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800594B4: addiu       $a1, $a1, -0x7590
    ctx->r5 = ADD32(ctx->r5, -0X7590);
    // 0x800594B8: jal         0x800033E0
    // 0x800594BC: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    Lib_DmaRead(rdram, ctx);
        goto after_0;
    // 0x800594BC: subu        $a2, $t6, $a0
    ctx->r6 = SUB32(ctx->r14, ctx->r4);
    after_0:
    // 0x800594C0: lui         $a0, 0xDE
    ctx->r4 = S32(0XDE << 16);
    // 0x800594C4: lui         $t7, 0xDF
    ctx->r15 = S32(0XDF << 16);
    // 0x800594C8: addiu       $a0, $a0, 0x5D50
    ctx->r4 = ADD32(ctx->r4, 0X5D50);
    // 0x800594CC: addiu       $t7, $t7, 0x4260
    ctx->r15 = ADD32(ctx->r15, 0X4260);
    // 0x800594D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800594D4: addiu       $a1, $a1, -0x6FF0
    ctx->r5 = ADD32(ctx->r5, -0X6FF0);
    // 0x800594D8: jal         0x80058B80
    // 0x800594DC: subu        $a2, $t7, $a0
    ctx->r6 = SUB32(ctx->r15, ctx->r4);
    Load_RomFile(rdram, ctx);
        goto after_1;
    // 0x800594DC: subu        $a2, $t7, $a0
    ctx->r6 = SUB32(ctx->r15, ctx->r4);
    after_1:
    // 0x800594E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800594E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800594E8: jr          $ra
    // 0x800594EC: nop

    return;
    // 0x800594EC: nop

;}
RECOMP_FUNC void Effect_TorpedoTrail_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E3E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007E3E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007E3EC: lh          $t6, 0x4A($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4A);
    // 0x8007E3F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E3F4: lwc1        $f6, 0x7470($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7470);
    // 0x8007E3F8: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007E3FC: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x8007E400: sh          $t7, 0x4A($a0)
    MEM_H(0X4A, ctx->r4) = ctx->r15;
    // 0x8007E404: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007E408: lh          $t8, 0x4A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4A);
    // 0x8007E40C: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007E410: bgez        $t8, L_8007E424
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8007E414: swc1        $f8, 0x70($a0)
        MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
            goto L_8007E424;
    }
    // 0x8007E414: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x8007E418: jal         0x80060FBC
    // 0x8007E41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007E41C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007E420: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007E424:
    // 0x8007E424: lh          $t9, 0x48($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X48);
    // 0x8007E428: lwc1        $f10, 0x18($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8007E42C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E430: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8007E434: lwc1        $f6, 0x58($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007E438: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8007E43C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007E440: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x8007E444: lwc1        $f8, 0x7474($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7474);
    // 0x8007E448: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E44C: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
    // 0x8007E450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007E454: jr          $ra
    // 0x8007E458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007E458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Effect_Effect385_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B494: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B498: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007B49C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007B4A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B4A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007B4A8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007B4AC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007B4B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007B4B4: jal         0x80061474
    // 0x8007B4B8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007B4B8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007B4BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007B4C0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B4C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B4C8: addiu       $t7, $zero, 0x181
    ctx->r15 = ADD32(0, 0X181);
    // 0x8007B4CC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007B4D0: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007B4D4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007B4D8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8007B4DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007B4E0: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007B4E4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007B4E8: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8007B4EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007B4F0: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007B4F4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007B4F8: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
    // 0x8007B4FC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007B500: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007B504: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007B508: sh          $v0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r2;
    // 0x8007B50C: beq         $at, $zero, L_8007B51C
    if (ctx->r1 == 0) {
        // 0x8007B510: swc1        $f16, 0x6C($a2)
        MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
            goto L_8007B51C;
    }
    // 0x8007B510: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x8007B514: b           L_8007B538
    // 0x8007B518: sh          $t8, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r24;
        goto L_8007B538;
    // 0x8007B518: sh          $t8, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r24;
L_8007B51C:
    // 0x8007B51C: slti        $at, $v0, 0x5A
    ctx->r1 = SIGNED(ctx->r2) < 0X5A ? 1 : 0;
    // 0x8007B520: beq         $at, $zero, L_8007B534
    if (ctx->r1 == 0) {
        // 0x8007B524: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_8007B534;
    }
    // 0x8007B524: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8007B528: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8007B52C: b           L_8007B538
    // 0x8007B530: sh          $t9, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r25;
        goto L_8007B538;
    // 0x8007B530: sh          $t9, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r25;
L_8007B534:
    // 0x8007B534: sh          $t0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r8;
L_8007B538:
    // 0x8007B538: jal         0x800612B8
    // 0x8007B53C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007B53C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_1:
    // 0x8007B540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B544: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007B548: jr          $ra
    // 0x8007B54C: nop

    return;
    // 0x8007B54C: nop

;}
RECOMP_FUNC void Audio_ProcessNotes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011FA8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80011FAC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80011FB0: lw          $v1, 0x5CA0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5CA0);
    // 0x80011FB4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80011FB8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80011FBC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80011FC0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80011FC4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80011FC8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80011FCC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80011FD0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80011FD4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80011FD8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80011FDC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80011FE0: blez        $v1, L_80012400
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80011FE4: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_80012400;
    }
    // 0x80011FE4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80011FE8: lui         $s6, 0x8015
    ctx->r22 = S32(0X8015 << 16);
    // 0x80011FEC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80011FF0: addiu       $s6, $s6, 0x5C78
    ctx->r22 = ADD32(ctx->r22, 0X5C78);
    // 0x80011FF4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80011FF8: addiu       $fp, $sp, 0x73
    ctx->r30 = ADD32(ctx->r29, 0X73);
    // 0x80011FFC: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80012000: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80012004: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_80012008:
    // 0x80012008: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001200C: lw          $t6, -0x1AD0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1AD0);
    // 0x80012010: addu        $s1, $s3, $t6
    ctx->r17 = ADD32(ctx->r19, ctx->r14);
    // 0x80012014: lw          $t7, 0x44($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X44);
    // 0x80012018: addiu       $s0, $s1, 0x30
    ctx->r16 = ADD32(ctx->r17, 0X30);
    // 0x8001201C: beql        $s4, $t7, L_80012140
    if (ctx->r20 == ctx->r15) {
        // 0x80012020: lbu         $t1, 0x4($s0)
        ctx->r9 = MEM_BU(ctx->r16, 0X4);
            goto L_80012140;
    }
    goto skip_0;
    // 0x80012020: lbu         $t1, 0x4($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X4);
    skip_0:
    // 0x80012024: addiu       $s0, $s1, 0x30
    ctx->r16 = ADD32(ctx->r17, 0X30);
    // 0x80012028: lw          $a1, 0x14($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14);
    // 0x8001202C: lui         $at, 0x7FFF
    ctx->r1 = S32(0X7FFF << 16);
    // 0x80012030: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80012034: sltu        $at, $a1, $at
    ctx->r1 = ctx->r5 < ctx->r1 ? 1 : 0;
    // 0x80012038: beq         $at, $zero, L_8001204C
    if (ctx->r1 == 0) {
        // 0x8001203C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8001204C;
    }
    // 0x8001203C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80012040: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80012044: b           L_800123F0
    // 0x80012048: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
        goto L_800123F0;
    // 0x80012048: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
L_8001204C:
    // 0x8001204C: lw          $t8, 0x40($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X40);
    // 0x80012050: beql        $s1, $t8, L_8001208C
    if (ctx->r17 == ctx->r24) {
        // 0x80012054: lw          $t2, 0x0($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X0);
            goto L_8001208C;
    }
    goto skip_1;
    // 0x80012054: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    skip_1:
    // 0x80012058: lbu         $t9, 0x4($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X4);
    // 0x8001205C: bnel        $t9, $zero, L_8001208C
    if (ctx->r25 != 0) {
        // 0x80012060: lw          $t2, 0x0($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X0);
            goto L_8001208C;
    }
    goto skip_2;
    // 0x80012060: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    skip_2:
    // 0x80012064: lbu         $t0, 0x28($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X28);
    // 0x80012068: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x8001206C: ori         $t1, $t0, 0x10
    ctx->r9 = ctx->r8 | 0X10;
    // 0x80012070: sb          $t1, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r9;
    // 0x80012074: lwc1        $f4, 0x18($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X18);
    // 0x80012078: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x8001207C: sb          $s7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r23;
    // 0x80012080: b           L_80012168
    // 0x80012084: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
        goto L_80012168;
    // 0x80012084: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
    // 0x80012088: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
L_8001208C:
    // 0x8001208C: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x80012090: bnel        $t3, $zero, L_800120B4
    if (ctx->r11 != 0) {
        // 0x80012094: lw          $a0, 0x4C($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X4C);
            goto L_800120B4;
    }
    goto skip_3;
    // 0x80012094: lw          $a0, 0x4C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4C);
    skip_3:
    // 0x80012098: lbu         $t4, 0x4($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X4);
    // 0x8001209C: bnel        $t4, $zero, L_800120B4
    if (ctx->r12 != 0) {
        // 0x800120A0: lw          $a0, 0x4C($a1)
        ctx->r4 = MEM_W(ctx->r5, 0X4C);
            goto L_800120B4;
    }
    goto skip_4;
    // 0x800120A0: lw          $a0, 0x4C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4C);
    skip_4:
    // 0x800120A4: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x800120A8: bgtz        $t5, L_80012110
    if (SIGNED(ctx->r13) > 0) {
        // 0x800120AC: nop
    
            goto L_80012110;
    }
    // 0x800120AC: nop

    // 0x800120B0: lw          $a0, 0x4C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X4C);
L_800120B4:
    // 0x800120B4: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800120B8: bnel        $v0, $zero, L_800120EC
    if (ctx->r2 != 0) {
        // 0x800120BC: lw          $t6, 0x0($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X0);
            goto L_800120EC;
    }
    goto skip_5;
    // 0x800120BC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    skip_5:
    // 0x800120C0: jal         0x8001415C
    // 0x800120C4: nop

    AudioSeq_SequenceChannelDisable(rdram, ctx);
        goto after_0;
    // 0x800120C4: nop

    after_0:
    // 0x800120C8: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x800120CC: sb          $s5, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r21;
    // 0x800120D0: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800120D4: lw          $v1, 0x5CA0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5CA0);
    // 0x800120D8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800120DC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800120E0: b           L_800123F0
    // 0x800120E4: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
        goto L_800123F0;
    // 0x800120E4: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
    // 0x800120E8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
L_800120EC:
    // 0x800120EC: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800120F0: bgez        $t8, L_80012108
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800120F4: nop
    
            goto L_80012108;
    }
    // 0x800120F4: nop

    // 0x800120F8: lbu         $t9, 0x3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X3);
    // 0x800120FC: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x80012100: bne         $t0, $zero, L_80012110
    if (ctx->r8 != 0) {
        // 0x80012104: nop
    
            goto L_80012110;
    }
    // 0x80012104: nop

L_80012108:
    // 0x80012108: b           L_80012168
    // 0x8001210C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
        goto L_80012168;
    // 0x8001210C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_80012110:
    // 0x80012110: jal         0x8001268C
    // 0x80012114: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    Audio_SeqLayerNoteRelease(rdram, ctx);
        goto after_1;
    // 0x80012114: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80012118: jal         0x80012C40
    // 0x8001211C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_AudioListRemove(rdram, ctx);
        goto after_2;
    // 0x8001211C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80012120: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80012124: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80012128: jal         0x80012C00
    // 0x8001212C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    Audio_AudioListPushFront(rdram, ctx);
        goto after_3;
    // 0x8001212C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_3:
    // 0x80012130: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x80012134: b           L_80012164
    // 0x80012138: sb          $s7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r23;
        goto L_80012164;
    // 0x80012138: sb          $s7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r23;
    // 0x8001213C: lbu         $t1, 0x4($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X4);
L_80012140:
    // 0x80012140: bnel        $t1, $zero, L_80012168
    if (ctx->r9 != 0) {
        // 0x80012144: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_80012168;
    }
    goto skip_6;
    // 0x80012144: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_6:
    // 0x80012148: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x8001214C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80012150: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80012154: blezl       $t2, L_80012168
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80012158: lbu         $v0, 0x0($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X0);
            goto L_80012168;
    }
    goto skip_7;
    // 0x80012158: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    skip_7:
    // 0x8001215C: b           L_800123F0
    // 0x80012160: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
        goto L_800123F0;
    // 0x80012160: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
L_80012164:
    // 0x80012164: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
L_80012168:
    // 0x80012168: beq         $v0, $zero, L_800123DC
    if (ctx->r2 == 0) {
        // 0x8001216C: nop
    
            goto L_800123DC;
    }
    // 0x8001216C: nop

    // 0x80012170: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80012174: addiu       $s2, $s1, 0xB0
    ctx->r18 = ADD32(ctx->r17, 0XB0);
    // 0x80012178: bgtzl       $v0, L_80012194
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001217C: lbu         $t6, 0x29($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X29);
            goto L_80012194;
    }
    goto skip_8;
    // 0x8001217C: lbu         $t6, 0x29($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X29);
    skip_8:
    // 0x80012180: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80012184: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80012188: bgezl       $t5, L_80012254
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8001218C: lbu         $t2, 0x29($s0)
        ctx->r10 = MEM_BU(ctx->r16, 0X29);
            goto L_80012254;
    }
    goto skip_9;
    // 0x8001218C: lbu         $t2, 0x29($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X29);
    skip_9:
    // 0x80012190: lbu         $t6, 0x29($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X29);
L_80012194:
    // 0x80012194: addiu       $s2, $s1, 0xB0
    ctx->r18 = ADD32(ctx->r17, 0XB0);
    // 0x80012198: beql        $t6, $zero, L_800121B4
    if (ctx->r14 == 0) {
        // 0x8001219C: lw          $t0, 0x18($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X18);
            goto L_800121B4;
    }
    goto skip_10;
    // 0x8001219C: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
    skip_10:
    // 0x800121A0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800121A4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800121A8: bgez        $t9, L_80012280
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800121AC: nop
    
            goto L_80012280;
    }
    // 0x800121AC: nop

    // 0x800121B0: lw          $t0, 0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X18);
L_800121B4:
    // 0x800121B4: beq         $s4, $t0, L_8001222C
    if (ctx->r20 == ctx->r8) {
        // 0x800121B8: nop
    
            goto L_8001222C;
    }
    // 0x800121B8: nop

    // 0x800121BC: jal         0x80011F4C
    // 0x800121C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_NoteDisable(rdram, ctx);
        goto after_4;
    // 0x800121C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800121C4: lw          $a1, 0x18($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18);
    // 0x800121C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800121CC: lw          $t1, 0x4C($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4C);
    // 0x800121D0: beq         $t1, $zero, L_80012208
    if (ctx->r9 == 0) {
        // 0x800121D4: nop
    
            goto L_80012208;
    }
    // 0x800121D4: nop

    // 0x800121D8: jal         0x80012CEC
    // 0x800121DC: addiu       $s2, $s1, 0xB0
    ctx->r18 = ADD32(ctx->r17, 0XB0);
    Audio_NoteInitForLayer(rdram, ctx);
        goto after_5;
    // 0x800121DC: addiu       $s2, $s1, 0xB0
    ctx->r18 = ADD32(ctx->r17, 0XB0);
    after_5:
    // 0x800121E0: jal         0x80013A84
    // 0x800121E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_NoteVibratoInit(rdram, ctx);
        goto after_6;
    // 0x800121E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x800121E8: jal         0x80012C40
    // 0x800121EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_AudioListRemove(rdram, ctx);
        goto after_7;
    // 0x800121EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800121F0: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x800121F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800121F8: jal         0x800145BC
    // 0x800121FC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_8;
    // 0x800121FC: addiu       $a0, $a0, 0x30
    ctx->r4 = ADD32(ctx->r4, 0X30);
    after_8:
    // 0x80012200: b           L_80012280
    // 0x80012204: sw          $s4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r20;
        goto L_80012280;
    // 0x80012204: sw          $s4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r20;
L_80012208:
    // 0x80012208: jal         0x80011F4C
    // 0x8001220C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_NoteDisable(rdram, ctx);
        goto after_9;
    // 0x8001220C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80012210: jal         0x80012C40
    // 0x80012214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_AudioListRemove(rdram, ctx);
        goto after_10;
    // 0x80012214: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80012218: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8001221C: jal         0x800145BC
    // 0x80012220: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_11;
    // 0x80012220: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_11:
    // 0x80012224: b           L_800123DC
    // 0x80012228: sw          $s4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r20;
        goto L_800123DC;
    // 0x80012228: sw          $s4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r20;
L_8001222C:
    // 0x8001222C: jal         0x80011F4C
    // 0x80012230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_NoteDisable(rdram, ctx);
        goto after_12;
    // 0x80012230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80012234: jal         0x80012C40
    // 0x80012238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_AudioListRemove(rdram, ctx);
        goto after_13;
    // 0x80012238: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8001223C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80012240: jal         0x800145BC
    // 0x80012244: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_14;
    // 0x80012244: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_14:
    // 0x80012248: b           L_800123DC
    // 0x8001224C: nop

        goto L_800123DC;
    // 0x8001224C: nop

    // 0x80012250: lbu         $t2, 0x29($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X29);
L_80012254:
    // 0x80012254: bne         $t2, $zero, L_80012280
    if (ctx->r10 != 0) {
        // 0x80012258: nop
    
            goto L_80012280;
    }
    // 0x80012258: nop

    // 0x8001225C: jal         0x80011F4C
    // 0x80012260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_NoteDisable(rdram, ctx);
        goto after_15;
    // 0x80012260: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80012264: jal         0x80012C40
    // 0x80012268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_AudioListRemove(rdram, ctx);
        goto after_16;
    // 0x80012268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x8001226C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80012270: jal         0x800145BC
    // 0x80012274: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_17;
    // 0x80012274: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_17:
    // 0x80012278: b           L_800123DC
    // 0x8001227C: nop

        goto L_800123DC;
    // 0x8001227C: nop

L_80012280:
    // 0x80012280: jal         0x80013B90
    // 0x80012284: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    Audio_AdsrUpdate(rdram, ctx);
        goto after_18;
    // 0x80012284: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    after_18:
    // 0x80012288: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001228C: jal         0x80013A18
    // 0x80012290: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Audio_NoteVibratoUpdate(rdram, ctx);
        goto after_19;
    // 0x80012290: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80012294: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80012298: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001229C: beq         $v0, $at, L_800122A8
    if (ctx->r2 == ctx->r1) {
        // 0x800122A0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800122A8;
    }
    // 0x800122A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800122A4: bne         $v0, $at, L_800122F0
    if (ctx->r2 != ctx->r1) {
        // 0x800122A8: addiu       $v0, $s0, 0x1C
        ctx->r2 = ADD32(ctx->r16, 0X1C);
            goto L_800122F0;
    }
L_800122A8:
    // 0x800122A8: addiu       $v0, $s0, 0x1C
    ctx->r2 = ADD32(ctx->r16, 0X1C);
    // 0x800122AC: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800122B0: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x800122B4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800122B8: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x800122BC: lbu         $t3, 0x2($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X2);
    // 0x800122C0: sb          $t3, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r11;
    // 0x800122C4: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800122C8: sb          $t4, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r12;
    // 0x800122CC: lbu         $at, 0x3($v0)
    ctx->r1 = MEM_BU(ctx->r2, 0X3);
    // 0x800122D0: sb          $at, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r1;
    // 0x800122D4: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800122D8: sb          $t8, 0x71($sp)
    MEM_B(0X71, ctx->r29) = ctx->r24;
    // 0x800122DC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800122E0: sll         $t9, $v1, 11
    ctx->r25 = S32(ctx->r3 << 11);
    // 0x800122E4: srl         $t0, $t9, 29
    ctx->r8 = S32(U32(ctx->r25) >> 29);
    // 0x800122E8: b           L_8001237C
    // 0x800122EC: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
        goto L_8001237C;
    // 0x800122EC: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
L_800122F0:
    // 0x800122F0: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x800122F4: lwc1        $f10, 0x30($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X30);
    // 0x800122F8: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800122FC: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x80012300: lwc1        $f16, 0x2C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X2C);
    // 0x80012304: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    // 0x80012308: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x8001230C: lbu         $t6, 0x7($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X7);
    // 0x80012310: sb          $t6, 0x72($sp)
    MEM_B(0X72, ctx->r29) = ctx->r14;
    // 0x80012314: lw          $t5, 0x14($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X14);
    // 0x80012318: lbu         $at, 0x1($t5)
    ctx->r1 = MEM_BU(ctx->r13, 0X1);
    // 0x8001231C: sb          $at, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r1;
    // 0x80012320: lw          $t0, 0x14($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14);
    // 0x80012324: lw          $t1, 0x4C($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4C);
    // 0x80012328: lbu         $t2, 0x4($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X4);
    // 0x8001232C: sb          $t2, 0x70($sp)
    MEM_B(0X70, ctx->r29) = ctx->r10;
    // 0x80012330: lw          $t3, 0x14($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X14);
    // 0x80012334: lw          $t4, 0x4C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4C);
    // 0x80012338: lbu         $t6, 0xB($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0XB);
    // 0x8001233C: sb          $t6, 0x71($sp)
    MEM_B(0X71, ctx->r29) = ctx->r14;
    // 0x80012340: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80012344: lw          $a0, 0x4C($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4C);
    // 0x80012348: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x8001234C: lbu         $t7, 0x8($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X8);
    // 0x80012350: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80012354: andi        $v1, $t7, 0x7
    ctx->r3 = ctx->r15 & 0X7;
    // 0x80012358: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x8001235C: bgezl       $t2, L_80012380
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80012360: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80012380;
    }
    goto skip_11;
    // 0x80012360: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_11:
    // 0x80012364: lbu         $t3, 0x3($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X3);
    // 0x80012368: andi        $t4, $t3, 0x8
    ctx->r12 = ctx->r11 & 0X8;
    // 0x8001236C: beql        $t4, $zero, L_80012380
    if (ctx->r12 == 0) {
        // 0x80012370: lwc1        $f18, 0xC($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80012380;
    }
    goto skip_12;
    // 0x80012370: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    skip_12:
    // 0x80012374: swc1        $f22, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f22.u32l;
    // 0x80012378: swc1        $f22, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f22.u32l;
L_8001237C:
    // 0x8001237C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
L_80012380:
    // 0x80012380: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80012384: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80012388: lwc1        $f16, 0x14($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8001238C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80012390: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80012394: sb          $v1, 0x6F($sp)
    MEM_B(0X6F, ctx->r29) = ctx->r3;
    // 0x80012398: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001239C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x800123A0: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800123A4: nop

    // 0x800123A8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800123AC: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x800123B0: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800123B4: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800123B8: jal         0x80011890
    // 0x800123BC: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    Audio_InitNoteSub(rdram, ctx);
        goto after_20;
    // 0x800123BC: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    after_20:
    // 0x800123C0: lbu         $t6, 0x6F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X6F);
    // 0x800123C4: lbu         $t5, 0x1($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X1);
    // 0x800123C8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800123CC: andi        $t7, $t8, 0x1C
    ctx->r15 = ctx->r24 & 0X1C;
    // 0x800123D0: andi        $t9, $t5, 0xFFE3
    ctx->r25 = ctx->r13 & 0XFFE3;
    // 0x800123D4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x800123D8: sb          $t0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r8;
L_800123DC:
    // 0x800123DC: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800123E0: lw          $v1, 0x5CA0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5CA0);
    // 0x800123E4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800123E8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800123EC: sll         $v0, $v0, 6
    ctx->r2 = S32(ctx->r2 << 6);
L_800123F0:
    // 0x800123F0: addiu       $s3, $s3, 0xC0
    ctx->r19 = ADD32(ctx->r19, 0XC0);
    // 0x800123F4: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800123F8: bne         $at, $zero, L_80012008
    if (ctx->r1 != 0) {
        // 0x800123FC: nop
    
            goto L_80012008;
    }
    // 0x800123FC: nop

L_80012400:
    // 0x80012400: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80012404: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80012408: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001240C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80012410: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80012414: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80012418: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8001241C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80012420: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80012424: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80012428: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8001242C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80012430: jr          $ra
    // 0x80012434: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80012434: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Effect_PinkExplosion_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800783C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800783C4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800783C8: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x800783CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800783D0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800783D4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800783D8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800783DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800783E0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800783E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800783E8: lh          $t8, 0x44($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X44);
    // 0x800783EC: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800783F0: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x800783F4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800783F8: jal         0x8005980C
    // 0x800783FC: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x800783FC: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x80078400: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80078404: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078408: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8007840C: lui         $t3, 0x200
    ctx->r11 = S32(0X200 << 16);
    // 0x80078410: addiu       $t3, $t3, 0x6F50
    ctx->r11 = ADD32(ctx->r11, 0X6F50);
    // 0x80078414: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80078418: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8007841C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80078420: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80078424: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80078428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007842C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078430: jr          $ra
    // 0x80078434: nop

    return;
    // 0x80078434: nop

;}
RECOMP_FUNC void HUD_RadarMark_Katt_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089B94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80089B98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80089B9C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80089BA0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089BA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80089BA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089BAC: jal         0x800B8DD0
    // 0x80089BB0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80089BB0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x80089BB4: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80089BB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80089BBC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80089BC0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089BC4: lui         $t8, 0xFF5C
    ctx->r24 = S32(0XFF5C << 16);
    // 0x80089BC8: ori         $t8, $t8, 0x5CFF
    ctx->r24 = ctx->r24 | 0X5CFF;
    // 0x80089BCC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80089BD0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80089BD4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80089BD8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80089BDC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80089BE0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80089BE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80089BE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089BEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089BF0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80089BF4: jal         0x80005C34
    // 0x80089BF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80089BF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80089BFC: jal         0x80006EB8
    // 0x80089C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80089C00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80089C04: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089C08: lui         $t2, 0xD01
    ctx->r10 = S32(0XD01 << 16);
    // 0x80089C0C: addiu       $t2, $t2, -0x6750
    ctx->r10 = ADD32(ctx->r10, -0X6750);
    // 0x80089C10: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x80089C14: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80089C18: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80089C1C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80089C20: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80089C24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80089C28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089C2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089C30: jr          $ra
    // 0x80089C34: nop

    return;
    // 0x80089C34: nop

;}
RECOMP_FUNC void func_versus_800BD1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD1FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD200: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800BD204: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD208: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800BD20C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD210: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x800BD214: addiu       $a1, $a1, 0x3E10
    ctx->r5 = ADD32(ctx->r5, 0X3E10);
    // 0x800BD218: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD21C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800BD220: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800BD224: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800BD228: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x800BD22C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800BD230: jal         0x8009D994
    // 0x800BD234: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x800BD234: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800BD23C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800BD240: jr          $ra
    // 0x800BD244: nop

    return;
    // 0x800BD244: nop

;}
RECOMP_FUNC void Effect_EnemyShot_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007FE88: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8007FE8C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8007FE90: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007FE94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007FE98: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007FE9C: lhu         $t6, 0x50($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X50);
    // 0x8007FEA0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8007FEA4: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    // 0x8007FEA8: bne         $t6, $zero, L_8007FEC0
    if (ctx->r14 != 0) {
        // 0x8007FEAC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8007FEC0;
    }
    // 0x8007FEAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007FEB0: jal         0x80060FBC
    // 0x8007FEB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007FEB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8007FEB8: b           L_800802A8
    // 0x8007FEBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800802A8;
    // 0x8007FEBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007FEC0:
    // 0x8007FEC0: jal         0x8007FD84
    // 0x8007FEC4: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    Effect_CheckTeamCollision(rdram, ctx);
        goto after_1;
    // 0x8007FEC4: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8007FEC8: beq         $v0, $zero, L_8007FEE4
    if (ctx->r2 == 0) {
        // 0x8007FECC: lwc1        $f12, 0x38($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
            goto L_8007FEE4;
    }
    // 0x8007FECC: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007FED0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007FED4: jal         0x80060FBC
    // 0x8007FED8: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x8007FED8: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_2:
    // 0x8007FEDC: b           L_800802A8
    // 0x8007FEE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800802A8;
    // 0x8007FEE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007FEE4:
    // 0x8007FEE4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8007FEE8: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x8007FEEC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8007FEF0: lw          $v0, 0x280($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X280);
    // 0x8007FEF4: beql        $v0, $zero, L_8007FF08
    if (ctx->r2 == 0) {
        // 0x8007FEF8: lwc1        $f4, 0x138($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
            goto L_8007FF08;
    }
    goto skip_0;
    // 0x8007FEF8: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    skip_0:
    // 0x8007FEFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8007FF00: nop

    // 0x8007FF04: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
L_8007FF08:
    // 0x8007FF08: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8007FF0C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8007FF10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007FF14: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007FF18: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8007FF1C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007FF20: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8007FF24: nop

    // 0x8007FF28: bc1f        L_80080150
    if (!c1cs) {
        // 0x8007FF2C: nop
    
            goto L_80080150;
    }
    // 0x8007FF2C: nop

    // 0x8007FF30: lwc1        $f16, 0x74($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8007FF34: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007FF38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007FF3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007FF40: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8007FF44: add.s       $f2, $f4, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8007FF48: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007FF4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007FF50: nop

    // 0x8007FF54: bc1f        L_80080150
    if (!c1cs) {
        // 0x8007FF58: nop
    
            goto L_80080150;
    }
    // 0x8007FF58: nop

    // 0x8007FF5C: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8007FF60: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007FF64: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8007FF68: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007FF6C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007FF70: nop

    // 0x8007FF74: bc1f        L_80080150
    if (!c1cs) {
        // 0x8007FF78: nop
    
            goto L_80080150;
    }
    // 0x8007FF78: nop

    // 0x8007FF7C: bne         $v0, $zero, L_8007FF90
    if (ctx->r2 != 0) {
        // 0x8007FF80: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_8007FF90;
    }
    // 0x8007FF80: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8007FF84: lw          $t7, 0x27C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X27C);
    // 0x8007FF88: beq         $t7, $zero, L_80080088
    if (ctx->r15 == 0) {
        // 0x8007FF8C: nop
    
            goto L_80080088;
    }
    // 0x8007FF8C: nop

L_8007FF90:
    // 0x8007FF90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007FF94: jal         0x80004EB0
    // 0x8007FF98: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8007FF98: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    after_3:
    // 0x8007FF9C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007FFA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007FFA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FFA8: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8007FFAC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8007FFB0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8007FFB4: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8007FFB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007FFBC: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8007FFC0: lwc1        $f6, 0x74CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X74CC);
    // 0x8007FFC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007FFC8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8007FFCC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8007FFD0: jal         0x80005E90
    // 0x8007FFD4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8007FFD4: nop

    after_4:
    // 0x8007FFD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007FFDC: lwc1        $f16, 0x74D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74D0);
    // 0x8007FFE0: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8007FFE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007FFE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007FFEC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007FFF0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8007FFF4: jal         0x80005D44
    // 0x8007FFF8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8007FFF8: nop

    after_5:
    // 0x8007FFFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80080000: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80080004: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80080008: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8008000C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80080010: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80080014: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80080018: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8008001C: jal         0x80006970
    // 0x80080020: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x80080020: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80080024: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80080028: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8008002C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80080030: swc1        $f6, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f6.u32l;
    // 0x80080034: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80080038: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8008003C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80080040: swc1        $f8, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f8.u32l;
    // 0x80080044: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80080048: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8008004C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80080050: swc1        $f10, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f10.u32l;
    // 0x80080054: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80080058: ori         $a0, $a0, 0x7011
    ctx->r4 = ctx->r4 | 0X7011;
    // 0x8008005C: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    // 0x80080060: lw          $t8, 0x2C4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C4);
    // 0x80080064: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80080068: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8008006C: sw          $t9, 0x2C4($s0)
    MEM_W(0X2C4, ctx->r16) = ctx->r25;
    // 0x80080070: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80080074: jal         0x80019218
    // 0x80080078: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x80080078: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_7:
    // 0x8008007C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80080080: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80080084: lw          $v0, 0x280($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X280);
L_80080088:
    // 0x80080088: bne         $v0, $zero, L_80080150
    if (ctx->r2 != 0) {
        // 0x8008008C: nop
    
            goto L_80080150;
    }
    // 0x8008008C: nop

    // 0x80080090: lw          $t1, 0x498($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X498);
    // 0x80080094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80080098: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008009C: bne         $t1, $zero, L_80080150
    if (ctx->r9 != 0) {
        // 0x800800A0: addiu       $t2, $s1, 0x80
        ctx->r10 = ADD32(ctx->r17, 0X80);
            goto L_80080150;
    }
    // 0x800800A0: addiu       $t2, $s1, 0x80
    ctx->r10 = ADD32(ctx->r17, 0X80);
    // 0x800800A4: lbu         $a2, 0x34($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X34);
    // 0x800800A8: jal         0x800A6CD0
    // 0x800800AC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    Player_ApplyDamage(rdram, ctx);
        goto after_8;
    // 0x800800AC: sw          $t2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r10;
    after_8:
    // 0x800800B0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800800B4: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x800800B8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800800BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800800C0: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x800800C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800800C8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800800CC: swc1        $f0, 0xD8($t3)
    MEM_W(0XD8, ctx->r11) = ctx->f0.u32l;
    // 0x800800D0: lwc1        $f16, 0x54($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800800D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800800D8: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800800DC: nop

    // 0x800800E0: bc1f        L_80080100
    if (!c1cs) {
        // 0x800800E4: nop
    
            goto L_80080100;
    }
    // 0x800800E4: nop

    // 0x800800E8: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x800800EC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800800F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800800F4: lwc1        $f4, 0xD8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x800800F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800800FC: swc1        $f8, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f8.u32l;
L_80080100:
    // 0x80080100: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x80080104: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80080108: beq         $t4, $at, L_80080148
    if (ctx->r12 == ctx->r1) {
        // 0x8008010C: nop
    
            goto L_80080148;
    }
    // 0x8008010C: nop

    // 0x80080110: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80080114: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80080118: swc1        $f0, 0xDC($t5)
    MEM_W(0XDC, ctx->r13) = ctx->f0.u32l;
    // 0x8008011C: lwc1        $f10, 0x58($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80080120: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80080124: nop

    // 0x80080128: bc1f        L_80080148
    if (!c1cs) {
        // 0x8008012C: nop
    
            goto L_80080148;
    }
    // 0x8008012C: nop

    // 0x80080130: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x80080134: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80080138: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008013C: lwc1        $f18, 0xDC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80080140: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80080144: swc1        $f6, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f6.u32l;
L_80080148:
    // 0x80080148: jal         0x80060FBC
    // 0x8008014C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Object_Kill(rdram, ctx);
        goto after_9;
    // 0x8008014C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_9:
L_80080150:
    // 0x80080150: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80080154: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x80080158: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008015C: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80080160: bne         $t6, $at, L_800801A0
    if (ctx->r14 != ctx->r1) {
        // 0x80080164: lui         $s0, 0x8017
        ctx->r16 = S32(0X8017 << 16);
            goto L_800801A0;
    }
    // 0x80080164: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80080168: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8008016C: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80080170: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80080174: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80080178: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8008017C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80080180: jal         0x801B6AEC
    // 0x80080184: nop

    Ground_801B6AEC(rdram, ctx);
        goto after_10;
    // 0x80080184: nop

    after_10:
    // 0x80080188: beq         $v0, $zero, L_800801F4
    if (ctx->r2 == 0) {
        // 0x8008018C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800801F4;
    }
    // 0x8008018C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80080190: jal         0x80060FBC
    // 0x80080194: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_11;
    // 0x80080194: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_11:
    // 0x80080198: b           L_800801F8
    // 0x8008019C: lwc1        $f6, 0x54($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
        goto L_800801F8;
    // 0x8008019C: lwc1        $f6, 0x54($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
L_800801A0:
    // 0x800801A0: addiu       $s0, $s0, 0x7940
    ctx->r16 = ADD32(ctx->r16, 0X7940);
    // 0x800801A4: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800801A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800801AC: c.lt.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl < ctx->f18.fl;
    // 0x800801B0: nop

    // 0x800801B4: bc1fl       L_800801F8
    if (!c1cs) {
        // 0x800801B8: lwc1        $f6, 0x54($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
            goto L_800801F8;
    }
    goto skip_1;
    // 0x800801B8: lwc1        $f6, 0x54($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
    skip_1:
    // 0x800801BC: jal         0x80060FBC
    // 0x800801C0: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x800801C0: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    after_12:
    // 0x800801C4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800801C8: lw          $t7, 0x1A88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A88);
    // 0x800801CC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800801D0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800801D4: beql        $t7, $at, L_800801F8
    if (ctx->r15 == ctx->r1) {
        // 0x800801D8: lwc1        $f6, 0x54($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
            goto L_800801F8;
    }
    goto skip_2;
    // 0x800801D8: lwc1        $f6, 0x54($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
    skip_2:
    // 0x800801DC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800801E0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800801E4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x800801E8: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    // 0x800801EC: jal         0x8007D074
    // 0x800801F0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    Effect_FireSmoke2_Spawn2(rdram, ctx);
        goto after_13;
    // 0x800801F0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    after_13:
L_800801F4:
    // 0x800801F4: lwc1        $f6, 0x54($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X54);
L_800801F8:
    // 0x800801F8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800801FC: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x80080200: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x80080204: lwc1        $f8, 0x58($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X58);
    // 0x80080208: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8008020C: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x80080210: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x80080214: lwc1        $f10, 0x5C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x80080218: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8008021C: beq         $t8, $at, L_8008026C
    if (ctx->r24 == ctx->r1) {
        // 0x80080220: swc1        $f10, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
            goto L_8008026C;
    }
    // 0x80080220: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x80080224: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x80080228: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x8008022C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80080230: jal         0x8006351C
    // 0x80080234: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    Object_CheckCollision(rdram, ctx);
        goto after_14;
    // 0x80080234: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_14:
    // 0x80080238: beq         $v0, $zero, L_800802A4
    if (ctx->r2 == 0) {
        // 0x8008023C: lui         $a3, 0x4000
        ctx->r7 = S32(0X4000 << 16);
            goto L_800802A4;
    }
    // 0x8008023C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80080240: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80080244: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80080248: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8008024C: addiu       $t9, $s1, 0x80
    ctx->r25 = ADD32(ctx->r17, 0X80);
    // 0x80080250: jal         0x8007D10C
    // 0x80080254: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_15;
    // 0x80080254: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    after_15:
    // 0x80080258: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008025C: jal         0x80060FBC
    // 0x80080260: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Object_Kill(rdram, ctx);
        goto after_16;
    // 0x80080260: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_16:
    // 0x80080264: b           L_800802A8
    // 0x80080268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800802A8;
    // 0x80080268: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8008026C:
    // 0x8008026C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80080270: jal         0x801A55D4
    // 0x80080274: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Macbeth_801A55D4(rdram, ctx);
        goto after_17;
    // 0x80080274: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x80080278: beq         $v0, $zero, L_800802A4
    if (ctx->r2 == 0) {
        // 0x8008027C: lui         $a3, 0x4000
        ctx->r7 = S32(0X4000 << 16);
            goto L_800802A4;
    }
    // 0x8008027C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80080280: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80080284: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80080288: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8008028C: addiu       $t0, $s1, 0x80
    ctx->r8 = ADD32(ctx->r17, 0X80);
    // 0x80080290: jal         0x8007D10C
    // 0x80080294: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_18;
    // 0x80080294: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_18:
    // 0x80080298: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008029C: jal         0x80060FBC
    // 0x800802A0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Object_Kill(rdram, ctx);
        goto after_19;
    // 0x800802A0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_19:
L_800802A4:
    // 0x800802A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800802A8:
    // 0x800802A8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800802AC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800802B0: jr          $ra
    // 0x800802B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800802B4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Player_UpdateTankCamOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043468: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8004346C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80043470: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80043474: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80043478: lwc1        $f0, 0xAC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XAC);
    // 0x8004347C: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80043480: lwc1        $f8, 0x148($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X148);
    // 0x80043484: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80043488: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8004348C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043490: lwc1        $f2, 0xE8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80043494: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80043498: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004349C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800434A0: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800434A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800434A8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800434AC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800434B0: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800434B4: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800434B8: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800434BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800434C0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800434C4: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800434C8: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800434CC: sub.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800434D0: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800434D4: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800434D8: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800434DC: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800434E0: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800434E4: lw          $t6, 0x1D4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1D4);
    // 0x800434E8: beql        $t6, $zero, L_80043650
    if (ctx->r14 == 0) {
        // 0x800434EC: lwc1        $f14, 0x78($s0)
        ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
            goto L_80043650;
    }
    goto skip_0;
    // 0x800434EC: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    skip_0:
    // 0x800434F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800434F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800434F8: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800434FC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80043500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043504: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80043508: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004350C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80043510: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80043514: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80043518: lwc1        $f0, 0xE4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8004351C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80043520: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80043524: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x80043528: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004352C: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80043530: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80043534: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80043538: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004353C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80043540: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80043544: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80043548: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8004354C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80043550: add.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80043554: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043558: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004355C: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80043560: lwc1        $f12, 0x17C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x80043564: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80043568: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8004356C: nop

    // 0x80043570: mul.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x80043574: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x80043578: bne         $t7, $at, L_800435D4
    if (ctx->r15 != ctx->r1) {
        // 0x8004357C: add.s       $f2, $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
            goto L_800435D4;
    }
    // 0x8004357C: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80043580: lbu         $t8, -0x5E18($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X5E18);
    // 0x80043584: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80043588: bne         $t8, $at, L_800435D4
    if (ctx->r24 != ctx->r1) {
        // 0x8004358C: lui         $at, 0xC040
        ctx->r1 = S32(0XC040 << 16);
            goto L_800435D4;
    }
    // 0x8004358C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80043590: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80043594: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80043598: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004359C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800435A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800435A4: add.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800435A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800435AC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800435B0: add.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800435B4: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800435B8: lwc1        $f6, 0x55F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55F4);
    // 0x800435BC: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800435C0: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800435C4: nop

    // 0x800435C8: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800435CC: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800435D0: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
L_800435D4:
    // 0x800435D4: lbu         $v0, -0x5E18($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X5E18);
    // 0x800435D8: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x800435DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800435E0: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x800435E4: bne         $v0, $at, L_8004362C
    if (ctx->r2 != ctx->r1) {
        // 0x800435E8: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_8004362C;
    }
    // 0x800435E8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800435EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800435F0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800435F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800435F8: add.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800435FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043600: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80043604: add.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x80043608: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8004360C: lwc1        $f6, 0x55F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X55F8);
    // 0x80043610: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80043614: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x80043618: nop

    // 0x8004361C: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80043620: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80043624: b           L_800436A8
    // 0x80043628: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
        goto L_800436A8;
    // 0x80043628: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
L_8004362C:
    // 0x8004362C: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x80043630: bnel        $v0, $at, L_800436AC
    if (ctx->r2 != ctx->r1) {
        // 0x80043634: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_800436AC;
    }
    goto skip_1;
    // 0x80043634: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    skip_1:
    // 0x80043638: mul.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8004363C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80043640: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80043644: b           L_800436A8
    // 0x80043648: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
        goto L_800436A8;
    // 0x80043648: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8004364C: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
L_80043650:
    // 0x80043650: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043654: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x80043658: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8004365C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80043660: bne         $t9, $at, L_80043688
    if (ctx->r25 != ctx->r1) {
        // 0x80043664: add.s       $f16, $f14, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f6.fl;
            goto L_80043688;
    }
    // 0x80043664: add.s       $f16, $f14, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80043668: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8004366C: lbu         $t0, -0x5E18($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X5E18);
    // 0x80043670: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80043674: bne         $t0, $at, L_80043688
    if (ctx->r8 != ctx->r1) {
        // 0x80043678: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_80043688;
    }
    // 0x80043678: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8004367C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80043680: nop

    // 0x80043684: add.s       $f2, $f14, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f4.fl;
L_80043688:
    // 0x80043688: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8004368C: lbu         $t1, -0x5E18($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X5E18);
    // 0x80043690: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x80043694: bne         $t1, $at, L_800436A8
    if (ctx->r9 != ctx->r1) {
        // 0x80043698: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_800436A8;
    }
    // 0x80043698: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8004369C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800436A0: nop

    // 0x800436A4: add.s       $f2, $f14, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f8.fl;
L_800436A8:
    // 0x800436A8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
L_800436AC:
    // 0x800436AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800436B0: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800436B4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800436B8: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x800436BC: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x800436C0: nop

    // 0x800436C4: bc1fl       L_80043718
    if (!c1cs) {
        // 0x800436C8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80043718;
    }
    goto skip_2;
    // 0x800436C8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_2:
    // 0x800436CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800436D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800436D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800436D8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800436DC: sub.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800436E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800436E4: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800436E8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800436EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800436F0: lwc1        $f8, 0x55FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X55FC);
    // 0x800436F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800436F8: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x800436FC: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x80043700: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80043704: jal         0x8009BC2C
    // 0x80043708: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80043708: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8004370C: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80043710: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80043714: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_80043718:
    // 0x80043718: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004371C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80043720: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043724: lwc1        $f8, 0x5600($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5600);
    // 0x80043728: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8004372C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80043730: addiu       $t2, $s0, 0x50
    ctx->r10 = ADD32(ctx->r16, 0X50);
    // 0x80043734: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x80043738: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004373C: swc1        $f16, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f16.u32l;
    // 0x80043740: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x80043744: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80043748: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x8004374C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80043750: jal         0x8009BC2C
    // 0x80043754: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80043754: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80043758: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8004375C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043760: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80043764: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80043768: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004376C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80043770: lwc1        $f8, 0x5604($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5604);
    // 0x80043774: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80043778: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004377C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80043780: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x80043784: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80043788: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8004378C: jal         0x8009BC2C
    // 0x80043790: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80043790: nop

    after_2:
    // 0x80043794: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80043798: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004379C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800437A0: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800437A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800437A8: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800437AC: lwc1        $f8, 0x5608($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5608);
    // 0x800437B0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800437B4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800437B8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800437BC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800437C0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800437C4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800437C8: jal         0x8009BC2C
    // 0x800437CC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800437CC: nop

    after_3:
    // 0x800437D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800437D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800437D8: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800437DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800437E0: lwc1        $f8, 0x560C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X560C);
    // 0x800437E4: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800437E8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800437EC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800437F0: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x800437F4: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800437F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800437FC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80043800: jal         0x8009BC2C
    // 0x80043804: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80043804: nop

    after_4:
    // 0x80043808: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004380C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043810: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80043814: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80043818: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8004381C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80043820: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80043824: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80043828: lui         $a1, 0x4348
    ctx->r5 = S32(0X4348 << 16);
    // 0x8004382C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80043830: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80043834: jal         0x8009BC2C
    // 0x80043838: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80043838: nop

    after_5:
    // 0x8004383C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80043840: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043844: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80043848: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004384C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x80043850: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80043854: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x80043858: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8004385C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80043860: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80043864: jal         0x8009BC2C
    // 0x80043868: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80043868: nop

    after_6:
    // 0x8004386C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80043870: lwc1        $f6, 0x5610($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5610);
    // 0x80043874: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80043878: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004387C: lwc1        $f8, 0x5614($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5614);
    // 0x80043880: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80043884: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80043888: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8004388C: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x80043890: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80043894: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80043898: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004389C: jal         0x8009BC2C
    // 0x800438A0: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800438A0: nop

    after_7:
    // 0x800438A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800438A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800438AC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800438B0: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x800438B4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800438B8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800438BC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800438C0: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800438C4: jal         0x8009BC2C
    // 0x800438C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800438C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x800438CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800438D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800438D4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800438D8: jr          $ra
    // 0x800438DC: nop

    return;
    // 0x800438DC: nop

;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021170: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80021174: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80021178: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8002117C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80021180: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80021184: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80021188: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002118C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80021190: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x80021194: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80021198: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8002119C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800211A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800211A4: jal         0x80020F40
    // 0x800211A8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x800211A8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800211AC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800211B0: jal         0x80026CD0
    // 0x800211B4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800211B4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x800211B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800211BC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800211C0: jr          $ra
    // 0x800211C4: nop

    return;
    // 0x800211C4: nop

;}
RECOMP_FUNC void Effect_SmallRock_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800788B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800788B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800788B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800788BC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800788C0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800788C4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800788C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800788CC: beq         $v0, $at, L_800788E4
    if (ctx->r2 == ctx->r1) {
        // 0x800788D0: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800788E4;
    }
    // 0x800788D0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800788D4: beq         $v0, $at, L_8007893C
    if (ctx->r2 == ctx->r1) {
        // 0x800788D8: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8007893C;
    }
    // 0x800788D8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800788DC: b           L_80078A54
    // 0x800788E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80078A54;
    // 0x800788E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800788E4:
    // 0x800788E4: jal         0x8005980C
    // 0x800788E8: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x800788E8: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    after_0:
    // 0x800788EC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800788F0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800788F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800788F8: lui         $t8, 0x8080
    ctx->r24 = S32(0X8080 << 16);
    // 0x800788FC: ori         $t8, $t8, 0x80FF
    ctx->r24 = ctx->r24 | 0X80FF;
    // 0x80078900: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80078904: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80078908: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8007890C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80078910: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078914: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078918: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x8007891C: addiu       $t1, $t1, -0x80
    ctx->r9 = ADD32(ctx->r9, -0X80);
    // 0x80078920: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80078924: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80078928: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8007892C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80078930: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80078934: b           L_80078A54
    // 0x80078938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80078A54;
    // 0x80078938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007893C:
    // 0x8007893C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80078940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078944: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80078948: jal         0x800B8DD0
    // 0x8007894C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8007894C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80078950: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80078954: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80078958: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8007895C: lw          $t2, 0x40($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X40);
    // 0x80078960: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80078964: jal         0x80004E20
    // 0x80078968: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    Math_ModF(rdram, ctx);
        goto after_2;
    // 0x80078968: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x8007896C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80078970: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078974: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80078978: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007897C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80078980: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80078984: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80078988: lwc1        $f6, 0x6C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x8007898C: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x80078990: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80078994: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80078998: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8007899C: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800789A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800789A4: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800789A8: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800789AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800789B0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800789B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800789B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800789BC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800789C0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800789C4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800789C8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800789CC: addiu       $t6, $t6, 0x173C
    ctx->r14 = ADD32(ctx->r14, 0X173C);
    // 0x800789D0: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x800789D4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800789D8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800789DC: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800789E0: nop

    // 0x800789E4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800789E8: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x800789EC: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800789F0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800789F4: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x800789F8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800789FC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80078A00: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x80078A04: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x80078A08: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80078A0C: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80078A10: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80078A14: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x80078A18: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80078A1C: jal         0x8005980C
    // 0x80078A20: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_3;
    // 0x80078A20: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    after_3:
    // 0x80078A24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078A28: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x80078A2C: addiu       $t9, $t9, 0x4AC0
    ctx->r25 = ADD32(ctx->r25, 0X4AC0);
    // 0x80078A30: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80078A34: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80078A38: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80078A3C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80078A40: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80078A44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078A48: jal         0x800B8DD0
    // 0x80078A4C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80078A4C: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x80078A50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80078A54:
    // 0x80078A54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80078A58: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80078A5C: jr          $ra
    // 0x80078A60: nop

    return;
    // 0x80078A60: nop

;}
RECOMP_FUNC void Effect_FireSmoke2_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CCBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007CCC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CCC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CCC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007CCCC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007CCD0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007CCD4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007CCD8: jal         0x80061474
    // 0x8007CCDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007CCDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007CCE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007CCE4: addiu       $t7, $zero, 0x154
    ctx->r15 = ADD32(0, 0X154);
    // 0x8007CCE8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007CCEC: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007CCF0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007CCF4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007CCF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007CCFC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007CD00: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007CD04: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007CD08: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007CD0C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007CD10: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007CD14: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    // 0x8007CD18: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x8007CD1C: lwc1        $f16, 0x742C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X742C);
    // 0x8007CD20: jal         0x80004EB0
    // 0x8007CD24: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007CD24: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x8007CD28: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007CD2C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007CD30: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007CD34: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8007CD38: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8007CD3C: jal         0x800612B8
    // 0x8007CD40: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8007CD40: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8007CD44: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8007CD48: lbu         $t9, 0x7C98($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X7C98);
    // 0x8007CD4C: addiu       $t0, $zero, 0xE6
    ctx->r8 = ADD32(0, 0XE6);
    // 0x8007CD50: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8007CD54: bnel        $t9, $zero, L_8007CD68
    if (ctx->r25 != 0) {
        // 0x8007CD58: sh          $t1, 0x44($s0)
        MEM_H(0X44, ctx->r16) = ctx->r9;
            goto L_8007CD68;
    }
    goto skip_0;
    // 0x8007CD58: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
    skip_0:
    // 0x8007CD5C: b           L_8007CD68
    // 0x8007CD60: sh          $t0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r8;
        goto L_8007CD68;
    // 0x8007CD60: sh          $t0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r8;
    // 0x8007CD64: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
L_8007CD68:
    // 0x8007CD68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CD6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007CD70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007CD74: jr          $ra
    // 0x8007CD78: nop

    return;
    // 0x8007CD78: nop

;}
