#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void AudioThread_GetAsyncLoadStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ECAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001ECB0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001ECB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ECB8: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001ECBC: addiu       $a0, $a0, 0x4248
    ctx->r4 = ADD32(ctx->r4, 0X4248);
    // 0x8001ECC0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8001ECC4: jal         0x800205E0
    // 0x8001ECC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001ECC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001ECCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001ECD0: bne         $v0, $at, L_8001ECE4
    if (ctx->r2 != ctx->r1) {
        // 0x8001ECD4: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_8001ECE4;
    }
    // 0x8001ECD4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8001ECD8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8001ECDC: b           L_8001ED04
    // 0x8001ECE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001ED04;
    // 0x8001ECE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ECE4:
    // 0x8001ECE4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ECE8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8001ECEC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8001ECF0: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8001ECF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8001ECF8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8001ECFC: srl         $t8, $v0, 24
    ctx->r24 = S32(U32(ctx->r2) >> 24);
    // 0x8001ED00: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8001ED04:
    // 0x8001ED04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ED08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001ED0C: jr          $ra
    // 0x8001ED10: nop

    return;
    // 0x8001ED10: nop

;}
RECOMP_FUNC void AudioLoad_Stub_10800(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010800: jr          $ra
    // 0x80010804: nop

    return;
    // 0x80010804: nop

;}
RECOMP_FUNC void Matrix_Copy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005680: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005684: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80005688: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8000568C: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80005690: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005694: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x80005698: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8000569C: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x800056A0: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800056A4: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x800056A8: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800056AC: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800056B0: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800056B4: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x800056B8: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800056BC: swc1        $f6, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f6.u32l;
    // 0x800056C0: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800056C4: swc1        $f8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f8.u32l;
    // 0x800056C8: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800056CC: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    // 0x800056D0: lwc1        $f16, 0x28($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800056D4: swc1        $f16, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f16.u32l;
    // 0x800056D8: lwc1        $f18, 0x2C($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800056DC: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x800056E0: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800056E4: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x800056E8: lwc1        $f6, 0x34($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800056EC: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x800056F0: lwc1        $f8, 0x38($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800056F4: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x800056F8: lwc1        $f10, 0x3C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x800056FC: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x80005700: jr          $ra
    // 0x80005704: nop

    return;
    // 0x80005704: nop

;}
RECOMP_FUNC void Actor_SpawnGreatFoxLaser(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006EFA4: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8006EFA8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8006EFAC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8006EFB0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006EFB4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8006EFB8: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8006EFBC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8006EFC0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006EFC4: addiu       $v0, $v0, 0x44B0
    ctx->r2 = ADD32(ctx->r2, 0X44B0);
    // 0x8006EFC8: addiu       $a1, $a1, 0x4050
    ctx->r5 = ADD32(ctx->r5, 0X4050);
    // 0x8006EFCC: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
L_8006EFD0:
    // 0x8006EFD0: bnel        $t6, $zero, L_8006F02C
    if (ctx->r14 != 0) {
        // 0x8006EFD4: addiu       $a1, $a1, 0x70
        ctx->r5 = ADD32(ctx->r5, 0X70);
            goto L_8006F02C;
    }
    goto skip_0;
    // 0x8006EFD4: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
    skip_0:
    // 0x8006EFD8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006EFDC: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8006EFE0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8006EFE4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8006EFE8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8006EFEC: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006EFF0: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8006EFF4: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8006EFF8: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8006EFFC: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8006F000: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8006F004: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8006F008: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8006F00C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8006F010: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8006F014: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8006F018: jal         0x8006ECBC
    // 0x8006F01C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    Actor_SetupPlayerShot(rdram, ctx);
        goto after_0;
    // 0x8006F01C: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8006F020: b           L_8006F038
    // 0x8006F024: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8006F038;
    // 0x8006F024: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006F028: addiu       $a1, $a1, 0x70
    ctx->r5 = ADD32(ctx->r5, 0X70);
L_8006F02C:
    // 0x8006F02C: bnel        $a1, $v0, L_8006EFD0
    if (ctx->r5 != ctx->r2) {
        // 0x8006F030: lbu         $t6, 0x0($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X0);
            goto L_8006EFD0;
    }
    goto skip_1;
    // 0x8006F030: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    skip_1:
    // 0x8006F034: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8006F038:
    // 0x8006F038: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8006F03C: jr          $ra
    // 0x8006F040: nop

    return;
    // 0x8006F040: nop

;}
RECOMP_FUNC void Audio_SetSfxSpeedModulation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CFA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001CFAC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8001CFB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001CFB4: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x8001CFB8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8001CFBC: bc1fl       L_8001CFD0
    if (!c1cs) {
        // 0x8001CFC0: neg.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
            goto L_8001CFD0;
    }
    goto skip_0;
    // 0x8001CFC0: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    skip_0:
    // 0x8001CFC4: b           L_8001CFD0
    // 0x8001CFC8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_8001CFD0;
    // 0x8001CFC8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8001CFCC: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
L_8001CFD0:
    // 0x8001CFD0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001CFD4: nop

    // 0x8001CFD8: bc1fl       L_8001CFEC
    if (!c1cs) {
        // 0x8001CFDC: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_8001CFEC;
    }
    goto skip_1;
    // 0x8001CFDC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x8001CFE0: b           L_8001D004
    // 0x8001CFE4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8001D004;
    // 0x8001CFE4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001CFE8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_8001CFEC:
    // 0x8001CFEC: nop

    // 0x8001CFF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8001CFF4: nop

    // 0x8001CFF8: bc1fl       L_8001D008
    if (!c1cs) {
        // 0x8001CFFC: lui         $at, 0x4190
        ctx->r1 = S32(0X4190 << 16);
            goto L_8001D008;
    }
    goto skip_2;
    // 0x8001CFFC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    skip_2:
    // 0x8001D000: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8001D004:
    // 0x8001D004: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
L_8001D008:
    // 0x8001D008: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001D00C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8001D010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001D014: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001D018: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D01C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D020: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001D024: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001D028: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001D02C: jr          $ra
    // 0x8001D030: swc1        $f4, 0x5E74($at)
    MEM_W(0X5E74, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x8001D030: swc1        $f4, 0x5E74($at)
    MEM_W(0X5E74, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void Audio_SetModulationAndPlaySfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D0B4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D0B8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001D0BC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D0C0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D0C4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001D0C8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001D0CC: addiu       $a3, $a3, 0x5E74
    ctx->r7 = ADD32(ctx->r7, 0X5E74);
    // 0x8001D0D0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001D0D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D0D8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D0DC: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8001D0E0: addiu       $t6, $t6, 0x5D34
    ctx->r14 = ADD32(ctx->r14, 0X5D34);
    // 0x8001D0E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001D0E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001D0EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001D0F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001D0F4: jal         0x80019218
    // 0x8001D0F8: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001D0F8: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
    after_0:
    // 0x8001D0FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D100: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D104: jr          $ra
    // 0x8001D108: nop

    return;
    // 0x8001D108: nop

;}
RECOMP_FUNC void AudioLoad_SyncInitSeqPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F200: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F204: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F208: jal         0x8000F220
    // 0x8000F20C: nop

    AudioLoad_SyncInitSeqPlayerInternal(rdram, ctx);
        goto after_0;
    // 0x8000F20C: nop

    after_0:
    // 0x8000F210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F214: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F218: jr          $ra
    // 0x8000F21C: nop

    return;
    // 0x8000F21C: nop

;}
RECOMP_FUNC void Effect_Effect387_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C8C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007C8C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007C8CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007C8D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007C8D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007C8D8: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8007C8DC: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8007C8E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C8E4: bne         $t6, $at, L_8007C904
    if (ctx->r14 != ctx->r1) {
        // 0x8007C8E8: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_8007C904;
    }
    // 0x8007C8E8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8007C8EC: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8007C8F0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007C8F4: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x8007C8F8: beql        $t8, $at, L_8007C908
    if (ctx->r24 == ctx->r1) {
        // 0x8007C8FC: lhu         $t9, 0x50($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0X50);
            goto L_8007C908;
    }
    goto skip_0;
    // 0x8007C8FC: lhu         $t9, 0x50($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X50);
    skip_0:
    // 0x8007C900: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8007C904:
    // 0x8007C904: lhu         $t9, 0x50($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X50);
L_8007C908:
    // 0x8007C908: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8007C90C: and         $t0, $t9, $v0
    ctx->r8 = ctx->r25 & ctx->r2;
    // 0x8007C910: bnel        $t0, $zero, L_8007C9D0
    if (ctx->r8 != 0) {
        // 0x8007C914: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007C9D0;
    }
    goto skip_1;
    // 0x8007C914: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8007C918: lbu         $t1, 0x7C98($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7C98);
    // 0x8007C91C: bnel        $t1, $zero, L_8007C9D0
    if (ctx->r9 != 0) {
        // 0x8007C920: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007C9D0;
    }
    goto skip_2;
    // 0x8007C920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8007C924: jal         0x80004EB0
    // 0x8007C928: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8007C928: nop

    after_0:
    // 0x8007C92C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C930: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007C934: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007C938: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C93C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8007C940: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007C944: jal         0x80004EB0
    // 0x8007C948: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007C948: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8007C94C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C950: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007C954: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007C958: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007C95C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8007C960: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8007C964: jal         0x80004EB0
    // 0x8007C968: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007C968: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8007C96C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007C970: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007C974: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007C978: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007C97C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007C980: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007C984: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007C988: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007C98C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007C990: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007C994: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8007C998: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007C99C: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007C9A0: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007C9A4: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8007C9A8: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8007C9AC: jal         0x8007C85C
    // 0x8007C9B0: nop

    Effect_Effect343_Spawn(rdram, ctx);
        goto after_3;
    // 0x8007C9B0: nop

    after_3:
    // 0x8007C9B4: lhu         $t2, 0x50($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X50);
    // 0x8007C9B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007C9BC: bnel        $t2, $zero, L_8007C9D0
    if (ctx->r10 != 0) {
        // 0x8007C9C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007C9D0;
    }
    goto skip_3;
    // 0x8007C9C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8007C9C4: jal         0x80060FBC
    // 0x8007C9C8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x8007C9C8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_4:
    // 0x8007C9CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007C9D0:
    // 0x8007C9D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007C9D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007C9D8: jr          $ra
    // 0x8007C9DC: nop

    return;
    // 0x8007C9DC: nop

;}
RECOMP_FUNC void func_effect_80079618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079618: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007961C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80079620: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80079624: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80079628: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007962C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80079630: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80079634: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    // 0x80079638: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007963C:
    // 0x8007963C: bnel        $t6, $zero, L_80079670
    if (ctx->r14 != 0) {
        // 0x80079640: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80079670;
    }
    goto skip_0;
    // 0x80079640: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x80079644: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80079648: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007964C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80079650: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80079654: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80079658: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007965C: jal         0x8007905C
    // 0x80079660: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect357_Setup(rdram, ctx);
        goto after_0;
    // 0x80079660: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80079664: b           L_80079680
    // 0x80079668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80079680;
    // 0x80079668: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007966C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80079670:
    // 0x80079670: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80079674: beql        $at, $zero, L_8007963C
    if (ctx->r1 == 0) {
        // 0x80079678: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007963C;
    }
    goto skip_1;
    // 0x80079678: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007967C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80079680:
    // 0x80079680: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80079684: jr          $ra
    // 0x80079688: nop

    return;
    // 0x80079688: nop

;}
RECOMP_FUNC void Play_CheckSingleHitbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A78C4: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x800A78C8: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x800A78CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800A78D0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A78D4: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A78D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A78DC: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800A78E0: lwc1        $f2, -0x7AC4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7AC4);
    // 0x800A78E4: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800A78E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A78EC: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A78F0: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800A78F4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800A78F8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A78FC: nop

    // 0x800A7900: bc1f        L_800A796C
    if (!c1cs) {
        // 0x800A7904: nop
    
            goto L_800A796C;
    }
    // 0x800A7904: nop

    // 0x800A7908: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800A790C: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800A7910: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800A7914: add.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f14.fl;
    // 0x800A7918: lwc1        $f18, 0x8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800A791C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A7920: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A7924: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800A7928: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800A792C: nop

    // 0x800A7930: bc1f        L_800A796C
    if (!c1cs) {
        // 0x800A7934: nop
    
            goto L_800A796C;
    }
    // 0x800A7934: nop

    // 0x800A7938: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800A793C: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A7940: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800A7944: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A7948: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A794C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A7950: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800A7954: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800A7958: nop

    // 0x800A795C: bc1f        L_800A796C
    if (!c1cs) {
        // 0x800A7960: nop
    
            goto L_800A796C;
    }
    // 0x800A7960: nop

    // 0x800A7964: jr          $ra
    // 0x800A7968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800A7968: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800A796C:
    // 0x800A796C: jr          $ra
    // 0x800A7970: nop

    return;
    // 0x800A7970: nop

;}
RECOMP_FUNC void func_effect_8007F5AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F5AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F5B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F5B4: lbu         $t6, 0x4C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4C);
    // 0x8007F5B8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8007F5BC: bnel        $t6, $zero, L_8007F6A4
    if (ctx->r14 != 0) {
        // 0x8007F5C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007F6A4;
    }
    goto skip_0;
    // 0x8007F5C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8007F5C4: lh          $t7, 0x46($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X46);
    // 0x8007F5C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007F5CC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8007F5D0: sh          $t8, 0x46($a0)
    MEM_H(0X46, ctx->r4) = ctx->r24;
    // 0x8007F5D4: lh          $t9, 0x46($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X46);
    // 0x8007F5D8: andi        $t0, $t9, 0x20
    ctx->r8 = ctx->r25 & 0X20;
    // 0x8007F5DC: bnel        $t0, $zero, L_8007F600
    if (ctx->r8 != 0) {
        // 0x8007F5E0: lwc1        $f10, 0x54($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
            goto L_8007F600;
    }
    goto skip_1;
    // 0x8007F5E0: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
    skip_1:
    // 0x8007F5E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007F5E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007F5EC: lwc1        $f4, 0x54($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8007F5F0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007F5F4: b           L_8007F610
    // 0x8007F5F8: swc1        $f8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f8.u32l;
        goto L_8007F610;
    // 0x8007F5F8: swc1        $f8, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f8.u32l;
    // 0x8007F5FC: lwc1        $f10, 0x54($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X54);
L_8007F600:
    // 0x8007F600: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007F604: nop

    // 0x8007F608: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8007F60C: swc1        $f18, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f18.u32l;
L_8007F610:
    // 0x8007F610: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x8007F614: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8007F618: bne         $t2, $zero, L_8007F64C
    if (ctx->r10 != 0) {
        // 0x8007F61C: nop
    
            goto L_8007F64C;
    }
    // 0x8007F61C: nop

    // 0x8007F620: lh          $t3, 0x44($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X44);
    // 0x8007F624: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007F628: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8007F62C: sh          $t4, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r12;
    // 0x8007F630: lh          $t5, 0x44($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X44);
    // 0x8007F634: slti        $at, $t5, 0x14
    ctx->r1 = SIGNED(ctx->r13) < 0X14 ? 1 : 0;
    // 0x8007F638: beq         $at, $zero, L_8007F64C
    if (ctx->r1 == 0) {
        // 0x8007F63C: nop
    
            goto L_8007F64C;
    }
    // 0x8007F63C: nop

    // 0x8007F640: jal         0x80060FBC
    // 0x8007F644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007F644: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007F648: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007F64C:
    // 0x8007F64C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F650: lwc1        $f6, 0x74A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X74A0);
    // 0x8007F654: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007F658: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007F65C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F660: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007F664: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
    // 0x8007F668: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8007F66C: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x8007F670: bnel        $t7, $zero, L_8007F694
    if (ctx->r15 != 0) {
        // 0x8007F674: lwc1        $f4, 0x70($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
            goto L_8007F694;
    }
    goto skip_2;
    // 0x8007F674: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
    skip_2:
    // 0x8007F678: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F67C: lwc1        $f16, 0x74A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74A4);
    // 0x8007F680: lwc1        $f10, 0x70($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8007F684: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8007F688: b           L_8007F6A0
    // 0x8007F68C: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
        goto L_8007F6A0;
    // 0x8007F68C: swc1        $f18, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f18.u32l;
    // 0x8007F690: lwc1        $f4, 0x70($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X70);
L_8007F694:
    // 0x8007F694: lwc1        $f6, 0x74A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X74A8);
    // 0x8007F698: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007F69C: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
L_8007F6A0:
    // 0x8007F6A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007F6A4:
    // 0x8007F6A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007F6A8: jr          $ra
    // 0x8007F6AC: nop

    return;
    // 0x8007F6AC: nop

;}
RECOMP_FUNC void Audio_PlayBombFlightSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CCDC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001CCE0: andi        $a2, $a0, 0xFF
    ctx->r6 = ctx->r4 & 0XFF;
    // 0x8001CCE4: addiu       $t6, $t6, -0x45DC
    ctx->r14 = ADD32(ctx->r14, -0X45DC);
    // 0x8001CCE8: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x8001CCEC: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8001CCF0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001CCF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CCF8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8001CCFC: beq         $t7, $zero, L_8001CE18
    if (ctx->r15 == 0) {
        // 0x8001CD00: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_8001CE18;
    }
    // 0x8001CD00: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8001CD04: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001CD08: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8001CD0C: lbu         $v0, -0x45E0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X45E0);
    // 0x8001CD10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CD14: beql        $v0, $zero, L_8001CD74
    if (ctx->r2 == 0) {
        // 0x8001CD18: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8001CD74;
    }
    goto skip_0;
    // 0x8001CD18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x8001CD1C: beq         $v0, $at, L_8001CD38
    if (ctx->r2 == ctx->r1) {
        // 0x8001CD20: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_8001CD38;
    }
    // 0x8001CD20: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8001CD24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001CD28: beq         $v0, $at, L_8001CD54
    if (ctx->r2 == ctx->r1) {
        // 0x8001CD2C: sll         $t0, $a2, 2
        ctx->r8 = S32(ctx->r6 << 2);
            goto L_8001CD54;
    }
    // 0x8001CD2C: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8001CD30: b           L_8001CD74
    // 0x8001CD34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_8001CD74;
    // 0x8001CD34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8001CD38:
    // 0x8001CD38: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001CD3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001CD40: lwc1        $f4, -0x6F14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6F14);
    // 0x8001CD44: addiu       $t9, $t9, -0x45F0
    ctx->r25 = ADD32(ctx->r25, -0X45F0);
    // 0x8001CD48: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8001CD4C: b           L_8001CD8C
    // 0x8001CD50: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
        goto L_8001CD8C;
    // 0x8001CD50: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_8001CD54:
    // 0x8001CD54: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001CD58: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8001CD5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001CD60: addiu       $t1, $t1, -0x45F0
    ctx->r9 = ADD32(ctx->r9, -0X45F0);
    // 0x8001CD64: addu        $a3, $t0, $t1
    ctx->r7 = ADD32(ctx->r8, ctx->r9);
    // 0x8001CD68: b           L_8001CD8C
    // 0x8001CD6C: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_8001CD8C;
    // 0x8001CD6C: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x8001CD70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8001CD74:
    // 0x8001CD74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001CD78: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8001CD7C: addiu       $t3, $t3, -0x45F0
    ctx->r11 = ADD32(ctx->r11, -0X45F0);
    // 0x8001CD80: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x8001CD84: addu        $a3, $t2, $t3
    ctx->r7 = ADD32(ctx->r10, ctx->r11);
    // 0x8001CD88: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
L_8001CD8C:
    // 0x8001CD8C: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8001CD90: addu        $t5, $t5, $a2
    ctx->r13 = ADD32(ctx->r13, ctx->r6);
    // 0x8001CD94: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8001CD98: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8001CD9C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8001CDA0: subu        $t5, $t5, $a2
    ctx->r13 = SUB32(ctx->r13, ctx->r6);
    // 0x8001CDA4: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8001CDA8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8001CDAC: lw          $a0, 0x47C($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X47C);
    // 0x8001CDB0: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x8001CDB4: ori         $a1, $a1, 0x8008
    ctx->r5 = ctx->r5 | 0X8008;
    // 0x8001CDB8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001CDBC: sb          $a2, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r6;
    // 0x8001CDC0: jal         0x8001A55C
    // 0x8001CDC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_0;
    // 0x8001CDC4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001CDC8: lbu         $a2, 0x33($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X33);
    // 0x8001CDCC: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001CDD0: addiu       $t0, $t0, -0x47B0
    ctx->r8 = ADD32(ctx->r8, -0X47B0);
    // 0x8001CDD4: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x8001CDD8: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x8001CDDC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8001CDE0: addiu       $t9, $t8, 0x6D
    ctx->r25 = ADD32(ctx->r24, 0X6D);
    // 0x8001CDE4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001CDE8: addiu       $t7, $t7, 0x5D34
    ctx->r15 = ADD32(ctx->r15, 0X5D34);
    // 0x8001CDEC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8001CDF0: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8001CDF4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8001CDF8: ori         $a0, $a0, 0x1001
    ctx->r4 = ctx->r4 | 0X1001;
    // 0x8001CDFC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8001CE00: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001CE04: jal         0x80019218
    // 0x8001CE08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8001CE08: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x8001CE0C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8001CE10: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8001CE14: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
L_8001CE18:
    // 0x8001CE18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CE1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8001CE20: jr          $ra
    // 0x8001CE24: nop

    return;
    // 0x8001CE24: nop

;}
RECOMP_FUNC void Effect_Effect365_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E45C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007E460: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007E464: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007E468: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007E46C: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x8007E470: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E474: beql        $v0, $zero, L_8007E490
    if (ctx->r2 == 0) {
        // 0x8007E478: lbu         $t6, 0x4C($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X4C);
            goto L_8007E490;
    }
    goto skip_0;
    // 0x8007E478: lbu         $t6, 0x4C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4C);
    skip_0:
    // 0x8007E47C: beq         $v0, $at, L_8007E560
    if (ctx->r2 == ctx->r1) {
        // 0x8007E480: addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
            goto L_8007E560;
    }
    // 0x8007E480: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007E484: b           L_8007E5BC
    // 0x8007E488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007E5BC;
    // 0x8007E488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007E48C: lbu         $t6, 0x4C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4C);
L_8007E490:
    // 0x8007E490: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007E494: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x8007E498: beq         $t6, $zero, L_8007E4F0
    if (ctx->r14 == 0) {
        // 0x8007E49C: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8007E4F0;
    }
    // 0x8007E49C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E4A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E4A4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8007E4A8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007E4AC: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8007E4B0: jal         0x8009BC2C
    // 0x8007E4B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007E4B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007E4B8: lh          $t7, 0x44($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X44);
    // 0x8007E4BC: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007E4C0: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007E4C4: addiu       $t8, $t7, -0xA
    ctx->r24 = ADD32(ctx->r15, -0XA);
    // 0x8007E4C8: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x8007E4CC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E4D0: lh          $t9, 0x44($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X44);
    // 0x8007E4D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007E4D8: bgez        $t9, L_8007E5B8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007E4DC: swc1        $f10, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
            goto L_8007E5B8;
    }
    // 0x8007E4DC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8007E4E0: jal         0x80060FBC
    // 0x8007E4E4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007E4E4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
    // 0x8007E4E8: b           L_8007E5BC
    // 0x8007E4EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007E5BC;
    // 0x8007E4EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007E4F0:
    // 0x8007E4F0: lh          $t0, 0x44($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X44);
    // 0x8007E4F4: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007E4F8: lwc1        $f18, 0x7478($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7478);
    // 0x8007E4FC: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8007E500: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
    // 0x8007E504: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007E508: lh          $t2, 0x44($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X44);
    // 0x8007E50C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007E510: bgez        $t2, L_8007E520
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8007E514: swc1        $f4, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
            goto L_8007E520;
    }
    // 0x8007E514: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x8007E518: jal         0x80060FBC
    // 0x8007E51C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x8007E51C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_2:
L_8007E520:
    // 0x8007E520: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007E524: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007E528: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E52C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8007E530: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E534: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8007E538: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8007E53C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007E540: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8007E544: lwc1        $f16, 0x747C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X747C);
    // 0x8007E548: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8007E54C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x8007E550: jal         0x8009BC2C
    // 0x8007E554: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8007E554: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8007E558: b           L_8007E5BC
    // 0x8007E55C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007E5BC;
    // 0x8007E55C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007E560:
    // 0x8007E560: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8007E564: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007E568: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007E56C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8007E570: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x8007E574: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8007E578: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x8007E57C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8007E580: jal         0x8009BC2C
    // 0x8007E584: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8007E584: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8007E588: lh          $t3, 0x44($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X44);
    // 0x8007E58C: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007E590: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007E594: addiu       $t4, $t3, -0xA
    ctx->r12 = ADD32(ctx->r11, -0XA);
    // 0x8007E598: sh          $t4, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r12;
    // 0x8007E59C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8007E5A0: lh          $t5, 0x44($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X44);
    // 0x8007E5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007E5A8: bgez        $t5, L_8007E5B8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007E5AC: swc1        $f10, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
            goto L_8007E5B8;
    }
    // 0x8007E5AC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8007E5B0: jal         0x80060FBC
    // 0x8007E5B4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8007E5B4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_5:
L_8007E5B8:
    // 0x8007E5B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007E5BC:
    // 0x8007E5BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007E5C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007E5C4: jr          $ra
    // 0x8007E5C8: nop

    return;
    // 0x8007E5C8: nop

;}
RECOMP_FUNC void Effect_Effect384_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007B2C0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8007B2C4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007B2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B2CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8007B2D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8007B2D4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007B2D8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007B2DC: jal         0x80061474
    // 0x8007B2E0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007B2E0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8007B2E4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8007B2E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B2EC: addiu       $t7, $zero, 0x180
    ctx->r15 = ADD32(0, 0X180);
    // 0x8007B2F0: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8007B2F4: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8007B2F8: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8007B2FC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8007B300: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007B304: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8007B308: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007B30C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8007B310: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8007B314: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007B318: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8007B31C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007B320: sh          $t8, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r24;
    // 0x8007B324: swc1        $f10, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f10.u32l;
    // 0x8007B328: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007B32C: jal         0x800612B8
    // 0x8007B330: sb          $t9, 0x4C($a2)
    MEM_B(0X4C, ctx->r6) = ctx->r25;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007B330: sb          $t9, 0x4C($a2)
    MEM_B(0X4C, ctx->r6) = ctx->r25;
    after_1:
    // 0x8007B334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B338: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007B33C: jr          $ra
    // 0x8007B340: nop

    return;
    // 0x8007B340: nop

;}
RECOMP_FUNC void Effect_Effect391_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800836C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800836C4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800836C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800836CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800836D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800836D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800836D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800836DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800836E0: jal         0x80061474
    // 0x800836E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x800836E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800836E8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800836EC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800836F0: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800836F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800836F8: addiu       $t7, $zero, 0x187
    ctx->r15 = ADD32(0, 0X187);
    // 0x800836FC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80083700: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80083704: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80083708: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008370C: addiu       $t8, $zero, 0xE6
    ctx->r24 = ADD32(0, 0XE6);
    // 0x80083710: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80083714: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80083718: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008371C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80083720: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80083724: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80083728: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x8008372C: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x80083730: lwc1        $f10, 0x7688($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7688);
    // 0x80083734: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083738: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8008373C: swc1        $f16, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f16.u32l;
    // 0x80083740: lwc1        $f18, 0x768C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X768C);
    // 0x80083744: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80083748: bc1t        L_80083754
    if (c1cs) {
        // 0x8008374C: swc1        $f18, 0x64($a2)
        MEM_W(0X64, ctx->r6) = ctx->f18.u32l;
            goto L_80083754;
    }
    // 0x8008374C: swc1        $f18, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f18.u32l;
    // 0x80083750: swc1        $f2, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f2.u32l;
L_80083754:
    // 0x80083754: sh          $t8, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r24;
    // 0x80083758: swc1        $f0, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f0.u32l;
    // 0x8008375C: lwc1        $f6, 0x7690($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7690);
    // 0x80083760: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x80083764: jal         0x800612B8
    // 0x80083768: swc1        $f6, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80083768: swc1        $f6, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f6.u32l;
    after_1:
    // 0x8008376C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80083774: jr          $ra
    // 0x80083778: nop

    return;
    // 0x80083778: nop

;}
RECOMP_FUNC void AudioSynth_ApplyHaasEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B98C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8000B990: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B994: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8000B998: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000B99C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8000B9A0: beq         $t6, $v0, L_8000B9BC
    if (ctx->r14 == ctx->r2) {
        // 0x8000B9A4: sw          $a1, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r5;
            goto L_8000B9BC;
    }
    // 0x8000B9A4: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x8000B9A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B9AC: beq         $t6, $at, L_8000B9D8
    if (ctx->r14 == ctx->r1) {
        // 0x8000B9B0: lw          $t8, 0xC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC);
            goto L_8000B9D8;
    }
    // 0x8000B9B0: lw          $t8, 0xC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC);
    // 0x8000B9B4: b           L_8000BC60
    // 0x8000B9B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8000BC60;
    // 0x8000B9B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000B9BC:
    // 0x8000B9BC: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8000B9C0: lbu         $v1, 0x2($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2);
    // 0x8000B9C4: addiu       $t0, $zero, 0x990
    ctx->r8 = ADD32(0, 0X990);
    // 0x8000B9C8: lbu         $a1, 0x3($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X3);
    // 0x8000B9CC: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8000B9D0: b           L_8000B9F8
    // 0x8000B9D4: sb          $a1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r5;
        goto L_8000B9F8;
    // 0x8000B9D4: sb          $a1, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r5;
