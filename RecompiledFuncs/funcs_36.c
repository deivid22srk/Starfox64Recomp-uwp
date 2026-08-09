#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Zoness_Effect394_Spawn3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193C5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80193C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80193C64: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80193C68: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80193C6C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80193C70: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80193C74: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80193C78: addiu       $a0, $a0, 0x2CF0
    ctx->r4 = ADD32(ctx->r4, 0X2CF0);
    // 0x80193C7C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80193C80:
    // 0x80193C80: bnel        $t6, $zero, L_80193CAC
    if (ctx->r14 != 0) {
        // 0x80193C84: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80193CAC;
    }
    goto skip_0;
    // 0x80193C84: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x80193C88: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80193C8C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80193C90: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80193C94: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80193C98: jal         0x80193B08
    // 0x80193C9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Zoness_Effect394_Setup3(rdram, ctx);
        goto after_0;
    // 0x80193C9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80193CA0: b           L_80193CBC
    // 0x80193CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80193CBC;
    // 0x80193CA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193CA8: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80193CAC:
    // 0x80193CAC: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80193CB0: beql        $at, $zero, L_80193C80
    if (ctx->r1 == 0) {
        // 0x80193CB4: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80193C80;
    }
    goto skip_1;
    // 0x80193CB4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80193CB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80193CBC:
    // 0x80193CBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80193CC0: jr          $ra
    // 0x80193CC4: nop

    return;
    // 0x80193CC4: nop

;}
RECOMP_FUNC void Aquas_801A92EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A92EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801A92F0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x801A92F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801A92F8: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x801A92FC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801A9300: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A9304: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801A9308: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801A930C: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x801A9310: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A9314: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x801A9318: addiu       $t8, $t8, 0x4750
    ctx->r24 = ADD32(ctx->r24, 0X4750);
    // 0x801A931C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801A9320: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x801A9324: swc1        $f4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f4.u32l;
    // 0x801A9328: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801A932C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801A9330: lwc1        $f16, 0xC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC);
    // 0x801A9334: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x801A9338: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801A933C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801A9340: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x801A9344: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801A9348: swc1        $f12, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f12.u32l;
    // 0x801A934C: swc1        $f14, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f14.u32l;
    // 0x801A9350: sb          $v1, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r3;
    // 0x801A9354: sb          $v1, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r3;
    // 0x801A9358: sb          $v1, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r3;
    // 0x801A935C: sb          $v1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r3;
    // 0x801A9360: sh          $t1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r9;
    // 0x801A9364: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x801A9368: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801A936C: jr          $ra
    // 0x801A9370: nop

    return;
    // 0x801A9370: nop

;}
RECOMP_FUNC void Zoness_ZoShrimp_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192C18: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80192C1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80192C20: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x80192C24: lw          $t6, 0x118($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X118);
    // 0x80192C28: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x80192C2C: addiu       $a0, $a0, 0x1ABC
    ctx->r4 = ADD32(ctx->r4, 0X1ABC);
    // 0x80192C30: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80192C34: jal         0x8009AA20
    // 0x80192C38: lh          $a1, 0xB6($t6)
    ctx->r5 = MEM_H(ctx->r14, 0XB6);
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x80192C38: lh          $a1, 0xB6($t6)
    ctx->r5 = MEM_H(ctx->r14, 0XB6);
    after_0:
    // 0x80192C3C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80192C40: lw          $t9, -0x4438($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4438);
    // 0x80192C44: lw          $t8, 0x118($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X118);
    // 0x80192C48: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80192C4C: addiu       $t7, $t7, 0x26F4
    ctx->r15 = ADD32(ctx->r15, 0X26F4);
    // 0x80192C50: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x80192C54: addiu       $a1, $a1, 0x1B88
    ctx->r5 = ADD32(ctx->r5, 0X1B88);
    // 0x80192C58: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80192C5C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80192C60: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80192C64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80192C68: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80192C6C: jal         0x8009A72C
    // 0x80192C70: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x80192C70: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_1:
    // 0x80192C74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80192C78: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    // 0x80192C7C: jr          $ra
    // 0x80192C80: nop

    return;
    // 0x80192C80: nop

;}
RECOMP_FUNC void Zoness_ZoSupplyCrane_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C200: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8019C204: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019C208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019C20C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019C210: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8019C214: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C218: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x8019C21C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019C220: swc1        $f4, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f4.u32l;
    // 0x8019C224: beq         $t6, $at, L_8019C270
    if (ctx->r14 == ctx->r1) {
        // 0x8019C228: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8019C270;
    }
    // 0x8019C228: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019C22C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019C230: jal         0x80004E20
    // 0x8019C234: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    Math_ModF(rdram, ctx);
        goto after_0;
    // 0x8019C234: lwc1        $f12, 0x18($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18);
    after_0:
    // 0x8019C238: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019C23C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C240: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019C244: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019C248: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8019C24C: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019C250: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8019C254: nop

    // 0x8019C258: sw          $t8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r24;
    // 0x8019C25C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019C260: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8019C264: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x8019C268: b           L_8019C27C
    // 0x8019C26C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
        goto L_8019C27C;
    // 0x8019C26C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
L_8019C270:
    // 0x8019C270: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x8019C274: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8019C278: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
L_8019C27C:
    // 0x8019C27C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019C280: lw          $t2, 0x60($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X60);
    // 0x8019C284: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8019C288: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019C28C: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8019C290: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x8019C294: bne         $t2, $at, L_8019C2CC
    if (ctx->r10 != ctx->r1) {
        // 0x8019C298: swc1        $f18, 0x128($s0)
        MEM_W(0X128, ctx->r16) = ctx->f18.u32l;
            goto L_8019C2CC;
    }
    // 0x8019C298: swc1        $f18, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f18.u32l;
    // 0x8019C29C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8019C2A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C2A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019C2A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C2AC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019C2B0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8019C2B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019C2B8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019C2BC: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x8019C2C0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019C2C4: b           L_8019C2DC
    // 0x8019C2C8: swc1        $f18, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f18.u32l;
        goto L_8019C2DC;
    // 0x8019C2C8: swc1        $f18, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f18.u32l;
L_8019C2CC:
    // 0x8019C2CC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019C2D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C2D4: nop

    // 0x8019C2D8: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
L_8019C2DC:
    // 0x8019C2DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019C2E0: lwc1        $f8, 0x1278($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1278);
    // 0x8019C2E4: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019C2E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019C2EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019C2F0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019C2F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019C2F8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019C2FC: jal         0x80005FE0
    // 0x8019C300: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x8019C300: nop

    after_1:
    // 0x8019C304: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019C308: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019C30C: addiu       $a1, $a1, -0x754
    ctx->r5 = ADD32(ctx->r5, -0X754);
    // 0x8019C310: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019C314: jal         0x80006970
    // 0x8019C318: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8019C318: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_2:
    // 0x8019C31C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C320: lwc1        $f18, 0x120($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8019C324: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019C328: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
    // 0x8019C32C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019C330: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019C334: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019C338: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019C33C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019C340: swc1        $f6, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f6.u32l;
    // 0x8019C344: lwc1        $f10, 0x127C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X127C);
    // 0x8019C348: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019C34C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019C350: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019C354: jal         0x80005E90
    // 0x8019C358: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8019C358: nop

    after_3:
    // 0x8019C35C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019C360: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019C364: addiu       $a1, $a1, -0x748
    ctx->r5 = ADD32(ctx->r5, -0X748);
    // 0x8019C368: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019C36C: jal         0x80006970
    // 0x8019C370: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8019C370: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x8019C374: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8019C378: addiu       $a2, $a2, 0x3FE0
    ctx->r6 = ADD32(ctx->r6, 0X3FE0);
    // 0x8019C37C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019C380: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_8019C384:
    // 0x8019C384: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x8019C388: bne         $t3, $zero, L_8019C424
    if (ctx->r11 != 0) {
        // 0x8019C38C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8019C424;
    }
    // 0x8019C38C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8019C390: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8019C394: jal         0x800613C4
    // 0x8019C398: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_5;
    // 0x8019C398: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_5:
    // 0x8019C39C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8019C3A0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019C3A4: addiu       $t5, $zero, 0xFB
    ctx->r13 = ADD32(0, 0XFB);
    // 0x8019C3A8: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x8019C3AC: sh          $t5, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r13;
    // 0x8019C3B0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C3B4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019C3B8: addiu       $t7, $zero, 0x309
    ctx->r15 = ADD32(0, 0X309);
    // 0x8019C3BC: andi        $a1, $t5, 0xFFFF
    ctx->r5 = ctx->r13 & 0XFFFF;
    // 0x8019C3C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019C3C4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8019C3C8: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x8019C3CC: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019C3D0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019C3D4: lwc1        $f18, 0x11C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8019C3D8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019C3DC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019C3E0: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x8019C3E4: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019C3E8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019C3EC: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019C3F0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019C3F4: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8019C3F8: swc1        $f16, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f16.u32l;
    // 0x8019C3FC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019C400: swc1        $f4, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f4.u32l;
    // 0x8019C404: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x8019C408: sw          $t7, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->r15;
    // 0x8019C40C: jal         0x800612B8
    // 0x8019C410: sw          $t6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r14;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x8019C410: sw          $t6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r14;
    after_6:
    // 0x8019C414: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8019C418: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8019C41C: b           L_8019C430
    // 0x8019C420: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
        goto L_8019C430;
    // 0x8019C420: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
L_8019C424:
    // 0x8019C424: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8019C428: bne         $v0, $v1, L_8019C384
    if (ctx->r2 != ctx->r3) {
        // 0x8019C42C: addiu       $a2, $a2, 0x2F4
        ctx->r6 = ADD32(ctx->r6, 0X2F4);
            goto L_8019C384;
    }
    // 0x8019C42C: addiu       $a2, $a2, 0x2F4
    ctx->r6 = ADD32(ctx->r6, 0X2F4);
L_8019C430:
    // 0x8019C430: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8019C434: bnel        $at, $zero, L_8019C444
    if (ctx->r1 != 0) {
        // 0x8019C438: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8019C444;
    }
    goto skip_0;
    // 0x8019C438: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8019C43C: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
    // 0x8019C440: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019C444:
    // 0x8019C444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8019C448: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8019C44C: jr          $ra
    // 0x8019C450: nop

    return;
    // 0x8019C450: nop

;}
RECOMP_FUNC void Solar_SoRock1_2_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019EF30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019EF34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019EF38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019EF3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019EF40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8019EF44: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8019EF48: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019EF4C: jal         0x800613C4
    // 0x8019EF50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019EF50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019EF54: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8019EF58: addiu       $t7, $zero, 0x113
    ctx->r15 = ADD32(0, 0X113);
    // 0x8019EF5C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8019EF60: jal         0x80004EB0
    // 0x8019EF64: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019EF64: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    after_1:
    // 0x8019EF68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019EF6C: lwc1        $f4, 0x150C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X150C);
    // 0x8019EF70: addiu       $t8, $zero, 0x114
    ctx->r24 = ADD32(0, 0X114);
    // 0x8019EF74: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8019EF78: nop

    // 0x8019EF7C: bc1fl       L_8019EF8C
    if (!c1cs) {
        // 0x8019EF80: lwc1        $f6, 0x2C($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
            goto L_8019EF8C;
    }
    goto skip_0;
    // 0x8019EF80: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8019EF84: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8019EF88: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
L_8019EF8C:
    // 0x8019EF8C: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8019EF90: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019EF94: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8019EF98: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019EF9C: jal         0x80004EB0
    // 0x8019EFA0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8019EFA0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8019EFA4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019EFA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019EFAC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8019EFB0: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x8019EFB4: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8019EFB8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019EFBC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8019EFC0: swc1        $f18, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f18.u32l;
    // 0x8019EFC4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019EFC8: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x8019EFCC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019EFD0: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x8019EFD4: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8019EFD8: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
    // 0x8019EFDC: sh          $t0, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r8;
    // 0x8019EFE0: jal         0x800612B8
    // 0x8019EFE4: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8019EFE4: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8019EFE8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8019EFEC: lw          $t1, -0x7D7C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D7C);
    // 0x8019EFF0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019EFF4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019EFF8: beq         $t1, $zero, L_8019F004
    if (ctx->r9 == 0) {
        // 0x8019EFFC: lui         $a0, 0x2900
        ctx->r4 = S32(0X2900 << 16);
            goto L_8019F004;
    }
    // 0x8019EFFC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8019F000: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
L_8019F004:
    // 0x8019F004: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019F008: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019F00C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019F010: ori         $a0, $a0, 0x71
    ctx->r4 = ctx->r4 | 0X71;
    // 0x8019F014: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019F018: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019F01C: jal         0x80019218
    // 0x8019F020: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8019F020: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_4:
    // 0x8019F024: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019F028: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019F02C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019F030: jr          $ra
    // 0x8019F034: nop

    return;
    // 0x8019F034: nop

;}
RECOMP_FUNC void Zoness_80193628(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193628: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8019362C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80193630: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80193634: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80193638: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019363C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80193640: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80193644: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80193648: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8019364C: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x80193650: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80193654: addiu       $t7, $t7, -0x9E0
    ctx->r15 = ADD32(ctx->r15, -0X9E0);
    // 0x80193658: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8019365C: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x80193660: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80193664: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x80193668: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8019366C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x80193670: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80193674: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80193678: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019367C: lwc1        $f6, 0xF24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XF24);
    // 0x80193680: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80193684: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80193688: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019368C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80193690: jal         0x80005E90
    // 0x80193694: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80193694: nop

    after_0:
    // 0x80193698: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019369C: lwc1        $f16, 0xF28($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XF28);
    // 0x801936A0: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801936A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801936A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801936AC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801936B0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801936B4: jal         0x80005D44
    // 0x801936B8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801936B8: nop

    after_1:
    // 0x801936BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801936C0: lwc1        $f6, 0xF2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XF2C);
    // 0x801936C4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801936C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801936CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801936D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801936D4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801936D8: jal         0x80005FE0
    // 0x801936DC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x801936DC: nop

    after_2:
    // 0x801936E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801936E4: lwc1        $f10, 0xF30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XF30);
    // 0x801936E8: lwc1        $f16, 0x74($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801936EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801936F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801936F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801936F8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801936FC: jal         0x80005E90
    // 0x80193700: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x80193700: nop

    after_3:
    // 0x80193704: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193708: lwc1        $f4, 0xF34($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XF34);
    // 0x8019370C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80193710: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80193714: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80193718: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019371C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80193720: jal         0x80005D44
    // 0x80193724: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x80193724: nop

    after_4:
    // 0x80193728: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019372C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80193730: jal         0x80006A20
    // 0x80193734: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x80193734: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_5:
    // 0x80193738: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8019373C: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80193740: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80193744: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80193748: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019374C: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80193750: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80193754: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x80193758: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8019375C: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80193760: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80193764: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80193768: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019376C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80193770: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80193774: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80193778: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8019377C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80193780: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80193784: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80193788: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019378C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80193790: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80193794: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80193798: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019379C: add.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801937A0: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x801937A4: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801937A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801937AC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801937B0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801937B4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801937B8: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x801937BC: jal         0x8007F04C
    // 0x801937C0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    Effect_SpawnById2(rdram, ctx);
        goto after_6;
    // 0x801937C0: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x801937C4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801937C8: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x801937CC: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x801937D0: jr          $ra
    // 0x801937D4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801937D4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Aquas_SpawnItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A94EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A94F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A94F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801A94F8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801A94FC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801A9500: addiu       $a2, $a2, 0x37E0
    ctx->r6 = ADD32(ctx->r6, 0X37E0);
    // 0x801A9504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801A9508: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_801A950C:
    // 0x801A950C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x801A9510: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801A9514: bne         $t6, $zero, L_801A9574
    if (ctx->r14 != 0) {
        // 0x801A9518: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801A9574;
    }
    // 0x801A9518: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A951C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801A9520: jal         0x80061444
    // 0x801A9524: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    Item_Initialize(rdram, ctx);
        goto after_0;
    // 0x801A9524: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x801A9528: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A952C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x801A9530: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A9534: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x801A9538: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x801A953C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801A9540: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801A9544: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x801A9548: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801A954C: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x801A9550: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801A9554: lwc1        $f6, 0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801A9558: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801A955C: lwc1        $f8, 0x8($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X8);
    // 0x801A9560: sh          $t9, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r25;
    // 0x801A9564: jal         0x800612B8
    // 0x801A9568: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801A9568: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x801A956C: b           L_801A9580
    // 0x801A9570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A9580;
    // 0x801A9570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A9574:
    // 0x801A9574: bne         $v0, $v1, L_801A950C
    if (ctx->r2 != ctx->r3) {
        // 0x801A9578: addiu       $a2, $a2, 0x6C
        ctx->r6 = ADD32(ctx->r6, 0X6C);
            goto L_801A950C;
    }
    // 0x801A9578: addiu       $a2, $a2, 0x6C
    ctx->r6 = ADD32(ctx->r6, 0X6C);
    // 0x801A957C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A9580:
    // 0x801A9580: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A9584: jr          $ra
    // 0x801A9588: nop

    return;
    // 0x801A9588: nop

;}
RECOMP_FUNC void Zoness_8018FF50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018FF54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018FF58: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018FF5C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8018FF60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FF64: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018FF68: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018FF6C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018FF70: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018FF74: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018FF78: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018FF7C: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018FF80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018FF84: jal         0x80005100
    // 0x8018FF88: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8018FF88: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    after_0:
    // 0x8018FF8C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018FF90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FF94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018FF98: lwc1        $f10, 0xDD0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XDD0);
    // 0x8018FF9C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018FFA0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8018FFA4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018FFA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FFAC: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018FFB0: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018FFB4: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018FFB8: swc1        $f4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f4.u32l;
    // 0x8018FFBC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8018FFC0: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8018FFC4: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8018FFC8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018FFCC: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8018FFD0: sub.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8018FFD4: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8018FFD8: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018FFDC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018FFE0: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018FFE4: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018FFE8: sub.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8018FFEC: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018FFF0: jal         0x80005100
    // 0x8018FFF4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x8018FFF4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x8018FFF8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018FFFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190000: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80190004: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190008: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019000C: lwc1        $f10, 0xDD4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XDD4);
    // 0x80190010: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80190014: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190018: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x8019001C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80190020: jr          $ra
    // 0x80190024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80190024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Solar_SoVulkain_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A71B8: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x801A71BC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801A71C0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A71C4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801A71C8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x801A71CC: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801A71D0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801A71D4: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801A71D8: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801A71DC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801A71E0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801A71E4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801A71E8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801A71EC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801A71F0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801A71F4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801A71F8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801A71FC: addiu       $t7, $t7, -0x5C0
    ctx->r15 = ADD32(ctx->r15, -0X5C0);
    // 0x801A7200: addiu       $t0, $t7, 0x6C
    ctx->r8 = ADD32(ctx->r15, 0X6C);
    // 0x801A7204: addiu       $t6, $sp, 0xE8
    ctx->r14 = ADD32(ctx->r29, 0XE8);
L_801A7208:
    // 0x801A7208: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801A720C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x801A7210: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801A7214: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x801A7218: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x801A721C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x801A7220: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x801A7224: bne         $t7, $t0, L_801A7208
    if (ctx->r15 != ctx->r8) {
        // 0x801A7228: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_801A7208;
    }
    // 0x801A7228: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x801A722C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801A7230: addiu       $t2, $t2, -0x554
    ctx->r10 = ADD32(ctx->r10, -0X554);
    // 0x801A7234: addiu       $t5, $t2, 0x24
    ctx->r13 = ADD32(ctx->r10, 0X24);
    // 0x801A7238: addiu       $t1, $sp, 0xC4
    ctx->r9 = ADD32(ctx->r29, 0XC4);
L_801A723C:
    // 0x801A723C: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x801A7240: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x801A7244: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x801A7248: sw          $at, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r1;
    // 0x801A724C: lw          $at, -0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X8);
    // 0x801A7250: sw          $at, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r1;
    // 0x801A7254: lw          $at, -0x4($t2)
    ctx->r1 = MEM_W(ctx->r10, -0X4);
    // 0x801A7258: bne         $t2, $t5, L_801A723C
    if (ctx->r10 != ctx->r13) {
        // 0x801A725C: sw          $at, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r1;
            goto L_801A723C;
    }
    // 0x801A725C: sw          $at, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r1;
    // 0x801A7260: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801A7264: addiu       $t8, $t8, -0x530
    ctx->r24 = ADD32(ctx->r24, -0X530);
    // 0x801A7268: addiu       $t6, $t8, 0x24
    ctx->r14 = ADD32(ctx->r24, 0X24);
    // 0x801A726C: addiu       $t9, $sp, 0xA0
    ctx->r25 = ADD32(ctx->r29, 0XA0);
L_801A7270:
    // 0x801A7270: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x801A7274: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x801A7278: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801A727C: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x801A7280: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x801A7284: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x801A7288: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x801A728C: bne         $t8, $t6, L_801A7270
    if (ctx->r24 != ctx->r14) {
        // 0x801A7290: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_801A7270;
    }
    // 0x801A7290: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x801A7294: lwc1        $f0, 0x3F8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X3F8);
    // 0x801A7298: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A729C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801A72A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A72A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A72A8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A72AC: jal         0x80005C34
    // 0x801A72B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x801A72B0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x801A72B4: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801A72B8: lw          $t3, -0x7D7C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D7C);
    // 0x801A72BC: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801A72C0: addiu       $a1, $a1, -0x1B90
    ctx->r5 = ADD32(ctx->r5, -0X1B90);
    // 0x801A72C4: beq         $t3, $zero, L_801A72F4
    if (ctx->r11 == 0) {
        // 0x801A72C8: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_801A72F4;
    }
    // 0x801A72C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801A72CC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x801A72D0: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x801A72D4: addiu       $t5, $t5, 0x6BDC
    ctx->r13 = ADD32(ctx->r13, 0X6BDC);
    // 0x801A72D8: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x801A72DC: addiu       $a3, $a3, 0x68A8
    ctx->r7 = ADD32(ctx->r7, 0X68A8);
    // 0x801A72E0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801A72E4: addiu       $a2, $s6, 0x1A0
    ctx->r6 = ADD32(ctx->r22, 0X1A0);
    // 0x801A72E8: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x801A72EC: jal         0x8009A72C
    // 0x801A72F0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x801A72F0: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    after_1:
L_801A72F4:
    // 0x801A72F4: lh          $t1, 0x60($s6)
    ctx->r9 = MEM_H(ctx->r22, 0X60);
    // 0x801A72F8: bgtzl       $t1, L_801A771C
    if (SIGNED(ctx->r9) > 0) {
        // 0x801A72FC: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801A771C;
    }
    goto skip_0;
    // 0x801A72FC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_0:
    // 0x801A7300: jal         0x800BA5B0
    // 0x801A7304: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_2;
    // 0x801A7304: nop

    after_2:
    // 0x801A7308: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x801A730C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x801A7310: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x801A7314: addiu       $s4, $s4, -0x4C40
    ctx->r20 = ADD32(ctx->r20, -0X4C40);
    // 0x801A7318: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A731C: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801A7320: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801A7324: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801A7328: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x801A732C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801A7330: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801A7334: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A7338: lui         $t4, 0xFFC0
    ctx->r12 = S32(0XFFC0 << 16);
    // 0x801A733C: ori         $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 | 0XFF;
    // 0x801A7340: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801A7344: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x801A7348: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x801A734C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801A7350: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801A7354: jal         0x80005740
    // 0x801A7358: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x801A7358: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_3:
    // 0x801A735C: jal         0x80005708
    // 0x801A7360: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x801A7360: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x801A7364: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801A7368: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A736C: lwc1        $f4, 0xC($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0XC);
    // 0x801A7370: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A7374: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801A7378: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A737C: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x801A7380: lw          $a2, 0x8($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X8);
    // 0x801A7384: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A7388: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A738C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A7390: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A7394: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801A7398: jal         0x80005B00
    // 0x801A739C: nop

    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x801A739C: nop

    after_5:
    // 0x801A73A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A73A4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A73A8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801A73AC: addiu       $v0, $v0, 0x2768
    ctx->r2 = ADD32(ctx->r2, 0X2768);
    // 0x801A73B0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A73B4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A73B8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801A73BC: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x801A73C0: lw          $a2, 0x8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X8);
    // 0x801A73C4: jal         0x80005C34
    // 0x801A73C8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x801A73C8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_6:
    // 0x801A73CC: jal         0x80006EB8
    // 0x801A73D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x801A73D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_7:
    // 0x801A73D4: lui         $fp, 0x600
    ctx->r30 = S32(0X600 << 16);
    // 0x801A73D8: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A73DC: lui         $s7, 0x102
    ctx->r23 = S32(0X102 << 16);
    // 0x801A73E0: addiu       $s7, $s7, 0x4AC0
    ctx->r23 = ADD32(ctx->r23, 0X4AC0);
    // 0x801A73E4: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801A73E8: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    // 0x801A73EC: sw          $s7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r23;
    // 0x801A73F0: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x801A73F4: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801A73F8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A73FC: lwc1        $f20, 0x1874($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X1874);
    // 0x801A7400: addiu       $s1, $s1, 0x2768
    ctx->r17 = ADD32(ctx->r17, 0X2768);
    // 0x801A7404: addiu       $s0, $sp, 0xE8
    ctx->r16 = ADD32(ctx->r29, 0XE8);
    // 0x801A7408: addiu       $s2, $sp, 0xC4
    ctx->r18 = ADD32(ctx->r29, 0XC4);
    // 0x801A740C: addiu       $s3, $sp, 0xA0
    ctx->r19 = ADD32(ctx->r29, 0XA0);
L_801A7410:
    // 0x801A7410: jal         0x80005740
    // 0x801A7414: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x801A7414: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x801A7418: jal         0x80005708
    // 0x801A741C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x801A741C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
    // 0x801A7420: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A7424: lwc1        $f4, 0x4($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X4);
    // 0x801A7428: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A742C: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A7430: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A7434: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801A7438: lwc1        $f18, 0xC($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0XC);
    // 0x801A743C: lwc1        $f10, 0x8($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X8);
    // 0x801A7440: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A7444: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A7448: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A744C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A7450: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A7454: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A7458: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A745C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801A7460: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801A7464: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801A7468: jal         0x80005B00
    // 0x801A746C: nop

    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x801A746C: nop

    after_10:
    // 0x801A7470: lwc1        $f16, 0x0($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801A7474: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A7478: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A747C: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801A7480: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A7484: jal         0x80005E90
    // 0x801A7488: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x801A7488: nop

    after_11:
    // 0x801A748C: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801A7490: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A7494: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A7498: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801A749C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A74A0: jal         0x80005D44
    // 0x801A74A4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_12;
    // 0x801A74A4: nop

    after_12:
    // 0x801A74A8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x801A74AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A74B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A74B4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A74B8: lw          $a1, 0x10($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10);
    // 0x801A74BC: jal         0x80005C34
    // 0x801A74C0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x801A74C0: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_13:
    // 0x801A74C4: jal         0x80006EB8
    // 0x801A74C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x801A74C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_14:
    // 0x801A74CC: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A74D0: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x801A74D4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801A74D8: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x801A74DC: sw          $t0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r8;
    // 0x801A74E0: sw          $s7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r23;
    // 0x801A74E4: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x801A74E8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801A74EC: addiu       $t6, $t6, 0x278C
    ctx->r14 = ADD32(ctx->r14, 0X278C);
    // 0x801A74F0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801A74F4: bne         $s1, $t6, L_801A7410
    if (ctx->r17 != ctx->r14) {
        // 0x801A74F8: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_801A7410;
    }
    // 0x801A74F8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x801A74FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A7500: lwc1        $f10, 0x279C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X279C);
    // 0x801A7504: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801A7508: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801A750C: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x801A7510: nop

    // 0x801A7514: bc1fl       L_801A771C
    if (!c1cs) {
        // 0x801A7518: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801A771C;
    }
    goto skip_1;
    // 0x801A7518: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x801A751C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A7520: lui         $t4, 0xFFC0
    ctx->r12 = S32(0XFFC0 << 16);
    // 0x801A7524: ori         $t4, $t4, 0x40FF
    ctx->r12 = ctx->r12 | 0X40FF;
    // 0x801A7528: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801A752C: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x801A7530: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801A7534: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801A7538: jal         0x80005740
    // 0x801A753C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x801A753C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x801A7540: jal         0x80005708
    // 0x801A7544: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_16;
    // 0x801A7544: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_16:
    // 0x801A7548: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801A754C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A7550: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A7554: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A7558: lwc1        $f16, 0x8($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X8);
    // 0x801A755C: lwc1        $f8, 0xC($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0XC);
    // 0x801A7560: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A7564: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A7568: lwc1        $f16, 0x7D20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801A756C: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x801A7570: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801A7574: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801A7578: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A757C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A7580: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A7584: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A7588: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801A758C: jal         0x80005B00
    // 0x801A7590: nop

    Matrix_Translate(rdram, ctx);
        goto after_17;
    // 0x801A7590: nop

    after_17:
    // 0x801A7594: lui         $a1, 0x3DB2
    ctx->r5 = S32(0X3DB2 << 16);
    // 0x801A7598: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x801A759C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A75A0: jal         0x80005D44
    // 0x801A75A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_18;
    // 0x801A75A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x801A75A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A75AC: lwc1        $f0, 0x279C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X279C);
    // 0x801A75B0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801A75B4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A75B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A75BC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A75C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801A75C4: jal         0x80005C34
    // 0x801A75C8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_19;
    // 0x801A75C8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_19:
    // 0x801A75CC: jal         0x80006EB8
    // 0x801A75D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_20;
    // 0x801A75D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_20:
    // 0x801A75D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A75D8: lwc1        $f20, 0x1878($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X1878);
    // 0x801A75DC: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A75E0: lui         $s0, 0x201
    ctx->r16 = S32(0X201 << 16);
    // 0x801A75E4: addiu       $s0, $s0, 0x12C0
    ctx->r16 = ADD32(ctx->r16, 0X12C0);
    // 0x801A75E8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801A75EC: sw          $t2, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r10;
    // 0x801A75F0: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x801A75F4: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x801A75F8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801A75FC: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801A7600: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A7604: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A7608: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A760C: jal         0x80005C34
    // 0x801A7610: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_21;
    // 0x801A7610: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_21:
    // 0x801A7614: jal         0x80006EB8
    // 0x801A7618: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_22;
    // 0x801A7618: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_22:
    // 0x801A761C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A7620: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801A7624: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x801A7628: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x801A762C: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x801A7630: jal         0x80005740
    // 0x801A7634: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_23;
    // 0x801A7634: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_23:
    // 0x801A7638: jal         0x80005708
    // 0x801A763C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Matrix_Push(rdram, ctx);
        goto after_24;
    // 0x801A763C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_24:
    // 0x801A7640: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x801A7644: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A7648: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A764C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A7650: lwc1        $f4, 0x8($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X8);
    // 0x801A7654: lwc1        $f10, 0xC($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0XC);
    // 0x801A7658: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A765C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801A7660: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801A7664: lw          $a1, 0x4($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X4);
    // 0x801A7668: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A766C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801A7670: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A7674: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801A7678: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A767C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A7680: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801A7684: jal         0x80005B00
    // 0x801A7688: nop

    Matrix_Translate(rdram, ctx);
        goto after_25;
    // 0x801A7688: nop

    after_25:
    // 0x801A768C: lui         $a1, 0xBD56
    ctx->r5 = S32(0XBD56 << 16);
    // 0x801A7690: ori         $a1, $a1, 0x7750
    ctx->r5 = ctx->r5 | 0X7750;
    // 0x801A7694: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A7698: jal         0x80005D44
    // 0x801A769C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_26;
    // 0x801A769C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x801A76A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A76A4: lwc1        $f0, 0x279C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X279C);
    // 0x801A76A8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801A76AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A76B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A76B4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A76B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801A76BC: jal         0x80005C34
    // 0x801A76C0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_27;
    // 0x801A76C0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_27:
    // 0x801A76C4: jal         0x80006EB8
    // 0x801A76C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_28;
    // 0x801A76C8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_28:
    // 0x801A76CC: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A76D0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801A76D4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801A76D8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801A76DC: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x801A76E0: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x801A76E4: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x801A76E8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801A76EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A76F0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A76F4: jal         0x80005C34
    // 0x801A76F8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_29;
    // 0x801A76F8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_29:
    // 0x801A76FC: jal         0x80006EB8
    // 0x801A7700: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_30;
    // 0x801A7700: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_30:
    // 0x801A7704: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801A7708: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801A770C: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x801A7710: sw          $s0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r16;
    // 0x801A7714: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x801A7718: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801A771C:
    // 0x801A771C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801A7720: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801A7724: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801A7728: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801A772C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801A7730: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801A7734: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801A7738: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x801A773C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x801A7740: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x801A7744: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x801A7748: jr          $ra
    // 0x801A774C: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x801A774C: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void Area6_8018DA58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA58: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DA5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018DA60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018DA64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018DA68: lh          $v1, 0xB8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB8);
    // 0x8018DA6C: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
    // 0x8018DA70: bne         $at, $zero, L_8018DA8C
    if (ctx->r1 != 0) {
        // 0x8018DA74: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018DA8C;
    }
    // 0x8018DA74: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018DA78: addiu       $at, $zero, 0x5B
    ctx->r1 = ADD32(0, 0X5B);
    // 0x8018DA7C: beq         $v0, $at, L_8018DE58
    if (ctx->r2 == ctx->r1) {
        // 0x8018DA80: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_8018DE58;
    }
    // 0x8018DA80: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8018DA84: b           L_8018DE98
    // 0x8018DA88: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018DE98;
    // 0x8018DA88: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018DA8C:
    // 0x8018DA8C: slti        $at, $v0, 0x12
    ctx->r1 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x8018DA90: bne         $at, $zero, L_8018DAAC
    if (ctx->r1 != 0) {
        // 0x8018DA94: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_8018DAAC;
    }
    // 0x8018DA94: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8018DA98: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x8018DA9C: beql        $v0, $at, L_8018DE98
    if (ctx->r2 == ctx->r1) {
        // 0x8018DAA0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8018DE98;
    }
    goto skip_0;
    // 0x8018DAA0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_0:
    // 0x8018DAA4: b           L_8018DE98
    // 0x8018DAA8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018DE98;
    // 0x8018DAA8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018DAAC:
    // 0x8018DAAC: sltiu       $at, $t6, 0x11
    ctx->r1 = ctx->r14 < 0X11 ? 1 : 0;
    // 0x8018DAB0: beq         $at, $zero, L_8018DE94
    if (ctx->r1 == 0) {
        // 0x8018DAB4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8018DE94;
    }
    // 0x8018DAB4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018DAB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DABC: addu        $at, $at, $t6
    gpr jr_addend_8018DAC4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018DAC0: lw          $t6, 0xACC($at)
    ctx->r14 = ADD32(ctx->r1, 0XACC);
    // 0x8018DAC4: jr          $t6
    // 0x8018DAC8: nop

    switch (jr_addend_8018DAC4 >> 2) {
        case 0: goto L_8018DACC; break;
        case 1: goto L_8018DB94; break;
        case 2: goto L_8018DBBC; break;
        case 3: goto L_8018DE94; break;
        case 4: goto L_8018DE94; break;
        case 5: goto L_8018DC48; break;
        case 6: goto L_8018DC8C; break;
        case 7: goto L_8018DE94; break;
        case 8: goto L_8018DE94; break;
        case 9: goto L_8018DE94; break;
        case 10: goto L_8018DC48; break;
        case 11: goto L_8018DC8C; break;
        case 12: goto L_8018DE94; break;
        case 13: goto L_8018DE94; break;
        case 14: goto L_8018DE94; break;
        case 15: goto L_8018DC48; break;
        case 16: goto L_8018DC8C; break;
        default: switch_error(__func__, 0x8018DAC4, 0x801C0ACC);
    }
    // 0x8018DAC8: nop

L_8018DACC:
    // 0x8018DACC: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8018DAD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DAD4: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8018DAD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DADC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DAE0: swc1        $f8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f8.u32l;
    // 0x8018DAE4: lwc1        $f18, 0xB10($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XB10);
    // 0x8018DAE8: lwc1        $f10, 0x130($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8018DAEC: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8018DAF0: jal         0x80023090
    // 0x8018DAF4: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8018DAF4: nop

    after_0:
    // 0x8018DAF8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DAFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DB00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DB08: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8018DB0C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018DB10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DB14: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018DB18: swc1        $f18, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f18.u32l;
    // 0x8018DB1C: swc1        $f6, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f6.u32l;
    // 0x8018DB20: lwc1        $f6, 0xB14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB14);
    // 0x8018DB24: lwc1        $f4, 0x134($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8018DB28: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018DB2C: jal         0x80023090
    // 0x8018DB30: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8018DB30: nop

    after_1:
    // 0x8018DB34: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018DB38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DB3C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018DB40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB44: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018DB48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DB4C: lwc1        $f6, 0x138($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8018DB50: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DB54: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8018DB58: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018DB5C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8018DB60: swc1        $f8, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f8.u32l;
    // 0x8018DB64: lwc1        $f4, 0xB18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB18);
    // 0x8018DB68: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8018DB6C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018DB70: jal         0x80023250
    // 0x8018DB74: nop

    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8018DB74: nop

    after_2:
    // 0x8018DB78: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018DB7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DB80: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018DB84: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018DB88: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018DB8C: b           L_8018DE94
    // 0x8018DB90: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8018DE94;
    // 0x8018DB90: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8018DB94:
    // 0x8018DB94: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018DB98: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018DB9C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DBA0: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x8018DBA4: lui         $a1, 0xC334
    ctx->r5 = S32(0XC334 << 16);
    // 0x8018DBA8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018DBAC: jal         0x8009BC2C
    // 0x8018DBB0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8018DBB0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8018DBB4: b           L_8018DE98
    // 0x8018DBB8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018DE98;
    // 0x8018DBB8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018DBBC:
    // 0x8018DBBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018DBC0: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018DBC4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DBC8: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x8018DBCC: lui         $a1, 0xC234
    ctx->r5 = S32(0XC234 << 16);
    // 0x8018DBD0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018DBD4: jal         0x8009BC2C
    // 0x8018DBD8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8018DBD8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8018DBDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018DBE0: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018DBE4: lui         $a3, 0x4019
    ctx->r7 = S32(0X4019 << 16);
    // 0x8018DBE8: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8018DBEC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DBF0: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8018DBF4: lui         $a1, 0x43AA
    ctx->r5 = S32(0X43AA << 16);
    // 0x8018DBF8: jal         0x8009BD38
    // 0x8018DBFC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x8018DBFC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x8018DC00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018DC04: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018DC08: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DC0C: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x8018DC10: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x8018DC14: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018DC18: jal         0x8009BC2C
    // 0x8018DC1C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8018DC1C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x8018DC20: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018DC24: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018DC28: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DC2C: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8018DC30: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x8018DC34: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018DC38: jal         0x8009BC2C
    // 0x8018DC3C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8018DC3C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x8018DC40: b           L_8018DE98
    // 0x8018DC44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018DE98;
    // 0x8018DC44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018DC48:
    // 0x8018DC48: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018DC4C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8018DC50: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018DC54: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018DC58: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    // 0x8018DC5C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018DC60: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018DC64: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018DC68: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018DC6C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018DC70: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018DC74: jal         0x80019218
    // 0x8018DC78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x8018DC78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8018DC7C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018DC80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC84: nop

    // 0x8018DC88: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
