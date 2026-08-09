#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void AudioLoad_InitTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EBB4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000EBB8: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8000EBBC: sh          $a2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r6;
    // 0x8000EBC0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8000EBC4: blez        $v1, L_8000EC0C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000EBC8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000EC0C;
    }
    // 0x8000EBC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000EBCC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8000EBD0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
L_8000EBD4:
    // 0x8000EBD4: lw          $t7, 0x14($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X14);
    // 0x8000EBD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000EBDC: beql        $t7, $zero, L_8000EC04
    if (ctx->r15 == 0) {
        // 0x8000EBE0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000EC04;
    }
    goto skip_0;
    // 0x8000EBE0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x8000EBE4: lb          $t8, 0x18($a2)
    ctx->r24 = MEM_B(ctx->r6, 0X18);
    // 0x8000EBE8: bnel        $a3, $t8, L_8000EC04
    if (ctx->r7 != ctx->r24) {
        // 0x8000EBEC: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8000EC04;
    }
    goto skip_1;
    // 0x8000EBEC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
    // 0x8000EBF0: lw          $t9, 0x10($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X10);
    // 0x8000EBF4: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x8000EBF8: sw          $t0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r8;
    // 0x8000EBFC: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x8000EC00: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8000EC04:
    // 0x8000EC04: bne         $at, $zero, L_8000EBD4
    if (ctx->r1 != 0) {
        // 0x8000EC08: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_8000EBD4;
    }
    // 0x8000EC08: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
L_8000EC0C:
    // 0x8000EC0C: jr          $ra
    // 0x8000EC10: nop

    return;
    // 0x8000EC10: nop

;}
RECOMP_FUNC void Audio_NotePoolClear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012964: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80012968: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001296C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80012970: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80012974: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80012978: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001297C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80012980: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80012984: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80012988: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8001298C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80012990: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80012994: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80012998: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001299C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800129A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800129A4: addiu       $v0, $v0, 0x30F0
    ctx->r2 = ADD32(ctx->r2, 0X30F0);
    // 0x800129A8: addiu       $v1, $v1, 0x30E0
    ctx->r3 = ADD32(ctx->r3, 0X30E0);
    // 0x800129AC: addiu       $a1, $a1, 0x30D0
    ctx->r5 = ADD32(ctx->r5, 0X30D0);
    // 0x800129B0: addiu       $a2, $a2, 0x30C0
    ctx->r6 = ADD32(ctx->r6, 0X30C0);
    // 0x800129B4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x800129B8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800129BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800129C0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x800129C4: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x800129C8: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x800129CC: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
L_800129D0:
    // 0x800129D0: beql        $s3, $zero, L_800129FC
    if (ctx->r19 == 0) {
        // 0x800129D4: or          $s1, $s4, $zero
        ctx->r17 = ctx->r20 | 0;
            goto L_800129FC;
    }
    goto skip_0;
    // 0x800129D4: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    skip_0:
    // 0x800129D8: beql        $s3, $s5, L_80012A0C
    if (ctx->r19 == ctx->r21) {
        // 0x800129DC: addiu       $s1, $s4, 0x10
        ctx->r17 = ADD32(ctx->r20, 0X10);
            goto L_80012A0C;
    }
    goto skip_1;
    // 0x800129DC: addiu       $s1, $s4, 0x10
    ctx->r17 = ADD32(ctx->r20, 0X10);
    skip_1:
    // 0x800129E0: beql        $s3, $s6, L_80012A1C
    if (ctx->r19 == ctx->r22) {
        // 0x800129E4: addiu       $s1, $s4, 0x20
        ctx->r17 = ADD32(ctx->r20, 0X20);
            goto L_80012A1C;
    }
    goto skip_2;
    // 0x800129E4: addiu       $s1, $s4, 0x20
    ctx->r17 = ADD32(ctx->r20, 0X20);
    skip_2:
    // 0x800129E8: beql        $s3, $s7, L_80012A2C
    if (ctx->r19 == ctx->r23) {
        // 0x800129EC: addiu       $s1, $s4, 0x30
        ctx->r17 = ADD32(ctx->r20, 0X30);
            goto L_80012A2C;
    }
    goto skip_3;
    // 0x800129EC: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
    skip_3:
    // 0x800129F0: b           L_80012A34
    // 0x800129F4: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
        goto L_80012A34;
    // 0x800129F4: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x800129F8: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
L_800129FC:
    // 0x800129FC: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x80012A00: b           L_80012A34
    // 0x80012A04: lw          $s0, 0x4($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X4);
        goto L_80012A34;
    // 0x80012A04: lw          $s0, 0x4($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X4);
    // 0x80012A08: addiu       $s1, $s4, 0x10
    ctx->r17 = ADD32(ctx->r20, 0X10);
L_80012A0C:
    // 0x80012A0C: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80012A10: b           L_80012A34
    // 0x80012A14: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
        goto L_80012A34;
    // 0x80012A14: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80012A18: addiu       $s1, $s4, 0x20
    ctx->r17 = ADD32(ctx->r20, 0X20);
L_80012A1C:
    // 0x80012A1C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
    // 0x80012A20: b           L_80012A34
    // 0x80012A24: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
        goto L_80012A34;
    // 0x80012A24: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80012A28: addiu       $s1, $s4, 0x30
    ctx->r17 = ADD32(ctx->r20, 0X30);
L_80012A2C:
    // 0x80012A2C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80012A30: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
L_80012A34:
    // 0x80012A34: beql        $s0, $s1, L_80012A84
    if (ctx->r16 == ctx->r17) {
        // 0x80012A38: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80012A84;
    }
    goto skip_4;
    // 0x80012A38: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
L_80012A3C:
    // 0x80012A3C: beql        $s0, $zero, L_80012A84
    if (ctx->r16 == 0) {
        // 0x80012A40: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80012A84;
    }
    goto skip_5;
    // 0x80012A40: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_5:
    // 0x80012A44: jal         0x80012C40
    // 0x80012A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_AudioListRemove(rdram, ctx);
        goto after_0;
    // 0x80012A48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80012A4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80012A50: jal         0x800145BC
    // 0x80012A54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_1;
    // 0x80012A54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80012A58: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x80012A5C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x80012A60: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80012A64: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x80012A68: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x80012A6C: addiu       $v0, $v0, 0x30F0
    ctx->r2 = ADD32(ctx->r2, 0X30F0);
    // 0x80012A70: addiu       $v1, $v1, 0x30E0
    ctx->r3 = ADD32(ctx->r3, 0X30E0);
    // 0x80012A74: addiu       $a1, $a1, 0x30D0
    ctx->r5 = ADD32(ctx->r5, 0X30D0);
    // 0x80012A78: bne         $s0, $s1, L_80012A3C
    if (ctx->r16 != ctx->r17) {
        // 0x80012A7C: addiu       $a2, $a2, 0x30C0
        ctx->r6 = ADD32(ctx->r6, 0X30C0);
            goto L_80012A3C;
    }
    // 0x80012A7C: addiu       $a2, $a2, 0x30C0
    ctx->r6 = ADD32(ctx->r6, 0X30C0);
    // 0x80012A80: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80012A84:
    // 0x80012A84: bne         $s3, $fp, L_800129D0
    if (ctx->r19 != ctx->r30) {
        // 0x80012A88: nop
    
            goto L_800129D0;
    }
    // 0x80012A88: nop

    // 0x80012A8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80012A90: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80012A94: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80012A98: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012A9C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80012AA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80012AA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80012AA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80012AAC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80012AB0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80012AB4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80012AB8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80012ABC: jr          $ra
    // 0x80012AC0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80012AC0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Fault_Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000762C: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x80007630: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80007634: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80007638: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000763C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80007640: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80007644: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80007648: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000764C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80007650: sw          $a2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r6;
    // 0x80007654: sw          $a3, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r7;
    // 0x80007658: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x8000765C: addiu       $v1, $sp, 0x140
    ctx->r3 = ADD32(ctx->r29, 0X140);
L_80007660:
    // 0x80007660: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80007664: sb          $zero, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = 0;
    // 0x80007668: sb          $zero, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = 0;
    // 0x8000766C: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x80007670: bne         $v0, $v1, L_80007660
    if (ctx->r2 != ctx->r3) {
        // 0x80007674: sb          $zero, -0x4($v0)
        MEM_B(-0X4, ctx->r2) = 0;
            goto L_80007660;
    }
    // 0x80007674: sb          $zero, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = 0;
    // 0x80007678: addiu       $s2, $sp, 0x40
    ctx->r18 = ADD32(ctx->r29, 0X40);
    // 0x8000767C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80007680: addiu       $a0, $a0, 0x7604
    ctx->r4 = ADD32(ctx->r4, 0X7604);
    // 0x80007684: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80007688: lw          $a2, 0x150($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X150);
    // 0x8000768C: jal         0x800246D0
    // 0x80007690: addiu       $a3, $sp, 0x154
    ctx->r7 = ADD32(ctx->r29, 0X154);
    _Printf(rdram, ctx);
        goto after_0;
    // 0x80007690: addiu       $a3, $sp, 0x154
    ctx->r7 = ADD32(ctx->r29, 0X154);
    after_0:
    // 0x80007694: blez        $v0, L_800076EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80007698: lbu         $t6, 0x40($sp)
        ctx->r14 = MEM_BU(ctx->r29, 0X40);
            goto L_800076EC;
    }
    // 0x80007698: lbu         $t6, 0x40($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X40);
    // 0x8000769C: beq         $t6, $zero, L_800076EC
    if (ctx->r14 == 0) {
        // 0x800076A0: or          $s0, $s2, $zero
        ctx->r16 = ctx->r18 | 0;
            goto L_800076EC;
    }
    // 0x800076A0: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x800076A4: addiu       $t7, $sp, 0x40
    ctx->r15 = ADD32(ctx->r29, 0X40);
    // 0x800076A8: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x800076AC: addiu       $s2, $s2, 0x46F0
    ctx->r18 = ADD32(ctx->r18, 0X46F0);
    // 0x800076B0: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800076B4: addiu       $s3, $zero, 0xFF
    ctx->r19 = ADD32(0, 0XFF);
    // 0x800076B8: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
L_800076BC:
    // 0x800076BC: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x800076C0: lbu         $a2, 0x0($t9)
    ctx->r6 = MEM_BU(ctx->r25, 0X0);
    // 0x800076C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800076C8: beql        $a2, $s3, L_800076DC
    if (ctx->r6 == ctx->r19) {
        // 0x800076CC: addiu       $s1, $s1, 0x6
        ctx->r17 = ADD32(ctx->r17, 0X6);
            goto L_800076DC;
    }
    goto skip_0;
    // 0x800076CC: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
    skip_0:
    // 0x800076D0: jal         0x800074AC
    // 0x800076D4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    Fault_DisplayChar(rdram, ctx);
        goto after_1;
    // 0x800076D4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800076D8: addiu       $s1, $s1, 0x6
    ctx->r17 = ADD32(ctx->r17, 0X6);
L_800076DC:
    // 0x800076DC: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x800076E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800076E4: bnel        $v0, $zero, L_800076BC
    if (ctx->r2 != 0) {
        // 0x800076E8: andi        $t8, $v0, 0x7F
        ctx->r24 = ctx->r2 & 0X7F;
            goto L_800076BC;
    }
    goto skip_1;
    // 0x800076E8: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    skip_1:
L_800076EC:
    // 0x800076EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800076F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800076F4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800076F8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800076FC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80007700: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80007704: jr          $ra
    // 0x80007708: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x80007708: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void Matrix_MultVec3fNoTranslate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006A20: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80006A24: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80006A28: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80006A2C: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80006A30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80006A34: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80006A38: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80006A3C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80006A40: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80006A44: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80006A48: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80006A4C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x80006A50: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80006A54: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80006A58: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80006A5C: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80006A60: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80006A64: lwc1        $f6, 0x24($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X24);
    // 0x80006A68: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80006A6C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80006A70: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80006A74: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80006A78: add.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80006A7C: swc1        $f10, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f10.u32l;
    // 0x80006A80: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80006A84: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80006A88: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80006A8C: lwc1        $f4, 0x18($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80006A90: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80006A94: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80006A98: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80006A9C: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80006AA0: mul.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80006AA4: add.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80006AA8: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80006AAC: swc1        $f16, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f16.u32l;
    // 0x80006AB0: jr          $ra
    // 0x80006AB4: nop

    return;
    // 0x80006AB4: nop

;}
RECOMP_FUNC void Boss_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069CBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80069CC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80069CC4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80069CC8: lh          $v0, 0x50($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X50);
    // 0x80069CCC: beq         $v0, $zero, L_80069CD8
    if (ctx->r2 == 0) {
        // 0x80069CD0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80069CD8;
    }
    // 0x80069CD0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80069CD4: sh          $t6, 0x50($a2)
    MEM_H(0X50, ctx->r6) = ctx->r14;
L_80069CD8:
    // 0x80069CD8: lh          $v0, 0x52($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X52);
    // 0x80069CDC: beq         $v0, $zero, L_80069CE8
    if (ctx->r2 == 0) {
        // 0x80069CE0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80069CE8;
    }
    // 0x80069CE0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80069CE4: sh          $t7, 0x52($a2)
    MEM_H(0X52, ctx->r6) = ctx->r15;
L_80069CE8:
    // 0x80069CE8: lh          $v0, 0x54($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X54);
    // 0x80069CEC: beq         $v0, $zero, L_80069CF8
    if (ctx->r2 == 0) {
        // 0x80069CF0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80069CF8;
    }
    // 0x80069CF0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80069CF4: sh          $t8, 0x54($a2)
    MEM_H(0X54, ctx->r6) = ctx->r24;
L_80069CF8:
    // 0x80069CF8: lh          $v0, 0x56($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X56);
    // 0x80069CFC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80069D00: beq         $v0, $zero, L_80069D0C
    if (ctx->r2 == 0) {
        // 0x80069D04: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80069D0C;
    }
    // 0x80069D04: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80069D08: sh          $t9, 0x56($a2)
    MEM_H(0X56, ctx->r6) = ctx->r25;
L_80069D0C:
    // 0x80069D0C: lh          $v0, 0x58($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X58);
    // 0x80069D10: beq         $v0, $zero, L_80069D1C
    if (ctx->r2 == 0) {
        // 0x80069D14: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80069D1C;
    }
    // 0x80069D14: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80069D18: sh          $t0, 0x58($a2)
    MEM_H(0X58, ctx->r6) = ctx->r8;
L_80069D1C:
    // 0x80069D1C: lh          $v0, 0x5A($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X5A);
    // 0x80069D20: beq         $v0, $zero, L_80069D2C
    if (ctx->r2 == 0) {
        // 0x80069D24: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_80069D2C;
    }
    // 0x80069D24: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80069D28: sh          $t1, 0x5A($a2)
    MEM_H(0X5A, ctx->r6) = ctx->r9;
L_80069D2C:
    // 0x80069D2C: lh          $v0, 0x5C($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X5C);
    // 0x80069D30: beq         $v0, $zero, L_80069D3C
    if (ctx->r2 == 0) {
        // 0x80069D34: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80069D3C;
    }
    // 0x80069D34: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80069D38: sh          $t2, 0x5C($a2)
    MEM_H(0X5C, ctx->r6) = ctx->r10;
L_80069D3C:
    // 0x80069D3C: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80069D40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80069D44: beq         $v0, $at, L_80069D68
    if (ctx->r2 == ctx->r1) {
        // 0x80069D48: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80069D68;
    }
    // 0x80069D48: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80069D4C: beq         $v0, $at, L_80069D8C
    if (ctx->r2 == ctx->r1) {
        // 0x80069D50: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80069D8C;
    }
    // 0x80069D50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80069D54: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80069D58: beq         $v0, $at, L_80069DC0
    if (ctx->r2 == ctx->r1) {
        // 0x80069D5C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80069DC0;
    }
    // 0x80069D5C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80069D60: b           L_80069DE8
    // 0x80069D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069DE8;
    // 0x80069D64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069D68:
    // 0x80069D68: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x80069D6C: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    // 0x80069D70: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x80069D74: jal         0x80063F90
    // 0x80069D78: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Object_Init(rdram, ctx);
        goto after_0;
    // 0x80069D78: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80069D7C: jal         0x80069658
    // 0x80069D80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    Boss_Move(rdram, ctx);
        goto after_1;
    // 0x80069D80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80069D84: b           L_80069DE8
    // 0x80069D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069DE8;
    // 0x80069D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069D8C:
    // 0x80069D8C: jal         0x80069658
    // 0x80069D90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Boss_Move(rdram, ctx);
        goto after_2;
    // 0x80069D90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_2:
    // 0x80069D94: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80069D98: lbu         $t4, 0x0($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X0);
    // 0x80069D9C: beql        $t4, $zero, L_80069DE8
    if (ctx->r12 == 0) {
        // 0x80069DA0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069DE8;
    }
    goto skip_0;
    // 0x80069DA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80069DA4: lw          $v0, 0x24($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X24);
    // 0x80069DA8: beql        $v0, $zero, L_80069DE8
    if (ctx->r2 == 0) {
        // 0x80069DAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069DE8;
    }
    goto skip_1;
    // 0x80069DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80069DB0: jalr        $v0
    // 0x80069DB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80069DB4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80069DB8: b           L_80069DE8
    // 0x80069DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80069DE8;
    // 0x80069DBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069DC0:
    // 0x80069DC0: jal         0x80069658
    // 0x80069DC4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Boss_Move(rdram, ctx);
        goto after_4;
    // 0x80069DC4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_4:
    // 0x80069DC8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80069DCC: lbu         $t5, 0x0($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X0);
    // 0x80069DD0: beql        $t5, $zero, L_80069DE8
    if (ctx->r13 == 0) {
        // 0x80069DD4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80069DE8;
    }
    goto skip_2;
    // 0x80069DD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80069DD8: lw          $a0, 0x40($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X40);
    // 0x80069DDC: jal         0x800690D0
    // 0x80069DE0: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    Object_Dying(rdram, ctx);
        goto after_5;
    // 0x80069DE0: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    after_5:
    // 0x80069DE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80069DE8:
    // 0x80069DE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80069DEC: jr          $ra
    // 0x80069DF0: nop

    return;
    // 0x80069DF0: nop

;}
RECOMP_FUNC void CoRadar_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800669A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800669A4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800669A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800669AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800669B0: lhu         $v0, 0xBC($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XBC);
    // 0x800669B4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800669B8: beql        $v0, $zero, L_800669E0
    if (ctx->r2 == 0) {
        // 0x800669BC: lwc1        $f4, 0x14($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
            goto L_800669E0;
    }
    goto skip_0;
    // 0x800669BC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    skip_0:
    // 0x800669C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800669C4: bne         $v0, $at, L_80066A6C
    if (ctx->r2 != ctx->r1) {
        // 0x800669C8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80066A6C;
    }
    // 0x800669C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800669CC: jal         0x80060FBC
    // 0x800669D0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x800669D0: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    after_0:
    // 0x800669D4: b           L_80066A70
    // 0x800669D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80066A70;
    // 0x800669D8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800669DC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
L_800669E0:
    // 0x800669E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800669E4: lb          $t6, 0xD0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0XD0);
    // 0x800669E8: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x800669EC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800669F0: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800669F4: beq         $t6, $zero, L_80066A6C
    if (ctx->r14 == 0) {
        // 0x800669F8: swc1        $f8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
            goto L_80066A6C;
    }
    // 0x800669F8: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800669FC: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80066A00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80066A04: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80066A08: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80066A0C: jal         0x8007D0E0
    // 0x80066A10: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_1;
    // 0x80066A10: add.s       $f14, $f10, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f16.fl;
    after_1:
    // 0x80066A14: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80066A18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80066A1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066A20: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80066A24: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80066A28: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80066A2C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80066A30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80066A34: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80066A38: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80066A3C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80066A40: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80066A44: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80066A48: add.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80066A4C: jal         0x8007BFFC
    // 0x80066A50: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_2;
    // 0x80066A50: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80066A54: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80066A58: lui         $a1, 0x1903
    ctx->r5 = S32(0X1903 << 16);
    // 0x80066A5C: sh          $t8, 0xBC($s0)
    MEM_H(0XBC, ctx->r16) = ctx->r24;
    // 0x80066A60: ori         $a1, $a1, 0x400F
    ctx->r5 = ctx->r5 | 0X400F;
    // 0x80066A64: jal         0x8007A6F0
    // 0x80066A68: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    Effect_TimedSfx_Spawn(rdram, ctx);
        goto after_3;
    // 0x80066A68: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_3:
L_80066A6C:
    // 0x80066A6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80066A70:
    // 0x80066A70: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80066A74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80066A78: jr          $ra
    // 0x80066A7C: nop

    return;
    // 0x80066A7C: nop

;}
RECOMP_FUNC void Aquas_AqRock_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80095538: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8009553C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80095540: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80095544: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80095548: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8009554C: addiu       $t7, $t7, 0x257C
    ctx->r15 = ADD32(ctx->r15, 0X257C);
    // 0x80095550: addiu       $t0, $t7, 0x48
    ctx->r8 = ADD32(ctx->r15, 0X48);
    // 0x80095554: addiu       $t6, $sp, 0x18
    ctx->r14 = ADD32(ctx->r29, 0X18);
L_80095558:
    // 0x80095558: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8009555C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80095560: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80095564: sw          $at, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r1;
    // 0x80095568: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x8009556C: sw          $at, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r1;
    // 0x80095570: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x80095574: bne         $t7, $t0, L_80095558
    if (ctx->r15 != ctx->r8) {
        // 0x80095578: sw          $at, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r1;
            goto L_80095558;
    }
    // 0x80095578: sw          $at, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r1;
    // 0x8009557C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80095580: jal         0x800613C4
    // 0x80095584: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x80095584: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    after_0:
    // 0x80095588: lw          $a2, 0x60($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X60);
    // 0x8009558C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80095590: addiu       $t2, $zero, 0xC3
    ctx->r10 = ADD32(0, 0XC3);
    // 0x80095594: sb          $t1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r9;
    // 0x80095598: sh          $t2, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r10;
    // 0x8009559C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800955A0: addiu       $t5, $sp, 0x18
    ctx->r13 = ADD32(ctx->r29, 0X18);
    // 0x800955A4: addiu       $t7, $zero, 0x2F
    ctx->r15 = ADD32(0, 0X2F);
    // 0x800955A8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800955AC: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800955B0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800955B4: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x800955B8: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x800955BC: andi        $a1, $t2, 0xFFFF
    ctx->r5 = ctx->r10 & 0XFFFF;
    // 0x800955C0: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x800955C4: sw          $at, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r1;
    // 0x800955C8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x800955CC: sw          $t0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r8;
    // 0x800955D0: lw          $at, 0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X8);
    // 0x800955D4: sw          $at, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r1;
    // 0x800955D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800955DC: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x800955E0: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800955E4: sh          $t7, 0xB6($a2)
    MEM_H(0XB6, ctx->r6) = ctx->r15;
    // 0x800955E8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800955EC: jal         0x800612B8
    // 0x800955F0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x800955F0: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    after_1:
    // 0x800955F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800955F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800955FC: jr          $ra
    // 0x80095600: nop

    return;
    // 0x80095600: nop

;}
RECOMP_FUNC void AudioLoad_DmaSlowCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800109FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80010A00: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80010A04: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80010A08: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80010A0C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80010A10: jal         0x80021740
    // 0x80010A14: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80010A14: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    after_0:
    // 0x80010A18: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x80010A1C: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x80010A20: addiu       $a1, $s0, 0x44
    ctx->r5 = ADD32(ctx->r16, 0X44);
    // 0x80010A24: jal         0x80021CF0
    // 0x80010A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80010A28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80010A2C: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80010A30: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80010A34: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80010A38: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80010A3C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80010A40: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80010A44: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80010A48: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x80010A4C: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80010A50: addiu       $t0, $t0, 0x52F4
    ctx->r8 = ADD32(ctx->r8, 0X52F4);
    // 0x80010A54: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80010A58: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x80010A5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80010A60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80010A64: jal         0x8000FBA8
    // 0x80010A68: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    AudioLoad_Dma(rdram, ctx);
        goto after_2;
    // 0x80010A68: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_2:
    // 0x80010A6C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010A70: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80010A74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80010A78: jr          $ra
    // 0x80010A7C: nop

    return;
    // 0x80010A7C: nop

;}
RECOMP_FUNC void Effect_Effect381_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007B184: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007B188: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007B18C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007B190: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007B194: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007B198: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8007B19C: jal         0x80061474
    // 0x8007B1A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x8007B1A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8007B1A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007B1A8: addiu       $t7, $zero, 0x17D
    ctx->r15 = ADD32(0, 0X17D);
    // 0x8007B1AC: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8007B1B0: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x8007B1B4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8007B1B8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8007B1BC: andi        $a1, $t7, 0xFFFF
    ctx->r5 = ctx->r15 & 0XFFFF;
    // 0x8007B1C0: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8007B1C4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007B1C8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x8007B1CC: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8007B1D0: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007B1D4: sh          $t8, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r24;
    // 0x8007B1D8: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8007B1DC: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007B1E0: jal         0x800612B8
    // 0x8007B1E4: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x8007B1E4: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8007B1E8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007B1EC: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x8007B1F0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007B1F4: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x8007B1F8: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x8007B1FC: ori         $a0, $a0, 0xC
    ctx->r4 = ctx->r4 | 0XC;
    // 0x8007B200: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8007B204: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007B208: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007B20C: jal         0x80019218
    // 0x8007B210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8007B210: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8007B214: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007B218: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007B21C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007B220: jr          $ra
    // 0x8007B224: nop

    return;
    // 0x8007B224: nop

;}
RECOMP_FUNC void ActorTeamBoss_Radarmarks_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092244: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80092248: addiu       $v0, $v0, 0x5A10
    ctx->r2 = ADD32(ctx->r2, 0X5A10);
    // 0x8009224C: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
    // 0x80092250: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x80092254: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80092258: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8009225C: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092260: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80092264: mflo        $t8
    ctx->r24 = lo;
    // 0x80092268: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x8009226C: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80092270: lw          $t1, 0x40($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X40);
    // 0x80092274: lh          $t0, 0xE4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0XE4);
    // 0x80092278: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009227C: mflo        $t2
    ctx->r10 = lo;
    // 0x80092280: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x80092284: sh          $t0, 0x2($t3)
    MEM_H(0X2, ctx->r11) = ctx->r8;
    // 0x80092288: lw          $t4, 0x40($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X40);
    // 0x8009228C: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80092290: multu       $t4, $v1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80092294: mflo        $t5
    ctx->r13 = lo;
    // 0x80092298: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x8009229C: swc1        $f4, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->f4.u32l;
    // 0x800922A0: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x800922A4: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800922A8: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800922AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800922B0: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800922B4: swc1        $f6, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f6.u32l;
    // 0x800922B8: lw          $t1, 0x40($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X40);
    // 0x800922BC: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800922C0: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800922C4: mflo        $t2
    ctx->r10 = lo;
    // 0x800922C8: addu        $t0, $v0, $t2
    ctx->r8 = ADD32(ctx->r2, ctx->r10);
    // 0x800922CC: swc1        $f8, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f8.u32l;
    // 0x800922D0: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x800922D4: lwc1        $f10, 0xF8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XF8);
    // 0x800922D8: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800922DC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800922E0: mflo        $t4
    ctx->r12 = lo;
    // 0x800922E4: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x800922E8: swc1        $f18, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->f18.u32l;
    // 0x800922EC: jr          $ra
    // 0x800922F0: nop

    return;
    // 0x800922F0: nop

;}
RECOMP_FUNC void BoBase_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E60C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E610: jal         0x80187520
    // 0x8002E614: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8002E614: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    after_0:
    // 0x8002E618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E620: jr          $ra
    // 0x8002E624: nop

    return;
    // 0x8002E624: nop

;}
RECOMP_FUNC void Idle_ThreadEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004D00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004D04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80004D08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80004D0C: jal         0x80022440
    // 0x80004D10: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x80004D10: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x80004D14: jal         0x80003EE0
    // 0x80004D18: nop

    Main_SetVIMode(rdram, ctx);
        goto after_1;
    // 0x80004D18: nop

    after_1:
    // 0x80004D1C: jal         0x800034E8
    // 0x80004D20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Lib_FillScreen(rdram, ctx);
        goto after_2;
    // 0x80004D20: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80004D24: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80004D28: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80004D2C: addiu       $a2, $a2, 0x2028
    ctx->r6 = ADD32(ctx->r6, 0X2028);
    // 0x80004D30: addiu       $a1, $a1, 0x2010
    ctx->r5 = ADD32(ctx->r5, 0X2010);
    // 0x80004D34: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80004D38: jal         0x800227A0
    // 0x80004D3C: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_3;
    // 0x80004D3C: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    after_3:
    // 0x80004D40: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80004D44: addiu       $t6, $t6, -0x4E10
    ctx->r14 = ADD32(ctx->r14, -0X4E10);
    // 0x80004D48: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80004D4C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80004D50: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80004D54: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80004D58: addiu       $a2, $a2, 0x4ABC
    ctx->r6 = ADD32(ctx->r6, 0X4ABC);
    // 0x80004D5C: addiu       $a0, $a0, -0x5FC0
    ctx->r4 = ADD32(ctx->r4, -0X5FC0);
    // 0x80004D60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80004D64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80004D68: jal         0x800221A0
    // 0x80004D6C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    osCreateThread_recomp(rdram, ctx);
        goto after_4;
    // 0x80004D6C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80004D70: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80004D74: jal         0x800222F0
    // 0x80004D78: addiu       $a0, $a0, -0x5FC0
    ctx->r4 = ADD32(ctx->r4, -0X5FC0);
    osStartThread_recomp(rdram, ctx);
        goto after_5;
    // 0x80004D78: addiu       $a0, $a0, -0x5FC0
    ctx->r4 = ADD32(ctx->r4, -0X5FC0);
    after_5:
    // 0x80004D7C: jal         0x80008018
    // 0x80004D80: nop

    Fault_Init(rdram, ctx);
        goto after_6;
    // 0x80004D80: nop

    after_6:
    // 0x80004D84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80004D88: jal         0x80022A80
    // 0x80004D8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_7;
    // 0x80004D8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
L_80004D90:
    // 0x80004D90: b           L_80004D90
    pause_self(rdram);
    // 0x80004D94: nop

    // 0x80004D98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80004D9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004DA0: jr          $ra
    // 0x80004DA4: nop

    return;
    // 0x80004DA4: nop

;}
RECOMP_FUNC void Effect_TorpedoTrail_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007843C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078440: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80078444: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80078448: jal         0x8005980C
    // 0x8007844C: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007844C: lwc1        $f12, 0x70($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X70);
    after_0:
    // 0x80078450: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80078454: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078458: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007845C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80078460: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80078464: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80078468: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007846C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80078470: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80078474: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80078478: lh          $t0, 0x4A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X4A);
    // 0x8007847C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80078480: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x80078484: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80078488: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007848C: lui         $t5, 0x103
    ctx->r13 = S32(0X103 << 16);
    // 0x80078490: addiu       $t5, $t5, -0x5760
    ctx->r13 = ADD32(ctx->r13, -0X5760);
    // 0x80078494: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80078498: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8007849C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800784A0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800784A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800784A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800784AC: jr          $ra
    // 0x800784B0: nop

    return;
    // 0x800784B0: nop

;}
RECOMP_FUNC void Effect_Effect376_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078CE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80078CEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80078CF0: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078CF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80078CF8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80078CFC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80078D00: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80078D04: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80078D08: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80078D0C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80078D10: lh          $t8, 0x4A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4A);
    // 0x80078D14: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80078D18: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80078D1C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80078D20: jal         0x8005980C
    // 0x80078D24: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x80078D24: lwc1        $f12, 0x70($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X70);
    after_0:
    // 0x80078D28: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80078D2C: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x80078D30: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80078D34: lui         $t3, 0x603
    ctx->r11 = S32(0X603 << 16);
    // 0x80078D38: addiu       $t3, $t3, 0x3000
    ctx->r11 = ADD32(ctx->r11, 0X3000);
    // 0x80078D3C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80078D40: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x80078D44: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x80078D48: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80078D4C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80078D50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80078D54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80078D58: jr          $ra
    // 0x80078D5C: nop

    return;
    // 0x80078D5C: nop

;}
RECOMP_FUNC void ActorAllRange_SetShadowData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EE64: addiu       $sp, $sp, -0x110
    ctx->r29 = ADD32(ctx->r29, -0X110);
    // 0x8002EE68: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x8002EE6C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8002EE70: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x8002EE74: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8002EE78: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x8002EE7C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x8002EE80: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x8002EE84: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x8002EE88: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x8002EE8C: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8002EE90: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x8002EE94: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x8002EE98: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x8002EE9C: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8002EEA0: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8002EEA4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8002EEA8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8002EEAC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x8002EEB0: addiu       $t7, $t7, -0x6570
    ctx->r15 = ADD32(ctx->r15, -0X6570);
    // 0x8002EEB4: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8002EEB8: addiu       $t6, $sp, 0x94
    ctx->r14 = ADD32(ctx->r29, 0X94);
    // 0x8002EEBC: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x8002EEC0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8002EEC4: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x8002EEC8: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x8002EECC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002EED0: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x8002EED4: lbu         $t1, 0xC9($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XC9);
    // 0x8002EED8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002EEDC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EEE0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002EEE4: swc1        $f4, 0x180($s1)
    MEM_W(0X180, ctx->r17) = ctx->f4.u32l;
    // 0x8002EEE8: swc1        $f6, 0x184($s1)
    MEM_W(0X184, ctx->r17) = ctx->f6.u32l;
    // 0x8002EEEC: swc1        $f8, 0x17C($s1)
    MEM_W(0X17C, ctx->r17) = ctx->f8.u32l;
    // 0x8002EEF0: beq         $t1, $zero, L_8002F138
    if (ctx->r9 == 0) {
        // 0x8002EEF4: swc1        $f10, 0x178($s1)
        MEM_W(0X178, ctx->r17) = ctx->f10.u32l;
            goto L_8002F138;
    }
    // 0x8002EEF4: swc1        $f10, 0x178($s1)
    MEM_W(0X178, ctx->r17) = ctx->f10.u32l;
    // 0x8002EEF8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8002EEFC: lw          $t2, 0x7880($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7880);
    // 0x8002EF00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002EF04: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8002EF08: bnel        $t2, $at, L_8002F13C
    if (ctx->r10 != ctx->r1) {
        // 0x8002EF0C: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_8002F13C;
    }
    goto skip_0;
    // 0x8002EF0C: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x8002EF10: lbu         $t3, 0x7C98($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X7C98);
    // 0x8002EF14: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002EF18: lui         $s2, 0x8018
    ctx->r18 = S32(0X8018 << 16);
    // 0x8002EF1C: bne         $t3, $zero, L_8002F138
    if (ctx->r11 != 0) {
        // 0x8002EF20: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8002F138;
    }
    // 0x8002EF20: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8002EF24: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8002EF28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002EF2C: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x8002EF30: addiu       $s7, $s7, -0x4438
    ctx->r23 = ADD32(ctx->r23, -0X4438);
    // 0x8002EF34: lwc1        $f28, 0x4E84($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X4E84);
    // 0x8002EF38: lw          $s2, -0x7D58($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X7D58);
    // 0x8002EF3C: addiu       $fp, $sp, 0xCC
    ctx->r30 = ADD32(ctx->r29, 0XCC);
    // 0x8002EF40: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8002EF44: addiu       $s5, $zero, 0x96
    ctx->r21 = ADD32(0, 0X96);
    // 0x8002EF48: addiu       $s4, $zero, 0x95
    ctx->r20 = ADD32(0, 0X95);