L_8000B9D8:
    // 0x8000B9D8: lbu         $a1, 0x4($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X4);
    // 0x8000B9DC: lbu         $v1, 0x3($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X3);
    // 0x8000B9E0: addiu       $t0, $zero, 0xB10
    ctx->r8 = ADD32(0, 0XB10);
    // 0x8000B9E4: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x8000B9E8: b           L_8000B9F8
    // 0x8000B9EC: sb          $a1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r5;
        goto L_8000B9F8;
    // 0x8000B9EC: sb          $a1, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r5;
    // 0x8000B9F0: b           L_8000BC60
    // 0x8000B9F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_8000BC60;
    // 0x8000B9F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000B9F8:
    // 0x8000B9F8: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8000B9FC: lui         $t7, 0xA00
    ctx->r15 = S32(0XA00 << 16);
    // 0x8000BA00: ori         $t7, $t7, 0x650
    ctx->r15 = ctx->r15 | 0X650;
    // 0x8000BA04: beq         $t9, $v0, L_8000BB84
    if (ctx->r25 == ctx->r2) {
        // 0x8000BA08: lui         $at, 0x450
        ctx->r1 = S32(0X450 << 16);
            goto L_8000BB84;
    }
    // 0x8000BA08: lui         $at, 0x450
    ctx->r1 = S32(0X450 << 16);
    // 0x8000BA0C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000BA10: beq         $v1, $a1, L_8000BAC0
    if (ctx->r3 == ctx->r5) {
        // 0x8000BA14: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8000BAC0;
    }
    // 0x8000BA14: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8000BA18: addu        $v1, $a3, $a2
    ctx->r3 = ADD32(ctx->r7, ctx->r6);
    // 0x8000BA1C: subu        $t1, $v1, $v0
    ctx->r9 = SUB32(ctx->r3, ctx->r2);
    // 0x8000BA20: andi        $t5, $t1, 0xFFFF
    ctx->r13 = ctx->r9 & 0XFFFF;
    // 0x8000BA24: lui         $at, 0x450
    ctx->r1 = S32(0X450 << 16);
    // 0x8000BA28: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8000BA2C: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x8000BA30: sll         $t7, $a3, 15
    ctx->r15 = S32(ctx->r7 << 15);
    // 0x8000BA34: ori         $t4, $t4, 0x650
    ctx->r12 = ctx->r12 | 0X650;
    // 0x8000BA38: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8000BA3C: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8000BA40: addiu       $t4, $t1, -0x2
    ctx->r12 = ADD32(ctx->r9, -0X2);
    // 0x8000BA44: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8000BA48: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BA4C: or          $t3, $a0, $zero
    ctx->r11 = ctx->r4 | 0;
    // 0x8000BA50: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8000BA54: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BA58: bgez        $t7, L_8000BA68
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000BA5C: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_8000BA68;
    }
    // 0x8000BA5C: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000BA60: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x8000BA64: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8000BA68:
    // 0x8000BA68: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8000BA6C: bgez        $t4, L_8000BA7C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8000BA70: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_8000BA7C;
    }
    // 0x8000BA70: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8000BA74: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x8000BA78: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_8000BA7C:
    // 0x8000BA7C: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x8000BA80: bne         $t5, $zero, L_8000BA8C
    if (ctx->r13 != 0) {
        // 0x8000BA84: nop
    
            goto L_8000BA8C;
    }
    // 0x8000BA84: nop

    // 0x8000BA88: break       7
    do_break(2147531400);
L_8000BA8C:
    // 0x8000BA8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000BA90: bne         $t5, $at, L_8000BAA4
    if (ctx->r13 != ctx->r1) {
        // 0x8000BA94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8000BAA4;
    }
    // 0x8000BA94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BA98: bne         $t9, $at, L_8000BAA4
    if (ctx->r25 != ctx->r1) {
        // 0x8000BA9C: nop
    
            goto L_8000BAA4;
    }
    // 0x8000BA9C: nop

    // 0x8000BAA0: break       6
    do_break(2147531424);
L_8000BAA4:
    // 0x8000BAA4: mflo        $t6
    ctx->r14 = lo;
    // 0x8000BAA8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8000BAAC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8000BAB0: lui         $at, 0x600
    ctx->r1 = S32(0X600 << 16);
    // 0x8000BAB4: or          $t4, $t8, $at
    ctx->r12 = ctx->r24 | ctx->r1;
    // 0x8000BAB8: b           L_8000BAE8
    // 0x8000BABC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
        goto L_8000BAE8;
    // 0x8000BABC: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
L_8000BAC0:
    // 0x8000BAC0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x8000BAC4: lui         $t9, 0xA00
    ctx->r25 = S32(0XA00 << 16);
    // 0x8000BAC8: andi        $t5, $a3, 0xFFFF
    ctx->r13 = ctx->r7 & 0XFFFF;
    // 0x8000BACC: lui         $at, 0x450
    ctx->r1 = S32(0X450 << 16);
    // 0x8000BAD0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8000BAD4: ori         $t9, $t9, 0x650
    ctx->r25 = ctx->r25 | 0X650;
    // 0x8000BAD8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8000BADC: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8000BAE0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BAE4: addu        $v1, $a3, $a2
    ctx->r3 = ADD32(ctx->r7, ctx->r6);
L_8000BAE8:
    // 0x8000BAE8: beq         $v0, $zero, L_8000BB60
    if (ctx->r2 == 0) {
        // 0x8000BAEC: lui         $t5, 0xA00
        ctx->r13 = S32(0XA00 << 16);
            goto L_8000BB60;
    }
    // 0x8000BAEC: lui         $t5, 0xA00
    ctx->r13 = S32(0XA00 << 16);
    // 0x8000BAF0: addiu       $t7, $v0, 0xF
    ctx->r15 = ADD32(ctx->r2, 0XF);
    // 0x8000BAF4: andi        $t8, $t7, 0xFFF0
    ctx->r24 = ctx->r15 & 0XFFF0;
    // 0x8000BAF8: sra         $t4, $t8, 4
    ctx->r12 = S32(SIGNED(ctx->r24) >> 4);
    // 0x8000BAFC: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x8000BB00: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x8000BB04: lui         $at, 0x1400
    ctx->r1 = S32(0X1400 << 16);
    // 0x8000BB08: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8000BB0C: ori         $t7, $t6, 0x650
    ctx->r15 = ctx->r14 | 0X650;
    // 0x8000BB10: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x8000BB14: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8000BB18: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8000BB1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BB20: ori         $at, $at, 0x80
    ctx->r1 = ctx->r1 | 0X80;
    // 0x8000BB24: addu        $t4, $t8, $at
    ctx->r12 = ADD32(ctx->r24, ctx->r1);
    // 0x8000BB28: sw          $t4, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r12;
    // 0x8000BB2C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BB30: lui         $t9, 0xA00
    ctx->r25 = S32(0XA00 << 16);
    // 0x8000BB34: ori         $t9, $t9, 0x450
    ctx->r25 = ctx->r25 | 0X450;
    // 0x8000BB38: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8000BB3C: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
    // 0x8000BB40: addiu       $t6, $v0, 0x650
    ctx->r14 = ADD32(ctx->r2, 0X650);
    // 0x8000BB44: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8000BB48: andi        $t4, $t8, 0xFFFF
    ctx->r12 = ctx->r24 & 0XFFFF;
    // 0x8000BB4C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8000BB50: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x8000BB54: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8000BB58: b           L_8000BBDC
    // 0x8000BB5C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000BBDC;
    // 0x8000BB5C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000BB60:
    // 0x8000BB60: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000BB64: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x8000BB68: lui         $at, 0x650
    ctx->r1 = S32(0X650 << 16);
    // 0x8000BB6C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8000BB70: ori         $t5, $t5, 0x450
    ctx->r13 = ctx->r13 | 0X450;
    // 0x8000BB74: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000BB78: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000BB7C: b           L_8000BBDC
    // 0x8000BB80: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
        goto L_8000BBDC;
    // 0x8000BB80: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000BB84:
    // 0x8000BB84: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000BB88: andi        $v0, $a3, 0xFFFF
    ctx->r2 = ctx->r7 & 0XFFFF;
    // 0x8000BB8C: or          $t4, $v0, $at
    ctx->r12 = ctx->r2 | ctx->r1;
    // 0x8000BB90: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BB94: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8000BB98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8000BB9C: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x8000BBA0: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BBA4: lui         $t9, 0x200
    ctx->r25 = S32(0X200 << 16);
    // 0x8000BBA8: ori         $t9, $t9, 0x650
    ctx->r25 = ctx->r25 | 0X650;
    // 0x8000BBAC: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8000BBB0: addiu       $t8, $a1, 0x650
    ctx->r24 = ADD32(ctx->r5, 0X650);
    // 0x8000BBB4: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8000BBB8: sw          $a1, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r5;
    // 0x8000BBBC: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8000BBC0: lui         $t5, 0xA00
    ctx->r13 = S32(0XA00 << 16);
    // 0x8000BBC4: ori         $t5, $t5, 0x450
    ctx->r13 = ctx->r13 | 0X450;
    // 0x8000BBC8: or          $t4, $t7, $v0
    ctx->r12 = ctx->r15 | ctx->r2;
    // 0x8000BBCC: sw          $t4, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r12;
    // 0x8000BBD0: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
    // 0x8000BBD4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000BBD8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8000BBDC:
    // 0x8000BBDC: beq         $a1, $zero, L_8000BC28
    if (ctx->r5 == 0) {
        // 0x8000BBE0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8000BC28;
    }
    // 0x8000BBE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000BBE4: addiu       $t9, $a2, 0xF
    ctx->r25 = ADD32(ctx->r6, 0XF);
    // 0x8000BBE8: andi        $t5, $t9, 0xFFF0
    ctx->r13 = ctx->r25 & 0XFFF0;
    // 0x8000BBEC: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8000BBF0: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8000BBF4: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8000BBF8: addiu       $t9, $a3, 0x650
    ctx->r25 = ADD32(ctx->r7, 0X650);
    // 0x8000BBFC: lui         $at, 0x1500
    ctx->r1 = S32(0X1500 << 16);
    // 0x8000BC00: or          $t4, $t7, $at
    ctx->r12 = ctx->r15 | ctx->r1;
    // 0x8000BC04: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8000BC08: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x8000BC0C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000BC10: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8000BC14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000BC18: ori         $at, $at, 0x80
    ctx->r1 = ctx->r1 | 0X80;
    // 0x8000BC1C: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x8000BC20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8000BC24: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_8000BC28:
    // 0x8000BC28: addiu       $t9, $a3, 0x3F
    ctx->r25 = ADD32(ctx->r7, 0X3F);
    // 0x8000BC2C: andi        $t4, $t9, 0xFFC0
    ctx->r12 = ctx->r25 & 0XFFC0;
    // 0x8000BC30: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x8000BC34: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8000BC38: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8000BC3C: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8000BC40: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8000BC44: lui         $at, 0x650
    ctx->r1 = S32(0X650 << 16);
    // 0x8000BC48: andi        $t4, $t0, 0xFFFF
    ctx->r12 = ctx->r8 & 0XFFFF;
    // 0x8000BC4C: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8000BC50: ori         $t9, $t7, 0x7FFF
    ctx->r25 = ctx->r15 | 0X7FFF;
    // 0x8000BC54: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8000BC58: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x8000BC5C: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
L_8000BC60:
    // 0x8000BC60: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8000BC64: jr          $ra
    // 0x8000BC68: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8000BC68: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void PlayerShot_UpdateBeam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B55C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003B560: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003B564: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B568: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B56C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8003B570: lw          $t6, 0x1A88($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A88);
    // 0x8003B574: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003B578: bne         $t6, $at, L_8003B618
    if (ctx->r14 != ctx->r1) {
        // 0x8003B57C: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8003B618;
    }
    // 0x8003B57C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B580: lwc1        $f14, 0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B584: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003B588: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B58C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B590: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x8003B594: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8003B598: nop

    // 0x8003B59C: bc1f        L_8003B618
    if (!c1cs) {
        // 0x8003B5A0: nop
    
            goto L_8003B618;
    }
    // 0x8003B5A0: nop

    // 0x8003B5A4: bne         $a1, $zero, L_8003B618
    if (ctx->r5 != 0) {
        // 0x8003B5A8: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8003B618;
    }
    // 0x8003B5A8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003B5AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003B5B0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B5B4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B5B8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003B5BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8003B5C0: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B5C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B5C8: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8003B5CC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8003B5D0: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003B5D4: jal         0x8007ACE0
    // 0x8003B5D8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Effect_WaterSpray_Spawn(rdram, ctx);
        goto after_0;
    // 0x8003B5D8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8003B5DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B5E0: lwc1        $f14, 0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B5E4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003B5E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B5EC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B5F0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B5F4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003B5F8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8003B5FC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B600: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003B604: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8003B608: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8003B60C: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003B610: jal         0x8007ACE0
    // 0x8003B614: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Effect_WaterSpray_Spawn(rdram, ctx);
        goto after_1;
    // 0x8003B614: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
L_8003B618:
    // 0x8003B618: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B61C: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B620: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B624: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8003B628: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8003B62C: nop

    // 0x8003B630: bc1fl       L_8003BA2C
    if (!c1cs) {
        // 0x8003B634: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_8003BA2C;
    }
    goto skip_0;
    // 0x8003B634: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_0:
    // 0x8003B638: lw          $t7, -0x7B54($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7B54);
    // 0x8003B63C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003B640: beql        $t7, $at, L_8003BA2C
    if (ctx->r15 == ctx->r1) {
        // 0x8003B644: lw          $v0, 0x64($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X64);
            goto L_8003BA2C;
    }
    goto skip_1;
    // 0x8003B644: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    skip_1:
    // 0x8003B648: jal         0x80036318
    // 0x8003B64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_2;
    // 0x8003B64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003B650: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B654: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B658: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003B65C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003B660: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003B664: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8003B668: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003B66C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8003B670: lui         $a1, 0x2912
    ctx->r5 = S32(0X2912 << 16);
    // 0x8003B674: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8003B678: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x8003B67C: bne         $t8, $at, L_8003B68C
    if (ctx->r24 != ctx->r1) {
        // 0x8003B680: nop
    
            goto L_8003B68C;
    }
    // 0x8003B680: nop

    // 0x8003B684: jal         0x8007A6F0
    // 0x8003B688: ori         $a1, $a1, 0x1007
    ctx->r5 = ctx->r5 | 0X1007;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_3;
    // 0x8003B688: ori         $a1, $a1, 0x1007
    ctx->r5 = ctx->r5 | 0X1007;
    after_3:
L_8003B68C:
    // 0x8003B68C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8003B690: lw          $t9, 0x78A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A8);
    // 0x8003B694: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003B698: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8003B69C: beq         $t9, $at, L_8003B850
    if (ctx->r25 == ctx->r1) {
        // 0x8003B6A0: nop
    
            goto L_8003B850;
    }
    // 0x8003B6A0: nop

    // 0x8003B6A4: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8003B6A8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8003B6AC: beq         $t0, $at, L_8003B850
    if (ctx->r8 == ctx->r1) {
        // 0x8003B6B0: nop
    
            goto L_8003B850;
    }
    // 0x8003B6B0: nop

    // 0x8003B6B4: lw          $t1, 0x68($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X68);
    // 0x8003B6B8: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8003B6BC: bnel        $t1, $zero, L_8003B82C
    if (ctx->r9 != 0) {
        // 0x8003B6C0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8003B82C;
    }
    goto skip_2;
    // 0x8003B6C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_2:
    // 0x8003B6C4: lw          $t2, 0x1AA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1AA8);
    // 0x8003B6C8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8003B6CC: beql        $t2, $zero, L_8003B82C
    if (ctx->r10 == 0) {
        // 0x8003B6D0: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8003B82C;
    }
    goto skip_3;
    // 0x8003B6D0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_3:
    // 0x8003B6D4: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8003B6D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003B6DC: lw          $t4, 0x1CC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X1CC);
    // 0x8003B6E0: beq         $t4, $at, L_8003B828
    if (ctx->r12 == ctx->r1) {
        // 0x8003B6E4: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8003B828;
    }
    // 0x8003B6E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003B6E8: lwc1        $f8, 0x531C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X531C);
    // 0x8003B6EC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B6F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003B6F4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003B6F8: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8003B6FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003B700: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003B704: jal         0x80005E90
    // 0x8003B708: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8003B708: nop

    after_4:
    // 0x8003B70C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003B710: lwc1        $f6, 0x5320($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5320);
    // 0x8003B714: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B718: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003B71C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003B720: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8003B724: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B728: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003B72C: jal         0x80005D44
    // 0x8003B730: nop

    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8003B730: nop

    after_5:
    // 0x8003B734: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003B738: lwc1        $f10, 0x5324($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5324);
    // 0x8003B73C: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8003B740: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003B744: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003B748: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003B74C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B750: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8003B754: jal         0x80005FE0
    // 0x8003B758: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8003B758: nop

    after_6:
    // 0x8003B75C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003B760: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8003B764: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B768: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003B76C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003B770: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003B774: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8003B778: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8003B77C: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8003B780: jal         0x80006A20
    // 0x8003B784: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_7;
    // 0x8003B784: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8003B788: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B78C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003B790: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B794: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8003B798: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003B79C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003B7A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003B7A4: add.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003B7A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B7AC: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B7B0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B7B4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003B7B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8003B7BC: jal         0x80036770
    // 0x8003B7C0: add.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f0.fl;
    PlayerShot_HitGround(rdram, ctx);
        goto after_8;
    // 0x8003B7C0: add.s       $f14, $f10, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f0.fl;
    after_8:
    // 0x8003B7C4: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8003B7C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B7CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003B7D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003B7D4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003B7D8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8003B7DC: jal         0x80006A20
    // 0x8003B7E0: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_9;
    // 0x8003B7E0: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8003B7E4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B7E8: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003B7EC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B7F0: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8003B7F4: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003B7F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003B7FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003B800: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8003B804: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B808: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B80C: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B810: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8003B814: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8003B818: jal         0x80036770
    // 0x8003B81C: add.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f0.fl;
    PlayerShot_HitGround(rdram, ctx);
        goto after_10;
    // 0x8003B81C: add.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f0.fl;
    after_10:
    // 0x8003B820: b           L_8003B850
    // 0x8003B824: nop

        goto L_8003B850;
    // 0x8003B824: nop

L_8003B828:
    // 0x8003B828: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8003B82C:
    // 0x8003B82C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003B830: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003B834: lwc1        $f18, 0x7940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003B838: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B83C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B840: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B844: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8003B848: jal         0x80036770
    // 0x8003B84C: add.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f0.fl;
    PlayerShot_HitGround(rdram, ctx);
        goto after_11;
    // 0x8003B84C: add.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f0.fl;
    after_11:
L_8003B850:
    // 0x8003B850: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8003B854: lw          $t5, 0x1A88($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1A88);
    // 0x8003B858: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003B85C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B860: bne         $t5, $at, L_8003B878
    if (ctx->r13 != ctx->r1) {
        // 0x8003B864: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8003B878;
    }
    // 0x8003B864: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003B868: jal         0x80060FBC
    // 0x8003B86C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x8003B86C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_12:
    // 0x8003B870: b           L_8003BA70
    // 0x8003B874: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003BA70;
    // 0x8003B874: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003B878:
    // 0x8003B878: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8003B87C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8003B880: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8003B884: bnel        $v0, $at, L_8003B8D0
    if (ctx->r2 != ctx->r1) {
        // 0x8003B888: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_8003B8D0;
    }
    goto skip_4;
    // 0x8003B888: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_4:
    // 0x8003B88C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B890: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B894: jal         0x8007BC7C
    // 0x8003B898: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_13;
    // 0x8003B898: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_13:
    // 0x8003B89C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B8A0: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B8A4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B8A8: jal         0x8007BC7C
    // 0x8003B8AC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_14;
    // 0x8003B8AC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_14:
    // 0x8003B8B0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B8B4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B8B8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B8BC: jal         0x8007BC7C
    // 0x8003B8C0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_15;
    // 0x8003B8C0: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_15:
    // 0x8003B8C4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003B8C8: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8003B8CC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
L_8003B8D0:
    // 0x8003B8D0: bne         $v0, $at, L_8003BA28
    if (ctx->r2 != ctx->r1) {
        // 0x8003B8D4: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_8003BA28;
    }
    // 0x8003B8D4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8003B8D8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B8DC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B8E0: jal         0x8007B8F8
    // 0x8003B8E4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_Effect364_Spawn(rdram, ctx);
        goto after_16;
    // 0x8003B8E4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_16:
    // 0x8003B8E8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B8EC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B8F0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B8F4: jal         0x8007B8F8
    // 0x8003B8F8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect364_Spawn(rdram, ctx);
        goto after_17;
    // 0x8003B8F8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_17:
    // 0x8003B8FC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B900: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B904: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B908: jal         0x8007B8F8
    // 0x8003B90C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect364_Spawn(rdram, ctx);
        goto after_18;
    // 0x8003B90C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_18:
    // 0x8003B910: jal         0x80004EB0
    // 0x8003B914: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x8003B914: nop

    after_19:
    // 0x8003B918: jal         0x80004EB0
    // 0x8003B91C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x8003B91C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x8003B920: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003B924: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B928: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003B92C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B930: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003B934: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8003B938: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B93C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B940: sub.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8003B944: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8003B948: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B94C: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x8003B950: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8003B954: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8003B958: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003B95C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003B960: jal         0x801AC8A8
    // 0x8003B964: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_21;
    // 0x8003B964: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    after_21:
    // 0x8003B968: jal         0x80004EB0
    // 0x8003B96C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x8003B96C: nop

    after_22:
    // 0x8003B970: jal         0x80004EB0
    // 0x8003B974: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x8003B974: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x8003B978: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003B97C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B980: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003B984: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B988: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003B98C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8003B990: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B994: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003B998: sub.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8003B99C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003B9A0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003B9A4: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x8003B9A8: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8003B9AC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8003B9B0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003B9B4: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003B9B8: jal         0x801AC8A8
    // 0x8003B9BC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_24;
    // 0x8003B9BC: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    after_24:
    // 0x8003B9C0: jal         0x80004EB0
    // 0x8003B9C4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_25;
    // 0x8003B9C4: nop

    after_25:
    // 0x8003B9C8: jal         0x80004EB0
    // 0x8003B9CC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_26;
    // 0x8003B9CC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_26:
    // 0x8003B9D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003B9D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B9D8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8003B9DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B9E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B9E4: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003B9E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003B9EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B9F0: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003B9F4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8003B9F8: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8003B9FC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003BA00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003BA04: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003BA08: lui         $a3, 0x3F4C
    ctx->r7 = S32(0X3F4C << 16);
    // 0x8003BA0C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8003BA10: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003BA14: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8003BA18: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003BA1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003BA20: jal         0x801AC8A8
    // 0x8003BA24: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_27;
    // 0x8003BA24: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    after_27:
L_8003BA28:
    // 0x8003BA28: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
L_8003BA2C:
    // 0x8003BA2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003BA30: bnel        $v0, $zero, L_8003BA4C
    if (ctx->r2 != 0) {
        // 0x8003BA34: lw          $t6, 0x68($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X68);
            goto L_8003BA4C;
    }
    goto skip_5;
    // 0x8003BA34: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
    skip_5:
    // 0x8003BA38: jal         0x80060FBC
    // 0x8003BA3C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_28;
    // 0x8003BA3C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_28:
    // 0x8003BA40: b           L_8003BA70
    // 0x8003BA44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003BA70;
    // 0x8003BA44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003BA48: lw          $t6, 0x68($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X68);
L_8003BA4C:
    // 0x8003BA4C: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8003BA50: slti        $at, $t6, 0x6E
    ctx->r1 = SIGNED(ctx->r14) < 0X6E ? 1 : 0;
    // 0x8003BA54: bne         $at, $zero, L_8003BA64
    if (ctx->r1 != 0) {
        // 0x8003BA58: nop
    
            goto L_8003BA64;
    }
    // 0x8003BA58: nop

    // 0x8003BA5C: beql        $t7, $zero, L_8003BA70
    if (ctx->r15 == 0) {
        // 0x8003BA60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8003BA70;
    }
    goto skip_6;
    // 0x8003BA60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
L_8003BA64:
    // 0x8003BA64: jal         0x80038140
    // 0x8003BA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_CollisionCheck(rdram, ctx);
        goto after_29;
    // 0x8003BA68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8003BA6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003BA70:
    // 0x8003BA70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003BA74: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8003BA78: jr          $ra
    // 0x8003BA7C: nop

    return;
    // 0x8003BA7C: nop

;}
RECOMP_FUNC void HUD_EdgeArrows_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CA44: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8008CA48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008CA4C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008CA50: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008CA54: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008CA58: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008CA5C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008CA60: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8008CA64: addiu       $t7, $t7, 0x2048
    ctx->r15 = ADD32(ctx->r15, 0X2048);
    // 0x8008CA68: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x8008CA6C: addiu       $t6, $sp, 0x48
    ctx->r14 = ADD32(ctx->r29, 0X48);
L_8008CA70:
    // 0x8008CA70: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8008CA74: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8008CA78: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8008CA7C: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x8008CA80: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8008CA84: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x8008CA88: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8008CA8C: bne         $t7, $t0, L_8008CA70
    if (ctx->r15 != ctx->r8) {
        // 0x8008CA90: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_8008CA70;
    }
    // 0x8008CA90: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8008CA94: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8008CA98: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x8008CA9C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8008CAA0: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8008CAA4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8008CAA8: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8008CAAC: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8008CAB0: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8008CAB4: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8008CAB8: addu        $v0, $t1, $t3
    ctx->r2 = ADD32(ctx->r9, ctx->r11);
    // 0x8008CABC: lw          $v1, 0x228($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X228);
    // 0x8008CAC0: beql        $v1, $zero, L_8008CB70
    if (ctx->r3 == 0) {
        // 0x8008CAC4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8008CB70;
    }
    goto skip_0;
    // 0x8008CAC4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8008CAC8: lw          $t4, 0x210($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X210);
    // 0x8008CACC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8008CAD0: bnel        $t4, $zero, L_8008CB70
    if (ctx->r12 != 0) {
        // 0x8008CAD4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8008CB70;
    }
    goto skip_1;
    // 0x8008CAD4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x8008CAD8: lw          $t5, 0x7854($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7854);
    // 0x8008CADC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8008CAE0: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8008CAE4: beq         $t5, $at, L_8008CB6C
    if (ctx->r13 == ctx->r1) {
        // 0x8008CAE8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008CB6C;
    }
    // 0x8008CAE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008CAEC: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x8008CAF0: addiu       $s4, $s4, 0x7DB0
    ctx->r20 = ADD32(ctx->r20, 0X7DB0);
    // 0x8008CAF4: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x8008CAF8: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
L_8008CAFC:
    // 0x8008CAFC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8008CB00: and         $t9, $s1, $v0
    ctx->r25 = ctx->r17 & ctx->r2;
    // 0x8008CB04: bnel        $t9, $v0, L_8008CB4C
    if (ctx->r25 != ctx->r2) {
        // 0x8008CB08: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8008CB4C;
    }
    goto skip_2;
    // 0x8008CB08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8008CB0C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8008CB10: xori        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 ^ 0XFF;
    // 0x8008CB14: and         $s1, $t8, $s1
    ctx->r17 = ctx->r24 & ctx->r17;
    // 0x8008CB18: andi        $t0, $v1, 0x4
    ctx->r8 = ctx->r3 & 0X4;
    // 0x8008CB1C: beq         $t0, $zero, L_8008CB30
    if (ctx->r8 == 0) {
        // 0x8008CB20: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008CB30;
    }
    // 0x8008CB20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008CB24: jal         0x8008C6F4
    // 0x8008CB28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    HUD_EdgeArrows_Draw(rdram, ctx);
        goto after_0;
    // 0x8008CB28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8008CB2C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
L_8008CB30:
    // 0x8008CB30: addiu       $t7, $v1, -0x2
    ctx->r15 = ADD32(ctx->r3, -0X2);
    // 0x8008CB34: andi        $t6, $t7, 0x4
    ctx->r14 = ctx->r15 & 0X4;
    // 0x8008CB38: beq         $t6, $zero, L_8008CB48
    if (ctx->r14 == 0) {
        // 0x8008CB3C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8008CB48;
    }
    // 0x8008CB3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008CB40: jal         0x8008C6F4
    // 0x8008CB44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    HUD_EdgeArrows_Draw(rdram, ctx);
        goto after_1;
    // 0x8008CB44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
L_8008CB48:
    // 0x8008CB48: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8008CB4C:
    // 0x8008CB4C: bne         $s0, $s3, L_8008CAFC
    if (ctx->r16 != ctx->r19) {
        // 0x8008CB50: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8008CAFC;
    }
    // 0x8008CB50: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8008CB54: lui         $a0, 0x102
    ctx->r4 = S32(0X102 << 16);
    // 0x8008CB58: addiu       $a0, $a0, 0x4A58
    ctx->r4 = ADD32(ctx->r4, 0X4A58);
    // 0x8008CB5C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8008CB60: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8008CB64: jal         0x8008BD00
    // 0x8008CB68: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    HUD_Texture_Scroll(rdram, ctx);
        goto after_2;
    // 0x8008CB68: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
L_8008CB6C:
    // 0x8008CB6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8008CB70:
    // 0x8008CB70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008CB74: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008CB78: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008CB7C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008CB80: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008CB84: jr          $ra
    // 0x8008CB88: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8008CB88: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void ActorTeamBoss_SomerSault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800924E0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800924E4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800924E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800924EC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800924F0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800924F4: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800924F8: lw          $t6, 0x6C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X6C);
    // 0x800924FC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80092500: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80092504: bne         $t6, $zero, L_80092520
    if (ctx->r14 != 0) {
        // 0x80092508: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80092520;
    }
    // 0x80092508: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8009250C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80092510: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80092514: sw          $v0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r2;
    // 0x80092518: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x8009251C: swc1        $f4, 0x2E8($s0)
    MEM_W(0X2E8, ctx->r16) = ctx->f4.u32l;
L_80092520:
    // 0x80092520: lwc1        $f6, 0x188($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X188);
    // 0x80092524: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80092528: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x8009252C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80092530: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80092534: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80092538: addiu       $a0, $s0, 0x150
    ctx->r4 = ADD32(ctx->r16, 0X150);
    // 0x8009253C: bc1f        L_80092548
    if (!c1cs) {
        // 0x80092540: lui         $a2, 0x3E99
        ctx->r6 = S32(0X3E99 << 16);
            goto L_80092548;
    }
    // 0x80092540: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80092544: swc1        $f2, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f2.u32l;
