#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void AudioHeap_AllocPermanent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DB64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000DB68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000DB6C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000DB70: addiu       $a0, $a0, -0x3850
    ctx->r4 = ADD32(ctx->r4, -0X3850);
    // 0x8000DB74: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8000DB78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DB7C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000DB80: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000DB84: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000DB88: jal         0x8000BF14
    // 0x8000DB8C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000DB8C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x8000DB90: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000DB94: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000DB98: addiu       $t9, $t9, -0x3850
    ctx->r25 = ADD32(ctx->r25, -0X3850);
    // 0x8000DB9C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8000DBA0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8000DBA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8000DBA8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8000DBAC: bne         $v0, $zero, L_8000DBBC
    if (ctx->r2 != 0) {
        // 0x8000DBB0: sw          $v0, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->r2;
            goto L_8000DBBC;
    }
    // 0x8000DBB0: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x8000DBB4: b           L_8000DBD4
    // 0x8000DBB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000DBD4;
    // 0x8000DBB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DBBC:
    // 0x8000DBBC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8000DBC0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8000DBC4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000DBC8: sh          $t0, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r8;
    // 0x8000DBCC: sh          $t1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r9;
    // 0x8000DBD0: sw          $t2, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r10;
L_8000DBD4:
    // 0x8000DBD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DBD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000DBDC: jr          $ra
    // 0x8000DBE0: nop

    return;
    // 0x8000DBE0: nop

;}
RECOMP_FUNC void PlayerShot_Impact(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036318: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003631C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80036320: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80036324: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036328: bne         $v0, $at, L_80036340
    if (ctx->r2 != ctx->r1) {
        // 0x8003632C: nop
    
            goto L_80036340;
    }
    // 0x8003632C: nop

    // 0x80036330: jal         0x80060FBC
    // 0x80036334: addiu       $a1, $a0, 0x38
    ctx->r5 = ADD32(ctx->r4, 0X38);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80036334: addiu       $a1, $a0, 0x38
    ctx->r5 = ADD32(ctx->r4, 0X38);
    after_0:
    // 0x80036338: b           L_8003651C
    // 0x8003633C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003651C;
    // 0x8003633C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80036340:
    // 0x80036340: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80036344: lwc1        $f4, -0x7B68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7B68);
    // 0x80036348: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003634C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80036350: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x80036354: lwc1        $f6, -0x7B60($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B60);
    // 0x80036358: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003635C: addiu       $a2, $a2, -0x7DCC
    ctx->r6 = ADD32(ctx->r6, -0X7DCC);
    // 0x80036360: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x80036364: lwc1        $f8, -0x7B64($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7B64);
    // 0x80036368: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003636C: beq         $v0, $at, L_80036398
    if (ctx->r2 == ctx->r1) {
        // 0x80036370: swc1        $f8, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
            goto L_80036398;
    }
    // 0x80036370: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80036374: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80036378: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8003637C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80036380: beql        $a1, $t6, L_800363C0
    if (ctx->r5 == ctx->r14) {
        // 0x80036384: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800363C0;
    }
    goto skip_0;
    // 0x80036384: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_0:
    // 0x80036388: bnel        $v0, $at, L_800363C0
    if (ctx->r2 != ctx->r1) {
        // 0x8003638C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800363C0;
    }
    goto skip_1;
    // 0x8003638C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    skip_1:
    // 0x80036390: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x80036394: beq         $t7, $zero, L_800363BC
    if (ctx->r15 == 0) {
        // 0x80036398: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800363BC;
    }
L_80036398:
    // 0x80036398: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003639C: bne         $v0, $at, L_800363AC
    if (ctx->r2 != ctx->r1) {
        // 0x800363A0: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800363AC;
    }
    // 0x800363A0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800363A4: sh          $t8, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r24;
    // 0x800363A8: sw          $zero, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = 0;
L_800363AC:
    // 0x800363AC: jal         0x80035E78
    // 0x800363B0: nop

    PlayerShot_ExplodeBomb(rdram, ctx);
        goto after_1;
    // 0x800363B0: nop

    after_1:
    // 0x800363B4: b           L_8003651C
    // 0x800363B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003651C;
    // 0x800363B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800363BC:
    // 0x800363BC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
L_800363C0:
    // 0x800363C0: bne         $v0, $at, L_80036510
    if (ctx->r2 != ctx->r1) {
        // 0x800363C4: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80036510;
    }
    // 0x800363C4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800363C8: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x800363CC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800363D0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800363D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800363D8: addiu       $v1, $v1, -0xEF0
    ctx->r3 = ADD32(ctx->r3, -0XEF0);
    // 0x800363DC: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x800363E0: swc1        $f10, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f10.u32l;
L_800363E4:
    // 0x800363E4: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x800363E8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800363EC: sb          $zero, 0xCA($t0)
    MEM_B(0XCA, ctx->r8) = 0;
    // 0x800363F0: lw          $t1, 0x68($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X68);
    // 0x800363F4: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x800363F8: sb          $zero, 0x3BE($t2)
    MEM_B(0X3BE, ctx->r10) = 0;
    // 0x800363FC: lw          $t3, 0x68($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X68);
    // 0x80036400: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80036404: sb          $zero, 0x6B2($t4)
    MEM_B(0X6B2, ctx->r12) = 0;
    // 0x80036408: lw          $t5, 0x68($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X68);
    // 0x8003640C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80036410: addiu       $v0, $v0, 0xBD0
    ctx->r2 = ADD32(ctx->r2, 0XBD0);
    // 0x80036414: bne         $v0, $v1, L_800363E4
    if (ctx->r2 != ctx->r3) {
        // 0x80036418: sb          $zero, 0x9A6($t6)
        MEM_B(0X9A6, ctx->r14) = 0;
            goto L_800363E4;
    }
    // 0x80036418: sb          $zero, 0x9A6($t6)
    MEM_B(0X9A6, ctx->r14) = 0;
    // 0x8003641C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80036420: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80036424: addiu       $v0, $v0, -0x7C98
    ctx->r2 = ADD32(ctx->r2, -0X7C98);
    // 0x80036428: swc1        $f0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f0.u32l;
    // 0x8003642C: swc1        $f0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f0.u32l;
    // 0x80036430: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80036434: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80036438: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8003643C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80036440: bne         $a1, $t7, L_800364BC
    if (ctx->r5 != ctx->r15) {
        // 0x80036444: lui         $a3, 0x4120
        ctx->r7 = S32(0X4120 << 16);
            goto L_800364BC;
    }
    // 0x80036444: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80036448: addiu       $v1, $v1, -0x7C9C
    ctx->r3 = ADD32(ctx->r3, -0X7C9C);
    // 0x8003644C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80036450: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80036454: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80036458: sw          $zero, -0x7CA0($at)
    MEM_W(-0X7CA0, ctx->r1) = 0;
    // 0x8003645C: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x80036460: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80036464: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80036468: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003646C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80036470: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80036474: jal         0x8007B344
    // 0x80036478: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_2;
    // 0x80036478: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_2:
    // 0x8003647C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80036480: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80036484: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80036488: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8003648C: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80036490: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x80036494: lwc1        $f16, 0x50FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X50FC);
    // 0x80036498: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8003649C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800364A0: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800364A4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800364A8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800364AC: jal         0x8007C120
    // 0x800364B0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_3;
    // 0x800364B0: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x800364B4: b           L_8003651C
    // 0x800364B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003651C;
    // 0x800364B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800364BC:
    // 0x800364BC: lw          $t2, 0x78E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78E8);
    // 0x800364C0: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800364C4: beq         $t2, $zero, L_800364D8
    if (ctx->r10 == 0) {
        // 0x800364C8: nop
    
            goto L_800364D8;
    }
    // 0x800364C8: nop

    // 0x800364CC: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x800364D0: b           L_800364D8
    // 0x800364D4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
        goto L_800364D8;
    // 0x800364D4: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
L_800364D8:
    // 0x800364D8: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800364DC: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800364E0: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x800364E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800364E8: jal         0x8007B344
    // 0x800364EC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_4;
    // 0x800364EC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x800364F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800364F4: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x800364F8: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800364FC: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80036500: jal         0x8007D2C8
    // 0x80036504: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_5;
    // 0x80036504: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    after_5:
    // 0x80036508: b           L_8003651C
    // 0x8003650C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003651C;
    // 0x8003650C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80036510:
    // 0x80036510: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x80036514: sw          $zero, 0x60($a0)
    MEM_W(0X60, ctx->r4) = 0;
    // 0x80036518: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003651C:
    // 0x8003651C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80036520: jr          $ra
    // 0x80036524: nop

    return;
    // 0x80036524: nop

;}
RECOMP_FUNC void Play_CheckMedalStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3F50: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A3F54: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800A3F58: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A3F5C: addiu       $v0, $v0, 0x78B0
    ctx->r2 = ADD32(ctx->r2, 0X78B0);
    // 0x800A3F60: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800A3F64: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800A3F68: blezl       $t7, L_800A3FA8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A3F6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A3FA8;
    }
    goto skip_0;
    // 0x800A3F6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800A3F70: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800A3F74: blezl       $t8, L_800A3FA8
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800A3F78: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A3FA8;
    }
    goto skip_1;
    // 0x800A3F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800A3F7C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800A3F80: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800A3F84: blezl       $t9, L_800A3FA8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A3F88: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A3FA8;
    }
    goto skip_2;
    // 0x800A3F88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800A3F8C: lw          $t0, 0x1A98($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1A98);
    // 0x800A3F90: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A3F94: bnel        $at, $zero, L_800A3FA8
    if (ctx->r1 != 0) {
        // 0x800A3F98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A3FA8;
    }
    goto skip_3;
    // 0x800A3F98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x800A3F9C: jr          $ra
    // 0x800A3FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800A3FA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A3FA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A3FA8:
    // 0x800A3FA8: jr          $ra
    // 0x800A3FAC: nop

    return;
    // 0x800A3FAC: nop

;}
RECOMP_FUNC void Sprite_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D8B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005D8BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005D8C0: bltz        $a1, L_8005D944
    if (SIGNED(ctx->r5) < 0) {
        // 0x8005D8C4: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_8005D944;
    }
    // 0x8005D8C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D8C8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005D8CC: lwc1        $f6, -0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005D8D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005D8D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005D8D8: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    // 0x8005D8DC: jal         0x8005D008
    // 0x8005D8E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_SetMatrix(rdram, ctx);
        goto after_0;
    // 0x8005D8E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8005D8E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8005D8E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8005D8EC: lwc1        $f16, -0x7B84($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B84);
    // 0x8005D8F0: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8005D8F4: lbu         $t6, 0x20($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X20);
    // 0x8005D8F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8005D8FC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8005D900: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x8005D904: bne         $t6, $zero, L_8005D930
    if (ctx->r14 != 0) {
        // 0x8005D908: swc1        $f18, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
            goto L_8005D930;
    }
    // 0x8005D908: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8005D90C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8005D910: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005D914: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8005D918: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8005D91C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8005D920: lw          $t9, 0x1C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1C);
    // 0x8005D924: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8005D928: b           L_8005D948
    // 0x8005D92C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8005D948;
    // 0x8005D92C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D930:
    // 0x8005D930: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x8005D934: beql        $v0, $zero, L_8005D948
    if (ctx->r2 == 0) {
        // 0x8005D938: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005D948;
    }
    goto skip_0;
    // 0x8005D938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8005D93C: jalr        $v0
    // 0x8005D940: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_1;
    // 0x8005D940: nop

    after_1:
L_8005D944:
    // 0x8005D944: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005D948:
    // 0x8005D948: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005D94C: jr          $ra
    // 0x8005D950: nop

    return;
    // 0x8005D950: nop

;}
RECOMP_FUNC void func_versus_800BC8D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC8D8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BC8DC: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800BC8E0: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800BC8E4: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800BC8E8: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800BC8EC: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BC8F0: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BC8F4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BC8F8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800BC8FC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800BC900: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800BC904: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800BC908: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800BC90C: lui         $s1, 0x301
    ctx->r17 = S32(0X301 << 16);
    // 0x800BC910: lui         $s3, 0x301
    ctx->r19 = S32(0X301 << 16);
    // 0x800BC914: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800BC918: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x800BC91C: addiu       $s3, $s3, -0x4DE8
    ctx->r19 = ADD32(ctx->r19, -0X4DE8);
    // 0x800BC920: addiu       $s1, $s1, -0x5B90
    ctx->r17 = ADD32(ctx->r17, -0X5B90);
    // 0x800BC924: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BC928: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
L_800BC92C:
    // 0x800BC92C: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800BC930: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800BC934: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BC938: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BC93C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BC940: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BC944: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800BC948: addiu       $a3, $zero, 0x98
    ctx->r7 = ADD32(0, 0X98);
    // 0x800BC94C: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BC950: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BC954: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BC958: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BC95C: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x800BC960: jal         0x8009D0BC
    // 0x800BC964: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BC964: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800BC968: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800BC96C: bne         $s0, $s4, L_800BC92C
    if (ctx->r16 != ctx->r20) {
        // 0x800BC970: addiu       $s1, $s1, 0x4C0
        ctx->r17 = ADD32(ctx->r17, 0X4C0);
            goto L_800BC92C;
    }
    // 0x800BC970: addiu       $s1, $s1, 0x4C0
    ctx->r17 = ADD32(ctx->r17, 0X4C0);
    // 0x800BC974: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800BC978: addiu       $t7, $zero, 0x7
    ctx->r15 = ADD32(0, 0X7);
    // 0x800BC97C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800BC980: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BC984: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BC988: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800BC98C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800BC990: addiu       $a3, $zero, 0x98
    ctx->r7 = ADD32(0, 0X98);
    // 0x800BC994: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BC998: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BC99C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BC9A0: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BC9A4: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800BC9A8: jal         0x8009D0BC
    // 0x800BC9AC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x800BC9AC: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800BC9B0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BC9B4: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800BC9B8: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800BC9BC: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800BC9C0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800BC9C4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800BC9C8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800BC9CC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800BC9D0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800BC9D4: jr          $ra
    // 0x800BC9D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BC9D8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ActorTeamBoss_SetFlyingSpeed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091B90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80091B94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80091B98: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80091B9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80091BA0: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80091BA4: lwc1        $f8, 0xF8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x80091BA8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80091BAC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80091BB0: lw          $a1, 0x118($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X118);
    // 0x80091BB4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80091BB8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80091BBC: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x80091BC0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091BC4: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x80091BC8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80091BCC: jal         0x8009BC2C
    // 0x80091BD0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80091BD0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x80091BD4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80091BD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80091BDC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80091BE0: lw          $a1, 0x120($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X120);
    // 0x80091BE4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80091BE8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80091BEC: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x80091BF0: jal         0x8009BC2C
    // 0x80091BF4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80091BF4: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80091BF8: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80091BFC: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80091C00: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80091C04: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x80091C08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80091C0C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80091C10: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80091C14: jal         0x8009F6CC
    // 0x80091C18: nop

    Math_Vec3fFromAngles(rdram, ctx);
        goto after_2;
    // 0x80091C18: nop

    after_2:
    // 0x80091C1C: lwc1        $f0, 0x14C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14C);
    // 0x80091C20: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80091C24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091C28: lwc1        $f14, 0x7F98($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7F98);
    // 0x80091C2C: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80091C30: lwc1        $f2, 0x148($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X148);
    // 0x80091C34: lwc1        $f12, 0x144($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80091C38: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80091C3C: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x80091C40: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80091C44: mul.s       $f18, $f2, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80091C48: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80091C4C: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x80091C50: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80091C54: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80091C58: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80091C5C: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x80091C60: swc1        $f4, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f4.u32l;
    // 0x80091C64: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80091C68: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    // 0x80091C6C: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80091C70: swc1        $f8, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->f8.u32l;
    // 0x80091C74: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80091C78: sub.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x80091C7C: swc1        $f18, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f18.u32l;
    // 0x80091C80: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80091C84: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80091C88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80091C8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80091C90: add.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80091C94: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x80091C98: nop

    // 0x80091C9C: bc1fl       L_80091CD8
    if (!c1cs) {
        // 0x80091CA0: lwc1        $f18, 0xF0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
            goto L_80091CD8;
    }
    goto skip_0;
    // 0x80091CA0: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    skip_0:
    // 0x80091CA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80091CA8: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80091CAC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80091CB0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80091CB4: nop

    // 0x80091CB8: bc1fl       L_80091CD8
    if (!c1cs) {
        // 0x80091CBC: lwc1        $f18, 0xF0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
            goto L_80091CD8;
    }
    goto skip_1;
    // 0x80091CBC: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    skip_1:
    // 0x80091CC0: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x80091CC4: bnel        $t6, $zero, L_80091CD8
    if (ctx->r14 != 0) {
        // 0x80091CC8: lwc1        $f18, 0xF0($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
            goto L_80091CD8;
    }
    goto skip_2;
    // 0x80091CC8: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    skip_2:
    // 0x80091CCC: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80091CD0: swc1        $f0, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f0.u32l;
    // 0x80091CD4: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
L_80091CD8:
    // 0x80091CD8: lwc1        $f4, 0x7D08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D08);
    // 0x80091CDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80091CE0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80091CE4: swc1        $f6, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f6.u32l;
    // 0x80091CE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80091CEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80091CF0: jr          $ra
    // 0x80091CF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80091CF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void CoSkibot_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006654C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80066550: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80066554: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066558: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006655C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066560: lwc1        $f4, 0x6928($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6928);
    // 0x80066564: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80066568: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006656C: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
    // 0x80066570: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80066574: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80066578: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006657C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066580: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80066584: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80066588: nop

    // 0x8006658C: bc1fl       L_800665A4
    if (!c1cs) {
        // 0x80066590: lwc1        $f18, 0x14($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
            goto L_800665A4;
    }
    goto skip_0;
    // 0x80066590: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    skip_0:
    // 0x80066594: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80066598: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8006659C: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
    // 0x800665A0: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
L_800665A4:
    // 0x800665A4: lwc1        $f4, 0x692C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X692C);
    // 0x800665A8: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800665AC: jal         0x80023090
    // 0x800665B0: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800665B0: nop

    after_0:
    // 0x800665B4: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800665B8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800665BC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800665C0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800665C4: swc1        $f8, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f8.u32l;
    // 0x800665C8: lwc1        $f16, 0x6930($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6930);
    // 0x800665CC: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800665D0: jal         0x80023250
    // 0x800665D4: nop

    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800665D4: nop

    after_1:
    // 0x800665D8: lwc1        $f2, 0x114($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800665DC: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x800665E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800665E4: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800665E8: beq         $v0, $zero, L_80066604
    if (ctx->r2 == 0) {
        // 0x800665EC: swc1        $f18, 0xF0($s0)
        MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
            goto L_80066604;
    }
    // 0x800665EC: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    // 0x800665F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800665F4: beql        $v0, $at, L_800666FC
    if (ctx->r2 == ctx->r1) {
        // 0x800665F8: mtc1        $zero, $f12
        ctx->f12.u32l = 0;
            goto L_800666FC;
    }
    goto skip_1;
    // 0x800665F8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    skip_1:
    // 0x800665FC: b           L_80066780
    // 0x80066600: lb          $t2, 0xD0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XD0);
        goto L_80066780;
    // 0x80066600: lb          $t2, 0xD0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XD0);
L_80066604:
    // 0x80066604: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066608: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006660C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80066610: nop

    // 0x80066614: bc1fl       L_80066630
    if (!c1cs) {
        // 0x80066618: lh          $t6, 0xB6($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XB6);
            goto L_80066630;
    }
    goto skip_2;
    // 0x80066618: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
    skip_2:
    // 0x8006661C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80066620: nop

    // 0x80066624: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80066628: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
    // 0x8006662C: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
L_80066630:
    // 0x80066630: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x80066634: addiu       $a0, $a0, -0x6AD8
    ctx->r4 = ADD32(ctx->r4, -0X6AD8);
    // 0x80066638: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8006663C: jal         0x8009ACDC
    // 0x80066640: sh          $t7, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r15;
    Animation_GetFrameCount(rdram, ctx);
        goto after_2;
    // 0x80066640: sh          $t7, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r15;
    after_2:
    // 0x80066644: lh          $v1, 0xB6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB6);
    // 0x80066648: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006664C: beql        $at, $zero, L_80066660
    if (ctx->r1 == 0) {
        // 0x80066650: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80066660;
    }
    goto skip_3;
    // 0x80066650: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_3:
    // 0x80066654: sh          $zero, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = 0;
    // 0x80066658: lh          $v1, 0xB6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB6);
    // 0x8006665C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_80066660:
    // 0x80066660: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066664: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80066668: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8006666C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80066670: nop

    // 0x80066674: bc1fl       L_8006669C
    if (!c1cs) {
        // 0x80066678: lui         $at, 0xC170
        ctx->r1 = S32(0XC170 << 16);
            goto L_8006669C;
    }
    goto skip_4;
    // 0x80066678: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    skip_4:
    // 0x8006667C: beq         $at, $zero, L_80066698
    if (ctx->r1 == 0) {
        // 0x80066680: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80066698;
    }
    // 0x80066680: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80066684: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80066688: lh          $v1, 0xB6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB6);
    // 0x8006668C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80066690: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x80066694: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
L_80066698:
    // 0x80066698: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
L_8006669C:
    // 0x8006669C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800666A0: slti        $at, $v1, 0x15
    ctx->r1 = SIGNED(ctx->r3) < 0X15 ? 1 : 0;
    // 0x800666A4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800666A8: nop

    // 0x800666AC: bc1fl       L_800666D0
    if (!c1cs) {
        // 0x800666B0: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_800666D0;
    }
    goto skip_5;
    // 0x800666B0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    skip_5:
    // 0x800666B4: bne         $at, $zero, L_800666CC
    if (ctx->r1 != 0) {
        // 0x800666B8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800666CC;
    }
    // 0x800666B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800666BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800666C0: lh          $v1, 0xB6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XB6);
    // 0x800666C4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800666C8: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
L_800666CC:
    // 0x800666CC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_800666D0:
    // 0x800666D0: beq         $v1, $at, L_800666E0
    if (ctx->r3 == ctx->r1) {
        // 0x800666D4: addiu       $at, $zero, 0x28
        ctx->r1 = ADD32(0, 0X28);
            goto L_800666E0;
    }
    // 0x800666D4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800666D8: bnel        $v1, $at, L_80066780
    if (ctx->r3 != ctx->r1) {
        // 0x800666DC: lb          $t2, 0xD0($s0)
        ctx->r10 = MEM_B(ctx->r16, 0XD0);
            goto L_80066780;
    }
    goto skip_6;
    // 0x800666DC: lb          $t2, 0xD0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XD0);
    skip_6:
L_800666E0:
    // 0x800666E0: lh          $t8, 0xB8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB8);
    // 0x800666E4: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x800666E8: sh          $t0, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r8;
    // 0x800666EC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800666F0: b           L_8006677C
    // 0x800666F4: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
        goto L_8006677C;
    // 0x800666F4: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
    // 0x800666F8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
L_800666FC:
    // 0x800666FC: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80066700: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80066704: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80066708: nop

    // 0x8006670C: bc1fl       L_8006672C
    if (!c1cs) {
        // 0x80066710: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_8006672C;
    }
    goto skip_7;
    // 0x80066710: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_7:
    // 0x80066714: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80066718: nop

    // 0x8006671C: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80066720: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x80066724: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80066728: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_8006672C:
    // 0x8006672C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80066730: bc1fl       L_8006674C
    if (!c1cs) {
        // 0x80066734: lwc1        $f2, 0x114($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X114);
            goto L_8006674C;
    }
    goto skip_8;
    // 0x80066734: lwc1        $f2, 0x114($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X114);
    skip_8:
    // 0x80066738: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006673C: nop

    // 0x80066740: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80066744: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80066748: lwc1        $f2, 0x114($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X114);
L_8006674C:
    // 0x8006674C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066750: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80066754: nop

    // 0x80066758: bc1fl       L_80066770
    if (!c1cs) {
        // 0x8006675C: lhu         $t1, 0xBC($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0XBC);
            goto L_80066770;
    }
    goto skip_9;
    // 0x8006675C: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
    skip_9:
    // 0x80066760: lwc1        $f6, 0x6934($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6934);
    // 0x80066764: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x80066768: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
    // 0x8006676C: lhu         $t1, 0xBC($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XBC);
L_80066770:
    // 0x80066770: bnel        $t1, $zero, L_80066780
    if (ctx->r9 != 0) {
        // 0x80066774: lb          $t2, 0xD0($s0)
        ctx->r10 = MEM_B(ctx->r16, 0XD0);
            goto L_80066780;
    }
    goto skip_10;
    // 0x80066774: lb          $t2, 0xD0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XD0);
    skip_10:
    // 0x80066778: sh          $zero, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = 0;
L_8006677C:
    // 0x8006677C: lb          $t2, 0xD0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0XD0);
L_80066780:
    // 0x80066780: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066784: lwc1        $f10, 0x6938($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6938);
    // 0x80066788: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8006678C: beq         $t2, $zero, L_80066838
    if (ctx->r10 == 0) {
        // 0x80066790: swc1        $f10, 0x110($s0)
        MEM_W(0X110, ctx->r16) = ctx->f10.u32l;
            goto L_80066838;
    }
    // 0x80066790: swc1        $f10, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f10.u32l;
    // 0x80066794: jal         0x80004EB0
    // 0x80066798: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80066798: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    after_3:
    // 0x8006679C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800667A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800667A4: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800667A8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800667AC: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800667B0: lb          $t4, 0xD0($s0)
    ctx->r12 = MEM_B(ctx->r16, 0XD0);
    // 0x800667B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800667B8: lui         $a3, 0x4150
    ctx->r7 = S32(0X4150 << 16);
    // 0x800667BC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800667C0: bne         $t4, $at, L_800667D8
    if (ctx->r12 != ctx->r1) {
        // 0x800667C4: swc1        $f6, 0xEC($s0)
        MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
            goto L_800667D8;
    }
    // 0x800667C4: swc1        $f6, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f6.u32l;
    // 0x800667C8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800667CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800667D0: nop

    // 0x800667D4: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
L_800667D8:
    // 0x800667D8: lui         $at, 0xC170
    ctx->r1 = S32(0XC170 << 16);
    // 0x800667DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800667E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800667E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800667E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800667EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800667F0: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800667F4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800667F8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800667FC: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    // 0x80066800: swc1        $f16, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f16.u32l;
    // 0x80066804: jal         0x8007D2C8
    // 0x80066808: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_4;
    // 0x80066808: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    after_4:
    // 0x8006680C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80066810: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80066814: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80066818: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8006681C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80066820: ori         $a0, $a0, 0xA008
    ctx->r4 = ctx->r4 | 0XA008;
    // 0x80066824: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80066828: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8006682C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80066830: jal         0x80019218
    // 0x80066834: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80066834: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_80066838:
    // 0x80066838: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006683C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80066840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80066844: jr          $ra
    // 0x80066848: nop

    return;
    // 0x80066848: nop

;}
RECOMP_FUNC void func_enmy_80061148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061148: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006114C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80061150: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80061154: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80061158: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8006115C: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x80061160: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80061164: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80061168: beq         $t6, $at, L_80061178
    if (ctx->r14 == ctx->r1) {
        // 0x8006116C: nop
    
            goto L_80061178;
    }
    // 0x8006116C: nop

    // 0x80061170: b           L_800612A8
    // 0x80061174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800612A8;
    // 0x80061174: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80061178:
    // 0x80061178: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006117C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80061180: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80061184: lw          $t7, 0x1C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C8);
    // 0x80061188: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006118C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80061190: bne         $t7, $at, L_800611A8
    if (ctx->r15 != ctx->r1) {
        // 0x80061194: nop
    
            goto L_800611A8;
    }
    // 0x80061194: nop

    // 0x80061198: jal         0x80060FE4
    // 0x8006119C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    func_enmy_80060FE4(rdram, ctx);
        goto after_0;
    // 0x8006119C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800611A0: b           L_800612AC
    // 0x800611A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800612AC;
    // 0x800611A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800611A8:
    // 0x800611A8: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x800611AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800611B0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800611B4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800611B8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800611BC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800611C0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800611C4: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x800611C8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800611CC: lw          $a1, 0x58($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X58);
    // 0x800611D0: jal         0x80005E90
    // 0x800611D4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x800611D4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_1:
    // 0x800611D8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800611DC: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x800611E0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800611E4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x800611E8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800611EC: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800611F0: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x800611F4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800611F8: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x800611FC: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x80061200: addu        $v0, $t1, $t3
    ctx->r2 = ADD32(ctx->r9, ctx->r11);
    // 0x80061204: lwc1        $f6, 0x40($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80061208: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8006120C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80061210: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80061214: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80061218: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8006121C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80061220: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80061224: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80061228: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8006122C: lwc1        $f16, 0x8($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80061230: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80061234: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80061238: jal         0x80006A20
    // 0x8006123C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x8006123C: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80061240: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80061244: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80061248: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8006124C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80061250: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80061254: nop

    // 0x80061258: bc1f        L_800612A8
    if (!c1cs) {
        // 0x8006125C: nop
    
            goto L_800612A8;
    }
    // 0x8006125C: nop

    // 0x80061260: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80061264: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80061268: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006126C: bc1f        L_800612A8
    if (!c1cs) {
        // 0x80061270: nop
    
            goto L_800612A8;
    }
    // 0x80061270: nop

    // 0x80061274: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061278: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x8006127C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80061280: mul.s       $f0, $f12, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80061284: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80061288: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006128C: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80061290: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80061294: nop

    // 0x80061298: bc1f        L_800612A8
    if (!c1cs) {
        // 0x8006129C: nop
    
            goto L_800612A8;
    }
    // 0x8006129C: nop

    // 0x800612A0: b           L_800612A8
    // 0x800612A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800612A8;
    // 0x800612A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800612A8:
    // 0x800612A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800612AC:
    // 0x800612AC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800612B0: jr          $ra
    // 0x800612B4: nop

    return;
    // 0x800612B4: nop

;}
RECOMP_FUNC void Math_PowF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800055DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800055E0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800055E4: blez        $a1, L_800055F8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800055E8: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800055F8;
    }
    // 0x800055E8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_800055EC:
    // 0x800055EC: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800055F0: bgtzl       $a1, L_800055EC
    if (SIGNED(ctx->r5) > 0) {
        // 0x800055F4: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800055EC;
    }
    goto skip_0;
    // 0x800055F4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    skip_0:
L_800055F8:
    // 0x800055F8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800055FC: jr          $ra
    // 0x80005600: nop

    return;
    // 0x80005600: nop

;}
RECOMP_FUNC void Scenery_Move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800696F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800696FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069700: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80069704: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80069708: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8006970C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80069710: lw          $t6, 0x1C8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C8);
    // 0x80069714: bne         $v0, $t6, L_80069754
    if (ctx->r2 != ctx->r14) {
        // 0x80069718: nop
    
            goto L_80069754;
    }
    // 0x80069718: nop

    // 0x8006971C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80069720: lwc1        $f6, 0x60($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X60);
    // 0x80069724: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80069728: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006972C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x80069730: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80069734: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80069738: nop

    // 0x8006973C: bc1fl       L_8006984C
    if (!c1cs) {
        // 0x80069740: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006984C;
    }
    goto skip_0;
    // 0x80069740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80069744: jal         0x80060FBC
    // 0x80069748: addiu       $a1, $a0, 0x70
    ctx->r5 = ADD32(ctx->r4, 0X70);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80069748: addiu       $a1, $a0, 0x70
    ctx->r5 = ADD32(ctx->r4, 0X70);
    after_0:
    // 0x8006974C: b           L_8006984C
    // 0x80069750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006984C;
    // 0x80069750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069754:
    // 0x80069754: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x80069758: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8006975C: bnel        $t7, $zero, L_8006984C
    if (ctx->r15 != 0) {
        // 0x80069760: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006984C;
    }
    goto skip_1;
    // 0x80069760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80069764: lw          $t8, -0x7D7C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D7C);
    // 0x80069768: beql        $v0, $t8, L_8006984C
    if (ctx->r2 == ctx->r24) {
        // 0x8006976C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006984C;
    }
    goto skip_2;
    // 0x8006976C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80069770: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80069774: lwc1        $f4, 0x40($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80069778: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8006977C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80069780: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80069784: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80069788: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8006978C: beq         $v0, $at, L_8006979C
    if (ctx->r2 == ctx->r1) {
        // 0x80069790: abs.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
            goto L_8006979C;
    }
    // 0x80069790: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80069794: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80069798: bne         $v0, $at, L_800697A8
    if (ctx->r2 != ctx->r1) {
        // 0x8006979C: lui         $at, 0x447A
        ctx->r1 = S32(0X447A << 16);
            goto L_800697A8;
    }
L_8006979C:
    // 0x8006979C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800697A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800697A4: nop

L_800697A8:
    // 0x800697A8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800697AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800697B0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800697B4: bc1fl       L_800697CC
    if (!c1cs) {
        // 0x800697B8: sub.s       $f6, $f0, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800697CC;
    }
    goto skip_3;
    // 0x800697B8: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    skip_3:
    // 0x800697BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800697C0: b           L_800697DC
    // 0x800697C4: lwc1        $f0, 0x114($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X114);
        goto L_800697DC;
    // 0x800697C4: lwc1        $f0, 0x114($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X114);
    // 0x800697C8: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
L_800697CC:
    // 0x800697CC: lwc1        $f8, 0x6A40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A40);
    // 0x800697D0: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800697D4: nop

    // 0x800697D8: lwc1        $f0, 0x114($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X114);
L_800697DC:
    // 0x800697DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800697E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800697E4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800697E8: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800697EC: nop

    // 0x800697F0: bc1tl       L_8006980C
    if (c1cs) {
        // 0x800697F4: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8006980C;
    }
    goto skip_4;
    // 0x800697F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_4:
    // 0x800697F8: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800697FC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80069800: bnel        $t9, $at, L_80069814
    if (ctx->r25 != ctx->r1) {
        // 0x80069804: lwc1        $f16, 0x48($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X48);
            goto L_80069814;
    }
    goto skip_5;
    // 0x80069804: lwc1        $f16, 0x48($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X48);
    skip_5:
    // 0x80069808: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8006980C:
    // 0x8006980C: nop

    // 0x80069810: lwc1        $f16, 0x48($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X48);
L_80069814:
    // 0x80069814: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80069818: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8006981C: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80069820: lwc1        $f18, 0x2C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x80069824: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80069828: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x8006982C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80069830: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x80069834: nop

    // 0x80069838: bc1fl       L_8006984C
    if (!c1cs) {
        // 0x8006983C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006984C;
    }
    goto skip_6;
    // 0x8006983C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80069840: jal         0x80060FBC
    // 0x80069844: addiu       $a1, $a0, 0x70
    ctx->r5 = ADD32(ctx->r4, 0X70);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x80069844: addiu       $a1, $a0, 0x70
    ctx->r5 = ADD32(ctx->r4, 0X70);
    after_1:
    // 0x80069848: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006984C:
    // 0x8006984C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069850: jr          $ra
    // 0x80069854: nop

    return;
    // 0x80069854: nop

;}
RECOMP_FUNC void AudioSynth_HartleyTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008780: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80008784: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80008788: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000878C: sllv        $s7, $t7, $a1
    ctx->r23 = S32(ctx->r15 << (ctx->r5 & 31));
    // 0x80008790: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80008794: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80008798: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000879C: sll         $t8, $s7, 1
    ctx->r24 = S32(ctx->r23 << 1);
    // 0x800087A0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800087A4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800087A8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800087AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800087B0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800087B4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800087B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800087BC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800087C0: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x800087C4: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x800087C8: or          $s4, $s7, $zero
    ctx->r20 = ctx->r23 | 0;
    // 0x800087CC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800087D0: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x800087D4: bgez        $s7, L_800087E4
    if (SIGNED(ctx->r23) >= 0) {
        // 0x800087D8: sra         $t9, $s7, 3
        ctx->r25 = S32(SIGNED(ctx->r23) >> 3);
            goto L_800087E4;
    }
    // 0x800087D8: sra         $t9, $s7, 3
    ctx->r25 = S32(SIGNED(ctx->r23) >> 3);
    // 0x800087DC: addiu       $at, $s7, 0x7
    ctx->r1 = ADD32(ctx->r23, 0X7);
    // 0x800087E0: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_800087E4:
    // 0x800087E4: addiu       $fp, $t9, -0x1
    ctx->r30 = ADD32(ctx->r25, -0X1);
    // 0x800087E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800087EC: beq         $s7, $at, L_800090F0
    if (ctx->r23 == ctx->r1) {
        // 0x800087F0: sw          $fp, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r30;
            goto L_800090F0;
    }
    // 0x800087F0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800087F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800087F8: beq         $s7, $at, L_80008810
    if (ctx->r23 == ctx->r1) {
        // 0x800087FC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80008810;
    }
    // 0x800087FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80008800: beq         $s7, $at, L_80008840
    if (ctx->r23 == ctx->r1) {
        // 0x80008804: lw          $t6, 0xE0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XE0);
            goto L_80008840;
    }
    // 0x80008804: lw          $t6, 0xE0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE0);
    // 0x80008808: b           L_800088C0
    // 0x8000880C: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
        goto L_800088C0;
    // 0x8000880C: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