L_8018DC8C:
    // 0x8018DC8C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8018DC90: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x8018DC94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DC98: lwc1        $f10, 0xB1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB1C);
    // 0x8018DC9C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018DCA0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DCA4: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8018DCA8: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x8018DCAC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018DCB0: jal         0x8009BC2C
    // 0x8018DCB4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8018DCB4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8018DCB8: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8018DCBC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8018DCC0: beq         $v0, $at, L_8018DCE0
    if (ctx->r2 == ctx->r1) {
        // 0x8018DCC4: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_8018DCE0;
    }
    // 0x8018DCC4: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018DCC8: beq         $v0, $at, L_8018DD08
    if (ctx->r2 == ctx->r1) {
        // 0x8018DCCC: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_8018DD08;
    }
    // 0x8018DCCC: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8018DCD0: beql        $v0, $at, L_8018DD2C
    if (ctx->r2 == ctx->r1) {
        // 0x8018DCD4: lui         $at, 0xC2C8
        ctx->r1 = S32(0XC2C8 << 16);
            goto L_8018DD2C;
    }
    goto skip_1;
    // 0x8018DCD4: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    skip_1:
    // 0x8018DCD8: b           L_8018DD50
    // 0x8018DCDC: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
        goto L_8018DD50;
    // 0x8018DCDC: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
L_8018DCE0:
    // 0x8018DCE0: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8018DCE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DCE8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018DCEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DCF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DCF4: lwc1        $f8, 0xB20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XB20);
    // 0x8018DCF8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8018DCFC: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x8018DD00: b           L_8018DD4C
    // 0x8018DD04: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
        goto L_8018DD4C;
    // 0x8018DD04: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
L_8018DD08:
    // 0x8018DD08: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8018DD0C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DD10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DD14: lwc1        $f18, 0xB24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XB24);
    // 0x8018DD18: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8018DD1C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8018DD20: b           L_8018DD4C
    // 0x8018DD24: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
        goto L_8018DD4C;
    // 0x8018DD24: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x8018DD28: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
L_8018DD2C:
    // 0x8018DD2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DD30: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018DD34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DD38: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DD3C: lwc1        $f10, 0xB28($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB28);
    // 0x8018DD40: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8018DD44: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x8018DD48: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
L_8018DD4C:
    // 0x8018DD4C: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
L_8018DD50:
    // 0x8018DD50: jal         0x80005100
    // 0x8018DD54: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    Math_Atan2F(rdram, ctx);
        goto after_10;
    // 0x8018DD54: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    after_10:
    // 0x8018DD58: jal         0x8009F768
    // 0x8018DD5C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_11;
    // 0x8018DD5C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_11:
    // 0x8018DD60: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018DD64: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018DD68: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8018DD6C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018DD70: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018DD74: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018DD78: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018DD7C: jal         0x80005100
    // 0x8018DD80: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_12;
    // 0x8018DD80: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_12:
    // 0x8018DD84: jal         0x8009F768
    // 0x8018DD88: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_13;
    // 0x8018DD88: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_13:
    // 0x8018DD8C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018DD90: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018DD94: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8018DD98: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018DD9C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018DDA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DDA4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8018DDA8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8018DDAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DDB0: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8018DDB4: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x8018DDB8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DDBC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8018DDC0: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018DDC4: bc1fl       L_8018DDD4
    if (!c1cs) {
        // 0x8018DDC8: c.lt.s      $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
            goto L_8018DDD4;
    }
    goto skip_2;
    // 0x8018DDC8: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    skip_2:
    // 0x8018DDCC: sub.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8018DDD0: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
L_8018DDD4:
    // 0x8018DDD4: nop

    // 0x8018DDD8: bc1f        L_8018DDE8
    if (!c1cs) {
        // 0x8018DDDC: nop
    
            goto L_8018DDE8;
    }
    // 0x8018DDDC: nop

    // 0x8018DDE0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018DDE4: nop

L_8018DDE8:
    // 0x8018DDE8: lwc1        $f6, 0xB2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB2C);
    // 0x8018DDEC: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x8018DDF0: jal         0x8009BD38
    // 0x8018DDF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_14;
    // 0x8018DDF4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x8018DDF8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018DDFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018DE00: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018DE04: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DE08: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018DE0C: lwc1        $f4, 0xB30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB30);
    // 0x8018DE10: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018DE14: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x8018DE18: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8018DE1C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018DE20: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018DE24: jal         0x8009BD38
    // 0x8018DE28: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_15;
    // 0x8018DE28: swc1        $f18, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f18.u32l;
    after_15:
    // 0x8018DE2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DE30: lwc1        $f10, 0xB34($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB34);
    // 0x8018DE34: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018DE38: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018DE3C: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x8018DE40: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8018DE44: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018DE48: jal         0x8009BD38
    // 0x8018DE4C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_16;
    // 0x8018DE4C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x8018DE50: b           L_8018DE98
    // 0x8018DE54: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_8018DE98;
    // 0x8018DE54: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018DE58:
    // 0x8018DE58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DE5C: lwc1        $f0, 0xB38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0XB38);
    // 0x8018DE60: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018DE64: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018DE68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DE6C: jal         0x8009BC2C
    // 0x8018DE70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8018DE70: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_17:
    // 0x8018DE74: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018DE78: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018DE7C: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x8018DE80: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018DE84: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8018DE88: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018DE8C: jal         0x8009BC2C
    // 0x8018DE90: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8018DE90: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_18:
L_8018DE94:
    // 0x8018DE94: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8018DE98:
    // 0x8018DE98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018DE9C: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018DEA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DEA4: lwc1        $f4, 0xB3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB3C);
    // 0x8018DEA8: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018DEAC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DEB0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018DEB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018DEB8: mul.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8018DEBC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018DEC0: jal         0x80005E90
    // 0x8018DEC4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_19;
    // 0x8018DEC4: nop

    after_19:
    // 0x8018DEC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DECC: lwc1        $f8, 0xB40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XB40);
    // 0x8018DED0: lwc1        $f6, 0xF4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8018DED4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DED8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018DEDC: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018DEE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DEE4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018DEE8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018DEEC: jal         0x80005D44
    // 0x8018DEF0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_20;
    // 0x8018DEF0: nop

    after_20:
    // 0x8018DEF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DEF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DEFC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018DF00: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8018DF04: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8018DF08: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018DF0C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x8018DF10: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8018DF14: jal         0x80006A20
    // 0x8018DF18: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_21;
    // 0x8018DF18: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    after_21:
    // 0x8018DF1C: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018DF20: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018DF24: lwc1        $f14, 0xF4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8018DF28: lwc1        $f12, 0xFC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8018DF2C: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x8018DF30: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8018DF34: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x8018DF38: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018DF3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DF40: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x8018DF44: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8018DF48: add.s       $f10, $f16, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8018DF4C: swc1        $f14, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f14.u32l;
    // 0x8018DF50: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    // 0x8018DF54: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x8018DF58: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8018DF5C: swc1        $f12, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f12.u32l;
    // 0x8018DF60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018DF64: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018DF68: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DF6C: jr          $ra
    // 0x8018DF70: nop

    return;
    // 0x8018DF70: nop

;}
RECOMP_FUNC void Aquas_AqSpindlyFish_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B7754: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801B7758: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801B775C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801B7760: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x801B7764: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801B7768: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801B776C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801B7770: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801B7774: addiu       $t6, $t6, 0x2D8
    ctx->r14 = ADD32(ctx->r14, 0X2D8);
    // 0x801B7778: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x801B777C: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x801B7780: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x801B7784: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801B7788: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x801B778C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x801B7790: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x801B7794: lh          $t0, 0xCE($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCE);
    // 0x801B7798: addiu       $at, $zero, -0x64
    ctx->r1 = ADD32(0, -0X64);
    // 0x801B779C: bne         $t0, $at, L_801B7A10
    if (ctx->r8 != ctx->r1) {
        // 0x801B77A0: sltiu       $at, $t1, 0x17
        ctx->r1 = ctx->r9 < 0X17 ? 1 : 0;
            goto L_801B7A10;
    }
    // 0x801B77A0: sltiu       $at, $t1, 0x17
    ctx->r1 = ctx->r9 < 0X17 ? 1 : 0;
    // 0x801B77A4: beq         $at, $zero, L_801B7A10
    if (ctx->r1 == 0) {
        // 0x801B77A8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_801B7A10;
    }
    // 0x801B77A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801B77AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B77B0: addu        $at, $at, $t1
    gpr jr_addend_801B77B8 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801B77B4: lw          $t1, 0x1FB8($at)
    ctx->r9 = ADD32(ctx->r1, 0X1FB8);
    // 0x801B77B8: jr          $t1
    // 0x801B77BC: nop

    switch (jr_addend_801B77B8 >> 2) {
        case 0: goto L_801B77C0; break;
        case 1: goto L_801B77E8; break;
        case 2: goto L_801B7810; break;
        case 3: goto L_801B7838; break;
        case 4: goto L_801B7860; break;
        case 5: goto L_801B7888; break;
        case 6: goto L_801B78B0; break;
        case 7: goto L_801B78D8; break;
        case 8: goto L_801B7900; break;
        case 9: goto L_801B7928; break;
        case 10: goto L_801B7950; break;
        case 11: goto L_801B7978; break;
        case 12: goto L_801B79A0; break;
        case 13: goto L_801B7A10; break;
        case 14: goto L_801B7A10; break;
        case 15: goto L_801B7A10; break;
        case 16: goto L_801B7A10; break;
        case 17: goto L_801B7A10; break;
        case 18: goto L_801B7A10; break;
        case 19: goto L_801B7A10; break;
        case 20: goto L_801B7A10; break;
        case 21: goto L_801B79C8; break;
        case 22: goto L_801B79F0; break;
        default: switch_error(__func__, 0x801B77B8, 0x801C1FB8);
    }
    // 0x801B77BC: nop