L_80092548:
    // 0x80092548: lwc1        $f10, 0x160($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X160);
    // 0x8009254C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80092550: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80092554: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80092558: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8009255C: bc1fl       L_80092570
    if (!c1cs) {
        // 0x80092560: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80092570;
    }
    goto skip_0;
    // 0x80092560: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80092564: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80092568: nop

    // 0x8009256C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80092570:
    // 0x80092570: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80092574: jal         0x8009BC2C
    // 0x80092578: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80092578: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8009257C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80092580: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80092584: addiu       $a0, $s0, 0x17C
    ctx->r4 = ADD32(ctx->r16, 0X17C);
    // 0x80092588: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8009258C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80092590: jal         0x8009BC2C
    // 0x80092594: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80092594: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80092598: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8009259C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800925A0: addiu       $a0, $s0, 0x154
    ctx->r4 = ADD32(ctx->r16, 0X154);
    // 0x800925A4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800925A8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800925AC: jal         0x8009BC2C
    // 0x800925B0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800925B0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x800925B4: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x800925B8: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x800925BC: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // 0x800925C0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800925C4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800925C8: jal         0x8009BC2C
    // 0x800925CC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800925CC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x800925D0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800925D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800925D8: lwc1        $f16, 0x160($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X160);
    // 0x800925DC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800925E0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800925E4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800925E8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800925EC: addiu       $a0, $s0, 0x160
    ctx->r4 = ADD32(ctx->r16, 0X160);
    // 0x800925F0: lui         $a1, 0x43B4
    ctx->r5 = S32(0X43B4 << 16);
    // 0x800925F4: bc1f        L_80092610
    if (!c1cs) {
        // 0x800925F8: nop
    
            goto L_80092610;
    }
    // 0x800925F8: nop

    // 0x800925FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80092600: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80092604: nop

    // 0x80092608: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8009260C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
L_80092610:
    // 0x80092610: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80092614: lwc1        $f10, 0x7FAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7FAC);
    // 0x80092618: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8009261C: jal         0x8009BC2C
    // 0x80092620: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80092620: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80092624: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80092628: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8009262C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80092630: addiu       $a0, $s0, 0x2E8
    ctx->r4 = ADD32(ctx->r16, 0X2E8);
    // 0x80092634: bc1f        L_8009265C
    if (!c1cs) {
        // 0x80092638: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_8009265C;
    }
    // 0x80092638: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8009263C: lwc1        $f16, 0x2E8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x80092640: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80092644: swc1        $f20, 0x2E8($s0)
    MEM_W(0X2E8, ctx->r16) = ctx->f20.u32l;
    // 0x80092648: swc1        $f20, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f20.u32l;
    // 0x8009264C: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x80092650: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x80092654: sw          $zero, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = 0;
    // 0x80092658: swc1        $f18, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f18.u32l;
L_8009265C:
    // 0x8009265C: lw          $t8, 0x6C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X6C);
    // 0x80092660: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80092664: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80092668: beql        $t8, $zero, L_8009278C
    if (ctx->r24 == 0) {
        // 0x8009266C: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_8009278C;
    }
    goto skip_1;
    // 0x8009266C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x80092670: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80092674: jal         0x8009BD38
    // 0x80092678: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x80092678: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x8009267C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80092680: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80092684: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80092688: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8009268C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80092690: jal         0x8009BD38
    // 0x80092694: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x80092694: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80092698: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009269C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800926A0: lwc1        $f6, 0x160($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X160);
    // 0x800926A4: lwc1        $f10, 0x2E8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x800926A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800926AC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800926B0: lwc1        $f18, 0xF8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800926B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800926B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800926BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800926C0: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x800926C4: lwc1        $f4, 0x7FB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7FB0);
    // 0x800926C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800926CC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800926D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800926D4: jal         0x80005E90
    // 0x800926D8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x800926D8: nop

    after_7:
    // 0x800926DC: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x800926E0: lwc1        $f10, 0x2E8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x800926E4: lwc1        $f18, 0x160($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X160);
    // 0x800926E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800926EC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800926F0: lwc1        $f6, 0x7FB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7FB4);
    // 0x800926F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800926F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800926FC: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80092700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80092704: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80092708: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8009270C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80092710: jal         0x80005D44
    // 0x80092714: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x80092714: nop

    after_8:
    // 0x80092718: lwc1        $f18, 0x118($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8009271C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80092720: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x80092724: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x80092728: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8009272C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80092730: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80092734: jal         0x80006A20
    // 0x80092738: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_9;
    // 0x80092738: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x8009273C: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80092740: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80092744: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80092748: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x8009274C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80092750: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x80092754: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80092758: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x8009275C: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80092760: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80092764: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80092768: nop

    // 0x8009276C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80092770: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80092774: nop

    // 0x80092778: bc1fl       L_8009278C
    if (!c1cs) {
        // 0x8009277C: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_8009278C;
    }
    goto skip_2;
    // 0x8009277C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_2:
    // 0x80092780: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80092784: swc1        $f20, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f20.u32l;
    // 0x80092788: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8009278C:
    // 0x8009278C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80092790: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80092794: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80092798: jr          $ra
    // 0x8009279C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8009279C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Tank_UpdateOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80047504: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80047508: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004750C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80047510: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80047514: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80047518: sw          $t6, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->r14;
    // 0x8004751C: jal         0x80045130
    // 0x80047520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045130(rdram, ctx);
        goto after_0;
    // 0x80047520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80047524: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047528: sw          $zero, -0x60EC($at)
    MEM_W(-0X60EC, ctx->r1) = 0;
    // 0x8004752C: jal         0x80045678
    // 0x80047530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045678(rdram, ctx);
        goto after_1;
    // 0x80047530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80047534: jal         0x80045348
    // 0x80047538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045348(rdram, ctx);
        goto after_2;
    // 0x80047538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8004753C: lw          $t7, 0x2B4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2B4);
    // 0x80047540: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80047544: bne         $t7, $zero, L_80047620
    if (ctx->r15 != 0) {
        // 0x80047548: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_80047620;
    }
    // 0x80047548: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8004754C: lw          $v0, -0x60EC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X60EC);
    // 0x80047550: beq         $v0, $zero, L_800475D8
    if (ctx->r2 == 0) {
        // 0x80047554: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800475D8;
    }
    // 0x80047554: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80047558: bne         $at, $zero, L_80047578
    if (ctx->r1 != 0) {
        // 0x8004755C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80047578;
    }
    // 0x8004755C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80047560: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80047564: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80047568: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x8004756C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80047570: b           L_8004758C
    // 0x80047574: swc1        $f8, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f8.u32l;
        goto L_8004758C;
    // 0x80047574: swc1        $f8, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f8.u32l;
L_80047578:
    // 0x80047578: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004757C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80047580: lwc1        $f10, 0x2BC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x80047584: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80047588: swc1        $f18, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f18.u32l;
L_8004758C:
    // 0x8004758C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80047590: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80047594: lwc1        $f4, 0x2BC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x80047598: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x8004759C: ori         $a1, $a1, 0x4024
    ctx->r5 = ctx->r5 | 0X4024;
    // 0x800475A0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800475A4: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800475A8: bc1f        L_80047654
    if (!c1cs) {
        // 0x800475AC: nop
    
            goto L_80047654;
    }
    // 0x800475AC: nop

    // 0x800475B0: swc1        $f0, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f0.u32l;
    // 0x800475B4: sw          $t8, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r24;
    // 0x800475B8: jal         0x8001A55C
    // 0x800475BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_3;
    // 0x800475BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_3:
    // 0x800475C0: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x800475C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800475C8: jal         0x8001A55C
    // 0x800475CC: ori         $a1, $a1, 0x8016
    ctx->r5 = ctx->r5 | 0X8016;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_4;
    // 0x800475CC: ori         $a1, $a1, 0x8016
    ctx->r5 = ctx->r5 | 0X8016;
    after_4:
    // 0x800475D0: b           L_80047654
    // 0x800475D4: nop

        goto L_80047654;
    // 0x800475D4: nop

L_800475D8:
    // 0x800475D8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800475DC: lwc1        $f8, 0x2BC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800475E0: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x800475E4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800475E8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x800475EC: ori         $a1, $a1, 0x4024
    ctx->r5 = ctx->r5 | 0X4024;
    // 0x800475F0: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800475F4: bc1f        L_80047654
    if (!c1cs) {
        // 0x800475F8: nop
    
            goto L_80047654;
    }
    // 0x800475F8: nop

    // 0x800475FC: sw          $t9, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r25;
    // 0x80047600: jal         0x8001A55C
    // 0x80047604: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_5;
    // 0x80047604: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_5:
    // 0x80047608: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x8004760C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80047610: jal         0x8001A55C
    // 0x80047614: ori         $a1, $a1, 0x8016
    ctx->r5 = ctx->r5 | 0X8016;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_6;
    // 0x80047614: ori         $a1, $a1, 0x8016
    ctx->r5 = ctx->r5 | 0X8016;
    after_6:
    // 0x80047618: b           L_80047654
    // 0x8004761C: nop

        goto L_80047654;
    // 0x8004761C: nop

L_80047620:
    // 0x80047620: lwc1        $f10, 0x2BC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x80047624: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80047628: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004762C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80047630: swc1        $f18, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f18.u32l;
    // 0x80047634: lwc1        $f6, 0x2BC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x80047638: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8004763C: nop

    // 0x80047640: bc1f        L_80047654
    if (!c1cs) {
        // 0x80047644: nop
    
            goto L_80047654;
    }
    // 0x80047644: nop

    // 0x80047648: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004764C: sw          $zero, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = 0;
    // 0x80047650: swc1        $f8, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f8.u32l;
L_80047654:
    // 0x80047654: jal         0x800B41E0
    // 0x80047658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Play_dummy_800B41E0(rdram, ctx);
        goto after_7;
    // 0x80047658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8004765C: jal         0x80045E7C
    // 0x80047660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80045E7C(rdram, ctx);
        goto after_8;
    // 0x80047660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80047664: jal         0x80044868
    // 0x80047668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80044868(rdram, ctx);
        goto after_9;
    // 0x80047668: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8004766C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80047670: sb          $zero, -0x60FC($at)
    MEM_B(-0X60FC, ctx->r1) = 0;
    // 0x80047674: jal         0x800ADF58
    // 0x80047678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdatePath(rdram, ctx);
        goto after_10;
    // 0x80047678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8004767C: jal         0x800AD7F0
    // 0x80047680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Shoot(rdram, ctx);
        goto after_11;
    // 0x80047680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80047684: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80047688: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8004768C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80047690: beql        $t0, $at, L_800476AC
    if (ctx->r8 == ctx->r1) {
        // 0x80047694: lui         $at, 0xC120
        ctx->r1 = S32(0XC120 << 16);
            goto L_800476AC;
    }
    goto skip_0;
    // 0x80047694: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    skip_0:
    // 0x80047698: jal         0x800A8BA4
    // 0x8004769C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_12;
    // 0x8004769C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800476A0: b           L_800476F4
    // 0x800476A4: nop

        goto L_800476F4;
    // 0x800476A4: nop

    // 0x800476A8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
L_800476AC:
    // 0x800476AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800476B0: lwc1        $f16, 0x138($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800476B4: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800476B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800476BC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800476C0: swc1        $f10, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f10.u32l;
    // 0x800476C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800476C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800476CC: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x800476D0: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800476D4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800476D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800476DC: swc1        $f0, 0x248($s0)
    MEM_W(0X248, ctx->r16) = ctx->f0.u32l;
    // 0x800476E0: swc1        $f0, 0x24C($s0)
    MEM_W(0X24C, ctx->r16) = ctx->f0.u32l;
    // 0x800476E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800476E8: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x800476EC: jal         0x800481F4
    // 0x800476F0: swc1        $f10, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f10.u32l;
    func_tank_800481F4(rdram, ctx);
        goto after_13;
    // 0x800476F0: swc1        $f10, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f10.u32l;
    after_13:
L_800476F4:
    // 0x800476F4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800476F8: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x800476FC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80047700: bne         $t1, $at, L_80047718
    if (ctx->r9 != ctx->r1) {
        // 0x80047704: nop
    
            goto L_80047718;
    }
    // 0x80047704: nop

    // 0x80047708: jal         0x80046358
    // 0x8004770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80046358(rdram, ctx);
        goto after_14;
    // 0x8004770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80047710: jal         0x80046260
    // 0x80047714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_tank_80046260(rdram, ctx);
        goto after_15;
    // 0x80047714: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_80047718:
    // 0x80047718: jal         0x800B415C
    // 0x8004771C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_LowHealthAlarm(rdram, ctx);
        goto after_16;
    // 0x8004771C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80047720: lw          $t2, 0x264($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X264);
    // 0x80047724: bgtzl       $t2, L_80047744
    if (SIGNED(ctx->r10) > 0) {
        // 0x80047728: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80047744;
    }
    goto skip_1;
    // 0x80047728: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8004772C: lw          $t3, 0x220($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X220);
    // 0x80047730: beql        $t3, $zero, L_80047744
    if (ctx->r11 == 0) {
        // 0x80047734: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80047744;
    }
    goto skip_2;
    // 0x80047734: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80047738: jal         0x800B41EC
    // 0x8004773C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Down(rdram, ctx);
        goto after_17;
    // 0x8004773C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80047740: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80047744:
    // 0x80047744: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80047748: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8004774C: jr          $ra
    // 0x80047750: nop

    return;
    // 0x80047750: nop

;}
RECOMP_FUNC void Camera_SetupLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B73E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B73E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B73E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B73EC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800B73F0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B73F4: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800B73F8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800B73FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B7400: bne         $t6, $at, L_800B74CC
    if (ctx->r14 != ctx->r1) {
        // 0x800B7404: addiu       $a0, $a0, -0x7B48
        ctx->r4 = ADD32(ctx->r4, -0X7B48);
            goto L_800B74CC;
    }
    // 0x800B7404: addiu       $a0, $a0, -0x7B48
    ctx->r4 = ADD32(ctx->r4, -0X7B48);
    // 0x800B7408: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B740C: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800B7410: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B7414: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x800B7418: beq         $t8, $at, L_800B74CC
    if (ctx->r24 == ctx->r1) {
        // 0x800B741C: lui         $at, 0x42DC
        ctx->r1 = S32(0X42DC << 16);
            goto L_800B74CC;
    }
    // 0x800B741C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x800B7420: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B7424: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B7428: addiu       $t0, $t0, -0x7B38
    ctx->r8 = ADD32(ctx->r8, -0X7B38);
    // 0x800B742C: swc1        $f4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f4.u32l;
    // 0x800B7430: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B7434: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B7438: addiu       $v1, $v1, -0x7B04
    ctx->r3 = ADD32(ctx->r3, -0X7B04);
    // 0x800B743C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800B7440: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B7444: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B7448: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B744C: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x800B7450: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B7454: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800B7458: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x800B745C: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B7460: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x800B7464: beq         $t1, $zero, L_800B749C
    if (ctx->r9 == 0) {
        // 0x800B7468: swc1        $f16, -0x7B2C($at)
        MEM_W(-0X7B2C, ctx->r1) = ctx->f16.u32l;
            goto L_800B749C;
    }
    // 0x800B7468: swc1        $f16, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f16.u32l;
    // 0x800B746C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800B7470: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B7474: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7478: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x800B747C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B7480: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800B7484: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B7488: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x800B748C: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B7490: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x800B7494: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B7498: swc1        $f10, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f10.u32l;
L_800B749C:
    // 0x800B749C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B74A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B74A4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B74A8: addiu       $v0, $v0, -0x7AC8
    ctx->r2 = ADD32(ctx->r2, -0X7AC8);
    // 0x800B74AC: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x800B74B0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B74B4: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800B74B8: addiu       $s0, $s0, -0x7AF0
    ctx->r16 = ADD32(ctx->r16, -0X7AF0);
    // 0x800B74BC: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x800B74C0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800B74C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B74C8: swc1        $f4, -0x7B18($at)
    MEM_W(-0X7B18, ctx->r1) = ctx->f4.u32l;
L_800B74CC:
    // 0x800B74CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B74D0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800B74D4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B74D8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800B74DC: addiu       $s0, $s0, -0x7AF0
    ctx->r16 = ADD32(ctx->r16, -0X7AF0);
    // 0x800B74E0: lw          $a3, -0x7B18($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B18);
    // 0x800B74E4: lw          $a1, -0x7B3C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B3C);
    // 0x800B74E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B74EC: jal         0x8009BD38
    // 0x800B74F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_0;
    // 0x800B74F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x800B74F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B74F8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B74FC: addiu       $t0, $t0, -0x7B38
    ctx->r8 = ADD32(ctx->r8, -0X7B38);
    // 0x800B7500: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B7504: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800B7508: lw          $a3, -0x7B18($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B18);
    // 0x800B750C: addiu       $a0, $a0, -0x7B44
    ctx->r4 = ADD32(ctx->r4, -0X7B44);
    // 0x800B7510: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800B7514: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B7518: jal         0x8009BD38
    // 0x800B751C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_1;
    // 0x800B751C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800B7520: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B7524: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B7528: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B752C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800B7530: lw          $a3, -0x7B18($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B18);
    // 0x800B7534: lw          $a1, -0x7B34($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B34);
    // 0x800B7538: addiu       $a0, $a0, -0x7B40
    ctx->r4 = ADD32(ctx->r4, -0X7B40);
    // 0x800B753C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B7540: jal         0x8009BD38
    // 0x800B7544: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_2;
    // 0x800B7544: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x800B7548: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B754C: addiu       $a0, $a0, -0x7A9C
    ctx->r4 = ADD32(ctx->r4, -0X7A9C);
    // 0x800B7550: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B7554: lw          $v1, -0x7A90($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7A90);
    // 0x800B7558: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B755C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B7560: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B7564: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B7568: beq         $at, $zero, L_800B7594
    if (ctx->r1 == 0) {
        // 0x800B756C: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_800B7594;
    }
    // 0x800B756C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B7570: addiu       $a1, $a1, -0x7AC0
    ctx->r5 = ADD32(ctx->r5, -0X7AC0);
    // 0x800B7574: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800B7578: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800B757C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B7580: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800B7584: beq         $at, $zero, L_800B7594
    if (ctx->r1 == 0) {
        // 0x800B7588: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_800B7594;
    }
    // 0x800B7588: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800B758C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B7590: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B7594:
    // 0x800B7594: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B7598: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B759C: beq         $at, $zero, L_800B75BC
    if (ctx->r1 == 0) {
        // 0x800B75A0: addiu       $a1, $a1, -0x7AC0
        ctx->r5 = ADD32(ctx->r5, -0X7AC0);
            goto L_800B75BC;
    }
    // 0x800B75A0: addiu       $a1, $a1, -0x7AC0
    ctx->r5 = ADD32(ctx->r5, -0X7AC0);
    // 0x800B75A4: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800B75A8: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x800B75AC: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B75B0: beq         $at, $zero, L_800B75BC
    if (ctx->r1 == 0) {
        // 0x800B75B4: sw          $t5, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r13;
            goto L_800B75BC;
    }
    // 0x800B75B4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800B75B8: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800B75BC:
    // 0x800B75BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B75C0: addiu       $a0, $a0, -0x7A98
    ctx->r4 = ADD32(ctx->r4, -0X7A98);
    // 0x800B75C4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B75C8: lw          $v1, -0x7A8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7A8C);
    // 0x800B75CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B75D0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B75D4: beql        $at, $zero, L_800B7600
    if (ctx->r1 == 0) {
        // 0x800B75D8: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800B7600;
    }
    goto skip_0;
    // 0x800B75D8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_0:
    // 0x800B75DC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800B75E0: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800B75E4: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B75E8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B75EC: beq         $at, $zero, L_800B75FC
    if (ctx->r1 == 0) {
        // 0x800B75F0: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800B75FC;
    }
    // 0x800B75F0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800B75F4: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B75F8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B75FC:
    // 0x800B75FC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_800B7600:
    // 0x800B7600: beq         $at, $zero, L_800B7620
    if (ctx->r1 == 0) {
        // 0x800B7604: nop
    
            goto L_800B7620;
    }
    // 0x800B7604: nop

    // 0x800B7608: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800B760C: subu        $t1, $v0, $t9
    ctx->r9 = SUB32(ctx->r2, ctx->r25);
    // 0x800B7610: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B7614: beq         $at, $zero, L_800B7620
    if (ctx->r1 == 0) {
        // 0x800B7618: sw          $t1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r9;
            goto L_800B7620;
    }
    // 0x800B7618: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800B761C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800B7620:
    // 0x800B7620: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B7624: addiu       $a0, $a0, -0x7A94
    ctx->r4 = ADD32(ctx->r4, -0X7A94);
    // 0x800B7628: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B762C: lw          $v1, -0x7A88($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7A88);
    // 0x800B7630: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800B7634: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B7638: beql        $at, $zero, L_800B7664
    if (ctx->r1 == 0) {
        // 0x800B763C: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800B7664;
    }
    goto skip_1;
    // 0x800B763C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    skip_1:
    // 0x800B7640: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800B7644: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x800B7648: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B764C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800B7650: beq         $at, $zero, L_800B7660
    if (ctx->r1 == 0) {
        // 0x800B7654: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_800B7660;
    }
    // 0x800B7654: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800B7658: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B765C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B7660:
    // 0x800B7660: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_800B7664:
    // 0x800B7664: beq         $at, $zero, L_800B7684
    if (ctx->r1 == 0) {
        // 0x800B7668: nop
    
            goto L_800B7684;
    }
    // 0x800B7668: nop

    // 0x800B766C: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800B7670: subu        $t6, $v0, $t5
    ctx->r14 = SUB32(ctx->r2, ctx->r13);
    // 0x800B7674: slt         $at, $t6, $v1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B7678: beq         $at, $zero, L_800B7684
    if (ctx->r1 == 0) {
        // 0x800B767C: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_800B7684;
    }
    // 0x800B767C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B7680: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_800B7684:
    // 0x800B7684: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B7688: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B768C: lw          $a1, -0x7B08($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B08);
    // 0x800B7690: addiu       $a0, $a0, -0x7B14
    ctx->r4 = ADD32(ctx->r4, -0X7B14);
    // 0x800B7694: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800B7698: jal         0x8009BD38
    // 0x800B769C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_3;
    // 0x800B769C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x800B76A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B76A4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B76A8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B76AC: lw          $a1, -0x7B04($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B04);
    // 0x800B76B0: addiu       $a0, $a0, -0x7B10
    ctx->r4 = ADD32(ctx->r4, -0X7B10);
    // 0x800B76B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B76B8: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800B76BC: jal         0x8009BD38
    // 0x800B76C0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x800B76C0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x800B76C4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B76C8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B76CC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B76D0: lw          $a1, -0x7B00($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B00);
    // 0x800B76D4: addiu       $a0, $a0, -0x7B0C
    ctx->r4 = ADD32(ctx->r4, -0X7B0C);
    // 0x800B76D8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B76DC: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x800B76E0: jal         0x8009BD38
    // 0x800B76E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x800B76E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800B76E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B76EC: lwc1        $f6, -0x7B30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B30);
    // 0x800B76F0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B76F4: addiu       $v0, $v0, -0x7B3C
    ctx->r2 = ADD32(ctx->r2, -0X7B3C);
    // 0x800B76F8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800B76FC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800B7700: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7704: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800B7708: swc1        $f8, -0x7B08($at)
    MEM_W(-0X7B08, ctx->r1) = ctx->f8.u32l;
    // 0x800B770C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7710: lwc1        $f10, -0x7B2C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7B2C);
    // 0x800B7714: addiu       $t0, $t0, -0x7B38
    ctx->r8 = ADD32(ctx->r8, -0X7B38);
    // 0x800B7718: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B771C: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800B7720: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800B7724: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B7728: addiu       $v1, $v1, -0x7B34
    ctx->r3 = ADD32(ctx->r3, -0X7B34);
    // 0x800B772C: swc1        $f16, -0x7B04($at)
    MEM_W(-0X7B04, ctx->r1) = ctx->f16.u32l;
    // 0x800B7730: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7734: lwc1        $f18, -0x7B28($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7B28);
    // 0x800B7738: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B773C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B7740: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x800B7744: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B7748: lw          $t8, -0x7AB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AB8);
    // 0x800B774C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B7750: swc1        $f4, -0x7B00($at)
    MEM_W(-0X7B00, ctx->r1) = ctx->f4.u32l;
    // 0x800B7754: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B7758: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B775C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7760: lw          $t9, -0x7AB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB4);
    // 0x800B7764: swc1        $f6, -0x7B18($at)
    MEM_W(-0X7B18, ctx->r1) = ctx->f6.u32l;
    // 0x800B7768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B776C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B7770: sw          $t8, -0x7A90($at)
    MEM_W(-0X7A90, ctx->r1) = ctx->r24;
    // 0x800B7774: lw          $t1, -0x7AB0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AB0);
    // 0x800B7778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B777C: sw          $t9, -0x7A8C($at)
    MEM_W(-0X7A8C, ctx->r1) = ctx->r25;
    // 0x800B7780: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800B7784: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7788: sw          $t1, -0x7A88($at)
    MEM_W(-0X7A88, ctx->r1) = ctx->r9;
    // 0x800B778C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7790: lwc1        $f8, -0x74A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X74A0);
    // 0x800B7794: lwc1        $f0, 0x34($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X34);
    // 0x800B7798: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800B779C: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x800B77A0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800B77A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B77A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B77AC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800B77B0: jal         0x80005FE0
    // 0x800B77B4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x800B77B4: nop

    after_6:
    // 0x800B77B8: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x800B77BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B77C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B77C4: lwc1        $f16, 0x5C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X5C);
    // 0x800B77C8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B77CC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B77D0: jal         0x80005D44
    // 0x800B77D4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x800B77D4: nop

    after_7:
    // 0x800B77D8: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x800B77DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B77E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B77E4: jal         0x80005E90
    // 0x800B77E8: lw          $a1, 0x58($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X58);
    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x800B77E8: lw          $a1, 0x58($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X58);
    after_8:
    // 0x800B77EC: jal         0x80005708
    // 0x800B77F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x800B77F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800B77F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B77F8: lwc1        $f4, -0x749C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X749C);
    // 0x800B77FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7800: lwc1        $f6, -0x7B48($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B48);
    // 0x800B7804: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B7808: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B780C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B7810: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B7814: jal         0x80005D44
    // 0x800B7818: nop

    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x800B7818: nop

    after_10:
    // 0x800B781C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7820: lwc1        $f10, -0x7498($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7498);
    // 0x800B7824: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7828: lwc1        $f16, -0x7B44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B44);
    // 0x800B782C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B7830: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B7834: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B7838: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B783C: jal         0x80005E90
    // 0x800B7840: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x800B7840: nop

    after_11:
    // 0x800B7844: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7848: lwc1        $f4, -0x7494($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7494);
    // 0x800B784C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7850: lwc1        $f6, -0x7B40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B40);
    // 0x800B7854: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B7858: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B785C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B7860: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B7864: jal         0x80005FE0
    // 0x800B7868: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_12;
    // 0x800B7868: nop

    after_12:
    // 0x800B786C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800B7870: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B7874: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B7878: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B787C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B7880: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B7884: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800B7888: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800B788C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800B7890: jal         0x80006A20
    // 0x800B7894: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_13;
    // 0x800B7894: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x800B7898: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B789C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B78A0: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B78A4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B78A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B78AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B78B0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800B78B4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B78B8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800B78BC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B78C0: sw          $t6, -0x7B24($at)
    MEM_W(-0X7B24, ctx->r1) = ctx->r14;
    // 0x800B78C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B78C8: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x800B78CC: sw          $t8, -0x7B20($at)
    MEM_W(-0X7B20, ctx->r1) = ctx->r24;
    // 0x800B78D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B78D4: jal         0x80005740
    // 0x800B78D8: sw          $t1, -0x7B1C($at)
    MEM_W(-0X7B1C, ctx->r1) = ctx->r9;
    Matrix_Pop(rdram, ctx);
        goto after_14;
    // 0x800B78D8: sw          $t1, -0x7B1C($at)
    MEM_W(-0X7B1C, ctx->r1) = ctx->r9;
    after_14:
    // 0x800B78DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B78E0: lwc1        $f4, -0x7490($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7490);
    // 0x800B78E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B78E8: lwc1        $f6, -0x7B14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B14);
    // 0x800B78EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B78F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B78F4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B78F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B78FC: jal         0x80005D44
    // 0x800B7900: nop

    Matrix_RotateX(rdram, ctx);
        goto after_15;
    // 0x800B7900: nop

    after_15:
    // 0x800B7904: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7908: lwc1        $f10, -0x748C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X748C);
    // 0x800B790C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7910: lwc1        $f16, -0x7B10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B10);
    // 0x800B7914: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B7918: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B791C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B7920: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B7924: jal         0x80005E90
    // 0x800B7928: nop

    Matrix_RotateY(rdram, ctx);
        goto after_16;
    // 0x800B7928: nop

    after_16:
    // 0x800B792C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7930: lwc1        $f4, -0x7488($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7488);
    // 0x800B7934: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7938: lwc1        $f6, -0x7B0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B0C);
    // 0x800B793C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B7940: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B7944: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B7948: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B794C: jal         0x80005FE0
    // 0x800B7950: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_17;
    // 0x800B7950: nop

    after_17:
    // 0x800B7954: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800B7958: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B795C: jal         0x80006A20
    // 0x800B7960: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_18;
    // 0x800B7960: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_18:
    // 0x800B7964: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B7968: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B796C: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B7970: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800B7974: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7978: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B797C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800B7980: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x800B7984: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B7988: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x800B798C: sw          $t3, -0x7AFC($at)
    MEM_W(-0X7AFC, ctx->r1) = ctx->r11;
    // 0x800B7990: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7994: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800B7998: sw          $t5, -0x7AF8($at)
    MEM_W(-0X7AF8, ctx->r1) = ctx->r13;
    // 0x800B799C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B79A0: sw          $t7, -0x7AF4($at)
    MEM_W(-0X7AF4, ctx->r1) = ctx->r15;
    // 0x800B79A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B79A8: jr          $ra
    // 0x800B79AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B79AC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_enmy_80066EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066EE4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80066EE8: jr          $ra
    // 0x80066EEC: nop

    return;
    // 0x80066EEC: nop