L_80008810:
    // 0x80008810: lwc1        $f12, 0x4($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80008814: lwc1        $f2, 0x0($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80008818: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8000881C: lwc1        $f14, -0x79D4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X79D4);
    // 0x80008820: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80008824: sub.s       $f6, $f2, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80008828: mul.s       $f0, $f4, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x8000882C: nop

    // 0x80008830: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80008834: swc1        $f0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f0.u32l;
    // 0x80008838: b           L_800090F0
    // 0x8000883C: swc1        $f8, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f8.u32l;
        goto L_800090F0;
    // 0x8000883C: swc1        $f8, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f8.u32l;
L_80008840:
    // 0x80008840: lwc1        $f14, 0x8($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80008844: lwc1        $f2, 0x0($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80008848: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8000884C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80008850: add.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80008854: lwc1        $f16, 0xC($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80008858: lwc1        $f12, 0x4($s6)
    ctx->f12.u32l = MEM_W(ctx->r22, 0X4);
    // 0x8000885C: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80008860: mul.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80008864: add.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x80008868: mul.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8000886C: sub.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80008870: swc1        $f0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f0.u32l;
    // 0x80008874: mul.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80008878: lwc1        $f2, 0x0($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8000887C: swc1        $f6, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f6.u32l;
    // 0x80008880: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80008884: lwc1        $f14, 0x8($s6)
    ctx->f14.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80008888: swc1        $f0, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f0.u32l;
    // 0x8000888C: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80008890: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80008894: swc1        $f4, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f4.u32l;
    // 0x80008898: lwc1        $f16, 0xC($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8000889C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800088A0: swc1        $f0, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f0.u32l;
    // 0x800088A4: add.s       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x800088A8: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    // 0x800088AC: sub.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800088B0: swc1        $f10, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f10.u32l;
    // 0x800088B4: b           L_800090F0
    // 0x800088B8: swc1        $f4, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f4.u32l;
        goto L_800090F0;
    // 0x800088B8: swc1        $f4, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->f4.u32l;
    // 0x800088BC: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
L_800088C0:
    // 0x800088C0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800088C4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800088C8: nop

    // 0x800088CC: beql        $s7, $t9, L_80008980
    if (ctx->r23 == ctx->r25) {
        // 0x800088D0: lw          $t9, 0xDC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XDC);
            goto L_80008980;
    }
    goto skip_0;
    // 0x800088D0: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    skip_0:
    // 0x800088D4: mtc1        $s7, $f10
    ctx->f10.u32l = ctx->r23;
    // 0x800088D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800088DC: addiu       $s0, $t6, 0x4
    ctx->r16 = ADD32(ctx->r14, 0X4);
    // 0x800088E0: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800088E4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800088E8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x800088EC: lwc1        $f4, -0x79D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X79D0);
    // 0x800088F0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800088F4: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800088F8: sll         $t0, $t7, 2
    ctx->r8 = S32(ctx->r15 << 2);
    // 0x800088FC: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x80008900: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x80008904: addu        $s3, $t0, $v1
    ctx->r19 = ADD32(ctx->r8, ctx->r3);
    // 0x80008908: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x8000890C: addiu       $s2, $v1, 0x4
    ctx->r18 = ADD32(ctx->r3, 0X4);
    // 0x80008910: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80008914: blez        $t7, L_8000897C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80008918: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_8000897C;
    }
    // 0x80008918: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8000891C: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
L_80008920:
    // 0x80008920: jal         0x80023250
    // 0x80008924: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x80008924: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80008928: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8000892C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80008930: jal         0x80023090
    // 0x80008934: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80008934: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x80008938: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8000893C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80008940: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80008944: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80008948: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8000894C: jal         0x80023250
    // 0x80008950: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80008950: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x80008954: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80008958: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x8000895C: jal         0x80023090
    // 0x80008960: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x80008960: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    after_3:
    // 0x80008964: swc1        $f0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f0.u32l;
    // 0x80008968: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8000896C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80008970: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80008974: bne         $s5, $fp, L_80008920
    if (ctx->r21 != ctx->r30) {
        // 0x80008978: add.s       $f20, $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
            goto L_80008920;
    }
    // 0x80008978: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
L_8000897C:
    // 0x8000897C: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
L_80008980:
    // 0x80008980: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80008984: sw          $t8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r24;
    // 0x80008988: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8000898C: sw          $t6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r14;
    // 0x80008990: blez        $t6, L_80008F34
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80008994: sw          $zero, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = 0;
            goto L_80008F34;
    }
    // 0x80008994: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x80008998: sw          $s4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r20;
    // 0x8000899C: sw          $s6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r22;
    // 0x800089A0: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800089A4: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x800089A8: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x800089AC: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x800089B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800089B4: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x800089B8: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x800089BC: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x800089C0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800089C4: addiu       $a2, $a2, 0x6D54
    ctx->r6 = ADD32(ctx->r6, 0X6D54);
    // 0x800089C8: addiu       $t5, $t5, 0x6D58
    ctx->r13 = ADD32(ctx->r13, 0X6D58);
    // 0x800089CC: addiu       $s5, $s5, 0x6D60
    ctx->r21 = ADD32(ctx->r21, 0X6D60);
    // 0x800089D0: addiu       $fp, $fp, 0x6D64
    ctx->r30 = ADD32(ctx->r30, 0X6D64);
    // 0x800089D4: lwc1        $f2, -0x79CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X79CC);
    // 0x800089D8: addiu       $s4, $s4, 0x6D5C
    ctx->r20 = ADD32(ctx->r20, 0X6D5C);
    // 0x800089DC: addiu       $s6, $s6, 0x6D68
    ctx->r22 = ADD32(ctx->r22, 0X6D68);
    // 0x800089E0: addiu       $s7, $s7, 0x6D70
    ctx->r23 = ADD32(ctx->r23, 0X6D70);
    // 0x800089E4: lw          $a3, 0xD8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD8);
    // 0x800089E8: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
L_800089EC:
    // 0x800089EC: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800089F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800089F4: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x800089F8: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800089FC: sw          $t8, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r24;
    // 0x80008A00: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80008A04: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x80008A08: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
L_80008A0C:
    // 0x80008A0C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80008A10: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x80008A14: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x80008A18: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80008A1C: beq         $at, $zero, L_80008E00
    if (ctx->r1 == 0) {
        // 0x80008A20: sra         $t8, $t7, 2
        ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
            goto L_80008E00;
    }
    // 0x80008A20: sra         $t8, $t7, 2
    ctx->r24 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80008A24: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x80008A28: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
L_80008A2C:
    // 0x80008A2C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80008A30: addu        $a0, $t9, $a3
    ctx->r4 = ADD32(ctx->r25, ctx->r7);
    // 0x80008A34: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80008A38: addu        $ra, $t3, $a0
    ctx->r31 = ADD32(ctx->r11, ctx->r4);
    // 0x80008A3C: addu        $v0, $t3, $ra
    ctx->r2 = ADD32(ctx->r11, ctx->r31);
    // 0x80008A40: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x80008A44: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80008A48: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80008A4C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008A50: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x80008A54: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80008A58: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80008A5C: lwc1        $f10, 0x0($ra)
    ctx->f10.u32l = MEM_W(ctx->r31, 0X0);
    // 0x80008A60: swc1        $f10, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->f10.u32l;
    // 0x80008A64: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80008A68: lwc1        $f6, 0x0($ra)
    ctx->f6.u32l = MEM_W(ctx->r31, 0X0);
    // 0x80008A6C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008A70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80008A74: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x80008A78: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80008A7C: swc1        $f10, 0x6D5C($at)
    MEM_W(0X6D5C, ctx->r1) = ctx->f10.u32l;
    // 0x80008A80: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80008A84: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80008A88: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008A8C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008A90: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80008A94: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80008A98: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008A9C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x80008AA0: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80008AA4: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80008AA8: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008AAC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80008AB0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80008AB4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80008AB8: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80008ABC: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80008AC0: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x80008AC4: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x80008AC8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80008ACC: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80008AD0: bne         $at, $zero, L_80008DDC
    if (ctx->r1 != 0) {
        // 0x80008AD4: lw          $t7, 0x4C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X4C);
            goto L_80008DDC;
    }
    // 0x80008AD4: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80008AD8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80008ADC: addu        $t2, $t8, $a0
    ctx->r10 = ADD32(ctx->r24, ctx->r4);
    // 0x80008AE0: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80008AE4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80008AE8: addiu       $t1, $t1, 0x6D54
    ctx->r9 = ADD32(ctx->r9, 0X6D54);
    // 0x80008AEC: addu        $v1, $t3, $t2
    ctx->r3 = ADD32(ctx->r11, ctx->r10);
    // 0x80008AF0: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x80008AF4: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x80008AF8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80008AFC: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80008B00: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008B04: addu        $a0, $t3, $v0
    ctx->r4 = ADD32(ctx->r11, ctx->r2);
    // 0x80008B08: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80008B0C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80008B10: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80008B14: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80008B18: swc1        $f8, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->f8.u32l;
    // 0x80008B1C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80008B20: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008B24: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80008B28: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80008B2C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80008B30: lwc1        $f8, 0x0($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80008B34: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80008B38: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80008B3C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80008B40: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80008B44: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008B48: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80008B4C: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80008B50: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80008B54: lw          $t4, 0xC0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC0);
    // 0x80008B58: lw          $t7, 0xE0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE0);
    // 0x80008B5C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80008B60: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80008B64: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x80008B68: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80008B6C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80008B70: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80008B74: addu        $s1, $t8, $s0
    ctx->r17 = ADD32(ctx->r24, ctx->r16);
    // 0x80008B78: addu        $s2, $t8, $s1
    ctx->r18 = ADD32(ctx->r24, ctx->r17);
    // 0x80008B7C: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x80008B80: addu        $s3, $t8, $s2
    ctx->r19 = ADD32(ctx->r24, ctx->r18);
    // 0x80008B84: bne         $at, $zero, L_80008DDC
    if (ctx->r1 != 0) {
        // 0x80008B88: sw          $t9, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r25;
            goto L_80008DDC;
    }
    // 0x80008B88: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
L_80008B8C:
    // 0x80008B8C: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x80008B90: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80008B94: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008B98: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80008B9C: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x80008BA0: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80008BA4: addu        $v1, $t3, $v0
    ctx->r3 = ADD32(ctx->r11, ctx->r2);
    // 0x80008BA8: addu        $a0, $t3, $v1
    ctx->r4 = ADD32(ctx->r11, ctx->r3);
    // 0x80008BAC: swc1        $f8, 0x6D54($at)
    MEM_W(0X6D54, ctx->r1) = ctx->f8.u32l;
    // 0x80008BB0: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80008BB4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008BB8: addu        $t1, $t3, $a0
    ctx->r9 = ADD32(ctx->r11, ctx->r4);
    // 0x80008BBC: swc1        $f4, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->f4.u32l;
    // 0x80008BC0: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80008BC4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008BC8: subu        $a1, $ra, $t7
    ctx->r5 = SUB32(ctx->r31, ctx->r15);
    // 0x80008BCC: swc1        $f10, 0x6D5C($at)
    MEM_W(0X6D5C, ctx->r1) = ctx->f10.u32l;
    // 0x80008BD0: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80008BD4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008BD8: addu        $a2, $t3, $a1
    ctx->r6 = ADD32(ctx->r11, ctx->r5);
    // 0x80008BDC: swc1        $f6, 0x6D60($at)
    MEM_W(0X6D60, ctx->r1) = ctx->f6.u32l;
    // 0x80008BE0: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80008BE4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008BE8: addu        $a3, $t3, $a2
    ctx->r7 = ADD32(ctx->r11, ctx->r6);
    // 0x80008BEC: swc1        $f8, 0x6D64($at)
    MEM_W(0X6D64, ctx->r1) = ctx->f8.u32l;
    // 0x80008BF0: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80008BF4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008BF8: addu        $t2, $t3, $a3
    ctx->r10 = ADD32(ctx->r11, ctx->r7);
    // 0x80008BFC: swc1        $f4, 0x6D68($at)
    MEM_W(0X6D68, ctx->r1) = ctx->f4.u32l;
    // 0x80008C00: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80008C04: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008C08: swc1        $f10, 0x6D6C($at)
    MEM_W(0X6D6C, ctx->r1) = ctx->f10.u32l;
    // 0x80008C0C: lwc1        $f6, 0x0($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80008C10: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008C14: swc1        $f6, 0x6D70($at)
    MEM_W(0X6D70, ctx->r1) = ctx->f6.u32l;
    // 0x80008C18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008C1C: lwc1        $f8, 0x6D54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6D54);
    // 0x80008C20: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80008C24: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80008C28: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80008C2C: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008C30: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80008C34: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80008C38: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80008C3C: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008C40: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80008C44: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80008C48: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80008C4C: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80008C50: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80008C54: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80008C58: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80008C5C: lwc1        $f6, 0x6D54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D54);
    // 0x80008C60: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008C64: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80008C68: lwc1        $f4, 0x0($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80008C6C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80008C70: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80008C74: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80008C78: lwc1        $f8, 0x6D6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6D6C);
    // 0x80008C7C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008C80: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80008C84: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80008C88: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80008C8C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80008C90: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x80008C94: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80008C98: lwc1        $f4, 0x6D54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D54);
    // 0x80008C9C: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80008CA0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008CA4: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80008CA8: lwc1        $f10, 0x6D6C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D6C);
    // 0x80008CAC: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80008CB0: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80008CB4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80008CB8: lwc1        $f10, 0x0($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80008CBC: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80008CC0: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008CC4: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80008CC8: lwc1        $f10, 0x0($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80008CCC: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80008CD0: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80008CD4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80008CD8: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80008CDC: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80008CE0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008CE4: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x80008CE8: lwc1        $f4, 0x6D6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D6C);
    // 0x80008CEC: lwc1        $f10, 0x0($fp)
    ctx->f10.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80008CF0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008CF4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80008CF8: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80008CFC: lwc1        $f10, 0x0($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80008D00: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80008D04: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80008D08: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80008D0C: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80008D10: lwc1        $f6, 0x6D54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D54);
    // 0x80008D14: lwc1        $f4, 0x0($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80008D18: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008D1C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80008D20: lwc1        $f8, 0x6D6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6D6C);
    // 0x80008D24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008D28: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80008D2C: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80008D30: addu        $s1, $s1, $t4
    ctx->r17 = ADD32(ctx->r17, ctx->r12);
    // 0x80008D34: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80008D38: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80008D3C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80008D40: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008D44: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80008D48: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80008D4C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80008D50: lwc1        $f4, 0x0($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80008D54: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80008D58: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80008D5C: addu        $s0, $s0, $t4
    ctx->r16 = ADD32(ctx->r16, ctx->r12);
    // 0x80008D60: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80008D64: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80008D68: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x80008D6C: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80008D70: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80008D74: lwc1        $f10, 0x0($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80008D78: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80008D7C: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x80008D80: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80008D84: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80008D88: addu        $s2, $s2, $t4
    ctx->r18 = ADD32(ctx->r18, ctx->r12);
    // 0x80008D8C: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80008D90: lwc1        $f6, 0x6D54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D54);
    // 0x80008D94: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80008D98: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80008D9C: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80008DA0: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80008DA4: lwc1        $f6, 0x0($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0X0);
    // 0x80008DA8: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80008DAC: lwc1        $f4, 0x6D6C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D6C);
    // 0x80008DB0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80008DB4: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80008DB8: addu        $s3, $s3, $t4
    ctx->r19 = ADD32(ctx->r19, ctx->r12);
    // 0x80008DBC: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80008DC0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80008DC4: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80008DC8: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x80008DCC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x80008DD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008DD4: bne         $v0, $t9, L_80008B8C
    if (ctx->r2 != ctx->r25) {
        // 0x80008DD8: sw          $v0, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r2;
            goto L_80008B8C;
    }
    // 0x80008DD8: sw          $v0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r2;
L_80008DDC:
    // 0x80008DDC: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x80008DE0: lw          $a1, 0xCC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XCC);
    // 0x80008DE4: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x80008DE8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80008DEC: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80008DF0: slt         $at, $a1, $t0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80008DF4: addiu       $a2, $a2, 0x6D54
    ctx->r6 = ADD32(ctx->r6, 0X6D54);
    // 0x80008DF8: bne         $at, $zero, L_80008A2C
    if (ctx->r1 != 0) {
        // 0x80008DFC: lw          $a3, 0xD8($sp)
        ctx->r7 = MEM_W(ctx->r29, 0XD8);
            goto L_80008A2C;
    }
    // 0x80008DFC: lw          $a3, 0xD8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD8);
L_80008E00:
    // 0x80008E00: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80008E04: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    // 0x80008E08: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80008E0C: subu        $a0, $t8, $t9
    ctx->r4 = SUB32(ctx->r24, ctx->r25);
    // 0x80008E10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80008E14: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80008E18: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80008E1C: bne         $at, $zero, L_80008A0C
    if (ctx->r1 != 0) {
        // 0x80008E20: sw          $t6, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r14;
            goto L_80008A0C;
    }
    // 0x80008E20: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x80008E24: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x80008E28: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x80008E2C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x80008E30: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80008E34: sw          $t9, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r25;
    // 0x80008E38: blez        $t7, L_80008F14
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80008E3C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80008F14;
    }
    // 0x80008E3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80008E40: andi        $a0, $t7, 0x3
    ctx->r4 = ctx->r15 & 0X3;
    // 0x80008E44: beq         $a0, $zero, L_80008E88
    if (ctx->r4 == 0) {
        // 0x80008E48: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_80008E88;
    }
    // 0x80008E48: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80008E4C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80008E50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008E54: beq         $v1, $v0, L_80008E74
    if (ctx->r3 == ctx->r2) {
        // 0x80008E58: lwc1        $f20, 0x0($t2)
        ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
            goto L_80008E74;
    }
    // 0x80008E58: lwc1        $f20, 0x0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
L_80008E5C:
    // 0x80008E5C: div.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80008E60: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80008E64: lwc1        $f20, 0x0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80008E68: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80008E6C: bne         $v1, $v0, L_80008E5C
    if (ctx->r3 != ctx->r2) {
        // 0x80008E70: swc1        $f18, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
            goto L_80008E5C;
    }
    // 0x80008E70: swc1        $f18, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
L_80008E74:
    // 0x80008E74: div.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80008E78: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80008E7C: swc1        $f18, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
    // 0x80008E80: beq         $v0, $a1, L_80008F04
    if (ctx->r2 == ctx->r5) {
        // 0x80008E84: nop
    
            goto L_80008F04;
    }
    // 0x80008E84: nop

L_80008E88:
    // 0x80008E88: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x80008E8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008E90: beq         $v0, $v1, L_80008ED4
    if (ctx->r2 == ctx->r3) {
        // 0x80008E94: lwc1        $f20, 0x0($t2)
        ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
            goto L_80008ED4;
    }
    // 0x80008E94: lwc1        $f20, 0x0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
L_80008E98:
    // 0x80008E98: div.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80008E9C: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80008EA0: lwc1        $f14, 0x8($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80008EA4: lwc1        $f12, 0xC($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80008EA8: lwc1        $f20, 0x10($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80008EAC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80008EB0: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80008EB4: div.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80008EB8: swc1        $f18, -0x10($t2)
    MEM_W(-0X10, ctx->r10) = ctx->f18.u32l;
    // 0x80008EBC: div.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80008EC0: swc1        $f16, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->f16.u32l;
    // 0x80008EC4: div.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80008EC8: swc1        $f14, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->f14.u32l;
    // 0x80008ECC: bne         $v0, $v1, L_80008E98
    if (ctx->r2 != ctx->r3) {
        // 0x80008ED0: swc1        $f12, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->f12.u32l;
            goto L_80008E98;
    }
    // 0x80008ED0: swc1        $f12, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f12.u32l;
L_80008ED4:
    // 0x80008ED4: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80008ED8: lwc1        $f14, 0x8($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80008EDC: lwc1        $f12, 0xC($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80008EE0: div.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80008EE4: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80008EE8: div.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80008EEC: swc1        $f18, -0x10($t2)
    MEM_W(-0X10, ctx->r10) = ctx->f18.u32l;
    // 0x80008EF0: div.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80008EF4: swc1        $f16, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->f16.u32l;
    // 0x80008EF8: div.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80008EFC: swc1        $f14, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->f14.u32l;
    // 0x80008F00: swc1        $f12, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f12.u32l;
L_80008F04:
    // 0x80008F04: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80008F08: addiu       $a2, $a2, 0x6D54
    ctx->r6 = ADD32(ctx->r6, 0X6D54);
    // 0x80008F0C: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x80008F10: lw          $a3, 0xD8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XD8);
L_80008F14:
    // 0x80008F14: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80008F18: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x80008F1C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80008F20: bne         $t9, $t7, L_800089EC
    if (ctx->r25 != ctx->r15) {
        // 0x80008F24: sw          $t9, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = ctx->r25;
            goto L_800089EC;
    }
    // 0x80008F24: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x80008F28: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80008F2C: lw          $s6, 0xD8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD8);
    // 0x80008F30: lw          $s4, 0xD4($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD4);
L_80008F34:
    // 0x80008F34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80008F38: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80008F3C: lwc1        $f2, -0x79C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X79C8);
    // 0x80008F40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80008F44: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80008F48: addiu       $a2, $a2, 0x6D54
    ctx->r6 = ADD32(ctx->r6, 0X6D54);
    // 0x80008F4C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80008F50:
    // 0x80008F50: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x80008F54: slt         $at, $v1, $s7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x80008F58: beq         $at, $zero, L_80008F98
    if (ctx->r1 == 0) {
        // 0x80008F5C: sll         $a0, $a3, 1
        ctx->r4 = S32(ctx->r7 << 1);
            goto L_80008F98;
    }
    // 0x80008F5C: sll         $a0, $a3, 1
    ctx->r4 = S32(ctx->r7 << 1);
L_80008F60:
    // 0x80008F60: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80008F64: addu        $v0, $t6, $s6
    ctx->r2 = ADD32(ctx->r14, ctx->r22);
    // 0x80008F68: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80008F6C: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80008F70: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80008F74: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x80008F78: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80008F7C: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80008F80: add.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80008F84: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x80008F88: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80008F8C: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80008F90: bne         $at, $zero, L_80008F60
    if (ctx->r1 != 0) {
        // 0x80008F94: swc1        $f4, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
            goto L_80008F60;
    }
    // 0x80008F94: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
L_80008F98:
    // 0x80008F98: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80008F9C: slt         $at, $a0, $s4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80008FA0: sll         $t8, $a3, 2
    ctx->r24 = S32(ctx->r7 << 2);
    // 0x80008FA4: bne         $at, $zero, L_80008F50
    if (ctx->r1 != 0) {
        // 0x80008FA8: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_80008F50;
    }
    // 0x80008FA8: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x80008FAC: or          $t2, $s6, $zero
    ctx->r10 = ctx->r22 | 0;
    // 0x80008FB0: blez        $s7, L_80009070
    if (SIGNED(ctx->r23) <= 0) {
        // 0x80008FB4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80009070;
    }
    // 0x80008FB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80008FB8: andi        $a0, $s7, 0x3
    ctx->r4 = ctx->r23 & 0X3;
    // 0x80008FBC: beq         $a0, $zero, L_80008FF8
    if (ctx->r4 == 0) {
        // 0x80008FC0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80008FF8;
    }
    // 0x80008FC0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80008FC4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80008FC8: beq         $v0, $a3, L_80008FE8
    if (ctx->r2 == ctx->r7) {
        // 0x80008FCC: lwc1        $f20, 0x0($t2)
        ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
            goto L_80008FE8;
    }
    // 0x80008FCC: lwc1        $f20, 0x0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
L_80008FD0:
    // 0x80008FD0: div.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80008FD4: lwc1        $f20, 0x4($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80008FD8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80008FDC: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80008FE0: bne         $v0, $a3, L_80008FD0
    if (ctx->r2 != ctx->r7) {
        // 0x80008FE4: swc1        $f18, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
            goto L_80008FD0;
    }
    // 0x80008FE4: swc1        $f18, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
L_80008FE8:
    // 0x80008FE8: div.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80008FEC: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80008FF0: swc1        $f18, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f18.u32l;
    // 0x80008FF4: beq         $a3, $s7, L_80009070
    if (ctx->r7 == ctx->r23) {
        // 0x80008FF8: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80009070;
    }
L_80008FF8:
    // 0x80008FF8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80008FFC: beq         $a3, $s4, L_80009040
    if (ctx->r7 == ctx->r20) {
        // 0x80009000: lwc1        $f20, 0x0($t2)
        ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
            goto L_80009040;
    }
    // 0x80009000: lwc1        $f20, 0x0($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X0);
L_80009004:
    // 0x80009004: div.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80009008: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x8000900C: lwc1        $f14, 0x8($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80009010: lwc1        $f12, 0xC($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XC);
    // 0x80009014: lwc1        $f20, 0x10($t2)
    ctx->f20.u32l = MEM_W(ctx->r10, 0X10);
    // 0x80009018: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000901C: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80009020: div.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80009024: swc1        $f18, -0x10($t2)
    MEM_W(-0X10, ctx->r10) = ctx->f18.u32l;
    // 0x80009028: div.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8000902C: swc1        $f16, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->f16.u32l;
    // 0x80009030: div.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80009034: swc1        $f14, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->f14.u32l;
    // 0x80009038: bne         $a3, $s4, L_80009004
    if (ctx->r7 != ctx->r20) {
        // 0x8000903C: swc1        $f12, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->f12.u32l;
            goto L_80009004;
    }
    // 0x8000903C: swc1        $f12, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f12.u32l;
L_80009040:
    // 0x80009040: lwc1        $f16, 0x4($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80009044: lwc1        $f14, 0x8($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X8);
    // 0x80009048: lwc1        $f12, 0xC($t2)
    ctx->f12.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8000904C: div.s       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80009050: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x80009054: div.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80009058: swc1        $f18, -0x10($t2)
    MEM_W(-0X10, ctx->r10) = ctx->f18.u32l;
    // 0x8000905C: div.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80009060: swc1        $f16, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->f16.u32l;
    // 0x80009064: div.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80009068: swc1        $f14, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->f14.u32l;
    // 0x8000906C: swc1        $f12, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->f12.u32l;
L_80009070:
    // 0x80009070: slti        $at, $s7, 0x2
    ctx->r1 = SIGNED(ctx->r23) < 0X2 ? 1 : 0;
    // 0x80009074: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80009078: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000907C: sw          $s4, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r20;
    // 0x80009080: bne         $at, $zero, L_800090F0
    if (ctx->r1 != 0) {
        // 0x80009084: sw          $s7, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r23;
            goto L_800090F0;
    }
    // 0x80009084: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80009088: sra         $t0, $s7, 1
    ctx->r8 = S32(SIGNED(ctx->r23) >> 1);
    // 0x8000908C: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
L_80009090:
    // 0x80009090: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80009094: beq         $at, $zero, L_800090C4
    if (ctx->r1 == 0) {
        // 0x80009098: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_800090C4;
    }
    // 0x80009098: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8000909C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800090A0: sw          $s6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r22;
    // 0x800090A4: addu        $v1, $t7, $s6
    ctx->r3 = ADD32(ctx->r15, ctx->r22);
    // 0x800090A8: lwc1        $f8, -0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0X4);
    // 0x800090AC: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800090B0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800090B4: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x800090B8: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800090BC: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800090C0: lw          $s6, 0xD8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD8);
L_800090C4:
    // 0x800090C4: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800090C8: beq         $at, $zero, L_800090E4
    if (ctx->r1 == 0) {
        // 0x800090CC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800090E4;
    }
    // 0x800090CC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800090D0:
    // 0x800090D0: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x800090D4: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800090D8: slt         $at, $t8, $a1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800090DC: bne         $at, $zero, L_800090D0
    if (ctx->r1 != 0) {
        // 0x800090E0: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800090D0;
    }
    // 0x800090E0: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800090E4:
    // 0x800090E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800090E8: bne         $a3, $t1, L_80009090
    if (ctx->r7 != ctx->r9) {
        // 0x800090EC: addu        $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
            goto L_80009090;
    }
    // 0x800090EC: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
L_800090F0:
    // 0x800090F0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800090F4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800090F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800090FC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80009100: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80009104: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80009108: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000910C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80009110: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80009114: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80009118: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000911C: jr          $ra
    // 0x80009120: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80009120: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void Display_LandmasterEngineGlow_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005478C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80054790: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80054794: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80054798: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005479C: jal         0x800BA140
    // 0x800547A0: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_0;
    // 0x800547A0: nop

    after_0:
    // 0x800547A4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800547A8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800547AC: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x800547B0: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x800547B4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800547B8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800547BC: addiu       $t8, $zero, -0x9C
    ctx->r24 = ADD32(0, -0X9C);
    // 0x800547C0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800547C4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800547C8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800547CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800547D0: jal         0x80005708
    // 0x800547D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x800547D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800547D8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800547DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800547E0: lwc1        $f6, 0x5E9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5E9C);
    // 0x800547E4: lwc1        $f4, 0xF8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XF8);
    // 0x800547E8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800547EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800547F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800547F4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800547F8: jal         0x80005FE0
    // 0x800547FC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x800547FC: nop

    after_2:
    // 0x80054800: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80054804: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80054808: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8005480C: lw          $t1, 0x1CC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X1CC);
    // 0x80054810: bnel        $t1, $at, L_80054868
    if (ctx->r9 != ctx->r1) {
        // 0x80054814: lwc1        $f0, 0x194($t0)
        ctx->f0.u32l = MEM_W(ctx->r8, 0X194);
            goto L_80054868;
    }
    goto skip_0;
    // 0x80054814: lwc1        $f0, 0x194($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X194);
    skip_0:
    // 0x80054818: lwc1        $f0, 0x194($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X194);
    // 0x8005481C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80054820: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80054824: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80054828: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8005482C: nop

    // 0x80054830: bc1fl       L_8005484C
    if (!c1cs) {
        // 0x80054834: mfc1        $a1, $f0
        ctx->r5 = (int32_t)ctx->f0.u32l;
            goto L_8005484C;
    }
    goto skip_1;
    // 0x80054834: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    skip_1:
    // 0x80054838: jal         0x80005740
    // 0x8005483C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x8005483C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80054840: b           L_80054904
    // 0x80054844: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80054904;
    // 0x80054844: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80054848: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
L_8005484C:
    // 0x8005484C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054850: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80054854: jal         0x80005C34
    // 0x80054858: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x80054858: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_4:
    // 0x8005485C: b           L_80054880
    // 0x80054860: nop

        goto L_80054880;
    // 0x80054860: nop

    // 0x80054864: lwc1        $f0, 0x194($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X194);
L_80054868:
    // 0x80054868: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005486C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80054870: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80054874: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80054878: jal         0x80005C34
    // 0x8005487C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x8005487C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
L_80054880:
    // 0x80054880: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80054884: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x80054888: lui         $a1, 0x3F4F
    ctx->r5 = S32(0X3F4F << 16);
    // 0x8005488C: ori         $a1, $a1, 0x5C28
    ctx->r5 = ctx->r5 | 0X5C28;
    // 0x80054890: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80054894: beq         $t5, $zero, L_800548C8
    if (ctx->r13 == 0) {
        // 0x80054898: lui         $a2, 0x3F11
        ctx->r6 = S32(0X3F11 << 16);
            goto L_800548C8;
    }
    // 0x80054898: lui         $a2, 0x3F11
    ctx->r6 = S32(0X3F11 << 16);
    // 0x8005489C: lui         $a1, 0x3F66
    ctx->r5 = S32(0X3F66 << 16);
    // 0x800548A0: lui         $a2, 0x3F21
    ctx->r6 = S32(0X3F21 << 16);
    // 0x800548A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800548A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800548AC: ori         $a2, $a2, 0x47AE
    ctx->r6 = ctx->r6 | 0X47AE;
    // 0x800548B0: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x800548B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800548B8: jal         0x80005C34
    // 0x800548BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_6;
    // 0x800548BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_6:
    // 0x800548C0: b           L_800548E0
    // 0x800548C4: nop

        goto L_800548E0;
    // 0x800548C4: nop

L_800548C8:
    // 0x800548C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800548CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800548D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800548D4: ori         $a2, $a2, 0x26E9
    ctx->r6 = ctx->r6 | 0X26E9;
    // 0x800548D8: jal         0x80005C34
    // 0x800548DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x800548DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_7:
L_800548E0:
    // 0x800548E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800548E4: jal         0x80006EB8
    // 0x800548E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x800548E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_8:
    // 0x800548EC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800548F0: jal         0x8005465C
    // 0x800548F4: lbu         $a0, 0x7C98($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7C98);
    Display_DrawEngineGlow(rdram, ctx);
        goto after_9;
    // 0x800548F4: lbu         $a0, 0x7C98($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X7C98);
    after_9:
    // 0x800548F8: jal         0x80005740
    // 0x800548FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x800548FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80054900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80054904:
    // 0x80054904: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80054908: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005490C: jr          $ra
    // 0x80054910: nop

    return;
    // 0x80054910: nop

;}
RECOMP_FUNC void AudioSeq_ScriptReadS16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800146D4: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x800146D8: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800146DC: addiu       $t9, $a1, 0x1
    ctx->r25 = ADD32(ctx->r5, 0X1);
    // 0x800146E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800146E4: lbu         $t0, 0x0($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X0);
    // 0x800146E8: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x800146EC: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x800146F0: or          $v1, $t0, $t8
    ctx->r3 = ctx->r8 | ctx->r24;
    // 0x800146F4: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x800146F8: sra         $v0, $t1, 16
    ctx->r2 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800146FC: jr          $ra
    // 0x80014700: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    return;
    // 0x80014700: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
;}
RECOMP_FUNC void func_effect_8007F2FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F2FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F304: lhu         $t6, 0x50($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X50);
    // 0x8007F308: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007F30C: bne         $t6, $zero, L_8007F320
    if (ctx->r14 != 0) {
        // 0x8007F310: nop
    
            goto L_8007F320;
    }
    // 0x8007F310: nop

    // 0x8007F314: jal         0x80060FBC
    // 0x8007F318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x8007F318: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007F31C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007F320:
    // 0x8007F320: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007F324: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8007F328: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8007F32C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8007F330: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8007F334: nop

    // 0x8007F338: bc1f        L_8007F35C
    if (!c1cs) {
        // 0x8007F33C: nop
    
            goto L_8007F35C;
    }
    // 0x8007F33C: nop

    // 0x8007F340: lbu         $t7, 0x7C98($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7C98);
    // 0x8007F344: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8007F348: bne         $t7, $zero, L_8007F35C
    if (ctx->r15 != 0) {
        // 0x8007F34C: nop
    
            goto L_8007F35C;
    }
    // 0x8007F34C: nop

    // 0x8007F350: jal         0x80060FBC
    // 0x8007F354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007F354: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8007F358: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8007F35C:
    // 0x8007F35C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8007F360: lbu         $t8, 0x7C98($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7C98);
    // 0x8007F364: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F368: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8007F36C: bne         $t8, $zero, L_8007F384
    if (ctx->r24 != 0) {
        // 0x8007F370: nop
    
            goto L_8007F384;
    }
    // 0x8007F370: nop

    // 0x8007F374: lwc1        $f8, 0x58($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007F378: lwc1        $f10, 0x748C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X748C);
    // 0x8007F37C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8007F380: swc1        $f16, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f16.u32l;
L_8007F384:
    // 0x8007F384: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007F388: lwc1        $f18, 0x7CC0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7CC0);
    // 0x8007F38C: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8007F390: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007F394: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8007F398: nop

    // 0x8007F39C: bc1fl       L_8007F3F8
    if (!c1cs) {
        // 0x8007F3A0: lh          $t9, 0x44($a0)
        ctx->r25 = MEM_H(ctx->r4, 0X44);
            goto L_8007F3F8;
    }
    goto skip_0;
    // 0x8007F3A0: lh          $t9, 0x44($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X44);
    skip_0:
    // 0x8007F3A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007F3A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007F3AC: lwc1        $f6, 0x7490($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7490);
    // 0x8007F3B0: lwc1        $f4, 0x58($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007F3B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007F3B8: lwc1        $f6, 0x54($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8007F3BC: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8007F3C0: swc1        $f8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f8.u32l;
    // 0x8007F3C4: lwc1        $f10, 0x58($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X58);
    // 0x8007F3C8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8007F3CC: sub.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8007F3D0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007F3D4: lwc1        $f16, 0xC($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8007F3D8: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
    // 0x8007F3DC: lwc1        $f18, 0x5C($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x8007F3E0: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007F3E4: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8007F3E8: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x8007F3EC: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8007F3F0: swc1        $f4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f4.u32l;
    // 0x8007F3F4: lh          $t9, 0x44($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X44);
L_8007F3F8:
    // 0x8007F3F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F3FC: bnel        $t9, $at, L_8007F42C
    if (ctx->r25 != ctx->r1) {
        // 0x8007F400: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007F42C;
    }
    goto skip_1;
    // 0x8007F400: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8007F404: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x8007F408: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x8007F40C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8007F410: bnel        $t1, $zero, L_8007F42C
    if (ctx->r9 != 0) {
        // 0x8007F414: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007F42C;
    }
    goto skip_2;
    // 0x8007F414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8007F418: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8007F41C: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8007F420: jal         0x8007D0E0
    // 0x8007F424: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_2;
    // 0x8007F424: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    after_2:
    // 0x8007F428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007F42C:
    // 0x8007F42C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007F430: jr          $ra
    // 0x8007F434: nop

    return;
    // 0x8007F434: nop