L_801B77C0:
    // 0x801B77C0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B77C4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B77C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B77CC: jal         0x80006970
    // 0x801B77D0: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x801B77D0: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    after_0:
    // 0x801B77D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B77D8: jal         0x80006AB8
    // 0x801B77DC: addiu       $a1, $s0, 0x240
    ctx->r5 = ADD32(ctx->r16, 0X240);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x801B77DC: addiu       $a1, $s0, 0x240
    ctx->r5 = ADD32(ctx->r16, 0X240);
    after_1:
    // 0x801B77E0: b           L_801B7A14
    // 0x801B77E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B77E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B77E8:
    // 0x801B77E8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B77EC: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B77F0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B77F4: jal         0x80006970
    // 0x801B77F8: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801B77F8: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    after_2:
    // 0x801B77FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7800: jal         0x80006AB8
    // 0x801B7804: addiu       $a1, $s0, 0x24C
    ctx->r5 = ADD32(ctx->r16, 0X24C);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_3;
    // 0x801B7804: addiu       $a1, $s0, 0x24C
    ctx->r5 = ADD32(ctx->r16, 0X24C);
    after_3:
    // 0x801B7808: b           L_801B7A14
    // 0x801B780C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B780C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7810:
    // 0x801B7810: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B7814: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B7818: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B781C: jal         0x80006970
    // 0x801B7820: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x801B7820: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    after_4:
    // 0x801B7824: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7828: jal         0x80006AB8
    // 0x801B782C: addiu       $a1, $s0, 0x258
    ctx->r5 = ADD32(ctx->r16, 0X258);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_5;
    // 0x801B782C: addiu       $a1, $s0, 0x258
    ctx->r5 = ADD32(ctx->r16, 0X258);
    after_5:
    // 0x801B7830: b           L_801B7A14
    // 0x801B7834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B7834: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7838:
    // 0x801B7838: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B783C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B7840: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7844: jal         0x80006970
    // 0x801B7848: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x801B7848: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    after_6:
    // 0x801B784C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7850: jal         0x80006AB8
    // 0x801B7854: addiu       $a1, $s0, 0x264
    ctx->r5 = ADD32(ctx->r16, 0X264);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_7;
    // 0x801B7854: addiu       $a1, $s0, 0x264
    ctx->r5 = ADD32(ctx->r16, 0X264);
    after_7:
    // 0x801B7858: b           L_801B7A14
    // 0x801B785C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B785C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7860:
    // 0x801B7860: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B7864: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B7868: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B786C: jal         0x80006970
    // 0x801B7870: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x801B7870: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    after_8:
    // 0x801B7874: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7878: jal         0x80006AB8
    // 0x801B787C: addiu       $a1, $s0, 0x270
    ctx->r5 = ADD32(ctx->r16, 0X270);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_9;
    // 0x801B787C: addiu       $a1, $s0, 0x270
    ctx->r5 = ADD32(ctx->r16, 0X270);
    after_9:
    // 0x801B7880: b           L_801B7A14
    // 0x801B7884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B7884: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7888:
    // 0x801B7888: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B788C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B7890: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7894: jal         0x80006970
    // 0x801B7898: addiu       $a2, $s0, 0x1C8
    ctx->r6 = ADD32(ctx->r16, 0X1C8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x801B7898: addiu       $a2, $s0, 0x1C8
    ctx->r6 = ADD32(ctx->r16, 0X1C8);
    after_10:
    // 0x801B789C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B78A0: jal         0x80006AB8
    // 0x801B78A4: addiu       $a1, $s0, 0x27C
    ctx->r5 = ADD32(ctx->r16, 0X27C);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_11;
    // 0x801B78A4: addiu       $a1, $s0, 0x27C
    ctx->r5 = ADD32(ctx->r16, 0X27C);
    after_11:
    // 0x801B78A8: b           L_801B7A14
    // 0x801B78AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B78AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B78B0:
    // 0x801B78B0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B78B4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B78B8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B78BC: jal         0x80006970
    // 0x801B78C0: addiu       $a2, $s0, 0x1D4
    ctx->r6 = ADD32(ctx->r16, 0X1D4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x801B78C0: addiu       $a2, $s0, 0x1D4
    ctx->r6 = ADD32(ctx->r16, 0X1D4);
    after_12:
    // 0x801B78C4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B78C8: jal         0x80006AB8
    // 0x801B78CC: addiu       $a1, $s0, 0x288
    ctx->r5 = ADD32(ctx->r16, 0X288);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_13;
    // 0x801B78CC: addiu       $a1, $s0, 0x288
    ctx->r5 = ADD32(ctx->r16, 0X288);
    after_13:
    // 0x801B78D0: b           L_801B7A14
    // 0x801B78D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B78D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B78D8:
    // 0x801B78D8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B78DC: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B78E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B78E4: jal         0x80006970
    // 0x801B78E8: addiu       $a2, $s0, 0x1E0
    ctx->r6 = ADD32(ctx->r16, 0X1E0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x801B78E8: addiu       $a2, $s0, 0x1E0
    ctx->r6 = ADD32(ctx->r16, 0X1E0);
    after_14:
    // 0x801B78EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B78F0: jal         0x80006AB8
    // 0x801B78F4: addiu       $a1, $s0, 0x294
    ctx->r5 = ADD32(ctx->r16, 0X294);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_15;
    // 0x801B78F4: addiu       $a1, $s0, 0x294
    ctx->r5 = ADD32(ctx->r16, 0X294);
    after_15:
    // 0x801B78F8: b           L_801B7A14
    // 0x801B78FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B78FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7900:
    // 0x801B7900: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B7904: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B7908: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B790C: jal         0x80006970
    // 0x801B7910: addiu       $a2, $s0, 0x1EC
    ctx->r6 = ADD32(ctx->r16, 0X1EC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x801B7910: addiu       $a2, $s0, 0x1EC
    ctx->r6 = ADD32(ctx->r16, 0X1EC);
    after_16:
    // 0x801B7914: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7918: jal         0x80006AB8
    // 0x801B791C: addiu       $a1, $s0, 0x2A0
    ctx->r5 = ADD32(ctx->r16, 0X2A0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_17;
    // 0x801B791C: addiu       $a1, $s0, 0x2A0
    ctx->r5 = ADD32(ctx->r16, 0X2A0);
    after_17:
    // 0x801B7920: b           L_801B7A14
    // 0x801B7924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B7924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7928:
    // 0x801B7928: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B792C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B7930: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7934: jal         0x80006970
    // 0x801B7938: addiu       $a2, $s0, 0x1F8
    ctx->r6 = ADD32(ctx->r16, 0X1F8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_18;
    // 0x801B7938: addiu       $a2, $s0, 0x1F8
    ctx->r6 = ADD32(ctx->r16, 0X1F8);
    after_18:
    // 0x801B793C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7940: jal         0x80006AB8
    // 0x801B7944: addiu       $a1, $s0, 0x2AC
    ctx->r5 = ADD32(ctx->r16, 0X2AC);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_19;
    // 0x801B7944: addiu       $a1, $s0, 0x2AC
    ctx->r5 = ADD32(ctx->r16, 0X2AC);
    after_19:
    // 0x801B7948: b           L_801B7A14
    // 0x801B794C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B794C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7950:
    // 0x801B7950: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B7954: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B7958: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B795C: jal         0x80006970
    // 0x801B7960: addiu       $a2, $s0, 0x204
    ctx->r6 = ADD32(ctx->r16, 0X204);
    Matrix_MultVec3f(rdram, ctx);
        goto after_20;
    // 0x801B7960: addiu       $a2, $s0, 0x204
    ctx->r6 = ADD32(ctx->r16, 0X204);
    after_20:
    // 0x801B7964: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7968: jal         0x80006AB8
    // 0x801B796C: addiu       $a1, $s0, 0x2B8
    ctx->r5 = ADD32(ctx->r16, 0X2B8);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_21;
    // 0x801B796C: addiu       $a1, $s0, 0x2B8
    ctx->r5 = ADD32(ctx->r16, 0X2B8);
    after_21:
    // 0x801B7970: b           L_801B7A14
    // 0x801B7974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B7974: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7978:
    // 0x801B7978: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B797C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B7980: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7984: jal         0x80006970
    // 0x801B7988: addiu       $a2, $s0, 0x210
    ctx->r6 = ADD32(ctx->r16, 0X210);
    Matrix_MultVec3f(rdram, ctx);
        goto after_22;
    // 0x801B7988: addiu       $a2, $s0, 0x210
    ctx->r6 = ADD32(ctx->r16, 0X210);
    after_22:
    // 0x801B798C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7990: jal         0x80006AB8
    // 0x801B7994: addiu       $a1, $s0, 0x2C4
    ctx->r5 = ADD32(ctx->r16, 0X2C4);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_23;
    // 0x801B7994: addiu       $a1, $s0, 0x2C4
    ctx->r5 = ADD32(ctx->r16, 0X2C4);
    after_23:
    // 0x801B7998: b           L_801B7A14
    // 0x801B799C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B799C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B79A0:
    // 0x801B79A0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B79A4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B79A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B79AC: jal         0x80006970
    // 0x801B79B0: addiu       $a2, $s0, 0x21C
    ctx->r6 = ADD32(ctx->r16, 0X21C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_24;
    // 0x801B79B0: addiu       $a2, $s0, 0x21C
    ctx->r6 = ADD32(ctx->r16, 0X21C);
    after_24:
    // 0x801B79B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B79B8: jal         0x80006AB8
    // 0x801B79BC: addiu       $a1, $s0, 0x2D0
    ctx->r5 = ADD32(ctx->r16, 0X2D0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_25;
    // 0x801B79BC: addiu       $a1, $s0, 0x2D0
    ctx->r5 = ADD32(ctx->r16, 0X2D0);
    after_25:
    // 0x801B79C0: b           L_801B7A14
    // 0x801B79C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B79C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B79C8:
    // 0x801B79C8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B79CC: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B79D0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B79D4: jal         0x80006970
    // 0x801B79D8: addiu       $a2, $s0, 0x228
    ctx->r6 = ADD32(ctx->r16, 0X228);
    Matrix_MultVec3f(rdram, ctx);
        goto after_26;
    // 0x801B79D8: addiu       $a2, $s0, 0x228
    ctx->r6 = ADD32(ctx->r16, 0X228);
    after_26:
    // 0x801B79DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B79E0: jal         0x80006AB8
    // 0x801B79E4: addiu       $a1, $s0, 0x2DC
    ctx->r5 = ADD32(ctx->r16, 0X2DC);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_27;
    // 0x801B79E4: addiu       $a1, $s0, 0x2DC
    ctx->r5 = ADD32(ctx->r16, 0X2DC);
    after_27:
    // 0x801B79E8: b           L_801B7A14
    // 0x801B79EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801B7A14;
    // 0x801B79EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B79F0:
    // 0x801B79F0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B79F4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801B79F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B79FC: jal         0x80006970
    // 0x801B7A00: addiu       $a2, $s0, 0x234
    ctx->r6 = ADD32(ctx->r16, 0X234);
    Matrix_MultVec3f(rdram, ctx);
        goto after_28;
    // 0x801B7A00: addiu       $a2, $s0, 0x234
    ctx->r6 = ADD32(ctx->r16, 0X234);
    after_28:
    // 0x801B7A04: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B7A08: jal         0x80006AB8
    // 0x801B7A0C: addiu       $a1, $s0, 0x2E8
    ctx->r5 = ADD32(ctx->r16, 0X2E8);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_29;
    // 0x801B7A0C: addiu       $a1, $s0, 0x2E8
    ctx->r5 = ADD32(ctx->r16, 0X2E8);
    after_29:
L_801B7A10:
    // 0x801B7A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801B7A14:
    // 0x801B7A14: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801B7A18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801B7A1C: jr          $ra
    // 0x801B7A20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801B7A20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Solar_801A8BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A8BE8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801A8BEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A8BF0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A8BF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A8BF8: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x801A8BFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A8C00: beq         $v0, $at, L_801A8C2C
    if (ctx->r2 == ctx->r1) {
        // 0x801A8C04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A8C2C;
    }
    // 0x801A8C04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A8C08: beq         $v0, $at, L_801A8C6C
    if (ctx->r2 == ctx->r1) {
        // 0x801A8C0C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801A8C6C;
    }
    // 0x801A8C0C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A8C10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A8C14: beq         $v0, $at, L_801A8CAC
    if (ctx->r2 == ctx->r1) {
        // 0x801A8C18: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801A8CAC;
    }
    // 0x801A8C18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801A8C1C: beql        $v0, $at, L_801A8CE0
    if (ctx->r2 == ctx->r1) {
        // 0x801A8C20: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_801A8CE0;
    }
    goto skip_0;
    // 0x801A8C20: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_0:
    // 0x801A8C24: b           L_801A8CE0
    // 0x801A8C28: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_801A8CE0;
    // 0x801A8C28: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_801A8C2C:
    // 0x801A8C2C: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
    // 0x801A8C30: beql        $t6, $zero, L_801A8CE0
    if (ctx->r14 == 0) {
        // 0x801A8C34: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_801A8CE0;
    }
    goto skip_1;
    // 0x801A8C34: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_1:
    // 0x801A8C38: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x801A8C3C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A8C40: lw          $t7, 0x7A80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7A80);
    // 0x801A8C44: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x801A8C48: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801A8C4C: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801A8C50: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x801A8C54: addiu       $t1, $t0, 0x406
    ctx->r9 = ADD32(ctx->r8, 0X406);
    // 0x801A8C58: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801A8C5C: beq         $at, $zero, L_801A8CDC
    if (ctx->r1 == 0) {
        // 0x801A8C60: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_801A8CDC;
    }
    // 0x801A8C60: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x801A8C64: b           L_801A8CDC
    // 0x801A8C68: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
        goto L_801A8CDC;
    // 0x801A8C68: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
L_801A8C6C:
    // 0x801A8C6C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801A8C70: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801A8C74: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A8C78: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    // 0x801A8C7C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x801A8C80: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801A8C84: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801A8C88: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801A8C8C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A8C90: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801A8C94: jal         0x80019218
    // 0x801A8C98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x801A8C98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801A8C9C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801A8CA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A8CA4: nop

    // 0x801A8CA8: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
L_801A8CAC:
    // 0x801A8CAC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A8CB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A8CB4: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801A8CB8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801A8CBC: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
    // 0x801A8CC0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A8CC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A8CC8: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801A8CCC: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x801A8CD0: lwc1        $f18, 0x1A18($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1A18);
    // 0x801A8CD4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A8CD8: swc1        $f4, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f4.u32l;
L_801A8CDC:
    // 0x801A8CDC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_801A8CE0:
    // 0x801A8CE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A8CE4: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x801A8CE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A8CEC: lwc1        $f16, 0x1A1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1A1C);
    // 0x801A8CF0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A8CF4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8CF8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A8CFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A8D00: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801A8D04: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A8D08: jal         0x80005E90
    // 0x801A8D0C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801A8D0C: nop

    after_1:
    // 0x801A8D10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A8D14: lwc1        $f6, 0x1A20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1A20);
    // 0x801A8D18: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801A8D1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8D20: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A8D24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A8D28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A8D2C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801A8D30: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A8D34: jal         0x80005D44
    // 0x801A8D38: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801A8D38: nop

    after_2:
    // 0x801A8D3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A8D40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A8D44: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A8D48: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801A8D4C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x801A8D50: lwc1        $f16, 0x114($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801A8D54: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801A8D58: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801A8D5C: jal         0x80006A20
    // 0x801A8D60: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x801A8D60: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801A8D64: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A8D68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A8D6C: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x801A8D70: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x801A8D74: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A8D78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A8D7C: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801A8D80: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x801A8D84: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A8D88: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A8D8C: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x801A8D90: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x801A8D94: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801A8D98: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x801A8D9C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x801A8DA0: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x801A8DA4: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x801A8DA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A8DAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A8DB0: jr          $ra
    // 0x801A8DB4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801A8DB4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Zoness_ZoObnema_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192C84: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80192C88: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80192C8C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80192C90: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80192C94: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80192C98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80192C9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80192CA0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80192CA4: addiu       $t6, $t6, -0xA1C
    ctx->r14 = ADD32(ctx->r14, -0XA1C);
    // 0x80192CA8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80192CAC: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x80192CB0: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80192CB4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80192CB8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80192CBC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80192CC0: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80192CC4: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x80192CC8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80192CCC: bne         $t0, $at, L_80192E50
    if (ctx->r8 != ctx->r1) {
        // 0x80192CD0: sltiu       $at, $t1, 0xD
        ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
            goto L_80192E50;
    }
    // 0x80192CD0: sltiu       $at, $t1, 0xD
    ctx->r1 = ctx->r9 < 0XD ? 1 : 0;
    // 0x80192CD4: beq         $at, $zero, L_80192E50
    if (ctx->r1 == 0) {
        // 0x80192CD8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80192E50;
    }
    // 0x80192CD8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80192CDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192CE0: addu        $at, $at, $t1
    gpr jr_addend_80192CE8 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80192CE4: lw          $t1, 0xEB8($at)
    ctx->r9 = ADD32(ctx->r1, 0XEB8);
    // 0x80192CE8: jr          $t1
    // 0x80192CEC: nop

    switch (jr_addend_80192CE8 >> 2) {
        case 0: goto L_80192CF0; break;
        case 1: goto L_80192D18; break;
        case 2: goto L_80192D40; break;
        case 3: goto L_80192D68; break;
        case 4: goto L_80192D90; break;
        case 5: goto L_80192DB8; break;
        case 6: goto L_80192DE0; break;
        case 7: goto L_80192E08; break;
        case 8: goto L_80192E50; break;
        case 9: goto L_80192E50; break;
        case 10: goto L_80192E50; break;
        case 11: goto L_80192E50; break;
        case 12: goto L_80192E30; break;
        default: switch_error(__func__, 0x80192CE8, 0x801C0EB8);
    }
    // 0x80192CEC: nop

L_80192CF0:
    // 0x80192CF0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192CF4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192CF8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192CFC: jal         0x80006970
    // 0x80192D00: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x80192D00: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    after_0:
    // 0x80192D04: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192D08: jal         0x80006AB8
    // 0x80192D0C: addiu       $a1, $s0, 0x1F8
    ctx->r5 = ADD32(ctx->r16, 0X1F8);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x80192D0C: addiu       $a1, $s0, 0x1F8
    ctx->r5 = ADD32(ctx->r16, 0X1F8);
    after_1:
    // 0x80192D10: b           L_80192E54
    // 0x80192D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80192E54;
    // 0x80192D14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192D18:
    // 0x80192D18: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192D1C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192D20: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192D24: jal         0x80006970
    // 0x80192D28: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x80192D28: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    after_2:
    // 0x80192D2C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192D30: jal         0x80006AB8
    // 0x80192D34: addiu       $a1, $s0, 0x204
    ctx->r5 = ADD32(ctx->r16, 0X204);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_3;
    // 0x80192D34: addiu       $a1, $s0, 0x204
    ctx->r5 = ADD32(ctx->r16, 0X204);
    after_3:
    // 0x80192D38: b           L_80192E54
    // 0x80192D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80192E54;
    // 0x80192D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192D40:
    // 0x80192D40: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192D44: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192D48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192D4C: jal         0x80006970
    // 0x80192D50: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x80192D50: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    after_4:
    // 0x80192D54: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192D58: jal         0x80006AB8
    // 0x80192D5C: addiu       $a1, $s0, 0x210
    ctx->r5 = ADD32(ctx->r16, 0X210);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_5;
    // 0x80192D5C: addiu       $a1, $s0, 0x210
    ctx->r5 = ADD32(ctx->r16, 0X210);
    after_5:
    // 0x80192D60: b           L_80192E54
    // 0x80192D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80192E54;
    // 0x80192D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192D68:
    // 0x80192D68: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192D6C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192D70: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192D74: jal         0x80006970
    // 0x80192D78: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x80192D78: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    after_6:
    // 0x80192D7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192D80: jal         0x80006AB8
    // 0x80192D84: addiu       $a1, $s0, 0x21C
    ctx->r5 = ADD32(ctx->r16, 0X21C);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_7;
    // 0x80192D84: addiu       $a1, $s0, 0x21C
    ctx->r5 = ADD32(ctx->r16, 0X21C);
    after_7:
    // 0x80192D88: b           L_80192E54
    // 0x80192D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80192E54;
    // 0x80192D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192D90:
    // 0x80192D90: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192D94: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192D98: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192D9C: jal         0x80006970
    // 0x80192DA0: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x80192DA0: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    after_8:
    // 0x80192DA4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192DA8: jal         0x80006AB8
    // 0x80192DAC: addiu       $a1, $s0, 0x228
    ctx->r5 = ADD32(ctx->r16, 0X228);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_9;
    // 0x80192DAC: addiu       $a1, $s0, 0x228
    ctx->r5 = ADD32(ctx->r16, 0X228);
    after_9:
    // 0x80192DB0: b           L_80192E54
    // 0x80192DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80192E54;
    // 0x80192DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192DB8:
    // 0x80192DB8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192DBC: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192DC0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192DC4: jal         0x80006970
    // 0x80192DC8: addiu       $a2, $s0, 0x1C8
    ctx->r6 = ADD32(ctx->r16, 0X1C8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x80192DC8: addiu       $a2, $s0, 0x1C8
    ctx->r6 = ADD32(ctx->r16, 0X1C8);
    after_10:
    // 0x80192DCC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192DD0: jal         0x80006AB8
    // 0x80192DD4: addiu       $a1, $s0, 0x234
    ctx->r5 = ADD32(ctx->r16, 0X234);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_11;
    // 0x80192DD4: addiu       $a1, $s0, 0x234
    ctx->r5 = ADD32(ctx->r16, 0X234);
    after_11:
    // 0x80192DD8: b           L_80192E54
    // 0x80192DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80192E54;
    // 0x80192DDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192DE0:
    // 0x80192DE0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192DE4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192DE8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192DEC: jal         0x80006970
    // 0x80192DF0: addiu       $a2, $s0, 0x1D4
    ctx->r6 = ADD32(ctx->r16, 0X1D4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x80192DF0: addiu       $a2, $s0, 0x1D4
    ctx->r6 = ADD32(ctx->r16, 0X1D4);
    after_12:
    // 0x80192DF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192DF8: jal         0x80006AB8
    // 0x80192DFC: addiu       $a1, $s0, 0x240
    ctx->r5 = ADD32(ctx->r16, 0X240);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_13;
    // 0x80192DFC: addiu       $a1, $s0, 0x240
    ctx->r5 = ADD32(ctx->r16, 0X240);
    after_13:
    // 0x80192E00: b           L_80192E54
    // 0x80192E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80192E54;
    // 0x80192E04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192E08:
    // 0x80192E08: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192E0C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192E10: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192E14: jal         0x80006970
    // 0x80192E18: addiu       $a2, $s0, 0x1E0
    ctx->r6 = ADD32(ctx->r16, 0X1E0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x80192E18: addiu       $a2, $s0, 0x1E0
    ctx->r6 = ADD32(ctx->r16, 0X1E0);
    after_14:
    // 0x80192E1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192E20: jal         0x80006AB8
    // 0x80192E24: addiu       $a1, $s0, 0x24C
    ctx->r5 = ADD32(ctx->r16, 0X24C);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_15;
    // 0x80192E24: addiu       $a1, $s0, 0x24C
    ctx->r5 = ADD32(ctx->r16, 0X24C);
    after_15:
    // 0x80192E28: b           L_80192E54
    // 0x80192E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80192E54;
    // 0x80192E2C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192E30:
    // 0x80192E30: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192E34: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192E38: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192E3C: jal         0x80006970
    // 0x80192E40: addiu       $a2, $s0, 0x1EC
    ctx->r6 = ADD32(ctx->r16, 0X1EC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x80192E40: addiu       $a2, $s0, 0x1EC
    ctx->r6 = ADD32(ctx->r16, 0X1EC);
    after_16:
    // 0x80192E44: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192E48: jal         0x80006AB8
    // 0x80192E4C: addiu       $a1, $s0, 0x258
    ctx->r5 = ADD32(ctx->r16, 0X258);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_17;
    // 0x80192E4C: addiu       $a1, $s0, 0x258
    ctx->r5 = ADD32(ctx->r16, 0X258);
    after_17:
L_80192E50:
    // 0x80192E50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192E54:
    // 0x80192E54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80192E58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80192E5C: jr          $ra
    // 0x80192E60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80192E60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Area6_ActorMissileSeekPlayer_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801875E4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801875E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801875EC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801875F0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801875F4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801875F8: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x801875FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80187600: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_80187604:
    // 0x80187604: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80187608: bnel        $t6, $zero, L_80187664
    if (ctx->r14 != 0) {
        // 0x8018760C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80187664;
    }
    goto skip_0;
    // 0x8018760C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x80187610: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80187614: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80187618: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018761C: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x80187620: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80187624: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80187628: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8018762C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x80187630: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80187634: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80187638: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018763C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80187640: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80187644: jal         0x80187530
    // 0x80187648: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    Area6_ActorMissileSeekPlayer_Setup(rdram, ctx);
        goto after_0;
    // 0x80187648: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x8018764C: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80187650: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187654: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80187658: b           L_8018766C
    // 0x8018765C: sw          $t9, 0x227C($at)
    MEM_W(0X227C, ctx->r1) = ctx->r25;
        goto L_8018766C;
    // 0x8018765C: sw          $t9, 0x227C($at)
    MEM_W(0X227C, ctx->r1) = ctx->r25;
    // 0x80187660: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80187664:
    // 0x80187664: bne         $v0, $v1, L_80187604
    if (ctx->r2 != ctx->r3) {
        // 0x80187668: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_80187604;
    }
    // 0x80187668: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_8018766C:
    // 0x8018766C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80187670: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80187674: jr          $ra
    // 0x80187678: nop

    return;
    // 0x80187678: nop

;}
RECOMP_FUNC void Zoness_80198ECC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198ECC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80198ED0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80198ED4: addiu       $v1, $v1, 0x24E8
    ctx->r3 = ADD32(ctx->r3, 0X24E8);
    // 0x80198ED8: addiu       $v0, $v0, 0x23D0
    ctx->r2 = ADD32(ctx->r2, 0X23D0);
    // 0x80198EDC: addiu       $t6, $zero, 0x1F4
    ctx->r14 = ADD32(0, 0X1F4);
    // 0x80198EE0: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80198EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198EE8: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x80198EEC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80198EF0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80198EF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80198EF8: sh          $t7, 0x50($a0)
    MEM_H(0X50, ctx->r4) = ctx->r15;
    // 0x80198EFC: sh          $zero, 0x54($a0)
    MEM_H(0X54, ctx->r4) = 0;
    // 0x80198F00: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x80198F04: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80198F08: swc1        $f4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f4.u32l;
    // 0x80198F0C: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
    // 0x80198F10: lwc1        $f8, 0x11BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X11BC);
    // 0x80198F14: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80198F18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80198F1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198F20: swc1        $f8, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f8.u32l;
    // 0x80198F24: swc1        $f10, 0x134($v1)
    MEM_W(0X134, ctx->r3) = ctx->f10.u32l;
    // 0x80198F28: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80198F2C: sh          $t8, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r24;
    // 0x80198F30: swc1        $f16, 0xE8($a0)
    MEM_W(0XE8, ctx->r4) = ctx->f16.u32l;
    // 0x80198F34: jr          $ra
    // 0x80198F38: nop

    return;
    // 0x80198F38: nop

;}
RECOMP_FUNC void Zoness_8019914C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019914C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80199150: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80199154: addiu       $a3, $a3, 0x23D0
    ctx->r7 = ADD32(ctx->r7, 0X23D0);
    // 0x80199158: addiu       $v1, $v1, 0x2330
    ctx->r3 = ADD32(ctx->r3, 0X2330);
    // 0x8019915C: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    // 0x80199160: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80199164: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x80199168: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019916C: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x80199170: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80199174: sw          $a2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r6;
    // 0x80199178: sw          $a2, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r6;
    // 0x8019917C: sw          $a2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r6;
    // 0x80199180: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199184: swc1        $f4, 0x261C($at)
    MEM_W(0X261C, ctx->r1) = ctx->f4.u32l;
    // 0x80199188: sw          $zero, 0x90($a3)
    MEM_W(0X90, ctx->r7) = 0;
    // 0x8019918C: sw          $zero, 0x40($a3)
    MEM_W(0X40, ctx->r7) = 0;
    // 0x80199190: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80199194: sh          $a2, 0x90($a0)
    MEM_H(0X90, ctx->r4) = ctx->r6;
    // 0x80199198: sh          $t2, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r10;
    // 0x8019919C: lw          $t3, 0x2C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X2C);
    // 0x801991A0: bne         $t3, $zero, L_801991C8
    if (ctx->r11 != 0) {
        // 0x801991A4: nop
    
            goto L_801991C8;
    }
    // 0x801991A4: nop

    // 0x801991A8: lw          $t4, 0x30($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X30);
    // 0x801991AC: bne         $t4, $zero, L_801991C8
    if (ctx->r12 != 0) {
        // 0x801991B0: nop
    
            goto L_801991C8;
    }
    // 0x801991B0: nop

    // 0x801991B4: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801991B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801991BC: swc1        $f6, 0xF0($a0)
    MEM_W(0XF0, ctx->r4) = ctx->f6.u32l;
    // 0x801991C0: sw          $t5, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r13;
    // 0x801991C4: sw          $t5, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r13;
L_801991C8:
    // 0x801991C8: jr          $ra
    // 0x801991CC: nop

    return;
    // 0x801991CC: nop

;}
RECOMP_FUNC void Solar_801A3128(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A3128: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A312C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A3130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A3134: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A3138: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
    // 0x801A313C: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x801A3140: beq         $v0, $zero, L_801A3150
    if (ctx->r2 == 0) {
        // 0x801A3144: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801A3150;
    }
    // 0x801A3144: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801A3148: sh          $t6, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r14;
    // 0x801A314C: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
L_801A3150:
    // 0x801A3150: lh          $t7, 0x4E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4E);
    // 0x801A3154: bne         $t7, $zero, L_801A3278
    if (ctx->r15 != 0) {
        // 0x801A3158: nop
    
            goto L_801A3278;
    }
    // 0x801A3158: nop

    // 0x801A315C: bne         $v0, $zero, L_801A3264
    if (ctx->r2 != 0) {
        // 0x801A3160: lui         $a0, 0x601
        ctx->r4 = S32(0X601 << 16);
            goto L_801A3264;
    }
    // 0x801A3160: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x801A3164: lh          $t8, 0x4C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4C);
    // 0x801A3168: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A316C: lwc1        $f0, 0x16C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X16C0);
    // 0x801A3170: addiu       $t9, $t8, -0x2
    ctx->r25 = ADD32(ctx->r24, -0X2);
    // 0x801A3174: sh          $t9, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r25;
    // 0x801A3178: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A317C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801A3180: lui         $a1, 0xC47A
    ctx->r5 = S32(0XC47A << 16);
    // 0x801A3184: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A3188: jal         0x8009BC2C
    // 0x801A318C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801A318C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801A3190: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
    // 0x801A3194: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801A3198: bne         $v0, $at, L_801A31D0
    if (ctx->r2 != ctx->r1) {
        // 0x801A319C: lui         $at, 0x44FA
        ctx->r1 = S32(0X44FA << 16);
            goto L_801A31D0;
    }
    // 0x801A319C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x801A31A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A31A4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A31A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801A31AC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x801A31B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A31B4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A31B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801A31BC: addiu       $a0, $a0, 0x5D68
    ctx->r4 = ADD32(ctx->r4, 0X5D68);
    // 0x801A31C0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801A31C4: jal         0x801A0CEC
    // 0x801A31C8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Solar_801A0CEC(rdram, ctx);
        goto after_1;
    // 0x801A31C8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_1:
    // 0x801A31CC: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
L_801A31D0:
    // 0x801A31D0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801A31D4: bne         $v0, $at, L_801A3214
    if (ctx->r2 != ctx->r1) {
        // 0x801A31D8: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801A3214;
    }
    // 0x801A31D8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A31DC: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801A31E0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A31E4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801A31E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801A31EC: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801A31F0: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x801A31F4: sb          $t1, 0x5E38($at)
    MEM_B(0X5E38, ctx->r1) = ctx->r9;
    // 0x801A31F8: ori         $a0, $a0, 0x6054
    ctx->r4 = ctx->r4 | 0X6054;
    // 0x801A31FC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801A3200: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A3204: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x801A3208: jal         0x80019218
    // 0x801A320C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801A320C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x801A3210: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
L_801A3214:
    // 0x801A3214: bne         $v0, $zero, L_801A3454
    if (ctx->r2 != 0) {
        // 0x801A3218: addiu       $t5, $zero, 0x64
        ctx->r13 = ADD32(0, 0X64);
            goto L_801A3454;
    }
    // 0x801A3218: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x801A321C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801A3220: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A3224: lh          $t3, 0x4E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4E);
    // 0x801A3228: lui         $at, 0x4516
    ctx->r1 = S32(0X4516 << 16);
    // 0x801A322C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A3230: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801A3234: sh          $t4, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r12;
    // 0x801A3238: sh          $t5, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r13;
    // 0x801A323C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801A3240: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x801A3244: swc1        $f16, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f16.u32l;
    // 0x801A3248: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801A324C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3250: lwc1        $f4, 0x16C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X16C4);
    // 0x801A3254: lwc1        $f18, 0x138($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X138);
    // 0x801A3258: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A325C: b           L_801A3454
    // 0x801A3260: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_801A3454;
    // 0x801A3260: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_801A3264:
    // 0x801A3264: jal         0x8009ACDC
    // 0x801A3268: addiu       $a0, $a0, 0x388C
    ctx->r4 = ADD32(ctx->r4, 0X388C);
    Animation_GetFrameCount(rdram, ctx);
        goto after_3;
    // 0x801A3268: addiu       $a0, $a0, 0x388C
    ctx->r4 = ADD32(ctx->r4, 0X388C);
    after_3:
    // 0x801A326C: addiu       $t7, $v0, -0x2
    ctx->r15 = ADD32(ctx->r2, -0X2);
    // 0x801A3270: b           L_801A3454
    // 0x801A3274: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
        goto L_801A3454;
    // 0x801A3274: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
L_801A3278:
    // 0x801A3278: bne         $v0, $at, L_801A3344
    if (ctx->r2 != ctx->r1) {
        // 0x801A327C: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_801A3344;
    }
    // 0x801A327C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3280: lwc1        $f10, 0x16C8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X16C8);
    // 0x801A3284: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A3288: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801A328C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x801A3290: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A3294: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A3298: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A329C: addiu       $a0, $a0, 0x5A74
    ctx->r4 = ADD32(ctx->r4, 0X5A74);
    // 0x801A32A0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801A32A4: jal         0x801A0CEC
    // 0x801A32A8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    Solar_801A0CEC(rdram, ctx);
        goto after_4;
    // 0x801A32A8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    after_4:
    // 0x801A32AC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A32B0: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x801A32B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A32B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A32BC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801A32C0: sb          $t9, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = ctx->r25;
    // 0x801A32C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A32C8: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x801A32CC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801A32D0: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801A32D4: addiu       $t0, $zero, 0x46
    ctx->r8 = ADD32(0, 0X46);
    // 0x801A32D8: addiu       $v1, $v1, 0x2740
    ctx->r3 = ADD32(ctx->r3, 0X2740);
    // 0x801A32DC: sh          $t0, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r8;
    // 0x801A32E0: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x801A32E4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801A32E8: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x801A32EC: beq         $t4, $zero, L_801A3344
    if (ctx->r12 == 0) {
        // 0x801A32F0: sw          $t3, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r11;
            goto L_801A3344;
    }
    // 0x801A32F0: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x801A32F4: andi        $t5, $t3, 0x2
    ctx->r13 = ctx->r11 & 0X2;
    // 0x801A32F8: beq         $t5, $zero, L_801A3328
    if (ctx->r13 == 0) {
        // 0x801A32FC: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_801A3328;
    }
    // 0x801A32FC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A3300: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801A3304: lw          $t6, 0x78BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78BC);
    // 0x801A3308: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A330C: addiu       $a0, $a0, 0x47F8
    ctx->r4 = ADD32(ctx->r4, 0X47F8);
    // 0x801A3310: blezl       $t6, L_801A3348
    if (SIGNED(ctx->r14) <= 0) {
        // 0x801A3314: lh          $v0, 0x9E($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X9E);
            goto L_801A3348;
    }
    goto skip_0;
    // 0x801A3314: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
    skip_0:
    // 0x801A3318: jal         0x800BA808
    // 0x801A331C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x801A331C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_5:
    // 0x801A3320: b           L_801A3348
    // 0x801A3324: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
        goto L_801A3348;
    // 0x801A3324: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
L_801A3328:
    // 0x801A3328: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x801A332C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A3330: addiu       $a0, $a0, 0x3E6C
    ctx->r4 = ADD32(ctx->r4, 0X3E6C);
    // 0x801A3334: blezl       $t7, L_801A3348
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801A3338: lh          $v0, 0x9E($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X9E);
            goto L_801A3348;
    }
    goto skip_1;
    // 0x801A3338: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
    skip_1:
    // 0x801A333C: jal         0x800BA808
    // 0x801A3340: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x801A3340: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
L_801A3344:
    // 0x801A3344: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
L_801A3348:
    // 0x801A3348: addiu       $t8, $zero, 0xDC
    ctx->r24 = ADD32(0, 0XDC);
    // 0x801A334C: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x801A3350: bne         $v0, $zero, L_801A3360
    if (ctx->r2 != 0) {
        // 0x801A3354: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_801A3360;
    }
    // 0x801A3354: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A3358: sh          $t8, 0x9E($s0)
    MEM_H(0X9E, ctx->r16) = ctx->r24;
    // 0x801A335C: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
L_801A3360:
    // 0x801A3360: bne         $v0, $at, L_801A3374
    if (ctx->r2 != ctx->r1) {
        // 0x801A3364: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_801A3374;
    }
    // 0x801A3364: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801A3368: sh          $zero, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = 0;
    // 0x801A336C: sh          $t9, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r25;
    // 0x801A3370: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
L_801A3374:
    // 0x801A3374: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x801A3378: bne         $at, $zero, L_801A339C
    if (ctx->r1 != 0) {
        // 0x801A337C: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_801A339C;
    }
    // 0x801A337C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3380: lwc1        $f0, 0x16CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X16CC);
    // 0x801A3384: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x801A3388: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x801A338C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A3390: jal         0x8009BC2C
    // 0x801A3394: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x801A3394: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x801A3398: lh          $v0, 0x9E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X9E);
L_801A339C:
    // 0x801A339C: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x801A33A0: bnel        $v0, $at, L_801A3414
    if (ctx->r2 != ctx->r1) {
        // 0x801A33A4: lh          $t3, 0x9E($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X9E);
            goto L_801A3414;
    }
    goto skip_2;
    // 0x801A33A4: lh          $t3, 0x9E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X9E);
    skip_2:
    // 0x801A33A8: jal         0x801A239C
    // 0x801A33AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Solar_801A239C(rdram, ctx);
        goto after_8;
    // 0x801A33AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801A33B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A33B4: lwc1        $f18, 0x16D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X16D0);
    // 0x801A33B8: jal         0x80004EB0
    // 0x801A33BC: swc1        $f18, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801A33BC: swc1        $f18, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f18.u32l;
    after_9:
    // 0x801A33C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A33C4: lwc1        $f4, 0x16D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X16D4);
    // 0x801A33C8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801A33CC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x801A33D0: nop

    // 0x801A33D4: bc1fl       L_801A3414
    if (!c1cs) {
        // 0x801A33D8: lh          $t3, 0x9E($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X9E);
            goto L_801A3414;
    }
    goto skip_3;
    // 0x801A33D8: lh          $t3, 0x9E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X9E);
    skip_3:
    // 0x801A33DC: lw          $t0, 0x78BC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78BC);
    // 0x801A33E0: blezl       $t0, L_801A3414
    if (SIGNED(ctx->r8) <= 0) {
        // 0x801A33E4: lh          $t3, 0x9E($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X9E);
            goto L_801A3414;
    }
    goto skip_4;
    // 0x801A33E4: lh          $t3, 0x9E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X9E);
    skip_4:
    // 0x801A33E8: lh          $t1, 0x8C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X8C);
    // 0x801A33EC: beql        $t1, $zero, L_801A3414
    if (ctx->r9 == 0) {
        // 0x801A33F0: lh          $t3, 0x9E($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X9E);
            goto L_801A3414;
    }
    goto skip_5;
    // 0x801A33F0: lh          $t3, 0x9E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X9E);
    skip_5:
    // 0x801A33F4: lh          $t2, 0x8E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8E);
    // 0x801A33F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A33FC: addiu       $a0, $a0, -0x33C
    ctx->r4 = ADD32(ctx->r4, -0X33C);
    // 0x801A3400: beql        $t2, $zero, L_801A3414
    if (ctx->r10 == 0) {
        // 0x801A3404: lh          $t3, 0x9E($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X9E);
            goto L_801A3414;
    }
    goto skip_6;
    // 0x801A3404: lh          $t3, 0x9E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X9E);
    skip_6:
    // 0x801A3408: jal         0x800BA808
    // 0x801A340C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_10;
    // 0x801A340C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_10:
    // 0x801A3410: lh          $t3, 0x9E($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X9E);
L_801A3414:
    // 0x801A3414: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801A3418: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A341C: bne         $t3, $at, L_801A3454
    if (ctx->r11 != ctx->r1) {
        // 0x801A3420: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_801A3454;
    }
    // 0x801A3420: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A3424: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801A3428: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801A342C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801A3430: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801A3434: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x801A3438: sb          $t4, 0x5B44($at)
    MEM_B(0X5B44, ctx->r1) = ctx->r12;
    // 0x801A343C: ori         $a0, $a0, 0x6053
    ctx->r4 = ctx->r4 | 0X6053;
    // 0x801A3440: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801A3444: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x801A3448: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A344C: jal         0x80019218
    // 0x801A3450: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_11;
    // 0x801A3450: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_11:
L_801A3454:
    // 0x801A3454: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A3458: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A345C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A3460: jr          $ra
    // 0x801A3464: nop

    return;
    // 0x801A3464: nop

;}
RECOMP_FUNC void Area6_8018EC38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EC38: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8018EC3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018EC40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018EC44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018EC48: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018EC4C: addiu       $t7, $t7, -0xAC4
    ctx->r15 = ADD32(ctx->r15, -0XAC4);
    // 0x8018EC50: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x8018EC54: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
L_8018EC58:
    // 0x8018EC58: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018EC5C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018EC60: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018EC64: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8018EC68: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8018EC6C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8018EC70: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8018EC74: bne         $t7, $t0, L_8018EC58
    if (ctx->r15 != ctx->r8) {
        // 0x8018EC78: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8018EC58;
    }
    // 0x8018EC78: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8018EC7C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x8018EC80: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018EC84: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018EC88: lw          $t2, 0x78B4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78B4);
    // 0x8018EC8C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018EC90: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8018EC94: blez        $t2, L_8018ED64
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8018EC98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018ED64;
    }
    // 0x8018EC98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018EC9C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8018ECA0: jal         0x800613C4
    // 0x8018ECA4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018ECA4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_0:
    // 0x8018ECA8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8018ECAC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8018ECB0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8018ECB4: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8018ECB8: addiu       $t4, $zero, 0xC3
    ctx->r12 = ADD32(0, 0XC3);
    // 0x8018ECBC: subu        $t5, $t5, $a1
    ctx->r13 = SUB32(ctx->r13, ctx->r5);
    // 0x8018ECC0: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x8018ECC4: sh          $t4, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r12;
    // 0x8018ECC8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8018ECCC: addiu       $t9, $sp, 0x2C
    ctx->r25 = ADD32(ctx->r29, 0X2C);
    // 0x8018ECD0: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x8018ECD4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018ECD8: lwc1        $f6, 0x74($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8018ECDC: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8018ECE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018ECE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018ECE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018ECEC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018ECF0: addiu       $t7, $a1, 0x2
    ctx->r15 = ADD32(ctx->r5, 0X2);
    // 0x8018ECF4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8018ECF8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018ECFC: lwc1        $f16, 0x78($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X78);
    // 0x8018ED00: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018ED04: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018ED08: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8018ED0C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018ED10: lwc1        $f6, 0x7C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X7C);
    // 0x8018ED14: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x8018ED18: sw          $t0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r8;
    // 0x8018ED1C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018ED20: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x8018ED24: beq         $a1, $at, L_8018ED30
    if (ctx->r5 == ctx->r1) {
        // 0x8018ED28: swc1        $f8, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
            goto L_8018ED30;
    }
    // 0x8018ED28: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8018ED2C: sw          $t7, 0x88($s0)
    MEM_W(0X88, ctx->r16) = ctx->r15;
L_8018ED30:
    // 0x8018ED30: jal         0x800612B8
    // 0x8018ED34: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8018ED34: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_1:
    // 0x8018ED38: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018ED3C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018ED40: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018ED44: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018ED48: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8018ED4C: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8018ED50: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018ED54: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018ED58: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018ED5C: jal         0x80019218
    // 0x8018ED60: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8018ED60: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
L_8018ED64:
    // 0x8018ED64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018ED68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018ED6C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8018ED70: jr          $ra
    // 0x8018ED74: nop

    return;
    // 0x8018ED74: nop

;}
RECOMP_FUNC void Solar_SoVulkain_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A68A8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801A68AC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801A68B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801A68B4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801A68B8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801A68BC: addiu       $t1, $t1, 0x2740
    ctx->r9 = ADD32(ctx->r9, 0X2740);
    // 0x801A68C0: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x801A68C4: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x801A68C8: lw          $s1, 0x78($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X78);
    // 0x801A68CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A68D0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x801A68D4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x801A68D8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x801A68DC: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801A68E0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801A68E4: addiu       $t7, $t7, -0x65C
    ctx->r15 = ADD32(ctx->r15, -0X65C);
    // 0x801A68E8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801A68EC: addiu       $t6, $sp, 0x58
    ctx->r14 = ADD32(ctx->r29, 0X58);
    // 0x801A68F0: lw          $t3, 0x4($t7)
    ctx->r11 = MEM_W(ctx->r15, 0X4);
    // 0x801A68F4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801A68F8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801A68FC: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801A6900: addiu       $t5, $t5, -0x650
    ctx->r13 = ADD32(ctx->r13, -0X650);
    // 0x801A6904: sw          $t3, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r11;
    // 0x801A6908: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801A690C: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x801A6910: addiu       $t4, $sp, 0x4C
    ctx->r12 = ADD32(ctx->r29, 0X4C);
    // 0x801A6914: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x801A6918: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x801A691C: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x801A6920: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801A6924: addiu       $t3, $t3, -0x644
    ctx->r11 = ADD32(ctx->r11, -0X644);
    // 0x801A6928: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x801A692C: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x801A6930: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x801A6934: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x801A6938: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x801A693C: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x801A6940: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x801A6944: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x801A6948: sw          $t4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r12;
    // 0x801A694C: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x801A6950: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801A6954: lui         $at, 0x4596
    ctx->r1 = S32(0X4596 << 16);
    // 0x801A6958: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A695C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801A6960: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x801A6964: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A6968: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x801A696C: lw          $t7, 0x4($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X4);
    // 0x801A6970: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x801A6974: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x801A6978: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x801A697C: sll         $t3, $t7, 24
    ctx->r11 = S32(ctx->r15 << 24);
    // 0x801A6980: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x801A6984: sll         $t5, $t6, 16
    ctx->r13 = S32(ctx->r14 << 16);
    // 0x801A6988: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x801A698C: ori         $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 | 0XFF;
    // 0x801A6990: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A6994: lwc1        $f4, 0xE4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x801A6998: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801A699C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801A69A0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801A69A4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801A69A8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801A69AC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801A69B0: bc1f        L_801A69F4
    if (!c1cs) {
        // 0x801A69B4: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_801A69F4;
    }
    // 0x801A69B4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x801A69B8: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x801A69BC: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x801A69C0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801A69C4: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x801A69C8: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    // 0x801A69CC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801A69D0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x801A69D4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A69D8: jal         0x800BA2E8
    // 0x801A69DC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    RCP_SetupDL_30(rdram, ctx);
        goto after_0;
    // 0x801A69DC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_0:
    // 0x801A69E0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801A69E4: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x801A69E8: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x801A69EC: b           L_801A6A1C
    // 0x801A69F0: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
        goto L_801A6A1C;
    // 0x801A69F0: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
L_801A69F4:
    // 0x801A69F4: lw          $t3, -0x7C28($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C28);
    // 0x801A69F8: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x801A69FC: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x801A6A00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A6A04: jal         0x800BA2E8
    // 0x801A6A08: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    RCP_SetupDL_30(rdram, ctx);
        goto after_1;
    // 0x801A6A08: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
    // 0x801A6A0C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801A6A10: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x801A6A14: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x801A6A18: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
L_801A6A1C:
    // 0x801A6A1C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x801A6A20: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x801A6A24: sltiu       $at, $t6, 0xB
    ctx->r1 = ctx->r14 < 0XB ? 1 : 0;
    // 0x801A6A28: beq         $at, $zero, L_801A6BC4
    if (ctx->r1 == 0) {
        // 0x801A6A2C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801A6BC4;
    }
    // 0x801A6A2C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801A6A30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A6A34: addu        $at, $at, $t6
    gpr jr_addend_801A6A3C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A6A38: lw          $t6, 0x1820($at)
    ctx->r14 = ADD32(ctx->r1, 0X1820);
    // 0x801A6A3C: jr          $t6
    // 0x801A6A40: nop

    switch (jr_addend_801A6A3C >> 2) {
        case 0: goto L_801A6A6C; break;
        case 1: goto L_801A6AE0; break;
        case 2: goto L_801A6AE0; break;
        case 3: goto L_801A6AE0; break;
        case 4: goto L_801A6B54; break;
        case 5: goto L_801A6B54; break;
        case 6: goto L_801A6B54; break;
        case 7: goto L_801A6BC4; break;
        case 8: goto L_801A6BC4; break;
        case 9: goto L_801A6BC4; break;
        case 10: goto L_801A6A44; break;
        default: switch_error(__func__, 0x801A6A3C, 0x801C1820);
    }
    // 0x801A6A40: nop

L_801A6A44:
    // 0x801A6A44: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801A6A48: addiu       $v0, $v0, 0x2768
    ctx->r2 = ADD32(ctx->r2, 0X2768);
    // 0x801A6A4C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801A6A50: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A6A54: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A6A58: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A6A5C: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x801A6A60: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A6A64: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A6A68: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_801A6A6C:
    // 0x801A6A6C: lh          $t8, 0x90($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X90);
    // 0x801A6A70: beql        $t8, $zero, L_801A6A84
    if (ctx->r24 == 0) {
        // 0x801A6A74: lh          $v0, 0x9C($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X9C);
            goto L_801A6A84;
    }
    goto skip_0;
    // 0x801A6A74: lh          $v0, 0x9C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X9C);
    skip_0:
    // 0x801A6A78: b           L_801A6BC4
    // 0x801A6A7C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_801A6BC4;
    // 0x801A6A7C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801A6A80: lh          $v0, 0x9C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X9C);
L_801A6A84:
    // 0x801A6A84: beq         $v0, $zero, L_801A6BC4
    if (ctx->r2 == 0) {
        // 0x801A6A88: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_801A6BC4;
    }
    // 0x801A6A88: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x801A6A8C: beq         $t7, $zero, L_801A6AC8
    if (ctx->r15 == 0) {
        // 0x801A6A90: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_801A6AC8;
    }
    // 0x801A6A90: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A6A94: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801A6A98: lui         $t3, 0x2020
    ctx->r11 = S32(0X2020 << 16);
    // 0x801A6A9C: ori         $t3, $t3, 0x80FF
    ctx->r11 = ctx->r11 | 0X80FF;
    // 0x801A6AA0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A6AA4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801A6AA8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801A6AAC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A6AB0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A6AB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A6AB8: nop

    // 0x801A6ABC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A6AC0: b           L_801A6BC4
    // 0x801A6AC4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_801A6BC4;
    // 0x801A6AC4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_801A6AC8:
    // 0x801A6AC8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A6ACC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A6AD0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A6AD4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A6AD8: b           L_801A6BC4
    // 0x801A6ADC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_801A6BC4;
    // 0x801A6ADC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_801A6AE0:
    // 0x801A6AE0: lh          $t4, 0x8C($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X8C);
    // 0x801A6AE4: bnel        $t4, $zero, L_801A6AF4
    if (ctx->r12 != 0) {
        // 0x801A6AE8: lh          $v0, 0x98($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X98);
            goto L_801A6AF4;
    }
    goto skip_1;
    // 0x801A6AE8: lh          $v0, 0x98($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X98);
    skip_1:
    // 0x801A6AEC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801A6AF0: lh          $v0, 0x98($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X98);
L_801A6AF4:
    // 0x801A6AF4: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x801A6AF8: beql        $t5, $zero, L_801A6BC8
    if (ctx->r13 == 0) {
        // 0x801A6AFC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801A6BC8;
    }
    goto skip_2;
    // 0x801A6AFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x801A6B00: beq         $t5, $zero, L_801A6B3C
    if (ctx->r13 == 0) {
        // 0x801A6B04: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_801A6B3C;
    }
    // 0x801A6B04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A6B08: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801A6B0C: lui         $t8, 0x2020
    ctx->r24 = S32(0X2020 << 16);
    // 0x801A6B10: ori         $t8, $t8, 0x80FF
    ctx->r24 = ctx->r24 | 0X80FF;
    // 0x801A6B14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A6B18: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801A6B1C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A6B20: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A6B24: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A6B28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A6B2C: nop

    // 0x801A6B30: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A6B34: b           L_801A6BC4
    // 0x801A6B38: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
        goto L_801A6BC4;
    // 0x801A6B38: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
L_801A6B3C:
    // 0x801A6B3C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A6B40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A6B44: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A6B48: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A6B4C: b           L_801A6BC4
    // 0x801A6B50: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
        goto L_801A6BC4;
    // 0x801A6B50: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_801A6B54:
    // 0x801A6B54: lh          $t7, 0x8E($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X8E);
    // 0x801A6B58: bnel        $t7, $zero, L_801A6B68
    if (ctx->r15 != 0) {
        // 0x801A6B5C: lh          $v0, 0x9A($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X9A);
            goto L_801A6B68;
    }
    goto skip_3;
    // 0x801A6B5C: lh          $v0, 0x9A($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X9A);
    skip_3:
    // 0x801A6B60: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801A6B64: lh          $v0, 0x9A($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X9A);
L_801A6B68:
    // 0x801A6B68: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x801A6B6C: beql        $t9, $zero, L_801A6BC8
    if (ctx->r25 == 0) {
        // 0x801A6B70: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801A6BC8;
    }
    goto skip_4;
    // 0x801A6B70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x801A6B74: beq         $t9, $zero, L_801A6BB0
    if (ctx->r25 == 0) {
        // 0x801A6B78: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_801A6BB0;
    }
    // 0x801A6B78: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A6B7C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801A6B80: lui         $t4, 0x2020
    ctx->r12 = S32(0X2020 << 16);
    // 0x801A6B84: ori         $t4, $t4, 0x80FF
    ctx->r12 = ctx->r12 | 0X80FF;
    // 0x801A6B88: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A6B8C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801A6B90: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A6B94: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A6B98: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A6B9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A6BA0: nop

    // 0x801A6BA4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A6BA8: b           L_801A6BC4
    // 0x801A6BAC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
        goto L_801A6BC4;
    // 0x801A6BAC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
L_801A6BB0:
    // 0x801A6BB0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A6BB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A6BB8: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A6BBC: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A6BC0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_801A6BC4:
    // 0x801A6BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801A6BC8:
    // 0x801A6BC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A6BCC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801A6BD0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801A6BD4: jr          $ra
    // 0x801A6BD8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801A6BD8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Aquas_801A958C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A958C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x801A9590: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801A9594: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A9598: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801A959C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A95A0: nop

    // 0x801A95A4: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A95A8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x801A95AC: nop

    // 0x801A95B0: bc1fl       L_801A95C0
    if (!c1cs) {
        // 0x801A95B4: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_801A95C0;
    }
    goto skip_0;
    // 0x801A95B4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x801A95B8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x801A95BC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801A95C0:
    // 0x801A95C0: jr          $ra
    // 0x801A95C4: nop

    return;
    // 0x801A95C4: nop

;}
RECOMP_FUNC void Aquas_AqBump2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BE1FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801BE200: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BE204: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801BE208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801BE20C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801BE210: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BE214: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801BE218: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801BE21C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801BE220: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801BE224: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801BE228: jal         0x80005C34
    // 0x801BE22C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x801BE22C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x801BE230: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801BE234: jal         0x80006EB8
    // 0x801BE238: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x801BE238: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x801BE23C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801BE240: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801BE244: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801BE248: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x801BE24C: addiu       $t9, $t9, -0x1110
    ctx->r25 = ADD32(ctx->r25, -0X1110);
    // 0x801BE250: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801BE254: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801BE258: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801BE25C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801BE260: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801BE264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801BE268: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801BE26C: jr          $ra
    // 0x801BE270: nop

    return;
    // 0x801BE270: nop

;}
RECOMP_FUNC void Solar_801A0DF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0DF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A0DFC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A0E00: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x801A0E04: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x801A0E08: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801A0E0C: sltiu       $at, $a3, 0x5
    ctx->r1 = ctx->r7 < 0X5 ? 1 : 0;
    // 0x801A0E10: beq         $at, $zero, L_801A0EC8
    if (ctx->r1 == 0) {
        // 0x801A0E14: sw          $a3, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r7;
            goto L_801A0EC8;
    }
    // 0x801A0E14: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x801A0E18: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x801A0E1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A0E20: addu        $at, $at, $t6
    gpr jr_addend_801A0E28 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A0E24: lw          $t6, 0x15AC($at)
    ctx->r14 = ADD32(ctx->r1, 0X15AC);
    // 0x801A0E28: jr          $t6
    // 0x801A0E2C: nop

    switch (jr_addend_801A0E28 >> 2) {
        case 0: goto L_801A0E30; break;
        case 1: goto L_801A0EA8; break;
        case 2: goto L_801A0EB4; break;
        case 3: goto L_801A0EC0; break;
        case 4: goto L_801A0EA8; break;
        default: switch_error(__func__, 0x801A0E28, 0x801C15AC);
    }
    // 0x801A0E2C: nop

L_801A0E30:
    // 0x801A0E30: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A0E34: lw          $t7, 0x7A10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7A10);
    // 0x801A0E38: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801A0E3C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x801A0E40: beq         $t7, $zero, L_801A0E78
    if (ctx->r15 == 0) {
        // 0x801A0E44: nop
    
            goto L_801A0E78;
    }
    // 0x801A0E44: nop

    // 0x801A0E48: jal         0x80004EB0
    // 0x801A0E4C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801A0E4C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_0:
    // 0x801A0E50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A0E54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A0E58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A0E5C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801A0E60: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801A0E64: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x801A0E68: nop

    // 0x801A0E6C: addiu       $t1, $t0, 0x80
    ctx->r9 = ADD32(ctx->r8, 0X80);
    // 0x801A0E70: b           L_801A0EC8
    // 0x801A0E74: sw          $t1, 0x7A14($at)
    MEM_W(0X7A14, ctx->r1) = ctx->r9;
        goto L_801A0EC8;
    // 0x801A0E74: sw          $t1, 0x7A14($at)
    MEM_W(0X7A14, ctx->r1) = ctx->r9;
L_801A0E78:
    // 0x801A0E78: jal         0x80004EB0
    // 0x801A0E7C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801A0E7C: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    after_1:
    // 0x801A0E80: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A0E84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A0E88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A0E8C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801A0E90: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801A0E94: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x801A0E98: nop

    // 0x801A0E9C: addiu       $t5, $t4, 0x80
    ctx->r13 = ADD32(ctx->r12, 0X80);
    // 0x801A0EA0: b           L_801A0EC8
    // 0x801A0EA4: sw          $t5, 0x7A10($at)
    MEM_W(0X7A10, ctx->r1) = ctx->r13;
        goto L_801A0EC8;
    // 0x801A0EA4: sw          $t5, 0x7A10($at)
    MEM_W(0X7A10, ctx->r1) = ctx->r13;
L_801A0EA8:
    // 0x801A0EA8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x801A0EAC: b           L_801A0EC8
    // 0x801A0EB0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
        goto L_801A0EC8;
    // 0x801A0EB0: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
L_801A0EB4:
    // 0x801A0EB4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801A0EB8: b           L_801A0EC8
    // 0x801A0EBC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
        goto L_801A0EC8;
    // 0x801A0EBC: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
L_801A0EC0:
    // 0x801A0EC0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801A0EC4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_801A0EC8:
    // 0x801A0EC8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x801A0ECC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x801A0ED0: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x801A0ED4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801A0ED8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801A0EDC: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x801A0EE0: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801A0EE4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801A0EE8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801A0EEC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801A0EF0: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x801A0EF4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A0EF8: jal         0x800613C4
    // 0x801A0EFC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_2;
    // 0x801A0EFC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x801A0F00: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801A0F04: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x801A0F08: addiu       $t3, $zero, 0x117
    ctx->r11 = ADD32(0, 0X117);
    // 0x801A0F0C: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    // 0x801A0F10: sb          $t2, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r10;
    // 0x801A0F14: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x801A0F18: jal         0x800612B8
    // 0x801A0F1C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x801A0F1C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    after_3:
    // 0x801A0F20: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801A0F24: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x801A0F28: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A0F2C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A0F30: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A0F34: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801A0F38: sh          $zero, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = 0;
    // 0x801A0F3C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801A0F40: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x801A0F44: beq         $t4, $at, L_801A0F64
    if (ctx->r12 == ctx->r1) {
        // 0x801A0F48: swc1        $f8, 0x14($a2)
        MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
            goto L_801A0F64;
    }
    // 0x801A0F48: swc1        $f8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
    // 0x801A0F4C: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x801A0F50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A0F54: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A0F58: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801A0F5C: b           L_801A0FC4
    // 0x801A0F60: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
        goto L_801A0FC4;
    // 0x801A0F60: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
L_801A0F64:
    // 0x801A0F64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801A0F68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A0F6C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A0F70: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x801A0F74: addiu       $a0, $a2, 0x100
    ctx->r4 = ADD32(ctx->r6, 0X100);
    // 0x801A0F78: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A0F7C: sh          $zero, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = 0;
    // 0x801A0F80: sh          $t5, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r13;
    // 0x801A0F84: sh          $zero, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = 0;
    // 0x801A0F88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801A0F8C: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x801A0F90: jal         0x8005F0E8
    // 0x801A0F94: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    Object_SetSfxSourceToPos(rdram, ctx);
        goto after_4;
    // 0x801A0F94: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    after_4:
    // 0x801A0F98: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A0F9C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801A0FA0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A0FA4: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x801A0FA8: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x801A0FAC: ori         $a0, $a0, 0x5053
    ctx->r4 = ctx->r4 | 0X5053;
    // 0x801A0FB0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801A0FB4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A0FB8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801A0FBC: jal         0x80019218
    // 0x801A0FC0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x801A0FC0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_801A0FC4:
    // 0x801A0FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A0FC8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A0FCC: jr          $ra
    // 0x801A0FD0: nop

    return;
    // 0x801A0FD0: nop

;}
RECOMP_FUNC void Zoness_ZoTanker_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B1F0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8019B1F4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8019B1F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8019B1FC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8019B200: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8019B204: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8019B208: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8019B20C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8019B210: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8019B214: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8019B218: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8019B21C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019B220: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8019B224: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019B228: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8019B22C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B230: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8019B234: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B238: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B23C: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    // 0x8019B240: swc1        $f6, 0x110($s1)
    MEM_W(0X110, ctx->r17) = ctx->f6.u32l;
    // 0x8019B244: lwc1        $f10, 0x124C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X124C);
    // 0x8019B248: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8019B24C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019B250: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019B254: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019B258: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019B25C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019B260: jal         0x80005E90
    // 0x8019B264: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8019B264: nop

    after_0:
    // 0x8019B268: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019B26C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019B270: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019B274: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x8019B278: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8019B27C: lwc1        $f18, 0x18($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8019B280: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8019B284: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x8019B288: jal         0x80006A20
    // 0x8019B28C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x8019B28C: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8019B290: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019B294: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019B298: lwc1        $f12, 0x10($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8019B29C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8019B2A0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019B2A4: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x8019B2A8: swc1        $f4, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f4.u32l;
    // 0x8019B2AC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8019B2B0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8019B2B4: swc1        $f8, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f8.u32l;
    // 0x8019B2B8: bc1f        L_8019B2FC
    if (!c1cs) {
        // 0x8019B2BC: swc1        $f6, 0xF0($s1)
        MEM_W(0XF0, ctx->r17) = ctx->f6.u32l;
            goto L_8019B2FC;
    }
    // 0x8019B2BC: swc1        $f6, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f6.u32l;
    // 0x8019B2C0: div.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f14.fl);
    // 0x8019B2C4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019B2C8: sh          $t6, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r14;
    // 0x8019B2CC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019B2D0: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8019B2D4: jal         0x80004E20
    // 0x8019B2D8: sw          $t8, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r24;
    Math_ModF(rdram, ctx);
        goto after_2;
    // 0x8019B2D8: sw          $t8, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->r24;
    after_2:
    // 0x8019B2DC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019B2E0: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8019B2E4: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x8019B2E8: nop

    // 0x8019B2EC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8019B2F0: nop

    // 0x8019B2F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019B2F8: swc1        $f6, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f6.u32l;
L_8019B2FC:
    // 0x8019B2FC: sll         $t1, $zero, 2
    ctx->r9 = S32(0 << 2);
    // 0x8019B300: subu        $t1, $t1, $zero
    ctx->r9 = SUB32(ctx->r9, 0);
    // 0x8019B304: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B308: lwc1        $f22, 0x1250($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X1250);
    // 0x8019B30C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8019B310: subu        $t1, $t1, $zero
    ctx->r9 = SUB32(ctx->r9, 0);
    // 0x8019B314: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8019B318: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8019B31C: addiu       $t2, $t2, 0x3FE0
    ctx->r10 = ADD32(ctx->r10, 0X3FE0);
    // 0x8019B320: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x8019B324: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x8019B328: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019B32C: addiu       $fp, $fp, -0x7FC
    ctx->r30 = ADD32(ctx->r30, -0X7FC);
    // 0x8019B330: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x8019B334: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8019B338: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8019B33C: addiu       $s7, $sp, 0x84
    ctx->r23 = ADD32(ctx->r29, 0X84);
    // 0x8019B340: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
L_8019B344:
    // 0x8019B344: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x8019B348: subu        $v0, $v0, $s3
    ctx->r2 = SUB32(ctx->r2, ctx->r19);
    // 0x8019B34C: bne         $t3, $zero, L_8019B4C0
    if (ctx->r11 != 0) {
        // 0x8019B350: sll         $v0, $v0, 2
        ctx->r2 = S32(ctx->r2 << 2);
            goto L_8019B4C0;
    }
    // 0x8019B350: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8019B354: lh          $t5, 0xB8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XB8);
    // 0x8019B358: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x8019B35C: addu        $s2, $s1, $t4
    ctx->r18 = ADD32(ctx->r17, ctx->r12);
    // 0x8019B360: bne         $t5, $zero, L_8019B38C
    if (ctx->r13 != 0) {
        // 0x8019B364: addiu       $s5, $s0, 0x1C
        ctx->r21 = ADD32(ctx->r16, 0X1C);
            goto L_8019B38C;
    }
    // 0x8019B364: addiu       $s5, $s0, 0x1C
    ctx->r21 = ADD32(ctx->r16, 0X1C);
    // 0x8019B368: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019B36C: addiu       $t6, $t6, -0x8BC
    ctx->r14 = ADD32(ctx->r14, -0X8BC);
    // 0x8019B370: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019B374: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019B378: addu        $a1, $v0, $t6
    ctx->r5 = ADD32(ctx->r2, ctx->r14);
    // 0x8019B37C: jal         0x80006970
    // 0x8019B380: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x8019B380: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x8019B384: b           L_8019B3A8
    // 0x8019B388: nop

        goto L_8019B3A8;
    // 0x8019B388: nop

L_8019B38C:
    // 0x8019B38C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019B390: addiu       $t7, $t7, -0x898
    ctx->r15 = ADD32(ctx->r15, -0X898);
    // 0x8019B394: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019B398: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019B39C: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8019B3A0: jal         0x80006970
    // 0x8019B3A4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8019B3A4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_4:
L_8019B3A8:
    // 0x8019B3A8: jal         0x800613C4
    // 0x8019B3AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_5;
    // 0x8019B3AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8019B3B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019B3B4: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x8019B3B8: lh          $t9, 0xB8($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XB8);
    // 0x8019B3BC: addiu       $t0, $zero, 0xFB
    ctx->r8 = ADD32(0, 0XFB);
    // 0x8019B3C0: addiu       $t1, $zero, 0x309
    ctx->r9 = ADD32(0, 0X309);
    // 0x8019B3C4: bne         $t9, $zero, L_8019B3D8
    if (ctx->r25 != 0) {
        // 0x8019B3C8: addiu       $t2, $zero, 0xFD
        ctx->r10 = ADD32(0, 0XFD);
            goto L_8019B3D8;
    }
    // 0x8019B3C8: addiu       $t2, $zero, 0xFD
    ctx->r10 = ADD32(0, 0XFD);
    // 0x8019B3CC: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x8019B3D0: b           L_8019B3DC
    // 0x8019B3D4: sw          $t1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r9;
        goto L_8019B3DC;
    // 0x8019B3D4: sw          $t1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r9;
L_8019B3D8:
    // 0x8019B3D8: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
L_8019B3DC:
    // 0x8019B3DC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019B3E0: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8019B3E4: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8019B3E8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8019B3EC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019B3F0: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019B3F4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8019B3F8: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8019B3FC: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019B400: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019B404: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8019B408: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019B40C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019B410: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8019B414: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8019B418: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8019B41C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019B420: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x8019B424: nop

    // 0x8019B428: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x8019B42C: sw          $t5, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r13;
    // 0x8019B430: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8019B434: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8019B438: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8019B43C: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    // 0x8019B440: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019B444: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019B448: lw          $t8, -0x874($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X874);
    // 0x8019B44C: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
    // 0x8019B450: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8019B454: sw          $s3, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r19;
    // 0x8019B458: jal         0x800612B8
    // 0x8019B45C: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x8019B45C: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    after_6:
    // 0x8019B460: lh          $t0, 0xB8($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XB8);
    // 0x8019B464: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8019B468: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8019B46C: beql        $t0, $zero, L_8019B4C0
    if (ctx->r8 == 0) {
        // 0x8019B470: sw          $s4, 0x50($s2)
        MEM_W(0X50, ctx->r18) = ctx->r20;
            goto L_8019B4C0;
    }
    goto skip_0;
    // 0x8019B470: sw          $s4, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r20;
    skip_0:
    // 0x8019B474: sh          $t1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r9;
    // 0x8019B478: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x8019B47C: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8019B480: addu        $t3, $fp, $t2
    ctx->r11 = ADD32(ctx->r30, ctx->r10);
    // 0x8019B484: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8019B488: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x8019B48C: addu        $v0, $t4, $s6
    ctx->r2 = ADD32(ctx->r12, ctx->r22);
    // 0x8019B490: c.le.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl <= ctx->f10.fl;
    // 0x8019B494: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8019B498: addu        $t6, $fp, $t5
    ctx->r14 = ADD32(ctx->r30, ctx->r13);
    // 0x8019B49C: bc1fl       L_8019B4B4
    if (!c1cs) {
        // 0x8019B4A0: lwc1        $f18, 0x0($t6)
        ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
            goto L_8019B4B4;
    }
    goto skip_1;
    // 0x8019B4A0: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    skip_1:
    // 0x8019B4A4: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8019B4A8: b           L_8019B4B8
    // 0x8019B4AC: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
        goto L_8019B4B8;
    // 0x8019B4AC: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x8019B4B0: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
L_8019B4B4:
    // 0x8019B4B4: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_8019B4B8:
    // 0x8019B4B8: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8019B4BC: sw          $s4, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r20;
L_8019B4C0:
    // 0x8019B4C0: slti        $at, $s3, 0x3
    ctx->r1 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x8019B4C4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8019B4C8: beq         $at, $zero, L_8019B4DC
    if (ctx->r1 == 0) {
        // 0x8019B4CC: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8019B4DC;
    }
    // 0x8019B4CC: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8019B4D0: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8019B4D4: bnel        $s4, $at, L_8019B344
    if (ctx->r20 != ctx->r1) {
        // 0x8019B4D8: lbu         $t3, 0x0($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X0);
            goto L_8019B344;
    }
    goto skip_2;
    // 0x8019B4D8: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    skip_2:
L_8019B4DC:
    // 0x8019B4DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019B4E0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019B4E4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019B4E8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019B4EC: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8019B4F0: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8019B4F4: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x8019B4F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019B4FC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019B500: ori         $a0, $a0, 0x203A
    ctx->r4 = ctx->r4 | 0X203A;
    // 0x8019B504: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8019B508: jal         0x80019218
    // 0x8019B50C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8019B50C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x8019B510: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8019B514: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8019B518: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8019B51C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019B520: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8019B524: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8019B528: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8019B52C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8019B530: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8019B534: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8019B538: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8019B53C: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8019B540: jr          $ra
    // 0x8019B544: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8019B544: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Aquas_BlueMarineDown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AB9B0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801AB9B4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801AB9B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801AB9BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801AB9C0: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801AB9C4: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801AB9C8: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x801AB9CC: jal         0x8007D0E0
    // 0x801AB9D0: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_0;
    // 0x801AB9D0: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    after_0:
    // 0x801AB9D4: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801AB9D8: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801AB9DC: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x801AB9E0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x801AB9E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801AB9E8: jal         0x8007B344
    // 0x801AB9EC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_1;
    // 0x801AB9EC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_1:
    // 0x801AB9F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AB9F4: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801AB9F8: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801AB9FC: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x801ABA00: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801ABA04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ABA08: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801ABA0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801ABA10: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801ABA14: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801ABA18: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801ABA1C: jal         0x8007BFFC
    // 0x801ABA20: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_2;
    // 0x801ABA20: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801ABA24: jal         0x8004D440
    // 0x801ABA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_KillPlayer(rdram, ctx);
        goto after_3;
    // 0x801ABA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801ABA2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801ABA30: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801ABA34: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801ABA38: jr          $ra
    // 0x801ABA3C: nop

    return;
    // 0x801ABA3C: nop

;}
RECOMP_FUNC void Aquas_CsAqFishGroup_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BE034: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801BE038: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801BE03C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801BE040: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801BE044: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x801BE048: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BE04C: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x801BE050: bne         $t6, $zero, L_801BE08C
    if (ctx->r14 != 0) {
        // 0x801BE054: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_801BE08C;
    }
    // 0x801BE054: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801BE058: lw          $t7, 0x58($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X58);
    // 0x801BE05C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BE060: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BE064: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801BE068: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801BE06C: swc1        $f4, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f4.u32l;
    // 0x801BE070: lwc1        $f0, 0x828($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X828);
    // 0x801BE074: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BE078: lwc1        $f6, 0x2220($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2220);
    // 0x801BE07C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801BE080: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801BE084: jal         0x8009BD38
    // 0x801BE088: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_0;
    // 0x801BE088: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
L_801BE08C:
    // 0x801BE08C: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x801BE090: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x801BE094: addiu       $a0, $a0, 0x35E0
    ctx->r4 = ADD32(ctx->r4, 0X35E0);
    // 0x801BE098: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801BE09C: jal         0x8009ACDC
    // 0x801BE0A0: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
    Animation_GetFrameCount(rdram, ctx);
        goto after_1;
    // 0x801BE0A0: sw          $t0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r8;
    after_1:
    // 0x801BE0A4: lw          $t1, 0x50($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X50);
    // 0x801BE0A8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801BE0AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801BE0B0: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801BE0B4: bne         $at, $zero, L_801BE0C0
    if (ctx->r1 != 0) {
        // 0x801BE0B8: nop
    
            goto L_801BE0C0;
    }
    // 0x801BE0B8: nop

    // 0x801BE0BC: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_801BE0C0:
    // 0x801BE0C0: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x801BE0C4: lw          $t3, 0x1D0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X1D0);
    // 0x801BE0C8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x801BE0CC: bnel        $at, $zero, L_801BE0E0
    if (ctx->r1 != 0) {
        // 0x801BE0D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801BE0E0;
    }
    goto skip_0;
    // 0x801BE0D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801BE0D4: jal         0x80060FBC
    // 0x801BE0D8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x801BE0D8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_2:
    // 0x801BE0DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801BE0E0:
    // 0x801BE0E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801BE0E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801BE0E8: jr          $ra
    // 0x801BE0EC: nop

    return;
    // 0x801BE0EC: nop

;}
RECOMP_FUNC void Aquas_AqFishGroup_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BDE6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801BDE70: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801BDE74: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801BDE78: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801BDE7C: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x801BDE80: lh          $a1, 0xB6($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XB6);
    // 0x801BDE84: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    // 0x801BDE88: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x801BDE8C: jal         0x8009AA20
    // 0x801BDE90: addiu       $a0, $a0, 0x35E0
    ctx->r4 = ADD32(ctx->r4, 0X35E0);
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x801BDE90: addiu       $a0, $a0, 0x35E0
    ctx->r4 = ADD32(ctx->r4, 0X35E0);
    after_0:
    // 0x801BDE94: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    // 0x801BDE98: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801BDE9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BDEA0: bne         $t6, $zero, L_801BDEDC
    if (ctx->r14 != 0) {
        // 0x801BDEA4: lui         $a1, 0x601
        ctx->r5 = S32(0X601 << 16);
            goto L_801BDEDC;
    }
    // 0x801BDEA4: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801BDEA8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801BDEAC: addiu       $t7, $t7, 0x4660
    ctx->r15 = ADD32(ctx->r15, 0X4660);
    // 0x801BDEB0: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801BDEB4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801BDEB8: addiu       $a3, $a3, -0x2204
    ctx->r7 = ADD32(ctx->r7, -0X2204);
    // 0x801BDEBC: addiu       $a1, $a1, 0x36CC
    ctx->r5 = ADD32(ctx->r5, 0X36CC);
    // 0x801BDEC0: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801BDEC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BDEC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801BDECC: jal         0x8009A72C
    // 0x801BDED0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x801BDED0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_1:
    // 0x801BDED4: b           L_801BDF04
    // 0x801BDED8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801BDF04;
    // 0x801BDED8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801BDEDC:
    // 0x801BDEDC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801BDEE0: addiu       $t8, $t8, 0x4660
    ctx->r24 = ADD32(ctx->r24, 0X4660);
    // 0x801BDEE4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801BDEE8: addiu       $a3, $a3, -0x2204
    ctx->r7 = ADD32(ctx->r7, -0X2204);
    // 0x801BDEEC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801BDEF0: addiu       $a1, $a1, 0x37CC
    ctx->r5 = ADD32(ctx->r5, 0X37CC);
    // 0x801BDEF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801BDEF8: jal         0x8009A72C
    // 0x801BDEFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x801BDEFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_2:
    // 0x801BDF00: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801BDF04:
    // 0x801BDF04: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801BDF08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801BDF0C: jr          $ra
    // 0x801BDF10: nop

    return;
    // 0x801BDF10: nop

;}
RECOMP_FUNC void Aquas_AqSculpin_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B4DDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801B4DE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801B4DE4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801B4DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801B4DEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801B4DF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801B4DF4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801B4DF8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801B4DFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801B4E00: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x801B4E04: lhu         $t7, 0xC6($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XC6);
    // 0x801B4E08: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801B4E0C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x801B4E10: bne         $t8, $zero, L_801B4E50
    if (ctx->r24 != 0) {
        // 0x801B4E14: nop
    
            goto L_801B4E50;
    }
    // 0x801B4E14: nop

    // 0x801B4E18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801B4E1C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801B4E20: jal         0x800B8DD0
    // 0x801B4E24: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801B4E24: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801B4E28: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801B4E2C: blez        $a2, L_801B4E80
    if (SIGNED(ctx->r6) <= 0) {
        // 0x801B4E30: slti        $at, $a2, 0x5
        ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
            goto L_801B4E80;
    }
    // 0x801B4E30: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x801B4E34: beq         $at, $zero, L_801B4E80
    if (ctx->r1 == 0) {
        // 0x801B4E38: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801B4E80;
    }
    // 0x801B4E38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801B4E3C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801B4E40: jal         0x800B8DD0
    // 0x801B4E44: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801B4E44: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_1:
    // 0x801B4E48: b           L_801B4E84
    // 0x801B4E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801B4E84;
    // 0x801B4E4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801B4E50:
    // 0x801B4E50: jal         0x800B8DD0
    // 0x801B4E54: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801B4E54: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_2:
    // 0x801B4E58: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801B4E5C: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x801B4E60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801B4E64: lui         $t1, 0xFF00
    ctx->r9 = S32(0XFF00 << 16);
    // 0x801B4E68: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801B4E6C: sw          $t9, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r25;
    // 0x801B4E70: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x801B4E74: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801B4E78: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801B4E7C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