;}
RECOMP_FUNC void Play_InitVsStage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4F7C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A4F80: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A4F84: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800A4F88: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800A4F8C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800A4F90: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800A4F94: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800A4F98: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800A4F9C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800A4FA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800A4FA4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A4FA8: lw          $v0, 0x789C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X789C);
    // 0x800A4FAC: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800A4FB0: addiu       $s3, $s3, -0x7CF0
    ctx->r19 = ADD32(ctx->r19, -0X7CF0);
    // 0x800A4FB4: beq         $v0, $zero, L_800A4FDC
    if (ctx->r2 == 0) {
        // 0x800A4FB8: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800A4FDC;
    }
    // 0x800A4FB8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A4FBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4FC0: beq         $v0, $at, L_800A5018
    if (ctx->r2 == ctx->r1) {
        // 0x800A4FC4: lui         $s3, 0x8018
        ctx->r19 = S32(0X8018 << 16);
            goto L_800A5018;
    }
    // 0x800A4FC4: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800A4FC8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800A4FCC: beq         $v0, $v1, L_800A505C
    if (ctx->r2 == ctx->r3) {
        // 0x800A4FD0: lui         $s3, 0x8018
        ctx->r19 = S32(0X8018 << 16);
            goto L_800A505C;
    }
    // 0x800A4FD0: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800A4FD4: b           L_800A50F4
    // 0x800A4FD8: addiu       $s3, $s3, -0x7CF0
    ctx->r19 = ADD32(ctx->r19, -0X7CF0);
        goto L_800A50F4;
    // 0x800A4FD8: addiu       $s3, $s3, -0x7CF0
    ctx->r19 = ADD32(ctx->r19, -0X7CF0);
L_800A4FDC:
    // 0x800A4FDC: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800A4FE0: addiu       $v0, $v0, -0x21C4
    ctx->r2 = ADD32(ctx->r2, -0X21C4);
    // 0x800A4FE4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800A4FE8: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800A4FEC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A4FF0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A4FF4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A4FF8: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x800A4FFC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5000: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x800A5004: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5008: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800A500C: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x800A5010: b           L_800A50F4
    // 0x800A5014: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
        goto L_800A50F4;
    // 0x800A5014: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
L_800A5018:
    // 0x800A5018: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800A501C: addiu       $v0, $v0, -0x1F1C
    ctx->r2 = ADD32(ctx->r2, -0X1F1C);
    // 0x800A5020: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x800A5024: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x800A5028: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800A502C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A5030: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800A5034: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A5038: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x800A503C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5040: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800A5044: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5048: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A504C: addiu       $s3, $s3, -0x7CF0
    ctx->r19 = ADD32(ctx->r19, -0X7CF0);
    // 0x800A5050: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800A5054: b           L_800A50F4
    // 0x800A5058: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
        goto L_800A50F4;
    // 0x800A5058: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
L_800A505C:
    // 0x800A505C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800A5060: lw          $t0, 0x78AC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78AC);
    // 0x800A5064: bne         $v1, $t0, L_800A50B0
    if (ctx->r3 != ctx->r8) {
        // 0x800A5068: lui         $v0, 0x303
        ctx->r2 = S32(0X303 << 16);
            goto L_800A50B0;
    }
    // 0x800A5068: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800A506C: addiu       $v0, $v0, -0x1C88
    ctx->r2 = ADD32(ctx->r2, -0X1C88);
    // 0x800A5070: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x800A5074: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x800A5078: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A507C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A5080: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800A5084: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A5088: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x800A508C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5090: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x800A5094: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800A5098: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A509C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800A50A0: addiu       $s3, $s3, -0x7CF0
    ctx->r19 = ADD32(ctx->r19, -0X7CF0);
    // 0x800A50A4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800A50A8: b           L_800A50F4
    // 0x800A50AC: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
        goto L_800A50F4;
    // 0x800A50AC: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
L_800A50B0:
    // 0x800A50B0: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800A50B4: addiu       $v0, $v0, -0x1E90
    ctx->r2 = ADD32(ctx->r2, -0X1E90);
    // 0x800A50B8: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800A50BC: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x800A50C0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800A50C4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800A50C8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800A50CC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A50D0: lw          $t1, 0x1FD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1FD0);
    // 0x800A50D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A50D8: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x800A50DC: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x800A50E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A50E4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A50E8: addiu       $s3, $s3, -0x7CF0
    ctx->r19 = ADD32(ctx->r19, -0X7CF0);
    // 0x800A50EC: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x800A50F0: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
L_800A50F4:
    // 0x800A50F4: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x800A50F8: addiu       $s2, $s2, -0x7D58
    ctx->r18 = ADD32(ctx->r18, -0X7D58);
    // 0x800A50FC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800A5100: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A5104: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x800A5108: addiu       $s6, $zero, 0x58
    ctx->r22 = ADD32(0, 0X58);
    // 0x800A510C: addiu       $s5, $zero, 0x93
    ctx->r21 = ADD32(0, 0X93);
L_800A5110:
    // 0x800A5110: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800A5114: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A5118: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x800A511C: bgez        $v0, L_800A512C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A5120: nop
    
            goto L_800A512C;
    }
    // 0x800A5120: nop

    // 0x800A5124: b           L_800A51FC
    // 0x800A5128: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
        goto L_800A51FC;
    // 0x800A5128: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_800A512C:
    // 0x800A512C: bnel        $s5, $v0, L_800A51F0
    if (ctx->r21 != ctx->r2) {
        // 0x800A5130: slti        $at, $s4, 0xC7
        ctx->r1 = SIGNED(ctx->r20) < 0XC7 ? 1 : 0;
            goto L_800A51F0;
    }
    goto skip_0;
    // 0x800A5130: slti        $at, $s4, 0xC7
    ctx->r1 = SIGNED(ctx->r20) < 0XC7 ? 1 : 0;
    skip_0:
    // 0x800A5134: multu       $s4, $s6
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A5138: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A513C: mflo        $s0
    ctx->r16 = lo;
    // 0x800A5140: addu        $a0, $s0, $t7
    ctx->r4 = ADD32(ctx->r16, ctx->r15);
    // 0x800A5144: jal         0x800A4F4C
    // 0x800A5148: nop

    Scenery360_Initialize(rdram, ctx);
        goto after_0;
    // 0x800A5148: nop

    after_0:
    // 0x800A514C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A5150: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800A5154: sb          $s7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r23;
    // 0x800A5158: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800A515C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A5160: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800A5164: lh          $t2, 0x10($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X10);
    // 0x800A5168: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800A516C: sh          $t2, 0x2($t4)
    MEM_H(0X2, ctx->r12) = ctx->r10;
    // 0x800A5170: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800A5174: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A5178: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A517C: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x800A5180: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800A5184: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800A5188: nop

    // 0x800A518C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5190: swc1        $f6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->f6.u32l;
    // 0x800A5194: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800A5198: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A519C: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800A51A0: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800A51A4: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800A51A8: swc1        $f8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f8.u32l;
    // 0x800A51AC: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800A51B0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A51B4: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x800A51B8: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x800A51BC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800A51C0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A51C4: nop

    // 0x800A51C8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A51CC: swc1        $f16, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f16.u32l;
    // 0x800A51D0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A51D4: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x800A51D8: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x800A51DC: lhu         $a1, 0x2($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X2);
    // 0x800A51E0: jal         0x800612B8
    // 0x800A51E4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800A51E4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x800A51E8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800A51EC: slti        $at, $s4, 0xC7
    ctx->r1 = SIGNED(ctx->r20) < 0XC7 ? 1 : 0;
L_800A51F0:
    // 0x800A51F0: bne         $at, $zero, L_800A5110
    if (ctx->r1 != 0) {
        // 0x800A51F4: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_800A5110;
    }
    // 0x800A51F4: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x800A51F8: addiu       $s4, $zero, 0x5
    ctx->r20 = ADD32(0, 0X5);
L_800A51FC:
    // 0x800A51FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800A5200:
    // 0x800A5200: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800A5204: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800A5208: lh          $v0, 0x10($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X10);
    // 0x800A520C: bltzl       $v0, L_800A5308
    if (SIGNED(ctx->r2) < 0) {
        // 0x800A5210: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800A5308;
    }
    goto skip_1;
    // 0x800A5210: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x800A5214: beql        $s5, $v0, L_800A52FC
    if (ctx->r21 == ctx->r2) {
        // 0x800A5218: slti        $at, $s4, 0xC7
        ctx->r1 = SIGNED(ctx->r20) < 0XC7 ? 1 : 0;
            goto L_800A52FC;
    }
    goto skip_2;
    // 0x800A5218: slti        $at, $s4, 0xC7
    ctx->r1 = SIGNED(ctx->r20) < 0XC7 ? 1 : 0;
    skip_2:
    // 0x800A521C: multu       $s4, $s6
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A5220: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A5224: mflo        $s0
    ctx->r16 = lo;
    // 0x800A5228: addu        $a0, $s0, $t3
    ctx->r4 = ADD32(ctx->r16, ctx->r11);
    // 0x800A522C: jal         0x800A4F4C
    // 0x800A5230: nop

    Scenery360_Initialize(rdram, ctx);
        goto after_2;
    // 0x800A5230: nop

    after_2:
    // 0x800A5234: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A5238: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x800A523C: sb          $s7, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r23;
    // 0x800A5240: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800A5244: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A5248: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A524C: lh          $t7, 0x10($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X10);
    // 0x800A5250: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x800A5254: sh          $t7, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r15;
    // 0x800A5258: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800A525C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A5260: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800A5264: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x800A5268: addu        $t4, $t2, $s0
    ctx->r12 = ADD32(ctx->r10, ctx->r16);
    // 0x800A526C: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x800A5270: nop

    // 0x800A5274: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A5278: swc1        $f4, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->f4.u32l;
    // 0x800A527C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800A5280: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A5284: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A5288: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800A528C: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x800A5290: swc1        $f6, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f6.u32l;
    // 0x800A5294: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800A5298: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A529C: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x800A52A0: lh          $t1, 0x8($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X8);
    // 0x800A52A4: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800A52A8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800A52AC: nop

    // 0x800A52B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A52B4: swc1        $f10, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f10.u32l;
    // 0x800A52B8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800A52BC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A52C0: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x800A52C4: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x800A52C8: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x800A52CC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800A52D0: nop

    // 0x800A52D4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A52D8: swc1        $f18, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f18.u32l;
    // 0x800A52DC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A52E0: addu        $a0, $s0, $v0
    ctx->r4 = ADD32(ctx->r16, ctx->r2);
    // 0x800A52E4: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x800A52E8: lhu         $a1, 0x2($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X2);
    // 0x800A52EC: jal         0x800612B8
    // 0x800A52F0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x800A52F0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x800A52F4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800A52F8: slti        $at, $s4, 0xC7
    ctx->r1 = SIGNED(ctx->r20) < 0XC7 ? 1 : 0;
L_800A52FC:
    // 0x800A52FC: bne         $at, $zero, L_800A5200
    if (ctx->r1 != 0) {
        // 0x800A5300: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_800A5200;
    }
    // 0x800A5300: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    // 0x800A5304: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800A5308:
    // 0x800A5308: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800A530C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800A5310: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5314: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800A5318: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800A531C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800A5320: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5324: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800A5328: jr          $ra
    // 0x800A532C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800A532C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_edisplay_8005A010(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005A014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A018: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x8005A01C: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8005A020: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005A024: bne         $t6, $zero, L_8005A06C
    if (ctx->r14 != 0) {
        // 0x8005A028: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8005A06C;
    }
    // 0x8005A028: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005A02C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005A030: jal         0x80005E90
    // 0x8005A034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8005A034: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x8005A038: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005A03C: jal         0x80006EB8
    // 0x8005A040: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8005A040: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x8005A044: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8005A048: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8005A04C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005A050: lui         $t9, 0x603
    ctx->r25 = S32(0X603 << 16);
    // 0x8005A054: addiu       $t9, $t9, 0x61F0
    ctx->r25 = ADD32(ctx->r25, 0X61F0);
    // 0x8005A058: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005A05C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8005A060: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005A064: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005A068: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_8005A06C:
    // 0x8005A06C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A070: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005A074: jr          $ra
    // 0x8005A078: nop

    return;
    // 0x8005A078: nop

;}
RECOMP_FUNC void HUD_DisplaySmallNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C390: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8008C394: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8008C398: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8008C39C: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8008C3A0: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8008C3A4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8008C3A8: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x8008C3AC: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8008C3B0: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x8008C3B4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8008C3B8: addiu       $s5, $sp, 0x70
    ctx->r21 = ADD32(ctx->r29, 0X70);
    // 0x8008C3BC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8008C3C0: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8008C3C4: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8008C3C8: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x8008C3CC: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8008C3D0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8008C3D4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8008C3D8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8008C3DC: addiu       $t6, $t6, 0x1EC0
    ctx->r14 = ADD32(ctx->r14, 0X1EC0);
    // 0x8008C3E0: addiu       $t9, $t6, 0x24
    ctx->r25 = ADD32(ctx->r14, 0X24);
    // 0x8008C3E4: or          $t0, $s5, $zero
    ctx->r8 = ctx->r21 | 0;
L_8008C3E8:
    // 0x8008C3E8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8008C3EC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8008C3F0: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8008C3F4: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x8008C3F8: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x8008C3FC: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8008C400: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8008C404: bne         $t6, $t9, L_8008C3E8
    if (ctx->r14 != ctx->r25) {
        // 0x8008C408: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_8008C3E8;
    }
    // 0x8008C408: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x8008C40C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8008C410: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x8008C414: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8008C418: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8008C41C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8008C420: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008C424: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x8008C428: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x8008C42C: mul.s       $f28, $f4, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f28.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8008C430: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008C434: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8008C438: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
L_8008C43C:
    // 0x8008C43C: nop

    // 0x8008C440: bc1f        L_8008C4B0
    if (!c1cs) {
        // 0x8008C444: nop
    
            goto L_8008C4B0;
    }
    // 0x8008C444: nop

    // 0x8008C448: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x8008C44C: nop

    // 0x8008C450: bc1f        L_8008C4B0
    if (!c1cs) {
        // 0x8008C454: nop
    
            goto L_8008C4B0;
    }
    // 0x8008C454: nop

    // 0x8008C458: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8008C45C: mflo        $t1
    ctx->r9 = lo;
    // 0x8008C460: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8008C464: addu        $t3, $s5, $t2
    ctx->r11 = ADD32(ctx->r21, ctx->r10);
    // 0x8008C468: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x8008C46C: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8008C470: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x8008C474: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x8008C478: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8008C47C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008C480: bne         $s0, $zero, L_8008C48C
    if (ctx->r16 != 0) {
        // 0x8008C484: nop
    
            goto L_8008C48C;
    }
    // 0x8008C484: nop

    // 0x8008C488: break       7
    do_break(2148058248);
L_8008C48C:
    // 0x8008C48C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008C490: bne         $s0, $at, L_8008C4A4
    if (ctx->r16 != ctx->r1) {
        // 0x8008C494: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008C4A4;
    }
    // 0x8008C494: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008C498: bne         $s1, $at, L_8008C4A4
    if (ctx->r17 != ctx->r1) {
        // 0x8008C49C: nop
    
            goto L_8008C4A4;
    }
    // 0x8008C49C: nop

    // 0x8008C4A0: break       6
    do_break(2148058272);
L_8008C4A4:
    // 0x8008C4A4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008C4A8: jal         0x8009D994
    // 0x8008C4AC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x8008C4AC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_0:
L_8008C4B0:
    // 0x8008C4B0: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8008C4B4: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x8008C4B8: bne         $s0, $zero, L_8008C4C4
    if (ctx->r16 != 0) {
        // 0x8008C4BC: nop
    
            goto L_8008C4C4;
    }
    // 0x8008C4BC: nop

    // 0x8008C4C0: break       7
    do_break(2148058304);
L_8008C4C4:
    // 0x8008C4C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008C4C8: bne         $s0, $at, L_8008C4DC
    if (ctx->r16 != ctx->r1) {
        // 0x8008C4CC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008C4DC;
    }
    // 0x8008C4CC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008C4D0: bne         $s1, $at, L_8008C4DC
    if (ctx->r17 != ctx->r1) {
        // 0x8008C4D4: nop
    
            goto L_8008C4DC;
    }
    // 0x8008C4D4: nop

    // 0x8008C4D8: break       6
    do_break(2148058328);
L_8008C4DC:
    // 0x8008C4DC: mfhi        $s1
    ctx->r17 = hi;
    // 0x8008C4E0: nop

    // 0x8008C4E4: nop

    // 0x8008C4E8: div         $zero, $s0, $s2
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r18)));
    // 0x8008C4EC: bne         $s2, $zero, L_8008C4F8
    if (ctx->r18 != 0) {
        // 0x8008C4F0: nop
    
            goto L_8008C4F8;
    }
    // 0x8008C4F0: nop

    // 0x8008C4F4: break       7
    do_break(2148058356);
L_8008C4F8:
    // 0x8008C4F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008C4FC: bne         $s2, $at, L_8008C510
    if (ctx->r18 != ctx->r1) {
        // 0x8008C500: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008C510;
    }
    // 0x8008C500: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008C504: bne         $s0, $at, L_8008C510
    if (ctx->r16 != ctx->r1) {
        // 0x8008C508: nop
    
            goto L_8008C510;
    }
    // 0x8008C508: nop

    // 0x8008C50C: break       6
    do_break(2148058380);
L_8008C510:
    // 0x8008C510: mflo        $s0
    ctx->r16 = lo;
    // 0x8008C514: bnel        $s0, $s3, L_8008C43C
    if (ctx->r16 != ctx->r19) {
        // 0x8008C518: c.lt.s      $f22, $f20
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
            goto L_8008C43C;
    }
    goto skip_0;
    // 0x8008C518: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    skip_0:
    // 0x8008C51C: c.lt.s      $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f22.fl < ctx->f20.fl;
    // 0x8008C520: nop

    // 0x8008C524: bc1fl       L_8008C594
    if (!c1cs) {
        // 0x8008C528: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8008C594;
    }
    goto skip_1;
    // 0x8008C528: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x8008C52C: c.lt.s      $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f22.fl < ctx->f26.fl;
    // 0x8008C530: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8008C534: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8008C538: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8008C53C: bc1fl       L_8008C594
    if (!c1cs) {
        // 0x8008C540: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8008C594;
    }
    goto skip_2;
    // 0x8008C540: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x8008C544: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x8008C548: mflo        $t4
    ctx->r12 = lo;
    // 0x8008C54C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8008C550: addu        $t8, $s5, $t5
    ctx->r24 = ADD32(ctx->r21, ctx->r13);
    // 0x8008C554: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x8008C558: bne         $s0, $zero, L_8008C564
    if (ctx->r16 != 0) {
        // 0x8008C55C: nop
    
            goto L_8008C564;
    }
    // 0x8008C55C: nop

    // 0x8008C560: break       7
    do_break(2148058464);
L_8008C564:
    // 0x8008C564: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008C568: bne         $s0, $at, L_8008C57C
    if (ctx->r16 != ctx->r1) {
        // 0x8008C56C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008C57C;
    }
    // 0x8008C56C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008C570: bne         $s1, $at, L_8008C57C
    if (ctx->r17 != ctx->r1) {
        // 0x8008C574: nop
    
            goto L_8008C57C;
    }
    // 0x8008C574: nop

    // 0x8008C578: break       6
    do_break(2148058488);
L_8008C57C:
    // 0x8008C57C: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8008C580: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x8008C584: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x8008C588: jal         0x8009D994
    // 0x8008C58C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x8008C58C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x8008C590: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8008C594:
    // 0x8008C594: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8008C598: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8008C59C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8008C5A0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8008C5A4: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8008C5A8: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8008C5AC: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8008C5B0: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8008C5B4: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8008C5B8: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8008C5BC: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8008C5C0: jr          $ra
    // 0x8008C5C4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8008C5C4: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Display_ArwingWingTrail_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056230: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80056234: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80056238: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005623C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80056240: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80056244: lw          $t6, 0x234($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X234);
    // 0x80056248: beql        $t6, $zero, L_800563A4
    if (ctx->r14 == 0) {
        // 0x8005624C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800563A4;
    }
    goto skip_0;
    // 0x8005624C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80056250: lw          $t7, 0x1CC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1CC);
    // 0x80056254: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80056258: bnel        $t7, $zero, L_800563A4
    if (ctx->r15 != 0) {
        // 0x8005625C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800563A4;
    }
    goto skip_1;
    // 0x8005625C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80056260: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80056264: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80056268: beq         $v0, $at, L_800563A0
    if (ctx->r2 == ctx->r1) {
        // 0x8005626C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800563A0;
    }
    // 0x8005626C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80056270: beq         $v0, $at, L_800563A0
    if (ctx->r2 == ctx->r1) {
        // 0x80056274: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_800563A0;
    }
    // 0x80056274: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80056278: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x8005627C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80056280: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80056284: bnel        $t8, $zero, L_800563A4
    if (ctx->r24 != 0) {
        // 0x80056288: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800563A4;
    }
    goto skip_2;
    // 0x80056288: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8005628C: jal         0x80005708
    // 0x80056290: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80056290: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80056294: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80056298: lwc1        $f6, 0x144($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X144);
    // 0x8005629C: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x800562A0: lw          $a2, 0x78($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X78);
    // 0x800562A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800562A8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800562AC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800562B0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800562B4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800562B8: jal         0x80005B00
    // 0x800562BC: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x800562BC: nop

    after_1:
    // 0x800562C0: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800562C4: lwc1        $f16, 0xE8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800562C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800562CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800562D0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800562D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800562D8: lwc1        $f8, 0x5F00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F00);
    // 0x800562DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800562E0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800562E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800562E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800562EC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800562F0: jal         0x80005E90
    // 0x800562F4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x800562F4: nop

    after_2:
    // 0x800562F8: lwc1        $f16, 0x120($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800562FC: lwc1        $f18, 0xE4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80056300: lwc1        $f6, 0x4D8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x80056304: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056308: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8005630C: lwc1        $f10, 0x5F04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F04);
    // 0x80056310: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80056314: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056318: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005631C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80056320: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80056324: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80056328: jal         0x80005D44
    // 0x8005632C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x8005632C: nop

    after_3:
    // 0x80056330: lwc1        $f4, 0xF8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80056334: lwc1        $f6, 0xF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80056338: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x8005633C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056340: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056344: lwc1        $f18, 0x5F08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F08);
    // 0x80056348: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005634C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056350: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80056354: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80056358: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005635C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80056360: jal         0x80005FE0
    // 0x80056364: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x80056364: nop

    after_4:
    // 0x80056368: lw          $a1, 0x84($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X84);
    // 0x8005636C: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    // 0x80056370: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80056374: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80056378: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8005637C: jal         0x80005B00
    // 0x80056380: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x80056380: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x80056384: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80056388: jal         0x80006EB8
    // 0x8005638C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8005638C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_6:
    // 0x80056390: jal         0x80055E98
    // 0x80056394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_ArwingWingTrail_Draw(rdram, ctx);
        goto after_7;
    // 0x80056394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80056398: jal         0x80005740
    // 0x8005639C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x8005639C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
L_800563A0:
    // 0x800563A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800563A4:
    // 0x800563A4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800563A8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800563AC: jr          $ra
    // 0x800563B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800563B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_radio_800BB388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BB388: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800BB38C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BB390: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800BB394: lw          $t6, 0x7834($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7834);
    // 0x800BB398: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BB39C: beq         $t6, $at, L_800BB558
    if (ctx->r14 == ctx->r1) {
        // 0x800BB3A0: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800BB558;
    }
    // 0x800BB3A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB3A4: lwc1        $f2, 0x7D50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7D50);
    // 0x800BB3A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BB3AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BB3B0: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x800BB3B4: nop

    // 0x800BB3B8: bc1t        L_800BB558
    if (c1cs) {
        // 0x800BB3BC: nop
    
            goto L_800BB558;
    }
    // 0x800BB3BC: nop

    // 0x800BB3C0: lwc1        $f6, -0x6FB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6FB4);
    // 0x800BB3C4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800BB3C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BB3CC: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BB3D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB3D4: lwc1        $f0, -0x78CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78CC);
    // 0x800BB3D8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800BB3DC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BB3E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BB3E4: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800BB3E8: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BB3EC: add.s       $f14, $f12, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800BB3F0: c.le.s      $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f18.fl <= ctx->f14.fl;
    // 0x800BB3F4: nop

    // 0x800BB3F8: bc1fl       L_800BB410
    if (!c1cs) {
        // 0x800BB3FC: c.le.s      $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
            goto L_800BB410;
    }
    goto skip_0;
    // 0x800BB3FC: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    skip_0:
    // 0x800BB400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BB404: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BB408: swc1        $f4, 0x4A78($at)
    MEM_W(0X4A78, ctx->r1) = ctx->f4.u32l;
    // 0x800BB40C: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
L_800BB410:
    // 0x800BB410: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800BB414: bc1f        L_800BB428
    if (!c1cs) {
        // 0x800BB418: nop
    
            goto L_800BB428;
    }
    // 0x800BB418: nop

    // 0x800BB41C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BB420: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BB424: swc1        $f6, 0x4A78($at)
    MEM_W(0X4A78, ctx->r1) = ctx->f6.u32l;
L_800BB428:
    // 0x800BB428: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800BB42C: lwc1        $f8, 0x4A78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4A78);
    // 0x800BB430: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB434: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB438: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x800BB43C: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x800BB440: jal         0x800B8DD0
    // 0x800BB444: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BB444: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800BB448: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800BB44C: lw          $v0, 0x7834($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7834);
    // 0x800BB450: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB454: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BB458: beq         $v0, $at, L_800BB474
    if (ctx->r2 == ctx->r1) {
        // 0x800BB45C: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_800BB474;
    }
    // 0x800BB45C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB460: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800BB464: beq         $v0, $at, L_800BB490
    if (ctx->r2 == ctx->r1) {
        // 0x800BB468: lui         $t9, 0x101
        ctx->r25 = S32(0X101 << 16);
            goto L_800BB490;
    }
    // 0x800BB468: lui         $t9, 0x101
    ctx->r25 = S32(0X101 << 16);
    // 0x800BB46C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800BB470: bne         $v0, $at, L_800BB4A4
    if (ctx->r2 != ctx->r1) {
        // 0x800BB474: lui         $t7, 0x602
        ctx->r15 = S32(0X602 << 16);
            goto L_800BB4A4;
    }
L_800BB474:
    // 0x800BB474: lui         $t7, 0x602
    ctx->r15 = S32(0X602 << 16);
    // 0x800BB478: lui         $t8, 0x602
    ctx->r24 = S32(0X602 << 16);
    // 0x800BB47C: addiu       $t7, $t7, -0x28B0
    ctx->r15 = ADD32(ctx->r15, -0X28B0);
    // 0x800BB480: addiu       $t8, $t8, -0x24B0
    ctx->r24 = ADD32(ctx->r24, -0X24B0);
    // 0x800BB484: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800BB488: b           L_800BB4A4
    // 0x800BB48C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_800BB4A4;
    // 0x800BB48C: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_800BB490:
    // 0x800BB490: lui         $t0, 0x101
    ctx->r8 = S32(0X101 << 16);
    // 0x800BB494: addiu       $t9, $t9, 0x3170
    ctx->r25 = ADD32(ctx->r25, 0X3170);
    // 0x800BB498: addiu       $t0, $t0, 0x3570
    ctx->r8 = ADD32(ctx->r8, 0X3570);
    // 0x800BB49C: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800BB4A0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
L_800BB4A4:
    // 0x800BB4A4: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BB4A8: lw          $t1, -0x78BC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X78BC);
    // 0x800BB4AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BB4B0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x800BB4B4: bne         $t1, $at, L_800BB4E4
    if (ctx->r9 != ctx->r1) {
        // 0x800BB4B8: addiu       $t8, $zero, 0x20
        ctx->r24 = ADD32(0, 0X20);
            goto L_800BB4E4;
    }
    // 0x800BB4B8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800BB4BC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BB4C0: lui         $t4, 0xFF19
    ctx->r12 = S32(0XFF19 << 16);
    // 0x800BB4C4: ori         $t4, $t4, 0x19AA
    ctx->r12 = ctx->r12 | 0X19AA;
    // 0x800BB4C8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800BB4CC: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800BB4D0: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800BB4D4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800BB4D8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800BB4DC: b           L_800BB504
    // 0x800BB4E0: nop

        goto L_800BB504;
    // 0x800BB4E0: nop

L_800BB4E4:
    // 0x800BB4E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BB4E8: lui         $t7, 0x3C3C
    ctx->r15 = S32(0X3C3C << 16);
    // 0x800BB4EC: ori         $t7, $t7, 0xFFAA
    ctx->r15 = ctx->r15 | 0XFFAA;
    // 0x800BB4F0: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800BB4F4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800BB4F8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800BB4FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BB500: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_800BB504:
    // 0x800BB504: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB508: lwc1        $f16, -0x78D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X78D0);
    // 0x800BB50C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB510: lwc1        $f18, -0x78CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X78CC);
    // 0x800BB514: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800BB518: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BB51C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800BB520: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB524: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800BB528: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800BB52C: lwc1        $f16, -0x78C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X78C8);
    // 0x800BB530: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB534: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800BB538: lwc1        $f18, 0x7D50($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D50);
    // 0x800BB53C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800BB540: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800BB544: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800BB548: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800BB54C: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800BB550: jal         0x8009D0BC
    // 0x800BB554: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x800BB554: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
L_800BB558:
    // 0x800BB558: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BB55C: lwc1        $f4, -0x6FB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6FB0);
    // 0x800BB560: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800BB564: lwc1        $f6, 0x7D50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D50);
    // 0x800BB568: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB56C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB570: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800BB574: nop

    // 0x800BB578: bc1fl       L_800BB5C4
    if (!c1cs) {
        // 0x800BB57C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800BB5C4;
    }
    goto skip_1;
    // 0x800BB57C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x800BB580: jal         0x800B8DD0
    // 0x800BB584: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x800BB584: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_2:
    // 0x800BB588: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800BB58C: lw          $t9, -0x7D28($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D28);
    // 0x800BB590: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BB594: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800BB598: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800BB59C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800BB5A0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BB5A4: lw          $a3, -0x78D4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X78D4);
    // 0x800BB5A8: lw          $a2, -0x78D8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X78D8);
    // 0x800BB5AC: lw          $a1, -0x7CF8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CF8);
    // 0x800BB5B0: jal         0x800C2AF0
    // 0x800BB5B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Message_DisplayText(rdram, ctx);
        goto after_3;
    // 0x800BB5B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_3:
    // 0x800BB5B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800BB5BC: sw          $v0, -0x7D08($at)
    MEM_W(-0X7D08, ctx->r1) = ctx->r2;
    // 0x800BB5C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BB5C4:
    // 0x800BB5C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800BB5C8: jr          $ra
    // 0x800BB5CC: nop

    return;
    // 0x800BB5CC: nop