;}
RECOMP_FUNC void Matrix_MultVec3f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006970: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80006974: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80006978: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000697C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80006980: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80006984: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80006988: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000698C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80006990: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80006994: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80006998: lwc1        $f18, 0x30($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8000699C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800069A0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800069A4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x800069A8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800069AC: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800069B0: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800069B4: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800069B8: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800069BC: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800069C0: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800069C4: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800069C8: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800069CC: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800069D0: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800069D4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800069D8: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800069DC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x800069E0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800069E4: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800069E8: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800069EC: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800069F0: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800069F4: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800069F8: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800069FC: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80006A00: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80006A04: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80006A08: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80006A0C: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80006A10: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80006A14: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x80006A18: jr          $ra
    // 0x80006A1C: nop

    return;
    // 0x80006A1C: nop

;}
RECOMP_FUNC void Audio_NoteVibratoUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013A18: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013A1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013A20: lbu         $t6, 0x7C($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X7C);
    // 0x80013A24: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80013A28: addiu       $a0, $a0, 0x7C
    ctx->r4 = ADD32(ctx->r4, 0X7C);
    // 0x80013A2C: beql        $t6, $zero, L_80013A48
    if (ctx->r14 == 0) {
        // 0x80013A30: lbu         $t7, 0xA0($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0XA0);
            goto L_80013A48;
    }
    goto skip_0;
    // 0x80013A30: lbu         $t7, 0xA0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA0);
    skip_0:
    // 0x80013A34: jal         0x80013708
    // 0x80013A38: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Audio_GetPortamentoFreqScale(rdram, ctx);
        goto after_0;
    // 0x80013A38: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80013A3C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80013A40: swc1        $f0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->f0.u32l;
    // 0x80013A44: lbu         $t7, 0xA0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA0);
L_80013A48:
    // 0x80013A48: beql        $t7, $zero, L_80013A78
    if (ctx->r15 == 0) {
        // 0x80013A4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80013A78;
    }
    goto skip_1;
    // 0x80013A4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80013A50: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x80013A54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80013A58: addiu       $a0, $a1, 0x8C
    ctx->r4 = ADD32(ctx->r5, 0X8C);
    // 0x80013A5C: beql        $t8, $at, L_80013A78
    if (ctx->r24 == ctx->r1) {
        // 0x80013A60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80013A78;
    }
    goto skip_2;
    // 0x80013A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80013A64: jal         0x80013820
    // 0x80013A68: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Audio_GetVibratoFreqScale(rdram, ctx);
        goto after_1;
    // 0x80013A68: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80013A6C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80013A70: swc1        $f0, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->f0.u32l;
    // 0x80013A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80013A78:
    // 0x80013A78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013A7C: jr          $ra
    // 0x80013A80: nop

    return;
    // 0x80013A80: nop

;}
RECOMP_FUNC void Actor_SpawnDebris70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800674B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800674B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800674BC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800674C0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800674C4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800674C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800674CC: addiu       $v0, $v0, -0x2F6C
    ctx->r2 = ADD32(ctx->r2, -0X2F6C);
    // 0x800674D0: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x800674D4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_800674D8:
    // 0x800674D8: bnel        $t6, $zero, L_80067524
    if (ctx->r14 != 0) {
        // 0x800674DC: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_80067524;
    }
    goto skip_0;
    // 0x800674DC: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_0:
    // 0x800674E0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800674E4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800674E8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800674EC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800674F0: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800674F4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800674F8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800674FC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80067500: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80067504: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80067508: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8006750C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80067510: jal         0x80067348
    // 0x80067514: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    Actor_SetupDebris70(rdram, ctx);
        goto after_0;
    // 0x80067514: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x80067518: b           L_80067530
    // 0x8006751C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80067530;
    // 0x8006751C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80067520: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_80067524:
    // 0x80067524: bnel        $a0, $v0, L_800674D8
    if (ctx->r4 != ctx->r2) {
        // 0x80067528: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_800674D8;
    }
    goto skip_1;
    // 0x80067528: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8006752C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80067530:
    // 0x80067530: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80067534: jr          $ra
    // 0x80067538: nop

    return;
    // 0x80067538: nop

;}
RECOMP_FUNC void Display_LandmasterMuzzleFlash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052B80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052B84: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80052B88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80052B8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80052B90: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052B94: jal         0x80005708
    // 0x80052B98: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80052B98: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x80052B9C: lw          $t6, 0x1C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C8);
    // 0x80052BA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80052BA4: bne         $t6, $at, L_80052D28
    if (ctx->r14 != ctx->r1) {
        // 0x80052BA8: nop
    
            goto L_80052D28;
    }
    // 0x80052BA8: nop

    // 0x80052BAC: lw          $t7, 0x1A0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1A0);
    // 0x80052BB0: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80052BB4: addiu       $t0, $t0, 0x1548
    ctx->r8 = ADD32(ctx->r8, 0X1548);
    // 0x80052BB8: beq         $t7, $zero, L_80052D28
    if (ctx->r15 == 0) {
        // 0x80052BBC: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_80052D28;
    }
    // 0x80052BBC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052BC0: lw          $t8, 0x1C4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C4);
    // 0x80052BC4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80052BC8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80052BCC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80052BD0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80052BD4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80052BD8: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80052BDC: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80052BE0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80052BE4: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x80052BE8: jal         0x80005B00
    // 0x80052BEC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80052BEC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x80052BF0: lw          $t2, 0x1A0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1A0);
    // 0x80052BF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80052BF8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052BFC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80052C00: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80052C04: lwc1        $f0, -0x5DBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5DBC);
    // 0x80052C08: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80052C0C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80052C10: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80052C14: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80052C18: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80052C1C: jal         0x80005C34
    // 0x80052C20: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x80052C20: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x80052C24: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80052C28: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80052C2C: jal         0x80006EB8
    // 0x80052C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x80052C30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80052C34: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80052C38: lw          $t5, 0x78E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78E8);
    // 0x80052C3C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80052C40: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052C44: beql        $t5, $zero, L_80052C9C
    if (ctx->r13 == 0) {
        // 0x80052C48: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80052C9C;
    }
    goto skip_0;
    // 0x80052C48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x80052C4C: jal         0x800B99C0
    // 0x80052C50: nop

    RCP_SetupDL_40(rdram, ctx);
        goto after_4;
    // 0x80052C50: nop

    after_4:
    // 0x80052C54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052C58: lui         $t7, 0xB600
    ctx->r15 = S32(0XB600 << 16);
    // 0x80052C5C: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x80052C60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80052C64: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80052C68: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80052C6C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80052C70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052C74: lui         $t1, 0x302
    ctx->r9 = S32(0X302 << 16);
    // 0x80052C78: addiu       $t1, $t1, -0x2E0
    ctx->r9 = ADD32(ctx->r9, -0X2E0);
    // 0x80052C7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80052C80: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80052C84: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80052C88: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80052C8C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80052C90: b           L_80052D28
    // 0x80052C94: nop

        goto L_80052D28;
    // 0x80052C94: nop

    // 0x80052C98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80052C9C:
    // 0x80052C9C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80052CA0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80052CA4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80052CA8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80052CAC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80052CB0: jal         0x80005C34
    // 0x80052CB4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x80052CB4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x80052CB8: jal         0x80006EB8
    // 0x80052CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80052CBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80052CC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052CC4: jal         0x800B8DD0
    // 0x80052CC8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x80052CC8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_7:
    // 0x80052CCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052CD0: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80052CD4: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80052CD8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80052CDC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80052CE0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80052CE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80052CE8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052CEC: lui         $t8, 0xFF
    ctx->r24 = S32(0XFF << 16);
    // 0x80052CF0: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x80052CF4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80052CF8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80052CFC: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80052D00: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80052D04: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80052D08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80052D0C: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x80052D10: addiu       $t1, $t1, 0x4AC0
    ctx->r9 = ADD32(ctx->r9, 0X4AC0);
    // 0x80052D14: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80052D18: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80052D1C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x80052D20: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80052D24: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
L_80052D28:
    // 0x80052D28: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052D2C: jal         0x80005740
    // 0x80052D30: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_8;
    // 0x80052D30: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_8:
    // 0x80052D34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80052D38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80052D3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052D40: jr          $ra
    // 0x80052D44: nop

    return;
    // 0x80052D44: nop

;}
RECOMP_FUNC void func_enmy2_8006A900(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A900: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006A904: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006A908: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006A90C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006A910: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8006A914: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8006A918: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8006A91C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8006A920: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8006A924:
    // 0x8006A924: bnel        $t6, $zero, L_8006A950
    if (ctx->r14 != 0) {
        // 0x8006A928: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8006A950;
    }
    goto skip_0;
    // 0x8006A928: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8006A92C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006A930: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8006A934: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8006A938: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8006A93C: jal         0x8006A800
    // 0x8006A940: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_enmy2_8006A800(rdram, ctx);
        goto after_0;
    // 0x8006A940: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8006A944: b           L_8006A960
    // 0x8006A948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8006A960;
    // 0x8006A948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006A94C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8006A950:
    // 0x8006A950: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8006A954: beql        $at, $zero, L_8006A924
    if (ctx->r1 == 0) {
        // 0x8006A958: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8006A924;
    }
    goto skip_1;
    // 0x8006A958: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8006A95C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006A960:
    // 0x8006A960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006A964: jr          $ra
    // 0x8006A968: nop

    return;
    // 0x8006A968: nop

;}
RECOMP_FUNC void ItemSilverStar_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800685D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800685DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800685E0: jal         0x80068020
    // 0x800685E4: nop

    ItemSupplyRing_Update(rdram, ctx);
        goto after_0;
    // 0x800685E4: nop

    after_0:
    // 0x800685E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800685EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800685F0: jr          $ra
    // 0x800685F4: nop

    return;
    // 0x800685F4: nop

;}
RECOMP_FUNC void Audio_ResetPlayerFreqMods(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AF9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001AFA0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001AFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AFA8: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
L_8001AFAC:
    // 0x8001AFAC: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8001AFB0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x8001AFB4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001AFB8: addiu       $t7, $t7, -0x47B0
    ctx->r15 = ADD32(ctx->r15, -0X47B0);
    // 0x8001AFBC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8001AFC0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8001AFC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001AFC8:
    // 0x8001AFC8: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AFCC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001AFD0: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8001AFD4: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x8001AFD8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8001AFDC: mflo        $t8
    ctx->r24 = lo;
    // 0x8001AFE0: addu        $a1, $a0, $t8
    ctx->r5 = ADD32(ctx->r4, ctx->r24);
    // 0x8001AFE4: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8001AFE8: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x8001AFEC: sb          $zero, 0x10($a1)
    MEM_B(0X10, ctx->r5) = 0;
    // 0x8001AFF0: bne         $at, $zero, L_8001AFC8
    if (ctx->r1 != 0) {
        // 0x8001AFF4: sb          $zero, 0x11($a1)
        MEM_B(0X11, ctx->r5) = 0;
            goto L_8001AFC8;
    }
    // 0x8001AFF4: sb          $zero, 0x11($a1)
    MEM_B(0X11, ctx->r5) = 0;
    // 0x8001AFF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001AFFC: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8001B000: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x8001B004: bne         $at, $zero, L_8001AFAC
    if (ctx->r1 != 0) {
        // 0x8001B008: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8001AFAC;
    }
    // 0x8001B008: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8001B00C: jr          $ra
    // 0x8001B010: nop

    return;
    // 0x8001B010: nop

;}
RECOMP_FUNC void Player_Down(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B41EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B41F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B41F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B41F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B41FC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800B4200: sw          $t6, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r14;
    // 0x800B4204: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B4208: lw          $t7, 0x78E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78E8);
    // 0x800B420C: lui         $a0, 0x1001
    ctx->r4 = S32(0X1001 << 16);
    // 0x800B4210: bne         $t7, $zero, L_800B4240
    if (ctx->r15 != 0) {
        // 0x800B4214: nop
    
            goto L_800B4240;
    }
    // 0x800B4214: nop

    // 0x800B4218: jal         0x800182F4
    // 0x800B421C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_0;
    // 0x800B421C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_0:
    // 0x800B4220: lui         $a0, 0x1101
    ctx->r4 = S32(0X1101 << 16);
    // 0x800B4224: jal         0x800182F4
    // 0x800B4228: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x800B4228: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x800B422C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B4230: addiu       $a1, $zero, 0x27
    ctx->r5 = ADD32(0, 0X27);
    // 0x800B4234: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B4238: jal         0x8001D444
    // 0x800B423C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_2;
    // 0x800B423C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
L_800B4240:
    // 0x800B4240: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800B4244: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x800B4248: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800B424C: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x800B4250: bne         $t8, $at, L_800B4260
    if (ctx->r24 != ctx->r1) {
        // 0x800B4254: nop
    
            goto L_800B4260;
    }
    // 0x800B4254: nop

    // 0x800B4258: jal         0x8001A838
    // 0x800B425C: ori         $a0, $a0, 0xC023
    ctx->r4 = ctx->r4 | 0XC023;
    Audio_KillSfxById(rdram, ctx);
        goto after_3;
    // 0x800B425C: ori         $a0, $a0, 0xC023
    ctx->r4 = ctx->r4 | 0XC023;
    after_3:
L_800B4260:
    // 0x800B4260: jal         0x8001CA24
    // 0x800B4264: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_4;
    // 0x800B4264: lbu         $a0, 0x1C7($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1C7);
    after_4:
    // 0x800B4268: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B426C: ori         $a1, $a1, 0xC010
    ctx->r5 = ctx->r5 | 0XC010;
    // 0x800B4270: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800B4274: jal         0x800A5FA0
    // 0x800B4278: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x800B4278: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_5:
    // 0x800B427C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B4280: sw          $zero, 0x264($s0)
    MEM_W(0X264, ctx->r16) = 0;
    // 0x800B4284: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    // 0x800B4288: sw          $zero, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = 0;
    // 0x800B428C: sw          $zero, 0x220($s0)
    MEM_W(0X220, ctx->r16) = 0;
    // 0x800B4290: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B4294: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    // 0x800B4298: sb          $zero, 0x1A2C($at)
    MEM_B(0X1A2C, ctx->r1) = 0;
    // 0x800B429C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B42A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B42A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B42A8: jr          $ra
    // 0x800B42AC: nop

    return;
    // 0x800B42AC: nop

;}
RECOMP_FUNC void HUD_StarTex_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CB98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008CB9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008CBA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8008CBA4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008CBA8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8008CBAC: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x8008CBB0: addiu       $a1, $a1, 0x13E0
    ctx->r5 = ADD32(ctx->r5, 0X13E0);
    // 0x8008CBB4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008CBB8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8008CBBC: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8008CBC0: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8008CBC4: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x8008CBC8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8008CBCC: jal         0x8009D994
    // 0x8008CBD0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x8008CBD0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8008CBD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008CBD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8008CBDC: jr          $ra
    // 0x8008CBE0: nop

    return;
    // 0x8008CBE0: nop

;}
RECOMP_FUNC void Effect_SpawnById2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F04C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8007F050: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8007F054: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8007F058: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007F05C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8007F060: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8007F064: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8007F068: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8007F06C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8007F070: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007F074: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007F078: addiu       $s0, $s0, 0x3754
    ctx->r16 = ADD32(ctx->r16, 0X3754);
    // 0x8007F07C: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_8007F080:
    // 0x8007F080: bnel        $t6, $zero, L_8007F0FC
    if (ctx->r14 != 0) {
        // 0x8007F084: addiu       $s0, $s0, -0x8C
        ctx->r16 = ADD32(ctx->r16, -0X8C);
            goto L_8007F0FC;
    }
    goto skip_0;
    // 0x8007F084: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
    skip_0:
    // 0x8007F088: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007F08C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007F090: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007F094: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007F098: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8007F09C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007F0A0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007F0A4: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8007F0A8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8007F0AC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x8007F0B0: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8007F0B4: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8007F0B8: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8007F0BC: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007F0C0: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007F0C4: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007F0C8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8007F0CC: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8007F0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007F0D4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8007F0D8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8007F0DC: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8007F0E0: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8007F0E4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8007F0E8: jal         0x8007ED54
    // 0x8007F0EC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Effect_SetupById(rdram, ctx);
        goto after_0;
    // 0x8007F0EC: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8007F0F0: b           L_8007F10C
    // 0x8007F0F4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_8007F10C;
    // 0x8007F0F4: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8007F0F8: addiu       $s0, $s0, -0x8C
    ctx->r16 = ADD32(ctx->r16, -0X8C);
L_8007F0FC:
    // 0x8007F0FC: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8007F100: beql        $at, $zero, L_8007F080
    if (ctx->r1 == 0) {
        // 0x8007F104: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_8007F080;
    }
    goto skip_1;
    // 0x8007F104: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x8007F108: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8007F10C:
    // 0x8007F10C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8007F110: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8007F114: jr          $ra
    // 0x8007F118: nop

    return;
    // 0x8007F118: nop

;}
RECOMP_FUNC void Graphics_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004144: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80004148: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000414C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80004150: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80004154: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004158: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000415C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004160: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004164: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004168: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000416C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004170: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80004174: jal         0x800A18B0
    // 0x80004178: nop

    Game_Initialize(rdram, ctx);
        goto after_0;
    // 0x80004178: nop

    after_0:
    // 0x8000417C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004180: addiu       $a0, $a0, 0x22C0
    ctx->r4 = ADD32(ctx->r4, 0X22C0);
    // 0x80004184: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80004188: jal         0x80020720
    // 0x8000418C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x8000418C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80004190: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80004194: addiu       $s4, $s4, 0x7E7C
    ctx->r20 = ADD32(ctx->r20, 0X7E7C);
    // 0x80004198: jal         0x80003DC0
    // 0x8000419C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    Graphics_InitializeTask(rdram, ctx);
        goto after_2;
    // 0x8000419C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_2:
    // 0x800041A0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800041A4: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800041A8: addiu       $s5, $s5, 0x7E60
    ctx->r21 = ADD32(ctx->r21, 0X7E60);
    // 0x800041AC: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x800041B0: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
    // 0x800041B4: lui         $t7, 0xBC00
    ctx->r15 = S32(0XBC00 << 16);
    // 0x800041B8: ori         $t7, $t7, 0x6
    ctx->r15 = ctx->r15 | 0X6;
    // 0x800041BC: addiu       $t6, $s1, 0x8
    ctx->r14 = ADD32(ctx->r17, 0X8);
    // 0x800041C0: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x800041C4: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x800041C8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800041CC: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800041D0: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800041D4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800041D8: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800041DC: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800041E0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800041E4: lw          $t3, 0x7E50($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7E50);
    // 0x800041E8: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800041EC: ori         $at, $at, 0x2150
    ctx->r1 = ctx->r1 | 0X2150;
    // 0x800041F0: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x800041F4: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800041F8: jal         0x800A26C0
    // 0x800041FC: nop

    Game_Update(rdram, ctx);
        goto after_3;
    // 0x800041FC: nop

    after_3:
    // 0x80004200: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80004204: addiu       $s7, $s7, 0x7E68
    ctx->r23 = ADD32(ctx->r23, 0X7E68);
    // 0x80004208: lui         $s6, 0xB800
    ctx->r22 = S32(0XB800 << 16);
    // 0x8000420C: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
    // 0x80004210: addiu       $t5, $s1, 0x8
    ctx->r13 = ADD32(ctx->r17, 0X8);
    // 0x80004214: sw          $t5, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r13;
    // 0x80004218: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8000421C: sw          $s6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r22;
    // 0x80004220: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x80004224: addiu       $t6, $t2, 0x8
    ctx->r14 = ADD32(ctx->r10, 0X8);
    // 0x80004228: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x8000422C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x80004230: sw          $s6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r22;
    // 0x80004234: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80004238: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8000423C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80004240: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80004244: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80004248: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8000424C: lw          $t9, 0x7E50($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7E50);
    // 0x80004250: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80004254: ori         $at, $at, 0xC950
    ctx->r1 = ctx->r1 | 0XC950;
    // 0x80004258: addu        $t3, $t9, $at
    ctx->r11 = ADD32(ctx->r25, ctx->r1);
    // 0x8000425C: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80004260: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80004264: lui         $t5, 0xE900
    ctx->r13 = S32(0XE900 << 16);
    // 0x80004268: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x8000426C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80004270: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80004274: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80004278: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8000427C: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80004280: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80004284: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80004288: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x8000428C: jal         0x80003C50
    // 0x80004290: nop

    Graphics_SetTask(rdram, ctx);
        goto after_4;
    // 0x80004290: nop

    after_4:
    // 0x80004294: lui         $fp, 0x8039
    ctx->r30 = S32(0X8039 << 16);
    // 0x80004298: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8000429C: addiu       $s2, $s2, 0x2278
    ctx->r18 = ADD32(ctx->r18, 0X2278);
    // 0x800042A0: addiu       $fp, $fp, -0x800
    ctx->r30 = ADD32(ctx->r30, -0X800);
    // 0x800042A4: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
L_800042A8:
    // 0x800042A8: addiu       $a0, $t7, 0x1
    ctx->r4 = ADD32(ctx->r15, 0X1);
    // 0x800042AC: jal         0x80003DC0
    // 0x800042B0: sw          $a0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r4;
    Graphics_InitializeTask(rdram, ctx);
        goto after_5;
    // 0x800042B0: sw          $a0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r4;
    after_5:
    // 0x800042B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800042B8: addiu       $a0, $a0, 0x22F8
    ctx->r4 = ADD32(ctx->r4, 0X22F8);
    // 0x800042BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800042C0: jal         0x800205E0
    // 0x800042C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x800042C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x800042C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800042CC: addiu       $a0, $a0, 0x22C0
    ctx->r4 = ADD32(ctx->r4, 0X22C0);
    // 0x800042D0: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x800042D4: jal         0x80020720
    // 0x800042D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800042D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x800042DC: jal         0x800029A8
    // 0x800042E0: nop

    Controller_UpdateInput(rdram, ctx);
        goto after_8;
    // 0x800042E0: nop

    after_8:
    // 0x800042E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800042E8: addiu       $a0, $a0, 0x22C0
    ctx->r4 = ADD32(ctx->r4, 0X22C0);
    // 0x800042EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800042F0: jal         0x80020720
    // 0x800042F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_9;
    // 0x800042F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x800042F8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800042FC: lhu         $t9, -0x2756($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2756);
    // 0x80004300: andi        $t3, $t9, 0x800
    ctx->r11 = ctx->r25 & 0X800;
    // 0x80004304: beql        $t3, $zero, L_80004318
    if (ctx->r11 == 0) {
        // 0x80004308: lw          $s1, 0x0($s5)
        ctx->r17 = MEM_W(ctx->r21, 0X0);
            goto L_80004318;
    }
    goto skip_0;
    // 0x80004308: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
    skip_0:
    // 0x8000430C: jal         0x80003EE0
    // 0x80004310: nop

    Main_SetVIMode(rdram, ctx);
        goto after_10;
    // 0x80004310: nop

    after_10:
    // 0x80004314: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
L_80004318:
    // 0x80004318: lui         $t5, 0xBC00
    ctx->r13 = S32(0XBC00 << 16);
    // 0x8000431C: ori         $t5, $t5, 0x6
    ctx->r13 = ctx->r13 | 0X6;
    // 0x80004320: addiu       $t4, $s1, 0x8
    ctx->r12 = ADD32(ctx->r17, 0X8);
    // 0x80004324: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x80004328: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8000432C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80004330: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80004334: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80004338: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8000433C: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80004340: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80004344: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80004348: lw          $t8, 0x7E50($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7E50);
    // 0x8000434C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80004350: ori         $at, $at, 0x2150
    ctx->r1 = ctx->r1 | 0X2150;
    // 0x80004354: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80004358: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8000435C: jal         0x800A26C0
    // 0x80004360: nop

    Game_Update(rdram, ctx);
        goto after_11;
    // 0x80004360: nop

    after_11:
    // 0x80004364: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80004368: lbu         $t3, 0x7E80($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7E80);
    // 0x8000436C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80004370: bnel        $t3, $at, L_80004384
    if (ctx->r11 != ctx->r1) {
        // 0x80004374: lw          $s1, 0x0($s5)
        ctx->r17 = MEM_W(ctx->r21, 0X0);
            goto L_80004384;
    }
    goto skip_1;
    // 0x80004374: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
    skip_1:
    // 0x80004378: jal         0x800BC4B0
    // 0x8000437C: nop

    Graphics_NMIWipe(rdram, ctx);
        goto after_12;
    // 0x8000437C: nop

    after_12:
    // 0x80004380: lw          $s1, 0x0($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X0);
L_80004384:
    // 0x80004384: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004388: addiu       $a0, $a0, 0x22A0
    ctx->r4 = ADD32(ctx->r4, 0X22A0);
    // 0x8000438C: addiu       $t4, $s1, 0x8
    ctx->r12 = ADD32(ctx->r17, 0X8);
    // 0x80004390: sw          $t4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r12;
    // 0x80004394: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x80004398: sw          $s6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r22;
    // 0x8000439C: lw          $t2, 0x0($s7)
    ctx->r10 = MEM_W(ctx->r23, 0X0);
    // 0x800043A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800043A4: addiu       $t5, $t2, 0x8
    ctx->r13 = ADD32(ctx->r10, 0X8);
    // 0x800043A8: sw          $t5, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r13;
    // 0x800043AC: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800043B0: sw          $s6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r22;
    // 0x800043B4: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800043B8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800043BC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800043C0: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800043C4: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x800043C8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800043CC: lw          $t8, 0x7E50($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7E50);
    // 0x800043D0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800043D4: ori         $at, $at, 0xC950
    ctx->r1 = ctx->r1 | 0XC950;
    // 0x800043D8: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800043DC: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800043E0: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800043E4: lui         $t4, 0xE900
    ctx->r12 = S32(0XE900 << 16);
    // 0x800043E8: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800043EC: sw          $t3, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r11;
    // 0x800043F0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800043F4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800043F8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x800043FC: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80004400: sw          $t5, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r13;
    // 0x80004404: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80004408: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x8000440C: jal         0x800205E0
    // 0x80004410: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_13;
    // 0x80004410: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x80004414: jal         0x80003C50
    // 0x80004418: nop

    Graphics_SetTask(rdram, ctx);
        goto after_14;
    // 0x80004418: nop

    after_14:
    // 0x8000441C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80004420: lhu         $t6, 0x7E8A($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7E8A);
    // 0x80004424: bnel        $t6, $zero, L_80004468
    if (ctx->r14 != 0) {
        // 0x80004428: lw          $t4, 0x0($s4)
        ctx->r12 = MEM_W(ctx->r20, 0X0);
            goto L_80004468;
    }
    goto skip_2;
    // 0x80004428: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    skip_2:
    // 0x8000442C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80004430: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80004434: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80004438: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x8000443C: mfhi        $t9
    ctx->r25 = hi;
    // 0x80004440: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80004444: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x80004448: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000444C: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80004450: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80004454: subu        $t3, $t3, $t9
    ctx->r11 = SUB32(ctx->r11, ctx->r25);
    // 0x80004458: sll         $t3, $t3, 11
    ctx->r11 = S32(ctx->r11 << 11);
    // 0x8000445C: jal         0x800219A0
    // 0x80004460: addu        $a0, $fp, $t3
    ctx->r4 = ADD32(ctx->r30, ctx->r11);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_15;
    // 0x80004460: addu        $a0, $fp, $t3
    ctx->r4 = ADD32(ctx->r30, ctx->r11);
    after_15:
    // 0x80004464: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
L_80004468:
    // 0x80004468: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000446C: addiu       $a1, $zero, 0x140
    ctx->r5 = ADD32(0, 0X140);
    // 0x80004470: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80004474: divu        $zero, $t5, $at
    lo = S32(U32(ctx->r13) / U32(ctx->r1)); hi = S32(U32(ctx->r13) % U32(ctx->r1));
    // 0x80004478: mfhi        $t6
    ctx->r14 = hi;
    // 0x8000447C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80004480: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80004484: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80004488: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8000448C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80004490: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80004494: sll         $t7, $t7, 11
    ctx->r15 = S32(ctx->r15 << 11);
    // 0x80004498: addu        $a0, $fp, $t7
    ctx->r4 = ADD32(ctx->r30, ctx->r15);
    // 0x8000449C: jal         0x80007FE4
    // 0x800044A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    Fault_SetFrameBuffer(rdram, ctx);
        goto after_16;
    // 0x800044A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_16:
    // 0x800044A4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800044A8: lbu         $v0, 0x7E78($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7E78);
    // 0x800044AC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800044B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800044B4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800044B8: beq         $at, $zero, L_800044C8
    if (ctx->r1 == 0) {
        // 0x800044BC: nop
    
            goto L_800044C8;
    }
    // 0x800044BC: nop

    // 0x800044C0: b           L_800044C8
    // 0x800044C4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
        goto L_800044C8;
    // 0x800044C4: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
L_800044C8:
    // 0x800044C8: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x800044CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800044D0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800044D4: beql        $at, $zero, L_800044E8
    if (ctx->r1 == 0) {
        // 0x800044D8: andi        $v1, $a0, 0xFF
        ctx->r3 = ctx->r4 & 0XFF;
            goto L_800044E8;
    }
    goto skip_3;
    // 0x800044D8: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    skip_3:
    // 0x800044DC: b           L_800044E8
    // 0x800044E0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
        goto L_800044E8;
    // 0x800044E0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800044E4: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
L_800044E8:
    // 0x800044E8: blez        $v1, L_80004514
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800044EC: or          $s1, $v1, $zero
        ctx->r17 = ctx->r3 | 0;
            goto L_80004514;
    }
    // 0x800044EC: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800044F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800044F4:
    // 0x800044F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800044F8: jal         0x800205E0
    // 0x800044FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_17;
    // 0x800044FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80004500: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x80004504: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x80004508: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8000450C: bnel        $at, $zero, L_800044F4
    if (ctx->r1 != 0) {
        // 0x80004510: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800044F4;
    }
    goto skip_4;
    // 0x80004510: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_4:
L_80004514:
    // 0x80004514: jal         0x8001DECC
    // 0x80004518: nop

    Audio_Update(rdram, ctx);
        goto after_18;
    // 0x80004518: nop

    after_18:
    // 0x8000451C: b           L_800042A8
    // 0x80004520: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
        goto L_800042A8;
    // 0x80004520: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80004524: nop

    // 0x80004528: nop

    // 0x8000452C: nop

    // 0x80004530: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80004534: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004538: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000453C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80004540: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80004544: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004548: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000454C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80004550: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80004554: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80004558: jr          $ra
    // 0x8000455C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000455C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Play_dummy_800B41E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B41E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B41E4: jr          $ra
    // 0x800B41E8: nop

    return;
    // 0x800B41E8: nop

;}
RECOMP_FUNC void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001FA54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001FA58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001FA5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001FA60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001FA64: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8001FA68: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8001FA6C: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x8001FA70: addiu       $a0, $a0, -0x620
    ctx->r4 = ADD32(ctx->r4, -0X620);
    // 0x8001FA74: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8001FA78: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8001FA7C: jal         0x800246D0
    // 0x8001FA80: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _Printf(rdram, ctx);
        goto after_0;
    // 0x8001FA80: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x8001FA84: bltz        $v0, L_8001FA98
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FA88: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001FA98;
    }
    // 0x8001FA88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001FA8C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8001FA90: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8001FA94: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_8001FA98:
    // 0x8001FA98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001FA9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001FAA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8001FAA4: jr          $ra
    // 0x8001FAA8: nop

    return;
    // 0x8001FAA8: nop

;}
RECOMP_FUNC void HUD_PauseScreen_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088970: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80088974: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80088978: addiu       $t2, $t2, 0x1838
    ctx->r10 = ADD32(ctx->r10, 0X1838);
    // 0x8008897C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80088980: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80088984: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80088988: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8008898C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80088990: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80088994: lw          $a0, 0x7854($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7854);
    // 0x80088998: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008899C: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
    // 0x800889A0: beq         $a0, $at, L_800889D8
    if (ctx->r4 == ctx->r1) {
        // 0x800889A4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800889D8;
    }
    // 0x800889A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800889A8: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800889AC: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x800889B0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800889B4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800889B8: addu        $v0, $t0, $t8
    ctx->r2 = ADD32(ctx->r8, ctx->r24);
    // 0x800889BC: sw          $zero, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = 0;
    // 0x800889C0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800889C4: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800889C8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800889CC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800889D0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800889D4: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
L_800889D8:
    // 0x800889D8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800889DC: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
    // 0x800889E0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800889E4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800889E8: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800889EC: bne         $at, $zero, L_800889F8
    if (ctx->r1 != 0) {
        // 0x800889F0: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800889F8;
    }
    // 0x800889F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800889F4: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
L_800889F8:
    // 0x800889F8: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800889FC: bnel        $a0, $at, L_80089044
    if (ctx->r4 != ctx->r1) {
        // 0x80088A00: lw          $t8, 0xC($t0)
        ctx->r24 = MEM_W(ctx->r8, 0XC);
            goto L_80089044;
    }
    goto skip_0;
    // 0x80088A00: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    skip_0:
    // 0x80088A04: lw          $t3, 0x7838($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7838);
    // 0x80088A08: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80088A0C: bnel        $t3, $zero, L_80089044
    if (ctx->r11 != 0) {
        // 0x80088A10: lw          $t8, 0xC($t0)
        ctx->r24 = MEM_W(ctx->r8, 0XC);
            goto L_80089044;
    }
    goto skip_1;
    // 0x80088A10: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    skip_1:
    // 0x80088A14: lw          $t4, 0x78E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78E8);
    // 0x80088A18: sltiu       $at, $v0, 0xB
    ctx->r1 = ctx->r2 < 0XB ? 1 : 0;
    // 0x80088A1C: bnel        $t4, $zero, L_80089044
    if (ctx->r12 != 0) {
        // 0x80088A20: lw          $t8, 0xC($t0)
        ctx->r24 = MEM_W(ctx->r8, 0XC);
            goto L_80089044;
    }
    goto skip_2;
    // 0x80088A20: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
    skip_2:
    // 0x80088A24: beq         $at, $zero, L_80089040
    if (ctx->r1 == 0) {
        // 0x80088A28: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_80089040;
    }
    // 0x80088A28: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80088A2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80088A30: addu        $at, $at, $t5
    gpr jr_addend_80088A38 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80088A34: lw          $t5, 0x78AC($at)
    ctx->r13 = ADD32(ctx->r1, 0X78AC);
    // 0x80088A38: jr          $t5
    // 0x80088A3C: nop

    switch (jr_addend_80088A38 >> 2) {
        case 0: goto L_80088A40; break;
        case 1: goto L_80088A54; break;
        case 2: goto L_80088B34; break;
        case 3: goto L_80088C18; break;
        case 4: goto L_80088DE8; break;
        case 5: goto L_80088EAC; break;
        case 6: goto L_80089040; break;
        case 7: goto L_80089040; break;
        case 8: goto L_80089040; break;
        case 9: goto L_80089040; break;
        case 10: goto L_80089018; break;
        default: switch_error(__func__, 0x80088A38, 0x800D78AC);
    }
    // 0x80088A3C: nop

L_80088A40:
    // 0x80088A40: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80088A44: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x80088A48: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x80088A4C: b           L_80089040
    // 0x80088A50: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
        goto L_80089040;
    // 0x80088A50: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_80088A54:
    // 0x80088A54: jal         0x800886B8
    // 0x80088A58: nop

    HUD_PauseScreenInput(rdram, ctx);
        goto after_0;
    // 0x80088A58: nop

    after_0:
    // 0x80088A5C: beq         $v0, $zero, L_80088ACC
    if (ctx->r2 == 0) {
        // 0x80088A60: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_80088ACC;
    }
    // 0x80088A60: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088A64: blez        $v0, L_80088A80
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80088A68: sw          $zero, 0x1838($at)
        MEM_W(0X1838, ctx->r1) = 0;
            goto L_80088A80;
    }
    // 0x80088A68: sw          $zero, 0x1838($at)
    MEM_W(0X1838, ctx->r1) = 0;
    // 0x80088A6C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80088A70: lw          $v1, 0x1814($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1814);
    // 0x80088A74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088A78: beq         $v1, $at, L_80088A90
    if (ctx->r3 == ctx->r1) {
        // 0x80088A7C: nop
    
            goto L_80088A90;
    }
    // 0x80088A7C: nop

L_80088A80:
    // 0x80088A80: bgez        $v0, L_80088ACC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80088A84: lui         $v1, 0x8016
        ctx->r3 = S32(0X8016 << 16);
            goto L_80088ACC;
    }
    // 0x80088A84: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80088A88: lw          $v1, 0x1814($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1814);
    // 0x80088A8C: bne         $v1, $zero, L_80088ACC
    if (ctx->r3 != 0) {
        // 0x80088A90: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80088ACC;
    }
L_80088A90:
    // 0x80088A90: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80088A94: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80088A98: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80088A9C: xori        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 ^ 0X1;
    // 0x80088AA0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088AA4: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80088AA8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80088AAC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80088AB0: sw          $t7, 0x1814($at)
    MEM_W(0X1814, ctx->r1) = ctx->r15;
    // 0x80088AB4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80088AB8: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80088ABC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80088AC0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80088AC4: jal         0x80019218
    // 0x80088AC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80088AC8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