L_801B4E80:
    // 0x801B4E80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801B4E84:
    // 0x801B4E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801B4E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801B4E8C: jr          $ra
    // 0x801B4E90: nop

    return;
    // 0x801B4E90: nop

;}
RECOMP_FUNC void Aquas_801A9DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9DE4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801A9DE8: addiu       $v1, $v1, 0x4190
    ctx->r3 = ADD32(ctx->r3, 0X4190);
    // 0x801A9DEC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801A9DF0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801A9DF4: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x801A9DF8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801A9DFC: bne         $t6, $at, L_801A9EC8
    if (ctx->r14 != ctx->r1) {
        // 0x801A9E00: addiu       $a1, $a1, -0xEF0
        ctx->r5 = ADD32(ctx->r5, -0XEF0);
            goto L_801A9EC8;
    }
    // 0x801A9E00: addiu       $a1, $a1, -0xEF0
    ctx->r5 = ADD32(ctx->r5, -0XEF0);
    // 0x801A9E04: lbu         $t7, 0x0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X0);
    // 0x801A9E08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A9E0C: bnel        $t7, $at, L_801A9E64
    if (ctx->r15 != ctx->r1) {
        // 0x801A9E10: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_801A9E64;
    }
    goto skip_0;
    // 0x801A9E10: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    skip_0:
    // 0x801A9E14: lh          $t8, 0x60($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X60);
    // 0x801A9E18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A9E1C: beql        $t8, $zero, L_801A9E64
    if (ctx->r24 == 0) {
        // 0x801A9E20: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_801A9E64;
    }
    goto skip_1;
    // 0x801A9E20: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    skip_1:
    // 0x801A9E24: lwc1        $f0, 0x4330($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4330);
    // 0x801A9E28: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801A9E2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A9E30: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801A9E34: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x801A9E38: nop

    // 0x801A9E3C: bc1tl       L_801A9E64
    if (c1cs) {
        // 0x801A9E40: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_801A9E64;
    }
    goto skip_2;
    // 0x801A9E40: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    skip_2:
    // 0x801A9E44: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x801A9E48: addiu       $at, $zero, 0x79
    ctx->r1 = ADD32(0, 0X79);
    // 0x801A9E4C: bnel        $v0, $at, L_801A9E7C
    if (ctx->r2 != ctx->r1) {
        // 0x801A9E50: lw          $t0, 0x28($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X28);
            goto L_801A9E7C;
    }
    goto skip_3;
    // 0x801A9E50: lw          $t0, 0x28($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X28);
    skip_3:
    // 0x801A9E54: lh          $t9, 0xA0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XA0);
    // 0x801A9E58: bnel        $t9, $zero, L_801A9E7C
    if (ctx->r25 != 0) {
        // 0x801A9E5C: lw          $t0, 0x28($a1)
        ctx->r8 = MEM_W(ctx->r5, 0X28);
            goto L_801A9E7C;
    }
    goto skip_4;
    // 0x801A9E5C: lw          $t0, 0x28($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X28);
    skip_4:
    // 0x801A9E60: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_801A9E64:
    // 0x801A9E64: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x801A9E68: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x801A9E6C: sw          $zero, 0x10($v1)
    MEM_W(0X10, ctx->r3) = 0;
    // 0x801A9E70: jr          $ra
    // 0x801A9E74: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    return;
    // 0x801A9E74: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801A9E78: lw          $t0, 0x28($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X28);
L_801A9E7C:
    // 0x801A9E7C: addiu       $v1, $v0, -0x2
    ctx->r3 = ADD32(ctx->r2, -0X2);
    // 0x801A9E80: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x801A9E84: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x801A9E88: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x801A9E8C: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801A9E90: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801A9E94: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801A9E98: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A9E9C: addiu       $a2, $a2, 0x41B8
    ctx->r6 = ADD32(ctx->r6, 0X41B8);
    // 0x801A9EA0: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x801A9EA4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801A9EA8: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801A9EAC: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
    // 0x801A9EB0: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801A9EB4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A9EB8: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x801A9EBC: lwc1        $f16, 0x10($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801A9EC0: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801A9EC4: swc1        $f18, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f18.u32l;
L_801A9EC8:
    // 0x801A9EC8: jr          $ra
    // 0x801A9ECC: nop

    return;
    // 0x801A9ECC: nop

;}
RECOMP_FUNC void Aquas_Update360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BEC80: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801BEC84: jr          $ra
    // 0x801BEC88: nop

    return;
    // 0x801BEC88: nop

;}
RECOMP_FUNC void Area6_8018A2C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A2C4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018A2C8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018A2CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018A2D0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018A2D4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8018A2D8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8018A2DC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8018A2E0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8018A2E4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8018A2E8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8018A2EC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018A2F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018A2F4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018A2F8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018A2FC: lui         $s5, 0x2903
    ctx->r21 = S32(0X2903 << 16);
    // 0x8018A300: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018A304: ori         $s5, $s5, 0x4003
    ctx->r21 = ctx->r21 | 0X4003;
    // 0x8018A308: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018A30C: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018A310: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x8018A314: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8018A318: addiu       $s4, $sp, 0x58
    ctx->r20 = ADD32(ctx->r29, 0X58);
L_8018A31C:
    // 0x8018A31C: lh          $t6, 0x66($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X66);
    // 0x8018A320: addiu       $s3, $s1, 0x1
    ctx->r19 = ADD32(ctx->r17, 0X1);
    // 0x8018A324: bne         $s3, $t6, L_8018A428
    if (ctx->r19 != ctx->r14) {
        // 0x8018A328: nop
    
            goto L_8018A428;
    }
    // 0x8018A328: nop

    // 0x8018A32C: lh          $t7, 0x4E($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X4E);
    // 0x8018A330: bne         $fp, $t7, L_8018A428
    if (ctx->r30 != ctx->r15) {
        // 0x8018A334: nop
    
            goto L_8018A428;
    }
    // 0x8018A334: nop

    // 0x8018A338: lwc1        $f4, 0xD8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XD8);
    // 0x8018A33C: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x8018A340: addu        $s0, $s2, $t8
    ctx->r16 = ADD32(ctx->r18, ctx->r24);
    // 0x8018A344: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x8018A348: nop

    // 0x8018A34C: bc1f        L_8018A428
    if (!c1cs) {
        // 0x8018A350: nop
    
            goto L_8018A428;
    }
    // 0x8018A350: nop

    // 0x8018A354: lh          $v0, 0xAC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XAC);
    // 0x8018A358: beq         $s6, $v0, L_8018A428
    if (ctx->r22 == ctx->r2) {
        // 0x8018A35C: nop
    
            goto L_8018A428;
    }
    // 0x8018A35C: nop

    // 0x8018A360: beq         $s7, $v0, L_8018A428
    if (ctx->r23 == ctx->r2) {
        // 0x8018A364: addiu       $t9, $zero, 0xF
        ctx->r25 = ADD32(0, 0XF);
            goto L_8018A428;
    }
    // 0x8018A364: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8018A368: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x8018A36C: sh          $t9, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r25;
    // 0x8018A370: sh          $t0, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = ctx->r8;
    // 0x8018A374: lh          $t2, 0x64($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X64);
    // 0x8018A378: lh          $t1, 0xCA($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCA);
    // 0x8018A37C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A380: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8018A384: bne         $s1, $zero, L_8018A3B4
    if (ctx->r17 != 0) {
        // 0x8018A388: sh          $t3, 0xCA($s0)
        MEM_H(0XCA, ctx->r16) = ctx->r11;
            goto L_8018A3B4;
    }
    // 0x8018A388: sh          $t3, 0xCA($s0)
    MEM_H(0XCA, ctx->r16) = ctx->r11;
    // 0x8018A38C: lwc1        $f6, -0xCCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XCCC);
    // 0x8018A390: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A394: lwc1        $f8, -0xC3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XC3C);
    // 0x8018A398: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8018A39C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018A3A0: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8018A3A4: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018A3A8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8018A3AC: jal         0x8007A6F0
    // 0x8018A3B0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_0;
    // 0x8018A3B0: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_0:
L_8018A3B4:
    // 0x8018A3B4: bne         $s1, $s6, L_8018A3E4
    if (ctx->r17 != ctx->r22) {
        // 0x8018A3B8: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8018A3E4;
    }
    // 0x8018A3B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A3BC: lwc1        $f16, -0xC9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XC9C);
    // 0x8018A3C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A3C4: lwc1        $f18, -0xC0C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XC0C);
    // 0x8018A3C8: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8018A3CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018A3D0: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x8018A3D4: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018A3D8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8018A3DC: jal         0x8007A6F0
    // 0x8018A3E0: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_1;
    // 0x8018A3E0: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    after_1:
L_8018A3E4:
    // 0x8018A3E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018A3E8: bne         $s1, $at, L_8018A418
    if (ctx->r17 != ctx->r1) {
        // 0x8018A3EC: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8018A418;
    }
    // 0x8018A3EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A3F0: lwc1        $f6, -0xC6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XC6C);
    // 0x8018A3F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A3F8: lwc1        $f8, -0xBDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XBDC);
    // 0x8018A3FC: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8018A400: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018A404: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8018A408: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8018A40C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8018A410: jal         0x8007A6F0
    // 0x8018A414: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_2;
    // 0x8018A414: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_2:
L_8018A418:
    // 0x8018A418: lh          $t4, 0xCA($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XCA);
    // 0x8018A41C: bgez        $t4, L_8018A428
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8018A420: nop
    
            goto L_8018A428;
    }
    // 0x8018A420: nop

    // 0x8018A424: sh          $zero, 0xCA($s0)
    MEM_H(0XCA, ctx->r16) = 0;
L_8018A428:
    // 0x8018A428: bne         $s3, $s7, L_8018A31C
    if (ctx->r19 != ctx->r23) {
        // 0x8018A42C: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_8018A31C;
    }
    // 0x8018A42C: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x8018A430: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018A434: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018A438: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018A43C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018A440: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018A444: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8018A448: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8018A44C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8018A450: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8018A454: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8018A458: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8018A45C: jr          $ra
    // 0x8018A460: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8018A460: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Area6_8018D694(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D694: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018D698: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D69C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018D6A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018D6A4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8018D6A8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018D6AC: addiu       $t7, $t7, -0xB24
    ctx->r15 = ADD32(ctx->r15, -0XB24);
    // 0x8018D6B0: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x8018D6B4: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
L_8018D6B8:
    // 0x8018D6B8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018D6BC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8018D6C0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018D6C4: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8018D6C8: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8018D6CC: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8018D6D0: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8018D6D4: bne         $t7, $t0, L_8018D6B8
    if (ctx->r15 != ctx->r8) {
        // 0x8018D6D8: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8018D6B8;
    }
    // 0x8018D6D8: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8018D6DC: jal         0x800613C4
    // 0x8018D6E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018D6E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018D6E4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018D6E8: addiu       $t2, $zero, 0xC3
    ctx->r10 = ADD32(0, 0XC3);
    // 0x8018D6EC: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
    // 0x8018D6F0: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x8018D6F4: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8018D6F8: addiu       $t5, $sp, 0x2C
    ctx->r13 = ADD32(ctx->r29, 0X2C);
    // 0x8018D6FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D700: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8018D704: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8018D708: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018D70C: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8018D710: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018D714: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D718: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8018D71C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D720: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D724: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8018D728: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D72C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018D730: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8018D734: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018D738: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8018D73C: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x8018D740: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018D744: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D748: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018D74C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018D750: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8018D754: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018D758: sh          $v1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r3;
    // 0x8018D75C: sh          $t9, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r25;
    // 0x8018D760: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D764: sw          $v1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r3;
    // 0x8018D768: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x8018D76C: swc1        $f16, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f16.u32l;
    // 0x8018D770: jal         0x80004FE8
    // 0x8018D774: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_1;
    // 0x8018D774: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8018D778: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018D77C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018D780: nop

    // 0x8018D784: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8018D788: jal         0x80004FE8
    // 0x8018D78C: swc1        $f4, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_2;
    // 0x8018D78C: swc1        $f4, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8018D790: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018D794: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D798: nop

    // 0x8018D79C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018D7A0: jal         0x80004FE8
    // 0x8018D7A4: swc1        $f8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_3;
    // 0x8018D7A4: swc1        $f8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8018D7A8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018D7AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D7B0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018D7B4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8018D7B8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018D7BC: jal         0x800612B8
    // 0x8018D7C0: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x8018D7C0: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x8018D7C4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018D7C8: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018D7CC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018D7D0: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018D7D4: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8018D7D8: ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // 0x8018D7DC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018D7E0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018D7E4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018D7E8: jal         0x80019218
    // 0x8018D7EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x8018D7EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x8018D7F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018D7F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D7F8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018D7FC: jr          $ra
    // 0x8018D800: nop

    return;
    // 0x8018D800: nop

;}
RECOMP_FUNC void Aquas_AqJellyfish_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BB26C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801BB270: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801BB274: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801BB278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801BB27C: jal         0x80004EB0
    // 0x801BB280: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801BB280: nop

    after_0:
    // 0x801BB284: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801BB288: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BB28C: nop

    // 0x801BB290: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801BB294: jal         0x80004EB0
    // 0x801BB298: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801BB298: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x801BB29C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801BB2A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BB2A4: nop

    // 0x801BB2A8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801BB2AC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801BB2B0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x801BB2B4: jal         0x80004EB0
    // 0x801BB2B8: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801BB2B8: sh          $t7, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r15;
    after_2:
    // 0x801BB2BC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801BB2C0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801BB2C4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801BB2C8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801BB2CC: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x801BB2D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801BB2D4: lui         $at, 0x4367
    ctx->r1 = S32(0X4367 << 16);
    // 0x801BB2D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BB2DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BB2E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BB2E4: lui         $at, 0x4355
    ctx->r1 = S32(0X4355 << 16);
    // 0x801BB2E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BB2EC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801BB2F0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801BB2F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BB2F8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801BB2FC: swc1        $f2, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f2.u32l;
    // 0x801BB300: swc1        $f2, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->f2.u32l;
    // 0x801BB304: swc1        $f2, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f2.u32l;
    // 0x801BB308: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801BB30C: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801BB310: swc1        $f2, 0x15C($s0)
    MEM_W(0X15C, ctx->r16) = ctx->f2.u32l;
    // 0x801BB314: swc1        $f2, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->f2.u32l;
    // 0x801BB318: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x801BB31C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801BB320: swc1        $f2, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f2.u32l;
    // 0x801BB324: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x801BB328: sw          $t0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r8;
    // 0x801BB32C: swc1        $f2, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f2.u32l;
    // 0x801BB330: swc1        $f2, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f2.u32l;
    // 0x801BB334: swc1        $f2, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f2.u32l;
    // 0x801BB338: swc1        $f12, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f12.u32l;
    // 0x801BB33C: swc1        $f12, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f12.u32l;
    // 0x801BB340: swc1        $f12, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f12.u32l;
    // 0x801BB344: swc1        $f14, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f14.u32l;
    // 0x801BB348: swc1        $f14, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f14.u32l;
    // 0x801BB34C: swc1        $f16, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f16.u32l;
    // 0x801BB350: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    // 0x801BB354: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x801BB358: swc1        $f18, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f18.u32l;
    // 0x801BB35C: swc1        $f4, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f4.u32l;
    // 0x801BB360: swc1        $f6, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f6.u32l;
    // 0x801BB364: jal         0x80004EB0
    // 0x801BB368: swc1        $f8, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801BB368: swc1        $f8, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x801BB36C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801BB370: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BB374: nop

    // 0x801BB378: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801BB37C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801BB380: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x801BB384: jal         0x80004EB0
    // 0x801BB388: sw          $t2, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r10;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801BB388: sw          $t2, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r10;
    after_4:
    // 0x801BB38C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801BB390: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801BB394: nop

    // 0x801BB398: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801BB39C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801BB3A0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801BB3A4: nop

    // 0x801BB3A8: addiu       $t5, $t4, 0xF
    ctx->r13 = ADD32(ctx->r12, 0XF);
    // 0x801BB3AC: jal         0x80004EB0
    // 0x801BB3B0: sw          $t5, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r13;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801BB3B0: sw          $t5, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r13;
    after_5:
    // 0x801BB3B4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801BB3B8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BB3BC: nop

    // 0x801BB3C0: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801BB3C4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801BB3C8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x801BB3CC: nop

    // 0x801BB3D0: addiu       $t8, $t7, 0x2D
    ctx->r24 = ADD32(ctx->r15, 0X2D);
    // 0x801BB3D4: jal         0x80004EB0
    // 0x801BB3D8: sw          $t8, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801BB3D8: sw          $t8, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r24;
    after_6:
    // 0x801BB3DC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801BB3E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BB3E4: nop

    // 0x801BB3E8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801BB3EC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801BB3F0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x801BB3F4: jal         0x80004EB0
    // 0x801BB3F8: sw          $t0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r8;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x801BB3F8: sw          $t0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r8;
    after_7:
    // 0x801BB3FC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801BB400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BB404: nop

    // 0x801BB408: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801BB40C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801BB410: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x801BB414: jal         0x80004EB0
    // 0x801BB418: sw          $t2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r10;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801BB418: sw          $t2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r10;
    after_8:
    // 0x801BB41C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801BB420: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BB424: nop

    // 0x801BB428: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801BB42C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801BB430: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x801BB434: jal         0x80004EB0
    // 0x801BB438: sw          $t4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r12;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801BB438: sw          $t4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r12;
    after_9:
    // 0x801BB43C: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x801BB440: addiu       $a0, $a0, 0x3780
    ctx->r4 = ADD32(ctx->r4, 0X3780);
    // 0x801BB444: jal         0x8009ACDC
    // 0x801BB448: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    Animation_GetFrameCount(rdram, ctx);
        goto after_10;
    // 0x801BB448: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x801BB44C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x801BB450: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801BB454: lw          $t7, 0x58($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X58);
    // 0x801BB458: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801BB45C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BB460: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801BB464: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801BB468: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801BB46C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x801BB470: bne         $t7, $zero, L_801BB788
    if (ctx->r15 != 0) {
        // 0x801BB474: sh          $t6, 0xB6($s0)
        MEM_H(0XB6, ctx->r16) = ctx->r14;
            goto L_801BB788;
    }
    // 0x801BB474: sh          $t6, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r14;
    // 0x801BB478: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801BB47C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BB480: nop

    // 0x801BB484: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801BB488: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801BB48C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801BB490: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x801BB494: nop

    // 0x801BB498: beq         $v0, $zero, L_801BB4A8
    if (ctx->r2 == 0) {
        // 0x801BB49C: sw          $v0, 0x98($s0)
        MEM_W(0X98, ctx->r16) = ctx->r2;
            goto L_801BB4A8;
    }
    // 0x801BB49C: sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    // 0x801BB4A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801BB4A4: bne         $v0, $at, L_801BB4B0
    if (ctx->r2 != ctx->r1) {
        // 0x801BB4A8: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_801BB4B0;
    }
L_801BB4A8:
    // 0x801BB4A8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801BB4AC: sw          $t0, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = ctx->r8;
L_801BB4B0:
    // 0x801BB4B0: lw          $t1, 0x4450($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4450);
    // 0x801BB4B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BB4B8: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801BB4BC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801BB4C0: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x801BB4C4: sw          $t2, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r10;
    // 0x801BB4C8: lwc1        $f4, 0x2160($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2160);
    // 0x801BB4CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BB4D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BB4D4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801BB4D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BB4DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801BB4E0: jal         0x80005FE0
    // 0x801BB4E4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_11;
    // 0x801BB4E4: nop

    after_11:
    // 0x801BB4E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801BB4EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BB4F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BB4F4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x801BB4F8: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801BB4FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BB500: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BB504: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801BB508: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x801BB50C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x801BB510: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801BB514: jal         0x80006A20
    // 0x801BB518: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_12;
    // 0x801BB518: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x801BB51C: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x801BB520: addiu       $a3, $a3, 0x3FE0
    ctx->r7 = ADD32(ctx->r7, 0X3FE0);
    // 0x801BB524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801BB528: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_801BB52C:
    // 0x801BB52C: lbu         $t3, 0x0($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X0);
    // 0x801BB530: bne         $t3, $zero, L_801BB5D0
    if (ctx->r11 != 0) {
        // 0x801BB534: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_801BB5D0;
    }
    // 0x801BB534: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x801BB538: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x801BB53C: jal         0x800613C4
    // 0x801BB540: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    Actor_Initialize(rdram, ctx);
        goto after_13;
    // 0x801BB540: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_13:
    // 0x801BB544: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x801BB548: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x801BB54C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801BB550: addiu       $t5, $zero, 0x10B
    ctx->r13 = ADD32(0, 0X10B);
    // 0x801BB554: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
    // 0x801BB558: sh          $t5, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r13;
    // 0x801BB55C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801BB560: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801BB564: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801BB568: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x801BB56C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801BB570: addiu       $a0, $a3, 0x1C
    ctx->r4 = ADD32(ctx->r7, 0X1C);
    // 0x801BB574: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x801BB578: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801BB57C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801BB580: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801BB584: swc1        $f4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f4.u32l;
    // 0x801BB588: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801BB58C: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x801BB590: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x801BB594: sw          $t8, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r24;
    // 0x801BB598: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801BB59C: sw          $t7, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r15;
    // 0x801BB5A0: lw          $t9, 0x84($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84);
    // 0x801BB5A4: sw          $t9, 0x84($a3)
    MEM_W(0X84, ctx->r7) = ctx->r25;
    // 0x801BB5A8: lw          $t0, 0x98($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X98);
    // 0x801BB5AC: sw          $t0, 0x98($a3)
    MEM_W(0X98, ctx->r7) = ctx->r8;
    // 0x801BB5B0: lw          $t1, 0x9C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X9C);
    // 0x801BB5B4: sw          $t1, 0x9C($a3)
    MEM_W(0X9C, ctx->r7) = ctx->r9;
    // 0x801BB5B8: sw          $t2, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r10;
    // 0x801BB5BC: lhu         $a1, 0x2($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X2);
    // 0x801BB5C0: jal         0x800612B8
    // 0x801BB5C4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    Object_SetInfo(rdram, ctx);
        goto after_14;
    // 0x801BB5C4: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_14:
    // 0x801BB5C8: b           L_801BB5DC
    // 0x801BB5CC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
        goto L_801BB5DC;
    // 0x801BB5CC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