;}
RECOMP_FUNC void ActorAllRange_ChooseNewTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FB4C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002FB50: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8002FB54: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8002FB58: addiu       $t3, $t3, 0x42D4
    ctx->r11 = ADD32(ctx->r11, 0X42D4);
    // 0x8002FB5C: addiu       $v1, $v1, 0x5D68
    ctx->r3 = ADD32(ctx->r3, 0X5D68);
    // 0x8002FB60: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8002FB64: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8002FB68: addiu       $t2, $zero, 0xC5
    ctx->r10 = ADD32(0, 0XC5);
    // 0x8002FB6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
L_8002FB70:
    // 0x8002FB70: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8002FB74: bnel        $t1, $t6, L_8002FBEC
    if (ctx->r9 != ctx->r14) {
        // 0x8002FB78: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8002FBEC;
    }
    goto skip_0;
    // 0x8002FB78: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x8002FB7C: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    // 0x8002FB80: bnel        $t2, $t7, L_8002FBEC
    if (ctx->r10 != ctx->r15) {
        // 0x8002FB84: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8002FBEC;
    }
    goto skip_1;
    // 0x8002FB84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x8002FB88: lh          $t8, 0xB6($v1)
    ctx->r24 = MEM_H(ctx->r3, 0XB6);
    // 0x8002FB8C: bnel        $t8, $zero, L_8002FBEC
    if (ctx->r24 != 0) {
        // 0x8002FB90: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8002FBEC;
    }
    goto skip_2;
    // 0x8002FB90: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8002FB94: lh          $t9, 0xE6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0XE6);
    // 0x8002FB98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002FB9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8002FBA0: bgez        $t9, L_8002FBE8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8002FBA4: or          $a2, $t3, $zero
        ctx->r6 = ctx->r11 | 0;
            goto L_8002FBE8;
    }
    // 0x8002FBA4: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x8002FBA8: lw          $t0, 0x40($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X40);
L_8002FBAC:
    // 0x8002FBAC: beql        $a1, $t0, L_8002FBC8
    if (ctx->r5 == ctx->r8) {
        // 0x8002FBB0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8002FBC8;
    }
    goto skip_3;
    // 0x8002FBB0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_3:
    // 0x8002FBB4: lh          $t5, 0xE6($a2)
    ctx->r13 = MEM_H(ctx->r6, 0XE6);
    // 0x8002FBB8: bnel        $v0, $t5, L_8002FBC8
    if (ctx->r2 != ctx->r13) {
        // 0x8002FBBC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8002FBC8;
    }
    goto skip_4;
    // 0x8002FBBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_4:
    // 0x8002FBC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002FBC4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_8002FBC8:
    // 0x8002FBC8: bne         $a1, $t4, L_8002FBAC
    if (ctx->r5 != ctx->r12) {
        // 0x8002FBCC: addiu       $a2, $a2, 0x2F4
        ctx->r6 = ADD32(ctx->r6, 0X2F4);
            goto L_8002FBAC;
    }
    // 0x8002FBCC: addiu       $a2, $a2, 0x2F4
    ctx->r6 = ADD32(ctx->r6, 0X2F4);
    // 0x8002FBD0: bnel        $a0, $zero, L_8002FBEC
    if (ctx->r4 != 0) {
        // 0x8002FBD4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8002FBEC;
    }
    goto skip_5;
    // 0x8002FBD4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_5:
    // 0x8002FBD8: sh          $v0, 0xE6($a3)
    MEM_H(0XE6, ctx->r7) = ctx->r2;
    // 0x8002FBDC: sh          $t1, 0xB8($a3)
    MEM_H(0XB8, ctx->r7) = ctx->r9;
    // 0x8002FBE0: jr          $ra
    // 0x8002FBE4: sw          $zero, 0x58($a3)
    MEM_W(0X58, ctx->r7) = 0;
    return;
    // 0x8002FBE4: sw          $zero, 0x58($a3)
    MEM_W(0X58, ctx->r7) = 0;
L_8002FBE8:
    // 0x8002FBE8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8002FBEC:
    // 0x8002FBEC: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x8002FBF0: bne         $at, $zero, L_8002FB70
    if (ctx->r1 != 0) {
        // 0x8002FBF4: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_8002FB70;
    }
    // 0x8002FBF4: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
    // 0x8002FBF8: jr          $ra
    // 0x8002FBFC: nop

    return;
    // 0x8002FBFC: nop

;}
RECOMP_FUNC void PlayerShot_DrawLaser(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039210: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80039214: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80039218: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003921C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80039220: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80039224: lw          $t7, 0x78A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A8);
    // 0x80039228: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x8003922C: addiu       $t6, $t6, -0x5130
    ctx->r14 = ADD32(ctx->r14, -0X5130);
    // 0x80039230: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80039234: beq         $at, $zero, L_80039834
    if (ctx->r1 == 0) {
        // 0x80039238: sw          $t6, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->r14;
            goto L_80039834;
    }
    // 0x80039238: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x8003923C: jal         0x800B9760
    // 0x80039240: nop

    RCP_SetupDL_21(rdram, ctx);
        goto after_0;
    // 0x80039240: nop

    after_0:
    // 0x80039244: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80039248: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8003924C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80039250: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
    // 0x80039254: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80039258: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8003925C: beq         $v0, $zero, L_8003928C
    if (ctx->r2 == 0) {
        // 0x80039260: lui         $v1, 0x8016
        ctx->r3 = S32(0X8016 << 16);
            goto L_8003928C;
    }
    // 0x80039260: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80039264: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x80039268: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003926C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80039270: bnel        $t0, $a0, L_800392B0
    if (ctx->r8 != ctx->r4) {
        // 0x80039274: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800392B0;
    }
    goto skip_0;
    // 0x80039274: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_0:
    // 0x80039278: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8003927C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80039280: lw          $t9, 0x1C8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C8);
    // 0x80039284: bnel        $a3, $t9, L_800392B0
    if (ctx->r7 != ctx->r25) {
        // 0x80039288: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800392B0;
    }
    goto skip_1;
    // 0x80039288: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_1:
L_8003928C:
    // 0x8003928C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80039290: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80039294: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80039298: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003929C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800392A0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800392A4: b           L_800392C0
    // 0x800392A8: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
        goto L_800392C0;
    // 0x800392A8: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x800392AC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_800392B0:
    // 0x800392B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800392B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800392B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800392BC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_800392C0:
    // 0x800392C0: lw          $v1, 0x1AA8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1AA8);
    // 0x800392C4: blezl       $v1, L_800393DC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800392C8: addiu       $v1, $zero, 0x10
        ctx->r3 = ADD32(0, 0X10);
            goto L_800393DC;
    }
    goto skip_2;
    // 0x800392C8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    skip_2:
    // 0x800392CC: bne         $v0, $zero, L_800393D8
    if (ctx->r2 != 0) {
        // 0x800392D0: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_800393D8;
    }
    // 0x800392D0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800392D4: beq         $v1, $t0, L_800392EC
    if (ctx->r3 == ctx->r8) {
        // 0x800392D8: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_800392EC;
    }
    // 0x800392D8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800392DC: bne         $v1, $a3, L_800392EC
    if (ctx->r3 != ctx->r7) {
        // 0x800392E0: lui         $t1, 0x102
        ctx->r9 = S32(0X102 << 16);
            goto L_800392EC;
    }
    // 0x800392E0: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x800392E4: addiu       $t1, $t1, -0x52E0
    ctx->r9 = ADD32(ctx->r9, -0X52E0);
    // 0x800392E8: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
L_800392EC:
    // 0x800392EC: bne         $a0, $at, L_800392FC
    if (ctx->r4 != ctx->r1) {
        // 0x800392F0: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800392FC;
    }
    // 0x800392F0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800392F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800392F8: nop

L_800392FC:
    // 0x800392FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039300: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80039304: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80039308: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8003930C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039310: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80039314: jal         0x80005C34
    // 0x80039318: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80039318: swc1        $f12, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8003931C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039320: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80039324: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80039328: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8003932C: jal         0x80005E90
    // 0x80039330: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80039330: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80039334: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039338: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003933C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80039340: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039344: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80039348: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003934C: jal         0x80005B00
    // 0x80039350: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80039350: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x80039354: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80039358: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003935C: jal         0x80006EB8
    // 0x80039360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80039360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80039364: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039368: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8003936C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80039370: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80039374: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80039378: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003937C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80039380: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80039384: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80039388: add.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f4.fl;
    // 0x8003938C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039390: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80039394: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80039398: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003939C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800393A0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800393A4: jal         0x80005B00
    // 0x800393A8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x800393A8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x800393AC: jal         0x80006EB8
    // 0x800393B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x800393B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800393B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800393B8: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800393BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800393C0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800393C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800393C8: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x800393CC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800393D0: b           L_80039A40
    // 0x800393D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039A40;
    // 0x800393D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800393D8:
    // 0x800393D8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_800393DC:
    // 0x800393DC: beq         $v1, $a0, L_8003945C
    if (ctx->r3 == ctx->r4) {
        // 0x800393E0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003945C;
    }
    // 0x800393E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800393E4: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x800393E8: slti        $at, $v0, 0x68
    ctx->r1 = SIGNED(ctx->r2) < 0X68 ? 1 : 0;
    // 0x800393EC: bne         $at, $zero, L_8003945C
    if (ctx->r1 != 0) {
        // 0x800393F0: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_8003945C;
    }
    // 0x800393F0: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800393F4: beq         $v0, $at, L_8003945C
    if (ctx->r2 == ctx->r1) {
        // 0x800393F8: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_8003945C;
    }
    // 0x800393F8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800393FC: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80039400: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80039404: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x80039408: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003940C: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80039410: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x80039414: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x80039418: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8003941C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80039420: addiu       $t4, $t4, 0x3FE0
    ctx->r12 = ADD32(ctx->r12, 0X3FE0);
    // 0x80039424: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x80039428: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8003942C: lhu         $t5, 0x58B2($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X58B2);
    // 0x80039430: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80039434: beql        $t5, $at, L_80039448
    if (ctx->r13 == ctx->r1) {
        // 0x80039438: lw          $t6, 0x5930($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X5930);
            goto L_80039448;
    }
    goto skip_3;
    // 0x80039438: lw          $t6, 0x5930($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X5930);
    skip_3:
    // 0x8003943C: b           L_800394F8
    // 0x80039440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800394F8;
    // 0x80039440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80039444: lw          $t6, 0x5930($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X5930);
L_80039448:
    // 0x80039448: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003944C: bne         $t6, $at, L_800394F8
    if (ctx->r14 != ctx->r1) {
        // 0x80039450: nop
    
            goto L_800394F8;
    }
    // 0x80039450: nop

    // 0x80039454: b           L_800394F8
    // 0x80039458: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_800394F8;
    // 0x80039458: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8003945C:
    // 0x8003945C: bne         $v1, $a0, L_800394F8
    if (ctx->r3 != ctx->r4) {
        // 0x80039460: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_800394F8;
    }
    // 0x80039460: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80039464: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80039468: lw          $v0, 0x68($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X68);
    // 0x8003946C: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x80039470: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x80039474: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80039478: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x8003947C: beq         $a3, $t8, L_800394D0
    if (ctx->r7 == ctx->r24) {
        // 0x80039480: sll         $t1, $t1, 4
        ctx->r9 = S32(ctx->r9 << 4);
            goto L_800394D0;
    }
    // 0x80039480: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80039484: slti        $at, $v0, 0x68
    ctx->r1 = SIGNED(ctx->r2) < 0X68 ? 1 : 0;
    // 0x80039488: bne         $at, $zero, L_800394F8
    if (ctx->r1 != 0) {
        // 0x8003948C: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_800394F8;
    }
    // 0x8003948C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80039490: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x80039494: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80039498: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8003949C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800394A0: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x800394A4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800394A8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800394AC: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x800394B0: lh          $v1, 0x1946($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X1946);
    // 0x800394B4: bne         $v1, $zero, L_800394C0
    if (ctx->r3 != 0) {
        // 0x800394B8: nop
    
            goto L_800394C0;
    }
    // 0x800394B8: nop

    // 0x800394BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800394C0:
    // 0x800394C0: bne         $a3, $v1, L_800394F8
    if (ctx->r7 != ctx->r3) {
        // 0x800394C4: nop
    
            goto L_800394F8;
    }
    // 0x800394C4: nop

    // 0x800394C8: b           L_800394F8
    // 0x800394CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_800394F8;
    // 0x800394CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_800394D0:
    // 0x800394D0: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x800394D4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800394D8: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x800394DC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800394E0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800394E4: lh          $t2, 0x1946($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X1946);
    // 0x800394E8: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x800394EC: bne         $t2, $at, L_800394F8
    if (ctx->r10 != ctx->r1) {
        // 0x800394F0: nop
    
            goto L_800394F8;
    }
    // 0x800394F0: nop

    // 0x800394F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800394F8:
    // 0x800394F8: beq         $a1, $zero, L_80039520
    if (ctx->r5 == 0) {
        // 0x800394FC: nop
    
            goto L_80039520;
    }
    // 0x800394FC: nop

    // 0x80039500: beq         $a1, $t0, L_80039590
    if (ctx->r5 == ctx->r8) {
        // 0x80039504: nop
    
            goto L_80039590;
    }
    // 0x80039504: nop

    // 0x80039508: beq         $a1, $a3, L_80039624
    if (ctx->r5 == ctx->r7) {
        // 0x8003950C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80039624;
    }
    // 0x8003950C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80039510: beq         $a1, $at, L_800396FC
    if (ctx->r5 == ctx->r1) {
        // 0x80039514: nop
    
            goto L_800396FC;
    }
    // 0x80039514: nop

    // 0x80039518: b           L_80039A40
    // 0x8003951C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039A40;
    // 0x8003951C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039520:
    // 0x80039520: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039524: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80039528: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003952C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80039530: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80039534: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80039538: jal         0x80005C34
    // 0x8003953C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x8003953C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_7:
    // 0x80039540: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039544: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80039548: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8003954C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039550: jal         0x80005E90
    // 0x80039554: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x80039554: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_8:
    // 0x80039558: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003955C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80039560: jal         0x80006EB8
    // 0x80039564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x80039564: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80039568: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003956C: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x80039570: addiu       $t6, $t6, -0x5130
    ctx->r14 = ADD32(ctx->r14, -0X5130);
    // 0x80039574: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80039578: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003957C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80039580: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80039584: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80039588: b           L_80039A40
    // 0x8003958C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039A40;
    // 0x8003958C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039590:
    // 0x80039590: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039594: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80039598: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003959C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800395A0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800395A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800395A8: jal         0x80005B00
    // 0x800395AC: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x800395AC: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_10:
    // 0x800395B0: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x800395B4: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x800395B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800395BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800395C0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800395C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800395C8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800395CC: jal         0x80005C34
    // 0x800395D0: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x800395D0: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_11:
    // 0x800395D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800395D8: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x800395DC: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x800395E0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800395E4: jal         0x80005E90
    // 0x800395E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x800395E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x800395EC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800395F0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800395F4: jal         0x80006EB8
    // 0x800395F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_13;
    // 0x800395F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800395FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039600: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x80039604: addiu       $t2, $t2, -0x5430
    ctx->r10 = ADD32(ctx->r10, -0X5430);
    // 0x80039608: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003960C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80039610: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80039614: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80039618: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8003961C: b           L_80039A40
    // 0x80039620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039A40;
    // 0x80039620: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039624:
    // 0x80039624: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039628: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003962C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80039630: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80039634: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80039638: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003963C: jal         0x80005C34
    // 0x80039640: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_14;
    // 0x80039640: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_14:
    // 0x80039644: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039648: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x8003964C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80039650: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039654: jal         0x80005E90
    // 0x80039658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_15;
    // 0x80039658: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_15:
    // 0x8003965C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039660: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80039664: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80039668: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8003966C: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    // 0x80039670: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80039674: jal         0x80005B00
    // 0x80039678: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x80039678: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_16:
    // 0x8003967C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80039680: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80039684: jal         0x80006EB8
    // 0x80039688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_17;
    // 0x80039688: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8003968C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039690: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x80039694: addiu       $t7, $t7, -0x5130
    ctx->r15 = ADD32(ctx->r15, -0X5130);
    // 0x80039698: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8003969C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800396A0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x800396A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800396A8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800396AC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800396B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800396B4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800396B8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800396BC: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    // 0x800396C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800396C4: jal         0x80005B00
    // 0x800396C8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_18;
    // 0x800396C8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_18:
    // 0x800396CC: jal         0x80006EB8
    // 0x800396D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x800396D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800396D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800396D8: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x800396DC: addiu       $t2, $t2, -0x5130
    ctx->r10 = ADD32(ctx->r10, -0X5130);
    // 0x800396E0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800396E4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800396E8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800396EC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800396F0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800396F4: b           L_80039A40
    // 0x800396F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039A40;
    // 0x800396F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800396FC:
    // 0x800396FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039700: jal         0x80005708
    // 0x80039704: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_20;
    // 0x80039704: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_20:
    // 0x80039708: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003970C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80039710: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80039714: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039718: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x8003971C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80039720: jal         0x80005B00
    // 0x80039724: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_21;
    // 0x80039724: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_21:
    // 0x80039728: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003972C: lwc1        $f0, 0x5280($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5280);
    // 0x80039730: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039734: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80039738: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003973C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80039740: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80039744: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039748: jal         0x80005C34
    // 0x8003974C: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_22;
    // 0x8003974C: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_22:
    // 0x80039750: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039754: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80039758: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8003975C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039760: jal         0x80005E90
    // 0x80039764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_23;
    // 0x80039764: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_23:
    // 0x80039768: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003976C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80039770: jal         0x80006EB8
    // 0x80039774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_24;
    // 0x80039774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x80039778: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8003977C: lui         $a1, 0x102
    ctx->r5 = S32(0X102 << 16);
    // 0x80039780: addiu       $a1, $a1, -0x5430
    ctx->r5 = ADD32(ctx->r5, -0X5430);
    // 0x80039784: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80039788: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003978C: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80039790: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80039794: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80039798: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003979C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    // 0x800397A0: jal         0x80005740
    // 0x800397A4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    Matrix_Pop(rdram, ctx);
        goto after_25;
    // 0x800397A4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_25:
    // 0x800397A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800397AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800397B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800397B4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800397B8: lui         $a1, 0xC248
    ctx->r5 = S32(0XC248 << 16);
    // 0x800397BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800397C0: jal         0x80005B00
    // 0x800397C4: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_26;
    // 0x800397C4: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    after_26:
    // 0x800397C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800397CC: lwc1        $f0, 0x5284($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5284);
    // 0x800397D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800397D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800397D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800397DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800397E0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800397E4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800397E8: jal         0x80005C34
    // 0x800397EC: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_27;
    // 0x800397EC: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    after_27:
    // 0x800397F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800397F4: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x800397F8: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x800397FC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039800: jal         0x80005E90
    // 0x80039804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_28;
    // 0x80039804: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_28:
    // 0x80039808: jal         0x80006EB8
    // 0x8003980C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_29;
    // 0x8003980C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80039810: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039814: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80039818: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003981C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80039820: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80039824: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80039828: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8003982C: b           L_80039A40
    // 0x80039830: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039A40;
    // 0x80039830: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039834:
    // 0x80039834: jal         0x800BA140
    // 0x80039838: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_30;
    // 0x80039838: nop

    after_30:
    // 0x8003983C: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x80039840: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80039844: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80039848: lw          $v0, 0x68($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X68);
    // 0x8003984C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039850: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x80039854: beq         $v0, $zero, L_8003988C
    if (ctx->r2 == 0) {
        // 0x80039858: lui         $a2, 0x4080
        ctx->r6 = S32(0X4080 << 16);
            goto L_8003988C;
    }
    // 0x80039858: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8003985C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80039860: beq         $v0, $t0, L_800398B4
    if (ctx->r2 == ctx->r8) {
        // 0x80039864: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800398B4;
    }
    // 0x80039864: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80039868: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8003986C: beq         $v0, $a3, L_800398E0
    if (ctx->r2 == ctx->r7) {
        // 0x80039870: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800398E0;
    }
    // 0x80039870: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80039874: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80039878: beq         $v0, $at, L_8003990C
    if (ctx->r2 == ctx->r1) {
        // 0x8003987C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8003990C;
    }
    // 0x8003987C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80039880: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80039884: b           L_80039930
    // 0x80039888: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
        goto L_80039930;
    // 0x80039888: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
L_8003988C:
    // 0x8003988C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039890: lui         $t6, 0xFFFF
    ctx->r14 = S32(0XFFFF << 16);
    // 0x80039894: ori         $t6, $t6, 0x20FF
    ctx->r14 = ctx->r14 | 0X20FF;
    // 0x80039898: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8003989C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800398A0: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800398A4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800398A8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800398AC: b           L_80039934
    // 0x800398B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
        goto L_80039934;
    // 0x800398B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_800398B4:
    // 0x800398B4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800398B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800398BC: lui         $t9, 0xFF64
    ctx->r25 = S32(0XFF64 << 16);
    // 0x800398C0: ori         $t9, $t9, 0xC8FF
    ctx->r25 = ctx->r25 | 0XC8FF;
    // 0x800398C4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800398C8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800398CC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800398D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800398D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800398D8: b           L_80039934
    // 0x800398DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
        goto L_80039934;
    // 0x800398DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_800398E0:
    // 0x800398E0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800398E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800398E8: lui         $t3, 0x20FF
    ctx->r11 = S32(0X20FF << 16);
    // 0x800398EC: ori         $t3, $t3, 0x20FF
    ctx->r11 = ctx->r11 | 0X20FF;
    // 0x800398F0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800398F4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800398F8: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800398FC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80039900: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80039904: b           L_80039934
    // 0x80039908: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
        goto L_80039934;
    // 0x80039908: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_8003990C:
    // 0x8003990C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80039910: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039914: lui         $t6, 0x2020
    ctx->r14 = S32(0X2020 << 16);
    // 0x80039918: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8003991C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80039920: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80039924: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80039928: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003992C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80039930:
    // 0x80039930: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80039934:
    // 0x80039934: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80039938: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8003993C: jal         0x80005C34
    // 0x80039940: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_31;
    // 0x80039940: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_31:
    // 0x80039944: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039948: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x8003994C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80039950: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80039954: jal         0x80005E90
    // 0x80039958: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_32;
    // 0x80039958: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_32:
    // 0x8003995C: jal         0x80006EB8
    // 0x80039960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_33;
    // 0x80039960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80039964: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x80039968: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8003996C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80039970: lw          $t9, 0x68($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X68);
    // 0x80039974: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x80039978: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003997C: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80039980: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80039984: lw          $t2, 0x1AA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1AA8);
    // 0x80039988: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8003998C: lui         $t3, 0x303
    ctx->r11 = S32(0X303 << 16);
    // 0x80039990: beql        $t2, $zero, L_80039A24
    if (ctx->r10 == 0) {
        // 0x80039994: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80039A24;
    }
    goto skip_4;
    // 0x80039994: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x80039998: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003999C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800399A0: jal         0x80005B00
    // 0x800399A4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_34;
    // 0x800399A4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_34:
    // 0x800399A8: jal         0x80006EB8
    // 0x800399AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_35;
    // 0x800399AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x800399B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800399B4: lui         $t0, 0x303
    ctx->r8 = S32(0X303 << 16);
    // 0x800399B8: addiu       $t0, $t0, -0x2EE0
    ctx->r8 = ADD32(ctx->r8, -0X2EE0);
    // 0x800399BC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800399C0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800399C4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800399C8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800399CC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800399D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800399D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800399D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800399DC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x800399E0: lui         $a1, 0xC140
    ctx->r5 = S32(0XC140 << 16);
    // 0x800399E4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800399E8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800399EC: jal         0x80005B00
    // 0x800399F0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    Matrix_Translate(rdram, ctx);
        goto after_36;
    // 0x800399F0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_36:
    // 0x800399F4: jal         0x80006EB8
    // 0x800399F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_37;
    // 0x800399F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x800399FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80039A00: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80039A04: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80039A08: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80039A0C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80039A10: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80039A14: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80039A18: b           L_80039A40
    // 0x80039A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80039A40;
    // 0x80039A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80039A20: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80039A24:
    // 0x80039A24: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80039A28: addiu       $t3, $t3, -0x2EE0
    ctx->r11 = ADD32(ctx->r11, -0X2EE0);
    // 0x80039A2C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80039A30: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80039A34: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80039A38: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80039A3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80039A40:
    // 0x80039A40: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80039A44: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80039A48: jr          $ra
    // 0x80039A4C: nop

    return;
    // 0x80039A4C: nop

;}
RECOMP_FUNC void RCP_SetupDL_61(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA640: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BA644: addiu       $t3, $t3, 0x7E64
    ctx->r11 = ADD32(ctx->r11, 0X7E64);
    // 0x800BA648: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800BA64C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA650: addiu       $t8, $t8, 0x42D8
    ctx->r24 = ADD32(ctx->r24, 0X42D8);
    // 0x800BA654: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BA658: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x800BA65C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA660: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800BA664: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800BA668: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800BA66C: lui         $t4, 0xF800
    ctx->r12 = S32(0XF800 << 16);
    // 0x800BA670: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800BA674: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800BA678: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x800BA67C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800BA680: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800BA684: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800BA688: andi        $t4, $a2, 0xFF
    ctx->r12 = ctx->r6 & 0XFF;
    // 0x800BA68C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800BA690: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800BA694: or          $t7, $t9, $t5
    ctx->r15 = ctx->r25 | ctx->r13;
    // 0x800BA698: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x800BA69C: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800BA6A0: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800BA6A4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x800BA6A8: lui         $t9, 0xBC00
    ctx->r25 = S32(0XBC00 << 16);
    // 0x800BA6AC: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800BA6B0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x800BA6B4: sw          $t4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r12;
    // 0x800BA6B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BA6BC: lw          $t7, 0x10($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10);
    // 0x800BA6C0: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x800BA6C4: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800BA6C8: ori         $t6, $t6, 0xF400
    ctx->r14 = ctx->r14 | 0XF400;
    // 0x800BA6CC: subu        $t2, $t5, $t7
    ctx->r10 = SUB32(ctx->r13, ctx->r15);
    // 0x800BA6D0: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800BA6D4: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800BA6D8: mflo        $t4
    ctx->r12 = lo;
    // 0x800BA6DC: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x800BA6E0: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800BA6E4: bne         $t2, $zero, L_800BA6F0
    if (ctx->r10 != 0) {
        // 0x800BA6E8: nop
    
            goto L_800BA6F0;
    }
    // 0x800BA6E8: nop

    // 0x800BA6EC: break       7
    do_break(2148247276);
L_800BA6F0:
    // 0x800BA6F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA6F4: bne         $t2, $at, L_800BA708
    if (ctx->r10 != ctx->r1) {
        // 0x800BA6F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BA708;
    }
    // 0x800BA6F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA6FC: bne         $t6, $at, L_800BA708
    if (ctx->r14 != ctx->r1) {
        // 0x800BA700: nop
    
            goto L_800BA708;
    }
    // 0x800BA700: nop

    // 0x800BA704: break       6
    do_break(2148247300);
L_800BA708:
    // 0x800BA708: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800BA70C: ori         $at, $at, 0xF400
    ctx->r1 = ctx->r1 | 0XF400;
    // 0x800BA710: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800BA714: addu        $t8, $t6, $at
    ctx->r24 = ADD32(ctx->r14, ctx->r1);
    // 0x800BA718: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800BA71C: mflo        $t4
    ctx->r12 = lo;
    // 0x800BA720: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800BA724: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x800BA728: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BA72C: bne         $t2, $zero, L_800BA738
    if (ctx->r10 != 0) {
        // 0x800BA730: nop
    
            goto L_800BA738;
    }
    // 0x800BA730: nop

    // 0x800BA734: break       7
    do_break(2148247348);
L_800BA738:
    // 0x800BA738: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BA73C: bne         $t2, $at, L_800BA750
    if (ctx->r10 != ctx->r1) {
        // 0x800BA740: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BA750;
    }
    // 0x800BA740: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA744: bne         $t8, $at, L_800BA750
    if (ctx->r24 != ctx->r1) {
        // 0x800BA748: nop
    
            goto L_800BA750;
    }
    // 0x800BA748: nop

    // 0x800BA74C: break       6
    do_break(2148247372);
L_800BA750:
    // 0x800BA750: jr          $ra
    // 0x800BA754: nop

    return;
    // 0x800BA754: nop

;}
RECOMP_FUNC void HUD_DrawLevelClearScreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086DCC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80086DD0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80086DD4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80086DD8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80086DDC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80086DE0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80086DE4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80086DE8: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x80086DEC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80086DF0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80086DF4: beq         $t6, $at, L_80086E10
    if (ctx->r14 == ctx->r1) {
        // 0x80086DF8: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_80086E10;
    }
    // 0x80086DF8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80086DFC: addiu       $v0, $v0, 0x7840
    ctx->r2 = ADD32(ctx->r2, 0X7840);
    // 0x80086E00: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80086E04: beq         $v1, $zero, L_80086E10
    if (ctx->r3 == 0) {
        // 0x80086E08: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_80086E10;
    }
    // 0x80086E08: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x80086E0C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80086E10:
    // 0x80086E10: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80086E14: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80086E18: lbu         $t8, 0x7930($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7930);
    // 0x80086E1C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80086E20: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80086E24: lw          $v1, 0x7840($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7840);
    // 0x80086E28: beq         $v0, $at, L_80086E60
    if (ctx->r2 == ctx->r1) {
        // 0x80086E2C: sw          $t8, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r24;
            goto L_80086E60;
    }
    // 0x80086E2C: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80086E30: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x80086E34: beq         $v0, $at, L_80086E60
    if (ctx->r2 == ctx->r1) {
        // 0x80086E38: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80086E60;
    }
    // 0x80086E38: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80086E3C: beq         $v0, $at, L_80086E60
    if (ctx->r2 == ctx->r1) {
        // 0x80086E40: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_80086E60;
    }
    // 0x80086E40: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x80086E44: beq         $v0, $at, L_80086E60
    if (ctx->r2 == ctx->r1) {
        // 0x80086E48: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80086E60;
    }
    // 0x80086E48: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80086E4C: beq         $v0, $at, L_80086E60
    if (ctx->r2 == ctx->r1) {
        // 0x80086E50: addiu       $s1, $zero, 0xD
        ctx->r17 = ADD32(0, 0XD);
            goto L_80086E60;
    }
    // 0x80086E50: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
    // 0x80086E54: beq         $s1, $v0, L_80086E60
    if (ctx->r17 == ctx->r2) {
        // 0x80086E58: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086E60;
    }
    // 0x80086E58: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086E5C: bne         $v0, $at, L_80086E6C
    if (ctx->r2 != ctx->r1) {
        // 0x80086E60: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80086E6C;
    }
