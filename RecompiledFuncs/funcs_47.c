#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void SectorY_SyShip3Destroyed_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4E44: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801A4E48: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801A4E4C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A4E50: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A4E54: lw          $t6, 0x48($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X48);
    // 0x801A4E58: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A4E5C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A4E60: bne         $t6, $zero, L_801A4E94
    if (ctx->r14 != 0) {
        // 0x801A4E64: lui         $a0, 0x1900
        ctx->r4 = S32(0X1900 << 16);
            goto L_801A4E94;
    }
    // 0x801A4E64: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801A4E68: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801A4E6C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x801A4E70: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801A4E74: ori         $a0, $a0, 0x404F
    ctx->r4 = ctx->r4 | 0X404F;
    // 0x801A4E78: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    // 0x801A4E7C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A4E80: jal         0x80019218
    // 0x801A4E84: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x801A4E84: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x801A4E88: lw          $t8, 0x48($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X48);
    // 0x801A4E8C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801A4E90: sw          $t9, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r25;
L_801A4E94:
    // 0x801A4E94: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801A4E98: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x801A4E9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A4EA0: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x801A4EA4: bnel        $t1, $zero, L_801A52A8
    if (ctx->r9 != 0) {
        // 0x801A4EA8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801A52A8;
    }
    goto skip_0;
    // 0x801A4EA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x801A4EAC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801A4EB0: lwc1        $f6, 0x7E8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7E8C);
    // 0x801A4EB4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4EB8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4EBC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A4EC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A4EC4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A4EC8: jal         0x80005E90
    // 0x801A4ECC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801A4ECC: nop

    after_1:
    // 0x801A4ED0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A4ED4: lwc1        $f16, 0x7E90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7E90);
    // 0x801A4ED8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801A4EDC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4EE0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4EE4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801A4EE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A4EEC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A4EF0: jal         0x80005D44
    // 0x801A4EF4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801A4EF4: nop

    after_2:
    // 0x801A4EF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A4EFC: lwc1        $f6, 0x7E94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7E94);
    // 0x801A4F00: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801A4F04: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4F08: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4F0C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A4F10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A4F14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A4F18: jal         0x80005FE0
    // 0x801A4F1C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801A4F1C: nop

    after_3:
    // 0x801A4F20: jal         0x80004EB0
    // 0x801A4F24: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801A4F24: nop

    after_4:
    // 0x801A4F28: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A4F2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4F30: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A4F34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A4F38: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801A4F3C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801A4F40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4F44: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A4F48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A4F4C: jal         0x80004EB0
    // 0x801A4F50: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801A4F50: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    after_5:
    // 0x801A4F54: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A4F58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4F5C: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x801A4F60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A4F64: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801A4F68: lui         $at, 0xC316
    ctx->r1 = S32(0XC316 << 16);
    // 0x801A4F6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4F70: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A4F74: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A4F78: jal         0x80004EB0
    // 0x801A4F7C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801A4F7C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x801A4F80: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801A4F84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4F88: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A4F8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4F90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4F94: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4F98: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801A4F9C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801A4FA0: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801A4FA4: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801A4FA8: jal         0x80006970
    // 0x801A4FAC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x801A4FAC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x801A4FB0: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A4FB4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A4FB8: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A4FBC: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A4FC0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A4FC4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A4FC8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A4FCC: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801A4FD0: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x801A4FD4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A4FD8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A4FDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A4FE0: add.s       $f14, $f16, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801A4FE4: lwc1        $f10, 0x7E98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7E98);
    // 0x801A4FE8: lwc1        $f16, 0x60($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801A4FEC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801A4FF0: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x801A4FF4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801A4FF8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801A4FFC: jal         0x8007C120
    // 0x801A5000: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_8;
    // 0x801A5000: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x801A5004: jal         0x80004EB0
    // 0x801A5008: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801A5008: nop

    after_9:
    // 0x801A500C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A5010: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A5014: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A5018: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A501C: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801A5020: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x801A5024: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A5028: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A502C: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801A5030: jal         0x80004EB0
    // 0x801A5034: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801A5034: swc1        $f10, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x801A5038: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A503C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A5040: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x801A5044: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A5048: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801A504C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A5050: jal         0x80004EB0
    // 0x801A5054: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x801A5054: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x801A5058: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801A505C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A5060: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A5064: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5068: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A506C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A5070: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801A5074: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801A5078: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801A507C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A5080: jal         0x80006970
    // 0x801A5084: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x801A5084: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_12:
    // 0x801A5088: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A508C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A5090: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A5094: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A5098: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A509C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A50A0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A50A4: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801A50A8: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x801A50AC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A50B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A50B4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A50B8: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A50BC: lwc1        $f16, 0x7E9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7E9C);
    // 0x801A50C0: lwc1        $f10, 0x60($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801A50C4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801A50C8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x801A50CC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801A50D0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801A50D4: jal         0x8007C120
    // 0x801A50D8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_13;
    // 0x801A50D8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x801A50DC: jal         0x80004EB0
    // 0x801A50E0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x801A50E0: nop

    after_14:
    // 0x801A50E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A50E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A50EC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A50F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A50F4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801A50F8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801A50FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5100: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A5104: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A5108: jal         0x80004EB0
    // 0x801A510C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x801A510C: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_15:
    // 0x801A5110: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A5114: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A5118: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x801A511C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A5120: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801A5124: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x801A5128: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A512C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A5130: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A5134: jal         0x80004EB0
    // 0x801A5138: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x801A5138: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    after_16:
    // 0x801A513C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A5140: lwc1        $f18, 0x7EA0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7EA0);
    // 0x801A5144: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A5148: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A514C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5150: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A5154: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801A5158: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801A515C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801A5160: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801A5164: jal         0x80006970
    // 0x801A5168: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_17;
    // 0x801A5168: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    after_17:
    // 0x801A516C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A5170: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A5174: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A5178: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A517C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A5180: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A5184: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A5188: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801A518C: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x801A5190: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A5194: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A5198: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801A519C: add.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801A51A0: lwc1        $f18, 0x7EA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7EA4);
    // 0x801A51A4: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801A51A8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801A51AC: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x801A51B0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x801A51B4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801A51B8: jal         0x8007C120
    // 0x801A51BC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_18;
    // 0x801A51BC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_18:
    // 0x801A51C0: jal         0x80004EB0
    // 0x801A51C4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x801A51C4: nop

    after_19:
    // 0x801A51C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A51CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A51D0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A51D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A51D8: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801A51DC: lui         $at, 0xC47A
    ctx->r1 = S32(0XC47A << 16);
    // 0x801A51E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A51E4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A51E8: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801A51EC: jal         0x80004EB0
    // 0x801A51F0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x801A51F0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x801A51F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A51F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A51FC: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x801A5200: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A5204: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801A5208: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x801A520C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A5210: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A5214: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801A5218: jal         0x80004EB0
    // 0x801A521C: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x801A521C: swc1        $f18, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f18.u32l;
    after_21:
    // 0x801A5220: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A5224: lwc1        $f6, 0x7EA8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7EA8);
    // 0x801A5228: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A522C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A5230: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5234: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A5238: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801A523C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801A5240: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801A5244: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801A5248: jal         0x80006970
    // 0x801A524C: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_22;
    // 0x801A524C: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_22:
    // 0x801A5250: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A5254: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A5258: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A525C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A5260: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A5264: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A5268: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801A526C: lwc1        $f18, 0x5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801A5270: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x801A5274: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A5278: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A527C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801A5280: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801A5284: lwc1        $f6, 0x7EAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7EAC);
    // 0x801A5288: lwc1        $f8, 0x60($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801A528C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801A5290: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x801A5294: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x801A5298: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801A529C: jal         0x8007C120
    // 0x801A52A0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_23;
    // 0x801A52A0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_23:
    // 0x801A52A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801A52A8:
    // 0x801A52A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801A52AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801A52B0: jr          $ra
    // 0x801A52B4: nop

    return;
    // 0x801A52B4: nop

;}
RECOMP_FUNC void SectorY_8019A640(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A640: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019A644: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8019A648: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8019A64C: sh          $t6, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r14;
    // 0x8019A650: sh          $zero, 0xB2($a0)
    MEM_H(0XB2, ctx->r4) = 0;
    // 0x8019A654: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x8019A658: swc1        $f0, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f0.u32l;
    // 0x8019A65C: swc1        $f0, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f0.u32l;
    // 0x8019A660: sh          $t7, 0x56($a0)
    MEM_H(0X56, ctx->r4) = ctx->r15;
    // 0x8019A664: jr          $ra
    // 0x8019A668: nop

    return;
    // 0x8019A668: nop

;}
RECOMP_FUNC void SectorY_SyShogun_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019DE10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8019DE14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019DE18: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8019DE1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019DE20: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8019DE24: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8019DE28: addiu       $t7, $t7, 0x694C
    ctx->r15 = ADD32(ctx->r15, 0X694C);
    // 0x8019DE2C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8019DE30: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x8019DE34: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8019DE38: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8019DE3C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8019DE40: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8019DE44: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8019DE48: lw          $t1, 0x40($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X40);
    // 0x8019DE4C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8019DE50: beql        $t1, $zero, L_8019DE6C
    if (ctx->r9 == 0) {
        // 0x8019DE54: lh          $t2, 0x5C($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X5C);
            goto L_8019DE6C;
    }
    goto skip_0;
    // 0x8019DE54: lh          $t2, 0x5C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X5C);
    skip_0:
    // 0x8019DE58: jal         0x8019DC4C
    // 0x8019DE5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    SectorY_8019DC4C(rdram, ctx);
        goto after_0;
    // 0x8019DE5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8019DE60: b           L_8019E004
    // 0x8019DE64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8019E004;
    // 0x8019DE64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019DE68: lh          $t2, 0x5C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X5C);
L_8019DE6C:
    // 0x8019DE6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019DE70: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019DE74: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8019DE78: beq         $t3, $zero, L_8019DEB0
    if (ctx->r11 == 0) {
        // 0x8019DE7C: lui         $a2, 0xFA00
        ctx->r6 = S32(0XFA00 << 16);
            goto L_8019DEB0;
    }
    // 0x8019DE7C: lui         $a2, 0xFA00
    ctx->r6 = S32(0XFA00 << 16);
    // 0x8019DE80: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019DE84: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019DE88: lui         $a2, 0xFA00
    ctx->r6 = S32(0XFA00 << 16);
    // 0x8019DE8C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019DE90: lui         $t5, 0x2020
    ctx->r13 = S32(0X2020 << 16);
    // 0x8019DE94: ori         $t5, $t5, 0xFFFF
    ctx->r13 = ctx->r13 | 0XFFFF;
    // 0x8019DE98: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019DE9C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8019DEA0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8019DEA4: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8019DEA8: b           L_8019DECC
    // 0x8019DEAC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
        goto L_8019DECC;
    // 0x8019DEAC: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_8019DEB0:
    // 0x8019DEB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019DEB4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8019DEB8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019DEBC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8019DEC0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019DEC4: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8019DEC8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_8019DECC:
    // 0x8019DECC: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x8019DED0: sltiu       $at, $t7, 0x11
    ctx->r1 = ctx->r15 < 0X11 ? 1 : 0;
    // 0x8019DED4: beq         $at, $zero, L_8019DFFC
    if (ctx->r1 == 0) {
        // 0x8019DED8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8019DFFC;
    }
    // 0x8019DED8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8019DEDC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019DEE0: addu        $at, $at, $t7
    gpr jr_addend_8019DEE8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8019DEE4: lw          $t7, 0x7740($at)
    ctx->r15 = ADD32(ctx->r1, 0X7740);
    // 0x8019DEE8: jr          $t7
    // 0x8019DEEC: nop

    switch (jr_addend_8019DEE8 >> 2) {
        case 0: goto L_8019DEF0; break;
        case 1: goto L_8019DF24; break;
        case 2: goto L_8019DF58; break;
        case 3: goto L_8019DFFC; break;
        case 4: goto L_8019DFFC; break;
        case 5: goto L_8019DFFC; break;
        case 6: goto L_8019DFFC; break;
        case 7: goto L_8019DFFC; break;
        case 8: goto L_8019DFFC; break;
        case 9: goto L_8019DFFC; break;
        case 10: goto L_8019DFFC; break;
        case 11: goto L_8019DFFC; break;
        case 12: goto L_8019DFFC; break;
        case 13: goto L_8019DFFC; break;
        case 14: goto L_8019DFFC; break;
        case 15: goto L_8019DFAC; break;
        case 16: goto L_8019DFDC; break;
        default: switch_error(__func__, 0x8019DEE8, 0x801A7740);
    }
    // 0x8019DEEC: nop

L_8019DEF0:
    // 0x8019DEF0: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019DEF4: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8019DEF8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019DEFC: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8019DF00: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8019DF04: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019DF08: lwc1        $f16, 0x118($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8019DF0C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019DF10: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8019DF14: lwc1        $f6, 0x11C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8019DF18: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019DF1C: b           L_8019DFFC
    // 0x8019DF20: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
        goto L_8019DFFC;
    // 0x8019DF20: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
L_8019DF24:
    // 0x8019DF24: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019DF28: lwc1        $f16, 0xE8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8019DF2C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019DF30: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8019DF34: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8019DF38: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019DF3C: lwc1        $f6, 0x110($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8019DF40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DF44: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8019DF48: lwc1        $f16, 0x114($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019DF4C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019DF50: b           L_8019DFFC
    // 0x8019DF54: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
        goto L_8019DFFC;
    // 0x8019DF54: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_8019DF58:
    // 0x8019DF58: lh          $t0, 0xBA($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XBA);
    // 0x8019DF5C: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x8019DF60: addiu       $t1, $t1, 0x3600
    ctx->r9 = ADD32(ctx->r9, 0X3600);
    // 0x8019DF64: bne         $t0, $zero, L_8019DFA4
    if (ctx->r8 != 0) {
        // 0x8019DF68: nop
    
            goto L_8019DFA4;
    }
    // 0x8019DF68: nop

    // 0x8019DF6C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x8019DF70: lh          $t2, 0xB8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0XB8);
    // 0x8019DF74: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8019DF78: beql        $t3, $zero, L_8019E000
    if (ctx->r11 == 0) {
        // 0x8019DF7C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8019E000;
    }
    goto skip_1;
    // 0x8019DF7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8019DF80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019DF84: lui         $t5, 0xFF
    ctx->r13 = S32(0XFF << 16);
    // 0x8019DF88: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x8019DF8C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019DF90: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x8019DF94: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8019DF98: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8019DF9C: b           L_8019E000
    // 0x8019DFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8019E000;
    // 0x8019DFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019DFA4:
    // 0x8019DFA4: b           L_8019DFFC
    // 0x8019DFA8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_8019DFFC;
    // 0x8019DFA8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8019DFAC:
    // 0x8019DFAC: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8019DFB0: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8019DFB4: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8019DFB8: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x8019DFBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DFC0: addiu       $t9, $t9, 0x4BD0
    ctx->r25 = ADD32(ctx->r25, 0X4BD0);
    // 0x8019DFC4: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8019DFC8: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8019DFCC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019DFD0: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x8019DFD4: b           L_8019DFFC
    // 0x8019DFD8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_8019DFFC;
    // 0x8019DFD8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_8019DFDC:
    // 0x8019DFDC: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8019DFE0: lwc1        $f6, 0xF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019DFE4: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8019DFE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DFEC: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8019DFF0: lwc1        $f16, 0xEC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8019DFF4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019DFF8: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
L_8019DFFC:
    // 0x8019DFFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019E000:
    // 0x8019E000: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019E004:
    // 0x8019E004: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019E008: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8019E00C: jr          $ra
    // 0x8019E010: nop

    return;
    // 0x8019E010: nop

;}
RECOMP_FUNC void Andross_AndPassage_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019366C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80193670: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80193674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80193678: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8019367C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80193680: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80193684: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80193688: jal         0x80061364
    // 0x8019368C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Scenery_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019368C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80193690: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80193694: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80193698: addiu       $t7, $zero, 0x83
    ctx->r15 = ADD32(0, 0X83);
    // 0x8019369C: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801936A0: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801936A4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801936A8: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x801936AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801936B0: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801936B4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801936B8: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x801936BC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801936C0: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801936C4: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801936C8: swc1        $f10, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f10.u32l;
    // 0x801936CC: jal         0x800612B8
    // 0x801936D0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801936D0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x801936D4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x801936D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801936DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801936E0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801936E4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801936E8: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801936EC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801936F0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x801936F4: addiu       $t0, $t9, 0x64
    ctx->r8 = ADD32(ctx->r25, 0X64);
    // 0x801936F8: sw          $t0, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->r8;
    // 0x801936FC: lwc1        $f16, 0x7324($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7324);
    // 0x80193700: swc1        $f16, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->f16.u32l;
    // 0x80193704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80193708: jr          $ra
    // 0x8019370C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8019370C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void SectorY_8019B5CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B5CC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8019B5D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019B5D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019B5D8: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8019B5DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019B5E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019B5E4: lh          $t6, 0x468($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X468);
    // 0x8019B5E8: bne         $t6, $zero, L_8019B600
    if (ctx->r14 != 0) {
        // 0x8019B5EC: nop
    
            goto L_8019B600;
    }
    // 0x8019B5EC: nop

    // 0x8019B5F0: lh          $t7, 0x870($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X870);
    // 0x8019B5F4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019B5F8: beq         $t7, $zero, L_8019B608
    if (ctx->r15 == 0) {
        // 0x8019B5FC: nop
    
            goto L_8019B608;
    }
    // 0x8019B5FC: nop

L_8019B600:
    // 0x8019B600: b           L_8019B6D4
    // 0x8019B604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8019B6D4;
    // 0x8019B604: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019B608:
    // 0x8019B608: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x8019B60C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8019B610: lui         $a3, 0x442F
    ctx->r7 = S32(0X442F << 16);
    // 0x8019B614: bnel        $t8, $zero, L_8019B628
    if (ctx->r24 != 0) {
        // 0x8019B618: lw          $a1, 0x78($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X78);
            goto L_8019B628;
    }
    goto skip_0;
    // 0x8019B618: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    skip_0:
    // 0x8019B61C: b           L_8019B6D4
    // 0x8019B620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8019B6D4;
    // 0x8019B620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019B624: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
L_8019B628:
    // 0x8019B628: jal         0x8009F6CC
    // 0x8019B62C: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    Math_Vec3fFromAngles(rdram, ctx);
        goto after_0;
    // 0x8019B62C: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    after_0:
    // 0x8019B630: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019B634: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019B638: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019B63C: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
    // 0x8019B640: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019B644: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B648: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019B64C: lwc1        $f16, 0x75F8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X75F8);
    // 0x8019B650: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019B654: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8019B658: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019B65C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8019B660: nop

    // 0x8019B664: bc1fl       L_8019B6D4
    if (!c1cs) {
        // 0x8019B668: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8019B6D4;
    }
    goto skip_1;
    // 0x8019B668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8019B66C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019B670: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8019B674: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B678: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019B67C: lwc1        $f8, 0x75FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75FC);
    // 0x8019B680: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019B684: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8019B688: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019B68C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8019B690: nop

    // 0x8019B694: bc1fl       L_8019B6D4
    if (!c1cs) {
        // 0x8019B698: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8019B6D4;
    }
    goto skip_2;
    // 0x8019B698: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8019B69C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019B6A0: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019B6A4: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x8019B6A8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019B6AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B6B0: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8019B6B4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019B6B8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8019B6BC: nop

    // 0x8019B6C0: bc1fl       L_8019B6D4
    if (!c1cs) {
        // 0x8019B6C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8019B6D4;
    }
    goto skip_3;
    // 0x8019B6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x8019B6C8: b           L_8019B6D4
    // 0x8019B6CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8019B6D4;
    // 0x8019B6CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8019B6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019B6D4:
    // 0x8019B6D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019B6D8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8019B6DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8019B6E0: jr          $ra
    // 0x8019B6E4: nop

    return;
    // 0x8019B6E4: nop

;}
RECOMP_FUNC void SectorY_SyRobotLaser_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A07FC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801A0800: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801A0804: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A0808: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801A080C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801A0810: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A0814: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801A0818: jal         0x800613C4
    // 0x801A081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801A081C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801A0820: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801A0824: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x801A0828: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x801A082C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x801A0830: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A0834: lwc1        $f4, 0x79B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79B4);
    // 0x801A0838: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x801A083C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A0840: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801A0844: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A0848: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A084C: swc1        $f4, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f4.u32l;
    // 0x801A0850: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A0854: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x801A0858: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x801A085C: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x801A0860: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x801A0864: lwc1        $f18, 0x79B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x801A0868: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801A086C: addiu       $s2, $s2, -0x4438
    ctx->r18 = ADD32(ctx->r18, -0X4438);
    // 0x801A0870: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A0874: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801A0878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A087C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A0880: jal         0x80005E90
    // 0x801A0884: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801A0884: nop

    after_1:
    // 0x801A0888: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A088C: lwc1        $f8, 0x79BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79BC);
    // 0x801A0890: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x801A0894: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801A0898: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A089C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A08A0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A08A4: jal         0x80005D44
    // 0x801A08A8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801A08A8: nop

    after_2:
    // 0x801A08AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A08B0: lwc1        $f18, 0x79C0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x801A08B4: lwc1        $f16, 0x18($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X18);
    // 0x801A08B8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801A08BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A08C0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A08C4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A08C8: jal         0x80005FE0
    // 0x801A08CC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801A08CC: nop

    after_3:
    // 0x801A08D0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801A08D4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801A08D8: jal         0x80006970
    // 0x801A08DC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x801A08DC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_4:
    // 0x801A08E0: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A08E4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A08E8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801A08EC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801A08F0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A08F4: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x801A08F8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A08FC: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A0900: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A0904: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801A0908: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A090C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A0910: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A0914: jal         0x800612B8
    // 0x801A0918: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x801A0918: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x801A091C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A0920: lwc1        $f18, 0x79C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79C4);
    // 0x801A0924: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x801A0928: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801A092C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A0930: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A0934: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A0938: jal         0x80005E90
    // 0x801A093C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x801A093C: nop

    after_6:
    // 0x801A0940: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A0944: lwc1        $f8, 0x79C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C8);
    // 0x801A0948: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x801A094C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801A0950: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A0954: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A0958: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A095C: jal         0x80005D44
    // 0x801A0960: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x801A0960: nop

    after_7:
    // 0x801A0964: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A0968: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801A096C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A0970: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801A0974: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801A0978: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801A097C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801A0980: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x801A0984: jal         0x80006970
    // 0x801A0988: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x801A0988: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_8:
    // 0x801A098C: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x801A0990: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
    // 0x801A0994: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A0998: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A099C: addiu       $t9, $zero, 0x2A
    ctx->r25 = ADD32(0, 0X2A);
    // 0x801A09A0: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x801A09A4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A09A8: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801A09AC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A09B0: swc1        $f4, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f4.u32l;
    // 0x801A09B4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A09B8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x801A09BC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x801A09C0: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x801A09C4: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x801A09C8: ori         $a0, $a0, 0x306B
    ctx->r4 = ctx->r4 | 0X306B;
    // 0x801A09CC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801A09D0: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x801A09D4: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x801A09D8: sh          $t9, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r25;
    // 0x801A09DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A09E0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x801A09E4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801A09E8: jal         0x80019218
    // 0x801A09EC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x801A09EC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_9:
    // 0x801A09F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801A09F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A09F8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801A09FC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801A0A00: jr          $ra
    // 0x801A0A04: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801A0A04: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Andross_AndAndross_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D16C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D170: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D174: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018D178: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D17C: jal         0x8001D400
    // 0x8018D180: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_0;
    // 0x8018D180: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_0:
    // 0x8018D184: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018D188: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x8018D18C: addiu       $v0, $v0, -0x7BD0
    ctx->r2 = ADD32(ctx->r2, -0X7BD0);
    // 0x8018D190: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8018D194: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018D198: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8018D19C: addiu       $v1, $v1, 0x7F7C
    ctx->r3 = ADD32(ctx->r3, 0X7F7C);
    // 0x8018D1A0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8018D1A4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018D1A8: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8018D1AC: addiu       $t0, $t0, 0x7F74
    ctx->r8 = ADD32(ctx->r8, 0X7F74);
    // 0x8018D1B0: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x8018D1B4: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8018D1B8: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8018D1BC: addiu       $t1, $t1, 0x7F6C
    ctx->r9 = ADD32(ctx->r9, 0X7F6C);
    // 0x8018D1C0: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x8018D1C4: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018D1C8: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8018D1CC: addiu       $t2, $t2, 0x7F64
    ctx->r10 = ADD32(ctx->r10, 0X7F64);
    // 0x8018D1D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D1D4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018D1D8: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x8018D1DC: lwc1        $f16, 0x0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8018D1E0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018D1E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018D1E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D1EC: swc1        $f16, 0x7F5C($at)
    MEM_W(0X7F5C, ctx->r1) = ctx->f16.u32l;
    // 0x8018D1F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8018D1F4: swc1        $f0, -0x63D0($at)
    MEM_W(-0X63D0, ctx->r1) = ctx->f0.u32l;
    // 0x8018D1F8: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x8018D1FC: sh          $t3, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r11;
    // 0x8018D200: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D204: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8018D208: swc1        $f2, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f2.u32l;
    // 0x8018D20C: swc1        $f2, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f2.u32l;
    // 0x8018D210: sw          $t6, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r14;
    // 0x8018D214: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D218: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018D21C: sw          $t7, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r15;
    // 0x8018D220: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8018D224: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D228: sw          $t4, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r12;
    // 0x8018D22C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018D230: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D234: sw          $t5, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r13;
    // 0x8018D238: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D23C: sw          $zero, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = 0;
    // 0x8018D240: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D244: sw          $t4, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r12;
    // 0x8018D248: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8018D24C: sh          $t9, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r25;
    // 0x8018D250: lh          $t6, 0x92($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X92);
    // 0x8018D254: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8018D258: sh          $t8, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r24;
    // 0x8018D25C: sh          $t3, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r11;
    // 0x8018D260: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018D264: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
    // 0x8018D268: sw          $t5, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = ctx->r13;
    // 0x8018D26C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018D270: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D274: sb          $t7, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = ctx->r15;
    // 0x8018D278: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x8018D27C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D280: ori         $a1, $zero, 0x8021
    ctx->r5 = 0 | 0X8021;
    // 0x8018D284: swc1        $f12, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f12.u32l;
    // 0x8018D288: lw          $t9, 0x28($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X28);
    // 0x8018D28C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018D290: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8018D294: jal         0x8001D444
    // 0x8018D298: swc1        $f12, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f12.u32l;
    Audio_PlaySequence(rdram, ctx);
        goto after_1;
    // 0x8018D298: swc1        $f12, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->f12.u32l;
    after_1:
    // 0x8018D29C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D2A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D2A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D2A8: jr          $ra
    // 0x8018D2AC: nop

    return;
    // 0x8018D2AC: nop

;}
RECOMP_FUNC void SectorY_8019DC4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019DC4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019DC50: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8019DC54: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8019DC58: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8019DC5C: addiu       $t7, $t7, 0x6940
    ctx->r15 = ADD32(ctx->r15, 0X6940);
    // 0x8019DC60: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8019DC64: addiu       $t6, $sp, 0x10
    ctx->r14 = ADD32(ctx->r29, 0X10);
    // 0x8019DC68: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x8019DC6C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8019DC70: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8019DC74: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8019DC78: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8019DC7C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8019DC80: lh          $t2, 0x5C($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X5C);
    // 0x8019DC84: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x8019DC88: lui         $t4, 0x2020
    ctx->r12 = S32(0X2020 << 16);
    // 0x8019DC8C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8019DC90: bne         $t3, $zero, L_8019DD04
    if (ctx->r11 != 0) {
        // 0x8019DC94: nop
    
            goto L_8019DD04;
    }
    // 0x8019DC94: nop

    // 0x8019DC98: lw          $t4, 0x40($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X40);
    // 0x8019DC9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019DCA0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8019DCA4: bne         $t4, $at, L_8019DCDC
    if (ctx->r12 != ctx->r1) {
        // 0x8019DCA8: addiu       $t0, $t0, 0x7E64
        ctx->r8 = ADD32(ctx->r8, 0X7E64);
            goto L_8019DCDC;
    }
    // 0x8019DCA8: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x8019DCAC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8019DCB0: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x8019DCB4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8019DCB8: lui         $t8, 0x6464
    ctx->r24 = S32(0X6464 << 16);
    // 0x8019DCBC: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x8019DCC0: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8019DCC4: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x8019DCC8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8019DCCC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8019DCD0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8019DCD4: b           L_8019DD24
    // 0x8019DCD8: addiu       $t5, $a0, -0x2
    ctx->r13 = ADD32(ctx->r4, -0X2);
        goto L_8019DD24;
    // 0x8019DCD8: addiu       $t5, $a0, -0x2
    ctx->r13 = ADD32(ctx->r4, -0X2);
L_8019DCDC:
    // 0x8019DCDC: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8019DCE0: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x8019DCE4: ori         $t1, $t1, 0x64FF
    ctx->r9 = ctx->r9 | 0X64FF;
    // 0x8019DCE8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8019DCEC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8019DCF0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8019DCF4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019DCF8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8019DCFC: b           L_8019DD24
    // 0x8019DD00: addiu       $t5, $a0, -0x2
    ctx->r13 = ADD32(ctx->r4, -0X2);
        goto L_8019DD24;
    // 0x8019DD00: addiu       $t5, $a0, -0x2
    ctx->r13 = ADD32(ctx->r4, -0X2);
L_8019DD04:
    // 0x8019DD04: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8019DD08: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8019DD0C: ori         $t4, $t4, 0xFFFF
    ctx->r12 = ctx->r12 | 0XFFFF;
    // 0x8019DD10: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8019DD14: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8019DD18: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8019DD1C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8019DD20: addiu       $t5, $a0, -0x2
    ctx->r13 = ADD32(ctx->r4, -0X2);
L_8019DD24:
    // 0x8019DD24: sltiu       $at, $t5, 0x11
    ctx->r1 = ctx->r13 < 0X11 ? 1 : 0;
    // 0x8019DD28: beq         $at, $zero, L_8019DE04
    if (ctx->r1 == 0) {
        // 0x8019DD2C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8019DE04;
    }
    // 0x8019DD2C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019DD30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019DD34: addu        $at, $at, $t5
    gpr jr_addend_8019DD3C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8019DD38: lw          $t5, 0x76FC($at)
    ctx->r13 = ADD32(ctx->r1, 0X76FC);
    // 0x8019DD3C: jr          $t5
    // 0x8019DD40: nop

    switch (jr_addend_8019DD3C >> 2) {
        case 0: goto L_8019DD44; break;
        case 1: goto L_8019DD78; break;
        case 2: goto L_8019DDAC; break;
        case 3: goto L_8019DE04; break;
        case 4: goto L_8019DE04; break;
        case 5: goto L_8019DE04; break;
        case 6: goto L_8019DE04; break;
        case 7: goto L_8019DE04; break;
        case 8: goto L_8019DE04; break;
        case 9: goto L_8019DE04; break;
        case 10: goto L_8019DE04; break;
        case 11: goto L_8019DE04; break;
        case 12: goto L_8019DE04; break;
        case 13: goto L_8019DE04; break;
        case 14: goto L_8019DE04; break;
        case 15: goto L_8019DDB4; break;
        case 16: goto L_8019DDE4; break;
        default: switch_error(__func__, 0x8019DD3C, 0x801A76FC);
    }
    // 0x8019DD40: nop

L_8019DD44:
    // 0x8019DD44: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019DD48: lwc1        $f6, 0xE8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XE8);
    // 0x8019DD4C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019DD50: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8019DD54: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8019DD58: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019DD5C: lwc1        $f16, 0x118($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X118);
    // 0x8019DD60: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019DD64: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8019DD68: lwc1        $f6, 0x11C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X11C);
    // 0x8019DD6C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019DD70: b           L_8019DE04
    // 0x8019DD74: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
        goto L_8019DE04;
    // 0x8019DD74: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
L_8019DD78:
    // 0x8019DD78: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019DD7C: lwc1        $f16, 0xE8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XE8);
    // 0x8019DD80: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019DD84: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8019DD88: swc1        $f18, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f18.u32l;
    // 0x8019DD8C: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8019DD90: lwc1        $f6, 0x110($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X110);
    // 0x8019DD94: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DD98: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x8019DD9C: lwc1        $f16, 0x114($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X114);
    // 0x8019DDA0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019DDA4: b           L_8019DE04
    // 0x8019DDA8: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
        goto L_8019DE04;
    // 0x8019DDA8: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_8019DDAC:
    // 0x8019DDAC: b           L_8019DE04
    // 0x8019DDB0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_8019DE04;
    // 0x8019DDB0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8019DDB4:
    // 0x8019DDB4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8019DDB8: lwc1        $f6, 0xF8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XF8);
    // 0x8019DDBC: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8019DDC0: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x8019DDC4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DDC8: addiu       $t9, $t9, 0x4BD0
    ctx->r25 = ADD32(ctx->r25, 0X4BD0);
    // 0x8019DDCC: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8019DDD0: lwc1        $f16, 0xF4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XF4);
    // 0x8019DDD4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019DDD8: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x8019DDDC: b           L_8019DE04
    // 0x8019DDE0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_8019DE04;
    // 0x8019DDE0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_8019DDE4:
    // 0x8019DDE4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8019DDE8: lwc1        $f6, 0xF0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XF0);
    // 0x8019DDEC: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8019DDF0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019DDF4: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8019DDF8: lwc1        $f16, 0xEC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XEC);
    // 0x8019DDFC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019DE00: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
L_8019DE04:
    // 0x8019DE04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019DE08: jr          $ra
    // 0x8019DE0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8019DE0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Andross_AndRadio_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801893B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801893BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801893C0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801893C4: lw          $t6, -0x6DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DC);
    // 0x801893C8: bnel        $t6, $zero, L_80189464
    if (ctx->r14 != 0) {
        // 0x801893CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80189464;
    }
    goto skip_0;
    // 0x801893CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801893D0: lh          $t7, 0x4E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X4E);
    // 0x801893D4: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x801893D8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801893DC: sh          $t8, 0x4E($a0)
    MEM_H(0X4E, ctx->r4) = ctx->r24;
    // 0x801893E0: lh          $v0, 0x4E($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X4E);
    // 0x801893E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801893E8: addiu       $a0, $a0, -0x1930
    ctx->r4 = ADD32(ctx->r4, -0X1930);
    // 0x801893EC: beq         $v0, $at, L_8018941C
    if (ctx->r2 == ctx->r1) {
        // 0x801893F0: addiu       $at, $zero, 0x190
        ctx->r1 = ADD32(0, 0X190);
            goto L_8018941C;
    }
    // 0x801893F0: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x801893F4: beq         $v0, $at, L_8018942C
    if (ctx->r2 == ctx->r1) {
        // 0x801893F8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018942C;
    }
    // 0x801893F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801893FC: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    // 0x80189400: beq         $v0, $at, L_80189440
    if (ctx->r2 == ctx->r1) {
        // 0x80189404: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80189440;
    }
    // 0x80189404: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189408: addiu       $at, $zero, 0x320
    ctx->r1 = ADD32(0, 0X320);
    // 0x8018940C: beq         $v0, $at, L_80189454
    if (ctx->r2 == ctx->r1) {
        // 0x80189410: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80189454;
    }
    // 0x80189410: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189414: b           L_80189464
    // 0x80189418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80189464;
    // 0x80189418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018941C:
    // 0x8018941C: jal         0x800BA808
    // 0x80189420: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x80189420: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_0:
    // 0x80189424: b           L_80189464
    // 0x80189428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80189464;
    // 0x80189428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018942C:
    // 0x8018942C: addiu       $a0, $a0, -0x18E0
    ctx->r4 = ADD32(ctx->r4, -0X18E0);
    // 0x80189430: jal         0x800BA808
    // 0x80189434: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x80189434: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_1:
    // 0x80189438: b           L_80189464
    // 0x8018943C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80189464;
    // 0x8018943C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80189440:
    // 0x80189440: addiu       $a0, $a0, -0x1894
    ctx->r4 = ADD32(ctx->r4, -0X1894);
    // 0x80189444: jal         0x800BA808
    // 0x80189448: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x80189448: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_2:
    // 0x8018944C: b           L_80189464
    // 0x80189450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80189464;
    // 0x80189450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80189454:
    // 0x80189454: addiu       $a0, $a0, 0x2C80
    ctx->r4 = ADD32(ctx->r4, 0X2C80);
    // 0x80189458: jal         0x800BA808
    // 0x8018945C: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x8018945C: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_3:
    // 0x80189460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80189464:
    // 0x80189464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80189468: jr          $ra
    // 0x8018946C: nop

    return;
    // 0x8018946C: nop

;}
RECOMP_FUNC void Andross_AndBrain_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B8C0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8018B8C4: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8018B8C8: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8018B8CC: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8018B8D0: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8018B8D4: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8018B8D8: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8018B8DC: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8018B8E0: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8018B8E4: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8018B8E8: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8018B8EC: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8018B8F0: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x8018B8F4: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8018B8F8: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8018B8FC: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8018B900: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018B904: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018B908: lh          $t6, 0x4E($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X4E);
    // 0x8018B90C: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8018B910: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018B914: beql        $t6, $at, L_8018BD94
    if (ctx->r14 == ctx->r1) {
        // 0x8018B918: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_8018BD94;
    }
    goto skip_0;
    // 0x8018B918: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_0:
    // 0x8018B91C: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8018B920: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B924: lwc1        $f22, 0x6CE8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6CE8);
    // 0x8018B928: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018B92C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018B930: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018B934: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018B938: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8018B93C: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8018B940: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018B944: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B948: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8018B94C: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8018B950: nop

    // 0x8018B954: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8018B958: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018B95C: jal         0x80005FE0
    // 0x8018B960: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_0;
    // 0x8018B960: nop

    after_0:
    // 0x8018B964: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B968: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018B96C: lwc1        $f0, 0x134($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X134);
    // 0x8018B970: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018B974: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018B978: add.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8018B97C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018B980: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018B984: sub.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8018B988: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018B98C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8018B990: jal         0x80005C34
    // 0x8018B994: nop

    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8018B994: nop

    after_1:
    // 0x8018B998: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018B99C: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x8018B9A0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018B9A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B9A8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8018B9AC: nop

    // 0x8018B9B0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8018B9B4: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8018B9B8: nop

    // 0x8018B9BC: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8018B9C0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018B9C4: jal         0x80005FE0
    // 0x8018B9C8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x8018B9C8: nop

    after_2:
    // 0x8018B9CC: lwc1        $f0, 0x134($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X134);
    // 0x8018B9D0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018B9D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018B9D8: add.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8018B9DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018B9E0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018B9E4: sub.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x8018B9E8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018B9EC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8018B9F0: jal         0x80005C34
    // 0x8018B9F4: nop

    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8018B9F4: nop

    after_3:
    // 0x8018B9F8: lwc1        $f0, 0x3F8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X3F8);
    // 0x8018B9FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018BA00: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018BA04: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018BA08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018BA0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018BA10: jal         0x80005C34
    // 0x8018BA14: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x8018BA14: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_4:
    // 0x8018BA18: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8018BA1C: addiu       $t2, $t2, 0x4660
    ctx->r10 = ADD32(ctx->r10, 0X4660);
    // 0x8018BA20: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x8018BA24: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018BA28: addiu       $a3, $a3, -0x4B84
    ctx->r7 = ADD32(ctx->r7, -0X4B84);
    // 0x8018BA2C: addiu       $a1, $a1, -0x3F5C
    ctx->r5 = ADD32(ctx->r5, -0X3F5C);
    // 0x8018BA30: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8018BA34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018BA38: addiu       $a2, $s4, 0x1A0
    ctx->r6 = ADD32(ctx->r20, 0X1A0);
    // 0x8018BA3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018BA40: jal         0x8009A72C
    // 0x8018BA44: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_5;
    // 0x8018BA44: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    after_5:
    // 0x8018BA48: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x8018BA4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018BA50: lwc1        $f6, 0x12C($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X12C);
    // 0x8018BA54: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8018BA58: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8018BA5C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8018BA60: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x8018BA64: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018BA68: bc1f        L_8018BAA8
    if (!c1cs) {
        // 0x8018BA6C: nop
    
            goto L_8018BAA8;
    }
    // 0x8018BA6C: nop

    // 0x8018BA70: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8018BA74: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8018BA78: jal         0x800B8DD0
    // 0x8018BA7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x8018BA7C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x8018BA80: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8018BA84: lui         $t5, 0xFF40
    ctx->r13 = S32(0XFF40 << 16);
    // 0x8018BA88: ori         $t5, $t5, 0x40FF
    ctx->r13 = ctx->r13 | 0X40FF;
    // 0x8018BA8C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018BA90: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x8018BA94: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8018BA98: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018BA9C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8018BAA0: b           L_8018BAEC
    // 0x8018BAA4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
        goto L_8018BAEC;
    // 0x8018BAA4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_8018BAA8:
    // 0x8018BAA8: jal         0x800B8DD0
    // 0x8018BAAC: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x8018BAAC: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_7:
    // 0x8018BAB0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8018BAB4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018BAB8: lui         $at, 0xFF40
    ctx->r1 = S32(0XFF40 << 16);
    // 0x8018BABC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018BAC0: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8018BAC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018BAC8: lwc1        $f10, 0x12C($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X12C);
    // 0x8018BACC: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x8018BAD0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018BAD4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8018BAD8: nop

    // 0x8018BADC: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8018BAE0: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8018BAE4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8018BAE8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
L_8018BAEC:
    // 0x8018BAEC: lui         $a2, 0xC180
    ctx->r6 = S32(0XC180 << 16);
    // 0x8018BAF0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8018BAF4: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x8018BAF8: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x8018BAFC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8018BB00: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x8018BB04: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8018BB08: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8018BB0C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018BB10: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018BB14: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018BB18: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018BB1C: jal         0x80005B00
    // 0x8018BB20: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x8018BB20: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_8:
    // 0x8018BB24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018BB28: lwc1        $f0, 0x6CEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6CEC);
    // 0x8018BB2C: lui         $a2, 0x3F19
    ctx->r6 = S32(0X3F19 << 16);
    // 0x8018BB30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018BB34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018BB38: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018BB3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018BB40: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8018BB44: jal         0x80005C34
    // 0x8018BB48: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x8018BB48: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x8018BB4C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018BB50: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8018BB54: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8018BB58: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018BB5C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8018BB60: lui         $fp, 0x601
    ctx->r30 = S32(0X601 << 16);
    // 0x8018BB64: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018BB68: addiu       $fp, $fp, -0x3D30
    ctx->r30 = ADD32(ctx->r30, -0X3D30);
    // 0x8018BB6C: sw          $zero, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = 0;
    // 0x8018BB70: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8018BB74: addiu       $s7, $zero, 0x9
    ctx->r23 = ADD32(0, 0X9);
    // 0x8018BB78: addiu       $s6, $zero, 0x5
    ctx->r22 = ADD32(0, 0X5);
    // 0x8018BB7C: lui         $s5, 0x600
    ctx->r21 = S32(0X600 << 16);
L_8018BB80:
    // 0x8018BB80: jal         0x80005708
    // 0x8018BB84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_10;
    // 0x8018BB84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x8018BB88: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x8018BB8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018BB90: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018BB94: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8018BB98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018BB9C: cvt.s.w     $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    ctx->f28.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018BBA0: mul.s       $f4, $f28, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f30.fl);
    // 0x8018BBA4: nop

    // 0x8018BBA8: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018BBAC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018BBB0: jal         0x80005E90
    // 0x8018BBB4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x8018BBB4: nop

    after_11:
    // 0x8018BBB8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018BBBC: lwc1        $f8, 0x6CF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CF0);
    // 0x8018BBC0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018BBC4: swc1        $f20, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f20.u32l;
    // 0x8018BBC8: mul.s       $f10, $f28, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f8.fl);
    // 0x8018BBCC: swc1        $f20, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f20.u32l;
    // 0x8018BBD0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018BBD4: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x8018BBD8: addiu       $a2, $sp, 0xA0
    ctx->r6 = ADD32(ctx->r29, 0XA0);
    // 0x8018BBDC: jal         0x80006970
    // 0x8018BBE0: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x8018BBE0: swc1        $f10, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x8018BBE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018BBE8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018BBEC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018BBF0: lw          $a1, 0xA0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA0);
    // 0x8018BBF4: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018BBF8: jal         0x80005B00
    // 0x8018BBFC: lw          $a3, 0xA8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA8);
    Matrix_Translate(rdram, ctx);
        goto after_13;
    // 0x8018BBFC: lw          $a3, 0xA8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA8);
    after_13:
    // 0x8018BC00: lwc1        $f16, 0x14($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8018BC04: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8018BC08: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8018BC0C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8018BC10: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018BC14: mul.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8018BC18: lwc1        $f6, 0x58($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X58);
    // 0x8018BC1C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018BC20: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018BC24: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018BC28: jal         0x80005E90
    // 0x8018BC2C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_14;
    // 0x8018BC2C: nop

    after_14:
    // 0x8018BC30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018BC34: lw          $s1, 0x80($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X80);
L_8018BC38:
    // 0x8018BC38: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018BC3C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8018BC40: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018BC44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018BC48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8018BC4C: jal         0x80005B00
    // 0x8018BC50: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_15;
    // 0x8018BC50: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_15:
    // 0x8018BC54: lwc1        $f10, 0x124($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X124);
    // 0x8018BC58: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018BC5C: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x8018BC60: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018BC64: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x8018BC68: nop

    // 0x8018BC6C: multu       $t2, $s1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018BC70: mflo        $t3
    ctx->r11 = lo;
    // 0x8018BC74: nop

    // 0x8018BC78: nop

    // 0x8018BC7C: multu       $t4, $s6
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018BC80: mflo        $t5
    ctx->r13 = lo;
    // 0x8018BC84: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8018BC88: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8018BC8C: nop

    // 0x8018BC90: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018BC94: mul.s       $f12, $f4, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018BC98: jal         0x80023090
    // 0x8018BC9C: nop

    __sinf_recomp(rdram, ctx);
        goto after_16;
    // 0x8018BC9C: nop

    after_16:
    // 0x8018BCA0: lwc1        $f6, 0x100($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X100);
    // 0x8018BCA4: lwc1        $f8, 0x120($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X120);
    // 0x8018BCA8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018BCAC: mul.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8018BCB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018BCB4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8018BCB8: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x8018BCBC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018BCC0: jal         0x80005FE0
    // 0x8018BCC4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_17;
    // 0x8018BCC4: nop

    after_17:
    // 0x8018BCC8: lwc1        $f18, 0x11C($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X11C);
    // 0x8018BCCC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018BCD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018BCD4: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8018BCD8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018BCDC: jal         0x80005D44
    // 0x8018BCE0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_18;
    // 0x8018BCE0: nop

    after_18:
    // 0x8018BCE4: jal         0x80005708
    // 0x8018BCE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_19;
    // 0x8018BCE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_19:
    // 0x8018BCEC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018BCF0: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8018BCF4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018BCF8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018BCFC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018BD00: jal         0x80005B00
    // 0x8018BD04: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_20;
    // 0x8018BD04: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_20:
    // 0x8018BD08: jal         0x80006EB8
    // 0x8018BD0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_21;
    // 0x8018BD0C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_21:
    // 0x8018BD10: bnel        $s0, $s7, L_8018BD38
    if (ctx->r16 != ctx->r23) {
        // 0x8018BD14: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_8018BD38;
    }
    goto skip_1;
    // 0x8018BD14: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x8018BD18: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8018BD1C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018BD20: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8018BD24: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x8018BD28: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8018BD2C: b           L_8018BD50
    // 0x8018BD30: nop

        goto L_8018BD50;
    // 0x8018BD30: nop

    // 0x8018BD34: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8018BD38:
    // 0x8018BD38: lui         $t0, 0x601
    ctx->r8 = S32(0X601 << 16);
    // 0x8018BD3C: addiu       $t0, $t0, -0x3AA0
    ctx->r8 = ADD32(ctx->r8, -0X3AA0);
    // 0x8018BD40: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018BD44: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8018BD48: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018BD4C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
L_8018BD50:
    // 0x8018BD50: jal         0x80005740
    // 0x8018BD54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_22;
    // 0x8018BD54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_22:
    // 0x8018BD58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018BD5C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018BD60: bne         $s0, $at, L_8018BC38
    if (ctx->r16 != ctx->r1) {
        // 0x8018BD64: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018BC38;
    }
    // 0x8018BD64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018BD68: jal         0x80005740
    // 0x8018BD6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_23;
    // 0x8018BD6C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_23:
    // 0x8018BD70: lw          $t1, 0x80($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X80);
    // 0x8018BD74: lw          $v0, 0xC0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC0);
    // 0x8018BD78: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8018BD7C: addiu       $t2, $t1, 0xA
    ctx->r10 = ADD32(ctx->r9, 0XA);
    // 0x8018BD80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018BD84: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // 0x8018BD88: bne         $v0, $at, L_8018BB80
    if (ctx->r2 != ctx->r1) {
        // 0x8018BD8C: sw          $t2, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r10;
            goto L_8018BB80;
    }
    // 0x8018BD8C: sw          $t2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r10;
    // 0x8018BD90: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_8018BD94:
    // 0x8018BD94: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018BD98: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018BD9C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8018BDA0: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8018BDA4: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8018BDA8: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8018BDAC: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8018BDB0: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8018BDB4: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8018BDB8: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8018BDBC: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8018BDC0: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8018BDC4: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8018BDC8: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8018BDCC: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8018BDD0: jr          $ra
    // 0x8018BDD4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8018BDD4: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void SectorY_8019BBBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BBBC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019BBC0: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x8019BBC4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8019BBC8: lwc1        $f4, 0x74($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X74);
    // 0x8019BBCC: swc1        $f4, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f4.u32l;
    // 0x8019BBD0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8019BBD4: lwc1        $f6, 0x78($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X78);
    // 0x8019BBD8: swc1        $f6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f6.u32l;
    // 0x8019BBDC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8019BBE0: lwc1        $f8, 0x7C($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X7C);
    // 0x8019BBE4: swc1        $f8, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f8.u32l;
    // 0x8019BBE8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8019BBEC: lwc1        $f10, 0xC0($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC0);
    // 0x8019BBF0: swc1        $f10, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->f10.u32l;
    // 0x8019BBF4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8019BBF8: lwc1        $f16, 0xC4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0XC4);
    // 0x8019BBFC: swc1        $f16, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->f16.u32l;
    // 0x8019BC00: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8019BC04: lwc1        $f18, 0xC8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0XC8);
    // 0x8019BC08: swc1        $f18, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->f18.u32l;
    // 0x8019BC0C: jr          $ra
    // 0x8019BC10: nop

    return;
    // 0x8019BC10: nop

;}
RECOMP_FUNC void SectorY_801A06A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A06A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A06A8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A06AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A06B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A06B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801A06B8: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x801A06BC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A06C0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801A06C4: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x801A06C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A06CC: blezl       $t7, L_801A07EC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801A06D0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801A07EC;
    }
    goto skip_0;
    // 0x801A06D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x801A06D4: jal         0x800613C4
    // 0x801A06D8: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801A06D8: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A06DC: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801A06E0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801A06E4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801A06E8: addiu       $t9, $zero, 0xC3
    ctx->r25 = ADD32(0, 0XC3);
    // 0x801A06EC: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x801A06F0: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x801A06F4: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x801A06F8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x801A06FC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801A0700: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x801A0704: subu        $t0, $t0, $a2
    ctx->r8 = SUB32(ctx->r8, ctx->r6);
    // 0x801A0708: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801A070C: addiu       $t1, $t1, 0x6AEC
    ctx->r9 = ADD32(ctx->r9, 0X6AEC);
    // 0x801A0710: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x801A0714: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801A0718: lwc1        $f6, 0x74($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X74);
    // 0x801A071C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A0720: addiu       $t8, $a2, 0x7
    ctx->r24 = ADD32(ctx->r6, 0X7);
    // 0x801A0724: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A0728: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801A072C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801A0730: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x801A0734: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x801A0738: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801A073C: lwc1        $f16, 0x78($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X78);
    // 0x801A0740: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A0744: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801A0748: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801A074C: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801A0750: lwc1        $f6, 0x7C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X7C);
    // 0x801A0754: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A0758: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x801A075C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x801A0760: lwc1        $f10, 0xD0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0XD0);
    // 0x801A0764: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x801A0768: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801A076C: lwc1        $f16, 0xE8($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XE8);
    // 0x801A0770: swc1        $f16, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f16.u32l;
    // 0x801A0774: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x801A0778: lwc1        $f18, 0xEC($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0XEC);
    // 0x801A077C: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x801A0780: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x801A0784: jal         0x800612B8
    // 0x801A0788: swc1        $f18, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801A0788: swc1        $f18, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x801A078C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A0790: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801A0794: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A0798: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x801A079C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x801A07A0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801A07A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801A07A8: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x801A07AC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801A07B0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A07B4: jal         0x80019218
    // 0x801A07B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801A07B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x801A07BC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A07C0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x801A07C4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A07C8: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x801A07CC: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801A07D0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801A07D4: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801A07D8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801A07DC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A07E0: jal         0x80019218
    // 0x801A07E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801A07E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x801A07E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801A07EC:
    // 0x801A07EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A07F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A07F4: jr          $ra
    // 0x801A07F8: nop

    return;
    // 0x801A07F8: nop

;}
RECOMP_FUNC void OvlI6_CallFunction(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void Andross_Ve2LoadLevelObjects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801878A8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801878AC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801878B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x801878B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801878B8: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x801878BC: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x801878C0: lui         $s5, 0xFF
    ctx->r21 = S32(0XFF << 16);
    // 0x801878C4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801878C8: lui         $s6, 0x8000
    ctx->r22 = S32(0X8000 << 16);
    // 0x801878CC: ori         $s5, $s5, 0xFFFF
    ctx->r21 = ctx->r21 | 0XFFFF;
    // 0x801878D0: addiu       $s4, $s4, 0x1FD0
    ctx->r20 = ADD32(ctx->r20, 0X1FD0);
    // 0x801878D4: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x801878D8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801878DC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x801878E0: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x801878E4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x801878E8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801878EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801878F0: lui         $v0, 0xC03
    ctx->r2 = S32(0XC03 << 16);
    // 0x801878F4: addiu       $v0, $v0, 0x56CC
    ctx->r2 = ADD32(ctx->r2, 0X56CC);
    // 0x801878F8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x801878FC: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80187900: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80187904: addu        $t9, $s4, $t8
    ctx->r25 = ADD32(ctx->r20, ctx->r24);
    // 0x80187908: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8018790C: and         $t1, $v0, $s5
    ctx->r9 = ctx->r2 & ctx->r21;
    // 0x80187910: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80187914: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80187918: addu        $t3, $t2, $s6
    ctx->r11 = ADD32(ctx->r10, ctx->r22);
    // 0x8018791C: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x80187920: lui         $fp, 0xC04
    ctx->r30 = S32(0XC04 << 16);
    // 0x80187924: addiu       $fp, $fp, -0x7334
    ctx->r30 = ADD32(ctx->r30, -0X7334);
    // 0x80187928: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x8018792C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80187930: addiu       $s7, $zero, 0x83
    ctx->r23 = ADD32(0, 0X83);
    // 0x80187934: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80187938: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
L_8018793C:
    // 0x8018793C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80187940: lh          $v0, 0x10($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X10);
    // 0x80187944: bgez        $v0, L_80187954
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80187948: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_80187954;
    }
    // 0x80187948: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x8018794C: b           L_80187A50
    // 0x80187950: nop

        goto L_80187A50;
    // 0x80187950: nop

L_80187954:
    // 0x80187954: beql        $at, $zero, L_80187A44
    if (ctx->r1 == 0) {
        // 0x80187958: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80187A44;
    }
    goto skip_0;
    // 0x80187958: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_0:
    // 0x8018795C: jal         0x800A4F4C
    // 0x80187960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Initialize(rdram, ctx);
        goto after_0;
    // 0x80187960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80187964: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80187968: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8018796C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80187970: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80187974: lh          $t8, 0x10($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X10);
    // 0x80187978: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8018797C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80187980: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80187984: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80187988: lh          $t1, 0x6($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X6);
    // 0x8018798C: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80187990: nop

    // 0x80187994: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80187998: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8018799C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x801879A0: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x801879A4: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x801879A8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801879AC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x801879B0: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x801879B4: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801879B8: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x801879BC: lh          $t6, 0x4($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4);
    // 0x801879C0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x801879C4: nop

    // 0x801879C8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801879CC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801879D0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x801879D4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x801879D8: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x801879DC: lh          $t9, 0x8($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X8);
    // 0x801879E0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x801879E4: nop

    // 0x801879E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801879EC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x801879F0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x801879F4: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x801879F8: lh          $t2, 0xC($t1)
    ctx->r10 = MEM_H(ctx->r9, 0XC);
    // 0x801879FC: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80187A00: nop

    // 0x80187A04: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80187A08: jal         0x800612B8
    // 0x80187A0C: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80187A0C: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x80187A10: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    // 0x80187A14: sll         $t4, $fp, 4
    ctx->r12 = S32(ctx->r30 << 4);
    // 0x80187A18: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x80187A1C: bne         $s7, $t3, L_80187A3C
    if (ctx->r23 != ctx->r11) {
        // 0x80187A20: sll         $t6, $t5, 2
        ctx->r14 = S32(ctx->r13 << 2);
            goto L_80187A3C;
    }
    // 0x80187A20: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80187A24: addu        $t7, $s4, $t6
    ctx->r15 = ADD32(ctx->r20, ctx->r14);
    // 0x80187A28: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80187A2C: and         $t9, $fp, $s5
    ctx->r25 = ctx->r30 & ctx->r21;
    // 0x80187A30: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80187A34: addu        $t1, $t0, $s6
    ctx->r9 = ADD32(ctx->r8, ctx->r22);
    // 0x80187A38: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
L_80187A3C:
    // 0x80187A3C: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80187A40: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80187A44:
    // 0x80187A44: slti        $at, $s1, 0x4E20
    ctx->r1 = SIGNED(ctx->r17) < 0X4E20 ? 1 : 0;
    // 0x80187A48: bnel        $at, $zero, L_8018793C
    if (ctx->r1 != 0) {
        // 0x80187A4C: lw          $t4, 0x0($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X0);
            goto L_8018793C;
    }
    goto skip_1;
    // 0x80187A4C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_80187A50:
    // 0x80187A50: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80187A54: addiu       $s0, $s0, 0x42D4
    ctx->r16 = ADD32(ctx->r16, 0X42D4);
    // 0x80187A58: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80187A5C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
L_80187A60:
    // 0x80187A60: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80187A64: lh          $v0, 0x10($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X10);
    // 0x80187A68: bgez        $v0, L_80187A78
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80187A6C: slti        $at, $v0, 0x124
        ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
            goto L_80187A78;
    }
    // 0x80187A6C: slti        $at, $v0, 0x124
    ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
    // 0x80187A70: b           L_80187B50
    // 0x80187A74: nop

        goto L_80187B50;
    // 0x80187A74: nop

L_80187A78:
    // 0x80187A78: beq         $at, $zero, L_80187B40
    if (ctx->r1 == 0) {
        // 0x80187A7C: slti        $at, $v0, 0xB0
        ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
            goto L_80187B40;
    }
    // 0x80187A7C: slti        $at, $v0, 0xB0
    ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
    // 0x80187A80: bnel        $at, $zero, L_80187B44
    if (ctx->r1 != 0) {
        // 0x80187A84: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80187B44;
    }
    goto skip_2;
    // 0x80187A84: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_2:
    // 0x80187A88: jal         0x800613C4
    // 0x80187A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_2;
    // 0x80187A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80187A90: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80187A94: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80187A98: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80187A9C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80187AA0: lh          $t6, 0x10($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X10);
    // 0x80187AA4: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x80187AA8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80187AAC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80187AB0: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80187AB4: lh          $t9, 0x6($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6);
    // 0x80187AB8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80187ABC: nop

    // 0x80187AC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80187AC4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80187AC8: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80187ACC: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80187AD0: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80187AD4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80187AD8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80187ADC: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80187AE0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80187AE4: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80187AE8: lh          $t4, 0x4($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X4);
    // 0x80187AEC: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80187AF0: nop

    // 0x80187AF4: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80187AF8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80187AFC: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80187B00: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80187B04: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80187B08: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x80187B0C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80187B10: nop

    // 0x80187B14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80187B18: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80187B1C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80187B20: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80187B24: lh          $t0, 0xC($t9)
    ctx->r8 = MEM_H(ctx->r25, 0XC);
    // 0x80187B28: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80187B2C: nop

    // 0x80187B30: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80187B34: jal         0x800612B8
    // 0x80187B38: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x80187B38: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x80187B3C: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_80187B40:
    // 0x80187B40: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80187B44:
    // 0x80187B44: slti        $at, $s1, 0x4E20
    ctx->r1 = SIGNED(ctx->r17) < 0X4E20 ? 1 : 0;
    // 0x80187B48: bnel        $at, $zero, L_80187A60
    if (ctx->r1 != 0) {
        // 0x80187B4C: lw          $t2, 0x0($s2)
        ctx->r10 = MEM_W(ctx->r18, 0X0);
            goto L_80187A60;
    }
    goto skip_3;
    // 0x80187B4C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    skip_3:
L_80187B50:
    // 0x80187B50: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80187B54: addiu       $s0, $s0, 0x37E0
    ctx->r16 = ADD32(ctx->r16, 0X37E0);
    // 0x80187B58: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80187B5C: addiu       $s4, $zero, 0x4E20
    ctx->r20 = ADD32(0, 0X4E20);
    // 0x80187B60: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
L_80187B64:
    // 0x80187B64: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x80187B68: lh          $v0, 0x10($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X10);
    // 0x80187B6C: bltz        $v0, L_80187C2C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80187B70: slti        $at, $v0, 0x153
        ctx->r1 = SIGNED(ctx->r2) < 0X153 ? 1 : 0;
            goto L_80187C2C;
    }
    // 0x80187B70: slti        $at, $v0, 0x153
    ctx->r1 = SIGNED(ctx->r2) < 0X153 ? 1 : 0;
    // 0x80187B74: beq         $at, $zero, L_80187C20
    if (ctx->r1 == 0) {
        // 0x80187B78: slti        $at, $v0, 0x142
        ctx->r1 = SIGNED(ctx->r2) < 0X142 ? 1 : 0;
            goto L_80187C20;
    }
    // 0x80187B78: slti        $at, $v0, 0x142
    ctx->r1 = SIGNED(ctx->r2) < 0X142 ? 1 : 0;
    // 0x80187B7C: bnel        $at, $zero, L_80187C24
    if (ctx->r1 != 0) {
        // 0x80187B80: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80187C24;
    }
    goto skip_4;
    // 0x80187B80: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_4:
    // 0x80187B84: jal         0x80061444
    // 0x80187B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_Initialize(rdram, ctx);
        goto after_4;
    // 0x80187B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80187B8C: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80187B90: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80187B94: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80187B98: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80187B9C: lh          $t5, 0x10($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X10);
    // 0x80187BA0: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x80187BA4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80187BA8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80187BAC: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80187BB0: lh          $t8, 0x6($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X6);
    // 0x80187BB4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80187BB8: nop

    // 0x80187BBC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80187BC0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80187BC4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80187BC8: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80187BCC: lwc1        $f8, 0x0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80187BD0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80187BD4: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80187BD8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80187BDC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80187BE0: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x80187BE4: lh          $t3, 0x4($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X4);
    // 0x80187BE8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80187BEC: nop

    // 0x80187BF0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80187BF4: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80187BF8: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80187BFC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80187C00: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80187C04: lh          $t6, 0x8($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X8);
    // 0x80187C08: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80187C0C: nop

    // 0x80187C10: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80187C14: jal         0x800612B8
    // 0x80187C18: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x80187C18: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x80187C1C: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
L_80187C20:
    // 0x80187C20: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80187C24:
    // 0x80187C24: bnel        $s1, $s4, L_80187B64
    if (ctx->r17 != ctx->r20) {
        // 0x80187C28: lw          $t1, 0x0($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X0);
            goto L_80187B64;
    }
    goto skip_5;
    // 0x80187C28: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    skip_5:
L_80187C2C:
    // 0x80187C2C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80187C30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80187C34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80187C38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80187C3C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80187C40: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80187C44: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80187C48: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80187C4C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80187C50: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80187C54: jr          $ra
    // 0x80187C58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80187C58: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void SectorY_Scenery156_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197CB8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80197CBC: jr          $ra
    // 0x80197CC0: nop

    return;
    // 0x80197CC0: nop

;}
RECOMP_FUNC void SectorY_80199D64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199D64: lh          $t6, 0xCC($a0)
    ctx->r14 = MEM_H(ctx->r4, 0XCC);
    // 0x80199D68: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80199D6C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80199D70: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80199D74: bne         $at, $zero, L_80199DA4
    if (ctx->r1 != 0) {
        // 0x80199D78: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_80199DA4;
    }
    // 0x80199D78: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80199D7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199D80: sh          $t7, 0xB0($a0)
    MEM_H(0XB0, ctx->r4) = ctx->r15;
    // 0x80199D84: sh          $t8, 0xB2($a0)
    MEM_H(0XB2, ctx->r4) = ctx->r24;
    // 0x80199D88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199D8C: swc1        $f4, 0x108($a0)
    MEM_W(0X108, ctx->r4) = ctx->f4.u32l;
    // 0x80199D90: lwc1        $f6, 0x7550($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7550);
    // 0x80199D94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80199D98: sh          $zero, 0x56($a0)
    MEM_H(0X56, ctx->r4) = 0;
    // 0x80199D9C: swc1        $f6, 0x160($a0)
    MEM_W(0X160, ctx->r4) = ctx->f6.u32l;
    // 0x80199DA0: swc1        $f8, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f8.u32l;
L_80199DA4:
    // 0x80199DA4: jr          $ra
    // 0x80199DA8: nop

    return;
    // 0x80199DA8: nop

;}
RECOMP_FUNC void SectorY_ActorCs_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A0514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A0518: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801A051C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801A0520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A0524: jal         0x800613C4
    // 0x801A0528: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801A0528: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A052C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801A0530: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A0534: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x801A0538: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x801A053C: subu        $t8, $t8, $v1
    ctx->r24 = SUB32(ctx->r24, ctx->r3);
    // 0x801A0540: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801A0544: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x801A0548: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801A054C: addiu       $t9, $t9, 0x6A74
    ctx->r25 = ADD32(ctx->r25, 0X6A74);
    // 0x801A0550: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x801A0554: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801A0558: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801A055C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A0560: sltiu       $at, $v1, 0xA
    ctx->r1 = ctx->r3 < 0XA ? 1 : 0;
    // 0x801A0564: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801A0568: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801A056C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801A0570: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801A0574: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A0578: beq         $at, $zero, L_801A0694
    if (ctx->r1 == 0) {
        // 0x801A057C: swc1        $f8, 0xC($a2)
        MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
            goto L_801A0694;
    }
    // 0x801A057C: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x801A0580: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A0584: addu        $at, $at, $t0
    gpr jr_addend_801A058C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801A0588: lw          $t0, 0x798C($at)
    ctx->r8 = ADD32(ctx->r1, 0X798C);
    // 0x801A058C: jr          $t0
    // 0x801A0590: nop

    switch (jr_addend_801A058C >> 2) {
        case 0: goto L_801A0594; break;
        case 1: goto L_801A0594; break;
        case 2: goto L_801A0594; break;
        case 3: goto L_801A05BC; break;
        case 4: goto L_801A05FC; break;
        case 5: goto L_801A0624; break;
        case 6: goto L_801A064C; break;
        case 7: goto L_801A0680; break;
        case 8: goto L_801A0594; break;
        case 9: goto L_801A0624; break;
        default: switch_error(__func__, 0x801A058C, 0x801A798C);
    }
    // 0x801A0590: nop

L_801A0594:
    // 0x801A0594: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801A0598: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A059C: addiu       $t1, $zero, 0x26
    ctx->r9 = ADD32(0, 0X26);
    // 0x801A05A0: sh          $t1, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r9;
    // 0x801A05A4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801A05A8: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x801A05AC: jal         0x800612B8
    // 0x801A05B0: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801A05B0: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    after_1:
    // 0x801A05B4: b           L_801A0698
    // 0x801A05B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A0698;
    // 0x801A05B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A05BC:
    // 0x801A05BC: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x801A05C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A05C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A05C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A05CC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A05D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A05D4: addiu       $t2, $zero, 0x24
    ctx->r10 = ADD32(0, 0X24);
    // 0x801A05D8: sh          $t2, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r10;
    // 0x801A05DC: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801A05E0: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x801A05E4: swc1        $f16, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f16.u32l;
    // 0x801A05E8: swc1        $f18, 0x110($a2)
    MEM_W(0X110, ctx->r6) = ctx->f18.u32l;
    // 0x801A05EC: jal         0x800612B8
    // 0x801A05F0: swc1        $f4, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x801A05F0: swc1        $f4, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f4.u32l;
    after_2:
    // 0x801A05F4: b           L_801A0698
    // 0x801A05F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A0698;
    // 0x801A05F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A05FC:
    // 0x801A05FC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801A0600: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A0604: addiu       $t3, $zero, 0x25
    ctx->r11 = ADD32(0, 0X25);
    // 0x801A0608: sh          $t3, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r11;
    // 0x801A060C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801A0610: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x801A0614: jal         0x800612B8
    // 0x801A0618: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x801A0618: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    after_3:
    // 0x801A061C: b           L_801A0698
    // 0x801A0620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A0698;
    // 0x801A0620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A0624:
    // 0x801A0624: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A0628: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A062C: addiu       $t4, $zero, 0x27
    ctx->r12 = ADD32(0, 0X27);
    // 0x801A0630: sh          $t4, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r12;
    // 0x801A0634: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801A0638: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x801A063C: jal         0x800612B8
    // 0x801A0640: swc1        $f8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x801A0640: swc1        $f8, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f8.u32l;
    after_4:
    // 0x801A0644: b           L_801A0698
    // 0x801A0648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A0698;
    // 0x801A0648: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A064C:
    // 0x801A064C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A0650: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A0654: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A0658: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A065C: addiu       $t5, $zero, 0x24
    ctx->r13 = ADD32(0, 0X24);
    // 0x801A0660: sh          $t5, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r13;
    // 0x801A0664: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801A0668: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x801A066C: swc1        $f10, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f10.u32l;
    // 0x801A0670: jal         0x800612B8
    // 0x801A0674: swc1        $f16, 0x110($a2)
    MEM_W(0X110, ctx->r6) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x801A0674: swc1        $f16, 0x110($a2)
    MEM_W(0X110, ctx->r6) = ctx->f16.u32l;
    after_5:
    // 0x801A0678: b           L_801A0698
    // 0x801A067C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A0698;
    // 0x801A067C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A0680:
    // 0x801A0680: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x801A0684: sh          $t6, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r14;
    // 0x801A0688: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801A068C: jal         0x800612B8
    // 0x801A0690: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x801A0690: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_6:
L_801A0694:
    // 0x801A0694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A0698:
    // 0x801A0698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A069C: jr          $ra
    // 0x801A06A0: nop

    return;
    // 0x801A06A0: nop

;}
RECOMP_FUNC void Andross_EscapePhase_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801961AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801961B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801961B4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801961B8: jal         0x80061404
    // 0x801961BC: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    Boss_Initialize(rdram, ctx);
        goto after_0;
    // 0x801961BC: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    after_0:
    // 0x801961C0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801961C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801961C8: sb          $t6, -0xEF0($at)
    MEM_B(-0XEF0, ctx->r1) = ctx->r14;
    // 0x801961CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801961D0: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x801961D4: sh          $t7, -0xEA2($at)
    MEM_H(-0XEA2, ctx->r1) = ctx->r15;
    // 0x801961D8: addiu       $a1, $zero, 0x141
    ctx->r5 = ADD32(0, 0X141);
    // 0x801961DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801961E0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801961E4: addiu       $a0, $a0, -0xED4
    ctx->r4 = ADD32(ctx->r4, -0XED4);
    // 0x801961E8: jal         0x800612B8
    // 0x801961EC: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801961EC: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    after_1:
    // 0x801961F0: addiu       $t8, $zero, 0x257
    ctx->r24 = ADD32(0, 0X257);
    // 0x801961F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801961F8: sw          $t8, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = ctx->r24;
    // 0x801961FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80196200: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80196204: jr          $ra
    // 0x80196208: nop

    return;
    // 0x80196208: nop

;}
RECOMP_FUNC void Turret_Shoot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A58A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A58AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A58B0: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x801A58B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801A58B8: lw          $t6, 0x1C4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X1C4);
    // 0x801A58BC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x801A58C0: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A58C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x801A58C8: mflo        $v0
    ctx->r2 = lo;
    // 0x801A58CC: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x801A58D0: lhu         $t7, -0x2768($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X2768);
    // 0x801A58D4: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x801A58D8: beql        $t8, $zero, L_801A58F8
    if (ctx->r24 == 0) {
        // 0x801A58DC: addu        $t6, $t6, $v0
        ctx->r14 = ADD32(ctx->r14, ctx->r2);
            goto L_801A58F8;
    }
    goto skip_0;
    // 0x801A58DC: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    skip_0:
    // 0x801A58E0: lw          $v0, 0x1C4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C4);
    // 0x801A58E4: sw          $zero, 0x244($a2)
    MEM_W(0X244, ctx->r6) = 0;
    // 0x801A58E8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801A58EC: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x801A58F0: sll         $v0, $t9, 1
    ctx->r2 = S32(ctx->r25 << 1);
    // 0x801A58F4: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
L_801A58F8:
    // 0x801A58F8: lhu         $t6, -0x2780($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2780);
    // 0x801A58FC: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x801A5900: beql        $t7, $zero, L_801A5968
    if (ctx->r15 == 0) {
        // 0x801A5904: lw          $v0, 0x1BC($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X1BC);
            goto L_801A5968;
    }
    goto skip_1;
    // 0x801A5904: lw          $v0, 0x1BC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1BC);
    skip_1:
    // 0x801A5908: lw          $v0, 0x244($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X244);
    // 0x801A590C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A5910: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    // 0x801A5914: bnel        $v0, $zero, L_801A5954
    if (ctx->r2 != 0) {
        // 0x801A5918: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_801A5954;
    }
    goto skip_2;
    // 0x801A5918: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x801A591C: jal         0x801A581C
    // 0x801A5920: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Turret_GreatFoxLaser(rdram, ctx);
        goto after_0;
    // 0x801A5920: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A5924: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A5928: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A592C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801A5930: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x801A5934: jal         0x801A581C
    // 0x801A5938: nop

    Turret_GreatFoxLaser(rdram, ctx);
        goto after_1;
    // 0x801A5938: nop

    after_1:
    // 0x801A593C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A5940: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801A5944: addiu       $ra, $zero, 0x6
    ctx->r31 = ADD32(0, 0X6);
    // 0x801A5948: sw          $t8, 0x1BC($a2)
    MEM_W(0X1BC, ctx->r6) = ctx->r24;
    // 0x801A594C: lw          $v0, 0x244($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X244);
    // 0x801A5950: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
L_801A5954:
    // 0x801A5954: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x801A5958: bne         $at, $zero, L_801A5964
    if (ctx->r1 != 0) {
        // 0x801A595C: sw          $t9, 0x244($a2)
        MEM_W(0X244, ctx->r6) = ctx->r25;
            goto L_801A5964;
    }
    // 0x801A595C: sw          $t9, 0x244($a2)
    MEM_W(0X244, ctx->r6) = ctx->r25;
    // 0x801A5960: sw          $zero, 0x244($a2)
    MEM_W(0X244, ctx->r6) = 0;
L_801A5964:
    // 0x801A5964: lw          $v0, 0x1BC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1BC);
L_801A5968:
    // 0x801A5968: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A596C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A5970: blez        $v0, L_801A5980
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801A5974: addiu       $t7, $v0, -0x4
        ctx->r15 = ADD32(ctx->r2, -0X4);
            goto L_801A5980;
    }
    // 0x801A5974: addiu       $t7, $v0, -0x4
    ctx->r15 = ADD32(ctx->r2, -0X4);
    // 0x801A5978: b           L_801A5984
    // 0x801A597C: sw          $t7, 0x1BC($a2)
    MEM_W(0X1BC, ctx->r6) = ctx->r15;
        goto L_801A5984;
    // 0x801A597C: sw          $t7, 0x1BC($a2)
    MEM_W(0X1BC, ctx->r6) = ctx->r15;
L_801A5980:
    // 0x801A5980: sw          $zero, 0x1BC($a2)
    MEM_W(0X1BC, ctx->r6) = 0;
L_801A5984:
    // 0x801A5984: lw          $t8, 0x1C4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X1C4);
    // 0x801A5988: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x801A598C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x801A5990: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A5994: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801A5998: addiu       $t2, $t2, 0x4750
    ctx->r10 = ADD32(ctx->r10, 0X4750);
    // 0x801A599C: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x801A59A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A59A4: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801A59A8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801A59AC: addiu       $t3, $zero, 0x30
    ctx->r11 = ADD32(0, 0X30);
    // 0x801A59B0: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801A59B4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801A59B8: mflo        $t9
    ctx->r25 = lo;
    // 0x801A59BC: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x801A59C0: lhu         $t6, -0x2768($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2768);
    // 0x801A59C4: andi        $t7, $t6, 0x10
    ctx->r15 = ctx->r14 & 0X10;
    // 0x801A59C8: beql        $t7, $zero, L_801A59D8
    if (ctx->r15 == 0) {
        // 0x801A59CC: lw          $a3, 0x1C0($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X1C0);
            goto L_801A59D8;
    }
    goto skip_3;
    // 0x801A59CC: lw          $a3, 0x1C0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X1C0);
    skip_3:
    // 0x801A59D0: sw          $zero, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = 0;
    // 0x801A59D4: lw          $a3, 0x1C0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X1C0);
L_801A59D8:
    // 0x801A59D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801A59DC: blezl       $a3, L_801A5A78
    if (SIGNED(ctx->r7) <= 0) {
        // 0x801A59E0: lw          $t7, 0x1C4($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X1C4);
            goto L_801A5A78;
    }
    goto skip_4;
    // 0x801A59E0: lw          $t7, 0x1C4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C4);
    skip_4:
    // 0x801A59E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A59E8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_801A59EC:
    // 0x801A59EC: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x801A59F0: bnel        $t0, $t8, L_801A5A68
    if (ctx->r8 != ctx->r24) {
        // 0x801A59F4: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_801A5A68;
    }
    goto skip_5;
    // 0x801A59F4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_5:
    // 0x801A59F8: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    // 0x801A59FC: bnel        $t1, $t9, L_801A5A68
    if (ctx->r9 != ctx->r25) {
        // 0x801A5A00: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_801A5A68;
    }
    goto skip_6;
    // 0x801A5A00: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_6:
    // 0x801A5A04: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A5A08: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801A5A0C: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x801A5A10: mflo        $t6
    ctx->r14 = lo;
    // 0x801A5A14: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x801A5A18: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x801A5A1C: swc1        $f0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f0.u32l;
    // 0x801A5A20: lwc1        $f4, 0x74($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X74);
    // 0x801A5A24: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x801A5A28: lwc1        $f6, 0x78($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X78);
    // 0x801A5A2C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x801A5A30: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x801A5A34: lwc1        $f8, 0x7C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X7C);
    // 0x801A5A38: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x801A5A3C: sb          $a0, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r4;
    // 0x801A5A40: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x801A5A44: sb          $a0, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r4;
    // 0x801A5A48: sb          $a0, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r4;
    // 0x801A5A4C: sb          $a0, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r4;
    // 0x801A5A50: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x801A5A54: swc1        $f16, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f16.u32l;
    // 0x801A5A58: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x801A5A5C: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x801A5A60: lw          $a3, 0x1C0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X1C0);
    // 0x801A5A64: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_801A5A68:
    // 0x801A5A68: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801A5A6C: bne         $at, $zero, L_801A59EC
    if (ctx->r1 != 0) {
        // 0x801A5A70: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_801A59EC;
    }
    // 0x801A5A70: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
    // 0x801A5A74: lw          $t7, 0x1C4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C4);
L_801A5A78:
    // 0x801A5A78: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x801A5A7C: multu       $t7, $ra
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A5A80: addiu       $t7, $a3, 0x1
    ctx->r15 = ADD32(ctx->r7, 0X1);
    // 0x801A5A84: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x801A5A88: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x801A5A8C: mflo        $t8
    ctx->r24 = lo;
    // 0x801A5A90: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801A5A94: lhu         $t9, -0x2780($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2780);
    // 0x801A5A98: andi        $t6, $t9, 0x10
    ctx->r14 = ctx->r25 & 0X10;
    // 0x801A5A9C: beql        $t6, $zero, L_801A5AC4
    if (ctx->r14 == 0) {
        // 0x801A5AA0: sw          $zero, 0x1C0($a2)
        MEM_W(0X1C0, ctx->r6) = 0;
            goto L_801A5AC4;
    }
    goto skip_7;
    // 0x801A5AA0: sw          $zero, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = 0;
    skip_7:
    // 0x801A5AA4: bne         $at, $zero, L_801A5AB8
    if (ctx->r1 != 0) {
        // 0x801A5AA8: sw          $t7, 0x1C0($a2)
        MEM_W(0X1C0, ctx->r6) = ctx->r15;
            goto L_801A5AB8;
    }
    // 0x801A5AA8: sw          $t7, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = ctx->r15;
    // 0x801A5AAC: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x801A5AB0: b           L_801A5AC4
    // 0x801A5AB4: sw          $t8, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = ctx->r24;
        goto L_801A5AC4;
    // 0x801A5AB4: sw          $t8, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = ctx->r24;
L_801A5AB8:
    // 0x801A5AB8: b           L_801A5AC4
    // 0x801A5ABC: sw          $a3, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = ctx->r7;
        goto L_801A5AC4;
    // 0x801A5ABC: sw          $a3, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = ctx->r7;
    // 0x801A5AC0: sw          $zero, 0x1C0($a2)
    MEM_W(0X1C0, ctx->r6) = 0;
L_801A5AC4:
    // 0x801A5AC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A5AC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A5ACC: jr          $ra
    // 0x801A5AD0: nop

    return;
    // 0x801A5AD0: nop

;}
RECOMP_FUNC void Andross_AndBrain_Control(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188CB8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80188CBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80188CC0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80188CC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188CC8: lh          $t6, 0x4C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4C);
    // 0x80188CCC: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80188CD0: addiu       $a0, $a0, -0x3FC8
    ctx->r4 = ADD32(ctx->r4, -0X3FC8);
    // 0x80188CD4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80188CD8: jal         0x8009ACDC
    // 0x80188CDC: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    Animation_GetFrameCount(rdram, ctx);
        goto after_0;
    // 0x80188CDC: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    after_0:
    // 0x80188CE0: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x80188CE4: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80188CE8: addiu       $a0, $a0, -0x3FC8
    ctx->r4 = ADD32(ctx->r4, -0X3FC8);
    // 0x80188CEC: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80188CF0: bne         $at, $zero, L_80188D00
    if (ctx->r1 != 0) {
        // 0x80188CF4: nop
    
            goto L_80188D00;
    }
    // 0x80188CF4: nop

    // 0x80188CF8: sh          $zero, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = 0;
    // 0x80188CFC: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
L_80188D00:
    // 0x80188D00: jal         0x8009AA20
    // 0x80188D04: addiu       $a2, $s0, 0x1A0
    ctx->r6 = ADD32(ctx->r16, 0X1A0);
    Animation_GetFrameData(rdram, ctx);
        goto after_1;
    // 0x80188D04: addiu       $a2, $s0, 0x1A0
    ctx->r6 = ADD32(ctx->r16, 0X1A0);
    after_1:
    // 0x80188D08: lh          $v1, 0x8E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8E);
    // 0x80188D0C: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x80188D10: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80188D14: beq         $v1, $zero, L_80188D20
    if (ctx->r3 == 0) {
        // 0x80188D18: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_80188D20;
    }
    // 0x80188D18: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80188D1C: sh          $t8, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = ctx->r24;
L_80188D20:
    // 0x80188D20: lh          $v0, 0x8C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8C);
    // 0x80188D24: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80188D28: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188D2C: beq         $v0, $zero, L_80188D8C
    if (ctx->r2 == 0) {
        // 0x80188D30: lui         $a3, 0x3E4C
        ctx->r7 = S32(0X3E4C << 16);
            goto L_80188D8C;
    }
    // 0x80188D30: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80188D34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80188D38: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80188D3C: sh          $t9, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = ctx->r25;
    // 0x80188D40: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80188D44: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188D48: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x80188D4C: lui         $a1, 0xC170
    ctx->r5 = S32(0XC170 << 16);
    // 0x80188D50: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80188D54: jal         0x8009BC2C
    // 0x80188D58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80188D58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80188D5C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80188D60: lui         $a1, 0x3D4C
    ctx->r5 = S32(0X3D4C << 16);
    // 0x80188D64: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x80188D68: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x80188D6C: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80188D70: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188D74: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80188D78: addiu       $a0, $s0, 0x118
    ctx->r4 = ADD32(ctx->r16, 0X118);
    // 0x80188D7C: jal         0x8009BC2C
    // 0x80188D80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80188D80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80188D84: b           L_80188DC8
    // 0x80188D88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_80188DC8;
    // 0x80188D88: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80188D8C:
    // 0x80188D8C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80188D90: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80188D94: jal         0x8009BC2C
    // 0x80188D98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80188D98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80188D9C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80188DA0: lui         $a1, 0x3CF5
    ctx->r5 = S32(0X3CF5 << 16);
    // 0x80188DA4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80188DA8: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80188DAC: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80188DB0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188DB4: ori         $a1, $a1, 0xC28F
    ctx->r5 = ctx->r5 | 0XC28F;
    // 0x80188DB8: addiu       $a0, $s0, 0x118
    ctx->r4 = ADD32(ctx->r16, 0X118);
    // 0x80188DBC: jal         0x8009BC2C
    // 0x80188DC0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80188DC0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80188DC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80188DC8:
    // 0x80188DC8: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    // 0x80188DCC: lw          $a2, 0x108($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X108);
    // 0x80188DD0: lw          $a3, 0x10C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X10C);
    // 0x80188DD4: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    // 0x80188DD8: jal         0x8009BC2C
    // 0x80188DDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80188DDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80188DE0: lh          $v0, 0x8A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8A);
    // 0x80188DE4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80188DE8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80188DEC: beq         $v0, $zero, L_80188E20
    if (ctx->r2 == 0) {
        // 0x80188DF0: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_80188E20;
    }
    // 0x80188DF0: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80188DF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80188DF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188DFC: sh          $t5, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r13;
    // 0x80188E00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188E04: swc1        $f6, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f6.u32l;
    // 0x80188E08: lwc1        $f8, 0x6BF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BF4);
    // 0x80188E0C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80188E10: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188E14: swc1        $f8, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f8.u32l;
    // 0x80188E18: b           L_80188E40
    // 0x80188E1C: swc1        $f10, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f10.u32l;
        goto L_80188E40;
    // 0x80188E1C: swc1        $f10, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f10.u32l;
L_80188E20:
    // 0x80188E20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188E24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188E28: swc1        $f4, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f4.u32l;
    // 0x80188E2C: lwc1        $f6, 0x6BF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6BF8);
    // 0x80188E30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80188E34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188E38: swc1        $f6, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f6.u32l;
    // 0x80188E3C: swc1        $f8, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f8.u32l;
L_80188E40:
    // 0x80188E40: lh          $v0, 0x96($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X96);
    // 0x80188E44: beq         $v0, $zero, L_80188F38
    if (ctx->r2 == 0) {
        // 0x80188E48: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80188F38;
    }
    // 0x80188E48: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80188E4C: sh          $t6, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r14;
    // 0x80188E50: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x80188E54: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80188E58: bnel        $t8, $zero, L_80188F3C
    if (ctx->r24 != 0) {
        // 0x80188E5C: lwc1        $f8, 0x110($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
            goto L_80188F3C;
    }
    goto skip_0;
    // 0x80188E5C: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    skip_0:
    // 0x80188E60: jal         0x80004EB0
    // 0x80188E64: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80188E64: nop

    after_7:
    // 0x80188E68: jal         0x80004EB0
    // 0x80188E6C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80188E6C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80188E70: jal         0x80004EB0
    // 0x80188E74: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80188E74: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x80188E78: jal         0x80004EB0
    // 0x80188E7C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x80188E7C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x80188E80: jal         0x80004EB0
    // 0x80188E84: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x80188E84: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x80188E88: jal         0x80004EB0
    // 0x80188E8C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x80188E8C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x80188E90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80188E94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80188E98: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80188E9C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80188EA0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188EA4: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80188EA8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80188EAC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80188EB0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80188EB4: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80188EB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188EBC: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80188EC0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80188EC4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188EC8: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80188ECC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188ED0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80188ED4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80188ED8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188EDC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80188EE0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80188EE4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80188EE8: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80188EEC: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80188EF0: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80188EF4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80188EF8: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80188EFC: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80188F00: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80188F04: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80188F08: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80188F0C: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80188F10: sub.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80188F14: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188F18: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80188F1C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80188F20: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80188F24: nop

    // 0x80188F28: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80188F2C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80188F30: jal         0x8018887C
    // 0x80188F34: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Andross_AndBrainWaste_Spawn(rdram, ctx);
        goto after_13;
    // 0x80188F34: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_13:
L_80188F38:
    // 0x80188F38: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
L_80188F3C:
    // 0x80188F3C: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80188F40: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80188F44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188F48: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80188F4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80188F50: swc1        $f10, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f10.u32l;
    // 0x80188F54: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80188F58: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188F5C: lwc1        $f4, 0x58($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80188F60: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x80188F64: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80188F68: jal         0x80005E90
    // 0x80188F6C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_14;
    // 0x80188F6C: nop

    after_14:
    // 0x80188F70: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80188F74: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188F78: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80188F7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80188F80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188F84: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80188F88: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80188F8C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188F90: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80188F94: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x80188F98: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x80188F9C: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80188FA0: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80188FA4: jal         0x80006970
    // 0x80188FA8: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_15;
    // 0x80188FA8: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80188FAC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80188FB0: lui         $at, 0xC1D0
    ctx->r1 = S32(0XC1D0 << 16);
    // 0x80188FB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188FB8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80188FBC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80188FC0: swc1        $f4, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f4.u32l;
    // 0x80188FC4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80188FC8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80188FCC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80188FD0: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80188FD4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80188FD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188FDC: sh          $zero, 0x90($s0)
    MEM_H(0X90, ctx->r16) = 0;
    // 0x80188FE0: addiu       $a3, $a3, 0x4750
    ctx->r7 = ADD32(ctx->r7, 0X4750);
    // 0x80188FE4: addiu       $v1, $v1, 0x5D68
    ctx->r3 = ADD32(ctx->r3, 0X5D68);
    // 0x80188FE8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80188FEC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80188FF0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80188FF4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80188FF8: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80188FFC: addiu       $t0, $zero, 0x30
    ctx->r8 = ADD32(0, 0X30);
    // 0x80189000: addiu       $a2, $zero, 0xC5
    ctx->r6 = ADD32(0, 0XC5);
    // 0x80189004: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80189008: swc1        $f6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f6.u32l;
    // 0x8018900C: swc1        $f8, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f8.u32l;
L_80189010:
    // 0x80189010: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80189014: bnel        $a1, $t5, L_8018907C
    if (ctx->r5 != ctx->r13) {
        // 0x80189018: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8018907C;
    }
    goto skip_1;
    // 0x80189018: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x8018901C: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x80189020: bnel        $a2, $t6, L_8018907C
    if (ctx->r6 != ctx->r14) {
        // 0x80189024: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8018907C;
    }
    goto skip_2;
    // 0x80189024: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
    // 0x80189028: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018902C: mflo        $t7
    ctx->r15 = lo;
    // 0x80189030: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x80189034: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80189038: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x8018903C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80189040: swc1        $f10, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f10.u32l;
    // 0x80189044: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80189048: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018904C: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80189050: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80189054: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80189058: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018905C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80189060: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x80189064: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80189068: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x8018906C: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x80189070: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x80189074: sh          $t3, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r11;
    // 0x80189078: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8018907C:
    // 0x8018907C: bne         $a0, $t4, L_80189010
    if (ctx->r4 != ctx->r12) {
        // 0x80189080: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_80189010;
    }
    // 0x80189080: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
    // 0x80189084: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80189088: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018908C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80189090: jr          $ra
    // 0x80189094: nop

    return;
    // 0x80189094: nop

;}
RECOMP_FUNC void SectorY_80197F84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197F84: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80197F88: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80197F8C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80197F90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197F94: lwc1        $f20, 0x74A0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X74A0);
    // 0x80197F98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80197F9C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80197FA0: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80197FA4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80197FA8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80197FAC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80197FB0: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80197FB4: jal         0x8009BC2C
    // 0x80197FB8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80197FB8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x80197FBC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80197FC0: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80197FC4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80197FC8: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80197FCC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80197FD0: jal         0x8009BC2C
    // 0x80197FD4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80197FD4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80197FD8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80197FDC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80197FE0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80197FE4: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x80197FE8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80197FEC: jal         0x8009BC2C
    // 0x80197FF0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80197FF0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x80197FF4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80197FF8: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80197FFC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80198000: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x80198004: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80198008: jal         0x8009BC2C
    // 0x8019800C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8019800C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80198010: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198014: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80198018: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019801C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80198020: jal         0x8009BD38
    // 0x80198024: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x80198024: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x80198028: jal         0x8019B5CC
    // 0x8019802C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B5CC(rdram, ctx);
        goto after_5;
    // 0x8019802C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80198030: beq         $v0, $zero, L_80198058
    if (ctx->r2 == 0) {
        // 0x80198034: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_80198058;
    }
    // 0x80198034: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80198038: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019803C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80198040: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80198044: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80198048: jal         0x8009BC2C
    // 0x8019804C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8019804C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80198050: b           L_8019806C
    // 0x80198054: nop

        goto L_8019806C;
    // 0x80198054: nop

L_80198058:
    // 0x80198058: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019805C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80198060: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80198064: jal         0x8009BC2C
    // 0x80198068: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x80198068: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
L_8019806C:
    // 0x8019806C: jal         0x8019B6E8
    // 0x80198070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B6E8(rdram, ctx);
        goto after_8;
    // 0x80198070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80198074: lh          $t6, 0x52($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X52);
    // 0x80198078: bnel        $t6, $zero, L_8019808C
    if (ctx->r14 != 0) {
        // 0x8019807C: lwc1        $f4, 0x120($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
            goto L_8019808C;
    }
    goto skip_0;
    // 0x8019807C: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    skip_0:
    // 0x80198080: jal         0x8019BC14
    // 0x80198084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019BC14(rdram, ctx);
        goto after_9;
    // 0x80198084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80198088: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
L_8019808C:
    // 0x8019808C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80198090: lwc1        $f8, 0x128($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X128);
    // 0x80198094: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80198098: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019809C: jal         0x80005100
    // 0x801980A0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    Math_Atan2F(rdram, ctx);
        goto after_10;
    // 0x801980A0: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_10:
    // 0x801980A4: jal         0x8009F768
    // 0x801980A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_11;
    // 0x801980A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_11:
    // 0x801980AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801980B0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801980B4: addiu       $a0, $s0, 0x7C
    ctx->r4 = ADD32(ctx->r16, 0X7C);
    // 0x801980B8: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x801980BC: jal         0x8009BD38
    // 0x801980C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_12;
    // 0x801980C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_12:
    // 0x801980C4: lh          $t7, 0x50($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X50);
    // 0x801980C8: bnel        $t7, $zero, L_801980DC
    if (ctx->r15 != 0) {
        // 0x801980CC: lh          $t8, 0xB4($s0)
        ctx->r24 = MEM_H(ctx->r16, 0XB4);
            goto L_801980DC;
    }
    goto skip_1;
    // 0x801980CC: lh          $t8, 0xB4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB4);
    skip_1:
    // 0x801980D0: jal         0x80198244
    // 0x801980D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80198244(rdram, ctx);
        goto after_13;
    // 0x801980D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x801980D8: lh          $t8, 0xB4($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB4);
L_801980DC:
    // 0x801980DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801980E0: bne         $t8, $at, L_8019820C
    if (ctx->r24 != ctx->r1) {
        // 0x801980E4: nop
    
            goto L_8019820C;
    }
    // 0x801980E4: nop

    // 0x801980E8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801980EC: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801980F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801980F4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801980F8: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x801980FC: nop

    // 0x80198100: bc1fl       L_80198114
    if (!c1cs) {
        // 0x80198104: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_80198114;
    }
    goto skip_2;
    // 0x80198104: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_2:
    // 0x80198108: b           L_80198114
    // 0x8019810C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80198114;
    // 0x8019810C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80198110: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80198114:
    // 0x80198114: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x80198118: nop

    // 0x8019811C: bc1f        L_8019820C
    if (!c1cs) {
        // 0x80198120: nop
    
            goto L_8019820C;
    }
    // 0x80198120: nop

    // 0x80198124: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80198128: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8019812C: nop

    // 0x80198130: bc1fl       L_80198144
    if (!c1cs) {
        // 0x80198134: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_80198144;
    }
    goto skip_3;
    // 0x80198134: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_3:
    // 0x80198138: b           L_80198144
    // 0x8019813C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80198144;
    // 0x8019813C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80198140: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80198144:
    // 0x80198144: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x80198148: nop

    // 0x8019814C: bc1f        L_8019820C
    if (!c1cs) {
        // 0x80198150: nop
    
            goto L_8019820C;
    }
    // 0x80198150: nop

    // 0x80198154: lwc1        $f16, 0x120($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80198158: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019815C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80198160: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198164: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80198168: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019816C: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80198170: nop

    // 0x80198174: bc1f        L_8019820C
    if (!c1cs) {
        // 0x80198178: nop
    
            goto L_8019820C;
    }
    // 0x80198178: nop

    // 0x8019817C: lwc1        $f6, 0x128($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X128);
    // 0x80198180: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80198184: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x80198188: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019818C: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80198190: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198194: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80198198: nop

    // 0x8019819C: bc1f        L_8019820C
    if (!c1cs) {
        // 0x801981A0: nop
    
            goto L_8019820C;
    }
    // 0x801981A0: nop

    // 0x801981A4: jal         0x80004EB0
    // 0x801981A8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x801981A8: nop

    after_14:
    // 0x801981AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801981B0: lwc1        $f16, 0x74A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74A4);
    // 0x801981B4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801981B8: nop

    // 0x801981BC: bc1f        L_801981E4
    if (!c1cs) {
        // 0x801981C0: nop
    
            goto L_801981E4;
    }
    // 0x801981C0: nop

    // 0x801981C4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801981C8: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801981CC: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x801981D0: nop

    // 0x801981D4: bc1f        L_801981E4
    if (!c1cs) {
        // 0x801981D8: nop
    
            goto L_801981E4;
    }
    // 0x801981D8: nop

    // 0x801981DC: jal         0x8019AA08
    // 0x801981E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019AA08(rdram, ctx);
        goto after_15;
    // 0x801981E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_801981E4:
    // 0x801981E4: jal         0x80004EB0
    // 0x801981E8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x801981E8: nop

    after_16:
    // 0x801981EC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801981F0: lwc1        $f6, 0x74A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X74A8);
    // 0x801981F4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801981F8: nop

    // 0x801981FC: bc1f        L_8019820C
    if (!c1cs) {
        // 0x80198200: nop
    
            goto L_8019820C;
    }
    // 0x80198200: nop

    // 0x80198204: jal         0x80198244
    // 0x80198208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80198244(rdram, ctx);
        goto after_17;
    // 0x80198208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_8019820C:
    // 0x8019820C: jal         0x8019B528
    // 0x80198210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B528(rdram, ctx);
        goto after_18;
    // 0x80198210: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x80198214: beql        $v0, $zero, L_80198228
    if (ctx->r2 == 0) {
        // 0x80198218: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80198228;
    }
    goto skip_4;
    // 0x80198218: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x8019821C: jal         0x80198ABC
    // 0x80198220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80198ABC(rdram, ctx);
        goto after_19;
    // 0x80198220: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80198224: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80198228:
    // 0x80198228: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8019822C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80198230: jr          $ra
    // 0x80198234: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80198234: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Turret_GreatFoxLaser(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A581C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A5820: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x801A5824: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A5828: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801A582C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x801A5830: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A5834: addiu       $v0, $v0, 0x4750
    ctx->r2 = ADD32(ctx->r2, 0X4750);
    // 0x801A5838: addiu       $s0, $s0, 0x4050
    ctx->r16 = ADD32(ctx->r16, 0X4050);
    // 0x801A583C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_801A5840:
    // 0x801A5840: bne         $t6, $zero, L_801A5888
    if (ctx->r14 != 0) {
        // 0x801A5844: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_801A5888;
    }
    // 0x801A5844: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801A5848: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A584C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A5850: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A5854: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x801A5858: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x801A585C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801A5860: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801A5864: lui         $a3, 0xC2C8
    ctx->r7 = S32(0XC2C8 << 16);
    // 0x801A5868: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A586C: jal         0x801A5560
    // 0x801A5870: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Turret_SetupShot(rdram, ctx);
        goto after_0;
    // 0x801A5870: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x801A5874: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x801A5878: jal         0x800A6028
    // 0x801A587C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    Play_PlaySfxFirstPlayer(rdram, ctx);
        goto after_1;
    // 0x801A587C: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    after_1:
    // 0x801A5880: b           L_801A5898
    // 0x801A5884: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801A5898;
    // 0x801A5884: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801A5888:
    // 0x801A5888: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x801A588C: bnel        $s0, $v0, L_801A5840
    if (ctx->r16 != ctx->r2) {
        // 0x801A5890: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_801A5840;
    }
    goto skip_0;
    // 0x801A5890: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_0:
    // 0x801A5894: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801A5898:
    // 0x801A5898: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801A589C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A58A0: jr          $ra
    // 0x801A58A4: nop

    return;
    // 0x801A58A4: nop

;}
RECOMP_FUNC void Turret_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A6168: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801A616C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801A6170: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A6174: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801A6178: lw          $t6, 0x1C4($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1C4);
    // 0x801A617C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801A6180: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A6184: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801A6188: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801A618C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x801A6190: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801A6194: lhu         $v0, -0x2780($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2780);
    // 0x801A6198: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801A619C: andi        $t8, $v0, 0x800
    ctx->r24 = ctx->r2 & 0X800;
    // 0x801A61A0: beq         $t8, $zero, L_801A61C4
    if (ctx->r24 == 0) {
        // 0x801A61A4: andi        $t9, $v0, 0x400
        ctx->r25 = ctx->r2 & 0X400;
            goto L_801A61C4;
    }
    // 0x801A61A4: andi        $t9, $v0, 0x400
    ctx->r25 = ctx->r2 & 0X400;
    // 0x801A61A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A61AC: lwc1        $f4, 0x6B80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B80);
    // 0x801A61B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A61B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A61B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A61BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A61C0: swc1        $f8, 0x6B80($at)
    MEM_W(0X6B80, ctx->r1) = ctx->f8.u32l;
L_801A61C4:
    // 0x801A61C4: beq         $t9, $zero, L_801A61E4
    if (ctx->r25 == 0) {
        // 0x801A61C8: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801A61E4;
    }
    // 0x801A61C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A61CC: lwc1        $f10, 0x6B80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6B80);
    // 0x801A61D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A61D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A61D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A61DC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A61E0: swc1        $f18, 0x6B80($at)
    MEM_W(0X6B80, ctx->r1) = ctx->f18.u32l;
L_801A61E4:
    // 0x801A61E4: jal         0x80005708
    // 0x801A61E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801A61E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801A61EC: jal         0x800B9358
    // 0x801A61F0: nop

    RCP_SetupDL_36(rdram, ctx);
        goto after_1;
    // 0x801A61F0: nop

    after_1:
    // 0x801A61F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A61F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A61FC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801A6200: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A6204: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A6208: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A620C: jal         0x80005B00
    // 0x801A6210: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801A6210: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    after_2:
    // 0x801A6214: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A6218: lwc1        $f6, 0x7EF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7EF8);
    // 0x801A621C: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x801A6220: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6224: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A6228: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A622C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A6230: jal         0x80005E90
    // 0x801A6234: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A6234: nop

    after_3:
    // 0x801A6238: lwc1        $f10, 0xE4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x801A623C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A6240: lwc1        $f18, 0x7EFC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7EFC);
    // 0x801A6244: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x801A6248: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A624C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A6250: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A6254: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A6258: jal         0x80005D44
    // 0x801A625C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801A625C: nop

    after_4:
    // 0x801A6260: lw          $t1, 0x1B0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1B0);
    // 0x801A6264: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x801A6268: beql        $at, $zero, L_801A62C8
    if (ctx->r1 == 0) {
        // 0x801A626C: lui         $a3, 0xC59C
        ctx->r7 = S32(0XC59C << 16);
            goto L_801A62C8;
    }
    goto skip_0;
    // 0x801A626C: lui         $a3, 0xC59C
    ctx->r7 = S32(0XC59C << 16);
    skip_0:
    // 0x801A6270: lw          $t2, 0x1BC($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1BC);
    // 0x801A6274: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A6278: lwc1        $f10, 0x7F00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7F00);
    // 0x801A627C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801A6280: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801A6284: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801A6288: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801A628C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x801A6290: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A6294: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A6298: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801A629C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A62A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A62A4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801A62A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A62AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A62B0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801A62B4: jal         0x80005B00
    // 0x801A62B8: nop

    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x801A62B8: nop

    after_5:
    // 0x801A62BC: b           L_801A62E8
    // 0x801A62C0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
        goto L_801A62E8;
    // 0x801A62C0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801A62C4: lui         $a3, 0xC59C
    ctx->r7 = S32(0XC59C << 16);
L_801A62C8:
    // 0x801A62C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A62CC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801A62D0: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x801A62D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A62D8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A62DC: jal         0x80005B00
    // 0x801A62E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x801A62E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_6:
    // 0x801A62E4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
L_801A62E8:
    // 0x801A62E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A62EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A62F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801A62F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A62F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A62FC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6300: jal         0x80005C34
    // 0x801A6304: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x801A6304: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
    // 0x801A6308: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A630C: jal         0x80006EB8
    // 0x801A6310: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x801A6310: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_8:
    // 0x801A6314: jal         0x80005740
    // 0x801A6318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x801A6318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801A631C: jal         0x800BA400
    // 0x801A6320: nop

    RCP_SetupDL_27(rdram, ctx);
        goto after_10;
    // 0x801A6320: nop

    after_10:
    // 0x801A6324: lw          $t7, 0x1BC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1BC);
    // 0x801A6328: slti        $at, $t7, 0x15
    ctx->r1 = SIGNED(ctx->r15) < 0X15 ? 1 : 0;
    // 0x801A632C: bne         $at, $zero, L_801A6370
    if (ctx->r1 != 0) {
        // 0x801A6330: nop
    
            goto L_801A6370;
    }
    // 0x801A6330: nop

    // 0x801A6334: lw          $t8, 0x1B0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1B0);
    // 0x801A6338: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801A633C: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801A6340: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x801A6344: bne         $at, $zero, L_801A6370
    if (ctx->r1 != 0) {
        // 0x801A6348: lui         $t1, 0xC800
        ctx->r9 = S32(0XC800 << 16);
            goto L_801A6370;
    }
    // 0x801A6348: lui         $t1, 0xC800
    ctx->r9 = S32(0XC800 << 16);
    // 0x801A634C: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x801A6350: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A6354: ori         $t1, $t1, 0x64FF
    ctx->r9 = ctx->r9 | 0X64FF;
    // 0x801A6358: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A635C: sw          $t9, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r25;
    // 0x801A6360: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801A6364: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801A6368: b           L_801A6394
    // 0x801A636C: nop

        goto L_801A6394;
    // 0x801A636C: nop

L_801A6370:
    // 0x801A6370: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801A6374: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x801A6378: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A637C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801A6380: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801A6384: sw          $t2, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r10;
    // 0x801A6388: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801A638C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A6390: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_801A6394:
    // 0x801A6394: jal         0x80005708
    // 0x801A6398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x801A6398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x801A639C: lw          $t5, 0x1BC($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X1BC);
    // 0x801A63A0: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x801A63A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A63A8: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x801A63AC: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x801A63B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A63B4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A63B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A63BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A63C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A63C4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801A63C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A63CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A63D0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801A63D4: jal         0x80005B00
    // 0x801A63D8: nop

    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x801A63D8: nop

    after_12:
    // 0x801A63DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A63E0: lwc1        $f16, 0x7F04($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7F04);
    // 0x801A63E4: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x801A63E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A63EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A63F0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801A63F4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A63F8: jal         0x80005E90
    // 0x801A63FC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x801A63FC: nop

    after_13:
    // 0x801A6400: lwc1        $f4, 0xE4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x801A6404: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A6408: lwc1        $f8, 0x7F08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7F08);
    // 0x801A640C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801A6410: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6414: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A6418: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A641C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A6420: jal         0x80005D44
    // 0x801A6424: nop

    Matrix_RotateX(rdram, ctx);
        goto after_14;
    // 0x801A6424: nop

    after_14:
    // 0x801A6428: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A642C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A6430: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A6434: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A6438: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A643C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A6440: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A6444: jal         0x80005C34
    // 0x801A6448: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_15;
    // 0x801A6448: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_15:
    // 0x801A644C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A6450: jal         0x80006EB8
    // 0x801A6454: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x801A6454: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_16:
    // 0x801A6458: jal         0x80005740
    // 0x801A645C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x801A645C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x801A6460: jal         0x80005708
    // 0x801A6464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_18;
    // 0x801A6464: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x801A6468: lw          $t8, 0x1BC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1BC);
    // 0x801A646C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x801A6470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A6474: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801A6478: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A647C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A6480: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801A6484: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6488: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x801A648C: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x801A6490: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A6494: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801A6498: jal         0x80005B00
    // 0x801A649C: nop

    Matrix_Translate(rdram, ctx);
        goto after_19;
    // 0x801A649C: nop

    after_19:
    // 0x801A64A0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A64A4: lwc1        $f10, 0x7F0C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7F0C);
    // 0x801A64A8: lwc1        $f8, 0xE8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x801A64AC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A64B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A64B4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A64B8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A64BC: jal         0x80005E90
    // 0x801A64C0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_20;
    // 0x801A64C0: nop

    after_20:
    // 0x801A64C4: lwc1        $f18, 0xE4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x801A64C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A64CC: lwc1        $f6, 0x7F10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F10);
    // 0x801A64D0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801A64D4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A64D8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A64DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A64E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A64E4: jal         0x80005D44
    // 0x801A64E8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_21;
    // 0x801A64E8: nop

    after_21:
    // 0x801A64EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A64F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A64F4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A64F8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801A64FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A6500: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A6504: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A6508: jal         0x80005C34
    // 0x801A650C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_22;
    // 0x801A650C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_22:
    // 0x801A6510: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A6514: jal         0x80006EB8
    // 0x801A6518: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_23;
    // 0x801A6518: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_23:
    // 0x801A651C: jal         0x80005740
    // 0x801A6520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_24;
    // 0x801A6520: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x801A6524: lw          $t1, 0x1BC($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X1BC);
    // 0x801A6528: slti        $at, $t1, 0x15
    ctx->r1 = SIGNED(ctx->r9) < 0X15 ? 1 : 0;
    // 0x801A652C: bnel        $at, $zero, L_801A673C
    if (ctx->r1 != 0) {
        // 0x801A6530: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801A673C;
    }
    goto skip_1;
    // 0x801A6530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801A6534: lw          $t2, 0x1B0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1B0);
    // 0x801A6538: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x801A653C: bnel        $at, $zero, L_801A673C
    if (ctx->r1 != 0) {
        // 0x801A6540: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801A673C;
    }
    goto skip_2;
    // 0x801A6540: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x801A6544: jal         0x800BA140
    // 0x801A6548: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_25;
    // 0x801A6548: nop

    after_25:
    // 0x801A654C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801A6550: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x801A6554: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801A6558: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801A655C: addiu       $t5, $zero, -0x80
    ctx->r13 = ADD32(0, -0X80);
    // 0x801A6560: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A6564: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x801A6568: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A656C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801A6570: jal         0x80005708
    // 0x801A6574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_26;
    // 0x801A6574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x801A6578: lw          $t6, 0x1BC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1BC);
    // 0x801A657C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x801A6580: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A6584: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801A6588: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A658C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A6590: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801A6594: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6598: lui         $a1, 0xC2C8
    ctx->r5 = S32(0XC2C8 << 16);
    // 0x801A659C: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x801A65A0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A65A4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801A65A8: jal         0x80005B00
    // 0x801A65AC: nop

    Matrix_Translate(rdram, ctx);
        goto after_27;
    // 0x801A65AC: nop

    after_27:
    // 0x801A65B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A65B4: lwc1        $f8, 0x7F14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7F14);
    // 0x801A65B8: lwc1        $f6, 0xE8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x801A65BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A65C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A65C4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A65C8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A65CC: jal         0x80005E90
    // 0x801A65D0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_28;
    // 0x801A65D0: nop

    after_28:
    // 0x801A65D4: lwc1        $f16, 0xE4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x801A65D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A65DC: lwc1        $f4, 0x7F18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7F18);
    // 0x801A65E0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x801A65E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A65E8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801A65EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A65F0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A65F4: jal         0x80005D44
    // 0x801A65F8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_29;
    // 0x801A65F8: nop

    after_29:
    // 0x801A65FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A6600: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A6604: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A6608: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A660C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A6610: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6614: jal         0x80005B00
    // 0x801A6618: lui         $a3, 0xC33C
    ctx->r7 = S32(0XC33C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_30;
    // 0x801A6618: lui         $a3, 0xC33C
    ctx->r7 = S32(0XC33C << 16);
    after_30:
    // 0x801A661C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A6620: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A6624: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A6628: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A662C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A6630: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A6634: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A6638: jal         0x80005C34
    // 0x801A663C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_31;
    // 0x801A663C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_31:
    // 0x801A6640: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A6644: jal         0x80006EB8
    // 0x801A6648: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_32;
    // 0x801A6648: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_32:
    // 0x801A664C: jal         0x80005740
    // 0x801A6650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_33;
    // 0x801A6650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x801A6654: jal         0x80005708
    // 0x801A6658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_34;
    // 0x801A6658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x801A665C: lw          $t0, 0x1BC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1BC);
    // 0x801A6660: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x801A6664: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A6668: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801A666C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A6670: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A6674: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801A6678: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A667C: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x801A6680: lui         $a2, 0xC2C8
    ctx->r6 = S32(0XC2C8 << 16);
    // 0x801A6684: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A6688: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801A668C: jal         0x80005B00
    // 0x801A6690: nop

    Matrix_Translate(rdram, ctx);
        goto after_35;
    // 0x801A6690: nop

    after_35:
    // 0x801A6694: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A6698: lwc1        $f6, 0x7F1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F1C);
    // 0x801A669C: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x801A66A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A66A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A66A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A66AC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A66B0: jal         0x80005E90
    // 0x801A66B4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_36;
    // 0x801A66B4: nop

    after_36:
    // 0x801A66B8: lwc1        $f10, 0xE4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x801A66BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A66C0: lwc1        $f18, 0x7F20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7F20);
    // 0x801A66C4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x801A66C8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A66CC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A66D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A66D4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A66D8: jal         0x80005D44
    // 0x801A66DC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_37;
    // 0x801A66DC: nop

    after_37:
    // 0x801A66E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A66E4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A66E8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801A66EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A66F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A66F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A66F8: jal         0x80005B00
    // 0x801A66FC: lui         $a3, 0xC33C
    ctx->r7 = S32(0XC33C << 16);
    Matrix_Translate(rdram, ctx);
        goto after_38;
    // 0x801A66FC: lui         $a3, 0xC33C
    ctx->r7 = S32(0XC33C << 16);
    after_38:
    // 0x801A6700: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A6704: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A6708: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A670C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A6710: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A6714: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A6718: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A671C: jal         0x80005C34
    // 0x801A6720: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_39;
    // 0x801A6720: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_39:
    // 0x801A6724: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A6728: jal         0x80006EB8
    // 0x801A672C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_40;
    // 0x801A672C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_40:
    // 0x801A6730: jal         0x80005740
    // 0x801A6734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_41;
    // 0x801A6734: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x801A6738: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801A673C:
    // 0x801A673C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801A6740: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801A6744: jr          $ra
    // 0x801A6748: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801A6748: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Andross_LoadEscapePath(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187C5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80187C60: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80187C64: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80187C68: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80187C6C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80187C70: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80187C74: jal         0x80004EB0
    // 0x80187C78: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80187C78: nop

    after_0:
    // 0x80187C7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80187C80: lwc1        $f4, 0x6BC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6BC4);
    // 0x80187C84: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80187C88: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80187C8C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80187C90: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x80187C94: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80187C98: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80187C9C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80187CA0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80187CA4: nop

    // 0x80187CA8: beq         $v0, $zero, L_80187CD0
    if (ctx->r2 == 0) {
        // 0x80187CAC: nop
    
            goto L_80187CD0;
    }
    // 0x80187CAC: nop

    // 0x80187CB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80187CB4: beq         $v0, $at, L_80187D04
    if (ctx->r2 == ctx->r1) {
        // 0x80187CB8: lui         $s2, 0x8018
        ctx->r18 = S32(0X8018 << 16);
            goto L_80187D04;
    }
    // 0x80187CB8: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80187CBC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80187CC0: beq         $v0, $at, L_80187D48
    if (ctx->r2 == ctx->r1) {
        // 0x80187CC4: nop
    
            goto L_80187D48;
    }
    // 0x80187CC4: nop

    // 0x80187CC8: b           L_80187D48
    // 0x80187CCC: nop

        goto L_80187D48;
    // 0x80187CCC: nop

L_80187CD0:
    // 0x80187CD0: lui         $v0, 0xC03
    ctx->r2 = S32(0XC03 << 16);
    // 0x80187CD4: addiu       $v0, $v0, 0x6310
    ctx->r2 = ADD32(ctx->r2, 0X6310);
    // 0x80187CD8: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80187CDC: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x80187CE0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80187CE4: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80187CE8: lw          $t0, 0x1FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FD0);
    // 0x80187CEC: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80187CF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80187CF4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80187CF8: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x80187CFC: b           L_80187D8C
    // 0x80187D00: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
        goto L_80187D8C;
    // 0x80187D00: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
L_80187D04:
    // 0x80187D04: lui         $v0, 0xC03
    ctx->r2 = S32(0XC03 << 16);
    // 0x80187D08: addiu       $v0, $v0, 0x6B6C
    ctx->r2 = ADD32(ctx->r2, 0X6B6C);
    // 0x80187D0C: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x80187D10: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x80187D14: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80187D18: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80187D1C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80187D20: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80187D24: lw          $t7, 0x1FD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1FD0);
    // 0x80187D28: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80187D2C: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80187D30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80187D34: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80187D38: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x80187D3C: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x80187D40: b           L_80187D8C
    // 0x80187D44: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
        goto L_80187D8C;
    // 0x80187D44: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
L_80187D48:
    // 0x80187D48: lui         $v0, 0xC03
    ctx->r2 = S32(0XC03 << 16);
    // 0x80187D4C: addiu       $v0, $v0, 0x733C
    ctx->r2 = ADD32(ctx->r2, 0X733C);
    // 0x80187D50: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x80187D54: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x80187D58: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80187D5C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80187D60: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80187D64: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80187D68: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x80187D6C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80187D70: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x80187D74: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80187D78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80187D7C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80187D80: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x80187D84: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80187D88: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
L_80187D8C:
    // 0x80187D8C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80187D90: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x80187D94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80187D98: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80187D9C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80187DA0:
    // 0x80187DA0: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80187DA4: lh          $v0, 0x10($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X10);
    // 0x80187DA8: bgez        $v0, L_80187DB8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80187DAC: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_80187DB8;
    }
    // 0x80187DAC: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x80187DB0: b           L_80187EEC
    // 0x80187DB4: nop

        goto L_80187EEC;
    // 0x80187DB4: nop

L_80187DB8:
    // 0x80187DB8: beql        $at, $zero, L_80187EE0
    if (ctx->r1 == 0) {
        // 0x80187DBC: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80187EE0;
    }
    goto skip_0;
    // 0x80187DBC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_0:
    // 0x80187DC0: jal         0x800A4F4C
    // 0x80187DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Initialize(rdram, ctx);
        goto after_1;
    // 0x80187DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80187DC8: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80187DCC: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80187DD0: addiu       $at, $zero, 0x93
    ctx->r1 = ADD32(0, 0X93);
    // 0x80187DD4: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80187DD8: lh          $t2, 0x10($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X10);
    // 0x80187DDC: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x80187DE0: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80187DE4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80187DE8: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80187DEC: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x80187DF0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80187DF4: nop

    // 0x80187DF8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80187DFC: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80187E00: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80187E04: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80187E08: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80187E0C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80187E10: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80187E14: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80187E18: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80187E1C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80187E20: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80187E24: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80187E28: nop

    // 0x80187E2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80187E30: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80187E34: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80187E38: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80187E3C: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x80187E40: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x80187E44: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80187E48: nop

    // 0x80187E4C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80187E50: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80187E54: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80187E58: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80187E5C: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x80187E60: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80187E64: nop

    // 0x80187E68: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80187E6C: bne         $a1, $at, L_80187E88
    if (ctx->r5 != ctx->r1) {
        // 0x80187E70: swc1        $f6, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
            goto L_80187E88;
    }
    // 0x80187E70: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80187E74: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80187E78: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80187E7C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80187E80: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x80187E84: sb          $t9, 0x40($s0)
    MEM_B(0X40, ctx->r16) = ctx->r25;
L_80187E88:
    // 0x80187E88: jal         0x800612B8
    // 0x80187E8C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x80187E8C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    after_2:
    // 0x80187E90: lhu         $t0, 0x2($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X2);
    // 0x80187E94: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x80187E98: lui         $v0, 0xC04
    ctx->r2 = S32(0XC04 << 16);
    // 0x80187E9C: bne         $t0, $at, L_80187ED8
    if (ctx->r8 != ctx->r1) {
        // 0x80187EA0: addiu       $v0, $v0, -0x7334
        ctx->r2 = ADD32(ctx->r2, -0X7334);
            goto L_80187ED8;
    }
    // 0x80187EA0: addiu       $v0, $v0, -0x7334
    ctx->r2 = ADD32(ctx->r2, -0X7334);
    // 0x80187EA4: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x80187EA8: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x80187EAC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80187EB0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80187EB4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80187EB8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80187EBC: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x80187EC0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80187EC4: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x80187EC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80187ECC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80187ED0: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80187ED4: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
L_80187ED8:
    // 0x80187ED8: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80187EDC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80187EE0:
    // 0x80187EE0: slti        $at, $s1, 0x4E20
    ctx->r1 = SIGNED(ctx->r17) < 0X4E20 ? 1 : 0;
    // 0x80187EE4: bnel        $at, $zero, L_80187DA0
    if (ctx->r1 != 0) {
        // 0x80187EE8: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80187DA0;
    }
    goto skip_1;
    // 0x80187EE8: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_80187EEC:
    // 0x80187EEC: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80187EF0: addiu       $s0, $s0, 0x42D4
    ctx->r16 = ADD32(ctx->r16, 0X42D4);
    // 0x80187EF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80187EF8: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80187EFC:
    // 0x80187EFC: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80187F00: lh          $v0, 0x10($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X10);
    // 0x80187F04: bgez        $v0, L_80187F14
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80187F08: slti        $at, $v0, 0x124
        ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
            goto L_80187F14;
    }
    // 0x80187F08: slti        $at, $v0, 0x124
    ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
    // 0x80187F0C: b           L_80187FEC
    // 0x80187F10: nop

        goto L_80187FEC;
    // 0x80187F10: nop

L_80187F14:
    // 0x80187F14: beq         $at, $zero, L_80187FDC
    if (ctx->r1 == 0) {
        // 0x80187F18: slti        $at, $v0, 0xB0
        ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
            goto L_80187FDC;
    }
    // 0x80187F18: slti        $at, $v0, 0xB0
    ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
    // 0x80187F1C: bnel        $at, $zero, L_80187FE0
    if (ctx->r1 != 0) {
        // 0x80187F20: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80187FE0;
    }
    goto skip_2;
    // 0x80187F20: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_2:
    // 0x80187F24: jal         0x800613C4
    // 0x80187F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_3;
    // 0x80187F28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80187F2C: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80187F30: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80187F34: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80187F38: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80187F3C: lh          $t2, 0x10($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X10);
    // 0x80187F40: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x80187F44: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80187F48: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80187F4C: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80187F50: lh          $t5, 0x6($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X6);
    // 0x80187F54: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80187F58: nop

    // 0x80187F5C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80187F60: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x80187F64: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80187F68: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80187F6C: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80187F70: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80187F74: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80187F78: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80187F7C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80187F80: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80187F84: lh          $t0, 0x4($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4);
    // 0x80187F88: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80187F8C: nop

    // 0x80187F90: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80187F94: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80187F98: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80187F9C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80187FA0: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x80187FA4: lh          $t3, 0x8($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X8);
    // 0x80187FA8: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80187FAC: nop

    // 0x80187FB0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80187FB4: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80187FB8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80187FBC: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80187FC0: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x80187FC4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80187FC8: nop

    // 0x80187FCC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80187FD0: jal         0x800612B8
    // 0x80187FD4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x80187FD4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80187FD8: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_80187FDC:
    // 0x80187FDC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80187FE0:
    // 0x80187FE0: slti        $at, $s1, 0x4E20
    ctx->r1 = SIGNED(ctx->r17) < 0X4E20 ? 1 : 0;
    // 0x80187FE4: bnel        $at, $zero, L_80187EFC
    if (ctx->r1 != 0) {
        // 0x80187FE8: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80187EFC;
    }
    goto skip_3;
    // 0x80187FE8: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_3:
L_80187FEC:
    // 0x80187FEC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80187FF0: addiu       $s0, $s0, 0x37E0
    ctx->r16 = ADD32(ctx->r16, 0X37E0);
    // 0x80187FF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80187FF8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_80187FFC:
    // 0x80187FFC: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80188000: lh          $v0, 0x10($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X10);
    // 0x80188004: bltz        $v0, L_801880C8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80188008: slti        $at, $v0, 0x153
        ctx->r1 = SIGNED(ctx->r2) < 0X153 ? 1 : 0;
            goto L_801880C8;
    }
    // 0x80188008: slti        $at, $v0, 0x153
    ctx->r1 = SIGNED(ctx->r2) < 0X153 ? 1 : 0;
    // 0x8018800C: beq         $at, $zero, L_801880B8
    if (ctx->r1 == 0) {
        // 0x80188010: slti        $at, $v0, 0x142
        ctx->r1 = SIGNED(ctx->r2) < 0X142 ? 1 : 0;
            goto L_801880B8;
    }
    // 0x80188010: slti        $at, $v0, 0x142
    ctx->r1 = SIGNED(ctx->r2) < 0X142 ? 1 : 0;
    // 0x80188014: bnel        $at, $zero, L_801880BC
    if (ctx->r1 != 0) {
        // 0x80188018: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_801880BC;
    }
    goto skip_4;
    // 0x80188018: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_4:
    // 0x8018801C: jal         0x80061444
    // 0x80188020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_Initialize(rdram, ctx);
        goto after_5;
    // 0x80188020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80188024: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80188028: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8018802C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80188030: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80188034: lh          $t1, 0x10($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X10);
    // 0x80188038: sh          $t1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r9;
    // 0x8018803C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80188040: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80188044: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80188048: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x8018804C: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80188050: nop

    // 0x80188054: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80188058: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x8018805C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80188060: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80188064: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80188068: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018806C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80188070: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80188074: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80188078: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8018807C: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80188080: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80188084: nop

    // 0x80188088: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018808C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80188090: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x80188094: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80188098: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8018809C: lh          $t2, 0x8($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X8);
    // 0x801880A0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x801880A4: nop

    // 0x801880A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801880AC: jal         0x800612B8
    // 0x801880B0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x801880B0: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_6:
    // 0x801880B4: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
L_801880B8:
    // 0x801880B8: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_801880BC:
    // 0x801880BC: addiu       $at, $zero, 0x4E20
    ctx->r1 = ADD32(0, 0X4E20);
    // 0x801880C0: bnel        $s1, $at, L_80187FFC
    if (ctx->r17 != ctx->r1) {
        // 0x801880C4: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_80187FFC;
    }
    goto skip_5;
    // 0x801880C4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_5:
L_801880C8:
    // 0x801880C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801880CC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801880D0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801880D4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801880D8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801880DC: jr          $ra
    // 0x801880E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801880E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void SectorY_8019A520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A520: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019A524: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019A528: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019A52C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019A530: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019A534: jal         0x8019B6E8
    // 0x8019A538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B6E8(rdram, ctx);
        goto after_0;
    // 0x8019A538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019A53C: lh          $t6, 0x52($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X52);
    // 0x8019A540: bne         $t6, $zero, L_8019A550
    if (ctx->r14 != 0) {
        // 0x8019A544: nop
    
            goto L_8019A550;
    }
    // 0x8019A544: nop

    // 0x8019A548: jal         0x8019BC14
    // 0x8019A54C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019BC14(rdram, ctx);
        goto after_1;
    // 0x8019A54C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_8019A550:
    // 0x8019A550: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A554: lwc1        $f20, 0x75A4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X75A4);
    // 0x8019A558: addiu       $a0, $s0, 0x7C
    ctx->r4 = ADD32(ctx->r16, 0X7C);
    // 0x8019A55C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019A560: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019A564: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019A568: jal         0x8009BD38
    // 0x8019A56C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_2;
    // 0x8019A56C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x8019A570: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019A574: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8019A578: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019A57C: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8019A580: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019A584: jal         0x8009BC2C
    // 0x8019A588: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8019A588: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x8019A58C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019A590: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8019A594: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019A598: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x8019A59C: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x8019A5A0: jal         0x8009BC2C
    // 0x8019A5A4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8019A5A4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x8019A5A8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019A5AC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8019A5B0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019A5B4: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8019A5B8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019A5BC: jal         0x8009BC2C
    // 0x8019A5C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8019A5C0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x8019A5C4: lh          $t7, 0x56($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X56);
    // 0x8019A5C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019A5CC: bnel        $t7, $zero, L_8019A5E8
    if (ctx->r15 != 0) {
        // 0x8019A5D0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_8019A5E8;
    }
    goto skip_0;
    // 0x8019A5D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x8019A5D4: jal         0x8019A640
    // 0x8019A5D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019A640(rdram, ctx);
        goto after_6;
    // 0x8019A5D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8019A5DC: b           L_8019A5F4
    // 0x8019A5E0: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
        goto L_8019A5F4;
    // 0x8019A5E0: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
    // 0x8019A5E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_8019A5E8:
    // 0x8019A5E8: nop

    // 0x8019A5EC: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
    // 0x8019A5F0: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
L_8019A5F4:
    // 0x8019A5F4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A5F8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A5FC: beq         $v0, $zero, L_8019A608
    if (ctx->r2 == 0) {
        // 0x8019A600: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_8019A608;
    }
    // 0x8019A600: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8019A604: bne         $v0, $at, L_8019A62C
    if (ctx->r2 != ctx->r1) {
        // 0x8019A608: lui         $t8, 0x800C
        ctx->r24 = S32(0X800C << 16);
            goto L_8019A62C;
    }
L_8019A608:
    // 0x8019A608: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8019A60C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8019A610: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x8019A614: ori         $a0, $a0, 0x2019
    ctx->r4 = ctx->r4 | 0X2019;
    // 0x8019A618: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8019A61C: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019A620: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A624: jal         0x80019218
    // 0x8019A628: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8019A628: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_7:
L_8019A62C:
    // 0x8019A62C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A630: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8019A634: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019A638: jr          $ra
    // 0x8019A63C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8019A63C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Andross_Gate_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018769C: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x801876A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801876A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801876A8: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x801876AC: addiu       $a0, $a0, 0x4658
    ctx->r4 = ADD32(ctx->r4, 0X4658);
    // 0x801876B0: lh          $a1, 0xB6($a3)
    ctx->r5 = MEM_H(ctx->r7, 0XB6);
    // 0x801876B4: jal         0x8009AA20
    // 0x801876B8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x801876B8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x801876BC: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801876C0: addiu       $t6, $t6, 0x4660
    ctx->r14 = ADD32(ctx->r14, 0X4660);
    // 0x801876C4: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801876C8: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801876CC: addiu       $a3, $a3, 0x767C
    ctx->r7 = ADD32(ctx->r7, 0X767C);
    // 0x801876D0: addiu       $a1, $a1, 0x4844
    ctx->r5 = ADD32(ctx->r5, 0X4844);
    // 0x801876D4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801876D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801876DC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801876E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801876E4: jal         0x8009A72C
    // 0x801876E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x801876E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x801876EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801876F0: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    // 0x801876F4: jr          $ra
    // 0x801876F8: nop

    return;
    // 0x801876F8: nop

;}
RECOMP_FUNC void Andross_AndBrain_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189B70: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80189B74: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80189B78: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80189B7C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80189B80: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80189B84: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80189B88: jal         0x80188A4C
    // 0x80189B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Andross_AndBrain_HandleDamage(rdram, ctx);
        goto after_0;
    // 0x80189B8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80189B90: jal         0x80188CB8
    // 0x80189B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Andross_AndBrain_Control(rdram, ctx);
        goto after_1;
    // 0x80189B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80189B98: lui         $v0, 0xC04
    ctx->r2 = S32(0XC04 << 16);
    // 0x80189B9C: addiu       $v0, $v0, -0x70DC
    ctx->r2 = ADD32(ctx->r2, -0X70DC);
    // 0x80189BA0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80189BA4: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x80189BA8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80189BAC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80189BB0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80189BB4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80189BB8: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x80189BBC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80189BC0: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x80189BC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80189BC8: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80189BCC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189BD0: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80189BD4: sw          $t2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r10;
    // 0x80189BD8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80189BDC: addiu       $a0, $a0, -0x63D0
    ctx->r4 = ADD32(ctx->r4, -0X63D0);
    // 0x80189BE0: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x80189BE4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80189BE8: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80189BEC: jal         0x8009BC2C
    // 0x80189BF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80189BF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80189BF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189BF8: lwc1        $f2, 0x6C18($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6C18);
    // 0x80189BFC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80189C00: addiu       $a0, $s1, 0x3F8
    ctx->r4 = ADD32(ctx->r17, 0X3F8);
    // 0x80189C04: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80189C08: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80189C0C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x80189C10: jal         0x8009BC2C
    // 0x80189C14: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80189C14: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80189C18: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80189C1C: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x80189C20: andi        $t4, $t3, 0x10
    ctx->r12 = ctx->r11 & 0X10;
    // 0x80189C24: bnel        $t4, $zero, L_80189C54
    if (ctx->r12 != 0) {
        // 0x80189C28: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_80189C54;
    }
    goto skip_0;
    // 0x80189C28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x80189C2C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80189C30: addiu       $a0, $s1, 0x13C
    ctx->r4 = ADD32(ctx->r17, 0X13C);
    // 0x80189C34: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x80189C38: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80189C3C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80189C40: jal         0x8009BC2C
    // 0x80189C44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80189C44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80189C48: b           L_80189C6C
    // 0x80189C4C: nop

        goto L_80189C6C;
    // 0x80189C4C: nop

    // 0x80189C50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_80189C54:
    // 0x80189C54: addiu       $a0, $s1, 0x13C
    ctx->r4 = ADD32(ctx->r17, 0X13C);
    // 0x80189C58: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x80189C5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80189C60: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80189C64: jal         0x8009BC2C
    // 0x80189C68: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80189C68: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
L_80189C6C:
    // 0x80189C6C: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80189C70: addiu       $s2, $s2, -0x7D80
    ctx->r18 = ADD32(ctx->r18, -0X7D80);
    // 0x80189C74: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80189C78: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80189C7C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80189C80: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80189C84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80189C88: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80189C8C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80189C90: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80189C94: nop

    // 0x80189C98: bc1fl       L_80189D3C
    if (!c1cs) {
        // 0x80189C9C: lhu         $t0, 0x4E($s1)
        ctx->r8 = MEM_HU(ctx->r17, 0X4E);
            goto L_80189D3C;
    }
    goto skip_1;
    // 0x80189C9C: lhu         $t0, 0x4E($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X4E);
    skip_1:
    // 0x80189CA0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80189CA4: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80189CA8: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80189CAC: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80189CB0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80189CB4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80189CB8: nop

    // 0x80189CBC: bc1fl       L_80189D3C
    if (!c1cs) {
        // 0x80189CC0: lhu         $t0, 0x4E($s1)
        ctx->r8 = MEM_HU(ctx->r17, 0X4E);
            goto L_80189D3C;
    }
    goto skip_2;
    // 0x80189CC0: lhu         $t0, 0x4E($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X4E);
    skip_2:
    // 0x80189CC4: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80189CC8: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80189CCC: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80189CD0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80189CD4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80189CD8: nop

    // 0x80189CDC: bc1fl       L_80189D3C
    if (!c1cs) {
        // 0x80189CE0: lhu         $t0, 0x4E($s1)
        ctx->r8 = MEM_HU(ctx->r17, 0X4E);
            goto L_80189D3C;
    }
    goto skip_3;
    // 0x80189CE0: lhu         $t0, 0x4E($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X4E);
    skip_3:
    // 0x80189CE4: lh          $t5, 0x4E($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X4E);
    // 0x80189CE8: slti        $at, $t5, 0xB
    ctx->r1 = SIGNED(ctx->r13) < 0XB ? 1 : 0;
    // 0x80189CEC: beql        $at, $zero, L_80189D3C
    if (ctx->r1 == 0) {
        // 0x80189CF0: lhu         $t0, 0x4E($s1)
        ctx->r8 = MEM_HU(ctx->r17, 0X4E);
            goto L_80189D3C;
    }
    goto skip_4;
    // 0x80189CF0: lhu         $t0, 0x4E($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X4E);
    skip_4:
    // 0x80189CF4: lh          $t6, 0x5A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X5A);
    // 0x80189CF8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189CFC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189D00: bne         $t6, $zero, L_80189D38
    if (ctx->r14 != 0) {
        // 0x80189D04: addiu       $t7, $zero, 0xB
        ctx->r15 = ADD32(0, 0XB);
            goto L_80189D38;
    }
    // 0x80189D04: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80189D08: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x80189D0C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80189D10: sh          $t7, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r15;
    // 0x80189D14: sh          $t8, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r24;
    // 0x80189D18: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80189D1C: lui         $a0, 0x3140
    ctx->r4 = S32(0X3140 << 16);
    // 0x80189D20: ori         $a0, $a0, 0x8097
    ctx->r4 = ctx->r4 | 0X8097;
    // 0x80189D24: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80189D28: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189D2C: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80189D30: jal         0x80019218
    // 0x80189D34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x80189D34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_6:
L_80189D38:
    // 0x80189D38: lhu         $t0, 0x4E($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X4E);
L_80189D3C:
    // 0x80189D3C: sltiu       $at, $t0, 0x16
    ctx->r1 = ctx->r8 < 0X16 ? 1 : 0;
    // 0x80189D40: beq         $at, $zero, L_8018B07C
    if (ctx->r1 == 0) {
        // 0x80189D44: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_8018B07C;
    }
    // 0x80189D44: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80189D48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189D4C: addu        $at, $at, $t0
    gpr jr_addend_80189D54 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80189D50: lw          $t0, 0x6C1C($at)
    ctx->r8 = ADD32(ctx->r1, 0X6C1C);
    // 0x80189D54: jr          $t0
    // 0x80189D58: nop

    switch (jr_addend_80189D54 >> 2) {
        case 0: goto L_80189D5C; break;
        case 1: goto L_80189EA4; break;
        case 2: goto L_80189FDC; break;
        case 3: goto L_8018A338; break;
        case 4: goto L_8018B07C; break;
        case 5: goto L_8018B07C; break;
        case 6: goto L_8018B07C; break;
        case 7: goto L_8018B07C; break;
        case 8: goto L_8018B07C; break;
        case 9: goto L_8018B07C; break;
        case 10: goto L_80189DF8; break;
        case 11: goto L_8018A038; break;
        case 12: goto L_8018A378; break;
        case 13: goto L_8018A4D8; break;
        case 14: goto L_8018B07C; break;
        case 15: goto L_8018B07C; break;
        case 16: goto L_8018B07C; break;
        case 17: goto L_8018B07C; break;
        case 18: goto L_8018B07C; break;
        case 19: goto L_8018B07C; break;
        case 20: goto L_8018A548; break;
        case 21: goto L_8018A9B8; break;
        default: switch_error(__func__, 0x80189D54, 0x801A6C1C);
    }
    // 0x80189D58: nop

L_80189D5C:
    // 0x80189D5C: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x80189D60: sh          $t1, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r9;
    // 0x80189D64: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80189D68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189D6C: sb          $t2, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = ctx->r10;
    // 0x80189D70: lui         $at, 0xC1D0
    ctx->r1 = S32(0XC1D0 << 16);
    // 0x80189D74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189D78: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80189D7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80189D84: addiu       $s0, $s1, 0x3FC
    ctx->r16 = ADD32(ctx->r17, 0X3FC);
    // 0x80189D88: swc1        $f10, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f10.u32l;
    // 0x80189D8C: jal         0x80189098
    // 0x80189D90: swc1        $f4, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f4.u32l;
    Andross_AndBrainEyes_Setup(rdram, ctx);
        goto after_7;
    // 0x80189D90: swc1        $f4, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f4.u32l;
    after_7:
    // 0x80189D94: lh          $t4, 0x4E($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4E);
    // 0x80189D98: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189D9C: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x80189DA0: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80189DA4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80189DA8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189DAC: sh          $t3, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r11;
    // 0x80189DB0: sh          $t5, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r13;
    // 0x80189DB4: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80189DB8: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x80189DBC: ori         $a0, $a0, 0x4074
    ctx->r4 = ctx->r4 | 0X4074;
    // 0x80189DC0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80189DC4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189DC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80189DCC: jal         0x80019218
    // 0x80189DD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x80189DD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_8:
    // 0x80189DD4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80189DD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80189DDC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80189DE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80189DE4: swc1        $f0, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f0.u32l;
    // 0x80189DE8: swc1        $f0, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f0.u32l;
    // 0x80189DEC: swc1        $f6, 0x134($s1)
    MEM_W(0X134, ctx->r17) = ctx->f6.u32l;
    // 0x80189DF0: b           L_8018B07C
    // 0x80189DF4: swc1        $f8, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f8.u32l;
        goto L_8018B07C;
    // 0x80189DF4: swc1        $f8, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f8.u32l;
L_80189DF8:
    // 0x80189DF8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80189DFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80189E00: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80189E04: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80189E08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189E0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189E10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189E14: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80189E18: swc1        $f10, 0x134($s1)
    MEM_W(0X134, ctx->r17) = ctx->f10.u32l;
    // 0x80189E1C: swc1        $f4, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f4.u32l;
    // 0x80189E20: swc1        $f6, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f6.u32l;
    // 0x80189E24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189E28: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189E2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80189E30: swc1        $f0, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f0.u32l;
    // 0x80189E34: swc1        $f8, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f8.u32l;
    // 0x80189E38: swc1        $f10, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f10.u32l;
    // 0x80189E3C: swc1        $f4, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f4.u32l;
    // 0x80189E40: swc1        $f6, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f6.u32l;
    // 0x80189E44: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80189E48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189E4C: lwc1        $f10, 0x6C74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C74);
    // 0x80189E50: lwc1        $f8, 0x7C($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X7C);
    // 0x80189E54: lh          $t9, 0x50($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X50);
    // 0x80189E58: lui         $at, 0xC1D0
    ctx->r1 = S32(0XC1D0 << 16);
    // 0x80189E5C: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80189E60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189E64: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80189E68: sh          $t8, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r24;
    // 0x80189E6C: swc1        $f4, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f4.u32l;
    // 0x80189E70: bne         $t9, $zero, L_8018B07C
    if (ctx->r25 != 0) {
        // 0x80189E74: swc1        $f6, 0x124($s1)
        MEM_W(0X124, ctx->r17) = ctx->f6.u32l;
            goto L_8018B07C;
    }
    // 0x80189E74: swc1        $f6, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f6.u32l;
    // 0x80189E78: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80189E7C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x80189E80: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80189E84: sw          $t0, 0x1C8($t1)
    MEM_W(0X1C8, ctx->r9) = ctx->r8;
    // 0x80189E88: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80189E8C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80189E90: sw          $zero, 0x1D0($t2)
    MEM_W(0X1D0, ctx->r10) = 0;
    // 0x80189E94: sh          $t3, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r11;
    // 0x80189E98: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80189E9C: b           L_8018B07C
    // 0x80189EA0: sw          $t4, 0x240($t5)
    MEM_W(0X240, ctx->r13) = ctx->r12;
        goto L_8018B07C;
    // 0x80189EA0: sw          $t4, 0x240($t5)
    MEM_W(0X240, ctx->r13) = ctx->r12;
L_80189EA4:
    // 0x80189EA4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80189EA8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80189EAC: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x80189EB0: beql        $t7, $at, L_8018B080
    if (ctx->r15 == ctx->r1) {
        // 0x80189EB4: lwc1        $f6, 0xE4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
            goto L_8018B080;
    }
    goto skip_5;
    // 0x80189EB4: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    skip_5:
    // 0x80189EB8: lh          $t8, 0x50($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X50);
    // 0x80189EBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189EC0: bnel        $t8, $zero, L_8018B080
    if (ctx->r24 != 0) {
        // 0x80189EC4: lwc1        $f6, 0xE4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
            goto L_8018B080;
    }
    goto skip_6;
    // 0x80189EC4: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    skip_6:
    // 0x80189EC8: lwc1        $f8, 0x6C78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C78);
    // 0x80189ECC: jal         0x80004EB0
    // 0x80189ED0: swc1        $f8, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80189ED0: swc1        $f8, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f8.u32l;
    after_9:
    // 0x80189ED4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80189ED8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80189EDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189EE0: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80189EE4: nop

    // 0x80189EE8: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80189EEC: nop

    // 0x80189EF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80189EF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189EF8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80189EFC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80189F00: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80189F04: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x80189F08: jal         0x80004EB0
    // 0x80189F0C: sh          $t2, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r10;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x80189F0C: sh          $t2, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r10;
    after_10:
    // 0x80189F10: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189F14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189F18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189F1C: lwc1        $f6, 0x6C7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C7C);
    // 0x80189F20: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80189F24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80189F28: jal         0x80004EB0
    // 0x80189F2C: swc1        $f8, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x80189F2C: swc1        $f8, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f8.u32l;
    after_11:
    // 0x80189F30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189F34: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189F38: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80189F3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189F40: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80189F44: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80189F48: jal         0x80004EB0
    // 0x80189F4C: swc1        $f8, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x80189F4C: swc1        $f8, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f8.u32l;
    after_12:
    // 0x80189F50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189F54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189F58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189F5C: lwc1        $f6, 0x6C80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C80);
    // 0x80189F60: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80189F64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80189F68: jal         0x80004EB0
    // 0x80189F6C: swc1        $f8, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x80189F6C: swc1        $f8, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f8.u32l;
    after_13:
    // 0x80189F70: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189F74: lwc1        $f10, 0x6C84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C84);
    // 0x80189F78: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80189F7C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80189F80: nop

    // 0x80189F84: bc1fl       L_8018B080
    if (!c1cs) {
        // 0x80189F88: lwc1        $f6, 0xE4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
            goto L_8018B080;
    }
    goto skip_7;
    // 0x80189F88: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    skip_7:
    // 0x80189F8C: jal         0x80004EB0
    // 0x80189F90: sh          $t3, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r11;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x80189F90: sh          $t3, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r11;
    after_14:
    // 0x80189F94: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80189F98: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80189F9C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189FA0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80189FA4: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80189FA8: nop

    // 0x80189FAC: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80189FB0: nop

    // 0x80189FB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80189FB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189FBC: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80189FC0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189FC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189FC8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80189FCC: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x80189FD0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80189FD4: b           L_8018B07C
    // 0x80189FD8: sh          $t7, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r15;
        goto L_8018B07C;
    // 0x80189FD8: sh          $t7, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r15;
L_80189FDC:
    // 0x80189FDC: lh          $t8, 0x50($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X50);
    // 0x80189FE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80189FE4: bnel        $t8, $zero, L_8018B080
    if (ctx->r24 != 0) {
        // 0x80189FE8: lwc1        $f6, 0xE4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
            goto L_8018B080;
    }
    goto skip_8;
    // 0x80189FE8: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    skip_8:
    // 0x80189FEC: jal         0x80004EB0
    // 0x80189FF0: sh          $t9, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r25;
    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x80189FF0: sh          $t9, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r25;
    after_15:
    // 0x80189FF4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80189FF8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80189FFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A000: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8018A004: nop

    // 0x8018A008: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8018A00C: nop

    // 0x8018A010: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018A014: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A018: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8018A01C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018A020: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A024: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018A028: swc1        $f6, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f6.u32l;
    // 0x8018A02C: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x8018A030: b           L_8018B07C
    // 0x8018A034: sh          $t3, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r11;
        goto L_8018B07C;
    // 0x8018A034: sh          $t3, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r11;
L_8018A038:
    // 0x8018A038: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8018A03C: addiu       $v0, $v0, -0x40CC
    ctx->r2 = ADD32(ctx->r2, -0X40CC);
    // 0x8018A040: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x8018A044: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x8018A048: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018A04C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8018A050: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018A054: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8018A058: lw          $t7, 0x1FD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1FD0);
    // 0x8018A05C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8018A060: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8018A064: lh          $t1, 0x50($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X50);
    // 0x8018A068: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018A06C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8018A070: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x8018A074: slti        $at, $t1, 0x78
    ctx->r1 = SIGNED(ctx->r9) < 0X78 ? 1 : 0;
    // 0x8018A078: beq         $at, $zero, L_8018A144
    if (ctx->r1 == 0) {
        // 0x8018A07C: sw          $t0, 0x28($s1)
        MEM_W(0X28, ctx->r17) = ctx->r8;
            goto L_8018A144;
    }
    // 0x8018A07C: sw          $t0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r8;
    // 0x8018A080: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018A084: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018A088: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8018A08C: addiu       $v1, $v1, -0x7CB0
    ctx->r3 = ADD32(ctx->r3, -0X7CB0);
    // 0x8018A090: addiu       $v0, $v0, -0x7CAC
    ctx->r2 = ADD32(ctx->r2, -0X7CAC);
    // 0x8018A094: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8018A098: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8018A09C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A0A0: sw          $t2, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r10;
    // 0x8018A0A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A0A8: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x8018A0AC: sw          $t5, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r13;
    // 0x8018A0B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A0B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018A0B8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018A0BC: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8018A0C0: sw          $t6, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r14;
    // 0x8018A0C4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8018A0C8: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x8018A0CC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8018A0D0: sw          $t8, 0x224($t9)
    MEM_W(0X224, ctx->r25) = ctx->r24;
    // 0x8018A0D4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8018A0D8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8018A0DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018A0E0: sw          $t0, 0x220($t1)
    MEM_W(0X220, ctx->r9) = ctx->r8;
    // 0x8018A0E4: lw          $t2, 0x7AF8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7AF8);
    // 0x8018A0E8: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018A0EC: addiu       $t4, $t4, 0x79A8
    ctx->r12 = ADD32(ctx->r12, 0X79A8);
    // 0x8018A0F0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8018A0F4: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8018A0F8: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8018A0FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018A100: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018A104: jal         0x8009BC2C
    // 0x8018A108: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x8018A108: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_16:
    // 0x8018A10C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018A110: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x8018A114: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x8018A118: bnel        $t6, $zero, L_8018A148
    if (ctx->r14 != 0) {
        // 0x8018A11C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8018A148;
    }
    goto skip_9;
    // 0x8018A11C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_9:
    // 0x8018A120: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8018A124: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018A128: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8018A12C: lw          $t7, 0x1C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C8);
    // 0x8018A130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018A134: bnel        $t7, $at, L_8018A148
    if (ctx->r15 != ctx->r1) {
        // 0x8018A138: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8018A148;
    }
    goto skip_10;
    // 0x8018A138: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_10:
    // 0x8018A13C: jal         0x800A6CD0
    // 0x8018A140: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    Player_ApplyDamage(rdram, ctx);
        goto after_17;
    // 0x8018A140: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_17:
L_8018A144:
    // 0x8018A144: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_8018A148:
    // 0x8018A148: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018A14C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A150: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A154: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018A158: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018A15C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018A160: addiu       $a0, $a0, 0xD0
    ctx->r4 = ADD32(ctx->r4, 0XD0);
    // 0x8018A164: jal         0x8009BC2C
    // 0x8018A168: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8018A168: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x8018A16C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A170: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018A174: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8018A178: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8018A17C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A180: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x8018A184: addiu       $a0, $a0, 0x74
    ctx->r4 = ADD32(ctx->r4, 0X74);
    // 0x8018A188: jal         0x8009BC2C
    // 0x8018A18C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x8018A18C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x8018A190: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018A194: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A198: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018A19C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A1A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018A1A4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018A1A8: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8018A1AC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A1B0: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x8018A1B4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018A1B8: addiu       $a0, $a0, 0x78
    ctx->r4 = ADD32(ctx->r4, 0X78);
    // 0x8018A1BC: jal         0x8009BC2C
    // 0x8018A1C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x8018A1C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_20:
    // 0x8018A1C4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A1C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018A1CC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8018A1D0: lui         $a2, 0x3F4C
    ctx->r6 = S32(0X3F4C << 16);
    // 0x8018A1D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A1D8: lui         $a3, 0x4248
    ctx->r7 = S32(0X4248 << 16);
    // 0x8018A1DC: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    // 0x8018A1E0: jal         0x8009BC2C
    // 0x8018A1E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x8018A1E4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x8018A1E8: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8018A1EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A1F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A1F4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018A1F8: swc1        $f8, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->f8.u32l;
    // 0x8018A1FC: lwc1        $f10, 0x6C88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C88);
    // 0x8018A200: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A204: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A208: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x8018A20C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A210: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018A214: swc1        $f10, 0x108($s1)
    MEM_W(0X108, ctx->r17) = ctx->f10.u32l;
    // 0x8018A218: swc1        $f4, 0x10C($s1)
    MEM_W(0X10C, ctx->r17) = ctx->f4.u32l;
    // 0x8018A21C: swc1        $f6, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f6.u32l;
    // 0x8018A220: swc1        $f8, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f8.u32l;
    // 0x8018A224: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8018A228: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A22C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8018A230: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x8018A234: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018A238: lui         $a3, 0x3B83
    ctx->r7 = S32(0X3B83 << 16);
    // 0x8018A23C: sw          $t8, 0x238($t9)
    MEM_W(0X238, ctx->r25) = ctx->r24;
    // 0x8018A240: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8018A244: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A248: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8018A24C: addiu       $a0, $a0, -0x5DD0
    ctx->r4 = ADD32(ctx->r4, -0X5DD0);
    // 0x8018A250: jal         0x8009BC2C
    // 0x8018A254: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x8018A254: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x8018A258: lh          $v0, 0x50($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X50);
    // 0x8018A25C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x8018A260: lui         $a0, 0x1940
    ctx->r4 = S32(0X1940 << 16);
    // 0x8018A264: bne         $v0, $at, L_8018A294
    if (ctx->r2 != ctx->r1) {
        // 0x8018A268: ori         $a0, $a0, 0x306E
        ctx->r4 = ctx->r4 | 0X306E;
            goto L_8018A294;
    }
    // 0x8018A268: ori         $a0, $a0, 0x306E
    ctx->r4 = ctx->r4 | 0X306E;
    // 0x8018A26C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8018A270: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018A274: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018A278: addiu       $a3, $t0, 0x5D34
    ctx->r7 = ADD32(ctx->r8, 0X5D34);
    // 0x8018A27C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018A280: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018A284: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x8018A288: jal         0x80019218
    // 0x8018A28C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_23;
    // 0x8018A28C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_23:
    // 0x8018A290: lh          $v0, 0x50($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X50);
L_8018A294:
    // 0x8018A294: bne         $v0, $zero, L_8018B07C
    if (ctx->r2 != 0) {
        // 0x8018A298: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_8018B07C;
    }
    // 0x8018A298: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A29C: lwc1        $f4, 0x1A54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x8018A2A0: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8018A2A4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A2A8: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x8018A2AC: swc1        $f4, 0xD0($t2)
    MEM_W(0XD0, ctx->r10) = ctx->f4.u32l;
    // 0x8018A2B0: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8018A2B4: addiu       $s0, $s1, 0x3FC
    ctx->r16 = ADD32(ctx->r17, 0X3FC);
    // 0x8018A2B8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018A2BC: sw          $zero, 0x238($t3)
    MEM_W(0X238, ctx->r11) = 0;
    // 0x8018A2C0: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8018A2C4: lh          $t5, 0x90($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X90);
    // 0x8018A2C8: sh          $t4, 0x5A($s1)
    MEM_H(0X5A, ctx->r17) = ctx->r12;
    // 0x8018A2CC: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8018A2D0: beql        $t5, $zero, L_8018A320
    if (ctx->r13 == 0) {
        // 0x8018A2D4: sh          $t1, 0x4E($s1)
        MEM_H(0X4E, ctx->r17) = ctx->r9;
            goto L_8018A320;
    }
    goto skip_11;
    // 0x8018A2D4: sh          $t1, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r9;
    skip_11:
    // 0x8018A2D8: jal         0x80004EB0
    // 0x8018A2DC: sh          $t6, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r14;
    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x8018A2DC: sh          $t6, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r14;
    after_24:
    // 0x8018A2E0: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8018A2E4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018A2E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018A2EC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8018A2F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A2F4: swc1        $f2, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f2.u32l;
    // 0x8018A2F8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8018A2FC: nop

    // 0x8018A300: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018A304: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8018A308: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018A30C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018A310: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8018A314: b           L_8018A320
    // 0x8018A318: sh          $t0, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r8;
        goto L_8018A320;
    // 0x8018A318: sh          $t0, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r8;
    // 0x8018A31C: sh          $t1, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r9;
L_8018A320:
    // 0x8018A320: lui         $a1, 0x3140
    ctx->r5 = S32(0X3140 << 16);
    // 0x8018A324: ori         $a1, $a1, 0x8097
    ctx->r5 = ctx->r5 | 0X8097;
    // 0x8018A328: jal         0x8001A55C
    // 0x8018A32C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_25;
    // 0x8018A32C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8018A330: b           L_8018B080
    // 0x8018A334: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
        goto L_8018B080;
    // 0x8018A334: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
L_8018A338:
    // 0x8018A338: lui         $at, 0x4228
    ctx->r1 = S32(0X4228 << 16);
    // 0x8018A33C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A340: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A344: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x8018A348: lwc1        $f6, 0x6C8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C8C);
    // 0x8018A34C: swc1        $f6, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f6.u32l;
    // 0x8018A350: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8018A354: lwc1        $f8, 0x74($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X74);
    // 0x8018A358: swc1        $f8, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f8.u32l;
    // 0x8018A35C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8018A360: lwc1        $f10, 0x78($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X78);
    // 0x8018A364: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
    // 0x8018A368: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8018A36C: lwc1        $f4, 0x138($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X138);
    // 0x8018A370: b           L_8018B07C
    // 0x8018A374: swc1        $f4, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f4.u32l;
        goto L_8018B07C;
    // 0x8018A374: swc1        $f4, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f4.u32l;
L_8018A378:
    // 0x8018A378: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8018A37C: addiu       $v0, $v0, -0x40CC
    ctx->r2 = ADD32(ctx->r2, -0X40CC);
    // 0x8018A380: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8018A384: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x8018A388: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018A38C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8018A390: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018A394: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8018A398: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x8018A39C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8018A3A0: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8018A3A4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018A3A8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018A3AC: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8018A3B0: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x8018A3B4: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
    // 0x8018A3B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A3BC: swc1        $f6, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f6.u32l;
    // 0x8018A3C0: lwc1        $f8, 0x6C90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C90);
    // 0x8018A3C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A3C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A3CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018A3D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A3D4: swc1        $f8, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f8.u32l;
    // 0x8018A3D8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8018A3DC: swc1        $f10, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f10.u32l;
    // 0x8018A3E0: bc1fl       L_8018B080
    if (!c1cs) {
        // 0x8018A3E4: lwc1        $f6, 0xE4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
            goto L_8018B080;
    }
    goto skip_12;
    // 0x8018A3E4: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    skip_12:
    // 0x8018A3E8: lh          $t2, 0x50($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X50);
    // 0x8018A3EC: bnel        $t2, $zero, L_8018B080
    if (ctx->r10 != 0) {
        // 0x8018A3F0: lwc1        $f6, 0xE4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
            goto L_8018B080;
    }
    goto skip_13;
    // 0x8018A3F0: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    skip_13:
    // 0x8018A3F4: lwc1        $f8, 0xE4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8018A3F8: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018A3FC: lwc1        $f4, 0xEC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8018A400: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018A404: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018A408: addiu       $s0, $s1, 0x3FC
    ctx->r16 = ADD32(ctx->r17, 0X3FC);
    // 0x8018A40C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018A410: swc1        $f12, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f12.u32l;
    // 0x8018A414: jal         0x80005100
    // 0x8018A418: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_26;
    // 0x8018A418: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    after_26:
    // 0x8018A41C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A420: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018A424: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A428: jal         0x80005E90
    // 0x8018A42C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_27;
    // 0x8018A42C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x8018A430: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x8018A434: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018A438: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A43C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A440: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A444: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A448: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018A44C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8018A450: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x8018A454: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    // 0x8018A458: jal         0x80006A20
    // 0x8018A45C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_28;
    // 0x8018A45C: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    after_28:
    // 0x8018A460: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8018A464: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018A468: lwc1        $f4, 0xEC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8018A46C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018A470: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8018A474: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018A478: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018A47C: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x8018A480: lwc1        $f14, 0x88($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8018A484: jal         0x80005100
    // 0x8018A488: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    Math_Atan2F(rdram, ctx);
        goto after_29;
    // 0x8018A488: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    after_29:
    // 0x8018A48C: jal         0x8009F768
    // 0x8018A490: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_30;
    // 0x8018A490: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_30:
    // 0x8018A494: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x8018A498: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8018A49C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8018A4A0: swc1        $f0, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f0.u32l;
    // 0x8018A4A4: sh          $t3, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r11;
    // 0x8018A4A8: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8018A4AC: addiu       $a3, $t4, 0x5D34
    ctx->r7 = ADD32(ctx->r12, 0X5D34);
    // 0x8018A4B0: lui         $a0, 0x1940
    ctx->r4 = S32(0X1940 << 16);
    // 0x8018A4B4: ori         $a0, $a0, 0x306E
    ctx->r4 = ctx->r4 | 0X306E;
    // 0x8018A4B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018A4BC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8018A4C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018A4C4: jal         0x80019218
    // 0x8018A4C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_31;
    // 0x8018A4C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_31:
    // 0x8018A4CC: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x8018A4D0: b           L_8018B07C
    // 0x8018A4D4: sh          $t6, 0x54($s1)
    MEM_H(0X54, ctx->r17) = ctx->r14;
        goto L_8018B07C;
    // 0x8018A4D4: sh          $t6, 0x54($s1)
    MEM_H(0X54, ctx->r17) = ctx->r14;
L_8018A4D8:
    // 0x8018A4D8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8018A4DC: addiu       $v0, $v0, -0x40CC
    ctx->r2 = ADD32(ctx->r2, -0X40CC);
    // 0x8018A4E0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x8018A4E4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018A4E8: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x8018A4EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018A4F0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018A4F4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8018A4F8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8018A4FC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8018A500: lw          $t0, 0x1FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FD0);
    // 0x8018A504: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8018A508: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x8018A50C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018A510: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8018A514: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8018A518: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8018A51C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A520: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A524: sw          $t3, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r11;
    // 0x8018A528: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8018A52C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8018A530: swc1        $f0, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f0.u32l;
    // 0x8018A534: swc1        $f10, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f10.u32l;
    // 0x8018A538: bc1fl       L_8018B080
    if (!c1cs) {
        // 0x8018A53C: lwc1        $f6, 0xE4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
            goto L_8018B080;
    }
    goto skip_14;
    // 0x8018A53C: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    skip_14:
    // 0x8018A540: b           L_8018B07C
    // 0x8018A544: sh          $t4, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r12;
        goto L_8018B07C;
    // 0x8018A544: sh          $t4, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r12;
L_8018A548:
    // 0x8018A548: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018A54C: lw          $t5, 0x7A80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7A80);
    // 0x8018A550: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018A554: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A558: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8018A55C: sw          $t6, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = ctx->r14;
    // 0x8018A560: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A564: swc1        $f0, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f0.u32l;
    // 0x8018A568: swc1        $f0, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f0.u32l;
    // 0x8018A56C: lwc1        $f8, 0x6C94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C94);
    // 0x8018A570: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8018A574: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A578: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018A57C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018A580: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A584: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018A588: swc1        $f10, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f10.u32l;
    // 0x8018A58C: lwc1        $f6, 0x6C98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C98);
    // 0x8018A590: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018A594: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018A598: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018A59C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A5A0: nop

    // 0x8018A5A4: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018A5A8: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    // 0x8018A5AC: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018A5B0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8018A5B4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A5B8: lwc1        $f8, 0x58($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X58);
    // 0x8018A5BC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8018A5C0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018A5C4: jal         0x80005E90
    // 0x8018A5C8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_32;
    // 0x8018A5C8: nop

    after_32:
    // 0x8018A5CC: jal         0x80004EB0
    // 0x8018A5D0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_33;
    // 0x8018A5D0: nop

    after_33:
    // 0x8018A5D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018A5D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A5DC: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8018A5E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A5E4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018A5E8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018A5EC: jal         0x80004EB0
    // 0x8018A5F0: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_34;
    // 0x8018A5F0: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    after_34:
    // 0x8018A5F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018A5F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A5FC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018A600: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A604: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018A608: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018A60C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A610: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A614: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018A618: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A61C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018A620: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8018A624: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8018A628: jal         0x80006970
    // 0x8018A62C: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_35;
    // 0x8018A62C: swc1        $f10, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f10.u32l;
    after_35:
    // 0x8018A630: jal         0x80004EB0
    // 0x8018A634: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_36;
    // 0x8018A634: nop

    after_36:
    // 0x8018A638: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018A63C: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018A640: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018A644: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018A648: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018A64C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018A650: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018A654: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018A658: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018A65C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A660: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8018A664: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018A668: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018A66C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A670: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018A674: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8018A678: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8018A67C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8018A680: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018A684: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8018A688: jal         0x8007797C
    // 0x8018A68C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_FireSmoke1_SpawnMoving(rdram, ctx);
        goto after_37;
    // 0x8018A68C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_37:
    // 0x8018A690: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018A694: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8018A698: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8018A69C: bnel        $t9, $zero, L_8018A734
    if (ctx->r25 != 0) {
        // 0x8018A6A0: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_8018A734;
    }
    goto skip_15;
    // 0x8018A6A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_15:
    // 0x8018A6A4: jal         0x80004EB0
    // 0x8018A6A8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_38;
    // 0x8018A6A8: nop

    after_38:
    // 0x8018A6AC: jal         0x80004EB0
    // 0x8018A6B0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_39;
    // 0x8018A6B0: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x8018A6B4: jal         0x80004EB0
    // 0x8018A6B8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_40;
    // 0x8018A6B8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_40:
    // 0x8018A6BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018A6C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018A6C4: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018A6C8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018A6CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018A6D0: sub.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8018A6D4: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018A6D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A6DC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018A6E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018A6E4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018A6E8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018A6EC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8018A6F0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8018A6F4: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8018A6F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018A6FC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018A700: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018A704: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018A708: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8018A70C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8018A710: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018A714: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018A718: lwc1        $f6, 0x6C9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6C9C);
    // 0x8018A71C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018A720: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018A724: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018A728: jal         0x8007C484
    // 0x8018A72C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_41;
    // 0x8018A72C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_41:
    // 0x8018A730: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_8018A734:
    // 0x8018A734: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8018A738: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A73C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018A740: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018A744: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018A748: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8018A74C: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8018A750: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8018A754: jal         0x80006970
    // 0x8018A758: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_42;
    // 0x8018A758: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    after_42:
    // 0x8018A75C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018A760: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018A764: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018A768: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8018A76C: addiu       $s0, $s0, 0x7A48
    ctx->r16 = ADD32(ctx->r16, 0X7A48);
    // 0x8018A770: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018A774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018A778: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8018A77C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018A780: jal         0x8009BC2C
    // 0x8018A784: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_43;
    // 0x8018A784: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_43:
    // 0x8018A788: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A78C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018A790: addiu       $a0, $a0, 0x7A4C
    ctx->r4 = ADD32(ctx->r4, 0X7A4C);
    // 0x8018A794: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8018A798: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018A79C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018A7A0: jal         0x8009BC2C
    // 0x8018A7A4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_44;
    // 0x8018A7A4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_44:
    // 0x8018A7A8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018A7AC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018A7B0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A7B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A7B8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018A7BC: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018A7C0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018A7C4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8018A7C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018A7CC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8018A7D0: jal         0x8009BC2C
    // 0x8018A7D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_45;
    // 0x8018A7D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_45:
    // 0x8018A7D8: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018A7DC: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018A7E0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A7E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A7E8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018A7EC: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018A7F0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018A7F4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8018A7F8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018A7FC: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    // 0x8018A800: jal         0x8009BC2C
    // 0x8018A804: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_46;
    // 0x8018A804: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_46:
    // 0x8018A808: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018A80C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018A810: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A814: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A818: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018A81C: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8018A820: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8018A824: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x8018A828: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018A82C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x8018A830: jal         0x8009BC2C
    // 0x8018A834: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_47;
    // 0x8018A834: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_47:
    // 0x8018A838: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A83C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018A840: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8018A844: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018A848: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A84C: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8018A850: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    // 0x8018A854: jal         0x8009BC2C
    // 0x8018A858: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_48;
    // 0x8018A858: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_48:
    // 0x8018A85C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A860: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018A864: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8018A868: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018A86C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A870: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8018A874: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8018A878: jal         0x8009BC2C
    // 0x8018A87C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_49;
    // 0x8018A87C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_49:
    // 0x8018A880: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A884: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018A888: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8018A88C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018A890: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018A894: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8018A898: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    // 0x8018A89C: jal         0x8009BC2C
    // 0x8018A8A0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_50;
    // 0x8018A8A0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_50:
    // 0x8018A8A4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018A8A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018A8AC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8018A8B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018A8B4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8018A8B8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8018A8BC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018A8C0: addiu       $a0, $a0, 0x34
    ctx->r4 = ADD32(ctx->r4, 0X34);
    // 0x8018A8C4: jal         0x8009BC2C
    // 0x8018A8C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_51;
    // 0x8018A8C8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_51:
    // 0x8018A8CC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A8D0: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018A8D4: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8018A8D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A8DC: bne         $v1, $at, L_8018A8F4
    if (ctx->r3 != ctx->r1) {
        // 0x8018A8E0: addiu       $a0, $a0, 0x2D14
        ctx->r4 = ADD32(ctx->r4, 0X2D14);
            goto L_8018A8F4;
    }
    // 0x8018A8E0: addiu       $a0, $a0, 0x2D14
    ctx->r4 = ADD32(ctx->r4, 0X2D14);
    // 0x8018A8E4: jal         0x800BA808
    // 0x8018A8E8: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    Radio_PlayMessage(rdram, ctx);
        goto after_52;
    // 0x8018A8E8: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_52:
    // 0x8018A8EC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018A8F0: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018A8F4:
    // 0x8018A8F4: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8018A8F8: bne         $v1, $at, L_8018B07C
    if (ctx->r3 != ctx->r1) {
        // 0x8018A8FC: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8018B07C;
    }
    // 0x8018A8FC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A900: sw          $zero, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = 0;
    // 0x8018A904: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A908: lwc1        $f4, 0x1A54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x8018A90C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8018A910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018A914: jal         0x8001CA24
    // 0x8018A918: swc1        $f4, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f4.u32l;
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_53;
    // 0x8018A918: swc1        $f4, 0xD0($t0)
    MEM_W(0XD0, ctx->r8) = ctx->f4.u32l;
    after_53:
    // 0x8018A91C: addiu       $t1, $zero, 0x15
    ctx->r9 = ADD32(0, 0X15);
    // 0x8018A920: sh          $t1, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r9;
    // 0x8018A924: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018A928: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018A92C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8018A930: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8018A934: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018A938: jal         0x8007B344
    // 0x8018A93C: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_54;
    // 0x8018A93C: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    after_54:
    // 0x8018A940: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018A944: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018A948: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8018A94C: jal         0x8007A568
    // 0x8018A950: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    Effect_Effect383_Spawn(rdram, ctx);
        goto after_55;
    // 0x8018A950: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_55:
    // 0x8018A954: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018A958: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8018A95C: addiu       $s0, $zero, 0x11E
    ctx->r16 = ADD32(0, 0X11E);
    // 0x8018A960: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
L_8018A964:
    // 0x8018A964: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018A968: bne         $t3, $at, L_8018A98C
    if (ctx->r11 != ctx->r1) {
        // 0x8018A96C: nop
    
            goto L_8018A98C;
    }
    // 0x8018A96C: nop

    // 0x8018A970: lhu         $t4, 0x2($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X2);
    // 0x8018A974: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    // 0x8018A978: bne         $s0, $t4, L_8018A98C
    if (ctx->r16 != ctx->r12) {
        // 0x8018A97C: nop
    
            goto L_8018A98C;
    }
    // 0x8018A97C: nop

    // 0x8018A980: jal         0x80060FBC
    // 0x8018A984: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_56;
    // 0x8018A984: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_56:
    // 0x8018A988: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_8018A98C:
    // 0x8018A98C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018A990: addiu       $t5, $t5, -0xEF0
    ctx->r13 = ADD32(ctx->r13, -0XEF0);
    // 0x8018A994: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    // 0x8018A998: bnel        $a0, $t5, L_8018A964
    if (ctx->r4 != ctx->r13) {
        // 0x8018A99C: lbu         $t3, 0x0($a0)
        ctx->r11 = MEM_BU(ctx->r4, 0X0);
            goto L_8018A964;
    }
    goto skip_16;
    // 0x8018A99C: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    skip_16:
    // 0x8018A9A0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8018A9A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A9A8: sb          $t6, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = ctx->r14;
    // 0x8018A9AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A9B0: b           L_8018B07C
    // 0x8018A9B4: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
        goto L_8018B07C;
    // 0x8018A9B4: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
L_8018A9B8:
    // 0x8018A9B8: jal         0x801876FC
    // 0x8018A9BC: nop

    Andross_Backdrop_RotEffect(rdram, ctx);
        goto after_57;
    // 0x8018A9BC: nop

    after_57:
    // 0x8018A9C0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018A9C4: lw          $t7, 0x7A80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7A80);
    // 0x8018A9C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A9CC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8018A9D0: addiu       $v1, $t7, 0x1
    ctx->r3 = ADD32(ctx->r15, 0X1);
    // 0x8018A9D4: sw          $v1, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = ctx->r3;
    // 0x8018A9D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A9DC: sw          $t9, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r25;
    // 0x8018A9E0: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
    // 0x8018A9E4: beq         $at, $zero, L_8018AA90
    if (ctx->r1 == 0) {
        // 0x8018A9E8: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8018AA90;
    }
    // 0x8018A9E8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018A9EC: addiu       $v0, $v0, -0x7C80
    ctx->r2 = ADD32(ctx->r2, -0X7C80);
    // 0x8018A9F0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8018A9F4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018A9F8: addiu       $v1, $v1, -0x7C50
    ctx->r3 = ADD32(ctx->r3, -0X7C50);
    // 0x8018A9FC: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8018AA00: sltiu       $at, $t1, 0xFF
    ctx->r1 = ctx->r9 < 0XFF ? 1 : 0;
    // 0x8018AA04: bne         $at, $zero, L_8018AA14
    if (ctx->r1 != 0) {
        // 0x8018AA08: sw          $t1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r9;
            goto L_8018AA14;
    }
    // 0x8018AA08: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018AA0C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8018AA10: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8018AA14:
    // 0x8018AA14: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8018AA18: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018AA1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AA20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018AA24: sw          $t4, -0x7C60($at)
    MEM_W(-0X7C60, ctx->r1) = ctx->r12;
    // 0x8018AA28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AA2C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8018AA30: lui         $a1, 0x3E19
    ctx->r5 = S32(0X3E19 << 16);
    // 0x8018AA34: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018AA38: lui         $a3, 0x3B83
    ctx->r7 = S32(0X3B83 << 16);
    // 0x8018AA3C: sw          $t4, -0x7C70($at)
    MEM_W(-0X7C70, ctx->r1) = ctx->r12;
    // 0x8018AA40: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8018AA44: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018AA48: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8018AA4C: addiu       $a0, $a0, -0x5DD0
    ctx->r4 = ADD32(ctx->r4, -0X5DD0);
    // 0x8018AA50: jal         0x8009BC2C
    // 0x8018AA54: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_58;
    // 0x8018AA54: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_58:
    // 0x8018AA58: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018AA5C: lw          $t5, 0x7AF8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7AF8);
    // 0x8018AA60: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018AA64: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018AA68: addiu       $t7, $t7, 0x79A8
    ctx->r15 = ADD32(ctx->r15, 0X79A8);
    // 0x8018AA6C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8018AA70: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8018AA74: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x8018AA78: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018AA7C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8018AA80: jal         0x8009BC2C
    // 0x8018AA84: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_59;
    // 0x8018AA84: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_59:
    // 0x8018AA88: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AA8C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AA90:
    // 0x8018AA90: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8018AA94: beq         $v1, $at, L_8018AAF4
    if (ctx->r3 == ctx->r1) {
        // 0x8018AA98: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018AAF4;
    }
    // 0x8018AA98: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018AA9C: addiu       $at, $zero, 0x15E
    ctx->r1 = ADD32(0, 0X15E);
    // 0x8018AAA0: beq         $v1, $at, L_8018AB20
    if (ctx->r3 == ctx->r1) {
        // 0x8018AAA4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018AB20;
    }
    // 0x8018AAA4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018AAA8: addiu       $at, $zero, 0x1F4
    ctx->r1 = ADD32(0, 0X1F4);
    // 0x8018AAAC: beq         $v1, $at, L_8018AB38
    if (ctx->r3 == ctx->r1) {
        // 0x8018AAB0: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018AB38;
    }
    // 0x8018AAB0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018AAB4: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    // 0x8018AAB8: beq         $v1, $at, L_8018AB5C
    if (ctx->r3 == ctx->r1) {
        // 0x8018AABC: addiu       $t1, $zero, 0x5
        ctx->r9 = ADD32(0, 0X5);
            goto L_8018AB5C;
    }
    // 0x8018AABC: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8018AAC0: addiu       $at, $zero, 0x320
    ctx->r1 = ADD32(0, 0X320);
    // 0x8018AAC4: beq         $v1, $at, L_8018AD44
    if (ctx->r3 == ctx->r1) {
        // 0x8018AAC8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018AD44;
    }
    // 0x8018AAC8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018AACC: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x8018AAD0: beq         $v1, $at, L_8018AD5C
    if (ctx->r3 == ctx->r1) {
        // 0x8018AAD4: addiu       $at, $zero, 0x514
        ctx->r1 = ADD32(0, 0X514);
            goto L_8018AD5C;
    }
    // 0x8018AAD4: addiu       $at, $zero, 0x514
    ctx->r1 = ADD32(0, 0X514);
    // 0x8018AAD8: beq         $v1, $at, L_8018AD70
    if (ctx->r3 == ctx->r1) {
        // 0x8018AADC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018AD70;
    }
    // 0x8018AADC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018AAE0: addiu       $at, $zero, 0x708
    ctx->r1 = ADD32(0, 0X708);
    // 0x8018AAE4: beq         $v1, $at, L_8018AD88
    if (ctx->r3 == ctx->r1) {
        // 0x8018AAE8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018AD88;
    }
    // 0x8018AAE8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018AAEC: b           L_8018ADA0
    // 0x8018AAF0: slti        $at, $v1, 0x259
    ctx->r1 = SIGNED(ctx->r3) < 0X259 ? 1 : 0;
        goto L_8018ADA0;
    // 0x8018AAF0: slti        $at, $v1, 0x259
    ctx->r1 = SIGNED(ctx->r3) < 0X259 ? 1 : 0;
L_8018AAF4:
    // 0x8018AAF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AAF8: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x8018AAFC: addiu       $a0, $a0, 0x481C
    ctx->r4 = ADD32(ctx->r4, 0X481C);
    // 0x8018AB00: jal         0x800BA808
    // 0x8018AB04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_60;
    // 0x8018AB04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_60:
    // 0x8018AB08: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8018AB0C: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8018AB10: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AB14: sw          $t9, 0x220($t8)
    MEM_W(0X220, ctx->r24) = ctx->r25;
    // 0x8018AB18: b           L_8018AD9C
    // 0x8018AB1C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018AD9C;
    // 0x8018AB1C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AB20:
    // 0x8018AB20: addiu       $a0, $a0, 0x3380
    ctx->r4 = ADD32(ctx->r4, 0X3380);
    // 0x8018AB24: jal         0x800BA808
    // 0x8018AB28: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    Radio_PlayMessage(rdram, ctx);
        goto after_61;
    // 0x8018AB28: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_61:
    // 0x8018AB2C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AB30: b           L_8018AD9C
    // 0x8018AB34: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018AD9C;
    // 0x8018AB34: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AB38:
    // 0x8018AB38: addiu       $a0, $a0, 0x2D8C
    ctx->r4 = ADD32(ctx->r4, 0X2D8C);
    // 0x8018AB3C: jal         0x800BA808
    // 0x8018AB40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_62;
    // 0x8018AB40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_62:
    // 0x8018AB44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018AB48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018AB4C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AB50: sw          $t0, -0x6DC($at)
    MEM_W(-0X6DC, ctx->r1) = ctx->r8;
    // 0x8018AB54: b           L_8018AD9C
    // 0x8018AB58: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018AD9C;
    // 0x8018AB58: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AB5C:
    // 0x8018AB5C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AB60: sb          $t1, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = ctx->r9;
    // 0x8018AB64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB68: addiu       $t2, $zero, 0x81
    ctx->r10 = ADD32(0, 0X81);
    // 0x8018AB6C: sw          $t2, -0x7CE0($at)
    MEM_W(-0X7CE0, ctx->r1) = ctx->r10;
    // 0x8018AB70: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB74: addiu       $t3, $zero, 0x1B
    ctx->r11 = ADD32(0, 0X1B);
    // 0x8018AB78: sw          $t3, -0x7CD8($at)
    MEM_W(-0X7CD8, ctx->r1) = ctx->r11;
    // 0x8018AB7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB80: sw          $zero, -0x7CD0($at)
    MEM_W(-0X7CD0, ctx->r1) = 0;
    // 0x8018AB84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB88: addiu       $t4, $zero, 0x3E4
    ctx->r12 = ADD32(0, 0X3E4);
    // 0x8018AB8C: sw          $t4, -0x7C28($at)
    MEM_W(-0X7C28, ctx->r1) = ctx->r12;
    // 0x8018AB90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018AB94: addiu       $t5, $zero, 0x3EF
    ctx->r13 = ADD32(0, 0X3EF);
    // 0x8018AB98: sw          $t5, -0x7C24($at)
    MEM_W(-0X7C24, ctx->r1) = ctx->r13;
    // 0x8018AB9C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018ABA0: addiu       $t6, $zero, 0x4081
    ctx->r14 = ADD32(0, 0X4081);
    // 0x8018ABA4: sh          $t6, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r14;
    // 0x8018ABA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ABAC: lwc1        $f10, 0x6CA0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6CA0);
    // 0x8018ABB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018ABB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018ABB8: swc1        $f10, 0x1A44($at)
    MEM_W(0X1A44, ctx->r1) = ctx->f10.u32l;
    // 0x8018ABBC: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8018ABC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018ABC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ABC8: swc1        $f4, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->f4.u32l;
    // 0x8018ABCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ABD0: lwc1        $f8, 0x6CA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CA4);
    // 0x8018ABD4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8018ABD8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018ABDC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018ABE0: swc1        $f8, 0x74($t7)
    MEM_W(0X74, ctx->r15) = ctx->f8.u32l;
    // 0x8018ABE4: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8018ABE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ABEC: swc1        $f6, 0x78($t9)
    MEM_W(0X78, ctx->r25) = ctx->f6.u32l;
    // 0x8018ABF0: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8018ABF4: lwc1        $f10, 0x6CA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6CA8);
    // 0x8018ABF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ABFC: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x8018AC00: swc1        $f10, 0x7C($t8)
    MEM_W(0X7C, ctx->r24) = ctx->f10.u32l;
    // 0x8018AC04: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC08: swc1        $f0, 0x8C($t0)
    MEM_W(0X8C, ctx->r8) = ctx->f0.u32l;
    // 0x8018AC0C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC10: lwc1        $f4, 0x6CAC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6CAC);
    // 0x8018AC14: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018AC18: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018AC1C: swc1        $f4, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->f4.u32l;
    // 0x8018AC20: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC24: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8018AC28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018AC2C: swc1        $f0, 0xEC($t2)
    MEM_W(0XEC, ctx->r10) = ctx->f0.u32l;
    // 0x8018AC30: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC34: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x8018AC38: addiu       $t2, $zero, 0xF0
    ctx->r10 = ADD32(0, 0XF0);
    // 0x8018AC3C: lwc1        $f2, 0xEC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8018AC40: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x8018AC44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018AC48: swc1        $f2, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f2.u32l;
    // 0x8018AC4C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AC54: swc1        $f2, 0xE8($t3)
    MEM_W(0XE8, ctx->r11) = ctx->f2.u32l;
    // 0x8018AC58: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC5C: swc1        $f2, 0x4D8($t4)
    MEM_W(0X4D8, ctx->r12) = ctx->f2.u32l;
    // 0x8018AC60: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC64: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018AC68: swc1        $f2, 0x110($t5)
    MEM_W(0X110, ctx->r13) = ctx->f2.u32l;
    // 0x8018AC6C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC70: swc1        $f8, 0x12C($t6)
    MEM_W(0X12C, ctx->r14) = ctx->f8.u32l;
    // 0x8018AC74: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC78: swc1        $f6, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f6.u32l;
    // 0x8018AC7C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC80: sw          $t9, 0x1C8($t8)
    MEM_W(0X1C8, ctx->r24) = ctx->r25;
    // 0x8018AC84: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC88: sw          $t0, 0x1D0($t1)
    MEM_W(0X1D0, ctx->r9) = ctx->r8;
    // 0x8018AC8C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC90: sw          $t2, 0x1F8($t3)
    MEM_W(0X1F8, ctx->r11) = ctx->r10;
    // 0x8018AC94: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8018AC98: sw          $t4, 0x234($t5)
    MEM_W(0X234, ctx->r13) = ctx->r12;
    // 0x8018AC9C: jal         0x80188468
    // 0x8018ACA0: swc1        $f10, 0x7A5C($at)
    MEM_W(0X7A5C, ctx->r1) = ctx->f10.u32l;
    Andross_James_Setup(rdram, ctx);
        goto after_63;
    // 0x8018ACA0: swc1        $f10, 0x7A5C($at)
    MEM_W(0X7A5C, ctx->r1) = ctx->f10.u32l;
    after_63:
    // 0x8018ACA4: jal         0x80187C5C
    // 0x8018ACA8: nop

    Andross_LoadEscapePath(rdram, ctx);
        goto after_64;
    // 0x8018ACA8: nop

    after_64:
    // 0x8018ACAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018ACB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018ACB4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8018ACB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8018ACBC: swc1        $f4, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f4.u32l;
    // 0x8018ACC0: jal         0x800B7184
    // 0x8018ACC4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Camera_Update360(rdram, ctx);
        goto after_65;
    // 0x8018ACC4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_65:
    // 0x8018ACC8: jal         0x8001C8B8
    // 0x8018ACCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_StartPlayerNoise(rdram, ctx);
        goto after_66;
    // 0x8018ACCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_66:
    // 0x8018ACD0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8018ACD4: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x8018ACD8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018ACDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018ACE0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8018ACE4: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8018ACE8: lhu         $a1, -0x616E($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X616E);
    // 0x8018ACEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018ACF0: jal         0x8001D444
    // 0x8018ACF4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_67;
    // 0x8018ACF4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_67:
    // 0x8018ACF8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018ACFC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018AD00: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018AD04: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018AD08: lui         $a0, 0x1140
    ctx->r4 = S32(0X1140 << 16);
    // 0x8018AD0C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8018AD10: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8018AD14: ori         $a0, $a0, 0x3076
    ctx->r4 = ctx->r4 | 0X3076;
    // 0x8018AD18: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018AD1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018AD20: jal         0x80019218
    // 0x8018AD24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_68;
    // 0x8018AD24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_68:
    // 0x8018AD28: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8018AD2C: lw          $t0, 0x1A98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1A98);
    // 0x8018AD30: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018AD34: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AD38: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018AD3C: b           L_8018AD9C
    // 0x8018AD40: sw          $t0, 0x7CA4($at)
    MEM_W(0X7CA4, ctx->r1) = ctx->r8;
        goto L_8018AD9C;
    // 0x8018AD40: sw          $t0, 0x7CA4($at)
    MEM_W(0X7CA4, ctx->r1) = ctx->r8;
L_8018AD44:
    // 0x8018AD44: addiu       $a0, $a0, 0x2D68
    ctx->r4 = ADD32(ctx->r4, 0X2D68);
    // 0x8018AD48: jal         0x800BA808
    // 0x8018AD4C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    Radio_PlayMessage(rdram, ctx);
        goto after_69;
    // 0x8018AD4C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_69:
    // 0x8018AD50: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AD54: b           L_8018AD9C
    // 0x8018AD58: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018AD9C;
    // 0x8018AD58: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AD5C:
    // 0x8018AD5C: jal         0x8001D400
    // 0x8018AD60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_70;
    // 0x8018AD60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_70:
    // 0x8018AD64: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AD68: b           L_8018AD9C
    // 0x8018AD6C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018AD9C;
    // 0x8018AD6C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AD70:
    // 0x8018AD70: addiu       $a0, $a0, 0x2DA4
    ctx->r4 = ADD32(ctx->r4, 0X2DA4);
    // 0x8018AD74: jal         0x800BA808
    // 0x8018AD78: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    Radio_PlayMessage(rdram, ctx);
        goto after_71;
    // 0x8018AD78: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_71:
    // 0x8018AD7C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AD80: b           L_8018AD9C
    // 0x8018AD84: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8018AD9C;
    // 0x8018AD84: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AD88:
    // 0x8018AD88: addiu       $a0, $a0, 0x2DC8
    ctx->r4 = ADD32(ctx->r4, 0X2DC8);
    // 0x8018AD8C: jal         0x800BA808
    // 0x8018AD90: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    Radio_PlayMessage(rdram, ctx);
        goto after_72;
    // 0x8018AD90: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_72:
    // 0x8018AD94: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AD98: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8018AD9C:
    // 0x8018AD9C: slti        $at, $v1, 0x259
    ctx->r1 = SIGNED(ctx->r3) < 0X259 ? 1 : 0;
L_8018ADA0:
    // 0x8018ADA0: bne         $at, $zero, L_8018ADDC
    if (ctx->r1 != 0) {
        // 0x8018ADA4: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_8018ADDC;
    }
    // 0x8018ADA4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8018ADA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018ADAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018ADB0: lw          $t1, 0x7AF8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7AF8);
    // 0x8018ADB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018ADB8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8018ADBC: addiu       $t3, $t3, 0x79A8
    ctx->r11 = ADD32(ctx->r11, 0X79A8);
    // 0x8018ADC0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8018ADC4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018ADC8: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x8018ADCC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8018ADD0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8018ADD4: jal         0x8009BC2C
    // 0x8018ADD8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_73;
    // 0x8018ADD8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_73:
L_8018ADDC:
    // 0x8018ADDC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ADE0: lwc1        $f6, 0x6CB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6CB0);
    // 0x8018ADE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018ADE8: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018ADEC: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018ADF0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8018ADF4: lw          $v0, 0x1C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C8);
    // 0x8018ADF8: bne         $v0, $at, L_8018AEE0
    if (ctx->r2 != ctx->r1) {
        // 0x8018ADFC: nop
    
            goto L_8018AEE0;
    }
    // 0x8018ADFC: nop

    // 0x8018AE00: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x8018AE04: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x8018AE08: bne         $t5, $zero, L_8018AEE0
    if (ctx->r13 != 0) {
        // 0x8018AE0C: nop
    
            goto L_8018AEE0;
    }
    // 0x8018AE0C: nop

    // 0x8018AE10: lwc1        $f10, 0xE8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8018AE14: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018AE18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AE1C: lwc1        $f6, 0x6CB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6CB4);
    // 0x8018AE20: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018AE24: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AE28: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018AE2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018AE30: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8018AE34: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018AE38: jal         0x80005E90
    // 0x8018AE3C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_74;
    // 0x8018AE3C: nop

    after_74:
    // 0x8018AE40: jal         0x80004EB0
    // 0x8018AE44: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_75;
    // 0x8018AE44: nop

    after_75:
    // 0x8018AE48: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018AE4C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AE50: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8018AE54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018AE58: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018AE5C: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018AE60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AE64: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8018AE68: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x8018AE6C: jal         0x80004EB0
    // 0x8018AE70: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_76;
    // 0x8018AE70: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    after_76:
    // 0x8018AE74: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8018AE78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018AE7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AE80: lwc1        $f10, 0x6CB8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6CB8);
    // 0x8018AE84: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018AE88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AE8C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018AE90: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018AE94: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8018AE98: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8018AE9C: jal         0x80006A20
    // 0x8018AEA0: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_77;
    // 0x8018AEA0: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    after_77:
    // 0x8018AEA4: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8018AEA8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018AEAC: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018AEB0: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018AEB4: lwc1        $f10, 0x138($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X138);
    // 0x8018AEB8: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x8018AEBC: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018AEC0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8018AEC4: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018AEC8: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018AECC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018AED0: jal         0x80189B00
    // 0x8018AED4: nop

    Andross_Effect357_Spawn(rdram, ctx);
        goto after_78;
    // 0x8018AED4: nop

    after_78:
    // 0x8018AED8: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8018AEDC: lw          $v0, 0x1C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C8);
L_8018AEE0:
    // 0x8018AEE0: beql        $v0, $zero, L_8018B080
    if (ctx->r2 == 0) {
        // 0x8018AEE4: lwc1        $f6, 0xE4($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
            goto L_8018B080;
    }
    goto skip_17;
    // 0x8018AEE4: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    skip_17:
    // 0x8018AEE8: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8018AEEC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AEF0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018AEF4: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8018AEF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018AEFC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018AF00: jal         0x80005E90
    // 0x8018AF04: nop

    Matrix_RotateY(rdram, ctx);
        goto after_79;
    // 0x8018AF04: nop

    after_79:
    // 0x8018AF08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018AF0C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x8018AF10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018AF14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AF18: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018AF1C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018AF20: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8018AF24: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8018AF28: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8018AF2C: jal         0x80006A20
    // 0x8018AF30: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_80;
    // 0x8018AF30: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    after_80:
    // 0x8018AF34: jal         0x80004EB0
    // 0x8018AF38: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_81;
    // 0x8018AF38: nop

    after_81:
    // 0x8018AF3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018AF40: lwc1        $f8, 0x6CBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CBC);
    // 0x8018AF44: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AF48: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018AF4C: mul.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018AF50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018AF54: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8018AF58: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018AF5C: jal         0x80005FE0
    // 0x8018AF60: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_82;
    // 0x8018AF60: nop

    after_82:
    // 0x8018AF64: jal         0x80004EB0
    // 0x8018AF68: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_83;
    // 0x8018AF68: nop

    after_83:
    // 0x8018AF6C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8018AF70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018AF74: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018AF78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018AF7C: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018AF80: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018AF84: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018AF88: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018AF8C: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018AF90: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8018AF94: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x8018AF98: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018AF9C: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x8018AFA0: jal         0x80006A20
    // 0x8018AFA4: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_84;
    // 0x8018AFA4: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    after_84:
    // 0x8018AFA8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8018AFAC: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8018AFB0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018AFB4: slti        $at, $v1, 0x3E8
    ctx->r1 = SIGNED(ctx->r3) < 0X3E8 ? 1 : 0;
    // 0x8018AFB8: beql        $at, $zero, L_8018AFCC
    if (ctx->r1 == 0) {
        // 0x8018AFBC: slti        $at, $v1, 0x5DC
        ctx->r1 = SIGNED(ctx->r3) < 0X5DC ? 1 : 0;
            goto L_8018AFCC;
    }
    goto skip_18;
    // 0x8018AFBC: slti        $at, $v1, 0x5DC
    ctx->r1 = SIGNED(ctx->r3) < 0X5DC ? 1 : 0;
    skip_18:
    // 0x8018AFC0: b           L_8018AFF0
    // 0x8018AFC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018AFF0;
    // 0x8018AFC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018AFC8: slti        $at, $v1, 0x5DC
    ctx->r1 = SIGNED(ctx->r3) < 0X5DC ? 1 : 0;
L_8018AFCC:
    // 0x8018AFCC: beql        $at, $zero, L_8018AFE0
    if (ctx->r1 == 0) {
        // 0x8018AFD0: slti        $at, $v1, 0x7D0
        ctx->r1 = SIGNED(ctx->r3) < 0X7D0 ? 1 : 0;
            goto L_8018AFE0;
    }
    goto skip_19;
    // 0x8018AFD0: slti        $at, $v1, 0x7D0
    ctx->r1 = SIGNED(ctx->r3) < 0X7D0 ? 1 : 0;
    skip_19:
    // 0x8018AFD4: b           L_8018AFF0
    // 0x8018AFD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8018AFF0;
    // 0x8018AFD8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8018AFDC: slti        $at, $v1, 0x7D0
    ctx->r1 = SIGNED(ctx->r3) < 0X7D0 ? 1 : 0;
L_8018AFE0:
    // 0x8018AFE0: beq         $at, $zero, L_8018AFF0
    if (ctx->r1 == 0) {
        // 0x8018AFE4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8018AFF0;
    }
    // 0x8018AFE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018AFE8: b           L_8018AFF0
    // 0x8018AFEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018AFF0;
    // 0x8018AFEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018AFF0:
    // 0x8018AFF0: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8018AFF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018AFF8: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x8018AFFC: and         $t9, $t7, $v0
    ctx->r25 = ctx->r15 & ctx->r2;
    // 0x8018B000: bne         $t9, $zero, L_8018B07C
    if (ctx->r25 != 0) {
        // 0x8018B004: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018B07C;
    }
    // 0x8018B004: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018B008:
    // 0x8018B008: jal         0x80004EB0
    // 0x8018B00C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    Rand_ZeroOne(rdram, ctx);
        goto after_85;
    // 0x8018B00C: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
    after_85:
    // 0x8018B010: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8018B014: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018B018: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018B01C: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8018B020: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8018B024: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8018B028: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018B02C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018B030: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8018B034: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018B038: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018B03C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8018B040: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x8018B044: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018B048: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8018B04C: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8018B050: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018B054: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018B058: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8018B05C: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8018B060: jal         0x8007797C
    // 0x8018B064: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_FireSmoke1_SpawnMoving(rdram, ctx);
        goto after_86;
    // 0x8018B064: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_86:
    // 0x8018B068: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
    // 0x8018B06C: lw          $t8, 0x98($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X98);
    // 0x8018B070: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018B074: bne         $v0, $t8, L_8018B008
    if (ctx->r2 != ctx->r24) {
        // 0x8018B078: nop
    
            goto L_8018B008;
    }
    // 0x8018B078: nop

L_8018B07C:
    // 0x8018B07C: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
L_8018B080:
    // 0x8018B080: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018B084: lwc1        $f4, 0xE8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x8018B088: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018B08C: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8018B090: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8018B094: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    // 0x8018B098: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018B09C: lwc1        $f10, 0xEC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8018B0A0: swc1        $f12, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f12.u32l;
    // 0x8018B0A4: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018B0A8: jal         0x80005100
    // 0x8018B0AC: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_87;
    // 0x8018B0AC: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    after_87:
    // 0x8018B0B0: jal         0x8009F768
    // 0x8018B0B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_88;
    // 0x8018B0B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_88:
    // 0x8018B0B8: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018B0BC: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8018B0C0: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8018B0C4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018B0C8: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8018B0CC: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018B0D0: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8018B0D4: jal         0x80005100
    // 0x8018B0D8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_89;
    // 0x8018B0D8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_89:
    // 0x8018B0DC: jal         0x8009F768
    // 0x8018B0E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_90;
    // 0x8018B0E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_90:
    // 0x8018B0E4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018B0E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018B0EC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018B0F0: lw          $a3, 0xE0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE0);
    // 0x8018B0F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B0F8: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x8018B0FC: jal         0x8009BD38
    // 0x8018B100: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_91;
    // 0x8018B100: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_91:
    // 0x8018B104: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018B108: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018B10C: lw          $a3, 0xE0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE0);
    // 0x8018B110: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B114: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    // 0x8018B118: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8018B11C: jal         0x8009BD38
    // 0x8018B120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_92;
    // 0x8018B120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_92:
    // 0x8018B124: lh          $t0, 0x90($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X90);
    // 0x8018B128: beql        $t0, $zero, L_8018B16C
    if (ctx->r8 == 0) {
        // 0x8018B12C: lh          $t2, 0x54($s1)
        ctx->r10 = MEM_H(ctx->r17, 0X54);
            goto L_8018B16C;
    }
    goto skip_20;
    // 0x8018B12C: lh          $t2, 0x54($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X54);
    skip_20:
    // 0x8018B130: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8018B134: lwc1        $f12, 0x58($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X58);
    // 0x8018B138: jal         0x8009F768
    // 0x8018B13C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_93;
    // 0x8018B13C: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_93:
    // 0x8018B140: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018B144: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018B148: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8018B14C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8018B150: addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // 0x8018B154: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018B158: jal         0x8009BD38
    // 0x8018B15C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_94;
    // 0x8018B15C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_94:
    // 0x8018B160: b           L_8018B1A4
    // 0x8018B164: nop

        goto L_8018B1A4;
    // 0x8018B164: nop

    // 0x8018B168: lh          $t2, 0x54($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X54);
L_8018B16C:
    // 0x8018B16C: bne         $t2, $zero, L_8018B1A4
    if (ctx->r10 != 0) {
        // 0x8018B170: nop
    
            goto L_8018B1A4;
    }
    // 0x8018B170: nop

    // 0x8018B174: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8018B178: lwc1        $f12, 0x58($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X58);
    // 0x8018B17C: jal         0x8009F768
    // 0x8018B180: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_95;
    // 0x8018B180: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_95:
    // 0x8018B184: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018B188: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018B18C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8018B190: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8018B194: addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // 0x8018B198: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8018B19C: jal         0x8009BD38
    // 0x8018B1A0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_96;
    // 0x8018B1A0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_96:
L_8018B1A4:
    // 0x8018B1A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B1A8: lwc1        $f10, 0x6CC0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6CC0);
    // 0x8018B1AC: lw          $a1, 0xDC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XDC);
    // 0x8018B1B0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018B1B4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018B1B8: addiu       $a0, $s1, 0xD8
    ctx->r4 = ADD32(ctx->r17, 0XD8);
    // 0x8018B1BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018B1C0: jal         0x8009BC2C
    // 0x8018B1C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_97;
    // 0x8018B1C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_97:
    // 0x8018B1C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B1CC: lwc1        $f8, 0x6CC4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CC4);
    // 0x8018B1D0: lwc1        $f4, 0x7C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x8018B1D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B1D8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B1DC: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018B1E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018B1E4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018B1E8: jal         0x80005E90
    // 0x8018B1EC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_98;
    // 0x8018B1EC: nop

    after_98:
    // 0x8018B1F0: lwc1        $f10, 0x78($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8018B1F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B1F8: lwc1        $f8, 0x6CC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6CC8);
    // 0x8018B1FC: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8018B200: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B204: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8018B208: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B20C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B210: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018B214: jal         0x80005D44
    // 0x8018B218: nop

    Matrix_RotateX(rdram, ctx);
        goto after_99;
    // 0x8018B218: nop

    after_99:
    // 0x8018B21C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018B220: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B224: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B228: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8018B22C: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x8018B230: lwc1        $f10, 0xD8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018B234: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8018B238: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8018B23C: jal         0x80006A20
    // 0x8018B240: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_100;
    // 0x8018B240: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    after_100:
    // 0x8018B244: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018B248: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018B24C: lh          $t4, 0x4E($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4E);
    // 0x8018B250: swc1        $f4, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f4.u32l;
    // 0x8018B254: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8018B258: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018B25C: addiu       $v0, $v0, 0x5A10
    ctx->r2 = ADD32(ctx->r2, 0X5A10);
    // 0x8018B260: swc1        $f8, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f8.u32l;
    // 0x8018B264: lwc1        $f10, 0x7D08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8018B268: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018B26C: slti        $at, $t4, 0x14
    ctx->r1 = SIGNED(ctx->r12) < 0X14 ? 1 : 0;
    // 0x8018B270: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018B274: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8018B278: addiu       $t6, $zero, 0x66
    ctx->r14 = ADD32(0, 0X66);
    // 0x8018B27C: beq         $at, $zero, L_8018B2B8
    if (ctx->r1 == 0) {
        // 0x8018B280: swc1        $f4, 0x74($s1)
        MEM_W(0X74, ctx->r17) = ctx->f4.u32l;
            goto L_8018B2B8;
    }
    // 0x8018B280: swc1        $f4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f4.u32l;
    // 0x8018B284: sb          $t5, 0x938($v0)
    MEM_B(0X938, ctx->r2) = ctx->r13;
    // 0x8018B288: sh          $t6, 0x93A($v0)
    MEM_H(0X93A, ctx->r2) = ctx->r14;
    // 0x8018B28C: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018B290: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018B294: swc1        $f8, 0x93C($v0)
    MEM_W(0X93C, ctx->r2) = ctx->f8.u32l;
    // 0x8018B298: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018B29C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B2A0: swc1        $f6, 0x940($v0)
    MEM_W(0X940, ctx->r2) = ctx->f6.u32l;
    // 0x8018B2A4: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018B2A8: swc1        $f10, 0x944($v0)
    MEM_W(0X944, ctx->r2) = ctx->f10.u32l;
    // 0x8018B2AC: lwc1        $f4, 0x7C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x8018B2B0: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018B2B4: swc1        $f6, 0x948($v0)
    MEM_W(0X948, ctx->r2) = ctx->f6.u32l;
L_8018B2B8:
    // 0x8018B2B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B2BC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018B2C0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8018B2C4: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8018B2C8: swc1        $f12, 0x1DC0($s0)
    MEM_W(0X1DC0, ctx->r16) = ctx->f12.u32l;
    // 0x8018B2CC: swc1        $f12, 0x20B4($s0)
    MEM_W(0X20B4, ctx->r16) = ctx->f12.u32l;
    // 0x8018B2D0: lh          $v0, 0x92($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X92);
    // 0x8018B2D4: beq         $v0, $zero, L_8018B424
    if (ctx->r2 == 0) {
        // 0x8018B2D8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8018B424;
    }
    // 0x8018B2D8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8018B2DC: sh          $t7, 0x92($s1)
    MEM_H(0X92, ctx->r17) = ctx->r15;
    // 0x8018B2E0: lh          $t9, 0x92($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X92);
    // 0x8018B2E4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B2E8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B2EC: bne         $t9, $zero, L_8018B3B4
    if (ctx->r25 != 0) {
        // 0x8018B2F0: lui         $s2, 0x1103
        ctx->r18 = S32(0X1103 << 16);
            goto L_8018B3B4;
    }
    // 0x8018B2F0: lui         $s2, 0x1103
    ctx->r18 = S32(0X1103 << 16);
    // 0x8018B2F4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018B2F8: ori         $s2, $s2, 0x2075
    ctx->r18 = ctx->r18 | 0X2075;
    // 0x8018B2FC: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018B300: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018B304: addiu       $a1, $a1, 0x5E68
    ctx->r5 = ADD32(ctx->r5, 0X5E68);
    // 0x8018B308: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018B30C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018B310: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018B314: jal         0x80019218
    // 0x8018B318: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_101;
    // 0x8018B318: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_101:
    // 0x8018B31C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B320: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8018B324: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B328: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8018B32C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018B330: addiu       $a1, $a1, 0x615C
    ctx->r5 = ADD32(ctx->r5, 0X615C);
    // 0x8018B334: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018B338: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B33C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018B340: jal         0x80019218
    // 0x8018B344: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_102;
    // 0x8018B344: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_102:
    // 0x8018B348: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B34C: lui         $s2, 0x3103
    ctx->r18 = S32(0X3103 << 16);
    // 0x8018B350: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018B354: ori         $s2, $s2, 0x108B
    ctx->r18 = ctx->r18 | 0X108B;
    // 0x8018B358: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B35C: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018B360: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018B364: addiu       $a1, $a1, 0x5E68
    ctx->r5 = ADD32(ctx->r5, 0X5E68);
    // 0x8018B368: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018B36C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B370: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018B374: jal         0x80019218
    // 0x8018B378: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_103;
    // 0x8018B378: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_103:
    // 0x8018B37C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018B380: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8018B384: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018B388: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8018B38C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018B390: addiu       $a1, $a1, 0x615C
    ctx->r5 = ADD32(ctx->r5, 0X615C);
    // 0x8018B394: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8018B398: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018B39C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018B3A0: jal         0x80019218
    // 0x8018B3A4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_104;
    // 0x8018B3A4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_104:
    // 0x8018B3A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B3AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018B3B0: nop

L_8018B3B4:
    // 0x8018B3B4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018B3B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018B3BC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018B3C0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018B3C4: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8018B3C8: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8018B3CC: swc1        $f4, 0x1D8C($s0)
    MEM_W(0X1D8C, ctx->r16) = ctx->f4.u32l;
    // 0x8018B3D0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018B3D4: sub.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8018B3D8: swc1        $f6, 0x1D90($s0)
    MEM_W(0X1D90, ctx->r16) = ctx->f6.u32l;
    // 0x8018B3DC: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018B3E0: sh          $zero, 0x1E40($s0)
    MEM_H(0X1E40, ctx->r16) = 0;
    // 0x8018B3E4: sh          $v0, 0x1E4A($s0)
    MEM_H(0X1E4A, ctx->r16) = ctx->r2;
    // 0x8018B3E8: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8018B3EC: swc1        $f2, 0x1DC0($s0)
    MEM_W(0X1DC0, ctx->r16) = ctx->f2.u32l;
    // 0x8018B3F0: swc1        $f4, 0x1D94($s0)
    MEM_W(0X1D94, ctx->r16) = ctx->f4.u32l;
    // 0x8018B3F4: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018B3F8: sub.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8018B3FC: swc1        $f6, 0x2080($s0)
    MEM_W(0X2080, ctx->r16) = ctx->f6.u32l;
    // 0x8018B400: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018B404: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8018B408: swc1        $f4, 0x2084($s0)
    MEM_W(0X2084, ctx->r16) = ctx->f4.u32l;
    // 0x8018B40C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018B410: sh          $zero, 0x2134($s0)
    MEM_H(0X2134, ctx->r16) = 0;
    // 0x8018B414: sh          $v0, 0x213E($s0)
    MEM_H(0X213E, ctx->r16) = ctx->r2;
    // 0x8018B418: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018B41C: swc1        $f2, 0x20B4($s0)
    MEM_W(0X20B4, ctx->r16) = ctx->f2.u32l;
    // 0x8018B420: swc1        $f6, 0x2088($s0)
    MEM_W(0X2088, ctx->r16) = ctx->f6.u32l;
L_8018B424:
    // 0x8018B424: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018B428: lw          $a1, 0x130($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X130);
    // 0x8018B42C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8018B430: addiu       $a0, $s1, 0x12C
    ctx->r4 = ADD32(ctx->r17, 0X12C);
    // 0x8018B434: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8018B438: jal         0x8009BC2C
    // 0x8018B43C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_105;
    // 0x8018B43C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_105:
    // 0x8018B440: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018B444: lw          $a1, 0x138($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X138);
    // 0x8018B448: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x8018B44C: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x8018B450: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8018B454: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8018B458: addiu       $a0, $s1, 0x134
    ctx->r4 = ADD32(ctx->r17, 0X134);
    // 0x8018B45C: jal         0x8009BC2C
    // 0x8018B460: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_106;
    // 0x8018B460: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_106:
    // 0x8018B464: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018B468: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018B46C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B470: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018B474: jr          $ra
    // 0x8018B478: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8018B478: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Andross_AndSuctionEject_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C8D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018C8D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018C8DC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8018C8E0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8018C8E4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018C8E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018C8EC: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8018C8F0: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8018C8F4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8018C8F8:
    // 0x8018C8F8: bnel        $t6, $zero, L_8018C93C
    if (ctx->r14 != 0) {
        // 0x8018C8FC: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8018C93C;
    }
    goto skip_0;
    // 0x8018C8FC: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8018C900: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018C904: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018C908: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018C90C: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8018C910: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8018C914: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8018C918: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8018C91C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018C920: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018C924: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018C928: jal         0x8018C7A0
    // 0x8018C92C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    Andross_AndSuctionEject_Setup(rdram, ctx);
        goto after_0;
    // 0x8018C92C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8018C930: b           L_8018C94C
    // 0x8018C934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018C94C;
    // 0x8018C934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018C938: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8018C93C:
    // 0x8018C93C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8018C940: beql        $at, $zero, L_8018C8F8
    if (ctx->r1 == 0) {
        // 0x8018C944: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8018C8F8;
    }
    goto skip_1;
    // 0x8018C944: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8018C948: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018C94C:
    // 0x8018C94C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018C950: jr          $ra
    // 0x8018C954: nop

    return;
    // 0x8018C954: nop

;}
RECOMP_FUNC void SectorY_SyShogun_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E2C4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8019E2C8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8019E2CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8019E2D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8019E2D4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8019E2D8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019E2DC: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8019E2E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019E2E4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8019E2E8: bne         $t6, $zero, L_8019E318
    if (ctx->r14 != 0) {
        // 0x8019E2EC: lui         $a2, 0x8018
        ctx->r6 = S32(0X8018 << 16);
            goto L_8019E318;
    }
    // 0x8019E2EC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8019E2F0: lh          $t7, 0xB8($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XB8);
    // 0x8019E2F4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8019E2F8: bne         $t8, $zero, L_8019E318
    if (ctx->r24 != 0) {
        // 0x8019E2FC: nop
    
            goto L_8019E318;
    }
    // 0x8019E2FC: nop

    // 0x8019E300: lh          $t9, 0x5C($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X5C);
    // 0x8019E304: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8019E308: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8019E30C: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x8019E310: beq         $t0, $zero, L_8019E350
    if (ctx->r8 == 0) {
        // 0x8019E314: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_8019E350;
    }
    // 0x8019E314: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
L_8019E318:
    // 0x8019E318: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8019E31C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8019E320: lw          $t2, -0x7C24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C24);
    // 0x8019E324: lw          $t1, -0x7C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7C28);
    // 0x8019E328: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8019E32C: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8019E330: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8019E334: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8019E338: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8019E33C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019E340: jal         0x800BA2E8
    // 0x8019E344: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    RCP_SetupDL_30(rdram, ctx);
        goto after_0;
    // 0x8019E344: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_0:
    // 0x8019E348: b           L_8019E384
    // 0x8019E34C: lh          $t5, 0x60($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X60);
        goto L_8019E384;
    // 0x8019E34C: lh          $t5, 0x60($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X60);
L_8019E350:
    // 0x8019E350: lw          $t3, -0x7C28($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C28);
    // 0x8019E354: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x8019E358: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019E35C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8019E360: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8019E364: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8019E368: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8019E36C: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8019E370: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8019E374: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019E378: jal         0x800BA1D0
    // 0x8019E37C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    RCP_SetupDL_29(rdram, ctx);
        goto after_1;
    // 0x8019E37C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_1:
    // 0x8019E380: lh          $t5, 0x60($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X60);
L_8019E384:
    // 0x8019E384: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x8019E388: addiu       $a1, $a1, -0x2EC0
    ctx->r5 = ADD32(ctx->r5, -0X2EC0);
    // 0x8019E38C: bgtz        $t5, L_8019E39C
    if (SIGNED(ctx->r13) > 0) {
        // 0x8019E390: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8019E39C;
    }
    // 0x8019E390: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8019E394: lh          $t6, 0xD0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XD0);
    // 0x8019E398: bne         $t6, $zero, L_8019EB68
    if (ctx->r14 != 0) {
        // 0x8019E39C: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_8019EB68;
    }
L_8019E39C:
    // 0x8019E39C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x8019E3A0: lw          $t8, -0x4438($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4438);
    // 0x8019E3A4: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8019E3A8: addiu       $t7, $t7, -0x1FEC
    ctx->r15 = ADD32(ctx->r15, -0X1FEC);
    // 0x8019E3AC: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8019E3B0: addiu       $a3, $a3, -0x21F0
    ctx->r7 = ADD32(ctx->r7, -0X21F0);
    // 0x8019E3B4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019E3B8: addiu       $a2, $s1, 0x1A0
    ctx->r6 = ADD32(ctx->r17, 0X1A0);
    // 0x8019E3BC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8019E3C0: jal         0x8009A72C
    // 0x8019E3C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x8019E3C4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_2:
    // 0x8019E3C8: lh          $v0, 0x54($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X54);
    // 0x8019E3CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E3D0: beq         $v0, $zero, L_8019E4A8
    if (ctx->r2 == 0) {
        // 0x8019E3D4: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_8019E4A8;
    }
    // 0x8019E3D4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8019E3D8: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019E3DC: lwc1        $f4, 0x69AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69AC);
    // 0x8019E3E0: jal         0x800BA5B0
    // 0x8019E3E4: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    RCP_SetupDL_49(rdram, ctx);
        goto after_3;
    // 0x8019E3E4: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8019E3E8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019E3EC: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8019E3F0: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8019E3F4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019E3F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E3FC: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8019E400: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8019E404: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8019E408: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8019E40C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8019E410: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8019E414: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E418: lui         $t5, 0xFF30
    ctx->r13 = S32(0XFF30 << 16);
    // 0x8019E41C: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x8019E420: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8019E424: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8019E428: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x8019E42C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8019E430: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8019E434: jal         0x80005740
    // 0x8019E438: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x8019E438: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x8019E43C: jal         0x80005708
    // 0x8019E440: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x8019E440: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x8019E444: lw          $a1, 0xDC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XDC);
    // 0x8019E448: lw          $a2, 0xE0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE0);
    // 0x8019E44C: lw          $a3, 0xE4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE4);
    // 0x8019E450: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019E454: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019E458: jal         0x80005B00
    // 0x8019E45C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x8019E45C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_6:
    // 0x8019E460: lwc1        $f0, 0x9C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8019E464: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019E468: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019E46C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019E470: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019E474: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019E478: jal         0x80005C34
    // 0x8019E47C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x8019E47C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_7:
    // 0x8019E480: jal         0x80006EB8
    // 0x8019E484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x8019E484: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8019E488: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E48C: lui         $t0, 0x102
    ctx->r8 = S32(0X102 << 16);
    // 0x8019E490: addiu       $t0, $t0, 0x4AC0
    ctx->r8 = ADD32(ctx->r8, 0X4AC0);
    // 0x8019E494: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8019E498: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8019E49C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8019E4A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8019E4A4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
L_8019E4A8:
    // 0x8019E4A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019E4AC: lwc1        $f8, 0x160($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X160);
    // 0x8019E4B0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019E4B4: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8019E4B8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8019E4BC: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8019E4C0: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8019E4C4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019E4C8: bc1t        L_8019E680
    if (c1cs) {
        // 0x8019E4CC: addiu       $t1, $t1, 0x4AC0
        ctx->r9 = ADD32(ctx->r9, 0X4AC0);
            goto L_8019E680;
    }
    // 0x8019E4CC: addiu       $t1, $t1, 0x4AC0
    ctx->r9 = ADD32(ctx->r9, 0X4AC0);
    // 0x8019E4D0: jal         0x800BA5B0
    // 0x8019E4D4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    RCP_SetupDL_49(rdram, ctx);
        goto after_9;
    // 0x8019E4D4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    after_9:
    // 0x8019E4D8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E4DC: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8019E4E0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8019E4E4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8019E4E8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8019E4EC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8019E4F0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019E4F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E4F8: lui         $t7, 0x20FF
    ctx->r15 = S32(0X20FF << 16);
    // 0x8019E4FC: ori         $t7, $t7, 0x20FF
    ctx->r15 = ctx->r15 | 0X20FF;
    // 0x8019E500: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8019E504: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8019E508: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8019E50C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019E510: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8019E514: jal         0x80005740
    // 0x8019E518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x8019E518: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x8019E51C: jal         0x80005708
    // 0x8019E520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x8019E520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_11:
    // 0x8019E524: lw          $a1, 0x154($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X154);
    // 0x8019E528: lw          $a2, 0x158($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X158);
    // 0x8019E52C: lw          $a3, 0x15C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X15C);
    // 0x8019E530: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019E534: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019E538: jal         0x80005B00
    // 0x8019E53C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_12;
    // 0x8019E53C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_12:
    // 0x8019E540: lwc1        $f0, 0x160($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X160);
    // 0x8019E544: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019E548: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8019E54C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019E550: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019E554: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019E558: jal         0x80005C34
    // 0x8019E55C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x8019E55C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_13:
    // 0x8019E560: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8019E564: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E568: lwc1        $f4, 0x77A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77A0);
    // 0x8019E56C: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8019E570: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E574: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019E578: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E57C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019E580: jal         0x80005D44
    // 0x8019E584: nop

    Matrix_RotateX(rdram, ctx);
        goto after_14;
    // 0x8019E584: nop

    after_14:
    // 0x8019E588: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8019E58C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E590: lwc1        $f18, 0x77A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X77A4);
    // 0x8019E594: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8019E598: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E59C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8019E5A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E5A4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019E5A8: jal         0x80005FE0
    // 0x8019E5AC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_15;
    // 0x8019E5AC: nop

    after_15:
    // 0x8019E5B0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019E5B4: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8019E5B8: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019E5BC: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019E5C0: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8019E5C4: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8019E5C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E5CC: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8019E5D0: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019E5D4: swc1        $f4, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f4.u32l;
    // 0x8019E5D8: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019E5DC: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8019E5E0: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8019E5E4: swc1        $f12, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f12.u32l;
    // 0x8019E5E8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019E5EC: sub.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8019E5F0: jal         0x80005100
    // 0x8019E5F4: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_16;
    // 0x8019E5F4: swc1        $f14, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f14.u32l;
    after_16:
    // 0x8019E5F8: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8019E5FC: lwc1        $f2, 0x98($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8019E600: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8019E604: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8019E608: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8019E60C: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8019E610: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8019E614: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019E618: jal         0x80005100
    // 0x8019E61C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_17;
    // 0x8019E61C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_17:
    // 0x8019E620: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8019E624: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8019E628: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E62C: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x8019E630: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E634: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019E638: jal         0x80005E90
    // 0x8019E63C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_18;
    // 0x8019E63C: nop

    after_18:
    // 0x8019E640: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8019E644: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E648: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E64C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8019E650: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019E654: jal         0x80005D44
    // 0x8019E658: nop

    Matrix_RotateX(rdram, ctx);
        goto after_19;
    // 0x8019E658: nop

    after_19:
    // 0x8019E65C: jal         0x80006EB8
    // 0x8019E660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_20;
    // 0x8019E660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8019E664: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E668: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8019E66C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8019E670: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8019E674: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8019E678: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8019E67C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_8019E680:
    // 0x8019E680: lw          $t3, 0x40($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X40);
    // 0x8019E684: bnel        $t3, $zero, L_8019E920
    if (ctx->r11 != 0) {
        // 0x8019E688: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8019E920;
    }
    goto skip_0;
    // 0x8019E688: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_0:
    // 0x8019E68C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019E690: lwc1        $f18, 0x17C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X17C);
    // 0x8019E694: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x8019E698: addiu       $t4, $t4, 0x4AC0
    ctx->r12 = ADD32(ctx->r12, 0X4AC0);
    // 0x8019E69C: c.eq.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl == ctx->f18.fl;
    // 0x8019E6A0: nop

    // 0x8019E6A4: bc1tl       L_8019E7D8
    if (c1cs) {
        // 0x8019E6A8: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8019E7D8;
    }
    goto skip_1;
    // 0x8019E6A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_1:
    // 0x8019E6AC: jal         0x800BA5B0
    // 0x8019E6B0: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    RCP_SetupDL_49(rdram, ctx);
        goto after_21;
    // 0x8019E6B0: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    after_21:
    // 0x8019E6B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E6B8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8019E6BC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8019E6C0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8019E6C4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8019E6C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8019E6CC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019E6D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E6D4: lui         $t0, 0x20FF
    ctx->r8 = S32(0X20FF << 16);
    // 0x8019E6D8: ori         $t0, $t0, 0x20FF
    ctx->r8 = ctx->r8 | 0X20FF;
    // 0x8019E6DC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8019E6E0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8019E6E4: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8019E6E8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8019E6EC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8019E6F0: jal         0x80005740
    // 0x8019E6F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_22;
    // 0x8019E6F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_22:
    // 0x8019E6F8: jal         0x80005708
    // 0x8019E6FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_23;
    // 0x8019E6FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_23:
    // 0x8019E700: lw          $a1, 0x164($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X164);
    // 0x8019E704: lw          $a2, 0x168($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X168);
    // 0x8019E708: lw          $a3, 0x16C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X16C);
    // 0x8019E70C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019E710: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8019E714: jal         0x80005B00
    // 0x8019E718: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_24;
    // 0x8019E718: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_24:
    // 0x8019E71C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E720: lwc1        $f4, 0x77A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77A8);
    // 0x8019E724: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8019E728: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E72C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E730: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8019E734: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019E738: jal         0x80005E90
    // 0x8019E73C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_25;
    // 0x8019E73C: nop

    after_25:
    // 0x8019E740: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E744: lwc1        $f18, 0x77AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X77AC);
    // 0x8019E748: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8019E74C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E754: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8019E758: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019E75C: jal         0x80005D44
    // 0x8019E760: nop

    Matrix_RotateX(rdram, ctx);
        goto after_26;
    // 0x8019E760: nop

    after_26:
    // 0x8019E764: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E768: lwc1        $f6, 0x77B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77B0);
    // 0x8019E76C: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8019E770: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E774: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E778: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019E77C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019E780: jal         0x80005FE0
    // 0x8019E784: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_27;
    // 0x8019E784: nop

    after_27:
    // 0x8019E788: lwc1        $f0, 0x17C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X17C);
    // 0x8019E78C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8019E790: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8019E794: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8019E798: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019E79C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E7A0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8019E7A4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8019E7A8: jal         0x80005C34
    // 0x8019E7AC: nop

    Matrix_Scale(rdram, ctx);
        goto after_28;
    // 0x8019E7AC: nop

    after_28:
    // 0x8019E7B0: jal         0x80006EB8
    // 0x8019E7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_29;
    // 0x8019E7B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8019E7B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E7BC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8019E7C0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8019E7C4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8019E7C8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8019E7CC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8019E7D0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8019E7D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_8019E7D8:
    // 0x8019E7D8: lwc1        $f10, 0x180($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X180);
    // 0x8019E7DC: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x8019E7E0: addiu       $t6, $t6, 0x4AC0
    ctx->r14 = ADD32(ctx->r14, 0X4AC0);
    // 0x8019E7E4: c.eq.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl == ctx->f10.fl;
    // 0x8019E7E8: nop

    // 0x8019E7EC: bc1tl       L_8019E920
    if (c1cs) {
        // 0x8019E7F0: mtc1        $zero, $f10
        ctx->f10.u32l = 0;
            goto L_8019E920;
    }
    goto skip_2;
    // 0x8019E7F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    skip_2:
    // 0x8019E7F4: jal         0x800BA5B0
    // 0x8019E7F8: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    RCP_SetupDL_49(rdram, ctx);
        goto after_30;
    // 0x8019E7F8: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    after_30:
    // 0x8019E7FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E800: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8019E804: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8019E808: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019E80C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8019E810: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8019E814: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019E818: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E81C: lui         $t2, 0x20FF
    ctx->r10 = S32(0X20FF << 16);
    // 0x8019E820: ori         $t2, $t2, 0x20FF
    ctx->r10 = ctx->r10 | 0X20FF;
    // 0x8019E824: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8019E828: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8019E82C: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x8019E830: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8019E834: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8019E838: jal         0x80005740
    // 0x8019E83C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_31;
    // 0x8019E83C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_31:
    // 0x8019E840: jal         0x80005708
    // 0x8019E844: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_32;
    // 0x8019E844: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_32:
    // 0x8019E848: lw          $a1, 0x170($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X170);
    // 0x8019E84C: lw          $a2, 0x174($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X174);
    // 0x8019E850: lw          $a3, 0x178($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X178);
    // 0x8019E854: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019E858: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019E85C: jal         0x80005B00
    // 0x8019E860: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_33;
    // 0x8019E860: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_33:
    // 0x8019E864: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E868: lwc1        $f6, 0x77B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77B4);
    // 0x8019E86C: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8019E870: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E874: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E878: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019E87C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019E880: jal         0x80005E90
    // 0x8019E884: nop

    Matrix_RotateY(rdram, ctx);
        goto after_34;
    // 0x8019E884: nop

    after_34:
    // 0x8019E888: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E88C: lwc1        $f10, 0x77B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77B8);
    // 0x8019E890: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8019E894: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E898: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E89C: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8019E8A0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019E8A4: jal         0x80005D44
    // 0x8019E8A8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_35;
    // 0x8019E8A8: nop

    after_35:
    // 0x8019E8AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E8B0: lwc1        $f8, 0x77BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X77BC);
    // 0x8019E8B4: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8019E8B8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E8BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E8C0: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019E8C4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019E8C8: jal         0x80005FE0
    // 0x8019E8CC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_36;
    // 0x8019E8CC: nop

    after_36:
    // 0x8019E8D0: lwc1        $f0, 0x180($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X180);
    // 0x8019E8D4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019E8D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8019E8DC: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8019E8E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019E8E4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E8E8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8019E8EC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8019E8F0: jal         0x80005C34
    // 0x8019E8F4: nop

    Matrix_Scale(rdram, ctx);
        goto after_37;
    // 0x8019E8F4: nop

    after_37:
    // 0x8019E8F8: jal         0x80006EB8
    // 0x8019E8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_38;
    // 0x8019E8FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8019E900: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E904: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8019E908: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8019E90C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8019E910: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019E914: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8019E918: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8019E91C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8019E920:
    // 0x8019E920: lwc1        $f4, 0x184($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X184);
    // 0x8019E924: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x8019E928: addiu       $t8, $t8, 0x4AC0
    ctx->r24 = ADD32(ctx->r24, 0X4AC0);
    // 0x8019E92C: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x8019E930: nop

    // 0x8019E934: bc1tl       L_8019EA00
    if (c1cs) {
        // 0x8019E938: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_8019EA00;
    }
    goto skip_3;
    // 0x8019E938: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_3:
    // 0x8019E93C: jal         0x800BA5B0
    // 0x8019E940: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    RCP_SetupDL_49(rdram, ctx);
        goto after_39;
    // 0x8019E940: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    after_39:
    // 0x8019E944: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E948: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8019E94C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8019E950: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019E954: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8019E958: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8019E95C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8019E960: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E964: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x8019E968: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8019E96C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8019E970: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8019E974: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019E978: jal         0x80005740
    // 0x8019E97C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_40;
    // 0x8019E97C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_40:
    // 0x8019E980: jal         0x80005708
    // 0x8019E984: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_41;
    // 0x8019E984: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_41:
    // 0x8019E988: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8019E98C: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x8019E990: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019E994: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8019E998: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E99C: jal         0x80005B00
    // 0x8019E9A0: lui         $a2, 0x431D
    ctx->r6 = S32(0X431D << 16);
    Matrix_Translate(rdram, ctx);
        goto after_42;
    // 0x8019E9A0: lui         $a2, 0x431D
    ctx->r6 = S32(0X431D << 16);
    after_42:
    // 0x8019E9A4: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8019E9A8: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8019E9AC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019E9B0: jal         0x80005D44
    // 0x8019E9B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_43;
    // 0x8019E9B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_43:
    // 0x8019E9B8: lwc1        $f0, 0x184($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X184);
    // 0x8019E9BC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019E9C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8019E9C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019E9C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019E9CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019E9D0: jal         0x80005C34
    // 0x8019E9D4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_44;
    // 0x8019E9D4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_44:
    // 0x8019E9D8: jal         0x80006EB8
    // 0x8019E9DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_45;
    // 0x8019E9DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x8019E9E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019E9E4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8019E9E8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019E9EC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019E9F0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019E9F4: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8019E9F8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019E9FC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_8019EA00:
    // 0x8019EA00: lwc1        $f8, 0x190($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X190);
    // 0x8019EA04: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x8019EA08: addiu       $t9, $t9, 0x4AC0
    ctx->r25 = ADD32(ctx->r25, 0X4AC0);
    // 0x8019EA0C: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8019EA10: nop

    // 0x8019EA14: bc1tl       L_8019EB6C
    if (c1cs) {
        // 0x8019EA18: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8019EB6C;
    }
    goto skip_4;
    // 0x8019EA18: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_4:
    // 0x8019EA1C: jal         0x800BA5B0
    // 0x8019EA20: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    RCP_SetupDL_49(rdram, ctx);
        goto after_46;
    // 0x8019EA20: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    after_46:
    // 0x8019EA24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019EA28: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8019EA2C: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8019EA30: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8019EA34: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8019EA38: lwc1        $f18, 0x190($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X190);
    // 0x8019EA3C: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8019EA40: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x8019EA44: nop

    // 0x8019EA48: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x8019EA4C: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x8019EA50: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8019EA54: sll         $t6, $t3, 16
    ctx->r14 = S32(ctx->r11 << 16);
    // 0x8019EA58: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8019EA5C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8019EA60: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019EA64: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8019EA68: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8019EA6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8019EA70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8019EA74: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8019EA78: jal         0x80005740
    // 0x8019EA7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_47;
    // 0x8019EA7C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_47:
    // 0x8019EA80: jal         0x80005708
    // 0x8019EA84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_48;
    // 0x8019EA84: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_48:
    // 0x8019EA88: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019EA8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019EA90: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019EA94: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8019EA98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019EA9C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019EAA0: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019EAA4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019EAA8: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8019EAAC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019EAB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019EAB4: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8019EAB8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8019EABC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8019EAC0: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019EAC4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8019EAC8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019EACC: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8019EAD0: jal         0x80005B00
    // 0x8019EAD4: nop

    Matrix_Translate(rdram, ctx);
        goto after_49;
    // 0x8019EAD4: nop

    after_49:
    // 0x8019EAD8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019EADC: lwc1        $f0, 0x77C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X77C0);
    // 0x8019EAE0: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8019EAE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019EAE8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019EAEC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019EAF0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8019EAF4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8019EAF8: jal         0x80005C34
    // 0x8019EAFC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_50;
    // 0x8019EAFC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_50:
    // 0x8019EB00: jal         0x80006EB8
    // 0x8019EB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_51;
    // 0x8019EB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_51:
    // 0x8019EB08: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019EB0C: lui         $a1, 0xC238
    ctx->r5 = S32(0XC238 << 16);
    // 0x8019EB10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019EB14: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8019EB18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019EB1C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8019EB20: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8019EB24: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019EB28: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8019EB2C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019EB30: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019EB34: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8019EB38: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019EB3C: jal         0x80005B00
    // 0x8019EB40: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    Matrix_Translate(rdram, ctx);
        goto after_52;
    // 0x8019EB40: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_52:
    // 0x8019EB44: jal         0x80006EB8
    // 0x8019EB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_53;
    // 0x8019EB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x8019EB4C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019EB50: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8019EB54: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019EB58: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019EB5C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019EB60: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8019EB64: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8019EB68:
    // 0x8019EB68: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8019EB6C:
    // 0x8019EB6C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019EB70: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8019EB74: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8019EB78: jr          $ra
    // 0x8019EB7C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8019EB7C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Andross_AndJamesTrigger_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189470: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80189474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80189478: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018947C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80189480: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80189484: lbu         $t6, 0x7AB0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7AB0);
    // 0x80189488: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018948C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80189490: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80189494: beq         $t6, $at, L_80189538
    if (ctx->r14 == ctx->r1) {
        // 0x80189498: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80189538;
    }
    // 0x80189498: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018949C: lw          $t7, 0x1C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C8);
    // 0x801894A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801894A4: bnel        $t7, $at, L_8018953C
    if (ctx->r15 != ctx->r1) {
        // 0x801894A8: lw          $t9, 0x1C8($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X1C8);
            goto L_8018953C;
    }
    goto skip_0;
    // 0x801894A8: lw          $t9, 0x1C8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C8);
    skip_0:
    // 0x801894AC: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801894B0: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801894B4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801894B8: lwc1        $f2, 0x6C00($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6C00);
    // 0x801894BC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801894C0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801894C4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801894C8: nop

    // 0x801894CC: bc1fl       L_8018953C
    if (!c1cs) {
        // 0x801894D0: lw          $t9, 0x1C8($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X1C8);
            goto L_8018953C;
    }
    goto skip_1;
    // 0x801894D0: lw          $t9, 0x1C8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C8);
    skip_1:
    // 0x801894D4: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x801894D8: lwc1        $f10, 0x138($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X138);
    // 0x801894DC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801894E0: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x801894E4: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801894E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801894EC: addiu       $a0, $a0, 0x2E18
    ctx->r4 = ADD32(ctx->r4, 0X2E18);
    // 0x801894F0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x801894F4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801894F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801894FC: nop

    // 0x80189500: bc1fl       L_8018953C
    if (!c1cs) {
        // 0x80189504: lw          $t9, 0x1C8($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X1C8);
            goto L_8018953C;
    }
    goto skip_2;
    // 0x80189504: lw          $t9, 0x1C8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C8);
    skip_2:
    // 0x80189508: sb          $t8, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = ctx->r24;
    // 0x8018950C: jal         0x800BA808
    // 0x80189510: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x80189510: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80189514: lui         $a0, 0x1014
    ctx->r4 = S32(0X1014 << 16);
    // 0x80189518: jal         0x800182F4
    // 0x8018951C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x8018951C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80189520: lui         $a0, 0x1114
    ctx->r4 = S32(0X1114 << 16);
    // 0x80189524: jal         0x800182F4
    // 0x80189528: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x80189528: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_2:
    // 0x8018952C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80189530: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80189534: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80189538:
    // 0x80189538: lw          $t9, 0x1C8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C8);
L_8018953C:
    // 0x8018953C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80189540: bnel        $t9, $at, L_80189714
    if (ctx->r25 != ctx->r1) {
        // 0x80189544: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80189714;
    }
    goto skip_3;
    // 0x80189544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80189548: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8018954C: lwc1        $f18, 0x74($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80189550: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80189554: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80189558: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8018955C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80189560: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80189564: nop

    // 0x80189568: bc1fl       L_80189714
    if (!c1cs) {
        // 0x8018956C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80189714;
    }
    goto skip_4;
    // 0x8018956C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80189570: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80189574: lwc1        $f6, 0x138($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80189578: lui         $a0, 0x1140
    ctx->r4 = S32(0X1140 << 16);
    // 0x8018957C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80189580: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80189584: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80189588: nop

    // 0x8018958C: bc1fl       L_80189714
    if (!c1cs) {
        // 0x80189590: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80189714;
    }
    goto skip_5;
    // 0x80189590: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80189594: jal         0x8001A838
    // 0x80189598: ori         $a0, $a0, 0x3076
    ctx->r4 = ctx->r4 | 0X3076;
    Audio_KillSfxById(rdram, ctx);
        goto after_3;
    // 0x80189598: ori         $a0, $a0, 0x3076
    ctx->r4 = ctx->r4 | 0X3076;
    after_3:
    // 0x8018959C: jal         0x8001D400
    // 0x801895A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_4;
    // 0x801895A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x801895A4: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801895A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801895AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801895B0: addiu       $t0, $zero, 0x13
    ctx->r8 = ADD32(0, 0X13);
    // 0x801895B4: sw          $t0, -0x7DCC($at)
    MEM_W(-0X7DCC, ctx->r1) = ctx->r8;
    // 0x801895B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801895BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801895C0: sw          $t1, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r9;
    // 0x801895C4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801895C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x801895CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801895D0: sb          $t4, 0x2F68($at)
    MEM_B(0X2F68, ctx->r1) = ctx->r12;
    // 0x801895D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801895D8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x801895DC: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x801895E0: addiu       $v1, $v1, 0x7D20
    ctx->r3 = ADD32(ctx->r3, 0X7D20);
    // 0x801895E4: sw          $t2, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r10;
    // 0x801895E8: sw          $t3, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = ctx->r11;
    // 0x801895EC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801895F0: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801895F4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801895F8: addiu       $a0, $a0, 0x7A98
    ctx->r4 = ADD32(ctx->r4, 0X7A98);
    // 0x801895FC: swc1        $f8, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f8.u32l;
    // 0x80189600: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80189604: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189608: sb          $t4, 0x7AB0($at)
    MEM_B(0X7AB0, ctx->r1) = ctx->r12;
    // 0x8018960C: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80189610: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189614: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189618: swc1        $f2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f2.u32l;
    // 0x8018961C: swc1        $f2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f2.u32l;
    // 0x80189620: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x80189624: swc1        $f0, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f0.u32l;
    // 0x80189628: lui         $at, 0x441B
    ctx->r1 = S32(0X441B << 16);
    // 0x8018962C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189630: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189634: swc1        $f16, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f16.u32l;
    // 0x80189638: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018963C: swc1        $f0, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f0.u32l;
    // 0x80189640: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80189644: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189648: sw          $zero, 0x234($s0)
    MEM_W(0X234, ctx->r16) = 0;
    // 0x8018964C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189650: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x80189654: jal         0x800A6148
    // 0x80189658: swc1        $f18, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f18.u32l;
    Play_ClearObjectData(rdram, ctx);
        goto after_5;
    // 0x80189658: swc1        $f18, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f18.u32l;
    after_5:
    // 0x8018965C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80189660: addiu       $v0, $v0, -0x7D58
    ctx->r2 = ADD32(ctx->r2, -0X7D58);
    // 0x80189664: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80189668: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
L_8018966C:
    // 0x8018966C: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80189670: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80189674: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x80189678: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8018967C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80189680: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    // 0x80189684: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80189688: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8018968C: sb          $zero, 0xB0($t0)
    MEM_B(0XB0, ctx->r8) = 0;
    // 0x80189690: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80189694: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x80189698: addiu       $v1, $v1, 0x160
    ctx->r3 = ADD32(ctx->r3, 0X160);
    // 0x8018969C: bne         $v1, $a0, L_8018966C
    if (ctx->r3 != ctx->r4) {
        // 0x801896A0: sb          $zero, 0x108($t2)
        MEM_B(0X108, ctx->r10) = 0;
            goto L_8018966C;
    }
    // 0x801896A0: sb          $zero, 0x108($t2)
    MEM_B(0X108, ctx->r10) = 0;
    // 0x801896A4: jal         0x80193710
    // 0x801896A8: nop

    Andross_LoadLevelObjects(rdram, ctx);
        goto after_6;
    // 0x801896A8: nop

    after_6:
    // 0x801896AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801896B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801896B4: jal         0x800A594C
    // 0x801896B8: sw          $t3, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = ctx->r11;
    Play_InitEnvironment(rdram, ctx);
        goto after_7;
    // 0x801896B8: sw          $t3, 0x782C($at)
    MEM_W(0X782C, ctx->r1) = ctx->r11;
    after_7:
    // 0x801896BC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801896C0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801896C4: addiu       $v1, $v1, -0x7CB0
    ctx->r3 = ADD32(ctx->r3, -0X7CB0);
    // 0x801896C8: addiu       $v0, $v0, -0x7CAC
    ctx->r2 = ADD32(ctx->r2, -0X7CAC);
    // 0x801896CC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801896D0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801896D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801896D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801896DC: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x801896E0: addiu       $a0, $a0, -0x7CA8
    ctx->r4 = ADD32(ctx->r4, -0X7CA8);
    // 0x801896E4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801896E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x801896EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801896F0: sw          $t6, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r14;
    // 0x801896F4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801896F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801896FC: sw          $t8, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r24;
    // 0x80189700: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189704: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x80189708: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018970C: swc1        $f4, 0x7A4C($at)
    MEM_W(0X7A4C, ctx->r1) = ctx->f4.u32l;
    // 0x80189710: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80189714:
    // 0x80189714: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80189718: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018971C: jr          $ra
    // 0x80189720: nop

    return;
    // 0x80189720: nop

;}
RECOMP_FUNC void SectorY_80198238(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198238: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8019823C: jr          $ra
    // 0x80198240: nop

    return;
    // 0x80198240: nop

;}
RECOMP_FUNC void Andross_AndSuction_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CAD4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8018CAD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018CADC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018CAE0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018CAE4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018CAE8: lwc1        $f6, 0x60($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8018CAEC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018CAF0: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x8018CAF4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018CAF8: lwc1        $f4, 0x64($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8018CAFC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018CB00: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018CB04: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8018CB08: beq         $v0, $zero, L_8018CB2C
    if (ctx->r2 == 0) {
        // 0x8018CB0C: swc1        $f6, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
            goto L_8018CB2C;
    }
    // 0x8018CB0C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018CB10: beq         $v0, $at, L_8018CDD0
    if (ctx->r2 == ctx->r1) {
        // 0x8018CB14: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8018CDD0;
    }
    // 0x8018CB14: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018CB18: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018CB1C: beq         $v0, $at, L_8018CEF0
    if (ctx->r2 == ctx->r1) {
        // 0x8018CB20: addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
            goto L_8018CEF0;
    }
    // 0x8018CB20: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8018CB24: b           L_8018CF88
    // 0x8018CB28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018CF88;
    // 0x8018CB28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018CB2C:
    // 0x8018CB2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018CB30: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8018CB34: lh          $t6, 0x4E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4E);
    // 0x8018CB38: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8018CB3C: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8018CB40: bne         $t6, $at, L_8018CD0C
    if (ctx->r14 != ctx->r1) {
        // 0x8018CB44: lui         $a2, 0x3D4C
        ctx->r6 = S32(0X3D4C << 16);
            goto L_8018CD0C;
    }
    // 0x8018CB44: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018CB48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018CB4C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018CB50: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018CB54: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8018CB58: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x8018CB5C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018CB60: jal         0x8009BC2C
    // 0x8018CB64: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8018CB64: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8018CB68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CB6C: lwc1        $f10, -0xEE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEE8);
    // 0x8018CB70: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018CB74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CB78: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018CB7C: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x8018CB80: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018CB84: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x8018CB88: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8018CB8C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018CB90: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018CB94: jal         0x8009BC2C
    // 0x8018CB98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8018CB98: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8018CB9C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018CBA0: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8018CBA4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018CBA8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018CBAC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CBB0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8018CBB4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018CBB8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018CBBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018CBC0: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8018CBC4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8018CBC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CBCC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018CBD0: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x8018CBD4: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018CBD8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018CBDC: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x8018CBE0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018CBE4: sub.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8018CBE8: sub.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8018CBEC: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    // 0x8018CBF0: jal         0x80005100
    // 0x8018CBF4: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x8018CBF4: swc1        $f14, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8018CBF8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018CBFC: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018CC00: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8018CC04: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018CC08: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018CC0C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8018CC10: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018CC14: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018CC18: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018CC1C: jal         0x80005100
    // 0x8018CC20: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x8018CC20: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_3:
    // 0x8018CC24: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8018CC28: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CC2C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x8018CC30: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CC34: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8018CC38: jal         0x80005E90
    // 0x8018CC3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8018CC3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8018CC40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CC44: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CC48: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8018CC4C: jal         0x80005D44
    // 0x8018CC50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8018CC50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8018CC54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018CC58: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018CC5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CC60: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CC64: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018CC68: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x8018CC6C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8018CC70: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x8018CC74: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x8018CC78: jal         0x80006970
    // 0x8018CC7C: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8018CC7C: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8018CC80: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8018CC84: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018CC88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018CC8C: swc1        $f6, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f6.u32l;
    // 0x8018CC90: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8018CC94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CC98: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018CC9C: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8018CCA0: lwc1        $f4, 0x7D08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x8018CCA4: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8018CCA8: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8018CCAC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018CCB0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018CCB4: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    // 0x8018CCB8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018CCBC: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018CCC0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018CCC4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8018CCC8: nop

    // 0x8018CCCC: bc1f        L_8018CDC8
    if (!c1cs) {
        // 0x8018CCD0: nop
    
            goto L_8018CDC8;
    }
    // 0x8018CCD0: nop

    // 0x8018CCD4: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8018CCD8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018CCDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018CCE0: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8018CCE4: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8018CCE8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018CCEC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8018CCF0: nop

    // 0x8018CCF4: bc1f        L_8018CDC8
    if (!c1cs) {
        // 0x8018CCF8: nop
    
            goto L_8018CDC8;
    }
    // 0x8018CCF8: nop

    // 0x8018CCFC: jal         0x80060FBC
    // 0x8018CD00: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x8018CD00: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_7:
    // 0x8018CD04: b           L_8018CDC8
    // 0x8018CD08: nop

        goto L_8018CDC8;
    // 0x8018CD08: nop

L_8018CD0C:
    // 0x8018CD0C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018CD10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018CD14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CD18: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018CD1C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018CD20: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x8018CD24: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018CD28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018CD2C: jal         0x8009BC2C
    // 0x8018CD30: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8018CD30: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8018CD34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018CD38: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018CD3C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018CD40: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018CD44: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018CD48: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8018CD4C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8018CD50: jal         0x8009BC2C
    // 0x8018CD54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8018CD54: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_9:
    // 0x8018CD58: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018CD5C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018CD60: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018CD64: addiu       $a0, $s0, 0x5C
    ctx->r4 = ADD32(ctx->r16, 0X5C);
    // 0x8018CD68: lui         $a1, 0x428C
    ctx->r5 = S32(0X428C << 16);
    // 0x8018CD6C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018CD70: jal         0x8009BC2C
    // 0x8018CD74: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8018CD74: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_10:
    // 0x8018CD78: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018CD7C: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8018CD80: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018CD84: jal         0x8007A774
    // 0x8018CD88: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_11;
    // 0x8018CD88: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_11:
    // 0x8018CD8C: lh          $t7, 0x44($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X44);
    // 0x8018CD90: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018CD94: beq         $t7, $zero, L_8018CDC8
    if (ctx->r15 == 0) {
        // 0x8018CD98: nop
    
            goto L_8018CDC8;
    }
    // 0x8018CD98: nop

    // 0x8018CD9C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018CDA0: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018CDA4: jal         0x8007D0E0
    // 0x8018CDA8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_12;
    // 0x8018CDA8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_12:
    // 0x8018CDAC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8018CDB0: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8018CDB4: jal         0x8007A6F0
    // 0x8018CDB8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_13;
    // 0x8018CDB8: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_13:
    // 0x8018CDBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018CDC0: jal         0x80060FBC
    // 0x8018CDC4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x8018CDC4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_14:
L_8018CDC8:
    // 0x8018CDC8: b           L_8018CF84
    // 0x8018CDCC: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
        goto L_8018CF84;
    // 0x8018CDCC: sh          $zero, 0x44($s0)
    MEM_H(0X44, ctx->r16) = 0;
L_8018CDD0:
    // 0x8018CDD0: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8018CDD4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018CDD8: jal         0x8007A774
    // 0x8018CDDC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_15;
    // 0x8018CDDC: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_15:
    // 0x8018CDE0: lh          $t8, 0x44($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X44);
    // 0x8018CDE4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018CDE8: beql        $t8, $zero, L_8018CF88
    if (ctx->r24 == 0) {
        // 0x8018CDEC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8018CF88;
    }
    goto skip_0;
    // 0x8018CDEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8018CDF0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018CDF4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018CDF8: jal         0x8007D0E0
    // 0x8018CDFC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_16;
    // 0x8018CDFC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    after_16:
    // 0x8018CE00: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8018CE04: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8018CE08: jal         0x8007A6F0
    // 0x8018CE0C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_17;
    // 0x8018CE0C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_17:
    // 0x8018CE10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018CE14: jal         0x80060FBC
    // 0x8018CE18: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_18;
    // 0x8018CE18: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_18:
    // 0x8018CE1C: jal         0x80004EB0
    // 0x8018CE20: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x8018CE20: nop

    after_19:
    // 0x8018CE24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CE28: lwc1        $f10, 0x6CF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6CF8);
    // 0x8018CE2C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018CE30: addiu       $a2, $a2, 0x37E0
    ctx->r6 = ADD32(ctx->r6, 0X37E0);
    // 0x8018CE34: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8018CE38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018CE3C: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x8018CE40: bc1fl       L_8018CF88
    if (!c1cs) {
        // 0x8018CE44: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8018CF88;
    }
    goto skip_1;
    // 0x8018CE44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
L_8018CE48:
    // 0x8018CE48: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x8018CE4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018CE50: bne         $t9, $zero, L_8018CEE0
    if (ctx->r25 != 0) {
        // 0x8018CE54: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8018CEE0;
    }
    // 0x8018CE54: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8018CE58: jal         0x80061444
    // 0x8018CE5C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    Item_Initialize(rdram, ctx);
        goto after_20;
    // 0x8018CE5C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_20:
    // 0x8018CE60: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8018CE64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018CE68: jal         0x80004EB0
    // 0x8018CE6C: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x8018CE6C: sb          $t0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r8;
    after_21:
    // 0x8018CE70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018CE74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CE78: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8018CE7C: addiu       $t1, $zero, 0x144
    ctx->r9 = ADD32(0, 0X144);
    // 0x8018CE80: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8018CE84: addiu       $t2, $zero, 0x147
    ctx->r10 = ADD32(0, 0X147);
    // 0x8018CE88: bc1fl       L_8018CE9C
    if (!c1cs) {
        // 0x8018CE8C: sh          $t2, 0x2($a2)
        MEM_H(0X2, ctx->r6) = ctx->r10;
            goto L_8018CE9C;
    }
    goto skip_2;
    // 0x8018CE8C: sh          $t2, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r10;
    skip_2:
    // 0x8018CE90: b           L_8018CE9C
    // 0x8018CE94: sh          $t1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r9;
        goto L_8018CE9C;
    // 0x8018CE94: sh          $t1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r9;
    // 0x8018CE98: sh          $t2, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r10;
L_8018CE9C:
    // 0x8018CE9C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018CEA0: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x8018CEA4: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x8018CEA8: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x8018CEAC: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018CEB0: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8018CEB4: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // 0x8018CEB8: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018CEBC: sh          $t3, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r11;
    // 0x8018CEC0: swc1        $f10, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f10.u32l;
    // 0x8018CEC4: jal         0x800612B8
    // 0x8018CEC8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    Object_SetInfo(rdram, ctx);
        goto after_22;
    // 0x8018CEC8: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_22:
    // 0x8018CECC: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018CED0: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8018CED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018CED8: b           L_8018CF84
    // 0x8018CEDC: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
        goto L_8018CF84;
    // 0x8018CEDC: swc1        $f6, 0x50($a2)
    MEM_W(0X50, ctx->r6) = ctx->f6.u32l;
L_8018CEE0:
    // 0x8018CEE0: bne         $v0, $v1, L_8018CE48
    if (ctx->r2 != ctx->r3) {
        // 0x8018CEE4: addiu       $a2, $a2, 0x6C
        ctx->r6 = ADD32(ctx->r6, 0X6C);
            goto L_8018CE48;
    }
    // 0x8018CEE4: addiu       $a2, $a2, 0x6C
    ctx->r6 = ADD32(ctx->r6, 0X6C);
    // 0x8018CEE8: b           L_8018CF88
    // 0x8018CEEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018CF88;
    // 0x8018CEEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018CEF0:
    // 0x8018CEF0: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018CEF4: lwc1        $f8, 0x68($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8018CEF8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018CEFC: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8018CF00: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8018CF04: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018CF08: lui         $a3, 0x3E99
    ctx->r7 = S32(0X3E99 << 16);
    // 0x8018CF0C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8018CF10: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8018CF14: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018CF18: jal         0x8009BC2C
    // 0x8018CF1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x8018CF1C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_23:
    // 0x8018CF20: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018CF24: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018CF28: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018CF2C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018CF30: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8018CF34: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8018CF38: jal         0x8009BC2C
    // 0x8018CF3C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x8018CF3C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_24:
    // 0x8018CF40: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018CF44: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018CF48: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018CF4C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018CF50: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8018CF54: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8018CF58: jal         0x8009BC2C
    // 0x8018CF5C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_25;
    // 0x8018CF5C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_25:
    // 0x8018CF60: lh          $t4, 0x44($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X44);
    // 0x8018CF64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018CF68: addiu       $t5, $t4, -0xA
    ctx->r13 = ADD32(ctx->r12, -0XA);
    // 0x8018CF6C: sh          $t5, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r13;
    // 0x8018CF70: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x8018CF74: bgezl       $t6, L_8018CF88
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018CF78: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8018CF88;
    }
    goto skip_3;
    // 0x8018CF78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8018CF7C: jal         0x80060FBC
    // 0x8018CF80: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_26;
    // 0x8018CF80: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_26:
L_8018CF84:
    // 0x8018CF84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018CF88:
    // 0x8018CF88: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018CF8C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8018CF90: jr          $ra
    // 0x8018CF94: nop

    return;
    // 0x8018CF94: nop

;}
RECOMP_FUNC void SectorY_SyRobot_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A3BD4: addiu       $sp, $sp, -0x1E8
    ctx->r29 = ADD32(ctx->r29, -0X1E8);
    // 0x801A3BD8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801A3BDC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801A3BE0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A3BE4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801A3BE8: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801A3BEC: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x801A3BF0: lh          $t7, 0xB4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XB4);
    // 0x801A3BF4: lw          $v0, 0x98($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X98);
    // 0x801A3BF8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801A3BFC: addiu       $t8, $t7, -0x30
    ctx->r24 = ADD32(ctx->r15, -0X30);
    // 0x801A3C00: sw          $t8, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r24;
    // 0x801A3C04: beq         $v0, $zero, L_801A3C14
    if (ctx->r2 == 0) {
        // 0x801A3C08: sb          $t9, 0x20($s1)
        MEM_B(0X20, ctx->r17) = ctx->r25;
            goto L_801A3C14;
    }
    // 0x801A3C08: sb          $t9, 0x20($s1)
    MEM_B(0X20, ctx->r17) = ctx->r25;
    // 0x801A3C0C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x801A3C10: sw          $t0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->r8;
L_801A3C14:
    // 0x801A3C14: lh          $v0, 0x48($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X48);
    // 0x801A3C18: beql        $v0, $zero, L_801A3D68
    if (ctx->r2 == 0) {
        // 0x801A3C1C: lh          $v1, 0x46($s1)
        ctx->r3 = MEM_H(ctx->r17, 0X46);
            goto L_801A3D68;
    }
    goto skip_0;
    // 0x801A3C1C: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
    skip_0:
    // 0x801A3C20: lh          $t1, 0x46($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X46);
    // 0x801A3C24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A3C28: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x801A3C2C: beq         $t1, $at, L_801A3D64
    if (ctx->r9 == ctx->r1) {
        // 0x801A3C30: sltiu       $at, $t2, 0xB
        ctx->r1 = ctx->r10 < 0XB ? 1 : 0;
            goto L_801A3D64;
    }
    // 0x801A3C30: sltiu       $at, $t2, 0xB
    ctx->r1 = ctx->r10 < 0XB ? 1 : 0;
    // 0x801A3C34: beq         $at, $zero, L_801A3D58
    if (ctx->r1 == 0) {
        // 0x801A3C38: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_801A3D58;
    }
    // 0x801A3C38: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801A3C3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A3C40: addu        $at, $at, $t2
    gpr jr_addend_801A3C48 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x801A3C44: lw          $t2, 0x7E24($at)
    ctx->r10 = ADD32(ctx->r1, 0X7E24);
    // 0x801A3C48: jr          $t2
    // 0x801A3C4C: nop

    switch (jr_addend_801A3C48 >> 2) {
        case 0: goto L_801A3C50; break;
        case 1: goto L_801A3C68; break;
        case 2: goto L_801A3C80; break;
        case 3: goto L_801A3C90; break;
        case 4: goto L_801A3D1C; break;
        case 5: goto L_801A3D0C; break;
        case 6: goto L_801A3D3C; break;
        case 7: goto L_801A3C9C; break;
        case 8: goto L_801A3CB8; break;
        case 9: goto L_801A3CD4; break;
        case 10: goto L_801A3CF0; break;
        default: switch_error(__func__, 0x801A3C48, 0x801A7E24);
    }
    // 0x801A3C4C: nop

L_801A3C50:
    // 0x801A3C50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A3C54: addiu       $t4, $zero, 0x32
    ctx->r12 = ADD32(0, 0X32);
    // 0x801A3C58: sh          $t3, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r11;
    // 0x801A3C5C: sh          $t4, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r12;
    // 0x801A3C60: b           L_801A3D58
    // 0x801A3C64: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
        goto L_801A3D58;
    // 0x801A3C64: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
L_801A3C68:
    // 0x801A3C68: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A3C6C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x801A3C70: sh          $t5, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r13;
    // 0x801A3C74: sh          $t6, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r14;
    // 0x801A3C78: b           L_801A3D58
    // 0x801A3C7C: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
        goto L_801A3D58;
    // 0x801A3C7C: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
L_801A3C80:
    // 0x801A3C80: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801A3C84: sh          $t7, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r15;
    // 0x801A3C88: b           L_801A3D58
    // 0x801A3C8C: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
        goto L_801A3D58;
    // 0x801A3C8C: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
L_801A3C90:
    // 0x801A3C90: sh          $zero, 0x46($s1)
    MEM_H(0X46, ctx->r17) = 0;
    // 0x801A3C94: b           L_801A3D58
    // 0x801A3C98: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
        goto L_801A3D58;
    // 0x801A3C98: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
L_801A3C9C:
    // 0x801A3C9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A3CA0: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x801A3CA4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A3CA8: sh          $t8, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r24;
    // 0x801A3CAC: sh          $t9, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r25;
    // 0x801A3CB0: b           L_801A3D58
    // 0x801A3CB4: sw          $t0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r8;
        goto L_801A3D58;
    // 0x801A3CB4: sw          $t0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r8;
L_801A3CB8:
    // 0x801A3CB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A3CBC: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x801A3CC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A3CC4: sh          $t1, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r9;
    // 0x801A3CC8: sh          $t2, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r10;
    // 0x801A3CCC: b           L_801A3D58
    // 0x801A3CD0: sw          $t3, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r11;
        goto L_801A3D58;
    // 0x801A3CD0: sw          $t3, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r11;
L_801A3CD4:
    // 0x801A3CD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A3CD8: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x801A3CDC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801A3CE0: sh          $t4, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r12;
    // 0x801A3CE4: sh          $t5, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r13;
    // 0x801A3CE8: b           L_801A3D58
    // 0x801A3CEC: sw          $t6, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r14;
        goto L_801A3D58;
    // 0x801A3CEC: sw          $t6, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r14;
L_801A3CF0:
    // 0x801A3CF0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A3CF4: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x801A3CF8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801A3CFC: sh          $t7, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r15;
    // 0x801A3D00: sh          $t8, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r24;
    // 0x801A3D04: b           L_801A3D58
    // 0x801A3D08: sw          $t9, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r25;
        goto L_801A3D58;
    // 0x801A3D08: sw          $t9, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->r25;
L_801A3D0C:
    // 0x801A3D0C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801A3D10: sh          $t0, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r8;
    // 0x801A3D14: b           L_801A3D58
    // 0x801A3D18: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
        goto L_801A3D58;
    // 0x801A3D18: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
L_801A3D1C:
    // 0x801A3D1C: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x801A3D20: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x801A3D24: addiu       $a0, $s0, -0x4888
    ctx->r4 = ADD32(ctx->r16, -0X4888);
    // 0x801A3D28: jal         0x8009ACDC
    // 0x801A3D2C: sh          $t1, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r9;
    Animation_GetFrameCount(rdram, ctx);
        goto after_0;
    // 0x801A3D2C: sh          $t1, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r9;
    after_0:
    // 0x801A3D30: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x801A3D34: b           L_801A3D58
    // 0x801A3D38: sh          $t2, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r10;
        goto L_801A3D58;
    // 0x801A3D38: sh          $t2, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r10;
L_801A3D3C:
    // 0x801A3D3C: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x801A3D40: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x801A3D44: addiu       $a0, $s0, -0x4888
    ctx->r4 = ADD32(ctx->r16, -0X4888);
    // 0x801A3D48: jal         0x8009ACDC
    // 0x801A3D4C: sh          $t3, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r11;
    Animation_GetFrameCount(rdram, ctx);
        goto after_1;
    // 0x801A3D4C: sh          $t3, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r11;
    after_1:
    // 0x801A3D50: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801A3D54: sh          $t4, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r12;
L_801A3D58:
    // 0x801A3D58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A3D5C: sh          $zero, 0x48($s1)
    MEM_H(0X48, ctx->r17) = 0;
    // 0x801A3D60: swc1        $f4, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f4.u32l;
L_801A3D64:
    // 0x801A3D64: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
L_801A3D68:
    // 0x801A3D68: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x801A3D6C: addiu       $s0, $s0, -0x4888
    ctx->r16 = ADD32(ctx->r16, -0X4888);
    // 0x801A3D70: sltiu       $at, $v1, 0x7
    ctx->r1 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x801A3D74: beq         $at, $zero, L_801A4338
    if (ctx->r1 == 0) {
        // 0x801A3D78: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_801A4338;
    }
    // 0x801A3D78: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x801A3D7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A3D80: addu        $at, $at, $t5
    gpr jr_addend_801A3D88 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801A3D84: lw          $t5, 0x7E50($at)
    ctx->r13 = ADD32(ctx->r1, 0X7E50);
    // 0x801A3D88: jr          $t5
    // 0x801A3D8C: nop

    switch (jr_addend_801A3D88 >> 2) {
        case 0: goto L_801A3D90; break;
        case 1: goto L_801A3E48; break;
        case 2: goto L_801A4044; break;
        case 3: goto L_801A4140; break;
        case 4: goto L_801A4088; break;
        case 5: goto L_801A40DC; break;
        case 6: goto L_801A40DC; break;
        default: switch_error(__func__, 0x801A3D88, 0x801A7E50);
    }
    // 0x801A3D8C: nop

L_801A3D90:
    // 0x801A3D90: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x801A3D94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A3D98: beq         $s0, $zero, L_801A3E18
    if (ctx->r16 == 0) {
        // 0x801A3D9C: nop
    
            goto L_801A3E18;
    }
    // 0x801A3D9C: nop

    // 0x801A3DA0: bnel        $s0, $at, L_801A3DE0
    if (ctx->r16 != ctx->r1) {
        // 0x801A3DA4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A3DE0;
    }
    goto skip_1;
    // 0x801A3DA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_1:
    // 0x801A3DA8: lui         $s0, 0x602
    ctx->r16 = S32(0X602 << 16);
    // 0x801A3DAC: addiu       $s0, $s0, 0x65B4
    ctx->r16 = ADD32(ctx->r16, 0X65B4);
    // 0x801A3DB0: jal         0x8009ACDC
    // 0x801A3DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_2;
    // 0x801A3DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801A3DB8: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801A3DBC: sh          $t6, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r14;
    // 0x801A3DC0: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A3DC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A3DC8: jal         0x8009AA20
    // 0x801A3DCC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_3;
    // 0x801A3DCC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x801A3DD0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801A3DD4: b           L_801A4338
    // 0x801A3DD8: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
        goto L_801A4338;
    // 0x801A3DD8: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
    // 0x801A3DDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801A3DE0:
    // 0x801A3DE0: bne         $s0, $at, L_801A4338
    if (ctx->r16 != ctx->r1) {
        // 0x801A3DE4: lui         $s0, 0x603
        ctx->r16 = S32(0X603 << 16);
            goto L_801A4338;
    }
    // 0x801A3DE4: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x801A3DE8: addiu       $s0, $s0, -0x4724
    ctx->r16 = ADD32(ctx->r16, -0X4724);
    // 0x801A3DEC: jal         0x8009ACDC
    // 0x801A3DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_4;
    // 0x801A3DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801A3DF4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x801A3DF8: sh          $t7, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r15;
    // 0x801A3DFC: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A3E00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A3E04: jal         0x8009AA20
    // 0x801A3E08: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_5;
    // 0x801A3E08: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_5:
    // 0x801A3E0C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801A3E10: b           L_801A4338
    // 0x801A3E14: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
        goto L_801A4338;
    // 0x801A3E14: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
L_801A3E18:
    // 0x801A3E18: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x801A3E1C: addiu       $s0, $s0, -0x314C
    ctx->r16 = ADD32(ctx->r16, -0X314C);
    // 0x801A3E20: jal         0x8009ACDC
    // 0x801A3E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_6;
    // 0x801A3E24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801A3E28: sh          $v0, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r2;
    // 0x801A3E2C: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A3E30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A3E34: jal         0x8009AA20
    // 0x801A3E38: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_7;
    // 0x801A3E38: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_7:
    // 0x801A3E3C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801A3E40: b           L_801A4338
    // 0x801A3E44: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
        goto L_801A4338;
    // 0x801A3E44: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
L_801A3E48:
    // 0x801A3E48: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x801A3E4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A3E50: beq         $s0, $zero, L_801A3EC8
    if (ctx->r16 == 0) {
        // 0x801A3E54: nop
    
            goto L_801A3EC8;
    }
    // 0x801A3E54: nop

    // 0x801A3E58: bnel        $s0, $at, L_801A3E94
    if (ctx->r16 != ctx->r1) {
        // 0x801A3E5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A3E94;
    }
    goto skip_2;
    // 0x801A3E5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_2:
    // 0x801A3E60: lui         $s0, 0x602
    ctx->r16 = S32(0X602 << 16);
    // 0x801A3E64: addiu       $s0, $s0, 0x65B4
    ctx->r16 = ADD32(ctx->r16, 0X65B4);
    // 0x801A3E68: jal         0x8009ACDC
    // 0x801A3E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_8;
    // 0x801A3E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801A3E70: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801A3E74: sh          $t8, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r24;
    // 0x801A3E78: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A3E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A3E80: jal         0x8009AA20
    // 0x801A3E84: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_9;
    // 0x801A3E84: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_9:
    // 0x801A3E88: b           L_801A3EF4
    // 0x801A3E8C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
        goto L_801A3EF4;
    // 0x801A3E8C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801A3E90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801A3E94:
    // 0x801A3E94: bne         $s0, $at, L_801A3EF4
    if (ctx->r16 != ctx->r1) {
        // 0x801A3E98: lui         $s0, 0x603
        ctx->r16 = S32(0X603 << 16);
            goto L_801A3EF4;
    }
    // 0x801A3E98: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x801A3E9C: addiu       $s0, $s0, -0x4724
    ctx->r16 = ADD32(ctx->r16, -0X4724);
    // 0x801A3EA0: jal         0x8009ACDC
    // 0x801A3EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_10;
    // 0x801A3EA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801A3EA8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801A3EAC: sh          $t9, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r25;
    // 0x801A3EB0: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A3EB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A3EB8: jal         0x8009AA20
    // 0x801A3EBC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_11;
    // 0x801A3EBC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_11:
    // 0x801A3EC0: b           L_801A3EF4
    // 0x801A3EC4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
        goto L_801A3EF4;
    // 0x801A3EC4: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_801A3EC8:
    // 0x801A3EC8: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x801A3ECC: addiu       $s0, $s0, -0x5D34
    ctx->r16 = ADD32(ctx->r16, -0X5D34);
    // 0x801A3ED0: jal         0x8009ACDC
    // 0x801A3ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_12;
    // 0x801A3ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801A3ED8: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x801A3EDC: sh          $t0, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r8;
    // 0x801A3EE0: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A3EE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A3EE8: jal         0x8009AA20
    // 0x801A3EEC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_13;
    // 0x801A3EEC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_13:
    // 0x801A3EF0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
L_801A3EF4:
    // 0x801A3EF4: lhu         $v1, 0xBE($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XBE);
    // 0x801A3EF8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801A3EFC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801A3F00: bne         $v1, $at, L_801A4024
    if (ctx->r3 != ctx->r1) {
        // 0x801A3F04: nop
    
            goto L_801A4024;
    }
    // 0x801A3F04: nop

    // 0x801A3F08: lw          $v0, 0x9C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X9C);
    // 0x801A3F0C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A3F10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A3F14: sh          $t1, 0xC4($s1)
    MEM_H(0XC4, ctx->r17) = ctx->r9;
    // 0x801A3F18: bgez        $v0, L_801A3F30
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801A3F1C: swc1        $f6, 0x160($s1)
        MEM_W(0X160, ctx->r17) = ctx->f6.u32l;
            goto L_801A3F30;
    }
    // 0x801A3F1C: swc1        $f6, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->f6.u32l;
    // 0x801A3F20: jal         0x8006F254
    // 0x801A3F24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ActorEvent_ShootForward(rdram, ctx);
        goto after_14;
    // 0x801A3F24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x801A3F28: b           L_801A4020
    // 0x801A3F2C: sh          $zero, 0x48($s1)
    MEM_H(0X48, ctx->r17) = 0;
        goto L_801A4020;
    // 0x801A3F2C: sh          $zero, 0x48($s1)
    MEM_H(0X48, ctx->r17) = 0;
L_801A3F30:
    // 0x801A3F30: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801A3F34: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x801A3F38: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801A3F3C: swc1        $f8, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->f8.u32l;
    // 0x801A3F40: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801A3F44: beq         $v0, $zero, L_801A3FB0
    if (ctx->r2 == 0) {
        // 0x801A3F48: swc1        $f10, 0x1E0($sp)
        MEM_W(0X1E0, ctx->r29) = ctx->f10.u32l;
            goto L_801A3FB0;
    }
    // 0x801A3F48: swc1        $f10, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->f10.u32l;
    // 0x801A3F4C: jal         0x80004EB0
    // 0x801A3F50: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x801A3F50: nop

    after_15:
    // 0x801A3F54: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A3F58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A3F5C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A3F60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A3F64: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801A3F68: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801A3F6C: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x801A3F70: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A3F74: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801A3F78: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801A3F7C: jal         0x80004EB0
    // 0x801A3F80: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x801A3F80: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    after_16:
    // 0x801A3F84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A3F88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A3F8C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A3F90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A3F94: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x801A3F98: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801A3F9C: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x801A3FA0: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801A3FA4: lwc1        $f8, 0x78($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801A3FA8: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801A3FAC: swc1        $f4, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f4.u32l;
L_801A3FB0:
    // 0x801A3FB0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A3FB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A3FB8: lw          $a1, 0x154($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X154);
    // 0x801A3FBC: lw          $a2, 0x158($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X158);
    // 0x801A3FC0: lw          $a3, 0x15C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X15C);
    // 0x801A3FC4: addiu       $a0, $zero, 0x162
    ctx->r4 = ADD32(0, 0X162);
    // 0x801A3FC8: jal         0x8007F11C
    // 0x801A3FCC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_17;
    // 0x801A3FCC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x801A3FD0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801A3FD4: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x801A3FD8: lwc1        $f8, 0x1E4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1E4);
    // 0x801A3FDC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801A3FE0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801A3FE4: swc1        $f8, 0x74($t2)
    MEM_W(0X74, ctx->r10) = ctx->f8.u32l;
    // 0x801A3FE8: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x801A3FEC: lwc1        $f6, 0x1E0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1E0);
    // 0x801A3FF0: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801A3FF4: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801A3FF8: addiu       $a3, $t4, 0x5D34
    ctx->r7 = ADD32(ctx->r12, 0X5D34);
    // 0x801A3FFC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x801A4000: swc1        $f6, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->f6.u32l;
    // 0x801A4004: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801A4008: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A400C: ori         $a0, $a0, 0x306B
    ctx->r4 = ctx->r4 | 0X306B;
    // 0x801A4010: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x801A4014: jal         0x80019218
    // 0x801A4018: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x801A4018: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_18:
    // 0x801A401C: sh          $zero, 0x48($s1)
    MEM_H(0X48, ctx->r17) = 0;
L_801A4020:
    // 0x801A4020: lhu         $v1, 0xBE($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XBE);
L_801A4024:
    // 0x801A4024: bne         $v1, $zero, L_801A403C
    if (ctx->r3 != 0) {
        // 0x801A4028: nop
    
            goto L_801A403C;
    }
    // 0x801A4028: nop

    // 0x801A402C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A4030: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
    // 0x801A4034: sh          $zero, 0x46($s1)
    MEM_H(0X46, ctx->r17) = 0;
    // 0x801A4038: swc1        $f4, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f4.u32l;
L_801A403C:
    // 0x801A403C: b           L_801A4338
    // 0x801A4040: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
        goto L_801A4338;
    // 0x801A4040: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
L_801A4044:
    // 0x801A4044: lui         $s0, 0x603
    ctx->r16 = S32(0X603 << 16);
    // 0x801A4048: addiu       $s0, $s0, -0x64B8
    ctx->r16 = ADD32(ctx->r16, -0X64B8);
    // 0x801A404C: jal         0x8009ACDC
    // 0x801A4050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_19;
    // 0x801A4050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x801A4054: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A4058: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801A405C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A4060: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801A4064: beq         $at, $zero, L_801A4074
    if (ctx->r1 == 0) {
        // 0x801A4068: addiu       $t7, $a1, 0x1
        ctx->r15 = ADD32(ctx->r5, 0X1);
            goto L_801A4074;
    }
    // 0x801A4068: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x801A406C: sh          $t7, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r15;
    // 0x801A4070: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
L_801A4074:
    // 0x801A4074: jal         0x8009AA20
    // 0x801A4078: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_20;
    // 0x801A4078: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_20:
    // 0x801A407C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801A4080: b           L_801A4338
    // 0x801A4084: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
        goto L_801A4338;
    // 0x801A4084: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
L_801A4088:
    // 0x801A4088: lh          $t8, 0xB6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XB6);
    // 0x801A408C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A4090: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801A4094: jal         0x8009ACDC
    // 0x801A4098: sh          $t9, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r25;
    Animation_GetFrameCount(rdram, ctx);
        goto after_21;
    // 0x801A4098: sh          $t9, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r25;
    after_21:
    // 0x801A409C: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A40A0: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x801A40A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A40A8: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x801A40AC: bne         $at, $zero, L_801A40C8
    if (ctx->r1 != 0) {
        // 0x801A40B0: nop
    
            goto L_801A40C8;
    }
    // 0x801A40B0: nop

    // 0x801A40B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A40B8: sh          $zero, 0x46($s1)
    MEM_H(0X46, ctx->r17) = 0;
    // 0x801A40BC: sw          $zero, 0x94($s1)
    MEM_W(0X94, ctx->r17) = 0;
    // 0x801A40C0: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A40C4: swc1        $f10, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f10.u32l;
L_801A40C8:
    // 0x801A40C8: jal         0x8009AA20
    // 0x801A40CC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_22;
    // 0x801A40CC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_22:
    // 0x801A40D0: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801A40D4: b           L_801A4338
    // 0x801A40D8: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
        goto L_801A4338;
    // 0x801A40D8: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
L_801A40DC:
    // 0x801A40DC: lh          $t1, 0xB6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XB6);
    // 0x801A40E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A40E4: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x801A40E8: sh          $t2, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r10;
    // 0x801A40EC: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A40F0: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x801A40F4: beq         $at, $zero, L_801A412C
    if (ctx->r1 == 0) {
        // 0x801A40F8: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_801A412C;
    }
    // 0x801A40F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A40FC: lwc1        $f8, 0x7E6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7E6C);
    // 0x801A4100: lh          $t3, 0x46($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X46);
    // 0x801A4104: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801A4108: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801A410C: bne         $t3, $at, L_801A4120
    if (ctx->r11 != ctx->r1) {
        // 0x801A4110: swc1        $f8, 0x150($s1)
        MEM_W(0X150, ctx->r17) = ctx->f8.u32l;
            goto L_801A4120;
    }
    // 0x801A4110: swc1        $f8, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f8.u32l;
    // 0x801A4114: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A4118: b           L_801A4124
    // 0x801A411C: sw          $t4, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r12;
        goto L_801A4124;
    // 0x801A411C: sw          $t4, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r12;
L_801A4120:
    // 0x801A4120: sw          $t5, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r13;
L_801A4124:
    // 0x801A4124: sh          $zero, 0x46($s1)
    MEM_H(0X46, ctx->r17) = 0;
    // 0x801A4128: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
L_801A412C:
    // 0x801A412C: jal         0x8009AA20
    // 0x801A4130: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_23;
    // 0x801A4130: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_23:
    // 0x801A4134: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801A4138: b           L_801A4338
    // 0x801A413C: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
        goto L_801A4338;
    // 0x801A413C: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
L_801A4140:
    // 0x801A4140: lh          $t6, 0xB6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XB6);
    // 0x801A4144: lui         $s0, 0x600
    ctx->r16 = S32(0X600 << 16);
    // 0x801A4148: addiu       $s0, $s0, 0x3348
    ctx->r16 = ADD32(ctx->r16, 0X3348);
    // 0x801A414C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801A4150: sh          $t7, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r15;
    // 0x801A4154: jal         0x8009ACDC
    // 0x801A4158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_24;
    // 0x801A4158: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x801A415C: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A4160: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801A4164: bnel        $at, $zero, L_801A4184
    if (ctx->r1 != 0) {
        // 0x801A4168: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801A4184;
    }
    goto skip_3;
    // 0x801A4168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x801A416C: jal         0x8009ACDC
    // 0x801A4170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Animation_GetFrameCount(rdram, ctx);
        goto after_25;
    // 0x801A4170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x801A4174: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801A4178: sh          $t8, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = ctx->r24;
    // 0x801A417C: lh          $a1, 0xB6($s1)
    ctx->r5 = MEM_H(ctx->r17, 0XB6);
    // 0x801A4180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A4184:
    // 0x801A4184: jal         0x8009AA20
    // 0x801A4188: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Animation_GetFrameData(rdram, ctx);
        goto after_26;
    // 0x801A4188: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_26:
    // 0x801A418C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801A4190: lhu         $v1, 0xBE($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XBE);
    // 0x801A4194: andi        $t9, $v1, 0x3
    ctx->r25 = ctx->r3 & 0X3;
    // 0x801A4198: bne         $t9, $zero, L_801A420C
    if (ctx->r25 != 0) {
        // 0x801A419C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_801A420C;
    }
    // 0x801A419C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801A41A0: jal         0x80004EB0
    // 0x801A41A4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_27;
    // 0x801A41A4: nop

    after_27:
    // 0x801A41A8: jal         0x80004EB0
    // 0x801A41AC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_28;
    // 0x801A41AC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_28:
    // 0x801A41B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A41B4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A41B8: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A41BC: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801A41C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A41C4: sub.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x801A41C8: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A41CC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A41D0: sub.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801A41D4: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801A41D8: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x801A41DC: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801A41E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A41E4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801A41E8: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A41EC: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A41F0: add.s       $f14, $f4, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x801A41F4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801A41F8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801A41FC: jal         0x8007D2C8
    // 0x801A4200: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_29;
    // 0x801A4200: nop

    after_29:
    // 0x801A4204: lhu         $v1, 0xBE($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XBE);
    // 0x801A4208: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_801A420C:
    // 0x801A420C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801A4210: bne         $a0, $at, L_801A4298
    if (ctx->r4 != ctx->r1) {
        // 0x801A4214: addiu       $t0, $zero, 0xA
        ctx->r8 = ADD32(0, 0XA);
            goto L_801A4298;
    }
    // 0x801A4214: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801A4218: lwc1        $f10, 0xEC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x801A421C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A4220: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A4224: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801A4228: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x801A422C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801A4230: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801A4234: lwc1        $f8, 0xF0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x801A4238: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A423C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801A4240: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801A4244: jal         0x8007BFFC
    // 0x801A4248: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_30;
    // 0x801A4248: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_30:
    // 0x801A424C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A4250: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A4254: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801A4258: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x801A425C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A4260: jal         0x8007B344
    // 0x801A4264: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_31;
    // 0x801A4264: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    after_31:
    // 0x801A4268: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801A426C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x801A4270: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x801A4274: addiu       $a3, $t2, 0x5D34
    ctx->r7 = ADD32(ctx->r10, 0X5D34);
    // 0x801A4278: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801A427C: ori         $a0, $a0, 0xA060
    ctx->r4 = ctx->r4 | 0XA060;
    // 0x801A4280: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A4284: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801A4288: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x801A428C: jal         0x80019218
    // 0x801A4290: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_32;
    // 0x801A4290: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_32:
    // 0x801A4294: lhu         $v1, 0xBE($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0XBE);
L_801A4298:
    // 0x801A4298: bne         $v1, $zero, L_801A4334
    if (ctx->r3 != 0) {
        // 0x801A429C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801A4334;
    }
    // 0x801A429C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A42A0: jal         0x80060FBC
    // 0x801A42A4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_33;
    // 0x801A42A4: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_33:
    // 0x801A42A8: jal         0x80066254
    // 0x801A42AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_34;
    // 0x801A42AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_34:
    // 0x801A42B0: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
L_801A42B4:
    // 0x801A42B4: jal         0x80004EB0
    // 0x801A42B8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_35;
    // 0x801A42B8: nop

    after_35:
    // 0x801A42BC: jal         0x80004EB0
    // 0x801A42C0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_36;
    // 0x801A42C0: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_36:
    // 0x801A42C4: jal         0x80004EB0
    // 0x801A42C8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_37;
    // 0x801A42C8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_37:
    // 0x801A42CC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A42D0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A42D4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A42D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A42DC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801A42E0: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A42E4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A42E8: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801A42EC: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A42F0: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801A42F4: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801A42F8: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801A42FC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801A4300: mul.s       $f10, $f4, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801A4304: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801A4308: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x801A430C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801A4310: lwc1        $f4, 0xF0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x801A4314: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801A4318: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801A431C: jal         0x801A3B50
    // 0x801A4320: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    SectorY_ActorDebris_Spawn(rdram, ctx);
        goto after_38;
    // 0x801A4320: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_38:
    // 0x801A4324: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A4328: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x801A432C: bne         $s0, $at, L_801A42B4
    if (ctx->r16 != ctx->r1) {
        // 0x801A4330: nop
    
            goto L_801A42B4;
    }
    // 0x801A4330: nop

L_801A4334:
    // 0x801A4334: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
L_801A4338:
    // 0x801A4338: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A433C: beq         $v1, $at, L_801A434C
    if (ctx->r3 == ctx->r1) {
        // 0x801A4340: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A434C;
    }
    // 0x801A4340: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A4344: bnel        $v1, $at, L_801A4600
    if (ctx->r3 != ctx->r1) {
        // 0x801A4348: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_801A4600;
    }
    goto skip_4;
    // 0x801A4348: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_4:
L_801A434C:
    // 0x801A434C: lwc1        $f8, 0x2F0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2F0);
    // 0x801A4350: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A4354: lwc1        $f4, 0x7E70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E70);
    // 0x801A4358: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x801A435C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4360: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A4364: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A436C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A4370: jal         0x80005FE0
    // 0x801A4374: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_39;
    // 0x801A4374: nop

    after_39:
    // 0x801A4378: lwc1        $f8, 0x2E8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2E8);
    // 0x801A437C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A4380: lwc1        $f4, 0x7E74($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E74);
    // 0x801A4384: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x801A4388: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A438C: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A4390: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4394: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A4398: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A439C: jal         0x80005D44
    // 0x801A43A0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_40;
    // 0x801A43A0: nop

    after_40:
    // 0x801A43A4: lwc1        $f8, 0x2EC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2EC);
    // 0x801A43A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A43AC: lwc1        $f4, 0x7E78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E78);
    // 0x801A43B0: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x801A43B4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A43B8: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A43BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A43C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A43C4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A43C8: jal         0x80005E90
    // 0x801A43CC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_41;
    // 0x801A43CC: nop

    after_41:
    // 0x801A43D0: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x801A43D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A43D8: lwc1        $f4, 0x7E7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E7C);
    // 0x801A43DC: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x801A43E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A43E4: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A43E8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A43EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A43F0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A43F4: jal         0x80005FE0
    // 0x801A43F8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_42;
    // 0x801A43F8: nop

    after_42:
    // 0x801A43FC: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x801A4400: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A4404: lwc1        $f4, 0x7E80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E80);
    // 0x801A4408: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x801A440C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4410: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A4414: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4418: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A441C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A4420: jal         0x80005D44
    // 0x801A4424: nop

    Matrix_RotateX(rdram, ctx);
        goto after_43;
    // 0x801A4424: nop

    after_43:
    // 0x801A4428: lw          $t4, 0x94($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X94);
    // 0x801A442C: bne         $t4, $zero, L_801A4460
    if (ctx->r12 != 0) {
        // 0x801A4430: nop
    
            goto L_801A4460;
    }
    // 0x801A4430: nop

    // 0x801A4434: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x801A4438: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A443C: lwc1        $f4, 0x7E84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E84);
    // 0x801A4440: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x801A4444: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4448: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A444C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4450: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A4454: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A4458: jal         0x80005E90
    // 0x801A445C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_44;
    // 0x801A445C: nop

    after_44:
L_801A4460:
    // 0x801A4460: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801A4464: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x801A4468: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801A446C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4470: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801A4474: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4478: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801A447C: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801A4480: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x801A4484: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x801A4488: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801A448C: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801A4490: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801A4494: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x801A4498: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A449C: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801A44A0: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x801A44A4: jal         0x80006A20
    // 0x801A44A8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_45;
    // 0x801A44A8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    after_45:
    // 0x801A44AC: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801A44B0: jal         0x80005100
    // 0x801A44B4: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    Math_Atan2F(rdram, ctx);
        goto after_46;
    // 0x801A44B4: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    after_46:
    // 0x801A44B8: jal         0x8009F768
    // 0x801A44BC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_47;
    // 0x801A44BC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_47:
    // 0x801A44C0: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801A44C4: lwc1        $f18, 0x58($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801A44C8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x801A44CC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801A44D0: swc1        $f16, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->f16.u32l;
    // 0x801A44D4: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801A44D8: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x801A44DC: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801A44E0: jal         0x80005100
    // 0x801A44E4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_48;
    // 0x801A44E4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_48:
    // 0x801A44E8: jal         0x8009F768
    // 0x801A44EC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_49;
    // 0x801A44EC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_49:
    // 0x801A44F0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801A44F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A44F8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A44FC: lwc1        $f16, 0x1D4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x801A4500: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801A4504: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x801A4508: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A450C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A4510: bc1f        L_801A4534
    if (!c1cs) {
        // 0x801A4514: addiu       $a0, $s1, 0x14
        ctx->r4 = ADD32(ctx->r17, 0X14);
            goto L_801A4534;
    }
    // 0x801A4514: addiu       $a0, $s1, 0x14
    ctx->r4 = ADD32(ctx->r17, 0X14);
    // 0x801A4518: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801A451C: nop

    // 0x801A4520: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801A4524: nop

    // 0x801A4528: bc1fl       L_801A4538
    if (!c1cs) {
        // 0x801A452C: lui         $at, 0x4387
        ctx->r1 = S32(0X4387 << 16);
            goto L_801A4538;
    }
    goto skip_5;
    // 0x801A452C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    skip_5:
    // 0x801A4530: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_801A4534:
    // 0x801A4534: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
L_801A4538:
    // 0x801A4538: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A453C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A4540: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801A4544: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801A4548: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801A454C: bc1fl       L_801A456C
    if (!c1cs) {
        // 0x801A4550: lw          $t5, 0x94($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X94);
            goto L_801A456C;
    }
    goto skip_6;
    // 0x801A4550: lw          $t5, 0x94($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X94);
    skip_6:
    // 0x801A4554: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x801A4558: nop

    // 0x801A455C: bc1fl       L_801A456C
    if (!c1cs) {
        // 0x801A4560: lw          $t5, 0x94($s1)
        ctx->r13 = MEM_W(ctx->r17, 0X94);
            goto L_801A456C;
    }
    goto skip_7;
    // 0x801A4560: lw          $t5, 0x94($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X94);
    skip_7:
    // 0x801A4564: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x801A4568: lw          $t5, 0x94($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X94);
L_801A456C:
    // 0x801A456C: beql        $t5, $zero, L_801A45AC
    if (ctx->r13 == 0) {
        // 0x801A4570: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_801A45AC;
    }
    goto skip_8;
    // 0x801A4570: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_8:
    // 0x801A4574: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A4578: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A457C: swc1        $f12, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->f12.u32l;
    // 0x801A4580: swc1        $f16, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->f16.u32l;
    // 0x801A4584: jal         0x8009BD38
    // 0x801A4588: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_50;
    // 0x801A4588: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_50:
    // 0x801A458C: lwc1        $f16, 0x1D4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x801A4590: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x801A4594: lwc1        $f12, 0x1D8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x801A4598: sub.s       $f2, $f16, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x801A459C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801A45A0: b           L_801A4610
    // 0x801A45A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_801A4610;
    // 0x801A45A4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A45A8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_801A45AC:
    // 0x801A45AC: nop

    // 0x801A45B0: bc1fl       L_801A45D0
    if (!c1cs) {
        // 0x801A45B4: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_801A45D0;
    }
    goto skip_9;
    // 0x801A45B4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_9:
    // 0x801A45B8: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x801A45BC: nop

    // 0x801A45C0: bc1fl       L_801A45D0
    if (!c1cs) {
        // 0x801A45C4: c.lt.s      $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
            goto L_801A45D0;
    }
    goto skip_10;
    // 0x801A45C4: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    skip_10:
    // 0x801A45C8: mov.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    ctx->f16.fl = ctx->f2.fl;
    // 0x801A45CC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
L_801A45D0:
    // 0x801A45D0: nop

    // 0x801A45D4: bc1fl       L_801A45F4
    if (!c1cs) {
        // 0x801A45D8: lwc1        $f6, 0x168($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X168);
            goto L_801A45F4;
    }
    goto skip_11;
    // 0x801A45D8: lwc1        $f6, 0x168($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X168);
    skip_11:
    // 0x801A45DC: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x801A45E0: nop

    // 0x801A45E4: bc1fl       L_801A45F4
    if (!c1cs) {
        // 0x801A45E8: lwc1        $f6, 0x168($s1)
        ctx->f6.u32l = MEM_W(ctx->r17, 0X168);
            goto L_801A45F4;
    }
    goto skip_12;
    // 0x801A45E8: lwc1        $f6, 0x168($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X168);
    skip_12:
    // 0x801A45EC: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x801A45F0: lwc1        $f6, 0x168($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X168);
L_801A45F4:
    // 0x801A45F4: b           L_801A460C
    // 0x801A45F8: sub.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f6.fl;
        goto L_801A460C;
    // 0x801A45F8: sub.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801A45FC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_801A4600:
    // 0x801A4600: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801A4604: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A4608: nop

L_801A460C:
    // 0x801A460C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_801A4610:
    // 0x801A4610: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A4614: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A4618: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A461C: addiu       $a0, $s1, 0x168
    ctx->r4 = ADD32(ctx->r17, 0X168);
    // 0x801A4620: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801A4624: swc1        $f2, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->f2.u32l;
    // 0x801A4628: swc1        $f12, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->f12.u32l;
    // 0x801A462C: jal         0x8009BD38
    // 0x801A4630: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_51;
    // 0x801A4630: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_51:
    // 0x801A4634: lwc1        $f12, 0x1D8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x801A4638: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A463C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A4640: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801A4644: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A4648: addiu       $a0, $s1, 0x164
    ctx->r4 = ADD32(ctx->r17, 0X164);
    // 0x801A464C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801A4650: jal         0x8009BD38
    // 0x801A4654: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_52;
    // 0x801A4654: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_52:
    // 0x801A4658: lwc1        $f2, 0x1D0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1D0);
    // 0x801A465C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A4660: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801A4664: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A4668: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x801A466C: lwc1        $f12, 0x1D8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x801A4670: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A4674: addiu       $a0, $s1, 0x184
    ctx->r4 = ADD32(ctx->r17, 0X184);
    // 0x801A4678: bc1f        L_801A4690
    if (!c1cs) {
        // 0x801A467C: lui         $a3, 0x40A0
        ctx->r7 = S32(0X40A0 << 16);
            goto L_801A4690;
    }
    // 0x801A467C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x801A4680: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801A4684: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4688: nop

    // 0x801A468C: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_801A4690:
    // 0x801A4690: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x801A4694: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A4698: jal         0x8009BD38
    // 0x801A469C: swc1        $f12, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->f12.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_53;
    // 0x801A469C: swc1        $f12, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->f12.u32l;
    after_53:
    // 0x801A46A0: lwc1        $f12, 0x1D8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x801A46A4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A46A8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801A46AC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801A46B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A46B4: addiu       $a0, $s1, 0x188
    ctx->r4 = ADD32(ctx->r17, 0X188);
    // 0x801A46B8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x801A46BC: jal         0x8009BD38
    // 0x801A46C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_54;
    // 0x801A46C0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_54:
    // 0x801A46C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A46C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A46CC: lwc1        $f8, 0x150($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X150);
    // 0x801A46D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A46D4: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x801A46D8: addiu       $a1, $s1, 0x18C
    ctx->r5 = ADD32(ctx->r17, 0X18C);
    // 0x801A46DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A46E0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x801A46E4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A46E8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A46EC: jal         0x8009BEEC
    // 0x801A46F0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_55;
    // 0x801A46F0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_55:
    // 0x801A46F4: lh          $v1, 0x46($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X46);
    // 0x801A46F8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801A46FC: addiu       $a0, $s1, 0x150
    ctx->r4 = ADD32(ctx->r17, 0X150);
    // 0x801A4700: beq         $v1, $at, L_801A4714
    if (ctx->r3 == ctx->r1) {
        // 0x801A4704: lui         $a1, 0x3E99
        ctx->r5 = S32(0X3E99 << 16);
            goto L_801A4714;
    }
    // 0x801A4704: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801A4708: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801A470C: bne         $v1, $at, L_801A4738
    if (ctx->r3 != ctx->r1) {
        // 0x801A4710: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_801A4738;
    }
    // 0x801A4710: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
L_801A4714:
    // 0x801A4714: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A4718: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x801A471C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801A4720: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801A4724: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801A4728: jal         0x8009BC2C
    // 0x801A472C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_56;
    // 0x801A472C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_56:
    // 0x801A4730: b           L_801A475C
    // 0x801A4734: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801A475C;
    // 0x801A4734: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801A4738:
    // 0x801A4738: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A473C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801A4740: lui         $a3, 0x3C75
    ctx->r7 = S32(0X3C75 << 16);
    // 0x801A4744: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x801A4748: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801A474C: addiu       $a0, $s1, 0x150
    ctx->r4 = ADD32(ctx->r17, 0X150);
    // 0x801A4750: jal         0x8009BC2C
    // 0x801A4754: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_57;
    // 0x801A4754: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_57:
    // 0x801A4758: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801A475C:
    // 0x801A475C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801A4760: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A4764: addiu       $a0, $s1, 0x160
    ctx->r4 = ADD32(ctx->r17, 0X160);
    // 0x801A4768: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A476C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A4770: jal         0x8009BC2C
    // 0x801A4774: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_58;
    // 0x801A4774: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_58:
    // 0x801A4778: lw          $t6, 0x94($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X94);
    // 0x801A477C: addiu       $a0, $s1, 0x180
    ctx->r4 = ADD32(ctx->r17, 0X180);
    // 0x801A4780: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A4784: beq         $t6, $zero, L_801A47B4
    if (ctx->r14 == 0) {
        // 0x801A4788: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_801A47B4;
    }
    // 0x801A4788: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801A478C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A4790: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x801A4794: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801A4798: addiu       $a0, $s1, 0x180
    ctx->r4 = ADD32(ctx->r17, 0X180);
    // 0x801A479C: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x801A47A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801A47A4: jal         0x8009BC2C
    // 0x801A47A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_59;
    // 0x801A47A8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_59:
    // 0x801A47AC: b           L_801A47C8
    // 0x801A47B0: nop

        goto L_801A47C8;
    // 0x801A47B0: nop

L_801A47B4:
    // 0x801A47B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A47B8: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x801A47BC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x801A47C0: jal         0x8009BC2C
    // 0x801A47C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_60;
    // 0x801A47C4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_60:
L_801A47C8:
    // 0x801A47C8: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801A47CC: addiu       $v0, $v0, 0x405C
    ctx->r2 = ADD32(ctx->r2, 0X405C);
    // 0x801A47D0: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x801A47D4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x801A47D8: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x801A47DC: addiu       $v1, $v1, 0x1FD0
    ctx->r3 = ADD32(ctx->r3, 0X1FD0);
    // 0x801A47E0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801A47E4: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x801A47E8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x801A47EC: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x801A47F0: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    // 0x801A47F4: lh          $t5, 0x46($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X46);
    // 0x801A47F8: and         $t2, $v0, $a0
    ctx->r10 = ctx->r2 & ctx->r4;
    // 0x801A47FC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801A4800: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x801A4804: addu        $t4, $t3, $a1
    ctx->r12 = ADD32(ctx->r11, ctx->r5);
    // 0x801A4808: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A480C: bne         $t5, $at, L_801A4840
    if (ctx->r13 != ctx->r1) {
        // 0x801A4810: sw          $t4, 0x28($s1)
        MEM_W(0X28, ctx->r17) = ctx->r12;
            goto L_801A4840;
    }
    // 0x801A4810: sw          $t4, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r12;
    // 0x801A4814: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801A4818: addiu       $v0, $v0, 0x421C
    ctx->r2 = ADD32(ctx->r2, 0X421C);
    // 0x801A481C: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x801A4820: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x801A4824: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801A4828: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x801A482C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x801A4830: and         $t1, $v0, $a0
    ctx->r9 = ctx->r2 & ctx->r4;
    // 0x801A4834: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801A4838: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x801A483C: sw          $t3, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r11;
L_801A4840:
    // 0x801A4840: lw          $s0, 0x94($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X94);
    // 0x801A4844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A4848: beql        $s0, $zero, L_801A48BC
    if (ctx->r16 == 0) {
        // 0x801A484C: lh          $t0, 0x46($s1)
        ctx->r8 = MEM_H(ctx->r17, 0X46);
            goto L_801A48BC;
    }
    goto skip_13;
    // 0x801A484C: lh          $t0, 0x46($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X46);
    skip_13:
    // 0x801A4850: bne         $s0, $at, L_801A4884
    if (ctx->r16 != ctx->r1) {
        // 0x801A4854: lui         $v0, 0x603
        ctx->r2 = S32(0X603 << 16);
            goto L_801A4884;
    }
    // 0x801A4854: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801A4858: addiu       $v0, $v0, 0x4124
    ctx->r2 = ADD32(ctx->r2, 0X4124);
    // 0x801A485C: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x801A4860: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x801A4864: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801A4868: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x801A486C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801A4870: and         $t9, $v0, $a0
    ctx->r25 = ctx->r2 & ctx->r4;
    // 0x801A4874: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801A4878: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x801A487C: b           L_801A48B8
    // 0x801A4880: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
        goto L_801A48B8;
    // 0x801A4880: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
L_801A4884:
    // 0x801A4884: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A4888: bne         $s0, $at, L_801A48B8
    if (ctx->r16 != ctx->r1) {
        // 0x801A488C: lui         $v0, 0x603
        ctx->r2 = S32(0X603 << 16);
            goto L_801A48B8;
    }
    // 0x801A488C: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801A4890: addiu       $v0, $v0, 0x41A8
    ctx->r2 = ADD32(ctx->r2, 0X41A8);
    // 0x801A4894: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x801A4898: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x801A489C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801A48A0: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x801A48A4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x801A48A8: and         $t7, $v0, $a0
    ctx->r15 = ctx->r2 & ctx->r4;
    // 0x801A48AC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801A48B0: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x801A48B4: sw          $t9, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r25;
L_801A48B8:
    // 0x801A48B8: lh          $t0, 0x46($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X46);
L_801A48BC:
    // 0x801A48BC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801A48C0: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801A48C4: bne         $a2, $t0, L_801A48F0
    if (ctx->r6 != ctx->r8) {
        // 0x801A48C8: addiu       $v0, $v0, 0x40C0
        ctx->r2 = ADD32(ctx->r2, 0X40C0);
            goto L_801A48F0;
    }
    // 0x801A48C8: addiu       $v0, $v0, 0x40C0
    ctx->r2 = ADD32(ctx->r2, 0X40C0);
    // 0x801A48CC: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x801A48D0: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x801A48D4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801A48D8: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x801A48DC: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801A48E0: and         $t6, $v0, $a0
    ctx->r14 = ctx->r2 & ctx->r4;
    // 0x801A48E4: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x801A48E8: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x801A48EC: sw          $t8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r24;
L_801A48F0:
    // 0x801A48F0: lb          $v0, 0xD0($s1)
    ctx->r2 = MEM_B(ctx->r17, 0XD0);
    // 0x801A48F4: beql        $v0, $zero, L_801A4A08
    if (ctx->r2 == 0) {
        // 0x801A48F8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801A4A08;
    }
    goto skip_14;
    // 0x801A48F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
    // 0x801A48FC: lh          $t9, 0x46($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X46);
    // 0x801A4900: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A4904: beql        $t9, $at, L_801A4A08
    if (ctx->r25 == ctx->r1) {
        // 0x801A4908: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801A4A08;
    }
    goto skip_15;
    // 0x801A4908: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
    // 0x801A490C: bne         $a2, $v0, L_801A491C
    if (ctx->r6 != ctx->r2) {
        // 0x801A4910: addiu       $a1, $s1, 0x100
        ctx->r5 = ADD32(ctx->r17, 0X100);
            goto L_801A491C;
    }
    // 0x801A4910: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x801A4914: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A4918: sh          $t0, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = ctx->r8;
L_801A491C:
    // 0x801A491C: lh          $t1, 0xD2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XD2);
    // 0x801A4920: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801A4924: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x801A4928: bne         $t1, $zero, L_801A4968
    if (ctx->r9 != 0) {
        // 0x801A492C: ori         $a0, $a0, 0x300E
        ctx->r4 = ctx->r4 | 0X300E;
            goto L_801A4968;
    }
    // 0x801A492C: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x801A4930: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A4934: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x801A4938: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x801A493C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A4940: sw          $t2, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->r10;
    // 0x801A4944: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x801A4948: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x801A494C: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x801A4950: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801A4954: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A4958: jal         0x80019218
    // 0x801A495C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_61;
    // 0x801A495C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_61:
    // 0x801A4960: b           L_801A4A08
    // 0x801A4964: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_801A4A08;
    // 0x801A4964: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801A4968:
    // 0x801A4968: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801A496C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801A4970: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801A4974: addiu       $a3, $t4, 0x5D34
    ctx->r7 = ADD32(ctx->r12, 0X5D34);
    // 0x801A4978: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A497C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801A4980: jal         0x80019218
    // 0x801A4984: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_62;
    // 0x801A4984: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_62:
    // 0x801A4988: lwc1        $f8, 0xEC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x801A498C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x801A4990: sh          $t6, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r14;
    // 0x801A4994: lwc1        $f12, 0xD8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x801A4998: lwc1        $f14, 0xDC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XDC);
    // 0x801A499C: lw          $a2, 0xE0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XE0);
    // 0x801A49A0: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x801A49A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A49A8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A49AC: lwc1        $f6, 0xF0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x801A49B0: lwc1        $f4, 0x7E88($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7E88);
    // 0x801A49B4: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801A49B8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x801A49BC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A49C0: jal         0x8007C120
    // 0x801A49C4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_63;
    // 0x801A49C4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_63:
    // 0x801A49C8: lh          $t8, 0xCE($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XCE);
    // 0x801A49CC: lhu         $t9, 0xD6($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XD6);
    // 0x801A49D0: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801A49D4: addiu       $t3, $zero, 0x32
    ctx->r11 = ADD32(0, 0X32);
    // 0x801A49D8: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801A49DC: sh          $t0, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r8;
    // 0x801A49E0: lh          $t1, 0xCE($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XCE);
    // 0x801A49E4: bgtzl       $t1, L_801A4A08
    if (SIGNED(ctx->r9) > 0) {
        // 0x801A49E8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801A4A08;
    }
    goto skip_16;
    // 0x801A49E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_16:
    // 0x801A49EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A49F0: sh          $t2, 0x46($s1)
    MEM_H(0X46, ctx->r17) = ctx->r10;
    // 0x801A49F4: sh          $zero, 0x48($s1)
    MEM_H(0X48, ctx->r17) = 0;
    // 0x801A49F8: sh          $zero, 0xB6($s1)
    MEM_H(0XB6, ctx->r17) = 0;
    // 0x801A49FC: sh          $t3, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r11;
    // 0x801A4A00: swc1        $f10, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f10.u32l;
    // 0x801A4A04: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801A4A08:
    // 0x801A4A08: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801A4A0C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801A4A10: jr          $ra
    // 0x801A4A14: addiu       $sp, $sp, 0x1E8
    ctx->r29 = ADD32(ctx->r29, 0X1E8);
    return;
    // 0x801A4A14: addiu       $sp, $sp, 0x1E8
    ctx->r29 = ADD32(ctx->r29, 0X1E8);
;}
RECOMP_FUNC void Andross_AndLaserEmitter_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192E94: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80192E98: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80192E9C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80192EA0: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80192EA4: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80192EA8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80192EAC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80192EB0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80192EB4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80192EB8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80192EBC: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
    // 0x80192EC0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80192EC4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80192EC8: beq         $v0, $zero, L_80192EF0
    if (ctx->r2 == 0) {
        // 0x80192ECC: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_80192EF0;
    }
    // 0x80192ECC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80192ED0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80192ED4: beq         $v0, $at, L_80192F70
    if (ctx->r2 == ctx->r1) {
        // 0x80192ED8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80192F70;
    }
    // 0x80192ED8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80192EDC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80192EE0: beq         $v0, $a2, L_801930D4
    if (ctx->r2 == ctx->r6) {
        // 0x80192EE4: nop
    
            goto L_801930D4;
    }
    // 0x80192EE4: nop

    // 0x80192EE8: b           L_80193140
    // 0x80192EEC: lb          $t0, 0xD0($s1)
    ctx->r8 = MEM_B(ctx->r17, 0XD0);
        goto L_80193140;
    // 0x80192EEC: lb          $t0, 0xD0($s1)
    ctx->r8 = MEM_B(ctx->r17, 0XD0);
L_80192EF0:
    // 0x80192EF0: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80192EF4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80192EF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80192EFC: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x80192F00: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80192F04: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80192F08: ori         $a0, $a0, 0x28
    ctx->r4 = ctx->r4 | 0X28;
    // 0x80192F0C: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x80192F10: bc1f        L_80192F24
    if (!c1cs) {
        // 0x80192F14: lui         $t8, 0x800C
        ctx->r24 = S32(0X800C << 16);
            goto L_80192F24;
    }
    // 0x80192F14: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80192F18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80192F1C: b           L_80192F2C
    // 0x80192F20: sh          $t6, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r14;
        goto L_80192F2C;
    // 0x80192F20: sh          $t6, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r14;
L_80192F24:
    // 0x80192F24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80192F28: sh          $a2, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r6;
L_80192F2C:
    // 0x80192F2C: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80192F30: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80192F34: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80192F38: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80192F3C: lwc1        $f6, 0x18($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80192F40: sh          $t7, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r15;
    // 0x80192F44: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80192F48: swc1        $f18, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f18.u32l;
    // 0x80192F4C: swc1        $f8, 0x18C($s1)
    MEM_W(0X18C, ctx->r17) = ctx->f8.u32l;
    // 0x80192F50: swc1        $f4, 0x194($s1)
    MEM_W(0X194, ctx->r17) = ctx->f4.u32l;
    // 0x80192F54: swc1        $f6, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f6.u32l;
    // 0x80192F58: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80192F5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80192F60: jal         0x80019218
    // 0x80192F64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80192F64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80192F68: b           L_80193140
    // 0x80192F6C: lb          $t0, 0xD0($s1)
    ctx->r8 = MEM_B(ctx->r17, 0XD0);
        goto L_80193140;
    // 0x80192F6C: lb          $t0, 0xD0($s1)
    ctx->r8 = MEM_B(ctx->r17, 0XD0);
L_80192F70:
    // 0x80192F70: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80192F74: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80192F78: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80192F7C: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80192F80: lw          $a1, 0x40($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X40);
    // 0x80192F84: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80192F88: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x80192F8C: addiu       $v1, $zero, 0x11D
    ctx->r3 = ADD32(0, 0X11D);
L_80192F90:
    // 0x80192F90: beql        $s0, $a1, L_801930CC
    if (ctx->r16 == ctx->r5) {
        // 0x80192F94: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801930CC;
    }
    goto skip_0;
    // 0x80192F94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80192F98: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80192F9C: bnel        $a2, $t9, L_801930CC
    if (ctx->r6 != ctx->r25) {
        // 0x80192FA0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801930CC;
    }
    goto skip_1;
    // 0x80192FA0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80192FA4: lhu         $t0, 0x2($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X2);
    // 0x80192FA8: bnel        $v1, $t0, L_801930CC
    if (ctx->r3 != ctx->r8) {
        // 0x80192FAC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801930CC;
    }
    goto skip_2;
    // 0x80192FAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x80192FB0: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80192FB4: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80192FB8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80192FBC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80192FC0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80192FC4: nop

    // 0x80192FC8: bc1fl       L_801930CC
    if (!c1cs) {
        // 0x80192FCC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801930CC;
    }
    goto skip_3;
    // 0x80192FCC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_3:
    // 0x80192FD0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80192FD4: sh          $a1, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r5;
    // 0x80192FD8: sh          $a1, 0xBC($v0)
    MEM_H(0XBC, ctx->r2) = ctx->r5;
    // 0x80192FDC: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x80192FE0: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x80192FE4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80192FE8: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80192FEC: addiu       $v1, $v1, 0x4750
    ctx->r3 = ADD32(ctx->r3, 0X4750);
    // 0x80192FF0: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x80192FF4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192FF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80192FFC: mflo        $t3
    ctx->r11 = lo;
    // 0x80193000: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x80193004: sb          $t1, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r9;
    // 0x80193008: lw          $t5, 0x40($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X40);
    // 0x8019300C: multu       $t5, $a0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193010: mflo        $t6
    ctx->r14 = lo;
    // 0x80193014: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80193018: swc1        $f16, 0x28($t7)
    MEM_W(0X28, ctx->r15) = ctx->f16.u32l;
    // 0x8019301C: lw          $t8, 0x40($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X40);
    // 0x80193020: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80193024: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193028: mflo        $t9
    ctx->r25 = lo;
    // 0x8019302C: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80193030: swc1        $f18, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f18.u32l;
    // 0x80193034: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x80193038: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019303C: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193040: mflo        $t3
    ctx->r11 = lo;
    // 0x80193044: addu        $t1, $v1, $t3
    ctx->r9 = ADD32(ctx->r3, ctx->r11);
    // 0x80193048: swc1        $f4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f4.u32l;
    // 0x8019304C: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x80193050: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80193054: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193058: mflo        $t5
    ctx->r13 = lo;
    // 0x8019305C: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80193060: swc1        $f6, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f6.u32l;
    // 0x80193064: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x80193068: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019306C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80193070: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193074: mflo        $t8
    ctx->r24 = lo;
    // 0x80193078: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x8019307C: swc1        $f8, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f8.u32l;
    // 0x80193080: lw          $t0, 0x40($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X40);
    // 0x80193084: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80193088: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019308C: mflo        $t2
    ctx->r10 = lo;
    // 0x80193090: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x80193094: swc1        $f10, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f10.u32l;
    // 0x80193098: lw          $t1, 0x40($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X40);
    // 0x8019309C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801930A0: multu       $t1, $a0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801930A4: mflo        $t4
    ctx->r12 = lo;
    // 0x801930A8: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x801930AC: swc1        $f16, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->f16.u32l;
    // 0x801930B0: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x801930B4: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801930B8: mflo        $t8
    ctx->r24 = lo;
    // 0x801930BC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x801930C0: b           L_801930D4
    // 0x801930C4: sh          $t6, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r14;
        goto L_801930D4;
    // 0x801930C4: sh          $t6, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r14;
    // 0x801930C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801930CC:
    // 0x801930CC: bne         $s0, $a0, L_80192F90
    if (ctx->r16 != ctx->r4) {
        // 0x801930D0: addiu       $v0, $v0, 0x2F4
        ctx->r2 = ADD32(ctx->r2, 0X2F4);
            goto L_80192F90;
    }
    // 0x801930D0: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
L_801930D4:
    // 0x801930D4: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x801930D8: addiu       $v0, $v0, 0x7F68
    ctx->r2 = ADD32(ctx->r2, 0X7F68);
    // 0x801930DC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801930E0: lwc1        $f18, 0xFC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XFC);
    // 0x801930E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801930E8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801930EC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801930F0: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801930F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801930F8: swc1        $f6, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f6.u32l;
    // 0x801930FC: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80193100: lwc1        $f8, 0x7318($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7318);
    // 0x80193104: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80193108: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019310C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80193110: jal         0x80005FE0
    // 0x80193114: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x80193114: nop

    after_1:
    // 0x80193118: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019311C: addiu       $a1, $s1, 0x18C
    ctx->r5 = ADD32(ctx->r17, 0X18C);
    // 0x80193120: jal         0x80006A20
    // 0x80193124: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80193124: addiu       $a2, $s1, 0x4
    ctx->r6 = ADD32(ctx->r17, 0X4);
    after_2:
    // 0x80193128: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019312C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80193130: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80193134: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80193138: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8019313C: lb          $t0, 0xD0($s1)
    ctx->r8 = MEM_B(ctx->r17, 0XD0);
L_80193140:
    // 0x80193140: beql        $t0, $zero, L_80193220
    if (ctx->r8 == 0) {
        // 0x80193144: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80193220;
    }
    goto skip_4;
    // 0x80193144: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_4:
    // 0x80193148: lh          $t2, 0xCE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XCE);
    // 0x8019314C: lhu         $t3, 0xD6($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0XD6);
    // 0x80193150: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x80193154: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80193158: subu        $t1, $t2, $t3
    ctx->r9 = SUB32(ctx->r10, ctx->r11);
    // 0x8019315C: sh          $t1, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r9;
    // 0x80193160: lh          $t4, 0xCE($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XCE);
    // 0x80193164: addiu       $t5, $s1, 0x100
    ctx->r13 = ADD32(ctx->r17, 0X100);
    // 0x80193168: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019316C: bgtz        $t4, L_8019321C
    if (SIGNED(ctx->r12) > 0) {
        // 0x80193170: addiu       $t7, $s1, 0x4
        ctx->r15 = ADD32(ctx->r17, 0X4);
            goto L_8019321C;
    }
    // 0x80193170: addiu       $t7, $s1, 0x4
    ctx->r15 = ADD32(ctx->r17, 0X4);
    // 0x80193174: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80193178: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019317C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80193180: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x80193184: jal         0x8007D0E0
    // 0x80193188: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_3;
    // 0x80193188: sw          $t5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r13;
    after_3:
    // 0x8019318C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80193190: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80193194: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80193198: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019319C: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_801931A0:
    // 0x801931A0: jal         0x80004EB0
    // 0x801931A4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801931A4: nop

    after_4:
    // 0x801931A8: jal         0x80004EB0
    // 0x801931AC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801931AC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_5:
    // 0x801931B0: jal         0x80004EB0
    // 0x801931B4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801931B4: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_6:
    // 0x801931B8: sub.s       $f8, $f22, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x801931BC: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801931C0: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801931C4: sub.s       $f18, $f24, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f24.fl - ctx->f20.fl;
    // 0x801931C8: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x801931CC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801931D0: mul.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x801931D4: nop

    // 0x801931D8: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801931DC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801931E0: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801931E4: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x801931E8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801931EC: jal         0x80079618
    // 0x801931F0: nop

    func_effect_80079618(rdram, ctx);
        goto after_7;
    // 0x801931F0: nop

    after_7:
    // 0x801931F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801931F8: bne         $s0, $s2, L_801931A0
    if (ctx->r16 != ctx->r18) {
        // 0x801931FC: nop
    
            goto L_801931A0;
    }
    // 0x801931FC: nop

    // 0x80193200: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x80193204: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x80193208: jal         0x8007A6F0
    // 0x8019320C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_8;
    // 0x8019320C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_8:
    // 0x80193210: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80193214: jal         0x80060FBC
    // 0x80193218: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    Object_Kill(rdram, ctx);
        goto after_9;
    // 0x80193218: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_9:
L_8019321C:
    // 0x8019321C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80193220:
    // 0x80193220: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80193224: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80193228: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8019322C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80193230: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80193234: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80193238: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8019323C: jr          $ra
    // 0x80193240: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80193240: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Andross_AndSuctionEject_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C7A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018C7A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018C7A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018C7AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018C7B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8018C7B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8018C7B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8018C7BC: jal         0x80061474
    // 0x8018C7C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018C7C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018C7C4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8018C7C8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8018C7CC: addiu       $t7, $zero, 0x18C
    ctx->r15 = ADD32(0, 0X18C);
    // 0x8018C7D0: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8018C7D4: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8018C7D8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018C7DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018C7E0: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8018C7E4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8018C7E8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018C7EC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018C7F0: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018C7F4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8018C7F8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018C7FC: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x8018C800: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018C804: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x8018C808: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018C80C: sh          $t8, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r24;
    // 0x8018C810: sb          $v0, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r2;
    // 0x8018C814: beq         $at, $zero, L_8018C840
    if (ctx->r1 == 0) {
        // 0x8018C818: swc1        $f18, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
            goto L_8018C840;
    }
    // 0x8018C818: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x8018C81C: jal         0x80004EB0
    // 0x8018C820: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018C820: nop

    after_1:
    // 0x8018C824: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8018C828: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C82C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018C830: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018C834: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018C838: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018C83C: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
L_8018C840:
    // 0x8018C840: jal         0x80004EB0
    // 0x8018C844: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018C844: nop

    after_2:
    // 0x8018C848: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018C84C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018C850: nop

    // 0x8018C854: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018C858: jal         0x80004EB0
    // 0x8018C85C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018C85C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x8018C860: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018C864: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C868: nop

    // 0x8018C86C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8018C870: jal         0x80004EB0
    // 0x8018C874: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8018C874: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x8018C878: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018C87C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018C880: nop

    // 0x8018C884: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8018C888: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8018C88C: jal         0x80004EB0
    // 0x8018C890: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8018C890: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x8018C894: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018C898: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018C89C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018C8A0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8018C8A4: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8018C8A8: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018C8AC: jal         0x800612B8
    // 0x8018C8B0: swc1        $f18, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x8018C8B0: swc1        $f18, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x8018C8B4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018C8B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C8BC: nop

    // 0x8018C8C0: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x8018C8C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018C8C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018C8CC: jr          $ra
    // 0x8018C8D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018C8D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void SectorY_SyRobot_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4CB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A4CB4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801A4CB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A4CBC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A4CC0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801A4CC4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x801A4CC8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801A4CCC: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x801A4CD0: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x801A4CD4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801A4CD8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801A4CDC: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x801A4CE0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x801A4CE4: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x801A4CE8: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x801A4CEC: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x801A4CF0: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x801A4CF4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801A4CF8: jal         0x800BA2E8
    // 0x801A4CFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_30(rdram, ctx);
        goto after_0;
    // 0x801A4CFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801A4D00: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801A4D04: lw          $t9, -0x4438($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4438);
    // 0x801A4D08: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x801A4D0C: addiu       $t8, $t8, 0x4C34
    ctx->r24 = ADD32(ctx->r24, 0X4C34);
    // 0x801A4D10: lui         $a1, 0x603
    ctx->r5 = S32(0X603 << 16);
    // 0x801A4D14: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x801A4D18: addiu       $a3, $a3, 0x4A18
    ctx->r7 = ADD32(ctx->r7, 0X4A18);
    // 0x801A4D1C: addiu       $a1, $a1, -0x2EC0
    ctx->r5 = ADD32(ctx->r5, -0X2EC0);
    // 0x801A4D20: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A4D24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801A4D28: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    // 0x801A4D2C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801A4D30: jal         0x8009A72C
    // 0x801A4D34: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x801A4D34: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_1:
    // 0x801A4D38: lhu         $v0, 0xC4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XC4);
    // 0x801A4D3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A4D40: beq         $v0, $zero, L_801A4E30
    if (ctx->r2 == 0) {
        // 0x801A4D44: sll         $t0, $v0, 2
        ctx->r8 = S32(ctx->r2 << 2);
            goto L_801A4E30;
    }
    // 0x801A4D44: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x801A4D48: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x801A4D4C: lwc1        $f4, 0x6B64($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B64);
    // 0x801A4D50: jal         0x800BA5B0
    // 0x801A4D54: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    RCP_SetupDL_49(rdram, ctx);
        goto after_2;
    // 0x801A4D54: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801A4D58: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801A4D5C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801A4D60: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801A4D64: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801A4D68: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801A4D6C: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801A4D70: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x801A4D74: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801A4D78: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A4D7C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801A4D80: lui         $t6, 0xFF30
    ctx->r14 = S32(0XFF30 << 16);
    // 0x801A4D84: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x801A4D88: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801A4D8C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801A4D90: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x801A4D94: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801A4D98: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A4D9C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4DA0: jal         0x80005740
    // 0x801A4DA4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x801A4DA4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x801A4DA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4DAC: jal         0x80005708
    // 0x801A4DB0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x801A4DB0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_4:
    // 0x801A4DB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A4DB8: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801A4DBC: lwc1        $f6, 0x15C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x801A4DC0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4DC4: lw          $a1, 0x154($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X154);
    // 0x801A4DC8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A4DCC: lw          $a2, 0x158($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X158);
    // 0x801A4DD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A4DD4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A4DD8: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801A4DDC: jal         0x80005B00
    // 0x801A4DE0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x801A4DE0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x801A4DE4: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A4DE8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4DEC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A4DF0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A4DF4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A4DF8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A4DFC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A4E00: jal         0x80005C34
    // 0x801A4E04: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x801A4E04: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_6:
    // 0x801A4E08: jal         0x80006EB8
    // 0x801A4E0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x801A4E0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801A4E10: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801A4E14: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x801A4E18: addiu       $t1, $t1, 0x4AC0
    ctx->r9 = ADD32(ctx->r9, 0X4AC0);
    // 0x801A4E1C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A4E20: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801A4E24: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x801A4E28: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801A4E2C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_801A4E30:
    // 0x801A4E30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801A4E34: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801A4E38: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801A4E3C: jr          $ra
    // 0x801A4E40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801A4E40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Venom2_UpdateStarWolfEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801962F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801962F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801962FC: jal         0x8002F69C
    // 0x80196300: nop

    ActorAllRange_UpdateStarWolfEvents(rdram, ctx);
        goto after_0;
    // 0x80196300: nop

    after_0:
    // 0x80196304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80196308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019630C: jr          $ra
    // 0x80196310: nop

    return;
    // 0x80196310: nop

;}
RECOMP_FUNC void SectorY_8019A66C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A66C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019A670: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019A674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019A678: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019A67C: jal         0x8019B6E8
    // 0x8019A680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B6E8(rdram, ctx);
        goto after_0;
    // 0x8019A680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019A684: lh          $t6, 0x52($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X52);
    // 0x8019A688: bnel        $t6, $zero, L_8019A69C
    if (ctx->r14 != 0) {
        // 0x8019A68C: lh          $v0, 0x56($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X56);
            goto L_8019A69C;
    }
    goto skip_0;
    // 0x8019A68C: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
    skip_0:
    // 0x8019A690: jal         0x8019BC14
    // 0x8019A694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019BC14(rdram, ctx);
        goto after_1;
    // 0x8019A694: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019A698: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
L_8019A69C:
    // 0x8019A69C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8019A6A0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A6A4: bne         $v0, $at, L_8019A720
    if (ctx->r2 != ctx->r1) {
        // 0x8019A6A8: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8019A720;
    }
    // 0x8019A6A8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A6AC: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019A6B0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8019A6B4: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x8019A6B8: ori         $a0, $a0, 0x306C
    ctx->r4 = ctx->r4 | 0X306C;
    // 0x8019A6BC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019A6C0: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019A6C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A6C8: jal         0x80019218
    // 0x8019A6CC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019A6CC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x8019A6D0: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8019A6D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019A6D8: jal         0x80004EB0
    // 0x8019A6DC: swc1        $f4, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8019A6DC: swc1        $f4, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8019A6E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019A6E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019A6E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A6EC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8019A6F0: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8019A6F4: addiu       $a0, $a0, 0x948
    ctx->r4 = ADD32(ctx->r4, 0X948);
    // 0x8019A6F8: bc1f        L_8019A714
    if (!c1cs) {
        // 0x8019A6FC: nop
    
            goto L_8019A714;
    }
    // 0x8019A6FC: nop

    // 0x8019A700: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A704: jal         0x8002E4F8
    // 0x8019A708: addiu       $a0, $a0, 0x980
    ctx->r4 = ADD32(ctx->r4, 0X980);
    AllRange_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x8019A708: addiu       $a0, $a0, 0x980
    ctx->r4 = ADD32(ctx->r4, 0X980);
    after_4:
    // 0x8019A70C: b           L_8019A720
    // 0x8019A710: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
        goto L_8019A720;
    // 0x8019A710: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
L_8019A714:
    // 0x8019A714: jal         0x8002E4F8
    // 0x8019A718: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    AllRange_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x8019A718: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_5:
    // 0x8019A71C: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
L_8019A720:
    // 0x8019A720: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8019A724: beq         $at, $zero, L_8019A808
    if (ctx->r1 == 0) {
        // 0x8019A728: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8019A808;
    }
    // 0x8019A728: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A72C: lwc1        $f10, 0x75A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X75A8);
    // 0x8019A730: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019A734: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019A738: jal         0x80023090
    // 0x8019A73C: nop

    __sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x8019A73C: nop

    after_6:
    // 0x8019A740: lwc1        $f16, 0x18C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x8019A744: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A748: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019A74C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8019A750: swc1        $f18, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f18.u32l;
    // 0x8019A754: lwc1        $f6, 0x75AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75AC);
    // 0x8019A758: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019A75C: jal         0x80023250
    // 0x8019A760: nop

    __cosf_recomp(rdram, ctx);
        goto after_7;
    // 0x8019A760: nop

    after_7:
    // 0x8019A764: lwc1        $f8, 0x18C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x8019A768: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A76C: lwc1        $f2, 0x75B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X75B0);
    // 0x8019A770: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8019A774: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019A778: sh          $t8, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r24;
    // 0x8019A77C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8019A780: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8019A784: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x8019A788: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019A78C: swc1        $f10, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f10.u32l;
    // 0x8019A790: jal         0x8009BC2C
    // 0x8019A794: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8019A794: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x8019A798: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019A79C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019A7A0: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    // 0x8019A7A4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019A7A8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8019A7AC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019A7B0: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x8019A7B4: jal         0x8009BC2C
    // 0x8019A7B8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8019A7B8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_9:
    // 0x8019A7BC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019A7C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A7C4: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    // 0x8019A7C8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019A7CC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019A7D0: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8019A7D4: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8019A7D8: jal         0x8009BC2C
    // 0x8019A7DC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8019A7DC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x8019A7E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019A7E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019A7E8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019A7EC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019A7F0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8019A7F4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8019A7F8: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8019A7FC: jal         0x8009BC2C
    // 0x8019A800: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8019A800: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x8019A804: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
L_8019A808:
    // 0x8019A808: bnel        $v0, $zero, L_8019A81C
    if (ctx->r2 != 0) {
        // 0x8019A80C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019A81C;
    }
    goto skip_1;
    // 0x8019A80C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8019A810: jal         0x80198244
    // 0x8019A814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80198244(rdram, ctx);
        goto after_12;
    // 0x8019A814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8019A818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019A81C:
    // 0x8019A81C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019A820: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019A824: jr          $ra
    // 0x8019A828: nop

    return;
    // 0x8019A828: nop

;}
RECOMP_FUNC void Andross_LightningAttack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D0DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0E0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8018D0E4: lw          $a3, -0x7D80($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7D80);
    // 0x8018D0E8: lw          $t6, 0x498($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X498);
    // 0x8018D0EC: bnel        $t6, $zero, L_8018D160
    if (ctx->r14 != 0) {
        // 0x8018D0F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D160;
    }
    goto skip_0;
    // 0x8018D0F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D0F4: lw          $t7, 0x1C8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C8);
    // 0x8018D0F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018D0FC: bnel        $t7, $at, L_8018D160
    if (ctx->r15 != ctx->r1) {
        // 0x8018D100: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D160;
    }
    goto skip_1;
    // 0x8018D100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8018D104: lwc1        $f4, 0x218($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X218);
    // 0x8018D108: lwc1        $f6, 0x74($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X74);
    // 0x8018D10C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8018D110: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018D114: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8018D118: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018D11C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8018D120: nop

    // 0x8018D124: bc1fl       L_8018D160
    if (!c1cs) {
        // 0x8018D128: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D160;
    }
    goto skip_2;
    // 0x8018D128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8018D12C: lwc1        $f8, 0x21C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X21C);
    // 0x8018D130: lwc1        $f10, 0x78($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X78);
    // 0x8018D134: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8018D138: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D13C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018D140: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018D144: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8018D148: nop

    // 0x8018D14C: bc1fl       L_8018D160
    if (!c1cs) {
        // 0x8018D150: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D160;
    }
    goto skip_3;
    // 0x8018D150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8018D154: jal         0x800A6CD0
    // 0x8018D158: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    Player_ApplyDamage(rdram, ctx);
        goto after_0;
    // 0x8018D158: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_0:
    // 0x8018D15C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D160:
    // 0x8018D160: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D164: jr          $ra
    // 0x8018D168: nop

    return;
    // 0x8018D168: nop

;}
RECOMP_FUNC void Venom2_LoadLevelObjects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196968: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019696C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80196970: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x80196974: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x80196978: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019697C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80196980: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80196984: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80196988: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019698C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80196990: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x80196994: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80196998: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8019699C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801969A0: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801969A4: lw          $v0, -0x260($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X260);
    // 0x801969A8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801969AC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801969B0: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x801969B4: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x801969B8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801969BC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801969C0: lw          $t2, 0x1FD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1FD0);
    // 0x801969C4: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x801969C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801969CC: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x801969D0: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x801969D4: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x801969D8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801969DC: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x801969E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801969E4: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x801969E8: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
L_801969EC:
    // 0x801969EC: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x801969F0: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x801969F4: bgez        $v0, L_80196A04
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801969F8: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_80196A04;
    }
    // 0x801969F8: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x801969FC: b           L_80196AC0
    // 0x80196A00: nop

        goto L_80196AC0;
    // 0x80196A00: nop

L_80196A04:
    // 0x80196A04: beql        $at, $zero, L_80196AB4
    if (ctx->r1 == 0) {
        // 0x80196A08: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80196AB4;
    }
    goto skip_0;
    // 0x80196A08: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_0:
    // 0x80196A0C: jal         0x800A4F4C
    // 0x80196A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Initialize(rdram, ctx);
        goto after_0;
    // 0x80196A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80196A14: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80196A18: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80196A1C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80196A20: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x80196A24: lh          $t0, 0x10($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10);
    // 0x80196A28: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x80196A2C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80196A30: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80196A34: addu        $t8, $t1, $s1
    ctx->r24 = ADD32(ctx->r9, ctx->r17);
    // 0x80196A38: lh          $t2, 0x6($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X6);
    // 0x80196A3C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80196A40: nop

    // 0x80196A44: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80196A48: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80196A4C: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80196A50: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80196A54: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80196A58: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x80196A5C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80196A60: nop

    // 0x80196A64: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80196A68: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80196A6C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80196A70: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80196A74: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80196A78: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80196A7C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80196A80: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80196A84: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80196A88: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80196A8C: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80196A90: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x80196A94: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80196A98: nop

    // 0x80196A9C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80196AA0: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80196AA4: jal         0x800612B8
    // 0x80196AA8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80196AA8: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80196AAC: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80196AB0: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80196AB4:
    // 0x80196AB4: slti        $at, $s1, 0x4E20
    ctx->r1 = SIGNED(ctx->r17) < 0X4E20 ? 1 : 0;
    // 0x80196AB8: bnel        $at, $zero, L_801969EC
    if (ctx->r1 != 0) {
        // 0x80196ABC: lw          $t5, 0x0($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X0);
            goto L_801969EC;
    }
    goto skip_1;
    // 0x80196ABC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_80196AC0:
    // 0x80196AC0: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80196AC4: addiu       $s0, $s0, -0x6788
    ctx->r16 = ADD32(ctx->r16, -0X6788);
    // 0x80196AC8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80196ACC: addiu       $s4, $zero, 0x4E20
    ctx->r20 = ADD32(0, 0X4E20);
    // 0x80196AD0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80196AD4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80196AD8:
    // 0x80196AD8: addu        $t2, $t8, $s1
    ctx->r10 = ADD32(ctx->r24, ctx->r17);
    // 0x80196ADC: lh          $v0, 0x10($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X10);
    // 0x80196AE0: bltz        $v0, L_80196BA8
    if (SIGNED(ctx->r2) < 0) {
        // 0x80196AE4: slti        $at, $v0, 0xB0
        ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
            goto L_80196BA8;
    }
    // 0x80196AE4: slti        $at, $v0, 0xB0
    ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
    // 0x80196AE8: bne         $at, $zero, L_80196B9C
    if (ctx->r1 != 0) {
        // 0x80196AEC: slti        $at, $v0, 0x124
        ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
            goto L_80196B9C;
    }
    // 0x80196AEC: slti        $at, $v0, 0x124
    ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
    // 0x80196AF0: beql        $at, $zero, L_80196BA0
    if (ctx->r1 == 0) {
        // 0x80196AF4: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80196BA0;
    }
    goto skip_2;
    // 0x80196AF4: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_2:
    // 0x80196AF8: jal         0x800613C4
    // 0x80196AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_2;
    // 0x80196AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80196B00: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x80196B04: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80196B08: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80196B0C: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80196B10: lh          $t5, 0x10($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X10);
    // 0x80196B14: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x80196B18: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80196B1C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80196B20: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80196B24: lh          $t9, 0x6($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X6);
    // 0x80196B28: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80196B2C: nop

    // 0x80196B30: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80196B34: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80196B38: swc1        $f0, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f0.u32l;
    // 0x80196B3C: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80196B40: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80196B44: lh          $t8, 0x8($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X8);
    // 0x80196B48: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80196B4C: nop

    // 0x80196B50: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80196B54: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80196B58: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
    // 0x80196B5C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80196B60: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80196B64: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80196B68: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80196B6C: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80196B70: swc1        $f0, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f0.u32l;
    // 0x80196B74: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80196B78: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80196B7C: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x80196B80: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80196B84: nop

    // 0x80196B88: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80196B8C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80196B90: jal         0x800612B8
    // 0x80196B94: swc1        $f0, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f0.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x80196B94: swc1        $f0, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x80196B98: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_80196B9C:
    // 0x80196B9C: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80196BA0:
    // 0x80196BA0: bnel        $s1, $s4, L_80196AD8
    if (ctx->r17 != ctx->r20) {
        // 0x80196BA4: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80196AD8;
    }
    goto skip_3;
    // 0x80196BA4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_3:
L_80196BA8:
    // 0x80196BA8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80196BAC: jal         0x80061404
    // 0x80196BB0: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    Boss_Initialize(rdram, ctx);
        goto after_4;
    // 0x80196BB0: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    after_4:
    // 0x80196BB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80196BB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196BBC: sb          $t7, -0xEF0($at)
    MEM_B(-0XEF0, ctx->r1) = ctx->r15;
    // 0x80196BC0: addiu       $a1, $zero, 0x138
    ctx->r5 = ADD32(0, 0X138);
    // 0x80196BC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196BC8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80196BCC: addiu       $a0, $a0, -0xED4
    ctx->r4 = ADD32(ctx->r4, -0XED4);
    // 0x80196BD0: jal         0x800612B8
    // 0x80196BD4: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x80196BD4: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    after_5:
    // 0x80196BD8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80196BDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80196BE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80196BE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80196BE8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80196BEC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80196BF0: jr          $ra
    // 0x80196BF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80196BF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void SectorY_8019C194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C194: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019C198: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019C19C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019C1A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019C1A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019C1A8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8019C1AC: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019C1B0: lw          $t6, 0x13A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13A0);
    // 0x8019C1B4: slti        $at, $t6, 0xFB
    ctx->r1 = SIGNED(ctx->r14) < 0XFB ? 1 : 0;
    // 0x8019C1B8: bne         $at, $zero, L_8019C2C4
    if (ctx->r1 != 0) {
        // 0x8019C1BC: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8019C2C4;
    }
    // 0x8019C1BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C1C0: lwc1        $f4, 0x760C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X760C);
    // 0x8019C1C4: lwc1        $f6, 0x160($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X160);
    // 0x8019C1C8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019C1CC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8019C1D0: nop

    // 0x8019C1D4: bc1fl       L_8019C2C8
    if (!c1cs) {
        // 0x8019C1D8: lui         $at, 0x4448
        ctx->r1 = S32(0X4448 << 16);
            goto L_8019C2C8;
    }
    goto skip_0;
    // 0x8019C1D8: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    skip_0:
    // 0x8019C1DC: lw          $v1, 0x7A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A30);
    // 0x8019C1E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019C1E4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019C1E8: beq         $v1, $zero, L_8019C20C
    if (ctx->r3 == 0) {
        // 0x8019C1EC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8019C20C;
    }
    // 0x8019C1EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8019C1F0: beq         $v0, $at, L_8019C234
    if (ctx->r2 == ctx->r1) {
        // 0x8019C1F4: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8019C234;
    }
    // 0x8019C1F4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019C1F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019C1FC: beq         $v0, $at, L_8019C25C
    if (ctx->r2 == ctx->r1) {
        // 0x8019C200: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_8019C25C;
    }
    // 0x8019C200: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8019C204: b           L_8019C2A0
    // 0x8019C208: nop

        goto L_8019C2A0;
    // 0x8019C208: nop

L_8019C20C:
    // 0x8019C20C: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x8019C210: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019C214: addiu       $a0, $a0, 0x7D8
    ctx->r4 = ADD32(ctx->r4, 0X7D8);
    // 0x8019C218: blez        $t7, L_8019C2A0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8019C21C: nop
    
            goto L_8019C2A0;
    }
    // 0x8019C21C: nop

    // 0x8019C220: jal         0x8002E4F8
    // 0x8019C224: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    AllRange_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x8019C224: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x8019C228: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019C22C: b           L_8019C2A0
    // 0x8019C230: lw          $v1, 0x7A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A30);
        goto L_8019C2A0;
    // 0x8019C230: lw          $v1, 0x7A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A30);
L_8019C234:
    // 0x8019C234: lw          $t8, 0x78BC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78BC);
    // 0x8019C238: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019C23C: addiu       $a0, $a0, 0x810
    ctx->r4 = ADD32(ctx->r4, 0X810);
    // 0x8019C240: blez        $t8, L_8019C2A0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8019C244: nop
    
            goto L_8019C2A0;
    }
    // 0x8019C244: nop

    // 0x8019C248: jal         0x8002E4F8
    // 0x8019C24C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    AllRange_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8019C24C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_1:
    // 0x8019C250: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019C254: b           L_8019C2A0
    // 0x8019C258: lw          $v1, 0x7A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A30);
        goto L_8019C2A0;
    // 0x8019C258: lw          $v1, 0x7A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A30);
L_8019C25C:
    // 0x8019C25C: lw          $t9, 0x78B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B8);
    // 0x8019C260: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019C264: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8019C268: blez        $t9, L_8019C2A0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8019C26C: nop
    
            goto L_8019C2A0;
    }
    // 0x8019C26C: nop

    // 0x8019C270: lbu         $t0, 0x408($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X408);
    // 0x8019C274: beq         $t0, $zero, L_8019C2A0
    if (ctx->r8 == 0) {
        // 0x8019C278: nop
    
            goto L_8019C2A0;
    }
    // 0x8019C278: nop

    // 0x8019C27C: lbu         $t1, 0x810($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X810);
    // 0x8019C280: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019C284: addiu       $a0, $a0, 0x854
    ctx->r4 = ADD32(ctx->r4, 0X854);
    // 0x8019C288: beq         $t1, $zero, L_8019C2A0
    if (ctx->r9 == 0) {
        // 0x8019C28C: nop
    
            goto L_8019C2A0;
    }
    // 0x8019C28C: nop

    // 0x8019C290: jal         0x8002E4F8
    // 0x8019C294: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    AllRange_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x8019C294: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_2:
    // 0x8019C298: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019C29C: lw          $v1, 0x7A30($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A30);
L_8019C2A0:
    // 0x8019C2A0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8019C2A4: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8019C2A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019C2AC: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x8019C2B0: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8019C2B4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8019C2B8: sw          $t5, 0x7A30($at)
    MEM_W(0X7A30, ctx->r1) = ctx->r13;
    // 0x8019C2BC: andi        $t6, $t5, 0x3
    ctx->r14 = ctx->r13 & 0X3;
    // 0x8019C2C0: sw          $t6, 0x7A30($at)
    MEM_W(0X7A30, ctx->r1) = ctx->r14;
L_8019C2C4:
    // 0x8019C2C4: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
L_8019C2C8:
    // 0x8019C2C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C2CC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019C2D0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019C2D4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019C2D8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8019C2DC: nop

    // 0x8019C2E0: bc1tl       L_8019C300
    if (c1cs) {
        // 0x8019C2E4: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8019C300;
    }
    goto skip_1;
    // 0x8019C2E4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    skip_1:
    // 0x8019C2E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C2EC: nop

    // 0x8019C2F0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8019C2F4: nop

    // 0x8019C2F8: bc1f        L_8019C874
    if (!c1cs) {
        // 0x8019C2FC: lui         $at, 0x4100
        ctx->r1 = S32(0X4100 << 16);
            goto L_8019C874;
    }
    // 0x8019C2FC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
L_8019C300:
    // 0x8019C300: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C304: lwc1        $f8, 0x188($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019C308: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019C30C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C310: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019C314: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C318: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
    // 0x8019C31C: lwc1        $f0, 0x188($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019C320: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8019C324: nop

    // 0x8019C328: bc1fl       L_8019C344
    if (!c1cs) {
        // 0x8019C32C: lw          $t7, 0x40($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X40);
            goto L_8019C344;
    }
    goto skip_2;
    // 0x8019C32C: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    skip_2:
    // 0x8019C330: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019C334: nop

    // 0x8019C338: swc1        $f8, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f8.u32l;
    // 0x8019C33C: lwc1        $f0, 0x188($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019C340: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
L_8019C344:
    // 0x8019C344: bne         $t7, $zero, L_8019C408
    if (ctx->r15 != 0) {
        // 0x8019C348: nop
    
            goto L_8019C408;
    }
    // 0x8019C348: nop

    // 0x8019C34C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C350: lwc1        $f10, 0x7610($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7610);
    // 0x8019C354: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019C358: jal         0x80023090
    // 0x8019C35C: nop

    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x8019C35C: nop

    after_3:
    // 0x8019C360: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8019C364: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C368: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8019C36C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019C370: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8019C374: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019C378: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8019C37C: nop

    // 0x8019C380: bc1fl       L_8019C394
    if (!c1cs) {
        // 0x8019C384: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_8019C394;
    }
    goto skip_3;
    // 0x8019C384: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_3:
    // 0x8019C388: b           L_8019C394
    // 0x8019C38C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8019C394;
    // 0x8019C38C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8019C390: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8019C394:
    // 0x8019C394: mul.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8019C398: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019C39C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C3A0: lwc1        $f6, 0x188($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019C3A4: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8019C3A8: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8019C3AC: lwc1        $f8, 0x7614($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7614);
    // 0x8019C3B0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8019C3B4: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019C3B8: jal         0x80023090
    // 0x8019C3BC: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8019C3BC: nop

    after_4:
    // 0x8019C3C0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8019C3C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C3C8: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8019C3CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019C3D0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C3D4: mul.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8019C3D8: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8019C3DC: nop

    // 0x8019C3E0: bc1fl       L_8019C3F4
    if (!c1cs) {
        // 0x8019C3E4: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_8019C3F4;
    }
    goto skip_4;
    // 0x8019C3E4: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_4:
    // 0x8019C3E8: b           L_8019C3F4
    // 0x8019C3EC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8019C3F4;
    // 0x8019C3EC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8019C3F0: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8019C3F4:
    // 0x8019C3F4: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8019C3F8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019C3FC: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019C400: b           L_8019C4BC
    // 0x8019C404: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8019C4BC;
    // 0x8019C404: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8019C408:
    // 0x8019C408: lwc1        $f4, 0x7618($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7618);
    // 0x8019C40C: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019C410: jal         0x80023090
    // 0x8019C414: nop

    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8019C414: nop

    after_5:
    // 0x8019C418: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C41C: lwc1        $f8, 0x761C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X761C);
    // 0x8019C420: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8019C424: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019C428: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8019C42C: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019C430: c.le.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl <= ctx->f12.fl;
    // 0x8019C434: nop

    // 0x8019C438: bc1fl       L_8019C44C
    if (!c1cs) {
        // 0x8019C43C: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_8019C44C;
    }
    goto skip_5;
    // 0x8019C43C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_5:
    // 0x8019C440: b           L_8019C44C
    // 0x8019C444: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8019C44C;
    // 0x8019C444: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8019C448: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8019C44C:
    // 0x8019C44C: mul.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8019C450: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019C454: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C458: lwc1        $f8, 0x188($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019C45C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8019C460: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8019C464: lwc1        $f10, 0x7620($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7620);
    // 0x8019C468: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8019C46C: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019C470: jal         0x80023090
    // 0x8019C474: nop

    __sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x8019C474: nop

    after_6:
    // 0x8019C478: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C47C: lwc1        $f6, 0x7624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7624);
    // 0x8019C480: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8019C484: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019C488: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C48C: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019C490: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8019C494: nop

    // 0x8019C498: bc1fl       L_8019C4AC
    if (!c1cs) {
        // 0x8019C49C: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_8019C4AC;
    }
    goto skip_6;
    // 0x8019C49C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_6:
    // 0x8019C4A0: b           L_8019C4AC
    // 0x8019C4A4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8019C4AC;
    // 0x8019C4A4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8019C4A8: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8019C4AC:
    // 0x8019C4AC: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8019C4B0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019C4B4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019C4B8: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8019C4BC:
    // 0x8019C4BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C4C0: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8019C4C4: jal         0x8019B5CC
    // 0x8019C4C8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    SectorY_8019B5CC(rdram, ctx);
        goto after_7;
    // 0x8019C4C8: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x8019C4CC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C4D0: bne         $v0, $zero, L_8019C568
    if (ctx->r2 != 0) {
        // 0x8019C4D4: lwc1        $f18, 0x28($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
            goto L_8019C568;
    }
    // 0x8019C4D4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019C4D8: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x8019C4DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C4E0: bnel        $t8, $zero, L_8019C530
    if (ctx->r24 != 0) {
        // 0x8019C4E4: lwc1        $f4, 0x188($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X188);
            goto L_8019C530;
    }
    goto skip_7;
    // 0x8019C4E4: lwc1        $f4, 0x188($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X188);
    skip_7:
    // 0x8019C4E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C4EC: lwc1        $f8, 0x7628($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7628);
    // 0x8019C4F0: lwc1        $f6, 0x188($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X188);
    // 0x8019C4F4: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8019C4F8: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8019C4FC: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019C500: jal         0x80023090
    // 0x8019C504: nop

    __sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x8019C504: nop

    after_8:
    // 0x8019C508: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019C50C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C510: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019C514: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C518: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019C51C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019C520: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8019C524: b           L_8019C568
    // 0x8019C528: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
        goto L_8019C568;
    // 0x8019C528: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8019C52C: lwc1        $f4, 0x188($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X188);
L_8019C530:
    // 0x8019C530: lwc1        $f10, 0x762C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X762C);
    // 0x8019C534: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x8019C538: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x8019C53C: mul.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8019C540: jal         0x80023090
    // 0x8019C544: nop

    __sinf_recomp(rdram, ctx);
        goto after_9;
    // 0x8019C544: nop

    after_9:
    // 0x8019C548: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019C54C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C550: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019C554: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019C558: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8019C55C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019C560: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019C564: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_8019C568:
    // 0x8019C568: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x8019C56C: bnel        $t9, $zero, L_8019C878
    if (ctx->r25 != 0) {
        // 0x8019C570: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019C878;
    }
    goto skip_8;
    // 0x8019C570: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x8019C574: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8019C578: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019C57C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019C580: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019C584: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8019C588: nop

    // 0x8019C58C: bc1fl       L_8019C5A0
    if (!c1cs) {
        // 0x8019C590: neg.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
            goto L_8019C5A0;
    }
    goto skip_9;
    // 0x8019C590: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
    skip_9:
    // 0x8019C594: b           L_8019C5A0
    // 0x8019C598: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
        goto L_8019C5A0;
    // 0x8019C598: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8019C59C: neg.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = -ctx->f0.fl;
L_8019C5A0:
    // 0x8019C5A0: lwc1        $f0, 0x6C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8019C5A4: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8019C5A8: nop

    // 0x8019C5AC: bc1fl       L_8019C5C0
    if (!c1cs) {
        // 0x8019C5B0: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_8019C5C0;
    }
    goto skip_10;
    // 0x8019C5B0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_10:
    // 0x8019C5B4: b           L_8019C5C0
    // 0x8019C5B8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8019C5C0;
    // 0x8019C5B8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019C5BC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8019C5C0:
    // 0x8019C5C0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8019C5C4: nop

    // 0x8019C5C8: bc1fl       L_8019C688
    if (!c1cs) {
        // 0x8019C5CC: lwc1        $f0, 0x18($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
            goto L_8019C688;
    }
    goto skip_11;
    // 0x8019C5CC: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    skip_11:
    // 0x8019C5D0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019C5D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C5D8: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019C5DC: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x8019C5E0: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8019C5E4: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8019C5E8: nop

    // 0x8019C5EC: bc1tl       L_8019C610
    if (c1cs) {
        // 0x8019C5F0: lui         $at, 0x4234
        ctx->r1 = S32(0X4234 << 16);
            goto L_8019C610;
    }
    goto skip_12;
    // 0x8019C5F0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    skip_12:
    // 0x8019C5F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C5F8: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8019C5FC: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x8019C600: nop

    // 0x8019C604: bc1fl       L_8019C650
    if (!c1cs) {
        // 0x8019C608: lwc1        $f0, 0x14($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
            goto L_8019C650;
    }
    goto skip_13;
    // 0x8019C608: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    skip_13:
    // 0x8019C60C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
L_8019C610:
    // 0x8019C610: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C614: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019C618: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x8019C61C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8019C620: nop

    // 0x8019C624: bc1fl       L_8019C730
    if (!c1cs) {
        // 0x8019C628: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8019C730;
    }
    goto skip_14;
    // 0x8019C628: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_14:
    // 0x8019C62C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C630: nop

    // 0x8019C634: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x8019C638: nop

    // 0x8019C63C: bc1fl       L_8019C730
    if (!c1cs) {
        // 0x8019C640: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8019C730;
    }
    goto skip_15;
    // 0x8019C640: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_15:
    // 0x8019C644: b           L_8019C72C
    // 0x8019C648: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
        goto L_8019C72C;
    // 0x8019C648: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
    // 0x8019C64C: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
L_8019C650:
    // 0x8019C650: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C654: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C658: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8019C65C: nop

    // 0x8019C660: bc1fl       L_8019C730
    if (!c1cs) {
        // 0x8019C664: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8019C730;
    }
    goto skip_16;
    // 0x8019C664: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_16:
    // 0x8019C668: lwc1        $f10, 0x7630($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7630);
    // 0x8019C66C: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8019C670: nop

    // 0x8019C674: bc1fl       L_8019C730
    if (!c1cs) {
        // 0x8019C678: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8019C730;
    }
    goto skip_17;
    // 0x8019C678: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_17:
    // 0x8019C67C: b           L_8019C72C
    // 0x8019C680: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
        goto L_8019C72C;
    // 0x8019C680: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
    // 0x8019C684: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
L_8019C688:
    // 0x8019C688: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C68C: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8019C690: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8019C694: nop

    // 0x8019C698: bc1tl       L_8019C6BC
    if (c1cs) {
        // 0x8019C69C: lui         $at, 0x4307
        ctx->r1 = S32(0X4307 << 16);
            goto L_8019C6BC;
    }
    goto skip_18;
    // 0x8019C69C: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    skip_18:
    // 0x8019C6A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C6A4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8019C6A8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8019C6AC: nop

    // 0x8019C6B0: bc1fl       L_8019C6FC
    if (!c1cs) {
        // 0x8019C6B4: lwc1        $f0, 0x14($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
            goto L_8019C6FC;
    }
    goto skip_19;
    // 0x8019C6B4: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    skip_19:
    // 0x8019C6B8: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
L_8019C6BC:
    // 0x8019C6BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C6C0: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019C6C4: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x8019C6C8: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8019C6CC: nop

    // 0x8019C6D0: bc1fl       L_8019C730
    if (!c1cs) {
        // 0x8019C6D4: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8019C730;
    }
    goto skip_20;
    // 0x8019C6D4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_20:
    // 0x8019C6D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019C6DC: nop

    // 0x8019C6E0: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8019C6E4: nop

    // 0x8019C6E8: bc1fl       L_8019C730
    if (!c1cs) {
        // 0x8019C6EC: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8019C730;
    }
    goto skip_21;
    // 0x8019C6EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_21:
    // 0x8019C6F0: b           L_8019C72C
    // 0x8019C6F4: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
        goto L_8019C72C;
    // 0x8019C6F4: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8019C6F8: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
L_8019C6FC:
    // 0x8019C6FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C700: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C704: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8019C708: nop

    // 0x8019C70C: bc1tl       L_8019C72C
    if (c1cs) {
        // 0x8019C710: neg.s       $f16, $f16
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
            goto L_8019C72C;
    }
    goto skip_22;
    // 0x8019C710: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    skip_22:
    // 0x8019C714: lwc1        $f6, 0x7634($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7634);
    // 0x8019C718: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8019C71C: nop

    // 0x8019C720: bc1fl       L_8019C730
    if (!c1cs) {
        // 0x8019C724: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_8019C730;
    }
    goto skip_23;
    // 0x8019C724: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_23:
    // 0x8019C728: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_8019C72C:
    // 0x8019C72C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_8019C730:
    // 0x8019C730: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C734: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8019C738: nop

    // 0x8019C73C: bc1fl       L_8019C780
    if (!c1cs) {
        // 0x8019C740: c.lt.s      $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
            goto L_8019C780;
    }
    goto skip_24;
    // 0x8019C740: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    skip_24:
    // 0x8019C744: lwc1        $f12, 0x7638($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7638);
    // 0x8019C748: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019C74C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C750: mul.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8019C754: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8019C758: nop

    // 0x8019C75C: bc1fl       L_8019C770
    if (!c1cs) {
        // 0x8019C760: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_8019C770;
    }
    goto skip_25;
    // 0x8019C760: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_25:
    // 0x8019C764: b           L_8019C770
    // 0x8019C768: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8019C770;
    // 0x8019C768: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019C76C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8019C770:
    // 0x8019C770: lwc1        $f14, 0x763C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X763C);
    // 0x8019C774: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8019C778: swc1        $f10, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f10.u32l;
    // 0x8019C77C: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
L_8019C780:
    // 0x8019C780: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C784: lwc1        $f12, 0x7640($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7640);
    // 0x8019C788: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019C78C: bc1f        L_8019C808
    if (!c1cs) {
        // 0x8019C790: lwc1        $f14, 0x7644($at)
        ctx->f14.u32l = MEM_W(ctx->r1, 0X7644);
            goto L_8019C808;
    }
    // 0x8019C790: lwc1        $f14, 0x7644($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7644);
    // 0x8019C794: lwc1        $f8, 0x17C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x8019C798: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019C79C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019C7A0: c.eq.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl == ctx->f8.fl;
    // 0x8019C7A4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019C7A8: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019C7AC: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019C7B0: bc1fl       L_8019C878
    if (!c1cs) {
        // 0x8019C7B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019C878;
    }
    goto skip_26;
    // 0x8019C7B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_26:
    // 0x8019C7B8: mul.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8019C7BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019C7C0: nop

    // 0x8019C7C4: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8019C7C8: nop

    // 0x8019C7CC: bc1fl       L_8019C7E0
    if (!c1cs) {
        // 0x8019C7D0: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_8019C7E0;
    }
    goto skip_27;
    // 0x8019C7D0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_27:
    // 0x8019C7D4: b           L_8019C7E0
    // 0x8019C7D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8019C7E0;
    // 0x8019C7D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019C7DC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8019C7E0:
    // 0x8019C7E0: add.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8019C7E4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8019C7E8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019C7EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019C7F0: swc1        $f4, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f4.u32l;
    // 0x8019C7F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8019C7F8: jal         0x80019218
    // 0x8019C7FC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8019C7FC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_10:
    // 0x8019C800: b           L_8019C878
    // 0x8019C804: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8019C878;
    // 0x8019C804: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019C808:
    // 0x8019C808: lwc1        $f10, 0x180($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X180);
    // 0x8019C80C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019C810: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019C814: c.eq.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl == ctx->f10.fl;
    // 0x8019C818: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019C81C: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019C820: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019C824: bc1fl       L_8019C878
    if (!c1cs) {
        // 0x8019C828: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019C878;
    }
    goto skip_28;
    // 0x8019C828: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_28:
    // 0x8019C82C: mul.s       $f0, $f16, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x8019C830: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019C834: nop

    // 0x8019C838: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x8019C83C: nop

    // 0x8019C840: bc1fl       L_8019C854
    if (!c1cs) {
        // 0x8019C844: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_8019C854;
    }
    goto skip_29;
    // 0x8019C844: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_29:
    // 0x8019C848: b           L_8019C854
    // 0x8019C84C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8019C854;
    // 0x8019C84C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019C850: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8019C854:
    // 0x8019C854: add.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x8019C858: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8019C85C: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019C860: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019C864: swc1        $f6, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->f6.u32l;
    // 0x8019C868: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019C86C: jal         0x80019218
    // 0x8019C870: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_11;
    // 0x8019C870: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_11:
L_8019C874:
    // 0x8019C874: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019C878:
    // 0x8019C878: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019C87C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019C880: jr          $ra
    // 0x8019C884: nop

    return;
    // 0x8019C884: nop

;}
RECOMP_FUNC void Andross_AndBrain_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B47C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018B480: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018B484: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8018B488: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018B48C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018B490: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8018B494: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8018B498: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8018B49C: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x8018B4A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B4A4: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018B4A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018B4AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018B4B0: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8018B4B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8018B4B8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018B4BC: bc1f        L_8018B538
    if (!c1cs) {
        // 0x8018B4C0: nop
    
            goto L_8018B538;
    }
    // 0x8018B4C0: nop

    // 0x8018B4C4: bne         $t6, $at, L_8018B524
    if (ctx->r14 != ctx->r1) {
        // 0x8018B4C8: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_8018B524;
    }
    // 0x8018B4C8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018B4CC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018B4D0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018B4D4: jal         0x800B8DD0
    // 0x8018B4D8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018B4D8: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_0:
    // 0x8018B4DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018B4E0: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x8018B4E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018B4E8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8018B4EC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018B4F0: sw          $t7, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r15;
    // 0x8018B4F4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018B4F8: lwc1        $f8, 0x13C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X13C);
    // 0x8018B4FC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8018B500: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018B504: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x8018B508: nop

    // 0x8018B50C: sll         $t2, $t1, 24
    ctx->r10 = S32(ctx->r9 << 24);
    // 0x8018B510: or          $t4, $t2, $at
    ctx->r12 = ctx->r10 | ctx->r1;
    // 0x8018B514: ori         $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 | 0XFFFF;
    // 0x8018B518: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8018B51C: b           L_8018B580
    // 0x8018B520: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_8018B580;
    // 0x8018B520: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8018B524:
    // 0x8018B524: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018B528: jal         0x800B8DD0
    // 0x8018B52C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018B52C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_1:
    // 0x8018B530: b           L_8018B580
    // 0x8018B534: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_8018B580;
    // 0x8018B534: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8018B538:
    // 0x8018B538: jal         0x800B8DD0
    // 0x8018B53C: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8018B53C: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    after_2:
    // 0x8018B540: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018B544: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x8018B548: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018B54C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018B550: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018B554: sw          $t6, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r14;
    // 0x8018B558: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018B55C: lwc1        $f16, 0x12C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018B560: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018B564: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018B568: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8018B56C: nop

    // 0x8018B570: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8018B574: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8018B578: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8018B57C: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8018B580:
    // 0x8018B580: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018B584: bnel        $v0, $at, L_8018B5AC
    if (ctx->r2 != ctx->r1) {
        // 0x8018B588: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8018B5AC;
    }
    goto skip_0;
    // 0x8018B588: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8018B58C: lh          $t2, 0x94($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X94);
    // 0x8018B590: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B594: beql        $t2, $zero, L_8018B5AC
    if (ctx->r10 == 0) {
        // 0x8018B598: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8018B5AC;
    }
    goto skip_1;
    // 0x8018B598: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x8018B59C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8018B5A0: b           L_8018B8AC
    // 0x8018B5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018B8AC;
    // 0x8018B5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018B5A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8018B5AC:
    // 0x8018B5AC: beq         $v0, $at, L_8018B5C0
    if (ctx->r2 == ctx->r1) {
        // 0x8018B5B0: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018B5C0;
    }
    // 0x8018B5B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B5B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018B5B8: bnel        $v0, $at, L_8018B8AC
    if (ctx->r2 != ctx->r1) {
        // 0x8018B5BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018B8AC;
    }
    goto skip_2;
    // 0x8018B5BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
L_8018B5C0:
    // 0x8018B5C0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8018B5C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018B5C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B5CC: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x8018B5D0: lw          $a2, 0x4($t4)
    ctx->r6 = MEM_W(ctx->r12, 0X4);
    // 0x8018B5D4: lw          $a3, 0x8($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X8);
    // 0x8018B5D8: jal         0x80005B00
    // 0x8018B5DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8018B5DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x8018B5E0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8018B5E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B5E8: lwc1        $f6, 0x6CCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6CCC);
    // 0x8018B5EC: lwc1        $f4, 0x8($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X8);
    // 0x8018B5F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B5F4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B5F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018B5FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B600: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018B604: jal         0x80005FE0
    // 0x8018B608: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x8018B608: nop

    after_4:
    // 0x8018B60C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8018B610: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B614: lwc1        $f16, 0x6CD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CD0);
    // 0x8018B618: lwc1        $f10, 0x4($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X4);
    // 0x8018B61C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B620: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B624: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018B628: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B62C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018B630: jal         0x80005E90
    // 0x8018B634: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x8018B634: nop

    after_5:
    // 0x8018B638: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8018B63C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B640: lwc1        $f6, 0x6CD4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6CD4);
    // 0x8018B644: lwc1        $f4, 0x0($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8018B648: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B64C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018B650: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018B654: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B658: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018B65C: jal         0x80005D44
    // 0x8018B660: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x8018B660: nop

    after_6:
    // 0x8018B664: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B668: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B66C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8018B670: beq         $t0, $zero, L_8018B8A0
    if (ctx->r8 == 0) {
        // 0x8018B674: nop
    
            goto L_8018B8A0;
    }
    // 0x8018B674: nop

    // 0x8018B678: jal         0x80005708
    // 0x8018B67C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x8018B67C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_7:
    // 0x8018B680: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B684: jal         0x80005708
    // 0x8018B688: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_8;
    // 0x8018B688: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_8:
    // 0x8018B68C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B690: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8018B694: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x8018B698: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018B69C: jal         0x80005754
    // 0x8018B6A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_9;
    // 0x8018B6A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8018B6A4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8018B6A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018B6AC: bnel        $t1, $at, L_8018B74C
    if (ctx->r9 != ctx->r1) {
        // 0x8018B6B0: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8018B74C;
    }
    goto skip_3;
    // 0x8018B6B0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    skip_3:
    // 0x8018B6B4: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8018B6B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B6BC: lwc1        $f18, 0x6CD8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6CD8);
    // 0x8018B6C0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8018B6C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B6C8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018B6CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018B6D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B6D4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018B6D8: jal         0x80005E90
    // 0x8018B6DC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_10;
    // 0x8018B6DC: nop

    after_10:
    // 0x8018B6E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B6E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018B6E8: lwc1        $f0, 0x118($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018B6EC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B6F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018B6F4: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8018B6F8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8018B6FC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018B700: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8018B704: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018B708: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018B70C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8018B710: jal         0x80005C34
    // 0x8018B714: nop

    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x8018B714: nop

    after_11:
    // 0x8018B718: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B71C: lwc1        $f16, 0x6CDC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6CDC);
    // 0x8018B720: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8018B724: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B728: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018B72C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8018B730: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B734: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018B738: jal         0x80005E90
    // 0x8018B73C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x8018B73C: nop

    after_12:
    // 0x8018B740: b           L_8018B7F0
    // 0x8018B744: nop

        goto L_8018B7F0;
    // 0x8018B744: nop

    // 0x8018B748: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
L_8018B74C:
    // 0x8018B74C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018B750: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8018B754: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B758: lwc1        $f10, 0x6CE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6CE0);
    // 0x8018B75C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018B760: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B764: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018B768: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B76C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018B770: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018B774: jal         0x80005E90
    // 0x8018B778: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x8018B778: nop

    after_13:
    // 0x8018B77C: lwc1        $f0, 0x118($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018B780: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018B784: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018B788: add.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8018B78C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B790: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018B794: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8018B798: add.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8018B79C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018B7A0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018B7A4: sub.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x8018B7A8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018B7AC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8018B7B0: jal         0x80005C34
    // 0x8018B7B4: nop

    Matrix_Scale(rdram, ctx);
        goto after_14;
    // 0x8018B7B4: nop

    after_14:
    // 0x8018B7B8: lwc1        $f6, 0x110($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8018B7BC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018B7C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018B7C4: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8018B7C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018B7CC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018B7D0: lwc1        $f18, 0x6CE4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6CE4);
    // 0x8018B7D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B7D8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018B7DC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018B7E0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8018B7E4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018B7E8: jal         0x80005E90
    // 0x8018B7EC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_15;
    // 0x8018B7EC: nop

    after_15:
L_8018B7F0:
    // 0x8018B7F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018B7F4: jal         0x80006EB8
    // 0x8018B7F8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x8018B7F8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_16:
    // 0x8018B7FC: lh          $t4, 0x8E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8E);
    // 0x8018B800: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x8018B804: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x8018B808: beq         $t5, $zero, L_8018B860
    if (ctx->r13 == 0) {
        // 0x8018B80C: nop
    
            goto L_8018B860;
    }
    // 0x8018B80C: nop

    // 0x8018B810: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018B814: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018B818: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018B81C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018B820: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8018B824: nop

    // 0x8018B828: bc1f        L_8018B860
    if (!c1cs) {
        // 0x8018B82C: nop
    
            goto L_8018B860;
    }
    // 0x8018B82C: nop

    // 0x8018B830: jal         0x800B8DD0
    // 0x8018B834: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    RCP_SetupDL(rdram, ctx);
        goto after_17;
    // 0x8018B834: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_17:
    // 0x8018B838: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018B83C: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8018B840: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8018B844: lui         $t8, 0xFF00
    ctx->r24 = S32(0XFF00 << 16);
    // 0x8018B848: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x8018B84C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018B850: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8018B854: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018B858: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018B85C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8018B860:
    // 0x8018B860: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018B864: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8018B868: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8018B86C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8018B870: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B874: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018B878: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8018B87C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8018B880: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8018B884: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8018B888: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018B88C: jal         0x80005740
    // 0x8018B890: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_18;
    // 0x8018B890: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_18:
    // 0x8018B894: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018B898: jal         0x80005740
    // 0x8018B89C: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x8018B89C: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_19:
L_8018B8A0:
    // 0x8018B8A0: b           L_8018B8AC
    // 0x8018B8A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018B8AC;
    // 0x8018B8A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018B8A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018B8AC:
    // 0x8018B8AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018B8B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018B8B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018B8B8: jr          $ra
    // 0x8018B8BC: nop

    return;
    // 0x8018B8BC: nop

;}
RECOMP_FUNC void Andross_AndBrain_HandleDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188A4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80188A50: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80188A54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80188A58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188A5C: lh          $t6, 0x64($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X64);
    // 0x80188A60: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80188A64: slti        $at, $t6, 0x15
    ctx->r1 = SIGNED(ctx->r14) < 0X15 ? 1 : 0;
    // 0x80188A68: bnel        $at, $zero, L_80188A78
    if (ctx->r1 != 0) {
        // 0x80188A6C: lb          $t8, 0x62($s0)
        ctx->r24 = MEM_B(ctx->r16, 0X62);
            goto L_80188A78;
    }
    goto skip_0;
    // 0x80188A6C: lb          $t8, 0x62($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X62);
    skip_0:
    // 0x80188A70: sh          $t7, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r15;
    // 0x80188A74: lb          $t8, 0x62($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X62);
L_80188A78:
    // 0x80188A78: beql        $t8, $zero, L_80188CA8
    if (ctx->r24 == 0) {
        // 0x80188A7C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80188CA8;
    }
    goto skip_1;
    // 0x80188A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x80188A80: lh          $t9, 0x4E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4E);
    // 0x80188A84: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
    // 0x80188A88: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80188A8C: beq         $at, $zero, L_80188CA4
    if (ctx->r1 == 0) {
        // 0x80188A90: lui         $at, 0x437A
        ctx->r1 = S32(0X437A << 16);
            goto L_80188CA4;
    }
    // 0x80188A90: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80188A94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188A98: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80188A9C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80188AA0: nop

    // 0x80188AA4: bc1tl       L_80188CA8
    if (c1cs) {
        // 0x80188AA8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80188CA8;
    }
    goto skip_2;
    // 0x80188AA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80188AAC: lh          $v0, 0x66($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X66);
    // 0x80188AB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188AB4: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80188AB8: beq         $v0, $zero, L_80188AD8
    if (ctx->r2 == 0) {
        // 0x80188ABC: addiu       $t2, $zero, 0x1E
        ctx->r10 = ADD32(0, 0X1E);
            goto L_80188AD8;
    }
    // 0x80188ABC: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80188AC0: beq         $v0, $at, L_80188AE4
    if (ctx->r2 == ctx->r1) {
        // 0x80188AC4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80188AE4;
    }
    // 0x80188AC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80188AC8: beql        $v0, $at, L_80188AE8
    if (ctx->r2 == ctx->r1) {
        // 0x80188ACC: lh          $t3, 0x90($s0)
        ctx->r11 = MEM_H(ctx->r16, 0X90);
            goto L_80188AE8;
    }
    goto skip_3;
    // 0x80188ACC: lh          $t3, 0x90($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X90);
    skip_3:
    // 0x80188AD0: b           L_80188C20
    // 0x80188AD4: lh          $t6, 0x90($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X90);
        goto L_80188C20;
    // 0x80188AD4: lh          $t6, 0x90($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X90);
L_80188AD8:
    // 0x80188AD8: sh          $t1, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r9;
    // 0x80188ADC: b           L_80188CA4
    // 0x80188AE0: sh          $t2, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r10;
        goto L_80188CA4;
    // 0x80188AE0: sh          $t2, 0x96($s0)
    MEM_H(0X96, ctx->r16) = ctx->r10;
L_80188AE4:
    // 0x80188AE4: lh          $t3, 0x90($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X90);
L_80188AE8:
    // 0x80188AE8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188AEC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188AF0: bne         $t3, $zero, L_80188CA4
    if (ctx->r11 != 0) {
        // 0x80188AF4: addiu       $t4, $zero, 0xA
        ctx->r12 = ADD32(0, 0XA);
            goto L_80188CA4;
    }
    // 0x80188AF4: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80188AF8: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80188AFC: sh          $t4, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = ctx->r12;
    // 0x80188B00: sh          $t5, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = ctx->r13;
    // 0x80188B04: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80188B08: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80188B0C: lui         $a0, 0x2943
    ctx->r4 = S32(0X2943 << 16);
    // 0x80188B10: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x80188B14: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80188B18: ori         $a0, $a0, 0x500F
    ctx->r4 = ctx->r4 | 0X500F;
    // 0x80188B1C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80188B20: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188B24: jal         0x80019218
    // 0x80188B28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80188B28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80188B2C: lh          $t7, 0x60($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X60);
    // 0x80188B30: lh          $t8, 0x64($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X64);
    // 0x80188B34: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188B38: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188B3C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80188B40: sh          $t9, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r25;
    // 0x80188B44: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x80188B48: beql        $v0, $zero, L_80188CA8
    if (ctx->r2 == 0) {
        // 0x80188B4C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80188CA8;
    }
    goto skip_4;
    // 0x80188B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80188B50: bgtz        $v0, L_80188CA4
    if (SIGNED(ctx->r2) > 0) {
        // 0x80188B54: addiu       $t1, $zero, 0x8
        ctx->r9 = ADD32(0, 0X8);
            goto L_80188CA4;
    }
    // 0x80188B54: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x80188B58: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80188B5C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80188B60: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80188B64: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x80188B68: sh          $t1, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = ctx->r9;
    // 0x80188B6C: ori         $a0, $a0, 0xD09A
    ctx->r4 = ctx->r4 | 0XD09A;
    // 0x80188B70: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80188B74: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80188B78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80188B7C: jal         0x80019218
    // 0x80188B80: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80188B80: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x80188B84: jal         0x80042EC0
    // 0x80188B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Boss_AwardBonus(rdram, ctx);
        goto after_2;
    // 0x80188B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80188B8C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80188B90: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x80188B94: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80188B98: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80188B9C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x80188BA0: sw          $zero, 0x1C8($t3)
    MEM_W(0X1C8, ctx->r11) = 0;
    // 0x80188BA4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80188BA8: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80188BAC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80188BB0: addiu       $v1, $v1, 0x7A48
    ctx->r3 = ADD32(ctx->r3, 0X7A48);
    // 0x80188BB4: sh          $t4, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r12;
    // 0x80188BB8: sh          $v0, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r2;
    // 0x80188BBC: sh          $v0, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = ctx->r2;
    // 0x80188BC0: sh          $t5, 0x94($s0)
    MEM_H(0X94, ctx->r16) = ctx->r13;
    // 0x80188BC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188BC8: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80188BCC: lwc1        $f10, 0x6BF0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6BF0);
    // 0x80188BD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80188BD4: lui         $a1, 0x1103
    ctx->r5 = S32(0X1103 << 16);
    // 0x80188BD8: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x80188BDC: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x80188BE0: ori         $a1, $a1, 0x4074
    ctx->r5 = ctx->r5 | 0X4074;
    // 0x80188BE4: jal         0x8001A55C
    // 0x80188BE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_3;
    // 0x80188BE8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80188BEC: lui         $a1, 0x3140
    ctx->r5 = S32(0X3140 << 16);
    // 0x80188BF0: ori         $a1, $a1, 0x8097
    ctx->r5 = ctx->r5 | 0X8097;
    // 0x80188BF4: jal         0x8001A55C
    // 0x80188BF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_4;
    // 0x80188BF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x80188BFC: lui         $a0, 0x1001
    ctx->r4 = S32(0X1001 << 16);
    // 0x80188C00: jal         0x800182F4
    // 0x80188C04: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_5;
    // 0x80188C04: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_5:
    // 0x80188C08: lui         $a0, 0x1101
    ctx->r4 = S32(0X1101 << 16);
    // 0x80188C0C: jal         0x800182F4
    // 0x80188C10: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_6;
    // 0x80188C10: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_6:
    // 0x80188C14: b           L_80188CA8
    // 0x80188C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80188CA8;
    // 0x80188C18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80188C1C: lh          $t6, 0x90($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X90);
L_80188C20:
    // 0x80188C20: bnel        $t6, $zero, L_80188CA8
    if (ctx->r14 != 0) {
        // 0x80188C24: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80188CA8;
    }
    goto skip_5;
    // 0x80188C24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80188C28: lh          $t7, 0x98($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X98);
    // 0x80188C2C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80188C30: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x80188C34: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80188C38: sh          $t8, 0x98($s0)
    MEM_H(0X98, ctx->r16) = ctx->r24;
    // 0x80188C3C: lh          $t9, 0x98($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X98);
    // 0x80188C40: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80188C44: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80188C48: slti        $at, $t9, 0x6
    ctx->r1 = SIGNED(ctx->r25) < 0X6 ? 1 : 0;
    // 0x80188C4C: bnel        $at, $zero, L_80188CA8
    if (ctx->r1 != 0) {
        // 0x80188C50: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80188CA8;
    }
    goto skip_6;
    // 0x80188C50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_6:
    // 0x80188C54: sh          $zero, 0x98($s0)
    MEM_H(0X98, ctx->r16) = 0;
    // 0x80188C58: sh          $t1, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r9;
    // 0x80188C5C: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    // 0x80188C60: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80188C64: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188C68: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80188C6C: lwc1        $f16, 0x74($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X74);
    // 0x80188C70: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188C74: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80188C78: swc1        $f16, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f16.u32l;
    // 0x80188C7C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80188C80: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x80188C84: ori         $a0, $a0, 0xB096
    ctx->r4 = ctx->r4 | 0XB096;
    // 0x80188C88: lwc1        $f18, 0x138($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X138);
    // 0x80188C8C: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x80188C90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80188C94: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x80188C98: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80188C9C: jal         0x80019218
    // 0x80188CA0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x80188CA0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_7:
L_80188CA4:
    // 0x80188CA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80188CA8:
    // 0x80188CA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80188CAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80188CB0: jr          $ra
    // 0x80188CB4: nop

    return;
    // 0x80188CB4: nop

;}
RECOMP_FUNC void Title_RankingData_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187E28: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80187E2C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80187E30: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80187E34: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80187E38: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80187E3C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80187E40: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80187E44: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80187E48: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80187E4C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80187E50: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80187E54: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80187E58: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80187E5C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80187E60: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80187E64: jal         0x800B8DD0
    // 0x80187E68: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80187E68: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x80187E6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187E70: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80187E74: lui         $s6, 0xFA00
    ctx->r22 = S32(0XFA00 << 16);
    // 0x80187E78: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80187E7C: lui         $t7, 0xFFFF
    ctx->r15 = S32(0XFFFF << 16);
    // 0x80187E80: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x80187E84: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80187E88: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80187E8C: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80187E90: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x80187E94: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80187E98: addiu       $t8, $t8, 0x6D70
    ctx->r24 = ADD32(ctx->r24, 0X6D70);
    // 0x80187E9C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187EA0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80187EA4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80187EA8: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    // 0x80187EAC: jal         0x800A1200
    // 0x80187EB0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_1;
    // 0x80187EB0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_1:
    // 0x80187EB4: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80187EB8: addiu       $t9, $t9, 0x6D78
    ctx->r25 = ADD32(ctx->r25, 0X6D78);
    // 0x80187EBC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187EC0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80187EC4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80187EC8: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    // 0x80187ECC: jal         0x800A1200
    // 0x80187ED0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_2;
    // 0x80187ED0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_2:
    // 0x80187ED4: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80187ED8: addiu       $t0, $t0, 0x6D80
    ctx->r8 = ADD32(ctx->r8, 0X6D80);
    // 0x80187EDC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187EE0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80187EE4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80187EE8: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80187EEC: jal         0x800A1200
    // 0x80187EF0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_3;
    // 0x80187EF0: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    after_3:
    // 0x80187EF4: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x80187EF8: addiu       $fp, $fp, -0x7D78
    ctx->r30 = ADD32(ctx->r30, -0X7D78);
    // 0x80187EFC: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x80187F00: addiu       $s1, $zero, 0x37
    ctx->r17 = ADD32(0, 0X37);
    // 0x80187F04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80187F08: blez        $t1, L_80187FDC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80187F0C: lui         $s5, 0x801C
        ctx->r21 = S32(0X801C << 16);
            goto L_80187FDC;
    }
    // 0x80187F0C: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80187F10: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80187F14: addiu       $s3, $s3, -0x7DE0
    ctx->r19 = ADD32(ctx->r19, -0X7DE0);
    // 0x80187F18: addiu       $s5, $s5, -0x7DB8
    ctx->r21 = ADD32(ctx->r21, -0X7DB8);
    // 0x80187F1C: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
L_80187F20:
    // 0x80187F20: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80187F24: addiu       $s4, $v1, 0x1
    ctx->r20 = ADD32(ctx->r3, 0X1);
    // 0x80187F28: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80187F2C: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x80187F30: sw          $s7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r23;
    // 0x80187F34: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x80187F38: jal         0x8008BCBC
    // 0x80187F3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    HUD_CountDigits(rdram, ctx);
        goto after_4;
    // 0x80187F3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_4:
    // 0x80187F40: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x80187F44: addiu       $t4, $zero, 0x71
    ctx->r12 = ADD32(0, 0X71);
    // 0x80187F48: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x80187F4C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80187F50: jal         0x8009FEA0
    // 0x80187F54: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_5;
    // 0x80187F54: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_5:
    // 0x80187F58: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80187F5C: lui         $t6, 0xFFFF
    ctx->r14 = S32(0XFFFF << 16);
    // 0x80187F60: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x80187F64: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80187F68: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x80187F6C: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80187F70: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x80187F74: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187F78: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80187F7C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80187F80: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80187F84: jal         0x800A1200
    // 0x80187F88: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_6;
    // 0x80187F88: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_6:
    // 0x80187F8C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x80187F90: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80187F94: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80187F98: sw          $s7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r23;
    // 0x80187F9C: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x80187FA0: jal         0x8008BCBC
    // 0x80187FA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    HUD_CountDigits(rdram, ctx);
        goto after_7;
    // 0x80187FA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_7:
    // 0x80187FA8: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x80187FAC: addiu       $t9, $zero, 0xDB
    ctx->r25 = ADD32(0, 0XDB);
    // 0x80187FB0: subu        $a0, $t9, $t8
    ctx->r4 = SUB32(ctx->r25, ctx->r24);
    // 0x80187FB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80187FB8: jal         0x8009FEA0
    // 0x80187FBC: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_8;
    // 0x80187FBC: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    after_8:
    // 0x80187FC0: lw          $t0, 0x0($fp)
    ctx->r8 = MEM_W(ctx->r30, 0X0);
    // 0x80187FC4: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x80187FC8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80187FCC: slt         $at, $s4, $t0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80187FD0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80187FD4: bne         $at, $zero, L_80187F20
    if (ctx->r1 != 0) {
        // 0x80187FD8: addiu       $s1, $s1, 0x11
        ctx->r17 = ADD32(ctx->r17, 0X11);
            goto L_80187F20;
    }
    // 0x80187FD8: addiu       $s1, $s1, 0x11
    ctx->r17 = ADD32(ctx->r17, 0X11);
L_80187FDC:
    // 0x80187FDC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80187FE0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80187FE4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80187FE8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80187FEC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80187FF0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80187FF4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80187FF8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80187FFC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80188000: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80188004: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80188008: jr          $ra
    // 0x8018800C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8018800C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Map_PlanetCleared2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A7D3C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801A7D40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A7D44: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A7D48: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801A7D4C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801A7D50: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801A7D54: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x801A7D58: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x801A7D5C: jal         0x80004EB0
    // 0x801A7D60: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801A7D60: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801A7D64: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801A7D68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A7D6C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x801A7D70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A7D74: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801A7D78: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A7D7C: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801A7D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7D84: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A7D88: jal         0x80005708
    // 0x801A7D8C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A7D8C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801A7D90: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x801A7D94: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A7D98: addiu       $t7, $t7, -0x25A0
    ctx->r15 = ADD32(ctx->r15, -0X25A0);
    // 0x801A7D9C: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x801A7DA0: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x801A7DA4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x801A7DA8: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x801A7DAC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A7DB0: jal         0x80005754
    // 0x801A7DB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_2;
    // 0x801A7DB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x801A7DB8: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x801A7DBC: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A7DC0: addiu       $t9, $t9, -0x1508
    ctx->r25 = ADD32(ctx->r25, -0X1508);
    // 0x801A7DC4: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x801A7DC8: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x801A7DCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7DD0: lwc1        $f18, 0x799C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X799C);
    // 0x801A7DD4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A7DD8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801A7DDC: or          $s1, $t8, $zero
    ctx->r17 = ctx->r24 | 0;
    // 0x801A7DE0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A7DE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A7DE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A7DEC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A7DF0: jal         0x80005E90
    // 0x801A7DF4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A7DF4: nop

    after_3:
    // 0x801A7DF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A7DFC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x801A7E00: addu        $a1, $a1, $s1
    ctx->r5 = ADD32(ctx->r5, ctx->r17);
    // 0x801A7E04: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801A7E08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A7E0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A7E10: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801A7E14: lw          $a1, -0x48($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X48);
    // 0x801A7E18: jal         0x80005B00
    // 0x801A7E1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x801A7E1C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x801A7E20: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801A7E24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7E28: lwc1        $f10, 0x79A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x801A7E2C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x801A7E30: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A7E34: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A7E38: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x801A7E3C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A7E40: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A7E44: jal         0x80005E90
    // 0x801A7E48: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x801A7E48: nop

    after_5:
    // 0x801A7E4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A7E50: jal         0x80006EB8
    // 0x801A7E54: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x801A7E54: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_6:
    // 0x801A7E58: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x801A7E5C: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A7E60: addiu       $t3, $t3, -0x1A60
    ctx->r11 = ADD32(ctx->r11, -0X1A60);
    // 0x801A7E64: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801A7E68: jal         0x80005680
    // 0x801A7E6C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Matrix_Copy(rdram, ctx);
        goto after_7;
    // 0x801A7E6C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_7:
    // 0x801A7E70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A7E74: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x801A7E78: lwc1        $f18, -0x1548($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1548);
    // 0x801A7E7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7E80: lwc1        $f4, 0x79A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79A4);
    // 0x801A7E84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A7E88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A7E8C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801A7E90: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A7E94: jal         0x80005FE0
    // 0x801A7E98: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x801A7E98: nop

    after_8:
    // 0x801A7E9C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A7EA0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A7EA4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801A7EA8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A7EAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A7EB0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A7EB4: jal         0x80005C34
    // 0x801A7EB8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_9;
    // 0x801A7EB8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_9:
    // 0x801A7EBC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A7EC0: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801A7EC4: jal         0x80006970
    // 0x801A7EC8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x801A7EC8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_10:
    // 0x801A7ECC: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A7ED0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A7ED4: addu        $at, $at, $s1
    ctx->r1 = ADD32(ctx->r1, ctx->r17);
    // 0x801A7ED8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A7EDC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A7EE0: jal         0x80006EB8
    // 0x801A7EE4: swc1        $f8, -0x15E8($at)
    MEM_W(-0X15E8, ctx->r1) = ctx->f8.u32l;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x801A7EE4: swc1        $f8, -0x15E8($at)
    MEM_W(-0X15E8, ctx->r1) = ctx->f8.u32l;
    after_11:
    // 0x801A7EE8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x801A7EEC: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A7EF0: addiu       $t6, $t6, -0x1E20
    ctx->r14 = ADD32(ctx->r14, -0X1E20);
    // 0x801A7EF4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801A7EF8: jal         0x80005680
    // 0x801A7EFC: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    Matrix_Copy(rdram, ctx);
        goto after_12;
    // 0x801A7EFC: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_12:
    // 0x801A7F00: jal         0x80005740
    // 0x801A7F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x801A7F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x801A7F08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A7F0C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801A7F10: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801A7F14: jr          $ra
    // 0x801A7F18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801A7F18: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Option_Vs_StartMatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A298: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A29C: lwc1        $f6, -0x6E14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6E14);
    // 0x8019A2A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019A2A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019A2A8: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8019A2AC: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8019A2B0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8019A2B4: bc1f        L_8019A2D8
    if (!c1cs) {
        // 0x8019A2B8: nop
    
            goto L_8019A2D8;
    }
    // 0x8019A2B8: nop

    // 0x8019A2BC: sw          $t6, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r14;
    // 0x8019A2C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019A2C4: sw          $t7, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r15;
    // 0x8019A2C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019A2CC: sw          $zero, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = 0;
    // 0x8019A2D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019A2D4: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
L_8019A2D8:
    // 0x8019A2D8: jr          $ra
    // 0x8019A2DC: nop

    return;
    // 0x8019A2DC: nop

;}
RECOMP_FUNC void Option_PlanetTextures_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192598: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8019259C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801925A0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x801925A4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801925A8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801925AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801925B0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801925B4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801925B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801925BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801925C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801925C4: sw          $zero, -0x6C18($at)
    MEM_W(-0X6C18, ctx->r1) = 0;
    // 0x801925C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801925CC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801925D0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801925D4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801925D8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801925DC: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801925E0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801925E4: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801925E8: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801925EC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801925F0: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x801925F4: sw          $zero, -0x6C14($at)
    MEM_W(-0X6C14, ctx->r1) = 0;
    // 0x801925F8: addiu       $s4, $s4, -0x47F0
    ctx->r20 = ADD32(ctx->r20, -0X47F0);
    // 0x801925FC: addiu       $v0, $v0, -0x6BF0
    ctx->r2 = ADD32(ctx->r2, -0X6BF0);
    // 0x80192600: addiu       $t2, $t2, -0x4BF0
    ctx->r10 = ADD32(ctx->r10, -0X4BF0);
    // 0x80192604: addiu       $t1, $t1, -0x6FF0
    ctx->r9 = ADD32(ctx->r9, -0X6FF0);
    // 0x80192608: addiu       $t0, $t0, 0x6C10
    ctx->r8 = ADD32(ctx->r8, 0X6C10);
    // 0x8019260C: addiu       $a3, $a3, 0x4810
    ctx->r7 = ADD32(ctx->r7, 0X4810);
    // 0x80192610: addiu       $a2, $a2, 0x2410
    ctx->r6 = ADD32(ctx->r6, 0X2410);
    // 0x80192614: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80192618: addiu       $a0, $a0, -0x23F0
    ctx->r4 = ADD32(ctx->r4, -0X23F0);
    // 0x8019261C: addiu       $v1, $v1, -0x47F0
    ctx->r3 = ADD32(ctx->r3, -0X47F0);
    // 0x80192620: addiu       $s3, $zero, 0x34
    ctx->r19 = ADD32(0, 0X34);
    // 0x80192624: addiu       $s2, $zero, 0x44
    ctx->r18 = ADD32(0, 0X44);
    // 0x80192628: addiu       $s1, $zero, 0x52
    ctx->r17 = ADD32(0, 0X52);
    // 0x8019262C: addiu       $s0, $zero, 0x37
    ctx->r16 = ADD32(0, 0X37);
    // 0x80192630: addiu       $ra, $zero, 0x51
    ctx->r31 = ADD32(0, 0X51);
    // 0x80192634: addiu       $t5, $zero, 0x4B
    ctx->r13 = ADD32(0, 0X4B);
    // 0x80192638: addiu       $t4, $zero, 0x54
    ctx->r12 = ADD32(0, 0X54);
    // 0x8019263C: addiu       $t3, $zero, 0x6A
    ctx->r11 = ADD32(0, 0X6A);
L_80192640:
    // 0x80192640: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80192644: sltu        $at, $v0, $s4
    ctx->r1 = ctx->r2 < ctx->r20 ? 1 : 0;
    // 0x80192648: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8019264C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80192650: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80192654: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80192658: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8019265C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80192660: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80192664: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80192668: sb          $t3, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r11;
    // 0x8019266C: sb          $t4, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r12;
    // 0x80192670: sb          $t5, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r13;
    // 0x80192674: sb          $ra, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r31;
    // 0x80192678: sb          $s0, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r16;
    // 0x8019267C: sb          $s1, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r17;
    // 0x80192680: sb          $s2, -0x1($t1)
    MEM_B(-0X1, ctx->r9) = ctx->r18;
    // 0x80192684: sb          $s3, -0x1($t2)
    MEM_B(-0X1, ctx->r10) = ctx->r19;
    // 0x80192688: bne         $at, $zero, L_80192640
    if (ctx->r1 != 0) {
        // 0x8019268C: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_80192640;
    }
    // 0x8019268C: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x80192690: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x80192694: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x80192698: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8019269C: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x801926A0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x801926A4: lui         $s3, 0xFF
    ctx->r19 = S32(0XFF << 16);
    // 0x801926A8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801926AC: ori         $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 | 0XFFFF;
    // 0x801926B0: addiu       $s4, $s4, 0x1FD0
    ctx->r20 = ADD32(ctx->r20, 0X1FD0);
    // 0x801926B4: addiu       $s6, $s6, 0x68F8
    ctx->r22 = ADD32(ctx->r22, 0X68F8);
    // 0x801926B8: addiu       $s1, $s1, 0x68D4
    ctx->r17 = ADD32(ctx->r17, 0X68D4);
    // 0x801926BC: addiu       $s2, $s2, 0x68B0
    ctx->r18 = ADD32(ctx->r18, 0X68B0);
    // 0x801926C0: addiu       $s0, $s0, -0x27E8
    ctx->r16 = ADD32(ctx->r16, -0X27E8);
    // 0x801926C4: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
L_801926C8:
    // 0x801926C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801926CC: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x801926D0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801926D4: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x801926D8: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x801926DC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801926E0: addu        $t7, $s4, $t9
    ctx->r15 = ADD32(ctx->r20, ctx->r25);
    // 0x801926E4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801926E8: and         $t6, $v0, $s3
    ctx->r14 = ctx->r2 & ctx->r19;
    // 0x801926EC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801926F0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801926F4: jal         0x801A07E8
    // 0x801926F8: addu        $a1, $t9, $s5
    ctx->r5 = ADD32(ctx->r25, ctx->r21);
    Map_Texture_Sphere(rdram, ctx);
        goto after_0;
    // 0x801926F8: addu        $a1, $t9, $s5
    ctx->r5 = ADD32(ctx->r25, ctx->r21);
    after_0:
    // 0x801926FC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80192700: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80192704: bne         $s1, $s6, L_801926C8
    if (ctx->r17 != ctx->r22) {
        // 0x80192708: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_801926C8;
    }
    // 0x80192708: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8019270C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80192710: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80192714: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80192718: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8019271C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80192720: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80192724: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80192728: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8019272C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80192730: jr          $ra
    // 0x80192734: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80192734: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Title_CsTakeOffSpace_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C644: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8018C648: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8018C64C: sw          $s7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r23;
    // 0x8018C650: sw          $s6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r22;
    // 0x8018C654: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x8018C658: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x8018C65C: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8018C660: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x8018C664: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8018C668: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8018C66C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x8018C670: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x8018C674: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8018C678: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8018C67C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8018C680: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018C684: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018C688: lw          $v1, -0x7D40($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D40);
    // 0x8018C68C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018C690: addiu       $s0, $s0, -0x7984
    ctx->r16 = ADD32(ctx->r16, -0X7984);
    // 0x8018C694: beq         $v1, $zero, L_8018C6C4
    if (ctx->r3 == 0) {
        // 0x8018C698: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018C6C4;
    }
    // 0x8018C698: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018C69C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018C6A0: beq         $v1, $at, L_8018C7BC
    if (ctx->r3 == ctx->r1) {
        // 0x8018C6A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018C7BC;
    }
    // 0x8018C6A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018C6A8: beq         $v1, $at, L_8018CA10
    if (ctx->r3 == ctx->r1) {
        // 0x8018C6AC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8018CA10;
    }
    // 0x8018C6AC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018C6B0: beq         $v0, $at, L_8018CA4C
    if (ctx->r2 == ctx->r1) {
        // 0x8018C6B4: lui         $t2, 0x801C
        ctx->r10 = S32(0X801C << 16);
            goto L_8018CA4C;
    }
    // 0x8018C6B4: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8018C6B8: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018C6BC: b           L_8018CA8C
    // 0x8018C6C0: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
        goto L_8018CA8C;
    // 0x8018C6C0: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
L_8018C6C4:
    // 0x8018C6C4: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x8018C6C8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8018C6CC: addiu       $s7, $s7, 0x5D34
    ctx->r23 = ADD32(ctx->r23, 0X5D34);
    // 0x8018C6D0: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8018C6D4: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x8018C6D8: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x8018C6DC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8018C6E0: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x8018C6E4: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x8018C6E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018C6EC: jal         0x80019218
    // 0x8018C6F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8018C6F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8018C6F4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018C6F8: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8018C6FC: lui         $a0, 0x3102
    ctx->r4 = S32(0X3102 << 16);
    // 0x8018C700: ori         $a0, $a0, 0x4059
    ctx->r4 = ctx->r4 | 0X4059;
    // 0x8018C704: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018C708: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018C70C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018C710: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x8018C714: jal         0x80019218
    // 0x8018C718: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8018C718: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_1:
    // 0x8018C71C: jal         0x8018C1C0
    // 0x8018C720: nop

    Title_CsTakeOffSpace_Setup(rdram, ctx);
        goto after_2;
    // 0x8018C720: nop

    after_2:
    // 0x8018C724: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018C728: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018C72C: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
    // 0x8018C730: addiu       $s1, $s1, -0x7D4C
    ctx->r17 = ADD32(ctx->r17, -0X7D4C);
    // 0x8018C734: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8018C738: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8018C73C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018C740: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C744: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018C748: sw          $t8, -0x796C($at)
    MEM_W(-0X796C, ctx->r1) = ctx->r24;
    // 0x8018C74C: addiu       $v0, $v0, -0x7B18
    ctx->r2 = ADD32(ctx->r2, -0X7B18);
    // 0x8018C750: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8018C754: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x8018C758: addiu       $t1, $zero, 0x2B
    ctx->r9 = ADD32(0, 0X2B);
    // 0x8018C75C: addiu       $t2, $zero, 0x3F
    ctx->r10 = ADD32(0, 0X3F);
    // 0x8018C760: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8018C764: sw          $t9, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r25;
    // 0x8018C768: sw          $t0, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->r8;
    // 0x8018C76C: sw          $t1, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->r9;
    // 0x8018C770: sw          $t2, 0x14C($v0)
    MEM_W(0X14C, ctx->r2) = ctx->r10;
    // 0x8018C774: addiu       $t3, $t3, -0x207C
    ctx->r11 = ADD32(ctx->r11, -0X207C);
    // 0x8018C778: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C77C: sw          $t3, -0x7D6C($at)
    MEM_W(-0X7D6C, ctx->r1) = ctx->r11;
    // 0x8018C780: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8018C784: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C788: sw          $zero, -0x7D68($at)
    MEM_W(-0X7D68, ctx->r1) = 0;
    // 0x8018C78C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C790: swc1        $f26, -0x7D74($at)
    MEM_W(-0X7D74, ctx->r1) = ctx->f26.u32l;
    // 0x8018C794: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C798: lwc1        $f4, 0x6FD8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FD8);
    // 0x8018C79C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8018C7A0: lw          $t4, -0x7D40($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D40);
    // 0x8018C7A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C7A8: swc1        $f4, -0x7D70($at)
    MEM_W(-0X7D70, ctx->r1) = ctx->f4.u32l;
    // 0x8018C7AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C7B0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8018C7B4: b           L_8018CA8C
    // 0x8018C7B8: sw          $t5, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r13;
        goto L_8018CA8C;
    // 0x8018C7B8: sw          $t5, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r13;
L_8018C7BC:
    // 0x8018C7BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C7C0: lwc1        $f30, 0x6FDC($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X6FDC);
    // 0x8018C7C4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018C7C8: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8018C7CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C7D0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018C7D4: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x8018C7D8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8018C7DC: addiu       $s7, $s7, 0x5D34
    ctx->r23 = ADD32(ctx->r23, 0X5D34);
    // 0x8018C7E0: addiu       $s0, $s0, -0x7B18
    ctx->r16 = ADD32(ctx->r16, -0X7B18);
    // 0x8018C7E4: lwc1        $f24, 0x6FE0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6FE0);
    // 0x8018C7E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8018C7EC:
    // 0x8018C7EC: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x8018C7F0: addiu       $s1, $s0, 0x4
    ctx->r17 = ADD32(ctx->r16, 0X4);
    // 0x8018C7F4: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x8018C7F8: blez        $v1, L_8018C80C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8018C7FC: lui         $t7, 0x801B
        ctx->r15 = S32(0X801B << 16);
            goto L_8018C80C;
    }
    // 0x8018C7FC: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8018C800: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8018C804: b           L_8018C974
    // 0x8018C808: sw          $t6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r14;
        goto L_8018C974;
    // 0x8018C808: sw          $t6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r14;
L_8018C80C:
    // 0x8018C80C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018C810: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8018C814: addiu       $t9, $t9, -0x1BAC
    ctx->r25 = ADD32(ctx->r25, -0X1BAC);
    // 0x8018C818: addiu       $t8, $t8, -0x1BCC
    ctx->r24 = ADD32(ctx->r24, -0X1BCC);
    // 0x8018C81C: addiu       $t7, $t7, -0x1BBC
    ctx->r15 = ADD32(ctx->r15, -0X1BBC);
    // 0x8018C820: addu        $s4, $v0, $t7
    ctx->r20 = ADD32(ctx->r2, ctx->r15);
    // 0x8018C824: addu        $s5, $v0, $t8
    ctx->r21 = ADD32(ctx->r2, ctx->r24);
    // 0x8018C828: addu        $s2, $v0, $t9
    ctx->r18 = ADD32(ctx->r2, ctx->r25);
    // 0x8018C82C: bne         $v1, $zero, L_8018C86C
    if (ctx->r3 != 0) {
        // 0x8018C830: addiu       $s6, $s0, 0x8
        ctx->r22 = ADD32(ctx->r16, 0X8);
            goto L_8018C86C;
    }
    // 0x8018C830: addiu       $s6, $s0, 0x8
    ctx->r22 = ADD32(ctx->r16, 0X8);
    // 0x8018C834: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8018C838: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8018C83C: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x8018C840: ori         $a0, $a0, 0x1
    ctx->r4 = ctx->r4 | 0X1;
    // 0x8018C844: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018C848: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    // 0x8018C84C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018C850: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x8018C854: jal         0x80019218
    // 0x8018C858: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8018C858: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    after_3:
    // 0x8018C85C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8018C860: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018C864: sw          $t1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r9;
    // 0x8018C868: sw          $t2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r10;
L_8018C86C:
    // 0x8018C86C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018C870: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8018C874: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8018C878: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018C87C: jal         0x8009BC2C
    // 0x8018C880: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8018C880: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_4:
    // 0x8018C884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018C888: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x8018C88C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8018C890: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018C894: jal         0x8009BC2C
    // 0x8018C898: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8018C898: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_5:
    // 0x8018C89C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8018C8A0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8018C8A4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8018C8A8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018C8AC: jal         0x8009BC2C
    // 0x8018C8B0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8018C8B0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_6:
    // 0x8018C8B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C8B8: lwc1        $f8, 0x6FE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FE4);
    // 0x8018C8BC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018C8C0: lwc1        $f2, 0x0($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8018C8C4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018C8C8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018C8CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018C8D0: c.eq.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl == ctx->f2.fl;
    // 0x8018C8D4: nop

    // 0x8018C8D8: bc1f        L_8018C90C
    if (!c1cs) {
        // 0x8018C8DC: swc1        $f10, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
            goto L_8018C90C;
    }
    // 0x8018C8DC: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8018C8E0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018C8E4: lwc1        $f4, 0x6FE8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FE8);
    // 0x8018C8E8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018C8EC: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8018C8F0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018C8F4: c.lt.s      $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f8.fl < ctx->f26.fl;
    // 0x8018C8F8: nop

    // 0x8018C8FC: bc1fl       L_8018C910
    if (!c1cs) {
        // 0x8018C900: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8018C910;
    }
    goto skip_0;
    // 0x8018C900: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_0:
    // 0x8018C904: swc1        $f26, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f26.u32l;
    // 0x8018C908: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
L_8018C90C:
    // 0x8018C90C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_8018C910:
    // 0x8018C910: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8018C914: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018C918: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018C91C: lwc1        $f18, 0x0($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8018C920: sub.s       $f20, $f10, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8018C924: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018C928: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018C92C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8018C930: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8018C934: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018C938: sub.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8018C93C: mul.s       $f18, $f22, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8018C940: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C944: jal         0x80005100
    // 0x8018C948: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_7;
    // 0x8018C948: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_7:
    // 0x8018C94C: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8018C950: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8018C954: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8018C958: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8018C95C: div.s       $f8, $f6, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f30.fl);
    // 0x8018C960: jal         0x80005100
    // 0x8018C964: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_8;
    // 0x8018C964: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    after_8:
    // 0x8018C968: mul.s       $f10, $f0, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8018C96C: div.s       $f16, $f10, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f30.fl);
    // 0x8018C970: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
L_8018C974:
    // 0x8018C974: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018C978: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018C97C: bne         $s3, $at, L_8018C7EC
    if (ctx->r19 != ctx->r1) {
        // 0x8018C980: addiu       $s0, $s0, 0x5C
        ctx->r16 = ADD32(ctx->r16, 0X5C);
            goto L_8018C7EC;
    }
    // 0x8018C980: addiu       $s0, $s0, 0x5C
    ctx->r16 = ADD32(ctx->r16, 0X5C);
    // 0x8018C984: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018C988: addiu       $s1, $s1, -0x7D4C
    ctx->r17 = ADD32(ctx->r17, -0X7D4C);
    // 0x8018C98C: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8018C990: addiu       $at, $zero, 0x7D
    ctx->r1 = ADD32(0, 0X7D);
    // 0x8018C994: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8018C998: bne         $t3, $at, L_8018C9A8
    if (ctx->r11 != ctx->r1) {
        // 0x8018C99C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8018C9A8;
    }
    // 0x8018C99C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018C9A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C9A4: sw          $t4, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r12;
L_8018C9A8:
    // 0x8018C9A8: lw          $t5, -0x7CC0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7CC0);
    // 0x8018C9AC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8018C9B0: bne         $t5, $at, L_8018C9F0
    if (ctx->r13 != ctx->r1) {
        // 0x8018C9B4: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_8018C9F0;
    }
    // 0x8018C9B4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018C9B8: addiu       $s0, $s0, -0x7984
    ctx->r16 = ADD32(ctx->r16, -0X7984);
    // 0x8018C9BC: lui         $a1, 0x1103
    ctx->r5 = S32(0X1103 << 16);
    // 0x8018C9C0: ori         $a1, $a1, 0x10
    ctx->r5 = ctx->r5 | 0X10;
    // 0x8018C9C4: jal         0x8001A55C
    // 0x8018C9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_9;
    // 0x8018C9C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8018C9CC: lui         $a1, 0x3102
    ctx->r5 = S32(0X3102 << 16);
    // 0x8018C9D0: ori         $a1, $a1, 0x4059
    ctx->r5 = ctx->r5 | 0X4059;
    // 0x8018C9D4: jal         0x8001A55C
    // 0x8018C9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_10;
    // 0x8018C9D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8018C9DC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8018C9E0: lw          $t6, -0x7D40($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D40);
    // 0x8018C9E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018C9E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018C9EC: sw          $t7, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r15;
L_8018C9F0:
    // 0x8018C9F0: jal         0x801912A0
    // 0x8018C9F4: nop

    Title_ScreenFade_Update(rdram, ctx);
        goto after_11;
    // 0x8018C9F4: nop

    after_11:
    // 0x8018C9F8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8018C9FC: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018CA00: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
    // 0x8018CA04: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8018CA08: b           L_8018CA8C
    // 0x8018CA0C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
        goto L_8018CA8C;
    // 0x8018CA0C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_8018CA10:
    // 0x8018CA10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018CA14: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x8018CA18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018CA1C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8018CA20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CA24: sw          $zero, -0x7960($at)
    MEM_W(-0X7960, ctx->r1) = 0;
    // 0x8018CA28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CA2C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x8018CA30: sw          $t0, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r8;
    // 0x8018CA34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CA38: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x8018CA3C: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018CA40: sw          $t1, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = ctx->r9;
    // 0x8018CA44: b           L_8018CA8C
    // 0x8018CA48: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
        goto L_8018CA8C;
    // 0x8018CA48: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
L_8018CA4C:
    // 0x8018CA4C: lw          $t2, -0x7D58($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D58);
    // 0x8018CA50: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CA54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018CA58: beq         $t2, $zero, L_8018CA6C
    if (ctx->r10 == 0) {
        // 0x8018CA5C: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_8018CA6C;
    }
    // 0x8018CA5C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8018CA60: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018CA64: b           L_8018CA8C
    // 0x8018CA68: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
        goto L_8018CA8C;
    // 0x8018CA68: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
L_8018CA6C:
    // 0x8018CA6C: sw          $zero, -0x7D40($at)
    MEM_W(-0X7D40, ctx->r1) = 0;
    // 0x8018CA70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CA74: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x8018CA78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CA7C: jal         0x8001DC6C
    // 0x8018CA80: sw          $zero, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = 0;
    Audio_SetAudioSpec(rdram, ctx);
        goto after_12;
    // 0x8018CA80: sw          $zero, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = 0;
    after_12:
    // 0x8018CA84: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8018CA88: addiu       $s2, $s2, 0x7BEC
    ctx->r18 = ADD32(ctx->r18, 0X7BEC);
L_8018CA8C:
    // 0x8018CA8C: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018CA90: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8018CA94: addiu       $s1, $s1, -0x7954
    ctx->r17 = ADD32(ctx->r17, -0X7954);
    // 0x8018CA98: addiu       $s0, $s0, -0x7958
    ctx->r16 = ADD32(ctx->r16, -0X7958);
    // 0x8018CA9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018CAA0: jal         0x80191798
    // 0x8018CAA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Title_GetCamRot(rdram, ctx);
        goto after_13;
    // 0x8018CAA4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_13:
    // 0x8018CAA8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018CAAC: jal         0x80191844
    // 0x8018CAB0: lwc1        $f14, 0x0($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X0);
    Title_SetCamUp(rdram, ctx);
        goto after_14;
    // 0x8018CAB0: lwc1        $f14, 0x0($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X0);
    after_14:
    // 0x8018CAB4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018CAB8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018CABC: lw          $a2, -0x7D70($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7D70);
    // 0x8018CAC0: lw          $a0, -0x7D6C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D6C);
    // 0x8018CAC4: jal         0x8018CC30
    // 0x8018CAC8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    Title_Cutscene_SetCamera(rdram, ctx);
        goto after_15;
    // 0x8018CAC8: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_15:
    // 0x8018CACC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CAD0: lwc1        $f12, -0x7938($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7938);
    // 0x8018CAD4: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8018CAD8: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8018CADC: addiu       $t4, $t4, -0x7D18
    ctx->r12 = ADD32(ctx->r12, -0X7D18);
    // 0x8018CAE0: addiu       $t3, $t3, -0x7D1C
    ctx->r11 = ADD32(ctx->r11, -0X7D1C);
    // 0x8018CAE4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018CAE8: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8018CAEC: addiu       $a3, $a3, -0x7D20
    ctx->r7 = ADD32(ctx->r7, -0X7D20);
    // 0x8018CAF0: lwc1        $f14, -0x7934($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7934);
    // 0x8018CAF4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018CAF8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8018CAFC: jal         0x80191674
    // 0x8018CB00: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    Title_SetLightRot(rdram, ctx);
        goto after_16;
    // 0x8018CB00: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_16:
    // 0x8018CB04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CB08: lwc1        $f12, 0x7978($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x8018CB0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CB10: lwc1        $f14, 0x7980($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x8018CB14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CB18: lwc1        $f18, 0x79B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x8018CB1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018CB20: lwc1        $f4, 0x79C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x8018CB24: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8018CB28: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018CB2C: lw          $a3, 0x79A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X79A0);
    // 0x8018CB30: lw          $a2, 0x7988($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7988);
    // 0x8018CB34: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8018CB38: jal         0x800B6F50
    // 0x8018CB3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_17;
    // 0x8018CB3C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_17:
    // 0x8018CB40: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8018CB44: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8018CB48: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8018CB4C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8018CB50: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018CB54: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8018CB58: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8018CB5C: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8018CB60: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x8018CB64: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x8018CB68: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8018CB6C: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8018CB70: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8018CB74: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8018CB78: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x8018CB7C: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x8018CB80: lw          $s6, 0x64($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X64);
    // 0x8018CB84: lw          $s7, 0x68($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X68);
    // 0x8018CB88: jr          $ra
    // 0x8018CB8C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8018CB8C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Option_VersusStage_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AAB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019AAB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019AABC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019AAC0: lw          $v0, -0x6C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6C30);
    // 0x8019AAC4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8019AAC8: beq         $v0, $at, L_8019AAE8
    if (ctx->r2 == ctx->r1) {
        // 0x8019AACC: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_8019AAE8;
    }
    // 0x8019AACC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8019AAD0: beq         $v0, $at, L_8019AB00
    if (ctx->r2 == ctx->r1) {
        // 0x8019AAD4: addiu       $at, $zero, 0x1E
        ctx->r1 = ADD32(0, 0X1E);
            goto L_8019AB00;
    }
    // 0x8019AAD4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8019AAD8: beq         $v0, $at, L_8019AAF8
    if (ctx->r2 == ctx->r1) {
        // 0x8019AADC: nop
    
            goto L_8019AAF8;
    }
    // 0x8019AADC: nop

    // 0x8019AAE0: b           L_8019AB00
    // 0x8019AAE4: nop

        goto L_8019AB00;
    // 0x8019AAE4: nop

L_8019AAE8:
    // 0x8019AAE8: jal         0x8019AB30
    // 0x8019AAEC: nop

    Option_VsPointMatch_Draw(rdram, ctx);
        goto after_0;
    // 0x8019AAEC: nop

    after_0:
    // 0x8019AAF0: b           L_8019AB00
    // 0x8019AAF4: nop

        goto L_8019AB00;
    // 0x8019AAF4: nop

L_8019AAF8:
    // 0x8019AAF8: jal         0x8019AD84
    // 0x8019AAFC: nop

    Option_VsTimeTrial_Draw(rdram, ctx);
        goto after_1;
    // 0x8019AAFC: nop

    after_1:
L_8019AB00:
    // 0x8019AB00: jal         0x8019AFFC
    // 0x8019AB04: nop

    Option_VsStageSelect_Draw(rdram, ctx);
        goto after_2;
    // 0x8019AB04: nop

    after_2:
    // 0x8019AB08: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019AB0C: lw          $t6, -0x6CC4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6CC4);
    // 0x8019AB10: beql        $t6, $zero, L_8019AB24
    if (ctx->r14 == 0) {
        // 0x8019AB14: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8019AB24;
    }
    goto skip_0;
    // 0x8019AB14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8019AB18: jal         0x8019B5AC
    // 0x8019AB1C: nop

    Option_VsOKConfirm_Draw(rdram, ctx);
        goto after_3;
    // 0x8019AB1C: nop

    after_3:
    // 0x8019AB20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8019AB24:
    // 0x8019AB24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019AB28: jr          $ra
    // 0x8019AB2C: nop

    return;
    // 0x8019AB2C: nop

;}
RECOMP_FUNC void Option_VsConfirmSelection(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A954: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019A958: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019A95C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A960: lwc1        $f6, -0x6E14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6E14);
    // 0x8019A964: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019A968: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019A96C: addiu       $t0, $t0, -0x6E10
    ctx->r8 = ADD32(ctx->r8, -0X6E10);
    // 0x8019A970: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8019A974: nop

    // 0x8019A978: bc1fl       L_8019AAA8
    if (!c1cs) {
        // 0x8019A97C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8019AAA8;
    }
    goto skip_0;
    // 0x8019A97C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8019A980: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8019A984: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A988: addiu       $v0, $v0, -0x6ED4
    ctx->r2 = ADD32(ctx->r2, -0X6ED4);
    // 0x8019A98C: beq         $t6, $zero, L_8019A9A8
    if (ctx->r14 == 0) {
        // 0x8019A990: nop
    
            goto L_8019A9A8;
    }
    // 0x8019A990: nop

    // 0x8019A994: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8019A998: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x8019A99C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8019A9A0: b           L_8019AAA4
    // 0x8019A9A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_8019AAA4;
    // 0x8019A9A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8019A9A8:
    // 0x8019A9A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8019A9AC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8019A9B0: addiu       $a2, $a2, -0x2768
    ctx->r6 = ADD32(ctx->r6, -0X2768);
    // 0x8019A9B4: addiu       $a0, $a0, -0x2750
    ctx->r4 = ADD32(ctx->r4, -0X2750);
    // 0x8019A9B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8019A9BC: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8019A9C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_8019A9C4:
    // 0x8019A9C4: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8019A9C8: beql        $t9, $zero, L_8019AA9C
    if (ctx->r25 == 0) {
        // 0x8019A9CC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8019AA9C;
    }
    goto skip_1;
    // 0x8019A9CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x8019A9D0: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019A9D4: mflo        $t1
    ctx->r9 = lo;
    // 0x8019A9D8: addu        $t2, $a2, $t1
    ctx->r10 = ADD32(ctx->r6, ctx->r9);
    // 0x8019A9DC: lhu         $v0, 0x0($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0X0);
    // 0x8019A9E0: andi        $t3, $v0, 0x8000
    ctx->r11 = ctx->r2 & 0X8000;
    // 0x8019A9E4: beql        $t3, $zero, L_8019AA34
    if (ctx->r11 == 0) {
        // 0x8019A9E8: andi        $t5, $v0, 0x4000
        ctx->r13 = ctx->r2 & 0X4000;
            goto L_8019AA34;
    }
    goto skip_2;
    // 0x8019A9E8: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    skip_2:
    // 0x8019A9EC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A9F0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8019A9F4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A9F8: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8019A9FC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019AA00: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019AA04: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019AA08: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019AA0C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8019AA10: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019AA14: jal         0x80019218
    // 0x8019AA18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019AA18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8019AA1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019AA20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019AA24: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AA28: b           L_8019AAA4
    // 0x8019AA2C: swc1        $f8, -0x6E14($at)
    MEM_W(-0X6E14, ctx->r1) = ctx->f8.u32l;
        goto L_8019AAA4;
    // 0x8019AA2C: swc1        $f8, -0x6E14($at)
    MEM_W(-0X6E14, ctx->r1) = ctx->f8.u32l;
    // 0x8019AA30: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
L_8019AA34:
    // 0x8019AA34: beq         $t5, $zero, L_8019AA98
    if (ctx->r13 == 0) {
        // 0x8019AA38: lui         $t6, 0x800C
        ctx->r14 = S32(0X800C << 16);
            goto L_8019AA98;
    }
    // 0x8019AA38: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8019AA3C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019AA40: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019AA44: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019AA48: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019AA4C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8019AA50: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8019AA54: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019AA58: ori         $a0, $a0, 0x101D
    ctx->r4 = ctx->r4 | 0X101D;
    // 0x8019AA5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019AA60: jal         0x80019218
    // 0x8019AA64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019AA64: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8019AA68: jal         0x8019A080
    // 0x8019AA6C: nop

    Option_8019A080(rdram, ctx);
        goto after_2;
    // 0x8019AA6C: nop

    after_2:
    // 0x8019AA70: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AA74: sw          $zero, -0x6CC4($at)
    MEM_W(-0X6CC4, ctx->r1) = 0;
    // 0x8019AA78: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019AA7C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019AA80: addiu       $v0, $v0, -0x6ED4
    ctx->r2 = ADD32(ctx->r2, -0X6ED4);
    // 0x8019AA84: sw          $zero, -0x6E10($at)
    MEM_W(-0X6E10, ctx->r1) = 0;
    // 0x8019AA88: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8019AA8C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8019AA90: b           L_8019AAA4
    // 0x8019AA94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
        goto L_8019AAA4;
    // 0x8019AA94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_8019AA98:
    // 0x8019AA98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8019AA9C:
    // 0x8019AA9C: bne         $v1, $a1, L_8019A9C4
    if (ctx->r3 != ctx->r5) {
        // 0x8019AAA0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8019A9C4;
    }
    // 0x8019AAA0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8019AAA4:
    // 0x8019AAA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019AAA8:
    // 0x8019AAA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019AAAC: jr          $ra
    // 0x8019AAB0: nop

    return;
    // 0x8019AAB0: nop

;}