L_80088ACC:
    // 0x80088ACC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80088AD0: lw          $v1, 0x797C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X797C);
    // 0x80088AD4: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80088AD8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088ADC: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80088AE0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80088AE4: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80088AE8: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x80088AEC: beql        $t9, $zero, L_80088B00
    if (ctx->r25 == 0) {
        // 0x80088AF0: andi        $t4, $v0, 0x8000
        ctx->r12 = ctx->r2 & 0X8000;
            goto L_80088B00;
    }
    goto skip_3;
    // 0x80088AF0: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
    skip_3:
    // 0x80088AF4: sw          $t3, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r11;
    // 0x80088AF8: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80088AFC: andi        $t4, $v0, 0x8000
    ctx->r12 = ctx->r2 & 0X8000;
L_80088B00:
    // 0x80088B00: beq         $t4, $zero, L_80088B2C
    if (ctx->r12 == 0) {
        // 0x80088B04: nop
    
            goto L_80088B2C;
    }
    // 0x80088B04: nop

    // 0x80088B08: lw          $t5, 0x1814($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1814);
    // 0x80088B0C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80088B10: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80088B14: bne         $t5, $zero, L_80088B28
    if (ctx->r13 != 0) {
        // 0x80088B18: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_80088B28;
    }
    // 0x80088B18: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088B1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088B20: b           L_80088B2C
    // 0x80088B24: sw          $t6, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r14;
        goto L_80088B2C;
    // 0x80088B24: sw          $t6, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r14;
L_80088B28:
    // 0x80088B28: sw          $t7, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r15;
L_80088B2C:
    // 0x80088B2C: b           L_80089040
    // 0x80088B30: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
        goto L_80089040;
    // 0x80088B30: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
L_80088B34:
    // 0x80088B34: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80088B38: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80088B3C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80088B40: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80088B44: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80088B48: sw          $zero, 0x1C8($t8)
    MEM_W(0X1C8, ctx->r24) = 0;
    // 0x80088B4C: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80088B50: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80088B54: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80088B58: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80088B5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088B60: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80088B64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088B68: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80088B6C: sw          $t4, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r12;
    // 0x80088B70: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80088B74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088B78: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80088B7C: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x80088B80: sw          $t5, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r13;
    // 0x80088B84: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80088B88: addiu       $t7, $t6, 0x20
    ctx->r15 = ADD32(ctx->r14, 0X20);
    // 0x80088B8C: slti        $at, $t7, 0xFF
    ctx->r1 = SIGNED(ctx->r15) < 0XFF ? 1 : 0;
    // 0x80088B90: bne         $at, $zero, L_80089040
    if (ctx->r1 != 0) {
        // 0x80088B94: sw          $t7, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r15;
            goto L_80089040;
    }
    // 0x80088B94: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80088B98: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80088B9C: jal         0x8001CA24
    // 0x80088BA0: lbu         $a0, 0x1C7($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1C7);
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_2;
    // 0x80088BA0: lbu         $a0, 0x1C7($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X1C7);
    after_2:
    // 0x80088BA4: jal         0x8001AE58
    // 0x80088BA8: nop

    Audio_ClearVoice(rdram, ctx);
        goto after_3;
    // 0x80088BA8: nop

    after_3:
    // 0x80088BAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088BB0: jal         0x800A6148
    // 0x80088BB4: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    Play_ClearObjectData(rdram, ctx);
        goto after_4;
    // 0x80088BB4: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    after_4:
    // 0x80088BB8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80088BBC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088BC0: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x80088BC4: sw          $zero, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = 0;
    // 0x80088BC8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80088BCC: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x80088BD0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80088BD4: lw          $t4, 0x78A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A0);
    // 0x80088BD8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80088BDC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80088BE0: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80088BE4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80088BE8: lh          $t6, 0x1AA0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1AA0);
    // 0x80088BEC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088BF0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80088BF4: bne         $t6, $zero, L_80088C08
    if (ctx->r14 != 0) {
        // 0x80088BF8: nop
    
            goto L_80088C08;
    }
    // 0x80088BF8: nop

    // 0x80088BFC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088C00: b           L_80088C0C
    // 0x80088C04: sw          $t7, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r15;
        goto L_80088C0C;
    // 0x80088C04: sw          $t7, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r15;
L_80088C08:
    // 0x80088C08: sw          $t8, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r24;
L_80088C0C:
    // 0x80088C0C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088C10: sw          $zero, 0x183C($at)
    MEM_W(0X183C, ctx->r1) = 0;
    // 0x80088C14: sw          $zero, 0x1838($at)
    MEM_W(0X1838, ctx->r1) = 0;
L_80088C18:
    // 0x80088C18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088C1C: addiu       $t9, $zero, 0xEF
    ctx->r25 = ADD32(0, 0XEF);
    // 0x80088C20: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80088C24: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80088C28: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80088C2C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80088C30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088C34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088C38: addiu       $a3, $zero, 0x13F
    ctx->r7 = ADD32(0, 0X13F);
    // 0x80088C3C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80088C40: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80088C44: jal         0x8009F574
    // 0x80088C48: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    Graphics_FillRectangle(rdram, ctx);
        goto after_5;
    // 0x80088C48: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_5:
    // 0x80088C4C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80088C50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088C54: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x80088C58: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x80088C5C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80088C60: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80088C64: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80088C68: addiu       $t5, $t4, -0x20
    ctx->r13 = ADD32(ctx->r12, -0X20);
    // 0x80088C6C: bgtz        $t5, L_80088C78
    if (SIGNED(ctx->r13) > 0) {
        // 0x80088C70: sw          $t5, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r13;
            goto L_80088C78;
    }
    // 0x80088C70: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80088C74: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
L_80088C78:
    // 0x80088C78: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80088C7C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80088C80: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80088C84: bne         $t7, $at, L_80088CC8
    if (ctx->r15 != ctx->r1) {
        // 0x80088C88: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_80088CC8;
    }
    // 0x80088C88: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80088C8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80088C90: sw          $t8, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r24;
    // 0x80088C94: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80088C98: sw          $t9, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r25;
    // 0x80088C9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80088CA0: sw          $zero, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = 0;
    // 0x80088CA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80088CA8: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80088CAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088CB0: sh          $t3, 0x1A34($at)
    MEM_H(0X1A34, ctx->r1) = ctx->r11;
    // 0x80088CB4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088CB8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80088CBC: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x80088CC0: b           L_80089040
    // 0x80088CC4: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
        goto L_80089040;
    // 0x80088CC4: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
L_80088CC8:
    // 0x80088CC8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80088CCC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80088CD0: bne         $t4, $zero, L_80088DDC
    if (ctx->r12 != 0) {
        // 0x80088CD4: nop
    
            goto L_80088DDC;
    }
    // 0x80088CD4: nop

    // 0x80088CD8: lbu         $t5, 0x7C98($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7C98);
    // 0x80088CDC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80088CE0: addiu       $a0, $a0, 0x1838
    ctx->r4 = ADD32(ctx->r4, 0X1838);
    // 0x80088CE4: bne         $t5, $zero, L_80088D60
    if (ctx->r13 != 0) {
        // 0x80088CE8: nop
    
            goto L_80088D60;
    }
    // 0x80088CE8: nop

    // 0x80088CEC: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80088CF0: bnel        $v1, $zero, L_80088D14
    if (ctx->r3 != 0) {
        // 0x80088CF4: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80088D14;
    }
    goto skip_4;
    // 0x80088CF4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_4:
    // 0x80088CF8: jal         0x8001D520
    // 0x80088CFC: nop

    Audio_PlayDeathSequence(rdram, ctx);
        goto after_6;
    // 0x80088CFC: nop

    after_6:
    // 0x80088D00: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80088D04: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80088D08: addiu       $a0, $a0, 0x1838
    ctx->r4 = ADD32(ctx->r4, 0X1838);
    // 0x80088D0C: lw          $v1, 0x183C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X183C);
    // 0x80088D10: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_80088D14:
    // 0x80088D14: bne         $v1, $at, L_80088D40
    if (ctx->r3 != ctx->r1) {
        // 0x80088D18: addiu       $t4, $v1, 0x1
        ctx->r12 = ADD32(ctx->r3, 0X1);
            goto L_80088D40;
    }
    // 0x80088D18: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x80088D1C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80088D20: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x80088D24: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80088D28: addiu       $t8, $t8, 0x1AA0
    ctx->r24 = ADD32(ctx->r24, 0X1AA0);
    // 0x80088D2C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80088D30: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80088D34: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80088D38: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80088D3C: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_80088D40:
    // 0x80088D40: slti        $at, $t4, 0x13
    ctx->r1 = SIGNED(ctx->r12) < 0X13 ? 1 : 0;
    // 0x80088D44: bne         $at, $zero, L_80088DDC
    if (ctx->r1 != 0) {
        // 0x80088D48: sw          $t4, 0x4($a0)
        MEM_W(0X4, ctx->r4) = ctx->r12;
            goto L_80088DDC;
    }
    // 0x80088D48: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x80088D4C: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80088D50: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088D54: sw          $t6, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r14;
    // 0x80088D58: b           L_80088DDC
    // 0x80088D5C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
        goto L_80088DDC;
    // 0x80088D5C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
L_80088D60:
    // 0x80088D60: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80088D64: lw          $v1, 0x183C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X183C);
    // 0x80088D68: bnel        $v1, $zero, L_80088D84
    if (ctx->r3 != 0) {
        // 0x80088D6C: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80088D84;
    }
    goto skip_5;
    // 0x80088D6C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_5:
    // 0x80088D70: jal         0x8001D520
    // 0x80088D74: nop

    Audio_PlayDeathSequence(rdram, ctx);
        goto after_7;
    // 0x80088D74: nop

    after_7:
    // 0x80088D78: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80088D7C: lw          $v1, 0x183C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X183C);
    // 0x80088D80: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_80088D84:
    // 0x80088D84: bne         $v1, $at, L_80088DB0
    if (ctx->r3 != ctx->r1) {
        // 0x80088D88: addiu       $t5, $v1, 0x1
        ctx->r13 = ADD32(ctx->r3, 0X1);
            goto L_80088DB0;
    }
    // 0x80088D88: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80088D8C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80088D90: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x80088D94: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80088D98: addiu       $t9, $t9, 0x1AA0
    ctx->r25 = ADD32(ctx->r25, 0X1AA0);
    // 0x80088D9C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80088DA0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80088DA4: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80088DA8: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80088DAC: sh          $t4, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r12;
L_80088DB0:
    // 0x80088DB0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088DB4: sw          $t5, 0x183C($at)
    MEM_W(0X183C, ctx->r1) = ctx->r13;
    // 0x80088DB8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80088DBC: lw          $t6, 0x183C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X183C);
    // 0x80088DC0: slti        $at, $t6, 0xE
    ctx->r1 = SIGNED(ctx->r14) < 0XE ? 1 : 0;
    // 0x80088DC4: bne         $at, $zero, L_80088DDC
    if (ctx->r1 != 0) {
        // 0x80088DC8: addiu       $t7, $zero, 0x4
        ctx->r15 = ADD32(0, 0X4);
            goto L_80088DDC;
    }
    // 0x80088DC8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80088DCC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088DD0: sw          $t7, 0x1810($at)
    MEM_W(0X1810, ctx->r1) = ctx->r15;
    // 0x80088DD4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088DD8: sw          $zero, 0x183C($at)
    MEM_W(0X183C, ctx->r1) = 0;
L_80088DDC:
    // 0x80088DDC: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80088DE0: b           L_80089040
    // 0x80088DE4: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
        goto L_80089040;
    // 0x80088DE4: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
L_80088DE8:
    // 0x80088DE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088DEC: addiu       $t9, $zero, 0xEF
    ctx->r25 = ADD32(0, 0XEF);
    // 0x80088DF0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80088DF4: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80088DF8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80088DFC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80088E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088E04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088E08: addiu       $a3, $zero, 0x13F
    ctx->r7 = ADD32(0, 0X13F);
    // 0x80088E0C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80088E10: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80088E14: jal         0x8009F574
    // 0x80088E18: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    Graphics_FillRectangle(rdram, ctx);
        goto after_8;
    // 0x80088E18: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_8:
    // 0x80088E1C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80088E20: lw          $v0, 0x1838($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1838);
    // 0x80088E24: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80088E28: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80088E2C: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x80088E30: beq         $at, $zero, L_80088E44
    if (ctx->r1 == 0) {
        // 0x80088E34: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80088E44;
    }
    // 0x80088E34: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80088E38: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80088E3C: b           L_80089040
    // 0x80088E40: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
        goto L_80089040;
    // 0x80088E40: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
L_80088E44:
    // 0x80088E44: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80088E48: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80088E4C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80088E50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088E54: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80088E58: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088E5C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80088E60: sw          $t6, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r14;
    // 0x80088E64: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80088E68: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088E6C: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80088E70: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x80088E74: sw          $t7, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
    // 0x80088E78: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80088E7C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80088E80: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80088E84: addiu       $t9, $t8, 0x20
    ctx->r25 = ADD32(ctx->r24, 0X20);
    // 0x80088E88: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80088E8C: bne         $at, $zero, L_80088E98
    if (ctx->r1 != 0) {
        // 0x80088E90: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_80088E98;
    }
    // 0x80088E90: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80088E94: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80088E98:
    // 0x80088E98: slti        $at, $v0, 0xA0
    ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
    // 0x80088E9C: beq         $at, $zero, L_80088EAC
    if (ctx->r1 == 0) {
        // 0x80088EA0: nop
    
            goto L_80088EAC;
    }
    // 0x80088EA0: nop

    // 0x80088EA4: b           L_80089040
    // 0x80088EA8: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
        goto L_80089040;
    // 0x80088EA8: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
L_80088EAC:
    // 0x80088EAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80088EB0: addiu       $t5, $zero, 0xEF
    ctx->r13 = ADD32(0, 0XEF);
    // 0x80088EB4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80088EB8: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80088EBC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088EC0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80088EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80088EC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80088ECC: addiu       $a3, $zero, 0x13F
    ctx->r7 = ADD32(0, 0X13F);
    // 0x80088ED0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80088ED4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80088ED8: jal         0x8009F574
    // 0x80088EDC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    Graphics_FillRectangle(rdram, ctx);
        goto after_9;
    // 0x80088EDC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_9:
    // 0x80088EE0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80088EE4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80088EE8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80088EEC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80088EF0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80088EF4: addiu       $t0, $t0, 0x7D08
    ctx->r8 = ADD32(ctx->r8, 0X7D08);
    // 0x80088EF8: addiu       $a0, $a0, 0x7CF0
    ctx->r4 = ADD32(ctx->r4, 0X7CF0);
    // 0x80088EFC: addiu       $a2, $a2, 0x7CD0
    ctx->r6 = ADD32(ctx->r6, 0X7CD0);
    // 0x80088F00: addiu       $v0, $v0, 0x78D0
    ctx->r2 = ADD32(ctx->r2, 0X78D0);
    // 0x80088F04: addiu       $a1, $a1, 0x7C38
    ctx->r5 = ADD32(ctx->r5, 0X7C38);
    // 0x80088F08: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_80088F0C:
    // 0x80088F0C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80088F10: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80088F14: bnel        $a3, $v1, L_80088F28
    if (ctx->r7 != ctx->r3) {
        // 0x80088F18: sw          $v1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r3;
            goto L_80088F28;
    }
    goto skip_6;
    // 0x80088F18: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    skip_6:
    // 0x80088F1C: b           L_80088F28
    // 0x80088F20: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80088F28;
    // 0x80088F20: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80088F24: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
L_80088F28:
    // 0x80088F28: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80088F2C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80088F30: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80088F34: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80088F38: bne         $a0, $t0, L_80088F0C
    if (ctx->r4 != ctx->r8) {
        // 0x80088F3C: sw          $t7, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r15;
            goto L_80088F0C;
    }
    // 0x80088F3C: sw          $t7, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r15;
    // 0x80088F40: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80088F44: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x80088F48: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80088F4C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80088F50: bne         $t8, $at, L_80088F78
    if (ctx->r24 != ctx->r1) {
        // 0x80088F54: addiu       $v0, $v0, 0x7CA0
        ctx->r2 = ADD32(ctx->r2, 0X7CA0);
            goto L_80088F78;
    }
    // 0x80088F54: addiu       $v0, $v0, 0x7CA0
    ctx->r2 = ADD32(ctx->r2, 0X7CA0);
    // 0x80088F58: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80088F5C: lw          $t9, -0x6DC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6DC);
    // 0x80088F60: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80088F64: beql        $t9, $zero, L_80088F7C
    if (ctx->r25 == 0) {
        // 0x80088F68: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80088F7C;
    }
    goto skip_7;
    // 0x80088F68: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_7:
    // 0x80088F6C: lw          $t3, 0x1A5C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A5C);
    // 0x80088F70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80088F74: sw          $t3, 0x7CA4($at)
    MEM_W(0X7CA4, ctx->r1) = ctx->r11;
L_80088F78:
    // 0x80088F78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80088F7C:
    // 0x80088F7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80088F80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088F84: swc1        $f4, 0x7CB0($at)
    MEM_W(0X7CB0, ctx->r1) = ctx->f4.u32l;
    // 0x80088F88: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088F8C: sw          $zero, -0x6DC($at)
    MEM_W(-0X6DC, ctx->r1) = 0;
    // 0x80088F90: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088F94: sb          $zero, 0x1A50($at)
    MEM_B(0X1A50, ctx->r1) = 0;
    // 0x80088F98: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80088F9C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088FA0: jal         0x8001CA24
    // 0x80088FA4: sw          $zero, 0x1A9C($at)
    MEM_W(0X1A9C, ctx->r1) = 0;
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_10;
    // 0x80088FA4: sw          $zero, 0x1A9C($at)
    MEM_W(0X1A9C, ctx->r1) = 0;
    after_10:
    // 0x80088FA8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80088FAC: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80088FB0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80088FB4: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80088FB8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80088FBC: sw          $t5, 0x1C8($t6)
    MEM_W(0X1C8, ctx->r14) = ctx->r13;
    // 0x80088FC0: sh          $zero, 0x1A60($at)
    MEM_H(0X1A60, ctx->r1) = 0;
    // 0x80088FC4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80088FC8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80088FCC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80088FD0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80088FD4: sw          $zero, 0x1F8($t7)
    MEM_W(0X1F8, ctx->r15) = 0;
    // 0x80088FD8: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x80088FDC: addiu       $v1, $v1, -0x7CA8
    ctx->r3 = ADD32(ctx->r3, -0X7CA8);
    // 0x80088FE0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80088FE4: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80088FE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80088FEC: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80088FF0: sw          $t3, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r11;
    // 0x80088FF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80088FF8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80088FFC: sw          $t4, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r12;
    // 0x80089000: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80089004: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80089008: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008900C: sw          $t5, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r13;
    // 0x80089010: b           L_80089040
    // 0x80089014: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
        goto L_80089040;
    // 0x80089014: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
L_80089018:
    // 0x80089018: jal         0x8001D638
    // 0x8008901C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_PlayPauseSfx(rdram, ctx);
        goto after_11;
    // 0x8008901C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80089020: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80089024: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80089028: sw          $t6, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r14;
    // 0x8008902C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80089030: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80089034: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80089038: sw          $t7, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r15;
    // 0x8008903C: addiu       $t0, $t0, 0x1810
    ctx->r8 = ADD32(ctx->r8, 0X1810);
L_80089040:
    // 0x80089040: lw          $t8, 0xC($t0)
    ctx->r24 = MEM_W(ctx->r8, 0XC);
L_80089044:
    // 0x80089044: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80089048: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8008904C: bne         $t8, $zero, L_80089660
    if (ctx->r24 != 0) {
        // 0x80089050: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_80089660;
    }
    // 0x80089050: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80089054: lw          $t9, 0x7854($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7854);
    // 0x80089058: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8008905C: bnel        $t9, $at, L_80089664
    if (ctx->r25 != ctx->r1) {
        // 0x80089060: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80089664;
    }
    goto skip_8;
    // 0x80089060: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80089064: lw          $t3, 0x78E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78E8);
    // 0x80089068: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008906C: bnel        $t3, $zero, L_80089664
    if (ctx->r11 != 0) {
        // 0x80089070: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80089664;
    }
    goto skip_9;
    // 0x80089070: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_9:
    // 0x80089074: lw          $t4, 0x7838($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7838);
    // 0x80089078: bnel        $t4, $zero, L_80089664
    if (ctx->r12 != 0) {
        // 0x8008907C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80089664;
    }
    goto skip_10;
    // 0x8008907C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_10:
    // 0x80089080: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80089084: beq         $v0, $zero, L_800890B0
    if (ctx->r2 == 0) {
        // 0x80089088: nop
    
            goto L_800890B0;
    }
    // 0x80089088: nop

    // 0x8008908C: beq         $v0, $at, L_800890B0
    if (ctx->r2 == ctx->r1) {
        // 0x80089090: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800890B0;
    }
    // 0x80089090: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80089094: beq         $v0, $at, L_8008961C
    if (ctx->r2 == ctx->r1) {
        // 0x80089098: lui         $t7, 0x8018
        ctx->r15 = S32(0X8018 << 16);
            goto L_8008961C;
    }
    // 0x80089098: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008909C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800890A0: beq         $v0, $at, L_8008961C
    if (ctx->r2 == ctx->r1) {
        // 0x800890A4: nop
    
            goto L_8008961C;
    }
    // 0x800890A4: nop

    // 0x800890A8: b           L_80089664
    // 0x800890AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80089664;
    // 0x800890AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800890B0:
    // 0x800890B0: jal         0x800863C8
    // 0x800890B4: nop

    HUD_GetLevelIndex(rdram, ctx);
        goto after_12;
    // 0x800890B4: nop

    after_12:
    // 0x800890B8: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800890BC: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800890C0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800890C4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800890C8: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800890CC: lw          $t6, 0x1AFC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1AFC);
    // 0x800890D0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800890D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800890D8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800890DC: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x800890E0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800890E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800890E8: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x800890EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800890F0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800890F4: lui         $a2, 0x40F3
    ctx->r6 = S32(0X40F3 << 16);
    // 0x800890F8: lui         $a3, 0x4006
    ctx->r7 = S32(0X4006 << 16);
    // 0x800890FC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80089100: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80089104: lui         $at, 0x428A
    ctx->r1 = S32(0X428A << 16);
    // 0x80089108: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008910C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80089110: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80089114: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80089118: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8008911C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80089120: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80089124: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80089128: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x8008912C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    // 0x80089130: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x80089134: jal         0x80086C08
    // 0x80089138: sub.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f10.fl;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_13;
    // 0x80089138: sub.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f10.fl;
    after_13:
    // 0x8008913C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80089140: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80089144: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80089148: sltiu       $at, $t7, 0x14
    ctx->r1 = ctx->r15 < 0X14 ? 1 : 0;
    // 0x8008914C: beq         $at, $zero, L_800891C4
    if (ctx->r1 == 0) {
        // 0x80089150: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800891C4;
    }
    // 0x80089150: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80089154: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80089158: addu        $at, $at, $t7
    gpr jr_addend_80089160 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8008915C: lw          $t7, 0x78D8($at)
    ctx->r15 = ADD32(ctx->r1, 0X78D8);
    // 0x80089160: jr          $t7
    // 0x80089164: nop

    switch (jr_addend_80089160 >> 2) {
        case 0: goto L_800891C4; break;
        case 1: goto L_800891C4; break;
        case 2: goto L_80089180; break;
        case 3: goto L_800891C4; break;
        case 4: goto L_800891C4; break;
        case 5: goto L_80089180; break;
        case 6: goto L_800891C4; break;
        case 7: goto L_800891A8; break;
        case 8: goto L_800891C4; break;
        case 9: goto L_800891C4; break;
        case 10: goto L_80089168; break;
        case 11: goto L_800891C4; break;
        case 12: goto L_800891C4; break;
        case 13: goto L_80089168; break;
        case 14: goto L_800891C4; break;
        case 15: goto L_800891C4; break;
        case 16: goto L_800891C4; break;
        case 17: goto L_80089168; break;
        case 18: goto L_80089180; break;
        case 19: goto L_800891C4; break;
        default: switch_error(__func__, 0x80089160, 0x800D78D8);
    }
    // 0x80089164: nop

L_80089168:
    // 0x80089168: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8008916C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80089170: nop

    // 0x80089174: add.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80089178: b           L_800891C4
    // 0x8008917C: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
        goto L_800891C4;
    // 0x8008917C: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
L_80089180:
    // 0x80089180: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80089184: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80089188: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8008918C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80089190: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80089194: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80089198: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8008919C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800891A0: b           L_800891C4
    // 0x800891A4: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
        goto L_800891C4;
    // 0x800891A4: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
L_800891A8:
    // 0x800891A8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800891AC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800891B0: lwc1        $f10, 0x60($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800891B4: add.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800891B8: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800891BC: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x800891C0: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
L_800891C4:
    // 0x800891C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800891C8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800891CC: jal         0x800B8DD0
    // 0x800891D0: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_14;
    // 0x800891D0: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_14:
    // 0x800891D4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800891D8: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x800891DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800891E0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800891E4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800891E8: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x800891EC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800891F0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800891F4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800891F8: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x800891FC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80089200: addiu       $t6, $t6, 0x1AEC
    ctx->r14 = ADD32(ctx->r14, 0X1AEC);
    // 0x80089204: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80089208: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8008920C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x80089210: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x80089214: lw          $t7, 0x14($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X14);
    // 0x80089218: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008921C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80089220: blezl       $t7, L_800892AC
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80089224: lui         $at, 0x430C
        ctx->r1 = S32(0X430C << 16);
            goto L_800892AC;
    }
    goto skip_11;
    // 0x80089224: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    skip_11:
    // 0x80089228: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008922C: nop

    // 0x80089230: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
L_80089234:
    // 0x80089234: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80089238: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8008923C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80089240: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80089244: lw          $t9, 0xC($t0)
    ctx->r25 = MEM_W(ctx->r8, 0XC);
    // 0x80089248: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8008924C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80089250: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80089254: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80089258: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8008925C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80089260: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80089264: mflo        $t8
    ctx->r24 = lo;
    // 0x80089268: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8008926C: sw          $v1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r3;
    // 0x80089270: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80089274: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80089278: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x8008927C: jal         0x8009D994
    // 0x80089280: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_15;
    // 0x80089280: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_15:
    // 0x80089284: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80089288: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x8008928C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80089290: lw          $t3, 0x14($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X14);
    // 0x80089294: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80089298: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008929C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800892A0: bnel        $at, $zero, L_80089234
    if (ctx->r1 != 0) {
        // 0x800892A4: lw          $v0, 0x10($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X10);
            goto L_80089234;
    }
    goto skip_12;
    // 0x800892A4: lw          $v0, 0x10($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X10);
    skip_12:
    // 0x800892A8: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
L_800892AC:
    // 0x800892AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800892B0: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800892B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800892B8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800892BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800892C0: sub.s       $f2, $f18, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800892C4: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x800892C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800892CC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800892D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800892D4: sub.s       $f12, $f2, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x800892D8: lui         $a2, 0x4096
    ctx->r6 = S32(0X4096 << 16);
    // 0x800892DC: lui         $a3, 0x4033
    ctx->r7 = S32(0X4033 << 16);
    // 0x800892E0: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800892E4: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x800892E8: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x800892EC: jal         0x80086C08
    // 0x800892F0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    HUD_MsgWindowBg_Draw2(rdram, ctx);
        goto after_16;
    // 0x800892F0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_16:
    // 0x800892F4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800892F8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800892FC: jal         0x800B8DD0
    // 0x80089300: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_17;
    // 0x80089300: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_17:
    // 0x80089304: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80089308: lw          $t4, 0x1814($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1814);
    // 0x8008930C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80089310: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80089314: bne         $t4, $zero, L_80089398
    if (ctx->r12 != 0) {
        // 0x80089318: lwc1        $f2, 0x30($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80089398;
    }
    // 0x80089318: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008931C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80089320: lw          $v1, 0x1838($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1838);
    // 0x80089324: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80089328: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8008932C: div         $zero, $v1, $at
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r1)));
    // 0x80089330: mfhi        $t5
    ctx->r13 = hi;
    // 0x80089334: slti        $at, $t5, 0xA
    ctx->r1 = SIGNED(ctx->r13) < 0XA ? 1 : 0;
    // 0x80089338: bne         $at, $zero, L_80089348
    if (ctx->r1 != 0) {
        // 0x8008933C: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_80089348;
    }
    // 0x8008933C: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x80089340: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80089344: subu        $v1, $t6, $t5
    ctx->r3 = SUB32(ctx->r14, ctx->r13);
L_80089348:
    // 0x80089348: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8008934C: addiu       $v1, $t7, -0x1
    ctx->r3 = ADD32(ctx->r15, -0X1);
    // 0x80089350: bgez        $v1, L_8008935C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80089354: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_8008935C;
    }
    // 0x80089354: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80089358: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8008935C:
    // 0x8008935C: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x80089360: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x80089364: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80089368: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8008936C: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x80089370: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x80089374: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80089378: sll         $t5, $a1, 8
    ctx->r13 = S32(ctx->r5 << 8);
    // 0x8008937C: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80089380: ori         $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 | 0XFF;
    // 0x80089384: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80089388: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008938C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80089390: b           L_800893C4
    // 0x80089394: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
        goto L_800893C4;
    // 0x80089394: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
L_80089398:
    // 0x80089398: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8008939C: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x800893A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800893A4: lui         $t3, 0x4040
    ctx->r11 = S32(0X4040 << 16);
    // 0x800893A8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800893AC: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x800893B0: ori         $t3, $t3, 0x40FF
    ctx->r11 = ctx->r11 | 0X40FF;
    // 0x800893B4: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800893B8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800893BC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800893C0: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
L_800893C4:
    // 0x800893C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800893C8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800893CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800893D0: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x800893D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800893D8: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800893DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800893E0: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x800893E4: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x800893E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800893EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800893F0: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800893F4: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800893F8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800893FC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80089400: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80089404: jal         0x8009D994
    // 0x80089408: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_18;
    // 0x80089408: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x8008940C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80089410: lw          $t4, 0x1814($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1814);
    // 0x80089414: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80089418: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8008941C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089420: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80089424: bne         $t4, $at, L_800894C4
    if (ctx->r12 != ctx->r1) {
        // 0x80089428: lwc1        $f2, 0x30($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
            goto L_800894C4;
    }
    // 0x80089428: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8008942C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80089430: lw          $t5, 0x1838($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1838);
    // 0x80089434: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80089438: div         $zero, $t5, $v0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r2)));
    // 0x8008943C: bne         $v0, $zero, L_80089448
    if (ctx->r2 != 0) {
        // 0x80089440: nop
    
            goto L_80089448;
    }
    // 0x80089440: nop

    // 0x80089444: break       7
    do_break(2148045892);
L_80089448:
    // 0x80089448: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008944C: bne         $v0, $at, L_80089460
    if (ctx->r2 != ctx->r1) {
        // 0x80089450: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80089460;
    }
    // 0x80089450: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80089454: bne         $t5, $at, L_80089460
    if (ctx->r13 != ctx->r1) {
        // 0x80089458: nop
    
            goto L_80089460;
    }
    // 0x80089458: nop

    // 0x8008945C: break       6
    do_break(2148045916);
L_80089460:
    // 0x80089460: mfhi        $v1
    ctx->r3 = hi;
    // 0x80089464: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x80089468: bnel        $at, $zero, L_80089478
    if (ctx->r1 != 0) {
        // 0x8008946C: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_80089478;
    }
    goto skip_13;
    // 0x8008946C: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    skip_13:
    // 0x80089470: subu        $v1, $v0, $v1
    ctx->r3 = SUB32(ctx->r2, ctx->r3);
    // 0x80089474: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
L_80089478:
    // 0x80089478: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x8008947C: bgez        $v1, L_80089488
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80089480: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80089488;
    }
    // 0x80089480: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80089484: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80089488:
    // 0x80089488: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x8008948C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80089490: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x80089494: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80089498: sw          $t7, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r15;
    // 0x8008949C: lui         $at, 0xA000
    ctx->r1 = S32(0XA000 << 16);
    // 0x800894A0: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x800894A4: or          $t3, $t9, $at
    ctx->r11 = ctx->r25 | ctx->r1;
    // 0x800894A8: sll         $t4, $a1, 8
    ctx->r12 = S32(ctx->r5 << 8);
    // 0x800894AC: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800894B0: ori         $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 | 0XFF;
    // 0x800894B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800894B8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800894BC: b           L_800894EC
    // 0x800894C0: nop

        goto L_800894EC;
    // 0x800894C0: nop

L_800894C4:
    // 0x800894C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800894C8: lw          $v0, 0x7E64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7E64);
    // 0x800894CC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800894D0: lui         $t9, 0x4040
    ctx->r25 = S32(0X4040 << 16);
    // 0x800894D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800894D8: sw          $t7, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r15;
    // 0x800894DC: ori         $t9, $t9, 0x40FF
    ctx->r25 = ctx->r25 | 0X40FF;
    // 0x800894E0: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800894E4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800894E8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_800894EC:
    // 0x800894EC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800894F0: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x800894F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800894F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800894FC: bne         $t3, $at, L_80089548
    if (ctx->r11 != ctx->r1) {
        // 0x80089500: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_80089548;
    }
    // 0x80089500: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80089504: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x80089508: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008950C: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80089510: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80089514: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80089518: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x8008951C: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80089520: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80089524: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80089528: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8008952C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80089530: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80089534: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80089538: jal         0x8009D994
    // 0x8008953C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_19;
    // 0x8008953C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x80089540: b           L_800895E8
    // 0x80089544: nop

        goto L_800895E8;
    // 0x80089544: nop

L_80089548:
    // 0x80089548: lw          $t4, 0x78A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78A0);
    // 0x8008954C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80089550: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80089554: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80089558: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8008955C: lh          $t6, 0x1AA0($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X1AA0);
    // 0x80089560: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x80089564: addiu       $a1, $a1, 0x640
    ctx->r5 = ADD32(ctx->r5, 0X640);
    // 0x80089568: beq         $t6, $zero, L_800895B8
    if (ctx->r14 == 0) {
        // 0x8008956C: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_800895B8;
    }
    // 0x8008956C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80089570: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x80089574: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80089578: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8008957C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80089580: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80089584: lui         $a1, 0x100
    ctx->r5 = S32(0X100 << 16);
    // 0x80089588: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8008958C: addiu       $a1, $a1, 0x280
    ctx->r5 = ADD32(ctx->r5, 0X280);
    // 0x80089590: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80089594: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80089598: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8008959C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x800895A0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800895A4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800895A8: jal         0x8009D994
    // 0x800895AC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_20;
    // 0x800895AC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x800895B0: b           L_800895E8
    // 0x800895B4: nop

        goto L_800895E8;
    // 0x800895B4: nop

L_800895B8:
    // 0x800895B8: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x800895BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800895C0: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800895C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800895C8: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800895CC: addiu       $a3, $zero, 0x16
    ctx->r7 = ADD32(0, 0X16);
    // 0x800895D0: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800895D4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800895D8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800895DC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800895E0: jal         0x8009D994
    // 0x800895E4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_21;
    // 0x800895E4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_21:
L_800895E8:
    // 0x800895E8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800895EC: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800895F0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800895F4: beq         $v0, $at, L_80089660
    if (ctx->r2 == ctx->r1) {
        // 0x800895F8: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80089660;
    }
    // 0x800895F8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800895FC: beql        $v0, $at, L_80089664
    if (ctx->r2 == ctx->r1) {
        // 0x80089600: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80089664;
    }
    goto skip_14;
    // 0x80089600: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
    // 0x80089604: jal         0x80087788
    // 0x80089608: nop

    HUD_TeammateStatus_Draw(rdram, ctx);
        goto after_22;
    // 0x80089608: nop

    after_22:
    // 0x8008960C: jal         0x80084B94
    // 0x80089610: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    HUD_TeamDownWrench_Draw(rdram, ctx);
        goto after_23;
    // 0x80089610: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x80089614: b           L_80089664
    // 0x80089618: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80089664;
    // 0x80089618: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8008961C:
    // 0x8008961C: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80089620: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80089624: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80089628: beq         $t7, $at, L_80089660
    if (ctx->r15 == ctx->r1) {
        // 0x8008962C: lui         $a2, 0x8016
        ctx->r6 = S32(0X8016 << 16);
            goto L_80089660;
    }
    // 0x8008962C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80089630: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x80089634: lui         $at, 0x4304
    ctx->r1 = S32(0X4304 << 16);
    // 0x80089638: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008963C: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x80089640: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80089644: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x80089648: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008964C: jal         0x80084930
    // 0x80089650: lh          $a2, 0x1AA0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1AA0);
    HUD_LivesCount1_Draw(rdram, ctx);
        goto after_24;
    // 0x80089650: lh          $a2, 0x1AA0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1AA0);
    after_24:
    // 0x80089654: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80089658: jal         0x80088784
    // 0x8008965C: lw          $a0, 0x183C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X183C);
    HUD_LoseLifeExplosion_Draw(rdram, ctx);
        goto after_25;
    // 0x8008965C: lw          $a0, 0x183C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X183C);
    after_25:
L_80089660:
    // 0x80089660: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80089664:
    // 0x80089664: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80089668: jr          $ra
    // 0x8008966C: nop

    return;
    // 0x8008966C: nop