L_80086E60:
    // 0x80086E60: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80086E64: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
    // 0x80086E68: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_80086E6C:
    // 0x80086E6C: bne         $s1, $v0, L_80086F28
    if (ctx->r17 != ctx->r2) {
        // 0x80086E70: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80086F28;
    }
    // 0x80086E70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80086E74: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80086E78: beql        $at, $zero, L_80086E88
    if (ctx->r1 == 0) {
        // 0x80086E7C: slti        $at, $v1, 0x61
        ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
            goto L_80086E88;
    }
    goto skip_0;
    // 0x80086E7C: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    skip_0:
    // 0x80086E80: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80086E84: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
L_80086E88:
    // 0x80086E88: beql        $at, $zero, L_80086E98
    if (ctx->r1 == 0) {
        // 0x80086E8C: slti        $at, $v1, 0x5D
        ctx->r1 = SIGNED(ctx->r3) < 0X5D ? 1 : 0;
            goto L_80086E98;
    }
    goto skip_1;
    // 0x80086E8C: slti        $at, $v1, 0x5D
    ctx->r1 = SIGNED(ctx->r3) < 0X5D ? 1 : 0;
    skip_1:
    // 0x80086E90: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80086E94: slti        $at, $v1, 0x5D
    ctx->r1 = SIGNED(ctx->r3) < 0X5D ? 1 : 0;
L_80086E98:
    // 0x80086E98: beql        $at, $zero, L_80086EA8
    if (ctx->r1 == 0) {
        // 0x80086E9C: slti        $at, $v1, 0x58
        ctx->r1 = SIGNED(ctx->r3) < 0X58 ? 1 : 0;
            goto L_80086EA8;
    }
    goto skip_2;
    // 0x80086E9C: slti        $at, $v1, 0x58
    ctx->r1 = SIGNED(ctx->r3) < 0X58 ? 1 : 0;
    skip_2:
    // 0x80086EA0: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80086EA4: slti        $at, $v1, 0x58
    ctx->r1 = SIGNED(ctx->r3) < 0X58 ? 1 : 0;
L_80086EA8:
    // 0x80086EA8: beq         $at, $zero, L_80086EB4
    if (ctx->r1 == 0) {
        // 0x80086EAC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80086EB4;
    }
    // 0x80086EAC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80086EB0: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80086EB4:
    // 0x80086EB4: slti        $at, $v1, 0x53
    ctx->r1 = SIGNED(ctx->r3) < 0X53 ? 1 : 0;
    // 0x80086EB8: beq         $at, $zero, L_80086EC4
    if (ctx->r1 == 0) {
        // 0x80086EBC: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_80086EC4;
    }
    // 0x80086EBC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80086EC0: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
L_80086EC4:
    // 0x80086EC4: slti        $at, $v1, 0x4E
    ctx->r1 = SIGNED(ctx->r3) < 0X4E ? 1 : 0;
    // 0x80086EC8: beq         $at, $zero, L_80086ED4
    if (ctx->r1 == 0) {
        // 0x80086ECC: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_80086ED4;
    }
    // 0x80086ECC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80086ED0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80086ED4:
    // 0x80086ED4: bne         $v1, $zero, L_80086EE0
    if (ctx->r3 != 0) {
        // 0x80086ED8: addiu       $at, $zero, 0x5C
        ctx->r1 = ADD32(0, 0X5C);
            goto L_80086EE0;
    }
    // 0x80086ED8: addiu       $at, $zero, 0x5C
    ctx->r1 = ADD32(0, 0X5C);
    // 0x80086EDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80086EE0:
    // 0x80086EE0: beq         $v1, $at, L_80086F00
    if (ctx->r3 == ctx->r1) {
        // 0x80086EE4: ori         $a0, $a0, 0x8031
        ctx->r4 = ctx->r4 | 0X8031;
            goto L_80086F00;
    }
    // 0x80086EE4: ori         $a0, $a0, 0x8031
    ctx->r4 = ctx->r4 | 0X8031;
    // 0x80086EE8: addiu       $at, $zero, 0x57
    ctx->r1 = ADD32(0, 0X57);
    // 0x80086EEC: beq         $v1, $at, L_80086F00
    if (ctx->r3 == ctx->r1) {
        // 0x80086EF0: addiu       $at, $zero, 0x52
        ctx->r1 = ADD32(0, 0X52);
            goto L_80086F00;
    }
    // 0x80086EF0: addiu       $at, $zero, 0x52
    ctx->r1 = ADD32(0, 0X52);
    // 0x80086EF4: beq         $v1, $at, L_80086F00
    if (ctx->r3 == ctx->r1) {
        // 0x80086EF8: addiu       $at, $zero, 0x4D
        ctx->r1 = ADD32(0, 0X4D);
            goto L_80086F00;
    }
    // 0x80086EF8: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x80086EFC: bne         $v1, $at, L_80087020
    if (ctx->r3 != ctx->r1) {
        // 0x80086F00: lui         $t0, 0x800C
        ctx->r8 = S32(0X800C << 16);
            goto L_80087020;
    }
L_80086F00:
    // 0x80086F00: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80086F04: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80086F08: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80086F0C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80086F10: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80086F14: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80086F18: jal         0x80019218
    // 0x80086F1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80086F1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x80086F20: b           L_80087020
    // 0x80086F24: nop

        goto L_80087020;
    // 0x80086F24: nop

L_80086F28:
    // 0x80086F28: slti        $at, $v1, 0x65
    ctx->r1 = SIGNED(ctx->r3) < 0X65 ? 1 : 0;
    // 0x80086F2C: beql        $at, $zero, L_80086F3C
    if (ctx->r1 == 0) {
        // 0x80086F30: slti        $at, $v1, 0x5B
        ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
            goto L_80086F3C;
    }
    goto skip_3;
    // 0x80086F30: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
    skip_3:
    // 0x80086F34: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80086F38: slti        $at, $v1, 0x5B
    ctx->r1 = SIGNED(ctx->r3) < 0X5B ? 1 : 0;
L_80086F3C:
    // 0x80086F3C: beql        $at, $zero, L_80086F4C
    if (ctx->r1 == 0) {
        // 0x80086F40: slti        $at, $v1, 0x51
        ctx->r1 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
            goto L_80086F4C;
    }
    goto skip_4;
    // 0x80086F40: slti        $at, $v1, 0x51
    ctx->r1 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
    skip_4:
    // 0x80086F44: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80086F48: slti        $at, $v1, 0x51
    ctx->r1 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
L_80086F4C:
    // 0x80086F4C: beql        $at, $zero, L_80086F5C
    if (ctx->r1 == 0) {
        // 0x80086F50: slti        $at, $v1, 0x49
        ctx->r1 = SIGNED(ctx->r3) < 0X49 ? 1 : 0;
            goto L_80086F5C;
    }
    goto skip_5;
    // 0x80086F50: slti        $at, $v1, 0x49
    ctx->r1 = SIGNED(ctx->r3) < 0X49 ? 1 : 0;
    skip_5:
    // 0x80086F54: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
    // 0x80086F58: slti        $at, $v1, 0x49
    ctx->r1 = SIGNED(ctx->r3) < 0X49 ? 1 : 0;
L_80086F5C:
    // 0x80086F5C: beq         $at, $zero, L_80086F68
    if (ctx->r1 == 0) {
        // 0x80086F60: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_80086F68;
    }
    // 0x80086F60: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80086F64: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_80086F68:
    // 0x80086F68: slti        $at, $v1, 0x41
    ctx->r1 = SIGNED(ctx->r3) < 0X41 ? 1 : 0;
    // 0x80086F6C: beql        $at, $zero, L_80086F7C
    if (ctx->r1 == 0) {
        // 0x80086F70: slti        $at, $v1, 0x39
        ctx->r1 = SIGNED(ctx->r3) < 0X39 ? 1 : 0;
            goto L_80086F7C;
    }
    goto skip_6;
    // 0x80086F70: slti        $at, $v1, 0x39
    ctx->r1 = SIGNED(ctx->r3) < 0X39 ? 1 : 0;
    skip_6:
    // 0x80086F74: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x80086F78: slti        $at, $v1, 0x39
    ctx->r1 = SIGNED(ctx->r3) < 0X39 ? 1 : 0;
L_80086F7C:
    // 0x80086F7C: beq         $at, $zero, L_80086F88
    if (ctx->r1 == 0) {
        // 0x80086F80: nop
    
            goto L_80086F88;
    }
    // 0x80086F80: nop

    // 0x80086F84: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80086F88:
    // 0x80086F88: bne         $v1, $zero, L_80086F94
    if (ctx->r3 != 0) {
        // 0x80086F8C: addiu       $at, $zero, 0x50
        ctx->r1 = ADD32(0, 0X50);
            goto L_80086F94;
    }
    // 0x80086F8C: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80086F90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80086F94:
    // 0x80086F94: beq         $v1, $at, L_80086FB4
    if (ctx->r3 == ctx->r1) {
        // 0x80086F98: addiu       $at, $zero, 0x48
        ctx->r1 = ADD32(0, 0X48);
            goto L_80086FB4;
    }
    // 0x80086F98: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x80086F9C: beq         $v1, $at, L_80086FB4
    if (ctx->r3 == ctx->r1) {
        // 0x80086FA0: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_80086FB4;
    }
    // 0x80086FA0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80086FA4: beq         $v1, $at, L_80086FB4
    if (ctx->r3 == ctx->r1) {
        // 0x80086FA8: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_80086FB4;
    }
    // 0x80086FA8: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80086FAC: bne         $v1, $at, L_80087020
    if (ctx->r3 != ctx->r1) {
        // 0x80086FB0: nop
    
            goto L_80087020;
    }
    // 0x80086FB0: nop

L_80086FB4:
    // 0x80086FB4: bne         $t1, $zero, L_80086FF4
    if (ctx->r9 != 0) {
        // 0x80086FB8: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80086FF4;
    }
    // 0x80086FB8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80086FBC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80086FC0: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80086FC4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80086FC8: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80086FCC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80086FD0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80086FD4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80086FD8: ori         $a0, $a0, 0x8034
    ctx->r4 = ctx->r4 | 0X8034;
    // 0x80086FDC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80086FE0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80086FE4: jal         0x80019218
    // 0x80086FE8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80086FE8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80086FEC: b           L_80087020
    // 0x80086FF0: nop

        goto L_80087020;
    // 0x80086FF0: nop

L_80086FF4:
    // 0x80086FF4: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80086FF8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80086FFC: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80087000: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80087004: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80087008: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8008700C: ori         $a0, $a0, 0x8031
    ctx->r4 = ctx->r4 | 0X8031;
    // 0x80087010: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80087014: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80087018: jal         0x80019218
    // 0x8008701C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8008701C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
L_80087020:
    // 0x80087020: beq         $s0, $zero, L_80087044
    if (ctx->r16 == 0) {
        // 0x80087024: lui         $at, 0x43A5
        ctx->r1 = S32(0X43A5 << 16);
            goto L_80087044;
    }
    // 0x80087024: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x80087028: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8008702C: beq         $s0, $at, L_80087054
    if (ctx->r16 == ctx->r1) {
        // 0x80087030: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_80087054;
    }
    // 0x80087030: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80087034: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80087038: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008703C: b           L_800870C0
    // 0x80087040: swc1        $f0, 0x1CFC($at)
    MEM_W(0X1CFC, ctx->r1) = ctx->f0.u32l;
        goto L_800870C0;
    // 0x80087040: swc1        $f0, 0x1CFC($at)
    MEM_W(0X1CFC, ctx->r1) = ctx->f0.u32l;
L_80087044:
    // 0x80087044: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80087048: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008704C: b           L_800870C0
    // 0x80087050: swc1        $f4, 0x1CFC($at)
    MEM_W(0X1CFC, ctx->r1) = ctx->f4.u32l;
        goto L_800870C0;
    // 0x80087050: swc1        $f4, 0x1CFC($at)
    MEM_W(0X1CFC, ctx->r1) = ctx->f4.u32l;
L_80087054:
    // 0x80087054: lw          $t4, -0x7DCC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7DCC);
    // 0x80087058: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8008705C: addiu       $v0, $v0, 0x1CFC
    ctx->r2 = ADD32(ctx->r2, 0X1CFC);
    // 0x80087060: bne         $s1, $t4, L_80087080
    if (ctx->r17 != ctx->r12) {
        // 0x80087064: lui         $at, 0x42DC
        ctx->r1 = S32(0X42DC << 16);
            goto L_80087080;
    }
    // 0x80087064: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80087068: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8008706C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80087070: nop

    // 0x80087074: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80087078: b           L_800870A4
    // 0x8008707C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
        goto L_800870A4;
    // 0x8008707C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_80087080:
    // 0x80087080: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80087084: lwc1        $f16, 0x1CFC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1CFC);
    // 0x80087088: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x8008708C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80087090: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80087094: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80087098: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8008709C: addiu       $v0, $v0, 0x1CFC
    ctx->r2 = ADD32(ctx->r2, 0X1CFC);
    // 0x800870A0: swc1        $f4, 0x1CFC($at)
    MEM_W(0X1CFC, ctx->r1) = ctx->f4.u32l;
L_800870A4:
    // 0x800870A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800870A8: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800870AC: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800870B0: nop

    // 0x800870B4: bc1f        L_800870C0
    if (!c1cs) {
        // 0x800870B8: nop
    
            goto L_800870C0;
    }
    // 0x800870B8: nop

    // 0x800870BC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_800870C0:
    // 0x800870C0: jal         0x800863C8
    // 0x800870C4: nop

    HUD_GetLevelIndex(rdram, ctx);
        goto after_3;
    // 0x800870C4: nop

    after_3:
    // 0x800870C8: beq         $s0, $zero, L_80087118
    if (ctx->r16 == 0) {
        // 0x800870CC: sw          $v0, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r2;
            goto L_80087118;
    }
    // 0x800870CC: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x800870D0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800870D4: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x800870D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800870DC: jal         0x800B8DD0
    // 0x800870E0: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x800870E0: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_4:
    // 0x800870E4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800870E8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800870EC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800870F0: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800870F4: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800870F8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800870FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80087100: lui         $at, 0x42C4
    ctx->r1 = S32(0X42C4 << 16);
    // 0x80087104: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80087108: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8008710C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80087110: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x80087114: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
L_80087118:
    // 0x80087118: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8008711C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80087120: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80087124: beq         $at, $zero, L_80087514
    if (ctx->r1 == 0) {
        // 0x80087128: addiu       $s1, $s1, 0x7E64
        ctx->r17 = ADD32(ctx->r17, 0X7E64);
            goto L_80087514;
    }
    // 0x80087128: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8008712C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80087130: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80087134: addu        $at, $at, $t8
    gpr jr_addend_8008713C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80087138: lw          $t8, 0x786C($at)
    ctx->r24 = ADD32(ctx->r1, 0X786C);
    // 0x8008713C: jr          $t8
    // 0x80087140: nop

    switch (jr_addend_8008713C >> 2) {
        case 0: goto L_80087144; break;
        case 1: goto L_800872B4; break;
        case 2: goto L_80087414; break;
        case 3: goto L_80087458; break;
        case 4: goto L_800874E4; break;
        default: switch_error(__func__, 0x8008713C, 0x800D786C);
    }
    // 0x80087140: nop

L_80087144:
    // 0x80087144: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x80087148: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8008714C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80087150: beq         $t9, $zero, L_8008720C
    if (ctx->r25 == 0) {
        // 0x80087154: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008720C;
    }
    // 0x80087154: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80087158: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8008715C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80087160: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80087164: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80087168: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8008716C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80087170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80087174: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x80087178: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008717C: addiu       $a1, $a1, 0x2DC0
    ctx->r5 = ADD32(ctx->r5, 0X2DC0);
    // 0x80087180: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80087184: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80087188: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
L_8008718C:
    // 0x8008718C: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80087190: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80087194: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80087198: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008719C: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x800871A0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800871A4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800871A8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800871AC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800871B0: add.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x800871B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800871B8: jal         0x8009D994
    // 0x800871BC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x800871BC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x800871C0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800871C4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800871C8: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x800871CC: bne         $s0, $at, L_8008718C
    if (ctx->r16 != ctx->r1) {
        // 0x800871D0: addiu       $a1, $a1, 0x110
        ctx->r5 = ADD32(ctx->r5, 0X110);
            goto L_8008718C;
    }
    // 0x800871D0: addiu       $a1, $a1, 0x110
    ctx->r5 = ADD32(ctx->r5, 0X110);
    // 0x800871D4: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800871D8: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800871DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800871E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800871E4: addiu       $a2, $zero, 0x88
    ctx->r6 = ADD32(0, 0X88);
    // 0x800871E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800871EC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800871F0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800871F4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800871F8: add.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x800871FC: jal         0x8009D994
    // 0x80087200: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_6;
    // 0x80087200: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80087204: b           L_800872B8
    // 0x80087208: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_800872B8;
    // 0x80087208: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8008720C:
    // 0x8008720C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80087210: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x80087214: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80087218: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8008721C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80087220: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x80087224: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80087228: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008722C: addiu       $a1, $a1, 0x4E20
    ctx->r5 = ADD32(ctx->r5, 0X4E20);
    // 0x80087230: add.s       $f22, $f10, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80087234: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_80087238:
    // 0x80087238: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x8008723C: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80087240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80087244: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80087248: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8008724C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80087250: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80087254: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80087258: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8008725C: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x80087260: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80087264: jal         0x8009D994
    // 0x80087268: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_7;
    // 0x80087268: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x8008726C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80087270: lui         $t0, 0x500
    ctx->r8 = S32(0X500 << 16);
    // 0x80087274: addiu       $t0, $t0, 0x5460
    ctx->r8 = ADD32(ctx->r8, 0X5460);
    // 0x80087278: addiu       $a1, $a1, 0xA0
    ctx->r5 = ADD32(ctx->r5, 0XA0);
    // 0x8008727C: bne         $a1, $t0, L_80087238
    if (ctx->r5 != ctx->r8) {
        // 0x80087280: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80087238;
    }
    // 0x80087280: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80087284: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x80087288: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8008728C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80087290: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80087294: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x80087298: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8008729C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800872A0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800872A4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800872A8: add.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f22.fl + ctx->f4.fl;
    // 0x800872AC: jal         0x8009D994
    // 0x800872B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_8;
    // 0x800872B0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
L_800872B4:
    // 0x800872B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800872B8:
    // 0x800872B8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800872BC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800872C0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800872C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800872C8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800872CC: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800872D0: beq         $t1, $zero, L_8008737C
    if (ctx->r9 == 0) {
        // 0x800872D4: add.s       $f22, $f8, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_8008737C;
    }
    // 0x800872D4: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800872D8: lui         $at, 0x4278
    ctx->r1 = S32(0X4278 << 16);
    // 0x800872DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800872E0: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800872E4: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x800872E8: addiu       $a1, $a1, 0x22F0
    ctx->r5 = ADD32(ctx->r5, 0X22F0);
    // 0x800872EC: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800872F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800872F4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_800872F8:
    // 0x800872F8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800872FC: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80087300: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80087304: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80087308: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8008730C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80087310: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80087314: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80087318: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8008731C: add.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x80087320: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80087324: jal         0x8009D994
    // 0x80087328: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_9;
    // 0x80087328: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x8008732C: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80087330: lui         $t2, 0x500
    ctx->r10 = S32(0X500 << 16);
    // 0x80087334: addiu       $t2, $t2, 0x2D40
    ctx->r10 = ADD32(ctx->r10, 0X2D40);
    // 0x80087338: addiu       $a1, $a1, 0xF0
    ctx->r5 = ADD32(ctx->r5, 0XF0);
    // 0x8008733C: bne         $a1, $t2, L_800872F8
    if (ctx->r5 != ctx->r10) {
        // 0x80087340: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_800872F8;
    }
    // 0x80087340: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80087344: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80087348: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8008734C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80087350: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80087354: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x80087358: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8008735C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80087360: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80087364: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80087368: add.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f18.fl;
    // 0x8008736C: jal         0x8009D994
    // 0x80087370: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_10;
    // 0x80087370: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x80087374: b           L_80087418
    // 0x80087378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
        goto L_80087418;
    // 0x80087378: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8008737C:
    // 0x8008737C: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80087380: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80087384: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x80087388: addiu       $a1, $a1, 0x4580
    ctx->r5 = ADD32(ctx->r5, 0X4580);
    // 0x8008738C: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80087390: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80087394: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_80087398:
    // 0x80087398: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x8008739C: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800873A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800873A4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800873A8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800873AC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800873B0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800873B4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800873B8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800873BC: add.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x800873C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800873C4: jal         0x8009D994
    // 0x800873C8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_11;
    // 0x800873C8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x800873CC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800873D0: lui         $t3, 0x500
    ctx->r11 = S32(0X500 << 16);
    // 0x800873D4: addiu       $t3, $t3, 0x4DC0
    ctx->r11 = ADD32(ctx->r11, 0X4DC0);
    // 0x800873D8: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
    // 0x800873DC: bne         $a1, $t3, L_80087398
    if (ctx->r5 != ctx->r11) {
        // 0x800873E0: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80087398;
    }
    // 0x800873E0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800873E4: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x800873E8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800873EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800873F0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800873F4: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800873F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800873FC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80087400: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80087404: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80087408: add.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x8008740C: jal         0x8009D994
    // 0x80087410: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_12;
    // 0x80087410: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_12:
L_80087414:
    // 0x80087414: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80087418:
    // 0x80087418: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8008741C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80087420: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80087424: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80087428: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8008742C: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x80087430: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80087434: addiu       $a1, $a1, 0x3A00
    ctx->r5 = ADD32(ctx->r5, 0X3A00);
    // 0x80087438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8008743C: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80087440: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80087444: addiu       $a3, $zero, 0x17
    ctx->r7 = ADD32(0, 0X17);
    // 0x80087448: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8008744C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80087450: jal         0x8009D994
    // 0x80087454: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_13;
    // 0x80087454: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_13:
L_80087458:
    // 0x80087458: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008745C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80087460: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80087464: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80087468: lui         $a1, 0x500
    ctx->r5 = S32(0X500 << 16);
    // 0x8008746C: addiu       $a1, $a1, 0x500
    ctx->r5 = ADD32(ctx->r5, 0X500);
    // 0x80087470: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80087474: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80087478: addiu       $a3, $zero, 0x13
    ctx->r7 = ADD32(0, 0X13);
    // 0x8008747C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80087480: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80087484: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80087488: jal         0x8009D994
    // 0x8008748C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_14;
    // 0x8008748C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x80087490: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80087494: lui         $at, 0x42E0
    ctx->r1 = S32(0X42E0 << 16);
    // 0x80087498: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008749C: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800874A0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800874A4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800874A8: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800874AC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800874B0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800874B4: addiu       $t6, $t6, 0x1AEC
    ctx->r14 = ADD32(ctx->r14, 0X1AEC);
    // 0x800874B8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800874BC: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x800874C0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800874C4: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800874C8: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800874CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800874D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800874D4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800874D8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800874DC: jal         0x8009D994
    // 0x800874E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_15;
    // 0x800874E0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_15:
L_800874E4:
    // 0x800874E4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800874E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800874EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800874F0: lwc1        $f10, 0x1CFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1CFC);
    // 0x800874F4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800874F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800874FC: lui         $a2, 0x412F
    ctx->r6 = S32(0X412F << 16);
    // 0x80087500: lui         $a3, 0x4098
    ctx->r7 = S32(0X4098 << 16);
    // 0x80087504: ori         $a3, $a3, 0xF5C3
    ctx->r7 = ctx->r7 | 0XF5C3;
    // 0x80087508: ori         $a2, $a2, 0x851F
    ctx->r6 = ctx->r6 | 0X851F;
    // 0x8008750C: jal         0x80086C08
    // 0x80087510: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_16;
    // 0x80087510: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_16:
L_80087514:
    // 0x80087514: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80087518: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8008751C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80087520: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80087524: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80087528: jr          $ra
    // 0x8008752C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8008752C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Display_LandmasterThrusters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052D48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80052D4C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80052D50: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80052D54: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80052D58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052D5C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80052D60: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80052D64: jal         0x80005708
    // 0x80052D68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80052D68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80052D6C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80052D70: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80052D74: addiu       $t9, $t9, 0x1418
    ctx->r25 = ADD32(ctx->r25, 0X1418);
    // 0x80052D78: lw          $t7, 0x1C4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C4);
    // 0x80052D7C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80052D80: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x80052D84: jal         0x80005680
    // 0x80052D88: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    Matrix_Copy(rdram, ctx);
        goto after_1;
    // 0x80052D88: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x80052D8C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80052D90: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x80052D94: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80052D98: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80052D9C: beq         $t0, $zero, L_80052DD8
    if (ctx->r8 == 0) {
        // 0x80052DA0: lui         $t8, 0xFB00
        ctx->r24 = S32(0XFB00 << 16);
            goto L_80052DD8;
    }
    // 0x80052DA0: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80052DA4: jal         0x800BA140
    // 0x80052DA8: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_2;
    // 0x80052DA8: nop

    after_2:
    // 0x80052DAC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80052DB0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80052DB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052DB8: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80052DBC: addiu       $t3, $zero, -0x6A
    ctx->r11 = ADD32(0, -0X6A);
    // 0x80052DC0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80052DC4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80052DC8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80052DCC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80052DD0: b           L_80052E20
    // 0x80052DD4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
        goto L_80052E20;
    // 0x80052DD4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80052DD8:
    // 0x80052DD8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052DDC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80052DE0: addiu       $t6, $zero, -0x40
    ctx->r14 = ADD32(0, -0X40);
    // 0x80052DE4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80052DE8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80052DEC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80052DF0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80052DF4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052DF8: lui         $t9, 0xFF00
    ctx->r25 = S32(0XFF00 << 16);
    // 0x80052DFC: ori         $t9, $t9, 0xC0
    ctx->r25 = ctx->r25 | 0XC0;
    // 0x80052E00: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80052E04: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80052E08: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80052E0C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80052E10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052E14: jal         0x800B8DD0
    // 0x80052E18: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80052E18: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_3:
    // 0x80052E1C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80052E20:
    // 0x80052E20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052E24: lwc1        $f4, 0x5DF8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5DF8);
    // 0x80052E28: lwc1        $f0, 0x16C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X16C);
    // 0x80052E2C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80052E30: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80052E34: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80052E38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80052E3C: bc1fl       L_80052FAC
    if (!c1cs) {
        // 0x80052E40: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_80052FAC;
    }
    goto skip_0;
    // 0x80052E40: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80052E44: lw          $t1, 0x78E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78E8);
    // 0x80052E48: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052E4C: bne         $t1, $zero, L_80052E60
    if (ctx->r9 != 0) {
        // 0x80052E50: nop
    
            goto L_80052E60;
    }
    // 0x80052E50: nop

    // 0x80052E54: lwc1        $f6, 0x5DFC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5DFC);
    // 0x80052E58: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80052E5C: nop

L_80052E60:
    // 0x80052E60: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x80052E64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052E68: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80052E6C: beq         $t3, $zero, L_80052E80
    if (ctx->r11 == 0) {
        // 0x80052E70: nop
    
            goto L_80052E80;
    }
    // 0x80052E70: nop

    // 0x80052E74: lwc1        $f8, 0x5E00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E00);
    // 0x80052E78: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80052E7C: nop

L_80052E80:
    // 0x80052E80: jal         0x80005708
    // 0x80052E84: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x80052E84: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80052E88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80052E8C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80052E90: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80052E94: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80052E98: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80052E9C: jal         0x80005B00
    // 0x80052EA0: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x80052EA0: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    after_5:
    // 0x80052EA4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80052EA8: lw          $t5, 0x78E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78E8);
    // 0x80052EAC: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80052EB0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80052EB4: bnel        $t5, $zero, L_80052F08
    if (ctx->r13 != 0) {
        // 0x80052EB8: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80052F08;
    }
    goto skip_1;
    // 0x80052EB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x80052EBC: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x80052EC0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80052EC4: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80052EC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80052ECC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80052ED0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80052ED4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80052ED8: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x80052EDC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80052EE0: lwc1        $f10, 0x58($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80052EE4: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80052EE8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80052EEC: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80052EF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80052EF4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80052EF8: jal         0x80005E90
    // 0x80052EFC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x80052EFC: nop

    after_6:
    // 0x80052F00: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80052F04: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80052F08:
    // 0x80052F08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80052F0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80052F10: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80052F14: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80052F18: jal         0x80005C34
    // 0x80052F1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x80052F1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_7:
    // 0x80052F20: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80052F24: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80052F28: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80052F2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80052F30: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80052F34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80052F38: jal         0x80005B00
    // 0x80052F3C: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x80052F3C: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    after_8:
    // 0x80052F40: jal         0x80006EB8
    // 0x80052F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x80052F44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80052F48: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80052F4C: lw          $t2, 0x78E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78E8);
    // 0x80052F50: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80052F54: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80052F58: bnel        $t2, $zero, L_80052F88
    if (ctx->r10 != 0) {
        // 0x80052F5C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80052F88;
    }
    goto skip_2;
    // 0x80052F5C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80052F60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052F64: lui         $t5, 0x300
    ctx->r13 = S32(0X300 << 16);
    // 0x80052F68: addiu       $t5, $t5, 0x66B0
    ctx->r13 = ADD32(ctx->r13, 0X66B0);
    // 0x80052F6C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80052F70: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80052F74: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80052F78: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80052F7C: b           L_80052FA0
    // 0x80052F80: nop

        goto L_80052FA0;
    // 0x80052F80: nop

    // 0x80052F84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80052F88:
    // 0x80052F88: lui         $t8, 0x302
    ctx->r24 = S32(0X302 << 16);
    // 0x80052F8C: addiu       $t8, $t8, -0x4920
    ctx->r24 = ADD32(ctx->r24, -0X4920);
    // 0x80052F90: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80052F94: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80052F98: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80052F9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80052FA0:
    // 0x80052FA0: jal         0x80005740
    // 0x80052FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x80052FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80052FA8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