L_801BB5D0:
    // 0x801BB5D0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801BB5D4: bne         $v0, $v1, L_801BB52C
    if (ctx->r2 != ctx->r3) {
        // 0x801BB5D8: addiu       $a3, $a3, 0x2F4
        ctx->r7 = ADD32(ctx->r7, 0X2F4);
            goto L_801BB52C;
    }
    // 0x801BB5D8: addiu       $a3, $a3, 0x2F4
    ctx->r7 = ADD32(ctx->r7, 0X2F4);
L_801BB5DC:
    // 0x801BB5DC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801BB5E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BB5E4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801BB5E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BB5EC: lwc1        $f4, 0x2164($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2164);
    // 0x801BB5F0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801BB5F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BB5F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BB5FC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801BB600: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801BB604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BB608: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801BB60C: jal         0x80005FE0
    // 0x801BB610: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_15;
    // 0x801BB610: nop

    after_15:
    // 0x801BB614: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801BB618: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BB61C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BB620: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x801BB624: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801BB628: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BB62C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BB630: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801BB634: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x801BB638: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x801BB63C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801BB640: jal         0x80006A20
    // 0x801BB644: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_16;
    // 0x801BB644: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    after_16:
    // 0x801BB648: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x801BB64C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
    // 0x801BB650: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x801BB654: addiu       $a2, $a2, 0x3FE0
    ctx->r6 = ADD32(ctx->r6, 0X3FE0);
    // 0x801BB658: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801BB65C:
    // 0x801BB65C: lbu         $t3, 0x0($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X0);
    // 0x801BB660: bne         $t3, $zero, L_801BB714
    if (ctx->r11 != 0) {
        // 0x801BB664: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_801BB714;
    }
    // 0x801BB664: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801BB668: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x801BB66C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801BB670: jal         0x800613C4
    // 0x801BB674: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    Actor_Initialize(rdram, ctx);
        goto after_17;
    // 0x801BB674: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_17:
    // 0x801BB678: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x801BB67C: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x801BB680: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x801BB684: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801BB688: addiu       $t5, $zero, 0x10B
    ctx->r13 = ADD32(0, 0X10B);
    // 0x801BB68C: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x801BB690: sh          $t5, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r13;
    // 0x801BB694: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801BB698: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801BB69C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801BB6A0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x801BB6A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801BB6A8: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801BB6AC: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x801BB6B0: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801BB6B4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801BB6B8: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801BB6BC: swc1        $f4, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f4.u32l;
    // 0x801BB6C0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801BB6C4: swc1        $f6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f6.u32l;
    // 0x801BB6C8: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x801BB6CC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801BB6D0: sw          $t7, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->r15;
    // 0x801BB6D4: lw          $t8, 0x40($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X40);
    // 0x801BB6D8: sw          $t0, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r8;
    // 0x801BB6DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801BB6E0: sw          $t9, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r25;
    // 0x801BB6E4: lw          $t1, 0x84($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X84);
    // 0x801BB6E8: sw          $t1, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r9;
    // 0x801BB6EC: lw          $t2, 0x98($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X98);
    // 0x801BB6F0: sw          $t2, 0x98($a2)
    MEM_W(0X98, ctx->r6) = ctx->r10;
    // 0x801BB6F4: lw          $t3, 0x9C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C);
    // 0x801BB6F8: sw          $t3, 0x9C($a2)
    MEM_W(0X9C, ctx->r6) = ctx->r11;
    // 0x801BB6FC: sw          $v1, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r3;
    // 0x801BB700: sw          $v1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r3;
    // 0x801BB704: jal         0x800612B8
    // 0x801BB708: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_18;
    // 0x801BB708: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_18:
    // 0x801BB70C: b           L_801BB724
    // 0x801BB710: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
        goto L_801BB724;
    // 0x801BB710: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_801BB714:
    // 0x801BB714: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801BB718: bne         $v0, $v1, L_801BB65C
    if (ctx->r2 != ctx->r3) {
        // 0x801BB71C: addiu       $a2, $a2, 0x2F4
        ctx->r6 = ADD32(ctx->r6, 0X2F4);
            goto L_801BB65C;
    }
    // 0x801BB71C: addiu       $a2, $a2, 0x2F4
    ctx->r6 = ADD32(ctx->r6, 0X2F4);
    // 0x801BB720: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_801BB724:
    // 0x801BB724: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BB728: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801BB72C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801BB730: lwc1        $f12, 0x14($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801BB734: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801BB738: jal         0x80004E20
    // 0x801BB73C: swc1        $f18, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f18.u32l;
    Math_ModF(rdram, ctx);
        goto after_19;
    // 0x801BB73C: swc1        $f18, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f18.u32l;
    after_19:
    // 0x801BB740: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801BB744: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801BB748: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801BB74C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801BB750: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801BB754: addiu       $v0, $v0, 0x4450
    ctx->r2 = ADD32(ctx->r2, 0X4450);
    // 0x801BB758: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x801BB75C: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x801BB760: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x801BB764: swc1        $f2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f2.u32l;
    // 0x801BB768: swc1        $f6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f6.u32l;
    // 0x801BB76C: sw          $t5, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r13;
    // 0x801BB770: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801BB774: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801BB778: slti        $at, $t7, 0x15
    ctx->r1 = SIGNED(ctx->r15) < 0X15 ? 1 : 0;
    // 0x801BB77C: bne         $at, $zero, L_801BB788
    if (ctx->r1 != 0) {
        // 0x801BB780: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_801BB788;
    }
    // 0x801BB780: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801BB784: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_801BB788:
    // 0x801BB788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801BB78C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801BB790: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801BB794: jr          $ra
    // 0x801BB798: nop

    return;
    // 0x801BB798: nop

;}
RECOMP_FUNC void Zoness_ZoBarrier_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D060: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019D064: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019D068: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8019D06C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8019D070: addiu       $a2, $a2, 0x3FE0
    ctx->r6 = ADD32(ctx->r6, 0X3FE0);
    // 0x8019D074: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019D078: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_8019D07C:
    // 0x8019D07C: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8019D080: bne         $t6, $zero, L_8019D140
    if (ctx->r14 != 0) {
        // 0x8019D084: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8019D140;
    }
    // 0x8019D084: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8019D088: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8019D08C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8019D090: jal         0x800613C4
    // 0x8019D094: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019D094: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x8019D098: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8019D09C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8019D0A0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8019D0A4: addiu       $t8, $zero, 0xF7
    ctx->r24 = ADD32(0, 0XF7);
    // 0x8019D0A8: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x8019D0AC: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x8019D0B0: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8019D0B4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019D0B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019D0BC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8019D0C0: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019D0C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8019D0C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019D0CC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019D0D0: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x8019D0D4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8019D0D8: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x8019D0DC: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8019D0E0: swc1        $f16, 0x11C($a2)
    MEM_W(0X11C, ctx->r6) = ctx->f16.u32l;
    // 0x8019D0E4: lwc1        $f18, 0xC($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8019D0E8: sh          $t9, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r25;
    // 0x8019D0EC: swc1        $f18, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f18.u32l;
    // 0x8019D0F0: sh          $t0, 0x46($a3)
    MEM_H(0X46, ctx->r7) = ctx->r8;
    // 0x8019D0F4: jal         0x800612B8
    // 0x8019D0F8: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8019D0F8: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_1:
    // 0x8019D0FC: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x8019D100: addiu       $v0, $v0, -0x3FD8
    ctx->r2 = ADD32(ctx->r2, -0X3FD8);
    // 0x8019D104: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x8019D108: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x8019D10C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8019D110: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8019D114: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8019D118: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019D11C: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x8019D120: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019D124: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x8019D128: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8019D12C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019D130: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8019D134: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x8019D138: b           L_8019D14C
    // 0x8019D13C: sw          $t7, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r15;
        goto L_8019D14C;
    // 0x8019D13C: sw          $t7, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r15;
L_8019D140:
    // 0x8019D140: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8019D144: bne         $v0, $v1, L_8019D07C
    if (ctx->r2 != ctx->r3) {
        // 0x8019D148: addiu       $a2, $a2, 0x2F4
        ctx->r6 = ADD32(ctx->r6, 0X2F4);
            goto L_8019D07C;
    }
    // 0x8019D148: addiu       $a2, $a2, 0x2F4
    ctx->r6 = ADD32(ctx->r6, 0X2F4);
L_8019D14C:
    // 0x8019D14C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019D150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019D154: jr          $ra
    // 0x8019D158: nop

    return;
    // 0x8019D158: nop

;}
RECOMP_FUNC void Aquas_AqAnglerFish_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B6344: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801B6348: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801B634C: nop

    // 0x801B6350: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6354: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801B6358: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B635C: addiu       $t6, $zero, 0xC8
    ctx->r14 = ADD32(0, 0XC8);
    // 0x801B6360: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801B6364: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x801B6368: sh          $t6, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = ctx->r14;
    // 0x801B636C: swc1        $f0, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f0.u32l;
    // 0x801B6370: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x801B6374: swc1        $f6, 0x144($a0)
    MEM_W(0X144, ctx->r4) = ctx->f6.u32l;
    // 0x801B6378: sw          $t8, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r24;
    // 0x801B637C: sw          $v0, 0x90($a0)
    MEM_W(0X90, ctx->r4) = ctx->r2;
    // 0x801B6380: sw          $v0, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r2;
    // 0x801B6384: jr          $ra
    // 0x801B6388: nop

    return;
    // 0x801B6388: nop

;}
RECOMP_FUNC void Zoness_80199470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199470: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80199474: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80199478: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019947C: addiu       $v0, $v0, 0x23D0
    ctx->r2 = ADD32(ctx->r2, 0X23D0);
    // 0x80199480: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80199484: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80199488: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019948C: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x80199490: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80199494: addiu       $t0, $t0, 0x24E8
    ctx->r8 = ADD32(ctx->r8, 0X24E8);
    // 0x80199498: bne         $v1, $zero, L_80199584
    if (ctx->r3 != 0) {
        // 0x8019949C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80199584;
    }
    // 0x8019949C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801994A0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801994A4: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x801994A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801994AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801994B0: addu        $v1, $t0, $t7
    ctx->r3 = ADD32(ctx->r8, ctx->r15);
    // 0x801994B4: lwc1        $f0, 0x44($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X44);
    // 0x801994B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801994BC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801994C0: nop

    // 0x801994C4: bc1fl       L_801994E4
    if (!c1cs) {
        // 0x801994C8: lw          $v1, 0x90($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X90);
            goto L_801994E4;
    }
    goto skip_0;
    // 0x801994C8: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
    skip_0:
    // 0x801994CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801994D0: nop

    // 0x801994D4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801994D8: b           L_80199618
    // 0x801994DC: swc1        $f8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f8.u32l;
        goto L_80199618;
    // 0x801994DC: swc1        $f8, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f8.u32l;
    // 0x801994E0: lw          $v1, 0x90($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X90);
L_801994E4:
    // 0x801994E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801994E8: bne         $v1, $zero, L_80199500
    if (ctx->r3 != 0) {
        // 0x801994EC: nop
    
            goto L_80199500;
    }
    // 0x801994EC: nop

    // 0x801994F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801994F4: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x801994F8: sw          $t8, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->r24;
    // 0x801994FC: swc1        $f10, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->f10.u32l;
L_80199500:
    // 0x80199500: jal         0x8019962C
    // 0x80199504: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    Zoness_8019962C(rdram, ctx);
        goto after_0;
    // 0x80199504: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_0:
    // 0x80199508: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019950C: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80199510: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80199514: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80199518: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8019951C: addiu       $t0, $t0, 0x24E8
    ctx->r8 = ADD32(ctx->r8, 0X24E8);
    // 0x80199520: addiu       $v0, $v0, 0x23D0
    ctx->r2 = ADD32(ctx->r2, 0X23D0);
    // 0x80199524: bc1fl       L_8019961C
    if (!c1cs) {
        // 0x80199528: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019961C;
    }
    goto skip_1;
    // 0x80199528: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8019952C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80199530: sw          $zero, 0x40($v0)
    MEM_W(0X40, ctx->r2) = 0;
    // 0x80199534: sw          $zero, 0x90($v0)
    MEM_W(0X90, ctx->r2) = 0;
    // 0x80199538: swc1        $f4, 0x134($t0)
    MEM_W(0X134, ctx->r8) = ctx->f4.u32l;
    // 0x8019953C: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x80199540: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80199544: sh          $t1, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r9;
    // 0x80199548: sh          $t2, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r10;
    // 0x8019954C: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    // 0x80199550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80199554: bne         $t3, $zero, L_80199574
    if (ctx->r11 != 0) {
        // 0x80199558: nop
    
            goto L_80199574;
    }
    // 0x80199558: nop

    // 0x8019955C: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80199560: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80199564: bne         $t4, $zero, L_80199574
    if (ctx->r12 != 0) {
        // 0x80199568: nop
    
            goto L_80199574;
    }
    // 0x80199568: nop

    // 0x8019956C: sw          $t5, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r13;
    // 0x80199570: sw          $t5, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r13;
L_80199574:
    // 0x80199574: jal         0x8019914C
    // 0x80199578: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Zoness_8019914C(rdram, ctx);
        goto after_1;
    // 0x80199578: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8019957C: b           L_8019961C
    // 0x80199580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8019961C;
    // 0x80199580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80199584:
    // 0x80199584: beql        $v1, $at, L_8019961C
    if (ctx->r3 == ctx->r1) {
        // 0x80199588: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019961C;
    }
    goto skip_2;
    // 0x80199588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8019958C: lh          $t7, 0x52($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X52);
    // 0x80199590: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80199594: addiu       $t0, $t0, 0x24E8
    ctx->r8 = ADD32(ctx->r8, 0X24E8);
    // 0x80199598: bne         $t7, $zero, L_80199618
    if (ctx->r15 != 0) {
        // 0x8019959C: lw          $t8, 0x34($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X34);
            goto L_80199618;
    }
    // 0x8019959C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801995A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801995A4: lwc1        $f6, 0x1200($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1200);
    // 0x801995A8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801995AC: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x801995B0: addiu       $a0, $v1, 0x44
    ctx->r4 = ADD32(ctx->r3, 0X44);
    // 0x801995B4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x801995B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801995BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801995C0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x801995C4: jal         0x8009BC2C
    // 0x801995C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801995C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801995CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801995D0: lwc1        $f8, 0x1204($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1204);
    // 0x801995D4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801995D8: addiu       $a0, $a0, 0x24F4
    ctx->r4 = ADD32(ctx->r4, 0X24F4);
    // 0x801995DC: lui         $a1, 0xC1F0
    ctx->r5 = S32(0XC1F0 << 16);
    // 0x801995E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801995E4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801995E8: jal         0x8009BC2C
    // 0x801995EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801995EC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x801995F0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x801995F4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801995F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801995FC: lwc1        $f16, 0x44($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80199600: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80199604: nop

    // 0x80199608: bc1fl       L_8019961C
    if (!c1cs) {
        // 0x8019960C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019961C;
    }
    goto skip_3;
    // 0x8019960C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x80199610: jal         0x80199394
    // 0x80199614: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Zoness_80199394(rdram, ctx);
        goto after_4;
    // 0x80199614: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_4:
L_80199618:
    // 0x80199618: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019961C:
    // 0x8019961C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80199620: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80199624: jr          $ra
    // 0x80199628: nop

    return;
    // 0x80199628: nop

;}
RECOMP_FUNC void Aquas_AqJellyfish_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BC91C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801BC920: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801BC924: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801BC928: jr          $ra
    // 0x801BC92C: nop

    return;
    // 0x801BC92C: nop

;}
RECOMP_FUNC void Zoness_ZoSarumarine_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193D08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80193D0C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80193D10: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80193D14: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80193D18: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80193D1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80193D20: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80193D24: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80193D28: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80193D2C: addiu       $t8, $t8, 0x2330
    ctx->r24 = ADD32(ctx->r24, 0X2330);
    // 0x80193D30: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80193D34: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x80193D38: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80193D3C: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80193D40: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80193D44: bne         $t9, $at, L_80193D50
    if (ctx->r25 != ctx->r1) {
        // 0x80193D48: addiu       $t1, $t1, 0x7E64
        ctx->r9 = ADD32(ctx->r9, 0X7E64);
            goto L_80193D50;
    }
    // 0x80193D48: addiu       $t1, $t1, 0x7E64
    ctx->r9 = ADD32(ctx->r9, 0X7E64);
    // 0x80193D4C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80193D50:
    // 0x80193D50: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80193D54: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x80193D58: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x80193D5C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80193D60: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80193D64: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80193D68: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80193D6C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80193D70: lw          $t5, 0x2464($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2464);
    // 0x80193D74: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80193D78: beql        $t5, $at, L_80193DD0
    if (ctx->r13 == ctx->r1) {
        // 0x80193D7C: lw          $t4, 0x0($t0)
        ctx->r12 = MEM_W(ctx->r8, 0X0);
            goto L_80193DD0;
    }
    goto skip_0;
    // 0x80193D7C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x80193D80: jal         0x800BA0E0
    // 0x80193D84: nop

    RCP_SetupDL_46(rdram, ctx);
        goto after_0;
    // 0x80193D84: nop

    after_0:
    // 0x80193D88: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80193D8C: addiu       $t1, $t1, 0x7E64
    ctx->r9 = ADD32(ctx->r9, 0X7E64);
    // 0x80193D90: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80193D94: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80193D98: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80193D9C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80193DA0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80193DA4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80193DA8: lw          $a0, 0x2464($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2464);
    // 0x80193DAC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80193DB0: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80193DB4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80193DB8: sll         $t2, $t8, 8
    ctx->r10 = S32(ctx->r24 << 8);
    // 0x80193DBC: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80193DC0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80193DC4: b           L_80193E54
    // 0x80193DC8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_80193E54;
    // 0x80193DC8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80193DCC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
L_80193DD0:
    // 0x80193DD0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80193DD4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80193DD8: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80193DDC: bne         $t5, $zero, L_80193E20
    if (ctx->r13 != 0) {
        // 0x80193DE0: lui         $a2, 0x8018
        ctx->r6 = S32(0X8018 << 16);
            goto L_80193E20;
    }
    // 0x80193DE0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80193DE4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80193DE8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80193DEC: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x80193DF0: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x80193DF4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80193DF8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80193DFC: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80193E00: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80193E04: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80193E08: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80193E0C: jal         0x800BA1D0
    // 0x80193E10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_29(rdram, ctx);
        goto after_1;
    // 0x80193E10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80193E14: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80193E18: b           L_80193E50
    // 0x80193E1C: addiu       $t1, $t1, 0x7E64
    ctx->r9 = ADD32(ctx->r9, 0X7E64);
        goto L_80193E50;
    // 0x80193E1C: addiu       $t1, $t1, 0x7E64
    ctx->r9 = ADD32(ctx->r9, 0X7E64);
L_80193E20:
    // 0x80193E20: jal         0x800BA400
    // 0x80193E24: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_2;
    // 0x80193E24: nop

    after_2:
    // 0x80193E28: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80193E2C: addiu       $t1, $t1, 0x7E64
    ctx->r9 = ADD32(ctx->r9, 0X7E64);
    // 0x80193E30: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80193E34: lui         $t2, 0xFF00
    ctx->r10 = S32(0XFF00 << 16);
    // 0x80193E38: ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // 0x80193E3C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80193E40: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80193E44: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80193E48: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80193E4C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_80193E50:
    // 0x80193E50: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_80193E54:
    // 0x80193E54: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80193E58: sltiu       $at, $t4, 0x19
    ctx->r1 = ctx->r12 < 0X19 ? 1 : 0;
    // 0x80193E5C: beq         $at, $zero, L_8019437C
    if (ctx->r1 == 0) {
        // 0x80193E60: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_8019437C;
    }
    // 0x80193E60: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80193E64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193E68: addu        $at, $at, $t4
    gpr jr_addend_80193E70 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80193E6C: lw          $t4, 0xF44($at)
    ctx->r12 = ADD32(ctx->r1, 0XF44);
    // 0x80193E70: jr          $t4
    // 0x80193E74: nop

    switch (jr_addend_80193E70 >> 2) {
        case 0: goto L_80193E78; break;
        case 1: goto L_80193F00; break;
        case 2: goto L_8019437C; break;
        case 3: goto L_80193F6C; break;
        case 4: goto L_80193F88; break;
        case 5: goto L_80193FCC; break;
        case 6: goto L_80194018; break;
        case 7: goto L_801940A8; break;
        case 8: goto L_801940D4; break;
        case 9: goto L_80194100; break;
        case 10: goto L_8019416C; break;
        case 11: goto L_80193EDC; break;
        case 12: goto L_8019437C; break;
        case 13: goto L_8019437C; break;
        case 14: goto L_801941FC; break;
        case 15: goto L_80193F6C; break;
        case 16: goto L_8019437C; break;
        case 17: goto L_80194064; break;
        case 18: goto L_801941B8; break;
        case 19: goto L_8019437C; break;
        case 20: goto L_8019427C; break;
        case 21: goto L_801942C0; break;
        case 22: goto L_801942E8; break;
        case 23: goto L_8019432C; break;
        case 24: goto L_80194354; break;
        default: switch_error(__func__, 0x80193E70, 0x801C0F44);
    }
    // 0x80193E74: nop

L_80193E78:
    // 0x80193E78: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80193E7C: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80193E80: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80193E84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80193E88: nop

    // 0x80193E8C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x80193E90: nop

    // 0x80193E94: bc1fl       L_80193ED4
    if (!c1cs) {
        // 0x80193E98: lwc1        $f16, 0x8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
            goto L_80193ED4;
    }
    goto skip_1;
    // 0x80193E98: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x80193E9C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80193EA0: lwc1        $f8, 0x1C0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x80193EA4: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80193EA8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80193EAC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80193EB0: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x80193EB4: lwc1        $f18, 0x1C0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x80193EB8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80193EBC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80193EC0: lwc1        $f8, 0x1C0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x80193EC4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80193EC8: b           L_80193EDC
    // 0x80193ECC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_80193EDC;
    // 0x80193ECC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80193ED0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
L_80193ED4:
    // 0x80193ED4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80193ED8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_80193EDC:
    // 0x80193EDC: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x80193EE0: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x80193EE4: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x80193EE8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80193EEC: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80193EF0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80193EF4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80193EF8: b           L_80194380
    // 0x80193EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80194380;
    // 0x80193EFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80193F00:
    // 0x80193F00: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80193F04: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80193F08: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80193F0C: lwc1        $f6, 0x1C8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C8);
    // 0x80193F10: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80193F14: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80193F18: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80193F1C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80193F20: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80193F24: lwc1        $f4, 0x1C8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C8);
    // 0x80193F28: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80193F2C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80193F30: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80193F34: lwc1        $f8, 0x1C8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C8);
    // 0x80193F38: lwc1        $f10, 0x14C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14C);
    // 0x80193F3C: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80193F40: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80193F44: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80193F48: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80193F4C: lwc1        $f10, 0x150($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X150);
    // 0x80193F50: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80193F54: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80193F58: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
    // 0x80193F5C: lwc1        $f16, 0x154($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X154);
    // 0x80193F60: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80193F64: b           L_8019437C
    // 0x80193F68: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
        goto L_8019437C;
    // 0x80193F68: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
L_80193F6C:
    // 0x80193F6C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80193F70: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80193F74: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80193F78: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80193F7C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80193F80: b           L_8019437C
    // 0x80193F84: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
        goto L_8019437C;
    // 0x80193F84: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
L_80193F88:
    // 0x80193F88: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80193F8C: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80193F90: lwc1        $f16, 0x1CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x80193F94: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80193F98: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80193F9C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80193FA0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80193FA4: lwc1        $f10, 0x1CC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x80193FA8: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80193FAC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80193FB0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80193FB4: lwc1        $f16, 0x1CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1CC);
    // 0x80193FB8: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80193FBC: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80193FC0: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80193FC4: b           L_8019437C
    // 0x80193FC8: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
        goto L_8019437C;
    // 0x80193FC8: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80193FCC:
    // 0x80193FCC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80193FD0: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80193FD4: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80193FD8: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80193FDC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80193FE0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80193FE4: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80193FE8: lwc1        $f4, 0x168($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X168);
    // 0x80193FEC: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80193FF0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80193FF4: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80193FF8: lwc1        $f18, 0x16C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X16C);
    // 0x80193FFC: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80194000: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80194004: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x80194008: lwc1        $f4, 0x170($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X170);
    // 0x8019400C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80194010: b           L_8019437C
    // 0x80194014: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_8019437C;
    // 0x80194014: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_80194018:
    // 0x80194018: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019401C: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80194020: lwc1        $f18, 0x1D0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x80194024: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80194028: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019402C: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80194030: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80194034: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80194038: lwc1        $f4, 0x1D0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x8019403C: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80194040: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80194044: lwc1        $f18, 0x1D0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x80194048: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8019404C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80194050: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80194054: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80194058: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019405C: b           L_8019437C
    // 0x80194060: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
        goto L_8019437C;
    // 0x80194060: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_80194064:
    // 0x80194064: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194068: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x8019406C: lwc1        $f18, 0x1D0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x80194070: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80194074: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80194078: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8019407C: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80194080: lwc1        $f4, 0x1D0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x80194084: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80194088: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019408C: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80194090: lwc1        $f18, 0x1D0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x80194094: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80194098: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8019409C: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801940A0: b           L_8019437C
    // 0x801940A4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_8019437C;
    // 0x801940A4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_801940A8:
    // 0x801940A8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801940AC: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x801940B0: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801940B4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801940B8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801940BC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801940C0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801940C4: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801940C8: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801940CC: b           L_8019437C
    // 0x801940D0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
        goto L_8019437C;
    // 0x801940D0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_801940D4:
    // 0x801940D4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801940D8: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x801940DC: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801940E0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801940E4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801940E8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801940EC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801940F0: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801940F4: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801940F8: b           L_8019437C
    // 0x801940FC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
        goto L_8019437C;
    // 0x801940FC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
L_80194100:
    // 0x80194100: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194104: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80194108: lwc1        $f10, 0x2C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8019410C: lwc1        $f8, 0x1C4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C4);
    // 0x80194110: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80194114: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80194118: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019411C: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80194120: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x80194124: lwc1        $f10, 0x1C4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C4);
    // 0x80194128: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8019412C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80194130: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80194134: lwc1        $f18, 0x1C4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C4);
    // 0x80194138: lwc1        $f6, 0x140($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X140);
    // 0x8019413C: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80194140: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80194144: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80194148: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8019414C: lwc1        $f6, 0x144($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X144);
    // 0x80194150: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80194154: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80194158: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    // 0x8019415C: lwc1        $f16, 0x148($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X148);
    // 0x80194160: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80194164: b           L_8019437C
    // 0x80194168: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_8019437C;
    // 0x80194168: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_8019416C:
    // 0x8019416C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194170: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80194174: lwc1        $f6, 0x1D4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x80194178: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8019417C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80194180: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80194184: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80194188: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8019418C: lwc1        $f16, 0x1D4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x80194190: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80194194: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x80194198: lwc1        $f6, 0x1D4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x8019419C: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801941A0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801941A4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801941A8: lwc1        $f16, 0x34($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801941AC: add.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801941B0: b           L_8019437C
    // 0x801941B4: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
        goto L_8019437C;
    // 0x801941B4: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_801941B8:
    // 0x801941B8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801941BC: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x801941C0: lwc1        $f6, 0x1D4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x801941C4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801941C8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801941CC: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801941D0: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x801941D4: lwc1        $f16, 0x1D4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x801941D8: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801941DC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801941E0: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x801941E4: lwc1        $f6, 0x1D4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x801941E8: lwc1        $f8, 0x30($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801941EC: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801941F0: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801941F4: b           L_8019437C
    // 0x801941F8: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_8019437C;
    // 0x801941F8: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_801941FC:
    // 0x801941FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194200: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80194204: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80194208: lwc1        $f8, 0x4C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8019420C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80194210: lwc1        $f16, 0x1C0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x80194214: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80194218: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8019421C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80194220: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80194224: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80194228: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019422C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80194230: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x80194234: lwc1        $f18, 0x1C0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x80194238: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8019423C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80194240: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80194244: lwc1        $f10, 0x1C0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C0);
    // 0x80194248: lwc1        $f8, 0x158($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X158);
    // 0x8019424C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80194250: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80194254: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80194258: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8019425C: lwc1        $f8, 0x15C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X15C);
    // 0x80194260: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80194264: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80194268: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8019426C: lwc1        $f6, 0x160($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X160);
    // 0x80194270: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80194274: b           L_8019437C
    // 0x80194278: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
        goto L_8019437C;
    // 0x80194278: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
L_8019427C:
    // 0x8019427C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194280: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80194284: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80194288: lwc1        $f8, 0x1D0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x8019428C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80194290: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80194294: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80194298: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8019429C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801942A0: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x801942A4: lwc1        $f16, 0x1D0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x801942A8: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801942AC: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x801942B0: lwc1        $f10, 0x1D0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1D0);
    // 0x801942B4: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x801942B8: b           L_8019437C
    // 0x801942BC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
        goto L_8019437C;
    // 0x801942BC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
L_801942C0:
    // 0x801942C0: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x801942C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801942C8: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x801942CC: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801942D0: lwc1        $f16, 0xDC($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0XDC);
    // 0x801942D4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801942D8: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x801942DC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801942E0: b           L_8019437C
    // 0x801942E4: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
        goto L_8019437C;
    // 0x801942E4: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_801942E8:
    // 0x801942E8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801942EC: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x801942F0: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801942F4: lwc1        $f18, 0x1D4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x801942F8: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801942FC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80194300: sub.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80194304: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80194308: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019430C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x80194310: lwc1        $f6, 0x1D4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x80194314: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80194318: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8019431C: lwc1        $f16, 0x1D4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1D4);
    // 0x80194320: sub.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80194324: b           L_8019437C
    // 0x80194328: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_8019437C;
    // 0x80194328: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_8019432C:
    // 0x8019432C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80194330: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194334: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80194338: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8019433C: lwc1        $f6, 0xE0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XE0);
    // 0x80194340: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80194344: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80194348: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8019434C: b           L_8019437C
    // 0x80194350: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
        goto L_8019437C;
    // 0x80194350: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
L_80194354:
    // 0x80194354: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80194358: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x8019435C: lwc1        $f10, 0x4C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x80194360: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80194364: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80194368: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x8019436C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80194370: lwc1        $f18, 0x1A4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1A4);
    // 0x80194374: add.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80194378: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
L_8019437C:
    // 0x8019437C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80194380:
    // 0x80194380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80194384: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80194388: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8019438C: jr          $ra
    // 0x80194390: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80194390: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Zoness_ZoRadarBuoy_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C1CC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8019C1D0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019C1D4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019C1D8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8019C1DC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8019C1E0: addiu       $t8, $t8, 0x2E10
    ctx->r24 = ADD32(ctx->r24, 0X2E10);
    // 0x8019C1E4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8019C1E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8019C1EC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8019C1F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019C1F4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8019C1F8: jr          $ra
    // 0x8019C1FC: nop

    return;
    // 0x8019C1FC: nop

;}
RECOMP_FUNC void Area6_LevelStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DF74: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018DF78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018DF7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018DF80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018DF84: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x8018DF88: beq         $v0, $zero, L_8018DFA0
    if (ctx->r2 == 0) {
        // 0x8018DF8C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8018DFA0;
    }
    // 0x8018DF8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018DF90: beq         $v0, $at, L_8018E124
    if (ctx->r2 == ctx->r1) {
        // 0x8018DF94: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8018E124;
    }
    // 0x8018DF94: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018DF98: b           L_8018E628
    // 0x8018DF9C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018E628;
    // 0x8018DF9C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018DFA0:
    // 0x8018DFA0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018DFA4: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018DFA8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DFAC: sw          $t9, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r25;
    // 0x8018DFB0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018DFB4: addiu       $a1, $zero, 0x7148
    ctx->r5 = ADD32(0, 0X7148);
    // 0x8018DFB8: jal         0x80004FC8
    // 0x8018DFBC: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    Rand_SetSeed(rdram, ctx);
        goto after_0;
    // 0x8018DFBC: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    after_0:
    // 0x8018DFC0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018DFC4: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x8018DFC8: jal         0x8018D694
    // 0x8018DFCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Area6_8018D694(rdram, ctx);
        goto after_1;
    // 0x8018DFCC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8018DFD0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018DFD4: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x8018DFD8: jal         0x8018D694
    // 0x8018DFDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Area6_8018D694(rdram, ctx);
        goto after_2;
    // 0x8018DFDC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8018DFE0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018DFE4: addiu       $a0, $a0, 0x5198
    ctx->r4 = ADD32(ctx->r4, 0X5198);
    // 0x8018DFE8: jal         0x8018D694
    // 0x8018DFEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Area6_8018D694(rdram, ctx);
        goto after_3;
    // 0x8018DFEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x8018DFF0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018DFF4: addiu       $a0, $a0, 0x548C
    ctx->r4 = ADD32(ctx->r4, 0X548C);
    // 0x8018DFF8: jal         0x8018D694
    // 0x8018DFFC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    Area6_8018D694(rdram, ctx);
        goto after_4;
    // 0x8018DFFC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x8018E000: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E004: addiu       $a0, $a0, 0x5780
    ctx->r4 = ADD32(ctx->r4, 0X5780);
    // 0x8018E008: jal         0x8018D694
    // 0x8018E00C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    Area6_8018D694(rdram, ctx);
        goto after_5;
    // 0x8018E00C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_5:
    // 0x8018E010: jal         0x8018D5C8
    // 0x8018E014: nop

    Area6_8018D5C8(rdram, ctx);
        goto after_6;
    // 0x8018E014: nop

    after_6:
    // 0x8018E018: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8018E01C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E020: lui         $at, 0x467A
    ctx->r1 = S32(0X467A << 16);
    // 0x8018E024: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E028: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018E02C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018E030: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E034: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8018E038: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x8018E03C: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    // 0x8018E040: swc1        $f4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f4.u32l;
    // 0x8018E044: swc1        $f10, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f10.u32l;
    // 0x8018E048: lw          $t0, 0x78B4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78B4);
    // 0x8018E04C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E050: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    // 0x8018E054: blez        $t0, L_8018E064
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8018E058: nop
    
            goto L_8018E064;
    }
    // 0x8018E058: nop

    // 0x8018E05C: jal         0x8018D804
    // 0x8018E060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Area6_8018D804(rdram, ctx);
        goto after_7;
    // 0x8018E060: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_8018E064:
    // 0x8018E064: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8018E068: lw          $t1, 0x78B8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B8);
    // 0x8018E06C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E070: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x8018E074: blez        $t1, L_8018E084
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8018E078: nop
    
            goto L_8018E084;
    }
    // 0x8018E078: nop

    // 0x8018E07C: jal         0x8018D804
    // 0x8018E080: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Area6_8018D804(rdram, ctx);
        goto after_8;
    // 0x8018E080: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
L_8018E084:
    // 0x8018E084: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018E088: lw          $t2, 0x78BC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78BC);
    // 0x8018E08C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E090: addiu       $a0, $a0, 0x4EA4
    ctx->r4 = ADD32(ctx->r4, 0X4EA4);
    // 0x8018E094: blezl       $t2, L_8018E0A8
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8018E098: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8018E0A8;
    }
    goto skip_0;
    // 0x8018E098: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_0:
    // 0x8018E09C: jal         0x8018D804
    // 0x8018E0A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Area6_8018D804(rdram, ctx);
        goto after_9;
    // 0x8018E0A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018E0A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8018E0A8:
    // 0x8018E0A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E0AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E0B0: swc1        $f4, 0x40F4($at)
    MEM_W(0X40F4, ctx->r1) = ctx->f4.u32l;
    // 0x8018E0B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018E0B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E0BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E0C0: swc1        $f6, 0x49D0($at)
    MEM_W(0X49D0, ctx->r1) = ctx->f6.u32l;
    // 0x8018E0C4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018E0C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E0CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E0D0: swc1        $f8, 0x4CC4($at)
    MEM_W(0X4CC4, ctx->r1) = ctx->f8.u32l;
    // 0x8018E0D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018E0D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E0DC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E0E0: swc1        $f10, 0x4FB8($at)
    MEM_W(0X4FB8, ctx->r1) = ctx->f10.u32l;
    // 0x8018E0E4: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8018E0E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E0EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E0F0: swc1        $f4, 0x7A58($at)
    MEM_W(0X7A58, ctx->r1) = ctx->f4.u32l;
    // 0x8018E0F4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8018E0F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E0FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E100: swc1        $f6, 0x7A5C($at)
    MEM_W(0X7A5C, ctx->r1) = ctx->f6.u32l;
    // 0x8018E104: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E108: lwc1        $f8, 0xB44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XB44);
    // 0x8018E10C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E110: swc1        $f8, 0x7A60($at)
    MEM_W(0X7A60, ctx->r1) = ctx->f8.u32l;
    // 0x8018E114: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E118: lwc1        $f10, 0xB48($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB48);
    // 0x8018E11C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E120: swc1        $f10, 0x7A54($at)
    MEM_W(0X7A54, ctx->r1) = ctx->f10.u32l;