L_8002EF4C:
    // 0x8002EF4C: lbu         $t4, 0x0($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X0);
    // 0x8002EF50: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002EF54: bnel        $t4, $at, L_8002F12C
    if (ctx->r12 != ctx->r1) {
        // 0x8002EF58: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8002F12C;
    }
    goto skip_1;
    // 0x8002EF58: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x8002EF5C: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x8002EF60: beql        $s5, $v0, L_8002EF8C
    if (ctx->r21 == ctx->r2) {
        // 0x8002EF64: lwc1        $f2, 0x4($s2)
        ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
            goto L_8002EF8C;
    }
    goto skip_2;
    // 0x8002EF64: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    skip_2:
    // 0x8002EF68: beq         $s4, $v0, L_8002EF88
    if (ctx->r20 == ctx->r2) {
        // 0x8002EF6C: addiu       $at, $zero, 0x94
        ctx->r1 = ADD32(0, 0X94);
            goto L_8002EF88;
    }
    // 0x8002EF6C: addiu       $at, $zero, 0x94
    ctx->r1 = ADD32(0, 0X94);
    // 0x8002EF70: beq         $v0, $at, L_8002EF88
    if (ctx->r2 == ctx->r1) {
        // 0x8002EF74: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8002EF88;
    }
    // 0x8002EF74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002EF78: beql        $v0, $at, L_8002EF8C
    if (ctx->r2 == ctx->r1) {
        // 0x8002EF7C: lwc1        $f2, 0x4($s2)
        ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
            goto L_8002EF8C;
    }
    goto skip_3;
    // 0x8002EF7C: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    skip_3:
    // 0x8002EF80: bnel        $s6, $v0, L_8002F12C
    if (ctx->r22 != ctx->r2) {
        // 0x8002EF84: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8002F12C;
    }
    goto skip_4;
    // 0x8002EF84: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_4:
L_8002EF88:
    // 0x8002EF88: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
L_8002EF8C:
    // 0x8002EF8C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8002EF90: sub.s       $f0, $f2, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002EF94: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8002EF98: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x8002EF9C: nop

    // 0x8002EFA0: bc1fl       L_8002F12C
    if (!c1cs) {
        // 0x8002EFA4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8002F12C;
    }
    goto skip_5;
    // 0x8002EFA4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_5:
    // 0x8002EFA8: lwc1        $f12, 0xC($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8002EFAC: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002EFB0: sub.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002EFB4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8002EFB8: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x8002EFBC: nop

    // 0x8002EFC0: bc1fl       L_8002F12C
    if (!c1cs) {
        // 0x8002EFC4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8002F12C;
    }
    goto skip_6;
    // 0x8002EFC4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_6:
    // 0x8002EFC8: lwc1        $f26, 0x14($s2)
    ctx->f26.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8002EFCC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002EFD0: lwc1        $f6, 0x4E88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4E88);
    // 0x8002EFD4: neg.s       $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = -ctx->f26.fl;
    // 0x8002EFD8: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8002EFDC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8002EFE0: lwc1        $f24, 0x8($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8002EFE4: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x8002EFE8: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x8002EFEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002EFF0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8002EFF4: jal         0x80005E90
    // 0x8002EFF8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x8002EFF8: nop

    after_0:
    // 0x8002EFFC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8002F000: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002F004: lw          $a0, 0x0($s7)
    ctx->r4 = MEM_W(ctx->r23, 0X0);
    // 0x8002F008: sub.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x8002F00C: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
    // 0x8002F010: addiu       $a1, $sp, 0xE4
    ctx->r5 = ADD32(ctx->r29, 0XE4);
    // 0x8002F014: addiu       $a2, $sp, 0xD8
    ctx->r6 = ADD32(ctx->r29, 0XD8);
    // 0x8002F018: swc1        $f16, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f16.u32l;
    // 0x8002F01C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8002F020: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x8002F024: jal         0x80006A20
    // 0x8002F028: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x8002F028: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8002F02C: lwc1        $f8, 0xD8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x8002F030: lwc1        $f16, 0xDC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8002F034: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x8002F038: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8002F03C: swc1        $f20, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f20.u32l;
    // 0x8002F040: swc1        $f24, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f24.u32l;
    // 0x8002F044: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x8002F048: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x8002F04C: swc1        $f22, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f22.u32l;
    // 0x8002F050: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x8002F054: swc1        $f18, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f18.u32l;
    // 0x8002F058: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002F05C: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x8002F060: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    // 0x8002F064: lhu         $v0, 0x2($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X2);
    // 0x8002F068: addiu       $a2, $sp, 0x94
    ctx->r6 = ADD32(ctx->r29, 0X94);
    // 0x8002F06C: addiu       $t5, $sp, 0xA8
    ctx->r13 = ADD32(ctx->r29, 0XA8);
    // 0x8002F070: beq         $s4, $v0, L_8002F080
    if (ctx->r20 == ctx->r2) {
        // 0x8002F074: addiu       $t9, $sp, 0xA0
        ctx->r25 = ADD32(ctx->r29, 0XA0);
            goto L_8002F080;
    }
    // 0x8002F074: addiu       $t9, $sp, 0xA0
    ctx->r25 = ADD32(ctx->r29, 0XA0);
    // 0x8002F078: bne         $s5, $v0, L_8002F0D8
    if (ctx->r21 != ctx->r2) {
        // 0x8002F07C: addiu       $a3, $sp, 0xB4
        ctx->r7 = ADD32(ctx->r29, 0XB4);
            goto L_8002F0D8;
    }
    // 0x8002F07C: addiu       $a3, $sp, 0xB4
    ctx->r7 = ADD32(ctx->r29, 0XB4);
L_8002F080:
    // 0x8002F080: bne         $s4, $v0, L_8002F090
    if (ctx->r20 != ctx->r2) {
        // 0x8002F084: addiu       $s0, $zero, 0x6
        ctx->r16 = ADD32(0, 0X6);
            goto L_8002F090;
    }
    // 0x8002F084: addiu       $s0, $zero, 0x6
    ctx->r16 = ADD32(0, 0X6);
    // 0x8002F088: b           L_8002F090
    // 0x8002F08C: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
        goto L_8002F090;
    // 0x8002F08C: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
L_8002F090:
    // 0x8002F090: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8002F094: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8002F098: jal         0x800998FC
    // 0x8002F09C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_col1_800998FC(rdram, ctx);
        goto after_2;
    // 0x8002F09C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_2:
    // 0x8002F0A0: blezl       $v0, L_8002F12C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F0A4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8002F12C;
    }
    goto skip_7;
    // 0x8002F0A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_7:
    // 0x8002F0A8: div.s       $f18, $f26, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = DIV_S(ctx->f26.fl, ctx->f30.fl);
    // 0x8002F0AC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8002F0B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002F0B4: swc1        $f8, 0x178($s1)
    MEM_W(0X178, ctx->r17) = ctx->f8.u32l;
    // 0x8002F0B8: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8002F0BC: swc1        $f10, 0x17C($s1)
    MEM_W(0X17C, ctx->r17) = ctx->f10.u32l;
    // 0x8002F0C0: lwc1        $f16, 0xA4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8002F0C4: swc1        $f16, 0x184($s1)
    MEM_W(0X184, ctx->r17) = ctx->f16.u32l;
    // 0x8002F0C8: lwc1        $f4, 0x4E8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4E8C);
    // 0x8002F0CC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002F0D0: b           L_8002F128
    // 0x8002F0D4: swc1        $f6, 0x180($s1)
    MEM_W(0X180, ctx->r17) = ctx->f6.u32l;
        goto L_8002F128;
    // 0x8002F0D4: swc1        $f6, 0x180($s1)
    MEM_W(0X180, ctx->r17) = ctx->f6.u32l;
L_8002F0D8:
    // 0x8002F0D8: bne         $s6, $v0, L_8002F0E4
    if (ctx->r22 != ctx->r2) {
        // 0x8002F0DC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8002F0E4;
    }
    // 0x8002F0DC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002F0E0: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
L_8002F0E4:
    // 0x8002F0E4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8002F0E8: addiu       $a1, $sp, 0xC0
    ctx->r5 = ADD32(ctx->r29, 0XC0);
    // 0x8002F0EC: jal         0x800A3690
    // 0x8002F0F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_col2_800A3690(rdram, ctx);
        goto after_3;
    // 0x8002F0F0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x8002F0F4: beql        $v0, $zero, L_8002F12C
    if (ctx->r2 == 0) {
        // 0x8002F0F8: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8002F12C;
    }
    goto skip_8;
    // 0x8002F0F8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_8:
    // 0x8002F0FC: div.s       $f18, $f26, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = DIV_S(ctx->f26.fl, ctx->f30.fl);
    // 0x8002F100: lwc1        $f8, 0xB8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8002F104: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8002F108: swc1        $f8, 0x178($s1)
    MEM_W(0X178, ctx->r17) = ctx->f8.u32l;
    // 0x8002F10C: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8002F110: swc1        $f10, 0x17C($s1)
    MEM_W(0X17C, ctx->r17) = ctx->f10.u32l;
    // 0x8002F114: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002F118: swc1        $f16, 0x184($s1)
    MEM_W(0X184, ctx->r17) = ctx->f16.u32l;
    // 0x8002F11C: lwc1        $f4, 0x4E90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4E90);
    // 0x8002F120: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002F124: swc1        $f6, 0x180($s1)
    MEM_W(0X180, ctx->r17) = ctx->f6.u32l;
L_8002F128:
    // 0x8002F128: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8002F12C:
    // 0x8002F12C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x8002F130: bne         $s3, $at, L_8002EF4C
    if (ctx->r19 != ctx->r1) {
        // 0x8002F134: addiu       $s2, $s2, 0x58
        ctx->r18 = ADD32(ctx->r18, 0X58);
            goto L_8002EF4C;
    }
    // 0x8002F134: addiu       $s2, $s2, 0x58
    ctx->r18 = ADD32(ctx->r18, 0X58);
L_8002F138:
    // 0x8002F138: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_8002F13C:
    // 0x8002F13C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8002F140: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8002F144: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8002F148: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8002F14C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x8002F150: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x8002F154: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x8002F158: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8002F15C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8002F160: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8002F164: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x8002F168: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8002F16C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8002F170: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x8002F174: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8002F178: jr          $ra
    // 0x8002F17C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
    return;
    // 0x8002F17C: addiu       $sp, $sp, 0x110
    ctx->r29 = ADD32(ctx->r29, 0X110);
;}
RECOMP_FUNC void HUD_PlayerShieldGauge_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B2F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B2F4: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008B2F8: addiu       $v1, $v1, 0x1730
    ctx->r3 = ADD32(ctx->r3, 0X1730);
    // 0x8008B2FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B300: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008B304: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B308: addiu       $a0, $a0, 0x17B0
    ctx->r4 = ADD32(ctx->r4, 0X17B0);
    // 0x8008B30C: beq         $v0, $zero, L_8008B334
    if (ctx->r2 == 0) {
        // 0x8008B310: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8008B334;
    }
    // 0x8008B310: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8008B314: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B318: beq         $v0, $at, L_8008B40C
    if (ctx->r2 == ctx->r1) {
        // 0x8008B31C: lui         $a1, 0x800D
        ctx->r5 = S32(0X800D << 16);
            goto L_8008B40C;
    }
    // 0x8008B31C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8008B320: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008B324: beq         $v0, $at, L_8008B434
    if (ctx->r2 == ctx->r1) {
        // 0x8008B328: nop
    
            goto L_8008B434;
    }
    // 0x8008B328: nop

    // 0x8008B32C: b           L_8008B5A4
    // 0x8008B330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8008B5A4;
    // 0x8008B330: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B334:
    // 0x8008B334: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008B338: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8008B33C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B340: swc1        $f4, 0x179C($at)
    MEM_W(0X179C, ctx->r1) = ctx->f4.u32l;
    // 0x8008B344: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8008B348: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008B34C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8008B350: lbu         $v0, 0x1A90($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1A90);
    // 0x8008B354: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B358: swc1        $f6, 0x17A0($at)
    MEM_W(0X17A0, ctx->r1) = ctx->f6.u32l;
    // 0x8008B35C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008B360: bne         $at, $zero, L_8008B390
    if (ctx->r1 != 0) {
        // 0x8008B364: lui         $t6, 0x8018
        ctx->r14 = S32(0X8018 << 16);
            goto L_8008B390;
    }
    // 0x8008B364: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008B368: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8008B36C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008B370: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B374: addiu       $a0, $a0, 0x17A8
    ctx->r4 = ADD32(ctx->r4, 0X17A8);
    // 0x8008B378: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x8008B37C: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008B380: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008B384: addiu       $t0, $t0, 0x17A4
    ctx->r8 = ADD32(ctx->r8, 0X17A4);
    // 0x8008B388: b           L_8008B3B4
    // 0x8008B38C: swc1        $f2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
        goto L_8008B3B4;
    // 0x8008B38C: swc1        $f2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
L_8008B390:
    // 0x8008B390: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B394: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008B398: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B39C: addiu       $a0, $a0, 0x17A8
    ctx->r4 = ADD32(ctx->r4, 0X17A8);
    // 0x8008B3A0: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x8008B3A4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008B3A8: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008B3AC: addiu       $t0, $t0, 0x17A4
    ctx->r8 = ADD32(ctx->r8, 0X17A4);
    // 0x8008B3B0: swc1        $f2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f2.u32l;
L_8008B3B4:
    // 0x8008B3B4: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8008B3B8: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8008B3BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008B3C0: lw          $t7, 0x264($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X264);
    // 0x8008B3C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B3C8: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8008B3CC: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8008B3D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008B3D4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B3D8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8008B3DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008B3E0: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008B3E4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8008B3E8: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8008B3EC: swc1        $f10, 0x17AC($at)
    MEM_W(0X17AC, ctx->r1) = ctx->f10.u32l;
    // 0x8008B3F0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008B3F4: bne         $at, $zero, L_8008B404
    if (ctx->r1 != 0) {
        // 0x8008B3F8: nop
    
            goto L_8008B404;
    }
    // 0x8008B3F8: nop

    // 0x8008B3FC: b           L_8008B5A0
    // 0x8008B400: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8008B5A0;
    // 0x8008B400: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8008B404:
    // 0x8008B404: b           L_8008B5A0
    // 0x8008B408: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_8008B5A0;
    // 0x8008B408: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8008B40C:
    // 0x8008B40C: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x8008B410: lbu         $t2, 0x1A90($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X1A90);
    // 0x8008B414: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B418: addiu       $a0, $a0, 0x17B0
    ctx->r4 = ADD32(ctx->r4, 0X17B0);
    // 0x8008B41C: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x8008B420: bne         $at, $zero, L_8008B434
    if (ctx->r1 != 0) {
        // 0x8008B424: addiu       $t3, $zero, 0x37
        ctx->r11 = ADD32(0, 0X37);
            goto L_8008B434;
    }
    // 0x8008B424: addiu       $t3, $zero, 0x37
    ctx->r11 = ADD32(0, 0X37);
    // 0x8008B428: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8008B42C: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8008B430: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_8008B434:
    // 0x8008B434: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B438: addiu       $a0, $a0, 0x17B0
    ctx->r4 = ADD32(ctx->r4, 0X17B0);
    // 0x8008B43C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008B440: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x8008B444: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008B448: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8008B44C: addiu       $t1, $t1, 0x1EB4
    ctx->r9 = ADD32(ctx->r9, 0X1EB4);
    // 0x8008B450: addiu       $a2, $a2, 0x1EB8
    ctx->r6 = ADD32(ctx->r6, 0X1EB8);
    // 0x8008B454: addiu       $a1, $a1, 0x1EBC
    ctx->r5 = ADD32(ctx->r5, 0X1EBC);
    // 0x8008B458: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8008B45C: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x8008B460: blez        $v1, L_8008B494
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008B464: sw          $a3, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r7;
            goto L_8008B494;
    }
    // 0x8008B464: sw          $a3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r7;
    // 0x8008B468: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8008B46C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8008B470: bne         $t7, $zero, L_8008B494
    if (ctx->r15 != 0) {
        // 0x8008B474: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_8008B494;
    }
    // 0x8008B474: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8008B478: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8008B47C: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x8008B480: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8008B484: lw          $t8, 0x26C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X26C);
    // 0x8008B488: addiu       $t9, $t8, 0x80
    ctx->r25 = ADD32(ctx->r24, 0X80);
    // 0x8008B48C: sw          $t9, 0x26C($v0)
    MEM_W(0X26C, ctx->r2) = ctx->r25;
    // 0x8008B490: lw          $v1, 0x17B0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X17B0);
L_8008B494:
    // 0x8008B494: bne         $v1, $zero, L_8008B4C8
    if (ctx->r3 != 0) {
        // 0x8008B498: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_8008B4C8;
    }
    // 0x8008B498: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B49C: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008B4A0: addiu       $t0, $t0, 0x17A4
    ctx->r8 = ADD32(ctx->r8, 0X17A4);
    // 0x8008B4A4: addiu       $a0, $a0, 0x17A8
    ctx->r4 = ADD32(ctx->r4, 0X17A8);
    // 0x8008B4A8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008B4AC: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8008B4B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008B4B4: lwc1        $f16, 0x7BB0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7BB0);
    // 0x8008B4B8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8008B4BC: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8008B4C0: nop

    // 0x8008B4C4: bc1f        L_8008B4F4
    if (!c1cs) {
        // 0x8008B4C8: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_8008B4F4;
    }
L_8008B4C8:
    // 0x8008B4C8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8008B4CC: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8008B4D0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B4D4: lui         $t0, 0x8016
    ctx->r8 = S32(0X8016 << 16);
    // 0x8008B4D8: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x8008B4DC: addiu       $t0, $t0, 0x17A4
    ctx->r8 = ADD32(ctx->r8, 0X17A4);
    // 0x8008B4E0: beq         $t3, $zero, L_8008B4F4
    if (ctx->r11 == 0) {
        // 0x8008B4E4: addiu       $a0, $a0, 0x17A8
        ctx->r4 = ADD32(ctx->r4, 0X17A8);
            goto L_8008B4F4;
    }
    // 0x8008B4E4: addiu       $a0, $a0, 0x17A8
    ctx->r4 = ADD32(ctx->r4, 0X17A8);
    // 0x8008B4E8: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8008B4EC: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x8008B4F0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_8008B4F4:
    // 0x8008B4F4: bne         $v1, $zero, L_8008B51C
    if (ctx->r3 != 0) {
        // 0x8008B4F8: lui         $a2, 0x3CA3
        ctx->r6 = S32(0X3CA3 << 16);
            goto L_8008B51C;
    }
    // 0x8008B4F8: lui         $a2, 0x3CA3
    ctx->r6 = S32(0X3CA3 << 16);
    // 0x8008B4FC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8008B500: lbu         $t4, 0x1A90($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X1A90);
    // 0x8008B504: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8008B508: bne         $at, $zero, L_8008B51C
    if (ctx->r1 != 0) {
        // 0x8008B50C: lui         $at, 0x3FC0
        ctx->r1 = S32(0X3FC0 << 16);
            goto L_8008B51C;
    }
    // 0x8008B50C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8008B510: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008B514: b           L_8008B52C
    // 0x8008B518: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
        goto L_8008B52C;
    // 0x8008B518: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
L_8008B51C:
    // 0x8008B51C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B520: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008B524: nop

    // 0x8008B528: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
L_8008B52C:
    // 0x8008B52C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008B530: lwc1        $f18, 0x7BB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7BB4);
    // 0x8008B534: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8008B538: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8008B53C: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8008B540: jal         0x8009BC2C
    // 0x8008B544: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8008B544: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8008B548: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8008B54C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008B550: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8008B554: addiu       $a0, $a0, 0x17A8
    ctx->r4 = ADD32(ctx->r4, 0X17A8);
    // 0x8008B558: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8008B55C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8008B560: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8008B564: lw          $t6, 0x264($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X264);
    // 0x8008B568: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008B56C: mul.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8008B570: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8008B574: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008B578: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008B57C: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8008B580: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8008B584: nop

    // 0x8008B588: bc1fl       L_8008B598
    if (!c1cs) {
        // 0x8008B58C: div.s       $f18, $f0, $f2
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
            goto L_8008B598;
    }
    goto skip_0;
    // 0x8008B58C: div.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    skip_0:
    // 0x8008B590: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8008B594: div.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_8008B598:
    // 0x8008B598: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8008B59C: swc1        $f18, 0x17AC($at)
    MEM_W(0X17AC, ctx->r1) = ctx->f18.u32l;
L_8008B5A0:
    // 0x8008B5A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B5A4:
    // 0x8008B5A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008B5A8: jr          $ra
    // 0x8008B5AC: nop

    return;
    // 0x8008B5AC: nop

;}
RECOMP_FUNC void Player_LowHealthMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B46F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B46FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B4700: lw          $t6, 0x1C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1C8);
    // 0x800B4704: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B4708: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B470C: bne         $t6, $at, L_800B48AC
    if (ctx->r14 != ctx->r1) {
        // 0x800B4710: addiu       $v1, $v1, 0x796C
        ctx->r3 = ADD32(ctx->r3, 0X796C);
            goto L_800B48AC;
    }
    // 0x800B4710: addiu       $v1, $v1, 0x796C
    ctx->r3 = ADD32(ctx->r3, 0X796C);
    // 0x800B4714: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800B4718: bltz        $v0, L_800B48AC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B471C: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_800B48AC;
    }
    // 0x800B471C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x800B4720: slti        $at, $t7, 0x3C1
    ctx->r1 = SIGNED(ctx->r15) < 0X3C1 ? 1 : 0;
    // 0x800B4724: bne         $at, $zero, L_800B48AC
    if (ctx->r1 != 0) {
        // 0x800B4728: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_800B48AC;
    }
    // 0x800B4728: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B472C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B4730: lw          $t9, 0x264($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X264);
    // 0x800B4734: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B4738: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x800B473C: slti        $at, $t9, 0x40
    ctx->r1 = SIGNED(ctx->r25) < 0X40 ? 1 : 0;
    // 0x800B4740: beql        $at, $zero, L_800B48B0
    if (ctx->r1 == 0) {
        // 0x800B4744: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B48B0;
    }
    goto skip_0;
    // 0x800B4744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800B4748: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x800B474C: bgtz        $t0, L_800B476C
    if (SIGNED(ctx->r8) > 0) {
        // 0x800B4750: nop
    
            goto L_800B476C;
    }
    // 0x800B4750: nop

    // 0x800B4754: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x800B4758: bgtz        $t1, L_800B476C
    if (SIGNED(ctx->r9) > 0) {
        // 0x800B475C: nop
    
            goto L_800B476C;
    }
    // 0x800B475C: nop

    // 0x800B4760: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B4764: blezl       $t2, L_800B48B0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800B4768: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B48B0;
    }
    goto skip_1;
    // 0x800B4768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
L_800B476C:
    // 0x800B476C: jal         0x80004EB0
    // 0x800B4770: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x800B4770: nop

    after_0:
    // 0x800B4774: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4778: lwc1        $f4, -0x7614($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7614);
    // 0x800B477C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x800B4780: addiu       $v1, $v1, 0x78B0
    ctx->r3 = ADD32(ctx->r3, 0X78B0);
    // 0x800B4784: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800B4788: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800B478C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800B4790: nop

    // 0x800B4794: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800B4798: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800B479C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x800B47A0: blez        $t6, L_800B476C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800B47A4: nop
    
            goto L_800B476C;
    }
    // 0x800B47A4: nop

    // 0x800B47A8: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800B47AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B47B0: beq         $v1, $at, L_800B47D0
    if (ctx->r3 == ctx->r1) {
        // 0x800B47B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B47D0;
    }
    // 0x800B47B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B47B8: beq         $v1, $at, L_800B481C
    if (ctx->r3 == ctx->r1) {
        // 0x800B47BC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800B481C;
    }
    // 0x800B47BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B47C0: beq         $v1, $at, L_800B4868
    if (ctx->r3 == ctx->r1) {
        // 0x800B47C4: nop
    
            goto L_800B4868;
    }
    // 0x800B47C4: nop

    // 0x800B47C8: b           L_800B48B0
    // 0x800B47CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B48B0;
    // 0x800B47CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B47D0:
    // 0x800B47D0: jal         0x80004EB0
    // 0x800B47D4: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800B47D4: nop

    after_1:
    // 0x800B47D8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B47DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B47E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B47E4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800B47E8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800B47EC: addiu       $a0, $a0, 0x46A0
    ctx->r4 = ADD32(ctx->r4, 0X46A0);
    // 0x800B47F0: bc1f        L_800B480C
    if (!c1cs) {
        // 0x800B47F4: nop
    
            goto L_800B480C;
    }
    // 0x800B47F4: nop

    // 0x800B47F8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B47FC: jal         0x800BA808
    // 0x800B4800: addiu       $a0, $a0, 0x4620
    ctx->r4 = ADD32(ctx->r4, 0X4620);
    Radio_PlayMessage(rdram, ctx);
        goto after_2;
    // 0x800B4800: addiu       $a0, $a0, 0x4620
    ctx->r4 = ADD32(ctx->r4, 0X4620);
    after_2:
    // 0x800B4804: b           L_800B48B0
    // 0x800B4808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B48B0;
    // 0x800B4808: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B480C:
    // 0x800B480C: jal         0x800BA808
    // 0x800B4810: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    Radio_PlayMessage(rdram, ctx);
        goto after_3;
    // 0x800B4810: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_3:
    // 0x800B4814: b           L_800B48B0
    // 0x800B4818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B48B0;
    // 0x800B4818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B481C:
    // 0x800B481C: jal         0x80004EB0
    // 0x800B4820: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x800B4820: nop

    after_4:
    // 0x800B4824: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B4828: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B482C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B4830: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800B4834: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800B4838: addiu       $a0, $a0, 0x4668
    ctx->r4 = ADD32(ctx->r4, 0X4668);
    // 0x800B483C: bc1f        L_800B4858
    if (!c1cs) {
        // 0x800B4840: nop
    
            goto L_800B4858;
    }
    // 0x800B4840: nop

    // 0x800B4844: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B4848: jal         0x800BA808
    // 0x800B484C: addiu       $a0, $a0, 0x45F8
    ctx->r4 = ADD32(ctx->r4, 0X45F8);
    Radio_PlayMessage(rdram, ctx);
        goto after_5;
    // 0x800B484C: addiu       $a0, $a0, 0x45F8
    ctx->r4 = ADD32(ctx->r4, 0X45F8);
    after_5:
    // 0x800B4850: b           L_800B48B0
    // 0x800B4854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B48B0;
    // 0x800B4854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B4858:
    // 0x800B4858: jal         0x800BA808
    // 0x800B485C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    Radio_PlayMessage(rdram, ctx);
        goto after_6;
    // 0x800B485C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_6:
    // 0x800B4860: b           L_800B48B0
    // 0x800B4864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B48B0;
    // 0x800B4864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B4868:
    // 0x800B4868: jal         0x80004EB0
    // 0x800B486C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x800B486C: nop

    after_7:
    // 0x800B4870: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B4874: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B4878: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B487C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800B4880: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800B4884: addiu       $a0, $a0, 0x4644
    ctx->r4 = ADD32(ctx->r4, 0X4644);
    // 0x800B4888: bc1f        L_800B48A4
    if (!c1cs) {
        // 0x800B488C: nop
    
            goto L_800B48A4;
    }
    // 0x800B488C: nop

    // 0x800B4890: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800B4894: jal         0x800BA808
    // 0x800B4898: addiu       $a0, $a0, 0x45A8
    ctx->r4 = ADD32(ctx->r4, 0X45A8);
    Radio_PlayMessage(rdram, ctx);
        goto after_8;
    // 0x800B4898: addiu       $a0, $a0, 0x45A8
    ctx->r4 = ADD32(ctx->r4, 0X45A8);
    after_8:
    // 0x800B489C: b           L_800B48B0
    // 0x800B48A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B48B0;
    // 0x800B48A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B48A4:
    // 0x800B48A4: jal         0x800BA808
    // 0x800B48A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    Radio_PlayMessage(rdram, ctx);
        goto after_9;
    // 0x800B48A8: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_9:
L_800B48AC:
    // 0x800B48AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B48B0:
    // 0x800B48B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B48B4: jr          $ra
    // 0x800B48B8: nop

    return;
    // 0x800B48B8: nop

;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023FC0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80023FC4: beq         $a2, $zero, L_80023FE4
    if (ctx->r6 == 0) {
        // 0x80023FC8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80023FE4;
    }
    // 0x80023FC8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80023FCC:
    // 0x80023FCC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80023FD0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80023FD4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023FD8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80023FDC: bne         $a2, $zero, L_80023FCC
    if (ctx->r6 != 0) {
        // 0x80023FE0: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_80023FCC;
    }
    // 0x80023FE0: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_80023FE4:
    // 0x80023FE4: jr          $ra
    // 0x80023FE8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80023FE8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void Lib_TextureRect_CI4_Flip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C674: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8009C678: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8009C67C: lui         $t0, 0x700
    ctx->r8 = S32(0X700 << 16);
    // 0x8009C680: lui         $t1, 0xE600
    ctx->r9 = S32(0XE600 << 16);
    // 0x8009C684: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C688: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8009C68C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C690: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C694: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8009C698: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C69C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C6A0: lui         $t9, 0xE800
    ctx->r25 = S32(0XE800 << 16);
    // 0x8009C6A4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C6A8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C6AC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C6B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009C6B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C6B8: lui         $t7, 0xF500
    ctx->r15 = S32(0XF500 << 16);
    // 0x8009C6BC: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8009C6C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C6C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C6C8: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009C6CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C6D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C6D4: lui         $a1, 0xE700
    ctx->r5 = S32(0XE700 << 16);
    // 0x8009C6D8: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8009C6DC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C6E0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C6E4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C6E8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009C6EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C6F0: lui         $t7, 0x703
    ctx->r15 = S32(0X703 << 16);
    // 0x8009C6F4: ori         $t7, $t7, 0xC000
    ctx->r15 = ctx->r15 | 0XC000;
    // 0x8009C6F8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009C6FC: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009C700: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009C704: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009C708: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C70C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8009C710: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C714: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C718: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C71C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8009C720: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C724: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8009C728: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009C72C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009C730: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009C734: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8009C738: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009C73C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C740: lui         $t9, 0xF550
    ctx->r25 = S32(0XF550 << 16);
    // 0x8009C744: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C748: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C74C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8009C750: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8009C754: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009C758: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C75C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C760: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C764: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C768: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009C76C: multu       $a3, $v1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009C770: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8009C774: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8009C778: srl         $v0, $a3, 4
    ctx->r2 = S32(U32(ctx->r7) >> 4);
    // 0x8009C77C: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x8009C780: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8009C784: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8009C788: mflo        $t4
    ctx->r12 = lo;
    // 0x8009C78C: addiu       $t4, $t4, 0x3
    ctx->r12 = ADD32(ctx->r12, 0X3);
    // 0x8009C790: srl         $t9, $t4, 2
    ctx->r25 = S32(U32(ctx->r12) >> 2);
    // 0x8009C794: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x8009C798: sltiu       $at, $t4, 0x7FF
    ctx->r1 = ctx->r12 < 0X7FF ? 1 : 0;
    // 0x8009C79C: beql        $at, $zero, L_8009C7B0
    if (ctx->r1 == 0) {
        // 0x8009C7A0: addiu       $a2, $zero, 0x7FF
        ctx->r6 = ADD32(0, 0X7FF);
            goto L_8009C7B0;
    }
    goto skip_0;
    // 0x8009C7A0: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009C7A4: b           L_8009C7B0
    // 0x8009C7A8: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
        goto L_8009C7B0;
    // 0x8009C7A8: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x8009C7AC: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
L_8009C7B0:
    // 0x8009C7B0: bne         $v0, $zero, L_8009C7C0
    if (ctx->r2 != 0) {
        // 0x8009C7B4: lui         $at, 0xF540
        ctx->r1 = S32(0XF540 << 16);
            goto L_8009C7C0;
    }
    // 0x8009C7B4: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8009C7B8: b           L_8009C7C4
    // 0x8009C7BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8009C7C4;
    // 0x8009C7BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8009C7C0:
    // 0x8009C7C0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
L_8009C7C4:
    // 0x8009C7C4: bne         $v0, $zero, L_8009C7D4
    if (ctx->r2 != 0) {
        // 0x8009C7C8: addiu       $t6, $t1, 0x7FF
        ctx->r14 = ADD32(ctx->r9, 0X7FF);
            goto L_8009C7D4;
    }
    // 0x8009C7C8: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8009C7CC: b           L_8009C7D8
    // 0x8009C7D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
        goto L_8009C7D8;
    // 0x8009C7D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8009C7D4:
    // 0x8009C7D4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
L_8009C7D8:
    // 0x8009C7D8: divu        $zero, $t6, $t3
    lo = S32(U32(ctx->r14) / U32(ctx->r11)); hi = S32(U32(ctx->r14) % U32(ctx->r11));
    // 0x8009C7DC: mflo        $t7
    ctx->r15 = lo;
    // 0x8009C7E0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009C7E4: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x8009C7E8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009C7EC: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x8009C7F0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009C7F4: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8009C7F8: bne         $t3, $zero, L_8009C804
    if (ctx->r11 != 0) {
        // 0x8009C7FC: nop
    
            goto L_8009C804;
    }
    // 0x8009C7FC: nop

    // 0x8009C800: break       7
    do_break(2148124672);
L_8009C804:
    // 0x8009C804: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C808: srl         $t7, $a3, 1
    ctx->r15 = S32(U32(ctx->r7) >> 1);
    // 0x8009C80C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C810: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C814: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C818: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8009C81C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C820: addiu       $t8, $t7, 0x7
    ctx->r24 = ADD32(ctx->r15, 0X7);
    // 0x8009C824: srl         $t6, $t8, 3
    ctx->r14 = S32(U32(ctx->r24) >> 3);
    // 0x8009C828: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009C82C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009C830: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8009C834: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8009C838: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8009C83C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009C840: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C844: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C848: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8009C84C: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x8009C850: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009C854: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C858: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C85C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8009C860: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8009C864: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009C868: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8009C86C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8009C870: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8009C874: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8009C878: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8009C87C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8009C880: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8009C884: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8009C888: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009C88C: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8009C890: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8009C894: lwc1        $f2, 0x4C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8009C898: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8009C89C: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8009C8A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009C8A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009C8A8: addiu       $t8, $a1, 0x8
    ctx->r24 = ADD32(ctx->r5, 0X8);
    // 0x8009C8AC: bgez        $a3, L_8009C8C0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009C8B0: sw          $t8, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r24;
            goto L_8009C8C0;
    }
    // 0x8009C8B0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C8B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009C8B8: nop

    // 0x8009C8BC: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009C8C0:
    // 0x8009C8C0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009C8C4: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x8009C8C8: lui         $at, 0xE500
    ctx->r1 = S32(0XE500 << 16);
    // 0x8009C8CC: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009C8D0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009C8D4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009C8D8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009C8DC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009C8E0: nop

    // 0x8009C8E4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8009C8E8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8009C8EC: bgez        $v1, L_8009C904
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009C8F0: or          $t6, $t8, $at
        ctx->r14 = ctx->r24 | ctx->r1;
            goto L_8009C904;
    }
    // 0x8009C8F0: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8009C8F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009C8F8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009C8FC: nop

    // 0x8009C900: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009C904:
    // 0x8009C904: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009C908: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8009C90C: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009C910: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009C914: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009C918: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009C91C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009C920: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009C924: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8009C928: nop

    // 0x8009C92C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009C930: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009C934: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009C938: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8009C93C: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009C940: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8009C944: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009C948: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009C94C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8009C950: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8009C954: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8009C958: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8009C95C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8009C960: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C964: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8009C968: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009C96C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009C970: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009C974: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009C978: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009C97C: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009C980: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009C984: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009C988: lui         $t7, 0xB300
    ctx->r15 = S32(0XB300 << 16);
    // 0x8009C98C: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8009C990: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009C994: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009C998: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8009C99C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C9A0: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009C9A4: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009C9A8: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009C9AC: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8009C9B0: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8009C9B4: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8009C9B8: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8009C9BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8009C9C0: jr          $ra
    // 0x8009C9C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8009C9C4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Audio_AllocNoteFromActive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80012F28: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x80012F2C: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80012F30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012F34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80012F38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80012F3C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80012F40: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80012F44: lw          $t8, 0x4C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4C);
    // 0x80012F48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80012F4C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80012F50: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80012F54: lbu         $a1, 0x5($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X5);
    // 0x80012F58: jal         0x80012C6C
    // 0x80012F5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    Audio_FindNodeWithPrioLessThan(rdram, ctx);
        goto after_0;
    // 0x80012F5C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80012F60: beq         $v0, $zero, L_80012F70
    if (ctx->r2 == 0) {
        // 0x80012F64: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80012F70;
    }
    // 0x80012F64: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80012F68: lbu         $t9, 0x30($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X30);
    // 0x80012F6C: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
