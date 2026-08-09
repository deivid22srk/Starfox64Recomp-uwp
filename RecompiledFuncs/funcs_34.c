#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Area6_A6Gorgon_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187754: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80187758: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018775C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80187760: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80187764: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80187768: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018776C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80187770: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80187774: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187778: sw          $t6, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = ctx->r14;
    // 0x8018777C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187780: lwc1        $f4, 0x910($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X910);
    // 0x80187784: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187788: addiu       $t7, $zero, 0x30C
    ctx->r15 = ADD32(0, 0X30C);
    // 0x8018778C: swc1        $f4, 0x1A44($at)
    MEM_W(0X1A44, ctx->r1) = ctx->f4.u32l;
    // 0x80187790: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187794: sw          $zero, 0x13A0($at)
    MEM_W(0X13A0, ctx->r1) = 0;
    // 0x80187798: sh          $t7, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r15;
    // 0x8018779C: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
    // 0x801877A0: swc1        $f0, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f0.u32l;
    // 0x801877A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801877A8: lwc1        $f6, 0x914($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X914);
    // 0x801877AC: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x801877B0: sh          $t8, 0xAA($s0)
    MEM_H(0XAA, ctx->r16) = ctx->r24;
    // 0x801877B4: lh          $v1, 0xAA($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XAA);
    // 0x801877B8: sh          $a2, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r6;
    // 0x801877BC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801877C0: sh          $v1, 0xA8($s0)
    MEM_H(0XA8, ctx->r16) = ctx->r3;
    // 0x801877C4: sh          $v1, 0xA6($s0)
    MEM_H(0XA6, ctx->r16) = ctx->r3;
    // 0x801877C8: lh          $v1, 0xB0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB0);
    // 0x801877CC: sh          $a2, 0xBA($s0)
    MEM_H(0XBA, ctx->r16) = ctx->r6;
    // 0x801877D0: addiu       $v0, $v0, 0x2250
    ctx->r2 = ADD32(ctx->r2, 0X2250);
    // 0x801877D4: sh          $v1, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r3;
    // 0x801877D8: sh          $v1, 0xAC($s0)
    MEM_H(0XAC, ctx->r16) = ctx->r3;
    // 0x801877DC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801877E0: addiu       $v1, $v1, 0x22F0
    ctx->r3 = ADD32(ctx->r3, 0X22F0);
    // 0x801877E4: swc1        $f6, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f6.u32l;
L_801877E8:
    // 0x801877E8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801877EC: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x801877F0: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x801877F4: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801877F8: bne         $v0, $v1, L_801877E8
    if (ctx->r2 != ctx->r3) {
        // 0x801877FC: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_801877E8;
    }
    // 0x801877FC: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x80187800: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80187804: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80187808: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018780C: addiu       $v0, $v0, 0x22F0
    ctx->r2 = ADD32(ctx->r2, 0X22F0);
    // 0x80187810: swc1        $f12, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f12.u32l;
    // 0x80187814: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80187818: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018781C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80187820: swc1        $f2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f2.u32l;
    // 0x80187824: swc1        $f2, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f2.u32l;
    // 0x80187828: swc1        $f2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f2.u32l;
    // 0x8018782C: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80187830: sh          $zero, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = 0;
    // 0x80187834: lh          $v1, 0xC2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XC2);
    // 0x80187838: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8018783C: sh          $a0, 0xB4($s0)
    MEM_H(0XB4, ctx->r16) = ctx->r4;
    // 0x80187840: sh          $a0, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r4;
    // 0x80187844: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
    // 0x80187848: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018784C: swc1        $f12, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f12.u32l;
    // 0x80187850: sh          $v1, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r3;
    // 0x80187854: sh          $v1, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r3;
    // 0x80187858: lwc1        $f10, 0x918($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X918);
    // 0x8018785C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80187860: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80187864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187868: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018786C: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x80187870: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80187874: lw          $t1, 0x28($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X28);
    // 0x80187878: addiu       $t0, $zero, 0x1F4
    ctx->r8 = ADD32(0, 0X1F4);
    // 0x8018787C: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
    // 0x80187880: swc1        $f10, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f10.u32l;
    // 0x80187884: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
    // 0x80187888: swc1        $f18, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f18.u32l;
    // 0x8018788C: swc1        $f4, 0x50($t1)
    MEM_W(0X50, ctx->r9) = ctx->f4.u32l;
    // 0x80187890: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80187894: lui         $at, 0x4313
    ctx->r1 = S32(0X4313 << 16);
    // 0x80187898: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018789C: lwc1        $f0, 0x50($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X50);
    // 0x801878A0: lui         $at, 0x4319
    ctx->r1 = S32(0X4319 << 16);
    // 0x801878A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801878A8: swc1        $f0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f0.u32l;
    // 0x801878AC: lw          $t2, 0x28($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X28);
    // 0x801878B0: lui         $a0, 0x1028
    ctx->r4 = S32(0X1028 << 16);
    // 0x801878B4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x801878B8: swc1        $f0, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f0.u32l;
    // 0x801878BC: lw          $t3, 0x28($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X28);
    // 0x801878C0: swc1        $f6, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f6.u32l;
    // 0x801878C4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x801878C8: lwc1        $f0, 0x58($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X58);
    // 0x801878CC: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x801878D0: lw          $t4, 0x28($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X28);
    // 0x801878D4: swc1        $f0, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f0.u32l;
    // 0x801878D8: lw          $t5, 0x28($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X28);
    // 0x801878DC: swc1        $f8, 0x60($t5)
    MEM_W(0X60, ctx->r13) = ctx->f8.u32l;
    // 0x801878E0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x801878E4: lwc1        $f0, 0x60($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X60);
    // 0x801878E8: swc1        $f0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f0.u32l;
    // 0x801878EC: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x801878F0: jal         0x800182F4
    // 0x801878F4: swc1        $f0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f0.u32l;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x801878F4: swc1        $f0, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f0.u32l;
    after_0:
    // 0x801878F8: lui         $a0, 0x1128
    ctx->r4 = S32(0X1128 << 16);
    // 0x801878FC: jal         0x800182F4
    // 0x80187900: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x80187900: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80187904: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80187908: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8018790C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80187910: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80187914: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x80187918: ori         $a0, $a0, 0x2050
    ctx->r4 = ctx->r4 | 0X2050;
    // 0x8018791C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80187920: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80187924: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x80187928: jal         0x80019218
    // 0x8018792C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8018792C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80187930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80187934: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80187938: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018793C: jr          $ra
    // 0x80187940: nop

    return;
    // 0x80187940: nop

;}
RECOMP_FUNC void Aquas_801BEC8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BEC8C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801BEC90: jr          $ra
    // 0x801BEC94: nop

    return;
    // 0x801BEC94: nop

;}
RECOMP_FUNC void Solar_801A4214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4214: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801A4218: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801A421C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A4220: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801A4224: lh          $t6, 0x60($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X60);
    // 0x801A4228: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A422C: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x801A4230: bgtzl       $t6, L_801A48A8
    if (SIGNED(ctx->r14) > 0) {
        // 0x801A4234: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801A48A8;
    }
    goto skip_0;
    // 0x801A4234: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801A4238: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A423C: lwc1        $f2, 0x1718($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1718);
    // 0x801A4240: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801A4244: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A4248: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801A424C: jal         0x8009BD38
    // 0x801A4250: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_0;
    // 0x801A4250: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x801A4254: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A4258: lwc1        $f2, 0x171C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X171C);
    // 0x801A425C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x801A4260: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x801A4264: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801A4268: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801A426C: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801A4270: jal         0x8009BD38
    // 0x801A4274: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_1;
    // 0x801A4274: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x801A4278: lh          $t7, 0x4C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4C);
    // 0x801A427C: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x801A4280: bne         $t7, $at, L_801A42AC
    if (ctx->r15 != ctx->r1) {
        // 0x801A4284: nop
    
            goto L_801A42AC;
    }
    // 0x801A4284: nop

    // 0x801A4288: lh          $t8, 0x8A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8A);
    // 0x801A428C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801A4290: addiu       $t9, $zero, 0x26
    ctx->r25 = ADD32(0, 0X26);
    // 0x801A4294: bne         $t8, $at, L_801A42AC
    if (ctx->r24 != ctx->r1) {
        // 0x801A4298: nop
    
            goto L_801A42AC;
    }
    // 0x801A4298: nop

    // 0x801A429C: sh          $t9, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r25;
    // 0x801A42A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A42A4: lwc1        $f4, 0x1724($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1724);
    // 0x801A42A8: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
L_801A42AC:
    // 0x801A42AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A42B0: lwc1        $f8, 0x1728($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1728);
    // 0x801A42B4: lwc1        $f6, 0xDC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x801A42B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A42BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A42C0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A42C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A42C8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A42CC: jal         0x80005D44
    // 0x801A42D0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801A42D0: nop

    after_2:
    // 0x801A42D4: lwc1        $f16, 0xE0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x801A42D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A42DC: lwc1        $f4, 0x1730($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1730);
    // 0x801A42E0: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x801A42E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A42E8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801A42EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A42F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A42F4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A42F8: jal         0x80005E90
    // 0x801A42FC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A42FC: nop

    after_3:
    // 0x801A4300: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801A4304: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4308: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A430C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A4310: lwc1        $f16, 0x1738($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1738);
    // 0x801A4314: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4318: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A431C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x801A4320: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x801A4324: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x801A4328: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x801A432C: jal         0x80006970
    // 0x801A4330: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x801A4330: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x801A4334: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x801A4338: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A433C: lwc1        $f2, 0x173C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X173C);
    // 0x801A4340: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x801A4344: bne         $at, $zero, L_801A438C
    if (ctx->r1 != 0) {
        // 0x801A4348: lui         $t0, 0x8017
        ctx->r8 = S32(0X8017 << 16);
            goto L_801A438C;
    }
    // 0x801A4348: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801A434C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A4350: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801A4354: lw          $t0, 0x7AF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7AF8);
    // 0x801A4358: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801A435C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801A4360: addiu       $t2, $t2, 0x79A8
    ctx->r10 = ADD32(ctx->r10, 0X79A8);
    // 0x801A4364: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801A4368: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x801A436C: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    // 0x801A4370: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x801A4374: lui         $a3, 0x4020
    ctx->r7 = S32(0X4020 << 16);
    // 0x801A4378: jal         0x8009BC2C
    // 0x801A437C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x801A437C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801A4380: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A4384: lwc1        $f2, 0x1740($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1740);
    // 0x801A4388: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
L_801A438C:
    // 0x801A438C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A4390: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801A4394: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x801A4398: beq         $at, $zero, L_801A48A4
    if (ctx->r1 == 0) {
        // 0x801A439C: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_801A48A4;
    }
    // 0x801A439C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x801A43A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A43A4: addu        $at, $at, $t3
    gpr jr_addend_801A43AC = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801A43A8: lw          $t3, 0x1744($at)
    ctx->r11 = ADD32(ctx->r1, 0X1744);
    // 0x801A43AC: jr          $t3
    // 0x801A43B0: nop

    switch (jr_addend_801A43AC >> 2) {
        case 0: goto L_801A43B4; break;
        case 1: goto L_801A4420; break;
        case 2: goto L_801A457C; break;
        case 3: goto L_801A45E8; break;
        case 4: goto L_801A4870; break;
        default: switch_error(__func__, 0x801A43AC, 0x801C1744);
    }
    // 0x801A43B0: nop

L_801A43B4:
    // 0x801A43B4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801A43B8: addiu       $v1, $v1, 0x2740
    ctx->r3 = ADD32(ctx->r3, 0X2740);
    // 0x801A43BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801A43C0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801A43C4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801A43C8: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x801A43CC: bne         $at, $zero, L_801A43DC
    if (ctx->r1 != 0) {
        // 0x801A43D0: lui         $a1, 0x4334
        ctx->r5 = S32(0X4334 << 16);
            goto L_801A43DC;
    }
    // 0x801A43D0: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x801A43D4: addiu       $t4, $v0, -0x3
    ctx->r12 = ADD32(ctx->r2, -0X3);
    // 0x801A43D8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_801A43DC:
    // 0x801A43DC: lh          $t5, 0x58($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X58);
    // 0x801A43E0: addiu       $at, $zero, 0x4DC6
    ctx->r1 = ADD32(0, 0X4DC6);
    // 0x801A43E4: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801A43E8: bne         $t5, $at, L_801A4410
    if (ctx->r13 != ctx->r1) {
        // 0x801A43EC: lui         $a3, 0x4120
        ctx->r7 = S32(0X4120 << 16);
            goto L_801A4410;
    }
    // 0x801A43EC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A43F0: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x801A43F4: sh          $t8, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r24;
    // 0x801A43F8: sh          $zero, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = 0;
    // 0x801A43FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801A4400: sh          $t7, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r15;
    // 0x801A4404: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A4408: lwc1        $f4, 0x1758($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1758);
    // 0x801A440C: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
L_801A4410:
    // 0x801A4410: jal         0x8009BC2C
    // 0x801A4414: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x801A4414: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x801A4418: b           L_801A48A8
    // 0x801A441C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801A48A8;
    // 0x801A441C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801A4420:
    // 0x801A4420: lh          $t9, 0x4C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4C);
    // 0x801A4424: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x801A4428: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A442C: bne         $t9, $at, L_801A48A4
    if (ctx->r25 != ctx->r1) {
        // 0x801A4430: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_801A48A4;
    }
    // 0x801A4430: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A4434: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x801A4438: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x801A443C: sh          $t0, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r8;
    // 0x801A4440: sh          $t1, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r9;
    // 0x801A4444: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801A4448: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801A444C: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801A4450: lui         $a0, 0x3943
    ctx->r4 = S32(0X3943 << 16);
    // 0x801A4454: sw          $zero, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = 0;
    // 0x801A4458: ori         $a0, $a0, 0x9076
    ctx->r4 = ctx->r4 | 0X9076;
    // 0x801A445C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801A4460: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A4464: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x801A4468: jal         0x80019218
    // 0x801A446C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x801A446C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
    // 0x801A4470: jal         0x80004EB0
    // 0x801A4474: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801A4474: nop

    after_8:
    // 0x801A4478: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A447C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A4480: lui         $at, 0x4292
    ctx->r1 = S32(0X4292 << 16);
    // 0x801A4484: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4488: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A448C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A4490: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x801A4494: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A4498: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801A449C: lwc1        $f10, 0xE0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x801A44A0: lwc1        $f12, 0xE8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x801A44A4: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A44A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A44AC: lw          $a2, 0xF0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XF0);
    // 0x801A44B0: lw          $a3, 0xDC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XDC);
    // 0x801A44B4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A44B8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801A44BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x801A44C0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A44C4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801A44C8: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801A44CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A44D0: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x801A44D4: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x801A44D8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801A44DC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801A44E0: jal         0x801A1E14
    // 0x801A44E4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    Solar_ActorDebris_Spawn(rdram, ctx);
        goto after_9;
    // 0x801A44E4: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x801A44E8: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801A44EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A44F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A44F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A44F8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801A44FC: addiu       $v1, $v1, 0x2768
    ctx->r3 = ADD32(ctx->r3, 0X2768);
    // 0x801A4500: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801A4504: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A4508: swc1        $f18, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f18.u32l;
    // 0x801A450C: swc1        $f4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f4.u32l;
    // 0x801A4510: sw          $v0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r2;
    // 0x801A4514: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A4518: sw          $v0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r2;
    // 0x801A451C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A4520: sw          $v0, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r2;
    // 0x801A4524: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A4528: sw          $v0, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r2;
    // 0x801A452C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A4530: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x801A4534: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A4538: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x801A453C: sw          $t4, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r12;
    // 0x801A4540: jal         0x80042EC0
    // 0x801A4544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Boss_AwardBonus(rdram, ctx);
        goto after_10;
    // 0x801A4544: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801A4548: lh          $t5, 0x90($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X90);
    // 0x801A454C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A4550: lwc1        $f2, 0x1768($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X1768);
    // 0x801A4554: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801A4558: sh          $t6, 0x90($s0)
    MEM_H(0X90, ctx->r16) = ctx->r14;
    // 0x801A455C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801A4560: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801A4564: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x801A4568: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A456C: jal         0x8009BC2C
    // 0x801A4570: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x801A4570: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_11:
    // 0x801A4574: b           L_801A48A8
    // 0x801A4578: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801A48A8;
    // 0x801A4578: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801A457C:
    // 0x801A457C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801A4580: addiu       $v1, $v1, 0x2740
    ctx->r3 = ADD32(ctx->r3, 0X2740);
    // 0x801A4584: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801A4588: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801A458C: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x801A4590: slti        $at, $v0, 0x21
    ctx->r1 = SIGNED(ctx->r2) < 0X21 ? 1 : 0;
    // 0x801A4594: bne         $at, $zero, L_801A45A0
    if (ctx->r1 != 0) {
        // 0x801A4598: addiu       $t7, $v0, -0x3
        ctx->r15 = ADD32(ctx->r2, -0X3);
            goto L_801A45A0;
    }
    // 0x801A4598: addiu       $t7, $v0, -0x3
    ctx->r15 = ADD32(ctx->r2, -0X3);
    // 0x801A459C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_801A45A0:
    // 0x801A45A0: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x801A45A4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A45A8: slti        $at, $t8, 0x21
    ctx->r1 = SIGNED(ctx->r24) < 0X21 ? 1 : 0;
    // 0x801A45AC: bnel        $at, $zero, L_801A45DC
    if (ctx->r1 != 0) {
        // 0x801A45B0: lh          $t1, 0x4E($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X4E);
            goto L_801A45DC;
    }
    goto skip_1;
    // 0x801A45B0: lh          $t1, 0x4E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4E);
    skip_1:
    // 0x801A45B4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801A45B8: jal         0x8009BC2C
    // 0x801A45BC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x801A45BC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x801A45C0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801A45C4: addiu       $v1, $v1, 0x2740
    ctx->r3 = ADD32(ctx->r3, 0X2740);
    // 0x801A45C8: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x801A45CC: addiu       $t0, $t9, -0x4
    ctx->r8 = ADD32(ctx->r25, -0X4);
    // 0x801A45D0: b           L_801A48A4
    // 0x801A45D4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
        goto L_801A48A4;
    // 0x801A45D4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x801A45D8: lh          $t1, 0x4E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4E);
L_801A45DC:
    // 0x801A45DC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801A45E0: b           L_801A48A4
    // 0x801A45E4: sh          $t2, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r10;
        goto L_801A48A4;
    // 0x801A45E4: sh          $t2, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r10;
L_801A45E8:
    // 0x801A45E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A45EC: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801A45F0: slti        $at, $v0, 0xCD
    ctx->r1 = SIGNED(ctx->r2) < 0XCD ? 1 : 0;
    // 0x801A45F4: bne         $at, $zero, L_801A461C
    if (ctx->r1 != 0) {
        // 0x801A45F8: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801A461C;
    }
    // 0x801A45F8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801A45FC: addiu       $v1, $v1, 0x2768
    ctx->r3 = ADD32(ctx->r3, 0X2768);
    // 0x801A4600: lwc1        $f0, 0x14($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X14);
    // 0x801A4604: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A4608: nop

    // 0x801A460C: bc1f        L_801A461C
    if (!c1cs) {
        // 0x801A4610: nop
    
            goto L_801A461C;
    }
    // 0x801A4610: nop

    // 0x801A4614: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801A4618: swc1        $f6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f6.u32l;
L_801A461C:
    // 0x801A461C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801A4620: slti        $at, $v0, 0xCF
    ctx->r1 = SIGNED(ctx->r2) < 0XCF ? 1 : 0;
    // 0x801A4624: bne         $at, $zero, L_801A4648
    if (ctx->r1 != 0) {
        // 0x801A4628: addiu       $v1, $v1, 0x2768
        ctx->r3 = ADD32(ctx->r3, 0X2768);
            goto L_801A4648;
    }
    // 0x801A4628: addiu       $v1, $v1, 0x2768
    ctx->r3 = ADD32(ctx->r3, 0X2768);
    // 0x801A462C: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x801A4630: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A4634: nop

    // 0x801A4638: bc1fl       L_801A464C
    if (!c1cs) {
        // 0x801A463C: slti        $at, $v0, 0xD1
        ctx->r1 = SIGNED(ctx->r2) < 0XD1 ? 1 : 0;
            goto L_801A464C;
    }
    goto skip_2;
    // 0x801A463C: slti        $at, $v0, 0xD1
    ctx->r1 = SIGNED(ctx->r2) < 0XD1 ? 1 : 0;
    skip_2:
    // 0x801A4640: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801A4644: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
L_801A4648:
    // 0x801A4648: slti        $at, $v0, 0xD1
    ctx->r1 = SIGNED(ctx->r2) < 0XD1 ? 1 : 0;
L_801A464C:
    // 0x801A464C: bnel        $at, $zero, L_801A4674
    if (ctx->r1 != 0) {
        // 0x801A4650: slti        $at, $v0, 0xD3
        ctx->r1 = SIGNED(ctx->r2) < 0XD3 ? 1 : 0;
            goto L_801A4674;
    }
    goto skip_3;
    // 0x801A4650: slti        $at, $v0, 0xD3
    ctx->r1 = SIGNED(ctx->r2) < 0XD3 ? 1 : 0;
    skip_3:
    // 0x801A4654: lwc1        $f0, 0x28($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X28);
    // 0x801A4658: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A465C: nop

    // 0x801A4660: bc1fl       L_801A4674
    if (!c1cs) {
        // 0x801A4664: slti        $at, $v0, 0xD3
        ctx->r1 = SIGNED(ctx->r2) < 0XD3 ? 1 : 0;
            goto L_801A4674;
    }
    goto skip_4;
    // 0x801A4664: slti        $at, $v0, 0xD3
    ctx->r1 = SIGNED(ctx->r2) < 0XD3 ? 1 : 0;
    skip_4:
    // 0x801A4668: add.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801A466C: swc1        $f10, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f10.u32l;
    // 0x801A4670: slti        $at, $v0, 0xD3
    ctx->r1 = SIGNED(ctx->r2) < 0XD3 ? 1 : 0;
L_801A4674:
    // 0x801A4674: bnel        $at, $zero, L_801A469C
    if (ctx->r1 != 0) {
        // 0x801A4678: slti        $at, $v0, 0xD5
        ctx->r1 = SIGNED(ctx->r2) < 0XD5 ? 1 : 0;
            goto L_801A469C;
    }
    goto skip_5;
    // 0x801A4678: slti        $at, $v0, 0xD5
    ctx->r1 = SIGNED(ctx->r2) < 0XD5 ? 1 : 0;
    skip_5:
    // 0x801A467C: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801A4680: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A4684: nop

    // 0x801A4688: bc1fl       L_801A469C
    if (!c1cs) {
        // 0x801A468C: slti        $at, $v0, 0xD5
        ctx->r1 = SIGNED(ctx->r2) < 0XD5 ? 1 : 0;
            goto L_801A469C;
    }
    goto skip_6;
    // 0x801A468C: slti        $at, $v0, 0xD5
    ctx->r1 = SIGNED(ctx->r2) < 0XD5 ? 1 : 0;
    skip_6:
    // 0x801A4690: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801A4694: swc1        $f16, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x801A4698: slti        $at, $v0, 0xD5
    ctx->r1 = SIGNED(ctx->r2) < 0XD5 ? 1 : 0;
L_801A469C:
    // 0x801A469C: bnel        $at, $zero, L_801A46C4
    if (ctx->r1 != 0) {
        // 0x801A46A0: slti        $at, $v0, 0xD7
        ctx->r1 = SIGNED(ctx->r2) < 0XD7 ? 1 : 0;
            goto L_801A46C4;
    }
    goto skip_7;
    // 0x801A46A0: slti        $at, $v0, 0xD7
    ctx->r1 = SIGNED(ctx->r2) < 0XD7 ? 1 : 0;
    skip_7:
    // 0x801A46A4: lwc1        $f0, 0x20($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801A46A8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A46AC: nop

    // 0x801A46B0: bc1fl       L_801A46C4
    if (!c1cs) {
        // 0x801A46B4: slti        $at, $v0, 0xD7
        ctx->r1 = SIGNED(ctx->r2) < 0XD7 ? 1 : 0;
            goto L_801A46C4;
    }
    goto skip_8;
    // 0x801A46B4: slti        $at, $v0, 0xD7
    ctx->r1 = SIGNED(ctx->r2) < 0XD7 ? 1 : 0;
    skip_8:
    // 0x801A46B8: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801A46BC: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    // 0x801A46C0: slti        $at, $v0, 0xD7
    ctx->r1 = SIGNED(ctx->r2) < 0XD7 ? 1 : 0;
L_801A46C4:
    // 0x801A46C4: bnel        $at, $zero, L_801A46EC
    if (ctx->r1 != 0) {
        // 0x801A46C8: slti        $at, $v0, 0xD9
        ctx->r1 = SIGNED(ctx->r2) < 0XD9 ? 1 : 0;
            goto L_801A46EC;
    }
    goto skip_9;
    // 0x801A46C8: slti        $at, $v0, 0xD9
    ctx->r1 = SIGNED(ctx->r2) < 0XD9 ? 1 : 0;
    skip_9:
    // 0x801A46CC: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x801A46D0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A46D4: nop

    // 0x801A46D8: bc1fl       L_801A46EC
    if (!c1cs) {
        // 0x801A46DC: slti        $at, $v0, 0xD9
        ctx->r1 = SIGNED(ctx->r2) < 0XD9 ? 1 : 0;
            goto L_801A46EC;
    }
    goto skip_10;
    // 0x801A46DC: slti        $at, $v0, 0xD9
    ctx->r1 = SIGNED(ctx->r2) < 0XD9 ? 1 : 0;
    skip_10:
    // 0x801A46E0: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801A46E4: swc1        $f4, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f4.u32l;
    // 0x801A46E8: slti        $at, $v0, 0xD9
    ctx->r1 = SIGNED(ctx->r2) < 0XD9 ? 1 : 0;
L_801A46EC:
    // 0x801A46EC: bnel        $at, $zero, L_801A4714
    if (ctx->r1 != 0) {
        // 0x801A46F0: slti        $at, $v0, 0xDB
        ctx->r1 = SIGNED(ctx->r2) < 0XDB ? 1 : 0;
            goto L_801A4714;
    }
    goto skip_11;
    // 0x801A46F0: slti        $at, $v0, 0xDB
    ctx->r1 = SIGNED(ctx->r2) < 0XDB ? 1 : 0;
    skip_11:
    // 0x801A46F4: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801A46F8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A46FC: nop

    // 0x801A4700: bc1fl       L_801A4714
    if (!c1cs) {
        // 0x801A4704: slti        $at, $v0, 0xDB
        ctx->r1 = SIGNED(ctx->r2) < 0XDB ? 1 : 0;
            goto L_801A4714;
    }
    goto skip_12;
    // 0x801A4704: slti        $at, $v0, 0xDB
    ctx->r1 = SIGNED(ctx->r2) < 0XDB ? 1 : 0;
    skip_12:
    // 0x801A4708: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801A470C: swc1        $f6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f6.u32l;
    // 0x801A4710: slti        $at, $v0, 0xDB
    ctx->r1 = SIGNED(ctx->r2) < 0XDB ? 1 : 0;
L_801A4714:
    // 0x801A4714: bne         $at, $zero, L_801A4738
    if (ctx->r1 != 0) {
        // 0x801A4718: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801A4738;
    }
    // 0x801A4718: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A471C: lwc1        $f0, 0x10($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X10);
    // 0x801A4720: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A4724: nop

    // 0x801A4728: bc1fl       L_801A473C
    if (!c1cs) {
        // 0x801A472C: slti        $at, $v0, 0xDD
        ctx->r1 = SIGNED(ctx->r2) < 0XDD ? 1 : 0;
            goto L_801A473C;
    }
    goto skip_13;
    // 0x801A472C: slti        $at, $v0, 0xDD
    ctx->r1 = SIGNED(ctx->r2) < 0XDD ? 1 : 0;
    skip_13:
    // 0x801A4730: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x801A4734: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
L_801A4738:
    // 0x801A4738: slti        $at, $v0, 0xDD
    ctx->r1 = SIGNED(ctx->r2) < 0XDD ? 1 : 0;
L_801A473C:
    // 0x801A473C: bne         $at, $zero, L_801A4768
    if (ctx->r1 != 0) {
        // 0x801A4740: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_801A4768;
    }
    // 0x801A4740: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A4744: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x801A4748: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A474C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x801A4750: nop

    // 0x801A4754: bc1fl       L_801A476C
    if (!c1cs) {
        // 0x801A4758: slti        $at, $v0, 0xE2
        ctx->r1 = SIGNED(ctx->r2) < 0XE2 ? 1 : 0;
            goto L_801A476C;
    }
    goto skip_14;
    // 0x801A4758: slti        $at, $v0, 0xE2
    ctx->r1 = SIGNED(ctx->r2) < 0XE2 ? 1 : 0;
    skip_14:
    // 0x801A475C: lwc1        $f10, 0x176C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X176C);
    // 0x801A4760: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x801A4764: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
L_801A4768:
    // 0x801A4768: slti        $at, $v0, 0xE2
    ctx->r1 = SIGNED(ctx->r2) < 0XE2 ? 1 : 0;
L_801A476C:
    // 0x801A476C: bne         $at, $zero, L_801A47A4
    if (ctx->r1 != 0) {
        // 0x801A4770: lui         $a0, 0x2940
        ctx->r4 = S32(0X2940 << 16);
            goto L_801A47A4;
    }
    // 0x801A4770: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x801A4774: lui         $at, 0x43BE
    ctx->r1 = S32(0X43BE << 16);
    // 0x801A4778: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A477C: lwc1        $f0, 0x34($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X34);
    // 0x801A4780: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A4784: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x801A4788: nop

    // 0x801A478C: bc1fl       L_801A47A8
    if (!c1cs) {
        // 0x801A4790: slti        $at, $v0, 0xEE
        ctx->r1 = SIGNED(ctx->r2) < 0XEE ? 1 : 0;
            goto L_801A47A8;
    }
    goto skip_15;
    // 0x801A4790: slti        $at, $v0, 0xEE
    ctx->r1 = SIGNED(ctx->r2) < 0XEE ? 1 : 0;
    skip_15:
    // 0x801A4794: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4798: nop

    // 0x801A479C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801A47A0: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
L_801A47A4:
    // 0x801A47A4: slti        $at, $v0, 0xEE
    ctx->r1 = SIGNED(ctx->r2) < 0XEE ? 1 : 0;
L_801A47A8:
    // 0x801A47A8: bne         $at, $zero, L_801A47BC
    if (ctx->r1 != 0) {
        // 0x801A47AC: ori         $a0, $a0, 0xF026
        ctx->r4 = ctx->r4 | 0XF026;
            goto L_801A47BC;
    }
    // 0x801A47AC: ori         $a0, $a0, 0xF026
    ctx->r4 = ctx->r4 | 0XF026;
    // 0x801A47B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A47B4: nop

    // 0x801A47B8: swc1        $f8, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f8.u32l;
L_801A47BC:
    // 0x801A47BC: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x801A47C0: bne         $v0, $at, L_801A480C
    if (ctx->r2 != ctx->r1) {
        // 0x801A47C4: lui         $a1, 0x8016
        ctx->r5 = S32(0X8016 << 16);
            goto L_801A480C;
    }
    // 0x801A47C4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801A47C8: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x801A47CC: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x801A47D0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801A47D4: addiu       $a1, $a1, 0x4FA4
    ctx->r5 = ADD32(ctx->r5, 0X4FA4);
    // 0x801A47D8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A47DC: jal         0x80019218
    // 0x801A47E0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_13;
    // 0x801A47E0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_13:
    // 0x801A47E4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801A47E8: lw          $t4, 0x7AF8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7AF8);
    // 0x801A47EC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801A47F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A47F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A47F8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801A47FC: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801A4800: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A4804: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801A4808: swc1        $f10, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f10.u32l;
L_801A480C:
    // 0x801A480C: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x801A4810: bne         $v0, $at, L_801A48A4
    if (ctx->r2 != ctx->r1) {
        // 0x801A4814: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_801A48A4;
    }
    // 0x801A4814: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801A4818: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x801A481C: lui         $at, 0xC4C8
    ctx->r1 = S32(0XC4C8 << 16);
    // 0x801A4820: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4824: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801A4828: sh          $t7, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r15;
    // 0x801A482C: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x801A4830: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x801A4834: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
L_801A4838:
    // 0x801A4838: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x801A483C: beq         $t8, $zero, L_801A4850
    if (ctx->r24 == 0) {
        // 0x801A4840: nop
    
            goto L_801A4850;
    }
    // 0x801A4840: nop

    // 0x801A4844: jal         0x80060FBC
    // 0x801A4848: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x801A4848: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_14:
    // 0x801A484C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_801A4850:
    // 0x801A4850: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801A4854: addiu       $t9, $t9, 0x248
    ctx->r25 = ADD32(ctx->r25, 0X248);
    // 0x801A4858: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    // 0x801A485C: bnel        $a0, $t9, L_801A4838
    if (ctx->r4 != ctx->r25) {
        // 0x801A4860: lbu         $t8, 0x0($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X0);
            goto L_801A4838;
    }
    goto skip_16;
    // 0x801A4860: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    skip_16:
    // 0x801A4864: addiu       $t0, $zero, 0x64
    ctx->r8 = ADD32(0, 0X64);
    // 0x801A4868: b           L_801A48A4
    // 0x801A486C: sh          $t0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r8;
        goto L_801A48A4;
    // 0x801A486C: sh          $t0, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r8;
L_801A4870:
    // 0x801A4870: lh          $t1, 0x58($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X58);
    // 0x801A4874: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A4878: lui         $a0, 0x1050
    ctx->r4 = S32(0X1050 << 16);
    // 0x801A487C: bnel        $t1, $at, L_801A48A8
    if (ctx->r9 != ctx->r1) {
        // 0x801A4880: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801A48A8;
    }
    goto skip_17;
    // 0x801A4880: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_17:
    // 0x801A4884: jal         0x800182F4
    // 0x801A4888: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_15;
    // 0x801A4888: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_15:
    // 0x801A488C: lui         $a0, 0x1150
    ctx->r4 = S32(0X1150 << 16);
    // 0x801A4890: jal         0x800182F4
    // 0x801A4894: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_16;
    // 0x801A4894: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_16:
    // 0x801A4898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A489C: jal         0x80060FBC
    // 0x801A48A0: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    Object_Kill(rdram, ctx);
        goto after_17;
    // 0x801A48A0: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    after_17:
L_801A48A4:
    // 0x801A48A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801A48A8:
    // 0x801A48A8: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801A48AC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801A48B0: jr          $ra
    // 0x801A48B4: nop

    return;
    // 0x801A48B4: nop

;}
RECOMP_FUNC void Aquas_AqBacoon_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B42AC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801B42B0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801B42B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801B42B8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x801B42BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801B42C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801B42C4: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x801B42C8: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x801B42CC: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x801B42D0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801B42D4: addiu       $t7, $t7, 0x1A4
    ctx->r15 = ADD32(ctx->r15, 0X1A4);
    // 0x801B42D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801B42DC: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x801B42E0: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x801B42E4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801B42E8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801B42EC: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x801B42F0: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801B42F4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801B42F8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x801B42FC: addiu       $t4, $t4, 0x4230
    ctx->r12 = ADD32(ctx->r12, 0X4230);
    // 0x801B4300: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x801B4304: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801B4308: addu        $t0, $t3, $t4
    ctx->r8 = ADD32(ctx->r11, ctx->r12);
    // 0x801B430C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801B4310: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x801B4314: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x801B4318: slti        $at, $v0, 0x3E8
    ctx->r1 = SIGNED(ctx->r2) < 0X3E8 ? 1 : 0;
    // 0x801B431C: bne         $at, $zero, L_801B4330
    if (ctx->r1 != 0) {
        // 0x801B4320: sw          $zero, 0x50($sp)
        MEM_W(0X50, ctx->r29) = 0;
            goto L_801B4330;
    }
    // 0x801B4320: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x801B4324: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x801B4328: b           L_801B4350
    // 0x801B432C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
        goto L_801B4350;
    // 0x801B432C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
L_801B4330:
    // 0x801B4330: beq         $v0, $zero, L_801B4350
    if (ctx->r2 == 0) {
        // 0x801B4334: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_801B4350;
    }
    // 0x801B4334: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801B4338: lw          $t9, 0x7854($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7854);
    // 0x801B433C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x801B4340: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x801B4344: beq         $t9, $at, L_801B4350
    if (ctx->r25 == ctx->r1) {
        // 0x801B4348: nop
    
            goto L_801B4350;
    }
    // 0x801B4348: nop

    // 0x801B434C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_801B4350:
    // 0x801B4350: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801B4354: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801B4358: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801B435C: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x801B4360: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x801B4364: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801B4368: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801B436C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801B4370: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801B4374: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801B4378: lw          $t2, 0x42A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X42A0);
    // 0x801B437C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x801B4380: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x801B4384: beq         $t2, $at, L_801B43E8
    if (ctx->r10 == ctx->r1) {
        // 0x801B4388: addiu       $at, $zero, 0x1B
        ctx->r1 = ADD32(0, 0X1B);
            goto L_801B43E8;
    }
    // 0x801B4388: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x801B438C: beq         $t3, $at, L_801B43E8
    if (ctx->r11 == ctx->r1) {
        // 0x801B4390: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801B43E8;
    }
    // 0x801B4390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801B4394: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    // 0x801B4398: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801B439C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x801B43A0: jal         0x800B8DD0
    // 0x801B43A4: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801B43A4: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x801B43A8: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801B43AC: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801B43B0: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801B43B4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801B43B8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x801B43BC: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801B43C0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801B43C4: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801B43C8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801B43CC: lw          $t9, 0x42A0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X42A0);
    // 0x801B43D0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801B43D4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x801B43D8: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x801B43DC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801B43E0: b           L_801B446C
    // 0x801B43E4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
        goto L_801B446C;
    // 0x801B43E4: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
L_801B43E8:
    // 0x801B43E8: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x801B43EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801B43F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801B43F4: andi        $t1, $t7, 0x1
    ctx->r9 = ctx->r15 & 0X1;
    // 0x801B43F8: bne         $t1, $zero, L_801B4428
    if (ctx->r9 != 0) {
        // 0x801B43FC: addiu       $a1, $zero, 0x3D
        ctx->r5 = ADD32(0, 0X3D);
            goto L_801B4428;
    }
    // 0x801B43FC: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x801B4400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801B4404: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x801B4408: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801B440C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x801B4410: jal         0x800B8DD0
    // 0x801B4414: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801B4414: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x801B4418: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801B441C: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801B4420: b           L_801B4468
    // 0x801B4424: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
        goto L_801B4468;
    // 0x801B4424: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
L_801B4428:
    // 0x801B4428: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x801B442C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801B4430: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x801B4434: jal         0x800B8DD0
    // 0x801B4438: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x801B4438: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x801B443C: lui         $a2, 0xFA00
    ctx->r6 = S32(0XFA00 << 16);
    // 0x801B4440: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801B4444: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801B4448: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801B444C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801B4450: lui         $t4, 0xFF00
    ctx->r12 = S32(0XFF00 << 16);
    // 0x801B4454: ori         $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 | 0XFF;
    // 0x801B4458: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x801B445C: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x801B4460: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801B4464: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
L_801B4468:
    // 0x801B4468: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
L_801B446C:
    // 0x801B446C: addiu       $t9, $t5, -0x4
    ctx->r25 = ADD32(ctx->r13, -0X4);
    // 0x801B4470: sltiu       $at, $t9, 0x18
    ctx->r1 = ctx->r25 < 0X18 ? 1 : 0;
    // 0x801B4474: beq         $at, $zero, L_801B483C
    if (ctx->r1 == 0) {
        // 0x801B4478: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_801B483C;
    }
    // 0x801B4478: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801B447C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4480: addu        $at, $at, $t9
    gpr jr_addend_801B4488 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801B4484: lw          $t9, 0x1DE4($at)
    ctx->r25 = ADD32(ctx->r1, 0X1DE4);
    // 0x801B4488: jr          $t9
    // 0x801B448C: nop

    switch (jr_addend_801B4488 >> 2) {
        case 0: goto L_801B4490; break;
        case 1: goto L_801B44B4; break;
        case 2: goto L_801B4544; break;
        case 3: goto L_801B4568; break;
        case 4: goto L_801B45C0; break;
        case 5: goto L_801B4618; break;
        case 6: goto L_801B46E4; break;
        case 7: goto L_801B483C; break;
        case 8: goto L_801B472C; break;
        case 9: goto L_801B483C; break;
        case 10: goto L_801B483C; break;
        case 11: goto L_801B4758; break;
        case 12: goto L_801B483C; break;
        case 13: goto L_801B483C; break;
        case 14: goto L_801B47A0; break;
        case 15: goto L_801B483C; break;
        case 16: goto L_801B483C; break;
        case 17: goto L_801B483C; break;
        case 18: goto L_801B47D8; break;
        case 19: goto L_801B483C; break;
        case 20: goto L_801B4824; break;
        case 21: goto L_801B483C; break;
        case 22: goto L_801B483C; break;
        case 23: goto L_801B483C; break;
        default: switch_error(__func__, 0x801B4488, 0x801C1DE4);
    }
    // 0x801B448C: nop

L_801B4490:
    // 0x801B4490: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B4494: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B4498: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x801B449C: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x801B44A0: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x801B44A4: lwc1        $f0, 0xF8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x801B44A8: lwc1        $f2, 0xFC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XFC);
    // 0x801B44AC: b           L_801B483C
    // 0x801B44B0: lwc1        $f12, 0x100($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X100);
        goto L_801B483C;
    // 0x801B44B0: lwc1        $f12, 0x100($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X100);
L_801B44B4:
    // 0x801B44B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801B44B8: jal         0x800B8DD0
    // 0x801B44BC: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801B44BC: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_3:
    // 0x801B44C0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B44C4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801B44C8: addiu       $a1, $a1, -0xEF0
    ctx->r5 = ADD32(ctx->r5, -0XEF0);
    // 0x801B44CC: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B44D0: lui         $a2, 0xFA00
    ctx->r6 = S32(0XFA00 << 16);
    // 0x801B44D4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801B44D8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801B44DC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x801B44E0: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x801B44E4: lh          $t6, 0xA8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XA8);
    // 0x801B44E8: lh          $t9, 0xA6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XA6);
    // 0x801B44EC: lh          $t3, 0xA4($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XA4);
    // 0x801B44F0: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x801B44F4: sll         $t1, $t7, 8
    ctx->r9 = S32(ctx->r15 << 8);
    // 0x801B44F8: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x801B44FC: sll         $t4, $t3, 24
    ctx->r12 = S32(ctx->r11 << 24);
    // 0x801B4500: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801B4504: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x801B4508: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x801B450C: ori         $t2, $t7, 0xFF
    ctx->r10 = ctx->r15 | 0XFF;
    // 0x801B4510: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x801B4514: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801B4518: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801B451C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801B4520: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x801B4524: lwc1        $f8, 0x3C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801B4528: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x801B452C: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x801B4530: swc1        $f10, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f10.u32l;
    // 0x801B4534: lwc1        $f0, 0xE8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x801B4538: lwc1        $f2, 0x104($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X104);
    // 0x801B453C: b           L_801B483C
    // 0x801B4540: lwc1        $f12, 0x120($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X120);
        goto L_801B483C;
    // 0x801B4540: lwc1        $f12, 0x120($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X120);
L_801B4544:
    // 0x801B4544: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B4548: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B454C: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x801B4550: lwc1        $f16, 0x30($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X30);
    // 0x801B4554: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x801B4558: lwc1        $f0, 0xF8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x801B455C: lwc1        $f2, 0xFC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XFC);
    // 0x801B4560: b           L_801B483C
    // 0x801B4564: lwc1        $f12, 0x100($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X100);
        goto L_801B483C;
    // 0x801B4564: lwc1        $f12, 0x100($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X100);
L_801B4568:
    // 0x801B4568: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B456C: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B4570: lwc1        $f18, 0x40($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801B4574: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x801B4578: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801B457C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801B4580: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801B4584: lwc1        $f8, 0xB4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x801B4588: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B458C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801B4590: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B4594: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x801B4598: lwc1        $f18, 0xB4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x801B459C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B45A0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x801B45A4: lwc1        $f8, 0xB4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XB4);
    // 0x801B45A8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801B45AC: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x801B45B0: lwc1        $f0, 0xD0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD0);
    // 0x801B45B4: lwc1        $f2, 0xEC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x801B45B8: b           L_801B483C
    // 0x801B45BC: lwc1        $f12, 0x108($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X108);
        goto L_801B483C;
    // 0x801B45BC: lwc1        $f12, 0x108($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X108);
L_801B45C0:
    // 0x801B45C0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B45C4: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B45C8: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801B45CC: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x801B45D0: lwc1        $f18, 0x4C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x801B45D4: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801B45D8: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801B45DC: lwc1        $f6, 0xB8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x801B45E0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B45E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B45E8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B45EC: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x801B45F0: lwc1        $f16, 0xB8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x801B45F4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B45F8: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801B45FC: lwc1        $f6, 0xB8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x801B4600: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B4604: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801B4608: lwc1        $f0, 0xD4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD4);
    // 0x801B460C: lwc1        $f2, 0xF0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x801B4610: b           L_801B483C
    // 0x801B4614: lwc1        $f12, 0x10C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10C);
        goto L_801B483C;
    // 0x801B4614: lwc1        $f12, 0x10C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X10C);
L_801B4618:
    // 0x801B4618: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B461C: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B4620: lwc1        $f16, 0xBC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x801B4624: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801B4628: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B462C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801B4630: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B4634: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B4638: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x801B463C: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x801B4640: lwc1        $f6, 0xBC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x801B4644: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B4648: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x801B464C: lwc1        $f16, 0xBC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x801B4650: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B4654: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x801B4658: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x801B465C: lwc1        $f0, 0xD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x801B4660: lwc1        $f2, 0xF4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XF4);
    // 0x801B4664: beq         $t1, $zero, L_801B483C
    if (ctx->r9 == 0) {
        // 0x801B4668: lwc1        $f12, 0x110($v0)
        ctx->f12.u32l = MEM_W(ctx->r2, 0X110);
            goto L_801B483C;
    }
    // 0x801B4668: lwc1        $f12, 0x110($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X110);
    // 0x801B466C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801B4670: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x801B4674: jal         0x800B8DD0
    // 0x801B4678: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x801B4678: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x801B467C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801B4680: addiu       $a1, $a1, -0xEF0
    ctx->r5 = ADD32(ctx->r5, -0XEF0);
    // 0x801B4684: lh          $t4, 0x60($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X60);
    // 0x801B4688: lui         $a2, 0xFA00
    ctx->r6 = S32(0XFA00 << 16);
    // 0x801B468C: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801B4690: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801B4694: beq         $t4, $zero, L_801B46C0
    if (ctx->r12 == 0) {
        // 0x801B4698: lwc1        $f12, 0x54($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
            goto L_801B46C0;
    }
    // 0x801B4698: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801B469C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801B46A0: lui         $t8, 0xFF00
    ctx->r24 = S32(0XFF00 << 16);
    // 0x801B46A4: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x801B46A8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801B46AC: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801B46B0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801B46B4: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x801B46B8: b           L_801B4840
    // 0x801B46BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B4840;
    // 0x801B46BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B46C0:
    // 0x801B46C0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801B46C4: lui         $t6, 0xFF00
    ctx->r14 = S32(0XFF00 << 16);
    // 0x801B46C8: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x801B46CC: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x801B46D0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x801B46D4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801B46D8: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x801B46DC: b           L_801B4840
    // 0x801B46E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
        goto L_801B4840;
    // 0x801B46E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B46E4:
    // 0x801B46E4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B46E8: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B46EC: lwc1        $f6, 0xC0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x801B46F0: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801B46F4: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B46F8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B46FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B4700: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x801B4704: lwc1        $f16, 0xC0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x801B4708: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801B470C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x801B4710: lwc1        $f6, 0xC0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC0);
    // 0x801B4714: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B4718: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x801B471C: lwc1        $f0, 0xDC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XDC);
    // 0x801B4720: lwc1        $f2, 0xF8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XF8);
    // 0x801B4724: b           L_801B483C
    // 0x801B4728: lwc1        $f12, 0x114($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X114);
        goto L_801B483C;
    // 0x801B4728: lwc1        $f12, 0x114($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X114);
L_801B472C:
    // 0x801B472C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B4730: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B4734: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x801B4738: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x801B473C: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x801B4740: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x801B4744: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x801B4748: lwc1        $f0, 0xF8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x801B474C: lwc1        $f2, 0xFC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XFC);
    // 0x801B4750: b           L_801B483C
    // 0x801B4754: lwc1        $f12, 0x100($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X100);
        goto L_801B483C;
    // 0x801B4754: lwc1        $f12, 0x100($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X100);
L_801B4758:
    // 0x801B4758: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B475C: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B4760: lwc1        $f4, 0xC4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x801B4764: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801B4768: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B476C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B4770: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B4774: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x801B4778: lwc1        $f10, 0xC4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x801B477C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B4780: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x801B4784: lwc1        $f4, 0xC4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC4);
    // 0x801B4788: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B478C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801B4790: lwc1        $f0, 0xE0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XE0);
    // 0x801B4794: lwc1        $f2, 0xFC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XFC);
    // 0x801B4798: b           L_801B483C
    // 0x801B479C: lwc1        $f12, 0x118($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X118);
        goto L_801B483C;
    // 0x801B479C: lwc1        $f12, 0x118($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X118);
L_801B47A0:
    // 0x801B47A0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B47A4: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B47A8: lwc1        $f10, 0xC8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x801B47AC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B47B0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B47B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B47B8: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x801B47BC: lwc1        $f4, 0xC8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC8);
    // 0x801B47C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B47C4: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x801B47C8: lwc1        $f0, 0xE4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XE4);
    // 0x801B47CC: lwc1        $f2, 0x100($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X100);
    // 0x801B47D0: b           L_801B483C
    // 0x801B47D4: lwc1        $f12, 0x11C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X11C);
        goto L_801B483C;
    // 0x801B47D4: lwc1        $f12, 0x11C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X11C);
L_801B47D8:
    // 0x801B47D8: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B47DC: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B47E0: lwc1        $f10, 0xCC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XCC);
    // 0x801B47E4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801B47E8: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x801B47EC: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B47F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B47F4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B47F8: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x801B47FC: lwc1        $f4, 0xCC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XCC);
    // 0x801B4800: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B4804: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x801B4808: lwc1        $f10, 0xCC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XCC);
    // 0x801B480C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B4810: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x801B4814: lwc1        $f0, 0xF8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XF8);
    // 0x801B4818: lwc1        $f2, 0xFC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XFC);
    // 0x801B481C: b           L_801B483C
    // 0x801B4820: lwc1        $f12, 0x100($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X100);
        goto L_801B483C;
    // 0x801B4820: lwc1        $f12, 0x100($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X100);
L_801B4824:
    // 0x801B4824: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801B4828: addiu       $v0, $v0, 0x4308
    ctx->r2 = ADD32(ctx->r2, 0X4308);
    // 0x801B482C: lwc1        $f18, 0x28($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801B4830: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x801B4834: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x801B4838: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_801B483C:
    // 0x801B483C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801B4840:
    // 0x801B4840: nop

    // 0x801B4844: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801B4848: nop

    // 0x801B484C: bc1fl       L_801B49C8
    if (!c1cs) {
        // 0x801B4850: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801B49C8;
    }
    goto skip_0;
    // 0x801B4850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801B4854: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x801B4858: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B485C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801B4860: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x801B4864: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801B4868: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x801B486C: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    // 0x801B4870: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x801B4874: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801B4878: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801B487C: jal         0x80005B00
    // 0x801B4880: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x801B4880: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_5:
    // 0x801B4884: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B4888: lwc1        $f10, 0x1E44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1E44);
    // 0x801B488C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B4890: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B4894: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B4898: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801B489C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B48A0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B48A4: jal         0x80005FE0
    // 0x801B48A8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x801B48A8: nop

    after_6:
    // 0x801B48AC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B48B0: lwc1        $f4, 0x1E48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1E48);
    // 0x801B48B4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B48B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B48BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B48C0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801B48C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B48C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801B48CC: jal         0x80005E90
    // 0x801B48D0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x801B48D0: nop

    after_7:
    // 0x801B48D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B48D8: lwc1        $f10, 0x1E4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1E4C);
    // 0x801B48DC: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801B48E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B48E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B48E8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801B48EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B48F0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B48F4: jal         0x80005D44
    // 0x801B48F8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x801B48F8: nop

    after_8:
    // 0x801B48FC: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x801B4900: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801B4904: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801B4908: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x801B490C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801B4910: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
    // 0x801B4914: beq         $t3, $zero, L_801B49BC
    if (ctx->r11 == 0) {
        // 0x801B4918: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801B49BC;
    }
    // 0x801B4918: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B491C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B4920: addiu       $a1, $sp, 0x6C
    ctx->r5 = ADD32(ctx->r29, 0X6C);
    // 0x801B4924: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x801B4928: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801B492C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x801B4930: jal         0x80006970
    // 0x801B4934: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_9;
    // 0x801B4934: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x801B4938: jal         0x8005F670
    // 0x801B493C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_SetSecondLight(rdram, ctx);
        goto after_10;
    // 0x801B493C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801B4940: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801B4944: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801B4948: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801B494C: lw          $a1, -0x4438($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4438);
    // 0x801B4950: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801B4954: jal         0x80005754
    // 0x801B4958: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_11;
    // 0x801B4958: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_11:
    // 0x801B495C: jal         0x80005708
    // 0x801B4960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_12;
    // 0x801B4960: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801B4964: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801B4968: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801B496C: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x801B4970: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801B4974: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801B4978: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x801B497C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x801B4980: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801B4984: jal         0x80005C34
    // 0x801B4988: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_13;
    // 0x801B4988: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_13:
    // 0x801B498C: jal         0x80006EB8
    // 0x801B4990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x801B4990: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x801B4994: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801B4998: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801B499C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x801B49A0: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801B49A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801B49A8: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x801B49AC: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x801B49B0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x801B49B4: jal         0x80005740
    // 0x801B49B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_15;
    // 0x801B49B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_801B49BC:
    // 0x801B49BC: b           L_801B49C8
    // 0x801B49C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801B49C8;
    // 0x801B49C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801B49C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801B49C8:
    // 0x801B49C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801B49CC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801B49D0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801B49D4: jr          $ra
    // 0x801B49D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801B49D8: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Aquas_AqBoulder_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BAD7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801BAD80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801BAD84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801BAD88: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x801BAD8C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BAD90: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801BAD94: lwc1        $f0, 0x110($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X110);
    // 0x801BAD98: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801BAD9C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801BADA0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801BADA4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801BADA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801BADAC: jal         0x80005C34
    // 0x801BADB0: nop

    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x801BADB0: nop

    after_0:
    // 0x801BADB4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801BADB8: jal         0x80006EB8
    // 0x801BADBC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x801BADBC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x801BADC0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801BADC4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801BADC8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801BADCC: lui         $t0, 0x601
    ctx->r8 = S32(0X601 << 16);
    // 0x801BADD0: addiu       $t0, $t0, 0x4FD0
    ctx->r8 = ADD32(ctx->r8, 0X4FD0);
    // 0x801BADD4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801BADD8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x801BADDC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801BADE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801BADE4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x801BADE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801BADEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801BADF0: jr          $ra
    // 0x801BADF4: nop

    return;
    // 0x801BADF4: nop

;}
RECOMP_FUNC void Zoness_ZoMine_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199E24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80199E28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80199E2C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80199E30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80199E34: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80199E38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80199E3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80199E40: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80199E44: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80199E48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80199E4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80199E50: jal         0x80005C34
    // 0x80199E54: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x80199E54: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x80199E58: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80199E5C: jal         0x80006EB8
    // 0x80199E60: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x80199E60: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_1:
    // 0x80199E64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80199E68: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80199E6C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80199E70: lui         $t9, 0x602
    ctx->r25 = S32(0X602 << 16);
    // 0x80199E74: addiu       $t9, $t9, 0x5E60
    ctx->r25 = ADD32(ctx->r25, 0X5E60);
    // 0x80199E78: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80199E7C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80199E80: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80199E84: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80199E88: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80199E8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80199E90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80199E94: jr          $ra
    // 0x80199E98: nop

    return;
    // 0x80199E98: nop

;}
RECOMP_FUNC void Aquas_AqSquid_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B91A4: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x801B91A8: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x801B91AC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801B91B0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x801B91B4: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x801B91B8: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x801B91BC: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x801B91C0: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x801B91C4: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x801B91C8: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x801B91CC: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x801B91D0: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801B91D4: addiu       $t7, $t7, 0x314
    ctx->r15 = ADD32(ctx->r15, 0X314);
    // 0x801B91D8: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801B91DC: addiu       $t6, $sp, 0xDC
    ctx->r14 = ADD32(ctx->r29, 0XDC);
    // 0x801B91E0: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801B91E4: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801B91E8: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801B91EC: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801B91F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B91F4: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801B91F8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B91FC: lwc1        $f6, 0x2098($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2098);
    // 0x801B9200: lwc1        $f4, 0x14($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801B9204: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B9208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B920C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801B9210: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801B9214: jal         0x80005E90
    // 0x801B9218: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x801B9218: nop

    after_0:
    // 0x801B921C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9220: lwc1        $f16, 0x209C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X209C);
    // 0x801B9224: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x801B9228: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B922C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B9230: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B9234: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B9238: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801B923C: jal         0x80005D44
    // 0x801B9240: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801B9240: nop

    after_1:
    // 0x801B9244: lh          $t1, 0xCE($s2)
    ctx->r9 = MEM_H(ctx->r18, 0XCE);
    // 0x801B9248: bnel        $t1, $zero, L_801B9460
    if (ctx->r9 != 0) {
        // 0x801B924C: lh          $v0, 0xB8($s2)
        ctx->r2 = MEM_H(ctx->r18, 0XB8);
            goto L_801B9460;
    }
    goto skip_0;
    // 0x801B924C: lh          $v0, 0xB8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XB8);
    skip_0:
    // 0x801B9250: lh          $t2, 0xB8($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XB8);
    // 0x801B9254: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801B9258: blezl       $t2, L_801B9460
    if (SIGNED(ctx->r10) <= 0) {
        // 0x801B925C: lh          $v0, 0xB8($s2)
        ctx->r2 = MEM_H(ctx->r18, 0XB8);
            goto L_801B9460;
    }
    goto skip_1;
    // 0x801B925C: lh          $v0, 0xB8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XB8);
    skip_1:
    // 0x801B9260: jal         0x80066254
    // 0x801B9264: sb          $zero, 0x44($s2)
    MEM_B(0X44, ctx->r18) = 0;
    Actor_Despawn(rdram, ctx);
        goto after_2;
    // 0x801B9264: sb          $zero, 0x44($s2)
    MEM_B(0X44, ctx->r18) = 0;
    after_2:
    // 0x801B9268: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801B926C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801B9270: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801B9274:
    // 0x801B9274: jal         0x80004EB0
    // 0x801B9278: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801B9278: nop

    after_3:
    // 0x801B927C: jal         0x80004EB0
    // 0x801B9280: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801B9280: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x801B9284: jal         0x80004EB0
    // 0x801B9288: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801B9288: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_5:
    // 0x801B928C: jal         0x80004EB0
    // 0x801B9290: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801B9290: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x801B9294: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x801B9298: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801B929C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B92A0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801B92A4: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801B92A8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801B92AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B92B0: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B92B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801B92B8: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x801B92BC: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x801B92C0: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801B92C4: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B92C8: mul.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x801B92CC: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B92D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B92D4: mul.s       $f6, $f22, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x801B92D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B92DC: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B92E0: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x801B92E4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801B92E8: add.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801B92EC: lwc1        $f10, 0x20A0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X20A0);
    // 0x801B92F0: mul.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x801B92F4: nop

    // 0x801B92F8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801B92FC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801B9300: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x801B9304: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801B9308: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801B930C: jal         0x80081A8C
    // 0x801B9310: nop

    func_effect_80081A8C(rdram, ctx);
        goto after_7;
    // 0x801B9310: nop

    after_7:
    // 0x801B9314: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801B9318: slti        $at, $s1, 0x5
    ctx->r1 = SIGNED(ctx->r17) < 0X5 ? 1 : 0;
    // 0x801B931C: bne         $at, $zero, L_801B9274
    if (ctx->r1 != 0) {
        // 0x801B9320: nop
    
            goto L_801B9274;
    }
    // 0x801B9320: nop

    // 0x801B9324: jal         0x80004EB0
    // 0x801B9328: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801B9328: nop

    after_8:
    // 0x801B932C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801B9330: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B9334: nop

    // 0x801B9338: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801B933C: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801B9340: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x801B9344: nop

    // 0x801B9348: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x801B934C: beq         $at, $zero, L_801B9424
    if (ctx->r1 == 0) {
        // 0x801B9350: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_801B9424;
    }
    // 0x801B9350: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801B9354: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x801B9358: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x801B935C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801B9360: addu        $s0, $s2, $t5
    ctx->r16 = ADD32(ctx->r18, ctx->r13);
    // 0x801B9364: addiu       $s3, $s0, 0x18C
    ctx->r19 = ADD32(ctx->r16, 0X18C);
    // 0x801B9368: addiu       $s4, $s0, 0x228
    ctx->r20 = ADD32(ctx->r16, 0X228);
L_801B936C:
    // 0x801B936C: jal         0x80004EB0
    // 0x801B9370: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801B9370: nop

    after_9:
    // 0x801B9374: jal         0x80004EB0
    // 0x801B9378: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801B9378: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_10:
    // 0x801B937C: jal         0x80004EB0
    // 0x801B9380: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x801B9380: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_11:
    // 0x801B9384: sub.s       $f10, $f22, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x801B9388: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801B938C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B9390: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801B9394: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B9398: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B939C: sub.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x801B93A0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801B93A4: mul.s       $f8, $f20, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x801B93A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801B93AC: addiu       $t9, $zero, 0x35
    ctx->r25 = ADD32(0, 0X35);
    // 0x801B93B0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801B93B4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x801B93B8: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801B93BC: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x801B93C0: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801B93C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801B93C8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x801B93CC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801B93D0: lwc1        $f18, 0x110($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X110);
    // 0x801B93D4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801B93D8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801B93DC: jal         0x801A9448
    // 0x801B93E0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    Aquas_SpawnDebris(rdram, ctx);
        goto after_12;
    // 0x801B93E0: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_12:
    // 0x801B93E4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801B93E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B93EC: lwc1        $f4, 0x194($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X194);
    // 0x801B93F0: lwc1        $f12, 0x18C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x801B93F4: lwc1        $f14, 0x190($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X190);
    // 0x801B93F8: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801B93FC: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x801B9400: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801B9404: jal         0x8007BC7C
    // 0x801B9408: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_13;
    // 0x801B9408: nop

    after_13:
    // 0x801B940C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801B9410: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801B9414: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x801B9418: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x801B941C: bne         $s1, $at, L_801B936C
    if (ctx->r17 != ctx->r1) {
        // 0x801B9420: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_801B936C;
    }
    // 0x801B9420: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
L_801B9424:
    // 0x801B9424: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801B9428: jal         0x80060FBC
    // 0x801B942C: addiu       $a1, $s2, 0x100
    ctx->r5 = ADD32(ctx->r18, 0X100);
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x801B942C: addiu       $a1, $s2, 0x100
    ctx->r5 = ADD32(ctx->r18, 0X100);
    after_14:
    // 0x801B9430: jal         0x800815DC
    // 0x801B9434: nop

    func_effect_800815DC(rdram, ctx);
        goto after_15;
    // 0x801B9434: nop

    after_15:
    // 0x801B9438: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B943C: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B9440: lw          $a2, 0xC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0XC);
    // 0x801B9444: jal         0x8007D0E0
    // 0x801B9448: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_16;
    // 0x801B9448: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_16:
    // 0x801B944C: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x801B9450: ori         $a1, $a1, 0x8090
    ctx->r5 = ctx->r5 | 0X8090;
    // 0x801B9454: jal         0x8007A6F0
    // 0x801B9458: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_17;
    // 0x801B9458: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_17:
    // 0x801B945C: lh          $v0, 0xB8($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XB8);
L_801B9460:
    // 0x801B9460: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801B9464: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801B9468: beq         $v0, $zero, L_801B948C
    if (ctx->r2 == 0) {
        // 0x801B946C: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_801B948C;
    }
    // 0x801B946C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801B9470: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801B9474: beq         $v0, $at, L_801B96AC
    if (ctx->r2 == ctx->r1) {
        // 0x801B9478: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801B96AC;
    }
    // 0x801B9478: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801B947C: beql        $v0, $at, L_801B99A8
    if (ctx->r2 == ctx->r1) {
        // 0x801B9480: lh          $t1, 0xB6($s2)
        ctx->r9 = MEM_H(ctx->r18, 0XB6);
            goto L_801B99A8;
    }
    goto skip_2;
    // 0x801B9480: lh          $t1, 0xB6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0XB6);
    skip_2:
    // 0x801B9484: b           L_801B9CB0
    // 0x801B9488: lb          $t5, 0xD0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XD0);
        goto L_801B9CB0;
    // 0x801B9488: lb          $t5, 0xD0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XD0);
L_801B948C:
    // 0x801B948C: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B9490: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B9494: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B9498: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x801B949C: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801B94A0: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x801B94A4: addiu       $s0, $s2, 0xC
    ctx->r16 = ADD32(ctx->r18, 0XC);
    // 0x801B94A8: swc1        $f10, 0x18C($s2)
    MEM_W(0X18C, ctx->r18) = ctx->f10.u32l;
    // 0x801B94AC: swc1        $f16, 0x190($s2)
    MEM_W(0X190, ctx->r18) = ctx->f16.u32l;
    // 0x801B94B0: swc1        $f18, 0x194($s2)
    MEM_W(0X194, ctx->r18) = ctx->f18.u32l;
    // 0x801B94B4: swc1        $f4, 0x228($s2)
    MEM_W(0X228, ctx->r18) = ctx->f4.u32l;
    // 0x801B94B8: swc1        $f8, 0x22C($s2)
    MEM_W(0X22C, ctx->r18) = ctx->f8.u32l;
    // 0x801B94BC: swc1        $f6, 0x230($s2)
    MEM_W(0X230, ctx->r18) = ctx->f6.u32l;
L_801B94C0:
    // 0x801B94C0: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B94C4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801B94C8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801B94CC: swc1        $f10, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f10.u32l;
    // 0x801B94D0: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B94D4: addiu       $s0, $s0, 0x30
    ctx->r16 = ADD32(ctx->r16, 0X30);
    // 0x801B94D8: swc1        $f16, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f16.u32l;
    // 0x801B94DC: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B94E0: swc1        $f18, 0x164($s0)
    MEM_W(0X164, ctx->r16) = ctx->f18.u32l;
    // 0x801B94E4: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x801B94E8: swc1        $f4, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->f4.u32l;
    // 0x801B94EC: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801B94F0: swc1        $f8, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->f8.u32l;
    // 0x801B94F4: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x801B94F8: swc1        $f6, 0x200($s0)
    MEM_W(0X200, ctx->r16) = ctx->f6.u32l;
    // 0x801B94FC: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B9500: swc1        $f10, 0x168($s0)
    MEM_W(0X168, ctx->r16) = ctx->f10.u32l;
    // 0x801B9504: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B9508: swc1        $f16, 0x16C($s0)
    MEM_W(0X16C, ctx->r16) = ctx->f16.u32l;
    // 0x801B950C: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B9510: swc1        $f18, 0x170($s0)
    MEM_W(0X170, ctx->r16) = ctx->f18.u32l;
    // 0x801B9514: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x801B9518: swc1        $f4, 0x204($s0)
    MEM_W(0X204, ctx->r16) = ctx->f4.u32l;
    // 0x801B951C: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801B9520: swc1        $f8, 0x208($s0)
    MEM_W(0X208, ctx->r16) = ctx->f8.u32l;
    // 0x801B9524: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x801B9528: swc1        $f6, 0x20C($s0)
    MEM_W(0X20C, ctx->r16) = ctx->f6.u32l;
    // 0x801B952C: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B9530: swc1        $f10, 0x174($s0)
    MEM_W(0X174, ctx->r16) = ctx->f10.u32l;
    // 0x801B9534: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B9538: swc1        $f16, 0x178($s0)
    MEM_W(0X178, ctx->r16) = ctx->f16.u32l;
    // 0x801B953C: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B9540: swc1        $f18, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = ctx->f18.u32l;
    // 0x801B9544: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x801B9548: swc1        $f4, 0x210($s0)
    MEM_W(0X210, ctx->r16) = ctx->f4.u32l;
    // 0x801B954C: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801B9550: swc1        $f8, 0x214($s0)
    MEM_W(0X214, ctx->r16) = ctx->f8.u32l;
    // 0x801B9554: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x801B9558: swc1        $f6, 0x218($s0)
    MEM_W(0X218, ctx->r16) = ctx->f6.u32l;
    // 0x801B955C: lwc1        $f10, 0x4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B9560: swc1        $f10, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->f10.u32l;
    // 0x801B9564: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B9568: swc1        $f16, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f16.u32l;
    // 0x801B956C: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B9570: swc1        $f18, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f18.u32l;
    // 0x801B9574: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x801B9578: swc1        $f4, 0x21C($s0)
    MEM_W(0X21C, ctx->r16) = ctx->f4.u32l;
    // 0x801B957C: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801B9580: swc1        $f8, 0x220($s0)
    MEM_W(0X220, ctx->r16) = ctx->f8.u32l;
    // 0x801B9584: lwc1        $f6, 0x18($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X18);
    // 0x801B9588: bne         $s1, $at, L_801B94C0
    if (ctx->r17 != ctx->r1) {
        // 0x801B958C: swc1        $f6, 0x224($s0)
        MEM_W(0X224, ctx->r16) = ctx->f6.u32l;
            goto L_801B94C0;
    }
    // 0x801B958C: swc1        $f6, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->f6.u32l;
    // 0x801B9590: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801B9594: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B9598: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x801B959C: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B95A0: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801B95A4: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x801B95A8: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x801B95AC: sh          $t6, 0xCE($s2)
    MEM_H(0XCE, ctx->r18) = ctx->r14;
    // 0x801B95B0: sh          $t7, 0xB6($s2)
    MEM_H(0XB6, ctx->r18) = ctx->r15;
    // 0x801B95B4: bc1f        L_801B9638
    if (!c1cs) {
        // 0x801B95B8: swc1        $f10, 0x118($s2)
        MEM_W(0X118, ctx->r18) = ctx->f10.u32l;
            goto L_801B9638;
    }
    // 0x801B95B8: swc1        $f10, 0x118($s2)
    MEM_W(0X118, ctx->r18) = ctx->f10.u32l;
    // 0x801B95BC: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801B95C0: addiu       $v0, $v0, 0x14AC
    ctx->r2 = ADD32(ctx->r2, 0X14AC);
    // 0x801B95C4: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x801B95C8: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x801B95CC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801B95D0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x801B95D4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801B95D8: lw          $t3, 0x1FD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1FD0);
    // 0x801B95DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801B95E0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801B95E4: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x801B95E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801B95EC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801B95F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801B95F4: addu        $t9, $t5, $at
    ctx->r25 = ADD32(ctx->r13, ctx->r1);
    // 0x801B95F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801B95FC: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B9600: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B9604: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x801B9608: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801B960C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801B9610: sw          $t9, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r25;
    // 0x801B9614: sh          $t8, 0xCE($s2)
    MEM_H(0XCE, ctx->r18) = ctx->r24;
    // 0x801B9618: sb          $t6, 0x3C($s2)
    MEM_B(0X3C, ctx->r18) = ctx->r14;
    // 0x801B961C: sh          $t7, 0xB8($s2)
    MEM_H(0XB8, ctx->r18) = ctx->r15;
    // 0x801B9620: swc1        $f0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f0.u32l;
    // 0x801B9624: swc1        $f0, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f0.u32l;
    // 0x801B9628: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    // 0x801B962C: swc1        $f18, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->f18.u32l;
    // 0x801B9630: b           L_801B9CAC
    // 0x801B9634: swc1        $f4, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f4.u32l;
        goto L_801B9CAC;
    // 0x801B9634: swc1        $f4, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f4.u32l;
L_801B9638:
    // 0x801B9638: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801B963C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B9640: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801B9644: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801B9648: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801B964C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801B9650: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B9654: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B9658: bc1f        L_801B9668
    if (!c1cs) {
        // 0x801B965C: addiu       $a1, $sp, 0xC4
        ctx->r5 = ADD32(ctx->r29, 0XC4);
            goto L_801B9668;
    }
    // 0x801B965C: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x801B9660: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801B9664: sw          $t0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->r8;
L_801B9668:
    // 0x801B9668: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x801B966C: swc1        $f10, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f10.u32l;
    // 0x801B9670: swc1        $f16, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f16.u32l;
    // 0x801B9674: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B9678: jal         0x80006A20
    // 0x801B967C: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_18;
    // 0x801B967C: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    after_18:
    // 0x801B9680: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x801B9684: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801B9688: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801B968C: swc1        $f18, 0x124($s2)
    MEM_W(0X124, ctx->r18) = ctx->f18.u32l;
    // 0x801B9690: lwc1        $f4, 0xBC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x801B9694: swc1        $f4, 0x128($s2)
    MEM_W(0X128, ctx->r18) = ctx->f4.u32l;
    // 0x801B9698: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x801B969C: sh          $t1, 0xB8($s2)
    MEM_H(0XB8, ctx->r18) = ctx->r9;
    // 0x801B96A0: swc1        $f6, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f6.u32l;
    // 0x801B96A4: b           L_801B9CAC
    // 0x801B96A8: swc1        $f8, 0x12C($s2)
    MEM_W(0X12C, ctx->r18) = ctx->f8.u32l;
        goto L_801B9CAC;
    // 0x801B96A8: swc1        $f8, 0x12C($s2)
    MEM_W(0X12C, ctx->r18) = ctx->f8.u32l;
L_801B96AC:
    // 0x801B96AC: lh          $t2, 0xB6($s2)
    ctx->r10 = MEM_H(ctx->r18, 0XB6);
    // 0x801B96B0: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x801B96B4: addiu       $a0, $a0, 0xAE4
    ctx->r4 = ADD32(ctx->r4, 0XAE4);
    // 0x801B96B8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801B96BC: jal         0x8009ACDC
    // 0x801B96C0: sh          $t3, 0xB6($s2)
    MEM_H(0XB6, ctx->r18) = ctx->r11;
    Animation_GetFrameCount(rdram, ctx);
        goto after_19;
    // 0x801B96C0: sh          $t3, 0xB6($s2)
    MEM_H(0XB6, ctx->r18) = ctx->r11;
    after_19:
    // 0x801B96C4: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
    // 0x801B96C8: addiu       $a0, $s2, 0xE8
    ctx->r4 = ADD32(ctx->r18, 0XE8);
    // 0x801B96CC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801B96D0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801B96D4: bne         $at, $zero, L_801B96E4
    if (ctx->r1 != 0) {
        // 0x801B96D8: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_801B96E4;
    }
    // 0x801B96D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B96DC: sh          $zero, 0xB6($s2)
    MEM_H(0XB6, ctx->r18) = 0;
    // 0x801B96E0: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
L_801B96E4:
    // 0x801B96E4: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x801B96E8: bne         $v1, $at, L_801B9708
    if (ctx->r3 != ctx->r1) {
        // 0x801B96EC: nop
    
            goto L_801B9708;
    }
    // 0x801B96EC: nop

    // 0x801B96F0: lwc1        $f10, 0x124($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X124);
    // 0x801B96F4: lwc1        $f16, 0x128($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X128);
    // 0x801B96F8: lwc1        $f18, 0x12C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x801B96FC: swc1        $f10, 0xE8($s2)
    MEM_W(0XE8, ctx->r18) = ctx->f10.u32l;
    // 0x801B9700: swc1        $f16, 0xEC($s2)
    MEM_W(0XEC, ctx->r18) = ctx->f16.u32l;
    // 0x801B9704: swc1        $f18, 0xF0($s2)
    MEM_W(0XF0, ctx->r18) = ctx->f18.u32l;
L_801B9708:
    // 0x801B9708: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B970C: lwc1        $f20, 0x20A4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X20A4);
    // 0x801B9710: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9714: lwc1        $f22, 0x20A8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X20A8);
    // 0x801B9718: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801B971C: jal         0x8009BC2C
    // 0x801B9720: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x801B9720: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_20:
    // 0x801B9724: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801B9728: addiu       $a0, $s2, 0xEC
    ctx->r4 = ADD32(ctx->r18, 0XEC);
    // 0x801B972C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801B9730: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B9734: jal         0x8009BC2C
    // 0x801B9738: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x801B9738: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_21:
    // 0x801B973C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801B9740: addiu       $a0, $s2, 0xF0
    ctx->r4 = ADD32(ctx->r18, 0XF0);
    // 0x801B9744: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801B9748: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B974C: jal         0x8009BC2C
    // 0x801B9750: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x801B9750: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_22:
    // 0x801B9754: lw          $t4, 0x54($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X54);
    // 0x801B9758: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801B975C: beql        $t4, $zero, L_801B9780
    if (ctx->r12 == 0) {
        // 0x801B9760: lh          $v1, 0xB6($s2)
        ctx->r3 = MEM_H(ctx->r18, 0XB6);
            goto L_801B9780;
    }
    goto skip_3;
    // 0x801B9760: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
    skip_3:
    // 0x801B9764: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
    // 0x801B9768: andi        $t5, $v1, 0x7
    ctx->r13 = ctx->r3 & 0X7;
    // 0x801B976C: bnel        $t5, $zero, L_801B9794
    if (ctx->r13 != 0) {
        // 0x801B9770: slti        $at, $v1, 0x25
        ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
            goto L_801B9794;
    }
    goto skip_4;
    // 0x801B9770: slti        $at, $v1, 0x25
    ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
    skip_4:
    // 0x801B9774: b           L_801B9790
    // 0x801B9778: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_801B9790;
    // 0x801B9778: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x801B977C: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
L_801B9780:
    // 0x801B9780: andi        $t9, $v1, 0x1
    ctx->r25 = ctx->r3 & 0X1;
    // 0x801B9784: bnel        $t9, $zero, L_801B9794
    if (ctx->r25 != 0) {
        // 0x801B9788: slti        $at, $v1, 0x25
        ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
            goto L_801B9794;
    }
    goto skip_5;
    // 0x801B9788: slti        $at, $v1, 0x25
    ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
    skip_5:
    // 0x801B978C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_801B9790:
    // 0x801B9790: slti        $at, $v1, 0x25
    ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
L_801B9794:
    // 0x801B9794: bnel        $at, $zero, L_801B9CB0
    if (ctx->r1 != 0) {
        // 0x801B9798: lb          $t5, 0xD0($s2)
        ctx->r13 = MEM_B(ctx->r18, 0XD0);
            goto L_801B9CB0;
    }
    goto skip_6;
    // 0x801B9798: lb          $t5, 0xD0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XD0);
    skip_6:
    // 0x801B979C: beq         $s1, $zero, L_801B9CAC
    if (ctx->r17 == 0) {
        // 0x801B97A0: lui         $s0, 0x8018
        ctx->r16 = S32(0X8018 << 16);
            goto L_801B9CAC;
    }
    // 0x801B97A0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801B97A4: addiu       $s0, $s0, -0x7D80
    ctx->r16 = ADD32(ctx->r16, -0X7D80);
    // 0x801B97A8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801B97AC: lwc1        $f8, 0xC($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B97B0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801B97B4: lwc1        $f4, 0x138($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X138);
    // 0x801B97B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B97BC: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801B97C0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801B97C4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801B97C8: nop

    // 0x801B97CC: bc1fl       L_801B9CB0
    if (!c1cs) {
        // 0x801B97D0: lb          $t5, 0xD0($s2)
        ctx->r13 = MEM_B(ctx->r18, 0XD0);
            goto L_801B9CB0;
    }
    goto skip_7;
    // 0x801B97D0: lb          $t5, 0xD0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XD0);
    skip_7:
    // 0x801B97D4: jal         0x80004EB0
    // 0x801B97D8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x801B97D8: nop

    after_23:
    // 0x801B97DC: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x801B97E0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801B97E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B97E8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801B97EC: lwc1        $f6, 0x2C4($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2C4);
    // 0x801B97F0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B97F4: lwc1        $f4, 0x74($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X74);
    // 0x801B97F8: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x801B97FC: jal         0x80004EB0
    // 0x801B9800: sub.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f6.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x801B9800: sub.s       $f20, $f8, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f6.fl;
    after_24:
    // 0x801B9804: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x801B9808: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801B980C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B9810: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x801B9814: lwc1        $f6, 0x2C8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2C8);
    // 0x801B9818: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B981C: lwc1        $f18, 0x78($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X78);
    // 0x801B9820: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B9824: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x801B9828: jal         0x80004EB0
    // 0x801B982C: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_25;
    // 0x801B982C: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
    after_25:
    // 0x801B9830: sub.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x801B9834: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801B9838: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B983C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x801B9840: lwc1        $f10, 0x2CC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X2CC);
    // 0x801B9844: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801B9848: lwc1        $f8, 0x138($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X138);
    // 0x801B984C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x801B9850: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801B9854: sub.s       $f22, $f6, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801B9858: jal         0x80005100
    // 0x801B985C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    Math_Atan2F(rdram, ctx);
        goto after_26;
    // 0x801B985C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_26:
    // 0x801B9860: jal         0x8009F768
    // 0x801B9864: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_27;
    // 0x801B9864: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_27:
    // 0x801B9868: mul.s       $f16, $f20, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x801B986C: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x801B9870: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801B9874: mul.s       $f18, $f22, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x801B9878: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B987C: jal         0x80005100
    // 0x801B9880: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_28;
    // 0x801B9880: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_28:
    // 0x801B9884: jal         0x8009F768
    // 0x801B9888: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_29;
    // 0x801B9888: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_29:
    // 0x801B988C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9890: lwc1        $f8, 0x20AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X20AC);
    // 0x801B9894: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801B9898: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B989C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801B98A0: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x801B98A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B98A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B98AC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801B98B0: jal         0x80005E90
    // 0x801B98B4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_30;
    // 0x801B98B4: nop

    after_30:
    // 0x801B98B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B98BC: lwc1        $f10, 0x20B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X20B0);
    // 0x801B98C0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B98C4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B98C8: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x801B98CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B98D0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B98D4: jal         0x80005D44
    // 0x801B98D8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_31;
    // 0x801B98D8: nop

    after_31:
    // 0x801B98DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801B98E0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801B98E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B98E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B98EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B98F0: addiu       $a1, $sp, 0xC4
    ctx->r5 = ADD32(ctx->r29, 0XC4);
    // 0x801B98F4: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    // 0x801B98F8: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    // 0x801B98FC: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
    // 0x801B9900: jal         0x80006A20
    // 0x801B9904: swc1        $f18, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_32;
    // 0x801B9904: swc1        $f18, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f18.u32l;
    after_32:
    // 0x801B9908: jal         0x80004EB0
    // 0x801B990C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_33;
    // 0x801B990C: nop

    after_33:
    // 0x801B9910: jal         0x80004EB0
    // 0x801B9914: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_34;
    // 0x801B9914: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_34:
    // 0x801B9918: sub.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x801B991C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801B9920: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B9924: sub.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x801B9928: lwc1        $f10, 0x2C4($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X2C4);
    // 0x801B992C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x801B9930: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B9934: lw          $a3, 0x2CC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X2CC);
    // 0x801B9938: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801B993C: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801B9940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801B9944: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x801B9948: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x801B994C: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x801B9950: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801B9954: lwc1        $f6, 0x2C8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2C8);
    // 0x801B9958: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801B995C: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801B9960: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B9964: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B9968: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801B996C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B9970: lwc1        $f4, 0xB4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x801B9974: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801B9978: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x801B997C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x801B9980: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x801B9984: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801B9988: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801B998C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801B9990: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x801B9994: jal         0x8007F04C
    // 0x801B9998: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    Effect_SpawnById2(rdram, ctx);
        goto after_35;
    // 0x801B9998: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    after_35:
    // 0x801B999C: b           L_801B9CB0
    // 0x801B99A0: lb          $t5, 0xD0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XD0);
        goto L_801B9CB0;
    // 0x801B99A0: lb          $t5, 0xD0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XD0);
    // 0x801B99A4: lh          $t1, 0xB6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0XB6);
L_801B99A8:
    // 0x801B99A8: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x801B99AC: addiu       $a0, $a0, 0xAE4
    ctx->r4 = ADD32(ctx->r4, 0XAE4);
    // 0x801B99B0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801B99B4: jal         0x8009ACDC
    // 0x801B99B8: sh          $t2, 0xB6($s2)
    MEM_H(0XB6, ctx->r18) = ctx->r10;
    Animation_GetFrameCount(rdram, ctx);
        goto after_36;
    // 0x801B99B8: sh          $t2, 0xB6($s2)
    MEM_H(0XB6, ctx->r18) = ctx->r10;
    after_36:
    // 0x801B99BC: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
    // 0x801B99C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801B99C4: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x801B99C8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801B99CC: bne         $at, $zero, L_801B99F8
    if (ctx->r1 != 0) {
        // 0x801B99D0: lui         $a2, 0x4120
        ctx->r6 = S32(0X4120 << 16);
            goto L_801B99F8;
    }
    // 0x801B99D0: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x801B99D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801B99D8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B99DC: lwc1        $f10, 0x134($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X134);
    // 0x801B99E0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x801B99E4: nop

    // 0x801B99E8: bc1fl       L_801B99FC
    if (!c1cs) {
        // 0x801B99EC: addiu       $at, $zero, 0x28
        ctx->r1 = ADD32(0, 0X28);
            goto L_801B99FC;
    }
    goto skip_8;
    // 0x801B99EC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    skip_8:
    // 0x801B99F0: sh          $zero, 0xB6($s2)
    MEM_H(0XB6, ctx->r18) = 0;
    // 0x801B99F4: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
L_801B99F8:
    // 0x801B99F8: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
L_801B99FC:
    // 0x801B99FC: bne         $v1, $at, L_801B9A14
    if (ctx->r3 != ctx->r1) {
        // 0x801B9A00: lui         $at, 0x442F
        ctx->r1 = S32(0X442F << 16);
            goto L_801B9A14;
    }
    // 0x801B9A00: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x801B9A04: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B9A08: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801B9A0C: jal         0x801A9728
    // 0x801B9A10: swc1        $f18, 0x134($s2)
    MEM_W(0X134, ctx->r18) = ctx->f18.u32l;
    Aquas_801A9728(rdram, ctx);
        goto after_37;
    // 0x801B9A10: swc1        $f18, 0x134($s2)
    MEM_W(0X134, ctx->r18) = ctx->f18.u32l;
    after_37:
L_801B9A14:
    // 0x801B9A14: lwc1        $f8, 0x134($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X134);
    // 0x801B9A18: lwc1        $f4, 0x130($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X130);
    // 0x801B9A1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9A20: lwc1        $f20, 0x20B4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X20B4);
    // 0x801B9A24: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801B9A28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9A2C: lwc1        $f22, 0x20B8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X20B8);
    // 0x801B9A30: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801B9A34: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801B9A38: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x801B9A3C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B9A40: jal         0x8009BC2C
    // 0x801B9A44: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_38;
    // 0x801B9A44: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_38:
    // 0x801B9A48: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9A4C: lwc1        $f10, 0x20BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X20BC);
    // 0x801B9A50: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801B9A54: addiu       $a0, $s2, 0x134
    ctx->r4 = ADD32(ctx->r18, 0X134);
    // 0x801B9A58: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801B9A5C: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801B9A60: jal         0x8009BC2C
    // 0x801B9A64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_39;
    // 0x801B9A64: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_39:
    // 0x801B9A68: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
    // 0x801B9A6C: slti        $at, $v1, 0x28
    ctx->r1 = SIGNED(ctx->r3) < 0X28 ? 1 : 0;
    // 0x801B9A70: bnel        $at, $zero, L_801B9AF8
    if (ctx->r1 != 0) {
        // 0x801B9A74: slti        $at, $v1, 0x25
        ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
            goto L_801B9AF8;
    }
    goto skip_9;
    // 0x801B9A74: slti        $at, $v1, 0x25
    ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
    skip_9:
    // 0x801B9A78: jal         0x80004EB0
    // 0x801B9A7C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_40;
    // 0x801B9A7C: nop

    after_40:
    // 0x801B9A80: jal         0x80004EB0
    // 0x801B9A84: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_41;
    // 0x801B9A84: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_41:
    // 0x801B9A88: jal         0x80004EB0
    // 0x801B9A8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_42;
    // 0x801B9A8C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_42:
    // 0x801B9A90: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801B9A94: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801B9A98: sub.s       $f16, $f22, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x801B9A9C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801B9AA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B9AA4: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B9AA8: sub.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x801B9AAC: mul.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801B9AB0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801B9AB4: lwc1        $f16, 0x8($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B9AB8: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x801B9ABC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801B9AC0: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x801B9AC4: lwc1        $f16, 0xC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B9AC8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801B9ACC: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801B9AD0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B9AD4: sub.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x801B9AD8: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801B9ADC: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x801B9AE0: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801B9AE4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801B9AE8: jal         0x801AC8A8
    // 0x801B9AEC: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_43;
    // 0x801B9AEC: nop

    after_43:
    // 0x801B9AF0: lh          $v1, 0xB6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XB6);
    // 0x801B9AF4: slti        $at, $v1, 0x25
    ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
L_801B9AF8:
    // 0x801B9AF8: bne         $at, $zero, L_801B9CAC
    if (ctx->r1 != 0) {
        // 0x801B9AFC: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_801B9CAC;
    }
    // 0x801B9AFC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801B9B00: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B9B04: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x801B9B08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B9B0C: lwc1        $f6, 0x11C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X11C);
    // 0x801B9B10: add.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x801B9B14: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x801B9B18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9B1C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801B9B20: swc1        $f4, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f4.u32l;
    // 0x801B9B24: swc1        $f10, 0x11C($s2)
    MEM_W(0X11C, ctx->r18) = ctx->f10.u32l;
    // 0x801B9B28: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x801B9B2C: andi        $t4, $t3, 0x3
    ctx->r12 = ctx->r11 & 0X3;
    // 0x801B9B30: bnel        $t4, $zero, L_801B9CB0
    if (ctx->r12 != 0) {
        // 0x801B9B34: lb          $t5, 0xD0($s2)
        ctx->r13 = MEM_B(ctx->r18, 0XD0);
            goto L_801B9CB0;
    }
    goto skip_10;
    // 0x801B9B34: lb          $t5, 0xD0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XD0);
    skip_10:
    // 0x801B9B38: lwc1        $f18, 0x11C($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X11C);
    // 0x801B9B3C: lwc1        $f8, 0x20C0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X20C0);
    // 0x801B9B40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B9B44: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B9B48: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801B9B4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B9B50: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801B9B54: jal         0x80005E90
    // 0x801B9B58: nop

    Matrix_RotateY(rdram, ctx);
        goto after_44;
    // 0x801B9B58: nop

    after_44:
    // 0x801B9B5C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9B60: lwc1        $f16, 0x20C4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X20C4);
    // 0x801B9B64: lwc1        $f6, 0x2D0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2D0);
    // 0x801B9B68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B9B6C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B9B70: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801B9B74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B9B78: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801B9B7C: jal         0x80005D44
    // 0x801B9B80: nop

    Matrix_RotateX(rdram, ctx);
        goto after_45;
    // 0x801B9B80: nop

    after_45:
    // 0x801B9B84: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B9B88: lwc1        $f8, 0x20C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X20C8);
    // 0x801B9B8C: lwc1        $f18, 0x2D8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X2D8);
    // 0x801B9B90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B9B94: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B9B98: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801B9B9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B9BA0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801B9BA4: jal         0x80005FE0
    // 0x801B9BA8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_46;
    // 0x801B9BA8: nop

    after_46:
    // 0x801B9BAC: jal         0x80004EB0
    // 0x801B9BB0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_47;
    // 0x801B9BB0: nop

    after_47:
    // 0x801B9BB4: jal         0x80004EB0
    // 0x801B9BB8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_48;
    // 0x801B9BB8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_48:
    // 0x801B9BBC: jal         0x80004EB0
    // 0x801B9BC0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_49;
    // 0x801B9BC0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_49:
    // 0x801B9BC4: sub.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x801B9BC8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801B9BCC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B9BD0: lwc1        $f18, 0x210($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X210);
    // 0x801B9BD4: sub.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x801B9BD8: mul.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801B9BDC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801B9BE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B9BE4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801B9BE8: lwc1        $f16, 0x214($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X214);
    // 0x801B9BEC: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x801B9BF0: lwc1        $f4, 0x218($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X218);
    // 0x801B9BF4: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801B9BF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801B9BFC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801B9C00: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x801B9C04: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801B9C08: add.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x801B9C0C: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801B9C10: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801B9C14: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801B9C18: jal         0x801AC8A8
    // 0x801B9C1C: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_50;
    // 0x801B9C1C: nop

    after_50:
    // 0x801B9C20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B9C24: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B9C28: addiu       $a1, $sp, 0xDC
    ctx->r5 = ADD32(ctx->r29, 0XDC);
    // 0x801B9C2C: jal         0x80006A20
    // 0x801B9C30: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_51;
    // 0x801B9C30: addiu       $a2, $sp, 0xD0
    ctx->r6 = ADD32(ctx->r29, 0XD0);
    after_51:
    // 0x801B9C34: lwc1        $f16, 0x2C4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X2C4);
    // 0x801B9C38: lwc1        $f10, 0xD0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x801B9C3C: lwc1        $f8, 0x2C8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X2C8);
    // 0x801B9C40: lwc1        $f4, 0xD4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x801B9C44: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801B9C48: lwc1        $f16, 0x2CC($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X2CC);
    // 0x801B9C4C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801B9C50: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x801B9C54: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801B9C58: lwc1        $f18, 0xD8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x801B9C5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801B9C60: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801B9C64: lwc1        $f6, 0x2D0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2D0);
    // 0x801B9C68: add.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B9C6C: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x801B9C70: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801B9C74: lwc1        $f16, 0x11C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X11C);
    // 0x801B9C78: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801B9C7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B9C80: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801B9C84: lwc1        $f8, 0x2D8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X2D8);
    // 0x801B9C88: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x801B9C8C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801B9C90: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801B9C94: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801B9C98: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801B9C9C: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x801B9CA0: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x801B9CA4: jal         0x8007F04C
    // 0x801B9CA8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_SpawnById2(rdram, ctx);
        goto after_52;
    // 0x801B9CA8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_52:
L_801B9CAC:
    // 0x801B9CAC: lb          $t5, 0xD0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XD0);
L_801B9CB0:
    // 0x801B9CB0: beql        $t5, $zero, L_801B9D88
    if (ctx->r13 == 0) {
        // 0x801B9CB4: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_801B9D88;
    }
    goto skip_11;
    // 0x801B9CB4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_11:
    // 0x801B9CB8: lh          $v0, 0xCE($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XCE);
    // 0x801B9CBC: sb          $zero, 0xD0($s2)
    MEM_B(0XD0, ctx->r18) = 0;
    // 0x801B9CC0: beql        $v0, $zero, L_801B9D88
    if (ctx->r2 == 0) {
        // 0x801B9CC4: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_801B9D88;
    }
    goto skip_12;
    // 0x801B9CC4: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_12:
    // 0x801B9CC8: lh          $t9, 0xB8($s2)
    ctx->r25 = MEM_H(ctx->r18, 0XB8);
    // 0x801B9CCC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801B9CD0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801B9CD4: beq         $t9, $zero, L_801B9D84
    if (ctx->r25 == 0) {
        // 0x801B9CD8: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_801B9D84;
    }
    // 0x801B9CD8: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x801B9CDC: lhu         $t6, 0xD6($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0XD6);
    // 0x801B9CE0: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801B9CE4: sh          $t8, 0xC6($s2)
    MEM_H(0XC6, ctx->r18) = ctx->r24;
    // 0x801B9CE8: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x801B9CEC: sh          $t7, 0xCE($s2)
    MEM_H(0XCE, ctx->r18) = ctx->r15;
    // 0x801B9CF0: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x801B9CF4: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801B9CF8: ori         $a0, $a0, 0x408F
    ctx->r4 = ctx->r4 | 0X408F;
    // 0x801B9CFC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801B9D00: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801B9D04: addiu       $a1, $s2, 0x100
    ctx->r5 = ADD32(ctx->r18, 0X100);
    // 0x801B9D08: jal         0x80019218
    // 0x801B9D0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_53;
    // 0x801B9D0C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_53:
    // 0x801B9D10: lh          $t1, 0xCE($s2)
    ctx->r9 = MEM_H(ctx->r18, 0XCE);
    // 0x801B9D14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801B9D18: bgtzl       $t1, L_801B9D88
    if (SIGNED(ctx->r9) > 0) {
        // 0x801B9D1C: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_801B9D88;
    }
    goto skip_13;
    // 0x801B9D1C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_13:
    // 0x801B9D20: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B9D24: lwc1        $f8, 0x110($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X110);
    // 0x801B9D28: sh          $zero, 0xCE($s2)
    MEM_H(0XCE, ctx->r18) = 0;
    // 0x801B9D2C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801B9D30: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x801B9D34: nop

    // 0x801B9D38: bc1fl       L_801B9D88
    if (!c1cs) {
        // 0x801B9D3C: lw          $ra, 0x6C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X6C);
            goto L_801B9D88;
    }
    goto skip_14;
    // 0x801B9D3C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    skip_14:
    // 0x801B9D40: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801B9D44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B9D48: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801B9D4C: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801B9D50: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801B9D54: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801B9D58: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801B9D5C: jal         0x80077240
    // 0x801B9D60: nop

    BonusText_Display(rdram, ctx);
        goto after_54;
    // 0x801B9D60: nop

    after_54:
    // 0x801B9D64: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x801B9D68: addiu       $v1, $v1, 0x1A98
    ctx->r3 = ADD32(ctx->r3, 0X1A98);
    // 0x801B9D6C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801B9D70: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x801B9D74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801B9D78: addiu       $t3, $t2, 0x2
    ctx->r11 = ADD32(ctx->r10, 0X2);
    // 0x801B9D7C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801B9D80: sw          $t4, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r12;
L_801B9D84:
    // 0x801B9D84: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
L_801B9D88:
    // 0x801B9D88: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x801B9D8C: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x801B9D90: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x801B9D94: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x801B9D98: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x801B9D9C: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x801B9DA0: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x801B9DA4: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x801B9DA8: jr          $ra
    // 0x801B9DAC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x801B9DAC: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void Aquas_AqBacconBarnacle_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B099C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801B09A0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801B09A4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801B09A8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801B09AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801B09B0: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801B09B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801B09B8: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    // 0x801B09BC: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801B09C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B09C4: lwc1        $f10, 0x1CA4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1CA4);
    // 0x801B09C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801B09CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B09D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B09D4: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801B09D8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801B09DC: jal         0x80005E90
    // 0x801B09E0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x801B09E0: nop

    after_0:
    // 0x801B09E4: lwc1        $f18, 0x124($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X124);
    // 0x801B09E8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801B09EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B09F0: lwc1        $f8, 0x1CA8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1CA8);
    // 0x801B09F4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B09F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B09FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B0A00: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801B0A04: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801B0A08: jal         0x80005D44
    // 0x801B0A0C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801B0A0C: nop

    after_1:
    // 0x801B0A10: lwc1        $f16, 0x128($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X128);
    // 0x801B0A14: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801B0A18: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0A1C: lwc1        $f6, 0x1CAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1CAC);
    // 0x801B0A20: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801B0A24: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801B0A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B0A2C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801B0A30: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801B0A34: jal         0x80005FE0
    // 0x801B0A38: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x801B0A38: nop

    after_2:
    // 0x801B0A3C: lw          $a1, 0x114($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X114);
    // 0x801B0A40: lw          $a2, 0x118($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X118);
    // 0x801B0A44: lw          $a3, 0x11C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X11C);
    // 0x801B0A48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801B0A4C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801B0A50: jal         0x80005C34
    // 0x801B0A54: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x801B0A54: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_3:
    // 0x801B0A58: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801B0A5C: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801B0A60: jal         0x80006EB8
    // 0x801B0A64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x801B0A64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801B0A68: lhu         $t7, 0xC6($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC6);
    // 0x801B0A6C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x801B0A70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801B0A74: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x801B0A78: bne         $t8, $zero, L_801B0A90
    if (ctx->r24 != 0) {
        // 0x801B0A7C: nop
    
            goto L_801B0A90;
    }
    // 0x801B0A7C: nop

    // 0x801B0A80: jal         0x800B8DD0
    // 0x801B0A84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x801B0A84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x801B0A88: b           L_801B0ABC
    // 0x801B0A8C: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
        goto L_801B0ABC;
    // 0x801B0A8C: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
L_801B0A90:
    // 0x801B0A90: jal         0x800B8DD0
    // 0x801B0A94: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x801B0A94: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_6:
    // 0x801B0A98: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801B0A9C: lui         $t1, 0xFF00
    ctx->r9 = S32(0XFF00 << 16);
    // 0x801B0AA0: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x801B0AA4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801B0AA8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801B0AAC: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801B0AB0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801B0AB4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801B0AB8: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
L_801B0ABC:
    // 0x801B0ABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801B0AC0: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801B0AC4: beql        $v0, $zero, L_801B0AEC
    if (ctx->r2 == 0) {
        // 0x801B0AC8: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_801B0AEC;
    }
    goto skip_0;
    // 0x801B0AC8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_0:
    // 0x801B0ACC: beq         $v0, $at, L_801B0B0C
    if (ctx->r2 == ctx->r1) {
        // 0x801B0AD0: lui         $t6, 0x600
        ctx->r14 = S32(0X600 << 16);
            goto L_801B0B0C;
    }
    // 0x801B0AD0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x801B0AD4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801B0AD8: beq         $v0, $at, L_801B0B30
    if (ctx->r2 == ctx->r1) {
        // 0x801B0ADC: lui         $t9, 0x600
        ctx->r25 = S32(0X600 << 16);
            goto L_801B0B30;
    }
    // 0x801B0ADC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x801B0AE0: b           L_801B0B50
    // 0x801B0AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801B0B50;
    // 0x801B0AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801B0AE8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_801B0AEC:
    // 0x801B0AEC: lui         $t4, 0x602
    ctx->r12 = S32(0X602 << 16);
    // 0x801B0AF0: addiu       $t4, $t4, -0x6180
    ctx->r12 = ADD32(ctx->r12, -0X6180);
    // 0x801B0AF4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801B0AF8: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x801B0AFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801B0B00: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801B0B04: b           L_801B0B50
    // 0x801B0B08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801B0B50;
    // 0x801B0B08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801B0B0C:
    // 0x801B0B0C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801B0B10: lui         $t7, 0x602
    ctx->r15 = S32(0X602 << 16);
    // 0x801B0B14: addiu       $t7, $t7, -0x6B30
    ctx->r15 = ADD32(ctx->r15, -0X6B30);
    // 0x801B0B18: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801B0B1C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x801B0B20: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801B0B24: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801B0B28: b           L_801B0B50
    // 0x801B0B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801B0B50;
    // 0x801B0B2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801B0B30:
    // 0x801B0B30: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801B0B34: lui         $t0, 0x602
    ctx->r8 = S32(0X602 << 16);
    // 0x801B0B38: addiu       $t0, $t0, -0x6780
    ctx->r8 = ADD32(ctx->r8, -0X6780);
    // 0x801B0B3C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801B0B40: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x801B0B44: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801B0B48: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801B0B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801B0B50:
    // 0x801B0B50: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801B0B54: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801B0B58: jr          $ra
    // 0x801B0B5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801B0B5C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Aquas_AqPearl_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B0B60: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801B0B64: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801B0B68: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801B0B6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801B0B70: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x801B0B74: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801B0B78: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801B0B7C: bnel        $t6, $zero, L_801B0B98
    if (ctx->r14 != 0) {
        // 0x801B0B80: sh          $t8, 0xB8($s0)
        MEM_H(0XB8, ctx->r16) = ctx->r24;
            goto L_801B0B98;
    }
    goto skip_0;
    // 0x801B0B80: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    skip_0:
    // 0x801B0B84: lh          $t7, -0xEA2($t7)
    ctx->r15 = MEM_H(ctx->r15, -0XEA2);
    // 0x801B0B88: slti        $at, $t7, 0x10
    ctx->r1 = SIGNED(ctx->r15) < 0X10 ? 1 : 0;
    // 0x801B0B8C: bnel        $at, $zero, L_801B0B9C
    if (ctx->r1 != 0) {
        // 0x801B0B90: lh          $v0, 0xB8($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB8);
            goto L_801B0B9C;
    }
    goto skip_1;
    // 0x801B0B90: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    skip_1:
    // 0x801B0B94: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
L_801B0B98:
    // 0x801B0B98: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
L_801B0B9C:
    // 0x801B0B9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801B0BA0: beql        $v0, $zero, L_801B0BCC
    if (ctx->r2 == 0) {
        // 0x801B0BA4: lhu         $t9, 0xBC($s0)
        ctx->r25 = MEM_HU(ctx->r16, 0XBC);
            goto L_801B0BCC;
    }
    goto skip_2;
    // 0x801B0BA4: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
    skip_2:
    // 0x801B0BA8: beq         $v0, $at, L_801B0C90
    if (ctx->r2 == ctx->r1) {
        // 0x801B0BAC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801B0C90;
    }
    // 0x801B0BAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801B0BB0: beq         $v0, $at, L_801B0D48
    if (ctx->r2 == ctx->r1) {
        // 0x801B0BB4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801B0D48;
    }
    // 0x801B0BB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801B0BB8: beq         $v0, $at, L_801B0D94
    if (ctx->r2 == ctx->r1) {
        // 0x801B0BBC: nop
    
            goto L_801B0D94;
    }
    // 0x801B0BBC: nop

    // 0x801B0BC0: b           L_801B0E18
    // 0x801B0BC4: nop

        goto L_801B0E18;
    // 0x801B0BC4: nop

    // 0x801B0BC8: lhu         $t9, 0xBC($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0XBC);
L_801B0BCC:
    // 0x801B0BCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0BD0: bne         $t9, $zero, L_801B0E18
    if (ctx->r25 != 0) {
        // 0x801B0BD4: nop
    
            goto L_801B0E18;
    }
    // 0x801B0BD4: nop

    // 0x801B0BD8: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x801B0BDC: lwc1        $f6, 0x1CB0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1CB0);
    // 0x801B0BE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B0BE4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B0BE8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801B0BEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B0BF0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801B0BF4: jal         0x80005E90
    // 0x801B0BF8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x801B0BF8: nop

    after_0:
    // 0x801B0BFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0C00: lwc1        $f18, 0x1CB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1CB4);
    // 0x801B0C04: lwc1        $f10, 0x118($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X118);
    // 0x801B0C08: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B0C0C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B0C10: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801B0C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B0C18: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801B0C1C: jal         0x80005D44
    // 0x801B0C20: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801B0C20: nop

    after_1:
    // 0x801B0C24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801B0C28: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801B0C2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B0C30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B0C34: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B0C38: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801B0C3C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x801B0C40: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x801B0C44: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x801B0C48: jal         0x80006A20
    // 0x801B0C4C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x801B0C4C: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x801B0C50: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801B0C54: lh          $t1, 0xB8($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XB8);
    // 0x801B0C58: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x801B0C5C: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    // 0x801B0C60: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801B0C64: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x801B0C68: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801B0C6C: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x801B0C70: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801B0C74: sh          $t0, 0xBE($s0)
    MEM_H(0XBE, ctx->r16) = ctx->r8;
    // 0x801B0C78: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x801B0C7C: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x801B0C80: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x801B0C84: sh          $t2, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r10;
    // 0x801B0C88: b           L_801B0E18
    // 0x801B0C8C: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
        goto L_801B0E18;
    // 0x801B0C8C: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
L_801B0C90:
    // 0x801B0C90: lhu         $t3, 0xBE($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0XBE);
    // 0x801B0C94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0C98: bne         $t3, $zero, L_801B0E18
    if (ctx->r11 != 0) {
        // 0x801B0C9C: nop
    
            goto L_801B0E18;
    }
    // 0x801B0C9C: nop

    // 0x801B0CA0: lwc1        $f4, 0x124($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X124);
    // 0x801B0CA4: lwc1        $f6, 0x1CB8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1CB8);
    // 0x801B0CA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B0CAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B0CB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801B0CB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801B0CB8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801B0CBC: jal         0x80005E90
    // 0x801B0CC0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801B0CC0: nop

    after_3:
    // 0x801B0CC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0CC8: lwc1        $f18, 0x1CBC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1CBC);
    // 0x801B0CCC: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x801B0CD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B0CD4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B0CD8: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801B0CDC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801B0CE0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801B0CE4: jal         0x80005D44
    // 0x801B0CE8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801B0CE8: nop

    after_4:
    // 0x801B0CEC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801B0CF0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801B0CF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B0CF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B0CFC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B0D00: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801B0D04: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x801B0D08: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x801B0D0C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x801B0D10: jal         0x80006A20
    // 0x801B0D14: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x801B0D14: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x801B0D18: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801B0D1C: lh          $t5, 0xB8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB8);
    // 0x801B0D20: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801B0D24: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    // 0x801B0D28: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801B0D2C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801B0D30: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    // 0x801B0D34: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801B0D38: sh          $t4, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r12;
    // 0x801B0D3C: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
    // 0x801B0D40: b           L_801B0E18
    // 0x801B0D44: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
        goto L_801B0E18;
    // 0x801B0D44: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
L_801B0D48:
    // 0x801B0D48: lhu         $t7, 0xC0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC0);
    // 0x801B0D4C: bne         $t7, $zero, L_801B0E18
    if (ctx->r15 != 0) {
        // 0x801B0D50: nop
    
            goto L_801B0E18;
    }
    // 0x801B0D50: nop

    // 0x801B0D54: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x801B0D58: lw          $t0, 0x58($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X58);
    // 0x801B0D5C: lw          $t2, 0x5C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X5C);
    // 0x801B0D60: addiu       $t9, $t8, -0x14
    ctx->r25 = ADD32(ctx->r24, -0X14);
    // 0x801B0D64: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x801B0D68: addiu       $t1, $t0, -0x14
    ctx->r9 = ADD32(ctx->r8, -0X14);
    // 0x801B0D6C: addiu       $t3, $t2, -0x14
    ctx->r11 = ADD32(ctx->r10, -0X14);
    // 0x801B0D70: sw          $t9, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r25;
    // 0x801B0D74: sw          $t1, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r9;
    // 0x801B0D78: beq         $at, $zero, L_801B0E18
    if (ctx->r1 == 0) {
        // 0x801B0D7C: sw          $t3, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->r11;
            goto L_801B0E18;
    }
    // 0x801B0D7C: sw          $t3, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r11;
    // 0x801B0D80: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801B0D84: sw          $v0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r2;
    // 0x801B0D88: sw          $v0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r2;
    // 0x801B0D8C: b           L_801B0E18
    // 0x801B0D90: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
        goto L_801B0E18;
    // 0x801B0D90: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
L_801B0D94:
    // 0x801B0D94: jal         0x80004EB0
    // 0x801B0D98: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801B0D98: nop

    after_6:
    // 0x801B0D9C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0DA0: ldc1        $f6, 0x1CC0($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, 0X1CC0);
    // 0x801B0DA4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x801B0DA8: addiu       $t5, $zero, 0x16
    ctx->r13 = ADD32(0, 0X16);
    // 0x801B0DAC: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x801B0DB0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801B0DB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801B0DB8: bc1fl       L_801B0DD0
    if (!c1cs) {
        // 0x801B0DBC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801B0DD0;
    }
    goto skip_3;
    // 0x801B0DBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x801B0DC0: sb          $t5, 0x44($s0)
    MEM_B(0X44, ctx->r16) = ctx->r13;
    // 0x801B0DC4: jal         0x80066254
    // 0x801B0DC8: sh          $t6, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r14;
    Actor_Despawn(rdram, ctx);
        goto after_7;
    // 0x801B0DC8: sh          $t6, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r14;
    after_7:
    // 0x801B0DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_801B0DD0:
    // 0x801B0DD0: jal         0x80060FBC
    // 0x801B0DD4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_8;
    // 0x801B0DD4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_8:
    // 0x801B0DD8: jal         0x800815DC
    // 0x801B0DDC: nop

    func_effect_800815DC(rdram, ctx);
        goto after_9;
    // 0x801B0DDC: nop

    after_9:
    // 0x801B0DE0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801B0DE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801B0DE8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801B0DEC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B0DF0: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B0DF4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B0DF8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x801B0DFC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801B0E00: jal         0x8007D0E0
    // 0x801B0E04: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_10;
    // 0x801B0E04: nop

    after_10:
    // 0x801B0E08: lui         $a1, 0x2901
    ctx->r5 = S32(0X2901 << 16);
    // 0x801B0E0C: ori         $a1, $a1, 0x8049
    ctx->r5 = ctx->r5 | 0X8049;
    // 0x801B0E10: jal         0x8007A6F0
    // 0x801B0E14: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_11;
    // 0x801B0E14: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_11:
L_801B0E18:
    // 0x801B0E18: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801B0E1C: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x801B0E20: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x801B0E24: bne         $t8, $zero, L_801B0EA4
    if (ctx->r24 != 0) {
        // 0x801B0E28: nop
    
            goto L_801B0EA4;
    }
    // 0x801B0E28: nop

    // 0x801B0E2C: jal         0x80004EB0
    // 0x801B0E30: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x801B0E30: nop

    after_12:
    // 0x801B0E34: jal         0x80004EB0
    // 0x801B0E38: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x801B0E38: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_13:
    // 0x801B0E3C: jal         0x80004EB0
    // 0x801B0E40: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x801B0E40: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_14:
    // 0x801B0E44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801B0E48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801B0E4C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801B0E50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801B0E54: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801B0E58: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x801B0E5C: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801B0E60: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801B0E64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801B0E68: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x801B0E6C: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x801B0E70: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801B0E74: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801B0E78: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801B0E7C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801B0E80: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801B0E84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801B0E88: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x801B0E8C: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801B0E90: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801B0E94: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801B0E98: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801B0E9C: jal         0x801AC8A8
    // 0x801B0EA0: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_15;
    // 0x801B0EA0: nop

    after_15:
L_801B0EA4:
    // 0x801B0EA4: jal         0x801A96DC
    // 0x801B0EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Aquas_801A96DC(rdram, ctx);
        goto after_16;
    // 0x801B0EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801B0EAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801B0EB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801B0EB4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801B0EB8: jr          $ra
    // 0x801B0EBC: nop

    return;
    // 0x801B0EBC: nop

;}
RECOMP_FUNC void Aquas_801ADF7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ADF7C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801ADF80: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801ADF84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801ADF88: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x801ADF8C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x801ADF90: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801ADF94: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801ADF98: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801ADF9C: jal         0x80005708
    // 0x801ADFA0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801ADFA0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x801ADFA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801ADFA8: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801ADFAC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801ADFB0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801ADFB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801ADFB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801ADFBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801ADFC0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801ADFC4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801ADFC8: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801ADFCC: jal         0x80005B00
    // 0x801ADFD0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x801ADFD0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x801ADFD4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ADFD8: lwc1        $f10, 0x1BFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1BFC);
    // 0x801ADFDC: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801ADFE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801ADFE4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801ADFE8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801ADFEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801ADFF0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801ADFF4: jal         0x80005E90
    // 0x801ADFF8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x801ADFF8: nop

    after_2:
    // 0x801ADFFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE000: lwc1        $f4, 0x1C00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1C00);
    // 0x801AE004: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801AE008: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AE00C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AE010: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AE014: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AE018: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AE01C: jal         0x80005D44
    // 0x801AE020: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x801AE020: nop

    after_3:
    // 0x801AE024: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE028: lwc1        $f10, 0x1C04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1C04);
    // 0x801AE02C: lwc1        $f16, 0x3C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801AE030: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AE034: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AE038: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801AE03C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AE040: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801AE044: jal         0x80005FE0
    // 0x801AE048: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x801AE048: nop

    after_4:
    // 0x801AE04C: jal         0x8005980C
    // 0x801AE050: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_5;
    // 0x801AE050: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x801AE054: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x801AE058: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x801AE05C: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x801AE060: beql        $at, $zero, L_801AE0C8
    if (ctx->r1 == 0) {
        // 0x801AE064: lw          $t2, 0x44($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X44);
            goto L_801AE0C8;
    }
    goto skip_0;
    // 0x801AE064: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x801AE068: bne         $t8, $zero, L_801AE08C
    if (ctx->r24 != 0) {
        // 0x801AE06C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_801AE08C;
    }
    // 0x801AE06C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AE070: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AE074: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AE078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AE07C: jal         0x800B8DD0
    // 0x801AE080: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x801AE080: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_6:
    // 0x801AE084: b           L_801AE120
    // 0x801AE088: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801AE120;
    // 0x801AE088: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801AE08C:
    // 0x801AE08C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AE090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AE094: jal         0x800B8DD0
    // 0x801AE098: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x801AE098: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_7:
    // 0x801AE09C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AE0A0: lui         $t1, 0xFF00
    ctx->r9 = S32(0XFF00 << 16);
    // 0x801AE0A4: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x801AE0A8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AE0AC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801AE0B0: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801AE0B4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801AE0B8: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801AE0BC: b           L_801AE120
    // 0x801AE0C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801AE120;
    // 0x801AE0C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AE0C4: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
L_801AE0C8:
    // 0x801AE0C8: bne         $t2, $zero, L_801AE0E8
    if (ctx->r10 != 0) {
        // 0x801AE0CC: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_801AE0E8;
    }
    // 0x801AE0CC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AE0D0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AE0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AE0D8: jal         0x800B8DD0
    // 0x801AE0DC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x801AE0DC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    after_8:
    // 0x801AE0E0: b           L_801AE120
    // 0x801AE0E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801AE120;
    // 0x801AE0E4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801AE0E8:
    // 0x801AE0E8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AE0EC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AE0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AE0F4: jal         0x800B8DD0
    // 0x801AE0F8: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x801AE0F8: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_9:
    // 0x801AE0FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AE100: lui         $t5, 0xFF00
    ctx->r13 = S32(0XFF00 << 16);
    // 0x801AE104: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x801AE108: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801AE10C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801AE110: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801AE114: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x801AE118: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801AE11C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801AE120:
    // 0x801AE120: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x801AE124: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801AE128: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AE12C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801AE130: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AE134: lbu         $t8, 0x43($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X43);
    // 0x801AE138: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AE13C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801AE140: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801AE144: lw          $t0, -0x464($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X464);
    // 0x801AE148: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801AE14C: jal         0x80005740
    // 0x801AE150: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x801AE150: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_10:
    // 0x801AE154: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AE158: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AE15C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801AE160: jr          $ra
    // 0x801AE164: nop

    return;
    // 0x801AE164: nop

;}
RECOMP_FUNC void Aquas_CsAqFishGroup_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BE0F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801BE0F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801BE0F8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801BE0FC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801BE100: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801BE104: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801BE108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801BE10C: jal         0x800B8DD0
    // 0x801BE110: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801BE110: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_0:
    // 0x801BE114: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BE118: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801BE11C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BE120: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801BE124: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801BE128: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801BE12C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801BE130: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801BE134: jal         0x80005C34
    // 0x801BE138: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x801BE138: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x801BE13C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BE140: lui         $t9, 0xFF
    ctx->r25 = S32(0XFF << 16);
    // 0x801BE144: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801BE148: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801BE14C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801BE150: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801BE154: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801BE158: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801BE15C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BE160: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x801BE164: addiu       $t2, $zero, 0x2000
    ctx->r10 = ADD32(0, 0X2000);
    // 0x801BE168: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801BE16C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801BE170: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801BE174: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801BE178: jal         0x80006EB8
    // 0x801BE17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x801BE17C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801BE180: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x801BE184: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x801BE188: addiu       $a0, $a0, 0x35E0
    ctx->r4 = ADD32(ctx->r4, 0X35E0);
    // 0x801BE18C: lw          $a1, 0x50($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X50);
    // 0x801BE190: addiu       $a2, $v0, 0x18C
    ctx->r6 = ADD32(ctx->r2, 0X18C);
    // 0x801BE194: jal         0x8009AA20
    // 0x801BE198: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    Animation_GetFrameData(rdram, ctx);
        goto after_3;
    // 0x801BE198: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_3:
    // 0x801BE19C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x801BE1A0: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801BE1A4: addiu       $t4, $t4, 0x4660
    ctx->r12 = ADD32(ctx->r12, 0X4660);
    // 0x801BE1A8: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801BE1AC: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x801BE1B0: addiu       $a1, $a1, 0x36CC
    ctx->r5 = ADD32(ctx->r5, 0X36CC);
    // 0x801BE1B4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801BE1B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801BE1BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801BE1C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801BE1C4: jal         0x8009A72C
    // 0x801BE1C8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_4;
    // 0x801BE1C8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_4:
    // 0x801BE1CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801BE1D0: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x801BE1D4: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x801BE1D8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801BE1DC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801BE1E0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801BE1E4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801BE1E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801BE1EC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801BE1F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801BE1F4: jr          $ra
    // 0x801BE1F8: nop

    return;
    // 0x801BE1F8: nop

;}
RECOMP_FUNC void Aquas_Bubble_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC918: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801AC91C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AC920: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801AC924: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AC928: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801AC92C: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
    // 0x801AC930: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801AC934: beq         $v0, $zero, L_801AC940
    if (ctx->r2 == 0) {
        // 0x801AC938: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801AC940;
    }
    // 0x801AC938: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801AC93C: sh          $t6, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r14;
L_801AC940:
    // 0x801AC940: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x801AC944: beql        $v0, $zero, L_801AC96C
    if (ctx->r2 == 0) {
        // 0x801AC948: lwc1        $f0, 0x58($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
            goto L_801AC96C;
    }
    goto skip_0;
    // 0x801AC948: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x801AC94C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801AC950: beq         $v0, $at, L_801ACA14
    if (ctx->r2 == ctx->r1) {
        // 0x801AC954: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801ACA14;
    }
    // 0x801AC954: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801AC958: beql        $v0, $at, L_801ACAF8
    if (ctx->r2 == ctx->r1) {
        // 0x801AC95C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_801ACAF8;
    }
    goto skip_1;
    // 0x801AC95C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_1:
    // 0x801AC960: b           L_801ACBA4
    // 0x801AC964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801ACBA4;
    // 0x801AC964: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AC968: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
L_801AC96C:
    // 0x801AC96C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AC970: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC974: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AC978: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801AC97C: nop

    // 0x801AC980: bc1fl       L_801AC998
    if (!c1cs) {
        // 0x801AC984: lh          $t7, 0x46($s0)
        ctx->r15 = MEM_H(ctx->r16, 0X46);
            goto L_801AC998;
    }
    goto skip_2;
    // 0x801AC984: lh          $t7, 0x46($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X46);
    skip_2:
    // 0x801AC988: lwc1        $f6, 0x1B74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1B74);
    // 0x801AC98C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x801AC990: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x801AC994: lh          $t7, 0x46($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X46);
L_801AC998:
    // 0x801AC998: bnel        $t7, $zero, L_801AC9AC
    if (ctx->r15 != 0) {
        // 0x801AC99C: lui         $at, 0x4204
        ctx->r1 = S32(0X4204 << 16);
            goto L_801AC9AC;
    }
    goto skip_3;
    // 0x801AC99C: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    skip_3:
    // 0x801AC9A0: jal         0x80060FBC
    // 0x801AC9A4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x801AC9A4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_0:
    // 0x801AC9A8: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
L_801AC9AC:
    // 0x801AC9AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AC9B0: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801AC9B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC9B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801AC9BC: swc1        $f18, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f18.u32l;
    // 0x801AC9C0: lwc1        $f6, 0x1B78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1B78);
    // 0x801AC9C4: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801AC9C8: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AC9CC: jal         0x80023250
    // 0x801AC9D0: nop

    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x801AC9D0: nop

    after_1:
    // 0x801AC9D4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801AC9D8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AC9DC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x801AC9E0: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x801AC9E4: mul.s       $f20, $f0, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801AC9E8: jal         0x80023250
    // 0x801AC9EC: lwc1        $f12, 0x58($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X58);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x801AC9EC: lwc1        $f12, 0x58($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X58);
    after_2:
    // 0x801AC9F0: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801AC9F4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801AC9F8: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x801AC9FC: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x801ACA00: jal         0x80023090
    // 0x801ACA04: lwc1        $f12, 0x58($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X58);
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x801ACA04: lwc1        $f12, 0x58($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X58);
    after_3:
    // 0x801ACA08: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801ACA0C: b           L_801ACBA0
    // 0x801ACA10: swc1        $f16, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
        goto L_801ACBA0;
    // 0x801ACA10: swc1        $f16, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f16.u32l;
L_801ACA14:
    // 0x801ACA14: lh          $t0, 0x46($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X46);
    // 0x801ACA18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801ACA1C: bne         $t0, $zero, L_801ACA2C
    if (ctx->r8 != 0) {
        // 0x801ACA20: nop
    
            goto L_801ACA2C;
    }
    // 0x801ACA20: nop

    // 0x801ACA24: jal         0x80060FBC
    // 0x801ACA28: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x801ACA28: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_4:
L_801ACA2C:
    // 0x801ACA2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACA30: lwc1        $f4, 0x1B7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1B7C);
    // 0x801ACA34: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x801ACA38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ACA3C: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801ACA40: lwc1        $f18, 0x60($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801ACA44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACA48: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801ACA4C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801ACA50: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    // 0x801ACA54: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801ACA58: swc1        $f6, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f6.u32l;
    // 0x801ACA5C: lwc1        $f4, 0x1B80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1B80);
    // 0x801ACA60: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801ACA64: jal         0x80023090
    // 0x801ACA68: nop

    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x801ACA68: nop

    after_5:
    // 0x801ACA6C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801ACA70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ACA74: lwc1        $f10, 0x60($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801ACA78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACA7C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801ACA80: lwc1        $f18, 0x6C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801ACA84: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801ACA88: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x801ACA8C: lwc1        $f4, 0x1B84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1B84);
    // 0x801ACA90: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801ACA94: jal         0x80023250
    // 0x801ACA98: nop

    __cosf_recomp(rdram, ctx);
        goto after_6;
    // 0x801ACA98: nop

    after_6:
    // 0x801ACA9C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801ACAA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ACAA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACAA8: lwc1        $f10, 0x1B88($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1B88);
    // 0x801ACAAC: lwc1        $f8, 0x64($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X64);
    // 0x801ACAB0: mul.s       $f20, $f0, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801ACAB4: nop

    // 0x801ACAB8: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801ACABC: jal         0x80023250
    // 0x801ACAC0: nop

    __cosf_recomp(rdram, ctx);
        goto after_7;
    // 0x801ACAC0: nop

    after_7:
    // 0x801ACAC4: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801ACAC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACACC: lwc1        $f18, 0x64($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X64);
    // 0x801ACAD0: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x801ACAD4: lwc1        $f4, 0x1B8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1B8C);
    // 0x801ACAD8: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801ACADC: jal         0x80023090
    // 0x801ACAE0: nop

    __sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x801ACAE0: nop

    after_8:
    // 0x801ACAE4: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x801ACAE8: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801ACAEC: b           L_801ACBA0
    // 0x801ACAF0: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
        goto L_801ACBA0;
    // 0x801ACAF0: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
    // 0x801ACAF4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_801ACAF8:
    // 0x801ACAF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801ACAFC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x801ACB00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACB04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801ACB08: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x801ACB0C: nop

    // 0x801ACB10: bc1fl       L_801ACB28
    if (!c1cs) {
        // 0x801ACB14: lh          $t1, 0x46($s0)
        ctx->r9 = MEM_H(ctx->r16, 0X46);
            goto L_801ACB28;
    }
    goto skip_4;
    // 0x801ACB14: lh          $t1, 0x46($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X46);
    skip_4:
    // 0x801ACB18: lwc1        $f16, 0x1B90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1B90);
    // 0x801ACB1C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801ACB20: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x801ACB24: lh          $t1, 0x46($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X46);
L_801ACB28:
    // 0x801ACB28: bnel        $t1, $zero, L_801ACB3C
    if (ctx->r9 != 0) {
        // 0x801ACB2C: lui         $at, 0x425C
        ctx->r1 = S32(0X425C << 16);
            goto L_801ACB3C;
    }
    goto skip_5;
    // 0x801ACB2C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    skip_5:
    // 0x801ACB30: jal         0x80060FBC
    // 0x801ACB34: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_9;
    // 0x801ACB34: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_9:
    // 0x801ACB38: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
L_801ACB3C:
    // 0x801ACB3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ACB40: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801ACB44: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACB48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801ACB4C: swc1        $f8, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f8.u32l;
    // 0x801ACB50: lwc1        $f16, 0x1B94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1B94);
    // 0x801ACB54: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801ACB58: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801ACB5C: jal         0x80023250
    // 0x801ACB60: nop

    __cosf_recomp(rdram, ctx);
        goto after_10;
    // 0x801ACB60: nop

    after_10:
    // 0x801ACB64: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801ACB68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801ACB6C: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801ACB70: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x801ACB74: mul.s       $f20, $f0, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801ACB78: jal         0x80023250
    // 0x801ACB7C: lwc1        $f12, 0x58($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X58);
    __cosf_recomp(rdram, ctx);
        goto after_11;
    // 0x801ACB7C: lwc1        $f12, 0x58($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0X58);
    after_11:
    // 0x801ACB80: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801ACB84: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x801ACB88: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x801ACB8C: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x801ACB90: jal         0x80023090
    // 0x801ACB94: lwc1        $f12, 0x58($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X58);
    __sinf_recomp(rdram, ctx);
        goto after_12;
    // 0x801ACB94: lwc1        $f12, 0x58($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X58);
    after_12:
    // 0x801ACB98: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801ACB9C: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
L_801ACBA0:
    // 0x801ACBA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801ACBA4:
    // 0x801ACBA4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801ACBA8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801ACBAC: jr          $ra
    // 0x801ACBB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801ACBB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Solar_801A239C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A239C: lh          $t7, 0x8C($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X8C);
    // 0x801A23A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A23A4: sh          $t6, 0x88($a0)
    MEM_H(0X88, ctx->r4) = ctx->r14;
    // 0x801A23A8: bnel        $t7, $zero, L_801A23C4
    if (ctx->r15 != 0) {
        // 0x801A23AC: lh          $t9, 0x8E($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X8E);
            goto L_801A23C4;
    }
    goto skip_0;
    // 0x801A23AC: lh          $t9, 0x8E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8E);
    skip_0:
    // 0x801A23B0: lh          $t8, 0x8E($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X8E);
    // 0x801A23B4: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x801A23B8: beql        $t8, $zero, L_801A23E8
    if (ctx->r24 == 0) {
        // 0x801A23BC: sh          $t2, 0x8A($a0)
        MEM_H(0X8A, ctx->r4) = ctx->r10;
            goto L_801A23E8;
    }
    goto skip_1;
    // 0x801A23BC: sh          $t2, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r10;
    skip_1:
    // 0x801A23C0: lh          $t9, 0x8E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X8E);
L_801A23C4:
    // 0x801A23C4: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801A23C8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801A23CC: beq         $t9, $zero, L_801A23DC
    if (ctx->r25 == 0) {
        // 0x801A23D0: nop
    
            goto L_801A23DC;
    }
    // 0x801A23D0: nop

    // 0x801A23D4: b           L_801A23E8
    // 0x801A23D8: sh          $t0, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r8;
        goto L_801A23E8;
    // 0x801A23D8: sh          $t0, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r8;
L_801A23DC:
    // 0x801A23DC: b           L_801A23E8
    // 0x801A23E0: sh          $t1, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r9;
        goto L_801A23E8;
    // 0x801A23E0: sh          $t1, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r9;
    // 0x801A23E4: sh          $t2, 0x8A($a0)
    MEM_H(0X8A, ctx->r4) = ctx->r10;
L_801A23E8:
    // 0x801A23E8: sh          $zero, 0x4C($a0)
    MEM_H(0X4C, ctx->r4) = 0;
    // 0x801A23EC: jr          $ra
    // 0x801A23F0: nop

    return;
    // 0x801A23F0: nop

;}
RECOMP_FUNC void Solar_SoRock_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F7AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019F7B0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8019F7B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8019F7B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019F7BC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8019F7C0: lh          $t6, 0xB8($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XB8);
    // 0x8019F7C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F7C8: beql        $t6, $zero, L_8019F98C
    if (ctx->r14 == 0) {
        // 0x8019F7CC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8019F98C;
    }
    goto skip_0;
    // 0x8019F7CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8019F7D0: jal         0x80005708
    // 0x8019F7D4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8019F7D4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x8019F7D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F7DC: lwc1        $f6, 0x1524($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1524);
    // 0x8019F7E0: lwc1        $f4, 0xF8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x8019F7E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F7E8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019F7EC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019F7F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019F7F4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019F7F8: jal         0x80005E90
    // 0x8019F7FC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8019F7FC: nop

    after_1:
    // 0x8019F800: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019F804: lwc1        $f16, 0x1528($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1528);
    // 0x8019F808: lwc1        $f10, 0xF4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x8019F80C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F810: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019F814: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019F818: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019F81C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8019F820: jal         0x80005D44
    // 0x8019F824: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x8019F824: nop

    after_2:
    // 0x8019F828: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019F82C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019F830: jal         0x80006EB8
    // 0x8019F834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x8019F834: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8019F838: lhu         $v0, 0x2($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X2);
    // 0x8019F83C: addiu       $at, $zero, 0x113
    ctx->r1 = ADD32(0, 0X113);
    // 0x8019F840: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8019F844: beq         $v0, $at, L_8019F868
    if (ctx->r2 == ctx->r1) {
        // 0x8019F848: addiu       $at, $zero, 0x114
        ctx->r1 = ADD32(0, 0X114);
            goto L_8019F868;
    }
    // 0x8019F848: addiu       $at, $zero, 0x114
    ctx->r1 = ADD32(0, 0X114);
    // 0x8019F84C: beq         $v0, $at, L_8019F88C
    if (ctx->r2 == ctx->r1) {
        // 0x8019F850: lui         $t0, 0x8017
        ctx->r8 = S32(0X8017 << 16);
            goto L_8019F88C;
    }
    // 0x8019F850: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8019F854: addiu       $at, $zero, 0x115
    ctx->r1 = ADD32(0, 0X115);
    // 0x8019F858: beq         $v0, $at, L_8019F8F0
    if (ctx->r2 == ctx->r1) {
        // 0x8019F85C: lui         $t9, 0x600
        ctx->r25 = S32(0X600 << 16);
            goto L_8019F8F0;
    }
    // 0x8019F85C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8019F860: b           L_8019F90C
    // 0x8019F864: nop

        goto L_8019F90C;
    // 0x8019F864: nop

L_8019F868:
    // 0x8019F868: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019F86C: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x8019F870: addiu       $t9, $t9, 0x7370
    ctx->r25 = ADD32(ctx->r25, 0X7370);
    // 0x8019F874: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8019F878: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8019F87C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8019F880: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8019F884: b           L_8019F90C
    // 0x8019F888: nop

        goto L_8019F90C;
    // 0x8019F888: nop

L_8019F88C:
    // 0x8019F88C: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x8019F890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019F894: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8019F898: bnel        $t1, $zero, L_8019F8CC
    if (ctx->r9 != 0) {
        // 0x8019F89C: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8019F8CC;
    }
    goto skip_1;
    // 0x8019F89C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8019F8A0: jal         0x800B8DD0
    // 0x8019F8A4: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x8019F8A4: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    after_4:
    // 0x8019F8A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019F8AC: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x8019F8B0: ori         $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 | 0XFF;
    // 0x8019F8B4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8019F8B8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8019F8BC: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8019F8C0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019F8C4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8019F8C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8019F8CC:
    // 0x8019F8CC: lui         $t7, 0x601
    ctx->r15 = S32(0X601 << 16);
    // 0x8019F8D0: addiu       $t7, $t7, 0x7090
    ctx->r15 = ADD32(ctx->r15, 0X7090);
    // 0x8019F8D4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8019F8D8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8019F8DC: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8019F8E0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8019F8E4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8019F8E8: b           L_8019F90C
    // 0x8019F8EC: nop

        goto L_8019F90C;
    // 0x8019F8EC: nop

L_8019F8F0:
    // 0x8019F8F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019F8F4: lui         $t0, 0x601
    ctx->r8 = S32(0X601 << 16);
    // 0x8019F8F8: addiu       $t0, $t0, 0x6CF0
    ctx->r8 = ADD32(ctx->r8, 0X6CF0);
    // 0x8019F8FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8019F900: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8019F904: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8019F908: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8019F90C:
    // 0x8019F90C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F910: jal         0x80005740
    // 0x8019F914: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x8019F914: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x8019F918: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8019F91C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019F920: lwc1        $f4, 0x110($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X110);
    // 0x8019F924: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019F928: jal         0x8005980C
    // 0x8019F92C: nop

    Graphics_SetScaleMtx(rdram, ctx);
        goto after_6;
    // 0x8019F92C: nop

    after_6:
    // 0x8019F930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019F934: jal         0x800B8DD0
    // 0x8019F938: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x8019F938: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_7:
    // 0x8019F93C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019F940: lui         $t3, 0xFF80
    ctx->r11 = S32(0XFF80 << 16);
    // 0x8019F944: ori         $t3, $t3, 0x80A0
    ctx->r11 = ctx->r11 | 0X80A0;
    // 0x8019F948: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8019F94C: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8019F950: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8019F954: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8019F958: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8019F95C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019F960: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8019F964: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x8019F968: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019F96C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8019F970: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8019F974: lh          $t6, 0xB6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XB6);
    // 0x8019F978: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019F97C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8019F980: lw          $t8, -0x6D4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6D4);
    // 0x8019F984: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019F988: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019F98C:
    // 0x8019F98C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8019F990: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8019F994: jr          $ra
    // 0x8019F998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8019F998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Zoness_ZoContainer_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BC78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019BC7C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8019BC80: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8019BC84: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x8019BC88: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8019BC8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019BC90: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8019BC94: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019BC98: addiu       $t6, $t6, -0x760
    ctx->r14 = ADD32(ctx->r14, -0X760);
    // 0x8019BC9C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8019BCA0: addiu       $t1, $a0, -0x1
    ctx->r9 = ADD32(ctx->r4, -0X1);
    // 0x8019BCA4: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8019BCA8: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8019BCAC: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8019BCB0: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8019BCB4: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8019BCB8: lh          $t0, 0xB8($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB8);
    // 0x8019BCBC: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8019BCC0: beql        $t0, $zero, L_8019BDD0
    if (ctx->r8 == 0) {
        // 0x8019BCC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8019BDD0;
    }
    goto skip_0;
    // 0x8019BCC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8019BCC8: beq         $at, $zero, L_8019BDCC
    if (ctx->r1 == 0) {
        // 0x8019BCCC: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8019BDCC;
    }
    // 0x8019BCCC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8019BCD0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019BCD4: addu        $at, $at, $t1
    gpr jr_addend_8019BCDC = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8019BCD8: lw          $t1, 0x1258($at)
    ctx->r9 = ADD32(ctx->r1, 0X1258);
    // 0x8019BCDC: jr          $t1
    // 0x8019BCE0: nop

    switch (jr_addend_8019BCDC >> 2) {
        case 0: goto L_8019BCE4; break;
        case 1: goto L_8019BD0C; break;
        case 2: goto L_8019BD34; break;
        case 3: goto L_8019BD5C; break;
        case 4: goto L_8019BD84; break;
        case 5: goto L_8019BDAC; break;
        default: switch_error(__func__, 0x8019BCDC, 0x801C1258);
    }
    // 0x8019BCE0: nop

L_8019BCE4:
    // 0x8019BCE4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019BCE8: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019BCEC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BCF0: jal         0x80006970
    // 0x8019BCF4: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8019BCF4: addiu       $a2, $s0, 0x18C
    ctx->r6 = ADD32(ctx->r16, 0X18C);
    after_0:
    // 0x8019BCF8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BCFC: jal         0x80006AB8
    // 0x8019BD00: addiu       $a1, $s0, 0x1D4
    ctx->r5 = ADD32(ctx->r16, 0X1D4);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x8019BD00: addiu       $a1, $s0, 0x1D4
    ctx->r5 = ADD32(ctx->r16, 0X1D4);
    after_1:
    // 0x8019BD04: b           L_8019BDD0
    // 0x8019BD08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8019BDD0;
    // 0x8019BD08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019BD0C:
    // 0x8019BD0C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019BD10: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019BD14: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BD18: jal         0x80006970
    // 0x8019BD1C: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8019BD1C: addiu       $a2, $s0, 0x198
    ctx->r6 = ADD32(ctx->r16, 0X198);
    after_2:
    // 0x8019BD20: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BD24: jal         0x80006AB8
    // 0x8019BD28: addiu       $a1, $s0, 0x1E0
    ctx->r5 = ADD32(ctx->r16, 0X1E0);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_3;
    // 0x8019BD28: addiu       $a1, $s0, 0x1E0
    ctx->r5 = ADD32(ctx->r16, 0X1E0);
    after_3:
    // 0x8019BD2C: b           L_8019BDD0
    // 0x8019BD30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8019BDD0;
    // 0x8019BD30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019BD34:
    // 0x8019BD34: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019BD38: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019BD3C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BD40: jal         0x80006970
    // 0x8019BD44: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x8019BD44: addiu       $a2, $s0, 0x1A4
    ctx->r6 = ADD32(ctx->r16, 0X1A4);
    after_4:
    // 0x8019BD48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BD4C: jal         0x80006AB8
    // 0x8019BD50: addiu       $a1, $s0, 0x1EC
    ctx->r5 = ADD32(ctx->r16, 0X1EC);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_5;
    // 0x8019BD50: addiu       $a1, $s0, 0x1EC
    ctx->r5 = ADD32(ctx->r16, 0X1EC);
    after_5:
    // 0x8019BD54: b           L_8019BDD0
    // 0x8019BD58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8019BDD0;
    // 0x8019BD58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019BD5C:
    // 0x8019BD5C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019BD60: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019BD64: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BD68: jal         0x80006970
    // 0x8019BD6C: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x8019BD6C: addiu       $a2, $s0, 0x1B0
    ctx->r6 = ADD32(ctx->r16, 0X1B0);
    after_6:
    // 0x8019BD70: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BD74: jal         0x80006AB8
    // 0x8019BD78: addiu       $a1, $s0, 0x1F8
    ctx->r5 = ADD32(ctx->r16, 0X1F8);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_7;
    // 0x8019BD78: addiu       $a1, $s0, 0x1F8
    ctx->r5 = ADD32(ctx->r16, 0X1F8);
    after_7:
    // 0x8019BD7C: b           L_8019BDD0
    // 0x8019BD80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8019BDD0;
    // 0x8019BD80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019BD84:
    // 0x8019BD84: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019BD88: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019BD8C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BD90: jal         0x80006970
    // 0x8019BD94: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x8019BD94: addiu       $a2, $s0, 0x1BC
    ctx->r6 = ADD32(ctx->r16, 0X1BC);
    after_8:
    // 0x8019BD98: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BD9C: jal         0x80006AB8
    // 0x8019BDA0: addiu       $a1, $s0, 0x204
    ctx->r5 = ADD32(ctx->r16, 0X204);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_9;
    // 0x8019BDA0: addiu       $a1, $s0, 0x204
    ctx->r5 = ADD32(ctx->r16, 0X204);
    after_9:
    // 0x8019BDA4: b           L_8019BDD0
    // 0x8019BDA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8019BDD0;
    // 0x8019BDA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019BDAC:
    // 0x8019BDAC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019BDB0: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019BDB4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BDB8: jal         0x80006970
    // 0x8019BDBC: addiu       $a2, $s0, 0x1C8
    ctx->r6 = ADD32(ctx->r16, 0X1C8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x8019BDBC: addiu       $a2, $s0, 0x1C8
    ctx->r6 = ADD32(ctx->r16, 0X1C8);
    after_10:
    // 0x8019BDC0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019BDC4: jal         0x80006AB8
    // 0x8019BDC8: addiu       $a1, $s0, 0x210
    ctx->r5 = ADD32(ctx->r16, 0X210);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_11;
    // 0x8019BDC8: addiu       $a1, $s0, 0x210
    ctx->r5 = ADD32(ctx->r16, 0X210);
    after_11:
L_8019BDCC:
    // 0x8019BDCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019BDD0:
    // 0x8019BDD0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8019BDD4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8019BDD8: jr          $ra
    // 0x8019BDDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8019BDDC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Aquas_BlueMarineTorpedo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC09C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801AC0A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AC0A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AC0A8: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x801AC0AC: addiu       $s0, $s0, 0x46E0
    ctx->r16 = ADD32(ctx->r16, 0X46E0);
    // 0x801AC0B0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x801AC0B4: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_801AC0B8:
    // 0x801AC0B8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x801AC0BC: bnel        $t6, $zero, L_801AC170
    if (ctx->r14 != 0) {
        // 0x801AC0C0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801AC170;
    }
    goto skip_0;
    // 0x801AC0C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x801AC0C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801AC0C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801AC0CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AC0D0: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x801AC0D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AC0D8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AC0DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801AC0E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801AC0E4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801AC0E8: jal         0x800AC290
    // 0x801AC0EC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_0;
    // 0x801AC0EC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801AC0F0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AC0F4: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x801AC0F8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AC0FC: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x801AC100: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x801AC104: ori         $a0, $a0, 0x25
    ctx->r4 = ctx->r4 | 0X25;
    // 0x801AC108: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801AC10C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AC110: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x801AC114: jal         0x80019218
    // 0x801AC118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x801AC118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801AC11C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x801AC120: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC124: addiu       $t0, $zero, 0x12C
    ctx->r8 = ADD32(0, 0X12C);
    // 0x801AC128: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801AC12C: sw          $t9, 0x41A4($at)
    MEM_W(0X41A4, ctx->r1) = ctx->r25;
    // 0x801AC130: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC134: sw          $t0, 0x4454($at)
    MEM_W(0X4454, ctx->r1) = ctx->r8;
    // 0x801AC138: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x801AC13C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AC140: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC144: swc1        $f6, 0x4458($at)
    MEM_W(0X4458, ctx->r1) = ctx->f6.u32l;
    // 0x801AC148: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC14C: lwc1        $f8, 0x1B58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1B58);
    // 0x801AC150: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC154: swc1        $f8, 0x445C($at)
    MEM_W(0X445C, ctx->r1) = ctx->f8.u32l;
    // 0x801AC158: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AC15C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AC160: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AC164: b           L_801AC178
    // 0x801AC168: swc1        $f10, -0x7C94($at)
    MEM_W(-0X7C94, ctx->r1) = ctx->f10.u32l;
        goto L_801AC178;
    // 0x801AC168: swc1        $f10, -0x7C94($at)
    MEM_W(-0X7C94, ctx->r1) = ctx->f10.u32l;
    // 0x801AC16C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_801AC170:
    // 0x801AC170: bne         $v0, $v1, L_801AC0B8
    if (ctx->r2 != ctx->r3) {
        // 0x801AC174: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_801AC0B8;
    }
    // 0x801AC174: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
L_801AC178:
    // 0x801AC178: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AC17C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AC180: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801AC184: jr          $ra
    // 0x801AC188: nop

    return;
    // 0x801AC188: nop

;}
RECOMP_FUNC void Aquas_BlueMarineLaser(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC18C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801AC190: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AC194: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AC198: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x801AC19C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801AC1A0: addiu       $v0, $v0, 0x41A0
    ctx->r2 = ADD32(ctx->r2, 0X41A0);
    // 0x801AC1A4: addiu       $s0, $s0, 0x4050
    ctx->r16 = ADD32(ctx->r16, 0X4050);
    // 0x801AC1A8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_801AC1AC:
    // 0x801AC1AC: bne         $t6, $zero, L_801AC254
    if (ctx->r14 != 0) {
        // 0x801AC1B0: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_801AC254;
    }
    // 0x801AC1B0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801AC1B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AC1B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801AC1BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801AC1C0: lui         $a3, 0xC120
    ctx->r7 = S32(0XC120 << 16);
    // 0x801AC1C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801AC1C8: jal         0x800AC290
    // 0x801AC1CC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Player_SetupArwingShot(rdram, ctx);
        goto after_0;
    // 0x801AC1CC: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801AC1D0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801AC1D4: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x801AC1D8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x801AC1DC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AC1E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801AC1E4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801AC1E8: lw          $t9, 0x1AA8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1AA8);
    // 0x801AC1EC: lui         $a0, 0x940
    ctx->r4 = S32(0X940 << 16);
    // 0x801AC1F0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AC1F4: bne         $t9, $zero, L_801AC230
    if (ctx->r25 != 0) {
        // 0x801AC1F8: ori         $a0, $a0, 0x27
        ctx->r4 = ctx->r4 | 0X27;
            goto L_801AC230;
    }
    // 0x801AC1F8: ori         $a0, $a0, 0x27
    ctx->r4 = ctx->r4 | 0X27;
    // 0x801AC1FC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AC200: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801AC204: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AC208: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x801AC20C: lui         $a0, 0x940
    ctx->r4 = S32(0X940 << 16);
    // 0x801AC210: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x801AC214: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801AC218: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AC21C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x801AC220: jal         0x80019218
    // 0x801AC224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x801AC224: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801AC228: b           L_801AC264
    // 0x801AC22C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801AC264;
    // 0x801AC22C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801AC230:
    // 0x801AC230: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x801AC234: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x801AC238: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801AC23C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x801AC240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801AC244: jal         0x80019218
    // 0x801AC248: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801AC248: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x801AC24C: b           L_801AC264
    // 0x801AC250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801AC264;
    // 0x801AC250: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801AC254:
    // 0x801AC254: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x801AC258: bnel        $s0, $v0, L_801AC1AC
    if (ctx->r16 != ctx->r2) {
        // 0x801AC25C: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_801AC1AC;
    }
    goto skip_0;
    // 0x801AC25C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_0:
    // 0x801AC260: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801AC264:
    // 0x801AC264: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AC268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801AC26C: jr          $ra
    // 0x801AC270: nop

    return;
    // 0x801AC270: nop

;}
RECOMP_FUNC void Zoness_ZoDodora_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190A00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80190A04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80190A08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80190A0C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80190A10: lhu         $t6, 0xC0($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XC0);
    // 0x80190A14: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80190A18: bne         $t6, $zero, L_80190AF8
    if (ctx->r14 != 0) {
        // 0x80190A1C: nop
    
            goto L_80190AF8;
    }
    // 0x80190A1C: nop

    // 0x80190A20: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80190A24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80190A28: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80190A2C: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80190A30: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80190A34: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80190A38: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80190A3C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80190A40: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80190A44: jal         0x800A73E4
    // 0x80190A48: nop

    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_0;
    // 0x80190A48: nop

    after_0:
    // 0x80190A4C: beq         $v0, $zero, L_80190AF8
    if (ctx->r2 == 0) {
        // 0x80190A50: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_80190AF8;
    }
    // 0x80190A50: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80190A54: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80190A58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80190A5C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190A60: lwc1        $f6, 0xE14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE14);
    // 0x80190A64: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80190A68: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80190A6C: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80190A70: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80190A74: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80190A78: jal         0x8008377C
    // 0x80190A7C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Effect_Effect391_Spawn(rdram, ctx);
        goto after_1;
    // 0x80190A7C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80190A80: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80190A84: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80190A88: lui         $a0, 0x1983
    ctx->r4 = S32(0X1983 << 16);
    // 0x80190A8C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80190A90: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x80190A94: addiu       $a3, $t8, 0x5D34
    ctx->r7 = ADD32(ctx->r24, 0X5D34);
    // 0x80190A98: ori         $a0, $a0, 0x2019
    ctx->r4 = ctx->r4 | 0X2019;
    // 0x80190A9C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80190AA0: bc1f        L_80190ADC
    if (!c1cs) {
        // 0x80190AA4: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80190ADC;
    }
    // 0x80190AA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80190AA8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80190AAC: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80190AB0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80190AB4: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80190AB8: lui         $a0, 0x1983
    ctx->r4 = S32(0X1983 << 16);
    // 0x80190ABC: ori         $a0, $a0, 0x201A
    ctx->r4 = ctx->r4 | 0X201A;
    // 0x80190AC0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80190AC4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80190AC8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80190ACC: jal         0x80019218
    // 0x80190AD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80190AD0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80190AD4: b           L_80190AF4
    // 0x80190AD8: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
        goto L_80190AF4;
    // 0x80190AD8: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
L_80190ADC:
    // 0x80190ADC: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80190AE0: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80190AE4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80190AE8: jal         0x80019218
    // 0x80190AEC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x80190AEC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_3:
    // 0x80190AF0: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
L_80190AF4:
    // 0x80190AF4: sh          $t0, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r8;
L_80190AF8:
    // 0x80190AF8: jal         0x80190790
    // 0x80190AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Zoness_80190790(rdram, ctx);
        goto after_4;
    // 0x80190AFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80190B00: lb          $t1, 0xD0($s0)
    ctx->r9 = MEM_B(ctx->r16, 0XD0);
    // 0x80190B04: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80190B08: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80190B0C: beq         $t1, $zero, L_80190B38
    if (ctx->r9 == 0) {
        // 0x80190B10: lui         $a0, 0x2912
        ctx->r4 = S32(0X2912 << 16);
            goto L_80190B38;
    }
    // 0x80190B10: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x80190B14: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80190B18: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x80190B1C: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80190B20: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80190B24: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80190B28: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x80190B2C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80190B30: jal         0x80019218
    // 0x80190B34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80190B34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_80190B38:
    // 0x80190B38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80190B3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80190B40: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80190B44: jr          $ra
    // 0x80190B48: nop

    return;
    // 0x80190B48: nop

;}
RECOMP_FUNC void Solar_SoRock1_2_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F038: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019F03C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019F040: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8019F044: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019F048: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019F04C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019F050: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8019F054: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x8019F058: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8019F05C:
    // 0x8019F05C: bnel        $t6, $zero, L_8019F098
    if (ctx->r14 != 0) {
        // 0x8019F060: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_8019F098;
    }
    goto skip_0;
    // 0x8019F060: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_0:
    // 0x8019F064: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019F068: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019F06C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019F070: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019F074: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8019F078: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8019F07C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019F080: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019F084: jal         0x8019EF30
    // 0x8019F088: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Solar_SoRock1_2_Setup(rdram, ctx);
        goto after_0;
    // 0x8019F088: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8019F08C: b           L_8019F0A4
    // 0x8019F090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8019F0A4;
    // 0x8019F090: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019F094: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_8019F098:
    // 0x8019F098: bnel        $a0, $v0, L_8019F05C
    if (ctx->r4 != ctx->r2) {
        // 0x8019F09C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8019F05C;
    }
    goto skip_1;
    // 0x8019F09C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8019F0A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019F0A4:
    // 0x8019F0A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019F0A8: jr          $ra
    // 0x8019F0AC: nop

    return;
    // 0x8019F0AC: nop

;}
RECOMP_FUNC void Solar_Effect392_Spawn5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FFC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019FFC4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8019FFC8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8019FFCC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019FFD0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019FFD4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019FFD8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019FFDC: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8019FFE0: addiu       $a1, $a1, 0x2778
    ctx->r5 = ADD32(ctx->r5, 0X2778);
    // 0x8019FFE4: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
L_8019FFE8:
    // 0x8019FFE8: bnel        $t6, $zero, L_801A0020
    if (ctx->r14 != 0) {
        // 0x8019FFEC: addiu       $a1, $a1, -0x8C
        ctx->r5 = ADD32(ctx->r5, -0X8C);
            goto L_801A0020;
    }
    goto skip_0;
    // 0x8019FFEC: addiu       $a1, $a1, -0x8C
    ctx->r5 = ADD32(ctx->r5, -0X8C);
    skip_0:
    // 0x8019FFF0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8019FFF4: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8019FFF8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8019FFFC: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x801A0000: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x801A0004: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A0008: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A000C: jal         0x8019FDE0
    // 0x801A0010: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    Solar_Effect392_Setup5(rdram, ctx);
        goto after_0;
    // 0x801A0010: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x801A0014: b           L_801A0030
    // 0x801A0018: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801A0030;
    // 0x801A0018: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A001C: addiu       $a1, $a1, -0x8C
    ctx->r5 = ADD32(ctx->r5, -0X8C);
L_801A0020:
    // 0x801A0020: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x801A0024: beql        $at, $zero, L_8019FFE8
    if (ctx->r1 == 0) {
        // 0x801A0028: lbu         $t6, 0x0($a1)
        ctx->r14 = MEM_BU(ctx->r5, 0X0);
            goto L_8019FFE8;
    }
    goto skip_1;
    // 0x801A0028: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    skip_1:
    // 0x801A002C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801A0030:
    // 0x801A0030: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A0034: jr          $ra
    // 0x801A0038: nop

    return;
    // 0x801A0038: nop

;}
RECOMP_FUNC void Aquas_AqSculpin_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B504C: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x801B5050: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801B5054: sw          $a0, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r4;
    // 0x801B5058: lw          $t6, 0x198($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X198);
    // 0x801B505C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801B5060: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801B5064: lwc1        $f0, 0x110($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X110);
    // 0x801B5068: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801B506C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801B5070: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801B5074: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801B5078: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801B507C: jal         0x80005C34
    // 0x801B5080: nop

    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x801B5080: nop

    after_0:
    // 0x801B5084: lw          $t8, 0x198($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X198);
    // 0x801B5088: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x801B508C: addiu       $a0, $a0, 0x5954
    ctx->r4 = ADD32(ctx->r4, 0X5954);
    // 0x801B5090: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801B5094: jal         0x8009AA20
    // 0x801B5098: lh          $a1, 0xB6($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XB6);
    Animation_GetFrameData(rdram, ctx);
        goto after_1;
    // 0x801B5098: lh          $a1, 0xB6($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XB6);
    after_1:
    // 0x801B509C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801B50A0: lw          $t1, -0x4438($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4438);
    // 0x801B50A4: lw          $t0, 0x198($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X198);
    // 0x801B50A8: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801B50AC: addiu       $t9, $t9, 0x4E94
    ctx->r25 = ADD32(ctx->r25, 0X4E94);
    // 0x801B50B0: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x801B50B4: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x801B50B8: addiu       $a3, $a3, 0x4DDC
    ctx->r7 = ADD32(ctx->r7, 0X4DDC);
    // 0x801B50BC: addiu       $a1, $a1, 0x5A80
    ctx->r5 = ADD32(ctx->r5, 0X5A80);
    // 0x801B50C0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801B50C4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801B50C8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801B50CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801B50D0: jal         0x8009A72C
    // 0x801B50D4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x801B50D4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x801B50D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801B50DC: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    // 0x801B50E0: jr          $ra
    // 0x801B50E4: nop

    return;
    // 0x801B50E4: nop

;}
RECOMP_FUNC void Area6_8018D4E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D4E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D4E4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018D4E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018D4EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8018D4F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D4F4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018D4F8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D4FC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018D500: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D504: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D508: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8018D50C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8018D510: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D514: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018D518: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8018D51C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8018D520: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8018D524: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8018D528: jal         0x8007BFFC
    // 0x8018D52C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_0;
    // 0x8018D52C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8018D530: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D534: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D538: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8018D53C: jal         0x8007D2C8
    // 0x8018D540: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_1;
    // 0x8018D540: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    after_1:
    // 0x8018D544: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D548: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D54C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8018D550: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8018D554: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018D558: jal         0x8007B344
    // 0x8018D55C: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_2;
    // 0x8018D55C: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    after_2:
    // 0x8018D560: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D564: jal         0x80060FBC
    // 0x8018D568: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8018D568: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_3:
    // 0x8018D56C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D570: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D574: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018D578: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
    // 0x8018D57C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
L_8018D580:
    // 0x8018D580: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D584: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D588: jal         0x800794CC
    // 0x8018D58C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_4;
    // 0x8018D58C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_4:
    // 0x8018D590: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018D594: bnel        $s0, $s2, L_8018D580
    if (ctx->r16 != ctx->r18) {
        // 0x8018D598: mfc1        $a3, $f20
        ctx->r7 = (int32_t)ctx->f20.u32l;
            goto L_8018D580;
    }
    goto skip_0;
    // 0x8018D598: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    skip_0:
    // 0x8018D59C: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8018D5A0: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x8018D5A4: jal         0x8007A6F0
    // 0x8018D5A8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_5;
    // 0x8018D5A8: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    after_5:
    // 0x8018D5AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D5B0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018D5B4: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D5B8: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018D5BC: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018D5C0: jr          $ra
    // 0x8018D5C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8018D5C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Solar_801A4A34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4A34: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801A4A38: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x801A4A3C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A4A40: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801A4A44: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x801A4A48: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x801A4A4C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x801A4A50: lh          $t6, 0x8C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X8C);
    // 0x801A4A54: bgezl       $t6, L_801A4C20
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801A4A58: lh          $t9, 0x8E($s0)
        ctx->r25 = MEM_H(ctx->r16, 0X8E);
            goto L_801A4C20;
    }
    goto skip_0;
    // 0x801A4A58: lh          $t9, 0x8E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X8E);
    skip_0:
    // 0x801A4A5C: jal         0x80004EB0
    // 0x801A4A60: sh          $zero, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = 0;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801A4A60: sh          $zero, 0x8C($s0)
    MEM_H(0X8C, ctx->r16) = 0;
    after_0:
    // 0x801A4A64: jal         0x80004EB0
    // 0x801A4A68: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801A4A68: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_1:
    // 0x801A4A6C: jal         0x80004EB0
    // 0x801A4A70: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801A4A70: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x801A4A74: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801A4A78: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801A4A7C: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x801A4A80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A4A84: lwc1        $f4, 0x180($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X180);
    // 0x801A4A88: lwc1        $f12, 0x148($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X148);
    // 0x801A4A8C: mul.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x801A4A90: lwc1        $f14, 0x14C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x801A4A94: lw          $a2, 0x150($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X150);
    // 0x801A4A98: lw          $a3, 0x17C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X17C);
    // 0x801A4A9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A4AA0: lwc1        $f6, 0x184($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X184);
    // 0x801A4AA4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A4AA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4AAC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A4AB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A4AB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4AB8: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A4ABC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A4AC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4AC4: mul.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x801A4AC8: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801A4ACC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801A4AD0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A4AD4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801A4AD8: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x801A4ADC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A4AE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4AE4: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801A4AE8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A4AEC: jal         0x801A1E14
    // 0x801A4AF0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Solar_ActorDebris_Spawn(rdram, ctx);
        goto after_3;
    // 0x801A4AF0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x801A4AF4: jal         0x80004EB0
    // 0x801A4AF8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801A4AF8: nop

    after_4:
    // 0x801A4AFC: jal         0x80004EB0
    // 0x801A4B00: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801A4B00: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_5:
    // 0x801A4B04: jal         0x80004EB0
    // 0x801A4B08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801A4B08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_6:
    // 0x801A4B0C: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x801A4B10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4B14: lwc1        $f8, 0x198($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X198);
    // 0x801A4B18: lwc1        $f12, 0x130($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X130);
    // 0x801A4B1C: mul.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f22.fl, ctx->f16.fl);
    // 0x801A4B20: lwc1        $f14, 0x134($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X134);
    // 0x801A4B24: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x801A4B28: lw          $a3, 0x194($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X194);
    // 0x801A4B2C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A4B30: lwc1        $f10, 0x19C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X19C);
    // 0x801A4B34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A4B38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4B3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A4B40: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801A4B44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4B48: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A4B4C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A4B50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A4B54: mul.s       $f8, $f20, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x801A4B58: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801A4B5C: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x801A4B60: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A4B64: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A4B68: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x801A4B6C: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x801A4B70: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A4B74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A4B78: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801A4B7C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A4B80: jal         0x801A1E14
    // 0x801A4B84: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Solar_ActorDebris_Spawn(rdram, ctx);
        goto after_7;
    // 0x801A4B84: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x801A4B88: jal         0x80004EB0
    // 0x801A4B8C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801A4B8C: nop

    after_8:
    // 0x801A4B90: jal         0x80004EB0
    // 0x801A4B94: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801A4B94: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_9:
    // 0x801A4B98: jal         0x80004EB0
    // 0x801A4B9C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801A4B9C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_10:
    // 0x801A4BA0: lui         $at, 0xC1C8
    ctx->r1 = S32(0XC1C8 << 16);
    // 0x801A4BA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4BA8: lwc1        $f16, 0x168($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X168);
    // 0x801A4BAC: lwc1        $f12, 0x100($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X100);
    // 0x801A4BB0: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x801A4BB4: lwc1        $f14, 0x104($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X104);
    // 0x801A4BB8: lw          $a2, 0x108($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X108);
    // 0x801A4BBC: lw          $a3, 0x164($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X164);
    // 0x801A4BC0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801A4BC4: lwc1        $f18, 0x16C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X16C);
    // 0x801A4BC8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A4BCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A4BD0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A4BD4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801A4BD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A4BDC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A4BE0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A4BE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4BE8: mul.s       $f16, $f20, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x801A4BEC: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x801A4BF0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801A4BF4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A4BF8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801A4BFC: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x801A4C00: mul.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x801A4C04: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A4C08: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4C0C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x801A4C10: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A4C14: jal         0x801A1E14
    // 0x801A4C18: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    Solar_ActorDebris_Spawn(rdram, ctx);
        goto after_11;
    // 0x801A4C18: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x801A4C1C: lh          $t9, 0x8E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X8E);
L_801A4C20:
    // 0x801A4C20: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801A4C24: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801A4C28: bgezl       $t9, L_801A4DD8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x801A4C2C: lh          $v1, 0x4C($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X4C);
            goto L_801A4DD8;
    }
    goto skip_1;
    // 0x801A4C2C: lh          $v1, 0x4C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4C);
    skip_1:
    // 0x801A4C30: jal         0x80004EB0
    // 0x801A4C34: sh          $zero, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = 0;
    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x801A4C34: sh          $zero, 0x8E($s0)
    MEM_H(0X8E, ctx->r16) = 0;
    after_12:
    // 0x801A4C38: jal         0x80004EB0
    // 0x801A4C3C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x801A4C3C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_13:
    // 0x801A4C40: jal         0x80004EB0
    // 0x801A4C44: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x801A4C44: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_14:
    // 0x801A4C48: mul.s       $f8, $f22, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x801A4C4C: lwc1        $f4, 0x174($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X174);
    // 0x801A4C50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A4C54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4C58: lwc1        $f12, 0x13C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X13C);
    // 0x801A4C5C: lwc1        $f14, 0x140($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X140);
    // 0x801A4C60: lw          $a2, 0x144($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X144);
    // 0x801A4C64: lw          $a3, 0x170($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X170);
    // 0x801A4C68: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A4C6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A4C70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4C74: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A4C78: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A4C7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A4C80: mul.s       $f18, $f20, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x801A4C84: lwc1        $f6, 0x178($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X178);
    // 0x801A4C88: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x801A4C8C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801A4C90: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A4C94: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A4C98: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x801A4C9C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A4CA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A4CA4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x801A4CA8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801A4CAC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x801A4CB0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A4CB4: jal         0x801A1E14
    // 0x801A4CB8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Solar_ActorDebris_Spawn(rdram, ctx);
        goto after_15;
    // 0x801A4CB8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x801A4CBC: jal         0x80004EB0
    // 0x801A4CC0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x801A4CC0: nop

    after_16:
    // 0x801A4CC4: jal         0x80004EB0
    // 0x801A4CC8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_17;
    // 0x801A4CC8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_17:
    // 0x801A4CCC: jal         0x80004EB0
    // 0x801A4CD0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x801A4CD0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_18:
    // 0x801A4CD4: mul.s       $f10, $f22, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x801A4CD8: lwc1        $f6, 0x18C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x801A4CDC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A4CE0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4CE4: lwc1        $f12, 0x124($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X124);
    // 0x801A4CE8: lwc1        $f14, 0x128($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X128);
    // 0x801A4CEC: lw          $a2, 0x12C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X12C);
    // 0x801A4CF0: lw          $a3, 0x188($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X188);
    // 0x801A4CF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A4CF8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801A4CFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4D00: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A4D04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A4D08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4D0C: mul.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x801A4D10: lwc1        $f8, 0x190($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X190);
    // 0x801A4D14: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801A4D18: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801A4D1C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x801A4D20: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A4D24: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x801A4D28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A4D2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A4D30: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801A4D34: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801A4D38: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801A4D3C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A4D40: jal         0x801A1E14
    // 0x801A4D44: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Solar_ActorDebris_Spawn(rdram, ctx);
        goto after_19;
    // 0x801A4D44: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_19:
    // 0x801A4D48: jal         0x80004EB0
    // 0x801A4D4C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x801A4D4C: nop

    after_20:
    // 0x801A4D50: jal         0x80004EB0
    // 0x801A4D54: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x801A4D54: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_21:
    // 0x801A4D58: jal         0x80004EB0
    // 0x801A4D5C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x801A4D5C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_22:
    // 0x801A4D60: mul.s       $f16, $f22, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x801A4D64: lwc1        $f8, 0x15C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X15C);
    // 0x801A4D68: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A4D6C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A4D70: lwc1        $f12, 0xF4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801A4D74: lwc1        $f14, 0xF8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x801A4D78: lw          $a2, 0xFC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XFC);
    // 0x801A4D7C: lw          $a3, 0x158($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X158);
    // 0x801A4D80: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A4D84: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A4D88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A4D8C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A4D90: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A4D94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A4D98: mul.s       $f6, $f20, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x801A4D9C: lwc1        $f10, 0x160($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X160);
    // 0x801A4DA0: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x801A4DA4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801A4DA8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801A4DAC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A4DB0: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x801A4DB4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A4DB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A4DBC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801A4DC0: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801A4DC4: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801A4DC8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A4DCC: jal         0x801A1E14
    // 0x801A4DD0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    Solar_ActorDebris_Spawn(rdram, ctx);
        goto after_23;
    // 0x801A4DD0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_23:
    // 0x801A4DD4: lh          $v1, 0x4C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4C);
L_801A4DD8:
    // 0x801A4DD8: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801A4DDC: lui         $a0, 0x2943
    ctx->r4 = S32(0X2943 << 16);
    // 0x801A4DE0: beq         $v1, $at, L_801A4E04
    if (ctx->r3 == ctx->r1) {
        // 0x801A4DE4: ori         $a0, $a0, 0x3074
        ctx->r4 = ctx->r4 | 0X3074;
            goto L_801A4E04;
    }
    // 0x801A4DE4: ori         $a0, $a0, 0x3074
    ctx->r4 = ctx->r4 | 0X3074;
    // 0x801A4DE8: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x801A4DEC: beq         $v1, $at, L_801A4E28
    if (ctx->r3 == ctx->r1) {
        // 0x801A4DF0: addiu       $at, $zero, 0x61
        ctx->r1 = ADD32(0, 0X61);
            goto L_801A4E28;
    }
    // 0x801A4DF0: addiu       $at, $zero, 0x61
    ctx->r1 = ADD32(0, 0X61);
    // 0x801A4DF4: beq         $v1, $at, L_801A4E28
    if (ctx->r3 == ctx->r1) {
        // 0x801A4DF8: nop
    
            goto L_801A4E28;
    }
    // 0x801A4DF8: nop

    // 0x801A4DFC: b           L_801A4E5C
    // 0x801A4E00: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
        goto L_801A4E5C;
    // 0x801A4E00: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
L_801A4E04:
    // 0x801A4E04: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x801A4E08: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801A4E0C: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x801A4E10: addiu       $a3, $t3, 0x5D34
    ctx->r7 = ADD32(ctx->r11, 0X5D34);
    // 0x801A4E14: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A4E18: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801A4E1C: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x801A4E20: jal         0x80019218
    // 0x801A4E24: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_24;
    // 0x801A4E24: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_24:
L_801A4E28:
    // 0x801A4E28: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A4E2C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801A4E30: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A4E34: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801A4E38: lui         $a0, 0x2943
    ctx->r4 = S32(0X2943 << 16);
    // 0x801A4E3C: ori         $a0, $a0, 0x4075
    ctx->r4 = ctx->r4 | 0X4075;
    // 0x801A4E40: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801A4E44: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A4E48: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x801A4E4C: jal         0x80019218
    // 0x801A4E50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_25;
    // 0x801A4E50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_25:
    // 0x801A4E54: lh          $v1, 0x4C($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4C);
    // 0x801A4E58: addiu       $at, $zero, 0x77
    ctx->r1 = ADD32(0, 0X77);
L_801A4E5C:
    // 0x801A4E5C: bnel        $v1, $at, L_801A4EA8
    if (ctx->r3 != ctx->r1) {
        // 0x801A4E60: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_801A4EA8;
    }
    goto skip_2;
    // 0x801A4E60: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_2:
    // 0x801A4E64: lh          $v0, 0x92($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X92);
    // 0x801A4E68: lh          $t6, 0x94($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X94);
    // 0x801A4E6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A4E70: sh          $v0, 0x88($s0)
    MEM_H(0X88, ctx->r16) = ctx->r2;
    // 0x801A4E74: beq         $v0, $at, L_801A4E88
    if (ctx->r2 == ctx->r1) {
        // 0x801A4E78: sh          $t6, 0x8A($s0)
        MEM_H(0X8A, ctx->r16) = ctx->r14;
            goto L_801A4E88;
    }
    // 0x801A4E78: sh          $t6, 0x8A($s0)
    MEM_H(0X8A, ctx->r16) = ctx->r14;
    // 0x801A4E7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A4E80: bnel        $v0, $at, L_801A4E98
    if (ctx->r2 != ctx->r1) {
        // 0x801A4E84: sh          $zero, 0x4C($s0)
        MEM_H(0X4C, ctx->r16) = 0;
            goto L_801A4E98;
    }
    goto skip_3;
    // 0x801A4E84: sh          $zero, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = 0;
    skip_3:
L_801A4E88:
    // 0x801A4E88: lh          $t7, 0x96($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X96);
    // 0x801A4E8C: b           L_801A4E98
    // 0x801A4E90: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
        goto L_801A4E98;
    // 0x801A4E90: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    // 0x801A4E94: sh          $zero, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = 0;
L_801A4E98:
    // 0x801A4E98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A4E9C: lwc1        $f10, 0x1774($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1774);
    // 0x801A4EA0: swc1        $f10, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f10.u32l;
    // 0x801A4EA4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_801A4EA8:
    // 0x801A4EA8: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801A4EAC: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x801A4EB0: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x801A4EB4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801A4EB8: jr          $ra
    // 0x801A4EBC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801A4EBC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Area6_8018BCD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BCD4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8018BCD8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8018BCDC: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8018BCE0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018BCE4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018BCE8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8018BCEC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8018BCF0: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8018BCF4: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8018BCF8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8018BCFC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018BD00: addiu       $s0, $s0, 0x22F0
    ctx->r16 = ADD32(ctx->r16, 0X22F0);
    // 0x8018BD04: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8018BD08: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8018BD0C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8018BD10: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8018BD14: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8018BD18: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8018BD1C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8018BD20: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8018BD24: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018BD28: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x8018BD2C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018BD30: addiu       $t7, $t7, -0xB3C
    ctx->r15 = ADD32(ctx->r15, -0XB3C);
    // 0x8018BD34: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8018BD38: addiu       $t6, $sp, 0x90
    ctx->r14 = ADD32(ctx->r29, 0X90);
    // 0x8018BD3C: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8018BD40: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8018BD44: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8018BD48: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8018BD4C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8018BD50: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8018BD54: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018BD58: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8018BD5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018BD60: c.eq.s      $f26, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f26.fl == ctx->f4.fl;
    // 0x8018BD64: nop

    // 0x8018BD68: bc1tl       L_8018C094
    if (c1cs) {
        // 0x8018BD6C: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_8018C094;
    }
    goto skip_0;
    // 0x8018BD6C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x8018BD70: jal         0x800B8DD0
    // 0x8018BD74: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018BD74: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_0:
    // 0x8018BD78: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018BD7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018BD80: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018BD84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018BD88: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8018BD8C: nop

    // 0x8018BD90: bc1tl       L_8018BDE0
    if (c1cs) {
        // 0x8018BD94: lw          $t8, 0xB0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XB0);
            goto L_8018BDE0;
    }
    goto skip_1;
    // 0x8018BD94: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
    skip_1:
    // 0x8018BD98: jal         0x800B8DD0
    // 0x8018BD9C: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018BD9C: addiu       $a1, $zero, 0x47
    ctx->r5 = ADD32(0, 0X47);
    after_1:
    // 0x8018BDA0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018BDA4: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8018BDA8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018BDAC: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8018BDB0: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018BDB4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8018BDB8: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8018BDBC: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8018BDC0: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x8018BDC4: nop

    // 0x8018BDC8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8018BDCC: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x8018BDD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8018BDD4: b           L_8018BE54
    // 0x8018BDD8: nop

        goto L_8018BE54;
    // 0x8018BDD8: nop

    // 0x8018BDDC: lw          $t8, 0xB0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB0);
L_8018BDE0:
    // 0x8018BDE0: beq         $t8, $zero, L_8018BE54
    if (ctx->r24 == 0) {
        // 0x8018BDE4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8018BE54;
    }
    // 0x8018BDE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018BDE8: jal         0x800B8DD0
    // 0x8018BDEC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8018BDEC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_2:
    // 0x8018BDF0: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8018BDF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018BDF8: lwc1        $f18, 0xBC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8018BDFC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018BE00: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8018BE04: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8018BE08: nop

    // 0x8018BE0C: bc1fl       L_8018BE3C
    if (!c1cs) {
        // 0x8018BE10: lw          $v0, 0x0($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X0);
            goto L_8018BE3C;
    }
    goto skip_2;
    // 0x8018BE10: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x8018BE14: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018BE18: lui         $t0, 0xFF00
    ctx->r8 = S32(0XFF00 << 16);
    // 0x8018BE1C: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8018BE20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018BE24: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018BE28: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8018BE2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018BE30: b           L_8018BE54
    // 0x8018BE34: nop

        goto L_8018BE54;
    // 0x8018BE34: nop

    // 0x8018BE38: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_8018BE3C:
    // 0x8018BE3C: lui         $t3, 0xFFFF
    ctx->r11 = S32(0XFFFF << 16);
    // 0x8018BE40: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x8018BE44: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8018BE48: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018BE4C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018BE50: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_8018BE54:
    // 0x8018BE54: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x8018BE58: addiu       $s5, $s5, -0x4C40
    ctx->r21 = ADD32(ctx->r21, -0X4C40);
    // 0x8018BE5C: jal         0x80005708
    // 0x8018BE60: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x8018BE60: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_3:
    // 0x8018BE64: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8018BE68: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8018BE6C: jal         0x80005708
    // 0x8018BE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x8018BE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8018BE74: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8018BE78: addiu       $a1, $a1, 0x4660
    ctx->r5 = ADD32(ctx->r5, 0X4660);
    // 0x8018BE7C: jal         0x80005680
    // 0x8018BE80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_5;
    // 0x8018BE80: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x8018BE84: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BE88: lwc1        $f24, 0xA8C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0XA8C);
    // 0x8018BE8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018BE90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018BE94: mul.s       $f6, $f24, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8018BE98: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018BE9C: jal         0x80005FE0
    // 0x8018BEA0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x8018BEA0: nop

    after_6:
    // 0x8018BEA4: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018BEA8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018BEAC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018BEB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018BEB4: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x8018BEB8: jal         0x80005B00
    // 0x8018BEBC: lui         $a3, 0xC35F
    ctx->r7 = S32(0XC35F << 16);
    Matrix_Translate(rdram, ctx);
        goto after_7;
    // 0x8018BEBC: lui         $a3, 0xC35F
    ctx->r7 = S32(0XC35F << 16);
    after_7:
    // 0x8018BEC0: mul.s       $f8, $f24, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x8018BEC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018BEC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018BECC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018BED0: jal         0x80005D44
    // 0x8018BED4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_8;
    // 0x8018BED4: nop

    after_8:
    // 0x8018BED8: lw          $fp, 0xB8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB8);
    // 0x8018BEDC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8018BEE0: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x8018BEE4: blez        $fp, L_8018C088
    if (SIGNED(ctx->r30) <= 0) {
        // 0x8018BEE8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8018C088;
    }
    // 0x8018BEE8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018BEEC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018BEF0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8018BEF4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018BEF8: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x8018BEFC: addiu       $s6, $zero, 0x2000
    ctx->r22 = ADD32(0, 0X2000);
L_8018BF00:
    // 0x8018BF00: jal         0x80005708
    // 0x8018BF04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x8018BF04: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_9:
    // 0x8018BF08: jal         0x80005708
    // 0x8018BF0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_10;
    // 0x8018BF0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8018BF10: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8018BF14: bne         $s4, $at, L_8018BF9C
    if (ctx->r20 != ctx->r1) {
        // 0x8018BF18: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8018BF9C;
    }
    // 0x8018BF18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018BF1C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018BF20: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018BF24: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018BF28: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018BF2C: lui         $s2, 0x601
    ctx->r18 = S32(0X601 << 16);
    // 0x8018BF30: addiu       $s2, $s2, -0xE10
    ctx->r18 = ADD32(ctx->r18, -0XE10);
    // 0x8018BF34: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8018BF38: jal         0x80005C34
    // 0x8018BF3C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x8018BF3C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x8018BF40: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8018BF44: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018BF48: jal         0x80005754
    // 0x8018BF4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_12;
    // 0x8018BF4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8018BF50: jal         0x80006EB8
    // 0x8018BF54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_13;
    // 0x8018BF54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8018BF58: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018BF5C: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x8018BF60: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8018BF64: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8018BF68: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8018BF6C: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8018BF70: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018BF74: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018BF78: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8018BF7C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8018BF80: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x8018BF84: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8018BF88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018BF8C: jal         0x80006970
    // 0x8018BF90: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x8018BF90: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    after_14:
    // 0x8018BF94: b           L_8018C018
    // 0x8018BF98: nop

        goto L_8018C018;
    // 0x8018BF98: nop

L_8018BF9C:
    // 0x8018BF9C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018BFA0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8018BFA4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8018BFA8: lui         $s2, 0x601
    ctx->r18 = S32(0X601 << 16);
    // 0x8018BFAC: addiu       $s2, $s2, 0x5EE0
    ctx->r18 = ADD32(ctx->r18, 0X5EE0);
    // 0x8018BFB0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018BFB4: jal         0x80005C34
    // 0x8018BFB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Matrix_Scale(rdram, ctx);
        goto after_15;
    // 0x8018BFB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_15:
    // 0x8018BFBC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8018BFC0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018BFC4: jal         0x80005754
    // 0x8018BFC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_16;
    // 0x8018BFC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x8018BFCC: jal         0x80006EB8
    // 0x8018BFD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_17;
    // 0x8018BFD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x8018BFD4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018BFD8: lui         $t1, 0xB600
    ctx->r9 = S32(0XB600 << 16);
    // 0x8018BFDC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8018BFE0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8018BFE4: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x8018BFE8: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8018BFEC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018BFF0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8018BFF4: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x8018BFF8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8018BFFC: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8018C000: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x8018C004: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8018C008: beq         $fp, $at, L_8018C018
    if (ctx->r30 == ctx->r1) {
        // 0x8018C00C: lw          $a2, 0xAC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XAC);
            goto L_8018C018;
    }
    // 0x8018C00C: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8018C010: jal         0x80006970
    // 0x8018C014: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_18;
    // 0x8018C014: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_18:
L_8018C018:
    // 0x8018C018: jal         0x80005740
    // 0x8018C01C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x8018C01C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_19:
    // 0x8018C020: jal         0x80005740
    // 0x8018C024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x8018C024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8018C028: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8018C02C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018C030: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C034: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8018C038: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8018C03C: jal         0x80005E90
    // 0x8018C040: nop

    Matrix_RotateY(rdram, ctx);
        goto after_21;
    // 0x8018C040: nop

    after_21:
    // 0x8018C044: lwc1        $f18, 0x0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8018C048: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018C04C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018C050: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8018C054: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018C058: jal         0x80005D44
    // 0x8018C05C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_22;
    // 0x8018C05C: nop

    after_22:
    // 0x8018C060: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018C064: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x8018C068: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018C06C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018C070: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8018C074: jal         0x80005B00
    // 0x8018C078: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    Matrix_Translate(rdram, ctx);
        goto after_23;
    // 0x8018C078: lw          $a3, 0xB4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB4);
    after_23:
    // 0x8018C07C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8018C080: bne         $s4, $fp, L_8018BF00
    if (ctx->r20 != ctx->r30) {
        // 0x8018C084: addiu       $s3, $s3, 0xC
        ctx->r19 = ADD32(ctx->r19, 0XC);
            goto L_8018BF00;
    }
    // 0x8018C084: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
L_8018C088:
    // 0x8018C088: jal         0x80005740
    // 0x8018C08C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_24;
    // 0x8018C08C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_24:
    // 0x8018C090: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_8018C094:
    // 0x8018C094: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018C098: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018C09C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018C0A0: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8018C0A4: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8018C0A8: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8018C0AC: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8018C0B0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8018C0B4: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8018C0B8: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8018C0BC: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8018C0C0: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8018C0C4: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8018C0C8: jr          $ra
    // 0x8018C0CC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8018C0CC: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Aquas_801A9C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9C98: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801A9C9C: addiu       $a2, $a2, 0x4190
    ctx->r6 = ADD32(ctx->r6, 0X4190);
    // 0x801A9CA0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801A9CA4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x801A9CA8: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x801A9CAC: beq         $v0, $at, L_801A9DDC
    if (ctx->r2 == ctx->r1) {
        // 0x801A9CB0: nop
    
            goto L_801A9DDC;
    }
    // 0x801A9CB0: nop

    // 0x801A9CB4: blez        $v0, L_801A9DDC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801A9CB8: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_801A9DDC;
    }
    // 0x801A9CB8: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x801A9CBC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801A9CC0: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801A9CC4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x801A9CC8: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801A9CCC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801A9CD0: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x801A9CD4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801A9CD8: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x801A9CDC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801A9CE0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x801A9CE4: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x801A9CE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A9CEC: bne         $t8, $at, L_801A9D4C
    if (ctx->r24 != ctx->r1) {
        // 0x801A9CF0: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_801A9D4C;
    }
    // 0x801A9CF0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A9CF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A9CF8: lwc1        $f0, 0x138($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X138);
    // 0x801A9CFC: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x801A9D00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A9D04: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x801A9D08: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x801A9D0C: nop

    // 0x801A9D10: bc1tl       L_801A9D50
    if (c1cs) {
        // 0x801A9D14: sw          $zero, 0x4($a2)
        MEM_W(0X4, ctx->r6) = 0;
            goto L_801A9D50;
    }
    goto skip_0;
    // 0x801A9D14: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    skip_0:
    // 0x801A9D18: lwc1        $f8, 0x1A74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1A74);
    // 0x801A9D1C: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x801A9D20: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x801A9D24: nop

    // 0x801A9D28: bc1tl       L_801A9D50
    if (c1cs) {
        // 0x801A9D2C: sw          $zero, 0x4($a2)
        MEM_W(0X4, ctx->r6) = 0;
            goto L_801A9D50;
    }
    goto skip_1;
    // 0x801A9D2C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    skip_1:
    // 0x801A9D30: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x801A9D34: lw          $t0, 0x4($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X4);
    // 0x801A9D38: bnel        $t9, $t0, L_801A9D50
    if (ctx->r25 != ctx->r8) {
        // 0x801A9D3C: sw          $zero, 0x4($a2)
        MEM_W(0X4, ctx->r6) = 0;
            goto L_801A9D50;
    }
    goto skip_2;
    // 0x801A9D3C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    skip_2:
    // 0x801A9D40: lh          $t1, 0xCE($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XCE);
    // 0x801A9D44: bnel        $t1, $zero, L_801A9D64
    if (ctx->r9 != 0) {
        // 0x801A9D48: lw          $a1, 0x28($a0)
        ctx->r5 = MEM_W(ctx->r4, 0X28);
            goto L_801A9D64;
    }
    goto skip_3;
    // 0x801A9D48: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
    skip_3:
L_801A9D4C:
    // 0x801A9D4C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
L_801A9D50:
    // 0x801A9D50: sw          $zero, 0x14($a2)
    MEM_W(0X14, ctx->r6) = 0;
    // 0x801A9D54: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x801A9D58: jr          $ra
    // 0x801A9D5C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    return;
    // 0x801A9D5C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x801A9D60: lw          $a1, 0x28($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X28);
L_801A9D64:
    // 0x801A9D64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A9D68: lwc1        $f16, 0x1A78($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1A78);
    // 0x801A9D6C: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801A9D70: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A9D74: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x801A9D78: nop

    // 0x801A9D7C: bc1fl       L_801A9D8C
    if (!c1cs) {
        // 0x801A9D80: sll         $v1, $v0, 2
        ctx->r3 = S32(ctx->r2 << 2);
            goto L_801A9D8C;
    }
    goto skip_4;
    // 0x801A9D80: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    skip_4:
    // 0x801A9D84: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801A9D88: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
L_801A9D8C:
    // 0x801A9D8C: addu        $a2, $a1, $v1
    ctx->r6 = ADD32(ctx->r5, ctx->r3);
    // 0x801A9D90: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801A9D94: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801A9D98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A9D9C: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x801A9DA0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801A9DA4: swc1        $f10, 0x41C0($at)
    MEM_W(0X41C0, ctx->r1) = ctx->f10.u32l;
    // 0x801A9DA8: lw          $t2, 0x28($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X28);
    // 0x801A9DAC: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x801A9DB0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A9DB4: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x801A9DB8: lwc1        $f16, 0x8($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X8);
    // 0x801A9DBC: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A9DC0: swc1        $f6, 0x41BC($at)
    MEM_W(0X41BC, ctx->r1) = ctx->f6.u32l;
    // 0x801A9DC4: lw          $t4, 0x28($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X28);
    // 0x801A9DC8: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x801A9DCC: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x801A9DD0: lwc1        $f4, 0x10($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X10);
    // 0x801A9DD4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801A9DD8: swc1        $f10, 0x41B8($at)
    MEM_W(0X41B8, ctx->r1) = ctx->f10.u32l;
L_801A9DDC:
    // 0x801A9DDC: jr          $ra
    // 0x801A9DE0: nop

    return;
    // 0x801A9DE0: nop

;}
RECOMP_FUNC void Aquas_Bubble_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC7C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801AC7CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801AC7D0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801AC7D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801AC7D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801AC7DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801AC7E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801AC7E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801AC7E8: jal         0x80061474
    // 0x801AC7EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x801AC7EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801AC7F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801AC7F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AC7F8: addiu       $t7, $zero, 0x16E
    ctx->r15 = ADD32(0, 0X16E);
    // 0x801AC7FC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801AC800: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801AC804: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801AC808: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801AC80C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AC810: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801AC814: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AC818: jal         0x80004EB0
    // 0x801AC81C: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801AC81C: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x801AC820: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801AC824: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AC828: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801AC82C: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x801AC830: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801AC834: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AC838: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x801AC83C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801AC840: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x801AC844: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801AC848: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    // 0x801AC84C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x801AC850: sh          $t9, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = ctx->r25;
    // 0x801AC854: sh          $t8, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r24;
    // 0x801AC858: lwc1        $f4, 0x1B70($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X1B70);
    // 0x801AC85C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801AC860: sh          $t0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r8;
    // 0x801AC864: lh          $t1, 0x4E($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X4E);
    // 0x801AC868: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801AC86C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801AC870: swc1        $f6, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f6.u32l;
    // 0x801AC874: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801AC878: lwc1        $f8, 0x114($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X114);
    // 0x801AC87C: lwc1        $f10, 0xE8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x801AC880: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801AC884: bne         $t1, $at, L_801AC890
    if (ctx->r9 != ctx->r1) {
        // 0x801AC888: swc1        $f16, 0x64($a2)
        MEM_W(0X64, ctx->r6) = ctx->f16.u32l;
            goto L_801AC890;
    }
    // 0x801AC888: swc1        $f16, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f16.u32l;
    // 0x801AC88C: sh          $t2, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r10;
L_801AC890:
    // 0x801AC890: jal         0x800612B8
    // 0x801AC894: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x801AC894: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_2:
    // 0x801AC898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801AC89C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801AC8A0: jr          $ra
    // 0x801AC8A4: nop

    return;
    // 0x801AC8A4: nop

;}
RECOMP_FUNC void Area6_A6Gorgon_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187944: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x80187948: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8018794C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80187950: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80187954: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80187958: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8018795C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80187960: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80187964: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80187968: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8018796C: lw          $t6, 0x13A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13A0);
    // 0x80187970: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187974: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80187978: sw          $t7, 0x13A0($at)
    MEM_W(0X13A0, ctx->r1) = ctx->r15;
    // 0x8018797C: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
    // 0x80187980: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80187984: bne         $at, $zero, L_80187998
    if (ctx->r1 != 0) {
        // 0x80187988: slti        $at, $v0, 0x8
        ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
            goto L_80187998;
    }
    // 0x80187988: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8018798C: bne         $at, $zero, L_80187A40
    if (ctx->r1 != 0) {
        // 0x80187990: slti        $at, $v0, 0xC
        ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
            goto L_80187A40;
    }
    // 0x80187990: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x80187994: beq         $at, $zero, L_80187A40
    if (ctx->r1 == 0) {
        // 0x80187998: lui         $s0, 0x8018
        ctx->r16 = S32(0X8018 << 16);
            goto L_80187A40;
    }
L_80187998:
    // 0x80187998: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8018799C: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x801879A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801879A4: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801879A8: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801879AC: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801879B0: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801879B4: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801879B8: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801879BC: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801879C0: jal         0x80005100
    // 0x801879C4: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x801879C4: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    after_0:
    // 0x801879C8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801879CC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801879D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801879D4: lwc1        $f22, 0x91C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X91C);
    // 0x801879D8: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x801879DC: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801879E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801879E4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801879E8: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801879EC: div.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x801879F0: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    // 0x801879F4: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x801879F8: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801879FC: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80187A00: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80187A04: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80187A08: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80187A0C: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80187A10: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80187A14: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80187A18: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80187A1C: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80187A20: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80187A24: add.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80187A28: jal         0x80005100
    // 0x80187A2C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x80187A2C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x80187A30: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80187A34: mul.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80187A38: div.s       $f18, $f4, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80187A3C: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
L_80187A40:
    // 0x80187A40: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187A44: lwc1        $f10, 0x920($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X920);
    // 0x80187A48: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80187A4C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187A50: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187A54: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80187A58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80187A5C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80187A60: jal         0x80005E90
    // 0x80187A64: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80187A64: nop

    after_2:
    // 0x80187A68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187A6C: lwc1        $f18, 0x924($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X924);
    // 0x80187A70: lwc1        $f4, 0x10($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80187A74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187A78: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187A7C: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80187A80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80187A84: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80187A88: jal         0x80005D44
    // 0x80187A8C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x80187A8C: nop

    after_3:
    // 0x80187A90: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187A94: lwc1        $f8, 0x928($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X928);
    // 0x80187A98: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80187A9C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187AA0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187AA4: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80187AA8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80187AAC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80187AB0: jal         0x80005FE0
    // 0x80187AB4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x80187AB4: nop

    after_4:
    // 0x80187AB8: lb          $t8, 0x62($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X62);
    // 0x80187ABC: beql        $t8, $zero, L_80187E58
    if (ctx->r24 == 0) {
        // 0x80187AC0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80187E58;
    }
    goto skip_0;
    // 0x80187AC0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_0:
    // 0x80187AC4: lh          $t9, 0x60($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X60);
    // 0x80187AC8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80187ACC: blezl       $t9, L_80187E58
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80187AD0: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_80187E58;
    }
    goto skip_1;
    // 0x80187AD0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_1:
    // 0x80187AD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80187AD8: lwc1        $f6, 0xD8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x80187ADC: sb          $zero, 0x62($s1)
    MEM_B(0X62, ctx->r17) = 0;
    // 0x80187AE0: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x80187AE4: nop

    // 0x80187AE8: bc1fl       L_80187DF8
    if (!c1cs) {
        // 0x80187AEC: lh          $v0, 0x66($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X66);
            goto L_80187DF8;
    }
    goto skip_2;
    // 0x80187AEC: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
    skip_2:
    // 0x80187AF0: lh          $t0, 0x66($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X66);
    // 0x80187AF4: bnel        $t0, $zero, L_80187DC4
    if (ctx->r8 != 0) {
        // 0x80187AF8: lh          $v0, 0x66($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X66);
            goto L_80187DC4;
    }
    goto skip_3;
    // 0x80187AF8: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
    skip_3:
    // 0x80187AFC: lh          $t1, 0xBA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XBA);
    // 0x80187B00: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80187B04: bnel        $t1, $zero, L_80187DC4
    if (ctx->r9 != 0) {
        // 0x80187B08: lh          $v0, 0x66($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X66);
            goto L_80187DC4;
    }
    goto skip_4;
    // 0x80187B08: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
    skip_4:
    // 0x80187B0C: lwc1        $f10, 0x14C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14C);
    // 0x80187B10: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80187B14: nop

    // 0x80187B18: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80187B1C: nop

    // 0x80187B20: bc1fl       L_80187DC4
    if (!c1cs) {
        // 0x80187B24: lh          $v0, 0x66($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X66);
            goto L_80187DC4;
    }
    goto skip_5;
    // 0x80187B24: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
    skip_5:
    // 0x80187B28: lh          $t3, 0x60($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X60);
    // 0x80187B2C: lh          $t4, 0x64($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X64);
    // 0x80187B30: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x80187B34: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80187B38: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80187B3C: sh          $t5, 0x60($s1)
    MEM_H(0X60, ctx->r17) = ctx->r13;
    // 0x80187B40: lh          $t6, 0x60($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X60);
    // 0x80187B44: sh          $t2, 0x5C($s1)
    MEM_H(0X5C, ctx->r17) = ctx->r10;
    // 0x80187B48: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x80187B4C: slti        $at, $t6, 0x186
    ctx->r1 = SIGNED(ctx->r14) < 0X186 ? 1 : 0;
    // 0x80187B50: beq         $at, $zero, L_80187B90
    if (ctx->r1 == 0) {
        // 0x80187B54: addiu       $a1, $s1, 0x3FC
        ctx->r5 = ADD32(ctx->r17, 0X3FC);
            goto L_80187B90;
    }
    // 0x80187B54: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80187B58: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80187B5C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80187B60: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80187B64: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80187B68: lui         $a0, 0x2943
    ctx->r4 = S32(0X2943 << 16);
    // 0x80187B6C: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80187B70: sw          $a1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r5;
    // 0x80187B74: ori         $a0, $a0, 0x500F
    ctx->r4 = ctx->r4 | 0X500F;
    // 0x80187B78: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80187B7C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80187B80: jal         0x80019218
    // 0x80187B84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80187B84: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80187B88: b           L_80187BB8
    // 0x80187B8C: lh          $t0, 0x60($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X60);
        goto L_80187BB8;
    // 0x80187B8C: lh          $t0, 0x60($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X60);
L_80187B90:
    // 0x80187B90: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80187B94: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80187B98: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80187B9C: addiu       $a3, $t8, 0x5D34
    ctx->r7 = ADD32(ctx->r24, 0X5D34);
    // 0x80187BA0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80187BA4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80187BA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80187BAC: jal         0x80019218
    // 0x80187BB0: sw          $a1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r5;
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x80187BB0: sw          $a1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r5;
    after_6:
    // 0x80187BB4: lh          $t0, 0x60($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X60);
L_80187BB8:
    // 0x80187BB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80187BBC: bgtzl       $t0, L_80187DC4
    if (SIGNED(ctx->r8) > 0) {
        // 0x80187BC0: lh          $v0, 0x66($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X66);
            goto L_80187DC4;
    }
    goto skip_6;
    // 0x80187BC0: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
    skip_6:
    // 0x80187BC4: jal         0x80042EC0
    // 0x80187BC8: sh          $zero, 0x60($s1)
    MEM_H(0X60, ctx->r17) = 0;
    Boss_AwardBonus(rdram, ctx);
        goto after_7;
    // 0x80187BC8: sh          $zero, 0x60($s1)
    MEM_H(0X60, ctx->r17) = 0;
    after_7:
    // 0x80187BCC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80187BD0: addiu       $a0, $a0, 0xFFC
    ctx->r4 = ADD32(ctx->r4, 0XFFC);
    // 0x80187BD4: jal         0x800BA808
    // 0x80187BD8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_8;
    // 0x80187BD8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_8:
    // 0x80187BDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80187BE0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80187BE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187BE8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80187BEC: sw          $t1, 0x796C($at)
    MEM_W(0X796C, ctx->r1) = ctx->r9;
    // 0x80187BF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187BF4: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80187BF8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187BFC: lwc1        $f18, 0x92C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X92C);
    // 0x80187C00: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80187C04: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80187C08: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80187C0C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80187C10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187C14: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80187C18: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x80187C1C: ori         $a0, $a0, 0xD09A
    ctx->r4 = ctx->r4 | 0XD09A;
    // 0x80187C20: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80187C24: add.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80187C28: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80187C2C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80187C30: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80187C34: jal         0x80019218
    // 0x80187C38: swc1        $f10, -0x67C($at)
    MEM_W(-0X67C, ctx->r1) = ctx->f10.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x80187C38: swc1        $f10, -0x67C($at)
    MEM_W(-0X67C, ctx->r1) = ctx->f10.u32l;
    after_9:
    // 0x80187C3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187C40: lui         $a0, 0x1028
    ctx->r4 = S32(0X1028 << 16);
    // 0x80187C44: sw          $zero, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = 0;
    // 0x80187C48: jal         0x800182F4
    // 0x80187C4C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_10;
    // 0x80187C4C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_10:
    // 0x80187C50: lui         $a0, 0x1128
    ctx->r4 = S32(0X1128 << 16);
    // 0x80187C54: jal         0x800182F4
    // 0x80187C58: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_11;
    // 0x80187C58: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_11:
    // 0x80187C5C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80187C60: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80187C64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187C68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187C6C: swc1        $f8, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f8.u32l;
    // 0x80187C70: lwc1        $f4, 0x930($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X930);
    // 0x80187C74: lui         $at, 0x432A
    ctx->r1 = S32(0X432A << 16);
    // 0x80187C78: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80187C7C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80187C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80187C84: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80187C88: swc1        $f4, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f4.u32l;
    // 0x80187C8C: swc1        $f18, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f18.u32l;
    // 0x80187C90: swc1        $f6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f6.u32l;
    // 0x80187C94: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187C98: addiu       $a1, $a1, -0x1320
    ctx->r5 = ADD32(ctx->r5, -0X1320);
    // 0x80187C9C: jal         0x80006970
    // 0x80187CA0: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x80187CA0: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_12:
    // 0x80187CA4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187CA8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80187CAC: addiu       $a1, $a1, -0x1314
    ctx->r5 = ADD32(ctx->r5, -0X1314);
    // 0x80187CB0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187CB4: jal         0x80006970
    // 0x80187CB8: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x80187CB8: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    after_13:
    // 0x80187CBC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187CC0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80187CC4: addiu       $a1, $a1, -0x1308
    ctx->r5 = ADD32(ctx->r5, -0X1308);
    // 0x80187CC8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80187CCC: jal         0x80006970
    // 0x80187CD0: addiu       $a2, $sp, 0xBC
    ctx->r6 = ADD32(ctx->r29, 0XBC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x80187CD0: addiu       $a2, $sp, 0xBC
    ctx->r6 = ADD32(ctx->r29, 0XBC);
    after_14:
    // 0x80187CD4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80187CD8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80187CDC: addiu       $v0, $sp, 0xA4
    ctx->r2 = ADD32(ctx->r29, 0XA4);
    // 0x80187CE0: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x80187CE4: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
L_80187CE8:
    // 0x80187CE8: lwc1        $f20, 0xC($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80187CEC: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80187CF0: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80187CF4: add.s       $f20, $f22, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x80187CF8: lwc1        $f22, 0x4($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80187CFC: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80187D00: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80187D04: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187D08: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80187D0C: add.s       $f14, $f22, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x80187D10: jal         0x8007D0E0
    // 0x80187D14: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_15;
    // 0x80187D14: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_15:
    // 0x80187D18: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80187D1C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80187D20: bnel        $v0, $s0, L_80187CE8
    if (ctx->r2 != ctx->r16) {
        // 0x80187D24: lwc1        $f22, 0x8($v0)
        ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
            goto L_80187CE8;
    }
    goto skip_7;
    // 0x80187D24: lwc1        $f22, 0x8($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X8);
    skip_7:
    // 0x80187D28: sh          $zero, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = 0;
    // 0x80187D2C: lh          $v0, 0xCE($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XCE);
    // 0x80187D30: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80187D34: addiu       $t3, $zero, 0xAA
    ctx->r11 = ADD32(0, 0XAA);
    // 0x80187D38: addiu       $s2, $s2, 0x2250
    ctx->r18 = ADD32(ctx->r18, 0X2250);
    // 0x80187D3C: sh          $t3, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r11;
    // 0x80187D40: sh          $v0, 0xCC($s1)
    MEM_H(0XCC, ctx->r17) = ctx->r2;
    // 0x80187D44: sh          $v0, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r2;
    // 0x80187D48: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80187D4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80187D50: sw          $v0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r2;
    // 0x80187D54: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    // 0x80187D58: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x80187D5C: sh          $t4, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = ctx->r12;
    // 0x80187D60: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80187D64: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80187D68: sh          $t5, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r13;
    // 0x80187D6C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80187D70: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80187D74: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80187D78: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x80187D7C: ori         $a0, $a0, 0xC00A
    ctx->r4 = ctx->r4 | 0XC00A;
    // 0x80187D80: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80187D84: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80187D88: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80187D8C: jal         0x80019218
    // 0x80187D90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_16;
    // 0x80187D90: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_16:
    // 0x80187D94: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80187D98: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80187D9C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80187DA0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80187DA4: lui         $a0, 0x3143
    ctx->r4 = S32(0X3143 << 16);
    // 0x80187DA8: ori         $a0, $a0, 0x402E
    ctx->r4 = ctx->r4 | 0X402E;
    // 0x80187DAC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80187DB0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80187DB4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80187DB8: jal         0x80019218
    // 0x80187DBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_17;
    // 0x80187DBC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_17:
    // 0x80187DC0: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
L_80187DC4:
    // 0x80187DC4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80187DC8: beq         $v0, $at, L_80187DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80187DCC: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80187DE0;
    }
    // 0x80187DCC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80187DD0: beq         $v0, $at, L_80187DE0
    if (ctx->r2 == ctx->r1) {
        // 0x80187DD4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80187DE0;
    }
    // 0x80187DD4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80187DD8: bnel        $v0, $at, L_80187DF8
    if (ctx->r2 != ctx->r1) {
        // 0x80187DDC: lh          $v0, 0x66($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X66);
            goto L_80187DF8;
    }
    goto skip_8;
    // 0x80187DDC: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
    skip_8:
L_80187DE0:
    // 0x80187DE0: lh          $t8, 0xBA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XBA);
    // 0x80187DE4: beql        $t8, $zero, L_80187DF8
    if (ctx->r24 == 0) {
        // 0x80187DE8: lh          $v0, 0x66($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X66);
            goto L_80187DF8;
    }
    goto skip_9;
    // 0x80187DE8: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
    skip_9:
    // 0x80187DEC: jal         0x8018B9BC
    // 0x80187DF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Area6_8018B9BC(rdram, ctx);
        goto after_18;
    // 0x80187DF0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
    // 0x80187DF4: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
L_80187DF8:
    // 0x80187DF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80187DFC: beq         $v0, $at, L_80187E14
    if (ctx->r2 == ctx->r1) {
        // 0x80187E00: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80187E14;
    }
    // 0x80187E00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80187E04: beq         $v0, $at, L_80187E14
    if (ctx->r2 == ctx->r1) {
        // 0x80187E08: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80187E14;
    }
    // 0x80187E08: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80187E0C: bnel        $v0, $at, L_80187E24
    if (ctx->r2 != ctx->r1) {
        // 0x80187E10: slti        $at, $v0, 0x7
        ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
            goto L_80187E24;
    }
    goto skip_10;
    // 0x80187E10: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    skip_10:
L_80187E14:
    // 0x80187E14: jal         0x8018A2C4
    // 0x80187E18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Area6_8018A2C4(rdram, ctx);
        goto after_19;
    // 0x80187E18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80187E1C: lh          $v0, 0x66($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X66);
    // 0x80187E20: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
L_80187E24:
    // 0x80187E24: bne         $at, $zero, L_80187E54
    if (ctx->r1 != 0) {
        // 0x80187E28: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80187E54;
    }
    // 0x80187E28: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80187E2C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80187E30: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80187E34: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80187E38: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x80187E3C: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x80187E40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80187E44: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80187E48: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80187E4C: jal         0x80019218
    // 0x80187E50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_20;
    // 0x80187E50: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_20:
L_80187E54:
    // 0x80187E54: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_80187E58:
    // 0x80187E58: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80187E5C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80187E60: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80187E64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187E68: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80187E6C: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80187E70: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80187E74: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80187E78: addiu       $t2, $t2, 0x2308
    ctx->r10 = ADD32(ctx->r10, 0X2308);
    // 0x80187E7C: addiu       $t1, $t1, 0x22FC
    ctx->r9 = ADD32(ctx->r9, 0X22FC);
    // 0x80187E80: addiu       $t0, $t0, 0x22F0
    ctx->r8 = ADD32(ctx->r8, 0X22F0);
    // 0x80187E84: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80187E88: addiu       $s2, $s2, 0x2250
    ctx->r18 = ADD32(ctx->r18, 0X2250);
    // 0x80187E8C: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x80187E90: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80187E94: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x80187E98: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_80187E9C:
    // 0x80187E9C: lh          $s0, 0xA6($v1)
    ctx->r16 = MEM_H(ctx->r3, 0XA6);
    // 0x80187EA0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80187EA4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80187EA8: div         $zero, $s0, $at
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r1)));
    // 0x80187EAC: mflo        $t3
    ctx->r11 = lo;
    // 0x80187EB0: addiu       $s0, $t3, -0x1
    ctx->r16 = ADD32(ctx->r11, -0X1);
    // 0x80187EB4: bgez        $s0, L_80187EC0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80187EB8: lui         $t5, 0x801C
        ctx->r13 = S32(0X801C << 16);
            goto L_80187EC0;
    }
    // 0x80187EB8: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80187EBC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80187EC0:
    // 0x80187EC0: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x80187EC4: subu        $t4, $t4, $s0
    ctx->r12 = SUB32(ctx->r12, ctx->r16);
    // 0x80187EC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80187ECC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80187ED0: addiu       $t5, $t5, -0x1350
    ctx->r13 = ADD32(ctx->r13, -0X1350);
    // 0x80187ED4: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80187ED8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187EDC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80187EE0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80187EE4: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
    // 0x80187EE8: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x80187EEC: jal         0x8009BC2C
    // 0x80187EF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x80187EF0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_21:
    // 0x80187EF4: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80187EF8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80187EFC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187F00: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80187F04: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x80187F08: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80187F0C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80187F10: jal         0x8009BC2C
    // 0x80187F14: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x80187F14: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_22:
    // 0x80187F18: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80187F1C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80187F20: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80187F24: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80187F28: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    // 0x80187F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80187F30: jal         0x8009BC2C
    // 0x80187F34: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x80187F34: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_23:
    // 0x80187F38: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x80187F3C: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80187F40: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80187F44: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80187F48: addiu       $t2, $t2, 0x2314
    ctx->r10 = ADD32(ctx->r10, 0X2314);
    // 0x80187F4C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80187F50: sltu        $at, $s0, $t2
    ctx->r1 = ctx->r16 < ctx->r10 ? 1 : 0;
    // 0x80187F54: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80187F58: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x80187F5C: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80187F60: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x80187F64: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80187F68: bne         $at, $zero, L_80187E9C
    if (ctx->r1 != 0) {
        // 0x80187F6C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80187E9C;
    }
    // 0x80187F6C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80187F70: lh          $t3, 0xA6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XA6);
    // 0x80187F74: bne         $t3, $zero, L_80188008
    if (ctx->r11 != 0) {
        // 0x80187F78: nop
    
            goto L_80188008;
    }
    // 0x80187F78: nop

    // 0x80187F7C: lh          $t4, 0xA8($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XA8);
    // 0x80187F80: bne         $t4, $zero, L_80188008
    if (ctx->r12 != 0) {
        // 0x80187F84: nop
    
            goto L_80188008;
    }
    // 0x80187F84: nop

    // 0x80187F88: lh          $t5, 0xAA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XAA);
    // 0x80187F8C: bne         $t5, $zero, L_80188008
    if (ctx->r13 != 0) {
        // 0x80187F90: nop
    
            goto L_80188008;
    }
    // 0x80187F90: nop

    // 0x80187F94: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80187F98: lwc1        $f8, 0xD8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x80187F9C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80187FA0: c.eq.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl == ctx->f8.fl;
    // 0x80187FA4: nop

    // 0x80187FA8: bc1t        L_80188008
    if (c1cs) {
        // 0x80187FAC: nop
    
            goto L_80188008;
    }
    // 0x80187FAC: nop

    // 0x80187FB0: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x80187FB4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80187FB8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80187FBC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80187FC0: bne         $t7, $zero, L_80188008
    if (ctx->r15 != 0) {
        // 0x80187FC4: nop
    
            goto L_80188008;
    }
    // 0x80187FC4: nop

    // 0x80187FC8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80187FCC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80187FD0: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x80187FD4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80187FD8: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80187FDC: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80187FE0: lw          $a3, 0x6C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X6C);
    // 0x80187FE4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187FE8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80187FEC: lwc1        $f8, 0x74($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80187FF0: lwc1        $f4, 0x934($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X934);
    // 0x80187FF4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80187FF8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80187FFC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80188000: jal         0x8007C120
    // 0x80188004: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_24;
    // 0x80188004: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_24:
L_80188008:
    // 0x80188008: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018800C: lh          $t9, -0xE36($t9)
    ctx->r25 = MEM_H(ctx->r25, -0XE36);
    // 0x80188010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188014: mov.s       $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    ctx->f2.fl = ctx->f22.fl;
    // 0x80188018: bne         $t9, $at, L_80188028
    if (ctx->r25 != ctx->r1) {
        // 0x8018801C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80188028;
    }
    // 0x8018801C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80188020: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80188024: nop

L_80188028:
    // 0x80188028: lw          $t0, 0x28($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X28);
    // 0x8018802C: beq         $t0, $zero, L_80188070
    if (ctx->r8 == 0) {
        // 0x80188030: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80188070;
    }
    // 0x80188030: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188034: lwc1        $f18, 0x2324($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2324);
    // 0x80188038: add.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8018803C: swc1        $f6, 0x2324($at)
    MEM_W(0X2324, ctx->r1) = ctx->f6.u32l;
    // 0x80188040: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80188044: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188048: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018804C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x80188050: nop

    // 0x80188054: bc1fl       L_801880A8
    if (!c1cs) {
        // 0x80188058: lh          $v0, 0x4E($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X4E);
            goto L_801880A8;
    }
    goto skip_11;
    // 0x80188058: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
    skip_11:
    // 0x8018805C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188060: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188064: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80188068: b           L_801880A4
    // 0x8018806C: swc1        $f4, 0x2324($at)
    MEM_W(0X2324, ctx->r1) = ctx->f4.u32l;
        goto L_801880A4;
    // 0x8018806C: swc1        $f4, 0x2324($at)
    MEM_W(0X2324, ctx->r1) = ctx->f4.u32l;
L_80188070:
    // 0x80188070: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188074: lwc1        $f18, 0x2324($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X2324);
    // 0x80188078: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018807C: sub.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80188080: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80188084: swc1        $f6, 0x2324($at)
    MEM_W(0X2324, ctx->r1) = ctx->f6.u32l;
    // 0x80188088: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018808C: bc1fl       L_801880A8
    if (!c1cs) {
        // 0x80188090: lh          $v0, 0x4E($s1)
        ctx->r2 = MEM_H(ctx->r17, 0X4E);
            goto L_801880A8;
    }
    goto skip_12;
    // 0x80188090: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
    skip_12:
    // 0x80188094: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188098: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018809C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801880A0: swc1        $f4, 0x2324($at)
    MEM_W(0X2324, ctx->r1) = ctx->f4.u32l;
L_801880A4:
    // 0x801880A4: lh          $v0, 0x4E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X4E);
L_801880A8:
    // 0x801880A8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801880AC: bne         $at, $zero, L_801882AC
    if (ctx->r1 != 0) {
        // 0x801880B0: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_801882AC;
    }
    // 0x801880B0: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x801880B4: beql        $at, $zero, L_801882B0
    if (ctx->r1 == 0) {
        // 0x801880B8: lh          $t4, 0x4E($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X4E);
            goto L_801882B0;
    }
    goto skip_13;
    // 0x801880B8: lh          $t4, 0x4E($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4E);
    skip_13:
    // 0x801880BC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801880C0: lwc1        $f6, 0x148($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X148);
    // 0x801880C4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801880C8: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x801880CC: c.eq.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl == ctx->f6.fl;
    // 0x801880D0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x801880D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801880D8: addiu       $a0, $s1, 0xFC
    ctx->r4 = ADD32(ctx->r17, 0XFC);
    // 0x801880DC: bc1f        L_801882AC
    if (!c1cs) {
        // 0x801880E0: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_801882AC;
    }
    // 0x801880E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801880E4: lwc1        $f10, 0x938($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X938);
    // 0x801880E8: lw          $a1, 0x158($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X158);
    // 0x801880EC: jal         0x8009BD38
    // 0x801880F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_25;
    // 0x801880F0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_25:
    // 0x801880F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801880F8: lwc1        $f8, 0x93C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X93C);
    // 0x801880FC: lw          $a1, 0xF8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XF8);
    // 0x80188100: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80188104: lw          $a3, 0xFC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XFC);
    // 0x80188108: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018810C: addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // 0x80188110: jal         0x8009BD38
    // 0x80188114: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_26;
    // 0x80188114: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_26:
    // 0x80188118: lh          $t1, 0xBA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XBA);
    // 0x8018811C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80188120: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80188124: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x80188128: bne         $at, $zero, L_801881E0
    if (ctx->r1 != 0) {
        // 0x8018812C: nop
    
            goto L_801881E0;
    }
    // 0x8018812C: nop

    // 0x80188130: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x80188134: andi        $t3, $t2, 0x3F
    ctx->r11 = ctx->r10 & 0X3F;
    // 0x80188138: bne         $t3, $zero, L_80188184
    if (ctx->r11 != 0) {
        // 0x8018813C: nop
    
            goto L_80188184;
    }
    // 0x8018813C: nop

    // 0x80188140: jal         0x80004EB0
    // 0x80188144: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_27;
    // 0x80188144: nop

    after_27:
    // 0x80188148: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8018814C: nop

    // 0x80188150: bc1f        L_80188184
    if (!c1cs) {
        // 0x80188154: nop
    
            goto L_80188184;
    }
    // 0x80188154: nop

    // 0x80188158: jal         0x80004EB0
    // 0x8018815C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_28;
    // 0x8018815C: nop

    after_28:
    // 0x80188160: sub.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80188164: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80188168: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018816C: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80188170: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80188174: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80188178: lwc1        $f10, 0x40($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X40);
    // 0x8018817C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80188180: swc1        $f8, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f8.u32l;
L_80188184:
    // 0x80188184: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80188188: lw          $t5, 0x7DB0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7DB0);
    // 0x8018818C: andi        $t6, $t5, 0x3F
    ctx->r14 = ctx->r13 & 0X3F;
    // 0x80188190: bnel        $t6, $zero, L_801882B0
    if (ctx->r14 != 0) {
        // 0x80188194: lh          $t4, 0x4E($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X4E);
            goto L_801882B0;
    }
    goto skip_14;
    // 0x80188194: lh          $t4, 0x4E($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4E);
    skip_14:
    // 0x80188198: jal         0x80004EB0
    // 0x8018819C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_29;
    // 0x8018819C: nop

    after_29:
    // 0x801881A0: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x801881A4: nop

    // 0x801881A8: bc1fl       L_801882B0
    if (!c1cs) {
        // 0x801881AC: lh          $t4, 0x4E($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X4E);
            goto L_801882B0;
    }
    goto skip_15;
    // 0x801881AC: lh          $t4, 0x4E($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4E);
    skip_15:
    // 0x801881B0: jal         0x80004EB0
    // 0x801881B4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_30;
    // 0x801881B4: nop

    after_30:
    // 0x801881B8: sub.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x801881BC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801881C0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801881C4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801881C8: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x801881CC: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801881D0: lwc1        $f6, 0x44($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X44);
    // 0x801881D4: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x801881D8: b           L_801882AC
    // 0x801881DC: swc1        $f8, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f8.u32l;
        goto L_801882AC;
    // 0x801881DC: swc1        $f8, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f8.u32l;
L_801881E0:
    // 0x801881E0: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x801881E4: andi        $t9, $t8, 0x1F
    ctx->r25 = ctx->r24 & 0X1F;
    // 0x801881E8: bne         $t9, $zero, L_80188244
    if (ctx->r25 != 0) {
        // 0x801881EC: nop
    
            goto L_80188244;
    }
    // 0x801881EC: nop

    // 0x801881F0: jal         0x80004EB0
    // 0x801881F4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_31;
    // 0x801881F4: nop

    after_31:
    // 0x801881F8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801881FC: lwc1        $f4, 0x940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X940);
    // 0x80188200: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80188204: nop

    // 0x80188208: bc1f        L_80188244
    if (!c1cs) {
        // 0x8018820C: nop
    
            goto L_80188244;
    }
    // 0x8018820C: nop

    // 0x80188210: jal         0x80004EB0
    // 0x80188214: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_32;
    // 0x80188214: nop

    after_32:
    // 0x80188218: sub.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8018821C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80188220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188224: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x80188228: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x8018822C: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80188230: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80188234: lwc1        $f8, 0x40($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X40);
    // 0x80188238: swc1        $f18, 0x150($s1)
    MEM_W(0X150, ctx->r17) = ctx->f18.u32l;
    // 0x8018823C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188240: swc1        $f4, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f4.u32l;
L_80188244:
    // 0x80188244: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80188248: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x8018824C: andi        $t2, $t1, 0x1F
    ctx->r10 = ctx->r9 & 0X1F;
    // 0x80188250: bnel        $t2, $zero, L_801882B0
    if (ctx->r10 != 0) {
        // 0x80188254: lh          $t4, 0x4E($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X4E);
            goto L_801882B0;
    }
    goto skip_16;
    // 0x80188254: lh          $t4, 0x4E($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4E);
    skip_16:
    // 0x80188258: jal         0x80004EB0
    // 0x8018825C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_33;
    // 0x8018825C: nop

    after_33:
    // 0x80188260: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188264: lwc1        $f6, 0x944($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X944);
    // 0x80188268: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8018826C: nop

    // 0x80188270: bc1fl       L_801882B0
    if (!c1cs) {
        // 0x80188274: lh          $t4, 0x4E($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X4E);
            goto L_801882B0;
    }
    goto skip_17;
    // 0x80188274: lh          $t4, 0x4E($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4E);
    skip_17:
    // 0x80188278: jal         0x80004EB0
    // 0x8018827C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_34;
    // 0x8018827C: nop

    after_34:
    // 0x80188280: sub.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80188284: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80188288: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018828C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80188290: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80188294: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80188298: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018829C: lwc1        $f18, 0x44($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X44);
    // 0x801882A0: swc1        $f8, 0x154($s1)
    MEM_W(0X154, ctx->r17) = ctx->f8.u32l;
    // 0x801882A4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801882A8: swc1        $f6, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f6.u32l;
L_801882AC:
    // 0x801882AC: lh          $t4, 0x4E($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X4E);
L_801882B0:
    // 0x801882B0: beq         $t4, $zero, L_80188408
    if (ctx->r12 == 0) {
        // 0x801882B4: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80188408;
    }
    // 0x801882B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882B8: lwc1        $f10, 0x948($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X948);
    // 0x801882BC: lw          $a1, 0xEC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XEC);
    // 0x801882C0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801882C4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801882C8: addiu       $a0, $s1, 0xE8
    ctx->r4 = ADD32(ctx->r17, 0XE8);
    // 0x801882CC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801882D0: jal         0x8009BC2C
    // 0x801882D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_35;
    // 0x801882D4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_35:
    // 0x801882D8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x801882DC: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x801882E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801882E4: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801882E8: lwc1        $f18, 0x48($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X48);
    // 0x801882EC: lwc1        $f8, 0xE4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x801882F0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801882F4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801882F8: lwc1        $f18, 0x94C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X94C);
    // 0x801882FC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188300: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x80188304: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80188308: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018830C: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x80188310: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80188314: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80188318: jal         0x8009BC2C
    // 0x8018831C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_36;
    // 0x8018831C: nop

    after_36:
    // 0x80188320: lh          $t6, 0x4E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4E);
    // 0x80188324: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188328: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018832C: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80188330: beq         $at, $zero, L_801883E4
    if (ctx->r1 == 0) {
        // 0x80188334: addiu       $a0, $s1, 0x150
        ctx->r4 = ADD32(ctx->r17, 0X150);
            goto L_801883E4;
    }
    // 0x80188334: addiu       $a0, $s1, 0x150
    ctx->r4 = ADD32(ctx->r17, 0X150);
    // 0x80188338: lh          $t7, 0xBA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XBA);
    // 0x8018833C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80188340: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80188344: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188348: bne         $t7, $at, L_80188358
    if (ctx->r15 != ctx->r1) {
        // 0x8018834C: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_80188358;
    }
    // 0x8018834C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80188350: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80188354: nop

L_80188358:
    // 0x80188358: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018835C: lwc1        $f4, 0x950($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X950);
    // 0x80188360: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80188364: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80188368: swc1        $f2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f2.u32l;
    // 0x8018836C: jal         0x8009BC2C
    // 0x80188370: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_37;
    // 0x80188370: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_37:
    // 0x80188374: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80188378: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018837C: lwc1        $f8, 0x954($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X954);
    // 0x80188380: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188384: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80188388: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8018838C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188390: addiu       $a0, $s1, 0x154
    ctx->r4 = ADD32(ctx->r17, 0X154);
    // 0x80188394: jal         0x8009BC2C
    // 0x80188398: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_38;
    // 0x80188398: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_38:
    // 0x8018839C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801883A0: lwc1        $f6, 0x958($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X958);
    // 0x801883A4: lw          $a1, 0xF0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XF0);
    // 0x801883A8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801883AC: lw          $a3, 0x150($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X150);
    // 0x801883B0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801883B4: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x801883B8: jal         0x8009BC2C
    // 0x801883BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_39;
    // 0x801883BC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_39:
    // 0x801883C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801883C4: lwc1        $f10, 0x95C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X95C);
    // 0x801883C8: lw          $a1, 0xF4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XF4);
    // 0x801883CC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801883D0: lw          $a3, 0x154($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X154);
    // 0x801883D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801883D8: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    // 0x801883DC: jal         0x8009BC2C
    // 0x801883E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_40;
    // 0x801883E0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_40:
L_801883E4:
    // 0x801883E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801883E8: lwc1        $f18, 0x960($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X960);
    // 0x801883EC: lw          $a1, 0xDC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XDC);
    // 0x801883F0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801883F4: lw          $a3, 0xE0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE0);
    // 0x801883F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801883FC: addiu       $a0, $s1, 0xD8
    ctx->r4 = ADD32(ctx->r17, 0XD8);
    // 0x80188400: jal         0x8009BD38
    // 0x80188404: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_41;
    // 0x80188404: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_41:
L_80188408:
    // 0x80188408: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018840C: lwc1        $f4, 0x964($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X964);
    // 0x80188410: lw          $a1, 0x10C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X10C);
    // 0x80188414: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188418: lw          $a3, 0x118($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X118);
    // 0x8018841C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188420: addiu       $a0, $s1, 0x100
    ctx->r4 = ADD32(ctx->r17, 0X100);
    // 0x80188424: jal         0x8009BC2C
    // 0x80188428: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_42;
    // 0x80188428: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_42:
    // 0x8018842C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188430: lwc1        $f8, 0x968($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X968);
    // 0x80188434: lw          $a1, 0x110($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X110);
    // 0x80188438: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8018843C: lw          $a3, 0x11C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X11C);
    // 0x80188440: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188444: addiu       $a0, $s1, 0x104
    ctx->r4 = ADD32(ctx->r17, 0X104);
    // 0x80188448: jal         0x8009BC2C
    // 0x8018844C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_43;
    // 0x8018844C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_43:
    // 0x80188450: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188454: lwc1        $f6, 0x96C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X96C);
    // 0x80188458: lw          $a1, 0x114($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X114);
    // 0x8018845C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188460: lw          $a3, 0x120($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X120);
    // 0x80188464: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188468: addiu       $a0, $s1, 0x108
    ctx->r4 = ADD32(ctx->r17, 0X108);
    // 0x8018846C: jal         0x8009BC2C
    // 0x80188470: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_44;
    // 0x80188470: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_44:
    // 0x80188474: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188478: lwc1        $f10, 0x970($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X970);
    // 0x8018847C: lw          $a1, 0x130($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X130);
    // 0x80188480: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188484: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80188488: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018848C: addiu       $a0, $s1, 0x124
    ctx->r4 = ADD32(ctx->r17, 0X124);
    // 0x80188490: jal         0x8009BC2C
    // 0x80188494: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_45;
    // 0x80188494: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_45:
    // 0x80188498: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018849C: lwc1        $f18, 0x974($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X974);
    // 0x801884A0: lw          $a1, 0x134($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X134);
    // 0x801884A4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801884A8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x801884AC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801884B0: addiu       $a0, $s1, 0x128
    ctx->r4 = ADD32(ctx->r17, 0X128);
    // 0x801884B4: jal         0x8009BC2C
    // 0x801884B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_46;
    // 0x801884B8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_46:
    // 0x801884BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801884C0: lwc1        $f4, 0x978($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X978);
    // 0x801884C4: lw          $a1, 0x138($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X138);
    // 0x801884C8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801884CC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x801884D0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801884D4: addiu       $a0, $s1, 0x12C
    ctx->r4 = ADD32(ctx->r17, 0X12C);
    // 0x801884D8: jal         0x8009BC2C
    // 0x801884DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_47;
    // 0x801884DC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_47:
    // 0x801884E0: lh          $t8, 0x4E($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4E);
    // 0x801884E4: slti        $at, $t8, 0xB
    ctx->r1 = SIGNED(ctx->r24) < 0XB ? 1 : 0;
    // 0x801884E8: bne         $at, $zero, L_80188780
    if (ctx->r1 != 0) {
        // 0x801884EC: nop
    
            goto L_80188780;
    }
    // 0x801884EC: nop

    // 0x801884F0: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x801884F4: lwc1        $f6, 0x148($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X148);
    // 0x801884F8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801884FC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80188500: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80188504: swc1        $f10, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f10.u32l;
    // 0x80188508: jal         0x80004E20
    // 0x8018850C: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    Math_ModF(rdram, ctx);
        goto after_48;
    // 0x8018850C: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    after_48:
    // 0x80188510: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x80188514: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188518: lwc1        $f18, 0x97C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X97C);
    // 0x8018851C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188520: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80188524: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80188528: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018852C: addiu       $a0, $s1, 0x148
    ctx->r4 = ADD32(ctx->r17, 0X148);
    // 0x80188530: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80188534: jal         0x8009BC2C
    // 0x80188538: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_49;
    // 0x80188538: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_49:
    // 0x8018853C: sw          $zero, 0x134($sp)
    MEM_W(0X134, ctx->r29) = 0;
L_80188540:
    // 0x80188540: jal         0x80004EB0
    // 0x80188544: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_50;
    // 0x80188544: nop

    after_50:
    // 0x80188548: lw          $s0, 0x134($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X134);
    // 0x8018854C: jal         0x80004EB0
    // 0x80188550: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_51;
    // 0x80188550: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    after_51:
    // 0x80188554: jal         0x80004EB0
    // 0x80188558: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_52;
    // 0x80188558: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    after_52:
    // 0x8018855C: jal         0x80004EB0
    // 0x80188560: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_53;
    // 0x80188560: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    after_53:
    // 0x80188564: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80188568: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018856C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80188570: sub.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80188574: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80188578: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018857C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80188580: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80188584: sub.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f22.fl;
    // 0x80188588: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8018858C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188590: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80188594: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80188598: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018859C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801885A0: sub.s       $f18, $f10, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x801885A4: add.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801885A8: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801885AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801885B0: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801885B4: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801885B8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x801885BC: add.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x801885C0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801885C4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801885C8: jal         0x80079618
    // 0x801885CC: nop

    func_effect_80079618(rdram, ctx);
        goto after_54;
    // 0x801885CC: nop

    after_54:
    // 0x801885D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801885D4: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x801885D8: bne         $at, $zero, L_80188540
    if (ctx->r1 != 0) {
        // 0x801885DC: sw          $s0, 0x134($sp)
        MEM_W(0X134, ctx->r29) = ctx->r16;
            goto L_80188540;
    }
    // 0x801885DC: sw          $s0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r16;
    // 0x801885E0: lh          $t9, 0x5C($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X5C);
    // 0x801885E4: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x801885E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801885EC: bne         $t9, $zero, L_801885F8
    if (ctx->r25 != 0) {
        // 0x801885F0: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801885F8;
    }
    // 0x801885F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801885F4: sh          $t0, 0x5C($s1)
    MEM_H(0X5C, ctx->r17) = ctx->r8;
L_801885F8:
    // 0x801885F8: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x801885FC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80188600: addiu       $a1, $a1, -0x12FC
    ctx->r5 = ADD32(ctx->r5, -0X12FC);
    // 0x80188604: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80188608: bne         $t1, $zero, L_80188738
    if (ctx->r9 != 0) {
        // 0x8018860C: addiu       $a2, $sp, 0xC8
        ctx->r6 = ADD32(ctx->r29, 0XC8);
            goto L_80188738;
    }
    // 0x8018860C: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    // 0x80188610: jal         0x80006970
    // 0x80188614: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_55;
    // 0x80188614: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_55:
    // 0x80188618: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018861C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80188620: addiu       $a1, $a1, -0x12F0
    ctx->r5 = ADD32(ctx->r5, -0X12F0);
    // 0x80188624: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188628: jal         0x80006970
    // 0x8018862C: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_56;
    // 0x8018862C: addiu       $a2, $sp, 0xD4
    ctx->r6 = ADD32(ctx->r29, 0XD4);
    after_56:
    // 0x80188630: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188634: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80188638: addiu       $a1, $a1, -0x12E4
    ctx->r5 = ADD32(ctx->r5, -0X12E4);
    // 0x8018863C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188640: jal         0x80006970
    // 0x80188644: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_57;
    // 0x80188644: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    after_57:
    // 0x80188648: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018864C: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80188650: addiu       $a1, $a1, -0x12D8
    ctx->r5 = ADD32(ctx->r5, -0X12D8);
    // 0x80188654: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188658: jal         0x80006970
    // 0x8018865C: addiu       $a2, $sp, 0xEC
    ctx->r6 = ADD32(ctx->r29, 0XEC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_58;
    // 0x8018865C: addiu       $a2, $sp, 0xEC
    ctx->r6 = ADD32(ctx->r29, 0XEC);
    after_58:
    // 0x80188660: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188664: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80188668: addiu       $a1, $a1, -0x12CC
    ctx->r5 = ADD32(ctx->r5, -0X12CC);
    // 0x8018866C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188670: jal         0x80006970
    // 0x80188674: addiu       $a2, $sp, 0xF8
    ctx->r6 = ADD32(ctx->r29, 0XF8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_59;
    // 0x80188674: addiu       $a2, $sp, 0xF8
    ctx->r6 = ADD32(ctx->r29, 0XF8);
    after_59:
    // 0x80188678: addiu       $v0, $sp, 0xC8
    ctx->r2 = ADD32(ctx->r29, 0XC8);
L_8018867C:
    // 0x8018867C: jal         0x80004EB0
    // 0x80188680: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    Rand_ZeroOne(rdram, ctx);
        goto after_60;
    // 0x80188680: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_60:
    // 0x80188684: sub.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80188688: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018868C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188690: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80188694: addiu       $t3, $sp, 0xC8
    ctx->r11 = ADD32(ctx->r29, 0XC8);
    // 0x80188698: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8018869C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801886A0: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x801886A4: bnel        $v0, $t3, L_801886D8
    if (ctx->r2 != ctx->r11) {
        // 0x801886A8: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_801886D8;
    }
    goto skip_18;
    // 0x801886A8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_18:
    // 0x801886AC: jal         0x80004EB0
    // 0x801886B0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    Rand_ZeroOne(rdram, ctx);
        goto after_61;
    // 0x801886B0: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_61:
    // 0x801886B4: sub.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x801886B8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801886BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801886C0: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x801886C4: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x801886C8: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801886CC: mfc1        $s0, $f18
    ctx->r16 = (int32_t)ctx->f18.u32l;
    // 0x801886D0: nop

    // 0x801886D4: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_801886D8:
    // 0x801886D8: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801886DC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801886E0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801886E4: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801886E8: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801886EC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x801886F0: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x801886F4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x801886F8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801886FC: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80188700: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80188704: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80188708: add.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8018870C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188710: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80188714: jal         0x8007D0E0
    // 0x80188718: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_62;
    // 0x80188718: nop

    after_62:
    // 0x8018871C: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80188720: addiu       $t5, $sp, 0x104
    ctx->r13 = ADD32(ctx->r29, 0X104);
    // 0x80188724: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80188728: bne         $v0, $t5, L_8018867C
    if (ctx->r2 != ctx->r13) {
        // 0x8018872C: nop
    
            goto L_8018867C;
    }
    // 0x8018872C: nop

    // 0x80188730: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80188734: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
L_80188738:
    // 0x80188738: andi        $t6, $v0, 0x1F
    ctx->r14 = ctx->r2 & 0X1F;
    // 0x8018873C: bne         $t6, $zero, L_80188780
    if (ctx->r14 != 0) {
        // 0x80188740: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_80188780;
    }
    // 0x80188740: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80188744: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80188748: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018874C: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x80188750: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80188754: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80188758: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018875C: lw          $a3, 0x6C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X6C);
    // 0x80188760: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80188764: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80188768: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8018876C: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80188770: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80188774: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80188778: jal         0x8007C120
    // 0x8018877C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_63;
    // 0x8018877C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_63:
L_80188780:
    // 0x80188780: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80188784: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80188788: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8018878C: bne         $t9, $zero, L_80188848
    if (ctx->r25 != 0) {
        // 0x80188790: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80188848;
    }
    // 0x80188790: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188794: lwc1        $f6, 0x980($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X980);
    // 0x80188798: lwc1        $f18, 0xE4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8018879C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801887A0: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x801887A4: div.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x801887A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801887AC: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x801887B0: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x801887B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801887B8: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x801887BC: lui         $at, 0x4319
    ctx->r1 = S32(0X4319 << 16);
    // 0x801887C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801887C4: lui         $at, 0x4313
    ctx->r1 = S32(0X4313 << 16);
    // 0x801887C8: bc1fl       L_801887D8
    if (!c1cs) {
        // 0x801887CC: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_801887D8;
    }
    goto skip_19;
    // 0x801887CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_19:
    // 0x801887D0: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x801887D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_801887D8:
    // 0x801887D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801887DC: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x801887E0: bc1fl       L_801887F0
    if (!c1cs) {
        // 0x801887E4: swc1        $f2, 0x114($sp)
        MEM_W(0X114, ctx->r29) = ctx->f2.u32l;
            goto L_801887F0;
    }
    goto skip_20;
    // 0x801887E4: swc1        $f2, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f2.u32l;
    skip_20:
    // 0x801887E8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801887EC: swc1        $f2, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f2.u32l;
L_801887F0:
    // 0x801887F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801887F4: lwc1        $f16, 0x114($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X114);
L_801887F8:
    // 0x801887F8: lh          $t0, 0xAC($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XAC);
    // 0x801887FC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x80188800: beq         $t0, $zero, L_8018880C
    if (ctx->r8 == 0) {
        // 0x80188804: nop
    
            goto L_8018880C;
    }
    // 0x80188804: nop

    // 0x80188808: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_8018880C:
    // 0x8018880C: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80188810: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
    // 0x80188814: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80188818: mul.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8018881C: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80188820: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80188824: swc1        $f8, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f8.u32l;
    // 0x80188828: lw          $t3, 0x28($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X28);
    // 0x8018882C: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x80188830: swc1        $f10, 0x28($t4)
    MEM_W(0X28, ctx->r12) = ctx->f10.u32l;
    // 0x80188834: lw          $t5, 0x28($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X28);
    // 0x80188838: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8018883C: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80188840: bne         $v0, $a0, L_801887F8
    if (ctx->r2 != ctx->r4) {
        // 0x80188844: swc1        $f4, 0x30($t6)
        MEM_W(0X30, ctx->r14) = ctx->f4.u32l;
            goto L_801887F8;
    }
    // 0x80188844: swc1        $f4, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->f4.u32l;
L_80188848:
    // 0x80188848: lhu         $t7, 0x4E($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X4E);
    // 0x8018884C: sltiu       $at, $t7, 0xC
    ctx->r1 = ctx->r15 < 0XC ? 1 : 0;
    // 0x80188850: beq         $at, $zero, L_80189EA4
    if (ctx->r1 == 0) {
        // 0x80188854: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80189EA4;
    }
    // 0x80188854: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80188858: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018885C: addu        $at, $at, $t7
    gpr jr_addend_80188864 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80188860: lw          $t7, 0x984($at)
    ctx->r15 = ADD32(ctx->r1, 0X984);
    // 0x80188864: jr          $t7
    // 0x80188868: nop

    switch (jr_addend_80188864 >> 2) {
        case 0: goto L_8018886C; break;
        case 1: goto L_80188B98; break;
        case 2: goto L_80188EBC; break;
        case 3: goto L_80189180; break;
        case 4: goto L_801893AC; break;
        case 5: goto L_80189674; break;
        case 6: goto L_80189774; break;
        case 7: goto L_80189898; break;
        case 8: goto L_80189A60; break;
        case 9: goto L_80189AB4; break;
        case 10: goto L_80189D60; break;
        case 11: goto L_80189E14; break;
        default: switch_error(__func__, 0x80188864, 0x801C0984);
    }
    // 0x80188868: nop

L_8018886C:
    // 0x8018886C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80188870: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x80188874: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80188878: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8018887C: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x80188880: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80188884: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80188888: mov.s       $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    ctx->f16.fl = ctx->f24.fl;
    // 0x8018888C: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80188890: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80188894: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188898: swc1        $f8, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f8.u32l;
    // 0x8018889C: lwc1        $f12, 0x8($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801888A0: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801888A4: sub.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x801888A8: swc1        $f4, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f4.u32l;
    // 0x801888AC: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801888B0: lh          $v0, 0x50($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X50);
    // 0x801888B4: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801888B8: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x801888BC: beq         $v0, $zero, L_8018890C
    if (ctx->r2 == 0) {
        // 0x801888C0: sub.s       $f14, $f8, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f2.fl;
            goto L_8018890C;
    }
    // 0x801888C0: sub.s       $f14, $f8, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x801888C4: slti        $at, $v0, 0xC8
    ctx->r1 = SIGNED(ctx->r2) < 0XC8 ? 1 : 0;
    // 0x801888C8: beql        $at, $zero, L_80188910
    if (ctx->r1 == 0) {
        // 0x801888CC: lwc1        $f12, 0x11C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X11C);
            goto L_80188910;
    }
    goto skip_21;
    // 0x801888CC: lwc1        $f12, 0x11C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X11C);
    skip_21:
    // 0x801888D0: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x801888D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801888D8: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x801888DC: lwc1        $f10, 0x7D20($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x801888E0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801888E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801888E8: swc1        $f4, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f4.u32l;
    // 0x801888EC: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x801888F0: sub.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x801888F4: swc1        $f6, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f6.u32l;
    // 0x801888F8: lwc1        $f8, 0x48($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801888FC: lwc1        $f18, 0xE4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x80188900: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80188904: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80188908: sub.s       $f14, $f6, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f2.fl;
L_8018890C:
    // 0x8018890C: lwc1        $f12, 0x11C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X11C);
L_80188910:
    // 0x80188910: swc1        $f14, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f14.u32l;
    // 0x80188914: jal         0x80005100
    // 0x80188918: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_64;
    // 0x80188918: swc1        $f16, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->f16.u32l;
    after_64:
    // 0x8018891C: jal         0x8009F768
    // 0x80188920: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_65;
    // 0x80188920: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_65:
    // 0x80188924: lwc1        $f2, 0x11C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80188928: lwc1        $f16, 0x114($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8018892C: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x80188930: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80188934: lwc1        $f12, 0x118($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X118);
    // 0x80188938: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018893C: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188940: jal         0x80005100
    // 0x80188944: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_66;
    // 0x80188944: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_66:
    // 0x80188948: jal         0x8009F768
    // 0x8018894C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_67;
    // 0x8018894C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_67:
    // 0x80188950: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188954: lwc1        $f18, 0x9B4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9B4);
    // 0x80188958: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018895C: addiu       $a0, $s1, 0x7C
    ctx->r4 = ADD32(ctx->r17, 0X7C);
    // 0x80188960: lw          $a1, 0x10C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10C);
    // 0x80188964: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80188968: swc1        $f0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f0.u32l;
    // 0x8018896C: jal         0x8009BD38
    // 0x80188970: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_68;
    // 0x80188970: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_68:
    // 0x80188974: lwc1        $f2, 0x110($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X110);
    // 0x80188978: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018897C: lwc1        $f4, 0x9B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9B8);
    // 0x80188980: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80188984: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80188988: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x8018898C: lw          $a3, 0x104($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X104);
    // 0x80188990: jal         0x8009BD38
    // 0x80188994: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_69;
    // 0x80188994: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_69:
    // 0x80188998: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018899C: lwc1        $f8, 0x9BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9BC);
    // 0x801889A0: lwc1        $f6, 0x7C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x801889A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801889A8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801889AC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801889B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801889B4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801889B8: jal         0x80005E90
    // 0x801889BC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_70;
    // 0x801889BC: nop

    after_70:
    // 0x801889C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801889C4: lwc1        $f4, 0x9C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9C0);
    // 0x801889C8: lwc1        $f18, 0x78($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X78);
    // 0x801889CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801889D0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801889D4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801889D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801889DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801889E0: jal         0x80005D44
    // 0x801889E4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_71;
    // 0x801889E4: nop

    after_71:
    // 0x801889E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801889EC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801889F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801889F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801889F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801889FC: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x80188A00: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x80188A04: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x80188A08: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80188A0C: jal         0x80006A20
    // 0x80188A10: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_72;
    // 0x80188A10: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    after_72:
    // 0x80188A14: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80188A18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80188A1C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80188A20: swc1        $f10, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f10.u32l;
    // 0x80188A24: lwc1        $f18, 0x90($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80188A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188A2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188A30: swc1        $f18, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f18.u32l;
    // 0x80188A34: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188A38: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x80188A3C: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x80188A40: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80188A44: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x80188A48: jal         0x80006A20
    // 0x80188A4C: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_73;
    // 0x80188A4C: swc1        $f4, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f4.u32l;
    after_73:
    // 0x80188A50: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80188A54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188A58: lwc1        $f8, 0x15C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X15C);
    // 0x80188A5C: lh          $t9, 0x50($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X50);
    // 0x80188A60: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80188A64: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80188A68: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188A6C: swc1        $f6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f6.u32l;
    // 0x80188A70: bne         $t9, $zero, L_80189EA4
    if (ctx->r25 != 0) {
        // 0x80188A74: swc1        $f18, 0x15C($s1)
        MEM_W(0X15C, ctx->r17) = ctx->f18.u32l;
            goto L_80189EA4;
    }
    // 0x80188A74: swc1        $f18, 0x15C($s1)
    MEM_W(0X15C, ctx->r17) = ctx->f18.u32l;
    // 0x80188A78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80188A7C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188A80: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80188A84: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188A88: addiu       $a0, $a0, 0x2314
    ctx->r4 = ADD32(ctx->r4, 0X2314);
    // 0x80188A8C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80188A90: jal         0x8009BC2C
    // 0x80188A94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_74;
    // 0x80188A94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_74:
    // 0x80188A98: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80188A9C: addiu       $v0, $v0, 0x22F0
    ctx->r2 = ADD32(ctx->r2, 0X22F0);
    // 0x80188AA0: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80188AA4: addiu       $a0, $s1, 0x3FC
    ctx->r4 = ADD32(ctx->r17, 0X3FC);
    // 0x80188AA8: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x80188AAC: nop

    // 0x80188AB0: bc1fl       L_80189EA8
    if (!c1cs) {
        // 0x80188AB4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_22;
    // 0x80188AB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_22:
    // 0x80188AB8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80188ABC: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80188AC0: jal         0x8001A500
    // 0x80188AC4: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    Audio_KillSfxBySource(rdram, ctx);
        goto after_75;
    // 0x80188AC4: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    after_75:
    // 0x80188AC8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188ACC: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80188AD0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188AD4: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80188AD8: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x80188ADC: ori         $a0, $a0, 0x4051
    ctx->r4 = ctx->r4 | 0X4051;
    // 0x80188AE0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80188AE4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188AE8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80188AEC: jal         0x80019218
    // 0x80188AF0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_76;
    // 0x80188AF0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_76:
    // 0x80188AF4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80188AF8: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80188AFC: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80188B00: sh          $t1, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r9;
    // 0x80188B04: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80188B08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80188B0C: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80188B10: lwc1        $f10, 0x48($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X48);
    // 0x80188B14: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x80188B18: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80188B1C: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80188B20: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80188B24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188B28: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80188B2C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80188B30: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80188B34: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80188B38: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80188B3C: swc1        $f8, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f8.u32l;
    // 0x80188B40: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80188B44: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80188B48: lui         $a0, 0x3940
    ctx->r4 = S32(0X3940 << 16);
    // 0x80188B4C: lwc1        $f0, 0x40($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X40);
    // 0x80188B50: ori         $a0, $a0, 0x8092
    ctx->r4 = ctx->r4 | 0X8092;
    // 0x80188B54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80188B58: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80188B5C: swc1        $f0, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f0.u32l;
    // 0x80188B60: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80188B64: lwc1        $f0, 0x44($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X44);
    // 0x80188B68: sh          $t5, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r13;
    // 0x80188B6C: swc1        $f2, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f2.u32l;
    // 0x80188B70: swc1        $f2, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f2.u32l;
    // 0x80188B74: swc1        $f10, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f10.u32l;
    // 0x80188B78: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x80188B7C: swc1        $f0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f0.u32l;
    // 0x80188B80: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80188B84: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188B88: jal         0x80019218
    // 0x80188B8C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    Audio_PlaySfx(rdram, ctx);
        goto after_77;
    // 0x80188B8C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_77:
    // 0x80188B90: b           L_80189EA8
    // 0x80188B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80189EA8;
    // 0x80188B94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80188B98:
    // 0x80188B98: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80188B9C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80188BA0: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188BA4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80188BA8: addiu       $a0, $a0, 0x79A8
    ctx->r4 = ADD32(ctx->r4, 0X79A8);
    // 0x80188BAC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80188BB0: addiu       $s0, $s1, 0x18
    ctx->r16 = ADD32(ctx->r17, 0X18);
    // 0x80188BB4: jal         0x8009BC2C
    // 0x80188BB8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_78;
    // 0x80188BB8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_78:
    // 0x80188BBC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80188BC0: lw          $t7, 0x28($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X28);
    // 0x80188BC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188BC8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80188BCC: swc1        $f6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f6.u32l;
    // 0x80188BD0: lwc1        $f4, 0x9C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9C4);
    // 0x80188BD4: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80188BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80188BDC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80188BE0: jal         0x8009BD38
    // 0x80188BE4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_79;
    // 0x80188BE4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_79:
    // 0x80188BE8: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80188BEC: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80188BF0: nop

    // 0x80188BF4: bc1fl       L_80189EA8
    if (!c1cs) {
        // 0x80188BF8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_23;
    // 0x80188BF8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_23:
    // 0x80188BFC: lw          $t8, 0x6C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X6C);
    // 0x80188C00: lui         $a0, 0x3940
    ctx->r4 = S32(0X3940 << 16);
    // 0x80188C04: ori         $a0, $a0, 0x8091
    ctx->r4 = ctx->r4 | 0X8091;
    // 0x80188C08: bne         $t8, $zero, L_80188C38
    if (ctx->r24 != 0) {
        // 0x80188C0C: addiu       $a1, $s1, 0x3FC
        ctx->r5 = ADD32(ctx->r17, 0X3FC);
            goto L_80188C38;
    }
    // 0x80188C0C: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80188C10: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80188C14: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80188C18: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80188C1C: addiu       $a3, $t9, 0x5D34
    ctx->r7 = ADD32(ctx->r25, 0X5D34);
    // 0x80188C20: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188C24: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80188C28: jal         0x80019218
    // 0x80188C2C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_80;
    // 0x80188C2C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_80:
    // 0x80188C30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80188C34: sw          $t1, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->r9;
L_80188C38:
    // 0x80188C38: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80188C3C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80188C40: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188C44: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188C48: swc1        $f10, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f10.u32l;
    // 0x80188C4C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188C50: addiu       $a0, $a0, 0x2314
    ctx->r4 = ADD32(ctx->r4, 0X2314);
    // 0x80188C54: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80188C58: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80188C5C: jal         0x8009BC2C
    // 0x80188C60: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_81;
    // 0x80188C60: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_81:
    // 0x80188C64: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80188C68: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188C6C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188C70: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80188C74: addiu       $a0, $s1, 0x160
    ctx->r4 = ADD32(ctx->r17, 0X160);
    // 0x80188C78: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80188C7C: jal         0x8009BC2C
    // 0x80188C80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_82;
    // 0x80188C80: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_82:
    // 0x80188C84: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80188C88: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188C8C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188C90: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80188C94: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80188C98: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80188C9C: addiu       $a0, $s1, 0x164
    ctx->r4 = ADD32(ctx->r17, 0X164);
    // 0x80188CA0: jal         0x8009BC2C
    // 0x80188CA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_83;
    // 0x80188CA4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_83:
    // 0x80188CA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188CAC: lwc1        $f8, 0x2314($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2314);
    // 0x80188CB0: addiu       $t2, $s1, 0x3FC
    ctx->r10 = ADD32(ctx->r17, 0X3FC);
    // 0x80188CB4: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x80188CB8: nop

    // 0x80188CBC: bc1fl       L_80189EA8
    if (!c1cs) {
        // 0x80188CC0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_24;
    // 0x80188CC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_24:
    // 0x80188CC4: jal         0x80004EB0
    // 0x80188CC8: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    Rand_ZeroOne(rdram, ctx);
        goto after_84;
    // 0x80188CC8: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    after_84:
    // 0x80188CCC: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80188CD0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80188CD4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188CD8: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80188CDC: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x80188CE0: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80188CE4: lwc1        $f4, 0x40($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X40);
    // 0x80188CE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80188CEC: jal         0x80004EB0
    // 0x80188CF0: swc1        $f8, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_85;
    // 0x80188CF0: swc1        $f8, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f8.u32l;
    after_85:
    // 0x80188CF4: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80188CF8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80188CFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188D00: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80188D04: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x80188D08: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80188D0C: lwc1        $f6, 0x44($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X44);
    // 0x80188D10: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80188D14: jal         0x80004EB0
    // 0x80188D18: swc1        $f8, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_86;
    // 0x80188D18: swc1        $f8, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f8.u32l;
    after_86:
    // 0x80188D1C: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80188D20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188D24: lwc1        $f18, 0x9C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9C8);
    // 0x80188D28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188D2C: lwc1        $f4, 0x9CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9CC);
    // 0x80188D30: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80188D34: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80188D38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188D3C: lh          $v0, 0xD2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XD2);
    // 0x80188D40: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188D44: swc1        $f10, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->f10.u32l;
    // 0x80188D48: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80188D4C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80188D50: swc1        $f8, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f8.u32l;
    // 0x80188D54: lwc1        $f18, 0x9D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9D0);
    // 0x80188D58: bne         $v0, $zero, L_80188DB4
    if (ctx->r2 != 0) {
        // 0x80188D5C: swc1        $f18, 0x164($s1)
        MEM_W(0X164, ctx->r17) = ctx->f18.u32l;
            goto L_80188DB4;
    }
    // 0x80188D5C: swc1        $f18, 0x164($s1)
    MEM_W(0X164, ctx->r17) = ctx->f18.u32l;
    // 0x80188D60: lh          $t5, 0xCA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XCA);
    // 0x80188D64: bne         $t5, $zero, L_80188DB4
    if (ctx->r13 != 0) {
        // 0x80188D68: nop
    
            goto L_80188DB4;
    }
    // 0x80188D68: nop

    // 0x80188D6C: lh          $t6, 0xCC($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XCC);
    // 0x80188D70: bne         $t6, $zero, L_80188DB4
    if (ctx->r14 != 0) {
        // 0x80188D74: nop
    
            goto L_80188DB4;
    }
    // 0x80188D74: nop

    // 0x80188D78: lh          $t7, 0xCE($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XCE);
    // 0x80188D7C: bne         $t7, $zero, L_80188DB4
    if (ctx->r15 != 0) {
        // 0x80188D80: nop
    
            goto L_80188DB4;
    }
    // 0x80188D80: nop

    // 0x80188D84: lh          $t8, 0xBE($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XBE);
    // 0x80188D88: bne         $t8, $zero, L_80188DB4
    if (ctx->r24 != 0) {
        // 0x80188D8C: nop
    
            goto L_80188DB4;
    }
    // 0x80188D8C: nop

    // 0x80188D90: lh          $t9, 0xC0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XC0);
    // 0x80188D94: bne         $t9, $zero, L_80188DB4
    if (ctx->r25 != 0) {
        // 0x80188D98: nop
    
            goto L_80188DB4;
    }
    // 0x80188D98: nop

    // 0x80188D9C: lh          $t0, 0xC2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XC2);
    // 0x80188DA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80188DA4: bne         $t0, $zero, L_80188DB4
    if (ctx->r8 != 0) {
        // 0x80188DA8: nop
    
            goto L_80188DB4;
    }
    // 0x80188DA8: nop

    // 0x80188DAC: sh          $t1, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = ctx->r9;
    // 0x80188DB0: lh          $v0, 0xD2($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XD2);
L_80188DB4:
    // 0x80188DB4: beql        $v0, $zero, L_80188E6C
    if (ctx->r2 == 0) {
        // 0x80188DB8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80188E6C;
    }
    goto skip_25;
    // 0x80188DB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_25:
    // 0x80188DBC: sh          $t2, 0xB0($s1)
    MEM_H(0XB0, ctx->r17) = ctx->r10;
    // 0x80188DC0: lh          $v0, 0xB0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB0);
    // 0x80188DC4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188DC8: lh          $t3, 0xBA($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XBA);
    // 0x80188DCC: sh          $v0, 0xAE($s1)
    MEM_H(0XAE, ctx->r17) = ctx->r2;
    // 0x80188DD0: sh          $v0, 0xAC($s1)
    MEM_H(0XAC, ctx->r17) = ctx->r2;
    // 0x80188DD4: lwc1        $f6, 0x9D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X9D4);
    // 0x80188DD8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80188DDC: beq         $t3, $at, L_80188E1C
    if (ctx->r11 == ctx->r1) {
        // 0x80188DE0: swc1        $f6, 0xE4($s1)
        MEM_W(0XE4, ctx->r17) = ctx->f6.u32l;
            goto L_80188E1C;
    }
    // 0x80188DE0: swc1        $f6, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f6.u32l;
    // 0x80188DE4: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80188DE8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80188DEC: beq         $t4, $at, L_80188E1C
    if (ctx->r12 == ctx->r1) {
        // 0x80188DF0: nop
    
            goto L_80188E1C;
    }
    // 0x80188DF0: nop

    // 0x80188DF4: jal         0x80004EB0
    // 0x80188DF8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_87;
    // 0x80188DF8: nop

    after_87:
    // 0x80188DFC: sub.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80188E00: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80188E04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188E08: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188E0C: lwc1        $f18, 0x9D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9D8);
    // 0x80188E10: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80188E14: add.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80188E18: swc1        $f6, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f6.u32l;
L_80188E1C:
    // 0x80188E1C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80188E20: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x80188E24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80188E28: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80188E2C: lwc1        $f4, 0x48($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X48);
    // 0x80188E30: lwc1        $f18, 0xE4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x80188E34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80188E38: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80188E3C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80188E40: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80188E44: swc1        $f6, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f6.u32l;
    // 0x80188E48: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x80188E4C: lwc1        $f0, 0x40($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X40);
    // 0x80188E50: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80188E54: swc1        $f0, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f0.u32l;
    // 0x80188E58: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80188E5C: lwc1        $f0, 0x44($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X44);
    // 0x80188E60: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x80188E64: swc1        $f0, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f0.u32l;
    // 0x80188E68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80188E6C:
    // 0x80188E6C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188E70: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80188E74: swc1        $f4, 0x2314($at)
    MEM_W(0X2314, ctx->r1) = ctx->f4.u32l;
    // 0x80188E78: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80188E7C: sh          $t8, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r24;
    // 0x80188E80: sh          $t9, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r25;
    // 0x80188E84: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80188E88: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80188E8C: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80188E90: addiu       $a3, $t0, 0x5D34
    ctx->r7 = ADD32(ctx->r8, 0X5D34);
    // 0x80188E94: lui         $a0, 0x3940
    ctx->r4 = S32(0X3940 << 16);
    // 0x80188E98: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    // 0x80188E9C: ori         $a0, $a0, 0x8092
    ctx->r4 = ctx->r4 | 0X8092;
    // 0x80188EA0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80188EA4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80188EA8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80188EAC: jal         0x80019218
    // 0x80188EB0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_88;
    // 0x80188EB0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_88:
    // 0x80188EB4: b           L_80189EA8
    // 0x80188EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80189EA8;
    // 0x80188EB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80188EBC:
    // 0x80188EBC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80188EC0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80188EC4: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80188EC8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80188ECC: addiu       $a0, $a0, 0x79A8
    ctx->r4 = ADD32(ctx->r4, 0X79A8);
    // 0x80188ED0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80188ED4: jal         0x8009BC2C
    // 0x80188ED8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_89;
    // 0x80188ED8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_89:
    // 0x80188EDC: lh          $v0, 0x50($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X50);
    // 0x80188EE0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80188EE4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80188EE8: bne         $v0, $at, L_80188F44
    if (ctx->r2 != ctx->r1) {
        // 0x80188EEC: addiu       $v1, $v1, -0x7CA8
        ctx->r3 = ADD32(ctx->r3, -0X7CA8);
            goto L_80188F44;
    }
    // 0x80188EEC: addiu       $v1, $v1, -0x7CA8
    ctx->r3 = ADD32(ctx->r3, -0X7CA8);
    // 0x80188EF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188EF4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80188EF8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80188EFC: addiu       $a2, $a2, -0x7CB0
    ctx->r6 = ADD32(ctx->r6, -0X7CB0);
    // 0x80188F00: addiu       $a0, $a0, -0x7CAC
    ctx->r4 = ADD32(ctx->r4, -0X7CAC);
    // 0x80188F04: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80188F08: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80188F0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80188F10: sw          $a1, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r5;
    // 0x80188F14: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80188F18: addiu       $a3, $a3, -0x7CC0
    ctx->r7 = ADD32(ctx->r7, -0X7CC0);
    // 0x80188F1C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x80188F20: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x80188F24: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80188F28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80188F2C: addiu       $t5, $zero, 0x19
    ctx->r13 = ADD32(0, 0X19);
    // 0x80188F30: sw          $t5, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r13;
    // 0x80188F34: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80188F38: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80188F3C: sw          $t6, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r14;
    // 0x80188F40: lh          $v0, 0x50($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X50);
L_80188F44:
    // 0x80188F44: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80188F48: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80188F4C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80188F50: addiu       $a3, $a3, -0x7CC0
    ctx->r7 = ADD32(ctx->r7, -0X7CC0);
    // 0x80188F54: addiu       $a2, $a2, -0x7CB0
    ctx->r6 = ADD32(ctx->r6, -0X7CB0);
    // 0x80188F58: bne         $v0, $zero, L_80189EA4
    if (ctx->r2 != 0) {
        // 0x80188F5C: addiu       $a0, $a0, -0x7CAC
        ctx->r4 = ADD32(ctx->r4, -0X7CAC);
            goto L_80189EA4;
    }
    // 0x80188F5C: addiu       $a0, $a0, -0x7CAC
    ctx->r4 = ADD32(ctx->r4, -0X7CAC);
    // 0x80188F60: lw          $t7, 0x20($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X20);
    // 0x80188F64: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80188F68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80188F6C: bne         $t7, $zero, L_80188F8C
    if (ctx->r15 != 0) {
        // 0x80188F70: lui         $a1, 0x437F
        ctx->r5 = S32(0X437F << 16);
            goto L_80188F8C;
    }
    // 0x80188F70: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x80188F74: sw          $t8, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r24;
    // 0x80188F78: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80188F7C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80188F80: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80188F84: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80188F88: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
L_80188F8C:
    // 0x80188F8C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188F90: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188F94: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80188F98: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188F9C: addiu       $a0, $a0, 0x2314
    ctx->r4 = ADD32(ctx->r4, 0X2314);
    // 0x80188FA0: jal         0x8009BC2C
    // 0x80188FA4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_90;
    // 0x80188FA4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_90:
    // 0x80188FA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188FAC: lwc1        $f2, 0x9DC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X9DC);
    // 0x80188FB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80188FB4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80188FB8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80188FBC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80188FC0: addiu       $a0, $s1, 0x160
    ctx->r4 = ADD32(ctx->r17, 0X160);
    // 0x80188FC4: jal         0x8009BC2C
    // 0x80188FC8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_91;
    // 0x80188FC8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_91:
    // 0x80188FCC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80188FD0: lwc1        $f2, 0x9E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X9E0);
    // 0x80188FD4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80188FD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80188FDC: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80188FE0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80188FE4: addiu       $a0, $s1, 0x164
    ctx->r4 = ADD32(ctx->r17, 0X164);
    // 0x80188FE8: jal         0x8009BC2C
    // 0x80188FEC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_92;
    // 0x80188FEC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_92:
    // 0x80188FF0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80188FF4: addiu       $v1, $v1, 0x22F0
    ctx->r3 = ADD32(ctx->r3, 0X22F0);
    // 0x80188FF8: lui         $at, 0x437E
    ctx->r1 = S32(0X437E << 16);
    // 0x80188FFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189000: lwc1        $f8, 0x24($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80189004: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80189008: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018900C: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80189010: nop

    // 0x80189014: bc1fl       L_80189EA8
    if (!c1cs) {
        // 0x80189018: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_26;
    // 0x80189018: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_26:
    // 0x8018901C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189020: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80189024: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189028: swc1        $f18, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f18.u32l;
    // 0x8018902C: lw          $t2, 0x28($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X28);
    // 0x80189030: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80189034: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80189038: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x8018903C: lh          $v0, 0xD4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XD4);
    // 0x80189040: swc1        $f20, 0x160($s1)
    MEM_W(0X160, ctx->r17) = ctx->f20.u32l;
    // 0x80189044: swc1        $f20, 0x164($s1)
    MEM_W(0X164, ctx->r17) = ctx->f20.u32l;
    // 0x80189048: beq         $v0, $zero, L_80189060
    if (ctx->r2 == 0) {
        // 0x8018904C: addiu       $t8, $zero, 0x1E
        ctx->r24 = ADD32(0, 0X1E);
            goto L_80189060;
    }
    // 0x8018904C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80189050: beq         $v0, $at, L_80189068
    if (ctx->r2 == ctx->r1) {
        // 0x80189054: addiu       $t4, $zero, 0x577
        ctx->r12 = ADD32(0, 0X577);
            goto L_80189068;
    }
    // 0x80189054: addiu       $t4, $zero, 0x577
    ctx->r12 = ADD32(0, 0X577);
    // 0x80189058: b           L_80189070
    // 0x8018905C: sh          $zero, 0xD4($s1)
    MEM_H(0XD4, ctx->r17) = 0;
        goto L_80189070;
    // 0x8018905C: sh          $zero, 0xD4($s1)
    MEM_H(0XD4, ctx->r17) = 0;
L_80189060:
    // 0x80189060: b           L_8018906C
    // 0x80189064: sh          $t3, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r11;
        goto L_8018906C;
    // 0x80189064: sh          $t3, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r11;
L_80189068:
    // 0x80189068: sh          $t4, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r12;
L_8018906C:
    // 0x8018906C: sh          $zero, 0xD4($s1)
    MEM_H(0XD4, ctx->r17) = 0;
L_80189070:
    // 0x80189070: sw          $t5, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r13;
    // 0x80189074: lh          $t7, 0xD2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XD2);
    // 0x80189078: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8018907C: sh          $t6, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r14;
    // 0x80189080: beq         $t7, $zero, L_801890B8
    if (ctx->r15 == 0) {
        // 0x80189084: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_801890B8;
    }
    // 0x80189084: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80189088: lh          $v0, 0xD0($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XD0);
    // 0x8018908C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80189090: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189094: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80189098: sh          $t8, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r24;
    // 0x8018909C: sh          $zero, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = 0;
    // 0x801890A0: swc1        $f6, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f6.u32l;
    // 0x801890A4: beq         $at, $zero, L_801890B4
    if (ctx->r1 == 0) {
        // 0x801890A8: swc1        $f4, 0xF8($s1)
        MEM_W(0XF8, ctx->r17) = ctx->f4.u32l;
            goto L_801890B4;
    }
    // 0x801890A8: swc1        $f4, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f4.u32l;
    // 0x801890AC: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x801890B0: sh          $t9, 0xD0($s1)
    MEM_H(0XD0, ctx->r17) = ctx->r25;
L_801890B4:
    // 0x801890B4: sh          $t0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r8;
L_801890B8:
    // 0x801890B8: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x801890BC: lui         $a0, 0x3140
    ctx->r4 = S32(0X3140 << 16);
    // 0x801890C0: ori         $a0, $a0, 0x4066
    ctx->r4 = ctx->r4 | 0X4066;
    // 0x801890C4: beq         $v0, $zero, L_801890F4
    if (ctx->r2 == 0) {
        // 0x801890C8: addiu       $a1, $s1, 0x3FC
        ctx->r5 = ADD32(ctx->r17, 0X3FC);
            goto L_801890F4;
    }
    // 0x801890C8: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x801890CC: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x801890D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801890D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801890D8: beql        $t1, $at, L_801890F0
    if (ctx->r9 == ctx->r1) {
        // 0x801890DC: sw          $zero, 0x0($s2)
        MEM_W(0X0, ctx->r18) = 0;
            goto L_801890F0;
    }
    goto skip_27;
    // 0x801890DC: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    skip_27:
    // 0x801890E0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x801890E4: b           L_801890F4
    // 0x801890E8: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
        goto L_801890F4;
    // 0x801890E8: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
    // 0x801890EC: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
L_801890F0:
    // 0x801890F0: lw          $v0, 0x18($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X18);
L_801890F4:
    // 0x801890F4: beq         $v0, $zero, L_80189108
    if (ctx->r2 == 0) {
        // 0x801890F8: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80189108;
    }
    // 0x801890F8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801890FC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80189100: bnel        $t3, $zero, L_80189EA8
    if (ctx->r11 != 0) {
        // 0x80189104: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_28;
    // 0x80189104: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_28:
L_80189108:
    // 0x80189108: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018910C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80189110: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189114: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80189118: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8018911C: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80189120: addiu       $a3, $t4, 0x5D34
    ctx->r7 = ADD32(ctx->r12, 0X5D34);
    // 0x80189124: swc1        $f8, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f8.u32l;
    // 0x80189128: swc1        $f18, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f18.u32l;
    // 0x8018912C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80189130: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189134: jal         0x80019218
    // 0x80189138: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_93;
    // 0x80189138: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_93:
    // 0x8018913C: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x80189140: addiu       $v0, $v0, -0x7A88
    ctx->r2 = ADD32(ctx->r2, -0X7A88);
    // 0x80189144: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80189148: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8018914C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80189150: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80189154: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80189158: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8018915C: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x80189160: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80189164: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x80189168: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018916C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80189170: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x80189174: sw          $t2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r10;
    // 0x80189178: b           L_80189EA4
    // 0x8018917C: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
        goto L_80189EA4;
    // 0x8018917C: sw          $zero, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = 0;
L_80189180:
    // 0x80189180: lh          $t3, 0x50($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X50);
    // 0x80189184: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80189188: addiu       $a0, $s1, 0x3FC
    ctx->r4 = ADD32(ctx->r17, 0X3FC);
    // 0x8018918C: bnel        $t3, $at, L_801891DC
    if (ctx->r11 != ctx->r1) {
        // 0x80189190: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_801891DC;
    }
    goto skip_29;
    // 0x80189190: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_29:
    // 0x80189194: jal         0x8001A500
    // 0x80189198: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    Audio_KillSfxBySource(rdram, ctx);
        goto after_94;
    // 0x80189198: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_94:
    // 0x8018919C: lw          $t4, 0x1C($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X1C);
    // 0x801891A0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801891A4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801891A8: bne         $t4, $zero, L_801891D8
    if (ctx->r12 != 0) {
        // 0x801891AC: lui         $a0, 0x3100
        ctx->r4 = S32(0X3100 << 16);
            goto L_801891D8;
    }
    // 0x801891AC: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x801891B0: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801891B4: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801891B8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801891BC: ori         $a0, $a0, 0x8069
    ctx->r4 = ctx->r4 | 0X8069;
    // 0x801891C0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x801891C4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801891C8: jal         0x80019218
    // 0x801891CC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_95;
    // 0x801891CC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_95:
    // 0x801891D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801891D4: sw          $t6, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r14;
L_801891D8:
    // 0x801891D8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_801891DC:
    // 0x801891DC: beql        $t7, $zero, L_80189240
    if (ctx->r15 == 0) {
        // 0x801891E0: lh          $t3, 0xD0($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XD0);
            goto L_80189240;
    }
    goto skip_30;
    // 0x801891E0: lh          $t3, 0xD0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD0);
    skip_30:
    // 0x801891E4: lh          $t8, 0xBA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XBA);
    // 0x801891E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801891EC: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x801891F0: bne         $t8, $at, L_80189230
    if (ctx->r24 != ctx->r1) {
        // 0x801891F4: addiu       $t2, $zero, 0x8
        ctx->r10 = ADD32(0, 0X8);
            goto L_80189230;
    }
    // 0x801891F4: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x801891F8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801891FC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189200: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80189204: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189208: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8018920C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189210: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x80189214: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80189218: sh          $t9, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r25;
    // 0x8018921C: sh          $t0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r8;
    // 0x80189220: swc1        $f10, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f10.u32l;
    // 0x80189224: swc1        $f6, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f6.u32l;
    // 0x80189228: b           L_80189EA4
    // 0x8018922C: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
        goto L_80189EA4;
    // 0x8018922C: swc1        $f4, 0x16C($s1)
    MEM_W(0X16C, ctx->r17) = ctx->f4.u32l;
L_80189230:
    // 0x80189230: sh          $t1, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r9;
    // 0x80189234: b           L_80189EA4
    // 0x80189238: sh          $t2, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r10;
        goto L_80189EA4;
    // 0x80189238: sh          $t2, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r10;
    // 0x8018923C: lh          $t3, 0xD0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD0);
L_80189240:
    // 0x80189240: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80189244: bnel        $t3, $at, L_80189288
    if (ctx->r11 != ctx->r1) {
        // 0x80189248: lh          $v0, 0xC4($s1)
        ctx->r2 = MEM_H(ctx->r17, 0XC4);
            goto L_80189288;
    }
    goto skip_31;
    // 0x80189248: lh          $v0, 0xC4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC4);
    skip_31:
    // 0x8018924C: lw          $t4, 0x74($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X74);
    // 0x80189250: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189254: addiu       $a0, $a0, -0x2060
    ctx->r4 = ADD32(ctx->r4, -0X2060);
    // 0x80189258: bnel        $t4, $zero, L_80189288
    if (ctx->r12 != 0) {
        // 0x8018925C: lh          $v0, 0xC4($s1)
        ctx->r2 = MEM_H(ctx->r17, 0XC4);
            goto L_80189288;
    }
    goto skip_32;
    // 0x8018925C: lh          $v0, 0xC4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC4);
    skip_32:
    // 0x80189260: jal         0x800BA808
    // 0x80189264: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_96;
    // 0x80189264: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_96:
    // 0x80189268: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8018926C: sh          $t5, 0xD0($s1)
    MEM_H(0XD0, ctx->r17) = ctx->r13;
    // 0x80189270: lw          $t6, 0x74($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X74);
    // 0x80189274: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80189278: sw          $t7, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r15;
    // 0x8018927C: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80189280: sw          $t9, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r25;
    // 0x80189284: lh          $v0, 0xC4($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC4);
L_80189288:
    // 0x80189288: beq         $v0, $zero, L_80189354
    if (ctx->r2 == 0) {
        // 0x8018928C: nop
    
            goto L_80189354;
    }
    // 0x8018928C: nop

    // 0x80189290: lh          $t0, 0xC6($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XC6);
    // 0x80189294: beq         $t0, $zero, L_80189354
    if (ctx->r8 == 0) {
        // 0x80189298: nop
    
            goto L_80189354;
    }
    // 0x80189298: nop

    // 0x8018929C: lh          $t1, 0xC8($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XC8);
    // 0x801892A0: addiu       $t2, $zero, 0x5DC
    ctx->r10 = ADD32(0, 0X5DC);
    // 0x801892A4: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801892A8: beq         $t1, $zero, L_80189354
    if (ctx->r9 == 0) {
        // 0x801892AC: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_80189354;
    }
    // 0x801892AC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x801892B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801892B4: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801892B8: addiu       $v0, $v0, -0x7BAC
    ctx->r2 = ADD32(ctx->r2, -0X7BAC);
    // 0x801892BC: sh          $t2, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r10;
    // 0x801892C0: sll         $t4, $v0, 4
    ctx->r12 = S32(ctx->r2 << 4);
    // 0x801892C4: swc1        $f8, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f8.u32l;
    // 0x801892C8: sw          $zero, 0x70($s2)
    MEM_W(0X70, ctx->r18) = 0;
    // 0x801892CC: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x801892D0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801892D4: sh          $t3, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r11;
    // 0x801892D8: swc1        $f20, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f20.u32l;
    // 0x801892DC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801892E0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801892E4: lw          $t7, 0x1FD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1FD0);
    // 0x801892E8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801892EC: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x801892F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801892F4: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x801892F8: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x801892FC: sw          $t0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r8;
    // 0x80189300: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80189304: addiu       $a0, $s1, 0x3FC
    ctx->r4 = ADD32(ctx->r17, 0X3FC);
    // 0x80189308: sw          $t1, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r9;
    // 0x8018930C: jal         0x8001A500
    // 0x80189310: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    Audio_KillSfxBySource(rdram, ctx);
        goto after_97;
    // 0x80189310: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_97:
    // 0x80189314: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80189318: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8018931C: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80189320: addiu       $a3, $t2, 0x5D34
    ctx->r7 = ADD32(ctx->r10, 0X5D34);
    // 0x80189324: lui         $a0, 0x3140
    ctx->r4 = S32(0X3140 << 16);
    // 0x80189328: ori         $a0, $a0, 0x4067
    ctx->r4 = ctx->r4 | 0X4067;
    // 0x8018932C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189330: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80189334: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80189338: jal         0x80019218
    // 0x8018933C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_98;
    // 0x8018933C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_98:
    // 0x80189340: sh          $zero, 0xC8($s1)
    MEM_H(0XC8, ctx->r17) = 0;
    // 0x80189344: lh          $v0, 0xC8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XC8);
    // 0x80189348: sh          $v0, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r2;
    // 0x8018934C: b           L_80189EA4
    // 0x80189350: sh          $v0, 0xC4($s1)
    MEM_H(0XC4, ctx->r17) = ctx->r2;
        goto L_80189EA4;
    // 0x80189350: sh          $v0, 0xC4($s1)
    MEM_H(0XC4, ctx->r17) = ctx->r2;
L_80189354:
    // 0x80189354: bne         $v0, $zero, L_8018936C
    if (ctx->r2 != 0) {
        // 0x80189358: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8018936C;
    }
    // 0x80189358: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018935C: jal         0x8018A1B0
    // 0x80189360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Area6_8018A1B0(rdram, ctx);
        goto after_99;
    // 0x80189360: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_99:
    // 0x80189364: b           L_80189EA8
    // 0x80189368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80189EA8;
    // 0x80189368: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8018936C:
    // 0x8018936C: lh          $t4, 0xC6($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XC6);
    // 0x80189370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80189374: bnel        $t4, $zero, L_80189390
    if (ctx->r12 != 0) {
        // 0x80189378: lh          $t5, 0xC8($s1)
        ctx->r13 = MEM_H(ctx->r17, 0XC8);
            goto L_80189390;
    }
    goto skip_33;
    // 0x80189378: lh          $t5, 0xC8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XC8);
    skip_33:
    // 0x8018937C: jal         0x8018A1B0
    // 0x80189380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Area6_8018A1B0(rdram, ctx);
        goto after_100;
    // 0x80189380: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_100:
    // 0x80189384: b           L_80189EA8
    // 0x80189388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80189EA8;
    // 0x80189388: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018938C: lh          $t5, 0xC8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XC8);
L_80189390:
    // 0x80189390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80189394: bnel        $t5, $zero, L_80189EA8
    if (ctx->r13 != 0) {
        // 0x80189398: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_34;
    // 0x80189398: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_34:
    // 0x8018939C: jal         0x8018A1B0
    // 0x801893A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Area6_8018A1B0(rdram, ctx);
        goto after_101;
    // 0x801893A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_101:
    // 0x801893A4: b           L_80189EA8
    // 0x801893A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80189EA8;
    // 0x801893A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_801893AC:
    // 0x801893AC: lh          $t6, 0x50($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X50);
    // 0x801893B0: addiu       $at, $zero, 0x578
    ctx->r1 = ADD32(0, 0X578);
    // 0x801893B4: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x801893B8: bne         $t6, $at, L_80189440
    if (ctx->r14 != ctx->r1) {
        // 0x801893BC: nop
    
            goto L_80189440;
    }
    // 0x801893BC: nop

    // 0x801893C0: sh          $t7, 0xAA($s1)
    MEM_H(0XAA, ctx->r17) = ctx->r15;
    // 0x801893C4: lh          $v0, 0xAA($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XAA);
    // 0x801893C8: lh          $t8, 0xBA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XBA);
    // 0x801893CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801893D0: sh          $v0, 0xA8($s1)
    MEM_H(0XA8, ctx->r17) = ctx->r2;
    // 0x801893D4: bne         $t8, $zero, L_801893E0
    if (ctx->r24 != 0) {
        // 0x801893D8: sh          $v0, 0xA6($s1)
        MEM_H(0XA6, ctx->r17) = ctx->r2;
            goto L_801893E0;
    }
    // 0x801893D8: sh          $v0, 0xA6($s1)
    MEM_H(0XA6, ctx->r17) = ctx->r2;
    // 0x801893DC: sh          $t9, 0xBA($s1)
    MEM_H(0XBA, ctx->r17) = ctx->r25;
L_801893E0:
    // 0x801893E0: jal         0x80004EB0
    // 0x801893E4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_102;
    // 0x801893E4: nop

    after_102:
    // 0x801893E8: sub.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x801893EC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801893F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801893F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801893F8: lwc1        $f4, 0x9E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9E4);
    // 0x801893FC: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x80189400: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189404: lui         $a0, 0x3940
    ctx->r4 = S32(0X3940 << 16);
    // 0x80189408: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8018940C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189410: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80189414: ori         $a0, $a0, 0x4068
    ctx->r4 = ctx->r4 | 0X4068;
    // 0x80189418: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8018941C: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80189420: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80189424: swc1        $f8, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f8.u32l;
    // 0x80189428: lw          $t0, 0x70($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X70);
    // 0x8018942C: bne         $t0, $zero, L_80189440
    if (ctx->r8 != 0) {
        // 0x80189430: nop
    
            goto L_80189440;
    }
    // 0x80189430: nop

    // 0x80189434: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189438: jal         0x80019218
    // 0x8018943C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    Audio_PlaySfx(rdram, ctx);
        goto after_103;
    // 0x8018943C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_103:
L_80189440:
    // 0x80189440: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189444: lwc1        $f18, 0x9E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9E8);
    // 0x80189448: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018944C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x80189450: addiu       $a0, $s1, 0x14C
    ctx->r4 = ADD32(ctx->r17, 0X14C);
    // 0x80189454: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x80189458: jal         0x8009BC2C
    // 0x8018945C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_104;
    // 0x8018945C: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_104:
    // 0x80189460: lh          $t2, 0xD0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XD0);
    // 0x80189464: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189468: bne         $t2, $at, L_801894C0
    if (ctx->r10 != ctx->r1) {
        // 0x8018946C: nop
    
            goto L_801894C0;
    }
    // 0x8018946C: nop

    // 0x80189470: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80189474: lwc1        $f6, 0xD8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x80189478: c.eq.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl == ctx->f6.fl;
    // 0x8018947C: nop

    // 0x80189480: bc1f        L_801894C0
    if (!c1cs) {
        // 0x80189484: nop
    
            goto L_801894C0;
    }
    // 0x80189484: nop

    // 0x80189488: lw          $t3, 0x78($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X78);
    // 0x8018948C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189490: addiu       $a0, $a0, -0x20B4
    ctx->r4 = ADD32(ctx->r4, -0X20B4);
    // 0x80189494: bne         $t3, $zero, L_801894C0
    if (ctx->r11 != 0) {
        // 0x80189498: nop
    
            goto L_801894C0;
    }
    // 0x80189498: nop

    // 0x8018949C: jal         0x800BA808
    // 0x801894A0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_105;
    // 0x801894A0: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_105:
    // 0x801894A4: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801894A8: sh          $t4, 0xD0($s1)
    MEM_H(0XD0, ctx->r17) = ctx->r12;
    // 0x801894AC: lw          $t5, 0x78($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X78);
    // 0x801894B0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801894B4: sw          $t6, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r14;
    // 0x801894B8: andi        $t8, $t6, 0x1
    ctx->r24 = ctx->r14 & 0X1;
    // 0x801894BC: sw          $t8, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r24;
L_801894C0:
    // 0x801894C0: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801894C4: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x801894C8: andi        $t0, $t9, 0x3F
    ctx->r8 = ctx->r25 & 0X3F;
    // 0x801894CC: bnel        $t0, $zero, L_801894F8
    if (ctx->r8 != 0) {
        // 0x801894D0: lh          $t1, 0x50($s1)
        ctx->r9 = MEM_H(ctx->r17, 0X50);
            goto L_801894F8;
    }
    goto skip_35;
    // 0x801894D0: lh          $t1, 0x50($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X50);
    skip_35:
    // 0x801894D4: jal         0x80004EB0
    // 0x801894D8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_106;
    // 0x801894D8: nop

    after_106:
    // 0x801894DC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801894E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801894E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801894E8: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801894EC: swc1        $f18, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f18.u32l;
    // 0x801894F0: swc1        $f8, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f8.u32l;
    // 0x801894F4: lh          $t1, 0x50($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X50);
L_801894F8:
    // 0x801894F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801894FC: beql        $t1, $zero, L_80189550
    if (ctx->r9 == 0) {
        // 0x80189500: sh          $t8, 0xD2($s1)
        MEM_H(0XD2, ctx->r17) = ctx->r24;
            goto L_80189550;
    }
    goto skip_36;
    // 0x80189500: sh          $t8, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = ctx->r24;
    skip_36:
    // 0x80189504: lh          $t2, 0xCA($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XCA);
    // 0x80189508: bnel        $t2, $zero, L_8018963C
    if (ctx->r10 != 0) {
        // 0x8018950C: lh          $t3, 0xD4($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XD4);
            goto L_8018963C;
    }
    goto skip_37;
    // 0x8018950C: lh          $t3, 0xD4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD4);
    skip_37:
    // 0x80189510: lh          $t3, 0xCC($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XCC);
    // 0x80189514: bnel        $t3, $zero, L_8018963C
    if (ctx->r11 != 0) {
        // 0x80189518: lh          $t3, 0xD4($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XD4);
            goto L_8018963C;
    }
    goto skip_38;
    // 0x80189518: lh          $t3, 0xD4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD4);
    skip_38:
    // 0x8018951C: lh          $t4, 0xCE($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XCE);
    // 0x80189520: bnel        $t4, $zero, L_8018963C
    if (ctx->r12 != 0) {
        // 0x80189524: lh          $t3, 0xD4($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XD4);
            goto L_8018963C;
    }
    goto skip_39;
    // 0x80189524: lh          $t3, 0xD4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD4);
    skip_39:
    // 0x80189528: lh          $t5, 0xBE($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XBE);
    // 0x8018952C: bnel        $t5, $zero, L_8018963C
    if (ctx->r13 != 0) {
        // 0x80189530: lh          $t3, 0xD4($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XD4);
            goto L_8018963C;
    }
    goto skip_40;
    // 0x80189530: lh          $t3, 0xD4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD4);
    skip_40:
    // 0x80189534: lh          $t6, 0xC0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XC0);
    // 0x80189538: bnel        $t6, $zero, L_8018963C
    if (ctx->r14 != 0) {
        // 0x8018953C: lh          $t3, 0xD4($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XD4);
            goto L_8018963C;
    }
    goto skip_41;
    // 0x8018953C: lh          $t3, 0xD4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD4);
    skip_41:
    // 0x80189540: lh          $t7, 0xC2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC2);
    // 0x80189544: bnel        $t7, $zero, L_8018963C
    if (ctx->r15 != 0) {
        // 0x80189548: lh          $t3, 0xD4($s1)
        ctx->r11 = MEM_H(ctx->r17, 0XD4);
            goto L_8018963C;
    }
    goto skip_42;
    // 0x80189548: lh          $t3, 0xD4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD4);
    skip_42:
    // 0x8018954C: sh          $t8, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = ctx->r24;
L_80189550:
    // 0x80189550: lw          $t9, 0x18($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X18);
    // 0x80189554: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189558: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018955C: beq         $t9, $zero, L_80189574
    if (ctx->r25 == 0) {
        // 0x80189560: lui         $at, 0x42B4
        ctx->r1 = S32(0X42B4 << 16);
            goto L_80189574;
    }
    // 0x80189560: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80189564: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80189568: sh          $t0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r8;
    // 0x8018956C: b           L_80189EA4
    // 0x80189570: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
        goto L_80189EA4;
    // 0x80189570: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
L_80189574:
    // 0x80189574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189578: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018957C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80189580: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80189584: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189588: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8018958C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80189590: sh          $t1, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r9;
    // 0x80189594: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80189598: lui         $a0, 0x3140
    ctx->r4 = S32(0X3140 << 16);
    // 0x8018959C: swc1        $f10, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f10.u32l;
    // 0x801895A0: swc1        $f6, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f6.u32l;
    // 0x801895A4: swc1        $f4, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f4.u32l;
    // 0x801895A8: swc1        $f8, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f8.u32l;
    // 0x801895AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801895B0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801895B4: ori         $a0, $a0, 0x4066
    ctx->r4 = ctx->r4 | 0X4066;
    // 0x801895B8: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x801895BC: jal         0x80019218
    // 0x801895C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_107;
    // 0x801895C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_107:
    // 0x801895C4: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x801895C8: addiu       $v0, $v0, -0x7A88
    ctx->r2 = ADD32(ctx->r2, -0X7A88);
    // 0x801895CC: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x801895D0: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x801895D4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801895D8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x801895DC: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x801895E0: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801895E4: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x801895E8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801895EC: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x801895F0: sh          $zero, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = 0;
    // 0x801895F4: lh          $t0, 0xD2($s1)
    ctx->r8 = MEM_H(ctx->r17, 0XD2);
    // 0x801895F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801895FC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80189600: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80189604: sw          $t9, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r25;
    // 0x80189608: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8018960C: sw          $t0, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r8;
    // 0x80189610: sh          $t1, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r9;
    // 0x80189614: lw          $t2, 0x18($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X18);
    // 0x80189618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018961C: ori         $a1, $zero, 0x8017
    ctx->r5 = 0 | 0X8017;
    // 0x80189620: bne         $t2, $zero, L_80189EA4
    if (ctx->r10 != 0) {
        // 0x80189624: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80189EA4;
    }
    // 0x80189624: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80189628: jal         0x8001D444
    // 0x8018962C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_108;
    // 0x8018962C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_108:
    // 0x80189630: b           L_80189EA8
    // 0x80189634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80189EA8;
    // 0x80189634: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80189638: lh          $t3, 0xD4($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD4);
L_8018963C:
    // 0x8018963C: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80189640: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x80189644: beq         $t3, $zero, L_80189EA4
    if (ctx->r11 == 0) {
        // 0x80189648: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80189EA4;
    }
    // 0x80189648: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018964C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80189650: sh          $t4, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r12;
    // 0x80189654: sh          $t5, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r13;
    // 0x80189658: swc1        $f18, 0x148($s1)
    MEM_W(0X148, ctx->r17) = ctx->f18.u32l;
    // 0x8018965C: sw          $zero, 0x60($s2)
    MEM_W(0X60, ctx->r18) = 0;
    // 0x80189660: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x80189664: sh          $zero, 0x50($s1)
    MEM_H(0X50, ctx->r17) = 0;
    // 0x80189668: sh          $zero, 0x54($s1)
    MEM_H(0X54, ctx->r17) = 0;
    // 0x8018966C: b           L_80189EA4
    // 0x80189670: sw          $t6, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->r14;
        goto L_80189EA4;
    // 0x80189670: sw          $t6, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->r14;
L_80189674:
    // 0x80189674: lh          $t7, 0x50($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X50);
    // 0x80189678: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018967C: addiu       $t8, $s1, 0x3FC
    ctx->r24 = ADD32(ctx->r17, 0X3FC);
    // 0x80189680: bnel        $t7, $at, L_801896C8
    if (ctx->r15 != ctx->r1) {
        // 0x80189684: lw          $v0, 0x84($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X84);
            goto L_801896C8;
    }
    goto skip_43;
    // 0x80189684: lw          $v0, 0x84($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X84);
    skip_43:
    // 0x80189688: jal         0x80187704
    // 0x8018968C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    Area6_Effect395_Spawn(rdram, ctx);
        goto after_109;
    // 0x8018968C: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    after_109:
    // 0x80189690: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189694: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80189698: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018969C: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x801896A0: lui         $a0, 0x3903
    ctx->r4 = S32(0X3903 << 16);
    // 0x801896A4: ori         $a0, $a0, 0x3093
    ctx->r4 = ctx->r4 | 0X3093;
    // 0x801896A8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801896AC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801896B0: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x801896B4: jal         0x80019218
    // 0x801896B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_110;
    // 0x801896B8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_110:
    // 0x801896BC: addiu       $t0, $zero, 0x78
    ctx->r8 = ADD32(0, 0X78);
    // 0x801896C0: sw          $t0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r8;
    // 0x801896C4: lw          $v0, 0x84($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X84);
L_801896C8:
    // 0x801896C8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801896CC: beq         $v0, $zero, L_801896DC
    if (ctx->r2 == 0) {
        // 0x801896D0: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_801896DC;
    }
    // 0x801896D0: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x801896D4: sw          $t1, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r9;
    // 0x801896D8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_801896DC:
    // 0x801896DC: bnel        $v0, $at, L_80189EA8
    if (ctx->r2 != ctx->r1) {
        // 0x801896E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_44;
    // 0x801896E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_44:
    // 0x801896E4: lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X80);
    // 0x801896E8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801896EC: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x801896F0: bnel        $v0, $zero, L_80189764
    if (ctx->r2 != 0) {
        // 0x801896F4: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_80189764;
    }
    goto skip_45;
    // 0x801896F4: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    skip_45:
    // 0x801896F8: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x801896FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189700: addiu       $a0, $a0, 0x47B0
    ctx->r4 = ADD32(ctx->r4, 0X47B0);
    // 0x80189704: blezl       $t2, L_80189720
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80189708: lw          $t3, 0x8($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X8);
            goto L_80189720;
    }
    goto skip_46;
    // 0x80189708: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    skip_46:
    // 0x8018970C: jal         0x800BA808
    // 0x80189710: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_111;
    // 0x80189710: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_111:
    // 0x80189714: b           L_80189760
    // 0x80189718: lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X80);
        goto L_80189760;
    // 0x80189718: lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X80);
    // 0x8018971C: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
L_80189720:
    // 0x80189720: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189724: addiu       $a0, $a0, 0x47D4
    ctx->r4 = ADD32(ctx->r4, 0X47D4);
    // 0x80189728: blezl       $t3, L_80189744
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8018972C: lw          $t4, 0xC($v1)
        ctx->r12 = MEM_W(ctx->r3, 0XC);
            goto L_80189744;
    }
    goto skip_47;
    // 0x8018972C: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
    skip_47:
    // 0x80189730: jal         0x800BA808
    // 0x80189734: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_112;
    // 0x80189734: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_112:
    // 0x80189738: b           L_80189760
    // 0x8018973C: lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X80);
        goto L_80189760;
    // 0x8018973C: lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X80);
    // 0x80189740: lw          $t4, 0xC($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XC);
L_80189744:
    // 0x80189744: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189748: addiu       $a0, $a0, 0x47F8
    ctx->r4 = ADD32(ctx->r4, 0X47F8);
    // 0x8018974C: blezl       $t4, L_80189764
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80189750: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_80189764;
    }
    goto skip_48;
    // 0x80189750: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    skip_48:
    // 0x80189754: jal         0x800BA808
    // 0x80189758: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_113;
    // 0x80189758: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_113:
    // 0x8018975C: lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X80);
L_80189760:
    // 0x80189760: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
L_80189764:
    // 0x80189764: sw          $t5, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r13;
    // 0x80189768: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8018976C: b           L_80189EA4
    // 0x80189770: sw          $t7, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r15;
        goto L_80189EA4;
    // 0x80189770: sw          $t7, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->r15;
L_80189774:
    // 0x80189774: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80189778: lwc1        $f6, 0x16C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X16C);
    // 0x8018977C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189780: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80189784: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80189788: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x8018978C: addiu       $a0, $s1, 0x16C
    ctx->r4 = ADD32(ctx->r17, 0X16C);
    // 0x80189790: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189794: swc1        $f4, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f4.u32l;
    // 0x80189798: lwc1        $f8, 0x9EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9EC);
    // 0x8018979C: jal         0x8009BC2C
    // 0x801897A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_114;
    // 0x801897A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_114:
    // 0x801897A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801897A8: lwc1        $f18, 0x9F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9F0);
    // 0x801897AC: lui         $a1, 0xC5BB
    ctx->r5 = S32(0XC5BB << 16);
    // 0x801897B0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801897B4: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x801897B8: addiu       $a0, $s1, 0xE4
    ctx->r4 = ADD32(ctx->r17, 0XE4);
    // 0x801897BC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801897C0: jal         0x8009BC2C
    // 0x801897C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_115;
    // 0x801897C4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_115:
    // 0x801897C8: lw          $t8, 0x24($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X24);
    // 0x801897CC: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801897D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801897D4: lwc1        $f10, 0x9F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X9F4);
    // 0x801897D8: addiu       $t0, $t0, -0xBAC
    ctx->r8 = ADD32(ctx->r8, -0XBAC);
    // 0x801897DC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x801897E0: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x801897E4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801897E8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801897EC: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x801897F0: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x801897F4: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x801897F8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801897FC: jal         0x8009BC2C
    // 0x80189800: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_116;
    // 0x80189800: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_116:
    // 0x80189804: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189808: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x8018980C: lwc1        $f6, 0x9F8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X9F8);
    // 0x80189810: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80189814: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80189818: addiu       $a0, $a0, 0x2320
    ctx->r4 = ADD32(ctx->r4, 0X2320);
    // 0x8018981C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189820: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x80189824: jal         0x8009BC2C
    // 0x80189828: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_117;
    // 0x80189828: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_117:
    // 0x8018982C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189830: lwc1        $f4, 0x9FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9FC);
    // 0x80189834: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80189838: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8018983C: addiu       $a0, $a0, 0x231C
    ctx->r4 = ADD32(ctx->r4, 0X231C);
    // 0x80189840: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x80189844: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189848: jal         0x8009BC2C
    // 0x8018984C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_118;
    // 0x8018984C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_118:
    // 0x80189850: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80189854: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x80189858: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8018985C: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x80189860: bnel        $t2, $zero, L_80189880
    if (ctx->r10 != 0) {
        // 0x80189864: lh          $t7, 0x50($s1)
        ctx->r15 = MEM_H(ctx->r17, 0X50);
            goto L_80189880;
    }
    goto skip_49;
    // 0x80189864: lh          $t7, 0x50($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X50);
    skip_49:
    // 0x80189868: lw          $t3, 0x24($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X24);
    // 0x8018986C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80189870: sw          $t4, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r12;
    // 0x80189874: andi        $t6, $t4, 0x3
    ctx->r14 = ctx->r12 & 0X3;
    // 0x80189878: sw          $t6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r14;
    // 0x8018987C: lh          $t7, 0x50($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X50);
L_80189880:
    // 0x80189880: bnel        $t7, $zero, L_80189EA8
    if (ctx->r15 != 0) {
        // 0x80189884: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_50;
    // 0x80189884: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_50:
    // 0x80189888: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018988C: sh          $t8, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r24;
    // 0x80189890: b           L_80189EA4
    // 0x80189894: swc1        $f8, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f8.u32l;
        goto L_80189EA4;
    // 0x80189894: swc1        $f8, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f8.u32l;
L_80189898:
    // 0x80189898: lh          $t9, 0xD6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XD6);
    // 0x8018989C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801898A0: lwc1        $f18, 0xA00($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XA00);
    // 0x801898A4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x801898A8: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801898AC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801898B0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x801898B4: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801898B8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801898BC: addiu       $t1, $t1, 0x130
    ctx->r9 = ADD32(ctx->r9, 0X130);
    // 0x801898C0: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801898C4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801898C8: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x801898CC: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x801898D0: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x801898D4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801898D8: jal         0x8009BC2C
    // 0x801898DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_119;
    // 0x801898DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_119:
    // 0x801898E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801898E4: lwc1        $f10, 0xA04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA04);
    // 0x801898E8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801898EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801898F0: addiu       $a0, $a0, 0x2320
    ctx->r4 = ADD32(ctx->r4, 0X2320);
    // 0x801898F4: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x801898F8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801898FC: jal         0x8009BC2C
    // 0x80189900: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_120;
    // 0x80189900: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_120:
    // 0x80189904: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189908: lwc1        $f6, 0xA08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XA08);
    // 0x8018990C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80189910: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80189914: addiu       $a0, $a0, 0x231C
    ctx->r4 = ADD32(ctx->r4, 0X231C);
    // 0x80189918: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x8018991C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80189920: jal         0x8009BC2C
    // 0x80189924: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_121;
    // 0x80189924: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_121:
    // 0x80189928: lwc1        $f2, 0xD8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018992C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80189930: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189934: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x80189938: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018993C: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    // 0x80189940: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189944: bc1fl       L_80189994
    if (!c1cs) {
        // 0x80189948: c.lt.s      $f2, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
            goto L_80189994;
    }
    goto skip_51;
    // 0x80189948: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    skip_51:
    // 0x8018994C: sub.s       $f4, $f24, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f2.fl;
    // 0x80189950: lwc1        $f8, 0xA0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA0C);
    // 0x80189954: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80189958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018995C: mul.s       $f18, $f4, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80189960: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189964: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80189968: swc1        $f6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f6.u32l;
    // 0x8018996C: lwc1        $f4, 0xD8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x80189970: lwc1        $f10, 0xA10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA10);
    // 0x80189974: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80189978: sub.s       $f8, $f24, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x8018997C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189980: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80189984: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80189988: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x8018998C: lwc1        $f2, 0xD8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x80189990: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
L_80189994:
    // 0x80189994: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189998: bc1fl       L_80189EA8
    if (!c1cs) {
        // 0x8018999C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_52;
    // 0x8018999C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_52:
    // 0x801899A0: lwc1        $f8, 0xA14($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA14);
    // 0x801899A4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801899A8: jal         0x8009BC2C
    // 0x801899AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_122;
    // 0x801899AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_122:
    // 0x801899B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801899B4: lwc1        $f10, 0xA18($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA18);
    // 0x801899B8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801899BC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801899C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801899C4: addiu       $a0, $s0, 0x64
    ctx->r4 = ADD32(ctx->r16, 0X64);
    // 0x801899C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801899CC: jal         0x8009BC2C
    // 0x801899D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_123;
    // 0x801899D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_123:
    // 0x801899D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801899D8: lwc1        $f6, 0xA1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XA1C);
    // 0x801899DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801899E0: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x801899E4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801899E8: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801899EC: jal         0x8009BC2C
    // 0x801899F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_124;
    // 0x801899F0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_124:
    // 0x801899F4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801899F8: lwc1        $f4, 0xA20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA20);
    // 0x801899FC: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80189A00: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80189A04: addiu       $v0, $v0, 0x22F0
    ctx->r2 = ADD32(ctx->r2, 0X22F0);
    // 0x80189A08: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80189A0C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80189A10: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80189A14: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80189A18: bc1f        L_80189EA4
    if (!c1cs) {
        // 0x80189A1C: lui         $at, 0x437F
        ctx->r1 = S32(0X437F << 16);
            goto L_80189EA4;
    }
    // 0x80189A1C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80189A20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189A24: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x80189A28: sh          $t3, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = ctx->r11;
    // 0x80189A2C: sh          $t4, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r12;
    // 0x80189A30: swc1        $f8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f8.u32l;
    // 0x80189A34: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80189A38: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80189A3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80189A40: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80189A44: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x80189A48: sh          $t5, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r13;
    // 0x80189A4C: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x80189A50: jal         0x80060FBC
    // 0x80189A54: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_125;
    // 0x80189A54: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_125:
    // 0x80189A58: b           L_80189EA8
    // 0x80189A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80189EA8;
    // 0x80189A5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80189A60:
    // 0x80189A60: lh          $t6, 0x52($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X52);
    // 0x80189A64: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189A68: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189A6C: bne         $t6, $zero, L_80189EA4
    if (ctx->r14 != 0) {
        // 0x80189A70: addiu       $t7, $zero, 0x12C
        ctx->r15 = ADD32(0, 0X12C);
            goto L_80189EA4;
    }
    // 0x80189A70: addiu       $t7, $zero, 0x12C
    ctx->r15 = ADD32(0, 0X12C);
    // 0x80189A74: sw          $zero, 0x60($s2)
    MEM_W(0X60, ctx->r18) = 0;
    // 0x80189A78: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x80189A7C: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80189A80: sh          $t7, 0x52($s1)
    MEM_H(0X52, ctx->r17) = ctx->r15;
    // 0x80189A84: sh          $zero, 0x54($s1)
    MEM_H(0X54, ctx->r17) = 0;
    // 0x80189A88: sh          $t8, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r24;
    // 0x80189A8C: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80189A90: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x80189A94: ori         $a0, $a0, 0x2050
    ctx->r4 = ctx->r4 | 0X2050;
    // 0x80189A98: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80189A9C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189AA0: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80189AA4: jal         0x80019218
    // 0x80189AA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_126;
    // 0x80189AA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_126:
    // 0x80189AAC: b           L_80189EA8
    // 0x80189AB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80189EA8;
    // 0x80189AB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80189AB4:
    // 0x80189AB4: lh          $t0, 0x52($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X52);
    // 0x80189AB8: addiu       $a0, $s1, 0x3FC
    ctx->r4 = ADD32(ctx->r17, 0X3FC);
    // 0x80189ABC: bnel        $t0, $zero, L_80189B0C
    if (ctx->r8 != 0) {
        // 0x80189AC0: lw          $t3, 0x88($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X88);
            goto L_80189B0C;
    }
    goto skip_53;
    // 0x80189AC0: lw          $t3, 0x88($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X88);
    skip_53:
    // 0x80189AC4: jal         0x8001A500
    // 0x80189AC8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    Audio_KillSfxBySource(rdram, ctx);
        goto after_127;
    // 0x80189AC8: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_127:
    // 0x80189ACC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80189AD0: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80189AD4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80189AD8: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80189ADC: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x80189AE0: ori         $a0, $a0, 0x4051
    ctx->r4 = ctx->r4 | 0X4051;
    // 0x80189AE4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80189AE8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80189AEC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x80189AF0: jal         0x80019218
    // 0x80189AF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_128;
    // 0x80189AF4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_128:
    // 0x80189AF8: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x80189AFC: sh          $zero, 0x54($s1)
    MEM_H(0X54, ctx->r17) = 0;
    // 0x80189B00: b           L_80189EA4
    // 0x80189B04: sh          $t2, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r10;
        goto L_80189EA4;
    // 0x80189B04: sh          $t2, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r10;
    // 0x80189B08: lw          $t3, 0x88($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X88);
L_80189B0C:
    // 0x80189B0C: bnel        $t3, $zero, L_80189B64
    if (ctx->r11 != 0) {
        // 0x80189B10: lh          $t4, 0x54($s1)
        ctx->r12 = MEM_H(ctx->r17, 0X54);
            goto L_80189B64;
    }
    goto skip_54;
    // 0x80189B10: lh          $t4, 0x54($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X54);
    skip_54:
    // 0x80189B14: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80189B18: lwc1        $f6, 0x148($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X148);
    // 0x80189B1C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80189B20: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80189B24: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80189B28: addiu       $s0, $s1, 0x148
    ctx->r16 = ADD32(ctx->r17, 0X148);
    // 0x80189B2C: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
    // 0x80189B30: jal         0x80004E20
    // 0x80189B34: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    Math_ModF(rdram, ctx);
        goto after_129;
    // 0x80189B34: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    after_129:
    // 0x80189B38: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x80189B3C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189B40: lwc1        $f4, 0xA24($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA24);
    // 0x80189B44: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80189B48: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80189B4C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189B50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80189B54: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80189B58: jal         0x8009BC2C
    // 0x80189B5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_130;
    // 0x80189B5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_130:
    // 0x80189B60: lh          $t4, 0x54($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X54);
L_80189B64:
    // 0x80189B64: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x80189B68: bnel        $t4, $zero, L_80189EA8
    if (ctx->r12 != 0) {
        // 0x80189B6C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_55;
    // 0x80189B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_55:
    // 0x80189B70: sh          $t5, 0x54($s1)
    MEM_H(0X54, ctx->r17) = ctx->r13;
    // 0x80189B74: lw          $t6, 0x88($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X88);
    // 0x80189B78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80189B7C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80189B80: bnel        $t6, $zero, L_80189B90
    if (ctx->r14 != 0) {
        // 0x80189B84: lh          $t8, 0xBA($s1)
        ctx->r24 = MEM_H(ctx->r17, 0XBA);
            goto L_80189B90;
    }
    goto skip_56;
    // 0x80189B84: lh          $t8, 0xBA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XBA);
    skip_56:
    // 0x80189B88: sh          $t7, 0x54($s1)
    MEM_H(0X54, ctx->r17) = ctx->r15;
    // 0x80189B8C: lh          $t8, 0xBA($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XBA);
L_80189B90:
    // 0x80189B90: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80189B94: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80189B98: bne         $t8, $at, L_80189BA4
    if (ctx->r24 != ctx->r1) {
        // 0x80189B9C: nop
    
            goto L_80189BA4;
    }
    // 0x80189B9C: nop

    // 0x80189BA0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80189BA4:
    // 0x80189BA4: blezl       $v0, L_80189D58
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80189BA8: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80189D58;
    }
    goto skip_57;
    // 0x80189BA8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    skip_57:
    // 0x80189BAC: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80189BB0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80189BB4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80189BB8: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80189BBC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189BC0: lwc1        $f4, 0xA28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA28);
    // 0x80189BC4: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80189BC8: addiu       $t9, $t9, 0x2250
    ctx->r25 = ADD32(ctx->r25, 0X2250);
    // 0x80189BCC: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80189BD0: div.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80189BD4: sw          $v0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r2;
    // 0x80189BD8: mul.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80189BDC: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
L_80189BE0:
    // 0x80189BE0: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80189BE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189BE8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189BEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80189BF0: jal         0x80005FE0
    // 0x80189BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_131;
    // 0x80189BF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_131:
    // 0x80189BF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80189BFC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80189C00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189C04: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80189C08: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80189C0C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x80189C10: addiu       $a2, $sp, 0x8C
    ctx->r6 = ADD32(ctx->r29, 0X8C);
    // 0x80189C14: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x80189C18: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x80189C1C: jal         0x80006A20
    // 0x80189C20: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_132;
    // 0x80189C20: swc1        $f10, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f10.u32l;
    after_132:
    // 0x80189C24: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80189C28: jal         0x80005100
    // 0x80189C2C: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    Math_Atan2F(rdram, ctx);
        goto after_133;
    // 0x80189C2C: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    after_133:
    // 0x80189C30: jal         0x8009F768
    // 0x80189C34: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_134;
    // 0x80189C34: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_134:
    // 0x80189C38: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80189C3C: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80189C40: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x80189C44: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80189C48: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80189C4C: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80189C50: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80189C54: jal         0x80005100
    // 0x80189C58: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_135;
    // 0x80189C58: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_135:
    // 0x80189C5C: jal         0x8009F768
    // 0x80189C60: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_136;
    // 0x80189C60: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_136:
    // 0x80189C64: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80189C68: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80189C6C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80189C70: lw          $v0, 0x30($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X30);
    // 0x80189C74: addiu       $t2, $t2, 0x3FE0
    ctx->r10 = ADD32(ctx->r10, 0X3FE0);
    // 0x80189C78: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x80189C7C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80189C80: bgez        $v0, L_80189C8C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80189C84: lui         $a3, 0x41C8
        ctx->r7 = S32(0X41C8 << 16);
            goto L_80189C8C;
    }
    // 0x80189C84: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    // 0x80189C88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80189C8C:
    // 0x80189C8C: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80189C90: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80189C94: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80189C98: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80189C9C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80189CA0: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80189CA4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80189CA8: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80189CAC: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80189CB0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80189CB4: beql        $t3, $zero, L_80189CDC
    if (ctx->r11 == 0) {
        // 0x80189CB8: sw          $zero, 0x30($t6)
        MEM_W(0X30, ctx->r14) = 0;
            goto L_80189CDC;
    }
    goto skip_58;
    // 0x80189CB8: sw          $zero, 0x30($t6)
    MEM_W(0X30, ctx->r14) = 0;
    skip_58:
    // 0x80189CBC: lhu         $t4, 0x2($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X2);
    // 0x80189CC0: addiu       $at, $zero, 0xBF
    ctx->r1 = ADD32(0, 0XBF);
    // 0x80189CC4: bnel        $t4, $at, L_80189CDC
    if (ctx->r12 != ctx->r1) {
        // 0x80189CC8: sw          $zero, 0x30($t6)
        MEM_W(0X30, ctx->r14) = 0;
            goto L_80189CDC;
    }
    goto skip_59;
    // 0x80189CC8: sw          $zero, 0x30($t6)
    MEM_W(0X30, ctx->r14) = 0;
    skip_59:
    // 0x80189CCC: lw          $t5, 0x60($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X60);
    // 0x80189CD0: bnel        $t5, $zero, L_80189D40
    if (ctx->r13 != 0) {
        // 0x80189CD4: lw          $t1, 0x64($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X64);
            goto L_80189D40;
    }
    goto skip_60;
    // 0x80189CD4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    skip_60:
    // 0x80189CD8: sw          $zero, 0x30($t6)
    MEM_W(0X30, ctx->r14) = 0;
L_80189CDC:
    // 0x80189CDC: lh          $t7, 0xBA($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XBA);
    // 0x80189CE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80189CE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80189CE8: bne         $t7, $at, L_80189CF4
    if (ctx->r15 != ctx->r1) {
        // 0x80189CEC: lwc1        $f4, 0x8C($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_80189CF4;
    }
    // 0x80189CEC: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80189CF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80189CF4:
    // 0x80189CF4: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80189CF8: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80189CFC: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80189D00: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80189D04: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80189D08: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80189D0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80189D10: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80189D14: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80189D18: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80189D1C: add.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80189D20: lwc1        $f10, 0x10C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x80189D24: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80189D28: jal         0x801875E4
    // 0x80189D2C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Area6_ActorMissileSeekPlayer_Spawn(rdram, ctx);
        goto after_137;
    // 0x80189D2C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_137:
    // 0x80189D30: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80189D34: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x80189D38: sw          $t9, 0x30($t0)
    MEM_W(0X30, ctx->r8) = ctx->r25;
    // 0x80189D3C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
L_80189D40:
    // 0x80189D40: lw          $t3, 0x128($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X128);
    // 0x80189D44: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80189D48: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80189D4C: bne         $s0, $t3, L_80189BE0
    if (ctx->r16 != ctx->r11) {
        // 0x80189D50: sw          $t2, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r10;
            goto L_80189BE0;
    }
    // 0x80189D50: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x80189D54: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_80189D58:
    // 0x80189D58: b           L_80189EA4
    // 0x80189D5C: sw          $t4, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->r12;
        goto L_80189EA4;
    // 0x80189D5C: sw          $t4, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->r12;
L_80189D60:
    // 0x80189D60: lw          $t5, 0x88($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X88);
    // 0x80189D64: bne         $t5, $zero, L_80189DB8
    if (ctx->r13 != 0) {
        // 0x80189D68: nop
    
            goto L_80189DB8;
    }
    // 0x80189D68: nop

    // 0x80189D6C: lwc1        $f8, 0x18($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80189D70: lwc1        $f6, 0x148($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X148);
    // 0x80189D74: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80189D78: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80189D7C: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80189D80: addiu       $s0, $s1, 0x148
    ctx->r16 = ADD32(ctx->r17, 0X148);
    // 0x80189D84: swc1        $f18, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f18.u32l;
    // 0x80189D88: jal         0x80004E20
    // 0x80189D8C: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    Math_ModF(rdram, ctx);
        goto after_138;
    // 0x80189D8C: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    after_138:
    // 0x80189D90: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x80189D94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189D98: lwc1        $f4, 0xA2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA2C);
    // 0x80189D9C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80189DA0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80189DA4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80189DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80189DAC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80189DB0: jal         0x8009BC2C
    // 0x80189DB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_139;
    // 0x80189DB4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_139:
L_80189DB8:
    // 0x80189DB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189DBC: lwc1        $f10, 0xA30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA30);
    // 0x80189DC0: lwc1        $f8, 0x148($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X148);
    // 0x80189DC4: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80189DC8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80189DCC: c.le.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl <= ctx->f10.fl;
    // 0x80189DD0: nop

    // 0x80189DD4: bc1fl       L_80189EA8
    if (!c1cs) {
        // 0x80189DD8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_61;
    // 0x80189DD8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_61:
    // 0x80189DDC: lw          $t6, 0x88($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X88);
    // 0x80189DE0: bnel        $t6, $zero, L_80189E04
    if (ctx->r14 != 0) {
        // 0x80189DE4: sh          $t9, 0x50($s1)
        MEM_H(0X50, ctx->r17) = ctx->r25;
            goto L_80189E04;
    }
    goto skip_62;
    // 0x80189DE4: sh          $t9, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r25;
    skip_62:
    // 0x80189DE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80189DEC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80189DF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80189DF4: swc1        $f6, 0x148($s1)
    MEM_W(0X148, ctx->r17) = ctx->f6.u32l;
    // 0x80189DF8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x80189DFC: sh          $t8, 0xD2($s1)
    MEM_H(0XD2, ctx->r17) = ctx->r24;
    // 0x80189E00: sh          $t9, 0x50($s1)
    MEM_H(0X50, ctx->r17) = ctx->r25;
L_80189E04:
    // 0x80189E04: sw          $zero, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = 0;
    // 0x80189E08: sw          $zero, 0x88($s2)
    MEM_W(0X88, ctx->r18) = 0;
    // 0x80189E0C: b           L_80189EA4
    // 0x80189E10: sh          $t0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r8;
        goto L_80189EA4;
    // 0x80189E10: sh          $t0, 0x4E($s1)
    MEM_H(0X4E, ctx->r17) = ctx->r8;
L_80189E14:
    // 0x80189E14: lh          $v0, 0x52($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X52);
    // 0x80189E18: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x80189E1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80189E20: bne         $v0, $at, L_80189E58
    if (ctx->r2 != ctx->r1) {
        // 0x80189E24: addiu       $a0, $a0, -0x7D80
        ctx->r4 = ADD32(ctx->r4, -0X7D80);
            goto L_80189E58;
    }
    // 0x80189E24: addiu       $a0, $a0, -0x7D80
    ctx->r4 = ADD32(ctx->r4, -0X7D80);
    // 0x80189E28: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x80189E2C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80189E30: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80189E34: lw          $v1, 0x1C8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C8);
    // 0x80189E38: beq         $v1, $at, L_80189E48
    if (ctx->r3 == ctx->r1) {
        // 0x80189E3C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80189E48;
    }
    // 0x80189E3C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80189E40: bnel        $v1, $at, L_80189E5C
    if (ctx->r3 != ctx->r1) {
        // 0x80189E44: slti        $at, $v0, 0x32
        ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
            goto L_80189E5C;
    }
    goto skip_63;
    // 0x80189E44: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    skip_63:
L_80189E48:
    // 0x80189E48: sw          $t1, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r9;
    // 0x80189E4C: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80189E50: sw          $zero, 0x1D0($t2)
    MEM_W(0X1D0, ctx->r10) = 0;
    // 0x80189E54: lh          $v0, 0x52($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X52);
L_80189E58:
    // 0x80189E58: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
L_80189E5C:
    // 0x80189E5C: beq         $at, $zero, L_80189E78
    if (ctx->r1 == 0) {
        // 0x80189E60: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189E78;
    }
    // 0x80189E60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80189E64: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80189E68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189E6C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189E70: b           L_80189E88
    // 0x80189E74: swc1        $f18, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f18.u32l;
        goto L_80189E88;
    // 0x80189E74: swc1        $f18, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f18.u32l;
L_80189E78:
    // 0x80189E78: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80189E7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80189E80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80189E84: swc1        $f4, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f4.u32l;
L_80189E88:
    // 0x80189E88: lh          $t3, 0x52($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X52);
    // 0x80189E8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189E90: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80189E94: bnel        $t3, $zero, L_80189EA8
    if (ctx->r11 != 0) {
        // 0x80189E98: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80189EA8;
    }
    goto skip_64;
    // 0x80189E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_64:
    // 0x80189E9C: jal         0x80060FBC
    // 0x80189EA0: sw          $zero, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = 0;
    Object_Kill(rdram, ctx);
        goto after_140;
    // 0x80189EA0: sw          $zero, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = 0;
    after_140:
L_80189EA4:
    // 0x80189EA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80189EA8:
    // 0x80189EA8: jal         0x8018A464
    // 0x80189EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Area6_8018A464(rdram, ctx);
        goto after_141;
    // 0x80189EAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_141:
    // 0x80189EB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80189EB4: jal         0x8018A464
    // 0x80189EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Area6_8018A464(rdram, ctx);
        goto after_142;
    // 0x80189EB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_142:
    // 0x80189EBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80189EC0: jal         0x8018A464
    // 0x80189EC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Area6_8018A464(rdram, ctx);
        goto after_143;
    // 0x80189EC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_143:
    // 0x80189EC8: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80189ECC: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80189ED0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80189ED4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80189ED8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80189EDC: addiu       $t8, $t8, -0xDB0
    ctx->r24 = ADD32(ctx->r24, -0XDB0);
    // 0x80189EE0: addiu       $t7, $t7, -0xDE0
    ctx->r15 = ADD32(ctx->r15, -0XDE0);
    // 0x80189EE4: addiu       $t6, $t6, -0xE10
    ctx->r14 = ADD32(ctx->r14, -0XE10);
    // 0x80189EE8: addiu       $t5, $t5, -0xD20
    ctx->r13 = ADD32(ctx->r13, -0XD20);
    // 0x80189EEC: addiu       $t4, $t4, -0xD50
    ctx->r12 = ADD32(ctx->r12, -0XD50);
    // 0x80189EF0: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80189EF4: addiu       $s0, $s0, -0xD80
    ctx->r16 = ADD32(ctx->r16, -0XD80);
    // 0x80189EF8: sw          $t4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r12;
    // 0x80189EFC: sw          $t5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r13;
    // 0x80189F00: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x80189F04: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x80189F08: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
L_80189F0C:
    // 0x80189F0C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80189F10: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x80189F14: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x80189F18: bne         $t0, $zero, L_80189F5C
    if (ctx->r8 != 0) {
        // 0x80189F1C: nop
    
            goto L_80189F5C;
    }
    // 0x80189F1C: nop

    // 0x80189F20: jal         0x80004EB0
    // 0x80189F24: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_144;
    // 0x80189F24: nop

    after_144:
    // 0x80189F28: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80189F2C: mul.s       $f8, $f10, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80189F30: jal         0x80004EB0
    // 0x80189F34: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_145;
    // 0x80189F34: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    after_145:
    // 0x80189F38: sub.s       $f6, $f0, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80189F3C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80189F40: mul.s       $f18, $f6, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80189F44: jal         0x80004EB0
    // 0x80189F48: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_146;
    // 0x80189F48: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    after_146:
    // 0x80189F4C: sub.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80189F50: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80189F54: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80189F58: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
L_80189F5C:
    // 0x80189F5C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189F60: lwc1        $f8, 0xA34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XA34);
    // 0x80189F64: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80189F68: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80189F6C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80189F70: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189F74: jal         0x8009BC2C
    // 0x80189F78: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_147;
    // 0x80189F78: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_147:
    // 0x80189F7C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80189F80: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189F84: lwc1        $f6, 0xA38($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XA38);
    // 0x80189F88: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80189F8C: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80189F90: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80189F94: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189F98: jal         0x8009BC2C
    // 0x80189F9C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_148;
    // 0x80189F9C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_148:
    // 0x80189FA0: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x80189FA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189FA8: lwc1        $f18, 0xA3C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XA3C);
    // 0x80189FAC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80189FB0: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80189FB4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80189FB8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80189FBC: jal         0x8009BC2C
    // 0x80189FC0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_149;
    // 0x80189FC0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_149:
    // 0x80189FC4: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x80189FC8: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80189FCC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x80189FD0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80189FD4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80189FD8: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x80189FDC: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80189FE0: addiu       $t5, $t5, -0xD9C
    ctx->r13 = ADD32(ctx->r13, -0XD9C);
    // 0x80189FE4: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x80189FE8: sltu        $at, $t4, $t5
    ctx->r1 = ctx->r12 < ctx->r13 ? 1 : 0;
    // 0x80189FEC: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80189FF0: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x80189FF4: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x80189FF8: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x80189FFC: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
    // 0x8018A000: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x8018A004: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x8018A008: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x8018A00C: bne         $at, $zero, L_80189F0C
    if (ctx->r1 != 0) {
        // 0x8018A010: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80189F0C;
    }
    // 0x8018A010: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018A014: lwc1        $f4, 0x1D8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1D8);
    // 0x8018A018: lw          $t6, 0x28($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X28);
    // 0x8018A01C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018A020: addiu       $at, $zero, 0x258
    ctx->r1 = ADD32(0, 0X258);
    // 0x8018A024: swc1        $f4, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->f4.u32l;
    // 0x8018A028: lw          $t7, 0x28($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X28);
    // 0x8018A02C: lwc1        $f10, 0x1D4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1D4);
    // 0x8018A030: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8018A034: addiu       $a0, $a0, -0x4D90
    ctx->r4 = ADD32(ctx->r4, -0X4D90);
    // 0x8018A038: swc1        $f10, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = ctx->f10.u32l;
    // 0x8018A03C: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x8018A040: lwc1        $f8, 0x1D0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1D0);
    // 0x8018A044: swc1        $f8, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->f8.u32l;
    // 0x8018A048: lw          $t9, 0x28($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X28);
    // 0x8018A04C: lwc1        $f6, 0x1E4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1E4);
    // 0x8018A050: swc1        $f6, 0x7C($t9)
    MEM_W(0X7C, ctx->r25) = ctx->f6.u32l;
    // 0x8018A054: lw          $t0, 0x28($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X28);
    // 0x8018A058: lwc1        $f18, 0x1E0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1E0);
    // 0x8018A05C: swc1        $f18, 0x84($t0)
    MEM_W(0X84, ctx->r8) = ctx->f18.u32l;
    // 0x8018A060: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
    // 0x8018A064: lwc1        $f4, 0x1DC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1DC);
    // 0x8018A068: swc1        $f4, 0x8C($t1)
    MEM_W(0X8C, ctx->r9) = ctx->f4.u32l;
    // 0x8018A06C: lw          $t2, 0x28($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X28);
    // 0x8018A070: lwc1        $f10, 0x1F0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X1F0);
    // 0x8018A074: swc1        $f10, 0x94($t2)
    MEM_W(0X94, ctx->r10) = ctx->f10.u32l;
    // 0x8018A078: lw          $t3, 0x28($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X28);
    // 0x8018A07C: lwc1        $f8, 0x1EC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X1EC);
    // 0x8018A080: swc1        $f8, 0x9C($t3)
    MEM_W(0X9C, ctx->r11) = ctx->f8.u32l;
    // 0x8018A084: lw          $t4, 0x28($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X28);
    // 0x8018A088: lwc1        $f6, 0x1E8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1E8);
    // 0x8018A08C: swc1        $f6, 0xA4($t4)
    MEM_W(0XA4, ctx->r12) = ctx->f6.u32l;
    // 0x8018A090: lw          $v0, 0x13A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13A0);
    // 0x8018A094: bnel        $v0, $at, L_8018A0B0
    if (ctx->r2 != ctx->r1) {
        // 0x8018A098: addiu       $at, $zero, 0x2F4
        ctx->r1 = ADD32(0, 0X2F4);
            goto L_8018A0B0;
    }
    goto skip_65;
    // 0x8018A098: addiu       $at, $zero, 0x2F4
    ctx->r1 = ADD32(0, 0X2F4);
    skip_65:
    // 0x8018A09C: jal         0x800BA808
    // 0x8018A0A0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_150;
    // 0x8018A0A0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_150:
    // 0x8018A0A4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8018A0A8: lw          $v0, 0x13A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13A0);
    // 0x8018A0AC: addiu       $at, $zero, 0x2F4
    ctx->r1 = ADD32(0, 0X2F4);
L_8018A0B0:
    // 0x8018A0B0: bne         $v0, $at, L_8018A0C4
    if (ctx->r2 != ctx->r1) {
        // 0x8018A0B4: or          $v1, $s1, $zero
        ctx->r3 = ctx->r17 | 0;
            goto L_8018A0C4;
    }
    // 0x8018A0B4: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8018A0B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018A0BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018A0C0: sw          $t5, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = ctx->r13;
L_8018A0C4:
    // 0x8018A0C4: slti        $at, $v0, 0x2F5
    ctx->r1 = SIGNED(ctx->r2) < 0X2F5 ? 1 : 0;
    // 0x8018A0C8: bne         $at, $zero, L_8018A108
    if (ctx->r1 != 0) {
        // 0x8018A0CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018A108;
    }
    // 0x8018A0CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018A0D0: lh          $t6, 0x60($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X60);
    // 0x8018A0D4: lui         $at, 0x4443
    ctx->r1 = S32(0X4443 << 16);
    // 0x8018A0D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018A0DC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8018A0E0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018A0E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A0E8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8018A0EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018A0F0: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8018A0F4: mul.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8018A0F8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018A0FC: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8018A100: nop

    // 0x8018A104: sw          $t8, 0x7848($at)
    MEM_W(0X7848, ctx->r1) = ctx->r24;
L_8018A108:
    // 0x8018A108: lh          $a0, 0x88($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X88);
    // 0x8018A10C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8018A110: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x8018A114: beq         $a0, $zero, L_8018A120
    if (ctx->r4 == 0) {
        // 0x8018A118: addiu       $t9, $a0, -0x1
        ctx->r25 = ADD32(ctx->r4, -0X1);
            goto L_8018A120;
    }
    // 0x8018A118: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x8018A11C: sh          $t9, 0x88($v1)
    MEM_H(0X88, ctx->r3) = ctx->r25;
L_8018A120:
    // 0x8018A120: bne         $at, $zero, L_8018A108
    if (ctx->r1 != 0) {
        // 0x8018A124: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8018A108;
    }
    // 0x8018A124: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8018A128: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018A12C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018A130: lwc1        $f8, 0xD8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XD8);
    // 0x8018A134: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018A138: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8018A13C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8018A140: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8018A144: bc1fl       L_8018A170
    if (!c1cs) {
        // 0x8018A148: lw          $v0, 0x14($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X14);
            goto L_8018A170;
    }
    goto skip_66;
    // 0x8018A148: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
    skip_66:
L_8018A14C:
    // 0x8018A14C: lh          $t0, 0x88($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X88);
    // 0x8018A150: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8018A154: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8018A158: bne         $t0, $zero, L_8018A164
    if (ctx->r8 != 0) {
        // 0x8018A15C: nop
    
            goto L_8018A164;
    }
    // 0x8018A15C: nop

    // 0x8018A160: sh          $t1, 0x88($v1)
    MEM_H(0X88, ctx->r3) = ctx->r9;
L_8018A164:
    // 0x8018A164: bne         $v0, $a0, L_8018A14C
    if (ctx->r2 != ctx->r4) {
        // 0x8018A168: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8018A14C;
    }
    // 0x8018A168: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8018A16C: lw          $v0, 0x14($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14);
L_8018A170:
    // 0x8018A170: beq         $v0, $zero, L_8018A17C
    if (ctx->r2 == 0) {
        // 0x8018A174: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8018A17C;
    }
    // 0x8018A174: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8018A178: sw          $t2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r10;
L_8018A17C:
    // 0x8018A17C: lw          $v0, 0x64($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X64);
    // 0x8018A180: beq         $v0, $zero, L_8018A18C
    if (ctx->r2 == 0) {
        // 0x8018A184: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8018A18C;
    }
    // 0x8018A184: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8018A188: sw          $t3, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r11;
L_8018A18C:
    // 0x8018A18C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8018A190: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018A194: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018A198: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8018A19C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8018A1A0: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8018A1A4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8018A1A8: jr          $ra
    // 0x8018A1AC: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x8018A1AC: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
;}
RECOMP_FUNC void Zoness_80190790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190790: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80190794: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80190798: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019079C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801907A0: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x801907A4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801907A8: sh          $t7, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r15;
    // 0x801907AC: lh          $t8, 0x4E($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X4E);
    // 0x801907B0: slti        $at, $t8, 0xC8
    ctx->r1 = SIGNED(ctx->r24) < 0XC8 ? 1 : 0;
    // 0x801907B4: bnel        $at, $zero, L_801907C4
    if (ctx->r1 != 0) {
        // 0x801907B8: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_801907C4;
    }
    goto skip_0;
    // 0x801907B8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_0:
    // 0x801907BC: sh          $zero, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = 0;
    // 0x801907C0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_801907C4:
    // 0x801907C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801907C8: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801907CC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801907D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801907D4: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
    // 0x801907D8: lwc1        $f16, 0xE08($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XE08);
    // 0x801907DC: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    // 0x801907E0: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801907E4: jal         0x80023090
    // 0x801907E8: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x801907E8: nop

    after_0:
    // 0x801907EC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801907F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801907F4: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801907F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801907FC: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80190800: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80190804: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190808: lwc1        $f10, 0x118($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8019080C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190810: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80190814: swc1        $f2, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f2.u32l;
    // 0x80190818: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x8019081C: swc1        $f18, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f18.u32l;
    // 0x80190820: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190824: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x80190828: swc1        $f8, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f8.u32l;
    // 0x8019082C: lwc1        $f6, 0xE0C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XE0C);
    // 0x80190830: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80190834: jal         0x80023090
    // 0x80190838: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80190838: nop

    after_1:
    // 0x8019083C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80190840: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80190844: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80190848: addiu       $v1, $v1, 0x3FE0
    ctx->r3 = ADD32(ctx->r3, 0X3FE0);
    // 0x8019084C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80190850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80190854: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x80190858: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x8019085C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80190860: swc1        $f10, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f10.u32l;
L_80190864:
    // 0x80190864: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80190868: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8019086C: bne         $a0, $t9, L_80190938
    if (ctx->r4 != ctx->r25) {
        // 0x80190870: nop
    
            goto L_80190938;
    }
    // 0x80190870: nop

    // 0x80190874: lhu         $t0, 0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2);
    // 0x80190878: bne         $a1, $t0, L_80190938
    if (ctx->r5 != ctx->r8) {
        // 0x8019087C: nop
    
            goto L_80190938;
    }
    // 0x8019087C: nop

    // 0x80190880: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x80190884: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x80190888: bne         $t1, $t2, L_80190938
    if (ctx->r9 != ctx->r10) {
        // 0x8019088C: nop
    
            goto L_80190938;
    }
    // 0x8019088C: nop

    // 0x80190890: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80190894: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80190898: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8019089C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801908A0: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x801908A4: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    // 0x801908A8: jal         0x80005100
    // 0x801908AC: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x801908AC: sub.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f8.fl;
    after_2:
    // 0x801908B0: jal         0x8009F768
    // 0x801908B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x801908B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x801908B8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801908BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801908C0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801908C4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801908C8: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x801908CC: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x801908D0: jal         0x8009BD38
    // 0x801908D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x801908D4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x801908D8: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x801908DC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801908E0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801908E4: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801908E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801908EC: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801908F0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801908F4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801908F8: nop

    // 0x801908FC: bc1f        L_80190940
    if (!c1cs) {
        // 0x80190900: nop
    
            goto L_80190940;
    }
    // 0x80190900: nop

    // 0x80190904: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80190908: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8019090C: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80190910: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80190914: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80190918: nop

    // 0x8019091C: bc1f        L_80190940
    if (!c1cs) {
        // 0x80190920: nop
    
            goto L_80190940;
    }
    // 0x80190920: nop

    // 0x80190924: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80190928: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    // 0x8019092C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80190930: b           L_80190940
    // 0x80190934: sw          $t4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r12;
        goto L_80190940;
    // 0x80190934: sw          $t4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r12;
L_80190938:
    // 0x80190938: bne         $v0, $a2, L_80190864
    if (ctx->r2 != ctx->r6) {
        // 0x8019093C: addiu       $v1, $v1, 0x2F4
        ctx->r3 = ADD32(ctx->r3, 0X2F4);
            goto L_80190864;
    }
    // 0x8019093C: addiu       $v1, $v1, 0x2F4
    ctx->r3 = ADD32(ctx->r3, 0X2F4);
L_80190940:
    // 0x80190940: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80190944: lwc1        $f8, 0xE10($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XE10);
    // 0x80190948: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8019094C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190950: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80190954: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80190958: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019095C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80190960: jal         0x80005E90
    // 0x80190964: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x80190964: nop

    after_5:
    // 0x80190968: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019096C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80190970: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80190974: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190978: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019097C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80190980: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80190984: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80190988: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8019098C: jal         0x80006A20
    // 0x80190990: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_6;
    // 0x80190990: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x80190994: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80190998: lh          $t5, 0x4E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4E);
    // 0x8019099C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801909A0: swc1        $f18, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f18.u32l;
    // 0x801909A4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801909A8: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x801909AC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801909B0: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    // 0x801909B4: lw          $t7, -0x7D3C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D3C);
    // 0x801909B8: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x801909BC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801909C0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801909C4: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x801909C8: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801909CC: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x801909D0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801909D4: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x801909D8: lwc1        $f16, 0xF4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801909DC: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x801909E0: lwc1        $f18, 0xF8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x801909E4: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x801909E8: lwc1        $f4, 0xFC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x801909EC: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x801909F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801909F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801909F8: jr          $ra
    // 0x801909FC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801909FC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Aquas_801BE274(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BE274: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801BE278: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801BE27C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x801BE280: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x801BE284: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x801BE288: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801BE28C: addiu       $t7, $t7, 0x8F4
    ctx->r15 = ADD32(ctx->r15, 0X8F4);
    // 0x801BE290: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801BE294: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x801BE298: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801BE29C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801BE2A0: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801BE2A4: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801BE2A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BE2AC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801BE2B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BE2B4: lwc1        $f4, 0x2224($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2224);
    // 0x801BE2B8: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801BE2BC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BE2C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801BE2C4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801BE2C8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801BE2CC: jal         0x80005E90
    // 0x801BE2D0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x801BE2D0: nop

    after_0:
    // 0x801BE2D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BE2D8: lwc1        $f10, 0x2228($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X2228);
    // 0x801BE2DC: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801BE2E0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BE2E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BE2E8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801BE2EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801BE2F0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801BE2F4: jal         0x80005D44
    // 0x801BE2F8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801BE2F8: nop

    after_1:
    // 0x801BE2FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801BE300: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801BE304: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BE308: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BE30C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BE310: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x801BE314: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x801BE318: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x801BE31C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x801BE320: jal         0x80006A20
    // 0x801BE324: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x801BE324: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801BE328: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x801BE32C: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801BE330: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801BE334: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801BE338: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BE33C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801BE340: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801BE344: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801BE348: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801BE34C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801BE350: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x801BE354: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801BE358: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801BE35C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x801BE360: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801BE364: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BE368: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x801BE36C: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801BE370: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    // 0x801BE374: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x801BE378: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x801BE37C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x801BE380: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x801BE384: jal         0x80006A20
    // 0x801BE388: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_3;
    // 0x801BE388: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x801BE38C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801BE390: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801BE394: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BE398: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801BE39C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801BE3A0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801BE3A4: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x801BE3A8: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801BE3AC: addiu       $a0, $zero, 0x163
    ctx->r4 = ADD32(0, 0X163);
    // 0x801BE3B0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x801BE3B4: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x801BE3B8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x801BE3BC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801BE3C0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801BE3C4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801BE3C8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801BE3CC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801BE3D0: swc1        $f16, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f16.u32l;
    // 0x801BE3D4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801BE3D8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x801BE3DC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801BE3E0: jal         0x8007F04C
    // 0x801BE3E4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    Effect_SpawnById2(rdram, ctx);
        goto after_4;
    // 0x801BE3E4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x801BE3E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801BE3EC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801BE3F0: jr          $ra
    // 0x801BE3F4: nop

    return;
    // 0x801BE3F4: nop

;}
RECOMP_FUNC void Zoness_ZoBarrier_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D3C4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8019D3C8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019D3CC: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x8019D3D0: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019D3D4: addiu       $a0, $a0, -0x43C
    ctx->r4 = ADD32(ctx->r4, -0X43C);
    // 0x8019D3D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019D3DC: jal         0x8009AA20
    // 0x8019D3E0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x8019D3E0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8019D3E4: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8019D3E8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019D3EC: addiu       $t7, $t7, 0x4660
    ctx->r15 = ADD32(ctx->r15, 0X4660);
    // 0x8019D3F0: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x8019D3F4: lui         $a3, 0x801A
    ctx->r7 = S32(0X801A << 16);
    // 0x8019D3F8: addiu       $a3, $a3, -0x2CC0
    ctx->r7 = ADD32(ctx->r7, -0X2CC0);
    // 0x8019D3FC: addiu       $a1, $a1, -0x370
    ctx->r5 = ADD32(ctx->r5, -0X370);
    // 0x8019D400: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8019D404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8019D408: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8019D40C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8019D410: jal         0x8009A72C
    // 0x8019D414: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x8019D414: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_1:
    // 0x8019D418: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019D41C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    // 0x8019D420: jr          $ra
    // 0x8019D424: nop

    return;
    // 0x8019D424: nop

;}
RECOMP_FUNC void Zoness_ActorDebris_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801900FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80190100: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80190104: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80190108: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8019010C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80190110: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80190114: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80190118: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8019011C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80190120: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80190124: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80190128: addiu       $s0, $s0, -0x11E4
    ctx->r16 = ADD32(ctx->r16, -0X11E4);
    // 0x8019012C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_80190130:
    // 0x80190130: bnel        $t6, $zero, L_80190180
    if (ctx->r14 != 0) {
        // 0x80190134: addiu       $s0, $s0, -0x2F4
        ctx->r16 = ADD32(ctx->r16, -0X2F4);
            goto L_80190180;
    }
    goto skip_0;
    // 0x80190134: addiu       $s0, $s0, -0x2F4
    ctx->r16 = ADD32(ctx->r16, -0X2F4);
    skip_0:
    // 0x80190138: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8019013C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80190140: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80190144: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80190148: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x8019014C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80190150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80190154: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80190158: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8019015C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80190160: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80190164: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80190168: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8019016C: jal         0x80190028
    // 0x80190170: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    Zoness_ActorDebris_Setup(rdram, ctx);
        goto after_0;
    // 0x80190170: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    after_0:
    // 0x80190174: b           L_8019018C
    // 0x80190178: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8019018C;
    // 0x80190178: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8019017C: addiu       $s0, $s0, -0x2F4
    ctx->r16 = ADD32(ctx->r16, -0X2F4);
L_80190180:
    // 0x80190180: bnel        $s0, $v0, L_80190130
    if (ctx->r16 != ctx->r2) {
        // 0x80190184: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_80190130;
    }
    goto skip_1;
    // 0x80190184: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x80190188: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8019018C:
    // 0x8019018C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80190190: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80190194: jr          $ra
    // 0x80190198: nop

    return;
    // 0x80190198: nop

;}
RECOMP_FUNC void Solar_SoVulkain_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6BDC: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x801A6BE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801A6BE4: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x801A6BE8: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x801A6BEC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801A6BF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A6BF4: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    // 0x801A6BF8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801A6BFC: addiu       $t7, $t7, -0x638
    ctx->r15 = ADD32(ctx->r15, -0X638);
    // 0x801A6C00: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801A6C04: addiu       $t6, $sp, 0xA0
    ctx->r14 = ADD32(ctx->r29, 0XA0);
    // 0x801A6C08: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x801A6C0C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x801A6C10: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801A6C14: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801A6C18: addiu       $t2, $t2, -0x62C
    ctx->r10 = ADD32(ctx->r10, -0X62C);
    // 0x801A6C1C: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x801A6C20: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x801A6C24: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x801A6C28: addiu       $t1, $sp, 0x94
    ctx->r9 = ADD32(ctx->r29, 0X94);
    // 0x801A6C2C: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x801A6C30: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x801A6C34: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x801A6C38: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801A6C3C: addiu       $t8, $t8, -0x620
    ctx->r24 = ADD32(ctx->r24, -0X620);
    // 0x801A6C40: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x801A6C44: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x801A6C48: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x801A6C4C: addiu       $t9, $sp, 0x88
    ctx->r25 = ADD32(ctx->r29, 0X88);
    // 0x801A6C50: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x801A6C54: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x801A6C58: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x801A6C5C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x801A6C60: addiu       $t4, $t4, -0x614
    ctx->r12 = ADD32(ctx->r12, -0X614);
    // 0x801A6C64: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x801A6C68: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x801A6C6C: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x801A6C70: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801A6C74: addiu       $t5, $t5, -0x608
    ctx->r13 = ADD32(ctx->r13, -0X608);
    // 0x801A6C78: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x801A6C7C: lw          $t2, 0x4($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X4);
    // 0x801A6C80: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801A6C84: addiu       $t0, $t0, -0x5FC
    ctx->r8 = ADD32(ctx->r8, -0X5FC);
    // 0x801A6C88: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x801A6C8C: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x801A6C90: addiu       $t8, $sp, 0x64
    ctx->r24 = ADD32(ctx->r29, 0X64);
    // 0x801A6C94: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801A6C98: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x801A6C9C: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x801A6CA0: addiu       $t6, $t6, -0x5F0
    ctx->r14 = ADD32(ctx->r14, -0X5F0);
    // 0x801A6CA4: addiu       $t2, $sp, 0x58
    ctx->r10 = ADD32(ctx->r29, 0X58);
    // 0x801A6CA8: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x801A6CAC: lw          $t9, 0x4($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X4);
    // 0x801A6CB0: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801A6CB4: addiu       $t1, $t1, -0x5E4
    ctx->r9 = ADD32(ctx->r9, -0X5E4);
    // 0x801A6CB8: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x801A6CBC: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x801A6CC0: addiu       $t3, $sp, 0x4C
    ctx->r11 = ADD32(ctx->r29, 0X4C);
    // 0x801A6CC4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801A6CC8: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x801A6CCC: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x801A6CD0: lw          $t4, 0x4($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X4);
    // 0x801A6CD4: addiu       $t7, $t7, -0x5D8
    ctx->r15 = ADD32(ctx->r15, -0X5D8);
    // 0x801A6CD8: sw          $at, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r1;
    // 0x801A6CDC: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x801A6CE0: sw          $t4, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r12;
    // 0x801A6CE4: addiu       $t5, $sp, 0x40
    ctx->r13 = ADD32(ctx->r29, 0X40);
    // 0x801A6CE8: sw          $at, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r1;
    // 0x801A6CEC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x801A6CF0: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801A6CF4: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801A6CF8: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x801A6CFC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x801A6D00: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x801A6D04: addiu       $t8, $t8, -0x5CC
    ctx->r24 = ADD32(ctx->r24, -0X5CC);
    // 0x801A6D08: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x801A6D0C: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x801A6D10: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x801A6D14: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x801A6D18: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x801A6D1C: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x801A6D20: sw          $t4, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r12;
    // 0x801A6D24: addiu       $t6, $a0, -0x2
    ctx->r14 = ADD32(ctx->r4, -0X2);
    // 0x801A6D28: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x801A6D2C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x801A6D30: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x801A6D34: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x801A6D38: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x801A6D3C: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x801A6D40: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x801A6D44: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x801A6D48: lw          $t4, 0x4($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X4);
    // 0x801A6D4C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x801A6D50: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x801A6D54: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x801A6D58: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x801A6D5C: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x801A6D60: beq         $at, $zero, L_801A71A4
    if (ctx->r1 == 0) {
        // 0x801A6D64: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801A71A4;
    }
    // 0x801A6D64: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801A6D68: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801A6D6C: addu        $at, $at, $t6
    gpr jr_addend_801A6D74 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A6D70: lw          $t6, 0x184C($at)
    ctx->r14 = ADD32(ctx->r1, 0X184C);
    // 0x801A6D74: jr          $t6
    // 0x801A6D78: nop

    switch (jr_addend_801A6D74 >> 2) {
        case 0: goto L_801A6DCC; break;
        case 1: goto L_801A6E94; break;
        case 2: goto L_801A6F14; break;
        case 3: goto L_801A6FBC; break;
        case 4: goto L_801A7080; break;
        case 5: goto L_801A7100; break;
        case 6: goto L_801A71A4; break;
        case 7: goto L_801A71A4; break;
        case 8: goto L_801A71A4; break;
        case 9: goto L_801A6D7C; break;
        default: switch_error(__func__, 0x801A6D74, 0x801C184C);
    }
    // 0x801A6D78: nop

L_801A6D7C:
    // 0x801A6D7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6D80: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6D84: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x801A6D88: jal         0x80006970
    // 0x801A6D8C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x801A6D8C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x801A6D90: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6D94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6D98: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801A6D9C: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x801A6DA0: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6DA4: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x801A6DA8: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6DAC: swc1        $f8, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f8.u32l;
    // 0x801A6DB0: jal         0x80006AB8
    // 0x801A6DB4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_1;
    // 0x801A6DB4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_1:
    // 0x801A6DB8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6DBC: swc1        $f10, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f10.u32l;
    // 0x801A6DC0: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6DC4: b           L_801A71A4
    // 0x801A6DC8: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
        goto L_801A71A4;
    // 0x801A6DC8: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
L_801A6DCC:
    // 0x801A6DCC: lh          $v0, 0x8C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8C);
    // 0x801A6DD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6DD4: blez        $v0, L_801A6E4C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801A6DD8: nop
    
            goto L_801A6E4C;
    }
    // 0x801A6DD8: nop

    // 0x801A6DDC: jal         0x80005708
    // 0x801A6DE0: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x801A6DE0: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_2:
    // 0x801A6DE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6DE8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6DEC: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x801A6DF0: jal         0x80006970
    // 0x801A6DF4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x801A6DF4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x801A6DF8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6DFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6E00: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    // 0x801A6E04: swc1        $f18, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f18.u32l;
    // 0x801A6E08: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6E0C: swc1        $f4, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f4.u32l;
    // 0x801A6E10: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6E14: jal         0x80005740
    // 0x801A6E18: swc1        $f6, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->f6.u32l;
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x801A6E18: swc1        $f6, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->f6.u32l;
    after_4:
    // 0x801A6E1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6E20: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6E24: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x801A6E28: jal         0x80006970
    // 0x801A6E2C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x801A6E2C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_5:
    // 0x801A6E30: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6E34: lh          $v0, 0x8C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8C);
    // 0x801A6E38: swc1        $f8, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f8.u32l;
    // 0x801A6E3C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6E40: swc1        $f10, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f10.u32l;
    // 0x801A6E44: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6E48: swc1        $f16, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f16.u32l;
L_801A6E4C:
    // 0x801A6E4C: bgez        $v0, L_801A71A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801A6E50: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801A71A4;
    }
    // 0x801A6E50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6E54: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6E58: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x801A6E5C: jal         0x80006970
    // 0x801A6E60: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x801A6E60: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x801A6E64: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6E68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6E6C: addiu       $a1, $s0, 0x17C
    ctx->r5 = ADD32(ctx->r16, 0X17C);
    // 0x801A6E70: swc1        $f18, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f18.u32l;
    // 0x801A6E74: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6E78: swc1        $f4, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f4.u32l;
    // 0x801A6E7C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6E80: swc1        $f6, 0x150($s0)
    MEM_W(0X150, ctx->r16) = ctx->f6.u32l;
    // 0x801A6E84: jal         0x80006AB8
    // 0x801A6E88: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_7;
    // 0x801A6E88: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_7:
    // 0x801A6E8C: b           L_801A71A8
    // 0x801A6E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A71A8;
    // 0x801A6E90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A6E94:
    // 0x801A6E94: lh          $v0, 0x8C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8C);
    // 0x801A6E98: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6E9C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801A6EA0: blez        $v0, L_801A6ECC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801A6EA4: nop
    
            goto L_801A6ECC;
    }
    // 0x801A6EA4: nop

    // 0x801A6EA8: jal         0x80006970
    // 0x801A6EAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x801A6EAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_8:
    // 0x801A6EB0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6EB4: lh          $v0, 0x8C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8C);
    // 0x801A6EB8: swc1        $f8, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f8.u32l;
    // 0x801A6EBC: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6EC0: swc1        $f10, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f10.u32l;
    // 0x801A6EC4: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6EC8: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
L_801A6ECC:
    // 0x801A6ECC: bgez        $v0, L_801A71A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801A6ED0: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801A71A4;
    }
    // 0x801A6ED0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6ED4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6ED8: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x801A6EDC: jal         0x80006970
    // 0x801A6EE0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_9;
    // 0x801A6EE0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_9:
    // 0x801A6EE4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6EE8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6EEC: addiu       $a1, $s0, 0x194
    ctx->r5 = ADD32(ctx->r16, 0X194);
    // 0x801A6EF0: swc1        $f18, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f18.u32l;
    // 0x801A6EF4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6EF8: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    // 0x801A6EFC: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6F00: swc1        $f6, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f6.u32l;
    // 0x801A6F04: jal         0x80006AB8
    // 0x801A6F08: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_10;
    // 0x801A6F08: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_10:
    // 0x801A6F0C: b           L_801A71A8
    // 0x801A6F10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A71A8;
    // 0x801A6F10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A6F14:
    // 0x801A6F14: lh          $t2, 0x8C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8C);
    // 0x801A6F18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6F1C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801A6F20: blez        $t2, L_801A6F64
    if (SIGNED(ctx->r10) <= 0) {
        // 0x801A6F24: lui         $t5, 0x8017
        ctx->r13 = S32(0X8017 << 16);
            goto L_801A6F64;
    }
    // 0x801A6F24: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801A6F28: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6F2C: jal         0x80006970
    // 0x801A6F30: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_11;
    // 0x801A6F30: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_11:
    // 0x801A6F34: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6F38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6F3C: addiu       $a1, $s0, 0x164
    ctx->r5 = ADD32(ctx->r16, 0X164);
    // 0x801A6F40: swc1        $f8, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f8.u32l;
    // 0x801A6F44: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6F48: swc1        $f10, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f10.u32l;
    // 0x801A6F4C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6F50: swc1        $f16, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f16.u32l;
    // 0x801A6F54: jal         0x80006AB8
    // 0x801A6F58: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_12;
    // 0x801A6F58: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_12:
    // 0x801A6F5C: b           L_801A71A8
    // 0x801A6F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A71A8;
    // 0x801A6F60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A6F64:
    // 0x801A6F64: lh          $t5, -0xE68($t5)
    ctx->r13 = MEM_H(ctx->r13, -0XE68);
    // 0x801A6F68: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A6F6C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6F70: beq         $t5, $at, L_801A6F94
    if (ctx->r13 == ctx->r1) {
        // 0x801A6F74: addiu       $a1, $sp, 0x4C
        ctx->r5 = ADD32(ctx->r29, 0X4C);
            goto L_801A6F94;
    }
    // 0x801A6F74: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x801A6F78: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6F7C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6F80: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x801A6F84: jal         0x80006970
    // 0x801A6F88: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x801A6F88: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_13:
    // 0x801A6F8C: b           L_801A6FA4
    // 0x801A6F90: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
        goto L_801A6FA4;
    // 0x801A6F90: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
L_801A6F94:
    // 0x801A6F94: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6F98: jal         0x80006970
    // 0x801A6F9C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x801A6F9C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_14:
    // 0x801A6FA0: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
L_801A6FA4:
    // 0x801A6FA4: swc1        $f18, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f18.u32l;
    // 0x801A6FA8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6FAC: swc1        $f4, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f4.u32l;
    // 0x801A6FB0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6FB4: b           L_801A71A4
    // 0x801A6FB8: swc1        $f6, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f6.u32l;
        goto L_801A71A4;
    // 0x801A6FB8: swc1        $f6, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f6.u32l;
L_801A6FBC:
    // 0x801A6FBC: lh          $v0, 0x8E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8E);
    // 0x801A6FC0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6FC4: blez        $v0, L_801A704C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801A6FC8: nop
    
            goto L_801A704C;
    }
    // 0x801A6FC8: nop

    // 0x801A6FCC: jal         0x80005708
    // 0x801A6FD0: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    Matrix_Push(rdram, ctx);
        goto after_15;
    // 0x801A6FD0: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    after_15:
    // 0x801A6FD4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6FD8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A6FDC: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x801A6FE0: jal         0x80006970
    // 0x801A6FE4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x801A6FE4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_16:
    // 0x801A6FE8: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A6FEC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A6FF0: addiu       $a0, $a0, -0x4438
    ctx->r4 = ADD32(ctx->r4, -0X4438);
    // 0x801A6FF4: swc1        $f8, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f8.u32l;
    // 0x801A6FF8: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A6FFC: swc1        $f10, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f10.u32l;
    // 0x801A7000: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A7004: jal         0x80005740
    // 0x801A7008: swc1        $f16, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f16.u32l;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x801A7008: swc1        $f16, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f16.u32l;
    after_17:
    // 0x801A700C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7010: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A7014: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    // 0x801A7018: jal         0x80006970
    // 0x801A701C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_18;
    // 0x801A701C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_18:
    // 0x801A7020: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A7024: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7028: addiu       $a1, $s0, 0x170
    ctx->r5 = ADD32(ctx->r16, 0X170);
    // 0x801A702C: swc1        $f18, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f18.u32l;
    // 0x801A7030: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A7034: swc1        $f4, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f4.u32l;
    // 0x801A7038: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A703C: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x801A7040: jal         0x80006AB8
    // 0x801A7044: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_19;
    // 0x801A7044: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_19:
    // 0x801A7048: lh          $v0, 0x8E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8E);
L_801A704C:
    // 0x801A704C: bgez        $v0, L_801A71A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801A7050: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801A71A4;
    }
    // 0x801A7050: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7054: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A7058: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x801A705C: jal         0x80006970
    // 0x801A7060: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_20;
    // 0x801A7060: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_20:
    // 0x801A7064: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A7068: swc1        $f8, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f8.u32l;
    // 0x801A706C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A7070: swc1        $f10, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f10.u32l;
    // 0x801A7074: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A7078: b           L_801A71A4
    // 0x801A707C: swc1        $f16, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f16.u32l;
        goto L_801A71A4;
    // 0x801A707C: swc1        $f16, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f16.u32l;
L_801A7080:
    // 0x801A7080: lh          $v0, 0x8E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8E);
    // 0x801A7084: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7088: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x801A708C: blez        $v0, L_801A70B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801A7090: nop
    
            goto L_801A70B8;
    }
    // 0x801A7090: nop

    // 0x801A7094: jal         0x80006970
    // 0x801A7098: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3f(rdram, ctx);
        goto after_21;
    // 0x801A7098: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_21:
    // 0x801A709C: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A70A0: lh          $v0, 0x8E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8E);
    // 0x801A70A4: swc1        $f18, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f18.u32l;
    // 0x801A70A8: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A70AC: swc1        $f4, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f4.u32l;
    // 0x801A70B0: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A70B4: swc1        $f6, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f6.u32l;
L_801A70B8:
    // 0x801A70B8: bgez        $v0, L_801A71A4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801A70BC: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801A71A4;
    }
    // 0x801A70BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A70C0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A70C4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x801A70C8: jal         0x80006970
    // 0x801A70CC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_22;
    // 0x801A70CC: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_22:
    // 0x801A70D0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A70D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A70D8: addiu       $a1, $s0, 0x188
    ctx->r5 = ADD32(ctx->r16, 0X188);
    // 0x801A70DC: swc1        $f8, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f8.u32l;
    // 0x801A70E0: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A70E4: swc1        $f10, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f10.u32l;
    // 0x801A70E8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A70EC: swc1        $f16, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f16.u32l;
    // 0x801A70F0: jal         0x80006AB8
    // 0x801A70F4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_23;
    // 0x801A70F4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_23:
    // 0x801A70F8: b           L_801A71A8
    // 0x801A70FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A71A8;
    // 0x801A70FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A7100:
    // 0x801A7100: lh          $t7, 0x8E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X8E);
    // 0x801A7104: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7108: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801A710C: blez        $t7, L_801A7150
    if (SIGNED(ctx->r15) <= 0) {
        // 0x801A7110: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_801A7150;
    }
    // 0x801A7110: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801A7114: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A7118: jal         0x80006970
    // 0x801A711C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_24;
    // 0x801A711C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_24:
    // 0x801A7120: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A7124: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7128: addiu       $a1, $s0, 0x158
    ctx->r5 = ADD32(ctx->r16, 0X158);
    // 0x801A712C: swc1        $f18, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f18.u32l;
    // 0x801A7130: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A7134: swc1        $f4, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f4.u32l;
    // 0x801A7138: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A713C: swc1        $f6, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f6.u32l;
    // 0x801A7140: jal         0x80006AB8
    // 0x801A7144: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_GetYPRAngles(rdram, ctx);
        goto after_25;
    // 0x801A7144: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_25:
    // 0x801A7148: b           L_801A71A8
    // 0x801A714C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A71A8;
    // 0x801A714C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A7150:
    // 0x801A7150: lh          $t9, -0xE68($t9)
    ctx->r25 = MEM_H(ctx->r25, -0XE68);
    // 0x801A7154: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A7158: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A715C: beq         $t9, $at, L_801A7180
    if (ctx->r25 == ctx->r1) {
        // 0x801A7160: addiu       $a1, $sp, 0x40
        ctx->r5 = ADD32(ctx->r29, 0X40);
            goto L_801A7180;
    }
    // 0x801A7160: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x801A7164: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7168: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A716C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x801A7170: jal         0x80006970
    // 0x801A7174: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_26;
    // 0x801A7174: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_26:
    // 0x801A7178: b           L_801A7190
    // 0x801A717C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
        goto L_801A7190;
    // 0x801A717C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
L_801A7180:
    // 0x801A7180: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A7184: jal         0x80006970
    // 0x801A7188: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    Matrix_MultVec3f(rdram, ctx);
        goto after_27;
    // 0x801A7188: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_27:
    // 0x801A718C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
L_801A7190:
    // 0x801A7190: swc1        $f8, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f8.u32l;
    // 0x801A7194: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A7198: swc1        $f10, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f10.u32l;
    // 0x801A719C: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A71A0: swc1        $f16, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f16.u32l;
L_801A71A4:
    // 0x801A71A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A71A8:
    // 0x801A71A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801A71AC: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x801A71B0: jr          $ra
    // 0x801A71B4: nop

    return;
    // 0x801A71B4: nop

;}
RECOMP_FUNC void Zoness_ZoTroika_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191FFC: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x80192000: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80192004: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x80192008: lw          $t6, 0x120($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X120);
    // 0x8019200C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80192010: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80192014: lwc1        $f0, 0x110($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X110);
    // 0x80192018: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019201C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80192020: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80192024: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80192028: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019202C: jal         0x80005C34
    // 0x80192030: nop

    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x80192030: nop

    after_0:
    // 0x80192034: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x80192038: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019203C: addiu       $a0, $a0, -0x6A14
    ctx->r4 = ADD32(ctx->r4, -0X6A14);
    // 0x80192040: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80192044: jal         0x8009AA20
    // 0x80192048: lh          $a1, 0xB6($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XB6);
    Animation_GetFrameData(rdram, ctx);
        goto after_1;
    // 0x80192048: lh          $a1, 0xB6($t8)
    ctx->r5 = MEM_H(ctx->r24, 0XB6);
    after_1:
    // 0x8019204C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80192050: lw          $t1, -0x4438($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4438);
    // 0x80192054: lw          $t0, 0x120($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X120);
    // 0x80192058: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8019205C: addiu       $t9, $t9, 0x1E94
    ctx->r25 = ADD32(ctx->r25, 0X1E94);
    // 0x80192060: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x80192064: addiu       $a1, $a1, -0x68C8
    ctx->r5 = ADD32(ctx->r5, -0X68C8);
    // 0x80192068: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8019206C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80192070: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x80192074: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80192078: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8019207C: jal         0x8009A72C
    // 0x80192080: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x80192080: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_2:
    // 0x80192084: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80192088: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    // 0x8019208C: jr          $ra
    // 0x80192090: nop

    return;
    // 0x80192090: nop

;}
RECOMP_FUNC void Solar_801A0D90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0D90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A0D94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A0D98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801A0D9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801A0DA0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801A0DA4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A0DA8: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x801A0DAC: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x801A0DB0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_801A0DB4:
    // 0x801A0DB4: bnel        $t6, $zero, L_801A0DE0
    if (ctx->r14 != 0) {
        // 0x801A0DB8: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_801A0DE0;
    }
    goto skip_0;
    // 0x801A0DB8: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_0:
    // 0x801A0DBC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x801A0DC0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801A0DC4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801A0DC8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x801A0DCC: jal         0x801A0CEC
    // 0x801A0DD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    Solar_801A0CEC(rdram, ctx);
        goto after_0;
    // 0x801A0DD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x801A0DD4: b           L_801A0DEC
    // 0x801A0DD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801A0DEC;
    // 0x801A0DD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A0DDC: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_801A0DE0:
    // 0x801A0DE0: bnel        $a0, $v0, L_801A0DB4
    if (ctx->r4 != ctx->r2) {
        // 0x801A0DE4: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_801A0DB4;
    }
    goto skip_1;
    // 0x801A0DE4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x801A0DE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801A0DEC:
    // 0x801A0DEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A0DF0: jr          $ra
    // 0x801A0DF4: nop

    return;
    // 0x801A0DF4: nop

;}
RECOMP_FUNC void Area6_8018D3CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D3CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D3D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018D3D4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D3D8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018D3DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8018D3E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8018D3E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8018D3E8: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8018D3EC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018D3F0: addiu       $v0, $v0, 0x44B0
    ctx->r2 = ADD32(ctx->r2, 0X44B0);
    // 0x8018D3F4: addiu       $s0, $s0, 0x4050
    ctx->r16 = ADD32(ctx->r16, 0X4050);
    // 0x8018D3F8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_8018D3FC:
    // 0x8018D3FC: bnel        $t6, $zero, L_8018D4C4
    if (ctx->r14 != 0) {
        // 0x8018D400: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_8018D4C4;
    }
    goto skip_0;
    // 0x8018D400: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    skip_0:
    // 0x8018D404: jal         0x80035E48
    // 0x8018D408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018D408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018D40C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018D410: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D414: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D418: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018D41C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018D420: swc1        $f4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f4.u32l;
    // 0x8018D424: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8018D428: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018D42C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D430: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8018D434: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D438: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8018D43C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8018D440: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8018D444: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D448: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x8018D44C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8018D450: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018D454: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8018D458: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8018D45C: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8018D460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8018D464: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018D468: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D46C: addiu       $t8, $zero, 0x96
    ctx->r24 = ADD32(0, 0X96);
    // 0x8018D470: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8018D474: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8018D478: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x8018D47C: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8018D480: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8018D484: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x8018D488: sw          $t7, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r15;
    // 0x8018D48C: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x8018D490: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x8018D494: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
    // 0x8018D498: sw          $t9, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r25;
    // 0x8018D49C: ori         $a0, $a0, 0xD
    ctx->r4 = ctx->r4 | 0XD;
    // 0x8018D4A0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8018D4A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018D4A8: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    // 0x8018D4AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018D4B0: jal         0x80019218
    // 0x8018D4B4: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8018D4B4: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8018D4B8: b           L_8018D4D0
    // 0x8018D4BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018D4D0;
    // 0x8018D4BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018D4C0: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
L_8018D4C4:
    // 0x8018D4C4: bnel        $s0, $v0, L_8018D3FC
    if (ctx->r16 != ctx->r2) {
        // 0x8018D4C8: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_8018D3FC;
    }
    goto skip_1;
    // 0x8018D4C8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x8018D4CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018D4D0:
    // 0x8018D4D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D4D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018D4D8: jr          $ra
    // 0x8018D4DC: nop

    return;
    // 0x8018D4DC: nop

;}
RECOMP_FUNC void Zoness_Effect394_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193908: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019390C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80193910: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80193914: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80193918: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019391C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80193920: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80193924: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80193928: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8019392C:
    // 0x8019392C: bnel        $t6, $zero, L_80193958
    if (ctx->r14 != 0) {
        // 0x80193930: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80193958;
    }
    goto skip_0;
    // 0x80193930: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80193934: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80193938: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019393C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80193940: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80193944: jal         0x801937D8
    // 0x80193948: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Zoness_Effect394_Setup(rdram, ctx);
        goto after_0;
    // 0x80193948: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8019394C: b           L_80193964
    // 0x80193950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80193964;
    // 0x80193950: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80193954: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80193958:
    // 0x80193958: bnel        $a0, $v0, L_8019392C
    if (ctx->r4 != ctx->r2) {
        // 0x8019395C: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8019392C;
    }
    goto skip_1;
    // 0x8019395C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80193960: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80193964:
    // 0x80193964: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80193968: jr          $ra
    // 0x8019396C: nop

    return;
    // 0x8019396C: nop

;}
RECOMP_FUNC void Zoness_ZoCraneMagnet_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A1FC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8019A200: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8019A204: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019A208: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8019A20C: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8019A210: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019A214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019A218: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8019A21C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8019A220: sw          $s5, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r21;
    // 0x8019A224: sw          $s4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r20;
    // 0x8019A228: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8019A22C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8019A230: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8019A234: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8019A238: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8019A23C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8019A240: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019A244: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019A248: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019A24C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019A250: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019A254: jal         0x80005C34
    // 0x8019A258: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x8019A258: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x8019A25C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8019A260: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8019A264: jal         0x80006EB8
    // 0x8019A268: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8019A268: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_1:
    // 0x8019A26C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8019A270: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019A274: lw          $t8, -0x7C24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7C24);
    // 0x8019A278: lw          $t7, -0x7C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C28);
    // 0x8019A27C: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x8019A280: lui         $s4, 0x8018
    ctx->r20 = S32(0X8018 << 16);
    // 0x8019A284: addiu       $s4, $s4, -0x7CD8
    ctx->r20 = ADD32(ctx->r20, -0X7CD8);
    // 0x8019A288: addiu       $s1, $s1, -0x7CE0
    ctx->r17 = ADD32(ctx->r17, -0X7CE0);
    // 0x8019A28C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8019A290: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8019A294: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8019A298: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8019A29C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019A2A0: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8019A2A4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8019A2A8: jal         0x800B9EB0
    // 0x8019A2AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    RCP_SetupDL_57(rdram, ctx);
        goto after_2;
    // 0x8019A2AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_2:
    // 0x8019A2B0: lui         $s5, 0x600
    ctx->r21 = S32(0X600 << 16);
    // 0x8019A2B4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019A2B8: lui         $t0, 0x602
    ctx->r8 = S32(0X602 << 16);
    // 0x8019A2BC: addiu       $t0, $t0, -0x3A70
    ctx->r8 = ADD32(ctx->r8, -0X3A70);
    // 0x8019A2C0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8019A2C4: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x8019A2C8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8019A2CC: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8019A2D0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8019A2D4: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8019A2D8: lw          $t2, -0x7C24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C24);
    // 0x8019A2DC: lw          $t1, -0x7C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7C28);
    // 0x8019A2E0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8019A2E4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8019A2E8: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8019A2EC: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8019A2F0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8019A2F4: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8019A2F8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019A2FC: jal         0x800B9B38
    // 0x8019A300: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    RCP_SetupDL_60(rdram, ctx);
        goto after_3;
    // 0x8019A300: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    after_3:
    // 0x8019A304: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019A308: lui         $t4, 0xB600
    ctx->r12 = S32(0XB600 << 16);
    // 0x8019A30C: addiu       $t5, $zero, 0x2000
    ctx->r13 = ADD32(0, 0X2000);
    // 0x8019A310: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8019A314: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x8019A318: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8019A31C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8019A320: lh          $a0, 0xB8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0XB8);
    // 0x8019A324: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019A328: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019A32C: bne         $a0, $at, L_8019A340
    if (ctx->r4 != ctx->r1) {
        // 0x8019A330: nop
    
            goto L_8019A340;
    }
    // 0x8019A330: nop

    // 0x8019A334: lh          $t6, -0xE9E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0XE9E);
    // 0x8019A338: bne         $t6, $zero, L_8019A344
    if (ctx->r14 != 0) {
        // 0x8019A33C: nop
    
            goto L_8019A344;
    }
    // 0x8019A33C: nop

L_8019A340:
    // 0x8019A340: bne         $a0, $zero, L_8019A374
    if (ctx->r4 != 0) {
        // 0x8019A344: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8019A374;
    }
L_8019A344:
    // 0x8019A344: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019A348: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8019A34C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A350: lwc1        $f8, 0x1224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1224);
    // 0x8019A354: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8019A358: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019A35C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019A360: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019A364: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019A368: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8019A36C: jal         0x80005E90
    // 0x8019A370: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8019A370: nop

    after_4:
L_8019A374:
    // 0x8019A374: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8019A378: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A37C: lwc1        $f12, 0x114($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019A380: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A384: lwc1        $f4, 0x25DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X25DC);
    // 0x8019A388: mul.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8019A38C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019A390: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8019A394: lui         $at, 0x42EA
    ctx->r1 = S32(0X42EA << 16);
    // 0x8019A398: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8019A39C: lui         $s4, 0x602
    ctx->r20 = S32(0X602 << 16);
    // 0x8019A3A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019A3A4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019A3A8: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x8019A3AC: nop

    // 0x8019A3B0: bc1fl       L_8019A3DC
    if (!c1cs) {
        // 0x8019A3B4: slti        $at, $s1, 0x1F
        ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
            goto L_8019A3DC;
    }
    goto skip_0;
    // 0x8019A3B4: slti        $at, $s1, 0x1F
    ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
    skip_0:
    // 0x8019A3B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019A3BC: nop

    // 0x8019A3C0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8019A3C4:
    // 0x8019A3C4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8019A3C8: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x8019A3CC: nop

    // 0x8019A3D0: bc1tl       L_8019A3C4
    if (c1cs) {
        // 0x8019A3D4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8019A3C4;
    }
    goto skip_1;
    // 0x8019A3D4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x8019A3D8: slti        $at, $s1, 0x1F
    ctx->r1 = SIGNED(ctx->r17) < 0X1F ? 1 : 0;
L_8019A3DC:
    // 0x8019A3DC: bne         $at, $zero, L_8019A3E8
    if (ctx->r1 != 0) {
        // 0x8019A3E0: nop
    
            goto L_8019A3E8;
    }
    // 0x8019A3E0: nop

    // 0x8019A3E4: addiu       $s1, $zero, 0x1E
    ctx->r17 = ADD32(0, 0X1E);
L_8019A3E8:
    // 0x8019A3E8: blez        $s1, L_8019A408
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8019A3EC: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_8019A408;
    }
    // 0x8019A3EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A3F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019A3F4: nop

    // 0x8019A3F8: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x8019A3FC: nop

    // 0x8019A400: bc1f        L_8019A40C
    if (!c1cs) {
        // 0x8019A404: nop
    
            goto L_8019A40C;
    }
    // 0x8019A404: nop

L_8019A408:
    // 0x8019A408: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_8019A40C:
    // 0x8019A40C: blez        $s1, L_8019A4AC
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8019A410: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8019A4AC;
    }
    // 0x8019A410: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019A414: lwc1        $f26, 0x1228($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X1228);
    // 0x8019A418: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019A41C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019A420: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8019A424: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019A428: addiu       $s4, $s4, -0x79A0
    ctx->r20 = ADD32(ctx->r20, -0X79A0);
    // 0x8019A42C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
L_8019A430:
    // 0x8019A430: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8019A434: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8019A438: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019A43C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019A440: jal         0x80005B00
    // 0x8019A444: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x8019A444: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_5:
    // 0x8019A448: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8019A44C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019A450: jal         0x80005E90
    // 0x8019A454: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8019A454: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x8019A458: jal         0x80005708
    // 0x8019A45C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_7;
    // 0x8019A45C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_7:
    // 0x8019A460: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8019A464: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8019A468: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8019A46C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8019A470: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8019A474: jal         0x80005C34
    // 0x8019A478: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x8019A478: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_8:
    // 0x8019A47C: jal         0x80006EB8
    // 0x8019A480: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x8019A480: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_9:
    // 0x8019A484: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8019A488: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8019A48C: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x8019A490: sw          $s4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r20;
    // 0x8019A494: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x8019A498: jal         0x80005740
    // 0x8019A49C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x8019A49C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x8019A4A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019A4A4: bnel        $s0, $s1, L_8019A430
    if (ctx->r16 != ctx->r17) {
        // 0x8019A4A8: mfc1        $a1, $f22
        ctx->r5 = (int32_t)ctx->f22.u32l;
            goto L_8019A430;
    }
    goto skip_2;
    // 0x8019A4A8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    skip_2:
L_8019A4AC:
    // 0x8019A4AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8019A4B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8019A4B4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8019A4B8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8019A4BC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8019A4C0: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8019A4C4: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8019A4C8: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x8019A4CC: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x8019A4D0: lw          $s4, 0x4C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X4C);
    // 0x8019A4D4: lw          $s5, 0x50($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X50);
    // 0x8019A4D8: jr          $ra
    // 0x8019A4DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8019A4DC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Zoness_ZoSearchLight_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019CBEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019CBF0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019CBF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019CBF8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019CBFC: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8019CC00: addiu       $t6, $zero, 0x7530
    ctx->r14 = ADD32(0, 0X7530);
    // 0x8019CC04: sh          $t6, 0xC2($s0)
    MEM_H(0XC2, ctx->r16) = ctx->r14;
    // 0x8019CC08: beq         $v0, $zero, L_8019CC2C
    if (ctx->r2 == 0) {
        // 0x8019CC0C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8019CC2C;
    }
    // 0x8019CC0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019CC10: beq         $v0, $at, L_8019CC94
    if (ctx->r2 == ctx->r1) {
        // 0x8019CC14: addiu       $a0, $s0, 0x12C
        ctx->r4 = ADD32(ctx->r16, 0X12C);
            goto L_8019CC94;
    }
    // 0x8019CC14: addiu       $a0, $s0, 0x12C
    ctx->r4 = ADD32(ctx->r16, 0X12C);
    // 0x8019CC18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019CC1C: beq         $v0, $at, L_8019CDB8
    if (ctx->r2 == ctx->r1) {
        // 0x8019CC20: addiu       $a0, $s0, 0x118
        ctx->r4 = ADD32(ctx->r16, 0X118);
            goto L_8019CDB8;
    }
    // 0x8019CC20: addiu       $a0, $s0, 0x118
    ctx->r4 = ADD32(ctx->r16, 0X118);
    // 0x8019CC24: b           L_8019CE34
    // 0x8019CC28: nop

        goto L_8019CE34;
    // 0x8019CC28: nop

L_8019CC2C:
    // 0x8019CC2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019CC30: addiu       $v0, $v0, 0x7DB0
    ctx->r2 = ADD32(ctx->r2, 0X7DB0);
    // 0x8019CC34: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8019CC38: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC3C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8019CC40: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8019CC44: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8019CC48: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8019CC4C: lwc1        $f4, -0x734($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X734);
    // 0x8019CC50: swc1        $f4, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f4.u32l;
    // 0x8019CC54: lbu         $t0, 0x1684($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1684);
    // 0x8019CC58: beql        $t0, $zero, L_8019CC88
    if (ctx->r8 == 0) {
        // 0x8019CC5C: lh          $t5, 0xB8($s0)
        ctx->r13 = MEM_H(ctx->r16, 0XB8);
            goto L_8019CC88;
    }
    goto skip_0;
    // 0x8019CC5C: lh          $t5, 0xB8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB8);
    skip_0:
    // 0x8019CC60: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8019CC64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC68: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019CC6C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x8019CC70: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8019CC74: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8019CC78: lwc1        $f6, -0x73C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73C);
    // 0x8019CC7C: sw          $t4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r12;
    // 0x8019CC80: swc1        $f6, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f6.u32l;
    // 0x8019CC84: lh          $t5, 0xB8($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XB8);
L_8019CC88:
    // 0x8019CC88: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8019CC8C: b           L_8019CE34
    // 0x8019CC90: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
        goto L_8019CE34;
    // 0x8019CC90: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
L_8019CC94:
    // 0x8019CC94: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CC98: lwc1        $f8, 0x12B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X12B0);
    // 0x8019CC9C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019CCA0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019CCA4: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8019CCA8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019CCAC: jal         0x8009BC2C
    // 0x8019CCB0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8019CCB0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8019CCB4: lw          $t7, 0x50($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X50);
    // 0x8019CCB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CCBC: lwc1        $f0, 0x12B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X12B4);
    // 0x8019CCC0: bne         $t7, $zero, L_8019CCF0
    if (ctx->r15 != 0) {
        // 0x8019CCC4: addiu       $a0, $s0, 0x124
        ctx->r4 = ADD32(ctx->r16, 0X124);
            goto L_8019CCF0;
    }
    // 0x8019CCC4: addiu       $a0, $s0, 0x124
    ctx->r4 = ADD32(ctx->r16, 0X124);
    // 0x8019CCC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CCCC: lwc1        $f10, 0x12B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X12B8);
    // 0x8019CCD0: lw          $a1, 0x128($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X128);
    // 0x8019CCD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019CCD8: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8019CCDC: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8019CCE0: jal         0x8009BD38
    // 0x8019CCE4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_1;
    // 0x8019CCE4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8019CCE8: b           L_8019CD0C
    // 0x8019CCEC: nop

        goto L_8019CD0C;
    // 0x8019CCEC: nop

L_8019CCF0:
    // 0x8019CCF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CCF4: lwc1        $f16, 0x12BC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X12BC);
    // 0x8019CCF8: lw          $a1, 0x128($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X128);
    // 0x8019CCFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019CD00: lw          $a3, 0x12C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X12C);
    // 0x8019CD04: jal         0x8009BD38
    // 0x8019CD08: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_2;
    // 0x8019CD08: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
L_8019CD0C:
    // 0x8019CD0C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8019CD10: lbu         $t8, 0x1684($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X1684);
    // 0x8019CD14: beql        $t8, $zero, L_8019CD6C
    if (ctx->r24 == 0) {
        // 0x8019CD18: lhu         $t1, 0xBC($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0XBC);
            goto L_8019CD6C;
    }
    goto skip_1;
    // 0x8019CD18: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    skip_1:
    // 0x8019CD1C: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x8019CD20: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019CD24: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8019CD28: bnel        $t9, $zero, L_8019CD6C
    if (ctx->r25 != 0) {
        // 0x8019CD2C: lhu         $t1, 0xBC($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0XBC);
            goto L_8019CD6C;
    }
    goto skip_2;
    // 0x8019CD2C: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    skip_2:
    // 0x8019CD30: lwc1        $f18, 0x128($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X128);
    // 0x8019CD34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019CD38: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CD3C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8019CD40: nop

    // 0x8019CD44: bc1f        L_8019CD5C
    if (!c1cs) {
        // 0x8019CD48: nop
    
            goto L_8019CD5C;
    }
    // 0x8019CD48: nop

    // 0x8019CD4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CD50: lwc1        $f6, -0x73C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X73C);
    // 0x8019CD54: b           L_8019CD64
    // 0x8019CD58: swc1        $f6, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f6.u32l;
        goto L_8019CD64;
    // 0x8019CD58: swc1        $f6, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f6.u32l;
L_8019CD5C:
    // 0x8019CD5C: lwc1        $f8, -0x738($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X738);
    // 0x8019CD60: swc1        $f8, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f8.u32l;
L_8019CD64:
    // 0x8019CD64: sw          $t0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r8;
    // 0x8019CD68: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
L_8019CD6C:
    // 0x8019CD6C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019CD70: bnel        $t1, $zero, L_8019CD9C
    if (ctx->r9 != 0) {
        // 0x8019CD74: lw          $t3, 0x50($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X50);
            goto L_8019CD9C;
    }
    goto skip_3;
    // 0x8019CD74: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
    skip_3:
    // 0x8019CD78: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019CD7C: lwc1        $f16, 0x128($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X128);
    // 0x8019CD80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019CD84: addiu       $t2, $zero, 0x2D
    ctx->r10 = ADD32(0, 0X2D);
    // 0x8019CD88: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019CD8C: sh          $t2, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r10;
    // 0x8019CD90: swc1        $f4, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = ctx->f4.u32l;
    // 0x8019CD94: swc1        $f18, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f18.u32l;
    // 0x8019CD98: lw          $t3, 0x50($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X50);
L_8019CD9C:
    // 0x8019CD9C: addiu       $at, $zero, 0x309
    ctx->r1 = ADD32(0, 0X309);
    // 0x8019CDA0: bne         $t3, $at, L_8019CE34
    if (ctx->r11 != ctx->r1) {
        // 0x8019CDA4: nop
    
            goto L_8019CE34;
    }
    // 0x8019CDA4: nop

    // 0x8019CDA8: lh          $t4, 0xB8($s0)
    ctx->r12 = MEM_H(ctx->r16, 0XB8);
    // 0x8019CDAC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8019CDB0: b           L_8019CE34
    // 0x8019CDB4: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
        goto L_8019CE34;
    // 0x8019CDB4: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
L_8019CDB8:
    // 0x8019CDB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CDBC: lwc1        $f6, 0x12C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12C0);
    // 0x8019CDC0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019CDC4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019CDC8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019CDCC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019CDD0: jal         0x8009BC2C
    // 0x8019CDD4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8019CDD4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8019CDD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CDDC: lwc1        $f10, 0x12C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X12C4);
    // 0x8019CDE0: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8019CDE4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019CDE8: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x8019CDEC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8019CDF0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019CDF4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8019CDF8: bc1f        L_8019CE34
    if (!c1cs) {
        // 0x8019CDFC: nop
    
            goto L_8019CE34;
    }
    // 0x8019CDFC: nop

    // 0x8019CE00: lwc1        $f16, 0x12C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X12C8);
    // 0x8019CE04: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019CE08: jal         0x8009BC2C
    // 0x8019CE0C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8019CE0C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8019CE10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019CE14: lwc1        $f4, 0x11C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8019CE18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019CE1C: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8019CE20: nop

    // 0x8019CE24: bc1f        L_8019CE34
    if (!c1cs) {
        // 0x8019CE28: nop
    
            goto L_8019CE34;
    }
    // 0x8019CE28: nop

    // 0x8019CE2C: jal         0x80060FBC
    // 0x8019CE30: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8019CE30: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_5:
L_8019CE34:
    // 0x8019CE34: jal         0x8018FF50
    // 0x8019CE38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Zoness_8018FF50(rdram, ctx);
        goto after_6;
    // 0x8019CE38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8019CE3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019CE40: nop

    // 0x8019CE44: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8019CE48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019CE4C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019CE50: jr          $ra
    // 0x8019CE54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8019CE54: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Aquas_AqBacoonMuscle_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AE3D8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801AE3DC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801AE3E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801AE3E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801AE3E8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801AE3EC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801AE3F0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801AE3F4: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
    // 0x801AE3F8: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x801AE3FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE400: beq         $v0, $zero, L_801AE430
    if (ctx->r2 == 0) {
        // 0x801AE404: addiu       $s2, $s2, -0xEF0
        ctx->r18 = ADD32(ctx->r18, -0XEF0);
            goto L_801AE430;
    }
    // 0x801AE404: addiu       $s2, $s2, -0xEF0
    ctx->r18 = ADD32(ctx->r18, -0XEF0);
    // 0x801AE408: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801AE40C: beq         $v0, $at, L_801AE7AC
    if (ctx->r2 == ctx->r1) {
        // 0x801AE410: lui         $t0, 0x8017
        ctx->r8 = S32(0X8017 << 16);
            goto L_801AE7AC;
    }
    // 0x801AE410: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801AE414: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801AE418: beq         $v0, $at, L_801AE8A0
    if (ctx->r2 == ctx->r1) {
        // 0x801AE41C: addiu       $s0, $zero, 0x3
        ctx->r16 = ADD32(0, 0X3);
            goto L_801AE8A0;
    }
    // 0x801AE41C: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x801AE420: beql        $v0, $s0, L_801AE94C
    if (ctx->r2 == ctx->r16) {
        // 0x801AE424: lhu         $t1, 0xBC($s1)
        ctx->r9 = MEM_HU(ctx->r17, 0XBC);
            goto L_801AE94C;
    }
    goto skip_0;
    // 0x801AE424: lhu         $t1, 0xBC($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XBC);
    skip_0:
    // 0x801AE428: b           L_801AEB2C
    // 0x801AE42C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_801AEB2C;
    // 0x801AE42C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801AE430:
    // 0x801AE430: lwc1        $f12, 0x1C0C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1C0C);
    // 0x801AE434: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE438: lwc1        $f14, 0x1C10($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X1C10);
    // 0x801AE43C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE440: lwc1        $f4, 0x4330($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4330);
    // 0x801AE444: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801AE448: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AE44C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE450: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AE454: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801AE458: add.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x801AE45C: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x801AE460: swc1        $f2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f2.u32l;
    // 0x801AE464: bc1fl       L_801AE474
    if (!c1cs) {
        // 0x801AE468: lwc1        $f8, 0x8($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
            goto L_801AE474;
    }
    goto skip_1;
    // 0x801AE468: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    skip_1:
    // 0x801AE46C: swc1        $f14, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f14.u32l;
    // 0x801AE470: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
L_801AE474:
    // 0x801AE474: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x801AE478: nop

    // 0x801AE47C: bc1f        L_801AE488
    if (!c1cs) {
        // 0x801AE480: nop
    
            goto L_801AE488;
    }
    // 0x801AE480: nop

    // 0x801AE484: swc1        $f12, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f12.u32l;
L_801AE488:
    // 0x801AE488: lwc1        $f12, 0x1C14($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X1C14);
    // 0x801AE48C: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x801AE490: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801AE494: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AE498: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801AE49C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE4A0: lwc1        $f10, 0x4330($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4330);
    // 0x801AE4A4: lui         $at, 0x42E8
    ctx->r1 = S32(0X42E8 << 16);
    // 0x801AE4A8: div.s       $f0, $f10, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x801AE4AC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801AE4B0: add.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x801AE4B4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x801AE4B8: swc1        $f2, 0x110($s1)
    MEM_W(0X110, ctx->r17) = ctx->f2.u32l;
    // 0x801AE4BC: bc1fl       L_801AE4CC
    if (!c1cs) {
        // 0x801AE4C0: lwc1        $f16, 0x110($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X110);
            goto L_801AE4CC;
    }
    goto skip_2;
    // 0x801AE4C0: lwc1        $f16, 0x110($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X110);
    skip_2:
    // 0x801AE4C4: swc1        $f12, 0x110($s1)
    MEM_W(0X110, ctx->r17) = ctx->f12.u32l;
    // 0x801AE4C8: lwc1        $f16, 0x110($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X110);
L_801AE4CC:
    // 0x801AE4CC: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x801AE4D0: nop

    // 0x801AE4D4: bc1fl       L_801AE4E4
    if (!c1cs) {
        // 0x801AE4D8: lh          $t6, 0x52($s2)
        ctx->r14 = MEM_H(ctx->r18, 0X52);
            goto L_801AE4E4;
    }
    goto skip_3;
    // 0x801AE4D8: lh          $t6, 0x52($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X52);
    skip_3:
    // 0x801AE4DC: swc1        $f20, 0x110($s1)
    MEM_W(0X110, ctx->r17) = ctx->f20.u32l;
    // 0x801AE4E0: lh          $t6, 0x52($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X52);
L_801AE4E4:
    // 0x801AE4E4: bnel        $t6, $zero, L_801AE514
    if (ctx->r14 != 0) {
        // 0x801AE4E8: lb          $t7, 0xD0($s1)
        ctx->r15 = MEM_B(ctx->r17, 0XD0);
            goto L_801AE514;
    }
    goto skip_4;
    // 0x801AE4E8: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
    skip_4:
    // 0x801AE4EC: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x801AE4F0: sh          $zero, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = 0;
    // 0x801AE4F4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801AE4F8: lwc1        $f18, 0x28($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X28);
    // 0x801AE4FC: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x801AE500: nop

    // 0x801AE504: bc1tl       L_801AE514
    if (c1cs) {
        // 0x801AE508: lb          $t7, 0xD0($s1)
        ctx->r15 = MEM_B(ctx->r17, 0XD0);
            goto L_801AE514;
    }
    goto skip_5;
    // 0x801AE508: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
    skip_5:
    // 0x801AE50C: swc1        $f0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f0.u32l;
    // 0x801AE510: lb          $t7, 0xD0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XD0);
L_801AE514:
    // 0x801AE514: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE518: beql        $t7, $zero, L_801AEB2C
    if (ctx->r15 == 0) {
        // 0x801AE51C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AEB2C;
    }
    goto skip_6;
    // 0x801AE51C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_6:
    // 0x801AE520: sb          $zero, 0xD0($s1)
    MEM_B(0XD0, ctx->r17) = 0;
    // 0x801AE524: lwc1        $f0, 0x4330($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4330);
    // 0x801AE528: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801AE52C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AE530: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801AE534: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x801AE538: nop

    // 0x801AE53C: bc1fl       L_801AEB2C
    if (!c1cs) {
        // 0x801AE540: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AEB2C;
    }
    goto skip_7;
    // 0x801AE540: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x801AE544: lh          $t8, 0x4E($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X4E);
    // 0x801AE548: slti        $at, $t8, 0xA
    ctx->r1 = SIGNED(ctx->r24) < 0XA ? 1 : 0;
    // 0x801AE54C: bnel        $at, $zero, L_801AEB2C
    if (ctx->r1 != 0) {
        // 0x801AE550: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AEB2C;
    }
    goto skip_8;
    // 0x801AE550: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_8:
    // 0x801AE554: lh          $t9, 0x88($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X88);
    // 0x801AE558: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AE55C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AE560: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x801AE564: beq         $at, $zero, L_801AEB28
    if (ctx->r1 == 0) {
        // 0x801AE568: addiu       $t0, $zero, 0x1E
        ctx->r8 = ADD32(0, 0X1E);
            goto L_801AEB28;
    }
    // 0x801AE568: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x801AE56C: sh          $t0, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r8;
    // 0x801AE570: sw          $zero, 0x54($s1)
    MEM_W(0X54, ctx->r17) = 0;
    // 0x801AE574: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE578: lwc1        $f6, 0x4444($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4444);
    // 0x801AE57C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801AE580: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AE584: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x801AE588: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE58C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801AE590: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x801AE594: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801AE598: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    // 0x801AE59C: swc1        $f10, 0x4444($at)
    MEM_W(0X4444, ctx->r1) = ctx->f10.u32l;
    // 0x801AE5A0: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x801AE5A4: ori         $a0, $a0, 0x6050
    ctx->r4 = ctx->r4 | 0X6050;
    // 0x801AE5A8: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x801AE5AC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AE5B0: jal         0x80019218
    // 0x801AE5B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x801AE5B4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x801AE5B8: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x801AE5BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801AE5C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE5C4: lwc1        $f16, 0x4444($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4444);
    // 0x801AE5C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE5CC: c.le.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl <= ctx->f14.fl;
    // 0x801AE5D0: nop

    // 0x801AE5D4: bc1fl       L_801AE5E4
    if (!c1cs) {
        // 0x801AE5D8: lui         $at, 0xC1B8
        ctx->r1 = S32(0XC1B8 << 16);
            goto L_801AE5E4;
    }
    goto skip_9;
    // 0x801AE5D8: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    skip_9:
    // 0x801AE5DC: swc1        $f14, 0x4444($at)
    MEM_W(0X4444, ctx->r1) = ctx->f14.u32l;
    // 0x801AE5E0: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
L_801AE5E4:
    // 0x801AE5E4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AE5E8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE5EC: lwc1        $f4, 0x4330($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4330);
    // 0x801AE5F0: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x801AE5F4: nop

    // 0x801AE5F8: bc1fl       L_801AEB2C
    if (!c1cs) {
        // 0x801AE5FC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AEB2C;
    }
    goto skip_10;
    // 0x801AE5FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_10:
    // 0x801AE600: lh          $t2, 0x52($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X52);
    // 0x801AE604: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801AE608: addiu       $t3, $zero, 0x48
    ctx->r11 = ADD32(0, 0X48);
    // 0x801AE60C: bne         $t2, $zero, L_801AE6C0
    if (ctx->r10 != 0) {
        // 0x801AE610: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_801AE6C0;
    }
    // 0x801AE610: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801AE614: sh          $t3, 0x52($s2)
    MEM_H(0X52, ctx->r18) = ctx->r11;
    // 0x801AE618: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801AE61C: sh          $a0, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r4;
    // 0x801AE620: addiu       $a1, $a1, -0xEF0
    ctx->r5 = ADD32(ctx->r5, -0XEF0);
    // 0x801AE624: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x801AE628: addiu       $v1, $zero, 0x100
    ctx->r3 = ADD32(0, 0X100);
    // 0x801AE62C: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
L_801AE630:
    // 0x801AE630: bnel        $v1, $t4, L_801AE650
    if (ctx->r3 != ctx->r12) {
        // 0x801AE634: lhu         $t7, 0x2F6($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X2F6);
            goto L_801AE650;
    }
    goto skip_11;
    // 0x801AE634: lhu         $t7, 0x2F6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2F6);
    skip_11:
    // 0x801AE638: lw          $t5, 0x40($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X40);
    // 0x801AE63C: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x801AE640: beql        $t5, $t6, L_801AE650
    if (ctx->r13 == ctx->r14) {
        // 0x801AE644: lhu         $t7, 0x2F6($v0)
        ctx->r15 = MEM_HU(ctx->r2, 0X2F6);
            goto L_801AE650;
    }
    goto skip_12;
    // 0x801AE644: lhu         $t7, 0x2F6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2F6);
    skip_12:
    // 0x801AE648: sh          $a0, 0xCE($v0)
    MEM_H(0XCE, ctx->r2) = ctx->r4;
    // 0x801AE64C: lhu         $t7, 0x2F6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2F6);
L_801AE650:
    // 0x801AE650: bnel        $v1, $t7, L_801AE670
    if (ctx->r3 != ctx->r15) {
        // 0x801AE654: lhu         $t0, 0x5EA($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0X5EA);
            goto L_801AE670;
    }
    goto skip_13;
    // 0x801AE654: lhu         $t0, 0x5EA($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X5EA);
    skip_13:
    // 0x801AE658: lw          $t8, 0x40($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X40);
    // 0x801AE65C: lw          $t9, 0x334($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X334);
    // 0x801AE660: beql        $t8, $t9, L_801AE670
    if (ctx->r24 == ctx->r25) {
        // 0x801AE664: lhu         $t0, 0x5EA($v0)
        ctx->r8 = MEM_HU(ctx->r2, 0X5EA);
            goto L_801AE670;
    }
    goto skip_14;
    // 0x801AE664: lhu         $t0, 0x5EA($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X5EA);
    skip_14:
    // 0x801AE668: sh          $a0, 0x3C2($v0)
    MEM_H(0X3C2, ctx->r2) = ctx->r4;
    // 0x801AE66C: lhu         $t0, 0x5EA($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X5EA);
L_801AE670:
    // 0x801AE670: bnel        $v1, $t0, L_801AE690
    if (ctx->r3 != ctx->r8) {
        // 0x801AE674: lhu         $t3, 0x8DE($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X8DE);
            goto L_801AE690;
    }
    goto skip_15;
    // 0x801AE674: lhu         $t3, 0x8DE($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X8DE);
    skip_15:
    // 0x801AE678: lw          $t1, 0x40($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X40);
    // 0x801AE67C: lw          $t2, 0x628($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X628);
    // 0x801AE680: beql        $t1, $t2, L_801AE690
    if (ctx->r9 == ctx->r10) {
        // 0x801AE684: lhu         $t3, 0x8DE($v0)
        ctx->r11 = MEM_HU(ctx->r2, 0X8DE);
            goto L_801AE690;
    }
    goto skip_16;
    // 0x801AE684: lhu         $t3, 0x8DE($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X8DE);
    skip_16:
    // 0x801AE688: sh          $a0, 0x6B6($v0)
    MEM_H(0X6B6, ctx->r2) = ctx->r4;
    // 0x801AE68C: lhu         $t3, 0x8DE($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X8DE);
L_801AE690:
    // 0x801AE690: bnel        $v1, $t3, L_801AE6B0
    if (ctx->r3 != ctx->r11) {
        // 0x801AE694: addiu       $v0, $v0, 0xBD0
        ctx->r2 = ADD32(ctx->r2, 0XBD0);
            goto L_801AE6B0;
    }
    goto skip_17;
    // 0x801AE694: addiu       $v0, $v0, 0xBD0
    ctx->r2 = ADD32(ctx->r2, 0XBD0);
    skip_17:
    // 0x801AE698: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x801AE69C: lw          $t5, 0x91C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X91C);
    // 0x801AE6A0: beql        $t4, $t5, L_801AE6B0
    if (ctx->r12 == ctx->r13) {
        // 0x801AE6A4: addiu       $v0, $v0, 0xBD0
        ctx->r2 = ADD32(ctx->r2, 0XBD0);
            goto L_801AE6B0;
    }
    goto skip_18;
    // 0x801AE6A4: addiu       $v0, $v0, 0xBD0
    ctx->r2 = ADD32(ctx->r2, 0XBD0);
    skip_18:
    // 0x801AE6A8: sh          $a0, 0x9AA($v0)
    MEM_H(0X9AA, ctx->r2) = ctx->r4;
    // 0x801AE6AC: addiu       $v0, $v0, 0xBD0
    ctx->r2 = ADD32(ctx->r2, 0XBD0);
L_801AE6B0:
    // 0x801AE6B0: bnel        $v0, $a1, L_801AE630
    if (ctx->r2 != ctx->r5) {
        // 0x801AE6B4: lhu         $t4, 0x2($v0)
        ctx->r12 = MEM_HU(ctx->r2, 0X2);
            goto L_801AE630;
    }
    goto skip_19;
    // 0x801AE6B4: lhu         $t4, 0x2($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0X2);
    skip_19:
    // 0x801AE6B8: b           L_801AE6CC
    // 0x801AE6BC: lh          $t6, 0x88($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X88);
        goto L_801AE6CC;
    // 0x801AE6BC: lh          $t6, 0x88($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X88);
L_801AE6C0:
    // 0x801AE6C0: sw          $zero, 0x54($s1)
    MEM_W(0X54, ctx->r17) = 0;
    // 0x801AE6C4: sh          $zero, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = 0;
    // 0x801AE6C8: lh          $t6, 0x88($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X88);
L_801AE6CC:
    // 0x801AE6CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801AE6D0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801AE6D4: bnel        $t6, $zero, L_801AE724
    if (ctx->r14 != 0) {
        // 0x801AE6D8: lhu         $v0, 0xD6($s1)
        ctx->r2 = MEM_HU(ctx->r17, 0XD6);
            goto L_801AE724;
    }
    goto skip_20;
    // 0x801AE6D8: lhu         $v0, 0xD6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XD6);
    skip_20:
    // 0x801AE6DC: sh          $t7, 0x88($s2)
    MEM_H(0X88, ctx->r18) = ctx->r15;
    // 0x801AE6E0: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x801AE6E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AE6E8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AE6EC: addiu       $a0, $a0, 0xDB8
    ctx->r4 = ADD32(ctx->r4, 0XDB8);
    // 0x801AE6F0: swc1        $f6, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->f6.u32l;
    // 0x801AE6F4: lw          $v0, 0xAC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XAC);
    // 0x801AE6F8: bnel        $v0, $zero, L_801AE710
    if (ctx->r2 != 0) {
        // 0x801AE6FC: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_801AE710;
    }
    goto skip_21;
    // 0x801AE6FC: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    skip_21:
    // 0x801AE700: jal         0x800BA808
    // 0x801AE704: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x801AE704: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x801AE708: lw          $v0, 0xAC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XAC);
    // 0x801AE70C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
L_801AE710:
    // 0x801AE710: sw          $t9, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r25;
    // 0x801AE714: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x801AE718: b           L_801AEB28
    // 0x801AE71C: sw          $t1, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r9;
        goto L_801AEB28;
    // 0x801AE71C: sw          $t1, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r9;
    // 0x801AE720: lhu         $v0, 0xD6($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0XD6);
L_801AE724:
    // 0x801AE724: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x801AE728: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801AE72C: bnel        $v0, $at, L_801AEB2C
    if (ctx->r2 != ctx->r1) {
        // 0x801AE730: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AEB2C;
    }
    goto skip_22;
    // 0x801AE730: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_22:
    // 0x801AE734: lh          $t2, 0xCE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XCE);
    // 0x801AE738: addiu       $a0, $a0, 0xDEC
    ctx->r4 = ADD32(ctx->r4, 0XDEC);
    // 0x801AE73C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801AE740: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x801AE744: jal         0x800BA808
    // 0x801AE748: sh          $t3, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r11;
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x801AE748: sh          $t3, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = ctx->r11;
    after_2:
    // 0x801AE74C: lh          $t4, 0xCE($s1)
    ctx->r12 = MEM_H(ctx->r17, 0XCE);
    // 0x801AE750: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AE754: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AE758: bgtz        $t4, L_801AEB28
    if (SIGNED(ctx->r12) > 0) {
        // 0x801AE75C: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_801AEB28;
    }
    // 0x801AE75C: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801AE760: sh          $t5, 0x88($s2)
    MEM_H(0X88, ctx->r18) = ctx->r13;
    // 0x801AE764: lwc1        $f8, 0x110($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X110);
    // 0x801AE768: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x801AE76C: sh          $zero, 0xCE($s1)
    MEM_H(0XCE, ctx->r17) = 0;
    // 0x801AE770: sh          $t6, 0xC6($s1)
    MEM_H(0XC6, ctx->r17) = ctx->r14;
    // 0x801AE774: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801AE778: swc1        $f8, 0x11C($s1)
    MEM_W(0X11C, ctx->r17) = ctx->f8.u32l;
    // 0x801AE77C: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x801AE780: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801AE784: ori         $a0, $a0, 0x33
    ctx->r4 = ctx->r4 | 0X33;
    // 0x801AE788: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801AE78C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AE790: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x801AE794: jal         0x80019218
    // 0x801AE798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801AE798: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x801AE79C: lh          $t8, 0xB8($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XB8);
    // 0x801AE7A0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801AE7A4: b           L_801AEB28
    // 0x801AE7A8: sh          $t9, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r25;
        goto L_801AEB28;
    // 0x801AE7A8: sh          $t9, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r25;
L_801AE7AC:
    // 0x801AE7AC: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x801AE7B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE7B4: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x801AE7B8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x801AE7BC: bnel        $t1, $zero, L_801AE868
    if (ctx->r9 != 0) {
        // 0x801AE7C0: lui         $at, 0x43C8
        ctx->r1 = S32(0X43C8 << 16);
            goto L_801AE868;
    }
    goto skip_23;
    // 0x801AE7C0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    skip_23:
    // 0x801AE7C4: lwc1        $f18, 0xEC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x801AE7C8: lwc1        $f10, 0x114($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X114);
    // 0x801AE7CC: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801AE7D0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801AE7D4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801AE7D8: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x801AE7DC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801AE7E0: lwc1        $f20, 0x1C18($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X1C18);
    // 0x801AE7E4: lwc1        $f4, 0xF0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x801AE7E8: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801AE7EC: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801AE7F0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801AE7F4: jal         0x8007C120
    // 0x801AE7F8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_4;
    // 0x801AE7F8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x801AE7FC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801AE800: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AE804: lwc1        $f6, 0x114($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X114);
    // 0x801AE808: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801AE80C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AE810: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801AE814: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801AE818: lwc1        $f8, 0xEC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x801AE81C: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801AE820: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801AE824: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801AE828: lw          $a3, 0xE8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XE8);
    // 0x801AE82C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801AE830: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801AE834: lwc1        $f10, 0xF0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x801AE838: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801AE83C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x801AE840: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801AE844: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801AE848: jal         0x8007C120
    // 0x801AE84C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_5;
    // 0x801AE84C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x801AE850: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801AE854: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AE858: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
    // 0x801AE85C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801AE860: swc1        $f4, 0x114($s1)
    MEM_W(0X114, ctx->r17) = ctx->f4.u32l;
    // 0x801AE864: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
L_801AE868:
    // 0x801AE868: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AE86C: lwc1        $f8, 0x11C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X11C);
    // 0x801AE870: lwc1        $f6, 0x114($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X114);
    // 0x801AE874: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801AE878: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x801AE87C: nop

    // 0x801AE880: bc1fl       L_801AEB2C
    if (!c1cs) {
        // 0x801AE884: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AEB2C;
    }
    goto skip_24;
    // 0x801AE884: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_24:
    // 0x801AE888: lh          $t5, 0xB8($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XB8);
    // 0x801AE88C: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x801AE890: sh          $t4, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r12;
    // 0x801AE894: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x801AE898: b           L_801AEB28
    // 0x801AE89C: sh          $t6, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r14;
        goto L_801AEB28;
    // 0x801AE89C: sh          $t6, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r14;
L_801AE8A0:
    // 0x801AE8A0: lhu         $t7, 0xBC($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0XBC);
    // 0x801AE8A4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801AE8A8: bnel        $t7, $zero, L_801AEB2C
    if (ctx->r15 != 0) {
        // 0x801AE8AC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AEB2C;
    }
    goto skip_25;
    // 0x801AE8AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_25:
    // 0x801AE8B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801AE8B4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801AE8B8: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
L_801AE8BC:
    // 0x801AE8BC: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x801AE8C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AE8C4: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x801AE8C8: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801AE8CC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801AE8D0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801AE8D4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801AE8D8: jal         0x8007B8F8
    // 0x801AE8DC: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    Effect_Effect364_Spawn(rdram, ctx);
        goto after_6;
    // 0x801AE8DC: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    after_6:
    // 0x801AE8E0: lui         $at, 0x43D2
    ctx->r1 = S32(0X43D2 << 16);
    // 0x801AE8E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AE8E8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801AE8EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AE8F0: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801AE8F4: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801AE8F8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801AE8FC: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801AE900: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801AE904: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801AE908: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801AE90C: jal         0x8007B8F8
    // 0x801AE910: nop

    Effect_Effect364_Spawn(rdram, ctx);
        goto after_7;
    // 0x801AE910: nop

    after_7:
    // 0x801AE914: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801AE918: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801AE91C: bnel        $s0, $at, L_801AE8BC
    if (ctx->r16 != ctx->r1) {
        // 0x801AE920: lwc1        $f8, 0xC($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
            goto L_801AE8BC;
    }
    goto skip_26;
    // 0x801AE920: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    skip_26:
    // 0x801AE924: lh          $t9, 0xB8($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XB8);
    // 0x801AE928: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE92C: lwc1        $f10, 0x1C1C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X1C1C);
    // 0x801AE930: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x801AE934: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801AE938: sh          $t8, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r24;
    // 0x801AE93C: sh          $t0, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r8;
    // 0x801AE940: b           L_801AEB28
    // 0x801AE944: swc1        $f10, 0x120($s1)
    MEM_W(0X120, ctx->r17) = ctx->f10.u32l;
        goto L_801AEB28;
    // 0x801AE944: swc1        $f10, 0x120($s1)
    MEM_W(0X120, ctx->r17) = ctx->f10.u32l;
    // 0x801AE948: lhu         $t1, 0xBC($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XBC);
L_801AE94C:
    // 0x801AE94C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE950: addiu       $a0, $s1, 0x120
    ctx->r4 = ADD32(ctx->r17, 0X120);
    // 0x801AE954: bne         $t1, $zero, L_801AEB28
    if (ctx->r9 != 0) {
        // 0x801AE958: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_801AEB28;
    }
    // 0x801AE958: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801AE95C: lwc1        $f20, 0x1C20($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X1C20);
    // 0x801AE960: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801AE964: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801AE968: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801AE96C: jal         0x8009BC2C
    // 0x801AE970: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x801AE970: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x801AE974: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801AE978: lw          $a2, 0x120($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X120);
    // 0x801AE97C: addiu       $a0, $s1, 0x110
    ctx->r4 = ADD32(ctx->r17, 0X110);
    // 0x801AE980: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801AE984: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801AE988: jal         0x8009BC2C
    // 0x801AE98C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x801AE98C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_9:
    // 0x801AE990: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AE994: lwc1        $f18, 0x1C24($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1C24);
    // 0x801AE998: lwc1        $f4, 0x110($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X110);
    // 0x801AE99C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801AE9A0: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x801AE9A4: nop

    // 0x801AE9A8: bc1fl       L_801AEB2C
    if (!c1cs) {
        // 0x801AE9AC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_801AEB2C;
    }
    goto skip_27;
    // 0x801AE9AC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_27:
    // 0x801AE9B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801AE9B4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801AE9B8: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801AE9BC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801AE9C0: jal         0x8007BC7C
    // 0x801AE9C4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_10;
    // 0x801AE9C4: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_10:
    // 0x801AE9C8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801AE9CC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801AE9D0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801AE9D4: jal         0x8007BC7C
    // 0x801AE9D8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_11;
    // 0x801AE9D8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_11:
    // 0x801AE9DC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801AE9E0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801AE9E4: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801AE9E8: jal         0x8007BC7C
    // 0x801AE9EC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect362_Spawn(rdram, ctx);
        goto after_12;
    // 0x801AE9EC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_12:
    // 0x801AE9F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801AE9F4: jal         0x80060FBC
    // 0x801AE9F8: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    Object_Kill(rdram, ctx);
        goto after_13;
    // 0x801AE9F8: addiu       $a1, $s1, 0x100
    ctx->r5 = ADD32(ctx->r17, 0X100);
    after_13:
    // 0x801AE9FC: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801AEA00: addiu       $v0, $v0, 0x42A0
    ctx->r2 = ADD32(ctx->r2, 0X42A0);
    // 0x801AEA04: lw          $t2, 0x5C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X5C);
    // 0x801AEA08: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801AEA0C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801AEA10: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x801AEA14: addiu       $s2, $s2, -0xEF0
    ctx->r18 = ADD32(ctx->r18, -0XEF0);
    // 0x801AEA18: addiu       $v1, $v1, 0x4308
    ctx->r3 = ADD32(ctx->r3, 0X4308);
    // 0x801AEA1C: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x801AEA20: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x801AEA24: sw          $t3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r11;
    // 0x801AEA28: sh          $s0, 0x88($s2)
    MEM_H(0X88, ctx->r18) = ctx->r16;
    // 0x801AEA2C: sh          $t4, 0xAE($s2)
    MEM_H(0XAE, ctx->r18) = ctx->r12;
    // 0x801AEA30: bne         $t3, $zero, L_801AEB08
    if (ctx->r11 != 0) {
        // 0x801AEA34: swc1        $f8, 0x13C($v1)
        MEM_W(0X13C, ctx->r3) = ctx->f8.u32l;
            goto L_801AEB08;
    }
    // 0x801AEA34: swc1        $f8, 0x13C($v1)
    MEM_W(0X13C, ctx->r3) = ctx->f8.u32l;
    // 0x801AEA38: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x801AEA3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AEA40: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AEA44: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801AEA48: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801AEA4C: swc1        $f10, 0x13C($v1)
    MEM_W(0X13C, ctx->r3) = ctx->f10.u32l;
L_801AEA50:
    // 0x801AEA50: jal         0x80004EB0
    // 0x801AEA54: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_14;
    // 0x801AEA54: nop

    after_14:
    // 0x801AEA58: jal         0x80004EB0
    // 0x801AEA5C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x801AEA5C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x801AEA60: jal         0x80004EB0
    // 0x801AEA64: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_16;
    // 0x801AEA64: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_16:
    // 0x801AEA68: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801AEA6C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801AEA70: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801AEA74: sub.s       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x801AEA78: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x801AEA7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AEA80: lwc1        $f8, 0x4($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801AEA84: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x801AEA88: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801AEA8C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801AEA90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AEA94: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801AEA98: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x801AEA9C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801AEAA0: add.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AEAA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AEAA8: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801AEAAC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801AEAB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801AEAB4: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x801AEAB8: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x801AEABC: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AEAC0: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801AEAC4: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801AEAC8: add.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x801AEACC: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x801AEAD0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801AEAD4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801AEAD8: jal         0x801AC8A8
    // 0x801AEADC: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_17;
    // 0x801AEADC: nop

    after_17:
    // 0x801AEAE0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801AEAE4: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x801AEAE8: bne         $s0, $v0, L_801AEA50
    if (ctx->r16 != ctx->r2) {
        // 0x801AEAEC: nop
    
            goto L_801AEA50;
    }
    // 0x801AEAEC: nop

    // 0x801AEAF0: addiu       $t7, $zero, 0xE
    ctx->r15 = ADD32(0, 0XE);
    // 0x801AEAF4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801AEAF8: sh          $zero, 0x52($s2)
    MEM_H(0X52, ctx->r18) = 0;
    // 0x801AEAFC: sh          $v0, 0x56($s2)
    MEM_H(0X56, ctx->r18) = ctx->r2;
    // 0x801AEB00: addiu       $v1, $v1, 0x4308
    ctx->r3 = ADD32(ctx->r3, 0X4308);
    // 0x801AEB04: sh          $t7, 0x4E($s2)
    MEM_H(0X4E, ctx->r18) = ctx->r15;
L_801AEB08:
    // 0x801AEB08: lw          $t8, 0x50($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X50);
    // 0x801AEB0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AEB10: lwc1        $f10, 0x140($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X140);
    // 0x801AEB14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801AEB18: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801AEB1C: lwc1        $f6, -0x458($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X458);
    // 0x801AEB20: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AEB24: swc1        $f4, 0x140($v1)
    MEM_W(0X140, ctx->r3) = ctx->f4.u32l;
L_801AEB28:
    // 0x801AEB28: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_801AEB2C:
    // 0x801AEB2C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801AEB30: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801AEB34: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x801AEB38: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x801AEB3C: jr          $ra
    // 0x801AEB40: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801AEB40: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Area6_8018B9BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018B9BC: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8018B9C0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8018B9C4: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8018B9C8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8018B9CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018B9D0: addiu       $s2, $s2, 0x2250
    ctx->r18 = ADD32(ctx->r18, 0X2250);
    // 0x8018B9D4: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8018B9D8: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8018B9DC: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x8018B9E0: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8018B9E4: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8018B9E8: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8018B9EC: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8018B9F0: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8018B9F4: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8018B9F8: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8018B9FC: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8018BA00: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018BA04: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018BA08: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8018BA0C: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8018BA10: addiu       $s5, $zero, 0x1E
    ctx->r21 = ADD32(0, 0X1E);
    // 0x8018BA14: bne         $t6, $zero, L_8018BC90
    if (ctx->r14 != 0) {
        // 0x8018BA18: addiu       $s1, $s0, 0x1E
        ctx->r17 = ADD32(ctx->r16, 0X1E);
            goto L_8018BC90;
    }
    // 0x8018BA18: addiu       $s1, $s0, 0x1E
    ctx->r17 = ADD32(ctx->r16, 0X1E);
    // 0x8018BA1C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BA20: lwc1        $f28, 0xA84($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0XA84);
    // 0x8018BA24: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018BA28: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018BA2C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018BA30: lwc1        $f24, 0xA88($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0XA88);
    // 0x8018BA34: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018BA38: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018BA3C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018BA40: lui         $fp, 0x8017
    ctx->r30 = S32(0X8017 << 16);
    // 0x8018BA44: lui         $s7, 0x8018
    ctx->r23 = S32(0X8018 << 16);
    // 0x8018BA48: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8018BA4C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018BA50: addiu       $s6, $s6, 0x5D34
    ctx->r22 = ADD32(ctx->r22, 0X5D34);
    // 0x8018BA54: addiu       $s7, $s7, -0x7ED4
    ctx->r23 = ADD32(ctx->r23, -0X7ED4);
    // 0x8018BA58: addiu       $fp, $fp, 0x4050
    ctx->r30 = ADD32(ctx->r30, 0X4050);
L_8018BA5C:
    // 0x8018BA5C: lh          $v0, 0x88($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X88);
    // 0x8018BA60: beql        $v0, $zero, L_8018BC80
    if (ctx->r2 == 0) {
        // 0x8018BA64: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8018BC80;
    }
    goto skip_0;
    // 0x8018BA64: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    skip_0:
    // 0x8018BA68: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8018BA6C: addiu       $s4, $s0, 0x3FC
    ctx->r20 = ADD32(ctx->r16, 0X3FC);
    // 0x8018BA70: beql        $t7, $zero, L_8018BA98
    if (ctx->r15 == 0) {
        // 0x8018BA74: lh          $t2, 0x66($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X66);
            goto L_8018BA98;
    }
    goto skip_1;
    // 0x8018BA74: lh          $t2, 0x66($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X66);
    skip_1:
    // 0x8018BA78: lw          $t8, 0x6F4($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X6F4);
    // 0x8018BA7C: blezl       $t8, L_8018BA98
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8018BA80: lh          $t2, 0x66($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X66);
            goto L_8018BA98;
    }
    goto skip_2;
    // 0x8018BA80: lh          $t2, 0x66($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X66);
    skip_2:
    // 0x8018BA84: lh          $t9, 0x64($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X64);
    // 0x8018BA88: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x8018BA8C: b           L_8018BB00
    // 0x8018BA90: sh          $t0, 0x88($s1)
    MEM_H(0X88, ctx->r17) = ctx->r8;
        goto L_8018BB00;
    // 0x8018BA90: sh          $t0, 0x88($s1)
    MEM_H(0X88, ctx->r17) = ctx->r8;
    // 0x8018BA94: lh          $t2, 0x66($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X66);
L_8018BA98:
    // 0x8018BA98: addiu       $t1, $s3, 0x1
    ctx->r9 = ADD32(ctx->r19, 0X1);
    // 0x8018BA9C: bne         $t1, $t2, L_8018BB00
    if (ctx->r9 != ctx->r10) {
        // 0x8018BAA0: nop
    
            goto L_8018BB00;
    }
    // 0x8018BAA0: nop

    // 0x8018BAA4: lh          $t3, 0x64($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X64);
    // 0x8018BAA8: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x8018BAAC: sh          $t4, 0x88($s1)
    MEM_H(0X88, ctx->r17) = ctx->r12;
    // 0x8018BAB0: lw          $t5, 0x64($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X64);
    // 0x8018BAB4: bne         $t5, $zero, L_8018BB00
    if (ctx->r13 != 0) {
        // 0x8018BAB8: nop
    
            goto L_8018BB00;
    }
    // 0x8018BAB8: nop

    // 0x8018BABC: lh          $t6, 0xBA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XBA);
    // 0x8018BAC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018BAC4: bne         $t6, $at, L_8018BB00
    if (ctx->r14 != ctx->r1) {
        // 0x8018BAC8: nop
    
            goto L_8018BB00;
    }
    // 0x8018BAC8: nop

    // 0x8018BACC: jal         0x80004EB0
    // 0x8018BAD0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8018BAD0: nop

    after_0:
    // 0x8018BAD4: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x8018BAD8: nop

    // 0x8018BADC: bc1f        L_8018BB00
    if (!c1cs) {
        // 0x8018BAE0: nop
    
            goto L_8018BB00;
    }
    // 0x8018BAE0: nop

    // 0x8018BAE4: lw          $t7, 0x28($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X28);
    // 0x8018BAE8: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8018BAEC: sw          $t1, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r9;
    // 0x8018BAF0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8018BAF4: sw          $t8, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r24;
    // 0x8018BAF8: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x8018BAFC: sw          $t0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r8;
L_8018BB00:
    // 0x8018BB00: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8018BB04: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8018BB08: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018BB0C: ori         $a0, $a0, 0x3064
    ctx->r4 = ctx->r4 | 0X3064;
    // 0x8018BB10: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8018BB14: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8018BB18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018BB1C: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    // 0x8018BB20: jal         0x80019218
    // 0x8018BB24: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8018BB24: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    after_1:
    // 0x8018BB28: lh          $t3, 0x88($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X88);
    // 0x8018BB2C: sll         $t4, $s3, 2
    ctx->r12 = S32(ctx->r19 << 2);
    // 0x8018BB30: subu        $t4, $t4, $s3
    ctx->r12 = SUB32(ctx->r12, ctx->r19);
    // 0x8018BB34: bgtz        $t3, L_8018BC04
    if (SIGNED(ctx->r11) > 0) {
        // 0x8018BB38: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8018BC04;
    }
    // 0x8018BB38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018BB3C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018BB40: sh          $zero, 0x88($s1)
    MEM_H(0X88, ctx->r17) = 0;
    // 0x8018BB44: addu        $a1, $s0, $t4
    ctx->r5 = ADD32(ctx->r16, ctx->r12);
    // 0x8018BB48: addiu       $a1, $a1, 0x1AC
    ctx->r5 = ADD32(ctx->r5, 0X1AC);
    // 0x8018BB4C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8018BB50: jal         0x80006970
    // 0x8018BB54: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x8018BB54: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    after_2:
    // 0x8018BB58: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BB5C: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018BB60: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018BB64: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8018BB68: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018BB6C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018BB70: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018BB74: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018BB78: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018BB7C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018BB80: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8018BB84: jal         0x8007D0E0
    // 0x8018BB88: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_3;
    // 0x8018BB88: nop

    after_3:
    // 0x8018BB8C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BB90: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018BB94: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018BB98: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x8018BB9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018BBA0: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8018BBA4: ori         $a1, $a1, 0xB009
    ctx->r5 = ctx->r5 | 0XB009;
    // 0x8018BBA8: addiu       $a0, $sp, 0x88
    ctx->r4 = ADD32(ctx->r29, 0X88);
    // 0x8018BBAC: swc1        $f10, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f10.u32l;
    // 0x8018BBB0: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018BBB4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018BBB8: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
    // 0x8018BBBC: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018BBC0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018BBC4: jal         0x8007A6F0
    // 0x8018BBC8: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_4;
    // 0x8018BBC8: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8018BBCC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018BBD0: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8018BBD4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018BBD8: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8018BBDC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018BBE0: lw          $a3, 0x6C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X6C);
    // 0x8018BBE4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018BBE8: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8018BBEC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018BBF0: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x8018BBF4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8018BBF8: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x8018BBFC: jal         0x8007C120
    // 0x8018BC00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_5;
    // 0x8018BC00: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_5:
L_8018BC04:
    // 0x8018BC04: lh          $t6, 0xA6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA6);
    // 0x8018BC08: bnel        $t6, $zero, L_8018BC80
    if (ctx->r14 != 0) {
        // 0x8018BC0C: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8018BC80;
    }
    goto skip_3;
    // 0x8018BC0C: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    skip_3:
    // 0x8018BC10: lh          $t7, 0xA8($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XA8);
    // 0x8018BC14: bnel        $t7, $zero, L_8018BC80
    if (ctx->r15 != 0) {
        // 0x8018BC18: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8018BC80;
    }
    goto skip_4;
    // 0x8018BC18: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    skip_4:
    // 0x8018BC1C: lh          $t8, 0xAA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XAA);
    // 0x8018BC20: bnel        $t8, $zero, L_8018BC80
    if (ctx->r24 != 0) {
        // 0x8018BC24: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_8018BC80;
    }
    goto skip_5;
    // 0x8018BC24: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
    skip_5:
    // 0x8018BC28: jal         0x8001A500
    // 0x8018BC2C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    Audio_KillSfxBySource(rdram, ctx);
        goto after_6;
    // 0x8018BC2C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_6:
    // 0x8018BC30: lh          $v0, 0xBA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XBA);
    // 0x8018BC34: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x8018BC38: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8018BC3C: beq         $v0, $zero, L_8018BC64
    if (ctx->r2 == 0) {
        // 0x8018BC40: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8018BC64;
    }
    // 0x8018BC40: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8018BC44: sh          $t9, 0xBA($s0)
    MEM_H(0XBA, ctx->r16) = ctx->r25;
    // 0x8018BC48: lh          $v0, 0xBA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XBA);
    // 0x8018BC4C: beq         $v0, $zero, L_8018BC64
    if (ctx->r2 == 0) {
        // 0x8018BC50: nop
    
            goto L_8018BC64;
    }
    // 0x8018BC50: nop

    // 0x8018BC54: lh          $t0, 0x60($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X60);
    // 0x8018BC58: lh          $v0, 0xBA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XBA);
    // 0x8018BC5C: addiu       $t1, $t0, -0x3C
    ctx->r9 = ADD32(ctx->r8, -0X3C);
    // 0x8018BC60: sh          $t1, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r9;
L_8018BC64:
    // 0x8018BC64: beql        $v0, $zero, L_8018BC78
    if (ctx->r2 == 0) {
        // 0x8018BC68: sh          $t3, 0x54($s0)
        MEM_H(0X54, ctx->r16) = ctx->r11;
            goto L_8018BC78;
    }
    goto skip_6;
    // 0x8018BC68: sh          $t3, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r11;
    skip_6:
    // 0x8018BC6C: b           L_8018BC7C
    // 0x8018BC70: sh          $t2, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r10;
        goto L_8018BC7C;
    // 0x8018BC70: sh          $t2, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r10;
    // 0x8018BC74: sh          $t3, 0x54($s0)
    MEM_H(0X54, ctx->r16) = ctx->r11;
L_8018BC78:
    // 0x8018BC78: swc1        $f26, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->f26.u32l;
L_8018BC7C:
    // 0x8018BC7C: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
L_8018BC80:
    // 0x8018BC80: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x8018BC84: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8018BC88: bne         $s5, $at, L_8018BA5C
    if (ctx->r21 != ctx->r1) {
        // 0x8018BC8C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8018BA5C;
    }
    // 0x8018BC8C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8018BC90:
    // 0x8018BC90: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8018BC94: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018BC98: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018BC9C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8018BCA0: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8018BCA4: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8018BCA8: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8018BCAC: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8018BCB0: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8018BCB4: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8018BCB8: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8018BCBC: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8018BCC0: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8018BCC4: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8018BCC8: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8018BCCC: jr          $ra
    // 0x8018BCD0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8018BCD0: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void Aquas_BlueMarine_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ACBB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801ACBB8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801ACBBC: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801ACBC0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801ACBC4: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801ACBC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801ACBCC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801ACBD0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801ACBD4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801ACBD8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801ACBDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801ACBE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801ACBE4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACBE8: jal         0x80005B00
    // 0x801ACBEC: lui         $a3, 0xC220
    ctx->r7 = S32(0XC220 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x801ACBEC: lui         $a3, 0xC220
    ctx->r7 = S32(0XC220 << 16);
    after_0:
    // 0x801ACBF0: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x801ACBF4: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x801ACBF8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACBFC: jal         0x80005E90
    // 0x801ACC00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801ACC00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801ACC04: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801ACC08: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x801ACC0C: jal         0x80006EB8
    // 0x801ACC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x801ACC10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x801ACC14: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ACC18: lui         $t9, 0x300
    ctx->r25 = S32(0X300 << 16);
    // 0x801ACC1C: addiu       $t9, $t9, 0xC70
    ctx->r25 = ADD32(ctx->r25, 0XC70);
    // 0x801ACC20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801ACC24: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801ACC28: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801ACC2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801ACC30: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801ACC34: jal         0x80005708
    // 0x801ACC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x801ACC38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801ACC3C: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x801ACC40: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801ACC44: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801ACC48: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x801ACC4C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACC50: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801ACC54: jal         0x80005B00
    // 0x801ACC58: lui         $a2, 0xC090
    ctx->r6 = S32(0XC090 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x801ACC58: lui         $a2, 0xC090
    ctx->r6 = S32(0XC090 << 16);
    after_4:
    // 0x801ACC5C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801ACC60: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACC64: lwc1        $f6, 0x1B98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1B98);
    // 0x801ACC68: lwc1        $f4, 0x178($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X178);
    // 0x801ACC6C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACC70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801ACC74: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801ACC78: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801ACC7C: jal         0x80005FE0
    // 0x801ACC80: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x801ACC80: nop

    after_5:
    // 0x801ACC84: jal         0x80006EB8
    // 0x801ACC88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x801ACC88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x801ACC8C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ACC90: lui         $t4, 0x300
    ctx->r12 = S32(0X300 << 16);
    // 0x801ACC94: addiu       $t4, $t4, 0x6DE0
    ctx->r12 = ADD32(ctx->r12, 0X6DE0);
    // 0x801ACC98: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801ACC9C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x801ACCA0: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801ACCA4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801ACCA8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801ACCAC: jal         0x80005740
    // 0x801ACCB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x801ACCB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801ACCB4: jal         0x80005708
    // 0x801ACCB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_8;
    // 0x801ACCB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x801ACCBC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801ACCC0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801ACCC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACCC8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x801ACCCC: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x801ACCD0: jal         0x80005B00
    // 0x801ACCD4: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x801ACCD4: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_9:
    // 0x801ACCD8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801ACCDC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACCE0: lwc1        $f18, 0x1B9C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1B9C);
    // 0x801ACCE4: lwc1        $f10, 0x180($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X180);
    // 0x801ACCE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACCEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801ACCF0: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x801ACCF4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801ACCF8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801ACCFC: jal         0x80005E90
    // 0x801ACD00: nop

    Matrix_RotateY(rdram, ctx);
        goto after_10;
    // 0x801ACD00: nop

    after_10:
    // 0x801ACD04: jal         0x80006EB8
    // 0x801ACD08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x801ACD08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x801ACD0C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ACD10: lui         $t9, 0x300
    ctx->r25 = S32(0X300 << 16);
    // 0x801ACD14: addiu       $t9, $t9, 0x6C70
    ctx->r25 = ADD32(ctx->r25, 0X6C70);
    // 0x801ACD18: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801ACD1C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801ACD20: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801ACD24: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801ACD28: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801ACD2C: jal         0x80005740
    // 0x801ACD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x801ACD30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x801ACD34: jal         0x80005708
    // 0x801ACD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_13;
    // 0x801ACD38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x801ACD3C: lui         $a2, 0xC066
    ctx->r6 = S32(0XC066 << 16);
    // 0x801ACD40: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x801ACD44: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801ACD48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801ACD4C: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x801ACD50: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801ACD54: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACD58: jal         0x80005B00
    // 0x801ACD5C: lui         $a1, 0xC198
    ctx->r5 = S32(0XC198 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_14;
    // 0x801ACD5C: lui         $a1, 0xC198
    ctx->r5 = S32(0XC198 << 16);
    after_14:
    // 0x801ACD60: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801ACD64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACD68: lwc1        $f8, 0x1BA0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1BA0);
    // 0x801ACD6C: lwc1        $f6, 0x17C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X17C);
    // 0x801ACD70: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACD74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801ACD78: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801ACD7C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801ACD80: jal         0x80005D44
    // 0x801ACD84: nop

    Matrix_RotateX(rdram, ctx);
        goto after_15;
    // 0x801ACD84: nop

    after_15:
    // 0x801ACD88: jal         0x80006EB8
    // 0x801ACD8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x801ACD8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_16:
    // 0x801ACD90: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ACD94: lui         $t4, 0x300
    ctx->r12 = S32(0X300 << 16);
    // 0x801ACD98: addiu       $t4, $t4, 0xAF0
    ctx->r12 = ADD32(ctx->r12, 0XAF0);
    // 0x801ACD9C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801ACDA0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x801ACDA4: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801ACDA8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801ACDAC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801ACDB0: jal         0x80005740
    // 0x801ACDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x801ACDB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x801ACDB8: jal         0x80005708
    // 0x801ACDBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_18;
    // 0x801ACDBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x801ACDC0: lui         $a2, 0xC066
    ctx->r6 = S32(0XC066 << 16);
    // 0x801ACDC4: lui         $a3, 0x3F99
    ctx->r7 = S32(0X3F99 << 16);
    // 0x801ACDC8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801ACDCC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801ACDD0: ori         $a3, $a3, 0x999A
    ctx->r7 = ctx->r7 | 0X999A;
    // 0x801ACDD4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801ACDD8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACDDC: jal         0x80005B00
    // 0x801ACDE0: lui         $a1, 0x4198
    ctx->r5 = S32(0X4198 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_19;
    // 0x801ACDE0: lui         $a1, 0x4198
    ctx->r5 = S32(0X4198 << 16);
    after_19:
    // 0x801ACDE4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801ACDE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801ACDEC: lwc1        $f18, 0x1BA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1BA4);
    // 0x801ACDF0: lwc1        $f16, 0x17C($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X17C);
    // 0x801ACDF4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801ACDF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801ACDFC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801ACE00: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801ACE04: jal         0x80005D44
    // 0x801ACE08: nop

    Matrix_RotateX(rdram, ctx);
        goto after_20;
    // 0x801ACE08: nop

    after_20:
    // 0x801ACE0C: jal         0x80006EB8
    // 0x801ACE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_21;
    // 0x801ACE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_21:
    // 0x801ACE14: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801ACE18: lui         $t9, 0x300
    ctx->r25 = S32(0X300 << 16);
    // 0x801ACE1C: addiu       $t9, $t9, 0x6AF0
    ctx->r25 = ADD32(ctx->r25, 0X6AF0);
    // 0x801ACE20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801ACE24: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801ACE28: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801ACE2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801ACE30: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801ACE34: jal         0x80005740
    // 0x801ACE38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_22;
    // 0x801ACE38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x801ACE3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801ACE40: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801ACE44: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801ACE48: jr          $ra
    // 0x801ACE4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801ACE4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Area6_8018D5C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D5CC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D5D0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018D5D4: jal         0x800613C4
    // 0x8018D5D8: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018D5D8: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    after_0:
    // 0x8018D5DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D5E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D5E4: sb          $t6, 0x3FE0($at)
    MEM_B(0X3FE0, ctx->r1) = ctx->r14;
    // 0x8018D5E8: lui         $at, 0x44C8
    ctx->r1 = S32(0X44C8 << 16);
    // 0x8018D5EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D5F0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D5F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D5F8: swc1        $f4, 0x3FE4($at)
    MEM_W(0X3FE4, ctx->r1) = ctx->f4.u32l;
    // 0x8018D5FC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018D600: lwc1        $f6, 0xABC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XABC);
    // 0x8018D604: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D608: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018D60C: swc1        $f6, 0x3FE8($at)
    MEM_W(0X3FE8, ctx->r1) = ctx->f6.u32l;
    // 0x8018D610: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018D614: lwc1        $f8, 0xAC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XAC0);
    // 0x8018D618: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D61C: addiu       $t8, $zero, 0x5A
    ctx->r24 = ADD32(0, 0X5A);
    // 0x8018D620: swc1        $f8, 0x3FEC($at)
    MEM_W(0X3FEC, ctx->r1) = ctx->f8.u32l;
    // 0x8018D624: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D628: sh          $t7, 0x4096($at)
    MEM_H(0X4096, ctx->r1) = ctx->r15;
    // 0x8018D62C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D630: sh          $t8, 0x4098($at)
    MEM_H(0X4098, ctx->r1) = ctx->r24;
    // 0x8018D634: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D638: swc1        $f10, 0x40F4($at)
    MEM_W(0X40F4, ctx->r1) = ctx->f10.u32l;
    // 0x8018D63C: addiu       $a1, $zero, 0xC3
    ctx->r5 = ADD32(0, 0XC3);
    // 0x8018D640: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018D644: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8018D648: addiu       $a0, $a0, 0x3FFC
    ctx->r4 = ADD32(ctx->r4, 0X3FFC);
    // 0x8018D64C: jal         0x800612B8
    // 0x8018D650: sh          $a1, 0x3FE2($at)
    MEM_H(0X3FE2, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8018D650: sh          $a1, 0x3FE2($at)
    MEM_H(0X3FE2, ctx->r1) = ctx->r5;
    after_1:
    // 0x8018D654: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018D658: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8018D65C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018D660: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8018D664: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x8018D668: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8018D66C: addiu       $a1, $a1, 0x40E0
    ctx->r5 = ADD32(ctx->r5, 0X40E0);
    // 0x8018D670: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x8018D674: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8018D678: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018D67C: jal         0x80019218
    // 0x8018D680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8018D680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8018D684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D688: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D68C: jr          $ra
    // 0x8018D690: nop

    return;
    // 0x8018D690: nop

;}
RECOMP_FUNC void Aquas_801B1008(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B1008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801B100C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801B1010: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801B1014: lh          $t6, 0xAE($a2)
    ctx->r14 = MEM_H(ctx->r6, 0XAE);
    // 0x801B1018: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B101C: bne         $t6, $zero, L_801B10A0
    if (ctx->r14 != 0) {
        // 0x801B1020: nop
    
            goto L_801B10A0;
    }
    // 0x801B1020: nop

    // 0x801B1024: lwc1        $f0, 0x4330($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4330);
    // 0x801B1028: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801B102C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801B1030: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801B1034: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x801B1038: nop

    // 0x801B103C: bc1f        L_801B10A0
    if (!c1cs) {
        // 0x801B1040: nop
    
            goto L_801B10A0;
    }
    // 0x801B1040: nop

    // 0x801B1044: lh          $t7, 0x88($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X88);
    // 0x801B1048: lui         $at, 0xC1E0
    ctx->r1 = S32(0XC1E0 << 16);
    // 0x801B104C: bne         $t7, $zero, L_801B10A0
    if (ctx->r15 != 0) {
        // 0x801B1050: nop
    
            goto L_801B10A0;
    }
    // 0x801B1050: nop

    // 0x801B1054: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801B1058: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B105C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801B1060: swc1        $f6, 0x4444($at)
    MEM_W(0X4444, ctx->r1) = ctx->f6.u32l;
    // 0x801B1064: lh          $v0, 0xB4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XB4);
    // 0x801B1068: sh          $a1, 0xAE($a2)
    MEM_H(0XAE, ctx->r6) = ctx->r5;
    // 0x801B106C: sh          $zero, 0x88($a2)
    MEM_H(0X88, ctx->r6) = 0;
    // 0x801B1070: bne         $v0, $zero, L_801B108C
    if (ctx->r2 != 0) {
        // 0x801B1074: addiu       $a0, $a0, 0xD80
        ctx->r4 = ADD32(ctx->r4, 0XD80);
            goto L_801B108C;
    }
    // 0x801B1074: addiu       $a0, $a0, 0xD80
    ctx->r4 = ADD32(ctx->r4, 0XD80);
    // 0x801B1078: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x801B107C: jal         0x800BA808
    // 0x801B1080: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x801B1080: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801B1084: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801B1088: lh          $v0, 0xB4($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XB4);
L_801B108C:
    // 0x801B108C: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x801B1090: sh          $t8, 0xB4($a2)
    MEM_H(0XB4, ctx->r6) = ctx->r24;
    // 0x801B1094: lh          $t9, 0xB4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XB4);
    // 0x801B1098: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x801B109C: sh          $t0, 0xB4($a2)
    MEM_H(0XB4, ctx->r6) = ctx->r8;
L_801B10A0:
    // 0x801B10A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B10A4: lwc1        $f0, 0x4330($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X4330);
    // 0x801B10A8: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801B10AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801B10B0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801B10B4: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801B10B8: nop

    // 0x801B10BC: bc1fl       L_801B10EC
    if (!c1cs) {
        // 0x801B10C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801B10EC;
    }
    goto skip_0;
    // 0x801B10C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801B10C4: lh          $t1, 0x56($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X56);
    // 0x801B10C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801B10CC: bnel        $t1, $zero, L_801B10EC
    if (ctx->r9 != 0) {
        // 0x801B10D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801B10EC;
    }
    goto skip_1;
    // 0x801B10D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801B10D4: sh          $t2, 0x8E($a2)
    MEM_H(0X8E, ctx->r6) = ctx->r10;
    // 0x801B10D8: lh          $t3, 0x8E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X8E);
    // 0x801B10DC: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x801B10E0: sh          $t4, 0x56($a2)
    MEM_H(0X56, ctx->r6) = ctx->r12;
    // 0x801B10E4: sh          $t3, 0x8C($a2)
    MEM_H(0X8C, ctx->r6) = ctx->r11;
    // 0x801B10E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801B10EC:
    // 0x801B10EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801B10F0: jr          $ra
    // 0x801B10F4: nop

    return;
    // 0x801B10F4: nop

;}
RECOMP_FUNC void Aquas_AqBacconBarnacle_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AF9FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AFA00: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x801AFA04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801AFA08: addiu       $a2, $a2, 0x4308
    ctx->r6 = ADD32(ctx->r6, 0X4308);
    // 0x801AFA0C: lw          $v0, 0x50($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X50);
    // 0x801AFA10: swc1        $f0, 0x11C($a0)
    MEM_W(0X11C, ctx->r4) = ctx->f0.u32l;
    // 0x801AFA14: swc1        $f0, 0x118($a0)
    MEM_W(0X118, ctx->r4) = ctx->f0.u32l;
    // 0x801AFA18: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x801AFA1C: swc1        $f0, 0x114($a0)
    MEM_W(0X114, ctx->r4) = ctx->f0.u32l;
    // 0x801AFA20: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
    // 0x801AFA24: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x801AFA28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801AFA2C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x801AFA30: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x801AFA34: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x801AFA38: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x801AFA3C: lwc1        $f8, 0x1C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x801AFA40: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x801AFA44: lwc1        $f16, -0x444($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X444);
    // 0x801AFA48: lwc1        $f10, 0x28($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X28);
    // 0x801AFA4C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801AFA50: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x801AFA54: jr          $ra
    // 0x801AFA58: nop

    return;
    // 0x801AFA58: nop

;}
RECOMP_FUNC void Zoness_ZoSarumarine_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801949DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801949E0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801949E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801949E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801949EC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801949F0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801949F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801949F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801949FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80194A00: lw          $a2, 0xE4($t6)
    ctx->r6 = MEM_W(ctx->r14, 0XE4);
    // 0x80194A04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80194A08: jal         0x80005B00
    // 0x80194A0C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80194A0C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_0:
    // 0x80194A10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194A14: lwc1        $f0, 0x1034($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X1034);
    // 0x80194A18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80194A1C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80194A20: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80194A24: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80194A28: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80194A2C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80194A30: jal         0x80005C34
    // 0x80194A34: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80194A34: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_1:
    // 0x80194A38: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80194A3C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80194A40: lw          $t0, -0x4438($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4438);
    // 0x80194A44: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80194A48: addiu       $t9, $t9, 0x4394
    ctx->r25 = ADD32(ctx->r25, 0X4394);
    // 0x80194A4C: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x80194A50: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80194A54: addiu       $a3, $a3, 0x3D08
    ctx->r7 = ADD32(ctx->r7, 0X3D08);
    // 0x80194A58: addiu       $a1, $a1, -0x61E8
    ctx->r5 = ADD32(ctx->r5, -0X61E8);
    // 0x80194A5C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80194A60: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80194A64: addiu       $a2, $v0, 0x1A0
    ctx->r6 = ADD32(ctx->r2, 0X1A0);
    // 0x80194A68: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80194A6C: jal         0x8009A72C
    // 0x80194A70: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_2;
    // 0x80194A70: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_2:
    // 0x80194A74: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80194A78: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80194A7C: jr          $ra
    // 0x80194A80: nop

    return;
    // 0x80194A80: nop

;}
RECOMP_FUNC void Aquas_801B0F88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801B0F88: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801B0F8C: lw          $t6, 0x42FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X42FC);
    // 0x801B0F90: beq         $t6, $zero, L_801B0FC4
    if (ctx->r14 == 0) {
        // 0x801B0F94: nop
    
            goto L_801B0FC4;
    }
    // 0x801B0F94: nop

    // 0x801B0F98: lh          $t7, 0x88($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X88);
    // 0x801B0F9C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801B0FA0: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801B0FA4: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x801B0FA8: beq         $at, $zero, L_801B0FC4
    if (ctx->r1 == 0) {
        // 0x801B0FAC: nop
    
            goto L_801B0FC4;
    }
    // 0x801B0FAC: nop

    // 0x801B0FB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801B0FB4: sh          $t8, 0xAE($a0)
    MEM_H(0XAE, ctx->r4) = ctx->r24;
    // 0x801B0FB8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801B0FBC: swc1        $f4, 0x4444($at)
    MEM_W(0X4444, ctx->r1) = ctx->f4.u32l;
    // 0x801B0FC0: sh          $t9, 0x88($a0)
    MEM_H(0X88, ctx->r4) = ctx->r25;
L_801B0FC4:
    // 0x801B0FC4: jr          $ra
    // 0x801B0FC8: nop

    return;
    // 0x801B0FC8: nop

;}
RECOMP_FUNC void Zoness_ZoShrimp_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192834: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80192838: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8019283C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80192840: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80192844: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x80192848: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8019284C: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80192850: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80192854: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80192858: lh          $v0, 0xB8($s3)
    ctx->r2 = MEM_H(ctx->r19, 0XB8);
    // 0x8019285C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192860: beql        $v0, $zero, L_80192890
    if (ctx->r2 == 0) {
        // 0x80192864: lwc1        $f4, 0x14($s3)
        ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
            goto L_80192890;
    }
    goto skip_0;
    // 0x80192864: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    skip_0:
    // 0x80192868: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019286C: beq         $v0, $at, L_80192934
    if (ctx->r2 == ctx->r1) {
        // 0x80192870: addiu       $a0, $s3, 0xEC
        ctx->r4 = ADD32(ctx->r19, 0XEC);
            goto L_80192934;
    }
    // 0x80192870: addiu       $a0, $s3, 0xEC
    ctx->r4 = ADD32(ctx->r19, 0XEC);
    // 0x80192874: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80192878: beq         $v0, $at, L_80192A50
    if (ctx->r2 == ctx->r1) {
        // 0x8019287C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80192A50;
    }
    // 0x8019287C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80192880: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80192884: b           L_80192B30
    // 0x80192888: lw          $t9, 0x50($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X50);
        goto L_80192B30;
    // 0x80192888: lw          $t9, 0x50($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X50);
    // 0x8019288C: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
L_80192890:
    // 0x80192890: lwc1        $f6, 0xEAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XEAC);
    // 0x80192894: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80192898: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x8019289C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801928A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801928A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801928A8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801928AC: jal         0x80005E90
    // 0x801928B0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x801928B0: nop

    after_0:
    // 0x801928B4: lui         $a1, 0x40AF
    ctx->r5 = S32(0X40AF << 16);
    // 0x801928B8: ori         $a1, $a1, 0xEDDF
    ctx->r5 = ctx->r5 | 0XEDDF;
    // 0x801928BC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801928C0: jal         0x80005D44
    // 0x801928C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801928C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801928C8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801928CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801928D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801928D4: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    // 0x801928D8: swc1        $f20, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f20.u32l;
    // 0x801928DC: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x801928E0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801928E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801928E8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801928EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801928F0: addiu       $a1, $sp, 0x84
    ctx->r5 = ADD32(ctx->r29, 0X84);
    // 0x801928F4: addiu       $a2, $sp, 0x78
    ctx->r6 = ADD32(ctx->r29, 0X78);
    // 0x801928F8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801928FC: jal         0x80006A20
    // 0x80192900: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80192900: swc1        $f6, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80192904: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80192908: lh          $t7, 0xB8($s3)
    ctx->r15 = MEM_H(ctx->r19, 0XB8);
    // 0x8019290C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80192910: swc1        $f8, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f8.u32l;
    // 0x80192914: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80192918: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8019291C: swc1        $f10, 0xEC($s3)
    MEM_W(0XEC, ctx->r19) = ctx->f10.u32l;
    // 0x80192920: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80192924: sh          $t6, 0xCE($s3)
    MEM_H(0XCE, ctx->r19) = ctx->r14;
    // 0x80192928: sh          $t8, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r24;
    // 0x8019292C: b           L_80192B2C
    // 0x80192930: swc1        $f16, 0xF0($s3)
    MEM_W(0XF0, ctx->r19) = ctx->f16.u32l;
        goto L_80192B2C;
    // 0x80192930: swc1        $f16, 0xF0($s3)
    MEM_W(0XF0, ctx->r19) = ctx->f16.u32l;
L_80192934:
    // 0x80192934: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192938: lwc1        $f18, 0xEB0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XEB0);
    // 0x8019293C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80192940: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80192944: lui         $a1, 0xC1F0
    ctx->r5 = S32(0XC1F0 << 16);
    // 0x80192948: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019294C: jal         0x8009BC2C
    // 0x80192950: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80192950: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x80192954: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80192958: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8019295C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80192960: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80192964: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80192968: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019296C: bc1fl       L_80192980
    if (!c1cs) {
        // 0x80192970: c.lt.s      $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
            goto L_80192980;
    }
    goto skip_1;
    // 0x80192970: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    skip_1:
    // 0x80192974: sw          $zero, 0x50($s3)
    MEM_W(0X50, ctx->r19) = 0;
    // 0x80192978: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8019297C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
L_80192980:
    // 0x80192980: nop

    // 0x80192984: bc1fl       L_80192998
    if (!c1cs) {
        // 0x80192988: lwc1        $f6, 0xEC($s3)
        ctx->f6.u32l = MEM_W(ctx->r19, 0XEC);
            goto L_80192998;
    }
    goto skip_2;
    // 0x80192988: lwc1        $f6, 0xEC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XEC);
    skip_2:
    // 0x8019298C: jal         0x80060FBC
    // 0x80192990: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x80192990: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    after_4:
    // 0x80192994: lwc1        $f6, 0xEC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XEC);
L_80192998:
    // 0x80192998: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019299C: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x801929A0: nop

    // 0x801929A4: bc1f        L_801929C4
    if (!c1cs) {
        // 0x801929A8: nop
    
            goto L_801929C4;
    }
    // 0x801929A8: nop

    // 0x801929AC: lh          $v1, 0xB6($s3)
    ctx->r3 = MEM_H(ctx->r19, 0XB6);
    // 0x801929B0: slti        $at, $v1, 0x11
    ctx->r1 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // 0x801929B4: beq         $at, $zero, L_801929E0
    if (ctx->r1 == 0) {
        // 0x801929B8: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_801929E0;
    }
    // 0x801929B8: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x801929BC: b           L_801929E0
    // 0x801929C0: sh          $t9, 0xB6($s3)
    MEM_H(0XB6, ctx->r19) = ctx->r25;
        goto L_801929E0;
    // 0x801929C0: sh          $t9, 0xB6($s3)
    MEM_H(0XB6, ctx->r19) = ctx->r25;
L_801929C4:
    // 0x801929C4: jal         0x8009ACDC
    // 0x801929C8: addiu       $a0, $a0, 0x1ABC
    ctx->r4 = ADD32(ctx->r4, 0X1ABC);
    Animation_GetFrameCount(rdram, ctx);
        goto after_5;
    // 0x801929C8: addiu       $a0, $a0, 0x1ABC
    ctx->r4 = ADD32(ctx->r4, 0X1ABC);
    after_5:
    // 0x801929CC: lh          $v1, 0xB6($s3)
    ctx->r3 = MEM_H(ctx->r19, 0XB6);
    // 0x801929D0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801929D4: beq         $at, $zero, L_801929E0
    if (ctx->r1 == 0) {
        // 0x801929D8: addiu       $t0, $v1, 0x1
        ctx->r8 = ADD32(ctx->r3, 0X1);
            goto L_801929E0;
    }
    // 0x801929D8: addiu       $t0, $v1, 0x1
    ctx->r8 = ADD32(ctx->r3, 0X1);
    // 0x801929DC: sh          $t0, 0xB6($s3)
    MEM_H(0XB6, ctx->r19) = ctx->r8;
L_801929E0:
    // 0x801929E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801929E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801929E8: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x801929EC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x801929F0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801929F4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801929F8: swc1        $f16, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f16.u32l;
    // 0x801929FC: jal         0x80004E20
    // 0x80192A00: lwc1        $f12, 0x10($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X10);
    Math_ModF(rdram, ctx);
        goto after_6;
    // 0x80192A00: lwc1        $f12, 0x10($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X10);
    after_6:
    // 0x80192A04: lb          $t1, 0xD0($s3)
    ctx->r9 = MEM_B(ctx->r19, 0XD0);
    // 0x80192A08: swc1        $f0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f0.u32l;
    // 0x80192A0C: beql        $t1, $zero, L_80192B30
    if (ctx->r9 == 0) {
        // 0x80192A10: lw          $t9, 0x50($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X50);
            goto L_80192B30;
    }
    goto skip_3;
    // 0x80192A10: lw          $t9, 0x50($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X50);
    skip_3:
    // 0x80192A14: lh          $v0, 0xCE($s3)
    ctx->r2 = MEM_H(ctx->r19, 0XCE);
    // 0x80192A18: beql        $v0, $zero, L_80192B30
    if (ctx->r2 == 0) {
        // 0x80192A1C: lw          $t9, 0x50($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X50);
            goto L_80192B30;
    }
    goto skip_4;
    // 0x80192A1C: lw          $t9, 0x50($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X50);
    skip_4:
    // 0x80192A20: lhu         $t2, 0xD6($s3)
    ctx->r10 = MEM_HU(ctx->r19, 0XD6);
    // 0x80192A24: sb          $zero, 0xD0($s3)
    MEM_B(0XD0, ctx->r19) = 0;
    // 0x80192A28: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80192A2C: sh          $t3, 0xCE($s3)
    MEM_H(0XCE, ctx->r19) = ctx->r11;
    // 0x80192A30: lh          $t4, 0xCE($s3)
    ctx->r12 = MEM_H(ctx->r19, 0XCE);
    // 0x80192A34: bgtzl       $t4, L_80192B30
    if (SIGNED(ctx->r12) > 0) {
        // 0x80192A38: lw          $t9, 0x50($s3)
        ctx->r25 = MEM_W(ctx->r19, 0X50);
            goto L_80192B30;
    }
    goto skip_5;
    // 0x80192A38: lw          $t9, 0x50($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X50);
    skip_5:
    // 0x80192A3C: lh          $t5, 0xB8($s3)
    ctx->r13 = MEM_H(ctx->r19, 0XB8);
    // 0x80192A40: sh          $zero, 0xCE($s3)
    MEM_H(0XCE, ctx->r19) = 0;
    // 0x80192A44: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80192A48: b           L_80192B2C
    // 0x80192A4C: sh          $t6, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r14;
        goto L_80192B2C;
    // 0x80192A4C: sh          $t6, 0xB8($s3)
    MEM_H(0XB8, ctx->r19) = ctx->r14;
L_80192A50:
    // 0x80192A50: addiu       $s1, $s3, 0x18C
    ctx->r17 = ADD32(ctx->r19, 0X18C);
    // 0x80192A54: addiu       $s2, $s3, 0x1C8
    ctx->r18 = ADD32(ctx->r19, 0X1C8);
L_80192A58:
    // 0x80192A58: jal         0x80004EB0
    // 0x80192A5C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80192A5C: nop

    after_7:
    // 0x80192A60: jal         0x80004EB0
    // 0x80192A64: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80192A64: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_8:
    // 0x80192A68: jal         0x80004EB0
    // 0x80192A6C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80192A6C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_9:
    // 0x80192A70: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80192A74: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80192A78: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80192A7C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80192A80: sub.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f18.fl;
    // 0x80192A84: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80192A88: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80192A8C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80192A90: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80192A94: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80192A98: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x80192A9C: mul.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80192AA0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80192AA4: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x80192AA8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80192AAC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80192AB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80192AB4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80192AB8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80192ABC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80192AC0: lwc1        $f6, 0x110($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X110);
    // 0x80192AC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80192AC8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80192ACC: jal         0x801900FC
    // 0x80192AD0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Zoness_ActorDebris_Spawn(rdram, ctx);
        goto after_10;
    // 0x80192AD0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80192AD4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80192AD8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80192ADC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80192AE0: bne         $s0, $at, L_80192A58
    if (ctx->r16 != ctx->r1) {
        // 0x80192AE4: addiu       $s2, $s2, 0xC
        ctx->r18 = ADD32(ctx->r18, 0XC);
            goto L_80192A58;
    }
    // 0x80192AE4: addiu       $s2, $s2, 0xC
    ctx->r18 = ADD32(ctx->r18, 0XC);
    // 0x80192AE8: sb          $zero, 0x44($s3)
    MEM_B(0X44, ctx->r19) = 0;
    // 0x80192AEC: jal         0x80066254
    // 0x80192AF0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Actor_Despawn(rdram, ctx);
        goto after_11;
    // 0x80192AF0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_11:
    // 0x80192AF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80192AF8: jal         0x80060FBC
    // 0x80192AFC: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    Object_Kill(rdram, ctx);
        goto after_12;
    // 0x80192AFC: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    after_12:
    // 0x80192B00: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80192B04: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80192B08: lw          $a2, 0xC($s3)
    ctx->r6 = MEM_W(ctx->r19, 0XC);
    // 0x80192B0C: jal         0x8007D0E0
    // 0x80192B10: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_13;
    // 0x80192B10: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_13:
    // 0x80192B14: lui         $a1, 0x2901
    ctx->r5 = S32(0X2901 << 16);
    // 0x80192B18: ori         $a1, $a1, 0x8036
    ctx->r5 = ctx->r5 | 0X8036;
    // 0x80192B1C: jal         0x8007A6F0
    // 0x80192B20: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_14;
    // 0x80192B20: addiu       $a0, $s3, 0x4
    ctx->r4 = ADD32(ctx->r19, 0X4);
    after_14:
    // 0x80192B24: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80192B28: nop

L_80192B2C:
    // 0x80192B2C: lw          $t9, 0x50($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X50);
L_80192B30:
    // 0x80192B30: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80192B34: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80192B38: bnel        $t9, $zero, L_80192BF8
    if (ctx->r25 != 0) {
        // 0x80192B3C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80192BF8;
    }
    goto skip_6;
    // 0x80192B3C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_6:
    // 0x80192B40: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80192B44: lw          $a2, 0x4($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X4);
    // 0x80192B48: lw          $a3, 0x8($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X8);
    // 0x80192B4C: jal         0x800A73E4
    // 0x80192B50: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_15;
    // 0x80192B50: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_15:
    // 0x80192B54: beq         $v0, $zero, L_80192BF4
    if (ctx->r2 == 0) {
        // 0x80192B58: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80192BF4;
    }
    // 0x80192B58: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192B5C: lw          $t0, 0x50($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X50);
    // 0x80192B60: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80192B64: lw          $a2, 0xC($s3)
    ctx->r6 = MEM_W(ctx->r19, 0XC);
    // 0x80192B68: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80192B6C: sw          $t1, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->r9;
    // 0x80192B70: lwc1        $f10, 0xEB4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XEB4);
    // 0x80192B74: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80192B78: lwc1        $f14, 0x74($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80192B7C: addiu       $s0, $s3, 0x100
    ctx->r16 = ADD32(ctx->r19, 0X100);
    // 0x80192B80: jal         0x8008377C
    // 0x80192B84: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Effect_Effect391_Spawn(rdram, ctx);
        goto after_16;
    // 0x80192B84: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x80192B88: lwc1        $f16, 0xEC($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0XEC);
    // 0x80192B8C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80192B90: lui         $a0, 0x1983
    ctx->r4 = S32(0X1983 << 16);
    // 0x80192B94: c.le.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl <= ctx->f16.fl;
    // 0x80192B98: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80192B9C: ori         $a0, $a0, 0x2019
    ctx->r4 = ctx->r4 | 0X2019;
    // 0x80192BA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80192BA4: bc1f        L_80192BE0
    if (!c1cs) {
        // 0x80192BA8: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80192BE0;
    }
    // 0x80192BA8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80192BAC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80192BB0: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80192BB4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80192BB8: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80192BBC: lui         $a0, 0x1983
    ctx->r4 = S32(0X1983 << 16);
    // 0x80192BC0: ori         $a0, $a0, 0x201A
    ctx->r4 = ctx->r4 | 0X201A;
    // 0x80192BC4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80192BC8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80192BCC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80192BD0: jal         0x80019218
    // 0x80192BD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_17;
    // 0x80192BD4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_17:
    // 0x80192BD8: b           L_80192BF8
    // 0x80192BDC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80192BF8;
    // 0x80192BDC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80192BE0:
    // 0x80192BE0: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80192BE4: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80192BE8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80192BEC: jal         0x80019218
    // 0x80192BF0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_18;
    // 0x80192BF0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_18:
L_80192BF4:
    // 0x80192BF4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80192BF8:
    // 0x80192BF8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80192BFC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80192C00: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x80192C04: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80192C08: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x80192C0C: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x80192C10: jr          $ra
    // 0x80192C14: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80192C14: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void Aquas_AqBoulder_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BA6A4: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x801BA6A8: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x801BA6AC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801BA6B0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801BA6B4: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x801BA6B8: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x801BA6BC: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x801BA6C0: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x801BA6C4: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x801BA6C8: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801BA6CC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801BA6D0: lh          $v0, 0xB8($s3)
    ctx->r2 = MEM_H(ctx->r19, 0XB8);
    // 0x801BA6D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801BA6D8: beql        $v0, $zero, L_801BA700
    if (ctx->r2 == 0) {
        // 0x801BA6DC: lw          $t6, 0x54($s3)
        ctx->r14 = MEM_W(ctx->r19, 0X54);
            goto L_801BA700;
    }
    goto skip_0;
    // 0x801BA6DC: lw          $t6, 0x54($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X54);
    skip_0:
    // 0x801BA6E0: beq         $v0, $at, L_801BA8D0
    if (ctx->r2 == ctx->r1) {
        // 0x801BA6E4: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_801BA8D0;
    }
    // 0x801BA6E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BA6E8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BA6EC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801BA6F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801BA6F4: b           L_801BAAD0
    // 0x801BA6F8: lb          $t6, 0xD0($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XD0);
        goto L_801BAAD0;
    // 0x801BA6F8: lb          $t6, 0xD0($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XD0);
    // 0x801BA6FC: lw          $t6, 0x54($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X54);
L_801BA700:
    // 0x801BA700: bnel        $t6, $zero, L_801BA8BC
    if (ctx->r14 != 0) {
        // 0x801BA704: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_801BA8BC;
    }
    goto skip_1;
    // 0x801BA704: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_1:
    // 0x801BA708: lwc1        $f4, 0x18($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X18);
    // 0x801BA70C: lwc1        $f6, 0x11C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X11C);
    // 0x801BA710: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801BA714: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801BA718: swc1        $f8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f8.u32l;
    // 0x801BA71C: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x801BA720: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x801BA724: bnel        $t8, $zero, L_801BA7AC
    if (ctx->r24 != 0) {
        // 0x801BA728: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_801BA7AC;
    }
    goto skip_2;
    // 0x801BA728: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_2:
    // 0x801BA72C: jal         0x80004EB0
    // 0x801BA730: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801BA730: nop

    after_0:
    // 0x801BA734: jal         0x80004EB0
    // 0x801BA738: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801BA738: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_1:
    // 0x801BA73C: jal         0x80004EB0
    // 0x801BA740: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801BA740: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_2:
    // 0x801BA744: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801BA748: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BA74C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BA750: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BA754: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801BA758: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BA75C: sub.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x801BA760: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BA764: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801BA768: sub.s       $f6, $f22, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x801BA76C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801BA770: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BA774: lwc1        $f16, 0x8($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BA778: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x801BA77C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801BA780: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BA784: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801BA788: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801BA78C: sub.s       $f18, $f0, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BA790: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801BA794: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x801BA798: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801BA79C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801BA7A0: jal         0x801AC8A8
    // 0x801BA7A4: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_3;
    // 0x801BA7A4: nop

    after_3:
    // 0x801BA7A8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_801BA7AC:
    // 0x801BA7AC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BA7B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BA7B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BA7B8: lwc1        $f10, 0x118($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X118);
    // 0x801BA7BC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BA7C0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801BA7C4: swc1        $f18, 0x118($s3)
    MEM_W(0X118, ctx->r19) = ctx->f18.u32l;
    // 0x801BA7C8: lwc1        $f6, 0x212C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X212C);
    // 0x801BA7CC: lwc1        $f4, 0x118($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X118);
    // 0x801BA7D0: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801BA7D4: jal         0x80023090
    // 0x801BA7D8: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x801BA7D8: nop

    after_4:
    // 0x801BA7DC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BA7E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BA7E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801BA7E8: lwc1        $f16, 0x8($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BA7EC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801BA7F0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801BA7F4: lui         $a0, 0x1940
    ctx->r4 = S32(0X1940 << 16);
    // 0x801BA7F8: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801BA7FC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801BA800: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x801BA804: ori         $a0, $a0, 0x7
    ctx->r4 = ctx->r4 | 0X7;
    // 0x801BA808: swc1        $f10, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f10.u32l;
    // 0x801BA80C: lwc1        $f18, 0x7940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801BA810: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BA814: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BA818: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    // 0x801BA81C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801BA820: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801BA824: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x801BA828: nop

    // 0x801BA82C: bc1fl       L_801BA8BC
    if (!c1cs) {
        // 0x801BA830: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_801BA8BC;
    }
    goto skip_3;
    // 0x801BA830: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_3:
    // 0x801BA834: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801BA838: jal         0x80019218
    // 0x801BA83C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x801BA83C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_5:
    // 0x801BA840: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BA844: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BA848: lwc1        $f18, 0x110($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X110);
    // 0x801BA84C: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BA850: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801BA854: mul.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801BA858: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x801BA85C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801BA860: sw          $t0, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->r8;
    // 0x801BA864: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BA868: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801BA86C: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BA870: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801BA874: swc1        $f20, 0xF0($s3)
    MEM_W(0XF0, ctx->r19) = ctx->f20.u32l;
    // 0x801BA878: swc1        $f20, 0xEC($s3)
    MEM_W(0XEC, ctx->r19) = ctx->f20.u32l;
    // 0x801BA87C: swc1        $f20, 0xE8($s3)
    MEM_W(0XE8, ctx->r19) = ctx->f20.u32l;
    // 0x801BA880: jal         0x8007B8F8
    // 0x801BA884: swc1        $f20, 0x10C($s3)
    MEM_W(0X10C, ctx->r19) = ctx->f20.u32l;
    Effect_Effect364_Spawn(rdram, ctx);
        goto after_6;
    // 0x801BA884: swc1        $f20, 0x10C($s3)
    MEM_W(0X10C, ctx->r19) = ctx->f20.u32l;
    after_6:
    // 0x801BA888: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BA88C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BA890: lwc1        $f10, 0x110($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X110);
    // 0x801BA894: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BA898: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BA89C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801BA8A0: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x801BA8A4: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BA8A8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801BA8AC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801BA8B0: jal         0x8007B8F8
    // 0x801BA8B4: nop

    Effect_Effect364_Spawn(rdram, ctx);
        goto after_7;
    // 0x801BA8B4: nop

    after_7:
    // 0x801BA8B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_801BA8BC:
    // 0x801BA8BC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BA8C0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801BA8C4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801BA8C8: b           L_801BAAD0
    // 0x801BA8CC: lb          $t6, 0xD0($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XD0);
        goto L_801BAAD0;
    // 0x801BA8CC: lb          $t6, 0xD0($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XD0);
L_801BA8D0:
    // 0x801BA8D0: lw          $t1, 0x54($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X54);
    // 0x801BA8D4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BA8D8: addiu       $a0, $s3, 0xEC
    ctx->r4 = ADD32(ctx->r19, 0XEC);
    // 0x801BA8DC: bne         $t1, $zero, L_801BAA64
    if (ctx->r9 != 0) {
        // 0x801BA8E0: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_801BAA64;
    }
    // 0x801BA8E0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801BA8E4: lwc1        $f16, 0x18($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X18);
    // 0x801BA8E8: lwc1        $f6, 0x11C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X11C);
    // 0x801BA8EC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801BA8F0: add.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x801BA8F4: swc1        $f8, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f8.u32l;
    // 0x801BA8F8: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x801BA8FC: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x801BA900: bne         $t3, $zero, L_801BA980
    if (ctx->r11 != 0) {
        // 0x801BA904: nop
    
            goto L_801BA980;
    }
    // 0x801BA904: nop

    // 0x801BA908: jal         0x80004EB0
    // 0x801BA90C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801BA90C: nop

    after_8:
    // 0x801BA910: jal         0x80004EB0
    // 0x801BA914: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801BA914: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_9:
    // 0x801BA918: jal         0x80004EB0
    // 0x801BA91C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801BA91C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_10:
    // 0x801BA920: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BA924: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BA928: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x801BA92C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BA930: sub.s       $f10, $f20, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x801BA934: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BA938: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801BA93C: sub.s       $f6, $f22, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x801BA940: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801BA944: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BA948: lwc1        $f18, 0x8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BA94C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801BA950: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801BA954: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BA958: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801BA95C: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x801BA960: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BA964: sub.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BA968: add.s       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x801BA96C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x801BA970: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801BA974: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801BA978: jal         0x801AC8A8
    // 0x801BA97C: nop

    Aquas_Bubble_Spawn(rdram, ctx);
        goto after_11;
    // 0x801BA97C: nop

    after_11:
L_801BA980:
    // 0x801BA980: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BA984: lwc1        $f24, 0x2130($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X2130);
    // 0x801BA988: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BA98C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BA990: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801BA994: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801BA998: addiu       $a0, $s3, 0xEC
    ctx->r4 = ADD32(ctx->r19, 0XEC);
    // 0x801BA99C: lui         $a1, 0xC0E0
    ctx->r5 = S32(0XC0E0 << 16);
    // 0x801BA9A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801BA9A4: jal         0x8009BC2C
    // 0x801BA9A8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x801BA9A8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_12:
    // 0x801BA9AC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801BA9B0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801BA9B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801BA9B8: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801BA9BC: lwc1        $f18, 0x8($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BA9C0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801BA9C4: add.s       $f16, $f4, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x801BA9C8: lui         $a0, 0x1940
    ctx->r4 = S32(0X1940 << 16);
    // 0x801BA9CC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801BA9D0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801BA9D4: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x801BA9D8: ori         $a0, $a0, 0x7
    ctx->r4 = ctx->r4 | 0X7;
    // 0x801BA9DC: addiu       $a1, $s3, 0x100
    ctx->r5 = ADD32(ctx->r19, 0X100);
    // 0x801BA9E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801BA9E4: bc1f        L_801BAA58
    if (!c1cs) {
        // 0x801BA9E8: lui         $t5, 0x800C
        ctx->r13 = S32(0X800C << 16);
            goto L_801BAA58;
    }
    // 0x801BA9E8: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801BA9EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801BA9F0: lwc1        $f6, 0xEC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XEC);
    // 0x801BA9F4: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801BA9F8: swc1        $f20, 0x10C($s3)
    MEM_W(0X10C, ctx->r19) = ctx->f20.u32l;
    // 0x801BA9FC: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x801BAA00: nop

    // 0x801BAA04: bc1fl       L_801BAA14
    if (!c1cs) {
        // 0x801BAA08: sw          $t4, 0x54($s3)
        MEM_W(0X54, ctx->r19) = ctx->r12;
            goto L_801BAA14;
    }
    goto skip_4;
    // 0x801BAA08: sw          $t4, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->r12;
    skip_4:
    // 0x801BAA0C: swc1        $f20, 0xEC($s3)
    MEM_W(0XEC, ctx->r19) = ctx->f20.u32l;
    // 0x801BAA10: sw          $t4, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->r12;
L_801BAA14:
    // 0x801BAA14: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801BAA18: jal         0x80019218
    // 0x801BAA1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_13;
    // 0x801BAA1C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_13:
    // 0x801BAA20: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801BAA24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801BAA28: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BAA2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BAA30: lwc1        $f18, 0x110($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X110);
    // 0x801BAA34: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BAA38: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BAA3C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801BAA40: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801BAA44: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BAA48: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801BAA4C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801BAA50: jal         0x8007B8F8
    // 0x801BAA54: nop

    Effect_Effect364_Spawn(rdram, ctx);
        goto after_14;
    // 0x801BAA54: nop

    after_14:
L_801BAA58:
    // 0x801BAA58: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801BAA5C: b           L_801BAA98
    // 0x801BAA60: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
        goto L_801BAA98;
    // 0x801BAA60: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_801BAA64:
    // 0x801BAA64: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801BAA68: lwc1        $f24, 0x2134($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X2134);
    // 0x801BAA6C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801BAA70: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801BAA74: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801BAA78: jal         0x8009BC2C
    // 0x801BAA7C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x801BAA7C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_15:
    // 0x801BAA80: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801BAA84: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801BAA88: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801BAA8C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801BAA90: nop

    // 0x801BAA94: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_801BAA98:
    // 0x801BAA98: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801BAA9C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801BAAA0: addiu       $a0, $s3, 0xE8
    ctx->r4 = ADD32(ctx->r19, 0XE8);
    // 0x801BAAA4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801BAAA8: jal         0x8009BC2C
    // 0x801BAAAC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x801BAAAC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_16:
    // 0x801BAAB0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801BAAB4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801BAAB8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801BAABC: addiu       $a0, $s3, 0xF0
    ctx->r4 = ADD32(ctx->r19, 0XF0);
    // 0x801BAAC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801BAAC4: jal         0x8009BC2C
    // 0x801BAAC8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x801BAAC8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_17:
    // 0x801BAACC: lb          $t6, 0xD0($s3)
    ctx->r14 = MEM_B(ctx->r19, 0XD0);
L_801BAAD0:
    // 0x801BAAD0: beql        $t6, $zero, L_801BAD54
    if (ctx->r14 == 0) {
        // 0x801BAAD4: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801BAD54;
    }
    goto skip_5;
    // 0x801BAAD4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_5:
    // 0x801BAAD8: lh          $t7, 0xCE($s3)
    ctx->r15 = MEM_H(ctx->r19, 0XCE);
    // 0x801BAADC: lhu         $t8, 0xD6($s3)
    ctx->r24 = MEM_HU(ctx->r19, 0XD6);
    // 0x801BAAE0: sb          $zero, 0xD0($s3)
    MEM_B(0XD0, ctx->r19) = 0;
    // 0x801BAAE4: andi        $t1, $zero, 0xFF
    ctx->r9 = 0 & 0XFF;
    // 0x801BAAE8: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x801BAAEC: sh          $t9, 0xCE($s3)
    MEM_H(0XCE, ctx->r19) = ctx->r25;
    // 0x801BAAF0: lh          $t0, 0xCE($s3)
    ctx->r8 = MEM_H(ctx->r19, 0XCE);
    // 0x801BAAF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801BAAF8: addiu       $t2, $s3, 0x100
    ctx->r10 = ADD32(ctx->r19, 0X100);
    // 0x801BAAFC: bgtzl       $t0, L_801BAD54
    if (SIGNED(ctx->r8) > 0) {
        // 0x801BAB00: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801BAD54;
    }
    goto skip_6;
    // 0x801BAB00: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_6:
    // 0x801BAB04: sb          $zero, 0x44($s3)
    MEM_B(0X44, ctx->r19) = 0;
    // 0x801BAB08: sh          $t1, 0xCE($s3)
    MEM_H(0XCE, ctx->r19) = ctx->r9;
    // 0x801BAB0C: jal         0x80066254
    // 0x801BAB10: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    Actor_Despawn(rdram, ctx);
        goto after_18;
    // 0x801BAB10: sw          $t2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r10;
    after_18:
    // 0x801BAB14: lh          $t3, 0xB8($s3)
    ctx->r11 = MEM_H(ctx->r19, 0XB8);
    // 0x801BAB18: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801BAB1C: addiu       $t9, $s3, 0x4
    ctx->r25 = ADD32(ctx->r19, 0X4);
    // 0x801BAB20: bne         $t3, $zero, L_801BAC0C
    if (ctx->r11 != 0) {
        // 0x801BAB24: addiu       $s2, $s3, 0x10
        ctx->r18 = ADD32(ctx->r19, 0X10);
            goto L_801BAC0C;
    }
    // 0x801BAB24: addiu       $s2, $s3, 0x10
    ctx->r18 = ADD32(ctx->r19, 0X10);
    // 0x801BAB28: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801BAB2C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x801BAB30: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BAB34: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x801BAB38: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801BAB3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801BAB40: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
L_801BAB44:
    // 0x801BAB44: bnel        $t4, $zero, L_801BABDC
    if (ctx->r12 != 0) {
        // 0x801BAB48: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801BABDC;
    }
    goto skip_7;
    // 0x801BAB48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x801BAB4C: jal         0x800613C4
    // 0x801BAB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_19;
    // 0x801BAB50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x801BAB54: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801BAB58: addiu       $t6, $zero, 0x109
    ctx->r14 = ADD32(0, 0X109);
    // 0x801BAB5C: sb          $t5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r13;
    // 0x801BAB60: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x801BAB64: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BAB68: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x801BAB6C: lwc1        $f10, 0x8($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BAB70: add.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f22.fl;
    // 0x801BAB74: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x801BAB78: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BAB7C: jal         0x80004EB0
    // 0x801BAB80: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x801BAB80: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    after_20:
    // 0x801BAB84: sub.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BAB88: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801BAB8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801BAB90: nop

    // 0x801BAB94: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x801BAB98: jal         0x80004EB0
    // 0x801BAB9C: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x801BAB9C: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    after_21:
    // 0x801BABA0: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x801BABA4: jal         0x80004EB0
    // 0x801BABA8: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x801BABA8: swc1        $f10, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f10.u32l;
    after_22:
    // 0x801BABAC: sub.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BABB0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801BABB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BABB8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801BABBC: sh          $t7, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r15;
    // 0x801BABC0: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801BABC4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801BABC8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801BABCC: jal         0x800612B8
    // 0x801BABD0: swc1        $f16, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_23;
    // 0x801BABD0: swc1        $f16, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f16.u32l;
    after_23:
    // 0x801BABD4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x801BABD8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_801BABDC:
    // 0x801BABDC: slti        $at, $s1, 0x3C
    ctx->r1 = SIGNED(ctx->r17) < 0X3C ? 1 : 0;
    // 0x801BABE0: beq         $at, $zero, L_801BABF4
    if (ctx->r1 == 0) {
        // 0x801BABE4: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_801BABF4;
    }
    // 0x801BABE4: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x801BABE8: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x801BABEC: bnel        $at, $zero, L_801BAB44
    if (ctx->r1 != 0) {
        // 0x801BABF0: lbu         $t4, 0x0($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X0);
            goto L_801BAB44;
    }
    goto skip_8;
    // 0x801BABF0: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    skip_8:
L_801BABF4:
    // 0x801BABF4: slti        $at, $s1, 0x3C
    ctx->r1 = SIGNED(ctx->r17) < 0X3C ? 1 : 0;
    // 0x801BABF8: bne         $at, $zero, L_801BAC04
    if (ctx->r1 != 0) {
        // 0x801BABFC: addiu       $t8, $s3, 0x4
        ctx->r24 = ADD32(ctx->r19, 0X4);
            goto L_801BAC04;
    }
    // 0x801BABFC: addiu       $t8, $s3, 0x4
    ctx->r24 = ADD32(ctx->r19, 0X4);
    // 0x801BAC00: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_801BAC04:
    // 0x801BAC04: b           L_801BAC9C
    // 0x801BAC08: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
        goto L_801BAC9C;
    // 0x801BAC08: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
L_801BAC0C:
    // 0x801BAC0C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801BAC10: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801BAC14: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x801BAC18: addiu       $s0, $zero, 0x4
    ctx->r16 = ADD32(0, 0X4);
L_801BAC1C:
    // 0x801BAC1C: jal         0x80004EB0
    // 0x801BAC20: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x801BAC20: nop

    after_24:
    // 0x801BAC24: jal         0x80004EB0
    // 0x801BAC28: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_25;
    // 0x801BAC28: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_25:
    // 0x801BAC2C: jal         0x80004EB0
    // 0x801BAC30: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_26;
    // 0x801BAC30: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_26:
    // 0x801BAC34: sub.s       $f6, $f20, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f20.fl - ctx->f26.fl;
    // 0x801BAC38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BAC3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801BAC40: sub.s       $f18, $f0, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x801BAC44: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801BAC48: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801BAC4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BAC50: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801BAC54: mul.s       $f4, $f22, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f24.fl);
    // 0x801BAC58: lwc1        $f8, 0x2138($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2138);
    // 0x801BAC5C: addiu       $t0, $zero, 0x36
    ctx->r8 = ADD32(0, 0X36);
    // 0x801BAC60: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801BAC64: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801BAC68: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801BAC6C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x801BAC70: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801BAC74: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801BAC78: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801BAC7C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x801BAC80: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801BAC84: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801BAC88: jal         0x801A9448
    // 0x801BAC8C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Aquas_SpawnDebris(rdram, ctx);
        goto after_27;
    // 0x801BAC8C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_27:
    // 0x801BAC90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801BAC94: bne         $s1, $s0, L_801BAC1C
    if (ctx->r17 != ctx->r16) {
        // 0x801BAC98: nop
    
            goto L_801BAC1C;
    }
    // 0x801BAC98: nop

L_801BAC9C:
    // 0x801BAC9C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x801BACA0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801BACA4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BACA8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801BACAC: lwc1        $f18, 0x110($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X110);
    // 0x801BACB0: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BACB4: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BACB8: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x801BACBC: add.s       $f4, $f10, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x801BACC0: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BACC4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801BACC8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801BACCC: jal         0x8007BC7C
    // 0x801BACD0: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_28;
    // 0x801BACD0: nop

    after_28:
    // 0x801BACD4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BACD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801BACDC: lwc1        $f4, 0x110($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X110);
    // 0x801BACE0: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BACE4: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BACE8: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x801BACEC: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x801BACF0: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BACF4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801BACF8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801BACFC: jal         0x8007BC7C
    // 0x801BAD00: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_29;
    // 0x801BAD00: nop

    after_29:
    // 0x801BAD04: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801BAD08: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801BAD0C: lwc1        $f10, 0x110($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X110);
    // 0x801BAD10: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x801BAD14: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801BAD18: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801BAD1C: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x801BAD20: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x801BAD24: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801BAD28: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801BAD2C: jal         0x8007BC7C
    // 0x801BAD30: nop

    Effect_Effect362_Spawn(rdram, ctx);
        goto after_30;
    // 0x801BAD30: nop

    after_30:
    // 0x801BAD34: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801BAD38: jal         0x80060FBC
    // 0x801BAD3C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    Object_Kill(rdram, ctx);
        goto after_31;
    // 0x801BAD3C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_31:
    // 0x801BAD40: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x801BAD44: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    // 0x801BAD48: jal         0x8007A6F0
    // 0x801BAD4C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_32;
    // 0x801BAD4C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    after_32:
    // 0x801BAD50: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801BAD54:
    // 0x801BAD54: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801BAD58: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801BAD5C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801BAD60: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x801BAD64: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x801BAD68: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x801BAD6C: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x801BAD70: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x801BAD74: jr          $ra
    // 0x801BAD78: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x801BAD78: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void Zoness_ZoBarrier_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D15C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019D160: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019D164: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019D168: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019D16C: lh          $t6, 0xB8($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB8);
    // 0x8019D170: bnel        $t6, $zero, L_8019D330
    if (ctx->r14 != 0) {
        // 0x8019D174: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019D330;
    }
    goto skip_0;
    // 0x8019D174: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8019D178: lb          $t7, 0xD0($s0)
    ctx->r15 = MEM_B(ctx->r16, 0XD0);
    // 0x8019D17C: beql        $t7, $zero, L_8019D264
    if (ctx->r15 == 0) {
        // 0x8019D180: lh          $v1, 0x46($s0)
        ctx->r3 = MEM_H(ctx->r16, 0X46);
            goto L_8019D264;
    }
    goto skip_1;
    // 0x8019D180: lh          $v1, 0x46($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X46);
    skip_1:
    // 0x8019D184: lh          $t8, 0xD2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XD2);
    // 0x8019D188: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019D18C: sb          $zero, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = 0;
    // 0x8019D190: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x8019D194: beq         $at, $zero, L_8019D23C
    if (ctx->r1 == 0) {
        // 0x8019D198: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_8019D23C;
    }
    // 0x8019D198: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019D19C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019D1A0: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8019D1A4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019D1A8: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8019D1AC: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x8019D1B0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019D1B4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8019D1B8: ori         $a0, $a0, 0x1E
    ctx->r4 = ctx->r4 | 0X1E;
    // 0x8019D1BC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8019D1C0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019D1C4: jal         0x80019218
    // 0x8019D1C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8019D1C8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8019D1CC: lui         $at, 0x4386
    ctx->r1 = S32(0X4386 << 16);
    // 0x8019D1D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019D1D4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D1D8: lwc1        $f10, 0xDC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x8019D1DC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019D1E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019D1E4: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x8019D1E8: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8019D1EC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019D1F0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8019D1F4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8019D1F8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019D1FC: ori         $a0, $a0, 0x1F
    ctx->r4 = ctx->r4 | 0X1F;
    // 0x8019D200: bc1f        L_8019D218
    if (!c1cs) {
        // 0x8019D204: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_8019D218;
    }
    // 0x8019D204: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019D208: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019D20C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D210: b           L_8019D228
    // 0x8019D214: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
        goto L_8019D228;
    // 0x8019D214: swc1        $f16, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f16.u32l;
L_8019D218:
    // 0x8019D218: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8019D21C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019D220: nop

    // 0x8019D224: swc1        $f18, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f18.u32l;
L_8019D228:
    // 0x8019D228: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019D22C: jal         0x80019218
    // 0x8019D230: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019D230: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_1:
    // 0x8019D234: b           L_8019D264
    // 0x8019D238: lh          $v1, 0x46($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X46);
        goto L_8019D264;
    // 0x8019D238: lh          $v1, 0x46($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X46);
L_8019D23C:
    // 0x8019D23C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8019D240: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019D244: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8019D248: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x8019D24C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019D250: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019D254: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019D258: jal         0x80019218
    // 0x8019D25C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019D25C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x8019D260: lh          $v1, 0x46($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X46);
L_8019D264:
    // 0x8019D264: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8019D268: addiu       $a0, $s0, 0x118
    ctx->r4 = ADD32(ctx->r16, 0X118);
    // 0x8019D26C: beq         $v1, $zero, L_8019D2DC
    if (ctx->r3 == 0) {
        // 0x8019D270: sll         $t2, $v1, 2
        ctx->r10 = S32(ctx->r3 << 2);
            goto L_8019D2DC;
    }
    // 0x8019D270: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8019D274: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x8019D278: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019D27C: lwc1        $f6, 0x12D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X12D0);
    // 0x8019D280: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8019D284: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8019D288: subu        $t2, $t2, $v1
    ctx->r10 = SUB32(ctx->r10, ctx->r3);
    // 0x8019D28C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019D290: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019D294: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8019D298: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8019D29C: addiu       $t3, $t2, -0x2F4
    ctx->r11 = ADD32(ctx->r10, -0X2F4);
    // 0x8019D2A0: addiu       $t4, $t4, 0x3FE0
    ctx->r12 = ADD32(ctx->r12, 0X3FE0);
    // 0x8019D2A4: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8019D2A8: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019D2AC: lui         $at, 0x43B9
    ctx->r1 = S32(0X43B9 << 16);
    // 0x8019D2B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D2B4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019D2B8: swc1        $f16, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f16.u32l;
    // 0x8019D2BC: lwc1        $f18, 0x11C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X11C);
    // 0x8019D2C0: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019D2C4: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019D2C8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8019D2CC: nop

    // 0x8019D2D0: bc1fl       L_8019D2E0
    if (!c1cs) {
        // 0x8019D2D4: lwc1        $f10, 0x114($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
            goto L_8019D2E0;
    }
    goto skip_2;
    // 0x8019D2D4: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
    skip_2:
    // 0x8019D2D8: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
L_8019D2DC:
    // 0x8019D2DC: lwc1        $f10, 0x114($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X114);
L_8019D2E0:
    // 0x8019D2E0: lwc1        $f8, 0x118($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8019D2E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019D2E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019D2EC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8019D2F0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019D2F4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8019D2F8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8019D2FC: swc1        $f16, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f16.u32l;
    // 0x8019D300: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019D304: jal         0x8009BC2C
    // 0x8019D308: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8019D308: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8019D30C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019D310: lwc1        $f4, 0x118($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X118);
    // 0x8019D314: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8019D318: nop

    // 0x8019D31C: bc1fl       L_8019D330
    if (!c1cs) {
        // 0x8019D320: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019D330;
    }
    goto skip_3;
    // 0x8019D320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8019D324: jal         0x8001A500
    // 0x8019D328: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_4;
    // 0x8019D328: addiu       $a0, $s0, 0x100
    ctx->r4 = ADD32(ctx->r16, 0X100);
    after_4:
    // 0x8019D32C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019D330:
    // 0x8019D330: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019D334: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019D338: jr          $ra
    // 0x8019D33C: nop

    return;
    // 0x8019D33C: nop

;}
RECOMP_FUNC void Aquas_Actor188_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801BEC74: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801BEC78: jr          $ra
    // 0x801BEC7C: nop

    return;
    // 0x801BEC7C: nop

;}