L_80052FAC:
    // 0x80052FAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052FB0: lwc1        $f18, 0x5E04($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5E04);
    // 0x80052FB4: lwc1        $f0, 0x170($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X170);
    // 0x80052FB8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80052FBC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80052FC0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80052FC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80052FC8: bc1f        L_80053130
    if (!c1cs) {
        // 0x80052FCC: nop
    
            goto L_80053130;
    }
    // 0x80052FCC: nop

    // 0x80052FD0: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x80052FD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052FD8: bne         $t0, $zero, L_80052FEC
    if (ctx->r8 != 0) {
        // 0x80052FDC: nop
    
            goto L_80052FEC;
    }
    // 0x80052FDC: nop

    // 0x80052FE0: lwc1        $f4, 0x5E08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5E08);
    // 0x80052FE4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80052FE8: nop

L_80052FEC:
    // 0x80052FEC: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x80052FF0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052FF4: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80052FF8: beq         $t2, $zero, L_8005300C
    if (ctx->r10 == 0) {
        // 0x80052FFC: nop
    
            goto L_8005300C;
    }
    // 0x80052FFC: nop

    // 0x80053000: lwc1        $f6, 0x5E0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5E0C);
    // 0x80053004: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80053008: nop

L_8005300C:
    // 0x8005300C: jal         0x80005708
    // 0x80053010: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x80053010: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x80053014: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80053018: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005301C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80053020: lui         $a1, 0xC1A0
    ctx->r5 = S32(0XC1A0 << 16);
    // 0x80053024: lui         $a2, 0x41F0
    ctx->r6 = S32(0X41F0 << 16);
    // 0x80053028: jal         0x80005B00
    // 0x8005302C: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x8005302C: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    after_12:
    // 0x80053030: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80053034: lw          $t4, 0x78E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78E8);
    // 0x80053038: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005303C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80053040: bnel        $t4, $zero, L_80053094
    if (ctx->r12 != 0) {
        // 0x80053044: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_80053094;
    }
    goto skip_3;
    // 0x80053044: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_3:
    // 0x80053048: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x8005304C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80053050: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x80053054: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80053058: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8005305C: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80053060: subu        $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80053064: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80053068: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x8005306C: lwc1        $f8, 0x58($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X58);
    // 0x80053070: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80053074: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80053078: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8005307C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80053080: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80053084: jal         0x80005E90
    // 0x80053088: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x80053088: nop

    after_13:
    // 0x8005308C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80053090: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_80053094:
    // 0x80053094: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80053098: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005309C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800530A0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800530A4: jal         0x80005C34
    // 0x800530A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_14;
    // 0x800530A8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_14:
    // 0x800530AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800530B0: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800530B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800530B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800530BC: lui         $a2, 0xC1F0
    ctx->r6 = S32(0XC1F0 << 16);
    // 0x800530C0: jal         0x80005B00
    // 0x800530C4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_15;
    // 0x800530C4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_15:
    // 0x800530C8: jal         0x80006EB8
    // 0x800530CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x800530CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800530D0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800530D4: lw          $t1, 0x78E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78E8);
    // 0x800530D8: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x800530DC: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x800530E0: bnel        $t1, $zero, L_80053110
    if (ctx->r9 != 0) {
        // 0x800530E4: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80053110;
    }
    goto skip_4;
    // 0x800530E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_4:
    // 0x800530E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800530EC: lui         $t4, 0x300
    ctx->r12 = S32(0X300 << 16);
    // 0x800530F0: addiu       $t4, $t4, 0x66B0
    ctx->r12 = ADD32(ctx->r12, 0X66B0);
    // 0x800530F4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800530F8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x800530FC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80053100: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80053104: b           L_80053128
    // 0x80053108: nop

        goto L_80053128;
    // 0x80053108: nop

    // 0x8005310C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80053110:
    // 0x80053110: lui         $t6, 0x302
    ctx->r14 = S32(0X302 << 16);
    // 0x80053114: addiu       $t6, $t6, -0x4920
    ctx->r14 = ADD32(ctx->r14, -0X4920);
    // 0x80053118: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005311C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80053120: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80053124: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80053128:
    // 0x80053128: jal         0x80005740
    // 0x8005312C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x8005312C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
L_80053130:
    // 0x80053130: jal         0x80005740
    // 0x80053134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_18;
    // 0x80053134: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80053138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005313C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80053140: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80053144: jr          $ra
    // 0x80053148: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80053148: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Camera_UpdateCockpitOnRails(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5D30: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800B5D34: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B5D38: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800B5D3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5D40: lwc1        $f20, -0x758C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X758C);
    // 0x800B5D44: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B5D48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B5D4C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800B5D50: lwc1        $f4, 0xE8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800B5D54: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B5D58: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800B5D5C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B5D60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B5D64: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B5D68: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B5D6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B5D70: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800B5D74: nop

    // 0x800B5D78: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B5D7C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B5D80: jal         0x80005E90
    // 0x800B5D84: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x800B5D84: nop

    after_0:
    // 0x800B5D88: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800B5D8C: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B5D90: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x800B5D94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B5D98: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B5D9C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B5DA0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B5DA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B5DA8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800B5DAC: nop

    // 0x800B5DB0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B5DB4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800B5DB8: jal         0x80005D44
    // 0x800B5DBC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x800B5DBC: nop

    after_1:
    // 0x800B5DC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B5DC4: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x800B5DC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B5DCC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B5DD0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B5DD4: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x800B5DD8: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800B5DDC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800B5DE0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x800B5DE4: jal         0x80006970
    // 0x800B5DE8: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x800B5DE8: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800B5DEC: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B5DF0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B5DF4: addiu       $v0, $v0, 0x7978
    ctx->r2 = ADD32(ctx->r2, 0X7978);
    // 0x800B5DF8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800B5DFC: lwc1        $f10, 0x80($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800B5E00: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B5E04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5E08: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B5E0C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B5E10: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B5E14: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x800B5E18: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B5E1C: swc1        $f16, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f16.u32l;
    // 0x800B5E20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5E24: lwc1        $f0, 0x7D20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800B5E28: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800B5E2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5E30: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800B5E34: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x800B5E38: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B5E3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5E40: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B5E44: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B5E48: swc1        $f10, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f10.u32l;
    // 0x800B5E4C: lwc1        $f18, 0x80($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800B5E50: lwc1        $f16, 0x78($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B5E54: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5E58: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B5E5C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B5E60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B5E64: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x800B5E68: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800B5E6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5E70: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800B5E74: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B5E78: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x800B5E7C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5E80: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800B5E84: jal         0x8009BC2C
    // 0x800B5E88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800B5E88: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x800B5E8C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5E90: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5E94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800B5E98: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x800B5E9C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800B5EA0: jal         0x8009BC2C
    // 0x800B5EA4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800B5EA4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_4:
    // 0x800B5EA8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5EAC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5EB0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800B5EB4: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x800B5EB8: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800B5EBC: jal         0x8009BC2C
    // 0x800B5EC0: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B5EC0: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    after_5:
    // 0x800B5EC4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5EC8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5ECC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800B5ED0: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x800B5ED4: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x800B5ED8: jal         0x8009BC2C
    // 0x800B5EDC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B5EDC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_6:
    // 0x800B5EE0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5EE4: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5EE8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800B5EEC: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x800B5EF0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x800B5EF4: jal         0x8009BC2C
    // 0x800B5EF8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B5EF8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_7:
    // 0x800B5EFC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B5F00: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800B5F04: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800B5F08: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x800B5F0C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x800B5F10: jal         0x8009BC2C
    // 0x800B5F14: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800B5F14: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    after_8:
    // 0x800B5F18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B5F1C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B5F20: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B5F24: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x800B5F28: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B5F2C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800B5F30: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B5F34: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800B5F38: jal         0x8009BC2C
    // 0x800B5F3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800B5F3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x800B5F40: lwc1        $f8, 0xF8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800B5F44: lwc1        $f10, 0xF0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800B5F48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5F4C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B5F50: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B5F54: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
    // 0x800B5F58: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800B5F5C: beql        $t6, $zero, L_800B5FAC
    if (ctx->r14 == 0) {
        // 0x800B5F60: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B5FAC;
    }
    goto skip_0;
    // 0x800B5F60: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800B5F64: lwc1        $f4, 0x7978($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x800B5F68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5F6C: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x800B5F70: lwc1        $f6, 0x7980($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x800B5F74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5F78: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x800B5F7C: lwc1        $f8, 0x7988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x800B5F80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5F84: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
    // 0x800B5F88: lwc1        $f10, 0x79A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x800B5F8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5F90: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x800B5F94: lwc1        $f16, 0x79B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x800B5F98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5F9C: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    // 0x800B5FA0: lwc1        $f18, 0x79C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x800B5FA4: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x800B5FA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B5FAC:
    // 0x800B5FAC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800B5FB0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B5FB4: jr          $ra
    // 0x800B5FB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800B5FB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void HUD_RadarMark_Arwing_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80089994: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80089998: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008999C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800899A0: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800899A4: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800899A8: addiu       $t7, $t7, 0x1E14
    ctx->r15 = ADD32(ctx->r15, 0X1E14);
    // 0x800899AC: addiu       $t1, $t7, 0x78
    ctx->r9 = ADD32(ctx->r15, 0X78);
    // 0x800899B0: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
L_800899B4:
    // 0x800899B4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800899B8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800899BC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800899C0: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x800899C4: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800899C8: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800899CC: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800899D0: bne         $t7, $t1, L_800899B4
    if (ctx->r15 != ctx->r9) {
        // 0x800899D4: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_800899B4;
    }
    // 0x800899D4: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800899D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800899DC: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x800899E0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800899E4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800899E8: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x800899EC: lw          $t2, 0x78A8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A8);
    // 0x800899F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800899F4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800899F8: beq         $t2, $at, L_80089A10
    if (ctx->r10 == ctx->r1) {
        // 0x800899FC: addiu       $s0, $s0, 0x7E64
        ctx->r16 = ADD32(ctx->r16, 0X7E64);
            goto L_80089A10;
    }
    // 0x800899FC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80089A00: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80089A04: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80089A08: b           L_80089A20
    // 0x80089A0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80089A20;
    // 0x80089A0C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80089A10:
    // 0x80089A10: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x80089A14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80089A18: nop

    // 0x80089A1C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80089A20:
    // 0x80089A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80089A24: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80089A28: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x80089A2C: jal         0x800B8DD0
    // 0x80089A30: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80089A30: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80089A34: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80089A38: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80089A3C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80089A40: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80089A44: addiu       $t8, $sp, 0x40
    ctx->r24 = ADD32(ctx->r29, 0X40);
    // 0x80089A48: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x80089A4C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80089A50: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80089A54: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x80089A58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80089A5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80089A60: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x80089A64: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x80089A68: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x80089A6C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80089A70: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x80089A74: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80089A78: andi        $t7, $t1, 0xFF
    ctx->r15 = ctx->r9 & 0XFF;
    // 0x80089A7C: sll         $t3, $t2, 24
    ctx->r11 = S32(ctx->r10 << 24);
    // 0x80089A80: or          $t4, $t7, $t3
    ctx->r12 = ctx->r15 | ctx->r11;
    // 0x80089A84: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x80089A88: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80089A8C: andi        $t2, $t6, 0xFF
    ctx->r10 = ctx->r14 & 0XFF;
    // 0x80089A90: sll         $t7, $t2, 8
    ctx->r15 = S32(ctx->r10 << 8);
    // 0x80089A94: or          $t1, $t4, $t8
    ctx->r9 = ctx->r12 | ctx->r24;
    // 0x80089A98: or          $t3, $t1, $t7
    ctx->r11 = ctx->r9 | ctx->r15;
    // 0x80089A9C: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x80089AA0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80089AA4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80089AA8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80089AAC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80089AB0: jal         0x80005C34
    // 0x80089AB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80089AB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80089AB8: jal         0x80006EB8
    // 0x80089ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80089ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80089AC0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80089AC4: lui         $t8, 0x101
    ctx->r24 = S32(0X101 << 16);
    // 0x80089AC8: addiu       $t8, $t8, 0x5510
    ctx->r24 = ADD32(ctx->r24, 0X5510);
    // 0x80089ACC: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x80089AD0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80089AD4: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80089AD8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80089ADC: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80089AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80089AE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089AE8: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x80089AEC: jr          $ra
    // 0x80089AF0: nop

    return;
    // 0x80089AF0: nop

;}
RECOMP_FUNC void Effect_Effect382_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077A7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077A80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80077A84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80077A88: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80077A8C: jal         0x800BA5B0
    // 0x80077A90: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_0;
    // 0x80077A90: nop

    after_0:
    // 0x80077A94: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80077A98: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80077A9C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80077AA0: addiu       $t2, $zero, -0x100
    ctx->r10 = ADD32(0, -0X100);
    // 0x80077AA4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80077AA8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80077AAC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80077AB0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80077AB4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80077AB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80077ABC: lh          $t8, 0x44($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X44);
    // 0x80077AC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80077AC4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80077AC8: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80077ACC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80077AD0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80077AD4: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80077AD8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80077ADC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80077AE0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80077AE4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80077AE8: lh          $t6, 0x44($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X44);
    // 0x80077AEC: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80077AF0: or          $t8, $t7, $t2
    ctx->r24 = ctx->r15 | ctx->r10;
    // 0x80077AF4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80077AF8: lw          $a1, 0x6C($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X6C);
    // 0x80077AFC: lw          $a2, 0x70($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X70);
    // 0x80077B00: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80077B04: jal         0x80005C34
    // 0x80077B08: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80077B08: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x80077B0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80077B10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80077B14: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077B18: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80077B1C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80077B20: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80077B24: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80077B28: jal         0x80005B00
    // 0x80077B2C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80077B2C: lui         $a2, 0x41A0
    ctx->r6 = S32(0X41A0 << 16);
    after_2:
    // 0x80077B30: jal         0x80006EB8
    // 0x80077B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x80077B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80077B38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80077B3C: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x80077B40: addiu       $t6, $t6, 0x4220
    ctx->r14 = ADD32(ctx->r14, 0X4220);
    // 0x80077B44: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80077B48: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80077B4C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80077B50: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80077B54: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80077B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80077B5C: jal         0x800B8DD0
    // 0x80077B60: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80077B60: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_4:
    // 0x80077B64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80077B68: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80077B6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80077B70: jr          $ra
    // 0x80077B74: nop

    return;
    // 0x80077B74: nop

;}
RECOMP_FUNC void AudioThread_ResetComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001ED34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001ED38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001ED3C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001ED40: lw          $a0, 0x7C64($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7C64);
    // 0x8001ED44: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8001ED48: jal         0x800205E0
    // 0x8001ED4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8001ED4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001ED50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001ED54: bne         $v0, $at, L_8001ED64
    if (ctx->r2 != ctx->r1) {
        // 0x8001ED58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001ED64;
    }
    // 0x8001ED58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001ED5C: b           L_8001ED84
    // 0x8001ED60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001ED84;
    // 0x8001ED60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ED64:
    // 0x8001ED64: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001ED68: lbu         $t7, -0x2AD7($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2AD7);
    // 0x8001ED6C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8001ED70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001ED74: beq         $t6, $t7, L_8001ED84
    if (ctx->r14 == ctx->r15) {
        // 0x8001ED78: nop
    
            goto L_8001ED84;
    }
    // 0x8001ED78: nop

    // 0x8001ED7C: b           L_8001ED84
    // 0x8001ED80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8001ED84;
    // 0x8001ED80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ED84:
    // 0x8001ED84: jr          $ra
    // 0x8001ED88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8001ED88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Animation_GetSkeletonBoundingBox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B784: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x8009B788: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8009B78C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009B790: lui         $v1, 0xFF
    ctx->r3 = S32(0XFF << 16);
    // 0x8009B794: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8009B798: addiu       $v0, $v0, 0x1FD0
    ctx->r2 = ADD32(ctx->r2, 0X1FD0);
    // 0x8009B79C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8009B7A0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8009B7A4: sw          $a2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r6;
    // 0x8009B7A8: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8009B7AC: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8009B7B0: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8009B7B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009B7B8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8009B7BC: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8009B7C0: and         $t7, $a0, $v1
    ctx->r15 = ctx->r4 & ctx->r3;
    // 0x8009B7C4: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009B7C8: addu        $ra, $t8, $t0
    ctx->r31 = ADD32(ctx->r24, ctx->r8);
    // 0x8009B7CC: lw          $t1, 0x0($ra)
    ctx->r9 = MEM_W(ctx->r31, 0X0);
    // 0x8009B7D0: sll         $t6, $t1, 4
    ctx->r14 = S32(ctx->r9 << 4);
    // 0x8009B7D4: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8009B7D8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009B7DC: addu        $t6, $v0, $t8
    ctx->r14 = ADD32(ctx->r2, ctx->r24);
    // 0x8009B7E0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8009B7E4: and         $t9, $t1, $v1
    ctx->r25 = ctx->r9 & ctx->r3;
    // 0x8009B7E8: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8009B7EC: addu        $t6, $t8, $t0
    ctx->r14 = ADD32(ctx->r24, ctx->r8);
    // 0x8009B7F0: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x8009B7F4: srl         $t7, $t9, 28
    ctx->r15 = S32(U32(ctx->r25) >> 28);
    // 0x8009B7F8: sw          $t6, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r14;
    // 0x8009B7FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8009B800: addu        $t6, $v0, $t8
    ctx->r14 = ADD32(ctx->r2, ctx->r24);
    // 0x8009B804: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8009B808: and         $t7, $a1, $v1
    ctx->r15 = ctx->r5 & ctx->r3;
    // 0x8009B80C: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8009B810: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x8009B814: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8009B818: lw          $t4, 0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X4);
    // 0x8009B81C: sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11 << 4);
    // 0x8009B820: srl         $t9, $t6, 28
    ctx->r25 = S32(U32(ctx->r14) >> 28);
    // 0x8009B824: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8009B828: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8009B82C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8009B830: and         $t9, $t3, $v1
    ctx->r25 = ctx->r11 & ctx->r3;
    // 0x8009B834: sll         $t8, $t4, 4
    ctx->r24 = S32(ctx->r12 << 4);
    // 0x8009B838: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x8009B83C: srl         $t6, $t8, 28
    ctx->r14 = S32(U32(ctx->r24) >> 28);
    // 0x8009B840: addu        $t5, $t7, $t0
    ctx->r13 = ADD32(ctx->r15, ctx->r8);
    // 0x8009B844: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009B848: addu        $t7, $v0, $t9
    ctx->r15 = ADD32(ctx->r2, ctx->r25);
    // 0x8009B84C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8009B850: and         $t6, $t4, $v1
    ctx->r14 = ctx->r12 & ctx->r3;
    // 0x8009B854: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8009B858: addu        $t7, $t9, $t0
    ctx->r15 = ADD32(ctx->r25, ctx->r8);
    // 0x8009B85C: sw          $t7, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r15;
    // 0x8009B860: lh          $t6, 0x14($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X14);
    // 0x8009B864: lw          $t8, 0x148($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X148);
    // 0x8009B868: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009B86C: beql        $at, $zero, L_8009B894
    if (ctx->r1 == 0) {
        // 0x8009B870: lh          $t9, 0x16($t5)
        ctx->r25 = MEM_H(ctx->r13, 0X16);
            goto L_8009B894;
    }
    goto skip_0;
    // 0x8009B870: lh          $t9, 0x16($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X16);
    skip_0:
    // 0x8009B874: lh          $t9, 0x16($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X16);
    // 0x8009B878: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8009B87C: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x8009B880: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8009B884: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x8009B888: b           L_8009B8A4
    // 0x8009B88C: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
        goto L_8009B8A4;
    // 0x8009B88C: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
    // 0x8009B890: lh          $t9, 0x16($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X16);
L_8009B894:
    // 0x8009B894: lw          $t8, 0x138($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X138);
    // 0x8009B898: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x8009B89C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x8009B8A0: lhu         $v0, 0x0($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X0);
L_8009B8A4:
    // 0x8009B8A4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8009B8A8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009B8AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009B8B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009B8B4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8009B8B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B8BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B8C0: lwc1        $f4, -0x7DCC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7DCC);
    // 0x8009B8C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009B8C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009B8CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8009B8D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009B8D4: sw          $t5, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r13;
    // 0x8009B8D8: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009B8DC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009B8E0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8009B8E4: jal         0x80005FE0
    // 0x8009B8E8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x8009B8E8: nop

    after_0:
    // 0x8009B8EC: lw          $t5, 0x13C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X13C);
    // 0x8009B8F0: lw          $a3, 0x148($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X148);
    // 0x8009B8F4: lw          $v1, 0x138($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X138);
    // 0x8009B8F8: lh          $t9, 0x10($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X10);
    // 0x8009B8FC: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8009B900: beql        $at, $zero, L_8009B928
    if (ctx->r1 == 0) {
        // 0x8009B904: lh          $t7, 0x12($t5)
        ctx->r15 = MEM_H(ctx->r13, 0X12);
            goto L_8009B928;
    }
    goto skip_1;
    // 0x8009B904: lh          $t7, 0x12($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X12);
    skip_1:
    // 0x8009B908: lh          $t8, 0x12($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X12);
    // 0x8009B90C: sll         $t9, $a3, 1
    ctx->r25 = S32(ctx->r7 << 1);
    // 0x8009B910: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8009B914: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x8009B918: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x8009B91C: b           L_8009B934
    // 0x8009B920: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
        goto L_8009B934;
    // 0x8009B920: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
    // 0x8009B924: lh          $t7, 0x12($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X12);
L_8009B928:
    // 0x8009B928: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8009B92C: addu        $t9, $v1, $t6
    ctx->r25 = ADD32(ctx->r3, ctx->r14);
    // 0x8009B930: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
L_8009B934:
    // 0x8009B934: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8009B938: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009B93C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009B940: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009B944: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8009B948: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009B94C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B950: lwc1        $f8, -0x7DC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7DC8);
    // 0x8009B954: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009B958: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009B95C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8009B960: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009B964: sw          $t5, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r13;
    // 0x8009B968: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009B96C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009B970: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8009B974: jal         0x80005E90
    // 0x8009B978: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8009B978: nop

    after_1:
    // 0x8009B97C: lw          $t5, 0x13C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X13C);
    // 0x8009B980: lw          $a3, 0x148($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X148);
    // 0x8009B984: lw          $v1, 0x138($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X138);
    // 0x8009B988: lh          $t8, 0xC($t5)
    ctx->r24 = MEM_H(ctx->r13, 0XC);
    // 0x8009B98C: slt         $at, $a3, $t8
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009B990: beql        $at, $zero, L_8009B9B8
    if (ctx->r1 == 0) {
        // 0x8009B994: lh          $t6, 0xE($t5)
        ctx->r14 = MEM_H(ctx->r13, 0XE);
            goto L_8009B9B8;
    }
    goto skip_2;
    // 0x8009B994: lh          $t6, 0xE($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XE);
    skip_2:
    // 0x8009B998: lh          $t7, 0xE($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XE);
    // 0x8009B99C: sll         $t8, $a3, 1
    ctx->r24 = S32(ctx->r7 << 1);
    // 0x8009B9A0: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8009B9A4: addu        $t9, $v1, $t6
    ctx->r25 = ADD32(ctx->r3, ctx->r14);
    // 0x8009B9A8: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8009B9AC: b           L_8009B9C4
    // 0x8009B9B0: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
        goto L_8009B9C4;
    // 0x8009B9B0: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x8009B9B4: lh          $t6, 0xE($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XE);
L_8009B9B8:
    // 0x8009B9B8: sll         $t9, $t6, 1
    ctx->r25 = S32(ctx->r14 << 1);
    // 0x8009B9BC: addu        $t8, $v1, $t9
    ctx->r24 = ADD32(ctx->r3, ctx->r25);
    // 0x8009B9C0: lhu         $v0, 0x0($t8)
    ctx->r2 = MEM_HU(ctx->r24, 0X0);
L_8009B9C4:
    // 0x8009B9C4: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8009B9C8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009B9CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8009B9D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8009B9D4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8009B9D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009B9DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009B9E0: lwc1        $f16, -0x7DC4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7DC4);
    // 0x8009B9E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8009B9E8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8009B9EC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8009B9F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8009B9F4: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8009B9F8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8009B9FC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8009BA00: jal         0x80005D44
    // 0x8009BA04: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x8009BA04: nop

    after_2:
    // 0x8009BA08: lw          $t7, 0x130($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X130);
    // 0x8009BA0C: sw          $zero, 0x128($sp)
    MEM_W(0X128, ctx->r29) = 0;
    // 0x8009BA10: lw          $a3, 0x150($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X150);
    // 0x8009BA14: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8009BA18: addiu       $a1, $zero, 0x2000
    ctx->r5 = ADD32(0, 0X2000);
    // 0x8009BA1C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8009BA20: beq         $a0, $zero, L_8009BC18
    if (ctx->r4 == 0) {
        // 0x8009BA24: addiu       $t6, $sp, 0x128
        ctx->r14 = ADD32(ctx->r29, 0X128);
            goto L_8009BC18;
    }
    // 0x8009BA24: addiu       $t6, $sp, 0x128
    ctx->r14 = ADD32(ctx->r29, 0X128);
    // 0x8009BA28: addiu       $t9, $sp, 0x124
    ctx->r25 = ADD32(ctx->r29, 0X124);
    // 0x8009BA2C: addiu       $t8, $sp, 0x120
    ctx->r24 = ADD32(ctx->r29, 0X120);
    // 0x8009BA30: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8009BA34: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009BA38: jal         0x8009AD18
    // 0x8009BA3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Animation_FindBoundingBox(rdram, ctx);
        goto after_3;
    // 0x8009BA3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x8009BA40: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x8009BA44: lw          $a3, 0x150($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X150);
    // 0x8009BA48: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x8009BA4C: beql        $t7, $zero, L_8009BC1C
    if (ctx->r15 == 0) {
        // 0x8009BA50: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8009BC1C;
    }
    goto skip_3;
    // 0x8009BA50: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x8009BA54: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8009BA58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009BA5C: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA60: swc1        $f0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA64: swc1        $f0, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA68: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA6C: lwc1        $f0, 0x4($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8009BA70: swc1        $f0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA74: swc1        $f0, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA78: swc1        $f0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA7C: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA80: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8009BA84: swc1        $f0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA88: swc1        $f0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA8C: swc1        $f0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA90: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA94: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8009BA98: swc1        $f0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f0.u32l;
    // 0x8009BA9C: swc1        $f0, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAA0: swc1        $f0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAA4: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAA8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009BAAC: swc1        $f0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAB0: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAB4: swc1        $f0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAB8: swc1        $f0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f0.u32l;
    // 0x8009BABC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8009BAC0: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAC4: swc1        $f0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAC8: swc1        $f0, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f0.u32l;
    // 0x8009BACC: swc1        $f0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f0.u32l;
    // 0x8009BAD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8009BAD4:
    // 0x8009BAD4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8009BAD8: bnel        $at, $zero, L_8009BAD4
    if (ctx->r1 != 0) {
        // 0x8009BADC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8009BAD4;
    }
    goto skip_4;
    // 0x8009BADC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_4:
    // 0x8009BAE0: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8009BAE4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8009BAE8: addiu       $v1, $sp, 0x6C
    ctx->r3 = ADD32(ctx->r29, 0X6C);
    // 0x8009BAEC: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x8009BAF0: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8009BAF4: addiu       $v0, $sp, 0xC0
    ctx->r2 = ADD32(ctx->r29, 0XC0);
    // 0x8009BAF8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8009BAFC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8009BB00: sw          $at, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r1;
    // 0x8009BB04: lw          $at, 0x0($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X0);
    // 0x8009BB08: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x8009BB0C: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x8009BB10: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x8009BB14: lw          $at, 0x8($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X8);
    // 0x8009BB18: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x8009BB1C: lw          $at, 0x0($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X0);
    // 0x8009BB20: sw          $at, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r1;
    // 0x8009BB24: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x8009BB28: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8009BB2C: lw          $at, 0x8($a0)
    ctx->r1 = MEM_W(ctx->r4, 0X8);
    // 0x8009BB30: sw          $at, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r1;
    // 0x8009BB34: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
L_8009BB38:
    // 0x8009BB38: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8009BB3C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009BB40: nop

    // 0x8009BB44: bc1fl       L_8009BB58
    if (!c1cs) {
        // 0x8009BB48: swc1        $f0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
            goto L_8009BB58;
    }
    goto skip_5;
    // 0x8009BB48: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    skip_5:
    // 0x8009BB4C: b           L_8009BB58
    // 0x8009BB50: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
        goto L_8009BB58;
    // 0x8009BB50: swc1        $f2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f2.u32l;
    // 0x8009BB54: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8009BB58:
    // 0x8009BB58: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8009BB5C: lwc1        $f2, 0x0($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8009BB60: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009BB64: nop

    // 0x8009BB68: bc1fl       L_8009BB7C
    if (!c1cs) {
        // 0x8009BB6C: swc1        $f0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
            goto L_8009BB7C;
    }
    goto skip_6;
    // 0x8009BB6C: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    skip_6:
    // 0x8009BB70: b           L_8009BB7C
    // 0x8009BB74: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
        goto L_8009BB7C;
    // 0x8009BB74: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    // 0x8009BB78: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_8009BB7C:
    // 0x8009BB7C: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8009BB80: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8009BB84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009BB88: nop

    // 0x8009BB8C: bc1fl       L_8009BBA0
    if (!c1cs) {
        // 0x8009BB90: swc1        $f0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
            goto L_8009BBA0;
    }
    goto skip_7;
    // 0x8009BB90: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    skip_7:
    // 0x8009BB94: b           L_8009BBA0
    // 0x8009BB98: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
        goto L_8009BBA0;
    // 0x8009BB98: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x8009BB9C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
L_8009BBA0:
    // 0x8009BBA0: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8009BBA4: lwc1        $f2, 0x4($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8009BBA8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009BBAC: nop

    // 0x8009BBB0: bc1fl       L_8009BBC4
    if (!c1cs) {
        // 0x8009BBB4: swc1        $f0, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
            goto L_8009BBC4;
    }
    goto skip_8;
    // 0x8009BBB4: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    skip_8:
    // 0x8009BBB8: b           L_8009BBC4
    // 0x8009BBBC: swc1        $f2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f2.u32l;
        goto L_8009BBC4;
    // 0x8009BBBC: swc1        $f2, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f2.u32l;
    // 0x8009BBC0: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
