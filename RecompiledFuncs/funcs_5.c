#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Effect_Sparkle_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078F78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80078F7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80078F80: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80078F84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80078F88: lh          $t6, 0x4E($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4E);
    // 0x80078F8C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80078F90: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80078F94: beq         $t6, $zero, L_80078FBC
    if (ctx->r14 == 0) {
        // 0x80078F98: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80078FBC;
    }
    // 0x80078F98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078F9C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80078FA0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80078FA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80078FA8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x80078FAC: jal         0x800B8DD0
    // 0x80078FB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80078FB0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80078FB4: b           L_80078FCC
    // 0x80078FB8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
        goto L_80078FCC;
    // 0x80078FB8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80078FBC:
    // 0x80078FBC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80078FC0: jal         0x800B8DD0
    // 0x80078FC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80078FC4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80078FC8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
L_80078FCC:
    // 0x80078FCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078FD0: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80078FD4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80078FD8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80078FDC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80078FE0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80078FE4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80078FE8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80078FEC: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
    // 0x80078FF0: ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // 0x80078FF4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80078FF8: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80078FFC: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x80079000: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80079004: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80079008: lwc1        $f4, 0x70($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X70);
    // 0x8007900C: lwc1        $f6, 0x6C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X6C);
    // 0x80079010: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80079014: jal         0x8005980C
    // 0x80079018: nop

    Graphics_SetScaleMtx(rdram, ctx);
        goto after_2;
    // 0x80079018: nop

    after_2:
    // 0x8007901C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80079020: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x80079024: addiu       $t5, $t5, -0x3D20
    ctx->r13 = ADD32(ctx->r13, -0X3D20);
    // 0x80079028: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007902C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80079030: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80079034: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80079038: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007903C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80079040: jal         0x800B8DD0
    // 0x80079044: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80079044: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x80079048: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007904C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079050: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80079054: jr          $ra
    // 0x80079058: nop

    return;
    // 0x80079058: nop

;}
RECOMP_FUNC void Audio_StartReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DE1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DE20: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x8001DE24: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8001DE28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DE2C: bne         $v0, $at, L_8001DE5C
    if (ctx->r2 != ctx->r1) {
        // 0x8001DE30: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8001DE5C;
    }
    // 0x8001DE30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8001DE34: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001DE38: lbu         $v0, 0x5D54($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5D54);
    // 0x8001DE3C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8001DE40: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8001DE44: beq         $v0, $at, L_8001DE50
    if (ctx->r2 == ctx->r1) {
        // 0x8001DE48: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8001DE50;
    }
    // 0x8001DE48: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8001DE4C: bne         $v0, $at, L_8001DE90
    if (ctx->r2 != ctx->r1) {
        // 0x8001DE50: lui         $at, 0x800C
        ctx->r1 = S32(0X800C << 16);
            goto L_8001DE90;
    }
L_8001DE50:
    // 0x8001DE50: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001DE54: b           L_8001DE90
    // 0x8001DE58: sb          $t7, 0x5D58($at)
    MEM_B(0X5D58, ctx->r1) = ctx->r15;
        goto L_8001DE90;
    // 0x8001DE58: sb          $t7, 0x5D58($at)
    MEM_B(0X5D58, ctx->r1) = ctx->r15;
L_8001DE5C:
    // 0x8001DE5C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8001DE60: bne         $v0, $at, L_8001DE84
    if (ctx->r2 != ctx->r1) {
        // 0x8001DE64: lui         $t8, 0x800C
        ctx->r24 = S32(0X800C << 16);
            goto L_8001DE84;
    }
    // 0x8001DE64: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x8001DE68: lbu         $t8, 0x5D54($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X5D54);
    // 0x8001DE6C: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8001DE70: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8001DE74: bne         $t8, $at, L_8001DE84
    if (ctx->r24 != ctx->r1) {
        // 0x8001DE78: lui         $at, 0x800C
        ctx->r1 = S32(0X800C << 16);
            goto L_8001DE84;
    }
    // 0x8001DE78: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001DE7C: b           L_8001DE90
    // 0x8001DE80: sb          $t9, 0x5D58($at)
    MEM_B(0X5D58, ctx->r1) = ctx->r25;
        goto L_8001DE90;
    // 0x8001DE80: sb          $t9, 0x5D58($at)
    MEM_B(0X5D58, ctx->r1) = ctx->r25;
L_8001DE84:
    // 0x8001DE84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001DE88: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001DE8C: sb          $t0, 0x5D58($at)
    MEM_B(0X5D58, ctx->r1) = ctx->r8;
L_8001DE90:
    // 0x8001DE90: lui         $a0, 0xF200
    ctx->r4 = S32(0XF200 << 16);
    // 0x8001DE94: jal         0x8001E8CC
    // 0x8001DE98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_0;
    // 0x8001DE98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8001DE9C: jal         0x8001BC48
    // 0x8001DEA0: nop

    Audio_ResetVoicesAndPlayers(rdram, ctx);
        goto after_1;
    // 0x8001DEA0: nop

    after_1:
    // 0x8001DEA4: jal         0x80017588
    // 0x8001DEA8: nop

    Audio_ResetSfxChannelState(rdram, ctx);
        goto after_2;
    // 0x8001DEA8: nop

    after_2:
    // 0x8001DEAC: jal         0x80019068
    // 0x8001DEB0: nop

    Audio_ResetActiveSequences(rdram, ctx);
        goto after_3;
    // 0x8001DEB0: nop

    after_3:
    // 0x8001DEB4: jal         0x8001AB50
    // 0x8001DEB8: nop

    Audio_ResetSfx(rdram, ctx);
        goto after_4;
    // 0x8001DEB8: nop

    after_4:
    // 0x8001DEBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DEC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001DEC4: jr          $ra
    // 0x8001DEC8: nop

    return;
    // 0x8001DEC8: nop

;}
RECOMP_FUNC void MeteoBall_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800598E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800598EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800598F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800598F4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800598F8: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800598FC: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x80059900: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x80059904: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80059908: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8005990C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80059910: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80059914: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80059918: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8005991C: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80059920: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80059924: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80059928: jal         0x800B9B38
    // 0x8005992C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_60(rdram, ctx);
        goto after_0;
    // 0x8005992C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80059930: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80059934: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x80059938: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8005993C: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x80059940: addiu       $t1, $t1, 0x5B50
    ctx->r9 = ADD32(ctx->r9, 0X5B50);
    // 0x80059944: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80059948: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8005994C: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80059950: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80059954: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80059958: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8005995C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80059960: lw          $t3, -0x7C24($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C24);
    // 0x80059964: lw          $t2, -0x7C28($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7C28);
    // 0x80059968: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8005996C: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80059970: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80059974: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80059978: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8005997C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80059980: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80059984: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80059988: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8005998C: jal         0x800BA1D0
    // 0x80059990: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    RCP_SetupDL_29(rdram, ctx);
        goto after_1;
    // 0x80059990: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_1:
    // 0x80059994: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059998: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005999C: jr          $ra
    // 0x800599A0: nop

    return;
    // 0x800599A0: nop

;}
RECOMP_FUNC void func_versus_800C0B0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0B0C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C0B10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C0B14: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C0B18: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800C0B1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0B20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C0B24: jal         0x800B8DD0
    // 0x800C0B28: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800C0B28: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x800C0B2C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C0B30: lw          $a0, -0x785C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X785C);
    // 0x800C0B34: addiu       $v0, $sp, 0x38
    ctx->r2 = ADD32(ctx->r29, 0X38);
    // 0x800C0B38: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800C0B3C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C0B40: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800C0B44: addiu       $a0, $a0, -0x7854
    ctx->r4 = ADD32(ctx->r4, -0X7854);
    // 0x800C0B48: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x800C0B4C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
L_800C0B50:
    // 0x800C0B50: bnel        $v0, $v1, L_800C0B70
    if (ctx->r2 != ctx->r3) {
        // 0x800C0B54: sw          $a2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r6;
            goto L_800C0B70;
    }
    goto skip_0;
    // 0x800C0B54: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    skip_0:
    // 0x800C0B58: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C0B5C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800C0B60: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800C0B64: b           L_800C0B70
    // 0x800C0B68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_800C0B70;
    // 0x800C0B68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800C0B6C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_800C0B70:
    // 0x800C0B70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C0B74: bne         $v0, $a1, L_800C0B50
    if (ctx->r2 != ctx->r5) {
        // 0x800C0B78: nop
    
            goto L_800C0B50;
    }
    // 0x800C0B78: nop

    // 0x800C0B7C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C0B80: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C0B84: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800C0B88: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800C0B8C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x800C0B90: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800C0B94: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800C0B98: andi        $t2, $a0, 0xFF
    ctx->r10 = ctx->r4 & 0XFF;
    // 0x800C0B9C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x800C0BA0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800C0BA4: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x800C0BA8: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x800C0BAC: ori         $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 | 0XFF;
    // 0x800C0BB0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800C0BB4: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x800C0BB8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0BBC: lui         $at, 0x4294
    ctx->r1 = S32(0X4294 << 16);
    // 0x800C0BC0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C0BC4: jal         0x800BD05C
    // 0x800C0BC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_versus_800BD05C(rdram, ctx);
        goto after_1;
    // 0x800C0BC8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_1:
    // 0x800C0BCC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C0BD0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800C0BD4: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800C0BD8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800C0BDC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800C0BE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800C0BE4: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800C0BE8: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
    // 0x800C0BEC: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800C0BF0: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x800C0BF4: sll         $t3, $t0, 16
    ctx->r11 = S32(ctx->r8 << 16);
    // 0x800C0BF8: or          $t4, $t2, $t3
    ctx->r12 = ctx->r10 | ctx->r11;
    // 0x800C0BFC: ori         $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 | 0XFF;
    // 0x800C0C00: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800C0C04: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x800C0C08: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0C0C: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
    // 0x800C0C10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C0C14: jal         0x800BD0B4
    // 0x800C0C18: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_versus_800BD0B4(rdram, ctx);
        goto after_2;
    // 0x800C0C18: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_2:
    // 0x800C0C1C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800C0C20: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800C0C24: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800C0C28: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C0C2C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800C0C30: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C0C34: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800C0C38: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800C0C3C: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800C0C40: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x800C0C44: sll         $t1, $t8, 16
    ctx->r9 = S32(ctx->r24 << 16);
    // 0x800C0C48: or          $t2, $t0, $t1
    ctx->r10 = ctx->r8 | ctx->r9;
    // 0x800C0C4C: ori         $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 | 0XFF;
    // 0x800C0C50: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800C0C54: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x800C0C58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0C5C: lui         $at, 0x431A
    ctx->r1 = S32(0X431A << 16);
    // 0x800C0C60: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800C0C64: jal         0x800BD10C
    // 0x800C0C68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    func_versus_800BD10C(rdram, ctx);
        goto after_3;
    // 0x800C0C68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_3:
    // 0x800C0C6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0C70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0C74: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C0C78: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800C0C7C: jr          $ra
    // 0x800C0C80: nop

    return;
    // 0x800C0C80: nop

;}
RECOMP_FUNC void Lib_SwapBuffers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002EE4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80002EE8: blez        $a2, L_80002F80
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80002EEC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80002F80;
    }
    // 0x80002EEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80002EF0: andi        $v1, $a2, 0x3
    ctx->r3 = ctx->r6 & 0X3;
    // 0x80002EF4: beq         $v1, $zero, L_80002F28
    if (ctx->r3 == 0) {
        // 0x80002EF8: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80002F28;
    }
    // 0x80002EF8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80002EFC: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80002F00: addu        $t0, $a3, $zero
    ctx->r8 = ADD32(ctx->r7, 0);
L_80002F04:
    // 0x80002F04: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x80002F08: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80002F0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80002F10: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80002F14: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80002F18: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80002F1C: bne         $t1, $v0, L_80002F04
    if (ctx->r9 != ctx->r2) {
        // 0x80002F20: sb          $v1, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r3;
            goto L_80002F04;
    }
    // 0x80002F20: sb          $v1, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r3;
    // 0x80002F24: beq         $v0, $a2, L_80002F80
    if (ctx->r2 == ctx->r6) {
        // 0x80002F28: addu        $a0, $a1, $v0
        ctx->r4 = ADD32(ctx->r5, ctx->r2);
            goto L_80002F80;
    }
L_80002F28:
    // 0x80002F28: addu        $a0, $a1, $v0
    ctx->r4 = ADD32(ctx->r5, ctx->r2);
    // 0x80002F2C: addu        $t0, $a3, $v0
    ctx->r8 = ADD32(ctx->r7, ctx->r2);
L_80002F30:
    // 0x80002F30: lbu         $t7, 0x0($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X0);
    // 0x80002F34: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80002F38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80002F3C: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x80002F40: lbu         $t8, 0x1($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X1);
    // 0x80002F44: sb          $v1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r3;
    // 0x80002F48: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x80002F4C: sb          $t8, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r24;
    // 0x80002F50: lbu         $t9, 0x2($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X2);
    // 0x80002F54: sb          $v1, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r3;
    // 0x80002F58: lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2);
    // 0x80002F5C: sb          $t9, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r25;
    // 0x80002F60: lbu         $t2, 0x3($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X3);
    // 0x80002F64: sb          $v1, 0x2($t0)
    MEM_B(0X2, ctx->r8) = ctx->r3;
    // 0x80002F68: lbu         $v1, 0x3($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X3);
    // 0x80002F6C: sb          $t2, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r10;
    // 0x80002F70: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80002F74: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80002F78: bne         $v0, $a2, L_80002F30
    if (ctx->r2 != ctx->r6) {
        // 0x80002F7C: sb          $v1, -0x1($t0)
        MEM_B(-0X1, ctx->r8) = ctx->r3;
            goto L_80002F30;
    }
    // 0x80002F7C: sb          $v1, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r3;
L_80002F80:
    // 0x80002F80: jr          $ra
    // 0x80002F84: nop

    return;
    // 0x80002F84: nop

;}
RECOMP_FUNC void Display_PlayerShadow_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056E2C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80056E30: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80056E34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80056E38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80056E3C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80056E40: lw          $t6, 0x234($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X234);
    // 0x80056E44: beql        $t6, $zero, L_80057238
    if (ctx->r14 == 0) {
        // 0x80056E48: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80057238;
    }
    goto skip_0;
    // 0x80056E48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80056E4C: lw          $t7, 0x240($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X240);
    // 0x80056E50: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x80056E54: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80056E58: bne         $t7, $zero, L_80057234
    if (ctx->r15 != 0) {
        // 0x80056E5C: lui         $s1, 0x8014
        ctx->r17 = S32(0X8014 << 16);
            goto L_80057234;
    }
    // 0x80056E5C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80056E60: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80056E64: lw          $t5, 0x1D4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1D4);
    // 0x80056E68: addiu       $v1, $v1, -0x5CCC
    ctx->r3 = ADD32(ctx->r3, -0X5CCC);
    // 0x80056E6C: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x80056E70: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80056E74: andi        $t8, $v0, 0x7
    ctx->r24 = ctx->r2 & 0X7;
    // 0x80056E78: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80056E7C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80056E80: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x80056E84: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x80056E88: lwc1        $f0, 0x0($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80056E8C: beq         $t5, $zero, L_80056EA0
    if (ctx->r13 == 0) {
        // 0x80056E90: lwc1        $f2, 0x0($t4)
        ctx->f2.u32l = MEM_W(ctx->r12, 0X0);
            goto L_80056EA0;
    }
    // 0x80056E90: lwc1        $f2, 0x0($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80056E94: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80056E98: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80056E9C: nop

L_80056EA0:
    // 0x80056EA0: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80056EA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80056EA8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80056EAC: jal         0x80005708
    // 0x80056EB0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80056EB0: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80056EB4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80056EB8: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x80056EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056EC0: bnel        $t6, $at, L_80056F48
    if (ctx->r14 != ctx->r1) {
        // 0x80056EC4: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80056F48;
    }
    goto skip_1;
    // 0x80056EC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    skip_1:
    // 0x80056EC8: lw          $t7, 0x1CC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1CC);
    // 0x80056ECC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80056ED0: bne         $t7, $at, L_80056F0C
    if (ctx->r15 != ctx->r1) {
        // 0x80056ED4: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80056F0C;
    }
    // 0x80056ED4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80056ED8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80056EDC: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80056EE0: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80056EE4: lw          $a3, 0x6C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X6C);
    // 0x80056EE8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056EEC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80056EF0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80056EF4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80056EF8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80056EFC: jal         0x80005B00
    // 0x80056F00: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x80056F00: nop

    after_1:
    // 0x80056F04: b           L_80056F84
    // 0x80056F08: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
        goto L_80056F84;
    // 0x80056F08: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80056F0C:
    // 0x80056F0C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80056F10: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80056F14: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80056F18: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80056F1C: lw          $a3, 0x6C($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X6C);
    // 0x80056F20: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80056F24: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80056F28: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80056F2C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80056F30: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80056F34: jal         0x80005B00
    // 0x80056F38: nop

    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x80056F38: nop

    after_2:
    // 0x80056F3C: b           L_80056F84
    // 0x80056F40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
        goto L_80056F84;
    // 0x80056F40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80056F44: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
L_80056F48:
    // 0x80056F48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80056F4C: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80056F50: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80056F54: lwc1        $f16, 0x144($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X144);
    // 0x80056F58: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80056F5C: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x80056F60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80056F64: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80056F68: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80056F6C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80056F70: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80056F74: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80056F78: jal         0x80005B00
    // 0x80056F7C: nop

    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x80056F7C: nop

    after_3:
    // 0x80056F80: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_80056F84:
    // 0x80056F84: lw          $a1, 0x70($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X70);
    // 0x80056F88: jal         0x80005E90
    // 0x80056F8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x80056F8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80056F90: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80056F94: lw          $a1, 0x248($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X248);
    // 0x80056F98: jal         0x80005D44
    // 0x80056F9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x80056F9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80056FA0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80056FA4: lw          $a1, 0x24C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24C);
    // 0x80056FA8: jal         0x80005FE0
    // 0x80056FAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x80056FAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80056FB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80056FB4: lwc1        $f0, 0x5F3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5F3C);
    // 0x80056FB8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80056FBC: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80056FC0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80056FC4: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80056FC8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80056FCC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80056FD0: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80056FD4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80056FD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80056FDC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80056FE0: jal         0x80005C34
    // 0x80056FE4: nop

    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x80056FE4: nop

    after_7:
    // 0x80056FE8: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x80056FEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80056FF0: beql        $v0, $zero, L_8005700C
    if (ctx->r2 == 0) {
        // 0x80056FF4: lwc1        $f16, 0xF8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
            goto L_8005700C;
    }
    goto skip_2;
    // 0x80056FF4: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
    skip_2:
    // 0x80056FF8: beq         $v0, $at, L_80057008
    if (ctx->r2 == ctx->r1) {
        // 0x80056FFC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80057008;
    }
    // 0x80056FFC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057000: bne         $v0, $at, L_80057144
    if (ctx->r2 != ctx->r1) {
        // 0x80057004: nop
    
            goto L_80057144;
    }
    // 0x80057004: nop

L_80057008:
    // 0x80057008: lwc1        $f16, 0xF8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XF8);
L_8005700C:
    // 0x8005700C: lwc1        $f18, 0xF0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80057010: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80057014: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80057018: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8005701C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80057020: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80057024: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80057028: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8005702C: nop

    // 0x80057030: bc1fl       L_80057050
    if (!c1cs) {
        // 0x80057034: lui         $at, 0xC28C
        ctx->r1 = S32(0XC28C << 16);
            goto L_80057050;
    }
    goto skip_3;
    // 0x80057034: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    skip_3:
    // 0x80057038: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005703C: nop

    // 0x80057040: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80057044: nop

    // 0x80057048: bc1t        L_80057080
    if (c1cs) {
        // 0x8005704C: lui         $at, 0xC28C
        ctx->r1 = S32(0XC28C << 16);
            goto L_80057080;
    }
    // 0x8005704C: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
L_80057050:
    // 0x80057050: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80057054: lui         $at, 0xC2DC
    ctx->r1 = S32(0XC2DC << 16);
    // 0x80057058: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8005705C: nop

    // 0x80057060: bc1fl       L_80057088
    if (!c1cs) {
        // 0x80057064: lwc1        $f18, 0x70($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
            goto L_80057088;
    }
    goto skip_4;
    // 0x80057064: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    skip_4:
    // 0x80057068: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8005706C: nop

    // 0x80057070: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80057074: nop

    // 0x80057078: bc1fl       L_80057088
    if (!c1cs) {
        // 0x8005707C: lwc1        $f18, 0x70($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
            goto L_80057088;
    }
    goto skip_5;
    // 0x8005707C: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    skip_5:
L_80057080:
    // 0x80057080: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80057084: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
L_80057088:
    // 0x80057088: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8005708C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80057090: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80057094: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057098: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005709C: jal         0x80005E90
    // 0x800570A0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x800570A0: nop

    after_8:
    // 0x800570A4: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800570A8: lwc1        $f8, 0xE8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800570AC: lwc1        $f16, 0x134($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800570B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800570B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800570B8: lwc1        $f4, 0x5F40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F40);
    // 0x800570BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800570C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800570C4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800570C8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800570CC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800570D0: jal         0x80005E90
    // 0x800570D4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_9;
    // 0x800570D4: nop

    after_9:
    // 0x800570D8: lwc1        $f8, 0x120($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X120);
    // 0x800570DC: lwc1        $f10, 0xE4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800570E0: lwc1        $f18, 0x4D8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x800570E4: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800570E8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800570EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800570F0: lwc1        $f10, 0x5F44($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F44);
    // 0x800570F4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800570F8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800570FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057100: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80057104: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80057108: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8005710C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80057110: jal         0x80005D44
    // 0x80057114: nop

    Matrix_RotateX(rdram, ctx);
        goto after_10;
    // 0x80057114: nop

    after_10:
    // 0x80057118: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005711C: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80057120: lwc1        $f4, 0x5F48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5F48);
    // 0x80057124: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80057128: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005712C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80057130: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80057134: jal         0x80005FE0
    // 0x80057138: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_11;
    // 0x80057138: nop

    after_11:
    // 0x8005713C: b           L_80057224
    // 0x80057140: nop

        goto L_80057224;
    // 0x80057140: nop

L_80057144:
    // 0x80057144: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057148: lwc1        $f10, 0x5F4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5F4C);
    // 0x8005714C: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80057150: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80057154: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057158: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8005715C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80057160: jal         0x80005E90
    // 0x80057164: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x80057164: nop

    after_12:
    // 0x80057168: lwc1        $f18, 0xE4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x8005716C: lwc1        $f4, 0x4D8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4D8);
    // 0x80057170: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80057174: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057178: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8005717C: lwc1        $f16, 0x5F50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5F50);
    // 0x80057180: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80057184: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057188: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005718C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80057190: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80057194: jal         0x80005D44
    // 0x80057198: nop

    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x80057198: nop

    after_13:
    // 0x8005719C: lwc1        $f4, 0xEC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800571A0: lwc1        $f6, 0xF0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800571A4: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800571A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800571AC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800571B0: lwc1        $f18, 0x5F54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5F54);
    // 0x800571B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800571B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800571BC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800571C0: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800571C4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800571C8: jal         0x80005FE0
    // 0x800571CC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_14;
    // 0x800571CC: nop

    after_14:
    // 0x800571D0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800571D4: lwc1        $f8, 0x5F58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F58);
    // 0x800571D8: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800571DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800571E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800571E4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800571E8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800571EC: jal         0x80005E90
    // 0x800571F0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_15;
    // 0x800571F0: nop

    after_15:
    // 0x800571F4: lwc1        $f16, 0x12C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800571F8: lwc1        $f4, 0x130($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X130);
    // 0x800571FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80057200: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80057204: lwc1        $f8, 0x5F5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5F5C);
    // 0x80057208: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005720C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80057210: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80057214: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80057218: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005721C: jal         0x80005FE0
    // 0x80057220: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_16;
    // 0x80057220: nop

    after_16:
L_80057224:
    // 0x80057224: jal         0x80054300
    // 0x80057228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Display_PlayerShadow_Draw(rdram, ctx);
        goto after_17;
    // 0x80057228: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8005722C: jal         0x80005740
    // 0x80057230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_18;
    // 0x80057230: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_18:
L_80057234:
    // 0x80057234: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80057238:
    // 0x80057238: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005723C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80057240: jr          $ra
    // 0x80057244: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80057244: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Lib_InitOrtho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800032B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800032B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800032BC: addiu       $v0, $v0, 0x7E5C
    ctx->r2 = ADD32(ctx->r2, 0X7E5C);
    // 0x800032C0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800032C4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800032C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800032CC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800032D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800032D4: lwc1        $f6, 0x1A40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X1A40);
    // 0x800032D8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800032DC: lwc1        $f8, 0x1A44($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1A44);
    // 0x800032E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800032E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800032E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800032EC: lui         $a1, 0xC320
    ctx->r5 = S32(0XC320 << 16);
    // 0x800032F0: lui         $a2, 0x4320
    ctx->r6 = S32(0X4320 << 16);
    // 0x800032F4: lui         $a3, 0xC2F0
    ctx->r7 = S32(0XC2F0 << 16);
    // 0x800032F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800032FC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80003300: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80003304: jal         0x80021654
    // 0x80003308: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guOrtho(rdram, ctx);
        goto after_0;
    // 0x80003308: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8000330C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80003310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80003314: addiu       $v0, $v0, 0x7E5C
    ctx->r2 = ADD32(ctx->r2, 0X7E5C);
    // 0x80003318: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x8000331C: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80003320: lui         $t7, 0x103
    ctx->r15 = S32(0X103 << 16);
    // 0x80003324: ori         $t7, $t7, 0x40
    ctx->r15 = ctx->r15 | 0X40;
    // 0x80003328: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x8000332C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80003330: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80003334: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80003338: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8000333C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80003340: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80003344: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80003348: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8000334C: lui         $at, 0xC648
    ctx->r1 = S32(0XC648 << 16);
    // 0x80003350: addiu       $t2, $t9, 0x40
    ctx->r10 = ADD32(ctx->r25, 0X40);
    // 0x80003354: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80003358: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000335C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80003360: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80003364: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80003368: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8000336C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80003370: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80003374: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80003378: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8000337C: jal         0x80021488
    // 0x80003380: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    guLookAt(rdram, ctx);
        goto after_1;
    // 0x80003380: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x80003384: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80003388: addiu       $v0, $v0, 0x7E5C
    ctx->r2 = ADD32(ctx->r2, 0X7E5C);
    // 0x8000338C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80003390: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80003394: lui         $t4, 0x101
    ctx->r12 = S32(0X101 << 16);
    // 0x80003398: ori         $t4, $t4, 0x40
    ctx->r12 = ctx->r12 | 0X40;
    // 0x8000339C: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800033A0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x800033A4: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800033A8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800033AC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800033B0: addiu       $a1, $a1, 0x4660
    ctx->r5 = ADD32(ctx->r5, 0X4660);
    // 0x800033B4: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800033B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800033BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800033C0: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800033C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800033C8: jal         0x80005680
    // 0x800033CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x800033CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x800033D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800033D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800033D8: jr          $ra
    // 0x800033DC: nop

    return;
    // 0x800033DC: nop

;}
RECOMP_FUNC void Boss_Move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006965C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069660: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80069664: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x80069668: lwc1        $f0, 0x70($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X70);
    // 0x8006966C: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80069670: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80069674: lwc1        $f4, 0x74($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80069678: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006967C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80069680: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    // 0x80069684: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80069688: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8006968C: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80069690: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80069694: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80069698: swc1        $f6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f6.u32l;
    // 0x8006969C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800696A0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800696A4: swc1        $f10, 0x70($a0)
    MEM_W(0X70, ctx->r4) = ctx->f10.u32l;
    // 0x800696A8: lw          $t6, 0x1AB8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1AB8);
    // 0x800696AC: beql        $t6, $zero, L_800696EC
    if (ctx->r14 == 0) {
        // 0x800696B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800696EC;
    }
    goto skip_0;
    // 0x800696B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800696B4: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800696B8: lwc1        $f16, 0x2C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800696BC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800696C0: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800696C4: lwc1        $f0, 0x48($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X48);
    // 0x800696C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800696CC: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800696D0: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x800696D4: nop

    // 0x800696D8: bc1fl       L_800696EC
    if (!c1cs) {
        // 0x800696DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800696EC;
    }
    goto skip_1;
    // 0x800696DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800696E0: jal         0x80060FBC
    // 0x800696E4: addiu       $a1, $a0, 0x3FC
    ctx->r5 = ADD32(ctx->r4, 0X3FC);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x800696E4: addiu       $a1, $a0, 0x3FC
    ctx->r5 = ADD32(ctx->r4, 0X3FC);
    after_0:
    // 0x800696E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800696EC:
    // 0x800696EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800696F0: jr          $ra
    // 0x800696F4: nop

    return;
    // 0x800696F4: nop

;}
RECOMP_FUNC void PlayerShot_UpdateLockOnShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF90: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8003CF94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8003CF98: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003CF9C: addiu       $v0, $v0, 0x7940
    ctx->r2 = ADD32(ctx->r2, 0X7940);
    // 0x8003CFA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003CFA4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003CFA8: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003CFAC: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003CFB0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8003CFB4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003CFB8: nop

    // 0x8003CFBC: bc1t        L_8003CFD4
    if (c1cs) {
        // 0x8003CFC0: nop
    
            goto L_8003CFD4;
    }
    // 0x8003CFC0: nop

    // 0x8003CFC4: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8003CFC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003CFCC: bnel        $t6, $at, L_8003D0E4
    if (ctx->r14 != ctx->r1) {
        // 0x8003CFD0: lw          $t9, 0x60($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X60);
            goto L_8003D0E4;
    }
    goto skip_0;
    // 0x8003CFD0: lw          $t9, 0x60($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X60);
    skip_0:
L_8003CFD4:
    // 0x8003CFD4: lw          $t7, 0x1A88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1A88);
    // 0x8003CFD8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8003CFDC: bne         $t0, $t7, L_8003D0D0
    if (ctx->r8 != ctx->r15) {
        // 0x8003CFE0: nop
    
            goto L_8003D0D0;
    }
    // 0x8003CFE0: nop

    // 0x8003CFE4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003CFE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003CFEC: bc1f        L_8003D0D0
    if (!c1cs) {
        // 0x8003CFF0: nop
    
            goto L_8003D0D0;
    }
    // 0x8003CFF0: nop

    // 0x8003CFF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003CFF8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003CFFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003D000: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8003D004: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003D008: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003D00C: lwc1        $f8, 0x534C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X534C);
    // 0x8003D010: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003D014: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003D018: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003D01C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003D020: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003D024: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003D028: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003D02C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003D030: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8003D034: jal         0x8007D9DC
    // 0x8003D038: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_0;
    // 0x8003D038: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8003D03C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003D040: lwc1        $f8, 0x7940($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003D044: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D048: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003D04C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003D050: lwc1        $f4, 0x5350($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5350);
    // 0x8003D054: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003D058: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003D05C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003D060: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003D064: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003D068: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003D06C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003D070: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003D074: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8003D078: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003D07C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8003D080: jal         0x8007D9DC
    // 0x8003D084: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Effect_Effect367_Spawn(rdram, ctx);
        goto after_1;
    // 0x8003D084: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8003D088: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003D08C: lwc1        $f14, 0x7940($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003D090: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003D094: lwc1        $f4, 0x5354($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5354);
    // 0x8003D098: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8003D09C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003D0A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003D0A4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003D0A8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003D0AC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8003D0B0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003D0B4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8003D0B8: jal         0x8007ADF4
    // 0x8003D0BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Effect_WaterSpray_SpawnCircle(rdram, ctx);
        goto after_2;
    // 0x8003D0BC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8003D0C0: lui         $a1, 0x1900
    ctx->r5 = S32(0X1900 << 16);
    // 0x8003D0C4: ori         $a1, $a1, 0x14
    ctx->r5 = ctx->r5 | 0X14;
    // 0x8003D0C8: jal         0x8007A6F0
    // 0x8003D0CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_3;
    // 0x8003D0CC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
L_8003D0D0:
    // 0x8003D0D0: jal         0x80036318
    // 0x8003D0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_4;
    // 0x8003D0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003D0D8: b           L_8003D53C
    // 0x8003D0DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003D53C;
    // 0x8003D0DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003D0E0: lw          $t9, 0x60($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X60);
L_8003D0E4:
    // 0x8003D0E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8003D0E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003D0EC: bne         $t9, $zero, L_8003D368
    if (ctx->r25 != 0) {
        // 0x8003D0F0: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_8003D368;
    }
    // 0x8003D0F0: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003D0F4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8003D0F8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D0FC: addiu       $a1, $a1, -0x63DC
    ctx->r5 = ADD32(ctx->r5, -0X63DC);
    // 0x8003D100: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x8003D104: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8003D108: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_8003D10C:
    // 0x8003D10C: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x8003D110: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003D114: bnel        $t0, $t4, L_8003D178
    if (ctx->r8 != ctx->r12) {
        // 0x8003D118: slti        $at, $a0, 0x3C
        ctx->r1 = SIGNED(ctx->r4) < 0X3C ? 1 : 0;
            goto L_8003D178;
    }
    goto skip_1;
    // 0x8003D118: slti        $at, $a0, 0x3C
    ctx->r1 = SIGNED(ctx->r4) < 0X3C ? 1 : 0;
    skip_1:
    // 0x8003D11C: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003D120: c.eq.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl == ctx->f4.fl;
    // 0x8003D124: nop

    // 0x8003D128: bc1tl       L_8003D178
    if (c1cs) {
        // 0x8003D12C: slti        $at, $a0, 0x3C
        ctx->r1 = SIGNED(ctx->r4) < 0X3C ? 1 : 0;
            goto L_8003D178;
    }
    goto skip_2;
    // 0x8003D12C: slti        $at, $a0, 0x3C
    ctx->r1 = SIGNED(ctx->r4) < 0X3C ? 1 : 0;
    skip_2:
    // 0x8003D130: lw          $t5, 0x68($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X68);
    // 0x8003D134: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x8003D138: lbu         $t6, 0xCA($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XCA);
    // 0x8003D13C: beql        $t6, $zero, L_8003D178
    if (ctx->r14 == 0) {
        // 0x8003D140: slti        $at, $a0, 0x3C
        ctx->r1 = SIGNED(ctx->r4) < 0X3C ? 1 : 0;
            goto L_8003D178;
    }
    goto skip_3;
    // 0x8003D140: slti        $at, $a0, 0x3C
    ctx->r1 = SIGNED(ctx->r4) < 0X3C ? 1 : 0;
    skip_3:
    // 0x8003D144: sb          $a2, 0xCA($v1)
    MEM_B(0XCA, ctx->r3) = ctx->r6;
    // 0x8003D148: lw          $at, 0x4($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X4);
    // 0x8003D14C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003D150: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8003D154: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8003D158: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8003D15C: lw          $at, 0xC($v0)
    ctx->r1 = MEM_W(ctx->r2, 0XC);
    // 0x8003D160: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8003D164: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8003D168: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003D16C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003D170: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8003D174: slti        $at, $a0, 0x3C
    ctx->r1 = SIGNED(ctx->r4) < 0X3C ? 1 : 0;
L_8003D178:
    // 0x8003D178: bne         $at, $zero, L_8003D10C
    if (ctx->r1 != 0) {
        // 0x8003D17C: addiu       $v0, $v0, 0x2F4
        ctx->r2 = ADD32(ctx->r2, 0X2F4);
            goto L_8003D10C;
    }
    // 0x8003D17C: addiu       $v0, $v0, 0x2F4
    ctx->r2 = ADD32(ctx->r2, 0X2F4);
    // 0x8003D180: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8003D184: lw          $t3, 0x78A8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A8);
    // 0x8003D188: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003D18C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8003D190: blez        $t3, L_8003D230
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8003D194: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8003D230;
    }
    // 0x8003D194: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003D198: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003D19C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8003D1A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003D1A4: addiu       $t2, $t2, 0x7B00
    ctx->r10 = ADD32(ctx->r10, 0X7B00);
    // 0x8003D1A8: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8003D1AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_8003D1B0:
    // 0x8003D1B0: lw          $v1, 0x1C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X1C8);
    // 0x8003D1B4: beql        $a2, $v1, L_8003D1C8
    if (ctx->r6 == ctx->r3) {
        // 0x8003D1B8: lw          $t5, 0x68($s0)
        ctx->r13 = MEM_W(ctx->r16, 0X68);
            goto L_8003D1C8;
    }
    goto skip_4;
    // 0x8003D1B8: lw          $t5, 0x68($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X68);
    skip_4:
    // 0x8003D1BC: bnel        $t1, $v1, L_8003D224
    if (ctx->r9 != ctx->r3) {
        // 0x8003D1C0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8003D224;
    }
    goto skip_5;
    // 0x8003D1C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_5:
    // 0x8003D1C4: lw          $t5, 0x68($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X68);
L_8003D1C8:
    // 0x8003D1C8: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x8003D1CC: addu        $t4, $t2, $t9
    ctx->r12 = ADD32(ctx->r10, ctx->r25);
    // 0x8003D1D0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8003D1D4: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x8003D1D8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8003D1DC: beql        $t7, $zero, L_8003D224
    if (ctx->r15 == 0) {
        // 0x8003D1E0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8003D224;
    }
    goto skip_6;
    // 0x8003D1E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_6:
    // 0x8003D1E4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8003D1E8: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8003D1EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003D1F0: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8003D1F4: lw          $t8, 0x1CC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1CC);
    // 0x8003D1F8: bnel        $t8, $zero, L_8003D210
    if (ctx->r24 != 0) {
        // 0x8003D1FC: lwc1        $f8, 0x78($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
            goto L_8003D210;
    }
    goto skip_7;
    // 0x8003D1FC: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
    skip_7:
    // 0x8003D200: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x8003D204: b           L_8003D218
    // 0x8003D208: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
        goto L_8003D218;
    // 0x8003D208: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x8003D20C: lwc1        $f8, 0x78($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X78);
L_8003D210:
    // 0x8003D210: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8003D214: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
L_8003D218:
    // 0x8003D218: lwc1        $f4, 0x138($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X138);
    // 0x8003D21C: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x8003D220: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8003D224:
    // 0x8003D224: slt         $at, $a0, $t3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003D228: bne         $at, $zero, L_8003D1B0
    if (ctx->r1 != 0) {
        // 0x8003D22C: addiu       $v0, $v0, 0x4E0
        ctx->r2 = ADD32(ctx->r2, 0X4E0);
            goto L_8003D1B0;
    }
    // 0x8003D22C: addiu       $v0, $v0, 0x4E0
    ctx->r2 = ADD32(ctx->r2, 0X4E0);
L_8003D230:
    // 0x8003D230: beq         $a3, $zero, L_8003D364
    if (ctx->r7 == 0) {
        // 0x8003D234: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003D364;
    }
    // 0x8003D234: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003D238: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003D23C: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8003D240: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003D244: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8003D248: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003D24C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8003D250: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8003D254: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8003D258: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D25C: swc1        $f12, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f12.u32l;
    // 0x8003D260: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003D264: jal         0x80005100
    // 0x8003D268: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_5;
    // 0x8003D268: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x8003D26C: jal         0x8009F768
    // 0x8003D270: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_6;
    // 0x8003D270: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_6:
    // 0x8003D274: lwc1        $f2, 0x6C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8003D278: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8003D27C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8003D280: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003D284: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8003D288: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8003D28C: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003D290: jal         0x80005100
    // 0x8003D294: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_7;
    // 0x8003D294: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_7:
    // 0x8003D298: jal         0x8009F768
    // 0x8003D29C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_8;
    // 0x8003D29C: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_8:
    // 0x8003D2A0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003D2A4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003D2A8: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8003D2AC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D2B0: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8003D2B4: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x8003D2B8: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x8003D2BC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003D2C0: bc1fl       L_8003D2D8
    if (!c1cs) {
        // 0x8003D2C4: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_8003D2D8;
    }
    goto skip_8;
    // 0x8003D2C4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_8:
    // 0x8003D2C8: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8003D2CC: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x8003D2D0: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    // 0x8003D2D4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_8003D2D8:
    // 0x8003D2D8: nop

    // 0x8003D2DC: bc1fl       L_8003D2F0
    if (!c1cs) {
        // 0x8003D2E0: lwc1        $f0, 0x2C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_8003D2F0;
    }
    goto skip_9;
    // 0x8003D2E0: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    skip_9:
    // 0x8003D2E4: add.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8003D2E8: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x8003D2EC: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
L_8003D2F0:
    // 0x8003D2F0: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x8003D2F4: nop

    // 0x8003D2F8: bc1fl       L_8003D310
    if (!c1cs) {
        // 0x8003D2FC: c.lt.s      $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
            goto L_8003D310;
    }
    goto skip_10;
    // 0x8003D2FC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    skip_10:
    // 0x8003D300: sub.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8003D304: swc1        $f4, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f4.u32l;
    // 0x8003D308: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003D30C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
L_8003D310:
    // 0x8003D310: nop

    // 0x8003D314: bc1fl       L_8003D328
    if (!c1cs) {
        // 0x8003D318: lw          $a3, 0x50($s0)
        ctx->r7 = MEM_W(ctx->r16, 0X50);
            goto L_8003D328;
    }
    goto skip_11;
    // 0x8003D318: lw          $a3, 0x50($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X50);
    skip_11:
    // 0x8003D31C: add.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8003D320: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x8003D324: lw          $a3, 0x50($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X50);
L_8003D328:
    // 0x8003D328: swc1        $f14, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f14.u32l;
    // 0x8003D32C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8003D330: jal         0x8009BD38
    // 0x8003D334: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_9;
    // 0x8003D334: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_9:
    // 0x8003D338: lwc1        $f14, 0x5C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003D33C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D340: lw          $a3, 0x50($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X50);
    // 0x8003D344: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8003D348: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x8003D34C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003D350: jal         0x8009BD38
    // 0x8003D354: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_10;
    // 0x8003D354: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_10:
    // 0x8003D358: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003D35C: b           L_8003D368
    // 0x8003D360: sw          $t9, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r25;
        goto L_8003D368;
    // 0x8003D360: sw          $t9, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r25;
L_8003D364:
    // 0x8003D364: sw          $t5, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r13;
L_8003D368:
    // 0x8003D368: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003D36C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003D370: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D374: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x8003D378: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8003D37C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003D380: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x8003D384: jal         0x8009BC2C
    // 0x8003D388: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8003D388: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x8003D38C: lw          $t4, 0x60($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X60);
    // 0x8003D390: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003D394: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8003D398: beq         $t4, $zero, L_8003D3C0
    if (ctx->r12 == 0) {
        // 0x8003D39C: lui         $a1, 0x42B6
        ctx->r5 = S32(0X42B6 << 16);
            goto L_8003D3C0;
    }
    // 0x8003D39C: lui         $a1, 0x42B6
    ctx->r5 = S32(0X42B6 << 16);
    // 0x8003D3A0: addiu       $a0, $s0, 0x54
    ctx->r4 = ADD32(ctx->r16, 0X54);
    // 0x8003D3A4: lui         $a1, 0x4329
    ctx->r5 = S32(0X4329 << 16);
    // 0x8003D3A8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003D3AC: lui         $a3, 0x4150
    ctx->r7 = S32(0X4150 << 16);
    // 0x8003D3B0: jal         0x8009BC2C
    // 0x8003D3B4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x8003D3B4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x8003D3B8: b           L_8003D3D8
    // 0x8003D3BC: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
        goto L_8003D3D8;
    // 0x8003D3BC: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
L_8003D3C0:
    // 0x8003D3C0: lui         $a3, 0x40F9
    ctx->r7 = S32(0X40F9 << 16);
    // 0x8003D3C4: ori         $a3, $a3, 0x9999
    ctx->r7 = ctx->r7 | 0X9999;
    // 0x8003D3C8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003D3CC: jal         0x8009BC2C
    // 0x8003D3D0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8003D3D0: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x8003D3D4: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
L_8003D3D8:
    // 0x8003D3D8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003D3DC: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8003D3E0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003D3E4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8003D3E8: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8003D3EC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8003D3F0: sll         $t8, $t8, 5
    ctx->r24 = S32(ctx->r24 << 5);
    // 0x8003D3F4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8003D3F8: lw          $t5, 0x1CC($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X1CC);
    // 0x8003D3FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003D400: bnel        $t5, $at, L_8003D418
    if (ctx->r13 != ctx->r1) {
        // 0x8003D404: lwc1        $f2, 0x30($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
            goto L_8003D418;
    }
    goto skip_12;
    // 0x8003D404: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
    skip_12:
    // 0x8003D408: lw          $t4, 0x60($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X60);
    // 0x8003D40C: bne         $t4, $zero, L_8003D4C0
    if (ctx->r12 != 0) {
        // 0x8003D410: nop
    
            goto L_8003D4C0;
    }
    // 0x8003D410: nop

    // 0x8003D414: lwc1        $f2, 0x30($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X30);
L_8003D418:
    // 0x8003D418: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8003D41C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003D420: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8003D424: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8003D428: lwc1        $f4, 0x5358($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5358);
    // 0x8003D42C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003D430: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003D434: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8003D438: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003D43C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003D440: jal         0x80005E90
    // 0x8003D444: nop

    Matrix_RotateY(rdram, ctx);
        goto after_14;
    // 0x8003D444: nop

    after_14:
    // 0x8003D448: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003D44C: lwc1        $f10, 0x535C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X535C);
    // 0x8003D450: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D454: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003D458: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003D45C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003D460: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003D464: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003D468: jal         0x80005D44
    // 0x8003D46C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_15;
    // 0x8003D46C: nop

    after_15:
    // 0x8003D470: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003D474: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8003D478: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003D47C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x8003D480: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x8003D484: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8003D488: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8003D48C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8003D490: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003D494: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8003D498: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8003D49C: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x8003D4A0: jal         0x80006970
    // 0x8003D4A4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_16;
    // 0x8003D4A4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    after_16:
    // 0x8003D4A8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8003D4AC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003D4B0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8003D4B4: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8003D4B8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8003D4BC: swc1        $f10, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f10.u32l;
L_8003D4C0:
    // 0x8003D4C0: jal         0x80038140
    // 0x8003D4C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_CollisionCheck(rdram, ctx);
        goto after_17;
    // 0x8003D4C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8003D4C8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8003D4CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D4D0: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x8003D4D4: swc1        $f4, -0x7C90($at)
    MEM_W(-0X7C90, ctx->r1) = ctx->f4.u32l;
    // 0x8003D4D8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003D4DC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D4E0: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x8003D4E4: swc1        $f6, -0x7C8C($at)
    MEM_W(-0X7C8C, ctx->r1) = ctx->f6.u32l;
    // 0x8003D4E8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D4EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D4F0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8003D4F4: swc1        $f8, -0x7C88($at)
    MEM_W(-0X7C88, ctx->r1) = ctx->f8.u32l;
    // 0x8003D4F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D4FC: sw          $v0, -0x7CA0($at)
    MEM_W(-0X7CA0, ctx->r1) = ctx->r2;
    // 0x8003D500: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D504: sw          $t7, -0x7C9C($at)
    MEM_W(-0X7C9C, ctx->r1) = ctx->r15;
    // 0x8003D508: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003D50C: sw          $v0, -0x7C98($at)
    MEM_W(-0X7C98, ctx->r1) = ctx->r2;
    // 0x8003D510: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003D514: lwc1        $f10, 0x5360($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5360);
    // 0x8003D518: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x8003D51C: lui         $a3, 0x3DA3
    ctx->r7 = S32(0X3DA3 << 16);
    // 0x8003D520: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x8003D524: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8003D528: addiu       $a0, $a0, -0x7C94
    ctx->r4 = ADD32(ctx->r4, -0X7C94);
    // 0x8003D52C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003D530: jal         0x8009BC2C
    // 0x8003D534: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_18;
    // 0x8003D534: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_18:
    // 0x8003D538: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003D53C:
    // 0x8003D53C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8003D540: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8003D544: jr          $ra
    // 0x8003D548: nop

    return;
    // 0x8003D548: nop

;}
RECOMP_FUNC void Aquas_AqBump2_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800953A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800953A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800953A8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800953AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800953B0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800953B4: addiu       $t7, $t7, 0x2510
    ctx->r15 = ADD32(ctx->r15, 0X2510);
    // 0x800953B8: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x800953BC: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
L_800953C0:
    // 0x800953C0: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800953C4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800953C8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800953CC: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x800953D0: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x800953D4: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x800953D8: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x800953DC: bne         $t7, $t0, L_800953C0
    if (ctx->r15 != ctx->r8) {
        // 0x800953E0: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_800953C0;
    }
    // 0x800953E0: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x800953E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800953E8: jal         0x800613C4
    // 0x800953EC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x800953EC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x800953F0: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800953F4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800953F8: addiu       $t2, $zero, 0xC3
    ctx->r10 = ADD32(0, 0XC3);
    // 0x800953FC: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x80095400: sh          $t2, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r10;
    // 0x80095404: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x80095408: addiu       $t5, $sp, 0x18
    ctx->r13 = ADD32(ctx->r29, 0X18);
    // 0x8009540C: addiu       $t7, $zero, 0x2D
    ctx->r15 = ADD32(0, 0X2D);
    // 0x80095410: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80095414: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80095418: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8009541C: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x80095420: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80095424: andi        $a1, $t2, 0xFFFF
    ctx->r5 = ctx->r10 & 0XFFFF;
    // 0x80095428: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x8009542C: sw          $at, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r1;
    // 0x80095430: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80095434: sw          $t0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r8;
    // 0x80095438: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x8009543C: sw          $at, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r1;
    // 0x80095440: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80095444: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80095448: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8009544C: sh          $t7, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r15;
    // 0x80095450: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80095454: jal         0x800612B8
    // 0x80095458: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80095458: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x8009545C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80095460: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80095464: jr          $ra
    // 0x80095468: nop

    return;
    // 0x80095468: nop

;}
RECOMP_FUNC void AudioHeap_InitSessionPools(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C044: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000C048: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000C04C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C050: addiu       $a0, $a0, -0x3E40
    ctx->r4 = ADD32(ctx->r4, -0X3E40);
    // 0x8000C054: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000C058: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x8000C05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000C060: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8000C064: jal         0x8000BF14
    // 0x8000C068: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000C068: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_0:
    // 0x8000C06C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000C070: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C074: addiu       $a0, $a0, -0x3E20
    ctx->r4 = ADD32(ctx->r4, -0X3E20);
    // 0x8000C078: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C07C: jal         0x8000BF6C
    // 0x8000C080: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    AudioHeap_InitPool(rdram, ctx);
        goto after_1;
    // 0x8000C080: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    after_1:
    // 0x8000C084: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x8000C088: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C08C: addiu       $a0, $a0, -0x3E40
    ctx->r4 = ADD32(ctx->r4, -0X3E40);
    // 0x8000C090: jal         0x8000BF14
    // 0x8000C094: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    AudioHeap_Alloc(rdram, ctx);
        goto after_2;
    // 0x8000C094: lw          $a1, 0xC($t9)
    ctx->r5 = MEM_W(ctx->r25, 0XC);
    after_2:
    // 0x8000C098: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000C09C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000C0A0: addiu       $a0, $a0, -0x3DF0
    ctx->r4 = ADD32(ctx->r4, -0X3DF0);
    // 0x8000C0A4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000C0A8: jal         0x8000BF6C
    // 0x8000C0AC: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    AudioHeap_InitPool(rdram, ctx);
        goto after_3;
    // 0x8000C0AC: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    after_3:
    // 0x8000C0B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000C0B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000C0B8: jr          $ra
    // 0x8000C0BC: nop

    return;
    // 0x8000C0BC: nop

;}
RECOMP_FUNC void Effect_Effect385_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B5C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007B5C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007B5C8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007B5CC: lwc1        $f0, 0x73D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73D4);
    // 0x8007B5D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007B5D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007B5D8: lw          $a1, 0x6C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X6C);
    // 0x8007B5DC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007B5E0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8007B5E4: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8007B5E8: jal         0x8009BC2C
    // 0x8007B5EC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8007B5EC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    after_0:
    // 0x8007B5F0: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x8007B5F4: lh          $t7, 0x46($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X46);
    // 0x8007B5F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007B5FC: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8007B600: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x8007B604: lh          $t9, 0x44($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X44);
    // 0x8007B608: bgezl       $t9, L_8007B61C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007B60C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007B61C;
    }
    goto skip_0;
    // 0x8007B60C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8007B610: jal         0x80060FBC
    // 0x8007B614: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8007B614: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_1:
    // 0x8007B618: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007B61C:
    // 0x8007B61C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007B620: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007B624: jr          $ra
    // 0x8007B628: nop

    return;
    // 0x8007B628: nop

;}
RECOMP_FUNC void Main_InitMesgQueues(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004568: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000456C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004570: addiu       $a1, $a1, 0x2108
    ctx->r5 = ADD32(ctx->r5, 0X2108);
    // 0x80004574: addiu       $a0, $a0, 0x20F0
    ctx->r4 = ADD32(ctx->r4, 0X20F0);
    // 0x80004578: jal         0x80021CF0
    // 0x8000457C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8000457C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80004580: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004584: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004588: addiu       $a1, $a1, 0x21F8
    ctx->r5 = ADD32(ctx->r5, 0X21F8);
    // 0x8000458C: addiu       $a0, $a0, 0x21E0
    ctx->r4 = ADD32(ctx->r4, 0X21E0);
    // 0x80004590: jal         0x80021CF0
    // 0x80004594: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80004594: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x80004598: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000459C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800045A0: addiu       $a1, $a1, 0x2250
    ctx->r5 = ADD32(ctx->r5, 0X2250);
    // 0x800045A4: addiu       $a0, $a0, 0x2238
    ctx->r4 = ADD32(ctx->r4, 0X2238);
    // 0x800045A8: jal         0x80021CF0
    // 0x800045AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_2;
    // 0x800045AC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800045B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800045B4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800045B8: addiu       $a1, $a1, 0x2270
    ctx->r5 = ADD32(ctx->r5, 0X2270);
    // 0x800045BC: addiu       $a0, $a0, 0x2258
    ctx->r4 = ADD32(ctx->r4, 0X2258);
    // 0x800045C0: jal         0x80021CF0
    // 0x800045C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x800045C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800045C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800045CC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800045D0: addiu       $a1, $a1, 0x2290
    ctx->r5 = ADD32(ctx->r5, 0X2290);
    // 0x800045D4: addiu       $a0, $a0, 0x2278
    ctx->r4 = ADD32(ctx->r4, 0X2278);
    // 0x800045D8: jal         0x80021CF0
    // 0x800045DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x800045DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x800045E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800045E4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800045E8: addiu       $a1, $a1, 0x22B8
    ctx->r5 = ADD32(ctx->r5, 0X22B8);
    // 0x800045EC: addiu       $a0, $a0, 0x22A0
    ctx->r4 = ADD32(ctx->r4, 0X22A0);
    // 0x800045F0: jal         0x80021CF0
    // 0x800045F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_5;
    // 0x800045F4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_5:
    // 0x800045F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800045FC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004600: addiu       $a1, $a1, 0x2140
    ctx->r5 = ADD32(ctx->r5, 0X2140);
    // 0x80004604: addiu       $a0, $a0, 0x2128
    ctx->r4 = ADD32(ctx->r4, 0X2128);
    // 0x80004608: jal         0x80021CF0
    // 0x8000460C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_6;
    // 0x8000460C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x80004610: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004614: addiu       $a1, $a1, 0x2128
    ctx->r5 = ADD32(ctx->r5, 0X2128);
    // 0x80004618: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x8000461C: jal         0x80021D20
    // 0x80004620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSetEventMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80004620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80004624: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004628: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000462C: addiu       $a1, $a1, 0x2160
    ctx->r5 = ADD32(ctx->r5, 0X2160);
    // 0x80004630: addiu       $a0, $a0, 0x2148
    ctx->r4 = ADD32(ctx->r4, 0X2148);
    // 0x80004634: jal         0x80021CF0
    // 0x80004638: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_8;
    // 0x80004638: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_8:
    // 0x8000463C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004640: addiu       $a0, $a0, 0x2148
    ctx->r4 = ADD32(ctx->r4, 0X2148);
    // 0x80004644: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80004648: jal         0x80021D90
    // 0x8000464C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osViSetEvent_recomp(rdram, ctx);
        goto after_9;
    // 0x8000464C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x80004650: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004654: addiu       $a1, $a1, 0x2148
    ctx->r5 = ADD32(ctx->r5, 0X2148);
    // 0x80004658: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8000465C: jal         0x80021D20
    // 0x80004660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_10;
    // 0x80004660: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_10:
    // 0x80004664: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004668: addiu       $a1, $a1, 0x2148
    ctx->r5 = ADD32(ctx->r5, 0X2148);
    // 0x8000466C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80004670: jal         0x80021D20
    // 0x80004674: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_11;
    // 0x80004674: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_11:
    // 0x80004678: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000467C: addiu       $a1, $a1, 0x2148
    ctx->r5 = ADD32(ctx->r5, 0X2148);
    // 0x80004680: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x80004684: jal         0x80021D20
    // 0x80004688: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_12;
    // 0x80004688: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_12:
    // 0x8000468C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004690: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004694: addiu       $a1, $a1, 0x2350
    ctx->r5 = ADD32(ctx->r5, 0X2350);
    // 0x80004698: addiu       $a0, $a0, 0x2338
    ctx->r4 = ADD32(ctx->r4, 0X2338);
    // 0x8000469C: jal         0x80021CF0
    // 0x800046A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_13;
    // 0x800046A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_13:
    // 0x800046A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800046A8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800046AC: addiu       $a1, $a1, 0x23A8
    ctx->r5 = ADD32(ctx->r5, 0X23A8);
    // 0x800046B0: addiu       $a0, $a0, 0x2390
    ctx->r4 = ADD32(ctx->r4, 0X2390);
    // 0x800046B4: jal         0x80021CF0
    // 0x800046B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_14;
    // 0x800046B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x800046BC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800046C0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800046C4: addiu       $a1, $a1, 0x22D8
    ctx->r5 = ADD32(ctx->r5, 0X22D8);
    // 0x800046C8: addiu       $a0, $a0, 0x22C0
    ctx->r4 = ADD32(ctx->r4, 0X22C0);
    // 0x800046CC: jal         0x80021CF0
    // 0x800046D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_15;
    // 0x800046D0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_15:
    // 0x800046D4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800046D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800046DC: addiu       $a1, $a1, 0x2310
    ctx->r5 = ADD32(ctx->r5, 0X2310);
    // 0x800046E0: addiu       $a0, $a0, 0x22F8
    ctx->r4 = ADD32(ctx->r4, 0X22F8);
    // 0x800046E4: jal         0x80021CF0
    // 0x800046E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_16;
    // 0x800046E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x800046EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800046F0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800046F4: addiu       $a1, $a1, 0x2330
    ctx->r5 = ADD32(ctx->r5, 0X2330);
    // 0x800046F8: addiu       $a0, $a0, 0x2318
    ctx->r4 = ADD32(ctx->r4, 0X2318);
    // 0x800046FC: jal         0x80021CF0
    // 0x80004700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_17;
    // 0x80004700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_17:
    // 0x80004704: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004708: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000470C: jr          $ra
    // 0x80004710: nop

    return;
    // 0x80004710: nop

;}
RECOMP_FUNC void func_versus_800BDE44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BDE44: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x800BDE48: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800BDE4C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800BDE50: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800BDE54: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800BDE58: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800BDE5C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800BDE60: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800BDE64: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800BDE68: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800BDE6C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800BDE70: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800BDE74: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800BDE78: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800BDE7C: addiu       $t7, $t7, 0x4B70
    ctx->r15 = ADD32(ctx->r15, 0X4B70);
    // 0x800BDE80: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800BDE84: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800BDE88: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
    // 0x800BDE8C: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800BDE90: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800BDE94: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800BDE98: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800BDE9C: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800BDEA0: addiu       $t2, $t2, 0x4B80
    ctx->r10 = ADD32(ctx->r10, 0X4B80);
    // 0x800BDEA4: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800BDEA8: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800BDEAC: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800BDEB0: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800BDEB4: addiu       $t1, $sp, 0x74
    ctx->r9 = ADD32(ctx->r29, 0X74);
    // 0x800BDEB8: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BDEBC: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800BDEC0: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800BDEC4: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800BDEC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BDECC: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    // 0x800BDED0: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800BDED4: jal         0x800B8DD0
    // 0x800BDED8: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800BDED8: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    after_0:
    // 0x800BDEDC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800BDEE0: lui         $t6, 0xFFFF
    ctx->r14 = S32(0XFFFF << 16);
    // 0x800BDEE4: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x800BDEE8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800BDEEC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800BDEF0: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800BDEF4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BDEF8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800BDEFC: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x800BDF00: addiu       $s7, $s7, 0x5D34
    ctx->r23 = ADD32(ctx->r23, 0X5D34);
    // 0x800BDF04: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800BDF08: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800BDF0C: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
L_800BDF10:
    // 0x800BDF10: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800BDF14: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800BDF18: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800BDF1C: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800BDF20: addu        $t0, $t7, $s6
    ctx->r8 = ADD32(ctx->r15, ctx->r22);
    // 0x800BDF24: lw          $v0, 0x1C8($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X1C8);
    // 0x800BDF28: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800BDF2C: addiu       $t3, $t3, -0x77F8
    ctx->r11 = ADD32(ctx->r11, -0X77F8);
    // 0x800BDF30: beq         $fp, $v0, L_800BDF3C
    if (ctx->r30 == ctx->r2) {
        // 0x800BDF34: addiu       $t4, $t4, 0x7C30
        ctx->r12 = ADD32(ctx->r12, 0X7C30);
            goto L_800BDF3C;
    }
    // 0x800BDF34: addiu       $t4, $t4, 0x7C30
    ctx->r12 = ADD32(ctx->r12, 0X7C30);
    // 0x800BDF38: bne         $v0, $at, L_800BE038
    if (ctx->r2 != ctx->r1) {
        // 0x800BDF3C: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_800BE038;
    }
L_800BDF3C:
    // 0x800BDF3C: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x800BDF40: addu        $s2, $v0, $t4
    ctx->r18 = ADD32(ctx->r2, ctx->r12);
    // 0x800BDF44: addu        $s1, $v0, $t3
    ctx->r17 = ADD32(ctx->r2, ctx->r11);
    // 0x800BDF48: lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X0);
    // 0x800BDF4C: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800BDF50: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x800BDF54: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800BDF58: addiu       $t1, $t1, -0x77F0
    ctx->r9 = ADD32(ctx->r9, -0X77F0);
    // 0x800BDF5C: addiu       $t2, $sp, 0x84
    ctx->r10 = ADD32(ctx->r29, 0X84);
    // 0x800BDF60: addiu       $t5, $sp, 0x74
    ctx->r13 = ADD32(ctx->r29, 0X74);
    // 0x800BDF64: addu        $s5, $v1, $t5
    ctx->r21 = ADD32(ctx->r3, ctx->r13);
    // 0x800BDF68: addu        $s4, $v1, $t2
    ctx->r20 = ADD32(ctx->r3, ctx->r10);
    // 0x800BDF6C: bne         $a0, $a3, L_800BDF80
    if (ctx->r4 != ctx->r7) {
        // 0x800BDF70: addu        $s0, $v1, $t1
        ctx->r16 = ADD32(ctx->r3, ctx->r9);
            goto L_800BDF80;
    }
    // 0x800BDF70: addu        $s0, $v1, $t1
    ctx->r16 = ADD32(ctx->r3, ctx->r9);
    // 0x800BDF74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800BDF78: beql        $v0, $zero, L_800BE004
    if (ctx->r2 == 0) {
        // 0x800BDF7C: slt         $at, $a0, $a3
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800BE004;
    }
    goto skip_0;
    // 0x800BDF7C: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    skip_0:
L_800BDF80:
    // 0x800BDF80: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800BDF84: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800BDF88: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800BDF8C: addiu       $v0, $t9, 0x4
    ctx->r2 = ADD32(ctx->r25, 0X4);
    // 0x800BDF90: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x800BDF94: bne         $at, $zero, L_800BE000
    if (ctx->r1 != 0) {
        // 0x800BDF98: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_800BE000;
    }
    // 0x800BDF98: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800BDF9C: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BDFA0: beq         $at, $zero, L_800BDFB4
    if (ctx->r1 == 0) {
        // 0x800BDFA4: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_800BDFB4;
    }
    // 0x800BDFA4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800BDFA8: addiu       $t6, $a3, 0x1
    ctx->r14 = ADD32(ctx->r7, 0X1);
    // 0x800BDFAC: b           L_800BDFBC
    // 0x800BDFB0: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
        goto L_800BDFBC;
    // 0x800BDFB0: sh          $t6, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r14;
L_800BDFB4:
    // 0x800BDFB4: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x800BDFB8: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
L_800BDFBC:
    // 0x800BDFBC: lhu         $t0, 0x0($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X0);
    // 0x800BDFC0: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x800BDFC4: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x800BDFC8: beq         $a0, $t0, L_800BDFDC
    if (ctx->r4 == ctx->r8) {
        // 0x800BDFCC: or          $a3, $s7, $zero
        ctx->r7 = ctx->r23 | 0;
            goto L_800BDFDC;
    }
    // 0x800BDFCC: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x800BDFD0: addiu       $t4, $v0, -0xF
    ctx->r12 = ADD32(ctx->r2, -0XF);
    // 0x800BDFD4: b           L_800BDFE0
    // 0x800BDFD8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_800BDFE0;
    // 0x800BDFD8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_800BDFDC:
    // 0x800BDFDC: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800BDFE0:
    // 0x800BDFE0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800BDFE4: ori         $a0, $a0, 0x4007
    ctx->r4 = ctx->r4 | 0X4007;
    // 0x800BDFE8: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x800BDFEC: jal         0x80019218
    // 0x800BDFF0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800BDFF0: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_1:
    // 0x800BDFF4: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800BDFF8: lhu         $a3, 0x0($s1)
    ctx->r7 = MEM_HU(ctx->r17, 0X0);
    // 0x800BDFFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_800BE000:
    // 0x800BE000: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
L_800BE004:
    // 0x800BE004: bne         $at, $zero, L_800BE028
    if (ctx->r1 != 0) {
        // 0x800BE008: addiu       $a2, $a3, -0x1
        ctx->r6 = ADD32(ctx->r7, -0X1);
            goto L_800BE028;
    }
    // 0x800BE008: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    // 0x800BE00C: lwc1        $f12, 0x0($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800BE010: lwc1        $f14, 0x0($s5)
    ctx->f14.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800BE014: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800BE018: jal         0x800BDAA0
    // 0x800BE01C: addiu       $a2, $a3, 0x1
    ctx->r6 = ADD32(ctx->r7, 0X1);
    func_versus_800BDAA0(rdram, ctx);
        goto after_2;
    // 0x800BE01C: addiu       $a2, $a3, 0x1
    ctx->r6 = ADD32(ctx->r7, 0X1);
    after_2:
    // 0x800BE020: b           L_800BE03C
    // 0x800BE024: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800BE03C;
    // 0x800BE024: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800BE028:
    // 0x800BE028: lwc1        $f12, 0x0($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800BE02C: lwc1        $f14, 0x0($s5)
    ctx->f14.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800BE030: jal         0x800BDAA0
    // 0x800BE034: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_versus_800BDAA0(rdram, ctx);
        goto after_3;
    // 0x800BE034: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
L_800BE038:
    // 0x800BE038: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800BE03C:
    // 0x800BE03C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800BE040: bne         $s3, $at, L_800BDF10
    if (ctx->r19 != ctx->r1) {
        // 0x800BE044: addiu       $s6, $s6, 0x4E0
        ctx->r22 = ADD32(ctx->r22, 0X4E0);
            goto L_800BDF10;
    }
    // 0x800BE044: addiu       $s6, $s6, 0x4E0
    ctx->r22 = ADD32(ctx->r22, 0X4E0);
    // 0x800BE048: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800BE04C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800BE050: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800BE054: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800BE058: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800BE05C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800BE060: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800BE064: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800BE068: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800BE06C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800BE070: jr          $ra
    // 0x800BE074: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800BE074: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Effect_Effect362_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BB14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007BB18: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007BB1C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007BB20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007BB24: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007BB28: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007BB2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007BB30: jal         0x80061474
    // 0x8007BB34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007BB34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007BB38: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007BB3C: addiu       $t7, $zero, 0x16A
    ctx->r15 = ADD32(0, 0X16A);
    // 0x8007BB40: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007BB44: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007BB48: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007BB4C: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007BB50: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007BB54: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007BB58: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007BB5C: jal         0x80004EB0
    // 0x8007BB60: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007BB60: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x8007BB64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007BB68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007BB6C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007BB70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007BB74: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8007BB78: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8007BB7C: jal         0x80004EB0
    // 0x8007BB80: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007BB80: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x8007BB84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007BB88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007BB8C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8007BB90: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007BB94: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8007BB98: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8007BB9C: sh          $t8, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r24;
    // 0x8007BBA0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007BBA4: jal         0x80004EB0
    // 0x8007BBA8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8007BBA8: swc1        $f16, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f16.u32l;
    after_3:
    // 0x8007BBAC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007BBB0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007BBB4: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8007BBB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007BBBC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8007BBC0: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8007BBC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007BBC8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8007BBCC: bc1f        L_8007BBE0
    if (!c1cs) {
        // 0x8007BBD0: addiu       $t4, $zero, 0x50
        ctx->r12 = ADD32(0, 0X50);
            goto L_8007BBE0;
    }
    // 0x8007BBD0: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8007BBD4: lh          $t9, 0x48($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X48);
    // 0x8007BBD8: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8007BBDC: sh          $t0, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r8;
L_8007BBE0:
    // 0x8007BBE0: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007BBE4: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x8007BBE8: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8007BBEC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8007BBF0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007BBF4: sh          $t1, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r9;
    // 0x8007BBF8: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x8007BBFC: bc1f        L_8007BC0C
    if (!c1cs) {
        // 0x8007BC00: nop
    
            goto L_8007BC0C;
    }
    // 0x8007BC00: nop

    // 0x8007BC04: sh          $t3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r11;
    // 0x8007BC08: sh          $t4, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r12;
L_8007BC0C:
    // 0x8007BC0C: jal         0x80004EB0
    // 0x8007BC10: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8007BC10: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    after_4:
    // 0x8007BC14: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8007BC18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007BC1C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8007BC20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007BC24: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8007BC28: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8007BC2C: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007BC30: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
    // 0x8007BC34: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007BC38: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x8007BC3C: nop

    // 0x8007BC40: bc1f        L_8007BC60
    if (!c1cs) {
        // 0x8007BC44: nop
    
            goto L_8007BC60;
    }
    // 0x8007BC44: nop

    // 0x8007BC48: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8007BC4C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007BC50: lwc1        $f8, 0x73E8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X73E8);
    // 0x8007BC54: lwc1        $f6, 0xC8($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0XC8);
    // 0x8007BC58: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8007BC5C: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
L_8007BC60:
    // 0x8007BC60: jal         0x800612B8
    // 0x8007BC64: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_5;
    // 0x8007BC64: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    after_5:
    // 0x8007BC68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007BC6C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007BC70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007BC74: jr          $ra
    // 0x8007BC78: nop

    return;
    // 0x8007BC78: nop

;}
RECOMP_FUNC void Scenery_Corneria_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063D58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063D60: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80063D64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80063D68: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80063D6C: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80063D70: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80063D74: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80063D78: addiu       $a2, $a2, 0x3400
    ctx->r6 = ADD32(ctx->r6, 0X3400);
    // 0x80063D7C: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x80063D80: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
L_80063D84:
    // 0x80063D84: bne         $t6, $zero, L_80063E40
    if (ctx->r14 != 0) {
        // 0x80063D88: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80063E40;
    }
    // 0x80063D88: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80063D8C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80063D90: jal         0x80061394
    // 0x80063D94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Sprite_Initialize(rdram, ctx);
        goto after_0;
    // 0x80063D94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80063D98: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80063D9C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80063DA0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80063DA4: addiu       $t8, $zero, 0xA4
    ctx->r24 = ADD32(0, 0XA4);
    // 0x80063DA8: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80063DAC: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x80063DB0: lhu         $t9, 0x2($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X2);
    // 0x80063DB4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80063DB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80063DBC: sb          $t9, 0x45($a2)
    MEM_B(0X45, ctx->r6) = ctx->r25;
    // 0x80063DC0: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80063DC4: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // 0x80063DC8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80063DCC: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x80063DD0: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80063DD4: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80063DD8: swc1        $f10, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f10.u32l;
    // 0x80063DDC: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80063DE0: beql        $v0, $zero, L_80063E1C
    if (ctx->r2 == 0) {
        // 0x80063DE4: lwc1        $f16, 0x14($a1)
        ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
            goto L_80063E1C;
    }
    goto skip_0;
    // 0x80063DE4: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
    skip_0:
    // 0x80063DE8: beq         $v0, $at, L_80063E18
    if (ctx->r2 == ctx->r1) {
        // 0x80063DEC: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80063E18;
    }
    // 0x80063DEC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80063DF0: beq         $v0, $at, L_80063E18
    if (ctx->r2 == ctx->r1) {
        // 0x80063DF4: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_80063E18;
    }
    // 0x80063DF4: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80063DF8: beq         $v0, $at, L_80063E18
    if (ctx->r2 == ctx->r1) {
        // 0x80063DFC: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80063E18;
    }
    // 0x80063DFC: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80063E00: beq         $v0, $at, L_80063E18
    if (ctx->r2 == ctx->r1) {
        // 0x80063E04: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_80063E18;
    }
    // 0x80063E04: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80063E08: beq         $v0, $at, L_80063E18
    if (ctx->r2 == ctx->r1) {
        // 0x80063E0C: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_80063E18;
    }
    // 0x80063E0C: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80063E10: bne         $v0, $at, L_80063E24
    if (ctx->r2 != ctx->r1) {
        // 0x80063E14: nop
    
            goto L_80063E24;
    }
    // 0x80063E14: nop

L_80063E18:
    // 0x80063E18: lwc1        $f16, 0x14($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X14);
L_80063E1C:
    // 0x80063E1C: b           L_80063E30
    // 0x80063E20: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
        goto L_80063E30;
    // 0x80063E20: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
L_80063E24:
    // 0x80063E24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80063E28: lwc1        $f18, 0x64D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X64D4);
    // 0x80063E2C: swc1        $f18, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f18.u32l;
L_80063E30:
    // 0x80063E30: jal         0x800612B8
    // 0x80063E34: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80063E34: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_1:
    // 0x80063E38: b           L_80063E50
    // 0x80063E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80063E50;
    // 0x80063E3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80063E40:
    // 0x80063E40: addiu       $a2, $a2, 0x4C
    ctx->r6 = ADD32(ctx->r6, 0X4C);
    // 0x80063E44: bnel        $a2, $v0, L_80063D84
    if (ctx->r6 != ctx->r2) {
        // 0x80063E48: lbu         $t6, 0x0($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X0);
            goto L_80063D84;
    }
    goto skip_1;
    // 0x80063E48: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    skip_1:
    // 0x80063E4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80063E50:
    // 0x80063E50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063E54: jr          $ra
    // 0x80063E58: nop

    return;
    // 0x80063E58: nop

;}
RECOMP_FUNC void AudioLoad_FinishSlowLoad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010808: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001080C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010810: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80010814: lbu         $a1, 0x2($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X2);
    // 0x80010818: lbu         $a0, 0x1($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1);
    // 0x8001081C: jal         0x8001079C
    // 0x80010820: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    AudioLoad_GetFontSample(rdram, ctx);
        goto after_0;
    // 0x80010820: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80010824: beq         $v0, $zero, L_80010860
    if (ctx->r2 == 0) {
        // 0x80010828: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80010860;
    }
    // 0x80010828: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8001082C: lw          $at, 0x0($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X0);
    // 0x80010830: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x80010834: sw          $at, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r1;
    // 0x80010838: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8001083C: sw          $t7, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r15;
    // 0x80010840: lw          $at, 0x8($v0)
    ctx->r1 = MEM_W(ctx->r2, 0X8);
    // 0x80010844: sw          $at, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r1;
    // 0x80010848: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8001084C: sw          $t7, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r15;
    // 0x80010850: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x80010854: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80010858: andi        $t0, $t9, 0xFFF3
    ctx->r8 = ctx->r25 & 0XFFF3;
    // 0x8001085C: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_80010860:
    // 0x80010860: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010864: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80010868: jr          $ra
    // 0x8001086C: nop

    return;
    // 0x8001086C: nop

;}
RECOMP_FUNC void RCP_SetupDL_7(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9150: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B9154: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B9158: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B915C: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B9160: addiu       $t8, $t8, 0x33A8
    ctx->r24 = ADD32(ctx->r24, 0X33A8);
    // 0x800B9164: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B9168: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B916C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B9170: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B9174: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B9178: jr          $ra
    // 0x800B917C: nop

    return;
    // 0x800B917C: nop

;}
RECOMP_FUNC void func_radio_800BA7BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA7BC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800BA7C0: addiu       $v1, $v1, 0x4A70
    ctx->r3 = ADD32(ctx->r3, 0X4A70);
    // 0x800BA7C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BA7C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA7CC: bne         $a1, $v0, L_800BA7DC
    if (ctx->r5 != ctx->r2) {
        // 0x800BA7D0: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800BA7DC;
    }
    // 0x800BA7D0: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BA7D4: jr          $ra
    // 0x800BA7D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BA7D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BA7DC:
    // 0x800BA7DC: beql        $at, $zero, L_800BA7F0
    if (ctx->r1 == 0) {
        // 0x800BA7E0: slt         $at, $v0, $a1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800BA7F0;
    }
    goto skip_0;
    // 0x800BA7E0: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    skip_0:
    // 0x800BA7E4: jr          $ra
    // 0x800BA7E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800BA7E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800BA7EC: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
L_800BA7F0:
    // 0x800BA7F0: beq         $at, $zero, L_800BA800
    if (ctx->r1 == 0) {
        // 0x800BA7F4: nop
    
            goto L_800BA800;
    }
    // 0x800BA7F4: nop

    // 0x800BA7F8: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800BA7FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800BA800:
    // 0x800BA800: jr          $ra
    // 0x800BA804: nop

    return;
    // 0x800BA804: nop

;}
RECOMP_FUNC void Player_LowHealthAlarm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B415C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B4160: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4164: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800B4168: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800B416C: jal         0x800B40AC
    // 0x800B4170: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    Player_UpdateShields(rdram, ctx);
        goto after_0;
    // 0x800B4170: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800B4174: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800B4178: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B417C: lw          $v0, 0x264($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X264);
    // 0x800B4180: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800B4184: beq         $at, $zero, L_800B41D0
    if (ctx->r1 == 0) {
        // 0x800B4188: slti        $at, $v0, 0x51
        ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
            goto L_800B41D0;
    }
    // 0x800B4188: slti        $at, $v0, 0x51
    ctx->r1 = SIGNED(ctx->r2) < 0X51 ? 1 : 0;
    // 0x800B418C: bne         $at, $zero, L_800B419C
    if (ctx->r1 != 0) {
        // 0x800B4190: addiu       $a0, $a3, 0x460
        ctx->r4 = ADD32(ctx->r7, 0X460);
            goto L_800B419C;
    }
    // 0x800B4190: addiu       $a0, $a3, 0x460
    ctx->r4 = ADD32(ctx->r7, 0X460);
    // 0x800B4194: b           L_800B41B0
    // 0x800B4198: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
        goto L_800B41B0;
    // 0x800B4198: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
L_800B419C:
    // 0x800B419C: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x800B41A0: bne         $at, $zero, L_800B41B0
    if (ctx->r1 != 0) {
        // 0x800B41A4: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_800B41B0;
    }
    // 0x800B41A4: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x800B41A8: b           L_800B41B0
    // 0x800B41AC: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
        goto L_800B41B0;
    // 0x800B41AC: addiu       $v0, $zero, 0x1F
    ctx->r2 = ADD32(0, 0X1F);
L_800B41B0:
    // 0x800B41B0: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x800B41B4: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x800B41B8: ori         $a1, $a1, 0x1026
    ctx->r5 = ctx->r5 | 0X1026;
    // 0x800B41BC: and         $t7, $t6, $v0
    ctx->r15 = ctx->r14 & ctx->r2;
    // 0x800B41C0: bnel        $t7, $zero, L_800B41D4
    if (ctx->r15 != 0) {
        // 0x800B41C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B41D4;
    }
    goto skip_0;
    // 0x800B41C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B41C8: jal         0x80060F30
    // 0x800B41CC: lw          $a2, 0x1C4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1C4);
    Object_PlayerSfx(rdram, ctx);
        goto after_1;
    // 0x800B41CC: lw          $a2, 0x1C4($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X1C4);
    after_1:
L_800B41D0:
    // 0x800B41D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B41D4:
    // 0x800B41D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B41D8: jr          $ra
    // 0x800B41DC: nop

    return;
    // 0x800B41DC: nop

;}
RECOMP_FUNC void Audio_NoteInitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800132E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800132EC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800132F0: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x800132F4: addiu       $s4, $s4, 0x5CA0
    ctx->r20 = ADD32(ctx->r20, 0X5CA0);
    // 0x800132F8: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800132FC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80013300: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80013304: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x80013308: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8001330C: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x80013310: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80013314: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80013318: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001331C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80013320: blez        $t6, L_800133D0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80013324: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800133D0;
    }
    // 0x80013324: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80013328: lui         $s7, 0x8015
    ctx->r23 = S32(0X8015 << 16);
    // 0x8001332C: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x80013330: lui         $s5, 0x8015
    ctx->r21 = S32(0X8015 << 16);
    // 0x80013334: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80013338: addiu       $s5, $s5, -0x1AD0
    ctx->r21 = ADD32(ctx->r21, -0X1AD0);
    // 0x8001333C: addiu       $s6, $s6, -0x2EA0
    ctx->r22 = ADD32(ctx->r22, -0X2EA0);
    // 0x80013340: addiu       $s7, $s7, -0x3E20
    ctx->r23 = ADD32(ctx->r23, -0X3E20);
    // 0x80013344: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80013348: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x8001334C: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
L_80013350:
    // 0x80013350: lw          $at, 0x0($s6)
    ctx->r1 = MEM_W(ctx->r22, 0X0);
    // 0x80013354: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80013358: addu        $s0, $s2, $t7
    ctx->r16 = ADD32(ctx->r18, ctx->r15);
    // 0x8001335C: sw          $at, 0xB0($s0)
    MEM_W(0XB0, ctx->r16) = ctx->r1;
    // 0x80013360: lw          $t9, 0x4($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X4);
    // 0x80013364: addiu       $a1, $zero, 0xC0
    ctx->r5 = ADD32(0, 0XC0);
    // 0x80013368: sw          $t9, 0xB4($s0)
    MEM_W(0XB4, ctx->r16) = ctx->r25;
    // 0x8001336C: lw          $at, 0x8($s6)
    ctx->r1 = MEM_W(ctx->r22, 0X8);
    // 0x80013370: sw          $at, 0xB8($s0)
    MEM_W(0XB8, ctx->r16) = ctx->r1;
    // 0x80013374: lw          $t9, 0xC($s6)
    ctx->r25 = MEM_W(ctx->r22, 0XC);
    // 0x80013378: sb          $zero, 0x30($s0)
    MEM_B(0X30, ctx->r16) = 0;
    // 0x8001337C: sb          $zero, 0x34($s0)
    MEM_B(0X34, ctx->r16) = 0;
    // 0x80013380: sw          $s3, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r19;
    // 0x80013384: sw          $s3, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r19;
    // 0x80013388: sw          $s3, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r19;
    // 0x8001338C: sb          $zero, 0x31($s0)
    MEM_B(0X31, ctx->r16) = 0;
    // 0x80013390: swc1        $f20, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f20.u32l;
    // 0x80013394: sh          $zero, 0x36($s0)
    MEM_H(0X36, ctx->r16) = 0;
    // 0x80013398: sb          $zero, 0x59($s0)
    MEM_B(0X59, ctx->r16) = 0;
    // 0x8001339C: sb          $zero, 0x58($s0)
    MEM_B(0X58, ctx->r16) = 0;
    // 0x800133A0: sb          $zero, 0xA0($s0)
    MEM_B(0XA0, ctx->r16) = 0;
    // 0x800133A4: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
    // 0x800133A8: swc1        $f20, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f20.u32l;
    // 0x800133AC: jal         0x8000BF14
    // 0x800133B0: sw          $t9, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r25;
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x800133B0: sw          $t9, 0xBC($s0)
    MEM_W(0XBC, ctx->r16) = ctx->r25;
    after_0:
    // 0x800133B4: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x800133B8: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800133BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800133C0: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x800133C4: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800133C8: bnel        $at, $zero, L_80013350
    if (ctx->r1 != 0) {
        // 0x800133CC: lw          $t7, 0x0($s5)
        ctx->r15 = MEM_W(ctx->r21, 0X0);
            goto L_80013350;
    }
    goto skip_0;
    // 0x800133CC: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    skip_0:
L_800133D0:
    // 0x800133D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800133D4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800133D8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800133DC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800133E0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800133E4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800133E8: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800133EC: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800133F0: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x800133F4: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x800133F8: jr          $ra
    // 0x800133FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800133FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ItemSupplyRing_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068020: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80068024: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80068028: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006802C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80068030: lbu         $v0, 0x46($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X46);
    // 0x80068034: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80068038: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x8006803C: beq         $v0, $zero, L_80068058
    if (ctx->r2 == 0) {
        // 0x80068040: lui         $a1, 0x3ECC
        ctx->r5 = S32(0X3ECC << 16);
            goto L_80068058;
    }
    // 0x80068040: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x80068044: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068048: beql        $v0, $at, L_80068310
    if (ctx->r2 == ctx->r1) {
        // 0x8006804C: lhu         $t3, 0x48($s0)
        ctx->r11 = MEM_HU(ctx->r16, 0X48);
            goto L_80068310;
    }
    goto skip_0;
    // 0x8006804C: lhu         $t3, 0x48($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X48);
    skip_0:
    // 0x80068050: b           L_800685C8
    // 0x80068054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800685C8;
    // 0x80068054: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80068058:
    // 0x80068058: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006805C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80068060: lui         $a3, 0x3D4C
    ctx->r7 = S32(0X3D4C << 16);
    // 0x80068064: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068068: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x8006806C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80068070: jal         0x8009BC2C
    // 0x80068074: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x80068074: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80068078: jal         0x80066EF0
    // 0x8006807C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_CheckBounds(rdram, ctx);
        goto after_1;
    // 0x8006807C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80068080: jal         0x800671D0
    // 0x80068084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_SpinPickup(rdram, ctx);
        goto after_2;
    // 0x80068084: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80068088: lb          $t6, 0x4C($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X4C);
    // 0x8006808C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80068090: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80068094: beql        $t6, $zero, L_800682DC
    if (ctx->r14 == 0) {
        // 0x80068098: lhu         $t2, 0x2($s0)
        ctx->r10 = MEM_HU(ctx->r16, 0X2);
            goto L_800682DC;
    }
    goto skip_1;
    // 0x80068098: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    skip_1:
    // 0x8006809C: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800680A0: addiu       $at, $zero, 0x144
    ctx->r1 = ADD32(0, 0X144);
    // 0x800680A4: sb          $t7, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r15;
    // 0x800680A8: bne         $v0, $at, L_80068108
    if (ctx->r2 != ctx->r1) {
        // 0x800680AC: sh          $t8, 0x48($s0)
        MEM_H(0X48, ctx->r16) = ctx->r24;
            goto L_80068108;
    }
    // 0x800680AC: sh          $t8, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r24;
    // 0x800680B0: lh          $t2, 0x4E($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X4E);
    // 0x800680B4: addiu       $t0, $zero, 0x4E0
    ctx->r8 = ADD32(0, 0X4E0);
    // 0x800680B8: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800680BC: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800680C0: addiu       $t1, $t1, -0x7D80
    ctx->r9 = ADD32(ctx->r9, -0X7D80);
    // 0x800680C4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800680C8: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x800680CC: ori         $a1, $a1, 0x200E
    ctx->r5 = ctx->r5 | 0X200E;
    // 0x800680D0: mflo        $t3
    ctx->r11 = lo;
    // 0x800680D4: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x800680D8: lw          $t4, 0x26C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X26C);
    // 0x800680DC: addiu       $t5, $t4, 0x20
    ctx->r13 = ADD32(ctx->r12, 0X20);
    // 0x800680E0: sw          $t5, 0x26C($v0)
    MEM_W(0X26C, ctx->r2) = ctx->r13;
    // 0x800680E4: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x800680E8: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800680EC: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800680F0: mflo        $t7
    ctx->r15 = lo;
    // 0x800680F4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800680F8: jal         0x80060F30
    // 0x800680FC: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Object_PlayerSfx(rdram, ctx);
        goto after_3;
    // 0x800680FC: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_3:
    // 0x80068100: b           L_800682DC
    // 0x80068104: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
        goto L_800682DC;
    // 0x80068104: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
L_80068108:
    // 0x80068108: addiu       $at, $zero, 0x150
    ctx->r1 = ADD32(0, 0X150);
    // 0x8006810C: bne         $v0, $at, L_80068288
    if (ctx->r2 != ctx->r1) {
        // 0x80068110: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_80068288;
    }
    // 0x80068110: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80068114: addiu       $v0, $v0, 0x1A90
    ctx->r2 = ADD32(ctx->r2, 0X1A90);
    // 0x80068118: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8006811C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80068120: addiu       $t2, $t8, 0x1
    ctx->r10 = ADD32(ctx->r24, 0X1);
    // 0x80068124: andi        $v1, $t2, 0xFF
    ctx->r3 = ctx->r10 & 0XFF;
    // 0x80068128: bne         $v1, $at, L_80068168
    if (ctx->r3 != ctx->r1) {
        // 0x8006812C: sb          $t2, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r10;
            goto L_80068168;
    }
    // 0x8006812C: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x80068130: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x80068134: addiu       $t0, $zero, 0x4E0
    ctx->r8 = ADD32(0, 0X4E0);
    // 0x80068138: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8006813C: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068140: addiu       $t1, $t1, -0x7D80
    ctx->r9 = ADD32(ctx->r9, -0X7D80);
    // 0x80068144: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80068148: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x8006814C: ori         $a1, $a1, 0x8015
    ctx->r5 = ctx->r5 | 0X8015;
    // 0x80068150: mflo        $t3
    ctx->r11 = lo;
    // 0x80068154: addu        $a0, $t9, $t3
    ctx->r4 = ADD32(ctx->r25, ctx->r11);
    // 0x80068158: jal         0x80060F30
    // 0x8006815C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Object_PlayerSfx(rdram, ctx);
        goto after_4;
    // 0x8006815C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_4:
    // 0x80068160: b           L_800682DC
    // 0x80068164: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
        goto L_800682DC;
    // 0x80068164: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
L_80068168:
    // 0x80068168: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8006816C: bnel        $v1, $at, L_80068234
    if (ctx->r3 != ctx->r1) {
        // 0x80068170: lh          $t4, 0x4E($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X4E);
            goto L_80068234;
    }
    goto skip_2;
    // 0x80068170: lh          $t4, 0x4E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4E);
    skip_2:
    // 0x80068174: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x80068178: addiu       $t0, $zero, 0x4E0
    ctx->r8 = ADD32(0, 0X4E0);
    // 0x8006817C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80068180: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068184: addiu       $t1, $t1, -0x7D80
    ctx->r9 = ADD32(ctx->r9, -0X7D80);
    // 0x80068188: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8006818C: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x80068190: ori         $a1, $a1, 0xC024
    ctx->r5 = ctx->r5 | 0XC024;
    // 0x80068194: mflo        $t5
    ctx->r13 = lo;
    // 0x80068198: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    // 0x8006819C: jal         0x80060F30
    // 0x800681A0: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Object_PlayerSfx(rdram, ctx);
        goto after_5;
    // 0x800681A0: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_5:
    // 0x800681A4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800681A8: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800681AC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800681B0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800681B4: addiu       $t1, $t1, -0x7D80
    ctx->r9 = ADD32(ctx->r9, -0X7D80);
    // 0x800681B8: beq         $t6, $at, L_800681E0
    if (ctx->r14 == ctx->r1) {
        // 0x800681BC: addiu       $t0, $zero, 0x4E0
        ctx->r8 = ADD32(0, 0X4E0);
            goto L_800681E0;
    }
    // 0x800681BC: addiu       $t0, $zero, 0x4E0
    ctx->r8 = ADD32(0, 0X4E0);
    // 0x800681C0: lh          $t7, 0x4E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4E);
    // 0x800681C4: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x800681C8: addiu       $t2, $t2, 0x1AA0
    ctx->r10 = ADD32(ctx->r10, 0X1AA0);
    // 0x800681CC: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800681D0: addu        $v0, $t8, $t2
    ctx->r2 = ADD32(ctx->r24, ctx->r10);
    // 0x800681D4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800681D8: addiu       $t3, $t9, 0x1
    ctx->r11 = ADD32(ctx->r25, 0X1);
    // 0x800681DC: sh          $t3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r11;
L_800681E0:
    // 0x800681E0: lh          $t5, 0x4E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4E);
    // 0x800681E4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800681E8: addiu       $a3, $zero, 0x65
    ctx->r7 = ADD32(0, 0X65);
    // 0x800681EC: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800681F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800681F4: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x800681F8: lw          $t7, 0x26C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X26C);
    // 0x800681FC: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x80068200: sw          $t8, 0x26C($v0)
    MEM_W(0X26C, ctx->r2) = ctx->r24;
    // 0x80068204: lh          $t9, 0x4E($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4E);
    // 0x80068208: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8006820C: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068210: mflo        $t3
    ctx->r11 = lo;
    // 0x80068214: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80068218: lwc1        $f12, 0x74($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8006821C: lwc1        $f14, 0x78($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X78);
    // 0x80068220: jal         0x80077240
    // 0x80068224: lw          $a2, 0x138($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X138);
    BonusText_Display(rdram, ctx);
        goto after_6;
    // 0x80068224: lw          $a2, 0x138($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X138);
    after_6:
    // 0x80068228: b           L_800682DC
    // 0x8006822C: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
        goto L_800682DC;
    // 0x8006822C: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
    // 0x80068230: lh          $t4, 0x4E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4E);
L_80068234:
    // 0x80068234: addiu       $t0, $zero, 0x4E0
    ctx->r8 = ADD32(0, 0X4E0);
    // 0x80068238: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8006823C: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068240: addiu       $t1, $t1, -0x7D80
    ctx->r9 = ADD32(ctx->r9, -0X7D80);
    // 0x80068244: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80068248: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x8006824C: ori         $a1, $a1, 0x3013
    ctx->r5 = ctx->r5 | 0X3013;
    // 0x80068250: mflo        $t6
    ctx->r14 = lo;
    // 0x80068254: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
    // 0x80068258: lw          $t7, 0x26C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X26C);
    // 0x8006825C: addiu       $t8, $t7, 0x20
    ctx->r24 = ADD32(ctx->r15, 0X20);
    // 0x80068260: sw          $t8, 0x26C($v0)
    MEM_W(0X26C, ctx->r2) = ctx->r24;
    // 0x80068264: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x80068268: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8006826C: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068270: mflo        $t2
    ctx->r10 = lo;
    // 0x80068274: addu        $a0, $t9, $t2
    ctx->r4 = ADD32(ctx->r25, ctx->r10);
    // 0x80068278: jal         0x80060F30
    // 0x8006827C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Object_PlayerSfx(rdram, ctx);
        goto after_7;
    // 0x8006827C: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_7:
    // 0x80068280: b           L_800682DC
    // 0x80068284: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
        goto L_800682DC;
    // 0x80068284: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
L_80068288:
    // 0x80068288: lh          $t4, 0x4E($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4E);
    // 0x8006828C: addiu       $t0, $zero, 0x4E0
    ctx->r8 = ADD32(0, 0X4E0);
    // 0x80068290: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80068294: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068298: addiu       $t1, $t1, -0x7D80
    ctx->r9 = ADD32(ctx->r9, -0X7D80);
    // 0x8006829C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800682A0: lui         $a1, 0x4900
    ctx->r5 = S32(0X4900 << 16);
    // 0x800682A4: ori         $a1, $a1, 0x200D
    ctx->r5 = ctx->r5 | 0X200D;
    // 0x800682A8: mflo        $t5
    ctx->r13 = lo;
    // 0x800682AC: addu        $v0, $t3, $t5
    ctx->r2 = ADD32(ctx->r11, ctx->r13);
    // 0x800682B0: lw          $t6, 0x26C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X26C);
    // 0x800682B4: addiu       $t7, $t6, 0x80
    ctx->r15 = ADD32(ctx->r14, 0X80);
    // 0x800682B8: sw          $t7, 0x26C($v0)
    MEM_W(0X26C, ctx->r2) = ctx->r15;
    // 0x800682BC: lh          $a2, 0x4E($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X4E);
    // 0x800682C0: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800682C4: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800682C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800682CC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800682D0: jal         0x80060F30
    // 0x800682D4: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Object_PlayerSfx(rdram, ctx);
        goto after_8;
    // 0x800682D4: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_8:
    // 0x800682D8: lhu         $t2, 0x2($s0)
    ctx->r10 = MEM_HU(ctx->r16, 0X2);
L_800682DC:
    // 0x800682DC: addiu       $at, $zero, 0x150
    ctx->r1 = ADD32(0, 0X150);
    // 0x800682E0: bnel        $t2, $at, L_800685C8
    if (ctx->r10 != ctx->r1) {
        // 0x800682E4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800685C8;
    }
    goto skip_3;
    // 0x800682E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x800682E8: lhu         $t4, 0x48($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X48);
    // 0x800682EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800682F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800682F4: bnel        $t4, $at, L_800685C8
    if (ctx->r12 != ctx->r1) {
        // 0x800682F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800685C8;
    }
    goto skip_4;
    // 0x800682F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800682FC: jal         0x80060FBC
    // 0x80068300: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_9;
    // 0x80068300: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_9:
    // 0x80068304: b           L_800685C8
    // 0x80068308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800685C8;
    // 0x80068308: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006830C: lhu         $t3, 0x48($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X48);
L_80068310:
    // 0x80068310: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x80068314: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80068318: slti        $at, $t3, 0x1F
    ctx->r1 = SIGNED(ctx->r11) < 0X1F ? 1 : 0;
    // 0x8006831C: bne         $at, $zero, L_80068354
    if (ctx->r1 != 0) {
        // 0x80068320: lui         $a3, 0x3D75
        ctx->r7 = S32(0X3D75 << 16);
            goto L_80068354;
    }
    // 0x80068320: lui         $a3, 0x3D75
    ctx->r7 = S32(0X3D75 << 16);
    // 0x80068324: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80068328: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006832C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80068330: lui         $a3, 0x3D75
    ctx->r7 = S32(0X3D75 << 16);
    // 0x80068334: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80068338: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8006833C: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80068340: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x80068344: jal         0x8009BC2C
    // 0x80068348: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80068348: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x8006834C: b           L_80068374
    // 0x80068350: lh          $t5, 0x4E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4E);
        goto L_80068374;
    // 0x80068350: lh          $t5, 0x4E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4E);
L_80068354:
    // 0x80068354: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80068358: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8006835C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80068360: ori         $a3, $a3, 0xC28F
    ctx->r7 = ctx->r7 | 0XC28F;
    // 0x80068364: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068368: jal         0x8009BC2C
    // 0x8006836C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x8006836C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80068370: lh          $t5, 0x4E($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4E);
L_80068374:
    // 0x80068374: addiu       $t0, $zero, 0x4E0
    ctx->r8 = ADD32(0, 0X4E0);
    // 0x80068378: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8006837C: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068380: addiu       $t1, $t1, -0x7D80
    ctx->r9 = ADD32(ctx->r9, -0X7D80);
    // 0x80068384: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80068388: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006838C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80068390: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80068394: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80068398: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8006839C: mflo        $v1
    ctx->r3 = lo;
    // 0x800683A0: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800683A4: lwc1        $f10, 0x74($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X74);
    // 0x800683A8: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800683AC: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800683B0: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800683B4: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x800683B8: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800683BC: addu        $v0, $t8, $v1
    ctx->r2 = ADD32(ctx->r24, ctx->r3);
    // 0x800683C0: lw          $t9, 0x1CC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1CC);
    // 0x800683C4: bne         $t9, $at, L_800683F0
    if (ctx->r25 != ctx->r1) {
        // 0x800683C8: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_800683F0;
    }
    // 0x800683C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800683CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800683D0: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800683D4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800683D8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800683DC: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800683E0: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800683E4: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800683E8: b           L_80068408
    // 0x800683EC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
        goto L_80068408;
    // 0x800683EC: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_800683F0:
    // 0x800683F0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800683F4: lwc1        $f6, 0x78($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800683F8: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800683FC: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80068400: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80068404: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
L_80068408:
    // 0x80068408: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8006840C: lw          $t2, 0x238($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X238);
    // 0x80068410: addu        $t5, $v0, $v1
    ctx->r13 = ADD32(ctx->r2, ctx->r3);
    // 0x80068414: beql        $t2, $zero, L_80068460
    if (ctx->r10 == 0) {
        // 0x80068418: lwc1        $f0, 0xC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80068460;
    }
    goto skip_5;
    // 0x80068418: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x8006841C: lw          $t4, 0x7880($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7880);
    // 0x80068420: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x80068424: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80068428: bnel        $t4, $zero, L_80068460
    if (ctx->r12 != 0) {
        // 0x8006842C: lwc1        $f0, 0xC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80068460;
    }
    goto skip_6;
    // 0x8006842C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x80068430: lwc1        $f18, 0x138($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X138);
    // 0x80068434: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80068438: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006843C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068440: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80068444: lwc1        $f10, 0x6984($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6984);
    // 0x80068448: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8006844C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80068450: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80068454: b           L_80068474
    // 0x80068458: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_80068474;
    // 0x80068458: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8006845C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
L_80068460:
    // 0x80068460: lwc1        $f4, 0x138($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X138);
    // 0x80068464: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80068468: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006846C: add.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80068470: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80068474:
    // 0x80068474: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80068478: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006847C: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80068480: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80068484: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80068488: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8006848C: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80068490: lwc1        $f12, 0x58($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X58);
    // 0x80068494: jal         0x8009F768
    // 0x80068498: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_12;
    // 0x80068498: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    after_12:
    // 0x8006849C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800684A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800684A4: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800684A8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800684AC: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x800684B0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800684B4: jal         0x8009BD38
    // 0x800684B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_13;
    // 0x800684B8: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_13:
    // 0x800684BC: lhu         $t8, 0x48($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X48);
    // 0x800684C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800684C4: bne         $t8, $zero, L_800684D4
    if (ctx->r24 != 0) {
        // 0x800684C8: nop
    
            goto L_800684D4;
    }
    // 0x800684C8: nop

    // 0x800684CC: jal         0x80060FBC
    // 0x800684D0: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_14;
    // 0x800684D0: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_14:
L_800684D4:
    // 0x800684D4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800684D8: lwc1        $f8, 0x6988($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6988);
    // 0x800684DC: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800684E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800684E4: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800684E8: nop

    // 0x800684EC: bc1fl       L_800685C8
    if (!c1cs) {
        // 0x800684F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800685C8;
    }
    goto skip_7;
    // 0x800684F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_7:
    // 0x800684F4: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800684F8: lwc1        $f18, 0x698C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X698C);
    // 0x800684FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80068500: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80068504: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80068508: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006850C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80068510: jal         0x80005E90
    // 0x80068514: nop

    Matrix_RotateY(rdram, ctx);
        goto after_15;
    // 0x80068514: nop

    after_15:
    // 0x80068518: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8006851C: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x80068520: lui         $at, 0x4214
    ctx->r1 = S32(0X4214 << 16);
    // 0x80068524: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80068528: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8006852C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80068530: lwc1        $f18, 0x6990($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6990);
    // 0x80068534: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80068538: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006853C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80068540: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80068544: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80068548: nop

    // 0x8006854C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80068550: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80068554: jal         0x80005FE0
    // 0x80068558: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_16;
    // 0x80068558: nop

    after_16:
    // 0x8006855C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80068560: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80068564: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80068568: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x8006856C: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80068570: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80068574: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80068578: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006857C: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80068580: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80068584: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80068588: jal         0x80006A20
    // 0x8006858C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_17;
    // 0x8006858C: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    after_17:
    // 0x80068590: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80068594: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80068598: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006859C: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800685A0: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800685A4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800685A8: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800685AC: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800685B0: lui         $a3, 0x4060
    ctx->r7 = S32(0X4060 << 16);
    // 0x800685B4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800685B8: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800685BC: jal         0x80078E50
    // 0x800685C0: nop

    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_18;
    // 0x800685C0: nop

    after_18:
    // 0x800685C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800685C8:
    // 0x800685C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800685CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800685D0: jr          $ra
    // 0x800685D4: nop

    return;
    // 0x800685D4: nop

;}
RECOMP_FUNC void Player_SetupArwingShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC290: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800AC294: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800AC298: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800AC29C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800AC2A0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800AC2A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800AC2A8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800AC2AC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800AC2B0: jal         0x80035E48
    // 0x800AC2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_Initialize(rdram, ctx);
        goto after_0;
    // 0x800AC2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800AC2B8: lwc1        $f4, 0x114($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X114);
    // 0x800AC2BC: lwc1        $f6, 0xE8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800AC2C0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800AC2C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800AC2C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AC2CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC2D0: lwc1        $f18, -0x79E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X79E4);
    // 0x800AC2D4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AC2D8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AC2DC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AC2E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AC2E4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AC2E8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800AC2EC: jal         0x80005E90
    // 0x800AC2F0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x800AC2F0: nop

    after_1:
    // 0x800AC2F4: lwc1        $f6, 0x120($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X120);
    // 0x800AC2F8: lwc1        $f8, 0xE4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x800AC2FC: lwc1        $f16, 0x4D8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4D8);
    // 0x800AC300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC304: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC308: lwc1        $f4, -0x79E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X79E0);
    // 0x800AC30C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AC310: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AC314: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AC318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC31C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AC320: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AC324: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800AC328: jal         0x80005D44
    // 0x800AC32C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x800AC32C: nop

    after_2:
    // 0x800AC330: lwc1        $f10, 0xF8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x800AC334: lwc1        $f16, 0xF0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XF0);
    // 0x800AC338: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC33C: lwc1        $f4, -0x79DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X79DC);
    // 0x800AC340: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AC344: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AC348: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AC34C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800AC350: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800AC354: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800AC358: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800AC35C: jal         0x80005FE0
    // 0x800AC360: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x800AC360: nop

    after_3:
    // 0x800AC364: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AC368: lw          $a1, 0x84($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X84);
    // 0x800AC36C: lw          $a2, 0x80($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X80);
    // 0x800AC370: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AC374: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800AC378: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AC37C: jal         0x80005B00
    // 0x800AC380: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x800AC380: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_4:
    // 0x800AC384: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800AC388: lw          $t7, 0x78E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78E8);
    // 0x800AC38C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800AC390: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AC394: beq         $t7, $zero, L_800AC3C0
    if (ctx->r15 == 0) {
        // 0x800AC398: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_800AC3C0;
    }
    // 0x800AC398: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800AC39C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800AC3A0: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800AC3A4: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x800AC3A8: beq         $at, $zero, L_800AC3C0
    if (ctx->r1 == 0) {
        // 0x800AC3AC: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800AC3C0;
    }
    // 0x800AC3AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800AC3B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AC3B4: nop

    // 0x800AC3B8: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800AC3BC: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_800AC3C0:
    // 0x800AC3C0: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800AC3C4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800AC3C8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800AC3CC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AC3D0: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800AC3D4: jal         0x80006970
    // 0x800AC3D8: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_5;
    // 0x800AC3D8: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    after_5:
    // 0x800AC3DC: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x800AC3E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AC3E4: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800AC3E8: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800AC3EC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800AC3F0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AC3F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800AC3F8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800AC3FC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800AC400: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800AC404: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800AC408: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800AC40C: jal         0x80006970
    // 0x800AC410: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_6;
    // 0x800AC410: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x800AC414: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x800AC418: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AC41C: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
    // 0x800AC420: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AC424: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800AC428: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x800AC42C: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800AC430: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AC434: addiu       $t2, $zero, 0x25
    ctx->r10 = ADD32(0, 0X25);
    // 0x800AC438: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800AC43C: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800AC440: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AC444: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
    // 0x800AC448: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
    // 0x800AC44C: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x800AC450: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x800AC454: bnel        $t0, $zero, L_800AC468
    if (ctx->r8 != 0) {
        // 0x800AC458: sw          $t2, 0x64($s0)
        MEM_W(0X64, ctx->r16) = ctx->r10;
            goto L_800AC468;
    }
    goto skip_0;
    // 0x800AC458: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
    skip_0:
    // 0x800AC45C: b           L_800AC468
    // 0x800AC460: sw          $t1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r9;
        goto L_800AC468;
    // 0x800AC460: sw          $t1, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r9;
    // 0x800AC464: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
L_800AC468:
    // 0x800AC468: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    // 0x800AC46C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800AC470: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AC474: bne         $t3, $at, L_800AC4B8
    if (ctx->r11 != ctx->r1) {
        // 0x800AC478: lwc1        $f16, 0x38($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
            goto L_800AC4B8;
    }
    // 0x800AC478: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AC47C: lwc1        $f10, 0x74($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800AC480: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AC484: addiu       $t4, $zero, 0x26
    ctx->r12 = ADD32(0, 0X26);
    // 0x800AC488: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AC48C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x800AC490: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800AC494: lwc1        $f4, 0x78($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800AC498: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AC49C: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800AC4A0: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AC4A4: lwc1        $f10, 0x138($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AC4A8: sw          $t4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r12;
    // 0x800AC4AC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800AC4B0: b           L_800AC52C
    // 0x800AC4B4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_800AC52C;
    // 0x800AC4B4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_800AC4B8:
    // 0x800AC4B8: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800AC4BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC4C0: ldc1        $f0, -0x79D8($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X79D8);
    // 0x800AC4C4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800AC4C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AC4CC: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800AC4D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC4D4: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800AC4D8: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x800AC4DC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800AC4E0: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800AC4E4: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AC4E8: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800AC4EC: lwc1        $f16, 0x78($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800AC4F0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800AC4F4: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800AC4F8: mul.d       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800AC4FC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800AC500: add.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d + ctx->f16.d;
    // 0x800AC504: cvt.s.d     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f10.fl = CVT_S_D(ctx->f18.d);
    // 0x800AC508: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x800AC50C: lwc1        $f18, -0x79D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X79D0);
    // 0x800AC510: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AC514: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AC518: lwc1        $f6, 0x138($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800AC51C: mul.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800AC520: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC524: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AC528: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
L_800AC52C:
    // 0x800AC52C: lwc1        $f8, 0x120($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X120);
    // 0x800AC530: lwc1        $f16, 0xE4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x800AC534: lwc1        $f4, 0x4D8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4D8);
    // 0x800AC538: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800AC53C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AC540: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC544: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800AC548: lwc1        $f8, 0x114($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X114);
    // 0x800AC54C: lwc1        $f6, 0xE8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800AC550: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC554: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x800AC558: lwc1        $f18, 0xF8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x800AC55C: bne         $v0, $at, L_800AC634
    if (ctx->r2 != ctx->r1) {
        // 0x800AC560: swc1        $f18, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
            goto L_800AC634;
    }
    // 0x800AC560: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x800AC564: lw          $t5, -0x7DCC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7DCC);
    // 0x800AC568: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800AC56C: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x800AC570: bnel        $t5, $at, L_800AC5F0
    if (ctx->r13 != ctx->r1) {
        // 0x800AC574: lwc1        $f18, 0xE8($s1)
        ctx->f18.u32l = MEM_W(ctx->r17, 0XE8);
            goto L_800AC5F0;
    }
    goto skip_1;
    // 0x800AC574: lwc1        $f18, 0xE8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE8);
    skip_1:
    // 0x800AC578: jal         0x80004EB0
    // 0x800AC57C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x800AC57C: nop

    after_7:
    // 0x800AC580: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800AC584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AC588: nop

    // 0x800AC58C: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800AC590: trunc.w.s   $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800AC594: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800AC598: jal         0x80004EB0
    // 0x800AC59C: sw          $t7, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r15;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x800AC59C: sw          $t7, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r15;
    after_8:
    // 0x800AC5A0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800AC5A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AC5A8: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800AC5AC: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800AC5B0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800AC5B4: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800AC5B8: nop

    // 0x800AC5BC: sw          $t9, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r25;
    // 0x800AC5C0: lwc1        $f10, 0x4D8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4D8);
    // 0x800AC5C4: lwc1        $f4, 0xE4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x800AC5C8: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800AC5CC: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x800AC5D0: lwc1        $f8, 0xE8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XE8);
    // 0x800AC5D4: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
    // 0x800AC5D8: lwc1        $f16, 0xF8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XF8);
    // 0x800AC5DC: swc1        $f16, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f16.u32l;
    // 0x800AC5E0: lw          $t0, -0x7B6C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7B6C);
    // 0x800AC5E4: b           L_800AC634
    // 0x800AC5E8: sw          $t0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r8;
        goto L_800AC634;
    // 0x800AC5E8: sw          $t0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r8;
    // 0x800AC5EC: lwc1        $f18, 0xE8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XE8);
L_800AC5F0:
    // 0x800AC5F0: lwc1        $f4, 0x114($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X114);
    // 0x800AC5F4: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x800AC5F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AC5FC: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AC600: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AC604: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x800AC608: lwc1        $f8, 0x4D8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4D8);
    // 0x800AC60C: lwc1        $f6, 0xE4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XE4);
    // 0x800AC610: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800AC614: swc1        $f16, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f16.u32l;
    // 0x800AC618: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800AC61C: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x800AC620: nop

    // 0x800AC624: bc1fl       L_800AC634
    if (!c1cs) {
        // 0x800AC628: sw          $t2, 0x64($s0)
        MEM_W(0X64, ctx->r16) = ctx->r10;
            goto L_800AC634;
    }
    goto skip_2;
    // 0x800AC628: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
    skip_2:
    // 0x800AC62C: sw          $t1, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r9;
    // 0x800AC630: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
L_800AC634:
    // 0x800AC634: lw          $t3, 0x1C4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X1C4);
    // 0x800AC638: sw          $t3, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->r11;
    // 0x800AC63C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800AC640: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC644: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800AC648: jr          $ra
    // 0x800AC64C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800AC64C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Object_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F90: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80063F94: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80063F98: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80063F9C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80063FA0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80063FA4: slti        $at, $a1, 0x14E
    ctx->r1 = SIGNED(ctx->r5) < 0X14E ? 1 : 0;
    // 0x80063FA8: bne         $at, $zero, L_80063FC0
    if (ctx->r1 != 0) {
        // 0x80063FAC: addiu       $at, $zero, 0x170
        ctx->r1 = ADD32(0, 0X170);
            goto L_80063FC0;
    }
    // 0x80063FAC: addiu       $at, $zero, 0x170
    ctx->r1 = ADD32(0, 0X170);
    // 0x80063FB0: beq         $a1, $at, L_8006418C
    if (ctx->r5 == ctx->r1) {
        // 0x80063FB4: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8006418C;
    }
    // 0x80063FB4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80063FB8: b           L_800652BC
    // 0x80063FBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80063FBC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80063FC0:
    // 0x80063FC0: slti        $at, $a1, 0x42
    ctx->r1 = SIGNED(ctx->r5) < 0X42 ? 1 : 0;
    // 0x80063FC4: bne         $at, $zero, L_80063FEC
    if (ctx->r1 != 0) {
        // 0x80063FC8: addiu       $t6, $a1, -0xA9
        ctx->r14 = ADD32(ctx->r5, -0XA9);
            goto L_80063FEC;
    }
    // 0x80063FC8: addiu       $t6, $a1, -0xA9
    ctx->r14 = ADD32(ctx->r5, -0XA9);
    // 0x80063FCC: sltiu       $at, $t6, 0xA5
    ctx->r1 = ctx->r14 < 0XA5 ? 1 : 0;
    // 0x80063FD0: beq         $at, $zero, L_800652B8
    if (ctx->r1 == 0) {
        // 0x80063FD4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800652B8;
    }
    // 0x80063FD4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80063FD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80063FDC: addu        $at, $at, $t6
    gpr jr_addend_80063FE4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80063FE0: lw          $t6, 0x64D8($at)
    ctx->r14 = ADD32(ctx->r1, 0X64D8);
    // 0x80063FE4: jr          $t6
    // 0x80063FE8: nop

    switch (jr_addend_80063FE4 >> 2) {
        case 0: goto L_80064E74; break;
        case 1: goto L_8006400C; break;
        case 2: goto L_800652B8; break;
        case 3: goto L_800652B8; break;
        case 4: goto L_800652B8; break;
        case 5: goto L_800652B8; break;
        case 6: goto L_800652B8; break;
        case 7: goto L_80064C00; break;
        case 8: goto L_80064BD4; break;
        case 9: goto L_80064BD4; break;
        case 10: goto L_800652B8; break;
        case 11: goto L_800652B8; break;
        case 12: goto L_800645F4; break;
        case 13: goto L_80064580; break;
        case 14: goto L_800652B8; break;
        case 15: goto L_800652B8; break;
        case 16: goto L_800652B8; break;
        case 17: goto L_80064580; break;
        case 18: goto L_80064534; break;
        case 19: goto L_800652B8; break;
        case 20: goto L_800652B8; break;
        case 21: goto L_80064954; break;
        case 22: goto L_80064954; break;
        case 23: goto L_800649B0; break;
        case 24: goto L_800652B8; break;
        case 25: goto L_8006485C; break;
        case 26: goto L_800652B8; break;
        case 27: goto L_800652B8; break;
        case 28: goto L_800652B8; break;
        case 29: goto L_800640E0; break;
        case 30: goto L_800652B8; break;
        case 31: goto L_800652B8; break;
        case 32: goto L_800652B8; break;
        case 33: goto L_80064654; break;
        case 34: goto L_800652B8; break;
        case 35: goto L_800652B8; break;
        case 36: goto L_80064A4C; break;
        case 37: goto L_80064A4C; break;
        case 38: goto L_80064A80; break;
        case 39: goto L_80064A4C; break;
        case 40: goto L_80064A4C; break;
        case 41: goto L_80064A4C; break;
        case 42: goto L_80064A4C; break;
        case 43: goto L_80064A4C; break;
        case 44: goto L_80064A4C; break;
        case 45: goto L_80064AB4; break;
        case 46: goto L_80064AE8; break;
        case 47: goto L_80064B50; break;
        case 48: goto L_80064B50; break;
        case 49: goto L_80064B84; break;
        case 50: goto L_800652B8; break;
        case 51: goto L_800652B8; break;
        case 52: goto L_800652B8; break;
        case 53: goto L_800652B8; break;
        case 54: goto L_80064B1C; break;
        case 55: goto L_800652B8; break;
        case 56: goto L_800652B8; break;
        case 57: goto L_800652B8; break;
        case 58: goto L_80064E0C; break;
        case 59: goto L_80064E40; break;
        case 60: goto L_80064DD8; break;
        case 61: goto L_800652B8; break;
        case 62: goto L_80064D3C; break;
        case 63: goto L_80064D70; break;
        case 64: goto L_80064DA4; break;
        case 65: goto L_80064044; break;
        case 66: goto L_80064114; break;
        case 67: goto L_80064720; break;
        case 68: goto L_800652B8; break;
        case 69: goto L_800652B8; break;
        case 70: goto L_800646E0; break;
        case 71: goto L_80064EC4; break;
        case 72: goto L_80064EF8; break;
        case 73: goto L_800652B8; break;
        case 74: goto L_800652B8; break;
        case 75: goto L_800652B8; break;
        case 76: goto L_800652B8; break;
        case 77: goto L_800652B8; break;
        case 78: goto L_80064158; break;
        case 79: goto L_800652B8; break;
        case 80: goto L_800652B8; break;
        case 81: goto L_80064F50; break;
        case 82: goto L_80064F84; break;
        case 83: goto L_80064684; break;
        case 84: goto L_80064FB8; break;
        case 85: goto L_800652B8; break;
        case 86: goto L_80064FEC; break;
        case 87: goto L_80065020; break;
        case 88: goto L_80065054; break;
        case 89: goto L_800652B8; break;
        case 90: goto L_800650AC; break;
        case 91: goto L_80065114; break;
        case 92: goto L_800652B8; break;
        case 93: goto L_800650E0; break;
        case 94: goto L_800652B8; break;
        case 95: goto L_800652B8; break;
        case 96: goto L_80065258; break;
        case 97: goto L_800652B8; break;
        case 98: goto L_8006528C; break;
        case 99: goto L_800652B8; break;
        case 100: goto L_800652B8; break;
        case 101: goto L_800652B8; break;
        case 102: goto L_800652B8; break;
        case 103: goto L_800652B8; break;
        case 104: goto L_800652B8; break;
        case 105: goto L_800652B8; break;
        case 106: goto L_800652B8; break;
        case 107: goto L_800652B8; break;
        case 108: goto L_800652B8; break;
        case 109: goto L_800652B8; break;
        case 110: goto L_800652B8; break;
        case 111: goto L_80065188; break;
        case 112: goto L_800651BC; break;
        case 113: goto L_800651BC; break;
        case 114: goto L_800651F0; break;
        case 115: goto L_80065224; break;
        case 116: goto L_800652B8; break;
        case 117: goto L_800652B8; break;
        case 118: goto L_800652B8; break;
        case 119: goto L_800652B8; break;
        case 120: goto L_800652B8; break;
        case 121: goto L_800652B8; break;
        case 122: goto L_800652B8; break;
        case 123: goto L_80064CD0; break;
        case 124: goto L_80064CF4; break;
        case 125: goto L_800652B8; break;
        case 126: goto L_800652B8; break;
        case 127: goto L_800652B8; break;
        case 128: goto L_80064C64; break;
        case 129: goto L_800652B8; break;
        case 130: goto L_80064C88; break;
        case 131: goto L_80064CAC; break;
        case 132: goto L_800652B8; break;
        case 133: goto L_80064D18; break;
        case 134: goto L_800652B8; break;
        case 135: goto L_800652B8; break;
        case 136: goto L_800652B8; break;
        case 137: goto L_80064EA0; break;
        case 138: goto L_80064F2C; break;
        case 139: goto L_800652B8; break;
        case 140: goto L_800652B8; break;
        case 141: goto L_800652B8; break;
        case 142: goto L_800652B8; break;
        case 143: goto L_800652B8; break;
        case 144: goto L_800652B8; break;
        case 145: goto L_80064A28; break;
        case 146: goto L_800652B8; break;
        case 147: goto L_80064A04; break;
        case 148: goto L_800652B8; break;
        case 149: goto L_80065088; break;
        case 150: goto L_80065164; break;
        case 151: goto L_800649E0; break;
        case 152: goto L_800652B8; break;
        case 153: goto L_800652B8; break;
        case 154: goto L_800643B4; break;
        case 155: goto L_800652B8; break;
        case 156: goto L_800652B8; break;
        case 157: goto L_800643E4; break;
        case 158: goto L_800652B8; break;
        case 159: goto L_80064440; break;
        case 160: goto L_80064440; break;
        case 161: goto L_8006446C; break;
        case 162: goto L_80064414; break;
        case 163: goto L_80064414; break;
        case 164: goto L_80064414; break;
        default: switch_error(__func__, 0x80063FE4, 0x800D64D8);
    }
    // 0x80063FE8: nop

L_80063FEC:
    // 0x80063FEC: sltiu       $at, $a1, 0x42
    ctx->r1 = ctx->r5 < 0X42 ? 1 : 0;
    // 0x80063FF0: beq         $at, $zero, L_800652B8
    if (ctx->r1 == 0) {
        // 0x80063FF4: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800652B8;
    }
    // 0x80063FF4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80063FF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80063FFC: addu        $at, $at, $t7
    gpr jr_addend_80064004 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80064000: lw          $t7, 0x676C($at)
    ctx->r15 = ADD32(ctx->r1, 0X676C);
    // 0x80064004: jr          $t7
    // 0x80064008: nop

    switch (jr_addend_80064004 >> 2) {
        case 0: goto L_800644FC; break;
        case 1: goto L_800652B8; break;
        case 2: goto L_800652B8; break;
        case 3: goto L_800652B8; break;
        case 4: goto L_800652B8; break;
        case 5: goto L_800652B8; break;
        case 6: goto L_80064518; break;
        case 7: goto L_80064518; break;
        case 8: goto L_800652B8; break;
        case 9: goto L_800652B8; break;
        case 10: goto L_800652B8; break;
        case 11: goto L_800652B8; break;
        case 12: goto L_800652B8; break;
        case 13: goto L_800652B8; break;
        case 14: goto L_800652B8; break;
        case 15: goto L_800652B8; break;
        case 16: goto L_800652B8; break;
        case 17: goto L_800652B8; break;
        case 18: goto L_800652B8; break;
        case 19: goto L_800652B8; break;
        case 20: goto L_80064518; break;
        case 21: goto L_80064518; break;
        case 22: goto L_80064518; break;
        case 23: goto L_80064398; break;
        case 24: goto L_800652B8; break;
        case 25: goto L_800652B8; break;
        case 26: goto L_800652B8; break;
        case 27: goto L_800652B8; break;
        case 28: goto L_800652B8; break;
        case 29: goto L_800652B8; break;
        case 30: goto L_80064254; break;
        case 31: goto L_80064278; break;
        case 32: goto L_8006429C; break;
        case 33: goto L_800642C0; break;
        case 34: goto L_800642E4; break;
        case 35: goto L_80064308; break;
        case 36: goto L_8006432C; break;
        case 37: goto L_80064350; break;
        case 38: goto L_80064374; break;
        case 39: goto L_800652B8; break;
        case 40: goto L_800652B8; break;
        case 41: goto L_800652B8; break;
        case 42: goto L_800652B8; break;
        case 43: goto L_800652B8; break;
        case 44: goto L_800652B8; break;
        case 45: goto L_800652B8; break;
        case 46: goto L_800652B8; break;
        case 47: goto L_800652B8; break;
        case 48: goto L_800652B8; break;
        case 49: goto L_800652B8; break;
        case 50: goto L_800652B8; break;
        case 51: goto L_800652B8; break;
        case 52: goto L_800652B8; break;
        case 53: goto L_800652B8; break;
        case 54: goto L_800640A0; break;
        case 55: goto L_800652B8; break;
        case 56: goto L_80064518; break;
        case 57: goto L_80065148; break;
        case 58: goto L_800652B8; break;
        case 59: goto L_800652B8; break;
        case 60: goto L_800652B8; break;
        case 61: goto L_800652B8; break;
        case 62: goto L_800652B8; break;
        case 63: goto L_800652B8; break;
        case 64: goto L_800652B8; break;
        case 65: goto L_80064BB8; break;
        default: switch_error(__func__, 0x80064004, 0x800D676C);
    }
    // 0x80064008: nop

L_8006400C:
    // 0x8006400C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80064010: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80064014: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064018: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8006401C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064020: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80064024: addiu       $t0, $t0, 0x3400
    ctx->r8 = ADD32(ctx->r8, 0X3400);
    // 0x80064028: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x8006402C: lui         $a1, 0x1100
    ctx->r5 = S32(0X1100 << 16);
    // 0x80064030: ori         $a1, $a1, 0x55
    ctx->r5 = ctx->r5 | 0X55;
    // 0x80064034: jal         0x8007A6F0
    // 0x80064038: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_0;
    // 0x80064038: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x8006403C: b           L_800652BC
    // 0x80064040: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064040: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064044:
    // 0x80064044: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80064048: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8006404C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80064050: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x80064054: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064058: addu        $t1, $t1, $s1
    ctx->r9 = ADD32(ctx->r9, ctx->r17);
    // 0x8006405C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80064060: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064064: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80064068: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8006406C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80064070: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x80064074: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x80064078: addiu       $t2, $t1, 0x100
    ctx->r10 = ADD32(ctx->r9, 0X100);
    // 0x8006407C: lui         $a0, 0x1103
    ctx->r4 = S32(0X1103 << 16);
    // 0x80064080: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    // 0x80064084: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    // 0x80064088: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8006408C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80064090: jal         0x80019218
    // 0x80064094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80064094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80064098: b           L_800652BC
    // 0x8006409C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x8006409C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800640A0:
    // 0x800640A0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800640A4: sll         $t5, $s1, 7
    ctx->r13 = S32(ctx->r17 << 7);
    // 0x800640A8: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800640AC: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x800640B0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800640B4: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x800640B8: addiu       $t7, $t7, 0x1B00
    ctx->r15 = ADD32(ctx->r15, 0X1B00);
    // 0x800640BC: addiu       $t6, $t5, 0x70
    ctx->r14 = ADD32(ctx->r13, 0X70);
    // 0x800640C0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800640C4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800640C8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800640CC: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x800640D0: jal         0x80019218
    // 0x800640D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800640D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800640D8: b           L_800652BC
    // 0x800640DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800640DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800640E0:
    // 0x800640E0: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x800640E4: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x800640E8: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800640EC: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x800640F0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800640F4: addu        $t9, $t9, $s1
    ctx->r25 = ADD32(ctx->r25, ctx->r17);
    // 0x800640F8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x800640FC: addiu       $t0, $t0, 0x3FE0
    ctx->r8 = ADD32(ctx->r8, 0X3FE0);
    // 0x80064100: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80064104: jal         0x80092D48
    // 0x80064108: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    ActorTeamBoss_Init(rdram, ctx);
        goto after_3;
    // 0x80064108: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x8006410C: b           L_800652BC
    // 0x80064110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064114:
    // 0x80064114: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80064118: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x8006411C: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x80064120: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x80064124: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064128: addu        $t1, $t1, $s1
    ctx->r9 = ADD32(ctx->r9, ctx->r17);
    // 0x8006412C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80064130: addiu       $t2, $t2, 0x3FE0
    ctx->r10 = ADD32(ctx->r10, 0X3FE0);
    // 0x80064134: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064138: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8006413C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80064140: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x80064144: jal         0x80004E20
    // 0x80064148: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    Math_ModF(rdram, ctx);
        goto after_4;
    // 0x80064148: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    after_4:
    // 0x8006414C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80064150: b           L_800652B8
    // 0x80064154: swc1        $f0, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f0.u32l;
        goto L_800652B8;
    // 0x80064154: swc1        $f0, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f0.u32l;
L_80064158:
    // 0x80064158: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x8006415C: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x80064160: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x80064164: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x80064168: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006416C: addu        $t3, $t3, $s1
    ctx->r11 = ADD32(ctx->r11, ctx->r17);
    // 0x80064170: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80064174: addiu       $t4, $t4, 0x3FE0
    ctx->r12 = ADD32(ctx->r12, 0X3FE0);
    // 0x80064178: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8006417C: jal         0x8019D060
    // 0x80064180: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    Zoness_ZoBarrier_Init(rdram, ctx);
        goto after_5;
    // 0x80064180: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_5:
    // 0x80064184: b           L_800652BC
    // 0x80064188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064188: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006418C:
    // 0x8006418C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x80064190: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80064194: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    // 0x80064198: bne         $v0, $at, L_80064228
    if (ctx->r2 != ctx->r1) {
        // 0x8006419C: addu        $t5, $t5, $s1
        ctx->r13 = ADD32(ctx->r13, ctx->r17);
            goto L_80064228;
    }
    // 0x8006419C: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x800641A0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800641A4: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x800641A8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800641AC: addiu       $t6, $t6, 0x130
    ctx->r14 = ADD32(ctx->r14, 0X130);
    // 0x800641B0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800641B4: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x800641B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800641BC: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800641C0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800641C4: addiu       $t7, $sp, 0x50
    ctx->r15 = ADD32(ctx->r29, 0X50);
    // 0x800641C8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800641CC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800641D0: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x800641D4: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x800641D8: jal         0x801B6E20
    // 0x800641DC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_6;
    // 0x800641DC: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_6:
    // 0x800641E0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800641E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800641E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800641EC: lwc1        $f2, 0x6874($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6874);
    // 0x800641F0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800641F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800641F8: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800641FC: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80064200: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80064204: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80064208: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8006420C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80064210: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80064214: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80064218: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006421C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x80064220: b           L_800652B8
    // 0x80064224: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
        goto L_800652B8;
    // 0x80064224: swc1        $f16, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f16.u32l;
L_80064228:
    // 0x80064228: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8006422C: bne         $v0, $at, L_800652B8
    if (ctx->r2 != ctx->r1) {
        // 0x80064230: sll         $t8, $s1, 3
        ctx->r24 = S32(ctx->r17 << 3);
            goto L_800652B8;
    }
    // 0x80064230: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x80064234: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80064238: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8006423C: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064240: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064244: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80064248: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8006424C: b           L_800652B8
    // 0x80064250: sb          $zero, 0x130($at)
    MEM_B(0X130, ctx->r1) = 0;
        goto L_800652B8;
    // 0x80064250: sb          $zero, 0x130($at)
    MEM_B(0X130, ctx->r1) = 0;
L_80064254:
    // 0x80064254: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x80064258: addiu       $t0, $t0, 0x1B00
    ctx->r8 = ADD32(ctx->r8, 0X1B00);
    // 0x8006425C: sll         $t9, $s1, 7
    ctx->r25 = S32(ctx->r17 << 7);
    // 0x80064260: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80064264: addiu       $a1, $a1, 0x6940
    ctx->r5 = ADD32(ctx->r5, 0X6940);
    // 0x80064268: jal         0x80063E5C
    // 0x8006426C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_7;
    // 0x8006426C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_7:
    // 0x80064270: b           L_800652BC
    // 0x80064274: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064274: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064278:
    // 0x80064278: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8006427C: addiu       $t2, $t2, 0x1B00
    ctx->r10 = ADD32(ctx->r10, 0X1B00);
    // 0x80064280: sll         $t1, $s1, 7
    ctx->r9 = S32(ctx->r17 << 7);
    // 0x80064284: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80064288: addiu       $a1, $a1, 0x695C
    ctx->r5 = ADD32(ctx->r5, 0X695C);
    // 0x8006428C: jal         0x80063E5C
    // 0x80064290: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_8;
    // 0x80064290: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_8:
    // 0x80064294: b           L_800652BC
    // 0x80064298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006429C:
    // 0x8006429C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x800642A0: addiu       $t4, $t4, 0x1B00
    ctx->r12 = ADD32(ctx->r12, 0X1B00);
    // 0x800642A4: sll         $t3, $s1, 7
    ctx->r11 = S32(ctx->r17 << 7);
    // 0x800642A8: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x800642AC: addiu       $a1, $a1, 0x6978
    ctx->r5 = ADD32(ctx->r5, 0X6978);
    // 0x800642B0: jal         0x80063E5C
    // 0x800642B4: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_9;
    // 0x800642B4: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_9:
    // 0x800642B8: b           L_800652BC
    // 0x800642BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800642BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800642C0:
    // 0x800642C0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800642C4: addiu       $t6, $t6, 0x1B00
    ctx->r14 = ADD32(ctx->r14, 0X1B00);
    // 0x800642C8: sll         $t5, $s1, 7
    ctx->r13 = S32(ctx->r17 << 7);
    // 0x800642CC: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x800642D0: addiu       $a1, $a1, 0x6994
    ctx->r5 = ADD32(ctx->r5, 0X6994);
    // 0x800642D4: jal         0x80063E5C
    // 0x800642D8: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_10;
    // 0x800642D8: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_10:
    // 0x800642DC: b           L_800652BC
    // 0x800642E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800642E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800642E4:
    // 0x800642E4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x800642E8: addiu       $t8, $t8, 0x1B00
    ctx->r24 = ADD32(ctx->r24, 0X1B00);
    // 0x800642EC: sll         $t7, $s1, 7
    ctx->r15 = S32(ctx->r17 << 7);
    // 0x800642F0: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x800642F4: addiu       $a1, $a1, 0x69B0
    ctx->r5 = ADD32(ctx->r5, 0X69B0);
    // 0x800642F8: jal         0x80063E5C
    // 0x800642FC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_11;
    // 0x800642FC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_11:
    // 0x80064300: b           L_800652BC
    // 0x80064304: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064304: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064308:
    // 0x80064308: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8006430C: addiu       $t0, $t0, 0x1B00
    ctx->r8 = ADD32(ctx->r8, 0X1B00);
    // 0x80064310: sll         $t9, $s1, 7
    ctx->r25 = S32(ctx->r17 << 7);
    // 0x80064314: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80064318: addiu       $a1, $a1, 0x69CC
    ctx->r5 = ADD32(ctx->r5, 0X69CC);
    // 0x8006431C: jal         0x80063E5C
    // 0x80064320: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_12;
    // 0x80064320: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    after_12:
    // 0x80064324: b           L_800652BC
    // 0x80064328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064328: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006432C:
    // 0x8006432C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80064330: addiu       $t2, $t2, 0x1B00
    ctx->r10 = ADD32(ctx->r10, 0X1B00);
    // 0x80064334: sll         $t1, $s1, 7
    ctx->r9 = S32(ctx->r17 << 7);
    // 0x80064338: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x8006433C: addiu       $a1, $a1, 0x69E8
    ctx->r5 = ADD32(ctx->r5, 0X69E8);
    // 0x80064340: jal         0x80063E5C
    // 0x80064344: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_13;
    // 0x80064344: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_13:
    // 0x80064348: b           L_800652BC
    // 0x8006434C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x8006434C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064350:
    // 0x80064350: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80064354: addiu       $t4, $t4, 0x1B00
    ctx->r12 = ADD32(ctx->r12, 0X1B00);
    // 0x80064358: sll         $t3, $s1, 7
    ctx->r11 = S32(ctx->r17 << 7);
    // 0x8006435C: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80064360: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x80064364: jal         0x80063E5C
    // 0x80064368: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_14;
    // 0x80064368: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_14:
    // 0x8006436C: b           L_800652BC
    // 0x80064370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064370: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064374:
    // 0x80064374: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80064378: addiu       $t6, $t6, 0x1B00
    ctx->r14 = ADD32(ctx->r14, 0X1B00);
    // 0x8006437C: sll         $t5, $s1, 7
    ctx->r13 = S32(ctx->r17 << 7);
    // 0x80064380: lui         $a1, 0x600
    ctx->r5 = S32(0X600 << 16);
    // 0x80064384: addiu       $a1, $a1, 0x6A20
    ctx->r5 = ADD32(ctx->r5, 0X6A20);
    // 0x80064388: jal         0x80063E5C
    // 0x8006438C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_15;
    // 0x8006438C: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_15:
    // 0x80064390: b           L_800652BC
    // 0x80064394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064394: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064398:
    // 0x80064398: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8006439C: addiu       $t8, $t8, 0x1B00
    ctx->r24 = ADD32(ctx->r24, 0X1B00);
    // 0x800643A0: sll         $t7, $s1, 7
    ctx->r15 = S32(ctx->r17 << 7);
    // 0x800643A4: jal         0x80063CAC
    // 0x800643A8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    Actor_CoRadar_Init(rdram, ctx);
        goto after_16;
    // 0x800643A8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_16:
    // 0x800643AC: b           L_800652BC
    // 0x800643B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800643B0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800643B4:
    // 0x800643B4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800643B8: lw          $t9, 0x7CA0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7CA0);
    // 0x800643BC: sll         $t0, $s1, 3
    ctx->r8 = S32(ctx->r17 << 3);
    // 0x800643C0: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x800643C4: beq         $t9, $zero, L_800652B8
    if (ctx->r25 == 0) {
        // 0x800643C8: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_800652B8;
    }
    // 0x800643C8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800643CC: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x800643D0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800643D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800643D8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x800643DC: b           L_800652B8
    // 0x800643E0: sb          $zero, 0x37E0($at)
    MEM_B(0X37E0, ctx->r1) = 0;
        goto L_800652B8;
    // 0x800643E0: sb          $zero, 0x37E0($at)
    MEM_B(0X37E0, ctx->r1) = 0;
L_800643E4:
    // 0x800643E4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800643E8: lw          $t1, 0x7E80($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7E80);
    // 0x800643EC: sll         $t2, $s1, 3
    ctx->r10 = S32(ctx->r17 << 3);
    // 0x800643F0: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x800643F4: bgez        $t1, L_800652B8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800643F8: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_800652B8;
    }
    // 0x800643F8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800643FC: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064400: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064404: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80064408: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8006440C: b           L_800652B8
    // 0x80064410: sb          $zero, 0x37E0($at)
    MEM_B(0X37E0, ctx->r1) = 0;
        goto L_800652B8;
    // 0x80064410: sb          $zero, 0x37E0($at)
    MEM_B(0X37E0, ctx->r1) = 0;
L_80064414:
    // 0x80064414: sll         $t3, $s1, 3
    ctx->r11 = S32(ctx->r17 << 3);
    // 0x80064418: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x8006441C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80064420: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x80064424: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80064428: addiu       $t4, $t4, 0x37E0
    ctx->r12 = ADD32(ctx->r12, 0X37E0);
    // 0x8006442C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80064430: jal         0x80063F74
    // 0x80064434: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    func_enmy_80063F74(rdram, ctx);
        goto after_17;
    // 0x80064434: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_17:
    // 0x80064438: b           L_800652BC
    // 0x8006443C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x8006443C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064440:
    // 0x80064440: sll         $t5, $s1, 3
    ctx->r13 = S32(ctx->r17 << 3);
    // 0x80064444: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80064448: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8006444C: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80064450: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80064454: addiu       $t6, $t6, 0x37E0
    ctx->r14 = ADD32(ctx->r14, 0X37E0);
    // 0x80064458: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8006445C: jal         0x80063F58
    // 0x80064460: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    func_enmy_80063F58(rdram, ctx);
        goto after_18;
    // 0x80064460: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_18:
    // 0x80064464: b           L_800652BC
    // 0x80064468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064468: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006446C:
    // 0x8006446C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80064470: lw          $t7, 0x7E80($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7E80);
    // 0x80064474: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80064478: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006447C: slti        $at, $t7, 0x7
    ctx->r1 = SIGNED(ctx->r15) < 0X7 ? 1 : 0;
    // 0x80064480: bne         $at, $zero, L_800644A4
    if (ctx->r1 != 0) {
        // 0x80064484: nop
    
            goto L_800644A4;
    }
    // 0x80064484: nop

    // 0x80064488: lw          $t8, -0x7DCC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7DCC);
    // 0x8006448C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80064490: bne         $t8, $zero, L_800644A4
    if (ctx->r24 != 0) {
        // 0x80064494: nop
    
            goto L_800644A4;
    }
    // 0x80064494: nop

    // 0x80064498: lw          $t9, 0x78B4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78B4);
    // 0x8006449C: bgtzl       $t9, L_800644BC
    if (SIGNED(ctx->r25) > 0) {
        // 0x800644A0: sll         $t1, $s1, 3
        ctx->r9 = S32(ctx->r17 << 3);
            goto L_800644BC;
    }
    goto skip_0;
    // 0x800644A0: sll         $t1, $s1, 3
    ctx->r9 = S32(ctx->r17 << 3);
    skip_0:
L_800644A4:
    // 0x800644A4: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x800644A8: sll         $t3, $s1, 3
    ctx->r11 = S32(ctx->r17 << 3);
    // 0x800644AC: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x800644B0: beq         $t0, $zero, L_800644E4
    if (ctx->r8 == 0) {
        // 0x800644B4: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_800644E4;
    }
    // 0x800644B4: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800644B8: sll         $t1, $s1, 3
    ctx->r9 = S32(ctx->r17 << 3);
L_800644BC:
    // 0x800644BC: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x800644C0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800644C4: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x800644C8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800644CC: addiu       $t2, $t2, 0x37E0
    ctx->r10 = ADD32(ctx->r10, 0X37E0);
    // 0x800644D0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800644D4: jal         0x80063F58
    // 0x800644D8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    func_enmy_80063F58(rdram, ctx);
        goto after_19;
    // 0x800644D8: addu        $a0, $t1, $t2
    ctx->r4 = ADD32(ctx->r9, ctx->r10);
    after_19:
    // 0x800644DC: b           L_800652BC
    // 0x800644E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800644E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800644E4:
    // 0x800644E4: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x800644E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800644EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800644F0: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800644F4: b           L_800652B8
    // 0x800644F8: sb          $zero, 0x37E0($at)
    MEM_B(0X37E0, ctx->r1) = 0;
        goto L_800652B8;
    // 0x800644F8: sb          $zero, 0x37E0($at)
    MEM_B(0X37E0, ctx->r1) = 0;
L_800644FC:
    // 0x800644FC: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80064500: addiu       $t5, $t5, 0x1B00
    ctx->r13 = ADD32(ctx->r13, 0X1B00);
    // 0x80064504: sll         $t4, $s1, 7
    ctx->r12 = S32(ctx->r17 << 7);
    // 0x80064508: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006450C: addiu       $a1, $a1, -0x40E8
    ctx->r5 = ADD32(ctx->r5, -0X40E8);
    // 0x80064510: jal         0x80063E5C
    // 0x80064514: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Scenery_CoStoneArch_Init(rdram, ctx);
        goto after_20;
    // 0x80064514: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_20:
L_80064518:
    // 0x80064518: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8006451C: addiu       $t7, $t7, 0x1B00
    ctx->r15 = ADD32(ctx->r15, 0X1B00);
    // 0x80064520: sll         $t6, $s1, 7
    ctx->r14 = S32(ctx->r17 << 7);
    // 0x80064524: jal         0x80063D58
    // 0x80064528: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Scenery_Corneria_Init(rdram, ctx);
        goto after_21;
    // 0x80064528: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_21:
    // 0x8006452C: b           L_800652BC
    // 0x80064530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064530: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064534:
    // 0x80064534: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80064538: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8006453C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80064540: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064544: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064548: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8006454C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80064550: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x80064554: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064558: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x8006455C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80064560: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80064564: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80064568: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006456C: swc1        $f18, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f18.u32l;
    // 0x80064570: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80064574: swc1        $f4, 0x118($s0)
    MEM_W(0X118, ctx->r16) = ctx->f4.u32l;
    // 0x80064578: b           L_800652B8
    // 0x8006457C: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
        goto L_800652B8;
    // 0x8006457C: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
L_80064580:
    // 0x80064580: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80064584: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80064588: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8006458C: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80064590: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80064594: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x80064598: lw          $t2, -0x7CE0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7CE0);
    // 0x8006459C: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x800645A0: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x800645A4: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x800645A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800645AC: addu        $s0, $t0, $t1
    ctx->r16 = ADD32(ctx->r8, ctx->r9);
    // 0x800645B0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800645B4: sh          $t2, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r10;
    // 0x800645B8: lw          $t3, -0x7C28($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C28);
    // 0x800645BC: jal         0x80004EB0
    // 0x800645C0: sh          $t3, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r11;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x800645C0: sh          $t3, 0x48($s0)
    MEM_H(0X48, ctx->r16) = ctx->r11;
    after_22:
    // 0x800645C4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800645C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800645CC: nop

    // 0x800645D0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800645D4: jal         0x80004EB0
    // 0x800645D8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_23;
    // 0x800645D8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    after_23:
    // 0x800645DC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800645E0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800645E4: nop

    // 0x800645E8: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800645EC: b           L_800652B8
    // 0x800645F0: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
        goto L_800652B8;
    // 0x800645F0: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
L_800645F4:
    // 0x800645F4: jal         0x80004EB0
    // 0x800645F8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_24;
    // 0x800645F8: nop

    after_24:
    // 0x800645FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80064600: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80064604: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064608: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x8006460C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80064610: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80064614: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064618: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006461C: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80064620: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80064624: addiu       $t5, $t5, 0x3FE0
    ctx->r13 = ADD32(ctx->r13, 0X3FE0);
    // 0x80064628: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006462C: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80064630: jal         0x80004EB0
    // 0x80064634: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_25;
    // 0x80064634: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    after_25:
    // 0x80064638: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8006463C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80064640: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x80064644: sh          $v1, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r3;
    // 0x80064648: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006464C: b           L_800652B8
    // 0x80064650: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
        goto L_800652B8;
    // 0x80064650: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
L_80064654:
    // 0x80064654: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x80064658: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x8006465C: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80064660: subu        $t7, $t7, $s1
    ctx->r15 = SUB32(ctx->r15, ctx->r17);
    // 0x80064664: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80064668: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x8006466C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80064670: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80064674: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80064678: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x8006467C: b           L_800652B8
    // 0x80064680: sh          $t6, 0x40AE($at)
    MEM_H(0X40AE, ctx->r1) = ctx->r14;
        goto L_800652B8;
    // 0x80064680: sh          $t6, 0x40AE($at)
    MEM_H(0X40AE, ctx->r1) = ctx->r14;
L_80064684:
    // 0x80064684: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80064688: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8006468C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80064690: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064694: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064698: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8006469C: lw          $t0, -0x7D80($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D80);
    // 0x800646A0: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x800646A4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800646A8: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x800646AC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800646B0: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x800646B4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800646B8: lwc1        $f16, 0x7C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X7C);
    // 0x800646BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800646C0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800646C4: nop

    // 0x800646C8: bc1fl       L_800652BC
    if (!c1cs) {
        // 0x800646CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800652BC;
    }
    goto skip_1;
    // 0x800646CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x800646D0: jal         0x80060FBC
    // 0x800646D4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_26;
    // 0x800646D4: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_26:
    // 0x800646D8: b           L_800652BC
    // 0x800646DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800646DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800646E0:
    // 0x800646E0: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x800646E4: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x800646E8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800646EC: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800646F0: addiu       $v1, $v1, -0x7B5C
    ctx->r3 = ADD32(ctx->r3, -0X7B5C);
    // 0x800646F4: subu        $t1, $t1, $s1
    ctx->r9 = SUB32(ctx->r9, ctx->r17);
    // 0x800646F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800646FC: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064700: addu        $t1, $t1, $s1
    ctx->r9 = ADD32(ctx->r9, ctx->r17);
    // 0x80064704: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80064708: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8006470C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80064710: sw          $v0, 0x4030($at)
    MEM_W(0X4030, ctx->r1) = ctx->r2;
    // 0x80064714: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80064718: b           L_800652B8
    // 0x8006471C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
        goto L_800652B8;
    // 0x8006471C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80064720:
    // 0x80064720: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80064724: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x80064728: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8006472C: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x80064730: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80064734: addu        $t3, $t3, $s1
    ctx->r11 = ADD32(ctx->r11, ctx->r17);
    // 0x80064738: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8006473C: addiu       $t4, $t4, 0x3FE0
    ctx->r12 = ADD32(ctx->r12, 0X3FE0);
    // 0x80064740: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80064744: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x80064748: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006474C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80064750: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80064754: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80064758: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8006475C: addiu       $v1, $v1, -0x7B5C
    ctx->r3 = ADD32(ctx->r3, -0X7B5C);
    // 0x80064760: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80064764: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80064768: swc1        $f4, 0xF4($s0)
    MEM_W(0XF4, ctx->r16) = ctx->f4.u32l;
    // 0x8006476C: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80064770: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80064774: swc1        $f6, 0xF8($s0)
    MEM_W(0XF8, ctx->r16) = ctx->f6.u32l;
    // 0x80064778: swc1        $f8, 0x11C($s0)
    MEM_W(0X11C, ctx->r16) = ctx->f8.u32l;
    // 0x8006477C: lw          $v0, -0x7D3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D3C);
    // 0x80064780: addiu       $v1, $zero, 0xC8
    ctx->r3 = ADD32(0, 0XC8);
    // 0x80064784: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80064788:
    // 0x80064788: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006478C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80064790: addiu       $v0, $v0, 0x60
    ctx->r2 = ADD32(ctx->r2, 0X60);
    // 0x80064794: swc1        $f10, -0x60($v0)
    MEM_W(-0X60, ctx->r2) = ctx->f10.u32l;
    // 0x80064798: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006479C: swc1        $f16, -0x5C($v0)
    MEM_W(-0X5C, ctx->r2) = ctx->f16.u32l;
    // 0x800647A0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800647A4: swc1        $f18, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = ctx->f18.u32l;
    // 0x800647A8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800647AC: swc1        $f4, -0x54($v0)
    MEM_W(-0X54, ctx->r2) = ctx->f4.u32l;
    // 0x800647B0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800647B4: swc1        $f6, -0x50($v0)
    MEM_W(-0X50, ctx->r2) = ctx->f6.u32l;
    // 0x800647B8: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800647BC: swc1        $f8, -0x4C($v0)
    MEM_W(-0X4C, ctx->r2) = ctx->f8.u32l;
    // 0x800647C0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800647C4: swc1        $f10, -0x48($v0)
    MEM_W(-0X48, ctx->r2) = ctx->f10.u32l;
    // 0x800647C8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800647CC: swc1        $f16, -0x44($v0)
    MEM_W(-0X44, ctx->r2) = ctx->f16.u32l;
    // 0x800647D0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800647D4: swc1        $f18, -0x40($v0)
    MEM_W(-0X40, ctx->r2) = ctx->f18.u32l;
    // 0x800647D8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800647DC: swc1        $f4, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = ctx->f4.u32l;
    // 0x800647E0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800647E4: swc1        $f6, -0x38($v0)
    MEM_W(-0X38, ctx->r2) = ctx->f6.u32l;
    // 0x800647E8: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800647EC: swc1        $f8, -0x34($v0)
    MEM_W(-0X34, ctx->r2) = ctx->f8.u32l;
    // 0x800647F0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800647F4: swc1        $f10, -0x30($v0)
    MEM_W(-0X30, ctx->r2) = ctx->f10.u32l;
    // 0x800647F8: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800647FC: swc1        $f16, -0x2C($v0)
    MEM_W(-0X2C, ctx->r2) = ctx->f16.u32l;
    // 0x80064800: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80064804: swc1        $f18, -0x28($v0)
    MEM_W(-0X28, ctx->r2) = ctx->f18.u32l;
    // 0x80064808: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006480C: swc1        $f4, -0x24($v0)
    MEM_W(-0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80064810: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80064814: swc1        $f6, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = ctx->f6.u32l;
    // 0x80064818: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006481C: swc1        $f8, -0x1C($v0)
    MEM_W(-0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80064820: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80064824: swc1        $f10, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = ctx->f10.u32l;
    // 0x80064828: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006482C: swc1        $f16, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->f16.u32l;
    // 0x80064830: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80064834: swc1        $f18, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f18.u32l;
    // 0x80064838: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006483C: swc1        $f4, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f4.u32l;
    // 0x80064840: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80064844: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80064848: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006484C: bne         $a0, $v1, L_80064788
    if (ctx->r4 != ctx->r3) {
        // 0x80064850: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80064788;
    }
    // 0x80064850: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80064854: b           L_800652BC
    // 0x80064858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006485C:
    // 0x8006485C: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x80064860: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x80064864: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80064868: subu        $t5, $t5, $s1
    ctx->r13 = SUB32(ctx->r13, ctx->r17);
    // 0x8006486C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80064870: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x80064874: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80064878: addiu       $t6, $t6, 0x3FE0
    ctx->r14 = ADD32(ctx->r14, 0X3FE0);
    // 0x8006487C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80064880: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x80064884: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x80064888: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8006488C: sh          $a3, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r7;
    // 0x80064890: addiu       $a1, $a1, 0x6550
    ctx->r5 = ADD32(ctx->r5, 0X6550);
    // 0x80064894: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80064898: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8006489C:
    // 0x8006489C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800648A0: bne         $t7, $zero, L_80064934
    if (ctx->r15 != 0) {
        // 0x800648A4: sll         $t9, $a0, 2
        ctx->r25 = S32(ctx->r4 << 2);
            goto L_80064934;
    }
    // 0x800648A4: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800648A8: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x800648AC: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x800648B0: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800648B4: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x800648B8: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800648BC: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x800648C0: addu        $t9, $t9, $a0
    ctx->r25 = ADD32(ctx->r25, ctx->r4);
    // 0x800648C4: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800648C8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800648CC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800648D0: addiu       $t2, $t2, 0x6B98
    ctx->r10 = ADD32(ctx->r10, 0X6B98);
    // 0x800648D4: addiu       $t0, $t0, 0x6878
    ctx->r8 = ADD32(ctx->r8, 0X6878);
    // 0x800648D8: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800648DC: sll         $t1, $t1, 4
    ctx->r9 = S32(ctx->r9 << 4);
    // 0x800648E0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800648E4: sh          $a0, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r4;
    // 0x800648E8: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x800648EC: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x800648F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800648F4: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800648F8: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
L_800648FC:
    // 0x800648FC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80064900: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x80064904: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x80064908: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8006490C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    // 0x80064910: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x80064914: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    // 0x80064918: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006491C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80064920: swc1        $f0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80064924: bne         $a2, $a3, L_800648FC
    if (ctx->r6 != ctx->r7) {
        // 0x80064928: swc1        $f2, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->f2.u32l;
            goto L_800648FC;
    }
    // 0x80064928: swc1        $f2, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f2.u32l;
    // 0x8006492C: b           L_80064944
    // 0x80064930: lh          $t3, 0x46($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X46);
        goto L_80064944;
    // 0x80064930: lh          $t3, 0x46($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X46);
L_80064934:
    // 0x80064934: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80064938: bne         $a0, $v0, L_8006489C
    if (ctx->r4 != ctx->r2) {
        // 0x8006493C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8006489C;
    }
    // 0x8006493C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80064940: lh          $t3, 0x46($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X46);
L_80064944:
    // 0x80064944: bnel        $a3, $t3, L_800652BC
    if (ctx->r7 != ctx->r11) {
        // 0x80064948: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800652BC;
    }
    goto skip_2;
    // 0x80064948: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8006494C: b           L_800652B8
    // 0x80064950: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
        goto L_800652B8;
    // 0x80064950: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_80064954:
    // 0x80064954: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064958: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x8006495C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80064960: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064964: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064968: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x8006496C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80064970: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064974: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80064978: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8006497C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80064980: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80064984: addiu       $t6, $t6, 0x3FE0
    ctx->r14 = ADD32(ctx->r14, 0X3FE0);
    // 0x80064988: addiu       $t5, $t4, 0x100
    ctx->r13 = ADD32(ctx->r12, 0X100);
    // 0x8006498C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80064990: ori         $a0, $a0, 0x12
    ctx->r4 = ctx->r4 | 0X12;
    // 0x80064994: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x80064998: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8006499C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800649A0: jal         0x80019218
    // 0x800649A4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_27;
    // 0x800649A4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_27:
    // 0x800649A8: b           L_800652BC
    // 0x800649AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800649AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800649B0:
    // 0x800649B0: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x800649B4: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x800649B8: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x800649BC: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x800649C0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800649C4: addu        $t9, $t9, $s1
    ctx->r25 = ADD32(ctx->r25, ctx->r17);
    // 0x800649C8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800649CC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800649D0: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800649D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800649D8: b           L_800652B8
    // 0x800649DC: sb          $t8, 0x40A9($at)
    MEM_B(0X40A9, ctx->r1) = ctx->r24;
        goto L_800652B8;
    // 0x800649DC: sb          $t8, 0x40A9($at)
    MEM_B(0X40A9, ctx->r1) = ctx->r24;
L_800649E0:
    // 0x800649E0: sll         $t0, $s1, 7
    ctx->r8 = S32(ctx->r17 << 7);
    // 0x800649E4: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x800649E8: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800649EC: addiu       $t1, $t1, -0xEF0
    ctx->r9 = ADD32(ctx->r9, -0XEF0);
    // 0x800649F0: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x800649F4: jal         0x8018D16C
    // 0x800649F8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Andross_AndAndross_Init(rdram, ctx);
        goto after_28;
    // 0x800649F8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_28:
    // 0x800649FC: b           L_800652BC
    // 0x80064A00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064A00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064A04:
    // 0x80064A04: sll         $t2, $s1, 7
    ctx->r10 = S32(ctx->r17 << 7);
    // 0x80064A08: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80064A0C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80064A10: addiu       $t3, $t3, -0xEF0
    ctx->r11 = ADD32(ctx->r11, -0XEF0);
    // 0x80064A14: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80064A18: jal         0x80193CA4
    // 0x80064A1C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Katina_KaSaucerer_Init(rdram, ctx);
        goto after_29;
    // 0x80064A1C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_29:
    // 0x80064A20: b           L_800652BC
    // 0x80064A24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064A24: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064A28:
    // 0x80064A28: sll         $t4, $s1, 7
    ctx->r12 = S32(ctx->r17 << 7);
    // 0x80064A2C: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80064A30: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80064A34: addiu       $t5, $t5, -0xEF0
    ctx->r13 = ADD32(ctx->r13, -0XEF0);
    // 0x80064A38: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80064A3C: jal         0x80197CC4
    // 0x80064A40: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    SectorY_SyShogun_Init(rdram, ctx);
        goto after_30;
    // 0x80064A40: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_30:
    // 0x80064A44: b           L_800652BC
    // 0x80064A48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064A48: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064A4C:
    // 0x80064A4C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80064A50: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064A54: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80064A58: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064A5C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064A60: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80064A64: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80064A68: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x80064A6C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064A70: jal         0x80199F8C
    // 0x80064A74: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Macbeth_Train_Init(rdram, ctx);
        goto after_31;
    // 0x80064A74: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_31:
    // 0x80064A78: b           L_800652BC
    // 0x80064A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064A7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064A80:
    // 0x80064A80: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80064A84: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064A88: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80064A8C: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064A90: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064A94: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80064A98: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80064A9C: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x80064AA0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064AA4: jal         0x801A7D98
    // 0x80064AA8: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Macbeth_MaMechbeth_Init(rdram, ctx);
        goto after_32;
    // 0x80064AA8: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_32:
    // 0x80064AAC: b           L_800652BC
    // 0x80064AB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064AB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064AB4:
    // 0x80064AB4: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80064AB8: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80064ABC: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80064AC0: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80064AC4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80064AC8: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80064ACC: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80064AD0: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x80064AD4: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80064AD8: jal         0x801A3E70
    // 0x80064ADC: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Macbeth_MaMaRailroadSwitch_Init(rdram, ctx);
        goto after_33;
    // 0x80064ADC: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_33:
    // 0x80064AE0: b           L_800652BC
    // 0x80064AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064AE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064AE8:
    // 0x80064AE8: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80064AEC: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064AF0: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80064AF4: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064AF8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064AFC: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80064B00: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80064B04: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x80064B08: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064B0C: jal         0x801A4660
    // 0x80064B10: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Macbeth_MaBoulder_Init(rdram, ctx);
        goto after_34;
    // 0x80064B10: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_34:
    // 0x80064B14: b           L_800652BC
    // 0x80064B18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064B18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064B1C:
    // 0x80064B1C: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064B20: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064B24: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80064B28: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064B2C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064B30: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80064B34: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80064B38: addiu       $t5, $t5, 0x3FE0
    ctx->r13 = ADD32(ctx->r13, 0X3FE0);
    // 0x80064B3C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064B40: jal         0x801A4AF8
    // 0x80064B44: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Macbeth_MaRailwaySignal_Init(rdram, ctx);
        goto after_35;
    // 0x80064B44: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_35:
    // 0x80064B48: b           L_800652BC
    // 0x80064B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064B4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064B50:
    // 0x80064B50: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80064B54: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064B58: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80064B5C: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064B60: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064B64: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80064B68: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80064B6C: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x80064B70: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064B74: jal         0x801A5E2C
    // 0x80064B78: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Macbeth_LockBars_Init(rdram, ctx);
        goto after_36;
    // 0x80064B78: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_36:
    // 0x80064B7C: b           L_800652BC
    // 0x80064B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064B80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064B84:
    // 0x80064B84: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80064B88: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064B8C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80064B90: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064B94: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064B98: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80064B9C: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80064BA0: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x80064BA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064BA8: jal         0x801A6134
    // 0x80064BAC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Macbeth_MaBarrier_Init(rdram, ctx);
        goto after_37;
    // 0x80064BAC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_37:
    // 0x80064BB0: b           L_800652BC
    // 0x80064BB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064BB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064BB8:
    // 0x80064BB8: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80064BBC: addiu       $t1, $t1, 0x1B00
    ctx->r9 = ADD32(ctx->r9, 0X1B00);
    // 0x80064BC0: sll         $t0, $s1, 7
    ctx->r8 = S32(ctx->r17 << 7);
    // 0x80064BC4: jal         0x801A65E0
    // 0x80064BC8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Macbeth_MaProximityLight_Init(rdram, ctx);
        goto after_38;
    // 0x80064BC8: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_38:
    // 0x80064BCC: b           L_800652BC
    // 0x80064BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064BD4:
    // 0x80064BD4: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80064BD8: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064BDC: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80064BE0: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064BE4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064BE8: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80064BEC: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80064BF0: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x80064BF4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064BF8: jal         0x8018B0B4
    // 0x80064BFC: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Corneria_CoIBeam_Init(rdram, ctx);
        goto after_39;
    // 0x80064BFC: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_39:
L_80064C00:
    // 0x80064C00: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064C04: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064C08: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80064C0C: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064C10: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064C14: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80064C18: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80064C1C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80064C20: addiu       $t5, $t5, 0x3FE0
    ctx->r13 = ADD32(ctx->r13, 0X3FE0);
    // 0x80064C24: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064C28: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80064C2C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80064C30: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80064C34: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x80064C38: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80064C3C: lui         $a0, 0x3100
    ctx->r4 = S32(0X3100 << 16);
    // 0x80064C40: sh          $t6, 0xCE($s0)
    MEM_H(0XCE, ctx->r16) = ctx->r14;
    // 0x80064C44: ori         $a0, $a0, 0x16
    ctx->r4 = ctx->r4 | 0X16;
    // 0x80064C48: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80064C4C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80064C50: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80064C54: jal         0x80019218
    // 0x80064C58: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_40;
    // 0x80064C58: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_40:
    // 0x80064C5C: b           L_800652BC
    // 0x80064C60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064C60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064C64:
    // 0x80064C64: sll         $t8, $s1, 7
    ctx->r24 = S32(ctx->r17 << 7);
    // 0x80064C68: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80064C6C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80064C70: addiu       $t9, $t9, -0xEF0
    ctx->r25 = ADD32(ctx->r25, -0XEF0);
    // 0x80064C74: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80064C78: jal         0x80188A40
    // 0x80064C7C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Meteo_MeCrusher_Init(rdram, ctx);
        goto after_41;
    // 0x80064C7C: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_41:
    // 0x80064C80: b           L_800652BC
    // 0x80064C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064C84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064C88:
    // 0x80064C88: sll         $t0, $s1, 7
    ctx->r8 = S32(ctx->r17 << 7);
    // 0x80064C8C: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80064C90: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80064C94: addiu       $t1, $t1, -0xEF0
    ctx->r9 = ADD32(ctx->r9, -0XEF0);
    // 0x80064C98: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80064C9C: jal         0x80042FAC
    // 0x80064CA0: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Boss299_Init(rdram, ctx);
        goto after_42;
    // 0x80064CA0: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_42:
    // 0x80064CA4: b           L_800652BC
    // 0x80064CA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064CA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064CAC:
    // 0x80064CAC: sll         $t2, $s1, 7
    ctx->r10 = S32(ctx->r17 << 7);
    // 0x80064CB0: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80064CB4: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80064CB8: addiu       $t3, $t3, -0xEF0
    ctx->r11 = ADD32(ctx->r11, -0XEF0);
    // 0x80064CBC: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x80064CC0: jal         0x80042FD0
    // 0x80064CC4: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Boss300_Init(rdram, ctx);
        goto after_43;
    // 0x80064CC4: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_43:
    // 0x80064CC8: b           L_800652BC
    // 0x80064CCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064CCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064CD0:
    // 0x80064CD0: sll         $t4, $s1, 7
    ctx->r12 = S32(ctx->r17 << 7);
    // 0x80064CD4: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80064CD8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80064CDC: addiu       $t5, $t5, -0xEF0
    ctx->r13 = ADD32(ctx->r13, -0XEF0);
    // 0x80064CE0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80064CE4: jal         0x801878D8
    // 0x80064CE8: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    LOOKUP_FUNC(0x801878D8)(rdram, ctx);
        goto after_44;
    // 0x80064CE8: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_44:
    // 0x80064CEC: b           L_800652BC
    // 0x80064CF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064CF0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064CF4:
    // 0x80064CF4: sll         $t6, $s1, 7
    ctx->r14 = S32(ctx->r17 << 7);
    // 0x80064CF8: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80064CFC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80064D00: addiu       $t7, $t7, -0xEF0
    ctx->r15 = ADD32(ctx->r15, -0XEF0);
    // 0x80064D04: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80064D08: jal         0x8018BE7C
    // 0x80064D0C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Corneria_CoCarrier_Init(rdram, ctx);
        goto after_45;
    // 0x80064D0C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_45:
    // 0x80064D10: b           L_800652BC
    // 0x80064D14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064D14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064D18:
    // 0x80064D18: sll         $t8, $s1, 7
    ctx->r24 = S32(ctx->r17 << 7);
    // 0x80064D1C: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80064D20: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80064D24: addiu       $t9, $t9, -0xEF0
    ctx->r25 = ADD32(ctx->r25, -0XEF0);
    // 0x80064D28: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80064D2C: jal         0x80187754
    // 0x80064D30: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    LOOKUP_FUNC(0x80187754)(rdram, ctx);
        goto after_46;
    // 0x80064D30: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_46:
    // 0x80064D34: b           L_800652BC
    // 0x80064D38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064D38: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064D3C:
    // 0x80064D3C: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80064D40: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80064D44: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80064D48: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80064D4C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80064D50: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80064D54: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80064D58: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x80064D5C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80064D60: jal         0x8018B96C
    // 0x80064D64: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Titania_TiBomb_Init(rdram, ctx);
        goto after_47;
    // 0x80064D64: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_47:
    // 0x80064D68: b           L_800652BC
    // 0x80064D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064D6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064D70:
    // 0x80064D70: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80064D74: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064D78: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80064D7C: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064D80: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064D84: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80064D88: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80064D8C: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x80064D90: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064D94: jal         0x8018ADC4
    // 0x80064D98: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Titania_TiRasco_Init(rdram, ctx);
        goto after_48;
    // 0x80064D98: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_48:
    // 0x80064D9C: b           L_800652BC
    // 0x80064DA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064DA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064DA4:
    // 0x80064DA4: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064DA8: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064DAC: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80064DB0: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064DB4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064DB8: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80064DBC: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80064DC0: addiu       $t5, $t5, 0x3FE0
    ctx->r13 = ADD32(ctx->r13, 0X3FE0);
    // 0x80064DC4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064DC8: jal         0x80189B80
    // 0x80064DCC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Titania_TiFekuda_Init(rdram, ctx);
        goto after_49;
    // 0x80064DCC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_49:
    // 0x80064DD0: b           L_800652BC
    // 0x80064DD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064DD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064DD8:
    // 0x80064DD8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80064DDC: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064DE0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80064DE4: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064DE8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064DEC: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80064DF0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80064DF4: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x80064DF8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064DFC: jal         0x8018BFB0
    // 0x80064E00: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Titania_TiDesertCrawler_Init(rdram, ctx);
        goto after_50;
    // 0x80064E00: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_50:
    // 0x80064E04: b           L_800652BC
    // 0x80064E08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064E08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064E0C:
    // 0x80064E0C: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80064E10: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064E14: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80064E18: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064E1C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064E20: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80064E24: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80064E28: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x80064E2C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064E30: jal         0x8018E3CC
    // 0x80064E34: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Titania_TiDelphor_Init(rdram, ctx);
        goto after_51;
    // 0x80064E34: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_51:
    // 0x80064E38: b           L_800652BC
    // 0x80064E3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064E3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064E40:
    // 0x80064E40: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80064E44: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80064E48: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80064E4C: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80064E50: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80064E54: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80064E58: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80064E5C: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x80064E60: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80064E64: jal         0x8018E5E8
    // 0x80064E68: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Titania_TiDelphorHead_Init(rdram, ctx);
        goto after_52;
    // 0x80064E68: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_52:
    // 0x80064E6C: b           L_800652BC
    // 0x80064E70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064E70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064E74:
    // 0x80064E74: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80064E78: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80064E7C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064E80: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064E84: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80064E88: addiu       $t3, $t3, 0x3400
    ctx->r11 = ADD32(ctx->r11, 0X3400);
    // 0x80064E8C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064E90: jal         0x8018EFF0
    // 0x80064E94: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Titania_TiCactus_Init(rdram, ctx);
        goto after_53;
    // 0x80064E94: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_53:
    // 0x80064E98: b           L_800652BC
    // 0x80064E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064E9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064EA0:
    // 0x80064EA0: sll         $t4, $s1, 7
    ctx->r12 = S32(ctx->r17 << 7);
    // 0x80064EA4: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80064EA8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80064EAC: addiu       $t5, $t5, -0xEF0
    ctx->r13 = ADD32(ctx->r13, -0XEF0);
    // 0x80064EB0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80064EB4: jal         0x8018FA48
    // 0x80064EB8: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Titania_TiGoras_Init(rdram, ctx);
        goto after_54;
    // 0x80064EB8: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_54:
    // 0x80064EBC: b           L_800652BC
    // 0x80064EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064EC0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064EC4:
    // 0x80064EC4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80064EC8: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064ECC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80064ED0: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064ED4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064ED8: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80064EDC: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80064EE0: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x80064EE4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064EE8: jal         0x801915A4
    // 0x80064EEC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Zoness_ZoEnergyBall_Init(rdram, ctx);
        goto after_55;
    // 0x80064EEC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_55:
    // 0x80064EF0: b           L_800652BC
    // 0x80064EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064EF4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064EF8:
    // 0x80064EF8: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80064EFC: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064F00: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80064F04: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064F08: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064F0C: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80064F10: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80064F14: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x80064F18: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80064F1C: jal         0x80191BB8
    // 0x80064F20: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Zoness_ZoEnergyBall_Init2(rdram, ctx);
        goto after_56;
    // 0x80064F20: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_56:
    // 0x80064F24: b           L_800652BC
    // 0x80064F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064F28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064F2C:
    // 0x80064F2C: sll         $t0, $s1, 7
    ctx->r8 = S32(ctx->r17 << 7);
    // 0x80064F30: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80064F34: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80064F38: addiu       $t1, $t1, -0xEF0
    ctx->r9 = ADD32(ctx->r9, -0XEF0);
    // 0x80064F3C: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x80064F40: jal         0x801932AC
    // 0x80064F44: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Zoness_ZoSarumarine_Init(rdram, ctx);
        goto after_57;
    // 0x80064F44: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_57:
    // 0x80064F48: b           L_800652BC
    // 0x80064F4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064F4C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064F50:
    // 0x80064F50: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80064F54: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064F58: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80064F5C: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80064F60: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064F64: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x80064F68: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80064F6C: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x80064F70: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80064F74: jal         0x8019B1F0
    // 0x80064F78: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Zoness_ZoTanker_Init(rdram, ctx);
        goto after_58;
    // 0x80064F78: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_58:
    // 0x80064F7C: b           L_800652BC
    // 0x80064F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064F80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064F84:
    // 0x80064F84: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x80064F88: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064F8C: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80064F90: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80064F94: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064F98: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80064F9C: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80064FA0: addiu       $t5, $t5, 0x3FE0
    ctx->r13 = ADD32(ctx->r13, 0X3FE0);
    // 0x80064FA4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80064FA8: jal         0x8019B810
    // 0x80064FAC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Zoness_ZoContainer_Init(rdram, ctx);
        goto after_59;
    // 0x80064FAC: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_59:
    // 0x80064FB0: b           L_800652BC
    // 0x80064FB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064FB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064FB8:
    // 0x80064FB8: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80064FBC: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064FC0: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80064FC4: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80064FC8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064FCC: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x80064FD0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x80064FD4: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x80064FD8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80064FDC: jal         0x8019C200
    // 0x80064FE0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Zoness_ZoSupplyCrane_Init(rdram, ctx);
        goto after_60;
    // 0x80064FE0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_60:
    // 0x80064FE4: b           L_800652BC
    // 0x80064FE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80064FE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80064FEC:
    // 0x80064FEC: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80064FF0: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064FF4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80064FF8: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x80064FFC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80065000: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80065004: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x80065008: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x8006500C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80065010: jal         0x801AD688
    // 0x80065014: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Aquas_AqSanada_Init(rdram, ctx);
        goto after_61;
    // 0x80065014: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_61:
    // 0x80065018: b           L_800652BC
    // 0x8006501C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x8006501C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065020:
    // 0x80065020: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80065024: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80065028: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8006502C: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80065030: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80065034: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80065038: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8006503C: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x80065040: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80065044: jal         0x801AE3AC
    // 0x80065048: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Aquas_AqBacoonMuscle_Init(rdram, ctx);
        goto after_62;
    // 0x80065048: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_62:
    // 0x8006504C: b           L_800652BC
    // 0x80065050: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065050: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065054:
    // 0x80065054: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80065058: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x8006505C: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80065060: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80065064: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80065068: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x8006506C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80065070: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x80065074: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80065078: jal         0x801AF9FC
    // 0x8006507C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Aquas_AqBacconBarnacle_Init(rdram, ctx);
        goto after_63;
    // 0x8006507C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_63:
    // 0x80065080: b           L_800652BC
    // 0x80065084: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065084: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065088:
    // 0x80065088: sll         $t4, $s1, 7
    ctx->r12 = S32(ctx->r17 << 7);
    // 0x8006508C: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80065090: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80065094: addiu       $t5, $t5, -0xEF0
    ctx->r13 = ADD32(ctx->r13, -0XEF0);
    // 0x80065098: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8006509C: jal         0x801B10F8
    // 0x800650A0: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Aquas_AqBacoon_Init(rdram, ctx);
        goto after_64;
    // 0x800650A0: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_64:
    // 0x800650A4: b           L_800652BC
    // 0x800650A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800650A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800650AC:
    // 0x800650AC: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800650B0: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800650B4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800650B8: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800650BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800650C0: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x800650C4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800650C8: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x800650CC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800650D0: jal         0x801B6344
    // 0x800650D4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Aquas_AqAnglerFish_Init(rdram, ctx);
        goto after_65;
    // 0x800650D4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_65:
    // 0x800650D8: b           L_800652BC
    // 0x800650DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800650DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800650E0:
    // 0x800650E0: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800650E4: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x800650E8: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800650EC: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x800650F0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800650F4: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x800650F8: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800650FC: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x80065100: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80065104: jal         0x801B6E54
    // 0x80065108: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Aquas_AqSpindlyFish_Init(rdram, ctx);
        goto after_66;
    // 0x80065108: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_66:
    // 0x8006510C: b           L_800652BC
    // 0x80065110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065110: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065114:
    // 0x80065114: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80065118: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x8006511C: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x80065120: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80065124: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80065128: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x8006512C: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x80065130: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x80065134: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80065138: jal         0x801B7AF0
    // 0x8006513C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Aquas_AqGaroa_Init(rdram, ctx);
        goto after_67;
    // 0x8006513C: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_67:
    // 0x80065140: b           L_800652BC
    // 0x80065144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065148:
    // 0x80065148: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8006514C: addiu       $t3, $t3, 0x1B00
    ctx->r11 = ADD32(ctx->r11, 0X1B00);
    // 0x80065150: sll         $t2, $s1, 7
    ctx->r10 = S32(ctx->r17 << 7);
    // 0x80065154: jal         0x8018F0D8
    // 0x80065158: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Titania_TiPillar_Init(rdram, ctx);
        goto after_68;
    // 0x80065158: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_68:
    // 0x8006515C: b           L_800652BC
    // 0x80065160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065160: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065164:
    // 0x80065164: sll         $t4, $s1, 7
    ctx->r12 = S32(ctx->r17 << 7);
    // 0x80065168: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x8006516C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x80065170: addiu       $t5, $t5, -0xEF0
    ctx->r13 = ADD32(ctx->r13, -0XEF0);
    // 0x80065174: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80065178: jal         0x801935CC
    // 0x8006517C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Venom1_Ve1Golemech_Init(rdram, ctx);
        goto after_69;
    // 0x8006517C: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_69:
    // 0x80065180: b           L_800652BC
    // 0x80065184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065184: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065188:
    // 0x80065188: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8006518C: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80065190: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80065194: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80065198: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006519C: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x800651A0: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800651A4: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x800651A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800651AC: jal         0x8019250C
    // 0x800651B0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Venom1_Ve1Pillar1_Init(rdram, ctx);
        goto after_70;
    // 0x800651B0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_70:
    // 0x800651B4: b           L_800652BC
    // 0x800651B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800651B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800651BC:
    // 0x800651BC: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800651C0: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x800651C4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x800651C8: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x800651CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800651D0: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x800651D4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x800651D8: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x800651DC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800651E0: jal         0x80192CB0
    // 0x800651E4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    Venom1_Ve1Pillar2_3_Init(rdram, ctx);
        goto after_71;
    // 0x800651E4: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_71:
    // 0x800651E8: b           L_800652BC
    // 0x800651EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x800651EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800651F0:
    // 0x800651F0: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x800651F4: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x800651F8: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x800651FC: subu        $t0, $t0, $s1
    ctx->r8 = SUB32(ctx->r8, ctx->r17);
    // 0x80065200: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80065204: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x80065208: lui         $t1, 0x8016
    ctx->r9 = S32(0X8016 << 16);
    // 0x8006520C: addiu       $t1, $t1, 0x3FE0
    ctx->r9 = ADD32(ctx->r9, 0X3FE0);
    // 0x80065210: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80065214: jal         0x80192EA4
    // 0x80065218: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Venom1_Ve1Pillar4_Init(rdram, ctx);
        goto after_72;
    // 0x80065218: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_72:
    // 0x8006521C: b           L_800652BC
    // 0x80065220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065220: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065224:
    // 0x80065224: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x80065228: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x8006522C: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x80065230: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x80065234: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80065238: addu        $t2, $t2, $s1
    ctx->r10 = ADD32(ctx->r10, ctx->r17);
    // 0x8006523C: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x80065240: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x80065244: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80065248: jal         0x801933B4
    // 0x8006524C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    Venom1_Ve1MonkeyStatue_Init(rdram, ctx);
        goto after_73;
    // 0x8006524C: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    after_73:
    // 0x80065250: b           L_800652BC
    // 0x80065254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065254: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80065258:
    // 0x80065258: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8006525C: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80065260: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x80065264: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80065268: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006526C: addu        $t4, $t4, $s1
    ctx->r12 = ADD32(ctx->r12, ctx->r17);
    // 0x80065270: lui         $t5, 0x8016
    ctx->r13 = S32(0X8016 << 16);
    // 0x80065274: addiu       $t5, $t5, 0x3FE0
    ctx->r13 = ADD32(ctx->r13, 0X3FE0);
    // 0x80065278: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8006527C: jal         0x801BA57C
    // 0x80065280: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    Aquas_AqBoulder_Init(rdram, ctx);
        goto after_74;
    // 0x80065280: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_74:
    // 0x80065284: b           L_800652BC
    // 0x80065288: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800652BC;
    // 0x80065288: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006528C:
    // 0x8006528C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80065290: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80065294: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80065298: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x8006529C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800652A0: addu        $t6, $t6, $s1
    ctx->r14 = ADD32(ctx->r14, ctx->r17);
    // 0x800652A4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x800652A8: addiu       $t7, $t7, 0x3FE0
    ctx->r15 = ADD32(ctx->r15, 0X3FE0);
    // 0x800652AC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800652B0: jal         0x801BB26C
    // 0x800652B4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    Aquas_AqJellyfish_Init(rdram, ctx);
        goto after_75;
    // 0x800652B4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_75:
L_800652B8:
    // 0x800652B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800652BC:
    // 0x800652BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800652C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800652C4: jr          $ra
    // 0x800652C8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800652C8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ActorEvent_SlowDestruct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071DC0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80071DC4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80071DC8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80071DCC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80071DD0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071DD4: lwc1        $f6, 0x6D68($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D68);
    // 0x80071DD8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80071DDC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80071DE0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80071DE4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80071DE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80071DEC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80071DF0: jal         0x80005E90
    // 0x80071DF4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80071DF4: nop

    after_0:
    // 0x80071DF8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071DFC: lwc1        $f16, 0x6D6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6D6C);
    // 0x80071E00: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80071E04: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80071E08: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80071E0C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80071E10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80071E14: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80071E18: jal         0x80005D44
    // 0x80071E1C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x80071E1C: nop

    after_1:
    // 0x80071E20: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071E24: lwc1        $f6, 0x6D70($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D70);
    // 0x80071E28: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80071E2C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80071E30: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80071E34: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80071E38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80071E3C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80071E40: jal         0x80005FE0
    // 0x80071E44: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_2;
    // 0x80071E44: nop

    after_2:
    // 0x80071E48: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80071E4C: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x80071E50: bnel        $v0, $at, L_80071EA8
    if (ctx->r2 != ctx->r1) {
        // 0x80071E54: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_80071EA8;
    }
    goto skip_0;
    // 0x80071E54: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    skip_0:
    // 0x80071E58: jal         0x80004EB0
    // 0x80071E5C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80071E5C: nop

    after_3:
    // 0x80071E60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071E64: lwc1        $f10, 0x6D74($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D74);
    // 0x80071E68: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x80071E6C: addiu       $t9, $t9, 0x1074
    ctx->r25 = ADD32(ctx->r25, 0X1074);
    // 0x80071E70: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80071E74: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80071E78: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80071E7C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80071E80: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80071E84: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80071E88: nop

    // 0x80071E8C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80071E90: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80071E94: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80071E98: jal         0x80006A20
    // 0x80071E9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_4;
    // 0x80071E9C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x80071EA0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80071EA4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
L_80071EA8:
    // 0x80071EA8: bnel        $v0, $at, L_80071F00
    if (ctx->r2 != ctx->r1) {
        // 0x80071EAC: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80071F00;
    }
    goto skip_1;
    // 0x80071EAC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    skip_1:
    // 0x80071EB0: jal         0x80004EB0
    // 0x80071EB4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x80071EB4: nop

    after_5:
    // 0x80071EB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071EBC: lwc1        $f4, 0x6D78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6D78);
    // 0x80071EC0: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80071EC4: addiu       $t3, $t3, 0xDD4
    ctx->r11 = ADD32(ctx->r11, 0XDD4);
    // 0x80071EC8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80071ECC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80071ED0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80071ED4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80071ED8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80071EDC: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80071EE0: nop

    // 0x80071EE4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80071EE8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80071EEC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80071EF0: jal         0x80006A20
    // 0x80071EF4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_6;
    // 0x80071EF4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x80071EF8: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    // 0x80071EFC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
L_80071F00:
    // 0x80071F00: bne         $v0, $at, L_80071F50
    if (ctx->r2 != ctx->r1) {
        // 0x80071F04: nop
    
            goto L_80071F50;
    }
    // 0x80071F04: nop

    // 0x80071F08: jal         0x80004EB0
    // 0x80071F0C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80071F0C: nop

    after_7:
    // 0x80071F10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071F14: lwc1        $f10, 0x6D7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D7C);
    // 0x80071F18: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80071F1C: addiu       $t7, $t7, 0x1194
    ctx->r15 = ADD32(ctx->r15, 0X1194);
    // 0x80071F20: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80071F24: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80071F28: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80071F2C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80071F30: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80071F34: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x80071F38: nop

    // 0x80071F3C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80071F40: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x80071F44: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80071F48: jal         0x80006A20
    // 0x80071F4C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x80071F4C: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_8:
L_80071F50:
    // 0x80071F50: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80071F54: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x80071F58: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80071F5C: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80071F60: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80071F64: bne         $t8, $zero, L_80071FBC
    if (ctx->r24 != 0) {
        // 0x80071F68: lwc1        $f18, 0x40($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
            goto L_80071FBC;
    }
    // 0x80071F68: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80071F6C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80071F70: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80071F74: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80071F78: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80071F7C: lwc1        $f6, 0xEC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80071F80: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x80071F84: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80071F88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80071F8C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80071F90: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80071F94: lwc1        $f10, 0x6D80($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D80);
    // 0x80071F98: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80071F9C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80071FA0: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80071FA4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80071FA8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x80071FAC: jal         0x8007C120
    // 0x80071FB0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_9;
    // 0x80071FB0: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x80071FB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80071FB8: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
L_80071FBC:
    // 0x80071FBC: andi        $t0, $v0, 0x7
    ctx->r8 = ctx->r2 & 0X7;
    // 0x80071FC0: bne         $t0, $zero, L_80072020
    if (ctx->r8 != 0) {
        // 0x80071FC4: lwc1        $f18, 0x38($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
            goto L_80072020;
    }
    // 0x80071FC4: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80071FC8: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80071FCC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80071FD0: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80071FD4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80071FD8: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80071FDC: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80071FE0: lwc1        $f18, 0xEC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80071FE4: lw          $a3, 0xE8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XE8);
    // 0x80071FE8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80071FEC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80071FF0: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80071FF4: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80071FF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80071FFC: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80072000: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80072004: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80072008: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8007200C: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80072010: jal         0x8007BFFC
    // 0x80072014: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_10;
    // 0x80072014: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80072018: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007201C: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
L_80072020:
    // 0x80072020: andi        $t2, $v0, 0xF
    ctx->r10 = ctx->r2 & 0XF;
    // 0x80072024: bne         $t2, $zero, L_80072054
    if (ctx->r10 != 0) {
        // 0x80072028: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80072054;
    }
    // 0x80072028: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007202C: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80072030: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80072034: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80072038: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8007203C: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x80072040: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80072044: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80072048: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x8007204C: jal         0x80019218
    // 0x80072050: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_11;
    // 0x80072050: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
L_80072054:
    // 0x80072054: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072058: lwc1        $f10, 0x6D84($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6D84);
    // 0x8007205C: lwc1        $f8, 0xEC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x80072060: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80072064: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072068: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8007206C: swc1        $f18, 0xF0($s0)
    MEM_W(0XF0, ctx->r16) = ctx->f18.u32l;
    // 0x80072070: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80072074: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80072078: swc1        $f16, 0xEC($s0)
    MEM_W(0XEC, ctx->r16) = ctx->f16.u32l;
    // 0x8007207C: lwc1        $f6, 0x6D88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6D88);
    // 0x80072080: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80072084: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80072088: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8007208C: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80072090: lwc1        $f16, 0x6D8C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6D8C);
    // 0x80072094: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80072098: swc1        $f18, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f18.u32l;
    // 0x8007209C: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x800720A0: andi        $t5, $t4, 0x7
    ctx->r13 = ctx->r12 & 0X7;
    // 0x800720A4: bnel        $t5, $zero, L_800720D8
    if (ctx->r13 != 0) {
        // 0x800720A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800720D8;
    }
    goto skip_2;
    // 0x800720A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x800720AC: jal         0x80004EB0
    // 0x800720B0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_12;
    // 0x800720B0: nop

    after_12:
    // 0x800720B4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800720B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800720BC: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x800720C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800720C4: nop

    // 0x800720C8: bc1fl       L_800720D8
    if (!c1cs) {
        // 0x800720CC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800720D8;
    }
    goto skip_3;
    // 0x800720CC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x800720D0: sh          $t6, 0xC6($s0)
    MEM_H(0XC6, ctx->r16) = ctx->r14;
    // 0x800720D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800720D8:
    // 0x800720D8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800720DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800720E0: jr          $ra
    // 0x800720E4: nop

    return;
    // 0x800720E4: nop

;}
RECOMP_FUNC void Player_ArwingBrake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2C00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B2C04: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800B2C08: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B2C0C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B2C10: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800B2C14: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B2C18: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x800B2C1C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B2C20: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800B2C24: bne         $t6, $zero, L_800B2C44
    if (ctx->r14 != 0) {
        // 0x800B2C28: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_800B2C44;
    }
    // 0x800B2C28: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B2C2C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B2C30: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B2C34: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B2C38: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800B2C3C: b           L_800B2C58
    // 0x800B2C40: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
        goto L_800B2C58;
    // 0x800B2C40: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
L_800B2C44:
    // 0x800B2C44: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B2C48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B2C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2C50: lwc1        $f2, -0x766C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X766C);
    // 0x800B2C54: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
L_800B2C58:
    // 0x800B2C58: sb          $zero, 0x485($s0)
    MEM_B(0X485, ctx->r16) = 0;
    // 0x800B2C5C: lw          $a0, 0x78A0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78A0);
    // 0x800B2C60: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B2C64: addiu       $t9, $t9, 0x7A00
    ctx->r25 = ADD32(ctx->r25, 0X7A00);
    // 0x800B2C68: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800B2C6C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x800B2C70: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B2C74: lw          $t7, 0x797C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X797C);
    // 0x800B2C78: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800B2C7C: beq         $v0, $zero, L_800B2C8C
    if (ctx->r2 == 0) {
        // 0x800B2C80: lb          $a2, 0x3($t7)
        ctx->r6 = MEM_B(ctx->r15, 0X3);
            goto L_800B2C8C;
    }
    // 0x800B2C80: lb          $a2, 0x3($t7)
    ctx->r6 = MEM_B(ctx->r15, 0X3);
    // 0x800B2C84: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x800B2C88: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
L_800B2C8C:
    // 0x800B2C8C: addiu       $t1, $t1, 0x7A38
    ctx->r9 = ADD32(ctx->r9, 0X7A38);
    // 0x800B2C90: addu        $v1, $a0, $t1
    ctx->r3 = ADD32(ctx->r4, ctx->r9);
    // 0x800B2C94: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B2C98: slti        $at, $a2, -0x32
    ctx->r1 = SIGNED(ctx->r6) < -0X32 ? 1 : 0;
    // 0x800B2C9C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B2CA0: beq         $v0, $zero, L_800B2CAC
    if (ctx->r2 == 0) {
        // 0x800B2CA4: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800B2CAC;
    }
    // 0x800B2CA4: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800B2CA8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_800B2CAC:
    // 0x800B2CAC: bne         $at, $zero, L_800B2CB8
    if (ctx->r1 != 0) {
        // 0x800B2CB0: addiu       $a3, $zero, 0x5
        ctx->r7 = ADD32(0, 0X5);
            goto L_800B2CB8;
    }
    // 0x800B2CB0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800B2CB4: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
L_800B2CB8:
    // 0x800B2CB8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B2CBC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800B2CC0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B2CC4: blez        $v0, L_800B2D48
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2CC8: slti        $at, $v0, 0x5
        ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
            goto L_800B2D48;
    }
    // 0x800B2CC8: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800B2CCC: beq         $at, $zero, L_800B2D48
    if (ctx->r1 == 0) {
        // 0x800B2CD0: lui         $t3, 0x8017
        ctx->r11 = S32(0X8017 << 16);
            goto L_800B2D48;
    }
    // 0x800B2CD0: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B2CD4: lbu         $t3, 0x7AB0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7AB0);
    // 0x800B2CD8: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x800B2CDC: beql        $at, $zero, L_800B2D4C
    if (ctx->r1 == 0) {
        // 0x800B2CE0: lw          $a2, 0x1C4($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X1C4);
            goto L_800B2D4C;
    }
    goto skip_0;
    // 0x800B2CE0: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    skip_0:
    // 0x800B2CE4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800B2CE8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B2CEC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800B2CF0: beq         $t4, $zero, L_800B2D48
    if (ctx->r12 == 0) {
        // 0x800B2CF4: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_800B2D48;
    }
    // 0x800B2CF4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B2CF8: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800B2CFC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B2D00: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B2D04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B2D08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B2D0C: sw          $a3, 0x1C8($s0)
    MEM_W(0X1C8, ctx->r16) = ctx->r7;
    // 0x800B2D10: sw          $zero, 0x1D0($s0)
    MEM_W(0X1D0, ctx->r16) = 0;
    // 0x800B2D14: sw          $t5, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = ctx->r13;
    // 0x800B2D18: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x800B2D1C: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x800B2D20: swc1        $f8, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f8.u32l;
    // 0x800B2D24: swc1        $f10, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f10.u32l;
    // 0x800B2D28: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800B2D2C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800B2D30: addiu       $v0, $v0, 0x7B6C
    ctx->r2 = ADD32(ctx->r2, 0X7B6C);
    // 0x800B2D34: bnel        $t6, $zero, L_800B2D4C
    if (ctx->r14 != 0) {
        // 0x800B2D38: lw          $a2, 0x1C4($s0)
        ctx->r6 = MEM_W(ctx->r16, 0X1C4);
            goto L_800B2D4C;
    }
    goto skip_1;
    // 0x800B2D38: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    skip_1:
    // 0x800B2D3C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800B2D40: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800B2D44: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_800B2D48:
    // 0x800B2D48: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
L_800B2D4C:
    // 0x800B2D4C: lw          $t9, 0x7974($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7974);
    // 0x800B2D50: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B2D54: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800B2D58: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800B2D5C: lhu         $t0, 0x7928($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X7928);
    // 0x800B2D60: lhu         $v1, 0x0($t9)
    ctx->r3 = MEM_HU(ctx->r25, 0X0);
    // 0x800B2D64: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B2D68: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800B2D6C: and         $t1, $t0, $v1
    ctx->r9 = ctx->r8 & ctx->r3;
    // 0x800B2D70: beql        $t1, $zero, L_800B2F6C
    if (ctx->r9 == 0) {
        // 0x800B2D74: lwc1        $f0, 0x2BC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
            goto L_800B2F6C;
    }
    goto skip_2;
    // 0x800B2D74: lwc1        $f0, 0x2BC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
    skip_2:
    // 0x800B2D78: lhu         $t2, 0x7908($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X7908);
    // 0x800B2D7C: and         $t3, $t2, $v1
    ctx->r11 = ctx->r10 & ctx->r3;
    // 0x800B2D80: bnel        $t3, $zero, L_800B2F6C
    if (ctx->r11 != 0) {
        // 0x800B2D84: lwc1        $f0, 0x2BC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
            goto L_800B2F6C;
    }
    goto skip_3;
    // 0x800B2D84: lwc1        $f0, 0x2BC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
    skip_3:
    // 0x800B2D88: lw          $t4, 0x1C8($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B2D8C: beql        $a3, $t4, L_800B2F6C
    if (ctx->r7 == ctx->r12) {
        // 0x800B2D90: lwc1        $f0, 0x2BC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
            goto L_800B2F6C;
    }
    goto skip_4;
    // 0x800B2D90: lwc1        $f0, 0x2BC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
    skip_4:
    // 0x800B2D94: lw          $t5, 0x2B4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X2B4);
    // 0x800B2D98: bnel        $t5, $zero, L_800B2F6C
    if (ctx->r13 != 0) {
        // 0x800B2D9C: lwc1        $f0, 0x2BC($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
            goto L_800B2F6C;
    }
    goto skip_5;
    // 0x800B2D9C: lwc1        $f0, 0x2BC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
    skip_5:
    // 0x800B2DA0: lwc1        $f16, 0x2BC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B2DA4: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800B2DA8: lui         $a1, 0x900
    ctx->r5 = S32(0X900 << 16);
    // 0x800B2DAC: c.eq.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl == ctx->f16.fl;
    // 0x800B2DB0: nop

    // 0x800B2DB4: bc1f        L_800B2E1C
    if (!c1cs) {
        // 0x800B2DB8: nop
    
            goto L_800B2E1C;
    }
    // 0x800B2DB8: nop

    // 0x800B2DBC: jal         0x800A5FA0
    // 0x800B2DC0: ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    Player_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800B2DC0: ori         $a1, $a1, 0x3
    ctx->r5 = ctx->r5 | 0X3;
    after_0:
    // 0x800B2DC4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800B2DC8: lw          $t6, 0x7880($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7880);
    // 0x800B2DCC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B2DD0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x800B2DD4: bne         $t6, $at, L_800B2E1C
    if (ctx->r14 != ctx->r1) {
        // 0x800B2DD8: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_800B2E1C;
    }
    // 0x800B2DD8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B2DDC: lw          $t7, 0x1C4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B2DE0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800B2DE4: lw          $t0, 0x797C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X797C);
    // 0x800B2DE8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800B2DEC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800B2DF0: lhu         $t9, 0x7928($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X7928);
    // 0x800B2DF4: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x800B2DF8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B2DFC: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x800B2E00: beq         $t2, $zero, L_800B2E1C
    if (ctx->r10 == 0) {
        // 0x800B2E04: nop
    
            goto L_800B2E1C;
    }
    // 0x800B2E04: nop

    // 0x800B2E08: lw          $t3, 0x78A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A0);
    // 0x800B2E0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800B2E10: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B2E14: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800B2E18: sw          $a3, 0x7A38($at)
    MEM_W(0X7A38, ctx->r1) = ctx->r7;
L_800B2E1C:
    // 0x800B2E1C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B2E20: lbu         $t5, 0x7C98($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7C98);
    // 0x800B2E24: addiu       $a0, $s0, 0x4A0
    ctx->r4 = ADD32(ctx->r16, 0X4A0);
    // 0x800B2E28: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800B2E2C: bne         $t5, $zero, L_800B2E98
    if (ctx->r13 != 0) {
        // 0x800B2E30: lui         $a2, 0x3E4C
        ctx->r6 = S32(0X3E4C << 16);
            goto L_800B2E98;
    }
    // 0x800B2E30: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B2E34: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B2E38: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B2E3C: jal         0x8009BC2C
    // 0x800B2E40: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800B2E40: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x800B2E44: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B2E48: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B2E4C: addiu       $a0, $s0, 0x4A4
    ctx->r4 = ADD32(ctx->r16, 0X4A4);
    // 0x800B2E50: lui         $a1, 0xC2B4
    ctx->r5 = S32(0XC2B4 << 16);
    // 0x800B2E54: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B2E58: jal         0x8009BC2C
    // 0x800B2E5C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800B2E5C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x800B2E60: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B2E64: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B2E68: addiu       $a0, $s0, 0x4A8
    ctx->r4 = ADD32(ctx->r16, 0X4A8);
    // 0x800B2E6C: lui         $a1, 0x42B4
    ctx->r5 = S32(0X42B4 << 16);
    // 0x800B2E70: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B2E74: jal         0x8009BC2C
    // 0x800B2E78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x800B2E78: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_3:
    // 0x800B2E7C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B2E80: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B2E84: addiu       $a0, $s0, 0x4AC
    ctx->r4 = ADD32(ctx->r16, 0X4AC);
    // 0x800B2E88: lui         $a1, 0xC2B4
    ctx->r5 = S32(0XC2B4 << 16);
    // 0x800B2E8C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x800B2E90: jal         0x8009BC2C
    // 0x800B2E94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x800B2E94: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_4:
L_800B2E98:
    // 0x800B2E98: lwc1        $f18, 0x2BC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B2E9C: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B2EA0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800B2EA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B2EA8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B2EAC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B2EB0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x800B2EB4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B2EB8: swc1        $f6, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f6.u32l;
    // 0x800B2EBC: lwc1        $f10, 0x2BC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B2EC0: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x800B2EC4: lui         $a1, 0x4334
    ctx->r5 = S32(0X4334 << 16);
    // 0x800B2EC8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800B2ECC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B2ED0: bc1fl       L_800B2EEC
    if (!c1cs) {
        // 0x800B2ED4: lui         $at, 0xC1A0
        ctx->r1 = S32(0XC1A0 << 16);
            goto L_800B2EEC;
    }
    goto skip_6;
    // 0x800B2ED4: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    skip_6:
    // 0x800B2ED8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B2EDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B2EE0: sw          $t6, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r14;
    // 0x800B2EE4: swc1        $f16, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f16.u32l;
    // 0x800B2EE8: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
L_800B2EEC:
    // 0x800B2EEC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B2EF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2EF4: lwc1        $f18, -0x7668($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7668);
    // 0x800B2EF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B2EFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B2F00: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800B2F04: swc1        $f18, 0x190($s0)
    MEM_W(0X190, ctx->r16) = ctx->f18.u32l;
    // 0x800B2F08: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B2F0C: swc1        $f8, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f8.u32l;
    // 0x800B2F10: lwc1        $f10, 0x110($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800B2F14: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800B2F18: nop

    // 0x800B2F1C: bc1f        L_800B2F28
    if (!c1cs) {
        // 0x800B2F20: nop
    
            goto L_800B2F28;
    }
    // 0x800B2F20: nop

    // 0x800B2F24: swc1        $f0, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f0.u32l;
L_800B2F28:
    // 0x800B2F28: jal         0x8009BC2C
    // 0x800B2F2C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B2F2C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x800B2F30: lw          $t8, 0x1C4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B2F34: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B2F38: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B2F3C: sb          $t7, 0x485($s0)
    MEM_B(0X485, ctx->r16) = ctx->r15;
    // 0x800B2F40: addiu       $t9, $t9, 0x79A8
    ctx->r25 = ADD32(ctx->r25, 0X79A8);
    // 0x800B2F44: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800B2F48: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    // 0x800B2F4C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800B2F50: lui         $a1, 0x41C8
    ctx->r5 = S32(0X41C8 << 16);
    // 0x800B2F54: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B2F58: jal         0x8009BC2C
    // 0x800B2F5C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B2F5C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_6:
    // 0x800B2F60: b           L_800B2FE4
    // 0x800B2F64: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
        goto L_800B2FE4;
    // 0x800B2F64: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800B2F68: lwc1        $f0, 0x2BC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2BC);
L_800B2F6C:
    // 0x800B2F6C: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800B2F70: nop

    // 0x800B2F74: bc1fl       L_800B2FE4
    if (!c1cs) {
        // 0x800B2F78: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_800B2FE4;
    }
    goto skip_7;
    // 0x800B2F78: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_7:
    // 0x800B2F7C: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800B2F80: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B2F84: swc1        $f16, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f16.u32l;
    // 0x800B2F88: lwc1        $f18, 0x2BC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2BC);
    // 0x800B2F8C: c.le.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl <= ctx->f20.fl;
    // 0x800B2F90: nop

    // 0x800B2F94: bc1fl       L_800B2FA8
    if (!c1cs) {
        // 0x800B2F98: lwc1        $f0, 0x110($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
            goto L_800B2FA8;
    }
    goto skip_8;
    // 0x800B2F98: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
    skip_8:
    // 0x800B2F9C: swc1        $f20, 0x2BC($s0)
    MEM_W(0X2BC, ctx->r16) = ctx->f20.u32l;
    // 0x800B2FA0: sw          $zero, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = 0;
    // 0x800B2FA4: lwc1        $f0, 0x110($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X110);
L_800B2FA8:
    // 0x800B2FA8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800B2FAC: nop

    // 0x800B2FB0: bc1fl       L_800B2FE4
    if (!c1cs) {
        // 0x800B2FB4: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_800B2FE4;
    }
    goto skip_9;
    // 0x800B2FB4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_9:
    // 0x800B2FB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B2FBC: nop

    // 0x800B2FC0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800B2FC4: swc1        $f6, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f6.u32l;
    // 0x800B2FC8: lwc1        $f8, 0x110($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800B2FCC: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x800B2FD0: nop

    // 0x800B2FD4: bc1fl       L_800B2FE4
    if (!c1cs) {
        // 0x800B2FD8: mfc1        $a1, $f20
        ctx->r5 = (int32_t)ctx->f20.u32l;
            goto L_800B2FE4;
    }
    goto skip_10;
    // 0x800B2FD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    skip_10:
    // 0x800B2FDC: swc1        $f20, 0x110($s0)
    MEM_W(0X110, ctx->r16) = ctx->f20.u32l;
    // 0x800B2FE0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
L_800B2FE4:
    // 0x800B2FE4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B2FE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B2FEC: addiu       $a0, $s0, 0x8C
    ctx->r4 = ADD32(ctx->r16, 0X8C);
    // 0x800B2FF0: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B2FF4: jal         0x8009BC2C
    // 0x800B2FF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B2FF8: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x800B2FFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B3000: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800B3004: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800B3008: jr          $ra
    // 0x800B300C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B300C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Player_ApplyDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A6CD0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800A6CD4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800A6CD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A6CDC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A6CE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A6CE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A6CE8: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800A6CEC: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800A6CF0: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800A6CF4: sw          $a1, 0x21C($s0)
    MEM_W(0X21C, ctx->r16) = ctx->r5;
    // 0x800A6CF8: sw          $t6, 0x1A4($s0)
    MEM_W(0X1A4, ctx->r16) = ctx->r14;
    // 0x800A6CFC: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800A6D00: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x800A6D04: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x800A6D08: beq         $t7, $at, L_800A6D2C
    if (ctx->r15 == ctx->r1) {
        // 0x800A6D0C: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_800A6D2C;
    }
    // 0x800A6D0C: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A6D10: addiu       $at, $zero, 0x29
    ctx->r1 = ADD32(0, 0X29);
    // 0x800A6D14: beq         $t7, $at, L_800A6D2C
    if (ctx->r15 == ctx->r1) {
        // 0x800A6D18: addiu       $at, $zero, 0x2A
        ctx->r1 = ADD32(0, 0X2A);
            goto L_800A6D2C;
    }
    // 0x800A6D18: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800A6D1C: beq         $t7, $at, L_800A6D2C
    if (ctx->r15 == ctx->r1) {
        // 0x800A6D20: addiu       $at, $zero, 0x2B
        ctx->r1 = ADD32(0, 0X2B);
            goto L_800A6D2C;
    }
    // 0x800A6D20: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x800A6D24: bne         $t7, $at, L_800A6D30
    if (ctx->r15 != ctx->r1) {
        // 0x800A6D28: nop
    
            goto L_800A6D30;
    }
    // 0x800A6D28: nop

L_800A6D2C:
    // 0x800A6D2C: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
L_800A6D30:
    // 0x800A6D30: lw          $t9, 0x79F8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X79F8);
    // 0x800A6D34: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800A6D38: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800A6D3C: beq         $t9, $zero, L_800A6D4C
    if (ctx->r25 == 0) {
        // 0x800A6D40: sll         $t1, $t0, 1
        ctx->r9 = S32(ctx->r8 << 1);
            goto L_800A6D4C;
    }
    // 0x800A6D40: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x800A6D44: b           L_800A6D50
    // 0x800A6D48: sw          $t1, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r9;
        goto L_800A6D50;
    // 0x800A6D48: sw          $t1, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r9;
L_800A6D4C:
    // 0x800A6D4C: sw          $t2, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r10;
L_800A6D50:
    // 0x800A6D50: lw          $t3, 0x268($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X268);
    // 0x800A6D54: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800A6D58: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800A6D5C: beql        $t3, $zero, L_800A6D6C
    if (ctx->r11 == 0) {
        // 0x800A6D60: lw          $t6, 0x1A4($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X1A4);
            goto L_800A6D6C;
    }
    goto skip_0;
    // 0x800A6D60: lw          $t6, 0x1A4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1A4);
    skip_0:
    // 0x800A6D64: sw          $t4, 0x220($s0)
    MEM_W(0X220, ctx->r16) = ctx->r12;
    // 0x800A6D68: lw          $t6, 0x1A4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1A4);
L_800A6D6C:
    // 0x800A6D6C: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x800A6D70: sw          $zero, 0x284($s0)
    MEM_W(0X284, ctx->r16) = 0;
    // 0x800A6D74: slti        $at, $t6, 0x29
    ctx->r1 = SIGNED(ctx->r14) < 0X29 ? 1 : 0;
    // 0x800A6D78: bne         $at, $zero, L_800A6DA4
    if (ctx->r1 != 0) {
        // 0x800A6D7C: sw          $t5, 0x1F4($s0)
        MEM_W(0X1F4, ctx->r16) = ctx->r13;
            goto L_800A6DA4;
    }
    // 0x800A6D7C: sw          $t5, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r13;
    // 0x800A6D80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A6D84: lwc1        $f6, -0x7C98($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7C98);
    // 0x800A6D88: lwc1        $f4, 0x110($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X110);
    // 0x800A6D8C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x800A6D90: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A6D94: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A6D98: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x800A6D9C: b           L_800A6DF4
    // 0x800A6DA0: sw          $t7, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r15;
        goto L_800A6DF4;
    // 0x800A6DA0: sw          $t7, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r15;
L_800A6DA4:
    // 0x800A6DA4: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800A6DA8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800A6DAC: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x800A6DB0: bnel        $v0, $at, L_800A6DD4
    if (ctx->r2 != ctx->r1) {
        // 0x800A6DB4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800A6DD4;
    }
    goto skip_1;
    // 0x800A6DB4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_1:
    // 0x800A6DB8: lw          $t8, -0x7D7C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D7C);
    // 0x800A6DBC: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800A6DC0: bnel        $t8, $zero, L_800A6DD4
    if (ctx->r24 != 0) {
        // 0x800A6DC4: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_800A6DD4;
    }
    goto skip_2;
    // 0x800A6DC4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    skip_2:
    // 0x800A6DC8: b           L_800A6DF4
    // 0x800A6DCC: sw          $t9, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r25;
        goto L_800A6DF4;
    // 0x800A6DCC: sw          $t9, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r25;
    // 0x800A6DD0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
L_800A6DD4:
    // 0x800A6DD4: beq         $v0, $at, L_800A6DE8
    if (ctx->r2 == ctx->r1) {
        // 0x800A6DD8: addiu       $t0, $zero, 0x5
        ctx->r8 = ADD32(0, 0X5);
            goto L_800A6DE8;
    }
    // 0x800A6DD8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800A6DDC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800A6DE0: bne         $v0, $at, L_800A6DF0
    if (ctx->r2 != ctx->r1) {
        // 0x800A6DE4: addiu       $t1, $zero, 0x14
        ctx->r9 = ADD32(0, 0X14);
            goto L_800A6DF0;
    }
    // 0x800A6DE4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_800A6DE8:
    // 0x800A6DE8: b           L_800A6DF4
    // 0x800A6DEC: sw          $t0, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r8;
        goto L_800A6DF4;
    // 0x800A6DEC: sw          $t0, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r8;
L_800A6DF0:
    // 0x800A6DF0: sw          $t1, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r9;
L_800A6DF4:
    // 0x800A6DF4: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6DF8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800A6DFC: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800A6E00: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800A6E04: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A6E08: lw          $t3, 0x7AD0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7AD0);
    // 0x800A6E0C: lui         $a1, 0x903
    ctx->r5 = S32(0X903 << 16);
    // 0x800A6E10: beql        $t3, $zero, L_800A6E60
    if (ctx->r11 == 0) {
        // 0x800A6E14: lw          $v0, 0x264($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X264);
            goto L_800A6E60;
    }
    goto skip_3;
    // 0x800A6E14: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
    skip_3:
    // 0x800A6E18: jal         0x800A5FA0
    // 0x800A6E1C: ori         $a1, $a1, 0x900E
    ctx->r5 = ctx->r5 | 0X900E;
    Player_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800A6E1C: ori         $a1, $a1, 0x900E
    ctx->r5 = ctx->r5 | 0X900E;
    after_0:
    // 0x800A6E20: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6E24: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A6E28: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800A6E2C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A6E30: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800A6E34: sw          $t4, 0x7AE8($at)
    MEM_W(0X7AE8, ctx->r1) = ctx->r12;
    // 0x800A6E38: lw          $t7, 0x1C4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C4);
    // 0x800A6E3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A6E40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A6E44: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A6E48: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A6E4C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800A6E50: swc1        $f16, 0x7AB8($at)
    MEM_W(0X7AB8, ctx->r1) = ctx->f16.u32l;
    // 0x800A6E54: b           L_800A6F18
    // 0x800A6E58: sw          $zero, 0x268($s0)
    MEM_W(0X268, ctx->r16) = 0;
        goto L_800A6F18;
    // 0x800A6E58: sw          $zero, 0x268($s0)
    MEM_W(0X268, ctx->r16) = 0;
    // 0x800A6E5C: lw          $v0, 0x264($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X264);
L_800A6E60:
    // 0x800A6E60: beq         $v0, $zero, L_800A6EE0
    if (ctx->r2 == 0) {
        // 0x800A6E64: slti        $at, $v0, 0x32
        ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
            goto L_800A6EE0;
    }
    // 0x800A6E64: slti        $at, $v0, 0x32
    ctx->r1 = SIGNED(ctx->r2) < 0X32 ? 1 : 0;
    // 0x800A6E68: beq         $at, $zero, L_800A6EA4
    if (ctx->r1 == 0) {
        // 0x800A6E6C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_800A6EA4;
    }
    // 0x800A6E6C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800A6E70: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800A6E74: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800A6E78: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x800A6E7C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800A6E80: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800A6E84: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800A6E88: ori         $a0, $a0, 0x8011
    ctx->r4 = ctx->r4 | 0X8011;
    // 0x800A6E8C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800A6E90: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800A6E94: jal         0x80019218
    // 0x800A6E98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800A6E98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800A6E9C: b           L_800A6EE0
    // 0x800A6EA0: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
        goto L_800A6EE0;
    // 0x800A6EA0: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
L_800A6EA4:
    // 0x800A6EA4: slti        $at, $v0, 0x64
    ctx->r1 = SIGNED(ctx->r2) < 0X64 ? 1 : 0;
    // 0x800A6EA8: beq         $at, $zero, L_800A6EE0
    if (ctx->r1 == 0) {
        // 0x800A6EAC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_800A6EE0;
    }
    // 0x800A6EAC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800A6EB0: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x800A6EB4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800A6EB8: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x800A6EBC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800A6EC0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800A6EC4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800A6EC8: ori         $a0, $a0, 0x8010
    ctx->r4 = ctx->r4 | 0X8010;
    // 0x800A6ECC: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A6ED0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800A6ED4: jal         0x80019218
    // 0x800A6ED8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x800A6ED8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_2:
    // 0x800A6EDC: lw          $a2, 0x1C4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X1C4);
L_800A6EE0:
    // 0x800A6EE0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800A6EE4: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    // 0x800A6EE8: lui         $a1, 0x903
    ctx->r5 = S32(0X903 << 16);
    // 0x800A6EEC: slti        $at, $t1, 0x19
    ctx->r1 = SIGNED(ctx->r9) < 0X19 ? 1 : 0;
    // 0x800A6EF0: beq         $at, $zero, L_800A6F10
    if (ctx->r1 == 0) {
        // 0x800A6EF4: nop
    
            goto L_800A6F10;
    }
    // 0x800A6EF4: nop

    // 0x800A6EF8: lui         $a1, 0x903
    ctx->r5 = S32(0X903 << 16);
    // 0x800A6EFC: ori         $a1, $a1, 0x900E
    ctx->r5 = ctx->r5 | 0X900E;
    // 0x800A6F00: jal         0x800A5FA0
    // 0x800A6F04: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    Player_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800A6F04: addiu       $a0, $s0, 0x460
    ctx->r4 = ADD32(ctx->r16, 0X460);
    after_3:
    // 0x800A6F08: b           L_800A6F18
    // 0x800A6F0C: nop

        goto L_800A6F18;
    // 0x800A6F0C: nop

L_800A6F10:
    // 0x800A6F10: jal         0x800A5FA0
    // 0x800A6F14: ori         $a1, $a1, 0xA00F
    ctx->r5 = ctx->r5 | 0XA00F;
    Player_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x800A6F14: ori         $a1, $a1, 0xA00F
    ctx->r5 = ctx->r5 | 0XA00F;
    after_4:
L_800A6F18:
    // 0x800A6F18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A6F1C: lwc1        $f4, -0x7C94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7C94);
    // 0x800A6F20: lwc1        $f18, 0x114($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800A6F24: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A6F28: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A6F2C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800A6F30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A6F34: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A6F38: jal         0x80005E90
    // 0x800A6F3C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x800A6F3C: nop

    after_5:
    // 0x800A6F40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A6F44: lwc1        $f10, -0x7C90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7C90);
    // 0x800A6F48: lwc1        $f8, 0xF8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800A6F4C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A6F50: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A6F54: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A6F58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A6F5C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800A6F60: jal         0x80005FE0
    // 0x800A6F64: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x800A6F64: nop

    after_6:
    // 0x800A6F68: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A6F6C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800A6F70: addiu       $v0, $v0, -0x4438
    ctx->r2 = ADD32(ctx->r2, -0X4438);
    // 0x800A6F74: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x800A6F78: lw          $t2, 0x21C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X21C);
    // 0x800A6F7C: sltiu       $at, $t2, 0x5
    ctx->r1 = ctx->r10 < 0X5 ? 1 : 0;
    // 0x800A6F80: beq         $at, $zero, L_800A7228
    if (ctx->r1 == 0) {
        // 0x800A6F84: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_800A7228;
    }
    // 0x800A6F84: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A6F88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A6F8C: addu        $at, $at, $t2
    gpr jr_addend_800A6F94 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800A6F90: lw          $t2, -0x7C8C($at)
    ctx->r10 = ADD32(ctx->r1, -0X7C8C);
    // 0x800A6F94: jr          $t2
    // 0x800A6F98: nop

    switch (jr_addend_800A6F94 >> 2) {
        case 0: goto L_800A6F9C; break;
        case 1: goto L_800A6FB8; break;
        case 2: goto L_800A7030; break;
        case 3: goto L_800A70A4; break;
        case 4: goto L_800A7174; break;
        default: switch_error(__func__, 0x800A6F94, 0x800D8374);
    }
    // 0x800A6F98: nop

L_800A6F9C:
    // 0x800A6F9C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800A6FA0: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x800A6FA4: sw          $t3, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->r11;
    // 0x800A6FA8: swc1        $f0, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f0.u32l;
    // 0x800A6FAC: swc1        $f0, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f0.u32l;
    // 0x800A6FB0: b           L_800A7228
    // 0x800A6FB4: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
        goto L_800A7228;
    // 0x800A6FB4: swc1        $f0, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f0.u32l;
L_800A6FB8:
    // 0x800A6FB8: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A6FBC: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A6FC0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A6FC4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800A6FC8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800A6FCC: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800A6FD0: jal         0x80006A20
    // 0x800A6FD4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_7;
    // 0x800A6FD4: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    after_7:
    // 0x800A6FD8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A6FDC: lwc1        $f4, 0x2DC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2DC);
    // 0x800A6FE0: lwc1        $f16, 0x2D4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2D4);
    // 0x800A6FE4: swc1        $f6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f6.u32l;
    // 0x800A6FE8: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A6FEC: lwc1        $f6, 0xC8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800A6FF0: lwc1        $f18, 0xC0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800A6FF4: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x800A6FF8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A6FFC: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A7000: lwc1        $f14, 0x2D8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x800A7004: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800A7008: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800A700C: jal         0x800A668C
    // 0x800A7010: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
    Play_SpawnHitmark(rdram, ctx);
        goto after_8;
    // 0x800A7010: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x800A7014: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A7018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800A701C: jal         0x800A6AC0
    // 0x800A7020: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    Player_DamageWings(rdram, ctx);
        goto after_9;
    // 0x800A7020: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_9:
    // 0x800A7024: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A7028: b           L_800A7228
    // 0x800A702C: nop

        goto L_800A7228;
    // 0x800A702C: nop

L_800A7030:
    // 0x800A7030: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A7034: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A7038: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A703C: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800A7040: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800A7044: jal         0x80006A20
    // 0x800A7048: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_10;
    // 0x800A7048: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x800A704C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A7050: lwc1        $f10, 0x2D0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2D0);
    // 0x800A7054: lwc1        $f6, 0x2C8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C8);
    // 0x800A7058: swc1        $f16, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f16.u32l;
    // 0x800A705C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A7060: lwc1        $f16, 0xC8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800A7064: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800A7068: swc1        $f18, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f18.u32l;
    // 0x800A706C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A7070: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A7074: lwc1        $f14, 0x2CC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x800A7078: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A707C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800A7080: jal         0x800A668C
    // 0x800A7084: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    Play_SpawnHitmark(rdram, ctx);
        goto after_11;
    // 0x800A7084: swc1        $f4, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f4.u32l;
    after_11:
    // 0x800A7088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A708C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A7090: jal         0x800A6AC0
    // 0x800A7094: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    Player_DamageWings(rdram, ctx);
        goto after_12;
    // 0x800A7094: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_12:
    // 0x800A7098: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A709C: b           L_800A7228
    // 0x800A70A0: nop

        goto L_800A7228;
    // 0x800A70A0: nop

L_800A70A4:
    // 0x800A70A4: lwc1        $f8, 0x2F4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x800A70A8: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800A70AC: lwc1        $f4, 0x2EC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x800A70B0: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800A70B4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A70B8: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x800A70BC: sw          $t5, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->r13;
    // 0x800A70C0: lwc1        $f14, 0x2F0($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x800A70C4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800A70C8: jal         0x800A668C
    // 0x800A70CC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    Play_SpawnHitmark(rdram, ctx);
        goto after_13;
    // 0x800A70CC: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_13:
    // 0x800A70D0: lw          $t4, 0x1CC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A70D4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800A70D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A70DC: beq         $t4, $at, L_800A7120
    if (ctx->r12 == ctx->r1) {
        // 0x800A70E0: addiu       $v0, $v0, -0x4438
        ctx->r2 = ADD32(ctx->r2, -0X4438);
            goto L_800A7120;
    }
    // 0x800A70E0: addiu       $v0, $v0, -0x4438
    ctx->r2 = ADD32(ctx->r2, -0X4438);
    // 0x800A70E4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A70E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A70EC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A70F0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A70F4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800A70F8: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800A70FC: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800A7100: jal         0x80006A20
    // 0x800A7104: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_14;
    // 0x800A7104: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x800A7108: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A710C: swc1        $f8, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f8.u32l;
    // 0x800A7110: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A7114: swc1        $f10, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f10.u32l;
    // 0x800A7118: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A711C: swc1        $f16, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f16.u32l;
L_800A7120:
    // 0x800A7120: jal         0x80004EB0
    // 0x800A7124: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_15;
    // 0x800A7124: nop

    after_15:
    // 0x800A7128: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A712C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A7130: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x800A7134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A7138: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800A713C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A7140: bc1f        L_800A7160
    if (!c1cs) {
        // 0x800A7144: nop
    
            goto L_800A7160;
    }
    // 0x800A7144: nop

    // 0x800A7148: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A714C: jal         0x800A6AC0
    // 0x800A7150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Player_DamageWings(rdram, ctx);
        goto after_16;
    // 0x800A7150: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x800A7154: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A7158: b           L_800A7228
    // 0x800A715C: nop

        goto L_800A7228;
    // 0x800A715C: nop

L_800A7160:
    // 0x800A7160: jal         0x800A6AC0
    // 0x800A7164: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    Player_DamageWings(rdram, ctx);
        goto after_17;
    // 0x800A7164: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_17:
    // 0x800A7168: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800A716C: b           L_800A7228
    // 0x800A7170: nop

        goto L_800A7228;
    // 0x800A7170: nop

L_800A7174:
    // 0x800A7174: lwc1        $f8, 0x2E8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x800A7178: lwc1        $f10, 0xC8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800A717C: lwc1        $f4, 0x2E0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E0);
    // 0x800A7180: lwc1        $f6, 0xC0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800A7184: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800A7188: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x800A718C: sw          $t6, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->r14;
    // 0x800A7190: lwc1        $f14, 0x2E4($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2E4);
    // 0x800A7194: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800A7198: jal         0x800A668C
    // 0x800A719C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    Play_SpawnHitmark(rdram, ctx);
        goto after_18;
    // 0x800A719C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_18:
    // 0x800A71A0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A71A4: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800A71A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800A71AC: addiu       $v0, $v0, -0x4438
    ctx->r2 = ADD32(ctx->r2, -0X4438);
    // 0x800A71B0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800A71B4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800A71B8: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800A71BC: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800A71C0: jal         0x80006A20
    // 0x800A71C4: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_19;
    // 0x800A71C4: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    after_19:
    // 0x800A71C8: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A71CC: swc1        $f6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f6.u32l;
    // 0x800A71D0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800A71D4: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x800A71D8: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A71DC: jal         0x80004EB0
    // 0x800A71E0: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x800A71E0: swc1        $f10, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f10.u32l;
    after_20:
    // 0x800A71E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800A71E8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A71EC: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x800A71F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A71F4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A71F8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800A71FC: bc1f        L_800A7218
    if (!c1cs) {
        // 0x800A7200: nop
    
            goto L_800A7218;
    }
    // 0x800A7200: nop

    // 0x800A7204: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A7208: jal         0x800A6AC0
    // 0x800A720C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Player_DamageWings(rdram, ctx);
        goto after_21;
    // 0x800A720C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x800A7210: b           L_800A7224
    // 0x800A7214: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
        goto L_800A7224;
    // 0x800A7214: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800A7218:
    // 0x800A7218: jal         0x800A6AC0
    // 0x800A721C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    Player_DamageWings(rdram, ctx);
        goto after_22;
    // 0x800A721C: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_22:
    // 0x800A7220: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800A7224:
    // 0x800A7224: nop

L_800A7228:
    // 0x800A7228: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800A722C: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x800A7230: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800A7234: bnel        $t7, $at, L_800A728C
    if (ctx->r15 != ctx->r1) {
        // 0x800A7238: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A728C;
    }
    goto skip_4;
    // 0x800A7238: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800A723C: lw          $t8, 0x1A4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1A4);
    // 0x800A7240: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800A7244: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x800A7248: bnel        $t8, $at, L_800A728C
    if (ctx->r24 != ctx->r1) {
        // 0x800A724C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A728C;
    }
    goto skip_5;
    // 0x800A724C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800A7250: lwc1        $f18, 0x74($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800A7254: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800A7258: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x800A725C: nop

    // 0x800A7260: bc1fl       L_800A727C
    if (!c1cs) {
        // 0x800A7264: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800A727C;
    }
    goto skip_6;
    // 0x800A7264: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_6:
    // 0x800A7268: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x800A726C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A7270: b           L_800A7284
    // 0x800A7274: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
        goto L_800A7284;
    // 0x800A7274: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
    // 0x800A7278: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800A727C:
    // 0x800A727C: nop

    // 0x800A7280: swc1        $f6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f6.u32l;
L_800A7284:
    // 0x800A7284: sw          $t9, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r25;
    // 0x800A7288: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A728C:
    // 0x800A728C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A7290: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800A7294: jr          $ra
    // 0x800A7298: nop

    return;
    // 0x800A7298: nop

;}
RECOMP_FUNC void func_tank_800481F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800481F4: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x800481F8: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800481FC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80048200: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x80048204: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x80048208: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x8004820C: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x80048210: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x80048214: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x80048218: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x8004821C: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x80048220: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x80048224: sdc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X58, ctx->r29);
    // 0x80048228: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x8004822C: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x80048230: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80048234: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80048238: jal         0x800A887C
    // 0x8004823C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Player_UpdateHitbox(rdram, ctx);
        goto after_0;
    // 0x8004823C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x80048240: jal         0x800444BC
    // 0x80048244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_tank_800444BC(rdram, ctx);
        goto after_1;
    // 0x80048244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80048248: lw          $t6, 0x498($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X498);
    // 0x8004824C: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80048250: addiu       $s0, $s0, 0x1B00
    ctx->r16 = ADD32(ctx->r16, 0X1B00);
    // 0x80048254: bne         $t6, $zero, L_80048A70
    if (ctx->r14 != 0) {
        // 0x80048258: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80048A70;
    }
    // 0x80048258: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8004825C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80048260: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x80048264: lui         $s5, 0x1900
    ctx->r21 = S32(0X1900 << 16);
    // 0x80048268: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x8004826C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80048270: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80048274: addiu       $s2, $s2, 0x5D34
    ctx->r18 = ADD32(ctx->r18, 0X5D34);
    // 0x80048278: ori         $s5, $s5, 0x1
    ctx->r21 = ctx->r21 | 0X1;
    // 0x8004827C: addiu       $s6, $s6, 0x5D3C
    ctx->r22 = ADD32(ctx->r22, 0X5D3C);
    // 0x80048280: addiu       $fp, $zero, 0x69
    ctx->r30 = ADD32(0, 0X69);
    // 0x80048284: addiu       $s7, $zero, 0x3A
    ctx->r23 = ADD32(0, 0X3A);
    // 0x80048288: addiu       $s4, $zero, 0x14
    ctx->r20 = ADD32(0, 0X14);
L_8004828C:
    // 0x8004828C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80048290: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048294: bnel        $t7, $at, L_80048444
    if (ctx->r15 != ctx->r1) {
        // 0x80048298: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048444;
    }
    goto skip_0;
    // 0x80048298: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_0:
    // 0x8004829C: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800482A0: beql        $s7, $v0, L_80048444
    if (ctx->r23 == ctx->r2) {
        // 0x800482A4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048444;
    }
    goto skip_1;
    // 0x800482A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x800482A8: beq         $fp, $v0, L_80048440
    if (ctx->r30 == ctx->r2) {
        // 0x800482AC: addiu       $at, $zero, 0x3B
        ctx->r1 = ADD32(0, 0X3B);
            goto L_80048440;
    }
    // 0x800482AC: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x800482B0: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482B4: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80048440;
    }
    // 0x800482B4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x800482B8: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482BC: addiu       $at, $zero, 0x3F
        ctx->r1 = ADD32(0, 0X3F);
            goto L_80048440;
    }
    // 0x800482BC: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x800482C0: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482C4: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_80048440;
    }
    // 0x800482C4: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800482C8: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482CC: addiu       $at, $zero, 0x43
        ctx->r1 = ADD32(0, 0X43);
            goto L_80048440;
    }
    // 0x800482CC: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x800482D0: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482D4: addiu       $at, $zero, 0x44
        ctx->r1 = ADD32(0, 0X44);
            goto L_80048440;
    }
    // 0x800482D4: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x800482D8: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482DC: addiu       $at, $zero, 0x46
        ctx->r1 = ADD32(0, 0X46);
            goto L_80048440;
    }
    // 0x800482DC: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x800482E0: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482E4: addiu       $at, $zero, 0x48
        ctx->r1 = ADD32(0, 0X48);
            goto L_80048440;
    }
    // 0x800482E4: addiu       $at, $zero, 0x48
    ctx->r1 = ADD32(0, 0X48);
    // 0x800482E8: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482EC: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80048440;
    }
    // 0x800482EC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800482F0: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482F4: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_80048440;
    }
    // 0x800482F4: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x800482F8: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x800482FC: addiu       $at, $zero, 0x4A
        ctx->r1 = ADD32(0, 0X4A);
            goto L_80048440;
    }
    // 0x800482FC: addiu       $at, $zero, 0x4A
    ctx->r1 = ADD32(0, 0X4A);
    // 0x80048300: beq         $v0, $at, L_80048440
    if (ctx->r2 == ctx->r1) {
        // 0x80048304: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80048440;
    }
    // 0x80048304: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x80048308: beql        $v0, $at, L_80048444
    if (ctx->r2 == ctx->r1) {
        // 0x8004830C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048444;
    }
    goto skip_2;
    // 0x8004830C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x80048310: lwc1        $f4, 0x138($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X138);
    // 0x80048314: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80048318: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8004831C: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80048320: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80048324: nop

    // 0x80048328: bc1fl       L_80048444
    if (!c1cs) {
        // 0x8004832C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048444;
    }
    goto skip_3;
    // 0x8004832C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_3:
    // 0x80048330: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80048334: lui         $t8, 0x8006
    ctx->r24 = S32(0X8006 << 16);
    // 0x80048338: addiu       $t8, $t8, 0x6EA8
    ctx->r24 = ADD32(ctx->r24, 0X6EA8);
    // 0x8004833C: bne         $t8, $t9, L_80048348
    if (ctx->r24 != ctx->r25) {
        // 0x80048340: lwc1        $f2, 0x14($s0)
        ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
            goto L_80048348;
    }
    // 0x80048340: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80048344: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
L_80048348:
    // 0x80048348: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8004834C: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80048350: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80048354: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80048358: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8004835C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80048360: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80048364: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x80048368: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8004836C: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80048370: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80048374: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x80048378: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8004837C: jal         0x800A7974
    // 0x80048380: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    Player_CheckHitboxCollision(rdram, ctx);
        goto after_2;
    // 0x80048380: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80048384: beq         $v0, $zero, L_80048440
    if (ctx->r2 == 0) {
        // 0x80048388: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80048440;
    }
    // 0x80048388: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8004838C: bgez        $v0, L_80048438
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80048390: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80048438;
    }
    // 0x80048390: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048394: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80048398: bne         $v0, $at, L_8004840C
    if (ctx->r2 != ctx->r1) {
        // 0x8004839C: addiu       $t0, $zero, 0x28
        ctx->r8 = ADD32(0, 0X28);
            goto L_8004840C;
    }
    // 0x8004839C: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x800483A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800483A4: sw          $t0, -0x7AC0($at)
    MEM_W(-0X7AC0, ctx->r1) = ctx->r8;
    // 0x800483A8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800483AC: sw          $s4, -0x7A90($at)
    MEM_W(-0X7A90, ctx->r1) = ctx->r20;
    // 0x800483B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800483B4: sw          $s4, -0x7A8C($at)
    MEM_W(-0X7A8C, ctx->r1) = ctx->r20;
    // 0x800483B8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800483BC: sw          $s4, -0x7A88($at)
    MEM_W(-0X7A88, ctx->r1) = ctx->r20;
    // 0x800483C0: lw          $v0, 0x22C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X22C);
    // 0x800483C4: addiu       $t1, $zero, 0x50
    ctx->r9 = ADD32(0, 0X50);
    // 0x800483C8: sw          $t1, 0x23C($s1)
    MEM_W(0X23C, ctx->r17) = ctx->r9;
    // 0x800483CC: bne         $v0, $zero, L_800483F0
    if (ctx->r2 != 0) {
        // 0x800483D0: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_800483F0;
    }
    // 0x800483D0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800483D4: addiu       $a1, $s1, 0x460
    ctx->r5 = ADD32(ctx->r17, 0X460);
    // 0x800483D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800483DC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800483E0: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800483E4: jal         0x80019218
    // 0x800483E8: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800483E8: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_3:
    // 0x800483EC: lw          $v0, 0x22C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X22C);
L_800483F0:
    // 0x800483F0: addiu       $t2, $v0, 0x2
    ctx->r10 = ADD32(ctx->r2, 0X2);
    // 0x800483F4: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x800483F8: bne         $at, $zero, L_80048440
    if (ctx->r1 != 0) {
        // 0x800483FC: sw          $t2, 0x22C($s1)
        MEM_W(0X22C, ctx->r17) = ctx->r10;
            goto L_80048440;
    }
    // 0x800483FC: sw          $t2, 0x22C($s1)
    MEM_W(0X22C, ctx->r17) = ctx->r10;
    // 0x80048400: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80048404: b           L_80048440
    // 0x80048408: sw          $t4, 0x22C($s1)
    MEM_W(0X22C, ctx->r17) = ctx->r12;
        goto L_80048440;
    // 0x80048408: sw          $t4, 0x22C($s1)
    MEM_W(0X22C, ctx->r17) = ctx->r12;
L_8004840C:
    // 0x8004840C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80048410: bne         $v0, $at, L_80048440
    if (ctx->r2 != ctx->r1) {
        // 0x80048414: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80048440;
    }
    // 0x80048414: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80048418: addiu       $a1, $s1, 0x460
    ctx->r5 = ADD32(ctx->r17, 0X460);
    // 0x8004841C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80048420: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80048424: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80048428: jal         0x80019218
    // 0x8004842C: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8004842C: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_4:
    // 0x80048430: b           L_80048444
    // 0x80048434: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80048444;
    // 0x80048434: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80048438:
    // 0x80048438: jal         0x800A6CD0
    // 0x8004843C: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    Player_ApplyDamage(rdram, ctx);
        goto after_5;
    // 0x8004843C: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    after_5:
L_80048440:
    // 0x80048440: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80048444:
    // 0x80048444: slti        $at, $s3, 0x32
    ctx->r1 = SIGNED(ctx->r19) < 0X32 ? 1 : 0;
    // 0x80048448: bne         $at, $zero, L_8004828C
    if (ctx->r1 != 0) {
        // 0x8004844C: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_8004828C;
    }
    // 0x8004844C: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80048450: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80048454: addiu       $s0, $s0, -0xEF0
    ctx->r16 = ADD32(ctx->r16, -0XEF0);
    // 0x80048458: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8004845C:
    // 0x8004845C: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x80048460: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80048464: bnel        $t5, $at, L_800484CC
    if (ctx->r13 != ctx->r1) {
        // 0x80048468: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800484CC;
    }
    goto skip_4;
    // 0x80048468: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
    // 0x8004846C: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80048470: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80048474: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80048478: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8004847C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80048480: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048484: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x80048488: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8004848C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80048490: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80048494: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80048498: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8004849C: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800484A0: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800484A4: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x800484A8: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800484AC: jal         0x800A7974
    // 0x800484B0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Player_CheckHitboxCollision(rdram, ctx);
        goto after_6;
    // 0x800484B0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x800484B4: beq         $v0, $zero, L_800484C8
    if (ctx->r2 == 0) {
        // 0x800484B8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800484C8;
    }
    // 0x800484B8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800484BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800484C0: jal         0x800A6CD0
    // 0x800484C4: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    Player_ApplyDamage(rdram, ctx);
        goto after_7;
    // 0x800484C4: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    after_7:
L_800484C8:
    // 0x800484C8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800484CC:
    // 0x800484CC: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x800484D0: bne         $at, $zero, L_8004845C
    if (ctx->r1 != 0) {
        // 0x800484D4: addiu       $s0, $s0, 0x408
        ctx->r16 = ADD32(ctx->r16, 0X408);
            goto L_8004845C;
    }
    // 0x800484D4: addiu       $s0, $s0, 0x408
    ctx->r16 = ADD32(ctx->r16, 0X408);
    // 0x800484D8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800484DC: lwc1        $f28, 0x573C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X573C);
    // 0x800484E0: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x800484E4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800484E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800484EC: lwc1        $f24, 0x5740($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X5740);
    // 0x800484F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800484F4: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x800484F8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800484FC: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x80048500: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80048504: addiu       $fp, $zero, -0x14
    ctx->r30 = ADD32(0, -0X14);
    // 0x80048508: addiu       $s7, $zero, 0xF
    ctx->r23 = ADD32(0, 0XF);
    // 0x8004850C: addiu       $s6, $zero, 0x8
    ctx->r22 = ADD32(0, 0X8);
    // 0x80048510: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_80048514:
    // 0x80048514: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x80048518: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004851C: bnel        $t6, $at, L_80048974
    if (ctx->r14 != ctx->r1) {
        // 0x80048520: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048974;
    }
    goto skip_5;
    // 0x80048520: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_5:
    // 0x80048524: lhu         $t7, 0xC2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC2);
    // 0x80048528: bnel        $t7, $zero, L_80048974
    if (ctx->r15 != 0) {
        // 0x8004852C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048974;
    }
    goto skip_6;
    // 0x8004852C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_6:
    // 0x80048530: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80048534: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80048538: bnel        $v0, $at, L_800485C8
    if (ctx->r2 != ctx->r1) {
        // 0x8004853C: addiu       $at, $zero, 0xCF
        ctx->r1 = ADD32(0, 0XCF);
            goto L_800485C8;
    }
    goto skip_7;
    // 0x8004853C: addiu       $at, $zero, 0xCF
    ctx->r1 = ADD32(0, 0XCF);
    skip_7:
    // 0x80048540: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80048544: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80048548: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x8004854C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80048550: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80048554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048558: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x8004855C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80048560: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80048564: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80048568: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004856C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x80048570: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80048574: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80048578: lwc1        $f10, 0x2E8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x8004857C: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80048580: lwc1        $f16, 0x2EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
    // 0x80048584: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80048588: lwc1        $f4, 0xFC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x8004858C: lwc1        $f18, 0x2F0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x80048590: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80048594: jal         0x800A7974
    // 0x80048598: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    Player_CheckHitboxCollision(rdram, ctx);
        goto after_8;
    // 0x80048598: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x8004859C: beq         $v0, $zero, L_80048970
    if (ctx->r2 == 0) {
        // 0x800485A0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80048970;
    }
    // 0x800485A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800485A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800485A8: jal         0x800A6CD0
    // 0x800485AC: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    Player_ApplyDamage(rdram, ctx);
        goto after_9;
    // 0x800485AC: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    after_9:
    // 0x800485B0: sb          $s5, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r21;
    // 0x800485B4: lw          $t8, 0x1C4($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X1C4);
    // 0x800485B8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800485BC: b           L_80048970
    // 0x800485C0: sh          $t9, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r25;
        goto L_80048970;
    // 0x800485C0: sh          $t9, 0xD4($s0)
    MEM_H(0XD4, ctx->r16) = ctx->r25;
    // 0x800485C4: addiu       $at, $zero, 0xCF
    ctx->r1 = ADD32(0, 0XCF);
L_800485C8:
    // 0x800485C8: bnel        $v0, $at, L_80048724
    if (ctx->r2 != ctx->r1) {
        // 0x800485CC: slti        $at, $v0, 0xCD
        ctx->r1 = SIGNED(ctx->r2) < 0XCD ? 1 : 0;
            goto L_80048724;
    }
    goto skip_8;
    // 0x800485CC: slti        $at, $v0, 0xCD
    ctx->r1 = SIGNED(ctx->r2) < 0XCD ? 1 : 0;
    skip_8:
    // 0x800485D0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800485D4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x800485D8: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x800485DC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800485E0: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800485E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800485E8: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x800485EC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800485F0: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800485F4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800485F8: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800485FC: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x80048600: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80048604: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80048608: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x8004860C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80048610: jal         0x80046E40
    // 0x80048614: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    func_tank_80046E40(rdram, ctx);
        goto after_10;
    // 0x80048614: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_10:
    // 0x80048618: beq         $v0, $zero, L_80048970
    if (ctx->r2 == 0) {
        // 0x8004861C: lui         $a1, 0x4170
        ctx->r5 = S32(0X4170 << 16);
            goto L_80048970;
    }
    // 0x8004861C: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x80048620: lwc1        $f6, 0x74($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X74);
    // 0x80048624: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80048628: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8004862C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80048630: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80048634: addiu       $a0, $s1, 0xD0
    ctx->r4 = ADD32(ctx->r17, 0XD0);
    // 0x80048638: addiu       $s2, $s1, 0x8C
    ctx->r18 = ADD32(ctx->r17, 0X8C);
    // 0x8004863C: bc1fl       L_80048690
    if (!c1cs) {
        // 0x80048640: lwc1        $f4, 0xF0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
            goto L_80048690;
    }
    goto skip_9;
    // 0x80048640: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    skip_9:
    // 0x80048644: lwc1        $f10, 0xF0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80048648: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x8004864C: c.lt.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl < ctx->f10.fl;
    // 0x80048650: nop

    // 0x80048654: bc1fl       L_80048670
    if (!c1cs) {
        // 0x80048658: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80048670;
    }
    goto skip_10;
    // 0x80048658: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_10:
    // 0x8004865C: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x80048660: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80048664: b           L_80048678
    // 0x80048668: swc1        $f16, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f16.u32l;
        goto L_80048678;
    // 0x80048668: swc1        $f16, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f16.u32l;
    // 0x8004866C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80048670:
    // 0x80048670: nop

    // 0x80048674: swc1        $f18, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f18.u32l;
L_80048678:
    // 0x80048678: sw          $s6, 0x1DC($s1)
    MEM_W(0X1DC, ctx->r17) = ctx->r22;
    // 0x8004867C: sw          $s7, 0x1E8($s1)
    MEM_W(0X1E8, ctx->r17) = ctx->r23;
    // 0x80048680: sw          $s4, 0x1F0($s1)
    MEM_W(0X1F0, ctx->r17) = ctx->r20;
    // 0x80048684: b           L_800486C8
    // 0x80048688: sw          $s4, 0x1EC($s1)
    MEM_W(0X1EC, ctx->r17) = ctx->r20;
        goto L_800486C8;
    // 0x80048688: sw          $s4, 0x1EC($s1)
    MEM_W(0X1EC, ctx->r17) = ctx->r20;
    // 0x8004868C: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
L_80048690:
    // 0x80048690: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80048694: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x80048698: nop

    // 0x8004869C: bc1fl       L_800486B0
    if (!c1cs) {
        // 0x800486A0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_800486B0;
    }
    goto skip_11;
    // 0x800486A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_11:
    // 0x800486A4: b           L_800486B8
    // 0x800486A8: swc1        $f22, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f22.u32l;
        goto L_800486B8;
    // 0x800486A8: swc1        $f22, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f22.u32l;
    // 0x800486AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_800486B0:
    // 0x800486B0: nop

    // 0x800486B4: swc1        $f6, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f6.u32l;
L_800486B8:
    // 0x800486B8: sw          $s6, 0x1DC($s1)
    MEM_W(0X1DC, ctx->r17) = ctx->r22;
    // 0x800486BC: sw          $s7, 0x1E8($s1)
    MEM_W(0X1E8, ctx->r17) = ctx->r23;
    // 0x800486C0: sw          $fp, 0x1F0($s1)
    MEM_W(0X1F0, ctx->r17) = ctx->r30;
    // 0x800486C4: sw          $fp, 0x1EC($s1)
    MEM_W(0X1EC, ctx->r17) = ctx->r30;
L_800486C8:
    // 0x800486C8: jal         0x8009BC2C
    // 0x800486CC: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x800486CC: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    after_11:
    // 0x800486D0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800486D4: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800486D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800486DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800486E0: jal         0x8009BC2C
    // 0x800486E4: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x800486E4: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    after_12:
    // 0x800486E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800486EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800486F0: lwc1        $f10, 0x90($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X90);
    // 0x800486F4: swc1        $f20, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->f20.u32l;
    // 0x800486F8: swc1        $f8, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f8.u32l;
    // 0x800486FC: swc1        $f10, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f10.u32l;
    // 0x80048700: sb          $s5, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r21;
    // 0x80048704: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8004870C: jal         0x800A6CD0
    // 0x80048710: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    Player_ApplyDamage(rdram, ctx);
        goto after_13;
    // 0x80048710: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_13:
    // 0x80048714: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80048718: b           L_80048970
    // 0x8004871C: sw          $t0, 0x498($s1)
    MEM_W(0X498, ctx->r17) = ctx->r8;
        goto L_80048970;
    // 0x8004871C: sw          $t0, 0x498($s1)
    MEM_W(0X498, ctx->r17) = ctx->r8;
    // 0x80048720: slti        $at, $v0, 0xCD
    ctx->r1 = SIGNED(ctx->r2) < 0XCD ? 1 : 0;
L_80048724:
    // 0x80048724: bne         $at, $zero, L_800488C4
    if (ctx->r1 != 0) {
        // 0x80048728: slti        $at, $v0, 0xD6
        ctx->r1 = SIGNED(ctx->r2) < 0XD6 ? 1 : 0;
            goto L_800488C4;
    }
    // 0x80048728: slti        $at, $v0, 0xD6
    ctx->r1 = SIGNED(ctx->r2) < 0XD6 ? 1 : 0;
    // 0x8004872C: beql        $at, $zero, L_800488C8
    if (ctx->r1 == 0) {
        // 0x80048730: lwc1        $f10, 0x8($s0)
        ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
            goto L_800488C8;
    }
    goto skip_12;
    // 0x80048730: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    skip_12:
    // 0x80048734: lwc1        $f16, 0x178($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X178);
    // 0x80048738: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8004873C: lwc1        $f6, 0x134($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X134);
    // 0x80048740: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80048744: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80048748: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x8004874C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80048750: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80048754: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80048758: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8004875C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048760: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80048764: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x80048768: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8004876C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80048770: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80048774: lwc1        $f6, 0x188($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X188);
    // 0x80048778: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8004877C: lwc1        $f8, 0x17C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x80048780: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80048784: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80048788: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8004878C: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x80048790: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80048794: jal         0x80046E40
    // 0x80048798: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    func_tank_80046E40(rdram, ctx);
        goto after_14;
    // 0x80048798: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_14:
    // 0x8004879C: beq         $v0, $zero, L_80048970
    if (ctx->r2 == 0) {
        // 0x800487A0: addiu       $a0, $s1, 0xD0
        ctx->r4 = ADD32(ctx->r17, 0XD0);
            goto L_80048970;
    }
    // 0x800487A0: addiu       $a0, $s1, 0xD0
    ctx->r4 = ADD32(ctx->r17, 0XD0);
    // 0x800487A4: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800487A8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800487AC: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x800487B0: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x800487B4: jal         0x8009BC2C
    // 0x800487B8: addiu       $s2, $s1, 0x8C
    ctx->r18 = ADD32(ctx->r17, 0X8C);
    Math_SmoothStepToF(rdram, ctx);
        goto after_15;
    // 0x800487B8: addiu       $s2, $s1, 0x8C
    ctx->r18 = ADD32(ctx->r17, 0X8C);
    after_15:
    // 0x800487BC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800487C0: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800487C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800487C8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800487CC: jal         0x8009BC2C
    // 0x800487D0: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x800487D0: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    after_16:
    // 0x800487D4: lwc1        $f18, 0x170($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X170);
    // 0x800487D8: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800487DC: lwc1        $f16, 0x74($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X74);
    // 0x800487E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800487E4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800487E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800487EC: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800487F0: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x800487F4: nop

    // 0x800487F8: bc1fl       L_8004884C
    if (!c1cs) {
        // 0x800487FC: lwc1        $f4, 0xF0($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
            goto L_8004884C;
    }
    goto skip_13;
    // 0x800487FC: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
    skip_13:
    // 0x80048800: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x80048804: lui         $at, 0xBFC0
    ctx->r1 = S32(0XBFC0 << 16);
    // 0x80048808: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x8004880C: nop

    // 0x80048810: bc1fl       L_8004882C
    if (!c1cs) {
        // 0x80048814: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_8004882C;
    }
    goto skip_14;
    // 0x80048814: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_14:
    // 0x80048818: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x8004881C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80048820: b           L_80048834
    // 0x80048824: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
        goto L_80048834;
    // 0x80048824: swc1        $f10, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f10.u32l;
    // 0x80048828: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_8004882C:
    // 0x8004882C: nop

    // 0x80048830: swc1        $f18, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f18.u32l;
L_80048834:
    // 0x80048834: sw          $s6, 0x1DC($s1)
    MEM_W(0X1DC, ctx->r17) = ctx->r22;
    // 0x80048838: sw          $s7, 0x1E8($s1)
    MEM_W(0X1E8, ctx->r17) = ctx->r23;
    // 0x8004883C: sw          $s4, 0x1F0($s1)
    MEM_W(0X1F0, ctx->r17) = ctx->r20;
    // 0x80048840: b           L_80048884
    // 0x80048844: sw          $s4, 0x1EC($s1)
    MEM_W(0X1EC, ctx->r17) = ctx->r20;
        goto L_80048884;
    // 0x80048844: sw          $s4, 0x1EC($s1)
    MEM_W(0X1EC, ctx->r17) = ctx->r20;
    // 0x80048848: lwc1        $f4, 0xF0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XF0);
L_8004884C:
    // 0x8004884C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80048850: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x80048854: nop

    // 0x80048858: bc1fl       L_8004886C
    if (!c1cs) {
        // 0x8004885C: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_8004886C;
    }
    goto skip_15;
    // 0x8004885C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_15:
    // 0x80048860: b           L_80048874
    // 0x80048864: swc1        $f22, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f22.u32l;
        goto L_80048874;
    // 0x80048864: swc1        $f22, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f22.u32l;
    // 0x80048868: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_8004886C:
    // 0x8004886C: nop

    // 0x80048870: swc1        $f16, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f16.u32l;
L_80048874:
    // 0x80048874: sw          $s6, 0x1DC($s1)
    MEM_W(0X1DC, ctx->r17) = ctx->r22;
    // 0x80048878: sw          $s7, 0x1E8($s1)
    MEM_W(0X1E8, ctx->r17) = ctx->r23;
    // 0x8004887C: sw          $fp, 0x1F0($s1)
    MEM_W(0X1F0, ctx->r17) = ctx->r30;
    // 0x80048880: sw          $fp, 0x1EC($s1)
    MEM_W(0X1EC, ctx->r17) = ctx->r30;
L_80048884:
    // 0x80048884: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80048888: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004888C: lwc1        $f8, 0x90($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X90);
    // 0x80048890: swc1        $f20, 0xC0($s1)
    MEM_W(0XC0, ctx->r17) = ctx->f20.u32l;
    // 0x80048894: swc1        $f6, 0xC4($s1)
    MEM_W(0XC4, ctx->r17) = ctx->f6.u32l;
    // 0x80048898: swc1        $f8, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f8.u32l;
    // 0x8004889C: lbu         $t1, 0x34($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X34);
    // 0x800488A0: sb          $s5, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r21;
    // 0x800488A4: beq         $t1, $zero, L_800488BC
    if (ctx->r9 == 0) {
        // 0x800488A8: nop
    
            goto L_800488BC;
    }
    // 0x800488A8: nop

    // 0x800488AC: jal         0x800A6CD0
    // 0x800488B0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    Player_ApplyDamage(rdram, ctx);
        goto after_17;
    // 0x800488B0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_17:
    // 0x800488B4: b           L_80048974
    // 0x800488B8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80048974;
    // 0x800488B8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800488BC:
    // 0x800488BC: b           L_80048970
    // 0x800488C0: sb          $t2, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r10;
        goto L_80048970;
    // 0x800488C0: sb          $t2, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r10;
L_800488C4:
    // 0x800488C4: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
L_800488C8:
    // 0x800488C8: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x800488CC: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x800488D0: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800488D4: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800488D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800488DC: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x800488E0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x800488E4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800488E8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800488EC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800488F0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800488F4: lwc1        $f6, 0x18($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800488F8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800488FC: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x80048900: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x80048904: jal         0x800A7974
    // 0x80048908: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Player_CheckHitboxCollision(rdram, ctx);
        goto after_18;
    // 0x80048908: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x8004890C: beq         $v0, $zero, L_80048970
    if (ctx->r2 == 0) {
        // 0x80048910: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80048970;
    }
    // 0x80048910: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80048914: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80048918: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x8004891C: sb          $s5, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r21;
    // 0x80048920: beq         $v0, $at, L_80048934
    if (ctx->r2 == ctx->r1) {
        // 0x80048924: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80048934;
    }
    // 0x80048924: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80048928: addiu       $at, $zero, 0xBE
    ctx->r1 = ADD32(0, 0XBE);
    // 0x8004892C: bnel        $v0, $at, L_8004893C
    if (ctx->r2 != ctx->r1) {
        // 0x80048930: lbu         $v0, 0x34($s0)
        ctx->r2 = MEM_BU(ctx->r16, 0X34);
            goto L_8004893C;
    }
    goto skip_16;
    // 0x80048930: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    skip_16:
L_80048934:
    // 0x80048934: sb          $t3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r11;
    // 0x80048938: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
L_8004893C:
    // 0x8004893C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048940: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80048944: beql        $v0, $zero, L_80048970
    if (ctx->r2 == 0) {
        // 0x80048948: sb          $t5, 0xD0($s0)
        MEM_B(0XD0, ctx->r16) = ctx->r13;
            goto L_80048970;
    }
    goto skip_17;
    // 0x80048948: sb          $t5, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r13;
    skip_17:
    // 0x8004894C: jal         0x800A6CD0
    // 0x80048950: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    Player_ApplyDamage(rdram, ctx);
        goto after_19;
    // 0x80048950: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_19:
    // 0x80048954: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x80048958: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x8004895C: bnel        $t4, $at, L_80048974
    if (ctx->r12 != ctx->r1) {
        // 0x80048960: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048974;
    }
    goto skip_18;
    // 0x80048960: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_18:
    // 0x80048964: b           L_80048970
    // 0x80048968: swc1        $f20, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f20.u32l;
        goto L_80048970;
    // 0x80048968: swc1        $f20, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f20.u32l;
    // 0x8004896C: sb          $t5, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r13;
L_80048970:
    // 0x80048970: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80048974:
    // 0x80048974: slti        $at, $s3, 0x3C
    ctx->r1 = SIGNED(ctx->r19) < 0X3C ? 1 : 0;
    // 0x80048978: bne         $at, $zero, L_80048514
    if (ctx->r1 != 0) {
        // 0x8004897C: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_80048514;
    }
    // 0x8004897C: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x80048980: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80048984: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80048988: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8004898C: addiu       $s0, $s0, 0x3400
    ctx->r16 = ADD32(ctx->r16, 0X3400);
    // 0x80048990: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80048994: addiu       $s7, $zero, 0xA9
    ctx->r23 = ADD32(0, 0XA9);
    // 0x80048998: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
    // 0x8004899C: addiu       $s5, $zero, 0xA2
    ctx->r21 = ADD32(0, 0XA2);
    // 0x800489A0: addiu       $s4, $zero, 0xA1
    ctx->r20 = ADD32(0, 0XA1);
    // 0x800489A4: addiu       $s2, $zero, 0xA3
    ctx->r18 = ADD32(0, 0XA3);
L_800489A8:
    // 0x800489A8: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800489AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800489B0: bnel        $t6, $at, L_80048A64
    if (ctx->r14 != ctx->r1) {
        // 0x800489B4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048A64;
    }
    goto skip_19;
    // 0x800489B4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_19:
    // 0x800489B8: lwc1        $f8, 0x138($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X138);
    // 0x800489BC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800489C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800489C4: sub.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f22.fl;
    // 0x800489C8: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    // 0x800489CC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800489D0: nop

    // 0x800489D4: bc1fl       L_80048A64
    if (!c1cs) {
        // 0x800489D8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80048A64;
    }
    goto skip_20;
    // 0x800489D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_20:
    // 0x800489DC: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800489E0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x800489E4: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x800489E8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800489EC: swc1        $f20, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f20.u32l;
    // 0x800489F0: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800489F4: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800489F8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800489FC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80048A00: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80048A04: jal         0x800A7974
    // 0x80048A08: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Player_CheckHitboxCollision(rdram, ctx);
        goto after_20;
    // 0x80048A08: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_20:
    // 0x80048A0C: beq         $v0, $zero, L_80048A60
    if (ctx->r2 == 0) {
        // 0x80048A10: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80048A60;
    }
    // 0x80048A10: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80048A14: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x80048A18: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80048A1C: beql        $s2, $v0, L_80048A38
    if (ctx->r18 == ctx->r2) {
        // 0x80048A20: sb          $t7, 0x46($s0)
        MEM_B(0X46, ctx->r16) = ctx->r15;
            goto L_80048A38;
    }
    goto skip_21;
    // 0x80048A20: sb          $t7, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r15;
    skip_21:
    // 0x80048A24: beql        $s4, $v0, L_80048A38
    if (ctx->r20 == ctx->r2) {
        // 0x80048A28: sb          $t7, 0x46($s0)
        MEM_B(0X46, ctx->r16) = ctx->r15;
            goto L_80048A38;
    }
    goto skip_22;
    // 0x80048A28: sb          $t7, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r15;
    skip_22:
    // 0x80048A2C: bne         $s5, $v0, L_80048A44
    if (ctx->r21 != ctx->r2) {
        // 0x80048A30: nop
    
            goto L_80048A44;
    }
    // 0x80048A30: nop

    // 0x80048A34: sb          $t7, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r15;
L_80048A38:
    // 0x80048A38: sw          $s6, 0x1F4($s1)
    MEM_W(0X1F4, ctx->r17) = ctx->r22;
    // 0x80048A3C: b           L_80048A60
    // 0x80048A40: sw          $zero, 0x21C($s1)
    MEM_W(0X21C, ctx->r17) = 0;
        goto L_80048A60;
    // 0x80048A40: sw          $zero, 0x21C($s1)
    MEM_W(0X21C, ctx->r17) = 0;
L_80048A44:
    // 0x80048A44: bne         $s7, $v0, L_80048A58
    if (ctx->r23 != ctx->r2) {
        // 0x80048A48: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80048A58;
    }
    // 0x80048A48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80048A4C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80048A50: b           L_80048A60
    // 0x80048A54: sb          $t8, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r24;
        goto L_80048A60;
    // 0x80048A54: sb          $t8, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r24;
L_80048A58:
    // 0x80048A58: jal         0x800A6CD0
    // 0x80048A5C: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    Player_ApplyDamage(rdram, ctx);
        goto after_21;
    // 0x80048A5C: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    after_21:
L_80048A60:
    // 0x80048A60: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80048A64:
    // 0x80048A64: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80048A68: bne         $s3, $at, L_800489A8
    if (ctx->r19 != ctx->r1) {
        // 0x80048A6C: addiu       $s0, $s0, 0x4C
        ctx->r16 = ADD32(ctx->r16, 0X4C);
            goto L_800489A8;
    }
    // 0x80048A6C: addiu       $s0, $s0, 0x4C
    ctx->r16 = ADD32(ctx->r16, 0X4C);
L_80048A70:
    // 0x80048A70: jal         0x800A86E4
    // 0x80048A74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Player_CheckItemCollect(rdram, ctx);
        goto after_22;
    // 0x80048A74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x80048A78: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x80048A7C: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80048A80: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80048A84: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x80048A88: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x80048A8C: ldc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X58);
    // 0x80048A90: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x80048A94: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x80048A98: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x80048A9C: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x80048AA0: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80048AA4: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x80048AA8: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x80048AAC: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x80048AB0: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x80048AB4: jr          $ra
    // 0x80048AB8: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80048AB8: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void AudioSeq_RequestFreeSeqChannel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800141C8: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x800141CC: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x800141D0: addiu       $v0, $v0, 0xFE8
    ctx->r2 = ADD32(ctx->r2, 0XFE8);
    // 0x800141D4: addiu       $v1, $v1, -0x1598
    ctx->r3 = ADD32(ctx->r3, -0X1598);
    // 0x800141D8: lw          $t6, 0x44($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X44);
L_800141DC:
    // 0x800141DC: bnel        $t6, $zero, L_800141F0
    if (ctx->r14 != 0) {
        // 0x800141E0: lw          $t7, 0x10C($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X10C);
            goto L_800141F0;
    }
    goto skip_0;
    // 0x800141E0: lw          $t7, 0x10C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10C);
    skip_0:
    // 0x800141E4: jr          $ra
    // 0x800141E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800141E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800141EC: lw          $t7, 0x10C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10C);
L_800141F0:
    // 0x800141F0: bnel        $t7, $zero, L_80014204
    if (ctx->r15 != 0) {
        // 0x800141F4: lw          $t8, 0x1D4($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X1D4);
            goto L_80014204;
    }
    goto skip_1;
    // 0x800141F4: lw          $t8, 0x1D4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1D4);
    skip_1:
    // 0x800141F8: jr          $ra
    // 0x800141FC: addiu       $v0, $v1, 0xC8
    ctx->r2 = ADD32(ctx->r3, 0XC8);
    return;
    // 0x800141FC: addiu       $v0, $v1, 0xC8
    ctx->r2 = ADD32(ctx->r3, 0XC8);
    // 0x80014200: lw          $t8, 0x1D4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1D4);
L_80014204:
    // 0x80014204: bnel        $t8, $zero, L_80014218
    if (ctx->r24 != 0) {
        // 0x80014208: lw          $t9, 0x29C($v1)
        ctx->r25 = MEM_W(ctx->r3, 0X29C);
            goto L_80014218;
    }
    goto skip_2;
    // 0x80014208: lw          $t9, 0x29C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X29C);
    skip_2:
    // 0x8001420C: jr          $ra
    // 0x80014210: addiu       $v0, $v1, 0x190
    ctx->r2 = ADD32(ctx->r3, 0X190);
    return;
    // 0x80014210: addiu       $v0, $v1, 0x190
    ctx->r2 = ADD32(ctx->r3, 0X190);
    // 0x80014214: lw          $t9, 0x29C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X29C);
L_80014218:
    // 0x80014218: bnel        $t9, $zero, L_8001422C
    if (ctx->r25 != 0) {
        // 0x8001421C: addiu       $v1, $v1, 0x320
        ctx->r3 = ADD32(ctx->r3, 0X320);
            goto L_8001422C;
    }
    goto skip_3;
    // 0x8001421C: addiu       $v1, $v1, 0x320
    ctx->r3 = ADD32(ctx->r3, 0X320);
    skip_3:
    // 0x80014220: jr          $ra
    // 0x80014224: addiu       $v0, $v1, 0x258
    ctx->r2 = ADD32(ctx->r3, 0X258);
    return;
    // 0x80014224: addiu       $v0, $v1, 0x258
    ctx->r2 = ADD32(ctx->r3, 0X258);
    // 0x80014228: addiu       $v1, $v1, 0x320
    ctx->r3 = ADD32(ctx->r3, 0X320);
L_8001422C:
    // 0x8001422C: bnel        $v1, $v0, L_800141DC
    if (ctx->r3 != ctx->r2) {
        // 0x80014230: lw          $t6, 0x44($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X44);
            goto L_800141DC;
    }
    goto skip_4;
    // 0x80014230: lw          $t6, 0x44($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X44);
    skip_4:
    // 0x80014234: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80014238: addiu       $v0, $v0, 0x2FE8
    ctx->r2 = ADD32(ctx->r2, 0X2FE8);
    // 0x8001423C: jr          $ra
    // 0x80014240: nop

    return;
    // 0x80014240: nop

;}
RECOMP_FUNC void func_versus_800C0D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0D10: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C0D14: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x800C0D18: addiu       $t1, $t1, 0x4A90
    ctx->r9 = ADD32(ctx->r9, 0X4A90);
    // 0x800C0D1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C0D20: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800C0D24: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C0D28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800C0D2C: beq         $v0, $zero, L_800C0D50
    if (ctx->r2 == 0) {
        // 0x800C0D30: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800C0D50;
    }
    // 0x800C0D30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C0D34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C0D38: beq         $v0, $at, L_800C0D8C
    if (ctx->r2 == ctx->r1) {
        // 0x800C0D3C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C0D8C;
    }
    // 0x800C0D3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C0D40: beq         $v0, $at, L_800C0E38
    if (ctx->r2 == ctx->r1) {
        // 0x800C0D44: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800C0E38;
    }
    // 0x800C0D44: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C0D48: b           L_800C0E68
    // 0x800C0D4C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800C0E68;
    // 0x800C0D4C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800C0D50:
    // 0x800C0D50: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800C0D54: addiu       $v1, $v1, -0x77C8
    ctx->r3 = ADD32(ctx->r3, -0X77C8);
    // 0x800C0D58: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C0D5C: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800C0D60: sw          $zero, -0x77C8($at)
    MEM_W(-0X77C8, ctx->r1) = 0;
    // 0x800C0D64: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800C0D68: addiu       $a2, $a2, 0x4A94
    ctx->r6 = ADD32(ctx->r6, 0X4A94);
    // 0x800C0D6C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800C0D70: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800C0D74: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800C0D78: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C0D7C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C0D80: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800C0D84: b           L_800C0E64
    // 0x800C0D88: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_800C0E64;
    // 0x800C0D88: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_800C0D8C:
    // 0x800C0D8C: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800C0D90: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800C0D94: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x800C0D98: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800C0D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C0DA0: addiu       $a2, $a2, 0x4A94
    ctx->r6 = ADD32(ctx->r6, 0X4A94);
    // 0x800C0DA4: addiu       $a3, $a3, 0x7C38
    ctx->r7 = ADD32(ctx->r7, 0X7C38);
    // 0x800C0DA8: addiu       $v1, $v1, 0x7C30
    ctx->r3 = ADD32(ctx->r3, 0X7C30);
    // 0x800C0DAC: addiu       $v0, $v0, -0x77C8
    ctx->r2 = ADD32(ctx->r2, -0X77C8);
L_800C0DB0:
    // 0x800C0DB0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800C0DB4: lhu         $t8, 0x0($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X0);
    // 0x800C0DB8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800C0DBC: bnel        $t8, $a0, L_800C0DD0
    if (ctx->r24 != ctx->r4) {
        // 0x800C0DC0: lw          $t2, 0x0($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X0);
            goto L_800C0DD0;
    }
    goto skip_0;
    // 0x800C0DC0: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x800C0DC4: b           L_800C0DE0
    // 0x800C0DC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800C0DE0;
    // 0x800C0DC8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C0DCC: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
L_800C0DD0:
    // 0x800C0DD0: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800C0DD4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800C0DD8: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C0DDC: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
L_800C0DE0:
    // 0x800C0DE0: bne         $v1, $a3, L_800C0DB0
    if (ctx->r3 != ctx->r7) {
        // 0x800C0DE4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800C0DB0;
    }
    // 0x800C0DE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C0DE8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800C0DEC: bne         $a1, $at, L_800C0DFC
    if (ctx->r5 != ctx->r1) {
        // 0x800C0DF0: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_800C0DFC;
    }
    // 0x800C0DF0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800C0DF4: b           L_800C0E64
    // 0x800C0DF8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_800C0E64;
    // 0x800C0DF8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_800C0DFC:
    // 0x800C0DFC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800C0E00: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x800C0E04: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800C0E08: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x800C0E0C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x800C0E10: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800C0E14: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800C0E18: ori         $a0, $a0, 0x4007
    ctx->r4 = ctx->r4 | 0X4007;
    // 0x800C0E1C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800C0E20: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800C0E24: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800C0E28: jal         0x80019218
    // 0x800C0E2C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x800C0E2C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x800C0E30: b           L_800C0E64
    // 0x800C0E34: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
        goto L_800C0E64;
    // 0x800C0E34: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
L_800C0E38:
    // 0x800C0E38: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800C0E3C: addiu       $a2, $a2, 0x4A94
    ctx->r6 = ADD32(ctx->r6, 0X4A94);
    // 0x800C0E40: addiu       $v1, $v1, -0x77C8
    ctx->r3 = ADD32(ctx->r3, -0X77C8);
    // 0x800C0E44: lw          $v0, 0x10($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X10);
    // 0x800C0E48: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C0E4C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800C0E50: beql        $t6, $v0, L_800C0E64
    if (ctx->r14 == ctx->r2) {
        // 0x800C0E54: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C0E64;
    }
    goto skip_1;
    // 0x800C0E54: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    skip_1:
    // 0x800C0E58: b           L_800C0E64
    // 0x800C0E5C: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
        goto L_800C0E64;
    // 0x800C0E5C: sw          $t7, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r15;
    // 0x800C0E60: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_800C0E64:
    // 0x800C0E64: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800C0E68:
    // 0x800C0E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0E6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C0E70: jr          $ra
    // 0x800C0E74: nop

    return;
    // 0x800C0E74: nop

;}
RECOMP_FUNC void Audio_RestoreVolumeSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D780: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001D784: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x8001D788: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8001D78C: lbu         $v1, 0x5D68($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D68);
    // 0x8001D790: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8001D794: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D798: sll         $t7, $v1, 7
    ctx->r15 = S32(ctx->r3 << 7);
    // 0x8001D79C: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8001D7A0: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x8001D7A4: mflo        $t8
    ctx->r24 = lo;
    // 0x8001D7A8: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x8001D7AC: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x8001D7B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D7B4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001D7B8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001D7BC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8001D7C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001D7C4: beq         $t6, $zero, L_8001D7E8
    if (ctx->r14 == 0) {
        // 0x8001D7C8: sra         $v1, $t0, 24
        ctx->r3 = S32(SIGNED(ctx->r8) >> 24);
            goto L_8001D7E8;
    }
    // 0x8001D7C8: sra         $v1, $t0, 24
    ctx->r3 = S32(SIGNED(ctx->r8) >> 24);
    // 0x8001D7CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001D7D0: beq         $t6, $at, L_8001D868
    if (ctx->r14 == ctx->r1) {
        // 0x8001D7D4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001D868;
    }
    // 0x8001D7D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001D7D8: beql        $t6, $at, L_8001D820
    if (ctx->r14 == ctx->r1) {
        // 0x8001D7DC: mtc1        $v1, $f4
        ctx->f4.u32l = ctx->r3;
            goto L_8001D820;
    }
    goto skip_0;
    // 0x8001D7DC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    skip_0:
    // 0x8001D7E0: b           L_8001D894
    // 0x8001D7E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001D894;
    // 0x8001D7E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D7E8:
    // 0x8001D7E8: andi        $s0, $v1, 0xFF
    ctx->r16 = ctx->r3 & 0XFF;
    // 0x8001D7EC: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    // 0x8001D7F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001D7F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D7F8: jal         0x800185A0
    // 0x8001D7FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Audio_SetSequenceFade(rdram, ctx);
        goto after_0;
    // 0x8001D7FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8001D800: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001D804: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001D808: andi        $a2, $s0, 0xFF
    ctx->r6 = ctx->r16 & 0XFF;
    // 0x8001D80C: jal         0x800185A0
    // 0x8001D810: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Audio_SetSequenceFade(rdram, ctx);
        goto after_1;
    // 0x8001D810: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8001D814: b           L_8001D894
    // 0x8001D818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001D894;
    // 0x8001D818: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D81C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
L_8001D820:
    // 0x8001D820: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8001D824: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D828: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001D82C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001D830: lui         $s1, 0x202
    ctx->r17 = S32(0X202 << 16);
    // 0x8001D834: div.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
L_8001D838:
    // 0x8001D838: andi        $t2, $s0, 0xFF
    ctx->r10 = ctx->r16 & 0XFF;
    // 0x8001D83C: sll         $t3, $t2, 8
    ctx->r11 = S32(ctx->r10 << 8);
    // 0x8001D840: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8001D844: jal         0x8001E8A8
    // 0x8001D848: or          $a0, $t3, $s1
    ctx->r4 = ctx->r11 | ctx->r17;
    AudioThread_QueueCmdF32(rdram, ctx);
        goto after_2;
    // 0x8001D848: or          $a0, $t3, $s1
    ctx->r4 = ctx->r11 | ctx->r17;
    after_2:
    // 0x8001D84C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001D850: andi        $t4, $s0, 0xFF
    ctx->r12 = ctx->r16 & 0XFF;
    // 0x8001D854: slti        $at, $t4, 0xF
    ctx->r1 = SIGNED(ctx->r12) < 0XF ? 1 : 0;
    // 0x8001D858: bne         $at, $zero, L_8001D838
    if (ctx->r1 != 0) {
        // 0x8001D85C: or          $s0, $t4, $zero
        ctx->r16 = ctx->r12 | 0;
            goto L_8001D838;
    }
    // 0x8001D85C: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
    // 0x8001D860: b           L_8001D894
    // 0x8001D864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8001D894;
    // 0x8001D864: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D868:
    // 0x8001D868: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8001D86C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8001D870: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D874: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001D878: lui         $a0, 0x203
    ctx->r4 = S32(0X203 << 16);
    // 0x8001D87C: ori         $a0, $a0, 0xF00
    ctx->r4 = ctx->r4 | 0XF00;
    // 0x8001D880: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001D884: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8001D888: jal         0x8001E8A8
    // 0x8001D88C: nop

    AudioThread_QueueCmdF32(rdram, ctx);
        goto after_3;
    // 0x8001D88C: nop

    after_3:
    // 0x8001D890: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D894:
    // 0x8001D894: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8001D898: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D89C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D8A0: jr          $ra
    // 0x8001D8A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001D8A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Timer_SetValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000707C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x80007080: jr          $ra
    // 0x80007084: nop

    return;
    // 0x80007084: nop

;}
RECOMP_FUNC void PlayerShot_SpawnTorpedoTrail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035DEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035DF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035DF4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80035DF8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80035DFC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80035E00: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80035E04: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80035E08: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80035E0C:
    // 0x80035E0C: bnel        $t6, $zero, L_80035E30
    if (ctx->r14 != 0) {
        // 0x80035E10: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_80035E30;
    }
    goto skip_0;
    // 0x80035E10: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    skip_0:
    // 0x80035E14: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80035E18: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80035E1C: jal         0x80035D30
    // 0x80035E20: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    PlayerShot_TorpedoTrail_Setup(rdram, ctx);
        goto after_0;
    // 0x80035E20: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80035E24: b           L_80035E3C
    // 0x80035E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035E3C;
    // 0x80035E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035E2C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
L_80035E30:
    // 0x80035E30: bnel        $a0, $v0, L_80035E0C
    if (ctx->r4 != ctx->r2) {
        // 0x80035E34: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80035E0C;
    }
    goto skip_1;
    // 0x80035E34: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80035E38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035E3C:
    // 0x80035E3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035E40: jr          $ra
    // 0x80035E44: nop

    return;
    // 0x80035E44: nop

;}
RECOMP_FUNC void Camera_SetStarfieldPos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6F50: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B6F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B6F58: swc1        $f12, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f12.u32l;
    // 0x800B6F5C: swc1        $f14, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f14.u32l;
    // 0x800B6F60: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800B6F64: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800B6F68: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B6F6C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B6F70: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B6F74: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B6F78: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B6F7C: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B6F80: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x800B6F84: jal         0x80005100
    // 0x800B6F88: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x800B6F88: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800B6F8C: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800B6F90: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B6F94: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x800B6F98: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800B6F9C: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B6FA0: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B6FA4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B6FA8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x800B6FAC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B6FB0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B6FB4: jal         0x80005100
    // 0x800B6FB8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x800B6FB8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_1:
    // 0x800B6FBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6FC0: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800B6FC4: lwc1        $f6, -0x74E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X74E4);
    // 0x800B6FC8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800B6FCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6FD0: c.le.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl <= ctx->f16.fl;
    // 0x800B6FD4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800B6FD8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800B6FDC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800B6FE0: bc1f        L_800B6FF0
    if (!c1cs) {
        // 0x800B6FE4: nop
    
            goto L_800B6FF0;
    }
    // 0x800B6FE4: nop

    // 0x800B6FE8: lwc1        $f8, -0x74E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X74E0);
    // 0x800B6FEC: sub.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f8.fl;
L_800B6FF0:
    // 0x800B6FF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6FF4: lwc1        $f10, -0x74DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X74DC);
    // 0x800B6FF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6FFC: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x800B7000: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800B7004: bc1f        L_800B7014
    if (!c1cs) {
        // 0x800B7008: nop
    
            goto L_800B7014;
    }
    // 0x800B7008: nop

    // 0x800B700C: lwc1        $f4, -0x74D8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X74D8);
    // 0x800B7010: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_800B7014:
    // 0x800B7014: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x800B7018: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B701C: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800B7020: bne         $t6, $at, L_800B7040
    if (ctx->r14 != ctx->r1) {
        // 0x800B7024: nop
    
            goto L_800B7040;
    }
    // 0x800B7024: nop

    // 0x800B7028: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800B702C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7030: lwc1        $f8, -0x74D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X74D4);
    // 0x800B7034: lwc1        $f6, 0x44($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X44);
    // 0x800B7038: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B703C: nop

L_800B7040:
    // 0x800B7040: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7044: lwc1        $f6, -0x74D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X74D0);
    // 0x800B7048: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800B704C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7050: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B7054: lwc1        $f10, -0x74CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X74CC);
    // 0x800B7058: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B705C: lwc1        $f6, -0x7BD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7BD0);
    // 0x800B7060: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7064: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800B7068: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B706C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B7070: lwc1        $f4, -0x74C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X74C8);
    // 0x800B7074: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7078: mul.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800B707C: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B7080: lwc1        $f8, -0x74C4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X74C4);
    // 0x800B7084: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7088: lwc1        $f4, -0x7BD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7BD4);
    // 0x800B708C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x800B7090: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7094: add.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800B7098: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B709C: lwc1        $f6, -0x7BE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7BE0);
    // 0x800B70A0: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x800B70A4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B70A8: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B70AC: jal         0x80004E20
    // 0x800B70B0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Math_ModF(rdram, ctx);
        goto after_2;
    // 0x800B70B0: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800B70B4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B70B8: swc1        $f0, -0x7BE0($at)
    MEM_W(-0X7BE0, ctx->r1) = ctx->f0.u32l;
    // 0x800B70BC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800B70C0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B70C4: jal         0x80004E20
    // 0x800B70C8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    Math_ModF(rdram, ctx);
        goto after_3;
    // 0x800B70C8: lwc1        $f12, 0x30($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x800B70CC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B70D0: lw          $t8, 0x7834($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7834);
    // 0x800B70D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B70D8: swc1        $f0, -0x7BDC($at)
    MEM_W(-0X7BDC, ctx->r1) = ctx->f0.u32l;
    // 0x800B70DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800B70E0: bne         $t8, $at, L_800B7174
    if (ctx->r24 != ctx->r1) {
        // 0x800B70E4: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_800B7174;
    }
    // 0x800B70E4: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800B70E8: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x800B70EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B70F0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800B70F4: lw          $t0, 0x1C8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X1C8);
    // 0x800B70F8: bnel        $t0, $at, L_800B7178
    if (ctx->r8 != ctx->r1) {
        // 0x800B70FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B7178;
    }
    goto skip_0;
    // 0x800B70FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B7100: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x800B7104: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B7108: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800B710C: bne         $t1, $at, L_800B7174
    if (ctx->r9 != ctx->r1) {
        // 0x800B7110: lui         $at, 0x8018
        ctx->r1 = S32(0X8018 << 16);
            goto L_800B7174;
    }
    // 0x800B7110: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B7114: lwc1        $f8, -0x7BE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7BE0);
    // 0x800B7118: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800B711C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B7120: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B7124: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B7128: abs.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = fabsf(ctx->f2.fl);
    // 0x800B712C: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800B7130: nop

    // 0x800B7134: bc1fl       L_800B7178
    if (!c1cs) {
        // 0x800B7138: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B7178;
    }
    goto skip_1;
    // 0x800B7138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800B713C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800B7140: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B7144: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800B7148: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x800B714C: addiu       $v0, $v0, -0x694
    ctx->r2 = ADD32(ctx->r2, -0X694);
    // 0x800B7150: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x800B7154: bc1fl       L_800B7178
    if (!c1cs) {
        // 0x800B7158: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B7178;
    }
    goto skip_2;
    // 0x800B7158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x800B715C: sub.s       $f0, $f2, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800B7160: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B7164: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B7168: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800B716C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800B7170: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_800B7174:
    // 0x800B7174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B7178:
    // 0x800B7178: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800B717C: jr          $ra
    // 0x800B7180: nop

    return;
    // 0x800B7180: nop

;}
RECOMP_FUNC void Effect_Effect390_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C120: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C124: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007C128: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8007C12C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8007C130: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007C134: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007C138: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007C13C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007C140: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007C144:
    // 0x8007C144: bnel        $t6, $zero, L_8007C190
    if (ctx->r14 != 0) {
        // 0x8007C148: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007C190;
    }
    goto skip_0;
    // 0x8007C148: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007C14C: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007C150: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007C154: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007C158: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007C15C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007C160: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007C164: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007C168: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8007C16C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007C170: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007C174: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8007C178: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8007C17C: jal         0x8007C088
    // 0x8007C180: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    Effect_Effect390_Setup(rdram, ctx);
        goto after_0;
    // 0x8007C180: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007C184: b           L_8007C1A0
    // 0x8007C188: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8007C1A0;
    // 0x8007C188: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C18C: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007C190:
    // 0x8007C190: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007C194: beql        $at, $zero, L_8007C144
    if (ctx->r1 == 0) {
        // 0x8007C198: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007C144;
    }
    goto skip_1;
    // 0x8007C198: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007C19C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8007C1A0:
    // 0x8007C1A0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007C1A4: jr          $ra
    // 0x8007C1A8: nop

    return;
    // 0x8007C1A8: nop

;}
RECOMP_FUNC void Actor_CoRadar_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063CAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80063CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063CB4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80063CB8: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80063CBC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80063CC0: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80063CC4: addiu       $a2, $a2, 0x3FE0
    ctx->r6 = ADD32(ctx->r6, 0X3FE0);
    // 0x80063CC8: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
L_80063CCC:
    // 0x80063CCC: bne         $t6, $zero, L_80063D3C
    if (ctx->r14 != 0) {
        // 0x80063CD0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80063D3C;
    }
    // 0x80063CD0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80063CD4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80063CD8: jal         0x800613C4
    // 0x80063CDC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80063CDC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80063CE0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80063CE4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80063CE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80063CEC: addiu       $t8, $zero, 0xC1
    ctx->r24 = ADD32(0, 0XC1);
    // 0x80063CF0: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80063CF4: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x80063CF8: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80063CFC: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80063D00: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80063D04: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80063D08: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80063D0C: jal         0x80004EB0
    // 0x80063D10: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80063D10: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x80063D14: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80063D18: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80063D1C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80063D20: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80063D24: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80063D28: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x80063D2C: jal         0x800612B8
    // 0x80063D30: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_2;
    // 0x80063D30: swc1        $f16, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f16.u32l;
    after_2:
    // 0x80063D34: b           L_80063D4C
    // 0x80063D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80063D4C;
    // 0x80063D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80063D3C:
    // 0x80063D3C: addiu       $a2, $a2, 0x2F4
    ctx->r6 = ADD32(ctx->r6, 0X2F4);
    // 0x80063D40: bnel        $a2, $v0, L_80063CCC
    if (ctx->r6 != ctx->r2) {
        // 0x80063D44: lbu         $t6, 0x0($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X0);
            goto L_80063CCC;
    }
    goto skip_0;
    // 0x80063D44: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    skip_0:
    // 0x80063D48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80063D4C:
    // 0x80063D4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80063D50: jr          $ra
    // 0x80063D54: nop

    return;
    // 0x80063D54: nop

;}
RECOMP_FUNC void AudioThread_QueueCmdS32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E8CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E8D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E8D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001E8D8: jal         0x8001E850
    // 0x8001E8DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    AudioThread_QueueCmd(rdram, ctx);
        goto after_0;
    // 0x8001E8DC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8001E8E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001E8E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E8E8: jr          $ra
    // 0x8001E8EC: nop

    return;
    // 0x8001E8EC: nop

;}
RECOMP_FUNC void AudioSeq_SequencePlayerProcessSequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015FD4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80015FD8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80015FDC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80015FE0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80015FE4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80015FE8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80015FEC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80015FF0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80015FF4: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80015FF8: beql        $t7, $zero, L_80016774
    if (ctx->r15 == 0) {
        // 0x80015FFC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80016774;
    }
    goto skip_0;
    // 0x80015FFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80016000: lbu         $t8, 0x4($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X4);
    // 0x80016004: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x80016008: addiu       $t9, $t9, -0x2BD8
    ctx->r25 = ADD32(ctx->r25, -0X2BD8);
    // 0x8001600C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80016010: lbu         $a0, 0x0($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X0);
    // 0x80016014: slti        $t0, $a0, 0x2
    ctx->r8 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x80016018: bne         $t0, $zero, L_80016044
    if (ctx->r8 != 0) {
        // 0x8001601C: nop
    
            goto L_80016044;
    }
    // 0x8001601C: nop

    // 0x80016020: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
    // 0x80016024: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80016028: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001602C: beq         $v0, $at, L_80016054
    if (ctx->r2 == ctx->r1) {
        // 0x80016030: addu        $t1, $t1, $v0
        ctx->r9 = ADD32(ctx->r9, ctx->r2);
            goto L_80016054;
    }
    // 0x80016030: addu        $t1, $t1, $v0
    ctx->r9 = ADD32(ctx->r9, ctx->r2);
    // 0x80016034: lbu         $t1, -0x2C18($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X2C18);
    // 0x80016038: slti        $t2, $t1, 0x2
    ctx->r10 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8001603C: beql        $t2, $zero, L_80016058
    if (ctx->r10 == 0) {
        // 0x80016040: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_80016058;
    }
    goto skip_1;
    // 0x80016040: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    skip_1:
L_80016044:
    // 0x80016044: jal         0x800144E4
    // 0x80016048: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_SequencePlayerDisable(rdram, ctx);
        goto after_0;
    // 0x80016048: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8001604C: b           L_80016774
    // 0x80016050: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80016774;
    // 0x80016050: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016054:
    // 0x80016054: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_80016058:
    // 0x80016058: beq         $a1, $a0, L_8001606C
    if (ctx->r5 == ctx->r4) {
        // 0x8001605C: lui         $t4, 0x8015
        ctx->r12 = S32(0X8015 << 16);
            goto L_8001606C;
    }
    // 0x8001605C: lui         $t4, 0x8015
    ctx->r12 = S32(0X8015 << 16);
    // 0x80016060: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80016064: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80016068: lbu         $v0, 0x5($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X5);
L_8001606C:
    // 0x8001606C: addiu       $t4, $t4, -0x2C18
    ctx->r12 = ADD32(ctx->r12, -0X2C18);
    // 0x80016070: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x80016074: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x80016078: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8001607C: beql        $a1, $t5, L_8001608C
    if (ctx->r5 == ctx->r13) {
        // 0x80016080: lw          $t7, 0x0($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X0);
            goto L_8001608C;
    }
    goto skip_2;
    // 0x80016080: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80016084: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80016088: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
L_8001608C:
    // 0x8001608C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80016090: bgezl       $t9, L_800160AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80016094: lhu         $t2, 0xA($s1)
        ctx->r10 = MEM_HU(ctx->r17, 0XA);
            goto L_800160AC;
    }
    goto skip_3;
    // 0x80016094: lhu         $t2, 0xA($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XA);
    skip_3:
    // 0x80016098: lbu         $t0, 0x3($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X3);
    // 0x8001609C: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x800160A0: bnel        $t1, $zero, L_80016774
    if (ctx->r9 != 0) {
        // 0x800160A4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80016774;
    }
    goto skip_4;
    // 0x800160A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x800160A8: lhu         $t2, 0xA($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0XA);
L_800160AC:
    // 0x800160AC: lhu         $t3, 0x8($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X8);
    // 0x800160B0: lh          $t6, 0xC($s1)
    ctx->r14 = MEM_H(ctx->r17, 0XC);
    // 0x800160B4: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x800160B8: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x800160BC: sh          $t5, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r13;
    // 0x800160C0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800160C4: sh          $t7, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r15;
    // 0x800160C8: lh          $a0, 0x5CA4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X5CA4);
    // 0x800160CC: andi        $v0, $t7, 0xFFFF
    ctx->r2 = ctx->r15 & 0XFFFF;
    // 0x800160D0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800160D4: bnel        $at, $zero, L_80016774
    if (ctx->r1 != 0) {
        // 0x800160D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80016774;
    }
    goto skip_5;
    // 0x800160D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x800160DC: lhu         $v1, 0x10($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X10);
    // 0x800160E0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x800160E4: sh          $t9, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r25;
    // 0x800160E8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800160EC: bne         $at, $zero, L_800160FC
    if (ctx->r1 != 0) {
        // 0x800160F0: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_800160FC;
    }
    // 0x800160F0: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x800160F4: b           L_80016724
    // 0x800160F8: sh          $t0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r8;
        goto L_80016724;
    // 0x800160F8: sh          $t0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r8;
L_800160FC:
    // 0x800160FC: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80016100: addiu       $s0, $s1, 0x74
    ctx->r16 = ADD32(ctx->r17, 0X74);
    // 0x80016104: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80016108: sb          $t3, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r11;
    // 0x8001610C: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
L_80016110:
    // 0x80016110: jal         0x800146C0
    // 0x80016114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_1;
    // 0x80016114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80016118: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001611C: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80016120: bne         $v0, $at, L_8001615C
    if (ctx->r2 != ctx->r1) {
        // 0x80016124: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8001615C;
    }
    // 0x80016124: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80016128: lbu         $a0, 0x18($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X18);
    // 0x8001612C: bne         $a0, $zero, L_80016144
    if (ctx->r4 != 0) {
        // 0x80016130: addiu       $v1, $a0, -0x1
        ctx->r3 = ADD32(ctx->r4, -0X1);
            goto L_80016144;
    }
    // 0x80016130: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x80016134: jal         0x800144E4
    // 0x80016138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    AudioSeq_SequencePlayerDisable(rdram, ctx);
        goto after_2;
    // 0x80016138: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8001613C: b           L_80016724
    // 0x80016140: nop

        goto L_80016724;
    // 0x80016140: nop

L_80016144:
    // 0x80016144: andi        $t4, $v1, 0xFF
    ctx->r12 = ctx->r3 & 0XFF;
    // 0x80016148: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8001614C: addu        $t6, $s0, $t5
    ctx->r14 = ADD32(ctx->r16, ctx->r13);
    // 0x80016150: sb          $t4, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r12;
    // 0x80016154: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80016158: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8001615C:
    // 0x8001615C: addiu       $at, $zero, 0xFD
    ctx->r1 = ADD32(0, 0XFD);
    // 0x80016160: bne         $a1, $at, L_80016178
    if (ctx->r5 != ctx->r1) {
        // 0x80016164: andi        $v1, $a1, 0xF0
        ctx->r3 = ctx->r5 & 0XF0;
            goto L_80016178;
    }
    // 0x80016164: andi        $v1, $a1, 0xF0
    ctx->r3 = ctx->r5 & 0XF0;
    // 0x80016168: jal         0x80014704
    // 0x8001616C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadCompressedU16(rdram, ctx);
        goto after_3;
    // 0x8001616C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80016170: b           L_80016724
    // 0x80016174: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
        goto L_80016724;
    // 0x80016174: sh          $v0, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r2;
L_80016178:
    // 0x80016178: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x8001617C: bne         $a1, $at, L_80016190
    if (ctx->r5 != ctx->r1) {
        // 0x80016180: addiu       $t9, $a1, -0xC7
        ctx->r25 = ADD32(ctx->r5, -0XC7);
            goto L_80016190;
    }
    // 0x80016180: addiu       $t9, $a1, -0xC7
    ctx->r25 = ADD32(ctx->r5, -0XC7);
    // 0x80016184: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80016188: b           L_80016724
    // 0x8001618C: sh          $t8, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r24;
        goto L_80016724;
    // 0x8001618C: sh          $t8, 0x10($s1)
    MEM_H(0X10, ctx->r17) = ctx->r24;
L_80016190:
    // 0x80016190: slti        $at, $a1, 0xC0
    ctx->r1 = SIGNED(ctx->r5) < 0XC0 ? 1 : 0;
    // 0x80016194: bne         $at, $zero, L_80016658
    if (ctx->r1 != 0) {
        // 0x80016198: sltiu       $at, $t9, 0x39
        ctx->r1 = ctx->r25 < 0X39 ? 1 : 0;
            goto L_80016658;
    }
    // 0x80016198: sltiu       $at, $t9, 0x39
    ctx->r1 = ctx->r25 < 0X39 ? 1 : 0;
    // 0x8001619C: beq         $at, $zero, L_80016110
    if (ctx->r1 == 0) {
        // 0x800161A0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80016110;
    }
    // 0x800161A0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800161A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800161A8: addu        $at, $at, $t9
    gpr jr_addend_800161B0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800161AC: lw          $t9, -0x749C($at)
    ctx->r25 = ADD32(ctx->r1, -0X749C);
    // 0x800161B0: jr          $t9
    // 0x800161B4: nop

    switch (jr_addend_800161B0 >> 2) {
        case 0: goto L_80016620; break;
        case 1: goto L_80016610; break;
        case 2: goto L_80016600; break;
        case 3: goto L_80016110; break;
        case 4: goto L_80016110; break;
        case 5: goto L_800165F0; break;
        case 6: goto L_80016110; break;
        case 7: goto L_80016110; break;
        case 8: goto L_80016110; break;
        case 9: goto L_800165E0; break;
        case 10: goto L_800165B4; break;
        case 11: goto L_800165B4; break;
        case 12: goto L_800165A4; break;
        case 13: goto L_80016594; break;
        case 14: goto L_80016568; break;
        case 15: goto L_8001654C; break;
        case 16: goto L_80016530; break;
        case 17: goto L_80016110; break;
        case 18: goto L_80016504; break;
        case 19: goto L_800163F0; break;
        case 20: goto L_8001646C; break;
        case 21: goto L_800163CC; break;
        case 22: goto L_80016378; break;
        case 23: goto L_80016358; break;
        case 24: goto L_80016354; break;
        case 25: goto L_80016110; break;
        case 26: goto L_80016110; break;
        case 27: goto L_80016110; break;
        case 28: goto L_80016110; break;
        case 29: goto L_80016110; break;
        case 30: goto L_80016110; break;
        case 31: goto L_80016110; break;
        case 32: goto L_80016110; break;
        case 33: goto L_80016110; break;
        case 34: goto L_80016110; break;
        case 35: goto L_80016110; break;
        case 36: goto L_80016110; break;
        case 37: goto L_80016110; break;
        case 38: goto L_80016110; break;
        case 39: goto L_80016110; break;
        case 40: goto L_80016110; break;
        case 41: goto L_80016344; break;
        case 42: goto L_8001631C; break;
        case 43: goto L_800162D4; break;
        case 44: goto L_800162D4; break;
        case 45: goto L_800162D4; break;
        case 46: goto L_8001627C; break;
        case 47: goto L_80016110; break;
        case 48: goto L_80016234; break;
        case 49: goto L_800161FC; break;
        case 50: goto L_8001627C; break;
        case 51: goto L_8001627C; break;
        case 52: goto L_8001627C; break;
        case 53: goto L_800161B8; break;
        case 54: goto L_80016110; break;
        case 55: goto L_80016110; break;
        case 56: goto L_80016110; break;
        default: switch_error(__func__, 0x800161B0, 0x800C8B64);
    }
    // 0x800161B4: nop

L_800161B8:
    // 0x800161B8: jal         0x800146D4
    // 0x800161BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_4;
    // 0x800161BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800161C0: lbu         $t1, 0x18($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X18);
    // 0x800161C4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800161C8: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x800161CC: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800161D0: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x800161D4: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800161D8: lbu         $t4, 0x18($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X18);
    // 0x800161DC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800161E0: sb          $t5, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r13;
    // 0x800161E4: lw          $t6, 0x18($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X18);
    // 0x800161E8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800161EC: b           L_80016110
    // 0x800161F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_80016110;
    // 0x800161F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800161F4: b           L_80016110
    // 0x800161F8: nop

        goto L_80016110;
    // 0x800161F8: nop

L_800161FC:
    // 0x800161FC: jal         0x800146C0
    // 0x80016200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_5;
    // 0x80016200: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80016204: lbu         $t9, 0x18($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18);
    // 0x80016208: addu        $t1, $s0, $t9
    ctx->r9 = ADD32(ctx->r16, ctx->r25);
    // 0x8001620C: sb          $v0, 0x14($t1)
    MEM_B(0X14, ctx->r9) = ctx->r2;
    // 0x80016210: lbu         $t0, 0x18($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X18);
    // 0x80016214: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80016218: sll         $t3, $t0, 2
    ctx->r11 = S32(ctx->r8 << 2);
    // 0x8001621C: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80016220: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x80016224: lbu         $t5, 0x18($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X18);
    // 0x80016228: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001622C: b           L_80016110
    // 0x80016230: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
        goto L_80016110;
    // 0x80016230: sb          $t6, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r14;
L_80016234:
    // 0x80016234: lbu         $t7, 0x18($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18);
    // 0x80016238: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
    // 0x8001623C: lbu         $t8, 0x13($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X13);
    // 0x80016240: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80016244: sb          $t9, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r25;
    // 0x80016248: lbu         $a0, 0x18($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X18);
    // 0x8001624C: addu        $t1, $s0, $a0
    ctx->r9 = ADD32(ctx->r16, ctx->r4);
    // 0x80016250: lbu         $t0, 0x13($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X13);
    // 0x80016254: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80016258: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8001625C: beq         $t0, $zero, L_80016274
    if (ctx->r8 == 0) {
        // 0x80016260: addiu       $t5, $a0, -0x1
        ctx->r13 = ADD32(ctx->r4, -0X1);
            goto L_80016274;
    }
    // 0x80016260: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x80016264: addu        $t2, $s0, $t3
    ctx->r10 = ADD32(ctx->r16, ctx->r11);
    // 0x80016268: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8001626C: b           L_80016110
    // 0x80016270: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_80016110;
    // 0x80016270: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_80016274:
    // 0x80016274: b           L_80016110
    // 0x80016278: sb          $t5, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r13;
        goto L_80016110;
    // 0x80016278: sb          $t5, 0x18($s0)
    MEM_B(0X18, ctx->r16) = ctx->r13;
L_8001627C:
    // 0x8001627C: jal         0x800146D4
    // 0x80016280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_6;
    // 0x80016280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80016284: addiu       $at, $zero, 0xFA
    ctx->r1 = ADD32(0, 0XFA);
    // 0x80016288: bne         $s2, $at, L_80016298
    if (ctx->r18 != ctx->r1) {
        // 0x8001628C: or          $v1, $s2, $zero
        ctx->r3 = ctx->r18 | 0;
            goto L_80016298;
    }
    // 0x8001628C: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x80016290: bne         $s3, $zero, L_80016110
    if (ctx->r19 != 0) {
        // 0x80016294: nop
    
            goto L_80016110;
    }
    // 0x80016294: nop

L_80016298:
    // 0x80016298: addiu       $at, $zero, 0xF9
    ctx->r1 = ADD32(0, 0XF9);
    // 0x8001629C: bnel        $v1, $at, L_800162B0
    if (ctx->r3 != ctx->r1) {
        // 0x800162A0: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_800162B0;
    }
    goto skip_6;
    // 0x800162A0: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    skip_6:
    // 0x800162A4: bgez        $s3, L_80016110
    if (SIGNED(ctx->r19) >= 0) {
        // 0x800162A8: nop
    
            goto L_80016110;
    }
    // 0x800162A8: nop

    // 0x800162AC: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
L_800162B0:
    // 0x800162B0: bnel        $v1, $at, L_800162C4
    if (ctx->r3 != ctx->r1) {
        // 0x800162B4: lw          $t6, 0x18($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X18);
            goto L_800162C4;
    }
    goto skip_7;
    // 0x800162B4: lw          $t6, 0x18($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X18);
    skip_7:
    // 0x800162B8: bltz        $s3, L_80016110
    if (SIGNED(ctx->r19) < 0) {
        // 0x800162BC: nop
    
            goto L_80016110;
    }
    // 0x800162BC: nop

    // 0x800162C0: lw          $t6, 0x18($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X18);
L_800162C4:
    // 0x800162C4: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x800162C8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800162CC: b           L_80016110
    // 0x800162D0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_80016110;
    // 0x800162D0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800162D4:
    // 0x800162D4: jal         0x800146C0
    // 0x800162D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_7;
    // 0x800162D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800162DC: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    // 0x800162E0: bne         $s2, $at, L_800162F0
    if (ctx->r18 != ctx->r1) {
        // 0x800162E4: or          $v1, $s2, $zero
        ctx->r3 = ctx->r18 | 0;
            goto L_800162F0;
    }
    // 0x800162E4: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x800162E8: bne         $s3, $zero, L_80016110
    if (ctx->r19 != 0) {
        // 0x800162EC: nop
    
            goto L_80016110;
    }
    // 0x800162EC: nop

L_800162F0:
    // 0x800162F0: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    // 0x800162F4: bnel        $v1, $at, L_80016308
    if (ctx->r3 != ctx->r1) {
        // 0x800162F8: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_80016308;
    }
    goto skip_8;
    // 0x800162F8: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_8:
    // 0x800162FC: bgez        $s3, L_80016110
    if (SIGNED(ctx->r19) >= 0) {
        // 0x80016300: nop
    
            goto L_80016110;
    }
    // 0x80016300: nop

    // 0x80016304: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_80016308:
    // 0x80016308: sll         $t1, $v0, 24
    ctx->r9 = S32(ctx->r2 << 24);
    // 0x8001630C: sra         $t0, $t1, 24
    ctx->r8 = S32(SIGNED(ctx->r9) >> 24);
    // 0x80016310: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x80016314: b           L_80016110
    // 0x80016318: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_80016110;
    // 0x80016318: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_8001631C:
    // 0x8001631C: addiu       $a0, $s1, 0x98
    ctx->r4 = ADD32(ctx->r17, 0X98);
    // 0x80016320: jal         0x80012964
    // 0x80016324: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    Audio_NotePoolClear(rdram, ctx);
        goto after_8;
    // 0x80016324: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_8:
    // 0x80016328: jal         0x800146C0
    // 0x8001632C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_9;
    // 0x8001632C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80016330: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80016334: jal         0x80012AC4
    // 0x80016338: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    Audio_NotePoolFill(rdram, ctx);
        goto after_10;
    // 0x80016338: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x8001633C: b           L_80016110
    // 0x80016340: nop

        goto L_80016110;
    // 0x80016340: nop

L_80016344:
    // 0x80016344: jal         0x80012964
    // 0x80016348: addiu       $a0, $s1, 0x98
    ctx->r4 = ADD32(ctx->r17, 0X98);
    Audio_NotePoolClear(rdram, ctx);
        goto after_11;
    // 0x80016348: addiu       $a0, $s1, 0x98
    ctx->r4 = ADD32(ctx->r17, 0X98);
    after_11:
    // 0x8001634C: b           L_80016110
    // 0x80016350: nop

        goto L_80016110;
    // 0x80016350: nop

L_80016354:
    // 0x80016354: sh          $zero, 0xE($s1)
    MEM_H(0XE, ctx->r17) = 0;
L_80016358:
    // 0x80016358: jal         0x800146C0
    // 0x8001635C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_12;
    // 0x8001635C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80016360: lh          $t2, 0xE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XE);
    // 0x80016364: sll         $t4, $v0, 24
    ctx->r12 = S32(ctx->r2 << 24);
    // 0x80016368: sra         $t5, $t4, 24
    ctx->r13 = S32(SIGNED(ctx->r12) >> 24);
    // 0x8001636C: addu        $t6, $t2, $t5
    ctx->r14 = ADD32(ctx->r10, ctx->r13);
    // 0x80016370: b           L_80016110
    // 0x80016374: sh          $t6, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r14;
        goto L_80016110;
    // 0x80016374: sh          $t6, 0xE($s1)
    MEM_H(0XE, ctx->r17) = ctx->r14;
L_80016378:
    // 0x80016378: jal         0x800146C0
    // 0x8001637C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_13;
    // 0x8001637C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80016380: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80016384: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x80016388: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8001638C: sh          $t7, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r15;
    // 0x80016390: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x80016394: lh          $a0, 0x5CA4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X5CA4);
    // 0x80016398: andi        $v1, $t7, 0xFFFF
    ctx->r3 = ctx->r15 & 0XFFFF;
    // 0x8001639C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800163A0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800163A4: beql        $at, $zero, L_800163B8
    if (ctx->r1 == 0) {
        // 0x800163A8: sll         $t8, $v1, 16
        ctx->r24 = S32(ctx->r3 << 16);
            goto L_800163B8;
    }
    goto skip_9;
    // 0x800163A8: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    skip_9:
    // 0x800163AC: sh          $a0, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r4;
    // 0x800163B0: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x800163B4: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
L_800163B8:
    // 0x800163B8: sra         $t1, $t8, 16
    ctx->r9 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800163BC: bgtz        $t1, L_80016110
    if (SIGNED(ctx->r9) > 0) {
        // 0x800163C0: nop
    
            goto L_80016110;
    }
    // 0x800163C0: nop

    // 0x800163C4: b           L_80016110
    // 0x800163C8: sh          $t9, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r25;
        goto L_80016110;
    // 0x800163C8: sh          $t9, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r25;
L_800163CC:
    // 0x800163CC: jal         0x800146C0
    // 0x800163D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_14;
    // 0x800163D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800163D4: sll         $t0, $v0, 24
    ctx->r8 = S32(ctx->r2 << 24);
    // 0x800163D8: sra         $t3, $t0, 24
    ctx->r11 = S32(SIGNED(ctx->r8) >> 24);
    // 0x800163DC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800163E0: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800163E4: sll         $t4, $t4, 4
    ctx->r12 = S32(ctx->r12 << 4);
    // 0x800163E8: b           L_80016110
    // 0x800163EC: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
        goto L_80016110;
    // 0x800163EC: sh          $t4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r12;
L_800163F0:
    // 0x800163F0: jal         0x800146C0
    // 0x800163F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_15;
    // 0x800163F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x800163F8: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x800163FC: jal         0x800146D4
    // 0x80016400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_16;
    // 0x80016400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x80016404: beq         $s2, $zero, L_80016428
    if (ctx->r18 == 0) {
        // 0x80016408: or          $v1, $s2, $zero
        ctx->r3 = ctx->r18 | 0;
            goto L_80016428;
    }
    // 0x80016408: or          $v1, $s2, $zero
    ctx->r3 = ctx->r18 | 0;
    // 0x8001640C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016410: beq         $v1, $at, L_80016428
    if (ctx->r3 == ctx->r1) {
        // 0x80016414: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80016428;
    }
    // 0x80016414: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80016418: beq         $v1, $at, L_80016444
    if (ctx->r3 == ctx->r1) {
        // 0x8001641C: andi        $t5, $v0, 0xFFFF
        ctx->r13 = ctx->r2 & 0XFFFF;
            goto L_80016444;
    }
    // 0x8001641C: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x80016420: b           L_80016110
    // 0x80016424: nop

        goto L_80016110;
    // 0x80016424: nop

L_80016428:
    // 0x80016428: lbu         $t2, 0x1($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X1);
    // 0x8001642C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80016430: beq         $t2, $at, L_80016110
    if (ctx->r10 == ctx->r1) {
        // 0x80016434: nop
    
            goto L_80016110;
    }
    // 0x80016434: nop

    // 0x80016438: sh          $v0, 0x14($s1)
    MEM_H(0X14, ctx->r17) = ctx->r2;
    // 0x8001643C: b           L_80016110
    // 0x80016440: sb          $s2, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r18;
        goto L_80016110;
    // 0x80016440: sb          $s2, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r18;
L_80016444:
    // 0x80016444: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80016448: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001644C: lwc1        $f6, 0x1C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x80016450: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80016454: sh          $v0, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r2;
    // 0x80016458: sb          $s2, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r18;
    // 0x8001645C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80016460: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80016464: b           L_80016110
    // 0x80016468: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
        goto L_80016110;
    // 0x80016468: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
L_8001646C:
    // 0x8001646C: jal         0x800146C0
    // 0x80016470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_17;
    // 0x80016470: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80016474: lbu         $v1, 0x1($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X1);
    // 0x80016478: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001647C: beql        $v1, $zero, L_800164AC
    if (ctx->r3 == 0) {
        // 0x80016480: lhu         $v1, 0x14($s1)
        ctx->r3 = MEM_HU(ctx->r17, 0X14);
            goto L_800164AC;
    }
    goto skip_10;
    // 0x80016480: lhu         $v1, 0x14($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X14);
    skip_10:
    // 0x80016484: beq         $v1, $at, L_8001649C
    if (ctx->r3 == ctx->r1) {
        // 0x80016488: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001649C;
    }
    // 0x80016488: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001648C: beq         $v1, $at, L_80016110
    if (ctx->r3 == ctx->r1) {
        // 0x80016490: nop
    
            goto L_80016110;
    }
    // 0x80016490: nop

    // 0x80016494: b           L_80016110
    // 0x80016498: nop

        goto L_80016110;
    // 0x80016498: nop

L_8001649C:
    // 0x8001649C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800164A0: sb          $zero, 0x1($s1)
    MEM_B(0X1, ctx->r17) = 0;
    // 0x800164A4: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
    // 0x800164A8: lhu         $v1, 0x14($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X14);
L_800164AC:
    // 0x800164AC: beq         $v1, $zero, L_800164E8
    if (ctx->r3 == 0) {
        // 0x800164B0: sh          $v1, 0x12($s1)
        MEM_H(0X12, ctx->r17) = ctx->r3;
            goto L_800164E8;
    }
    // 0x800164B0: sh          $v1, 0x12($s1)
    MEM_H(0X12, ctx->r17) = ctx->r3;
    // 0x800164B4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800164B8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800164BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800164C0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800164C4: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800164C8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800164CC: lwc1        $f18, 0x1C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x800164D0: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800164D4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800164D8: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800164DC: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800164E0: b           L_80016110
    // 0x800164E4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
        goto L_80016110;
    // 0x800164E4: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
L_800164E8:
    // 0x800164E8: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800164EC: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800164F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800164F4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800164F8: div.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800164FC: b           L_80016110
    // 0x80016500: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
        goto L_80016110;
    // 0x80016500: swc1        $f4, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f4.u32l;
L_80016504:
    // 0x80016504: jal         0x800146C0
    // 0x80016508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_18;
    // 0x80016508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8001650C: sll         $t7, $v0, 24
    ctx->r15 = S32(ctx->r2 << 24);
    // 0x80016510: sra         $t8, $t7, 24
    ctx->r24 = S32(SIGNED(ctx->r15) >> 24);
    // 0x80016514: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80016518: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8001651C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80016520: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80016524: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80016528: b           L_80016110
    // 0x8001652C: swc1        $f18, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f18.u32l;
        goto L_80016110;
    // 0x8001652C: swc1        $f18, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f18.u32l;
L_80016530:
    // 0x80016530: jal         0x800146D4
    // 0x80016534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_19;
    // 0x80016534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80016538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001653C: jal         0x80014244
    // 0x80016540: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    AudioSeq_SequencePlayerSetupChannels(rdram, ctx);
        goto after_20;
    // 0x80016540: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_20:
    // 0x80016544: b           L_80016110
    // 0x80016548: nop

        goto L_80016110;
    // 0x80016548: nop

L_8001654C:
    // 0x8001654C: jal         0x800146D4
    // 0x80016550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_21;
    // 0x80016550: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x80016554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80016558: jal         0x80014370
    // 0x8001655C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    AudioSeq_SequencePlayerDisableChannels(rdram, ctx);
        goto after_22;
    // 0x8001655C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    after_22:
    // 0x80016560: b           L_80016110
    // 0x80016564: nop

        goto L_80016110;
    // 0x80016564: nop

L_80016568:
    // 0x80016568: jal         0x800146C0
    // 0x8001656C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_23;
    // 0x8001656C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_23:
    // 0x80016570: sll         $t1, $v0, 24
    ctx->r9 = S32(ctx->r2 << 24);
    // 0x80016574: sra         $t9, $t1, 24
    ctx->r25 = S32(SIGNED(ctx->r9) >> 24);
    // 0x80016578: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8001657C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80016580: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80016584: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80016588: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8001658C: b           L_80016110
    // 0x80016590: swc1        $f8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f8.u32l;
        goto L_80016110;
    // 0x80016590: swc1        $f8, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f8.u32l;
L_80016594:
    // 0x80016594: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x80016598: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8001659C: b           L_80016110
    // 0x800165A0: sb          $t4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r12;
        goto L_80016110;
    // 0x800165A0: sb          $t4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r12;
L_800165A4:
    // 0x800165A4: jal         0x800146C0
    // 0x800165A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_24;
    // 0x800165A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800165AC: b           L_80016110
    // 0x800165B0: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
        goto L_80016110;
    // 0x800165B0: sb          $v0, 0x3($s1)
    MEM_B(0X3, ctx->r17) = ctx->r2;
L_800165B4:
    // 0x800165B4: jal         0x800146D4
    // 0x800165B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_25;
    // 0x800165B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x800165BC: lw          $t2, 0x18($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X18);
    // 0x800165C0: andi        $t5, $v0, 0xFFFF
    ctx->r13 = ctx->r2 & 0XFFFF;
    // 0x800165C4: addiu       $at, $zero, 0xD2
    ctx->r1 = ADD32(0, 0XD2);
    // 0x800165C8: bne         $s2, $at, L_800165D8
    if (ctx->r18 != ctx->r1) {
        // 0x800165CC: addu        $v1, $t2, $t5
        ctx->r3 = ADD32(ctx->r10, ctx->r13);
            goto L_800165D8;
    }
    // 0x800165CC: addu        $v1, $t2, $t5
    ctx->r3 = ADD32(ctx->r10, ctx->r13);
    // 0x800165D0: b           L_80016110
    // 0x800165D4: sw          $v1, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r3;
        goto L_80016110;
    // 0x800165D4: sw          $v1, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r3;
L_800165D8:
    // 0x800165D8: b           L_80016110
    // 0x800165DC: sw          $v1, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r3;
        goto L_80016110;
    // 0x800165DC: sw          $v1, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r3;
L_800165E0:
    // 0x800165E0: jal         0x800146C0
    // 0x800165E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_26;
    // 0x800165E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_26:
    // 0x800165E8: b           L_80016110
    // 0x800165EC: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
        goto L_80016110;
    // 0x800165EC: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
L_800165F0:
    // 0x800165F0: jal         0x800146C0
    // 0x800165F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_27;
    // 0x800165F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x800165F8: b           L_80016110
    // 0x800165FC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
        goto L_80016110;
    // 0x800165FC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_80016600:
    // 0x80016600: jal         0x800146C0
    // 0x80016604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_28;
    // 0x80016604: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_28:
    // 0x80016608: b           L_80016110
    // 0x8001660C: and         $s3, $s3, $v0
    ctx->r19 = ctx->r19 & ctx->r2;
        goto L_80016110;
    // 0x8001660C: and         $s3, $s3, $v0
    ctx->r19 = ctx->r19 & ctx->r2;
L_80016610:
    // 0x80016610: jal         0x800146C0
    // 0x80016614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_29;
    // 0x80016614: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x80016618: b           L_80016110
    // 0x8001661C: subu        $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
        goto L_80016110;
    // 0x8001661C: subu        $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
L_80016620:
    // 0x80016620: andi        $t6, $s3, 0xFF
    ctx->r14 = ctx->r19 & 0XFF;
    // 0x80016624: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80016628: jal         0x800146C0
    // 0x8001662C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadU8(rdram, ctx);
        goto after_30;
    // 0x8001662C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x80016630: andi        $s2, $v0, 0xFF
    ctx->r18 = ctx->r2 & 0XFF;
    // 0x80016634: jal         0x800146D4
    // 0x80016638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_31;
    // 0x80016638: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_31:
    // 0x8001663C: lw          $t7, 0x18($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X18);
    // 0x80016640: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80016644: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x80016648: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8001664C: addu        $t9, $t1, $s2
    ctx->r25 = ADD32(ctx->r9, ctx->r18);
    // 0x80016650: b           L_80016110
    // 0x80016654: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
        goto L_80016110;
    // 0x80016654: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
L_80016658:
    // 0x80016658: slti        $at, $v1, 0x11
    ctx->r1 = SIGNED(ctx->r3) < 0X11 ? 1 : 0;
    // 0x8001665C: bne         $at, $zero, L_800166A0
    if (ctx->r1 != 0) {
        // 0x80016660: slti        $at, $v1, 0x21
        ctx->r1 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
            goto L_800166A0;
    }
    // 0x80016660: slti        $at, $v1, 0x21
    ctx->r1 = SIGNED(ctx->r3) < 0X21 ? 1 : 0;
    // 0x80016664: bne         $at, $zero, L_8001668C
    if (ctx->r1 != 0) {
        // 0x80016668: addiu       $t0, $v1, -0x40
        ctx->r8 = ADD32(ctx->r3, -0X40);
            goto L_8001668C;
    }
    // 0x80016668: addiu       $t0, $v1, -0x40
    ctx->r8 = ADD32(ctx->r3, -0X40);
    // 0x8001666C: sltiu       $at, $t0, 0x61
    ctx->r1 = ctx->r8 < 0X61 ? 1 : 0;
    // 0x80016670: beq         $at, $zero, L_80016110
    if (ctx->r1 == 0) {
        // 0x80016674: sll         $t0, $t0, 2
        ctx->r8 = S32(ctx->r8 << 2);
            goto L_80016110;
    }
    // 0x80016674: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80016678: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001667C: addu        $at, $at, $t0
    gpr jr_addend_80016684 = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80016680: lw          $t0, -0x73B8($at)
    ctx->r8 = ADD32(ctx->r1, -0X73B8);
    // 0x80016684: jr          $t0
    // 0x80016688: nop

    switch (jr_addend_80016684 >> 2) {
        case 0: goto L_80016110; break;
        case 1: goto L_80016110; break;
        case 2: goto L_80016110; break;
        case 3: goto L_80016110; break;
        case 4: goto L_80016110; break;
        case 5: goto L_80016110; break;
        case 6: goto L_80016110; break;
        case 7: goto L_80016110; break;
        case 8: goto L_80016110; break;
        case 9: goto L_80016110; break;
        case 10: goto L_80016110; break;
        case 11: goto L_80016110; break;
        case 12: goto L_80016110; break;
        case 13: goto L_80016110; break;
        case 14: goto L_80016110; break;
        case 15: goto L_80016110; break;
        case 16: goto L_800166D8; break;
        case 17: goto L_80016110; break;
        case 18: goto L_80016110; break;
        case 19: goto L_80016110; break;
        case 20: goto L_80016110; break;
        case 21: goto L_80016110; break;
        case 22: goto L_80016110; break;
        case 23: goto L_80016110; break;
        case 24: goto L_80016110; break;
        case 25: goto L_80016110; break;
        case 26: goto L_80016110; break;
        case 27: goto L_80016110; break;
        case 28: goto L_80016110; break;
        case 29: goto L_80016110; break;
        case 30: goto L_80016110; break;
        case 31: goto L_80016110; break;
        case 32: goto L_80016110; break;
        case 33: goto L_80016110; break;
        case 34: goto L_80016110; break;
        case 35: goto L_80016110; break;
        case 36: goto L_80016110; break;
        case 37: goto L_80016110; break;
        case 38: goto L_80016110; break;
        case 39: goto L_80016110; break;
        case 40: goto L_80016110; break;
        case 41: goto L_80016110; break;
        case 42: goto L_80016110; break;
        case 43: goto L_80016110; break;
        case 44: goto L_80016110; break;
        case 45: goto L_80016110; break;
        case 46: goto L_80016110; break;
        case 47: goto L_80016110; break;
        case 48: goto L_800166E4; break;
        case 49: goto L_80016110; break;
        case 50: goto L_80016110; break;
        case 51: goto L_80016110; break;
        case 52: goto L_80016110; break;
        case 53: goto L_80016110; break;
        case 54: goto L_80016110; break;
        case 55: goto L_80016110; break;
        case 56: goto L_80016110; break;
        case 57: goto L_80016110; break;
        case 58: goto L_80016110; break;
        case 59: goto L_80016110; break;
        case 60: goto L_80016110; break;
        case 61: goto L_80016110; break;
        case 62: goto L_80016110; break;
        case 63: goto L_80016110; break;
        case 64: goto L_800166EC; break;
        case 65: goto L_80016110; break;
        case 66: goto L_80016110; break;
        case 67: goto L_80016110; break;
        case 68: goto L_80016110; break;
        case 69: goto L_80016110; break;
        case 70: goto L_80016110; break;
        case 71: goto L_80016110; break;
        case 72: goto L_80016110; break;
        case 73: goto L_80016110; break;
        case 74: goto L_80016110; break;
        case 75: goto L_80016110; break;
        case 76: goto L_80016110; break;
        case 77: goto L_80016110; break;
        case 78: goto L_80016110; break;
        case 79: goto L_80016110; break;
        case 80: goto L_800166F4; break;
        case 81: goto L_80016110; break;
        case 82: goto L_80016110; break;
        case 83: goto L_80016110; break;
        case 84: goto L_80016110; break;
        case 85: goto L_80016110; break;
        case 86: goto L_80016110; break;
        case 87: goto L_80016110; break;
        case 88: goto L_80016110; break;
        case 89: goto L_80016110; break;
        case 90: goto L_80016110; break;
        case 91: goto L_80016110; break;
        case 92: goto L_80016110; break;
        case 93: goto L_80016110; break;
        case 94: goto L_80016110; break;
        case 95: goto L_80016110; break;
        case 96: goto L_80016110; break;
        default: switch_error(__func__, 0x80016684, 0x800C8C48);
    }
    // 0x80016688: nop

L_8001668C:
    // 0x8001668C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80016690: beq         $v1, $at, L_80016110
    if (ctx->r3 == ctx->r1) {
        // 0x80016694: nop
    
            goto L_80016110;
    }
    // 0x80016694: nop

    // 0x80016698: b           L_80016110
    // 0x8001669C: nop

        goto L_80016110;
    // 0x8001669C: nop

L_800166A0:
    // 0x800166A0: beq         $v1, $zero, L_800166BC
    if (ctx->r3 == 0) {
        // 0x800166A4: andi        $t4, $a1, 0xF
        ctx->r12 = ctx->r5 & 0XF;
            goto L_800166BC;
    }
    // 0x800166A4: andi        $t4, $a1, 0xF
    ctx->r12 = ctx->r5 & 0XF;
    // 0x800166A8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800166AC: beq         $v1, $at, L_80016110
    if (ctx->r3 == ctx->r1) {
        // 0x800166B0: nop
    
            goto L_80016110;
    }
    // 0x800166B0: nop

    // 0x800166B4: b           L_80016110
    // 0x800166B8: nop

        goto L_80016110;
    // 0x800166B8: nop

L_800166BC:
    // 0x800166BC: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x800166C0: addu        $t5, $s1, $t2
    ctx->r13 = ADD32(ctx->r17, ctx->r10);
    // 0x800166C4: lw          $t6, 0x34($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X34);
    // 0x800166C8: lw          $s3, 0x0($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X0);
    // 0x800166CC: sll         $t7, $s3, 1
    ctx->r15 = S32(ctx->r19 << 1);
    // 0x800166D0: b           L_80016110
    // 0x800166D4: srl         $s3, $t7, 31
    ctx->r19 = S32(U32(ctx->r15) >> 31);
        goto L_80016110;
    // 0x800166D4: srl         $s3, $t7, 31
    ctx->r19 = S32(U32(ctx->r15) >> 31);
L_800166D8:
    // 0x800166D8: lb          $t1, 0x7($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X7);
    // 0x800166DC: b           L_80016110
    // 0x800166E0: subu        $s3, $s3, $t1
    ctx->r19 = SUB32(ctx->r19, ctx->r9);
        goto L_80016110;
    // 0x800166E0: subu        $s3, $s3, $t1
    ctx->r19 = SUB32(ctx->r19, ctx->r9);
L_800166E4:
    // 0x800166E4: b           L_80016110
    // 0x800166E8: sb          $s3, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r19;
        goto L_80016110;
    // 0x800166E8: sb          $s3, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r19;
L_800166EC:
    // 0x800166EC: b           L_80016110
    // 0x800166F0: lb          $s3, 0x7($s1)
    ctx->r19 = MEM_B(ctx->r17, 0X7);
        goto L_80016110;
    // 0x800166F0: lb          $s3, 0x7($s1)
    ctx->r19 = MEM_B(ctx->r17, 0X7);
L_800166F4:
    // 0x800166F4: jal         0x800146D4
    // 0x800166F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    AudioSeq_ScriptReadS16(rdram, ctx);
        goto after_32;
    // 0x800166F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x800166FC: lw          $t0, 0x18($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X18);
    // 0x80016700: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80016704: andi        $t9, $a1, 0xF
    ctx->r25 = ctx->r5 & 0XF;
    // 0x80016708: andi        $t3, $v0, 0xFFFF
    ctx->r11 = ctx->r2 & 0XFFFF;
    // 0x8001670C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x80016710: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80016714: jal         0x80014440
    // 0x80016718: addu        $a2, $t0, $t3
    ctx->r6 = ADD32(ctx->r8, ctx->r11);
    AudioSeq_SequenceChannelEnable(rdram, ctx);
        goto after_33;
    // 0x80016718: addu        $a2, $t0, $t3
    ctx->r6 = ADD32(ctx->r8, ctx->r11);
    after_33:
    // 0x8001671C: b           L_80016110
    // 0x80016720: nop

        goto L_80016110;
    // 0x80016720: nop

L_80016724:
    // 0x80016724: lui         $s0, 0x8015
    ctx->r16 = S32(0X8015 << 16);
    // 0x80016728: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x8001672C: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
    // 0x80016730: addiu       $s0, $s0, 0x2FE8
    ctx->r16 = ADD32(ctx->r16, 0X2FE8);
    // 0x80016734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80016738:
    // 0x80016738: lw          $a0, 0x34($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X34);
    // 0x8001673C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016740: xor         $t4, $s0, $a0
    ctx->r12 = ctx->r16 ^ ctx->r4;
    // 0x80016744: sltu        $t4, $zero, $t4
    ctx->r12 = 0 < ctx->r12 ? 1 : 0;
    // 0x80016748: bnel        $t4, $at, L_80016768
    if (ctx->r12 != ctx->r1) {
        // 0x8001674C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80016768;
    }
    goto skip_11;
    // 0x8001674C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_11:
    // 0x80016750: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80016754: jal         0x800153E8
    // 0x80016758: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    AudioSeq_SequenceChannelProcessScript(rdram, ctx);
        goto after_34;
    // 0x80016758: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_34:
    // 0x8001675C: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80016760: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80016764: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80016768:
    // 0x80016768: bne         $v0, $s1, L_80016738
    if (ctx->r2 != ctx->r17) {
        // 0x8001676C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80016738;
    }
    // 0x8001676C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80016770: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016774:
    // 0x80016774: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80016778: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001677C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80016780: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80016784: jr          $ra
    // 0x80016788: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80016788: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_tank_80043AA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80043AA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80043AA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80043AA8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80043AAC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80043AB0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80043AB4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80043AB8: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80043ABC: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    // 0x80043AC0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80043AC4:
    // 0x80043AC4: bnel        $t6, $zero, L_80043AF0
    if (ctx->r14 != 0) {
        // 0x80043AC8: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_80043AF0;
    }
    goto skip_0;
    // 0x80043AC8: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x80043ACC: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80043AD0: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80043AD4: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80043AD8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80043ADC: jal         0x800438E0
    // 0x80043AE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_tank_800438E0(rdram, ctx);
        goto after_0;
    // 0x80043AE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80043AE4: b           L_80043B00
    // 0x80043AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80043B00;
    // 0x80043AE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80043AEC: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_80043AF0:
    // 0x80043AF0: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80043AF4: beql        $at, $zero, L_80043AC4
    if (ctx->r1 == 0) {
        // 0x80043AF8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80043AC4;
    }
    goto skip_1;
    // 0x80043AF8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x80043AFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80043B00:
    // 0x80043B00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80043B04: jr          $ra
    // 0x80043B08: nop

    return;
    // 0x80043B08: nop

;}
RECOMP_FUNC void func_edisplay_80059C28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C28: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80059C2C: jr          $ra
    // 0x80059C30: nop

    return;
    // 0x80059C30: nop

;}
RECOMP_FUNC void AudioHeap_ResetPool(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BFD8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000BFDC: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8000BFE0: jr          $ra
    // 0x8000BFE4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    return;
    // 0x8000BFE4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void AudioSynth_FinalResample(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B480: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000B484: andi        $t6, $a3, 0xFFFF
    ctx->r14 = ctx->r7 & 0XFFFF;
    // 0x8000B488: bne         $t6, $zero, L_8000B4B0
    if (ctx->r14 != 0) {
        // 0x8000B48C: or          $a3, $t6, $zero
        ctx->r7 = ctx->r14 | 0;
            goto L_8000B4B0;
    }
    // 0x8000B48C: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x8000B490: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B494: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x8000B498: ori         $t7, $t7, 0x450
    ctx->r15 = ctx->r15 | 0X450;
    // 0x8000B49C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000B4A0: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8000B4A4: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B4A8: jr          $ra
    // 0x8000B4AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000B4AC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000B4B0:
    // 0x8000B4B0: lhu         $t9, 0x12($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X12);
    // 0x8000B4B4: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x8000B4B8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000B4BC: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x8000B4C0: lui         $at, 0x450
    ctx->r1 = S32(0X450 << 16);
    // 0x8000B4C4: andi        $t1, $a2, 0xFFFF
    ctx->r9 = ctx->r6 & 0XFFFF;
    // 0x8000B4C8: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8000B4CC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8000B4D0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8000B4D4: lw          $t3, 0x14($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X14);
    // 0x8000B4D8: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8000B4DC: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B4E0: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8000B4E4: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x8000B4E8: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8000B4EC: andi        $t7, $a3, 0xFFFF
    ctx->r15 = ctx->r7 & 0XFFFF;
    // 0x8000B4F0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8000B4F4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000B4F8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8000B4FC: lw          $t9, 0xC($a1)
    ctx->r25 = MEM_W(ctx->r5, 0XC);
    // 0x8000B500: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000B504: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8000B508: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x8000B50C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8000B510: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8000B514: jr          $ra
    // 0x8000B518: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000B518: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void PlayerShot_DrawAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DA0C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003DA10: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003DA14: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8003DA18: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8003DA1C: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8003DA20: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8003DA24: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003DA28: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003DA2C: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8003DA30: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8003DA34: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003DA38: lui         $s4, 0x8016
    ctx->r20 = S32(0X8016 << 16);
    // 0x8003DA3C: lui         $s3, 0x8016
    ctx->r19 = S32(0X8016 << 16);
    // 0x8003DA40: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8003DA44: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003DA48: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8003DA4C: addiu       $s3, $s3, 0x1410
    ctx->r19 = ADD32(ctx->r19, 0X1410);
    // 0x8003DA50: addiu       $s4, $s4, -0x6B0
    ctx->r20 = ADD32(ctx->r20, -0X6B0);
    // 0x8003DA54: addiu       $s0, $s0, 0x4050
    ctx->r16 = ADD32(ctx->r16, 0X4050);
    // 0x8003DA58: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8003DA5C: addiu       $s5, $zero, 0x10
    ctx->r21 = ADD32(0, 0X10);
L_8003DA60:
    // 0x8003DA60: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x8003DA64: sw          $s1, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r17;
    // 0x8003DA68: beql        $t6, $zero, L_8003DAC0
    if (ctx->r14 == 0) {
        // 0x8003DA6C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8003DAC0;
    }
    goto skip_0;
    // 0x8003DA6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8003DA70: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
    // 0x8003DA74: bgez        $v0, L_8003DA90
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003DA78: nop
    
            goto L_8003DA90;
    }
    // 0x8003DA78: nop

    // 0x8003DA7C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003DA80: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x8003DA84: nop

    // 0x8003DA88: bc1t        L_8003DAAC
    if (c1cs) {
        // 0x8003DA8C: nop
    
            goto L_8003DAAC;
    }
    // 0x8003DA8C: nop

L_8003DA90:
    // 0x8003DA90: jal         0x80005708
    // 0x8003DA94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8003DA94: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8003DA98: jal         0x8003AF88
    // 0x8003DA9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_Draw(rdram, ctx);
        goto after_1;
    // 0x8003DA9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8003DAA0: jal         0x80005740
    // 0x8003DAA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_2;
    // 0x8003DAA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8003DAA8: lh          $v0, 0x0($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X0);
L_8003DAAC:
    // 0x8003DAAC: blez        $v0, L_8003DABC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003DAB0: addiu       $a0, $s0, 0x38
        ctx->r4 = ADD32(ctx->r16, 0X38);
            goto L_8003DABC;
    }
    // 0x8003DAB0: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x8003DAB4: jal         0x8005F290
    // 0x8003DAB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    Object_SetSfxSourceToView(rdram, ctx);
        goto after_3;
    // 0x8003DAB8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
L_8003DABC:
    // 0x8003DABC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8003DAC0:
    // 0x8003DAC0: bne         $s1, $s5, L_8003DA60
    if (ctx->r17 != ctx->r21) {
        // 0x8003DAC4: addiu       $s0, $s0, 0x70
        ctx->r16 = ADD32(ctx->r16, 0X70);
            goto L_8003DA60;
    }
    // 0x8003DAC4: addiu       $s0, $s0, 0x70
    ctx->r16 = ADD32(ctx->r16, 0X70);
    // 0x8003DAC8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003DACC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8003DAD0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DAD4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003DAD8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8003DADC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8003DAE0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8003DAE4: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8003DAE8: jr          $ra
    // 0x8003DAEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003DAEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Lib_TextureRect_RGBA32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F2C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009F2C4: lui         $t0, 0xF518
    ctx->r8 = S32(0XF518 << 16);
    // 0x8009F2C8: lui         $t1, 0x700
    ctx->r9 = S32(0X700 << 16);
    // 0x8009F2CC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F2D0: lui         $t7, 0xFD18
    ctx->r15 = S32(0XFD18 << 16);
    // 0x8009F2D4: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009F2D8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009F2DC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F2E0: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x8009F2E4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009F2E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F2EC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009F2F0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009F2F4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8009F2F8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8009F2FC: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8009F300: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8009F304: addiu       $t9, $t4, 0x8
    ctx->r25 = ADD32(ctx->r12, 0X8);
    // 0x8009F308: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009F30C: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x8009F310: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8009F314: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009F318: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F31C: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8009F320: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009F324: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009F328: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009F32C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009F330: mflo        $v0
    ctx->r2 = lo;
    // 0x8009F334: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009F338: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009F33C: beql        $at, $zero, L_8009F350
    if (ctx->r1 == 0) {
        // 0x8009F340: addiu       $a1, $zero, 0x7FF
        ctx->r5 = ADD32(0, 0X7FF);
            goto L_8009F350;
    }
    goto skip_0;
    // 0x8009F340: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009F344: b           L_8009F350
    // 0x8009F348: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8009F350;
    // 0x8009F348: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8009F34C: addiu       $a1, $zero, 0x7FF
    ctx->r5 = ADD32(0, 0X7FF);
L_8009F350:
    // 0x8009F350: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8009F354: srl         $t9, $v0, 3
    ctx->r25 = S32(U32(ctx->r2) >> 3);
    // 0x8009F358: bne         $t9, $zero, L_8009F368
    if (ctx->r25 != 0) {
        // 0x8009F35C: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8009F368;
    }
    // 0x8009F35C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8009F360: b           L_8009F36C
    // 0x8009F364: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8009F36C;
    // 0x8009F364: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8009F368:
    // 0x8009F368: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
L_8009F36C:
    // 0x8009F36C: bne         $v0, $zero, L_8009F37C
    if (ctx->r2 != 0) {
        // 0x8009F370: addiu       $t6, $t2, 0x7FF
        ctx->r14 = ADD32(ctx->r10, 0X7FF);
            goto L_8009F37C;
    }
    // 0x8009F370: addiu       $t6, $t2, 0x7FF
    ctx->r14 = ADD32(ctx->r10, 0X7FF);
    // 0x8009F374: b           L_8009F380
    // 0x8009F378: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009F380;
    // 0x8009F378: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009F37C:
    // 0x8009F37C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009F380:
    // 0x8009F380: divu        $zero, $t6, $t3
    lo = S32(U32(ctx->r14) / U32(ctx->r11)); hi = S32(U32(ctx->r14) % U32(ctx->r11));
    // 0x8009F384: mflo        $t7
    ctx->r15 = lo;
    // 0x8009F388: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009F38C: andi        $t6, $a1, 0xFFF
    ctx->r14 = ctx->r5 & 0XFFF;
    // 0x8009F390: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009F394: or          $t9, $t8, $t1
    ctx->r25 = ctx->r24 | ctx->r9;
    // 0x8009F398: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009F39C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8009F3A0: bne         $t3, $zero, L_8009F3AC
    if (ctx->r11 != 0) {
        // 0x8009F3A4: nop
    
            goto L_8009F3AC;
    }
    // 0x8009F3A4: nop

    // 0x8009F3A8: break       7
    do_break(2148135848);
L_8009F3AC:
    // 0x8009F3AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F3B0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009F3B4: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8009F3B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009F3BC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F3C0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009F3C4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009F3C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F3CC: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x8009F3D0: srl         $t9, $t6, 3
    ctx->r25 = S32(U32(ctx->r14) >> 3);
    // 0x8009F3D4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8009F3D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009F3DC: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8009F3E0: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8009F3E4: or          $t6, $t8, $t0
    ctx->r14 = ctx->r24 | ctx->r8;
    // 0x8009F3E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009F3EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009F3F0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F3F4: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8009F3F8: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x8009F3FC: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009F400: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009F404: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009F408: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x8009F40C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009F410: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009F414: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x8009F418: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8009F41C: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8009F420: addiu       $t9, $a3, -0x1
    ctx->r25 = ADD32(ctx->r7, -0X1);
    // 0x8009F424: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8009F428: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8009F42C: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8009F430: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x8009F434: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009F438: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009F43C: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009F440: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009F444: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009F448: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009F44C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009F450: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009F454: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8009F458: bgez        $a2, L_8009F46C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009F45C: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_8009F46C;
    }
    // 0x8009F45C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F460: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009F464: nop

    // 0x8009F468: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009F46C:
    // 0x8009F46C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009F470: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009F474: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009F478: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009F47C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009F480: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009F484: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009F488: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x8009F48C: nop

    // 0x8009F490: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009F494: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8009F498: bgez        $a3, L_8009F4B0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009F49C: or          $t9, $t6, $at
        ctx->r25 = ctx->r14 | ctx->r1;
            goto L_8009F4B0;
    }
    // 0x8009F49C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8009F4A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009F4A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009F4A8: nop

    // 0x8009F4AC: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009F4B0:
    // 0x8009F4B0: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009F4B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009F4B8: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009F4BC: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009F4C0: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009F4C4: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009F4C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009F4CC: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009F4D0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8009F4D4: nop

    // 0x8009F4D8: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009F4DC: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8009F4E0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009F4E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009F4E8: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009F4EC: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8009F4F0: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009F4F4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009F4F8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8009F4FC: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009F500: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009F504: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8009F508: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8009F50C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F510: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x8009F514: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009F518: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009F51C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009F520: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009F524: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009F528: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009F52C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009F530: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F534: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8009F538: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8009F53C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009F540: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F544: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8009F548: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009F54C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009F550: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009F554: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009F558: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8009F55C: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8009F560: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x8009F564: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8009F568: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009F56C: jr          $ra
    // 0x8009F570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009F570: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void RCP_SetupDL_46(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA0E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BA0E4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BA0E8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800BA0EC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BA0F0: addiu       $t8, $t8, 0x3EA0
    ctx->r24 = ADD32(ctx->r24, 0X3EA0);
    // 0x800BA0F4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800BA0F8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800BA0FC: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800BA100: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA104: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800BA108: jr          $ra
    // 0x800BA10C: nop

    return;
    // 0x800BA10C: nop

;}
RECOMP_FUNC void TiGreatFox_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077218: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007721C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077220: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80077224: jal         0x800515C4
    // 0x80077228: nop

    Cutscene_DrawGreatFox(rdram, ctx);
        goto after_0;
    // 0x80077228: nop

    after_0:
    // 0x8007722C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80077234: jr          $ra
    // 0x80077238: nop

    return;
    // 0x80077238: nop

;}
RECOMP_FUNC void func_enmy_80063F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063F4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80063F50: jr          $ra
    // 0x80063F54: nop

    return;
    // 0x80063F54: nop

;}
RECOMP_FUNC void PlayerShot_CollisionCheck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038140: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80038144: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80038148: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003814C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80038150: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x80038154: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80038158: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003815C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80038160: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80038164: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80038168: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003816C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80038170: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x80038174: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
    // 0x80038178: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8003817C: addiu       $a0, $a0, 0x130
    ctx->r4 = ADD32(ctx->r4, 0X130);
    // 0x80038180: bne         $s6, $t7, L_8003818C
    if (ctx->r22 != ctx->r15) {
        // 0x80038184: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8003818C;
    }
    // 0x80038184: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80038188: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_8003818C:
    // 0x8003818C: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x80038190: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x80038194: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80038198: beq         $t8, $zero, L_800388AC
    if (ctx->r24 == 0) {
        // 0x8003819C: nop
    
            goto L_800388AC;
    }
    // 0x8003819C: nop

L_800381A0:
    // 0x800381A0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800381A4: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x800381A8: bnel        $at, $zero, L_80038254
    if (ctx->r1 != 0) {
        // 0x800381AC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038254;
    }
    goto skip_0;
    // 0x800381AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800381B0: lbu         $v0, 0x35($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X35);
    // 0x800381B4: beql        $v0, $zero, L_80038254
    if (ctx->r2 == 0) {
        // 0x800381B8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038254;
    }
    goto skip_1;
    // 0x800381B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x800381BC: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800381C0: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800381C4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800381C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800381CC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800381D0: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800381D4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800381D8: nop

    // 0x800381DC: bc1fl       L_80038254
    if (!c1cs) {
        // 0x800381E0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038254;
    }
    goto skip_2;
    // 0x800381E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x800381E4: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800381E8: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800381EC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800381F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800381F4: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800381F8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800381FC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80038200: nop

    // 0x80038204: bc1fl       L_80038254
    if (!c1cs) {
        // 0x80038208: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038254;
    }
    goto skip_3;
    // 0x80038208: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_3:
    // 0x8003820C: lwc1        $f6, 0x8($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038210: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80038214: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80038218: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003821C: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80038220: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038224: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80038228: nop

    // 0x8003822C: bc1fl       L_80038254
    if (!c1cs) {
        // 0x80038230: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038254;
    }
    goto skip_4;
    // 0x80038230: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x80038234: bne         $s5, $v0, L_80038244
    if (ctx->r21 != ctx->r2) {
        // 0x80038238: addiu       $a1, $a0, 0x80
        ctx->r5 = ADD32(ctx->r4, 0X80);
            goto L_80038244;
    }
    // 0x80038238: addiu       $a1, $a0, 0x80
    ctx->r5 = ADD32(ctx->r4, 0X80);
    // 0x8003823C: b           L_80038250
    // 0x80038240: sh          $s3, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r19;
        goto L_80038250;
    // 0x80038240: sh          $s3, 0x44($a0)
    MEM_H(0X44, ctx->r4) = ctx->r19;
L_80038244:
    // 0x80038244: jal         0x80060FBC
    // 0x80038248: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80038248: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003824C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
L_80038250:
    // 0x80038250: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038254:
    // 0x80038254: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x80038258: bne         $at, $zero, L_800381A0
    if (ctx->r1 != 0) {
        // 0x8003825C: addiu       $a0, $a0, 0x8C
        ctx->r4 = ADD32(ctx->r4, 0X8C);
            goto L_800381A0;
    }
    // 0x8003825C: addiu       $a0, $a0, 0x8C
    ctx->r4 = ADD32(ctx->r4, 0X8C);
    // 0x80038260: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80038264: addiu       $s0, $s0, 0x3FE0
    ctx->r16 = ADD32(ctx->r16, 0X3FE0);
    // 0x80038268: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003826C: addiu       $s4, $zero, 0xB4
    ctx->r20 = ADD32(0, 0XB4);
L_80038270:
    // 0x80038270: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x80038274: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x80038278: bnel        $at, $zero, L_80038520
    if (ctx->r1 != 0) {
        // 0x8003827C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038520;
    }
    goto skip_5;
    // 0x8003827C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_5:
    // 0x80038280: lhu         $t1, 0xC2($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XC2);
    // 0x80038284: bnel        $t1, $zero, L_80038520
    if (ctx->r9 != 0) {
        // 0x80038288: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038520;
    }
    goto skip_6;
    // 0x80038288: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_6:
    // 0x8003828C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80038290: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80038294: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038298: beq         $a1, $s4, L_800382B0
    if (ctx->r5 == ctx->r20) {
        // 0x8003829C: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800382B0;
    }
    // 0x8003829C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800382A0: beql        $v1, $at, L_800382D4
    if (ctx->r3 == ctx->r1) {
        // 0x800382A4: lh          $v0, 0xB4($s0)
        ctx->r2 = MEM_H(ctx->r16, 0XB4);
            goto L_800382D4;
    }
    goto skip_7;
    // 0x800382A4: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
    skip_7:
    // 0x800382A8: b           L_800383AC
    // 0x800382AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800383AC;
    // 0x800382AC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800382B0:
    // 0x800382B0: jal         0x8003774C
    // 0x800382B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    PlayerShot_CheckPolyCollision(rdram, ctx);
        goto after_1;
    // 0x800382B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x800382B8: beql        $v0, $zero, L_80038520
    if (ctx->r2 == 0) {
        // 0x800382BC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038520;
    }
    goto skip_8;
    // 0x800382BC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_8:
    // 0x800382C0: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
    // 0x800382C4: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x800382C8: b           L_80038F0C
    // 0x800382CC: sh          $t2, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = ctx->r10;
        goto L_80038F0C;
    // 0x800382CC: sh          $t2, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = ctx->r10;
    // 0x800382D0: lh          $v0, 0xB4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB4);
L_800382D4:
    // 0x800382D4: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x800382D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800382DC: bne         $v0, $at, L_80038304
    if (ctx->r2 != ctx->r1) {
        // 0x800382E0: addiu       $a1, $zero, 0x3E8
        ctx->r5 = ADD32(0, 0X3E8);
            goto L_80038304;
    }
    // 0x800382E0: addiu       $a1, $zero, 0x3E8
    ctx->r5 = ADD32(0, 0X3E8);
    // 0x800382E4: jal         0x8003774C
    // 0x800382E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    PlayerShot_CheckPolyCollision(rdram, ctx);
        goto after_2;
    // 0x800382E8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x800382EC: beql        $v0, $zero, L_80038520
    if (ctx->r2 == 0) {
        // 0x800382F0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038520;
    }
    goto skip_9;
    // 0x800382F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_9:
    // 0x800382F4: sb          $s3, 0xD0($s0)
    MEM_B(0XD0, ctx->r16) = ctx->r19;
    // 0x800382F8: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x800382FC: b           L_80038F0C
    // 0x80038300: sh          $t3, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = ctx->r11;
        goto L_80038F0C;
    // 0x80038300: sh          $t3, 0xD2($s0)
    MEM_H(0XD2, ctx->r16) = ctx->r11;
L_80038304:
    // 0x80038304: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80038308: bne         $v0, $at, L_80038388
    if (ctx->r2 != ctx->r1) {
        // 0x8003830C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80038388;
    }
    // 0x8003830C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038310: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80038314: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038318: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003831C: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038320: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80038324: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80038328: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003832C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80038330: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80038334: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80038338: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003833C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038340: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80038344: abs.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = fabsf(ctx->f0.fl);
    // 0x80038348: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003834C: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80038350: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038354: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038358: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003835C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80038360: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80038364: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80038368: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8003836C: nop

    // 0x80038370: bc1fl       L_80038520
    if (!c1cs) {
        // 0x80038374: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038520;
    }
    goto skip_10;
    // 0x80038374: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_10:
    // 0x80038378: jal         0x80037CF4
    // 0x8003837C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    PlayerShot_ApplyDamageToActor(rdram, ctx);
        goto after_3;
    // 0x8003837C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80038380: b           L_80038520
    // 0x80038384: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80038520;
    // 0x80038384: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038388:
    // 0x80038388: jal         0x80036F88
    // 0x8003838C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    PlayerShot_CheckEventHitbox(rdram, ctx);
        goto after_4;
    // 0x8003838C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80038390: beq         $v0, $zero, L_8003851C
    if (ctx->r2 == 0) {
        // 0x80038394: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8003851C;
    }
    // 0x80038394: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80038398: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003839C: jal         0x80037CF4
    // 0x800383A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    PlayerShot_ApplyDamageToActor(rdram, ctx);
        goto after_5;
    // 0x800383A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x800383A4: b           L_80038F10
    // 0x800383A8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80038F10;
    // 0x800383A8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800383AC:
    // 0x800383AC: lh          $t4, 0x32($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X32);
    // 0x800383B0: addiu       $at, $zero, 0xC5
    ctx->r1 = ADD32(0, 0XC5);
    // 0x800383B4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800383B8: beq         $t4, $zero, L_800384F8
    if (ctx->r12 == 0) {
        // 0x800383BC: nop
    
            goto L_800384F8;
    }
    // 0x800383BC: nop

    // 0x800383C0: bnel        $a1, $at, L_800384D4
    if (ctx->r5 != ctx->r1) {
        // 0x800383C4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800384D4;
    }
    goto skip_11;
    // 0x800383C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_11:
    // 0x800383C8: lh          $v0, 0xE4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE4);
    // 0x800383CC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800383D0: bne         $at, $zero, L_800384D0
    if (ctx->r1 != 0) {
        // 0x800383D4: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_800384D0;
    }
    // 0x800383D4: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800383D8: beq         $at, $zero, L_800384D0
    if (ctx->r1 == 0) {
        // 0x800383DC: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_800384D0;
    }
    // 0x800383DC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800383E0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x800383E4: addiu       $v1, $zero, 0x13
    ctx->r3 = ADD32(0, 0X13);
    // 0x800383E8: bne         $v1, $v0, L_80038400
    if (ctx->r3 != ctx->r2) {
        // 0x800383EC: nop
    
            goto L_80038400;
    }
    // 0x800383EC: nop

    // 0x800383F0: lw          $t5, 0x68($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X68);
    // 0x800383F4: slti        $at, $t5, 0x68
    ctx->r1 = SIGNED(ctx->r13) < 0X68 ? 1 : 0;
    // 0x800383F8: bnel        $at, $zero, L_80038418
    if (ctx->r1 != 0) {
        // 0x800383FC: lhu         $t7, 0x2($s1)
        ctx->r15 = MEM_HU(ctx->r17, 0X2);
            goto L_80038418;
    }
    goto skip_12;
    // 0x800383FC: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
    skip_12:
L_80038400:
    // 0x80038400: beql        $v1, $v0, L_800384D4
    if (ctx->r3 == ctx->r2) {
        // 0x80038404: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800384D4;
    }
    goto skip_13;
    // 0x80038404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_13:
    // 0x80038408: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x8003840C: bnel        $t6, $zero, L_800384D4
    if (ctx->r14 != 0) {
        // 0x80038410: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800384D4;
    }
    goto skip_14;
    // 0x80038410: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_14:
    // 0x80038414: lhu         $t7, 0x2($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X2);
L_80038418:
    // 0x80038418: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003841C: beql        $t7, $at, L_800384D4
    if (ctx->r15 == ctx->r1) {
        // 0x80038420: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800384D4;
    }
    goto skip_15;
    // 0x80038420: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_15:
    // 0x80038424: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80038428: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003842C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80038430: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80038434: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038438: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003843C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80038440: nop

    // 0x80038444: bc1fl       L_800384D4
    if (!c1cs) {
        // 0x80038448: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800384D4;
    }
    goto skip_16;
    // 0x80038448: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_16:
    // 0x8003844C: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80038450: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038454: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80038458: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003845C: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80038460: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038464: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80038468: nop

    // 0x8003846C: bc1fl       L_800384D4
    if (!c1cs) {
        // 0x80038470: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800384D4;
    }
    goto skip_17;
    // 0x80038470: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_17:
    // 0x80038474: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80038478: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003847C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80038480: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80038484: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80038488: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003848C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80038490: nop

    // 0x80038494: bc1fl       L_800384D4
    if (!c1cs) {
        // 0x80038498: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800384D4;
    }
    goto skip_18;
    // 0x80038498: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_18:
    // 0x8003849C: bne         $v1, $v0, L_800384AC
    if (ctx->r3 != ctx->r2) {
        // 0x800384A0: nop
    
            goto L_800384AC;
    }
    // 0x800384A0: nop

    // 0x800384A4: b           L_800384D0
    // 0x800384A8: sw          $s3, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r19;
        goto L_800384D0;
    // 0x800384A8: sw          $s3, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r19;
L_800384AC:
    // 0x800384AC: jal         0x80004EB0
    // 0x800384B0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800384B0: nop

    after_6:
    // 0x800384B4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800384B8: lwc1        $f18, 0x5248($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5248);
    // 0x800384BC: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800384C0: nop

    // 0x800384C4: bc1fl       L_800384D4
    if (!c1cs) {
        // 0x800384C8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800384D4;
    }
    goto skip_19;
    // 0x800384C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_19:
    // 0x800384CC: sw          $s3, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r19;
L_800384D0:
    // 0x800384D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800384D4:
    // 0x800384D4: jal         0x80037438
    // 0x800384D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    PlayerShot_CheckActorHitbox(rdram, ctx);
        goto after_7;
    // 0x800384D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800384DC: beq         $v0, $zero, L_8003851C
    if (ctx->r2 == 0) {
        // 0x800384E0: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8003851C;
    }
    // 0x800384E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800384E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800384E8: jal         0x80037CF4
    // 0x800384EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    PlayerShot_ApplyDamageToActor(rdram, ctx);
        goto after_8;
    // 0x800384EC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_8:
    // 0x800384F0: b           L_80038F10
    // 0x800384F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80038F10;
    // 0x800384F4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800384F8:
    // 0x800384F8: jal         0x80036874
    // 0x800384FC: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    PlayerShot_CheckObjectHitbox(rdram, ctx);
        goto after_9;
    // 0x800384FC: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_9:
    // 0x80038500: beq         $v0, $zero, L_8003851C
    if (ctx->r2 == 0) {
        // 0x80038504: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8003851C;
    }
    // 0x80038504: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80038508: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003850C: jal         0x80037CF4
    // 0x80038510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    PlayerShot_ApplyDamageToActor(rdram, ctx);
        goto after_10;
    // 0x80038510: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_10:
    // 0x80038514: b           L_80038F10
    // 0x80038518: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80038F10;
    // 0x80038518: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8003851C:
    // 0x8003851C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038520:
    // 0x80038520: slti        $at, $s2, 0x3C
    ctx->r1 = SIGNED(ctx->r18) < 0X3C ? 1 : 0;
    // 0x80038524: bne         $at, $zero, L_80038270
    if (ctx->r1 != 0) {
        // 0x80038528: addiu       $s0, $s0, 0x2F4
        ctx->r16 = ADD32(ctx->r16, 0X2F4);
            goto L_80038270;
    }
    // 0x80038528: addiu       $s0, $s0, 0x2F4
    ctx->r16 = ADD32(ctx->r16, 0X2F4);
    // 0x8003852C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80038530: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x80038534: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80038538: bne         $s3, $t8, L_800388AC
    if (ctx->r19 != ctx->r24) {
        // 0x8003853C: nop
    
            goto L_800388AC;
    }
    // 0x8003853C: nop

    // 0x80038540: lw          $t9, 0x78A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A8);
    // 0x80038544: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x80038548: lw          $s0, -0x7D80($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D80);
    // 0x8003854C: blez        $t9, L_800388AC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80038550: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_800388AC;
    }
    // 0x80038550: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80038554: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038558: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003855C: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_80038560:
    // 0x80038560: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80038564: lw          $t0, 0x78E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78E8);
    // 0x80038568: lw          $a0, 0x68($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X68);
    // 0x8003856C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x80038570: beq         $t0, $zero, L_800385AC
    if (ctx->r8 == 0) {
        // 0x80038574: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_800385AC;
    }
    // 0x80038574: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80038578: beq         $at, $zero, L_800385AC
    if (ctx->r1 == 0) {
        // 0x8003857C: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_800385AC;
    }
    // 0x8003857C: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80038580: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x80038584: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x80038588: lw          $t2, 0x1AA8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1AA8);
    // 0x8003858C: bnel        $t2, $zero, L_800385A4
    if (ctx->r10 != 0) {
        // 0x80038590: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800385A4;
    }
    goto skip_20;
    // 0x80038590: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    skip_20:
    // 0x80038594: lhu         $t3, 0x2($s1)
    ctx->r11 = MEM_HU(ctx->r17, 0X2);
    // 0x80038598: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003859C: bne         $t3, $at, L_800385AC
    if (ctx->r11 != ctx->r1) {
        // 0x800385A0: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_800385AC;
    }
    // 0x800385A0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
L_800385A4:
    // 0x800385A4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800385A8: nop

L_800385AC:
    // 0x800385AC: lw          $v1, 0x280($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X280);
    // 0x800385B0: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x800385B4: bne         $at, $zero, L_800385C4
    if (ctx->r1 != 0) {
        // 0x800385B8: lui         $at, 0x4316
        ctx->r1 = S32(0X4316 << 16);
            goto L_800385C4;
    }
    // 0x800385B8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x800385BC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800385C0: nop

L_800385C4:
    // 0x800385C4: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800385C8: bne         $s3, $v0, L_800385DC
    if (ctx->r19 != ctx->r2) {
        // 0x800385CC: nop
    
            goto L_800385DC;
    }
    // 0x800385CC: nop

    // 0x800385D0: add.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800385D4: b           L_800385F0
    // 0x800385D8: add.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f14.fl;
        goto L_800385F0;
    // 0x800385D8: add.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f14.fl;
L_800385DC:
    // 0x800385DC: bnel        $s4, $v0, L_800385F0
    if (ctx->r20 != ctx->r2) {
        // 0x800385E0: mov.s       $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
            goto L_800385F0;
    }
    goto skip_21;
    // 0x800385E0: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    skip_21:
    // 0x800385E4: b           L_800385F0
    // 0x800385E8: add.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f14.fl;
        goto L_800385F0;
    // 0x800385E8: add.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f14.fl;
    // 0x800385EC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_800385F0:
    // 0x800385F0: beq         $s2, $a0, L_8003888C
    if (ctx->r18 == ctx->r4) {
        // 0x800385F4: nop
    
            goto L_8003888C;
    }
    // 0x800385F4: nop

    // 0x800385F8: lw          $v0, 0x1C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C8);
    // 0x800385FC: beql        $s4, $v0, L_80038610
    if (ctx->r20 == ctx->r2) {
        // 0x80038600: lwc1        $f4, 0x138($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
            goto L_80038610;
    }
    goto skip_22;
    // 0x80038600: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
    skip_22:
    // 0x80038604: bne         $s6, $v0, L_8003888C
    if (ctx->r22 != ctx->r2) {
        // 0x80038608: nop
    
            goto L_8003888C;
    }
    // 0x80038608: nop

    // 0x8003860C: lwc1        $f4, 0x138($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X138);
L_80038610:
    // 0x80038610: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80038614: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038618: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003861C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80038620: nop

    // 0x80038624: bc1f        L_8003888C
    if (!c1cs) {
        // 0x80038628: nop
    
            goto L_8003888C;
    }
    // 0x80038628: nop

    // 0x8003862C: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80038630: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038634: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80038638: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003863C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80038640: nop

    // 0x80038644: bc1f        L_8003888C
    if (!c1cs) {
        // 0x80038648: nop
    
            goto L_8003888C;
    }
    // 0x80038648: nop

    // 0x8003864C: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80038650: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038654: slti        $at, $v1, 0x64
    ctx->r1 = SIGNED(ctx->r3) < 0X64 ? 1 : 0;
    // 0x80038658: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003865C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038660: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80038664: nop

    // 0x80038668: bc1f        L_8003888C
    if (!c1cs) {
        // 0x8003866C: nop
    
            goto L_8003888C;
    }
    // 0x8003866C: nop

    // 0x80038670: bne         $at, $zero, L_800387D4
    if (ctx->r1 != 0) {
        // 0x80038674: nop
    
            goto L_800387D4;
    }
    // 0x80038674: nop

    // 0x80038678: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x8003867C: lwc1        $f8, 0x114($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X114);
    // 0x80038680: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80038684: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038688: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003868C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80038690: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038694: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80038698: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003869C: jal         0x80004EB0
    // 0x800386A0: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_11;
    // 0x800386A0: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    after_11:
    // 0x800386A4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x800386A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800386AC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800386B0: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800386B4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800386B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800386BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800386C0: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x800386C4: lwc1        $f6, 0x5250($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5250);
    // 0x800386C8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800386CC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800386D0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800386D4: jal         0x80005E90
    // 0x800386D8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x800386D8: nop

    after_12:
    // 0x800386DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800386E0: lwc1        $f18, 0x5254($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5254);
    // 0x800386E4: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800386E8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800386EC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800386F0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800386F4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800386F8: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800386FC: jal         0x80005D44
    // 0x80038700: nop

    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x80038700: nop

    after_13:
    // 0x80038704: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80038708: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003870C: lwc1        $f6, 0x5258($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5258);
    // 0x80038710: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80038714: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80038718: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8003871C: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x80038720: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x80038724: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x80038728: jal         0x80006A20
    // 0x8003872C: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_14;
    // 0x8003872C: swc1        $f6, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f6.u32l;
    after_14:
    // 0x80038730: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80038734: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038738: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8003873C: swc1        $f8, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f8.u32l;
    // 0x80038740: lwc1        $f0, 0x20($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80038744: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80038748: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8003874C: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80038750: swc1        $f10, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f10.u32l;
    // 0x80038754: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80038758: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8003875C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80038760: swc1        $f18, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f18.u32l;
    // 0x80038764: lwc1        $f12, 0x28($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80038768: add.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8003876C: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80038770: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038774: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80038778: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003877C: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80038780: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80038784: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80038788: sw          $t4, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->r12;
    // 0x8003878C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80038790: swc1        $f4, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f4.u32l;
    // 0x80038794: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80038798: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x8003879C: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x800387A0: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800387A4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800387A8: ori         $a0, $a0, 0x7011
    ctx->r4 = ctx->r4 | 0X7011;
    // 0x800387AC: addiu       $a1, $s0, 0x460
    ctx->r5 = ADD32(ctx->r16, 0X460);
    // 0x800387B0: jal         0x80019218
    // 0x800387B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_15;
    // 0x800387B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x800387B8: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800387BC: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800387C0: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    // 0x800387C4: jal         0x80078E50
    // 0x800387C8: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    Effect_Sparkle_Spawn(rdram, ctx);
        goto after_16;
    // 0x800387C8: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    after_16:
    // 0x800387CC: b           L_8003888C
    // 0x800387D0: nop

        goto L_8003888C;
    // 0x800387D0: nop

L_800387D4:
    // 0x800387D4: jal         0x80036318
    // 0x800387D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_17;
    // 0x800387D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x800387DC: lw          $t6, 0x1F4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1F4);
    // 0x800387E0: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x800387E4: bne         $t6, $zero, L_8003888C
    if (ctx->r14 != 0) {
        // 0x800387E8: nop
    
            goto L_8003888C;
    }
    // 0x800387E8: nop

    // 0x800387EC: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x800387F0: addiu       $a2, $zero, 0x3C
    ctx->r6 = ADD32(0, 0X3C);
    // 0x800387F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800387F8: lw          $t8, 0x1CC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1CC);
    // 0x800387FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80038800: bne         $s4, $t8, L_8003881C
    if (ctx->r20 != ctx->r24) {
        // 0x80038804: nop
    
            goto L_8003881C;
    }
    // 0x80038804: nop

    // 0x80038808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003880C: jal         0x800A6CD0
    // 0x80038810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Player_ApplyDamage(rdram, ctx);
        goto after_18;
    // 0x80038810: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_18:
    // 0x80038814: b           L_80038828
    // 0x80038818: sw          $s3, 0x284($s0)
    MEM_W(0X284, ctx->r16) = ctx->r19;
        goto L_80038828;
    // 0x80038818: sw          $s3, 0x284($s0)
    MEM_W(0X284, ctx->r16) = ctx->r19;
L_8003881C:
    // 0x8003881C: jal         0x800A6CD0
    // 0x80038820: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    Player_ApplyDamage(rdram, ctx);
        goto after_19;
    // 0x80038820: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    after_19:
    // 0x80038824: sw          $s3, 0x284($s0)
    MEM_W(0X284, ctx->r16) = ctx->r19;
L_80038828:
    // 0x80038828: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8003882C: lw          $t9, 0x78A8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X78A8);
    // 0x80038830: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80038834: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80038838: beq         $s3, $t9, L_8003884C
    if (ctx->r19 == ctx->r25) {
        // 0x8003883C: nop
    
            goto L_8003884C;
    }
    // 0x8003883C: nop

    // 0x80038840: lw          $t0, 0x68($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X68);
    // 0x80038844: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80038848: sw          $t1, 0x288($s0)
    MEM_W(0X288, ctx->r16) = ctx->r9;
L_8003884C:
    // 0x8003884C: lwc1        $f16, 0x525C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X525C);
    // 0x80038850: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x80038854: lw          $t2, 0x1CC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X1CC);
    // 0x80038858: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8003885C: swc1        $f4, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f4.u32l;
    // 0x80038860: lwc1        $f6, 0x24($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X24);
    // 0x80038864: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80038868: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x8003886C: lwc1        $f10, 0x28($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80038870: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80038874: beq         $s4, $t2, L_8003888C
    if (ctx->r20 == ctx->r10) {
        // 0x80038878: swc1        $f18, 0xE0($s0)
        MEM_W(0XE0, ctx->r16) = ctx->f18.u32l;
            goto L_8003888C;
    }
    // 0x80038878: swc1        $f18, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f18.u32l;
    // 0x8003887C: lwc1        $f12, 0x74($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80038880: lwc1        $f14, 0x78($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80038884: jal         0x8007D1E0
    // 0x80038888: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    Effect_FireSmoke3_Spawn(rdram, ctx);
        goto after_20;
    // 0x80038888: lw          $a2, 0x138($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X138);
    after_20:
L_8003888C:
    // 0x8003888C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x80038890: lw          $t3, 0x78A8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A8);
    // 0x80038894: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80038898: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003889C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800388A0: slt         $at, $s2, $t3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800388A4: bne         $at, $zero, L_80038560
    if (ctx->r1 != 0) {
        // 0x800388A8: addiu       $s0, $s0, 0x4E0
        ctx->r16 = ADD32(ctx->r16, 0X4E0);
            goto L_80038560;
    }
    // 0x800388A8: addiu       $s0, $s0, 0x4E0
    ctx->r16 = ADD32(ctx->r16, 0X4E0);
L_800388AC:
    // 0x800388AC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800388B0: lw          $t4, -0x7B54($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7B54);
    // 0x800388B4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800388B8: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
    // 0x800388BC: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x800388C0: bne         $s6, $t4, L_8003892C
    if (ctx->r22 != ctx->r12) {
        // 0x800388C4: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8003892C;
    }
    // 0x800388C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800388C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800388CC: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800388D0: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800388D4: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800388D8: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800388DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800388E0: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800388E4: jal         0x801B6AEC
    // 0x800388E8: nop

    Ground_801B6AEC(rdram, ctx);
        goto after_21;
    // 0x800388E8: nop

    after_21:
    // 0x800388EC: beq         $v0, $zero, L_8003892C
    if (ctx->r2 == 0) {
        // 0x800388F0: nop
    
            goto L_8003892C;
    }
    // 0x800388F0: nop

    // 0x800388F4: jal         0x80036318
    // 0x800388F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_22;
    // 0x800388F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x800388FC: lhu         $t5, 0x2($s1)
    ctx->r13 = MEM_HU(ctx->r17, 0X2);
    // 0x80038900: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80038904: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80038908: beq         $s6, $t5, L_8003892C
    if (ctx->r22 == ctx->r13) {
        // 0x8003890C: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_8003892C;
    }
    // 0x8003890C: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80038910: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038914: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038918: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    // 0x8003891C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80038920: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80038924: jal         0x8007A900
    // 0x80038928: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    Effect_Effect359_Spawn(rdram, ctx);
        goto after_23;
    // 0x80038928: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_23:
L_8003892C:
    // 0x8003892C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80038930: lw          $t8, -0x7D6C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D6C);
    // 0x80038934: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80038938: addiu       $a1, $sp, 0xA4
    ctx->r5 = ADD32(ctx->r29, 0XA4);
    // 0x8003893C: beq         $t8, $zero, L_80038988
    if (ctx->r24 == 0) {
        // 0x80038940: nop
    
            goto L_80038988;
    }
    // 0x80038940: nop

    // 0x80038944: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80038948: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x8003894C: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x80038950: jal         0x800A73E4
    // 0x80038954: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_24;
    // 0x80038954: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_24:
    // 0x80038958: beq         $v0, $zero, L_80038988
    if (ctx->r2 == 0) {
        // 0x8003895C: nop
    
            goto L_80038988;
    }
    // 0x8003895C: nop

    // 0x80038960: jal         0x80036318
    // 0x80038964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_25;
    // 0x80038964: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x80038968: lhu         $t9, 0x2($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X2);
    // 0x8003896C: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80038970: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80038974: beq         $s6, $t9, L_80038988
    if (ctx->r22 == ctx->r25) {
        // 0x80038978: nop
    
            goto L_80038988;
    }
    // 0x80038978: nop

    // 0x8003897C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038980: jal         0x8007B228
    // 0x80038984: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    Effect_Effect381_Spawn(rdram, ctx);
        goto after_26;
    // 0x80038984: lw          $a2, 0xC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0XC);
    after_26:
L_80038988:
    // 0x80038988: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8003898C: lw          $t0, 0x7880($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7880);
    // 0x80038990: lui         $s0, 0x8016
    ctx->r16 = S32(0X8016 << 16);
    // 0x80038994: addiu       $s0, $s0, 0x1B00
    ctx->r16 = ADD32(ctx->r16, 0X1B00);
    // 0x80038998: bne         $s3, $t0, L_80038A54
    if (ctx->r19 != ctx->r8) {
        // 0x8003899C: nop
    
            goto L_80038A54;
    }
    // 0x8003899C: nop

    // 0x800389A0: lw          $t1, 0x68($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X68);
    // 0x800389A4: slti        $at, $t1, 0x6E
    ctx->r1 = SIGNED(ctx->r9) < 0X6E ? 1 : 0;
    // 0x800389A8: beq         $at, $zero, L_80038A54
    if (ctx->r1 == 0) {
        // 0x800389AC: nop
    
            goto L_80038A54;
    }
    // 0x800389AC: nop

    // 0x800389B0: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x800389B4: lw          $s0, -0x7D58($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X7D58);
L_800389B8:
    // 0x800389B8: lbu         $t2, 0x0($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X0);
    // 0x800389BC: bnel        $s5, $t2, L_80038A40
    if (ctx->r21 != ctx->r10) {
        // 0x800389C0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038A40;
    }
    goto skip_23;
    // 0x800389C0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_23:
    // 0x800389C4: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x800389C8: addiu       $at, $zero, 0x75
    ctx->r1 = ADD32(0, 0X75);
    // 0x800389CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800389D0: beq         $a1, $at, L_80038A20
    if (ctx->r5 == ctx->r1) {
        // 0x800389D4: addiu       $at, $zero, 0x8D
        ctx->r1 = ADD32(0, 0X8D);
            goto L_80038A20;
    }
    // 0x800389D4: addiu       $at, $zero, 0x8D
    ctx->r1 = ADD32(0, 0X8D);
    // 0x800389D8: beq         $a1, $at, L_80038A20
    if (ctx->r5 == ctx->r1) {
        // 0x800389DC: addiu       $at, $zero, 0x95
        ctx->r1 = ADD32(0, 0X95);
            goto L_80038A20;
    }
    // 0x800389DC: addiu       $at, $zero, 0x95
    ctx->r1 = ADD32(0, 0X95);
    // 0x800389E0: beq         $a1, $at, L_80038A20
    if (ctx->r5 == ctx->r1) {
        // 0x800389E4: addiu       $at, $zero, 0x96
        ctx->r1 = ADD32(0, 0X96);
            goto L_80038A20;
    }
    // 0x800389E4: addiu       $at, $zero, 0x96
    ctx->r1 = ADD32(0, 0X96);
    // 0x800389E8: beq         $a1, $at, L_80038A20
    if (ctx->r5 == ctx->r1) {
        // 0x800389EC: addiu       $at, $zero, 0x94
        ctx->r1 = ADD32(0, 0X94);
            goto L_80038A20;
    }
    // 0x800389EC: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x800389F0: beq         $a1, $at, L_80038A20
    if (ctx->r5 == ctx->r1) {
        // 0x800389F4: addiu       $at, $zero, 0x8F
        ctx->r1 = ADD32(0, 0X8F);
            goto L_80038A20;
    }
    // 0x800389F4: addiu       $at, $zero, 0x8F
    ctx->r1 = ADD32(0, 0X8F);
    // 0x800389F8: beq         $a1, $at, L_80038A20
    if (ctx->r5 == ctx->r1) {
        // 0x800389FC: addiu       $at, $zero, 0xA0
        ctx->r1 = ADD32(0, 0XA0);
            goto L_80038A20;
    }
    // 0x800389FC: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x80038A00: beq         $a1, $at, L_80038A20
    if (ctx->r5 == ctx->r1) {
        // 0x80038A04: nop
    
            goto L_80038A20;
    }
    // 0x80038A04: nop

    // 0x80038A08: beq         $s3, $a1, L_80038A20
    if (ctx->r19 == ctx->r5) {
        // 0x80038A0C: nop
    
            goto L_80038A20;
    }
    // 0x80038A0C: nop

    // 0x80038A10: beq         $s4, $a1, L_80038A20
    if (ctx->r20 == ctx->r5) {
        // 0x80038A14: addiu       $at, $zero, 0x8C
        ctx->r1 = ADD32(0, 0X8C);
            goto L_80038A20;
    }
    // 0x80038A14: addiu       $at, $zero, 0x8C
    ctx->r1 = ADD32(0, 0X8C);
    // 0x80038A18: bne         $a1, $at, L_80038A30
    if (ctx->r5 != ctx->r1) {
        // 0x80038A1C: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_80038A30;
    }
    // 0x80038A1C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
L_80038A20:
    // 0x80038A20: jal         0x8003774C
    // 0x80038A24: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    PlayerShot_CheckPolyCollision(rdram, ctx);
        goto after_27;
    // 0x80038A24: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_27:
    // 0x80038A28: b           L_80038A40
    // 0x80038A2C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80038A40;
    // 0x80038A2C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038A30:
    // 0x80038A30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038A34: jal         0x80036874
    // 0x80038A38: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    PlayerShot_CheckObjectHitbox(rdram, ctx);
        goto after_28;
    // 0x80038A38: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_28:
    // 0x80038A3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038A40:
    // 0x80038A40: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80038A44: bne         $s2, $at, L_800389B8
    if (ctx->r18 != ctx->r1) {
        // 0x80038A48: addiu       $s0, $s0, 0x58
        ctx->r16 = ADD32(ctx->r16, 0X58);
            goto L_800389B8;
    }
    // 0x80038A48: addiu       $s0, $s0, 0x58
    ctx->r16 = ADD32(ctx->r16, 0X58);
    // 0x80038A4C: b           L_80038B14
    // 0x80038A50: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
        goto L_80038B14;
    // 0x80038A50: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
L_80038A54:
    // 0x80038A54: lbu         $t3, 0x0($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X0);
    // 0x80038A58: bnel        $s5, $t3, L_80038B04
    if (ctx->r21 != ctx->r11) {
        // 0x80038A5C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038B04;
    }
    goto skip_24;
    // 0x80038A5C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_24:
    // 0x80038A60: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80038A64: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80038A68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038A6C: beq         $s3, $a1, L_80038AD4
    if (ctx->r19 == ctx->r5) {
        // 0x80038A70: nop
    
            goto L_80038AD4;
    }
    // 0x80038A70: nop

    // 0x80038A74: beq         $a1, $at, L_80038AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80038A78: nop
    
            goto L_80038AD4;
    }
    // 0x80038A78: nop

    // 0x80038A7C: beq         $s6, $a1, L_80038AD4
    if (ctx->r22 == ctx->r5) {
        // 0x80038A80: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80038AD4;
    }
    // 0x80038A80: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80038A84: beq         $a1, $at, L_80038AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80038A88: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_80038AD4;
    }
    // 0x80038A88: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80038A8C: beq         $a1, $at, L_80038AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80038A90: addiu       $at, $zero, 0x7C
        ctx->r1 = ADD32(0, 0X7C);
            goto L_80038AD4;
    }
    // 0x80038A90: addiu       $at, $zero, 0x7C
    ctx->r1 = ADD32(0, 0X7C);
    // 0x80038A94: beq         $a1, $at, L_80038AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80038A98: addiu       $at, $zero, 0x7E
        ctx->r1 = ADD32(0, 0X7E);
            goto L_80038AD4;
    }
    // 0x80038A98: addiu       $at, $zero, 0x7E
    ctx->r1 = ADD32(0, 0X7E);
    // 0x80038A9C: beq         $a1, $at, L_80038AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80038AA0: addiu       $at, $zero, 0x2F
        ctx->r1 = ADD32(0, 0X2F);
            goto L_80038AD4;
    }
    // 0x80038AA0: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x80038AA4: beq         $a1, $at, L_80038AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80038AA8: nop
    
            goto L_80038AD4;
    }
    // 0x80038AA8: nop

    // 0x80038AAC: beq         $s5, $a1, L_80038AD4
    if (ctx->r21 == ctx->r5) {
        // 0x80038AB0: nop
    
            goto L_80038AD4;
    }
    // 0x80038AB0: nop

    // 0x80038AB4: beq         $s4, $a1, L_80038AD4
    if (ctx->r20 == ctx->r5) {
        // 0x80038AB8: addiu       $at, $zero, 0x43
        ctx->r1 = ADD32(0, 0X43);
            goto L_80038AD4;
    }
    // 0x80038AB8: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80038ABC: beq         $a1, $at, L_80038AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80038AC0: addiu       $at, $zero, 0x4A
        ctx->r1 = ADD32(0, 0X4A);
            goto L_80038AD4;
    }
    // 0x80038AC0: addiu       $at, $zero, 0x4A
    ctx->r1 = ADD32(0, 0X4A);
    // 0x80038AC4: beq         $a1, $at, L_80038AD4
    if (ctx->r5 == ctx->r1) {
        // 0x80038AC8: nop
    
            goto L_80038AD4;
    }
    // 0x80038AC8: nop

    // 0x80038ACC: bne         $s4, $a1, L_80038AE4
    if (ctx->r20 != ctx->r5) {
        // 0x80038AD0: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_80038AE4;
    }
    // 0x80038AD0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
L_80038AD4:
    // 0x80038AD4: jal         0x8003774C
    // 0x80038AD8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    PlayerShot_CheckPolyCollision(rdram, ctx);
        goto after_29;
    // 0x80038AD8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_29:
    // 0x80038ADC: b           L_80038B04
    // 0x80038AE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80038B04;
    // 0x80038AE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038AE4:
    // 0x80038AE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038AE8: jal         0x80036874
    // 0x80038AEC: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    PlayerShot_CheckObjectHitbox(rdram, ctx);
        goto after_30;
    // 0x80038AEC: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    after_30:
    // 0x80038AF0: beq         $v0, $zero, L_80038B00
    if (ctx->r2 == 0) {
        // 0x80038AF4: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80038B00;
    }
    // 0x80038AF4: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80038AF8: sb          $s3, 0x50($s0)
    MEM_B(0X50, ctx->r16) = ctx->r19;
    // 0x80038AFC: sw          $t4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r12;
L_80038B00:
    // 0x80038B00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038B04:
    // 0x80038B04: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80038B08: bne         $s2, $at, L_80038A54
    if (ctx->r18 != ctx->r1) {
        // 0x80038B0C: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_80038A54;
    }
    // 0x80038B0C: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x80038B10: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
L_80038B14:
    // 0x80038B14: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80038B18: addiu       $a2, $a2, 0x3400
    ctx->r6 = ADD32(ctx->r6, 0X3400);
    // 0x80038B1C: beq         $t5, $zero, L_80038B8C
    if (ctx->r13 == 0) {
        // 0x80038B20: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80038B8C;
    }
    // 0x80038B20: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80038B24: addiu       $s0, $zero, 0xA9
    ctx->r16 = ADD32(0, 0XA9);
L_80038B28:
    // 0x80038B28: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x80038B2C: bnel        $s5, $t6, L_80038B80
    if (ctx->r21 != ctx->r14) {
        // 0x80038B30: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038B80;
    }
    goto skip_25;
    // 0x80038B30: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_25:
    // 0x80038B34: lhu         $t7, 0x2($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X2);
    // 0x80038B38: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80038B3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038B40: beql        $s0, $t7, L_80038B68
    if (ctx->r16 == ctx->r15) {
        // 0x80038B44: lw          $a1, 0x28($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X28);
            goto L_80038B68;
    }
    goto skip_26;
    // 0x80038B44: lw          $a1, 0x28($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X28);
    skip_26:
    // 0x80038B48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038B4C: jal         0x80037698
    // 0x80038B50: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    PlayerShot_CheckSpriteHitbox(rdram, ctx);
        goto after_31;
    // 0x80038B50: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    after_31:
    // 0x80038B54: beq         $v0, $zero, L_80038B7C
    if (ctx->r2 == 0) {
        // 0x80038B58: lw          $a2, 0x6C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X6C);
            goto L_80038B7C;
    }
    // 0x80038B58: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80038B5C: b           L_80038B7C
    // 0x80038B60: sb          $s3, 0x46($a2)
    MEM_B(0X46, ctx->r6) = ctx->r19;
        goto L_80038B7C;
    // 0x80038B60: sb          $s3, 0x46($a2)
    MEM_B(0X46, ctx->r6) = ctx->r19;
    // 0x80038B64: lw          $a1, 0x28($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X28);
L_80038B68:
    // 0x80038B68: jal         0x80036874
    // 0x80038B6C: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    PlayerShot_CheckObjectHitbox(rdram, ctx);
        goto after_32;
    // 0x80038B6C: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    after_32:
    // 0x80038B70: beq         $v0, $zero, L_80038B7C
    if (ctx->r2 == 0) {
        // 0x80038B74: lw          $a2, 0x6C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X6C);
            goto L_80038B7C;
    }
    // 0x80038B74: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80038B78: sb          $s3, 0x46($a2)
    MEM_B(0X46, ctx->r6) = ctx->r19;
L_80038B7C:
    // 0x80038B7C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038B80:
    // 0x80038B80: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80038B84: bne         $s2, $at, L_80038B28
    if (ctx->r18 != ctx->r1) {
        // 0x80038B88: addiu       $a2, $a2, 0x4C
        ctx->r6 = ADD32(ctx->r6, 0X4C);
            goto L_80038B28;
    }
    // 0x80038B88: addiu       $a2, $a2, 0x4C
    ctx->r6 = ADD32(ctx->r6, 0X4C);
L_80038B8C:
    // 0x80038B8C: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x80038B90: addiu       $s0, $s0, -0xEF0
    ctx->r16 = ADD32(ctx->r16, -0XEF0);
    // 0x80038B94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80038B98:
    // 0x80038B98: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80038B9C: bnel        $s5, $t8, L_80038F04
    if (ctx->r21 != ctx->r24) {
        // 0x80038BA0: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038F04;
    }
    goto skip_27;
    // 0x80038BA0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_27:
    // 0x80038BA4: lh          $t9, 0x5A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X5A);
    // 0x80038BA8: bnel        $t9, $zero, L_80038F04
    if (ctx->r25 != 0) {
        // 0x80038BAC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038F04;
    }
    goto skip_28;
    // 0x80038BAC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_28:
    // 0x80038BB0: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80038BB4: addiu       $at, $zero, 0x134
    ctx->r1 = ADD32(0, 0X134);
    // 0x80038BB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038BBC: beq         $a1, $at, L_80038BDC
    if (ctx->r5 == ctx->r1) {
        // 0x80038BC0: addiu       $at, $zero, 0x138
        ctx->r1 = ADD32(0, 0X138);
            goto L_80038BDC;
    }
    // 0x80038BC0: addiu       $at, $zero, 0x138
    ctx->r1 = ADD32(0, 0X138);
    // 0x80038BC4: beq         $a1, $at, L_80038BDC
    if (ctx->r5 == ctx->r1) {
        // 0x80038BC8: addiu       $at, $zero, 0x135
        ctx->r1 = ADD32(0, 0X135);
            goto L_80038BDC;
    }
    // 0x80038BC8: addiu       $at, $zero, 0x135
    ctx->r1 = ADD32(0, 0X135);
    // 0x80038BCC: beq         $a1, $at, L_80038BDC
    if (ctx->r5 == ctx->r1) {
        // 0x80038BD0: addiu       $at, $zero, 0x139
        ctx->r1 = ADD32(0, 0X139);
            goto L_80038BDC;
    }
    // 0x80038BD0: addiu       $at, $zero, 0x139
    ctx->r1 = ADD32(0, 0X139);
    // 0x80038BD4: bnel        $a1, $at, L_80038BF0
    if (ctx->r5 != ctx->r1) {
        // 0x80038BD8: addiu       $at, $zero, 0x136
        ctx->r1 = ADD32(0, 0X136);
            goto L_80038BF0;
    }
    goto skip_29;
    // 0x80038BD8: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
    skip_29:
L_80038BDC:
    // 0x80038BDC: jal         0x8003774C
    // 0x80038BE0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    PlayerShot_CheckPolyCollision(rdram, ctx);
        goto after_33;
    // 0x80038BE0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_33:
    // 0x80038BE4: b           L_80038F04
    // 0x80038BE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80038F04;
    // 0x80038BE8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80038BEC: addiu       $at, $zero, 0x136
    ctx->r1 = ADD32(0, 0X136);
L_80038BF0:
    // 0x80038BF0: bnel        $a1, $at, L_80038CE8
    if (ctx->r5 != ctx->r1) {
        // 0x80038BF4: addiu       $at, $zero, 0x13C
        ctx->r1 = ADD32(0, 0X13C);
            goto L_80038CE8;
    }
    goto skip_30;
    // 0x80038BF4: addiu       $at, $zero, 0x13C
    ctx->r1 = ADD32(0, 0X13C);
    skip_30:
    // 0x80038BF8: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80038BFC: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038C00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80038C04: lwc1        $f6, 0x5264($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5264);
    // 0x80038C08: sub.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80038C0C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80038C10: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038C14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80038C18: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038C1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80038C20: mul.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80038C24: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80038C28: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80038C2C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80038C30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80038C34: lwc1        $f8, 0x5268($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5268);
    // 0x80038C38: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038C3C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80038C40: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80038C44: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038C48: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038C4C: mul.s       $f14, $f0, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80038C50: lwc1        $f8, 0x526C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X526C);
    // 0x80038C54: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80038C58: nop

    // 0x80038C5C: mul.s       $f18, $f12, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80038C60: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80038C64: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80038C68: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80038C6C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80038C70: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80038C74: nop

    // 0x80038C78: bc1f        L_80038F00
    if (!c1cs) {
        // 0x80038C7C: nop
    
            goto L_80038F00;
    }
    // 0x80038C7C: nop

    // 0x80038C80: lhu         $t0, 0x2($s1)
    ctx->r8 = MEM_HU(ctx->r17, 0X2);
    // 0x80038C84: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    // 0x80038C88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038C8C: bnel        $s6, $t0, L_80038CA8
    if (ctx->r22 != ctx->r8) {
        // 0x80038C90: sb          $s3, 0x62($s0)
        MEM_B(0X62, ctx->r16) = ctx->r19;
            goto L_80038CA8;
    }
    goto skip_31;
    // 0x80038C90: sb          $s3, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r19;
    skip_31:
    // 0x80038C94: jal         0x80060FBC
    // 0x80038C98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Object_Kill(rdram, ctx);
        goto after_34;
    // 0x80038C98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_34:
    // 0x80038C9C: b           L_80038F04
    // 0x80038CA0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80038F04;
    // 0x80038CA0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80038CA4: sb          $s3, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r19;
L_80038CA8:
    // 0x80038CA8: jal         0x80036318
    // 0x80038CAC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    PlayerShot_Impact(rdram, ctx);
        goto after_35;
    // 0x80038CAC: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    after_35:
    // 0x80038CB0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80038CB4: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80038CB8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80038CBC: addiu       $t1, $t1, 0x5D3C
    ctx->r9 = ADD32(ctx->r9, 0X5D3C);
    // 0x80038CC0: lui         $a0, 0x2900
    ctx->r4 = S32(0X2900 << 16);
    // 0x80038CC4: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x80038CC8: ori         $a0, $a0, 0x1062
    ctx->r4 = ctx->r4 | 0X1062;
    // 0x80038CCC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80038CD0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80038CD4: jal         0x80019218
    // 0x80038CD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_36;
    // 0x80038CD8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_36:
    // 0x80038CDC: b           L_80038F04
    // 0x80038CE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80038F04;
    // 0x80038CE0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80038CE4: addiu       $at, $zero, 0x13C
    ctx->r1 = ADD32(0, 0X13C);
L_80038CE8:
    // 0x80038CE8: bnel        $a1, $at, L_80038DC4
    if (ctx->r5 != ctx->r1) {
        // 0x80038CEC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80038DC4;
    }
    goto skip_32;
    // 0x80038CEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_32:
    // 0x80038CF0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80038CF4: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038CF8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80038CFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038D00: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80038D04: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80038D08: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038D0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80038D10: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038D14: lwc1        $f18, 0x5270($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5270);
    // 0x80038D18: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80038D1C: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80038D20: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80038D24: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80038D28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80038D2C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038D30: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80038D34: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80038D38: lwc1        $f6, 0x5274($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5274);
    // 0x80038D3C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80038D40: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80038D44: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80038D48: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80038D4C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80038D50: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80038D54: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80038D58: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80038D5C: nop

    // 0x80038D60: bc1fl       L_80038DC4
    if (!c1cs) {
        // 0x80038D64: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80038DC4;
    }
    goto skip_33;
    // 0x80038D64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_33:
    // 0x80038D68: lhu         $t2, 0x2($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X2);
    // 0x80038D6C: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    // 0x80038D70: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80038D74: bne         $s6, $t2, L_80038D8C
    if (ctx->r22 != ctx->r10) {
        // 0x80038D78: lui         $a0, 0x2912
        ctx->r4 = S32(0X2912 << 16);
            goto L_80038D8C;
    }
    // 0x80038D78: lui         $a0, 0x2912
    ctx->r4 = S32(0X2912 << 16);
    // 0x80038D7C: jal         0x80060FBC
    // 0x80038D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Object_Kill(rdram, ctx);
        goto after_37;
    // 0x80038D80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_37:
    // 0x80038D84: b           L_80038DC4
    // 0x80038D88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_80038DC4;
    // 0x80038D88: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80038D8C:
    // 0x80038D8C: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80038D90: lui         $t5, 0x800C
    ctx->r13 = S32(0X800C << 16);
    // 0x80038D94: sb          $s3, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r19;
    // 0x80038D98: sh          $t3, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r11;
    // 0x80038D9C: addiu       $t5, $t5, 0x5D3C
    ctx->r13 = ADD32(ctx->r13, 0X5D3C);
    // 0x80038DA0: addiu       $a3, $t4, 0x5D34
    ctx->r7 = ADD32(ctx->r12, 0X5D34);
    // 0x80038DA4: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80038DA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80038DAC: ori         $a0, $a0, 0x1007
    ctx->r4 = ctx->r4 | 0X1007;
    // 0x80038DB0: jal         0x80019218
    // 0x80038DB4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_38;
    // 0x80038DB4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_38:
    // 0x80038DB8: jal         0x80036318
    // 0x80038DBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    PlayerShot_Impact(rdram, ctx);
        goto after_39;
    // 0x80038DBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_39:
    // 0x80038DC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80038DC4:
    // 0x80038DC4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x80038DC8: jal         0x80036874
    // 0x80038DCC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    PlayerShot_CheckObjectHitbox(rdram, ctx);
        goto after_40;
    // 0x80038DCC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_40:
    // 0x80038DD0: beql        $v0, $zero, L_80038F04
    if (ctx->r2 == 0) {
        // 0x80038DD4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038F04;
    }
    goto skip_34;
    // 0x80038DD4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_34:
    // 0x80038DD8: lhu         $t6, 0x2($s1)
    ctx->r14 = MEM_HU(ctx->r17, 0X2);
    // 0x80038DDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80038DE0: bnel        $s6, $t6, L_80038DFC
    if (ctx->r22 != ctx->r14) {
        // 0x80038DE4: lhu         $t7, 0x2($s0)
        ctx->r15 = MEM_HU(ctx->r16, 0X2);
            goto L_80038DFC;
    }
    goto skip_35;
    // 0x80038DE4: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
    skip_35:
    // 0x80038DE8: jal         0x80060FBC
    // 0x80038DEC: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    Object_Kill(rdram, ctx);
        goto after_41;
    // 0x80038DEC: addiu       $a1, $s1, 0x38
    ctx->r5 = ADD32(ctx->r17, 0X38);
    after_41:
    // 0x80038DF0: b           L_80038F04
    // 0x80038DF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80038F04;
    // 0x80038DF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80038DF8: lhu         $t7, 0x2($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X2);
L_80038DFC:
    // 0x80038DFC: addiu       $at, $zero, 0x13C
    ctx->r1 = ADD32(0, 0X13C);
    // 0x80038E00: bnel        $t7, $at, L_80038E18
    if (ctx->r15 != ctx->r1) {
        // 0x80038E04: sb          $s3, 0x62($s0)
        MEM_B(0X62, ctx->r16) = ctx->r19;
            goto L_80038E18;
    }
    goto skip_36;
    // 0x80038E04: sb          $s3, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r19;
    skip_36:
    // 0x80038E08: lw          $t8, 0x68($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X68);
    // 0x80038E0C: bnel        $t8, $zero, L_80038F10
    if (ctx->r24 != 0) {
        // 0x80038E10: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80038F10;
    }
    goto skip_37;
    // 0x80038E10: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_37:
    // 0x80038E14: sb          $s3, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r19;
L_80038E18:
    // 0x80038E18: lhu         $v1, 0x2($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X2);
    // 0x80038E1C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80038E20: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80038E24: bne         $s4, $v1, L_80038E3C
    if (ctx->r20 != ctx->r3) {
        // 0x80038E28: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80038E3C;
    }
    // 0x80038E28: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80038E2C: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80038E30: sb          $t9, 0x62($s0)
    MEM_B(0X62, ctx->r16) = ctx->r25;
    // 0x80038E34: b           L_80038EA8
    // 0x80038E38: sh          $t0, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r8;
        goto L_80038EA8;
    // 0x80038E38: sh          $t0, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r8;
L_80038E3C:
    // 0x80038E3C: bne         $v1, $at, L_80038E6C
    if (ctx->r3 != ctx->r1) {
        // 0x80038E40: addiu       $t4, $zero, 0xA
        ctx->r12 = ADD32(0, 0XA);
            goto L_80038E6C;
    }
    // 0x80038E40: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80038E44: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x80038E48: lw          $t1, -0x7DCC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7DCC);
    // 0x80038E4C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80038E50: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80038E54: bne         $t1, $at, L_80038E64
    if (ctx->r9 != ctx->r1) {
        // 0x80038E58: addiu       $t3, $zero, 0x1E
        ctx->r11 = ADD32(0, 0X1E);
            goto L_80038E64;
    }
    // 0x80038E58: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80038E5C: b           L_80038EA8
    // 0x80038E60: sh          $t2, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r10;
        goto L_80038EA8;
    // 0x80038E60: sh          $t2, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r10;
L_80038E64:
    // 0x80038E64: b           L_80038EA8
    // 0x80038E68: sh          $t3, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r11;
        goto L_80038EA8;
    // 0x80038E68: sh          $t3, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r11;
L_80038E6C:
    // 0x80038E6C: sh          $t4, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r12;
    // 0x80038E70: lw          $a0, 0x68($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X68);
    // 0x80038E74: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x80038E78: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80038E7C: beq         $at, $zero, L_80038EA8
    if (ctx->r1 == 0) {
        // 0x80038E80: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_80038EA8;
    }
    // 0x80038E80: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x80038E84: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
    // 0x80038E88: lw          $v1, 0x1AA8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1AA8);
    // 0x80038E8C: beql        $v1, $zero, L_80038EAC
    if (ctx->r3 == 0) {
        // 0x80038E90: lhu         $a1, 0x2($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X2);
            goto L_80038EAC;
    }
    goto skip_38;
    // 0x80038E90: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    skip_38:
    // 0x80038E94: beql        $v1, $s3, L_80038EAC
    if (ctx->r3 == ctx->r19) {
        // 0x80038E98: lhu         $a1, 0x2($s0)
        ctx->r5 = MEM_HU(ctx->r16, 0X2);
            goto L_80038EAC;
    }
    goto skip_39;
    // 0x80038E98: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    skip_39:
    // 0x80038E9C: bne         $v1, $s5, L_80038EA8
    if (ctx->r3 != ctx->r21) {
        // 0x80038EA0: addiu       $t6, $zero, 0xF
        ctx->r14 = ADD32(0, 0XF);
            goto L_80038EA8;
    }
    // 0x80038EA0: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80038EA4: sh          $t6, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r14;
L_80038EA8:
    // 0x80038EA8: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
L_80038EAC:
    // 0x80038EAC: addiu       $at, $zero, 0x13A
    ctx->r1 = ADD32(0, 0X13A);
    // 0x80038EB0: bnel        $a1, $at, L_80038EC8
    if (ctx->r5 != ctx->r1) {
        // 0x80038EB4: addiu       $at, $zero, 0x12D
        ctx->r1 = ADD32(0, 0X12D);
            goto L_80038EC8;
    }
    goto skip_40;
    // 0x80038EB4: addiu       $at, $zero, 0x12D
    ctx->r1 = ADD32(0, 0X12D);
    skip_40:
    // 0x80038EB8: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x80038EBC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80038EC0: sh          $t7, 0xAE($s0)
    MEM_H(0XAE, ctx->r16) = ctx->r15;
    // 0x80038EC4: addiu       $at, $zero, 0x12D
    ctx->r1 = ADD32(0, 0X12D);
L_80038EC8:
    // 0x80038EC8: bne         $a1, $at, L_80038EDC
    if (ctx->r5 != ctx->r1) {
        // 0x80038ECC: sh          $t8, 0x66($s0)
        MEM_H(0X66, ctx->r16) = ctx->r24;
            goto L_80038EDC;
    }
    // 0x80038ECC: sh          $t8, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r24;
    // 0x80038ED0: lhu         $t9, 0x2($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X2);
    // 0x80038ED4: b           L_80038F00
    // 0x80038ED8: sh          $t9, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r25;
        goto L_80038F00;
    // 0x80038ED8: sh          $t9, 0x92($s0)
    MEM_H(0X92, ctx->r16) = ctx->r25;
L_80038EDC:
    // 0x80038EDC: addiu       $at, $zero, 0x13F
    ctx->r1 = ADD32(0, 0X13F);
    // 0x80038EE0: bnel        $a1, $at, L_80038F04
    if (ctx->r5 != ctx->r1) {
        // 0x80038EE4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80038F04;
    }
    goto skip_41;
    // 0x80038EE4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_41:
    // 0x80038EE8: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80038EEC: swc1        $f8, 0x194($s0)
    MEM_W(0X194, ctx->r16) = ctx->f8.u32l;
    // 0x80038EF0: lwc1        $f10, 0x8($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80038EF4: swc1        $f10, 0x198($s0)
    MEM_W(0X198, ctx->r16) = ctx->f10.u32l;
    // 0x80038EF8: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80038EFC: swc1        $f18, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = ctx->f18.u32l;
L_80038F00:
    // 0x80038F00: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80038F04:
    // 0x80038F04: bne         $s2, $s6, L_80038B98
    if (ctx->r18 != ctx->r22) {
        // 0x80038F08: addiu       $s0, $s0, 0x408
        ctx->r16 = ADD32(ctx->r16, 0X408);
            goto L_80038B98;
    }
    // 0x80038F08: addiu       $s0, $s0, 0x408
    ctx->r16 = ADD32(ctx->r16, 0X408);
L_80038F0C:
    // 0x80038F0C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80038F10:
    // 0x80038F10: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80038F14: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80038F18: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80038F1C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80038F20: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80038F24: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80038F28: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80038F2C: jr          $ra
    // 0x80038F30: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80038F30: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void PlayerShot_SearchLockOnTarget(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BEF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003BEF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003BEFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003BF00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003BF04: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003BF08: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x8003BF0C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003BF10: beql        $t6, $zero, L_8003BF8C
    if (ctx->r14 == 0) {
        // 0x8003BF14: lwc1        $f8, 0x8($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
            goto L_8003BF8C;
    }
    goto skip_0;
    // 0x8003BF14: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    skip_0:
    // 0x8003BF18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003BF1C: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003BF20: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003BF24: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003BF28: nop

    // 0x8003BF2C: bc1tl       L_8003BF78
    if (c1cs) {
        // 0x8003BF30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003BF78;
    }
    goto skip_1;
    // 0x8003BF30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x8003BF34: jal         0x8003BB4C
    // 0x8003BF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_FindLockTarget(rdram, ctx);
        goto after_0;
    // 0x8003BF38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8003BF3C: bnel        $v0, $zero, L_8003BF78
    if (ctx->r2 != 0) {
        // 0x8003BF40: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003BF78;
    }
    goto skip_2;
    // 0x8003BF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x8003BF44: lw          $t7, 0x68($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X68);
    // 0x8003BF48: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8003BF4C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003BF50: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8003BF54: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8003BF58: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8003BF5C: lhu         $t9, -0x2780($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X2780);
    // 0x8003BF60: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x8003BF64: beql        $t0, $zero, L_8003BF78
    if (ctx->r8 == 0) {
        // 0x8003BF68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003BF78;
    }
    goto skip_3;
    // 0x8003BF68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x8003BF6C: lw          $t1, 0x64($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X64);
    // 0x8003BF70: bne         $t1, $zero, L_8003BFEC
    if (ctx->r9 != 0) {
        // 0x8003BF74: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003BFEC;
    }
    // 0x8003BF74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003BF78:
    // 0x8003BF78: jal         0x80060FBC
    // 0x8003BF7C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x8003BF7C: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_1:
    // 0x8003BF80: b           L_8003BFEC
    // 0x8003BF84: nop

        goto L_8003BFEC;
    // 0x8003BF84: nop

    // 0x8003BF88: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
L_8003BF8C:
    // 0x8003BF8C: lwc1        $f10, 0x7940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8003BF90: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8003BF94: nop

    // 0x8003BF98: bc1tl       L_8003BFE4
    if (c1cs) {
        // 0x8003BF9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003BFE4;
    }
    goto skip_4;
    // 0x8003BF9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x8003BFA0: jal         0x8003BB4C
    // 0x8003BFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_FindLockTarget(rdram, ctx);
        goto after_2;
    // 0x8003BFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003BFA8: bne         $v0, $zero, L_8003BFE0
    if (ctx->r2 != 0) {
        // 0x8003BFAC: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_8003BFE0;
    }
    // 0x8003BFAC: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8003BFB0: lw          $t2, 0x7AF8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7AF8);
    // 0x8003BFB4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8003BFB8: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8003BFBC: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8003BFC0: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x8003BFC4: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8003BFC8: lhu         $t4, -0x2780($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0X2780);
    // 0x8003BFCC: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8003BFD0: beql        $t5, $zero, L_8003BFE4
    if (ctx->r13 == 0) {
        // 0x8003BFD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003BFE4;
    }
    goto skip_5;
    // 0x8003BFD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_5:
    // 0x8003BFD8: lw          $t6, 0x64($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X64);
    // 0x8003BFDC: bne         $t6, $zero, L_8003BFEC
    if (ctx->r14 != 0) {
        // 0x8003BFE0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003BFEC;
    }
L_8003BFE0:
    // 0x8003BFE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003BFE4:
    // 0x8003BFE4: jal         0x80060FBC
    // 0x8003BFE8: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    Object_Kill(rdram, ctx);
        goto after_3;
    // 0x8003BFE8: addiu       $a1, $s0, 0x38
    ctx->r5 = ADD32(ctx->r16, 0X38);
    after_3:
L_8003BFEC:
    // 0x8003BFEC: jal         0x80038140
    // 0x8003BFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    PlayerShot_CollisionCheck(rdram, ctx);
        goto after_4;
    // 0x8003BFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8003BFF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003BFF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003BFFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003C000: jr          $ra
    // 0x8003C004: nop

    return;
    // 0x8003C004: nop

;}
RECOMP_FUNC void Effect_Effect383_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A568: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007A56C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A570: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8007A574: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x8007A578: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8007A57C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8007A580: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007A584: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007A588: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x8007A58C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007A590: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007A594:
    // 0x8007A594: bnel        $t6, $zero, L_8007A5C0
    if (ctx->r14 != 0) {
        // 0x8007A598: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007A5C0;
    }
    goto skip_0;
    // 0x8007A598: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007A59C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007A5A0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8007A5A4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8007A5A8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8007A5AC: jal         0x8007A4B8
    // 0x8007A5B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Effect_Effect383_Setup(rdram, ctx);
        goto after_0;
    // 0x8007A5B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8007A5B4: b           L_8007A5D0
    // 0x8007A5B8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
        goto L_8007A5D0;
    // 0x8007A5B8: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8007A5BC: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007A5C0:
    // 0x8007A5C0: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x8007A5C4: beql        $at, $zero, L_8007A594
    if (ctx->r1 == 0) {
        // 0x8007A5C8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007A594;
    }
    goto skip_1;
    // 0x8007A5C8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007A5CC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
L_8007A5D0:
    // 0x8007A5D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007A5D4: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007A5D8: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007A5DC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8007A5E0: jal         0x8007B344
    // 0x8007A5E4: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_1;
    // 0x8007A5E4: lui         $a3, 0x42A0
    ctx->r7 = S32(0X42A0 << 16);
    after_1:
    // 0x8007A5E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A5EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8007A5F0: jr          $ra
    // 0x8007A5F4: nop

    return;
    // 0x8007A5F4: nop

;}