L_8018E124:
    // 0x8018E124: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E128: lwc1        $f4, 0xB4C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB4C);
    // 0x8018E12C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E130: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018E134: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018E138: addiu       $a0, $a0, 0x3FE8
    ctx->r4 = ADD32(ctx->r4, 0X3FE8);
    // 0x8018E13C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018E140: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018E144: jal         0x8009BC2C
    // 0x8018E148: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8018E148: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x8018E14C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8018E150: lw          $t3, 0x7A80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7A80);
    // 0x8018E154: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018E158: addiu       $a0, $a0, 0x7A54
    ctx->r4 = ADD32(ctx->r4, 0X7A54);
    // 0x8018E15C: slti        $at, $t3, 0x1EA
    ctx->r1 = SIGNED(ctx->r11) < 0X1EA ? 1 : 0;
    // 0x8018E160: beq         $at, $zero, L_8018E388
    if (ctx->r1 == 0) {
        // 0x8018E164: lui         $a1, 0x3DCC
        ctx->r5 = S32(0X3DCC << 16);
            goto L_8018E388;
    }
    // 0x8018E164: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x8018E168: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018E16C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018E170: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8018E174: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8018E178: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E17C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018E180: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E184: lw          $a3, 0x18($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X18);
    // 0x8018E188: lui         $a2, 0x43AF
    ctx->r6 = S32(0X43AF << 16);
    // 0x8018E18C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018E190: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8018E194: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8018E198: jal         0x80005B00
    // 0x8018E19C: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x8018E19C: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x8018E1A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E1A4: lwc1        $f8, 0x7A58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7A58);
    // 0x8018E1A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E1AC: lwc1        $f10, 0xB50($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB50);
    // 0x8018E1B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E1B4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E1B8: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018E1BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E1C0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8018E1C4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018E1C8: jal         0x80005E90
    // 0x8018E1CC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x8018E1CC: nop

    after_12:
    // 0x8018E1D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E1D4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E1D8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8018E1DC: jal         0x80006970
    // 0x8018E1E0: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x8018E1E0: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_13:
    // 0x8018E1E4: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018E1E8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018E1EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E1F0: swc1        $f8, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f8.u32l;
    // 0x8018E1F4: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8018E1F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E1FC: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018E200: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x8018E204: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x8018E208: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E20C: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x8018E210: slti        $at, $t4, 0xC8
    ctx->r1 = SIGNED(ctx->r12) < 0XC8 ? 1 : 0;
    // 0x8018E214: beq         $at, $zero, L_8018E294
    if (ctx->r1 == 0) {
        // 0x8018E218: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_8018E294;
    }
    // 0x8018E218: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018E21C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E220: lwc1        $f6, 0xB54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB54);
    // 0x8018E224: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018E228: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018E22C: lui         $a3, 0x3F0F
    ctx->r7 = S32(0X3F0F << 16);
    // 0x8018E230: ori         $a3, $a3, 0x5C29
    ctx->r7 = ctx->r7 | 0X5C29;
    // 0x8018E234: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018E238: addiu       $a0, $a0, 0x7A58
    ctx->r4 = ADD32(ctx->r4, 0X7A58);
    // 0x8018E23C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018E240: jal         0x8009BC2C
    // 0x8018E244: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8018E244: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x8018E248: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018E24C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018E250: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E254: lwc1        $f8, 0x42D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X42D8);
    // 0x8018E258: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E25C: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x8018E260: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E264: lwc1        $f10, 0x42DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X42DC);
    // 0x8018E268: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E26C: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x8018E270: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E274: lwc1        $f4, 0x42E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X42E0);
    // 0x8018E278: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E27C: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x8018E280: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E284: swc1        $f0, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f0.u32l;
    // 0x8018E288: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E28C: b           L_8018E500
    // 0x8018E290: swc1        $f0, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f0.u32l;
        goto L_8018E500;
    // 0x8018E290: swc1        $f0, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f0.u32l;
L_8018E294:
    // 0x8018E294: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E298: lwc1        $f6, 0xB58($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB58);
    // 0x8018E29C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018E2A0: lui         $a3, 0x3F0F
    ctx->r7 = S32(0X3F0F << 16);
    // 0x8018E2A4: ori         $a3, $a3, 0x5C29
    ctx->r7 = ctx->r7 | 0X5C29;
    // 0x8018E2A8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018E2AC: addiu       $a0, $a0, 0x7A58
    ctx->r4 = ADD32(ctx->r4, 0X7A58);
    // 0x8018E2B0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018E2B4: jal         0x8009BC2C
    // 0x8018E2B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8018E2B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x8018E2BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E2C0: lwc1        $f8, 0xB5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XB5C);
    // 0x8018E2C4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018E2C8: lui         $a2, 0x3B44
    ctx->r6 = S32(0X3B44 << 16);
    // 0x8018E2CC: ori         $a2, $a2, 0x9BA6
    ctx->r6 = ctx->r6 | 0X9BA6;
    // 0x8018E2D0: addiu       $a0, $a0, 0x7A5C
    ctx->r4 = ADD32(ctx->r4, 0X7A5C);
    // 0x8018E2D4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018E2D8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018E2DC: jal         0x8009BC2C
    // 0x8018E2E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8018E2E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x8018E2E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E2E8: lwc1        $f10, 0xB60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB60);
    // 0x8018E2EC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018E2F0: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x8018E2F4: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018E2F8: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018E2FC: addiu       $a0, $a0, 0x79A0
    ctx->r4 = ADD32(ctx->r4, 0X79A0);
    // 0x8018E300: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8018E304: jal         0x8009BC2C
    // 0x8018E308: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x8018E308: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x8018E30C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E310: lwc1        $f4, 0xB64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB64);
    // 0x8018E314: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018E318: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x8018E31C: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018E320: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018E324: addiu       $a0, $a0, 0x79B8
    ctx->r4 = ADD32(ctx->r4, 0X79B8);
    // 0x8018E328: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8018E32C: jal         0x8009BC2C
    // 0x8018E330: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8018E330: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_18:
    // 0x8018E334: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E338: lwc1        $f8, 0xB68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XB68);
    // 0x8018E33C: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018E340: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E344: lwc1        $f4, 0xB6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB6C);
    // 0x8018E348: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018E34C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018E350: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x8018E354: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018E358: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018E35C: addiu       $a0, $a0, 0x79C0
    ctx->r4 = ADD32(ctx->r4, 0X79C0);
    // 0x8018E360: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8018E364: jal         0x8009BC2C
    // 0x8018E368: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x8018E368: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x8018E36C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018E370: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018E374: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E378: swc1        $f0, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f0.u32l;
    // 0x8018E37C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E380: b           L_8018E500
    // 0x8018E384: swc1        $f0, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f0.u32l;
        goto L_8018E500;
    // 0x8018E384: swc1        $f0, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f0.u32l;
L_8018E388:
    // 0x8018E388: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E38C: lwc1        $f6, 0xB70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XB70);
    // 0x8018E390: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8018E394: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8018E398: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8018E39C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8018E3A0: jal         0x8009BC2C
    // 0x8018E3A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x8018E3A4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_20:
    // 0x8018E3A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E3AC: lwc1        $f18, 0x7978($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x8018E3B0: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018E3B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E3B8: lwc1        $f2, 0x7A54($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7A54);
    // 0x8018E3BC: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8018E3C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E3C4: lwc1        $f10, 0x7980($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x8018E3C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018E3CC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018E3D0: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8018E3D4: mul.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8018E3D8: lwc1        $f6, 0x148($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X148);
    // 0x8018E3DC: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018E3E0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E3E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E3E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E3EC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8018E3F0: lwc1        $f8, 0x7988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x8018E3F4: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018E3F8: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8018E3FC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x8018E400: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018E404: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E408: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018E40C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E410: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018E414: mul.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8018E418: add.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x8018E41C: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8018E420: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x8018E424: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E428: sub.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x8018E42C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018E430: swc1        $f4, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f4.u32l;
    // 0x8018E434: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8018E438: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E43C: sub.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8018E440: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x8018E444: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E448: lwc1        $f10, 0x79A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x8018E44C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E450: lwc1        $f8, 0x79B8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8018E454: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8018E458: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018E45C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8018E460: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018E464: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8018E468: lwc1        $f4, 0x148($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X148);
    // 0x8018E46C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018E470: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018E474: mul.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8018E478: nop

    // 0x8018E47C: mul.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8018E480: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E484: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E488: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018E48C: lwc1        $f4, 0x79C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8018E490: lui         $at, 0x424C
    ctx->r1 = S32(0X424C << 16);
    // 0x8018E494: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018E498: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8018E49C: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018E4A0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018E4A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E4A8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018E4AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E4B0: sub.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8018E4B4: mul.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8018E4B8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018E4BC: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8018E4C0: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8018E4C4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018E4C8: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x8018E4CC: mul.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8018E4D0: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x8018E4D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E4D8: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x8018E4DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E4E0: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8018E4E4: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
    // 0x8018E4E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018E4EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018E4F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E4F4: swc1        $f0, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f0.u32l;
    // 0x8018E4F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E4FC: swc1        $f0, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f0.u32l;
L_8018E500:
    // 0x8018E500: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018E504: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018E508: addiu       $at, $zero, 0x1CC
    ctx->r1 = ADD32(0, 0X1CC);
    // 0x8018E50C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018E510: bne         $v1, $at, L_8018E55C
    if (ctx->r3 != ctx->r1) {
        // 0x8018E514: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8018E55C;
    }
    // 0x8018E514: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018E518: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018E51C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E520: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018E524: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E528: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8018E52C: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8018E530: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018E534: swc1        $f8, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f8.u32l;
    // 0x8018E538: swc1        $f10, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f10.u32l;
    // 0x8018E53C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8018E540: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018E544: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018E548: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x8018E54C: jal         0x80019218
    // 0x8018E550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_21;
    // 0x8018E550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_21:
    // 0x8018E554: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018E558: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018E55C:
    // 0x8018E55C: slti        $at, $v1, 0x1CC
    ctx->r1 = SIGNED(ctx->r3) < 0X1CC ? 1 : 0;
    // 0x8018E560: bne         $at, $zero, L_8018E588
    if (ctx->r1 != 0) {
        // 0x8018E564: addiu       $a0, $s0, 0xD0
        ctx->r4 = ADD32(ctx->r16, 0XD0);
            goto L_8018E588;
    }
    // 0x8018E564: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x8018E568: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E56C: lwc1        $f4, 0xB74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB74);
    // 0x8018E570: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018E574: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018E578: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x8018E57C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018E580: jal         0x8009BC2C
    // 0x8018E584: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8018E584: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_22:
L_8018E588:
    // 0x8018E588: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018E58C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E590: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018E594: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018E598: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018E59C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x8018E5A0: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8018E5A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018E5A8: ori         $a1, $zero, 0x8007
    ctx->r5 = 0 | 0X8007;
    // 0x8018E5AC: bc1f        L_8018E5C4
    if (!c1cs) {
        // 0x8018E5B0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8018E5C4;
    }
    // 0x8018E5B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018E5B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018E5B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018E5BC: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x8018E5C0: swc1        $f4, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f4.u32l;
L_8018E5C4:
    // 0x8018E5C4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018E5C8: addiu       $at, $zero, 0x21C
    ctx->r1 = ADD32(0, 0X21C);
    // 0x8018E5CC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8018E5D0: bne         $v1, $at, L_8018E628
    if (ctx->r3 != ctx->r1) {
        // 0x8018E5D4: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8018E628;
    }
    // 0x8018E5D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018E5D8: sw          $t6, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r14;
    // 0x8018E5DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018E5E0: sw          $t7, 0x7838($at)
    MEM_W(0X7838, ctx->r1) = ctx->r15;
    // 0x8018E5E4: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8018E5E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018E5EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018E5F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E5F4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E5F8: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    // 0x8018E5FC: swc1        $f8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f8.u32l;
    // 0x8018E600: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x8018E604: lwc1        $f4, 0x1A54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x8018E608: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    // 0x8018E60C: sw          $zero, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = 0;
    // 0x8018E610: jal         0x8001D444
    // 0x8018E614: swc1        $f4, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f4.u32l;
    Audio_PlaySequence(rdram, ctx);
        goto after_23;
    // 0x8018E614: swc1        $f4, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f4.u32l;
    after_23:
    // 0x8018E618: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8018E61C: sw          $t8, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r24;
    // 0x8018E620: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018E624: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018E628:
    // 0x8018E628: slti        $at, $v1, 0x169
    ctx->r1 = SIGNED(ctx->r3) < 0X169 ? 1 : 0;
    // 0x8018E62C: bne         $at, $zero, L_8018E66C
    if (ctx->r1 != 0) {
        // 0x8018E630: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018E66C;
    }
    // 0x8018E630: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018E634: addiu       $at, $zero, 0x1AE
    ctx->r1 = ADD32(0, 0X1AE);
    // 0x8018E638: beq         $v1, $at, L_8018E838
    if (ctx->r3 == ctx->r1) {
        // 0x8018E63C: addiu       $t8, $zero, 0x10
        ctx->r24 = ADD32(0, 0X10);
            goto L_8018E838;
    }
    // 0x8018E63C: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8018E640: addiu       $at, $zero, 0x1B8
    ctx->r1 = ADD32(0, 0X1B8);
    // 0x8018E644: beq         $v1, $at, L_8018E844
    if (ctx->r3 == ctx->r1) {
        // 0x8018E648: addiu       $t9, $zero, 0xB
        ctx->r25 = ADD32(0, 0XB);
            goto L_8018E844;
    }
    // 0x8018E648: addiu       $t9, $zero, 0xB
    ctx->r25 = ADD32(0, 0XB);
    // 0x8018E64C: addiu       $at, $zero, 0x1C2
    ctx->r1 = ADD32(0, 0X1C2);
    // 0x8018E650: beq         $v1, $at, L_8018E850
    if (ctx->r3 == ctx->r1) {
        // 0x8018E654: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_8018E850;
    }
    // 0x8018E654: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x8018E658: addiu       $at, $zero, 0x1E0
    ctx->r1 = ADD32(0, 0X1E0);
    // 0x8018E65C: beq         $v1, $at, L_8018E85C
    if (ctx->r3 == ctx->r1) {
        // 0x8018E660: nop
    
            goto L_8018E85C;
    }
    // 0x8018E660: nop

    // 0x8018E664: b           L_8018E868
    // 0x8018E668: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E668: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E66C:
    // 0x8018E66C: slti        $at, $v0, 0xD3
    ctx->r1 = SIGNED(ctx->r2) < 0XD3 ? 1 : 0;
    // 0x8018E670: bne         $at, $zero, L_8018E6B4
    if (ctx->r1 != 0) {
        // 0x8018E674: slti        $at, $v0, 0x119
        ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
            goto L_8018E6B4;
    }
    // 0x8018E674: slti        $at, $v0, 0x119
    ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
    // 0x8018E678: bne         $at, $zero, L_8018E694
    if (ctx->r1 != 0) {
        // 0x8018E67C: addiu       $t9, $v0, -0xF0
        ctx->r25 = ADD32(ctx->r2, -0XF0);
            goto L_8018E694;
    }
    // 0x8018E67C: addiu       $t9, $v0, -0xF0
    ctx->r25 = ADD32(ctx->r2, -0XF0);
    // 0x8018E680: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x8018E684: beq         $v0, $at, L_8018E824
    if (ctx->r2 == ctx->r1) {
        // 0x8018E688: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018E824;
    }
    // 0x8018E688: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018E68C: b           L_8018E868
    // 0x8018E690: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E690: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E694:
    // 0x8018E694: sltiu       $at, $t9, 0x29
    ctx->r1 = ctx->r25 < 0X29 ? 1 : 0;
    // 0x8018E698: beq         $at, $zero, L_8018E864
    if (ctx->r1 == 0) {
        // 0x8018E69C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8018E864;
    }
    // 0x8018E69C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018E6A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E6A4: addu        $at, $at, $t9
    gpr jr_addend_8018E6AC = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8018E6A8: lw          $t9, 0xB78($at)
    ctx->r25 = ADD32(ctx->r1, 0XB78);
    // 0x8018E6AC: jr          $t9
    // 0x8018E6B0: nop

    switch (jr_addend_8018E6AC >> 2) {
        case 0: goto L_8018E7E4; break;
        case 1: goto L_8018E864; break;
        case 2: goto L_8018E864; break;
        case 3: goto L_8018E864; break;
        case 4: goto L_8018E864; break;
        case 5: goto L_8018E864; break;
        case 6: goto L_8018E864; break;
        case 7: goto L_8018E864; break;
        case 8: goto L_8018E864; break;
        case 9: goto L_8018E864; break;
        case 10: goto L_8018E7F4; break;
        case 11: goto L_8018E864; break;
        case 12: goto L_8018E864; break;
        case 13: goto L_8018E864; break;
        case 14: goto L_8018E864; break;
        case 15: goto L_8018E864; break;
        case 16: goto L_8018E864; break;
        case 17: goto L_8018E864; break;
        case 18: goto L_8018E864; break;
        case 19: goto L_8018E864; break;
        case 20: goto L_8018E804; break;
        case 21: goto L_8018E864; break;
        case 22: goto L_8018E864; break;
        case 23: goto L_8018E864; break;
        case 24: goto L_8018E864; break;
        case 25: goto L_8018E864; break;
        case 26: goto L_8018E864; break;
        case 27: goto L_8018E864; break;
        case 28: goto L_8018E864; break;
        case 29: goto L_8018E864; break;
        case 30: goto L_8018E814; break;
        case 31: goto L_8018E864; break;
        case 32: goto L_8018E864; break;
        case 33: goto L_8018E864; break;
        case 34: goto L_8018E864; break;
        case 35: goto L_8018E864; break;
        case 36: goto L_8018E864; break;
        case 37: goto L_8018E864; break;
        case 38: goto L_8018E864; break;
        case 39: goto L_8018E864; break;
        case 40: goto L_8018E6F4; break;
        default: switch_error(__func__, 0x8018E6AC, 0x801C0B78);
    }
    // 0x8018E6B0: nop

L_8018E6B4:
    // 0x8018E6B4: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8018E6B8: bne         $at, $zero, L_8018E6E0
    if (ctx->r1 != 0) {
        // 0x8018E6BC: addiu       $t0, $v0, -0x9B
        ctx->r8 = ADD32(ctx->r2, -0X9B);
            goto L_8018E6E0;
    }
    // 0x8018E6BC: addiu       $t0, $v0, -0x9B
    ctx->r8 = ADD32(ctx->r2, -0X9B);
    // 0x8018E6C0: sltiu       $at, $t0, 0x38
    ctx->r1 = ctx->r8 < 0X38 ? 1 : 0;
    // 0x8018E6C4: beq         $at, $zero, L_8018E864
    if (ctx->r1 == 0) {
        // 0x8018E6C8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8018E864;
    }
    // 0x8018E6C8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8018E6CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E6D0: addu        $at, $at, $t0
    gpr jr_addend_8018E6D8 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8018E6D4: lw          $t0, 0xC1C($at)
    ctx->r8 = ADD32(ctx->r1, 0XC1C);
    // 0x8018E6D8: jr          $t0
    // 0x8018E6DC: nop

    switch (jr_addend_8018E6D8 >> 2) {
        case 0: goto L_8018E724; break;
        case 1: goto L_8018E864; break;
        case 2: goto L_8018E864; break;
        case 3: goto L_8018E864; break;
        case 4: goto L_8018E864; break;
        case 5: goto L_8018E864; break;
        case 6: goto L_8018E864; break;
        case 7: goto L_8018E864; break;
        case 8: goto L_8018E864; break;
        case 9: goto L_8018E864; break;
        case 10: goto L_8018E864; break;
        case 11: goto L_8018E864; break;
        case 12: goto L_8018E864; break;
        case 13: goto L_8018E864; break;
        case 14: goto L_8018E864; break;
        case 15: goto L_8018E864; break;
        case 16: goto L_8018E864; break;
        case 17: goto L_8018E864; break;
        case 18: goto L_8018E864; break;
        case 19: goto L_8018E864; break;
        case 20: goto L_8018E864; break;
        case 21: goto L_8018E74C; break;
        case 22: goto L_8018E864; break;
        case 23: goto L_8018E864; break;
        case 24: goto L_8018E864; break;
        case 25: goto L_8018E864; break;
        case 26: goto L_8018E864; break;
        case 27: goto L_8018E864; break;
        case 28: goto L_8018E864; break;
        case 29: goto L_8018E864; break;
        case 30: goto L_8018E864; break;
        case 31: goto L_8018E864; break;
        case 32: goto L_8018E770; break;
        case 33: goto L_8018E864; break;
        case 34: goto L_8018E864; break;
        case 35: goto L_8018E864; break;
        case 36: goto L_8018E864; break;
        case 37: goto L_8018E864; break;
        case 38: goto L_8018E864; break;
        case 39: goto L_8018E864; break;
        case 40: goto L_8018E864; break;
        case 41: goto L_8018E864; break;
        case 42: goto L_8018E864; break;
        case 43: goto L_8018E794; break;
        case 44: goto L_8018E7B8; break;
        case 45: goto L_8018E864; break;
        case 46: goto L_8018E864; break;
        case 47: goto L_8018E864; break;
        case 48: goto L_8018E864; break;
        case 49: goto L_8018E864; break;
        case 50: goto L_8018E864; break;
        case 51: goto L_8018E864; break;
        case 52: goto L_8018E864; break;
        case 53: goto L_8018E864; break;
        case 54: goto L_8018E864; break;
        case 55: goto L_8018E7CC; break;
        default: switch_error(__func__, 0x8018E6D8, 0x801C0C1C);
    }
    // 0x8018E6DC: nop

L_8018E6E0:
    // 0x8018E6E0: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8018E6E4: beq         $v0, $at, L_8018E710
    if (ctx->r2 == ctx->r1) {
        // 0x8018E6E8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018E710;
    }
    // 0x8018E6E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018E6EC: b           L_8018E868
    // 0x8018E6F0: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E6F0: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E6F4:
    // 0x8018E6F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018E6F8: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x8018E6FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018E700: jal         0x8001D444
    // 0x8018E704: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_24;
    // 0x8018E704: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_24:
    // 0x8018E708: b           L_8018E868
    // 0x8018E70C: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E70C: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E710:
    // 0x8018E710: addiu       $a0, $a0, -0x250C
    ctx->r4 = ADD32(ctx->r4, -0X250C);
    // 0x8018E714: jal         0x800BA808
    // 0x8018E718: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    Radio_PlayMessage(rdram, ctx);
        goto after_25;
    // 0x8018E718: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    after_25:
    // 0x8018E71C: b           L_8018E868
    // 0x8018E720: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E720: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E724:
    // 0x8018E724: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018E728: addiu       $a0, $sp, 0x5C
    ctx->r4 = ADD32(ctx->r29, 0X5C);
    // 0x8018E72C: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8018E730: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018E734: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    // 0x8018E738: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018E73C: jal         0x8018D920
    // 0x8018E740: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    Area6_8018D920(rdram, ctx);
        goto after_26;
    // 0x8018E740: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    after_26:
    // 0x8018E744: b           L_8018E868
    // 0x8018E748: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E748: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E74C:
    // 0x8018E74C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8018E750: lw          $t1, 0x78B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B4);
    // 0x8018E754: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E758: blezl       $t1, L_8018E868
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8018E75C: lwc1        $f4, 0xE8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
            goto L_8018E868;
    }
    goto skip_1;
    // 0x8018E75C: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    skip_1:
    // 0x8018E760: jal         0x8018D920
    // 0x8018E764: addiu       $a0, $a0, 0x48C0
    ctx->r4 = ADD32(ctx->r4, 0X48C0);
    Area6_8018D920(rdram, ctx);
        goto after_27;
    // 0x8018E764: addiu       $a0, $a0, 0x48C0
    ctx->r4 = ADD32(ctx->r4, 0X48C0);
    after_27:
    // 0x8018E768: b           L_8018E868
    // 0x8018E76C: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E76C: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E770:
    // 0x8018E770: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018E774: lw          $t2, 0x78B8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78B8);
    // 0x8018E778: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E77C: blezl       $t2, L_8018E868
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8018E780: lwc1        $f4, 0xE8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
            goto L_8018E868;
    }
    goto skip_2;
    // 0x8018E780: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    skip_2:
    // 0x8018E784: jal         0x8018D920
    // 0x8018E788: addiu       $a0, $a0, 0x4BB4
    ctx->r4 = ADD32(ctx->r4, 0X4BB4);
    Area6_8018D920(rdram, ctx);
        goto after_28;
    // 0x8018E788: addiu       $a0, $a0, 0x4BB4
    ctx->r4 = ADD32(ctx->r4, 0X4BB4);
    after_28:
    // 0x8018E78C: b           L_8018E868
    // 0x8018E790: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E790: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E794:
    // 0x8018E794: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8018E798: lw          $t3, 0x78BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78BC);
    // 0x8018E79C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E7A0: blezl       $t3, L_8018E868
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8018E7A4: lwc1        $f4, 0xE8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
            goto L_8018E868;
    }
    goto skip_3;
    // 0x8018E7A4: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    skip_3:
    // 0x8018E7A8: jal         0x8018D920
    // 0x8018E7AC: addiu       $a0, $a0, 0x4EA8
    ctx->r4 = ADD32(ctx->r4, 0X4EA8);
    Area6_8018D920(rdram, ctx);
        goto after_29;
    // 0x8018E7AC: addiu       $a0, $a0, 0x4EA8
    ctx->r4 = ADD32(ctx->r4, 0X4EA8);
    after_29:
    // 0x8018E7B0: b           L_8018E868
    // 0x8018E7B4: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E7B4: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E7B8:
    // 0x8018E7B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018E7BC: jal         0x8018D4E0
    // 0x8018E7C0: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    Area6_8018D4E0(rdram, ctx);
        goto after_30;
    // 0x8018E7C0: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    after_30:
    // 0x8018E7C4: b           L_8018E868
    // 0x8018E7C8: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E7C8: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E7CC:
    // 0x8018E7CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018E7D0: addiu       $a0, $a0, -0x24D4
    ctx->r4 = ADD32(ctx->r4, -0X24D4);
    // 0x8018E7D4: jal         0x800BA808
    // 0x8018E7D8: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    Radio_PlayMessage(rdram, ctx);
        goto after_31;
    // 0x8018E7D8: addiu       $a1, $zero, 0xB4
    ctx->r5 = ADD32(0, 0XB4);
    after_31:
    // 0x8018E7DC: b           L_8018E868
    // 0x8018E7E0: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E7E0: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E7E4:
    // 0x8018E7E4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8018E7E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E7EC: b           L_8018E864
    // 0x8018E7F0: sh          $t4, 0x4680($at)
    MEM_H(0X4680, ctx->r1) = ctx->r12;
        goto L_8018E864;
    // 0x8018E7F0: sh          $t4, 0x4680($at)
    MEM_H(0X4680, ctx->r1) = ctx->r12;
L_8018E7F4:
    // 0x8018E7F4: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8018E7F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E7FC: b           L_8018E864
    // 0x8018E800: sh          $t5, 0x5250($at)
    MEM_H(0X5250, ctx->r1) = ctx->r13;
        goto L_8018E864;
    // 0x8018E800: sh          $t5, 0x5250($at)
    MEM_H(0X5250, ctx->r1) = ctx->r13;
L_8018E804:
    // 0x8018E804: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8018E808: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E80C: b           L_8018E864
    // 0x8018E810: sh          $t6, 0x5544($at)
    MEM_H(0X5544, ctx->r1) = ctx->r14;
        goto L_8018E864;
    // 0x8018E810: sh          $t6, 0x5544($at)
    MEM_H(0X5544, ctx->r1) = ctx->r14;
L_8018E814:
    // 0x8018E814: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8018E818: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E81C: b           L_8018E864
    // 0x8018E820: sh          $t7, 0x5838($at)
    MEM_H(0X5838, ctx->r1) = ctx->r15;
        goto L_8018E864;
    // 0x8018E820: sh          $t7, 0x5838($at)
    MEM_H(0X5838, ctx->r1) = ctx->r15;
L_8018E824:
    // 0x8018E824: addiu       $a0, $a0, -0x248C
    ctx->r4 = ADD32(ctx->r4, -0X248C);
    // 0x8018E828: jal         0x800BA808
    // 0x8018E82C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_32;
    // 0x8018E82C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_32:
    // 0x8018E830: b           L_8018E868
    // 0x8018E834: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
        goto L_8018E868;
    // 0x8018E834: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E838:
    // 0x8018E838: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E83C: b           L_8018E864
    // 0x8018E840: sh          $t8, 0x4F5C($at)
    MEM_H(0X4F5C, ctx->r1) = ctx->r24;
        goto L_8018E864;
    // 0x8018E840: sh          $t8, 0x4F5C($at)
    MEM_H(0X4F5C, ctx->r1) = ctx->r24;
L_8018E844:
    // 0x8018E844: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E848: b           L_8018E864
    // 0x8018E84C: sh          $t9, 0x4C68($at)
    MEM_H(0X4C68, ctx->r1) = ctx->r25;
        goto L_8018E864;
    // 0x8018E84C: sh          $t9, 0x4C68($at)
    MEM_H(0X4C68, ctx->r1) = ctx->r25;
L_8018E850:
    // 0x8018E850: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018E854: b           L_8018E864
    // 0x8018E858: sh          $t0, 0x4974($at)
    MEM_H(0X4974, ctx->r1) = ctx->r8;
        goto L_8018E864;
    // 0x8018E858: sh          $t0, 0x4974($at)
    MEM_H(0X4974, ctx->r1) = ctx->r8;
L_8018E85C:
    // 0x8018E85C: jal         0x800A6148
    // 0x8018E860: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_33;
    // 0x8018E860: nop

    after_33:
L_8018E864:
    // 0x8018E864: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
L_8018E868:
    // 0x8018E868: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018E86C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018E870: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018E874: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018E878: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E87C: lwc1        $f6, 0xCFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XCFC);
    // 0x8018E880: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E884: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018E888: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E88C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018E890: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018E894: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E898: jal         0x80005E90
    // 0x8018E89C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_34;
    // 0x8018E89C: nop

    after_34:
    // 0x8018E8A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E8A4: lwc1        $f4, 0xD00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XD00);
    // 0x8018E8A8: lwc1        $f10, 0xE4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8018E8AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E8B0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E8B4: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8018E8B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E8BC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8018E8C0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018E8C4: jal         0x80005D44
    // 0x8018E8C8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_35;
    // 0x8018E8C8: nop

    after_35:
    // 0x8018E8CC: lw          $t1, 0x1C8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X1C8);
    // 0x8018E8D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018E8D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018E8D8: beql        $t1, $at, L_8018E958
    if (ctx->r9 == ctx->r1) {
        // 0x8018E8DC: lwc1        $f6, 0xEC($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
            goto L_8018E958;
    }
    goto skip_4;
    // 0x8018E8DC: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    skip_4:
    // 0x8018E8E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018E8E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018E8E8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8018E8EC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8018E8F0: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8018E8F4: lwc1        $f10, 0xD0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x8018E8F8: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x8018E8FC: jal         0x80006A20
    // 0x8018E900: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_36;
    // 0x8018E900: swc1        $f10, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f10.u32l;
    after_36:
    // 0x8018E904: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018E908: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018E90C: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x8018E910: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8018E914: lwc1        $f4, 0xC0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x8018E918: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x8018E91C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018E920: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018E924: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x8018E928: lwc1        $f10, 0xC4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x8018E92C: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8018E930: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    // 0x8018E934: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018E938: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018E93C: lwc1        $f8, 0xC8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x8018E940: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018E944: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
    // 0x8018E948: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x8018E94C: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018E950: swc1        $f4, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f4.u32l;
    // 0x8018E954: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
L_8018E958:
    // 0x8018E958: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018E95C: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x8018E960: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E964: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018E968: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018E96C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018E970: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018E974: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018E978: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018E97C: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x8018E980: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x8018E984: lwc1        $f8, 0xD04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XD04);
    // 0x8018E988: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018E98C: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x8018E990: jal         0x8009BC2C
    // 0x8018E994: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_37;
    // 0x8018E994: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_37:
    // 0x8018E998: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E99C: lwc1        $f10, 0xD08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XD08);
    // 0x8018E9A0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018E9A4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018E9A8: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018E9AC: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018E9B0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018E9B4: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x8018E9B8: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8018E9BC: jal         0x8009BC2C
    // 0x8018E9C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_38;
    // 0x8018E9C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_38:
    // 0x8018E9C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E9C8: lwc1        $f4, 0xD0C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XD0C);
    // 0x8018E9CC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018E9D0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018E9D4: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018E9D8: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018E9DC: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8018E9E0: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x8018E9E4: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8018E9E8: jal         0x8009BC2C
    // 0x8018E9EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_39;
    // 0x8018E9EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_39:
    // 0x8018E9F0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018E9F4: lwc1        $f6, 0xD10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD10);
    // 0x8018E9F8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018E9FC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018EA00: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018EA04: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018EA08: lw          $a2, 0x7A4C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A4C);
    // 0x8018EA0C: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x8018EA10: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8018EA14: jal         0x8009BC2C
    // 0x8018EA18: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_40;
    // 0x8018EA18: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_40:
    // 0x8018EA1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EA20: lwc1        $f8, 0xD14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XD14);
    // 0x8018EA24: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018EA28: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018EA2C: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018EA30: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018EA34: lw          $a2, 0x7A4C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A4C);
    // 0x8018EA38: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x8018EA3C: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8018EA40: jal         0x8009BC2C
    // 0x8018EA44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_41;
    // 0x8018EA44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_41:
    // 0x8018EA48: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018EA4C: lwc1        $f10, 0xD18($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XD18);
    // 0x8018EA50: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018EA54: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018EA58: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8018EA5C: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8018EA60: lw          $a2, 0x7A4C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A4C);
    // 0x8018EA64: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x8018EA68: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8018EA6C: jal         0x8009BC2C
    // 0x8018EA70: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_42;
    // 0x8018EA70: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_42:
    // 0x8018EA74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018EA78: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018EA7C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8018EA80: jr          $ra
    // 0x8018EA84: nop

    return;
    // 0x8018EA84: nop

;}
RECOMP_FUNC void Aquas_AqJellyfish_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BC530: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801BC534: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801BC538: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801BC53C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801BC540: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801BC544: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801BC548: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x801BC54C: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801BC550: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x801BC554: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x801BC558: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801BC55C: addiu       $t7, $t7, 0x4B8
    ctx->r15 = ADD32(ctx->r15, 0X4B8);
    // 0x801BC560: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801BC564: addiu       $t6, $sp, 0x64
    ctx->r14 = ADD32(ctx->r29, 0X64);
    // 0x801BC568: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x801BC56C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801BC570: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801BC574: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x801BC578: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801BC57C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801BC580: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x801BC584: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x801BC588: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x801BC58C: jal         0x800B8DD0
    // 0x801BC590: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801BC590: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_0:
    // 0x801BC594: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x801BC598: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801BC59C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x801BC5A0: lhu         $t2, 0xC6($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XC6);
    // 0x801BC5A4: lui         $a1, 0xFA00
    ctx->r5 = S32(0XFA00 << 16);
    // 0x801BC5A8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x801BC5AC: bne         $t3, $zero, L_801BC5F4
    if (ctx->r11 != 0) {
        // 0x801BC5B0: nop
    
            goto L_801BC5F4;
    }
    // 0x801BC5B0: nop

    // 0x801BC5B4: lui         $a1, 0xFA00
    ctx->r5 = S32(0XFA00 << 16);
    // 0x801BC5B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BC5BC: lui         $at, 0xBFFF
    ctx->r1 = S32(0XBFFF << 16);
    // 0x801BC5C0: ori         $at, $at, 0xDF00
    ctx->r1 = ctx->r1 | 0XDF00;
    // 0x801BC5C4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801BC5C8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801BC5CC: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x801BC5D0: lwc1        $f4, 0x118($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X118);
    // 0x801BC5D4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801BC5D8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801BC5DC: nop

    // 0x801BC5E0: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x801BC5E4: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x801BC5E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801BC5EC: b           L_801BC610
    // 0x801BC5F0: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
        goto L_801BC610;
    // 0x801BC5F0: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
L_801BC5F4:
    // 0x801BC5F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BC5F8: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x801BC5FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801BC600: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801BC604: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801BC608: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x801BC60C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
L_801BC610:
    // 0x801BC610: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x801BC614: sltiu       $at, $t3, 0xB
    ctx->r1 = ctx->r11 < 0XB ? 1 : 0;
    // 0x801BC618: beq         $at, $zero, L_801BC7A4
    if (ctx->r1 == 0) {
        // 0x801BC61C: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_801BC7A4;
    }
    // 0x801BC61C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801BC620: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BC624: addu        $at, $at, $t3
    gpr jr_addend_801BC62C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801BC628: lw          $t3, 0x2190($at)
    ctx->r11 = ADD32(ctx->r1, 0X2190);
    // 0x801BC62C: jr          $t3
    // 0x801BC630: nop

    switch (jr_addend_801BC62C >> 2) {
        case 0: goto L_801BC634; break;
        case 1: goto L_801BC650; break;
        case 2: goto L_801BC66C; break;
        case 3: goto L_801BC6CC; break;
        case 4: goto L_801BC72C; break;
        case 5: goto L_801BC7A4; break;
        case 6: goto L_801BC7A4; break;
        case 7: goto L_801BC7A4; break;
        case 8: goto L_801BC7A4; break;
        case 9: goto L_801BC7A4; break;
        case 10: goto L_801BC78C; break;
        default: switch_error(__func__, 0x801BC62C, 0x801C2190);
    }
    // 0x801BC630: nop

L_801BC634:
    // 0x801BC634: lwc1        $f8, 0x144($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X144);
    // 0x801BC638: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x801BC63C: lwc1        $f10, 0x150($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X150);
    // 0x801BC640: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x801BC644: lwc1        $f16, 0x15C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X15C);
    // 0x801BC648: b           L_801BC7A4
    // 0x801BC64C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
        goto L_801BC7A4;
    // 0x801BC64C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
L_801BC650:
    // 0x801BC650: lwc1        $f18, 0x148($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X148);
    // 0x801BC654: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x801BC658: lwc1        $f4, 0x154($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X154);
    // 0x801BC65C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x801BC660: lwc1        $f6, 0x160($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X160);
    // 0x801BC664: b           L_801BC7A4
    // 0x801BC668: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
        goto L_801BC7A4;
    // 0x801BC668: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