L_8009BBC4:
    // 0x8009BBC4: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8009BBC8: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8009BBCC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009BBD0: nop

    // 0x8009BBD4: bc1fl       L_8009BBE8
    if (!c1cs) {
        // 0x8009BBD8: swc1        $f0, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
            goto L_8009BBE8;
    }
    goto skip_9;
    // 0x8009BBD8: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    skip_9:
    // 0x8009BBDC: b           L_8009BBE8
    // 0x8009BBE0: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
        goto L_8009BBE8;
    // 0x8009BBE0: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    // 0x8009BBE4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_8009BBE8:
    // 0x8009BBE8: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8009BBEC: lwc1        $f2, 0x8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8009BBF0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8009BBF4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8009BBF8: nop

    // 0x8009BBFC: bc1fl       L_8009BC10
    if (!c1cs) {
        // 0x8009BC00: swc1        $f0, 0x8($a3)
        MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
            goto L_8009BC10;
    }
    goto skip_10;
    // 0x8009BC00: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    skip_10:
    // 0x8009BC04: b           L_8009BC10
    // 0x8009BC08: swc1        $f2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f2.u32l;
        goto L_8009BC10;
    // 0x8009BC08: swc1        $f2, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f2.u32l;
    // 0x8009BC0C: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
L_8009BC10:
    // 0x8009BC10: bnel        $v1, $v0, L_8009BB38
    if (ctx->r3 != ctx->r2) {
        // 0x8009BC14: lwc1        $f2, 0x0($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
            goto L_8009BB38;
    }
    goto skip_11;
    // 0x8009BC14: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    skip_11:
L_8009BC18:
    // 0x8009BC18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8009BC1C:
    // 0x8009BC1C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8009BC20: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    // 0x8009BC24: jr          $ra
    // 0x8009BC28: nop

    return;
    // 0x8009BC28: nop

;}
RECOMP_FUNC void ActorEvent_PinkExplosion_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006F048: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006F04C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8006F050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8006F058: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006F05C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8006F060: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8006F064: jal         0x80061474
    // 0x8006F068: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8006F068: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006F06C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006F070: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006F074: addiu       $t7, $zero, 0x15B
    ctx->r15 = ADD32(0, 0X15B);
    // 0x8006F078: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8006F07C: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8006F080: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006F084: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8006F088: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8006F08C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8006F090: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006F094: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8006F098: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x8006F09C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006F0A0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8006F0A4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006F0A8: sh          $t8, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r24;
    // 0x8006F0AC: jal         0x800612B8
    // 0x8006F0B0: swc1        $f10, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8006F0B0: swc1        $f10, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f10.u32l;
    after_1:
    // 0x8006F0B4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8006F0B8: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8006F0BC: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x8006F0C0: jal         0x8007A6F0
    // 0x8006F0C4: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_2;
    // 0x8006F0C4: addiu       $a0, $a2, 0x4
    ctx->r4 = ADD32(ctx->r6, 0X4);
    after_2:
    // 0x8006F0C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F0CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006F0D0: jr          $ra
    // 0x8006F0D4: nop

    return;
    // 0x8006F0D4: nop

;}
RECOMP_FUNC void Boss299_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FC4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042FC8: jr          $ra
    // 0x80042FCC: nop

    return;
    // 0x80042FCC: nop

;}
RECOMP_FUNC void func_versus_800C1138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1138: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C113C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C1140: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C1144: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C1148: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C114C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C1150: addiu       $s6, $sp, 0x88
    ctx->r22 = ADD32(ctx->r29, 0X88);
    // 0x800C1154: addiu       $s7, $sp, 0x78
    ctx->r23 = ADD32(ctx->r29, 0X78);
    // 0x800C1158: addiu       $fp, $sp, 0x68
    ctx->r30 = ADD32(ctx->r29, 0X68);
    // 0x800C115C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C1160: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C1164: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C1168: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C116C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C1170: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C1174: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800C1178: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800C117C: addiu       $t7, $t7, 0x4CB8
    ctx->r15 = ADD32(ctx->r15, 0X4CB8);
    // 0x800C1180: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800C1184: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800C1188: addiu       $t6, $sp, 0xA8
    ctx->r14 = ADD32(ctx->r29, 0XA8);
    // 0x800C118C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800C1190: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800C1194: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800C1198: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800C119C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800C11A0: addiu       $t2, $t2, 0x4CC8
    ctx->r10 = ADD32(ctx->r10, 0X4CC8);
    // 0x800C11A4: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800C11A8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800C11AC: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800C11B0: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800C11B4: addiu       $t1, $sp, 0x98
    ctx->r9 = ADD32(ctx->r29, 0X98);
    // 0x800C11B8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800C11BC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800C11C0: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800C11C4: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800C11C8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800C11CC: addiu       $t9, $t9, 0x4CD8
    ctx->r25 = ADD32(ctx->r25, 0X4CD8);
    // 0x800C11D0: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800C11D4: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x800C11D8: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800C11DC: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800C11E0: addiu       $t0, $t0, 0x4CE8
    ctx->r8 = ADD32(ctx->r8, 0X4CE8);
    // 0x800C11E4: sw          $at, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r1;
    // 0x800C11E8: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x800C11EC: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800C11F0: addiu       $t2, $t2, 0x4CF8
    ctx->r10 = ADD32(ctx->r10, 0X4CF8);
    // 0x800C11F4: sw          $t7, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r15;
    // 0x800C11F8: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x800C11FC: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800C1200: addiu       $t3, $sp, 0xA8
    ctx->r11 = ADD32(ctx->r29, 0XA8);
    // 0x800C1204: sw          $at, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r1;
    // 0x800C1208: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x800C120C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800C1210: addu        $t9, $t9, $a1
    ctx->r25 = ADD32(ctx->r25, ctx->r5);
    // 0x800C1214: sw          $t7, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r15;
    // 0x800C1218: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800C121C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800C1220: addiu       $t7, $t7, 0x7DD0
    ctx->r15 = ADD32(ctx->r15, 0X7DD0);
    // 0x800C1224: sw          $at, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r1;
    // 0x800C1228: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800C122C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800C1230: addiu       $t4, $sp, 0x98
    ctx->r12 = ADD32(ctx->r29, 0X98);
    // 0x800C1234: sw          $t1, 0x4($s7)
    MEM_W(0X4, ctx->r23) = ctx->r9;
    // 0x800C1238: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800C123C: addu        $s5, $v0, $t4
    ctx->r21 = ADD32(ctx->r2, ctx->r12);
    // 0x800C1240: addu        $s2, $t9, $t7
    ctx->r18 = ADD32(ctx->r25, ctx->r15);
    // 0x800C1244: sw          $at, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r1;
    // 0x800C1248: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x800C124C: addu        $s4, $v0, $t3
    ctx->r20 = ADD32(ctx->r2, ctx->r11);
    // 0x800C1250: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C1254: sw          $t1, 0xC($s7)
    MEM_W(0XC, ctx->r23) = ctx->r9;
    // 0x800C1258: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800C125C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C1260: sw          $at, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r1;
    // 0x800C1264: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x800C1268: sw          $t8, 0x4($fp)
    MEM_W(0X4, ctx->r30) = ctx->r24;
    // 0x800C126C: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800C1270: sw          $at, 0x8($fp)
    MEM_W(0X8, ctx->r30) = ctx->r1;
    // 0x800C1274: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x800C1278: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800C127C: blez        $s3, L_800C1330
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800C1280: sw          $t8, 0xC($fp)
        MEM_W(0XC, ctx->r30) = ctx->r24;
            goto L_800C1330;
    }
    // 0x800C1280: sw          $t8, 0xC($fp)
    MEM_W(0XC, ctx->r30) = ctx->r24;
    // 0x800C1284: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800C1288: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
L_800C128C:
    // 0x800C128C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C1290: jal         0x800B8DD0
    // 0x800C1294: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800C1294: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    after_0:
    // 0x800C1298: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x800C129C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C12A0: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C12A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C12A8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800C12AC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800C12B0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C12B4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800C12B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C12BC: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800C12C0: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x800C12C4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800C12C8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800C12CC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800C12D0: addu        $t8, $fp, $v1
    ctx->r24 = ADD32(ctx->r30, ctx->r3);
    // 0x800C12D4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800C12D8: addu        $t2, $s7, $v1
    ctx->r10 = ADD32(ctx->r23, ctx->r3);
    // 0x800C12DC: addu        $t4, $s6, $v1
    ctx->r12 = ADD32(ctx->r22, ctx->r3);
    // 0x800C12E0: lw          $t1, 0x0($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X0);
    // 0x800C12E4: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800C12E8: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800C12EC: sll         $t3, $t7, 8
    ctx->r11 = S32(ctx->r15 << 8);
    // 0x800C12F0: sll         $t6, $t1, 24
    ctx->r14 = S32(ctx->r9 << 24);
    // 0x800C12F4: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C12F8: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800C12FC: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x800C1300: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800C1304: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800C1308: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x800C130C: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800C1310: lwc1        $f14, 0x0($s5)
    ctx->f14.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800C1314: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C1318: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800C131C: jal         0x800BD720
    // 0x800C1320: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    func_versus_800BD720(rdram, ctx);
        goto after_1;
    // 0x800C1320: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_1:
    // 0x800C1324: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C1328: bne         $s1, $s3, L_800C128C
    if (ctx->r17 != ctx->r19) {
        // 0x800C132C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800C128C;
    }
    // 0x800C132C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800C1330:
    // 0x800C1330: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C1334: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C1338: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800C133C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C1340: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C1344: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C1348: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C134C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C1350: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C1354: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C1358: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C135C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C1360: jr          $ra
    // 0x800C1364: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800C1364: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void Message_GetWidth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C28DC: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800C28E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C28E4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C28E8: beq         $t6, $zero, L_800C291C
    if (ctx->r14 == 0) {
        // 0x800C28EC: addiu       $a1, $zero, 0xC
        ctx->r5 = ADD32(0, 0XC);
            goto L_800C291C;
    }
    // 0x800C28EC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800C28F0: lhu         $a0, 0x0($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X0);
    // 0x800C28F4: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
L_800C28F8:
    // 0x800C28F8: beql        $at, $zero, L_800C290C
    if (ctx->r1 == 0) {
        // 0x800C28FC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800C290C;
    }
    goto skip_0;
    // 0x800C28FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800C2900: bnel        $a1, $a0, L_800C2910
    if (ctx->r5 != ctx->r4) {
        // 0x800C2904: lhu         $a0, 0x2($v0)
        ctx->r4 = MEM_HU(ctx->r2, 0X2);
            goto L_800C2910;
    }
    goto skip_1;
    // 0x800C2904: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
    skip_1:
    // 0x800C2908: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800C290C:
    // 0x800C290C: lhu         $a0, 0x2($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X2);
L_800C2910:
    // 0x800C2910: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C2914: bnel        $a0, $zero, L_800C28F8
    if (ctx->r4 != 0) {
        // 0x800C2918: slti        $at, $a0, 0x10
        ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
            goto L_800C28F8;
    }
    goto skip_2;
    // 0x800C2918: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    skip_2:
L_800C291C:
    // 0x800C291C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C2920: jr          $ra
    // 0x800C2924: nop

    return;
    // 0x800C2924: nop

;}
RECOMP_FUNC void func_effect_80081BEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081BEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80081BF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80081BF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80081BF8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80081BFC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80081C00: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80081C04: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80081C08: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80081C0C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80081C10:
    // 0x80081C10: bnel        $t6, $zero, L_80081C44
    if (ctx->r14 != 0) {
        // 0x80081C14: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80081C44;
    }
    goto skip_0;
    // 0x80081C14: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80081C18: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80081C1C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80081C20: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80081C24: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80081C28: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80081C2C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80081C30: jal         0x8008165C
    // 0x80081C34: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_effect_8008165C(rdram, ctx);
        goto after_0;
    // 0x80081C34: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_0:
    // 0x80081C38: b           L_80081C50
    // 0x80081C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80081C50;
    // 0x80081C3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80081C40: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80081C44:
    // 0x80081C44: bnel        $a0, $v0, L_80081C10
    if (ctx->r4 != ctx->r2) {
        // 0x80081C48: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80081C10;
    }
    goto skip_1;
    // 0x80081C48: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80081C4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80081C50:
    // 0x80081C50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80081C54: jr          $ra
    // 0x80081C58: nop

    return;
    // 0x80081C58: nop

;}
RECOMP_FUNC void Display_Unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053B00: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80053B04: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
    // 0x80053B08: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80053B0C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80053B10: jr          $ra
    // 0x80053B14: nop

    return;
    // 0x80053B14: nop

;}
RECOMP_FUNC void __roundf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FF08: round.w.s   $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.u32l = lroundf(ctx->f12.fl);
    // 0x8001FF0C: jr          $ra
    // 0x8001FF10: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
    return;
    // 0x8001FF10: cvt.s.w     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = CVT_S_W(ctx->f12.u32l);
;}
RECOMP_FUNC void Object_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060714: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80060718: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006071C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80060720: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80060724: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80060728: sh          $t6, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r14;
    // 0x8006072C: jal         0x8005FB70
    // 0x80060730: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Object_DrawAll(rdram, ctx);
        goto after_0;
    // 0x80060730: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80060734: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80060738: lw          $t7, 0x1A88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A88);
    // 0x8006073C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80060740: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060744: bnel        $v0, $t7, L_80060890
    if (ctx->r2 != ctx->r15) {
        // 0x80060748: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80060890;
    }
    goto skip_0;
    // 0x80060748: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8006074C: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80060750: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80060754: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80060758: lw          $t9, 0x1C8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C8);
    // 0x8006075C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80060760: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060764: beq         $v0, $t9, L_8006088C
    if (ctx->r2 == ctx->r25) {
        // 0x80060768: lui         $t0, 0x8018
        ctx->r8 = S32(0X8018 << 16);
            goto L_8006088C;
    }
    // 0x80060768: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006076C: lw          $t0, -0x7B20($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7B20);
    // 0x80060770: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80060774: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80060778: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006077C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80060780: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80060784: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80060788: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8006078C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80060790: lw          $t6, -0x7AA4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7AA4);
    // 0x80060794: lw          $t5, -0x7AA8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7AA8);
    // 0x80060798: lw          $t4, -0x7AAC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7AAC);
    // 0x8006079C: lw          $t3, -0x7AB0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7AB0);
    // 0x800607A0: lw          $t2, -0x7AB4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AB4);
    // 0x800607A4: lw          $t1, -0x7AB8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AB8);
    // 0x800607A8: mflo        $a2
    ctx->r6 = lo;
    // 0x800607AC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800607B0: sh          $v0, 0x1410($at)
    MEM_H(0X1410, ctx->r1) = ctx->r2;
    // 0x800607B4: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x800607B8: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x800607BC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800607C0: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800607C4: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800607C8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800607CC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800607D0: jal         0x8000372C
    // 0x800607D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    Lights_SetOneLight(rdram, ctx);
        goto after_1;
    // 0x800607D4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_1:
    // 0x800607D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800607DC: jal         0x80005708
    // 0x800607E0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x800607E0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x800607E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800607E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800607EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800607F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800607F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800607F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800607FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80060800: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80060804: jal         0x80005C34
    // 0x80060808: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x80060808: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_3:
    // 0x8006080C: jal         0x8005FB70
    // 0x80060810: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    Object_DrawAll(rdram, ctx);
        goto after_4;
    // 0x80060810: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_4:
    // 0x80060814: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80060818: jal         0x80005740
    // 0x8006081C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x8006081C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x80060820: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80060824: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80060828: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006082C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80060830: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80060834: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80060838: lw          $t3, -0x7AA4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7AA4);
    // 0x8006083C: lw          $t2, -0x7AA8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7AA8);
    // 0x80060840: lw          $t1, -0x7AAC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7AAC);
    // 0x80060844: lw          $t0, -0x7AB0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7AB0);
    // 0x80060848: lw          $t9, -0x7AB4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7AB4);
    // 0x8006084C: lw          $t8, -0x7AB8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7AB8);
    // 0x80060850: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80060854: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80060858: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8006085C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80060860: lw          $a3, -0x7B1C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7B1C);
    // 0x80060864: lw          $a2, -0x7B20($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7B20);
    // 0x80060868: lw          $a1, -0x7B24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7B24);
    // 0x8006086C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80060870: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80060874: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80060878: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8006087C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80060880: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80060884: jal         0x8000372C
    // 0x80060888: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    Lights_SetOneLight(rdram, ctx);
        goto after_6;
    // 0x80060888: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_6:
L_8006088C:
    // 0x8006088C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80060890:
    // 0x80060890: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80060894: jr          $ra
    // 0x80060898: nop

    return;
    // 0x80060898: nop

;}
RECOMP_FUNC void Play_dummy_MuteSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3FB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A3FB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800A3FB8: swc1        $f4, 0x2F64($at)
    MEM_W(0X2F64, ctx->r1) = ctx->f4.u32l;
    // 0x800A3FBC: jr          $ra
    // 0x800A3FC0: nop

    return;
    // 0x800A3FC0: nop

;}
RECOMP_FUNC void Cutscene_CoComplete_SetupClouds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004A888: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004A88C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004A890: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8004A894: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004A898: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8004A89C: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8004A8A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004A8A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A8A8: lwc1        $f4, 0xE8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x8004A8AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A8B0: lwc1        $f10, 0x5928($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5928);
    // 0x8004A8B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004A8B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004A8BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004A8C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8004A8C4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004A8C8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8004A8CC: jal         0x80005E90
    // 0x8004A8D0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8004A8D0: nop

    after_0:
    // 0x8004A8D4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8004A8D8: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8004A8DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A8E0: lwc1        $f4, 0x592C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X592C);
    // 0x8004A8E4: lwc1        $f18, 0xE4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XE4);
    // 0x8004A8E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004A8EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004A8F0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8004A8F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8004A8F8: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8004A8FC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8004A900: jal         0x80005D44
    // 0x8004A904: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8004A904: nop

    after_1:
    // 0x8004A908: jal         0x80061474
    // 0x8004A90C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_2;
    // 0x8004A90C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8004A910: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8004A914: jal         0x80004EB0
    // 0x8004A918: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8004A918: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    after_3:
    // 0x8004A91C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004A920: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004A924: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A928: lwc1        $f18, 0x5930($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5930);
    // 0x8004A92C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8004A930: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8004A934: jal         0x80004EB0
    // 0x8004A938: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8004A938: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8004A93C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004A940: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004A944: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8004A948: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004A94C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8004A950: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004A954: lwc1        $f18, 0x5934($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5934);
    // 0x8004A958: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004A95C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8004A960: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004A964: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8004A968: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8004A96C: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x8004A970: jal         0x80006970
    // 0x8004A974: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x8004A974: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x8004A978: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8004A97C: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x8004A980: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8004A984: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004A988: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8004A98C: lwc1        $f4, 0x74($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X74);
    // 0x8004A990: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x8004A994: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8004A998: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004A99C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8004A9A0: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8004A9A4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8004A9A8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8004A9AC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004A9B0: lwc1        $f10, 0x78($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8004A9B4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8004A9B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004A9BC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8004A9C0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8004A9C4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004A9C8: lwc1        $f4, 0x7C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X7C);
    // 0x8004A9CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004A9D0: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8004A9D4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8004A9D8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8004A9DC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8004A9E0: jal         0x80006970
    // 0x8004A9E4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8004A9E4: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8004A9E8: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8004A9EC: addiu       $t2, $zero, 0x160
    ctx->r10 = ADD32(0, 0X160);
    // 0x8004A9F0: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x8004A9F4: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x8004A9F8: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8004A9FC: addiu       $t4, $zero, 0x90
    ctx->r12 = ADD32(0, 0X90);
    // 0x8004AA00: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x8004AA04: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8004AA08: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x8004AA0C: sh          $t3, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r11;
    // 0x8004AA10: sh          $t4, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r12;
    // 0x8004AA14: jal         0x80004EB0
    // 0x8004AA18: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8004AA18: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    after_7:
    // 0x8004AA1C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8004AA20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004AA24: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004AA28: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004AA2C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004AA30: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8004AA34: jal         0x80004EB0
    // 0x8004AA38: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8004AA38: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    after_8:
    // 0x8004AA3C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8004AA40: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004AA44: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8004AA48: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8004AA4C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8004AA50: nop

    // 0x8004AA54: bc1f        L_8004AA68
    if (!c1cs) {
        // 0x8004AA58: nop
    
            goto L_8004AA68;
    }
    // 0x8004AA58: nop

    // 0x8004AA5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004AA60: nop

    // 0x8004AA64: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
L_8004AA68:
    // 0x8004AA68: jal         0x800612B8
    // 0x8004AA6C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_9;
    // 0x8004AA6C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_9:
    // 0x8004AA70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004AA74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004AA78: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8004AA7C: jr          $ra
    // 0x8004AA80: nop

    return;
    // 0x8004AA80: nop

;}
RECOMP_FUNC void Effect_FlamePillar_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DED4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007DED8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007DEDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8007DEE0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8007DEE4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007DEE8: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8007DEEC: lh          $v0, 0x4E($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X4E);
    // 0x8007DEF0: beq         $v0, $zero, L_8007DF08
    if (ctx->r2 == 0) {
        // 0x8007DEF4: nop
    
            goto L_8007DF08;
    }
    // 0x8007DEF4: nop

    // 0x8007DEF8: beq         $v0, $at, L_8007DF84
    if (ctx->r2 == ctx->r1) {
        // 0x8007DEFC: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8007DF84;
    }
    // 0x8007DEFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007DF00: b           L_8007E008
    // 0x8007DF04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007E008;
    // 0x8007DF04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007DF08:
    // 0x8007DF08: jal         0x8005980C
    // 0x8007DF0C: lwc1        $f12, 0x70($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007DF0C: lwc1        $f12, 0x70($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X70);
    after_0:
    // 0x8007DF10: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8007DF14: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8007DF18: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x8007DF1C: lw          $t8, -0x7C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C28);
    // 0x8007DF20: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DF24: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8007DF28: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8007DF2C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8007DF30: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8007DF34: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8007DF38: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8007DF3C: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8007DF40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8007DF44: jal         0x800B9B38
    // 0x8007DF48: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    RCP_SetupDL_60(rdram, ctx);
        goto after_1;
    // 0x8007DF48: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8007DF4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007DF50: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8007DF54: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007DF58: lui         $t2, 0x401
    ctx->r10 = S32(0X401 << 16);
    // 0x8007DF5C: addiu       $t2, $t2, -0x7320
    ctx->r10 = ADD32(ctx->r10, -0X7320);
    // 0x8007DF60: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8007DF64: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8007DF68: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8007DF6C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8007DF70: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8007DF74: jal         0x800B8DD0
    // 0x8007DF78: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8007DF78: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_2:
    // 0x8007DF7C: b           L_8007E008
    // 0x8007DF80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8007E008;
    // 0x8007DF80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007DF84:
    // 0x8007DF84: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8007DF88: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007DF8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007DF90: lw          $a1, 0x6C($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X6C);
    // 0x8007DF94: lw          $a2, 0x70($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X70);
    // 0x8007DF98: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8007DF9C: jal         0x80005C34
    // 0x8007DFA0: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8007DFA0: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    after_3:
    // 0x8007DFA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007DFA8: jal         0x80006EB8
    // 0x8007DFAC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8007DFAC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_4:
    // 0x8007DFB0: jal         0x800B99C0
    // 0x8007DFB4: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_5;
    // 0x8007DFB4: nop

    after_5:
    // 0x8007DFB8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8007DFBC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8007DFC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007DFC4: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x8007DFC8: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x8007DFCC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8007DFD0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8007DFD4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007DFD8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007DFDC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007DFE0: lui         $t0, 0x401
    ctx->r8 = S32(0X401 << 16);
    // 0x8007DFE4: addiu       $t0, $t0, -0x7090
    ctx->r8 = ADD32(ctx->r8, -0X7090);
    // 0x8007DFE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007DFEC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007DFF0: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8007DFF4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007DFF8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8007DFFC: jal         0x800B8DD0
    // 0x8007E000: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x8007E000: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_6:
    // 0x8007E004: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007E008:
    // 0x8007E008: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007E00C: jr          $ra
    // 0x8007E010: nop

    return;
    // 0x8007E010: nop

;}
RECOMP_FUNC void Matrix_Mult(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005754: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80005758: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000575C: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80005760: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80005764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005768: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000576C: bne         $a2, $at, L_80005AE8
    if (ctx->r6 != ctx->r1) {
        // 0x80005770: nop
    
            goto L_80005AE8;
    }
    // 0x80005770: nop

    // 0x80005774: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80005778: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000577C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80005780: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005784: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80005788: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8000578C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005790: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80005794: lwc1        $f14, 0x30($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80005798: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8000579C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800057A0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800057A4: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800057A8: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800057AC: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800057B0: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800057B4: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800057B8: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800057BC: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800057C0: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800057C4: nop

    // 0x800057C8: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800057CC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800057D0: mul.s       $f16, $f12, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800057D4: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800057D8: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800057DC: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800057E0: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800057E4: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x800057E8: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800057EC: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800057F0: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800057F4: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800057F8: nop

    // 0x800057FC: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80005800: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80005804: mul.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80005808: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8000580C: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80005810: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80005814: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80005818: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x8000581C: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80005820: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80005824: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80005828: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8000582C: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80005830: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80005834: lwc1        $f2, 0x14($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80005838: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8000583C: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80005840: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005844: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80005848: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8000584C: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005850: lwc1        $f14, 0x34($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X34);
    // 0x80005854: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005858: swc1        $f18, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f18.u32l;
    // 0x8000585C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005860: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005864: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005868: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8000586C: nop

    // 0x80005870: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80005874: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80005878: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8000587C: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80005880: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80005884: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80005888: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8000588C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80005890: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80005894: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80005898: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8000589C: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800058A0: nop

    // 0x800058A4: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800058A8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800058AC: mul.s       $f16, $f12, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800058B0: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800058B4: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800058B8: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800058BC: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800058C0: swc1        $f18, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f18.u32l;
    // 0x800058C4: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800058C8: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800058CC: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800058D0: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800058D4: nop

    // 0x800058D8: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800058DC: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800058E0: mul.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800058E4: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800058E8: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800058EC: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800058F0: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800058F4: swc1        $f18, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f18.u32l;
    // 0x800058F8: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800058FC: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80005900: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80005904: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80005908: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000590C: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80005910: lwc1        $f2, 0x18($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80005914: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80005918: lwc1        $f12, 0x28($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8000591C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005920: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80005924: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80005928: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000592C: lwc1        $f14, 0x38($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80005930: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005934: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x80005938: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8000593C: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005940: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005944: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80005948: nop

    // 0x8000594C: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80005950: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80005954: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80005958: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8000595C: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80005960: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80005964: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80005968: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8000596C: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80005970: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80005974: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80005978: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8000597C: nop

    // 0x80005980: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80005984: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80005988: mul.s       $f16, $f12, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8000598C: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80005990: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80005994: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80005998: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8000599C: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800059A0: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800059A4: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800059A8: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800059AC: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800059B0: nop

    // 0x800059B4: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800059B8: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800059BC: mul.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800059C0: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800059C4: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800059C8: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800059CC: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800059D0: swc1        $f18, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f18.u32l;
    // 0x800059D4: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800059D8: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800059DC: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800059E0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800059E4: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800059E8: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800059EC: lwc1        $f2, 0x1C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800059F0: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x800059F4: lwc1        $f12, 0x2C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800059F8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800059FC: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80005A00: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80005A04: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005A08: lwc1        $f14, 0x3C($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x80005A0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005A10: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    // 0x80005A14: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80005A18: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80005A1C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80005A20: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80005A24: nop

    // 0x80005A28: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80005A2C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80005A30: mul.s       $f4, $f12, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80005A34: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80005A38: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80005A3C: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80005A40: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80005A44: swc1        $f18, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f18.u32l;
    // 0x80005A48: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80005A4C: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80005A50: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x80005A54: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80005A58: nop

    // 0x80005A5C: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80005A60: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80005A64: mul.s       $f16, $f12, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80005A68: lwc1        $f4, 0x1C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80005A6C: mul.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80005A70: add.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80005A74: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80005A78: swc1        $f18, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f18.u32l;
    // 0x80005A7C: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80005A80: lwc1        $f4, 0x24($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80005A84: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x80005A88: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80005A8C: nop

    // 0x80005A90: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80005A94: add.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80005A98: mul.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80005A9C: lwc1        $f16, 0x2C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80005AA0: mul.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80005AA4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80005AA8: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80005AAC: swc1        $f18, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f18.u32l;
    // 0x80005AB0: lwc1        $f6, 0x30($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80005AB4: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x80005AB8: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x80005ABC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80005AC0: nop

    // 0x80005AC4: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80005AC8: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80005ACC: mul.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x80005AD0: lwc1        $f8, 0x3C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x80005AD4: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80005AD8: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80005ADC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80005AE0: b           L_80005AF0
    // 0x80005AE4: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
        goto L_80005AF0;
    // 0x80005AE4: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
L_80005AE8:
    // 0x80005AE8: jal         0x80005680
    // 0x80005AEC: nop

    Matrix_Copy(rdram, ctx);
        goto after_0;
    // 0x80005AEC: nop

    after_0:
L_80005AF0:
    // 0x80005AF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005AF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80005AF8: jr          $ra
    // 0x80005AFC: nop

    return;
    // 0x80005AFC: nop

;}
RECOMP_FUNC void Audio_StopEventSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D3A0: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x8001D3A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001D3A8: lui         $a2, 0x800C
    ctx->r6 = S32(0X800C << 16);
    // 0x8001D3AC: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8001D3B0: lw          $a2, 0x5E88($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5E88);
    // 0x8001D3B4: lui         $at, 0xF000
    ctx->r1 = S32(0XF000 << 16);
    // 0x8001D3B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001D3BC: and         $t8, $a2, $at
    ctx->r24 = ctx->r6 & ctx->r1;
    // 0x8001D3C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001D3C8: beq         $t8, $at, L_8001D3E0
    if (ctx->r24 == ctx->r1) {
        // 0x8001D3CC: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8001D3E0;
    }
    // 0x8001D3CC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001D3D0: jal         0x8001A55C
    // 0x8001D3D4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_0;
    // 0x8001D3D4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8001D3D8: b           L_8001D3F4
    // 0x8001D3DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8001D3F4;
    // 0x8001D3DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001D3E0:
    // 0x8001D3E0: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x8001D3E4: addiu       $a0, $a0, 0x5D28
    ctx->r4 = ADD32(ctx->r4, 0X5D28);
    // 0x8001D3E8: jal         0x8001A55C
    // 0x8001D3EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_1;
    // 0x8001D3EC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
    // 0x8001D3F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001D3F4:
    // 0x8001D3F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001D3F8: jr          $ra
    // 0x8001D3FC: nop

    return;
    // 0x8001D3FC: nop

;}