;}
RECOMP_FUNC void MeteoBall_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AC08: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006AC0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006AC10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006AC14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006AC18: jal         0x8006ABA4
    // 0x8006AC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    MeteoBall_IsCloseToPlayer(rdram, ctx);
        goto after_0;
    // 0x8006AC1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006AC20: beq         $v0, $zero, L_8006AC78
    if (ctx->r2 == 0) {
        // 0x8006AC24: nop
    
            goto L_8006AC78;
    }
    // 0x8006AC24: nop

    // 0x8006AC28: lhu         $t6, 0xBC($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XBC);
    // 0x8006AC2C: addiu       $a0, $zero, 0x161
    ctx->r4 = ADD32(0, 0X161);
    // 0x8006AC30: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8006AC34: bne         $t6, $zero, L_8006AC78
    if (ctx->r14 != 0) {
        // 0x8006AC38: nop
    
            goto L_8006AC78;
    }
    // 0x8006AC38: nop

    // 0x8006AC3C: lhu         $t7, 0x7828($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X7828);
    // 0x8006AC40: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8006AC44: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8006AC48: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8006AC4C: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8006AC50: bgez        $t7, L_8006AC68
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8006AC54: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8006AC68;
    }
    // 0x8006AC54: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006AC58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8006AC5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8006AC60: nop

    // 0x8006AC64: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8006AC68:
    // 0x8006AC68: jal         0x8007F11C
    // 0x8006AC6C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Effect_ShootAtPlayer(rdram, ctx);
        goto after_1;
    // 0x8006AC6C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8006AC70: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8006AC74: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
L_8006AC78:
    // 0x8006AC78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8006AC7C: lwc1        $f18, 0x7D20($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8006AC80: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006AC84: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006AC88: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006AC8C: add.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8006AC90: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006AC94: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8006AC98: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8006AC9C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8006ACA0: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8006ACA4: jal         0x80005100
    // 0x8006ACA8: sub.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f0.fl;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x8006ACA8: sub.s       $f14, $f6, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f0.fl;
    after_2:
    // 0x8006ACAC: jal         0x8009F768
    // 0x8006ACB0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x8006ACB0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x8006ACB4: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8006ACB8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006ACBC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006ACC0: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006ACC4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006ACC8: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8006ACCC: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8006ACD0: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8006ACD4: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8006ACD8: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8006ACDC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006ACE0: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006ACE4: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8006ACE8: sub.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8006ACEC: add.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006ACF0: jal         0x80005100
    // 0x8006ACF4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_4;
    // 0x8006ACF4: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_4:
    // 0x8006ACF8: jal         0x8009F768
    // 0x8006ACFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_5;
    // 0x8006ACFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x8006AD00: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8006AD04: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x8006AD08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006AD0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006AD10: jr          $ra
    // 0x8006AD14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006AD14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Aquas_Effect363_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094BBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80094BC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094BC4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80094BC8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80094BCC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80094BD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80094BD4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80094BD8: lw          $t6, 0x1C8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C8);
    // 0x80094BDC: bnel        $t6, $at, L_80094CA4
    if (ctx->r14 != ctx->r1) {
        // 0x80094BE0: lwc1        $f12, 0x70($a2)
        ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
            goto L_80094CA4;
    }
    goto skip_0;
    // 0x80094BE0: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    skip_0:
    // 0x80094BE4: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x80094BE8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80094BEC: bnel        $t7, $at, L_80094CA4
    if (ctx->r15 != ctx->r1) {
        // 0x80094BF0: lwc1        $f12, 0x70($a2)
        ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
            goto L_80094CA4;
    }
    goto skip_1;
    // 0x80094BF0: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    skip_1:
    // 0x80094BF4: lw          $t8, 0x1D0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1D0);
    // 0x80094BF8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80094BFC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80094C00: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80094C04: beq         $at, $zero, L_80094CA0
    if (ctx->r1 == 0) {
        // 0x80094C08: addiu       $a1, $zero, 0x44
        ctx->r5 = ADD32(0, 0X44);
            goto L_80094CA0;
    }
    // 0x80094C08: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x80094C0C: jal         0x800B8DD0
    // 0x80094C10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80094C10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80094C14: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80094C18: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80094C1C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80094C20: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80094C24: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80094C28: lui         $at, 0x15
    ctx->r1 = S32(0X15 << 16);
    // 0x80094C2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80094C30: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80094C34: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80094C38: lh          $t1, 0x4A($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X4A);
    // 0x80094C3C: ori         $at, $at, 0x2200
    ctx->r1 = ctx->r1 | 0X2200;
    // 0x80094C40: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x80094C44: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80094C48: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80094C4C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80094C50: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80094C54: addiu       $t6, $zero, -0x500
    ctx->r14 = ADD32(0, -0X500);
    // 0x80094C58: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80094C5C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80094C60: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80094C64: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80094C68: jal         0x8005980C
    // 0x80094C6C: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_1;
    // 0x80094C6C: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
    after_1:
    // 0x80094C70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80094C74: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80094C78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80094C7C: lui         $t9, 0x102
    ctx->r25 = S32(0X102 << 16);
    // 0x80094C80: addiu       $t9, $t9, 0x3750
    ctx->r25 = ADD32(ctx->r25, 0X3750);
    // 0x80094C84: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80094C88: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80094C8C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80094C90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80094C94: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80094C98: b           L_80094D04
    // 0x80094C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80094D04;
    // 0x80094C9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094CA0:
    // 0x80094CA0: lwc1        $f12, 0x70($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X70);
L_80094CA4:
    // 0x80094CA4: jal         0x8005980C
    // 0x80094CA8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_2;
    // 0x80094CA8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80094CAC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80094CB0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80094CB4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80094CB8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80094CBC: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80094CC0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80094CC4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80094CC8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80094CCC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80094CD0: lh          $t2, 0x4A($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X4A);
    // 0x80094CD4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x80094CD8: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x80094CDC: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80094CE0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80094CE4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80094CE8: lui         $t7, 0x102
    ctx->r15 = S32(0X102 << 16);
    // 0x80094CEC: addiu       $t7, $t7, 0x3750
    ctx->r15 = ADD32(ctx->r15, 0X3750);
    // 0x80094CF0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80094CF4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80094CF8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80094CFC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80094D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80094D04:
    // 0x80094D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80094D08: jr          $ra
    // 0x80094D0C: nop

    return;
    // 0x80094D0C: nop

;}
RECOMP_FUNC void Game_SetScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A25DC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A25E0: lw          $t6, 0x7834($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7834);
    // 0x800A25E4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800A25E8: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x800A25EC: beq         $at, $zero, L_800A26B8
    if (ctx->r1 == 0) {
        // 0x800A25F0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800A26B8;
    }
    // 0x800A25F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A25F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A25F8: addu        $at, $at, $t7
    gpr jr_addend_800A2600 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800A25FC: lw          $t7, -0x7D8C($at)
    ctx->r15 = ADD32(ctx->r1, -0X7D8C);
    // 0x800A2600: jr          $t7
    // 0x800A2604: nop

    switch (jr_addend_800A2600 >> 2) {
        case 0: goto L_800A2608; break;
        case 1: goto L_800A261C; break;
        case 2: goto L_800A2630; break;
        case 3: goto L_800A2648; break;
        case 4: goto L_800A2694; break;
        case 5: goto L_800A2660; break;
        case 6: goto L_800A2670; break;
        case 7: goto L_800A26AC; break;
        default: switch_error(__func__, 0x800A2600, 0x800D8274);
    }
    // 0x800A2604: nop

L_800A2608:
    // 0x800A2608: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A260C: sw          $zero, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = 0;
    // 0x800A2610: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2614: jr          $ra
    // 0x800A2618: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    return;
    // 0x800A2618: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
L_800A261C:
    // 0x800A261C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2620: sw          $zero, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = 0;
    // 0x800A2624: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2628: jr          $ra
    // 0x800A262C: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    return;
    // 0x800A262C: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
L_800A2630:
    // 0x800A2630: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A2634: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2638: sw          $t8, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r24;
    // 0x800A263C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2640: jr          $ra
    // 0x800A2644: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    return;
    // 0x800A2644: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
L_800A2648:
    // 0x800A2648: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800A264C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2650: sw          $t9, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r25;
    // 0x800A2654: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2658: jr          $ra
    // 0x800A265C: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    return;
    // 0x800A265C: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
L_800A2660:
    // 0x800A2660: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x800A2664: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2668: jr          $ra
    // 0x800A266C: sw          $t0, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r8;
    return;
    // 0x800A266C: sw          $t0, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r8;
L_800A2670:
    // 0x800A2670: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800A2674: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x800A2678: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800A267C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A2680: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A2684: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A2688: lw          $t3, 0x28B4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X28B4);
    // 0x800A268C: jr          $ra
    // 0x800A2690: sw          $t3, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r11;
    return;
    // 0x800A2690: sw          $t3, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r11;
L_800A2694:
    // 0x800A2694: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800A2698: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A269C: sw          $t4, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r12;
    // 0x800A26A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A26A4: jr          $ra
    // 0x800A26A8: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
    return;
    // 0x800A26A8: sw          $zero, 0x7820($at)
    MEM_W(0X7820, ctx->r1) = 0;
L_800A26AC:
    // 0x800A26AC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800A26B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A26B4: sw          $t5, 0x74F8($at)
    MEM_W(0X74F8, ctx->r1) = ctx->r13;
L_800A26B8:
    // 0x800A26B8: jr          $ra
    // 0x800A26BC: nop

    return;
    // 0x800A26BC: nop

;}
RECOMP_FUNC void Player_RepairWings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067A40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067A44: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80067A48: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80067A4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80067A50: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80067A54: lw          $a1, -0x7D80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D80);
    // 0x80067A58: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80067A5C: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x80067A60: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80067A64: ori         $a0, $a0, 0x8023
    ctx->r4 = ctx->r4 | 0X8023;
    // 0x80067A68: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80067A6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80067A70: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80067A74: jal         0x80019218
    // 0x80067A78: addiu       $a1, $a1, 0x460
    ctx->r5 = ADD32(ctx->r5, 0X460);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80067A78: addiu       $a1, $a1, 0x460
    ctx->r5 = ADD32(ctx->r5, 0X460);
    after_0:
    // 0x80067A7C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80067A80: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80067A84: addiu       $t8, $zero, 0x41A
    ctx->r24 = ADD32(0, 0X41A);
    // 0x80067A88: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80067A8C: lbu         $t7, 0x49C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49C);
    // 0x80067A90: addiu       $t1, $zero, 0x41A
    ctx->r9 = ADD32(0, 0X41A);
    // 0x80067A94: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80067A98: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80067A9C: beq         $at, $zero, L_80067AB8
    if (ctx->r1 == 0) {
        // 0x80067AA0: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_80067AB8;
    }
    // 0x80067AA0: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80067AA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067AA8: sw          $t8, 0x7D40($at)
    MEM_W(0X7D40, ctx->r1) = ctx->r24;
    // 0x80067AAC: sb          $t9, 0x49C($v0)
    MEM_B(0X49C, ctx->r2) = ctx->r25;
    // 0x80067AB0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80067AB4: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
L_80067AB8:
    // 0x80067AB8: lbu         $t0, 0x49D($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X49D);
    // 0x80067ABC: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80067AC0: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80067AC4: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x80067AC8: beq         $at, $zero, L_80067AD8
    if (ctx->r1 == 0) {
        // 0x80067ACC: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80067AD8;
    }
    // 0x80067ACC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067AD0: sw          $t1, 0x7D58($at)
    MEM_W(0X7D58, ctx->r1) = ctx->r9;
    // 0x80067AD4: sb          $t2, 0x49D($v0)
    MEM_B(0X49D, ctx->r2) = ctx->r10;
L_80067AD8:
    // 0x80067AD8: lw          $t3, 0x79F8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X79F8);
    // 0x80067ADC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80067AE0: addiu       $v0, $v0, 0x7D28
    ctx->r2 = ADD32(ctx->r2, 0X7D28);
    // 0x80067AE4: beq         $t3, $zero, L_80067B04
    if (ctx->r11 == 0) {
        // 0x80067AE8: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80067B04;
    }
    // 0x80067AE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067AEC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80067AF0: addiu       $v0, $v0, 0x7D28
    ctx->r2 = ADD32(ctx->r2, 0X7D28);
    // 0x80067AF4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80067AF8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80067AFC: b           L_80067B0C
    // 0x80067B00: sw          $t4, 0x7D10($at)
    MEM_W(0X7D10, ctx->r1) = ctx->r12;
        goto L_80067B0C;
    // 0x80067B00: sw          $t4, 0x7D10($at)
    MEM_W(0X7D10, ctx->r1) = ctx->r12;
L_80067B04:
    // 0x80067B04: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80067B08: sw          $t6, 0x7D10($at)
    MEM_W(0X7D10, ctx->r1) = ctx->r14;
L_80067B0C:
    // 0x80067B0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80067B10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067B14: jr          $ra
    // 0x80067B18: nop

    return;
    // 0x80067B18: nop

;}
RECOMP_FUNC void Boss_SpawnDebris(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800430DC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800430E0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800430E4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800430E8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800430EC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800430F0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800430F4: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x800430F8: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x800430FC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80043100:
    // 0x80043100: bnel        $t6, $zero, L_8004316C
    if (ctx->r14 != 0) {
        // 0x80043104: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_8004316C;
    }
    goto skip_0;
    // 0x80043104: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_0:
    // 0x80043108: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8004310C: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80043110: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80043114: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80043118: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8004311C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80043120: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80043124: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80043128: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8004312C: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80043130: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80043134: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80043138: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8004313C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80043140: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80043144: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80043148: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8004314C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80043150: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    // 0x80043154: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80043158: jal         0x80042FF4
    // 0x8004315C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    Boss_SetupDebris(rdram, ctx);
        goto after_0;
    // 0x8004315C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    after_0:
    // 0x80043160: b           L_8004317C
    // 0x80043164: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8004317C;
    // 0x80043164: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80043168: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_8004316C:
    // 0x8004316C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80043170: beql        $at, $zero, L_80043100
    if (ctx->r1 == 0) {
        // 0x80043174: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80043100;
    }
    goto skip_1;
    // 0x80043174: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80043178: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8004317C:
    // 0x8004317C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80043180: jr          $ra
    // 0x80043184: nop

    return;
    // 0x80043184: nop

;}
RECOMP_FUNC void Math_RadToDeg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F768: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8009F76C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009F770: lwc1        $f4, -0x7DB4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7DB4);
    // 0x8009F774: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8009F778: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8009F77C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8009F780: nop

    // 0x8009F784: bc1fl       L_8009F7AC
    if (!c1cs) {
        // 0x8009F788: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8009F7AC;
    }
    goto skip_0;
    // 0x8009F788: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x8009F78C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009F790: nop

    // 0x8009F794: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
L_8009F798:
    // 0x8009F798: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8009F79C: nop

    // 0x8009F7A0: bc1tl       L_8009F798
    if (c1cs) {
        // 0x8009F7A4: add.s       $f12, $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
            goto L_8009F798;
    }
    goto skip_1;
    // 0x8009F7A4: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    skip_1:
    // 0x8009F7A8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8009F7AC:
    // 0x8009F7AC: jr          $ra
    // 0x8009F7B0: nop

    return;
    // 0x8009F7B0: nop

;}
RECOMP_FUNC void Load_SceneFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058C48: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80058C4C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80058C50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80058C54: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80058C58: lui         $fp, 0x800D
    ctx->r30 = S32(0X800D << 16);
    // 0x80058C5C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80058C60: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80058C64: addiu       $fp, $fp, -0x422C
    ctx->r30 = ADD32(ctx->r30, -0X422C);
    // 0x80058C68: addiu       $s0, $s0, 0x7520
    ctx->r16 = ADD32(ctx->r16, 0X7520);
    // 0x80058C6C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80058C70: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80058C74: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80058C78: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80058C7C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80058C80: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80058C84: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80058C88: sb          $zero, 0x42($sp)
    MEM_B(0X42, ctx->r29) = 0;
    // 0x80058C8C: lw          $a3, 0x0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X0);
    // 0x80058C90: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80058C94: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x80058C98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80058C9C: bnel        $a3, $t6, L_80058CC8
    if (ctx->r7 != ctx->r14) {
        // 0x80058CA0: sw          $a3, 0x0($fp)
        MEM_W(0X0, ctx->r30) = ctx->r7;
            goto L_80058CC8;
    }
    goto skip_0;
    // 0x80058CA0: sw          $a3, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r7;
    skip_0:
    // 0x80058CA4: lw          $t7, 0x4($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X4);
    // 0x80058CA8: lw          $t9, 0xC($s4)
    ctx->r25 = MEM_W(ctx->r20, 0XC);
    // 0x80058CAC: lw          $t1, 0x8($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X8);
    // 0x80058CB0: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x80058CB4: addu        $s2, $t8, $s0
    ctx->r18 = ADD32(ctx->r24, ctx->r16);
    // 0x80058CB8: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x80058CBC: b           L_80058D20
    // 0x80058CC0: addu        $s2, $t2, $s2
    ctx->r18 = ADD32(ctx->r10, ctx->r18);
        goto L_80058D20;
    // 0x80058CC0: addu        $s2, $t2, $s2
    ctx->r18 = ADD32(ctx->r10, ctx->r18);
    // 0x80058CC4: sw          $a3, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r7;
L_80058CC8:
    // 0x80058CC8: sw          $s0, -0x4228($at)
    MEM_W(-0X4228, ctx->r1) = ctx->r16;
    // 0x80058CCC: lw          $a3, 0x0($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X0);
    // 0x80058CD0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80058CD4: beq         $a3, $zero, L_80058D20
    if (ctx->r7 == 0) {
        // 0x80058CD8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80058D20;
    }
    // 0x80058CD8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80058CDC: sb          $t3, 0x42($sp)
    MEM_B(0X42, ctx->r29) = ctx->r11;
    // 0x80058CE0: lw          $t4, 0x4($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X4);
    // 0x80058CE4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80058CE8: jal         0x80058B80
    // 0x80058CEC: subu        $a2, $t4, $a3
    ctx->r6 = SUB32(ctx->r12, ctx->r7);
    Load_RomFile(rdram, ctx);
        goto after_0;
    // 0x80058CEC: subu        $a2, $t4, $a3
    ctx->r6 = SUB32(ctx->r12, ctx->r7);
    after_0:
    // 0x80058CF0: lw          $t5, 0x4($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X4);
    // 0x80058CF4: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80058CF8: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x80058CFC: lw          $t8, 0xC($s4)
    ctx->r24 = MEM_W(ctx->r20, 0XC);
    // 0x80058D00: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80058D04: addu        $s2, $t7, $s0
    ctx->r18 = ADD32(ctx->r15, ctx->r16);
    // 0x80058D08: jal         0x80028D40
    // 0x80058D0C: subu        $a1, $t8, $a0
    ctx->r5 = SUB32(ctx->r24, ctx->r4);
    bzero_recomp(rdram, ctx);
        goto after_1;
    // 0x80058D0C: subu        $a1, $t8, $a0
    ctx->r5 = SUB32(ctx->r24, ctx->r4);
    after_1:
    // 0x80058D10: lw          $t9, 0xC($s4)
    ctx->r25 = MEM_W(ctx->r20, 0XC);
    // 0x80058D14: lw          $t1, 0x8($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X8);
    // 0x80058D18: subu        $t2, $t9, $t1
    ctx->r10 = SUB32(ctx->r25, ctx->r9);
    // 0x80058D1C: addu        $s2, $t2, $s2
    ctx->r18 = ADD32(ctx->r10, ctx->r18);
L_80058D20:
    // 0x80058D20: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x80058D24: lw          $t4, -0x420C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X420C);
    // 0x80058D28: lw          $t3, 0x20($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X20);
    // 0x80058D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80058D30: lbu         $a2, 0x42($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X42);
    // 0x80058D34: bne         $t3, $t4, L_80058DF4
    if (ctx->r11 != ctx->r12) {
        // 0x80058D38: nop
    
            goto L_80058DF4;
    }
    // 0x80058D38: nop

    // 0x80058D3C: bne         $a2, $zero, L_80058DF4
    if (ctx->r6 != 0) {
        // 0x80058D40: sll         $t5, $zero, 3
        ctx->r13 = S32(0 << 3);
            goto L_80058DF4;
    }
    // 0x80058D40: sll         $t5, $zero, 3
    ctx->r13 = S32(0 << 3);
    // 0x80058D44: addu        $s0, $s4, $t5
    ctx->r16 = ADD32(ctx->r20, ctx->r13);
    // 0x80058D48: lui         $s6, 0x1FFF
    ctx->r22 = S32(0X1FFF << 16);
    // 0x80058D4C: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80058D50: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80058D54: addiu       $s3, $s3, 0x7E60
    ctx->r19 = ADD32(ctx->r19, 0X7E60);
    // 0x80058D58: addiu       $s5, $s5, 0x1FD0
    ctx->r21 = ADD32(ctx->r21, 0X1FD0);
    // 0x80058D5C: ori         $s6, $s6, 0xFFFF
    ctx->r22 = ctx->r22 | 0XFFFF;
    // 0x80058D60: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80058D64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80058D68: lui         $s7, 0xBC00
    ctx->r23 = S32(0XBC00 << 16);
L_80058D6C:
    // 0x80058D6C: beq         $a0, $zero, L_80058DBC
    if (ctx->r4 == 0) {
        // 0x80058D70: addiu       $a1, $s1, 0x1
        ctx->r5 = ADD32(ctx->r17, 0X1);
            goto L_80058DBC;
    }
    // 0x80058D70: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x80058D74: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80058D78: addu        $t6, $s5, $v0
    ctx->r14 = ADD32(ctx->r21, ctx->r2);
    // 0x80058D7C: and         $v1, $s2, $s6
    ctx->r3 = ctx->r18 & ctx->r22;
    // 0x80058D80: sw          $v1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r3;
    // 0x80058D84: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x80058D88: addiu       $t8, $v0, 0x4
    ctx->r24 = ADD32(ctx->r2, 0X4);
    // 0x80058D8C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80058D90: sll         $t1, $t9, 8
    ctx->r9 = S32(ctx->r25 << 8);
    // 0x80058D94: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x80058D98: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x80058D9C: or          $t2, $t1, $s7
    ctx->r10 = ctx->r9 | ctx->r23;
    // 0x80058DA0: ori         $t3, $t2, 0x6
    ctx->r11 = ctx->r10 | 0X6;
    // 0x80058DA4: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x80058DA8: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x80058DAC: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80058DB0: lw          $t5, 0x20($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X20);
    // 0x80058DB4: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80058DB8: addu        $s2, $t6, $s2
    ctx->r18 = ADD32(ctx->r14, ctx->r18);
L_80058DBC:
    // 0x80058DBC: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80058DC0: slti        $at, $t7, 0xF
    ctx->r1 = SIGNED(ctx->r15) < 0XF ? 1 : 0;
    // 0x80058DC4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80058DC8: beq         $at, $zero, L_80058DF4
    if (ctx->r1 == 0) {
        // 0x80058DCC: or          $s1, $t7, $zero
        ctx->r17 = ctx->r15 | 0;
            goto L_80058DF4;
    }
    // 0x80058DCC: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80058DD0: sll         $v0, $t7, 3
    ctx->r2 = S32(ctx->r15 << 3);
    // 0x80058DD4: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x80058DD8: addu        $t8, $fp, $v0
    ctx->r24 = ADD32(ctx->r30, ctx->r2);
    // 0x80058DDC: lw          $t9, 0x20($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X20);
    // 0x80058DE0: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80058DE4: bne         $a0, $t9, L_80058DF4
    if (ctx->r4 != ctx->r25) {
        // 0x80058DE8: nop
    
            goto L_80058DF4;
    }
    // 0x80058DE8: nop

    // 0x80058DEC: beq         $a2, $zero, L_80058D6C
    if (ctx->r6 == 0) {
        // 0x80058DF0: nop
    
            goto L_80058D6C;
    }
    // 0x80058DF0: nop

L_80058DF4:
    // 0x80058DF4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80058DF8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x80058DFC: lui         $s6, 0x1FFF
    ctx->r22 = S32(0X1FFF << 16);
    // 0x80058E00: slti        $at, $a1, 0xF
    ctx->r1 = SIGNED(ctx->r5) < 0XF ? 1 : 0;
    // 0x80058E04: ori         $s6, $s6, 0xFFFF
    ctx->r22 = ctx->r22 | 0XFFFF;
    // 0x80058E08: addiu       $s5, $s5, 0x1FD0
    ctx->r21 = ADD32(ctx->r21, 0X1FD0);
    // 0x80058E0C: addiu       $s3, $s3, 0x7E60
    ctx->r19 = ADD32(ctx->r19, 0X7E60);
    // 0x80058E10: lui         $s7, 0xBC00
    ctx->r23 = S32(0XBC00 << 16);
    // 0x80058E14: beq         $at, $zero, L_80058EAC
    if (ctx->r1 == 0) {
        // 0x80058E18: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80058EAC;
    }
    // 0x80058E18: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80058E1C:
    // 0x80058E1C: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80058E20: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
    // 0x80058E24: lw          $t1, 0x20($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X20);
    // 0x80058E28: addu        $v1, $fp, $v0
    ctx->r3 = ADD32(ctx->r30, ctx->r2);
    // 0x80058E2C: sw          $s2, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r18;
    // 0x80058E30: sw          $t1, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r9;
    // 0x80058E34: lw          $t2, 0x20($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X20);
    // 0x80058E38: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80058E3C: addu        $t3, $s5, $v0
    ctx->r11 = ADD32(ctx->r21, ctx->r2);
    // 0x80058E40: beq         $t2, $zero, L_80058E98
    if (ctx->r10 == 0) {
        // 0x80058E44: and         $v1, $s2, $s6
        ctx->r3 = ctx->r18 & ctx->r22;
            goto L_80058E98;
    }
    // 0x80058E44: and         $v1, $s2, $s6
    ctx->r3 = ctx->r18 & ctx->r22;
    // 0x80058E48: sw          $v1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r3;
    // 0x80058E4C: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x80058E50: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x80058E54: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80058E58: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80058E5C: addiu       $t4, $a3, 0x8
    ctx->r12 = ADD32(ctx->r7, 0X8);
    // 0x80058E60: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80058E64: or          $t8, $t7, $s7
    ctx->r24 = ctx->r15 | ctx->r23;
    // 0x80058E68: ori         $t9, $t8, 0x6
    ctx->r25 = ctx->r24 | 0X6;
    // 0x80058E6C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80058E70: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x80058E74: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80058E78: lw          $t1, 0x24($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X24);
    // 0x80058E7C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80058E80: jal         0x80058B80
    // 0x80058E84: subu        $a2, $t1, $a0
    ctx->r6 = SUB32(ctx->r9, ctx->r4);
    Load_RomFile(rdram, ctx);
        goto after_2;
    // 0x80058E84: subu        $a2, $t1, $a0
    ctx->r6 = SUB32(ctx->r9, ctx->r4);
    after_2:
    // 0x80058E88: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80058E8C: lw          $t3, 0x20($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X20);
    // 0x80058E90: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x80058E94: addu        $s2, $t4, $s2
    ctx->r18 = ADD32(ctx->r12, ctx->r18);
L_80058E98:
    // 0x80058E98: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x80058E9C: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x80058EA0: slti        $at, $s1, 0xF
    ctx->r1 = SIGNED(ctx->r17) < 0XF ? 1 : 0;
    // 0x80058EA4: bne         $at, $zero, L_80058E1C
    if (ctx->r1 != 0) {
        // 0x80058EA8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80058E1C;
    }
    // 0x80058EA8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
L_80058EAC:
    // 0x80058EAC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80058EB0: addiu       $v1, $v1, -0x5C50
    ctx->r3 = ADD32(ctx->r3, -0X5C50);
    // 0x80058EB4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80058EB8: beq         $v0, $zero, L_80058EC8
    if (ctx->r2 == 0) {
        // 0x80058EBC: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80058EC8;
    }
    // 0x80058EBC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80058EC0: b           L_80058EE0
    // 0x80058EC4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
        goto L_80058EE0;
    // 0x80058EC4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_80058EC8:
    // 0x80058EC8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80058ECC: lbu         $t7, 0x7E80($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7E80);
    // 0x80058ED0: bnel        $t7, $zero, L_80058EE4
    if (ctx->r15 != 0) {
        // 0x80058ED4: lbu         $v0, 0x42($sp)
        ctx->r2 = MEM_BU(ctx->r29, 0X42);
            goto L_80058EE4;
    }
    goto skip_1;
    // 0x80058ED4: lbu         $v0, 0x42($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X42);
    skip_1:
    // 0x80058ED8: jal         0x800034E8
    // 0x80058EDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Lib_FillScreen(rdram, ctx);
        goto after_3;
    // 0x80058EDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_80058EE0:
    // 0x80058EE0: lbu         $v0, 0x42($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X42);
L_80058EE4:
    // 0x80058EE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80058EE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80058EEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80058EF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80058EF4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80058EF8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80058EFC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80058F00: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80058F04: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80058F08: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80058F0C: jr          $ra
    // 0x80058F10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80058F10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_tank_80046704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80046704: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80046708: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8004670C: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x80046710: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80046714: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80046718: addiu       $s6, $s6, -0x6100
    ctx->r22 = ADD32(ctx->r22, -0X6100);
    // 0x8004671C: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80046720: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80046724: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80046728: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8004672C: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80046730: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80046734: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x80046738: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x8004673C: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80046740: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80046744: lbu         $v0, 0x0($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X0);
    // 0x80046748: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x8004674C: addiu       $s1, $s1, 0x1B00
    ctx->r17 = ADD32(ctx->r17, 0X1B00);
    // 0x80046750: blez        $v0, L_80046760
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80046754: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_80046760;
    }
    // 0x80046754: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80046758: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8004675C: sb          $t6, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r14;
L_80046760:
    // 0x80046760: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x80046764: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80046768: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8004676C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80046770: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x80046774: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80046778: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8004677C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80046780: addiu       $s3, $s3, -0x1DB0
    ctx->r19 = ADD32(ctx->r19, -0X1DB0);
    // 0x80046784: addiu       $s5, $zero, 0x3B
    ctx->r21 = ADD32(0, 0X3B);
L_80046788:
    // 0x80046788: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x8004678C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80046790: bne         $t7, $at, L_80046DF0
    if (ctx->r15 != ctx->r1) {
        // 0x80046794: lui         $at, 0x44FA
        ctx->r1 = S32(0X44FA << 16);
            goto L_80046DF0;
    }
    // 0x80046794: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80046798: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004679C: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800467A0: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800467A4: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800467A8: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x800467AC: nop

    // 0x800467B0: bc1fl       L_80046DF4
    if (!c1cs) {
        // 0x800467B4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_0;
    // 0x800467B4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_0:
    // 0x800467B8: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x800467BC: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x800467C0: beq         $a1, $at, L_800467F0
    if (ctx->r5 == ctx->r1) {
        // 0x800467C4: addiu       $at, $zero, 0x46
        ctx->r1 = ADD32(0, 0X46);
            goto L_800467F0;
    }
    // 0x800467C4: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x800467C8: beq         $a1, $at, L_800467F0
    if (ctx->r5 == ctx->r1) {
        // 0x800467CC: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800467F0;
    }
    // 0x800467CC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800467D0: beq         $a1, $at, L_800467F0
    if (ctx->r5 == ctx->r1) {
        // 0x800467D4: addiu       $at, $zero, 0x48
        ctx->r1 = ADD32(0, 0X48);
            goto L_800467F0;
    }
    // 0x800467D4: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x800467D8: beq         $a1, $at, L_800467F0
    if (ctx->r5 == ctx->r1) {
        // 0x800467DC: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_800467F0;
    }
    // 0x800467DC: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x800467E0: beq         $a1, $at, L_800467F0
    if (ctx->r5 == ctx->r1) {
        // 0x800467E4: addiu       $at, $zero, 0x43
        ctx->r1 = ADD32(0, 0X43);
            goto L_800467F0;
    }
    // 0x800467E4: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x800467E8: bnel        $a1, $at, L_80046864
    if (ctx->r5 != ctx->r1) {
        // 0x800467EC: addiu       $at, $zero, 0x4A
        ctx->r1 = ADD32(0, 0X4A);
            goto L_80046864;
    }
    goto skip_1;
    // 0x800467EC: addiu       $at, $zero, 0x4A
    ctx->r1 = ADD32(0, 0X4A);
    skip_1:
L_800467F0:
    // 0x800467F0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800467F4: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800467F8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800467FC: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80046800: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046804: sub.s       $f2, $f12, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80046808: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8004680C: nop

    // 0x80046810: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80046814: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80046818: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8004681C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80046820: nop

    // 0x80046824: bc1f        L_8004693C
    if (!c1cs) {
        // 0x80046828: nop
    
            goto L_8004693C;
    }
    // 0x80046828: nop

    // 0x8004682C: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80046830: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80046834: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80046838: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8004683C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046840: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80046844: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80046848: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8004684C: lwc1        $f4, 0x18($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80046850: jal         0x8004641C
    // 0x80046854: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_tank_8004641C(rdram, ctx);
        goto after_0;
    // 0x80046854: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80046858: b           L_8004693C
    // 0x8004685C: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
        goto L_8004693C;
    // 0x8004685C: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    // 0x80046860: addiu       $at, $zero, 0x4A
    ctx->r1 = ADD32(0, 0X4A);
L_80046864:
    // 0x80046864: bne         $a1, $at, L_8004693C
    if (ctx->r5 != ctx->r1) {
        // 0x80046868: lui         $at, 0x444D
        ctx->r1 = S32(0X444D << 16);
            goto L_8004693C;
    }
    // 0x80046868: lui         $at, 0x444D
    ctx->r1 = S32(0X444D << 16);
    // 0x8004686C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046870: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80046874: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80046878: lui         $at, 0x444D
    ctx->r1 = S32(0X444D << 16);
    // 0x8004687C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80046880: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x80046884: nop

    // 0x80046888: bc1f        L_8004693C
    if (!c1cs) {
        // 0x8004688C: nop
    
            goto L_8004693C;
    }
    // 0x8004688C: nop

    // 0x80046890: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80046894: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80046898: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8004689C: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x800468A0: nop

    // 0x800468A4: bc1f        L_8004693C
    if (!c1cs) {
        // 0x800468A8: nop
    
            goto L_8004693C;
    }
    // 0x800468A8: nop

    // 0x800468AC: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800468B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800468B4: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800468B8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800468BC: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800468C0: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800468C4: nop

    // 0x800468C8: bc1f        L_8004693C
    if (!c1cs) {
        // 0x800468CC: nop
    
            goto L_8004693C;
    }
    // 0x800468CC: nop

    // 0x800468D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800468D4: nop

    // 0x800468D8: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800468DC: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800468E0: nop

    // 0x800468E4: bc1f        L_8004693C
    if (!c1cs) {
        // 0x800468E8: nop
    
            goto L_8004693C;
    }
    // 0x800468E8: nop

    // 0x800468EC: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x800468F0: lui         $at, 0x4470
    ctx->r1 = S32(0X4470 << 16);
    // 0x800468F4: bc1f        L_8004693C
    if (!c1cs) {
        // 0x800468F8: nop
    
            goto L_8004693C;
    }
    // 0x800468F8: nop

    // 0x800468FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046900: nop

    // 0x80046904: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80046908: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x8004690C: nop

    // 0x80046910: bc1f        L_8004693C
    if (!c1cs) {
        // 0x80046914: nop
    
            goto L_8004693C;
    }
    // 0x80046914: nop

    // 0x80046918: swc1        $f0, 0x6C($s3)
    MEM_W(0X6C, ctx->r19) = ctx->f0.u32l;
    // 0x8004691C: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80046920: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80046924: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046928: swc1        $f10, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f10.u32l;
    // 0x8004692C: lwc1        $f4, 0x6C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x80046930: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80046934: swc1        $f8, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f8.u32l;
    // 0x80046938: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
L_8004693C:
    // 0x8004693C: beq         $s5, $a1, L_8004697C
    if (ctx->r21 == ctx->r5) {
        // 0x80046940: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8004697C;
    }
    // 0x80046940: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80046944: beq         $a1, $at, L_8004697C
    if (ctx->r5 == ctx->r1) {
        // 0x80046948: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_8004697C;
    }
    // 0x80046948: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8004694C: beq         $a1, $at, L_8004697C
    if (ctx->r5 == ctx->r1) {
        // 0x80046950: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_8004697C;
    }
    // 0x80046950: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80046954: beq         $a1, $at, L_8004697C
    if (ctx->r5 == ctx->r1) {
        // 0x80046958: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_8004697C;
    }
    // 0x80046958: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x8004695C: beq         $a1, $at, L_8004697C
    if (ctx->r5 == ctx->r1) {
        // 0x80046960: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_8004697C;
    }
    // 0x80046960: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80046964: beq         $a1, $at, L_8004697C
    if (ctx->r5 == ctx->r1) {
        // 0x80046968: addiu       $at, $zero, 0x43
        ctx->r1 = ADD32(0, 0X43);
            goto L_8004697C;
    }
    // 0x80046968: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x8004696C: beq         $a1, $at, L_8004697C
    if (ctx->r5 == ctx->r1) {
        // 0x80046970: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_8004697C;
    }
    // 0x80046970: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80046974: bnel        $a1, $at, L_80046DF4
    if (ctx->r5 != ctx->r1) {
        // 0x80046978: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_2;
    // 0x80046978: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_2:
L_8004697C:
    // 0x8004697C: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80046980: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    // 0x80046984: lw          $a3, 0x4($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4);
    // 0x80046988: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8004698C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80046990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046994: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x80046998: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004699C: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800469A0: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800469A4: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800469A8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x800469AC: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x800469B0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800469B4: swc1        $f24, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f24.u32l;
    // 0x800469B8: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800469BC: jal         0x80046E40
    // 0x800469C0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_tank_80046E40(rdram, ctx);
        goto after_1;
    // 0x800469C0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800469C4: beq         $v0, $zero, L_80046B78
    if (ctx->r2 == 0) {
        // 0x800469C8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80046B78;
    }
    // 0x800469C8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800469CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800469D0: beq         $v0, $at, L_800469F4
    if (ctx->r2 == ctx->r1) {
        // 0x800469D4: addiu       $a0, $s0, 0xD0
        ctx->r4 = ADD32(ctx->r16, 0XD0);
            goto L_800469F4;
    }
    // 0x800469D4: addiu       $a0, $s0, 0xD0
    ctx->r4 = ADD32(ctx->r16, 0XD0);
    // 0x800469D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800469DC: beq         $v0, $at, L_800469F4
    if (ctx->r2 == ctx->r1) {
        // 0x800469E0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800469F4;
    }
    // 0x800469E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800469E4: beql        $v0, $at, L_80046AAC
    if (ctx->r2 == ctx->r1) {
        // 0x800469E8: lhu         $a1, 0x2($s1)
        ctx->r5 = MEM_HU(ctx->r17, 0X2);
            goto L_80046AAC;
    }
    goto skip_3;
    // 0x800469E8: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
    skip_3:
    // 0x800469EC: b           L_80046B7C
    // 0x800469F0: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
        goto L_80046B7C;
    // 0x800469F0: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
L_800469F4:
    // 0x800469F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800469F8: lwc1        $f4, 0x56E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X56E8);
    // 0x800469FC: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80046A00: addiu       $t8, $s0, 0x8C
    ctx->r24 = ADD32(ctx->r16, 0X8C);
    // 0x80046A04: sw          $t8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r24;
    // 0x80046A08: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80046A0C: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x80046A10: lui         $a3, 0x4060
    ctx->r7 = S32(0X4060 << 16);
    // 0x80046A14: jal         0x8009BC2C
    // 0x80046A18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80046A18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80046A1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046A20: lwc1        $f6, 0x56EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X56EC);
    // 0x80046A24: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80046A28: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80046A2C: lw          $a0, 0x8C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X8C);
    // 0x80046A30: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80046A34: lui         $a3, 0x4060
    ctx->r7 = S32(0X4060 << 16);
    // 0x80046A38: jal         0x8009BC2C
    // 0x80046A3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80046A3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80046A40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80046A44: bne         $s2, $at, L_80046A5C
    if (ctx->r18 != ctx->r1) {
        // 0x80046A48: sll         $t9, $s2, 2
        ctx->r25 = S32(ctx->r18 << 2);
            goto L_80046A5C;
    }
    // 0x80046A48: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80046A4C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80046A50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046A54: b           L_80046A6C
    // 0x80046A58: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
        goto L_80046A6C;
    // 0x80046A58: swc1        $f8, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f8.u32l;
L_80046A5C:
    // 0x80046A5C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80046A60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80046A64: nop

    // 0x80046A68: swc1        $f10, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f10.u32l;
L_80046A6C:
    // 0x80046A6C: lwc1        $f0, 0x90($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X90);
    // 0x80046A70: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x80046A74: addiu       $t0, $t0, -0x60B4
    ctx->r8 = ADD32(ctx->r8, -0X60B4);
    // 0x80046A78: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x80046A7C: swc1        $f0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f0.u32l;
    // 0x80046A80: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80046A84: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80046A88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046A8C: add.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80046A90: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
    // 0x80046A94: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80046A98: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80046A9C: add.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80046AA0: b           L_80046B78
    // 0x80046AA4: swc1        $f4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f4.u32l;
        goto L_80046B78;
    // 0x80046AA4: swc1        $f4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f4.u32l;
    // 0x80046AA8: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
L_80046AAC:
    // 0x80046AAC: addiu       $t1, $s0, 0x460
    ctx->r9 = ADD32(ctx->r16, 0X460);
    // 0x80046AB0: sw          $t1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r9;
    // 0x80046AB4: beq         $s5, $a1, L_80046AD8
    if (ctx->r21 == ctx->r5) {
        // 0x80046AB8: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80046AD8;
    }
    // 0x80046AB8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80046ABC: beq         $a1, $at, L_80046AD8
    if (ctx->r5 == ctx->r1) {
        // 0x80046AC0: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_80046AD8;
    }
    // 0x80046AC0: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80046AC4: beq         $a1, $at, L_80046AD8
    if (ctx->r5 == ctx->r1) {
        // 0x80046AC8: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_80046AD8;
    }
    // 0x80046AC8: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80046ACC: beq         $a1, $at, L_80046AD8
    if (ctx->r5 == ctx->r1) {
        // 0x80046AD0: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_80046AD8;
    }
    // 0x80046AD0: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80046AD4: bne         $a1, $at, L_80046AE8
    if (ctx->r5 != ctx->r1) {
        // 0x80046AD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80046AE8;
    }
L_80046AD8:
    // 0x80046AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80046ADC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80046AE0: jal         0x800A6CD0
    // 0x80046AE4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    Player_ApplyDamage(rdram, ctx);
        goto after_4;
    // 0x80046AE4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_4:
L_80046AE8:
    // 0x80046AE8: lbu         $t2, 0x0($s6)
    ctx->r10 = MEM_BU(ctx->r22, 0X0);
    // 0x80046AEC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80046AF0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80046AF4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80046AF8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80046AFC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80046B00: bgez        $t2, L_80046B18
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80046B04: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80046B18;
    }
    // 0x80046B04: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80046B08: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80046B0C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80046B10: nop

    // 0x80046B14: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80046B18:
    // 0x80046B18: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80046B1C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80046B20: swc1        $f6, 0xD0($s0)
    MEM_W(0XD0, ctx->r16) = ctx->f6.u32l;
    // 0x80046B24: lbu         $t3, 0x0($s6)
    ctx->r11 = MEM_BU(ctx->r22, 0X0);
    // 0x80046B28: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80046B2C: bgez        $t3, L_80046B44
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80046B30: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80046B44;
    }
    // 0x80046B30: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80046B34: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80046B38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80046B3C: nop

    // 0x80046B40: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80046B44:
    // 0x80046B44: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80046B48: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80046B4C: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80046B50: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80046B54: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80046B58: ori         $a0, $a0, 0x8015
    ctx->r4 = ctx->r4 | 0X8015;
    // 0x80046B5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80046B60: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80046B64: sb          $t4, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r12;
    // 0x80046B68: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80046B6C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80046B70: jal         0x80019218
    // 0x80046B74: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80046B74: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    after_5:
L_80046B78:
    // 0x80046B78: lhu         $a1, 0x2($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X2);
L_80046B7C:
    // 0x80046B7C: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80046B80: bne         $s5, $a1, L_80046D90
    if (ctx->r21 != ctx->r5) {
        // 0x80046B84: nop
    
            goto L_80046D90;
    }
    // 0x80046B84: nop

    // 0x80046B88: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80046B8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80046B90: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80046B94: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80046B98: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80046B9C: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80046BA0: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80046BA4: nop

    // 0x80046BA8: bc1fl       L_80046D0C
    if (!c1cs) {
        // 0x80046BAC: sub.s       $f10, $f0, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80046D0C;
    }
    goto skip_4;
    // 0x80046BAC: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    skip_4:
    // 0x80046BB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046BB4: nop

    // 0x80046BB8: add.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80046BBC: c.le.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl <= ctx->f6.fl;
    // 0x80046BC0: nop

    // 0x80046BC4: bc1fl       L_80046D0C
    if (!c1cs) {
        // 0x80046BC8: sub.s       $f10, $f0, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80046D0C;
    }
    goto skip_5;
    // 0x80046BC8: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    skip_5:
    // 0x80046BCC: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80046BD0: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80046BD4: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80046BD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046BDC: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80046BE0: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x80046BE4: nop

    // 0x80046BE8: bc1fl       L_80046D0C
    if (!c1cs) {
        // 0x80046BEC: sub.s       $f10, $f0, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80046D0C;
    }
    goto skip_6;
    // 0x80046BEC: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    skip_6:
    // 0x80046BF0: c.lt.s      $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f2.fl < ctx->f26.fl;
    // 0x80046BF4: nop

    // 0x80046BF8: bc1fl       L_80046D0C
    if (!c1cs) {
        // 0x80046BFC: sub.s       $f10, $f0, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80046D0C;
    }
    goto skip_7;
    // 0x80046BFC: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    skip_7:
    // 0x80046C00: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80046C04: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80046C08: sub.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x80046C0C: c.le.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl <= ctx->f16.fl;
    // 0x80046C10: nop

    // 0x80046C14: bc1fl       L_80046D0C
    if (!c1cs) {
        // 0x80046C18: sub.s       $f10, $f0, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80046D0C;
    }
    goto skip_8;
    // 0x80046C18: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    skip_8:
    // 0x80046C1C: add.s       $f10, $f18, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x80046C20: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80046C24: nop

    // 0x80046C28: bc1fl       L_80046D0C
    if (!c1cs) {
        // 0x80046C2C: sub.s       $f10, $f0, $f20
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80046D0C;
    }
    goto skip_9;
    // 0x80046C2C: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    skip_9:
    // 0x80046C30: sub.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x80046C34: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80046C38: nop

    // 0x80046C3C: bc1fl       L_80046C5C
    if (!c1cs) {
        // 0x80046C40: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80046C5C;
    }
    goto skip_10;
    // 0x80046C40: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_10:
    // 0x80046C44: add.s       $f8, $f0, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x80046C48: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x80046C4C: nop

    // 0x80046C50: bc1tl       L_80046CE0
    if (c1cs) {
        // 0x80046C54: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80046CE0;
    }
    goto skip_11;
    // 0x80046C54: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_11:
    // 0x80046C58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80046C5C:
    // 0x80046C5C: lwc1        $f10, 0x6C($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X6C);
    // 0x80046C60: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x80046C64: nop

    // 0x80046C68: bc1fl       L_80046CE0
    if (!c1cs) {
        // 0x80046C6C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80046CE0;
    }
    goto skip_12;
    // 0x80046C6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_12:
    // 0x80046C70: lwc1        $f4, 0xC4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80046C74: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80046C78: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80046C7C: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80046C80: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x80046C84: nop

    // 0x80046C88: bc1fl       L_80046CE0
    if (!c1cs) {
        // 0x80046C8C: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80046CE0;
    }
    goto skip_13;
    // 0x80046C8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_13:
    // 0x80046C90: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80046C94: sw          $t6, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = ctx->r14;
    // 0x80046C98: sw          $t7, 0x1E8($s0)
    MEM_W(0X1E8, ctx->r16) = ctx->r15;
    // 0x80046C9C: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80046CA0: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80046CA4: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80046CA8: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x80046CAC: addiu       $t0, $zero, -0x14
    ctx->r8 = ADD32(0, -0X14);
    // 0x80046CB0: addiu       $t1, $zero, -0x14
    ctx->r9 = ADD32(0, -0X14);
    // 0x80046CB4: bc1fl       L_80046CCC
    if (!c1cs) {
        // 0x80046CB8: sw          $t0, 0x1F0($s0)
        MEM_W(0X1F0, ctx->r16) = ctx->r8;
            goto L_80046CCC;
    }
    goto skip_14;
    // 0x80046CB8: sw          $t0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r8;
    skip_14:
    // 0x80046CBC: sw          $t8, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r24;
    // 0x80046CC0: b           L_80046CD0
    // 0x80046CC4: sw          $t9, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r25;
        goto L_80046CD0;
    // 0x80046CC4: sw          $t9, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r25;
    // 0x80046CC8: sw          $t0, 0x1F0($s0)
    MEM_W(0X1F0, ctx->r16) = ctx->r8;
L_80046CCC:
    // 0x80046CCC: sw          $t1, 0x1EC($s0)
    MEM_W(0X1EC, ctx->r16) = ctx->r9;
L_80046CD0:
    // 0x80046CD0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80046CD4: b           L_80046D08
    // 0x80046CD8: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
        goto L_80046D08;
    // 0x80046CD8: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80046CDC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80046CE0:
    // 0x80046CE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80046CE4: sb          $t2, -0x60FC($at)
    MEM_B(-0X60FC, ctx->r1) = ctx->r10;
    // 0x80046CE8: lui         $at, 0x434E
    ctx->r1 = S32(0X434E << 16);
    // 0x80046CEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046CF0: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80046CF4: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80046CF8: swc1        $f6, 0x6C($s3)
    MEM_W(0X6C, ctx->r19) = ctx->f6.u32l;
    // 0x80046CFC: sw          $zero, 0x1DC($s0)
    MEM_W(0X1DC, ctx->r16) = 0;
    // 0x80046D00: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80046D04: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
L_80046D08:
    // 0x80046D08: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
