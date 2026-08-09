#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void SectorY_SyRobotLaser_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197C64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80197C68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80197C6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80197C70: jal         0x800B9760
    // 0x80197C74: nop

    RCP_SetupDL_21(rdram, ctx);
        goto after_0;
    // 0x80197C74: nop

    after_0:
    // 0x80197C78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80197C7C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80197C80: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80197C84: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x80197C88: addiu       $t8, $t8, 0x4A40
    ctx->r24 = ADD32(ctx->r24, 0X4A40);
    // 0x80197C8C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80197C90: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80197C94: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x80197C98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80197C9C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80197CA0: jal         0x800B8DD0
    // 0x80197CA4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80197CA4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_1:
    // 0x80197CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80197CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80197CB0: jr          $ra
    // 0x80197CB4: nop

    return;
    // 0x80197CB4: nop

;}
RECOMP_FUNC void Andross_LoadLevelObjects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193710: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80193714: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80193718: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8019371C: addiu       $s2, $s2, -0x7CF0
    ctx->r18 = ADD32(ctx->r18, -0X7CF0);
    // 0x80193720: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80193724: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80193728: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8019372C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80193730: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80193734: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80193738: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x8019373C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80193740: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80193744: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80193748: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8019374C: lw          $v0, -0x260($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X260);
    // 0x80193750: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80193754: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80193758: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8019375C: srl         $t0, $t9, 28
    ctx->r8 = S32(U32(ctx->r25) >> 28);
    // 0x80193760: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80193764: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80193768: lw          $t2, 0x1FD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1FD0);
    // 0x8019376C: and         $t8, $v0, $at
    ctx->r24 = ctx->r2 & ctx->r1;
    // 0x80193770: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80193774: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x80193778: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x8019377C: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x80193780: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80193784: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
    // 0x80193788: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8019378C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80193790: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
L_80193794:
    // 0x80193794: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80193798: lh          $v0, 0x10($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X10);
    // 0x8019379C: bgez        $v0, L_801937AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801937A0: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_801937AC;
    }
    // 0x801937A0: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x801937A4: b           L_80193868
    // 0x801937A8: nop

        goto L_80193868;
    // 0x801937A8: nop

L_801937AC:
    // 0x801937AC: beql        $at, $zero, L_8019385C
    if (ctx->r1 == 0) {
        // 0x801937B0: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_8019385C;
    }
    goto skip_0;
    // 0x801937B0: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_0:
    // 0x801937B4: jal         0x800A4F4C
    // 0x801937B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Scenery360_Initialize(rdram, ctx);
        goto after_0;
    // 0x801937B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801937BC: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x801937C0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x801937C4: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801937C8: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x801937CC: lh          $t0, 0x10($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X10);
    // 0x801937D0: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x801937D4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x801937D8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801937DC: addu        $t8, $t1, $s1
    ctx->r24 = ADD32(ctx->r9, ctx->r17);
    // 0x801937E0: lh          $t2, 0x6($t8)
    ctx->r10 = MEM_H(ctx->r24, 0X6);
    // 0x801937E4: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801937E8: nop

    // 0x801937EC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801937F0: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x801937F4: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x801937F8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x801937FC: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x80193800: lh          $t5, 0x8($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X8);
    // 0x80193804: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80193808: nop

    // 0x8019380C: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80193810: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80193814: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80193818: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8019381C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80193820: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80193824: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80193828: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8019382C: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80193830: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80193834: addu        $t0, $t9, $s1
    ctx->r8 = ADD32(ctx->r25, ctx->r17);
    // 0x80193838: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8019383C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80193840: nop

    // 0x80193844: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80193848: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8019384C: jal         0x800612B8
    // 0x80193850: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80193850: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80193854: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80193858: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_8019385C:
    // 0x8019385C: slti        $at, $s1, 0x4E20
    ctx->r1 = SIGNED(ctx->r17) < 0X4E20 ? 1 : 0;
    // 0x80193860: bnel        $at, $zero, L_80193794
    if (ctx->r1 != 0) {
        // 0x80193864: lw          $t5, 0x0($s2)
        ctx->r13 = MEM_W(ctx->r18, 0X0);
            goto L_80193794;
    }
    goto skip_1;
    // 0x80193864: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    skip_1:
L_80193868:
    // 0x80193868: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8019386C: addiu       $s0, $s0, -0x6788
    ctx->r16 = ADD32(ctx->r16, -0X6788);
    // 0x80193870: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80193874: addiu       $s4, $zero, 0x4E20
    ctx->r20 = ADD32(0, 0X4E20);
    // 0x80193878: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8019387C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80193880:
    // 0x80193880: addu        $t2, $t8, $s1
    ctx->r10 = ADD32(ctx->r24, ctx->r17);
    // 0x80193884: lh          $v0, 0x10($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X10);
    // 0x80193888: bltz        $v0, L_80193950
    if (SIGNED(ctx->r2) < 0) {
        // 0x8019388C: slti        $at, $v0, 0xB0
        ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
            goto L_80193950;
    }
    // 0x8019388C: slti        $at, $v0, 0xB0
    ctx->r1 = SIGNED(ctx->r2) < 0XB0 ? 1 : 0;
    // 0x80193890: bne         $at, $zero, L_80193944
    if (ctx->r1 != 0) {
        // 0x80193894: slti        $at, $v0, 0x124
        ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
            goto L_80193944;
    }
    // 0x80193894: slti        $at, $v0, 0x124
    ctx->r1 = SIGNED(ctx->r2) < 0X124 ? 1 : 0;
    // 0x80193898: beql        $at, $zero, L_80193948
    if (ctx->r1 == 0) {
        // 0x8019389C: addiu       $s1, $s1, 0x14
        ctx->r17 = ADD32(ctx->r17, 0X14);
            goto L_80193948;
    }
    goto skip_2;
    // 0x8019389C: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
    skip_2:
    // 0x801938A0: jal         0x800613C4
    // 0x801938A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_2;
    // 0x801938A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801938A8: sb          $s3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r19;
    // 0x801938AC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x801938B0: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x801938B4: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x801938B8: lh          $t5, 0x10($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X10);
    // 0x801938BC: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x801938C0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x801938C4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x801938C8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x801938CC: lh          $t9, 0x6($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X6);
    // 0x801938D0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x801938D4: nop

    // 0x801938D8: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801938DC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x801938E0: swc1        $f0, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f0.u32l;
    // 0x801938E4: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x801938E8: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x801938EC: lh          $t8, 0x8($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X8);
    // 0x801938F0: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x801938F4: nop

    // 0x801938F8: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801938FC: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80193900: swc1        $f0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f0.u32l;
    // 0x80193904: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80193908: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x8019390C: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80193910: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80193914: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80193918: swc1        $f0, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f0.u32l;
    // 0x8019391C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80193920: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80193924: lh          $t6, 0xC($t5)
    ctx->r14 = MEM_H(ctx->r13, 0XC);
    // 0x80193928: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8019392C: nop

    // 0x80193930: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80193934: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80193938: jal         0x800612B8
    // 0x8019393C: swc1        $f0, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f0.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x8019393C: swc1        $f0, 0x148($s0)
    MEM_W(0X148, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x80193940: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_80193944:
    // 0x80193944: addiu       $s1, $s1, 0x14
    ctx->r17 = ADD32(ctx->r17, 0X14);
L_80193948:
    // 0x80193948: bnel        $s1, $s4, L_80193880
    if (ctx->r17 != ctx->r20) {
        // 0x8019394C: lw          $t8, 0x0($s2)
        ctx->r24 = MEM_W(ctx->r18, 0X0);
            goto L_80193880;
    }
    goto skip_3;
    // 0x8019394C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    skip_3:
L_80193950:
    // 0x80193950: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80193954: jal         0x80061404
    // 0x80193958: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    Boss_Initialize(rdram, ctx);
        goto after_4;
    // 0x80193958: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    after_4:
    // 0x8019395C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80193960: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193964: sb          $t7, -0xEF0($at)
    MEM_B(-0XEF0, ctx->r1) = ctx->r15;
    // 0x80193968: addiu       $a1, $zero, 0x138
    ctx->r5 = ADD32(0, 0X138);
    // 0x8019396C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193970: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80193974: addiu       $a0, $a0, -0xED4
    ctx->r4 = ADD32(ctx->r4, -0XED4);
    // 0x80193978: jal         0x800612B8
    // 0x8019397C: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x8019397C: sh          $a1, -0xEEE($at)
    MEM_H(-0XEEE, ctx->r1) = ctx->r5;
    after_5:
    // 0x80193980: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80193984: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80193988: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8019398C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80193990: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80193994: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80193998: jr          $ra
    // 0x8019399C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8019399C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Andross_Backdrop_RotEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801876FC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80187700: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80187704: lui         $a3, 0xFF
    ctx->r7 = S32(0XFF << 16);
    // 0x80187708: ori         $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 | 0XFFFF;
    // 0x8018770C: addiu       $a2, $a2, 0x1FD0
    ctx->r6 = ADD32(ctx->r6, 0X1FD0);
    // 0x80187710: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80187714: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80187718: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8018771C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80187720: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80187724: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80187728: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8018772C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80187730: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80187734: lui         $v0, 0xC04
    ctx->r2 = S32(0XC04 << 16);
    // 0x80187738: addiu       $v0, $v0, -0x6D70
    ctx->r2 = ADD32(ctx->r2, -0X6D70);
    // 0x8018773C: lui         $v1, 0xC04
    ctx->r3 = S32(0XC04 << 16);
    // 0x80187740: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x80187744: addiu       $v1, $v1, -0x5D70
    ctx->r3 = ADD32(ctx->r3, -0X5D70);
    // 0x80187748: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8018774C: sll         $t4, $v1, 4
    ctx->r12 = S32(ctx->r3 << 4);
    // 0x80187750: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80187754: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x80187758: addu        $t9, $a2, $t8
    ctx->r25 = ADD32(ctx->r6, ctx->r24);
    // 0x8018775C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80187760: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80187764: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x80187768: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8018776C: and         $t2, $v0, $a3
    ctx->r10 = ctx->r2 & ctx->r7;
    // 0x80187770: and         $t9, $v1, $a3
    ctx->r25 = ctx->r3 & ctx->r7;
    // 0x80187774: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80187778: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018777C: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x80187780: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80187784: addu        $s0, $t3, $t0
    ctx->r16 = ADD32(ctx->r11, ctx->r8);
    // 0x80187788: addu        $s3, $t1, $t0
    ctx->r19 = ADD32(ctx->r9, ctx->r8);
    // 0x8018778C: addiu       $s4, $s4, 0x7DB0
    ctx->r20 = ADD32(ctx->r20, 0X7DB0);
    // 0x80187790: lwc1        $f20, 0x6BC0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6BC0);
    // 0x80187794: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80187798: addiu       $s5, $zero, 0x400
    ctx->r21 = ADD32(0, 0X400);
    // 0x8018779C: addiu       $s1, $zero, 0x20
    ctx->r17 = ADD32(0, 0X20);
L_801877A0:
    // 0x801877A0: bgez        $s2, L_801877B0
    if (SIGNED(ctx->r18) >= 0) {
        // 0x801877A4: sra         $t2, $s2, 5
        ctx->r10 = S32(SIGNED(ctx->r18) >> 5);
            goto L_801877B0;
    }
    // 0x801877A4: sra         $t2, $s2, 5
    ctx->r10 = S32(SIGNED(ctx->r18) >> 5);
    // 0x801877A8: addiu       $at, $s2, 0x1F
    ctx->r1 = ADD32(ctx->r18, 0X1F);
    // 0x801877AC: sra         $t2, $at, 5
    ctx->r10 = S32(SIGNED(ctx->r1) >> 5);
L_801877B0:
    // 0x801877B0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x801877B4: bgez        $t3, L_801877C4
    if (SIGNED(ctx->r11) >= 0) {
        // 0x801877B8: sra         $t4, $t3, 1
        ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
            goto L_801877C4;
    }
    // 0x801877B8: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x801877BC: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x801877C0: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_801877C4:
    // 0x801877C4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x801877C8: andi        $t6, $t5, 0x1F
    ctx->r14 = ctx->r13 & 0X1F;
    // 0x801877CC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801877D0: nop

    // 0x801877D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801877D8: mul.s       $f12, $f6, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801877DC: jal         0x80023090
    // 0x801877E0: nop

    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x801877E0: nop

    after_0:
    // 0x801877E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801877E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801877EC: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x801877F0: addiu       $s3, $s3, 0x80
    ctx->r19 = ADD32(ctx->r19, 0X80);
    // 0x801877F4: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801877F8: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x801877FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80187800: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80187804: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80187808: nop

L_8018780C:
    // 0x8018780C: addu        $v0, $a1, $a0
    ctx->r2 = ADD32(ctx->r5, ctx->r4);
    // 0x80187810: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80187814: andi        $t9, $v0, 0x1F
    ctx->r25 = ctx->r2 & 0X1F;
    // 0x80187818: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8018781C: addu        $t3, $s0, $t1
    ctx->r11 = ADD32(ctx->r16, ctx->r9);
    // 0x80187820: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80187824: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x80187828: lw          $t2, 0x4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X4);
    // 0x8018782C: andi        $t5, $t4, 0x1F
    ctx->r13 = ctx->r12 & 0X1F;
    // 0x80187830: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80187834: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80187838: addiu       $t1, $v0, 0x2
    ctx->r9 = ADD32(ctx->r2, 0X2);
    // 0x8018783C: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x80187840: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80187844: andi        $t8, $t1, 0x1F
    ctx->r24 = ctx->r9 & 0X1F;
    // 0x80187848: sll         $t3, $t8, 2
    ctx->r11 = S32(ctx->r24 << 2);
    // 0x8018784C: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80187850: addiu       $t6, $v0, 0x3
    ctx->r14 = ADD32(ctx->r2, 0X3);
    // 0x80187854: andi        $t2, $t6, 0x1F
    ctx->r10 = ctx->r14 & 0X1F;
    // 0x80187858: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8018785C: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x80187860: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x80187864: addu        $t1, $s0, $t7
    ctx->r9 = ADD32(ctx->r16, ctx->r15);
    // 0x80187868: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8018786C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80187870: bne         $a0, $s1, L_8018780C
    if (ctx->r4 != ctx->r17) {
        // 0x80187874: sw          $t5, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r13;
            goto L_8018780C;
    }
    // 0x80187874: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x80187878: bne         $s2, $s5, L_801877A0
    if (ctx->r18 != ctx->r21) {
        // 0x8018787C: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_801877A0;
    }
    // 0x8018787C: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80187880: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80187884: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80187888: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8018788C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80187890: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80187894: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80187898: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8018789C: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x801878A0: jr          $ra
    // 0x801878A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801878A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void SectorY_8019A898(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A898: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019A89C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019A8A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019A8A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019A8A8: jal         0x8019B6E8
    // 0x8019A8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B6E8(rdram, ctx);
        goto after_0;
    // 0x8019A8AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8019A8B0: lh          $t6, 0x52($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X52);
    // 0x8019A8B4: bnel        $t6, $zero, L_8019A8C8
    if (ctx->r14 != 0) {
        // 0x8019A8B8: lwc1        $f4, 0x120($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
            goto L_8019A8C8;
    }
    goto skip_0;
    // 0x8019A8B8: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
    skip_0:
    // 0x8019A8BC: jal         0x8019BC14
    // 0x8019A8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019BC14(rdram, ctx);
        goto after_1;
    // 0x8019A8C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019A8C4: lwc1        $f4, 0x120($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X120);
L_8019A8C8:
    // 0x8019A8C8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019A8CC: lwc1        $f8, 0x128($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X128);
    // 0x8019A8D0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019A8D4: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019A8D8: jal         0x80005100
    // 0x8019A8DC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x8019A8DC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x8019A8E0: jal         0x8009F768
    // 0x8019A8E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x8019A8E4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x8019A8E8: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019A8EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019A8F0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019A8F4: sub.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x8019A8F8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019A8FC: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8019A900: nop

    // 0x8019A904: bc1fl       L_8019A91C
    if (!c1cs) {
        // 0x8019A908: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_8019A91C;
    }
    goto skip_1;
    // 0x8019A908: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    skip_1:
    // 0x8019A90C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019A910: nop

    // 0x8019A914: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8019A918: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_8019A91C:
    // 0x8019A91C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019A920: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8019A924: sh          $t7, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r15;
    // 0x8019A928: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x8019A92C: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8019A930: bc1fl       L_8019A954
    if (!c1cs) {
        // 0x8019A934: lh          $v0, 0x4C($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X4C);
            goto L_8019A954;
    }
    goto skip_2;
    // 0x8019A934: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
    skip_2:
    // 0x8019A938: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019A93C: nop

    // 0x8019A940: c.le.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl <= ctx->f8.fl;
    // 0x8019A944: nop

    // 0x8019A948: bc1t        L_8019A964
    if (c1cs) {
        // 0x8019A94C: nop
    
            goto L_8019A964;
    }
    // 0x8019A94C: nop

    // 0x8019A950: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
L_8019A954:
    // 0x8019A954: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8019A958: beql        $v0, $zero, L_8019A9E0
    if (ctx->r2 == 0) {
        // 0x8019A95C: sh          $zero, 0x56($s0)
        MEM_H(0X56, ctx->r16) = 0;
            goto L_8019A9E0;
    }
    goto skip_3;
    // 0x8019A95C: sh          $zero, 0x56($s0)
    MEM_H(0X56, ctx->r16) = 0;
    skip_3:
    // 0x8019A960: beq         $v0, $at, L_8019A9DC
    if (ctx->r2 == ctx->r1) {
        // 0x8019A964: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_8019A9DC;
    }
L_8019A964:
    // 0x8019A964: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A968: lwc1        $f0, 0x75B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X75B4);
    // 0x8019A96C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8019A970: sh          $t8, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r24;
    // 0x8019A974: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019A978: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019A97C: addiu       $a0, $s0, 0x7C
    ctx->r4 = ADD32(ctx->r16, 0X7C);
    // 0x8019A980: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019A984: jal         0x8009BD38
    // 0x8019A988: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_4;
    // 0x8019A988: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8019A98C: lh          $v0, 0x4C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4C);
    // 0x8019A990: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019A994: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019A998: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x8019A99C: beq         $v0, $zero, L_8019A9A8
    if (ctx->r2 == 0) {
        // 0x8019A9A0: swc1        $f10, 0xD8($s0)
        MEM_W(0XD8, ctx->r16) = ctx->f10.u32l;
            goto L_8019A9A8;
    }
    // 0x8019A9A0: swc1        $f10, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f10.u32l;
    // 0x8019A9A4: bne         $v0, $at, L_8019A9E0
    if (ctx->r2 != ctx->r1) {
        // 0x8019A9A8: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019A9E0;
    }
L_8019A9A8:
    // 0x8019A9A8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A9AC: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8019A9B0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A9B4: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8019A9B8: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x8019A9BC: ori         $a0, $a0, 0x2019
    ctx->r4 = ctx->r4 | 0X2019;
    // 0x8019A9C0: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8019A9C4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019A9C8: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019A9CC: jal         0x80019218
    // 0x8019A9D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x8019A9D0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x8019A9D4: b           L_8019A9E4
    // 0x8019A9D8: lh          $t0, 0x50($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X50);
        goto L_8019A9E4;
    // 0x8019A9D8: lh          $t0, 0x50($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X50);
L_8019A9DC:
    // 0x8019A9DC: sh          $zero, 0x56($s0)
    MEM_H(0X56, ctx->r16) = 0;
L_8019A9E0:
    // 0x8019A9E0: lh          $t0, 0x50($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X50);
L_8019A9E4:
    // 0x8019A9E4: bnel        $t0, $zero, L_8019A9F8
    if (ctx->r8 != 0) {
        // 0x8019A9E8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019A9F8;
    }
    goto skip_4;
    // 0x8019A9E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8019A9EC: jal         0x8019A434
    // 0x8019A9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019A434(rdram, ctx);
        goto after_6;
    // 0x8019A9F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8019A9F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019A9F8:
    // 0x8019A9F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019A9FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019AA00: jr          $ra
    // 0x8019AA04: nop

    return;
    // 0x8019AA04: nop

;}
RECOMP_FUNC void Andross_Effect357_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801899E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801899E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801899EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801899F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801899F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x801899F8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801899FC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80189A00: jal         0x80061474
    // 0x80189A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80189A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80189A08: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80189A0C: addiu       $t7, $zero, 0x165
    ctx->r15 = ADD32(0, 0X165);
    // 0x80189A10: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80189A14: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80189A18: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80189A1C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80189A20: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80189A24: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80189A28: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80189A2C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80189A30: lbu         $t8, 0x37($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X37);
    // 0x80189A34: jal         0x80004EB0
    // 0x80189A38: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80189A38: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    after_1:
    // 0x80189A3C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189A40: lwc1        $f10, 0x6C10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6C10);
    // 0x80189A44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80189A48: lwc1        $f18, 0x6C14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6C14);
    // 0x80189A4C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80189A50: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80189A54: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80189A58: sh          $t9, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r25;
    // 0x80189A5C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80189A60: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80189A64: jal         0x80004EB0
    // 0x80189A68: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80189A68: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    after_2:
    // 0x80189A6C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80189A70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189A74: nop

    // 0x80189A78: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80189A7C: jal         0x80004EB0
    // 0x80189A80: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80189A80: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x80189A84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189A88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189A8C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80189A90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189A94: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80189A98: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80189A9C: jal         0x80004EB0
    // 0x80189AA0: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80189AA0: swc1        $f8, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x80189AA4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189AA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189AAC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80189AB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80189AB4: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80189AB8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80189ABC: jal         0x80004EB0
    // 0x80189AC0: swc1        $f4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x80189AC0: swc1        $f4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f4.u32l;
    after_5:
    // 0x80189AC4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80189AC8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189ACC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80189AD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189AD4: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80189AD8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80189ADC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80189AE0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80189AE4: jal         0x800612B8
    // 0x80189AE8: swc1        $f16, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x80189AE8: swc1        $f16, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
    after_6:
    // 0x80189AEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80189AF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80189AF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80189AF8: jr          $ra
    // 0x80189AFC: nop

    return;
    // 0x80189AFC: nop

;}
RECOMP_FUNC void SectorY_80198CE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198CE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80198CE8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80198CEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80198CF0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80198CF4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80198CF8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80198CFC: jal         0x8019B6E8
    // 0x80198D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B6E8(rdram, ctx);
        goto after_0;
    // 0x80198D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80198D04: lh          $t6, 0x52($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X52);
    // 0x80198D08: bne         $t6, $zero, L_80198D18
    if (ctx->r14 != 0) {
        // 0x80198D0C: nop
    
            goto L_80198D18;
    }
    // 0x80198D0C: nop

    // 0x80198D10: jal         0x8019BC14
    // 0x80198D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019BC14(rdram, ctx);
        goto after_1;
    // 0x80198D14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_80198D18:
    // 0x80198D18: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198D1C: lwc1        $f20, 0x7524($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7524);
    // 0x80198D20: lw          $a1, 0x144($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X144);
    // 0x80198D24: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x80198D28: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198D2C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80198D30: jal         0x8009BD38
    // 0x80198D34: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_2;
    // 0x80198D34: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x80198D38: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198D3C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x80198D40: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80198D44: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80198D48: jal         0x8009BD38
    // 0x80198D4C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_3;
    // 0x80198D4C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x80198D50: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80198D54: lwc1        $f22, 0xC($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80198D58: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    // 0x80198D5C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198D60: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x80198D64: jal         0x80005100
    // 0x80198D68: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    Math_Atan2F(rdram, ctx);
        goto after_4;
    // 0x80198D68: sub.s       $f14, $f18, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f22.fl;
    after_4:
    // 0x80198D6C: jal         0x8009F768
    // 0x80198D70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_5;
    // 0x80198D70: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_5:
    // 0x80198D74: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x80198D78: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80198D7C: addiu       $a0, $s0, 0x7C
    ctx->r4 = ADD32(ctx->r16, 0X7C);
    // 0x80198D80: beq         $t7, $zero, L_80198DA8
    if (ctx->r15 == 0) {
        // 0x80198D84: lui         $a3, 0x4000
        ctx->r7 = S32(0X4000 << 16);
            goto L_80198DA8;
    }
    // 0x80198D84: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80198D88: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80198D8C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198D90: addiu       $a0, $s0, 0x7C
    ctx->r4 = ADD32(ctx->r16, 0X7C);
    // 0x80198D94: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80198D98: jal         0x8009BD38
    // 0x80198D9C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x80198D9C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80198DA0: b           L_80198DBC
    // 0x80198DA4: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
        goto L_80198DBC;
    // 0x80198DA4: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
L_80198DA8:
    // 0x80198DA8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80198DAC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198DB0: jal         0x8009BD38
    // 0x80198DB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_7;
    // 0x80198DB4: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x80198DB8: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
L_80198DBC:
    // 0x80198DBC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198DC0: bnel        $t8, $zero, L_80198E30
    if (ctx->r24 != 0) {
        // 0x80198DC4: lwc1        $f8, 0x7C($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_80198E30;
    }
    goto skip_0;
    // 0x80198DC4: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    skip_0:
    // 0x80198DC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198DCC: lwc1        $f10, 0x7528($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7528);
    // 0x80198DD0: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80198DD4: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80198DD8: jal         0x80023090
    // 0x80198DDC: nop

    __sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x80198DDC: nop

    after_8:
    // 0x80198DE0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80198DE4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198DE8: lwc1        $f16, 0x18C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80198DEC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198DF0: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80198DF4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80198DF8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80198DFC: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x80198E00: lwc1        $f10, 0x752C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X752C);
    // 0x80198E04: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80198E08: jal         0x80023250
    // 0x80198E0C: nop

    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x80198E0C: nop

    after_9:
    // 0x80198E10: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80198E14: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198E18: lwc1        $f16, 0x18C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80198E1C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80198E20: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80198E24: b           L_80198E70
    // 0x80198E28: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
        goto L_80198E70;
    // 0x80198E28: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    // 0x80198E2C: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
L_80198E30:
    // 0x80198E30: lwc1        $f10, 0x7530($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7530);
    // 0x80198E34: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80198E38: jal         0x80023090
    // 0x80198E3C: nop

    __sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x80198E3C: nop

    after_10:
    // 0x80198E40: lwc1        $f16, 0x18C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80198E44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198E48: lwc1        $f4, 0x7C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80198E4C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80198E50: swc1        $f18, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f18.u32l;
    // 0x80198E54: lwc1        $f6, 0x7534($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7534);
    // 0x80198E58: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80198E5C: jal         0x80023250
    // 0x80198E60: nop

    __cosf_recomp(rdram, ctx);
        goto after_11;
    // 0x80198E60: nop

    after_11:
    // 0x80198E64: lwc1        $f8, 0x18C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80198E68: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80198E6C: swc1        $f10, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f10.u32l;
L_80198E70:
    // 0x80198E70: jal         0x8019B5CC
    // 0x80198E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B5CC(rdram, ctx);
        goto after_12;
    // 0x80198E74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80198E78: beq         $v0, $zero, L_80198EA0
    if (ctx->r2 == 0) {
        // 0x80198E7C: addiu       $a0, $s0, 0x8
        ctx->r4 = ADD32(ctx->r16, 0X8);
            goto L_80198EA0;
    }
    // 0x80198E7C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80198E80: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198E84: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80198E88: lui         $a1, 0x447A
    ctx->r5 = S32(0X447A << 16);
    // 0x80198E8C: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x80198E90: jal         0x8009BC2C
    // 0x80198E94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x80198E94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_13:
    // 0x80198E98: b           L_80198EB8
    // 0x80198E9C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
        goto L_80198EB8;
    // 0x80198E9C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_80198EA0:
    // 0x80198EA0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198EA4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80198EA8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80198EAC: jal         0x8009BC2C
    // 0x80198EB0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x80198EB0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_14:
    // 0x80198EB4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
L_80198EB8:
    // 0x80198EB8: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80198EBC: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80198EC0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80198EC4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80198EC8: jal         0x8009BC2C
    // 0x80198ECC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80198ECC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_15:
    // 0x80198ED0: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80198ED4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80198ED8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80198EDC: sub.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f16.fl;
    // 0x80198EE0: c.lt.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl < ctx->f18.fl;
    // 0x80198EE4: nop

    // 0x80198EE8: bc1f        L_80198EFC
    if (!c1cs) {
        // 0x80198EEC: nop
    
            goto L_80198EFC;
    }
    // 0x80198EEC: nop

    // 0x80198EF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198EF4: nop

    // 0x80198EF8: add.s       $f22, $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f4.fl;
L_80198EFC:
    // 0x80198EFC: jal         0x8019B528
    // 0x80198F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B528(rdram, ctx);
        goto after_16;
    // 0x80198F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80198F04: bne         $v0, $zero, L_80198F44
    if (ctx->r2 != 0) {
        // 0x80198F08: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80198F44;
    }
    // 0x80198F08: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80198F0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80198F10: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80198F14: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x80198F18: nop

    // 0x80198F1C: bc1t        L_80198F3C
    if (c1cs) {
        // 0x80198F20: nop
    
            goto L_80198F3C;
    }
    // 0x80198F20: nop

    // 0x80198F24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80198F28: nop

    // 0x80198F2C: c.le.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl <= ctx->f22.fl;
    // 0x80198F30: nop

    // 0x80198F34: bc1fl       L_80198F48
    if (!c1cs) {
        // 0x80198F38: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_80198F48;
    }
    goto skip_1;
    // 0x80198F38: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
L_80198F3C:
    // 0x80198F3C: jal         0x80198244
    // 0x80198F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80198244(rdram, ctx);
        goto after_17;
    // 0x80198F40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
L_80198F44:
    // 0x80198F44: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80198F48:
    // 0x80198F48: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80198F4C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80198F50: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80198F54: jr          $ra
    // 0x80198F58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80198F58: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Andross_AndDoor_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801934EC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801934F0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801934F4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801934F8: bne         $a0, $at, L_80193504
    if (ctx->r4 != ctx->r1) {
        // 0x801934FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80193504;
    }
    // 0x801934FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80193500: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80193504:
    // 0x80193504: jr          $ra
    // 0x80193508: nop

    return;
    // 0x80193508: nop

;}
RECOMP_FUNC void Andross_AndSuctionSmoke_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CA50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018CA54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018CA58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8018CA5C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8018CA60: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8018CA64: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8018CA68: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8018CA6C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8018CA70: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8018CA74:
    // 0x8018CA74: bnel        $t6, $zero, L_8018CAB8
    if (ctx->r14 != 0) {
        // 0x8018CA78: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8018CAB8;
    }
    goto skip_0;
    // 0x8018CA78: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8018CA7C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018CA80: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018CA84: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8018CA88: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018CA8C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8018CA90: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8018CA94: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8018CA98: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8018CA9C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018CAA0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018CAA4: jal         0x8018C958
    // 0x8018CAA8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    Andross_AndSuctionSmoke_Setup(rdram, ctx);
        goto after_0;
    // 0x8018CAA8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8018CAAC: b           L_8018CAC8
    // 0x8018CAB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018CAC8;
    // 0x8018CAB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018CAB4: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8018CAB8:
    // 0x8018CAB8: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8018CABC: beql        $at, $zero, L_8018CA74
    if (ctx->r1 == 0) {
        // 0x8018CAC0: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8018CA74;
    }
    goto skip_1;
    // 0x8018CAC0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8018CAC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018CAC8:
    // 0x8018CAC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018CACC: jr          $ra
    // 0x8018CAD0: nop

    return;
    // 0x8018CAD0: nop

;}
RECOMP_FUNC void SectorY_ActorDebris_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A39FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A3A00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801A3A04: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801A3A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A3A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801A3A10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801A3A14: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801A3A18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801A3A1C: jal         0x800613C4
    // 0x801A3A20: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801A3A20: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801A3A24: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A3A28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A3A2C: addiu       $t7, $zero, 0xBD
    ctx->r15 = ADD32(0, 0XBD);
    // 0x801A3A30: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801A3A34: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801A3A38: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x801A3A3C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x801A3A40: sh          $t8, 0xB8($a2)
    MEM_H(0XB8, ctx->r6) = ctx->r24;
    // 0x801A3A44: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801A3A48: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801A3A4C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801A3A50: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A3A54: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801A3A58: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801A3A5C: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x801A3A60: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A3A64: swc1        $f10, 0xE8($a2)
    MEM_W(0XE8, ctx->r6) = ctx->f10.u32l;
    // 0x801A3A68: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A3A6C: swc1        $f16, 0xEC($a2)
    MEM_W(0XEC, ctx->r6) = ctx->f16.u32l;
    // 0x801A3A70: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A3A74: swc1        $f4, 0x110($a2)
    MEM_W(0X110, ctx->r6) = ctx->f4.u32l;
    // 0x801A3A78: jal         0x80004EB0
    // 0x801A3A7C: swc1        $f18, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801A3A7C: swc1        $f18, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f18.u32l;
    after_1:
    // 0x801A3A80: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801A3A84: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801A3A88: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A3A8C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801A3A90: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x801A3A94: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A3A98: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801A3A9C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801A3AA0: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x801A3AA4: nop

    // 0x801A3AA8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x801A3AAC: nop

    // 0x801A3AB0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801A3AB4: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x801A3AB8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801A3ABC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801A3AC0: nop

    // 0x801A3AC4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801A3AC8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801A3ACC: nop

    // 0x801A3AD0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801A3AD4: beql        $t2, $zero, L_801A3B24
    if (ctx->r10 == 0) {
        // 0x801A3AD8: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_801A3B24;
    }
    goto skip_0;
    // 0x801A3AD8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x801A3ADC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A3AE0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801A3AE4: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A3AE8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801A3AEC: nop

    // 0x801A3AF0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x801A3AF4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801A3AF8: nop

    // 0x801A3AFC: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x801A3B00: bne         $t2, $zero, L_801A3B18
    if (ctx->r10 != 0) {
        // 0x801A3B04: nop
    
            goto L_801A3B18;
    }
    // 0x801A3B04: nop

    // 0x801A3B08: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x801A3B0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A3B10: b           L_801A3B30
    // 0x801A3B14: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_801A3B30;
    // 0x801A3B14: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_801A3B18:
    // 0x801A3B18: b           L_801A3B30
    // 0x801A3B1C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_801A3B30;
    // 0x801A3B1C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801A3B20: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_801A3B24:
    // 0x801A3B24: nop

    // 0x801A3B28: bltz        $t2, L_801A3B18
    if (SIGNED(ctx->r10) < 0) {
        // 0x801A3B2C: nop
    
            goto L_801A3B18;
    }
    // 0x801A3B2C: nop

L_801A3B30:
    // 0x801A3B30: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801A3B34: sh          $t2, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r10;
    // 0x801A3B38: jal         0x800612B8
    // 0x801A3B3C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x801A3B3C: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_2:
    // 0x801A3B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A3B44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A3B48: jr          $ra
    // 0x801A3B4C: nop

    return;
    // 0x801A3B4C: nop

;}
RECOMP_FUNC void Andross_EvAndrossGate_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187530: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80187534: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80187538: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8018753C: lh          $v0, 0x48($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X48);
    // 0x80187540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80187544: beq         $v0, $zero, L_80187564
    if (ctx->r2 == 0) {
        // 0x80187548: nop
    
            goto L_80187564;
    }
    // 0x80187548: nop

    // 0x8018754C: beq         $v0, $at, L_8018756C
    if (ctx->r2 == ctx->r1) {
        // 0x80187550: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8018756C;
    }
    // 0x80187550: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80187554: beql        $v0, $at, L_801875D4
    if (ctx->r2 == ctx->r1) {
        // 0x80187558: lwc1        $f8, 0x16C($a1)
        ctx->f8.u32l = MEM_W(ctx->r5, 0X16C);
            goto L_801875D4;
    }
    goto skip_0;
    // 0x80187558: lwc1        $f8, 0x16C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X16C);
    skip_0:
    // 0x8018755C: b           L_80187600
    // 0x80187560: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
        goto L_80187600;
    // 0x80187560: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
L_80187564:
    // 0x80187564: b           L_80187600
    // 0x80187568: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
        goto L_80187600;
    // 0x80187568: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
L_8018756C:
    // 0x8018756C: lwc1        $f4, 0x16C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X16C);
    // 0x80187570: lh          $t6, 0xB6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XB6);
    // 0x80187574: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80187578: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018757C: addiu       $a0, $a0, 0x4658
    ctx->r4 = ADD32(ctx->r4, 0X4658);
    // 0x80187580: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80187584: nop

    // 0x80187588: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018758C: sh          $t9, 0xB6($a1)
    MEM_H(0XB6, ctx->r5) = ctx->r25;
    // 0x80187590: jal         0x8009ACDC
    // 0x80187594: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Animation_GetFrameCount(rdram, ctx);
        goto after_0;
    // 0x80187594: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80187598: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8018759C: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x801875A0: addiu       $a0, $a0, 0x4658
    ctx->r4 = ADD32(ctx->r4, 0X4658);
    // 0x801875A4: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
    // 0x801875A8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801875AC: bnel        $at, $zero, L_80187604
    if (ctx->r1 != 0) {
        // 0x801875B0: mtc1        $v1, $f16
        ctx->f16.u32l = ctx->r3;
            goto L_80187604;
    }
    goto skip_1;
    // 0x801875B0: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    skip_1:
    // 0x801875B4: jal         0x8009ACDC
    // 0x801875B8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Animation_GetFrameCount(rdram, ctx);
        goto after_1;
    // 0x801875B8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x801875BC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801875C0: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x801875C4: sh          $t0, 0xB6($a1)
    MEM_H(0XB6, ctx->r5) = ctx->r8;
    // 0x801875C8: b           L_80187600
    // 0x801875CC: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
        goto L_80187600;
    // 0x801875CC: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
    // 0x801875D0: lwc1        $f8, 0x16C($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X16C);
L_801875D4:
    // 0x801875D4: lh          $t1, 0xB6($a1)
    ctx->r9 = MEM_H(ctx->r5, 0XB6);
    // 0x801875D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801875DC: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x801875E0: nop

    // 0x801875E4: subu        $t4, $t1, $t3
    ctx->r12 = SUB32(ctx->r9, ctx->r11);
    // 0x801875E8: sh          $t4, 0xB6($a1)
    MEM_H(0XB6, ctx->r5) = ctx->r12;
    // 0x801875EC: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
    // 0x801875F0: bgtzl       $v1, L_80187604
    if (SIGNED(ctx->r3) > 0) {
        // 0x801875F4: mtc1        $v1, $f16
        ctx->f16.u32l = ctx->r3;
            goto L_80187604;
    }
    goto skip_2;
    // 0x801875F4: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    skip_2:
    // 0x801875F8: sh          $zero, 0xB6($a1)
    MEM_H(0XB6, ctx->r5) = 0;
    // 0x801875FC: lh          $v1, 0xB6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XB6);
L_80187600:
    // 0x80187600: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
L_80187604:
    // 0x80187604: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80187608: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018760C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80187610: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x80187614: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80187618: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8018761C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80187620: div.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80187624: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80187628: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8018762C: nop

    // 0x80187630: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80187634: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80187638: lw          $v0, 0x6760($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6760);
    // 0x8018763C: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80187640: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x80187644: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80187648: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8018764C: lw          $t2, 0x1FD0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1FD0);
    // 0x80187650: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80187654: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80187658: addu        $t1, $t6, $t2
    ctx->r9 = ADD32(ctx->r14, ctx->r10);
    // 0x8018765C: addu        $t3, $t1, $at
    ctx->r11 = ADD32(ctx->r9, ctx->r1);
    // 0x80187660: sw          $t3, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r11;
    // 0x80187664: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80187668: lwc1        $f10, 0x7F68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7F68);
    // 0x8018766C: swc1        $f10, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f10.u32l;
    // 0x80187670: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80187674: jr          $ra
    // 0x80187678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80187678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Andross_AbsorbArwing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C390: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018C394: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018C398: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018C39C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018C3A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8018C3A4: lw          $v0, 0x1D0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1D0);
    // 0x8018C3A8: sw          $v1, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r3;
    // 0x8018C3AC: sw          $zero, 0x280($s0)
    MEM_W(0X280, ctx->r16) = 0;
    // 0x8018C3B0: beq         $v0, $zero, L_8018C3DC
    if (ctx->r2 == 0) {
        // 0x8018C3B4: addiu       $a0, $s0, 0x74
        ctx->r4 = ADD32(ctx->r16, 0X74);
            goto L_8018C3DC;
    }
    // 0x8018C3B4: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x8018C3B8: beq         $v0, $v1, L_8018C53C
    if (ctx->r2 == ctx->r3) {
        // 0x8018C3BC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8018C53C;
    }
    // 0x8018C3BC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018C3C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018C3C4: beq         $v0, $at, L_8018C634
    if (ctx->r2 == ctx->r1) {
        // 0x8018C3C8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8018C634;
    }
    // 0x8018C3C8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018C3CC: beql        $v0, $at, L_8018C638
    if (ctx->r2 == ctx->r1) {
        // 0x8018C3D0: lwc1        $f8, 0x7C($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_8018C638;
    }
    goto skip_0;
    // 0x8018C3D0: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    skip_0:
    // 0x8018C3D4: b           L_8018C638
    // 0x8018C3D8: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
        goto L_8018C638;
    // 0x8018C3D8: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
L_8018C3DC:
    // 0x8018C3DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018C3E0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8018C3E4: lw          $a1, -0xEEC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XEEC);
    // 0x8018C3E8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8018C3EC: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8018C3F0: jal         0x8009BC2C
    // 0x8018C3F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8018C3F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8018C3F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018C3FC: lwc1        $f6, -0xEE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEE8);
    // 0x8018C400: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018C404: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018C408: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018C40C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8018C410: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018C414: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8018C418: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8018C41C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8018C420: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8018C424: jal         0x8009BC2C
    // 0x8018C428: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8018C428: nop

    after_1:
    // 0x8018C42C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018C430: lwc1        $f18, -0xEE4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x8018C434: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018C438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C43C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018C440: addiu       $a0, $s0, 0x7C
    ctx->r4 = ADD32(ctx->r16, 0X7C);
    // 0x8018C444: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018C448: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8018C44C: lui         $a3, 0x4270
    ctx->r7 = S32(0X4270 << 16);
    // 0x8018C450: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8018C454: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018C458: jal         0x8009BC2C
    // 0x8018C45C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8018C45C: nop

    after_2:
    // 0x8018C460: lwc1        $f0, 0x7C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8018C464: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8018C468: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018C46C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8018C470: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018C474: swc1        $f0, 0x144($s0)
    MEM_W(0X144, ctx->r16) = ctx->f0.u32l;
    // 0x8018C478: swc1        $f0, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f0.u32l;
    // 0x8018C47C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C480: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8018C484: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x8018C488: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x8018C48C: jal         0x8009BC2C
    // 0x8018C490: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8018C490: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8018C494: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8018C498: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018C49C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C4A0: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x8018C4A4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018C4A8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018C4AC: jal         0x8009BC2C
    // 0x8018C4B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8018C4B0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8018C4B4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8018C4B8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018C4BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C4C0: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x8018C4C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018C4C8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018C4CC: jal         0x8009BC2C
    // 0x8018C4D0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8018C4D0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8018C4D4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018C4D8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018C4DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C4E0: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8018C4E4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018C4E8: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018C4EC: jal         0x8009BC2C
    // 0x8018C4F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8018C4F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8018C4F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018C4F8: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018C4FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C500: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8018C504: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8018C508: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018C50C: jal         0x8009BC2C
    // 0x8018C510: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8018C510: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8018C514: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018C518: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018C51C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C520: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8018C524: lui         $a1, 0x42C8
    ctx->r5 = S32(0X42C8 << 16);
    // 0x8018C528: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018C52C: jal         0x8009BC2C
    // 0x8018C530: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x8018C530: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_8:
    // 0x8018C534: b           L_8018C638
    // 0x8018C538: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
        goto L_8018C638;
    // 0x8018C538: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
L_8018C53C:
    // 0x8018C53C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018C540: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018C544: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018C548: lwc1        $f10, 0xE4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8018C54C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018C550: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018C554: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018C558: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018C55C: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8018C560: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x8018C564: swc1        $f18, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f18.u32l;
    // 0x8018C568: lwc1        $f0, 0xE4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8018C56C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8018C570: nop

    // 0x8018C574: bc1fl       L_8018C590
    if (!c1cs) {
        // 0x8018C578: lui         $at, 0x4110
        ctx->r1 = S32(0X4110 << 16);
            goto L_8018C590;
    }
    goto skip_1;
    // 0x8018C578: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    skip_1:
    // 0x8018C57C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018C580: nop

    // 0x8018C584: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8018C588: swc1        $f6, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f6.u32l;
    // 0x8018C58C: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
L_8018C590:
    // 0x8018C590: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018C594: lwc1        $f8, 0xE8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8018C598: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8018C59C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8018C5A0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018C5A4: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x8018C5A8: lwc1        $f0, 0xE8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8018C5AC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8018C5B0: nop

    // 0x8018C5B4: bc1fl       L_8018C5D0
    if (!c1cs) {
        // 0x8018C5B8: lui         $a3, 0x41A0
        ctx->r7 = S32(0X41A0 << 16);
            goto L_8018C5D0;
    }
    goto skip_2;
    // 0x8018C5B8: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    skip_2:
    // 0x8018C5BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C5C0: nop

    // 0x8018C5C4: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8018C5C8: swc1        $f4, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f4.u32l;
    // 0x8018C5CC: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
L_8018C5D0:
    // 0x8018C5D0: jal         0x8009BC2C
    // 0x8018C5D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8018C5D4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x8018C5D8: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x8018C5DC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018C5E0: beq         $v0, $zero, L_8018C618
    if (ctx->r2 == 0) {
        // 0x8018C5E4: nop
    
            goto L_8018C618;
    }
    // 0x8018C5E4: nop

    // 0x8018C5E8: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x8018C5EC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8018C5F0: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8018C5F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018C5F8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8018C5FC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8018C600: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018C604: lhu         $t8, -0x2768($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2768);
    // 0x8018C608: beq         $t8, $zero, L_8018C618
    if (ctx->r24 == 0) {
        // 0x8018C60C: nop
    
            goto L_8018C618;
    }
    // 0x8018C60C: nop

    // 0x8018C610: sw          $t9, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r25;
    // 0x8018C614: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8018C618:
    // 0x8018C618: bnel        $v0, $zero, L_8018C638
    if (ctx->r2 != 0) {
        // 0x8018C61C: lwc1        $f8, 0x7C($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_8018C638;
    }
    goto skip_3;
    // 0x8018C61C: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    skip_3:
    // 0x8018C620: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018C624: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8018C628: sw          $t0, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r8;
    // 0x8018C62C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8018C630: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
L_8018C634:
    // 0x8018C634: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
L_8018C638:
    // 0x8018C638: lwc1        $f10, 0x8C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x8018C63C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018C640: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018C644: jal         0x800A46A0
    // 0x8018C648: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    Player_DamageEffects(rdram, ctx);
        goto after_10;
    // 0x8018C648: swc1        $f16, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f16.u32l;
    after_10:
    // 0x8018C64C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018C650: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018C654: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018C658: jr          $ra
    // 0x8018C65C: nop

    return;
    // 0x8018C65C: nop

;}
RECOMP_FUNC void SectorY_80197B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197B30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80197B34: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80197B38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80197B3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80197B40: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80197B44: jal         0x800613C4
    // 0x80197B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80197B48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80197B4C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80197B50: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80197B54: addiu       $t7, $zero, 0xC3
    ctx->r15 = ADD32(0, 0XC3);
    // 0x80197B58: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80197B5C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80197B60: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80197B64: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80197B68: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80197B6C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80197B70: lwc1        $f4, 0x74($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X74);
    // 0x80197B74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80197B78: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80197B7C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80197B80: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80197B84: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80197B88: lwc1        $f6, 0x78($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X78);
    // 0x80197B8C: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80197B90: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80197B94: lwc1        $f8, 0x7C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X7C);
    // 0x80197B98: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80197B9C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80197BA0: lwc1        $f10, 0xD0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XD0);
    // 0x80197BA4: swc1        $f10, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f10.u32l;
    // 0x80197BA8: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80197BAC: lwc1        $f16, 0xC0($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0XC0);
    // 0x80197BB0: swc1        $f16, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f16.u32l;
    // 0x80197BB4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80197BB8: lwc1        $f18, 0xC4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XC4);
    // 0x80197BBC: swc1        $f18, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f18.u32l;
    // 0x80197BC0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80197BC4: lwc1        $f4, 0xC8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC8);
    // 0x80197BC8: swc1        $f4, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f4.u32l;
    // 0x80197BCC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80197BD0: lwc1        $f6, 0x120($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X120);
    // 0x80197BD4: lwc1        $f8, 0xE4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XE4);
    // 0x80197BD8: lwc1        $f16, 0x4D8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4D8);
    // 0x80197BDC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80197BE0: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80197BE4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80197BE8: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x80197BEC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80197BF0: lwc1        $f4, 0xE8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XE8);
    // 0x80197BF4: lwc1        $f6, 0x114($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X114);
    // 0x80197BF8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80197BFC: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80197C00: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80197C04: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80197C08: lwc1        $f18, 0xEC($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0XEC);
    // 0x80197C0C: sh          $t6, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r14;
    // 0x80197C10: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x80197C14: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80197C18: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80197C1C: jal         0x800612B8
    // 0x80197C20: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80197C20: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    after_1:
    // 0x80197C24: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80197C28: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x80197C2C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80197C30: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x80197C34: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80197C38: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80197C3C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80197C40: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80197C44: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80197C48: jal         0x80019218
    // 0x80197C4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80197C4C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x80197C50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80197C54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80197C58: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80197C5C: jr          $ra
    // 0x80197C60: nop

    return;
    // 0x80197C60: nop

;}
RECOMP_FUNC void Venom2_Ve2Base_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196288: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019628C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80196290: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80196294: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80196298: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x8019629C: addiu       $a0, $a0, 0x4904
    ctx->r4 = ADD32(ctx->r4, 0X4904);
    // 0x801962A0: addiu       $a2, $a2, 0x1A0
    ctx->r6 = ADD32(ctx->r6, 0X1A0);
    // 0x801962A4: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x801962A8: jal         0x8009AA20
    // 0x801962AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Animation_GetFrameData(rdram, ctx);
        goto after_0;
    // 0x801962AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x801962B0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801962B4: lw          $t7, -0x4438($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4438);
    // 0x801962B8: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801962BC: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801962C0: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x801962C4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801962C8: addiu       $a3, $a3, 0x624C
    ctx->r7 = ADD32(ctx->r7, 0X624C);
    // 0x801962CC: addiu       $a1, $a1, 0x49D0
    ctx->r5 = ADD32(ctx->r5, 0X49D0);
    // 0x801962D0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801962D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801962D8: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x801962DC: jal         0x8009A72C
    // 0x801962E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    Animation_DrawSkeleton(rdram, ctx);
        goto after_1;
    // 0x801962E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_1:
    // 0x801962E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801962E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801962EC: jr          $ra
    // 0x801962F0: nop

    return;
    // 0x801962F0: nop

;}
RECOMP_FUNC void SectorY_8019A434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A434: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019A438: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019A43C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019A440: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019A444: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8019A448: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8019A44C: sh          $t6, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r14;
    // 0x8019A450: jal         0x80004EB0
    // 0x8019A454: sh          $t7, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r15;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8019A454: sh          $t7, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r15;
    after_0:
    // 0x8019A458: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8019A45C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019A460: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019A464: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019A468: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019A46C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A470: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019A474: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019A478: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019A47C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8019A480: nop

    // 0x8019A484: sh          $t9, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r25;
    // 0x8019A488: lwc1        $f4, 0x759C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X759C);
    // 0x8019A48C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019A490: jal         0x80023090
    // 0x8019A494: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8019A494: nop

    after_1:
    // 0x8019A498: lwc1        $f6, 0x18C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x8019A49C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A4A0: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019A4A4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8019A4A8: swc1        $f8, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f8.u32l;
    // 0x8019A4AC: lwc1        $f16, 0x75A0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X75A0);
    // 0x8019A4B0: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019A4B4: jal         0x80023250
    // 0x8019A4B8: nop

    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8019A4B8: nop

    after_2:
    // 0x8019A4BC: lwc1        $f18, 0x18C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x8019A4C0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019A4C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019A4C8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8019A4CC: lui         $at, 0x4335
    ctx->r1 = S32(0X4335 << 16);
    // 0x8019A4D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019A4D4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A4D8: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8019A4DC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A4E0: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019A4E4: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
    // 0x8019A4E8: lui         $a0, 0x1903
    ctx->r4 = S32(0X1903 << 16);
    // 0x8019A4EC: swc1        $f6, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f6.u32l;
    // 0x8019A4F0: swc1        $f8, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f8.u32l;
    // 0x8019A4F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8019A4F8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019A4FC: ori         $a0, $a0, 0x1003
    ctx->r4 = ctx->r4 | 0X1003;
    // 0x8019A500: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019A504: jal         0x80019218
    // 0x8019A508: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8019A508: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_3:
    // 0x8019A50C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019A510: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019A514: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019A518: jr          $ra
    // 0x8019A51C: nop

    return;
    // 0x8019A51C: nop

;}
RECOMP_FUNC void Andross_AndSuction_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018C660: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018C664: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018C668: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8018C66C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018C670: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8018C674: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8018C678: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8018C67C: jal         0x80061474
    // 0x8018C680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8018C680: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8018C684: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8018C688: addiu       $t7, $zero, 0x18C
    ctx->r15 = ADD32(0, 0X18C);
    // 0x8018C68C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8018C690: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8018C694: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8018C698: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8018C69C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8018C6A0: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018C6A4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8018C6A8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8018C6AC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8018C6B0: jal         0x80004EB0
    // 0x8018C6B4: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018C6B4: sb          $t8, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r24;
    after_1:
    // 0x8018C6B8: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8018C6BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018C6C0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8018C6C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C6C8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018C6CC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C6D0: jal         0x80004EB0
    // 0x8018C6D4: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018C6D4: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8018C6D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018C6DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018C6E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018C6E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018C6E8: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8018C6EC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018C6F0: jal         0x80004EB0
    // 0x8018C6F4: swc1        $f16, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018C6F4: swc1        $f16, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x8018C6F8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018C6FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018C700: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018C704: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018C708: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8018C70C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8018C710: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8018C714: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018C718: jal         0x800612B8
    // 0x8018C71C: swc1        $f8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_4;
    // 0x8018C71C: swc1        $f8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x8018C720: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018C724: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018C728: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018C72C: jr          $ra
    // 0x8018C730: nop

    return;
    // 0x8018C730: nop

;}
RECOMP_FUNC void Andross_AndBrainWaste_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018887C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80188880: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188884: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80188888: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8018888C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80188890: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80188894: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80188898: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8018889C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_801888A0:
    // 0x801888A0: bnel        $t6, $zero, L_801888DC
    if (ctx->r14 != 0) {
        // 0x801888A4: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_801888DC;
    }
    goto skip_0;
    // 0x801888A4: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_0:
    // 0x801888A8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801888AC: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801888B0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801888B4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801888B8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801888BC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801888C0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801888C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801888C8: jal         0x801887B0
    // 0x801888CC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Andross_AndBrainWaste_Setup(rdram, ctx);
        goto after_0;
    // 0x801888CC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801888D0: b           L_801888E8
    // 0x801888D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801888E8;
    // 0x801888D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801888D8: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_801888DC:
    // 0x801888DC: bnel        $a0, $v0, L_801888A0
    if (ctx->r4 != ctx->r2) {
        // 0x801888E0: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_801888A0;
    }
    goto skip_1;
    // 0x801888E0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x801888E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801888E8:
    // 0x801888E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801888EC: jr          $ra
    // 0x801888F0: nop

    return;
    // 0x801888F0: nop

;}
RECOMP_FUNC void Venom2_UpdateEvents(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196314: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80196318: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8019631C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80196320: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80196324: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80196328: lh          $v0, 0xB8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0XB8);
    // 0x8019632C: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80196330: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x80196334: beq         $v0, $zero, L_80196360
    if (ctx->r2 == 0) {
        // 0x80196338: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_80196360;
    }
    // 0x80196338: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019633C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80196340: beq         $v0, $a1, L_801964D4
    if (ctx->r2 == ctx->r5) {
        // 0x80196344: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_801964D4;
    }
    // 0x80196344: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80196348: beq         $v0, $t0, L_80196560
    if (ctx->r2 == ctx->r8) {
        // 0x8019634C: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80196560;
    }
    // 0x8019634C: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80196350: beq         $v0, $t1, L_80196734
    if (ctx->r2 == ctx->r9) {
        // 0x80196354: lui         $t7, 0x8016
        ctx->r15 = S32(0X8016 << 16);
            goto L_80196734;
    }
    // 0x80196354: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80196358: b           L_80196880
    // 0x8019635C: nop

        goto L_80196880;
    // 0x8019635C: nop

L_80196360:
    // 0x80196360: sw          $zero, -0x6D8($at)
    MEM_W(-0X6D8, ctx->r1) = 0;
    // 0x80196364: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80196368: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019636C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80196370: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80196374: sh          $zero, -0x6F8($at)
    MEM_H(-0X6F8, ctx->r1) = 0;
    // 0x80196378: addiu       $a0, $a0, 0x7CE8
    ctx->r4 = ADD32(ctx->r4, 0X7CE8);
    // 0x8019637C: addiu       $v0, $v0, 0x7CD0
    ctx->r2 = ADD32(ctx->r2, 0X7CD0);
    // 0x80196380: addiu       $v1, $v1, 0x7CF0
    ctx->r3 = ADD32(ctx->r3, 0X7CF0);
    // 0x80196384: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80196388:
    // 0x80196388: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8019638C: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80196390: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80196394: sw          $a1, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r5;
    // 0x80196398: bne         $at, $zero, L_80196388
    if (ctx->r1 != 0) {
        // 0x8019639C: sw          $a1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r5;
            goto L_80196388;
    }
    // 0x8019639C: sw          $a1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r5;
    // 0x801963A0: lw          $t6, 0x1C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C8);
    // 0x801963A4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801963A8: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x801963AC: bne         $t1, $t6, L_801963F8
    if (ctx->r9 != ctx->r14) {
        // 0x801963B0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_801963F8;
    }
    // 0x801963B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x801963B4: lui         $at, 0x45FA
    ctx->r1 = S32(0X45FA << 16);
    // 0x801963B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801963BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801963C0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801963C4: sh          $t0, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r8;
    // 0x801963C8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801963CC: swc1        $f4, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f4.u32l;
    // 0x801963D0: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
    // 0x801963D4: lwc1        $f8, 0x7440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7440);
    // 0x801963D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x801963DC: addiu       $t7, $zero, 0x78
    ctx->r15 = ADD32(0, 0X78);
    // 0x801963E0: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x801963E4: sw          $t7, -0x64B4($at)
    MEM_W(-0X64B4, ctx->r1) = ctx->r15;
    // 0x801963E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801963EC: addiu       $t8, $zero, 0x3E8
    ctx->r24 = ADD32(0, 0X3E8);
    // 0x801963F0: b           L_801964C8
    // 0x801963F4: sh          $t8, -0x6F8($at)
    MEM_H(-0X6F8, ctx->r1) = ctx->r24;
        goto L_801964C8;
    // 0x801963F4: sh          $t8, -0x6F8($at)
    MEM_H(-0X6F8, ctx->r1) = ctx->r24;
L_801963F8:
    // 0x801963F8: sw          $t9, -0x64B4($at)
    MEM_W(-0X64B4, ctx->r1) = ctx->r25;
    // 0x801963FC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80196400: addiu       $t5, $zero, 0x4B0
    ctx->r13 = ADD32(0, 0X4B0);
    // 0x80196404: sh          $t5, -0x6F8($at)
    MEM_H(-0X6F8, ctx->r1) = ctx->r13;
    // 0x80196408: lui         $at, 0x467A
    ctx->r1 = S32(0X467A << 16);
    // 0x8019640C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80196410: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80196414: sh          $a1, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r5;
    // 0x80196418: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019641C: swc1        $f10, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f10.u32l;
    // 0x80196420: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x80196424: lwc1        $f18, 0x7444($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7444);
    // 0x80196428: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8019642C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80196430: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80196434: lui         $at, 0x43AA
    ctx->r1 = S32(0X43AA << 16);
    // 0x80196438: addiu       $t6, $zero, 0xD2
    ctx->r14 = ADD32(0, 0XD2);
    // 0x8019643C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80196440: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x80196444: swc1        $f4, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f4.u32l;
    // 0x80196448: swc1        $f6, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f6.u32l;
    // 0x8019644C: sh          $t6, 0xBC($s1)
    MEM_H(0XBC, ctx->r17) = ctx->r14;
    // 0x80196450: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196454: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x80196458: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019645C: lui         $v1, 0x801A
    ctx->r3 = S32(0X801A << 16);
    // 0x80196460: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x80196464: addiu       $a0, $a0, 0x68FC
    ctx->r4 = ADD32(ctx->r4, 0X68FC);
    // 0x80196468: addiu       $v1, $v1, 0x68BC
    ctx->r3 = ADD32(ctx->r3, 0X68BC);
    // 0x8019646C: addiu       $v0, $v0, 0x42D4
    ctx->r2 = ADD32(ctx->r2, 0X42D4);
    // 0x80196470: addiu       $a1, $a1, 0x6908
    ctx->r5 = ADD32(ctx->r5, 0X6908);
    // 0x80196474: lwc1        $f0, 0x7448($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7448);
L_80196478:
    // 0x80196478: lwc1        $f8, -0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, -0XC);
    // 0x8019647C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80196480: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80196484: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80196488: lwc1        $f10, -0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, -0X14);
    // 0x8019648C: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x80196490: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80196494: swc1        $f16, -0x2EC($v0)
    MEM_W(-0X2EC, ctx->r2) = ctx->f16.u32l;
    // 0x80196498: lwc1        $f18, -0x10($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, -0X10);
    // 0x8019649C: swc1        $f18, -0x2E8($v0)
    MEM_W(-0X2E8, ctx->r2) = ctx->f18.u32l;
    // 0x801964A0: lwc1        $f4, -0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, -0X8);
    // 0x801964A4: swc1        $f2, -0x200($v0)
    MEM_W(-0X200, ctx->r2) = ctx->f2.u32l;
    // 0x801964A8: bne         $a0, $a1, L_80196478
    if (ctx->r4 != ctx->r5) {
        // 0x801964AC: swc1        $f4, -0x2DC($v0)
        MEM_W(-0X2DC, ctx->r2) = ctx->f4.u32l;
            goto L_80196478;
    }
    // 0x801964AC: swc1        $f4, -0x2DC($v0)
    MEM_W(-0X2DC, ctx->r2) = ctx->f4.u32l;
    // 0x801964B0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801964B4: addiu       $v0, $v0, -0x7CA8
    ctx->r2 = ADD32(ctx->r2, -0X7CA8);
    // 0x801964B8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801964BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801964C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801964C4: sw          $t7, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r15;
L_801964C8:
    // 0x801964C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801964CC: jal         0x800B63BC
    // 0x801964D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Camera_UpdateArwing360(rdram, ctx);
        goto after_0;
    // 0x801964D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_801964D4:
    // 0x801964D4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801964D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801964DC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801964E0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x801964E4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x801964E8: addiu       $a1, $a1, 0x7838
    ctx->r5 = ADD32(ctx->r5, 0X7838);
    // 0x801964EC: lwc1        $f0, 0x744C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X744C);
    // 0x801964F0: addiu       $v0, $v0, 0x42D4
    ctx->r2 = ADD32(ctx->r2, 0X42D4);
    // 0x801964F4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801964F8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801964FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80196500: addiu       $v1, $zero, 0x50
    ctx->r3 = ADD32(0, 0X50);
L_80196504:
    // 0x80196504: sh          $zero, 0xB8($v0)
    MEM_H(0XB8, ctx->r2) = 0;
    // 0x80196508: sh          $a0, 0xBC($v0)
    MEM_H(0XBC, ctx->r2) = ctx->r4;
    // 0x8019650C: lhu         $t9, 0xBC($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0XBC);
    // 0x80196510: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80196514: bne         $t9, $zero, L_80196530
    if (ctx->r25 != 0) {
        // 0x80196518: nop
    
            goto L_80196530;
    }
    // 0x80196518: nop

    // 0x8019651C: sh          $t0, 0xB8($v0)
    MEM_H(0XB8, ctx->r2) = ctx->r8;
    // 0x80196520: sh          $t0, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r8;
    // 0x80196524: sw          $t1, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r9;
    // 0x80196528: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8019652C: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
L_80196530:
    // 0x80196530: bne         $t3, $a2, L_80196504
    if (ctx->r11 != ctx->r6) {
        // 0x80196534: addiu       $v0, $v0, 0x2F4
        ctx->r2 = ADD32(ctx->r2, 0X2F4);
            goto L_80196504;
    }
    // 0x80196534: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x80196538: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8019653C: lw          $t5, -0x6D8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6D8);
    // 0x80196540: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80196544: addiu       $a0, $a0, 0x2A58
    ctx->r4 = ADD32(ctx->r4, 0X2A58);
    // 0x80196548: bne         $v1, $t5, L_80196880
    if (ctx->r3 != ctx->r13) {
        // 0x8019654C: nop
    
            goto L_80196880;
    }
    // 0x8019654C: nop

    // 0x80196550: jal         0x800BA808
    // 0x80196554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x80196554: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80196558: b           L_80196880
    // 0x8019655C: nop

        goto L_80196880;
    // 0x8019655C: nop

L_80196560:
    // 0x80196560: jal         0x801962F4
    // 0x80196564: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Venom2_UpdateStarWolfEvents(rdram, ctx);
        goto after_2;
    // 0x80196564: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80196568: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8019656C: lw          $t7, -0x64B4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X64B4);
    // 0x80196570: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80196574: lw          $t6, -0x6D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6D8);
    // 0x80196578: addiu       $t8, $t7, 0x64
    ctx->r24 = ADD32(ctx->r15, 0X64);
    // 0x8019657C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80196580: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80196584: beq         $at, $zero, L_801965D4
    if (ctx->r1 == 0) {
        // 0x80196588: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_801965D4;
    }
    // 0x80196588: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019658C: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80196590: lbu         $t9, 0xBD0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XBD0);
    // 0x80196594: bnel        $t9, $zero, L_801965D8
    if (ctx->r25 != 0) {
        // 0x80196598: lhu         $t5, 0xBE($s1)
        ctx->r13 = MEM_HU(ctx->r17, 0XBE);
            goto L_801965D8;
    }
    goto skip_0;
    // 0x80196598: lhu         $t5, 0xBE($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XBE);
    skip_0:
    // 0x8019659C: lbu         $t5, 0xEC4($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0XEC4);
    // 0x801965A0: bnel        $t5, $zero, L_801965D8
    if (ctx->r13 != 0) {
        // 0x801965A4: lhu         $t5, 0xBE($s1)
        ctx->r13 = MEM_HU(ctx->r17, 0XBE);
            goto L_801965D8;
    }
    goto skip_1;
    // 0x801965A4: lhu         $t5, 0xBE($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XBE);
    skip_1:
    // 0x801965A8: lbu         $t7, 0x11B8($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11B8);
    // 0x801965AC: bnel        $t7, $zero, L_801965D8
    if (ctx->r15 != 0) {
        // 0x801965B0: lhu         $t5, 0xBE($s1)
        ctx->r13 = MEM_HU(ctx->r17, 0XBE);
            goto L_801965D8;
    }
    goto skip_2;
    // 0x801965B0: lhu         $t5, 0xBE($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XBE);
    skip_2:
    // 0x801965B4: lbu         $t6, 0x14AC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X14AC);
    // 0x801965B8: bnel        $t6, $zero, L_801965D8
    if (ctx->r14 != 0) {
        // 0x801965BC: lhu         $t5, 0xBE($s1)
        ctx->r13 = MEM_HU(ctx->r17, 0XBE);
            goto L_801965D8;
    }
    goto skip_3;
    // 0x801965BC: lhu         $t5, 0xBE($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XBE);
    skip_3:
    // 0x801965C0: lhu         $t8, 0xBE($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XBE);
    // 0x801965C4: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x801965C8: bnel        $t8, $zero, L_801965D8
    if (ctx->r24 != 0) {
        // 0x801965CC: lhu         $t5, 0xBE($s1)
        ctx->r13 = MEM_HU(ctx->r17, 0XBE);
            goto L_801965D8;
    }
    goto skip_4;
    // 0x801965CC: lhu         $t5, 0xBE($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XBE);
    skip_4:
    // 0x801965D0: sh          $t9, 0xBE($s1)
    MEM_H(0XBE, ctx->r17) = ctx->r25;
L_801965D4:
    // 0x801965D4: lhu         $t5, 0xBE($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0XBE);
L_801965D8:
    // 0x801965D8: bne         $a1, $t5, L_80196880
    if (ctx->r5 != ctx->r13) {
        // 0x801965DC: nop
    
            goto L_80196880;
    }
    // 0x801965DC: nop

    // 0x801965E0: lw          $t7, 0x1C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C8);
    // 0x801965E4: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x801965E8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801965EC: beq         $t4, $t7, L_80196880
    if (ctx->r12 == ctx->r15) {
        // 0x801965F0: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80196880;
    }
    // 0x801965F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801965F4: lw          $v0, 0x78D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78D4);
    // 0x801965F8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801965FC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80196600: sw          $v0, 0x7C3C($at)
    MEM_W(0X7C3C, ctx->r1) = ctx->r2;
    // 0x80196604: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196608: sw          $v0, 0x78F4($at)
    MEM_W(0X78F4, ctx->r1) = ctx->r2;
    // 0x8019660C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80196610: lw          $v0, 0x78B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B4);
    // 0x80196614: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196618: addiu       $t8, $t8, 0x78D0
    ctx->r24 = ADD32(ctx->r24, 0X78D0);
    // 0x8019661C: sw          $v0, 0x78D4($at)
    MEM_W(0X78D4, ctx->r1) = ctx->r2;
    // 0x80196620: sll         $v1, $t3, 2
    ctx->r3 = S32(ctx->r11 << 2);
    // 0x80196624: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x80196628: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8019662C: addiu       $t5, $t5, 0x78B0
    ctx->r13 = ADD32(ctx->r13, 0X78B0);
    // 0x80196630: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80196634: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80196638: addu        $a2, $v1, $t5
    ctx->r6 = ADD32(ctx->r3, ctx->r13);
    // 0x8019663C: addiu       $t6, $t6, 0x7C38
    ctx->r14 = ADD32(ctx->r14, 0X7C38);
    // 0x80196640: addiu       $t9, $t9, 0x78F0
    ctx->r25 = ADD32(ctx->r25, 0X78F0);
    // 0x80196644: addu        $a0, $v1, $t6
    ctx->r4 = ADD32(ctx->r3, ctx->r14);
    // 0x80196648: addu        $a1, $v1, $t9
    ctx->r5 = ADD32(ctx->r3, ctx->r25);
    // 0x8019664C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80196650: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80196654: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80196658: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x8019665C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80196660: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x80196664: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80196668: lw          $t8, 0x8($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X8);
    // 0x8019666C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80196670: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80196674: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80196678: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x8019667C: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x80196680: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    // 0x80196684: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x80196688: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x8019668C: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x80196690: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x80196694: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80196698: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8019669C: sw          $t4, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r12;
    // 0x801966A0: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    // 0x801966A4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801966A8: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x801966AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x801966B0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801966B4: lbu         $t6, 0x1A90($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1A90);
    // 0x801966B8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x801966BC: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801966C0: sb          $t5, 0x3180($at)
    MEM_B(0X3180, ctx->r1) = ctx->r13;
    // 0x801966C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801966C8: sw          $t6, 0x7C94($at)
    MEM_W(0X7C94, ctx->r1) = ctx->r14;
    // 0x801966CC: lw          $t8, 0x264($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X264);
    // 0x801966D0: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x801966D4: lw          $t5, 0x1A98($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1A98);
    // 0x801966D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801966DC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801966E0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801966E4: sw          $t9, 0x7C9C($at)
    MEM_W(0X7C9C, ctx->r1) = ctx->r25;
    // 0x801966E8: addiu       $v0, $v0, 0x7CA4
    ctx->r2 = ADD32(ctx->r2, 0X7CA4);
    // 0x801966EC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801966F0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801966F4: sw          $t5, 0x1A5C($at)
    MEM_W(0X1A5C, ctx->r1) = ctx->r13;
    // 0x801966F8: lbu         $t6, 0x49C($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X49C);
    // 0x801966FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196700: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80196704: sw          $t6, 0x7CAC($at)
    MEM_W(0X7CAC, ctx->r1) = ctx->r14;
    // 0x80196708: lbu         $t8, 0x49D($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X49D);
    // 0x8019670C: lw          $t9, 0x7D10($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7D10);
    // 0x80196710: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196714: sw          $t8, 0x7CB4($at)
    MEM_W(0X7CB4, ctx->r1) = ctx->r24;
    // 0x80196718: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019671C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80196720: lw          $t5, 0x7D28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7D28);
    // 0x80196724: sw          $t9, 0x7CBC($at)
    MEM_W(0X7CBC, ctx->r1) = ctx->r25;
    // 0x80196728: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019672C: b           L_80196880
    // 0x80196730: sw          $t5, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = ctx->r13;
        goto L_80196880;
    // 0x80196730: sw          $t5, 0x7CC4($at)
    MEM_W(0X7CC4, ctx->r1) = ctx->r13;
L_80196734:
    // 0x80196734: lh          $t7, -0x6F8($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X6F8);
    // 0x80196738: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019673C: sb          $zero, 0x79BC($at)
    MEM_B(0X79BC, ctx->r1) = 0;
    // 0x80196740: slti        $at, $t7, 0x258
    ctx->r1 = SIGNED(ctx->r15) < 0X258 ? 1 : 0;
    // 0x80196744: beq         $at, $zero, L_8019679C
    if (ctx->r1 == 0) {
        // 0x80196748: addiu       $a0, $s0, 0x4C
        ctx->r4 = ADD32(ctx->r16, 0X4C);
            goto L_8019679C;
    }
    // 0x80196748: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x8019674C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196750: lwc1        $f0, 0x7450($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7450);
    // 0x80196754: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80196758: lwc1        $f8, 0x4C98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C98);
    // 0x8019675C: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80196760: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80196764: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80196768: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8019676C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80196770: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80196774: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    // 0x80196778: lwc1        $f4, 0x4C9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C9C);
    // 0x8019677C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80196780: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80196784: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80196788: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x8019678C: lwc1        $f16, 0x4CA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4CA0);
    // 0x80196790: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80196794: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80196798: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
L_8019679C:
    // 0x8019679C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801967A0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801967A4: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x801967A8: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x801967AC: lw          $a1, 0x4BB4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BB4);
    // 0x801967B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801967B4: jal         0x8009BC2C
    // 0x801967B8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801967B8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x801967BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801967C0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801967C4: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x801967C8: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x801967CC: lw          $a1, 0x4BB8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BB8);
    // 0x801967D0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x801967D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801967D8: jal         0x8009BC2C
    // 0x801967DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x801967DC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x801967E0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801967E4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801967E8: lui         $a3, 0x469C
    ctx->r7 = S32(0X469C << 16);
    // 0x801967EC: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x801967F0: lw          $a1, 0x4BBC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4BBC);
    // 0x801967F4: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x801967F8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801967FC: jal         0x8009BC2C
    // 0x80196800: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80196800: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x80196804: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80196808: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019680C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80196810: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80196814: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80196818: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x8019681C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80196820: jal         0x8009BC2C
    // 0x80196824: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x80196824: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x80196828: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8019682C: lhu         $t6, -0x2768($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X2768);
    // 0x80196830: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80196834: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80196838: andi        $t8, $t6, 0x1000
    ctx->r24 = ctx->r14 & 0X1000;
    // 0x8019683C: bne         $t8, $zero, L_8019685C
    if (ctx->r24 != 0) {
        // 0x80196840: lui         $t9, 0x8016
        ctx->r25 = S32(0X8016 << 16);
            goto L_8019685C;
    }
    // 0x80196840: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80196844: lui         $t5, 0x800D
    ctx->r13 = S32(0X800D << 16);
    // 0x80196848: lw          $t5, -0x64B4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X64B4);
    // 0x8019684C: lw          $t9, -0x6D8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6D8);
    // 0x80196850: addiu       $t7, $t5, 0x12C
    ctx->r15 = ADD32(ctx->r13, 0X12C);
    // 0x80196854: bne         $t9, $t7, L_80196880
    if (ctx->r25 != ctx->r15) {
        // 0x80196858: nop
    
            goto L_80196880;
    }
    // 0x80196858: nop

L_8019685C:
    // 0x8019685C: sh          $t0, 0xB8($s1)
    MEM_H(0XB8, ctx->r17) = ctx->r8;
    // 0x80196860: sw          $t1, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r9;
    // 0x80196864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80196868: jal         0x800B7184
    // 0x8019686C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Camera_Update360(rdram, ctx);
        goto after_7;
    // 0x8019686C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80196870: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80196874: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80196878: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8019687C: sw          $zero, 0x1708($at)
    MEM_W(0X1708, ctx->r1) = 0;
L_80196880:
    // 0x80196880: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80196884: addiu       $a0, $a0, -0x6F8
    ctx->r4 = ADD32(ctx->r4, -0X6F8);
    // 0x80196888: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8019688C: beq         $v1, $zero, L_80196954
    if (ctx->r3 == 0) {
        // 0x80196890: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80196954;
    }
    // 0x80196890: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80196894: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x80196898: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x8019689C: addiu       $at, $zero, 0xDC
    ctx->r1 = ADD32(0, 0XDC);
    // 0x801968A0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801968A4: beq         $v0, $at, L_8019694C
    if (ctx->r2 == ctx->r1) {
        // 0x801968A8: addiu       $a0, $a0, 0x2C4C
        ctx->r4 = ADD32(ctx->r4, 0X2C4C);
            goto L_8019694C;
    }
    // 0x801968A8: addiu       $a0, $a0, 0x2C4C
    ctx->r4 = ADD32(ctx->r4, 0X2C4C);
    // 0x801968AC: addiu       $at, $zero, 0x15E
    ctx->r1 = ADD32(0, 0X15E);
    // 0x801968B0: beq         $v0, $at, L_80196938
    if (ctx->r2 == ctx->r1) {
        // 0x801968B4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80196938;
    }
    // 0x801968B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801968B8: addiu       $at, $zero, 0x1E0
    ctx->r1 = ADD32(0, 0X1E0);
    // 0x801968BC: beq         $v0, $at, L_80196924
    if (ctx->r2 == ctx->r1) {
        // 0x801968C0: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80196924;
    }
    // 0x801968C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801968C4: addiu       $at, $zero, 0x26C
    ctx->r1 = ADD32(0, 0X26C);
    // 0x801968C8: beq         $v0, $at, L_80196910
    if (ctx->r2 == ctx->r1) {
        // 0x801968CC: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80196910;
    }
    // 0x801968CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801968D0: addiu       $at, $zero, 0x2F8
    ctx->r1 = ADD32(0, 0X2F8);
    // 0x801968D4: beq         $v0, $at, L_801968FC
    if (ctx->r2 == ctx->r1) {
        // 0x801968D8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_801968FC;
    }
    // 0x801968D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801968DC: addiu       $at, $zero, 0x35C
    ctx->r1 = ADD32(0, 0X35C);
    // 0x801968E0: bne         $v0, $at, L_80196954
    if (ctx->r2 != ctx->r1) {
        // 0x801968E4: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80196954;
    }
    // 0x801968E4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801968E8: addiu       $a0, $a0, 0x2AB0
    ctx->r4 = ADD32(ctx->r4, 0X2AB0);
    // 0x801968EC: jal         0x800BA808
    // 0x801968F0: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    Radio_PlayMessage(rdram, ctx);
        goto after_8;
    // 0x801968F0: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    after_8:
    // 0x801968F4: b           L_80196958
    // 0x801968F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80196958;
    // 0x801968F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801968FC:
    // 0x801968FC: addiu       $a0, $a0, 0x2AF4
    ctx->r4 = ADD32(ctx->r4, 0X2AF4);
    // 0x80196900: jal         0x800BA808
    // 0x80196904: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    Radio_PlayMessage(rdram, ctx);
        goto after_9;
    // 0x80196904: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_9:
    // 0x80196908: b           L_80196958
    // 0x8019690C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80196958;
    // 0x8019690C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80196910:
    // 0x80196910: addiu       $a0, $a0, 0x2B4C
    ctx->r4 = ADD32(ctx->r4, 0X2B4C);
    // 0x80196914: jal         0x800BA808
    // 0x80196918: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    Radio_PlayMessage(rdram, ctx);
        goto after_10;
    // 0x80196918: addiu       $a1, $zero, 0xD2
    ctx->r5 = ADD32(0, 0XD2);
    after_10:
    // 0x8019691C: b           L_80196958
    // 0x80196920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80196958;
    // 0x80196920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80196924:
    // 0x80196924: addiu       $a0, $a0, 0x2BA0
    ctx->r4 = ADD32(ctx->r4, 0X2BA0);
    // 0x80196928: jal         0x800BA808
    // 0x8019692C: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    Radio_PlayMessage(rdram, ctx);
        goto after_11;
    // 0x8019692C: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    after_11:
    // 0x80196930: b           L_80196958
    // 0x80196934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80196958;
    // 0x80196934: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80196938:
    // 0x80196938: addiu       $a0, $a0, 0x2BF8
    ctx->r4 = ADD32(ctx->r4, 0X2BF8);
    // 0x8019693C: jal         0x800BA808
    // 0x80196940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_12;
    // 0x80196940: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80196944: b           L_80196958
    // 0x80196948: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80196958;
    // 0x80196948: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019694C:
    // 0x8019694C: jal         0x800BA808
    // 0x80196950: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_13;
    // 0x80196950: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_13:
L_80196954:
    // 0x80196954: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80196958:
    // 0x80196958: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8019695C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80196960: jr          $ra
    // 0x80196964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80196964: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Venom2_LevelStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196BF8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80196BFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80196C00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80196C04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80196C08: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80196C0C: lw          $t6, 0x7A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7A80);
    // 0x80196C10: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80196C14: slti        $at, $t6, 0x33
    ctx->r1 = SIGNED(ctx->r14) < 0X33 ? 1 : 0;
    // 0x80196C18: bne         $at, $zero, L_80196C2C
    if (ctx->r1 != 0) {
        // 0x80196C1C: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_80196C2C;
    }
    // 0x80196C1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80196C20: sw          $t7, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
    // 0x80196C24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80196C28: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
L_80196C2C:
    // 0x80196C2C: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80196C30: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x80196C34: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80196C38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80196C3C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80196C40: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196C44: lwc1        $f18, 0x7454($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7454);
    // 0x80196C48: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80196C4C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80196C50: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80196C54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80196C58: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80196C5C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80196C60: jal         0x80005E90
    // 0x80196C64: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80196C64: nop

    after_0:
    // 0x80196C68: lwc1        $f6, 0x120($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80196C6C: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x80196C70: lwc1        $f16, 0x4D8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x80196C74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196C78: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80196C7C: lwc1        $f4, 0x7458($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7458);
    // 0x80196C80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80196C84: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80196C88: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80196C8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80196C90: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80196C94: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80196C98: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80196C9C: jal         0x80005D44
    // 0x80196CA0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80196CA0: nop

    after_1:
    // 0x80196CA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80196CA8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80196CAC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80196CB0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80196CB4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80196CB8: lwc1        $f16, 0x110($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X110);
    // 0x80196CBC: lwc1        $f10, 0xD0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD0);
    // 0x80196CC0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80196CC4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80196CC8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80196CCC: jal         0x80006A20
    // 0x80196CD0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x80196CD0: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80196CD4: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80196CD8: lwc1        $f10, 0x74($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80196CDC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80196CE0: swc1        $f4, 0xC0($s0)
    MEM_W(0XC0, ctx->r16) = ctx->f4.u32l;
    // 0x80196CE4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80196CE8: lwc1        $f16, 0xC0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x80196CEC: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80196CF0: swc1        $f6, 0xC8($s0)
    MEM_W(0XC8, ctx->r16) = ctx->f6.u32l;
    // 0x80196CF4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80196CF8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80196CFC: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x80196D00: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x80196D04: lwc1        $f6, 0xC4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x80196D08: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80196D0C: swc1        $f18, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f18.u32l;
    // 0x80196D10: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80196D14: lwc1        $f6, 0x12C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x80196D18: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80196D1C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80196D20: swc1        $f8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f8.u32l;
    // 0x80196D24: lwc1        $f10, 0x130($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X130);
    // 0x80196D28: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80196D2C: swc1        $f18, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f18.u32l;
    // 0x80196D30: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80196D34: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80196D38: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80196D3C: lwc1        $f0, 0x7C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80196D40: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80196D44: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80196D48: swc1        $f16, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f16.u32l;
    // 0x80196D4C: swc1        $f18, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f18.u32l;
    // 0x80196D50: swc1        $f0, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f0.u32l;
    // 0x80196D54: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x80196D58: lwc1        $f6, 0x745C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X745C);
    // 0x80196D5C: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80196D60: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80196D64: swc1        $f0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f0.u32l;
    // 0x80196D68: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x80196D6C: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x80196D70: swc1        $f10, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f10.u32l;
    // 0x80196D74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80196D78: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80196D7C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80196D80: jr          $ra
    // 0x80196D84: nop

    return;
    // 0x80196D84: nop

;}
RECOMP_FUNC void Andross_AndAndross_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801924B4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x801924B8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801924BC: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x801924C0: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x801924C4: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x801924C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801924CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801924D0: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    // 0x801924D4: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x801924D8: addiu       $t6, $t6, 0x6800
    ctx->r14 = ADD32(ctx->r14, 0X6800);
    // 0x801924DC: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x801924E0: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x801924E4: addiu       $t1, $t1, 0x680C
    ctx->r9 = ADD32(ctx->r9, 0X680C);
    // 0x801924E8: sw          $at, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r1;
    // 0x801924EC: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801924F0: addiu       $t0, $sp, 0x88
    ctx->r8 = ADD32(ctx->r29, 0X88);
    // 0x801924F4: lui         $t5, 0x801A
    ctx->r13 = S32(0X801A << 16);
    // 0x801924F8: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x801924FC: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x80192500: addiu       $t5, $t5, 0x6818
    ctx->r13 = ADD32(ctx->r13, 0X6818);
    // 0x80192504: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80192508: sw          $at, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r1;
    // 0x8019250C: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x80192510: lw          $t4, 0x4($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X4);
    // 0x80192514: addiu       $t3, $t3, 0x6824
    ctx->r11 = ADD32(ctx->r11, 0X6824);
    // 0x80192518: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8019251C: lw          $at, 0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X8);
    // 0x80192520: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
    // 0x80192524: addiu       $t9, $sp, 0x70
    ctx->r25 = ADD32(ctx->r29, 0X70);
    // 0x80192528: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x8019252C: lw          $at, 0x0($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X0);
    // 0x80192530: lui         $t7, 0x801A
    ctx->r15 = S32(0X801A << 16);
    // 0x80192534: addiu       $t7, $t7, 0x6830
    ctx->r15 = ADD32(ctx->r15, 0X6830);
    // 0x80192538: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8019253C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80192540: addiu       $t4, $sp, 0x64
    ctx->r12 = ADD32(ctx->r29, 0X64);
    // 0x80192544: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x80192548: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8019254C: lw          $at, 0x8($t5)
    ctx->r1 = MEM_W(ctx->r13, 0X8);
    // 0x80192550: addiu       $t2, $t2, 0x683C
    ctx->r10 = ADD32(ctx->r10, 0X683C);
    // 0x80192554: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x80192558: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8019255C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80192560: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80192564: lui         $t8, 0x801A
    ctx->r24 = S32(0X801A << 16);
    // 0x80192568: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8019256C: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80192570: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80192574: addiu       $t8, $t8, 0x6848
    ctx->r24 = ADD32(ctx->r24, 0X6848);
    // 0x80192578: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x8019257C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80192580: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80192584: addiu       $t5, $sp, 0x4C
    ctx->r13 = ADD32(ctx->r29, 0X4C);
    // 0x80192588: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x8019258C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80192590: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80192594: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x80192598: sw          $at, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r1;
    // 0x8019259C: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x801925A0: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x801925A4: addiu       $t9, $t9, 0x6854
    ctx->r25 = ADD32(ctx->r25, 0X6854);
    // 0x801925A8: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x801925AC: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x801925B0: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x801925B4: addiu       $t3, $sp, 0x40
    ctx->r11 = ADD32(ctx->r29, 0X40);
    // 0x801925B8: sw          $at, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r1;
    // 0x801925BC: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x801925C0: lw          $t6, 0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X4);
    // 0x801925C4: lui         $t4, 0x801A
    ctx->r12 = S32(0X801A << 16);
    // 0x801925C8: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x801925CC: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x801925D0: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x801925D4: addiu       $t4, $t4, 0x6860
    ctx->r12 = ADD32(ctx->r12, 0X6860);
    // 0x801925D8: sw          $at, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r1;
    // 0x801925DC: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x801925E0: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x801925E4: addiu       $t7, $sp, 0x34
    ctx->r15 = ADD32(ctx->r29, 0X34);
    // 0x801925E8: sw          $at, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r1;
    // 0x801925EC: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x801925F0: sw          $t1, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r9;
    // 0x801925F4: lui         $t0, 0x801A
    ctx->r8 = S32(0X801A << 16);
    // 0x801925F8: sw          $at, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r1;
    // 0x801925FC: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80192600: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    // 0x80192604: addiu       $t0, $t0, 0x686C
    ctx->r8 = ADD32(ctx->r8, 0X686C);
    // 0x80192608: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x8019260C: lw          $at, 0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X8);
    // 0x80192610: sw          $t6, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r14;
    // 0x80192614: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x80192618: sw          $at, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r1;
    // 0x8019261C: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x80192620: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80192624: addiu       $t5, $a0, -0x3
    ctx->r13 = ADD32(ctx->r4, -0X3);
    // 0x80192628: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x8019262C: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x80192630: sw          $t1, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r9;
    // 0x80192634: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x80192638: sltiu       $at, $t5, 0x1A
    ctx->r1 = ctx->r13 < 0X1A ? 1 : 0;
    // 0x8019263C: beq         $at, $zero, L_80192760
    if (ctx->r1 == 0) {
        // 0x80192640: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80192760;
    }
    // 0x80192640: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80192644: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80192648: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019264C: addu        $at, $at, $t5
    gpr jr_addend_80192654 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80192650: lw          $t5, 0x7270($at)
    ctx->r13 = ADD32(ctx->r1, 0X7270);
    // 0x80192654: jr          $t5
    // 0x80192658: nop

    switch (jr_addend_80192654 >> 2) {
        case 0: goto L_8019265C; break;
        case 1: goto L_80192678; break;
        case 2: goto L_80192694; break;
        case 3: goto L_80192760; break;
        case 4: goto L_80192760; break;
        case 5: goto L_80192760; break;
        case 6: goto L_80192760; break;
        case 7: goto L_80192760; break;
        case 8: goto L_801926E4; break;
        case 9: goto L_801926C4; break;
        case 10: goto L_80192760; break;
        case 11: goto L_80192760; break;
        case 12: goto L_80192760; break;
        case 13: goto L_80192760; break;
        case 14: goto L_80192760; break;
        case 15: goto L_80192760; break;
        case 16: goto L_80192760; break;
        case 17: goto L_80192704; break;
        case 18: goto L_80192760; break;
        case 19: goto L_80192760; break;
        case 20: goto L_80192760; break;
        case 21: goto L_80192760; break;
        case 22: goto L_80192744; break;
        case 23: goto L_80192760; break;
        case 24: goto L_80192760; break;
        case 25: goto L_80192724; break;
        default: switch_error(__func__, 0x80192654, 0x801A7270);
    }
    // 0x80192658: nop

L_8019265C:
    // 0x8019265C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192660: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192664: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192668: jal         0x80006970
    // 0x8019266C: addiu       $a2, $s0, 0x1B8
    ctx->r6 = ADD32(ctx->r16, 0X1B8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8019266C: addiu       $a2, $s0, 0x1B8
    ctx->r6 = ADD32(ctx->r16, 0X1B8);
    after_0:
    // 0x80192670: b           L_80192760
    // 0x80192674: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
        goto L_80192760;
    // 0x80192674: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
L_80192678:
    // 0x80192678: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8019267C: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x80192680: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192684: jal         0x80006970
    // 0x80192688: addiu       $a2, $s0, 0x1C4
    ctx->r6 = ADD32(ctx->r16, 0X1C4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_1;
    // 0x80192688: addiu       $a2, $s0, 0x1C4
    ctx->r6 = ADD32(ctx->r16, 0X1C4);
    after_1:
    // 0x8019268C: b           L_80192760
    // 0x80192690: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
        goto L_80192760;
    // 0x80192690: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
L_80192694:
    // 0x80192694: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192698: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019269C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801926A0: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x801926A4: jal         0x80006970
    // 0x801926A8: addiu       $a2, $s0, 0x1E8
    ctx->r6 = ADD32(ctx->r16, 0X1E8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801926A8: addiu       $a2, $s0, 0x1E8
    ctx->r6 = ADD32(ctx->r16, 0X1E8);
    after_2:
    // 0x801926AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801926B0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x801926B4: jal         0x80006970
    // 0x801926B8: addiu       $a2, $s0, 0x1F4
    ctx->r6 = ADD32(ctx->r16, 0X1F4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x801926B8: addiu       $a2, $s0, 0x1F4
    ctx->r6 = ADD32(ctx->r16, 0X1F4);
    after_3:
    // 0x801926BC: b           L_80192760
    // 0x801926C0: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
        goto L_80192760;
    // 0x801926C0: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
L_801926C4:
    // 0x801926C4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801926C8: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801926CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801926D0: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x801926D4: jal         0x80006970
    // 0x801926D8: addiu       $a2, $s0, 0x20C
    ctx->r6 = ADD32(ctx->r16, 0X20C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_4;
    // 0x801926D8: addiu       $a2, $s0, 0x20C
    ctx->r6 = ADD32(ctx->r16, 0X20C);
    after_4:
    // 0x801926DC: b           L_80192760
    // 0x801926E0: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
        goto L_80192760;
    // 0x801926E0: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
L_801926E4:
    // 0x801926E4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801926E8: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801926EC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801926F0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x801926F4: jal         0x80006970
    // 0x801926F8: addiu       $a2, $s0, 0x200
    ctx->r6 = ADD32(ctx->r16, 0X200);
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x801926F8: addiu       $a2, $s0, 0x200
    ctx->r6 = ADD32(ctx->r16, 0X200);
    after_5:
    // 0x801926FC: b           L_80192760
    // 0x80192700: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
        goto L_80192760;
    // 0x80192700: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
L_80192704:
    // 0x80192704: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192708: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019270C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192710: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x80192714: jal         0x80006970
    // 0x80192718: addiu       $a2, $s0, 0x1A0
    ctx->r6 = ADD32(ctx->r16, 0X1A0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x80192718: addiu       $a2, $s0, 0x1A0
    ctx->r6 = ADD32(ctx->r16, 0X1A0);
    after_6:
    // 0x8019271C: b           L_80192760
    // 0x80192720: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
        goto L_80192760;
    // 0x80192720: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
L_80192724:
    // 0x80192724: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192728: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019272C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192730: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80192734: jal         0x80006970
    // 0x80192738: addiu       $a2, $s0, 0x1AC
    ctx->r6 = ADD32(ctx->r16, 0X1AC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x80192738: addiu       $a2, $s0, 0x1AC
    ctx->r6 = ADD32(ctx->r16, 0X1AC);
    after_7:
    // 0x8019273C: b           L_80192760
    // 0x80192740: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
        goto L_80192760;
    // 0x80192740: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
L_80192744:
    // 0x80192744: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192748: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019274C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192750: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x80192754: jal         0x80006970
    // 0x80192758: addiu       $a2, $s0, 0x218
    ctx->r6 = ADD32(ctx->r16, 0X218);
    Matrix_MultVec3f(rdram, ctx);
        goto after_8;
    // 0x80192758: addiu       $a2, $s0, 0x218
    ctx->r6 = ADD32(ctx->r16, 0X218);
    after_8:
    // 0x8019275C: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
L_80192760:
    // 0x80192760: lh          $t7, 0x4E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4E);
    // 0x80192764: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80192768: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x8019276C: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x80192770: bne         $at, $zero, L_801928B4
    if (ctx->r1 != 0) {
        // 0x80192774: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_801928B4;
    }
    // 0x80192774: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80192778: addiu       $t6, $t4, -0x1
    ctx->r14 = ADD32(ctx->r12, -0X1);
    // 0x8019277C: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x80192780: beq         $at, $zero, L_801928B4
    if (ctx->r1 == 0) {
        // 0x80192784: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801928B4;
    }
    // 0x80192784: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80192788: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019278C: addu        $at, $at, $t6
    gpr jr_addend_80192794 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80192790: lw          $t6, 0x72D8($at)
    ctx->r14 = ADD32(ctx->r1, 0X72D8);
    // 0x80192794: jr          $t6
    // 0x80192798: nop

    switch (jr_addend_80192794 >> 2) {
        case 0: goto L_8019279C; break;
        case 1: goto L_801927B4; break;
        case 2: goto L_801927CC; break;
        case 3: goto L_801927E4; break;
        case 4: goto L_801927FC; break;
        case 5: goto L_80192814; break;
        case 6: goto L_8019282C; break;
        case 7: goto L_80192844; break;
        case 8: goto L_8019285C; break;
        case 9: goto L_80192874; break;
        case 10: goto L_8019288C; break;
        case 11: goto L_801928A4; break;
        default: switch_error(__func__, 0x80192794, 0x801A72D8);
    }
    // 0x80192798: nop

L_8019279C:
    // 0x8019279C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801927A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801927A4: jal         0x80006970
    // 0x801927A8: addiu       $a2, $s0, 0x260
    ctx->r6 = ADD32(ctx->r16, 0X260);
    Matrix_MultVec3f(rdram, ctx);
        goto after_9;
    // 0x801927A8: addiu       $a2, $s0, 0x260
    ctx->r6 = ADD32(ctx->r16, 0X260);
    after_9:
    // 0x801927AC: b           L_801928B8
    // 0x801927B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x801927B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801927B4:
    // 0x801927B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801927B8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801927BC: jal         0x80006970
    // 0x801927C0: addiu       $a2, $s0, 0x254
    ctx->r6 = ADD32(ctx->r16, 0X254);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x801927C0: addiu       $a2, $s0, 0x254
    ctx->r6 = ADD32(ctx->r16, 0X254);
    after_10:
    // 0x801927C4: b           L_801928B8
    // 0x801927C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x801927C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801927CC:
    // 0x801927CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801927D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801927D4: jal         0x80006970
    // 0x801927D8: addiu       $a2, $s0, 0x23C
    ctx->r6 = ADD32(ctx->r16, 0X23C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_11;
    // 0x801927D8: addiu       $a2, $s0, 0x23C
    ctx->r6 = ADD32(ctx->r16, 0X23C);
    after_11:
    // 0x801927DC: b           L_801928B8
    // 0x801927E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x801927E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801927E4:
    // 0x801927E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801927E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x801927EC: jal         0x80006970
    // 0x801927F0: addiu       $a2, $s0, 0x248
    ctx->r6 = ADD32(ctx->r16, 0X248);
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x801927F0: addiu       $a2, $s0, 0x248
    ctx->r6 = ADD32(ctx->r16, 0X248);
    after_12:
    // 0x801927F4: b           L_801928B8
    // 0x801927F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x801927F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801927FC:
    // 0x801927FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192800: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80192804: jal         0x80006970
    // 0x80192808: addiu       $a2, $s0, 0x284
    ctx->r6 = ADD32(ctx->r16, 0X284);
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x80192808: addiu       $a2, $s0, 0x284
    ctx->r6 = ADD32(ctx->r16, 0X284);
    after_13:
    // 0x8019280C: b           L_801928B8
    // 0x80192810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x80192810: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192814:
    // 0x80192814: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192818: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8019281C: jal         0x80006970
    // 0x80192820: addiu       $a2, $s0, 0x29C
    ctx->r6 = ADD32(ctx->r16, 0X29C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_14;
    // 0x80192820: addiu       $a2, $s0, 0x29C
    ctx->r6 = ADD32(ctx->r16, 0X29C);
    after_14:
    // 0x80192824: b           L_801928B8
    // 0x80192828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x80192828: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019282C:
    // 0x8019282C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192830: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80192834: jal         0x80006970
    // 0x80192838: addiu       $a2, $s0, 0x2A8
    ctx->r6 = ADD32(ctx->r16, 0X2A8);
    Matrix_MultVec3f(rdram, ctx);
        goto after_15;
    // 0x80192838: addiu       $a2, $s0, 0x2A8
    ctx->r6 = ADD32(ctx->r16, 0X2A8);
    after_15:
    // 0x8019283C: b           L_801928B8
    // 0x80192840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x80192840: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192844:
    // 0x80192844: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192848: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8019284C: jal         0x80006970
    // 0x80192850: addiu       $a2, $s0, 0x2B4
    ctx->r6 = ADD32(ctx->r16, 0X2B4);
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x80192850: addiu       $a2, $s0, 0x2B4
    ctx->r6 = ADD32(ctx->r16, 0X2B4);
    after_16:
    // 0x80192854: b           L_801928B8
    // 0x80192858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x80192858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019285C:
    // 0x8019285C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192860: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80192864: jal         0x80006970
    // 0x80192868: addiu       $a2, $s0, 0x2CC
    ctx->r6 = ADD32(ctx->r16, 0X2CC);
    Matrix_MultVec3f(rdram, ctx);
        goto after_17;
    // 0x80192868: addiu       $a2, $s0, 0x2CC
    ctx->r6 = ADD32(ctx->r16, 0X2CC);
    after_17:
    // 0x8019286C: b           L_801928B8
    // 0x80192870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x80192870: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80192874:
    // 0x80192874: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192878: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8019287C: jal         0x80006970
    // 0x80192880: addiu       $a2, $s0, 0x2C0
    ctx->r6 = ADD32(ctx->r16, 0X2C0);
    Matrix_MultVec3f(rdram, ctx);
        goto after_18;
    // 0x80192880: addiu       $a2, $s0, 0x2C0
    ctx->r6 = ADD32(ctx->r16, 0X2C0);
    after_18:
    // 0x80192884: b           L_801928B8
    // 0x80192888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x80192888: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8019288C:
    // 0x8019288C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80192890: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80192894: jal         0x80006970
    // 0x80192898: addiu       $a2, $s0, 0x278
    ctx->r6 = ADD32(ctx->r16, 0X278);
    Matrix_MultVec3f(rdram, ctx);
        goto after_19;
    // 0x80192898: addiu       $a2, $s0, 0x278
    ctx->r6 = ADD32(ctx->r16, 0X278);
    after_19:
    // 0x8019289C: b           L_801928B8
    // 0x801928A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801928B8;
    // 0x801928A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801928A4:
    // 0x801928A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801928A8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801928AC: jal         0x80006970
    // 0x801928B0: addiu       $a2, $s0, 0x26C
    ctx->r6 = ADD32(ctx->r16, 0X26C);
    Matrix_MultVec3f(rdram, ctx);
        goto after_20;
    // 0x801928B0: addiu       $a2, $s0, 0x26C
    ctx->r6 = ADD32(ctx->r16, 0X26C);
    after_20:
L_801928B4:
    // 0x801928B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801928B8:
    // 0x801928B8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801928BC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801928C0: jr          $ra
    // 0x801928C4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x801928C4: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Andross_Team_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193AE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80193AE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80193AEC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80193AF0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80193AF4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80193AF8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80193AFC: addiu       $t8, $t8, 0x3FE0
    ctx->r24 = ADD32(ctx->r24, 0X3FE0);
    // 0x80193B00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80193B04: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80193B08: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80193B0C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80193B10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80193B14: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80193B18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80193B1C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80193B20: jal         0x800613C4
    // 0x80193B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80193B24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80193B28: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80193B2C: addiu       $t0, $zero, 0xC3
    ctx->r8 = ADD32(0, 0XC3);
    // 0x80193B30: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x80193B34: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
    // 0x80193B38: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80193B3C: lui         $t3, 0x801A
    ctx->r11 = S32(0X801A << 16);
    // 0x80193B40: addiu       $t3, $t3, 0x6878
    ctx->r11 = ADD32(ctx->r11, 0X6878);
    // 0x80193B44: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80193B48: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80193B4C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80193B50: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80193B54: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80193B58: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80193B5C: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x80193B60: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80193B64: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80193B68: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80193B6C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80193B70: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80193B74: jal         0x800612B8
    // 0x80193B78: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80193B78: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80193B7C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80193B80: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80193B84: addiu       $t4, $t4, 0x3FFC
    ctx->r12 = ADD32(ctx->r12, 0X3FFC);
    // 0x80193B88: bne         $a0, $t4, L_80193BD4
    if (ctx->r4 != ctx->r12) {
        // 0x80193B8C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80193BD4;
    }
    // 0x80193B8C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80193B90: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80193B94: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x80193B98: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80193B9C: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80193BA0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80193BA4: sh          $t5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r13;
    // 0x80193BA8: sh          $t6, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r14;
    // 0x80193BAC: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80193BB0: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x80193BB4: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x80193BB8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80193BBC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80193BC0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80193BC4: jal         0x80019218
    // 0x80193BC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x80193BC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80193BCC: b           L_80193C3C
    // 0x80193BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80193C3C;
    // 0x80193BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80193BD4:
    // 0x80193BD4: jal         0x80004EB0
    // 0x80193BD8: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80193BD8: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    after_3:
    // 0x80193BDC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80193BE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193BE4: nop

    // 0x80193BE8: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80193BEC: jal         0x80004EB0
    // 0x80193BF0: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80193BF0: swc1        $f16, 0x130($s0)
    MEM_W(0X130, ctx->r16) = ctx->f16.u32l;
    after_4:
    // 0x80193BF4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80193BF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193BFC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80193C00: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x80193C04: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80193C08: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80193C0C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80193C10: sh          $t9, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r25;
    // 0x80193C14: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80193C18: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80193C1C: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x80193C20: swc1        $f4, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f4.u32l;
    // 0x80193C24: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80193C28: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80193C2C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80193C30: jal         0x80019218
    // 0x80193C34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80193C34: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80193C38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80193C3C:
    // 0x80193C3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80193C40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80193C44: jr          $ra
    // 0x80193C48: nop

    return;
    // 0x80193C48: nop

;}
RECOMP_FUNC void SectorY_ActorDebris_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A3B50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A3B54: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A3B58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801A3B5C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801A3B60: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x801A3B64: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801A3B68: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x801A3B6C: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x801A3B70: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_801A3B74:
    // 0x801A3B74: bnel        $t6, $zero, L_801A3BB8
    if (ctx->r14 != 0) {
        // 0x801A3B78: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_801A3BB8;
    }
    goto skip_0;
    // 0x801A3B78: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_0:
    // 0x801A3B7C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A3B80: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A3B84: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801A3B88: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x801A3B8C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x801A3B90: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x801A3B94: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801A3B98: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A3B9C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A3BA0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801A3BA4: jal         0x801A39FC
    // 0x801A3BA8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    SectorY_ActorDebris_Setup(rdram, ctx);
        goto after_0;
    // 0x801A3BA8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x801A3BAC: b           L_801A3BC8
    // 0x801A3BB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801A3BC8;
    // 0x801A3BB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A3BB4: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_801A3BB8:
    // 0x801A3BB8: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x801A3BBC: beql        $at, $zero, L_801A3B74
    if (ctx->r1 == 0) {
        // 0x801A3BC0: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_801A3B74;
    }
    goto skip_1;
    // 0x801A3BC0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x801A3BC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801A3BC8:
    // 0x801A3BC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A3BCC: jr          $ra
    // 0x801A3BD0: nop

    return;
    // 0x801A3BD0: nop

;}
RECOMP_FUNC void Andross_801935B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801935B4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x801935B8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x801935BC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x801935C0: beq         $a0, $at, L_801935CC
    if (ctx->r4 == ctx->r1) {
        // 0x801935C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801935CC;
    }
    // 0x801935C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801935C8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_801935CC:
    // 0x801935CC: jr          $ra
    // 0x801935D0: nop

    return;
    // 0x801935D0: nop

;}
RECOMP_FUNC void SectorY_80199438(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199438: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8019943C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80199440: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80199444: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80199448: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8019944C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80199450: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80199454: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80199458: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019945C: lh          $v0, 0x60($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X60);
    // 0x80199460: bgtz        $v0, L_80199B90
    if (SIGNED(ctx->r2) > 0) {
        // 0x80199464: slti        $at, $v0, 0x50
        ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
            goto L_80199B90;
    }
    // 0x80199464: slti        $at, $v0, 0x50
    ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    // 0x80199468: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8019946C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80199470: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x80199474: bnel        $t6, $zero, L_80199510
    if (ctx->r14 != 0) {
        // 0x80199478: lwc1        $f18, 0x20($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
            goto L_80199510;
    }
    goto skip_0;
    // 0x80199478: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    skip_0:
    // 0x8019947C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80199480: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80199484: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80199488: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019948C: swc1        $f4, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f4.u32l;
    // 0x80199490: swc1        $f6, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f6.u32l;
    // 0x80199494: swc1        $f8, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f8.u32l;
    // 0x80199498: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x8019949C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801994A0: addiu       $a0, $a0, 0xA2C
    ctx->r4 = ADD32(ctx->r4, 0XA2C);
    // 0x801994A4: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x801994A8: beql        $at, $zero, L_801994C4
    if (ctx->r1 == 0) {
        // 0x801994AC: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_801994C4;
    }
    goto skip_1;
    // 0x801994AC: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    skip_1:
    // 0x801994B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801994B4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801994B8: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
    // 0x801994BC: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801994C0: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
L_801994C4:
    // 0x801994C4: bnel        $v0, $at, L_801994E0
    if (ctx->r2 != ctx->r1) {
        // 0x801994C8: slti        $at, $v0, 0x50
        ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
            goto L_801994E0;
    }
    goto skip_2;
    // 0x801994C8: slti        $at, $v0, 0x50
    ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
    skip_2:
    // 0x801994CC: jal         0x800BA808
    // 0x801994D0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x801994D0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_0:
    // 0x801994D4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801994D8: lw          $v0, 0x7A80($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7A80);
    // 0x801994DC: slti        $at, $v0, 0x50
    ctx->r1 = SIGNED(ctx->r2) < 0X50 ? 1 : 0;
L_801994E0:
    // 0x801994E0: bne         $at, $zero, L_801994F4
    if (ctx->r1 != 0) {
        // 0x801994E4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801994F4;
    }
    // 0x801994E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801994E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801994EC: nop

    // 0x801994F0: swc1        $f16, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f16.u32l;
L_801994F4:
    // 0x801994F4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801994F8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801994FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80199500: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80199504: b           L_801998B4
    // 0x80199508: nop

        goto L_801998B4;
    // 0x80199508: nop

    // 0x8019950C: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
L_80199510:
    // 0x80199510: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80199514: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199518: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8019951C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80199520: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80199524: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80199528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019952C: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x80199530: lwc1        $f10, 0x7544($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7544);
    // 0x80199534: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80199538: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019953C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80199540: jal         0x80005E90
    // 0x80199544: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80199544: nop

    after_1:
    // 0x80199548: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x8019954C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80199550: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80199554: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199558: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019955C: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x80199560: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    // 0x80199564: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x80199568: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8019956C: jal         0x80006970
    // 0x80199570: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x80199570: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80199574: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80199578: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8019957C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80199580: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80199584: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80199588: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019958C: swc1        $f16, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f16.u32l;
    // 0x80199590: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80199594: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80199598: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019959C: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x801995A0: lh          $v0, 0x58($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X58);
    // 0x801995A4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801995A8: bnel        $v0, $at, L_801995E4
    if (ctx->r2 != ctx->r1) {
        // 0x801995AC: slti        $at, $v0, 0x56
        ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
            goto L_801995E4;
    }
    goto skip_3;
    // 0x801995AC: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
    skip_3:
    // 0x801995B0: lbu         $t7, -0xAE8($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0XAE8);
    // 0x801995B4: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801995B8: bnel        $t7, $zero, L_801995E4
    if (ctx->r15 != 0) {
        // 0x801995BC: slti        $at, $v0, 0x56
        ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
            goto L_801995E4;
    }
    goto skip_4;
    // 0x801995BC: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
    skip_4:
    // 0x801995C0: lbu         $t8, -0x6E0($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X6E0);
    // 0x801995C4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801995C8: addiu       $a0, $a0, 0xA2C
    ctx->r4 = ADD32(ctx->r4, 0XA2C);
    // 0x801995CC: bnel        $t8, $zero, L_801995E4
    if (ctx->r24 != 0) {
        // 0x801995D0: slti        $at, $v0, 0x56
        ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
            goto L_801995E4;
    }
    goto skip_5;
    // 0x801995D0: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
    skip_5:
    // 0x801995D4: jal         0x800BA808
    // 0x801995D8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x801995D8: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_3:
    // 0x801995DC: lh          $v0, 0x58($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X58);
    // 0x801995E0: slti        $at, $v0, 0x56
    ctx->r1 = SIGNED(ctx->r2) < 0X56 ? 1 : 0;
L_801995E4:
    // 0x801995E4: bnel        $at, $zero, L_801995FC
    if (ctx->r1 != 0) {
        // 0x801995E8: slti        $at, $v0, 0x43
        ctx->r1 = SIGNED(ctx->r2) < 0X43 ? 1 : 0;
            goto L_801995FC;
    }
    goto skip_6;
    // 0x801995E8: slti        $at, $v0, 0x43
    ctx->r1 = SIGNED(ctx->r2) < 0X43 ? 1 : 0;
    skip_6:
    // 0x801995EC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801995F0: lh          $v0, 0x58($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X58);
    // 0x801995F4: swc1        $f8, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f8.u32l;
    // 0x801995F8: slti        $at, $v0, 0x43
    ctx->r1 = SIGNED(ctx->r2) < 0X43 ? 1 : 0;
L_801995FC:
    // 0x801995FC: beq         $at, $zero, L_80199610
    if (ctx->r1 == 0) {
        // 0x80199600: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80199610;
    }
    // 0x80199600: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80199604: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80199608: lh          $v0, 0x58($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X58);
    // 0x8019960C: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
L_80199610:
    // 0x80199610: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80199614: bnel        $v0, $at, L_80199658
    if (ctx->r2 != ctx->r1) {
        // 0x80199618: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80199658;
    }
    goto skip_7;
    // 0x80199618: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    skip_7:
    // 0x8019961C: lh          $t9, 0xAE($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XAE);
    // 0x80199620: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80199624: bnel        $t9, $zero, L_80199658
    if (ctx->r25 != 0) {
        // 0x80199628: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_80199658;
    }
    goto skip_8;
    // 0x80199628: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    skip_8:
    // 0x8019962C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80199630: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80199634: jal         0x80077240
    // 0x80199638: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    BonusText_Display(rdram, ctx);
        goto after_4;
    // 0x80199638: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_4:
    // 0x8019963C: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80199640: addiu       $v1, $v1, 0x1A98
    ctx->r3 = ADD32(ctx->r3, 0X1A98);
    // 0x80199644: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80199648: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8019964C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80199650: lh          $v0, 0x58($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X58);
    // 0x80199654: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
L_80199658:
    // 0x80199658: bne         $v0, $at, L_801997A8
    if (ctx->r2 != ctx->r1) {
        // 0x8019965C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801997A8;
    }
    // 0x8019965C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80199660: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80199664: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80199668: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019966C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80199670: ori         $a0, $a0, 0xA060
    ctx->r4 = ctx->r4 | 0XA060;
    // 0x80199674: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80199678: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019967C: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80199680: jal         0x80019218
    // 0x80199684: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80199684: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x80199688: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019968C: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x80199690: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80199694: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80199698: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8019969C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801996A0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801996A4: sb          $t3, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = ctx->r11;
    // 0x801996A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801996AC: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x801996B0: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801996B4: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x801996B8: sh          $t4, 0x7BD0($at)
    MEM_H(0X7BD0, ctx->r1) = ctx->r12;
    // 0x801996BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801996C0: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x801996C4: sw          $t6, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r14;
    // 0x801996C8: lh          $t7, 0xD0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XD0);
    // 0x801996CC: lwc1        $f16, 0x70($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X70);
    // 0x801996D0: lw          $a3, 0x6C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X6C);
    // 0x801996D4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801996D8: sh          $t8, 0xD0($s1)
    MEM_H(0XD0, ctx->r17) = ctx->r24;
    // 0x801996DC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801996E0: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801996E4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801996E8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801996EC: lwc1        $f18, 0x74($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801996F0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x801996F4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801996F8: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801996FC: jal         0x8007BFFC
    // 0x80199700: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_6;
    // 0x80199700: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x80199704: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80199708: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019970C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80199710: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80199714: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80199718: jal         0x8007B344
    // 0x8019971C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_7;
    // 0x8019971C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_7:
    // 0x80199720: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80199724: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80199728: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019972C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80199730: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x80199734: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
L_80199738:
    // 0x80199738: beql        $s0, $at, L_8019979C
    if (ctx->r16 == ctx->r1) {
        // 0x8019973C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8019979C;
    }
    goto skip_9;
    // 0x8019973C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_9:
    // 0x80199740: jal         0x80004EB0
    // 0x80199744: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80199744: nop

    after_8:
    // 0x80199748: jal         0x80004EB0
    // 0x8019974C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x8019974C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_9:
    // 0x80199750: jal         0x80004EB0
    // 0x80199754: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x80199754: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_10:
    // 0x80199758: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8019975C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80199760: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80199764: sub.s       $f8, $f22, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x80199768: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x8019976C: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80199770: sub.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80199774: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80199778: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8019977C: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80199780: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80199784: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80199788: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8019978C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80199790: jal         0x801A3B50
    // 0x80199794: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    SectorY_ActorDebris_Spawn(rdram, ctx);
        goto after_11;
    // 0x80199794: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_11:
    // 0x80199798: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8019979C:
    // 0x8019979C: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x801997A0: bnel        $s0, $at, L_80199738
    if (ctx->r16 != ctx->r1) {
        // 0x801997A4: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80199738;
    }
    goto skip_10;
    // 0x801997A4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    skip_10:
L_801997A8:
    // 0x801997A8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801997AC: lwc1        $f20, 0x7548($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7548);
    // 0x801997B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801997B4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801997B8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801997BC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801997C0: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x801997C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801997C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801997CC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801997D0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801997D4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801997D8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801997DC: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x801997E0: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x801997E4: jal         0x8009BC2C
    // 0x801997E8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x801997E8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_12:
    // 0x801997EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801997F0: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x801997F4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801997F8: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x801997FC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80199800: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80199804: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x80199808: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8019980C: jal         0x8009BC2C
    // 0x80199810: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x80199810: addiu       $a0, $a0, 0x44
    ctx->r4 = ADD32(ctx->r4, 0X44);
    after_13:
    // 0x80199814: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80199818: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8019981C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80199820: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80199824: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80199828: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019982C: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x80199830: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80199834: jal         0x8009BC2C
    // 0x80199838: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x80199838: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_14:
    // 0x8019983C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80199840: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x80199844: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80199848: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019984C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80199850: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x80199854: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x80199858: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8019985C: jal         0x8009BC2C
    // 0x80199860: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x80199860: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_15:
    // 0x80199864: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80199868: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8019986C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80199870: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80199874: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80199878: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019987C: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x80199880: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80199884: jal         0x8009BC2C
    // 0x80199888: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x80199888: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    after_16:
    // 0x8019988C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80199890: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x80199894: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80199898: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019989C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801998A0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x801998A4: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x801998A8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801998AC: jal         0x8009BC2C
    // 0x801998B0: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x801998B0: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    after_17:
L_801998B4:
    // 0x801998B4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x801998B8: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x801998BC: andi        $t2, $t1, 0x3
    ctx->r10 = ctx->r9 & 0X3;
    // 0x801998C0: bne         $t2, $zero, L_8019990C
    if (ctx->r10 != 0) {
        // 0x801998C4: nop
    
            goto L_8019990C;
    }
    // 0x801998C4: nop

    // 0x801998C8: lh          $t3, 0xD0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0XD0);
    // 0x801998CC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801998D0: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x801998D4: bne         $t3, $zero, L_8019990C
    if (ctx->r11 != 0) {
        // 0x801998D8: nop
    
            goto L_8019990C;
    }
    // 0x801998D8: nop

    // 0x801998DC: lwc1        $f8, 0x70($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X70);
    // 0x801998E0: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801998E4: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801998E8: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801998EC: lw          $a3, 0x6C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X6C);
    // 0x801998F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801998F4: lwc1        $f10, 0x74($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801998F8: lwc1        $f16, 0x754C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X754C);
    // 0x801998FC: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80199900: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80199904: jal         0x8007C120
    // 0x80199908: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_18;
    // 0x80199908: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_18:
L_8019990C:
    // 0x8019990C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80199910: lw          $t5, 0x7A80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7A80);
    // 0x80199914: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80199918: bnel        $t5, $at, L_80199A90
    if (ctx->r13 != ctx->r1) {
        // 0x8019991C: lh          $t5, 0x58($s1)
        ctx->r13 = MEM_H(ctx->r17, 0X58);
            goto L_80199A90;
    }
    goto skip_11;
    // 0x8019991C: lh          $t5, 0x58($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X58);
    skip_11:
    // 0x80199920: lh          $t6, 0xD0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XD0);
    // 0x80199924: bnel        $t6, $zero, L_80199A90
    if (ctx->r14 != 0) {
        // 0x80199928: lh          $t5, 0x58($s1)
        ctx->r13 = MEM_H(ctx->r17, 0X58);
            goto L_80199A90;
    }
    goto skip_12;
    // 0x80199928: lh          $t5, 0x58($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X58);
    skip_12:
    // 0x8019992C: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x80199930: addiu       $t8, $s1, 0x3FC
    ctx->r24 = ADD32(ctx->r17, 0X3FC);
    // 0x80199934: bnel        $t7, $zero, L_80199A90
    if (ctx->r15 != 0) {
        // 0x80199938: lh          $t5, 0x58($s1)
        ctx->r13 = MEM_H(ctx->r17, 0X58);
            goto L_80199A90;
    }
    goto skip_13;
    // 0x80199938: lh          $t5, 0x58($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X58);
    skip_13:
    // 0x8019993C: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80199940: lh          $t9, 0xAE($s1)
    ctx->r25 = MEM_H(ctx->r17, 0XAE);
    // 0x80199944: bne         $t9, $zero, L_80199954
    if (ctx->r25 != 0) {
        // 0x80199948: nop
    
            goto L_80199954;
    }
    // 0x80199948: nop

    // 0x8019994C: jal         0x80042EC0
    // 0x80199950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Boss_AwardBonus(rdram, ctx);
        goto after_19;
    // 0x80199950: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
L_80199954:
    // 0x80199954: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80199958: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8019995C: addiu       $s0, $s0, 0x248
    ctx->r16 = ADD32(ctx->r16, 0X248);
    // 0x80199960: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80199964: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
L_80199968:
    // 0x80199968: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8019996C: beql        $t0, $zero, L_80199984
    if (ctx->r8 == 0) {
        // 0x80199970: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80199984;
    }
    goto skip_14;
    // 0x80199970: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_14:
    // 0x80199974: jal         0x80060FBC
    // 0x80199978: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_20;
    // 0x80199978: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_20:
    // 0x8019997C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80199980: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80199984:
    // 0x80199984: sltu        $at, $a0, $s0
    ctx->r1 = ctx->r4 < ctx->r16 ? 1 : 0;
    // 0x80199988: bnel        $at, $zero, L_80199968
    if (ctx->r1 != 0) {
        // 0x8019998C: lbu         $t0, 0x0($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X0);
            goto L_80199968;
    }
    goto skip_15;
    // 0x8019998C: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    skip_15:
    // 0x80199990: jal         0x8001A500
    // 0x80199994: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_21;
    // 0x80199994: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    after_21:
    // 0x80199998: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019999C: sw          $zero, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = 0;
    // 0x801999A0: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801999A4: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801999A8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801999AC: jal         0x8007A568
    // 0x801999B0: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    Effect_Effect383_Spawn(rdram, ctx);
        goto after_22;
    // 0x801999B0: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    after_22:
    // 0x801999B4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801999B8: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801999BC: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x801999C0: jal         0x8007D0E0
    // 0x801999C4: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_23;
    // 0x801999C4: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    after_23:
    // 0x801999C8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801999CC: lwc1        $f14, 0xC($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801999D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801999D4: jal         0x80062B60
    // 0x801999D8: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    Effect_Effect348_Spawn(rdram, ctx);
        goto after_24;
    // 0x801999D8: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    after_24:
    // 0x801999DC: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    // 0x801999E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801999E4: sw          $t1, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r9;
    // 0x801999E8: lh          $t2, 0xD0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XD0);
    // 0x801999EC: addiu       $s0, $zero, 0xA
    ctx->r16 = ADD32(0, 0XA);
    // 0x801999F0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801999F4: sh          $t3, 0xD0($s1)
    MEM_H(0XD0, ctx->r17) = ctx->r11;
    // 0x801999F8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
L_801999FC:
    // 0x801999FC: beql        $s0, $at, L_80199A60
    if (ctx->r16 == ctx->r1) {
        // 0x80199A00: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80199A60;
    }
    goto skip_16;
    // 0x80199A00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_16:
    // 0x80199A04: jal         0x80004EB0
    // 0x80199A08: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_25;
    // 0x80199A08: nop

    after_25:
    // 0x80199A0C: jal         0x80004EB0
    // 0x80199A10: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_26;
    // 0x80199A10: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_26:
    // 0x80199A14: jal         0x80004EB0
    // 0x80199A18: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_27;
    // 0x80199A18: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_27:
    // 0x80199A1C: sub.s       $f18, $f20, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x80199A20: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80199A24: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80199A28: sub.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x80199A2C: mul.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80199A30: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x80199A34: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80199A38: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80199A3C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80199A40: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80199A44: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80199A48: lwc1        $f18, 0x74($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80199A4C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80199A50: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80199A54: jal         0x801A3B50
    // 0x80199A58: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    SectorY_ActorDebris_Spawn(rdram, ctx);
        goto after_28;
    // 0x80199A58: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_28:
    // 0x80199A5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80199A60:
    // 0x80199A60: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x80199A64: bnel        $s0, $at, L_801999FC
    if (ctx->r16 != ctx->r1) {
        // 0x80199A68: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_801999FC;
    }
    goto skip_17;
    // 0x80199A68: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    skip_17:
    // 0x80199A6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80199A70: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80199A74: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80199A78: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80199A7C: sh          $t4, 0x58($s1)
    MEM_H(0X58, ctx->r17) = ctx->r12;
    // 0x80199A80: swc1        $f6, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f6.u32l;
    // 0x80199A84: swc1        $f8, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f8.u32l;
    // 0x80199A88: swc1        $f10, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f10.u32l;
    // 0x80199A8C: lh          $t5, 0x58($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X58);
L_80199A90:
    // 0x80199A90: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80199A94: addiu       $t6, $s1, 0x3FC
    ctx->r14 = ADD32(ctx->r17, 0X3FC);
    // 0x80199A98: bnel        $t5, $at, L_80199D44
    if (ctx->r13 != ctx->r1) {
        // 0x80199A9C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80199D44;
    }
    goto skip_18;
    // 0x80199A9C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    skip_18:
    // 0x80199AA0: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x80199AA4: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x80199AA8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80199AAC: beql        $t7, $zero, L_80199B80
    if (ctx->r15 == 0) {
        // 0x80199AB0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80199B80;
    }
    goto skip_19;
    // 0x80199AB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_19:
    // 0x80199AB4: lw          $t8, 0x7A34($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A34);
    // 0x80199AB8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80199ABC: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x80199AC0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80199AC4: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80199AC8: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x80199ACC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80199AD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80199AD4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80199AD8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80199ADC: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x80199AE0: jal         0x80060FBC
    // 0x80199AE4: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    Object_Kill(rdram, ctx);
        goto after_29;
    // 0x80199AE4: addiu       $a1, $a0, 0x100
    ctx->r5 = ADD32(ctx->r4, 0X100);
    after_29:
    // 0x80199AE8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80199AEC: addiu       $v1, $v1, -0xEF0
    ctx->r3 = ADD32(ctx->r3, -0XEF0);
    // 0x80199AF0: lbu         $t1, 0x408($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X408);
    // 0x80199AF4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80199AF8: addiu       $v0, $v0, -0x7D58
    ctx->r2 = ADD32(ctx->r2, -0X7D58);
    // 0x80199AFC: beq         $t1, $zero, L_80199B10
    if (ctx->r9 == 0) {
        // 0x80199B00: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80199B10;
    }
    // 0x80199B00: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80199B04: lbu         $t2, 0x810($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X810);
    // 0x80199B08: bne         $t2, $zero, L_80199B30
    if (ctx->r10 != 0) {
        // 0x80199B0C: nop
    
            goto L_80199B30;
    }
    // 0x80199B0C: nop

L_80199B10:
    // 0x80199B10: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80199B14: lui         $t4, 0x602
    ctx->r12 = S32(0X602 << 16);
    // 0x80199B18: sh          $t3, 0x4A($v1)
    MEM_H(0X4A, ctx->r3) = ctx->r11;
    // 0x80199B1C: addiu       $t4, $t4, -0xC30
    ctx->r12 = ADD32(ctx->r12, -0XC30);
    // 0x80199B20: sw          $t4, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->r12;
    // 0x80199B24: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80199B28: b           L_80199B7C
    // 0x80199B2C: sb          $zero, 0x20($t6)
    MEM_B(0X20, ctx->r14) = 0;
        goto L_80199B7C;
    // 0x80199B2C: sb          $zero, 0x20($t6)
    MEM_B(0X20, ctx->r14) = 0;
L_80199B30:
    // 0x80199B30: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80199B34: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80199B38: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80199B3C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80199B40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80199B44: sw          $t7, 0x1C8($t8)
    MEM_W(0X1C8, ctx->r24) = ctx->r15;
    // 0x80199B48: jal         0x800B63BC
    // 0x80199B4C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    Camera_UpdateArwing360(rdram, ctx);
        goto after_30;
    // 0x80199B4C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_30:
    // 0x80199B50: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80199B54: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80199B58: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80199B5C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80199B60: swc1        $f16, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f16.u32l;
    // 0x80199B64: lw          $t0, 0x78BC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78BC);
    // 0x80199B68: blez        $t0, L_80199B7C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80199B6C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80199B7C;
    }
    // 0x80199B6C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80199B70: addiu       $a0, $a0, 0x884
    ctx->r4 = ADD32(ctx->r4, 0X884);
    // 0x80199B74: jal         0x8002E4F8
    // 0x80199B78: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    AllRange_PlayMessage(rdram, ctx);
        goto after_31;
    // 0x80199B78: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_31:
L_80199B7C:
    // 0x80199B7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80199B80:
    // 0x80199B80: jal         0x80060FBC
    // 0x80199B84: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    Object_Kill(rdram, ctx);
        goto after_32;
    // 0x80199B84: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_32:
    // 0x80199B88: b           L_80199D44
    // 0x80199B8C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80199D44;
    // 0x80199B8C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80199B90:
    // 0x80199B90: beql        $at, $zero, L_80199CE4
    if (ctx->r1 == 0) {
        // 0x80199B94: slti        $at, $v0, 0x51
        ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
            goto L_80199CE4;
    }
    goto skip_20;
    // 0x80199B94: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
    skip_20:
    // 0x80199B98: lh          $t1, 0xBA($s1)
    ctx->r9 = MEM_H(ctx->r17, 0XBA);
    // 0x80199B9C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80199BA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80199BA4: bne         $t1, $zero, L_80199CE0
    if (ctx->r9 != 0) {
        // 0x80199BA8: addiu       $s0, $s0, -0x11E4
        ctx->r16 = ADD32(ctx->r16, -0X11E4);
            goto L_80199CE0;
    }
    // 0x80199BA8: addiu       $s0, $s0, -0x11E4
    ctx->r16 = ADD32(ctx->r16, -0X11E4);
    // 0x80199BAC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80199BB0: sh          $t2, 0xBA($s1)
    MEM_H(0XBA, ctx->r17) = ctx->r10;
    // 0x80199BB4: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80199BB8: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
L_80199BBC:
    // 0x80199BBC: bnel        $t3, $zero, L_80199C40
    if (ctx->r11 != 0) {
        // 0x80199BC0: addiu       $s0, $s0, -0x2F4
        ctx->r16 = ADD32(ctx->r16, -0X2F4);
            goto L_80199C40;
    }
    goto skip_21;
    // 0x80199BC0: addiu       $s0, $s0, -0x2F4
    ctx->r16 = ADD32(ctx->r16, -0X2F4);
    skip_21:
    // 0x80199BC4: jal         0x80004EB0
    // 0x80199BC8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_33;
    // 0x80199BC8: nop

    after_33:
    // 0x80199BCC: jal         0x80004EB0
    // 0x80199BD0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_34;
    // 0x80199BD0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_34:
    // 0x80199BD4: jal         0x80004EB0
    // 0x80199BD8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_35;
    // 0x80199BD8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_35:
    // 0x80199BDC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80199BE0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80199BE4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80199BE8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80199BEC: sub.s       $f18, $f20, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x80199BF0: lw          $a1, 0x148($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X148);
    // 0x80199BF4: lw          $a2, 0x14C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14C);
    // 0x80199BF8: sub.s       $f6, $f22, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x80199BFC: mul.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80199C00: lw          $a3, 0x150($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X150);
    // 0x80199C04: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80199C08: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80199C0C: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80199C10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80199C14: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x80199C18: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80199C1C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80199C20: lwc1        $f18, 0x74($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80199C24: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x80199C28: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80199C2C: jal         0x801A39FC
    // 0x80199C30: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    SectorY_ActorDebris_Setup(rdram, ctx);
        goto after_36;
    // 0x80199C30: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_36:
    // 0x80199C34: b           L_80199C50
    // 0x80199C38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
        goto L_80199C50;
    // 0x80199C38: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80199C3C: addiu       $s0, $s0, -0x2F4
    ctx->r16 = ADD32(ctx->r16, -0X2F4);
L_80199C40:
    // 0x80199C40: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x80199C44: beql        $at, $zero, L_80199BBC
    if (ctx->r1 == 0) {
        // 0x80199C48: lbu         $t3, 0x0($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X0);
            goto L_80199BBC;
    }
    goto skip_22;
    // 0x80199C48: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    skip_22:
    // 0x80199C4C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
L_80199C50:
    // 0x80199C50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80199C54: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80199C58: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80199C5C: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80199C60: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80199C64: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80199C68: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80199C6C: jal         0x8007D2C8
    // 0x80199C70: nop

    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_37;
    // 0x80199C70: nop

    after_37:
    // 0x80199C74: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x80199C78: addiu       $v0, $v0, 0x4304
    ctx->r2 = ADD32(ctx->r2, 0X4304);
    // 0x80199C7C: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x80199C80: srl         $t6, $t5, 28
    ctx->r14 = S32(U32(ctx->r13) >> 28);
    // 0x80199C84: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80199C88: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80199C8C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80199C90: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80199C94: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x80199C98: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80199C9C: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x80199CA0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80199CA4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80199CA8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80199CAC: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x80199CB0: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80199CB4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80199CB8: sw          $t1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r9;
    // 0x80199CBC: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80199CC0: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80199CC4: ori         $a0, $a0, 0xA06F
    ctx->r4 = ctx->r4 | 0XA06F;
    // 0x80199CC8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80199CCC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80199CD0: addiu       $a1, $s1, 0x3FC
    ctx->r5 = ADD32(ctx->r17, 0X3FC);
    // 0x80199CD4: jal         0x80019218
    // 0x80199CD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_38;
    // 0x80199CD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_38:
    // 0x80199CDC: lh          $v0, 0x60($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X60);
L_80199CE0:
    // 0x80199CE0: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
L_80199CE4:
    // 0x80199CE4: beq         $at, $zero, L_80199CF4
    if (ctx->r1 == 0) {
        // 0x80199CE8: addiu       $t3, $zero, 0xDAC
        ctx->r11 = ADD32(0, 0XDAC);
            goto L_80199CF4;
    }
    // 0x80199CE8: addiu       $t3, $zero, 0xDAC
    ctx->r11 = ADD32(0, 0XDAC);
    // 0x80199CEC: sh          $t3, 0xCA($s1)
    MEM_H(0XCA, ctx->r17) = ctx->r11;
    // 0x80199CF0: lh          $v0, 0x60($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X60);
L_80199CF4:
    // 0x80199CF4: slti        $at, $v0, 0x47
    ctx->r1 = SIGNED(ctx->r2) < 0X47 ? 1 : 0;
    // 0x80199CF8: beq         $at, $zero, L_80199D08
    if (ctx->r1 == 0) {
        // 0x80199CFC: addiu       $t4, $zero, 0x1F
        ctx->r12 = ADD32(0, 0X1F);
            goto L_80199D08;
    }
    // 0x80199CFC: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x80199D00: sh          $t4, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r12;
    // 0x80199D04: lh          $v0, 0x60($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X60);
L_80199D08:
    // 0x80199D08: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x80199D0C: beq         $at, $zero, L_80199D1C
    if (ctx->r1 == 0) {
        // 0x80199D10: addiu       $t5, $zero, 0xF
        ctx->r13 = ADD32(0, 0XF);
            goto L_80199D1C;
    }
    // 0x80199D10: addiu       $t5, $zero, 0xF
    ctx->r13 = ADD32(0, 0XF);
    // 0x80199D14: sh          $t5, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r13;
    // 0x80199D18: lh          $v0, 0x60($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X60);
L_80199D1C:
    // 0x80199D1C: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80199D20: beq         $at, $zero, L_80199D30
    if (ctx->r1 == 0) {
        // 0x80199D24: addiu       $t6, $zero, 0x7
        ctx->r14 = ADD32(0, 0X7);
            goto L_80199D30;
    }
    // 0x80199D24: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80199D28: sh          $t6, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r14;
    // 0x80199D2C: lh          $v0, 0x60($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X60);
L_80199D30:
    // 0x80199D30: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80199D34: beq         $at, $zero, L_80199D40
    if (ctx->r1 == 0) {
        // 0x80199D38: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_80199D40;
    }
    // 0x80199D38: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80199D3C: sh          $t7, 0xC2($s1)
    MEM_H(0XC2, ctx->r17) = ctx->r15;
L_80199D40:
    // 0x80199D40: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80199D44:
    // 0x80199D44: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80199D48: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80199D4C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80199D50: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x80199D54: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80199D58: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80199D5C: jr          $ra
    // 0x80199D60: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80199D60: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void SectorY_LevelComplete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019EE60: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8019EE64: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8019EE68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8019EE6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019EE70: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8019EE74: lw          $v1, 0x1D0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1D0);
    // 0x8019EE78: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8019EE7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EE80: beq         $v1, $zero, L_8019EEB8
    if (ctx->r3 == 0) {
        // 0x8019EE84: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8019EEB8;
    }
    // 0x8019EE84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8019EE88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8019EE8C: beq         $v1, $a1, L_8019F0E8
    if (ctx->r3 == ctx->r5) {
        // 0x8019EE90: addiu       $a0, $s1, 0xE4
        ctx->r4 = ADD32(ctx->r17, 0XE4);
            goto L_8019F0E8;
    }
    // 0x8019EE90: addiu       $a0, $s1, 0xE4
    ctx->r4 = ADD32(ctx->r17, 0XE4);
    // 0x8019EE94: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019EE98: beq         $v1, $at, L_8019F404
    if (ctx->r3 == ctx->r1) {
        // 0x8019EE9C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8019F404;
    }
    // 0x8019EE9C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019EEA0: beq         $v0, $at, L_8019F518
    if (ctx->r2 == ctx->r1) {
        // 0x8019EEA4: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8019F518;
    }
    // 0x8019EEA4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019EEA8: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8019EEAC: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
    // 0x8019EEB0: b           L_8019F964
    // 0x8019EEB4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8019F964;
    // 0x8019EEB4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8019EEB8:
    // 0x8019EEB8: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x8019EEBC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8019EEC0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019EEC4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019EEC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019EECC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019EED0: swc1        $f4, 0x4D8($s1)
    MEM_W(0X4D8, ctx->r17) = ctx->f4.u32l;
    // 0x8019EED4: swc1        $f6, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f6.u32l;
    // 0x8019EED8: swc1        $f8, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f8.u32l;
    // 0x8019EEDC: swc1        $f10, 0x110($s1)
    MEM_W(0X110, ctx->r17) = ctx->f10.u32l;
    // 0x8019EEE0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019EEE4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019EEE8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019EEEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019EEF0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019EEF4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019EEF8: sw          $a1, 0x234($s1)
    MEM_W(0X234, ctx->r17) = ctx->r5;
    // 0x8019EEFC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019EF00: swc1        $f10, 0x4A0($s1)
    MEM_W(0X4A0, ctx->r17) = ctx->f10.u32l;
    // 0x8019EF04: swc1        $f8, 0x4A8($s1)
    MEM_W(0X4A8, ctx->r17) = ctx->f8.u32l;
    // 0x8019EF08: swc1        $f6, 0x4A4($s1)
    MEM_W(0X4A4, ctx->r17) = ctx->f6.u32l;
    // 0x8019EF0C: swc1        $f4, 0x4AC($s1)
    MEM_W(0X4AC, ctx->r17) = ctx->f4.u32l;
    // 0x8019EF10: swc1        $f16, 0x12C($s1)
    MEM_W(0X12C, ctx->r17) = ctx->f16.u32l;
    // 0x8019EF14: swc1        $f18, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->f18.u32l;
    // 0x8019EF18: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8019EF1C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EF20: lwc1        $f18, -0xEEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x8019EF24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EF28: lwc1        $f6, -0xEE4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x8019EF2C: lwc1        $f16, 0x40($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8019EF30: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8019EF34: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8019EF38: jal         0x80005100
    // 0x8019EF3C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x8019EF3C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    after_0:
    // 0x8019EF40: jal         0x8009F768
    // 0x8019EF44: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_1;
    // 0x8019EF44: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8019EF48: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EF4C: swc1        $f0, 0x7A68($at)
    MEM_W(0X7A68, ctx->r1) = ctx->f0.u32l;
    // 0x8019EF50: lwc1        $f8, 0x7A68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7A68);
    // 0x8019EF54: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019EF58: lwc1        $f10, 0x77C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77C4);
    // 0x8019EF5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019EF60: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019EF64: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019EF68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019EF6C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019EF70: jal         0x80005E90
    // 0x8019EF74: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x8019EF74: nop

    after_2:
    // 0x8019EF78: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x8019EF7C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019EF80: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019EF84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019EF88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019EF8C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019EF90: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019EF94: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8019EF98: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x8019EF9C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x8019EFA0: jal         0x80006970
    // 0x8019EFA4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x8019EFA4: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8019EFA8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EFAC: lwc1        $f0, -0xEE8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XEE8);
    // 0x8019EFB0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EFB4: lwc1        $f2, -0xEEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x8019EFB8: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019EFBC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EFC0: lwc1        $f12, -0xEE4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x8019EFC4: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8019EFC8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EFCC: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019EFD0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8019EFD4: swc1        $f10, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f10.u32l;
    // 0x8019EFD8: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8019EFDC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019EFE0: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8019EFE4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EFE8: addiu       $s0, $s0, 0x5D68
    ctx->r16 = ADD32(ctx->r16, 0X5D68);
    // 0x8019EFEC: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x8019EFF0: swc1        $f18, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f18.u32l;
    // 0x8019EFF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EFF8: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
    // 0x8019EFFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F000: swc1        $f2, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f2.u32l;
    // 0x8019F004: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F008: swc1        $f0, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f0.u32l;
    // 0x8019F00C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F010: swc1        $f12, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f12.u32l;
    // 0x8019F014: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
L_8019F018:
    // 0x8019F018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019F01C: bne         $t6, $zero, L_8019F02C
    if (ctx->r14 != 0) {
        // 0x8019F020: nop
    
            goto L_8019F02C;
    }
    // 0x8019F020: nop

    // 0x8019F024: jal         0x80060FBC
    // 0x8019F028: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x8019F028: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_4:
L_8019F02C:
    // 0x8019F02C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019F030: addiu       $t7, $t7, -0xEF0
    ctx->r15 = ADD32(ctx->r15, -0XEF0);
    // 0x8019F034: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8019F038: bnel        $s0, $t7, L_8019F018
    if (ctx->r16 != ctx->r15) {
        // 0x8019F03C: lh          $t6, 0xB6($s0)
        ctx->r14 = MEM_H(ctx->r16, 0XB6);
            goto L_8019F018;
    }
    goto skip_0;
    // 0x8019F03C: lh          $t6, 0xB6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB6);
    skip_0:
    // 0x8019F040: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019F044: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019F048: addiu       $a1, $a1, 0x46C8
    ctx->r5 = ADD32(ctx->r5, 0X46C8);
    // 0x8019F04C: jal         0x80060FBC
    // 0x8019F050: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8019F050: addiu       $a0, $a0, 0x45C8
    ctx->r4 = ADD32(ctx->r4, 0X45C8);
    after_5:
    // 0x8019F054: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019F058: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019F05C: addiu       $a1, $a1, 0x49BC
    ctx->r5 = ADD32(ctx->r5, 0X49BC);
    // 0x8019F060: jal         0x80060FBC
    // 0x8019F064: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x8019F064: addiu       $a0, $a0, 0x48BC
    ctx->r4 = ADD32(ctx->r4, 0X48BC);
    after_6:
    // 0x8019F068: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019F06C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019F070: addiu       $a1, $a1, 0x4CB0
    ctx->r5 = ADD32(ctx->r5, 0X4CB0);
    // 0x8019F074: jal         0x80060FBC
    // 0x8019F078: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    Object_Kill(rdram, ctx);
        goto after_7;
    // 0x8019F078: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    after_7:
    // 0x8019F07C: lw          $t8, 0x1D0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1D0);
    // 0x8019F080: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F084: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019F088: sw          $t9, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r25;
    // 0x8019F08C: lwc1        $f8, 0x77C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X77C8);
    // 0x8019F090: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F094: jal         0x80004EB0
    // 0x8019F098: swc1        $f8, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8019F098: swc1        $f8, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f8.u32l;
    after_8:
    // 0x8019F09C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019F0A0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F0A4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8019F0A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019F0AC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8019F0B0: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
    // 0x8019F0B4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F0B8: bc1fl       L_8019F0D8
    if (!c1cs) {
        // 0x8019F0BC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8019F0D8;
    }
    goto skip_1;
    // 0x8019F0BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_1:
    // 0x8019F0C0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8019F0C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019F0C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F0CC: b           L_8019F0E0
    // 0x8019F0D0: swc1        $f16, 0x7A6C($at)
    MEM_W(0X7A6C, ctx->r1) = ctx->f16.u32l;
        goto L_8019F0E0;
    // 0x8019F0D0: swc1        $f16, 0x7A6C($at)
    MEM_W(0X7A6C, ctx->r1) = ctx->f16.u32l;
    // 0x8019F0D4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8019F0D8:
    // 0x8019F0D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F0DC: swc1        $f18, 0x7A6C($at)
    MEM_W(0X7A6C, ctx->r1) = ctx->f18.u32l;
L_8019F0E0:
    // 0x8019F0E0: b           L_8019F964
    // 0x8019F0E4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8019F964;
    // 0x8019F0E4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8019F0E8:
    // 0x8019F0E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019F0EC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F0F0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F0F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019F0F8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019F0FC: jal         0x8009BC2C
    // 0x8019F100: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8019F100: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x8019F104: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019F108: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8019F10C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F110: addiu       $a0, $s1, 0x78
    ctx->r4 = ADD32(ctx->r17, 0X78);
    // 0x8019F114: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x8019F118: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019F11C: jal         0x8009BC2C
    // 0x8019F120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8019F120: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x8019F124: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F128: lwc1        $f8, -0xEEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x8019F12C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F130: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8019F134: lwc1        $f16, -0xEE4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x8019F138: lwc1        $f10, 0x7C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x8019F13C: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019F140: jal         0x80005100
    // 0x8019F144: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    Math_Atan2F(rdram, ctx);
        goto after_11;
    // 0x8019F144: sub.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f16.fl;
    after_11:
    // 0x8019F148: jal         0x8009F768
    // 0x8019F14C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_12;
    // 0x8019F14C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_12:
    // 0x8019F150: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F154: lwc1        $f18, 0x77CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X77CC);
    // 0x8019F158: addiu       $s0, $s1, 0xE8
    ctx->r16 = ADD32(ctx->r17, 0XE8);
    // 0x8019F15C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019F160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019F164: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8019F168: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019F16C: jal         0x8009BD38
    // 0x8019F170: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_13;
    // 0x8019F170: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x8019F174: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019F178: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019F17C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F180: lwc1        $f10, 0x77D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77D0);
    // 0x8019F184: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019F188: addiu       $a0, $s1, 0xEC
    ctx->r4 = ADD32(ctx->r17, 0XEC);
    // 0x8019F18C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F190: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F194: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8019F198: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019F19C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019F1A0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8019F1A4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019F1A8: jal         0x8009BD38
    // 0x8019F1AC: nop

    Math_SmoothStepToAngle(rdram, ctx);
        goto after_14;
    // 0x8019F1AC: nop

    after_14:
    // 0x8019F1B0: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8019F1B4: lw          $t1, 0x7A80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7A80);
    // 0x8019F1B8: slti        $at, $t1, 0xB4
    ctx->r1 = SIGNED(ctx->r9) < 0XB4 ? 1 : 0;
    // 0x8019F1BC: beq         $at, $zero, L_8019F25C
    if (ctx->r1 == 0) {
        // 0x8019F1C0: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8019F25C;
    }
    // 0x8019F1C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F1C4: lwc1        $f16, 0x7A68($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7A68);
    // 0x8019F1C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F1CC: lwc1        $f18, 0x7A6C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7A6C);
    // 0x8019F1D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F1D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F1D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019F1DC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F1E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019F1E4: swc1        $f4, 0x7A68($at)
    MEM_W(0X7A68, ctx->r1) = ctx->f4.u32l;
    // 0x8019F1E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F1EC: lwc1        $f6, 0x77D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77D4);
    // 0x8019F1F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019F1F4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019F1F8: jal         0x80005E90
    // 0x8019F1FC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_15;
    // 0x8019F1FC: nop

    after_15:
    // 0x8019F200: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019F204: lui         $at, 0x44AF
    ctx->r1 = S32(0X44AF << 16);
    // 0x8019F208: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F20C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F210: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F214: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019F218: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8019F21C: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8019F220: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8019F224: jal         0x80006970
    // 0x8019F228: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x8019F228: swc1        $f10, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x8019F22C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F230: lwc1        $f2, -0xEEC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0XEEC);
    // 0x8019F234: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019F238: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F23C: lwc1        $f12, -0xEE4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0XEE4);
    // 0x8019F240: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019F244: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8019F248: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F24C: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8019F250: swc1        $f18, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f18.u32l;
    // 0x8019F254: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F258: swc1        $f6, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f6.u32l;
L_8019F25C:
    // 0x8019F25C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019F260: lui         $a1, 0x438D
    ctx->r5 = S32(0X438D << 16);
    // 0x8019F264: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F268: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F26C: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8019F270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019F274: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019F278: jal         0x8009BD38
    // 0x8019F27C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_17;
    // 0x8019F27C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_17:
    // 0x8019F280: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019F284: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F288: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019F28C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F290: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8019F294: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F298: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8019F29C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019F2A0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8019F2A4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019F2A8: jal         0x8009BC2C
    // 0x8019F2AC: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8019F2AC: nop

    after_18:
    // 0x8019F2B0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019F2B4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8019F2B8: addiu       $t2, $t2, 0x43D0
    ctx->r10 = ADD32(ctx->r10, 0X43D0);
    // 0x8019F2BC: addiu       $a0, $a0, 0x43CC
    ctx->r4 = ADD32(ctx->r4, 0X43CC);
    // 0x8019F2C0: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8019F2C4: addiu       $s0, $s0, 0x42D4
    ctx->r16 = ADD32(ctx->r16, 0X42D4);
    // 0x8019F2C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8019F2CC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
L_8019F2D0:
    // 0x8019F2D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019F2D4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F2D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8019F2DC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F2E0: lw          $a1, 0x118($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X118);
    // 0x8019F2E4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8019F2E8: jal         0x8009BD38
    // 0x8019F2EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_19;
    // 0x8019F2EC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x8019F2F0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019F2F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019F2F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019F2FC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F300: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8019F304: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F308: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8019F30C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019F310: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019F314: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019F318: jal         0x8009BC2C
    // 0x8019F31C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x8019F31C: nop

    after_20:
    // 0x8019F320: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8019F324: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8019F328: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x8019F32C: addiu       $t5, $t5, 0x4CAC
    ctx->r13 = ADD32(ctx->r13, 0X4CAC);
    // 0x8019F330: addiu       $t4, $t3, 0x2F4
    ctx->r12 = ADD32(ctx->r11, 0X2F4);
    // 0x8019F334: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x8019F338: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8019F33C: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8019F340: bne         $v0, $t5, L_8019F2D0
    if (ctx->r2 != ctx->r13) {
        // 0x8019F344: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8019F2D0;
    }
    // 0x8019F344: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8019F348: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F34C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8019F350: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019F354: addiu       $a0, $a0, -0x7CAC
    ctx->r4 = ADD32(ctx->r4, -0X7CAC);
    // 0x8019F358: slti        $at, $v1, 0xB4
    ctx->r1 = SIGNED(ctx->r3) < 0XB4 ? 1 : 0;
    // 0x8019F35C: bne         $at, $zero, L_8019F384
    if (ctx->r1 != 0) {
        // 0x8019F360: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8019F384;
    }
    // 0x8019F360: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8019F364: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F368: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x8019F36C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8019F370: addiu       $a1, $a1, -0x7CB0
    ctx->r5 = ADD32(ctx->r5, -0X7CB0);
    // 0x8019F374: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8019F378: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8019F37C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F380: sw          $v0, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r2;
L_8019F384:
    // 0x8019F384: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x8019F388: bne         $v1, $at, L_8019F3F8
    if (ctx->r3 != ctx->r1) {
        // 0x8019F38C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8019F3F8;
    }
    // 0x8019F38C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019F390: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019F394: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F398: swc1        $f16, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f16.u32l;
    // 0x8019F39C: lw          $t8, 0x1D0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1D0);
    // 0x8019F3A0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019F3A4: jal         0x800A6148
    // 0x8019F3A8: sw          $t9, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r25;
    Play_ClearObjectData(rdram, ctx);
        goto after_21;
    // 0x8019F3A8: sw          $t9, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r25;
    after_21:
    // 0x8019F3AC: jal         0x8001CA24
    // 0x8019F3B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_StopPlayerNoise(rdram, ctx);
        goto after_22;
    // 0x8019F3B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_22:
    // 0x8019F3B4: jal         0x8001A500
    // 0x8019F3B8: addiu       $a0, $s1, 0x460
    ctx->r4 = ADD32(ctx->r17, 0X460);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_23;
    // 0x8019F3B8: addiu       $a0, $s1, 0x460
    ctx->r4 = ADD32(ctx->r17, 0X460);
    after_23:
    // 0x8019F3BC: addiu       $t1, $zero, 0xFA
    ctx->r9 = ADD32(0, 0XFA);
    // 0x8019F3C0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F3C4: sw          $t1, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r9;
    // 0x8019F3C8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019F3CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019F3D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019F3D4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019F3D8: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x8019F3DC: sw          $t2, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = ctx->r10;
    // 0x8019F3E0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F3E4: swc1        $f18, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f18.u32l;
    // 0x8019F3E8: swc1        $f4, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f4.u32l;
    // 0x8019F3EC: swc1        $f6, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f6.u32l;
    // 0x8019F3F0: swc1        $f8, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f8.u32l;
    // 0x8019F3F4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8019F3F8:
    // 0x8019F3F8: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8019F3FC: b           L_8019F964
    // 0x8019F400: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
        goto L_8019F964;
    // 0x8019F400: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
L_8019F404:
    // 0x8019F404: lw          $t3, 0x1F8($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1F8);
    // 0x8019F408: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F40C: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x8019F410: bne         $t3, $zero, L_8019F504
    if (ctx->r11 != 0) {
        // 0x8019F414: nop
    
            goto L_8019F504;
    }
    // 0x8019F414: nop

    // 0x8019F418: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019F41C: sw          $a1, 0x240($s1)
    MEM_W(0X240, ctx->r17) = ctx->r5;
    // 0x8019F420: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019F424: swc1        $f0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f0.u32l;
    // 0x8019F428: lwc1        $f10, 0x77D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77D8);
    // 0x8019F42C: sw          $t4, 0x1D0($s1)
    MEM_W(0X1D0, ctx->r17) = ctx->r12;
    // 0x8019F430: swc1        $f0, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f0.u32l;
    // 0x8019F434: jal         0x8001C8B8
    // 0x8019F438: swc1        $f10, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f10.u32l;
    Audio_StartPlayerNoise(rdram, ctx);
        goto after_24;
    // 0x8019F438: swc1        $f10, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f10.u32l;
    after_24:
    // 0x8019F43C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019F440: addiu       $a1, $zero, 0x26
    ctx->r5 = ADD32(0, 0X26);
    // 0x8019F444: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019F448: jal         0x8001D444
    // 0x8019F44C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_25;
    // 0x8019F44C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_25:
    // 0x8019F450: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F454: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019F458: sb          $zero, 0x7A98($at)
    MEM_B(0X7A98, ctx->r1) = 0;
    // 0x8019F45C: addiu       $v0, $v0, -0x7D58
    ctx->r2 = ADD32(ctx->r2, -0X7D58);
    // 0x8019F460: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8019F464: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
L_8019F468:
    // 0x8019F468: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8019F46C: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8019F470: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8019F474: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8019F478: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8019F47C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    // 0x8019F480: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8019F484: addu        $t1, $t9, $v1
    ctx->r9 = ADD32(ctx->r25, ctx->r3);
    // 0x8019F488: sb          $zero, 0xB0($t1)
    MEM_B(0XB0, ctx->r9) = 0;
    // 0x8019F48C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8019F490: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8019F494: addiu       $v1, $v1, 0x160
    ctx->r3 = ADD32(ctx->r3, 0X160);
    // 0x8019F498: bne         $v1, $a0, L_8019F468
    if (ctx->r3 != ctx->r4) {
        // 0x8019F49C: sb          $zero, 0x108($t3)
        MEM_B(0X108, ctx->r11) = 0;
            goto L_8019F468;
    }
    // 0x8019F49C: sb          $zero, 0x108($t3)
    MEM_B(0X108, ctx->r11) = 0;
    // 0x8019F4A0: jal         0x800A6148
    // 0x8019F4A4: nop

    Play_ClearObjectData(rdram, ctx);
        goto after_26;
    // 0x8019F4A4: nop

    after_26:
    // 0x8019F4A8: jal         0x8019EB80
    // 0x8019F4AC: nop

    SectorY_8019EB80(rdram, ctx);
        goto after_27;
    // 0x8019F4AC: nop

    after_27:
    // 0x8019F4B0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019F4B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019F4B8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019F4BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019F4C0: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8019F4C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019F4C8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8019F4CC: addiu       $t0, $t0, 0x7A48
    ctx->r8 = ADD32(ctx->r8, 0X7A48);
    // 0x8019F4D0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8019F4D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019F4D8: lui         $at, 0x4561
    ctx->r1 = S32(0X4561 << 16);
    // 0x8019F4DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019F4E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019F4E4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019F4E8: swc1        $f16, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->f16.u32l;
    // 0x8019F4EC: swc1        $f18, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->f18.u32l;
    // 0x8019F4F0: swc1        $f6, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->f6.u32l;
    // 0x8019F4F4: swc1        $f8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f8.u32l;
    // 0x8019F4F8: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x8019F4FC: swc1        $f10, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f10.u32l;
    // 0x8019F500: sb          $t4, 0x4C8($s1)
    MEM_B(0X4C8, ctx->r17) = ctx->r12;
L_8019F504:
    // 0x8019F504: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F508: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8019F50C: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
    // 0x8019F510: b           L_8019F964
    // 0x8019F514: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
        goto L_8019F964;
    // 0x8019F514: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8019F518:
    // 0x8019F518: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8019F51C: lw          $t5, 0x7A80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7A80);
    // 0x8019F520: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8019F524: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8019F528: slti        $at, $t5, 0x2D0
    ctx->r1 = SIGNED(ctx->r13) < 0X2D0 ? 1 : 0;
    // 0x8019F52C: beq         $at, $zero, L_8019F56C
    if (ctx->r1 == 0) {
        // 0x8019F530: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8019F56C;
    }
    // 0x8019F530: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F534: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8019F538: lw          $t6, -0x7D08($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D08);
    // 0x8019F53C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019F540: beq         $t6, $zero, L_8019F56C
    if (ctx->r14 == 0) {
        // 0x8019F544: nop
    
            goto L_8019F56C;
    }
    // 0x8019F544: nop

    // 0x8019F548: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8019F54C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019F550: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019F554: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x8019F558: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8019F55C: nop

    // 0x8019F560: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8019F564: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019F568: swc1        $f6, 0x4CC($s1)
    MEM_W(0X4CC, ctx->r17) = ctx->f6.u32l;
L_8019F56C:
    // 0x8019F56C: lw          $t1, -0x7CC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7CC0);
    // 0x8019F570: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F574: sw          $zero, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = 0;
    // 0x8019F578: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F57C: bne         $t1, $zero, L_8019F588
    if (ctx->r9 != 0) {
        // 0x8019F580: sw          $t9, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r25;
            goto L_8019F588;
    }
    // 0x8019F580: sw          $t9, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r25;
    // 0x8019F584: sw          $a1, 0x204($s1)
    MEM_W(0X204, ctx->r17) = ctx->r5;
L_8019F588:
    // 0x8019F588: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8019F58C: addiu       $at, $zero, 0x157
    ctx->r1 = ADD32(0, 0X157);
    // 0x8019F590: bne         $v1, $at, L_8019F5C8
    if (ctx->r3 != ctx->r1) {
        // 0x8019F594: lui         $s0, 0x800C
        ctx->r16 = S32(0X800C << 16);
            goto L_8019F5C8;
    }
    // 0x8019F594: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8019F598: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019F59C: addiu       $a3, $s0, 0x5D34
    ctx->r7 = ADD32(ctx->r16, 0X5D34);
    // 0x8019F5A0: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019F5A4: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019F5A8: ori         $a0, $a0, 0x7
    ctx->r4 = ctx->r4 | 0X7;
    // 0x8019F5AC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019F5B0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019F5B4: addiu       $a1, $s1, 0x460
    ctx->r5 = ADD32(ctx->r17, 0X460);
    // 0x8019F5B8: jal         0x80019218
    // 0x8019F5BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_28;
    // 0x8019F5BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x8019F5C0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F5C4: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
L_8019F5C8:
    // 0x8019F5C8: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8019F5CC: addiu       $at, $zero, 0x18B
    ctx->r1 = ADD32(0, 0X18B);
    // 0x8019F5D0: bne         $v1, $at, L_8019F600
    if (ctx->r3 != ctx->r1) {
        // 0x8019F5D4: addiu       $s0, $s0, 0x5D34
        ctx->r16 = ADD32(ctx->r16, 0X5D34);
            goto L_8019F600;
    }
    // 0x8019F5D4: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
    // 0x8019F5D8: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8019F5DC: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x8019F5E0: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019F5E4: ori         $a0, $a0, 0x13
    ctx->r4 = ctx->r4 | 0X13;
    // 0x8019F5E8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8019F5EC: addiu       $a1, $s1, 0x460
    ctx->r5 = ADD32(ctx->r17, 0X460);
    // 0x8019F5F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019F5F4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8019F5F8: jal         0x80019218
    // 0x8019F5FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    Audio_PlaySfx(rdram, ctx);
        goto after_29;
    // 0x8019F5FC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_29:
L_8019F600:
    // 0x8019F600: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019F604: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8019F608: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019F60C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8019F610: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F614: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F618: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019F61C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019F620: swc1        $f16, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f16.u32l;
    // 0x8019F624: lwc1        $f4, 0x77DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77DC);
    // 0x8019F628: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019F62C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F630: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019F634: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019F638: jal         0x80005E90
    // 0x8019F63C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_30;
    // 0x8019F63C: nop

    after_30:
    // 0x8019F640: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019F644: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F648: lwc1        $f8, 0x7A68($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7A68);
    // 0x8019F64C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019F650: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019F654: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019F658: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8019F65C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8019F660: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x8019F664: jal         0x80006A20
    // 0x8019F668: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_31;
    // 0x8019F668: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_31:
    // 0x8019F66C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019F670: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F674: lui         $a1, 0x4554
    ctx->r5 = S32(0X4554 << 16);
    // 0x8019F678: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8019F67C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019F680: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8019F684: addiu       $a0, $a0, 0x7A6C
    ctx->r4 = ADD32(ctx->r4, 0X7A6C);
    // 0x8019F688: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019F68C: jal         0x8009BC2C
    // 0x8019F690: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_32;
    // 0x8019F690: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_32:
    // 0x8019F694: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019F698: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8019F69C: lui         $at, 0x42BA
    ctx->r1 = S32(0X42BA << 16);
    // 0x8019F6A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019F6A4: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019F6A8: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8019F6AC: nop

    // 0x8019F6B0: bc1f        L_8019F704
    if (!c1cs) {
        // 0x8019F6B4: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_8019F704;
    }
    // 0x8019F6B4: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8019F6B8: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x8019F6BC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F6C0: addiu       $a0, $a0, 0x7A64
    ctx->r4 = ADD32(ctx->r4, 0X7A64);
    // 0x8019F6C4: slti        $at, $t4, 0x564
    ctx->r1 = SIGNED(ctx->r12) < 0X564 ? 1 : 0;
    // 0x8019F6C8: beq         $at, $zero, L_8019F6F0
    if (ctx->r1 == 0) {
        // 0x8019F6CC: lui         $a1, 0x4396
        ctx->r5 = S32(0X4396 << 16);
            goto L_8019F6F0;
    }
    // 0x8019F6CC: lui         $a1, 0x4396
    ctx->r5 = S32(0X4396 << 16);
    // 0x8019F6D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019F6D4: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x8019F6D8: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8019F6DC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019F6E0: jal         0x8009BC2C
    // 0x8019F6E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_33;
    // 0x8019F6E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_33:
    // 0x8019F6E8: b           L_8019F704
    // 0x8019F6EC: nop

        goto L_8019F704;
    // 0x8019F6EC: nop

L_8019F6F0:
    // 0x8019F6F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019F6F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019F6F8: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8019F6FC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019F700: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
L_8019F704:
    // 0x8019F704: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8019F708: lw          $t5, 0x7A80($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7A80);
    // 0x8019F70C: slti        $at, $t5, 0x280
    ctx->r1 = SIGNED(ctx->r13) < 0X280 ? 1 : 0;
    // 0x8019F710: bnel        $at, $zero, L_8019F770
    if (ctx->r1 != 0) {
        // 0x8019F714: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8019F770;
    }
    goto skip_2;
    // 0x8019F714: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_2:
    // 0x8019F718: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019F71C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F720: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F724: lui         $a3, 0x3CCC
    ctx->r7 = S32(0X3CCC << 16);
    // 0x8019F728: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019F72C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F730: addiu       $a0, $a0, 0x7A60
    ctx->r4 = ADD32(ctx->r4, 0X7A60);
    // 0x8019F734: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8019F738: jal         0x8009BC2C
    // 0x8019F73C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_34;
    // 0x8019F73C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_34:
    // 0x8019F740: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019F744: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F748: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8019F74C: lw          $a3, 0x7A60($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X7A60);
    // 0x8019F750: addiu       $a0, $a0, 0x7A68
    ctx->r4 = ADD32(ctx->r4, 0X7A68);
    // 0x8019F754: lui         $a1, 0x44C8
    ctx->r5 = S32(0X44C8 << 16);
    // 0x8019F758: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019F75C: jal         0x8009BC2C
    // 0x8019F760: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_35;
    // 0x8019F760: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_35:
    // 0x8019F764: b           L_8019F798
    // 0x8019F768: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
        goto L_8019F798;
    // 0x8019F768: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019F76C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8019F770:
    // 0x8019F770: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F774: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019F778: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x8019F77C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x8019F780: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019F784: addiu       $a0, $a0, 0x7A68
    ctx->r4 = ADD32(ctx->r4, 0X7A68);
    // 0x8019F788: lui         $a1, 0x43AF
    ctx->r5 = S32(0X43AF << 16);
    // 0x8019F78C: jal         0x8009BC2C
    // 0x8019F790: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_36;
    // 0x8019F790: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_36:
    // 0x8019F794: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
L_8019F798:
    // 0x8019F798: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019F79C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F7A0: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x8019F7A4: swc1        $f6, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f6.u32l;
    // 0x8019F7A8: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8019F7AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F7B0: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019F7B4: swc1        $f8, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f8.u32l;
    // 0x8019F7B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F7BC: lwc1        $f10, 0x77E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77E0);
    // 0x8019F7C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019F7C4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F7C8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019F7CC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019F7D0: lw          $t6, 0x7A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7A80);
    // 0x8019F7D4: swc1        $f18, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f18.u32l;
    // 0x8019F7D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F7DC: swc1        $f0, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f0.u32l;
    // 0x8019F7E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F7E4: lwc1        $f4, 0x77E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77E4);
    // 0x8019F7E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F7EC: swc1        $f4, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f4.u32l;
    // 0x8019F7F0: lwc1        $f8, 0x7C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x8019F7F4: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8019F7F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F7FC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019F800: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
    // 0x8019F804: slti        $at, $t6, 0x5A1
    ctx->r1 = SIGNED(ctx->r14) < 0X5A1 ? 1 : 0;
    // 0x8019F808: bne         $at, $zero, L_8019F868
    if (ctx->r1 != 0) {
        // 0x8019F80C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8019F868;
    }
    // 0x8019F80C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019F810: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019F814: lwc1        $f16, 0xD0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XD0);
    // 0x8019F818: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F81C: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8019F820: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019F824: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019F828: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F82C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019F830: swc1        $f4, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->f4.u32l;
    // 0x8019F834: lwc1        $f8, 0x77E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X77E8);
    // 0x8019F838: lui         $a3, 0x3A83
    ctx->r7 = S32(0X3A83 << 16);
    // 0x8019F83C: ori         $a3, $a3, 0x126F
    ctx->r7 = ctx->r7 | 0X126F;
    // 0x8019F840: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019F844: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x8019F848: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019F84C: swc1        $f10, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f10.u32l;
    // 0x8019F850: jal         0x8009BC2C
    // 0x8019F854: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_37;
    // 0x8019F854: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_37:
    // 0x8019F858: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8019F85C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019F860: b           L_8019F8D4
    // 0x8019F864: swc1        $f18, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f18.u32l;
        goto L_8019F8D4;
    // 0x8019F864: swc1        $f18, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f18.u32l;
L_8019F868:
    // 0x8019F868: lui         $at, 0x42B8
    ctx->r1 = S32(0X42B8 << 16);
    // 0x8019F86C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019F870: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8019F874: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F878: lui         $a1, 0x3C23
    ctx->r5 = S32(0X3C23 << 16);
    // 0x8019F87C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8019F880: ori         $a1, $a1, 0xD70A
    ctx->r5 = ctx->r5 | 0XD70A;
    // 0x8019F884: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x8019F888: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019F88C: bc1f        L_8019F8C4
    if (!c1cs) {
        // 0x8019F890: lui         $a3, 0x3AD1
        ctx->r7 = S32(0X3AD1 << 16);
            goto L_8019F8C4;
    }
    // 0x8019F890: lui         $a3, 0x3AD1
    ctx->r7 = S32(0X3AD1 << 16);
    // 0x8019F894: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019F898: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F89C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8019F8A0: lui         $a3, 0x3AEB
    ctx->r7 = S32(0X3AEB << 16);
    // 0x8019F8A4: ori         $a3, $a3, 0xEDFA
    ctx->r7 = ctx->r7 | 0XEDFA;
    // 0x8019F8A8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8019F8AC: addiu       $a0, $a0, 0x7A50
    ctx->r4 = ADD32(ctx->r4, 0X7A50);
    // 0x8019F8B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8019F8B4: jal         0x8009BC2C
    // 0x8019F8B8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_38;
    // 0x8019F8B8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_38:
    // 0x8019F8BC: b           L_8019F8D4
    // 0x8019F8C0: nop

        goto L_8019F8D4;
    // 0x8019F8C0: nop

L_8019F8C4:
    // 0x8019F8C4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019F8C8: ori         $a3, $a3, 0xB717
    ctx->r7 = ctx->r7 | 0XB717;
    // 0x8019F8CC: jal         0x8009BC2C
    // 0x8019F8D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_39;
    // 0x8019F8D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_39:
L_8019F8D4:
    // 0x8019F8D4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F8D8: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8019F8DC: slti        $at, $v1, 0x5FB
    ctx->r1 = SIGNED(ctx->r3) < 0X5FB ? 1 : 0;
    // 0x8019F8E0: bne         $at, $zero, L_8019F964
    if (ctx->r1 != 0) {
        // 0x8019F8E4: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8019F964;
    }
    // 0x8019F8E4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8019F8E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F8EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019F8F0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8019F8F4: sw          $v0, -0x7CA8($at)
    MEM_W(-0X7CA8, ctx->r1) = ctx->r2;
    // 0x8019F8F8: addiu       $a1, $a1, -0x7CB0
    ctx->r5 = ADD32(ctx->r5, -0X7CB0);
    // 0x8019F8FC: addiu       $a0, $a0, -0x7CAC
    ctx->r4 = ADD32(ctx->r4, -0X7CAC);
    // 0x8019F900: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8019F904: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x8019F908: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8019F90C: lw          $t1, -0x7CC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7CC0);
    // 0x8019F910: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F914: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x8019F918: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F91C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8019F920: bne         $v0, $t1, L_8019F964
    if (ctx->r2 != ctx->r9) {
        // 0x8019F924: sw          $t9, -0x7CA4($at)
        MEM_W(-0X7CA4, ctx->r1) = ctx->r25;
            goto L_8019F964;
    }
    // 0x8019F924: sw          $t9, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r25;
    // 0x8019F928: jal         0x8001DBD0
    // 0x8019F92C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    Audio_FadeOutAll(rdram, ctx);
        goto after_40;
    // 0x8019F92C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_40:
    // 0x8019F930: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8019F934: sw          $t2, 0x1C8($s1)
    MEM_W(0X1C8, ctx->r17) = ctx->r10;
    // 0x8019F938: sw          $zero, 0x1F8($s1)
    MEM_W(0X1F8, ctx->r17) = 0;
    // 0x8019F93C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x8019F940: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019F944: sw          $t3, -0x7C84($at)
    MEM_W(-0X7C84, ctx->r1) = ctx->r11;
    // 0x8019F948: jal         0x800A3F50
    // 0x8019F94C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    Play_CheckMedalStatus(rdram, ctx);
        goto after_41;
    // 0x8019F94C: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_41:
    // 0x8019F950: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8019F954: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8019F958: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F95C: lw          $v1, 0x7A80($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7A80);
    // 0x8019F960: sb          $t4, 0x3185($at)
    MEM_B(0X3185, ctx->r1) = ctx->r12;
L_8019F964:
    // 0x8019F964: slti        $at, $v1, 0x369
    ctx->r1 = SIGNED(ctx->r3) < 0X369 ? 1 : 0;
    // 0x8019F968: bne         $at, $zero, L_8019F9B8
    if (ctx->r1 != 0) {
        // 0x8019F96C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8019F9B8;
    }
    // 0x8019F96C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8019F970: slti        $at, $v1, 0x48C
    ctx->r1 = SIGNED(ctx->r3) < 0X48C ? 1 : 0;
    // 0x8019F974: bne         $at, $zero, L_8019F99C
    if (ctx->r1 != 0) {
        // 0x8019F978: addiu       $t5, $v1, -0x553
        ctx->r13 = ADD32(ctx->r3, -0X553);
            goto L_8019F99C;
    }
    // 0x8019F978: addiu       $t5, $v1, -0x553
    ctx->r13 = ADD32(ctx->r3, -0X553);
    // 0x8019F97C: sltiu       $at, $t5, 0x4E
    ctx->r1 = ctx->r13 < 0X4E ? 1 : 0;
    // 0x8019F980: beq         $at, $zero, L_8019FC9C
    if (ctx->r1 == 0) {
        // 0x8019F984: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8019FC9C;
    }
    // 0x8019F984: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8019F988: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019F98C: addu        $at, $at, $t5
    gpr jr_addend_8019F994 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8019F990: lw          $t5, 0x77EC($at)
    ctx->r13 = ADD32(ctx->r1, 0X77EC);
    // 0x8019F994: jr          $t5
    // 0x8019F998: nop

    switch (jr_addend_8019F994 >> 2) {
        case 0: goto L_8019FBDC; break;
        case 1: goto L_8019FC9C; break;
        case 2: goto L_8019FC9C; break;
        case 3: goto L_8019FC9C; break;
        case 4: goto L_8019FC9C; break;
        case 5: goto L_8019FC9C; break;
        case 6: goto L_8019FC9C; break;
        case 7: goto L_8019FC9C; break;
        case 8: goto L_8019FC9C; break;
        case 9: goto L_8019FC9C; break;
        case 10: goto L_8019FC9C; break;
        case 11: goto L_8019FC9C; break;
        case 12: goto L_8019FC9C; break;
        case 13: goto L_8019FC9C; break;
        case 14: goto L_8019FC9C; break;
        case 15: goto L_8019FC9C; break;
        case 16: goto L_8019FC9C; break;
        case 17: goto L_8019FC40; break;
        case 18: goto L_8019FC9C; break;
        case 19: goto L_8019FC9C; break;
        case 20: goto L_8019FC9C; break;
        case 21: goto L_8019FC9C; break;
        case 22: goto L_8019FC9C; break;
        case 23: goto L_8019FC9C; break;
        case 24: goto L_8019FC9C; break;
        case 25: goto L_8019FC9C; break;
        case 26: goto L_8019FC9C; break;
        case 27: goto L_8019FC9C; break;
        case 28: goto L_8019FC9C; break;
        case 29: goto L_8019FC9C; break;
        case 30: goto L_8019FC9C; break;
        case 31: goto L_8019FC9C; break;
        case 32: goto L_8019FC9C; break;
        case 33: goto L_8019FC9C; break;
        case 34: goto L_8019FC9C; break;
        case 35: goto L_8019FC9C; break;
        case 36: goto L_8019FC9C; break;
        case 37: goto L_8019FC60; break;
        case 38: goto L_8019FC9C; break;
        case 39: goto L_8019FC9C; break;
        case 40: goto L_8019FC9C; break;
        case 41: goto L_8019FC9C; break;
        case 42: goto L_8019FC9C; break;
        case 43: goto L_8019FC9C; break;
        case 44: goto L_8019FC9C; break;
        case 45: goto L_8019FC9C; break;
        case 46: goto L_8019FC9C; break;
        case 47: goto L_8019FC9C; break;
        case 48: goto L_8019FC9C; break;
        case 49: goto L_8019FC9C; break;
        case 50: goto L_8019FC9C; break;
        case 51: goto L_8019FC9C; break;
        case 52: goto L_8019FC9C; break;
        case 53: goto L_8019FC9C; break;
        case 54: goto L_8019FC9C; break;
        case 55: goto L_8019FC9C; break;
        case 56: goto L_8019FC9C; break;
        case 57: goto L_8019FC80; break;
        case 58: goto L_8019FC9C; break;
        case 59: goto L_8019FC9C; break;
        case 60: goto L_8019FC9C; break;
        case 61: goto L_8019FC9C; break;
        case 62: goto L_8019FC9C; break;
        case 63: goto L_8019FC9C; break;
        case 64: goto L_8019FC9C; break;
        case 65: goto L_8019FC9C; break;
        case 66: goto L_8019FC9C; break;
        case 67: goto L_8019FC9C; break;
        case 68: goto L_8019FC9C; break;
        case 69: goto L_8019FC9C; break;
        case 70: goto L_8019FC9C; break;
        case 71: goto L_8019FC9C; break;
        case 72: goto L_8019FC9C; break;
        case 73: goto L_8019FC9C; break;
        case 74: goto L_8019FC9C; break;
        case 75: goto L_8019FC9C; break;
        case 76: goto L_8019FC9C; break;
        case 77: goto L_8019FBE8; break;
        default: switch_error(__func__, 0x8019F994, 0x801A77EC);
    }
    // 0x8019F998: nop

L_8019F99C:
    // 0x8019F99C: addiu       $at, $zero, 0x3FA
    ctx->r1 = ADD32(0, 0X3FA);
    // 0x8019F9A0: beq         $v0, $at, L_8019FB50
    if (ctx->r2 == ctx->r1) {
        // 0x8019F9A4: addiu       $at, $zero, 0x48B
        ctx->r1 = ADD32(0, 0X48B);
            goto L_8019FB50;
    }
    // 0x8019F9A4: addiu       $at, $zero, 0x48B
    ctx->r1 = ADD32(0, 0X48B);
    // 0x8019F9A8: beq         $v0, $at, L_8019FBD0
    if (ctx->r2 == ctx->r1) {
        // 0x8019F9AC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8019FBD0;
    }
    // 0x8019F9AC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8019F9B0: b           L_8019FCA0
    // 0x8019F9B4: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019F9B4: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019F9B8:
    // 0x8019F9B8: addiu       $at, $zero, 0x208
    ctx->r1 = ADD32(0, 0X208);
    // 0x8019F9BC: beq         $v0, $at, L_8019F9EC
    if (ctx->r2 == ctx->r1) {
        // 0x8019F9C0: lui         $t6, 0x8016
        ctx->r14 = S32(0X8016 << 16);
            goto L_8019F9EC;
    }
    // 0x8019F9C0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019F9C4: addiu       $at, $zero, 0x244
    ctx->r1 = ADD32(0, 0X244);
    // 0x8019F9C8: beq         $v0, $at, L_8019FA14
    if (ctx->r2 == ctx->r1) {
        // 0x8019F9CC: lui         $t9, 0x8016
        ctx->r25 = S32(0X8016 << 16);
            goto L_8019FA14;
    }
    // 0x8019F9CC: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8019F9D0: addiu       $at, $zero, 0x2D5
    ctx->r1 = ADD32(0, 0X2D5);
    // 0x8019F9D4: beq         $v0, $at, L_8019FA50
    if (ctx->r2 == ctx->r1) {
        // 0x8019F9D8: addiu       $at, $zero, 0x368
        ctx->r1 = ADD32(0, 0X368);
            goto L_8019FA50;
    }
    // 0x8019F9D8: addiu       $at, $zero, 0x368
    ctx->r1 = ADD32(0, 0X368);
    // 0x8019F9DC: beq         $v0, $at, L_8019FAD0
    if (ctx->r2 == ctx->r1) {
        // 0x8019F9E0: nop
    
            goto L_8019FAD0;
    }
    // 0x8019F9E0: nop

    // 0x8019F9E4: b           L_8019FCA0
    // 0x8019F9E8: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019F9E8: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019F9EC:
    // 0x8019F9EC: lw          $t6, 0x1A98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A98);
    // 0x8019F9F0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019F9F4: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8019F9F8: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x8019F9FC: bne         $at, $zero, L_8019FA08
    if (ctx->r1 != 0) {
        // 0x8019FA00: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8019FA08;
    }
    // 0x8019FA00: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019FA04: sb          $t7, 0x7930($at)
    MEM_B(0X7930, ctx->r1) = ctx->r15;
L_8019FA08:
    // 0x8019FA08: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019FA0C: b           L_8019FC9C
    // 0x8019FA10: sw          $t8, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r24;
        goto L_8019FC9C;
    // 0x8019FA10: sw          $t8, 0x7840($at)
    MEM_W(0X7840, ctx->r1) = ctx->r24;
L_8019FA14:
    // 0x8019FA14: lw          $t9, 0x1A98($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1A98);
    // 0x8019FA18: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FA1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019FA20: slti        $at, $t9, 0x64
    ctx->r1 = SIGNED(ctx->r25) < 0X64 ? 1 : 0;
    // 0x8019FA24: bne         $at, $zero, L_8019FA40
    if (ctx->r1 != 0) {
        // 0x8019FA28: addiu       $a0, $a0, 0x33C0
        ctx->r4 = ADD32(ctx->r4, 0X33C0);
            goto L_8019FA40;
    }
    // 0x8019FA28: addiu       $a0, $a0, 0x33C0
    ctx->r4 = ADD32(ctx->r4, 0X33C0);
    // 0x8019FA2C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FA30: jal         0x800BA808
    // 0x8019FA34: addiu       $a0, $a0, 0xA50
    ctx->r4 = ADD32(ctx->r4, 0XA50);
    Radio_PlayMessage(rdram, ctx);
        goto after_42;
    // 0x8019FA34: addiu       $a0, $a0, 0xA50
    ctx->r4 = ADD32(ctx->r4, 0XA50);
    after_42:
    // 0x8019FA38: b           L_8019FCA0
    // 0x8019FA3C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FA3C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FA40:
    // 0x8019FA40: jal         0x800BA808
    // 0x8019FA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Radio_PlayMessage(rdram, ctx);
        goto after_43;
    // 0x8019FA44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x8019FA48: b           L_8019FCA0
    // 0x8019FA4C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FA4C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FA50:
    // 0x8019FA50: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019FA54: lw          $v0, 0x78B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B8);
    // 0x8019FA58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019FA5C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FA60: beq         $v0, $at, L_8019FA88
    if (ctx->r2 == ctx->r1) {
        // 0x8019FA64: addiu       $a0, $a0, 0x4A4C
        ctx->r4 = ADD32(ctx->r4, 0X4A4C);
            goto L_8019FA88;
    }
    // 0x8019FA64: addiu       $a0, $a0, 0x4A4C
    ctx->r4 = ADD32(ctx->r4, 0X4A4C);
    // 0x8019FA68: bne         $v0, $zero, L_8019FA98
    if (ctx->r2 != 0) {
        // 0x8019FA6C: lui         $t1, 0x8016
        ctx->r9 = S32(0X8016 << 16);
            goto L_8019FA98;
    }
    // 0x8019FA6C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8019FA70: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FA74: addiu       $a0, $a0, 0x4C68
    ctx->r4 = ADD32(ctx->r4, 0X4C68);
    // 0x8019FA78: jal         0x800BA808
    // 0x8019FA7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_44;
    // 0x8019FA7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_44:
    // 0x8019FA80: b           L_8019FCA0
    // 0x8019FA84: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FA84: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FA88:
    // 0x8019FA88: jal         0x800BA808
    // 0x8019FA8C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_45;
    // 0x8019FA8C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_45:
    // 0x8019FA90: b           L_8019FCA0
    // 0x8019FA94: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FA94: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FA98:
    // 0x8019FA98: lw          $t1, 0x1A98($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1A98);
    // 0x8019FA9C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FAA0: addiu       $a0, $a0, -0x4878
    ctx->r4 = ADD32(ctx->r4, -0X4878);
    // 0x8019FAA4: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x8019FAA8: bne         $at, $zero, L_8019FAC0
    if (ctx->r1 != 0) {
        // 0x8019FAAC: nop
    
            goto L_8019FAC0;
    }
    // 0x8019FAAC: nop

    // 0x8019FAB0: jal         0x800BA808
    // 0x8019FAB4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_46;
    // 0x8019FAB4: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_46:
    // 0x8019FAB8: b           L_8019FCA0
    // 0x8019FABC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FABC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FAC0:
    // 0x8019FAC0: jal         0x80048AC0
    // 0x8019FAC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Cutscene_AllAircraftReport(rdram, ctx);
        goto after_47;
    // 0x8019FAC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_47:
    // 0x8019FAC8: b           L_8019FCA0
    // 0x8019FACC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FACC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FAD0:
    // 0x8019FAD0: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019FAD4: lw          $v0, 0x78BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78BC);
    // 0x8019FAD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019FADC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FAE0: beq         $v0, $at, L_8019FB08
    if (ctx->r2 == ctx->r1) {
        // 0x8019FAE4: addiu       $a0, $a0, 0x4A04
        ctx->r4 = ADD32(ctx->r4, 0X4A04);
            goto L_8019FB08;
    }
    // 0x8019FAE4: addiu       $a0, $a0, 0x4A04
    ctx->r4 = ADD32(ctx->r4, 0X4A04);
    // 0x8019FAE8: bne         $v0, $zero, L_8019FB18
    if (ctx->r2 != 0) {
        // 0x8019FAEC: lui         $t2, 0x8016
        ctx->r10 = S32(0X8016 << 16);
            goto L_8019FB18;
    }
    // 0x8019FAEC: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8019FAF0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FAF4: addiu       $a0, $a0, 0x4C1C
    ctx->r4 = ADD32(ctx->r4, 0X4C1C);
    // 0x8019FAF8: jal         0x800BA808
    // 0x8019FAFC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_48;
    // 0x8019FAFC: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_48:
    // 0x8019FB00: b           L_8019FCA0
    // 0x8019FB04: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FB04: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FB08:
    // 0x8019FB08: jal         0x800BA808
    // 0x8019FB0C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_49;
    // 0x8019FB0C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_49:
    // 0x8019FB10: b           L_8019FCA0
    // 0x8019FB14: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FB14: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FB18:
    // 0x8019FB18: lw          $t2, 0x1A98($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1A98);
    // 0x8019FB1C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FB20: addiu       $a0, $a0, 0x3CA8
    ctx->r4 = ADD32(ctx->r4, 0X3CA8);
    // 0x8019FB24: slti        $at, $t2, 0x64
    ctx->r1 = SIGNED(ctx->r10) < 0X64 ? 1 : 0;
    // 0x8019FB28: bne         $at, $zero, L_8019FB40
    if (ctx->r1 != 0) {
        // 0x8019FB2C: nop
    
            goto L_8019FB40;
    }
    // 0x8019FB2C: nop

    // 0x8019FB30: jal         0x800BA808
    // 0x8019FB34: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_50;
    // 0x8019FB34: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_50:
    // 0x8019FB38: b           L_8019FCA0
    // 0x8019FB3C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FB3C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FB40:
    // 0x8019FB40: jal         0x80048AC0
    // 0x8019FB44: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    Cutscene_AllAircraftReport(rdram, ctx);
        goto after_51;
    // 0x8019FB44: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_51:
    // 0x8019FB48: b           L_8019FCA0
    // 0x8019FB4C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FB4C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FB50:
    // 0x8019FB50: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019FB54: lw          $v0, 0x78B4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X78B4);
    // 0x8019FB58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8019FB5C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FB60: beq         $v0, $at, L_8019FB88
    if (ctx->r2 == ctx->r1) {
        // 0x8019FB64: addiu       $a0, $a0, 0x49B8
        ctx->r4 = ADD32(ctx->r4, 0X49B8);
            goto L_8019FB88;
    }
    // 0x8019FB64: addiu       $a0, $a0, 0x49B8
    ctx->r4 = ADD32(ctx->r4, 0X49B8);
    // 0x8019FB68: bne         $v0, $zero, L_8019FB98
    if (ctx->r2 != 0) {
        // 0x8019FB6C: lui         $t3, 0x8016
        ctx->r11 = S32(0X8016 << 16);
            goto L_8019FB98;
    }
    // 0x8019FB6C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8019FB70: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FB74: addiu       $a0, $a0, 0x4B7C
    ctx->r4 = ADD32(ctx->r4, 0X4B7C);
    // 0x8019FB78: jal         0x800BA808
    // 0x8019FB7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_52;
    // 0x8019FB7C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_52:
    // 0x8019FB80: b           L_8019FCA0
    // 0x8019FB84: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FB84: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FB88:
    // 0x8019FB88: jal         0x800BA808
    // 0x8019FB8C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    Radio_PlayMessage(rdram, ctx);
        goto after_53;
    // 0x8019FB8C: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    after_53:
    // 0x8019FB90: b           L_8019FCA0
    // 0x8019FB94: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FB94: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FB98:
    // 0x8019FB98: lw          $t3, 0x1A98($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1A98);
    // 0x8019FB9C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019FBA0: addiu       $a0, $a0, 0x3CF0
    ctx->r4 = ADD32(ctx->r4, 0X3CF0);
    // 0x8019FBA4: slti        $at, $t3, 0x64
    ctx->r1 = SIGNED(ctx->r11) < 0X64 ? 1 : 0;
    // 0x8019FBA8: bne         $at, $zero, L_8019FBC0
    if (ctx->r1 != 0) {
        // 0x8019FBAC: nop
    
            goto L_8019FBC0;
    }
    // 0x8019FBAC: nop

    // 0x8019FBB0: jal         0x800BA808
    // 0x8019FBB4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_54;
    // 0x8019FBB4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_54:
    // 0x8019FBB8: b           L_8019FCA0
    // 0x8019FBBC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FBBC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FBC0:
    // 0x8019FBC0: jal         0x80048AC0
    // 0x8019FBC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Cutscene_AllAircraftReport(rdram, ctx);
        goto after_55;
    // 0x8019FBC4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_55:
    // 0x8019FBC8: b           L_8019FCA0
    // 0x8019FBCC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FBCC: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FBD0:
    // 0x8019FBD0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019FBD4: b           L_8019FC9C
    // 0x8019FBD8: sb          $t4, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r12;
        goto L_8019FC9C;
    // 0x8019FBD8: sb          $t4, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = ctx->r12;
L_8019FBDC:
    // 0x8019FBDC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019FBE0: b           L_8019FC9C
    // 0x8019FBE4: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
        goto L_8019FC9C;
    // 0x8019FBE4: sb          $zero, 0x7830($at)
    MEM_B(0X7830, ctx->r1) = 0;
L_8019FBE8:
    // 0x8019FBE8: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x8019FBEC: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8019FBF0: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019FBF4: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019FBF8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8019FBFC: addiu       $a1, $s1, 0x460
    ctx->r5 = ADD32(ctx->r17, 0X460);
    // 0x8019FC00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019FC04: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8019FC08: jal         0x80019218
    // 0x8019FC0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    Audio_PlaySfx(rdram, ctx);
        goto after_56;
    // 0x8019FC0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_56:
    // 0x8019FC10: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019FC14: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019FC18: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x8019FC1C: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x8019FC20: swc1        $f0, 0x194($s1)
    MEM_W(0X194, ctx->r17) = ctx->f0.u32l;
    // 0x8019FC24: jal         0x800182F4
    // 0x8019FC28: swc1        $f0, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f0.u32l;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_57;
    // 0x8019FC28: swc1        $f0, 0x190($s1)
    MEM_W(0X190, ctx->r17) = ctx->f0.u32l;
    after_57:
    // 0x8019FC2C: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x8019FC30: jal         0x800182F4
    // 0x8019FC34: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_58;
    // 0x8019FC34: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_58:
    // 0x8019FC38: b           L_8019FCA0
    // 0x8019FC3C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
        goto L_8019FCA0;
    // 0x8019FC3C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FC40:
    // 0x8019FC40: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019FC44: lw          $t6, 0x78BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78BC);
    // 0x8019FC48: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8019FC4C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019FC50: blezl       $t6, L_8019FCA0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8019FC54: lwc1        $f16, 0x114($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
            goto L_8019FCA0;
    }
    goto skip_3;
    // 0x8019FC54: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
    skip_3:
    // 0x8019FC58: b           L_8019FC9C
    // 0x8019FC5C: sh          $t7, 0x4098($at)
    MEM_H(0X4098, ctx->r1) = ctx->r15;
        goto L_8019FC9C;
    // 0x8019FC5C: sh          $t7, 0x4098($at)
    MEM_H(0X4098, ctx->r1) = ctx->r15;
L_8019FC60:
    // 0x8019FC60: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019FC64: lw          $t8, 0x78B8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78B8);
    // 0x8019FC68: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8019FC6C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019FC70: blezl       $t8, L_8019FCA0
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8019FC74: lwc1        $f16, 0x114($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
            goto L_8019FCA0;
    }
    goto skip_4;
    // 0x8019FC74: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
    skip_4:
    // 0x8019FC78: b           L_8019FC9C
    // 0x8019FC7C: sh          $t9, 0x438C($at)
    MEM_H(0X438C, ctx->r1) = ctx->r25;
        goto L_8019FC9C;
    // 0x8019FC7C: sh          $t9, 0x438C($at)
    MEM_H(0X438C, ctx->r1) = ctx->r25;
L_8019FC80:
    // 0x8019FC80: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8019FC84: lw          $t1, 0x78B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78B4);
    // 0x8019FC88: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8019FC8C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019FC90: blezl       $t1, L_8019FCA0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8019FC94: lwc1        $f16, 0x114($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
            goto L_8019FCA0;
    }
    goto skip_5;
    // 0x8019FC94: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
    skip_5:
    // 0x8019FC98: sh          $t2, 0x4680($at)
    MEM_H(0X4680, ctx->r1) = ctx->r10;
L_8019FC9C:
    // 0x8019FC9C: lwc1        $f16, 0x114($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X114);
L_8019FCA0:
    // 0x8019FCA0: lwc1        $f18, 0xE8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x8019FCA4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019FCA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019FCAC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019FCB0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019FCB4: lwc1        $f10, 0x7924($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7924);
    // 0x8019FCB8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019FCBC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019FCC0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019FCC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019FCC8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019FCCC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019FCD0: jal         0x80005E90
    // 0x8019FCD4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_59;
    // 0x8019FCD4: nop

    after_59:
    // 0x8019FCD8: lwc1        $f18, 0x120($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X120);
    // 0x8019FCDC: lwc1        $f4, 0xE4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x8019FCE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019FCE4: lwc1        $f8, 0x7928($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7928);
    // 0x8019FCE8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8019FCEC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019FCF0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019FCF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019FCF8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019FCFC: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8019FD00: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8019FD04: jal         0x80005D44
    // 0x8019FD08: nop

    Matrix_RotateX(rdram, ctx);
        goto after_60;
    // 0x8019FD08: nop

    after_60:
    // 0x8019FD0C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019FD10: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019FD14: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019FD18: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8019FD1C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8019FD20: lwc1        $f18, 0xD0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XD0);
    // 0x8019FD24: addiu       $a1, $sp, 0x60
    ctx->r5 = ADD32(ctx->r29, 0X60);
    // 0x8019FD28: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8019FD2C: jal         0x80006A20
    // 0x8019FD30: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_61;
    // 0x8019FD30: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    after_61:
    // 0x8019FD34: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019FD38: lwc1        $f10, 0x74($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X74);
    // 0x8019FD3C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019FD40: swc1        $f4, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->f4.u32l;
    // 0x8019FD44: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019FD48: lwc1        $f16, 0xC0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC0);
    // 0x8019FD4C: lwc1        $f4, 0x78($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X78);
    // 0x8019FD50: swc1        $f6, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = ctx->f6.u32l;
    // 0x8019FD54: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019FD58: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019FD5C: lwc1        $f16, 0xC8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC8);
    // 0x8019FD60: lwc1        $f10, 0x7C($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x8019FD64: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    // 0x8019FD68: lwc1        $f6, 0xC4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC4);
    // 0x8019FD6C: swc1        $f18, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f18.u32l;
    // 0x8019FD70: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019FD74: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019FD78: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8019FD7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019FD80: swc1        $f18, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f18.u32l;
    // 0x8019FD84: lwc1        $f4, 0x7C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x8019FD88: lwc1        $f6, 0xEC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XEC);
    // 0x8019FD8C: swc1        $f8, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f8.u32l;
    // 0x8019FD90: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8019FD94: swc1        $f4, 0x138($s1)
    MEM_W(0X138, ctx->r17) = ctx->f4.u32l;
    // 0x8019FD98: swc1        $f6, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f6.u32l;
    // 0x8019FD9C: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019FDA0: lw          $a1, 0x7978($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7978);
    // 0x8019FDA4: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8019FDA8: addiu       $a0, $s1, 0x40
    ctx->r4 = ADD32(ctx->r17, 0X40);
    // 0x8019FDAC: jal         0x8009BC2C
    // 0x8019FDB0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_62;
    // 0x8019FDB0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_62:
    // 0x8019FDB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019FDB8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019FDBC: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019FDC0: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8019FDC4: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8019FDC8: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019FDCC: lw          $a1, 0x7980($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7980);
    // 0x8019FDD0: addiu       $a0, $s1, 0x44
    ctx->r4 = ADD32(ctx->r17, 0X44);
    // 0x8019FDD4: jal         0x8009BC2C
    // 0x8019FDD8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_63;
    // 0x8019FDD8: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_63:
    // 0x8019FDDC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019FDE0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019FDE4: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019FDE8: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8019FDEC: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8019FDF0: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019FDF4: lw          $a1, 0x7988($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7988);
    // 0x8019FDF8: addiu       $a0, $s1, 0x48
    ctx->r4 = ADD32(ctx->r17, 0X48);
    // 0x8019FDFC: jal         0x8009BC2C
    // 0x8019FE00: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_64;
    // 0x8019FE00: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_64:
    // 0x8019FE04: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8019FE08: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019FE0C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019FE10: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8019FE14: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8019FE18: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019FE1C: lw          $a1, 0x79A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79A0);
    // 0x8019FE20: addiu       $a0, $s1, 0x4C
    ctx->r4 = ADD32(ctx->r17, 0X4C);
    // 0x8019FE24: jal         0x8009BC2C
    // 0x8019FE28: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_65;
    // 0x8019FE28: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_65:
    // 0x8019FE2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019FE30: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019FE34: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019FE38: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8019FE3C: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8019FE40: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019FE44: lw          $a1, 0x79B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79B8);
    // 0x8019FE48: addiu       $a0, $s1, 0x50
    ctx->r4 = ADD32(ctx->r17, 0X50);
    // 0x8019FE4C: jal         0x8009BC2C
    // 0x8019FE50: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_66;
    // 0x8019FE50: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_66:
    // 0x8019FE54: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019FE58: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019FE5C: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019FE60: lui         $a3, 0x4743
    ctx->r7 = S32(0X4743 << 16);
    // 0x8019FE64: ori         $a3, $a3, 0x5000
    ctx->r7 = ctx->r7 | 0X5000;
    // 0x8019FE68: lw          $a2, 0x7A48($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7A48);
    // 0x8019FE6C: lw          $a1, 0x79C0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X79C0);
    // 0x8019FE70: addiu       $a0, $s1, 0x54
    ctx->r4 = ADD32(ctx->r17, 0X54);
    // 0x8019FE74: jal         0x8009BC2C
    // 0x8019FE78: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_67;
    // 0x8019FE78: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_67:
    // 0x8019FE7C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8019FE80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019FE84: lwc1        $f8, 0x88($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X88);
    // 0x8019FE88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019FE8C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019FE90: swc1        $f16, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->f16.u32l;
    // 0x8019FE94: lwc1        $f4, 0x792C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X792C);
    // 0x8019FE98: lwc1        $f18, 0x88($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X88);
    // 0x8019FE9C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8019FEA0: jal         0x80023090
    // 0x8019FEA4: nop

    __sinf_recomp(rdram, ctx);
        goto after_68;
    // 0x8019FEA4: nop

    after_68:
    // 0x8019FEA8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019FEAC: lwc1        $f8, 0x7930($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7930);
    // 0x8019FEB0: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8019FEB4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8019FEB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019FEBC: lwc1        $f16, 0xF4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x8019FEC0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019FEC4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019FEC8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019FECC: swc1        $f4, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f4.u32l;
    // 0x8019FED0: swc1        $f10, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f10.u32l;
    // 0x8019FED4: lwc1        $f8, 0x7934($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7934);
    // 0x8019FED8: lwc1        $f6, 0xF4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XF4);
    // 0x8019FEDC: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019FEE0: jal         0x80023090
    // 0x8019FEE4: nop

    __sinf_recomp(rdram, ctx);
        goto after_69;
    // 0x8019FEE4: nop

    after_69:
    // 0x8019FEE8: swc1        $f0, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f0.u32l;
    // 0x8019FEEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019FEF0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8019FEF4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8019FEF8: jr          $ra
    // 0x8019FEFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8019FEFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Andross_80189214(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80189218: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018921C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80189220: lw          $a1, -0x7D80($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D80);
    // 0x80189224: jal         0x800A6148
    // 0x80189228: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Play_ClearObjectData(rdram, ctx);
        goto after_0;
    // 0x80189228: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8018922C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80189230: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80189234: addiu       $v0, $v0, -0x7D58
    ctx->r2 = ADD32(ctx->r2, -0X7D58);
    // 0x80189238: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018923C: addiu       $a0, $zero, 0x44C0
    ctx->r4 = ADD32(0, 0X44C0);
L_80189240:
    // 0x80189240: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80189244: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80189248: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8018924C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80189250: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80189254: sb          $zero, 0x58($t9)
    MEM_B(0X58, ctx->r25) = 0;
    // 0x80189258: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8018925C: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80189260: sb          $zero, 0xB0($t1)
    MEM_B(0XB0, ctx->r9) = 0;
    // 0x80189264: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80189268: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8018926C: addiu       $v1, $v1, 0x160
    ctx->r3 = ADD32(ctx->r3, 0X160);
    // 0x80189270: bne         $v1, $a0, L_80189240
    if (ctx->r3 != ctx->r4) {
        // 0x80189274: sb          $zero, 0x108($t3)
        MEM_B(0X108, ctx->r11) = 0;
            goto L_80189240;
    }
    // 0x80189274: sb          $zero, 0x108($t3)
    MEM_B(0X108, ctx->r11) = 0;
    // 0x80189278: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8018927C: lwc1        $f0, 0x6BFC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6BFC);
    // 0x80189280: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80189284: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80189288: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018928C: sw          $zero, 0x7880($at)
    MEM_W(0X7880, ctx->r1) = 0;
    // 0x80189290: sw          $zero, 0x204($a1)
    MEM_W(0X204, ctx->r5) = 0;
    // 0x80189294: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80189298: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018929C: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x801892A0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801892A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801892A8: swc1        $f2, 0x74($t4)
    MEM_W(0X74, ctx->r12) = ctx->f2.u32l;
    // 0x801892AC: lwc1        $f8, 0x78($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X78);
    // 0x801892B0: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x801892B4: lwc1        $f4, 0x74($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X74);
    // 0x801892B8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801892BC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801892C0: swc1        $f6, 0x54($a1)
    MEM_W(0X54, ctx->r5) = ctx->f6.u32l;
    // 0x801892C4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801892C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801892CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801892D0: swc1        $f0, 0x148($a1)
    MEM_W(0X148, ctx->r5) = ctx->f0.u32l;
    // 0x801892D4: swc1        $f0, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->f0.u32l;
    // 0x801892D8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801892DC: swc1        $f12, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f12.u32l;
    // 0x801892E0: swc1        $f6, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f6.u32l;
    // 0x801892E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801892E8: swc1        $f18, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f18.u32l;
    // 0x801892EC: sw          $zero, 0x7DC8($at)
    MEM_W(0X7DC8, ctx->r1) = 0;
    // 0x801892F0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801892F4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801892F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801892FC: swc1        $f2, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->f2.u32l;
    // 0x80189300: swc1        $f2, 0x50($a1)
    MEM_W(0X50, ctx->r5) = ctx->f2.u32l;
    // 0x80189304: swc1        $f2, 0x114($a1)
    MEM_W(0X114, ctx->r5) = ctx->f2.u32l;
    // 0x80189308: swc1        $f2, 0x144($a1)
    MEM_W(0X144, ctx->r5) = ctx->f2.u32l;
    // 0x8018930C: swc1        $f2, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f2.u32l;
    // 0x80189310: lwc1        $f0, 0x144($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X144);
    // 0x80189314: swc1        $f12, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f12.u32l;
    // 0x80189318: swc1        $f12, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f12.u32l;
    // 0x8018931C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80189320: swc1        $f0, 0x138($a1)
    MEM_W(0X138, ctx->r5) = ctx->f0.u32l;
    // 0x80189324: jal         0x800B56BC
    // 0x80189328: swc1        $f0, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->f0.u32l;
    Camera_UpdateArwingOnRails(rdram, ctx);
        goto after_1;
    // 0x80189328: swc1        $f0, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->f0.u32l;
    after_1:
    // 0x8018932C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80189330: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80189334: jr          $ra
    // 0x80189338: nop

    return;
    // 0x80189338: nop

;}
RECOMP_FUNC void SectorY_80198244(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198244: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80198248: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019824C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80198250: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80198254: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80198258: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019825C: sh          $t6, 0xB0($s0)
    MEM_H(0XB0, ctx->r16) = ctx->r14;
    // 0x80198260: jal         0x80004EB0
    // 0x80198264: sh          $t7, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r15;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80198264: sh          $t7, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r15;
    after_0:
    // 0x80198268: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8019826C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198270: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80198274: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80198278: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019827C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198280: lwc1        $f18, 0x7C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80198284: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80198288: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019828C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80198290: nop

    // 0x80198294: sh          $t9, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r25;
    // 0x80198298: lwc1        $f4, 0x74AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X74AC);
    // 0x8019829C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801982A0: jal         0x80023090
    // 0x801982A4: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x801982A4: nop

    after_1:
    // 0x801982A8: lwc1        $f6, 0x18C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x801982AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801982B0: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801982B4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801982B8: swc1        $f8, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f8.u32l;
    // 0x801982BC: lwc1        $f16, 0x74B0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X74B0);
    // 0x801982C0: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x801982C4: jal         0x80023250
    // 0x801982C8: nop

    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x801982C8: nop

    after_2:
    // 0x801982CC: lwc1        $f18, 0x18C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x801982D0: lwc1        $f2, 0x6C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x801982D4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801982D8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801982DC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801982E0: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x801982E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801982E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801982EC: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x801982F0: bc1f        L_80198300
    if (!c1cs) {
        // 0x801982F4: swc1        $f4, 0x10C($s0)
        MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
            goto L_80198300;
    }
    // 0x801982F4: swc1        $f4, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f4.u32l;
    // 0x801982F8: b           L_80198304
    // 0x801982FC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80198304;
    // 0x801982FC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80198300:
    // 0x80198300: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80198304:
    // 0x80198304: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80198308: nop

    // 0x8019830C: bc1fl       L_8019833C
    if (!c1cs) {
        // 0x80198310: lwc1        $f2, 0x74($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
            goto L_8019833C;
    }
    goto skip_0;
    // 0x80198310: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x80198314: lwc1        $f0, 0x74B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X74B4);
    // 0x80198318: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    // 0x8019831C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80198320: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80198324: jal         0x8009BC2C
    // 0x80198328: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80198328: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8019832C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80198330: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80198334: nop

    // 0x80198338: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
L_8019833C:
    // 0x8019833C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80198340: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80198344: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80198348: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x8019834C: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x80198350: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198354: bc1fl       L_80198368
    if (!c1cs) {
        // 0x80198358: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_80198368;
    }
    goto skip_1;
    // 0x80198358: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_1:
    // 0x8019835C: b           L_80198368
    // 0x80198360: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80198368;
    // 0x80198360: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80198364: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80198368:
    // 0x80198368: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8019836C: nop

    // 0x80198370: bc1fl       L_80198390
    if (!c1cs) {
        // 0x80198374: lui         $at, 0x4335
        ctx->r1 = S32(0X4335 << 16);
            goto L_80198390;
    }
    goto skip_2;
    // 0x80198374: lui         $at, 0x4335
    ctx->r1 = S32(0X4335 << 16);
    skip_2:
    // 0x80198378: lwc1        $f10, 0x74B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X74B8);
    // 0x8019837C: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    // 0x80198380: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x80198384: jal         0x8009BC2C
    // 0x80198388: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80198388: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x8019838C: lui         $at, 0x4335
    ctx->r1 = S32(0X4335 << 16);
L_80198390:
    // 0x80198390: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198394: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198398: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019839C: swc1        $f16, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f16.u32l;
    // 0x801983A0: lwc1        $f18, 0x74BC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X74BC);
    // 0x801983A4: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x801983A8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801983AC: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x801983B0: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x801983B4: swc1        $f18, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f18.u32l;
    // 0x801983B8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801983BC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801983C0: ori         $a0, $a0, 0x306C
    ctx->r4 = ctx->r4 | 0X306C;
    // 0x801983C4: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x801983C8: jal         0x80019218
    // 0x801983CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x801983CC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
    // 0x801983D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801983D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801983D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801983DC: jr          $ra
    // 0x801983E0: nop

    return;
    // 0x801983E0: nop

;}
RECOMP_FUNC void Andross_AndDoor_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193380: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80193384: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80193388: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8019338C: lw          $v0, 0x48($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X48);
    // 0x80193390: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193394: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80193398: beq         $v0, $zero, L_801933B0
    if (ctx->r2 == 0) {
        // 0x8019339C: nop
    
            goto L_801933B0;
    }
    // 0x8019339C: nop

    // 0x801933A0: beql        $v0, $at, L_80193420
    if (ctx->r2 == ctx->r1) {
        // 0x801933A4: lw          $t5, 0x44($a1)
        ctx->r13 = MEM_W(ctx->r5, 0X44);
            goto L_80193420;
    }
    goto skip_0;
    // 0x801933A4: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    skip_0:
    // 0x801933A8: b           L_801934D4
    // 0x801933AC: nop

        goto L_801934D4;
    // 0x801933AC: nop

L_801933B0:
    // 0x801933B0: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x801933B4: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x801933B8: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x801933BC: lwc1        $f6, 0x138($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X138);
    // 0x801933C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801933C4: lui         $v0, 0xC04
    ctx->r2 = S32(0XC04 << 16);
    // 0x801933C8: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801933CC: addiu       $v0, $v0, -0x753C
    ctx->r2 = ADD32(ctx->r2, -0X753C);
    // 0x801933D0: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x801933D4: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x801933D8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801933DC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801933E0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801933E4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x801933E8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801933EC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801933F0: bc1f        L_801934D4
    if (!c1cs) {
        // 0x801933F4: lui         $at, 0xFF
        ctx->r1 = S32(0XFF << 16);
            goto L_801934D4;
    }
    // 0x801933F4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801933F8: sw          $t7, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r15;
    // 0x801933FC: lw          $t1, 0x1FD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1FD0);
    // 0x80193400: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80193404: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x80193408: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019340C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80193410: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80193414: b           L_801934D4
    // 0x80193418: sw          $t4, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r12;
        goto L_801934D4;
    // 0x80193418: sw          $t4, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r12;
    // 0x8019341C: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
L_80193420:
    // 0x80193420: lui         $at, 0xC302
    ctx->r1 = S32(0XC302 << 16);
    // 0x80193424: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80193428: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8019342C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193430: lwc1        $f2, 0x7320($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7320);
    // 0x80193434: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80193438: lw          $t6, 0x28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28);
    // 0x8019343C: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x80193440: addiu       $a0, $a0, 0x4658
    ctx->r4 = ADD32(ctx->r4, 0X4658);
    // 0x80193444: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80193448: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8019344C: swc1        $f4, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f4.u32l;
    // 0x80193450: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x80193454: lw          $t8, 0x28($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X28);
    // 0x80193458: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8019345C: nop

    // 0x80193460: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80193464: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80193468: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8019346C: swc1        $f16, 0x44($t8)
    MEM_W(0X44, ctx->r24) = ctx->f16.u32l;
    // 0x80193470: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    // 0x80193474: lw          $t0, 0x28($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X28);
    // 0x80193478: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8019347C: nop

    // 0x80193480: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80193484: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80193488: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8019348C: swc1        $f8, 0x6C($t0)
    MEM_W(0X6C, ctx->r8) = ctx->f8.u32l;
    // 0x80193490: lw          $t1, 0x44($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X44);
    // 0x80193494: addiu       $t2, $t1, 0x2
    ctx->r10 = ADD32(ctx->r9, 0X2);
    // 0x80193498: sw          $t2, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r10;
    // 0x8019349C: jal         0x8009ACDC
    // 0x801934A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Animation_GetFrameCount(rdram, ctx);
        goto after_0;
    // 0x801934A0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x801934A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801934A8: lui         $a0, 0x601
    ctx->r4 = S32(0X601 << 16);
    // 0x801934AC: addiu       $a0, $a0, 0x4658
    ctx->r4 = ADD32(ctx->r4, 0X4658);
    // 0x801934B0: lw          $t3, 0x44($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X44);
    // 0x801934B4: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801934B8: bne         $at, $zero, L_801934D4
    if (ctx->r1 != 0) {
        // 0x801934BC: nop
    
            goto L_801934D4;
    }
    // 0x801934BC: nop

    // 0x801934C0: jal         0x8009ACDC
    // 0x801934C4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Animation_GetFrameCount(rdram, ctx);
        goto after_1;
    // 0x801934C4: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x801934C8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801934CC: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801934D0: sw          $t4, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r12;
L_801934D4:
    // 0x801934D4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801934D8: lwc1        $f10, 0x7F68($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7F68);
    // 0x801934DC: swc1        $f10, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f10.u32l;
    // 0x801934E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801934E4: jr          $ra
    // 0x801934E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801934E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void SectorY_8019EB80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019EB80: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8019EB84: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8019EB88: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8019EB8C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x8019EB90: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8019EB94: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8019EB98: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8019EB9C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8019EBA0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8019EBA4: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8019EBA8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8019EBAC: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x8019EBB0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8019EBB4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8019EBB8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8019EBBC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8019EBC0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8019EBC4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019EBC8: lw          $t6, 0x1A98($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A98);
    // 0x8019EBCC: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x8019EBD0: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x8019EBD4: slti        $at, $t6, 0x64
    ctx->r1 = SIGNED(ctx->r14) < 0X64 ? 1 : 0;
    // 0x8019EBD8: bne         $at, $zero, L_8019EBE8
    if (ctx->r1 != 0) {
        // 0x8019EBDC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8019EBE8;
    }
    // 0x8019EBDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8019EBE0: b           L_8019EBEC
    // 0x8019EBE4: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
        goto L_8019EBEC;
    // 0x8019EBE4: addiu       $s1, $zero, 0x9
    ctx->r17 = ADD32(0, 0X9);
L_8019EBE8:
    // 0x8019EBE8: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8019EBEC:
    // 0x8019EBEC: addiu       $a1, $zero, 0x71AC
    ctx->r5 = ADD32(0, 0X71AC);
    // 0x8019EBF0: jal         0x80004FC8
    // 0x8019EBF4: addiu       $a2, $zero, 0x263A
    ctx->r6 = ADD32(0, 0X263A);
    Rand_SetSeed(rdram, ctx);
        goto after_0;
    // 0x8019EBF4: addiu       $a2, $zero, 0x263A
    ctx->r6 = ADD32(0, 0X263A);
    after_0:
    // 0x8019EBF8: bltz        $s1, L_8019EE18
    if (SIGNED(ctx->r17) < 0) {
        // 0x8019EBFC: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8019EE18;
    }
    // 0x8019EBFC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8019EC00: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8019EC04: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8019EC08: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019EC0C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8019EC10: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x8019EC14: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8019EC18: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8019EC1C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019EC20: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019EC24: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8019EC28: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x8019EC2C: lui         $s3, 0x8018
    ctx->r19 = S32(0X8018 << 16);
    // 0x8019EC30: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8019EC34: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8019EC38: addiu       $s3, $s3, -0x7D80
    ctx->r19 = ADD32(ctx->r19, -0X7D80);
    // 0x8019EC3C: addiu       $s4, $s4, 0x78B0
    ctx->r20 = ADD32(ctx->r20, 0X78B0);
    // 0x8019EC40: addiu       $s6, $s6, 0x5D34
    ctx->r22 = ADD32(ctx->r22, 0X5D34);
    // 0x8019EC44: addiu       $s7, $s1, 0x1
    ctx->r23 = ADD32(ctx->r17, 0X1);
    // 0x8019EC48: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x8019EC4C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8019EC50:
    // 0x8019EC50: bne         $s2, $zero, L_8019EC78
    if (ctx->r18 != 0) {
        // 0x8019EC54: nop
    
            goto L_8019EC78;
    }
    // 0x8019EC54: nop

    // 0x8019EC58: lw          $t7, 0xC($s4)
    ctx->r15 = MEM_W(ctx->r20, 0XC);
    // 0x8019EC5C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8019EC60: nop

    // 0x8019EC64: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019EC68: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x8019EC6C: nop

    // 0x8019EC70: bc1tl       L_8019EE10
    if (c1cs) {
        // 0x8019EC74: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8019EE10;
    }
    goto skip_0;
    // 0x8019EC74: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
L_8019EC78:
    // 0x8019EC78: bne         $s2, $s5, L_8019ECA0
    if (ctx->r18 != ctx->r21) {
        // 0x8019EC7C: nop
    
            goto L_8019ECA0;
    }
    // 0x8019EC7C: nop

    // 0x8019EC80: lw          $t8, 0x8($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X8);
    // 0x8019EC84: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8019EC88: nop

    // 0x8019EC8C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019EC90: c.le.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl <= ctx->f20.fl;
    // 0x8019EC94: nop

    // 0x8019EC98: bc1tl       L_8019EE10
    if (c1cs) {
        // 0x8019EC9C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8019EE10;
    }
    goto skip_1;
    // 0x8019EC9C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
L_8019ECA0:
    // 0x8019ECA0: bne         $s2, $fp, L_8019ECC4
    if (ctx->r18 != ctx->r30) {
        // 0x8019ECA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019ECC4;
    }
    // 0x8019ECA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019ECA8: lw          $t9, 0x4($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X4);
    // 0x8019ECAC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8019ECB0: nop

    // 0x8019ECB4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8019ECB8: c.le.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl <= ctx->f20.fl;
    // 0x8019ECBC: nop

    // 0x8019ECC0: bc1t        L_8019EE0C
    if (c1cs) {
        // 0x8019ECC4: sll         $t0, $s2, 2
        ctx->r8 = S32(ctx->r18 << 2);
            goto L_8019EE0C;
    }
L_8019ECC4:
    // 0x8019ECC4: sll         $t0, $s2, 2
    ctx->r8 = S32(ctx->r18 << 2);
    // 0x8019ECC8: subu        $t0, $t0, $s2
    ctx->r8 = SUB32(ctx->r8, ctx->r18);
    // 0x8019ECCC: lui         $t1, 0x801A
    ctx->r9 = S32(0X801A << 16);
    // 0x8019ECD0: addiu       $t1, $t1, 0x69FC
    ctx->r9 = ADD32(ctx->r9, 0X69FC);
    // 0x8019ECD4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019ECD8: jal         0x800613C4
    // 0x8019ECDC: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    Actor_Initialize(rdram, ctx);
        goto after_1;
    // 0x8019ECDC: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    after_1:
    // 0x8019ECE0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8019ECE4: addiu       $t3, $zero, 0xC3
    ctx->r11 = ADD32(0, 0XC3);
    // 0x8019ECE8: sb          $t2, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r10;
    // 0x8019ECEC: jal         0x80004FE8
    // 0x8019ECF0: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_2;
    // 0x8019ECF0: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    after_2:
    // 0x8019ECF4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8019ECF8: sub.s       $f16, $f0, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8019ECFC: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8019ED00: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8019ED04: lwc1        $f8, 0x74($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X74);
    // 0x8019ED08: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8019ED0C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019ED10: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8019ED14: jal         0x80004FE8
    // 0x8019ED18: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_3;
    // 0x8019ED18: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    after_3:
    // 0x8019ED1C: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8019ED20: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8019ED24: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019ED28: lwc1        $f8, 0x78($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X78);
    // 0x8019ED2C: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019ED30: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8019ED34: jal         0x80004FE8
    // 0x8019ED38: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_4;
    // 0x8019ED38: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    after_4:
    // 0x8019ED3C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8019ED40: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8019ED44: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019ED48: lwc1        $f6, 0x7C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X7C);
    // 0x8019ED4C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019ED50: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8019ED54: jal         0x80004FE8
    // 0x8019ED58: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_5;
    // 0x8019ED58: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x8019ED5C: sub.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8019ED60: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8019ED64: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8019ED68: mul.s       $f4, $f10, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f28.fl);
    // 0x8019ED6C: swc1        $f4, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f4.u32l;
    // 0x8019ED70: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8019ED74: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8019ED78: mul.s       $f8, $f18, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8019ED7C: lwc1        $f6, 0x74($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X74);
    // 0x8019ED80: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019ED84: swc1        $f16, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f16.u32l;
    // 0x8019ED88: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8019ED8C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8019ED90: lwc1        $f10, 0x78($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X78);
    // 0x8019ED94: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019ED98: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
    // 0x8019ED9C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8019EDA0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8019EDA4: lwc1        $f6, 0x7C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X7C);
    // 0x8019EDA8: sh          $s5, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r21;
    // 0x8019EDAC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019EDB0: jal         0x800612B8
    // 0x8019EDB4: swc1        $f16, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_6;
    // 0x8019EDB4: swc1        $f16, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f16.u32l;
    after_6:
    // 0x8019EDB8: slti        $at, $s2, 0x3
    ctx->r1 = SIGNED(ctx->r18) < 0X3 ? 1 : 0;
    // 0x8019EDBC: bne         $at, $zero, L_8019EDD0
    if (ctx->r1 != 0) {
        // 0x8019EDC0: lui         $a0, 0x3100
        ctx->r4 = S32(0X3100 << 16);
            goto L_8019EDD0;
    }
    // 0x8019EDC0: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x8019EDC4: addiu       $t0, $zero, 0x23
    ctx->r8 = ADD32(0, 0X23);
    // 0x8019EDC8: sh          $t0, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r8;
    // 0x8019EDCC: swc1        $f20, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f20.u32l;
L_8019EDD0:
    // 0x8019EDD0: slti        $at, $s2, 0x7
    ctx->r1 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    // 0x8019EDD4: bne         $at, $zero, L_8019EDE8
    if (ctx->r1 != 0) {
        // 0x8019EDD8: ori         $a0, $a0, 0xC
        ctx->r4 = ctx->r4 | 0XC;
            goto L_8019EDE8;
    }
    // 0x8019EDD8: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8019EDDC: addiu       $t1, $zero, 0x24
    ctx->r9 = ADD32(0, 0X24);
    // 0x8019EDE0: sh          $t1, 0xB6($s0)
    MEM_H(0XB6, ctx->r16) = ctx->r9;
    // 0x8019EDE4: swc1        $f30, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f30.u32l;
L_8019EDE8:
    // 0x8019EDE8: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019EDEC: sw          $s5, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r21;
    // 0x8019EDF0: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019EDF4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019EDF8: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x8019EDFC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8019EE00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019EE04: jal         0x80019218
    // 0x8019EE08: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x8019EE08: or          $a3, $s6, $zero
    ctx->r7 = ctx->r22 | 0;
    after_7:
L_8019EE0C:
    // 0x8019EE0C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8019EE10:
    // 0x8019EE10: bne         $s7, $s2, L_8019EC50
    if (ctx->r23 != ctx->r18) {
        // 0x8019EE14: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_8019EC50;
    }
    // 0x8019EE14: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
L_8019EE18:
    // 0x8019EE18: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x8019EE1C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8019EE20: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8019EE24: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8019EE28: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8019EE2C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8019EE30: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8019EE34: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8019EE38: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8019EE3C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8019EE40: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8019EE44: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8019EE48: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8019EE4C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8019EE50: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8019EE54: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8019EE58: jr          $ra
    // 0x8019EE5C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8019EE5C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void SectorY_SyRobot_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4C34: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A4C38: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801A4C3C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801A4C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A4C44: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801A4C48: lui         $t6, 0x801A
    ctx->r14 = S32(0X801A << 16);
    // 0x801A4C4C: addiu       $t6, $t6, 0x6B58
    ctx->r14 = ADD32(ctx->r14, 0X6B58);
    // 0x801A4C50: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x801A4C54: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x801A4C58: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x801A4C5C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x801A4C60: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x801A4C64: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x801A4C68: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x801A4C6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A4C70: bne         $a0, $at, L_801A4CA0
    if (ctx->r4 != ctx->r1) {
        // 0x801A4C74: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801A4CA0;
    }
    // 0x801A4C74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A4C78: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A4C7C: jal         0x80006970
    // 0x801A4C80: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x801A4C80: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    after_0:
    // 0x801A4C84: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x801A4C88: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801A4C8C: swc1        $f4, 0x154($a3)
    MEM_W(0X154, ctx->r7) = ctx->f4.u32l;
    // 0x801A4C90: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801A4C94: swc1        $f6, 0x158($a3)
    MEM_W(0X158, ctx->r7) = ctx->f6.u32l;
    // 0x801A4C98: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801A4C9C: swc1        $f8, 0x15C($a3)
    MEM_W(0X15C, ctx->r7) = ctx->f8.u32l;
L_801A4CA0:
    // 0x801A4CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A4CA4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801A4CA8: jr          $ra
    // 0x801A4CAC: nop

    return;
    // 0x801A4CAC: nop

;}
RECOMP_FUNC void SectorY_80198F5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198F5C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80198F60: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80198F64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80198F68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80198F6C: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80198F70: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80198F74: sh          $t6, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r14;
    // 0x80198F78: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80198F7C: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80198F80: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80198F84: lw          $a3, 0x6C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X6C);
    // 0x80198F88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80198F8C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80198F90: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80198F94: lwc1        $f8, 0x7538($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7538);
    // 0x80198F98: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80198F9C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80198FA0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80198FA4: jal         0x8007C120
    // 0x80198FA8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_0;
    // 0x80198FA8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80198FAC: lh          $t8, 0x60($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X60);
    // 0x80198FB0: lh          $t9, 0x64($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X64);
    // 0x80198FB4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80198FB8: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80198FBC: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80198FC0: sh          $t0, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r8;
    // 0x80198FC4: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x80198FC8: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x80198FCC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80198FD0: bgez        $v0, L_80198FE0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80198FD4: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80198FE0;
    }
    // 0x80198FD4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80198FD8: sh          $zero, 0x60($s0)
    MEM_H(0X60, ctx->r16) = 0;
    // 0x80198FDC: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
L_80198FE0:
    // 0x80198FE0: bgtz        $v0, L_80199350
    if (SIGNED(ctx->r2) > 0) {
        // 0x80198FE4: sh          $t1, 0x58($s0)
        MEM_H(0X58, ctx->r16) = ctx->r9;
            goto L_80199350;
    }
    // 0x80198FE4: sh          $t1, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r9;
    // 0x80198FE8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x80198FEC: addiu       $v0, $v0, -0x40CC
    ctx->r2 = ADD32(ctx->r2, -0X40CC);
    // 0x80198FF0: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x80198FF4: srl         $t4, $t3, 28
    ctx->r12 = S32(U32(ctx->r11) >> 28);
    // 0x80198FF8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80198FFC: sh          $zero, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = 0;
    // 0x80199000: sh          $zero, 0xD0($s0)
    MEM_H(0XD0, ctx->r16) = 0;
    // 0x80199004: sh          $t2, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r10;
    // 0x80199008: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8019900C: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x80199010: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x80199014: lw          $t0, 0x40($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X40);
    // 0x80199018: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019901C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80199020: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x80199024: bne         $t0, $zero, L_80199140
    if (ctx->r8 != 0) {
        // 0x80199028: sw          $t9, 0x28($s0)
        MEM_W(0X28, ctx->r16) = ctx->r25;
            goto L_80199140;
    }
    // 0x80199028: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x8019902C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80199030: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80199034: addiu       $t1, $zero, 0x4E20
    ctx->r9 = ADD32(0, 0X4E20);
    // 0x80199038: addiu       $a0, $a0, -0x7D80
    ctx->r4 = ADD32(ctx->r4, -0X7D80);
    // 0x8019903C: sh          $t1, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r9;
    // 0x80199040: swc1        $f2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f2.u32l;
    // 0x80199044: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
    // 0x80199048: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    // 0x8019904C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80199050: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80199054: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80199058: lw          $v1, 0x1C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C8);
    // 0x8019905C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80199060: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x80199064: beq         $v1, $at, L_80199074
    if (ctx->r3 == ctx->r1) {
        // 0x80199068: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80199074;
    }
    // 0x80199068: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019906C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80199070: bne         $v1, $at, L_80199104
    if (ctx->r3 != ctx->r1) {
        // 0x80199074: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_80199104;
    }
L_80199074:
    // 0x80199074: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80199078: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019907C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80199080: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x80199084: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80199088: sw          $t2, 0x1C8($v0)
    MEM_W(0X1C8, ctx->r2) = ctx->r10;
    // 0x8019908C: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80199090: sw          $zero, 0x1F8($t3)
    MEM_W(0X1F8, ctx->r11) = 0;
    // 0x80199094: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80199098: lw          $t4, 0x1F8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1F8);
    // 0x8019909C: sw          $t4, 0x1D0($v0)
    MEM_W(0X1D0, ctx->r2) = ctx->r12;
    // 0x801990A0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801990A4: lwc1        $f10, 0xE8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x801990A8: lwc1        $f16, 0x114($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X114);
    // 0x801990AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801990B0: swc1        $f18, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->f18.u32l;
    // 0x801990B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801990B8: lwc1        $f0, 0xE8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x801990BC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801990C0: nop

    // 0x801990C4: bc1fl       L_801990E4
    if (!c1cs) {
        // 0x801990C8: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_801990E4;
    }
    goto skip_0;
    // 0x801990C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x801990CC: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x801990D0: swc1        $f4, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->f4.u32l;
    // 0x801990D4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801990D8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x801990DC: lwc1        $f0, 0xE8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XE8);
    // 0x801990E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_801990E4:
    // 0x801990E4: nop

    // 0x801990E8: bc1fl       L_80199104
    if (!c1cs) {
        // 0x801990EC: swc1        $f2, 0x114($v0)
        MEM_W(0X114, ctx->r2) = ctx->f2.u32l;
            goto L_80199104;
    }
    goto skip_1;
    // 0x801990EC: swc1        $f2, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f2.u32l;
    skip_1:
    // 0x801990F0: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x801990F4: swc1        $f6, 0xE8($v0)
    MEM_W(0XE8, ctx->r2) = ctx->f6.u32l;
    // 0x801990F8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801990FC: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80199100: swc1        $f2, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f2.u32l;
L_80199104:
    // 0x80199104: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80199108: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x8019910C: lui         $a0, 0x2940
    ctx->r4 = S32(0X2940 << 16);
    // 0x80199110: ori         $a0, $a0, 0xD09A
    ctx->r4 = ctx->r4 | 0XD09A;
    // 0x80199114: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80199118: jal         0x80019218
    // 0x8019911C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019911C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x80199120: lui         $a0, 0x101E
    ctx->r4 = S32(0X101E << 16);
    // 0x80199124: jal         0x800182F4
    // 0x80199128: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x80199128: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_2:
    // 0x8019912C: lui         $a0, 0x111E
    ctx->r4 = S32(0X111E << 16);
    // 0x80199130: jal         0x800182F4
    // 0x80199134: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_3;
    // 0x80199134: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x80199138: b           L_80199428
    // 0x8019913C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80199428;
    // 0x8019913C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80199140:
    // 0x80199140: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80199144: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80199148: lbu         $t6, 0x408($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X408);
    // 0x8019914C: lui         $a0, 0x1014
    ctx->r4 = S32(0X1014 << 16);
    // 0x80199150: beq         $t6, $zero, L_80199164
    if (ctx->r14 == 0) {
        // 0x80199154: nop
    
            goto L_80199164;
    }
    // 0x80199154: nop

    // 0x80199158: lbu         $t7, 0x810($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X810);
    // 0x8019915C: bne         $t7, $zero, L_80199178
    if (ctx->r15 != 0) {
        // 0x80199160: nop
    
            goto L_80199178;
    }
    // 0x80199160: nop

L_80199164:
    // 0x80199164: jal         0x800182F4
    // 0x80199168: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_4;
    // 0x80199168: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_4:
    // 0x8019916C: lui         $a0, 0x1114
    ctx->r4 = S32(0X1114 << 16);
    // 0x80199170: jal         0x800182F4
    // 0x80199174: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_5;
    // 0x80199174: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_5:
L_80199178:
    // 0x80199178: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8019917C: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x80199180: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80199184: addiu       $v1, $zero, 0x3C
    ctx->r3 = ADD32(0, 0X3C);
L_80199188:
    // 0x80199188: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x8019918C: bnel        $t8, $zero, L_801991B4
    if (ctx->r24 != 0) {
        // 0x80199190: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801991B4;
    }
    goto skip_2;
    // 0x80199190: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x80199194: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x80199198: jal         0x80197B30
    // 0x8019919C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    SectorY_80197B30(rdram, ctx);
        goto after_6;
    // 0x8019919C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_6:
    // 0x801991A0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x801991A4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801991A8: b           L_801991BC
    // 0x801991AC: sw          $v0, 0x7A34($at)
    MEM_W(0X7A34, ctx->r1) = ctx->r2;
        goto L_801991BC;
    // 0x801991AC: sw          $v0, 0x7A34($at)
    MEM_W(0X7A34, ctx->r1) = ctx->r2;
    // 0x801991B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_801991B4:
    // 0x801991B4: bne         $v0, $v1, L_80199188
    if (ctx->r2 != ctx->r3) {
        // 0x801991B8: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_80199188;
    }
    // 0x801991B8: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_801991BC:
    // 0x801991BC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801991C0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801991C4: addiu       $t9, $zero, 0x7D0
    ctx->r25 = ADD32(0, 0X7D0);
    // 0x801991C8: addiu       $a0, $a0, -0x7D80
    ctx->r4 = ADD32(ctx->r4, -0X7D80);
    // 0x801991CC: sh          $t9, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r25;
    // 0x801991D0: swc1        $f2, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f2.u32l;
    // 0x801991D4: swc1        $f2, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f2.u32l;
    // 0x801991D8: swc1        $f2, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f2.u32l;
    // 0x801991DC: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x801991E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801991E4: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x801991E8: lw          $v1, 0x1C8($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X1C8);
    // 0x801991EC: beq         $v1, $at, L_801991FC
    if (ctx->r3 == ctx->r1) {
        // 0x801991F0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801991FC;
    }
    // 0x801991F0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801991F4: bnel        $v1, $at, L_80199428
    if (ctx->r3 != ctx->r1) {
        // 0x801991F8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80199428;
    }
    goto skip_3;
    // 0x801991F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
L_801991FC:
    // 0x801991FC: sh          $t1, 0x58($s0)
    MEM_H(0X58, ctx->r16) = ctx->r9;
    // 0x80199200: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80199204: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80199208: sw          $zero, 0x1C8($t2)
    MEM_W(0X1C8, ctx->r10) = 0;
    // 0x8019920C: sw          $zero, 0x7A80($at)
    MEM_W(0X7A80, ctx->r1) = 0;
    // 0x80199210: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80199214: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80199218: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019921C: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80199220: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80199224: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80199228: jal         0x80005100
    // 0x8019922C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    Math_Atan2F(rdram, ctx);
        goto after_7;
    // 0x8019922C: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    after_7:
    // 0x80199230: jal         0x8009F768
    // 0x80199234: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_8;
    // 0x80199234: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_8:
    // 0x80199238: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019923C: addiu       $v0, $v0, 0x7A48
    ctx->r2 = ADD32(ctx->r2, 0X7A48);
    // 0x80199240: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80199244: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199248: lwc1        $f6, 0x753C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X753C);
    // 0x8019924C: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80199250: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80199254: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80199258: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019925C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80199260: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80199264: jal         0x80005E90
    // 0x80199268: nop

    Matrix_RotateY(rdram, ctx);
        goto after_9;
    // 0x80199268: nop

    after_9:
    // 0x8019926C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80199270: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80199274: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80199278: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019927C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80199280: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x80199284: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x80199288: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x8019928C: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    // 0x80199290: jal         0x80006970
    // 0x80199294: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x80199294: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x80199298: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019929C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801992A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801992A4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801992A8: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801992AC: swc1        $f4, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f4.u32l;
    // 0x801992B0: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x801992B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801992B8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801992BC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801992C0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801992C4: swc1        $f10, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f10.u32l;
    // 0x801992C8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801992CC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801992D0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801992D4: swc1        $f4, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f4.u32l;
    // 0x801992D8: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801992DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801992E0: swc1        $f6, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f6.u32l;
    // 0x801992E4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801992E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801992EC: swc1        $f8, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f8.u32l;
    // 0x801992F0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801992F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801992F8: swc1        $f10, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f10.u32l;
    // 0x801992FC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199300: lwc1        $f16, 0x7540($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7540);
    // 0x80199304: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80199308: jal         0x80004EB0
    // 0x8019930C: swc1        $f16, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x8019930C: swc1        $f16, 0x7A48($at)
    MEM_W(0X7A48, ctx->r1) = ctx->f16.u32l;
    after_11:
    // 0x80199310: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80199314: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80199318: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8019931C: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80199320: nop

    // 0x80199324: bc1fl       L_80199344
    if (!c1cs) {
        // 0x80199328: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80199344;
    }
    goto skip_4;
    // 0x80199328: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x8019932C: lui         $at, 0xC040
    ctx->r1 = S32(0XC040 << 16);
    // 0x80199330: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80199334: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80199338: b           L_80199424
    // 0x8019933C: swc1        $f4, 0x7A6C($at)
    MEM_W(0X7A6C, ctx->r1) = ctx->f4.u32l;
        goto L_80199424;
    // 0x8019933C: swc1        $f4, 0x7A6C($at)
    MEM_W(0X7A6C, ctx->r1) = ctx->f4.u32l;
    // 0x80199340: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80199344:
    // 0x80199344: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80199348: b           L_80199424
    // 0x8019934C: swc1        $f6, 0x7A6C($at)
    MEM_W(0X7A6C, ctx->r1) = ctx->f6.u32l;
        goto L_80199424;
    // 0x8019934C: swc1        $f6, 0x7A6C($at)
    MEM_W(0X7A6C, ctx->r1) = ctx->f6.u32l;
L_80199350:
    // 0x80199350: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x80199354: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80199358: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019935C: beq         $t3, $zero, L_80199390
    if (ctx->r11 == 0) {
        // 0x80199360: slti        $at, $v0, 0x47
        ctx->r1 = SIGNED(ctx->r2) < 0X47 ? 1 : 0;
            goto L_80199390;
    }
    // 0x80199360: slti        $at, $v0, 0x47
    ctx->r1 = SIGNED(ctx->r2) < 0X47 ? 1 : 0;
    // 0x80199364: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80199368: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8019936C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x80199370: ori         $a0, $a0, 0x300E
    ctx->r4 = ctx->r4 | 0X300E;
    // 0x80199374: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80199378: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019937C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80199380: jal         0x80019218
    // 0x80199384: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_12;
    // 0x80199384: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_12:
    // 0x80199388: b           L_801993F4
    // 0x8019938C: nop

        goto L_801993F4;
    // 0x8019938C: nop

L_80199390:
    // 0x80199390: bne         $at, $zero, L_801993CC
    if (ctx->r1 != 0) {
        // 0x80199394: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801993CC;
    }
    // 0x80199394: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80199398: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019939C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x801993A0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801993A4: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x801993A8: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x801993AC: ori         $a0, $a0, 0x4003
    ctx->r4 = ctx->r4 | 0X4003;
    // 0x801993B0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x801993B4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801993B8: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x801993BC: jal         0x80019218
    // 0x801993C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_13;
    // 0x801993C0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_13:
    // 0x801993C4: b           L_801993F4
    // 0x801993C8: nop

        goto L_801993F4;
    // 0x801993C8: nop

L_801993CC:
    // 0x801993CC: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801993D0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801993D4: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x801993D8: lui         $a0, 0x2943
    ctx->r4 = S32(0X2943 << 16);
    // 0x801993DC: ori         $a0, $a0, 0x500F
    ctx->r4 = ctx->r4 | 0X500F;
    // 0x801993E0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801993E4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801993E8: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x801993EC: jal         0x80019218
    // 0x801993F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_14;
    // 0x801993F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_14:
L_801993F4:
    // 0x801993F4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801993F8: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x801993FC: lbu         $t7, 0x408($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X408);
    // 0x80199400: bnel        $t7, $zero, L_80199428
    if (ctx->r15 != 0) {
        // 0x80199404: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80199428;
    }
    goto skip_5;
    // 0x80199404: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_5:
    // 0x80199408: lbu         $t8, 0x810($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X810);
    // 0x8019940C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80199410: addiu       $a0, $a0, 0x9FC
    ctx->r4 = ADD32(ctx->r4, 0X9FC);
    // 0x80199414: bnel        $t8, $zero, L_80199428
    if (ctx->r24 != 0) {
        // 0x80199418: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80199428;
    }
    goto skip_6;
    // 0x80199418: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_6:
    // 0x8019941C: jal         0x8002E4F8
    // 0x80199420: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    AllRange_PlayMessage(rdram, ctx);
        goto after_15;
    // 0x80199420: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_15:
L_80199424:
    // 0x80199424: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80199428:
    // 0x80199428: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019942C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80199430: jr          $ra
    // 0x80199434: nop

    return;
    // 0x80199434: nop

;}
RECOMP_FUNC void Andross_AndBrainWaste_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188660: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80188664: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80188668: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018866C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80188670: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80188674: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80188678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018867C: jal         0x800B8DD0
    // 0x80188680: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80188680: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    after_0:
    // 0x80188684: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80188688: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8018868C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80188690: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80188694: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80188698: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018869C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801886A0: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801886A4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801886A8: lwc1        $f6, 0x6BE8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6BE8);
    // 0x801886AC: lwc1        $f4, 0xFC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XFC);
    // 0x801886B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801886B4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801886B8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801886BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801886C0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801886C4: jal         0x80005FE0
    // 0x801886C8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x801886C8: nop

    after_1:
    // 0x801886CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801886D0: lui         $a1, 0x3F8C
    ctx->r5 = S32(0X3F8C << 16);
    // 0x801886D4: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x801886D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801886DC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801886E0: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x801886E4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801886E8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801886EC: jal         0x80005C34
    // 0x801886F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x801886F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x801886F4: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801886F8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801886FC: lwc1        $f18, 0x6BEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6BEC);
    // 0x80188700: lwc1        $f10, 0xFC($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XFC);
    // 0x80188704: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188708: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018870C: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80188710: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80188714: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80188718: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8018871C: jal         0x80005FE0
    // 0x80188720: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x80188720: nop

    after_3:
    // 0x80188724: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188728: lui         $a1, 0x3F8C
    ctx->r5 = S32(0X3F8C << 16);
    // 0x8018872C: lui         $a2, 0x3F66
    ctx->r6 = S32(0X3F66 << 16);
    // 0x80188730: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80188734: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80188738: ori         $a2, $a2, 0x6666
    ctx->r6 = ctx->r6 | 0X6666;
    // 0x8018873C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80188740: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80188744: jal         0x80005C34
    // 0x80188748: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x80188748: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x8018874C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80188750: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188754: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188758: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018875C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80188760: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80188764: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80188768: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018876C: jal         0x80005C34
    // 0x80188770: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x80188770: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_5:
    // 0x80188774: jal         0x80006EB8
    // 0x80188778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x80188778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8018877C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80188780: lui         $t6, 0x601
    ctx->r14 = S32(0X601 << 16);
    // 0x80188784: addiu       $t6, $t6, -0x6D00
    ctx->r14 = ADD32(ctx->r14, -0X6D00);
    // 0x80188788: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8018878C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80188790: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x80188794: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80188798: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018879C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801887A0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801887A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801887A8: jr          $ra
    // 0x801887AC: nop

    return;
    // 0x801887AC: nop

;}
RECOMP_FUNC void Andross_James_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801880E4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801880E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801880EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801880F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801880F4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801880F8: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
    // 0x801880FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80188100: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
    // 0x80188104: addiu       $a0, $zero, 0x93
    ctx->r4 = ADD32(0, 0X93);
L_80188108:
    // 0x80188108: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x8018810C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80188110: bne         $a0, $t6, L_80188144
    if (ctx->r4 != ctx->r14) {
        // 0x80188114: nop
    
            goto L_80188144;
    }
    // 0x80188114: nop

    // 0x80188118: lbu         $t7, 0x4F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4F);
    // 0x8018811C: lbu         $t8, 0x40($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X40);
    // 0x80188120: bne         $t7, $t8, L_80188144
    if (ctx->r15 != ctx->r24) {
        // 0x80188124: nop
    
            goto L_80188144;
    }
    // 0x80188124: nop

    // 0x80188128: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8018812C: swc1        $f4, 0x120($s0)
    MEM_W(0X120, ctx->r16) = ctx->f4.u32l;
    // 0x80188130: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80188134: swc1        $f6, 0x124($s0)
    MEM_W(0X124, ctx->r16) = ctx->f6.u32l;
    // 0x80188138: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8018813C: b           L_8018814C
    // 0x80188140: swc1        $f8, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f8.u32l;
        goto L_8018814C;
    // 0x80188140: swc1        $f8, 0x128($s0)
    MEM_W(0X128, ctx->r16) = ctx->f8.u32l;
L_80188144:
    // 0x80188144: bne         $v1, $a1, L_80188108
    if (ctx->r3 != ctx->r5) {
        // 0x80188148: addiu       $v0, $v0, 0x58
        ctx->r2 = ADD32(ctx->r2, 0X58);
            goto L_80188108;
    }
    // 0x80188148: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
L_8018814C:
    // 0x8018814C: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x80188150: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80188154: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80188158: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018815C: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80188160: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80188164: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80188168: lwc1        $f6, 0x124($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8018816C: abs.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = fabsf(ctx->f12.fl);
    // 0x80188170: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188174: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80188178: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018817C: lwc1        $f10, 0x128($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X128);
    // 0x80188180: swc1        $f18, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f18.u32l;
    // 0x80188184: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80188188: bc1f        L_801881C4
    if (!c1cs) {
        // 0x8018818C: sub.s       $f16, $f10, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
            goto L_801881C4;
    }
    // 0x8018818C: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80188190: abs.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = fabsf(ctx->f14.fl);
    // 0x80188194: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80188198: nop

    // 0x8018819C: bc1f        L_801881C4
    if (!c1cs) {
        // 0x801881A0: nop
    
            goto L_801881C4;
    }
    // 0x801881A0: nop

    // 0x801881A4: abs.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = fabsf(ctx->f16.fl);
    // 0x801881A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801881AC: nop

    // 0x801881B0: bc1f        L_801881C4
    if (!c1cs) {
        // 0x801881B4: nop
    
            goto L_801881C4;
    }
    // 0x801881B4: nop

    // 0x801881B8: lh          $t9, 0x4E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4E);
    // 0x801881BC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x801881C0: sh          $t0, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r8;
L_801881C4:
    // 0x801881C4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x801881C8: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x801881CC: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801881D0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801881D4: andi        $t2, $t1, 0x1F
    ctx->r10 = ctx->r9 & 0X1F;
    // 0x801881D8: bne         $t2, $zero, L_80188280
    if (ctx->r10 != 0) {
        // 0x801881DC: addiu       $a0, $s0, 0x114
        ctx->r4 = ADD32(ctx->r16, 0X114);
            goto L_80188280;
    }
    // 0x801881DC: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x801881E0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801881E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801881E8: lui         $at, 0x423C
    ctx->r1 = S32(0X423C << 16);
    // 0x801881EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801881F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801881F4: sw          $t3, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r11;
    // 0x801881F8: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801881FC: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
    // 0x80188200: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80188204: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80188208: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8018820C: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80188210: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80188214: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80188218: nop

    // 0x8018821C: bc1fl       L_80188284
    if (!c1cs) {
        // 0x80188220: lw          $a1, 0x118($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X118);
            goto L_80188284;
    }
    goto skip_0;
    // 0x80188220: lw          $a1, 0x118($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X118);
    skip_0:
    // 0x80188224: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80188228: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8018822C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80188230: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80188234: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80188238: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8018823C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80188240: nop

    // 0x80188244: bc1fl       L_80188284
    if (!c1cs) {
        // 0x80188248: lw          $a1, 0x118($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X118);
            goto L_80188284;
    }
    goto skip_1;
    // 0x80188248: lw          $a1, 0x118($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X118);
    skip_1:
    // 0x8018824C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80188250: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x80188254: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80188258: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8018825C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80188260: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80188264: nop

    // 0x80188268: bc1fl       L_80188284
    if (!c1cs) {
        // 0x8018826C: lw          $a1, 0x118($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X118);
            goto L_80188284;
    }
    goto skip_2;
    // 0x8018826C: lw          $a1, 0x118($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X118);
    skip_2:
    // 0x80188270: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188274: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80188278: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x8018827C: swc1        $f6, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f6.u32l;
L_80188280:
    // 0x80188280: lw          $a1, 0x118($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X118);
L_80188284:
    // 0x80188284: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188288: lwc1        $f8, 0x6BC8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BC8);
    // 0x8018828C: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80188290: swc1        $f16, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f16.u32l;
    // 0x80188294: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x80188298: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x8018829C: jal         0x8009BC2C
    // 0x801882A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801882A0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x801882A4: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801882A8: jal         0x80005100
    // 0x801882AC: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x801882AC: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x801882B0: jal         0x8009F768
    // 0x801882B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_2;
    // 0x801882B4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_2:
    // 0x801882B8: lwc1        $f2, 0x68($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801882BC: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801882C0: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x801882C4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801882C8: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801882CC: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801882D0: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801882D4: jal         0x80005100
    // 0x801882D8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_3;
    // 0x801882D8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_3:
    // 0x801882DC: jal         0x8009F768
    // 0x801882E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_4;
    // 0x801882E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_4:
    // 0x801882E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801882E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801882EC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801882F0: lw          $a3, 0x11C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X11C);
    // 0x801882F4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801882F8: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x801882FC: jal         0x8009BD38
    // 0x80188300: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_5;
    // 0x80188300: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x80188304: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188308: lwc1        $f8, 0x6BCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BCC);
    // 0x8018830C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188310: lw          $a3, 0x11C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X11C);
    // 0x80188314: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188318: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8018831C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80188320: jal         0x8009BD38
    // 0x80188324: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x80188324: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_6:
    // 0x80188328: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8018832C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80188330: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80188334: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80188338: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8018833C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80188340: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188344: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80188348: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8018834C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80188350: nop

    // 0x80188354: bc1fl       L_80188378
    if (!c1cs) {
        // 0x80188358: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80188378;
    }
    goto skip_3;
    // 0x80188358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x8018835C: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80188360: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80188364: nop

    // 0x80188368: mul.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8018836C: b           L_80188380
    // 0x80188370: nop

        goto L_80188380;
    // 0x80188370: nop

    // 0x80188374: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80188378:
    // 0x80188378: nop

    // 0x8018837C: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
L_80188380:
    // 0x80188380: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188384: lwc1        $f10, 0x6BD0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6BD0);
    // 0x80188388: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018838C: jal         0x8009BD38
    // 0x80188390: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_7;
    // 0x80188390: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80188394: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x80188398: lwc1        $f2, 0xF8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8018839C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801883A0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801883A4: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x801883A8: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x801883AC: lwc1        $f8, 0x6BD4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BD4);
    // 0x801883B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801883B4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801883B8: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x801883BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801883C0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801883C4: jal         0x80005E90
    // 0x801883C8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x801883C8: nop

    after_8:
    // 0x801883CC: lwc1        $f4, 0xF4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF4);
    // 0x801883D0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801883D4: lwc1        $f8, 0x6BD8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6BD8);
    // 0x801883D8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801883DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801883E0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801883E4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801883E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801883EC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801883F0: jal         0x80005D44
    // 0x801883F4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x801883F4: nop

    after_9:
    // 0x801883F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801883FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80188400: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80188404: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x80188408: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8018840C: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80188410: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80188414: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x80188418: jal         0x80006A20
    // 0x8018841C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_10;
    // 0x8018841C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x80188420: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80188424: swc1        $f6, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f6.u32l;
    // 0x80188428: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8018842C: swc1        $f8, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f8.u32l;
    // 0x80188430: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80188434: swc1        $f10, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f10.u32l;
    // 0x80188438: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018843C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80188440: jr          $ra
    // 0x80188444: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80188444: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Venom2_Ve2Base_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196210: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80196214: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80196218: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019621C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80196220: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80196224: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x80196228: lw          $a1, 0xDC($t6)
    ctx->r5 = MEM_W(ctx->r14, 0XDC);
    // 0x8019622C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80196230: addiu       $a0, $t6, 0xD8
    ctx->r4 = ADD32(ctx->r14, 0XD8);
    // 0x80196234: jal         0x8009BC2C
    // 0x80196238: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80196238: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8019623C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80196240: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80196244: jr          $ra
    // 0x80196248: nop

    return;
    // 0x80196248: nop

;}
RECOMP_FUNC void SectorY_80199DAC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199DAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80199DB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80199DB4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80199DB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80199DBC: jal         0x8019B6E8
    // 0x80199DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B6E8(rdram, ctx);
        goto after_0;
    // 0x80199DC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80199DC4: lh          $t6, 0x52($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X52);
    // 0x80199DC8: bnel        $t6, $zero, L_80199DDC
    if (ctx->r14 != 0) {
        // 0x80199DCC: lui         $at, 0xC396
        ctx->r1 = S32(0XC396 << 16);
            goto L_80199DDC;
    }
    goto skip_0;
    // 0x80199DCC: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    skip_0:
    // 0x80199DD0: jal         0x8019BC14
    // 0x80199DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019BC14(rdram, ctx);
        goto after_1;
    // 0x80199DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80199DD8: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
L_80199DDC:
    // 0x80199DDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80199DE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80199DE4: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80199DE8: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80199DEC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80199DF0: jal         0x80005100
    // 0x80199DF4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    Math_Atan2F(rdram, ctx);
        goto after_2;
    // 0x80199DF4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    after_2:
    // 0x80199DF8: jal         0x8009F768
    // 0x80199DFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x80199DFC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_3:
    // 0x80199E00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199E04: lwc1        $f18, 0x7554($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7554);
    // 0x80199E08: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80199E0C: mul.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80199E10: jal         0x80023090
    // 0x80199E14: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x80199E14: nop

    after_4:
    // 0x80199E18: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80199E1C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199E20: lwc1        $f4, 0x18C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80199E24: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80199E28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199E2C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80199E30: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80199E34: swc1        $f10, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f10.u32l;
    // 0x80199E38: lwc1        $f18, 0x7558($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7558);
    // 0x80199E3C: mul.s       $f12, $f18, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80199E40: jal         0x80023250
    // 0x80199E44: nop

    __cosf_recomp(rdram, ctx);
        goto after_5;
    // 0x80199E44: nop

    after_5:
    // 0x80199E48: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199E4C: lwc1        $f14, 0x755C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X755C);
    // 0x80199E50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80199E54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80199E58: lwc1        $f4, 0x18C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80199E5C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80199E60: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80199E64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80199E68: swc1        $f2, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f2.u32l;
    // 0x80199E6C: addiu       $a0, $s0, 0x80
    ctx->r4 = ADD32(ctx->r16, 0X80);
    // 0x80199E70: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80199E74: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80199E78: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x80199E7C: swc1        $f10, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f10.u32l;
    // 0x80199E80: jal         0x8009BD38
    // 0x80199E84: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_6;
    // 0x80199E84: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x80199E88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199E8C: lwc1        $f14, 0x7560($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7560);
    // 0x80199E90: lw          $a1, 0x100($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X100);
    // 0x80199E94: addiu       $a0, $s0, 0x7C
    ctx->r4 = ADD32(ctx->r16, 0X7C);
    // 0x80199E98: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80199E9C: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x80199EA0: jal         0x8009BD38
    // 0x80199EA4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_7;
    // 0x80199EA4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_7:
    // 0x80199EA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80199EAC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80199EB0: lw          $a1, 0x108($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X108);
    // 0x80199EB4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80199EB8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80199EBC: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80199EC0: jal         0x8009BC2C
    // 0x80199EC4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x80199EC4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_8:
    // 0x80199EC8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80199ECC: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80199ED0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199ED4: lwc1        $f14, 0x7568($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7568);
    // 0x80199ED8: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80199EDC: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x80199EE0: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80199EE4: bc1fl       L_80199EF8
    if (!c1cs) {
        // 0x80199EE8: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_80199EF8;
    }
    goto skip_1;
    // 0x80199EE8: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_1:
    // 0x80199EEC: b           L_80199EF8
    // 0x80199EF0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80199EF8;
    // 0x80199EF0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80199EF4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80199EF8:
    // 0x80199EF8: lwc1        $f18, 0x108($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X108);
    // 0x80199EFC: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x80199F00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80199F04: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80199F08: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x80199F0C: nop

    // 0x80199F10: bc1fl       L_8019A154
    if (!c1cs) {
        // 0x80199F14: lw          $a1, 0x104($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X104);
            goto L_8019A154;
    }
    goto skip_2;
    // 0x80199F14: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    skip_2:
    // 0x80199F18: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80199F1C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80199F20: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80199F24: nop

    // 0x80199F28: bc1fl       L_80199F3C
    if (!c1cs) {
        // 0x80199F2C: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_80199F3C;
    }
    goto skip_3;
    // 0x80199F2C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_3:
    // 0x80199F30: b           L_80199F3C
    // 0x80199F34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80199F3C;
    // 0x80199F34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80199F38: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80199F3C:
    // 0x80199F3C: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x80199F40: nop

    // 0x80199F44: bc1fl       L_8019A154
    if (!c1cs) {
        // 0x80199F48: lw          $a1, 0x104($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X104);
            goto L_8019A154;
    }
    goto skip_4;
    // 0x80199F48: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    skip_4:
    // 0x80199F4C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80199F50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80199F54: nop

    // 0x80199F58: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80199F5C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x80199F60: nop

    // 0x80199F64: bc1fl       L_80199F78
    if (!c1cs) {
        // 0x80199F68: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_80199F78;
    }
    goto skip_5;
    // 0x80199F68: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_5:
    // 0x80199F6C: b           L_80199F78
    // 0x80199F70: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80199F78;
    // 0x80199F70: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80199F74: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80199F78:
    // 0x80199F78: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x80199F7C: nop

    // 0x80199F80: bc1fl       L_8019A154
    if (!c1cs) {
        // 0x80199F84: lw          $a1, 0x104($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X104);
            goto L_8019A154;
    }
    goto skip_6;
    // 0x80199F84: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
    skip_6:
    // 0x80199F88: lwc1        $f2, 0x104($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X104);
    // 0x80199F8C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80199F90: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80199F94: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80199F98: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80199F9C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x80199FA0: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    // 0x80199FA4: bc1f        L_80199FB4
    if (!c1cs) {
        // 0x80199FA8: swc1        $f16, 0x74($s0)
        MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
            goto L_80199FB4;
    }
    // 0x80199FA8: swc1        $f16, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
    // 0x80199FAC: b           L_80199FB8
    // 0x80199FB0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80199FB8;
    // 0x80199FB0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80199FB4:
    // 0x80199FB4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80199FB8:
    // 0x80199FB8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80199FBC: jal         0x8009BC2C
    // 0x80199FC0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80199FC0: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_9:
    // 0x80199FC4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80199FC8: lwc1        $f2, 0x10C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80199FCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80199FD0: lwc1        $f14, 0x756C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X756C);
    // 0x80199FD4: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80199FD8: addiu       $a0, $s0, 0xC
    ctx->r4 = ADD32(ctx->r16, 0XC);
    // 0x80199FDC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80199FE0: lui         $a1, 0xC396
    ctx->r5 = S32(0XC396 << 16);
    // 0x80199FE4: bc1fl       L_80199FF8
    if (!c1cs) {
        // 0x80199FE8: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_80199FF8;
    }
    goto skip_7;
    // 0x80199FE8: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_7:
    // 0x80199FEC: b           L_80199FF8
    // 0x80199FF0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_80199FF8;
    // 0x80199FF0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80199FF4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80199FF8:
    // 0x80199FF8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80199FFC: jal         0x8009BC2C
    // 0x8019A000: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8019A000: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_10:
    // 0x8019A004: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A008: lwc1        $f14, 0x7570($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7570);
    // 0x8019A00C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8019A010: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019A014: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8019A018: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019A01C: jal         0x8009BD38
    // 0x8019A020: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_11;
    // 0x8019A020: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_11:
    // 0x8019A024: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8019A028: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019A02C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019A030: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A034: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8019A038: lwc1        $f14, 0x7574($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7574);
    // 0x8019A03C: swc1        $f10, 0x100($s0)
    MEM_W(0X100, ctx->r16) = ctx->f10.u32l;
    // 0x8019A040: bc1fl       L_8019A054
    if (!c1cs) {
        // 0x8019A044: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_8019A054;
    }
    goto skip_8;
    // 0x8019A044: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_8:
    // 0x8019A048: b           L_8019A054
    // 0x8019A04C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8019A054;
    // 0x8019A04C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8019A050: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_8019A054:
    // 0x8019A054: lwc1        $f18, 0x108($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X108);
    // 0x8019A058: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019A05C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019A060: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x8019A064: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x8019A068: nop

    // 0x8019A06C: bc1fl       L_8019A380
    if (!c1cs) {
        // 0x8019A070: lh          $t5, 0x56($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X56);
            goto L_8019A380;
    }
    goto skip_9;
    // 0x8019A070: lh          $t5, 0x56($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X56);
    skip_9:
    // 0x8019A074: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019A078: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8019A07C: nop

    // 0x8019A080: bc1fl       L_8019A094
    if (!c1cs) {
        // 0x8019A084: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_8019A094;
    }
    goto skip_10;
    // 0x8019A084: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_10:
    // 0x8019A088: b           L_8019A094
    // 0x8019A08C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8019A094;
    // 0x8019A08C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019A090: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8019A094:
    // 0x8019A094: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x8019A098: nop

    // 0x8019A09C: bc1fl       L_8019A380
    if (!c1cs) {
        // 0x8019A0A0: lh          $t5, 0x56($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X56);
            goto L_8019A380;
    }
    goto skip_11;
    // 0x8019A0A0: lh          $t5, 0x56($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X56);
    skip_11:
    // 0x8019A0A4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019A0A8: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x8019A0AC: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x8019A0B0: add.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8019A0B4: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8019A0B8: nop

    // 0x8019A0BC: bc1fl       L_8019A0D0
    if (!c1cs) {
        // 0x8019A0C0: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_8019A0D0;
    }
    goto skip_12;
    // 0x8019A0C0: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_12:
    // 0x8019A0C4: b           L_8019A0D0
    // 0x8019A0C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8019A0D0;
    // 0x8019A0C8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019A0CC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8019A0D0:
    // 0x8019A0D0: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x8019A0D4: nop

    // 0x8019A0D8: bc1fl       L_8019A380
    if (!c1cs) {
        // 0x8019A0DC: lh          $t5, 0x56($s0)
        ctx->r13 = MEM_H(ctx->r16, 0X56);
            goto L_8019A380;
    }
    goto skip_13;
    // 0x8019A0DC: lh          $t5, 0x56($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X56);
    skip_13:
    // 0x8019A0E0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8019A0E4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8019A0E8: jal         0x8009BC2C
    // 0x8019A0EC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x8019A0EC: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_12:
    // 0x8019A0F0: lh          $t9, 0x56($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X56);
    // 0x8019A0F4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8019A0F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019A0FC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x8019A100: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x8019A104: sh          $t7, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r15;
    // 0x8019A108: sh          $t8, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r24;
    // 0x8019A10C: bne         $t9, $zero, L_8019A37C
    if (ctx->r25 != 0) {
        // 0x8019A110: swc1        $f8, 0x108($s0)
        MEM_W(0X108, ctx->r16) = ctx->f8.u32l;
            goto L_8019A37C;
    }
    // 0x8019A110: swc1        $f8, 0x108($s0)
    MEM_W(0X108, ctx->r16) = ctx->f8.u32l;
    // 0x8019A114: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019A118: addiu       $t0, $zero, 0x33
    ctx->r8 = ADD32(0, 0X33);
    // 0x8019A11C: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x8019A120: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019A124: sh          $t0, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r8;
    // 0x8019A128: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x8019A12C: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x8019A130: ori         $a0, $a0, 0x306C
    ctx->r4 = ctx->r4 | 0X306C;
    // 0x8019A134: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8019A138: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019A13C: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019A140: jal         0x80019218
    // 0x8019A144: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_13;
    // 0x8019A144: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_13:
    // 0x8019A148: b           L_8019A380
    // 0x8019A14C: lh          $t5, 0x56($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X56);
        goto L_8019A380;
    // 0x8019A14C: lh          $t5, 0x56($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X56);
    // 0x8019A150: lw          $a1, 0x104($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X104);
L_8019A154:
    // 0x8019A154: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8019A158: jal         0x8009BC2C
    // 0x8019A15C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8019A15C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_14:
    // 0x8019A160: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A164: lwc1        $f14, 0x7578($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7578);
    // 0x8019A168: lw          $a1, 0x10C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10C);
    // 0x8019A16C: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x8019A170: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8019A174: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x8019A178: jal         0x8009BC2C
    // 0x8019A17C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8019A17C: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_15:
    // 0x8019A180: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8019A184: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8019A188: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A18C: lwc1        $f14, 0x757C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X757C);
    // 0x8019A190: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019A194: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019A198: lwc1        $f10, 0x114($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X114);
    // 0x8019A19C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019A1A0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019A1A4: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8019A1A8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8019A1AC: nop

    // 0x8019A1B0: bc1fl       L_8019A1C8
    if (!c1cs) {
        // 0x8019A1B4: lwc1        $f6, 0x7C($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
            goto L_8019A1C8;
    }
    goto skip_14;
    // 0x8019A1B4: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    skip_14:
    // 0x8019A1B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019A1BC: nop

    // 0x8019A1C0: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8019A1C4: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
L_8019A1C8:
    // 0x8019A1C8: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8019A1CC: sub.s       $f2, $f6, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8019A1D0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8019A1D4: nop

    // 0x8019A1D8: bc1fl       L_8019A1F0
    if (!c1cs) {
        // 0x8019A1DC: lwc1        $f12, 0x128($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X128);
            goto L_8019A1F0;
    }
    goto skip_15;
    // 0x8019A1DC: lwc1        $f12, 0x128($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X128);
    skip_15:
    // 0x8019A1E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019A1E4: nop

    // 0x8019A1E8: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8019A1EC: lwc1        $f12, 0x128($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X128);
L_8019A1F0:
    // 0x8019A1F0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019A1F4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019A1F8: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8019A1FC: nop

    // 0x8019A200: bc1fl       L_8019A218
    if (!c1cs) {
        // 0x8019A204: sub.s       $f18, $f12, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_8019A218;
    }
    goto skip_16;
    // 0x8019A204: sub.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
    skip_16:
    // 0x8019A208: sub.s       $f10, $f12, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8019A20C: b           L_8019A220
    // 0x8019A210: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
        goto L_8019A220;
    // 0x8019A210: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8019A214: sub.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
L_8019A218:
    // 0x8019A218: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8019A21C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
L_8019A220:
    // 0x8019A220: lwc1        $f12, 0x120($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8019A224: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019A228: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x8019A22C: nop

    // 0x8019A230: bc1fl       L_8019A248
    if (!c1cs) {
        // 0x8019A234: sub.s       $f8, $f12, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_8019A248;
    }
    goto skip_17;
    // 0x8019A234: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    skip_17:
    // 0x8019A238: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8019A23C: b           L_8019A250
    // 0x8019A240: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
        goto L_8019A250;
    // 0x8019A240: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8019A244: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
L_8019A248:
    // 0x8019A248: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8019A24C: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
L_8019A250:
    // 0x8019A250: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8019A254: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x8019A258: nop

    // 0x8019A25C: bc1tl       L_8019A2D4
    if (c1cs) {
        // 0x8019A260: lh          $t3, 0xB4($s0)
        ctx->r11 = MEM_H(ctx->r16, 0XB4);
            goto L_8019A2D4;
    }
    goto skip_18;
    // 0x8019A260: lh          $t3, 0xB4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB4);
    skip_18:
    // 0x8019A264: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019A268: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019A26C: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8019A270: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8019A274: lui         $a1, 0x4335
    ctx->r5 = S32(0X4335 << 16);
    // 0x8019A278: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8019A27C: bc1tl       L_8019A2A0
    if (c1cs) {
        // 0x8019A280: mfc1        $a2, $f14
        ctx->r6 = (int32_t)ctx->f14.u32l;
            goto L_8019A2A0;
    }
    goto skip_19;
    // 0x8019A280: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    skip_19:
    // 0x8019A284: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019A288: nop

    // 0x8019A28C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8019A290: nop

    // 0x8019A294: bc1fl       L_8019A2B4
    if (!c1cs) {
        // 0x8019A298: mfc1        $a1, $f16
        ctx->r5 = (int32_t)ctx->f16.u32l;
            goto L_8019A2B4;
    }
    goto skip_20;
    // 0x8019A298: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    skip_20:
    // 0x8019A29C: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
L_8019A2A0:
    // 0x8019A2A0: jal         0x8009BD38
    // 0x8019A2A4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_16;
    // 0x8019A2A4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_16:
    // 0x8019A2A8: b           L_8019A360
    // 0x8019A2AC: nop

        goto L_8019A360;
    // 0x8019A2AC: nop

    // 0x8019A2B0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
L_8019A2B4:
    // 0x8019A2B4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8019A2B8: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8019A2BC: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8019A2C0: jal         0x8009BD38
    // 0x8019A2C4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_17;
    // 0x8019A2C4: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_17:
    // 0x8019A2C8: b           L_8019A360
    // 0x8019A2CC: nop

        goto L_8019A360;
    // 0x8019A2CC: nop

    // 0x8019A2D0: lh          $t3, 0xB4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB4);
L_8019A2D4:
    // 0x8019A2D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019A2D8: bne         $t3, $at, L_8019A360
    if (ctx->r11 != ctx->r1) {
        // 0x8019A2DC: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_8019A360;
    }
    // 0x8019A2DC: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019A2E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019A2E4: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019A2E8: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x8019A2EC: nop

    // 0x8019A2F0: bc1t        L_8019A310
    if (c1cs) {
        // 0x8019A2F4: nop
    
            goto L_8019A310;
    }
    // 0x8019A2F4: nop

    // 0x8019A2F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019A2FC: nop

    // 0x8019A300: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8019A304: nop

    // 0x8019A308: bc1f        L_8019A360
    if (!c1cs) {
        // 0x8019A30C: nop
    
            goto L_8019A360;
    }
    // 0x8019A30C: nop

L_8019A310:
    // 0x8019A310: jal         0x80004EB0
    // 0x8019A314: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_18;
    // 0x8019A314: nop

    after_18:
    // 0x8019A318: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A31C: lwc1        $f14, 0x7580($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7580);
    // 0x8019A320: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A324: lwc1        $f18, 0x7584($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7584);
    // 0x8019A328: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8019A32C: lui         $a1, 0x4335
    ctx->r5 = S32(0X4335 << 16);
    // 0x8019A330: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8019A334: lui         $a3, 0x40C0
    ctx->r7 = S32(0X40C0 << 16);
    // 0x8019A338: bc1f        L_8019A360
    if (!c1cs) {
        // 0x8019A33C: nop
    
            goto L_8019A360;
    }
    // 0x8019A33C: nop

    // 0x8019A340: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8019A344: jal         0x8009BD38
    // 0x8019A348: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_19;
    // 0x8019A348: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    after_19:
    // 0x8019A34C: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8019A350: sh          $t4, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r12;
    // 0x8019A354: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A358: lwc1        $f4, 0x7588($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7588);
    // 0x8019A35C: swc1        $f4, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f4.u32l;
L_8019A360:
    // 0x8019A360: jal         0x8019B5CC
    // 0x8019A364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019B5CC(rdram, ctx);
        goto after_20;
    // 0x8019A364: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8019A368: bne         $v0, $zero, L_8019A37C
    if (ctx->r2 != 0) {
        // 0x8019A36C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019A37C;
    }
    // 0x8019A36C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019A370: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8019A374: jal         0x8019C194
    // 0x8019A378: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    SectorY_8019C194(rdram, ctx);
        goto after_21;
    // 0x8019A378: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    after_21:
L_8019A37C:
    // 0x8019A37C: lh          $t5, 0x56($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X56);
L_8019A380:
    // 0x8019A380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019A384: bnel        $t5, $at, L_8019A424
    if (ctx->r13 != ctx->r1) {
        // 0x8019A388: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019A424;
    }
    goto skip_21;
    // 0x8019A388: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_21:
    // 0x8019A38C: jal         0x80004EB0
    // 0x8019A390: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x8019A390: nop

    after_22:
    // 0x8019A394: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A398: lwc1        $f6, 0x758C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X758C);
    // 0x8019A39C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019A3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019A3A4: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8019A3A8: nop

    // 0x8019A3AC: bc1f        L_8019A3C0
    if (!c1cs) {
        // 0x8019A3B0: nop
    
            goto L_8019A3C0;
    }
    // 0x8019A3B0: nop

    // 0x8019A3B4: jal         0x8019A82C
    // 0x8019A3B8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    SectorY_8019A82C(rdram, ctx);
        goto after_23;
    // 0x8019A3B8: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_23:
    // 0x8019A3BC: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
L_8019A3C0:
    // 0x8019A3C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A3C4: lwc1        $f8, 0x7590($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7590);
    // 0x8019A3C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019A3CC: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8019A3D0: nop

    // 0x8019A3D4: bc1f        L_8019A3E8
    if (!c1cs) {
        // 0x8019A3D8: nop
    
            goto L_8019A3E8;
    }
    // 0x8019A3D8: nop

    // 0x8019A3DC: jal         0x8019A434
    // 0x8019A3E0: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    SectorY_8019A434(rdram, ctx);
        goto after_24;
    // 0x8019A3E0: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_24:
    // 0x8019A3E4: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
L_8019A3E8:
    // 0x8019A3E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A3EC: lwc1        $f10, 0x7594($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7594);
    // 0x8019A3F0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019A3F4: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x8019A3F8: nop

    // 0x8019A3FC: bc1fl       L_8019A424
    if (!c1cs) {
        // 0x8019A400: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019A424;
    }
    goto skip_22;
    // 0x8019A400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_22:
    // 0x8019A404: lwc1        $f18, 0x7598($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7598);
    // 0x8019A408: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x8019A40C: nop

    // 0x8019A410: bc1fl       L_8019A424
    if (!c1cs) {
        // 0x8019A414: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019A424;
    }
    goto skip_23;
    // 0x8019A414: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_23:
    // 0x8019A418: jal         0x8019A640
    // 0x8019A41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_8019A640(rdram, ctx);
        goto after_25;
    // 0x8019A41C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x8019A420: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019A424:
    // 0x8019A424: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019A428: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8019A42C: jr          $ra
    // 0x8019A430: nop

    return;
    // 0x8019A430: nop

;}
RECOMP_FUNC void Andross_AndPassage_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019356C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80193570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80193574: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80193578: lwc1        $f8, 0x60($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X60);
    // 0x8019357C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80193580: lwc1        $f4, 0x7F68($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7F68);
    // 0x80193584: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80193588: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8019358C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193590: swc1        $f4, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f4.u32l;
    // 0x80193594: bne         $t6, $at, L_801935A4
    if (ctx->r14 != ctx->r1) {
        // 0x80193598: swc1        $f10, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
            goto L_801935A4;
    }
    // 0x80193598: swc1        $f10, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f10.u32l;
    // 0x8019359C: jal         0x80060FBC
    // 0x801935A0: addiu       $a1, $a0, 0x70
    ctx->r5 = ADD32(ctx->r4, 0X70);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x801935A0: addiu       $a1, $a0, 0x70
    ctx->r5 = ADD32(ctx->r4, 0X70);
    after_0:
L_801935A4:
    // 0x801935A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801935A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801935AC: jr          $ra
    // 0x801935B0: nop

    return;
    // 0x801935B0: nop

;}
RECOMP_FUNC void Andross_AndBrainWaste_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188528: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018852C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80188530: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80188534: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80188538: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018853C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80188540: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80188544: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188548: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8018854C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80188550: jal         0x8009BC2C
    // 0x80188554: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80188554: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80188558: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018855C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80188560: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188564: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80188568: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8018856C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80188570: jal         0x8009BC2C
    // 0x80188574: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80188574: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80188578: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018857C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80188580: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80188584: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80188588: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x8018858C: lui         $a3, 0x3F00
    ctx->r7 = S32(0X3F00 << 16);
    // 0x80188590: jal         0x8009BC2C
    // 0x80188594: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80188594: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80188598: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x8018859C: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    // 0x801885A0: lui         $a1, 0x2903
    ctx->r5 = S32(0X2903 << 16);
    // 0x801885A4: beql        $t6, $zero, L_801885E8
    if (ctx->r14 == 0) {
        // 0x801885A8: lhu         $t8, 0xBC($s0)
        ctx->r24 = MEM_HU(ctx->r16, 0XBC);
            goto L_801885E8;
    }
    goto skip_0;
    // 0x801885A8: lhu         $t8, 0xBC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XBC);
    skip_0:
    // 0x801885AC: jal         0x8007A6F0
    // 0x801885B0: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_3;
    // 0x801885B0: ori         $a1, $a1, 0xA008
    ctx->r5 = ctx->r5 | 0XA008;
    after_3:
    // 0x801885B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801885B8: jal         0x80060FBC
    // 0x801885BC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x801885BC: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_4:
    // 0x801885C0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801885C4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801885C8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x801885CC: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801885D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801885D4: jal         0x8007B344
    // 0x801885D8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_5;
    // 0x801885D8: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    after_5:
    // 0x801885DC: b           L_801885FC
    // 0x801885E0: nop

        goto L_801885FC;
    // 0x801885E0: nop

    // 0x801885E4: lhu         $t8, 0xBC($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XBC);
L_801885E8:
    // 0x801885E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801885EC: bne         $t8, $zero, L_801885FC
    if (ctx->r24 != 0) {
        // 0x801885F0: nop
    
            goto L_801885FC;
    }
    // 0x801885F0: nop

    // 0x801885F4: jal         0x80060FBC
    // 0x801885F8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x801885F8: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_6:
L_801885FC:
    // 0x801885FC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80188600: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x80188604: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80188608: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8018860C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80188610: lwc1        $f4, 0x58($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80188614: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80188618: lwc1        $f2, 0x6BE4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6BE4);
    // 0x8018861C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80188620: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80188624: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x80188628: div.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8018862C: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80188630: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80188634: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80188638: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018863C: lwc1        $f16, 0x5C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X5C);
    // 0x80188640: swc1        $f10, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f10.u32l;
    // 0x80188644: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80188648: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8018864C: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x80188650: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80188654: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80188658: jr          $ra
    // 0x8018865C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018865C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void SectorY_SyShogun_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C888: addiu       $sp, $sp, -0x1F0
    ctx->r29 = ADD32(ctx->r29, -0X1F0);
    // 0x8019C88C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019C890: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019C894: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019C898: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8019C89C: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8019C8A0: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8019C8A4: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x8019C8A8: beql        $t7, $at, L_8019DC3C
    if (ctx->r15 == ctx->r1) {
        // 0x8019C8AC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019DC3C;
    }
    goto skip_0;
    // 0x8019C8AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8019C8B0: lh          $t8, 0xCC($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XCC);
    // 0x8019C8B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019C8B8: bnel        $t8, $at, L_8019C918
    if (ctx->r24 != ctx->r1) {
        // 0x8019C8BC: lw          $t3, 0x40($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X40);
            goto L_8019C918;
    }
    goto skip_1;
    // 0x8019C8BC: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    skip_1:
    // 0x8019C8C0: lh          $t9, 0x60($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X60);
    // 0x8019C8C4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019C8C8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8019C8CC: blez        $t9, L_8019C8EC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8019C8D0: nop
    
            goto L_8019C8EC;
    }
    // 0x8019C8D0: nop

    // 0x8019C8D4: lw          $v0, -0x7D58($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D58);
    // 0x8019C8D8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019C8DC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C8E0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8019C8E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019C8E8: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
L_8019C8EC:
    // 0x8019C8EC: lw          $t0, -0x7D58($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D58);
    // 0x8019C8F0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019C8F4: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x8019C8F8: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x8019C8FC: nop

    // 0x8019C900: bc1fl       L_8019C918
    if (!c1cs) {
        // 0x8019C904: lw          $t3, 0x40($s0)
        ctx->r11 = MEM_W(ctx->r16, 0X40);
            goto L_8019C918;
    }
    goto skip_2;
    // 0x8019C904: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    skip_2:
    // 0x8019C908: lh          $t1, 0xCC($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XCC);
    // 0x8019C90C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8019C910: sh          $t2, 0xCC($s0)
    MEM_H(0XCC, ctx->r16) = ctx->r10;
    // 0x8019C914: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
L_8019C918:
    // 0x8019C918: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019C91C: bne         $t3, $at, L_8019CA20
    if (ctx->r11 != ctx->r1) {
        // 0x8019C920: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8019CA20;
    }
    // 0x8019C920: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019C924: lwc1        $f12, -0xAE4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0XAE4);
    // 0x8019C928: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019C92C: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x8019C930: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019C934: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8019C938: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019C93C: bc1fl       L_8019C950
    if (!c1cs) {
        // 0x8019C940: sub.s       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_8019C950;
    }
    goto skip_3;
    // 0x8019C940: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    skip_3:
    // 0x8019C944: b           L_8019C954
    // 0x8019C948: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
        goto L_8019C954;
    // 0x8019C948: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8019C94C: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
L_8019C950:
    // 0x8019C950: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8019C954:
    // 0x8019C954: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8019C958: nop

    // 0x8019C95C: bc1fl       L_8019CA24
    if (!c1cs) {
        // 0x8019C960: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8019CA24;
    }
    goto skip_4;
    // 0x8019C960: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_4:
    // 0x8019C964: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019C968: lwc1        $f2, -0xADC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0XADC);
    // 0x8019C96C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8019C970: nop

    // 0x8019C974: bc1fl       L_8019C988
    if (!c1cs) {
        // 0x8019C978: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8019C988;
    }
    goto skip_5;
    // 0x8019C978: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_5:
    // 0x8019C97C: b           L_8019C98C
    // 0x8019C980: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_8019C98C;
    // 0x8019C980: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8019C984: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_8019C988:
    // 0x8019C988: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_8019C98C:
    // 0x8019C98C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8019C990: nop

    // 0x8019C994: bc1fl       L_8019CA24
    if (!c1cs) {
        // 0x8019C998: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8019CA24;
    }
    goto skip_6;
    // 0x8019C998: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_6:
    // 0x8019C99C: lh          $t4, 0x60($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X60);
    // 0x8019C9A0: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8019C9A4: blezl       $t4, L_8019CA24
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8019C9A8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8019CA24;
    }
    goto skip_7;
    // 0x8019C9A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_7:
    // 0x8019C9AC: lh          $t5, -0xA88($t5)
    ctx->r13 = MEM_H(ctx->r13, -0XA88);
    // 0x8019C9B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019C9B4: blezl       $t5, L_8019CA24
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8019C9B8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8019CA24;
    }
    goto skip_8;
    // 0x8019C9B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_8:
    // 0x8019C9BC: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019C9C0: lwc1        $f12, -0xAE0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0XAE0);
    // 0x8019C9C4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019C9C8: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8019C9CC: nop

    // 0x8019C9D0: bc1fl       L_8019C9E4
    if (!c1cs) {
        // 0x8019C9D4: sub.s       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_8019C9E4;
    }
    goto skip_9;
    // 0x8019C9D4: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    skip_9:
    // 0x8019C9D8: b           L_8019C9E8
    // 0x8019C9DC: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
        goto L_8019C9E8;
    // 0x8019C9DC: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8019C9E0: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
L_8019C9E4:
    // 0x8019C9E4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8019C9E8:
    // 0x8019C9E8: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8019C9EC: nop

    // 0x8019C9F0: bc1fl       L_8019CA24
    if (!c1cs) {
        // 0x8019C9F4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8019CA24;
    }
    goto skip_10;
    // 0x8019C9F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_10:
    // 0x8019C9F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019C9FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019CA00: add.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x8019CA04: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8019CA08: lwc1        $f10, -0xAE0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XAE0);
    // 0x8019CA0C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019CA10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019CA14: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019CA18: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8019CA1C: swc1        $f6, -0xAE0($at)
    MEM_W(-0XAE0, ctx->r1) = ctx->f6.u32l;
L_8019CA20:
    // 0x8019CA20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8019CA24:
    // 0x8019CA24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019CA28: lwc1        $f0, 0x160($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X160);
    // 0x8019CA2C: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8019CA30: nop

    // 0x8019CA34: bc1f        L_8019CA5C
    if (!c1cs) {
        // 0x8019CA38: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_8019CA5C;
    }
    // 0x8019CA38: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019CA3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019CA40: nop

    // 0x8019CA44: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8019CA48: nop

    // 0x8019CA4C: bc1f        L_8019CA5C
    if (!c1cs) {
        // 0x8019CA50: nop
    
            goto L_8019CA5C;
    }
    // 0x8019CA50: nop

    // 0x8019CA54: jal         0x8001A500
    // 0x8019CA58: addiu       $a0, $s0, 0x3FC
    ctx->r4 = ADD32(ctx->r16, 0X3FC);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_0;
    // 0x8019CA58: addiu       $a0, $s0, 0x3FC
    ctx->r4 = ADD32(ctx->r16, 0X3FC);
    after_0:
L_8019CA5C:
    // 0x8019CA5C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019CA60: lw          $t6, 0x13A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13A0);
    // 0x8019CA64: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019CA68: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8019CA6C: sw          $t7, 0x13A0($at)
    MEM_W(0X13A0, ctx->r1) = ctx->r15;
    // 0x8019CA70: lh          $v0, 0xB8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB8);
    // 0x8019CA74: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CA78: lwc1        $f4, 0x7648($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7648);
    // 0x8019CA7C: beq         $v0, $zero, L_8019CA8C
    if (ctx->r2 == 0) {
        // 0x8019CA80: swc1        $f4, 0xD8($s0)
        MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
            goto L_8019CA8C;
    }
    // 0x8019CA80: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
    // 0x8019CA84: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8019CA88: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
L_8019CA8C:
    // 0x8019CA8C: lh          $t9, 0x60($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X60);
    // 0x8019CA90: blezl       $t9, L_8019CABC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8019CA94: lh          $t2, 0x58($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X58);
            goto L_8019CABC;
    }
    goto skip_11;
    // 0x8019CA94: lh          $t2, 0x58($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X58);
    skip_11:
    // 0x8019CA98: lh          $t0, 0xB0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XB0);
    // 0x8019CA9C: lui         $t9, 0x801A
    ctx->r25 = S32(0X801A << 16);
    // 0x8019CAA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019CAA4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8019CAA8: addu        $t9, $t9, $t1
    ctx->r25 = ADD32(ctx->r25, ctx->r9);
    // 0x8019CAAC: lw          $t9, 0x6910($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6910);
    // 0x8019CAB0: jalr        $t9
    // 0x8019CAB4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8019CAB4: nop

    after_1:
    // 0x8019CAB8: lh          $t2, 0x58($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X58);
L_8019CABC:
    // 0x8019CABC: beql        $t2, $zero, L_8019CAD0
    if (ctx->r10 == 0) {
        // 0x8019CAC0: lh          $v0, 0xC2($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XC2);
            goto L_8019CAD0;
    }
    goto skip_12;
    // 0x8019CAC0: lh          $v0, 0xC2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XC2);
    skip_12:
    // 0x8019CAC4: jal         0x80199438
    // 0x8019CAC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80199438(rdram, ctx);
        goto after_2;
    // 0x8019CAC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8019CACC: lh          $v0, 0xC2($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XC2);
L_8019CAD0:
    // 0x8019CAD0: beq         $v0, $zero, L_8019CB20
    if (ctx->r2 == 0) {
        // 0x8019CAD4: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_8019CB20;
    }
    // 0x8019CAD4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8019CAD8: lw          $t3, 0x7DB0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7DB0);
    // 0x8019CADC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CAE0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8019CAE4: and         $t4, $v0, $t3
    ctx->r12 = ctx->r2 & ctx->r11;
    // 0x8019CAE8: bnel        $t4, $zero, L_8019CB24
    if (ctx->r12 != 0) {
        // 0x8019CAEC: lhu         $t6, 0xB2($s0)
        ctx->r14 = MEM_HU(ctx->r16, 0XB2);
            goto L_8019CB24;
    }
    goto skip_13;
    // 0x8019CAEC: lhu         $t6, 0xB2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XB2);
    skip_13:
    // 0x8019CAF0: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8019CAF4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019CAF8: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019CAFC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8019CB00: lw          $a3, 0x6C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X6C);
    // 0x8019CB04: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019CB08: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x8019CB0C: lwc1        $f10, 0x764C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X764C);
    // 0x8019CB10: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8019CB14: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8019CB18: jal         0x8007C120
    // 0x8019CB1C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_3;
    // 0x8019CB1C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_3:
L_8019CB20:
    // 0x8019CB20: lhu         $t6, 0xB2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XB2);
L_8019CB24:
    // 0x8019CB24: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8019CB28: beq         $at, $zero, L_8019CD84
    if (ctx->r1 == 0) {
        // 0x8019CB2C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8019CD84;
    }
    // 0x8019CB2C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8019CB30: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CB34: addu        $at, $at, $t6
    gpr jr_addend_8019CB3C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8019CB38: lw          $t6, 0x7650($at)
    ctx->r14 = ADD32(ctx->r1, 0X7650);
    // 0x8019CB3C: jr          $t6
    // 0x8019CB40: nop

    switch (jr_addend_8019CB3C >> 2) {
        case 0: goto L_8019CB44; break;
        case 1: goto L_8019CB74; break;
        case 2: goto L_8019CBA4; break;
        case 3: goto L_8019CBD4; break;
        case 4: goto L_8019CC04; break;
        case 5: goto L_8019CC5C; break;
        case 6: goto L_8019CCA4; break;
        case 7: goto L_8019CCC0; break;
        case 8: goto L_8019CD00; break;
        case 9: goto L_8019CD40; break;
        default: switch_error(__func__, 0x8019CB3C, 0x801A7650);
    }
    // 0x8019CB40: nop

L_8019CB44:
    // 0x8019CB44: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8019CB48: jal         0x8009ACDC
    // 0x8019CB4C: addiu       $a0, $a0, -0x4888
    ctx->r4 = ADD32(ctx->r4, -0X4888);
    Animation_GetFrameCount(rdram, ctx);
        goto after_4;
    // 0x8019CB4C: addiu       $a0, $a0, -0x4888
    ctx->r4 = ADD32(ctx->r4, -0X4888);
    after_4:
    // 0x8019CB50: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8019CB54: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    // 0x8019CB58: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8019CB5C: addiu       $a0, $a0, -0x4888
    ctx->r4 = ADD32(ctx->r4, -0X4888);
    // 0x8019CB60: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CB64: jal         0x8009AA20
    // 0x8019CB68: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_5;
    // 0x8019CB68: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_5:
    // 0x8019CB6C: b           L_8019CD84
    // 0x8019CB70: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CB70: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CB74:
    // 0x8019CB74: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CB78: jal         0x8009ACDC
    // 0x8019CB7C: addiu       $a0, $a0, 0x65B4
    ctx->r4 = ADD32(ctx->r4, 0X65B4);
    Animation_GetFrameCount(rdram, ctx);
        goto after_6;
    // 0x8019CB7C: addiu       $a0, $a0, 0x65B4
    ctx->r4 = ADD32(ctx->r4, 0X65B4);
    after_6:
    // 0x8019CB80: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8019CB84: sh          $t8, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r24;
    // 0x8019CB88: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CB8C: addiu       $a0, $a0, 0x65B4
    ctx->r4 = ADD32(ctx->r4, 0X65B4);
    // 0x8019CB90: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CB94: jal         0x8009AA20
    // 0x8019CB98: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_7;
    // 0x8019CB98: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_7:
    // 0x8019CB9C: b           L_8019CD84
    // 0x8019CBA0: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CBA0: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CBA4:
    // 0x8019CBA4: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8019CBA8: jal         0x8009ACDC
    // 0x8019CBAC: addiu       $a0, $a0, -0x64B8
    ctx->r4 = ADD32(ctx->r4, -0X64B8);
    Animation_GetFrameCount(rdram, ctx);
        goto after_8;
    // 0x8019CBAC: addiu       $a0, $a0, -0x64B8
    ctx->r4 = ADD32(ctx->r4, -0X64B8);
    after_8:
    // 0x8019CBB0: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8019CBB4: sh          $t0, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r8;
    // 0x8019CBB8: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8019CBBC: addiu       $a0, $a0, -0x64B8
    ctx->r4 = ADD32(ctx->r4, -0X64B8);
    // 0x8019CBC0: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CBC4: jal         0x8009AA20
    // 0x8019CBC8: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_9;
    // 0x8019CBC8: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_9:
    // 0x8019CBCC: b           L_8019CD84
    // 0x8019CBD0: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CBD0: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CBD4:
    // 0x8019CBD4: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8019CBD8: jal         0x8009ACDC
    // 0x8019CBDC: addiu       $a0, $a0, -0x4724
    ctx->r4 = ADD32(ctx->r4, -0X4724);
    Animation_GetFrameCount(rdram, ctx);
        goto after_10;
    // 0x8019CBDC: addiu       $a0, $a0, -0x4724
    ctx->r4 = ADD32(ctx->r4, -0X4724);
    after_10:
    // 0x8019CBE0: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x8019CBE4: sh          $t1, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r9;
    // 0x8019CBE8: lui         $a0, 0x603
    ctx->r4 = S32(0X603 << 16);
    // 0x8019CBEC: addiu       $a0, $a0, -0x4724
    ctx->r4 = ADD32(ctx->r4, -0X4724);
    // 0x8019CBF0: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CBF4: jal         0x8009AA20
    // 0x8019CBF8: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_11;
    // 0x8019CBF8: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_11:
    // 0x8019CBFC: b           L_8019CD84
    // 0x8019CC00: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CC00: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CC04:
    // 0x8019CC04: lh          $t9, 0x4C($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CC08: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x8019CC0C: addiu       $a0, $a0, 0x3348
    ctx->r4 = ADD32(ctx->r4, 0X3348);
    // 0x8019CC10: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x8019CC14: jal         0x8009ACDC
    // 0x8019CC18: sh          $t2, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r10;
    Animation_GetFrameCount(rdram, ctx);
        goto after_12;
    // 0x8019CC18: sh          $t2, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r10;
    after_12:
    // 0x8019CC1C: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CC20: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x8019CC24: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019CC28: bne         $at, $zero, L_8019CC44
    if (ctx->r1 != 0) {
        // 0x8019CC2C: nop
    
            goto L_8019CC44;
    }
    // 0x8019CC2C: nop

    // 0x8019CC30: jal         0x8009ACDC
    // 0x8019CC34: addiu       $a0, $a0, 0x3348
    ctx->r4 = ADD32(ctx->r4, 0X3348);
    Animation_GetFrameCount(rdram, ctx);
        goto after_13;
    // 0x8019CC34: addiu       $a0, $a0, 0x3348
    ctx->r4 = ADD32(ctx->r4, 0X3348);
    after_13:
    // 0x8019CC38: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8019CC3C: sh          $t3, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r11;
    // 0x8019CC40: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
L_8019CC44:
    // 0x8019CC44: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x8019CC48: addiu       $a0, $a0, 0x3348
    ctx->r4 = ADD32(ctx->r4, 0X3348);
    // 0x8019CC4C: jal         0x8009AA20
    // 0x8019CC50: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_14;
    // 0x8019CC50: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_14:
    // 0x8019CC54: b           L_8019CD84
    // 0x8019CC58: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CC58: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CC5C:
    // 0x8019CC5C: lh          $t4, 0x4C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CC60: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CC64: addiu       $a0, $a0, 0x738C
    ctx->r4 = ADD32(ctx->r4, 0X738C);
    // 0x8019CC68: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8019CC6C: jal         0x8009ACDC
    // 0x8019CC70: sh          $t5, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r13;
    Animation_GetFrameCount(rdram, ctx);
        goto after_15;
    // 0x8019CC70: sh          $t5, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r13;
    after_15:
    // 0x8019CC74: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CC78: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CC7C: addiu       $a0, $a0, 0x738C
    ctx->r4 = ADD32(ctx->r4, 0X738C);
    // 0x8019CC80: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019CC84: bne         $at, $zero, L_8019CC94
    if (ctx->r1 != 0) {
        // 0x8019CC88: nop
    
            goto L_8019CC94;
    }
    // 0x8019CC88: nop

    // 0x8019CC8C: sh          $zero, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = 0;
    // 0x8019CC90: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
L_8019CC94:
    // 0x8019CC94: jal         0x8009AA20
    // 0x8019CC98: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_16;
    // 0x8019CC98: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_16:
    // 0x8019CC9C: b           L_8019CD84
    // 0x8019CCA0: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CCA0: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CCA4:
    // 0x8019CCA4: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CCA8: addiu       $a0, $a0, 0x738C
    ctx->r4 = ADD32(ctx->r4, 0X738C);
    // 0x8019CCAC: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CCB0: jal         0x8009AA20
    // 0x8019CCB4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_17;
    // 0x8019CCB4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_17:
    // 0x8019CCB8: b           L_8019CD84
    // 0x8019CCBC: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CCBC: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CCC0:
    // 0x8019CCC0: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CCC4: jal         0x8009ACDC
    // 0x8019CCC8: addiu       $a0, $a0, 0x645C
    ctx->r4 = ADD32(ctx->r4, 0X645C);
    Animation_GetFrameCount(rdram, ctx);
        goto after_18;
    // 0x8019CCC8: addiu       $a0, $a0, 0x645C
    ctx->r4 = ADD32(ctx->r4, 0X645C);
    after_18:
    // 0x8019CCCC: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CCD0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8019CCD4: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CCD8: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8019CCDC: beq         $at, $zero, L_8019CCF0
    if (ctx->r1 == 0) {
        // 0x8019CCE0: addiu       $a0, $a0, 0x645C
        ctx->r4 = ADD32(ctx->r4, 0X645C);
            goto L_8019CCF0;
    }
    // 0x8019CCE0: addiu       $a0, $a0, 0x645C
    ctx->r4 = ADD32(ctx->r4, 0X645C);
    // 0x8019CCE4: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x8019CCE8: sh          $t7, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r15;
    // 0x8019CCEC: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
L_8019CCF0:
    // 0x8019CCF0: jal         0x8009AA20
    // 0x8019CCF4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_19;
    // 0x8019CCF4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_19:
    // 0x8019CCF8: b           L_8019CD84
    // 0x8019CCFC: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CCFC: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CD00:
    // 0x8019CD00: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CD04: jal         0x8009ACDC
    // 0x8019CD08: addiu       $a0, $a0, 0x58A0
    ctx->r4 = ADD32(ctx->r4, 0X58A0);
    Animation_GetFrameCount(rdram, ctx);
        goto after_20;
    // 0x8019CD08: addiu       $a0, $a0, 0x58A0
    ctx->r4 = ADD32(ctx->r4, 0X58A0);
    after_20:
    // 0x8019CD0C: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CD10: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8019CD14: lui         $a0, 0x602
    ctx->r4 = S32(0X602 << 16);
    // 0x8019CD18: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8019CD1C: beq         $at, $zero, L_8019CD30
    if (ctx->r1 == 0) {
        // 0x8019CD20: addiu       $a0, $a0, 0x58A0
        ctx->r4 = ADD32(ctx->r4, 0X58A0);
            goto L_8019CD30;
    }
    // 0x8019CD20: addiu       $a0, $a0, 0x58A0
    ctx->r4 = ADD32(ctx->r4, 0X58A0);
    // 0x8019CD24: addiu       $t0, $a1, 0x1
    ctx->r8 = ADD32(ctx->r5, 0X1);
    // 0x8019CD28: sh          $t0, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r8;
    // 0x8019CD2C: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
L_8019CD30:
    // 0x8019CD30: jal         0x8009AA20
    // 0x8019CD34: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_21;
    // 0x8019CD34: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_21:
    // 0x8019CD38: b           L_8019CD84
    // 0x8019CD3C: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
        goto L_8019CD84;
    // 0x8019CD3C: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CD40:
    // 0x8019CD40: lh          $t1, 0x4C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CD44: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x8019CD48: addiu       $a0, $a0, 0x34C4
    ctx->r4 = ADD32(ctx->r4, 0X34C4);
    // 0x8019CD4C: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x8019CD50: jal         0x8009ACDC
    // 0x8019CD54: sh          $t9, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r25;
    Animation_GetFrameCount(rdram, ctx);
        goto after_22;
    // 0x8019CD54: sh          $t9, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = ctx->r25;
    after_22:
    // 0x8019CD58: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
    // 0x8019CD5C: lui         $a0, 0x600
    ctx->r4 = S32(0X600 << 16);
    // 0x8019CD60: addiu       $a0, $a0, 0x34C4
    ctx->r4 = ADD32(ctx->r4, 0X34C4);
    // 0x8019CD64: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019CD68: bne         $at, $zero, L_8019CD78
    if (ctx->r1 != 0) {
        // 0x8019CD6C: nop
    
            goto L_8019CD78;
    }
    // 0x8019CD6C: nop

    // 0x8019CD70: sh          $zero, 0x4C($s0)
    MEM_H(0X4C, ctx->r16) = 0;
    // 0x8019CD74: lh          $a1, 0x4C($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X4C);
L_8019CD78:
    // 0x8019CD78: jal         0x8009AA20
    // 0x8019CD7C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    Animation_GetFrameData(rdram, ctx);
        goto after_23;
    // 0x8019CD7C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_23:
    // 0x8019CD80: sw          $v0, 0x1D0($sp)
    MEM_W(0X1D0, ctx->r29) = ctx->r2;
L_8019CD84:
    // 0x8019CD84: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8019CD88: lwc1        $f6, 0x7C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019CD8C: lwc1        $f8, 0x80($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X80);
    // 0x8019CD90: lwc1        $f10, 0x304($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X304);
    // 0x8019CD94: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CD98: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x8019CD9C: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8019CDA0: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x8019CDA4: lwc1        $f6, 0x7678($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7678);
    // 0x8019CDA8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8019CDAC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CDB0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019CDB4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019CDB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019CDBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019CDC0: jal         0x80005FE0
    // 0x8019CDC4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_24;
    // 0x8019CDC4: nop

    after_24:
    // 0x8019CDC8: lwc1        $f10, 0x2FC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2FC);
    // 0x8019CDCC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CDD0: lwc1        $f6, 0x767C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X767C);
    // 0x8019CDD4: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8019CDD8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CDDC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019CDE0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019CDE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019CDE8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019CDEC: jal         0x80005D44
    // 0x8019CDF0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_25;
    // 0x8019CDF0: nop

    after_25:
    // 0x8019CDF4: lwc1        $f10, 0x300($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X300);
    // 0x8019CDF8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CDFC: lwc1        $f6, 0x7680($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7680);
    // 0x8019CE00: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8019CE04: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CE08: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019CE0C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019CE10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019CE14: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019CE18: jal         0x80005E90
    // 0x8019CE1C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_26;
    // 0x8019CE1C: nop

    after_26:
    // 0x8019CE20: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019CE24: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CE28: lwc1        $f6, 0x7684($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7684);
    // 0x8019CE2C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8019CE30: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CE34: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019CE38: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019CE3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019CE40: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019CE44: jal         0x80005FE0
    // 0x8019CE48: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_27;
    // 0x8019CE48: nop

    after_27:
    // 0x8019CE4C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8019CE50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CE54: lwc1        $f6, 0x7688($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7688);
    // 0x8019CE58: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8019CE5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CE60: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019CE64: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019CE68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019CE6C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019CE70: jal         0x80005D44
    // 0x8019CE74: nop

    Matrix_RotateX(rdram, ctx);
        goto after_28;
    // 0x8019CE74: nop

    after_28:
    // 0x8019CE78: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019CE7C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CE80: lwc1        $f6, 0x768C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X768C);
    // 0x8019CE84: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8019CE88: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CE8C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019CE90: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019CE94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019CE98: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019CE9C: jal         0x80005E90
    // 0x8019CEA0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_29;
    // 0x8019CEA0: nop

    after_29:
    // 0x8019CEA4: lh          $t2, 0x60($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X60);
    // 0x8019CEA8: blez        $t2, L_8019D674
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8019CEAC: nop
    
            goto L_8019D674;
    }
    // 0x8019CEAC: nop

    // 0x8019CEB0: lh          $t3, 0xB0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XB0);
    // 0x8019CEB4: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x8019CEB8: beq         $at, $zero, L_8019D674
    if (ctx->r1 == 0) {
        // 0x8019CEBC: nop
    
            goto L_8019D674;
    }
    // 0x8019CEBC: nop

    // 0x8019CEC0: lwc1        $f10, 0x120($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8019CEC4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019CEC8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019CECC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019CED0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8019CED4: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8019CED8: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8019CEDC: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8019CEE0: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019CEE4: lwc1        $f8, 0x124($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8019CEE8: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019CEEC: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x8019CEF0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019CEF4: lwc1        $f6, 0x128($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X128);
    // 0x8019CEF8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019CEFC: jal         0x80006A20
    // 0x8019CF00: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_30;
    // 0x8019CF00: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_30:
    // 0x8019CF04: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019CF08: jal         0x80005100
    // 0x8019CF0C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    Math_Atan2F(rdram, ctx);
        goto after_31;
    // 0x8019CF0C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_31:
    // 0x8019CF10: jal         0x8009F768
    // 0x8019CF14: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_32;
    // 0x8019CF14: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_32:
    // 0x8019CF18: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019CF1C: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019CF20: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019CF24: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8019CF28: swc1        $f2, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->f2.u32l;
    // 0x8019CF2C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019CF30: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019CF34: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019CF38: jal         0x80005100
    // 0x8019CF3C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_33;
    // 0x8019CF3C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_33:
    // 0x8019CF40: jal         0x8009F768
    // 0x8019CF44: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_34;
    // 0x8019CF44: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_34:
    // 0x8019CF48: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019CF4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019CF50: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019CF54: lwc1        $f2, 0x1E4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1E4);
    // 0x8019CF58: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x8019CF5C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019CF60: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019CF64: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x8019CF68: bc1f        L_8019CF90
    if (!c1cs) {
        // 0x8019CF6C: lui         $a3, 0x4080
        ctx->r7 = S32(0X4080 << 16);
            goto L_8019CF90;
    }
    // 0x8019CF6C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019CF70: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019CF74: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019CF78: nop

    // 0x8019CF7C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8019CF80: nop

    // 0x8019CF84: bc1fl       L_8019CF94
    if (!c1cs) {
        // 0x8019CF88: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8019CF94;
    }
    goto skip_14;
    // 0x8019CF88: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_14:
    // 0x8019CF8C: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
L_8019CF90:
    // 0x8019CF90: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8019CF94:
    // 0x8019CF94: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019CF98: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8019CF9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019CFA0: nop

    // 0x8019CFA4: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8019CFA8: nop

    // 0x8019CFAC: bc1fl       L_8019CFD0
    if (!c1cs) {
        // 0x8019CFB0: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_8019CFD0;
    }
    goto skip_15;
    // 0x8019CFB0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_15:
    // 0x8019CFB4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8019CFB8: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    // 0x8019CFBC: bc1fl       L_8019CFD0
    if (!c1cs) {
        // 0x8019CFC0: lui         $at, 0x42A0
        ctx->r1 = S32(0X42A0 << 16);
            goto L_8019CFD0;
    }
    goto skip_16;
    // 0x8019CFC0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    skip_16:
    // 0x8019CFC4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019CFC8: nop

    // 0x8019CFCC: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
L_8019CFD0:
    // 0x8019CFD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019CFD4: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019CFD8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019CFDC: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x8019CFE0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019CFE4: bc1fl       L_8019D004
    if (!c1cs) {
        // 0x8019CFE8: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8019D004;
    }
    goto skip_17;
    // 0x8019CFE8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_17:
    // 0x8019CFEC: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x8019CFF0: nop

    // 0x8019CFF4: bc1fl       L_8019D004
    if (!c1cs) {
        // 0x8019CFF8: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8019D004;
    }
    goto skip_18;
    // 0x8019CFF8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_18:
    // 0x8019CFFC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8019D000: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8019D004:
    // 0x8019D004: nop

    // 0x8019D008: bc1f        L_8019D024
    if (!c1cs) {
        // 0x8019D00C: nop
    
            goto L_8019D024;
    }
    // 0x8019D00C: nop

    // 0x8019D010: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8019D014: nop

    // 0x8019D018: bc1f        L_8019D024
    if (!c1cs) {
        // 0x8019D01C: nop
    
            goto L_8019D024;
    }
    // 0x8019D01C: nop

    // 0x8019D020: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8019D024:
    // 0x8019D024: lwc1        $f10, 0x7690($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7690);
    // 0x8019D028: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8019D02C: swc1        $f12, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->f12.u32l;
    // 0x8019D030: jal         0x8009BD38
    // 0x8019D034: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_35;
    // 0x8019D034: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_35:
    // 0x8019D038: lwc1        $f12, 0x1E8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x8019D03C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D040: lwc1        $f4, 0x7694($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7694);
    // 0x8019D044: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D048: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019D04C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D050: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8019D054: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019D058: jal         0x8009BD38
    // 0x8019D05C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_36;
    // 0x8019D05C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_36:
    // 0x8019D060: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x8019D064: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D068: lwc1        $f10, 0x7698($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7698);
    // 0x8019D06C: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8019D070: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D074: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019D078: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019D07C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019D080: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019D084: jal         0x80005D44
    // 0x8019D088: nop

    Matrix_RotateX(rdram, ctx);
        goto after_37;
    // 0x8019D088: nop

    after_37:
    // 0x8019D08C: lwc1        $f6, 0xF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x8019D090: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D094: lwc1        $f10, 0x769C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X769C);
    // 0x8019D098: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8019D09C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D0A0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8019D0A4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019D0A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019D0AC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019D0B0: jal         0x80005E90
    // 0x8019D0B4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_38;
    // 0x8019D0B4: nop

    after_38:
    // 0x8019D0B8: lwc1        $f6, 0x120($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8019D0BC: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D0C0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8019D0C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D0C8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019D0CC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019D0D0: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8019D0D4: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8019D0D8: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x8019D0DC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D0E0: lwc1        $f4, 0x124($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8019D0E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D0E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019D0EC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019D0F0: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x8019D0F4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D0F8: lwc1        $f6, 0x128($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X128);
    // 0x8019D0FC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019D100: jal         0x80006A20
    // 0x8019D104: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_39;
    // 0x8019D104: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_39:
    // 0x8019D108: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019D10C: jal         0x80005100
    // 0x8019D110: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    Math_Atan2F(rdram, ctx);
        goto after_40;
    // 0x8019D110: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_40:
    // 0x8019D114: jal         0x8009F768
    // 0x8019D118: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_41;
    // 0x8019D118: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_41:
    // 0x8019D11C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019D120: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019D124: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019D128: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8019D12C: swc1        $f2, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->f2.u32l;
    // 0x8019D130: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019D134: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019D138: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019D13C: jal         0x80005100
    // 0x8019D140: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_42;
    // 0x8019D140: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_42:
    // 0x8019D144: jal         0x8009F768
    // 0x8019D148: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_43;
    // 0x8019D148: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_43:
    // 0x8019D14C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019D150: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D154: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8019D158: lwc1        $f2, 0x1E0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1E0);
    // 0x8019D15C: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8019D160: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019D164: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D168: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8019D16C: bc1f        L_8019D194
    if (!c1cs) {
        // 0x8019D170: lui         $a3, 0x4100
        ctx->r7 = S32(0X4100 << 16);
            goto L_8019D194;
    }
    // 0x8019D170: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8019D174: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019D178: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019D17C: nop

    // 0x8019D180: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8019D184: nop

    // 0x8019D188: bc1fl       L_8019D198
    if (!c1cs) {
        // 0x8019D18C: lui         $at, 0x43A5
        ctx->r1 = S32(0X43A5 << 16);
            goto L_8019D198;
    }
    goto skip_19;
    // 0x8019D18C: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
    skip_19:
    // 0x8019D190: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8019D194:
    // 0x8019D194: lui         $at, 0x43A5
    ctx->r1 = S32(0X43A5 << 16);
L_8019D198:
    // 0x8019D198: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019D19C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019D1A0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019D1A4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8019D1A8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019D1AC: bc1fl       L_8019D1CC
    if (!c1cs) {
        // 0x8019D1B0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8019D1CC;
    }
    goto skip_20;
    // 0x8019D1B0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_20:
    // 0x8019D1B4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8019D1B8: nop

    // 0x8019D1BC: bc1fl       L_8019D1CC
    if (!c1cs) {
        // 0x8019D1C0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8019D1CC;
    }
    goto skip_21;
    // 0x8019D1C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_21:
    // 0x8019D1C4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019D1C8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8019D1CC:
    // 0x8019D1CC: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8019D1D0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D1D4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8019D1D8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D1DC: bc1fl       L_8019D1FC
    if (!c1cs) {
        // 0x8019D1E0: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8019D1FC;
    }
    goto skip_22;
    // 0x8019D1E0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_22:
    // 0x8019D1E4: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x8019D1E8: nop

    // 0x8019D1EC: bc1fl       L_8019D1FC
    if (!c1cs) {
        // 0x8019D1F0: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8019D1FC;
    }
    goto skip_23;
    // 0x8019D1F0: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_23:
    // 0x8019D1F4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019D1F8: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_8019D1FC:
    // 0x8019D1FC: nop

    // 0x8019D200: bc1f        L_8019D21C
    if (!c1cs) {
        // 0x8019D204: nop
    
            goto L_8019D21C;
    }
    // 0x8019D204: nop

    // 0x8019D208: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8019D20C: nop

    // 0x8019D210: bc1f        L_8019D21C
    if (!c1cs) {
        // 0x8019D214: nop
    
            goto L_8019D21C;
    }
    // 0x8019D214: nop

    // 0x8019D218: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8019D21C:
    // 0x8019D21C: lwc1        $f8, 0x76A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76A0);
    // 0x8019D220: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8019D224: swc1        $f12, 0x1DC($sp)
    MEM_W(0X1DC, ctx->r29) = ctx->f12.u32l;
    // 0x8019D228: jal         0x8009BD38
    // 0x8019D22C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_44;
    // 0x8019D22C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_44:
    // 0x8019D230: lwc1        $f12, 0x1DC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1DC);
    // 0x8019D234: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D238: lwc1        $f10, 0x76A4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76A4);
    // 0x8019D23C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8019D240: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019D244: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D248: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x8019D24C: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8019D250: jal         0x8009BD38
    // 0x8019D254: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_45;
    // 0x8019D254: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_45:
    // 0x8019D258: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D25C: lwc1        $f6, 0x76A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76A8);
    // 0x8019D260: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019D264: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8019D268: jal         0x80023250
    // 0x8019D26C: nop

    __cosf_recomp(rdram, ctx);
        goto after_46;
    // 0x8019D26C: nop

    after_46:
    // 0x8019D270: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8019D274: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D278: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019D27C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019D280: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019D284: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019D288: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8019D28C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D290: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019D294: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8019D298: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8019D29C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019D2A0: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x8019D2A4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D2A8: lwc1        $f6, 0x124($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8019D2AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019D2B0: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019D2B4: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8019D2B8: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x8019D2BC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D2C0: lwc1        $f8, 0x128($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X128);
    // 0x8019D2C4: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8019D2C8: jal         0x80006A20
    // 0x8019D2CC: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_47;
    // 0x8019D2CC: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_47:
    // 0x8019D2D0: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019D2D4: jal         0x80005100
    // 0x8019D2D8: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    Math_Atan2F(rdram, ctx);
        goto after_48;
    // 0x8019D2D8: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_48:
    // 0x8019D2DC: jal         0x8009F768
    // 0x8019D2E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_49;
    // 0x8019D2E0: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_49:
    // 0x8019D2E4: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019D2E8: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019D2EC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019D2F0: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8019D2F4: swc1        $f2, 0x1D8($sp)
    MEM_W(0X1D8, ctx->r29) = ctx->f2.u32l;
    // 0x8019D2F8: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019D2FC: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019D300: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019D304: jal         0x80005100
    // 0x8019D308: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_50;
    // 0x8019D308: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_50:
    // 0x8019D30C: jal         0x8009F768
    // 0x8019D310: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_51;
    // 0x8019D310: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_51:
    // 0x8019D314: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019D318: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D31C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D320: lwc1        $f2, 0x1D8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1D8);
    // 0x8019D324: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8019D328: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019D32C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D330: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019D334: bc1f        L_8019D360
    if (!c1cs) {
        // 0x8019D338: lui         $a3, 0x4080
        ctx->r7 = S32(0X4080 << 16);
            goto L_8019D360;
    }
    // 0x8019D338: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019D33C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019D340: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019D344: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019D348: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8019D34C: nop

    // 0x8019D350: bc1fl       L_8019D364
    if (!c1cs) {
        // 0x8019D354: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8019D364;
    }
    goto skip_24;
    // 0x8019D354: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_24:
    // 0x8019D358: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019D35C: nop

L_8019D360:
    // 0x8019D360: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8019D364:
    // 0x8019D364: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019D368: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8019D36C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019D370: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8019D374: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019D378: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x8019D37C: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x8019D380: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019D384: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D388: bc1fl       L_8019D3A8
    if (!c1cs) {
        // 0x8019D38C: c.lt.s      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
            goto L_8019D3A8;
    }
    goto skip_25;
    // 0x8019D38C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    skip_25:
    // 0x8019D390: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8019D394: nop

    // 0x8019D398: bc1fl       L_8019D3A8
    if (!c1cs) {
        // 0x8019D39C: c.lt.s      $f16, $f2
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
            goto L_8019D3A8;
    }
    goto skip_26;
    // 0x8019D39C: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    skip_26:
    // 0x8019D3A0: mov.s       $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    ctx->f12.fl = ctx->f18.fl;
    // 0x8019D3A4: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
L_8019D3A8:
    // 0x8019D3A8: nop

    // 0x8019D3AC: bc1fl       L_8019D3CC
    if (!c1cs) {
        // 0x8019D3B0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8019D3CC;
    }
    goto skip_27;
    // 0x8019D3B0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_27:
    // 0x8019D3B4: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x8019D3B8: nop

    // 0x8019D3BC: bc1fl       L_8019D3CC
    if (!c1cs) {
        // 0x8019D3C0: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8019D3CC;
    }
    goto skip_28;
    // 0x8019D3C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_28:
    // 0x8019D3C4: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8019D3C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8019D3CC:
    // 0x8019D3CC: nop

    // 0x8019D3D0: bc1f        L_8019D3EC
    if (!c1cs) {
        // 0x8019D3D4: nop
    
            goto L_8019D3EC;
    }
    // 0x8019D3D4: nop

    // 0x8019D3D8: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8019D3DC: nop

    // 0x8019D3E0: bc1f        L_8019D3EC
    if (!c1cs) {
        // 0x8019D3E4: nop
    
            goto L_8019D3EC;
    }
    // 0x8019D3E4: nop

    // 0x8019D3E8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8019D3EC:
    // 0x8019D3EC: lwc1        $f10, 0x76AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76AC);
    // 0x8019D3F0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8019D3F4: swc1        $f12, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->f12.u32l;
    // 0x8019D3F8: jal         0x8009BD38
    // 0x8019D3FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_52;
    // 0x8019D3FC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_52:
    // 0x8019D400: lwc1        $f12, 0x1D4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1D4);
    // 0x8019D404: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D408: lwc1        $f6, 0x76B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76B0);
    // 0x8019D40C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D410: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019D414: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D418: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x8019D41C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019D420: jal         0x8009BD38
    // 0x8019D424: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_53;
    // 0x8019D424: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_53:
    // 0x8019D428: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x8019D42C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D430: lwc1        $f10, 0x76B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76B4);
    // 0x8019D434: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8019D438: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D43C: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8019D440: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019D444: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019D448: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019D44C: jal         0x80005D44
    // 0x8019D450: nop

    Matrix_RotateX(rdram, ctx);
        goto after_54;
    // 0x8019D450: nop

    after_54:
    // 0x8019D454: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x8019D458: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D45C: lwc1        $f10, 0x76B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76B8);
    // 0x8019D460: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8019D464: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D468: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8019D46C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019D470: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019D474: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8019D478: jal         0x80005E90
    // 0x8019D47C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_55;
    // 0x8019D47C: nop

    after_55:
    // 0x8019D480: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x8019D484: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D488: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D48C: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8019D490: lwc1        $f8, 0x76BC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76BC);
    // 0x8019D494: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x8019D498: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8019D49C: mul.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8019D4A0: jal         0x80023250
    // 0x8019D4A4: nop

    __cosf_recomp(rdram, ctx);
        goto after_56;
    // 0x8019D4A4: nop

    after_56:
    // 0x8019D4A8: lwc1        $f4, 0x124($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X124);
    // 0x8019D4AC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D4B0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8019D4B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019D4B8: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8019D4BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D4C0: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8019D4C4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019D4C8: lwc1        $f4, 0x76C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X76C0);
    // 0x8019D4CC: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x8019D4D0: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8019D4D4: mul.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8019D4D8: jal         0x80023250
    // 0x8019D4DC: nop

    __cosf_recomp(rdram, ctx);
        goto after_57;
    // 0x8019D4DC: nop

    after_57:
    // 0x8019D4E0: lwc1        $f6, 0x128($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X128);
    // 0x8019D4E4: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D4E8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8019D4EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D4F0: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8019D4F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019D4F8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019D4FC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8019D500: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8019D504: addiu       $a2, $sp, 0x4C
    ctx->r6 = ADD32(ctx->r29, 0X4C);
    // 0x8019D508: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8019D50C: jal         0x80006A20
    // 0x8019D510: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_58;
    // 0x8019D510: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    after_58:
    // 0x8019D514: lwc1        $f12, 0x4C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019D518: jal         0x80005100
    // 0x8019D51C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    Math_Atan2F(rdram, ctx);
        goto after_59;
    // 0x8019D51C: lwc1        $f14, 0x54($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X54);
    after_59:
    // 0x8019D520: jal         0x8009F768
    // 0x8019D524: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_60;
    // 0x8019D524: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_60:
    // 0x8019D528: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8019D52C: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019D530: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019D534: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8019D538: swc1        $f2, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->f2.u32l;
    // 0x8019D53C: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019D540: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8019D544: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8019D548: jal         0x80005100
    // 0x8019D54C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_61;
    // 0x8019D54C: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_61:
    // 0x8019D550: jal         0x8009F768
    // 0x8019D554: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_62;
    // 0x8019D554: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_62:
    // 0x8019D558: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019D55C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019D560: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D564: lwc1        $f2, 0x1E4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1E4);
    // 0x8019D568: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8019D56C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019D570: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D574: addiu       $a0, $s0, 0x11C
    ctx->r4 = ADD32(ctx->r16, 0X11C);
    // 0x8019D578: bc1f        L_8019D5A4
    if (!c1cs) {
        // 0x8019D57C: lui         $a3, 0x4080
        ctx->r7 = S32(0X4080 << 16);
            goto L_8019D5A4;
    }
    // 0x8019D57C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019D580: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019D584: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019D588: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019D58C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x8019D590: nop

    // 0x8019D594: bc1fl       L_8019D5A8
    if (!c1cs) {
        // 0x8019D598: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_8019D5A8;
    }
    goto skip_29;
    // 0x8019D598: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_29:
    // 0x8019D59C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8019D5A0: nop

L_8019D5A4:
    // 0x8019D5A4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_8019D5A8:
    // 0x8019D5A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019D5AC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019D5B0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8019D5B4: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8019D5B8: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8019D5BC: bc1fl       L_8019D5DC
    if (!c1cs) {
        // 0x8019D5C0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8019D5DC;
    }
    goto skip_30;
    // 0x8019D5C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_30:
    // 0x8019D5C4: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x8019D5C8: nop

    // 0x8019D5CC: bc1fl       L_8019D5DC
    if (!c1cs) {
        // 0x8019D5D0: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8019D5DC;
    }
    goto skip_31;
    // 0x8019D5D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_31:
    // 0x8019D5D4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019D5D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8019D5DC:
    // 0x8019D5DC: lui         $at, 0x4387
    ctx->r1 = S32(0X4387 << 16);
    // 0x8019D5E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8019D5E4: nop

    // 0x8019D5E8: bc1fl       L_8019D608
    if (!c1cs) {
        // 0x8019D5EC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8019D608;
    }
    goto skip_32;
    // 0x8019D5EC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_32:
    // 0x8019D5F0: c.le.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl <= ctx->f14.fl;
    // 0x8019D5F4: nop

    // 0x8019D5F8: bc1fl       L_8019D608
    if (!c1cs) {
        // 0x8019D5FC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8019D608;
    }
    goto skip_33;
    // 0x8019D5FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_33:
    // 0x8019D600: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019D604: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8019D608:
    // 0x8019D608: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D60C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8019D610: nop

    // 0x8019D614: bc1f        L_8019D630
    if (!c1cs) {
        // 0x8019D618: nop
    
            goto L_8019D630;
    }
    // 0x8019D618: nop

    // 0x8019D61C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8019D620: nop

    // 0x8019D624: bc1f        L_8019D630
    if (!c1cs) {
        // 0x8019D628: nop
    
            goto L_8019D630;
    }
    // 0x8019D628: nop

    // 0x8019D62C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8019D630:
    // 0x8019D630: lwc1        $f10, 0x76C4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76C4);
    // 0x8019D634: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8019D638: swc1        $f12, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->f12.u32l;
    // 0x8019D63C: jal         0x8009BD38
    // 0x8019D640: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_63;
    // 0x8019D640: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_63:
    // 0x8019D644: lwc1        $f12, 0x1E8($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1E8);
    // 0x8019D648: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D64C: lwc1        $f4, 0x76C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X76C8);
    // 0x8019D650: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D654: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8019D658: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D65C: addiu       $a0, $s0, 0x118
    ctx->r4 = ADD32(ctx->r16, 0X118);
    // 0x8019D660: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019D664: jal         0x8009BD38
    // 0x8019D668: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_64;
    // 0x8019D668: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_64:
    // 0x8019D66C: b           L_8019D750
    // 0x8019D670: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
        goto L_8019D750;
    // 0x8019D670: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8019D674:
    // 0x8019D674: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D678: lwc1        $f8, 0x76CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76CC);
    // 0x8019D67C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D680: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D684: addiu       $a0, $s0, 0xF0
    ctx->r4 = ADD32(ctx->r16, 0XF0);
    // 0x8019D688: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D68C: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019D690: jal         0x8009BD38
    // 0x8019D694: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_65;
    // 0x8019D694: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_65:
    // 0x8019D698: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D69C: lwc1        $f6, 0x76D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76D0);
    // 0x8019D6A0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D6A4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D6A8: addiu       $a0, $s0, 0xEC
    ctx->r4 = ADD32(ctx->r16, 0XEC);
    // 0x8019D6AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D6B0: lui         $a3, 0x4080
    ctx->r7 = S32(0X4080 << 16);
    // 0x8019D6B4: jal         0x8009BD38
    // 0x8019D6B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_66;
    // 0x8019D6B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_66:
    // 0x8019D6BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D6C0: lwc1        $f10, 0x76D4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76D4);
    // 0x8019D6C4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8019D6C8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D6CC: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x8019D6D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D6D4: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8019D6D8: jal         0x8009BD38
    // 0x8019D6DC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_67;
    // 0x8019D6DC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_67:
    // 0x8019D6E0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D6E4: lwc1        $f4, 0x76D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X76D8);
    // 0x8019D6E8: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8019D6EC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D6F0: addiu       $a0, $s0, 0xF4
    ctx->r4 = ADD32(ctx->r16, 0XF4);
    // 0x8019D6F4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D6F8: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8019D6FC: jal         0x8009BD38
    // 0x8019D700: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_68;
    // 0x8019D700: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_68:
    // 0x8019D704: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D708: lwc1        $f8, 0x76DC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76DC);
    // 0x8019D70C: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8019D710: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D714: addiu       $a0, $s0, 0x114
    ctx->r4 = ADD32(ctx->r16, 0X114);
    // 0x8019D718: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D71C: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8019D720: jal         0x8009BD38
    // 0x8019D724: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_69;
    // 0x8019D724: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_69:
    // 0x8019D728: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D72C: lwc1        $f6, 0x76E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76E0);
    // 0x8019D730: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8019D734: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D738: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x8019D73C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D740: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8019D744: jal         0x8009BD38
    // 0x8019D748: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_70;
    // 0x8019D748: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_70:
    // 0x8019D74C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
L_8019D750:
    // 0x8019D750: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x8019D754: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D758: addiu       $a0, $s0, 0xE8
    ctx->r4 = ADD32(ctx->r16, 0XE8);
    // 0x8019D75C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D760: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8019D764: jal         0x8009BC2C
    // 0x8019D768: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_71;
    // 0x8019D768: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_71:
    // 0x8019D76C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D770: lwc1        $f4, 0x76E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X76E4);
    // 0x8019D774: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019D778: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8019D77C: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019D780: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D784: addiu       $a0, $s0, 0x160
    ctx->r4 = ADD32(ctx->r16, 0X160);
    // 0x8019D788: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D78C: jal         0x8009BC2C
    // 0x8019D790: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_72;
    // 0x8019D790: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_72:
    // 0x8019D794: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D798: lwc1        $f2, 0x76E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X76E8);
    // 0x8019D79C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019D7A0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D7A4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8019D7A8: addiu       $a0, $s0, 0x17C
    ctx->r4 = ADD32(ctx->r16, 0X17C);
    // 0x8019D7AC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D7B0: jal         0x8009BC2C
    // 0x8019D7B4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_73;
    // 0x8019D7B4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_73:
    // 0x8019D7B8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019D7BC: lwc1        $f2, 0x76EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X76EC);
    // 0x8019D7C0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019D7C4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019D7C8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8019D7CC: addiu       $a0, $s0, 0x180
    ctx->r4 = ADD32(ctx->r16, 0X180);
    // 0x8019D7D0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019D7D4: jal         0x8009BC2C
    // 0x8019D7D8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_74;
    // 0x8019D7D8: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_74:
    // 0x8019D7DC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019D7E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019D7E4: lwc1        $f8, 0xD8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x8019D7E8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019D7EC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8019D7F0: addiu       $a1, $s0, 0x1A0
    ctx->r5 = ADD32(ctx->r16, 0X1A0);
    // 0x8019D7F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8019D7F8: lw          $a3, 0x1D0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1D0);
    // 0x8019D7FC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019D800: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8019D804: jal         0x8009BEEC
    // 0x8019D808: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToVec3fArray(rdram, ctx);
        goto after_75;
    // 0x8019D808: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_75:
    // 0x8019D80C: lb          $t4, 0x62($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X62);
    // 0x8019D810: beql        $t4, $zero, L_8019D894
    if (ctx->r12 == 0) {
        // 0x8019D814: lw          $v1, 0x40($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X40);
            goto L_8019D894;
    }
    goto skip_34;
    // 0x8019D814: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    skip_34:
    // 0x8019D818: lh          $t5, 0x60($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X60);
    // 0x8019D81C: blezl       $t5, L_8019D894
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8019D820: lw          $v1, 0x40($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X40);
            goto L_8019D894;
    }
    goto skip_35;
    // 0x8019D820: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    skip_35:
    // 0x8019D824: lh          $t6, 0x66($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X66);
    // 0x8019D828: sb          $zero, 0x62($s0)
    MEM_B(0X62, ctx->r16) = 0;
    // 0x8019D82C: bne         $t6, $zero, L_8019D888
    if (ctx->r14 != 0) {
        // 0x8019D830: nop
    
            goto L_8019D888;
    }
    // 0x8019D830: nop

    // 0x8019D834: lh          $t7, 0xBA($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XBA);
    // 0x8019D838: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019D83C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019D840: bne         $t7, $zero, L_8019D878
    if (ctx->r15 != 0) {
        // 0x8019D844: addiu       $t8, $zero, 0xF
        ctx->r24 = ADD32(0, 0XF);
            goto L_8019D878;
    }
    // 0x8019D844: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x8019D848: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x8019D84C: sh          $t8, 0xB8($s0)
    MEM_H(0XB8, ctx->r16) = ctx->r24;
    // 0x8019D850: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x8019D854: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x8019D858: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x8019D85C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8019D860: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019D864: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    // 0x8019D868: jal         0x80019218
    // 0x8019D86C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_76;
    // 0x8019D86C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_76:
    // 0x8019D870: b           L_8019D894
    // 0x8019D874: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
        goto L_8019D894;
    // 0x8019D874: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
L_8019D878:
    // 0x8019D878: jal         0x80198F5C
    // 0x8019D87C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80198F5C(rdram, ctx);
        goto after_77;
    // 0x8019D87C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_77:
    // 0x8019D880: b           L_8019D894
    // 0x8019D884: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
        goto L_8019D894;
    // 0x8019D884: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
L_8019D888:
    // 0x8019D888: jal         0x80198F5C
    // 0x8019D88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80198F5C(rdram, ctx);
        goto after_78;
    // 0x8019D88C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_78:
    // 0x8019D890: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
L_8019D894:
    // 0x8019D894: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019D898: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019D89C: bne         $v1, $zero, L_8019D900
    if (ctx->r3 != 0) {
        // 0x8019D8A0: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_8019D900;
    }
    // 0x8019D8A0: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8019D8A4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x8019D8A8: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x8019D8AC: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x8019D8B0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8019D8B4: addiu       $t2, $t2, 0x5A10
    ctx->r10 = ADD32(ctx->r10, 0X5A10);
    // 0x8019D8B8: addiu       $t9, $t1, 0x28
    ctx->r25 = ADD32(ctx->r9, 0X28);
    // 0x8019D8BC: addu        $v0, $t9, $t2
    ctx->r2 = ADD32(ctx->r25, ctx->r10);
    // 0x8019D8C0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019D8C4: addiu       $t4, $zero, 0x66
    ctx->r12 = ADD32(0, 0X66);
    // 0x8019D8C8: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x8019D8CC: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x8019D8D0: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D8D4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019D8D8: swc1        $f4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f4.u32l;
    // 0x8019D8DC: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D8E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019D8E4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8019D8E8: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D8EC: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8019D8F0: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019D8F4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8019D8F8: b           L_8019D950
    // 0x8019D8FC: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
        goto L_8019D950;
    // 0x8019D8FC: swc1        $f8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f8.u32l;
L_8019D900:
    // 0x8019D900: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x8019D904: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8019D908: addiu       $t6, $t5, 0xA0
    ctx->r14 = ADD32(ctx->r13, 0XA0);
    // 0x8019D90C: addiu       $t7, $t7, 0x5A10
    ctx->r15 = ADD32(ctx->r15, 0X5A10);
    // 0x8019D910: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8019D914: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019D918: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8019D91C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x8019D920: sh          $t0, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r8;
    // 0x8019D924: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019D928: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8019D92C: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x8019D930: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019D934: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019D938: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x8019D93C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019D940: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8019D944: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8019D948: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8019D94C: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
L_8019D950:
    // 0x8019D950: lw          $a1, 0x13A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X13A0);
    // 0x8019D954: addiu       $a2, $zero, 0xFA
    ctx->r6 = ADD32(0, 0XFA);
    // 0x8019D958: addiu       $v0, $zero, 0x3B
    ctx->r2 = ADD32(0, 0X3B);
    // 0x8019D95C: bne         $a2, $a1, L_8019D99C
    if (ctx->r6 != ctx->r5) {
        // 0x8019D960: lui         $v1, 0x8017
        ctx->r3 = S32(0X8017 << 16);
            goto L_8019D99C;
    }
    // 0x8019D960: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019D964: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x8019D968: addiu       $a0, $a0, -0x80
    ctx->r4 = ADD32(ctx->r4, -0X80);
    // 0x8019D96C: addiu       $v1, $v1, -0x11E4
    ctx->r3 = ADD32(ctx->r3, -0X11E4);
L_8019D970:
    // 0x8019D970: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x8019D974: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019D978: bnel        $t1, $at, L_8019D994
    if (ctx->r9 != ctx->r1) {
        // 0x8019D97C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8019D994;
    }
    goto skip_36;
    // 0x8019D97C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    skip_36:
    // 0x8019D980: lw          $t9, 0x80($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X80);
    // 0x8019D984: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x8019D988: addu        $t3, $a0, $t2
    ctx->r11 = ADD32(ctx->r4, ctx->r10);
    // 0x8019D98C: sw          $v0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r2;
    // 0x8019D990: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_8019D994:
    // 0x8019D994: bgez        $v0, L_8019D970
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8019D998: addiu       $v1, $v1, -0x2F4
        ctx->r3 = ADD32(ctx->r3, -0X2F4);
            goto L_8019D970;
    }
    // 0x8019D998: addiu       $v1, $v1, -0x2F4
    ctx->r3 = ADD32(ctx->r3, -0X2F4);
L_8019D99C:
    // 0x8019D99C: bne         $a2, $a1, L_8019D9D4
    if (ctx->r6 != ctx->r5) {
        // 0x8019D9A0: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_8019D9D4;
    }
    // 0x8019D9A0: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8019D9A4: lw          $t4, 0x78B8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X78B8);
    // 0x8019D9A8: beql        $t4, $zero, L_8019D9D8
    if (ctx->r12 == 0) {
        // 0x8019D9AC: addiu       $at, $zero, 0x26C
        ctx->r1 = ADD32(0, 0X26C);
            goto L_8019D9D8;
    }
    goto skip_37;
    // 0x8019D9AC: addiu       $at, $zero, 0x26C
    ctx->r1 = ADD32(0, 0X26C);
    skip_37:
    // 0x8019D9B0: lh          $t5, 0xCC($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XCC);
    // 0x8019D9B4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019D9B8: addiu       $a0, $a0, -0x4D90
    ctx->r4 = ADD32(ctx->r4, -0X4D90);
    // 0x8019D9BC: bnel        $t5, $zero, L_8019D9D8
    if (ctx->r13 != 0) {
        // 0x8019D9C0: addiu       $at, $zero, 0x26C
        ctx->r1 = ADD32(0, 0X26C);
            goto L_8019D9D8;
    }
    goto skip_38;
    // 0x8019D9C0: addiu       $at, $zero, 0x26C
    ctx->r1 = ADD32(0, 0X26C);
    skip_38:
    // 0x8019D9C4: jal         0x800BA808
    // 0x8019D9C8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_79;
    // 0x8019D9C8: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_79:
    // 0x8019D9CC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8019D9D0: lw          $a1, 0x13A0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X13A0);
L_8019D9D4:
    // 0x8019D9D4: addiu       $at, $zero, 0x26C
    ctx->r1 = ADD32(0, 0X26C);
L_8019D9D8:
    // 0x8019D9D8: bne         $a1, $at, L_8019D9F4
    if (ctx->r5 != ctx->r1) {
        // 0x8019D9DC: lh          $v0, 0xCC($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XCC);
            goto L_8019D9F4;
    }
    // 0x8019D9DC: lh          $v0, 0xCC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XCC);
    // 0x8019D9E0: bne         $v0, $zero, L_8019D9F4
    if (ctx->r2 != 0) {
        // 0x8019D9E4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8019D9F4;
    }
    // 0x8019D9E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019D9E8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019D9EC: sw          $t6, 0x1734($at)
    MEM_W(0X1734, ctx->r1) = ctx->r14;
    // 0x8019D9F0: lh          $v0, 0xCC($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XCC);
L_8019D9F4:
    // 0x8019D9F4: slti        $at, $a1, 0x15E
    ctx->r1 = SIGNED(ctx->r5) < 0X15E ? 1 : 0;
    // 0x8019D9F8: beq         $at, $zero, L_8019DA08
    if (ctx->r1 == 0) {
        // 0x8019D9FC: lui         $v1, 0x8016
        ctx->r3 = S32(0X8016 << 16);
            goto L_8019DA08;
    }
    // 0x8019D9FC: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019DA00: beq         $v0, $zero, L_8019DA84
    if (ctx->r2 == 0) {
        // 0x8019DA04: nop
    
            goto L_8019DA84;
    }
    // 0x8019DA04: nop

L_8019DA08:
    // 0x8019DA08: beq         $v0, $zero, L_8019DA3C
    if (ctx->r2 == 0) {
        // 0x8019DA0C: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_8019DA3C;
    }
    // 0x8019DA0C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8019DA10: lh          $t7, 0x60($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X60);
    // 0x8019DA14: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019DA18: lwc1        $f6, 0x76F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76F0);
    // 0x8019DA1C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8019DA20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019DA24: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019DA28: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8019DA2C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019DA30: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x8019DA34: b           L_8019DA84
    // 0x8019DA38: sw          $t0, 0x7848($at)
    MEM_W(0X7848, ctx->r1) = ctx->r8;
        goto L_8019DA84;
    // 0x8019DA38: sw          $t0, 0x7848($at)
    MEM_W(0X7848, ctx->r1) = ctx->r8;
L_8019DA3C:
    // 0x8019DA3C: lh          $t1, -0xEA6($t1)
    ctx->r9 = MEM_H(ctx->r9, -0XEA6);
    // 0x8019DA40: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8019DA44: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8019DA48: bne         $t1, $zero, L_8019DA84
    if (ctx->r9 != 0) {
        // 0x8019DA4C: nop
    
            goto L_8019DA84;
    }
    // 0x8019DA4C: nop

    // 0x8019DA50: lh          $t9, -0x680($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X680);
    // 0x8019DA54: lh          $t2, -0xA88($t2)
    ctx->r10 = MEM_H(ctx->r10, -0XA88);
    // 0x8019DA58: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019DA5C: lwc1        $f10, 0x76F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76F4);
    // 0x8019DA60: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8019DA64: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8019DA68: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019DA6C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019DA70: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8019DA74: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019DA78: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8019DA7C: nop

    // 0x8019DA80: sw          $t5, 0x7848($at)
    MEM_W(0X7848, ctx->r1) = ctx->r13;
L_8019DA84:
    // 0x8019DA84: addiu       $v1, $v1, 0x15D0
    ctx->r3 = ADD32(ctx->r3, 0X15D0);
    // 0x8019DA88: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8019DA8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019DA90: nop

    // 0x8019DA94: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8019DA98: nop

    // 0x8019DA9C: bc1fl       L_8019DC38
    if (!c1cs) {
        // 0x8019DAA0: sh          $zero, 0xC4($s0)
        MEM_H(0XC4, ctx->r16) = 0;
            goto L_8019DC38;
    }
    goto skip_39;
    // 0x8019DAA0: sh          $zero, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = 0;
    skip_39:
    // 0x8019DAA4: lh          $t6, 0xC4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC4);
    // 0x8019DAA8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8019DAAC: sh          $t7, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r15;
    // 0x8019DAB0: lh          $v0, 0xC4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XC4);
    // 0x8019DAB4: slti        $at, $v0, 0x12D
    ctx->r1 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x8019DAB8: bnel        $at, $zero, L_8019DB68
    if (ctx->r1 != 0) {
        // 0x8019DABC: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8019DB68;
    }
    goto skip_40;
    // 0x8019DABC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_40:
    // 0x8019DAC0: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8019DAC4: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8019DAC8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019DACC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019DAD0: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x8019DAD4: nop

    // 0x8019DAD8: bc1fl       L_8019DAEC
    if (!c1cs) {
        // 0x8019DADC: neg.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
            goto L_8019DAEC;
    }
    goto skip_41;
    // 0x8019DADC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    skip_41:
    // 0x8019DAE0: b           L_8019DAEC
    // 0x8019DAE4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8019DAEC;
    // 0x8019DAE4: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019DAE8: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_8019DAEC:
    // 0x8019DAEC: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019DAF0: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x8019DAF4: nop

    // 0x8019DAF8: bc1fl       L_8019DB0C
    if (!c1cs) {
        // 0x8019DAFC: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_8019DB0C;
    }
    goto skip_42;
    // 0x8019DAFC: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_42:
    // 0x8019DB00: b           L_8019DB0C
    // 0x8019DB04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8019DB0C;
    // 0x8019DB04: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8019DB08: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_8019DB0C:
    // 0x8019DB0C: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8019DB10: lwc1        $f8, 0x76F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X76F8);
    // 0x8019DB14: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x8019DB18: nop

    // 0x8019DB1C: bc1fl       L_8019DB68
    if (!c1cs) {
        // 0x8019DB20: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8019DB68;
    }
    goto skip_43;
    // 0x8019DB20: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_43:
    // 0x8019DB24: lw          $t8, -0x7D64($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D64);
    // 0x8019DB28: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8019DB2C: bnel        $t8, $zero, L_8019DB68
    if (ctx->r24 != 0) {
        // 0x8019DB30: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8019DB68;
    }
    goto skip_44;
    // 0x8019DB30: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_44:
    // 0x8019DB34: lw          $t0, 0x78BC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78BC);
    // 0x8019DB38: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019DB3C: addiu       $a0, $a0, -0x4CE4
    ctx->r4 = ADD32(ctx->r4, -0X4CE4);
    // 0x8019DB40: blezl       $t0, L_8019DB5C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8019DB44: addiu       $t1, $zero, 0x96
        ctx->r9 = ADD32(0, 0X96);
            goto L_8019DB5C;
    }
    goto skip_45;
    // 0x8019DB44: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
    skip_45:
    // 0x8019DB48: jal         0x800BA808
    // 0x8019DB4C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_80;
    // 0x8019DB4C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_80:
    // 0x8019DB50: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019DB54: addiu       $v1, $v1, 0x15D0
    ctx->r3 = ADD32(ctx->r3, 0X15D0);
    // 0x8019DB58: addiu       $t1, $zero, 0x96
    ctx->r9 = ADD32(0, 0X96);
L_8019DB5C:
    // 0x8019DB5C: sh          $t1, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = ctx->r9;
    // 0x8019DB60: lh          $v0, 0xC4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XC4);
    // 0x8019DB64: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8019DB68:
    // 0x8019DB68: slti        $at, $v0, 0x65
    ctx->r1 = SIGNED(ctx->r2) < 0X65 ? 1 : 0;
    // 0x8019DB6C: bne         $at, $zero, L_8019DBF8
    if (ctx->r1 != 0) {
        // 0x8019DB70: lwc1        $f2, 0x0($v1)
        ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
            goto L_8019DBF8;
    }
    // 0x8019DB70: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019DB74: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8019DB78: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8019DB7C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8019DB80: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x8019DB84: nop

    // 0x8019DB88: bc1fl       L_8019DB9C
    if (!c1cs) {
        // 0x8019DB8C: neg.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
            goto L_8019DB9C;
    }
    goto skip_46;
    // 0x8019DB8C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    skip_46:
    // 0x8019DB90: b           L_8019DB9C
    // 0x8019DB94: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
        goto L_8019DB9C;
    // 0x8019DB94: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8019DB98: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
L_8019DB9C:
    // 0x8019DB9C: c.le.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl <= ctx->f2.fl;
    // 0x8019DBA0: nop

    // 0x8019DBA4: bc1fl       L_8019DBB8
    if (!c1cs) {
        // 0x8019DBA8: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_8019DBB8;
    }
    goto skip_47;
    // 0x8019DBA8: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_47:
    // 0x8019DBAC: b           L_8019DBB8
    // 0x8019DBB0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8019DBB8;
    // 0x8019DBB0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8019DBB4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_8019DBB8:
    // 0x8019DBB8: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8019DBBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019DBC0: nop

    // 0x8019DBC4: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x8019DBC8: nop

    // 0x8019DBCC: bc1fl       L_8019DBFC
    if (!c1cs) {
        // 0x8019DBD0: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8019DBFC;
    }
    goto skip_48;
    // 0x8019DBD0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_48:
    // 0x8019DBD4: lw          $t9, 0x78B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B4);
    // 0x8019DBD8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019DBDC: addiu       $a0, $a0, -0x4D34
    ctx->r4 = ADD32(ctx->r4, -0X4D34);
    // 0x8019DBE0: blezl       $t9, L_8019DBFC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8019DBE4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8019DBFC;
    }
    goto skip_49;
    // 0x8019DBE4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_49:
    // 0x8019DBE8: jal         0x800BA808
    // 0x8019DBEC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_81;
    // 0x8019DBEC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_81:
    // 0x8019DBF0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019DBF4: lwc1        $f2, 0x15D0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X15D0);
L_8019DBF8:
    // 0x8019DBF8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8019DBFC:
    // 0x8019DBFC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8019DC00: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8019DC04: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8019DC08: nop

    // 0x8019DC0C: bc1f        L_8019DC24
    if (!c1cs) {
        // 0x8019DC10: nop
    
            goto L_8019DC24;
    }
    // 0x8019DC10: nop

    // 0x8019DC14: lw          $t3, -0x7D80($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7D80);
    // 0x8019DC18: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8019DC1C: b           L_8019DC38
    // 0x8019DC20: sw          $t2, 0x228($t3)
    MEM_W(0X228, ctx->r11) = ctx->r10;
        goto L_8019DC38;
    // 0x8019DC20: sw          $t2, 0x228($t3)
    MEM_W(0X228, ctx->r11) = ctx->r10;
L_8019DC24:
    // 0x8019DC24: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8019DC28: addiu       $t4, $zero, 0x20
    ctx->r12 = ADD32(0, 0X20);
    // 0x8019DC2C: b           L_8019DC38
    // 0x8019DC30: sw          $t4, 0x228($t5)
    MEM_W(0X228, ctx->r13) = ctx->r12;
        goto L_8019DC38;
    // 0x8019DC30: sw          $t4, 0x228($t5)
    MEM_W(0X228, ctx->r13) = ctx->r12;
    // 0x8019DC34: sh          $zero, 0xC4($s0)
    MEM_H(0XC4, ctx->r16) = 0;
L_8019DC38:
    // 0x8019DC38: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019DC3C:
    // 0x8019DC3C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019DC40: addiu       $sp, $sp, 0x1F0
    ctx->r29 = ADD32(ctx->r29, 0X1F0);
    // 0x8019DC44: jr          $ra
    // 0x8019DC48: nop

    return;
    // 0x8019DC48: nop

;}
RECOMP_FUNC void Turret_UpdateCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A5FC0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801A5FC4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801A5FC8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A5FCC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801A5FD0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801A5FD4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A5FD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A5FDC: lwc1        $f20, 0x7EEC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7EEC);
    // 0x801A5FE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A5FE4: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x801A5FE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A5FEC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A5FF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A5FF4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x801A5FF8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x801A5FFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A6000: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x801A6004: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x801A6008: lwc1        $f8, 0x7EF0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7EF0);
    // 0x801A600C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A6010: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A6014: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A6018: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A601C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801A6020: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x801A6024: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A6028: jal         0x80005E90
    // 0x801A602C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x801A602C: nop

    after_0:
    // 0x801A6030: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A6034: lwc1        $f8, 0x7EF4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7EF4);
    // 0x801A6038: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x801A603C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A6040: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A6044: mul.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A6048: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A604C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A6050: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x801A6054: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A6058: jal         0x80005D44
    // 0x801A605C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801A605C: nop

    after_1:
    // 0x801A6060: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x801A6064: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A6068: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A606C: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801A6070: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A6074: jal         0x80005FE0
    // 0x801A6078: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x801A6078: nop

    after_2:
    // 0x801A607C: lwc1        $f10, 0x180($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X180);
    // 0x801A6080: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A6084: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A6088: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801A608C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A6090: jal         0x80005E90
    // 0x801A6094: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A6094: nop

    after_3:
    // 0x801A6098: lwc1        $f18, 0x17C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x801A609C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A60A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A60A4: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x801A60A8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A60AC: jal         0x80005D44
    // 0x801A60B0: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801A60B0: nop

    after_4:
    // 0x801A60B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801A60B8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A60BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A60C0: mul.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x801A60C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A60C8: jal         0x80005E90
    // 0x801A60CC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x801A60CC: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x801A60D0: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A60D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A60D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A60DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A60E0: jal         0x80005D44
    // 0x801A60E4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x801A60E4: nop

    after_6:
    // 0x801A60E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A60EC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x801A60F0: jal         0x80006970
    // 0x801A60F4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x801A60F4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_7:
    // 0x801A60F8: lwc1        $f0, 0x74($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X74);
    // 0x801A60FC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801A6100: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x801A6104: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A6108: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x801A610C: addiu       $v0, $v0, 0x7D20
    ctx->r2 = ADD32(ctx->r2, 0X7D20);
    // 0x801A6110: lwc1        $f12, 0x7C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x801A6114: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x801A6118: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801A611C: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x801A6120: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
    // 0x801A6124: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A6128: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A612C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x801A6130: add.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x801A6134: swc1        $f2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f2.u32l;
    // 0x801A6138: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A613C: swc1        $f10, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f10.u32l;
    // 0x801A6140: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A6144: add.s       $f18, $f12, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x801A6148: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x801A614C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A6150: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801A6154: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801A6158: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801A615C: jr          $ra
    // 0x801A6160: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801A6160: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Andross_8018BDD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018BDD8: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x8018BDDC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8018BDE0: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8018BDE4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8018BDE8: addiu       $a0, $a0, 0x1FD0
    ctx->r4 = ADD32(ctx->r4, 0X1FD0);
    // 0x8018BDEC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8018BDF0: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8018BDF4: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8018BDF8: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8018BDFC: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8018BE00: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8018BE04: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8018BE08: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8018BE0C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8018BE10: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018BE14: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018BE18: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018BE1C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8018BE20: lui         $v0, 0xC04
    ctx->r2 = S32(0XC04 << 16);
    // 0x8018BE24: addiu       $v0, $v0, -0x7018
    ctx->r2 = ADD32(ctx->r2, -0X7018);
    // 0x8018BE28: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8018BE2C: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x8018BE30: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8018BE34: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x8018BE38: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x8018BE3C: lui         $v1, 0xC01
    ctx->r3 = S32(0XC01 << 16);
    // 0x8018BE40: and         $t5, $v0, $a1
    ctx->r13 = ctx->r2 & ctx->r5;
    // 0x8018BE44: addiu       $v1, $v1, 0x7598
    ctx->r3 = ADD32(ctx->r3, 0X7598);
    // 0x8018BE48: sll         $t8, $v1, 4
    ctx->r24 = S32(ctx->r3 << 4);
    // 0x8018BE4C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8018BE50: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x8018BE54: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8018BE58: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8018BE5C: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8018BE60: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018BE64: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8018BE68: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018BE6C: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8018BE70: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018BE74: and         $t7, $v1, $a1
    ctx->r15 = ctx->r3 & ctx->r5;
    // 0x8018BE78: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018BE7C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018BE80: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018BE84: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8018BE88: lui         $s6, 0x8017
    ctx->r22 = S32(0X8017 << 16);
    // 0x8018BE8C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018BE90: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8018BE94: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8018BE98: addiu       $s6, $s6, 0x7880
    ctx->r22 = ADD32(ctx->r22, 0X7880);
    // 0x8018BE9C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8018BEA0: addiu       $s1, $sp, 0xC0
    ctx->r17 = ADD32(ctx->r29, 0XC0);
    // 0x8018BEA4: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x8018BEA8: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8018BEAC: addiu       $s4, $sp, 0xC0
    ctx->r20 = ADD32(ctx->r29, 0XC0);
    // 0x8018BEB0: addiu       $s3, $sp, 0xBC
    ctx->r19 = ADD32(ctx->r29, 0XBC);
    // 0x8018BEB4: addiu       $s2, $sp, 0x7C
    ctx->r18 = ADD32(ctx->r29, 0X7C);
L_8018BEB8:
    // 0x8018BEB8: beql        $s0, $s2, L_8018BECC
    if (ctx->r16 == ctx->r18) {
        // 0x8018BEBC: swc1        $f26, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f26.u32l;
            goto L_8018BECC;
    }
    goto skip_0;
    // 0x8018BEBC: swc1        $f26, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f26.u32l;
    skip_0:
    // 0x8018BEC0: bnel        $s0, $s3, L_8018BED8
    if (ctx->r16 != ctx->r19) {
        // 0x8018BEC4: lw          $t4, 0x0($s6)
        ctx->r12 = MEM_W(ctx->r22, 0X0);
            goto L_8018BED8;
    }
    goto skip_1;
    // 0x8018BEC4: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x8018BEC8: swc1        $f26, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f26.u32l;
L_8018BECC:
    // 0x8018BECC: b           L_8018BF2C
    // 0x8018BED0: swc1        $f26, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f26.u32l;
        goto L_8018BF2C;
    // 0x8018BED0: swc1        $f26, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f26.u32l;
    // 0x8018BED4: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
L_8018BED8:
    // 0x8018BED8: bne         $s5, $t4, L_8018BF08
    if (ctx->r21 != ctx->r12) {
        // 0x8018BEDC: nop
    
            goto L_8018BF08;
    }
    // 0x8018BEDC: nop

    // 0x8018BEE0: jal         0x80004EB0
    // 0x8018BEE4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8018BEE4: nop

    after_0:
    // 0x8018BEE8: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8018BEEC: mul.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018BEF0: jal         0x80004EB0
    // 0x8018BEF4: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018BEF4: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    after_1:
    // 0x8018BEF8: sub.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8018BEFC: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8018BF00: b           L_8018BF2C
    // 0x8018BF04: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_8018BF2C;
    // 0x8018BF04: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
L_8018BF08:
    // 0x8018BF08: jal         0x80004EB0
    // 0x8018BF0C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018BF0C: nop

    after_2:
    // 0x8018BF10: sub.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8018BF14: mul.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f24.fl);
    // 0x8018BF18: jal         0x80004EB0
    // 0x8018BF1C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018BF1C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
    after_3:
    // 0x8018BF20: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8018BF24: mul.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8018BF28: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_8018BF2C:
    // 0x8018BF2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018BF30: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x8018BF34: bne         $at, $zero, L_8018BEB8
    if (ctx->r1 != 0) {
        // 0x8018BF38: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8018BEB8;
    }
    // 0x8018BF38: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018BF3C: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8018BF40: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x8018BF44: addiu       $a3, $sp, 0xC0
    ctx->r7 = ADD32(ctx->r29, 0XC0);
    // 0x8018BF48: lh          $t5, 0x4($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X4);
    // 0x8018BF4C: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x8018BF50: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8018BF54: addiu       $t6, $t5, 0xC8
    ctx->r14 = ADD32(ctx->r13, 0XC8);
    // 0x8018BF58: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x8018BF5C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8018BF60: mflo        $a1
    ctx->r5 = lo;
    // 0x8018BF64: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8018BF68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018BF6C: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x8018BF70: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018BF74: addiu       $t0, $sp, 0x7C
    ctx->r8 = ADD32(ctx->r29, 0X7C);
    // 0x8018BF78: bne         $a2, $zero, L_8018BF84
    if (ctx->r6 != 0) {
        // 0x8018BF7C: nop
    
            goto L_8018BF84;
    }
    // 0x8018BF7C: nop

    // 0x8018BF80: break       7
    do_break(2149105536);
L_8018BF84:
    // 0x8018BF84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018BF88: bne         $a2, $at, L_8018BF9C
    if (ctx->r6 != ctx->r1) {
        // 0x8018BF8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018BF9C;
    }
    // 0x8018BF8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018BF90: bne         $t6, $at, L_8018BF9C
    if (ctx->r14 != ctx->r1) {
        // 0x8018BF94: nop
    
            goto L_8018BF9C;
    }
    // 0x8018BF94: nop

    // 0x8018BF98: break       6
    do_break(2149105560);
L_8018BF9C:
    // 0x8018BF9C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018BFA0: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x8018BFA4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8018BFA8: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018BFAC: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8018BFB0: nop

    // 0x8018BFB4: sh          $t4, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r12;
    // 0x8018BFB8: lh          $t6, 0x2($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X2);
    // 0x8018BFBC: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018BFC0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018BFC4: nop

    // 0x8018BFC8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018BFCC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018BFD0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018BFD4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8018BFD8: nop

    // 0x8018BFDC: sh          $t8, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r24;
    // 0x8018BFE0: lh          $t9, 0x14($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X14);
    // 0x8018BFE4: lh          $t6, 0x10($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X10);
    // 0x8018BFE8: addiu       $t4, $t9, 0xC8
    ctx->r12 = ADD32(ctx->r25, 0XC8);
    // 0x8018BFEC: div         $zero, $t4, $a2
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r6)));
    // 0x8018BFF0: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018BFF4: mflo        $a1
    ctx->r5 = lo;
    // 0x8018BFF8: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8018BFFC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C000: addu        $t5, $a3, $v1
    ctx->r13 = ADD32(ctx->r7, ctx->r3);
    // 0x8018C004: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018C008: bne         $a2, $zero, L_8018C014
    if (ctx->r6 != 0) {
        // 0x8018C00C: nop
    
            goto L_8018C014;
    }
    // 0x8018C00C: nop

    // 0x8018C010: break       7
    do_break(2149105680);
L_8018C014:
    // 0x8018C014: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018C018: bne         $a2, $at, L_8018C02C
    if (ctx->r6 != ctx->r1) {
        // 0x8018C01C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018C02C;
    }
    // 0x8018C01C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018C020: bne         $t4, $at, L_8018C02C
    if (ctx->r12 != ctx->r1) {
        // 0x8018C024: nop
    
            goto L_8018C02C;
    }
    // 0x8018C024: nop

    // 0x8018C028: break       6
    do_break(2149105704);
L_8018C02C:
    // 0x8018C02C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C030: addu        $t9, $t0, $v1
    ctx->r25 = ADD32(ctx->r8, ctx->r3);
    // 0x8018C034: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018C038: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8018C03C: nop

    // 0x8018C040: sh          $t8, 0x10($t3)
    MEM_H(0X10, ctx->r11) = ctx->r24;
    // 0x8018C044: lh          $t4, 0x12($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X12);
    // 0x8018C048: lwc1        $f18, 0x0($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018C04C: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x8018C050: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8018C054: nop

    // 0x8018C058: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C05C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018C060: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018C064: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8018C068: nop

    // 0x8018C06C: sh          $t6, 0x12($t3)
    MEM_H(0X12, ctx->r11) = ctx->r14;
    // 0x8018C070: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8018C074: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x8018C078: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8018C07C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
L_8018C080:
    // 0x8018C080: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x8018C084: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x8018C088: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8018C08C: addiu       $t8, $t7, 0xC8
    ctx->r24 = ADD32(ctx->r15, 0XC8);
    // 0x8018C090: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x8018C094: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8018C098: mflo        $a1
    ctx->r5 = lo;
    // 0x8018C09C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8018C0A0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C0A4: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x8018C0A8: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018C0AC: bne         $a2, $zero, L_8018C0B8
    if (ctx->r6 != 0) {
        // 0x8018C0B0: nop
    
            goto L_8018C0B8;
    }
    // 0x8018C0B0: nop

    // 0x8018C0B4: break       7
    do_break(2149105844);
L_8018C0B8:
    // 0x8018C0B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018C0BC: bne         $a2, $at, L_8018C0D0
    if (ctx->r6 != ctx->r1) {
        // 0x8018C0C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018C0D0;
    }
    // 0x8018C0C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018C0C4: bne         $t8, $at, L_8018C0D0
    if (ctx->r24 != ctx->r1) {
        // 0x8018C0C8: nop
    
            goto L_8018C0D0;
    }
    // 0x8018C0C8: nop

    // 0x8018C0CC: break       6
    do_break(2149105868);
L_8018C0D0:
    // 0x8018C0D0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C0D4: addu        $t7, $t0, $v1
    ctx->r15 = ADD32(ctx->r8, ctx->r3);
    // 0x8018C0D8: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8018C0DC: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8018C0E0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018C0E4: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8018C0E8: nop

    // 0x8018C0EC: sh          $t6, -0x40($a0)
    MEM_H(-0X40, ctx->r4) = ctx->r14;
    // 0x8018C0F0: lh          $t8, -0x3E($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X3E);
    // 0x8018C0F4: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018C0F8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8018C0FC: nop

    // 0x8018C100: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C104: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018C108: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018C10C: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x8018C110: nop

    // 0x8018C114: sh          $t4, -0x3E($a0)
    MEM_H(-0X3E, ctx->r4) = ctx->r12;
    // 0x8018C118: lh          $t5, -0x2C($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X2C);
    // 0x8018C11C: lh          $t8, -0x30($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X30);
    // 0x8018C120: addiu       $t6, $t5, 0xC8
    ctx->r14 = ADD32(ctx->r13, 0XC8);
    // 0x8018C124: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x8018C128: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8018C12C: mflo        $a1
    ctx->r5 = lo;
    // 0x8018C130: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8018C134: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C138: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x8018C13C: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018C140: bne         $a2, $zero, L_8018C14C
    if (ctx->r6 != 0) {
        // 0x8018C144: nop
    
            goto L_8018C14C;
    }
    // 0x8018C144: nop

    // 0x8018C148: break       7
    do_break(2149105992);
L_8018C14C:
    // 0x8018C14C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018C150: bne         $a2, $at, L_8018C164
    if (ctx->r6 != ctx->r1) {
        // 0x8018C154: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018C164;
    }
    // 0x8018C154: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018C158: bne         $t6, $at, L_8018C164
    if (ctx->r14 != ctx->r1) {
        // 0x8018C15C: nop
    
            goto L_8018C164;
    }
    // 0x8018C15C: nop

    // 0x8018C160: break       6
    do_break(2149106016);
L_8018C164:
    // 0x8018C164: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018C168: addu        $t5, $t0, $v1
    ctx->r13 = ADD32(ctx->r8, ctx->r3);
    // 0x8018C16C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018C170: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8018C174: nop

    // 0x8018C178: sh          $t4, -0x30($a0)
    MEM_H(-0X30, ctx->r4) = ctx->r12;
    // 0x8018C17C: lh          $t6, -0x2E($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X2E);
    // 0x8018C180: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018C184: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018C188: nop

    // 0x8018C18C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C190: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018C194: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8018C198: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x8018C19C: nop

    // 0x8018C1A0: sh          $t8, -0x2E($a0)
    MEM_H(-0X2E, ctx->r4) = ctx->r24;
    // 0x8018C1A4: lh          $t9, -0x1C($v0)
    ctx->r25 = MEM_H(ctx->r2, -0X1C);
    // 0x8018C1A8: lh          $t6, -0x20($v0)
    ctx->r14 = MEM_H(ctx->r2, -0X20);
    // 0x8018C1AC: addiu       $t4, $t9, 0xC8
    ctx->r12 = ADD32(ctx->r25, 0XC8);
    // 0x8018C1B0: div         $zero, $t4, $a2
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r6)));
    // 0x8018C1B4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018C1B8: mflo        $a1
    ctx->r5 = lo;
    // 0x8018C1BC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8018C1C0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C1C4: addu        $t5, $a3, $v1
    ctx->r13 = ADD32(ctx->r7, ctx->r3);
    // 0x8018C1C8: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018C1CC: bne         $a2, $zero, L_8018C1D8
    if (ctx->r6 != 0) {
        // 0x8018C1D0: nop
    
            goto L_8018C1D8;
    }
    // 0x8018C1D0: nop

    // 0x8018C1D4: break       7
    do_break(2149106132);
L_8018C1D8:
    // 0x8018C1D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018C1DC: bne         $a2, $at, L_8018C1F0
    if (ctx->r6 != ctx->r1) {
        // 0x8018C1E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018C1F0;
    }
    // 0x8018C1E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018C1E4: bne         $t4, $at, L_8018C1F0
    if (ctx->r12 != ctx->r1) {
        // 0x8018C1E8: nop
    
            goto L_8018C1F0;
    }
    // 0x8018C1E8: nop

    // 0x8018C1EC: break       6
    do_break(2149106156);
L_8018C1F0:
    // 0x8018C1F0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018C1F4: addu        $t9, $t0, $v1
    ctx->r25 = ADD32(ctx->r8, ctx->r3);
    // 0x8018C1F8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018C1FC: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8018C200: nop

    // 0x8018C204: sh          $t8, -0x20($a0)
    MEM_H(-0X20, ctx->r4) = ctx->r24;
    // 0x8018C208: lh          $t4, -0x1E($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X1E);
    // 0x8018C20C: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018C210: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8018C214: nop

    // 0x8018C218: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C21C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8018C220: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018C224: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8018C228: nop

    // 0x8018C22C: sh          $t6, -0x1E($a0)
    MEM_H(-0X1E, ctx->r4) = ctx->r14;
    // 0x8018C230: lh          $t7, -0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, -0XC);
    // 0x8018C234: lh          $t4, -0x10($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X10);
    // 0x8018C238: addiu       $t8, $t7, 0xC8
    ctx->r24 = ADD32(ctx->r15, 0XC8);
    // 0x8018C23C: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x8018C240: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8018C244: mflo        $a1
    ctx->r5 = lo;
    // 0x8018C248: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x8018C24C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C250: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x8018C254: lwc1        $f8, 0x0($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8018C258: bne         $a2, $zero, L_8018C264
    if (ctx->r6 != 0) {
        // 0x8018C25C: nop
    
            goto L_8018C264;
    }
    // 0x8018C25C: nop

    // 0x8018C260: break       7
    do_break(2149106272);
L_8018C264:
    // 0x8018C264: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018C268: bne         $a2, $at, L_8018C27C
    if (ctx->r6 != ctx->r1) {
        // 0x8018C26C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018C27C;
    }
    // 0x8018C26C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018C270: bne         $t8, $at, L_8018C27C
    if (ctx->r24 != ctx->r1) {
        // 0x8018C274: nop
    
            goto L_8018C27C;
    }
    // 0x8018C274: nop

    // 0x8018C278: break       6
    do_break(2149106296);
L_8018C27C:
    // 0x8018C27C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8018C280: addu        $t7, $t0, $v1
    ctx->r15 = ADD32(ctx->r8, ctx->r3);
    // 0x8018C284: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8018C288: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8018C28C: nop

    // 0x8018C290: sh          $t6, -0x10($a0)
    MEM_H(-0X10, ctx->r4) = ctx->r14;
    // 0x8018C294: lh          $t8, -0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, -0XE);
    // 0x8018C298: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8018C29C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8018C2A0: nop

    // 0x8018C2A4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018C2A8: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8018C2AC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018C2B0: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x8018C2B4: bne         $t1, $t2, L_8018C080
    if (ctx->r9 != ctx->r10) {
        // 0x8018C2B8: sh          $t4, -0xE($a0)
        MEM_H(-0XE, ctx->r4) = ctx->r12;
            goto L_8018C080;
    }
    // 0x8018C2B8: sh          $t4, -0xE($a0)
    MEM_H(-0XE, ctx->r4) = ctx->r12;
    // 0x8018C2BC: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8018C2C0: lw          $t5, -0x7D7C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D7C);
    // 0x8018C2C4: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8018C2C8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018C2CC: beq         $t5, $zero, L_8018C300
    if (ctx->r13 == 0) {
        // 0x8018C2D0: addiu       $a0, $a0, 0x7F58
        ctx->r4 = ADD32(ctx->r4, 0X7F58);
            goto L_8018C300;
    }
    // 0x8018C2D0: addiu       $a0, $a0, 0x7F58
    ctx->r4 = ADD32(ctx->r4, 0X7F58);
    // 0x8018C2D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018C2D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018C2DC: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8018C2E0: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018C2E4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018C2E8: addiu       $a0, $a0, 0x7F58
    ctx->r4 = ADD32(ctx->r4, 0X7F58);
    // 0x8018C2EC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x8018C2F0: jal         0x8009BC2C
    // 0x8018C2F4: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8018C2F4: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_4:
    // 0x8018C2F8: b           L_8018C31C
    // 0x8018C2FC: nop

        goto L_8018C31C;
    // 0x8018C2FC: nop

L_8018C300:
    // 0x8018C300: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018C304: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C308: lw          $a1, 0x7F60($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7F60);
    // 0x8018C30C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018C310: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018C314: jal         0x8009BC2C
    // 0x8018C318: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8018C318: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_5:
L_8018C31C:
    // 0x8018C31C: lui         $v0, 0x801A
    ctx->r2 = S32(0X801A << 16);
    // 0x8018C320: lui         $a0, 0x801A
    ctx->r4 = S32(0X801A << 16);
    // 0x8018C324: addiu       $a0, $a0, 0x7F70
    ctx->r4 = ADD32(ctx->r4, 0X7F70);
    // 0x8018C328: addiu       $v0, $v0, 0x7F68
    ctx->r2 = ADD32(ctx->r2, 0X7F68);
    // 0x8018C32C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8018C330: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8018C334: lui         $a1, 0x801A
    ctx->r5 = S32(0X801A << 16);
    // 0x8018C338: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8018C33C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8018C340: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x8018C344: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8018C348: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x8018C34C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8018C350: jal         0x8009BC2C
    // 0x8018C354: lw          $a1, 0x7F78($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7F78);
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8018C354: lw          $a1, 0x7F78($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7F78);
    after_6:
    // 0x8018C358: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8018C35C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018C360: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018C364: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018C368: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8018C36C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8018C370: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8018C374: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8018C378: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8018C37C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8018C380: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8018C384: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8018C388: jr          $ra
    // 0x8018C38C: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x8018C38C: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void SectorY_8019B6E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B6E8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8019B6EC: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x8019B6F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8019B6F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019B6F8: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8019B6FC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8019B700: lwc1        $f12, 0x78($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8019B704: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8019B708: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8019B70C: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8019B710: nop

    // 0x8019B714: bc1fl       L_8019B72C
    if (!c1cs) {
        // 0x8019B718: lwc1        $f8, 0x18($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8019B72C;
    }
    goto skip_0;
    // 0x8019B718: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x8019B71C: sub.s       $f2, $f12, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x8019B720: b           L_8019B738
    // 0x8019B724: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
        goto L_8019B738;
    // 0x8019B724: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x8019B728: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
L_8019B72C:
    // 0x8019B72C: sub.s       $f2, $f12, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8019B730: neg.s       $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = -ctx->f2.fl;
    // 0x8019B734: swc1        $f16, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f16.u32l;
L_8019B738:
    // 0x8019B738: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8019B73C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8019B740: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8019B744: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8019B748: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x8019B74C: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8019B750: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8019B754: nop

    // 0x8019B758: bc1fl       L_8019B770
    if (!c1cs) {
        // 0x8019B75C: lwc1        $f10, 0x10($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
            goto L_8019B770;
    }
    goto skip_1;
    // 0x8019B75C: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    skip_1:
    // 0x8019B760: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019B764: b           L_8019B77C
    // 0x8019B768: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8019B77C;
    // 0x8019B768: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x8019B76C: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
L_8019B770:
    // 0x8019B770: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8019B774: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8019B778: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
L_8019B77C:
    // 0x8019B77C: lwc1        $f6, 0x7C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x8019B780: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019B784: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019B788: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8019B78C: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019B790: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019B794: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x8019B798: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8019B79C: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8019B7A0: swc1        $f4, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f4.u32l;
    // 0x8019B7A4: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019B7A8: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8019B7AC: nop

    // 0x8019B7B0: bc1fl       L_8019B7C8
    if (!c1cs) {
        // 0x8019B7B4: lwc1        $f10, 0x4($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
            goto L_8019B7C8;
    }
    goto skip_2;
    // 0x8019B7B4: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    skip_2:
    // 0x8019B7B8: sub.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019B7BC: b           L_8019B7D4
    // 0x8019B7C0: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
        goto L_8019B7D4;
    // 0x8019B7C0: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x8019B7C4: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
L_8019B7C8:
    // 0x8019B7C8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019B7CC: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8019B7D0: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
L_8019B7D4:
    // 0x8019B7D4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8019B7D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019B7DC: add.s       $f8, $f14, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x8019B7E0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8019B7E4: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8019B7E8: nop

    // 0x8019B7EC: bc1fl       L_8019B870
    if (!c1cs) {
        // 0x8019B7F0: lwc1        $f8, 0x18($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8019B870;
    }
    goto skip_3;
    // 0x8019B7F0: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    skip_3:
    // 0x8019B7F4: lwc1        $f6, 0x18($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8019B7F8: lwc1        $f8, 0x10($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8019B7FC: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8019B800: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8019B804: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8019B808: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019B80C: bc1fl       L_8019B824
    if (!c1cs) {
        // 0x8019B810: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_8019B824;
    }
    goto skip_4;
    // 0x8019B810: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_4:
    // 0x8019B814: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8019B818: b           L_8019B824
    // 0x8019B81C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8019B824;
    // 0x8019B81C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8019B820: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_8019B824:
    // 0x8019B824: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x8019B828: nop

    // 0x8019B82C: bc1fl       L_8019B840
    if (!c1cs) {
        // 0x8019B830: neg.s       $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
            goto L_8019B840;
    }
    goto skip_5;
    // 0x8019B830: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
    skip_5:
    // 0x8019B834: b           L_8019B840
    // 0x8019B838: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8019B840;
    // 0x8019B838: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x8019B83C: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
L_8019B840:
    // 0x8019B840: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x8019B844: nop

    // 0x8019B848: bc1fl       L_8019B860
    if (!c1cs) {
        // 0x8019B84C: neg.s       $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
            goto L_8019B860;
    }
    goto skip_6;
    // 0x8019B84C: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
    skip_6:
    // 0x8019B850: add.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8019B854: b           L_8019B8DC
    // 0x8019B858: add.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f6.fl;
        goto L_8019B8DC;
    // 0x8019B858: add.s       $f2, $f18, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8019B85C: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
L_8019B860:
    // 0x8019B860: add.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8019B864: b           L_8019B8DC
    // 0x8019B868: add.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f6.fl;
        goto L_8019B8DC;
    // 0x8019B868: add.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8019B86C: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
L_8019B870:
    // 0x8019B870: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8019B874: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8019B878: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x8019B87C: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8019B880: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019B884: bc1fl       L_8019B89C
    if (!c1cs) {
        // 0x8019B888: neg.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
            goto L_8019B89C;
    }
    goto skip_7;
    // 0x8019B888: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    skip_7:
    // 0x8019B88C: lwc1        $f12, 0xC($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8019B890: b           L_8019B89C
    // 0x8019B894: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8019B89C;
    // 0x8019B894: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8019B898: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_8019B89C:
    // 0x8019B89C: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x8019B8A0: nop

    // 0x8019B8A4: bc1fl       L_8019B8B8
    if (!c1cs) {
        // 0x8019B8A8: neg.s       $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
            goto L_8019B8B8;
    }
    goto skip_8;
    // 0x8019B8A8: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
    skip_8:
    // 0x8019B8AC: b           L_8019B8B8
    // 0x8019B8B0: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8019B8B8;
    // 0x8019B8B0: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x8019B8B4: neg.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = -ctx->f16.fl;
L_8019B8B8:
    // 0x8019B8B8: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8019B8BC: add.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8019B8C0: bc1fl       L_8019B8D4
    if (!c1cs) {
        // 0x8019B8C4: neg.s       $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
            goto L_8019B8D4;
    }
    goto skip_9;
    // 0x8019B8C4: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
    skip_9:
    // 0x8019B8C8: b           L_8019B8D4
    // 0x8019B8CC: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
        goto L_8019B8D4;
    // 0x8019B8CC: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x8019B8D0: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
L_8019B8D4:
    // 0x8019B8D4: add.s       $f2, $f16, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8019B8D8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8019B8DC:
    // 0x8019B8DC: lwc1        $f0, 0x5F0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X5F0);
    // 0x8019B8E0: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8019B8E4: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019B8E8: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x8019B8EC: nop

    // 0x8019B8F0: bc1fl       L_8019B904
    if (!c1cs) {
        // 0x8019B8F4: lwc1        $f4, 0x18($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
            goto L_8019B904;
    }
    goto skip_10;
    // 0x8019B8F4: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    skip_10:
    // 0x8019B8F8: b           L_8019B90C
    // 0x8019B8FC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
        goto L_8019B90C;
    // 0x8019B8FC: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8019B900: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
L_8019B904:
    // 0x8019B904: sub.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8019B908: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_8019B90C:
    // 0x8019B90C: lwc1        $f0, 0x5EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x8019B910: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8019B914: nop

    // 0x8019B918: bc1fl       L_8019B92C
    if (!c1cs) {
        // 0x8019B91C: sub.s       $f14, $f0, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_8019B92C;
    }
    goto skip_11;
    // 0x8019B91C: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    skip_11:
    // 0x8019B920: b           L_8019B930
    // 0x8019B924: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_8019B930;
    // 0x8019B924: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8019B928: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
L_8019B92C:
    // 0x8019B92C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_8019B930:
    // 0x8019B930: lwc1        $f18, 0x5F4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5F4);
    // 0x8019B934: add.s       $f10, $f14, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8019B938: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019B93C: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x8019B940: nop

    // 0x8019B944: bc1fl       L_8019B958
    if (!c1cs) {
        // 0x8019B948: sub.s       $f0, $f18, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
            goto L_8019B958;
    }
    goto skip_12;
    // 0x8019B948: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    skip_12:
    // 0x8019B94C: b           L_8019B95C
    // 0x8019B950: sub.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f6.fl;
        goto L_8019B95C;
    // 0x8019B950: sub.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8019B954: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
L_8019B958:
    // 0x8019B958: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8019B95C:
    // 0x8019B95C: lwc1        $f4, 0x8E4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8E4);
    // 0x8019B960: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8019B964: add.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8019B968: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8019B96C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019B970: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019B974: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8019B978: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8019B97C: nop

    // 0x8019B980: bc1fl       L_8019B994
    if (!c1cs) {
        // 0x8019B984: sub.s       $f16, $f10, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
            goto L_8019B994;
    }
    goto skip_13;
    // 0x8019B984: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    skip_13:
    // 0x8019B988: b           L_8019B998
    // 0x8019B98C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
        goto L_8019B998;
    // 0x8019B98C: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019B990: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
L_8019B994:
    // 0x8019B994: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_8019B998:
    // 0x8019B998: lwc1        $f0, 0x8E0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8E0);
    // 0x8019B99C: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8019B9A0: nop

    // 0x8019B9A4: bc1fl       L_8019B9B8
    if (!c1cs) {
        // 0x8019B9A8: sub.s       $f14, $f0, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_8019B9B8;
    }
    goto skip_14;
    // 0x8019B9A8: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    skip_14:
    // 0x8019B9AC: b           L_8019B9BC
    // 0x8019B9B0: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_8019B9BC;
    // 0x8019B9B0: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8019B9B4: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
L_8019B9B8:
    // 0x8019B9B8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_8019B9BC:
    // 0x8019B9BC: lwc1        $f6, 0x8E8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8E8);
    // 0x8019B9C0: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019B9C4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x8019B9C8: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019B9CC: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019B9D0: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019B9D4: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8019B9D8: nop

    // 0x8019B9DC: bc1fl       L_8019B9F0
    if (!c1cs) {
        // 0x8019B9E0: sub.s       $f0, $f4, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
            goto L_8019B9F0;
    }
    goto skip_15;
    // 0x8019B9E0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    skip_15:
    // 0x8019B9E4: b           L_8019B9F4
    // 0x8019B9E8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
        goto L_8019B9F4;
    // 0x8019B9E8: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019B9EC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
L_8019B9F0:
    // 0x8019B9F0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8019B9F4:
    // 0x8019B9F4: add.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8019B9F8: lwc1        $f4, 0xBD8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XBD8);
    // 0x8019B9FC: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8019BA00: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8019BA04: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019BA08: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8019BA0C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8019BA10: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019BA14: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8019BA18: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8019BA1C: bc1fl       L_8019BA30
    if (!c1cs) {
        // 0x8019BA20: sub.s       $f16, $f10, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
            goto L_8019BA30;
    }
    goto skip_16;
    // 0x8019BA20: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
    skip_16:
    // 0x8019BA24: b           L_8019BA34
    // 0x8019BA28: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
        goto L_8019BA34;
    // 0x8019BA28: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8019BA2C: sub.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f4.fl;
L_8019BA30:
    // 0x8019BA30: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_8019BA34:
    // 0x8019BA34: lwc1        $f0, 0xBD4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XBD4);
    // 0x8019BA38: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019BA3C: lwc1        $f8, 0x0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8019BA40: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8019BA44: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8019BA48: bc1fl       L_8019BA5C
    if (!c1cs) {
        // 0x8019BA4C: sub.s       $f14, $f0, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_8019BA5C;
    }
    goto skip_17;
    // 0x8019BA4C: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    skip_17:
    // 0x8019BA50: b           L_8019BA60
    // 0x8019BA54: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
        goto L_8019BA60;
    // 0x8019BA54: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8019BA58: sub.s       $f14, $f0, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f12.fl;
L_8019BA5C:
    // 0x8019BA5C: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_8019BA60:
    // 0x8019BA60: lwc1        $f12, 0xBDC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XBDC);
    // 0x8019BA64: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8019BA68: nop

    // 0x8019BA6C: bc1fl       L_8019BA80
    if (!c1cs) {
        // 0x8019BA70: sub.s       $f0, $f12, $f8
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
            goto L_8019BA80;
    }
    goto skip_18;
    // 0x8019BA70: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
    skip_18:
    // 0x8019BA74: b           L_8019BA84
    // 0x8019BA78: sub.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f6.fl;
        goto L_8019BA84;
    // 0x8019BA78: sub.s       $f0, $f12, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x8019BA7C: sub.s       $f0, $f12, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f8.fl;
L_8019BA80:
    // 0x8019BA80: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8019BA84:
    // 0x8019BA84: sh          $t6, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = ctx->r14;
    // 0x8019BA88: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8019BA8C: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x8019BA90: lwc1        $f10, 0x74($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X74);
    // 0x8019BA94: swc1        $f10, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f10.u32l;
    // 0x8019BA98: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8019BA9C: lwc1        $f4, 0x78($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X78);
    // 0x8019BAA0: swc1        $f4, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f4.u32l;
    // 0x8019BAA4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8019BAA8: lwc1        $f6, 0x7C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X7C);
    // 0x8019BAAC: swc1        $f6, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f6.u32l;
    // 0x8019BAB0: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8019BAB4: lwc1        $f8, 0xC0($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC0);
    // 0x8019BAB8: swc1        $f8, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->f8.u32l;
    // 0x8019BABC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8019BAC0: lwc1        $f10, 0xC4($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0XC4);
    // 0x8019BAC4: swc1        $f10, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->f10.u32l;
    // 0x8019BAC8: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8019BACC: lwc1        $f4, 0xC8($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0XC8);
    // 0x8019BAD0: bc1f        L_8019BB18
    if (!c1cs) {
        // 0x8019BAD4: swc1        $f4, 0x140($a0)
        MEM_W(0X140, ctx->r4) = ctx->f4.u32l;
            goto L_8019BB18;
    }
    // 0x8019BAD4: swc1        $f4, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->f4.u32l;
    // 0x8019BAD8: lh          $t3, 0xB4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0XB4);
    // 0x8019BADC: mov.s       $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = ctx->f18.fl;
    // 0x8019BAE0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8019BAE4: sh          $t4, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = ctx->r12;
    // 0x8019BAE8: lwc1        $f6, 0x5EC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5EC);
    // 0x8019BAEC: swc1        $f6, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f6.u32l;
    // 0x8019BAF0: lwc1        $f8, 0x5F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5F0);
    // 0x8019BAF4: swc1        $f8, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f8.u32l;
    // 0x8019BAF8: lwc1        $f10, 0x5F4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X5F4);
    // 0x8019BAFC: swc1        $f10, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f10.u32l;
    // 0x8019BB00: lwc1        $f4, 0x6D0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x8019BB04: swc1        $f4, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->f4.u32l;
    // 0x8019BB08: lwc1        $f6, 0x6D4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X6D4);
    // 0x8019BB0C: swc1        $f6, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->f6.u32l;
    // 0x8019BB10: lwc1        $f8, 0x6D8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6D8);
    // 0x8019BB14: swc1        $f8, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->f8.u32l;
L_8019BB18:
    // 0x8019BB18: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019BB1C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8019BB20: nop

    // 0x8019BB24: bc1fl       L_8019BB68
    if (!c1cs) {
        // 0x8019BB28: add.s       $f8, $f14, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f16.fl;
            goto L_8019BB68;
    }
    goto skip_19;
    // 0x8019BB28: add.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f16.fl;
    skip_19:
    // 0x8019BB2C: sh          $t5, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = ctx->r13;
    // 0x8019BB30: lwc1        $f4, 0x8E0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8E0);
    // 0x8019BB34: swc1        $f4, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f4.u32l;
    // 0x8019BB38: lwc1        $f6, 0x8E4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8E4);
    // 0x8019BB3C: swc1        $f6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f6.u32l;
    // 0x8019BB40: lwc1        $f8, 0x8E8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8E8);
    // 0x8019BB44: swc1        $f8, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f8.u32l;
    // 0x8019BB48: lwc1        $f10, 0x9C4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X9C4);
    // 0x8019BB4C: swc1        $f10, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->f10.u32l;
    // 0x8019BB50: lwc1        $f4, 0x9C8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X9C8);
    // 0x8019BB54: swc1        $f4, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->f4.u32l;
    // 0x8019BB58: lwc1        $f6, 0x9CC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X9CC);
    // 0x8019BB5C: swc1        $f6, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->f6.u32l;
    // 0x8019BB60: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019BB64: add.s       $f8, $f14, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f16.fl;
L_8019BB68:
    // 0x8019BB68: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8019BB6C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8019BB70: nop

    // 0x8019BB74: bc1f        L_8019BBB4
    if (!c1cs) {
        // 0x8019BB78: nop
    
            goto L_8019BBB4;
    }
    // 0x8019BB78: nop

    // 0x8019BB7C: lwc1        $f4, 0xBD4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XBD4);
    // 0x8019BB80: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8019BB84: swc1        $f4, 0x120($a0)
    MEM_W(0X120, ctx->r4) = ctx->f4.u32l;
    // 0x8019BB88: lwc1        $f6, 0xBD8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XBD8);
    // 0x8019BB8C: swc1        $f6, 0x124($a0)
    MEM_W(0X124, ctx->r4) = ctx->f6.u32l;
    // 0x8019BB90: lwc1        $f8, 0xBDC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XBDC);
    // 0x8019BB94: swc1        $f8, 0x128($a0)
    MEM_W(0X128, ctx->r4) = ctx->f8.u32l;
    // 0x8019BB98: lwc1        $f10, 0xCB8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XCB8);
    // 0x8019BB9C: swc1        $f10, 0x138($a0)
    MEM_W(0X138, ctx->r4) = ctx->f10.u32l;
    // 0x8019BBA0: lwc1        $f4, 0xCBC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XCBC);
    // 0x8019BBA4: swc1        $f4, 0x13C($a0)
    MEM_W(0X13C, ctx->r4) = ctx->f4.u32l;
    // 0x8019BBA8: lwc1        $f6, 0xCC0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XCC0);
    // 0x8019BBAC: sh          $t6, 0xB4($a0)
    MEM_H(0XB4, ctx->r4) = ctx->r14;
    // 0x8019BBB0: swc1        $f6, 0x140($a0)
    MEM_W(0X140, ctx->r4) = ctx->f6.u32l;
L_8019BBB4:
    // 0x8019BBB4: jr          $ra
    // 0x8019BBB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8019BBB8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void SectorY_8019AEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AEEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019AEF0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019AEF4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8019AEF8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019AEFC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019AF00: lwc1        $f4, 0x75C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X75C8);
    // 0x8019AF04: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019AF08: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019AF0C: lui         $a1, 0xC6E2
    ctx->r5 = S32(0XC6E2 << 16);
    // 0x8019AF10: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8019AF14: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x8019AF18: ori         $a1, $a1, 0x9000
    ctx->r5 = ctx->r5 | 0X9000;
    // 0x8019AF1C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019AF20: bc1tl       L_8019B1AC
    if (c1cs) {
        // 0x8019AF24: lwc1        $f16, 0xC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8019B1AC;
    }
    goto skip_0;
    // 0x8019AF24: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x8019AF28: lh          $t6, 0xB2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB2);
    // 0x8019AF2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019AF30: beql        $t6, $at, L_8019B1AC
    if (ctx->r14 == ctx->r1) {
        // 0x8019AF34: lwc1        $f16, 0xC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8019B1AC;
    }
    goto skip_1;
    // 0x8019AF34: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    skip_1:
    // 0x8019AF38: lh          $v0, 0x4A($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4A);
    // 0x8019AF3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019AF40: beql        $v0, $zero, L_8019B518
    if (ctx->r2 == 0) {
        // 0x8019AF44: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019B518;
    }
    goto skip_2;
    // 0x8019AF44: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x8019AF48: bne         $v0, $at, L_8019B030
    if (ctx->r2 != ctx->r1) {
        // 0x8019AF4C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8019B030;
    }
    // 0x8019AF4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019AF50: ori         $a1, $zero, 0x8041
    ctx->r5 = 0 | 0X8041;
    // 0x8019AF54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019AF58: jal         0x8001D444
    // 0x8019AF5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    Audio_PlaySequence(rdram, ctx);
        goto after_0;
    // 0x8019AF5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x8019AF60: lh          $t7, 0x4A($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4A);
    // 0x8019AF64: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019AF68: addiu       $v0, $v0, -0x7D80
    ctx->r2 = ADD32(ctx->r2, -0X7D80);
    // 0x8019AF6C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8019AF70: sh          $t8, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r24;
    // 0x8019AF74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019AF78: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8019AF7C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8019AF80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019AF84: swc1        $f0, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f0.u32l;
    // 0x8019AF88: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8019AF8C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019AF90: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019AF94: swc1        $f6, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f6.u32l;
    // 0x8019AF98: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8019AF9C: lwc1        $f8, 0x75CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75CC);
    // 0x8019AFA0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8019AFA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019AFA8: swc1        $f8, 0x48($t1)
    MEM_W(0X48, ctx->r9) = ctx->f8.u32l;
    // 0x8019AFAC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8019AFB0: addiu       $a0, $a0, 0x8CC
    ctx->r4 = ADD32(ctx->r4, 0X8CC);
    // 0x8019AFB4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8019AFB8: swc1        $f0, 0x4C($t2)
    MEM_W(0X4C, ctx->r10) = ctx->f0.u32l;
    // 0x8019AFBC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8019AFC0: swc1        $f10, 0x50($t3)
    MEM_W(0X50, ctx->r11) = ctx->f10.u32l;
    // 0x8019AFC4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8019AFC8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019AFCC: swc1        $f16, 0x54($t4)
    MEM_W(0X54, ctx->r12) = ctx->f16.u32l;
    // 0x8019AFD0: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8019AFD4: jal         0x800BA808
    // 0x8019AFD8: swc1        $f0, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f0.u32l;
    Radio_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8019AFD8: swc1        $f0, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f0.u32l;
    after_1:
    // 0x8019AFDC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019AFE0: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x8019AFE4: jal         0x801A0510
    // 0x8019AFE8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    SectorY_ActorCs_Setup(rdram, ctx);
        goto after_2;
    // 0x8019AFE8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_2:
    // 0x8019AFEC: lui         $at, 0x434A
    ctx->r1 = S32(0X434A << 16);
    // 0x8019AFF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019AFF4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019AFF8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019AFFC: addiu       $v1, $v1, -0x4020
    ctx->r3 = ADD32(ctx->r3, -0X4020);
    // 0x8019B000: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8019B004: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019B008: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019B00C: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8019B010: swc1        $f6, 0x2E44($v1)
    MEM_W(0X2E44, ctx->r3) = ctx->f6.u32l;
    // 0x8019B014: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019B018: swc1        $f8, 0x2E40($v1)
    MEM_W(0X2E40, ctx->r3) = ctx->f8.u32l;
    // 0x8019B01C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8019B020: sh          $t6, 0x2EF4($v1)
    MEM_H(0X2EF4, ctx->r3) = ctx->r14;
    // 0x8019B024: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8019B028: swc1        $f18, 0x2E48($v1)
    MEM_W(0X2E48, ctx->r3) = ctx->f18.u32l;
    // 0x8019B02C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
L_8019B030:
    // 0x8019B030: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019B034: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019B038: lui         $a0, 0x100
    ctx->r4 = S32(0X100 << 16);
    // 0x8019B03C: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8019B040: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019B044: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019B048: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019B04C: bc1f        L_8019B06C
    if (!c1cs) {
        // 0x8019B050: ori         $a0, $a0, 0x1D
        ctx->r4 = ctx->r4 | 0X1D;
            goto L_8019B06C;
    }
    // 0x8019B050: ori         $a0, $a0, 0x1D
    ctx->r4 = ctx->r4 | 0X1D;
    // 0x8019B054: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019B058: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8019B05C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019B060: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019B064: jal         0x80019218
    // 0x8019B068: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x8019B068: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_3:
L_8019B06C:
    // 0x8019B06C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B070: lwc1        $f0, 0x75D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X75D0);
    // 0x8019B074: lui         $a1, 0x43B6
    ctx->r5 = S32(0X43B6 << 16);
    // 0x8019B078: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8019B07C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B080: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8019B084: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019B088: jal         0x8009BC2C
    // 0x8019B08C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x8019B08C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8019B090: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B094: lwc1        $f0, 0x75D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X75D4);
    // 0x8019B098: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019B09C: addiu       $a0, $a0, -0x11DC
    ctx->r4 = ADD32(ctx->r4, -0X11DC);
    // 0x8019B0A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B0A4: lui         $a1, 0x4319
    ctx->r5 = S32(0X4319 << 16);
    // 0x8019B0A8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019B0AC: jal         0x8009BC2C
    // 0x8019B0B0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x8019B0B0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_5:
    // 0x8019B0B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B0B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B0BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019B0C0: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8019B0C4: lui         $a1, 0xC6DD
    ctx->r5 = S32(0XC6DD << 16);
    // 0x8019B0C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B0CC: ori         $a1, $a1, 0x1800
    ctx->r5 = ctx->r5 | 0X1800;
    // 0x8019B0D0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8019B0D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019B0D8: jal         0x8009BC2C
    // 0x8019B0DC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x8019B0DC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_6:
    // 0x8019B0E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019B0E4: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8019B0E8: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B0EC: lwc1        $f6, 0x75D8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75D8);
    // 0x8019B0F0: lwc1        $f8, 0x48($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X48);
    // 0x8019B0F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B0F8: addiu       $a0, $s0, 0x190
    ctx->r4 = ADD32(ctx->r16, 0X190);
    // 0x8019B0FC: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8019B100: nop

    // 0x8019B104: bc1f        L_8019B150
    if (!c1cs) {
        // 0x8019B108: nop
    
            goto L_8019B150;
    }
    // 0x8019B108: nop

    // 0x8019B10C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B110: lui         $a1, 0x4300
    ctx->r5 = S32(0X4300 << 16);
    // 0x8019B114: lui         $a3, 0x4180
    ctx->r7 = S32(0X4180 << 16);
    // 0x8019B118: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B11C: jal         0x8009BC2C
    // 0x8019B120: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x8019B120: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8019B124: lh          $t9, 0x60($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X60);
    // 0x8019B128: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B12C: lwc1        $f18, 0x75DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X75DC);
    // 0x8019B130: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8019B134: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019B138: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019B13C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8019B140: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019B144: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8019B148: nop

    // 0x8019B14C: sw          $t1, 0x7848($at)
    MEM_W(0X7848, ctx->r1) = ctx->r9;
L_8019B150:
    // 0x8019B150: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B154: lwc1        $f8, 0x75E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75E0);
    // 0x8019B158: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019B15C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8019B160: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8019B164: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8019B168: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x8019B16C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8019B170: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x8019B174: bc1f        L_8019B514
    if (!c1cs) {
        // 0x8019B178: ori         $a0, $a0, 0x2013
        ctx->r4 = ctx->r4 | 0X2013;
            goto L_8019B514;
    }
    // 0x8019B178: ori         $a0, $a0, 0x2013
    ctx->r4 = ctx->r4 | 0X2013;
    // 0x8019B17C: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x8019B180: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019B184: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019B188: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019B18C: jal         0x80019218
    // 0x8019B190: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x8019B190: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_8:
    // 0x8019B194: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x8019B198: addiu       $t4, $zero, 0x87
    ctx->r12 = ADD32(0, 0X87);
    // 0x8019B19C: sh          $t3, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r11;
    // 0x8019B1A0: b           L_8019B514
    // 0x8019B1A4: sh          $t4, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r12;
        goto L_8019B514;
    // 0x8019B1A4: sh          $t4, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r12;
    // 0x8019B1A8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
L_8019B1AC:
    // 0x8019B1AC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8019B1B0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B1B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B1B8: swc1        $f16, 0x54($t5)
    MEM_W(0X54, ctx->r13) = ctx->f16.u32l;
    // 0x8019B1BC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8019B1C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B1C4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019B1C8: jal         0x8009BC2C
    // 0x8019B1CC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x8019B1CC: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_9:
    // 0x8019B1D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B1D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B1D8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019B1DC: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8019B1E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B1E4: lui         $a1, 0x44FA
    ctx->r5 = S32(0X44FA << 16);
    // 0x8019B1E8: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x8019B1EC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019B1F0: jal         0x8009BC2C
    // 0x8019B1F4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8019B1F4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_10:
    // 0x8019B1F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B1FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B200: addiu       $a0, $s0, 0x190
    ctx->r4 = ADD32(ctx->r16, 0X190);
    // 0x8019B204: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019B208: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B20C: lui         $a3, 0x4180
    ctx->r7 = S32(0X4180 << 16);
    // 0x8019B210: jal         0x8009BC2C
    // 0x8019B214: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8019B214: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x8019B218: lh          $t6, 0x50($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X50);
    // 0x8019B21C: lui         $a0, 0x3102
    ctx->r4 = S32(0X3102 << 16);
    // 0x8019B220: ori         $a0, $a0, 0x505A
    ctx->r4 = ctx->r4 | 0X505A;
    // 0x8019B224: bne         $t6, $zero, L_8019B230
    if (ctx->r14 != 0) {
        // 0x8019B228: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_8019B230;
    }
    // 0x8019B228: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019B22C: sh          $zero, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = 0;
L_8019B230:
    // 0x8019B230: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
    // 0x8019B234: addiu       $at, $zero, 0x5F
    ctx->r1 = ADD32(0, 0X5F);
    // 0x8019B238: addiu       $a1, $a1, -0x10E4
    ctx->r5 = ADD32(ctx->r5, -0X10E4);
    // 0x8019B23C: bne         $v0, $at, L_8019B264
    if (ctx->r2 != ctx->r1) {
        // 0x8019B240: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_8019B264;
    }
    // 0x8019B240: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019B244: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8019B248: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8019B24C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8019B250: addiu       $a3, $t7, 0x5D34
    ctx->r7 = ADD32(ctx->r15, 0X5D34);
    // 0x8019B254: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019B258: jal         0x80019218
    // 0x8019B25C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    Audio_PlaySfx(rdram, ctx);
        goto after_12;
    // 0x8019B25C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_12:
    // 0x8019B260: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
L_8019B264:
    // 0x8019B264: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
    // 0x8019B268: beq         $at, $zero, L_8019B344
    if (ctx->r1 == 0) {
        // 0x8019B26C: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_8019B344;
    }
    // 0x8019B26C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019B270: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B274: lwc1        $f18, 0x75E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X75E4);
    // 0x8019B278: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019B27C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x8019B280: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8019B284: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B288: addiu       $a0, $a0, -0x10D0
    ctx->r4 = ADD32(ctx->r4, -0X10D0);
    // 0x8019B28C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019B290: jal         0x8009BC2C
    // 0x8019B294: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8019B294: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_13:
    // 0x8019B298: lh          $t9, 0x56($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X56);
    // 0x8019B29C: addiu       $a0, $s0, 0x74
    ctx->r4 = ADD32(ctx->r16, 0X74);
    // 0x8019B2A0: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x8019B2A4: slti        $at, $t9, 0x38
    ctx->r1 = SIGNED(ctx->r25) < 0X38 ? 1 : 0;
    // 0x8019B2A8: bne         $at, $zero, L_8019B344
    if (ctx->r1 != 0) {
        // 0x8019B2AC: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_8019B344;
    }
    // 0x8019B2AC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019B2B0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019B2B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B2B8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B2BC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019B2C0: jal         0x8009BC2C
    // 0x8019B2C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8019B2C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_14:
    // 0x8019B2C8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019B2CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B2D0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019B2D4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019B2D8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B2DC: addiu       $a0, $a0, -0x10F4
    ctx->r4 = ADD32(ctx->r4, -0X10F4);
    // 0x8019B2E0: lui         $a1, 0x42A0
    ctx->r5 = S32(0X42A0 << 16);
    // 0x8019B2E4: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x8019B2E8: jal         0x8009BC2C
    // 0x8019B2EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x8019B2EC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x8019B2F0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8019B2F4: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x8019B2F8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8019B2FC: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8019B300: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8019B304: bnel        $t1, $zero, L_8019B348
    if (ctx->r9 != 0) {
        // 0x8019B308: lh          $v0, 0x56($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X56);
            goto L_8019B348;
    }
    goto skip_3;
    // 0x8019B308: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
    skip_3:
    // 0x8019B30C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019B310: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8019B314: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019B318: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B31C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8019B320: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8019B324: lwc1        $f16, 0x75E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X75E8);
    // 0x8019B328: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019B32C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x8019B330: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8019B334: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8019B338: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8019B33C: jal         0x8007C120
    // 0x8019B340: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_16;
    // 0x8019B340: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_16:
L_8019B344:
    // 0x8019B344: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
L_8019B348:
    // 0x8019B348: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x8019B34C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x8019B350: bne         $v0, $at, L_8019B3D8
    if (ctx->r2 != ctx->r1) {
        // 0x8019B354: addiu       $a1, $a1, -0x7BC0
        ctx->r5 = ADD32(ctx->r5, -0X7BC0);
            goto L_8019B3D8;
    }
    // 0x8019B354: addiu       $a1, $a1, -0x7BC0
    ctx->r5 = ADD32(ctx->r5, -0X7BC0);
    // 0x8019B358: lwc1        $f18, 0x3FC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X3FC);
    // 0x8019B35C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    // 0x8019B360: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B364: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x8019B368: lwc1        $f4, 0x400($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X400);
    // 0x8019B36C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x8019B370: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8019B374: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8019B378: addiu       $a3, $t3, 0x5D34
    ctx->r7 = ADD32(ctx->r11, 0X5D34);
    // 0x8019B37C: lui         $a0, 0x2902
    ctx->r4 = S32(0X2902 << 16);
    // 0x8019B380: ori         $a0, $a0, 0x306C
    ctx->r4 = ctx->r4 | 0X306C;
    // 0x8019B384: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8019B388: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8019B38C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019B390: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    // 0x8019B394: jal         0x80019218
    // 0x8019B398: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    Audio_PlaySfx(rdram, ctx);
        goto after_17;
    // 0x8019B398: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    after_17:
    // 0x8019B39C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019B3A0: jal         0x8001A500
    // 0x8019B3A4: addiu       $a0, $a0, -0x10E4
    ctx->r4 = ADD32(ctx->r4, -0X10E4);
    Audio_KillSfxBySource(rdram, ctx);
        goto after_18;
    // 0x8019B3A4: addiu       $a0, $a0, -0x10E4
    ctx->r4 = ADD32(ctx->r4, -0X10E4);
    after_18:
    // 0x8019B3A8: lui         $at, 0x4090
    ctx->r1 = S32(0X4090 << 16);
    // 0x8019B3AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019B3B0: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8019B3B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019B3B8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019B3BC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8019B3C0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019B3C4: addiu       $v1, $v1, -0x4020
    ctx->r3 = ADD32(ctx->r3, -0X4020);
    // 0x8019B3C8: swc1        $f8, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f8.u32l;
    // 0x8019B3CC: swc1        $f10, 0x2F2C($v1)
    MEM_W(0X2F2C, ctx->r3) = ctx->f10.u32l;
    // 0x8019B3D0: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
    // 0x8019B3D4: swc1        $f16, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
L_8019B3D8:
    // 0x8019B3D8: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x8019B3DC: beq         $at, $zero, L_8019B458
    if (ctx->r1 == 0) {
        // 0x8019B3E0: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8019B458;
    }
    // 0x8019B3E0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019B3E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B3E8: lwc1        $f0, 0x75EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X75EC);
    // 0x8019B3EC: sh          $t5, 0xB2($s0)
    MEM_H(0XB2, ctx->r16) = ctx->r13;
    // 0x8019B3F0: addiu       $a0, $s0, 0x184
    ctx->r4 = ADD32(ctx->r16, 0X184);
    // 0x8019B3F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8019B3F8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019B3FC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019B400: jal         0x8009BC2C
    // 0x8019B404: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_19;
    // 0x8019B404: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_19:
    // 0x8019B408: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019B40C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019B410: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019B414: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B418: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8019B41C: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x8019B420: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8019B424: jal         0x8009BC2C
    // 0x8019B428: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_20;
    // 0x8019B428: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x8019B42C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019B430: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B434: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019B438: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x8019B43C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019B440: addiu       $a0, $a0, -0x10F4
    ctx->r4 = ADD32(ctx->r4, -0X10F4);
    // 0x8019B444: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8019B448: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8019B44C: jal         0x8009BC2C
    // 0x8019B450: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_21;
    // 0x8019B450: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_21:
    // 0x8019B454: lh          $v0, 0x56($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X56);
L_8019B458:
    // 0x8019B458: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8019B45C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019B460: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019B464: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x8019B468: nop

    // 0x8019B46C: bc1fl       L_8019B518
    if (!c1cs) {
        // 0x8019B470: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8019B518;
    }
    goto skip_4;
    // 0x8019B470: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_4:
    // 0x8019B474: jal         0x80198244
    // 0x8019B478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    SectorY_80198244(rdram, ctx);
        goto after_22;
    // 0x8019B478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_22:
    // 0x8019B47C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8019B480: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019B484: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019B488: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B48C: swc1        $f16, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
    // 0x8019B490: swc1        $f18, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f18.u32l;
    // 0x8019B494: lwc1        $f4, 0x75F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X75F0);
    // 0x8019B498: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x8019B49C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8019B4A0: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8019B4A4: lw          $t6, -0x7D58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D58);
    // 0x8019B4A8: lwc1        $f8, 0x75F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75F4);
    // 0x8019B4AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019B4B0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8019B4B4: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x8019B4B8: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019B4BC: swc1        $f6, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f6.u32l;
    // 0x8019B4C0: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x8019B4C4: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8019B4C8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8019B4CC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019B4D0: sw          $t7, 0x1C8($t8)
    MEM_W(0X1C8, ctx->r24) = ctx->r15;
    // 0x8019B4D4: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8019B4D8: jal         0x800B63BC
    // 0x8019B4DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Camera_UpdateArwing360(rdram, ctx);
        goto after_23;
    // 0x8019B4DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x8019B4E0: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8019B4E4: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8019B4E8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8019B4EC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019B4F0: addiu       $a0, $a0, 0x900
    ctx->r4 = ADD32(ctx->r4, 0X900);
    // 0x8019B4F4: swc1        $f16, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f16.u32l;
    // 0x8019B4F8: lh          $t0, 0xCC($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XCC);
    // 0x8019B4FC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8019B500: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8019B504: jal         0x800BA808
    // 0x8019B508: sh          $t1, 0xCC($s0)
    MEM_H(0XCC, ctx->r16) = ctx->r9;
    Radio_PlayMessage(rdram, ctx);
        goto after_24;
    // 0x8019B508: sh          $t1, 0xCC($s0)
    MEM_H(0XCC, ctx->r16) = ctx->r9;
    after_24:
    // 0x8019B50C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019B510: sw          $zero, 0x13A0($at)
    MEM_W(0X13A0, ctx->r1) = 0;
L_8019B514:
    // 0x8019B514: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8019B518:
    // 0x8019B518: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019B51C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019B520: jr          $ra
    // 0x8019B524: nop

    return;
    // 0x8019B524: nop

;}
RECOMP_FUNC void Andross_AndSuction_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018CF98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018CF9C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018CFA0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8018CFA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018CFA8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8018CFAC: lh          $t6, 0x4E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4E);
    // 0x8018CFB0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018CFB4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018CFB8: bne         $t6, $at, L_8018D044
    if (ctx->r14 != ctx->r1) {
        // 0x8018CFBC: addiu       $s0, $s0, 0x7E64
        ctx->r16 = ADD32(ctx->r16, 0X7E64);
            goto L_8018D044;
    }
    // 0x8018CFBC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018CFC0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8018CFC4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8018CFC8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018CFCC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8018CFD0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8018CFD4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8018CFD8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8018CFDC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018CFE0: lh          $t9, 0x44($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X44);
    // 0x8018CFE4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018CFE8: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x8018CFEC: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x8018CFF0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8018CFF4: lwc1        $f0, 0x70($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8018CFF8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018CFFC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018D000: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D004: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D008: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018D00C: jal         0x80005C34
    // 0x8018D010: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x8018D010: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_0:
    // 0x8018D014: jal         0x80006EB8
    // 0x8018D018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_1;
    // 0x8018D018: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8018D01C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D020: lui         $t5, 0x201
    ctx->r13 = S32(0X201 << 16);
    // 0x8018D024: addiu       $t5, $t5, 0xA30
    ctx->r13 = ADD32(ctx->r13, 0XA30);
    // 0x8018D028: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018D02C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8018D030: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8018D034: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018D038: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8018D03C: b           L_8018D0C8
    // 0x8018D040: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8018D0C8;
    // 0x8018D040: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018D044:
    // 0x8018D044: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D048: jal         0x800B8DD0
    // 0x8018D04C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8018D04C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_2:
    // 0x8018D050: lbu         $t6, 0x4C($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X4C);
    // 0x8018D054: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018D058: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8018D05C: beql        $at, $zero, L_8018D090
    if (ctx->r1 == 0) {
        // 0x8018D060: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8018D090;
    }
    goto skip_0;
    // 0x8018D060: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8018D064: lwc1        $f0, 0x70($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8018D068: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018D06C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018D070: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018D074: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018D078: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018D07C: jal         0x80005C34
    // 0x8018D080: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8018D080: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x8018D084: jal         0x80006EB8
    // 0x8018D088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8018D088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8018D08C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8018D090:
    // 0x8018D090: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8018D094: lui         $t2, 0x801A
    ctx->r10 = S32(0X801A << 16);
    // 0x8018D098: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8018D09C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D0A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018D0A4: lbu         $t0, 0x4C($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X4C);
    // 0x8018D0A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D0AC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8018D0B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8018D0B4: lw          $t2, 0x6790($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6790);
    // 0x8018D0B8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018D0BC: jal         0x800B8DD0
    // 0x8018D0C0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x8018D0C0: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_5:
    // 0x8018D0C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8018D0C8:
    // 0x8018D0C8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D0CC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8018D0D0: jr          $ra
    // 0x8018D0D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018D0D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Andross_AndBrainWaste_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801887B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801887B4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x801887B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801887BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801887C0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801887C4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801887C8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801887CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801887D0: jal         0x800613C4
    // 0x801887D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801887D4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x801887D8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801887DC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801887E0: addiu       $t7, $zero, 0x11E
    ctx->r15 = ADD32(0, 0X11E);
    // 0x801887E4: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x801887E8: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x801887EC: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801887F0: swc1        $f4, 0xE8($a2)
    MEM_W(0XE8, ctx->r6) = ctx->f4.u32l;
    // 0x801887F4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801887F8: swc1        $f6, 0xEC($a2)
    MEM_W(0XEC, ctx->r6) = ctx->f6.u32l;
    // 0x801887FC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80188800: swc1        $f8, 0xF0($a2)
    MEM_W(0XF0, ctx->r6) = ctx->f8.u32l;
    // 0x80188804: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80188808: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x8018880C: lwc1        $f16, 0x20($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80188810: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x80188814: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80188818: jal         0x80004EB0
    // 0x8018881C: swc1        $f18, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018881C: swc1        $f18, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f18.u32l;
    after_1:
    // 0x80188820: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80188824: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80188828: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8018882C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80188830: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80188834: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x80188838: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8018883C: bc1fl       L_80188858
    if (!c1cs) {
        // 0x80188840: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80188858;
    }
    goto skip_0;
    // 0x80188840: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_0:
    // 0x80188844: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80188848: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018884C: b           L_80188860
    // 0x80188850: swc1        $f6, 0x114($a2)
    MEM_W(0X114, ctx->r6) = ctx->f6.u32l;
        goto L_80188860;
    // 0x80188850: swc1        $f6, 0x114($a2)
    MEM_W(0X114, ctx->r6) = ctx->f6.u32l;
    // 0x80188854: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80188858:
    // 0x80188858: nop

    // 0x8018885C: swc1        $f8, 0x114($a2)
    MEM_W(0X114, ctx->r6) = ctx->f8.u32l;
L_80188860:
    // 0x80188860: sh          $t8, 0xBC($a2)
    MEM_H(0XBC, ctx->r6) = ctx->r24;
    // 0x80188864: jal         0x800612B8
    // 0x80188868: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x80188868: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_2:
    // 0x8018886C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80188870: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80188874: jr          $ra
    // 0x80188878: nop

    return;
    // 0x80188878: nop

;}
RECOMP_FUNC void SectorY_SyShogun_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197CC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80197CC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80197CCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80197CD0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80197CD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80197CD8: addiu       $t6, $zero, 0x157C
    ctx->r14 = ADD32(0, 0X157C);
    // 0x80197CDC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80197CE0: swc1        $f0, 0xFC($s0)
    MEM_W(0XFC, ctx->r16) = ctx->f0.u32l;
    // 0x80197CE4: sh          $t6, 0xCA($s0)
    MEM_H(0XCA, ctx->r16) = ctx->r14;
    // 0x80197CE8: sh          $t7, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r15;
    // 0x80197CEC: sh          $zero, 0x58($s0)
    MEM_H(0X58, ctx->r16) = 0;
    // 0x80197CF0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80197CF4: sw          $zero, 0x7A30($at)
    MEM_W(0X7A30, ctx->r1) = 0;
    // 0x80197CF8: lw          $v1, 0x40($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X40);
    // 0x80197CFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80197D00: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197D04: bne         $v1, $zero, L_80197DB8
    if (ctx->r3 != 0) {
        // 0x80197D08: lui         $v0, 0x603
        ctx->r2 = S32(0X603 << 16);
            goto L_80197DB8;
    }
    // 0x80197D08: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x80197D0C: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x80197D10: addiu       $v0, $v0, 0x42A0
    ctx->r2 = ADD32(ctx->r2, 0X42A0);
    // 0x80197D14: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80197D18: srl         $t9, $t8, 28
    ctx->r25 = S32(U32(ctx->r24) >> 28);
    // 0x80197D1C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80197D20: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80197D24: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80197D28: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80197D2C: lw          $t1, 0x1FD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1FD0);
    // 0x80197D30: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80197D34: and         $t2, $v0, $at
    ctx->r10 = ctx->r2 & ctx->r1;
    // 0x80197D38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80197D3C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80197D40: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80197D44: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x80197D48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80197D4C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80197D50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197D54: addiu       $t5, $zero, 0x96
    ctx->r13 = ADD32(0, 0X96);
    // 0x80197D58: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80197D5C: sw          $t4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r12;
    // 0x80197D60: sh          $t5, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r13;
    // 0x80197D64: sh          $t6, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = ctx->r14;
    // 0x80197D68: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x80197D6C: swc1        $f4, 0x184($s0)
    MEM_W(0X184, ctx->r16) = ctx->f4.u32l;
    // 0x80197D70: swc1        $f6, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f6.u32l;
    // 0x80197D74: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80197D78: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80197D7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197D80: lw          $t8, 0x1C8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C8);
    // 0x80197D84: bne         $t8, $at, L_80197DA8
    if (ctx->r24 != ctx->r1) {
        // 0x80197D88: lui         $at, 0x801A
        ctx->r1 = S32(0X801A << 16);
            goto L_80197DA8;
    }
    // 0x80197D88: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197D8C: lwc1        $f8, 0x7480($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7480);
    // 0x80197D90: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197D94: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80197D98: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80197D9C: lw          $t9, -0x7D58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D58);
    // 0x80197DA0: lwc1        $f10, 0x7484($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7484);
    // 0x80197DA4: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
L_80197DA8:
    // 0x80197DA8: jal         0x8019AEC0
    // 0x80197DAC: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    SectorY_8019AEC0(rdram, ctx);
        goto after_0;
    // 0x80197DAC: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    after_0:
    // 0x80197DB0: b           L_80197EA4
    // 0x80197DB4: nop

        goto L_80197EA4;
    // 0x80197DB4: nop

L_80197DB8:
    // 0x80197DB8: addiu       $v0, $v0, 0x4304
    ctx->r2 = ADD32(ctx->r2, 0X4304);
    // 0x80197DBC: lwc1        $f16, 0x7488($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7488);
    // 0x80197DC0: sll         $t0, $v0, 4
    ctx->r8 = S32(ctx->r2 << 4);
    // 0x80197DC4: srl         $t1, $t0, 28
    ctx->r9 = S32(U32(ctx->r8) >> 28);
    // 0x80197DC8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80197DCC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80197DD0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x80197DD4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80197DD8: swc1        $f16, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->f16.u32l;
    // 0x80197DDC: lw          $t3, 0x1FD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1FD0);
    // 0x80197DE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80197DE4: and         $t4, $v0, $at
    ctx->r12 = ctx->r2 & ctx->r1;
    // 0x80197DE8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80197DEC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80197DF0: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x80197DF4: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80197DF8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197DFC: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80197E00: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80197E04: sh          $t7, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r15;
    // 0x80197E08: sh          $zero, 0xC0($s0)
    MEM_H(0XC0, ctx->r16) = 0;
    // 0x80197E0C: sh          $a0, 0xBA($s0)
    MEM_H(0XBA, ctx->r16) = ctx->r4;
    // 0x80197E10: bne         $a0, $v1, L_80197E28
    if (ctx->r4 != ctx->r3) {
        // 0x80197E14: swc1        $f18, 0x18C($s0)
        MEM_W(0X18C, ctx->r16) = ctx->f18.u32l;
            goto L_80197E28;
    }
    // 0x80197E14: swc1        $f18, 0x18C($s0)
    MEM_W(0X18C, ctx->r16) = ctx->f18.u32l;
    // 0x80197E18: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80197E1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80197E20: b           L_80197E34
    // 0x80197E24: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
        goto L_80197E34;
    // 0x80197E24: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
L_80197E28:
    // 0x80197E28: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197E2C: lwc1        $f6, 0x748C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X748C);
    // 0x80197E30: swc1        $f6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f6.u32l;
L_80197E34:
    // 0x80197E34: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197E38: lwc1        $f10, 0x7490($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7490);
    // 0x80197E3C: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80197E40: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80197E44: jal         0x80023090
    // 0x80197E48: nop

    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80197E48: nop

    after_1:
    // 0x80197E4C: lwc1        $f16, 0x18C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80197E50: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197E54: lwc1        $f4, 0x7494($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7494);
    // 0x80197E58: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80197E5C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197E60: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80197E64: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80197E68: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x80197E6C: lwc1        $f10, 0x7498($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7498);
    // 0x80197E70: mul.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80197E74: jal         0x80023250
    // 0x80197E78: nop

    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80197E78: nop

    after_2:
    // 0x80197E7C: lwc1        $f16, 0x18C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18C);
    // 0x80197E80: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x80197E84: lwc1        $f4, 0x749C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X749C);
    // 0x80197E88: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80197E8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197E90: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80197E94: jal         0x80198244
    // 0x80197E98: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    SectorY_80198244(rdram, ctx);
        goto after_3;
    // 0x80197E98: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80197E9C: addiu       $t8, $zero, 0xFA
    ctx->r24 = ADD32(0, 0XFA);
    // 0x80197EA0: sh          $t8, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r24;
L_80197EA4:
    // 0x80197EA4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80197EA8: lw          $t9, 0x7880($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7880);
    // 0x80197EAC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80197EB0: bnel        $t9, $zero, L_80197F08
    if (ctx->r25 != 0) {
        // 0x80197EB4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80197F08;
    }
    goto skip_0;
    // 0x80197EB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80197EB8: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x80197EBC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80197EC0: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80197EC4: lw          $t0, 0x1C8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X1C8);
    // 0x80197EC8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80197ECC: lui         $a0, 0x1032
    ctx->r4 = S32(0X1032 << 16);
    // 0x80197ED0: bnel        $t0, $at, L_80197EFC
    if (ctx->r8 != ctx->r1) {
        // 0x80197ED4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80197EFC;
    }
    goto skip_1;
    // 0x80197ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x80197ED8: sw          $t1, 0x1C8($v0)
    MEM_W(0X1C8, ctx->r2) = ctx->r9;
    // 0x80197EDC: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x80197EE0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    // 0x80197EE4: jal         0x800182F4
    // 0x80197EE8: sw          $zero, 0x1D0($t2)
    MEM_W(0X1D0, ctx->r10) = 0;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_4;
    // 0x80197EE8: sw          $zero, 0x1D0($t2)
    MEM_W(0X1D0, ctx->r10) = 0;
    after_4:
    // 0x80197EEC: lui         $a0, 0x1132
    ctx->r4 = S32(0X1132 << 16);
    // 0x80197EF0: jal         0x800182F4
    // 0x80197EF4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_5;
    // 0x80197EF4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_5:
    // 0x80197EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80197EFC:
    // 0x80197EFC: jal         0x80060FBC
    // 0x80197F00: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    Object_Kill(rdram, ctx);
        goto after_6;
    // 0x80197F00: addiu       $a1, $s0, 0x3FC
    ctx->r5 = ADD32(ctx->r16, 0X3FC);
    after_6:
    // 0x80197F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80197F08:
    // 0x80197F08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80197F0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80197F10: jr          $ra
    // 0x80197F14: nop

    return;
    // 0x80197F14: nop

;}
RECOMP_FUNC void Andross_AndAndross_Explode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA94: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8018DA98: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8018DA9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DAA0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018DAA4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8018DAA8: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8018DAAC: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8018DAB0: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8018DAB4: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8018DAB8: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8018DABC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018DAC0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018DAC4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8018DAC8: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018DACC: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018DAD0: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018DAD4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DAD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DADC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018DAE0: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8018DAE4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8018DAE8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAEC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAF0: jal         0x8007BFFC
    // 0x8018DAF4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_0;
    // 0x8018DAF4: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8018DAF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DAFC: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8018DB00: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8018DB04: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018DB08: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018DB0C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018DB10: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018DB14: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_8018DB18:
    // 0x8018DB18: jal         0x80004EB0
    // 0x8018DB1C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8018DB1C: nop

    after_1:
    // 0x8018DB20: jal         0x80004EB0
    // 0x8018DB24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8018DB24: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_2:
    // 0x8018DB28: jal         0x80004EB0
    // 0x8018DB2C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8018DB2C: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_3:
    // 0x8018DB30: sub.s       $f6, $f22, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x8018DB34: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018DB38: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018DB3C: sub.s       $f16, $f24, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f20.fl;
    // 0x8018DB40: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x8018DB44: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018DB48: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8018DB4C: nop

    // 0x8018DB50: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8018DB54: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8018DB58: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018DB5C: add.s       $f8, $f6, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8018DB60: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8018DB64: jal         0x800794CC
    // 0x8018DB68: nop

    Effect_Effect357_Spawn50(rdram, ctx);
        goto after_4;
    // 0x8018DB68: nop

    after_4:
    // 0x8018DB6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018DB70: bne         $s1, $s2, L_8018DB18
    if (ctx->r17 != ctx->r18) {
        // 0x8018DB74: nop
    
            goto L_8018DB18;
    }
    // 0x8018DB74: nop

    // 0x8018DB78: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018DB7C: lwc1        $f14, 0x4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018DB80: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018DB84: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x8018DB88: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018DB8C: jal         0x8007B344
    // 0x8018DB90: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_5;
    // 0x8018DB90: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_5:
    // 0x8018DB94: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8018DB98: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8018DB9C: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8018DBA0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8018DBA4: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x8018DBA8: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8018DBAC: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x8018DBB0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018DBB4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8018DBB8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8018DBBC: jal         0x80019218
    // 0x8018DBC0: addiu       $a1, $a1, 0x3FC
    ctx->r5 = ADD32(ctx->r5, 0X3FC);
    Audio_PlaySfx(rdram, ctx);
        goto after_6;
    // 0x8018DBC0: addiu       $a1, $a1, 0x3FC
    ctx->r5 = ADD32(ctx->r5, 0X3FC);
    after_6:
    // 0x8018DBC4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8018DBC8: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018DBCC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018DBD0: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8018DBD4: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8018DBD8: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8018DBDC: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8018DBE0: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8018DBE4: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8018DBE8: jr          $ra
    // 0x8018DBEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8018DBEC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Venom2_Ve2Base_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019624C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80196250: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80196254: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80196258: beq         $a0, $at, L_8019626C
    if (ctx->r4 == ctx->r1) {
        // 0x8019625C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8019626C;
    }
    // 0x8019625C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80196260: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80196264: bne         $a0, $at, L_80196280
    if (ctx->r4 != ctx->r1) {
        // 0x80196268: nop
    
            goto L_80196280;
    }
    // 0x80196268: nop

L_8019626C:
    // 0x8019626C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80196270: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80196274: lwc1        $f6, 0xD8($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XD8);
    // 0x80196278: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8019627C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
L_80196280:
    // 0x80196280: jr          $ra
    // 0x80196284: nop

    return;
    // 0x80196284: nop

;}
RECOMP_FUNC void SectorY_SyShip4Destroyed_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A52B8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801A52BC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801A52C0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A52C4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801A52C8: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801A52CC: lw          $t6, 0x48($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X48);
    // 0x801A52D0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A52D4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A52D8: bne         $t6, $zero, L_801A530C
    if (ctx->r14 != 0) {
        // 0x801A52DC: lui         $a0, 0x1900
        ctx->r4 = S32(0X1900 << 16);
            goto L_801A530C;
    }
    // 0x801A52DC: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801A52E0: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801A52E4: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x801A52E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801A52EC: ori         $a0, $a0, 0x404F
    ctx->r4 = ctx->r4 | 0X404F;
    // 0x801A52F0: addiu       $a1, $s0, 0x70
    ctx->r5 = ADD32(ctx->r16, 0X70);
    // 0x801A52F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A52F8: jal         0x80019218
    // 0x801A52FC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x801A52FC: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_0:
    // 0x801A5300: lw          $t8, 0x48($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X48);
    // 0x801A5304: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801A5308: sw          $t9, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r25;
L_801A530C:
    // 0x801A530C: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801A5310: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x801A5314: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A5318: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x801A531C: bnel        $t1, $zero, L_801A5544
    if (ctx->r9 != 0) {
        // 0x801A5320: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_801A5544;
    }
    goto skip_0;
    // 0x801A5320: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x801A5324: lwc1        $f20, 0x7EB0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X7EB0);
    // 0x801A5328: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x801A532C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5330: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A5334: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801A5338: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A533C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A5340: jal         0x80005E90
    // 0x801A5344: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x801A5344: nop

    after_1:
    // 0x801A5348: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x801A534C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5350: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A5354: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x801A5358: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A535C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A5360: jal         0x80005D44
    // 0x801A5364: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801A5364: nop

    after_2:
    // 0x801A5368: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x801A536C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A5370: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A5374: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801A5378: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A537C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A5380: jal         0x80005FE0
    // 0x801A5384: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801A5384: nop

    after_3:
    // 0x801A5388: jal         0x80004EB0
    // 0x801A538C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x801A538C: nop

    after_4:
    // 0x801A5390: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A5394: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A5398: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A539C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A53A0: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801A53A4: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x801A53A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A53AC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A53B0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A53B4: jal         0x80004EB0
    // 0x801A53B8: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x801A53B8: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    after_5:
    // 0x801A53BC: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801A53C0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A53C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A53C8: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x801A53CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A53D0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801A53D4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A53D8: jal         0x80004EB0
    // 0x801A53DC: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801A53DC: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x801A53E0: sub.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801A53E4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A53E8: lwc1        $f18, 0x7EB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7EB4);
    // 0x801A53EC: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801A53F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A53F4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801A53F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A53FC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A5400: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801A5404: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x801A5408: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A540C: jal         0x80006970
    // 0x801A5410: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x801A5410: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x801A5414: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A5418: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A541C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A5420: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A5424: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A5428: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801A542C: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A5430: lwc1        $f16, 0x5C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801A5434: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x801A5438: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A543C: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A5440: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x801A5444: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A5448: lwc1        $f4, 0x7EB8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7EB8);
    // 0x801A544C: lwc1        $f18, 0x60($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801A5450: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801A5454: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x801A5458: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x801A545C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801A5460: jal         0x8007C120
    // 0x801A5464: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_8;
    // 0x801A5464: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_8:
    // 0x801A5468: jal         0x80004EB0
    // 0x801A546C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801A546C: nop

    after_9:
    // 0x801A5470: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801A5474: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A5478: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A547C: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x801A5480: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A5484: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A5488: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A548C: jal         0x80004EB0
    // 0x801A5490: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801A5490: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_10:
    // 0x801A5494: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801A5498: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x801A549C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A54A0: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801A54A4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A54A8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A54AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A54B0: jal         0x80004EB0
    // 0x801A54B4: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x801A54B4: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x801A54B8: sub.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801A54BC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A54C0: lwc1        $f4, 0x7EBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7EBC);
    // 0x801A54C4: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A54C8: lwc1        $f8, 0x7EC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7EC0);
    // 0x801A54CC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801A54D0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A54D4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A54D8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x801A54DC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x801A54E0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A54E4: jal         0x80006970
    // 0x801A54E8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x801A54E8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x801A54EC: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A54F0: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801A54F4: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x801A54F8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x801A54FC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A5500: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x801A5504: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A5508: lwc1        $f18, 0x5C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801A550C: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x801A5510: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A5514: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x801A5518: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801A551C: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A5520: lwc1        $f6, 0x7EC4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7EC4);
    // 0x801A5524: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x801A5528: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801A552C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x801A5530: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x801A5534: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x801A5538: jal         0x8007C120
    // 0x801A553C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_13;
    // 0x801A553C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_13:
    // 0x801A5540: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801A5544:
    // 0x801A5544: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801A5548: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801A554C: jr          $ra
    // 0x801A5550: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801A5550: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Andross_AndBrainEyes_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80189098: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018909C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801890A0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801890A4: addiu       $a0, $a0, 0x5D68
    ctx->r4 = ADD32(ctx->r4, 0X5D68);
    // 0x801890A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801890AC: jal         0x800613C4
    // 0x801890B0: nop

    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x801890B0: nop

    after_0:
    // 0x801890B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801890B8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801890BC: sb          $t6, 0x5D68($at)
    MEM_B(0X5D68, ctx->r1) = ctx->r14;
    // 0x801890C0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801890C4: addiu       $t7, $zero, 0xC5
    ctx->r15 = ADD32(0, 0XC5);
    // 0x801890C8: sh          $t7, 0x5D6A($at)
    MEM_H(0X5D6A, ctx->r1) = ctx->r15;
    // 0x801890CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801890D0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x801890D4: sh          $t8, 0x5E4C($at)
    MEM_H(0X5E4C, ctx->r1) = ctx->r24;
    // 0x801890D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801890DC: sh          $zero, 0x5E4E($at)
    MEM_H(0X5E4E, ctx->r1) = 0;
    // 0x801890E0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801890E4: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x801890E8: sh          $t9, 0x5E36($at)
    MEM_H(0X5E36, ctx->r1) = ctx->r25;
    // 0x801890EC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801890F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801890F4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801890F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801890FC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80189100: swc1        $f4, 0x5D6C($at)
    MEM_W(0X5D6C, ctx->r1) = ctx->f4.u32l;
    // 0x80189104: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189108: swc1        $f6, 0x5D70($at)
    MEM_W(0X5D70, ctx->r1) = ctx->f6.u32l;
    // 0x8018910C: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80189110: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80189114: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80189118: addiu       $a0, $a0, 0x5D84
    ctx->r4 = ADD32(ctx->r4, 0X5D84);
    // 0x8018911C: addiu       $a1, $zero, 0xC5
    ctx->r5 = ADD32(0, 0XC5);
    // 0x80189120: jal         0x800612B8
    // 0x80189124: swc1        $f8, 0x5D74($at)
    MEM_W(0X5D74, ctx->r1) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80189124: swc1        $f8, 0x5D74($at)
    MEM_W(0X5D74, ctx->r1) = ctx->f8.u32l;
    after_1:
    // 0x80189128: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8018912C: addiu       $v0, $v0, -0x4158
    ctx->r2 = ADD32(ctx->r2, -0X4158);
    // 0x80189130: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x80189134: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x80189138: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8018913C: addiu       $t4, $t4, 0x1FD0
    ctx->r12 = ADD32(ctx->r12, 0X1FD0);
    // 0x80189140: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80189144: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x80189148: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8018914C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80189150: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80189154: and         $a1, $v0, $at
    ctx->r5 = ctx->r2 & ctx->r1;
    // 0x80189158: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018915C: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x80189160: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x80189164: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80189168: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8018916C: addiu       $a0, $a2, 0x605C
    ctx->r4 = ADD32(ctx->r6, 0X605C);
    // 0x80189170: sw          $t7, 0x5D90($at)
    MEM_W(0X5D90, ctx->r1) = ctx->r15;
    // 0x80189174: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80189178: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8018917C: jal         0x800613C4
    // 0x80189180: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    Actor_Initialize(rdram, ctx);
        goto after_2;
    // 0x80189180: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_2:
    // 0x80189184: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80189188: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x8018918C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189190: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80189194: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80189198: addiu       $t9, $zero, 0xC5
    ctx->r25 = ADD32(0, 0XC5);
    // 0x8018919C: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801891A0: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x801891A4: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x801891A8: sh          $t9, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r25;
    // 0x801891AC: sh          $t0, 0xE4($a2)
    MEM_H(0XE4, ctx->r6) = ctx->r8;
    // 0x801891B0: sh          $zero, 0xE6($a2)
    MEM_H(0XE6, ctx->r6) = 0;
    // 0x801891B4: sh          $t1, 0xCE($a2)
    MEM_H(0XCE, ctx->r6) = ctx->r9;
    // 0x801891B8: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x801891BC: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x801891C0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801891C4: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    // 0x801891C8: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x801891CC: lwc1        $f18, 0xC($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0XC);
    // 0x801891D0: jal         0x800612B8
    // 0x801891D4: swc1        $f18, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f18.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x801891D4: swc1        $f18, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f18.u32l;
    after_3:
    // 0x801891D8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801891DC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x801891E0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801891E4: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801891E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801891EC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801891F0: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x801891F4: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x801891F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x801891FC: sw          $t7, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r15;
    // 0x80189200: sh          $t8, 0x4098($at)
    MEM_H(0X4098, ctx->r1) = ctx->r24;
    // 0x80189204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80189208: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018920C: jr          $ra
    // 0x80189210: nop

    return;
    // 0x80189210: nop

;}
RECOMP_FUNC void SectorY_8019B528(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B528: lh          $t6, 0x50($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X50);
    // 0x8019B52C: beql        $t6, $zero, L_8019B540
    if (ctx->r14 == 0) {
        // 0x8019B530: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_8019B540;
    }
    goto skip_0;
    // 0x8019B530: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_0:
    // 0x8019B534: jr          $ra
    // 0x8019B538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8019B538: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019B53C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_8019B540:
    // 0x8019B540: lwc1        $f0, 0x4($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8019B544: c.le.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl <= ctx->f0.fl;
    // 0x8019B548: nop

    // 0x8019B54C: bc1fl       L_8019B560
    if (!c1cs) {
        // 0x8019B550: neg.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
            goto L_8019B560;
    }
    goto skip_1;
    // 0x8019B550: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    skip_1:
    // 0x8019B554: b           L_8019B560
    // 0x8019B558: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8019B560;
    // 0x8019B558: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8019B55C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_8019B560:
    // 0x8019B560: lh          $t7, 0xCA($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XCA);
    // 0x8019B564: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8019B568: nop

    // 0x8019B56C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019B570: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8019B574: nop

    // 0x8019B578: bc1fl       L_8019B58C
    if (!c1cs) {
        // 0x8019B57C: lwc1        $f12, 0xC($a0)
        ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
            goto L_8019B58C;
    }
    goto skip_2;
    // 0x8019B57C: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x8019B580: jr          $ra
    // 0x8019B584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8019B584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8019B588: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
L_8019B58C:
    // 0x8019B58C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019B590: c.le.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl <= ctx->f12.fl;
    // 0x8019B594: nop

    // 0x8019B598: bc1fl       L_8019B5AC
    if (!c1cs) {
        // 0x8019B59C: neg.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
            goto L_8019B5AC;
    }
    goto skip_3;
    // 0x8019B59C: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    skip_3:
    // 0x8019B5A0: b           L_8019B5AC
    // 0x8019B5A4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
        goto L_8019B5AC;
    // 0x8019B5A4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8019B5A8: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
L_8019B5AC:
    // 0x8019B5AC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8019B5B0: nop

    // 0x8019B5B4: bc1f        L_8019B5C4
    if (!c1cs) {
        // 0x8019B5B8: nop
    
            goto L_8019B5C4;
    }
    // 0x8019B5B8: nop

    // 0x8019B5BC: jr          $ra
    // 0x8019B5C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8019B5C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8019B5C4:
    // 0x8019B5C4: jr          $ra
    // 0x8019B5C8: nop

    return;
    // 0x8019B5C8: nop

;}
RECOMP_FUNC void SectorY_8019A82C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A82C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019A830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019A834: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8019A838: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8019A83C: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8019A840: sh          $t6, 0xB0($a2)
    MEM_H(0XB0, ctx->r6) = ctx->r14;
    // 0x8019A844: swc1        $f4, 0xFC($a2)
    MEM_W(0XFC, ctx->r6) = ctx->f4.u32l;
    // 0x8019A848: jal         0x80004EB0
    // 0x8019A84C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x8019A84C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8019A850: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8019A854: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019A858: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8019A85C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019A860: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8019A864: addiu       $a0, $a0, 0x9AC
    ctx->r4 = ADD32(ctx->r4, 0X9AC);
    // 0x8019A868: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8019A86C: sh          $zero, 0x56($a2)
    MEM_H(0X56, ctx->r6) = 0;
    // 0x8019A870: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019A874: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8019A878: nop

    // 0x8019A87C: addiu       $t9, $t8, 0x154
    ctx->r25 = ADD32(ctx->r24, 0X154);
    // 0x8019A880: jal         0x8002E4F8
    // 0x8019A884: sh          $t9, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r25;
    AllRange_PlayMessage(rdram, ctx);
        goto after_1;
    // 0x8019A884: sh          $t9, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r25;
    after_1:
    // 0x8019A888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019A88C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019A890: jr          $ra
    // 0x8019A894: nop

    return;
    // 0x8019A894: nop

;}