L_80012F70:
    // 0x80012F70: lw          $t0, 0x4C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X4C);
    // 0x80012F74: addiu       $a0, $s0, 0x30
    ctx->r4 = ADD32(ctx->r16, 0X30);
    // 0x80012F78: lbu         $a1, 0x5($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X5);
    // 0x80012F7C: jal         0x80012C6C
    // 0x80012F80: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    Audio_FindNodeWithPrioLessThan(rdram, ctx);
        goto after_1;
    // 0x80012F80: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x80012F84: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80012F88: beq         $v0, $zero, L_80012F98
    if (ctx->r2 == 0) {
        // 0x80012F8C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80012F98;
    }
    // 0x80012F8C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80012F90: lbu         $t1, 0x30($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X30);
    // 0x80012F94: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
L_80012F98:
    // 0x80012F98: bne         $v1, $zero, L_80012FB0
    if (ctx->r3 != 0) {
        // 0x80012F9C: lw          $t2, 0x28($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X28);
            goto L_80012FB0;
    }
    // 0x80012F9C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012FA0: bnel        $v0, $zero, L_80012FB4
    if (ctx->r2 != 0) {
        // 0x80012FA4: lw          $t3, 0x2C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X2C);
            goto L_80012FB4;
    }
    goto skip_0;
    // 0x80012FA4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x80012FA8: b           L_80013008
    // 0x80012FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80013008;
    // 0x80012FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80012FB0:
    // 0x80012FB0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
L_80012FB4:
    // 0x80012FB4: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80012FB8: beql        $at, $zero, L_80012FF8
    if (ctx->r1 == 0) {
        // 0x80012FBC: sw          $s1, 0x48($v1)
        MEM_W(0X48, ctx->r3) = ctx->r17;
            goto L_80012FF8;
    }
    goto skip_1;
    // 0x80012FBC: sw          $s1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r17;
    skip_1:
    // 0x80012FC0: jal         0x80012C40
    // 0x80012FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Audio_AudioListRemove(rdram, ctx);
        goto after_2;
    // 0x80012FC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80012FC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80012FCC: jal         0x80012E28
    // 0x80012FD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80012E28(rdram, ctx);
        goto after_3;
    // 0x80012FD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80012FD4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80012FD8: jal         0x800145BC
    // 0x80012FDC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_4;
    // 0x80012FDC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x80012FE0: lw          $t4, 0x4C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X4C);
    // 0x80012FE4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80012FE8: lbu         $t5, 0x5($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X5);
    // 0x80012FEC: b           L_80013008
    // 0x80012FF0: sb          $t5, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r13;
        goto L_80013008;
    // 0x80012FF0: sb          $t5, 0x30($s0)
    MEM_B(0X30, ctx->r16) = ctx->r13;
    // 0x80012FF4: sw          $s1, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r17;
L_80012FF8:
    // 0x80012FF8: lw          $t6, 0x4C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X4C);
    // 0x80012FFC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80013000: lbu         $t7, 0x5($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X5);
    // 0x80013004: sb          $t7, 0x30($v1)
    MEM_B(0X30, ctx->r3) = ctx->r15;
L_80013008:
    // 0x80013008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001300C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80013010: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80013014: jr          $ra
    // 0x80013018: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80013018: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Audio_RestartSeqPlayers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DD40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001DD44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DD48: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001DD4C: sh          $t6, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r14;
    // 0x8001DD50: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8001DD54: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001DD58: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8001DD5C: jal         0x80017600
    // 0x8001DD60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Audio_StartSequence(rdram, ctx);
        goto after_0;
    // 0x8001DD60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8001DD64: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001DD68: lbu         $v0, 0x5D54($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5D54);
    // 0x8001DD6C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8001DD70: lhu         $a3, 0x1E($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X1E);
    // 0x8001DD74: bne         $v0, $at, L_8001DD84
    if (ctx->r2 != ctx->r1) {
        // 0x8001DD78: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_8001DD84;
    }
    // 0x8001DD78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001DD7C: b           L_8001DD94
    // 0x8001DD80: addiu       $a3, $zero, 0x168
    ctx->r7 = ADD32(0, 0X168);
        goto L_8001DD94;
    // 0x8001DD80: addiu       $a3, $zero, 0x168
    ctx->r7 = ADD32(0, 0X168);
L_8001DD84:
    // 0x8001DD84: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x8001DD88: beql        $at, $zero, L_8001DD98
    if (ctx->r1 == 0) {
        // 0x8001DD8C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001DD98;
    }
    goto skip_0;
    // 0x8001DD8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    skip_0:
    // 0x8001DD90: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
L_8001DD94:
    // 0x8001DD94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001DD98:
    // 0x8001DD98: jal         0x80017600
    // 0x8001DD9C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    Audio_StartSequence(rdram, ctx);
        goto after_1;
    // 0x8001DD9C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_1:
    // 0x8001DDA0: jal         0x80017494
    // 0x8001DDA4: nop

    Audio_LoadInstruments(rdram, ctx);
        goto after_2;
    // 0x8001DDA4: nop

    after_2:
    // 0x8001DDA8: jal         0x80017550
    // 0x8001DDAC: nop

    Audio_LoadAquasSequence(rdram, ctx);
        goto after_3;
    // 0x8001DDAC: nop

    after_3:
    // 0x8001DDB0: lui         $a0, 0x4200
    ctx->r4 = S32(0X4200 << 16);
    // 0x8001DDB4: jal         0x800182F4
    // 0x8001DDB8: ori         $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 | 0X7F;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_4;
    // 0x8001DDB8: ori         $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 | 0X7F;
    after_4:
    // 0x8001DDBC: lui         $a0, 0x4300
    ctx->r4 = S32(0X4300 << 16);
    // 0x8001DDC0: jal         0x800182F4
    // 0x8001DDC4: ori         $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 | 0X7F;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_5;
    // 0x8001DDC4: ori         $a0, $a0, 0x7F
    ctx->r4 = ctx->r4 | 0X7F;
    after_5:
    // 0x8001DDC8: jal         0x8001E920
    // 0x8001DDCC: nop

    AudioThread_ScheduleProcessCmds(rdram, ctx);
        goto after_6;
    // 0x8001DDCC: nop

    after_6:
    // 0x8001DDD0: lui         $a0, 0xF800
    ctx->r4 = S32(0XF800 << 16);
    // 0x8001DDD4: jal         0x8001E8CC
    // 0x8001DDD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_7;
    // 0x8001DDD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x8001DDDC: lui         $a0, 0xF800
    ctx->r4 = S32(0XF800 << 16);
    // 0x8001DDE0: jal         0x8001E8CC
    // 0x8001DDE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_8;
    // 0x8001DDE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8001DDE8: lui         $a0, 0xF800
    ctx->r4 = S32(0XF800 << 16);
    // 0x8001DDEC: jal         0x8001E8CC
    // 0x8001DDF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    AudioThread_QueueCmdS32(rdram, ctx);
        goto after_9;
    // 0x8001DDF0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x8001DDF4: jal         0x8001D780
    // 0x8001DDF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Audio_RestoreVolumeSettings(rdram, ctx);
        goto after_10;
    // 0x8001DDF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x8001DDFC: jal         0x8001D780
    // 0x8001DE00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Audio_RestoreVolumeSettings(rdram, ctx);
        goto after_11;
    // 0x8001DE00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x8001DE04: jal         0x8001D780
    // 0x8001DE08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Audio_RestoreVolumeSettings(rdram, ctx);
        goto after_12;
    // 0x8001DE08: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x8001DE0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DE10: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001DE14: jr          $ra
    // 0x8001DE18: nop

    return;
    // 0x8001DE18: nop

;}
RECOMP_FUNC void osParameterPad(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021A60: nop

    // 0x80021A64: nop

    // 0x80021A68: nop

    // 0x80021A6C: nop

    // 0x80021A70: nop

    // 0x80021A74: nop

    // 0x80021A78: nop

    // 0x80021A7C: nop

    // 0x80021A80: nop

    // 0x80021A84: nop

    // 0x80021A88: nop

    // 0x80021A8C: nop

    // 0x80021A90: nop

    // 0x80021A94: nop

    // 0x80021A98: nop

    // 0x80021A9C: nop

    // 0x80021AA0: nop

    // 0x80021AA4: nop

    // 0x80021AA8: nop

    // 0x80021AAC: nop

    // 0x80021AB0: nop

    // 0x80021AB4: nop

    // 0x80021AB8: nop

    // 0x80021ABC: nop

;}
RECOMP_FUNC void Matrix_LookAt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E3C: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80006E40: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80006E44: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80006E48: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80006E4C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80006E50: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80006E54: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80006E58: lwc1        $f6, 0x84($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80006E5C: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80006E60: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80006E64: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80006E68: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80006E6C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80006E70: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80006E74: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80006E78: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80006E7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80006E80: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80006E84: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80006E88: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80006E8C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80006E90: jal         0x800211D0
    // 0x80006E94: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    guLookAtF(rdram, ctx);
        goto after_0;
    // 0x80006E94: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80006E98: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80006E9C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80006EA0: jal         0x80005754
    // 0x80006EA4: lbu         $a2, 0x9B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X9B);
    Matrix_Mult(rdram, ctx);
        goto after_1;
    // 0x80006EA4: lbu         $a2, 0x9B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X9B);
    after_1:
    // 0x80006EA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80006EAC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x80006EB0: jr          $ra
    // 0x80006EB4: nop

    return;
    // 0x80006EB4: nop

;}
RECOMP_FUNC void func_enmy_8006546C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006546C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065470: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80065474: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80065478: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8006547C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80065480: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80065484: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80065488: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8006548C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80065490:
    // 0x80065490: bnel        $t6, $zero, L_800654CC
    if (ctx->r14 != 0) {
        // 0x80065494: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_800654CC;
    }
    goto skip_0;
    // 0x80065494: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_0:
    // 0x80065498: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8006549C: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800654A0: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800654A4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800654A8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800654AC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800654B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800654B4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800654B8: jal         0x80065380
    // 0x800654BC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    func_enmy_80065380(rdram, ctx);
        goto after_0;
    // 0x800654BC: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800654C0: b           L_800654D8
    // 0x800654C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_800654D8;
    // 0x800654C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800654C8: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_800654CC:
    // 0x800654CC: bnel        $a0, $v0, L_80065490
    if (ctx->r4 != ctx->r2) {
        // 0x800654D0: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80065490;
    }
    goto skip_1;
    // 0x800654D0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x800654D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800654D8:
    // 0x800654D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800654DC: jr          $ra
    // 0x800654E0: nop

    return;
    // 0x800654E0: nop

;}
RECOMP_FUNC void AudioLoad_GetFontSample(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001079C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800107A0: slti        $at, $a1, 0x80
    ctx->r1 = SIGNED(ctx->r5) < 0X80 ? 1 : 0;
    // 0x800107A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800107A8: beq         $at, $zero, L_800107D0
    if (ctx->r1 == 0) {
        // 0x800107AC: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800107D0;
    }
    // 0x800107AC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800107B0: jal         0x80011D4C
    // 0x800107B4: nop

    Audio_GetInstrument(rdram, ctx);
        goto after_0;
    // 0x800107B4: nop

    after_0:
    // 0x800107B8: bne         $v0, $zero, L_800107C8
    if (ctx->r2 != 0) {
        // 0x800107BC: nop
    
            goto L_800107C8;
    }
    // 0x800107BC: nop

    // 0x800107C0: b           L_800107F0
    // 0x800107C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800107F0;
    // 0x800107C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800107C8:
    // 0x800107C8: b           L_800107EC
    // 0x800107CC: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
        goto L_800107EC;
    // 0x800107CC: lw          $v1, 0x10($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X10);
L_800107D0:
    // 0x800107D0: jal         0x80011DFC
    // 0x800107D4: addiu       $a1, $a2, -0x80
    ctx->r5 = ADD32(ctx->r6, -0X80);
    Audio_GetDrum(rdram, ctx);
        goto after_1;
    // 0x800107D4: addiu       $a1, $a2, -0x80
    ctx->r5 = ADD32(ctx->r6, -0X80);
    after_1:
    // 0x800107D8: bnel        $v0, $zero, L_800107EC
    if (ctx->r2 != 0) {
        // 0x800107DC: lw          $v1, 0x4($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X4);
            goto L_800107EC;
    }
    goto skip_0;
    // 0x800107DC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    skip_0:
    // 0x800107E0: b           L_800107F0
    // 0x800107E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800107F0;
    // 0x800107E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800107E8: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
L_800107EC:
    // 0x800107EC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800107F0:
    // 0x800107F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800107F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800107F8: jr          $ra
    // 0x800107FC: nop

    return;
    // 0x800107FC: nop

;}
RECOMP_FUNC void AudioThread_ProcessGlobalCmd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E444: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001E448: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001E44C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E450: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001E454: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E458: slti        $at, $v0, 0x89
    ctx->r1 = SIGNED(ctx->r2) < 0X89 ? 1 : 0;
    // 0x8001E45C: bne         $at, $zero, L_8001E488
    if (ctx->r1 != 0) {
        // 0x8001E460: addiu       $t7, $v0, -0x81
        ctx->r15 = ADD32(ctx->r2, -0X81);
            goto L_8001E488;
    }
    // 0x8001E460: addiu       $t7, $v0, -0x81
    ctx->r15 = ADD32(ctx->r2, -0X81);
    // 0x8001E464: addiu       $t6, $v0, -0xF0
    ctx->r14 = ADD32(ctx->r2, -0XF0);
    // 0x8001E468: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x8001E46C: beq         $at, $zero, L_8001E70C
    if (ctx->r1 == 0) {
        // 0x8001E470: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8001E70C;
    }
    // 0x8001E470: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001E474: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001E478: addu        $at, $at, $t6
    gpr jr_addend_8001E480 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8001E47C: lw          $t6, -0x6D54($at)
    ctx->r14 = ADD32(ctx->r1, -0X6D54);
    // 0x8001E480: jr          $t6
    // 0x8001E484: nop

    switch (jr_addend_8001E480 >> 2) {
        case 0: goto L_8001E548; break;
        case 1: goto L_8001E558; break;
        case 2: goto L_8001E5AC; break;
        case 3: goto L_8001E6AC; break;
        case 4: goto L_8001E6C4; break;
        case 5: goto L_8001E6E4; break;
        case 6: goto L_8001E704; break;
        default: switch_error(__func__, 0x8001E480, 0x800C92AC);
    }
    // 0x8001E484: nop

L_8001E488:
    // 0x8001E488: sltiu       $at, $t7, 0x8
    ctx->r1 = ctx->r15 < 0X8 ? 1 : 0;
    // 0x8001E48C: beq         $at, $zero, L_8001E70C
    if (ctx->r1 == 0) {
        // 0x8001E490: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8001E70C;
    }
    // 0x8001E490: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8001E494: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8001E498: addu        $at, $at, $t7
    gpr jr_addend_8001E4A0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8001E49C: lw          $t7, -0x6D38($at)
    ctx->r15 = ADD32(ctx->r1, -0X6D38);
    // 0x8001E4A0: jr          $t7
    // 0x8001E4A4: nop

    switch (jr_addend_8001E4A0 >> 2) {
        case 0: goto L_8001E4A8; break;
        case 1: goto L_8001E4BC; break;
        case 2: goto L_8001E4E0; break;
        case 3: goto L_8001E70C; break;
        case 4: goto L_8001E70C; break;
        case 5: goto L_8001E70C; break;
        case 6: goto L_8001E70C; break;
        case 7: goto L_8001E4BC; break;
        default: switch_error(__func__, 0x8001E4A0, 0x800C92C8);
    }
    // 0x8001E4A4: nop

L_8001E4A8:
    // 0x8001E4A8: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    // 0x8001E4AC: jal         0x8000ECC0
    // 0x8001E4B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    AudioLoad_SyncLoadSeqParts(rdram, ctx);
        goto after_0;
    // 0x8001E4B0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x8001E4B4: b           L_8001E710
    // 0x8001E4B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E710;
    // 0x8001E4B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E4BC:
    // 0x8001E4BC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001E4C0: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8001E4C4: jal         0x8000F200
    // 0x8001E4C8: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    AudioLoad_SyncInitSeqPlayer(rdram, ctx);
        goto after_1;
    // 0x8001E4C8: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    after_1:
    // 0x8001E4CC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001E4D0: jal         0x8001E778
    // 0x8001E4D4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    AudioThread_SetFadeInTimer(rdram, ctx);
        goto after_2;
    // 0x8001E4D4: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    after_2:
    // 0x8001E4D8: b           L_8001E710
    // 0x8001E4DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E710;
    // 0x8001E4DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E4E0:
    // 0x8001E4E0: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8001E4E4: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8001E4E8: addiu       $t9, $t9, -0x1AC8
    ctx->r25 = ADD32(ctx->r25, -0X1AC8);
    // 0x8001E4EC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001E4F0: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001E4F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E4F8: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8001E4FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E500: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8001E504: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8001E508: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x8001E50C: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8001E510: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x8001E514: beql        $t2, $zero, L_8001E710
    if (ctx->r10 == 0) {
        // 0x8001E518: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8001E710;
    }
    goto skip_0;
    // 0x8001E518: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8001E51C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8001E520: bne         $a1, $zero, L_8001E538
    if (ctx->r5 != 0) {
        // 0x8001E524: nop
    
            goto L_8001E538;
    }
    // 0x8001E524: nop

    // 0x8001E528: jal         0x800144E4
    // 0x8001E52C: nop

    AudioSeq_SequencePlayerDisable(rdram, ctx);
        goto after_3;
    // 0x8001E52C: nop

    after_3:
    // 0x8001E530: b           L_8001E710
    // 0x8001E534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E710;
    // 0x8001E534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E538:
    // 0x8001E538: jal         0x8001E720
    // 0x8001E53C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    AudioThread_SetFadeOutTimer(rdram, ctx);
        goto after_4;
    // 0x8001E53C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8001E540: b           L_8001E710
    // 0x8001E544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E710;
    // 0x8001E544: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E548:
    // 0x8001E548: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8001E54C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E550: b           L_8001E70C
    // 0x8001E554: sb          $t3, 0x5CA6($at)
    MEM_B(0X5CA6, ctx->r1) = ctx->r11;
        goto L_8001E70C;
    // 0x8001E554: sb          $t3, 0x5CA6($at)
    MEM_B(0X5CA6, ctx->r1) = ctx->r11;
L_8001E558:
    // 0x8001E558: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001E55C: lbu         $t7, -0x1AC8($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X1AC8);
    // 0x8001E560: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001E564: lbu         $t1, -0x197C($v1)
    ctx->r9 = MEM_BU(ctx->r3, -0X197C);
    // 0x8001E568: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001E56C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001E570: lbu         $a1, -0x16E4($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X16E4);
    // 0x8001E574: lbu         $a0, -0x1830($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1830);
    // 0x8001E578: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E57C: ori         $v0, $t7, 0x24
    ctx->r2 = ctx->r15 | 0X24;
    // 0x8001E580: sb          $v0, -0x1AC8($at)
    MEM_B(-0X1AC8, ctx->r1) = ctx->r2;
    // 0x8001E584: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E588: ori         $v1, $t1, 0x24
    ctx->r3 = ctx->r9 | 0X24;
    // 0x8001E58C: sb          $v1, -0x197C($at)
    MEM_B(-0X197C, ctx->r1) = ctx->r3;
    // 0x8001E590: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E594: ori         $t3, $a0, 0x24
    ctx->r11 = ctx->r4 | 0X24;
    // 0x8001E598: sb          $t3, -0x1830($at)
    MEM_B(-0X1830, ctx->r1) = ctx->r11;
    // 0x8001E59C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E5A0: ori         $t9, $a1, 0x24
    ctx->r25 = ctx->r5 | 0X24;
    // 0x8001E5A4: b           L_8001E70C
    // 0x8001E5A8: sb          $t9, -0x16E4($at)
    MEM_B(-0X16E4, ctx->r1) = ctx->r25;
        goto L_8001E70C;
    // 0x8001E5A8: sb          $t9, -0x16E4($at)
    MEM_B(-0X16E4, ctx->r1) = ctx->r25;
L_8001E5AC:
    // 0x8001E5AC: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x8001E5B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E5B4: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8001E5B8: bne         $t1, $at, L_8001E648
    if (ctx->r9 != ctx->r1) {
        // 0x8001E5BC: nop
    
            goto L_8001E648;
    }
    // 0x8001E5BC: nop

    // 0x8001E5C0: lw          $a2, 0x5CA0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CA0);
    // 0x8001E5C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001E5C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001E5CC: blez        $a2, L_8001E648
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001E5D0: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8001E648;
    }
    // 0x8001E5D0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8001E5D4: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8001E5D8: addiu       $a3, $a3, -0x1AD0
    ctx->r7 = ADD32(ctx->r7, -0X1AD0);
L_8001E5DC:
    // 0x8001E5DC: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8001E5E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001E5E4: addu        $v1, $a1, $t2
    ctx->r3 = ADD32(ctx->r5, ctx->r10);
    // 0x8001E5E8: lw          $t3, 0xB0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XB0);
    // 0x8001E5EC: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x8001E5F0: beql        $t4, $zero, L_8001E640
    if (ctx->r12 == 0) {
        // 0x8001E5F4: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001E640;
    }
    goto skip_1;
    // 0x8001E5F4: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_1:
    // 0x8001E5F8: lbu         $t5, 0x34($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X34);
    // 0x8001E5FC: bnel        $t5, $zero, L_8001E640
    if (ctx->r13 != 0) {
        // 0x8001E600: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001E640;
    }
    goto skip_2;
    // 0x8001E600: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_2:
    // 0x8001E604: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x8001E608: beql        $t0, $v0, L_8001E640
    if (ctx->r8 == ctx->r2) {
        // 0x8001E60C: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001E640;
    }
    goto skip_3;
    // 0x8001E60C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_3:
    // 0x8001E610: lw          $t6, 0x4C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4C);
    // 0x8001E614: addiu       $v0, $v1, 0xB0
    ctx->r2 = ADD32(ctx->r3, 0XB0);
    // 0x8001E618: lbu         $t7, 0x3($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X3);
    // 0x8001E61C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8001E620: beql        $t8, $zero, L_8001E640
    if (ctx->r24 == 0) {
        // 0x8001E624: slt         $at, $a0, $a2
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001E640;
    }
    goto skip_4;
    // 0x8001E624: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
    skip_4:
    // 0x8001E628: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8001E62C: lui         $a2, 0x8015
    ctx->r6 = S32(0X8015 << 16);
    // 0x8001E630: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x8001E634: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x8001E638: lw          $a2, 0x5CA0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X5CA0);
    // 0x8001E63C: slt         $at, $a0, $a2
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r6) ? 1 : 0;
L_8001E640:
    // 0x8001E640: bne         $at, $zero, L_8001E5DC
    if (ctx->r1 != 0) {
        // 0x8001E644: addiu       $a1, $a1, 0xC0
        ctx->r5 = ADD32(ctx->r5, 0XC0);
            goto L_8001E5DC;
    }
    // 0x8001E644: addiu       $a1, $a1, 0xC0
    ctx->r5 = ADD32(ctx->r5, 0XC0);
L_8001E648:
    // 0x8001E648: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8001E64C: lbu         $v0, -0x1AC8($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1AC8);
    // 0x8001E650: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8001E654: lbu         $v1, -0x197C($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X197C);
    // 0x8001E658: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001E65C: lbu         $a0, -0x1830($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X1830);
    // 0x8001E660: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001E664: andi        $t5, $v0, 0xFFDF
    ctx->r13 = ctx->r2 & 0XFFDF;
    // 0x8001E668: lbu         $a1, -0x16E4($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X16E4);
    // 0x8001E66C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E670: ori         $v0, $t5, 0x4
    ctx->r2 = ctx->r13 | 0X4;
    // 0x8001E674: sb          $v0, -0x1AC8($at)
    MEM_B(-0X1AC8, ctx->r1) = ctx->r2;
    // 0x8001E678: andi        $t1, $v1, 0xFFDF
    ctx->r9 = ctx->r3 & 0XFFDF;
    // 0x8001E67C: ori         $v1, $t1, 0x4
    ctx->r3 = ctx->r9 | 0X4;
    // 0x8001E680: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E684: sb          $v1, -0x197C($at)
    MEM_B(-0X197C, ctx->r1) = ctx->r3;
    // 0x8001E688: andi        $t6, $a0, 0xFFDF
    ctx->r14 = ctx->r4 & 0XFFDF;
    // 0x8001E68C: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8001E690: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E694: sb          $t8, -0x1830($at)
    MEM_B(-0X1830, ctx->r1) = ctx->r24;
    // 0x8001E698: andi        $t2, $a1, 0xFFDF
    ctx->r10 = ctx->r5 & 0XFFDF;
    // 0x8001E69C: ori         $t4, $t2, 0x4
    ctx->r12 = ctx->r10 | 0X4;
    // 0x8001E6A0: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8001E6A4: b           L_8001E70C
    // 0x8001E6A8: sb          $t4, -0x16E4($at)
    MEM_B(-0X16E4, ctx->r1) = ctx->r12;
        goto L_8001E70C;
    // 0x8001E6A8: sb          $t4, -0x16E4($at)
    MEM_B(-0X16E4, ctx->r1) = ctx->r12;
L_8001E6AC:
    // 0x8001E6AC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001E6B0: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8001E6B4: jal         0x8000EE14
    // 0x8001E6B8: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    AudioLoad_SyncLoadInstrument(rdram, ctx);
        goto after_5;
    // 0x8001E6B8: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    after_5:
    // 0x8001E6BC: b           L_8001E710
    // 0x8001E6C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E710;
    // 0x8001E6C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E6C4:
    // 0x8001E6C4: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8001E6C8: addiu       $a3, $a3, 0x4248
    ctx->r7 = ADD32(ctx->r7, 0X4248);
    // 0x8001E6CC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001E6D0: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8001E6D4: jal         0x8000EEE4
    // 0x8001E6D8: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    AudioLoad_AsyncLoadSampleBank(rdram, ctx);
        goto after_6;
    // 0x8001E6D8: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    after_6:
    // 0x8001E6DC: b           L_8001E710
    // 0x8001E6E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E710;
    // 0x8001E6E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E6E4:
    // 0x8001E6E4: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8001E6E8: addiu       $a3, $a3, 0x4248
    ctx->r7 = ADD32(ctx->r7, 0X4248);
    // 0x8001E6EC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x8001E6F0: lbu         $a1, 0x2($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2);
    // 0x8001E6F4: jal         0x8000EF48
    // 0x8001E6F8: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    AudioLoad_AsyncLoadSeq(rdram, ctx);
        goto after_7;
    // 0x8001E6F8: lbu         $a2, 0x3($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X3);
    after_7:
    // 0x8001E6FC: b           L_8001E710
    // 0x8001E700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001E710;
    // 0x8001E700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E704:
    // 0x8001E704: jal         0x8000F078
    // 0x8001E708: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    AudioLoad_DiscardSeqFonts(rdram, ctx);
        goto after_8;
    // 0x8001E708: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    after_8:
L_8001E70C:
    // 0x8001E70C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001E710:
    // 0x8001E710: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E714: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001E718: jr          $ra
    // 0x8001E71C: nop

    return;
    // 0x8001E71C: nop

;}
RECOMP_FUNC void AudioHeap_AllocTemporarySampleCache(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DBE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000DBE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000DBEC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000DBF0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8000DBF4: jal         0x8000DD68
    // 0x8000DBF8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    AudioHeap_AllocTemporarySampleCacheEntry(rdram, ctx);
        goto after_0;
    // 0x8000DBF8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000DBFC: beq         $v0, $zero, L_8000DC20
    if (ctx->r2 == 0) {
        // 0x8000DC00: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_8000DC20;
    }
    // 0x8000DC00: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8000DC04: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x8000DC08: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8000DC0C: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8000DC10: lb          $t8, 0x27($sp)
    ctx->r24 = MEM_B(ctx->r29, 0X27);
    // 0x8000DC14: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000DC18: b           L_8000DC24
    // 0x8000DC1C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
        goto L_8000DC24;
    // 0x8000DC1C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
L_8000DC20:
    // 0x8000DC20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000DC24:
    // 0x8000DC24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000DC28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000DC2C: jr          $ra
    // 0x8000DC30: nop

    return;
    // 0x8000DC30: nop

;}
RECOMP_FUNC void func_enmy_80066C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066C00: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80066C04: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80066C08: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80066C0C: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80066C10: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80066C14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80066C18: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80066C1C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80066C20: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80066C24: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80066C28: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x80066C2C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80066C30: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80066C34: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80066C38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80066C3C: swc1        $f24, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f24.u32l;
    // 0x80066C40: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80066C44: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x80066C48: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80066C4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80066C50: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80066C54: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80066C58: nop

    // 0x80066C5C: bc1f        L_80066C74
    if (!c1cs) {
        // 0x80066C60: nop
    
            goto L_80066C74;
    }
    // 0x80066C60: nop

    // 0x80066C64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80066C68: nop

    // 0x80066C6C: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80066C70: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
L_80066C74:
    // 0x80066C74: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80066C78: lwc1        $f10, 0x6940($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6940);
    // 0x80066C7C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80066C80: addiu       $s3, $s3, -0x4438
    ctx->r19 = ADD32(ctx->r19, -0X4438);
    // 0x80066C84: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80066C88: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80066C8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80066C90: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80066C94: jal         0x80005E90
    // 0x80066C98: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x80066C98: nop

    after_0:
    // 0x80066C9C: lui         $at, 0xC334
    ctx->r1 = S32(0XC334 << 16);
    // 0x80066CA0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80066CA4: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80066CA8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80066CAC: addiu       $s2, $sp, 0x58
    ctx->r18 = ADD32(ctx->r29, 0X58);
    // 0x80066CB0: c.le.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl <= ctx->f26.fl;
    // 0x80066CB4: nop

    // 0x80066CB8: bc1fl       L_80066D34
    if (!c1cs) {
        // 0x80066CBC: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80066D34;
    }
    goto skip_0;
    // 0x80066CBC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80066CC0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80066CC4: addiu       $s1, $sp, 0x64
    ctx->r17 = ADD32(ctx->r29, 0X64);
    // 0x80066CC8: swc1        $f20, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f20.u32l;
L_80066CCC:
    // 0x80066CCC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80066CD0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80066CD4: jal         0x80006A20
    // 0x80066CD8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x80066CD8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80066CDC: jal         0x80004EB0
    // 0x80066CE0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80066CE0: nop

    after_2:
    // 0x80066CE4: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80066CE8: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80066CEC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80066CF0: lwc1        $f16, 0x60($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80066CF4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80066CF8: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80066CFC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80066D00: add.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f22.fl;
    // 0x80066D04: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80066D08: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80066D0C: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80066D10: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80066D14: jal         0x8007D0E0
    // 0x80066D18: nop

    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_3;
    // 0x80066D18: nop

    after_3:
    // 0x80066D1C: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x80066D20: c.le.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl <= ctx->f26.fl;
    // 0x80066D24: nop

    // 0x80066D28: bc1tl       L_80066CCC
    if (c1cs) {
        // 0x80066D2C: swc1        $f20, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f20.u32l;
            goto L_80066CCC;
    }
    goto skip_1;
    // 0x80066D2C: swc1        $f20, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f20.u32l;
    skip_1:
    // 0x80066D30: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80066D34:
    // 0x80066D34: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80066D38: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x80066D3C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x80066D40: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x80066D44: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x80066D48: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80066D4C: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80066D50: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80066D54: jr          $ra
    // 0x80066D58: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80066D58: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Play_InitEnvironment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A594C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A5950: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A5954: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800A5958: lw          $t6, 0x78E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78E8);
    // 0x800A595C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800A5960: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800A5964: beq         $t6, $zero, L_800A5A60
    if (ctx->r14 == 0) {
        // 0x800A5968: nop
    
            goto L_800A5A60;
    }
    // 0x800A5968: nop

    // 0x800A596C: lw          $v0, 0x789C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X789C);
    // 0x800A5970: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A5974: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A5978: beq         $v0, $zero, L_800A59A0
    if (ctx->r2 == 0) {
        // 0x800A597C: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_800A59A0;
    }
    // 0x800A597C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800A5980: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A5984: beq         $v0, $at, L_800A59DC
    if (ctx->r2 == ctx->r1) {
        // 0x800A5988: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800A59DC;
    }
    // 0x800A5988: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A598C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A5990: beq         $v0, $at, L_800A5A1C
    if (ctx->r2 == ctx->r1) {
        // 0x800A5994: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_800A5A1C;
    }
    // 0x800A5994: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800A5998: b           L_800A5A58
    // 0x800A599C: nop

        goto L_800A5A58;
    // 0x800A599C: nop

L_800A59A0:
    // 0x800A59A0: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800A59A4: addiu       $v0, $v0, -0x2290
    ctx->r2 = ADD32(ctx->r2, -0X2290);
    // 0x800A59A8: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800A59AC: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800A59B0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A59B4: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800A59B8: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x800A59BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A59C0: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800A59C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A59C8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A59CC: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800A59D0: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A59D4: b           L_800A5A58
    // 0x800A59D8: sw          $t9, 0x1A68($at)
    MEM_W(0X1A68, ctx->r1) = ctx->r25;
        goto L_800A5A58;
    // 0x800A59D8: sw          $t9, 0x1A68($at)
    MEM_W(0X1A68, ctx->r1) = ctx->r25;
L_800A59DC:
    // 0x800A59DC: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800A59E0: addiu       $v0, $v0, -0x224C
    ctx->r2 = ADD32(ctx->r2, -0X224C);
    // 0x800A59E4: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800A59E8: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800A59EC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A59F0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A59F4: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A59F8: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x800A59FC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5A00: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x800A5A04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5A08: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800A5A0C: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800A5A10: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5A14: b           L_800A5A58
    // 0x800A5A18: sw          $t8, 0x1A68($at)
    MEM_W(0X1A68, ctx->r1) = ctx->r24;
        goto L_800A5A58;
    // 0x800A5A18: sw          $t8, 0x1A68($at)
    MEM_W(0X1A68, ctx->r1) = ctx->r24;
L_800A5A1C:
    // 0x800A5A1C: lui         $v0, 0x303
    ctx->r2 = S32(0X303 << 16);
    // 0x800A5A20: addiu       $v0, $v0, -0x2208
    ctx->r2 = ADD32(ctx->r2, -0X2208);
    // 0x800A5A24: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x800A5A28: srl         $t6, $t9, 28
    ctx->r14 = S32(U32(ctx->r25) >> 28);
    // 0x800A5A2C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800A5A30: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800A5A34: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A5A38: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x800A5A3C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5A40: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x800A5A44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5A48: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800A5A4C: addu        $t7, $t6, $at
    ctx->r15 = ADD32(ctx->r14, ctx->r1);
    // 0x800A5A50: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5A54: sw          $t7, 0x1A68($at)
    MEM_W(0X1A68, ctx->r1) = ctx->r15;