L_801BC66C:
    // 0x801BC66C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BC670: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801BC674: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801BC678: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x801BC67C: lwc1        $f8, 0x138($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X138);
    // 0x801BC680: lwc1        $f4, 0x130($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X130);
    // 0x801BC684: lwc1        $f16, 0x128($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X128);
    // 0x801BC688: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801BC68C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801BC690: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801BC694: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801BC698: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x801BC69C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801BC6A0: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x801BC6A4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x801BC6A8: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x801BC6AC: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x801BC6B0: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x801BC6B4: or          $t4, $t6, $t3
    ctx->r12 = ctx->r14 | ctx->r11;
    // 0x801BC6B8: or          $t1, $t4, $t7
    ctx->r9 = ctx->r12 | ctx->r15;
    // 0x801BC6BC: ori         $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 | 0XFF;
    // 0x801BC6C0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801BC6C4: b           L_801BC7A8
    // 0x801BC6C8: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
        goto L_801BC7A8;
    // 0x801BC6C8: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
L_801BC6CC:
    // 0x801BC6CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BC6D0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801BC6D4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801BC6D8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x801BC6DC: lwc1        $f8, 0x124($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X124);
    // 0x801BC6E0: lwc1        $f4, 0x120($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X120);
    // 0x801BC6E4: lwc1        $f16, 0x11C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X11C);
    // 0x801BC6E8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801BC6EC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801BC6F0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x801BC6F4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801BC6F8: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x801BC6FC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x801BC700: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x801BC704: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x801BC708: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x801BC70C: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x801BC710: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x801BC714: or          $t6, $t8, $t2
    ctx->r14 = ctx->r24 | ctx->r10;
    // 0x801BC718: or          $t7, $t6, $t4
    ctx->r15 = ctx->r14 | ctx->r12;
    // 0x801BC71C: ori         $t1, $t7, 0xFF
    ctx->r9 = ctx->r15 | 0XFF;
    // 0x801BC720: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801BC724: b           L_801BC7A8
    // 0x801BC728: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
        goto L_801BC7A8;
    // 0x801BC728: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
L_801BC72C:
    // 0x801BC72C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BC730: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801BC734: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801BC738: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x801BC73C: lwc1        $f8, 0x13C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X13C);
    // 0x801BC740: lwc1        $f4, 0x134($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X134);
    // 0x801BC744: lwc1        $f16, 0x12C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X12C);
    // 0x801BC748: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801BC74C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801BC750: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x801BC754: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801BC758: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x801BC75C: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x801BC760: sll         $t9, $t5, 8
    ctx->r25 = S32(ctx->r13 << 8);
    // 0x801BC764: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x801BC768: andi        $t5, $t3, 0xFF
    ctx->r13 = ctx->r11 & 0XFF;
    // 0x801BC76C: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801BC770: sll         $t1, $t7, 24
    ctx->r9 = S32(ctx->r15 << 24);
    // 0x801BC774: or          $t8, $t9, $t1
    ctx->r24 = ctx->r25 | ctx->r9;
    // 0x801BC778: or          $t4, $t8, $t6
    ctx->r12 = ctx->r24 | ctx->r14;
    // 0x801BC77C: ori         $t7, $t4, 0xFF
    ctx->r15 = ctx->r12 | 0XFF;
    // 0x801BC780: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801BC784: b           L_801BC7A8
    // 0x801BC788: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
        goto L_801BC7A8;
    // 0x801BC788: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
L_801BC78C:
    // 0x801BC78C: lwc1        $f8, 0x140($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X140);
    // 0x801BC790: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x801BC794: lwc1        $f10, 0x14C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14C);
    // 0x801BC798: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x801BC79C: lwc1        $f16, 0x158($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X158);
    // 0x801BC7A0: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
L_801BC7A4:
    // 0x801BC7A4: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
L_801BC7A8:
    // 0x801BC7A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC7AC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801BC7B0: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x801BC7B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801BC7B8: bc1f        L_801BC908
    if (!c1cs) {
        // 0x801BC7BC: nop
    
            goto L_801BC908;
    }
    // 0x801BC7BC: nop

    // 0x801BC7C0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x801BC7C4: lw          $a2, 0x4($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4);
    // 0x801BC7C8: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x801BC7CC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801BC7D0: jal         0x80005B00
    // 0x801BC7D4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x801BC7D4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_1:
    // 0x801BC7D8: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x801BC7DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BC7E0: lwc1        $f6, 0x21BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X21BC);
    // 0x801BC7E4: lwc1        $f4, 0x8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801BC7E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC7EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BC7F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801BC7F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801BC7F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801BC7FC: jal         0x80005FE0
    // 0x801BC800: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x801BC800: nop

    after_2:
    // 0x801BC804: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x801BC808: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BC80C: lwc1        $f16, 0x21C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X21C0);
    // 0x801BC810: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x801BC814: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC818: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BC81C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801BC820: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801BC824: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801BC828: jal         0x80005E90
    // 0x801BC82C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801BC82C: nop

    after_3:
    // 0x801BC830: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x801BC834: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BC838: lwc1        $f6, 0x21C4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X21C4);
    // 0x801BC83C: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801BC840: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC844: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BC848: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801BC84C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801BC850: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801BC854: jal         0x80005D44
    // 0x801BC858: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801BC858: nop

    after_4:
    // 0x801BC85C: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x801BC860: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC864: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x801BC868: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x801BC86C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x801BC870: beq         $t8, $zero, L_801BC900
    if (ctx->r24 == 0) {
        // 0x801BC874: nop
    
            goto L_801BC900;
    }
    // 0x801BC874: nop

    // 0x801BC878: jal         0x80006970
    // 0x801BC87C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x801BC87C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_5:
    // 0x801BC880: jal         0x8005F670
    // 0x801BC884: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    Display_SetSecondLight(rdram, ctx);
        goto after_6;
    // 0x801BC884: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_6:
    // 0x801BC888: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC88C: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801BC890: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x801BC894: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801BC898: jal         0x80005754
    // 0x801BC89C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_7;
    // 0x801BC89C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x801BC8A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC8A4: jal         0x80005708
    // 0x801BC8A8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_8;
    // 0x801BC8A8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_8:
    // 0x801BC8AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC8B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801BC8B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801BC8B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801BC8BC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x801BC8C0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801BC8C4: jal         0x80005C34
    // 0x801BC8C8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x801BC8C8: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_9:
    // 0x801BC8CC: jal         0x80006EB8
    // 0x801BC8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x801BC8D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801BC8D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BC8D8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801BC8DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BC8E0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801BC8E4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801BC8E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801BC8EC: lw          $t9, 0x74($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X74);
    // 0x801BC8F0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801BC8F4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801BC8F8: jal         0x80005740
    // 0x801BC8FC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x801BC8FC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_11:
L_801BC900:
    // 0x801BC900: b           L_801BC908
    // 0x801BC904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801BC908;
    // 0x801BC904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801BC908:
    // 0x801BC908: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801BC90C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801BC910: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801BC914: jr          $ra
    // 0x801BC918: nop

    return;
    // 0x801BC918: nop

;}
RECOMP_FUNC void Zoness_Effect394_Setup2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193970: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80193974: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80193978: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019397C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80193980: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80193984: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80193988: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8019398C: jal         0x80061474
    // 0x80193990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80193990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80193994: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193998: lwc1        $f4, 0xF3C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XF3C);
    // 0x8019399C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801939A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801939A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801939A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801939AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801939B0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801939B4: jal         0x80005E90
    // 0x801939B8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801939B8: nop

    after_1:
    // 0x801939BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801939C0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801939C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801939C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801939CC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801939D0: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801939D4: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x801939D8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x801939DC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801939E0: jal         0x80006970
    // 0x801939E4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801939E4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801939E8: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801939EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801939F0: addiu       $t7, $zero, 0x18A
    ctx->r15 = ADD32(0, 0X18A);
    // 0x801939F4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x801939F8: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x801939FC: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x80193A00: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80193A04: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80193A08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80193A0C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80193A10: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80193A14: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80193A18: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80193A1C: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x80193A20: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80193A24: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80193A28: jal         0x80004EB0
    // 0x80193A2C: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80193A2C: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    after_3:
    // 0x80193A30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80193A34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193A38: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80193A3C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193A40: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80193A44: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80193A48: jal         0x80004EB0
    // 0x80193A4C: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80193A4C: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80193A50: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80193A54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193A58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80193A5C: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x80193A60: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80193A64: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x80193A68: sh          $t9, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r25;
    // 0x80193A6C: sh          $t0, 0x78($s0)
    MEM_H(0X78, ctx->r16) = ctx->r8;
    // 0x80193A70: sh          $t1, 0x7A($s0)
    MEM_H(0X7A, ctx->r16) = ctx->r9;
    // 0x80193A74: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80193A78: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80193A7C: jal         0x800612B8
    // 0x80193A80: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x80193A80: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    after_5:
    // 0x80193A84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193A88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80193A8C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80193A90: jr          $ra
    // 0x80193A94: nop

    return;
    // 0x80193A94: nop

;}
RECOMP_FUNC void Aquas_AqSpindlyFish_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B6E54: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801B6E58: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801B6E5C: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801B6E60: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801B6E64: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B6E68: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6E6C: swc1        $f4, 0x18C($a0)
    MEM_W(0X18C, ctx->r4) = ctx->f4.u32l;
    // 0x801B6E70: swc1        $f6, 0x190($a0)
    MEM_W(0X190, ctx->r4) = ctx->f6.u32l;
    // 0x801B6E74: swc1        $f8, 0x194($a0)
    MEM_W(0X194, ctx->r4) = ctx->f8.u32l;
    // 0x801B6E78: swc1        $f10, 0x240($a0)
    MEM_W(0X240, ctx->r4) = ctx->f10.u32l;
    // 0x801B6E7C: swc1        $f16, 0x244($a0)
    MEM_W(0X244, ctx->r4) = ctx->f16.u32l;
    // 0x801B6E80: swc1        $f18, 0x248($a0)
    MEM_W(0X248, ctx->r4) = ctx->f18.u32l;
    // 0x801B6E84: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6E88: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B6E8C: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801B6E90: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801B6E94: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801B6E98: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801B6E9C: swc1        $f18, 0x254($a0)
    MEM_W(0X254, ctx->r4) = ctx->f18.u32l;
    // 0x801B6EA0: swc1        $f16, 0x250($a0)
    MEM_W(0X250, ctx->r4) = ctx->f16.u32l;
    // 0x801B6EA4: swc1        $f10, 0x24C($a0)
    MEM_W(0X24C, ctx->r4) = ctx->f10.u32l;
    // 0x801B6EA8: swc1        $f8, 0x1A0($a0)
    MEM_W(0X1A0, ctx->r4) = ctx->f8.u32l;
    // 0x801B6EAC: swc1        $f6, 0x19C($a0)
    MEM_W(0X19C, ctx->r4) = ctx->f6.u32l;
    // 0x801B6EB0: swc1        $f4, 0x198($a0)
    MEM_W(0X198, ctx->r4) = ctx->f4.u32l;
    // 0x801B6EB4: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801B6EB8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801B6EBC: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801B6EC0: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801B6EC4: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B6EC8: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6ECC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801B6ED0: addiu       $v1, $a0, 0x24
    ctx->r3 = ADD32(ctx->r4, 0X24);
    // 0x801B6ED4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x801B6ED8: swc1        $f4, 0x1A4($a0)
    MEM_W(0X1A4, ctx->r4) = ctx->f4.u32l;
    // 0x801B6EDC: swc1        $f6, 0x1A8($a0)
    MEM_W(0X1A8, ctx->r4) = ctx->f6.u32l;
    // 0x801B6EE0: swc1        $f8, 0x1AC($a0)
    MEM_W(0X1AC, ctx->r4) = ctx->f8.u32l;
    // 0x801B6EE4: swc1        $f10, 0x258($a0)
    MEM_W(0X258, ctx->r4) = ctx->f10.u32l;
    // 0x801B6EE8: swc1        $f16, 0x25C($a0)
    MEM_W(0X25C, ctx->r4) = ctx->f16.u32l;
    // 0x801B6EEC: swc1        $f18, 0x260($a0)
    MEM_W(0X260, ctx->r4) = ctx->f18.u32l;
L_801B6EF0:
    // 0x801B6EF0: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801B6EF4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801B6EF8: addiu       $v1, $v1, 0x30
    ctx->r3 = ADD32(ctx->r3, 0X30);
    // 0x801B6EFC: swc1        $f4, 0x15C($v1)
    MEM_W(0X15C, ctx->r3) = ctx->f4.u32l;
    // 0x801B6F00: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801B6F04: swc1        $f6, 0x160($v1)
    MEM_W(0X160, ctx->r3) = ctx->f6.u32l;
    // 0x801B6F08: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801B6F0C: swc1        $f8, 0x164($v1)
    MEM_W(0X164, ctx->r3) = ctx->f8.u32l;
    // 0x801B6F10: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801B6F14: swc1        $f10, 0x210($v1)
    MEM_W(0X210, ctx->r3) = ctx->f10.u32l;
    // 0x801B6F18: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B6F1C: swc1        $f16, 0x214($v1)
    MEM_W(0X214, ctx->r3) = ctx->f16.u32l;
    // 0x801B6F20: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6F24: swc1        $f18, 0x218($v1)
    MEM_W(0X218, ctx->r3) = ctx->f18.u32l;
    // 0x801B6F28: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801B6F2C: swc1        $f4, 0x168($v1)
    MEM_W(0X168, ctx->r3) = ctx->f4.u32l;
    // 0x801B6F30: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801B6F34: swc1        $f6, 0x16C($v1)
    MEM_W(0X16C, ctx->r3) = ctx->f6.u32l;
    // 0x801B6F38: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801B6F3C: swc1        $f8, 0x170($v1)
    MEM_W(0X170, ctx->r3) = ctx->f8.u32l;
    // 0x801B6F40: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801B6F44: swc1        $f10, 0x21C($v1)
    MEM_W(0X21C, ctx->r3) = ctx->f10.u32l;
    // 0x801B6F48: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B6F4C: swc1        $f16, 0x220($v1)
    MEM_W(0X220, ctx->r3) = ctx->f16.u32l;
    // 0x801B6F50: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6F54: swc1        $f18, 0x224($v1)
    MEM_W(0X224, ctx->r3) = ctx->f18.u32l;
    // 0x801B6F58: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801B6F5C: swc1        $f4, 0x174($v1)
    MEM_W(0X174, ctx->r3) = ctx->f4.u32l;
    // 0x801B6F60: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801B6F64: swc1        $f6, 0x178($v1)
    MEM_W(0X178, ctx->r3) = ctx->f6.u32l;
    // 0x801B6F68: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801B6F6C: swc1        $f8, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = ctx->f8.u32l;
    // 0x801B6F70: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801B6F74: swc1        $f10, 0x228($v1)
    MEM_W(0X228, ctx->r3) = ctx->f10.u32l;
    // 0x801B6F78: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B6F7C: swc1        $f16, 0x22C($v1)
    MEM_W(0X22C, ctx->r3) = ctx->f16.u32l;
    // 0x801B6F80: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6F84: swc1        $f18, 0x230($v1)
    MEM_W(0X230, ctx->r3) = ctx->f18.u32l;
    // 0x801B6F88: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801B6F8C: swc1        $f4, 0x180($v1)
    MEM_W(0X180, ctx->r3) = ctx->f4.u32l;
    // 0x801B6F90: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801B6F94: swc1        $f6, 0x184($v1)
    MEM_W(0X184, ctx->r3) = ctx->f6.u32l;
    // 0x801B6F98: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801B6F9C: swc1        $f8, 0x188($v1)
    MEM_W(0X188, ctx->r3) = ctx->f8.u32l;
    // 0x801B6FA0: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x801B6FA4: swc1        $f10, 0x234($v1)
    MEM_W(0X234, ctx->r3) = ctx->f10.u32l;
    // 0x801B6FA8: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x801B6FAC: swc1        $f16, 0x238($v1)
    MEM_W(0X238, ctx->r3) = ctx->f16.u32l;
    // 0x801B6FB0: lwc1        $f18, 0x18($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6FB4: bne         $v0, $a1, L_801B6EF0
    if (ctx->r2 != ctx->r5) {
        // 0x801B6FB8: swc1        $f18, 0x23C($v1)
        MEM_W(0X23C, ctx->r3) = ctx->f18.u32l;
            goto L_801B6EF0;
    }
    // 0x801B6FB8: swc1        $f18, 0x23C($v1)
    MEM_W(0X23C, ctx->r3) = ctx->f18.u32l;
    // 0x801B6FBC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801B6FC0: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x801B6FC4: sh          $zero, 0xCE($a0)
    MEM_H(0XCE, ctx->r4) = 0;
    // 0x801B6FC8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801B6FCC: nop

    // 0x801B6FD0: bc1tl       L_801B6FEC
    if (c1cs) {
        // 0x801B6FD4: lwc1        $f10, 0xC($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
            goto L_801B6FEC;
    }
    goto skip_0;
    // 0x801B6FD4: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x801B6FD8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801B6FDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801B6FE0: sh          $t6, 0xB8($a0)
    MEM_H(0XB8, ctx->r4) = ctx->r14;
    // 0x801B6FE4: swc1        $f8, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f8.u32l;
    // 0x801B6FE8: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
L_801B6FEC:
    // 0x801B6FEC: swc1        $f10, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f10.u32l;
    // 0x801B6FF0: jr          $ra
    // 0x801B6FF4: nop

    return;
    // 0x801B6FF4: nop

;}
RECOMP_FUNC void Zoness_80199E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199E9C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80199EA0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80199EA4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80199EA8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80199EAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80199EB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80199EB4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199EB8: lwc1        $f4, 0x25D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25D8);
    // 0x80199EBC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199EC0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80199EC4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80199EC8: lwc1        $f6, 0x121C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X121C);
    // 0x80199ECC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x80199ED0: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x80199ED4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80199ED8: jal         0x8009BC2C
    // 0x80199EDC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80199EDC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80199EE0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80199EE4: addiu       $v0, $v0, 0x24E8
    ctx->r2 = ADD32(ctx->r2, 0X24E8);
    // 0x80199EE8: lwc1        $f10, 0xF4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XF4);
    // 0x80199EEC: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80199EF0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80199EF4: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80199EF8: lwc1        $f18, 0xF8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XF8);
    // 0x80199EFC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80199F00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80199F04: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80199F08: jr          $ra
    // 0x80199F0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80199F0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Aquas_AqCoral_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BB0C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801BB0C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801BB0CC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801BB0D0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x801BB0D4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801BB0D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801BB0DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801BB0E0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801BB0E4: addiu       $t6, $t6, 0x338
    ctx->r14 = ADD32(ctx->r14, 0X338);
    // 0x801BB0E8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x801BB0EC: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x801BB0F0: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x801BB0F4: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801BB0F8: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x801BB0FC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x801BB100: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x801BB104: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x801BB108: sltiu       $at, $t1, 0x9
    ctx->r1 = ctx->r9 < 0X9 ? 1 : 0;
    // 0x801BB10C: beql        $t0, $zero, L_801BB1F4
    if (ctx->r8 == 0) {
        // 0x801BB110: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801BB1F4;
    }
    goto skip_0;
    // 0x801BB110: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801BB114: beq         $at, $zero, L_801BB1F0
    if (ctx->r1 == 0) {
        // 0x801BB118: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_801BB1F0;
    }
    // 0x801BB118: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801BB11C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BB120: addu        $at, $at, $t1
    gpr jr_addend_801BB128 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x801BB124: lw          $t1, 0x213C($at)
    ctx->r9 = ADD32(ctx->r1, 0X213C);
    // 0x801BB128: jr          $t1
    // 0x801BB12C: nop

    switch (jr_addend_801BB128 >> 2) {
        case 0: goto L_801BB130; break;
        case 1: goto L_801BB158; break;
        case 2: goto L_801BB180; break;
        case 3: goto L_801BB1A8; break;
        case 4: goto L_801BB1F0; break;
        case 5: goto L_801BB1F0; break;
        case 6: goto L_801BB1F0; break;
        case 7: goto L_801BB1F0; break;
        case 8: goto L_801BB1D0; break;
        default: switch_error(__func__, 0x801BB128, 0x801C213C);
    }
    // 0x801BB12C: nop

L_801BB130:
    // 0x801BB130: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801BB134: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801BB138: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB13C: jal         0x80006970
    // 0x801BB140: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x801BB140: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    after_0:
    // 0x801BB144: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB148: jal         0x80006AB8
    // 0x801BB14C: addiu       $a1, $s0, 0x1C8
    ctx->r5 = ADD32(ctx->r16, 0X1C8);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x801BB14C: addiu       $a1, $s0, 0x1C8
    ctx->r5 = ADD32(ctx->r16, 0X1C8);
    after_1:
    // 0x801BB150: b           L_801BB1F4
    // 0x801BB154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801BB1F4;
    // 0x801BB154: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801BB158:
    // 0x801BB158: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801BB15C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801BB160: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB164: jal         0x80006970
    // 0x801BB168: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801BB168: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    after_2:
    // 0x801BB16C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB170: jal         0x80006AB8
    // 0x801BB174: addiu       $a1, $s0, 0x1D4
    ctx->r5 = ADD32(ctx->r16, 0X1D4);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_3;
    // 0x801BB174: addiu       $a1, $s0, 0x1D4
    ctx->r5 = ADD32(ctx->r16, 0X1D4);
    after_3:
    // 0x801BB178: b           L_801BB1F4
    // 0x801BB17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801BB1F4;
    // 0x801BB17C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801BB180:
    // 0x801BB180: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801BB184: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801BB188: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB18C: jal         0x80006970
    // 0x801BB190: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x801BB190: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    after_4:
    // 0x801BB194: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB198: jal         0x80006AB8
    // 0x801BB19C: addiu       $a1, $s0, 0x1E0
    ctx->r5 = ADD32(ctx->r16, 0X1E0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_5;
    // 0x801BB19C: addiu       $a1, $s0, 0x1E0
    ctx->r5 = ADD32(ctx->r16, 0X1E0);
    after_5:
    // 0x801BB1A0: b           L_801BB1F4
    // 0x801BB1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801BB1F4;
    // 0x801BB1A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801BB1A8:
    // 0x801BB1A8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801BB1AC: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801BB1B0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB1B4: jal         0x80006970
    // 0x801BB1B8: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x801BB1B8: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    after_6:
    // 0x801BB1BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB1C0: jal         0x80006AB8
    // 0x801BB1C4: addiu       $a1, $s0, 0x1EC
    ctx->r5 = ADD32(ctx->r16, 0X1EC);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_7;
    // 0x801BB1C4: addiu       $a1, $s0, 0x1EC
    ctx->r5 = ADD32(ctx->r16, 0X1EC);
    after_7:
    // 0x801BB1C8: b           L_801BB1F4
    // 0x801BB1CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801BB1F4;
    // 0x801BB1CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801BB1D0:
    // 0x801BB1D0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801BB1D4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801BB1D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB1DC: jal         0x80006970
    // 0x801BB1E0: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x801BB1E0: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    after_8:
    // 0x801BB1E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801BB1E8: jal         0x80006AB8
    // 0x801BB1EC: addiu       $a1, $s0, 0x1F8
    ctx->r5 = ADD32(ctx->r16, 0X1F8);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_9;
    // 0x801BB1EC: addiu       $a1, $s0, 0x1F8
    ctx->r5 = ADD32(ctx->r16, 0X1F8);
    after_9:
L_801BB1F0:
    // 0x801BB1F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801BB1F4:
    // 0x801BB1F4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801BB1F8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801BB1FC: jr          $ra
    // 0x801BB200: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801BB200: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Solar_ActorDebris_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A1E14: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A1E18: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801A1E1C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801A1E20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x801A1E24: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801A1E28: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801A1E2C: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x801A1E30: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x801A1E34: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_801A1E38:
    // 0x801A1E38: bnel        $t6, $zero, L_801A1E94
    if (ctx->r14 != 0) {
        // 0x801A1E3C: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_801A1E94;
    }
    goto skip_0;
    // 0x801A1E3C: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_0:
    // 0x801A1E40: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801A1E44: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801A1E48: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801A1E4C: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801A1E50: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801A1E54: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801A1E58: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x801A1E5C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801A1E60: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801A1E64: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x801A1E68: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A1E6C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A1E70: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801A1E74: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801A1E78: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801A1E7C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x801A1E80: jal         0x801A1CD8
    // 0x801A1E84: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    Solar_ActorDebris_Setup(rdram, ctx);
        goto after_0;
    // 0x801A1E84: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    after_0:
    // 0x801A1E88: b           L_801A1EA4
    // 0x801A1E8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801A1EA4;
    // 0x801A1E8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801A1E90: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_801A1E94:
    // 0x801A1E94: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x801A1E98: beql        $at, $zero, L_801A1E38
    if (ctx->r1 == 0) {
        // 0x801A1E9C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_801A1E38;
    }
    goto skip_1;
    // 0x801A1E9C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x801A1EA0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801A1EA4:
    // 0x801A1EA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801A1EA8: jr          $ra
    // 0x801A1EAC: nop

    return;
    // 0x801A1EAC: nop

;}
RECOMP_FUNC void Zoness_ZoBird_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190204: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80190208: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8019020C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80190210: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80190214: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80190218: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019021C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80190220: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80190224: addiu       $t6, $t6, -0xAA0
    ctx->r14 = ADD32(ctx->r14, -0XAA0);
    // 0x80190228: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8019022C: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x80190230: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80190234: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80190238: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8019023C: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x80190240: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x80190244: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190248: bne         $t0, $at, L_8019041C
    if (ctx->r8 != ctx->r1) {
        // 0x8019024C: sltiu       $at, $a0, 0xB
        ctx->r1 = ctx->r4 < 0XB ? 1 : 0;
            goto L_8019041C;
    }
    // 0x8019024C: sltiu       $at, $a0, 0xB
    ctx->r1 = ctx->r4 < 0XB ? 1 : 0;
    // 0x80190250: beq         $at, $zero, L_8019041C
    if (ctx->r1 == 0) {
        // 0x80190254: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8019041C;
    }
    // 0x80190254: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80190258: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019025C: addu        $at, $at, $t1
    gpr jr_addend_80190264 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80190260: lw          $t1, 0xDD8($at)
    ctx->r9 = ADD32(ctx->r1, 0XDD8);
    // 0x80190264: jr          $t1
    // 0x80190268: nop

    switch (jr_addend_80190264 >> 2) {
        case 0: goto L_8019026C; break;
        case 1: goto L_80190294; break;
        case 2: goto L_801902BC; break;
        case 3: goto L_801902E4; break;
        case 4: goto L_8019030C; break;
        case 5: goto L_80190334; break;
        case 6: goto L_8019035C; break;
        case 7: goto L_80190384; break;
        case 8: goto L_801903AC; break;
        case 9: goto L_801903D4; break;
        case 10: goto L_801903FC; break;
        default: switch_error(__func__, 0x80190264, 0x801C0DD8);
    }
    // 0x80190268: nop

