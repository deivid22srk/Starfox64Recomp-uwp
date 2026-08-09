#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Bolse_ActorCsLaserShot_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ED44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018ED48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018ED4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018ED50: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8018ED54: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8018ED58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018ED5C: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_8018ED60:
    // 0x8018ED60: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8018ED64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018ED68: bne         $t6, $zero, L_8018EE30
    if (ctx->r14 != 0) {
        // 0x8018ED6C: nop
    
            goto L_8018EE30;
    }
    // 0x8018ED6C: nop

    // 0x8018ED70: jal         0x800613C4
    // 0x8018ED74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018ED74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018ED78: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018ED7C: addiu       $t8, $zero, 0xC3
    ctx->r24 = ADD32(0, 0XC3);
    // 0x8018ED80: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8018ED84: jal         0x80004EB0
    // 0x8018ED88: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018ED88: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    after_1:
    // 0x8018ED8C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018ED90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018ED94: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018ED98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018ED9C: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018EDA0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018EDA4: jal         0x80004EB0
    // 0x8018EDA8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018EDA8: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x8018EDAC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018EDB0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018EDB4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EDB8: lwc1        $f4, -0x2C70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x8018EDBC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8018EDC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EDC4: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8018EDC8: addiu       $t0, $zero, 0x1F
    ctx->r8 = ADD32(0, 0X1F);
    // 0x8018EDCC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018EDD0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8018EDD4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018EDD8: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018EDDC: lwc1        $f8, -0x650($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X650);
    // 0x8018EDE0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018EDE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018EDE8: sh          $t9, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r25;
    // 0x8018EDEC: sh          $t0, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r8;
    // 0x8018EDF0: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8018EDF4: jal         0x800612B8
    // 0x8018EDF8: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8018EDF8: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    after_3:
    // 0x8018EDFC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018EE00: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018EE04: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018EE08: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018EE0C: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8018EE10: ori         $a0, $a0, 0x2002
    ctx->r4 = ctx->r4 | 0X2002;
    // 0x8018EE14: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018EE18: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018EE1C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018EE20: jal         0x80019218
    // 0x8018EE24: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8018EE24: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x8018EE28: b           L_8018EE3C
    // 0x8018EE2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018EE3C;
    // 0x8018EE2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018EE30:
    // 0x8018EE30: bne         $v0, $v1, L_8018ED60
    if (ctx->r2 != ctx->r3) {
        // 0x8018EE34: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8018ED60;
    }
    // 0x8018EE34: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8018EE38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018EE3C:
    // 0x8018EE3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018EE40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018EE44: jr          $ra
    // 0x8018EE48: nop

    return;
    // 0x8018EE48: nop

;}
RECOMP_FUNC void Katina_BillFighterInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019848C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80198490: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80198494: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80198498: jal         0x800613C4
    // 0x8019849C: addiu       $a0, $a0, 0x5A74
    ctx->r4 = ADD32(ctx->r4, 0X5A74);
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019849C: addiu       $a0, $a0, 0x5A74
    ctx->r4 = ADD32(ctx->r4, 0X5A74);
    after_0:
    // 0x801984A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801984A4: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801984A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801984AC: sb          $t6, 0x5A74($at)
    MEM_B(0X5A74, ctx->r1) = ctx->r14;
    // 0x801984B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801984B4: swc1        $f4, 0x5A78($at)
    MEM_W(0X5A78, ctx->r1) = ctx->f4.u32l;
    // 0x801984B8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801984BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801984C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801984C4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801984C8: swc1        $f6, 0x5A7C($at)
    MEM_W(0X5A7C, ctx->r1) = ctx->f6.u32l;
    // 0x801984CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801984D0: sh          $t7, 0x5B2C($at)
    MEM_H(0X5B2C, ctx->r1) = ctx->r15;
    // 0x801984D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801984D8: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x801984DC: sh          $t8, 0x5B58($at)
    MEM_H(0X5B58, ctx->r1) = ctx->r24;
    // 0x801984E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801984E4: addiu       $t9, $zero, 0x1B
    ctx->r25 = ADD32(0, 0X1B);
    // 0x801984E8: sh          $t9, 0x5B5A($at)
    MEM_H(0X5B5A, ctx->r1) = ctx->r25;
    // 0x801984EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801984F0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801984F4: sh          $t0, 0x5B2A($at)
    MEM_H(0X5B2A, ctx->r1) = ctx->r8;
    // 0x801984F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801984FC: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x80198500: sh          $t1, 0x5B42($at)
    MEM_H(0X5B42, ctx->r1) = ctx->r9;
    // 0x80198504: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80198508: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8019850C: sw          $t2, 0x5AF0($at)
    MEM_W(0X5AF0, ctx->r1) = ctx->r10;
    // 0x80198510: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80198514: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80198518: sb          $t3, 0x5B3D($at)
    MEM_B(0X5B3D, ctx->r1) = ctx->r11;
    // 0x8019851C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80198520: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80198524: sh          $t4, 0x5B36($at)
    MEM_H(0X5B36, ctx->r1) = ctx->r12;
    // 0x80198528: addiu       $a1, $zero, 0xC5
    ctx->r5 = ADD32(0, 0XC5);
    // 0x8019852C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80198530: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80198534: addiu       $a0, $a0, 0x5A90
    ctx->r4 = ADD32(ctx->r4, 0X5A90);
    // 0x80198538: jal         0x800612B8
    // 0x8019853C: sh          $a1, 0x5A76($at)
    MEM_H(0X5A76, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8019853C: sh          $a1, 0x5A76($at)
    MEM_H(0X5A76, ctx->r1) = ctx->r5;
    after_1:
    // 0x80198540: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80198544: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80198548: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019854C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80198550: swc1        $f8, 0x5AAC($at)
    MEM_W(0X5AAC, ctx->r1) = ctx->f8.u32l;
    // 0x80198554: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80198558: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019855C: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80198560: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80198564: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80198568: sb          $zero, 0x5AB0($at)
    MEM_B(0X5AB0, ctx->r1) = 0;
    // 0x8019856C: addiu       $a1, $a1, 0x5B74
    ctx->r5 = ADD32(ctx->r5, 0X5B74);
    // 0x80198570: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80198574: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80198578: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019857C: jal         0x80019218
    // 0x80198580: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80198580: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80198584: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80198588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019858C: jr          $ra
    // 0x80198590: nop

    return;
    // 0x80198590: nop

;}
RECOMP_FUNC void Bolse_8018CCE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CCE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018CCEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CCF0: lwc1        $f0, -0x698($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X698);
    // 0x8018CCF4: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x8018CCF8: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8018CCFC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8018CD00: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8018CD04: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8018CD08: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8018CD0C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8018CD10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018CD14: addiu       $a2, $a2, 0x3FE0
    ctx->r6 = ADD32(ctx->r6, 0X3FE0);
    // 0x8018CD18: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x8018CD1C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018CD20: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8018CD24: lwc1        $f22, 0xC($a1)
    ctx->f22.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8018CD28: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8018CD2C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8018CD30: addiu       $a3, $zero, 0x2F4
    ctx->r7 = ADD32(0, 0X2F4);
L_8018CD34:
    // 0x8018CD34: beql        $v1, $zero, L_8018CD58
    if (ctx->r3 == 0) {
        // 0x8018CD38: lw          $a0, 0x0($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X0);
            goto L_8018CD58;
    }
    goto skip_0;
    // 0x8018CD38: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    skip_0:
    // 0x8018CD3C: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018CD40: mflo        $t6
    ctx->r14 = lo;
    // 0x8018CD44: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x8018CD48: lwc1        $f14, 0x4($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8018CD4C: b           L_8018CD60
    // 0x8018CD50: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
        goto L_8018CD60;
    // 0x8018CD50: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018CD54: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
L_8018CD58:
    // 0x8018CD58: lwc1        $f14, 0x74($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8018CD5C: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
L_8018CD60:
    // 0x8018CD60: sub.s       $f0, $f14, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8018CD64: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x8018CD68: sub.s       $f0, $f16, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x8018CD6C: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8018CD70: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018CD74: bc1t        L_8018CD98
    if (c1cs) {
        // 0x8018CD78: nop
    
            goto L_8018CD98;
    }
    // 0x8018CD78: nop

    // 0x8018CD7C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8018CD80: nop

    // 0x8018CD84: bc1t        L_8018CD98
    if (c1cs) {
        // 0x8018CD88: nop
    
            goto L_8018CD98;
    }
    // 0x8018CD88: nop

    // 0x8018CD8C: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8018CD90: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8018CD94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8018CD98:
    // 0x8018CD98: beql        $v1, $t1, L_8018CDBC
    if (ctx->r3 == ctx->r9) {
        // 0x8018CD9C: lw          $a0, 0x0($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X0);
            goto L_8018CDBC;
    }
    goto skip_1;
    // 0x8018CD9C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    skip_1:
    // 0x8018CDA0: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018CDA4: mflo        $t7
    ctx->r15 = lo;
    // 0x8018CDA8: addu        $a0, $a2, $t7
    ctx->r4 = ADD32(ctx->r6, ctx->r15);
    // 0x8018CDAC: lwc1        $f14, 0x2F8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X2F8);
    // 0x8018CDB0: b           L_8018CDC4
    // 0x8018CDB4: lwc1        $f16, 0x300($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X300);
        goto L_8018CDC4;
    // 0x8018CDB4: lwc1        $f16, 0x300($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X300);
    // 0x8018CDB8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
L_8018CDBC:
    // 0x8018CDBC: lwc1        $f14, 0x74($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8018CDC0: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
L_8018CDC4:
    // 0x8018CDC4: sub.s       $f0, $f14, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8018CDC8: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x8018CDCC: sub.s       $f0, $f16, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x8018CDD0: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8018CDD4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018CDD8: bc1tl       L_8018CE00
    if (c1cs) {
        // 0x8018CDDC: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8018CE00;
    }
    goto skip_2;
    // 0x8018CDDC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_2:
    // 0x8018CDE0: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8018CDE4: nop

    // 0x8018CDE8: bc1tl       L_8018CE00
    if (c1cs) {
        // 0x8018CDEC: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8018CE00;
    }
    goto skip_3;
    // 0x8018CDEC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    skip_3:
    // 0x8018CDF0: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x8018CDF4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8018CDF8: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8018CDFC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8018CE00:
    // 0x8018CE00: bne         $v1, $t2, L_8018CD34
    if (ctx->r3 != ctx->r10) {
        // 0x8018CE04: nop
    
            goto L_8018CD34;
    }
    // 0x8018CE04: nop

    // 0x8018CE08: bne         $v0, $zero, L_8018CE24
    if (ctx->r2 != 0) {
        // 0x8018CE0C: nop
    
            goto L_8018CE24;
    }
    // 0x8018CE0C: nop

    // 0x8018CE10: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8018CE14: lwc1        $f14, 0x74($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8018CE18: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8018CE1C: b           L_8018CE3C
    // 0x8018CE20: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
        goto L_8018CE3C;
    // 0x8018CE20: lwc1        $f16, 0x7C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X7C);
L_8018CE24:
    // 0x8018CE24: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018CE28: mflo        $t8
    ctx->r24 = lo;
    // 0x8018CE2C: addu        $v1, $a2, $t8
    ctx->r3 = ADD32(ctx->r6, ctx->r24);
    // 0x8018CE30: lwc1        $f14, 0x4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8018CE34: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8018CE38: lwc1        $f16, 0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XC);
L_8018CE3C:
    // 0x8018CE3C: swc1        $f14, 0x114($a1)
    MEM_W(0X114, ctx->r5) = ctx->f14.u32l;
    // 0x8018CE40: swc1        $f0, 0x118($a1)
    MEM_W(0X118, ctx->r5) = ctx->f0.u32l;
    // 0x8018CE44: swc1        $f16, 0x11C($a1)
    MEM_W(0X11C, ctx->r5) = ctx->f16.u32l;
    // 0x8018CE48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018CE4C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x8018CE50: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x8018CE54: jr          $ra
    // 0x8018CE58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8018CE58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Bolse_8018EAEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EAEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018EAF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018EAF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018EAF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018EAFC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8018EB00: jal         0x800613C4
    // 0x8018EB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018EB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018EB08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018EB0C: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x8018EB10: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8018EB14: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8018EB18: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EB1C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8018EB20: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8018EB24: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8018EB28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EB2C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8018EB30: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018EB34: lwc1        $f6, -0x1024($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1024);
    // 0x8018EB38: lwc1        $f4, 0x74($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X74);
    // 0x8018EB3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EB40: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018EB44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018EB48: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8018EB4C: addu        $t2, $t2, $t8
    ctx->r10 = ADD32(ctx->r10, ctx->r24);
    // 0x8018EB50: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8018EB54: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8018EB58: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8018EB5C: lwc1        $f16, -0x1018($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1018);
    // 0x8018EB60: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EB64: lwc1        $f10, 0x78($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X78);
    // 0x8018EB68: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018EB6C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018EB70: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018EB74: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8018EB78: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8018EB7C: lwc1        $f6, -0x100C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X100C);
    // 0x8018EB80: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018EB84: lwc1        $f4, 0x7C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X7C);
    // 0x8018EB88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018EB8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EB90: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018EB94: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018EB98: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8018EB9C: lw          $t2, -0x1000($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1000);
    // 0x8018EBA0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8018EBA4: sh          $t2, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r10;
    // 0x8018EBA8: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x8018EBAC: lwc1        $f16, 0xD0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0XD0);
    // 0x8018EBB0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8018EBB4: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    // 0x8018EBB8: lwc1        $f4, -0xFF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XFF4);
    // 0x8018EBBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EBC0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018EBC4: swc1        $f4, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f4.u32l;
    // 0x8018EBC8: lwc1        $f6, -0xFE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XFE8);
    // 0x8018EBCC: jal         0x800612B8
    // 0x8018EBD0: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8018EBD0: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x8018EBD4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018EBD8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018EBDC: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8018EBE0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018EBE4: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x8018EBE8: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8018EBEC: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8018EBF0: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8018EBF4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8018EBF8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018EBFC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8018EC00: jal         0x80019218
    // 0x8018EC04: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8018EC04: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8018EC08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018EC0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018EC10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018EC14: jr          $ra
    // 0x8018EC18: nop

    return;
    // 0x8018EC18: nop

;}
RECOMP_FUNC void Katina_BossOverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801965A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801965AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801965B0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801965B4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801965B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801965BC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801965C0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801965C4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801965C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801965CC: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x801965D0: jal         0x800B8DD0
    // 0x801965D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801965D4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x801965D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801965DC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x801965E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801965E4: lui         $t8, 0x2828
    ctx->r24 = S32(0X2828 << 16);
    // 0x801965E8: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x801965EC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801965F0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801965F4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801965F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801965FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80196600: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80196604: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80196608: sltiu       $at, $t0, 0xA
    ctx->r1 = ctx->r8 < 0XA ? 1 : 0;
    // 0x8019660C: beq         $at, $zero, L_801968DC
    if (ctx->r1 == 0) {
        // 0x80196610: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_801968DC;
    }
    // 0x80196610: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80196614: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196618: addu        $at, $at, $t0
    gpr jr_addend_80196620 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8019661C: lw          $t0, -0x88($at)
    ctx->r8 = ADD32(ctx->r1, -0X88);
    // 0x80196620: jr          $t0
    // 0x80196624: nop

    switch (jr_addend_80196620 >> 2) {
        case 0: goto L_80196628; break;
        case 1: goto L_801966A4; break;
        case 2: goto L_80196720; break;
        case 3: goto L_8019679C; break;
        case 4: goto L_801968DC; break;
        case 5: goto L_801968DC; break;
        case 6: goto L_801968DC; break;
        case 7: goto L_801968DC; break;
        case 8: goto L_80196818; break;
        case 9: goto L_80196894; break;
        default: switch_error(__func__, 0x80196620, 0x8019FF78);
    }
    // 0x80196624: nop

L_80196628:
    // 0x80196628: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8019662C: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80196630: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80196634: lwc1        $f6, 0xD8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x80196638: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019663C: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80196640: lh          $t1, 0x88($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X88);
    // 0x80196644: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80196648: beql        $t2, $zero, L_80196660
    if (ctx->r10 == 0) {
        // 0x8019664C: lh          $t3, 0x9C($v0)
        ctx->r11 = MEM_H(ctx->r2, 0X9C);
            goto L_80196660;
    }
    goto skip_0;
    // 0x8019664C: lh          $t3, 0x9C($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X9C);
    skip_0:
    // 0x80196650: jal         0x800B8DD0
    // 0x80196654: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80196654: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_1:
    // 0x80196658: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8019665C: lh          $t3, 0x9C($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X9C);
L_80196660:
    // 0x80196660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80196664: bgtzl       $t3, L_801968E0
    if (SIGNED(ctx->r11) > 0) {
        // 0x80196668: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801968E0;
    }
    goto skip_1;
    // 0x80196668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8019666C: jal         0x800B8DD0
    // 0x80196670: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80196670: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_2:
    // 0x80196674: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196678: lui         $t5, 0xB600
    ctx->r13 = S32(0XB600 << 16);
    // 0x8019667C: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x80196680: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80196684: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80196688: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8019668C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80196690: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80196694: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80196698: addiu       $t7, $t7, 0x12A0
    ctx->r15 = ADD32(ctx->r15, 0X12A0);
    // 0x8019669C: b           L_801968DC
    // 0x801966A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_801968DC;
    // 0x801966A0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_801966A4:
    // 0x801966A4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x801966A8: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801966AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801966B0: lwc1        $f16, 0xDC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XDC);
    // 0x801966B4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801966B8: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x801966BC: lh          $t9, 0x8A($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8A);
    // 0x801966C0: andi        $t0, $t9, 0x1
    ctx->r8 = ctx->r25 & 0X1;
    // 0x801966C4: beql        $t0, $zero, L_801966DC
    if (ctx->r8 == 0) {
        // 0x801966C8: lh          $t1, 0x9E($v0)
        ctx->r9 = MEM_H(ctx->r2, 0X9E);
            goto L_801966DC;
    }
    goto skip_2;
    // 0x801966C8: lh          $t1, 0x9E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X9E);
    skip_2:
    // 0x801966CC: jal         0x800B8DD0
    // 0x801966D0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801966D0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_3:
    // 0x801966D4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x801966D8: lh          $t1, 0x9E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X9E);
L_801966DC:
    // 0x801966DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801966E0: bgtzl       $t1, L_801968E0
    if (SIGNED(ctx->r9) > 0) {
        // 0x801966E4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801968E0;
    }
    goto skip_3;
    // 0x801966E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x801966E8: jal         0x800B8DD0
    // 0x801966EC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x801966EC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_4:
    // 0x801966F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801966F4: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x801966F8: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x801966FC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80196700: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80196704: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80196708: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019670C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80196710: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x80196714: addiu       $t5, $t5, -0x3240
    ctx->r13 = ADD32(ctx->r13, -0X3240);
    // 0x80196718: b           L_801968DC
    // 0x8019671C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
        goto L_801968DC;
    // 0x8019671C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_80196720:
    // 0x80196720: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80196724: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x80196728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019672C: lwc1        $f6, 0xE0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XE0);
    // 0x80196730: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80196734: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80196738: lh          $t7, 0x8C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X8C);
    // 0x8019673C: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80196740: beql        $t8, $zero, L_80196758
    if (ctx->r24 == 0) {
        // 0x80196744: lh          $t9, 0xA0($v0)
        ctx->r25 = MEM_H(ctx->r2, 0XA0);
            goto L_80196758;
    }
    goto skip_4;
    // 0x80196744: lh          $t9, 0xA0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA0);
    skip_4:
    // 0x80196748: jal         0x800B8DD0
    // 0x8019674C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x8019674C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_5:
    // 0x80196750: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80196754: lh          $t9, 0xA0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XA0);
L_80196758:
    // 0x80196758: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019675C: bgtzl       $t9, L_801968E0
    if (SIGNED(ctx->r25) > 0) {
        // 0x80196760: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801968E0;
    }
    goto skip_5;
    // 0x80196760: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80196764: jal         0x800B8DD0
    // 0x80196768: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x80196768: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_6:
    // 0x8019676C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196770: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x80196774: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x80196778: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8019677C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80196780: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80196784: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80196788: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8019678C: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x80196790: addiu       $t3, $t3, -0x2B20
    ctx->r11 = ADD32(ctx->r11, -0X2B20);
    // 0x80196794: b           L_801968DC
    // 0x80196798: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
        goto L_801968DC;
    // 0x80196798: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
L_8019679C:
    // 0x8019679C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x801967A0: lwc1        $f10, 0x4($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X4);
    // 0x801967A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801967A8: lwc1        $f16, 0xE4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x801967AC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801967B0: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x801967B4: lh          $t5, 0x8E($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X8E);
    // 0x801967B8: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x801967BC: beql        $t6, $zero, L_801967D4
    if (ctx->r14 == 0) {
        // 0x801967C0: lh          $t7, 0xA2($v0)
        ctx->r15 = MEM_H(ctx->r2, 0XA2);
            goto L_801967D4;
    }
    goto skip_6;
    // 0x801967C0: lh          $t7, 0xA2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA2);
    skip_6:
    // 0x801967C4: jal         0x800B8DD0
    // 0x801967C8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x801967C8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_7:
    // 0x801967CC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x801967D0: lh          $t7, 0xA2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA2);
L_801967D4:
    // 0x801967D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801967D8: bgtzl       $t7, L_801968E0
    if (SIGNED(ctx->r15) > 0) {
        // 0x801967DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801968E0;
    }
    goto skip_7;
    // 0x801967DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_7:
    // 0x801967E0: jal         0x800B8DD0
    // 0x801967E4: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x801967E4: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_8:
    // 0x801967E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801967EC: lui         $t9, 0xB600
    ctx->r25 = S32(0XB600 << 16);
    // 0x801967F0: addiu       $t0, $zero, 0x2000
    ctx->r8 = ADD32(0, 0X2000);
    // 0x801967F4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801967F8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801967FC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x80196800: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80196804: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80196808: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x8019680C: addiu       $t1, $t1, -0x2D70
    ctx->r9 = ADD32(ctx->r9, -0X2D70);
    // 0x80196810: b           L_801968DC
    // 0x80196814: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
        goto L_801968DC;
    // 0x80196814: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80196818:
    // 0x80196818: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8019681C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80196820: lwc1        $f6, 0xE8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x80196824: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80196828: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8019682C: lh          $t3, 0x90($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X90);
    // 0x80196830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80196834: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80196838: beql        $t4, $zero, L_80196850
    if (ctx->r12 == 0) {
        // 0x8019683C: lh          $t5, 0xA4($v0)
        ctx->r13 = MEM_H(ctx->r2, 0XA4);
            goto L_80196850;
    }
    goto skip_8;
    // 0x8019683C: lh          $t5, 0xA4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA4);
    skip_8:
    // 0x80196840: jal         0x800B8DD0
    // 0x80196844: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x80196844: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_9:
    // 0x80196848: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8019684C: lh          $t5, 0xA4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XA4);
L_80196850:
    // 0x80196850: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80196854: bgtzl       $t5, L_801968E0
    if (SIGNED(ctx->r13) > 0) {
        // 0x80196858: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801968E0;
    }
    goto skip_9;
    // 0x80196858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x8019685C: jal         0x800B8DD0
    // 0x80196860: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_10;
    // 0x80196860: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_10:
    // 0x80196864: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196868: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x8019686C: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x80196870: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80196874: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80196878: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019687C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80196880: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80196884: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x80196888: addiu       $t9, $t9, -0x2F70
    ctx->r25 = ADD32(ctx->r25, -0X2F70);
    // 0x8019688C: b           L_801968DC
    // 0x80196890: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_801968DC;
    // 0x80196890: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
L_80196894:
    // 0x80196894: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80196898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019689C: lh          $t1, 0x60($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X60);
    // 0x801968A0: bgezl       $t1, L_801968E0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801968A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801968E0;
    }
    goto skip_10;
    // 0x801968A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_10:
    // 0x801968A8: jal         0x800B8DD0
    // 0x801968AC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x801968AC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_11:
    // 0x801968B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801968B4: lui         $t3, 0xB600
    ctx->r11 = S32(0XB600 << 16);
    // 0x801968B8: addiu       $t4, $zero, 0x2000
    ctx->r12 = ADD32(0, 0X2000);
    // 0x801968BC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801968C0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801968C4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801968C8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801968CC: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x801968D0: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801968D4: addiu       $t5, $t5, 0x7300
    ctx->r13 = ADD32(ctx->r13, 0X7300);
    // 0x801968D8: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_801968DC:
    // 0x801968DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801968E0:
    // 0x801968E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801968E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801968E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801968EC: jr          $ra
    // 0x801968F0: nop

    return;
    // 0x801968F0: nop

;}
RECOMP_FUNC void Katina_LaserEnergyParticlesSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801927E0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801927E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801927E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801927EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801927F0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x801927F4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x801927F8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x801927FC: jal         0x80061474
    // 0x80192800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80192800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80192804: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80192808: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019280C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80192810: addiu       $t7, $zero, 0x166
    ctx->r15 = ADD32(0, 0X166);
    // 0x80192814: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80192818: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8019281C: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x80192820: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80192824: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x80192828: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8019282C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80192830: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80192834: sub.s       $f14, $f8, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80192838: sub.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8019283C: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80192840: jal         0x80005100
    // 0x80192844: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x80192844: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x80192848: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019284C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80192850: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80192854: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80192858: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8019285C: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80192860: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80192864: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80192868: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019286C: jal         0x80005100
    // 0x80192870: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x80192870: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_2:
    // 0x80192874: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80192878: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019287C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80192880: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80192884: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80192888: jal         0x80005E90
    // 0x8019288C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8019288C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80192890: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80192894: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80192898: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8019289C: jal         0x80005D44
    // 0x801928A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801928A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x801928A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801928A8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801928AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801928B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801928B4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801928B8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x801928BC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x801928C0: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801928C4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801928C8: jal         0x80006970
    // 0x801928CC: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x801928CC: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x801928D0: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801928D4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801928D8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801928DC: swc1        $f18, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f18.u32l;
    // 0x801928E0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801928E4: swc1        $f4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f4.u32l;
    // 0x801928E8: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801928EC: jal         0x800612B8
    // 0x801928F0: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x801928F0: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x801928F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801928F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801928FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80192900: jr          $ra
    // 0x80192904: nop

    return;
    // 0x80192904: nop

;}
RECOMP_FUNC void Bolse_BoBaseShield_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191BAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80191BB0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80191BB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80191BB8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80191BBC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80191BC0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80191BC4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x80191BC8: lw          $t6, 0x3DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3DC);
    // 0x80191BCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191BD0: sw          $zero, 0x530($at)
    MEM_W(0X530, ctx->r1) = 0;
    // 0x80191BD4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80191BD8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x80191BDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191BE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80191BE4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80191BE8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80191BEC: addiu       $a0, $s0, 0xD8
    ctx->r4 = ADD32(ctx->r16, 0XD8);
    // 0x80191BF0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80191BF4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80191BF8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80191BFC: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80191C00: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80191C04: jal         0x8009BC2C
    // 0x80191C08: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80191C08: nop

    after_0:
    // 0x80191C0C: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80191C10: addiu       $a0, $a0, -0x3078
    ctx->r4 = ADD32(ctx->r4, -0X3078);
    // 0x80191C14: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80191C18: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80191C1C: jal         0x80099A2C
    // 0x80191C20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_1;
    // 0x80191C20: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80191C24: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80191C28: addiu       $a0, $a0, -0x3078
    ctx->r4 = ADD32(ctx->r4, -0X3078);
    // 0x80191C2C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80191C30: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80191C34: jal         0x80099A2C
    // 0x80191C38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Lib_Texture_Scroll(rdram, ctx);
        goto after_2;
    // 0x80191C38: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80191C3C: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x80191C40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80191C44: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80191C48: beq         $v0, $zero, L_80191C6C
    if (ctx->r2 == 0) {
        // 0x80191C4C: nop
    
            goto L_80191C6C;
    }
    // 0x80191C4C: nop

    // 0x80191C50: beq         $v0, $at, L_80191CB4
    if (ctx->r2 == ctx->r1) {
        // 0x80191C54: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_80191CB4;
    }
    // 0x80191C54: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80191C58: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80191C5C: beq         $v0, $at, L_80191D14
    if (ctx->r2 == ctx->r1) {
        // 0x80191C60: nop
    
            goto L_80191D14;
    }
    // 0x80191C60: nop

    // 0x80191C64: b           L_80191D14
    // 0x80191C68: nop

        goto L_80191D14;
    // 0x80191C68: nop

L_80191C6C:
    // 0x80191C6C: lw          $t7, 0x3DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3DC);
    // 0x80191C70: addiu       $t8, $zero, 0x82
    ctx->r24 = ADD32(0, 0X82);
    // 0x80191C74: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80191C78: bne         $t7, $zero, L_80191D14
    if (ctx->r15 != 0) {
        // 0x80191C7C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80191D14;
    }
    // 0x80191C7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80191C80: sh          $t8, 0x52($s0)
    MEM_H(0X52, ctx->r16) = ctx->r24;
    // 0x80191C84: sh          $t9, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r25;
    // 0x80191C88: addiu       $a0, $a0, -0xC8
    ctx->r4 = ADD32(ctx->r4, -0XC8);
    // 0x80191C8C: jal         0x800BA808
    // 0x80191C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x80191C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80191C94: lui         $a0, 0x1001
    ctx->r4 = S32(0X1001 << 16);
    // 0x80191C98: jal         0x800182F4
    // 0x80191C9C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_4;
    // 0x80191C9C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_4:
    // 0x80191CA0: lui         $a0, 0x1101
    ctx->r4 = S32(0X1101 << 16);
    // 0x80191CA4: jal         0x800182F4
    // 0x80191CA8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_5;
    // 0x80191CA8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_5:
    // 0x80191CAC: b           L_80191D14
    // 0x80191CB0: nop

        goto L_80191D14;
    // 0x80191CB0: nop

L_80191CB4:
    // 0x80191CB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191CB8: lwc1        $f4, -0x30C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30C);
    // 0x80191CBC: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x80191CC0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80191CC4: addiu       $a0, $a0, -0xE14
    ctx->r4 = ADD32(ctx->r4, -0XE14);
    // 0x80191CC8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80191CCC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80191CD0: jal         0x8009BC2C
    // 0x80191CD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80191CD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x80191CD8: lh          $t0, 0x52($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X52);
    // 0x80191CDC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80191CE0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80191CE4: bne         $t0, $zero, L_80191D14
    if (ctx->r8 != 0) {
        // 0x80191CE8: addiu       $t1, $zero, 0x2
        ctx->r9 = ADD32(0, 0X2);
            goto L_80191D14;
    }
    // 0x80191CE8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80191CEC: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80191CF0: sh          $t1, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r9;
    // 0x80191CF4: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80191CF8: lui         $a0, 0x1940
    ctx->r4 = S32(0X1940 << 16);
    // 0x80191CFC: ori         $a0, $a0, 0x1048
    ctx->r4 = ctx->r4 | 0X1048;
    // 0x80191D00: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80191D04: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80191D08: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x80191D0C: jal         0x80019218
    // 0x80191D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x80191D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
L_80191D14:
    // 0x80191D14: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80191D18: lw          $t3, -0x7ED4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7ED4);
    // 0x80191D1C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80191D20: bnel        $t3, $zero, L_80191DA0
    if (ctx->r11 != 0) {
        // 0x80191D24: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80191DA0;
    }
    goto skip_0;
    // 0x80191D24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80191D28: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x80191D2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80191D30: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80191D34: bnel        $t5, $zero, L_80191D50
    if (ctx->r13 != 0) {
        // 0x80191D38: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80191D50;
    }
    goto skip_1;
    // 0x80191D38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x80191D3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80191D40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191D44: b           L_80191D58
    // 0x80191D48: swc1        $f6, -0x7C94($at)
    MEM_W(-0X7C94, ctx->r1) = ctx->f6.u32l;
        goto L_80191D58;
    // 0x80191D48: swc1        $f6, -0x7C94($at)
    MEM_W(-0X7C94, ctx->r1) = ctx->f6.u32l;
    // 0x80191D4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80191D50:
    // 0x80191D50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191D54: swc1        $f8, -0x7C94($at)
    MEM_W(-0X7C94, ctx->r1) = ctx->f8.u32l;
L_80191D58:
    // 0x80191D58: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80191D5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191D60: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80191D64: swc1        $f10, -0x7C90($at)
    MEM_W(-0X7C90, ctx->r1) = ctx->f10.u32l;
    // 0x80191D68: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80191D6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191D70: addiu       $v0, $zero, 0x80
    ctx->r2 = ADD32(0, 0X80);
    // 0x80191D74: swc1        $f16, -0x7C8C($at)
    MEM_W(-0X7C8C, ctx->r1) = ctx->f16.u32l;
    // 0x80191D78: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80191D7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191D80: swc1        $f18, -0x7C88($at)
    MEM_W(-0X7C88, ctx->r1) = ctx->f18.u32l;
    // 0x80191D84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191D88: sw          $t6, -0x7CA0($at)
    MEM_W(-0X7CA0, ctx->r1) = ctx->r14;
    // 0x80191D8C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191D90: sw          $v0, -0x7C9C($at)
    MEM_W(-0X7C9C, ctx->r1) = ctx->r2;
    // 0x80191D94: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191D98: sw          $v0, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = ctx->r2;
    // 0x80191D9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80191DA0:
    // 0x80191DA0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80191DA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80191DA8: jr          $ra
    // 0x80191DAC: nop

    return;
    // 0x80191DAC: nop

;}
RECOMP_FUNC void SectorZ_CsLevelCompleteKattInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C70C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019C710: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019C714: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019C718: jal         0x800613C4
    // 0x8019C71C: addiu       $a0, $a0, 0x5780
    ctx->r4 = ADD32(ctx->r4, 0X5780);
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019C71C: addiu       $a0, $a0, 0x5780
    ctx->r4 = ADD32(ctx->r4, 0X5780);
    after_0:
    // 0x8019C720: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019C724: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019C728: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8019C72C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019C730: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C734: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019C738: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019C73C: sb          $t6, 0x5780($at)
    MEM_B(0X5780, ctx->r1) = ctx->r14;
    // 0x8019C740: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8019C744: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8019C748: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C74C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019C750: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C754: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x8019C758: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019C75C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019C760: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8019C764: addiu       $t0, $zero, 0x82
    ctx->r8 = ADD32(0, 0X82);
    // 0x8019C768: swc1        $f8, 0x5784($at)
    MEM_W(0X5784, ctx->r1) = ctx->f8.u32l;
    // 0x8019C76C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019C770: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C774: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x8019C778: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8019C77C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019C780: addiu       $a0, $a0, 0x579C
    ctx->r4 = ADD32(ctx->r4, 0X579C);
    // 0x8019C784: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8019C788: swc1        $f16, 0x5788($at)
    MEM_W(0X5788, ctx->r1) = ctx->f16.u32l;
    // 0x8019C78C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8019C790: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C794: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8019C798: swc1        $f4, 0x578C($at)
    MEM_W(0X578C, ctx->r1) = ctx->f4.u32l;
    // 0x8019C79C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7A0: swc1        $f0, 0x5878($at)
    MEM_W(0X5878, ctx->r1) = ctx->f0.u32l;
    // 0x8019C7A4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019C7A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C7AC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7B0: swc1        $f6, 0x5874($at)
    MEM_W(0X5874, ctx->r1) = ctx->f6.u32l;
    // 0x8019C7B4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8019C7B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019C7BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7C0: swc1        $f8, 0x5790($at)
    MEM_W(0X5790, ctx->r1) = ctx->f8.u32l;
    // 0x8019C7C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7C8: swc1        $f10, 0x5794($at)
    MEM_W(0X5794, ctx->r1) = ctx->f10.u32l;
    // 0x8019C7CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7D0: lwc1        $f16, 0x587C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X587C);
    // 0x8019C7D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7D8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8019C7DC: swc1        $f18, 0x5798($at)
    MEM_W(0X5798, ctx->r1) = ctx->f18.u32l;
    // 0x8019C7E0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019C7E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019C7E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7EC: swc1        $f4, 0x5894($at)
    MEM_W(0X5894, ctx->r1) = ctx->f4.u32l;
    // 0x8019C7F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7F4: sh          $t7, 0x5836($at)
    MEM_H(0X5836, ctx->r1) = ctx->r15;
    // 0x8019C7F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C7FC: sw          $t8, 0x57FC($at)
    MEM_W(0X57FC, ctx->r1) = ctx->r24;
    // 0x8019C800: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C804: sh          $t9, 0x5838($at)
    MEM_H(0X5838, ctx->r1) = ctx->r25;
    // 0x8019C808: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C80C: sh          $t0, 0x583C($at)
    MEM_H(0X583C, ctx->r1) = ctx->r8;
    // 0x8019C810: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019C814: jal         0x800612B8
    // 0x8019C818: sh          $a1, 0x5782($at)
    MEM_H(0X5782, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8019C818: sh          $a1, 0x5782($at)
    MEM_H(0X5782, ctx->r1) = ctx->r5;
    after_1:
    // 0x8019C81C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019C820: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8019C824: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019C828: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019C82C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8019C830: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019C834: addiu       $a1, $a1, 0x5880
    ctx->r5 = ADD32(ctx->r5, 0X5880);
    // 0x8019C838: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8019C83C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019C840: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019C844: jal         0x80019218
    // 0x8019C848: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019C848: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8019C84C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019C850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019C854: jr          $ra
    // 0x8019C858: nop

    return;
    // 0x8019C858: nop

;}
RECOMP_FUNC void SectorZ_CsTeamInit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B75C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019B760: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019B764: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019B768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019B76C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019B770: jal         0x800613C4
    // 0x8019B774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019B774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019B778: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8019B77C: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x8019B780: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8019B784: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8019B788: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8019B78C: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8019B790: addiu       $t0, $t0, -0xA44
    ctx->r8 = ADD32(ctx->r8, -0XA44);
    // 0x8019B794: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8019B798: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8019B79C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019B7A0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8019B7A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019B7A8: lwc1        $f6, 0x3FE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3FE4);
    // 0x8019B7AC: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019B7B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019B7B4: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8019B7B8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019B7BC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019B7C0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x8019B7C4: lwc1        $f10, 0x3FE8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3FE8);
    // 0x8019B7C8: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8019B7CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019B7D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019B7D4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019B7D8: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8019B7DC: lwc1        $f6, 0x3FEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X3FEC);
    // 0x8019B7E0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019B7E4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019B7E8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019B7EC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8019B7F0: lwc1        $f10, 0x1A54($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1A54);
    // 0x8019B7F4: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8019B7F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019B7FC: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8019B800: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x8019B804: jal         0x800612B8
    // 0x8019B808: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8019B808: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x8019B80C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019B810: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8019B814: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019B818: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019B81C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8019B820: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019B824: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8019B828: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8019B82C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019B830: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019B834: jal         0x80019218
    // 0x8019B838: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019B838: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8019B83C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019B840: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019B844: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019B848: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019B84C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019B850: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8019B854: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019B858: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019B85C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019B860: jal         0x80019218
    // 0x8019B864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8019B864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8019B868: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019B86C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B870: nop

    // 0x8019B874: swc1        $f4, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f4.u32l;
    // 0x8019B878: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019B87C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019B880: jr          $ra
    // 0x8019B884: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8019B884: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Fortuna_ActorDebris_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188A48: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80188A4C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80188A50: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80188A54: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80188A58: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80188A5C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80188A60: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80188A64: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80188A68: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80188A6C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80188A70: addiu       $v0, $v0, -0x6A7C
    ctx->r2 = ADD32(ctx->r2, -0X6A7C);
    // 0x80188A74: addiu       $s0, $s0, -0x11E4
    ctx->r16 = ADD32(ctx->r16, -0X11E4);
    // 0x80188A78: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_80188A7C:
    // 0x80188A7C: bnel        $t6, $zero, L_80188AB4
    if (ctx->r14 != 0) {
        // 0x80188A80: addiu       $s0, $s0, -0x2F4
        ctx->r16 = ADD32(ctx->r16, -0X2F4);
            goto L_80188AB4;
    }
    goto skip_0;
    // 0x80188A80: addiu       $s0, $s0, -0x2F4
    ctx->r16 = ADD32(ctx->r16, -0X2F4);
    skip_0:
    // 0x80188A84: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80188A88: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80188A8C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80188A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80188A94: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80188A98: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x80188A9C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80188AA0: jal         0x801888C0
    // 0x80188AA4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    Fortuna_ActorDebris_Setup(rdram, ctx);
        goto after_0;
    // 0x80188AA4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x80188AA8: b           L_80188AC0
    // 0x80188AAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80188AC0;
    // 0x80188AAC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80188AB0: addiu       $s0, $s0, -0x2F4
    ctx->r16 = ADD32(ctx->r16, -0X2F4);
L_80188AB4:
    // 0x80188AB4: bnel        $s0, $v0, L_80188A7C
    if (ctx->r16 != ctx->r2) {
        // 0x80188AB8: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_80188A7C;
    }
    goto skip_1;
    // 0x80188AB8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x80188ABC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80188AC0:
    // 0x80188AC0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80188AC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80188AC8: jr          $ra
    // 0x80188ACC: nop

    return;
    // 0x80188ACC: nop

;}
RECOMP_FUNC void SectorZ_SpawnMissile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199FCC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80199FD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80199FD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80199FD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80199FDC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80199FE0: jal         0x800613C4
    // 0x80199FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80199FE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80199FE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80199FEC: addiu       $t7, $zero, 0xC5
    ctx->r15 = ADD32(0, 0XC5);
    // 0x80199FF0: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x80199FF4: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80199FF8: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80199FFC: sh          $t8, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r24;
    // 0x8019A000: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8019A004: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8019A008: addiu       $t1, $t1, -0xB40
    ctx->r9 = ADD32(ctx->r9, -0XB40);
    // 0x8019A00C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8019A010: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8019A014: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019A018: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8019A01C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019A020: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019A024: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019A028: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8019A02C: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019A030: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8019A034: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8019A038: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8019A03C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019A040: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
    // 0x8019A044: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019A048: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x8019A04C: jal         0x800612B8
    // 0x8019A050: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8019A050: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8019A054: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x8019A058: addiu       $v0, $v0, -0x6DD0
    ctx->r2 = ADD32(ctx->r2, -0X6DD0);
    // 0x8019A05C: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8019A060: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x8019A064: addiu       $t3, $zero, 0xFA
    ctx->r11 = ADD32(0, 0XFA);
    // 0x8019A068: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8019A06C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019A070: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8019A074: sh          $t3, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r11;
    // 0x8019A078: sb          $t4, 0x20($s0)
    MEM_B(0X20, ctx->r16) = ctx->r12;
    // 0x8019A07C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019A080: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019A084: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x8019A088: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019A08C: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8019A090: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019A094: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8019A098: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x8019A09C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8019A0A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A0A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019A0A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019A0AC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A0B0: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019A0B4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A0B8: sw          $t1, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r9;
    // 0x8019A0BC: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019A0C0: lui         $a0, 0x3103
    ctx->r4 = S32(0X3103 << 16);
    // 0x8019A0C4: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
    // 0x8019A0C8: swc1        $f18, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f18.u32l;
    // 0x8019A0CC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019A0D0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019A0D4: ori         $a0, $a0, 0xA061
    ctx->r4 = ctx->r4 | 0XA061;
    // 0x8019A0D8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019A0DC: jal         0x80019218
    // 0x8019A0E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019A0E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8019A0E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019A0E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019A0EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019A0F0: jr          $ra
    // 0x8019A0F4: nop

    return;
    // 0x8019A0F4: nop

;}
RECOMP_FUNC void Katina_SFTeam_LevelComplete_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197024: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80197028: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8019702C: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80197030: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80197034: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80197038: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8019703C: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80197040: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80197044: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80197048: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8019704C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80197050: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80197054: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80197058: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8019705C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80197060: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80197064: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x80197068: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8019706C: addiu       $a1, $zero, 0x71AC
    ctx->r5 = ADD32(0, 0X71AC);
    // 0x80197070: jal         0x80004FC8
    // 0x80197074: addiu       $a2, $zero, 0x263A
    ctx->r6 = ADD32(0, 0X263A);
    Rand_SetSeed(rdram, ctx);
        goto after_0;
    // 0x80197074: addiu       $a2, $zero, 0x263A
    ctx->r6 = ADD32(0, 0X263A);
    after_0:
    // 0x80197078: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019707C: lbu         $t6, 0x7930($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7930);
    // 0x80197080: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80197084: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80197088: beq         $t6, $zero, L_80197098
    if (ctx->r14 == 0) {
        // 0x8019708C: lui         $s5, 0x801A
        ctx->r21 = S32(0X801A << 16);
            goto L_80197098;
    }
    // 0x8019708C: lui         $s5, 0x801A
    ctx->r21 = S32(0X801A << 16);
    // 0x80197090: b           L_80197098
    // 0x80197094: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
        goto L_80197098;
    // 0x80197094: addiu       $v0, $zero, 0x13
    ctx->r2 = ADD32(0, 0X13);
L_80197098:
    // 0x80197098: bltz        $v0, L_80197250
    if (SIGNED(ctx->r2) < 0) {
        // 0x8019709C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80197250;
    }
    // 0x8019709C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801970A0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801970A4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801970A8: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x801970AC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801970B0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801970B4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801970B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801970BC: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x801970C0: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x801970C4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801970C8: addiu       $s3, $s3, -0x7D80
    ctx->r19 = ADD32(ctx->r19, -0X7D80);
    // 0x801970CC: addiu       $s7, $s7, 0x5D34
    ctx->r23 = ADD32(ctx->r23, 0X5D34);
    // 0x801970D0: addiu       $s5, $s5, -0xD10
    ctx->r21 = ADD32(ctx->r21, -0XD10);
    // 0x801970D4: addiu       $fp, $v0, 0x1
    ctx->r30 = ADD32(ctx->r2, 0X1);
    // 0x801970D8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_801970DC:
    // 0x801970DC: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x801970E0: lbu         $t8, -0x6DF($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X6DF);
    // 0x801970E4: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x801970E8: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801970EC: bne         $at, $zero, L_8019723C
    if (ctx->r1 != 0) {
        // 0x801970F0: slti        $at, $s2, 0x3
        ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
            goto L_8019723C;
    }
    // 0x801970F0: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x801970F4: beq         $at, $zero, L_80197108
    if (ctx->r1 == 0) {
        // 0x801970F8: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_80197108;
    }
    // 0x801970F8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801970FC: addu        $t9, $t9, $s4
    ctx->r25 = ADD32(ctx->r25, ctx->r20);
    // 0x80197100: lw          $t9, 0x78B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B4);
    // 0x80197104: blez        $t9, L_8019723C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80197108: sll         $t0, $s2, 2
        ctx->r8 = S32(ctx->r18 << 2);
            goto L_8019723C;
    }
L_80197108:
    // 0x80197108: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x8019710C: subu        $t0, $t0, $s2
    ctx->r8 = SUB32(ctx->r8, ctx->r18);
    // 0x80197110: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x80197114: addiu       $t1, $t1, -0xCC0
    ctx->r9 = ADD32(ctx->r9, -0XCC0);
    // 0x80197118: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019711C: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x80197120: jal         0x800613C4
    // 0x80197124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_1;
    // 0x80197124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80197128: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8019712C: addiu       $t3, $zero, 0xC3
    ctx->r11 = ADD32(0, 0XC3);
    // 0x80197130: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
    // 0x80197134: jal         0x80004FE8
    // 0x80197138: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_2;
    // 0x80197138: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    after_2:
    // 0x8019713C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80197140: sub.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80197144: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x80197148: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8019714C: lwc1        $f8, 0x74($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X74);
    // 0x80197150: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80197154: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80197158: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8019715C: jal         0x80004FE8
    // 0x80197160: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_3;
    // 0x80197160: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x80197164: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80197168: mul.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8019716C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80197170: lwc1        $f8, 0x78($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X78);
    // 0x80197174: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80197178: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8019717C: jal         0x80004FE8
    // 0x80197180: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_4;
    // 0x80197180: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x80197184: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80197188: mul.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8019718C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80197190: lwc1        $f6, 0x7C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X7C);
    // 0x80197194: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80197198: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8019719C: jal         0x80004FE8
    // 0x801971A0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_5;
    // 0x801971A0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_5:
    // 0x801971A4: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801971A8: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x801971AC: addiu       $t0, $zero, 0x21
    ctx->r8 = ADD32(0, 0X21);
    // 0x801971B0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801971B4: mul.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x801971B8: swc1        $f4, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f4.u32l;
    // 0x801971BC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801971C0: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x801971C4: mul.s       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801971C8: lwc1        $f6, 0x74($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X74);
    // 0x801971CC: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801971D0: swc1        $f18, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f18.u32l;
    // 0x801971D4: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x801971D8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801971DC: lwc1        $f10, 0x78($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X78);
    // 0x801971E0: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801971E4: swc1        $f16, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f16.u32l;
    // 0x801971E8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x801971EC: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801971F0: lwc1        $f6, 0x7C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X7C);
    // 0x801971F4: sh          $s6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r22;
    // 0x801971F8: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801971FC: bne         $at, $zero, L_80197208
    if (ctx->r1 != 0) {
        // 0x80197200: swc1        $f18, 0x194($s0)
        MEM_W(0X194, ctx->r16) = ctx->f18.u32l;
            goto L_80197208;
    }
    // 0x80197200: swc1        $f18, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f18.u32l;
    // 0x80197204: sh          $t0, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r8;
L_80197208:
    // 0x80197208: jal         0x800612B8
    // 0x8019720C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x8019720C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_6:
    // 0x80197210: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80197214: sw          $s6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r22;
    // 0x80197218: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019721C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80197220: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80197224: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80197228: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x8019722C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80197230: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80197234: jal         0x80019218
    // 0x80197238: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x80197238: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_7:
L_8019723C:
    // 0x8019723C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80197240: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80197244: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80197248: bne         $fp, $s2, L_801970DC
    if (ctx->r30 != ctx->r18) {
        // 0x8019724C: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_801970DC;
    }
    // 0x8019724C: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_80197250:
    // 0x80197250: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80197254: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80197258: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8019725C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80197260: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80197264: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80197268: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8019726C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80197270: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80197274: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80197278: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8019727C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80197280: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80197284: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80197288: jr          $ra
    // 0x8019728C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8019728C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Bolse_8018CE5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CE5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018CE60: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018CE64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018CE68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018CE6C: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x8018CE70: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018CE74: bnel        $t6, $zero, L_8018CE88
    if (ctx->r14 != 0) {
        // 0x8018CE78: lw          $t7, 0x40($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X40);
            goto L_8018CE88;
    }
    goto skip_0;
    // 0x8018CE78: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    skip_0:
    // 0x8018CE7C: b           L_8018CFF4
    // 0x8018CE80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018CFF4;
    // 0x8018CE80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018CE84: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
L_8018CE88:
    // 0x8018CE88: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8018CE8C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8018CE90: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x8018CE94: bne         $t0, $zero, L_8018CFA8
    if (ctx->r8 != 0) {
        // 0x8018CE98: nop
    
            goto L_8018CFA8;
    }
    // 0x8018CE98: nop

    // 0x8018CE9C: jal         0x80004EB0
    // 0x8018CEA0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8018CEA0: nop

    after_0:
    // 0x8018CEA4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018CEA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018CEAC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018CEB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018CEB4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018CEB8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018CEBC: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8018CEC0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8018CEC4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018CEC8: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8018CECC: jal         0x80004EB0
    // 0x8018CED0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018CED0: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8018CED4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018CED8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018CEDC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018CEE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018CEE4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8018CEE8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018CEEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018CEF0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018CEF4: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8018CEF8: lwc1        $f10, 0x118($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8018CEFC: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8018CF00: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018CF04: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018CF08: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018CF0C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8018CF10: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018CF14: lwc1        $f10, 0x11C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8018CF18: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018CF1C: jal         0x80005100
    // 0x8018CF20: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x8018CF20: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8018CF24: jal         0x8009F768
    // 0x8018CF28: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x8018CF28: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x8018CF2C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018CF30: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018CF34: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8018CF38: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8018CF3C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018CF40: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8018CF44: swc1        $f2, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f2.u32l;
    // 0x8018CF48: bc1fl       L_8018CF60
    if (!c1cs) {
        // 0x8018CF4C: lwc1        $f0, 0x12C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
            goto L_8018CF60;
    }
    goto skip_1;
    // 0x8018CF4C: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
    skip_1:
    // 0x8018CF50: lwc1        $f8, 0x12C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x8018CF54: sub.s       $f18, $f8, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x8018CF58: swc1        $f18, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f18.u32l;
    // 0x8018CF5C: lwc1        $f0, 0x12C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X12C);
L_8018CF60:
    // 0x8018CF60: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8018CF64: nop

    // 0x8018CF68: bc1fl       L_8018CF7C
    if (!c1cs) {
        // 0x8018CF6C: lwc1        $f16, 0x34($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
            goto L_8018CF7C;
    }
    goto skip_2;
    // 0x8018CF6C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    skip_2:
    // 0x8018CF70: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8018CF74: swc1        $f4, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f4.u32l;
    // 0x8018CF78: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
L_8018CF7C:
    // 0x8018CF7C: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018CF80: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018CF84: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018CF88: nop

    // 0x8018CF8C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018CF90: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018CF94: jal         0x80005100
    // 0x8018CF98: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_4;
    // 0x8018CF98: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_4:
    // 0x8018CF9C: jal         0x8009F768
    // 0x8018CFA0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_5;
    // 0x8018CFA0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x8018CFA4: swc1        $f0, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f0.u32l;
L_8018CFA8:
    // 0x8018CFA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CFAC: lwc1        $f2, -0x694($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X694);
    // 0x8018CFB0: lw          $a1, 0x128($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X128);
    // 0x8018CFB4: lui         $a3, 0x4099
    ctx->r7 = S32(0X4099 << 16);
    // 0x8018CFB8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8018CFBC: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8018CFC0: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x8018CFC4: jal         0x8009BC2C
    // 0x8018CFC8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8018CFC8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x8018CFCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018CFD0: lwc1        $f2, -0x690($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X690);
    // 0x8018CFD4: lw          $a1, 0x12C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X12C);
    // 0x8018CFD8: lui         $a3, 0x4099
    ctx->r7 = S32(0X4099 << 16);
    // 0x8018CFDC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8018CFE0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x8018CFE4: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8018CFE8: jal         0x8009BC2C
    // 0x8018CFEC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8018CFEC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_7:
    // 0x8018CFF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018CFF4:
    // 0x8018CFF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018CFF8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018CFFC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018D000: jr          $ra
    // 0x8018D004: nop

    return;
    // 0x8018D004: nop

;}
RECOMP_FUNC void Bolse_BoBaseShield_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018ECB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018ECB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018ECBC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018ECC0: jal         0x80061404
    // 0x8018ECC4: addiu       $a0, $a0, -0xAE8
    ctx->r4 = ADD32(ctx->r4, -0XAE8);
    Boss_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018ECC4: addiu       $a0, $a0, -0xAE8
    ctx->r4 = ADD32(ctx->r4, -0XAE8);
    after_0:
    // 0x8018ECC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018ECCC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018ECD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ECD4: sb          $t6, -0xAE8($at)
    MEM_B(-0XAE8, ctx->r1) = ctx->r14;
    // 0x8018ECD8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018ECDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ECE0: swc1        $f4, -0xAE4($at)
    MEM_W(-0XAE4, ctx->r1) = ctx->f4.u32l;
    // 0x8018ECE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ECE8: swc1        $f6, -0xAE0($at)
    MEM_W(-0XAE0, ctx->r1) = ctx->f6.u32l;
    // 0x8018ECEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ECF0: lwc1        $f8, -0x658($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X658);
    // 0x8018ECF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ECF8: addiu       $a1, $zero, 0x136
    ctx->r5 = ADD32(0, 0X136);
    // 0x8018ECFC: swc1        $f8, -0xADC($at)
    MEM_W(-0XADC, ctx->r1) = ctx->f8.u32l;
    // 0x8018ED00: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018ED04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018ED08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ED0C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018ED10: swc1        $f10, -0xAD8($at)
    MEM_W(-0XAD8, ctx->r1) = ctx->f10.u32l;
    // 0x8018ED14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018ED18: lwc1        $f16, -0x654($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X654);
    // 0x8018ED1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ED20: addiu       $a0, $a0, -0xACC
    ctx->r4 = ADD32(ctx->r4, -0XACC);
    // 0x8018ED24: swc1        $f16, -0x6F0($at)
    MEM_W(-0X6F0, ctx->r1) = ctx->f16.u32l;
    // 0x8018ED28: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ED2C: jal         0x800612B8
    // 0x8018ED30: sh          $a1, -0xAE6($at)
    MEM_H(-0XAE6, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8018ED30: sh          $a1, -0xAE6($at)
    MEM_H(-0XAE6, ctx->r1) = ctx->r5;
    after_1:
    // 0x8018ED34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018ED38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018ED3C: jr          $ra
    // 0x8018ED40: nop

    return;
    // 0x8018ED40: nop

;}
RECOMP_FUNC void Katina_801981F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801981F8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801981FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80198200: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80198204: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80198208: lhu         $t6, 0xC0($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XC0);
    // 0x8019820C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80198210: bnel        $t6, $zero, L_8019847C
    if (ctx->r14 != 0) {
        // 0x80198214: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019847C;
    }
    goto skip_0;
    // 0x80198214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80198218: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8019821C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80198220: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198224: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x80198228: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8019822C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80198230: beq         $t8, $zero, L_80198478
    if (ctx->r24 == 0) {
        // 0x80198234: lui         $s0, 0x8016
        ctx->r16 = S32(0X8016 << 16);
            goto L_80198478;
    }
    // 0x80198234: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80198238: sh          $t9, 0xC0($a1)
    MEM_H(0XC0, ctx->r5) = ctx->r25;
    // 0x8019823C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80198240: lh          $t0, -0xA9A($t0)
    ctx->r8 = MEM_H(ctx->r8, -0XA9A);
    // 0x80198244: lwc1        $f4, 0x20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X20);
    // 0x80198248: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8019824C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80198250: beq         $t0, $zero, L_80198264
    if (ctx->r8 == 0) {
        // 0x80198254: swc1        $f4, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
            goto L_80198264;
    }
    // 0x80198254: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80198258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019825C: lwc1        $f6, 0x24($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X24);
    // 0x80198260: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
L_80198264:
    // 0x80198264: addiu       $s0, $s0, 0x5D68
    ctx->r16 = ADD32(ctx->r16, 0X5D68);
    // 0x80198268: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_8019826C:
    // 0x8019826C: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x80198270: bne         $t1, $zero, L_8019846C
    if (ctx->r9 != 0) {
        // 0x80198274: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019846C;
    }
    // 0x80198274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198278: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8019827C: jal         0x800613C4
    // 0x80198280: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80198280: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    after_0:
    // 0x80198284: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80198288: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8019828C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80198290: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x80198294: lbu         $t2, -0xBD0($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0XBD0);
    // 0x80198298: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8019829C: addiu       $t6, $zero, 0xC5
    ctx->r14 = ADD32(0, 0XC5);
    // 0x801982A0: sh          $t2, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r10;
    // 0x801982A4: lh          $t3, 0xB6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB6);
    // 0x801982A8: bnel        $t3, $zero, L_801982C0
    if (ctx->r11 != 0) {
        // 0x801982AC: sb          $t5, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r13;
            goto L_801982C0;
    }
    goto skip_1;
    // 0x801982AC: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    skip_1:
    // 0x801982B0: lh          $t4, -0xA9A($t4)
    ctx->r12 = MEM_H(ctx->r12, -0XA9A);
    // 0x801982B4: bnel        $t4, $zero, L_8019847C
    if (ctx->r12 != 0) {
        // 0x801982B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019847C;
    }
    goto skip_2;
    // 0x801982B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x801982BC: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
L_801982C0:
    // 0x801982C0: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x801982C4: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x801982C8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801982CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801982D0: lh          $t8, 0x4E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4E);
    // 0x801982D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801982D8: lwc1        $f4, 0x28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X28);
    // 0x801982DC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801982E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801982E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801982E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801982EC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x801982F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801982F4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801982F8: nop

    // 0x801982FC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80198300: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80198304: jal         0x80005E90
    // 0x80198308: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80198308: nop

    after_1:
    // 0x8019830C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198310: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80198314: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80198318: jal         0x80006A20
    // 0x8019831C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8019831C: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_2:
    // 0x80198320: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80198324: jal         0x80004EB0
    // 0x80198328: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80198328: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x8019832C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80198330: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80198334: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80198338: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019833C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80198340: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x80198344: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80198348: lh          $t5, 0xB6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB6);
    // 0x8019834C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80198350: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80198354: addiu       $t1, $v0, 0xA
    ctx->r9 = ADD32(ctx->r2, 0XA);
    // 0x80198358: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019835C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198360: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80198364: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80198368: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x8019836C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80198370: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198374: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80198378: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8019837C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80198380: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x80198384: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80198388: lh          $t0, 0x4E($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4E);
    // 0x8019838C: sh          $v1, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r3;
    // 0x80198390: sh          $t1, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r9;
    // 0x80198394: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80198398: addiu       $t6, $zero, 0x3E8
    ctx->r14 = ADD32(0, 0X3E8);
    // 0x8019839C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801983A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801983A4: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x801983A8: addiu       $t9, $zero, 0x16
    ctx->r25 = ADD32(0, 0X16);
    // 0x801983AC: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x801983B0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801983B4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801983B8: swc1        $f18, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f18.u32l;
    // 0x801983BC: lw          $t3, -0xBBC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0XBBC);
    // 0x801983C0: sh          $t4, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r12;
    // 0x801983C4: swc1        $f4, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f4.u32l;
    // 0x801983C8: bne         $at, $zero, L_801983D4
    if (ctx->r1 != 0) {
        // 0x801983CC: sh          $t3, 0xE6($s0)
        MEM_H(0XE6, ctx->r16) = ctx->r11;
            goto L_801983D4;
    }
    // 0x801983CC: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
    // 0x801983D0: sh          $t6, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r14;
L_801983D4:
    // 0x801983D4: sw          $v1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r3;
    // 0x801983D8: sb          $t7, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r15;
    // 0x801983DC: lw          $t8, 0x540($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X540);
    // 0x801983E0: slti        $at, $t8, 0x2580
    ctx->r1 = SIGNED(ctx->r24) < 0X2580 ? 1 : 0;
    // 0x801983E4: beql        $at, $zero, L_801983F4
    if (ctx->r1 == 0) {
        // 0x801983E8: sh          $t0, 0xC2($s0)
        MEM_H(0XC2, ctx->r16) = ctx->r8;
            goto L_801983F4;
    }
    goto skip_3;
    // 0x801983E8: sh          $t0, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r8;
    skip_3:
    // 0x801983EC: sb          $t9, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r25;
    // 0x801983F0: sh          $t0, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r8;
L_801983F4:
    // 0x801983F4: jal         0x800612B8
    // 0x801983F8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x801983F8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_4:
    // 0x801983FC: lh          $t1, 0xB6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XB6);
    // 0x80198400: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80198404: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80198408: bne         $v1, $t1, L_80198440
    if (ctx->r3 != ctx->r9) {
        // 0x8019840C: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_80198440;
    }
    // 0x8019840C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80198410: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80198414: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80198418: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
    // 0x8019841C: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80198420: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80198424: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
    // 0x80198428: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019842C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80198430: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80198434: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80198438: jal         0x80019218
    // 0x8019843C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x8019843C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_80198440:
    // 0x80198440: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80198444: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x80198448: addiu       $t3, $t3, -0x7560
    ctx->r11 = ADD32(ctx->r11, -0X7560);
    // 0x8019844C: addiu       $t4, $t4, -0x6A4C
    ctx->r12 = ADD32(ctx->r12, -0X6A4C);
    // 0x80198450: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
    // 0x80198454: sw          $t4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r12;
    // 0x80198458: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8019845C: lh          $t6, 0x4E($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X4E);
    // 0x80198460: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80198464: b           L_80198478
    // 0x80198468: sh          $t7, 0x4E($t5)
    MEM_H(0X4E, ctx->r13) = ctx->r15;
        goto L_80198478;
    // 0x80198468: sh          $t7, 0x4E($t5)
    MEM_H(0X4E, ctx->r13) = ctx->r15;
L_8019846C:
    // 0x8019846C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80198470: bne         $v0, $v1, L_8019826C
    if (ctx->r2 != ctx->r3) {
        // 0x80198474: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8019826C;
    }
    // 0x80198474: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_80198478:
    // 0x80198478: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019847C:
    // 0x8019847C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80198480: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80198484: jr          $ra
    // 0x80198488: nop

    return;
    // 0x80198488: nop

;}
RECOMP_FUNC void Fortuna_FoRadar_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188AD0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80188AD4: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80188AD8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80188ADC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80188AE0: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80188AE4: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80188AE8: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80188AEC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80188AF0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80188AF4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80188AF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188AFC: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80188B00: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x80188B04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80188B08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80188B0C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80188B10: bne         $t6, $at, L_80188CE4
    if (ctx->r14 != ctx->r1) {
        // 0x80188B14: swc1        $f8, 0x114($s0)
        MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
            goto L_80188CE4;
    }
    // 0x80188B14: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
    // 0x80188B18: jal         0x80004EB0
    // 0x80188B1C: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80188B1C: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    after_0:
    // 0x80188B20: jal         0x80004EB0
    // 0x80188B24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80188B24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_1:
    // 0x80188B28: jal         0x80004EB0
    // 0x80188B2C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80188B2C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x80188B30: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80188B34: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80188B38: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80188B3C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80188B40: sub.s       $f10, $f22, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x80188B44: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80188B48: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80188B4C: sub.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80188B50: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80188B54: addiu       $t8, $zero, 0x24
    ctx->r24 = ADD32(0, 0X24);
    // 0x80188B58: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80188B5C: mul.s       $f18, $f20, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80188B60: addiu       $a0, $s0, 0x18C
    ctx->r4 = ADD32(ctx->r16, 0X18C);
    // 0x80188B64: addiu       $a1, $s0, 0x1D4
    ctx->r5 = ADD32(ctx->r16, 0X1D4);
    // 0x80188B68: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80188B6C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80188B70: add.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x80188B74: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80188B78: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80188B7C: jal         0x80188A48
    // 0x80188B80: nop

    Fortuna_ActorDebris_Spawn(rdram, ctx);
        goto after_3;
    // 0x80188B80: nop

    after_3:
    // 0x80188B84: jal         0x80004EB0
    // 0x80188B88: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80188B88: nop

    after_4:
    // 0x80188B8C: jal         0x80004EB0
    // 0x80188B90: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x80188B90: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_5:
    // 0x80188B94: jal         0x80004EB0
    // 0x80188B98: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x80188B98: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x80188B9C: sub.s       $f10, $f22, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x80188BA0: addiu       $t9, $zero, 0x24
    ctx->r25 = ADD32(0, 0X24);
    // 0x80188BA4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80188BA8: sub.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80188BAC: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80188BB0: addiu       $a0, $s0, 0x198
    ctx->r4 = ADD32(ctx->r16, 0X198);
    // 0x80188BB4: addiu       $a1, $s0, 0x1E0
    ctx->r5 = ADD32(ctx->r16, 0X1E0);
    // 0x80188BB8: mul.s       $f18, $f20, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80188BBC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80188BC0: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80188BC4: add.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x80188BC8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80188BCC: jal         0x80188A48
    // 0x80188BD0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Fortuna_ActorDebris_Spawn(rdram, ctx);
        goto after_7;
    // 0x80188BD0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x80188BD4: jal         0x80004EB0
    // 0x80188BD8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80188BD8: nop

    after_8:
    // 0x80188BDC: jal         0x80004EB0
    // 0x80188BE0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80188BE0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_9:
    // 0x80188BE4: jal         0x80004EB0
    // 0x80188BE8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x80188BE8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_10:
    // 0x80188BEC: sub.s       $f10, $f22, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x80188BF0: addiu       $t0, $zero, 0x23
    ctx->r8 = ADD32(0, 0X23);
    // 0x80188BF4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80188BF8: sub.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80188BFC: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80188C00: addiu       $a0, $s0, 0x1A4
    ctx->r4 = ADD32(ctx->r16, 0X1A4);
    // 0x80188C04: addiu       $a1, $s0, 0x1EC
    ctx->r5 = ADD32(ctx->r16, 0X1EC);
    // 0x80188C08: mul.s       $f18, $f20, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80188C0C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80188C10: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80188C14: add.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x80188C18: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80188C1C: jal         0x80188A48
    // 0x80188C20: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Fortuna_ActorDebris_Spawn(rdram, ctx);
        goto after_11;
    // 0x80188C20: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80188C24: jal         0x80004EB0
    // 0x80188C28: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x80188C28: nop

    after_12:
    // 0x80188C2C: jal         0x80004EB0
    // 0x80188C30: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x80188C30: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_13:
    // 0x80188C34: jal         0x80004EB0
    // 0x80188C38: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x80188C38: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_14:
    // 0x80188C3C: sub.s       $f10, $f22, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x80188C40: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x80188C44: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80188C48: sub.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80188C4C: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80188C50: addiu       $a0, $s0, 0x1B0
    ctx->r4 = ADD32(ctx->r16, 0X1B0);
    // 0x80188C54: addiu       $a1, $s0, 0x1F8
    ctx->r5 = ADD32(ctx->r16, 0X1F8);
    // 0x80188C58: mul.s       $f18, $f20, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80188C5C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80188C60: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80188C64: add.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x80188C68: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80188C6C: jal         0x80188A48
    // 0x80188C70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Fortuna_ActorDebris_Spawn(rdram, ctx);
        goto after_15;
    // 0x80188C70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80188C74: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80188C78: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80188C7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80188C80: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188C84: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80188C88: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80188C8C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80188C90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188C94: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80188C98: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80188C9C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80188CA0: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80188CA4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80188CA8: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80188CAC: jal         0x8007BFFC
    // 0x80188CB0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_16;
    // 0x80188CB0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_16:
    // 0x80188CB4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80188CB8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80188CBC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188CC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80188CC4: sb          $t3, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r11;
    // 0x80188CC8: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80188CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80188CD0: jal         0x80066254
    // 0x80188CD4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    Actor_Despawn(rdram, ctx);
        goto after_17;
    // 0x80188CD4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    after_17:
    // 0x80188CD8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188CDC: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x80188CE0: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
L_80188CE4:
    // 0x80188CE4: lb          $t4, 0xD0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XD0);
    // 0x80188CE8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80188CEC: beql        $t4, $zero, L_80188D80
    if (ctx->r12 == 0) {
        // 0x80188CF0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80188D80;
    }
    goto skip_0;
    // 0x80188CF0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x80188CF4: lh          $t5, 0xB8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB8);
    // 0x80188CF8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188CFC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188D00: bne         $t5, $zero, L_80188D7C
    if (ctx->r13 != 0) {
        // 0x80188D04: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80188D7C;
    }
    // 0x80188D04: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80188D08: lui         $v0, 0x601
    ctx->r2 = S32(0X601 << 16);
    // 0x80188D0C: addiu       $v0, $v0, -0x9C
    ctx->r2 = ADD32(ctx->r2, -0X9C);
    // 0x80188D10: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80188D14: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x80188D18: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80188D1C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80188D20: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x80188D24: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
    // 0x80188D28: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80188D2C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80188D30: lw          $t0, 0x1FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FD0);
    // 0x80188D34: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80188D38: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x80188D3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80188D40: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80188D44: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x80188D48: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80188D4C: sw          $t3, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r11;
    // 0x80188D50: swc1        $f20, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f20.u32l;
    // 0x80188D54: sb          $zero, 0xCA($s0)
    MEM_B(0XCA, ctx->r16) = 0;
    // 0x80188D58: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
    // 0x80188D5C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x80188D60: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80188D64: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x80188D68: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80188D6C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188D70: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80188D74: jal         0x80019218
    // 0x80188D78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x80188D78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_18:
L_80188D7C:
    // 0x80188D7C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80188D80:
    // 0x80188D80: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80188D84: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80188D88: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80188D8C: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x80188D90: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x80188D94: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80188D98: jr          $ra
    // 0x80188D9C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80188D9C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Katina_EnemyDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801995B4: addiu       $sp, $sp, -0x1D0
    ctx->r29 = ADD32(ctx->r29, -0X1D0);
    // 0x801995B8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801995BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801995C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801995C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801995C8: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x801995CC: addiu       $t7, $t7, -0xB58
    ctx->r15 = ADD32(ctx->r15, -0XB58);
    // 0x801995D0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801995D4: addiu       $t6, $sp, 0x1B4
    ctx->r14 = ADD32(ctx->r29, 0X1B4);
    // 0x801995D8: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801995DC: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801995E0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801995E4: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801995E8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801995EC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801995F0: lw          $t2, 0x7E7C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7E7C);
    // 0x801995F4: lw          $t1, 0x40($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X40);
    // 0x801995F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801995FC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80199600: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80199604: andi        $t4, $t3, 0x7
    ctx->r12 = ctx->r11 & 0X7;
    // 0x80199608: bne         $t4, $zero, L_80199660
    if (ctx->r12 != 0) {
        // 0x8019960C: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_80199660;
    }
    // 0x8019960C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80199610: lwc1        $f2, 0xAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XAC);
    // 0x80199614: sw          $t5, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r13;
    // 0x80199618: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8019961C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80199620: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80199624: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80199628: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019962C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80199630: nop

    // 0x80199634: bc1fl       L_80199664
    if (!c1cs) {
        // 0x80199638: lw          $v0, 0x70($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X70);
            goto L_80199664;
    }
    goto skip_0;
    // 0x80199638: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    skip_0:
    // 0x8019963C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80199640: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80199644: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80199648: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8019964C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80199650: nop

    // 0x80199654: bc1fl       L_80199664
    if (!c1cs) {
        // 0x80199658: lw          $v0, 0x70($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X70);
            goto L_80199664;
    }
    goto skip_1;
    // 0x80199658: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
    skip_1:
    // 0x8019965C: sw          $zero, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = 0;
L_80199660:
    // 0x80199660: lw          $v0, 0x70($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X70);
L_80199664:
    // 0x80199664: beql        $v0, $zero, L_80199718
    if (ctx->r2 == 0) {
        // 0x80199668: lw          $t6, 0xAC($s1)
        ctx->r14 = MEM_W(ctx->r17, 0XAC);
            goto L_80199718;
    }
    goto skip_2;
    // 0x80199668: lw          $t6, 0xAC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XAC);
    skip_2:
    // 0x8019966C: lh          $t9, 0xE4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XE4);
    // 0x80199670: slti        $at, $t9, 0x64
    ctx->r1 = SIGNED(ctx->r25) < 0X64 ? 1 : 0;
    // 0x80199674: beql        $at, $zero, L_80199718
    if (ctx->r1 == 0) {
        // 0x80199678: lw          $t6, 0xAC($s1)
        ctx->r14 = MEM_W(ctx->r17, 0XAC);
            goto L_80199718;
    }
    goto skip_3;
    // 0x80199678: lw          $t6, 0xAC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XAC);
    skip_3:
    // 0x8019967C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80199680: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80199684: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199688: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8019968C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199690: lwc1        $f8, 0xB0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XB0);
    // 0x80199694: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80199698: nop

    // 0x8019969C: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801996A0: jal         0x80023090
    // 0x801996A4: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x801996A4: nop

    after_0:
    // 0x801996A8: lw          $t8, 0x70($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X70);
    // 0x801996AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801996B0: lwc1        $f18, 0xB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XB4);
    // 0x801996B4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x801996B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801996BC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801996C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801996C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801996C8: mul.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801996CC: nop

    // 0x801996D0: mul.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x801996D4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801996D8: jal         0x80005E90
    // 0x801996DC: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801996DC: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x801996E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801996E4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801996E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801996EC: jal         0x80005D44
    // 0x801996F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801996F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x801996F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801996F8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801996FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80199700: jal         0x80005FE0
    // 0x80199704: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80199704: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x80199708: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019970C: jal         0x80006EB8
    // 0x80199710: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x80199710: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    after_4:
    // 0x80199714: lw          $t6, 0xAC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XAC);
L_80199718:
    // 0x80199718: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019971C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80199720: beq         $t6, $zero, L_8019975C
    if (ctx->r14 == 0) {
        // 0x80199724: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019975C;
    }
    // 0x80199724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80199728: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019972C: jal         0x800B8DD0
    // 0x80199730: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x80199730: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_5:
    // 0x80199734: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80199738: lui         $t1, 0x5040
    ctx->r9 = S32(0X5040 << 16);
    // 0x8019973C: ori         $t1, $t1, 0x40FF
    ctx->r9 = ctx->r9 | 0X40FF;
    // 0x80199740: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80199744: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80199748: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8019974C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80199750: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80199754: b           L_80199768
    // 0x80199758: lhu         $t2, 0xC6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC6);
        goto L_80199768;
    // 0x80199758: lhu         $t2, 0xC6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC6);
L_8019975C:
    // 0x8019975C: jal         0x800B8DD0
    // 0x80199760: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x80199760: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_6:
    // 0x80199764: lhu         $t2, 0xC6($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XC6);
L_80199768:
    // 0x80199768: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x8019976C: ori         $t5, $t5, 0x8
    ctx->r13 = ctx->r13 | 0X8;
    // 0x80199770: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80199774: bne         $t3, $zero, L_80199820
    if (ctx->r11 != 0) {
        // 0x80199778: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80199820;
    }
    // 0x80199778: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019977C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80199780: addiu       $t9, $zero, 0x3ED
    ctx->r25 = ADD32(0, 0X3ED);
    // 0x80199784: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80199788: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019978C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80199790: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80199794: lw          $a0, -0x7C28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7C28);
    // 0x80199798: ori         $t8, $t8, 0xF400
    ctx->r24 = ctx->r24 | 0XF400;
    // 0x8019979C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801997A0: subu        $a1, $t9, $a0
    ctx->r5 = SUB32(ctx->r25, ctx->r4);
    // 0x801997A4: div         $zero, $t8, $a1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r5)));
    // 0x801997A8: negu        $t1, $a0
    ctx->r9 = SUB32(0, ctx->r4);
    // 0x801997AC: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x801997B0: addu        $t3, $t2, $t8
    ctx->r11 = ADD32(ctx->r10, ctx->r24);
    // 0x801997B4: mflo        $t6
    ctx->r14 = lo;
    // 0x801997B8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x801997BC: bne         $a1, $zero, L_801997C8
    if (ctx->r5 != 0) {
        // 0x801997C0: nop
    
            goto L_801997C8;
    }
    // 0x801997C0: nop

    // 0x801997C4: break       7
    do_break(2149160900);
L_801997C8:
    // 0x801997C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801997CC: bne         $a1, $at, L_801997E0
    if (ctx->r5 != ctx->r1) {
        // 0x801997D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801997E0;
    }
    // 0x801997D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801997D4: bne         $t8, $at, L_801997E0
    if (ctx->r24 != ctx->r1) {
        // 0x801997D8: nop
    
            goto L_801997E0;
    }
    // 0x801997D8: nop

    // 0x801997DC: break       6
    do_break(2149160924);
L_801997E0:
    // 0x801997E0: div         $zero, $t3, $a1
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r5)));
    // 0x801997E4: addu        $at, $t8, $zero
    ctx->r1 = ADD32(ctx->r24, 0);
    // 0x801997E8: mflo        $t4
    ctx->r12 = lo;
    // 0x801997EC: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x801997F0: sll         $t0, $t7, 16
    ctx->r8 = S32(ctx->r15 << 16);
    // 0x801997F4: or          $t9, $t0, $t5
    ctx->r25 = ctx->r8 | ctx->r13;
    // 0x801997F8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801997FC: bne         $a1, $zero, L_80199808
    if (ctx->r5 != 0) {
        // 0x80199800: nop
    
            goto L_80199808;
    }
    // 0x80199800: nop

    // 0x80199804: break       7
    do_break(2149160964);
L_80199808:
    // 0x80199808: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019980C: bne         $a1, $at, L_80199820
    if (ctx->r5 != ctx->r1) {
        // 0x80199810: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80199820;
    }
    // 0x80199810: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80199814: bne         $t3, $at, L_80199820
    if (ctx->r11 != ctx->r1) {
        // 0x80199818: nop
    
            goto L_80199820;
    }
    // 0x80199818: nop

    // 0x8019981C: break       6
    do_break(2149160988);
L_80199820:
    // 0x80199820: lh          $v0, 0xB6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB6);
    // 0x80199824: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80199828: beql        $v0, $zero, L_80199844
    if (ctx->r2 == 0) {
        // 0x8019982C: lw          $t8, 0xAC($s1)
        ctx->r24 = MEM_W(ctx->r17, 0XAC);
            goto L_80199844;
    }
    goto skip_4;
    // 0x8019982C: lw          $t8, 0xAC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XAC);
    skip_4:
    // 0x80199830: beq         $v0, $at, L_8019989C
    if (ctx->r2 == ctx->r1) {
        // 0x80199834: lui         $t5, 0x600
        ctx->r13 = S32(0X600 << 16);
            goto L_8019989C;
    }
    // 0x80199834: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80199838: b           L_801998EC
    // 0x8019983C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801998EC;
    // 0x8019983C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80199840: lw          $t8, 0xAC($s1)
    ctx->r24 = MEM_W(ctx->r17, 0XAC);
L_80199844:
    // 0x80199844: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80199848: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8019984C: beql        $t8, $zero, L_8019987C
    if (ctx->r24 == 0) {
        // 0x80199850: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8019987C;
    }
    goto skip_5;
    // 0x80199850: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x80199854: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80199858: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x8019985C: addiu       $t1, $t1, -0x1010
    ctx->r9 = ADD32(ctx->r9, -0X1010);
    // 0x80199860: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80199864: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80199868: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8019986C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80199870: b           L_801998EC
    // 0x80199874: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801998EC;
    // 0x80199874: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80199878: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8019987C:
    // 0x8019987C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80199880: addiu       $t4, $t4, 0x1530
    ctx->r12 = ADD32(ctx->r12, 0X1530);
    // 0x80199884: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80199888: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8019988C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80199890: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80199894: b           L_801998EC
    // 0x80199898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801998EC;
    // 0x80199898: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019989C:
    // 0x8019989C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801998A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801998A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801998A8: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x801998AC: addiu       $t9, $t9, -0x1FB0
    ctx->r25 = ADD32(ctx->r25, -0X1FB0);
    // 0x801998B0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801998B4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801998B8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801998BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801998C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801998C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801998C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801998CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801998D0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801998D4: jal         0x80005B00
    // 0x801998D8: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_7;
    // 0x801998D8: lui         $a3, 0xC270
    ctx->r7 = S32(0XC270 << 16);
    after_7:
    // 0x801998DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801998E0: jal         0x8005B1E8
    // 0x801998E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Actor_DrawEngineGlow(rdram, ctx);
        goto after_8;
    // 0x801998E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x801998E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801998EC:
    // 0x801998EC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801998F0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801998F4: jr          $ra
    // 0x801998F8: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
    return;
    // 0x801998F8: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
;}
RECOMP_FUNC void SectorZ_SzGreatFox_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E98C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019E990: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8019E994: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x8019E998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019E99C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8019E9A0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8019E9A4: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x8019E9A8: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x8019E9AC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8019E9B0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8019E9B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019E9B8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019E9BC: lw          $a0, -0x7C28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7C28);
    // 0x8019E9C0: addiu       $t8, $zero, 0x3ED
    ctx->r24 = ADD32(0, 0X3ED);
    // 0x8019E9C4: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x8019E9C8: subu        $a1, $t8, $a0
    ctx->r5 = SUB32(ctx->r24, ctx->r4);
    // 0x8019E9CC: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x8019E9D0: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x8019E9D4: negu        $t3, $a0
    ctx->r11 = SUB32(0, ctx->r4);
    // 0x8019E9D8: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x8019E9DC: addu        $t5, $t4, $t9
    ctx->r13 = ADD32(ctx->r12, ctx->r25);
    // 0x8019E9E0: mflo        $t0
    ctx->r8 = lo;
    // 0x8019E9E4: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8019E9E8: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8019E9EC: div         $zero, $t5, $a1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r5)));
    // 0x8019E9F0: mflo        $t6
    ctx->r14 = lo;
    // 0x8019E9F4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8019E9F8: or          $t8, $t2, $t7
    ctx->r24 = ctx->r10 | ctx->r15;
    // 0x8019E9FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8019EA00: bne         $a1, $zero, L_8019EA0C
    if (ctx->r5 != 0) {
        // 0x8019EA04: nop
    
            goto L_8019EA0C;
    }
    // 0x8019EA04: nop

    // 0x8019EA08: break       7
    do_break(2149181960);
L_8019EA0C:
    // 0x8019EA0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019EA10: bne         $a1, $at, L_8019EA24
    if (ctx->r5 != ctx->r1) {
        // 0x8019EA14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8019EA24;
    }
    // 0x8019EA14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019EA18: bne         $t9, $at, L_8019EA24
    if (ctx->r25 != ctx->r1) {
        // 0x8019EA1C: nop
    
            goto L_8019EA24;
    }
    // 0x8019EA1C: nop

    // 0x8019EA20: break       6
    do_break(2149181984);
L_8019EA24:
    // 0x8019EA24: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x8019EA28: bne         $a1, $zero, L_8019EA34
    if (ctx->r5 != 0) {
        // 0x8019EA2C: nop
    
            goto L_8019EA34;
    }
    // 0x8019EA2C: nop

    // 0x8019EA30: break       7
    do_break(2149182000);
L_8019EA34:
    // 0x8019EA34: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019EA38: bne         $a1, $at, L_8019EA4C
    if (ctx->r5 != ctx->r1) {
        // 0x8019EA3C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8019EA4C;
    }
    // 0x8019EA3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019EA40: bne         $t5, $at, L_8019EA4C
    if (ctx->r13 != ctx->r1) {
        // 0x8019EA44: nop
    
            goto L_8019EA4C;
    }
    // 0x8019EA44: nop

    // 0x8019EA48: break       6
    do_break(2149182024);
L_8019EA4C:
    // 0x8019EA4C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019EA50: jal         0x800515C4
    // 0x8019EA54: nop

    Cutscene_DrawGreatFox(rdram, ctx);
        goto after_0;
    // 0x8019EA54: nop

    after_0:
    // 0x8019EA58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019EA5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019EA60: jr          $ra
    // 0x8019EA64: nop

    return;
    // 0x8019EA64: nop

;}
RECOMP_FUNC void Katina_IsActorCloseToBase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801989F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801989F8: lwc1        $f2, 0x40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X40);
    // 0x801989FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198A00: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80198A04: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80198A08: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80198A0C: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80198A10: lwc1        $f16, 0x44($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X44);
    // 0x80198A14: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80198A18: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80198A1C: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80198A20: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80198A24: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80198A28: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198A2C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80198A30: nop

    // 0x80198A34: bc1fl       L_80198A98
    if (!c1cs) {
        // 0x80198A38: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80198A98;
    }
    goto skip_0;
    // 0x80198A38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80198A3C: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80198A40: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80198A44: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80198A48: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80198A4C: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80198A50: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198A54: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80198A58: nop

    // 0x80198A5C: bc1fl       L_80198A98
    if (!c1cs) {
        // 0x80198A60: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80198A98;
    }
    goto skip_1;
    // 0x80198A60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80198A64: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80198A68: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80198A6C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80198A70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198A74: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80198A78: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80198A7C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80198A80: nop

    // 0x80198A84: bc1fl       L_80198A98
    if (!c1cs) {
        // 0x80198A88: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80198A98;
    }
    goto skip_2;
    // 0x80198A88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80198A8C: jr          $ra
    // 0x80198A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80198A90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80198A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80198A98:
    // 0x80198A98: jr          $ra
    // 0x80198A9C: nop

    return;
    // 0x80198A9C: nop

;}
RECOMP_FUNC void Bolse_BoBaseShield_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191DB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80191DB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80191DB8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80191DBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80191DC0: lwc1        $f0, 0x3F8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3F8);
    // 0x80191DC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191DC8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80191DCC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80191DD0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80191DD4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80191DD8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80191DDC: jal         0x80005C34
    // 0x80191DE0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x80191DE0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x80191DE4: lwc1        $f4, 0xD8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x80191DE8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80191DEC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80191DF0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80191DF4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80191DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80191DFC: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x80191E00: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x80191E04: nop

    // 0x80191E08: beql        $t0, $zero, L_80191EC8
    if (ctx->r8 == 0) {
        // 0x80191E0C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80191EC8;
    }
    goto skip_0;
    // 0x80191E0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80191E10: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80191E14: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80191E18: bne         $t9, $zero, L_80191E40
    if (ctx->r25 != 0) {
        // 0x80191E1C: nop
    
            goto L_80191E40;
    }
    // 0x80191E1C: nop

    // 0x80191E20: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80191E24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191E28: lwc1        $f16, -0x308($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X308);
    // 0x80191E2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80191E30: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80191E34: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80191E38: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x80191E3C: nop

L_80191E40:
    // 0x80191E40: jal         0x800B8DD0
    // 0x80191E44: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80191E44: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80191E48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80191E4C: lwc1        $f0, -0x304($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X304);
    // 0x80191E50: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80191E54: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80191E58: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x80191E5C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80191E60: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80191E64: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80191E68: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80191E6C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80191E70: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80191E74: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80191E78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80191E7C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80191E80: lui         $a2, 0x3F0C
    ctx->r6 = S32(0X3F0C << 16);
    // 0x80191E84: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80191E88: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80191E8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80191E90: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80191E94: jal         0x80005C34
    // 0x80191E98: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x80191E98: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x80191E9C: jal         0x80006EB8
    // 0x80191EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x80191EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80191EA4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80191EA8: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x80191EAC: addiu       $t9, $t9, -0x3B20
    ctx->r25 = ADD32(ctx->r25, -0X3B20);
    // 0x80191EB0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80191EB4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80191EB8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80191EBC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80191EC0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80191EC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80191EC8:
    // 0x80191EC8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80191ECC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80191ED0: jr          $ra
    // 0x80191ED4: nop

    return;
    // 0x80191ED4: nop

;}
RECOMP_FUNC void SectorZ_SpawnMissileEscort(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A0F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019A0FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019A100: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8019A104: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8019A108: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8019A10C: jal         0x800613C4
    // 0x8019A110: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8019A110: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8019A114: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8019A118: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8019A11C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019A120: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8019A124: addiu       $t7, $zero, 0xC5
    ctx->r15 = ADD32(0, 0XC5);
    // 0x8019A128: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8019A12C: addiu       $t8, $a3, 0xD
    ctx->r24 = ADD32(ctx->r7, 0XD);
    // 0x8019A130: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x8019A134: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019A138: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019A13C: addiu       $t0, $t0, -0xB1C
    ctx->r8 = ADD32(ctx->r8, -0XB1C);
    // 0x8019A140: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x8019A144: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x8019A148: sh          $t8, 0xE4($a2)
    MEM_H(0XE4, ctx->r6) = ctx->r24;
    // 0x8019A14C: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x8019A150: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8019A154: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019A158: lwc1        $f6, 0x1D8C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1D8C);
    // 0x8019A15C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019A160: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8019A164: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019A168: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8019A16C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8019A170: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x8019A174: lwc1        $f16, 0x1D90($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1D90);
    // 0x8019A178: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019A17C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019A180: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019A184: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
    // 0x8019A188: lwc1        $f6, 0x1D94($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1D94);
    // 0x8019A18C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019A190: sh          $t1, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r9;
    // 0x8019A194: swc1        $f10, 0xF8($a2)
    MEM_W(0XF8, ctx->r6) = ctx->f10.u32l;
    // 0x8019A198: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019A19C: jal         0x800612B8
    // 0x8019A1A0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8019A1A0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x8019A1A4: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019A1A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8019A1AC: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x8019A1B0: lwc1        $f16, 0x1EA0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1EA0);
    // 0x8019A1B4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8019A1B8: sw          $t2, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r10;
    // 0x8019A1BC: swc1        $f16, 0x118($a2)
    MEM_W(0X118, ctx->r6) = ctx->f16.u32l;
    // 0x8019A1C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019A1C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019A1C8: jr          $ra
    // 0x8019A1CC: nop

    return;
    // 0x8019A1CC: nop

;}
RECOMP_FUNC void Katina_SetOutcomingEnemyAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801945FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80194600: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80194604: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80194608: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8019460C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80194610: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80194614: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80194618: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x8019461C: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x80194620: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80194624: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80194628: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8019462C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80194630: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80194634: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80194638: mov.s       $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    ctx->f20.fl = ctx->f22.fl;
    // 0x8019463C: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x80194640: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
L_80194644:
    // 0x80194644: lh          $t6, 0x9C($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X9C);
    // 0x80194648: blezl       $t6, L_80194690
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8019464C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80194690;
    }
    goto skip_0;
    // 0x8019464C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80194650: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80194654: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80194658: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8019465C: add.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x80194660: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80194664: addu        $a1, $s1, $t7
    ctx->r5 = ADD32(ctx->r17, ctx->r15);
    // 0x80194668: addiu       $a1, $a1, 0x1AC
    ctx->r5 = ADD32(ctx->r5, 0X1AC);
    // 0x8019466C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80194670: nop

    // 0x80194674: bc1fl       L_80194684
    if (!c1cs) {
        // 0x80194678: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_80194684;
    }
    goto skip_1;
    // 0x80194678: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x8019467C: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80194680: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80194684:
    // 0x80194684: jal         0x80194458
    // 0x80194688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Katina_BossSpawnEnemies(rdram, ctx);
        goto after_0;
    // 0x80194688: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8019468C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80194690:
    // 0x80194690: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x80194694: bne         $s0, $s3, L_80194644
    if (ctx->r16 != ctx->r19) {
        // 0x80194698: sub.s       $f20, $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f24.fl;
            goto L_80194644;
    }
    // 0x80194698: sub.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8019469C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801946A0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801946A4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801946A8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801946AC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801946B0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801946B4: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x801946B8: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x801946BC: jr          $ra
    // 0x801946C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801946C0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void SectorZ_EnemyUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A3E8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8019A3EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019A3F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019A3F4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8019A3F8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019A3FC: lw          $t6, -0x6D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6D8);
    // 0x8019A400: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019A404: bltz        $t6, L_8019A5B8
    if (SIGNED(ctx->r14) < 0) {
        // 0x8019A408: nop
    
            goto L_8019A5B8;
    }
    // 0x8019A408: nop

    // 0x8019A40C: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x8019A410: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019A414: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x8019A418: blez        $t7, L_8019A480
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8019A41C: nop
    
            goto L_8019A480;
    }
    // 0x8019A41C: nop

    // 0x8019A420: lw          $t8, 0x34C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X34C);
    // 0x8019A424: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8019A428: bnel        $t8, $zero, L_8019A480
    if (ctx->r24 != 0) {
        // 0x8019A42C: sh          $t6, 0x3DA($t0)
        MEM_H(0X3DA, ctx->r8) = ctx->r14;
            goto L_8019A480;
    }
    goto skip_0;
    // 0x8019A42C: sh          $t6, 0x3DA($t0)
    MEM_H(0X3DA, ctx->r8) = ctx->r14;
    skip_0:
    // 0x8019A430: lbu         $t9, 0x1D88($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1D88);
    // 0x8019A434: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019A438: addiu       $t5, $zero, 0xD
    ctx->r13 = ADD32(0, 0XD);
    // 0x8019A43C: bne         $t9, $at, L_8019A474
    if (ctx->r25 != ctx->r1) {
        // 0x8019A440: nop
    
            goto L_8019A474;
    }
    // 0x8019A440: nop

    // 0x8019A444: lh          $t3, 0x3DA($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X3DA);
    // 0x8019A448: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8019A44C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A450: beq         $t3, $at, L_8019A468
    if (ctx->r11 == ctx->r1) {
        // 0x8019A454: addiu       $a0, $a0, 0x1154
        ctx->r4 = ADD32(ctx->r4, 0X1154);
            goto L_8019A468;
    }
    // 0x8019A454: addiu       $a0, $a0, 0x1154
    ctx->r4 = ADD32(ctx->r4, 0X1154);
    // 0x8019A458: jal         0x800BA808
    // 0x8019A45C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x8019A45C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x8019A460: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019A464: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
L_8019A468:
    // 0x8019A468: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8019A46C: b           L_8019A480
    // 0x8019A470: sh          $t4, 0x3DA($t0)
    MEM_H(0X3DA, ctx->r8) = ctx->r12;
        goto L_8019A480;
    // 0x8019A470: sh          $t4, 0x3DA($t0)
    MEM_H(0X3DA, ctx->r8) = ctx->r12;
L_8019A474:
    // 0x8019A474: b           L_8019A480
    // 0x8019A478: sh          $t5, 0x3DA($t0)
    MEM_H(0X3DA, ctx->r8) = ctx->r13;
        goto L_8019A480;
    // 0x8019A478: sh          $t5, 0x3DA($t0)
    MEM_H(0X3DA, ctx->r8) = ctx->r13;
    // 0x8019A47C: sh          $t6, 0x3DA($t0)
    MEM_H(0X3DA, ctx->r8) = ctx->r14;
L_8019A480:
    // 0x8019A480: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019A484: lw          $t7, 0x78BC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78BC);
    // 0x8019A488: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019A48C: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x8019A490: blez        $t7, L_8019A4F4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8019A494: nop
    
            goto L_8019A4F4;
    }
    // 0x8019A494: nop

    // 0x8019A498: lw          $t8, 0x934($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X934);
    // 0x8019A49C: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8019A4A0: bnel        $t8, $zero, L_8019A4F4
    if (ctx->r24 != 0) {
        // 0x8019A4A4: sh          $t5, 0x9C2($t0)
        MEM_H(0X9C2, ctx->r8) = ctx->r13;
            goto L_8019A4F4;
    }
    goto skip_1;
    // 0x8019A4A4: sh          $t5, 0x9C2($t0)
    MEM_H(0X9C2, ctx->r8) = ctx->r13;
    skip_1:
    // 0x8019A4A8: lbu         $t9, 0x2370($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X2370);
    // 0x8019A4AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019A4B0: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x8019A4B4: bne         $t9, $at, L_8019A4E8
    if (ctx->r25 != ctx->r1) {
        // 0x8019A4B8: nop
    
            goto L_8019A4E8;
    }
    // 0x8019A4B8: nop

    // 0x8019A4BC: lh          $t3, 0x9C2($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X9C2);
    // 0x8019A4C0: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x8019A4C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A4C8: beq         $s0, $t3, L_8019A4E0
    if (ctx->r16 == ctx->r11) {
        // 0x8019A4CC: addiu       $a0, $a0, 0x119C
        ctx->r4 = ADD32(ctx->r4, 0X119C);
            goto L_8019A4E0;
    }
    // 0x8019A4CC: addiu       $a0, $a0, 0x119C
    ctx->r4 = ADD32(ctx->r4, 0X119C);
    // 0x8019A4D0: jal         0x800BA808
    // 0x8019A4D4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8019A4D4: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_1:
    // 0x8019A4D8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019A4DC: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
L_8019A4E0:
    // 0x8019A4E0: b           L_8019A4F4
    // 0x8019A4E4: sh          $s0, 0x9C2($t0)
    MEM_H(0X9C2, ctx->r8) = ctx->r16;
        goto L_8019A4F4;
    // 0x8019A4E4: sh          $s0, 0x9C2($t0)
    MEM_H(0X9C2, ctx->r8) = ctx->r16;
L_8019A4E8:
    // 0x8019A4E8: b           L_8019A4F4
    // 0x8019A4EC: sh          $t4, 0x9C2($t0)
    MEM_H(0X9C2, ctx->r8) = ctx->r12;
        goto L_8019A4F4;
    // 0x8019A4EC: sh          $t4, 0x9C2($t0)
    MEM_H(0X9C2, ctx->r8) = ctx->r12;
    // 0x8019A4F0: sh          $t5, 0x9C2($t0)
    MEM_H(0X9C2, ctx->r8) = ctx->r13;
L_8019A4F4:
    // 0x8019A4F4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x8019A4F8: lw          $t6, 0x564($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X564);
    // 0x8019A4FC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8019A500: beq         $t6, $zero, L_8019A550
    if (ctx->r14 == 0) {
        // 0x8019A504: nop
    
            goto L_8019A550;
    }
    // 0x8019A504: nop

    // 0x8019A508: lbu         $t7, 0x207C($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X207C);
    // 0x8019A50C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019A510: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8019A514: bne         $t7, $at, L_8019A548
    if (ctx->r15 != ctx->r1) {
        // 0x8019A518: nop
    
            goto L_8019A548;
    }
    // 0x8019A518: nop

    // 0x8019A51C: lh          $t8, 0x1886($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X1886);
    // 0x8019A520: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
    // 0x8019A524: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A528: beq         $s0, $t8, L_8019A540
    if (ctx->r16 == ctx->r24) {
        // 0x8019A52C: addiu       $a0, $a0, 0x1504
        ctx->r4 = ADD32(ctx->r4, 0X1504);
            goto L_8019A540;
    }
    // 0x8019A52C: addiu       $a0, $a0, 0x1504
    ctx->r4 = ADD32(ctx->r4, 0X1504);
    // 0x8019A530: jal         0x800BA808
    // 0x8019A534: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x8019A534: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    after_2:
    // 0x8019A538: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019A53C: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
L_8019A540:
    // 0x8019A540: b           L_8019A5B8
    // 0x8019A544: sh          $s0, 0x1886($t0)
    MEM_H(0X1886, ctx->r8) = ctx->r16;
        goto L_8019A5B8;
    // 0x8019A544: sh          $s0, 0x1886($t0)
    MEM_H(0X1886, ctx->r8) = ctx->r16;
L_8019A548:
    // 0x8019A548: b           L_8019A5B8
    // 0x8019A54C: sh          $t9, 0x1886($t0)
    MEM_H(0X1886, ctx->r8) = ctx->r25;
        goto L_8019A5B8;
    // 0x8019A54C: sh          $t9, 0x1886($t0)
    MEM_H(0X1886, ctx->r8) = ctx->r25;
L_8019A550:
    // 0x8019A550: lw          $t3, 0x78B8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78B8);
    // 0x8019A554: blez        $t3, L_8019A5B8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8019A558: nop
    
            goto L_8019A5B8;
    }
    // 0x8019A558: nop

    // 0x8019A55C: lw          $t4, 0x640($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X640);
    // 0x8019A560: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8019A564: bnel        $t4, $zero, L_8019A5B8
    if (ctx->r12 != 0) {
        // 0x8019A568: sh          $t8, 0x6CE($t0)
        MEM_H(0X6CE, ctx->r8) = ctx->r24;
            goto L_8019A5B8;
    }
    goto skip_2;
    // 0x8019A568: sh          $t8, 0x6CE($t0)
    MEM_H(0X6CE, ctx->r8) = ctx->r24;
    skip_2:
    // 0x8019A56C: lbu         $t5, 0x207C($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X207C);
    // 0x8019A570: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019A574: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x8019A578: bne         $t5, $at, L_8019A5AC
    if (ctx->r13 != ctx->r1) {
        // 0x8019A57C: nop
    
            goto L_8019A5AC;
    }
    // 0x8019A57C: nop

    // 0x8019A580: lh          $t6, 0x6CE($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X6CE);
    // 0x8019A584: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
    // 0x8019A588: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A58C: beq         $s0, $t6, L_8019A5A4
    if (ctx->r16 == ctx->r14) {
        // 0x8019A590: addiu       $a0, $a0, 0x11D8
        ctx->r4 = ADD32(ctx->r4, 0X11D8);
            goto L_8019A5A4;
    }
    // 0x8019A590: addiu       $a0, $a0, 0x11D8
    ctx->r4 = ADD32(ctx->r4, 0X11D8);
    // 0x8019A594: jal         0x800BA808
    // 0x8019A598: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x8019A598: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x8019A59C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019A5A0: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
L_8019A5A4:
    // 0x8019A5A4: b           L_8019A5B8
    // 0x8019A5A8: sh          $s0, 0x6CE($t0)
    MEM_H(0X6CE, ctx->r8) = ctx->r16;
        goto L_8019A5B8;
    // 0x8019A5A8: sh          $s0, 0x6CE($t0)
    MEM_H(0X6CE, ctx->r8) = ctx->r16;
L_8019A5AC:
    // 0x8019A5AC: b           L_8019A5B8
    // 0x8019A5B0: sh          $t7, 0x6CE($t0)
    MEM_H(0X6CE, ctx->r8) = ctx->r15;
        goto L_8019A5B8;
    // 0x8019A5B0: sh          $t7, 0x6CE($t0)
    MEM_H(0X6CE, ctx->r8) = ctx->r15;
    // 0x8019A5B4: sh          $t8, 0x6CE($t0)
    MEM_H(0X6CE, ctx->r8) = ctx->r24;
L_8019A5B8:
    // 0x8019A5B8: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019A5BC: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
    // 0x8019A5C0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8019A5C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A5C8: bne         $v1, $at, L_8019A5E0
    if (ctx->r3 != ctx->r1) {
        // 0x8019A5CC: addiu       $a0, $a0, 0x1134
        ctx->r4 = ADD32(ctx->r4, 0X1134);
            goto L_8019A5E0;
    }
    // 0x8019A5CC: addiu       $a0, $a0, 0x1134
    ctx->r4 = ADD32(ctx->r4, 0X1134);
    // 0x8019A5D0: jal         0x800BA808
    // 0x8019A5D4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x8019A5D4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_4:
    // 0x8019A5D8: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019A5DC: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
L_8019A5E0:
    // 0x8019A5E0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8019A5E4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8019A5E8: lhu         $t3, 0xC0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0XC0);
    // 0x8019A5EC: bnel        $t3, $zero, L_8019A848
    if (ctx->r11 != 0) {
        // 0x8019A5F0: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_8019A848;
    }
    goto skip_3;
    // 0x8019A5F0: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    skip_3:
    // 0x8019A5F4: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8019A5F8: slti        $at, $v1, 0xC8
    ctx->r1 = SIGNED(ctx->r3) < 0XC8 ? 1 : 0;
    // 0x8019A5FC: lw          $t5, 0x1C8($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X1C8);
    // 0x8019A600: beql        $t5, $zero, L_8019A848
    if (ctx->r13 == 0) {
        // 0x8019A604: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_8019A848;
    }
    goto skip_4;
    // 0x8019A604: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    skip_4:
    // 0x8019A608: bne         $at, $zero, L_8019A624
    if (ctx->r1 != 0) {
        // 0x8019A60C: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_8019A624;
    }
    // 0x8019A60C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8019A610: slti        $at, $v1, 0xFA1
    ctx->r1 = SIGNED(ctx->r3) < 0XFA1 ? 1 : 0;
    // 0x8019A614: bne         $at, $zero, L_8019A844
    if (ctx->r1 != 0) {
        // 0x8019A618: slti        $at, $v1, 0x1068
        ctx->r1 = SIGNED(ctx->r3) < 0X1068 ? 1 : 0;
            goto L_8019A844;
    }
    // 0x8019A618: slti        $at, $v1, 0x1068
    ctx->r1 = SIGNED(ctx->r3) < 0X1068 ? 1 : 0;
    // 0x8019A61C: beql        $at, $zero, L_8019A848
    if (ctx->r1 == 0) {
        // 0x8019A620: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_8019A848;
    }
    goto skip_5;
    // 0x8019A620: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    skip_5:
L_8019A624:
    // 0x8019A624: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8019A628: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A62C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019A630: sh          $t6, 0xC0($t7)
    MEM_H(0XC0, ctx->r15) = ctx->r14;
    // 0x8019A634: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019A638: lwc1        $f8, 0x128($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X128);
    // 0x8019A63C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8019A640: addiu       $s0, $s0, 0x6644
    ctx->r16 = ADD32(ctx->r16, 0X6644);
    // 0x8019A644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019A648: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x8019A64C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x8019A650: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x8019A654: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
L_8019A658:
    // 0x8019A658: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8019A65C: bne         $t8, $zero, L_8019A830
    if (ctx->r24 != 0) {
        // 0x8019A660: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019A830;
    }
    // 0x8019A660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019A664: jal         0x800613C4
    // 0x8019A668: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    Actor_Initialize(rdram, ctx);
        goto after_5;
    // 0x8019A668: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    after_5:
    // 0x8019A66C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8019A670: addiu       $t3, $zero, 0xC5
    ctx->r11 = ADD32(0, 0XC5);
    // 0x8019A674: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x8019A678: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x8019A67C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8019A680: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8019A684: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019A688: lh          $t5, 0x4E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X4E);
    // 0x8019A68C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A690: lwc1        $f6, 0x12C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12C);
    // 0x8019A694: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8019A698: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019A69C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019A6A0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019A6A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019A6A8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8019A6AC: nop

    // 0x8019A6B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019A6B4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019A6B8: jal         0x80005E90
    // 0x8019A6BC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8019A6BC: nop

    after_6:
    // 0x8019A6C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019A6C4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019A6C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8019A6CC: jal         0x80006A20
    // 0x8019A6D0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_7;
    // 0x8019A6D0: addiu       $a2, $sp, 0x34
    ctx->r6 = ADD32(ctx->r29, 0X34);
    after_7:
    // 0x8019A6D4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019A6D8: jal         0x80004EB0
    // 0x8019A6DC: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8019A6DC: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x8019A6E0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8019A6E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A6E8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019A6EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019A6F0: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8019A6F4: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8019A6F8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8019A6FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8019A700: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8019A704: addiu       $v1, $v0, 0xD
    ctx->r3 = ADD32(ctx->r2, 0XD);
    // 0x8019A708: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8019A70C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019A710: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019A714: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8019A718: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8019A71C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019A720: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8019A724: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8019A728: lh          $t7, 0x4E($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4E);
    // 0x8019A72C: sh          $a0, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r4;
    // 0x8019A730: sh          $v1, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r3;
    // 0x8019A734: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8019A738: sh          $t8, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r24;
    // 0x8019A73C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019A740: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8019A744: swc1        $f4, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f4.u32l;
    // 0x8019A748: lw          $t9, -0x6D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6D8);
    // 0x8019A74C: bltzl       $t9, L_8019A7C0
    if (SIGNED(ctx->r25) < 0) {
        // 0x8019A750: addiu       $t9, $zero, 0x18
        ctx->r25 = ADD32(0, 0X18);
            goto L_8019A7C0;
    }
    goto skip_6;
    // 0x8019A750: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    skip_6:
    // 0x8019A754: beq         $v1, $at, L_8019A764
    if (ctx->r3 == ctx->r1) {
        // 0x8019A758: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_8019A764;
    }
    // 0x8019A758: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8019A75C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8019A760: bne         $v1, $at, L_8019A770
    if (ctx->r3 != ctx->r1) {
        // 0x8019A764: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_8019A770;
    }
L_8019A764:
    // 0x8019A764: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8019A768: sh          $t3, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r11;
    // 0x8019A76C: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
L_8019A770:
    // 0x8019A770: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8019A774: bne         $v1, $at, L_8019A784
    if (ctx->r3 != ctx->r1) {
        // 0x8019A778: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_8019A784;
    }
    // 0x8019A778: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8019A77C: sh          $zero, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = 0;
    // 0x8019A780: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
L_8019A784:
    // 0x8019A784: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8019A788: beq         $v1, $at, L_8019A79C
    if (ctx->r3 == ctx->r1) {
        // 0x8019A78C: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8019A79C;
    }
    // 0x8019A78C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8019A790: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8019A794: bnel        $v1, $at, L_8019A7A8
    if (ctx->r3 != ctx->r1) {
        // 0x8019A798: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_8019A7A8;
    }
    goto skip_7;
    // 0x8019A798: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    skip_7:
L_8019A79C:
    // 0x8019A79C: sh          $a0, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r4;
    // 0x8019A7A0: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
    // 0x8019A7A4: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
L_8019A7A8:
    // 0x8019A7A8: bne         $v1, $at, L_8019A7BC
    if (ctx->r3 != ctx->r1) {
        // 0x8019A7AC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8019A7BC;
    }
    // 0x8019A7AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019A7B0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8019A7B4: sh          $t7, 0xE6($s0)
    MEM_H(0XE6, ctx->r16) = ctx->r15;
    // 0x8019A7B8: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
L_8019A7BC:
    // 0x8019A7BC: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
L_8019A7C0:
    // 0x8019A7C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019A7C4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8019A7C8: addiu       $t5, $zero, 0x1E
    ctx->r13 = ADD32(0, 0X1E);
    // 0x8019A7CC: sh          $t9, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r25;
    // 0x8019A7D0: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x8019A7D4: sb          $t4, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r12;
    // 0x8019A7D8: sh          $t5, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r13;
    // 0x8019A7DC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019A7E0: jal         0x800612B8
    // 0x8019A7E4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_9;
    // 0x8019A7E4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_9:
    // 0x8019A7E8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A7EC: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8019A7F0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A7F4: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8019A7F8: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8019A7FC: ori         $a0, $a0, 0x11
    ctx->r4 = ctx->r4 | 0X11;
    // 0x8019A800: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8019A804: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019A808: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019A80C: jal         0x80019218
    // 0x8019A810: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x8019A810: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x8019A814: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x8019A818: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019A81C: lh          $t8, 0x4E($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X4E);
    // 0x8019A820: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019A824: sh          $t9, 0x4E($t7)
    MEM_H(0X4E, ctx->r15) = ctx->r25;
    // 0x8019A828: b           L_8019A844
    // 0x8019A82C: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
        goto L_8019A844;
    // 0x8019A82C: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
L_8019A830:
    // 0x8019A830: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8019A834: bne         $v0, $v1, L_8019A658
    if (ctx->r2 != ctx->r3) {
        // 0x8019A838: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8019A658;
    }
    // 0x8019A838: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8019A83C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019A840: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
L_8019A844:
    // 0x8019A844: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
L_8019A848:
    // 0x8019A848: beq         $v1, $at, L_8019A918
    if (ctx->r3 == ctx->r1) {
        // 0x8019A84C: addiu       $t5, $zero, 0x1EA
        ctx->r13 = ADD32(0, 0X1EA);
            goto L_8019A918;
    }
    // 0x8019A84C: addiu       $t5, $zero, 0x1EA
    ctx->r13 = ADD32(0, 0X1EA);
    // 0x8019A850: addiu       $at, $zero, 0xF0A
    ctx->r1 = ADD32(0, 0XF0A);
    // 0x8019A854: beq         $v1, $at, L_8019A8D8
    if (ctx->r3 == ctx->r1) {
        // 0x8019A858: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8019A8D8;
    }
    // 0x8019A858: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A85C: addiu       $at, $zero, 0xFA0
    ctx->r1 = ADD32(0, 0XFA0);
    // 0x8019A860: beq         $v1, $at, L_8019A8EC
    if (ctx->r3 == ctx->r1) {
        // 0x8019A864: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8019A8EC;
    }
    // 0x8019A864: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A868: addiu       $at, $zero, 0x16DA
    ctx->r1 = ADD32(0, 0X16DA);
    // 0x8019A86C: beq         $v1, $at, L_8019A888
    if (ctx->r3 == ctx->r1) {
        // 0x8019A870: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_8019A888;
    }
    // 0x8019A870: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A874: addiu       $at, $zero, 0x1770
    ctx->r1 = ADD32(0, 0X1770);
    // 0x8019A878: beq         $v1, $at, L_8019A89C
    if (ctx->r3 == ctx->r1) {
        // 0x8019A87C: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8019A89C;
    }
    // 0x8019A87C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A880: b           L_8019AA78
    // 0x8019A884: nop

        goto L_8019AA78;
    // 0x8019A884: nop

L_8019A888:
    // 0x8019A888: addiu       $a0, $a0, 0x13F0
    ctx->r4 = ADD32(ctx->r4, 0X13F0);
    // 0x8019A88C: jal         0x800BA808
    // 0x8019A890: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x8019A890: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_11:
    // 0x8019A894: b           L_8019AA78
    // 0x8019A898: nop

        goto L_8019AA78;
    // 0x8019A898: nop

L_8019A89C:
    // 0x8019A89C: addiu       $a0, $a0, 0x6350
    ctx->r4 = ADD32(ctx->r4, 0X6350);
    // 0x8019A8A0: jal         0x80199FCC
    // 0x8019A8A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    SectorZ_SpawnMissile(rdram, ctx);
        goto after_12;
    // 0x8019A8A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x8019A8A8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A8AC: addiu       $a0, $a0, 0x605C
    ctx->r4 = ADD32(ctx->r4, 0X605C);
    // 0x8019A8B0: jal         0x80199FCC
    // 0x8019A8B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    SectorZ_SpawnMissile(rdram, ctx);
        goto after_13;
    // 0x8019A8B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8019A8B8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A8BC: addiu       $a0, $a0, 0x5D68
    ctx->r4 = ADD32(ctx->r4, 0X5D68);
    // 0x8019A8C0: jal         0x80199FCC
    // 0x8019A8C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    SectorZ_SpawnMissile(rdram, ctx);
        goto after_14;
    // 0x8019A8C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x8019A8C8: addiu       $t3, $zero, 0x244
    ctx->r11 = ADD32(0, 0X244);
    // 0x8019A8CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019A8D0: b           L_8019AA78
    // 0x8019A8D4: sw          $t3, 0x1710($at)
    MEM_W(0X1710, ctx->r1) = ctx->r11;
        goto L_8019AA78;
    // 0x8019A8D4: sw          $t3, 0x1710($at)
    MEM_W(0X1710, ctx->r1) = ctx->r11;
L_8019A8D8:
    // 0x8019A8D8: addiu       $a0, $a0, 0x13B0
    ctx->r4 = ADD32(ctx->r4, 0X13B0);
    // 0x8019A8DC: jal         0x800BA808
    // 0x8019A8E0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_15;
    // 0x8019A8E0: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_15:
    // 0x8019A8E4: b           L_8019AA78
    // 0x8019A8E8: nop

        goto L_8019AA78;
    // 0x8019A8E8: nop

L_8019A8EC:
    // 0x8019A8EC: addiu       $a0, $a0, 0x605C
    ctx->r4 = ADD32(ctx->r4, 0X605C);
    // 0x8019A8F0: jal         0x80199FCC
    // 0x8019A8F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    SectorZ_SpawnMissile(rdram, ctx);
        goto after_16;
    // 0x8019A8F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x8019A8F8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A8FC: addiu       $a0, $a0, 0x5D68
    ctx->r4 = ADD32(ctx->r4, 0X5D68);
    // 0x8019A900: jal         0x80199FCC
    // 0x8019A904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    SectorZ_SpawnMissile(rdram, ctx);
        goto after_17;
    // 0x8019A904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_17:
    // 0x8019A908: addiu       $t4, $zero, 0x244
    ctx->r12 = ADD32(0, 0X244);
    // 0x8019A90C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019A910: b           L_8019AA78
    // 0x8019A914: sw          $t4, 0x1710($at)
    MEM_W(0X1710, ctx->r1) = ctx->r12;
        goto L_8019AA78;
    // 0x8019A914: sw          $t4, 0x1710($at)
    MEM_W(0X1710, ctx->r1) = ctx->r12;
L_8019A918:
    // 0x8019A918: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019A91C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A920: sw          $t5, 0x1710($at)
    MEM_W(0X1710, ctx->r1) = ctx->r13;
    // 0x8019A924: addiu       $a0, $a0, 0x5D68
    ctx->r4 = ADD32(ctx->r4, 0X5D68);
    // 0x8019A928: jal         0x80199FCC
    // 0x8019A92C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    SectorZ_SpawnMissile(rdram, ctx);
        goto after_18;
    // 0x8019A92C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x8019A930: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019A934: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019A938: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019A93C: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x8019A940: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A944: swc1        $f6, 0x1EA0($t0)
    MEM_W(0X1EA0, ctx->r8) = ctx->f6.u32l;
    // 0x8019A948: lwc1        $f8, 0x130($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X130);
    // 0x8019A94C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A950: addiu       $a0, $a0, 0x6644
    ctx->r4 = ADD32(ctx->r4, 0X6644);
    // 0x8019A954: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019A958: jal         0x8019A0F8
    // 0x8019A95C: swc1        $f8, 0x1D94($t0)
    MEM_W(0X1D94, ctx->r8) = ctx->f8.u32l;
    SectorZ_SpawnMissileEscort(rdram, ctx);
        goto after_19;
    // 0x8019A95C: swc1        $f8, 0x1D94($t0)
    MEM_W(0X1D94, ctx->r8) = ctx->f8.u32l;
    after_19:
    // 0x8019A960: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A964: addiu       $a0, $a0, 0x6938
    ctx->r4 = ADD32(ctx->r4, 0X6938);
    // 0x8019A968: jal         0x8019A0F8
    // 0x8019A96C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    SectorZ_SpawnMissileEscort(rdram, ctx);
        goto after_20;
    // 0x8019A96C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x8019A970: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A974: addiu       $a0, $a0, 0x6C2C
    ctx->r4 = ADD32(ctx->r4, 0X6C2C);
    // 0x8019A978: jal         0x8019A0F8
    // 0x8019A97C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    SectorZ_SpawnMissileEscort(rdram, ctx);
        goto after_21;
    // 0x8019A97C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_21:
    // 0x8019A980: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019A984: addiu       $a0, $a0, 0x6F20
    ctx->r4 = ADD32(ctx->r4, 0X6F20);
    // 0x8019A988: jal         0x8019A0F8
    // 0x8019A98C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    SectorZ_SpawnMissileEscort(rdram, ctx);
        goto after_22;
    // 0x8019A98C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_22:
    // 0x8019A990: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8019A994: addiu       $t2, $t2, -0x7D80
    ctx->r10 = ADD32(ctx->r10, -0X7D80);
    // 0x8019A998: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8019A99C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019A9A0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8019A9A4: sw          $zero, 0x1C8($t6)
    MEM_W(0X1C8, ctx->r14) = 0;
    // 0x8019A9A8: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8019A9AC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8019A9B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A9B4: sh          $t8, 0xB8($t9)
    MEM_H(0XB8, ctx->r25) = ctx->r24;
    // 0x8019A9B8: swc1        $f10, 0x13C($t9)
    MEM_W(0X13C, ctx->r25) = ctx->f10.u32l;
    // 0x8019A9BC: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8019A9C0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019A9C4: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x8019A9C8: swc1        $f16, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f16.u32l;
    // 0x8019A9CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A9D0: lwc1        $f4, 0x134($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X134);
    // 0x8019A9D4: lwc1        $f18, 0x1D8C($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X1D8C);
    // 0x8019A9D8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8019A9DC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019A9E0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8019A9E4: addiu       $t7, $zero, 0x2710
    ctx->r15 = ADD32(0, 0X2710);
    // 0x8019A9E8: addiu       $v0, $v0, -0x7CA8
    ctx->r2 = ADD32(ctx->r2, -0X7CA8);
    // 0x8019A9EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019A9F0: swc1        $f6, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f6.u32l;
    // 0x8019A9F4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8019A9F8: lwc1        $f8, 0x1D90($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X1D90);
    // 0x8019A9FC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019AA00: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8019AA04: swc1        $f8, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f8.u32l;
    // 0x8019AA08: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8019AA0C: lwc1        $f10, 0x1D94($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X1D94);
    // 0x8019AA10: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8019AA14: addiu       $t1, $t1, -0x7CB0
    ctx->r9 = ADD32(ctx->r9, -0X7CB0);
    // 0x8019AA18: swc1        $f10, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f10.u32l;
    // 0x8019AA1C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8019AA20: lwc1        $f16, 0x1D8C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X1D8C);
    // 0x8019AA24: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x8019AA28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019AA2C: swc1        $f16, 0x4C($t6)
    MEM_W(0X4C, ctx->r14) = ctx->f16.u32l;
    // 0x8019AA30: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8019AA34: lwc1        $f18, 0x1D90($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X1D90);
    // 0x8019AA38: ori         $a1, $zero, 0x801F
    ctx->r5 = 0 | 0X801F;
    // 0x8019AA3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019AA40: swc1        $f18, 0x50($t8)
    MEM_W(0X50, ctx->r24) = ctx->f18.u32l;
    // 0x8019AA44: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8019AA48: lwc1        $f4, 0x1D94($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X1D94);
    // 0x8019AA4C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8019AA50: swc1        $f4, 0x54($t9)
    MEM_W(0X54, ctx->r25) = ctx->f4.u32l;
    // 0x8019AA54: lw          $t3, 0x50($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X50);
    // 0x8019AA58: sh          $t7, 0xBC($t3)
    MEM_H(0XBC, ctx->r11) = ctx->r15;
    // 0x8019AA5C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8019AA60: sw          $t4, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r12;
    // 0x8019AA64: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8019AA68: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8019AA6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019AA70: jal         0x8001D444
    // 0x8019AA74: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    Audio_PlaySequence(rdram, ctx);
        goto after_23;
    // 0x8019AA74: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    after_23:
L_8019AA78:
    // 0x8019AA78: jal         0x8002FC00
    // 0x8019AA7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    ActorAllRange_UpdateEnemyEvents(rdram, ctx);
        goto after_24;
    // 0x8019AA7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_24:
    // 0x8019AA80: jal         0x8019A2F4
    // 0x8019AA84: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    SectorZ_KattCutscene(rdram, ctx);
        goto after_25;
    // 0x8019AA84: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_25:
    // 0x8019AA88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019AA8C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019AA90: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8019AA94: jr          $ra
    // 0x8019AA98: nop

    return;
    // 0x8019AA98: nop

;}
RECOMP_FUNC void Bolse_LevelComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F94C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8018F950: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018F954: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x8018F958: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018F95C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8018F960: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018F964: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x8018F968: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018F96C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018F970: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018F974: addiu       $a0, $s1, 0x110
    ctx->r4 = ADD32(ctx->r17, 0X110);
    // 0x8018F978: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8018F97C: jal         0x8009BC2C
    // 0x8018F980: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8018F980: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8018F984: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018F988: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018F98C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018F990: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8018F994: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8018F998: lw          $t6, 0x1D0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X1D0);
    // 0x8018F99C: sltiu       $at, $t6, 0xD
    ctx->r1 = ctx->r14 < 0XD ? 1 : 0;
    // 0x8018F9A0: beq         $at, $zero, L_80190758
    if (ctx->r1 == 0) {
        // 0x8018F9A4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80190758;
    }
    // 0x8018F9A4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018F9A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F9AC: addu        $at, $at, $t6
    gpr jr_addend_8018F9B4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018F9B0: lw          $t6, -0x498($at)
    ctx->r14 = ADD32(ctx->r1, -0X498);
    // 0x8018F9B4: jr          $t6
    // 0x8018F9B8: nop

    switch (jr_addend_8018F9B4 >> 2) {
        case 0: goto L_8018F9BC; break;
        case 1: goto L_8018FAB8; break;
        case 2: goto L_80190758; break;
        case 3: goto L_80190758; break;
        case 4: goto L_80190758; break;
        case 5: goto L_8018FD94; break;
        case 6: goto L_80190758; break;
        case 7: goto L_80190758; break;
        case 8: goto L_80190758; break;
        case 9: goto L_80190758; break;
        case 10: goto L_8018FDB0; break;
        case 11: goto L_80190338; break;
        case 12: goto L_801905D0; break;
        default: switch_error(__func__, 0x8018F9B4, 0x8019FB68);
    }
    // 0x8018F9B8: nop

L_8018F9BC:
    // 0x8018F9BC: addiu       $s0, $s1, 0x460
    ctx->r16 = ADD32(ctx->r17, 0X460);
    // 0x8018F9C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018F9C4: jal         0x8001A38C
    // 0x8018F9C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Audio_StopSfxByBankAndSource(rdram, ctx);
        goto after_1;
    // 0x8018F9C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8018F9CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018F9D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018F9D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018F9D8: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018F9DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F9E0: swc1        $f0, 0x3D0($at)
    MEM_W(0X3D0, ctx->r1) = ctx->f0.u32l;
    // 0x8018F9E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F9E8: swc1        $f0, 0x3D4($at)
    MEM_W(0X3D4, ctx->r1) = ctx->f0.u32l;
    // 0x8018F9EC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8018F9F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018F9F4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018F9F8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018F9FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018FA00: addiu       $a0, $s1, 0xE8
    ctx->r4 = ADD32(ctx->r17, 0XE8);
    // 0x8018FA04: lui         $a1, 0xC220
    ctx->r5 = S32(0XC220 << 16);
    // 0x8018FA08: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x8018FA0C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8018FA10: jal         0x8009BC2C
    // 0x8018FA14: swc1        $f8, 0x3D8($at)
    MEM_W(0X3D8, ctx->r1) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8018FA14: swc1        $f8, 0x3D8($at)
    MEM_W(0X3D8, ctx->r1) = ctx->f8.u32l;
    after_2:
    // 0x8018FA18: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018FA1C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018FA20: addiu       $a0, $s1, 0xEC
    ctx->r4 = ADD32(ctx->r17, 0XEC);
    // 0x8018FA24: lui         $a1, 0xC270
    ctx->r5 = S32(0XC270 << 16);
    // 0x8018FA28: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018FA2C: jal         0x8009BC2C
    // 0x8018FA30: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8018FA30: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x8018FA34: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018FA38: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018FA3C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018FA40: addiu       $a0, $s1, 0xE4
    ctx->r4 = ADD32(ctx->r17, 0XE4);
    // 0x8018FA44: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x8018FA48: jal         0x8009BC2C
    // 0x8018FA4C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8018FA4C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
    // 0x8018FA50: lw          $t7, 0x1F8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1F8);
    // 0x8018FA54: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018FA58: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018FA5C: bne         $t7, $zero, L_80190758
    if (ctx->r15 != 0) {
        // 0x8018FA60: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80190758;
    }
    // 0x8018FA60: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018FA64: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8018FA68: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018FA6C: sw          $t8, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r24;
    // 0x8018FA70: sw          $t9, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = ctx->r25;
    // 0x8018FA74: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8018FA78: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8018FA7C: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8018FA80: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8018FA84: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018FA88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018FA8C: jal         0x80019218
    // 0x8018FA90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x8018FA90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8018FA94: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018FA98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018FA9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FAA0: swc1        $f0, 0x194($s1)
    MEM_W(0X194, ctx->r17) = ctx->f0.u32l;
    // 0x8018FAA4: swc1        $f0, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f0.u32l;
    // 0x8018FAA8: lwc1        $f10, -0x464($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X464);
    // 0x8018FAAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018FAB0: b           L_80190758
    // 0x8018FAB4: swc1        $f10, 0x1A44($at)
    MEM_W(0X1A44, ctx->r1) = ctx->f10.u32l;
        goto L_80190758;
    // 0x8018FAB4: swc1        $f10, 0x1A44($at)
    MEM_W(0X1A44, ctx->r1) = ctx->f10.u32l;
L_8018FAB8:
    // 0x8018FAB8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018FABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018FAC0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018FAC4: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x8018FAC8: swc1        $f4, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f4.u32l;
    // 0x8018FACC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8018FAD0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8018FAD4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018FAD8: addiu       $a0, $s1, 0xE4
    ctx->r4 = ADD32(ctx->r17, 0XE4);
    // 0x8018FADC: jal         0x8009BC2C
    // 0x8018FAE0: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8018FAE0: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    after_6:
    // 0x8018FAE4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8018FAE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018FAEC: addiu       $a0, $s1, 0xEC
    ctx->r4 = ADD32(ctx->r17, 0XEC);
    // 0x8018FAF0: lui         $a1, 0x4220
    ctx->r5 = S32(0X4220 << 16);
    // 0x8018FAF4: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8018FAF8: jal         0x8009BC2C
    // 0x8018FAFC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8018FAFC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x8018FB00: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018FB04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018FB08: addiu       $a0, $s1, 0xE8
    ctx->r4 = ADD32(ctx->r17, 0XE8);
    // 0x8018FB0C: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x8018FB10: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8018FB14: jal         0x8009BC2C
    // 0x8018FB18: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8018FB18: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x8018FB1C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8018FB20: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018FB24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018FB28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018FB2C: lwc1        $f6, 0xD0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XD0);
    // 0x8018FB30: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018FB34: addiu       $t4, $zero, 0x3E8
    ctx->r12 = ADD32(0, 0X3E8);
    // 0x8018FB38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018FB3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018FB40: swc1        $f10, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f10.u32l;
    // 0x8018FB44: lwc1        $f4, 0xD0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XD0);
    // 0x8018FB48: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8018FB4C: nop

    // 0x8018FB50: bc1fl       L_8018FB60
    if (!c1cs) {
        // 0x8018FB54: lw          $t2, 0x1F8($s1)
        ctx->r10 = MEM_W(ctx->r17, 0X1F8);
            goto L_8018FB60;
    }
    goto skip_0;
    // 0x8018FB54: lw          $t2, 0x1F8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1F8);
    skip_0:
    // 0x8018FB58: swc1        $f2, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f2.u32l;
    // 0x8018FB5C: lw          $t2, 0x1F8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X1F8);
L_8018FB60:
    // 0x8018FB60: bne         $t2, $zero, L_80190758
    if (ctx->r10 != 0) {
        // 0x8018FB64: nop
    
            goto L_80190758;
    }
    // 0x8018FB64: nop

    // 0x8018FB68: sw          $t3, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r11;
    // 0x8018FB6C: jal         0x8001CA24
    // 0x8018FB70: sw          $t4, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = ctx->r12;
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_9;
    // 0x8018FB70: sw          $t4, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = ctx->r12;
    after_9:
    // 0x8018FB74: jal         0x8001A500
    // 0x8018FB78: addiu       $a0, $s1, 0x460
    ctx->r4 = ADD32(ctx->r17, 0X460);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_10;
    // 0x8018FB78: addiu       $a0, $s1, 0x460
    ctx->r4 = ADD32(ctx->r17, 0X460);
    after_10:
    // 0x8018FB7C: jal         0x800A6148
    // 0x8018FB80: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_11;
    // 0x8018FB80: nop

    after_11:
    // 0x8018FB84: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018FB88: addiu       $v0, $v0, -0x7D58
    ctx->r2 = ADD32(ctx->r2, -0X7D58);
    // 0x8018FB8C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018FB90: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
L_8018FB94:
    // 0x8018FB94: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8018FB98: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8018FB9C: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8018FBA0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8018FBA4: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8018FBA8: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    // 0x8018FBAC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8018FBB0: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x8018FBB4: sb          $zero, 0xB0($t1)
    MEM_B(0XB0, ctx->r9) = 0;
    // 0x8018FBB8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8018FBBC: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8018FBC0: addiu       $v1, $v1, 0x160
    ctx->r3 = ADD32(ctx->r3, 0X160);
    // 0x8018FBC4: bne         $v1, $a0, L_8018FB94
    if (ctx->r3 != ctx->r4) {
        // 0x8018FBC8: sb          $zero, 0x108($t3)
        MEM_B(0X108, ctx->r11) = 0;
            goto L_8018FB94;
    }
    // 0x8018FBC8: sb          $zero, 0x108($t3)
    MEM_B(0X108, ctx->r11) = 0;
    // 0x8018FBCC: jal         0x8018EC1C
    // 0x8018FBD0: nop

    Bolse_CsBoSatellite_Setup(rdram, ctx);
        goto after_12;
    // 0x8018FBD0: nop

    after_12:
    // 0x8018FBD4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FBD8: lwc1        $f6, -0x2C74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x8018FBDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FBE0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8018FBE4: swc1        $f6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f6.u32l;
    // 0x8018FBE8: lwc1        $f8, -0x2C70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x8018FBEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FBF0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8018FBF4: swc1        $f8, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f8.u32l;
    // 0x8018FBF8: lwc1        $f10, -0x2C6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2C6C);
    // 0x8018FBFC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8018FC00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018FC04: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8018FC08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018FC0C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018FC10: swc1        $f20, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f20.u32l;
    // 0x8018FC14: swc1        $f20, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f20.u32l;
    // 0x8018FC18: swc1        $f20, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f20.u32l;
    // 0x8018FC1C: swc1        $f6, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f6.u32l;
    // 0x8018FC20: swc1        $f20, 0x114($s1)
    MEM_W(0X114, ctx->r17) = ctx->f20.u32l;
    // 0x8018FC24: swc1        $f8, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f8.u32l;
    // 0x8018FC28: lw          $t4, 0x78B4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78B4);
    // 0x8018FC2C: addiu       $a0, $s0, 0x3FE0
    ctx->r4 = ADD32(ctx->r16, 0X3FE0);
    // 0x8018FC30: blez        $t4, L_8018FC40
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8018FC34: nop
    
            goto L_8018FC40;
    }
    // 0x8018FC34: nop

    // 0x8018FC38: jal         0x8018F83C
    // 0x8018FC3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Bolse_8018F83C(rdram, ctx);
        goto after_13;
    // 0x8018FC3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_8018FC40:
    // 0x8018FC40: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018FC44: lw          $t5, 0x78B8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78B8);
    // 0x8018FC48: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018FC4C: addiu       $a0, $a0, 0x42D4
    ctx->r4 = ADD32(ctx->r4, 0X42D4);
    // 0x8018FC50: blez        $t5, L_8018FC60
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8018FC54: nop
    
            goto L_8018FC60;
    }
    // 0x8018FC54: nop

    // 0x8018FC58: jal         0x8018F83C
    // 0x8018FC5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Bolse_8018F83C(rdram, ctx);
        goto after_14;
    // 0x8018FC5C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
L_8018FC60:
    // 0x8018FC60: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018FC64: lw          $t6, 0x78BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78BC);
    // 0x8018FC68: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018FC6C: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    // 0x8018FC70: blezl       $t6, L_8018FC84
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8018FC74: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_8018FC84;
    }
    goto skip_1;
    // 0x8018FC74: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    skip_1:
    // 0x8018FC78: jal         0x8018F83C
    // 0x8018FC7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Bolse_8018F83C(rdram, ctx);
        goto after_15;
    // 0x8018FC7C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_15:
    // 0x8018FC80: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
L_8018FC84:
    // 0x8018FC84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018FC88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018FC8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018FC90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FC94: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x8018FC98: swc1        $f10, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f10.u32l;
    // 0x8018FC9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018FCA0: sw          $t7, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r15;
    // 0x8018FCA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018FCA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FCAC: sb          $zero, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = 0;
    // 0x8018FCB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FCB4: swc1        $f4, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f4.u32l;
    // 0x8018FCB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FCBC: swc1        $f0, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f0.u32l;
    // 0x8018FCC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FCC4: lwc1        $f6, -0x460($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X460);
    // 0x8018FCC8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018FCCC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8018FCD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FCD4: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x8018FCD8: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8018FCDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FCE0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018FCE4: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x8018FCE8: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8018FCEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FCF0: addiu       $a1, $a1, -0x7CA8
    ctx->r5 = ADD32(ctx->r5, -0X7CA8);
    // 0x8018FCF4: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x8018FCF8: lwc1        $f4, 0x7C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x8018FCFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FD00: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8018FD04: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x8018FD08: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8018FD0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018FD10: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x8018FD14: sw          $t0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r8;
    // 0x8018FD18: jal         0x800182F4
    // 0x8018FD1C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_16;
    // 0x8018FD1C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_16:
    // 0x8018FD20: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x8018FD24: jal         0x800182F4
    // 0x8018FD28: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_17;
    // 0x8018FD28: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_17:
    // 0x8018FD2C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FD30: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8018FD34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FD38: lwc1        $f6, -0x45C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X45C);
    // 0x8018FD3C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FD40: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018FD44: swc1        $f6, 0x7940($at)
    MEM_W(0X7940, ctx->r1) = ctx->f6.u32l;
    // 0x8018FD48: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018FD4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018FD50: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8018FD54: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018FD58: sw          $t9, 0x240($s1)
    MEM_W(0X240, ctx->r17) = ctx->r25;
    // 0x8018FD5C: sb          $t1, 0x4C8($s1)
    MEM_B(0X4C8, ctx->r17) = ctx->r9;
    // 0x8018FD60: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8018FD64: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8018FD68: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018FD6C: addiu       $a1, $a1, -0x2B78
    ctx->r5 = ADD32(ctx->r5, -0X2B78);
    // 0x8018FD70: ori         $a0, $a0, 0x9063
    ctx->r4 = ctx->r4 | 0X9063;
    // 0x8018FD74: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8018FD78: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018FD7C: jal         0x80019218
    // 0x8018FD80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x8018FD80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x8018FD84: jal         0x8001C8B8
    // 0x8018FD88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_StartPlayerNoise(rdram, ctx);
        goto after_19;
    // 0x8018FD88: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_19:
    // 0x8018FD8C: b           L_80190758
    // 0x8018FD90: nop

        goto L_80190758;
    // 0x8018FD90: nop

L_8018FD94:
    // 0x8018FD94: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8018FD98: addiu       $a1, $a1, -0x7CA8
    ctx->r5 = ADD32(ctx->r5, -0X7CA8);
    // 0x8018FD9C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8018FDA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018FDA4: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x8018FDA8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8018FDAC: sw          $t4, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r12;
L_8018FDB0:
    // 0x8018FDB0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8018FDB4: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8018FDB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FDBC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8018FDC0: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8018FDC4: lw          $t5, 0x7A80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7A80);
    // 0x8018FDC8: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x8018FDCC: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8018FDD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FDD4: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x8018FDD8: lwc1        $f4, 0x7C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x8018FDDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FDE0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018FDE4: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x8018FDE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FDEC: lwc1        $f6, -0x2C70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x8018FDF0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018FDF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018FDF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FDFC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018FE00: swc1        $f10, -0x2C70($at)
    MEM_W(-0X2C70, ctx->r1) = ctx->f10.u32l;
    // 0x8018FE04: slti        $at, $t5, 0x5C
    ctx->r1 = SIGNED(ctx->r13) < 0X5C ? 1 : 0;
    // 0x8018FE08: beq         $at, $zero, L_8018FF68
    if (ctx->r1 == 0) {
        // 0x8018FE0C: nop
    
            goto L_8018FF68;
    }
    // 0x8018FE0C: nop

    // 0x8018FE10: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8018FE14: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x8018FE18: bne         $t6, $zero, L_8018FED0
    if (ctx->r14 != 0) {
        // 0x8018FE1C: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8018FED0;
    }
    // 0x8018FE1C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8018FE20: jal         0x80004EB0
    // 0x8018FE24: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x8018FE24: nop

    after_20:
    // 0x8018FE28: jal         0x80004EB0
    // 0x8018FE2C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x8018FE2C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x8018FE30: jal         0x80004EB0
    // 0x8018FE34: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x8018FE34: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x8018FE38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018FE3C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018FE40: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8018FE44: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8018FE48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018FE4C: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8018FE50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FE54: lwc1        $f10, -0x2C74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x8018FE58: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8018FE5C: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8018FE60: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FE64: lwc1        $f4, -0x2C70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x8018FE68: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018FE6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FE70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FE74: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018FE78: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018FE7C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8018FE80: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8018FE84: sub.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8018FE88: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8018FE8C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018FE90: mul.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8018FE94: lwc1        $f4, -0x2C6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C6C);
    // 0x8018FE98: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FE9C: lwc1        $f8, -0x458($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X458);
    // 0x8018FEA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FEA4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018FEA8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8018FEAC: lwc1        $f4, -0x454($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X454);
    // 0x8018FEB0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018FEB4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8018FEB8: jal         0x8007C484
    // 0x8018FEBC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_23;
    // 0x8018FEBC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_23:
    // 0x8018FEC0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018FEC4: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8018FEC8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x8018FECC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8018FED0:
    // 0x8018FED0: bne         $v0, $zero, L_8018FF68
    if (ctx->r2 != 0) {
        // 0x8018FED4: nop
    
            goto L_8018FF68;
    }
    // 0x8018FED4: nop

    // 0x8018FED8: jal         0x80004EB0
    // 0x8018FEDC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x8018FEDC: nop

    after_24:
    // 0x8018FEE0: jal         0x80004EB0
    // 0x8018FEE4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_25;
    // 0x8018FEE4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x8018FEE8: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8018FEEC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018FEF0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018FEF4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8018FEF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018FEFC: sub.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8018FF00: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FF04: lwc1        $f8, -0x2C74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x8018FF08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FF0C: mul.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8018FF10: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8018FF14: lwc1        $f18, -0x2C70($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x8018FF18: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018FF1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FF20: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8018FF24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018FF28: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8018FF2C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018FF30: mul.s       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8018FF34: add.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018FF38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FF3C: lwc1        $f6, -0x2C6C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C6C);
    // 0x8018FF40: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018FF44: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018FF48: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8018FF4C: add.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018FF50: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8018FF54: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8018FF58: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8018FF5C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8018FF60: jal         0x8007BFFC
    // 0x8018FF64: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_26;
    // 0x8018FF64: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_26:
L_8018FF68:
    // 0x8018FF68: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018FF6C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8018FF70: slti        $at, $v0, 0x6F
    ctx->r1 = SIGNED(ctx->r2) < 0X6F ? 1 : 0;
    // 0x8018FF74: bne         $at, $zero, L_8018FF90
    if (ctx->r1 != 0) {
        // 0x8018FF78: slti        $at, $v0, 0xC8
        ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
            goto L_8018FF90;
    }
    // 0x8018FF78: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x8018FF7C: beq         $at, $zero, L_8018FF90
    if (ctx->r1 == 0) {
        // 0x8018FF80: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8018FF90;
    }
    // 0x8018FF80: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8018FF84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018FF88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018FF8C: swc1        $f8, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f8.u32l;
L_8018FF90:
    // 0x8018FF90: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x8018FF94: bne         $at, $zero, L_8018FFBC
    if (ctx->r1 != 0) {
        // 0x8018FF98: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8018FFBC;
    }
    // 0x8018FF98: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8018FF9C: addiu       $at, $zero, 0xEB
    ctx->r1 = ADD32(0, 0XEB);
    // 0x8018FFA0: beq         $v1, $at, L_8019024C
    if (ctx->r3 == ctx->r1) {
        // 0x8018FFA4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8019024C;
    }
    // 0x8018FFA4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018FFA8: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8018FFAC: beql        $v1, $at, L_8019026C
    if (ctx->r3 == ctx->r1) {
        // 0x8018FFB0: lw          $t8, 0x1D0($s1)
        ctx->r24 = MEM_W(ctx->r17, 0X1D0);
            goto L_8019026C;
    }
    goto skip_2;
    // 0x8018FFB0: lw          $t8, 0x1D0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1D0);
    skip_2:
    // 0x8018FFB4: b           L_801902A4
    // 0x8018FFB8: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
        goto L_801902A4;
    // 0x8018FFB8: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
L_8018FFBC:
    // 0x8018FFBC: slti        $at, $v1, 0x83
    ctx->r1 = SIGNED(ctx->r3) < 0X83 ? 1 : 0;
    // 0x8018FFC0: bne         $at, $zero, L_8018FFDC
    if (ctx->r1 != 0) {
        // 0x8018FFC4: addiu       $t9, $v1, -0x5C
        ctx->r25 = ADD32(ctx->r3, -0X5C);
            goto L_8018FFDC;
    }
    // 0x8018FFC4: addiu       $t9, $v1, -0x5C
    ctx->r25 = ADD32(ctx->r3, -0X5C);
    // 0x8018FFC8: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x8018FFCC: beq         $v1, $at, L_8018FFFC
    if (ctx->r3 == ctx->r1) {
        // 0x8018FFD0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8018FFFC;
    }
    // 0x8018FFD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018FFD4: b           L_801902A4
    // 0x8018FFD8: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
        goto L_801902A4;
    // 0x8018FFD8: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
L_8018FFDC:
    // 0x8018FFDC: sltiu       $at, $t9, 0x27
    ctx->r1 = ctx->r25 < 0X27 ? 1 : 0;
    // 0x8018FFE0: beq         $at, $zero, L_801902A0
    if (ctx->r1 == 0) {
        // 0x8018FFE4: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801902A0;
    }
    // 0x8018FFE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018FFE8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018FFEC: addu        $at, $at, $t9
    gpr jr_addend_8018FFF4 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8018FFF0: lw          $t9, -0x450($at)
    ctx->r25 = ADD32(ctx->r1, -0X450);
    // 0x8018FFF4: jr          $t9
    // 0x8018FFF8: nop

    switch (jr_addend_8018FFF4 >> 2) {
        case 0: goto L_80190018; break;
        case 1: goto L_801902A0; break;
        case 2: goto L_801902A0; break;
        case 3: goto L_80190028; break;
        case 4: goto L_801902A0; break;
        case 5: goto L_801902A0; break;
        case 6: goto L_801902A0; break;
        case 7: goto L_801902A0; break;
        case 8: goto L_801900D0; break;
        case 9: goto L_801902A0; break;
        case 10: goto L_801902A0; break;
        case 11: goto L_801902A0; break;
        case 12: goto L_801902A0; break;
        case 13: goto L_801900D0; break;
        case 14: goto L_801902A0; break;
        case 15: goto L_801902A0; break;
        case 16: goto L_801902A0; break;
        case 17: goto L_801902A0; break;
        case 18: goto L_801900D0; break;
        case 19: goto L_801902A0; break;
        case 20: goto L_801902A0; break;
        case 21: goto L_801902A0; break;
        case 22: goto L_801902A0; break;
        case 23: goto L_801902A0; break;
        case 24: goto L_801902A0; break;
        case 25: goto L_801902A0; break;
        case 26: goto L_801902A0; break;
        case 27: goto L_801902A0; break;
        case 28: goto L_801902A0; break;
        case 29: goto L_801902A0; break;
        case 30: goto L_801902A0; break;
        case 31: goto L_801902A0; break;
        case 32: goto L_801902A0; break;
        case 33: goto L_801902A0; break;
        case 34: goto L_801902A0; break;
        case 35: goto L_801902A0; break;
        case 36: goto L_801902A0; break;
        case 37: goto L_801902A0; break;
        case 38: goto L_80190104; break;
        default: switch_error(__func__, 0x8018FFF4, 0x8019FBB0);
    }
    // 0x8018FFF8: nop

L_8018FFFC:
    // 0x8018FFFC: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x80190000: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80190004: jal         0x8001D444
    // 0x80190008: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_27;
    // 0x80190008: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_27:
    // 0x8019000C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80190010: b           L_801902A0
    // 0x80190014: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_801902A0;
    // 0x80190014: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80190018:
    // 0x80190018: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8019001C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80190020: b           L_801902A0
    // 0x80190024: sh          $t1, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = ctx->r9;
        goto L_801902A0;
    // 0x80190024: sh          $t1, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = ctx->r9;
L_80190028:
    // 0x80190028: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019002C: jal         0x8001A500
    // 0x80190030: addiu       $a0, $a0, -0x2B78
    ctx->r4 = ADD32(ctx->r4, -0X2B78);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_28;
    // 0x80190030: addiu       $a0, $a0, -0x2B78
    ctx->r4 = ADD32(ctx->r4, -0X2B78);
    after_28:
    // 0x80190034: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80190038: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019003C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80190040: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80190044: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x80190048: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019004C: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x80190050: ori         $a0, $a0, 0xF026
    ctx->r4 = ctx->r4 | 0XF026;
    // 0x80190054: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80190058: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019005C: jal         0x80019218
    // 0x80190060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_29;
    // 0x80190060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_29:
    // 0x80190064: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80190068: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019006C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80190070: addiu       $s0, $s0, 0x3860
    ctx->r16 = ADD32(ctx->r16, 0X3860);
    // 0x80190074: addiu       $a1, $a1, 0x1B0
    ctx->r5 = ADD32(ctx->r5, 0X1B0);
    // 0x80190078: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
L_8019007C:
    // 0x8019007C: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x80190080: jal         0x80060FBC
    // 0x80190084: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    Object_Kill(rdram, ctx);
        goto after_30;
    // 0x80190084: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_30:
    // 0x80190088: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8019008C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80190090: addiu       $a1, $a1, 0x8C
    ctx->r5 = ADD32(ctx->r5, 0X8C);
    // 0x80190094: bne         $a1, $s0, L_8019007C
    if (ctx->r5 != ctx->r16) {
        // 0x80190098: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_8019007C;
    }
    // 0x80190098: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    // 0x8019009C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801900A0: lwc1        $f12, -0x2C74($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x801900A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801900A8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801900AC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801900B0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801900B4: lw          $a2, -0x2C6C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2C6C);
    // 0x801900B8: lwc1        $f14, -0x2C70($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x801900BC: jal         0x8007B344
    // 0x801900C0: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_31;
    // 0x801900C0: lui         $a3, 0x43C8
    ctx->r7 = S32(0X43C8 << 16);
    after_31:
    // 0x801900C4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801900C8: b           L_801902A0
    // 0x801900CC: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_801902A0;
    // 0x801900CC: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_801900D0:
    // 0x801900D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801900D4: lwc1        $f12, -0x2C74($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x801900D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801900DC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801900E0: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x801900E4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801900E8: lw          $a2, -0x2C6C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2C6C);
    // 0x801900EC: lwc1        $f14, -0x2C70($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x801900F0: jal         0x8007B344
    // 0x801900F4: lui         $a3, 0x437A
    ctx->r7 = S32(0X437A << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_32;
    // 0x801900F4: lui         $a3, 0x437A
    ctx->r7 = S32(0X437A << 16);
    after_32:
    // 0x801900F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801900FC: b           L_801902A0
    // 0x80190100: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_801902A0;
    // 0x80190100: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_80190104:
    // 0x80190104: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80190108:
    // 0x80190108: jal         0x80004EB0
    // 0x8019010C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_33;
    // 0x8019010C: nop

    after_33:
    // 0x80190110: jal         0x80004EB0
    // 0x80190114: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_34;
    // 0x80190114: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_34:
    // 0x80190118: jal         0x80004EB0
    // 0x8019011C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_35;
    // 0x8019011C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_35:
    // 0x80190120: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80190124: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190128: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019012C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80190130: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80190134: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190138: lwc1        $f8, -0x2C74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x8019013C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80190140: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190144: lwc1        $f10, -0x2C70($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x80190148: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8019014C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80190150: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190154: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80190158: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019015C: lui         $a3, 0x40A3
    ctx->r7 = S32(0X40A3 << 16);
    // 0x80190160: ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // 0x80190164: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80190168: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8019016C: sub.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80190170: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80190174: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80190178: lwc1        $f10, -0x2C6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2C6C);
    // 0x8019017C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80190180: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80190184: jal         0x80079618
    // 0x80190188: nop

    func_effect_80079618(rdram, ctx);
        goto after_36;
    // 0x80190188: nop

    after_36:
    // 0x8019018C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80190190: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    // 0x80190194: bne         $at, $zero, L_80190108
    if (ctx->r1 != 0) {
        // 0x80190198: nop
    
            goto L_80190108;
    }
    // 0x80190198: nop

    // 0x8019019C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801901A0:
    // 0x801901A0: jal         0x80004EB0
    // 0x801901A4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_37;
    // 0x801901A4: nop

    after_37:
    // 0x801901A8: jal         0x80004EB0
    // 0x801901AC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_38;
    // 0x801901AC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_38:
    // 0x801901B0: jal         0x80004EB0
    // 0x801901B4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_39;
    // 0x801901B4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_39:
    // 0x801901B8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801901BC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801901C0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801901C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801901C8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801901CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801901D0: lwc1        $f6, -0x2C74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x801901D4: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x801901D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801901DC: lwc1        $f8, -0x2C70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x801901E0: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x801901E4: mul.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801901E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801901EC: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801901F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801901F4: lui         $a3, 0x40A3
    ctx->r7 = S32(0X40A3 << 16);
    // 0x801901F8: ori         $a3, $a3, 0x851F
    ctx->r7 = ctx->r7 | 0X851F;
    // 0x801901FC: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80190200: mul.s       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80190204: sub.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80190208: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8019020C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80190210: lwc1        $f8, -0x2C6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C6C);
    // 0x80190214: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80190218: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019021C: jal         0x800795AC
    // 0x80190220: nop

    Effect_Effect357_Spawn95(rdram, ctx);
        goto after_40;
    // 0x80190220: nop

    after_40:
    // 0x80190224: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80190228: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8019022C: bne         $s0, $at, L_801901A0
    if (ctx->r16 != ctx->r1) {
        // 0x80190230: nop
    
            goto L_801901A0;
    }
    // 0x80190230: nop

    // 0x80190234: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80190238: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019023C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80190240: sh          $t5, -0x2C32($at)
    MEM_H(-0X2C32, ctx->r1) = ctx->r13;
    // 0x80190244: b           L_801902A0
    // 0x80190248: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_801902A0;
    // 0x80190248: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_8019024C:
    // 0x8019024C: sw          $t6, 0x204($s1)
    MEM_W(0X204, ctx->r17) = ctx->r14;
    // 0x80190250: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80190254: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190258: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019025C: sw          $t7, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r15;
    // 0x80190260: b           L_801902A0
    // 0x80190264: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
        goto L_801902A0;
    // 0x80190264: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x80190268: lw          $t8, 0x1D0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1D0);
L_8019026C:
    // 0x8019026C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190270: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190274: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80190278: sw          $t9, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r25;
    // 0x8019027C: swc1        $f6, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f6.u32l;
    // 0x80190280: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80190284: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190288: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019028C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80190290: swc1        $f4, 0x7A5C($at)
    MEM_W(0X7A5C, ctx->r1) = ctx->f4.u32l;
    // 0x80190294: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190298: swc1        $f20, 0x7A60($at)
    MEM_W(0X7A60, ctx->r1) = ctx->f20.u32l;
    // 0x8019029C: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
L_801902A0:
    // 0x801902A0: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
L_801902A4:
    // 0x801902A4: bne         $at, $zero, L_801902E8
    if (ctx->r1 != 0) {
        // 0x801902A8: lui         $t1, 0x8018
        ctx->r9 = S32(0X8018 << 16);
            goto L_801902E8;
    }
    // 0x801902A8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801902AC: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x801902B0: beq         $at, $zero, L_801902E8
    if (ctx->r1 == 0) {
        // 0x801902B4: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_801902E8;
    }
    // 0x801902B4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801902B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801902BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801902C0: swc1        $f20, -0x7B30($at)
    MEM_W(-0X7B30, ctx->r1) = ctx->f20.u32l;
    // 0x801902C4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801902C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801902CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801902D0: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x801902D4: swc1        $f8, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f8.u32l;
    // 0x801902D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801902DC: swc1        $f20, -0x7B28($at)
    MEM_W(-0X7B28, ctx->r1) = ctx->f20.u32l;
    // 0x801902E0: b           L_80190310
    // 0x801902E4: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
        goto L_80190310;
    // 0x801902E4: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
L_801902E8:
    // 0x801902E8: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x801902EC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801902F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801902F4: swc1        $f10, -0x7B30($at)
    MEM_W(-0X7B30, ctx->r1) = ctx->f10.u32l;
    // 0x801902F8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801902FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190300: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80190304: swc1        $f6, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f6.u32l;
    // 0x80190308: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019030C: swc1        $f20, -0x7B28($at)
    MEM_W(-0X7B28, ctx->r1) = ctx->f20.u32l;
L_80190310:
    // 0x80190310: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x80190314: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190318: lwc1        $f8, -0x3B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3B4);
    // 0x8019031C: lwc1        $f4, 0xC8($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XC8);
    // 0x80190320: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190324: lwc1        $f6, 0x7988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x80190328: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8019032C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80190330: b           L_80190758
    // 0x80190334: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
        goto L_80190758;
    // 0x80190334: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
L_80190338:
    // 0x80190338: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019033C: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x80190340: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80190344: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80190348: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8019034C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80190350: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80190354: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80190358: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
    // 0x8019035C: lw          $t2, 0x7A80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7A80);
    // 0x80190360: slti        $at, $t2, 0x2A8
    ctx->r1 = SIGNED(ctx->r10) < 0X2A8 ? 1 : 0;
    // 0x80190364: beq         $at, $zero, L_801903D0
    if (ctx->r1 == 0) {
        // 0x80190368: nop
    
            goto L_801903D0;
    }
    // 0x80190368: nop

    // 0x8019036C: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80190370: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190374: lwc1        $f8, -0x3B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3B0);
    // 0x80190378: lwc1        $f4, 0xC8($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XC8);
    // 0x8019037C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190380: lwc1        $f10, 0x7988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x80190384: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80190388: lui         $a1, 0x3F33
    ctx->r5 = S32(0X3F33 << 16);
    // 0x8019038C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80190390: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x80190394: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80190398: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019039C: ori         $a1, $a1, 0x3333
    ctx->r5 = ctx->r5 | 0X3333;
    // 0x801903A0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801903A4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801903A8: addiu       $a0, $a0, 0x7A60
    ctx->r4 = ADD32(ctx->r4, 0X7A60);
    // 0x801903AC: jal         0x8009BC2C
    // 0x801903B0: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_41;
    // 0x801903B0: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    after_41:
    // 0x801903B4: lwc1        $f2, 0xC8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x801903B8: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x801903BC: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x801903C0: swc1        $f2, 0x6D8($s0)
    MEM_W(0X6D8, ctx->r16) = ctx->f2.u32l;
    // 0x801903C4: swc1        $f2, 0x3E4($s0)
    MEM_W(0X3E4, ctx->r16) = ctx->f2.u32l;
    // 0x801903C8: b           L_801903FC
    // 0x801903CC: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
        goto L_801903FC;
    // 0x801903CC: swc1        $f2, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f2.u32l;
L_801903D0:
    // 0x801903D0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801903D4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801903D8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801903DC: lui         $a3, 0x3BA3
    ctx->r7 = S32(0X3BA3 << 16);
    // 0x801903E0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x801903E4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801903E8: addiu       $a0, $a0, 0x7A60
    ctx->r4 = ADD32(ctx->r4, 0X7A60);
    // 0x801903EC: jal         0x8009BC2C
    // 0x801903F0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_42;
    // 0x801903F0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_42:
    // 0x801903F4: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x801903F8: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
L_801903FC:
    // 0x801903FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80190400: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80190404: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80190408: addiu       $a0, $s1, 0xD0
    ctx->r4 = ADD32(ctx->r17, 0XD0);
    // 0x8019040C: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x80190410: jal         0x8009BC2C
    // 0x80190414: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_43;
    // 0x80190414: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_43:
    // 0x80190418: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019041C: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80190420: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x80190424: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x80190428: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8019042C: addiu       $a0, $a0, 0x7A48
    ctx->r4 = ADD32(ctx->r4, 0X7A48);
    // 0x80190430: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80190434: jal         0x8009BC2C
    // 0x80190438: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_44;
    // 0x80190438: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_44:
    // 0x8019043C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190440: lwc1        $f8, 0x7A5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7A5C);
    // 0x80190444: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190448: lwc1        $f10, -0x3AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3AC);
    // 0x8019044C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190450: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190454: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80190458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019045C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80190460: jal         0x80005E90
    // 0x80190464: nop

    Matrix_RotateY(rdram, ctx);
        goto after_45;
    // 0x80190464: nop

    after_45:
    // 0x80190468: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019046C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190470: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80190474: jal         0x80005D44
    // 0x80190478: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_46;
    // 0x80190478: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_46:
    // 0x8019047C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80190480: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190484: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190488: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x8019048C: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x80190490: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190494: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80190498: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x8019049C: jal         0x80006A20
    // 0x801904A0: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_47;
    // 0x801904A0: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    after_47:
    // 0x801904A4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801904A8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801904AC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801904B0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801904B4: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801904B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801904BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801904C0: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801904C4: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801904C8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801904CC: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x801904D0: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x801904D4: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x801904D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801904DC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801904E0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801904E4: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801904E8: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x801904EC: lwc1        $f6, 0x7C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x801904F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801904F4: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x801904F8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801904FC: swc1        $f10, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f10.u32l;
    // 0x80190500: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x80190504: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190508: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x8019050C: lwc1        $f4, 0x78($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80190510: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190514: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x80190518: lwc1        $f8, 0x7C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x8019051C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190520: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80190524: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
    // 0x80190528: addiu       $at, $zero, 0x2E4
    ctx->r1 = ADD32(0, 0X2E4);
    // 0x8019052C: beq         $v1, $at, L_8019055C
    if (ctx->r3 == ctx->r1) {
        // 0x80190530: addiu       $at, $zero, 0x2F8
        ctx->r1 = ADD32(0, 0X2F8);
            goto L_8019055C;
    }
    // 0x80190530: addiu       $at, $zero, 0x2F8
    ctx->r1 = ADD32(0, 0X2F8);
    // 0x80190534: beq         $v1, $at, L_80190564
    if (ctx->r3 == ctx->r1) {
        // 0x80190538: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80190564;
    }
    // 0x80190538: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019053C: addiu       $at, $zero, 0x30C
    ctx->r1 = ADD32(0, 0X30C);
    // 0x80190540: beq         $v1, $at, L_8019056C
    if (ctx->r3 == ctx->r1) {
        // 0x80190544: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8019056C;
    }
    // 0x80190544: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80190548: addiu       $at, $zero, 0x320
    ctx->r1 = ADD32(0, 0X320);
    // 0x8019054C: beql        $v1, $at, L_80190578
    if (ctx->r3 == ctx->r1) {
        // 0x80190550: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_80190578;
    }
    goto skip_3;
    // 0x80190550: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    skip_3:
    // 0x80190554: b           L_80190758
    // 0x80190558: nop

        goto L_80190758;
    // 0x80190558: nop

L_8019055C:
    // 0x8019055C: b           L_80190758
    // 0x80190560: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
        goto L_80190758;
    // 0x80190560: sh          $t4, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r12;
L_80190564:
    // 0x80190564: b           L_80190758
    // 0x80190568: sh          $t5, 0x3AC($s0)
    MEM_H(0X3AC, ctx->r16) = ctx->r13;
        goto L_80190758;
    // 0x80190568: sh          $t5, 0x3AC($s0)
    MEM_H(0X3AC, ctx->r16) = ctx->r13;
L_8019056C:
    // 0x8019056C: b           L_80190758
    // 0x80190570: sh          $t6, 0x6A0($s0)
    MEM_H(0X6A0, ctx->r16) = ctx->r14;
        goto L_80190758;
    // 0x80190570: sh          $t6, 0x6A0($s0)
    MEM_H(0X6A0, ctx->r16) = ctx->r14;
    // 0x80190574: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
L_80190578:
    // 0x80190578: lw          $t7, 0x1D0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1D0);
    // 0x8019057C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190580: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190584: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80190588: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8019058C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80190590: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80190594: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80190598: sw          $t8, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r24;
    // 0x8019059C: sw          $t9, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = ctx->r25;
    // 0x801905A0: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x801905A4: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x801905A8: swc1        $f6, 0x194($s1)
    MEM_W(0X194, ctx->r17) = ctx->f6.u32l;
    // 0x801905AC: swc1        $f4, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f4.u32l;
    // 0x801905B0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801905B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801905B8: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801905BC: addiu       $a1, $s1, 0x460
    ctx->r5 = ADD32(ctx->r17, 0X460);
    // 0x801905C0: jal         0x80019218
    // 0x801905C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_48;
    // 0x801905C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_48:
    // 0x801905C8: b           L_80190758
    // 0x801905CC: nop

        goto L_80190758;
    // 0x801905CC: nop

L_801905D0:
    // 0x801905D0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801905D4: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801905D8: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801905DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801905E0: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x801905E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801905E8: swc1        $f8, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f8.u32l;
    // 0x801905EC: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x801905F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801905F4: swc1        $f10, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f10.u32l;
    // 0x801905F8: lwc1        $f6, 0x7C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x801905FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190600: add.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80190604: swc1        $f4, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f4.u32l;
    // 0x80190608: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019060C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80190610: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80190614: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190618: lwc1        $f10, 0xD0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XD0);
    // 0x8019061C: lw          $v1, 0x1F8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1F8);
    // 0x80190620: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80190624: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80190628: swc1        $f8, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f8.u32l;
    // 0x8019062C: bne         $v1, $at, L_80190640
    if (ctx->r3 != ctx->r1) {
        // 0x80190630: swc1        $f4, 0xD0($s1)
        MEM_W(0XD0, ctx->r17) = ctx->f4.u32l;
            goto L_80190640;
    }
    // 0x80190630: swc1        $f4, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f4.u32l;
    // 0x80190634: jal         0x8001DBD0
    // 0x80190638: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    Audio_FadeOutAll(rdram, ctx);
        goto after_49;
    // 0x80190638: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_49:
    // 0x8019063C: lw          $v1, 0x1F8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1F8);
L_80190640:
    // 0x80190640: bne         $v1, $zero, L_80190758
    if (ctx->r3 != 0) {
        // 0x80190644: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_80190758;
    }
    // 0x80190644: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80190648: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019064C: addiu       $v1, $v1, -0x7CB0
    ctx->r3 = ADD32(ctx->r3, -0X7CB0);
    // 0x80190650: addiu       $v0, $v0, -0x7CAC
    ctx->r2 = ADD32(ctx->r2, -0X7CAC);
    // 0x80190654: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80190658: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8019065C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80190660: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80190664: addiu       $a1, $a1, -0x7CA8
    ctx->r5 = ADD32(ctx->r5, -0X7CA8);
    // 0x80190668: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8019066C: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80190670: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x80190674: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80190678: lw          $t4, -0x7CC0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7CC0);
    // 0x8019067C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80190680: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80190684: bne         $t0, $t4, L_80190758
    if (ctx->r8 != ctx->r12) {
        // 0x80190688: addiu       $t6, $zero, 0x7
        ctx->r14 = ADD32(0, 0X7);
            goto L_80190758;
    }
    // 0x80190688: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8019068C: lbu         $t5, 0x1A90($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X1A90);
    // 0x80190690: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80190694: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80190698: sb          $t5, 0x1A94($at)
    MEM_B(0X1A94, ctx->r1) = ctx->r13;
    // 0x8019069C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801906A0: sh          $t6, 0x1A32($at)
    MEM_H(0X1A32, ctx->r1) = ctx->r14;
    // 0x801906A4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801906A8: jal         0x8001CA24
    // 0x801906AC: sh          $t7, 0x1A30($at)
    MEM_H(0X1A30, ctx->r1) = ctx->r15;
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_50;
    // 0x801906AC: sh          $t7, 0x1A30($at)
    MEM_H(0X1A30, ctx->r1) = ctx->r15;
    after_50:
    // 0x801906B0: jal         0x8001A500
    // 0x801906B4: addiu       $a0, $s1, 0x460
    ctx->r4 = ADD32(ctx->r17, 0X460);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_51;
    // 0x801906B4: addiu       $a0, $s1, 0x460
    ctx->r4 = ADD32(ctx->r17, 0X460);
    after_51:
    // 0x801906B8: jal         0x800A3F50
    // 0x801906BC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_52;
    // 0x801906BC: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_52:
    // 0x801906C0: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x801906C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x801906C8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801906CC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801906D0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801906D4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801906D8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801906DC: sb          $t8, 0x3191($at)
    MEM_B(0X3191, ctx->r1) = ctx->r24;
    // 0x801906E0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801906E4: addiu       $a3, $a3, 0x78E8
    ctx->r7 = ADD32(ctx->r7, 0X78E8);
    // 0x801906E8: addiu       $a0, $a0, 0x78D4
    ctx->r4 = ADD32(ctx->r4, 0X78D4);
    // 0x801906EC: addiu       $a2, $a2, 0x78F4
    ctx->r6 = ADD32(ctx->r6, 0X78F4);
    // 0x801906F0: addiu       $a1, $a1, 0x78B4
    ctx->r5 = ADD32(ctx->r5, 0X78B4);
    // 0x801906F4: addiu       $v1, $v1, 0x7C3C
    ctx->r3 = ADD32(ctx->r3, 0X7C3C);
L_801906F8:
    // 0x801906F8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801906FC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80190700: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80190704: sltu        $at, $a0, $a3
    ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x80190708: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8019070C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80190710: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80190714: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x80190718: sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
    // 0x8019071C: bne         $at, $zero, L_801906F8
    if (ctx->r1 != 0) {
        // 0x80190720: sw          $t9, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r25;
            goto L_801906F8;
    }
    // 0x80190720: sw          $t9, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r25;
    // 0x80190724: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80190728: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019072C: addiu       $v0, $v0, 0x7C48
    ctx->r2 = ADD32(ctx->r2, 0X7C48);
    // 0x80190730: addiu       $v1, $v1, 0x7C3C
    ctx->r3 = ADD32(ctx->r3, 0X7C3C);
    // 0x80190734: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
L_80190738:
    // 0x80190738: bnel        $t1, $zero, L_80190748
    if (ctx->r9 != 0) {
        // 0x8019073C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80190748;
    }
    goto skip_4;
    // 0x8019073C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_4:
    // 0x80190740: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80190744: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80190748:
    // 0x80190748: bnel        $v1, $v0, L_80190738
    if (ctx->r3 != ctx->r2) {
        // 0x8019074C: lw          $t1, 0x0($v1)
        ctx->r9 = MEM_W(ctx->r3, 0X0);
            goto L_80190738;
    }
    goto skip_5;
    // 0x8019074C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    skip_5:
    // 0x80190750: jal         0x80088564
    // 0x80190754: nop

    HUD_Bolse_Area6_SaveData(rdram, ctx);
        goto after_53;
    // 0x80190754: nop

    after_53:
L_80190758:
    // 0x80190758: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019075C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x80190760: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x80190764: beq         $v1, $at, L_80190784
    if (ctx->r3 == ctx->r1) {
        // 0x80190768: addiu       $at, $zero, 0x258
        ctx->r1 = ADD32(0, 0X258);
            goto L_80190784;
    }
    // 0x80190768: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    // 0x8019076C: beq         $v1, $at, L_80190794
    if (ctx->r3 == ctx->r1) {
        // 0x80190770: addiu       $at, $zero, 0x26C
        ctx->r1 = ADD32(0, 0X26C);
            goto L_80190794;
    }
    // 0x80190770: addiu       $at, $zero, 0x26C
    ctx->r1 = ADD32(0, 0X26C);
    // 0x80190774: beq         $v1, $at, L_801907A0
    if (ctx->r3 == ctx->r1) {
        // 0x80190778: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801907A0;
    }
    // 0x80190778: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019077C: b           L_801907AC
    // 0x80190780: nop

        goto L_801907AC;
    // 0x80190780: nop

L_80190784:
    // 0x80190784: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80190788: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019078C: b           L_801907AC
    // 0x80190790: sb          $t2, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r10;
        goto L_801907AC;
    // 0x80190790: sb          $t2, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r10;
L_80190794:
    // 0x80190794: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190798: b           L_801907AC
    // 0x8019079C: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
        goto L_801907AC;
    // 0x8019079C: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_801907A0:
    // 0x801907A0: addiu       $a0, $a0, 0x178
    ctx->r4 = ADD32(ctx->r4, 0X178);
    // 0x801907A4: jal         0x800BA808
    // 0x801907A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_54;
    // 0x801907A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_54:
L_801907AC:
    // 0x801907AC: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x801907B0: lh          $t3, -0x2C32($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2C32);
    // 0x801907B4: beq         $t3, $zero, L_8019096C
    if (ctx->r11 == 0) {
        // 0x801907B8: nop
    
            goto L_8019096C;
    }
    // 0x801907B8: nop

    // 0x801907BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801907C0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801907C4: lui         $a2, 0x3CF5
    ctx->r6 = S32(0X3CF5 << 16);
    // 0x801907C8: lui         $a3, 0x3C23
    ctx->r7 = S32(0X3C23 << 16);
    // 0x801907CC: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x801907D0: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x801907D4: addiu       $a0, $a0, -0x2B14
    ctx->r4 = ADD32(ctx->r4, -0X2B14);
    // 0x801907D8: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x801907DC: jal         0x8009BC2C
    // 0x801907E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_55;
    // 0x801907E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_55:
    // 0x801907E4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801907E8: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x801907EC: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x801907F0: bne         $t4, $zero, L_801908B4
    if (ctx->r12 != 0) {
        // 0x801907F4: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_801908B4;
    }
    // 0x801907F4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x801907F8: jal         0x80004EB0
    // 0x801907FC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_56;
    // 0x801907FC: nop

    after_56:
    // 0x80190800: jal         0x80004EB0
    // 0x80190804: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_57;
    // 0x80190804: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_57:
    // 0x80190808: jal         0x80004EB0
    // 0x8019080C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_58;
    // 0x8019080C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_58:
    // 0x80190810: jal         0x80004EB0
    // 0x80190814: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_59;
    // 0x80190814: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_59:
    // 0x80190818: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019081C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190820: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80190824: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190828: lwc1        $f18, -0x3A8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3A8);
    // 0x8019082C: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80190830: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80190834: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190838: lwc1        $f8, -0x2C74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x8019083C: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80190840: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80190844: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80190848: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019084C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80190850: sub.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80190854: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80190858: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8019085C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80190860: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80190864: lwc1        $f8, -0x2C70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x80190868: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019086C: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80190870: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80190874: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80190878: lwc1        $f4, -0x2C6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C6C);
    // 0x8019087C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190880: lwc1        $f10, -0x3A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3A4);
    // 0x80190884: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190888: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019088C: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80190890: lwc1        $f4, -0x3A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3A0);
    // 0x80190894: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80190898: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019089C: jal         0x8007C484
    // 0x801908A0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_60;
    // 0x801908A0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_60:
    // 0x801908A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801908A8: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x801908AC: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x801908B0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_801908B4:
    // 0x801908B4: bne         $v0, $zero, L_8019096C
    if (ctx->r2 != 0) {
        // 0x801908B8: nop
    
            goto L_8019096C;
    }
    // 0x801908B8: nop

    // 0x801908BC: jal         0x80004EB0
    // 0x801908C0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_61;
    // 0x801908C0: nop

    after_61:
    // 0x801908C4: jal         0x80004EB0
    // 0x801908C8: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_62;
    // 0x801908C8: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    after_62:
    // 0x801908CC: jal         0x80004EB0
    // 0x801908D0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_63;
    // 0x801908D0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_63:
    // 0x801908D4: jal         0x80004EB0
    // 0x801908D8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_64;
    // 0x801908D8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_64:
    // 0x801908DC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801908E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801908E4: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801908E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801908EC: lwc1        $f18, -0x39C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X39C);
    // 0x801908F0: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801908F4: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801908F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801908FC: lwc1        $f8, -0x2C74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C74);
    // 0x80190900: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80190904: sub.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80190908: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019090C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190910: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80190914: sub.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80190918: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8019091C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80190920: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80190924: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80190928: lwc1        $f8, -0x2C70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2C70);
    // 0x8019092C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80190930: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80190934: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80190938: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8019093C: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80190940: lwc1        $f4, -0x2C6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C6C);
    // 0x80190944: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80190948: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019094C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190950: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80190954: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80190958: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019095C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80190960: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190964: jal         0x8007BFFC
    // 0x80190968: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_65;
    // 0x80190968: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_65:
L_8019096C:
    // 0x8019096C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80190970: addiu       $a0, $a0, 0x3D0
    ctx->r4 = ADD32(ctx->r4, 0X3D0);
    // 0x80190974: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x80190978: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019097C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80190980: jal         0x8009BC2C
    // 0x80190984: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_66;
    // 0x80190984: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_66:
    // 0x80190988: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8019098C: addiu       $a0, $a0, 0x3D4
    ctx->r4 = ADD32(ctx->r4, 0X3D4);
    // 0x80190990: lw          $a1, 0x88($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X88);
    // 0x80190994: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80190998: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019099C: jal         0x8009BC2C
    // 0x801909A0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_67;
    // 0x801909A0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_67:
    // 0x801909A4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x801909A8: addiu       $a0, $a0, 0x3D8
    ctx->r4 = ADD32(ctx->r4, 0X3D8);
    // 0x801909AC: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x801909B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801909B4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801909B8: jal         0x8009BC2C
    // 0x801909BC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_68;
    // 0x801909BC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_68:
    // 0x801909C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801909C4: lwc1        $f10, 0x3D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3D0);
    // 0x801909C8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801909CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801909D0: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801909D4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801909D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801909DC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x801909E0: nop

    // 0x801909E4: sw          $t8, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r24;
    // 0x801909E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801909EC: lwc1        $f4, 0x3D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3D4);
    // 0x801909F0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801909F4: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801909F8: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x801909FC: nop

    // 0x80190A00: sw          $t1, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r9;
    // 0x80190A04: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190A08: lwc1        $f10, 0x3D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X3D8);
    // 0x80190A0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80190A10: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80190A14: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x80190A18: nop

    // 0x80190A1C: sw          $t3, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r11;
    // 0x80190A20: lwc1        $f8, 0xE8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x80190A24: lwc1        $f4, 0x114($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X114);
    // 0x80190A28: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80190A2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190A30: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80190A34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190A38: lwc1        $f8, -0x398($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X398);
    // 0x80190A3C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80190A40: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80190A44: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80190A48: jal         0x80005E90
    // 0x80190A4C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_69;
    // 0x80190A4C: nop

    after_69:
    // 0x80190A50: lwc1        $f6, 0x120($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X120);
    // 0x80190A54: lwc1        $f4, 0xE4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x80190A58: lwc1        $f10, 0x4D8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4D8);
    // 0x80190A5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190A60: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190A64: lwc1        $f4, -0x394($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X394);
    // 0x80190A68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190A6C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190A70: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80190A74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190A78: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80190A7C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80190A80: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80190A84: jal         0x80005D44
    // 0x80190A88: nop

    Matrix_RotateX(rdram, ctx);
        goto after_70;
    // 0x80190A88: nop

    after_70:
    // 0x80190A8C: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x80190A90: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x80190A94: lwc1        $f4, 0x110($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X110);
    // 0x80190A98: lwc1        $f6, 0xD0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XD0);
    // 0x80190A9C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190AA0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190AA4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190AA8: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80190AAC: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x80190AB0: jal         0x80006A20
    // 0x80190AB4: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_71;
    // 0x80190AB4: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    after_71:
    // 0x80190AB8: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80190ABC: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80190AC0: lw          $t4, 0x1D0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X1D0);
    // 0x80190AC4: swc1        $f10, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->f10.u32l;
    // 0x80190AC8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80190ACC: lwc1        $f10, 0xC0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x80190AD0: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80190AD4: swc1        $f6, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f6.u32l;
    // 0x80190AD8: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80190ADC: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80190AE0: slti        $at, $t4, 0xA
    ctx->r1 = SIGNED(ctx->r12) < 0XA ? 1 : 0;
    // 0x80190AE4: swc1        $f4, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f4.u32l;
    // 0x80190AE8: lwc1        $f8, 0xC4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x80190AEC: lwc1        $f4, 0x78($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X78);
    // 0x80190AF0: swc1        $f6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f6.u32l;
    // 0x80190AF4: lwc1        $f6, 0x7C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80190AF8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80190AFC: lwc1        $f4, 0xC8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x80190B00: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80190B04: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    // 0x80190B08: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190B0C: swc1        $f10, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f10.u32l;
    // 0x80190B10: lwc1        $f4, 0x12C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x80190B14: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x80190B18: swc1        $f8, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f8.u32l;
    // 0x80190B1C: lwc1        $f10, 0x7C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80190B20: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190B24: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80190B28: swc1        $f10, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f10.u32l;
    // 0x80190B2C: lwc1        $f10, 0x130($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X130);
    // 0x80190B30: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80190B34: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80190B38: beq         $at, $zero, L_80190C38
    if (ctx->r1 == 0) {
        // 0x80190B3C: swc1        $f6, 0xF8($s1)
        MEM_W(0XF8, ctx->r17) = ctx->f6.u32l;
            goto L_80190C38;
    }
    // 0x80190B3C: swc1        $f6, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f6.u32l;
    // 0x80190B40: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80190B44: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80190B48: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80190B4C: addiu       $a0, $s1, 0x130
    ctx->r4 = ADD32(ctx->r17, 0X130);
    // 0x80190B50: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80190B54: jal         0x8009BC2C
    // 0x80190B58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_72;
    // 0x80190B58: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_72:
    // 0x80190B5C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80190B60: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80190B64: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80190B68: addiu       $a0, $s1, 0x12C
    ctx->r4 = ADD32(ctx->r17, 0X12C);
    // 0x80190B6C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80190B70: jal         0x8009BC2C
    // 0x80190B74: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_73;
    // 0x80190B74: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_73:
    // 0x80190B78: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80190B7C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80190B80: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80190B84: addiu       $a0, $s1, 0x34
    ctx->r4 = ADD32(ctx->r17, 0X34);
    // 0x80190B88: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80190B8C: jal         0x8009BC2C
    // 0x80190B90: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_74;
    // 0x80190B90: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_74:
    // 0x80190B94: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80190B98: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80190B9C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80190BA0: addiu       $a0, $s1, 0x4D8
    ctx->r4 = ADD32(ctx->r17, 0X4D8);
    // 0x80190BA4: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80190BA8: jal         0x8009BD38
    // 0x80190BAC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_75;
    // 0x80190BAC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_75:
    // 0x80190BB0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x80190BB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80190BB8: lwc1        $f4, 0x78($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X78);
    // 0x80190BBC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80190BC0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80190BC4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80190BC8: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x80190BCC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80190BD0: bc1fl       L_80190BE8
    if (!c1cs) {
        // 0x80190BD4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80190BE8;
    }
    goto skip_6;
    // 0x80190BD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_6:
    // 0x80190BD8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80190BDC: jal         0x8009BC2C
    // 0x80190BE0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_76;
    // 0x80190BE0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_76:
    // 0x80190BE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80190BE8:
    // 0x80190BE8: jal         0x800B7184
    // 0x80190BEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Camera_Update360(rdram, ctx);
        goto after_77;
    // 0x80190BEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_77:
    // 0x80190BF0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190BF4: lwc1        $f0, -0x390($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X390);
    // 0x80190BF8: lwc1        $f10, 0xC0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x80190BFC: lwc1        $f8, 0x40($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X40);
    // 0x80190C00: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80190C04: lwc1        $f10, 0x44($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80190C08: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80190C0C: lwc1        $f8, 0xC4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x80190C10: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80190C14: swc1        $f4, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f4.u32l;
    // 0x80190C18: lwc1        $f8, 0x48($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X48);
    // 0x80190C1C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80190C20: lwc1        $f10, 0xC8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x80190C24: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80190C28: swc1        $f4, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f4.u32l;
    // 0x80190C2C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80190C30: b           L_80190D10
    // 0x80190C34: swc1        $f4, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f4.u32l;
        goto L_80190D10;
    // 0x80190C34: swc1        $f4, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f4.u32l;
L_80190C38:
    // 0x80190C38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80190C3C: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x80190C40: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80190C44: jal         0x8009BC2C
    // 0x80190C48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_78;
    // 0x80190C48: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_78:
    // 0x80190C4C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80190C50: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80190C54: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80190C58: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80190C5C: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80190C60: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80190C64: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x80190C68: addiu       $a0, $s1, 0x44
    ctx->r4 = ADD32(ctx->r17, 0X44);
    // 0x80190C6C: jal         0x8009BC2C
    // 0x80190C70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_79;
    // 0x80190C70: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_79:
    // 0x80190C74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80190C78: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80190C7C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80190C80: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80190C84: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80190C88: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80190C8C: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x80190C90: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    // 0x80190C94: jal         0x8009BC2C
    // 0x80190C98: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_80;
    // 0x80190C98: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_80:
    // 0x80190C9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190CA0: lwc1        $f20, -0x38C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X38C);
    // 0x80190CA4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80190CA8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80190CAC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80190CB0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80190CB4: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80190CB8: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x80190CBC: addiu       $a0, $s1, 0x4C
    ctx->r4 = ADD32(ctx->r17, 0X4C);
    // 0x80190CC0: jal         0x8009BC2C
    // 0x80190CC4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_81;
    // 0x80190CC4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_81:
    // 0x80190CC8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80190CCC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80190CD0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80190CD4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80190CD8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80190CDC: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x80190CE0: addiu       $a0, $s1, 0x50
    ctx->r4 = ADD32(ctx->r17, 0X50);
    // 0x80190CE4: jal         0x8009BC2C
    // 0x80190CE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_82;
    // 0x80190CE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_82:
    // 0x80190CEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80190CF0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80190CF4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80190CF8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80190CFC: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80190D00: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x80190D04: addiu       $a0, $s1, 0x54
    ctx->r4 = ADD32(ctx->r17, 0X54);
    // 0x80190D08: jal         0x8009BC2C
    // 0x80190D0C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_83;
    // 0x80190D0C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_83:
L_80190D10:
    // 0x80190D10: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80190D14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190D18: lwc1        $f6, 0x88($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X88);
    // 0x80190D1C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190D20: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190D24: swc1        $f10, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->f10.u32l;
    // 0x80190D28: lwc1        $f6, -0x388($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X388);
    // 0x80190D2C: lwc1        $f8, 0x88($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X88);
    // 0x80190D30: mul.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80190D34: jal         0x80023090
    // 0x80190D38: nop

    __sinf_recomp(rdram, ctx);
        goto after_84;
    // 0x80190D38: nop

    after_84:
    // 0x80190D3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190D40: lwc1        $f10, -0x384($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X384);
    // 0x80190D44: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x80190D48: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80190D4C: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80190D50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80190D54: lwc1        $f6, 0xF4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80190D58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190D5C: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80190D60: swc1        $f8, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f8.u32l;
    // 0x80190D64: swc1        $f10, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f10.u32l;
    // 0x80190D68: lwc1        $f6, -0x380($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X380);
    // 0x80190D6C: lwc1        $f8, 0xF4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x80190D70: mul.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80190D74: jal         0x80023090
    // 0x80190D78: nop

    __sinf_recomp(rdram, ctx);
        goto after_85;
    // 0x80190D78: nop

    after_85:
    // 0x80190D7C: swc1        $f0, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f0.u32l;
    // 0x80190D80: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80190D84: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80190D88: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x80190D8C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80190D90: jr          $ra
    // 0x80190D94: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80190D94: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void SectorZ_SpaceJunkUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E234: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8019E238: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8019E23C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8019E240: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8019E244: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8019E248: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019E24C: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8019E250: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8019E254: lwc1        $f6, 0xF4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x8019E258: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8019E25C: lwc1        $f16, 0xF8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x8019E260: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019E264: lb          $t6, 0xD0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0XD0);
    // 0x8019E268: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019E26C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019E270: swc1        $f8, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f8.u32l;
    // 0x8019E274: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019E278: beq         $t6, $zero, L_8019E38C
    if (ctx->r14 == 0) {
        // 0x8019E27C: swc1        $f18, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
            goto L_8019E38C;
    }
    // 0x8019E27C: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x8019E280: lh          $t8, 0xCE($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XCE);
    // 0x8019E284: lhu         $t9, 0xD6($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XD6);
    // 0x8019E288: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8019E28C: sh          $t7, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r15;
    // 0x8019E290: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8019E294: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x8019E298: sh          $t0, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r8;
    // 0x8019E29C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8019E2A0: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019E2A4: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019E2A8: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x8019E2AC: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x8019E2B0: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x8019E2B4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019E2B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019E2BC: jal         0x80019218
    // 0x8019E2C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019E2C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8019E2C4: lh          $t2, 0xCE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XCE);
    // 0x8019E2C8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019E2CC: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x8019E2D0: bgtzl       $t2, L_8019E390
    if (SIGNED(ctx->r10) > 0) {
        // 0x8019E2D4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8019E390;
    }
    goto skip_0;
    // 0x8019E2D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8019E2D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019E2DC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019E2E0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019E2E4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8019E2E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E2EC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019E2F0: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8019E2F4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019E2F8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019E2FC: jal         0x8007BFFC
    // 0x8019E300: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_1;
    // 0x8019E300: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8019E304: jal         0x80066254
    // 0x8019E308: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_2;
    // 0x8019E308: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8019E30C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019E310: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019E314: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8019E318: jal         0x80077240
    // 0x8019E31C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    BonusText_Display(rdram, ctx);
        goto after_3;
    // 0x8019E31C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_3:
    // 0x8019E320: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019E324: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x8019E328: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8019E32C: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8019E330: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E334: addiu       $t5, $t4, 0x3
    ctx->r13 = ADD32(ctx->r12, 0X3);
    // 0x8019E338: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8019E33C: sw          $t6, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r14;
    // 0x8019E340: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019E344: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019E348: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019E34C: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8019E350: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_8019E354:
    // 0x8019E354: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019E358: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019E35C: jal         0x800794CC
    // 0x8019E360: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_4;
    // 0x8019E360: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_4:
    // 0x8019E364: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019E368: bnel        $s0, $s2, L_8019E354
    if (ctx->r16 != ctx->r18) {
        // 0x8019E36C: mfc1        $a3, $f20
        ctx->r7 = (int32_t)ctx->f20.u32l;
            goto L_8019E354;
    }
    goto skip_1;
    // 0x8019E36C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x8019E370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8019E374: jal         0x80060FBC
    // 0x8019E378: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8019E378: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x8019E37C: lui         $a1, 0x1903
    ctx->r5 = S32(0X1903 << 16);
    // 0x8019E380: ori         $a1, $a1, 0x400F
    ctx->r5 = ctx->r5 | 0X400F;
    // 0x8019E384: jal         0x8007A6F0
    // 0x8019E388: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_6;
    // 0x8019E388: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_6:
L_8019E38C:
    // 0x8019E38C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8019E390:
    // 0x8019E390: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8019E394: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019E398: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8019E39C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8019E3A0: jr          $ra
    // 0x8019E3A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8019E3A4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Katina_SFTeamFlyTowardsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197F10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80197F14: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80197F18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80197F1C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80197F20: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x80197F24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80197F28: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80197F2C: beq         $v0, $at, L_80197F5C
    if (ctx->r2 == ctx->r1) {
        // 0x80197F30: lui         $a2, 0x3CA3
        ctx->r6 = S32(0X3CA3 << 16);
            goto L_80197F5C;
    }
    // 0x80197F30: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80197F34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80197F38: beq         $v0, $at, L_80198028
    if (ctx->r2 == ctx->r1) {
        // 0x80197F3C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80198028;
    }
    // 0x80197F3C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80197F40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80197F44: beq         $v0, $at, L_80198068
    if (ctx->r2 == ctx->r1) {
        // 0x80197F48: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80198068;
    }
    // 0x80197F48: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80197F4C: beq         $v0, $at, L_801980D0
    if (ctx->r2 == ctx->r1) {
        // 0x80197F50: addiu       $a0, $s0, 0xFC
        ctx->r4 = ADD32(ctx->r16, 0XFC);
            goto L_801980D0;
    }
    // 0x80197F50: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x80197F54: b           L_80198120
    // 0x80197F58: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
        goto L_80198120;
    // 0x80197F58: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80197F5C:
    // 0x80197F5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197F60: lwc1        $f4, -0x8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X8);
    // 0x80197F64: lw          $a1, 0x18C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X18C);
    // 0x80197F68: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80197F6C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80197F70: jal         0x8009BC2C
    // 0x80197F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80197F74: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80197F78: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197F7C: lwc1        $f6, -0x4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4);
    // 0x80197F80: lw          $a1, 0x190($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X190);
    // 0x80197F84: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80197F88: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80197F8C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80197F90: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80197F94: jal         0x8009BC2C
    // 0x80197F98: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80197F98: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80197F9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197FA0: lwc1        $f8, 0x0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X0);
    // 0x80197FA4: lw          $a1, 0x194($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X194);
    // 0x80197FA8: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80197FAC: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80197FB0: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80197FB4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80197FB8: jal         0x8009BC2C
    // 0x80197FBC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80197FBC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80197FC0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197FC4: lwc1        $f10, 0x4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4);
    // 0x80197FC8: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x80197FCC: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80197FD0: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80197FD4: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80197FD8: addiu       $a0, $s0, 0xFC
    ctx->r4 = ADD32(ctx->r16, 0XFC);
    // 0x80197FDC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80197FE0: jal         0x8009BC2C
    // 0x80197FE4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80197FE4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x80197FE8: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
    // 0x80197FEC: beql        $t6, $zero, L_80198120
    if (ctx->r14 == 0) {
        // 0x80197FF0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80198120;
    }
    goto skip_0;
    // 0x80197FF0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_0:
    // 0x80197FF4: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x80197FF8: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80197FFC: lw          $t7, 0x7A80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7A80);
    // 0x80198000: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x80198004: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80198008: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8019800C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80198010: addiu       $t1, $t0, 0x320
    ctx->r9 = ADD32(ctx->r8, 0X320);
    // 0x80198014: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80198018: beq         $at, $zero, L_8019811C
    if (ctx->r1 == 0) {
        // 0x8019801C: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8019811C;
    }
    // 0x8019801C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80198020: b           L_8019811C
    // 0x80198024: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
        goto L_8019811C;
    // 0x80198024: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
L_80198028:
    // 0x80198028: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8019802C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80198030: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80198034: sh          $t3, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r11;
    // 0x80198038: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8019803C: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80198040: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80198044: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80198048: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019804C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80198050: jal         0x80019218
    // 0x80198054: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x80198054: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80198058: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019805C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198060: nop

    // 0x80198064: swc1        $f16, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f16.u32l;
L_80198068:
    // 0x80198068: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019806C: lwc1        $f0, 0x8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X8);
    // 0x80198070: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80198074: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198078: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019807C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80198080: sw          $t5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r13;
    // 0x80198084: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80198088: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019808C: lwc1        $f8, 0xF4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80198090: lwc1        $f18, 0x168($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X168);
    // 0x80198094: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x80198098: lwc1        $f10, 0xC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XC);
    // 0x8019809C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801980A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801980A4: swc1        $f16, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f16.u32l;
    // 0x801980A8: lwc1        $f4, 0x10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X10);
    // 0x801980AC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801980B0: swc1        $f6, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f6.u32l;
    // 0x801980B4: lwc1        $f8, 0x168($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X168);
    // 0x801980B8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801980BC: nop

    // 0x801980C0: bc1fl       L_80198120
    if (!c1cs) {
        // 0x801980C4: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80198120;
    }
    goto skip_1;
    // 0x801980C4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_1:
    // 0x801980C8: b           L_8019811C
    // 0x801980CC: swc1        $f0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f0.u32l;
        goto L_8019811C;
    // 0x801980CC: swc1        $f0, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f0.u32l;
L_801980D0:
    // 0x801980D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801980D4: lwc1        $f10, 0x14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X14);
    // 0x801980D8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801980DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801980E0: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x801980E4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801980E8: jal         0x8009BC2C
    // 0x801980EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x801980EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x801980F0: lwc1        $f0, 0x118($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X118);
    // 0x801980F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801980F8: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801980FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80198100: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80198104: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80198108: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8019810C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x80198110: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80198114: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80198118: swc1        $f10, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f10.u32l;
L_8019811C:
    // 0x8019811C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80198120:
    // 0x80198120: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198124: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80198128: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019812C: lwc1        $f6, 0x18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X18);
    // 0x80198130: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80198134: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198138: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019813C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80198140: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80198144: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80198148: jal         0x80005E90
    // 0x8019814C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8019814C: nop

    after_6:
    // 0x80198150: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198154: lwc1        $f16, 0x1C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1C);
    // 0x80198158: lwc1        $f10, 0xF4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x8019815C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198160: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80198164: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80198168: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019816C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80198170: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80198174: jal         0x80005D44
    // 0x80198178: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x80198178: nop

    after_7:
    // 0x8019817C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80198180: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80198184: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80198188: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8019818C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x80198190: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80198194: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80198198: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x8019819C: jal         0x80006A20
    // 0x801981A0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x801981A0: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x801981A4: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801981A8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801981AC: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x801981B0: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    // 0x801981B4: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801981B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801981BC: lwc1        $f18, 0xF4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801981C0: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x801981C4: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801981C8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801981CC: swc1        $f16, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f16.u32l;
    // 0x801981D0: lwc1        $f16, 0xFC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x801981D4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801981D8: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x801981DC: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x801981E0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x801981E4: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x801981E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801981EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801981F0: jr          $ra
    // 0x801981F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801981F4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Bolse_8018D4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D4F0: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8018D4F4: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8018D4F8: addiu       $v0, $v0, 0x488
    ctx->r2 = ADD32(ctx->r2, 0X488);
    // 0x8018D4FC: addiu       $v1, $v1, 0x3E0
    ctx->r3 = ADD32(ctx->r3, 0X3E0);
    // 0x8018D500: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
L_8018D504:
    // 0x8018D504: beq         $t6, $zero, L_8018D518
    if (ctx->r14 == 0) {
        // 0x8018D508: nop
    
            goto L_8018D518;
    }
    // 0x8018D508: nop

    // 0x8018D50C: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8018D510: bnel        $v1, $v0, L_8018D504
    if (ctx->r3 != ctx->r2) {
        // 0x8018D514: lw          $t6, 0x18($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X18);
            goto L_8018D504;
    }
    goto skip_0;
    // 0x8018D514: lw          $t6, 0x18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X18);
    skip_0:
L_8018D518:
    // 0x8018D518: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x8018D51C: addiu       $t7, $t7, 0x488
    ctx->r15 = ADD32(ctx->r15, 0X488);
    // 0x8018D520: sltu        $at, $v1, $t7
    ctx->r1 = ctx->r3 < ctx->r15 ? 1 : 0;
    // 0x8018D524: bnel        $at, $zero, L_8018D538
    if (ctx->r1 != 0) {
        // 0x8018D528: lwc1        $f4, 0x4($a0)
        ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
            goto L_8018D538;
    }
    goto skip_1;
    // 0x8018D528: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x8018D52C: jr          $ra
    // 0x8018D530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8018D530: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D534: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
L_8018D538:
    // 0x8018D538: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018D53C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018D540: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8018D544: lwc1        $f8, -0x67C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X67C);
    // 0x8018D548: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8018D54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D550: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018D554: swc1        $f10, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8018D558: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8018D55C: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x8018D560: lwc1        $f18, 0x13C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X13C);
    // 0x8018D564: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
    // 0x8018D568: lwc1        $f4, 0x140($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X140);
    // 0x8018D56C: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
    // 0x8018D570: lwc1        $f6, 0x144($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X144);
    // 0x8018D574: sw          $t8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r24;
    // 0x8018D578: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
    // 0x8018D57C: jr          $ra
    // 0x8018D580: nop

    return;
    // 0x8018D580: nop

;}
RECOMP_FUNC void Katina_SFTeamMissionAccomUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196E30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80196E34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80196E38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80196E3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80196E40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80196E44: jal         0x800613C4
    // 0x80196E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80196E48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80196E4C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80196E50: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x80196E54: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80196E58: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80196E5C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80196E60: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80196E64: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x80196E68: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80196E6C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196E70: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80196E74: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196E78: lwc1        $f6, -0xD9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XD9C);
    // 0x80196E7C: lwc1        $f4, 0x74($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X74);
    // 0x80196E80: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196E84: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196E88: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80196E8C: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80196E90: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80196E94: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80196E98: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80196E9C: lwc1        $f16, -0xD90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XD90);
    // 0x80196EA0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196EA4: lwc1        $f10, 0x78($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X78);
    // 0x80196EA8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196EAC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80196EB0: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x80196EB4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80196EB8: lwc1        $f6, -0xD84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XD84);
    // 0x80196EBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196EC0: lwc1        $f4, 0x7C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X7C);
    // 0x80196EC4: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196EC8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80196ECC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80196ED0: lwc1        $f10, -0xD78($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XD78);
    // 0x80196ED4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196ED8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196EDC: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x80196EE0: lwc1        $f16, -0xD6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XD6C);
    // 0x80196EE4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80196EE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80196EEC: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
    // 0x80196EF0: jal         0x800612B8
    // 0x80196EF4: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80196EF4: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x80196EF8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80196EFC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80196F00: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80196F04: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80196F08: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x80196F0C: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80196F10: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80196F14: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80196F18: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80196F1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80196F20: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80196F24: jal         0x80019218
    // 0x80196F28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80196F28: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80196F2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80196F30: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80196F34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80196F38: jr          $ra
    // 0x80196F3C: nop

    return;
    // 0x80196F3C: nop

;}
RECOMP_FUNC void Katina_KaSaucerer_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801968F4: addiu       $sp, $sp, -0x1D8
    ctx->r29 = ADD32(ctx->r29, -0X1D8);
    // 0x801968F8: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801968FC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80196900: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80196904: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80196908: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019690C: lh          $v0, 0x4E($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4E);
    // 0x80196910: beq         $v0, $zero, L_80196E18
    if (ctx->r2 == 0) {
        // 0x80196914: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80196E18;
    }
    // 0x80196914: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80196918: beq         $at, $zero, L_801969E0
    if (ctx->r1 == 0) {
        // 0x8019691C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_801969E0;
    }
    // 0x8019691C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80196920: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80196924: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80196928: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019692C: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x80196930: ori         $t7, $t7, 0x8
    ctx->r15 = ctx->r15 | 0X8;
    // 0x80196934: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80196938: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019693C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80196940: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80196944: lw          $v1, -0x7C28($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7C28);
    // 0x80196948: addiu       $t8, $zero, 0x3EA
    ctx->r24 = ADD32(0, 0X3EA);
    // 0x8019694C: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80196950: subu        $a1, $t8, $v1
    ctx->r5 = SUB32(ctx->r24, ctx->r3);
    // 0x80196954: ori         $t9, $t9, 0xF400
    ctx->r25 = ctx->r25 | 0XF400;
    // 0x80196958: div         $zero, $t9, $a1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r5)));
    // 0x8019695C: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x80196960: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x80196964: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x80196968: mflo        $t1
    ctx->r9 = lo;
    // 0x8019696C: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x80196970: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80196974: div         $zero, $t6, $a1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r5)));
    // 0x80196978: mflo        $t7
    ctx->r15 = lo;
    // 0x8019697C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80196980: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80196984: bne         $a1, $zero, L_80196990
    if (ctx->r5 != 0) {
        // 0x80196988: nop
    
            goto L_80196990;
    }
    // 0x80196988: nop

    // 0x8019698C: break       7
    do_break(2149149068);
L_80196990:
    // 0x80196990: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80196994: bne         $a1, $at, L_801969A8
    if (ctx->r5 != ctx->r1) {
        // 0x80196998: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801969A8;
    }
    // 0x80196998: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019699C: bne         $t9, $at, L_801969A8
    if (ctx->r25 != ctx->r1) {
        // 0x801969A0: nop
    
            goto L_801969A8;
    }
    // 0x801969A0: nop

    // 0x801969A4: break       6
    do_break(2149149092);
L_801969A8:
    // 0x801969A8: addu        $at, $t9, $zero
    ctx->r1 = ADD32(ctx->r25, 0);
    // 0x801969AC: or          $t9, $t3, $t8
    ctx->r25 = ctx->r11 | ctx->r24;
    // 0x801969B0: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x801969B4: bne         $a1, $zero, L_801969C0
    if (ctx->r5 != 0) {
        // 0x801969B8: nop
    
            goto L_801969C0;
    }
    // 0x801969B8: nop

    // 0x801969BC: break       7
    do_break(2149149116);
L_801969C0:
    // 0x801969C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801969C4: bne         $a1, $at, L_801969D8
    if (ctx->r5 != ctx->r1) {
        // 0x801969C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_801969D8;
    }
    // 0x801969C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801969CC: bne         $t6, $at, L_801969D8
    if (ctx->r14 != ctx->r1) {
        // 0x801969D0: nop
    
            goto L_801969D8;
    }
    // 0x801969D0: nop

    // 0x801969D4: break       6
    do_break(2149149140);
L_801969D8:
    // 0x801969D8: b           L_80196A94
    // 0x801969DC: nop

        goto L_80196A94;
    // 0x801969DC: nop

L_801969E0:
    // 0x801969E0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801969E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801969E8: lui         $t2, 0xBC00
    ctx->r10 = S32(0XBC00 << 16);
    // 0x801969EC: ori         $t2, $t2, 0x8
    ctx->r10 = ctx->r10 | 0X8;
    // 0x801969F0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801969F4: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x801969F8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801969FC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80196A00: lw          $v1, -0x7C28($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7C28);
    // 0x80196A04: addiu       $t4, $zero, 0x3EE
    ctx->r12 = ADD32(0, 0X3EE);
    // 0x80196A08: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x80196A0C: subu        $a1, $t4, $v1
    ctx->r5 = SUB32(ctx->r12, ctx->r3);
    // 0x80196A10: ori         $t5, $t5, 0xF400
    ctx->r13 = ctx->r13 | 0XF400;
    // 0x80196A14: div         $zero, $t5, $a1
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r5)));
    // 0x80196A18: negu        $t8, $v1
    ctx->r24 = SUB32(0, ctx->r3);
    // 0x80196A1C: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x80196A20: addu        $t1, $t9, $t5
    ctx->r9 = ADD32(ctx->r25, ctx->r13);
    // 0x80196A24: mflo        $t6
    ctx->r14 = lo;
    // 0x80196A28: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80196A2C: sll         $t3, $t7, 16
    ctx->r11 = S32(ctx->r15 << 16);
    // 0x80196A30: div         $zero, $t1, $a1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r5)));
    // 0x80196A34: mflo        $t2
    ctx->r10 = lo;
    // 0x80196A38: andi        $t4, $t2, 0xFFFF
    ctx->r12 = ctx->r10 & 0XFFFF;
    // 0x80196A3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80196A40: bne         $a1, $zero, L_80196A4C
    if (ctx->r5 != 0) {
        // 0x80196A44: nop
    
            goto L_80196A4C;
    }
    // 0x80196A44: nop

    // 0x80196A48: break       7
    do_break(2149149256);
L_80196A4C:
    // 0x80196A4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80196A50: bne         $a1, $at, L_80196A64
    if (ctx->r5 != ctx->r1) {
        // 0x80196A54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80196A64;
    }
    // 0x80196A54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80196A58: bne         $t5, $at, L_80196A64
    if (ctx->r13 != ctx->r1) {
        // 0x80196A5C: nop
    
            goto L_80196A64;
    }
    // 0x80196A5C: nop

    // 0x80196A60: break       6
    do_break(2149149280);
L_80196A64:
    // 0x80196A64: addu        $at, $t5, $zero
    ctx->r1 = ADD32(ctx->r13, 0);
    // 0x80196A68: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80196A6C: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80196A70: bne         $a1, $zero, L_80196A7C
    if (ctx->r5 != 0) {
        // 0x80196A74: nop
    
            goto L_80196A7C;
    }
    // 0x80196A74: nop

    // 0x80196A78: break       7
    do_break(2149149304);
L_80196A7C:
    // 0x80196A7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80196A80: bne         $a1, $at, L_80196A94
    if (ctx->r5 != ctx->r1) {
        // 0x80196A84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80196A94;
    }
    // 0x80196A84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80196A88: bne         $t1, $at, L_80196A94
    if (ctx->r9 != ctx->r1) {
        // 0x80196A8C: nop
    
            goto L_80196A94;
    }
    // 0x80196A8C: nop

    // 0x80196A90: break       6
    do_break(2149149328);
L_80196A94:
    // 0x80196A94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196A98: lwc1        $f6, -0x60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X60);
    // 0x80196A9C: lwc1        $f4, 0x10C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10C);
    // 0x80196AA0: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80196AA4: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80196AA8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80196AAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196AB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80196AB4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80196AB8: jal         0x80005E90
    // 0x80196ABC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80196ABC: nop

    after_0:
    // 0x80196AC0: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80196AC4: addiu       $a0, $a0, 0x5D8
    ctx->r4 = ADD32(ctx->r4, 0X5D8);
    // 0x80196AC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80196ACC: jal         0x8009AA20
    // 0x80196AD0: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    Animation_GetFrameData(rdram, ctx);
        goto after_1;
    // 0x80196AD0: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_1:
    // 0x80196AD4: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80196AD8: addiu       $t6, $t6, 0x4660
    ctx->r14 = ADD32(ctx->r14, 0X4660);
    // 0x80196ADC: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x80196AE0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80196AE4: addiu       $a3, $a3, 0x65A8
    ctx->r7 = ADD32(ctx->r7, 0X65A8);
    // 0x80196AE8: addiu       $a1, $a1, 0x744
    ctx->r5 = ADD32(ctx->r5, 0X744);
    // 0x80196AEC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80196AF0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80196AF4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x80196AF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80196AFC: jal         0x8009A72C
    // 0x80196B00: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x80196B00: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_2:
    // 0x80196B04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196B08: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80196B0C: ori         $t8, $t8, 0x8
    ctx->r24 = ctx->r24 | 0X8;
    // 0x80196B10: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80196B14: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80196B18: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80196B1C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80196B20: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80196B24: lw          $t9, -0x7C24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7C24);
    // 0x80196B28: lw          $v1, -0x7C28($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7C28);
    // 0x80196B2C: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x80196B30: ori         $t1, $t1, 0xF400
    ctx->r9 = ctx->r9 | 0XF400;
    // 0x80196B34: subu        $a1, $t9, $v1
    ctx->r5 = SUB32(ctx->r25, ctx->r3);
    // 0x80196B38: div         $zero, $t1, $a1
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r5)));
    // 0x80196B3C: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x80196B40: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x80196B44: addu        $t7, $t6, $t1
    ctx->r15 = ADD32(ctx->r14, ctx->r9);
    // 0x80196B48: mflo        $t2
    ctx->r10 = lo;
    // 0x80196B4C: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x80196B50: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80196B54: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x80196B58: mflo        $t8
    ctx->r24 = lo;
    // 0x80196B5C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80196B60: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80196B64: bne         $a1, $zero, L_80196B70
    if (ctx->r5 != 0) {
        // 0x80196B68: nop
    
            goto L_80196B70;
    }
    // 0x80196B68: nop

    // 0x80196B6C: break       7
    do_break(2149149548);
L_80196B70:
    // 0x80196B70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80196B74: bne         $a1, $at, L_80196B88
    if (ctx->r5 != ctx->r1) {
        // 0x80196B78: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80196B88;
    }
    // 0x80196B78: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80196B7C: bne         $t1, $at, L_80196B88
    if (ctx->r9 != ctx->r1) {
        // 0x80196B80: nop
    
            goto L_80196B88;
    }
    // 0x80196B80: nop

    // 0x80196B84: break       6
    do_break(2149149572);
L_80196B88:
    // 0x80196B88: addu        $at, $t1, $zero
    ctx->r1 = ADD32(ctx->r9, 0);
    // 0x80196B8C: or          $t1, $t4, $t9
    ctx->r9 = ctx->r12 | ctx->r25;
    // 0x80196B90: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x80196B94: bne         $a1, $zero, L_80196BA0
    if (ctx->r5 != 0) {
        // 0x80196B98: nop
    
            goto L_80196BA0;
    }
    // 0x80196B98: nop

    // 0x80196B9C: break       7
    do_break(2149149596);
L_80196BA0:
    // 0x80196BA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80196BA4: bne         $a1, $at, L_80196BB8
    if (ctx->r5 != ctx->r1) {
        // 0x80196BA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80196BB8;
    }
    // 0x80196BA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80196BAC: bne         $t7, $at, L_80196BB8
    if (ctx->r15 != ctx->r1) {
        // 0x80196BB0: nop
    
            goto L_80196BB8;
    }
    // 0x80196BB0: nop

    // 0x80196BB4: break       6
    do_break(2149149620);
L_80196BB8:
    // 0x80196BB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80196BBC: lwc1        $f16, 0x110($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X110);
    // 0x80196BC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80196BC4: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80196BC8: nop

    // 0x80196BCC: bc1fl       L_80196D7C
    if (!c1cs) {
        // 0x80196BD0: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80196D7C;
    }
    goto skip_0;
    // 0x80196BD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x80196BD4: jal         0x800B8DD0
    // 0x80196BD8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80196BD8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_3:
    // 0x80196BDC: jal         0x80005708
    // 0x80196BE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x80196BE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80196BE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80196BE8: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80196BEC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196BF0: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80196BF4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80196BF8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80196BFC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80196C00: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80196C04: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80196C08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196C0C: lui         $t8, 0xFF
    ctx->r24 = S32(0XFF << 16);
    // 0x80196C10: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80196C14: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80196C18: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80196C1C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80196C20: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80196C24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80196C28: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80196C2C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80196C30: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80196C34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196C38: jal         0x80005B00
    // 0x80196C3C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x80196C3C: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    after_5:
    // 0x80196C40: lwc1        $f0, 0x110($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X110);
    // 0x80196C44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80196C48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80196C4C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80196C50: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80196C54: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80196C58: jal         0x80005C34
    // 0x80196C5C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x80196C5C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_6:
    // 0x80196C60: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x80196C64: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80196C68: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196C6C: jal         0x80005D44
    // 0x80196C70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x80196C70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x80196C74: jal         0x80006EB8
    // 0x80196C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x80196C78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80196C7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196C80: lui         $a1, 0x102
    ctx->r5 = S32(0X102 << 16);
    // 0x80196C84: addiu       $a1, $a1, 0x4AC0
    ctx->r5 = ADD32(ctx->r5, 0X4AC0);
    // 0x80196C88: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80196C8C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80196C90: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80196C94: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80196C98: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80196C9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80196CA0: jal         0x80005740
    // 0x80196CA4: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x80196CA4: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_9:
    // 0x80196CA8: jal         0x80005708
    // 0x80196CAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_10;
    // 0x80196CAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80196CB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196CB4: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80196CB8: addiu       $t6, $zero, -0xC0
    ctx->r14 = ADD32(0, -0XC0);
    // 0x80196CBC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80196CC0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80196CC4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80196CC8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80196CCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196CD0: lui         $t4, 0xFF
    ctx->r12 = S32(0XFF << 16);
    // 0x80196CD4: ori         $t4, $t4, 0xFF40
    ctx->r12 = ctx->r12 | 0XFF40;
    // 0x80196CD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80196CDC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80196CE0: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80196CE4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80196CE8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80196CEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80196CF0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80196CF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196CF8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80196CFC: lui         $a2, 0x43FA
    ctx->r6 = S32(0X43FA << 16);
    // 0x80196D00: jal         0x80005B00
    // 0x80196D04: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_11;
    // 0x80196D04: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_11:
    // 0x80196D08: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80196D0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80196D10: lwc1        $f18, 0x110($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X110);
    // 0x80196D14: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80196D18: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80196D1C: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80196D20: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196D24: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80196D28: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80196D2C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80196D30: jal         0x80005C34
    // 0x80196D34: nop

    Matrix_Scale(rdram, ctx);
        goto after_12;
    // 0x80196D34: nop

    after_12:
    // 0x80196D38: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x80196D3C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80196D40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196D44: jal         0x80005D44
    // 0x80196D48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x80196D48: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80196D4C: jal         0x80006EB8
    // 0x80196D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x80196D50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x80196D54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196D58: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x80196D5C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80196D60: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80196D64: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80196D68: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80196D6C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80196D70: jal         0x80005740
    // 0x80196D74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x80196D74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x80196D78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80196D7C:
    // 0x80196D7C: lwc1        $f8, 0x114($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X114);
    // 0x80196D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80196D84: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80196D88: nop

    // 0x80196D8C: bc1fl       L_80196E1C
    if (!c1cs) {
        // 0x80196D90: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80196E1C;
    }
    goto skip_1;
    // 0x80196D90: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x80196D94: jal         0x800B8DD0
    // 0x80196D98: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_16;
    // 0x80196D98: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_16:
    // 0x80196D9C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196DA0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80196DA4: addiu       $t8, $zero, -0x80
    ctx->r24 = ADD32(0, -0X80);
    // 0x80196DA8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80196DAC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80196DB0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80196DB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80196DB8: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x80196DBC: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x80196DC0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196DC4: jal         0x80005D44
    // 0x80196DC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x80196DC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80196DCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196DD0: lwc1        $f0, -0x5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5C);
    // 0x80196DD4: lw          $a2, 0x114($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X114);
    // 0x80196DD8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80196DDC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80196DE0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80196DE4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80196DE8: jal         0x80005C34
    // 0x80196DEC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_18;
    // 0x80196DEC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_18:
    // 0x80196DF0: jal         0x80006EB8
    // 0x80196DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x80196DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80196DF8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80196DFC: lui         $t2, 0x601
    ctx->r10 = S32(0X601 << 16);
    // 0x80196E00: addiu       $t2, $t2, -0x4050
    ctx->r10 = ADD32(ctx->r10, -0X4050);
    // 0x80196E04: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80196E08: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80196E0C: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80196E10: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80196E14: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
L_80196E18:
    // 0x80196E18: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80196E1C:
    // 0x80196E1C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80196E20: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80196E24: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80196E28: jr          $ra
    // 0x80196E2C: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
    return;
    // 0x80196E2C: addiu       $sp, $sp, 0x1D8
    ctx->r29 = ADD32(ctx->r29, 0X1D8);
;}
RECOMP_FUNC void Bolse_BoBaseCore_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191AFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80191B00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80191B04: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80191B08: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80191B0C: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x80191B10: addiu       $a0, $a0, 0x1C64
    ctx->r4 = ADD32(ctx->r4, 0X1C64);
    // 0x80191B14: addiu       $a2, $a2, 0x1A0
    ctx->r6 = ADD32(ctx->r6, 0X1A0);
    // 0x80191B18: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80191B1C: jal         0x8009AA20
    // 0x80191B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x80191B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80191B24: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80191B28: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80191B2C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80191B30: lh          $t6, 0x4E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4E);
    // 0x80191B34: addiu       $a1, $a1, 0x1FB0
    ctx->r5 = ADD32(ctx->r5, 0X1FB0);
    // 0x80191B38: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80191B3C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80191B40: bne         $at, $zero, L_80191B84
    if (ctx->r1 != 0) {
        // 0x80191B44: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80191B84;
    }
    // 0x80191B44: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80191B48: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80191B4C: lw          $t8, -0x4438($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4438);
    // 0x80191B50: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80191B54: addiu       $t7, $t7, 0x1A6C
    ctx->r15 = ADD32(ctx->r15, 0X1A6C);
    // 0x80191B58: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80191B5C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80191B60: addiu       $a3, $a3, 0x18E4
    ctx->r7 = ADD32(ctx->r7, 0X18E4);
    // 0x80191B64: addiu       $a1, $a1, 0x1FB0
    ctx->r5 = ADD32(ctx->r5, 0X1FB0);
    // 0x80191B68: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80191B6C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80191B70: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80191B74: jal         0x8009A72C
    // 0x80191B78: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x80191B78: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x80191B7C: b           L_80191BA0
    // 0x80191B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80191BA0;
    // 0x80191B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80191B84:
    // 0x80191B84: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80191B88: lw          $t9, -0x4438($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4438);
    // 0x80191B8C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80191B90: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80191B94: jal         0x8009A72C
    // 0x80191B98: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x80191B98: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_2:
    // 0x80191B9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80191BA0:
    // 0x80191BA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80191BA4: jr          $ra
    // 0x80191BA8: nop

    return;
    // 0x80191BA8: nop

;}
RECOMP_FUNC void Katina_SFTeamFleeUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196F40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80196F44: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80196F48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80196F4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80196F50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80196F54: jal         0x800613C4
    // 0x80196F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80196F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80196F5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80196F60: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x80196F64: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80196F68: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80196F6C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80196F70: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196F74: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x80196F78: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80196F7C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196F80: lwc1        $f4, -0xD60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XD60);
    // 0x80196F84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196F88: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196F8C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80196F90: lwc1        $f6, -0xD50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XD50);
    // 0x80196F94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196F98: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196F9C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80196FA0: lwc1        $f8, -0xD40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XD40);
    // 0x80196FA4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196FA8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196FAC: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80196FB0: lwc1        $f10, -0xD30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XD30);
    // 0x80196FB4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196FB8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80196FBC: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x80196FC0: lwc1        $f16, -0xD20($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XD20);
    // 0x80196FC4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80196FC8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80196FCC: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80196FD0: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
    // 0x80196FD4: jal         0x800612B8
    // 0x80196FD8: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80196FD8: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x80196FDC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80196FE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80196FE4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80196FE8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80196FEC: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x80196FF0: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80196FF4: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80196FF8: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80196FFC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80197000: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80197004: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80197008: jal         0x80019218
    // 0x8019700C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019700C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80197010: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80197014: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80197018: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019701C: jr          $ra
    // 0x80197020: nop

    return;
    // 0x80197020: nop

;}
RECOMP_FUNC void Bolse_BoLaserCannon_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D394: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D398: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D39C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018D3A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D3A4: jal         0x8018CC60
    // 0x8018D3A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_8018CC60(rdram, ctx);
        goto after_0;
    // 0x8018D3A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018D3AC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8018D3B0: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8018D3B4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8018D3B8: lw          $v1, 0x1C8($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X1C8);
    // 0x8018D3BC: beq         $v1, $zero, L_8018D3F4
    if (ctx->r3 == 0) {
        // 0x8018D3C0: nop
    
            goto L_8018D3F4;
    }
    // 0x8018D3C0: nop

    // 0x8018D3C4: beq         $v1, $at, L_8018D3F4
    if (ctx->r3 == ctx->r1) {
        // 0x8018D3C8: nop
    
            goto L_8018D3F4;
    }
    // 0x8018D3C8: nop

    // 0x8018D3CC: jal         0x8018CCE8
    // 0x8018D3D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_8018CCE8(rdram, ctx);
        goto after_1;
    // 0x8018D3D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8018D3D4: jal         0x8018CE5C
    // 0x8018D3D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_8018CE5C(rdram, ctx);
        goto after_2;
    // 0x8018D3D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8018D3DC: jal         0x8018D008
    // 0x8018D3E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_8018D008(rdram, ctx);
        goto after_3;
    // 0x8018D3E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D3E4: beq         $v0, $zero, L_8018D3F4
    if (ctx->r2 == 0) {
        // 0x8018D3E8: nop
    
            goto L_8018D3F4;
    }
    // 0x8018D3E8: nop

    // 0x8018D3EC: jal         0x8018D124
    // 0x8018D3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_8018D124(rdram, ctx);
        goto after_4;
    // 0x8018D3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8018D3F4:
    // 0x8018D3F4: jal         0x8018D278
    // 0x8018D3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Bolse_8018D278(rdram, ctx);
        goto after_5;
    // 0x8018D3F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8018D3FC: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x8018D400: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D404: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D40C: jr          $ra
    // 0x8018D410: nop

    return;
    // 0x8018D410: nop

;}
RECOMP_FUNC void Katina_FireSmokeEffectSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192B4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80192B50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80192B54: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80192B58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80192B5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80192B60: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80192B64: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80192B68: jal         0x80061474
    // 0x80192B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80192B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80192B70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80192B74: addiu       $t7, $zero, 0x153
    ctx->r15 = ADD32(0, 0X153);
    // 0x80192B78: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80192B7C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80192B80: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80192B84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80192B88: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80192B8C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80192B90: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80192B94: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80192B98: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80192B9C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80192BA0: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80192BA4: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80192BA8: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x80192BAC: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80192BB0: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80192BB4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80192BB8: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x80192BBC: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80192BC0: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    // 0x80192BC4: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x80192BC8: jal         0x80004EB0
    // 0x80192BCC: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80192BCC: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80192BD0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80192BD4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80192BD8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80192BDC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80192BE0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80192BE4: jal         0x800612B8
    // 0x80192BE8: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x80192BE8: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x80192BEC: addiu       $t9, $zero, 0xE6
    ctx->r25 = ADD32(0, 0XE6);
    // 0x80192BF0: sh          $t9, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r25;
    // 0x80192BF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80192BF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80192BFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80192C00: jr          $ra
    // 0x80192C04: nop

    return;
    // 0x80192C04: nop

;}
RECOMP_FUNC void Bolse_Effect397_Setup1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190D98: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80190D9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80190DA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80190DA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80190DA8: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80190DAC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80190DB0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80190DB4: jal         0x80061474
    // 0x80190DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80190DB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80190DBC: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80190DC0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80190DC4: addiu       $t7, $zero, 0x18D
    ctx->r15 = ADD32(0, 0X18D);
    // 0x80190DC8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80190DCC: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80190DD0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80190DD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80190DD8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190DDC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80190DE0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80190DE4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190DE8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190DEC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80190DF0: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80190DF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80190DF8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80190DFC: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80190E00: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80190E04: swc1        $f16, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f16.u32l;
    // 0x80190E08: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80190E0C: lwc1        $f18, -0x37C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X37C);
    // 0x80190E10: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190E14: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80190E18: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80190E1C: jal         0x80005E90
    // 0x80190E20: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80190E20: nop

    after_1:
    // 0x80190E24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80190E28: lwc1        $f6, -0x378($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X378);
    // 0x80190E2C: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80190E30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190E34: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190E38: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80190E3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80190E40: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80190E44: jal         0x80005D44
    // 0x80190E48: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x80190E48: nop

    after_2:
    // 0x80190E4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80190E50: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80190E54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190E58: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190E5C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190E60: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80190E64: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80190E68: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80190E6C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80190E70: jal         0x80006A20
    // 0x80190E74: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x80190E74: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80190E78: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80190E7C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80190E80: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80190E84: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    // 0x80190E88: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80190E8C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80190E90: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80190E94: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80190E98: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80190E9C: sh          $t8, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r24;
    // 0x80190EA0: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80190EA4: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80190EA8: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    // 0x80190EAC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80190EB0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80190EB4: ori         $a0, $a0, 0x13
    ctx->r4 = ctx->r4 | 0X13;
    // 0x80190EB8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x80190EBC: jal         0x80019218
    // 0x80190EC0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x80190EC0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x80190EC4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80190EC8: jal         0x800612B8
    // 0x80190ECC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x80190ECC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_5:
    // 0x80190ED0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80190ED4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80190ED8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80190EDC: jr          $ra
    // 0x80190EE0: nop

    return;
    // 0x80190EE0: nop

;}
RECOMP_FUNC void SectorZ_SzGreatFox_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E454: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8019E458: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8019E45C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8019E460: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8019E464: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8019E468: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8019E46C: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x8019E470: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8019E474: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8019E478: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8019E47C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8019E480: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8019E484: lb          $t6, 0x62($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X62);
    // 0x8019E488: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8019E48C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019E490: bne         $t6, $at, L_8019E4D8
    if (ctx->r14 != ctx->r1) {
        // 0x8019E494: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8019E4D8;
    }
    // 0x8019E494: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019E498: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8019E49C: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x8019E4A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019E4A4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8019E4A8: sb          $zero, 0x62($s2)
    MEM_B(0X62, ctx->r18) = 0;
    // 0x8019E4AC: sh          $t7, 0x50($s2)
    MEM_H(0X50, ctx->r18) = ctx->r15;
    // 0x8019E4B0: sh          $t8, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r24;
    // 0x8019E4B4: sh          $t9, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r25;
    // 0x8019E4B8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019E4BC: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x8019E4C0: ori         $a0, $a0, 0x404F
    ctx->r4 = ctx->r4 | 0X404F;
    // 0x8019E4C4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8019E4C8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019E4CC: addiu       $a1, $s2, 0x3FC
    ctx->r5 = ADD32(ctx->r18, 0X3FC);
    // 0x8019E4D0: jal         0x80019218
    // 0x8019E4D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019E4D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
L_8019E4D8:
    // 0x8019E4D8: lh          $v0, 0x50($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X50);
    // 0x8019E4DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019E4E0: bne         $v0, $at, L_8019E4F0
    if (ctx->r2 != ctx->r1) {
        // 0x8019E4E4: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8019E4F0;
    }
    // 0x8019E4E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E4E8: sb          $zero, 0x7B8C($at)
    MEM_B(0X7B8C, ctx->r1) = 0;
    // 0x8019E4EC: lh          $v0, 0x50($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X50);
L_8019E4F0:
    // 0x8019E4F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8019E4F4: bne         $v0, $at, L_8019E608
    if (ctx->r2 != ctx->r1) {
        // 0x8019E4F8: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_8019E608;
    }
    // 0x8019E4F8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8019E4FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019E500: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019E504: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019E508: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8019E50C: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8019E510: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8019E514: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019E518: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019E51C: addiu       $s1, $zero, 0x19
    ctx->r17 = ADD32(0, 0X19);
    // 0x8019E520: add.s       $f30, $f4, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019E524: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E528: swc1        $f16, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f16.u32l;
    // 0x8019E52C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019E530: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8019E534: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8019E538: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019E53C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8019E540: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019E544: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019E548: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019E54C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019E550: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8019E554: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
L_8019E558:
    // 0x8019E558: jal         0x80004EB0
    // 0x8019E55C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019E55C: nop

    after_1:
    // 0x8019E560: jal         0x80004EB0
    // 0x8019E564: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8019E564: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x8019E568: sub.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8019E56C: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8019E570: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8019E574: sub.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8019E578: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8019E57C: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    // 0x8019E580: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8019E584: add.s       $f12, $f10, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x8019E588: jal         0x800794CC
    // 0x8019E58C: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_3;
    // 0x8019E58C: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    after_3:
    // 0x8019E590: jal         0x80004EB0
    // 0x8019E594: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8019E594: nop

    after_4:
    // 0x8019E598: jal         0x80004EB0
    // 0x8019E59C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8019E59C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_5:
    // 0x8019E5A0: sub.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8019E5A4: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8019E5A8: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8019E5AC: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8019E5B0: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8019E5B4: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    // 0x8019E5B8: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x8019E5BC: add.s       $f12, $f8, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x8019E5C0: jal         0x80079618
    // 0x8019E5C4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    func_effect_80079618(rdram, ctx);
        goto after_6;
    // 0x8019E5C4: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    after_6:
    // 0x8019E5C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019E5CC: bne         $s0, $s1, L_8019E558
    if (ctx->r16 != ctx->r17) {
        // 0x8019E5D0: nop
    
            goto L_8019E558;
    }
    // 0x8019E5D0: nop

    // 0x8019E5D4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019E5D8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019E5DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E5E0: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8019E5E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019E5E8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8019E5EC: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    // 0x8019E5F0: lwc1        $f14, 0x98($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8019E5F4: lw          $a2, 0x94($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X94);
    // 0x8019E5F8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019E5FC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019E600: jal         0x8007BFFC
    // 0x8019E604: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_7;
    // 0x8019E604: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_7:
L_8019E608:
    // 0x8019E608: lh          $t2, 0x52($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X52);
    // 0x8019E60C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019E610: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019E614: beq         $t2, $zero, L_8019E6E4
    if (ctx->r10 == 0) {
        // 0x8019E618: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8019E6E4;
    }
    // 0x8019E618: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E61C: lwc1        $f30, 0x3A4($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X3A4);
    // 0x8019E620: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019E624: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8019E628: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019E62C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8019E630: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8019E634:
    // 0x8019E634: jal         0x80004EB0
    // 0x8019E638: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8019E638: nop

    after_8:
    // 0x8019E63C: mul.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8019E640: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8019E644: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x8019E648: jal         0x80004EB0
    // 0x8019E64C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x8019E64C: nop

    after_9:
    // 0x8019E650: jal         0x80004EB0
    // 0x8019E654: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8019E654: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_10:
    // 0x8019E658: jal         0x80004EB0
    // 0x8019E65C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x8019E65C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_11:
    // 0x8019E660: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x8019E664: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x8019E668: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x8019E66C: addiu       $t5, $t5, -0x9B4
    ctx->r13 = ADD32(ctx->r13, -0X9B4);
    // 0x8019E670: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8019E674: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8019E678: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019E67C: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8019E680: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019E684: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019E688: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8019E68C: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8019E690: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019E694: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8019E698: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x8019E69C: sub.s       $f16, $f22, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x8019E6A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019E6A4: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019E6A8: mul.s       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x8019E6AC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019E6B0: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8019E6B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019E6B8: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8019E6BC: mul.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8019E6C0: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8019E6C4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019E6C8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019E6CC: jal         0x80199BDC
    // 0x8019E6D0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    SectorZ_FireSmokeEffectSpawn(rdram, ctx);
        goto after_12;
    // 0x8019E6D0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x8019E6D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8019E6D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019E6DC: bne         $s1, $at, L_8019E634
    if (ctx->r17 != ctx->r1) {
        // 0x8019E6E0: nop
    
            goto L_8019E634;
    }
    // 0x8019E6E0: nop

L_8019E6E4:
    // 0x8019E6E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E6E8: lwc1        $f20, 0x3A8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X3A8);
    // 0x8019E6EC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019E6F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8019E6F4: lwc1        $f18, 0x7C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x8019E6F8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019E6FC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8019E700: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x8019E704: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8019E708: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8019E70C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E710: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8019E714: lwc1        $f30, 0x3AC($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X3AC);
    // 0x8019E718: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019E71C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019E720: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019E724: jal         0x80005E90
    // 0x8019E728: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x8019E728: nop

    after_13:
    // 0x8019E72C: lwc1        $f8, 0x78($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8019E730: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019E734: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E738: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8019E73C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8019E740: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019E744: jal         0x80005D44
    // 0x8019E748: nop

    Matrix_RotateX(rdram, ctx);
        goto after_14;
    // 0x8019E748: nop

    after_14:
    // 0x8019E74C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019E750: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019E754: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
    // 0x8019E758: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x8019E75C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8019E760: lwc1        $f6, 0xD8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XD8);
    // 0x8019E764: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8019E768: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019E76C: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8019E770: jal         0x80006A20
    // 0x8019E774: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_15;
    // 0x8019E774: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x8019E778: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8019E77C: lwc1        $f6, 0x7C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x8019E780: lwc1        $f18, 0x78($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X78);
    // 0x8019E784: swc1        $f8, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f8.u32l;
    // 0x8019E788: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8019E78C: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x8019E790: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019E794: swc1        $f10, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f10.u32l;
    // 0x8019E798: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8019E79C: lwc1        $f10, 0x80($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X80);
    // 0x8019E7A0: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8019E7A4: swc1        $f16, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f16.u32l;
    // 0x8019E7A8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8019E7AC: swc1        $f4, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f4.u32l;
    // 0x8019E7B0: swc1        $f8, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f8.u32l;
    // 0x8019E7B4: swc1        $f16, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f16.u32l;
    // 0x8019E7B8: lbu         $t6, 0x7B8C($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7B8C);
    // 0x8019E7BC: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8019E7C0: bnel        $t6, $zero, L_8019E960
    if (ctx->r14 != 0) {
        // 0x8019E7C4: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8019E960;
    }
    goto skip_0;
    // 0x8019E7C4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x8019E7C8: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8019E7CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019E7D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019E7D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019E7D8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8019E7DC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8019E7E0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019E7E4: jal         0x80005E90
    // 0x8019E7E8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_16;
    // 0x8019E7E8: nop

    after_16:
    // 0x8019E7EC: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8019E7F0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019E7F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E7F8: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8019E7FC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019E800: jal         0x80005D44
    // 0x8019E804: nop

    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x8019E804: nop

    after_17:
    // 0x8019E808: lwc1        $f18, 0x18($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8019E80C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019E810: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019E814: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8019E818: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019E81C: jal         0x80005FE0
    // 0x8019E820: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_18;
    // 0x8019E820: nop

    after_18:
    // 0x8019E824: jal         0x80004EB0
    // 0x8019E828: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x8019E828: nop

    after_19:
    // 0x8019E82C: mul.s       $f6, $f0, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8019E830: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x8019E834: addiu       $t0, $t0, -0x9B4
    ctx->r8 = ADD32(ctx->r8, -0X9B4);
    // 0x8019E838: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019E83C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8019E840: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8019E844: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8019E848: nop

    // 0x8019E84C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8019E850: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8019E854: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8019E858: jal         0x80006A20
    // 0x8019E85C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_20;
    // 0x8019E85C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_20:
    // 0x8019E860: jal         0x80004EB0
    // 0x8019E864: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x8019E864: nop

    after_21:
    // 0x8019E868: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8019E86C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8019E870: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8019E874: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8019E878: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8019E87C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8019E880: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E884: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019E888: lwc1        $f4, 0x3B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X3B0);
    // 0x8019E88C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019E890: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019E894: lwc1        $f16, 0x70($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X70);
    // 0x8019E898: lw          $a3, 0x6C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X6C);
    // 0x8019E89C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019E8A0: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019E8A4: lwc1        $f8, 0x3B4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X3B4);
    // 0x8019E8A8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019E8AC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8019E8B0: lwc1        $f18, 0x74($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X74);
    // 0x8019E8B4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8019E8B8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019E8BC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8019E8C0: jal         0x8007C484
    // 0x8019E8C4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_22;
    // 0x8019E8C4: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_22:
    // 0x8019E8C8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8019E8CC: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x8019E8D0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8019E8D4: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x8019E8D8: mfhi        $t2
    ctx->r10 = hi;
    // 0x8019E8DC: bnel        $t2, $zero, L_8019E960
    if (ctx->r10 != 0) {
        // 0x8019E8E0: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8019E960;
    }
    goto skip_1;
    // 0x8019E8E0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_1:
    // 0x8019E8E4: jal         0x80004EB0
    // 0x8019E8E8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x8019E8E8: nop

    after_23:
    // 0x8019E8EC: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8019E8F0: nop

    // 0x8019E8F4: bc1fl       L_8019E960
    if (!c1cs) {
        // 0x8019E8F8: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8019E960;
    }
    goto skip_2;
    // 0x8019E8F8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_2:
    // 0x8019E8FC: jal         0x80004EB0
    // 0x8019E900: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x8019E900: nop

    after_24:
    // 0x8019E904: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8019E908: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8019E90C: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8019E910: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8019E914: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019E918: lwc1        $f18, 0x70($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X70);
    // 0x8019E91C: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8019E920: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8019E924: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019E928: lw          $a3, 0x6C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X6C);
    // 0x8019E92C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8019E930: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8019E934: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8019E938: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019E93C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019E940: lwc1        $f4, 0x74($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X74);
    // 0x8019E944: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8019E948: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019E94C: add.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x8019E950: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8019E954: jal         0x80199BDC
    // 0x8019E958: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    SectorZ_FireSmokeEffectSpawn(rdram, ctx);
        goto after_25;
    // 0x8019E958: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x8019E95C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8019E960:
    // 0x8019E960: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8019E964: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8019E968: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8019E96C: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8019E970: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8019E974: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8019E978: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8019E97C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8019E980: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8019E984: jr          $ra
    // 0x8019E988: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8019E988: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void Fortuna_SetupStarWolfFlee(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187884: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80187888: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018788C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80187890: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80187894: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80187898: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018789C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x801878A0: lh          $t6, 0xCE($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XCE);
    // 0x801878A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801878A8: jal         0x800613C4
    // 0x801878AC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801878AC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    after_0:
    // 0x801878B0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801878B4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801878B8: sb          $t8, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r24;
    // 0x801878BC: sh          $t7, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r15;
    // 0x801878C0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801878C4: addiu       $t9, $zero, 0xC5
    ctx->r25 = ADD32(0, 0XC5);
    // 0x801878C8: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x801878CC: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801878D0: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801878D4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801878D8: addiu       $t2, $zero, 0x2710
    ctx->r10 = ADD32(0, 0X2710);
    // 0x801878DC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801878E0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801878E4: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x801878E8: sh          $t0, 0xE4($s0)
    MEM_H(0XE4, ctx->r16) = ctx->r8;
    // 0x801878EC: sb          $t1, 0xC9($s0)
    MEM_B(0XC9, ctx->r16) = ctx->r9;
    // 0x801878F0: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
    // 0x801878F4: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
    // 0x801878F8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x801878FC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80187900: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80187904: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80187908: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x8018790C: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x80187910: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80187914: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x80187918: jal         0x800612B8
    // 0x8018791C: swc1        $f16, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8018791C: swc1        $f16, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x80187920: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80187924: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80187928: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018792C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x80187930: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80187934: ori         $a0, $a0, 0x4005
    ctx->r4 = ctx->r4 | 0X4005;
    // 0x80187938: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8018793C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80187940: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80187944: jal         0x80019218
    // 0x80187948: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80187948: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x8018794C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80187950: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80187954: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80187958: jr          $ra
    // 0x8018795C: nop

    return;
    // 0x8018795C: nop

;}
RECOMP_FUNC void Bolse_CsBoSatellite_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EC1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018EC20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018EC24: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018EC28: jal         0x800613C4
    // 0x8018EC2C: addiu       $a0, $a0, -0x2C78
    ctx->r4 = ADD32(ctx->r4, -0X2C78);
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018EC2C: addiu       $a0, $a0, -0x2C78
    ctx->r4 = ADD32(ctx->r4, -0X2C78);
    after_0:
    // 0x8018EC30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018EC34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018EC38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EC3C: sb          $t6, -0x2C78($at)
    MEM_B(-0X2C78, ctx->r1) = ctx->r14;
    // 0x8018EC40: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018EC44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EC48: swc1        $f4, -0x2C74($at)
    MEM_W(-0X2C74, ctx->r1) = ctx->f4.u32l;
    // 0x8018EC4C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EC50: swc1        $f6, -0x2C70($at)
    MEM_W(-0X2C70, ctx->r1) = ctx->f6.u32l;
    // 0x8018EC54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018EC58: lwc1        $f8, -0x65C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X65C);
    // 0x8018EC5C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EC60: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x8018EC64: swc1        $f8, -0x2C6C($at)
    MEM_W(-0X2C6C, ctx->r1) = ctx->f8.u32l;
    // 0x8018EC68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EC6C: sh          $t7, -0x2BC2($at)
    MEM_H(-0X2BC2, ctx->r1) = ctx->r15;
    // 0x8018EC70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018EC74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018EC78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EC7C: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x8018EC80: swc1        $f10, -0x2B14($at)
    MEM_W(-0X2B14, ctx->r1) = ctx->f10.u32l;
    // 0x8018EC84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018EC88: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018EC8C: addiu       $a0, $a0, -0x2C5C
    ctx->r4 = ADD32(ctx->r4, -0X2C5C);
    // 0x8018EC90: jal         0x800612B8
    // 0x8018EC94: sh          $a1, -0x2C76($at)
    MEM_H(-0X2C76, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8018EC94: sh          $a1, -0x2C76($at)
    MEM_H(-0X2C76, ctx->r1) = ctx->r5;
    after_1:
    // 0x8018EC98: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018EC9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018ECA0: sb          $t8, -0x2C3C($at)
    MEM_B(-0X2C3C, ctx->r1) = ctx->r24;
    // 0x8018ECA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018ECA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018ECAC: jr          $ra
    // 0x8018ECB0: nop

    return;
    // 0x8018ECB0: nop

;}
RECOMP_FUNC void SectorZ_LoadLevelObjects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019EA68: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8019EA6C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8019EA70: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8019EA74: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x8019EA78: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8019EA7C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8019EA80: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8019EA84: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8019EA88: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8019EA8C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8019EA90: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019EA94: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8019EA98: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019EA9C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8019EAA0: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8019EAA4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8019EAA8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8019EAAC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019EAB0: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8019EAB4: lw          $v0, -0x260($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X260);
    // 0x8019EAB8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019EABC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8019EAC0: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8019EAC4: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x8019EAC8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8019EACC: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8019EAD0: lw          $t2, 0x1FD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1FD0);
    // 0x8019EAD4: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x8019EAD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019EADC: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x8019EAE0: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x8019EAE4: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8019EAE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8019EAEC: addiu       $a1, $zero, 0x7148
    ctx->r5 = ADD32(0, 0X7148);
    // 0x8019EAF0: jal         0x80004FC8
    // 0x8019EAF4: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    Rand_SetSeed(rdram, ctx);
        goto after_0;
    // 0x8019EAF4: addiu       $a2, $zero, 0x2694
    ctx->r6 = ADD32(0, 0X2694);
    after_0:
    // 0x8019EAF8: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8019EAFC: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x8019EB00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8019EB04: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x8019EB08: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
L_8019EB0C:
    // 0x8019EB0C: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x8019EB10: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x8019EB14: bgez        $v0, L_8019EB24
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8019EB18: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_8019EB24;
    }
    // 0x8019EB18: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x8019EB1C: b           L_8019EBD4
    // 0x8019EB20: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
        goto L_8019EBD4;
    // 0x8019EB20: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_8019EB24:
    // 0x8019EB24: beql        $at, $zero, L_8019EBC4
    if (ctx->r1 == 0) {
        // 0x8019EB28: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_8019EBC4;
    }
    goto skip_0;
    // 0x8019EB28: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_0:
    // 0x8019EB2C: jal         0x800A4F4C
    // 0x8019EB30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Initialize(rdram, ctx);
        goto after_1;
    // 0x8019EB30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019EB34: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x8019EB38: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8019EB3C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019EB40: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x8019EB44: lh          $t0, 0x10($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10);
    // 0x8019EB48: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x8019EB4C: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8019EB50: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8019EB54: addu        $t8, $t1, $s1
    ctx->r24 = ADD32(ctx->r9, ctx->r17);
    // 0x8019EB58: lh          $t2, 0x6($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X6);
    // 0x8019EB5C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8019EB60: nop

    // 0x8019EB64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019EB68: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x8019EB6C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8019EB70: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8019EB74: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x8019EB78: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8019EB7C: nop

    // 0x8019EB80: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019EB84: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8019EB88: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8019EB8C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8019EB90: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8019EB94: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8019EB98: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8019EB9C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8019EBA0: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x8019EBA4: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8019EBA8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8019EBAC: nop

    // 0x8019EBB0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019EBB4: jal         0x800612B8
    // 0x8019EBB8: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8019EBB8: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    after_2:
    // 0x8019EBBC: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x8019EBC0: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_8019EBC4:
    // 0x8019EBC4: slti        $at, $s1, 0x4E20
    ctx->r1 = SIGNED(ctx->r17) < 0X4E20 ? 1 : 0;
    // 0x8019EBC8: bnel        $at, $zero, L_8019EB0C
    if (ctx->r1 != 0) {
        // 0x8019EBCC: lw          $t5, 0x0($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X0);
            goto L_8019EB0C;
    }
    goto skip_1;
    // 0x8019EBCC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x8019EBD0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_8019EBD4:
    // 0x8019EBD4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8019EBD8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019EBDC: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8019EBE0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019EBE4: addiu       $s0, $s0, -0x2C78
    ctx->r16 = ADD32(ctx->r16, -0X2C78);
    // 0x8019EBE8: addiu       $s3, $zero, 0x32
    ctx->r19 = ADD32(0, 0X32);
    // 0x8019EBEC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8019EBF0: addiu       $s6, $zero, 0x4E20
    ctx->r22 = ADD32(0, 0X4E20);
    // 0x8019EBF4: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x8019EBF8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8019EBFC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_8019EC00:
    // 0x8019EC00: addu        $t2, $t8, $s1
    ctx->r10 = ADD32(ctx->r24, ctx->r17);
    // 0x8019EC04: lh          $v0, 0x10($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X10);
    // 0x8019EC08: bltz        $v0, L_8019ECD8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8019EC0C: slti        $at, $v0, 0xB0
        ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
            goto L_8019ECD8;
    }
    // 0x8019EC0C: slti        $at, $v0, 0xB0
    ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
    // 0x8019EC10: bne         $at, $zero, L_8019ECCC
    if (ctx->r1 != 0) {
        // 0x8019EC14: slti        $at, $v0, 0x124
        ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
            goto L_8019ECCC;
    }
    // 0x8019EC14: slti        $at, $v0, 0x124
    ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
    // 0x8019EC18: beql        $at, $zero, L_8019ECD0
    if (ctx->r1 == 0) {
        // 0x8019EC1C: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_8019ECD0;
    }
    goto skip_2;
    // 0x8019EC1C: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_2:
    // 0x8019EC20: jal         0x800613C4
    // 0x8019EC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_3;
    // 0x8019EC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8019EC28: sb          $s4, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r20;
    // 0x8019EC2C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8019EC30: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8019EC34: lh          $t5, 0x10($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X10);
    // 0x8019EC38: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x8019EC3C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8019EC40: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8019EC44: lh          $t9, 0x6($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X6);
    // 0x8019EC48: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8019EC4C: nop

    // 0x8019EC50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019EC54: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8019EC58: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8019EC5C: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x8019EC60: lh          $t8, 0x8($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X8);
    // 0x8019EC64: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8019EC68: nop

    // 0x8019EC6C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8019EC70: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x8019EC74: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8019EC78: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x8019EC7C: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8019EC80: sh          $s5, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r21;
    // 0x8019EC84: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8019EC88: jal         0x80004EB0
    // 0x8019EC8C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8019EC8C: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x8019EC90: sub.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8019EC94: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8019EC98: jal         0x80004EB0
    // 0x8019EC9C: swc1        $f10, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8019EC9C: swc1        $f10, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f10.u32l;
    after_5:
    // 0x8019ECA0: sub.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8019ECA4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019ECA8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8019ECAC: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8019ECB0: jal         0x800612B8
    // 0x8019ECB4: swc1        $f18, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x8019ECB4: swc1        $f18, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f18.u32l;
    after_6:
    // 0x8019ECB8: slti        $v0, $s3, 0x3C
    ctx->r2 = SIGNED(ctx->r19) < 0X3C ? 1 : 0;
    // 0x8019ECBC: sb          $s4, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r20;
    // 0x8019ECC0: beq         $v0, $zero, L_8019ECD8
    if (ctx->r2 == 0) {
        // 0x8019ECC4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8019ECD8;
    }
    // 0x8019ECC4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8019ECC8: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_8019ECCC:
    // 0x8019ECCC: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_8019ECD0:
    // 0x8019ECD0: bnel        $s1, $s6, L_8019EC00
    if (ctx->r17 != ctx->r22) {
        // 0x8019ECD4: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_8019EC00;
    }
    goto skip_3;
    // 0x8019ECD4: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_3:
L_8019ECD8:
    // 0x8019ECD8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019ECDC: jal         0x80061404
    // 0x8019ECE0: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    Boss_Initialize(rdram, ctx);
        goto after_7;
    // 0x8019ECE0: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    after_7:
    // 0x8019ECE4: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019ECE8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019ECEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019ECF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ECF4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019ECF8: sb          $t4, -0xEF0($at)
    MEM_B(-0XEF0, ctx->r1) = ctx->r12;
    // 0x8019ECFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED00: swc1        $f0, -0xEEC($at)
    MEM_W(-0XEEC, ctx->r1) = ctx->f0.u32l;
    // 0x8019ED04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED08: swc1        $f0, -0xEE8($at)
    MEM_W(-0XEE8, ctx->r1) = ctx->f0.u32l;
    // 0x8019ED0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED10: swc1        $f0, -0xEE4($at)
    MEM_W(-0XEE4, ctx->r1) = ctx->f0.u32l;
    // 0x8019ED14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED18: swc1        $f2, -0xE74($at)
    MEM_W(-0XE74, ctx->r1) = ctx->f2.u32l;
    // 0x8019ED1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED20: lwc1        $f4, -0xE78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XE78);
    // 0x8019ED24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED28: addiu       $a1, $zero, 0x139
    ctx->r5 = ADD32(0, 0X139);
    // 0x8019ED2C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8019ED30: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019ED34: swc1        $f6, -0xEE0($at)
    MEM_W(-0XEE0, ctx->r1) = ctx->f6.u32l;
    // 0x8019ED38: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019ED3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019ED40: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED44: addiu       $a0, $a0, -0xED4
    ctx->r4 = ADD32(ctx->r4, -0XED4);
    // 0x8019ED48: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8019ED4C: swc1        $f10, -0xEDC($at)
    MEM_W(-0XEDC, ctx->r1) = ctx->f10.u32l;
    // 0x8019ED50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED54: lwc1        $f16, -0xE70($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XE70);
    // 0x8019ED58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED5C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8019ED60: swc1        $f18, -0xED8($at)
    MEM_W(-0XED8, ctx->r1) = ctx->f18.u32l;
    // 0x8019ED64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019ED68: jal         0x800612B8
    // 0x8019ED6C: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_8;
    // 0x8019ED6C: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    after_8:
    // 0x8019ED70: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019ED74: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8019ED78: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019ED7C: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8019ED80: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x8019ED84: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019ED88: addiu       $a1, $a1, -0xAF4
    ctx->r5 = ADD32(ctx->r5, -0XAF4);
    // 0x8019ED8C: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x8019ED90: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019ED94: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019ED98: jal         0x80019218
    // 0x8019ED9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x8019ED9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8019EDA0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8019EDA4: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8019EDA8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8019EDAC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019EDB0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8019EDB4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8019EDB8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8019EDBC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8019EDC0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8019EDC4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8019EDC8: jr          $ra
    // 0x8019EDCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8019EDCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Katina_Hatch_Destroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193CE4: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80193CE8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80193CEC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80193CF0: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80193CF4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193CF8: lwc1        $f22, -0x1B4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X1B4);
    // 0x80193CFC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80193D00: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80193D04: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80193D08: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80193D0C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80193D10: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x80193D14: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x80193D18: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80193D1C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80193D20: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80193D24: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x80193D28: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x80193D2C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80193D30: addu        $s0, $s2, $t6
    ctx->r16 = ADD32(ctx->r18, ctx->r14);
    // 0x80193D34: lwc1        $f4, 0x1AC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1AC);
    // 0x80193D38: lwc1        $f10, 0x1B0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1B0);
    // 0x80193D3C: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80193D40: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80193D44: lwc1        $f4, 0x1B4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1B4);
    // 0x80193D48: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80193D4C: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80193D50: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80193D54: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80193D58: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80193D5C: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80193D60: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80193D64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80193D68: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80193D6C: jal         0x8007D2C8
    // 0x80193D70: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_0;
    // 0x80193D70: nop

    after_0:
    // 0x80193D74: sll         $t8, $s3, 1
    ctx->r24 = S32(ctx->r19 << 1);
    // 0x80193D78: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x80193D7C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80193D80: sh          $t7, 0x92($t9)
    MEM_H(0X92, ctx->r25) = ctx->r15;
    // 0x80193D84: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193D88: lwc1        $f30, -0x1B0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X1B0);
    // 0x80193D8C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80193D90: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80193D94: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80193D98: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80193D9C: addiu       $s3, $zero, 0x14
    ctx->r19 = ADD32(0, 0X14);
    // 0x80193DA0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80193DA4:
    // 0x80193DA4: jal         0x80004EB0
    // 0x80193DA8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80193DA8: nop

    after_1:
    // 0x80193DAC: jal         0x80004EB0
    // 0x80193DB0: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80193DB0: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    after_2:
    // 0x80193DB4: jal         0x80004EB0
    // 0x80193DB8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80193DB8: mov.s       $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    ctx->f28.fl = ctx->f0.fl;
    after_3:
    // 0x80193DBC: sub.s       $f18, $f26, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x80193DC0: lwc1        $f8, 0x1AC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1AC);
    // 0x80193DC4: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80193DC8: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80193DCC: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80193DD0: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80193DD4: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80193DD8: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80193DDC: sub.s       $f16, $f28, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f28.fl - ctx->f20.fl;
    // 0x80193DE0: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80193DE4: mul.s       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x80193DE8: lwc1        $f10, 0x1B0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1B0);
    // 0x80193DEC: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80193DF0: mul.s       $f6, $f10, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80193DF4: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80193DF8: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80193DFC: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80193E00: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80193E04: lwc1        $f6, 0x1B4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1B4);
    // 0x80193E08: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80193E0C: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80193E10: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80193E14: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80193E18: jal         0x800794CC
    // 0x80193E1C: nop

    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_4;
    // 0x80193E1C: nop

    after_4:
    // 0x80193E20: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80193E24: bne         $s1, $s3, L_80193DA4
    if (ctx->r17 != ctx->r19) {
        // 0x80193E28: nop
    
            goto L_80193DA4;
    }
    // 0x80193E28: nop

    // 0x80193E2C: lwc1        $f16, 0x1AC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1AC);
    // 0x80193E30: lwc1        $f6, 0x4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X4);
    // 0x80193E34: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x80193E38: mul.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x80193E3C: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x80193E40: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80193E44: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80193E48: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x80193E4C: lwc1        $f10, 0x1B0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1B0);
    // 0x80193E50: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80193E54: mul.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x80193E58: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80193E5C: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x80193E60: lwc1        $f6, 0x1B4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1B4);
    // 0x80193E64: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80193E68: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80193E6C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80193E70: jal         0x8007A6F0
    // 0x80193E74: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_5;
    // 0x80193E74: swc1        $f18, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80193E78: lh          $t0, 0xA6($s2)
    ctx->r8 = MEM_H(ctx->r18, 0XA6);
    // 0x80193E7C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80193E80: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80193E84: sh          $t1, 0xA6($s2)
    MEM_H(0XA6, ctx->r18) = ctx->r9;
    // 0x80193E88: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80193E8C: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80193E90: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80193E94: jal         0x80077240
    // 0x80193E98: sub.s       $f14, $f16, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f24.fl;
    BonusText_Display(rdram, ctx);
        goto after_6;
    // 0x80193E98: sub.s       $f14, $f16, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f24.fl;
    after_6:
    // 0x80193E9C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80193EA0: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x80193EA4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80193EA8: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80193EAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193EB0: addiu       $t3, $t2, 0x6
    ctx->r11 = ADD32(ctx->r10, 0X6);
    // 0x80193EB4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80193EB8: sw          $t4, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r12;
    // 0x80193EBC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80193EC0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80193EC4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80193EC8: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80193ECC: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80193ED0: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x80193ED4: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x80193ED8: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80193EDC: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80193EE0: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80193EE4: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x80193EE8: jr          $ra
    // 0x80193EEC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80193EEC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Bolse_8018D278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D278: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D27C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D280: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018D284: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D288: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018D28C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018D290: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018D294: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x8018D298: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018D29C: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x8018D2A0: bnel        $t6, $zero, L_8018D2B4
    if (ctx->r14 != 0) {
        // 0x8018D2A4: lwc1        $f4, 0x8($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
            goto L_8018D2B4;
    }
    goto skip_0;
    // 0x8018D2A4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x8018D2A8: b           L_8018D378
    // 0x8018D2AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018D378;
    // 0x8018D2AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D2B0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
L_8018D2B4:
    // 0x8018D2B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D2B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018D2BC: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8018D2C0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D2C4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8018D2C8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D2CC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8018D2D0: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8018D2D4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D2D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018D2DC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018D2E0: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8018D2E4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8018D2E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8018D2EC: jal         0x8007BFFC
    // 0x8018D2F0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_0;
    // 0x8018D2F0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8018D2F4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018D2F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D2FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D300: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8018D304:
    // 0x8018D304: jal         0x80004EB0
    // 0x8018D308: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018D308: nop

    after_1:
    // 0x8018D30C: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x8018D310: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8018D314: bc1fl       L_8018D330
    if (!c1cs) {
        // 0x8018D318: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D330;
    }
    goto skip_1;
    // 0x8018D318: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_1:
    // 0x8018D31C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D320: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D324: jal         0x800A69F8
    // 0x8018D328: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    Play_SpawnDebris(rdram, ctx);
        goto after_2;
    // 0x8018D328: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    after_2:
    // 0x8018D32C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D330:
    // 0x8018D330: bne         $s1, $s2, L_8018D304
    if (ctx->r17 != ctx->r18) {
        // 0x8018D334: nop
    
            goto L_8018D304;
    }
    // 0x8018D334: nop

    // 0x8018D338: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8018D33C: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x8018D340: jal         0x8007A6F0
    // 0x8018D344: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_3;
    // 0x8018D344: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
    // 0x8018D348: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018D34C: sb          $t8, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r24;
    // 0x8018D350: jal         0x80066254
    // 0x8018D354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_4;
    // 0x8018D354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8018D358: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D35C: jal         0x80060FBC
    // 0x8018D360: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8018D360: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_5:
    // 0x8018D364: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018D368: sb          $zero, 0x3C($s0)
    MEM_B(0X3C, ctx->r16) = 0;
    // 0x8018D36C: sb          $zero, 0xCA($s0)
    MEM_B(0XCA, ctx->r16) = 0;
    // 0x8018D370: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018D374: swc1        $f16, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f16.u32l;
L_8018D378:
    // 0x8018D378: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D37C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018D380: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D384: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018D388: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018D38C: jr          $ra
    // 0x8018D390: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8018D390: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Katina_LevelStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192E20: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80192E24: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80192E28: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80192E2C: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80192E30: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80192E34: addiu       $s0, $s0, -0x6D8
    ctx->r16 = ADD32(ctx->r16, -0X6D8);
    // 0x80192E38: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80192E3C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x80192E40: lw          $v0, 0x1D0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1D0);
    // 0x80192E44: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80192E48: beql        $v0, $zero, L_80192E60
    if (ctx->r2 == 0) {
        // 0x80192E4C: sltiu       $at, $v0, 0xE
        ctx->r1 = ctx->r2 < 0XE ? 1 : 0;
            goto L_80192E60;
    }
    goto skip_0;
    // 0x80192E4C: sltiu       $at, $v0, 0xE
    ctx->r1 = ctx->r2 < 0XE ? 1 : 0;
    skip_0:
    // 0x80192E50: jal         0x801981F8
    // 0x80192E54: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    Katina_801981F8(rdram, ctx);
        goto after_0;
    // 0x80192E54: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    after_0:
    // 0x80192E58: lw          $v0, 0x1D0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X1D0);
    // 0x80192E5C: sltiu       $at, $v0, 0xE
    ctx->r1 = ctx->r2 < 0XE ? 1 : 0;
L_80192E60:
    // 0x80192E60: beq         $at, $zero, L_801931F4
    if (ctx->r1 == 0) {
        // 0x80192E64: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_801931F4;
    }
    // 0x80192E64: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80192E68: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192E6C: addu        $at, $at, $t6
    gpr jr_addend_80192E74 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80192E70: lw          $t6, -0x2D0($at)
    ctx->r14 = ADD32(ctx->r1, -0X2D0);
    // 0x80192E74: jr          $t6
    // 0x80192E78: nop

    switch (jr_addend_80192E74 >> 2) {
        case 0: goto L_80192E7C; break;
        case 1: goto L_801931F4; break;
        case 2: goto L_801931F4; break;
        case 3: goto L_801931F4; break;
        case 4: goto L_801931F4; break;
        case 5: goto L_801931F4; break;
        case 6: goto L_801931F4; break;
        case 7: goto L_801931F4; break;
        case 8: goto L_801931F4; break;
        case 9: goto L_801931F4; break;
        case 10: goto L_801931F4; break;
        case 11: goto L_80192EF8; break;
        case 12: goto L_80192F88; break;
        case 13: goto L_801930F8; break;
        default: switch_error(__func__, 0x80192E74, 0x8019FD30);
    }
    // 0x80192E78: nop

L_80192E7C:
    // 0x80192E7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192E80: jal         0x80192C8C
    // 0x80192E84: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    Katina_StartCutsceneUpdate(rdram, ctx);
        goto after_1;
    // 0x80192E84: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    after_1:
    // 0x80192E88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192E8C: lwc1        $f0, -0x298($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X298);
    // 0x80192E90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192E94: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80192E98: swc1        $f0, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f0.u32l;
    // 0x80192E9C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80192EA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80192EA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192EA8: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x80192EAC: swc1        $f4, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f4.u32l;
    // 0x80192EB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192EB4: swc1        $f0, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f0.u32l;
    // 0x80192EB8: lwc1        $f6, 0xBD4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XBD4);
    // 0x80192EBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192EC0: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80192EC4: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x80192EC8: lwc1        $f8, 0xBD8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XBD8);
    // 0x80192ECC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192ED0: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x80192ED4: lwc1        $f10, 0xBDC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XBDC);
    // 0x80192ED8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192EDC: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
    // 0x80192EE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192EE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80192EE8: sw          $t7, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r15;
    // 0x80192EEC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192EF0: b           L_801931F4
    // 0x80192EF4: swc1        $f16, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f16.u32l;
        goto L_801931F4;
    // 0x80192EF4: swc1        $f16, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f16.u32l;
L_80192EF8:
    // 0x80192EF8: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80192EFC: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x80192F00: lwc1        $f18, 0xBD4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XBD4);
    // 0x80192F04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192F08: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80192F0C: swc1        $f18, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f18.u32l;
    // 0x80192F10: lwc1        $f4, 0xBD8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XBD8);
    // 0x80192F14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192F18: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80192F1C: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x80192F20: lwc1        $f6, 0xBDC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XBDC);
    // 0x80192F24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192F28: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x80192F2C: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
    // 0x80192F30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192F34: lwc1        $f10, -0x294($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X294);
    // 0x80192F38: lwc1        $f8, 0xBE8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XBE8);
    // 0x80192F3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192F40: lwc1        $f18, 0xEDC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XEDC);
    // 0x80192F44: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80192F48: lwc1        $f8, 0x11D0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X11D0);
    // 0x80192F4C: swc1        $f16, 0xBE8($s0)
    MEM_W(0XBE8, ctx->r16) = ctx->f16.u32l;
    // 0x80192F50: lwc1        $f4, -0x290($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X290);
    // 0x80192F54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192F58: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80192F5C: swc1        $f6, 0xEDC($s0)
    MEM_W(0XEDC, ctx->r16) = ctx->f6.u32l;
    // 0x80192F60: lwc1        $f10, -0x28C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X28C);
    // 0x80192F64: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80192F68: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80192F6C: swc1        $f16, 0x11D0($s0)
    MEM_W(0X11D0, ctx->r16) = ctx->f16.u32l;
    // 0x80192F70: lw          $t8, 0x7A80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A80);
    // 0x80192F74: bne         $t8, $at, L_801931F4
    if (ctx->r24 != ctx->r1) {
        // 0x80192F78: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_801931F4;
    }
    // 0x80192F78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192F7C: sw          $t9, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = ctx->r25;
    // 0x80192F80: b           L_801931F4
    // 0x80192F84: sw          $t0, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r8;
        goto L_801931F4;
    // 0x80192F84: sw          $t0, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r8;
L_80192F88:
    // 0x80192F88: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80192F8C: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x80192F90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192F94: lwc1        $f4, -0x288($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X288);
    // 0x80192F98: lwc1        $f18, 0xCBC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XCBC);
    // 0x80192F9C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80192FA0: lwc1        $f8, 0xCC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XCC0);
    // 0x80192FA4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80192FA8: lwc1        $f18, 0xBE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XBE8);
    // 0x80192FAC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80192FB0: swc1        $f6, 0xCBC($s0)
    MEM_W(0XCBC, ctx->r16) = ctx->f6.u32l;
    // 0x80192FB4: lwc1        $f10, -0x284($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X284);
    // 0x80192FB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192FBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80192FC0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80192FC4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80192FC8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80192FCC: swc1        $f16, 0xCC0($s0)
    MEM_W(0XCC0, ctx->r16) = ctx->f16.u32l;
    // 0x80192FD0: swc1        $f6, 0xBE8($s0)
    MEM_W(0XBE8, ctx->r16) = ctx->f6.u32l;
    // 0x80192FD4: lw          $t1, 0x7A80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7A80);
    // 0x80192FD8: bne         $t1, $at, L_801931F4
    if (ctx->r9 != ctx->r1) {
        // 0x80192FDC: nop
    
            goto L_801931F4;
    }
    // 0x80192FDC: nop

    // 0x80192FE0: jal         0x8002F180
    // 0x80192FE4: nop

    ActorAllRange_SpawnTeam(rdram, ctx);
        goto after_2;
    // 0x80192FE4: nop

    after_2:
    // 0x80192FE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80192FEC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80192FF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80192FF4: addiu       $t2, $zero, 0xD
    ctx->r10 = ADD32(0, 0XD);
    // 0x80192FF8: sw          $t2, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r10;
    // 0x80192FFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193000: swc1        $f8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f8.u32l;
    // 0x80193004: lwc1        $f10, -0x280($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X280);
    // 0x80193008: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019300C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80193010: swc1        $f10, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f10.u32l;
    // 0x80193014: lwc1        $f16, -0x27C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X27C);
    // 0x80193018: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x8019301C: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80193020: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x80193024: addiu       $a3, $a3, -0xE64
    ctx->r7 = ADD32(ctx->r7, -0XE64);
    // 0x80193028: addiu       $a0, $a0, -0xE70
    ctx->r4 = ADD32(ctx->r4, -0XE70);
    // 0x8019302C: addiu       $v1, $v1, -0xE8C
    ctx->r3 = ADD32(ctx->r3, -0XE8C);
    // 0x80193030: addiu       $v0, $v0, 0x42D4
    ctx->r2 = ADD32(ctx->r2, 0X42D4);
    // 0x80193034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80193038: addiu       $a2, $zero, 0x3E8
    ctx->r6 = ADD32(0, 0X3E8);
    // 0x8019303C: swc1        $f0, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f0.u32l;
    // 0x80193040: swc1        $f16, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f16.u32l;
    // 0x80193044: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80193048: lwc1        $f16, -0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8019304C: beq         $a0, $a3, L_801930AC
    if (ctx->r4 == ctx->r7) {
        // 0x80193050: lwc1        $f18, 0x74($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0X74);
            goto L_801930AC;
    }
    // 0x80193050: lwc1        $f18, 0x74($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80193054: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_80193058:
    // 0x80193058: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8019305C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80193060: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x80193064: swc1        $f14, -0x2F0($v0)
    MEM_W(-0X2F0, ctx->r2) = ctx->f14.u32l;
    // 0x80193068: lwc1        $f14, -0x14($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, -0X14);
    // 0x8019306C: lwc1        $f12, 0x78($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X78);
    // 0x80193070: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80193074: swc1        $f12, -0x2EC($v0)
    MEM_W(-0X2EC, ctx->r2) = ctx->f12.u32l;
    // 0x80193078: lwc1        $f12, -0x10($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8019307C: lwc1        $f14, 0x7C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80193080: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80193084: swc1        $f14, -0x2E8($v0)
    MEM_W(-0X2E8, ctx->r2) = ctx->f14.u32l;
    // 0x80193088: lwc1        $f14, -0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0XC);
    // 0x8019308C: swc1        $f0, -0x200($v0)
    MEM_W(-0X200, ctx->r2) = ctx->f0.u32l;
    // 0x80193090: sh          $a1, -0x23C($v0)
    MEM_H(-0X23C, ctx->r2) = ctx->r5;
    // 0x80193094: swc1        $f14, -0x1FC($v0)
    MEM_W(-0X1FC, ctx->r2) = ctx->f14.u32l;
    // 0x80193098: sh          $a2, -0x238($v0)
    MEM_H(-0X238, ctx->r2) = ctx->r6;
    // 0x8019309C: lwc1        $f16, -0xC($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, -0XC);
    // 0x801930A0: lwc1        $f18, 0x74($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801930A4: bnel        $a0, $a3, L_80193058
    if (ctx->r4 != ctx->r7) {
        // 0x801930A8: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80193058;
    }
    goto skip_1;
    // 0x801930A8: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
L_801930AC:
    // 0x801930AC: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801930B0: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x801930B4: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x801930B8: swc1        $f14, -0x2F0($v0)
    MEM_W(-0X2F0, ctx->r2) = ctx->f14.u32l;
    // 0x801930BC: lwc1        $f12, 0x78($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X78);
    // 0x801930C0: lwc1        $f14, -0x14($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, -0X14);
    // 0x801930C4: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x801930C8: swc1        $f12, -0x2EC($v0)
    MEM_W(-0X2EC, ctx->r2) = ctx->f12.u32l;
    // 0x801930CC: lwc1        $f14, 0x7C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x801930D0: lwc1        $f12, -0x10($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, -0X10);
    // 0x801930D4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x801930D8: swc1        $f14, -0x2E8($v0)
    MEM_W(-0X2E8, ctx->r2) = ctx->f14.u32l;
    // 0x801930DC: lwc1        $f14, -0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, -0X8);
    // 0x801930E0: swc1        $f0, -0x200($v0)
    MEM_W(-0X200, ctx->r2) = ctx->f0.u32l;
    // 0x801930E4: sh          $a1, -0x23C($v0)
    MEM_H(-0X23C, ctx->r2) = ctx->r5;
    // 0x801930E8: sh          $a2, -0x238($v0)
    MEM_H(-0X238, ctx->r2) = ctx->r6;
    // 0x801930EC: swc1        $f14, -0x1FC($v0)
    MEM_W(-0X1FC, ctx->r2) = ctx->f14.u32l;
    // 0x801930F0: b           L_801931F4
    // 0x801930F4: nop

        goto L_801931F4;
    // 0x801930F4: nop

L_801930F8:
    // 0x801930F8: lwc1        $f10, 0x74($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801930FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193100: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80193104: swc1        $f10, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f10.u32l;
    // 0x80193108: lwc1        $f16, 0x79A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x8019310C: lwc1        $f18, 0x78($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X78);
    // 0x80193110: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193114: swc1        $f16, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f16.u32l;
    // 0x80193118: swc1        $f18, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f18.u32l;
    // 0x8019311C: lwc1        $f4, 0x79B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x80193120: lwc1        $f6, 0x7C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80193124: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193128: swc1        $f4, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f4.u32l;
    // 0x8019312C: swc1        $f6, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f6.u32l;
    // 0x80193130: lwc1        $f8, 0x79C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x80193134: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80193138: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019313C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193140: swc1        $f8, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f8.u32l;
    // 0x80193144: swc1        $f10, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f10.u32l;
    // 0x80193148: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019314C: swc1        $f10, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f10.u32l;
    // 0x80193150: lwc1        $f16, -0x278($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X278);
    // 0x80193154: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193158: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019315C: swc1        $f16, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f16.u32l;
    // 0x80193160: swc1        $f16, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f16.u32l;
    // 0x80193164: lw          $t3, 0x7A80($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7A80);
    // 0x80193168: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8019316C: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x80193170: bne         $t3, $at, L_801931F4
    if (ctx->r11 != ctx->r1) {
        // 0x80193174: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801931F4;
    }
    // 0x80193174: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80193178: jal         0x80060FBC
    // 0x8019317C: addiu       $a1, $a1, 0x4CB0
    ctx->r5 = ADD32(ctx->r5, 0X4CB0);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8019317C: addiu       $a1, $a1, 0x4CB0
    ctx->r5 = ADD32(ctx->r5, 0X4CB0);
    after_3:
    // 0x80193180: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80193184: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80193188: addiu       $a1, $a1, 0x5298
    ctx->r5 = ADD32(ctx->r5, 0X5298);
    // 0x8019318C: jal         0x80060FBC
    // 0x80193190: addiu       $a0, $a0, 0x5198
    ctx->r4 = ADD32(ctx->r4, 0X5198);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x80193190: addiu       $a0, $a0, 0x5198
    ctx->r4 = ADD32(ctx->r4, 0X5198);
    after_4:
    // 0x80193194: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80193198: sw          $t4, 0x1C8($s1)
    MEM_W(0X1C8, ctx->r17) = ctx->r12;
    // 0x8019319C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801931A0: lwc1        $f18, -0x274($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X274);
    // 0x801931A4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801931A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801931AC: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x801931B0: lhu         $a1, 0x7C90($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7C90);
    // 0x801931B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801931B8: jal         0x8001D444
    // 0x801931BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_5;
    // 0x801931BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_5:
    // 0x801931C0: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x801931C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801931C8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801931CC: sw          $t5, 0x7838($at)
    MEM_W(0X7838, ctx->r1) = ctx->r13;
    // 0x801931D0: addiu       $v0, $v0, 0x42D4
    ctx->r2 = ADD32(ctx->r2, 0X42D4);
    // 0x801931D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801931D8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_801931DC:
    // 0x801931DC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801931E0: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x801931E4: bne         $a1, $v1, L_801931DC
    if (ctx->r5 != ctx->r3) {
        // 0x801931E8: sh          $zero, -0x238($v0)
        MEM_H(-0X238, ctx->r2) = 0;
            goto L_801931DC;
    }
    // 0x801931E8: sh          $zero, -0x238($v0)
    MEM_H(-0X238, ctx->r2) = 0;
    // 0x801931EC: addiu       $t6, $zero, -0x262
    ctx->r14 = ADD32(0, -0X262);
    // 0x801931F0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
L_801931F4:
    // 0x801931F4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801931F8: lw          $t7, 0x7A80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7A80);
    // 0x801931FC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80193200: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80193204: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80193208: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019320C: addiu       $t8, $t7, -0xA
    ctx->r24 = ADD32(ctx->r15, -0XA);
    // 0x80193210: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80193214: sltiu       $at, $t8, 0x26
    ctx->r1 = ctx->r24 < 0X26 ? 1 : 0;
    // 0x80193218: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8019321C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x80193220: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x80193224: beq         $at, $zero, L_80193518
    if (ctx->r1 == 0) {
        // 0x80193228: swc1        $f6, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
            goto L_80193518;
    }
    // 0x80193228: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8019322C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80193230: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193234: addu        $at, $at, $t8
    gpr jr_addend_8019323C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80193238: lw          $t8, -0x270($at)
    ctx->r24 = ADD32(ctx->r1, -0X270);
    // 0x8019323C: jr          $t8
    // 0x80193240: nop

    switch (jr_addend_8019323C >> 2) {
        case 0: goto L_8019325C; break;
        case 1: goto L_80193518; break;
        case 2: goto L_80193518; break;
        case 3: goto L_80193518; break;
        case 4: goto L_80193518; break;
        case 5: goto L_80193244; break;
        case 6: goto L_80193518; break;
        case 7: goto L_80193518; break;
        case 8: goto L_80193518; break;
        case 9: goto L_80193518; break;
        case 10: goto L_8019325C; break;
        case 11: goto L_80193518; break;
        case 12: goto L_80193518; break;
        case 13: goto L_80193518; break;
        case 14: goto L_80193518; break;
        case 15: goto L_8019325C; break;
        case 16: goto L_80193518; break;
        case 17: goto L_80193518; break;
        case 18: goto L_80193518; break;
        case 19: goto L_80193518; break;
        case 20: goto L_80193518; break;
        case 21: goto L_80193518; break;
        case 22: goto L_80193518; break;
        case 23: goto L_80193518; break;
        case 24: goto L_80193518; break;
        case 25: goto L_80193380; break;
        case 26: goto L_80193518; break;
        case 27: goto L_80193518; break;
        case 28: goto L_80193518; break;
        case 29: goto L_80193518; break;
        case 30: goto L_8019325C; break;
        case 31: goto L_80193380; break;
        case 32: goto L_80193518; break;
        case 33: goto L_80193518; break;
        case 34: goto L_80193380; break;
        case 35: goto L_801934A4; break;
        case 36: goto L_80193518; break;
        case 37: goto L_80193504; break;
        default: switch_error(__func__, 0x8019323C, 0x8019FD90);
    }
    // 0x80193240: nop

L_80193244:
    // 0x80193244: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80193248: addiu       $a0, $a0, 0x2210
    ctx->r4 = ADD32(ctx->r4, 0X2210);
    // 0x8019324C: jal         0x800BA808
    // 0x80193250: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x80193250: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_6:
    // 0x80193254: b           L_8019351C
    // 0x80193258: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
        goto L_8019351C;
    // 0x80193258: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
L_8019325C:
    // 0x8019325C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193260: lwc1        $f16, -0x1D8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1D8);
    // 0x80193264: lwc1        $f10, 0xED8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XED8);
    // 0x80193268: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019326C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80193270: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80193274: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80193278: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019327C: jal         0x80005E90
    // 0x80193280: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x80193280: nop

    after_7:
    // 0x80193284: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193288: lwc1        $f4, 0x4EB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4EB4);
    // 0x8019328C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193290: lwc1        $f6, -0x1D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1D4);
    // 0x80193294: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80193298: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019329C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801932A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801932A4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801932A8: jal         0x80005D44
    // 0x801932AC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x801932AC: nop

    after_8:
    // 0x801932B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801932B4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801932B8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x801932BC: jal         0x80006A20
    // 0x801932C0: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_9;
    // 0x801932C0: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_9:
    // 0x801932C4: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801932C8: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801932CC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801932D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801932D4: cvt.d.s     $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.d = CVT_D_S(ctx->f2.fl);
    // 0x801932D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801932DC: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x801932E0: lwc1        $f10, 0x4EA8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4EA8);
    // 0x801932E4: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801932E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801932EC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x801932F0: lwc1        $f10, 0x4EAC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4EAC);
    // 0x801932F4: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801932F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801932FC: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80193300: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x80193304: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80193308: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x8019330C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80193310: mul.d       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x80193314: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80193318: lwc1        $f10, 0x4EB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4EB0);
    // 0x8019331C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193320: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80193324: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80193328: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x8019332C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80193330: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x80193334: lwc1        $f10, 0x4EB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4EB4);
    // 0x80193338: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019333C: cvt.d.s     $f18, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f18.d = CVT_D_S(ctx->f14.fl);
    // 0x80193340: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80193344: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80193348: lwc1        $f18, 0x4EB8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4EB8);
    // 0x8019334C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193350: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80193354: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80193358: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x8019335C: add.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f16.d + ctx->f4.d;
    // 0x80193360: lwc1        $f16, 0x4EBC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4EBC);
    // 0x80193364: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80193368: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8019336C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80193370: jal         0x8006EEFC
    // 0x80193374: nop

    Actor_SpawnPlayerLaser(rdram, ctx);
        goto after_10;
    // 0x80193374: nop

    after_10:
    // 0x80193378: b           L_8019351C
    // 0x8019337C: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
        goto L_8019351C;
    // 0x8019337C: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
L_80193380:
    // 0x80193380: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193384: lwc1        $f6, -0x1D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1D0);
    // 0x80193388: lwc1        $f4, 0x11CC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11CC);
    // 0x8019338C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80193390: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80193394: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80193398: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019339C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801933A0: jal         0x80005E90
    // 0x801933A4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x801933A4: nop

    after_11:
    // 0x801933A8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801933AC: lwc1        $f10, 0x51A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X51A8);
    // 0x801933B0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801933B4: lwc1        $f18, -0x1CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1CC);
    // 0x801933B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801933BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801933C0: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801933C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801933C8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801933CC: jal         0x80005D44
    // 0x801933D0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_12;
    // 0x801933D0: nop

    after_12:
    // 0x801933D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801933D8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801933DC: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x801933E0: jal         0x80006A20
    // 0x801933E4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_13;
    // 0x801933E4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_13:
    // 0x801933E8: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801933EC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x801933F0: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x801933F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801933F8: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x801933FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193400: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80193404: lwc1        $f4, 0x519C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X519C);
    // 0x80193408: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019340C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193410: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80193414: lwc1        $f4, 0x51A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51A0);
    // 0x80193418: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019341C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193420: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x80193424: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x80193428: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8019342C: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80193430: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80193434: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80193438: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8019343C: lwc1        $f4, 0x51A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51A4);
    // 0x80193440: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193444: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x80193448: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019344C: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x80193450: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80193454: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x80193458: lwc1        $f4, 0x51A8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51A8);
    // 0x8019345C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193460: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80193464: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x80193468: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8019346C: lwc1        $f8, 0x51AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X51AC);
    // 0x80193470: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80193474: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80193478: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8019347C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80193480: add.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f6.d + ctx->f10.d;
    // 0x80193484: lwc1        $f6, 0x51B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X51B0);
    // 0x80193488: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8019348C: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80193490: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80193494: jal         0x8006EEFC
    // 0x80193498: nop

    Actor_SpawnPlayerLaser(rdram, ctx);
        goto after_14;
    // 0x80193498: nop

    after_14:
    // 0x8019349C: b           L_8019351C
    // 0x801934A0: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
        goto L_8019351C;
    // 0x801934A0: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
L_801934A4:
    // 0x801934A4: lwc1        $f12, 0xEC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC8);
    // 0x801934A8: lwc1        $f14, 0xECC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XECC);
    // 0x801934AC: lw          $a2, 0xED0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XED0);
    // 0x801934B0: jal         0x8007D2C8
    // 0x801934B4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_15;
    // 0x801934B4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_15:
    // 0x801934B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801934BC: lwc1        $f12, 0xEC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC8);
L_801934C0:
    // 0x801934C0: lwc1        $f14, 0xECC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XECC);
    // 0x801934C4: lw          $a2, 0xED0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XED0);
    // 0x801934C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801934CC: jal         0x800794CC
    // 0x801934D0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_16;
    // 0x801934D0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_16:
    // 0x801934D4: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x801934D8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801934DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801934E0: bnel        $v0, $at, L_801934C0
    if (ctx->r2 != ctx->r1) {
        // 0x801934E4: lwc1        $f12, 0xEC8($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0XEC8);
            goto L_801934C0;
    }
    goto skip_2;
    // 0x801934E4: lwc1        $f12, 0xEC8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XEC8);
    skip_2:
    // 0x801934E8: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801934EC: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x801934F0: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x801934F4: jal         0x8007A6F0
    // 0x801934F8: addiu       $a0, $a0, 0x4EA8
    ctx->r4 = ADD32(ctx->r4, 0X4EA8);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_17;
    // 0x801934F8: addiu       $a0, $a0, 0x4EA8
    ctx->r4 = ADD32(ctx->r4, 0X4EA8);
    after_17:
    // 0x801934FC: b           L_8019351C
    // 0x80193500: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
        goto L_8019351C;
    // 0x80193500: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
L_80193504:
    // 0x80193504: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80193508: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019350C: addiu       $a1, $a1, 0x4FA4
    ctx->r5 = ADD32(ctx->r5, 0X4FA4);
    // 0x80193510: jal         0x80060FBC
    // 0x80193514: addiu       $a0, $a0, 0x4EA4
    ctx->r4 = ADD32(ctx->r4, 0X4EA4);
    Object_Kill(rdram, ctx);
        goto after_18;
    // 0x80193514: addiu       $a0, $a0, 0x4EA4
    ctx->r4 = ADD32(ctx->r4, 0X4EA4);
    after_18:
L_80193518:
    // 0x80193518: lwc1        $f10, 0xE8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XE8);
L_8019351C:
    // 0x8019351C: lwc1        $f18, 0x114($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X114);
    // 0x80193520: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80193524: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80193528: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019352C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193530: lwc1        $f6, -0x1C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1C8);
    // 0x80193534: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80193538: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8019353C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80193540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80193544: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80193548: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019354C: jal         0x80005E90
    // 0x80193550: nop

    Matrix_RotateY(rdram, ctx);
        goto after_19;
    // 0x80193550: nop

    after_19:
    // 0x80193554: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193558: lwc1        $f16, -0x1C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1C4);
    // 0x8019355C: lwc1        $f18, 0xE4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x80193560: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80193564: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80193568: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8019356C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80193570: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x80193574: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80193578: jal         0x80005D44
    // 0x8019357C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_20;
    // 0x8019357C: nop

    after_20:
    // 0x80193580: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80193584: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80193588: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019358C: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x80193590: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80193594: lwc1        $f18, 0xD0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XD0);
    // 0x80193598: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019359C: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x801935A0: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x801935A4: jal         0x80006A20
    // 0x801935A8: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_21;
    // 0x801935A8: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    after_21:
    // 0x801935AC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801935B0: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801935B4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801935B8: swc1        $f16, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->f16.u32l;
    // 0x801935BC: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801935C0: lwc1        $f10, 0xC0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x801935C4: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    // 0x801935C8: swc1        $f4, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f4.u32l;
    // 0x801935CC: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801935D0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801935D4: lwc1        $f10, 0xC8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x801935D8: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    // 0x801935DC: lwc1        $f4, 0xC4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x801935E0: lwc1        $f6, 0x7C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x801935E4: swc1        $f18, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f18.u32l;
    // 0x801935E8: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x801935EC: lwc1        $f4, 0xEC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x801935F0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801935F4: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801935F8: swc1        $f8, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f8.u32l;
    // 0x801935FC: lwc1        $f8, 0x12C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X12C);
    // 0x80193600: lwc1        $f10, 0x130($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X130);
    // 0x80193604: swc1        $f18, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f18.u32l;
    // 0x80193608: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8019360C: lwc1        $f16, 0x7C($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80193610: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80193614: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80193618: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019361C: swc1        $f16, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f16.u32l;
    // 0x80193620: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80193624: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    // 0x80193628: swc1        $f18, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f18.u32l;
    // 0x8019362C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80193630: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x80193634: jal         0x8009BC2C
    // 0x80193638: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x80193638: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_22:
    // 0x8019363C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80193640: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80193644: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80193648: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8019364C: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80193650: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80193654: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x80193658: addiu       $a0, $s1, 0x44
    ctx->r4 = ADD32(ctx->r17, 0X44);
    // 0x8019365C: jal         0x8009BC2C
    // 0x80193660: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x80193660: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_23:
    // 0x80193664: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80193668: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019366C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80193670: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x80193674: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x80193678: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019367C: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x80193680: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    // 0x80193684: jal         0x8009BC2C
    // 0x80193688: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x80193688: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_24:
    // 0x8019368C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80193690: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80193694: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80193698: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8019369C: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x801936A0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801936A4: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x801936A8: addiu       $a0, $s1, 0x4C
    ctx->r4 = ADD32(ctx->r17, 0X4C);
    // 0x801936AC: jal         0x8009BC2C
    // 0x801936B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_25;
    // 0x801936B0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_25:
    // 0x801936B4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801936B8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801936BC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801936C0: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x801936C4: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x801936C8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801936CC: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x801936D0: addiu       $a0, $s1, 0x50
    ctx->r4 = ADD32(ctx->r17, 0X50);
    // 0x801936D4: jal         0x8009BC2C
    // 0x801936D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_26;
    // 0x801936D8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_26:
    // 0x801936DC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801936E0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801936E4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801936E8: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x801936EC: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x801936F0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801936F4: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x801936F8: addiu       $a0, $s1, 0x54
    ctx->r4 = ADD32(ctx->r17, 0X54);
    // 0x801936FC: jal         0x8009BC2C
    // 0x80193700: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_27;
    // 0x80193700: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_27:
    // 0x80193704: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80193708: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8019370C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80193710: jr          $ra
    // 0x80193714: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80193714: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Katina_UpdateEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198594: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80198598: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019859C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801985A0: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x801985A4: addiu       $t7, $t7, -0xB6C
    ctx->r15 = ADD32(ctx->r15, -0XB6C);
    // 0x801985A8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801985AC: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x801985B0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801985B4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801985B8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801985BC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801985C0: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x801985C4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801985C8: lw          $at, 0x10($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X10);
    // 0x801985CC: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x801985D0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801985D4: sw          $at, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r1;
    // 0x801985D8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x801985DC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801985E0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x801985E4: lh          $v0, 0xB8($t1)
    ctx->r2 = MEM_H(ctx->r9, 0XB8);
    // 0x801985E8: beq         $v0, $zero, L_8019860C
    if (ctx->r2 == 0) {
        // 0x801985EC: nop
    
            goto L_8019860C;
    }
    // 0x801985EC: nop

    // 0x801985F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801985F4: beq         $v0, $at, L_801986EC
    if (ctx->r2 == ctx->r1) {
        // 0x801985F8: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_801986EC;
    }
    // 0x801985F8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801985FC: beq         $v0, $at, L_80198710
    if (ctx->r2 == ctx->r1) {
        // 0x80198600: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_80198710;
    }
    // 0x80198600: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80198604: b           L_80198738
    // 0x80198608: nop

        goto L_80198738;
    // 0x80198608: nop

L_8019860C:
    // 0x8019860C: lwc1        $f4, 0x2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2C);
    // 0x80198610: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80198614: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80198618: swc1        $f4, 0x1A44($at)
    MEM_W(0X1A44, ctx->r1) = ctx->f4.u32l;
    // 0x8019861C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198620: sw          $zero, 0x540($at)
    MEM_W(0X540, ctx->r1) = 0;
    // 0x80198624: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80198628: addiu       $v0, $v0, -0x6DF
    ctx->r2 = ADD32(ctx->r2, -0X6DF);
    // 0x8019862C: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80198630: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80198634: sb          $zero, -0x6E0($at)
    MEM_B(-0X6E0, ctx->r1) = 0;
    // 0x80198638: sh          $t3, 0xB8($t4)
    MEM_H(0XB8, ctx->r12) = ctx->r11;
    // 0x8019863C: lw          $t5, -0x6DC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6DC);
    // 0x80198640: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80198644: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80198648: beq         $t5, $zero, L_801986E4
    if (ctx->r13 == 0) {
        // 0x8019864C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801986E4;
    }
    // 0x8019864C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80198650: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80198654: lw          $t9, 0x1A9C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1A9C);
    // 0x80198658: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019865C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80198660: sw          $t9, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = ctx->r25;
    // 0x80198664: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80198668: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019866C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80198670: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80198674: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80198678: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x8019867C: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x80198680: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80198684: sh          $t8, 0x456($v0)
    MEM_H(0X456, ctx->r2) = ctx->r24;
    // 0x80198688: addiu       $a1, $a1, -0x6EC
    ctx->r5 = ADD32(ctx->r5, -0X6EC);
    // 0x8019868C: ori         $a0, $a0, 0x7025
    ctx->r4 = ctx->r4 | 0X7025;
    // 0x80198690: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80198694: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80198698: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019869C: swc1        $f0, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f0.u32l;
    // 0x801986A0: swc1        $f0, 0x414($v0)
    MEM_W(0X414, ctx->r2) = ctx->f0.u32l;
    // 0x801986A4: jal         0x80019218
    // 0x801986A8: swc1        $f6, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f6.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x801986A8: swc1        $f6, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f6.u32l;
    after_0:
    // 0x801986AC: addiu       $t7, $zero, 0x4E20
    ctx->r15 = ADD32(0, 0X4E20);
    // 0x801986B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801986B4: sw          $t7, -0x6D8($at)
    MEM_W(-0X6D8, ctx->r1) = ctx->r15;
    // 0x801986B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801986BC: addiu       $t0, $zero, 0x1680
    ctx->r8 = ADD32(0, 0X1680);
    // 0x801986C0: sh          $t0, -0xA40($at)
    MEM_H(-0XA40, ctx->r1) = ctx->r8;
    // 0x801986C4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801986C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801986CC: sb          $t1, -0x6E0($at)
    MEM_B(-0X6E0, ctx->r1) = ctx->r9;
    // 0x801986D0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801986D4: ori         $a1, $zero, 0x801D
    ctx->r5 = 0 | 0X801D;
    // 0x801986D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801986DC: jal         0x8001D444
    // 0x801986E0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_1;
    // 0x801986E0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
L_801986E4:
    // 0x801986E4: jal         0x8019848C
    // 0x801986E8: nop

    Katina_BillFighterInit(rdram, ctx);
        goto after_2;
    // 0x801986E8: nop

    after_2:
L_801986EC:
    // 0x801986EC: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x801986F0: addiu       $v0, $v0, 0x540
    ctx->r2 = ADD32(ctx->r2, 0X540);
    // 0x801986F4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x801986F8: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x801986FC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80198700: jal         0x801981F8
    // 0x80198704: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    Katina_801981F8(rdram, ctx);
        goto after_3;
    // 0x80198704: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_3:
    // 0x80198708: b           L_80198738
    // 0x8019870C: nop

        goto L_80198738;
    // 0x8019870C: nop

L_80198710:
    // 0x80198710: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80198714: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80198718: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8019871C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80198720: sh          $zero, 0x3DA($v0)
    MEM_H(0X3DA, ctx->r2) = 0;
    // 0x80198724: sh          $t4, 0x3AC($v0)
    MEM_H(0X3AC, ctx->r2) = ctx->r12;
    // 0x80198728: sh          $zero, 0x6CE($v0)
    MEM_H(0X6CE, ctx->r2) = 0;
    // 0x8019872C: sh          $t5, 0x6A0($v0)
    MEM_H(0X6A0, ctx->r2) = ctx->r13;
    // 0x80198730: sh          $zero, 0x9C2($v0)
    MEM_H(0X9C2, ctx->r2) = 0;
    // 0x80198734: sh          $t9, 0x994($v0)
    MEM_H(0X994, ctx->r2) = ctx->r25;
L_80198738:
    // 0x80198738: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019873C: lh          $a0, -0xA9A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XA9A);
    // 0x80198740: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80198744: slti        $at, $a0, 0xF
    ctx->r1 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x80198748: beql        $at, $zero, L_80198924
    if (ctx->r1 == 0) {
        // 0x8019874C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80198924;
    }
    goto skip_0;
    // 0x8019874C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80198750: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
    // 0x80198754: addiu       $at, $zero, -0x1F4
    ctx->r1 = ADD32(0, -0X1F4);
    // 0x80198758: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x8019875C: beq         $v1, $at, L_8019878C
    if (ctx->r3 == ctx->r1) {
        // 0x80198760: addiu       $at, $zero, -0x186
        ctx->r1 = ADD32(0, -0X186);
            goto L_8019878C;
    }
    // 0x80198760: addiu       $at, $zero, -0x186
    ctx->r1 = ADD32(0, -0X186);
    // 0x80198764: beq         $v1, $at, L_801987AC
    if (ctx->r3 == ctx->r1) {
        // 0x80198768: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801987AC;
    }
    // 0x80198768: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019876C: addiu       $at, $zero, -0xDC
    ctx->r1 = ADD32(0, -0XDC);
    // 0x80198770: beq         $v1, $at, L_801987CC
    if (ctx->r3 == ctx->r1) {
        // 0x80198774: addiu       $a1, $zero, 0xAA
        ctx->r5 = ADD32(0, 0XAA);
            goto L_801987CC;
    }
    // 0x80198774: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    // 0x80198778: addiu       $at, $zero, -0x1E
    ctx->r1 = ADD32(0, -0X1E);
    // 0x8019877C: beq         $v1, $at, L_801987EC
    if (ctx->r3 == ctx->r1) {
        // 0x80198780: addiu       $a1, $zero, 0x14
        ctx->r5 = ADD32(0, 0X14);
            goto L_801987EC;
    }
    // 0x80198780: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x80198784: b           L_8019880C
    // 0x80198788: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
        goto L_8019880C;
    // 0x80198788: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_8019878C:
    // 0x8019878C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80198790: jal         0x800BA808
    // 0x80198794: addiu       $a0, $a0, 0x225C
    ctx->r4 = ADD32(ctx->r4, 0X225C);
    Radio_PlayMessage(rdram, ctx);
        goto after_4;
    // 0x80198794: addiu       $a0, $a0, 0x225C
    ctx->r4 = ADD32(ctx->r4, 0X225C);
    after_4:
    // 0x80198798: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019879C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x801987A0: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
    // 0x801987A4: b           L_80198808
    // 0x801987A8: lh          $a0, -0xA9A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XA9A);
        goto L_80198808;
    // 0x801987A8: lh          $a0, -0xA9A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XA9A);
L_801987AC:
    // 0x801987AC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801987B0: jal         0x800BA808
    // 0x801987B4: addiu       $a0, $a0, 0x2284
    ctx->r4 = ADD32(ctx->r4, 0X2284);
    Radio_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x801987B4: addiu       $a0, $a0, 0x2284
    ctx->r4 = ADD32(ctx->r4, 0X2284);
    after_5:
    // 0x801987B8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801987BC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x801987C0: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
    // 0x801987C4: b           L_80198808
    // 0x801987C8: lh          $a0, -0xA9A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XA9A);
        goto L_80198808;
    // 0x801987C8: lh          $a0, -0xA9A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XA9A);
L_801987CC:
    // 0x801987CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801987D0: jal         0x800BA808
    // 0x801987D4: addiu       $a0, $a0, 0x22D8
    ctx->r4 = ADD32(ctx->r4, 0X22D8);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x801987D4: addiu       $a0, $a0, 0x22D8
    ctx->r4 = ADD32(ctx->r4, 0X22D8);
    after_6:
    // 0x801987D8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801987DC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x801987E0: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
    // 0x801987E4: b           L_80198808
    // 0x801987E8: lh          $a0, -0xA9A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XA9A);
        goto L_80198808;
    // 0x801987E8: lh          $a0, -0xA9A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XA9A);
L_801987EC:
    // 0x801987EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801987F0: jal         0x800BA808
    // 0x801987F4: addiu       $a0, $a0, 0x2314
    ctx->r4 = ADD32(ctx->r4, 0X2314);
    Radio_PlayMessage(rdram, ctx);
        goto after_7;
    // 0x801987F4: addiu       $a0, $a0, 0x2314
    ctx->r4 = ADD32(ctx->r4, 0X2314);
    after_7:
    // 0x801987F8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801987FC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80198800: lw          $v1, -0x6D8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6D8);
    // 0x80198804: lh          $a0, -0xA9A($a0)
    ctx->r4 = MEM_H(ctx->r4, -0XA9A);
L_80198808:
    // 0x80198808: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
L_8019880C:
    // 0x8019880C: bne         $a0, $at, L_80198854
    if (ctx->r4 != ctx->r1) {
        // 0x80198810: andi        $t8, $v1, 0xFF
        ctx->r24 = ctx->r3 & 0XFF;
            goto L_80198854;
    }
    // 0x80198810: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x80198814: bnel        $t8, $zero, L_80198924
    if (ctx->r24 != 0) {
        // 0x80198818: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80198924;
    }
    goto skip_1;
    // 0x80198818: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8019881C: jal         0x80004EB0
    // 0x80198820: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80198820: nop

    after_8:
    // 0x80198824: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80198828: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019882C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80198830: addiu       $a0, $a0, 0x26E0
    ctx->r4 = ADD32(ctx->r4, 0X26E0);
    // 0x80198834: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80198838: nop

    // 0x8019883C: bc1fl       L_80198924
    if (!c1cs) {
        // 0x80198840: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80198924;
    }
    goto skip_2;
    // 0x80198840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80198844: jal         0x8002E4F8
    // 0x80198848: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    AllRange_PlayMessage(rdram, ctx);
        goto after_9;
    // 0x80198848: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_9:
    // 0x8019884C: b           L_80198924
    // 0x80198850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80198924;
    // 0x80198850: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80198854:
    // 0x80198854: slti        $at, $v1, 0x1F5
    ctx->r1 = SIGNED(ctx->r3) < 0X1F5 ? 1 : 0;
    // 0x80198858: bne         $at, $zero, L_80198920
    if (ctx->r1 != 0) {
        // 0x8019885C: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_80198920;
    }
    // 0x8019885C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80198860: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80198864: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80198868: andi        $t0, $v1, 0x1FF
    ctx->r8 = ctx->r3 & 0X1FF;
    // 0x8019886C: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x80198870: bnel        $t7, $at, L_80198924
    if (ctx->r15 != ctx->r1) {
        // 0x80198874: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80198924;
    }
    goto skip_3;
    // 0x80198874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80198878: bnel        $t0, $zero, L_80198924
    if (ctx->r8 != 0) {
        // 0x8019887C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80198924;
    }
    goto skip_4;
    // 0x8019887C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80198880: jal         0x80004EB0
    // 0x80198884: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x80198884: nop

    after_10:
    // 0x80198888: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019888C: lwc1        $f10, 0x30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X30);
    // 0x80198890: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80198894: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80198898: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019889C: addiu       $a0, $a0, 0x23E8
    ctx->r4 = ADD32(ctx->r4, 0X23E8);
    // 0x801988A0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801988A4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x801988A8: nop

    // 0x801988AC: beq         $v0, $zero, L_801988DC
    if (ctx->r2 == 0) {
        // 0x801988B0: nop
    
            goto L_801988DC;
    }
    // 0x801988B0: nop

    // 0x801988B4: beq         $v0, $at, L_801988EC
    if (ctx->r2 == ctx->r1) {
        // 0x801988B8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801988EC;
    }
    // 0x801988B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801988BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801988C0: beq         $v0, $at, L_80198900
    if (ctx->r2 == ctx->r1) {
        // 0x801988C4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80198900;
    }
    // 0x801988C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801988C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801988CC: beq         $v0, $at, L_80198914
    if (ctx->r2 == ctx->r1) {
        // 0x801988D0: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80198914;
    }
    // 0x801988D0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801988D4: b           L_80198924
    // 0x801988D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80198924;
    // 0x801988D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801988DC:
    // 0x801988DC: jal         0x8002E4F8
    // 0x801988E0: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    AllRange_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x801988E0: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_11:
    // 0x801988E4: b           L_80198924
    // 0x801988E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80198924;
    // 0x801988E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801988EC:
    // 0x801988EC: addiu       $a0, $a0, 0x2424
    ctx->r4 = ADD32(ctx->r4, 0X2424);
    // 0x801988F0: jal         0x8002E4F8
    // 0x801988F4: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    AllRange_PlayMessage(rdram, ctx);
        goto after_12;
    // 0x801988F4: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_12:
    // 0x801988F8: b           L_80198924
    // 0x801988FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80198924;
    // 0x801988FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80198900:
    // 0x80198900: addiu       $a0, $a0, 0x2484
    ctx->r4 = ADD32(ctx->r4, 0X2484);
    // 0x80198904: jal         0x8002E4F8
    // 0x80198908: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    AllRange_PlayMessage(rdram, ctx);
        goto after_13;
    // 0x80198908: addiu       $a1, $zero, 0xAA
    ctx->r5 = ADD32(0, 0XAA);
    after_13:
    // 0x8019890C: b           L_80198924
    // 0x80198910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80198924;
    // 0x80198910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80198914:
    // 0x80198914: addiu       $a0, $a0, 0x24AC
    ctx->r4 = ADD32(ctx->r4, 0X24AC);
    // 0x80198918: jal         0x8002E4F8
    // 0x8019891C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    AllRange_PlayMessage(rdram, ctx);
        goto after_14;
    // 0x8019891C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_14:
L_80198920:
    // 0x80198920: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80198924:
    // 0x80198924: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80198928: jr          $ra
    // 0x8019892C: nop

    return;
    // 0x8019892C: nop

;}
RECOMP_FUNC void Macbeth_MaLocomotive_HandleDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C4EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019C4F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019C4F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019C4F8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019C4FC: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x8019C500: beql        $t6, $zero, L_8019C5A4
    if (ctx->r14 == 0) {
        // 0x8019C504: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8019C5A4;
    }
    goto skip_0;
    // 0x8019C504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8019C508: lh          $t7, 0xD2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XD2);
    // 0x8019C50C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019C510: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8019C514: bne         $t7, $at, L_8019C574
    if (ctx->r15 != ctx->r1) {
        // 0x8019C518: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019C574;
    }
    // 0x8019C518: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019C51C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8019C520: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019C524: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8019C528: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8019C52C: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x8019C530: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8019C534: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019C538: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019C53C: jal         0x80019218
    // 0x8019C540: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019C540: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8019C544: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019C548: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x8019C54C: addiu       $v1, $v1, -0x1CE0
    ctx->r3 = ADD32(ctx->r3, -0X1CE0);
    // 0x8019C550: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8019C554: sw          $t9, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r25;
    // 0x8019C558: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x8019C55C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8019C560: sh          $zero, 0x2C($v1)
    MEM_H(0X2C, ctx->r3) = 0;
    // 0x8019C564: sh          $t0, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r8;
    // 0x8019C568: sh          $t1, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r9;
    // 0x8019C56C: b           L_8019C5A4
    // 0x8019C570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8019C5A4;
    // 0x8019C570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8019C574:
    // 0x8019C574: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019C578: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019C57C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019C580: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019C584: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8019C588: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x8019C58C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019C590: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019C594: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019C598: jal         0x80019218
    // 0x8019C59C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019C59C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8019C5A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019C5A4:
    // 0x8019C5A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019C5A8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019C5AC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019C5B0: jr          $ra
    // 0x8019C5B4: nop

    return;
    // 0x8019C5B4: nop

;}
RECOMP_FUNC void Macbeth_LongTrainObjects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ACFBC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801ACFC0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x801ACFC4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x801ACFC8: addiu       $v1, $v1, -0x7CF0
    ctx->r3 = ADD32(ctx->r3, -0X7CF0);
    // 0x801ACFCC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x801ACFD0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801ACFD4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801ACFD8: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801ACFDC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801ACFE0: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801ACFE4: addiu       $v0, $v0, 0x57CC
    ctx->r2 = ADD32(ctx->r2, 0X57CC);
    // 0x801ACFE8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x801ACFEC: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x801ACFF0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801ACFF4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x801ACFF8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801ACFFC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801AD000: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x801AD004: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801AD008: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x801AD00C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801AD010: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801AD014: addu        $s0, $t1, $at
    ctx->r16 = ADD32(ctx->r9, ctx->r1);
    // 0x801AD018: sw          $s0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r16;
    // 0x801AD01C: lh          $t3, 0x10($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X10);
    // 0x801AD020: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x801AD024: beql        $s1, $t3, L_801AD068
    if (ctx->r17 == ctx->r11) {
        // 0x801AD028: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801AD068;
    }
    goto skip_0;
    // 0x801AD028: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801AD02C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801AD030: lui         $at, 0x457A
    ctx->r1 = S32(0X457A << 16);
    // 0x801AD034: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801AD038: nop

    // 0x801AD03C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_801AD040:
    // 0x801AD040: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801AD044: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801AD048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AD04C: jal         0x80062180
    // 0x801AD050: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Object_Load(rdram, ctx);
        goto after_0;
    // 0x801AD050: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x801AD054: lh          $t4, 0x24($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X24);
    // 0x801AD058: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x801AD05C: bnel        $s1, $t4, L_801AD040
    if (ctx->r17 != ctx->r12) {
        // 0x801AD060: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_801AD040;
    }
    goto skip_1;
    // 0x801AD060: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_1:
    // 0x801AD064: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801AD068:
    // 0x801AD068: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801AD06C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801AD070: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801AD074: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801AD078: jr          $ra
    // 0x801AD07C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801AD07C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Macbeth_801A3790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A3790: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801A3794: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A3798: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x801A379C: addiu       $t0, $t0, -0x1DB0
    ctx->r8 = ADD32(ctx->r8, -0X1DB0);
    // 0x801A37A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A37A4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801A37A8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x801A37AC: lwc1        $f2, 0x40($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X40);
    // 0x801A37B0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A37B4: addiu       $a0, $a0, -0x6580
    ctx->r4 = ADD32(ctx->r4, -0X6580);
    // 0x801A37B8: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x801A37BC: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x801A37C0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x801A37C4: nop

    // 0x801A37C8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x801A37CC: sra         $v1, $t7, 16
    ctx->r3 = S32(SIGNED(ctx->r15) >> 16);
L_801A37D0:
    // 0x801A37D0: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A37D4: mflo        $t9
    ctx->r25 = lo;
    // 0x801A37D8: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x801A37DC: lh          $t1, 0x10($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X10);
    // 0x801A37E0: bnel        $t1, $zero, L_801A37F4
    if (ctx->r9 != 0) {
        // 0x801A37E4: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_801A37F4;
    }
    goto skip_0;
    // 0x801A37E4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x801A37E8: b           L_801A3C10
    // 0x801A37EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801A3C10;
    // 0x801A37EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A37F0: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_801A37F4:
    // 0x801A37F4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x801A37F8: nop

    // 0x801A37FC: bc1fl       L_801A38BC
    if (!c1cs) {
        // 0x801A3800: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_801A38BC;
    }
    goto skip_1;
    // 0x801A3800: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_1:
    // 0x801A3804: bnel        $v1, $zero, L_801A3818
    if (ctx->r3 != 0) {
        // 0x801A3808: mtc1        $v1, $f4
        ctx->f4.u32l = ctx->r3;
            goto L_801A3818;
    }
    goto skip_2;
    // 0x801A3808: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    skip_2:
    // 0x801A380C: b           L_801A3C10
    // 0x801A3810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801A3C10;
    // 0x801A3810: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A3814: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
L_801A3818:
    // 0x801A3818: lh          $a0, -0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, -0X4);
    // 0x801A381C: lwc1        $f6, -0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, -0XC);
    // 0x801A3820: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801A3824: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801A3828: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A382C: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x801A3830: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801A3834: lwc1        $f16, -0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X14);
    // 0x801A3838: c.eq.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl == ctx->f2.fl;
    // 0x801A383C: lwc1        $f12, -0x10($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X10);
    // 0x801A3840: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x801A3844: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801A3848: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x801A384C: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x801A3850: bc1t        L_801A38C8
    if (c1cs) {
        // 0x801A3854: swc1        $f10, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
            goto L_801A38C8;
    }
    // 0x801A3854: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x801A3858: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801A385C: addiu       $t3, $a0, -0x61
    ctx->r11 = ADD32(ctx->r4, -0X61);
    // 0x801A3860: sltiu       $at, $t3, 0x5
    ctx->r1 = ctx->r11 < 0X5 ? 1 : 0;
    // 0x801A3864: beq         $at, $zero, L_801A38B0
    if (ctx->r1 == 0) {
        // 0x801A3868: swc1        $f6, 0x44($t0)
        MEM_W(0X44, ctx->r8) = ctx->f6.u32l;
            goto L_801A38B0;
    }
    // 0x801A3868: swc1        $f6, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f6.u32l;
    // 0x801A386C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801A3870: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3874: addu        $at, $at, $t3
    gpr jr_addend_801A387C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801A3878: lw          $t3, -0x49EC($at)
    ctx->r11 = ADD32(ctx->r1, -0X49EC);
    // 0x801A387C: jr          $t3
    // 0x801A3880: nop

    switch (jr_addend_801A387C >> 2) {
        case 0: goto L_801A3884; break;
        case 1: goto L_801A3890; break;
        case 2: goto L_801A38A0; break;
        case 3: goto L_801A3884; break;
        case 4: goto L_801A3884; break;
        default: switch_error(__func__, 0x801A387C, 0x801BB614);
    }
    // 0x801A3880: nop

L_801A3884:
    // 0x801A3884: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A3888: b           L_801A38B0
    // 0x801A388C: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
        goto L_801A38B0;
    // 0x801A388C: swc1        $f8, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f8.u32l;
L_801A3890:
    // 0x801A3890: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801A3894: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A3898: b           L_801A38B0
    // 0x801A389C: swc1        $f10, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f10.u32l;
        goto L_801A38B0;
    // 0x801A389C: swc1        $f10, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f10.u32l;
L_801A38A0:
    // 0x801A38A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A38A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A38A8: nop

    // 0x801A38AC: swc1        $f4, 0x48($t0)
    MEM_W(0X48, ctx->r8) = ctx->f4.u32l;
L_801A38B0:
    // 0x801A38B0: b           L_801A38C8
    // 0x801A38B4: swc1        $f18, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f18.u32l;
        goto L_801A38C8;
    // 0x801A38B4: swc1        $f18, 0x40($t0)
    MEM_W(0X40, ctx->r8) = ctx->f18.u32l;
    // 0x801A38B8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801A38BC:
    // 0x801A38BC: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x801A38C0: b           L_801A37D0
    // 0x801A38C4: sra         $v1, $t4, 16
    ctx->r3 = S32(SIGNED(ctx->r12) >> 16);
        goto L_801A37D0;
    // 0x801A38C4: sra         $v1, $t4, 16
    ctx->r3 = S32(SIGNED(ctx->r12) >> 16);
L_801A38C8:
    // 0x801A38C8: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A38CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A38D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A38D4: sub.s       $f18, $f6, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x801A38D8: addiu       $v0, $zero, 0x5F
    ctx->r2 = ADD32(0, 0X5F);
    // 0x801A38DC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A38E0: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801A38E4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A38E8: addiu       $at, $zero, 0x60
    ctx->r1 = ADD32(0, 0X60);
    // 0x801A38EC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A38F0: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801A38F4: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x801A38F8: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801A38FC: addiu       $a0, $a0, -0x1D7C
    ctx->r4 = ADD32(ctx->r4, -0X1D7C);
    // 0x801A3900: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801A3904: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801A3908: beq         $a1, $v0, L_801A3928
    if (ctx->r5 == ctx->r2) {
        // 0x801A390C: swc1        $f2, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
            goto L_801A3928;
    }
    // 0x801A390C: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x801A3910: beq         $a1, $at, L_801A3928
    if (ctx->r5 == ctx->r1) {
        // 0x801A3914: addiu       $v1, $zero, 0x62
        ctx->r3 = ADD32(0, 0X62);
            goto L_801A3928;
    }
    // 0x801A3914: addiu       $v1, $zero, 0x62
    ctx->r3 = ADD32(0, 0X62);
    // 0x801A3918: beq         $a1, $v1, L_801A3928
    if (ctx->r5 == ctx->r3) {
        // 0x801A391C: addiu       $at, $zero, 0x63
        ctx->r1 = ADD32(0, 0X63);
            goto L_801A3928;
    }
    // 0x801A391C: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x801A3920: bne         $a1, $at, L_801A3B28
    if (ctx->r5 != ctx->r1) {
        // 0x801A3924: lwc1        $f4, 0x38($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801A3B28;
    }
    // 0x801A3924: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
L_801A3928:
    // 0x801A3928: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A392C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A3930: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3934: lwc1        $f10, -0x49D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X49D8);
    // 0x801A3938: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A393C: addiu       $v1, $zero, 0x62
    ctx->r3 = ADD32(0, 0X62);
    // 0x801A3940: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3944: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x801A3948: nop

    // 0x801A394C: bc1f        L_801A39F4
    if (!c1cs) {
        // 0x801A3950: abs.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
            goto L_801A39F4;
    }
    // 0x801A3950: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801A3954: beq         $a1, $v0, L_801A3964
    if (ctx->r5 == ctx->r2) {
        // 0x801A3958: lwc1        $f4, 0x38($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801A3964;
    }
    // 0x801A3958: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A395C: bne         $a1, $v1, L_801A39AC
    if (ctx->r5 != ctx->r3) {
        // 0x801A3960: lwc1        $f8, 0x38($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801A39AC;
    }
    // 0x801A3960: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
L_801A3964:
    // 0x801A3964: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x801A3968: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A396C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3970: sub.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x801A3974: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A3978: sub.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x801A397C: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x801A3980: add.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x801A3984: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A3988: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A398C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3990: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801A3994: lwc1        $f6, -0x49D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X49D4);
    // 0x801A3998: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A399C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A39A0: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x801A39A4: b           L_801A3B3C
    // 0x801A39A8: swc1        $f6, -0x1D64($at)
    MEM_W(-0X1D64, ctx->r1) = ctx->f6.u32l;
        goto L_801A3B3C;
    // 0x801A39A8: swc1        $f6, -0x1D64($at)
    MEM_W(-0X1D64, ctx->r1) = ctx->f6.u32l;
L_801A39AC:
    // 0x801A39AC: sub.s       $f4, $f8, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x801A39B0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A39B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A39B8: sub.s       $f2, $f16, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x801A39BC: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801A39C0: sub.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x801A39C4: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x801A39C8: add.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x801A39CC: div.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801A39D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A39D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A39D8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A39DC: lwc1        $f4, -0x49D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X49D0);
    // 0x801A39E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A39E4: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801A39E8: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801A39EC: b           L_801A3B3C
    // 0x801A39F0: swc1        $f4, -0x1D64($at)
    MEM_W(-0X1D64, ctx->r1) = ctx->f4.u32l;
        goto L_801A3B3C;
    // 0x801A39F0: swc1        $f4, -0x1D64($at)
    MEM_W(-0X1D64, ctx->r1) = ctx->f4.u32l;
L_801A39F4:
    // 0x801A39F4: lwc1        $f10, -0x49CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X49CC);
    // 0x801A39F8: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x801A39FC: nop

    // 0x801A3A00: bc1f        L_801A3A60
    if (!c1cs) {
        // 0x801A3A04: nop
    
            goto L_801A3A60;
    }
    // 0x801A3A04: nop

    // 0x801A3A08: beq         $a1, $v0, L_801A3A18
    if (ctx->r5 == ctx->r2) {
        // 0x801A3A0C: lwc1        $f8, 0x38($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801A3A18;
    }
    // 0x801A3A0C: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A3A10: bne         $a1, $v1, L_801A3A3C
    if (ctx->r5 != ctx->r3) {
        // 0x801A3A14: lwc1        $f10, 0x38($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801A3A3C;
    }
    // 0x801A3A14: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
L_801A3A18:
    // 0x801A3A18: sub.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x801A3A1C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3A20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3A24: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A3A28: lwc1        $f6, -0x49C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X49C8);
    // 0x801A3A2C: add.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x801A3A30: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801A3A34: b           L_801A3B3C
    // 0x801A3A38: swc1        $f4, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->f4.u32l;
        goto L_801A3B3C;
    // 0x801A3A38: swc1        $f4, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->f4.u32l;
L_801A3A3C:
    // 0x801A3A3C: sub.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x801A3A40: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3A44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3A48: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801A3A4C: lwc1        $f8, -0x49C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X49C4);
    // 0x801A3A50: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x801A3A54: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801A3A58: b           L_801A3B3C
    // 0x801A3A5C: swc1        $f6, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->f6.u32l;
        goto L_801A3B3C;
    // 0x801A3A5C: swc1        $f6, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->f6.u32l;
L_801A3A60:
    // 0x801A3A60: beq         $a1, $v0, L_801A3A70
    if (ctx->r5 == ctx->r2) {
        // 0x801A3A64: lwc1        $f4, 0x38($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801A3A70;
    }
    // 0x801A3A64: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A3A68: bne         $a1, $v1, L_801A3ACC
    if (ctx->r5 != ctx->r3) {
        // 0x801A3A6C: lwc1        $f10, 0x38($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
            goto L_801A3ACC;
    }
    // 0x801A3A6C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
L_801A3A70:
    // 0x801A3A70: sub.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x801A3A74: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3A78: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A3A7C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801A3A80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A3A84: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A3A88: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3A8C: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x801A3A90: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801A3A94: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x801A3A98: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801A3A9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A3AA0: div.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801A3AA4: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A3AA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A3AAC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3AB0: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801A3AB4: lwc1        $f8, -0x49C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X49C0);
    // 0x801A3AB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3ABC: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A3AC0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A3AC4: b           L_801A3B3C
    // 0x801A3AC8: swc1        $f8, -0x1D64($at)
    MEM_W(-0X1D64, ctx->r1) = ctx->f8.u32l;
        goto L_801A3B3C;
    // 0x801A3AC8: swc1        $f8, -0x1D64($at)
    MEM_W(-0X1D64, ctx->r1) = ctx->f8.u32l;
L_801A3ACC:
    // 0x801A3ACC: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x801A3AD0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3AD4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A3AD8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A3ADC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A3AE0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A3AE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A3AE8: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x801A3AEC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801A3AF0: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x801A3AF4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A3AF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A3AFC: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801A3B00: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x801A3B04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A3B08: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3B0C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A3B10: lwc1        $f6, -0x49BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X49BC);
    // 0x801A3B14: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A3B18: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A3B1C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801A3B20: b           L_801A3B3C
    // 0x801A3B24: swc1        $f6, -0x1D64($at)
    MEM_W(-0X1D64, ctx->r1) = ctx->f6.u32l;
        goto L_801A3B3C;
    // 0x801A3B24: swc1        $f6, -0x1D64($at)
    MEM_W(-0X1D64, ctx->r1) = ctx->f6.u32l;
L_801A3B28:
    // 0x801A3B28: sub.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x801A3B2C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3B30: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x801A3B34: add.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x801A3B38: swc1        $f4, 0x4C($t0)
    MEM_W(0X4C, ctx->r8) = ctx->f4.u32l;
L_801A3B3C:
    // 0x801A3B3C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A3B40: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A3B44: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3B48: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801A3B4C: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x801A3B50: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A3B54: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801A3B58: beq         $a1, $at, L_801A3B6C
    if (ctx->r5 == ctx->r1) {
        // 0x801A3B5C: swc1        $f6, 0x30($t0)
        MEM_W(0X30, ctx->r8) = ctx->f6.u32l;
            goto L_801A3B6C;
    }
    // 0x801A3B5C: swc1        $f6, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->f6.u32l;
    // 0x801A3B60: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x801A3B64: bnel        $a1, $at, L_801A3B8C
    if (ctx->r5 != ctx->r1) {
        // 0x801A3B68: addiu       $at, $zero, 0x65
        ctx->r1 = ADD32(0, 0X65);
            goto L_801A3B8C;
    }
    goto skip_3;
    // 0x801A3B68: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    skip_3:
L_801A3B6C:
    // 0x801A3B6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A3B70: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x801A3B74: jal         0x8009BC2C
    // 0x801A3B78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801A3B78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801A3B7C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A3B80: b           L_801A3BF4
    // 0x801A3B84: addiu       $t0, $t0, -0x1DB0
    ctx->r8 = ADD32(ctx->r8, -0X1DB0);
        goto L_801A3BF4;
    // 0x801A3B84: addiu       $t0, $t0, -0x1DB0
    ctx->r8 = ADD32(ctx->r8, -0X1DB0);
    // 0x801A3B88: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
L_801A3B8C:
    // 0x801A3B8C: beq         $a1, $at, L_801A3BA0
    if (ctx->r5 == ctx->r1) {
        // 0x801A3B90: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801A3BA0;
    }
    // 0x801A3B90: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A3B94: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x801A3B98: bne         $a1, $at, L_801A3BCC
    if (ctx->r5 != ctx->r1) {
        // 0x801A3B9C: lui         $a2, 0x3D4C
        ctx->r6 = S32(0X3D4C << 16);
            goto L_801A3BCC;
    }
    // 0x801A3B9C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
L_801A3BA0:
    // 0x801A3BA0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A3BA4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A3BA8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A3BAC: addiu       $a0, $a0, -0x1D7C
    ctx->r4 = ADD32(ctx->r4, -0X1D7C);
    // 0x801A3BB0: lui         $a1, 0xC000
    ctx->r5 = S32(0XC000 << 16);
    // 0x801A3BB4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801A3BB8: jal         0x8009BC2C
    // 0x801A3BBC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801A3BBC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x801A3BC0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A3BC4: b           L_801A3BF4
    // 0x801A3BC8: addiu       $t0, $t0, -0x1DB0
    ctx->r8 = ADD32(ctx->r8, -0X1DB0);
        goto L_801A3BF4;
    // 0x801A3BC8: addiu       $t0, $t0, -0x1DB0
    ctx->r8 = ADD32(ctx->r8, -0X1DB0);
L_801A3BCC:
    // 0x801A3BCC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A3BD0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801A3BD4: addiu       $a0, $a0, -0x1D7C
    ctx->r4 = ADD32(ctx->r4, -0X1D7C);
    // 0x801A3BD8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801A3BDC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A3BE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801A3BE4: jal         0x8009BC2C
    // 0x801A3BE8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A3BE8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801A3BEC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A3BF0: addiu       $t0, $t0, -0x1DB0
    ctx->r8 = ADD32(ctx->r8, -0X1DB0);
L_801A3BF4:
    // 0x801A3BF4: lwc1        $f6, 0x48($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X48);
    // 0x801A3BF8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3BFC: lwc1        $f8, 0x44($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X44);
    // 0x801A3C00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801A3C04: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801A3C08: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A3C0C: swc1        $f6, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f6.u32l;
L_801A3C10:
    // 0x801A3C10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A3C14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801A3C18: jr          $ra
    // 0x801A3C1C: nop

    return;
    // 0x801A3C1C: nop

;}
RECOMP_FUNC void Macbeth_MaBombDrop_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ADC08: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801ADC0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801ADC10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801ADC14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801ADC18: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801ADC1C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801ADC20: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801ADC24: jal         0x800613C4
    // 0x801ADC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801ADC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801ADC2C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801ADC30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801ADC34: addiu       $t7, $zero, 0xDC
    ctx->r15 = ADD32(0, 0XDC);
    // 0x801ADC38: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x801ADC3C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x801ADC40: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801ADC44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ADC48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801ADC4C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801ADC50: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801ADC54: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801ADC58: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801ADC5C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x801ADC60: lwc1        $f10, -0x45B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X45B8);
    // 0x801ADC64: c.eq.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl == ctx->f10.fl;
    // 0x801ADC68: nop

    // 0x801ADC6C: bc1fl       L_801ADC88
    if (!c1cs) {
        // 0x801ADC70: swc1        $f0, 0xE8($s0)
        MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
            goto L_801ADC88;
    }
    goto skip_0;
    // 0x801ADC70: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x801ADC74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801ADC78: sw          $t8, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r24;
    // 0x801ADC7C: b           L_801ADC8C
    // 0x801ADC80: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
        goto L_801ADC8C;
    // 0x801ADC80: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x801ADC84: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
L_801ADC88:
    // 0x801ADC88: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
L_801ADC8C:
    // 0x801ADC8C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801ADC90: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801ADC94: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801ADC98: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x801ADC9C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801ADCA0: sh          $zero, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = 0;
    // 0x801ADCA4: jal         0x800612B8
    // 0x801ADCA8: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x801ADCA8: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x801ADCAC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801ADCB0: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801ADCB4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801ADCB8: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x801ADCBC: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x801ADCC0: ori         $a0, $a0, 0x201D
    ctx->r4 = ctx->r4 | 0X201D;
    // 0x801ADCC4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801ADCC8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801ADCCC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x801ADCD0: jal         0x80019218
    // 0x801ADCD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801ADCD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x801ADCD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801ADCDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801ADCE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801ADCE4: jr          $ra
    // 0x801ADCE8: nop

    return;
    // 0x801ADCE8: nop

;}
RECOMP_FUNC void Macbeth_TrainTrack_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A23AC: addiu       $sp, $sp, -0x2D0
    ctx->r29 = ADD32(ctx->r29, -0X2D0);
    // 0x801A23B0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x801A23B4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A23B8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A23BC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801A23C0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x801A23C4: sw          $a0, 0x2D0($sp)
    MEM_W(0X2D0, ctx->r29) = ctx->r4;
    // 0x801A23C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A23CC: jal         0x800B8DD0
    // 0x801A23D0: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A23D0: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_0:
    // 0x801A23D4: lw          $a2, 0x2D0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2D0);
    // 0x801A23D8: lhu         $t6, 0x2($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X2);
    // 0x801A23DC: addiu       $t7, $t6, -0x5C
    ctx->r15 = ADD32(ctx->r14, -0X5C);
    // 0x801A23E0: sltiu       $at, $t7, 0xE
    ctx->r1 = ctx->r15 < 0XE ? 1 : 0;
    // 0x801A23E4: beq         $at, $zero, L_801A2A58
    if (ctx->r1 == 0) {
        // 0x801A23E8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_801A2A58;
    }
    // 0x801A23E8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801A23EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A23F0: addu        $at, $at, $t7
    gpr jr_addend_801A23F8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A23F4: lw          $t7, -0x4AD4($at)
    ctx->r15 = ADD32(ctx->r1, -0X4AD4);
    // 0x801A23F8: jr          $t7
    // 0x801A23FC: nop

    switch (jr_addend_801A23F8 >> 2) {
        case 0: goto L_801A2A10; break;
        case 1: goto L_801A2A38; break;
        case 2: goto L_801A2400; break;
        case 3: goto L_801A2470; break;
        case 4: goto L_801A24E0; break;
        case 5: goto L_801A2400; break;
        case 6: goto L_801A2470; break;
        case 7: goto L_801A24E0; break;
        case 8: goto L_801A2508; break;
        case 9: goto L_801A2530; break;
        case 10: goto L_801A2508; break;
        case 11: goto L_801A2530; break;
        case 12: goto L_801A258C; break;
        case 13: goto L_801A2558; break;
        default: switch_error(__func__, 0x801A23F8, 0x801BB52C);
    }
    // 0x801A23FC: nop

L_801A2400:
    // 0x801A2400: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801A2404: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801A2408: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A240C: lw          $t8, 0x1C8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C8);
    // 0x801A2410: beql        $t8, $at, L_801A244C
    if (ctx->r24 == ctx->r1) {
        // 0x801A2414: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_801A244C;
    }
    goto skip_0;
    // 0x801A2414: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x801A2418: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x801A241C: lwc1        $f6, 0xC($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XC);
    // 0x801A2420: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A2424: lwc1        $f10, -0x4A9C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X4A9C);
    // 0x801A2428: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A242C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A2430: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x801A2434: nop

    // 0x801A2438: bc1fl       L_801A244C
    if (!c1cs) {
        // 0x801A243C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_801A244C;
    }
    goto skip_1;
    // 0x801A243C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x801A2440: jal         0x80060FBC
    // 0x801A2444: addiu       $a1, $a2, 0x70
    ctx->r5 = ADD32(ctx->r6, 0X70);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x801A2444: addiu       $a1, $a2, 0x70
    ctx->r5 = ADD32(ctx->r6, 0X70);
    after_1:
    // 0x801A2448: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801A244C:
    // 0x801A244C: lui         $t3, 0x602
    ctx->r11 = S32(0X602 << 16);
    // 0x801A2450: addiu       $t3, $t3, 0x6860
    ctx->r11 = ADD32(ctx->r11, 0X6860);
    // 0x801A2454: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A2458: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801A245C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801A2460: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A2464: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801A2468: b           L_801A2A5C
    // 0x801A246C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A246C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A2470:
    // 0x801A2470: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801A2474: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801A2478: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A247C: lw          $t4, 0x1C8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C8);
    // 0x801A2480: beql        $t4, $at, L_801A24BC
    if (ctx->r12 == ctx->r1) {
        // 0x801A2484: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_801A24BC;
    }
    goto skip_2;
    // 0x801A2484: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x801A2488: lwc1        $f16, 0x138($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X138);
    // 0x801A248C: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x801A2490: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A2494: lwc1        $f6, -0x4A98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4A98);
    // 0x801A2498: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A249C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A24A0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801A24A4: nop

    // 0x801A24A8: bc1fl       L_801A24BC
    if (!c1cs) {
        // 0x801A24AC: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_801A24BC;
    }
    goto skip_3;
    // 0x801A24AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x801A24B0: jal         0x80060FBC
    // 0x801A24B4: addiu       $a1, $a2, 0x70
    ctx->r5 = ADD32(ctx->r6, 0X70);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x801A24B4: addiu       $a1, $a2, 0x70
    ctx->r5 = ADD32(ctx->r6, 0X70);
    after_2:
    // 0x801A24B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801A24BC:
    // 0x801A24BC: lui         $t7, 0x603
    ctx->r15 = S32(0X603 << 16);
    // 0x801A24C0: addiu       $t7, $t7, -0x410
    ctx->r15 = ADD32(ctx->r15, -0X410);
    // 0x801A24C4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801A24C8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801A24CC: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x801A24D0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801A24D4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801A24D8: b           L_801A2A5C
    // 0x801A24DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A24DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A24E0:
    // 0x801A24E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A24E4: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x801A24E8: addiu       $t2, $t2, 0x2610
    ctx->r10 = ADD32(ctx->r10, 0X2610);
    // 0x801A24EC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801A24F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801A24F4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801A24F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801A24FC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801A2500: b           L_801A2A5C
    // 0x801A2504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A2504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A2508:
    // 0x801A2508: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A250C: lui         $t5, 0x603
    ctx->r13 = S32(0X603 << 16);
    // 0x801A2510: addiu       $t5, $t5, 0x9D0
    ctx->r13 = ADD32(ctx->r13, 0X9D0);
    // 0x801A2514: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A2518: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801A251C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x801A2520: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801A2524: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A2528: b           L_801A2A5C
    // 0x801A252C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A252C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A2530:
    // 0x801A2530: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2534: lui         $t8, 0x603
    ctx->r24 = S32(0X603 << 16);
    // 0x801A2538: addiu       $t8, $t8, 0x750
    ctx->r24 = ADD32(ctx->r24, 0X750);
    // 0x801A253C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A2540: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A2544: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801A2548: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A254C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A2550: b           L_801A2A5C
    // 0x801A2554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A2554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A2558:
    // 0x801A2558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A255C: jal         0x800B8DD0
    // 0x801A2560: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801A2560: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_3:
    // 0x801A2564: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2568: lui         $t3, 0x603
    ctx->r11 = S32(0X603 << 16);
    // 0x801A256C: addiu       $t3, $t3, -0x2C80
    ctx->r11 = ADD32(ctx->r11, -0X2C80);
    // 0x801A2570: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A2574: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801A2578: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801A257C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A2580: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801A2584: b           L_801A2A5C
    // 0x801A2588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A2588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A258C:
    // 0x801A258C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A2590: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A2594: jal         0x80005708
    // 0x801A2598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x801A2598: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801A259C: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x801A25A0: addiu       $a0, $a0, 0x5CA0
    ctx->r4 = ADD32(ctx->r4, 0X5CA0);
    // 0x801A25A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801A25A8: jal         0x8009AA20
    // 0x801A25AC: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    Animation_GetFrameData(rdram, ctx);
        goto after_5;
    // 0x801A25AC: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    after_5:
    // 0x801A25B0: lw          $t5, 0x2D0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2D0);
    // 0x801A25B4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x801A25B8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801A25BC: addiu       $t6, $t6, 0x4660
    ctx->r14 = ADD32(ctx->r14, 0X4660);
    // 0x801A25C0: addiu       $t4, $t4, 0xE2C
    ctx->r12 = ADD32(ctx->r12, 0XE2C);
    // 0x801A25C4: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x801A25C8: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x801A25CC: addiu       $a3, $a3, 0xDD8
    ctx->r7 = ADD32(ctx->r7, 0XDD8);
    // 0x801A25D0: addiu       $a1, $a1, 0x5DAC
    ctx->r5 = ADD32(ctx->r5, 0X5DAC);
    // 0x801A25D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801A25D8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801A25DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801A25E0: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x801A25E4: jal         0x8009A72C
    // 0x801A25E8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_6;
    // 0x801A25E8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_6:
    // 0x801A25EC: jal         0x80005740
    // 0x801A25F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x801A25F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801A25F4: lw          $v1, 0x2D0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2D0);
    // 0x801A25F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A25FC: lw          $v0, 0x48($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X48);
    // 0x801A2600: bnel        $v0, $at, L_801A2808
    if (ctx->r2 != ctx->r1) {
        // 0x801A2604: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A2808;
    }
    goto skip_4;
    // 0x801A2604: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_4:
    // 0x801A2608: lw          $t7, 0x4C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4C);
    // 0x801A260C: bgtzl       $t7, L_801A2808
    if (SIGNED(ctx->r15) > 0) {
        // 0x801A2610: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A2808;
    }
    goto skip_5;
    // 0x801A2610: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_5:
    // 0x801A2614: jal         0x80005708
    // 0x801A2618: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_8;
    // 0x801A2618: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x801A261C: jal         0x800BA5B0
    // 0x801A2620: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_9;
    // 0x801A2620: nop

    after_9:
    // 0x801A2624: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801A2628: addiu       $t1, $t1, -0x1978
    ctx->r9 = ADD32(ctx->r9, -0X1978);
    // 0x801A262C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2630: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x801A2634: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801A2638: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801A263C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801A2640: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801A2644: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801A2648: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A264C: lui         $t5, 0xFF30
    ctx->r13 = S32(0XFF30 << 16);
    // 0x801A2650: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x801A2654: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A2658: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801A265C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x801A2660: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801A2664: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A2668: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A266C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A2670: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A2674: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A2678: lwc1        $f8, 0x4($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X4);
    // 0x801A267C: lwc1        $f18, 0x8($t1)
    ctx->f18.u32l = MEM_W(ctx->r9, 0X8);
    // 0x801A2680: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A2684: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A2688: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801A268C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A2690: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A2694: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801A2698: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x801A269C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801A26A0: jal         0x80005B00
    // 0x801A26A4: nop

    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x801A26A4: nop

    after_10:
    // 0x801A26A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A26AC: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x801A26B0: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x801A26B4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A26B8: jal         0x80005D44
    // 0x801A26BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_11;
    // 0x801A26BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x801A26C0: lw          $t7, 0x2D0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2D0);
    // 0x801A26C4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A26C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A26CC: lwc1        $f0, 0x6C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X6C);
    // 0x801A26D0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A26D4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A26D8: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801A26DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A26E0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A26E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A26E8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801A26EC: jal         0x80005C34
    // 0x801A26F0: nop

    Matrix_Scale(rdram, ctx);
        goto after_12;
    // 0x801A26F0: nop

    after_12:
    // 0x801A26F4: jal         0x80006EB8
    // 0x801A26F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_13;
    // 0x801A26F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x801A26FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2700: lui         $a1, 0x102
    ctx->r5 = S32(0X102 << 16);
    // 0x801A2704: addiu       $a1, $a1, 0x4AC0
    ctx->r5 = ADD32(ctx->r5, 0X4AC0);
    // 0x801A2708: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A270C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801A2710: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801A2714: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A2718: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x801A271C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A2720: jal         0x80005740
    // 0x801A2724: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    Matrix_Pop(rdram, ctx);
        goto after_14;
    // 0x801A2724: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_14:
    // 0x801A2728: jal         0x80005708
    // 0x801A272C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_15;
    // 0x801A272C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x801A2730: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801A2734: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A2738: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A273C: addiu       $v0, $v0, -0x1978
    ctx->r2 = ADD32(ctx->r2, -0X1978);
    // 0x801A2740: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A2744: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A2748: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801A274C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801A2750: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A2754: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A2758: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A275C: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x801A2760: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A2764: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801A2768: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A276C: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801A2770: jal         0x80005B00
    // 0x801A2774: nop

    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x801A2774: nop

    after_16:
    // 0x801A2778: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A277C: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x801A2780: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x801A2784: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A2788: jal         0x80005D44
    // 0x801A278C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_17;
    // 0x801A278C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x801A2790: lw          $t4, 0x2D0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2D0);
    // 0x801A2794: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A2798: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A279C: lwc1        $f0, 0x6C($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X6C);
    // 0x801A27A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A27A4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801A27A8: div.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f16.fl);
    // 0x801A27AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A27B0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A27B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A27B8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801A27BC: jal         0x80005C34
    // 0x801A27C0: nop

    Matrix_Scale(rdram, ctx);
        goto after_18;
    // 0x801A27C0: nop

    after_18:
    // 0x801A27C4: jal         0x80006EB8
    // 0x801A27C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x801A27C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x801A27CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A27D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801A27D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A27D8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A27DC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A27E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A27E4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x801A27E8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A27EC: jal         0x800B8DD0
    // 0x801A27F0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_20;
    // 0x801A27F0: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_20:
    // 0x801A27F4: jal         0x80005740
    // 0x801A27F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_21;
    // 0x801A27F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x801A27FC: b           L_801A292C
    // 0x801A2800: nop

        goto L_801A292C;
    // 0x801A2800: nop

    // 0x801A2804: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_801A2808:
    // 0x801A2808: bne         $v0, $at, L_801A292C
    if (ctx->r2 != ctx->r1) {
        // 0x801A280C: nop
    
            goto L_801A292C;
    }
    // 0x801A280C: nop

    // 0x801A2810: jal         0x80005708
    // 0x801A2814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_22;
    // 0x801A2814: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x801A2818: jal         0x800BA5B0
    // 0x801A281C: nop

    RCP_SetupDL_49(rdram, ctx);
        goto after_23;
    // 0x801A281C: nop

    after_23:
    // 0x801A2820: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A2824: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801A2828: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A282C: addiu       $t1, $t1, -0x1978
    ctx->r9 = ADD32(ctx->r9, -0X1978);
    // 0x801A2830: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2834: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x801A2838: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801A283C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A2840: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801A2844: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801A2848: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A284C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2850: lui         $t6, 0xFF30
    ctx->r14 = S32(0XFF30 << 16);
    // 0x801A2854: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x801A2858: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801A285C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801A2860: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x801A2864: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801A2868: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A286C: lwc1        $f4, 0xC($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0XC);
    // 0x801A2870: lwc1        $f8, 0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X10);
    // 0x801A2874: lwc1        $f16, 0x14($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X14);
    // 0x801A2878: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801A287C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A2880: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A2884: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801A2888: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A288C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A2890: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801A2894: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801A2898: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801A289C: jal         0x80005B00
    // 0x801A28A0: nop

    Matrix_Translate(rdram, ctx);
        goto after_24;
    // 0x801A28A0: nop

    after_24:
    // 0x801A28A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A28A8: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x801A28AC: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x801A28B0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A28B4: jal         0x80005D44
    // 0x801A28B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_25;
    // 0x801A28B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_25:
    // 0x801A28BC: lw          $t8, 0x2D0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2D0);
    // 0x801A28C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801A28C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A28C8: lwc1        $f0, 0x6C($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X6C);
    // 0x801A28CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A28D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A28D4: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801A28D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A28DC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A28E0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A28E4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801A28E8: jal         0x80005C34
    // 0x801A28EC: nop

    Matrix_Scale(rdram, ctx);
        goto after_26;
    // 0x801A28EC: nop

    after_26:
    // 0x801A28F0: jal         0x80006EB8
    // 0x801A28F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_27;
    // 0x801A28F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x801A28F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A28FC: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x801A2900: addiu       $t4, $t4, 0x4AC0
    ctx->r12 = ADD32(ctx->r12, 0X4AC0);
    // 0x801A2904: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801A2908: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801A290C: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801A2910: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801A2914: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A2918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A291C: jal         0x800B8DD0
    // 0x801A2920: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_28;
    // 0x801A2920: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_28:
    // 0x801A2924: jal         0x80005740
    // 0x801A2928: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_29;
    // 0x801A2928: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
L_801A292C:
    // 0x801A292C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801A2930: lh          $t5, -0x1D06($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X1D06);
    // 0x801A2934: beq         $t5, $zero, L_801A299C
    if (ctx->r13 == 0) {
        // 0x801A2938: nop
    
            goto L_801A299C;
    }
    // 0x801A2938: nop

    // 0x801A293C: jal         0x80005708
    // 0x801A2940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_30;
    // 0x801A2940: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_30:
    // 0x801A2944: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A2948: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A294C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801A2950: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A2954: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A2958: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A295C: jal         0x80005B00
    // 0x801A2960: lui         $a3, 0xC4E1
    ctx->r7 = S32(0XC4E1 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_31;
    // 0x801A2960: lui         $a3, 0xC4E1
    ctx->r7 = S32(0XC4E1 << 16);
    after_31:
    // 0x801A2964: jal         0x80006EB8
    // 0x801A2968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_32;
    // 0x801A2968: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x801A296C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2970: lui         $t9, 0x602
    ctx->r25 = S32(0X602 << 16);
    // 0x801A2974: addiu       $t9, $t9, -0x3E90
    ctx->r25 = ADD32(ctx->r25, -0X3E90);
    // 0x801A2978: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801A297C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801A2980: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801A2984: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801A2988: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801A298C: jal         0x80005740
    // 0x801A2990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_33;
    // 0x801A2990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_33:
    // 0x801A2994: b           L_801A2A5C
    // 0x801A2998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A2998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A299C:
    // 0x801A299C: jal         0x80005708
    // 0x801A29A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_34;
    // 0x801A29A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_34:
    // 0x801A29A4: lui         $a1, 0xBE32
    ctx->r5 = S32(0XBE32 << 16);
    // 0x801A29A8: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x801A29AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A29B0: jal         0x80005E90
    // 0x801A29B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_35;
    // 0x801A29B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_35:
    // 0x801A29B8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A29BC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A29C0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801A29C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A29C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A29CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A29D0: jal         0x80005B00
    // 0x801A29D4: lui         $a3, 0xC4E1
    ctx->r7 = S32(0XC4E1 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_36;
    // 0x801A29D4: lui         $a3, 0xC4E1
    ctx->r7 = S32(0XC4E1 << 16);
    after_36:
    // 0x801A29D8: jal         0x80006EB8
    // 0x801A29DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_37;
    // 0x801A29DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x801A29E0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A29E4: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x801A29E8: addiu       $t5, $t5, -0x3E90
    ctx->r13 = ADD32(ctx->r13, -0X3E90);
    // 0x801A29EC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A29F0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801A29F4: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x801A29F8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801A29FC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A2A00: jal         0x80005740
    // 0x801A2A04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_38;
    // 0x801A2A04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_38:
    // 0x801A2A08: b           L_801A2A5C
    // 0x801A2A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A2A0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A2A10:
    // 0x801A2A10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2A14: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801A2A18: addiu       $t8, $t8, 0x14A0
    ctx->r24 = ADD32(ctx->r24, 0X14A0);
    // 0x801A2A1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A2A20: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A2A24: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801A2A28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A2A2C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801A2A30: b           L_801A2A5C
    // 0x801A2A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_801A2A5C;
    // 0x801A2A34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A2A38:
    // 0x801A2A38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A2A3C: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801A2A40: addiu       $t3, $t3, 0x1180
    ctx->r11 = ADD32(ctx->r11, 0X1180);
    // 0x801A2A44: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801A2A48: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801A2A4C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x801A2A50: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801A2A54: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
L_801A2A58:
    // 0x801A2A58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801A2A5C:
    // 0x801A2A5C: jal         0x800B8DD0
    // 0x801A2A60: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_39;
    // 0x801A2A60: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_39:
    // 0x801A2A64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801A2A68: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x801A2A6C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x801A2A70: jr          $ra
    // 0x801A2A74: addiu       $sp, $sp, 0x2D0
    ctx->r29 = ADD32(ctx->r29, 0X2D0);
    return;
    // 0x801A2A74: addiu       $sp, $sp, 0x2D0
    ctx->r29 = ADD32(ctx->r29, 0X2D0);
;}
RECOMP_FUNC void Titania_TiDesertRover_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189AFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80189B00: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80189B04: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80189B08: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80189B0C: lui         $a0, 0x701
    ctx->r4 = S32(0X701 << 16);
    // 0x80189B10: addiu       $a0, $a0, -0x3728
    ctx->r4 = ADD32(ctx->r4, -0X3728);
    // 0x80189B14: addiu       $a2, $a2, 0x18C
    ctx->r6 = ADD32(ctx->r6, 0X18C);
    // 0x80189B18: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80189B1C: jal         0x8009AA20
    // 0x80189B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x80189B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80189B24: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80189B28: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x80189B2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189B30: lwc1        $f4, 0x128($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X128);
    // 0x80189B34: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80189B38: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80189B3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80189B40: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80189B44: addiu       $t7, $t7, 0x4660
    ctx->r15 = ADD32(ctx->r15, 0X4660);
    // 0x80189B48: addiu       $t6, $t6, -0x6E4C
    ctx->r14 = ADD32(ctx->r14, -0X6E4C);
    // 0x80189B4C: swc1        $f8, 0x1B8($v0)
    MEM_W(0X1B8, ctx->r2) = ctx->f8.u32l;
    // 0x80189B50: lui         $a1, 0x701
    ctx->r5 = S32(0X701 << 16);
    // 0x80189B54: addiu       $a1, $a1, -0x369C
    ctx->r5 = ADD32(ctx->r5, -0X369C);
    // 0x80189B58: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80189B5C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80189B60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80189B64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80189B68: jal         0x8009A72C
    // 0x80189B6C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x80189B6C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    after_1:
    // 0x80189B70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80189B74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80189B78: jr          $ra
    // 0x80189B7C: nop

    return;
    // 0x80189B7C: nop

;}
RECOMP_FUNC void Ground_801B4A54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B4A54: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801B4A58: nop

    // 0x801B4A5C: trunc.w.s   $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x801B4A60: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x801B4A64: swc1        $f2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f2.u32l;
    // 0x801B4A68: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x801B4A6C: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x801B4A70: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801B4A74: sh          $v0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r2;
    // 0x801B4A78: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801B4A7C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801B4A80: swc1        $f0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f0.u32l;
    // 0x801B4A84: swc1        $f0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f0.u32l;
    // 0x801B4A88: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x801B4A8C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x801B4A90: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x801B4A94: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x801B4A98: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x801B4A9C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x801B4AA0: jr          $ra
    // 0x801B4AA4: nop

    return;
    // 0x801B4AA4: nop

;}
RECOMP_FUNC void Macbeth_8019B8B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B8B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8019B8B4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8019B8B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019B8BC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8019B8C0: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8019B8C4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8019B8C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019B8CC: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8019B8D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019B8D4: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8019B8D8: bne         $t6, $zero, L_8019B988
    if (ctx->r14 != 0) {
        // 0x8019B8DC: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8019B988;
    }
    // 0x8019B8DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8019B8E0: jal         0x80004EB0
    // 0x8019B8E4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8019B8E4: nop

    after_0:
    // 0x8019B8E8: jal         0x80004EB0
    // 0x8019B8EC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019B8EC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_1:
    // 0x8019B8F0: jal         0x80004EB0
    // 0x8019B8F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8019B8F4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x8019B8F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019B8FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019B900: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019B904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B908: sub.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x8019B90C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019B910: lwc1        $f18, 0x168($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X168);
    // 0x8019B914: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019B918: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019B91C: sub.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x8019B920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B924: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019B928: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8019B92C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019B930: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019B934: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019B938: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019B93C: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019B940: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019B944: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x8019B948: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B94C: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8019B950: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019B954: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019B958: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019B95C: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019B960: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8019B964: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019B968: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8019B96C: jal         0x8007D2C8
    // 0x8019B970: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_3;
    // 0x8019B970: nop

    after_3:
    // 0x8019B974: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019B978: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8019B97C: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8019B980: b           L_8019BB84
    // 0x8019B984: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8019BB84;
    // 0x8019B984: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_8019B988:
    // 0x8019B988: bnel        $v0, $at, L_8019BA30
    if (ctx->r2 != ctx->r1) {
        // 0x8019B98C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8019BA30;
    }
    goto skip_0;
    // 0x8019B98C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8019B990: jal         0x80004EB0
    // 0x8019B994: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8019B994: nop

    after_4:
    // 0x8019B998: jal         0x80004EB0
    // 0x8019B99C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8019B99C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_5:
    // 0x8019B9A0: jal         0x80004EB0
    // 0x8019B9A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8019B9A4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x8019B9A8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019B9AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019B9B0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019B9B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B9B8: sub.s       $f4, $f22, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x8019B9BC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019B9C0: lwc1        $f16, 0x178($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019B9C4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019B9C8: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019B9CC: sub.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x8019B9D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B9D4: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019B9D8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8019B9DC: add.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019B9E0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019B9E4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019B9E8: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8019B9EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019B9F0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019B9F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B9F8: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019B9FC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019BA00: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019BA04: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019BA08: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019BA0C: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8019BA10: jal         0x8007D2C8
    // 0x8019BA14: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_7;
    // 0x8019BA14: nop

    after_7:
    // 0x8019BA18: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019BA1C: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8019BA20: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8019BA24: b           L_8019BB84
    // 0x8019BA28: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8019BB84;
    // 0x8019BA28: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8019BA2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8019BA30:
    // 0x8019BA30: bnel        $v0, $at, L_8019BAE4
    if (ctx->r2 != ctx->r1) {
        // 0x8019BA34: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8019BAE4;
    }
    goto skip_1;
    // 0x8019BA34: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_1:
    // 0x8019BA38: jal         0x80004EB0
    // 0x8019BA3C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8019BA3C: nop

    after_8:
    // 0x8019BA40: jal         0x80004EB0
    // 0x8019BA44: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x8019BA44: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_9:
    // 0x8019BA48: jal         0x80004EB0
    // 0x8019BA4C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8019BA4C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_10:
    // 0x8019BA50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019BA54: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019BA58: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019BA5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019BA60: sub.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x8019BA64: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019BA68: lwc1        $f16, 0x170($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X170);
    // 0x8019BA6C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019BA70: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019BA74: sub.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x8019BA78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019BA7C: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019BA80: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8019BA84: add.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019BA88: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019BA8C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019BA90: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019BA94: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019BA98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BA9C: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x8019BAA0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019BAA4: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8019BAA8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019BAAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BAB0: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019BAB4: add.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8019BAB8: mul.s       $f6, $f0, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x8019BABC: add.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019BAC0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8019BAC4: jal         0x8007D2C8
    // 0x8019BAC8: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_11;
    // 0x8019BAC8: nop

    after_11:
    // 0x8019BACC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019BAD0: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8019BAD4: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8019BAD8: b           L_8019BB84
    // 0x8019BADC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_8019BB84;
    // 0x8019BADC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8019BAE0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8019BAE4:
    // 0x8019BAE4: bne         $v0, $at, L_8019BB84
    if (ctx->r2 != ctx->r1) {
        // 0x8019BAE8: nop
    
            goto L_8019BB84;
    }
    // 0x8019BAE8: nop

    // 0x8019BAEC: jal         0x80004EB0
    // 0x8019BAF0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x8019BAF0: nop

    after_12:
    // 0x8019BAF4: jal         0x80004EB0
    // 0x8019BAF8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x8019BAF8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_13:
    // 0x8019BAFC: jal         0x80004EB0
    // 0x8019BB00: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x8019BB00: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_14:
    // 0x8019BB04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019BB08: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019BB0C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019BB10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019BB14: sub.s       $f10, $f22, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x8019BB18: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019BB1C: lwc1        $f18, 0x178($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019BB20: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019BB24: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019BB28: sub.s       $f10, $f20, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f2.fl;
    // 0x8019BB2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019BB30: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019BB34: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8019BB38: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8019BB3C: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8019BB40: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019BB44: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019BB48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019BB4C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019BB50: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019BB54: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019BB58: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019BB5C: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019BB60: add.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019BB64: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8019BB68: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8019BB6C: jal         0x8007D2C8
    // 0x8019BB70: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_15;
    // 0x8019BB70: nop

    after_15:
    // 0x8019BB74: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019BB78: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8019BB7C: andi        $t0, $v0, 0x3
    ctx->r8 = ctx->r2 & 0X3;
    // 0x8019BB80: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8019BB84:
    // 0x8019BB84: bne         $v0, $zero, L_8019BBD4
    if (ctx->r2 != 0) {
        // 0x8019BB88: lui         $at, 0x43AF
        ctx->r1 = S32(0X43AF << 16);
            goto L_8019BBD4;
    }
    // 0x8019BB88: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8019BB8C: lwc1        $f6, 0x178($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8019BB90: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019BB94: lwc1        $f16, 0xEC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8019BB98: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019BB9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019BBA0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8019BBA4: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x8019BBA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019BBAC: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8019BBB0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019BBB4: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019BBB8: lwc1        $f6, -0x4CD8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4CD8);
    // 0x8019BBBC: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8019BBC0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8019BBC4: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019BBC8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8019BBCC: jal         0x8007C120
    // 0x8019BBD0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_16;
    // 0x8019BBD0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_16:
L_8019BBD4:
    // 0x8019BBD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8019BBD8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8019BBDC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8019BBE0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8019BBE4: jr          $ra
    // 0x8019BBE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8019BBE8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