L_800A5A58:
    // 0x800A5A58: b           L_800A5AAC
    // 0x800A5A5C: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
        goto L_800A5AAC;
    // 0x800A5A5C: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
L_800A5A60:
    // 0x800A5A60: lw          $v1, -0x7DCC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DCC);
    // 0x800A5A64: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800A5A68: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A5A6C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800A5A70: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800A5A74: lw          $v0, 0x2F98($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2F98);
    // 0x800A5A78: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5A7C: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x800A5A80: srl         $t7, $t6, 28
    ctx->r15 = S32(U32(ctx->r14) >> 28);
    // 0x800A5A84: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A5A88: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A5A8C: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x800A5A90: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x800A5A94: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x800A5A98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5A9C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800A5AA0: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x800A5AA4: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5AA8: sw          $t8, 0x1A68($at)
    MEM_W(0X1A68, ctx->r1) = ctx->r24;
L_800A5AAC:
    // 0x800A5AAC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800A5AB0: lw          $t9, 0x782C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X782C);
    // 0x800A5AB4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800A5AB8: bne         $t9, $zero, L_800A5B24
    if (ctx->r25 != 0) {
        // 0x800A5ABC: nop
    
            goto L_800A5B24;
    }
    // 0x800A5ABC: nop

    // 0x800A5AC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A5AC4: bne         $v1, $at, L_800A5B68
    if (ctx->r3 != ctx->r1) {
        // 0x800A5AC8: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800A5B68;
    }
    // 0x800A5AC8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800A5ACC: jal         0x8001D1C8
    // 0x800A5AD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    Audio_SetHeatAlarmParams(rdram, ctx);
        goto after_0;
    // 0x800A5AD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800A5AD4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800A5AD8: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x800A5ADC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x800A5AE0: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x800A5AE4: lui         $a0, 0x4100
    ctx->r4 = S32(0X4100 << 16);
    // 0x800A5AE8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800A5AEC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800A5AF0: ori         $a0, $a0, 0xC023
    ctx->r4 = ctx->r4 | 0XC023;
    // 0x800A5AF4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800A5AF8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800A5AFC: jal         0x80019218
    // 0x800A5B00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x800A5B00: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x800A5B04: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800A5B08: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x800A5B0C: lui         $a1, 0x3140
    ctx->r5 = S32(0X3140 << 16);
    // 0x800A5B10: ori         $a1, $a1, 0x807E
    ctx->r5 = ctx->r5 | 0X807E;
    // 0x800A5B14: jal         0x8001A55C
    // 0x800A5B18: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_2;
    // 0x800A5B18: addiu       $a0, $a0, 0x460
    ctx->r4 = ADD32(ctx->r4, 0X460);
    after_2:
    // 0x800A5B1C: b           L_800A5B68
    // 0x800A5B20: nop

        goto L_800A5B68;
    // 0x800A5B20: nop

L_800A5B24:
    // 0x800A5B24: bne         $v1, $at, L_800A5B68
    if (ctx->r3 != ctx->r1) {
        // 0x800A5B28: lui         $v0, 0x603
        ctx->r2 = S32(0X603 << 16);
            goto L_800A5B68;
    }
    // 0x800A5B28: lui         $v0, 0x603
    ctx->r2 = S32(0X603 << 16);
    // 0x800A5B2C: addiu       $v0, $v0, -0x1A7C
    ctx->r2 = ADD32(ctx->r2, -0X1A7C);
    // 0x800A5B30: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x800A5B34: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x800A5B38: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A5B3C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A5B40: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800A5B44: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800A5B48: lw          $t6, 0x1FD0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1FD0);
    // 0x800A5B4C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800A5B50: and         $t7, $v0, $at
    ctx->r15 = ctx->r2 & ctx->r1;
    // 0x800A5B54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A5B58: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A5B5C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x800A5B60: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5B64: sw          $t9, 0x1A68($at)
    MEM_W(0X1A68, ctx->r1) = ctx->r25;
L_800A5B68:
    // 0x800A5B68: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800A5B6C: lw          $v0, 0x1A68($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1A68);
    // 0x800A5B70: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5B74: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x800A5B78: lhu         $t6, 0xA($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0XA);
    // 0x800A5B7C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800A5B80: addiu       $a0, $a0, -0x7A9C
    ctx->r4 = ADD32(ctx->r4, -0X7A9C);
    // 0x800A5B84: sh          $t6, 0x7C90($at)
    MEM_H(0X7C90, ctx->r1) = ctx->r14;
    // 0x800A5B88: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800A5B8C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800A5B90: addiu       $v1, $v1, 0x1A70
    ctx->r3 = ADD32(ctx->r3, 0X1A70);
    // 0x800A5B94: sb          $t7, 0x7C98($at)
    MEM_B(0X7C98, ctx->r1) = ctx->r15;
    // 0x800A5B98: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800A5B9C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5BA0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x800A5BA4: sw          $t8, -0x7B54($at)
    MEM_W(-0X7B54, ctx->r1) = ctx->r24;
    // 0x800A5BA8: lhu         $t9, 0x8($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X8);
    // 0x800A5BAC: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5BB0: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x800A5BB4: sh          $t9, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = ctx->r25;
    // 0x800A5BB8: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800A5BBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5BC0: addiu       $a2, $a2, -0x7A98
    ctx->r6 = ADD32(ctx->r6, -0X7A98);
    // 0x800A5BC4: sw          $t6, -0x7CE0($at)
    MEM_W(-0X7CE0, ctx->r1) = ctx->r14;
    // 0x800A5BC8: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x800A5BCC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5BD0: addiu       $a1, $a1, 0x1A74
    ctx->r5 = ADD32(ctx->r5, 0X1A74);
    // 0x800A5BD4: sw          $t7, -0x7CD8($at)
    MEM_W(-0X7CD8, ctx->r1) = ctx->r15;
    // 0x800A5BD8: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x800A5BDC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5BE0: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x800A5BE4: sw          $t8, -0x7CD0($at)
    MEM_W(-0X7CD0, ctx->r1) = ctx->r24;
    // 0x800A5BE8: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x800A5BEC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5BF0: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x800A5BF4: sw          $t9, -0x7C28($at)
    MEM_W(-0X7C28, ctx->r1) = ctx->r25;
    // 0x800A5BF8: lw          $t6, 0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X1C);
    // 0x800A5BFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5C00: addiu       $t0, $t0, -0x7A94
    ctx->r8 = ADD32(ctx->r8, -0X7A94);
    // 0x800A5C04: sw          $t6, -0x7C24($at)
    MEM_W(-0X7C24, ctx->r1) = ctx->r14;
    // 0x800A5C08: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    // 0x800A5C0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5C10: addiu       $a3, $a3, 0x1A78
    ctx->r7 = ADD32(ctx->r7, 0X1A78);
    // 0x800A5C14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800A5C18: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A5C1C: sw          $t7, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r15;
    // 0x800A5C20: lw          $t6, 0x30($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X30);
    // 0x800A5C24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5C28: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x800A5C2C: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800A5C30: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800A5C34: sw          $t6, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r14;
    // 0x800A5C38: lw          $t9, 0x34($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X34);
    // 0x800A5C3C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5C40: addiu       $t1, $t1, -0x7B3C
    ctx->r9 = ADD32(ctx->r9, -0X7B3C);
    // 0x800A5C44: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800A5C48: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800A5C4C: sw          $t9, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r25;
    // 0x800A5C50: lw          $t8, 0x38($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X38);
    // 0x800A5C54: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5C58: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x800A5C5C: sw          $t8, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r24;
    // 0x800A5C60: lw          $t9, 0x3C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3C);
    // 0x800A5C64: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5C68: addiu       $t2, $t2, -0x7B48
    ctx->r10 = ADD32(ctx->r10, -0X7B48);
    // 0x800A5C6C: sw          $t9, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r25;
    // 0x800A5C70: lw          $t6, 0x40($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X40);
    // 0x800A5C74: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5C78: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800A5C7C: sw          $t6, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r14;
    // 0x800A5C80: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800A5C84: addiu       $t3, $t3, -0x7AE0
    ctx->r11 = ADD32(ctx->r11, -0X7AE0);
    // 0x800A5C88: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x800A5C8C: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x800A5C90: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x800A5C94: addiu       $t4, $t4, -0x7B08
    ctx->r12 = ADD32(ctx->r12, -0X7B08);
    // 0x800A5C98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5C9C: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x800A5CA0: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800A5CA4: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x800A5CA8: addiu       $t5, $t5, -0x7B38
    ctx->r13 = ADD32(ctx->r13, -0X7B38);
    // 0x800A5CAC: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800A5CB0: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800A5CB4: lui         $ra, 0x8018
    ctx->r31 = S32(0X8018 << 16);
    // 0x800A5CB8: addiu       $ra, $ra, -0x7B44
    ctx->r31 = ADD32(ctx->r31, -0X7B44);
    // 0x800A5CBC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800A5CC0: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800A5CC4: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x800A5CC8: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x800A5CCC: swc1        $f16, -0x7B30($at)
    MEM_W(-0X7B30, ctx->r1) = ctx->f16.u32l;
    // 0x800A5CD0: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800A5CD4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5CD8: swc1        $f18, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f18.u32l;
    // 0x800A5CDC: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800A5CE0: swc1        $f4, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f4.u32l;
    // 0x800A5CE4: lwc1        $f6, 0x0($ra)
    ctx->f6.u32l = MEM_W(ctx->r31, 0X0);
    // 0x800A5CE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5CEC: swc1        $f6, -0x7ADC($at)
    MEM_W(-0X7ADC, ctx->r1) = ctx->f6.u32l;
    // 0x800A5CF0: lwc1        $f8, -0x7ADC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7ADC);
    // 0x800A5CF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5CF8: swc1        $f8, -0x7B04($at)
    MEM_W(-0X7B04, ctx->r1) = ctx->f8.u32l;
    // 0x800A5CFC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5D00: swc1        $f8, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f8.u32l;
    // 0x800A5D04: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800A5D08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5D0C: swc1        $f10, -0x7B34($at)
    MEM_W(-0X7B34, ctx->r1) = ctx->f10.u32l;
    // 0x800A5D10: lwc1        $f16, -0x7B34($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7B34);
    // 0x800A5D14: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5D18: swc1        $f16, -0x7B40($at)
    MEM_W(-0X7B40, ctx->r1) = ctx->f16.u32l;
    // 0x800A5D1C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5D20: swc1        $f16, -0x7AD8($at)
    MEM_W(-0X7AD8, ctx->r1) = ctx->f16.u32l;
    // 0x800A5D24: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5D28: swc1        $f16, -0x7B00($at)
    MEM_W(-0X7B00, ctx->r1) = ctx->f16.u32l;
    // 0x800A5D2C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5D30: swc1        $f16, -0x7B28($at)
    MEM_W(-0X7B28, ctx->r1) = ctx->f16.u32l;
    // 0x800A5D34: lui         $at, 0x4648
    ctx->r1 = S32(0X4648 << 16);
    // 0x800A5D38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5D3C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5D40: swc1        $f18, 0x1A44($at)
    MEM_W(0X1A44, ctx->r1) = ctx->f18.u32l;
    // 0x800A5D44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5D48: sw          $t7, -0x7AC0($at)
    MEM_W(-0X7AC0, ctx->r1) = ctx->r15;
    // 0x800A5D4C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800A5D50: sw          $t8, -0x7ABC($at)
    MEM_W(-0X7ABC, ctx->r1) = ctx->r24;
    // 0x800A5D54: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x800A5D58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A5D5C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x800A5D60: swc1        $f4, 0x1A3C($at)
    MEM_W(0X1A3C, ctx->r1) = ctx->f4.u32l;
    // 0x800A5D64: jr          $ra
    // 0x800A5D68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A5D68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void MeMolarRock_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066A80: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80066A84: jr          $ra
    // 0x80066A88: nop

    return;
    // 0x80066A88: nop

;}
RECOMP_FUNC void func_enmy_800654E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800654E4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800654E8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800654EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800654F0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x800654F4: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800654F8: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800654FC: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80065500: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80065504: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80065508: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8006550C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80065510: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80065514: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80065518: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8006551C: jal         0x8007D2C8
    // 0x80065520: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    Effect_FireSmoke1_Spawn3(rdram, ctx);
        goto after_0;
    // 0x80065520: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    after_0:
    // 0x80065524: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80065528: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8006552C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80065530: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80065534: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80065538: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8006553C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80065540: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_80065544:
    // 0x80065544: jal         0x80004EB0
    // 0x80065548: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80065548: nop

    after_1:
    // 0x8006554C: jal         0x80004EB0
    // 0x80065550: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80065550: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_2:
    // 0x80065554: jal         0x80004EB0
    // 0x80065558: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80065558: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_3:
    // 0x8006555C: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x80065560: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80065564: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80065568: sub.s       $f8, $f22, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f24.fl;
    // 0x8006556C: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80065570: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80065574: mul.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80065578: nop

    // 0x8006557C: mul.s       $f16, $f0, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80065580: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80065584: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x80065588: jal         0x8006546C
    // 0x8006558C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    func_enmy_8006546C(rdram, ctx);
        goto after_4;
    // 0x8006558C: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80065590: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80065594: bne         $s1, $s2, L_80065544
    if (ctx->r17 != ctx->r18) {
        // 0x80065598: nop
    
            goto L_80065544;
    }
    // 0x80065598: nop

    // 0x8006559C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800655A0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800655A4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800655A8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800655AC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800655B0: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800655B4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800655B8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800655BC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800655C0: jr          $ra
    // 0x800655C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800655C4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_versus_800BD2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BD2A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BD2A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BD2A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BD2AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BD2B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD2B4: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x800BD2B8: lui         $a2, 0x700
    ctx->r6 = S32(0X700 << 16);
    // 0x800BD2BC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x800BD2C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800BD2C4: addiu       $a2, $a2, 0x42F0
    ctx->r6 = ADD32(ctx->r6, 0X42F0);
    // 0x800BD2C8: addiu       $a1, $a1, 0x41F0
    ctx->r5 = ADD32(ctx->r5, 0X41F0);
    // 0x800BD2CC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800BD2D0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800BD2D4: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800BD2D8: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800BD2DC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800BD2E0: jal         0x8009D0BC
    // 0x800BD2E4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BD2E4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800BD2E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BD2EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BD2F0: jr          $ra
    // 0x800BD2F4: nop

    return;
    // 0x800BD2F4: nop

;}
RECOMP_FUNC void RCP_SetupDL_0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8F18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B8F1C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x800B8F20: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800B8F24: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800B8F28: addiu       $t8, $t8, 0x31B0
    ctx->r24 = ADD32(ctx->r24, 0X31B0);
    // 0x800B8F2C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800B8F30: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800B8F34: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800B8F38: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B8F3C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800B8F40: jr          $ra
    // 0x800B8F44: nop

    return;
    // 0x800B8F44: nop

;}
RECOMP_FUNC void Boss_AwardBonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042EC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80042EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042EC8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80042ECC: lw          $v0, 0x13A0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13A0);
    // 0x80042ED0: slti        $at, $v0, 0xF00
    ctx->r1 = SIGNED(ctx->r2) < 0XF00 ? 1 : 0;
    // 0x80042ED4: beql        $at, $zero, L_80042EE8
    if (ctx->r1 == 0) {
        // 0x80042ED8: slti        $at, $v0, 0x1680
        ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
            goto L_80042EE8;
    }
    goto skip_0;
    // 0x80042ED8: slti        $at, $v0, 0x1680
    ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
    skip_0:
    // 0x80042EDC: b           L_80042F20
    // 0x80042EE0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
        goto L_80042F20;
    // 0x80042EE0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80042EE4: slti        $at, $v0, 0x1680
    ctx->r1 = SIGNED(ctx->r2) < 0X1680 ? 1 : 0;
L_80042EE8:
    // 0x80042EE8: beql        $at, $zero, L_80042EFC
    if (ctx->r1 == 0) {
        // 0x80042EEC: slti        $at, $v0, 0x1E00
        ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
            goto L_80042EFC;
    }
    goto skip_1;
    // 0x80042EEC: slti        $at, $v0, 0x1E00
    ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
    skip_1:
    // 0x80042EF0: b           L_80042F20
    // 0x80042EF4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
        goto L_80042F20;
    // 0x80042EF4: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x80042EF8: slti        $at, $v0, 0x1E00
    ctx->r1 = SIGNED(ctx->r2) < 0X1E00 ? 1 : 0;
L_80042EFC:
    // 0x80042EFC: beql        $at, $zero, L_80042F10
    if (ctx->r1 == 0) {
        // 0x80042F00: slti        $at, $v0, 0x2580
        ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
            goto L_80042F10;
    }
    goto skip_2;
    // 0x80042F00: slti        $at, $v0, 0x2580
    ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
    skip_2:
    // 0x80042F04: b           L_80042F20
    // 0x80042F08: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
        goto L_80042F20;
    // 0x80042F08: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80042F0C: slti        $at, $v0, 0x2580
    ctx->r1 = SIGNED(ctx->r2) < 0X2580 ? 1 : 0;
L_80042F10:
    // 0x80042F10: beq         $at, $zero, L_80042F20
    if (ctx->r1 == 0) {
        // 0x80042F14: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80042F20;
    }
    // 0x80042F14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80042F18: b           L_80042F20
    // 0x80042F1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_80042F20;
    // 0x80042F1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80042F20:
    // 0x80042F20: beq         $a3, $zero, L_80042F78
    if (ctx->r7 == 0) {
        // 0x80042F24: nop
    
            goto L_80042F78;
    }
    // 0x80042F24: nop

    // 0x80042F28: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x80042F2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80042F30: addiu       $at, $zero, 0x124
    ctx->r1 = ADD32(0, 0X124);
    // 0x80042F34: bne         $v0, $at, L_80042F48
    if (ctx->r2 != ctx->r1) {
        // 0x80042F38: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_80042F48;
    }
    // 0x80042F38: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80042F3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042F40: b           L_80042F60
    // 0x80042F44: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
        goto L_80042F60;
    // 0x80042F44: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_80042F48:
    // 0x80042F48: addiu       $at, $zero, 0x132
    ctx->r1 = ADD32(0, 0X132);
    // 0x80042F4C: bne         $v0, $at, L_80042F5C
    if (ctx->r2 != ctx->r1) {
        // 0x80042F50: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_80042F5C;
    }
    // 0x80042F50: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80042F54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80042F58: nop

L_80042F5C:
    // 0x80042F5C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
L_80042F60:
    // 0x80042F60: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80042F64: lw          $a2, 0xC($a0)
    ctx->r6 = MEM_W(ctx->r4, 0XC);
    // 0x80042F68: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80042F6C: jal         0x80077240
    // 0x80042F70: add.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f0.fl;
    BonusText_Display(rdram, ctx);
        goto after_0;
    // 0x80042F70: add.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f0.fl;
    after_0:
    // 0x80042F74: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80042F78:
    // 0x80042F78: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80042F7C: addiu       $v0, $v0, 0x1A98
    ctx->r2 = ADD32(ctx->r2, 0X1A98);
    // 0x80042F80: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80042F84: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80042F88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80042F8C: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x80042F90: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80042F94: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80042F98: sw          $t9, 0x7850($at)
    MEM_W(0X7850, ctx->r1) = ctx->r25;
    // 0x80042F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042FA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80042FA4: jr          $ra
    // 0x80042FA8: nop

    return;
    // 0x80042FA8: nop

;}
RECOMP_FUNC void Audio_ResetSequenceRequests(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800184D4: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800184D8: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800184DC: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800184E0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800184E4: jr          $ra
    // 0x800184E8: sb          $zero, -0x5660($at)
    MEM_B(-0X5660, ctx->r1) = 0;
    return;
    // 0x800184E8: sb          $zero, -0x5660($at)
    MEM_B(-0X5660, ctx->r1) = 0;
;}
RECOMP_FUNC void Fault_Wait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000770C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80007710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007714: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80007718: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8000771C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80007720: addiu       $a3, $zero, 0x3E8
    ctx->r7 = ADD32(0, 0X3E8);
    // 0x80007724: jal         0x80023DF8
    // 0x80007728: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    __ll_mul_recomp(rdram, ctx);
        goto after_0;
    // 0x80007728: sra         $a0, $a1, 31
    ctx->r4 = S32(SIGNED(ctx->r5) >> 31);
    after_0:
    // 0x8000772C: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x80007730: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80007734: lw          $a1, 0x7E14($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X7E14);
    // 0x80007738: lw          $a0, 0x7E10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7E10);
    // 0x8000773C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80007740: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80007744: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80007748: jal         0x80023CF8
    // 0x8000774C: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x8000774C: addiu       $a3, $zero, 0x3D09
    ctx->r7 = ADD32(0, 0X3D09);
    after_1:
    // 0x80007750: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80007754: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80007758: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000775C: jal         0x80023DF8
    // 0x80007760: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_2;
    // 0x80007760: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_2:
    // 0x80007764: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80007768: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8000776C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80007770: jal         0x80023CF8
    // 0x80007774: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    __ull_div_recomp(rdram, ctx);
        goto after_3;
    // 0x80007774: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_3:
    // 0x80007778: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8000777C: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80007780: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80007784: jal         0x80024D20
    // 0x80007788: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_4;
    // 0x80007788: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_4:
    // 0x8000778C: jal         0x80023000
    // 0x80007790: nop

    osGetTime_recomp(rdram, ctx);
        goto after_5;
    // 0x80007790: nop

    after_5:
    // 0x80007794: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80007798: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8000779C: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x800077A0: bne         $at, $zero, L_800077E8
    if (ctx->r1 != 0) {
        // 0x800077A4: sltu        $at, $v0, $t8
        ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
            goto L_800077E8;
    }
    // 0x800077A4: sltu        $at, $v0, $t8
    ctx->r1 = ctx->r2 < ctx->r24 ? 1 : 0;
    // 0x800077A8: bne         $at, $zero, L_800077B8
    if (ctx->r1 != 0) {
        // 0x800077AC: sltu        $at, $v1, $t9
        ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
            goto L_800077B8;
    }
    // 0x800077AC: sltu        $at, $v1, $t9
    ctx->r1 = ctx->r3 < ctx->r25 ? 1 : 0;
    // 0x800077B0: beql        $at, $zero, L_800077EC
    if (ctx->r1 == 0) {
        // 0x800077B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800077EC;
    }
    goto skip_0;
    // 0x800077B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800077B8:
    // 0x800077B8: jal         0x80023000
    // 0x800077BC: nop

    osGetTime_recomp(rdram, ctx);
        goto after_6;
    // 0x800077BC: nop

    after_6:
    // 0x800077C0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800077C4: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800077C8: sltu        $at, $v0, $t0
    ctx->r1 = ctx->r2 < ctx->r8 ? 1 : 0;
    // 0x800077CC: bne         $at, $zero, L_800077B8
    if (ctx->r1 != 0) {
        // 0x800077D0: nop
    
            goto L_800077B8;
    }
    // 0x800077D0: nop

    // 0x800077D4: sltu        $at, $t0, $v0
    ctx->r1 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800077D8: bne         $at, $zero, L_800077E8
    if (ctx->r1 != 0) {
        // 0x800077DC: sltu        $at, $v1, $t1
        ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
            goto L_800077E8;
    }
    // 0x800077DC: sltu        $at, $v1, $t1
    ctx->r1 = ctx->r3 < ctx->r9 ? 1 : 0;
    // 0x800077E0: bne         $at, $zero, L_800077B8
    if (ctx->r1 != 0) {
        // 0x800077E4: nop
    
            goto L_800077B8;
    }
    // 0x800077E4: nop

L_800077E8:
    // 0x800077E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800077EC:
    // 0x800077EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800077F0: jr          $ra
    // 0x800077F4: nop

    return;
    // 0x800077F4: nop

;}
RECOMP_FUNC void Background_DrawBackdrop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E1E8: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x8003E1EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003E1F0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003E1F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003E1F8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003E1FC: lbu         $t6, 0x7AB0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7AB0);
    // 0x8003E200: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8003E204: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003E208: beq         $t6, $zero, L_8004043C
    if (ctx->r14 == 0) {
        // 0x8003E20C: addiu       $s1, $s1, -0x4C40
        ctx->r17 = ADD32(ctx->r17, -0X4C40);
            goto L_8004043C;
    }
    // 0x8003E20C: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x8003E210: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8003E214: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8003E218: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8003E21C: bne         $a1, $at, L_8003E23C
    if (ctx->r5 != ctx->r1) {
        // 0x8003E220: lbu         $s0, 0x7C98($s0)
        ctx->r16 = MEM_BU(ctx->r16, 0X7C98);
            goto L_8003E23C;
    }
    // 0x8003E220: lbu         $s0, 0x7C98($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0X7C98);
    // 0x8003E224: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003E228: lw          $t7, 0x789C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X789C);
    // 0x8003E22C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003E230: bnel        $t7, $at, L_8003E240
    if (ctx->r15 != ctx->r1) {
        // 0x8003E234: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8003E240;
    }
    goto skip_0;
    // 0x8003E234: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    skip_0:
    // 0x8003E238: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8003E23C:
    // 0x8003E23C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_8003E240:
    // 0x8003E240: bne         $a1, $at, L_8003E24C
    if (ctx->r5 != ctx->r1) {
        // 0x8003E244: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8003E24C;
    }
    // 0x8003E244: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003E248: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8003E24C:
    // 0x8003E24C: jal         0x80005708
    // 0x8003E250: sw          $a1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r5;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8003E250: sw          $a1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003E254: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003E258: lw          $t8, 0x7C70($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7C70);
    // 0x8003E25C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003E260: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003E264: bne         $t8, $at, L_8003E288
    if (ctx->r24 != ctx->r1) {
        // 0x8003E268: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8003E288;
    }
    // 0x8003E268: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E26C: lwc1        $f0, 0x5390($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5390);
    // 0x8003E270: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003E274: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003E278: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003E27C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003E280: jal         0x80005C34
    // 0x8003E284: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8003E284: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_1:
L_8003E288:
    // 0x8003E288: beq         $s0, $zero, L_8003E2A4
    if (ctx->r16 == 0) {
        // 0x8003E28C: addiu       $a1, $zero, 0x11
        ctx->r5 = ADD32(0, 0X11);
            goto L_8003E2A4;
    }
    // 0x8003E28C: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x8003E290: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003E294: beq         $s0, $at, L_8003F590
    if (ctx->r16 == ctx->r1) {
        // 0x8003E298: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_8003F590;
    }
    // 0x8003E298: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003E29C: b           L_80040434
    // 0x8003E2A0: nop

        goto L_80040434;
    // 0x8003E2A0: nop

L_8003E2A4:
    // 0x8003E2A4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003E2A8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003E2AC: jal         0x800B8DD0
    // 0x8003E2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8003E2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8003E2B4: lw          $t1, 0x11C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X11C);
    // 0x8003E2B8: sltiu       $at, $t1, 0x15
    ctx->r1 = ctx->r9 < 0X15 ? 1 : 0;
    // 0x8003E2BC: beq         $at, $zero, L_80040434
    if (ctx->r1 == 0) {
        // 0x8003E2C0: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_80040434;
    }
    // 0x8003E2C0: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8003E2C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E2C8: addu        $at, $at, $t1
    gpr jr_addend_8003E2D0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8003E2CC: lw          $t1, 0x5394($at)
    ctx->r9 = ADD32(ctx->r1, 0X5394);
    // 0x8003E2D0: jr          $t1
    // 0x8003E2D4: nop

    switch (jr_addend_8003E2D0 >> 2) {
        case 0: goto L_8003E6C4; break;
        case 1: goto L_80040434; break;
        case 2: goto L_80040434; break;
        case 3: goto L_80040434; break;
        case 4: goto L_80040434; break;
        case 5: goto L_80040434; break;
        case 6: goto L_8003E6C4; break;
        case 7: goto L_8003F0B4; break;
        case 8: goto L_8003F0B4; break;
        case 9: goto L_8003E8C8; break;
        case 10: goto L_80040434; break;
        case 11: goto L_8003F0B4; break;
        case 12: goto L_8003F0B4; break;
        case 13: goto L_8003EE1C; break;
        case 14: goto L_8003E2D8; break;
        case 15: goto L_80040434; break;
        case 16: goto L_8003E2D8; break;
        case 17: goto L_80040434; break;
        case 18: goto L_80040434; break;
        case 19: goto L_8003E2D8; break;
        case 20: goto L_8003E2D8; break;
        default: switch_error(__func__, 0x8003E2D0, 0x800D5394);
    }
    // 0x8003E2D4: nop

L_8003E2D8:
    // 0x8003E2D8: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8003E2DC: lw          $t3, 0x78A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78A0);
    // 0x8003E2E0: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8003E2E4: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8003E2E8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003E2EC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8003E2F0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003E2F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E2F8: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8003E2FC: lwc1        $f0, 0x53E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X53E8);
    // 0x8003E300: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8003E304: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E308: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x8003E30C: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8003E310: lwc1        $f6, 0x53EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X53EC);
    // 0x8003E314: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8003E318: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003E31C: nop

    // 0x8003E320: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003E324: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003E328: swc1        $f4, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f4.u32l;
    // 0x8003E32C: jal         0x8009F768
    // 0x8003E330: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    Math_RadToDeg(rdram, ctx);
        goto after_3;
    // 0x8003E330: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    after_3:
    // 0x8003E334: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E338: lwc1        $f6, 0x53F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X53F0);
    // 0x8003E33C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003E340: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003E344: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003E348: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E34C: lwc1        $f14, 0x53F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X53F4);
    // 0x8003E350: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003E354: jal         0x80004E20
    // 0x8003E358: nop

    Math_ModF(rdram, ctx);
        goto after_4;
    // 0x8003E358: nop

    after_4:
    // 0x8003E35C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003E360: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x8003E364: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8003E368: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8003E36C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8003E370: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8003E374: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8003E378: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8003E37C: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8003E380: swc1        $f0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f0.u32l;
    // 0x8003E384: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E388: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8003E38C: lwc1        $f18, 0x34($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X34);
    // 0x8003E390: lwc1        $f4, 0x53F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X53F8);
    // 0x8003E394: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E398: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003E39C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003E3A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003E3A4: jal         0x80005FE0
    // 0x8003E3A8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_5;
    // 0x8003E3A8: nop

    after_5:
    // 0x8003E3AC: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x8003E3B0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E3B4: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003E3B8: lui         $a3, 0xC5BB
    ctx->r7 = S32(0XC5BB << 16);
    // 0x8003E3BC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003E3C0: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8003E3C4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003E3C8: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8003E3CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E3D0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8003E3D4: jal         0x80005B00
    // 0x8003E3D8: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x8003E3D8: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    after_6:
    // 0x8003E3DC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003E3E0: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8003E3E4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8003E3E8: lui         $a2, 0xC4FA
    ctx->r6 = S32(0XC4FA << 16);
    // 0x8003E3EC: bne         $a1, $at, L_8003E410
    if (ctx->r5 != ctx->r1) {
        // 0x8003E3F0: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_8003E410;
    }
    // 0x8003E3F0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8003E3F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003E3F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003E3FC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E400: jal         0x80005B00
    // 0x8003E404: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_7;
    // 0x8003E404: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_7:
    // 0x8003E408: b           L_8003E438
    // 0x8003E40C: nop

        goto L_8003E438;
    // 0x8003E40C: nop

L_8003E410:
    // 0x8003E410: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8003E414: bne         $a1, $at, L_8003E438
    if (ctx->r5 != ctx->r1) {
        // 0x8003E418: lui         $a2, 0xC51C
        ctx->r6 = S32(0XC51C << 16);
            goto L_8003E438;
    }
    // 0x8003E418: lui         $a2, 0xC51C
    ctx->r6 = S32(0XC51C << 16);
    // 0x8003E41C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003E420: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003E424: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E428: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003E42C: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x8003E430: jal         0x80005B00
    // 0x8003E434: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_8;
    // 0x8003E434: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_8:
L_8003E438:
    // 0x8003E438: jal         0x80006EB8
    // 0x8003E43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x8003E43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8003E440: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003E444: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8003E448: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8003E44C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003E450: beq         $v0, $at, L_8003E508
    if (ctx->r2 == ctx->r1) {
        // 0x8003E454: lui         $a1, 0x45E3
        ctx->r5 = S32(0X45E3 << 16);
            goto L_8003E508;
    }
    // 0x8003E454: lui         $a1, 0x45E3
    ctx->r5 = S32(0X45E3 << 16);
    // 0x8003E458: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8003E45C: beq         $v0, $at, L_8003E530
    if (ctx->r2 == ctx->r1) {
        // 0x8003E460: lui         $t7, 0x600
        ctx->r15 = S32(0X600 << 16);
            goto L_8003E530;
    }
    // 0x8003E460: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003E464: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8003E468: beq         $v0, $at, L_8003E554
    if (ctx->r2 == ctx->r1) {
        // 0x8003E46C: lui         $t1, 0x600
        ctx->r9 = S32(0X600 << 16);
            goto L_8003E554;
    }
    // 0x8003E46C: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8003E470: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8003E474: bne         $v0, $at, L_8003E570
    if (ctx->r2 != ctx->r1) {
        // 0x8003E478: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_8003E570;
    }
    // 0x8003E478: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003E47C: lw          $v0, 0x789C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X789C);
    // 0x8003E480: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003E484: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003E488: bne         $v0, $zero, L_8003E4B4
    if (ctx->r2 != 0) {
        // 0x8003E48C: nop
    
            goto L_8003E4B4;
    }
    // 0x8003E48C: nop

    // 0x8003E490: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E494: lui         $t6, 0x303
    ctx->r14 = S32(0X303 << 16);
    // 0x8003E498: addiu       $t6, $t6, -0x2B30
    ctx->r14 = ADD32(ctx->r14, -0X2B30);
    // 0x8003E49C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8003E4A0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003E4A4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8003E4A8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8003E4AC: b           L_8003E574
    // 0x8003E4B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
        goto L_8003E574;
    // 0x8003E4B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_8003E4B4:
    // 0x8003E4B4: bne         $v0, $at, L_8003E4E4
    if (ctx->r2 != ctx->r1) {
        // 0x8003E4B8: lui         $t1, 0x600
        ctx->r9 = S32(0X600 << 16);
            goto L_8003E4E4;
    }
    // 0x8003E4B8: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8003E4BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E4C0: lui         $t8, 0x301
    ctx->r24 = S32(0X301 << 16);
    // 0x8003E4C4: addiu       $t8, $t8, 0x46B0
    ctx->r24 = ADD32(ctx->r24, 0X46B0);
    // 0x8003E4C8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8003E4CC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003E4D0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003E4D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8003E4D8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8003E4DC: b           L_8003E574
    // 0x8003E4E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
        goto L_8003E574;
    // 0x8003E4E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_8003E4E4:
    // 0x8003E4E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E4E8: lui         $t3, 0x301
    ctx->r11 = S32(0X301 << 16);
    // 0x8003E4EC: addiu       $t3, $t3, 0x1E40
    ctx->r11 = ADD32(ctx->r11, 0X1E40);
    // 0x8003E4F0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8003E4F4: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003E4F8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8003E4FC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8003E500: b           L_8003E574
    // 0x8003E504: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
        goto L_8003E574;
    // 0x8003E504: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_8003E508:
    // 0x8003E508: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E50C: lui         $t6, 0x601
    ctx->r14 = S32(0X601 << 16);
    // 0x8003E510: addiu       $t6, $t6, -0x2610
    ctx->r14 = ADD32(ctx->r14, -0X2610);
    // 0x8003E514: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8003E518: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003E51C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003E520: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8003E524: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8003E528: b           L_8003E574
    // 0x8003E52C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
        goto L_8003E574;
    // 0x8003E52C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_8003E530:
    // 0x8003E530: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E534: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x8003E538: addiu       $t8, $t8, -0xE30
    ctx->r24 = ADD32(ctx->r24, -0XE30);
    // 0x8003E53C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8003E540: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003E544: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8003E548: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8003E54C: b           L_8003E574
    // 0x8003E550: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
        goto L_8003E574;
    // 0x8003E550: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_8003E554:
    // 0x8003E554: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E558: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x8003E55C: addiu       $t3, $t3, -0x990
    ctx->r11 = ADD32(ctx->r11, -0X990);
    // 0x8003E560: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8003E564: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003E568: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8003E56C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8003E570:
    // 0x8003E570: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_8003E574:
    // 0x8003E574: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003E578: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003E57C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003E580: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E584: jal         0x80005B00
    // 0x8003E588: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x8003E588: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    after_10:
    // 0x8003E58C: jal         0x80006EB8
    // 0x8003E590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x8003E590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8003E594: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003E598: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8003E59C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8003E5A0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003E5A4: beq         $v0, $at, L_8003E658
    if (ctx->r2 == ctx->r1) {
        // 0x8003E5A8: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_8003E658;
    }
    // 0x8003E5A8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8003E5AC: beq         $v0, $at, L_8003E67C
    if (ctx->r2 == ctx->r1) {
        // 0x8003E5B0: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_8003E67C;
    }
    // 0x8003E5B0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003E5B4: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8003E5B8: beq         $v0, $at, L_8003E6A0
    if (ctx->r2 == ctx->r1) {
        // 0x8003E5BC: lui         $t3, 0x600
        ctx->r11 = S32(0X600 << 16);
            goto L_8003E6A0;
    }
    // 0x8003E5BC: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8003E5C0: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8003E5C4: bne         $v0, $at, L_80040434
    if (ctx->r2 != ctx->r1) {
        // 0x8003E5C8: lui         $v0, 0x8017
        ctx->r2 = S32(0X8017 << 16);
            goto L_80040434;
    }
    // 0x8003E5C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003E5CC: lw          $v0, 0x789C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X789C);
    // 0x8003E5D0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003E5D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003E5D8: bne         $v0, $zero, L_8003E604
    if (ctx->r2 != 0) {
        // 0x8003E5DC: nop
    
            goto L_8003E604;
    }
    // 0x8003E5DC: nop

    // 0x8003E5E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E5E4: lui         $t5, 0x303
    ctx->r13 = S32(0X303 << 16);
    // 0x8003E5E8: addiu       $t5, $t5, -0x2B30
    ctx->r13 = ADD32(ctx->r13, -0X2B30);
    // 0x8003E5EC: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003E5F0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003E5F4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8003E5F8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8003E5FC: b           L_80040434
    // 0x8003E600: nop

        goto L_80040434;
    // 0x8003E600: nop