L_80046D0C:
    // 0x80046D0C: c.le.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl <= ctx->f12.fl;
    // 0x80046D10: nop

    // 0x80046D14: bc1fl       L_80046DF4
    if (!c1cs) {
        // 0x80046D18: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_15;
    // 0x80046D18: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_15:
    // 0x80046D1C: add.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80046D20: c.le.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl <= ctx->f4.fl;
    // 0x80046D24: nop

    // 0x80046D28: bc1fl       L_80046DF4
    if (!c1cs) {
        // 0x80046D2C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_16;
    // 0x80046D2C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_16:
    // 0x80046D30: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x80046D34: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80046D38: sub.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x80046D3C: c.le.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl <= ctx->f16.fl;
    // 0x80046D40: nop

    // 0x80046D44: bc1fl       L_80046DF4
    if (!c1cs) {
        // 0x80046D48: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_17;
    // 0x80046D48: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_17:
    // 0x80046D4C: add.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x80046D50: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x80046D54: nop

    // 0x80046D58: bc1fl       L_80046DF4
    if (!c1cs) {
        // 0x80046D5C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_18;
    // 0x80046D5C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_18:
    // 0x80046D60: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80046D64: lui         $at, 0x434C
    ctx->r1 = S32(0X434C << 16);
    // 0x80046D68: c.le.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl <= ctx->f10.fl;
    // 0x80046D6C: nop

    // 0x80046D70: bc1fl       L_80046DF4
    if (!c1cs) {
        // 0x80046D74: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_19;
    // 0x80046D74: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_19:
    // 0x80046D78: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80046D7C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80046D80: nop

    // 0x80046D84: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80046D88: b           L_80046DF0
    // 0x80046D8C: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
        goto L_80046DF0;
    // 0x80046D8C: swc1        $f6, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f6.u32l;
L_80046D90:
    // 0x80046D90: bnel        $a1, $at, L_80046DF4
    if (ctx->r5 != ctx->r1) {
        // 0x80046D94: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_20;
    // 0x80046D94: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_20:
    // 0x80046D98: jal         0x801A3C20
    // 0x80046D9C: lwc1        $f12, 0x138($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X138);
    Macbeth_801A3C20(rdram, ctx);
        goto after_6;
    // 0x80046D9C: lwc1        $f12, 0x138($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X138);
    after_6:
    // 0x80046DA0: beql        $v0, $zero, L_80046DF4
    if (ctx->r2 == 0) {
        // 0x80046DA4: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_21;
    // 0x80046DA4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_21:
    // 0x80046DA8: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80046DAC: lwc1        $f2, 0x54($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X54);
    // 0x80046DB0: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x80046DB4: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80046DB8: nop

    // 0x80046DBC: bc1fl       L_80046DF4
    if (!c1cs) {
        // 0x80046DC0: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_22;
    // 0x80046DC0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_22:
    // 0x80046DC4: add.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80046DC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80046DCC: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80046DD0: nop

    // 0x80046DD4: bc1fl       L_80046DF4
    if (!c1cs) {
        // 0x80046DD8: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_80046DF4;
    }
    goto skip_23;
    // 0x80046DD8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    skip_23:
    // 0x80046DDC: lwc1        $f8, 0x58($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X58);
    // 0x80046DE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80046DE4: nop

    // 0x80046DE8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80046DEC: swc1        $f10, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f10.u32l;
L_80046DF0:
    // 0x80046DF0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_80046DF4:
    // 0x80046DF4: sll         $t3, $s4, 16
    ctx->r11 = S32(ctx->r20 << 16);
    // 0x80046DF8: sra         $s4, $t3, 16
    ctx->r20 = S32(SIGNED(ctx->r11) >> 16);
    // 0x80046DFC: slti        $at, $s4, 0x32
    ctx->r1 = SIGNED(ctx->r20) < 0X32 ? 1 : 0;
    // 0x80046E00: bne         $at, $zero, L_80046788
    if (ctx->r1 != 0) {
        // 0x80046E04: addiu       $s1, $s1, 0x80
        ctx->r17 = ADD32(ctx->r17, 0X80);
            goto L_80046788;
    }
    // 0x80046E04: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x80046E08: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x80046E0C: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80046E10: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80046E14: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x80046E18: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x80046E1C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80046E20: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80046E24: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80046E28: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80046E2C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80046E30: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80046E34: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80046E38: jr          $ra
    // 0x80046E3C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80046E3C: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Audio_SetSfxBanksMute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019158: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001915C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80019160: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80019164: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80019168: addiu       $a1, $a1, -0x6584
    ctx->r5 = ADD32(ctx->r5, -0X6584);
    // 0x8001916C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80019170: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80019174:
    // 0x80019174: andi        $t7, $a0, 0x1
    ctx->r15 = ctx->r4 & 0X1;
    // 0x80019178: beq         $t7, $zero, L_8001918C
    if (ctx->r15 == 0) {
        // 0x8001917C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8001918C;
    }
    // 0x8001917C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80019180: addu        $t8, $a1, $v0
    ctx->r24 = ADD32(ctx->r5, ctx->r2);
    // 0x80019184: b           L_80019194
    // 0x80019188: sb          $a2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r6;
        goto L_80019194;
    // 0x80019188: sb          $a2, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r6;
L_8001918C:
    // 0x8001918C: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x80019190: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
L_80019194:
    // 0x80019194: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80019198: andi        $t1, $v0, 0xFF
    ctx->r9 = ctx->r2 & 0XFF;
    // 0x8001919C: sra         $a0, $v1, 1
    ctx->r4 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800191A0: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x800191A4: andi        $t0, $a0, 0xFFFF
    ctx->r8 = ctx->r4 & 0XFFFF;
    // 0x800191A8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800191AC: bne         $at, $zero, L_80019174
    if (ctx->r1 != 0) {
        // 0x800191B0: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_80019174;
    }
    // 0x800191B0: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x800191B4: jr          $ra
    // 0x800191B8: nop

    return;
    // 0x800191B8: nop

;}
RECOMP_FUNC void AudioHeap_InitTemporaryCache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BFA8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8000BFAC: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8000BFB0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8000BFB4: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x8000BFB8: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8000BFBC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8000BFC0: sw          $t7, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r15;
    // 0x8000BFC4: sh          $v1, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = ctx->r3;
    // 0x8000BFC8: sh          $v1, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r3;
    // 0x8000BFCC: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x8000BFD0: jr          $ra
    // 0x8000BFD4: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
    return;
    // 0x8000BFD4: sw          $v0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_col2_800A3A74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3A74: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A3A78: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A3A7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A3A80: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x800A3A84: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A3A88: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A3A8C: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x800A3A90: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A3A94: lw          $v0, -0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X4);
    // 0x800A3A98: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A3A9C: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A3AA0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800A3AA4: lwc1        $f14, 0x8($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A3AA8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A3AAC: sub.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x800A3AB0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800A3AB4: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800A3AB8: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x800A3ABC: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A3AC0: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A3AC4: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800A3AC8: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800A3ACC: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800A3AD0: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x800A3AD4: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A3AD8: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x800A3ADC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800A3AE0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800A3AE4: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x800A3AE8: sub.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A3AEC: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x800A3AF0: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800A3AF4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800A3AF8: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A3AFC: sub.s       $f10, $f4, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800A3B00: mul.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A3B04: sub.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800A3B08: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800A3B0C: nop

    // 0x800A3B10: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x800A3B14: nop

    // 0x800A3B18: bc1fl       L_800A3C90
    if (!c1cs) {
        // 0x800A3B1C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A3C90;
    }
    goto skip_0;
    // 0x800A3B1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_0:
    // 0x800A3B20: sub.s       $f10, $f16, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800A3B24: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x800A3B28: sub.s       $f6, $f18, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800A3B2C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800A3B30: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800A3B34: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800A3B38: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x800A3B3C: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A3B40: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A3B44: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A3B48: mul.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A3B4C: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800A3B50: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800A3B54: swc1        $f10, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f10.u32l;
    // 0x800A3B58: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800A3B5C: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800A3B60: c.le.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl <= ctx->f8.fl;
    // 0x800A3B64: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800A3B68: bc1fl       L_800A3C90
    if (!c1cs) {
        // 0x800A3B6C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A3C90;
    }
    goto skip_1;
    // 0x800A3B6C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x800A3B70: sub.s       $f8, $f2, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x800A3B74: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800A3B78: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800A3B7C: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A3B80: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A3B84: sub.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800A3B88: sub.s       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800A3B8C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A3B90: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A3B94: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800A3B98: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A3B9C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A3BA0: bc1fl       L_800A3C90
    if (!c1cs) {
        // 0x800A3BA4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A3C90;
    }
    goto skip_2;
    // 0x800A3BA4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_2:
    // 0x800A3BA8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A3BAC: lwc1        $f16, 0x0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800A3BB0: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800A3BB4: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800A3BB8: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800A3BBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A3BC0: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800A3BC4: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800A3BC8: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x800A3BCC: lwc1        $f4, 0x14($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A3BD0: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800A3BD4: nop

    // 0x800A3BD8: mul.s       $f6, $f18, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x800A3BDC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800A3BE0: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800A3BE4: lwc1        $f2, 0x0($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800A3BE8: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x800A3BEC: lwc1        $f10, 0x14($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A3BF0: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800A3BF4: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800A3BF8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A3BFC: bc1f        L_800A3C2C
    if (!c1cs) {
        // 0x800A3C00: swc1        $f8, 0x8($a2)
        MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
            goto L_800A3C2C;
    }
    // 0x800A3C00: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // 0x800A3C04: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800A3C08: c.eq.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl == ctx->f10.fl;
    // 0x800A3C0C: nop

    // 0x800A3C10: bc1f        L_800A3C2C
    if (!c1cs) {
        // 0x800A3C14: nop
    
            goto L_800A3C2C;
    }
    // 0x800A3C14: nop

    // 0x800A3C18: lwc1        $f4, 0x8($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800A3C1C: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x800A3C20: nop

    // 0x800A3C24: bc1tl       L_800A3C90
    if (c1cs) {
        // 0x800A3C28: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A3C90;
    }
    goto skip_3;
    // 0x800A3C28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_3:
L_800A3C2C:
    // 0x800A3C2C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800A3C30: lwc1        $f12, 0x4($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800A3C34: lwc1        $f14, 0x8($a2)
    ctx->f14.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800A3C38: mul.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800A3C3C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800A3C40: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800A3C44: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A3C48: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800A3C4C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800A3C50: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800A3C54: nop

    // 0x800A3C58: bc1tl       L_800A3C90
    if (c1cs) {
        // 0x800A3C5C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800A3C90;
    }
    goto skip_4;
    // 0x800A3C5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x800A3C60: div.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800A3C64: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800A3C68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A3C6C: div.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800A3C70: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A3C74: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x800A3C78: div.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800A3C7C: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800A3C80: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x800A3C84: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A3C88: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x800A3C8C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800A3C90:
    // 0x800A3C90: jr          $ra
    // 0x800A3C94: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800A3C94: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ActorEvent_RepairWings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE28: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006FE2C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006FE30: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8006FE34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006FE38: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8006FE3C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8006FE40: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8006FE44: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8006FE48: lwc1        $f6, 0x74($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8006FE4C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8006FE50: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006FE54: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006FE58: nop

    // 0x8006FE5C: bc1fl       L_8006FEE0
    if (!c1cs) {
        // 0x8006FE60: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006FEE0;
    }
    goto skip_0;
    // 0x8006FE60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006FE64: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8006FE68: lwc1        $f10, 0x78($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8006FE6C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006FE70: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006FE74: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8006FE78: nop

    // 0x8006FE7C: bc1fl       L_8006FEE0
    if (!c1cs) {
        // 0x8006FE80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006FEE0;
    }
    goto skip_1;
    // 0x8006FE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8006FE84: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006FE88: lwc1        $f18, 0x138($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8006FE8C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006FE90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8006FE94: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8006FE98: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8006FE9C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8006FEA0: nop

    // 0x8006FEA4: bc1fl       L_8006FEE0
    if (!c1cs) {
        // 0x8006FEA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006FEE0;
    }
    goto skip_2;
    // 0x8006FEA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8006FEAC: jal         0x80067A40
    // 0x8006FEB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    Player_RepairWings(rdram, ctx);
        goto after_0;
    // 0x8006FEB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8006FEB4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8006FEB8: lui         $a1, 0x1900
    ctx->r5 = S32(0X1900 << 16);
    // 0x8006FEBC: ori         $a1, $a1, 0x302B
    ctx->r5 = ctx->r5 | 0X302B;
    // 0x8006FEC0: addiu       $a3, $a2, 0x100
    ctx->r7 = ADD32(ctx->r6, 0X100);
    // 0x8006FEC4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8006FEC8: jal         0x8001A55C
    // 0x8006FECC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_1;
    // 0x8006FECC: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8006FED0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006FED4: jal         0x80060FBC
    // 0x8006FED8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    Object_Kill(rdram, ctx);
        goto after_2;
    // 0x8006FED8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8006FEDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006FEE0:
    // 0x8006FEE0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006FEE4: jr          $ra
    // 0x8006FEE8: nop

    return;
    // 0x8006FEE8: nop

;}
RECOMP_FUNC void AudioHeap_SearchCaches(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C994: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C998: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000C99C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000C9A0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000C9A4: jal         0x8000DB0C
    // 0x8000C9A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    AudioHeap_SearchPermanentCache(rdram, ctx);
        goto after_0;
    // 0x8000C9A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x8000C9AC: beq         $v0, $zero, L_8000C9BC
    if (ctx->r2 == 0) {
        // 0x8000C9B0: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_8000C9BC;
    }
    // 0x8000C9B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C9B4: b           L_8000C9DC
    // 0x8000C9B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000C9DC;
    // 0x8000C9B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C9BC:
    // 0x8000C9BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000C9C0: bne         $a1, $at, L_8000C9D0
    if (ctx->r5 != ctx->r1) {
        // 0x8000C9C4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_8000C9D0;
    }
    // 0x8000C9C4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000C9C8: b           L_8000C9D8
    // 0x8000C9CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C9D8;
    // 0x8000C9CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C9D0:
    // 0x8000C9D0: jal         0x8000C9E8
    // 0x8000C9D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    AudioHeap_SearchRegularCaches(rdram, ctx);
        goto after_1;
    // 0x8000C9D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    after_1:
L_8000C9D8:
    // 0x8000C9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000C9DC:
    // 0x8000C9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C9E0: jr          $ra
    // 0x8000C9E4: nop

    return;
    // 0x8000C9E4: nop

;}
RECOMP_FUNC void Effect_FireSmoke1_SetupMoving(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800778C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800778C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800778CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800778D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800778D4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800778D8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800778DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800778E0: jal         0x80061474
    // 0x800778E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x800778E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800778E8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800778EC: addiu       $t7, $zero, 0x153
    ctx->r15 = ADD32(0, 0X153);
    // 0x800778F0: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x800778F4: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x800778F8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800778FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80077900: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80077904: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80077908: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007790C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80077910: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80077914: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80077918: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007791C: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x80077920: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80077924: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    // 0x80077928: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007792C: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x80077930: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80077934: sb          $zero, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = 0;
    // 0x80077938: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x8007793C: jal         0x80004EB0
    // 0x80077940: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80077940: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    after_1:
    // 0x80077944: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80077948: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007794C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80077950: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80077954: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80077958: jal         0x800612B8
    // 0x8007795C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x8007795C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    after_2:
    // 0x80077960: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80077964: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x80077968: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007796C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80077970: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80077974: jr          $ra
    // 0x80077978: nop

    return;
    // 0x80077978: nop

;}
RECOMP_FUNC void Player_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B48BC: addiu       $sp, $sp, -0x1D0
    ctx->r29 = ADD32(ctx->r29, -0X1D0);
    // 0x800B48C0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B48C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B48C8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B48CC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B48D0: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800B48D4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B48D8: addiu       $t1, $t1, 0x7984
    ctx->r9 = ADD32(ctx->r9, 0X7984);
    // 0x800B48DC: beq         $t6, $zero, L_800B494C
    if (ctx->r14 == 0) {
        // 0x800B48E0: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_800B494C;
    }
    // 0x800B48E0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B48E4: lw          $t7, 0x1C4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B48E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B48EC: addiu       $t9, $t9, -0x2780
    ctx->r25 = ADD32(ctx->r25, -0X2780);
    // 0x800B48F0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B48F4: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800B48F8: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x800B48FC: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800B4900: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4904: sw          $t2, 0x7974($at)
    MEM_W(0X7974, ctx->r1) = ctx->r10;
    // 0x800B4908: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B490C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B4910: addiu       $t5, $t5, -0x2768
    ctx->r13 = ADD32(ctx->r13, -0X2768);
    // 0x800B4914: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B4918: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800B491C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x800B4920: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800B4924: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4928: sw          $t6, 0x797C($at)
    MEM_W(0X797C, ctx->r1) = ctx->r14;
    // 0x800B492C: lw          $t7, 0x1C4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B4930: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B4934: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B4938: addiu       $t8, $t8, 0x7E84
    ctx->r24 = ADD32(ctx->r24, 0X7E84);
    // 0x800B493C: addiu       $t1, $t1, 0x7984
    ctx->r9 = ADD32(ctx->r9, 0X7984);
    // 0x800B4940: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B4944: b           L_800B49A0
    // 0x800B4948: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_800B49A0;
    // 0x800B4948: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_800B494C:
    // 0x800B494C: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x800B4950: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B4954: addiu       $t3, $t3, -0x2780
    ctx->r11 = ADD32(ctx->r11, -0X2780);
    // 0x800B4958: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800B495C: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800B4960: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800B4964: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800B4968: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B496C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4970: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B4974: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800B4978: sw          $t4, 0x7974($at)
    MEM_W(0X7974, ctx->r1) = ctx->r12;
    // 0x800B497C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800B4980: addiu       $t6, $t6, -0x2768
    ctx->r14 = ADD32(ctx->r14, -0X2768);
    // 0x800B4984: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800B4988: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800B498C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4990: addiu       $t8, $t8, 0x7E84
    ctx->r24 = ADD32(ctx->r24, 0X7E84);
    // 0x800B4994: sw          $t7, 0x797C($at)
    MEM_W(0X797C, ctx->r1) = ctx->r15;
    // 0x800B4998: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800B499C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_800B49A0:
    // 0x800B49A0: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B49A4: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B49A8: addiu       $t0, $t0, 0x79A8
    ctx->r8 = ADD32(ctx->r8, 0X79A8);
    // 0x800B49AC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800B49B0: addu        $t5, $t0, $t2
    ctx->r13 = ADD32(ctx->r8, ctx->r10);
    // 0x800B49B4: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800B49B8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B49BC: addiu       $t3, $t3, 0x7990
    ctx->r11 = ADD32(ctx->r11, 0X7990);
    // 0x800B49C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800B49C4: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x800B49C8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800B49CC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B49D0: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800B49D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B49D8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B49DC: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800B49E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800B49E4: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B49E8: lui         $a3, 0x3FC0
    ctx->r7 = S32(0X3FC0 << 16);
    // 0x800B49EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800B49F0: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800B49F4: jal         0x8009BC2C
    // 0x800B49F8: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B49F8: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
    after_0:
    // 0x800B49FC: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B4A00: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B4A04: addiu       $t5, $t5, 0x7990
    ctx->r13 = ADD32(ctx->r13, 0X7990);
    // 0x800B4A08: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800B4A0C: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x800B4A10: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800B4A14: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B4A18: addiu       $t1, $t1, 0x7984
    ctx->r9 = ADD32(ctx->r9, 0X7984);
    // 0x800B4A1C: slti        $at, $a0, 0x64
    ctx->r1 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
    // 0x800B4A20: bne         $at, $zero, L_800B4A40
    if (ctx->r1 != 0) {
        // 0x800B4A24: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_800B4A40;
    }
    // 0x800B4A24: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B4A28: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B4A2C: addiu       $t6, $a0, -0x64
    ctx->r14 = ADD32(ctx->r4, -0X64);
    // 0x800B4A30: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800B4A34: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800B4A38: sb          $t4, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r12;
    // 0x800B4A3C: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
L_800B4A40:
    // 0x800B4A40: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800B4A44: addiu       $t9, $t9, 0x7BD0
    ctx->r25 = ADD32(ctx->r25, 0X7BD0);
    // 0x800B4A48: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800B4A4C: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x800B4A50: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B4A54: beq         $a0, $zero, L_800B4A7C
    if (ctx->r4 == 0) {
        // 0x800B4A58: addiu       $t2, $a0, -0x1
        ctx->r10 = ADD32(ctx->r4, -0X1);
            goto L_800B4A7C;
    }
    // 0x800B4A58: addiu       $t2, $a0, -0x1
    ctx->r10 = ADD32(ctx->r4, -0X1);
    // 0x800B4A5C: sh          $t2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r10;
    // 0x800B4A60: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x800B4A64: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x800B4A68: bnel        $t5, $zero, L_800B4A80
    if (ctx->r13 != 0) {
        // 0x800B4A6C: lw          $v0, 0x1C8($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X1C8);
            goto L_800B4A80;
    }
    goto skip_0;
    // 0x800B4A6C: lw          $v0, 0x1C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C8);
    skip_0:
    // 0x800B4A70: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800B4A74: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B4A78: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
L_800B4A7C:
    // 0x800B4A7C: lw          $v0, 0x1C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C8);
L_800B4A80:
    // 0x800B4A80: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800B4A84: bnel        $at, $zero, L_800B4A9C
    if (ctx->r1 != 0) {
        // 0x800B4A88: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800B4A9C;
    }
    goto skip_1;
    // 0x800B4A88: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    skip_1:
    // 0x800B4A8C: jal         0x800B39E0
    // 0x800B4A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateEffects(rdram, ctx);
        goto after_1;
    // 0x800B4A90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800B4A94: lw          $v0, 0x1C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B4A98: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_800B4A9C:
    // 0x800B4A9C: bne         $at, $zero, L_800B4B60
    if (ctx->r1 != 0) {
        // 0x800B4AA0: sw          $zero, 0x228($s0)
        MEM_W(0X228, ctx->r16) = 0;
            goto L_800B4B60;
    }
    // 0x800B4AA0: sw          $zero, 0x228($s0)
    MEM_W(0X228, ctx->r16) = 0;
    // 0x800B4AA4: lw          $t7, 0x1CC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B4AA8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B4AAC: bnel        $t7, $zero, L_800B4B64
    if (ctx->r15 != 0) {
        // 0x800B4AB0: lw          $v0, 0x22C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X22C);
            goto L_800B4B64;
    }
    goto skip_2;
    // 0x800B4AB0: lw          $v0, 0x22C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X22C);
    skip_2:
    // 0x800B4AB4: lw          $t8, 0x78E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78E8);
    // 0x800B4AB8: bnel        $t8, $zero, L_800B4B64
    if (ctx->r24 != 0) {
        // 0x800B4ABC: lw          $v0, 0x22C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X22C);
            goto L_800B4B64;
    }
    goto skip_3;
    // 0x800B4ABC: lw          $v0, 0x22C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X22C);
    skip_3:
    // 0x800B4AC0: lw          $v0, 0x204($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X204);
    // 0x800B4AC4: lui         $a0, 0x301
    ctx->r4 = S32(0X301 << 16);
    // 0x800B4AC8: addiu       $a0, $a0, 0x5AF4
    ctx->r4 = ADD32(ctx->r4, 0X5AF4);
    // 0x800B4ACC: beq         $v0, $zero, L_800B4AF4
    if (ctx->r2 == 0) {
        // 0x800B4AD0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800B4AF4;
    }
    // 0x800B4AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B4AD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B4AD8: beq         $v0, $at, L_800B4B04
    if (ctx->r2 == ctx->r1) {
        // 0x800B4ADC: lui         $a0, 0x301
        ctx->r4 = S32(0X301 << 16);
            goto L_800B4B04;
    }
    // 0x800B4ADC: lui         $a0, 0x301
    ctx->r4 = S32(0X301 << 16);
    // 0x800B4AE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B4AE4: beq         $v0, $at, L_800B4B1C
    if (ctx->r2 == ctx->r1) {
        // 0x800B4AE8: lui         $a0, 0x301
        ctx->r4 = S32(0X301 << 16);
            goto L_800B4B1C;
    }
    // 0x800B4AE8: lui         $a0, 0x301
    ctx->r4 = S32(0X301 << 16);
    // 0x800B4AEC: b           L_800B4B30
    // 0x800B4AF0: lw          $a3, 0x1C4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C4);
        goto L_800B4B30;
    // 0x800B4AF0: lw          $a3, 0x1C4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C4);
L_800B4AF4:
    // 0x800B4AF4: jal         0x8009AA20
    // 0x800B4AF8: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    Animation_GetFrameData(rdram, ctx);
        goto after_2;
    // 0x800B4AF8: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x800B4AFC: b           L_800B4B30
    // 0x800B4B00: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800B4B30;
    // 0x800B4B00: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800B4B04:
    // 0x800B4B04: addiu       $a0, $a0, 0x5C28
    ctx->r4 = ADD32(ctx->r4, 0X5C28);
    // 0x800B4B08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B4B0C: jal         0x8009AA20
    // 0x800B4B10: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    Animation_GetFrameData(rdram, ctx);
        goto after_3;
    // 0x800B4B10: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_3:
    // 0x800B4B14: b           L_800B4B30
    // 0x800B4B18: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_800B4B30;
    // 0x800B4B18: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800B4B1C:
    // 0x800B4B1C: addiu       $a0, $a0, 0x63C4
    ctx->r4 = ADD32(ctx->r4, 0X63C4);
    // 0x800B4B20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B4B24: jal         0x8009AA20
    // 0x800B4B28: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    Animation_GetFrameData(rdram, ctx);
        goto after_4;
    // 0x800B4B28: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_4:
    // 0x800B4B2C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800B4B30:
    // 0x800B4B30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4B34: lwc1        $f8, -0x7610($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7610);
    // 0x800B4B38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4B3C: lwc1        $f10, -0x760C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X760C);
    // 0x800B4B40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B4B44: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800B4B48: addiu       $a1, $s0, 0x2F8
    ctx->r5 = ADD32(ctx->r16, 0X2F8);
    // 0x800B4B4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B4B50: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800B4B54: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800B4B58: jal         0x8009BEEC
    // 0x800B4B5C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_5;
    // 0x800B4B5C: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_5:
L_800B4B60:
    // 0x800B4B60: lw          $v0, 0x22C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X22C);
L_800B4B64:
    // 0x800B4B64: sb          $zero, 0x494($s0)
    MEM_B(0X494, ctx->r16) = 0;
    // 0x800B4B68: sb          $zero, 0x48C($s0)
    MEM_B(0X48C, ctx->r16) = 0;
    // 0x800B4B6C: beq         $v0, $zero, L_800B4B78
    if (ctx->r2 == 0) {
        // 0x800B4B70: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800B4B78;
    }
    // 0x800B4B70: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800B4B74: sw          $t2, 0x22C($s0)
    MEM_W(0X22C, ctx->r16) = ctx->r10;
L_800B4B78:
    // 0x800B4B78: lw          $t3, 0x1C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B4B7C: sltiu       $at, $t3, 0xE
    ctx->r1 = ctx->r11 < 0XE ? 1 : 0;
    // 0x800B4B80: beq         $at, $zero, L_800B5544
    if (ctx->r1 == 0) {
        // 0x800B4B84: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_800B5544;
    }
    // 0x800B4B84: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800B4B88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4B8C: addu        $at, $at, $t3
    gpr jr_addend_800B4B94 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800B4B90: lw          $t3, -0x7608($at)
    ctx->r11 = ADD32(ctx->r1, -0X7608);
    // 0x800B4B94: jr          $t3
    // 0x800B4B98: nop

    switch (jr_addend_800B4B94 >> 2) {
        case 0: goto L_800B4B9C; break;
        case 1: goto L_800B4BB8; break;
        case 2: goto L_800B4BD4; break;
        case 3: goto L_800B4C00; break;
        case 4: goto L_800B4F08; break;
        case 5: goto L_800B4F18; break;
        case 6: goto L_800B5238; break;
        case 7: goto L_800B5044; break;
        case 8: goto L_800B50A0; break;
        case 9: goto L_800B50C8; break;
        case 10: goto L_800B5118; break;
        case 11: goto L_800B5138; break;
        case 12: goto L_800B5150; break;
        case 13: goto L_800B5158; break;
        default: switch_error(__func__, 0x800B4B94, 0x800D89F8);
    }
    // 0x800B4B98: nop

L_800B4B9C:
    // 0x800B4B9C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B4BA0: addiu       $a1, $a1, 0x1A2C
    ctx->r5 = ADD32(ctx->r5, 0X1A2C);
    // 0x800B4BA4: sw          $zero, 0x234($s0)
    MEM_W(0X234, ctx->r16) = 0;
    // 0x800B4BA8: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x800B4BAC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4BB0: b           L_800B5544
    // 0x800B4BB4: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
        goto L_800B5544;
    // 0x800B4BB4: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
L_800B4BB8:
    // 0x800B4BB8: jal         0x800B0F50
    // 0x800B4BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Setup(rdram, ctx);
        goto after_6;
    // 0x800B4BBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x800B4BC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B4BC4: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x800B4BC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4BCC: b           L_800B5544
    // 0x800B4BD0: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
        goto L_800B5544;
    // 0x800B4BD0: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
L_800B4BD4:
    // 0x800B4BD4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B4BD8: addiu       $a1, $a1, 0x1A2C
    ctx->r5 = ADD32(ctx->r5, 0X1A2C);
    // 0x800B4BDC: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x800B4BE0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4BE4: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
    // 0x800B4BE8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B4BEC: sb          $t5, 0x4C8($s0)
    MEM_B(0X4C8, ctx->r16) = ctx->r13;
    // 0x800B4BF0: jal         0x8004A52C
    // 0x800B4BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_LevelStart(rdram, ctx);
        goto after_7;
    // 0x800B4BF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800B4BF8: b           L_800B5544
    // 0x800B4BFC: nop

        goto L_800B5544;
    // 0x800B4BFC: nop

L_800B4C00:
    // 0x800B4C00: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B4C04: addiu       $a1, $a1, 0x1A2C
    ctx->r5 = ADD32(ctx->r5, 0X1A2C);
    // 0x800B4C08: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B4C0C: sb          $t6, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r14;
    // 0x800B4C10: jal         0x800B46F8
    // 0x800B4C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_LowHealthMsg(rdram, ctx);
        goto after_8;
    // 0x800B4C14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800B4C18: sb          $zero, 0x4C8($s0)
    MEM_B(0X4C8, ctx->r16) = 0;
    // 0x800B4C1C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B4C20: lw          $v1, 0x78E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78E8);
    // 0x800B4C24: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800B4C28: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B4C2C: beq         $v1, $zero, L_800B4C44
    if (ctx->r3 == 0) {
        // 0x800B4C30: sw          $t4, 0x1704($at)
        MEM_W(0X1704, ctx->r1) = ctx->r12;
            goto L_800B4C44;
    }
    // 0x800B4C30: sw          $t4, 0x1704($at)
    MEM_W(0X1704, ctx->r1) = ctx->r12;
    // 0x800B4C34: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B4C38: lw          $t7, 0x7E7C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7E7C);
    // 0x800B4C3C: beq         $t7, $zero, L_800B4D2C
    if (ctx->r15 == 0) {
        // 0x800B4C40: nop
    
            goto L_800B4D2C;
    }
    // 0x800B4C40: nop

L_800B4C44:
    // 0x800B4C44: lw          $t8, 0x4DC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4DC);
    // 0x800B4C48: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B4C4C: addiu       $t0, $t0, 0x797C
    ctx->r8 = ADD32(ctx->r8, 0X797C);
    // 0x800B4C50: bne         $t8, $zero, L_800B4D2C
    if (ctx->r24 != 0) {
        // 0x800B4C54: nop
    
            goto L_800B4D2C;
    }
    // 0x800B4C54: nop

    // 0x800B4C58: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B4C5C: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x800B4C60: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x800B4C64: beq         $t3, $zero, L_800B4D2C
    if (ctx->r11 == 0) {
        // 0x800B4C68: nop
    
            goto L_800B4D2C;
    }
    // 0x800B4C68: nop

    // 0x800B4C6C: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B4C70: beql        $v0, $zero, L_800B4C8C
    if (ctx->r2 == 0) {
        // 0x800B4C74: lw          $t5, 0x238($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X238);
            goto L_800B4C8C;
    }
    goto skip_4;
    // 0x800B4C74: lw          $t5, 0x238($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X238);
    skip_4:
    // 0x800B4C78: beq         $v1, $zero, L_800B4D2C
    if (ctx->r3 == 0) {
        // 0x800B4C7C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B4D2C;
    }
    // 0x800B4C7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B4C80: bne         $v0, $at, L_800B4D2C
    if (ctx->r2 != ctx->r1) {
        // 0x800B4C84: nop
    
            goto L_800B4D2C;
    }
    // 0x800B4C84: nop

    // 0x800B4C88: lw          $t5, 0x238($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X238);
L_800B4C8C:
    // 0x800B4C8C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B4C90: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800B4C94: subu        $v0, $t6, $t5
    ctx->r2 = SUB32(ctx->r14, ctx->r13);
    // 0x800B4C98: beq         $v0, $zero, L_800B4CD8
    if (ctx->r2 == 0) {
        // 0x800B4C9C: sw          $v0, 0x238($s0)
        MEM_W(0X238, ctx->r16) = ctx->r2;
            goto L_800B4CD8;
    }
    // 0x800B4C9C: sw          $v0, 0x238($s0)
    MEM_W(0X238, ctx->r16) = ctx->r2;
    // 0x800B4CA0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800B4CA4: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x800B4CA8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800B4CAC: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x800B4CB0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800B4CB4: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800B4CB8: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800B4CBC: ori         $a0, $a0, 0x2C
    ctx->r4 = ctx->r4 | 0X2C;
    // 0x800B4CC0: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800B4CC4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800B4CC8: jal         0x80019218
    // 0x800B4CCC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x800B4CCC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_9:
    // 0x800B4CD0: b           L_800B4D20
    // 0x800B4CD4: nop

        goto L_800B4D20;
    // 0x800B4CD4: nop

L_800B4CD8:
    // 0x800B4CD8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800B4CDC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800B4CE0: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x800B4CE4: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800B4CE8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800B4CEC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800B4CF0: ori         $a0, $a0, 0x2D
    ctx->r4 = ctx->r4 | 0X2D;
    // 0x800B4CF4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800B4CF8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800B4CFC: jal         0x80019218
    // 0x800B4D00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x800B4D00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_10:
    // 0x800B4D04: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B4D08: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x800B4D0C: bne         $t8, $zero, L_800B4D20
    if (ctx->r24 != 0) {
        // 0x800B4D10: nop
    
            goto L_800B4D20;
    }
    // 0x800B4D10: nop

    // 0x800B4D14: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B4D18: nop

    // 0x800B4D1C: swc1        $f18, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f18.u32l;
L_800B4D20:
    // 0x800B4D20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4D24: lwc1        $f4, -0x75D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X75D0);
    // 0x800B4D28: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
L_800B4D2C:
    // 0x800B4D2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B4D30: lw          $v0, 0x7880($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7880);
    // 0x800B4D34: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B4D38: addiu       $t0, $t0, 0x797C
    ctx->r8 = ADD32(ctx->r8, 0X797C);
    // 0x800B4D3C: beq         $v0, $zero, L_800B4D64
    if (ctx->r2 == 0) {
        // 0x800B4D40: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800B4D64;
    }
    // 0x800B4D40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B4D44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B4D48: beq         $v0, $at, L_800B4D80
    if (ctx->r2 == ctx->r1) {
        // 0x800B4D4C: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_800B4D80;
    }
    // 0x800B4D4C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B4D50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B4D54: beq         $v0, $at, L_800B4EE8
    if (ctx->r2 == ctx->r1) {
        // 0x800B4D58: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800B4EE8;
    }
    // 0x800B4D58: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B4D5C: b           L_800B5544
    // 0x800B4D60: nop

        goto L_800B5544;
    // 0x800B4D60: nop

L_800B4D64:
    // 0x800B4D64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B4D68: sw          $t9, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r25;
    // 0x800B4D6C: jal         0x800B42B0
    // 0x800B4D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateOnRails(rdram, ctx);
        goto after_11;
    // 0x800B4D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x800B4D74: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B4D78: b           L_800B5544
    // 0x800B4D7C: sw          $t2, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r10;
        goto L_800B5544;
    // 0x800B4D7C: sw          $t2, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r10;
L_800B4D80:
    // 0x800B4D80: lw          $t3, 0x78E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78E8);
    // 0x800B4D84: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B4D88: bne         $t3, $zero, L_800B4DA4
    if (ctx->r11 != 0) {
        // 0x800B4D8C: nop
    
            goto L_800B4DA4;
    }
    // 0x800B4D8C: nop

    // 0x800B4D90: jal         0x800B44C4
    // 0x800B4D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Update360(rdram, ctx);
        goto after_12;
    // 0x800B4D94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x800B4D98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B4D9C: b           L_800B5544
    // 0x800B4DA0: sw          $t6, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r14;
        goto L_800B5544;
    // 0x800B4DA0: sw          $t6, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r14;
L_800B4DA4:
    // 0x800B4DA4: lw          $v1, 0x7E7C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E7C);
    // 0x800B4DA8: beql        $v1, $zero, L_800B4EC4
    if (ctx->r3 == 0) {
        // 0x800B4DAC: lw          $t2, 0x0($t0)
        ctx->r10 = MEM_W(ctx->r8, 0X0);
            goto L_800B4EC4;
    }
    goto skip_5;
    // 0x800B4DAC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    skip_5:
    // 0x800B4DB0: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B4DB4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800B4DB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B4DBC: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800B4DC0: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x800B4DC4: lw          $t7, 0x1A18($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A18);
    // 0x800B4DC8: bnel        $t7, $at, L_800B4E38
    if (ctx->r15 != ctx->r1) {
        // 0x800B4DCC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B4E38;
    }
    goto skip_6;
    // 0x800B4DCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_6:
L_800B4DD0:
    // 0x800B4DD0: jal         0x80004EB0
    // 0x800B4DD4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_13;
    // 0x800B4DD4: nop

    after_13:
    // 0x800B4DD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4DDC: lwc1        $f6, -0x75CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X75CC);
    // 0x800B4DE0: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800B4DE4: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800B4DE8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800B4DEC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800B4DF0: nop

    // 0x800B4DF4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800B4DF8: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800B4DFC: lw          $t2, 0x1A18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1A18);
    // 0x800B4E00: bne         $t2, $zero, L_800B4DD0
    if (ctx->r10 != 0) {
        // 0x800B4E04: nop
    
            goto L_800B4DD0;
    }
    // 0x800B4E04: nop

    // 0x800B4E08: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B4E0C: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x800B4E10: sw          $v0, 0x288($s0)
    MEM_W(0X288, ctx->r16) = ctx->r2;
    // 0x800B4E14: sw          $t3, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r11;
    // 0x800B4E18: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    // 0x800B4E1C: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x800B4E20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B4E24: jal         0x800B5FBC
    // 0x800B4E28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Camera_FollowPlayer(rdram, ctx);
        goto after_14;
    // 0x800B4E28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x800B4E2C: b           L_800B5544
    // 0x800B4E30: nop

        goto L_800B5544;
    // 0x800B4E30: nop

    // 0x800B4E34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800B4E38:
    // 0x800B4E38: bne         $v1, $at, L_800B4EAC
    if (ctx->r3 != ctx->r1) {
        // 0x800B4E3C: addiu       $t6, $v1, 0x1
        ctx->r14 = ADD32(ctx->r3, 0X1);
            goto L_800B4EAC;
    }
    // 0x800B4E3C: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x800B4E40: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4E44: sw          $t6, 0x7E7C($at)
    MEM_W(0X7E7C, ctx->r1) = ctx->r14;
    // 0x800B4E48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B4E4C:
    // 0x800B4E4C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800B4E50: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x800B4E54: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B4E58: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x800B4E5C: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x800B4E60: lw          $a2, 0x1C4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X1C4);
    // 0x800B4E64: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800B4E68: jal         0x800A5FA0
    // 0x800B4E6C: addiu       $a0, $v1, 0x460
    ctx->r4 = ADD32(ctx->r3, 0X460);
    Player_PlaySfx(rdram, ctx);
        goto after_15;
    // 0x800B4E6C: addiu       $a0, $v1, 0x460
    ctx->r4 = ADD32(ctx->r3, 0X460);
    after_15:
    // 0x800B4E70: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800B4E74: addiu       $a1, $a1, -0x7D80
    ctx->r5 = ADD32(ctx->r5, -0X7D80);
    // 0x800B4E78: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800B4E7C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800B4E80: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B4E84: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B4E88: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x800B4E8C: addiu       $at, $zero, 0x1380
    ctx->r1 = ADD32(0, 0X1380);
    // 0x800B4E90: swc1        $f16, 0x194($t7)
    MEM_W(0X194, ctx->r15) = ctx->f16.u32l;
    // 0x800B4E94: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800B4E98: addu        $v1, $t8, $v0
    ctx->r3 = ADD32(ctx->r24, ctx->r2);
    // 0x800B4E9C: lwc1        $f18, 0x194($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X194);
    // 0x800B4EA0: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
    // 0x800B4EA4: bne         $v0, $at, L_800B4E4C
    if (ctx->r2 != ctx->r1) {
        // 0x800B4EA8: swc1        $f18, 0x190($v1)
        MEM_W(0X190, ctx->r3) = ctx->f18.u32l;
            goto L_800B4E4C;
    }
    // 0x800B4EA8: swc1        $f18, 0x190($v1)
    MEM_W(0X190, ctx->r3) = ctx->f18.u32l;
L_800B4EAC:
    // 0x800B4EAC: jal         0x800B44C4
    // 0x800B4EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Update360(rdram, ctx);
        goto after_16;
    // 0x800B4EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x800B4EB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B4EB8: b           L_800B5544
    // 0x800B4EBC: sw          $t9, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r25;
        goto L_800B5544;
    // 0x800B4EBC: sw          $t9, 0x234($s0)
    MEM_W(0X234, ctx->r16) = ctx->r25;
    // 0x800B4EC0: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
L_800B4EC4:
    // 0x800B4EC4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4EC8: sb          $zero, 0x3($t2)
    MEM_B(0X3, ctx->r10) = 0;
    // 0x800B4ECC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800B4ED0: lb          $t3, 0x3($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X3);
    // 0x800B4ED4: sb          $t3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r11;
    // 0x800B4ED8: sw          $zero, 0x7844($at)
    MEM_W(0X7844, ctx->r1) = 0;
    // 0x800B4EDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B4EE0: b           L_800B5544
    // 0x800B4EE4: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
        goto L_800B5544;
    // 0x800B4EE4: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
L_800B4EE8:
    // 0x800B4EE8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B4EEC: sw          $t6, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r14;
    // 0x800B4EF0: jal         0x801A5AD4
    // 0x800B4EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Turret_Update(rdram, ctx);
        goto after_17;
    // 0x800B4EF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x800B4EF8: jal         0x800A8BA4
    // 0x800B4EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_18;
    // 0x800B4EFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x800B4F00: b           L_800B5544
    // 0x800B4F04: nop

        goto L_800B5544;
    // 0x800B4F04: nop

L_800B4F08:
    // 0x800B4F08: jal         0x8004E3D8
    // 0x800B4F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_PlayerDown(rdram, ctx);
        goto after_19;
    // 0x800B4F0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x800B4F10: b           L_800B5544
    // 0x800B4F14: nop

        goto L_800B5544;
    // 0x800B4F14: nop

L_800B4F18:
    // 0x800B4F18: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B4F1C: lw          $t5, 0x78E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78E8);
    // 0x800B4F20: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B4F24: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B4F28: beq         $t5, $zero, L_800B4F7C
    if (ctx->r13 == 0) {
        // 0x800B4F2C: addiu       $a1, $zero, 0x0
        ctx->r5 = ADD32(0, 0X0);
            goto L_800B4F7C;
    }
    // 0x800B4F2C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B4F30: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B4F34: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B4F38: addiu       $a0, $a0, 0x7B00
    ctx->r4 = ADD32(ctx->r4, 0X7B00);
    // 0x800B4F3C: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x800B4F40: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800B4F44: sw          $zero, 0xC($t8)
    MEM_W(0XC, ctx->r24) = 0;
    // 0x800B4F48: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B4F4C: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x800B4F50: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x800B4F54: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800B4F58: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800B4F5C: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B4F60: sll         $t6, $t3, 4
    ctx->r14 = S32(ctx->r11 << 4);
    // 0x800B4F64: addu        $t5, $a0, $t6
    ctx->r13 = ADD32(ctx->r4, ctx->r14);
    // 0x800B4F68: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x800B4F6C: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B4F70: sll         $t7, $t4, 4
    ctx->r15 = S32(ctx->r12 << 4);
    // 0x800B4F74: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800B4F78: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
L_800B4F7C:
    // 0x800B4F7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B4F80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B4F84: sb          $t9, 0x4C8($s0)
    MEM_B(0X4C8, ctx->r16) = ctx->r25;
    // 0x800B4F88: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x800B4F8C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B4F90: jal         0x8009BC2C
    // 0x800B4F94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x800B4F94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_20:
    // 0x800B4F98: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B4F9C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B4FA0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B4FA4: addiu       $a0, $s0, 0x4A4
    ctx->r4 = ADD32(ctx->r16, 0X4A4);
    // 0x800B4FA8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B4FAC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B4FB0: jal         0x8009BC2C
    // 0x800B4FB4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x800B4FB4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_21:
    // 0x800B4FB8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B4FBC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B4FC0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B4FC4: addiu       $a0, $s0, 0x4A8
    ctx->r4 = ADD32(ctx->r16, 0X4A8);
    // 0x800B4FC8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B4FCC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B4FD0: jal         0x8009BC2C
    // 0x800B4FD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_22;
    // 0x800B4FD4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_22:
    // 0x800B4FD8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B4FDC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B4FE0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B4FE4: addiu       $a0, $s0, 0x4AC
    ctx->r4 = ADD32(ctx->r16, 0X4AC);
    // 0x800B4FE8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B4FEC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B4FF0: jal         0x8009BC2C
    // 0x800B4FF4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x800B4FF4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x800B4FF8: jal         0x800B40AC
    // 0x800B4FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateShields(rdram, ctx);
        goto after_24;
    // 0x800B4FFC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800B5000: jal         0x8004CCC0
    // 0x800B5004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_UTurn(rdram, ctx);
        goto after_25;
    // 0x800B5004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x800B5008: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800B500C: lw          $t2, -0x7DCC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7DCC);
    // 0x800B5010: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B5014: bne         $t2, $at, L_800B502C
    if (ctx->r10 != ctx->r1) {
        // 0x800B5018: nop
    
            goto L_800B502C;
    }
    // 0x800B5018: nop

    // 0x800B501C: jal         0x800A8BA4
    // 0x800B5020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CollisionCheck(rdram, ctx);
        goto after_26;
    // 0x800B5020: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x800B5024: b           L_800B5544
    // 0x800B5028: nop

        goto L_800B5544;
    // 0x800B5028: nop

L_800B502C:
    // 0x800B502C: jal         0x800A887C
    // 0x800B5030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateHitbox(rdram, ctx);
        goto after_27;
    // 0x800B5030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x800B5034: jal         0x800A86E4
    // 0x800B5038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_CheckItemCollect(rdram, ctx);
        goto after_28;
    // 0x800B5038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x800B503C: b           L_800B5544
    // 0x800B5040: nop

        goto L_800B5544;
    // 0x800B5040: nop

L_800B5044:
    // 0x800B5044: sw          $zero, 0x238($s0)
    MEM_W(0X238, ctx->r16) = 0;
    // 0x800B5048: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B504C: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
    // 0x800B5050: jal         0x800B40AC
    // 0x800B5054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateShields(rdram, ctx);
        goto after_29;
    // 0x800B5054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x800B5058: jal         0x8004C930
    // 0x800B505C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_LevelComplete(rdram, ctx);
        goto after_30;
    // 0x800B505C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x800B5060: jal         0x800A4C40
    // 0x800B5064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_WaterEffects(rdram, ctx);
        goto after_31;
    // 0x800B5064: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x800B5068: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B506C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B5070: addiu       $v1, $v1, 0x79C8
    ctx->r3 = ADD32(ctx->r3, 0X79C8);
    // 0x800B5074: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800B5078: addu        $t5, $v1, $t6
    ctx->r13 = ADD32(ctx->r3, ctx->r14);
    // 0x800B507C: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800B5080: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B5084: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B5088: addiu       $a1, $a1, 0x1A2C
    ctx->r5 = ADD32(ctx->r5, 0X1A2C);
    // 0x800B508C: sll         $t7, $t4, 2
    ctx->r15 = S32(ctx->r12 << 2);
    // 0x800B5090: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800B5094: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B5098: b           L_800B5544
    // 0x800B509C: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
        goto L_800B5544;
    // 0x800B509C: sb          $t9, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r25;
L_800B50A0:
    // 0x800B50A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B50A4: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
    // 0x800B50A8: jal         0x800B40AC
    // 0x800B50AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateShields(rdram, ctx);
        goto after_32;
    // 0x800B50AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x800B50B0: jal         0x80049C0C
    // 0x800B50B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_EnterWarpZone(rdram, ctx);
        goto after_33;
    // 0x800B50B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x800B50B8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B50BC: addiu       $a1, $a1, 0x1A2C
    ctx->r5 = ADD32(ctx->r5, 0X1A2C);
    // 0x800B50C0: b           L_800B5544
    // 0x800B50C4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
        goto L_800B5544;
    // 0x800B50C4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_800B50C8:
    // 0x800B50C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B50CC: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
    // 0x800B50D0: jal         0x800B40AC
    // 0x800B50D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateShields(rdram, ctx);
        goto after_34;
    // 0x800B50D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_34:
    // 0x800B50D8: jal         0x8004AAF4
    // 0x800B50DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Cutscene_AllRangeMode(rdram, ctx);
        goto after_35;
    // 0x800B50DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x800B50E0: jal         0x800B2130
    // 0x800B50E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateArwingRoll(rdram, ctx);
        goto after_36;
    // 0x800B50E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x800B50E8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B50EC: addiu       $a1, $a1, 0x1A2C
    ctx->r5 = ADD32(ctx->r5, 0X1A2C);
    // 0x800B50F0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x800B50F4: lw          $t2, 0x1C4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B50F8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B50FC: addiu       $v1, $v1, 0x79C8
    ctx->r3 = ADD32(ctx->r3, 0X79C8);
    // 0x800B5100: andi        $v0, $zero, 0xFF
    ctx->r2 = 0 & 0XFF;
    // 0x800B5104: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B5108: addu        $t6, $v1, $t3
    ctx->r14 = ADD32(ctx->r3, ctx->r11);
    // 0x800B510C: sw          $v0, 0x238($s0)
    MEM_W(0X238, ctx->r16) = ctx->r2;
    // 0x800B5110: b           L_800B5544
    // 0x800B5114: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
        goto L_800B5544;
    // 0x800B5114: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
L_800B5118:
    // 0x800B5118: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B511C: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
    // 0x800B5120: jal         0x8002E700
    // 0x800B5124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AllRange_GreatFoxRepair(rdram, ctx);
        goto after_37;
    // 0x800B5124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_37:
    // 0x800B5128: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B512C: addiu       $a1, $a1, 0x1A2C
    ctx->r5 = ADD32(ctx->r5, 0X1A2C);
    // 0x800B5130: b           L_800B5544
    // 0x800B5134: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
        goto L_800B5544;
    // 0x800B5134: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
L_800B5138:
    // 0x800B5138: jal         0x8018C390
    // 0x800B513C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Andross_AbsorbArwing(rdram, ctx);
        goto after_38;
    // 0x800B513C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x800B5140: jal         0x800B40AC
    // 0x800B5144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_UpdateShields(rdram, ctx);
        goto after_39;
    // 0x800B5144: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_39:
    // 0x800B5148: b           L_800B5544
    // 0x800B514C: nop

        goto L_800B5544;
    // 0x800B514C: nop

L_800B5150:
    // 0x800B5150: b           L_800B5544
    // 0x800B5154: nop

        goto L_800B5544;
    // 0x800B5154: nop

L_800B5158:
    // 0x800B5158: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B515C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800B5160: sw          $zero, 0x234($s0)
    MEM_W(0X234, ctx->r16) = 0;
    // 0x800B5164: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x800B5168: addu        $t7, $t7, $t4
    ctx->r15 = ADD32(ctx->r15, ctx->r12);
    // 0x800B516C: lw          $t7, 0x1A18($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A18);
    // 0x800B5170: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B5174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B5178: bne         $t7, $at, L_800B5198
    if (ctx->r15 != ctx->r1) {
        // 0x800B517C: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_800B5198;
    }
    // 0x800B517C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B5180: lw          $a1, 0x288($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X288);
    // 0x800B5184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B5188: jal         0x800B5FBC
    // 0x800B518C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    Camera_FollowPlayer(rdram, ctx);
        goto after_40;
    // 0x800B518C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_40:
    // 0x800B5190: b           L_800B5544
    // 0x800B5194: nop

        goto L_800B5544;
    // 0x800B5194: nop

L_800B5198:
    // 0x800B5198: lw          $t8, 0x7E74($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7E74);
    // 0x800B519C: bnel        $t8, $zero, L_800B5208
    if (ctx->r24 != 0) {
        // 0x800B51A0: lw          $v0, 0x288($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X288);
            goto L_800B5208;
    }
    goto skip_7;
    // 0x800B51A0: lw          $v0, 0x288($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X288);
    skip_7:
    // 0x800B51A4: lw          $t9, 0x1D0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1D0);
    // 0x800B51A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B51AC: beql        $t9, $zero, L_800B5208
    if (ctx->r25 == 0) {
        // 0x800B51B0: lw          $v0, 0x288($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X288);
            goto L_800B5208;
    }
    goto skip_8;
    // 0x800B51B0: lw          $v0, 0x288($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X288);
    skip_8:
    // 0x800B51B4: jal         0x800AB304
    // 0x800B51B8: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    Player_Initialize(rdram, ctx);
        goto after_41;
    // 0x800B51B8: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    after_41:
    // 0x800B51BC: jal         0x800B0F50
    // 0x800B51C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Setup(rdram, ctx);
        goto after_42;
    // 0x800B51C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x800B51C4: jal         0x800B44C4
    // 0x800B51C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Player_Update360(rdram, ctx);
        goto after_43;
    // 0x800B51C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x800B51CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B51D0: jal         0x800B7184
    // 0x800B51D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Camera_Update360(rdram, ctx);
        goto after_44;
    // 0x800B51D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_44:
    // 0x800B51D8: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B51DC: ori         $a1, $a1, 0x2
    ctx->r5 = ctx->r5 | 0X2;
    // 0x800B51E0: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800B51E4: jal         0x800A5FA0
    // 0x800B51E8: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    Player_PlaySfx(rdram, ctx);
        goto after_45;
    // 0x800B51E8: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    after_45:
    // 0x800B51EC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B51F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B51F4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B51F8: swc1        $f16, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f16.u32l;
    // 0x800B51FC: b           L_800B5544
    // 0x800B5200: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
        goto L_800B5544;
    // 0x800B5200: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
    // 0x800B5204: lw          $v0, 0x288($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X288);
L_800B5208:
    // 0x800B5208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B520C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B5210: bltz        $v0, L_800B5230
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B5214: nop
    
            goto L_800B5230;
    }
    // 0x800B5214: nop

    // 0x800B5218: bne         $v0, $zero, L_800B5228
    if (ctx->r2 != 0) {
        // 0x800B521C: nop
    
            goto L_800B5228;
    }
    // 0x800B521C: nop

    // 0x800B5220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800B5224: sw          $v0, 0x288($s0)
    MEM_W(0X288, ctx->r16) = ctx->r2;
L_800B5228:
    // 0x800B5228: jal         0x800B5FBC
    // 0x800B522C: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    Camera_FollowPlayer(rdram, ctx);
        goto after_46;
    // 0x800B522C: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    after_46:
L_800B5230:
    // 0x800B5230: b           L_800B5544
    // 0x800B5234: nop

        goto L_800B5544;
    // 0x800B5234: nop

L_800B5238:
    // 0x800B5238: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800B523C: addiu       $a1, $a1, 0x1A2C
    ctx->r5 = ADD32(ctx->r5, 0X1A2C);
    // 0x800B5240: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x800B5244: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B5248: lw          $t3, 0x78E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78E8);
    // 0x800B524C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B5250: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B5254: bne         $t3, $zero, L_800B5264
    if (ctx->r11 != 0) {
        // 0x800B5258: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800B5264;
    }
    // 0x800B5258: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B525C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5260: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
L_800B5264:
    // 0x800B5264: sw          $zero, 0x234($s0)
    MEM_W(0X234, ctx->r16) = 0;
    // 0x800B5268: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x800B526C: swc1        $f0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f0.u32l;
    // 0x800B5270: swc1        $f0, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f0.u32l;
    // 0x800B5274: swc1        $f0, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f0.u32l;
    // 0x800B5278: swc1        $f0, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f0.u32l;
    // 0x800B527C: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x800B5280: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B5284: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800B5288: bne         $t6, $at, L_800B52C4
    if (ctx->r14 != ctx->r1) {
        // 0x800B528C: addiu       $a0, $s0, 0x44
        ctx->r4 = ADD32(ctx->r16, 0X44);
            goto L_800B52C4;
    }
    // 0x800B528C: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800B5290: lw          $t5, -0x7C84($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C84);
    // 0x800B5294: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800B5298: bne         $t5, $at, L_800B52C4
    if (ctx->r13 != ctx->r1) {
        // 0x800B529C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800B52C4;
    }
    // 0x800B529C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B52A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B52A4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B52A8: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800B52AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B52B0: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800B52B4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B52B8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B52BC: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x800B52C0: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
L_800B52C4:
    // 0x800B52C4: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x800B52C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800B52CC: lui         $a1, 0x43FA
    ctx->r5 = S32(0X43FA << 16);
    // 0x800B52D0: beq         $v1, $at, L_800B52E0
    if (ctx->r3 == ctx->r1) {
        // 0x800B52D4: lui         $a2, 0x3D4C
        ctx->r6 = S32(0X3D4C << 16);
            goto L_800B52E0;
    }
    // 0x800B52D4: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B52D8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800B52DC: bne         $v1, $at, L_800B5330
    if (ctx->r3 != ctx->r1) {
        // 0x800B52E0: ori         $a2, $a2, 0xCCCD
        ctx->r6 = ctx->r6 | 0XCCCD;
            goto L_800B5330;
    }
L_800B52E0:
    // 0x800B52E0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B52E4: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B52E8: jal         0x8009BC2C
    // 0x800B52EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_47;
    // 0x800B52EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_47:
    // 0x800B52F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B52F4: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800B52F8: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800B52FC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800B5300: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B5304: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B5308: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B530C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B5310: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B5314: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B5318: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800B531C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800B5320: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800B5324: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800B5328: jal         0x8009BC2C
    // 0x800B532C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_48;
    // 0x800B532C: nop

    after_48:
L_800B5330:
    // 0x800B5330: lw          $t4, 0x1F8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F8);
    // 0x800B5334: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B5338: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800B533C: bne         $t4, $zero, L_800B5544
    if (ctx->r12 != 0) {
        // 0x800B5340: nop
    
            goto L_800B5544;
    }
    // 0x800B5340: nop

    // 0x800B5344: lw          $t7, 0x78A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A8);
    // 0x800B5348: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B534C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B5350: bne         $t7, $at, L_800B536C
    if (ctx->r15 != ctx->r1) {
        // 0x800B5354: addiu       $v0, $v0, -0x7CAC
        ctx->r2 = ADD32(ctx->r2, -0X7CAC);
            goto L_800B536C;
    }
    // 0x800B5354: addiu       $v0, $v0, -0x7CAC
    ctx->r2 = ADD32(ctx->r2, -0X7CAC);
    // 0x800B5358: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x800B535C: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x800B5360: sw          $t8, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r24;
    // 0x800B5364: b           L_800B5390
    // 0x800B5368: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
        goto L_800B5390;
    // 0x800B5368: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
L_800B536C:
    // 0x800B536C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B5370: addiu       $v1, $v1, -0x7CB0
    ctx->r3 = ADD32(ctx->r3, -0X7CB0);
    // 0x800B5374: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B5378: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B537C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5380: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x800B5384: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5388: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800B538C: sw          $t6, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r14;
L_800B5390:
    // 0x800B5390: lw          $t5, -0x7CC0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7CC0);
    // 0x800B5394: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800B5398: bne         $t5, $at, L_800B5544
    if (ctx->r13 != ctx->r1) {
        // 0x800B539C: nop
    
            goto L_800B5544;
    }
    // 0x800B539C: nop

    // 0x800B53A0: jal         0x800A6148
    // 0x800B53A4: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_49;
    // 0x800B53A4: nop

    after_49:
    // 0x800B53A8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B53AC: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x800B53B0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800B53B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800B53B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B53BC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B53C0: swc1        $f4, 0x144($t4)
    MEM_W(0X144, ctx->r12) = ctx->f4.u32l;
    // 0x800B53C4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B53C8: addiu       $v0, $v0, -0x7D64
    ctx->r2 = ADD32(ctx->r2, -0X7D64);
    // 0x800B53CC: lwc1        $f6, 0x144($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X144);
    // 0x800B53D0: swc1        $f6, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f6.u32l;
    // 0x800B53D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B53D8: sw          $zero, -0x7C80($at)
    MEM_W(-0X7C80, ctx->r1) = 0;
    // 0x800B53DC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B53E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B53E4: jal         0x8001AE58
    // 0x800B53E8: sw          $zero, -0x6C4($at)
    MEM_W(-0X6C4, ctx->r1) = 0;
    Audio_ClearVoice(rdram, ctx);
        goto after_50;
    // 0x800B53E8: sw          $zero, -0x6C4($at)
    MEM_W(-0X6C4, ctx->r1) = 0;
    after_50:
    // 0x800B53EC: jal         0x8001D400
    // 0x800B53F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_SetEnvSfxReverb(rdram, ctx);
        goto after_51;
    // 0x800B53F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_51:
    // 0x800B53F4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800B53F8: lbu         $v0, 0x1A90($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A90);
    // 0x800B53FC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800B5400: addiu       $a0, $a0, 0x1A94
    ctx->r4 = ADD32(ctx->r4, 0X1A94);
    // 0x800B5404: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800B5408: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800B540C: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x800B5410: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800B5414: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800B5418: bne         $v1, $at, L_800B5428
    if (ctx->r3 != ctx->r1) {
        // 0x800B541C: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_800B5428;
    }
    // 0x800B541C: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x800B5420: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5424: sw          $v0, 0x7C94($at)
    MEM_W(0X7C94, ctx->r1) = ctx->r2;
L_800B5428:
    // 0x800B5428: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B542C: lw          $v0, -0x7C84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7C84);
    // 0x800B5430: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B5434: beq         $v0, $at, L_800B5524
    if (ctx->r2 == ctx->r1) {
        // 0x800B5438: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800B5524;
    }
    // 0x800B5438: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800B543C: beq         $v0, $at, L_800B544C
    if (ctx->r2 == ctx->r1) {
        // 0x800B5440: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_800B544C;
    }
    // 0x800B5440: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5444: b           L_800B5544
    // 0x800B5448: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
        goto L_800B5544;
    // 0x800B5448: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
L_800B544C:
    // 0x800B544C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B5450: bne         $v1, $at, L_800B5494
    if (ctx->r3 != ctx->r1) {
        // 0x800B5454: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_800B5494;
    }
    // 0x800B5454: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800B5458: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B545C: sw          $t9, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r25;
    // 0x800B5460: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5464: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800B5468: sw          $t2, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r10;
    // 0x800B546C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5470: sw          $zero, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = 0;
    // 0x800B5474: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5478: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x800B547C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B5480: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x800B5484: sh          $t3, 0x1A34($at)
    MEM_H(0X1A34, ctx->r1) = ctx->r11;
    // 0x800B5488: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B548C: b           L_800B5544
    // 0x800B5490: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
        goto L_800B5544;
    // 0x800B5490: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
L_800B5494:
    // 0x800B5494: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B5498: beq         $v1, $at, L_800B54A8
    if (ctx->r3 == ctx->r1) {
        // 0x800B549C: addiu       $t4, $zero, 0x5
        ctx->r12 = ADD32(0, 0X5);
            goto L_800B54A8;
    }
    // 0x800B549C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800B54A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B54A4: bne         $v1, $at, L_800B54B0
    if (ctx->r3 != ctx->r1) {
        // 0x800B54A8: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800B54B0;
    }
L_800B54A8:
    // 0x800B54A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B54AC: sw          $zero, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = 0;
L_800B54B0:
    // 0x800B54B0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B54B4: lw          $v1, 0x78A0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X78A0);
    // 0x800B54B8: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x800B54BC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B54C0: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x800B54C4: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800B54C8: lh          $t5, 0x1AA0($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X1AA0);
    // 0x800B54CC: bgezl       $t5, L_800B54E4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B54D0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800B54E4;
    }
    goto skip_9;
    // 0x800B54D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    skip_9:
    // 0x800B54D4: sh          $t4, 0x1A32($at)
    MEM_H(0X1A32, ctx->r1) = ctx->r12;
    // 0x800B54D8: b           L_800B54EC
    // 0x800B54DC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
        goto L_800B54EC;
    // 0x800B54DC: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800B54E0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_800B54E4:
    // 0x800B54E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B54E8: sw          $t7, 0x7854($at)
    MEM_W(0X7854, ctx->r1) = ctx->r15;
L_800B54EC:
    // 0x800B54EC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800B54F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B54F4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B54F8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800B54FC: sw          $t8, 0x7DA0($at)
    MEM_W(0X7DA0, ctx->r1) = ctx->r24;
    // 0x800B5500: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B5504: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800B5508: sw          $zero, 0x1AA8($at)
    MEM_W(0X1AA8, ctx->r1) = 0;
    // 0x800B550C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B5510: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B5514: sw          $t9, -0x7B78($at)
    MEM_W(-0X7B78, ctx->r1) = ctx->r25;
    // 0x800B5518: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B551C: b           L_800B5544
    // 0x800B5520: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
        goto L_800B5544;
    // 0x800B5520: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
L_800B5524:
    // 0x800B5524: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B5528: sh          $t2, 0x1A32($at)
    MEM_H(0X1A32, ctx->r1) = ctx->r10;
    // 0x800B552C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800B5530: sh          $t3, 0x1A34($at)
    MEM_H(0X1A34, ctx->r1) = ctx->r11;
    // 0x800B5534: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B5538: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x800B553C: b           L_800B5544
    // 0x800B5540: nop

        goto L_800B5544;
    // 0x800B5540: nop

L_800B5544:
    // 0x800B5544: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B5548: lw          $v0, 0x7C70($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C70);
    // 0x800B554C: addiu       $a0, $s0, 0x148
    ctx->r4 = ADD32(ctx->r16, 0X148);
    // 0x800B5550: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B5554: bne         $v0, $zero, L_800B557C
    if (ctx->r2 != 0) {
        // 0x800B5558: lui         $a3, 0x3D4C
        ctx->r7 = S32(0X3D4C << 16);
            goto L_800B557C;
    }
    // 0x800B5558: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x800B555C: lw          $t6, 0x1CC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B5560: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5564: bnel        $t6, $zero, L_800B5580
    if (ctx->r14 != 0) {
        // 0x800B5568: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B5580;
    }
    goto skip_10;
    // 0x800B5568: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_10:
    // 0x800B556C: lwc1        $f2, -0x75C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X75C8);
    // 0x800B5570: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5574: b           L_800B55AC
    // 0x800B5578: lwc1        $f12, -0x75C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X75C4);
        goto L_800B55AC;
    // 0x800B5578: lwc1        $f12, -0x75C4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X75C4);
L_800B557C:
    // 0x800B557C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800B5580:
    // 0x800B5580: bne         $v0, $at, L_800B5598
    if (ctx->r2 != ctx->r1) {
        // 0x800B5584: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800B5598;
    }
    // 0x800B5584: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5588: lwc1        $f2, -0x75C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X75C0);
    // 0x800B558C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B5590: b           L_800B55AC
    // 0x800B5594: lwc1        $f12, -0x75BC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X75BC);
        goto L_800B55AC;
    // 0x800B5594: lwc1        $f12, -0x75BC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X75BC);
L_800B5598:
    // 0x800B5598: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B559C: lwc1        $f2, -0x75B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X75B8);
    // 0x800B55A0: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x800B55A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B55A8: nop

L_800B55AC:
    // 0x800B55AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B55B0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B55B4: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B55B8: swc1        $f2, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->f2.u32l;
    // 0x800B55BC: swc1        $f12, 0x1C8($sp)
    MEM_W(0X1C8, ctx->r29) = ctx->f12.u32l;
    // 0x800B55C0: jal         0x8009BC2C
    // 0x800B55C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_52;
    // 0x800B55C4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_52:
    // 0x800B55C8: lwc1        $f2, 0x1CC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1CC);
    // 0x800B55CC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B55D0: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x800B55D4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800B55D8: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B55DC: addiu       $a0, $s0, 0x14C
    ctx->r4 = ADD32(ctx->r16, 0X14C);
    // 0x800B55E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B55E4: jal         0x8009BC2C
    // 0x800B55E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_53;
    // 0x800B55E8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_53:
    // 0x800B55EC: lwc1        $f12, 0x1C8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C8);
    // 0x800B55F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B55F4: addiu       $a0, $s0, 0x9C
    ctx->r4 = ADD32(ctx->r16, 0X9C);
    // 0x800B55F8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800B55FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B5600: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B5604: jal         0x8009BC2C
    // 0x800B5608: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_54;
    // 0x800B5608: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_54:
    // 0x800B560C: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B5610: addiu       $a0, $s0, 0x194
    ctx->r4 = ADD32(ctx->r16, 0X194);
    // 0x800B5614: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x800B5618: bne         $v0, $zero, L_800B5674
    if (ctx->r2 != 0) {
        // 0x800B561C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B5674;
    }
    // 0x800B561C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B5620: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B5624: lw          $a1, 0x190($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X190);
    // 0x800B5628: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B562C: jal         0x8009BC2C
    // 0x800B5630: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_55;
    // 0x800B5630: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_55:
    // 0x800B5634: lw          $t5, 0x2B4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2B4);
    // 0x800B5638: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B563C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B5640: beq         $t5, $zero, L_800B5664
    if (ctx->r13 == 0) {
        // 0x800B5644: lui         $t4, 0x8018
        ctx->r12 = S32(0X8018 << 16);
            goto L_800B5664;
    }
    // 0x800B5644: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800B5648: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x800B564C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B5650: lw          $t7, 0x1C8($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X1C8);
    // 0x800B5654: bnel        $t7, $at, L_800B5668
    if (ctx->r15 != ctx->r1) {
        // 0x800B5658: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800B5668;
    }
    goto skip_11;
    // 0x800B5658: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_11:
    // 0x800B565C: b           L_800B56A8
    // 0x800B5660: swc1        $f2, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f2.u32l;
        goto L_800B56A8;
    // 0x800B5660: swc1        $f2, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f2.u32l;
L_800B5664:
    // 0x800B5664: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800B5668:
    // 0x800B5668: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B566C: b           L_800B56A8
    // 0x800B5670: swc1        $f4, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f4.u32l;
        goto L_800B56A8;
    // 0x800B5670: swc1        $f4, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f4.u32l;
L_800B5674:
    // 0x800B5674: bne         $v0, $at, L_800B56A8
    if (ctx->r2 != ctx->r1) {
        // 0x800B5678: addiu       $a0, $s0, 0x194
        ctx->r4 = ADD32(ctx->r16, 0X194);
            goto L_800B56A8;
    }
    // 0x800B5678: addiu       $a0, $s0, 0x194
    ctx->r4 = ADD32(ctx->r16, 0X194);
    // 0x800B567C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B5680: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B5684: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B5688: lw          $a1, 0x190($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X190);
    // 0x800B568C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800B5690: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800B5694: jal         0x8009BC2C
    // 0x800B5698: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_56;
    // 0x800B5698: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_56:
    // 0x800B569C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B56A0: nop

    // 0x800B56A4: swc1        $f8, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f8.u32l;
L_800B56A8:
    // 0x800B56A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B56AC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B56B0: addiu       $sp, $sp, 0x1D0
    ctx->r29 = ADD32(ctx->r29, 0X1D0);
    // 0x800B56B4: jr          $ra
    // 0x800B56B8: nop

    return;
    // 0x800B56B8: nop

;}
RECOMP_FUNC void Versus_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C1EDC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800C1EE0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800C1EE4: lw          $t7, -0x779C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X779C);
    // 0x800C1EE8: lw          $t6, -0x77A0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X77A0);
    // 0x800C1EEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1EF0: sw          $t7, -0x7794($at)
    MEM_W(-0X7794, ctx->r1) = ctx->r15;
    // 0x800C1EF4: jal         0x80023000
    // 0x800C1EF8: sw          $t6, -0x7798($at)
    MEM_W(-0X7798, ctx->r1) = ctx->r14;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x800C1EF8: sw          $t6, -0x7798($at)
    MEM_W(-0X7798, ctx->r1) = ctx->r14;
    after_0:
    // 0x800C1EFC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800C1F00: lw          $t8, -0x7888($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7888);
    // 0x800C1F04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1F08: sw          $v0, -0x77A0($at)
    MEM_W(-0X77A0, ctx->r1) = ctx->r2;
    // 0x800C1F0C: sw          $v1, -0x779C($at)
    MEM_W(-0X779C, ctx->r1) = ctx->r3;
    // 0x800C1F10: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800C1F14: sltiu       $at, $t9, 0xB
    ctx->r1 = ctx->r25 < 0XB ? 1 : 0;
    // 0x800C1F18: beq         $at, $zero, L_800C2080
    if (ctx->r1 == 0) {
        // 0x800C1F1C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800C2080;
    }
    // 0x800C1F1C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800C1F20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C1F24: addu        $at, $at, $t9
    gpr jr_addend_800C1F2C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800C1F28: lw          $t9, -0x6D08($at)
    ctx->r25 = ADD32(ctx->r1, -0X6D08);
    // 0x800C1F2C: jr          $t9
    // 0x800C1F30: nop

    switch (jr_addend_800C1F2C >> 2) {
        case 0: goto L_800C1F34; break;
        case 1: goto L_800C1F44; break;
        case 2: goto L_800C1FEC; break;
        case 3: goto L_800C1FAC; break;
        case 4: goto L_800C1F68; break;
        case 5: goto L_800C1F54; break;
        case 6: goto L_800C1F54; break;
        case 7: goto L_800C2034; break;
        case 8: goto L_800C2078; break;
        case 9: goto L_800C202C; break;
        case 10: goto L_800C2044; break;
        default: switch_error(__func__, 0x800C1F2C, 0x800D92F8);
    }
    // 0x800C1F30: nop

L_800C1F34:
    // 0x800C1F34: jal         0x800BEDDC
    // 0x800C1F38: nop

    func_versus_800BEDDC(rdram, ctx);
        goto after_1;
    // 0x800C1F38: nop

    after_1:
    // 0x800C1F3C: b           L_800C2080
    // 0x800C1F40: nop

        goto L_800C2080;
    // 0x800C1F40: nop

L_800C1F44:
    // 0x800C1F44: jal         0x800BEFE4
    // 0x800C1F48: nop

    func_versus_800BEFE4(rdram, ctx);
        goto after_2;
    // 0x800C1F48: nop

    after_2:
    // 0x800C1F4C: b           L_800C2080
    // 0x800C1F50: nop

        goto L_800C2080;
    // 0x800C1F50: nop

L_800C1F54:
    // 0x800C1F54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1F58: lwc1        $f12, -0x7834($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7834);
    // 0x800C1F5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1F60: jal         0x800C0970
    // 0x800C1F64: lwc1        $f14, -0x7830($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7830);
    func_versus_800C0970(rdram, ctx);
        goto after_3;
    // 0x800C1F64: lwc1        $f14, -0x7830($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7830);
    after_3:
L_800C1F68:
    // 0x800C1F68: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800C1F6C: lw          $v0, 0x78AC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78AC);
    // 0x800C1F70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C1F74: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C1F78: beq         $v0, $zero, L_800C1F90
    if (ctx->r2 == 0) {
        // 0x800C1F7C: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_800C1F90;
    }
    // 0x800C1F7C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800C1F80: beq         $v0, $at, L_800C1FA4
    if (ctx->r2 == ctx->r1) {
        // 0x800C1F84: nop
    
            goto L_800C1FA4;
    }
    // 0x800C1F84: nop

    // 0x800C1F88: b           L_800C1FAC
    // 0x800C1F8C: nop

        goto L_800C1FAC;
    // 0x800C1F8C: nop

L_800C1F90:
    // 0x800C1F90: lw          $a0, -0x7848($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7848);
    // 0x800C1F94: jal         0x800C1138
    // 0x800C1F98: lw          $a1, -0x7858($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7858);
    func_versus_800C1138(rdram, ctx);
        goto after_4;
    // 0x800C1F98: lw          $a1, -0x7858($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7858);
    after_4:
    // 0x800C1F9C: b           L_800C1FAC
    // 0x800C1FA0: nop

        goto L_800C1FAC;
    // 0x800C1FA0: nop

L_800C1FA4:
    // 0x800C1FA4: jal         0x800C0E78
    // 0x800C1FA8: nop

    func_versus_800C0E78(rdram, ctx);
        goto after_5;
    // 0x800C1FA8: nop

    after_5:
L_800C1FAC:
    // 0x800C1FAC: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800C1FB0: lw          $t0, 0x78AC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78AC);
    // 0x800C1FB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C1FB8: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800C1FBC: bne         $t0, $at, L_800C1FD4
    if (ctx->r8 != ctx->r1) {
        // 0x800C1FC0: lui         $t3, 0x8018
        ctx->r11 = S32(0X8018 << 16);
            goto L_800C1FD4;
    }
    // 0x800C1FC0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800C1FC4: lw          $t1, 0x4A98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4A98);
    // 0x800C1FC8: andi        $t2, $t1, 0x20
    ctx->r10 = ctx->r9 & 0X20;
    // 0x800C1FCC: bne         $t2, $zero, L_800C1FEC
    if (ctx->r10 != 0) {
        // 0x800C1FD0: nop
    
            goto L_800C1FEC;
    }
    // 0x800C1FD0: nop

L_800C1FD4:
    // 0x800C1FD4: lw          $t3, -0x7858($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7858);
    // 0x800C1FD8: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800C1FDC: beq         $at, $zero, L_800C1FEC
    if (ctx->r1 == 0) {
        // 0x800C1FE0: nop
    
            goto L_800C1FEC;
    }
    // 0x800C1FE0: nop

    // 0x800C1FE4: jal         0x800C075C
    // 0x800C1FE8: nop

    func_versus_800C075C(rdram, ctx);
        goto after_6;
    // 0x800C1FE8: nop

    after_6:
L_800C1FEC:
    // 0x800C1FEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1FF0: lwc1        $f12, -0x7840($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7840);
    // 0x800C1FF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C1FF8: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800C1FFC: lw          $a2, -0x7858($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7858);
    // 0x800C2000: jal         0x800C04DC
    // 0x800C2004: lwc1        $f14, -0x7838($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7838);
    func_versus_800C04DC(rdram, ctx);
        goto after_7;
    // 0x800C2004: lwc1        $f14, -0x7838($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7838);
    after_7:
    // 0x800C2008: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800C200C: lw          $t4, -0x7888($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7888);
    // 0x800C2010: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800C2014: bne         $t4, $at, L_800C2080
    if (ctx->r12 != ctx->r1) {
        // 0x800C2018: nop
    
            goto L_800C2080;
    }
    // 0x800C2018: nop

    // 0x800C201C: jal         0x800C0B0C
    // 0x800C2020: nop

    func_versus_800C0B0C(rdram, ctx);
        goto after_8;
    // 0x800C2020: nop

    after_8:
    // 0x800C2024: b           L_800C2080
    // 0x800C2028: nop

        goto L_800C2080;
    // 0x800C2028: nop

L_800C202C:
    // 0x800C202C: jal         0x800BDE44
    // 0x800C2030: nop

    func_versus_800BDE44(rdram, ctx);
        goto after_9;
    // 0x800C2030: nop

    after_9:
L_800C2034:
    // 0x800C2034: jal         0x800BF750
    // 0x800C2038: nop

    func_versus_800BF750(rdram, ctx);
        goto after_10;
    // 0x800C2038: nop

    after_10:
    // 0x800C203C: jal         0x800BF59C
    // 0x800C2040: nop

    func_versus_800BF59C(rdram, ctx);
        goto after_11;
    // 0x800C2040: nop

    after_11:
L_800C2044:
    // 0x800C2044: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800C2048: lw          $t5, 0x78AC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78AC);
    // 0x800C204C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C2050: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800C2054: bne         $t5, $at, L_800C2080
    if (ctx->r13 != ctx->r1) {
        // 0x800C2058: lui         $at, 0x42F8
        ctx->r1 = S32(0X42F8 << 16);
            goto L_800C2080;
    }
    // 0x800C2058: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x800C205C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C2060: lui         $at, 0x42E8
    ctx->r1 = S32(0X42E8 << 16);
    // 0x800C2064: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C2068: jal         0x800BE300
    // 0x800C206C: addiu       $a2, $a2, -0x7898
    ctx->r6 = ADD32(ctx->r6, -0X7898);
    Versus_DrawCountdown(rdram, ctx);
        goto after_12;
    // 0x800C206C: addiu       $a2, $a2, -0x7898
    ctx->r6 = ADD32(ctx->r6, -0X7898);
    after_12:
    // 0x800C2070: b           L_800C2080
    // 0x800C2074: nop

        goto L_800C2080;
    // 0x800C2074: nop

L_800C2078:
    // 0x800C2078: jal         0x800C1764
    // 0x800C207C: nop

    Versus_dummy_800C1764(rdram, ctx);
        goto after_13;
    // 0x800C207C: nop

    after_13:
L_800C2080:
    // 0x800C2080: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800C2084: lw          $a1, -0x77D0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X77D0);
    // 0x800C2088: slti        $at, $a1, 0x79
    ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
    // 0x800C208C: bne         $at, $zero, L_800C2098
    if (ctx->r1 != 0) {
        // 0x800C2090: nop
    
            goto L_800C2098;
    }
    // 0x800C2090: nop

    // 0x800C2094: addiu       $a1, $zero, 0x79
    ctx->r5 = ADD32(0, 0X79);
L_800C2098:
    // 0x800C2098: jal         0x80084688
    // 0x800C209C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Wipe_Draw(rdram, ctx);
        goto after_14;
    // 0x800C209C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_14:
    // 0x800C20A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C20A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C20A8: jr          $ra
    // 0x800C20AC: nop

    return;
    // 0x800C20AC: nop

;}
RECOMP_FUNC void Scenery_Initialize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061364: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80061368: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    // 0x8006136C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80061370:
    // 0x80061370: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80061374: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x80061378: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x8006137C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80061380: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80061384: bne         $v1, $a0, L_80061370
    if (ctx->r3 != ctx->r4) {
        // 0x80061388: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_80061370;
    }
    // 0x80061388: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x8006138C: jr          $ra
    // 0x80061390: nop

    return;
    // 0x80061390: nop

;}
RECOMP_FUNC void RCP_SetupDL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8DD0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B8DD4: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800B8DD8: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800B8DDC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B8DE0: sll         $t0, $a1, 3
    ctx->r8 = S32(ctx->r5 << 3);
    // 0x800B8DE4: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x800B8DE8: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800B8DEC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800B8DF0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B8DF4: addiu       $t2, $t2, 0x31B0
    ctx->r10 = ADD32(ctx->r10, 0X31B0);
    // 0x800B8DF8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800B8DFC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800B8E00: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800B8E04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B8E08: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800B8E0C: jr          $ra
    // 0x800B8E10: nop

    return;
    // 0x800B8E10: nop