L_8019026C:
    // 0x8019026C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80190270: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80190274: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190278: jal         0x80006970
    // 0x8019027C: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8019027C: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    after_0:
    // 0x80190280: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190284: jal         0x80006AB8
    // 0x80190288: addiu       $a1, $s0, 0x210
    ctx->r5 = ADD32(ctx->r16, 0X210);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x80190288: addiu       $a1, $s0, 0x210
    ctx->r5 = ADD32(ctx->r16, 0X210);
    after_1:
    // 0x8019028C: b           L_80190420
    // 0x80190290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x80190290: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80190294:
    // 0x80190294: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80190298: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019029C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801902A0: jal         0x80006970
    // 0x801902A4: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801902A4: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    after_2:
    // 0x801902A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801902AC: jal         0x80006AB8
    // 0x801902B0: addiu       $a1, $s0, 0x21C
    ctx->r5 = ADD32(ctx->r16, 0X21C);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_3;
    // 0x801902B0: addiu       $a1, $s0, 0x21C
    ctx->r5 = ADD32(ctx->r16, 0X21C);
    after_3:
    // 0x801902B4: b           L_80190420
    // 0x801902B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x801902B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801902BC:
    // 0x801902BC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801902C0: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801902C4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801902C8: jal         0x80006970
    // 0x801902CC: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x801902CC: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    after_4:
    // 0x801902D0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801902D4: jal         0x80006AB8
    // 0x801902D8: addiu       $a1, $s0, 0x228
    ctx->r5 = ADD32(ctx->r16, 0X228);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_5;
    // 0x801902D8: addiu       $a1, $s0, 0x228
    ctx->r5 = ADD32(ctx->r16, 0X228);
    after_5:
    // 0x801902DC: b           L_80190420
    // 0x801902E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x801902E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801902E4:
    // 0x801902E4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801902E8: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801902EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801902F0: jal         0x80006970
    // 0x801902F4: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x801902F4: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    after_6:
    // 0x801902F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801902FC: jal         0x80006AB8
    // 0x80190300: addiu       $a1, $s0, 0x234
    ctx->r5 = ADD32(ctx->r16, 0X234);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_7;
    // 0x80190300: addiu       $a1, $s0, 0x234
    ctx->r5 = ADD32(ctx->r16, 0X234);
    after_7:
    // 0x80190304: b           L_80190420
    // 0x80190308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x80190308: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019030C:
    // 0x8019030C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80190310: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80190314: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190318: jal         0x80006970
    // 0x8019031C: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x8019031C: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    after_8:
    // 0x80190320: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190324: jal         0x80006AB8
    // 0x80190328: addiu       $a1, $s0, 0x240
    ctx->r5 = ADD32(ctx->r16, 0X240);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_9;
    // 0x80190328: addiu       $a1, $s0, 0x240
    ctx->r5 = ADD32(ctx->r16, 0X240);
    after_9:
    // 0x8019032C: b           L_80190420
    // 0x80190330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x80190330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80190334:
    // 0x80190334: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80190338: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019033C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190340: jal         0x80006970
    // 0x80190344: addiu       $a2, $s0, 0x1C8
    ctx->r6 = ADD32(ctx->r16, 0X1C8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x80190344: addiu       $a2, $s0, 0x1C8
    ctx->r6 = ADD32(ctx->r16, 0X1C8);
    after_10:
    // 0x80190348: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019034C: jal         0x80006AB8
    // 0x80190350: addiu       $a1, $s0, 0x24C
    ctx->r5 = ADD32(ctx->r16, 0X24C);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_11;
    // 0x80190350: addiu       $a1, $s0, 0x24C
    ctx->r5 = ADD32(ctx->r16, 0X24C);
    after_11:
    // 0x80190354: b           L_80190420
    // 0x80190358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x80190358: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019035C:
    // 0x8019035C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80190360: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80190364: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190368: jal         0x80006970
    // 0x8019036C: addiu       $a2, $s0, 0x1D4
    ctx->r6 = ADD32(ctx->r16, 0X1D4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x8019036C: addiu       $a2, $s0, 0x1D4
    ctx->r6 = ADD32(ctx->r16, 0X1D4);
    after_12:
    // 0x80190370: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190374: jal         0x80006AB8
    // 0x80190378: addiu       $a1, $s0, 0x258
    ctx->r5 = ADD32(ctx->r16, 0X258);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_13;
    // 0x80190378: addiu       $a1, $s0, 0x258
    ctx->r5 = ADD32(ctx->r16, 0X258);
    after_13:
    // 0x8019037C: b           L_80190420
    // 0x80190380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x80190380: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80190384:
    // 0x80190384: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80190388: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019038C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190390: jal         0x80006970
    // 0x80190394: addiu       $a2, $s0, 0x1E0
    ctx->r6 = ADD32(ctx->r16, 0X1E0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x80190394: addiu       $a2, $s0, 0x1E0
    ctx->r6 = ADD32(ctx->r16, 0X1E0);
    after_14:
    // 0x80190398: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019039C: jal         0x80006AB8
    // 0x801903A0: addiu       $a1, $s0, 0x264
    ctx->r5 = ADD32(ctx->r16, 0X264);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_15;
    // 0x801903A0: addiu       $a1, $s0, 0x264
    ctx->r5 = ADD32(ctx->r16, 0X264);
    after_15:
    // 0x801903A4: b           L_80190420
    // 0x801903A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x801903A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801903AC:
    // 0x801903AC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801903B0: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801903B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801903B8: jal         0x80006970
    // 0x801903BC: addiu       $a2, $s0, 0x1EC
    ctx->r6 = ADD32(ctx->r16, 0X1EC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x801903BC: addiu       $a2, $s0, 0x1EC
    ctx->r6 = ADD32(ctx->r16, 0X1EC);
    after_16:
    // 0x801903C0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801903C4: jal         0x80006AB8
    // 0x801903C8: addiu       $a1, $s0, 0x270
    ctx->r5 = ADD32(ctx->r16, 0X270);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_17;
    // 0x801903C8: addiu       $a1, $s0, 0x270
    ctx->r5 = ADD32(ctx->r16, 0X270);
    after_17:
    // 0x801903CC: b           L_80190420
    // 0x801903D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x801903D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801903D4:
    // 0x801903D4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801903D8: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801903DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801903E0: jal         0x80006970
    // 0x801903E4: addiu       $a2, $s0, 0x1F8
    ctx->r6 = ADD32(ctx->r16, 0X1F8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_18;
    // 0x801903E4: addiu       $a2, $s0, 0x1F8
    ctx->r6 = ADD32(ctx->r16, 0X1F8);
    after_18:
    // 0x801903E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801903EC: jal         0x80006AB8
    // 0x801903F0: addiu       $a1, $s0, 0x27C
    ctx->r5 = ADD32(ctx->r16, 0X27C);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_19;
    // 0x801903F0: addiu       $a1, $s0, 0x27C
    ctx->r5 = ADD32(ctx->r16, 0X27C);
    after_19:
    // 0x801903F4: b           L_80190420
    // 0x801903F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80190420;
    // 0x801903F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801903FC:
    // 0x801903FC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80190400: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80190404: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190408: jal         0x80006970
    // 0x8019040C: addiu       $a2, $s0, 0x204
    ctx->r6 = ADD32(ctx->r16, 0X204);
    Matrix_MultVec3f(rdram, ctx);
        goto after_20;
    // 0x8019040C: addiu       $a2, $s0, 0x204
    ctx->r6 = ADD32(ctx->r16, 0X204);
    after_20:
    // 0x80190410: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80190414: jal         0x80006AB8
    // 0x80190418: addiu       $a1, $s0, 0x288
    ctx->r5 = ADD32(ctx->r16, 0X288);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_21;
    // 0x80190418: addiu       $a1, $s0, 0x288
    ctx->r5 = ADD32(ctx->r16, 0X288);
    after_21:
L_8019041C:
    // 0x8019041C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80190420:
    // 0x80190420: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80190424: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80190428: jr          $ra
    // 0x8019042C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8019042C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Aquas_AqBacoonMuscle_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AEB44: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x801AEB48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AEB4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801AEB50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AEB54: lhu         $a1, 0xC6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XC6);
    // 0x801AEB58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x801AEB5C: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    // 0x801AEB60: beq         $a1, $zero, L_801AEBB4
    if (ctx->r5 == 0) {
        // 0x801AEB64: lui         $a2, 0xFF
        ctx->r6 = S32(0XFF << 16);
            goto L_801AEBB4;
    }
    // 0x801AEB64: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x801AEB68: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x801AEB6C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801AEB70: bne         $t6, $zero, L_801AEBB4
    if (ctx->r14 != 0) {
        // 0x801AEB74: nop
    
            goto L_801AEBB4;
    }
    // 0x801AEB74: nop

    // 0x801AEB78: lw          $t7, 0x7854($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7854);
    // 0x801AEB7C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801AEB80: beq         $t7, $at, L_801AEBB4
    if (ctx->r15 == ctx->r1) {
        // 0x801AEB84: nop
    
            goto L_801AEBB4;
    }
    // 0x801AEB84: nop

    // 0x801AEB88: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x801AEB8C: lhu         $a1, 0xC6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XC6);
    // 0x801AEB90: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801AEB94: or          $t6, $t9, $zero
    ctx->r14 = ctx->r25 | 0;
    // 0x801AEB98: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    // 0x801AEB9C: bgez        $t6, L_801AEBB0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801AEBA0: andi        $t7, $t6, 0x7
        ctx->r15 = ctx->r14 & 0X7;
            goto L_801AEBB0;
    }
    // 0x801AEBA0: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x801AEBA4: beq         $t7, $zero, L_801AEBB0
    if (ctx->r15 == 0) {
        // 0x801AEBA8: nop
    
            goto L_801AEBB0;
    }
    // 0x801AEBA8: nop

    // 0x801AEBAC: addiu       $t7, $t7, -0x8
    ctx->r15 = ADD32(ctx->r15, -0X8);
L_801AEBB0:
    // 0x801AEBB0: sw          $t7, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r15;
L_801AEBB4:
    // 0x801AEBB4: lui         $v0, 0x602
    ctx->r2 = S32(0X602 << 16);
    // 0x801AEBB8: addiu       $v0, $v0, -0x6F88
    ctx->r2 = ADD32(ctx->r2, -0X6F88);
    // 0x801AEBBC: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x801AEBC0: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x801AEBC4: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801AEBC8: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x801AEBCC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801AEBD0: lw          $v1, 0x54($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X54);
    // 0x801AEBD4: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x801AEBD8: and         $t9, $v0, $a2
    ctx->r25 = ctx->r2 & ctx->r6;
    // 0x801AEBDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801AEBE0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x801AEBE4: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x801AEBE8: beq         $at, $zero, L_801AEC1C
    if (ctx->r1 == 0) {
        // 0x801AEBEC: addu        $ra, $t6, $a3
        ctx->r31 = ADD32(ctx->r14, ctx->r7);
            goto L_801AEC1C;
    }
    // 0x801AEBEC: addu        $ra, $t6, $a3
    ctx->r31 = ADD32(ctx->r14, ctx->r7);
    // 0x801AEBF0: lui         $v0, 0x602
    ctx->r2 = S32(0X602 << 16);
    // 0x801AEBF4: addiu       $v0, $v0, -0x7388
    ctx->r2 = ADD32(ctx->r2, -0X7388);
    // 0x801AEBF8: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x801AEBFC: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x801AEC00: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801AEC04: addu        $t6, $a0, $t9
    ctx->r14 = ADD32(ctx->r4, ctx->r25);
    // 0x801AEC08: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801AEC0C: and         $t8, $v0, $a2
    ctx->r24 = ctx->r2 & ctx->r6;
    // 0x801AEC10: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801AEC14: b           L_801AEC44
    // 0x801AEC18: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
        goto L_801AEC44;
    // 0x801AEC18: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
L_801AEC1C:
    // 0x801AEC1C: lui         $v0, 0x602
    ctx->r2 = S32(0X602 << 16);
    // 0x801AEC20: addiu       $v0, $v0, -0x7788
    ctx->r2 = ADD32(ctx->r2, -0X7788);
    // 0x801AEC24: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x801AEC28: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x801AEC2C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801AEC30: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x801AEC34: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x801AEC38: and         $t7, $v0, $a2
    ctx->r15 = ctx->r2 & ctx->r6;
    // 0x801AEC3C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801AEC40: addu        $t5, $t8, $a3
    ctx->r13 = ADD32(ctx->r24, ctx->r7);
L_801AEC44:
    // 0x801AEC44: bgez        $v1, L_801AEC58
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801AEC48: andi        $v0, $v1, 0x3
        ctx->r2 = ctx->r3 & 0X3;
            goto L_801AEC58;
    }
    // 0x801AEC48: andi        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 & 0X3;
    // 0x801AEC4C: beq         $v0, $zero, L_801AEC58
    if (ctx->r2 == 0) {
        // 0x801AEC50: nop
    
            goto L_801AEC58;
    }
    // 0x801AEC50: nop

    // 0x801AEC54: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_801AEC58:
    // 0x801AEC58: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x801AEC5C: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x801AEC60: bne         $at, $zero, L_801AEC74
    if (ctx->r1 != 0) {
        // 0x801AEC64: or          $t1, $t9, $zero
        ctx->r9 = ctx->r25 | 0;
            goto L_801AEC74;
    }
    // 0x801AEC64: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x801AEC68: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801AEC6C: subu        $v0, $t6, $t9
    ctx->r2 = SUB32(ctx->r14, ctx->r25);
    // 0x801AEC70: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
L_801AEC74:
    // 0x801AEC74: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x801AEC78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AEC7C: lwc1        $f2, 0x1C28($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1C28);
    // 0x801AEC80: bgez        $a1, L_801AEC98
    if (SIGNED(ctx->r5) >= 0) {
        // 0x801AEC84: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801AEC98;
    }
    // 0x801AEC84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801AEC88: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801AEC8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AEC90: nop

    // 0x801AEC94: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_801AEC98:
    // 0x801AEC98: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801AEC9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AECA0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x801AECA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AECA8: div.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801AECAC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x801AECB0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801AECB4: nop

    // 0x801AECB8: bc1f        L_801AECC4
    if (!c1cs) {
        // 0x801AECBC: nop
    
            goto L_801AECC4;
    }
    // 0x801AECBC: nop

    // 0x801AECC0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_801AECC4:
    // 0x801AECC4: lw          $a0, 0x7E7C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7E7C);
    // 0x801AECC8: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801AECCC: addiu       $t4, $t4, 0x3A88
    ctx->r12 = ADD32(ctx->r12, 0X3A88);
    // 0x801AECD0: andi        $t8, $a0, 0x1
    ctx->r24 = ctx->r4 & 0X1;
    // 0x801AECD4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
L_801AECD8:
    // 0x801AECD8: sll         $v0, $t2, 4
    ctx->r2 = S32(ctx->r10 << 4);
    // 0x801AECDC: addu        $a1, $t5, $v0
    ctx->r5 = ADD32(ctx->r13, ctx->r2);
    // 0x801AECE0: addu        $v1, $ra, $v0
    ctx->r3 = ADD32(ctx->r31, ctx->r2);
    // 0x801AECE4: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x801AECE8: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x801AECEC: addiu       $t2, $t3, 0x1
    ctx->r10 = ADD32(ctx->r11, 0X1);
    // 0x801AECF0: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x801AECF4: subu        $t6, $t9, $a2
    ctx->r14 = SUB32(ctx->r25, ctx->r6);
    // 0x801AECF8: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AECFC: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x801AED00: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x801AED04: mflo        $t7
    ctx->r15 = lo;
    // 0x801AED08: bgez        $t7, L_801AED18
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801AED0C: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_801AED18;
    }
    // 0x801AED0C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x801AED10: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x801AED14: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801AED18:
    // 0x801AED18: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801AED1C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AED20: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AED24: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801AED28: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x801AED2C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801AED30: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x801AED34: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x801AED38: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801AED3C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AED40: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x801AED44: nop

    // 0x801AED48: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x801AED4C: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801AED50: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x801AED54: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801AED58: sh          $t9, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r25;
    // 0x801AED5C: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x801AED60: lh          $a3, 0x2($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X2);
    // 0x801AED64: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x801AED68: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AED6C: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x801AED70: mflo        $t9
    ctx->r25 = lo;
    // 0x801AED74: bgez        $t9, L_801AED84
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801AED78: sra         $t8, $t9, 1
        ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
            goto L_801AED84;
    }
    // 0x801AED78: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x801AED7C: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x801AED80: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801AED84:
    // 0x801AED84: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x801AED88: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x801AED8C: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x801AED90: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x801AED94: sll         $t9, $t9, 7
    ctx->r25 = S32(ctx->r25 << 7);
    // 0x801AED98: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x801AED9C: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x801AEDA0: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x801AEDA4: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x801AEDA8: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x801AEDAC: sh          $t6, 0x2($t8)
    MEM_H(0X2, ctx->r24) = ctx->r14;
    // 0x801AEDB0: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x801AEDB4: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x801AEDB8: subu        $t9, $t7, $t0
    ctx->r25 = SUB32(ctx->r15, ctx->r8);
    // 0x801AEDBC: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AEDC0: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x801AEDC4: mflo        $t6
    ctx->r14 = lo;
    // 0x801AEDC8: bgez        $t6, L_801AEDD8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801AEDCC: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_801AEDD8;
    }
    // 0x801AEDCC: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x801AEDD0: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x801AEDD4: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801AEDD8:
    // 0x801AEDD8: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x801AEDDC: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x801AEDE0: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801AEDE4: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x801AEDE8: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x801AEDEC: addu        $t7, $t8, $t0
    ctx->r15 = ADD32(ctx->r24, ctx->r8);
    // 0x801AEDF0: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x801AEDF4: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x801AEDF8: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x801AEDFC: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x801AEE00: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    // 0x801AEE04: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x801AEE08: lhu         $t9, 0x6($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X6);
    // 0x801AEE0C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AEE10: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AEE14: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x801AEE18: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801AEE1C: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x801AEE20: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801AEE24: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x801AEE28: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x801AEE2C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801AEE30: sh          $t9, 0x6($t8)
    MEM_H(0X6, ctx->r24) = ctx->r25;
    // 0x801AEE34: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x801AEE38: lh          $a2, 0x8($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X8);
    // 0x801AEE3C: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x801AEE40: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AEE44: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x801AEE48: mflo        $t9
    ctx->r25 = lo;
    // 0x801AEE4C: bgez        $t9, L_801AEE5C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801AEE50: sra         $t8, $t9, 1
        ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
            goto L_801AEE5C;
    }
    // 0x801AEE50: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x801AEE54: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x801AEE58: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801AEE5C:
    // 0x801AEE5C: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x801AEE60: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x801AEE64: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x801AEE68: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x801AEE6C: sll         $t9, $t9, 7
    ctx->r25 = S32(ctx->r25 << 7);
    // 0x801AEE70: addu        $t6, $t8, $a2
    ctx->r14 = ADD32(ctx->r24, ctx->r6);
    // 0x801AEE74: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x801AEE78: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x801AEE7C: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x801AEE80: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x801AEE84: sh          $t6, 0x8($t8)
    MEM_H(0X8, ctx->r24) = ctx->r14;
    // 0x801AEE88: lh          $t7, 0xA($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XA);
    // 0x801AEE8C: lh          $a3, 0xA($v1)
    ctx->r7 = MEM_H(ctx->r3, 0XA);
    // 0x801AEE90: subu        $t9, $t7, $a3
    ctx->r25 = SUB32(ctx->r15, ctx->r7);
    // 0x801AEE94: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AEE98: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x801AEE9C: mflo        $t6
    ctx->r14 = lo;
    // 0x801AEEA0: bgez        $t6, L_801AEEB0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801AEEA4: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_801AEEB0;
    }
    // 0x801AEEA4: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x801AEEA8: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x801AEEAC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801AEEB0:
    // 0x801AEEB0: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x801AEEB4: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x801AEEB8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801AEEBC: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x801AEEC0: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x801AEEC4: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x801AEEC8: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x801AEECC: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x801AEED0: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x801AEED4: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x801AEED8: sh          $t7, 0xA($t8)
    MEM_H(0XA, ctx->r24) = ctx->r15;
    // 0x801AEEDC: lb          $t9, 0xC($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XC);
    // 0x801AEEE0: lb          $a2, 0xC($v1)
    ctx->r6 = MEM_B(ctx->r3, 0XC);
    // 0x801AEEE4: subu        $t6, $t9, $a2
    ctx->r14 = SUB32(ctx->r25, ctx->r6);
    // 0x801AEEE8: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AEEEC: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x801AEEF0: mflo        $t7
    ctx->r15 = lo;
    // 0x801AEEF4: bgez        $t7, L_801AEF04
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801AEEF8: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_801AEF04;
    }
    // 0x801AEEF8: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x801AEEFC: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x801AEF00: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801AEF04:
    // 0x801AEF04: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AEF08: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AEF0C: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x801AEF10: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801AEF14: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x801AEF18: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x801AEF1C: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801AEF20: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x801AEF24: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x801AEF28: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801AEF2C: sb          $t9, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r25;
    // 0x801AEF30: lb          $t6, 0xD($a1)
    ctx->r14 = MEM_B(ctx->r5, 0XD);
    // 0x801AEF34: lb          $a3, 0xD($v1)
    ctx->r7 = MEM_B(ctx->r3, 0XD);
    // 0x801AEF38: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x801AEF3C: multu       $t7, $t1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AEF40: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x801AEF44: mflo        $t9
    ctx->r25 = lo;
    // 0x801AEF48: bgez        $t9, L_801AEF58
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801AEF4C: sra         $t8, $t9, 1
        ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
            goto L_801AEF58;
    }
    // 0x801AEF4C: sra         $t8, $t9, 1
    ctx->r24 = S32(SIGNED(ctx->r25) >> 1);
    // 0x801AEF50: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x801AEF54: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801AEF58:
    // 0x801AEF58: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x801AEF5C: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x801AEF60: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x801AEF64: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x801AEF68: sll         $t9, $t9, 7
    ctx->r25 = S32(ctx->r25 << 7);
    // 0x801AEF6C: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x801AEF70: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x801AEF74: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x801AEF78: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x801AEF7C: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x801AEF80: sb          $t6, 0xD($t8)
    MEM_B(0XD, ctx->r24) = ctx->r14;
    // 0x801AEF84: lb          $t7, 0xE($a1)
    ctx->r15 = MEM_B(ctx->r5, 0XE);
    // 0x801AEF88: lb          $t0, 0xE($v1)
    ctx->r8 = MEM_B(ctx->r3, 0XE);
    // 0x801AEF8C: subu        $t9, $t7, $t0
    ctx->r25 = SUB32(ctx->r15, ctx->r8);
    // 0x801AEF90: multu       $t9, $t1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AEF94: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x801AEF98: mflo        $t6
    ctx->r14 = lo;
    // 0x801AEF9C: bgez        $t6, L_801AEFAC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801AEFA0: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_801AEFAC;
    }
    // 0x801AEFA0: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x801AEFA4: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x801AEFA8: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_801AEFAC:
    // 0x801AEFAC: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x801AEFB0: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x801AEFB4: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801AEFB8: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x801AEFBC: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x801AEFC0: addu        $t7, $t8, $t0
    ctx->r15 = ADD32(ctx->r24, ctx->r8);
    // 0x801AEFC4: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x801AEFC8: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x801AEFCC: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x801AEFD0: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x801AEFD4: sb          $t7, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r15;
    // 0x801AEFD8: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x801AEFDC: lbu         $t9, 0xF($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0XF);
    // 0x801AEFE0: slti        $at, $t3, 0x1C
    ctx->r1 = SIGNED(ctx->r11) < 0X1C ? 1 : 0;
    // 0x801AEFE4: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AEFE8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AEFEC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x801AEFF0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801AEFF4: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x801AEFF8: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801AEFFC: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x801AF000: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x801AF004: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x801AF008: bne         $at, $zero, L_801AECD8
    if (ctx->r1 != 0) {
        // 0x801AF00C: sb          $t9, 0xF($t8)
        MEM_B(0XF, ctx->r24) = ctx->r25;
            goto L_801AECD8;
    }
    // 0x801AF00C: sb          $t9, 0xF($t8)
    MEM_B(0XF, ctx->r24) = ctx->r25;
    // 0x801AF010: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801AF014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AF018: lwc1        $f2, 0x110($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X110);
    // 0x801AF01C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AF020: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AF024: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x801AF028: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x801AF02C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AF030: lwc1        $f0, 0x118($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X118);
    // 0x801AF034: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801AF038: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AF03C: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801AF040: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801AF044: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801AF048: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AF04C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801AF050: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801AF054: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AF058: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801AF05C: jal         0x80005C34
    // 0x801AF060: nop

    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x801AF060: nop

    after_0:
    // 0x801AF064: lh          $t9, 0xB8($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XB8);
    // 0x801AF068: beq         $t9, $zero, L_801AF088
    if (ctx->r25 == 0) {
        // 0x801AF06C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801AF088;
    }
    // 0x801AF06C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF070: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801AF074: jal         0x800B8DD0
    // 0x801AF078: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801AF078: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_1:
    // 0x801AF07C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF080: b           L_801AF114
    // 0x801AF084: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
        goto L_801AF114;
    // 0x801AF084: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
L_801AF088:
    // 0x801AF088: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801AF08C: lh          $t8, -0xE68($t8)
    ctx->r24 = MEM_H(ctx->r24, -0XE68);
    // 0x801AF090: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801AF094: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF098: bne         $t8, $at, L_801AF0B4
    if (ctx->r24 != ctx->r1) {
        // 0x801AF09C: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_801AF0B4;
    }
    // 0x801AF09C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801AF0A0: jal         0x800B8DD0
    // 0x801AF0A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801AF0A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x801AF0A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF0AC: b           L_801AF114
    // 0x801AF0B0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
        goto L_801AF114;
    // 0x801AF0B0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
L_801AF0B4:
    // 0x801AF0B4: lhu         $t6, 0xC6($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC6);
    // 0x801AF0B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF0BC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801AF0C0: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801AF0C4: bne         $t7, $zero, L_801AF0E4
    if (ctx->r15 != 0) {
        // 0x801AF0C8: addiu       $a1, $zero, 0x1D
        ctx->r5 = ADD32(0, 0X1D);
            goto L_801AF0E4;
    }
    // 0x801AF0C8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x801AF0CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF0D0: jal         0x800B8DD0
    // 0x801AF0D4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801AF0D4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_3:
    // 0x801AF0D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF0DC: b           L_801AF114
    // 0x801AF0E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
        goto L_801AF114;
    // 0x801AF0E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
L_801AF0E4:
    // 0x801AF0E4: jal         0x800B8DD0
    // 0x801AF0E8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x801AF0E8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_4:
    // 0x801AF0EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF0F0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801AF0F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF0F8: lui         $t6, 0xFF00
    ctx->r14 = S32(0XFF00 << 16);
    // 0x801AF0FC: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x801AF100: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF104: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF108: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801AF10C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AF110: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_801AF114:
    // 0x801AF114: jal         0x80006EB8
    // 0x801AF118: nop

    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x801AF118: nop

    after_5:
    // 0x801AF11C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AF120: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801AF124: addiu       $t4, $t4, 0x3A88
    ctx->r12 = ADD32(ctx->r12, 0X3A88);
    // 0x801AF128: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801AF12C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF130: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x801AF134: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x801AF138: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF13C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF140: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x801AF144: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF148: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF14C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF150: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x801AF154: addiu       $t9, $t9, -0x7038
    ctx->r25 = ADD32(ctx->r25, -0X7038);
    // 0x801AF158: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF15C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF160: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x801AF164: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AF168: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF16C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF170: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x801AF174: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x801AF178: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF17C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF180: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF184: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF188: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF18C: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x801AF190: lui         $t8, 0x700
    ctx->r24 = S32(0X700 << 16);
    // 0x801AF194: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF198: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF19C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF1A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF1A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF1A8: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x801AF1AC: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x801AF1B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF1B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF1B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF1BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AF1C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF1C4: lui         $t6, 0x73F
    ctx->r14 = S32(0X73F << 16);
    // 0x801AF1C8: ori         $t6, $t6, 0xC000
    ctx->r14 = ctx->r14 | 0XC000;
    // 0x801AF1CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF1D0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF1D4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF1D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AF1DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF1E0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x801AF1E4: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x801AF1E8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF1EC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF1F0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF1F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF1F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF1FC: lui         $t7, 0x601
    ctx->r15 = S32(0X601 << 16);
    // 0x801AF200: addiu       $t7, $t7, -0x7138
    ctx->r15 = ADD32(ctx->r15, -0X7138);
    // 0x801AF204: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF208: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF20C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF210: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF214: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF218: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x801AF21C: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x801AF220: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF224: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF228: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x801AF22C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AF230: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF234: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF238: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x801AF23C: lui         $v1, 0xBF00
    ctx->r3 = S32(0XBF00 << 16);
    // 0x801AF240: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF244: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF248: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF24C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF250: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF254: lui         $t7, 0x707
    ctx->r15 = S32(0X707 << 16);
    // 0x801AF258: ori         $t7, $t7, 0xF400
    ctx->r15 = ctx->r15 | 0XF400;
    // 0x801AF25C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF260: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF264: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x801AF268: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF26C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF270: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF274: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801AF278: lui         $t7, 0xF548
    ctx->r15 = S32(0XF548 << 16);
    // 0x801AF27C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF280: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF284: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF288: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AF28C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF290: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x801AF294: ori         $t9, $t9, 0x40
    ctx->r25 = ctx->r25 | 0X40;
    // 0x801AF298: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF29C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF2A0: ori         $t7, $t7, 0x400
    ctx->r15 = ctx->r15 | 0X400;
    // 0x801AF2A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AF2A8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF2AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF2B0: lui         $t7, 0x3
    ctx->r15 = S32(0X3 << 16);
    // 0x801AF2B4: ori         $t7, $t7, 0xC03C
    ctx->r15 = ctx->r15 | 0XC03C;
    // 0x801AF2B8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF2BC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF2C0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x801AF2C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF2C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF2CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF2D0: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x801AF2D4: ori         $t8, $t8, 0x38DF
    ctx->r24 = ctx->r24 | 0X38DF;
    // 0x801AF2D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF2DC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF2E0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AF2E4: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x801AF2E8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801AF2EC: lw          $t8, 0x7E7C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7E7C);
    // 0x801AF2F0: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AF2F4: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AF2F8: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x801AF2FC: addu        $t9, $t4, $t7
    ctx->r25 = ADD32(ctx->r12, ctx->r15);
    // 0x801AF300: andi        $t6, $t8, 0x1
    ctx->r14 = ctx->r24 & 0X1;
    // 0x801AF304: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AF308: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AF30C: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x801AF310: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x801AF314: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF318: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF31C: addiu       $t9, $zero, 0x204
    ctx->r25 = ADD32(0, 0X204);
    // 0x801AF320: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF324: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF328: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF32C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF330: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF334: lui         $t8, 0x6
    ctx->r24 = S32(0X6 << 16);
    // 0x801AF338: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x801AF33C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF340: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF344: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF348: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF34C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF350: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x801AF354: ori         $t9, $t9, 0xA00
    ctx->r25 = ctx->r25 | 0XA00;
    // 0x801AF358: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF35C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF360: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF364: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF368: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF36C: addiu       $t8, $zero, 0xC0E
    ctx->r24 = ADD32(0, 0XC0E);
    // 0x801AF370: addiu       $ra, $zero, 0x1C0
    ctx->r31 = ADD32(0, 0X1C0);
    // 0x801AF374: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF378: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF37C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF380: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF384: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF388: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x801AF38C: ori         $t7, $t7, 0xC00
    ctx->r15 = ctx->r15 | 0XC00;
    // 0x801AF390: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF394: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF398: sw          $v0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r2;
    // 0x801AF39C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF3A0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF3A4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF3A8: addiu       $t6, $zero, 0xA06
    ctx->r14 = ADD32(0, 0XA06);
    // 0x801AF3AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF3B0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF3B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF3B8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF3BC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF3C0: addiu       $t9, $zero, 0x1008
    ctx->r25 = ADD32(0, 0X1008);
    // 0x801AF3C4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF3C8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF3CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF3D0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF3D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF3D8: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x801AF3DC: ori         $t6, $t6, 0x1000
    ctx->r14 = ctx->r14 | 0X1000;
    // 0x801AF3E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF3E4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF3E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF3EC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF3F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF3F4: lui         $t9, 0x12
    ctx->r25 = S32(0X12 << 16);
    // 0x801AF3F8: ori         $t9, $t9, 0x810
    ctx->r25 = ctx->r25 | 0X810;
    // 0x801AF3FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF400: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF404: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF408: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF40C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF410: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x801AF414: ori         $t6, $t6, 0xE14
    ctx->r14 = ctx->r14 | 0XE14;
    // 0x801AF418: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF41C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF420: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF424: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF428: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF42C: lui         $t9, 0x10
    ctx->r25 = S32(0X10 << 16);
    // 0x801AF430: ori         $t9, $t9, 0x1612
    ctx->r25 = ctx->r25 | 0X1612;
    // 0x801AF434: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF438: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF43C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF440: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF444: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF448: lui         $t6, 0x14
    ctx->r14 = S32(0X14 << 16);
    // 0x801AF44C: ori         $t6, $t6, 0x1610
    ctx->r14 = ctx->r14 | 0X1610;
    // 0x801AF450: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF454: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF458: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF45C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF460: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF464: lui         $t9, 0x18
    ctx->r25 = S32(0X18 << 16);
    // 0x801AF468: ori         $t9, $t9, 0x812
    ctx->r25 = ctx->r25 | 0X812;
    // 0x801AF46C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF470: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF474: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF478: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF47C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF480: lui         $t6, 0x1A
    ctx->r14 = S32(0X1A << 16);
    // 0x801AF484: ori         $t6, $t6, 0xA08
    ctx->r14 = ctx->r14 | 0XA08;
    // 0x801AF488: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF48C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF490: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF494: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF498: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF49C: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x801AF4A0: ori         $t8, $t8, 0x181A
    ctx->r24 = ctx->r24 | 0X181A;
    // 0x801AF4A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF4A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF4AC: sw          $v0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r2;
    // 0x801AF4B0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF4B4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF4B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF4BC: lui         $t7, 0x6
    ctx->r15 = S32(0X6 << 16);
    // 0x801AF4C0: ori         $t7, $t7, 0xA1A
    ctx->r15 = ctx->r15 | 0XA1A;
    // 0x801AF4C4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF4C8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF4CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF4D0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF4D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF4D8: lui         $t9, 0x1A
    ctx->r25 = S32(0X1A << 16);
    // 0x801AF4DC: ori         $t9, $t9, 0xC04
    ctx->r25 = ctx->r25 | 0XC04;
    // 0x801AF4E0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF4E4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF4E8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF4EC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF4F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF4F4: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x801AF4F8: ori         $t7, $t7, 0xC1A
    ctx->r15 = ctx->r15 | 0XC1A;
    // 0x801AF4FC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF500: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF504: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF508: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF50C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF510: lui         $t9, 0x1A
    ctx->r25 = S32(0X1A << 16);
    // 0x801AF514: ori         $t9, $t9, 0x180E
    ctx->r25 = ctx->r25 | 0X180E;
    // 0x801AF518: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF51C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF520: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF524: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF528: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF52C: lui         $t7, 0x14
    ctx->r15 = S32(0X14 << 16);
    // 0x801AF530: ori         $t7, $t7, 0xE18
    ctx->r15 = ctx->r15 | 0XE18;
    // 0x801AF534: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF538: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF53C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF540: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF544: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF548: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801AF54C: ori         $t9, $t9, 0xC2F
    ctx->r25 = ctx->r25 | 0XC2F;
    // 0x801AF550: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF554: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF558: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF55C: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x801AF560: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801AF564: lw          $t9, 0x7E7C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7E7C);
    // 0x801AF568: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x801AF56C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AF570: andi        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 & 0X1;
    // 0x801AF574: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AF578: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x801AF57C: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801AF580: mflo        $t7
    ctx->r15 = lo;
    // 0x801AF584: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x801AF588: addiu       $t6, $t9, 0x10
    ctx->r14 = ADD32(ctx->r25, 0X10);
    // 0x801AF58C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF590: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF594: lui         $t7, 0x406
    ctx->r15 = S32(0X406 << 16);
    // 0x801AF598: ori         $t7, $t7, 0x81F
    ctx->r15 = ctx->r15 | 0X81F;
    // 0x801AF59C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF5A0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF5A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AF5A8: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x801AF5AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801AF5B0: lw          $t7, 0x7E7C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7E7C);
    // 0x801AF5B4: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x801AF5B8: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x801AF5BC: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x801AF5C0: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AF5C4: sll         $t6, $t6, 7
    ctx->r14 = S32(ctx->r14 << 7);
    // 0x801AF5C8: addu        $t8, $t4, $t6
    ctx->r24 = ADD32(ctx->r12, ctx->r14);
    // 0x801AF5CC: mflo        $t6
    ctx->r14 = lo;
    // 0x801AF5D0: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x801AF5D4: addiu       $t9, $t7, 0x90
    ctx->r25 = ADD32(ctx->r15, 0X90);
    // 0x801AF5D8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF5DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF5E0: lui         $t6, 0x40A
    ctx->r14 = S32(0X40A << 16);
    // 0x801AF5E4: ori         $t6, $t6, 0x207F
    ctx->r14 = ctx->r14 | 0X207F;
    // 0x801AF5E8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF5EC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF5F0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF5F4: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x801AF5F8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801AF5FC: lw          $t6, 0x7E7C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E7C);
    // 0x801AF600: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x801AF604: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x801AF608: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801AF60C: multu       $t7, $ra
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801AF610: sll         $t9, $t9, 7
    ctx->r25 = S32(ctx->r25 << 7);
    // 0x801AF614: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x801AF618: mflo        $t9
    ctx->r25 = lo;
    // 0x801AF61C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x801AF620: addiu       $t7, $t6, 0xC0
    ctx->r15 = ADD32(ctx->r14, 0XC0);
    // 0x801AF624: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF628: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF62C: addiu       $t9, $zero, 0x40E
    ctx->r25 = ADD32(0, 0X40E);
    // 0x801AF630: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF634: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF638: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF63C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF640: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF644: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x801AF648: ori         $t7, $t7, 0x410
    ctx->r15 = ctx->r15 | 0X410;
    // 0x801AF64C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF650: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF654: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF658: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF65C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF660: lui         $t9, 0xC
    ctx->r25 = S32(0XC << 16);
    // 0x801AF664: ori         $t9, $t9, 0x1004
    ctx->r25 = ctx->r25 | 0X1004;
    // 0x801AF668: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF66C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF670: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF674: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF678: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF67C: lui         $t7, 0x10
    ctx->r15 = S32(0X10 << 16);
    // 0x801AF680: ori         $t7, $t7, 0x212
    ctx->r15 = ctx->r15 | 0X212;
    // 0x801AF684: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF688: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF68C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF690: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF694: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF698: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x801AF69C: ori         $t9, $t9, 0x100C
    ctx->r25 = ctx->r25 | 0X100C;
    // 0x801AF6A0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF6A4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF6A8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF6AC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF6B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF6B4: lui         $t7, 0xA
    ctx->r15 = S32(0XA << 16);
    // 0x801AF6B8: ori         $t7, $t7, 0x1408
    ctx->r15 = ctx->r15 | 0X1408;
    // 0x801AF6BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF6C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF6C4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF6C8: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF6CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF6D0: lui         $t9, 0x6
    ctx->r25 = S32(0X6 << 16);
    // 0x801AF6D4: ori         $t9, $t9, 0x140A
    ctx->r25 = ctx->r25 | 0X140A;
    // 0x801AF6D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF6DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF6E0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF6E4: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF6E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF6EC: lui         $t7, 0x10
    ctx->r15 = S32(0X10 << 16);
    // 0x801AF6F0: ori         $t7, $t7, 0x180E
    ctx->r15 = ctx->r15 | 0X180E;
    // 0x801AF6F4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF6F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF6FC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF700: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF704: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF708: lui         $t9, 0xE
    ctx->r25 = S32(0XE << 16);
    // 0x801AF70C: ori         $t9, $t9, 0x1600
    ctx->r25 = ctx->r25 | 0X1600;
    // 0x801AF710: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF714: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF718: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF71C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF720: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF724: addiu       $t8, $zero, 0x1612
    ctx->r24 = ADD32(0, 0X1612);
    // 0x801AF728: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF72C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF730: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    // 0x801AF734: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF738: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF73C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF740: lui         $t6, 0x12
    ctx->r14 = S32(0X12 << 16);
    // 0x801AF744: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x801AF748: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF74C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF750: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF754: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF758: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF75C: lui         $t7, 0x12
    ctx->r15 = S32(0X12 << 16);
    // 0x801AF760: ori         $t7, $t7, 0x1810
    ctx->r15 = ctx->r15 | 0X1810;
    // 0x801AF764: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF768: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF76C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF770: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF774: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF778: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x801AF77C: addiu       $t8, $t8, -0x6CC8
    ctx->r24 = ADD32(ctx->r24, -0X6CC8);
    // 0x801AF780: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF784: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF788: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x801AF78C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF790: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF794: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF798: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x801AF79C: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x801AF7A0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF7A4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF7A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF7AC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF7B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF7B4: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x801AF7B8: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x801AF7BC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF7C0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF7C4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF7C8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AF7CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF7D0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x801AF7D4: lui         $t7, 0xF000
    ctx->r15 = S32(0XF000 << 16);
    // 0x801AF7D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF7DC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF7E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF7E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF7E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF7EC: lui         $t9, 0x73F
    ctx->r25 = S32(0X73F << 16);
    // 0x801AF7F0: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x801AF7F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF7F8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF7FC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF800: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AF804: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF808: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801AF80C: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x801AF810: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF814: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF818: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF81C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AF820: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF824: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x801AF828: addiu       $t6, $t6, -0x6DC8
    ctx->r14 = ADD32(ctx->r14, -0X6DC8);
    // 0x801AF82C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF830: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF834: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF838: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF83C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF840: lui         $t6, 0x701
    ctx->r14 = S32(0X701 << 16);
    // 0x801AF844: ori         $t6, $t6, 0x40
    ctx->r14 = ctx->r14 | 0X40;
    // 0x801AF848: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF84C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF850: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x801AF854: lui         $t7, 0xF550
    ctx->r15 = S32(0XF550 << 16);
    // 0x801AF858: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AF85C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AF860: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF864: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x801AF868: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x801AF86C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF870: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF874: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF878: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AF87C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF880: lui         $t8, 0x707
    ctx->r24 = S32(0X707 << 16);
    // 0x801AF884: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x801AF888: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF88C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF890: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF894: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF898: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF89C: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x801AF8A0: lui         $t8, 0xF548
    ctx->r24 = S32(0XF548 << 16);
    // 0x801AF8A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF8A8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF8AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF8B0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF8B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF8B8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x801AF8BC: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x801AF8C0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AF8C4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801AF8C8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x801AF8CC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AF8D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF8D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF8D8: lui         $t8, 0x3
    ctx->r24 = S32(0X3 << 16);
    // 0x801AF8DC: ori         $t8, $t8, 0xC03C
    ctx->r24 = ctx->r24 | 0XC03C;
    // 0x801AF8E0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF8E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF8E8: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x801AF8EC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF8F0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF8F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF8F8: lui         $t6, 0x400
    ctx->r14 = S32(0X400 << 16);
    // 0x801AF8FC: ori         $t6, $t6, 0x207F
    ctx->r14 = ctx->r14 | 0X207F;
    // 0x801AF900: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF904: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF908: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF90C: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x801AF910: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801AF914: lw          $t6, 0x7E7C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7E7C);
    // 0x801AF918: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x801AF91C: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x801AF920: sll         $t8, $t8, 7
    ctx->r24 = S32(ctx->r24 << 7);
    // 0x801AF924: addu        $t7, $t4, $t8
    ctx->r15 = ADD32(ctx->r12, ctx->r24);
    // 0x801AF928: andi        $t9, $t6, 0x1
    ctx->r25 = ctx->r14 & 0X1;
    // 0x801AF92C: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x801AF930: subu        $t8, $t8, $t9
    ctx->r24 = SUB32(ctx->r24, ctx->r25);
    // 0x801AF934: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x801AF938: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x801AF93C: addiu       $t9, $t6, 0x140
    ctx->r25 = ADD32(ctx->r14, 0X140);
    // 0x801AF940: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF944: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF948: addiu       $t8, $zero, 0x204
    ctx->r24 = ADD32(0, 0X204);
    // 0x801AF94C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF950: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF954: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF958: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF95C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF960: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x801AF964: ori         $t9, $t9, 0x600
    ctx->r25 = ctx->r25 | 0X600;
    // 0x801AF968: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF96C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF970: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801AF974: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF978: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF97C: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x801AF980: ori         $t8, $t8, 0xA0C
    ctx->r24 = ctx->r24 | 0XA0C;
    // 0x801AF984: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF988: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF98C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AF990: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF994: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF998: lui         $t7, 0xC
    ctx->r15 = S32(0XC << 16);
    // 0x801AF99C: ori         $t7, $t7, 0xE08
    ctx->r15 = ctx->r15 | 0XE08;
    // 0x801AF9A0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AF9A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801AF9A8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801AF9AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AF9B0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x801AF9B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF9B8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x801AF9BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AF9C0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801AF9C4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF9C8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801AF9CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801AF9D0: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x801AF9D4: ori         $t9, $t9, 0xE02
    ctx->r25 = ctx->r25 | 0XE02;
    // 0x801AF9D8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AF9DC: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801AF9E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801AF9E4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801AF9E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AF9EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AF9F0: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    // 0x801AF9F4: jr          $ra
    // 0x801AF9F8: nop

    return;
    // 0x801AF9F8: nop

;}
RECOMP_FUNC void Solar_SoFlare_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E920: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019E924: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8019E928: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8019E92C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019E930: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8019E934: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8019E938: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8019E93C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8019E940: jal         0x80061474
    // 0x8019E944: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019E944: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8019E948: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8019E94C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8019E950: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8019E954: addiu       $t7, $zero, 0x188
    ctx->r15 = ADD32(0, 0X188);
    // 0x8019E958: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019E95C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8019E960: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8019E964: bne         $v0, $at, L_8019E97C
    if (ctx->r2 != ctx->r1) {
        // 0x8019E968: sh          $v0, 0x4E($a2)
        MEM_H(0X4E, ctx->r6) = ctx->r2;
            goto L_8019E97C;
    }
    // 0x8019E968: sh          $v0, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r2;
    // 0x8019E96C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8019E970: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8019E974: sh          $t8, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r24;
    // 0x8019E978: sb          $t9, 0x4C($a2)
    MEM_B(0X4C, ctx->r6) = ctx->r25;
L_8019E97C:
    // 0x8019E97C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8019E980: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8019E984: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019E988: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8019E98C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8019E990: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8019E994: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019E998: swc1        $f10, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->f10.u32l;
    // 0x8019E99C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019E9A0: swc1        $f16, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->f16.u32l;
    // 0x8019E9A4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019E9A8: swc1        $f18, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f18.u32l;
    // 0x8019E9AC: jal         0x80004EB0
    // 0x8019E9B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019E9B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x8019E9B4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019E9B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E9BC: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8019E9C0: addiu       $t0, $zero, 0xB0
    ctx->r8 = ADD32(0, 0XB0);
    // 0x8019E9C4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019E9C8: sh          $t0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r8;
    // 0x8019E9CC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8019E9D0: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x8019E9D4: swc1        $f6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f6.u32l;
    // 0x8019E9D8: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019E9DC: jal         0x800612B8
    // 0x8019E9E0: swc1        $f8, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8019E9E0: swc1        $f8, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f8.u32l;
    after_2:
    // 0x8019E9E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019E9E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019E9EC: jr          $ra
    // 0x8019E9F0: nop

    return;
    // 0x8019E9F0: nop

;}
RECOMP_FUNC void Solar_Effect392_SpawnOnSides(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A1EB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A1EB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A1EB8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801A1EBC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801A1EC0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801A1EC4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801A1EC8: jal         0x80004EB0
    // 0x801A1ECC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801A1ECC: nop

    after_0:
    // 0x801A1ED0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801A1ED4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A1ED8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A1EDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A1EE0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A1EE4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A1EE8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801A1EEC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801A1EF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A1EF4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x801A1EF8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801A1EFC: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A1F00: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x801A1F04: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801A1F08: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x801A1F0C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801A1F10: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A1F14: jal         0x8019E9F4
    // 0x801A1F18: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Solar_SoFlare_Spawn(rdram, ctx);
        goto after_1;
    // 0x801A1F18: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x801A1F1C: jal         0x80004EB0
    // 0x801A1F20: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801A1F20: nop

    after_2:
    // 0x801A1F24: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801A1F28: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A1F2C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A1F30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A1F34: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A1F38: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A1F3C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801A1F40: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801A1F44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A1F48: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801A1F4C: lwc1        $f14, 0x34($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A1F50: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x801A1F54: lui         $a3, 0xC1A0
    ctx->r7 = S32(0XC1A0 << 16);
    // 0x801A1F58: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801A1F5C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x801A1F60: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801A1F64: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A1F68: jal         0x8019E9F4
    // 0x801A1F6C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Solar_SoFlare_Spawn(rdram, ctx);
        goto after_3;
    // 0x801A1F6C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x801A1F70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A1F74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A1F78: jr          $ra
    // 0x801A1F7C: nop

    return;
    // 0x801A1F7C: nop

;}
RECOMP_FUNC void OvlI3_CallFunction(uint8_t* rdram, recomp_context* ctx) {
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