L_8003E604:
    // 0x8003E604: bne         $v0, $at, L_8003E634
    if (ctx->r2 != ctx->r1) {
        // 0x8003E608: lui         $t3, 0x600
        ctx->r11 = S32(0X600 << 16);
            goto L_8003E634;
    }
    // 0x8003E608: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8003E60C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E610: lui         $t9, 0x301
    ctx->r25 = S32(0X301 << 16);
    // 0x8003E614: addiu       $t9, $t9, 0x46B0
    ctx->r25 = ADD32(ctx->r25, 0X46B0);
    // 0x8003E618: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8003E61C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003E620: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003E624: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003E628: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8003E62C: b           L_80040434
    // 0x8003E630: nop

        goto L_80040434;
    // 0x8003E630: nop

L_8003E634:
    // 0x8003E634: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E638: lui         $t2, 0x301
    ctx->r10 = S32(0X301 << 16);
    // 0x8003E63C: addiu       $t2, $t2, 0x1E40
    ctx->r10 = ADD32(ctx->r10, 0X1E40);
    // 0x8003E640: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8003E644: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003E648: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8003E64C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8003E650: b           L_80040434
    // 0x8003E654: nop

        goto L_80040434;
    // 0x8003E654: nop

L_8003E658:
    // 0x8003E658: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E65C: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x8003E660: addiu       $t5, $t5, -0x2610
    ctx->r13 = ADD32(ctx->r13, -0X2610);
    // 0x8003E664: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003E668: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003E66C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8003E670: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8003E674: b           L_80040434
    // 0x8003E678: nop

        goto L_80040434;
    // 0x8003E678: nop

L_8003E67C:
    // 0x8003E67C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E680: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x8003E684: addiu       $t9, $t9, -0xE30
    ctx->r25 = ADD32(ctx->r25, -0XE30);
    // 0x8003E688: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8003E68C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003E690: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8003E694: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003E698: b           L_80040434
    // 0x8003E69C: nop

        goto L_80040434;
    // 0x8003E69C: nop

L_8003E6A0:
    // 0x8003E6A0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E6A4: lui         $t2, 0x601
    ctx->r10 = S32(0X601 << 16);
    // 0x8003E6A8: addiu       $t2, $t2, -0x990
    ctx->r10 = ADD32(ctx->r10, -0X990);
    // 0x8003E6AC: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8003E6B0: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003E6B4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8003E6B8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8003E6BC: b           L_80040434
    // 0x8003E6C0: nop

        goto L_80040434;
    // 0x8003E6C0: nop

L_8003E6C4:
    // 0x8003E6C4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003E6C8: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x8003E6CC: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003E6D0: lw          $t4, -0x7D80($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D80);
    // 0x8003E6D4: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8003E6D8: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x8003E6DC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8003E6E0: subu        $t5, $t5, $t6
    ctx->r13 = SUB32(ctx->r13, ctx->r14);
    // 0x8003E6E4: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8003E6E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E6EC: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8003E6F0: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8003E6F4: lwc1        $f6, 0x53FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X53FC);
    // 0x8003E6F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E6FC: lwc1        $f18, 0x5400($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5400);
    // 0x8003E700: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003E704: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8003E708: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8003E70C: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8003E710: swc1        $f6, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f6.u32l;
    // 0x8003E714: jal         0x8009F768
    // 0x8003E718: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    Math_RadToDeg(rdram, ctx);
        goto after_12;
    // 0x8003E718: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    after_12:
    // 0x8003E71C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E720: lwc1        $f8, 0x5404($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5404);
    // 0x8003E724: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003E728: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003E72C: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003E730: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E734: lwc1        $f14, 0x5408($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5408);
    // 0x8003E738: mul.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8003E73C: jal         0x80004E20
    // 0x8003E740: nop

    Math_ModF(rdram, ctx);
        goto after_13;
    // 0x8003E740: nop

    after_13:
    // 0x8003E744: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003E748: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x8003E74C: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8003E750: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8003E754: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003E758: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8003E75C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003E760: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8003E764: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8003E768: swc1        $f0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f0.u32l;
    // 0x8003E76C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E770: addu        $t1, $t7, $t9
    ctx->r9 = ADD32(ctx->r15, ctx->r25);
    // 0x8003E774: lwc1        $f4, 0x34($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8003E778: lwc1        $f6, 0x540C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X540C);
    // 0x8003E77C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003E784: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003E788: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8003E78C: jal         0x80005FE0
    // 0x8003E790: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_14;
    // 0x8003E790: nop

    after_14:
    // 0x8003E794: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x8003E798: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003E79C: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003E7A0: lui         $a3, 0xC5BB
    ctx->r7 = S32(0XC5BB << 16);
    // 0x8003E7A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003E7A8: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8003E7AC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003E7B0: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8003E7B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E7B8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003E7BC: jal         0x80005B00
    // 0x8003E7C0: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    Matrix_Translate(rdram, ctx);
        goto after_15;
    // 0x8003E7C0: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    after_15:
    // 0x8003E7C4: jal         0x80006EB8
    // 0x8003E7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_16;
    // 0x8003E7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8003E7CC: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003E7D0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8003E7D4: lui         $a1, 0x45E3
    ctx->r5 = S32(0X45E3 << 16);
    // 0x8003E7D8: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8003E7DC: beq         $v0, $zero, L_8003E7F8
    if (ctx->r2 == 0) {
        // 0x8003E7E0: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_8003E7F8;
    }
    // 0x8003E7E0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003E7E4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003E7E8: beq         $v0, $at, L_8003E820
    if (ctx->r2 == ctx->r1) {
        // 0x8003E7EC: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_8003E820;
    }
    // 0x8003E7EC: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003E7F0: b           L_8003E840
    // 0x8003E7F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
        goto L_8003E840;
    // 0x8003E7F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8003E7F8:
    // 0x8003E7F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E7FC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003E800: addiu       $t4, $t4, 0x59F0
    ctx->r12 = ADD32(ctx->r12, 0X59F0);
    // 0x8003E804: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8003E808: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003E80C: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003E810: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8003E814: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8003E818: b           L_8003E840
    // 0x8003E81C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
        goto L_8003E840;
    // 0x8003E81C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8003E820:
    // 0x8003E820: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E824: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003E828: addiu       $t7, $t7, 0x46F0
    ctx->r15 = ADD32(ctx->r15, 0X46F0);
    // 0x8003E82C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8003E830: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003E834: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8003E838: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003E83C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8003E840:
    // 0x8003E840: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003E844: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E848: jal         0x80005B00
    // 0x8003E84C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_17;
    // 0x8003E84C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_17:
    // 0x8003E850: jal         0x80006EB8
    // 0x8003E854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_18;
    // 0x8003E854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8003E858: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003E85C: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8003E860: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003E864: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8003E868: beql        $v0, $zero, L_8003E884
    if (ctx->r2 == 0) {
        // 0x8003E86C: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8003E884;
    }
    goto skip_1;
    // 0x8003E86C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x8003E870: beq         $v0, $at, L_8003E8A4
    if (ctx->r2 == ctx->r1) {
        // 0x8003E874: lui         $t4, 0x600
        ctx->r12 = S32(0X600 << 16);
            goto L_8003E8A4;
    }
    // 0x8003E874: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003E878: b           L_80040434
    // 0x8003E87C: nop

        goto L_80040434;
    // 0x8003E87C: nop

    // 0x8003E880: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8003E884:
    // 0x8003E884: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8003E888: addiu       $t2, $t2, 0x59F0
    ctx->r10 = ADD32(ctx->r10, 0X59F0);
    // 0x8003E88C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8003E890: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003E894: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8003E898: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8003E89C: b           L_80040434
    // 0x8003E8A0: nop

        goto L_80040434;
    // 0x8003E8A0: nop

L_8003E8A4:
    // 0x8003E8A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E8A8: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8003E8AC: addiu       $t5, $t5, 0x46F0
    ctx->r13 = ADD32(ctx->r13, 0X46F0);
    // 0x8003E8B0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8003E8B4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003E8B8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8003E8BC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8003E8C0: b           L_80040434
    // 0x8003E8C4: nop

        goto L_80040434;
    // 0x8003E8C4: nop

L_8003E8C8:
    // 0x8003E8C8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8003E8CC: lbu         $v0, 0x7AB0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7AB0);
    // 0x8003E8D0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003E8D4: beq         $v0, $at, L_80040434
    if (ctx->r2 == ctx->r1) {
        // 0x8003E8D8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80040434;
    }
    // 0x8003E8D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003E8DC: beq         $v0, $at, L_8003E8EC
    if (ctx->r2 == ctx->r1) {
        // 0x8003E8E0: lui         $t8, 0x8018
        ctx->r24 = S32(0X8018 << 16);
            goto L_8003E8EC;
    }
    // 0x8003E8E0: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8003E8E4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003E8E8: bne         $v0, $at, L_8003E984
    if (ctx->r2 != ctx->r1) {
        // 0x8003E8EC: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8003E984;
    }
L_8003E8EC:
    // 0x8003E8EC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003E8F0: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x8003E8F4: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8003E8F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003E8FC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8003E900: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8003E904: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003E908: subu        $t9, $t9, $t7
    ctx->r25 = SUB32(ctx->r25, ctx->r15);
    // 0x8003E90C: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8003E910: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8003E914: lwc1        $f6, 0x34($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8003E918: lwc1        $f8, 0x5410($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5410);
    // 0x8003E91C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E920: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003E924: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003E928: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8003E92C: jal         0x80005FE0
    // 0x8003E930: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_19;
    // 0x8003E930: nop

    after_19:
    // 0x8003E934: lui         $a3, 0xC5DA
    ctx->r7 = S32(0XC5DA << 16);
    // 0x8003E938: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003E93C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003E940: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x8003E944: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003E948: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003E94C: jal         0x80005B00
    // 0x8003E950: lui         $a2, 0xC57A
    ctx->r6 = S32(0XC57A << 16);
    Matrix_Translate(rdram, ctx);
        goto after_20;
    // 0x8003E950: lui         $a2, 0xC57A
    ctx->r6 = S32(0XC57A << 16);
    after_20:
    // 0x8003E954: jal         0x80006EB8
    // 0x8003E958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_21;
    // 0x8003E958: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
    // 0x8003E95C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003E960: lui         $t4, 0x601
    ctx->r12 = S32(0X601 << 16);
    // 0x8003E964: addiu       $t4, $t4, -0x990
    ctx->r12 = ADD32(ctx->r12, -0X990);
    // 0x8003E968: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8003E96C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003E970: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003E974: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8003E978: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8003E97C: b           L_80040434
    // 0x8003E980: nop

        goto L_80040434;
    // 0x8003E980: nop

L_8003E984:
    // 0x8003E984: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003E988: beq         $v0, $at, L_8003E99C
    if (ctx->r2 == ctx->r1) {
        // 0x8003E98C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003E99C;
    }
    // 0x8003E98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003E990: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003E994: bnel        $v0, $at, L_8003EC24
    if (ctx->r2 != ctx->r1) {
        // 0x8003E998: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003EC24;
    }
    goto skip_2;
    // 0x8003E998: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
L_8003E99C:
    // 0x8003E99C: jal         0x800B8DD0
    // 0x8003E9A0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_22;
    // 0x8003E9A0: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_22:
    // 0x8003E9A4: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8003E9A8: lbu         $t5, 0x7AB0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7AB0);
    // 0x8003E9AC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003E9B0: bne         $t5, $at, L_8003EA14
    if (ctx->r13 != ctx->r1) {
        // 0x8003E9B4: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8003EA14;
    }
    // 0x8003E9B4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003E9B8: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8003E9BC: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8003E9C0: addiu       $a0, $a0, 0x1394
    ctx->r4 = ADD32(ctx->r4, 0X1394);
    // 0x8003E9C4: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8003E9C8: bne         $t8, $zero, L_8003E9F8
    if (ctx->r24 != 0) {
        // 0x8003E9CC: lui         $a1, 0x42F0
        ctx->r5 = S32(0X42F0 << 16);
            goto L_8003E9F8;
    }
    // 0x8003E9CC: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x8003E9D0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003E9D4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8003E9D8: addiu       $a0, $a0, 0x1394
    ctx->r4 = ADD32(ctx->r4, 0X1394);
    // 0x8003E9DC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003E9E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003E9E4: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8003E9E8: jal         0x8009BC2C
    // 0x8003E9EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_23;
    // 0x8003E9EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_23:
    // 0x8003E9F0: b           L_8003EA24
    // 0x8003E9F4: nop

        goto L_8003EA24;
    // 0x8003E9F4: nop

L_8003E9F8:
    // 0x8003E9F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003E9FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003EA00: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8003EA04: jal         0x8009BC2C
    // 0x8003EA08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_24;
    // 0x8003EA08: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_24:
    // 0x8003EA0C: b           L_8003EA24
    // 0x8003EA10: nop

        goto L_8003EA24;
    // 0x8003EA10: nop

L_8003EA14:
    // 0x8003EA14: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8003EA18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003EA1C: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003EA20: swc1        $f6, 0x1394($at)
    MEM_W(0X1394, ctx->r1) = ctx->f6.u32l;
L_8003EA24:
    // 0x8003EA24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EA28: lwc1        $f0, 0x5414($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5414);
    // 0x8003EA2C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003EA30: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8003EA34: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003EA38: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8003EA3C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003EA40: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8003EA44: lwc1        $f8, 0x1394($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1394);
    // 0x8003EA48: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8003EA4C: trunc.w.s   $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8003EA50: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8003EA54: nop

    // 0x8003EA58: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x8003EA5C: sll         $t6, $t2, 16
    ctx->r14 = S32(ctx->r10 << 16);
    // 0x8003EA60: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x8003EA64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EA68: lwc1        $f10, -0x63D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X63D0);
    // 0x8003EA6C: sll         $t5, $t2, 8
    ctx->r13 = S32(ctx->r10 << 8);
    // 0x8003EA70: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x8003EA74: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8003EA78: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8003EA7C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EA80: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003EA84: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8003EA88: nop

    // 0x8003EA8C: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8003EA90: or          $t3, $t7, $t1
    ctx->r11 = ctx->r15 | ctx->r9;
    // 0x8003EA94: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8003EA98: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x8003EA9C: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8003EAA0: lwc1        $f8, 0x5418($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5418);
    // 0x8003EAA4: sll         $t4, $t6, 2
    ctx->r12 = S32(ctx->r14 << 2);
    // 0x8003EAA8: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8003EAAC: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003EAB0: subu        $t4, $t4, $t6
    ctx->r12 = SUB32(ctx->r12, ctx->r14);
    // 0x8003EAB4: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8003EAB8: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x8003EABC: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8003EAC0: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8003EAC4: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003EAC8: nop

    // 0x8003EACC: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003EAD0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003EAD4: swc1        $f6, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f6.u32l;
    // 0x8003EAD8: jal         0x8009F768
    // 0x8003EADC: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    Math_RadToDeg(rdram, ctx);
        goto after_25;
    // 0x8003EADC: lwc1        $f12, 0x58($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X58);
    after_25:
    // 0x8003EAE0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EAE4: lwc1        $f8, 0x541C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X541C);
    // 0x8003EAE8: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003EAEC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003EAF0: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003EAF4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EAF8: lwc1        $f14, 0x5420($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5420);
    // 0x8003EAFC: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8003EB00: jal         0x80004E20
    // 0x8003EB04: nop

    Math_ModF(rdram, ctx);
        goto after_26;
    // 0x8003EB04: nop

    after_26:
    // 0x8003EB08: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003EB0C: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x8003EB10: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8003EB14: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8003EB18: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8003EB1C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8003EB20: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8003EB24: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8003EB28: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8003EB2C: swc1        $f0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f0.u32l;
    // 0x8003EB30: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EB34: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x8003EB38: lwc1        $f4, 0x34($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X34);
    // 0x8003EB3C: lwc1        $f6, 0x5424($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5424);
    // 0x8003EB40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003EB44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003EB48: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003EB4C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8003EB50: jal         0x80005FE0
    // 0x8003EB54: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_27;
    // 0x8003EB54: nop

    after_27:
    // 0x8003EB58: lui         $at, 0xC4FA
    ctx->r1 = S32(0XC4FA << 16);
    // 0x8003EB5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003EB60: lwc1        $f18, 0x134($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003EB64: lui         $a3, 0xC5BB
    ctx->r7 = S32(0XC5BB << 16);
    // 0x8003EB68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003EB6C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8003EB70: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003EB74: ori         $a3, $a3, 0x8000
    ctx->r7 = ctx->r7 | 0X8000;
    // 0x8003EB78: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003EB7C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003EB80: jal         0x80005B00
    // 0x8003EB84: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    Matrix_Translate(rdram, ctx);
        goto after_28;
    // 0x8003EB84: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    after_28:
    // 0x8003EB88: lui         $a2, 0xC51C
    ctx->r6 = S32(0XC51C << 16);
    // 0x8003EB8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003EB90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003EB94: ori         $a2, $a2, 0x4000
    ctx->r6 = ctx->r6 | 0X4000;
    // 0x8003EB98: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003EB9C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003EBA0: jal         0x80005B00
    // 0x8003EBA4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_29;
    // 0x8003EBA4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_29:
    // 0x8003EBA8: jal         0x80006EB8
    // 0x8003EBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_30;
    // 0x8003EBAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_30:
    // 0x8003EBB0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003EBB4: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8003EBB8: addiu       $t0, $t0, 0x38E0
    ctx->r8 = ADD32(ctx->r8, 0X38E0);
    // 0x8003EBBC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8003EBC0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003EBC4: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8003EBC8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8003EBCC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8003EBD0: lui         $a1, 0x45E3
    ctx->r5 = S32(0X45E3 << 16);
    // 0x8003EBD4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003EBD8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003EBDC: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x8003EBE0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003EBE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003EBE8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8003EBEC: jal         0x80005B00
    // 0x8003EBF0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    Matrix_Translate(rdram, ctx);
        goto after_31;
    // 0x8003EBF0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_31:
    // 0x8003EBF4: jal         0x80006EB8
    // 0x8003EBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_32;
    // 0x8003EBF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x8003EBFC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003EC00: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8003EC04: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8003EC08: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003EC0C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8003EC10: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8003EC14: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8003EC18: b           L_80040434
    // 0x8003EC1C: nop

        goto L_80040434;
    // 0x8003EC1C: nop

    // 0x8003EC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8003EC24:
    // 0x8003EC24: jal         0x800B8DD0
    // 0x8003EC28: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_33;
    // 0x8003EC28: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_33:
    // 0x8003EC2C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003EC30: lbu         $t7, 0x7AB0($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X7AB0);
    // 0x8003EC34: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003EC38: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8003EC3C: bne         $t7, $at, L_8003EC68
    if (ctx->r15 != ctx->r1) {
        // 0x8003EC40: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_8003EC68;
    }
    // 0x8003EC40: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003EC44: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003EC48: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8003EC4C: addiu       $t6, $zero, -0xC0
    ctx->r14 = ADD32(0, -0XC0);
    // 0x8003EC50: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8003EC54: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003EC58: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8003EC5C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8003EC60: b           L_8003ECA8
    // 0x8003EC64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8003ECA8;
    // 0x8003EC64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8003EC68:
    // 0x8003EC68: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003EC6C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8003EC70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EC74: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8003EC78: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003EC7C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8003EC80: lwc1        $f6, -0x63D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X63D0);
    // 0x8003EC84: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8003EC88: ori         $at, $at, 0x8000
    ctx->r1 = ctx->r1 | 0X8000;
    // 0x8003EC8C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8003EC90: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x8003EC94: nop

    // 0x8003EC98: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x8003EC9C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x8003ECA0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8003ECA4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8003ECA8:
    // 0x8003ECA8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003ECAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003ECB0: jal         0x80005B00
    // 0x8003ECB4: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_34;
    // 0x8003ECB4: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    after_34:
    // 0x8003ECB8: jal         0x80005708
    // 0x8003ECBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_35;
    // 0x8003ECBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_35:
    // 0x8003ECC0: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8003ECC4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003ECC8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003ECCC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003ECD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003ECD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003ECD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003ECDC: jal         0x80005C34
    // 0x8003ECE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_36;
    // 0x8003ECE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_36:
    // 0x8003ECE4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8003ECE8: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8003ECEC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003ECF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003ECF4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8003ECF8: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x8003ECFC: lw          $t2, -0x7D80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7D80);
    // 0x8003ED00: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003ED04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003ED08: lwc1        $f8, 0x34($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8003ED0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003ED10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003ED14: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003ED18: lwc1        $f18, 0x5428($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5428);
    // 0x8003ED1C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8003ED20: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8003ED24: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003ED28: jal         0x80005FE0
    // 0x8003ED2C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_37;
    // 0x8003ED2C: nop

    after_37:
    // 0x8003ED30: jal         0x80006EB8
    // 0x8003ED34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_38;
    // 0x8003ED34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_38:
    // 0x8003ED38: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003ED3C: lui         $a1, 0xC04
    ctx->r5 = S32(0XC04 << 16);
    // 0x8003ED40: addiu       $a1, $a1, -0x6DF8
    ctx->r5 = ADD32(ctx->r5, -0X6DF8);
    // 0x8003ED44: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003ED48: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003ED4C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003ED50: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003ED54: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8003ED58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003ED5C: jal         0x80005740
    // 0x8003ED60: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    Matrix_Pop(rdram, ctx);
        goto after_39;
    // 0x8003ED60: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_39:
    // 0x8003ED64: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8003ED68: lbu         $t5, 0x7AB0($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X7AB0);
    // 0x8003ED6C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003ED70: beq         $t5, $at, L_80040434
    if (ctx->r13 == ctx->r1) {
        // 0x8003ED74: nop
    
            goto L_80040434;
    }
    // 0x8003ED74: nop

    // 0x8003ED78: jal         0x80005708
    // 0x8003ED7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_40;
    // 0x8003ED7C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_40:
    // 0x8003ED80: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003ED84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003ED88: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003ED8C: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8003ED90: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8003ED94: jal         0x80005C34
    // 0x8003ED98: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_41;
    // 0x8003ED98: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_41:
    // 0x8003ED9C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003EDA0: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x8003EDA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EDA8: lwc1        $f10, 0x542C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X542C);
    // 0x8003EDAC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8003EDB0: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003EDB4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8003EDB8: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003EDBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EDC0: lwc1        $f4, 0x34($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X34);
    // 0x8003EDC4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003EDC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003EDCC: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8003EDD0: lwc1        $f6, 0x5430($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5430);
    // 0x8003EDD4: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x8003EDD8: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8003EDDC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003EDE0: jal         0x80005FE0
    // 0x8003EDE4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_42;
    // 0x8003EDE4: nop

    after_42:
    // 0x8003EDE8: jal         0x80006EB8
    // 0x8003EDEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_43;
    // 0x8003EDEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_43:
    // 0x8003EDF0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003EDF4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003EDF8: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8003EDFC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003EE00: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8003EE04: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x8003EE08: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8003EE0C: jal         0x80005740
    // 0x8003EE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_44;
    // 0x8003EE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_44:
    // 0x8003EE14: b           L_80040434
    // 0x8003EE18: nop

        goto L_80040434;
    // 0x8003EE18: nop

L_8003EE1C:
    // 0x8003EE1C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8003EE20: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8003EE24: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003EE28: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003EE2C: lw          $t4, 0x1C8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1C8);
    // 0x8003EE30: bne         $t4, $at, L_80040434
    if (ctx->r12 != ctx->r1) {
        // 0x8003EE34: nop
    
            goto L_80040434;
    }
    // 0x8003EE34: nop

    // 0x8003EE38: lw          $t8, 0x78A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78A0);
    // 0x8003EE3C: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8003EE40: addu        $t5, $t5, $t8
    ctx->r13 = ADD32(ctx->r13, ctx->r24);
    // 0x8003EE44: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8003EE48: subu        $t5, $t5, $t8
    ctx->r13 = SUB32(ctx->r13, ctx->r24);
    // 0x8003EE4C: sll         $t5, $t5, 5
    ctx->r13 = S32(ctx->r13 << 5);
    // 0x8003EE50: addu        $t9, $v1, $t5
    ctx->r25 = ADD32(ctx->r3, ctx->r13);
    // 0x8003EE54: jal         0x8009F768
    // 0x8003EE58: lwc1        $f12, 0x58($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X58);
    Math_RadToDeg(rdram, ctx);
        goto after_45;
    // 0x8003EE58: lwc1        $f12, 0x58($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X58);
    after_45:
    // 0x8003EE5C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003EE60: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x8003EE64: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8003EE68: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8003EE6C: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8003EE70: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x8003EE74: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8003EE78: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x8003EE7C: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8003EE80: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x8003EE84: lwc1        $f4, 0x114($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X114);
    // 0x8003EE88: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EE8C: lwc1        $f8, 0x5434($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5434);
    // 0x8003EE90: lwc1        $f18, 0x5C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8003EE94: sub.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8003EE98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EE9C: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8003EEA0: lwc1        $f4, 0x5438($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5438);
    // 0x8003EEA4: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8003EEA8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EEAC: mul.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8003EEB0: lwc1        $f10, 0x543C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X543C);
    // 0x8003EEB4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EEB8: lwc1        $f14, 0x5440($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5440);
    // 0x8003EEBC: mul.s       $f2, $f16, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8003EEC0: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8003EEC4: add.s       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8003EEC8: jal         0x80004E20
    // 0x8003EECC: swc1        $f8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f8.u32l;
    Math_ModF(rdram, ctx);
        goto after_46;
    // 0x8003EECC: swc1        $f8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f8.u32l;
    after_46:
    // 0x8003EED0: jal         0x800B9328
    // 0x8003EED4: swc1        $f0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f0.u32l;
    RCP_SetupDL_17(rdram, ctx);
        goto after_47;
    // 0x8003EED4: swc1        $f0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f0.u32l;
    after_47:
    // 0x8003EED8: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8003EEDC: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x8003EEE0: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003EEE4: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8003EEE8: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8003EEEC: addu        $t4, $t4, $t2
    ctx->r12 = ADD32(ctx->r12, ctx->r10);
    // 0x8003EEF0: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8003EEF4: subu        $t4, $t4, $t2
    ctx->r12 = SUB32(ctx->r12, ctx->r10);
    // 0x8003EEF8: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8003EEFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003EF00: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x8003EF04: lwc1        $f4, 0x34($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X34);
    // 0x8003EF08: lwc1        $f6, 0x5444($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5444);
    // 0x8003EF0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003EF10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003EF14: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003EF18: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8003EF1C: jal         0x80005FE0
    // 0x8003EF20: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_48;
    // 0x8003EF20: nop

    after_48:
    // 0x8003EF24: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003EF28: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003EF2C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003EF30: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8003EF34: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003EF38: jal         0x80005C34
    // 0x8003EF3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_49;
    // 0x8003EF3C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_49:
    // 0x8003EF40: jal         0x80005708
    // 0x8003EF44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_50;
    // 0x8003EF44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_50:
    // 0x8003EF48: lui         $a3, 0xC5DA
    ctx->r7 = S32(0XC5DA << 16);
    // 0x8003EF4C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003EF50: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003EF54: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x8003EF58: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003EF5C: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    // 0x8003EF60: jal         0x80005B00
    // 0x8003EF64: lw          $a2, 0x134($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X134);
    Matrix_Translate(rdram, ctx);
        goto after_51;
    // 0x8003EF64: lw          $a2, 0x134($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X134);
    after_51:
    // 0x8003EF68: jal         0x80006EB8
    // 0x8003EF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_52;
    // 0x8003EF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_52:
    // 0x8003EF70: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003EF74: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8003EF78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003EF7C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003EF80: lw          $t7, 0x1C8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1C8);
    // 0x8003EF84: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8003EF88: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003EF8C: bnel        $t7, $at, L_8003EFBC
    if (ctx->r15 != ctx->r1) {
        // 0x8003EF90: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8003EFBC;
    }
    goto skip_3;
    // 0x8003EF90: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x8003EF94: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003EF98: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x8003EF9C: addiu       $t6, $t6, -0x5010
    ctx->r14 = ADD32(ctx->r14, -0X5010);
    // 0x8003EFA0: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8003EFA4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003EFA8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8003EFAC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8003EFB0: b           L_8003EFD8
    // 0x8003EFB4: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
        goto L_8003EFD8;
    // 0x8003EFB4: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x8003EFB8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8003EFBC:
    // 0x8003EFBC: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x8003EFC0: addiu       $t5, $t5, -0x3F80
    ctx->r13 = ADD32(ctx->r13, -0X3F80);
    // 0x8003EFC4: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003EFC8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003EFCC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8003EFD0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003EFD4: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
L_8003EFD8:
    // 0x8003EFD8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8003EFDC: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x8003EFE0: nop

    // 0x8003EFE4: bc1fl       L_8003F000
    if (!c1cs) {
        // 0x8003EFE8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8003F000;
    }
    goto skip_4;
    // 0x8003EFE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_4:
    // 0x8003EFEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003EFF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003EFF4: b           L_8003F008
    // 0x8003EFF8: swc1        $f4, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f4.u32l;
        goto L_8003F008;
    // 0x8003EFF8: swc1        $f4, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f4.u32l;
    // 0x8003EFFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8003F000:
    // 0x8003F000: nop

    // 0x8003F004: swc1        $f6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f6.u32l;
L_8003F008:
    // 0x8003F008: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F00C: lwc1        $f18, 0x5448($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5448);
    // 0x8003F010: lwc1        $f8, 0x13C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x8003F014: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003F018: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003F01C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8003F020: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003F024: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003F028: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003F02C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003F030: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003F034: jal         0x80005B00
    // 0x8003F038: nop

    Matrix_Translate(rdram, ctx);
        goto after_53;
    // 0x8003F038: nop

    after_53:
    // 0x8003F03C: jal         0x80006EB8
    // 0x8003F040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_54;
    // 0x8003F040: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_54:
    // 0x8003F044: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003F048: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8003F04C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F050: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8003F054: lw          $t7, 0x1C8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1C8);
    // 0x8003F058: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003F05C: bnel        $t7, $at, L_8003F08C
    if (ctx->r15 != ctx->r1) {
        // 0x8003F060: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_8003F08C;
    }
    goto skip_5;
    // 0x8003F060: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x8003F064: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F068: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x8003F06C: addiu       $t6, $t6, -0x5010
    ctx->r14 = ADD32(ctx->r14, -0X5010);
    // 0x8003F070: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8003F074: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003F078: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8003F07C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8003F080: b           L_8003F0A4
    // 0x8003F084: nop

        goto L_8003F0A4;
    // 0x8003F084: nop

    // 0x8003F088: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_8003F08C:
    // 0x8003F08C: lui         $t5, 0x602
    ctx->r13 = S32(0X602 << 16);
    // 0x8003F090: addiu       $t5, $t5, -0x3F80
    ctx->r13 = ADD32(ctx->r13, -0X3F80);
    // 0x8003F094: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003F098: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003F09C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8003F0A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8003F0A4:
    // 0x8003F0A4: jal         0x80005740
    // 0x8003F0A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_55;
    // 0x8003F0A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_55:
    // 0x8003F0AC: b           L_80040434
    // 0x8003F0B0: nop

        goto L_80040434;
    // 0x8003F0B0: nop