;}
RECOMP_FUNC void func_versus_800BD0B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD0B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD0B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD0BC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800BD0C0: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800BD0C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD0C8: lui         $a1, 0x300
    ctx->r5 = S32(0X300 << 16);
    // 0x800BD0CC: lui         $a2, 0x300
    ctx->r6 = S32(0X300 << 16);
    // 0x800BD0D0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800BD0D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD0D8: addiu       $a2, $a2, 0x6A0
    ctx->r6 = ADD32(ctx->r6, 0X6A0);
    // 0x800BD0DC: addiu       $a1, $a1, 0x510
    ctx->r5 = ADD32(ctx->r5, 0X510);
    // 0x800BD0E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD0E4: addiu       $a3, $zero, 0x50
    ctx->r7 = ADD32(0, 0X50);
    // 0x800BD0E8: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD0EC: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD0F0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x800BD0F4: jal         0x8009C320
    // 0x800BD0F8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x800BD0F8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800BD0FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD104: jr          $ra
    // 0x800BD108: nop

    return;
    // 0x800BD108: nop

;}
RECOMP_FUNC void CoWaterfall_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AA98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006AA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006AAA0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8006AAA4: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x8006AAA8: addiu       $a0, $a0, 0x38F8
    ctx->r4 = ADD32(ctx->r4, 0X38F8);
    // 0x8006AAAC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8006AAB0: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8006AAB4: jal         0x80099A2C
    // 0x8006AAB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Lib_Texture_Scroll(rdram, ctx);
        goto after_0;
    // 0x8006AAB8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8006AABC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8006AAC0: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8006AAC4: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8006AAC8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8006AACC: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x8006AAD0: bnel        $t7, $zero, L_8006AB98
    if (ctx->r15 != 0) {
        // 0x8006AAD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006AB98;
    }
    goto skip_0;
    // 0x8006AAD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8006AAD8: lwc1        $f4, 0x14($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X14);
    // 0x8006AADC: lwc1        $f6, 0x6A80($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A80);
    // 0x8006AAE0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006AAE4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006AAE8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006AAEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006AAF0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8006AAF4: jal         0x80005E90
    // 0x8006AAF8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8006AAF8: nop

    after_1:
    // 0x8006AAFC: jal         0x80004EB0
    // 0x8006AB00: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8006AB00: nop

    after_2:
    // 0x8006AB04: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8006AB08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006AB0C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8006AB10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006AB14: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8006AB18: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006AB1C: jal         0x80004EB0
    // 0x8006AB20: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8006AB20: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8006AB24: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006AB28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8006AB2C: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x8006AB30: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006AB34: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006AB38: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006AB3C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8006AB40: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8006AB44: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8006AB48: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8006AB4C: jal         0x80006A20
    // 0x8006AB50: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_4;
    // 0x8006AB50: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x8006AB54: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8006AB58: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006AB5C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006AB60: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006AB64: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006AB68: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8006AB6C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006AB70: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006AB74: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8006AB78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006AB7C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8006AB80: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006AB84: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006AB88: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8006AB8C: jal         0x8006AA3C
    // 0x8006AB90: nop

    Obj54_8006AA3C(rdram, ctx);
        goto after_5;
    // 0x8006AB90: nop

    after_5:
    // 0x8006AB94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006AB98:
    // 0x8006AB98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8006AB9C: jr          $ra
    // 0x8006ABA0: nop

    return;
    // 0x8006ABA0: nop

;}
RECOMP_FUNC void AudioLoad_RelocateFont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F864: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8000F868: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8000F86C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000F870: lw          $t7, 0x5C70($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5C70);
    // 0x8000F874: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8000F878: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000F87C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000F880: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000F884: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000F888: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000F88C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000F890: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000F894: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000F898: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000F89C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000F8A0: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x8000F8A4: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x8000F8A8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8000F8AC: lbu         $s6, 0x1($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X1);
    // 0x8000F8B0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000F8B4: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8000F8B8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8000F8BC: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8000F8C0: beql        $v1, $zero, L_8000F938
    if (ctx->r3 == 0) {
        // 0x8000F8C4: lw          $t4, 0x40($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X40);
            goto L_8000F938;
    }
    goto skip_0;
    // 0x8000F8C4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x8000F8C8: beq         $s6, $zero, L_8000F934
    if (ctx->r22 == 0) {
        // 0x8000F8CC: addu        $t0, $v1, $a1
        ctx->r8 = ADD32(ctx->r3, ctx->r5);
            goto L_8000F934;
    }
    // 0x8000F8CC: addu        $t0, $v1, $a1
    ctx->r8 = ADD32(ctx->r3, ctx->r5);
    // 0x8000F8D0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8000F8D4: blez        $s6, L_8000F934
    if (SIGNED(ctx->r22) <= 0) {
        // 0x8000F8D8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8000F934;
    }
    // 0x8000F8D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000F8DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000F8E0: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_8000F8E4:
    // 0x8000F8E4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8000F8E8: addu        $v0, $t1, $s4
    ctx->r2 = ADD32(ctx->r9, ctx->r20);
    // 0x8000F8EC: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8000F8F0: beq         $s0, $zero, L_8000F928
    if (ctx->r16 == 0) {
        // 0x8000F8F4: addu        $s0, $s0, $s2
        ctx->r16 = ADD32(ctx->r16, ctx->r18);
            goto L_8000F928;
    }
    // 0x8000F8F4: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // 0x8000F8F8: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8000F8FC: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    // 0x8000F900: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x8000F904: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x8000F908: bne         $t2, $zero, L_8000F928
    if (ctx->r10 != 0) {
        // 0x8000F90C: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_8000F928;
    }
    // 0x8000F90C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000F910: jal         0x80010FE4
    // 0x8000F914: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    AudioLoad_RelocateSample(rdram, ctx);
        goto after_0;
    // 0x8000F914: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x8000F918: lw          $s0, 0xC($s1)
    ctx->r16 = MEM_W(ctx->r17, 0XC);
    // 0x8000F91C: sb          $s7, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r23;
    // 0x8000F920: addu        $t3, $s0, $s2
    ctx->r11 = ADD32(ctx->r16, ctx->r18);
    // 0x8000F924: sw          $t3, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r11;
L_8000F928:
    // 0x8000F928: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000F92C: bne         $s3, $s6, L_8000F8E4
    if (ctx->r19 != ctx->r22) {
        // 0x8000F930: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_8000F8E4;
    }
    // 0x8000F930: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_8000F934:
    // 0x8000F934: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
L_8000F938:
    // 0x8000F938: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8000F93C: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    // 0x8000F940: blez        $t4, L_8000F9D8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000F944: sll         $t5, $t4, 2
        ctx->r13 = S32(ctx->r12 << 2);
            goto L_8000F9D8;
    }
    // 0x8000F944: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8000F948: addu        $s4, $t5, $s2
    ctx->r20 = ADD32(ctx->r13, ctx->r18);
    // 0x8000F94C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8000F950: addiu       $s6, $zero, 0x7F
    ctx->r22 = ADD32(0, 0X7F);
    // 0x8000F954: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_8000F958:
    // 0x8000F958: beq         $v0, $zero, L_8000F9CC
    if (ctx->r2 == 0) {
        // 0x8000F95C: addu        $t6, $v0, $s2
        ctx->r14 = ADD32(ctx->r2, ctx->r18);
            goto L_8000F9CC;
    }
    // 0x8000F95C: addu        $t6, $v0, $s2
    ctx->r14 = ADD32(ctx->r2, ctx->r18);
    // 0x8000F960: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8000F964: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8000F968: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8000F96C: bnel        $t7, $zero, L_8000F9D0
    if (ctx->r15 != 0) {
        // 0x8000F970: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8000F9D0;
    }
    goto skip_1;
    // 0x8000F970: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    skip_1:
    // 0x8000F974: lbu         $t8, 0x1($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1);
    // 0x8000F978: addiu       $a0, $t6, 0x8
    ctx->r4 = ADD32(ctx->r14, 0X8);
    // 0x8000F97C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000F980: beql        $t8, $zero, L_8000F994
    if (ctx->r24 == 0) {
        // 0x8000F984: addiu       $a0, $s1, 0x10
        ctx->r4 = ADD32(ctx->r17, 0X10);
            goto L_8000F994;
    }
    goto skip_2;
    // 0x8000F984: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
    skip_2:
    // 0x8000F988: jal         0x80010FE4
    // 0x8000F98C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    AudioLoad_RelocateSample(rdram, ctx);
        goto after_1;
    // 0x8000F98C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_1:
    // 0x8000F990: addiu       $a0, $s1, 0x10
    ctx->r4 = ADD32(ctx->r17, 0X10);
L_8000F994:
    // 0x8000F994: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000F998: jal         0x80010FE4
    // 0x8000F99C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    AudioLoad_RelocateSample(rdram, ctx);
        goto after_2;
    // 0x8000F99C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_2:
    // 0x8000F9A0: lbu         $t9, 0x2($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X2);
    // 0x8000F9A4: addiu       $a0, $s1, 0x18
    ctx->r4 = ADD32(ctx->r17, 0X18);
    // 0x8000F9A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8000F9AC: beql        $s6, $t9, L_8000F9C0
    if (ctx->r22 == ctx->r25) {
        // 0x8000F9B0: lw          $s0, 0x4($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X4);
            goto L_8000F9C0;
    }
    goto skip_3;
    // 0x8000F9B0: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    skip_3:
    // 0x8000F9B4: jal         0x80010FE4
    // 0x8000F9B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    AudioLoad_RelocateSample(rdram, ctx);
        goto after_3;
    // 0x8000F9B8: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x8000F9BC: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
L_8000F9C0:
    // 0x8000F9C0: sb          $s7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r23;
    // 0x8000F9C4: addu        $t0, $s0, $s2
    ctx->r8 = ADD32(ctx->r16, ctx->r18);
    // 0x8000F9C8: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
L_8000F9CC:
    // 0x8000F9CC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8000F9D0:
    // 0x8000F9D0: bnel        $s4, $s3, L_8000F958
    if (ctx->r20 != ctx->r19) {
        // 0x8000F9D4: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_8000F958;
    }
    goto skip_4;
    // 0x8000F9D4: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_4:
L_8000F9D8:
    // 0x8000F9D8: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000F9DC: lw          $t2, 0x5C70($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5C70);
    // 0x8000F9E0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F9E4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8000F9E8: addiu       $t5, $s2, 0x4
    ctx->r13 = ADD32(ctx->r18, 0X4);
    // 0x8000F9EC: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8000F9F0: addu        $t6, $t2, $t3
    ctx->r14 = ADD32(ctx->r10, ctx->r11);
    // 0x8000F9F4: sw          $t1, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r9;
    // 0x8000F9F8: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x8000F9FC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8000FA00: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000FA04: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000FA08: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000FA0C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000FA10: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000FA14: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000FA18: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000FA1C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000FA20: jr          $ra
    // 0x8000FA24: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8000FA24: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Effect_WaterSpray_SpawnCircle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ADF4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8007ADF8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8007ADFC: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x8007AE00: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x8007AE04: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x8007AE08: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x8007AE0C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x8007AE10: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8007AE14: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8007AE18: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8007AE1C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8007AE20: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8007AE24: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x8007AE28: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x8007AE2C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8007AE30: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8007AE34: lui         $at, 0x4134
    ctx->r1 = S32(0X4134 << 16);
    // 0x8007AE38: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8007AE3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007AE40: lwc1        $f30, 0x73C0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X73C0);
    // 0x8007AE44: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8007AE48: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8007AE4C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8007AE50: addiu       $s1, $s1, 0x37E0
    ctx->r17 = ADD32(ctx->r17, 0X37E0);
    // 0x8007AE54: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8007AE58: lwc1        $f26, 0x78($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007AE5C: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_8007AE60:
    // 0x8007AE60: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8007AE64: addiu       $s0, $s0, 0x130
    ctx->r16 = ADD32(ctx->r16, 0X130);
    // 0x8007AE68: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
L_8007AE6C:
    // 0x8007AE6C: bnel        $t6, $zero, L_8007AEE0
    if (ctx->r14 != 0) {
        // 0x8007AE70: addiu       $s0, $s0, 0x8C
        ctx->r16 = ADD32(ctx->r16, 0X8C);
            goto L_8007AEE0;
    }
    goto skip_0;
    // 0x8007AE70: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
    skip_0:
    // 0x8007AE74: mul.s       $f20, $f30, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f30.fl, ctx->f22.fl);
    // 0x8007AE78: jal         0x80023090
    // 0x8007AE7C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8007AE7C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x8007AE80: mul.s       $f4, $f0, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8007AE84: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8007AE88: mul.s       $f24, $f4, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = MUL_S(ctx->f4.fl, ctx->f28.fl);
    // 0x8007AE8C: jal         0x80023250
    // 0x8007AE90: nop

    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8007AE90: nop

    after_1:
    // 0x8007AE94: mul.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8007AE98: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007AE9C: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007AEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007AEA4: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8007AEA8: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8007AEAC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007AEB0: mul.s       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f28.fl);
    // 0x8007AEB4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x8007AEB8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8007AEBC: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8007AEC0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8007AEC4: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8007AEC8: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007AECC: jal         0x8007AD58
    // 0x8007AED0: nop

    Effect_WaterSpray_SetupCircle(rdram, ctx);
        goto after_2;
    // 0x8007AED0: nop

    after_2:
    // 0x8007AED4: b           L_8007AEEC
    // 0x8007AED8: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
        goto L_8007AEEC;
    // 0x8007AED8: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
    // 0x8007AEDC: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
L_8007AEE0:
    // 0x8007AEE0: bnel        $s0, $s1, L_8007AE6C
    if (ctx->r16 != ctx->r17) {
        // 0x8007AEE4: lbu         $t6, 0x0($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X0);
            goto L_8007AE6C;
    }
    goto skip_1;
    // 0x8007AEE4: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    skip_1:
    // 0x8007AEE8: lui         $at, 0x41B4
    ctx->r1 = S32(0X41B4 << 16);
L_8007AEEC:
    // 0x8007AEEC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007AEF0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007AEF4: bne         $s2, $s3, L_8007AE60
    if (ctx->r18 != ctx->r19) {
        // 0x8007AEF8: add.s       $f22, $f22, $f8
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
            goto L_8007AE60;
    }
    // 0x8007AEF8: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x8007AEFC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8007AF00: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8007AF04: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8007AF08: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8007AF0C: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8007AF10: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8007AF14: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8007AF18: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x8007AF1C: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x8007AF20: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x8007AF24: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x8007AF28: jr          $ra
    // 0x8007AF2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8007AF2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