L_8003F0B4:
    // 0x8003F0B4: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003F0B8: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x8003F0BC: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003F0C0: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8003F0C4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8003F0C8: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x8003F0CC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8003F0D0: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x8003F0D4: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8003F0D8: addu        $t3, $t9, $t7
    ctx->r11 = ADD32(ctx->r25, ctx->r15);
    // 0x8003F0DC: jal         0x8009F768
    // 0x8003F0E0: lwc1        $f12, 0x58($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X58);
    Math_RadToDeg(rdram, ctx);
        goto after_56;
    // 0x8003F0E0: lwc1        $f12, 0x58($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X58);
    after_56:
    // 0x8003F0E4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8003F0E8: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x8003F0EC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8003F0F0: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8003F0F4: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8003F0F8: addu        $t6, $t6, $t2
    ctx->r14 = ADD32(ctx->r14, ctx->r10);
    // 0x8003F0FC: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8003F100: subu        $t6, $t6, $t2
    ctx->r14 = SUB32(ctx->r14, ctx->r10);
    // 0x8003F104: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8003F108: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8003F10C: lwc1        $f4, 0x114($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X114);
    // 0x8003F110: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F114: lwc1        $f18, 0x544C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X544C);
    // 0x8003F118: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8003F11C: sub.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8003F120: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F124: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8003F128: lwc1        $f4, 0x5450($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5450);
    // 0x8003F12C: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8003F130: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F134: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003F138: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8003F13C: lwc1        $f10, 0x5454($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5454);
    // 0x8003F140: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8003F144: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8003F148: mul.s       $f2, $f12, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8003F14C: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8003F150: add.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x8003F154: swc1        $f18, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f18.u32l;
    // 0x8003F158: bne         $a1, $at, L_8003F1C4
    if (ctx->r5 != ctx->r1) {
        // 0x8003F15C: swc1        $f14, 0x13C($sp)
        MEM_W(0X13C, ctx->r29) = ctx->f14.u32l;
            goto L_8003F1C4;
    }
    // 0x8003F15C: swc1        $f14, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f14.u32l;
    // 0x8003F160: lw          $t4, 0x1C8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1C8);
    // 0x8003F164: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F168: bnel        $t4, $at, L_8003F1C8
    if (ctx->r12 != ctx->r1) {
        // 0x8003F16C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8003F1C8;
    }
    goto skip_6;
    // 0x8003F16C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_6:
    // 0x8003F170: lw          $t8, 0x1D0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1D0);
    // 0x8003F174: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8003F178: beql        $at, $zero, L_8003F1C8
    if (ctx->r1 == 0) {
        // 0x8003F17C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8003F1C8;
    }
    goto skip_7;
    // 0x8003F17C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    skip_7:
    // 0x8003F180: lwc1        $f12, 0x58($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X58);
    // 0x8003F184: jal         0x80023090
    // 0x8003F188: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_57;
    // 0x8003F188: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_57:
    // 0x8003F18C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003F190: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003F194: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003F198: addiu       $v0, $v0, -0x698
    ctx->r2 = ADD32(ctx->r2, -0X698);
    // 0x8003F19C: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003F1A0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003F1A4: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003F1A8: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003F1AC: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003F1B0: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
    // 0x8003F1B4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003F1B8: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8003F1BC: add.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8003F1C0: swc1        $f8, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f8.u32l;
L_8003F1C4:
    // 0x8003F1C4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
L_8003F1C8:
    // 0x8003F1C8: bne         $a1, $at, L_8003F240
    if (ctx->r5 != ctx->r1) {
        // 0x8003F1CC: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_8003F240;
    }
    // 0x8003F1CC: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8003F1D0: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8003F1D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F1D8: lw          $t5, 0x1C8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1C8);
    // 0x8003F1DC: bne         $t5, $at, L_8003F240
    if (ctx->r13 != ctx->r1) {
        // 0x8003F1E0: nop
    
            goto L_8003F240;
    }
    // 0x8003F1E0: nop

    // 0x8003F1E4: lw          $t1, 0x1D0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X1D0);
    // 0x8003F1E8: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8003F1EC: bne         $at, $zero, L_8003F240
    if (ctx->r1 != 0) {
        // 0x8003F1F0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8003F240;
    }
    // 0x8003F1F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F1F4: lwc1        $f4, 0x5458($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5458);
    // 0x8003F1F8: lwc1        $f6, 0x48($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X48);
    // 0x8003F1FC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8003F200: nop

    // 0x8003F204: bc1f        L_8003F240
    if (!c1cs) {
        // 0x8003F208: nop
    
            goto L_8003F240;
    }
    // 0x8003F208: nop

    // 0x8003F20C: jal         0x80023090
    // 0x8003F210: lwc1        $f12, 0x5C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X5C);
    __sinf_recomp(rdram, ctx);
        goto after_58;
    // 0x8003F210: lwc1        $f12, 0x5C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X5C);
    after_58:
    // 0x8003F214: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F218: lwc1        $f18, 0x545C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X545C);
    // 0x8003F21C: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8003F220: addiu       $v0, $v0, -0x698
    ctx->r2 = ADD32(ctx->r2, -0X698);
    // 0x8003F224: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8003F228: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F22C: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8003F230: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003F234: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8003F238: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8003F23C: swc1        $f4, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f4.u32l;
L_8003F240:
    // 0x8003F240: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F244: lwc1        $f14, 0x5460($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X5460);
    // 0x8003F248: jal         0x80004E20
    // 0x8003F24C: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    Math_ModF(rdram, ctx);
        goto after_59;
    // 0x8003F24C: lwc1        $f12, 0x13C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X13C);
    after_59:
    // 0x8003F250: jal         0x800B9328
    // 0x8003F254: swc1        $f0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f0.u32l;
    RCP_SetupDL_17(rdram, ctx);
        goto after_60;
    // 0x8003F254: swc1        $f0, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f0.u32l;
    after_60:
    // 0x8003F258: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8003F25C: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x8003F260: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003F264: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8003F268: sll         $t3, $t7, 2
    ctx->r11 = S32(ctx->r15 << 2);
    // 0x8003F26C: addu        $t3, $t3, $t7
    ctx->r11 = ADD32(ctx->r11, ctx->r15);
    // 0x8003F270: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8003F274: subu        $t3, $t3, $t7
    ctx->r11 = SUB32(ctx->r11, ctx->r15);
    // 0x8003F278: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x8003F27C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F280: addu        $t2, $t9, $t3
    ctx->r10 = ADD32(ctx->r25, ctx->r11);
    // 0x8003F284: lwc1        $f6, 0x34($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X34);
    // 0x8003F288: lwc1        $f18, 0x5464($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5464);
    // 0x8003F28C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003F290: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003F294: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8003F298: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003F29C: jal         0x80005FE0
    // 0x8003F2A0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_61;
    // 0x8003F2A0: nop

    after_61:
    // 0x8003F2A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003F2A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F2AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003F2B0: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8003F2B4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8003F2B8: jal         0x80005C34
    // 0x8003F2BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_62;
    // 0x8003F2BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_62:
    // 0x8003F2C0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003F2C4: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8003F2C8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8003F2CC: lwc1        $f4, 0x134($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F2D0: beq         $a1, $at, L_8003F2DC
    if (ctx->r5 == ctx->r1) {
        // 0x8003F2D4: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8003F2DC;
    }
    // 0x8003F2D4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003F2D8: bne         $a1, $at, L_8003F310
    if (ctx->r5 != ctx->r1) {
        // 0x8003F2DC: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_8003F310;
    }
L_8003F2DC:
    // 0x8003F2DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F2E0: lwc1        $f8, 0x5468($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5468);
    // 0x8003F2E4: lui         $a3, 0xC5DA
    ctx->r7 = S32(0XC5DA << 16);
    // 0x8003F2E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003F2EC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8003F2F0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003F2F4: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x8003F2F8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003F2FC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003F300: jal         0x80005B00
    // 0x8003F304: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    Matrix_Translate(rdram, ctx);
        goto after_63;
    // 0x8003F304: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    after_63:
    // 0x8003F308: b           L_8003F388
    // 0x8003F30C: nop

        goto L_8003F388;
    // 0x8003F30C: nop

L_8003F310:
    // 0x8003F310: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003F314: bne         $a1, $at, L_8003F350
    if (ctx->r5 != ctx->r1) {
        // 0x8003F318: lwc1        $f10, 0x134($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
            goto L_8003F350;
    }
    // 0x8003F318: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F31C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F320: lwc1        $f18, 0x546C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X546C);
    // 0x8003F324: lui         $a3, 0xC5DA
    ctx->r7 = S32(0XC5DA << 16);
    // 0x8003F328: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003F32C: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8003F330: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003F334: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x8003F338: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003F33C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8003F340: jal         0x80005B00
    // 0x8003F344: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    Matrix_Translate(rdram, ctx);
        goto after_64;
    // 0x8003F344: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    after_64:
    // 0x8003F348: b           L_8003F388
    // 0x8003F34C: nop

        goto L_8003F388;
    // 0x8003F34C: nop

L_8003F350:
    // 0x8003F350: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003F354: bne         $a1, $at, L_8003F388
    if (ctx->r5 != ctx->r1) {
        // 0x8003F358: lwc1        $f6, 0x134($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X134);
            goto L_8003F388;
    }
    // 0x8003F358: lwc1        $f6, 0x134($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F35C: lui         $at, 0xC57A
    ctx->r1 = S32(0XC57A << 16);
    // 0x8003F360: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F364: lui         $a3, 0xC5DA
    ctx->r7 = S32(0XC5DA << 16);
    // 0x8003F368: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003F36C: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003F370: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003F374: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x8003F378: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003F37C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8003F380: jal         0x80005B00
    // 0x8003F384: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    Matrix_Translate(rdram, ctx);
        goto after_65;
    // 0x8003F384: lw          $a1, 0x13C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X13C);
    after_65:
L_8003F388:
    // 0x8003F388: jal         0x80006EB8
    // 0x8003F38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_66;
    // 0x8003F38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_66:
    // 0x8003F390: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003F394: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8003F398: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8003F39C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003F3A0: bne         $a1, $at, L_8003F3CC
    if (ctx->r5 != ctx->r1) {
        // 0x8003F3A4: lui         $t7, 0x600
        ctx->r15 = S32(0X600 << 16);
            goto L_8003F3CC;
    }
    // 0x8003F3A4: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003F3A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F3AC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8003F3B0: addiu       $t9, $t9, 0xA80
    ctx->r25 = ADD32(ctx->r25, 0XA80);
    // 0x8003F3B4: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8003F3B8: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003F3BC: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8003F3C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8003F3C4: b           L_8003F458
    // 0x8003F3C8: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
        goto L_8003F458;
    // 0x8003F3C8: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
L_8003F3CC:
    // 0x8003F3CC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003F3D0: bne         $a1, $at, L_8003F3FC
    if (ctx->r5 != ctx->r1) {
        // 0x8003F3D4: lui         $t2, 0x600
        ctx->r10 = S32(0X600 << 16);
            goto L_8003F3FC;
    }
    // 0x8003F3D4: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8003F3D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F3DC: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x8003F3E0: addiu       $t6, $t6, -0x6DE0
    ctx->r14 = ADD32(ctx->r14, -0X6DE0);
    // 0x8003F3E4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8003F3E8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003F3EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8003F3F0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8003F3F4: b           L_8003F458
    // 0x8003F3F8: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
        goto L_8003F458;
    // 0x8003F3F8: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
L_8003F3FC:
    // 0x8003F3FC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003F400: bne         $a1, $at, L_8003F42C
    if (ctx->r5 != ctx->r1) {
        // 0x8003F404: lui         $t8, 0x600
        ctx->r24 = S32(0X600 << 16);
            goto L_8003F42C;
    }
    // 0x8003F404: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003F408: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F40C: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x8003F410: addiu       $t5, $t5, 0x3480
    ctx->r13 = ADD32(ctx->r13, 0X3480);
    // 0x8003F414: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003F418: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003F41C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x8003F420: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003F424: b           L_8003F458
    // 0x8003F428: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
        goto L_8003F458;
    // 0x8003F428: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
L_8003F42C:
    // 0x8003F42C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003F430: bne         $a1, $at, L_8003F454
    if (ctx->r5 != ctx->r1) {
        // 0x8003F434: lui         $t7, 0x600
        ctx->r15 = S32(0X600 << 16);
            goto L_8003F454;
    }
    // 0x8003F434: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8003F438: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F43C: lui         $t9, 0x602
    ctx->r25 = S32(0X602 << 16);
    // 0x8003F440: addiu       $t9, $t9, -0x1EB0
    ctx->r25 = ADD32(ctx->r25, -0X1EB0);
    // 0x8003F444: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x8003F448: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8003F44C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8003F450: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8003F454:
    // 0x8003F454: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
L_8003F458:
    // 0x8003F458: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8003F45C: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8003F460: nop

    // 0x8003F464: bc1fl       L_8003F480
    if (!c1cs) {
        // 0x8003F468: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8003F480;
    }
    goto skip_8;
    // 0x8003F468: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_8:
    // 0x8003F46C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003F470: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F474: b           L_8003F488
    // 0x8003F478: swc1        $f4, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f4.u32l;
        goto L_8003F488;
    // 0x8003F478: swc1        $f4, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f4.u32l;
    // 0x8003F47C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8003F480:
    // 0x8003F480: nop

    // 0x8003F484: swc1        $f6, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->f6.u32l;
L_8003F488:
    // 0x8003F488: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F48C: lwc1        $f18, 0x5470($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5470);
    // 0x8003F490: lwc1        $f10, 0x13C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X13C);
    // 0x8003F494: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003F498: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003F49C: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8003F4A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003F4A4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003F4A8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8003F4AC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003F4B0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8003F4B4: jal         0x80005B00
    // 0x8003F4B8: nop

    Matrix_Translate(rdram, ctx);
        goto after_67;
    // 0x8003F4B8: nop

    after_67:
    // 0x8003F4BC: jal         0x80006EB8
    // 0x8003F4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_68;
    // 0x8003F4C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_68:
    // 0x8003F4C4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003F4C8: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8003F4CC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8003F4D0: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003F4D4: bnel        $a1, $at, L_8003F504
    if (ctx->r5 != ctx->r1) {
        // 0x8003F4D8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8003F504;
    }
    goto skip_9;
    // 0x8003F4D8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    skip_9:
    // 0x8003F4DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F4E0: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003F4E4: addiu       $t4, $t4, 0xA80
    ctx->r12 = ADD32(ctx->r12, 0XA80);
    // 0x8003F4E8: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8003F4EC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003F4F0: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8003F4F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8003F4F8: b           L_80040434
    // 0x8003F4FC: nop

        goto L_80040434;
    // 0x8003F4FC: nop

    // 0x8003F500: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
L_8003F504:
    // 0x8003F504: bne         $a1, $at, L_8003F530
    if (ctx->r5 != ctx->r1) {
        // 0x8003F508: lui         $t5, 0x600
        ctx->r13 = S32(0X600 << 16);
            goto L_8003F530;
    }
    // 0x8003F508: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8003F50C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F510: lui         $t1, 0x602
    ctx->r9 = S32(0X602 << 16);
    // 0x8003F514: addiu       $t1, $t1, -0x6DE0
    ctx->r9 = ADD32(ctx->r9, -0X6DE0);
    // 0x8003F518: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8003F51C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003F520: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8003F524: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8003F528: b           L_80040434
    // 0x8003F52C: nop

        goto L_80040434;
    // 0x8003F52C: nop

L_8003F530:
    // 0x8003F530: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003F534: bne         $a1, $at, L_8003F560
    if (ctx->r5 != ctx->r1) {
        // 0x8003F538: lui         $t9, 0x600
        ctx->r25 = S32(0X600 << 16);
            goto L_8003F560;
    }
    // 0x8003F538: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8003F53C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F540: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x8003F544: addiu       $t3, $t3, 0x3480
    ctx->r11 = ADD32(ctx->r11, 0X3480);
    // 0x8003F548: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8003F54C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003F550: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8003F554: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8003F558: b           L_80040434
    // 0x8003F55C: nop

        goto L_80040434;
    // 0x8003F55C: nop

L_8003F560:
    // 0x8003F560: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003F564: bne         $a1, $at, L_80040434
    if (ctx->r5 != ctx->r1) {
        // 0x8003F568: lui         $t6, 0x600
        ctx->r14 = S32(0X600 << 16);
            goto L_80040434;
    }
    // 0x8003F568: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8003F56C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F570: lui         $t4, 0x602
    ctx->r12 = S32(0X602 << 16);
    // 0x8003F574: addiu       $t4, $t4, -0x1EB0
    ctx->r12 = ADD32(ctx->r12, -0X1EB0);
    // 0x8003F578: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8003F57C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8003F580: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8003F584: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8003F588: b           L_80040434
    // 0x8003F58C: nop

        goto L_80040434;
    // 0x8003F58C: nop

L_8003F590:
    // 0x8003F590: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8003F594: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003F598: lw          $t5, 0x1C8($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X1C8);
    // 0x8003F59C: beq         $t5, $at, L_8004026C
    if (ctx->r13 == ctx->r1) {
        // 0x8003F5A0: nop
    
            goto L_8004026C;
    }
    // 0x8003F5A0: nop

    // 0x8003F5A4: jal         0x80005708
    // 0x8003F5A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_69;
    // 0x8003F5A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_69:
    // 0x8003F5AC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003F5B0: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8003F5B4: jal         0x8009F768
    // 0x8003F5B8: lwc1        $f12, 0x58($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X58);
    Math_RadToDeg(rdram, ctx);
        goto after_70;
    // 0x8003F5B8: lwc1        $f12, 0x58($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X58);
    after_70:
    // 0x8003F5BC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8003F5C0: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x8003F5C4: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    // 0x8003F5C8: jal         0x8009F768
    // 0x8003F5CC: lwc1        $f12, 0x5C($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X5C);
    Math_RadToDeg(rdram, ctx);
        goto after_71;
    // 0x8003F5CC: lwc1        $f12, 0x5C($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X5C);
    after_71:
    // 0x8003F5D0: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8003F5D4: lwc1        $f2, 0x12C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8003F5D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F5DC: swc1        $f0, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f0.u32l;
    // 0x8003F5E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F5E4: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8003F5E8: nop

    // 0x8003F5EC: bc1tl       L_8003F608
    if (c1cs) {
        // 0x8003F5F0: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_8003F608;
    }
    goto skip_10;
    // 0x8003F5F0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    skip_10:
    // 0x8003F5F4: lwc1        $f6, 0x5474($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5474);
    // 0x8003F5F8: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003F5FC: nop

    // 0x8003F600: bc1f        L_80040264
    if (!c1cs) {
        // 0x8003F604: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_80040264;
    }
    // 0x8003F604: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
L_8003F608:
    // 0x8003F608: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F60C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F610: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8003F614: nop

    // 0x8003F618: bc1t        L_8003F634
    if (c1cs) {
        // 0x8003F61C: nop
    
            goto L_8003F634;
    }
    // 0x8003F61C: nop

    // 0x8003F620: lwc1        $f10, 0x5478($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5478);
    // 0x8003F624: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8003F628: nop

    // 0x8003F62C: bc1f        L_80040264
    if (!c1cs) {
        // 0x8003F630: nop
    
            goto L_80040264;
    }
    // 0x8003F630: nop

L_8003F634:
    // 0x8003F634: jal         0x800B9358
    // 0x8003F638: nop

    RCP_SetupDL_36(rdram, ctx);
        goto after_72;
    // 0x8003F638: nop

    after_72:
    // 0x8003F63C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003F640: lwc1        $f8, -0x7BE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7BE0);
    // 0x8003F644: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003F648: lw          $a1, -0x7DCC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7DCC);
    // 0x8003F64C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8003F650: lwc1        $f4, -0x7BDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7BDC);
    // 0x8003F654: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003F658: swc1        $f8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f8.u32l;
    // 0x8003F65C: beq         $v0, $a1, L_8003F66C
    if (ctx->r2 == ctx->r5) {
        // 0x8003F660: swc1        $f4, 0x134($sp)
        MEM_W(0X134, ctx->r29) = ctx->f4.u32l;
            goto L_8003F66C;
    }
    // 0x8003F660: swc1        $f4, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f4.u32l;
    // 0x8003F664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F668: bne         $a1, $at, L_8003F688
    if (ctx->r5 != ctx->r1) {
        // 0x8003F66C: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_8003F688;
    }
L_8003F66C:
    // 0x8003F66C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x8003F670: lw          $t9, -0x7D84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D84);
    // 0x8003F674: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F678: addiu       $t3, $zero, 0x4D
    ctx->r11 = ADD32(0, 0X4D);
    // 0x8003F67C: bnel        $t9, $at, L_8003F68C
    if (ctx->r25 != ctx->r1) {
        // 0x8003F680: lw          $t2, 0x11C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X11C);
            goto L_8003F68C;
    }
    goto skip_11;
    // 0x8003F680: lw          $t2, 0x11C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X11C);
    skip_11:
    // 0x8003F684: sw          $t3, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r11;
L_8003F688:
    // 0x8003F688: lw          $t2, 0x11C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X11C);
L_8003F68C:
    // 0x8003F68C: lwc1        $f6, 0x138($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8003F690: lw          $t6, 0x11C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X11C);
    // 0x8003F694: bne         $t2, $v0, L_8003F6E0
    if (ctx->r10 != ctx->r2) {
        // 0x8003F698: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8003F6E0;
    }
    // 0x8003F698: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F69C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8003F6A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F6A4: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003F6A8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F6AC: jal         0x80004E20
    // 0x8003F6B0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    Math_ModF(rdram, ctx);
        goto after_73;
    // 0x8003F6B0: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_73:
    // 0x8003F6B4: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F6B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F6BC: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F6C0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8003F6C4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F6C8: add.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8003F6CC: swc1        $f0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f0.u32l;
    // 0x8003F6D0: jal         0x80004E20
    // 0x8003F6D4: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    Math_ModF(rdram, ctx);
        goto after_74;
    // 0x8003F6D4: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    after_74:
    // 0x8003F6D8: b           L_8003F86C
    // 0x8003F6DC: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
        goto L_8003F86C;
    // 0x8003F6DC: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
L_8003F6E0:
    // 0x8003F6E0: bne         $t6, $at, L_8003F738
    if (ctx->r14 != ctx->r1) {
        // 0x8003F6E4: lw          $t4, 0x11C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X11C);
            goto L_8003F738;
    }
    // 0x8003F6E4: lw          $t4, 0x11C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X11C);
    // 0x8003F6E8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003F6EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F6F0: lwc1        $f6, 0x138($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8003F6F4: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003F6F8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F6FC: jal         0x80004E20
    // 0x8003F700: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    Math_ModF(rdram, ctx);
        goto after_75;
    // 0x8003F700: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    after_75:
    // 0x8003F704: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F708: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003F70C: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F710: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8003F714: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F718: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8003F71C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F720: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F724: swc1        $f0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f0.u32l;
    // 0x8003F728: jal         0x80004E20
    // 0x8003F72C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    Math_ModF(rdram, ctx);
        goto after_76;
    // 0x8003F72C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    after_76:
    // 0x8003F730: b           L_8003F86C
    // 0x8003F734: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
        goto L_8003F86C;
    // 0x8003F734: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
L_8003F738:
    // 0x8003F738: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003F73C: bne         $t4, $at, L_8003F794
    if (ctx->r12 != ctx->r1) {
        // 0x8003F740: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8003F794;
    }
    // 0x8003F740: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003F744: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x8003F748: lwc1        $f18, 0x138($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8003F74C: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003F750: bnel        $t8, $zero, L_8003F798
    if (ctx->r24 != 0) {
        // 0x8003F754: lw          $t5, 0x11C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X11C);
            goto L_8003F798;
    }
    goto skip_12;
    // 0x8003F754: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
    skip_12:
    // 0x8003F758: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003F75C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8003F760: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F764: add.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8003F768: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003F76C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F770: jal         0x80004E20
    // 0x8003F774: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    Math_ModF(rdram, ctx);
        goto after_77;
    // 0x8003F774: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    after_77:
    // 0x8003F778: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F77C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F780: swc1        $f0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f0.u32l;
    // 0x8003F784: jal         0x80004E20
    // 0x8003F788: lwc1        $f12, 0x134($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X134);
    Math_ModF(rdram, ctx);
        goto after_78;
    // 0x8003F788: lwc1        $f12, 0x134($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X134);
    after_78:
    // 0x8003F78C: b           L_8003F86C
    // 0x8003F790: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
        goto L_8003F86C;
    // 0x8003F790: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
L_8003F794:
    // 0x8003F794: lw          $t5, 0x11C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X11C);
L_8003F798:
    // 0x8003F798: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8003F79C: lwc1        $f6, 0x138($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8003F7A0: bne         $t5, $at, L_8003F7E8
    if (ctx->r13 != ctx->r1) {
        // 0x8003F7A4: lw          $t1, 0x11C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X11C);
            goto L_8003F7E8;
    }
    // 0x8003F7A4: lw          $t1, 0x11C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X11C);
    // 0x8003F7A8: lui         $at, 0x420A
    ctx->r1 = S32(0X420A << 16);
    // 0x8003F7AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F7B0: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003F7B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F7B8: jal         0x80004E20
    // 0x8003F7BC: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    Math_ModF(rdram, ctx);
        goto after_79;
    // 0x8003F7BC: sub.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f18.fl;
    after_79:
    // 0x8003F7C0: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x8003F7C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003F7C8: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F7CC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F7D0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F7D4: swc1        $f0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f0.u32l;
    // 0x8003F7D8: jal         0x80004E20
    // 0x8003F7DC: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    Math_ModF(rdram, ctx);
        goto after_80;
    // 0x8003F7DC: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_80:
    // 0x8003F7E0: b           L_8003F86C
    // 0x8003F7E4: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
        goto L_8003F86C;
    // 0x8003F7E4: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
L_8003F7E8:
    // 0x8003F7E8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8003F7EC: bne         $t1, $at, L_8003F844
    if (ctx->r9 != ctx->r1) {
        // 0x8003F7F0: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_8003F844;
    }
    // 0x8003F7F0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x8003F7F4: lw          $v1, -0x7D80($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D80);
    // 0x8003F7F8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003F7FC: lwc1        $f4, 0x134($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F800: lw          $t7, 0x1C8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X1C8);
    // 0x8003F804: bnel        $t7, $at, L_8003F81C
    if (ctx->r15 != ctx->r1) {
        // 0x8003F808: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8003F81C;
    }
    goto skip_13;
    // 0x8003F808: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    skip_13:
    // 0x8003F80C: lw          $t9, 0x1D0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1D0);
    // 0x8003F810: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8003F814: beq         $at, $zero, L_8003F86C
    if (ctx->r1 == 0) {
        // 0x8003F818: lui         $at, 0x43B4
        ctx->r1 = S32(0X43B4 << 16);
            goto L_8003F86C;
    }
    // 0x8003F818: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
L_8003F81C:
    // 0x8003F81C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F820: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8003F824: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003F828: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003F82C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F830: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F834: jal         0x80004E20
    // 0x8003F838: sub.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f10.fl;
    Math_ModF(rdram, ctx);
        goto after_81;
    // 0x8003F838: sub.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f10.fl;
    after_81:
    // 0x8003F83C: b           L_8003F86C
    // 0x8003F840: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
        goto L_8003F86C;
    // 0x8003F840: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
L_8003F844:
    // 0x8003F844: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003F848: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F84C: jal         0x80004E20
    // 0x8003F850: lwc1        $f12, 0x138($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X138);
    Math_ModF(rdram, ctx);
        goto after_82;
    // 0x8003F850: lwc1        $f12, 0x138($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X138);
    after_82:
    // 0x8003F854: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F858: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8003F85C: lwc1        $f12, 0x134($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F860: jal         0x80004E20
    // 0x8003F864: swc1        $f0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f0.u32l;
    Math_ModF(rdram, ctx);
        goto after_83;
    // 0x8003F864: swc1        $f0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f0.u32l;
    after_83:
    // 0x8003F868: swc1        $f0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f0.u32l;
L_8003F86C:
    // 0x8003F86C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8003F870: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003F874: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8003F878: lui         $at, 0x43BE
    ctx->r1 = S32(0X43BE << 16);
    // 0x8003F87C: lwc1        $f6, 0x138($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8003F880: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8003F884: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8003F888: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003F88C: bc1fl       L_8003F8C4
    if (!c1cs) {
        // 0x8003F890: lwc1        $f4, 0x130($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X130);
            goto L_8003F8C4;
    }
    goto skip_14;
    // 0x8003F890: lwc1        $f4, 0x130($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X130);
    skip_14:
    // 0x8003F894: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F898: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003F89C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8003F8A0: nop

    // 0x8003F8A4: bc1fl       L_8003F8C4
    if (!c1cs) {
        // 0x8003F8A8: lwc1        $f4, 0x130($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X130);
            goto L_8003F8C4;
    }
    goto skip_15;
    // 0x8003F8A8: lwc1        $f4, 0x130($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X130);
    skip_15:
    // 0x8003F8AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F8B0: nop

    // 0x8003F8B4: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003F8B8: neg.s       $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = -ctx->f10.fl;
    // 0x8003F8BC: swc1        $f8, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f8.u32l;
    // 0x8003F8C0: lwc1        $f4, 0x130($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X130);
L_8003F8C4:
    // 0x8003F8C4: lui         $at, 0x438C
    ctx->r1 = S32(0X438C << 16);
    // 0x8003F8C8: lwc1        $f6, 0x134($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F8CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8003F8D0: nop

    // 0x8003F8D4: bc1fl       L_8003F90C
    if (!c1cs) {
        // 0x8003F8D8: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_8003F90C;
    }
    goto skip_16;
    // 0x8003F8D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_16:
    // 0x8003F8DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F8E0: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003F8E4: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x8003F8E8: nop

    // 0x8003F8EC: bc1fl       L_8003F90C
    if (!c1cs) {
        // 0x8003F8F0: lw          $a0, 0x0($s1)
        ctx->r4 = MEM_W(ctx->r17, 0X0);
            goto L_8003F90C;
    }
    goto skip_17;
    // 0x8003F8F0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    skip_17:
    // 0x8003F8F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003F8F8: nop

    // 0x8003F8FC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8003F900: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8003F904: swc1        $f4, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f4.u32l;
    // 0x8003F908: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
L_8003F90C:
    // 0x8003F90C: jal         0x80005FE0
    // 0x8003F910: lw          $a1, -0x7BD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7BD8);
    Matrix_RotateZ(rdram, ctx);
        goto after_84;
    // 0x8003F910: lw          $a1, -0x7BD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7BD8);
    after_84:
    // 0x8003F914: lw          $t3, 0x11C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X11C);
    // 0x8003F918: lw          $t2, 0x11C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X11C);
    // 0x8003F91C: lwc1        $f16, 0x138($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8003F920: slti        $at, $t3, 0x13
    ctx->r1 = SIGNED(ctx->r11) < 0X13 ? 1 : 0;
    // 0x8003F924: bne         $at, $zero, L_8003F940
    if (ctx->r1 != 0) {
        // 0x8003F928: addiu       $t6, $t2, -0x1
        ctx->r14 = ADD32(ctx->r10, -0X1);
            goto L_8003F940;
    }
    // 0x8003F928: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x8003F92C: addiu       $at, $zero, 0x4D
    ctx->r1 = ADD32(0, 0X4D);
    // 0x8003F930: beq         $t3, $at, L_8003F960
    if (ctx->r11 == ctx->r1) {
        // 0x8003F934: nop
    
            goto L_8003F960;
    }
    // 0x8003F934: nop

    // 0x8003F938: b           L_80040264
    // 0x8003F93C: nop

        goto L_80040264;
    // 0x8003F93C: nop

L_8003F940:
    // 0x8003F940: sltiu       $at, $t6, 0x12
    ctx->r1 = ctx->r14 < 0X12 ? 1 : 0;
    // 0x8003F944: beq         $at, $zero, L_80040264
    if (ctx->r1 == 0) {
        // 0x8003F948: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80040264;
    }
    // 0x8003F948: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003F94C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003F950: addu        $at, $at, $t6
    gpr jr_addend_8003F958 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003F954: lw          $t6, 0x547C($at)
    ctx->r14 = ADD32(ctx->r1, 0X547C);
    // 0x8003F958: jr          $t6
    // 0x8003F95C: nop

    switch (jr_addend_8003F958 >> 2) {
        case 0: goto L_8003FB34; break;
        case 1: goto L_8003FCBC; break;
        case 2: goto L_8003FE40; break;
        case 3: goto L_8003FE40; break;
        case 4: goto L_800401B0; break;
        case 5: goto L_80040264; break;
        case 6: goto L_80040264; break;
        case 7: goto L_80040264; break;
        case 8: goto L_80040264; break;
        case 9: goto L_8003FD84; break;
        case 10: goto L_80040264; break;
        case 11: goto L_80040264; break;
        case 12: goto L_80040264; break;
        case 13: goto L_8003FF6C; break;
        case 14: goto L_80040264; break;
        case 15: goto L_80040264; break;
        case 16: goto L_80040038; break;
        case 17: goto L_80040104; break;
        default: switch_error(__func__, 0x8003F958, 0x800D547C);
    }
    // 0x8003F95C: nop

L_8003F960:
    // 0x8003F960: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003F964: lwc1        $f18, -0x6A0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6A0);
    // 0x8003F968: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8003F96C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8003F970: nop

    // 0x8003F974: beq         $t8, $zero, L_8003FB2C
    if (ctx->r24 == 0) {
        // 0x8003F978: nop
    
            goto L_8003FB2C;
    }
    // 0x8003F978: nop

    // 0x8003F97C: jal         0x800B94A0
    // 0x8003F980: swc1        $f16, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f16.u32l;
    RCP_SetupDL_62(rdram, ctx);
        goto after_85;
    // 0x8003F980: swc1        $f16, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->f16.u32l;
    after_85:
    // 0x8003F984: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003F988: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003F98C: lwc1        $f16, 0x138($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X138);
    // 0x8003F990: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003F994: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8003F998: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003F99C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8003F9A0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8003F9A4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8003F9A8: lwc1        $f6, -0x6A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6A0);
    // 0x8003F9AC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8003F9B0: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8003F9B4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8003F9B8: nop

    // 0x8003F9BC: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x8003F9C0: or          $t2, $t3, $at
    ctx->r10 = ctx->r11 | ctx->r1;
    // 0x8003F9C4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8003F9C8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8003F9CC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003F9D0: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003F9D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F9D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003F9DC: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8003F9E0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F9E4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003F9E8: sub.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8003F9EC: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x8003F9F0: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8003F9F4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8003F9F8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8003F9FC: jal         0x80005B00
    // 0x8003FA00: nop

    Matrix_Translate(rdram, ctx);
        goto after_86;
    // 0x8003FA00: nop

    after_86:
    // 0x8003FA04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003FA08: lwc1        $f0, 0x54C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X54C4);
    // 0x8003FA0C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8003FA10: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003FA14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003FA18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003FA1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FA20: jal         0x80005C34
    // 0x8003FA24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_87;
    // 0x8003FA24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_87:
    // 0x8003FA28: jal         0x80005708
    // 0x8003FA2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_88;
    // 0x8003FA2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_88:
    // 0x8003FA30: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003FA34: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8003FA38: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003FA3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003FA40: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8003FA44: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003FA48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FA4C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003FA50: lwc1        $f18, 0x54C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X54C8);
    // 0x8003FA54: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003FA58: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8003FA5C: mul.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003FA60: nop

    // 0x8003FA64: mul.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8003FA68: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003FA6C: jal         0x80005FE0
    // 0x8003FA70: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_89;
    // 0x8003FA70: nop

    after_89:
    // 0x8003FA74: lui         $a1, 0x3F88
    ctx->r5 = S32(0X3F88 << 16);
    // 0x8003FA78: lui         $a2, 0x3F6E
    ctx->r6 = S32(0X3F6E << 16);
    // 0x8003FA7C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003FA80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003FA84: ori         $a2, $a2, 0x147B
    ctx->r6 = ctx->r6 | 0X147B;
    // 0x8003FA88: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x8003FA8C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FA90: jal         0x80005C34
    // 0x8003FA94: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_90;
    // 0x8003FA94: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_90:
    // 0x8003FA98: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003FA9C: lw          $t1, 0x7DB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7DB0);
    // 0x8003FAA0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003FAA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003FAA8: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8003FAAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003FAB0: lwc1        $f10, 0x54CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X54CC);
    // 0x8003FAB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003FAB8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FABC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003FAC0: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8003FAC4: nop

    // 0x8003FAC8: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8003FACC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003FAD0: jal         0x80005FE0
    // 0x8003FAD4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_91;
    // 0x8003FAD4: nop

    after_91:
    // 0x8003FAD8: lui         $a1, 0x3F88
    ctx->r5 = S32(0X3F88 << 16);
    // 0x8003FADC: lui         $a2, 0x3F6E
    ctx->r6 = S32(0X3F6E << 16);
    // 0x8003FAE0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003FAE4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FAE8: ori         $a2, $a2, 0x147B
    ctx->r6 = ctx->r6 | 0X147B;
    // 0x8003FAEC: ori         $a1, $a1, 0xF5C3
    ctx->r5 = ctx->r5 | 0XF5C3;
    // 0x8003FAF0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FAF4: jal         0x80005C34
    // 0x8003FAF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_92;
    // 0x8003FAF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_92:
    // 0x8003FAFC: jal         0x80006EB8
    // 0x8003FB00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_93;
    // 0x8003FB00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_93:
    // 0x8003FB04: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003FB08: lui         $t2, 0x700
    ctx->r10 = S32(0X700 << 16);
    // 0x8003FB0C: addiu       $t2, $t2, 0x1540
    ctx->r10 = ADD32(ctx->r10, 0X1540);
    // 0x8003FB10: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8003FB14: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003FB18: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8003FB1C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8003FB20: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8003FB24: jal         0x80005740
    // 0x8003FB28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_94;
    // 0x8003FB28: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_94:
L_8003FB2C:
    // 0x8003FB2C: b           L_80040264
    // 0x8003FB30: nop

        goto L_80040264;
    // 0x8003FB30: nop

L_8003FB34:
    // 0x8003FB34: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8003FB38: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8003FB3C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003FB40: lw          $t4, 0x1C8($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X1C8);
    // 0x8003FB44: bne         $t4, $at, L_8003FBFC
    if (ctx->r12 != ctx->r1) {
        // 0x8003FB48: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8003FBFC;
    }
    // 0x8003FB48: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003FB4C: lw          $t8, 0x7A80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7A80);
    // 0x8003FB50: slti        $at, $t8, 0x105
    ctx->r1 = SIGNED(ctx->r24) < 0X105 ? 1 : 0;
    // 0x8003FB54: bne         $at, $zero, L_8003FBFC
    if (ctx->r1 != 0) {
        // 0x8003FB58: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8003FBFC;
    }
    // 0x8003FB58: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8003FB5C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003FB60: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003FB64: lwc1        $f18, 0x134($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003FB68: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8003FB6C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8003FB70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003FB74: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8003FB78: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003FB7C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003FB80: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003FB84: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003FB88: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FB8C: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003FB90: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x8003FB94: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8003FB98: jal         0x80005B00
    // 0x8003FB9C: nop

    Matrix_Translate(rdram, ctx);
        goto after_95;
    // 0x8003FB9C: nop

    after_95:
    // 0x8003FBA0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003FBA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003FBA8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003FBAC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003FBB0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8003FBB4: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8003FBB8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FBBC: jal         0x80005C34
    // 0x8003FBC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_96;
    // 0x8003FBC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_96:
    // 0x8003FBC4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003FBC8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003FBCC: jal         0x80006EB8
    // 0x8003FBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_97;
    // 0x8003FBD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_97:
    // 0x8003FBD4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003FBD8: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x8003FBDC: addiu       $t3, $t3, -0x2210
    ctx->r11 = ADD32(ctx->r11, -0X2210);
    // 0x8003FBE0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8003FBE4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8003FBE8: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8003FBEC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8003FBF0: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8003FBF4: b           L_80040264
    // 0x8003FBF8: nop

        goto L_80040264;
    // 0x8003FBF8: nop

L_8003FBFC:
    // 0x8003FBFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003FC00: lwc1        $f10, 0x54D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X54D0);
    // 0x8003FC04: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003FC08: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8003FC0C: c.lt.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl < ctx->f6.fl;
    // 0x8003FC10: nop

    // 0x8003FC14: bc1f        L_8003FCB4
    if (!c1cs) {
        // 0x8003FC18: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8003FCB4;
    }
    // 0x8003FC18: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8003FC1C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003FC20: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003FC24: lwc1        $f18, 0x134($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003FC28: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8003FC2C: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x8003FC30: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003FC34: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8003FC38: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003FC3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003FC40: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003FC44: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003FC48: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FC4C: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003FC50: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x8003FC54: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8003FC58: jal         0x80005B00
    // 0x8003FC5C: nop

    Matrix_Translate(rdram, ctx);
        goto after_98;
    // 0x8003FC5C: nop

    after_98:
    // 0x8003FC60: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003FC64: lwc1        $f0, 0x54D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X54D4);
    // 0x8003FC68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003FC6C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003FC70: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003FC74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003FC78: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FC7C: jal         0x80005C34
    // 0x8003FC80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_99;
    // 0x8003FC80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_99:
    // 0x8003FC84: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003FC88: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003FC8C: jal         0x80006EB8
    // 0x8003FC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_100;
    // 0x8003FC90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_100:
    // 0x8003FC94: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003FC98: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x8003FC9C: addiu       $t5, $t5, -0x2210
    ctx->r13 = ADD32(ctx->r13, -0X2210);
    // 0x8003FCA0: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003FCA4: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003FCA8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003FCAC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003FCB0: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_8003FCB4:
    // 0x8003FCB4: b           L_80040264
    // 0x8003FCB8: nop

        goto L_80040264;
    // 0x8003FCB8: nop

L_8003FCBC:
    // 0x8003FCBC: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8003FCC0: lw          $t1, 0x7820($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7820);
    // 0x8003FCC4: bne         $t1, $zero, L_8003FD7C
    if (ctx->r9 != 0) {
        // 0x8003FCC8: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8003FD7C;
    }
    // 0x8003FCC8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8003FCCC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003FCD0: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003FCD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003FCD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003FCDC: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003FCE0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FCE4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FCE8: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8003FCEC: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x8003FCF0: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x8003FCF4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003FCF8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8003FCFC: jal         0x80005B00
    // 0x8003FD00: nop

    Matrix_Translate(rdram, ctx);
        goto after_101;
    // 0x8003FD00: nop

    after_101:
    // 0x8003FD04: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8003FD08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003FD0C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003FD10: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003FD14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003FD18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003FD1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FD20: jal         0x80005C34
    // 0x8003FD24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_102;
    // 0x8003FD24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_102:
    // 0x8003FD28: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003FD2C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003FD30: jal         0x80006EB8
    // 0x8003FD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_103;
    // 0x8003FD34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_103:
    // 0x8003FD38: jal         0x800B94A0
    // 0x8003FD3C: nop

    RCP_SetupDL_62(rdram, ctx);
        goto after_104;
    // 0x8003FD3C: nop

    after_104:
    // 0x8003FD40: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003FD44: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8003FD48: addiu       $t6, $zero, -0x40
    ctx->r14 = ADD32(0, -0X40);
    // 0x8003FD4C: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8003FD50: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003FD54: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8003FD58: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8003FD5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003FD60: lui         $t5, 0x603
    ctx->r13 = S32(0X603 << 16);
    // 0x8003FD64: addiu       $t5, $t5, -0x6770
    ctx->r13 = ADD32(ctx->r13, -0X6770);
    // 0x8003FD68: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003FD6C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8003FD70: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003FD74: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8003FD78: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
L_8003FD7C:
    // 0x8003FD7C: b           L_80040264
    // 0x8003FD80: nop

        goto L_80040264;
    // 0x8003FD80: nop

L_8003FD84:
    // 0x8003FD84: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8003FD88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003FD8C: lwc1        $f4, 0x134($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003FD90: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003FD94: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003FD98: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8003FD9C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003FDA0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FDA4: sub.s       $f8, $f16, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003FDA8: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x8003FDAC: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8003FDB0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8003FDB4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003FDB8: jal         0x80005B00
    // 0x8003FDBC: nop

    Matrix_Translate(rdram, ctx);
        goto after_105;
    // 0x8003FDBC: nop

    after_105:
    // 0x8003FDC0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003FDC4: lwc1        $f0, 0x54D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X54D8);
    // 0x8003FDC8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003FDCC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FDD0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003FDD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003FDD8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FDDC: jal         0x80005C34
    // 0x8003FDE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_106;
    // 0x8003FDE0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_106:
    // 0x8003FDE4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003FDE8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003FDEC: jal         0x80006EB8
    // 0x8003FDF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_107;
    // 0x8003FDF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_107:
    // 0x8003FDF4: jal         0x800B94A0
    // 0x8003FDF8: nop

    RCP_SetupDL_62(rdram, ctx);
        goto after_108;
    // 0x8003FDF8: nop

    after_108:
    // 0x8003FDFC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003FE00: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8003FE04: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x8003FE08: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8003FE0C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8003FE10: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8003FE14: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8003FE18: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003FE1C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8003FE20: addiu       $t8, $t8, 0x3760
    ctx->r24 = ADD32(ctx->r24, 0X3760);
    // 0x8003FE24: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8003FE28: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003FE2C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8003FE30: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8003FE34: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8003FE38: b           L_80040264
    // 0x8003FE3C: nop

        goto L_80040264;
    // 0x8003FE3C: nop

L_8003FE40:
    // 0x8003FE40: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8003FE44: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003FE48: lui         $at, 0x4060
    ctx->r1 = S32(0X4060 << 16);
    // 0x8003FE4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003FE50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8003FE54: lwc1        $f8, 0x7D20($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8003FE58: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8003FE5C: lwc1        $f4, 0x54DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54DC);
    // 0x8003FE60: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8003FE64: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8003FE68: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003FE6C: add.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8003FE70: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8003FE74: nop

    // 0x8003FE78: bc1f        L_8003FE84
    if (!c1cs) {
        // 0x8003FE7C: nop
    
            goto L_8003FE84;
    }
    // 0x8003FE7C: nop

    // 0x8003FE80: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8003FE84:
    // 0x8003FE84: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8003FE88: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8003FE8C: lw          $t1, 0x1C8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X1C8);
    // 0x8003FE90: bne         $t1, $at, L_8003FEB0
    if (ctx->r9 != ctx->r1) {
        // 0x8003FE94: lui         $at, 0x8016
        ctx->r1 = S32(0X8016 << 16);
            goto L_8003FEB0;
    }
    // 0x8003FE94: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8003FE98: lwc1        $f0, -0x67C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X67C);
    // 0x8003FE9C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8003FEA0: nop

    // 0x8003FEA4: bc1fl       L_8003FEB4
    if (!c1cs) {
        // 0x8003FEA8: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8003FEB4;
    }
    goto skip_18;
    // 0x8003FEA8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    skip_18:
    // 0x8003FEAC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_8003FEB0:
    // 0x8003FEB0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
L_8003FEB4:
    // 0x8003FEB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003FEB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003FEBC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003FEC0: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003FEC4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FEC8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FECC: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8003FED0: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x8003FED4: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    // 0x8003FED8: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x8003FEDC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8003FEE0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8003FEE4: jal         0x80005B00
    // 0x8003FEE8: nop

    Matrix_Translate(rdram, ctx);
        goto after_109;
    // 0x8003FEE8: nop

    after_109:
    // 0x8003FEEC: lwc1        $f0, 0x128($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8003FEF0: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x8003FEF4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003FEF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003FEFC: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003FF00: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8003FF04: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003FF08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003FF0C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8003FF10: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003FF14: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8003FF18: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FF1C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003FF20: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8003FF24: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003FF28: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8003FF2C: jal         0x80005C34
    // 0x8003FF30: nop

    Matrix_Scale(rdram, ctx);
        goto after_110;
    // 0x8003FF30: nop

    after_110:
    // 0x8003FF34: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003FF38: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8003FF3C: jal         0x80006EB8
    // 0x8003FF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_111;
    // 0x8003FF40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_111:
    // 0x8003FF44: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8003FF48: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x8003FF4C: addiu       $t6, $t6, -0x44C0
    ctx->r14 = ADD32(ctx->r14, -0X44C0);
    // 0x8003FF50: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8003FF54: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8003FF58: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8003FF5C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8003FF60: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8003FF64: b           L_80040264
    // 0x8003FF68: nop

        goto L_80040264;
    // 0x8003FF68: nop

L_8003FF6C:
    // 0x8003FF6C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8003FF70: lw          $t4, 0x7A80($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7A80);
    // 0x8003FF74: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003FF78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003FF7C: slti        $at, $t4, 0x191
    ctx->r1 = SIGNED(ctx->r12) < 0X191 ? 1 : 0;
    // 0x8003FF80: bne         $at, $zero, L_8003FFA4
    if (ctx->r1 != 0) {
        // 0x8003FF84: lwc1        $f18, 0x134($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X134);
            goto L_8003FFA4;
    }
    // 0x8003FF84: lwc1        $f18, 0x134($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X134);
    // 0x8003FF88: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8003FF8C: lbu         $t8, 0x7930($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7930);
    // 0x8003FF90: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8003FF94: bnel        $t8, $zero, L_8003FFA8
    if (ctx->r24 != 0) {
        // 0x8003FF98: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_8003FFA8;
    }
    goto skip_19;
    // 0x8003FF98: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    skip_19:
    // 0x8003FF9C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003FFA0: nop

L_8003FFA4:
    // 0x8003FFA4: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
L_8003FFA8:
    // 0x8003FFA8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003FFAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003FFB0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003FFB4: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8003FFB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003FFBC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8003FFC0: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8003FFC4: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x8003FFC8: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    // 0x8003FFCC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8003FFD0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003FFD4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8003FFD8: jal         0x80005B00
    // 0x8003FFDC: nop

    Matrix_Translate(rdram, ctx);
        goto after_112;
    // 0x8003FFDC: nop

    after_112:
    // 0x8003FFE0: lwc1        $f0, 0x128($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X128);
    // 0x8003FFE4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003FFE8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8003FFEC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8003FFF0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8003FFF4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003FFF8: jal         0x80005C34
    // 0x8003FFFC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_113;
    // 0x8003FFFC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_113:
    // 0x80040000: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80040004: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80040008: jal         0x80006EB8
    // 0x8004000C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_114;
    // 0x8004000C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_114:
    // 0x80040010: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80040014: lui         $t3, 0x601
    ctx->r11 = S32(0X601 << 16);
    // 0x80040018: addiu       $t3, $t3, -0x4B50
    ctx->r11 = ADD32(ctx->r11, -0X4B50);
    // 0x8004001C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80040020: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80040024: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80040028: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8004002C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80040030: b           L_80040264
    // 0x80040034: nop

        goto L_80040264;
    // 0x80040034: nop

L_80040038:
    // 0x80040038: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x8004003C: lw          $t2, 0x7A80($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7A80);
    // 0x80040040: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80040044: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80040048: slti        $at, $t2, 0x1F5
    ctx->r1 = SIGNED(ctx->r10) < 0X1F5 ? 1 : 0;
    // 0x8004004C: bne         $at, $zero, L_80040070
    if (ctx->r1 != 0) {
        // 0x80040050: lwc1        $f10, 0x134($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
            goto L_80040070;
    }
    // 0x80040050: lwc1        $f10, 0x134($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X134);
    // 0x80040054: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80040058: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8004005C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80040060: lw          $t4, 0x1C8($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X1C8);
    // 0x80040064: bne         $t4, $at, L_80040070
    if (ctx->r12 != ctx->r1) {
        // 0x80040068: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80040070;
    }
    // 0x80040068: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8004006C: lwc1        $f0, 0x54E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X54E0);
L_80040070:
    // 0x80040070: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80040074: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80040078: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8004007C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80040080: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80040084: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80040088: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8004008C: sub.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80040090: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x80040094: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    // 0x80040098: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8004009C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800400A0: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800400A4: jal         0x80005B00
    // 0x800400A8: nop

    Matrix_Translate(rdram, ctx);
        goto after_115;
    // 0x800400A8: nop

    after_115:
    // 0x800400AC: lwc1        $f0, 0x128($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X128);
    // 0x800400B0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800400B4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800400B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800400BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800400C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800400C4: jal         0x80005C34
    // 0x800400C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_116;
    // 0x800400C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_116:
    // 0x800400CC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800400D0: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800400D4: jal         0x80006EB8
    // 0x800400D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_117;
    // 0x800400D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_117:
    // 0x800400DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800400E0: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x800400E4: addiu       $t9, $t9, -0x2E70
    ctx->r25 = ADD32(ctx->r25, -0X2E70);
    // 0x800400E8: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800400EC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800400F0: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800400F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800400F8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800400FC: b           L_80040264
    // 0x80040100: nop

        goto L_80040264;
    // 0x80040100: nop

L_80040104:
    // 0x80040104: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80040108: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004010C: lwc1        $f6, 0x134($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X134);
    // 0x80040110: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80040114: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80040118: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004011C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80040120: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80040124: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80040128: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x8004012C: neg.s       $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = -ctx->f4.fl;
    // 0x80040130: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80040134: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80040138: jal         0x80005B00
    // 0x8004013C: nop

    Matrix_Translate(rdram, ctx);
        goto after_118;
    // 0x8004013C: nop

    after_118:
    // 0x80040140: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80040144: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80040148: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8004014C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80040150: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80040154: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80040158: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004015C: jal         0x80005C34
    // 0x80040160: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_119;
    // 0x80040160: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_119:
    // 0x80040164: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x80040168: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8004016C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80040170: jal         0x80005D44
    // 0x80040174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_120;
    // 0x80040174: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_120:
    // 0x80040178: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8004017C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80040180: jal         0x80006EB8
    // 0x80040184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_121;
    // 0x80040184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_121:
    // 0x80040188: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8004018C: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80040190: addiu       $t8, $t8, 0x2F80
    ctx->r24 = ADD32(ctx->r24, 0X2F80);
    // 0x80040194: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80040198: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8004019C: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x800401A0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800401A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800401A8: b           L_80040264
    // 0x800401AC: nop

        goto L_80040264;
    // 0x800401AC: nop

L_800401B0:
    // 0x800401B0: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800401B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800401B8: lwc1        $f8, 0x134($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X134);
    // 0x800401BC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800401C0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800401C4: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800401C8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800401CC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800401D0: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800401D4: lui         $a3, 0xC391
    ctx->r7 = S32(0XC391 << 16);
    // 0x800401D8: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x800401DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800401E0: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800401E4: jal         0x80005B00
    // 0x800401E8: nop

    Matrix_Translate(rdram, ctx);
        goto after_122;
    // 0x800401E8: nop

    after_122:
    // 0x800401EC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800401F0: lwc1        $f0, 0x54E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X54E4);
    // 0x800401F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800401F8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800401FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80040200: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80040204: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80040208: jal         0x80005C34
    // 0x8004020C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_123;
    // 0x8004020C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_123:
    // 0x80040210: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80040214: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80040218: jal         0x80006EB8
    // 0x8004021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_124;
    // 0x8004021C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_124:
    // 0x80040220: jal         0x800B94A0
    // 0x80040224: nop

    RCP_SetupDL_62(rdram, ctx);
        goto after_125;
    // 0x80040224: nop

    after_125:
    // 0x80040228: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8004022C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80040230: addiu       $t3, $zero, -0x40
    ctx->r11 = ADD32(0, -0X40);
    // 0x80040234: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80040238: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8004023C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80040240: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80040244: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80040248: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8004024C: addiu       $t4, $t4, 0x1840
    ctx->r12 = ADD32(ctx->r12, 0X1840);
    // 0x80040250: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x80040254: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80040258: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8004025C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80040260: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
L_80040264:
    // 0x80040264: jal         0x80005740
    // 0x80040268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_126;
    // 0x80040268: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_126:
L_8004026C:
    // 0x8004026C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80040270: lwc1        $f8, -0x7BEC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7BEC);
    // 0x80040274: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80040278: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8004027C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80040280: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80040284: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80040288: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8004028C: bc1f        L_80040434
    if (!c1cs) {
        // 0x80040290: nop
    
            goto L_80040434;
    }
    // 0x80040290: nop

    // 0x80040294: lw          $t8, -0x7D78($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D78);
    // 0x80040298: lw          $t5, -0x7D70($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D70);
    // 0x8004029C: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x800402A0: jal         0x800B92F8
    // 0x800402A4: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    RCP_SetupDL_14(rdram, ctx);
        goto after_127;
    // 0x800402A4: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_127:
    // 0x800402A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800402AC: lui         $t9, 0x8080
    ctx->r25 = S32(0X8080 << 16);
    // 0x800402B0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800402B4: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x800402B8: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x800402BC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800402C0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800402C4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800402C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800402CC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800402D0: addiu       $t3, $t3, -0x280
    ctx->r11 = ADD32(ctx->r11, -0X280);
    // 0x800402D4: sw          $t3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r11;
    // 0x800402D8: sw          $zero, 0x124($sp)
    MEM_W(0X124, ctx->r29) = 0;
    // 0x800402DC: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
L_800402E0:
    // 0x800402E0: jal         0x80004FE8
    // 0x800402E4: nop

    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_128;
    // 0x800402E4: nop

    after_128:
    // 0x800402E8: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x800402EC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800402F0: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800402F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800402F8: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800402FC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80040300: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80040304: jal         0x80004FE8
    // 0x80040308: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    Rand_ZeroOneSeeded(rdram, ctx);
        goto after_129;
    // 0x80040308: swc1        $f8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f8.u32l;
    after_129:
    // 0x8004030C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80040310: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040314: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80040318: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004031C: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80040320: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80040324: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80040328: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x8004032C: jal         0x80005708
    // 0x80040330: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    Matrix_Push(rdram, ctx);
        goto after_130;
    // 0x80040330: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    after_130:
    // 0x80040334: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80040338: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8004033C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80040340: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80040344: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80040348: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8004034C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80040350: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x80040354: sub.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80040358: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004035C: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80040360: lui         $a3, 0xC59C
    ctx->r7 = S32(0XC59C << 16);
    // 0x80040364: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80040368: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8004036C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80040370: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80040374: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80040378: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8004037C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80040380: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80040384: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80040388: jal         0x80005B00
    // 0x8004038C: nop

    Matrix_Translate(rdram, ctx);
        goto after_131;
    // 0x8004038C: nop

    after_131:
    // 0x80040390: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80040394: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80040398: jal         0x80005FE0
    // 0x8004039C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_132;
    // 0x8004039C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_132:
    // 0x800403A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800403A4: lwc1        $f10, -0x7BEC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7BEC);
    // 0x800403A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800403AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800403B0: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800403B4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800403B8: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800403BC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x800403C0: jal         0x80005C34
    // 0x800403C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_133;
    // 0x800403C4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_133:
    // 0x800403C8: jal         0x80006EB8
    // 0x800403CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_134;
    // 0x800403CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_134:
    // 0x800403D0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800403D4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x800403D8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800403DC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800403E0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800403E4: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800403E8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x800403EC: jal         0x80005740
    // 0x800403F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_135;
    // 0x800403F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_135:
    // 0x800403F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800403F8: lwc1        $f4, 0x54E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X54E8);
    // 0x800403FC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80040400: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x80040404: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80040408: lw          $v0, 0x124($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X124);
    // 0x8004040C: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80040410: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x80040414: addiu       $t6, $t2, 0x4
    ctx->r14 = ADD32(ctx->r10, 0X4);
    // 0x80040418: addiu       $t8, $t4, 0x4
    ctx->r24 = ADD32(ctx->r12, 0X4);
    // 0x8004041C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80040420: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x80040424: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80040428: sw          $t6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r14;
    // 0x8004042C: bne         $v0, $at, L_800402E0
    if (ctx->r2 != ctx->r1) {
        // 0x80040430: swc1        $f18, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
            goto L_800402E0;
    }
    // 0x80040430: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
L_80040434:
    // 0x80040434: jal         0x80005740
    // 0x80040438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_136;
    // 0x80040438: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_136:
L_8004043C:
    // 0x8004043C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80040440: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80040444: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80040448: jr          $ra
    // 0x8004044C: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x8004044C: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void Lib_TextureRect_IA16_MirXY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EFDC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009EFE0: lui         $t1, 0xF570
    ctx->r9 = S32(0XF570 << 16);
    // 0x8009EFE4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8009EFE8: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8009EFEC: sll         $t3, $a2, 1
    ctx->r11 = S32(ctx->r6 << 1);
    // 0x8009EFF0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8009EFF4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009EFF8: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x8009EFFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8009F000: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F004: lui         $t9, 0x704
    ctx->r25 = S32(0X704 << 16);
    // 0x8009F008: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8009F00C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009F010: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009F014: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009F018: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8009F01C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F020: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8009F024: addiu       $v1, $a2, -0x1
    ctx->r3 = ADD32(ctx->r6, -0X1);
    // 0x8009F028: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009F02C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F030: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8009F034: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009F038: multu       $a2, $a3
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009F03C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F040: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8009F044: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x8009F048: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009F04C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009F050: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009F054: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8009F058: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
    // 0x8009F05C: mflo        $v0
    ctx->r2 = lo;
    // 0x8009F060: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8009F064: sltiu       $at, $v0, 0x7FF
    ctx->r1 = ctx->r2 < 0X7FF ? 1 : 0;
    // 0x8009F068: beql        $at, $zero, L_8009F07C
    if (ctx->r1 == 0) {
        // 0x8009F06C: addiu       $t2, $zero, 0x7FF
        ctx->r10 = ADD32(0, 0X7FF);
            goto L_8009F07C;
    }
    goto skip_0;
    // 0x8009F06C: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
    skip_0:
    // 0x8009F070: b           L_8009F07C
    // 0x8009F074: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
        goto L_8009F07C;
    // 0x8009F074: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x8009F078: addiu       $t2, $zero, 0x7FF
    ctx->r10 = ADD32(0, 0X7FF);
L_8009F07C:
    // 0x8009F07C: srl         $v0, $t3, 3
    ctx->r2 = S32(U32(ctx->r11) >> 3);
    // 0x8009F080: bne         $v0, $zero, L_8009F090
    if (ctx->r2 != 0) {
        // 0x8009F084: lui         $at, 0x700
        ctx->r1 = S32(0X700 << 16);
            goto L_8009F090;
    }
    // 0x8009F084: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8009F088: b           L_8009F094
    // 0x8009F08C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
        goto L_8009F094;
    // 0x8009F08C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
L_8009F090:
    // 0x8009F090: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8009F094:
    // 0x8009F094: bne         $v0, $zero, L_8009F0A4
    if (ctx->r2 != 0) {
        // 0x8009F098: addiu       $t6, $t4, 0x7FF
        ctx->r14 = ADD32(ctx->r12, 0X7FF);
            goto L_8009F0A4;
    }
    // 0x8009F098: addiu       $t6, $t4, 0x7FF
    ctx->r14 = ADD32(ctx->r12, 0X7FF);
    // 0x8009F09C: b           L_8009F0A8
    // 0x8009F0A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
        goto L_8009F0A8;
    // 0x8009F0A0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8009F0A4:
    // 0x8009F0A4: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
L_8009F0A8:
    // 0x8009F0A8: divu        $zero, $t6, $t5
    lo = S32(U32(ctx->r14) / U32(ctx->r13)); hi = S32(U32(ctx->r14) % U32(ctx->r13));
    // 0x8009F0AC: mflo        $t7
    ctx->r15 = lo;
    // 0x8009F0B0: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8009F0B4: andi        $t6, $t2, 0xFFF
    ctx->r14 = ctx->r10 & 0XFFF;
    // 0x8009F0B8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8009F0BC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8009F0C0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8009F0C4: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8009F0C8: bne         $t5, $zero, L_8009F0D4
    if (ctx->r13 != 0) {
        // 0x8009F0CC: nop
    
            goto L_8009F0D4;
    }
    // 0x8009F0CC: nop

    // 0x8009F0D0: break       7
    do_break(2148135120);
L_8009F0D4:
    // 0x8009F0D4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F0D8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8009F0DC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8009F0E0: sw          $v0, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r2;
    // 0x8009F0E4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009F0E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F0EC: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8009F0F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009F0F4: addiu       $t6, $t3, 0x7
    ctx->r14 = ADD32(ctx->r11, 0X7);
    // 0x8009F0F8: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x8009F0FC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8009F100: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F104: srl         $t9, $t6, 3
    ctx->r25 = S32(U32(ctx->r14) >> 3);
    // 0x8009F108: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8009F10C: sw          $v0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r2;
    // 0x8009F110: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009F114: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009F118: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8009F11C: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8009F120: lui         $t7, 0x4
    ctx->r15 = S32(0X4 << 16);
    // 0x8009F124: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x8009F128: or          $t6, $t8, $t1
    ctx->r14 = ctx->r24 | ctx->r9;
    // 0x8009F12C: sw          $t6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r14;
    // 0x8009F130: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8009F134: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F138: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8009F13C: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8009F140: sw          $v0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r2;
    // 0x8009F144: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009F148: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009F14C: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8009F150: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8009F154: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8009F158: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8009F15C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8009F160: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8009F164: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8009F168: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8009F16C: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8009F170: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8009F174: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8009F178: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8009F17C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8009F180: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009F184: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009F188: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x8009F18C: bgez        $a2, L_8009F1A0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x8009F190: sw          $t6, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r14;
            goto L_8009F1A0;
    }
    // 0x8009F190: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8009F194: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8009F198: nop

    // 0x8009F19C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8009F1A0:
    // 0x8009F1A0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8009F1A4: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x8009F1A8: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x8009F1AC: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8009F1B0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009F1B4: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8009F1B8: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8009F1BC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x8009F1C0: nop

    // 0x8009F1C4: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8009F1C8: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8009F1CC: bgez        $a3, L_8009F1E4
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8009F1D0: or          $t8, $t6, $at
        ctx->r24 = ctx->r14 | ctx->r1;
            goto L_8009F1E4;
    }
    // 0x8009F1D0: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8009F1D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8009F1D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8009F1DC: nop

    // 0x8009F1E0: add.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f18.fl;
L_8009F1E4:
    // 0x8009F1E4: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8009F1E8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8009F1EC: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x8009F1F0: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8009F1F4: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009F1F8: mul.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8009F1FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009F200: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x8009F204: mul.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8009F208: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8009F20C: nop

    // 0x8009F210: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8009F214: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8009F218: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009F21C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8009F220: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8009F224: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009F228: div.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8009F22C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009F230: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8009F234: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8009F238: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8009F23C: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8009F240: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8009F244: div.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8009F248: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F24C: lui         $t9, 0xB400
    ctx->r25 = S32(0XB400 << 16);
    // 0x8009F250: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009F254: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8009F258: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8009F25C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8009F260: sll         $t9, $a1, 5
    ctx->r25 = S32(ctx->r5 << 5);
    // 0x8009F264: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x8009F268: sll         $t8, $v1, 21
    ctx->r24 = S32(ctx->r3 << 21);
    // 0x8009F26C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8009F270: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009F274: mul.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8009F278: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009F27C: lui         $t8, 0xB300
    ctx->r24 = S32(0XB300 << 16);
    // 0x8009F280: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8009F284: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8009F288: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8009F28C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8009F290: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8009F294: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8009F298: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8009F29C: nop

    // 0x8009F2A0: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x8009F2A4: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8009F2A8: nop

    // 0x8009F2AC: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x8009F2B0: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8009F2B4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8009F2B8: jr          $ra
    // 0x8009F2BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8009F2BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Display_Reticle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053F7C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80053F80: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80053F84: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80053F88: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80053F8C: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x80053F90: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80053F94: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80053F98: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80053F9C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80053FA0: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80053FA4: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80053FA8: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80053FAC: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80053FB0: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80053FB4: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80053FB8: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80053FBC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80053FC0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80053FC4: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80053FC8: lw          $t6, 0x78A0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A0);
    // 0x80053FCC: lw          $t7, 0x1C4($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X1C4);
    // 0x80053FD0: bnel        $t6, $t7, L_8005423C
    if (ctx->r14 != ctx->r15) {
        // 0x80053FD4: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_8005423C;
    }
    goto skip_0;
    // 0x80053FD4: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x80053FD8: lw          $v0, 0x1CC($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X1CC);
    // 0x80053FDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80053FE0: beql        $v0, $zero, L_80053FF4
    if (ctx->r2 == 0) {
        // 0x80053FE4: lw          $t8, 0x234($s4)
        ctx->r24 = MEM_W(ctx->r20, 0X234);
            goto L_80053FF4;
    }
    goto skip_1;
    // 0x80053FE4: lw          $t8, 0x234($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X234);
    skip_1:
    // 0x80053FE8: bnel        $v0, $at, L_8005423C
    if (ctx->r2 != ctx->r1) {
        // 0x80053FEC: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_8005423C;
    }
    goto skip_2;
    // 0x80053FEC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_2:
    // 0x80053FF0: lw          $t8, 0x234($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X234);
L_80053FF4:
    // 0x80053FF4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80053FF8: beql        $t8, $zero, L_8005423C
    if (ctx->r24 == 0) {
        // 0x80053FFC: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_8005423C;
    }
    goto skip_3;
    // 0x80053FFC: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_3:
    // 0x80054000: lw          $v0, 0x7834($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7834);
    // 0x80054004: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80054008: bnel        $v0, $at, L_80054020
    if (ctx->r2 != ctx->r1) {
        // 0x8005400C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80054020;
    }
    goto skip_4;
    // 0x8005400C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_4:
    // 0x80054010: lw          $t9, 0x1C8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X1C8);
    // 0x80054014: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80054018: beq         $t9, $at, L_80054024
    if (ctx->r25 == ctx->r1) {
        // 0x8005401C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80054024;
    }
    // 0x8005401C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80054020:
    // 0x80054020: bne         $v0, $at, L_80054238
    if (ctx->r2 != ctx->r1) {
        // 0x80054024: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80054238;
    }
L_80054024:
    // 0x80054024: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054028: lwc1        $f30, 0x5E8C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X5E8C);
    // 0x8005402C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80054030: lwc1        $f28, 0x5E90($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X5E90);
    // 0x80054034: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80054038: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8005403C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80054040: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80054044: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80054048: lui         $t1, 0x102
    ctx->r9 = S32(0X102 << 16);
    // 0x8005404C: addiu       $t1, $t1, 0x4F60
    ctx->r9 = ADD32(ctx->r9, 0X4F60);
    // 0x80054050: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x80054054: lui         $fp, 0xFFFF
    ctx->r30 = S32(0XFFFF << 16);
    // 0x80054058: lui         $s6, 0xFF00
    ctx->r22 = S32(0XFF00 << 16);
    // 0x8005405C: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x80054060: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80054064: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80054068: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8005406C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80054070: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80054074: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x80054078: addiu       $s3, $s3, -0x5D68
    ctx->r19 = ADD32(ctx->r19, -0X5D68);
    // 0x8005407C: ori         $s6, $s6, 0xFF
    ctx->r22 = ctx->r22 | 0XFF;
    // 0x80054080: ori         $fp, $fp, 0xFF
    ctx->r30 = ctx->r30 | 0XFF;
    // 0x80054084: addiu       $s1, $s1, 0x13E0
    ctx->r17 = ADD32(ctx->r17, 0X13E0);
    // 0x80054088: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8005408C: lui         $s7, 0xFB00
    ctx->r23 = S32(0XFB00 << 16);
    // 0x80054090: lui         $s5, 0xFA00
    ctx->r21 = S32(0XFA00 << 16);
L_80054094:
    // 0x80054094: jal         0x80005708
    // 0x80054098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x80054098: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8005409C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800540A0: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800540A4: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800540A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800540AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800540B0: jal         0x80005B00
    // 0x800540B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x800540B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x800540B8: lw          $t3, 0x1C4($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X1C4);
    // 0x800540BC: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800540C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800540C4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800540C8: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800540CC: lw          $t5, 0x79C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X79C8);
    // 0x800540D0: slti        $at, $t5, 0x14
    ctx->r1 = SIGNED(ctx->r13) < 0X14 ? 1 : 0;
    // 0x800540D4: bne         $at, $zero, L_80054174
    if (ctx->r1 != 0) {
        // 0x800540D8: nop
    
            goto L_80054174;
    }
    // 0x800540D8: nop

    // 0x800540DC: jal         0x800B8DD0
    // 0x800540E0: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x800540E0: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x800540E4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x800540E8: addiu       $t6, $t6, 0x13EC
    ctx->r14 = ADD32(ctx->r14, 0X13EC);
    // 0x800540EC: bnel        $s1, $t6, L_80054148
    if (ctx->r17 != ctx->r14) {
        // 0x800540F0: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_80054148;
    }
    goto skip_5;
    // 0x800540F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x800540F4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800540F8: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x800540FC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80054100: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80054104: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80054108: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x8005410C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80054110: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054114: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80054118: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005411C: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x80054120: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80054124: lw          $t9, 0x1C4($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X1C4);
    // 0x80054128: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8005412C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80054130: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80054134: jal         0x8009BC2C
    // 0x80054138: addu        $a0, $s3, $t1
    ctx->r4 = ADD32(ctx->r19, ctx->r9);
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80054138: addu        $a0, $s3, $t1
    ctx->r4 = ADD32(ctx->r19, ctx->r9);
    after_3:
    // 0x8005413C: b           L_8005417C
    // 0x80054140: nop

        goto L_8005417C;
    // 0x80054140: nop

    // 0x80054144: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80054148:
    // 0x80054148: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8005414C: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80054150: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x80054154: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80054158: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005415C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80054160: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80054164: sw          $fp, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r30;
    // 0x80054168: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x8005416C: b           L_8005417C
    // 0x80054170: nop

        goto L_8005417C;
    // 0x80054170: nop

L_80054174:
    // 0x80054174: jal         0x800B9358
    // 0x80054178: nop

    RCP_SetupDL_36(rdram, ctx);
        goto after_4;
    // 0x80054178: nop

    after_4:
L_8005417C:
    // 0x8005417C: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x80054180: addiu       $t4, $t4, 0x13EC
    ctx->r12 = ADD32(ctx->r12, 0X13EC);
    // 0x80054184: bnel        $s1, $t4, L_800541E0
    if (ctx->r17 != ctx->r12) {
        // 0x80054188: mfc1        $a1, $f22
        ctx->r5 = (int32_t)ctx->f22.u32l;
            goto L_800541E0;
    }
    goto skip_6;
    // 0x80054188: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    skip_6:
    // 0x8005418C: lw          $t5, 0x1C4($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X1C4);
    // 0x80054190: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80054194: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80054198: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8005419C: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x800541A0: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800541A4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800541A8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800541AC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800541B0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800541B4: jal         0x80005C34
    // 0x800541B8: nop

    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x800541B8: nop

    after_5:
    // 0x800541BC: lw          $t9, 0x1C4($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X1C4);
    // 0x800541C0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800541C4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800541C8: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x800541CC: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800541D0: addu        $a0, $s3, $t1
    ctx->r4 = ADD32(ctx->r19, ctx->r9);
    // 0x800541D4: jal         0x8009BC2C
    // 0x800541D8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800541D8: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_6:
    // 0x800541DC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
L_800541E0:
    // 0x800541E0: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800541E4: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800541E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800541EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800541F0: jal         0x80005C34
    // 0x800541F4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x800541F4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_7:
    // 0x800541F8: jal         0x80006EB8
    // 0x800541FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x800541FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x80054200: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80054204: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x80054208: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005420C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80054210: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80054214: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80054218: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005421C: jal         0x80005740
    // 0x80054220: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x80054220: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x80054224: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80054228: addiu       $t6, $t6, 0x13F8
    ctx->r14 = ADD32(ctx->r14, 0X13F8);
    // 0x8005422C: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x80054230: bne         $s1, $t6, L_80054094
    if (ctx->r17 != ctx->r14) {
        // 0x80054234: nop
    
            goto L_80054094;
    }
    // 0x80054234: nop

L_80054238:
    // 0x80054238: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_8005423C:
    // 0x8005423C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80054240: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80054244: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80054248: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8005424C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80054250: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80054254: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80054258: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x8005425C: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80054260: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80054264: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80054268: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x8005426C: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80054270: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80054274: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80054278: jr          $ra
    // 0x8005427C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8005427C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Scenery_UpdateTitaniaBones(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800652CC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800652D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800652D4: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x800652D8: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x800652DC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800652E0: bnel        $t6, $at, L_80065374
    if (ctx->r14 != ctx->r1) {
        // 0x800652E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80065374;
    }
    goto skip_0;
    // 0x800652E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800652E8: lw          $t7, 0x48($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X48);
    // 0x800652EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800652F0: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x800652F4: bne         $t7, $zero, L_80065370
    if (ctx->r15 != 0) {
        // 0x800652F8: addiu       $a3, $sp, 0x24
        ctx->r7 = ADD32(ctx->r29, 0X24);
            goto L_80065370;
    }
    // 0x800652F8: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x800652FC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80065300: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80065304: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80065308: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x8006530C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80065310: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80065314: jal         0x801B6E20
    // 0x80065318: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_0;
    // 0x80065318: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8006531C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80065320: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80065324: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80065328: lwc1        $f2, 0x6878($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6878);
    // 0x8006532C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80065330: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80065334: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065338: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8006533C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80065340: lw          $t9, 0x48($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X48);
    // 0x80065344: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80065348: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8006534C: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80065350: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80065354: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80065358: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x8006535C: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80065360: sw          $t0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r8;
    // 0x80065364: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80065368: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006536C: swc1        $f16, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f16.u32l;
L_80065370:
    // 0x80065370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80065374:
    // 0x80065374: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80065378: jr          $ra
    // 0x8006537C: nop

    return;
    // 0x8006537C: nop

;}
RECOMP_FUNC void Display_OnFootFalco_PostLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005250C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80052510: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052514: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80052518: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8005251C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80052520: bne         $a0, $at, L_80052574
    if (ctx->r4 != ctx->r1) {
        // 0x80052524: addiu       $a1, $sp, 0x1C
        ctx->r5 = ADD32(ctx->r29, 0X1C);
            goto L_80052574;
    }
    // 0x80052524: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80052528: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x8005252C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80052530: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80052534: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80052538: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8005253C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80052540: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x80052544: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x80052548: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8005254C: lw          $t6, 0x1C4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X1C4);
    // 0x80052550: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80052554: addiu       $t8, $t8, 0x13B0
    ctx->r24 = ADD32(ctx->r24, 0X13B0);
    // 0x80052558: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005255C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80052560: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80052564: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80052568: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005256C: jal         0x80006970
    // 0x80052570: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x80052570: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_0:
L_80052574:
    // 0x80052574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80052578: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8005257C: jr          $ra
    // 0x80052580: nop

    return;
    // 0x80052580: nop

;}
RECOMP_FUNC void Fault_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000801C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80008020: addiu       $v0, $v0, 0x5360
    ctx->r2 = ADD32(ctx->r2, 0X5360);
    // 0x80008024: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80008028: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8000802C: lw          $t6, 0x318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X318);
    // 0x80008030: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80008034: addiu       $t9, $zero, 0x140
    ctx->r25 = ADD32(0, 0X140);
    // 0x80008038: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8000803C: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80008040: ori         $at, $at, 0xA800
    ctx->r1 = ctx->r1 | 0XA800;
    // 0x80008044: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x80008048: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x8000804C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80008050: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80008054: sw          $t8, 0x9CC($v0)
    MEM_W(0X9CC, ctx->r2) = ctx->r24;
    // 0x80008058: sh          $t9, 0x9D0($v0)
    MEM_H(0X9D0, ctx->r2) = ctx->r25;
    // 0x8000805C: sh          $t0, 0x9D2($v0)
    MEM_H(0X9D2, ctx->r2) = ctx->r8;
    // 0x80008060: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80008064: addiu       $a0, $a0, 0x5D10
    ctx->r4 = ADD32(ctx->r4, 0X5D10);
    // 0x80008068: jal         0x80021CF0
    // 0x8000806C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8000806C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80008070: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80008074: addiu       $t1, $t1, 0x5D10
    ctx->r9 = ADD32(ctx->r9, 0X5D10);
    // 0x80008078: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8000807C: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80008080: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x80008084: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80008088: addiu       $a2, $a2, 0x7D58
    ctx->r6 = ADD32(ctx->r6, 0X7D58);
    // 0x8000808C: addiu       $a0, $a0, 0x5360
    ctx->r4 = ADD32(ctx->r4, 0X5360);
    // 0x80008090: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80008094: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80008098: jal         0x800221A0
    // 0x8000809C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x8000809C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800080A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800080A4: jal         0x800222F0
    // 0x800080A8: addiu       $a0, $a0, 0x5360
    ctx->r4 = ADD32(ctx->r4, 0X5360);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x800080A8: addiu       $a0, $a0, 0x5360
    ctx->r4 = ADD32(ctx->r4, 0X5360);
    after_2:
    // 0x800080AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800080B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800080B4: jr          $ra
    // 0x800080B8: nop

    return;
    // 0x800080B8: nop

;}
RECOMP_FUNC void AudioLoad_DmaSlowCopyUnkMedium(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80010A80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80010A84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80010A88: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80010A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80010A90: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80010A94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80010A98: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80010A9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80010AA0: jal         0x80021740
    // 0x80010AA4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80010AA4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80010AA8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80010AAC: jal         0x8000FC7C
    // 0x80010AB0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    func_8000FC7C(rdram, ctx);
        goto after_1;
    // 0x80010AB0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_1:
    // 0x80010AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80010AB8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80010ABC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80010AC0: jal         0x8000FC8C
    // 0x80010AC4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    func_8000FC8C(rdram, ctx);
        goto after_2;
    // 0x80010AC4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80010AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010ACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80010AD0: jr          $ra
    // 0x80010AD4: nop

    return;
    // 0x80010AD4: nop

;}
RECOMP_FUNC void ActorAllRange_DrawShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005EA24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8005EA28: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8005EA2C: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8005EA30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005EA34: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8005EA38: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8005EA3C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005EA40: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8005EA44: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8005EA48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005EA4C: lwc1        $f4, 0x178($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X178);
    // 0x8005EA50: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8005EA54: lw          $a3, 0xC($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XC);
    // 0x8005EA58: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005EA5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005EA60: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005EA64: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005EA68: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8005EA6C: jal         0x80005B00
    // 0x8005EA70: nop

    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x8005EA70: nop

    after_0:
    // 0x8005EA74: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8005EA78: lw          $t7, -0x7DCC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7DCC);
    // 0x8005EA7C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8005EA80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005EA84: bne         $t7, $at, L_8005EAD4
    if (ctx->r15 != ctx->r1) {
        // 0x8005EA88: nop
    
            goto L_8005EAD4;
    }
    // 0x8005EA88: nop

    // 0x8005EA8C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005EA90: jal         0x80005E90
    // 0x8005EA94: lw          $a1, 0x180($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X180);
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x8005EA94: lw          $a1, 0x180($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X180);
    after_1:
    // 0x8005EA98: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005EA9C: lw          $a1, 0x17C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X17C);
    // 0x8005EAA0: jal         0x80005D44
    // 0x8005EAA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x8005EAA4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x8005EAA8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005EAAC: lw          $a1, 0x184($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X184);
    // 0x8005EAB0: jal         0x80005FE0
    // 0x8005EAB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x8005EAB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8005EAB8: lwc1        $f10, 0x180($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X180);
    // 0x8005EABC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005EAC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005EAC4: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8005EAC8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8005EACC: jal         0x80005E90
    // 0x8005EAD0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_4;
    // 0x8005EAD0: nop

    after_4:
L_8005EAD4:
    // 0x8005EAD4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005EAD8: lwc1        $f0, 0x635C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X635C);
    // 0x8005EADC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005EAE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005EAE4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005EAE8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005EAEC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005EAF0: jal         0x80005C34
    // 0x8005EAF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x8005EAF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_5:
    // 0x8005EAF8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8005EAFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005EB00: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8005EB04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005EB08: lwc1        $f8, 0x6360($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6360);
    // 0x8005EB0C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8005EB10: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005EB14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005EB18: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8005EB1C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005EB20: jal         0x80005E90
    // 0x8005EB24: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x8005EB24: nop

    after_6:
    // 0x8005EB28: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005EB2C: lwc1        $f18, 0x6364($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6364);
    // 0x8005EB30: lwc1        $f16, 0x18($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8005EB34: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8005EB38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005EB3C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005EB40: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8005EB44: jal         0x80005FE0
    // 0x8005EB48: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x8005EB48: nop

    after_7:
    // 0x8005EB4C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8005EB50: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x8005EB54: jal         0x80006EB8
    // 0x8005EB58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x8005EB58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8005EB5C: lh          $v1, 0xE4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XE4);
    // 0x8005EB60: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    // 0x8005EB64: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8005EB68: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8005EB6C: beq         $at, $zero, L_8005EBC0
    if (ctx->r1 == 0) {
        // 0x8005EB70: nop
    
            goto L_8005EBC0;
    }
    // 0x8005EB70: nop

    // 0x8005EB74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005EB78: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005EB7C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005EB80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005EB84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005EB88: jal         0x80005B00
    // 0x8005EB8C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x8005EB8C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_9:
    // 0x8005EB90: jal         0x80006EB8
    // 0x8005EB94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x8005EB94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8005EB98: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005EB9C: lui         $t2, 0x103
    ctx->r10 = S32(0X103 << 16);
    // 0x8005EBA0: addiu       $t2, $t2, 0x2780
    ctx->r10 = ADD32(ctx->r10, 0X2780);
    // 0x8005EBA4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8005EBA8: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x8005EBAC: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x8005EBB0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8005EBB4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005EBB8: b           L_8005ECC4
    // 0x8005EBBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8005ECC4;
    // 0x8005EBBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005EBC0:
    // 0x8005EBC0: lw          $v0, -0x7DCC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DCC);
    // 0x8005EBC4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8005EBC8: bnel        $v0, $at, L_8005EC38
    if (ctx->r2 != ctx->r1) {
        // 0x8005EBCC: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_8005EC38;
    }
    goto skip_0;
    // 0x8005EBCC: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    skip_0:
    // 0x8005EBD0: lh          $v0, 0xB6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XB6);
    // 0x8005EBD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EBD8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005EBDC: beq         $v0, $at, L_8005EBEC
    if (ctx->r2 == ctx->r1) {
        // 0x8005EBE0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8005EBEC;
    }
    // 0x8005EBE0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005EBE4: bne         $v0, $at, L_8005EC10
    if (ctx->r2 != ctx->r1) {
        // 0x8005EBE8: lui         $t7, 0x600
        ctx->r15 = S32(0X600 << 16);
            goto L_8005EC10;
    }
    // 0x8005EBE8: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
L_8005EBEC:
    // 0x8005EBEC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005EBF0: lui         $t5, 0x601
    ctx->r13 = S32(0X601 << 16);
    // 0x8005EBF4: addiu       $t5, $t5, -0x28D0
    ctx->r13 = ADD32(ctx->r13, -0X28D0);
    // 0x8005EBF8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005EBFC: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8005EC00: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005EC04: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005EC08: b           L_8005ECC4
    // 0x8005EC0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8005ECC4;
    // 0x8005EC0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005EC10:
    // 0x8005EC10: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005EC14: lui         $t8, 0x601
    ctx->r24 = S32(0X601 << 16);
    // 0x8005EC18: addiu       $t8, $t8, -0x2440
    ctx->r24 = ADD32(ctx->r24, -0X2440);
    // 0x8005EC1C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005EC20: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8005EC24: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005EC28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005EC2C: b           L_8005ECC4
    // 0x8005EC30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8005ECC4;
    // 0x8005EC30: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EC34: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_8005EC38:
    // 0x8005EC38: bne         $at, $zero, L_8005EC4C
    if (ctx->r1 != 0) {
        // 0x8005EC3C: lui         $t0, 0x600
        ctx->r8 = S32(0X600 << 16);
            goto L_8005EC4C;
    }
    // 0x8005EC3C: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x8005EC40: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8005EC44: beql        $v0, $at, L_8005EC74
    if (ctx->r2 == ctx->r1) {
        // 0x8005EC48: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8005EC74;
    }
    goto skip_1;
    // 0x8005EC48: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    skip_1:
L_8005EC4C:
    // 0x8005EC4C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005EC50: lui         $t1, 0xF01
    ctx->r9 = S32(0XF01 << 16);
    // 0x8005EC54: addiu       $t1, $t1, 0x4310
    ctx->r9 = ADD32(ctx->r9, 0X4310);
    // 0x8005EC58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005EC5C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8005EC60: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8005EC64: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8005EC68: b           L_8005ECC4
    // 0x8005EC6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8005ECC4;
    // 0x8005EC6C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EC70: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
L_8005EC74:
    // 0x8005EC74: bne         $v0, $at, L_8005ECA4
    if (ctx->r2 != ctx->r1) {
        // 0x8005EC78: lui         $t6, 0x600
        ctx->r14 = S32(0X600 << 16);
            goto L_8005ECA4;
    }
    // 0x8005EC78: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8005EC7C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005EC80: lui         $t4, 0x601
    ctx->r12 = S32(0X601 << 16);
    // 0x8005EC84: addiu       $t4, $t4, -0x6070
    ctx->r12 = ADD32(ctx->r12, -0X6070);
    // 0x8005EC88: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8005EC8C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8005EC90: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8005EC94: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005EC98: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005EC9C: b           L_8005ECC4
    // 0x8005ECA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8005ECC4;
    // 0x8005ECA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005ECA4:
    // 0x8005ECA4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8005ECA8: lui         $t7, 0xF01
    ctx->r15 = S32(0XF01 << 16);
    // 0x8005ECAC: addiu       $t7, $t7, 0x4310
    ctx->r15 = ADD32(ctx->r15, 0X4310);
    // 0x8005ECB0: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005ECB4: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8005ECB8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005ECBC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005ECC0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005ECC4:
    // 0x8005ECC4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005ECC8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005ECCC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8005ECD0: jr          $ra
    // 0x8005ECD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8005ECD4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void BonusText_Display(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077240: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80077244: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80077248: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007724C: addiu       $v0, $v0, 0x6550
    ctx->r2 = ADD32(ctx->r2, 0X6550);
    // 0x80077250: addiu       $v1, $v1, 0x6438
    ctx->r3 = ADD32(ctx->r3, 0X6438);
    // 0x80077254: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
L_80077258:
    // 0x80077258: bnel        $t6, $zero, L_8007728C
    if (ctx->r14 != 0) {
        // 0x8007725C: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_8007728C;
    }
    goto skip_0;
    // 0x8007725C: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    skip_0:
    // 0x80077260: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80077264: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80077268: addiu       $t7, $zero, 0x41
    ctx->r15 = ADD32(0, 0X41);
    // 0x8007726C: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x80077270: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80077274: swc1        $f14, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f14.u32l;
    // 0x80077278: sh          $t7, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r15;
    // 0x8007727C: swc1        $f4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f4.u32l;
    // 0x80077280: jr          $ra
    // 0x80077284: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
    return;
    // 0x80077284: swc1        $f6, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f6.u32l;
    // 0x80077288: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
L_8007728C:
    // 0x8007728C: bnel        $v1, $v0, L_80077258
    if (ctx->r3 != ctx->r2) {
        // 0x80077290: lbu         $t6, 0x0($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X0);
            goto L_80077258;
    }
    goto skip_1;
    // 0x80077290: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    skip_1:
    // 0x80077294: jr          $ra
    // 0x80077298: nop

    return;
    // 0x80077298: nop

;}
RECOMP_FUNC void HUD_PauseScreenInput(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800886B8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800886BC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x800886C0: lw          $t6, 0x797C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X797C);
    // 0x800886C4: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800886C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800886CC: lb          $t7, 0x3($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X3);
    // 0x800886D0: addiu       $v0, $v0, 0x1810
    ctx->r2 = ADD32(ctx->r2, 0X1810);
    // 0x800886D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800886D8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800886DC: nop

    // 0x800886E0: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800886E4: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    // 0x800886E8: nop

    // 0x800886EC: bc1tl       L_8008870C
    if (c1cs) {
        // 0x800886F0: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8008870C;
    }
    goto skip_0;
    // 0x800886F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_0:
    // 0x800886F4: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x800886F8: beql        $t8, $zero, L_8008870C
    if (ctx->r24 == 0) {
        // 0x800886FC: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_8008870C;
    }
    goto skip_1;
    // 0x800886FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80088700: jr          $ra
    // 0x80088704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80088704: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80088708: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_8008870C:
    // 0x8008870C: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x80088710: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80088714: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80088718: addiu       $v0, $v0, 0x1810
    ctx->r2 = ADD32(ctx->r2, 0X1810);
    // 0x8008871C: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x80088720: bc1fl       L_80088730
    if (!c1cs) {
        // 0x80088724: c.eq.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
            goto L_80088730;
    }
    goto skip_2;
    // 0x80088724: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
    skip_2:
    // 0x80088728: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8008872C: c.eq.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl == ctx->f12.fl;
L_80088730:
    // 0x80088730: nop

    // 0x80088734: bc1tl       L_80088778
    if (c1cs) {
        // 0x80088738: sw          $zero, 0x8($v0)
        MEM_W(0X8, ctx->r2) = 0;
            goto L_80088778;
    }
    goto skip_3;
    // 0x80088738: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    skip_3:
    // 0x8008873C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80088740: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80088744: bnel        $t9, $zero, L_8008877C
    if (ctx->r25 != 0) {
        // 0x80088748: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8008877C;
    }
    goto skip_4;
    // 0x80088748: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x8008874C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80088750: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80088754: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80088758: nop

    // 0x8008875C: bc1f        L_8008876C
    if (!c1cs) {
        // 0x80088760: nop
    
            goto L_8008876C;
    }
    // 0x80088760: nop

    // 0x80088764: b           L_8008876C
    // 0x80088768: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8008876C;
    // 0x80088768: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8008876C:
    // 0x8008876C: b           L_80088778
    // 0x80088770: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
        goto L_80088778;
    // 0x80088770: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x80088774: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
L_80088778:
    // 0x80088778: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8008877C:
    // 0x8008877C: jr          $ra
    // 0x80088780: nop

    return;
    // 0x80088780: nop

;}
RECOMP_FUNC void AudioHeap_AllocPersistentSampleCacheEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E208: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E20C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000E210: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E214: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8000E218: addiu       $a0, $a0, -0x36C0
    ctx->r4 = ADD32(ctx->r4, -0X36C0);
    // 0x8000E21C: jal         0x8000BF14
    // 0x8000E220: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    AudioHeap_Alloc(rdram, ctx);
        goto after_0;
    // 0x8000E220: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x8000E224: bne         $v0, $zero, L_8000E234
    if (ctx->r2 != 0) {
        // 0x8000E228: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8000E234;
    }
    // 0x8000E228: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8000E22C: b           L_8000E280
    // 0x8000E230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000E280;
    // 0x8000E230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E234:
    // 0x8000E234: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8000E238: lw          $t6, -0x31B0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X31B0);
    // 0x8000E23C: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000E240: addiu       $t9, $t9, -0x36C0
    ctx->r25 = ADD32(ctx->r25, -0X36C0);
    // 0x8000E244: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000E248: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8000E24C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000E250: addiu       $t8, $t7, 0x10
    ctx->r24 = ADD32(ctx->r15, 0X10);
    // 0x8000E254: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8000E258: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000E25C: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x8000E260: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x8000E264: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x8000E268: lui         $t2, 0x8015
    ctx->r10 = S32(0X8015 << 16);
    // 0x8000E26C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x8000E270: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x8000E274: lw          $t2, -0x31B0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X31B0);
    // 0x8000E278: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8000E27C: sw          $t3, -0x31B0($at)
    MEM_W(-0X31B0, ctx->r1) = ctx->r11;
L_8000E280:
    // 0x8000E280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E284: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000E288: jr          $ra
    // 0x8000E28C: nop

    return;
    // 0x8000E28C: nop

;}
RECOMP_FUNC void ActorEvent_Dying(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007717C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80077180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077184: lh          $v0, 0xB4($a0)
    ctx->r2 = MEM_H(ctx->r4, 0XB4);
    // 0x80077188: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x8007718C: beq         $v0, $at, L_800771A4
    if (ctx->r2 == ctx->r1) {
        // 0x80077190: addiu       $at, $zero, 0x31
        ctx->r1 = ADD32(0, 0X31);
            goto L_800771A4;
    }
    // 0x80077190: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80077194: beq         $v0, $at, L_800771A4
    if (ctx->r2 == ctx->r1) {
        // 0x80077198: addiu       $at, $zero, 0x32
        ctx->r1 = ADD32(0, 0X32);
            goto L_800771A4;
    }
    // 0x80077198: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x8007719C: bne         $v0, $at, L_800771B4
    if (ctx->r2 != ctx->r1) {
        // 0x800771A0: nop
    
            goto L_800771B4;
    }
    // 0x800771A0: nop

L_800771A4:
    // 0x800771A4: jal         0x801A3BD4
    // 0x800771A8: nop

    SectorY_SyRobot_Update(rdram, ctx);
        goto after_0;
    // 0x800771A8: nop

    after_0:
    // 0x800771AC: b           L_800771C0
    // 0x800771B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800771C0;
    // 0x800771B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800771B4:
    // 0x800771B4: jal         0x800763A4
    // 0x800771B8: nop

    Actor_DyingCrash(rdram, ctx);
        goto after_1;
    // 0x800771B8: nop

    after_1:
    // 0x800771BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800771C0:
    // 0x800771C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800771C4: jr          $ra
    // 0x800771C8: nop

    return;
    // 0x800771C8: nop

;}
RECOMP_FUNC void ActorEvent_SxWarpGate_OverrideLimbDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074C44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074C48: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074C4C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80074C50: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80074C54: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80074C58: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80074C5C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80074C60: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80074C64: bne         $a0, $at, L_80074E28
    if (ctx->r4 != ctx->r1) {
        // 0x80074C68: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80074E28;
    }
    // 0x80074C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80074C6C: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80074C70: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80074C74: lwc1        $f8, 0x6FBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FBC);
    // 0x80074C78: lh          $t7, 0xCE($t6)
    ctx->r15 = MEM_H(ctx->r14, 0XCE);
    // 0x80074C7C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80074C80: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x80074C84: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80074C88: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80074C8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80074C90: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80074C94: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80074C98: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80074C9C: mfc1        $s1, $f16
    ctx->r17 = (int32_t)ctx->f16.u32l;
    // 0x80074CA0: nop

    // 0x80074CA4: slti        $at, $s1, 0x100
    ctx->r1 = SIGNED(ctx->r17) < 0X100 ? 1 : 0;
    // 0x80074CA8: bne         $at, $zero, L_80074CB4
    if (ctx->r1 != 0) {
        // 0x80074CAC: nop
    
            goto L_80074CB4;
    }
    // 0x80074CAC: nop

    // 0x80074CB0: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
L_80074CB4:
    // 0x80074CB4: bgezl       $s1, L_80074CC4
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80074CB8: lw          $a1, 0x0($t9)
        ctx->r5 = MEM_W(ctx->r25, 0X0);
            goto L_80074CC4;
    }
    goto skip_0;
    // 0x80074CB8: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    skip_0:
    // 0x80074CBC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80074CC0: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
L_80074CC4:
    // 0x80074CC4: lw          $a2, 0x4($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X4);
    // 0x80074CC8: lw          $a3, 0x8($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X8);
    // 0x80074CCC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80074CD0: jal         0x80005B00
    // 0x80074CD4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80074CD4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_0:
    // 0x80074CD8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80074CDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80074CE0: lwc1        $f4, 0x6FC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FC0);
    // 0x80074CE4: lwc1        $f18, 0x8($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X8);
    // 0x80074CE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074CEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80074CF0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80074CF4: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80074CF8: jal         0x80005FE0
    // 0x80074CFC: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x80074CFC: nop

    after_1:
    // 0x80074D00: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80074D04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80074D08: lwc1        $f10, 0x6FC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6FC4);
    // 0x80074D0C: lwc1        $f8, 0x4($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X4);
    // 0x80074D10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074D14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80074D18: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80074D1C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80074D20: jal         0x80005E90
    // 0x80074D24: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x80074D24: nop

    after_2:
    // 0x80074D28: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x80074D2C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80074D30: lwc1        $f4, 0x6FC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FC8);
    // 0x80074D34: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80074D38: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80074D3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80074D40: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80074D44: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80074D48: jal         0x80005D44
    // 0x80074D4C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x80074D4C: nop

    after_3:
    // 0x80074D50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80074D54: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80074D58: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80074D5C: jal         0x80005754
    // 0x80074D60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_4;
    // 0x80074D60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x80074D64: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80074D68: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80074D6C: jal         0x80006EB8
    // 0x80074D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x80074D70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80074D74: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80074D78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074D7C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80074D80: beq         $t7, $zero, L_80074E20
    if (ctx->r15 == 0) {
        // 0x80074D84: nop
    
            goto L_80074E20;
    }
    // 0x80074D84: nop

    // 0x80074D88: jal         0x800B8DD0
    // 0x80074D8C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x80074D8C: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_6:
    // 0x80074D90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80074D94: andi        $t0, $s1, 0xFF
    ctx->r8 = ctx->r17 & 0XFF;
    // 0x80074D98: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x80074D9C: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80074DA0: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80074DA4: sll         $t4, $t0, 8
    ctx->r12 = S32(ctx->r8 << 8);
    // 0x80074DA8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80074DAC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80074DB0: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80074DB4: ori         $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 | 0XFF;
    // 0x80074DB8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80074DBC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80074DC0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80074DC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80074DC8: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x80074DCC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80074DD0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80074DD4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80074DD8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80074DDC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80074DE0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80074DE4: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x80074DE8: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80074DEC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80074DF0: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80074DF4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80074DF8: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x80074DFC: lw          $t4, -0x7C24($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7C24);
    // 0x80074E00: lw          $t3, -0x7C28($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7C28);
    // 0x80074E04: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x80074E08: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x80074E0C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x80074E10: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x80074E14: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80074E18: jal         0x800BA1D0
    // 0x80074E1C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    RCP_SetupDL_29(rdram, ctx);
        goto after_7;
    // 0x80074E1C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_7:
L_80074E20:
    // 0x80074E20: b           L_80074E28
    // 0x80074E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80074E28;
    // 0x80074E24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074E28:
    // 0x80074E28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074E2C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80074E30: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80074E34: jr          $ra
    // 0x80074E38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074E38: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void HUD_LivesCount2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087530: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80087534: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80087538: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8008753C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x80087540: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80087544: addiu       $s1, $s1, 0x7E64
    ctx->r17 = ADD32(ctx->r17, 0X7E64);
    // 0x80087548: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8008754C: swc1        $f12, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f12.u32l;
    // 0x80087550: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x80087554: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x80087558: addiu       $t7, $t7, 0x1D00
    ctx->r15 = ADD32(ctx->r15, 0X1D00);
    // 0x8008755C: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80087560: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
    // 0x80087564: lw          $t1, 0x4($t7)
    ctx->r9 = MEM_W(ctx->r15, 0X4);
    // 0x80087568: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x8008756C: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x80087570: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x80087574: addiu       $t3, $t3, 0x1D0C
    ctx->r11 = ADD32(ctx->r11, 0X1D0C);
    // 0x80087578: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8008757C: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x80087580: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x80087584: addiu       $t2, $sp, 0x78
    ctx->r10 = ADD32(ctx->r29, 0X78);
    // 0x80087588: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8008758C: sw          $at, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r1;
    // 0x80087590: lw          $at, 0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X8);
    // 0x80087594: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80087598: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8008759C: sw          $at, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r1;
    // 0x800875A0: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x800875A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800875A8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    // 0x800875AC: jal         0x800B8DD0
    // 0x800875B0: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800875B0: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    after_0:
    // 0x800875B4: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800875B8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800875BC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800875C0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800875C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800875C8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800875CC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800875D0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800875D4: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x800875D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800875DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800875E0: lw          $a0, 0x1CC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X1CC);
    // 0x800875E4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800875E8: beq         $a0, $zero, L_80087614
    if (ctx->r4 == 0) {
        // 0x800875EC: nop
    
            goto L_80087614;
    }
    // 0x800875EC: nop

    // 0x800875F0: beq         $a0, $at, L_80087608
    if (ctx->r4 == ctx->r1) {
        // 0x800875F4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80087608;
    }
    // 0x800875F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800875F8: beql        $a0, $at, L_80087614
    if (ctx->r4 == ctx->r1) {
        // 0x800875FC: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_80087614;
    }
    goto skip_0;
    // 0x800875FC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    skip_0:
    // 0x80087600: b           L_80087614
    // 0x80087604: nop

        goto L_80087614;
    // 0x80087604: nop

L_80087608:
    // 0x80087608: b           L_80087614
    // 0x8008760C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80087614;
    // 0x8008760C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80087610: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_80087614:
    // 0x80087614: bgezl       $s0, L_80087624
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80087618: slti        $at, $s0, 0x64
        ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
            goto L_80087624;
    }
    goto skip_1;
    // 0x80087618: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
    skip_1:
    // 0x8008761C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80087620: slti        $at, $s0, 0x64
    ctx->r1 = SIGNED(ctx->r16) < 0X64 ? 1 : 0;
L_80087624:
    // 0x80087624: bne         $at, $zero, L_80087630
    if (ctx->r1 != 0) {
        // 0x80087628: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_80087630;
    }
    // 0x80087628: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8008762C: addiu       $s0, $zero, 0x63
    ctx->r16 = ADD32(0, 0X63);
L_80087630:
    // 0x80087630: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80087634: bne         $at, $zero, L_80087654
    if (ctx->r1 != 0) {
        // 0x80087638: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80087654;
    }
    // 0x80087638: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8008763C:
    // 0x8008763C: multu       $v0, $a0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80087640: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80087644: mflo        $v0
    ctx->r2 = lo;
    // 0x80087648: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008764C: beq         $at, $zero, L_8008763C
    if (ctx->r1 == 0) {
        // 0x80087650: nop
    
            goto L_8008763C;
    }
    // 0x80087650: nop

L_80087654:
    // 0x80087654: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80087658: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8008765C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80087660: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x80087664: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80087668: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8008766C: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80087670: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80087674: add.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x80087678: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8008767C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80087680: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80087684: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80087688: addu        $a1, $sp, $v0
    ctx->r5 = ADD32(ctx->r29, ctx->r2);
    // 0x8008768C: addu        $a2, $sp, $v0
    ctx->r6 = ADD32(ctx->r29, ctx->r2);
    // 0x80087690: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80087694: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80087698: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x8008769C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800876A0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800876A4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800876A8: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    // 0x800876AC: lw          $a2, 0x78($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X78);
    // 0x800876B0: lw          $a1, 0x84($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X84);
    // 0x800876B4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800876B8: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800876BC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800876C0: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800876C4: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800876C8: jal         0x8009C320
    // 0x800876CC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x800876CC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800876D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800876D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800876D8: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x800876DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800876E0: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800876E4: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800876E8: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x800876EC: add.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800876F0: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x800876F4: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800876F8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800876FC: addiu       $a2, $a2, 0x1F08
    ctx->r6 = ADD32(ctx->r6, 0X1F08);
    // 0x80087700: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80087704: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    // 0x80087708: addiu       $a1, $a1, 0x1ED0
    ctx->r5 = ADD32(ctx->r5, 0X1ED0);
    // 0x8008770C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80087710: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80087714: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    // 0x80087718: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8008771C: jal         0x8009C320
    // 0x80087720: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_2;
    // 0x80087720: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80087724: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80087728: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8008772C: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x80087730: ori         $t1, $t1, 0xFF
    ctx->r9 = ctx->r9 | 0XFF;
    // 0x80087734: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80087738: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8008773C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80087740: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80087744: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80087748: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008774C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80087750: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80087754: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80087758: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8008775C: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80087760: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80087764: mfc1        $a0, $f16
    ctx->r4 = (int32_t)ctx->f16.u32l;
    // 0x80087768: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8008776C: jal         0x8009FC0C
    // 0x80087770: nop

    Graphics_DisplayHUDNumber(rdram, ctx);
        goto after_3;
    // 0x80087770: nop

    after_3:
    // 0x80087774: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80087778: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x8008777C: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x80087780: jr          $ra
    // 0x80087784: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80087784: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
