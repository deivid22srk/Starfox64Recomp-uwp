#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void PlayerShot_UpdateTank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003BA80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003BA84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003BA88: jal         0x8003B55C
    // 0x8003BA8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    PlayerShot_UpdateBeam(rdram, ctx);
        goto after_0;
    // 0x8003BA8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8003BA90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003BA94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003BA98: jr          $ra
    // 0x8003BA9C: nop

    return;
    // 0x8003BA9C: nop

;}
RECOMP_FUNC void Boss299_Init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042FB0: jr          $ra
    // 0x80042FB4: nop

    return;
    // 0x80042FB4: nop

;}
RECOMP_FUNC void Object_SetInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800612B8: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800612BC: addu        $t6, $t6, $a1
    ctx->r14 = ADD32(ctx->r14, ctx->r5);
    // 0x800612C0: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800612C4: addiu       $t7, $t7, -0x3EDC
    ctx->r15 = ADD32(ctx->r15, -0X3EDC);
    // 0x800612C8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800612CC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800612D0: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800612D4: addiu       $t0, $v0, 0x24
    ctx->r8 = ADD32(ctx->r2, 0X24);
    // 0x800612D8: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
L_800612DC:
    // 0x800612DC: lw          $at, 0x0($t1)
    ctx->r1 = MEM_W(ctx->r9, 0X0);
    // 0x800612E0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800612E4: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800612E8: sw          $at, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r1;
    // 0x800612EC: lw          $at, -0x8($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X8);
    // 0x800612F0: sw          $at, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r1;
    // 0x800612F4: lw          $at, -0x4($t1)
    ctx->r1 = MEM_W(ctx->r9, -0X4);
    // 0x800612F8: bne         $t1, $t0, L_800612DC
    if (ctx->r9 != ctx->r8) {
        // 0x800612FC: sw          $at, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r1;
            goto L_800612DC;
    }
    // 0x800612FC: sw          $at, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r1;
    // 0x80061300: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80061304: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80061308: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8006130C: sll         $t4, $v1, 4
    ctx->r12 = S32(ctx->r3 << 4);
    // 0x80061310: srl         $t5, $t4, 28
    ctx->r13 = S32(U32(ctx->r12) >> 28);
    // 0x80061314: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80061318: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006131C: lw          $t7, 0x1FD0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1FD0);
    // 0x80061320: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80061324: and         $t3, $v1, $at
    ctx->r11 = ctx->r3 & ctx->r1;
    // 0x80061328: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8006132C: addu        $t9, $t3, $t7
    ctx->r25 = ADD32(ctx->r11, ctx->r15);
    // 0x80061330: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x80061334: sw          $t8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r24;
    // 0x80061338: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8006133C: lw          $t0, 0x7880($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7880);
    // 0x80061340: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80061344: bne         $t0, $at, L_8006135C
    if (ctx->r8 != ctx->r1) {
        // 0x80061348: lui         $at, 0x4348
        ctx->r1 = S32(0X4348 << 16);
            goto L_8006135C;
    }
    // 0x80061348: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8006134C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80061350: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80061354: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80061358: swc1        $f8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f8.u32l;
L_8006135C:
    // 0x8006135C: jr          $ra
    // 0x80061360: nop

    return;
    // 0x80061360: nop

;}
RECOMP_FUNC void AudioSeq_SeqLayerDisable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800140D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800140D4: beq         $a0, $zero, L_800140FC
    if (ctx->r4 == 0) {
        // 0x800140D8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800140FC;
    }
    // 0x800140D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800140DC: jal         0x8001266C
    // 0x800140E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    Audio_SeqLayerNoteDecay(rdram, ctx);
        goto after_0;
    // 0x800140E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800140E4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800140E8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800140EC: andi        $t9, $t6, 0xFF7F
    ctx->r25 = ctx->r14 & 0XFF7F;
    // 0x800140F0: ori         $t0, $t9, 0x40
    ctx->r8 = ctx->r25 | 0X40;
    // 0x800140F4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x800140F8: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
L_800140FC:
    // 0x800140FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014104: jr          $ra
    // 0x80014108: nop

    return;
    // 0x80014108: nop

;}
RECOMP_FUNC void AudioHeap_AllocCached(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C2B4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000C2B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000C2BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C2C0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8000C2C4: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000C2C8: addiu       $t1, $t1, -0x2C18
    ctx->r9 = ADD32(ctx->r9, -0X2C18);
    // 0x8000C2CC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8000C2D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000C2D4: addiu       $ra, $zero, 0xC
    ctx->r31 = ADD32(0, 0XC);
    // 0x8000C2D8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8000C2DC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8000C2E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000C2E4: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8000C2E8:
    // 0x8000C2E8: beq         $s0, $zero, L_8000C308
    if (ctx->r16 == 0) {
        // 0x8000C2EC: lw          $a1, 0x54($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X54);
            goto L_8000C308;
    }
    // 0x8000C2EC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8000C2F0: beq         $s0, $t2, L_8000C31C
    if (ctx->r16 == ctx->r10) {
        // 0x8000C2F4: nop
    
            goto L_8000C31C;
    }
    // 0x8000C2F4: nop

    // 0x8000C2F8: beq         $s0, $t0, L_8000C32C
    if (ctx->r16 == ctx->r8) {
        // 0x8000C2FC: nop
    
            goto L_8000C32C;
    }
    // 0x8000C2FC: nop

    // 0x8000C300: b           L_8000C33C
    // 0x8000C304: nop

        goto L_8000C33C;
    // 0x8000C304: nop

L_8000C308:
    // 0x8000C308: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000C30C: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000C310: addiu       $a3, $a3, -0x3DC0
    ctx->r7 = ADD32(ctx->r7, -0X3DC0);
    // 0x8000C314: b           L_8000C33C
    // 0x8000C318: addiu       $t3, $t3, -0x2BD8
    ctx->r11 = ADD32(ctx->r11, -0X2BD8);
        goto L_8000C33C;
    // 0x8000C318: addiu       $t3, $t3, -0x2BD8
    ctx->r11 = ADD32(ctx->r11, -0X2BD8);
L_8000C31C:
    // 0x8000C31C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000C320: addiu       $a3, $a3, -0x3BF0
    ctx->r7 = ADD32(ctx->r7, -0X3BF0);
    // 0x8000C324: b           L_8000C33C
    // 0x8000C328: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
        goto L_8000C33C;
    // 0x8000C328: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
L_8000C32C:
    // 0x8000C32C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8000C330: lui         $t3, 0x8015
    ctx->r11 = S32(0X8015 << 16);
    // 0x8000C334: addiu       $a3, $a3, -0x3A20
    ctx->r7 = ADD32(ctx->r7, -0X3A20);
    // 0x8000C338: addiu       $t3, $t3, -0x2C58
    ctx->r11 = ADD32(ctx->r11, -0X2C58);
L_8000C33C:
    // 0x8000C33C: bne         $a2, $zero, L_8000C8C0
    if (ctx->r6 != 0) {
        // 0x8000C340: addiu       $a0, $a3, 0x4
        ctx->r4 = ADD32(ctx->r7, 0X4);
            goto L_8000C8C0;
    }
    // 0x8000C340: addiu       $a0, $a3, 0x4
    ctx->r4 = ADD32(ctx->r7, 0X4);
    // 0x8000C344: lh          $t6, 0x1B2($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X1B2);
    // 0x8000C348: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C34C: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8000C350: bne         $t6, $at, L_8000C360
    if (ctx->r14 != ctx->r1) {
        // 0x8000C354: addiu       $a2, $a3, 0x194
        ctx->r6 = ADD32(ctx->r7, 0X194);
            goto L_8000C360;
    }
    // 0x8000C354: addiu       $a2, $a3, 0x194
    ctx->r6 = ADD32(ctx->r7, 0X194);
    // 0x8000C358: b           L_8000C36C
    // 0x8000C35C: addiu       $a2, $a3, 0x194
    ctx->r6 = ADD32(ctx->r7, 0X194);
        goto L_8000C36C;
    // 0x8000C35C: addiu       $a2, $a3, 0x194
    ctx->r6 = ADD32(ctx->r7, 0X194);
L_8000C360:
    // 0x8000C360: lh          $t7, 0x1E($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X1E);
    // 0x8000C364: addu        $t8, $t7, $t3
    ctx->r24 = ADD32(ctx->r15, ctx->r11);
    // 0x8000C368: lbu         $t4, 0x0($t8)
    ctx->r12 = MEM_BU(ctx->r24, 0X0);
L_8000C36C:
    // 0x8000C36C: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    // 0x8000C370: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C374: bne         $a0, $at, L_8000C384
    if (ctx->r4 != ctx->r1) {
        // 0x8000C378: addu        $t9, $a0, $t3
        ctx->r25 = ADD32(ctx->r4, ctx->r11);
            goto L_8000C384;
    }
    // 0x8000C378: addu        $t9, $a0, $t3
    ctx->r25 = ADD32(ctx->r4, ctx->r11);
    // 0x8000C37C: b           L_8000C388
    // 0x8000C380: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
        goto L_8000C388;
    // 0x8000C380: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
L_8000C384:
    // 0x8000C384: lbu         $t5, 0x0($t9)
    ctx->r13 = MEM_BU(ctx->r25, 0X0);
L_8000C388:
    // 0x8000C388: bne         $s0, $t2, L_8000C48C
    if (ctx->r16 != ctx->r10) {
        // 0x8000C38C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8000C48C;
    }
    // 0x8000C38C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000C390: bne         $t4, $at, L_8000C40C
    if (ctx->r12 != ctx->r1) {
        // 0x8000C394: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_8000C40C;
    }
    // 0x8000C394: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000C398: lw          $a1, 0x5CA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5CA0);
    // 0x8000C39C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C3A0: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000C3A4: blez        $a1, L_8000C3E0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000C3A8: nop
    
            goto L_8000C3E0;
    }
    // 0x8000C3A8: nop

    // 0x8000C3AC: lw          $v0, -0x1AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1AD0);
    // 0x8000C3B0: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
L_8000C3B4:
    // 0x8000C3B4: lbu         $t6, 0x33($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X33);
    // 0x8000C3B8: bnel        $t6, $a0, L_8000C3D4
    if (ctx->r14 != ctx->r4) {
        // 0x8000C3BC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000C3D4;
    }
    goto skip_0;
    // 0x8000C3BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x8000C3C0: lw          $t7, 0xB0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB0);
    // 0x8000C3C4: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8000C3C8: bne         $t8, $zero, L_8000C3E0
    if (ctx->r24 != 0) {
        // 0x8000C3CC: nop
    
            goto L_8000C3E0;
    }
    // 0x8000C3CC: nop

    // 0x8000C3D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000C3D4:
    // 0x8000C3D4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000C3D8: bne         $at, $zero, L_8000C3B4
    if (ctx->r1 != 0) {
        // 0x8000C3DC: addiu       $v0, $v0, 0xC0
        ctx->r2 = ADD32(ctx->r2, 0XC0);
            goto L_8000C3B4;
    }
    // 0x8000C3DC: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
L_8000C3E0:
    // 0x8000C3E0: bnel        $v1, $a1, L_8000C410
    if (ctx->r3 != ctx->r5) {
        // 0x8000C3E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8000C410;
    }
    goto skip_1;
    // 0x8000C3E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    skip_1:
    // 0x8000C3E8: lh          $t9, 0x1E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1E);
    // 0x8000C3EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000C3F0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8000C3F4: addu        $v0, $t1, $t9
    ctx->r2 = ADD32(ctx->r9, ctx->r25);
    // 0x8000C3F8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C3FC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8000C400: beq         $t6, $at, L_8000C40C
    if (ctx->r14 == ctx->r1) {
        // 0x8000C404: nop
    
            goto L_8000C40C;
    }
    // 0x8000C404: nop

    // 0x8000C408: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8000C40C:
    // 0x8000C40C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_8000C410:
    // 0x8000C410: bne         $t5, $at, L_8000C48C
    if (ctx->r13 != ctx->r1) {
        // 0x8000C414: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_8000C48C;
    }
    // 0x8000C414: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000C418: lw          $a1, 0x5CA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5CA0);
    // 0x8000C41C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C420: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000C424: blez        $a1, L_8000C460
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000C428: nop
    
            goto L_8000C460;
    }
    // 0x8000C428: nop

    // 0x8000C42C: lw          $v0, -0x1AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1AD0);
    // 0x8000C430: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
L_8000C434:
    // 0x8000C434: lbu         $t8, 0x33($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X33);
    // 0x8000C438: bnel        $t8, $a0, L_8000C454
    if (ctx->r24 != ctx->r4) {
        // 0x8000C43C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000C454;
    }
    goto skip_2;
    // 0x8000C43C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_2:
    // 0x8000C440: lw          $t9, 0xB0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB0);
    // 0x8000C444: srl         $t6, $t9, 31
    ctx->r14 = S32(U32(ctx->r25) >> 31);
    // 0x8000C448: bne         $t6, $zero, L_8000C460
    if (ctx->r14 != 0) {
        // 0x8000C44C: nop
    
            goto L_8000C460;
    }
    // 0x8000C44C: nop

    // 0x8000C450: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000C454:
    // 0x8000C454: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000C458: bne         $at, $zero, L_8000C434
    if (ctx->r1 != 0) {
        // 0x8000C45C: addiu       $v0, $v0, 0xC0
        ctx->r2 = ADD32(ctx->r2, 0XC0);
            goto L_8000C434;
    }
    // 0x8000C45C: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
L_8000C460:
    // 0x8000C460: bne         $v1, $a1, L_8000C48C
    if (ctx->r3 != ctx->r5) {
        // 0x8000C464: nop
    
            goto L_8000C48C;
    }
    // 0x8000C464: nop

    // 0x8000C468: lh          $t7, 0x2A($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X2A);
    // 0x8000C46C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000C470: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x8000C474: addu        $v0, $t1, $t7
    ctx->r2 = ADD32(ctx->r9, ctx->r15);
    // 0x8000C478: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8000C47C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8000C480: beq         $t8, $at, L_8000C48C
    if (ctx->r24 == ctx->r1) {
        // 0x8000C484: nop
    
            goto L_8000C48C;
    }
    // 0x8000C484: nop

    // 0x8000C488: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_8000C48C:
    // 0x8000C48C: bne         $t4, $zero, L_8000C4A0
    if (ctx->r12 != 0) {
        // 0x8000C490: or          $t1, $t4, $zero
        ctx->r9 = ctx->r12 | 0;
            goto L_8000C4A0;
    }
    // 0x8000C490: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
    // 0x8000C494: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000C498: b           L_8000C6BC
    // 0x8000C49C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C6BC;
    // 0x8000C49C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C4A0:
    // 0x8000C4A0: bne         $t5, $zero, L_8000C4B4
    if (ctx->r13 != 0) {
        // 0x8000C4A4: or          $t4, $t5, $zero
        ctx->r12 = ctx->r13 | 0;
            goto L_8000C4B4;
    }
    // 0x8000C4A4: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8000C4A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C4AC: b           L_8000C6BC
    // 0x8000C4B0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_8000C6BC;
    // 0x8000C4B0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8000C4B4:
    // 0x8000C4B4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000C4B8: bne         $v0, $t1, L_8000C4D0
    if (ctx->r2 != ctx->r9) {
        // 0x8000C4BC: nop
    
            goto L_8000C4D0;
    }
    // 0x8000C4BC: nop

    // 0x8000C4C0: bne         $v0, $t4, L_8000C4D0
    if (ctx->r2 != ctx->r12) {
        // 0x8000C4C4: nop
    
            goto L_8000C4D0;
    }
    // 0x8000C4C4: nop

    // 0x8000C4C8: b           L_8000C6BC
    // 0x8000C4CC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
        goto L_8000C6BC;
    // 0x8000C4CC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_8000C4D0:
    // 0x8000C4D0: bne         $v0, $t1, L_8000C4E4
    if (ctx->r2 != ctx->r9) {
        // 0x8000C4D4: nop
    
            goto L_8000C4E4;
    }
    // 0x8000C4D4: nop

    // 0x8000C4D8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000C4DC: b           L_8000C6BC
    // 0x8000C4E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C6BC;
    // 0x8000C4E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C4E4:
    // 0x8000C4E4: bne         $v0, $t4, L_8000C4F4
    if (ctx->r2 != ctx->r12) {
        // 0x8000C4E8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000C4F4;
    }
    // 0x8000C4E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C4EC: b           L_8000C6BC
    // 0x8000C4F0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_8000C6BC;
    // 0x8000C4F0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8000C4F4:
    // 0x8000C4F4: bne         $s0, $zero, L_8000C5B0
    if (ctx->r16 != 0) {
        // 0x8000C4F8: nop
    
            goto L_8000C5B0;
    }
    // 0x8000C4F8: nop

    // 0x8000C4FC: bne         $t0, $t1, L_8000C558
    if (ctx->r8 != ctx->r9) {
        // 0x8000C500: lui         $v0, 0x8015
        ctx->r2 = S32(0X8015 << 16);
            goto L_8000C558;
    }
    // 0x8000C500: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000C504: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000C508: addiu       $v1, $v1, -0x1598
    ctx->r3 = ADD32(ctx->r3, -0X1598);
    // 0x8000C50C: addiu       $v0, $v0, -0x1AC8
    ctx->r2 = ADD32(ctx->r2, -0X1AC8);
    // 0x8000C510: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
L_8000C514:
    // 0x8000C514: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x8000C518: beql        $t9, $zero, L_8000C534
    if (ctx->r25 == 0) {
        // 0x8000C51C: addiu       $v0, $v0, 0x14C
        ctx->r2 = ADD32(ctx->r2, 0X14C);
            goto L_8000C534;
    }
    goto skip_3;
    // 0x8000C51C: addiu       $v0, $v0, 0x14C
    ctx->r2 = ADD32(ctx->r2, 0X14C);
    skip_3:
    // 0x8000C520: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x8000C524: lh          $t7, 0x1E($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X1E);
    // 0x8000C528: beq         $t6, $t7, L_8000C53C
    if (ctx->r14 == ctx->r15) {
        // 0x8000C52C: nop
    
            goto L_8000C53C;
    }
    // 0x8000C52C: nop

    // 0x8000C530: addiu       $v0, $v0, 0x14C
    ctx->r2 = ADD32(ctx->r2, 0X14C);
L_8000C534:
    // 0x8000C534: bnel        $v0, $v1, L_8000C514
    if (ctx->r2 != ctx->r3) {
        // 0x8000C538: lw          $t8, 0x0($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X0);
            goto L_8000C514;
    }
    goto skip_4;
    // 0x8000C538: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    skip_4:
L_8000C53C:
    // 0x8000C53C: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8000C540: addiu       $t8, $t8, -0x1598
    ctx->r24 = ADD32(ctx->r24, -0X1598);
    // 0x8000C544: bne         $v0, $t8, L_8000C558
    if (ctx->r2 != ctx->r24) {
        // 0x8000C548: nop
    
            goto L_8000C558;
    }
    // 0x8000C548: nop

    // 0x8000C54C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000C550: b           L_8000C6BC
    // 0x8000C554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C6BC;
    // 0x8000C554: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C558:
    // 0x8000C558: bne         $t0, $t4, L_8000C678
    if (ctx->r8 != ctx->r12) {
        // 0x8000C55C: lui         $v0, 0x8015
        ctx->r2 = S32(0X8015 << 16);
            goto L_8000C678;
    }
    // 0x8000C55C: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000C560: lui         $v1, 0x8015
    ctx->r3 = S32(0X8015 << 16);
    // 0x8000C564: addiu       $v1, $v1, -0x1598
    ctx->r3 = ADD32(ctx->r3, -0X1598);
    // 0x8000C568: addiu       $v0, $v0, -0x1AC8
    ctx->r2 = ADD32(ctx->r2, -0X1AC8);
    // 0x8000C56C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_8000C570:
    // 0x8000C570: srl         $t6, $t9, 31
    ctx->r14 = S32(U32(ctx->r25) >> 31);
    // 0x8000C574: beql        $t6, $zero, L_8000C590
    if (ctx->r14 == 0) {
        // 0x8000C578: addiu       $v0, $v0, 0x14C
        ctx->r2 = ADD32(ctx->r2, 0X14C);
            goto L_8000C590;
    }
    goto skip_5;
    // 0x8000C578: addiu       $v0, $v0, 0x14C
    ctx->r2 = ADD32(ctx->r2, 0X14C);
    skip_5:
    // 0x8000C57C: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x8000C580: lh          $t8, 0x2A($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2A);
    // 0x8000C584: beq         $t7, $t8, L_8000C598
    if (ctx->r15 == ctx->r24) {
        // 0x8000C588: nop
    
            goto L_8000C598;
    }
    // 0x8000C588: nop

    // 0x8000C58C: addiu       $v0, $v0, 0x14C
    ctx->r2 = ADD32(ctx->r2, 0X14C);
L_8000C590:
    // 0x8000C590: bnel        $v0, $v1, L_8000C570
    if (ctx->r2 != ctx->r3) {
        // 0x8000C594: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_8000C570;
    }
    goto skip_6;
    // 0x8000C594: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_6:
L_8000C598:
    // 0x8000C598: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8000C59C: addiu       $t9, $t9, -0x1598
    ctx->r25 = ADD32(ctx->r25, -0X1598);
    // 0x8000C5A0: bne         $v0, $t9, L_8000C678
    if (ctx->r2 != ctx->r25) {
        // 0x8000C5A4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000C678;
    }
    // 0x8000C5A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C5A8: b           L_8000C6BC
    // 0x8000C5AC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_8000C6BC;
    // 0x8000C5AC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8000C5B0:
    // 0x8000C5B0: bnel        $s0, $t2, L_8000C67C
    if (ctx->r16 != ctx->r10) {
        // 0x8000C5B4: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_8000C67C;
    }
    goto skip_7;
    // 0x8000C5B4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_7:
    // 0x8000C5B8: bne         $t0, $t1, L_8000C618
    if (ctx->r8 != ctx->r9) {
        // 0x8000C5BC: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_8000C618;
    }
    // 0x8000C5BC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000C5C0: lw          $a1, 0x5CA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5CA0);
    // 0x8000C5C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C5C8: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000C5CC: blez        $a1, L_8000C608
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000C5D0: nop
    
            goto L_8000C608;
    }
    // 0x8000C5D0: nop

    // 0x8000C5D4: lw          $v0, -0x1AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1AD0);
    // 0x8000C5D8: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
L_8000C5DC:
    // 0x8000C5DC: lbu         $t7, 0x33($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X33);
    // 0x8000C5E0: bnel        $t7, $a0, L_8000C5FC
    if (ctx->r15 != ctx->r4) {
        // 0x8000C5E4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000C5FC;
    }
    goto skip_8;
    // 0x8000C5E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_8:
    // 0x8000C5E8: lw          $t8, 0xB0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB0);
    // 0x8000C5EC: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x8000C5F0: bne         $t9, $zero, L_8000C608
    if (ctx->r25 != 0) {
        // 0x8000C5F4: nop
    
            goto L_8000C608;
    }
    // 0x8000C5F4: nop

    // 0x8000C5F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000C5FC:
    // 0x8000C5FC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000C600: bne         $at, $zero, L_8000C5DC
    if (ctx->r1 != 0) {
        // 0x8000C604: addiu       $v0, $v0, 0xC0
        ctx->r2 = ADD32(ctx->r2, 0XC0);
            goto L_8000C5DC;
    }
    // 0x8000C604: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
L_8000C608:
    // 0x8000C608: bne         $v1, $a1, L_8000C618
    if (ctx->r3 != ctx->r5) {
        // 0x8000C60C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000C618;
    }
    // 0x8000C60C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C610: b           L_8000C6BC
    // 0x8000C614: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8000C6BC;
    // 0x8000C614: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8000C618:
    // 0x8000C618: bne         $t0, $t4, L_8000C678
    if (ctx->r8 != ctx->r12) {
        // 0x8000C61C: lui         $a1, 0x8015
        ctx->r5 = S32(0X8015 << 16);
            goto L_8000C678;
    }
    // 0x8000C61C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8000C620: lw          $a1, 0x5CA0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X5CA0);
    // 0x8000C624: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000C628: lui         $v0, 0x8015
    ctx->r2 = S32(0X8015 << 16);
    // 0x8000C62C: blez        $a1, L_8000C668
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000C630: nop
    
            goto L_8000C668;
    }
    // 0x8000C630: nop

    // 0x8000C634: lw          $v0, -0x1AD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1AD0);
    // 0x8000C638: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
L_8000C63C:
    // 0x8000C63C: lbu         $t6, 0x33($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X33);
    // 0x8000C640: bnel        $t6, $a0, L_8000C65C
    if (ctx->r14 != ctx->r4) {
        // 0x8000C644: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8000C65C;
    }
    goto skip_9;
    // 0x8000C644: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_9:
    // 0x8000C648: lw          $t7, 0xB0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB0);
    // 0x8000C64C: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x8000C650: bne         $t8, $zero, L_8000C668
    if (ctx->r24 != 0) {
        // 0x8000C654: nop
    
            goto L_8000C668;
    }
    // 0x8000C654: nop

    // 0x8000C658: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8000C65C:
    // 0x8000C65C: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000C660: bne         $at, $zero, L_8000C63C
    if (ctx->r1 != 0) {
        // 0x8000C664: addiu       $v0, $v0, 0xC0
        ctx->r2 = ADD32(ctx->r2, 0XC0);
            goto L_8000C63C;
    }
    // 0x8000C664: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
L_8000C668:
    // 0x8000C668: bne         $v1, $a1, L_8000C678
    if (ctx->r3 != ctx->r5) {
        // 0x8000C66C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000C678;
    }
    // 0x8000C66C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C670: b           L_8000C6BC
    // 0x8000C674: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_8000C6BC;
    // 0x8000C674: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8000C678:
    // 0x8000C678: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_8000C67C:
    // 0x8000C67C: bne         $v0, $zero, L_8000C69C
    if (ctx->r2 != 0) {
        // 0x8000C680: nop
    
            goto L_8000C69C;
    }
    // 0x8000C680: nop

    // 0x8000C684: bne         $t2, $t1, L_8000C6BC
    if (ctx->r10 != ctx->r9) {
        // 0x8000C688: nop
    
            goto L_8000C6BC;
    }
    // 0x8000C688: nop

    // 0x8000C68C: beq         $t2, $t4, L_8000C6B4
    if (ctx->r10 == ctx->r12) {
        // 0x8000C690: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000C6B4;
    }
    // 0x8000C690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C694: b           L_8000C6BC
    // 0x8000C698: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_8000C6BC;
    // 0x8000C698: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_8000C69C:
    // 0x8000C69C: bne         $t2, $t4, L_8000C6BC
    if (ctx->r10 != ctx->r12) {
        // 0x8000C6A0: nop
    
            goto L_8000C6BC;
    }
    // 0x8000C6A0: nop

    // 0x8000C6A4: beq         $t2, $t1, L_8000C6B4
    if (ctx->r10 == ctx->r9) {
        // 0x8000C6A8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000C6B4;
    }
    // 0x8000C6A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C6AC: b           L_8000C6BC
    // 0x8000C6B0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8000C6BC;
    // 0x8000C6B0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8000C6B4:
    // 0x8000C6B4: b           L_8000C97C
    // 0x8000C6B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C97C;
    // 0x8000C6B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C6BC:
    // 0x8000C6BC: multu       $v0, $ra
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C6C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C6C4: mflo        $t7
    ctx->r15 = lo;
    // 0x8000C6C8: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8000C6CC: lh          $v1, 0x1E($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X1E);
    // 0x8000C6D0: beq         $v1, $at, L_8000C714
    if (ctx->r3 == ctx->r1) {
        // 0x8000C6D4: addu        $t9, $t3, $v1
        ctx->r25 = ADD32(ctx->r11, ctx->r3);
            goto L_8000C714;
    }
    // 0x8000C6D4: addu        $t9, $t3, $v1
    ctx->r25 = ADD32(ctx->r11, ctx->r3);
    // 0x8000C6D8: bne         $s0, $t2, L_8000C714
    if (ctx->r16 != ctx->r10) {
        // 0x8000C6DC: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_8000C714;
    }
    // 0x8000C6DC: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8000C6E0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8000C6E4: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C6E8: mflo        $t7
    ctx->r15 = lo;
    // 0x8000C6EC: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8000C6F0: lh          $a0, 0x1E($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X1E);
    // 0x8000C6F4: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8000C6F8: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8000C6FC: jal         0x8000BD38
    // 0x8000C700: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    AudioHeap_DiscardFont(rdram, ctx);
        goto after_0;
    // 0x8000C700: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000C704: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8000C708: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8000C70C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000C710: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_8000C714:
    // 0x8000C714: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8000C718: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000C71C: addiu       $v0, $a3, 0x198
    ctx->r2 = ADD32(ctx->r7, 0X198);
    // 0x8000C720: beql        $a0, $zero, L_8000C73C
    if (ctx->r4 == 0) {
        // 0x8000C724: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_8000C73C;
    }
    goto skip_10;
    // 0x8000C724: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_10:
    // 0x8000C728: beq         $a0, $at, L_8000C800
    if (ctx->r4 == ctx->r1) {
        // 0x8000C72C: addiu       $v0, $a3, 0x198
        ctx->r2 = ADD32(ctx->r7, 0X198);
            goto L_8000C800;
    }
    // 0x8000C72C: addiu       $v0, $a3, 0x198
    ctx->r2 = ADD32(ctx->r7, 0X198);
    // 0x8000C730: b           L_8000C97C
    // 0x8000C734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C97C;
    // 0x8000C734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000C738: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_8000C73C:
    // 0x8000C73C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C740: sw          $t9, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r25;
    // 0x8000C744: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8000C748: sh          $t6, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r14;
    // 0x8000C74C: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8000C750: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x8000C754: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8000C758: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000C75C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8000C760: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000C764: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    // 0x8000C768: beql        $a0, $at, L_8000C7EC
    if (ctx->r4 == ctx->r1) {
        // 0x8000C76C: lw          $v1, 0x14($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X14);
            goto L_8000C7EC;
    }
    goto skip_11;
    // 0x8000C76C: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    skip_11:
    // 0x8000C770: lw          $t7, 0x20($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X20);
    // 0x8000C774: addu        $t9, $t3, $a0
    ctx->r25 = ADD32(ctx->r11, ctx->r4);
    // 0x8000C778: sltu        $at, $t7, $t6
    ctx->r1 = ctx->r15 < ctx->r14 ? 1 : 0;
    // 0x8000C77C: beql        $at, $zero, L_8000C7EC
    if (ctx->r1 == 0) {
        // 0x8000C780: lw          $v1, 0x14($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X14);
            goto L_8000C7EC;
    }
    goto skip_12;
    // 0x8000C780: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
    skip_12:
    // 0x8000C784: beq         $s0, $zero, L_8000C79C
    if (ctx->r16 == 0) {
        // 0x8000C788: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_8000C79C;
    }
    // 0x8000C788: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8000C78C: beql        $s0, $t2, L_8000C7BC
    if (ctx->r16 == ctx->r10) {
        // 0x8000C790: lh          $a0, 0x2A($a2)
        ctx->r4 = MEM_H(ctx->r6, 0X2A);
            goto L_8000C7BC;
    }
    goto skip_13;
    // 0x8000C790: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    skip_13:
    // 0x8000C794: b           L_8000C7D4
    // 0x8000C798: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_8000C7D4;
    // 0x8000C798: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_8000C79C:
    // 0x8000C79C: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
    // 0x8000C7A0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000C7A4: jal         0x8000BE24
    // 0x8000C7A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    AudioHeap_DiscardSequence(rdram, ctx);
        goto after_1;
    // 0x8000C7A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000C7AC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8000C7B0: b           L_8000C7D0
    // 0x8000C7B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
        goto L_8000C7D0;
    // 0x8000C7B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8000C7B8: lh          $a0, 0x2A($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2A);
L_8000C7BC:
    // 0x8000C7BC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000C7C0: jal         0x8000BD38
    // 0x8000C7C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    AudioHeap_DiscardFont(rdram, ctx);
        goto after_2;
    // 0x8000C7C4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x8000C7C8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8000C7CC: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_8000C7D0:
    // 0x8000C7D0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_8000C7D4:
    // 0x8000C7D4: sh          $t6, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = ctx->r14;
    // 0x8000C7D8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8000C7DC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000C7E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8000C7E4: sw          $t9, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r25;
    // 0x8000C7E8: lw          $v1, 0x14($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X14);
L_8000C7EC:
    // 0x8000C7EC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8000C7F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000C7F4: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x8000C7F8: b           L_8000C97C
    // 0x8000C7FC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
        goto L_8000C97C;
    // 0x8000C7FC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_8000C800:
    // 0x8000C800: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000C804: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8000C808: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8000C80C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000C810: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8000C814: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8000C818: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x8000C81C: sw          $t9, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r25;
    // 0x8000C820: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8000C824: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
    // 0x8000C828: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000C82C: sh          $t6, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = ctx->r14;
    // 0x8000C830: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8000C834: or          $t8, $t9, $zero
    ctx->r24 = ctx->r25 | 0;
    // 0x8000C838: beq         $a0, $at, L_8000C8B0
    if (ctx->r4 == ctx->r1) {
        // 0x8000C83C: sw          $t7, 0x24($a2)
        MEM_W(0X24, ctx->r6) = ctx->r15;
            goto L_8000C8B0;
    }
    // 0x8000C83C: sw          $t7, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r15;
    // 0x8000C840: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8000C844: addu        $t6, $t3, $a0
    ctx->r14 = ADD32(ctx->r11, ctx->r4);
    // 0x8000C848: sltu        $at, $t8, $t9
    ctx->r1 = ctx->r24 < ctx->r25 ? 1 : 0;
    // 0x8000C84C: beq         $at, $zero, L_8000C8B0
    if (ctx->r1 == 0) {
        // 0x8000C850: nop
    
            goto L_8000C8B0;
    }
    // 0x8000C850: nop

    // 0x8000C854: beq         $s0, $zero, L_8000C86C
    if (ctx->r16 == 0) {
        // 0x8000C858: sb          $zero, 0x0($t6)
        MEM_B(0X0, ctx->r14) = 0;
            goto L_8000C86C;
    }
    // 0x8000C858: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8000C85C: beql        $s0, $t2, L_8000C88C
    if (ctx->r16 == ctx->r10) {
        // 0x8000C860: lh          $a0, 0x1E($a2)
        ctx->r4 = MEM_H(ctx->r6, 0X1E);
            goto L_8000C88C;
    }
    goto skip_14;
    // 0x8000C860: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
    skip_14:
    // 0x8000C864: b           L_8000C8A4
    // 0x8000C868: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8000C8A4;
    // 0x8000C868: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8000C86C:
    // 0x8000C86C: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
    // 0x8000C870: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000C874: jal         0x8000BE24
    // 0x8000C878: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    AudioHeap_DiscardSequence(rdram, ctx);
        goto after_3;
    // 0x8000C878: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_3:
    // 0x8000C87C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8000C880: b           L_8000C8A0
    // 0x8000C884: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
        goto L_8000C8A0;
    // 0x8000C884: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8000C888: lh          $a0, 0x1E($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X1E);
L_8000C88C:
    // 0x8000C88C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8000C890: jal         0x8000BD38
    // 0x8000C894: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    AudioHeap_DiscardFont(rdram, ctx);
        goto after_4;
    // 0x8000C894: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_4:
    // 0x8000C898: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8000C89C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
L_8000C8A0:
    // 0x8000C8A0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8000C8A4:
    // 0x8000C8A4: sh          $t7, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r15;
    // 0x8000C8A8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000C8AC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_8000C8B0:
    // 0x8000C8B0: b           L_8000C7EC
    // 0x8000C8B4: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
        goto L_8000C7EC;
    // 0x8000C8B4: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
    // 0x8000C8B8: b           L_8000C97C
    // 0x8000C8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C97C;
    // 0x8000C8BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C8C0:
    // 0x8000C8C0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8000C8C4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8000C8C8: jal         0x8000BF14
    // 0x8000C8CC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    AudioHeap_Alloc(rdram, ctx);
        goto after_5;
    // 0x8000C8CC: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    after_5:
    // 0x8000C8D0: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8000C8D4: addiu       $ra, $zero, 0xC
    ctx->r31 = ADD32(0, 0XC);
    // 0x8000C8D8: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x8000C8DC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8000C8E0: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8000C8E4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8000C8E8: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C8EC: addiu       $t1, $t1, -0x2C18
    ctx->r9 = ADD32(ctx->r9, -0X2C18);
    // 0x8000C8F0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8000C8F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8000C8F8: mflo        $t6
    ctx->r14 = lo;
    // 0x8000C8FC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8000C900: bne         $v0, $zero, L_8000C930
    if (ctx->r2 != 0) {
        // 0x8000C904: sw          $v0, 0x14($t7)
        MEM_W(0X14, ctx->r15) = ctx->r2;
            goto L_8000C930;
    }
    // 0x8000C904: sw          $v0, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->r2;
    // 0x8000C908: beq         $a2, $zero, L_8000C928
    if (ctx->r6 == 0) {
        // 0x8000C90C: nop
    
            goto L_8000C928;
    }
    // 0x8000C90C: nop

    // 0x8000C910: beq         $a2, $t2, L_8000C928
    if (ctx->r6 == ctx->r10) {
        // 0x8000C914: nop
    
            goto L_8000C928;
    }
    // 0x8000C914: nop

    // 0x8000C918: bnel        $a2, $t0, L_8000C934
    if (ctx->r6 != ctx->r8) {
        // 0x8000C91C: lw          $t9, 0x0($a3)
        ctx->r25 = MEM_W(ctx->r7, 0X0);
            goto L_8000C934;
    }
    goto skip_15;
    // 0x8000C91C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    skip_15:
    // 0x8000C920: b           L_8000C2E8
    // 0x8000C924: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8000C2E8;
    // 0x8000C924: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000C928:
    // 0x8000C928: b           L_8000C97C
    // 0x8000C92C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000C97C;
    // 0x8000C92C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000C930:
    // 0x8000C930: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
L_8000C934:
    // 0x8000C934: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8000C938: multu       $t9, $ra
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C93C: mflo        $t6
    ctx->r14 = lo;
    // 0x8000C940: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8000C944: sh          $t8, 0x1E($t7)
    MEM_H(0X1E, ctx->r15) = ctx->r24;
    // 0x8000C948: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8000C94C: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8000C950: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C954: mflo        $t8
    ctx->r24 = lo;
    // 0x8000C958: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8000C95C: sw          $t9, 0x18($t7)
    MEM_W(0X18, ctx->r15) = ctx->r25;
    // 0x8000C960: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8000C964: multu       $v1, $ra
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000C968: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8000C96C: mflo        $t6
    ctx->r14 = lo;
    // 0x8000C970: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x8000C974: lw          $v0, 0x14($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X14);
    // 0x8000C978: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_8000C97C:
    // 0x8000C97C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C980: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000C984: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8000C988: jr          $ra
    // 0x8000C98C: nop

    return;
    // 0x8000C98C: nop

;}
RECOMP_FUNC void ItemMeteoWarp_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006868C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80068690: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80068694: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80068698: jal         0x80066EF0
    // 0x8006869C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Item_CheckBounds(rdram, ctx);
        goto after_0;
    // 0x8006869C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800686A0: lbu         $v0, 0x46($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X46);
    // 0x800686A4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800686A8: blezl       $v0, L_800687B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800686AC: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_800687B0;
    }
    goto skip_0;
    // 0x800686AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_0:
    // 0x800686B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800686B4: bne         $v0, $at, L_80068780
    if (ctx->r2 != ctx->r1) {
        // 0x800686B8: lui         $v1, 0x8018
        ctx->r3 = S32(0X8018 << 16);
            goto L_80068780;
    }
    // 0x800686B8: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800686BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800686C0: lwc1        $f14, 0x6994($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X6994);
    // 0x800686C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800686C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800686CC: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800686D0: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x800686D4: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x800686D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800686DC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800686E0: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x800686E4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800686E8: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x800686EC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800686F0: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800686F4: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x800686F8: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800686FC: lwc1        $f10, 0x74($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X74);
    // 0x80068700: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80068704: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80068708: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006870C: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80068710: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80068714: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80068718: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x8006871C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80068720: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x80068724: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80068728: addu        $t1, $t9, $t6
    ctx->r9 = ADD32(ctx->r25, ctx->r14);
    // 0x8006872C: lwc1        $f8, 0x78($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X78);
    // 0x80068730: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80068734: mul.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80068738: add.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f18.fl;
    // 0x8006873C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    // 0x80068740: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80068744: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80068748: addu        $t3, $t2, $t6
    ctx->r11 = ADD32(ctx->r10, ctx->r14);
    // 0x8006874C: lwc1        $f6, 0x138($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X138);
    // 0x80068750: sub.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80068754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80068758: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8006875C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80068760: swc1        $f8, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f8.u32l;
    // 0x80068764: add.s       $f18, $f12, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x80068768: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8006876C: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80068770: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x80068774: bc1fl       L_80068784
    if (!c1cs) {
        // 0x80068778: lh          $t4, 0x44($s0)
        ctx->r12 = MEM_H(ctx->r16, 0X44);
            goto L_80068784;
    }
    goto skip_1;
    // 0x80068778: lh          $t4, 0x44($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X44);
    skip_1:
    // 0x8006877C: swc1        $f16, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f16.u32l;
L_80068780:
    // 0x80068780: lh          $t4, 0x44($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X44);
L_80068784:
    // 0x80068784: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80068788: addiu       $t5, $t4, -0xA
    ctx->r13 = ADD32(ctx->r12, -0XA);
    // 0x8006878C: sh          $t5, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r13;
    // 0x80068790: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x80068794: bgezl       $t6, L_80068904
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80068798: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80068904;
    }
    goto skip_2;
    // 0x80068798: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8006879C: jal         0x80060FBC
    // 0x800687A0: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    Object_Kill(rdram, ctx);
        goto after_1;
    // 0x800687A0: addiu       $a1, $s0, 0x5C
    ctx->r5 = ADD32(ctx->r16, 0X5C);
    after_1:
    // 0x800687A4: b           L_80068904
    // 0x800687A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80068904;
    // 0x800687A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800687AC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_800687B0:
    // 0x800687B0: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x800687B4: addiu       $t0, $t0, 0x7E80
    ctx->r8 = ADD32(ctx->r8, 0X7E80);
    // 0x800687B8: swc1        $f18, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f18.u32l;
    // 0x800687BC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800687C0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800687C4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800687C8: bgezl       $t7, L_800687E0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800687CC: lb          $t1, 0x4C($s0)
        ctx->r9 = MEM_B(ctx->r16, 0X4C);
            goto L_800687E0;
    }
    goto skip_3;
    // 0x800687CC: lb          $t1, 0x4C($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X4C);
    skip_3:
    // 0x800687D0: sb          $t8, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r24;
    // 0x800687D4: b           L_80068900
    // 0x800687D8: sh          $t9, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r25;
        goto L_80068900;
    // 0x800687D8: sh          $t9, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r25;
    // 0x800687DC: lb          $t1, 0x4C($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X4C);
L_800687E0:
    // 0x800687E0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800687E4: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x800687E8: beq         $t1, $zero, L_80068900
    if (ctx->r9 == 0) {
        // 0x800687EC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_80068900;
    }
    // 0x800687EC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800687F0: lh          $t6, 0x4E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4E);
    // 0x800687F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800687F8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800687FC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80068800: sb          $t2, 0x46($s0)
    MEM_B(0X46, ctx->r16) = ctx->r10;
    // 0x80068804: sh          $t3, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r11;
    // 0x80068808: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8006880C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80068810: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80068814: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80068818: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8006881C: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80068820: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80068824: sw          $t4, 0x27C($t8)
    MEM_W(0X27C, ctx->r24) = ctx->r12;
    // 0x80068828: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8006882C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80068830: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80068834: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80068838: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8006883C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80068840: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x80068844: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x80068848: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8006884C: lw          $a0, -0xAC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XAC);
    // 0x80068850: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80068854: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80068858: jal         0x80019218
    // 0x8006885C: addiu       $a1, $a1, 0x460
    ctx->r5 = ADD32(ctx->r5, 0X460);
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8006885C: addiu       $a1, $a1, 0x460
    ctx->r5 = ADD32(ctx->r5, 0X460);
    after_2:
    // 0x80068860: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80068864: addiu       $t0, $t0, 0x7E80
    ctx->r8 = ADD32(ctx->r8, 0X7E80);
    // 0x80068868: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8006886C: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80068870: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80068874: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80068878: bne         $v0, $zero, L_80068890
    if (ctx->r2 != 0) {
        // 0x8006887C: addiu       $v1, $v1, -0x7D80
        ctx->r3 = ADD32(ctx->r3, -0X7D80);
            goto L_80068890;
    }
    // 0x8006887C: addiu       $v1, $v1, -0x7D80
    ctx->r3 = ADD32(ctx->r3, -0X7D80);
    // 0x80068880: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80068884: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80068888: swc1        $f16, 0x110($t3)
    MEM_W(0X110, ctx->r11) = ctx->f16.u32l;
    // 0x8006888C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
L_80068890:
    // 0x80068890: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80068894: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80068898: bne         $at, $zero, L_80068900
    if (ctx->r1 != 0) {
        // 0x8006889C: sw          $t6, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r14;
            goto L_80068900;
    }
    // 0x8006889C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800688A0: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800688A4: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800688A8: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x800688AC: sw          $t7, 0x1C8($t4)
    MEM_W(0X1C8, ctx->r12) = ctx->r15;
    // 0x800688B0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800688B4: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x800688B8: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x800688BC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x800688C0: sw          $zero, 0x1D0($t8)
    MEM_W(0X1D0, ctx->r24) = 0;
    // 0x800688C4: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800688C8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x800688CC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x800688D0: ori         $a0, $a0, 0x602A
    ctx->r4 = ctx->r4 | 0X602A;
    // 0x800688D4: jal         0x80019218
    // 0x800688D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x800688D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x800688DC: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x800688E0: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x800688E4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x800688E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800688EC: sb          $t1, 0x7930($at)
    MEM_B(0X7930, ctx->r1) = ctx->r9;
    // 0x800688F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800688F4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800688F8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800688FC: sb          $t2, 0x3180($at)
    MEM_B(0X3180, ctx->r1) = ctx->r10;
L_80068900:
    // 0x80068900: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80068904:
    // 0x80068904: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80068908: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006890C: jr          $ra
    // 0x80068910: nop

    return;
    // 0x80068910: nop

;}
RECOMP_FUNC void HUD_IncomingMsgSignal3_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008556C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80085570: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80085574: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80085578: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008557C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80085580: lui         $a1, 0x101
    ctx->r5 = S32(0X101 << 16);
    // 0x80085584: lui         $a2, 0x101
    ctx->r6 = S32(0X101 << 16);
    // 0x80085588: addiu       $t6, $zero, 0x1A
    ctx->r14 = ADD32(0, 0X1A);
    // 0x8008558C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80085590: addiu       $a2, $a2, 0x1E60
    ctx->r6 = ADD32(ctx->r6, 0X1E60);
    // 0x80085594: addiu       $a1, $a1, 0x1D90
    ctx->r5 = ADD32(ctx->r5, 0X1D90);
    // 0x80085598: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8008559C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x800855A0: swc1        $f12, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f12.u32l;
    // 0x800855A4: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800855A8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800855AC: jal         0x8009C320
    // 0x800855B0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_0;
    // 0x800855B0: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800855B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800855B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800855BC: jr          $ra
    // 0x800855C0: nop

    return;
    // 0x800855C0: nop

;}
RECOMP_FUNC void ActorTeamBoss_SetBoost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80091CF8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80091CFC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80091D00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80091D04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80091D08: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    // 0x80091D0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091D10: beql        $t6, $zero, L_80091D78
    if (ctx->r14 == 0) {
        // 0x80091D14: mtc1        $zero, $f0
        ctx->f0.u32l = 0;
            goto L_80091D78;
    }
    goto skip_0;
    // 0x80091D14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    skip_0:
    // 0x80091D18: lwc1        $f4, 0x13C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X13C);
    // 0x80091D1C: lwc1        $f6, 0x7F9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7F9C);
    // 0x80091D20: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80091D24: lui         $a0, 0x900
    ctx->r4 = S32(0X900 << 16);
    // 0x80091D28: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80091D2C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80091D30: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80091D34: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x80091D38: bc1f        L_80091D70
    if (!c1cs) {
        // 0x80091D3C: addiu       $a1, $s0, 0x100
        ctx->r5 = ADD32(ctx->r16, 0X100);
            goto L_80091D70;
    }
    // 0x80091D3C: addiu       $a1, $s0, 0x100
    ctx->r5 = ADD32(ctx->r16, 0X100);
    // 0x80091D40: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80091D44: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80091D48: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x80091D4C: swc1        $f8, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f8.u32l;
    // 0x80091D50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80091D54: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80091D58: jal         0x80019218
    // 0x80091D5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80091D5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80091D60: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80091D64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80091D68: nop

    // 0x80091D6C: swc1        $f10, 0x188($s0)
    MEM_W(0X188, ctx->r16) = ctx->f10.u32l;
L_80091D70:
    // 0x80091D70: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80091D74: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
L_80091D78:
    // 0x80091D78: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80091D7C: lui         $a3, 0x3E4C
    ctx->r7 = S32(0X3E4C << 16);
    // 0x80091D80: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80091D84: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80091D88: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091D8C: addiu       $a0, $s0, 0x13C
    ctx->r4 = ADD32(ctx->r16, 0X13C);
    // 0x80091D90: jal         0x8009BC2C
    // 0x80091D94: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80091D94: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80091D98: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80091D9C: lw          $a1, 0x13C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X13C);
    // 0x80091DA0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80091DA4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80091DA8: addiu       $a0, $s0, 0x138
    ctx->r4 = ADD32(ctx->r16, 0X138);
    // 0x80091DAC: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80091DB0: jal         0x8009BC2C
    // 0x80091DB4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80091DB4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80091DB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80091DBC: lwc1        $f4, 0x7FA0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7FA0);
    // 0x80091DC0: lwc1        $f18, 0x13C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X13C);
    // 0x80091DC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80091DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80091DCC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80091DD0: nop

    // 0x80091DD4: bc1f        L_80091DE0
    if (!c1cs) {
        // 0x80091DD8: nop
    
            goto L_80091DE0;
    }
    // 0x80091DD8: nop

    // 0x80091DDC: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
L_80091DE0:
    // 0x80091DE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80091DE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80091DE8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80091DEC: jr          $ra
    // 0x80091DF0: nop

    return;
    // 0x80091DF0: nop

;}
RECOMP_FUNC void Boss300_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042FE8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80042FEC: jr          $ra
    // 0x80042FF0: nop

    return;
    // 0x80042FF0: nop

;}
RECOMP_FUNC void Effect_FlamePillar_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DB70: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8007DB74: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8007DB78: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007DB7C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007DB80: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8007DB84: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8007DB88: addiu       $t6, $t6, 0x18D8
    ctx->r14 = ADD32(ctx->r14, 0X18D8);
    // 0x8007DB8C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8007DB90: sw          $at, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r1;
    // 0x8007DB94: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8007DB98: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8007DB9C: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8007DBA0: sw          $at, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r1;
    // 0x8007DBA4: lh          $v0, 0x4E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4E);
    // 0x8007DBA8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007DBAC: beql        $v0, $zero, L_8007DBCC
    if (ctx->r2 == 0) {
        // 0x8007DBB0: lwc1        $f4, 0x58($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
            goto L_8007DBCC;
    }
    goto skip_0;
    // 0x8007DBB0: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    skip_0:
    // 0x8007DBB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007DBB8: beql        $v0, $at, L_8007DD90
    if (ctx->r2 == ctx->r1) {
        // 0x8007DBBC: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8007DD90;
    }
    goto skip_1;
    // 0x8007DBBC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_1:
    // 0x8007DBC0: b           L_8007DEC4
    // 0x8007DBC4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8007DEC4;
    // 0x8007DBC4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007DBC8: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
L_8007DBCC:
    // 0x8007DBCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007DBD0: lhu         $t0, 0x50($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X50);
    // 0x8007DBD4: addiu       $a0, $zero, 0x3E8
    ctx->r4 = ADD32(0, 0X3E8);
    // 0x8007DBD8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007DBDC: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x8007DBE0: bne         $t0, $zero, L_8007DEC0
    if (ctx->r8 != 0) {
        // 0x8007DBE4: swc1        $f8, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
            goto L_8007DEC0;
    }
    // 0x8007DBE4: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x8007DBE8: jal         0x8006351C
    // 0x8007DBEC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_0;
    // 0x8007DBEC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x8007DBF0: bne         $v0, $zero, L_8007DC1C
    if (ctx->r2 != 0) {
        // 0x8007DBF4: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8007DC1C;
    }
    // 0x8007DBF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007DBF8: lwc1        $f16, 0x7940($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8007DBFC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007DC00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007DC04: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007DC08: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8007DC0C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x8007DC10: nop

    // 0x8007DC14: bc1fl       L_8007DEC4
    if (!c1cs) {
        // 0x8007DC18: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007DEC4;
    }
    goto skip_2;
    // 0x8007DC18: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_2:
L_8007DC1C:
    // 0x8007DC1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007DC20: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007DC24: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007DC28: swc1        $f2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f2.u32l;
    // 0x8007DC2C: lwc1        $f0, 0x7940($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8007DC30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007DC34: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007DC38: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8007DC3C: lui         $a0, 0x2903
    ctx->r4 = S32(0X2903 << 16);
    // 0x8007DC40: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8007DC44: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x8007DC48: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8007DC4C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007DC50: c.lt.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl < ctx->f16.fl;
    // 0x8007DC54: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x8007DC58: addiu       $t3, $zero, 0xC0
    ctx->r11 = ADD32(0, 0XC0);
    // 0x8007DC5C: ori         $a0, $a0, 0xB009
    ctx->r4 = ctx->r4 | 0XB009;
    // 0x8007DC60: bc1f        L_8007DC6C
    if (!c1cs) {
        // 0x8007DC64: addiu       $a1, $s0, 0x80
        ctx->r5 = ADD32(ctx->r16, 0X80);
            goto L_8007DC6C;
    }
    // 0x8007DC64: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    // 0x8007DC68: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
L_8007DC6C:
    // 0x8007DC6C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007DC70: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x8007DC74: sh          $t1, 0x4E($s0)
    MEM_H(0X4E, ctx->r16) = ctx->r9;
    // 0x8007DC78: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    // 0x8007DC7C: sh          $t3, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r11;
    // 0x8007DC80: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x8007DC84: swc1        $f0, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f0.u32l;
    // 0x8007DC88: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x8007DC8C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8007DC90: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x8007DC94: jal         0x80019218
    // 0x8007DC98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8007DC98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8007DC9C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007DCA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007DCA4: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007DCA8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007DCAC: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8007DCB0: lui         $a3, 0x40E0
    ctx->r7 = S32(0X40E0 << 16);
    // 0x8007DCB4: jal         0x8007D0E0
    // 0x8007DCB8: add.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f10.fl;
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_2;
    // 0x8007DCB8: add.s       $f14, $f18, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f10.fl;
    after_2:
    // 0x8007DCBC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8007DCC0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007DCC4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007DCC8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007DCCC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007DCD0: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007DCD4: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8007DCD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007DCDC: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8007DCE0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8007DCE4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8007DCE8: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8007DCEC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8007DCF0: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8007DCF4: jal         0x8007BFFC
    // 0x8007DCF8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Effect_Effect386_Spawn1(rdram, ctx);
        goto after_3;
    // 0x8007DCF8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x8007DCFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007DD00: lwc1        $f18, 0x7940($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x8007DD04: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8007DD08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007DD0C: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007DD10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007DD14: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8007DD18: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8007DD1C: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8007DD20: nop

    // 0x8007DD24: bc1tl       L_8007DD40
    if (c1cs) {
        // 0x8007DD28: lwc1        $f12, 0x4($s0)
        ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
            goto L_8007DD40;
    }
    goto skip_3;
    // 0x8007DD28: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x8007DD2C: lw          $t8, 0x1A88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1A88);
    // 0x8007DD30: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007DD34: beql        $t8, $at, L_8007DEC4
    if (ctx->r24 == ctx->r1) {
        // 0x8007DD38: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007DEC4;
    }
    goto skip_4;
    // 0x8007DD38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_4:
    // 0x8007DD3C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
L_8007DD40:
    // 0x8007DD40: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007DD44: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8007DD48: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8007DD4C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8007DD50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007DD54: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007DD58: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007DD5C: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8007DD60: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007DD64: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007DD68: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007DD6C: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8007DD70: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x8007DD74: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8007DD78: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8007DD7C: jal         0x800365E4
    // 0x8007DD80: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    PlayerShot_Effect344_Spawn(rdram, ctx);
        goto after_4;
    // 0x8007DD80: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_4:
    // 0x8007DD84: b           L_8007DEC4
    // 0x8007DD88: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_8007DEC4;
    // 0x8007DD88: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007DD8C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8007DD90:
    // 0x8007DD90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007DD94: lwc1        $f0, 0x70($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007DD98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DD9C: lwc1        $f16, 0x7454($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7454);
    // 0x8007DDA0: sub.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8007DDA4: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x8007DDA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007DDAC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007DDB0: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8007DDB4: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8007DDB8: swc1        $f8, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f8.u32l;
    // 0x8007DDBC: lwc1        $f18, 0x70($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007DDC0: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8007DDC4: nop

    // 0x8007DDC8: bc1fl       L_8007DE04
    if (!c1cs) {
        // 0x8007DDCC: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_8007DE04;
    }
    goto skip_5;
    // 0x8007DDCC: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_5:
    // 0x8007DDD0: lh          $t7, 0x44($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X44);
    // 0x8007DDD4: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x8007DDD8: lwc1        $f16, 0x7458($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7458);
    // 0x8007DDDC: addiu       $t6, $t7, -0x14
    ctx->r14 = ADD32(ctx->r15, -0X14);
    // 0x8007DDE0: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
    // 0x8007DDE4: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8007DDE8: lh          $t9, 0x44($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X44);
    // 0x8007DDEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007DDF0: bgez        $t9, L_8007DE00
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8007DDF4: swc1        $f4, 0x6C($s0)
        MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
            goto L_8007DE00;
    }
    // 0x8007DDF4: swc1        $f4, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f4.u32l;
    // 0x8007DDF8: jal         0x80060FBC
    // 0x8007DDFC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_5;
    // 0x8007DDFC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_5:
L_8007DE00:
    // 0x8007DE00: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_8007DE04:
    // 0x8007DE04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007DE08: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8007DE0C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8007DE10: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007DE14: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8007DE18: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8007DE1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007DE20: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8007DE24: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x8007DE28: lwc1        $f10, 0x138($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X138);
    // 0x8007DE2C: sub.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8007DE30: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007DE34: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8007DE38: nop

    // 0x8007DE3C: bc1fl       L_8007DEC4
    if (!c1cs) {
        // 0x8007DE40: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007DEC4;
    }
    goto skip_6;
    // 0x8007DE40: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_6:
    // 0x8007DE44: lwc1        $f8, 0x74($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8007DE48: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007DE4C: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x8007DE50: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007DE54: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8007DE58: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007DE5C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8007DE60: nop

    // 0x8007DE64: bc1fl       L_8007DEC4
    if (!c1cs) {
        // 0x8007DE68: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007DEC4;
    }
    goto skip_7;
    // 0x8007DE68: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x8007DE6C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007DE70: lwc1        $f2, 0x78($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8007DE74: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8007DE78: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007DE7C: nop

    // 0x8007DE80: bc1fl       L_8007DEC4
    if (!c1cs) {
        // 0x8007DE84: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007DEC4;
    }
    goto skip_8;
    // 0x8007DE84: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_8:
    // 0x8007DE88: lwc1        $f16, 0x70($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8007DE8C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007DE90: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007DE94: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8007DE98: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8007DE9C: nop

    // 0x8007DEA0: bc1fl       L_8007DEC4
    if (!c1cs) {
        // 0x8007DEA4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007DEC4;
    }
    goto skip_9;
    // 0x8007DEA4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_9:
    // 0x8007DEA8: lw          $t0, 0x498($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X498);
    // 0x8007DEAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8007DEB0: bnel        $t0, $zero, L_8007DEC4
    if (ctx->r8 != 0) {
        // 0x8007DEB4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8007DEC4;
    }
    goto skip_10;
    // 0x8007DEB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_10:
    // 0x8007DEB8: jal         0x800A6CD0
    // 0x8007DEBC: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    Player_ApplyDamage(rdram, ctx);
        goto after_6;
    // 0x8007DEBC: lbu         $a2, 0x34($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X34);
    after_6:
L_8007DEC0:
    // 0x8007DEC0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8007DEC4:
    // 0x8007DEC4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8007DEC8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8007DECC: jr          $ra
    // 0x8007DED0: nop

    return;
    // 0x8007DED0: nop

;}
RECOMP_FUNC void Effect_ElectricArc_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C484: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007C488: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007C48C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8007C490: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8007C494: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8007C498: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8007C49C: addiu       $v0, $v0, 0x12B0
    ctx->r2 = ADD32(ctx->r2, 0X12B0);
    // 0x8007C4A0: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    // 0x8007C4A4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_8007C4A8:
    // 0x8007C4A8: bnel        $t6, $zero, L_8007C4F4
    if (ctx->r14 != 0) {
        // 0x8007C4AC: addiu       $a0, $a0, -0x8C
        ctx->r4 = ADD32(ctx->r4, -0X8C);
            goto L_8007C4F4;
    }
    goto skip_0;
    // 0x8007C4AC: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
    skip_0:
    // 0x8007C4B0: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8007C4B4: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007C4B8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8007C4BC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007C4C0: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8007C4C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8007C4C8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8007C4CC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8007C4D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8007C4D4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8007C4D8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8007C4DC: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8007C4E0: jal         0x8007C3B4
    // 0x8007C4E4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    Effect_ElectricArc_Setup(rdram, ctx);
        goto after_0;
    // 0x8007C4E4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x8007C4E8: b           L_8007C500
    // 0x8007C4EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8007C500;
    // 0x8007C4EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C4F0: addiu       $a0, $a0, -0x8C
    ctx->r4 = ADD32(ctx->r4, -0X8C);
L_8007C4F4:
    // 0x8007C4F4: bnel        $a0, $v0, L_8007C4A8
    if (ctx->r4 != ctx->r2) {
        // 0x8007C4F8: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_8007C4A8;
    }
    goto skip_1;
    // 0x8007C4F8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x8007C4FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8007C500:
    // 0x8007C500: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8007C504: jr          $ra
    // 0x8007C508: nop

    return;
    // 0x8007C508: nop

;}
RECOMP_FUNC void func_versus_800C2198(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2198: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C219C: lwc1        $f2, -0x6CDC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6CDC);
    // 0x800C21A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C21A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800C21A8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C21AC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C21B0: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x800C21B4: lwc1        $f16, -0x6CD8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6CD8);
    // 0x800C21B8: mul.s       $f6, $f12, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800C21BC: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C21C0: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C21C4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C21C8: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800C21CC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800C21D0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800C21D4: nop

    // 0x800C21D8: bc1fl       L_800C223C
    if (!c1cs) {
        // 0x800C21DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C223C;
    }
    goto skip_0;
    // 0x800C21DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800C21E0: mul.s       $f4, $f14, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800C21E4: lwc1        $f18, 0xC($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800C21E8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800C21EC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800C21F0: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800C21F4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800C21F8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800C21FC: nop

    // 0x800C2200: bc1fl       L_800C223C
    if (!c1cs) {
        // 0x800C2204: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C223C;
    }
    goto skip_1;
    // 0x800C2204: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800C2208: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800C220C: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800C2210: lui         $at, 0x442F
    ctx->r1 = S32(0X442F << 16);
    // 0x800C2214: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2218: sub.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800C221C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800C2220: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800C2224: nop

    // 0x800C2228: bc1fl       L_800C223C
    if (!c1cs) {
        // 0x800C222C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C223C;
    }
    goto skip_2;
    // 0x800C222C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800C2230: jr          $ra
    // 0x800C2234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C2234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C2238: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C223C:
    // 0x800C223C: jr          $ra
    // 0x800C2240: nop

    return;
    // 0x800C2240: nop

;}
RECOMP_FUNC void guOrtho(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021654: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80021658: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8002165C: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x80021660: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x80021664: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80021668: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8002166C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80021670: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80021674: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80021678: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8002167C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80021680: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x80021684: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80021688: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8002168C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80021690: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80021694: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80021698: jal         0x80021500
    // 0x8002169C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    guOrthoF(rdram, ctx);
        goto after_0;
    // 0x8002169C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800216A0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800216A4: jal         0x80026CD0
    // 0x800216A8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800216A8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x800216AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800216B0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800216B4: jr          $ra
    // 0x800216B8: nop

    return;
    // 0x800216B8: nop

;}
RECOMP_FUNC void Effect_FireSmoke_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D55C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007D560: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8007D564: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007D568: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007D56C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8007D570: jal         0x8005980C
    // 0x8007D574: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    Graphics_SetScaleMtx(rdram, ctx);
        goto after_0;
    // 0x8007D574: lwc1        $f12, 0x70($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X70);
    after_0:
    // 0x8007D578: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8007D57C: lbu         $t6, 0x7C98($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X7C98);
    // 0x8007D580: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8007D584: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8007D588: bne         $t6, $zero, L_8007D66C
    if (ctx->r14 != 0) {
        // 0x8007D58C: nop
    
            goto L_8007D66C;
    }
    // 0x8007D58C: nop

    // 0x8007D590: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8007D594: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8007D598: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007D59C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8007D5A0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x8007D5A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007D5A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007D5AC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007D5B0: lbu         $t9, 0x4C($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X4C);
    // 0x8007D5B4: addiu       $t2, $t2, 0x184C
    ctx->r10 = ADD32(ctx->r10, 0X184C);
    // 0x8007D5B8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007D5BC: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x8007D5C0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8007D5C4: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x8007D5C8: lbu         $t1, 0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1);
    // 0x8007D5CC: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x8007D5D0: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x8007D5D4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8007D5D8: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x8007D5DC: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x8007D5E0: sll         $t4, $t6, 8
    ctx->r12 = S32(ctx->r14 << 8);
    // 0x8007D5E4: or          $t7, $t3, $t4
    ctx->r15 = ctx->r11 | ctx->r12;
    // 0x8007D5E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007D5EC: lbu         $t9, 0x4C($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X4C);
    // 0x8007D5F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007D5F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007D5F8: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007D5FC: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8007D600: lwc1        $f4, 0x17F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X17F8);
    // 0x8007D604: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007D608: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007D60C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8007D610: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8007D614: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8007D618: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8007D61C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8007D620: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007D624: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007D628: jal         0x80005C34
    // 0x8007D62C: nop

    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x8007D62C: nop

    after_1:
    // 0x8007D630: jal         0x80006EB8
    // 0x8007D634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8007D634: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8007D638: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007D63C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8007D640: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x8007D644: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007D648: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x8007D64C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007D650: lbu         $t6, 0x4C($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X4C);
    // 0x8007D654: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x8007D658: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8007D65C: lw          $t4, 0x17A4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X17A4);
    // 0x8007D660: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8007D664: b           L_8007D738
    // 0x8007D668: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007D738;
    // 0x8007D668: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007D66C:
    // 0x8007D66C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007D670: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8007D674: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8007D678: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007D67C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8007D680: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007D684: lh          $t1, 0x44($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X44);
    // 0x8007D688: ori         $at, $at, 0x6400
    ctx->r1 = ctx->r1 | 0X6400;
    // 0x8007D68C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8007D690: andi        $t8, $t1, 0xFF
    ctx->r24 = ctx->r9 & 0XFF;
    // 0x8007D694: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x8007D698: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8007D69C: lbu         $t5, 0x4C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X4C);
    // 0x8007D6A0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8007D6A4: bnel        $t5, $zero, L_8007D70C
    if (ctx->r13 != 0) {
        // 0x8007D6A8: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8007D70C;
    }
    goto skip_0;
    // 0x8007D6A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8007D6AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007D6B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007D6B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8007D6B8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007D6BC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007D6C0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007D6C4: jal         0x80005C34
    // 0x8007D6C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8007D6C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_3:
    // 0x8007D6CC: jal         0x80006EB8
    // 0x8007D6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8007D6D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8007D6D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8007D6D8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8007D6DC: lui         $t1, 0x800D
    ctx->r9 = S32(0X800D << 16);
    // 0x8007D6E0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007D6E4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8007D6E8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007D6EC: lbu         $t7, 0x4C($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X4C);
    // 0x8007D6F0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007D6F4: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8007D6F8: lw          $t1, 0x18A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X18A0);
    // 0x8007D6FC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007D700: b           L_8007D738
    // 0x8007D704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8007D738;
    // 0x8007D704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007D708: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8007D70C:
    // 0x8007D70C: lui         $t2, 0x600
    ctx->r10 = S32(0X600 << 16);
    // 0x8007D710: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x8007D714: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007D718: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8007D71C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8007D720: lbu         $t5, 0x4C($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X4C);
    // 0x8007D724: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8007D728: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x8007D72C: lw          $t3, 0x18A0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X18A0);
    // 0x8007D730: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8007D734: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007D738:
    // 0x8007D738: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D73C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8007D740: jr          $ra
    // 0x8007D744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007D744: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ActorAllRange_PlayMessage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F5F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002F5F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F5FC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8002F600: lw          $t6, -0x7D00($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D00);
    // 0x8002F604: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8002F608: bnel        $t6, $zero, L_8002F640
    if (ctx->r14 != 0) {
        // 0x8002F60C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002F640;
    }
    goto skip_0;
    // 0x8002F60C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002F610: lh          $t7, 0x4098($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X4098);
    // 0x8002F614: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002F618: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8002F61C: bnel        $t7, $at, L_8002F640
    if (ctx->r15 != ctx->r1) {
        // 0x8002F620: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002F640;
    }
    goto skip_1;
    // 0x8002F620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8002F624: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8002F628: lw          $t9, 0x1C8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C8);
    // 0x8002F62C: beql        $t9, $zero, L_8002F640
    if (ctx->r25 == 0) {
        // 0x8002F630: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002F640;
    }
    goto skip_2;
    // 0x8002F630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8002F634: jal         0x800BA808
    // 0x8002F638: nop

    Radio_PlayMessage(rdram, ctx);
        goto after_0;
    // 0x8002F638: nop

    after_0:
    // 0x8002F63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002F640:
    // 0x8002F640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002F644: jr          $ra
    // 0x8002F648: nop

    return;
    // 0x8002F648: nop

;}
RECOMP_FUNC void func_versus_800BCC48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCC48: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800BCC4C: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800BCC50: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800BCC54: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800BCC58: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800BCC5C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x800BCC60: mtc1        $a2, $f26
    ctx->f26.u32l = ctx->r6;
    // 0x800BCC64: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x800BCC68: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x800BCC6C: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800BCC70: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x800BCC74: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x800BCC78: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x800BCC7C: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x800BCC80: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800BCC84: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800BCC88: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800BCC8C: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800BCC90: addiu       $t7, $t7, 0x4AC8
    ctx->r15 = ADD32(ctx->r15, 0X4AC8);
    // 0x800BCC94: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x800BCC98: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x800BCC9C: addiu       $t6, $sp, 0xA8
    ctx->r14 = ADD32(ctx->r29, 0XA8);
    // 0x800BCCA0: sw          $at, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r1;
    // 0x800BCCA4: sw          $t0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r8;
    // 0x800BCCA8: lw          $t0, 0xC($t7)
    ctx->r8 = MEM_W(ctx->r15, 0XC);
    // 0x800BCCAC: lw          $at, 0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X8);
    // 0x800BCCB0: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800BCCB4: addiu       $t2, $t2, 0x4AD8
    ctx->r10 = ADD32(ctx->r10, 0X4AD8);
    // 0x800BCCB8: sw          $t0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r8;
    // 0x800BCCBC: sw          $at, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r1;
    // 0x800BCCC0: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x800BCCC4: lw          $at, 0x0($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X0);
    // 0x800BCCC8: addiu       $t1, $sp, 0x98
    ctx->r9 = ADD32(ctx->r29, 0X98);
    // 0x800BCCCC: sw          $t5, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r13;
    // 0x800BCCD0: sw          $at, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r1;
    // 0x800BCCD4: lw          $at, 0x8($t2)
    ctx->r1 = MEM_W(ctx->r10, 0X8);
    // 0x800BCCD8: lw          $t5, 0xC($t2)
    ctx->r13 = MEM_W(ctx->r10, 0XC);
    // 0x800BCCDC: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800BCCE0: addiu       $t8, $t8, 0x4AE8
    ctx->r24 = ADD32(ctx->r24, 0X4AE8);
    // 0x800BCCE4: sw          $at, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r1;
    // 0x800BCCE8: sw          $t5, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r13;
    // 0x800BCCEC: lw          $t0, 0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X4);
    // 0x800BCCF0: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x800BCCF4: addiu       $t9, $sp, 0x88
    ctx->r25 = ADD32(ctx->r29, 0X88);
    // 0x800BCCF8: sw          $t0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r8;
    // 0x800BCCFC: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800BCD00: lw          $at, 0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X8);
    // 0x800BCD04: lw          $t0, 0xC($t8)
    ctx->r8 = MEM_W(ctx->r24, 0XC);
    // 0x800BCD08: addiu       $t2, $sp, 0xA8
    ctx->r10 = ADD32(ctx->r29, 0XA8);
    // 0x800BCD0C: sw          $at, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r1;
    // 0x800BCD10: sw          $t0, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->r8;
    // 0x800BCD14: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x800BCD18: addiu       $t3, $sp, 0x88
    ctx->r11 = ADD32(ctx->r29, 0X88);
    // 0x800BCD1C: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800BCD20: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800BCD24: addu        $s2, $t4, $t3
    ctx->r18 = ADD32(ctx->r12, ctx->r11);
    // 0x800BCD28: addu        $s3, $t4, $t1
    ctx->r19 = ADD32(ctx->r12, ctx->r9);
    // 0x800BCD2C: addu        $s4, $t4, $t2
    ctx->r20 = ADD32(ctx->r12, ctx->r10);
    // 0x800BCD30: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x800BCD34: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BCD38: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800BCD3C: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
L_800BCD40:
    // 0x800BCD40: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800BCD44: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800BCD48: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BCD4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BCD50: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800BCD54: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCD58: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800BCD5C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x800BCD60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800BCD64: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BCD68: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BCD6C: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x800BCD70: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BCD74: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BCD78: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800BCD7C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BCD80: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x800BCD84: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    // 0x800BCD88: jal         0x8009D0BC
    // 0x800BCD8C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_0;
    // 0x800BCD8C: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800BCD90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BCD94: bne         $s0, $s6, L_800BCD40
    if (ctx->r16 != ctx->r22) {
        // 0x800BCD98: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800BCD40;
    }
    // 0x800BCD98: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800BCD9C: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x800BCDA0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800BCDA4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800BCDA8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BCDAC: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x800BCDB0: multu       $t8, $s0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCDB4: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800BCDB8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800BCDBC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800BCDC0: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800BCDC4: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x800BCDC8: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x800BCDCC: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800BCDD0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800BCDD4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800BCDD8: mflo        $t0
    ctx->r8 = lo;
    // 0x800BCDDC: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800BCDE0: addu        $a1, $t0, $t4
    ctx->r5 = ADD32(ctx->r8, ctx->r12);
    // 0x800BCDE4: jal         0x8009D0BC
    // 0x800BCDE8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x800BCDE8: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800BCDEC: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800BCDF0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800BCDF4: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800BCDF8: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800BCDFC: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800BCE00: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800BCE04: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800BCE08: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800BCE0C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x800BCE10: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x800BCE14: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x800BCE18: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x800BCE1C: jr          $ra
    // 0x800BCE20: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800BCE20: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void Object_UpdateSfxSource(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005F1EC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005F1F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005F1F4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8005F1F8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005F1FC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8005F200: addiu       $t6, $t6, -0x2D8
    ctx->r14 = ADD32(ctx->r14, -0X2D8);
    // 0x8005F204: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8005F208: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8005F20C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8005F210: sw          $at, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r1;
    // 0x8005F214: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x8005F218: addiu       $a0, $a0, 0x15F0
    ctx->r4 = ADD32(ctx->r4, 0X15F0);
    // 0x8005F21C: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x8005F220: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8005F224: lw          $at, 0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X8);
    // 0x8005F228: sw          $at, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r1;
    // 0x8005F22C: lw          $t0, 0x78A8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A8);
    // 0x8005F230: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005F234: beq         $t0, $at, L_8005F254
    if (ctx->r8 == ctx->r1) {
        // 0x8005F238: nop
    
            goto L_8005F254;
    }
    // 0x8005F238: nop

    // 0x8005F23C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005F240: nop

    // 0x8005F244: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    // 0x8005F248: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x8005F24C: b           L_8005F278
    // 0x8005F250: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
        goto L_8005F278;
    // 0x8005F250: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
L_8005F254:
    // 0x8005F254: jal         0x80006970
    // 0x8005F258: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    Matrix_MultVec3f(rdram, ctx);
        goto after_0;
    // 0x8005F258: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005F25C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8005F260: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8005F264: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x8005F268: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005F26C: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x8005F270: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8005F274: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
L_8005F278:
    // 0x8005F278: jal         0x8005F030
    // 0x8005F27C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    Object_ClampSfxSource(rdram, ctx);
        goto after_1;
    // 0x8005F27C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_1:
    // 0x8005F280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005F284: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8005F288: jr          $ra
    // 0x8005F28C: nop

    return;
    // 0x8005F28C: nop

;}
RECOMP_FUNC void Timer_Increment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007068: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8000706C: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80007070: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80007074: jr          $ra
    // 0x80007078: nop

    return;
    // 0x80007078: nop

;}
RECOMP_FUNC void func_enmy_8006566C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006566C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065670: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065674: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065678: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006567C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80065680: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80065684: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80065688: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8006568C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80065690:
    // 0x80065690: bnel        $t6, $zero, L_800656BC
    if (ctx->r14 != 0) {
        // 0x80065694: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_800656BC;
    }
    goto skip_0;
    // 0x80065694: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_0:
    // 0x80065698: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8006569C: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800656A0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800656A4: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x800656A8: jal         0x800655C8
    // 0x800656AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_enmy_800655C8(rdram, ctx);
        goto after_0;
    // 0x800656AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x800656B0: b           L_800656C8
    // 0x800656B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800656C8;
    // 0x800656B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800656B8: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_800656BC:
    // 0x800656BC: bnel        $a0, $v0, L_80065690
    if (ctx->r4 != ctx->r2) {
        // 0x800656C0: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80065690;
    }
    goto skip_1;
    // 0x800656C0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_1:
    // 0x800656C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800656C8:
    // 0x800656C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800656CC: jr          $ra
    // 0x800656D0: nop

    return;
    // 0x800656D0: nop

;}
RECOMP_FUNC void Audio_InitNoteFreeList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800128B4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800128B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800128BC: lui         $s3, 0x8015
    ctx->r19 = S32(0X8015 << 16);
    // 0x800128C0: addiu       $s3, $s3, 0x30C0
    ctx->r19 = ADD32(ctx->r19, 0X30C0);
    // 0x800128C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800128C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800128CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800128D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800128D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800128D8: jal         0x80012864
    // 0x800128DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Audio_InitNoteLists(rdram, ctx);
        goto after_0;
    // 0x800128DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800128E0: lui         $s4, 0x8015
    ctx->r20 = S32(0X8015 << 16);
    // 0x800128E4: addiu       $s4, $s4, 0x5CA0
    ctx->r20 = ADD32(ctx->r20, 0X5CA0);
    // 0x800128E8: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800128EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800128F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800128F4: blez        $t6, L_80012944
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800128F8: lui         $s2, 0x8015
        ctx->r18 = S32(0X8015 << 16);
            goto L_80012944;
    }
    // 0x800128F8: lui         $s2, 0x8015
    ctx->r18 = S32(0X8015 << 16);
    // 0x800128FC: addiu       $s2, $s2, -0x1AD0
    ctx->r18 = ADD32(ctx->r18, -0X1AD0);
    // 0x80012900: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_80012904:
    // 0x80012904: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80012908: addu        $t7, $s0, $v0
    ctx->r15 = ADD32(ctx->r16, ctx->r2);
    // 0x8001290C: addu        $t8, $v0, $s0
    ctx->r24 = ADD32(ctx->r2, ctx->r16);
    // 0x80012910: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80012914: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80012918: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8001291C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80012920: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80012924: jal         0x800145BC
    // 0x80012928: addu        $a1, $s0, $t1
    ctx->r5 = ADD32(ctx->r16, ctx->r9);
    AudioSeq_AudioListPushBack(rdram, ctx);
        goto after_1;
    // 0x80012928: addu        $a1, $s0, $t1
    ctx->r5 = ADD32(ctx->r16, ctx->r9);
    after_1:
    // 0x8001292C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80012930: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80012934: addiu       $s0, $s0, 0xC0
    ctx->r16 = ADD32(ctx->r16, 0XC0);
    // 0x80012938: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001293C: bnel        $at, $zero, L_80012904
    if (ctx->r1 != 0) {
        // 0x80012940: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_80012904;
    }
    goto skip_0;
    // 0x80012940: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_80012944:
    // 0x80012944: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80012948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001294C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80012950: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80012954: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80012958: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001295C: jr          $ra
    // 0x80012960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80012960: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_enmy_800655C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800655C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800655CC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800655D0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800655D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800655D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800655DC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800655E0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800655E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800655E8: jal         0x800613C4
    // 0x800655EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Actor_Initialize(rdram, ctx);
        goto after_0;
    // 0x800655EC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800655F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800655F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800655F8: addiu       $t7, $zero, 0xBE
    ctx->r15 = ADD32(0, 0XBE);
    // 0x800655FC: sb          $t6, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r14;
    // 0x80065600: sh          $t7, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r15;
    // 0x80065604: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80065608: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8006560C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80065610: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80065614: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80065618: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x8006561C: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80065620: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x80065624: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80065628: swc1        $f8, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f8.u32l;
    // 0x8006562C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80065630: sh          $t9, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r25;
    // 0x80065634: sh          $t8, 0xB4($a2)
    MEM_H(0XB4, ctx->r6) = ctx->r24;
    // 0x80065638: lh          $t0, 0xB4($a2)
    ctx->r8 = MEM_H(ctx->r6, 0XB4);
    // 0x8006563C: bnel        $t0, $at, L_8006564C
    if (ctx->r8 != ctx->r1) {
        // 0x80065640: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_8006564C;
    }
    goto skip_0;
    // 0x80065640: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    skip_0:
    // 0x80065644: sh          $t1, 0xBE($a2)
    MEM_H(0XBE, ctx->r6) = ctx->r9;
    // 0x80065648: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
L_8006564C:
    // 0x8006564C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80065650: lhu         $a1, 0x2($a2)
    ctx->r5 = MEM_HU(ctx->r6, 0X2);
    // 0x80065654: jal         0x800612B8
    // 0x80065658: swc1        $f10, 0x128($a2)
    MEM_W(0X128, ctx->r6) = ctx->f10.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80065658: swc1        $f10, 0x128($a2)
    MEM_W(0X128, ctx->r6) = ctx->f10.u32l;
    after_1:
    // 0x8006565C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065660: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80065664: jr          $ra
    // 0x80065668: nop

    return;
    // 0x80065668: nop

;}
RECOMP_FUNC void Player_UpdateEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B39E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B39E4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B39E8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B39EC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B39F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B39F4: lw          $v0, 0x1F8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F8);
    // 0x800B39F8: lwc1        $f4, 0x74($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B39FC: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B3A00: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800B3A04: swc1        $f0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f0.u32l;
    // 0x800B3A08: swc1        $f4, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f4.u32l;
    // 0x800B3A0C: swc1        $f6, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->f6.u32l;
    // 0x800B3A10: beq         $v0, $zero, L_800B3A20
    if (ctx->r2 == 0) {
        // 0x800B3A14: swc1        $f8, 0x98($s0)
        MEM_W(0X98, ctx->r16) = ctx->f8.u32l;
            goto L_800B3A20;
    }
    // 0x800B3A14: swc1        $f8, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->f8.u32l;
    // 0x800B3A18: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800B3A1C: sw          $t6, 0x1F8($s0)
    MEM_W(0X1F8, ctx->r16) = ctx->r14;
L_800B3A20:
    // 0x800B3A20: lw          $v0, 0x1FC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1FC);
    // 0x800B3A24: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B3A28: beq         $v0, $zero, L_800B3A34
    if (ctx->r2 == 0) {
        // 0x800B3A2C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800B3A34;
    }
    // 0x800B3A2C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800B3A30: sw          $t7, 0x1FC($s0)
    MEM_W(0X1FC, ctx->r16) = ctx->r15;
L_800B3A34:
    // 0x800B3A34: lw          $v0, 0x220($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X220);
    // 0x800B3A38: beq         $v0, $zero, L_800B3A44
    if (ctx->r2 == 0) {
        // 0x800B3A3C: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_800B3A44;
    }
    // 0x800B3A3C: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800B3A40: sw          $t8, 0x220($s0)
    MEM_W(0X220, ctx->r16) = ctx->r24;
L_800B3A44:
    // 0x800B3A44: lw          $v0, 0x498($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X498);
    // 0x800B3A48: beq         $v0, $zero, L_800B3A54
    if (ctx->r2 == 0) {
        // 0x800B3A4C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800B3A54;
    }
    // 0x800B3A4C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800B3A50: sw          $t9, 0x498($s0)
    MEM_W(0X498, ctx->r16) = ctx->r25;
L_800B3A54:
    // 0x800B3A54: lw          $v0, 0x224($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X224);
    // 0x800B3A58: beq         $v0, $zero, L_800B3A64
    if (ctx->r2 == 0) {
        // 0x800B3A5C: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800B3A64;
    }
    // 0x800B3A5C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800B3A60: sw          $t2, 0x224($s0)
    MEM_W(0X224, ctx->r16) = ctx->r10;
L_800B3A64:
    // 0x800B3A64: lw          $t3, 0x78E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X78E8);
    // 0x800B3A68: beq         $t3, $zero, L_800B3AE4
    if (ctx->r11 == 0) {
        // 0x800B3A6C: lui         $t1, 0x8017
        ctx->r9 = S32(0X8017 << 16);
            goto L_800B3AE4;
    }
    // 0x800B3A6C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x800B3A70: lw          $t1, 0x78A8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A8);
    // 0x800B3A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B3A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B3A7C: blez        $t1, L_800B3AE4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800B3A80: addiu       $t0, $zero, 0x6
        ctx->r8 = ADD32(0, 0X6);
            goto L_800B3AE4;
    }
    // 0x800B3A80: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800B3A84: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B3A88: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x800B3A8C: addiu       $a2, $a2, 0x7B00
    ctx->r6 = ADD32(ctx->r6, 0X7B00);
    // 0x800B3A90: addiu       $a3, $a3, -0x2780
    ctx->r7 = ADD32(ctx->r7, -0X2780);
L_800B3A94:
    // 0x800B3A94: lw          $t4, 0x1C4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3A98: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800B3A9C: addu        $t6, $a2, $t5
    ctx->r14 = ADD32(ctx->r6, ctx->r13);
    // 0x800B3AA0: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x800B3AA4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800B3AA8: beql        $a0, $zero, L_800B3AD8
    if (ctx->r4 == 0) {
        // 0x800B3AAC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800B3AD8;
    }
    goto skip_0;
    // 0x800B3AAC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x800B3AB0: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3AB4: addiu       $t3, $a0, -0x1
    ctx->r11 = ADD32(ctx->r4, -0X1);
    // 0x800B3AB8: mflo        $t7
    ctx->r15 = lo;
    // 0x800B3ABC: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x800B3AC0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800B3AC4: andi        $t2, $t9, 0x8000
    ctx->r10 = ctx->r25 & 0X8000;
    // 0x800B3AC8: bnel        $t2, $zero, L_800B3AD8
    if (ctx->r10 != 0) {
        // 0x800B3ACC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800B3AD8;
    }
    goto skip_1;
    // 0x800B3ACC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_1:
    // 0x800B3AD0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800B3AD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800B3AD8:
    // 0x800B3AD8: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800B3ADC: bne         $at, $zero, L_800B3A94
    if (ctx->r1 != 0) {
        // 0x800B3AE0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800B3A94;
    }
    // 0x800B3AE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800B3AE4:
    // 0x800B3AE4: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3AE8: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B3AEC: addiu       $a1, $a1, 0x7D40
    ctx->r5 = ADD32(ctx->r5, 0X7D40);
    // 0x800B3AF0: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800B3AF4: addu        $v1, $a1, $t4
    ctx->r3 = ADD32(ctx->r5, ctx->r12);
    // 0x800B3AF8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800B3AFC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x800B3B00: beq         $a0, $zero, L_800B3B3C
    if (ctx->r4 == 0) {
        // 0x800B3B04: addiu       $t5, $a0, -0x1
        ctx->r13 = ADD32(ctx->r4, -0X1);
            goto L_800B3B3C;
    }
    // 0x800B3B04: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    // 0x800B3B08: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800B3B0C: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3B10: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800B3B14: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800B3B18: addu        $v1, $a1, $t6
    ctx->r3 = ADD32(ctx->r5, ctx->r14);
    // 0x800B3B1C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B3B20: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x800B3B24: bne         $t7, $at, L_800B3B3C
    if (ctx->r15 != ctx->r1) {
        // 0x800B3B28: nop
    
            goto L_800B3B3C;
    }
    // 0x800B3B28: nop

    // 0x800B3B2C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B3B30: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3B34: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800B3B38: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800B3B3C:
    // 0x800B3B3C: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x800B3B40: addiu       $a1, $a1, 0x7D58
    ctx->r5 = ADD32(ctx->r5, 0X7D58);
    // 0x800B3B44: addu        $v1, $a1, $v0
    ctx->r3 = ADD32(ctx->r5, ctx->r2);
    // 0x800B3B48: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800B3B4C: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B3B50: addiu       $t5, $t5, 0x7D88
    ctx->r13 = ADD32(ctx->r13, 0X7D88);
    // 0x800B3B54: beq         $a0, $zero, L_800B3B94
    if (ctx->r4 == 0) {
        // 0x800B3B58: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_800B3B94;
    }
    // 0x800B3B58: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B3B5C: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x800B3B60: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B3B64: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3B68: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x800B3B6C: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800B3B70: addu        $v1, $a1, $t2
    ctx->r3 = ADD32(ctx->r5, ctx->r10);
    // 0x800B3B74: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800B3B78: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800B3B7C: bnel        $t3, $at, L_800B3B98
    if (ctx->r11 != ctx->r1) {
        // 0x800B3B80: addu        $v1, $v0, $t5
        ctx->r3 = ADD32(ctx->r2, ctx->r13);
            goto L_800B3B98;
    }
    goto skip_2;
    // 0x800B3B80: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    skip_2:
    // 0x800B3B84: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800B3B88: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3B8C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800B3B90: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
L_800B3B94:
    // 0x800B3B94: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
L_800B3B98:
    // 0x800B3B98: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800B3B9C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B3BA0: addiu       $t8, $t8, 0x7D70
    ctx->r24 = ADD32(ctx->r24, 0X7D70);
    // 0x800B3BA4: beq         $a0, $zero, L_800B3BC0
    if (ctx->r4 == 0) {
        // 0x800B3BA8: addiu       $t3, $t3, 0x7AE8
        ctx->r11 = ADD32(ctx->r11, 0X7AE8);
            goto L_800B3BC0;
    }
    // 0x800B3BA8: addiu       $t3, $t3, 0x7AE8
    ctx->r11 = ADD32(ctx->r11, 0X7AE8);
    // 0x800B3BAC: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800B3BB0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800B3BB4: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3BB8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800B3BBC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800B3BC0:
    // 0x800B3BC0: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800B3BC4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800B3BC8: beq         $a0, $zero, L_800B3BE0
    if (ctx->r4 == 0) {
        // 0x800B3BCC: addiu       $t9, $a0, -0x1
        ctx->r25 = ADD32(ctx->r4, -0X1);
            goto L_800B3BE0;
    }
    // 0x800B3BCC: addiu       $t9, $a0, -0x1
    ctx->r25 = ADD32(ctx->r4, -0X1);
    // 0x800B3BD0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B3BD4: lw          $v0, 0x1C4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3BD8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x800B3BDC: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800B3BE0:
    // 0x800B3BE0: addu        $v1, $v0, $t3
    ctx->r3 = ADD32(ctx->r2, ctx->r11);
    // 0x800B3BE4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800B3BE8: beq         $t0, $zero, L_800B3C2C
    if (ctx->r8 == 0) {
        // 0x800B3BEC: addiu       $t4, $t0, -0x1
        ctx->r12 = ADD32(ctx->r8, -0X1);
            goto L_800B3C2C;
    }
    // 0x800B3BEC: addiu       $t4, $t0, -0x1
    ctx->r12 = ADD32(ctx->r8, -0X1);
    // 0x800B3BF0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x800B3BF4: lw          $t5, 0x1C4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C4);
    // 0x800B3BF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3BFC: lwc1        $f10, -0x7638($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7638);
    // 0x800B3C00: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B3C04: addiu       $t7, $t7, 0x7AB8
    ctx->r15 = ADD32(ctx->r15, 0X7AB8);
    // 0x800B3C08: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B3C0C: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x800B3C10: lui         $a1, 0x4300
    ctx->r5 = S32(0X4300 << 16);
    // 0x800B3C14: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B3C18: lui         $a3, 0x4220
    ctx->r7 = S32(0X4220 << 16);
    // 0x800B3C1C: jal         0x8009BC2C
    // 0x800B3C20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x800B3C20: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x800B3C24: b           L_800B3C58
    // 0x800B3C28: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
        goto L_800B3C58;
    // 0x800B3C28: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
L_800B3C2C:
    // 0x800B3C2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3C30: lwc1        $f16, -0x7634($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7634);
    // 0x800B3C34: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B3C38: addiu       $t8, $t8, 0x7AB8
    ctx->r24 = ADD32(ctx->r24, 0X7AB8);
    // 0x800B3C3C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B3C40: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x800B3C44: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B3C48: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800B3C4C: jal         0x8009BC2C
    // 0x800B3C50: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x800B3C50: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x800B3C54: lw          $t9, 0x1C4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C4);
L_800B3C58:
    // 0x800B3C58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3C5C: lwc1        $f18, -0x7630($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7630);
    // 0x800B3C60: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x800B3C64: addiu       $t3, $t3, 0x7AA0
    ctx->r11 = ADD32(ctx->r11, 0X7AA0);
    // 0x800B3C68: lui         $a3, 0x3ECC
    ctx->r7 = S32(0X3ECC << 16);
    // 0x800B3C6C: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800B3C70: addu        $a0, $t2, $t3
    ctx->r4 = ADD32(ctx->r10, ctx->r11);
    // 0x800B3C74: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x800B3C78: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B3C7C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B3C80: jal         0x8009BC2C
    // 0x800B3C84: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x800B3C84: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800B3C88: lw          $t4, 0x1CC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B3C8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B3C90: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800B3C94: bnel        $t4, $at, L_800B3CB0
    if (ctx->r12 != ctx->r1) {
        // 0x800B3C98: lw          $v0, 0x224($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X224);
            goto L_800B3CB0;
    }
    goto skip_3;
    // 0x800B3C98: lw          $v0, 0x224($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X224);
    skip_3:
    // 0x800B3C9C: lw          $v0, 0x1A0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1A0);
    // 0x800B3CA0: beq         $v0, $zero, L_800B3CAC
    if (ctx->r2 == 0) {
        // 0x800B3CA4: addiu       $t5, $v0, -0x1
        ctx->r13 = ADD32(ctx->r2, -0X1);
            goto L_800B3CAC;
    }
    // 0x800B3CA4: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800B3CA8: sw          $t5, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->r13;
L_800B3CAC:
    // 0x800B3CAC: lw          $v0, 0x224($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X224);
L_800B3CB0:
    // 0x800B3CB0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B3CB4: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x800B3CB8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800B3CBC: beq         $v0, $zero, L_800B3CCC
    if (ctx->r2 == 0) {
        // 0x800B3CC0: sw          $t6, 0x200($s0)
        MEM_W(0X200, ctx->r16) = ctx->r14;
            goto L_800B3CCC;
    }
    // 0x800B3CC0: sw          $t6, 0x200($s0)
    MEM_W(0X200, ctx->r16) = ctx->r14;
    // 0x800B3CC4: sw          $t7, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r15;
    // 0x800B3CC8: lw          $v0, 0x224($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X224);
L_800B3CCC:
    // 0x800B3CCC: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800B3CD0: bne         $v0, $at, L_800B3CFC
    if (ctx->r2 != ctx->r1) {
        // 0x800B3CD4: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_800B3CFC;
    }
    // 0x800B3CD4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800B3CD8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B3CDC: sw          $t8, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r24;
    // 0x800B3CE0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B3CE4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800B3CE8: sw          $t9, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r25;
    // 0x800B3CEC: addiu       $v0, $v0, -0x7CAC
    ctx->r2 = ADD32(ctx->r2, -0X7CAC);
    // 0x800B3CF0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B3CF4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800B3CF8: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
L_800B3CFC:
    // 0x800B3CFC: lw          $v1, 0x278($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X278);
    // 0x800B3D00: beq         $v1, $zero, L_800B3D70
    if (ctx->r3 == 0) {
        // 0x800B3D04: andi        $t3, $v1, 0x7
        ctx->r11 = ctx->r3 & 0X7;
            goto L_800B3D70;
    }
    // 0x800B3D04: andi        $t3, $v1, 0x7
    ctx->r11 = ctx->r3 & 0X7;
    // 0x800B3D08: bne         $t3, $zero, L_800B3D68
    if (ctx->r11 != 0) {
        // 0x800B3D0C: andi        $t4, $v1, 0x8
        ctx->r12 = ctx->r3 & 0X8;
            goto L_800B3D68;
    }
    // 0x800B3D0C: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x800B3D10: beq         $t4, $zero, L_800B3D44
    if (ctx->r12 == 0) {
        // 0x800B3D14: lui         $t2, 0x8017
        ctx->r10 = S32(0X8017 << 16);
            goto L_800B3D44;
    }
    // 0x800B3D14: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B3D18: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x800B3D1C: lw          $t5, 0x78A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78A0);
    // 0x800B3D20: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x800B3D24: addiu       $t7, $t7, 0x7DB8
    ctx->r15 = ADD32(ctx->r15, 0X7DB8);
    // 0x800B3D28: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B3D2C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800B3D30: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B3D34: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B3D38: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800B3D3C: b           L_800B3D68
    // 0x800B3D40: lw          $v1, 0x278($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X278);
        goto L_800B3D68;
    // 0x800B3D40: lw          $v1, 0x278($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X278);
L_800B3D44:
    // 0x800B3D44: lw          $t2, 0x78A0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X78A0);
    // 0x800B3D48: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x800B3D4C: addiu       $t4, $t4, 0x7DB8
    ctx->r12 = ADD32(ctx->r12, 0X7DB8);
    // 0x800B3D50: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800B3D54: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3D58: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800B3D5C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800B3D60: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800B3D64: lw          $v1, 0x278($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X278);
L_800B3D68:
    // 0x800B3D68: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800B3D6C: sw          $t7, 0x278($s0)
    MEM_W(0X278, ctx->r16) = ctx->r15;
L_800B3D70:
    // 0x800B3D70: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x800B3D74: blez        $v0, L_800B3FB0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B3D78: slti        $at, $v0, 0x4
        ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
            goto L_800B3FB0;
    }
    // 0x800B3D78: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800B3D7C: bne         $at, $zero, L_800B3D94
    if (ctx->r1 != 0) {
        // 0x800B3D80: lui         $t9, 0x8017
        ctx->r25 = S32(0X8017 << 16);
            goto L_800B3D94;
    }
    // 0x800B3D80: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x800B3D84: lw          $t9, 0x7984($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7984);
    // 0x800B3D88: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800B3D8C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800B3D90: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_800B3D94:
    // 0x800B3D94: lw          $t3, 0x1CC($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1CC);
    // 0x800B3D98: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800B3D9C: sw          $t2, 0x1F4($s0)
    MEM_W(0X1F4, ctx->r16) = ctx->r10;
    // 0x800B3DA0: bnel        $t3, $zero, L_800B3E84
    if (ctx->r11 != 0) {
        // 0x800B3DA4: lw          $t4, 0x1F4($s0)
        ctx->r12 = MEM_W(ctx->r16, 0X1F4);
            goto L_800B3E84;
    }
    goto skip_4;
    // 0x800B3DA4: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
    skip_4:
    // 0x800B3DA8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800B3DAC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800B3DB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B3DB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B3DB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3DBC: lwc1        $f16, -0x762C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X762C);
    // 0x800B3DC0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B3DC4: nop

    // 0x800B3DC8: mul.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800B3DCC: jal         0x80023090
    // 0x800B3DD0: nop

    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B3DD0: nop

    after_3:
    // 0x800B3DD4: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x800B3DD8: lw          $t5, 0x21C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X21C);
    // 0x800B3DDC: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800B3DE0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800B3DE4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B3DE8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B3DEC: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B3DF0: lw          $t7, 0x3164($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3164);
    // 0x800B3DF4: lw          $t8, 0x1C8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C8);
    // 0x800B3DF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B3DFC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800B3E00: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800B3E04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B3E08: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800B3E0C: bne         $t8, $at, L_800B3F00
    if (ctx->r24 != ctx->r1) {
        // 0x800B3E10: swc1        $f10, 0x134($s0)
        MEM_W(0X134, ctx->r16) = ctx->f10.u32l;
            goto L_800B3F00;
    }
    // 0x800B3E10: swc1        $f10, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f10.u32l;
    // 0x800B3E14: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800B3E18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800B3E1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3E20: lwc1        $f4, -0x7628($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7628);
    // 0x800B3E24: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800B3E28: nop

    // 0x800B3E2C: mul.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B3E30: jal         0x80023090
    // 0x800B3E34: nop

    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x800B3E34: nop

    after_4:
    // 0x800B3E38: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x800B3E3C: lw          $t9, 0x21C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X21C);
    // 0x800B3E40: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800B3E44: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800B3E48: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800B3E4C: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800B3E50: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B3E54: lw          $t3, 0x3164($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3164);
    // 0x800B3E58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3E5C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800B3E60: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800B3E64: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800B3E68: lwc1        $f6, -0x7624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7624);
    // 0x800B3E6C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B3E70: nop

    // 0x800B3E74: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B3E78: b           L_800B3F00
    // 0x800B3E7C: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
        goto L_800B3F00;
    // 0x800B3E7C: swc1        $f10, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f10.u32l;
    // 0x800B3E80: lw          $t4, 0x1F4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X1F4);
L_800B3E84:
    // 0x800B3E84: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x800B3E88: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800B3E8C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800B3E90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B3E94: lwc1        $f6, -0x7620($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7620);
    // 0x800B3E98: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B3E9C: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800B3EA0: nop

    // 0x800B3EA4: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B3EA8: jal         0x80023090
    // 0x800B3EAC: nop

    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x800B3EAC: nop

    after_5:
    // 0x800B3EB0: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
    // 0x800B3EB4: lw          $t5, 0x21C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X21C);
    // 0x800B3EB8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
    // 0x800B3EBC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800B3EC0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800B3EC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800B3EC8: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B3ECC: lw          $t7, 0x3164($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3164);
    // 0x800B3ED0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800B3ED4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800B3ED8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800B3EDC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B3EE0: nop

    // 0x800B3EE4: swc1        $f18, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->f18.u32l;
    // 0x800B3EE8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B3EEC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B3EF0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800B3EF4: nop

    // 0x800B3EF8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800B3EFC: swc1        $f8, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f8.u32l;
L_800B3F00:
    // 0x800B3F00: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x800B3F04: lw          $t8, 0x7880($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7880);
    // 0x800B3F08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B3F0C: beq         $t8, $at, L_800B3F9C
    if (ctx->r24 == ctx->r1) {
        // 0x800B3F10: nop
    
            goto L_800B3F9C;
    }
    // 0x800B3F10: nop

    // 0x800B3F14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B3F18: lwc1        $f16, 0xD8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x800B3F1C: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x800B3F20: nop

    // 0x800B3F24: bc1fl       L_800B3F58
    if (!c1cs) {
        // 0x800B3F28: lw          $v1, 0x1A4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1A4);
            goto L_800B3F58;
    }
    goto skip_5;
    // 0x800B3F28: lw          $v1, 0x1A4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1A4);
    skip_5:
    // 0x800B3F2C: lwc1        $f4, 0xDC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x800B3F30: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800B3F34: nop

    // 0x800B3F38: bc1fl       L_800B3F58
    if (!c1cs) {
        // 0x800B3F3C: lw          $v1, 0x1A4($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X1A4);
            goto L_800B3F58;
    }
    goto skip_6;
    // 0x800B3F3C: lw          $v1, 0x1A4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1A4);
    skip_6:
    // 0x800B3F40: lwc1        $f6, 0xE0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x800B3F44: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800B3F48: nop

    // 0x800B3F4C: bc1t        L_800B3F9C
    if (c1cs) {
        // 0x800B3F50: nop
    
            goto L_800B3F9C;
    }
    // 0x800B3F50: nop

    // 0x800B3F54: lw          $v1, 0x1A4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1A4);
L_800B3F58:
    // 0x800B3F58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800B3F5C: addiu       $a0, $s0, 0x110
    ctx->r4 = ADD32(ctx->r16, 0X110);
    // 0x800B3F60: slti        $at, $v1, 0x28
    ctx->r1 = SIGNED(ctx->r3) < 0X28 ? 1 : 0;
    // 0x800B3F64: beq         $at, $zero, L_800B3F78
    if (ctx->r1 == 0) {
        // 0x800B3F68: lui         $a2, 0x3F80
        ctx->r6 = S32(0X3F80 << 16);
            goto L_800B3F78;
    }
    // 0x800B3F68: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800B3F6C: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x800B3F70: bne         $v1, $at, L_800B3F9C
    if (ctx->r3 != ctx->r1) {
        // 0x800B3F74: nop
    
            goto L_800B3F9C;
    }
    // 0x800B3F74: nop

L_800B3F78:
    // 0x800B3F78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B3F7C: sw          $t9, 0x2B4($s0)
    MEM_W(0X2B4, ctx->r16) = ctx->r25;
    // 0x800B3F80: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800B3F84: swc1        $f0, 0xE4($s0)
    MEM_W(0XE4, ctx->r16) = ctx->f0.u32l;
    // 0x800B3F88: swc1        $f0, 0xE8($s0)
    MEM_W(0XE8, ctx->r16) = ctx->f0.u32l;
    // 0x800B3F8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B3F90: jal         0x8009BC2C
    // 0x800B3F94: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B3F94: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x800B3F98: lw          $v0, 0x1F4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1F4);
L_800B3F9C:
    // 0x800B3F9C: bnel        $v0, $zero, L_800B3FB4
    if (ctx->r2 != 0) {
        // 0x800B3FA0: lwc1        $f8, 0x74($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
            goto L_800B3FB4;
    }
    goto skip_7;
    // 0x800B3FA0: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    skip_7:
    // 0x800B3FA4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B3FA8: nop

    // 0x800B3FAC: swc1        $f10, 0x134($s0)
    MEM_W(0X134, ctx->r16) = ctx->f10.u32l;
L_800B3FB0:
    // 0x800B3FB0: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
L_800B3FB4:
    // 0x800B3FB4: lwc1        $f18, 0xD8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x800B3FB8: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B3FBC: lwc1        $f6, 0xDC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x800B3FC0: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B3FC4: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x800B3FC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B3FCC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3FD0: swc1        $f16, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f16.u32l;
    // 0x800B3FD4: addiu       $a0, $s0, 0xE0
    ctx->r4 = ADD32(ctx->r16, 0XE0);
    // 0x800B3FD8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B3FDC: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x800B3FE0: lw          $t2, 0x7880($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7880);
    // 0x800B3FE4: bnel        $t2, $at, L_800B401C
    if (ctx->r10 != ctx->r1) {
        // 0x800B3FE8: lui         $at, 0x3F00
        ctx->r1 = S32(0X3F00 << 16);
            goto L_800B401C;
    }
    goto skip_8;
    // 0x800B3FE8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    skip_8:
    // 0x800B3FEC: lwc1        $f8, 0x7C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800B3FF0: lwc1        $f18, 0xE0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x800B3FF4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B3FF8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B3FFC: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800B4000: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B4004: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B4008: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B400C: swc1        $f16, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f16.u32l;
    // 0x800B4010: jal         0x8009BC2C
    // 0x800B4014: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B4014: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_7:
    // 0x800B4018: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
L_800B401C:
    // 0x800B401C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B4020: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B4024: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B4028: addiu       $a0, $s0, 0xD8
    ctx->r4 = ADD32(ctx->r16, 0XD8);
    // 0x800B402C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B4030: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B4034: jal         0x8009BC2C
    // 0x800B4038: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_8;
    // 0x800B4038: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x800B403C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800B4040: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B4044: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B4048: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B404C: addiu       $a0, $s0, 0xDC
    ctx->r4 = ADD32(ctx->r16, 0XDC);
    // 0x800B4050: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800B4054: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B4058: jal         0x8009BC2C
    // 0x800B405C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800B405C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x800B4060: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B4064: lwc1        $f18, -0x761C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X761C);
    // 0x800B4068: lwc1        $f8, 0x25C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x800B406C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800B4070: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800B4074: swc1        $f16, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f16.u32l;
    // 0x800B4078: lwc1        $f4, 0x25C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X25C);
    // 0x800B407C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800B4080: nop

    // 0x800B4084: bc1fl       L_800B409C
    if (!c1cs) {
        // 0x800B4088: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B409C;
    }
    goto skip_9;
    // 0x800B4088: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_9:
    // 0x800B408C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B4090: nop

    // 0x800B4094: swc1        $f10, 0x25C($s0)
    MEM_W(0X25C, ctx->r16) = ctx->f10.u32l;
    // 0x800B4098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B409C:
    // 0x800B409C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B40A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800B40A4: jr          $ra
    // 0x800B40A8: nop

    return;
    // 0x800B40A8: nop

;}
RECOMP_FUNC void HUD_Number_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800869A0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800869A4: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x800869A8: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800869AC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800869B0: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x800869B4: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x800869B8: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800869BC: mov.s       $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    ctx->f24.fl = ctx->f12.fl;
    // 0x800869C0: mov.s       $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.fl = ctx->f14.fl;
    // 0x800869C4: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800869C8: addiu       $s6, $sp, 0x74
    ctx->r22 = ADD32(ctx->r29, 0X74);
    // 0x800869CC: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800869D0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800869D4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800869D8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800869DC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800869E0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800869E4: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x800869E8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800869EC: addiu       $t6, $t6, 0x1CD4
    ctx->r14 = ADD32(ctx->r14, 0X1CD4);
    // 0x800869F0: addiu       $t9, $t6, 0x24
    ctx->r25 = ADD32(ctx->r14, 0X24);
    // 0x800869F4: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
L_800869F8:
    // 0x800869F8: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x800869FC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80086A00: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80086A04: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x80086A08: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x80086A0C: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x80086A10: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x80086A14: bne         $t6, $t9, L_800869F8
    if (ctx->r14 != ctx->r25) {
        // 0x80086A18: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_800869F8;
    }
    // 0x80086A18: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x80086A1C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x80086A20: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80086A24: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80086A28: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80086A2C: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x80086A30: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x80086A34: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x80086A38: beq         $t1, $zero, L_80086A48
    if (ctx->r9 == 0) {
        // 0x80086A3C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80086A48;
    }
    // 0x80086A3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80086A40: b           L_80086A48
    // 0x80086A44: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_80086A48;
    // 0x80086A44: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80086A48:
    // 0x80086A48: div         $zero, $s1, $v0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r2)));
    // 0x80086A4C: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80086A50: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80086A54: bne         $v0, $zero, L_80086A60
    if (ctx->r2 != 0) {
        // 0x80086A58: nop
    
            goto L_80086A60;
    }
    // 0x80086A58: nop

    // 0x80086A5C: break       7
    do_break(2148035164);
L_80086A60:
    // 0x80086A60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80086A64: bne         $v0, $at, L_80086A78
    if (ctx->r2 != ctx->r1) {
        // 0x80086A68: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80086A78;
    }
    // 0x80086A68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80086A6C: bne         $s1, $at, L_80086A78
    if (ctx->r17 != ctx->r1) {
        // 0x80086A70: nop
    
            goto L_80086A78;
    }
    // 0x80086A70: nop

    // 0x80086A74: break       6
    do_break(2148035188);
L_80086A78:
    // 0x80086A78: mfhi        $s1
    ctx->r17 = hi;
    // 0x80086A7C: nop

    // 0x80086A80: nop

    // 0x80086A84: div         $zero, $v0, $s4
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r20)));
    // 0x80086A88: mflo        $v1
    ctx->r3 = lo;
    // 0x80086A8C: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x80086A90: bne         $s4, $zero, L_80086A9C
    if (ctx->r20 != 0) {
        // 0x80086A94: nop
    
            goto L_80086A9C;
    }
    // 0x80086A94: nop

    // 0x80086A98: break       7
    do_break(2148035224);
L_80086A9C:
    // 0x80086A9C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80086AA0: bne         $s4, $at, L_80086AB4
    if (ctx->r20 != ctx->r1) {
        // 0x80086AA4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80086AB4;
    }
    // 0x80086AA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80086AA8: bne         $v0, $at, L_80086AB4
    if (ctx->r2 != ctx->r1) {
        // 0x80086AAC: nop
    
            goto L_80086AB4;
    }
    // 0x80086AAC: nop

    // 0x80086AB0: break       6
    do_break(2148035248);
L_80086AB4:
    // 0x80086AB4: beql        $s3, $v1, L_80086BA4
    if (ctx->r19 == ctx->r3) {
        // 0x80086AB8: sll         $t4, $s1, 2
        ctx->r12 = S32(ctx->r17 << 2);
            goto L_80086BA4;
    }
    goto skip_0;
    // 0x80086AB8: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    skip_0:
L_80086ABC:
    // 0x80086ABC: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x80086AC0: mflo        $v0
    ctx->r2 = lo;
    // 0x80086AC4: bne         $s0, $zero, L_80086AD0
    if (ctx->r16 != 0) {
        // 0x80086AC8: nop
    
            goto L_80086AD0;
    }
    // 0x80086AC8: nop

    // 0x80086ACC: break       7
    do_break(2148035276);
L_80086AD0:
    // 0x80086AD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80086AD4: bne         $s0, $at, L_80086AE8
    if (ctx->r16 != ctx->r1) {
        // 0x80086AD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80086AE8;
    }
    // 0x80086AD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80086ADC: bne         $s1, $at, L_80086AE8
    if (ctx->r17 != ctx->r1) {
        // 0x80086AE0: nop
    
            goto L_80086AE8;
    }
    // 0x80086AE0: nop

    // 0x80086AE4: break       6
    do_break(2148035300);
L_80086AE8:
    // 0x80086AE8: bnel        $v0, $zero, L_80086AFC
    if (ctx->r2 != 0) {
        // 0x80086AEC: sll         $t2, $v0, 2
        ctx->r10 = S32(ctx->r2 << 2);
            goto L_80086AFC;
    }
    goto skip_1;
    // 0x80086AEC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    skip_1:
    // 0x80086AF0: bne         $s2, $s3, L_80086B6C
    if (ctx->r18 != ctx->r19) {
        // 0x80086AF4: nop
    
            goto L_80086B6C;
    }
    // 0x80086AF4: nop

    // 0x80086AF8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
L_80086AFC:
    // 0x80086AFC: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80086B00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80086B04: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80086B08: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80086B0C: mul.s       $f20, $f4, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x80086B10: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80086B14: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80086B18: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x80086B1C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80086B20: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80086B24: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80086B28: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80086B2C: jal         0x8009D994
    // 0x80086B30: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_0;
    // 0x80086B30: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    after_0:
    // 0x80086B34: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x80086B38: add.s       $f24, $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x80086B3C: bne         $s0, $zero, L_80086B48
    if (ctx->r16 != 0) {
        // 0x80086B40: nop
    
            goto L_80086B48;
    }
    // 0x80086B40: nop

    // 0x80086B44: break       7
    do_break(2148035396);
L_80086B48:
    // 0x80086B48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80086B4C: bne         $s0, $at, L_80086B60
    if (ctx->r16 != ctx->r1) {
        // 0x80086B50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80086B60;
    }
    // 0x80086B50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80086B54: bne         $s1, $at, L_80086B60
    if (ctx->r17 != ctx->r1) {
        // 0x80086B58: nop
    
            goto L_80086B60;
    }
    // 0x80086B58: nop

    // 0x80086B5C: break       6
    do_break(2148035420);
L_80086B60:
    // 0x80086B60: mfhi        $s1
    ctx->r17 = hi;
    // 0x80086B64: nop

    // 0x80086B68: nop

L_80086B6C:
    // 0x80086B6C: div         $zero, $s0, $s4
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r20)));
    // 0x80086B70: bne         $s4, $zero, L_80086B7C
    if (ctx->r20 != 0) {
        // 0x80086B74: nop
    
            goto L_80086B7C;
    }
    // 0x80086B74: nop

    // 0x80086B78: break       7
    do_break(2148035448);
L_80086B7C:
    // 0x80086B7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80086B80: bne         $s4, $at, L_80086B94
    if (ctx->r20 != ctx->r1) {
        // 0x80086B84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80086B94;
    }
    // 0x80086B84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80086B88: bne         $s0, $at, L_80086B94
    if (ctx->r16 != ctx->r1) {
        // 0x80086B8C: nop
    
            goto L_80086B94;
    }
    // 0x80086B8C: nop

    // 0x80086B90: break       6
    do_break(2148035472);
L_80086B94:
    // 0x80086B94: mflo        $s0
    ctx->r16 = lo;
    // 0x80086B98: bne         $s0, $s3, L_80086ABC
    if (ctx->r16 != ctx->r19) {
        // 0x80086B9C: nop
    
            goto L_80086ABC;
    }
    // 0x80086B9C: nop

    // 0x80086BA0: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
L_80086BA4:
    // 0x80086BA4: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x80086BA8: lw          $a1, 0x0($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X0);
    // 0x80086BAC: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80086BB0: addiu       $a0, $s5, 0x7E64
    ctx->r4 = ADD32(ctx->r21, 0X7E64);
    // 0x80086BB4: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80086BB8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80086BBC: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x80086BC0: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80086BC4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80086BC8: jal         0x8009D994
    // 0x80086BCC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x80086BCC: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    after_1:
    // 0x80086BD0: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80086BD4: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80086BD8: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80086BDC: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80086BE0: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x80086BE4: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80086BE8: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80086BEC: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80086BF0: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80086BF4: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80086BF8: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80086BFC: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80086C00: jr          $ra
    // 0x80086C04: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80086C04: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void HUD_SinglePlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F96C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F974: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8008F978: lw          $t6, 0x7854($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7854);
    // 0x8008F97C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8008F980: beq         $t6, $at, L_8008F990
    if (ctx->r14 == ctx->r1) {
        // 0x8008F984: nop
    
            goto L_8008F990;
    }
    // 0x8008F984: nop

    // 0x8008F988: jal         0x8008E5E8
    // 0x8008F98C: nop

    HUD_Radar(rdram, ctx);
        goto after_0;
    // 0x8008F98C: nop

    after_0:
L_8008F990:
    // 0x8008F990: jal         0x800B9358
    // 0x8008F994: nop

    RCP_SetupDL_36(rdram, ctx);
        goto after_1;
    // 0x8008F994: nop

    after_1:
    // 0x8008F998: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8008F99C: lw          $t7, 0x7880($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7880);
    // 0x8008F9A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008F9A4: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8008F9A8: beq         $t7, $at, L_8008F9EC
    if (ctx->r15 == ctx->r1) {
        // 0x8008F9AC: nop
    
            goto L_8008F9EC;
    }
    // 0x8008F9AC: nop

    // 0x8008F9B0: lw          $t8, 0x1708($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1708);
    // 0x8008F9B4: lui         $at, 0x4376
    ctx->r1 = S32(0X4376 << 16);
    // 0x8008F9B8: beq         $t8, $zero, L_8008F9EC
    if (ctx->r24 == 0) {
        // 0x8008F9BC: nop
    
            goto L_8008F9EC;
    }
    // 0x8008F9BC: nop

    // 0x8008F9C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008F9C4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8008F9C8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008F9CC: jal         0x8008D4F0
    // 0x8008F9D0: nop

    HUD_BoostGauge_Draw(rdram, ctx);
        goto after_2;
    // 0x8008F9D0: nop

    after_2:
    // 0x8008F9D4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8008F9D8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008F9DC: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8008F9E0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008F9E4: jal         0x8008EA14
    // 0x8008F9E8: nop

    HUD_BombCounter_Draw(rdram, ctx);
        goto after_3;
    // 0x8008F9E8: nop

    after_3:
L_8008F9EC:
    // 0x8008F9EC: jal         0x8008B2A4
    // 0x8008F9F0: nop

    HUD_IncomingMsg(rdram, ctx);
        goto after_4;
    // 0x8008F9F0: nop

    after_4:
    // 0x8008F9F4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8008F9F8: lw          $t9, 0x1708($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1708);
    // 0x8008F9FC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x8008FA00: beq         $t9, $zero, L_8008FA58
    if (ctx->r25 == 0) {
        // 0x8008FA04: nop
    
            goto L_8008FA58;
    }
    // 0x8008FA04: nop

    // 0x8008FA08: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008FA0C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8008FA10: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008FA14: jal         0x8008E9EC
    // 0x8008FA18: nop

    HUD_Shield_GoldRings_Score(rdram, ctx);
        goto after_5;
    // 0x8008FA18: nop

    after_5:
    // 0x8008FA1C: lui         $t0, 0x8018
    ctx->r8 = S32(0X8018 << 16);
    // 0x8008FA20: lw          $t0, -0x7DCC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7DCC);
    // 0x8008FA24: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008FA28: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x8008FA2C: beq         $t0, $at, L_8008FA58
    if (ctx->r8 == ctx->r1) {
        // 0x8008FA30: lui         $a2, 0x8016
        ctx->r6 = S32(0X8016 << 16);
            goto L_8008FA58;
    }
    // 0x8008FA30: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x8008FA34: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x8008FA38: lui         $at, 0x4378
    ctx->r1 = S32(0X4378 << 16);
    // 0x8008FA3C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008FA40: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8008FA44: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x8008FA48: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x8008FA4C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8008FA50: jal         0x80087530
    // 0x8008FA54: lh          $a2, 0x1AA0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1AA0);
    HUD_LivesCount2_Draw(rdram, ctx);
        goto after_6;
    // 0x8008FA54: lh          $a2, 0x1AA0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1AA0);
    after_6:
L_8008FA58:
    // 0x8008FA58: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x8008FA5C: lw          $t3, -0x7DCC($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7DCC);
    // 0x8008FA60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8008FA64: bnel        $t3, $at, L_8008FA78
    if (ctx->r11 != ctx->r1) {
        // 0x8008FA68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008FA78;
    }
    goto skip_0;
    // 0x8008FA68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8008FA6C: jal         0x801988E0
    // 0x8008FA70: nop

    Training_RingPassCount_Draw(rdram, ctx);
        goto after_7;
    // 0x8008FA70: nop

    after_7:
    // 0x8008FA74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008FA78:
    // 0x8008FA78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008FA7C: jr          $ra
    // 0x8008FA80: nop

    return;
    // 0x8008FA80: nop

;}
RECOMP_FUNC void Audio_KillSfxBySource(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A500: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001A504: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001A508: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001A50C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001A510: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001A514: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001A518:
    // 0x8001A518: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x8001A51C: jal         0x8001A38C
    // 0x8001A520: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    Audio_StopSfxByBankAndSource(rdram, ctx);
        goto after_0;
    // 0x8001A520: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8001A524: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001A528: andi        $t6, $s0, 0xFF
    ctx->r14 = ctx->r16 & 0XFF;
    // 0x8001A52C: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8001A530: bne         $at, $zero, L_8001A518
    if (ctx->r1 != 0) {
        // 0x8001A534: or          $s0, $t6, $zero
        ctx->r16 = ctx->r14 | 0;
            goto L_8001A518;
    }
    // 0x8001A534: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8001A538: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8001A53C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8001A540: jal         0x80019290
    // 0x8001A544: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    Audio_RemoveMatchingSfxRequests(rdram, ctx);
        goto after_1;
    // 0x8001A544: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8001A548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001A54C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001A550: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001A554: jr          $ra
    // 0x8001A558: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001A558: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_tank_800438E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800438E0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800438E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800438E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800438EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800438F0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800438F4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800438F8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800438FC: jal         0x80061474
    // 0x80043900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80043900: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80043904: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80043908: addiu       $t7, $zero, 0x165
    ctx->r15 = ADD32(0, 0X165);
    // 0x8004390C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x80043910: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80043914: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80043918: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x8004391C: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80043920: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80043924: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80043928: jal         0x80004EB0
    // 0x8004392C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8004392C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    after_1:
    // 0x80043930: jal         0x80004EB0
    // 0x80043934: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80043934: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80043938: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8004393C: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80043940: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80043944: jal         0x80004EB0
    // 0x80043948: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80043948: swc1        $f18, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f18.u32l;
    after_3:
    // 0x8004394C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80043950: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x80043954: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80043958: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8004395C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80043960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043964: lwc1        $f4, 0xC8($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0XC8);
    // 0x80043968: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8004396C: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80043970: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80043974: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80043978: jal         0x80004EB0
    // 0x8004397C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8004397C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    after_4:
    // 0x80043980: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80043984: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x80043988: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8004398C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043990: lwc1        $f4, 0xC8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC8);
    // 0x80043994: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80043998: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004399C: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800439A0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800439A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800439A8: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800439AC: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800439B0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800439B4: jal         0x80004EB0
    // 0x800439B8: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x800439B8: swc1        $f6, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x800439BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800439C0: lwc1        $f8, 0x5618($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5618);
    // 0x800439C4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800439C8: lwc1        $f10, 0x561C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X561C);
    // 0x800439CC: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800439D0: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800439D4: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800439D8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800439DC: jal         0x80004EB0
    // 0x800439E0: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x800439E0: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x800439E4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800439E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800439EC: nop

    // 0x800439F0: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800439F4: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800439F8: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800439FC: nop

    // 0x80043A00: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80043A04: jal         0x80004EB0
    // 0x80043A08: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x80043A08: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    after_7:
    // 0x80043A0C: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80043A10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80043A14: nop

    // 0x80043A18: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80043A1C: jal         0x80004EB0
    // 0x80043A20: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x80043A20: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    after_8:
    // 0x80043A24: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80043A28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043A2C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80043A30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80043A34: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80043A38: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80043A3C: jal         0x80004EB0
    // 0x80043A40: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x80043A40: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
    after_9:
    // 0x80043A44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80043A48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80043A4C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80043A50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80043A54: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80043A58: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80043A5C: jal         0x80004EB0
    // 0x80043A60: swc1        $f8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x80043A60: swc1        $f8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->f8.u32l;
    after_10:
    // 0x80043A64: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80043A68: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80043A6C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80043A70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80043A74: sub.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80043A78: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80043A7C: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80043A80: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80043A84: jal         0x800612B8
    // 0x80043A88: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_11;
    // 0x80043A88: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    after_11:
    // 0x80043A8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80043A90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80043A94: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80043A98: jr          $ra
    // 0x80043A9C: nop

    return;
    // 0x80043A9C: nop

;}
RECOMP_FUNC void Game_InitStandbyDL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1E68: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A1E6C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800A1E70: addiu       $t8, $t8, -0x4560
    ctx->r24 = ADD32(ctx->r24, -0X4560);
    // 0x800A1E74: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800A1E78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A1E7C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800A1E80: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800A1E84: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800A1E88: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A1E8C: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x800A1E90: ori         $t1, $t1, 0xB40
    ctx->r9 = ctx->r9 | 0XB40;
    // 0x800A1E94: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A1E98: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A1E9C: lui         $t0, 0xED00
    ctx->r8 = S32(0XED00 << 16);
    // 0x800A1EA0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800A1EA4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800A1EA8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A1EAC: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x800A1EB0: ori         $t4, $t4, 0x1
    ctx->r12 = ctx->r12 | 0X1;
    // 0x800A1EB4: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A1EB8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800A1EBC: lui         $t3, 0xF700
    ctx->r11 = S32(0XF700 << 16);
    // 0x800A1EC0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A1EC4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800A1EC8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A1ECC: lui         $t6, 0xFF10
    ctx->r14 = S32(0XFF10 << 16);
    // 0x800A1ED0: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x800A1ED4: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800A1ED8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A1EDC: addiu       $t7, $t7, -0x800
    ctx->r15 = ADD32(ctx->r15, -0X800);
    // 0x800A1EE0: ori         $t6, $t6, 0x13F
    ctx->r14 = ctx->r14 | 0X13F;
    // 0x800A1EE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800A1EE8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800A1EEC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A1EF0: lui         $t9, 0xF64F
    ctx->r25 = S32(0XF64F << 16);
    // 0x800A1EF4: ori         $t9, $t9, 0xCB3C
    ctx->r25 = ctx->r25 | 0XCB3C;
    // 0x800A1EF8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800A1EFC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A1F00: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A1F04: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800A1F08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A1F0C: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x800A1F10: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x800A1F14: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800A1F18: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A1F1C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800A1F20: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A1F24: lui         $t3, 0xBA00
    ctx->r11 = S32(0XBA00 << 16);
    // 0x800A1F28: ori         $t3, $t3, 0x602
    ctx->r11 = ctx->r11 | 0X602;
    // 0x800A1F2C: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A1F30: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800A1F34: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800A1F38: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A1F3C: jr          $ra
    // 0x800A1F40: nop

    return;
    // 0x800A1F40: nop

;}
RECOMP_FUNC void Object_Load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062180: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80062184: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80062188: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8006218C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80062190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062194: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80062198: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8006219C: lh          $t6, 0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X6);
    // 0x800621A0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x800621A4: lw          $v0, -0x7D80($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7D80);
    // 0x800621A8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800621AC: lwc1        $f8, 0xAC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x800621B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800621B4: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800621B8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800621BC: nop

    // 0x800621C0: bc1fl       L_8006255C
    if (!c1cs) {
        // 0x800621C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006255C;
    }
    goto skip_0;
    // 0x800621C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800621C8: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800621CC: nop

    // 0x800621D0: bc1fl       L_8006255C
    if (!c1cs) {
        // 0x800621D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006255C;
    }
    goto skip_1;
    // 0x800621D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800621D8: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800621DC: lwc1        $f18, 0xB0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x800621E0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800621E4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800621E8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800621EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800621F0: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800621F4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800621F8: nop

    // 0x800621FC: bc1fl       L_8006255C
    if (!c1cs) {
        // 0x80062200: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006255C;
    }
    goto skip_2;
    // 0x80062200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80062204: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80062208: nop

    // 0x8006220C: bc1fl       L_8006255C
    if (!c1cs) {
        // 0x80062210: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006255C;
    }
    goto skip_3;
    // 0x80062210: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80062214: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
    // 0x80062218: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8006221C: addiu       $a0, $a0, 0x1B00
    ctx->r4 = ADD32(ctx->r4, 0X1B00);
    // 0x80062220: slti        $at, $v1, 0xA1
    ctx->r1 = SIGNED(ctx->r3) < 0XA1 ? 1 : 0;
    // 0x80062224: beq         $at, $zero, L_8006225C
    if (ctx->r1 == 0) {
        // 0x80062228: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_8006225C;
    }
    // 0x80062228: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8006222C: addiu       $v0, $v0, 0x3400
    ctx->r2 = ADD32(ctx->r2, 0X3400);
    // 0x80062230: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
L_80062234:
    // 0x80062234: bnel        $t8, $zero, L_80062254
    if (ctx->r24 != 0) {
        // 0x80062238: addiu       $a0, $a0, 0x80
        ctx->r4 = ADD32(ctx->r4, 0X80);
            goto L_80062254;
    }
    goto skip_4;
    // 0x80062238: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    skip_4:
    // 0x8006223C: jal         0x800614B4
    // 0x80062240: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Scenery_Load(rdram, ctx);
        goto after_0;
    // 0x80062240: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80062244: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80062248: b           L_8006225C
    // 0x8006224C: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_8006225C;
    // 0x8006224C: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
    // 0x80062250: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
L_80062254:
    // 0x80062254: bnel        $a0, $v0, L_80062234
    if (ctx->r4 != ctx->r2) {
        // 0x80062258: lbu         $t8, 0x0($a0)
        ctx->r24 = MEM_BU(ctx->r4, 0X0);
            goto L_80062234;
    }
    goto skip_5;
    // 0x80062258: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    skip_5:
L_8006225C:
    // 0x8006225C: slti        $at, $v1, 0xA1
    ctx->r1 = SIGNED(ctx->r3) < 0XA1 ? 1 : 0;
    // 0x80062260: bne         $at, $zero, L_800622A8
    if (ctx->r1 != 0) {
        // 0x80062264: slti        $at, $v1, 0xB0
        ctx->r1 = SIGNED(ctx->r3) < 0XB0 ? 1 : 0;
            goto L_800622A8;
    }
    // 0x80062264: slti        $at, $v1, 0xB0
    ctx->r1 = SIGNED(ctx->r3) < 0XB0 ? 1 : 0;
    // 0x80062268: beq         $at, $zero, L_800622A8
    if (ctx->r1 == 0) {
        // 0x8006226C: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_800622A8;
    }
    // 0x8006226C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80062270: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80062274: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x80062278: addiu       $a0, $a0, 0x3400
    ctx->r4 = ADD32(ctx->r4, 0X3400);
    // 0x8006227C: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
L_80062280:
    // 0x80062280: bnel        $t9, $zero, L_800622A0
    if (ctx->r25 != 0) {
        // 0x80062284: addiu       $a0, $a0, 0x4C
        ctx->r4 = ADD32(ctx->r4, 0X4C);
            goto L_800622A0;
    }
    goto skip_6;
    // 0x80062284: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    skip_6:
    // 0x80062288: jal         0x800615A0
    // 0x8006228C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Sprite_Load(rdram, ctx);
        goto after_1;
    // 0x8006228C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80062290: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80062294: b           L_800622A8
    // 0x80062298: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_800622A8;
    // 0x80062298: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
    // 0x8006229C: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
L_800622A0:
    // 0x800622A0: bnel        $a0, $v0, L_80062280
    if (ctx->r4 != ctx->r2) {
        // 0x800622A4: lbu         $t9, 0x0($a0)
        ctx->r25 = MEM_BU(ctx->r4, 0X0);
            goto L_80062280;
    }
    goto skip_7;
    // 0x800622A4: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    skip_7:
L_800622A8:
    // 0x800622A8: slti        $at, $v1, 0xB0
    ctx->r1 = SIGNED(ctx->r3) < 0XB0 ? 1 : 0;
    // 0x800622AC: bne         $at, $zero, L_80062398
    if (ctx->r1 != 0) {
        // 0x800622B0: slti        $at, $v1, 0x124
        ctx->r1 = SIGNED(ctx->r3) < 0X124 ? 1 : 0;
            goto L_80062398;
    }
    // 0x800622B0: slti        $at, $v1, 0x124
    ctx->r1 = SIGNED(ctx->r3) < 0X124 ? 1 : 0;
    // 0x800622B4: beq         $at, $zero, L_80062398
    if (ctx->r1 == 0) {
        // 0x800622B8: addiu       $at, $zero, 0x10B
        ctx->r1 = ADD32(0, 0X10B);
            goto L_80062398;
    }
    // 0x800622B8: addiu       $at, $zero, 0x10B
    ctx->r1 = ADD32(0, 0X10B);
    // 0x800622BC: beq         $v1, $at, L_800622CC
    if (ctx->r3 == ctx->r1) {
        // 0x800622C0: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_800622CC;
    }
    // 0x800622C0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800622C4: addiu       $at, $zero, 0xFE
    ctx->r1 = ADD32(0, 0XFE);
    // 0x800622C8: bne         $v1, $at, L_80062310
    if (ctx->r3 != ctx->r1) {
        // 0x800622CC: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_80062310;
    }
L_800622CC:
    // 0x800622CC: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x800622D0: addiu       $v0, $v0, 0x3FE0
    ctx->r2 = ADD32(ctx->r2, 0X3FE0);
    // 0x800622D4: addiu       $a0, $a0, -0x11E4
    ctx->r4 = ADD32(ctx->r4, -0X11E4);
    // 0x800622D8: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
L_800622DC:
    // 0x800622DC: bnel        $t0, $zero, L_800622FC
    if (ctx->r8 != 0) {
        // 0x800622E0: addiu       $a0, $a0, -0x2F4
        ctx->r4 = ADD32(ctx->r4, -0X2F4);
            goto L_800622FC;
    }
    goto skip_8;
    // 0x800622E0: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
    skip_8:
    // 0x800622E4: jal         0x8006168C
    // 0x800622E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Actor_Load(rdram, ctx);
        goto after_2;
    // 0x800622E8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x800622EC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800622F0: b           L_80062398
    // 0x800622F4: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062398;
    // 0x800622F4: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
    // 0x800622F8: addiu       $a0, $a0, -0x2F4
    ctx->r4 = ADD32(ctx->r4, -0X2F4);
L_800622FC:
    // 0x800622FC: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x80062300: beql        $at, $zero, L_800622DC
    if (ctx->r1 == 0) {
        // 0x80062304: lbu         $t0, 0x0($a0)
        ctx->r8 = MEM_BU(ctx->r4, 0X0);
            goto L_800622DC;
    }
    goto skip_9;
    // 0x80062304: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    skip_9:
    // 0x80062308: b           L_8006239C
    // 0x8006230C: slti        $at, $v1, 0x124
    ctx->r1 = SIGNED(ctx->r3) < 0X124 ? 1 : 0;
        goto L_8006239C;
    // 0x8006230C: slti        $at, $v1, 0x124
    ctx->r1 = SIGNED(ctx->r3) < 0X124 ? 1 : 0;
L_80062310:
    // 0x80062310: addiu       $at, $zero, 0xC6
    ctx->r1 = ADD32(0, 0XC6);
    // 0x80062314: bne         $v1, $at, L_80062360
    if (ctx->r3 != ctx->r1) {
        // 0x80062318: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_80062360;
    }
    // 0x80062318: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x8006231C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80062320: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x80062324: addiu       $v0, $v0, 0x48BC
    ctx->r2 = ADD32(ctx->r2, 0X48BC);
    // 0x80062328: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8006232C: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
L_80062330:
    // 0x80062330: bnel        $t1, $zero, L_80062350
    if (ctx->r9 != 0) {
        // 0x80062334: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_80062350;
    }
    goto skip_10;
    // 0x80062334: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_10:
    // 0x80062338: jal         0x8006168C
    // 0x8006233C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Actor_Load(rdram, ctx);
        goto after_3;
    // 0x8006233C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_3:
    // 0x80062340: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80062344: b           L_80062398
    // 0x80062348: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062398;
    // 0x80062348: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
    // 0x8006234C: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_80062350:
    // 0x80062350: bnel        $a0, $v0, L_80062330
    if (ctx->r4 != ctx->r2) {
        // 0x80062354: lbu         $t1, 0x0($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0X0);
            goto L_80062330;
    }
    goto skip_11;
    // 0x80062354: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    skip_11:
    // 0x80062358: b           L_8006239C
    // 0x8006235C: slti        $at, $v1, 0x124
    ctx->r1 = SIGNED(ctx->r3) < 0X124 ? 1 : 0;
        goto L_8006239C;
    // 0x8006235C: slti        $at, $v1, 0x124
    ctx->r1 = SIGNED(ctx->r3) < 0X124 ? 1 : 0;
L_80062360:
    // 0x80062360: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80062364: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80062368: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x8006236C: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
L_80062370:
    // 0x80062370: bnel        $t2, $zero, L_80062390
    if (ctx->r10 != 0) {
        // 0x80062374: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_80062390;
    }
    goto skip_12;
    // 0x80062374: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
    skip_12:
    // 0x80062378: jal         0x8006168C
    // 0x8006237C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Actor_Load(rdram, ctx);
        goto after_4;
    // 0x8006237C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x80062380: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80062384: b           L_80062398
    // 0x80062388: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062398;
    // 0x80062388: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
    // 0x8006238C: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_80062390:
    // 0x80062390: bnel        $a0, $v0, L_80062370
    if (ctx->r4 != ctx->r2) {
        // 0x80062394: lbu         $t2, 0x0($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X0);
            goto L_80062370;
    }
    goto skip_13;
    // 0x80062394: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    skip_13:
L_80062398:
    // 0x80062398: slti        $at, $v1, 0x124
    ctx->r1 = SIGNED(ctx->r3) < 0X124 ? 1 : 0;
L_8006239C:
    // 0x8006239C: bne         $at, $zero, L_800623E4
    if (ctx->r1 != 0) {
        // 0x800623A0: slti        $at, $v1, 0x142
        ctx->r1 = SIGNED(ctx->r3) < 0X142 ? 1 : 0;
            goto L_800623E4;
    }
    // 0x800623A0: slti        $at, $v1, 0x142
    ctx->r1 = SIGNED(ctx->r3) < 0X142 ? 1 : 0;
    // 0x800623A4: beq         $at, $zero, L_800623E4
    if (ctx->r1 == 0) {
        // 0x800623A8: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_800623E4;
    }
    // 0x800623A8: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800623AC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800623B0: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x800623B4: addiu       $a0, $a0, -0xEF0
    ctx->r4 = ADD32(ctx->r4, -0XEF0);
    // 0x800623B8: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
L_800623BC:
    // 0x800623BC: bnel        $t3, $zero, L_800623DC
    if (ctx->r11 != 0) {
        // 0x800623C0: addiu       $a0, $a0, 0x408
        ctx->r4 = ADD32(ctx->r4, 0X408);
            goto L_800623DC;
    }
    goto skip_14;
    // 0x800623C0: addiu       $a0, $a0, 0x408
    ctx->r4 = ADD32(ctx->r4, 0X408);
    skip_14:
    // 0x800623C4: jal         0x80061778
    // 0x800623C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Boss_Load(rdram, ctx);
        goto after_5;
    // 0x800623C8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_5:
    // 0x800623CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800623D0: b           L_800623E4
    // 0x800623D4: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_800623E4;
    // 0x800623D4: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
    // 0x800623D8: addiu       $a0, $a0, 0x408
    ctx->r4 = ADD32(ctx->r4, 0X408);
L_800623DC:
    // 0x800623DC: bnel        $a0, $v0, L_800623BC
    if (ctx->r4 != ctx->r2) {
        // 0x800623E0: lbu         $t3, 0x0($a0)
        ctx->r11 = MEM_BU(ctx->r4, 0X0);
            goto L_800623BC;
    }
    goto skip_15;
    // 0x800623E0: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    skip_15:
L_800623E4:
    // 0x800623E4: slti        $at, $v1, 0x142
    ctx->r1 = SIGNED(ctx->r3) < 0X142 ? 1 : 0;
    // 0x800623E8: bne         $at, $zero, L_80062430
    if (ctx->r1 != 0) {
        // 0x800623EC: slti        $at, $v1, 0x153
        ctx->r1 = SIGNED(ctx->r3) < 0X153 ? 1 : 0;
            goto L_80062430;
    }
    // 0x800623EC: slti        $at, $v1, 0x153
    ctx->r1 = SIGNED(ctx->r3) < 0X153 ? 1 : 0;
    // 0x800623F0: beq         $at, $zero, L_80062430
    if (ctx->r1 == 0) {
        // 0x800623F4: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_80062430;
    }
    // 0x800623F4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800623F8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x800623FC: addiu       $v0, $v0, 0x4050
    ctx->r2 = ADD32(ctx->r2, 0X4050);
    // 0x80062400: addiu       $a0, $a0, 0x37E0
    ctx->r4 = ADD32(ctx->r4, 0X37E0);
    // 0x80062404: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
L_80062408:
    // 0x80062408: bnel        $t4, $zero, L_80062428
    if (ctx->r12 != 0) {
        // 0x8006240C: addiu       $a0, $a0, 0x6C
        ctx->r4 = ADD32(ctx->r4, 0X6C);
            goto L_80062428;
    }
    goto skip_16;
    // 0x8006240C: addiu       $a0, $a0, 0x6C
    ctx->r4 = ADD32(ctx->r4, 0X6C);
    skip_16:
    // 0x80062410: jal         0x80061864
    // 0x80062414: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    Item_Load(rdram, ctx);
        goto after_6;
    // 0x80062414: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_6:
    // 0x80062418: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006241C: b           L_80062430
    // 0x80062420: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062430;
    // 0x80062420: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
    // 0x80062424: addiu       $a0, $a0, 0x6C
    ctx->r4 = ADD32(ctx->r4, 0X6C);
L_80062428:
    // 0x80062428: bnel        $a0, $v0, L_80062408
    if (ctx->r4 != ctx->r2) {
        // 0x8006242C: lbu         $t4, 0x0($a0)
        ctx->r12 = MEM_BU(ctx->r4, 0X0);
            goto L_80062408;
    }
    goto skip_17;
    // 0x8006242C: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    skip_17:
L_80062430:
    // 0x80062430: slti        $at, $v1, 0x153
    ctx->r1 = SIGNED(ctx->r3) < 0X153 ? 1 : 0;
    // 0x80062434: bne         $at, $zero, L_80062518
    if (ctx->r1 != 0) {
        // 0x80062438: slti        $at, $v1, 0x197
        ctx->r1 = SIGNED(ctx->r3) < 0X197 ? 1 : 0;
            goto L_80062518;
    }
    // 0x80062438: slti        $at, $v1, 0x197
    ctx->r1 = SIGNED(ctx->r3) < 0X197 ? 1 : 0;
    // 0x8006243C: beq         $at, $zero, L_80062518
    if (ctx->r1 == 0) {
        // 0x80062440: addiu       $t5, $v1, -0x190
        ctx->r13 = ADD32(ctx->r3, -0X190);
            goto L_80062518;
    }
    // 0x80062440: addiu       $t5, $v1, -0x190
    ctx->r13 = ADD32(ctx->r3, -0X190);
    // 0x80062444: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80062448: beq         $at, $zero, L_80062518
    if (ctx->r1 == 0) {
        // 0x8006244C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80062518;
    }
    // 0x8006244C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80062450: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80062454: addu        $at, $at, $t5
    gpr jr_addend_8006245C = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80062458: lw          $t5, 0x6458($at)
    ctx->r13 = ADD32(ctx->r1, 0X6458);
    // 0x8006245C: jr          $t5
    // 0x80062460: nop

    switch (jr_addend_8006245C >> 2) {
        case 0: goto L_800624E0; break;
        case 1: goto L_800624FC; break;
        case 2: goto L_8006249C; break;
        case 3: goto L_80062464; break;
        case 4: goto L_80062478; break;
        case 5: goto L_80062488; break;
        default: switch_error(__func__, 0x8006245C, 0x800D6458);
    }
    // 0x80062460: nop

L_80062464:
    // 0x80062464: addiu       $t6, $zero, 0x63
    ctx->r14 = ADD32(0, 0X63);
    // 0x80062468: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8006246C: sb          $t6, -0x5E18($at)
    MEM_B(-0X5E18, ctx->r1) = ctx->r14;
    // 0x80062470: b           L_80062518
    // 0x80062474: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062518;
    // 0x80062474: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
L_80062478:
    // 0x80062478: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8006247C: sb          $zero, -0x5E18($at)
    MEM_B(-0X5E18, ctx->r1) = 0;
    // 0x80062480: b           L_80062518
    // 0x80062484: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062518;
    // 0x80062484: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
L_80062488:
    // 0x80062488: addiu       $t7, $zero, 0x62
    ctx->r15 = ADD32(0, 0X62);
    // 0x8006248C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80062490: sb          $t7, -0x5E18($at)
    MEM_B(-0X5E18, ctx->r1) = ctx->r15;
    // 0x80062494: b           L_80062518
    // 0x80062498: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062518;
    // 0x80062498: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
L_8006249C:
    // 0x8006249C: lh          $t8, 0xE($a1)
    ctx->r24 = MEM_H(ctx->r5, 0XE);
    // 0x800624A0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800624A4: lwc1        $f16, 0x6470($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6470);
    // 0x800624A8: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800624AC: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800624B0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800624B4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800624B8: swc1        $f18, 0x7F78($at)
    MEM_W(0X7F78, ctx->r1) = ctx->f18.u32l;
    // 0x800624BC: lh          $t9, 0xA($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XA);
    // 0x800624C0: lui         $at, 0x801A
    ctx->r1 = S32(0X801A << 16);
    // 0x800624C4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800624C8: nop

    // 0x800624CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800624D0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800624D4: swc1        $f8, 0x7F60($at)
    MEM_W(0X7F60, ctx->r1) = ctx->f8.u32l;
    // 0x800624D8: b           L_80062518
    // 0x800624DC: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062518;
    // 0x800624DC: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
L_800624E0:
    // 0x800624E0: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x800624E4: addiu       $a0, $a0, -0x7D48
    ctx->r4 = ADD32(ctx->r4, -0X7D48);
    // 0x800624E8: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800624EC: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800624F0: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800624F4: b           L_80062518
    // 0x800624F8: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
        goto L_80062518;
    // 0x800624F8: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
L_800624FC:
    // 0x800624FC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80062500: addiu       $a0, $a0, -0x7D48
    ctx->r4 = ADD32(ctx->r4, -0X7D48);
    // 0x80062504: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80062508: blez        $v0, L_80062518
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8006250C: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80062518;
    }
    // 0x8006250C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80062510: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80062514: lh          $v1, 0x10($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X10);
L_80062518:
    // 0x80062518: slti        $at, $v1, 0x197
    ctx->r1 = SIGNED(ctx->r3) < 0X197 ? 1 : 0;
    // 0x8006251C: bne         $at, $zero, L_80062558
    if (ctx->r1 != 0) {
        // 0x80062520: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80062558;
    }
    // 0x80062520: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80062524: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80062528: addiu       $a0, $a0, 0x3FE0
    ctx->r4 = ADD32(ctx->r4, 0X3FE0);
    // 0x8006252C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
L_80062530:
    // 0x80062530: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x80062534: bnel        $t3, $zero, L_80062550
    if (ctx->r11 != 0) {
        // 0x80062538: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80062550;
    }
    goto skip_18;
    // 0x80062538: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_18:
    // 0x8006253C: jal         0x80061F0C
    // 0x80062540: nop

    ActorEvent_Load(rdram, ctx);
        goto after_7;
    // 0x80062540: nop

    after_7:
    // 0x80062544: b           L_8006255C
    // 0x80062548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8006255C;
    // 0x80062548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006254C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80062550:
    // 0x80062550: bne         $a2, $v0, L_80062530
    if (ctx->r6 != ctx->r2) {
        // 0x80062554: addiu       $a0, $a0, 0x2F4
        ctx->r4 = ADD32(ctx->r4, 0X2F4);
            goto L_80062530;
    }
    // 0x80062554: addiu       $a0, $a0, 0x2F4
    ctx->r4 = ADD32(ctx->r4, 0X2F4);
L_80062558:
    // 0x80062558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006255C:
    // 0x8006255C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80062560: jr          $ra
    // 0x80062564: nop

    return;
    // 0x80062564: nop

;}
RECOMP_FUNC void func_80009504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009504: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009508: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000950C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80009510: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80009514: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80009518: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8000951C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80009520: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80009524: beq         $v0, $zero, L_80009534
    if (ctx->r2 == 0) {
        // 0x80009528: lui         $t7, 0x8015
        ctx->r15 = S32(0X8015 << 16);
            goto L_80009534;
    }
    // 0x80009528: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8000952C: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x80009530: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80009534:
    // 0x80009534: lh          $t6, 0x18($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X18);
    // 0x80009538: lh          $t7, -0x3E4C($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X3E4C);
    // 0x8000953C: addiu       $s2, $s1, 0xC
    ctx->r18 = ADD32(ctx->r17, 0XC);
    // 0x80009540: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80009544: sh          $t8, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r24;
    // 0x80009548: lh          $t9, 0x18($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X18);
    // 0x8000954C: slti        $at, $t9, 0x1001
    ctx->r1 = SIGNED(ctx->r25) < 0X1001 ? 1 : 0;
    // 0x80009550: bne         $at, $zero, L_8000957C
    if (ctx->r1 != 0) {
        // 0x80009554: nop
    
            goto L_8000957C;
    }
    // 0x80009554: nop

L_80009558:
    // 0x80009558: jal         0x80009124
    // 0x8000955C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80009124(rdram, ctx);
        goto after_0;
    // 0x8000955C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80009560: lh          $t0, 0x18($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X18);
    // 0x80009564: addiu       $t1, $t0, -0x1000
    ctx->r9 = ADD32(ctx->r8, -0X1000);
    // 0x80009568: sh          $t1, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r9;
    // 0x8000956C: lh          $t2, 0x18($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X18);
    // 0x80009570: slti        $at, $t2, 0x1001
    ctx->r1 = SIGNED(ctx->r10) < 0X1001 ? 1 : 0;
    // 0x80009574: beq         $at, $zero, L_80009558
    if (ctx->r1 == 0) {
        // 0x80009578: nop
    
            goto L_80009558;
    }
    // 0x80009578: nop

L_8000957C:
    // 0x8000957C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80009580: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80009584: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80009588: addiu       $a3, $a3, 0x6548
    ctx->r7 = ADD32(ctx->r7, 0X6548);
    // 0x8000958C: addiu       $a1, $a1, 0x6148
    ctx->r5 = ADD32(ctx->r5, 0X6148);
    // 0x80009590: addiu       $a0, $a0, 0x5D48
    ctx->r4 = ADD32(ctx->r4, 0X5D48);
    // 0x80009594: jal         0x80008364
    // 0x80009598: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    AudioSynth_InverseDiscreteCosineTransform(rdram, ctx);
        goto after_1;
    // 0x80009598: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x8000959C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800095A0: lwc1        $f12, -0x79AC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X79AC);
    // 0x800095A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800095A8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800095AC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800095B0: addiu       $v1, $v1, 0x6148
    ctx->r3 = ADD32(ctx->r3, 0X6148);
    // 0x800095B4: addiu       $v0, $v0, 0x5D48
    ctx->r2 = ADD32(ctx->r2, 0X5D48);
    // 0x800095B8: lwc1        $f2, -0x79A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X79A8);
    // 0x800095BC: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
L_800095C0:
    // 0x800095C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800095C4: nop

    // 0x800095C8: bc1fl       L_800095DC
    if (!c1cs) {
        // 0x800095CC: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_800095DC;
    }
    goto skip_0;
    // 0x800095CC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x800095D0: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x800095D4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800095D8: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_800095DC:
    // 0x800095DC: nop

    // 0x800095E0: bc1fl       L_800095F0
    if (!c1cs) {
        // 0x800095E4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800095F0;
    }
    goto skip_1;
    // 0x800095E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_1:
    // 0x800095E8: swc1        $f12, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f12.u32l;
    // 0x800095EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800095F0:
    // 0x800095F0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800095F4: bnel        $at, $zero, L_800095C0
    if (ctx->r1 != 0) {
        // 0x800095F8: lwc1        $f0, 0x0($v0)
        ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
            goto L_800095C0;
    }
    goto skip_2;
    // 0x800095F8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    skip_2:
    // 0x800095FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80009600: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80009604: addiu       $v1, $v1, 0x6148
    ctx->r3 = ADD32(ctx->r3, 0X6148);
    // 0x80009608: addiu       $v0, $v0, 0x5D48
    ctx->r2 = ADD32(ctx->r2, 0X5D48);
L_8000960C:
    // 0x8000960C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80009610: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80009614: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80009618: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8000961C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80009620: nop

    // 0x80009624: sh          $t4, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r12;
    // 0x80009628: lwc1        $f8, -0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, -0XC);
    // 0x8000962C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80009630: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80009634: nop

    // 0x80009638: sh          $t6, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r14;
    // 0x8000963C: lwc1        $f16, -0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, -0X8);
    // 0x80009640: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80009644: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x80009648: nop

    // 0x8000964C: sh          $t8, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r24;
    // 0x80009650: lwc1        $f4, -0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, -0X4);
    // 0x80009654: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80009658: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x8000965C: bne         $v0, $v1, L_8000960C
    if (ctx->r2 != ctx->r3) {
        // 0x80009660: sh          $t0, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r8;
            goto L_8000960C;
    }
    // 0x80009660: sh          $t0, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r8;
    // 0x80009664: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80009668: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000966C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80009670: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80009674: jr          $ra
    // 0x80009678: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80009678: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Main_StartNextTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800049D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800049DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800049E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800049E4: lw          $v1, 0x1FB4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1FB4);
    // 0x800049E8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800049EC: addiu       $s0, $s0, 0x1FB0
    ctx->r16 = ADD32(ctx->r16, 0X1FB0);
    // 0x800049F0: beql        $v1, $zero, L_80004A58
    if (ctx->r3 == 0) {
        // 0x800049F4: lw          $t0, 0x0($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X0);
            goto L_80004A58;
    }
    goto skip_0;
    // 0x800049F4: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x800049F8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800049FC: addiu       $s0, $s0, 0x1FB0
    ctx->r16 = ADD32(ctx->r16, 0X1FB0);
    // 0x80004A00: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80004A04: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80004A08: beq         $v0, $zero, L_80004A34
    if (ctx->r2 == 0) {
        // 0x80004A0C: nop
    
            goto L_80004A34;
    }
    // 0x80004A0C: nop

    // 0x80004A10: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80004A14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80004A18: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80004A1C: bnel        $t6, $at, L_80004AAC
    if (ctx->r14 != ctx->r1) {
        // 0x80004A20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80004AAC;
    }
    goto skip_1;
    // 0x80004A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80004A24: jal         0x80021E80
    // 0x80004A28: sw          $t7, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r15;
    osSpTaskYield_recomp(rdram, ctx);
        goto after_0;
    // 0x80004A28: sw          $t7, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r15;
    after_0:
    // 0x80004A2C: b           L_80004AAC
    // 0x80004A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80004AAC;
    // 0x80004A30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80004A34:
    // 0x80004A34: jal         0x80021FBC
    // 0x80004A38: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_1;
    // 0x80004A38: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    after_1:
    // 0x80004A3C: jal         0x8002214C
    // 0x80004A40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_2;
    // 0x80004A40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_2:
    // 0x80004A44: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80004A48: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80004A4C: b           L_80004AA8
    // 0x80004A50: sw          $t8, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r24;
        goto L_80004AA8;
    // 0x80004A50: sw          $t8, 0x48($t9)
    MEM_W(0X48, ctx->r25) = ctx->r24;
    // 0x80004A54: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
L_80004A58:
    // 0x80004A58: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80004A5C: bnel        $t0, $zero, L_80004AAC
    if (ctx->r8 != 0) {
        // 0x80004A60: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80004AAC;
    }
    goto skip_2;
    // 0x80004A60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80004A64: lw          $v0, 0x1FB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1FB8);
    // 0x80004A68: beql        $v0, $zero, L_80004AAC
    if (ctx->r2 == 0) {
        // 0x80004A6C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80004AAC;
    }
    goto skip_3;
    // 0x80004A6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80004A70: lw          $t1, 0x48($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X48);
    // 0x80004A74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80004A78: addiu       $a0, $zero, 0x3C0
    ctx->r4 = ADD32(0, 0X3C0);
    // 0x80004A7C: beql        $t1, $at, L_80004AAC
    if (ctx->r9 == ctx->r1) {
        // 0x80004A80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80004AAC;
    }
    goto skip_4;
    // 0x80004A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80004A84: jal         0x80022190
    // 0x80004A88: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    osDpSetStatus_recomp(rdram, ctx);
        goto after_3;
    // 0x80004A88: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    after_3:
    // 0x80004A8C: jal         0x80021FBC
    // 0x80004A90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_4;
    // 0x80004A90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_4:
    // 0x80004A94: jal         0x8002214C
    // 0x80004A98: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_5;
    // 0x80004A98: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x80004A9C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80004AA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80004AA4: sw          $t2, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->r10;
L_80004AA8:
    // 0x80004AA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80004AAC:
    // 0x80004AAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004AB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004AB4: jr          $ra
    // 0x80004AB8: nop

    return;
    // 0x80004AB8: nop

;}
RECOMP_FUNC void Audio_SeqLayerDecayRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012438: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001243C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80012440: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012444: beq         $a0, $a2, L_8001265C
    if (ctx->r4 == ctx->r6) {
        // 0x80012448: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8001265C;
    }
    // 0x80012448: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001244C: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80012450: sb          $zero, 0x3($a0)
    MEM_B(0X3, ctx->r4) = 0;
    // 0x80012454: beql        $v0, $zero, L_80012660
    if (ctx->r2 == 0) {
        // 0x80012458: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012660;
    }
    goto skip_0;
    // 0x80012458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001245C: lw          $t6, 0x48($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X48);
    // 0x80012460: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80012464: bnel        $a0, $t6, L_80012474
    if (ctx->r4 != ctx->r14) {
        // 0x80012468: lw          $v0, 0x44($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X44);
            goto L_80012474;
    }
    goto skip_1;
    // 0x80012468: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
    skip_1:
    // 0x8001246C: sw          $a2, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r6;
    // 0x80012470: lw          $v0, 0x44($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X44);
L_80012474:
    // 0x80012474: beql        $a0, $v0, L_800124C8
    if (ctx->r4 == ctx->r2) {
        // 0x80012478: lbu         $t2, 0x59($a1)
        ctx->r10 = MEM_BU(ctx->r5, 0X59);
            goto L_800124C8;
    }
    goto skip_2;
    // 0x80012478: lbu         $t2, 0x59($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X59);
    skip_2:
    // 0x8001247C: bnel        $a2, $v0, L_80012660
    if (ctx->r6 != ctx->r2) {
        // 0x80012480: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012660;
    }
    goto skip_3;
    // 0x80012480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80012484: lw          $t7, 0x48($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X48);
    // 0x80012488: bnel        $a2, $t7, L_80012660
    if (ctx->r6 != ctx->r15) {
        // 0x8001248C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012660;
    }
    goto skip_4;
    // 0x8001248C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80012490: lw          $t8, 0x40($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X40);
    // 0x80012494: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80012498: bnel        $a0, $t8, L_80012660
    if (ctx->r4 != ctx->r24) {
        // 0x8001249C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012660;
    }
    goto skip_5;
    // 0x8001249C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x800124A0: beql        $a3, $t0, L_80012660
    if (ctx->r7 == ctx->r8) {
        // 0x800124A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012660;
    }
    goto skip_6;
    // 0x800124A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x800124A8: lbu         $t9, 0x58($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X58);
    // 0x800124AC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800124B0: lwc1        $f4, 0x5C90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5C90);
    // 0x800124B4: ori         $t1, $t9, 0x10
    ctx->r9 = ctx->r25 | 0X10;
    // 0x800124B8: sb          $t1, 0x58($a1)
    MEM_B(0X58, ctx->r5) = ctx->r9;
    // 0x800124BC: b           L_8001265C
    // 0x800124C0: swc1        $f4, 0x68($a1)
    MEM_W(0X68, ctx->r5) = ctx->f4.u32l;
        goto L_8001265C;
    // 0x800124C0: swc1        $f4, 0x68($a1)
    MEM_W(0X68, ctx->r5) = ctx->f4.u32l;
    // 0x800124C4: lbu         $t2, 0x59($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X59);
L_800124C8:
    // 0x800124C8: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800124CC: beq         $t0, $t2, L_8001263C
    if (ctx->r8 == ctx->r10) {
        // 0x800124D0: nop
    
            goto L_8001263C;
    }
    // 0x800124D0: nop

    // 0x800124D4: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800124D8: addiu       $v0, $a1, 0x4C
    ctx->r2 = ADD32(ctx->r5, 0X4C);
    // 0x800124DC: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800124E0: lwc1        $f8, 0x2C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800124E4: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800124E8: lbu         $t3, 0x7($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X7);
    // 0x800124EC: sb          $t3, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r11;
    // 0x800124F0: lbu         $at, 0x1($a0)
    ctx->r1 = MEM_BU(ctx->r4, 0X1);
    // 0x800124F4: sb          $at, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r1;
    // 0x800124F8: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x800124FC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80012500: beql        $v1, $zero, L_80012554
    if (ctx->r3 == 0) {
        // 0x80012504: lw          $t9, 0x44($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X44);
            goto L_80012554;
    }
    goto skip_7;
    // 0x80012504: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    skip_7:
    // 0x80012508: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x8001250C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80012510: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80012514: lbu         $t8, 0xB($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0XB);
    // 0x80012518: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8001251C: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x80012520: lw          $t9, 0x44($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X44);
    // 0x80012524: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80012528: sll         $t3, $t1, 2
    ctx->r11 = S32(ctx->r9 << 2);
    // 0x8001252C: bgezl       $t3, L_80012554
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80012530: lw          $t9, 0x44($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X44);
            goto L_80012554;
    }
    goto skip_8;
    // 0x80012530: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    skip_8:
    // 0x80012534: lbu         $t4, 0x3($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X3);
    // 0x80012538: andi        $t5, $t4, 0x8
    ctx->r13 = ctx->r12 & 0X8;
    // 0x8001253C: beql        $t5, $zero, L_80012554
    if (ctx->r13 == 0) {
        // 0x80012540: lw          $t9, 0x44($a1)
        ctx->r25 = MEM_W(ctx->r5, 0X44);
            goto L_80012554;
    }
    goto skip_9;
    // 0x80012540: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
    skip_9:
    // 0x80012544: lbu         $t7, 0xB0($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XB0);
    // 0x80012548: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x8001254C: sb          $t8, 0xB0($a1)
    MEM_B(0XB0, ctx->r5) = ctx->r24;
    // 0x80012550: lw          $t9, 0x44($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X44);
L_80012554:
    // 0x80012554: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80012558: sb          $v1, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r3;
    // 0x8001255C: sw          $a2, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r6;
    // 0x80012560: bne         $a3, $at, L_8001258C
    if (ctx->r7 != ctx->r1) {
        // 0x80012564: sw          $t9, 0x40($a1)
        MEM_W(0X40, ctx->r5) = ctx->r25;
            goto L_8001258C;
    }
    // 0x80012564: sw          $t9, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->r25;
    // 0x80012568: lbu         $t1, 0x58($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X58);
    // 0x8001256C: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80012570: lwc1        $f10, 0x5C90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5C90);
    // 0x80012574: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80012578: ori         $t2, $t1, 0x10
    ctx->r10 = ctx->r9 | 0X10;
    // 0x8001257C: sb          $t2, 0x58($a1)
    MEM_B(0X58, ctx->r5) = ctx->r10;
    // 0x80012580: sb          $t3, 0x34($a1)
    MEM_B(0X34, ctx->r5) = ctx->r11;
    // 0x80012584: b           L_8001263C
    // 0x80012588: swc1        $f10, 0x68($a1)
    MEM_W(0X68, ctx->r5) = ctx->f10.u32l;
        goto L_8001263C;
    // 0x80012588: swc1        $f10, 0x68($a1)
    MEM_W(0X68, ctx->r5) = ctx->f10.u32l;
L_8001258C:
    // 0x8001258C: lbu         $t4, 0x58($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X58);
    // 0x80012590: sb          $v1, 0x34($a1)
    MEM_B(0X34, ctx->r5) = ctx->r3;
    // 0x80012594: ori         $t5, $t4, 0x20
    ctx->r13 = ctx->r12 | 0X20;
    // 0x80012598: sb          $t5, 0x58($a1)
    MEM_B(0X58, ctx->r5) = ctx->r13;
    // 0x8001259C: lbu         $v0, 0x18($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X18);
    // 0x800125A0: bnel        $v0, $zero, L_800125E4
    if (ctx->r2 != 0) {
        // 0x800125A4: mtc1        $v0, $f10
        ctx->f10.u32l = ctx->r2;
            goto L_800125E4;
    }
    goto skip_10;
    // 0x800125A4: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    skip_10:
    // 0x800125A8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x800125AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800125B0: lbu         $t7, 0x74($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X74);
    // 0x800125B4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800125B8: bgez        $t7, L_800125CC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800125BC: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800125CC;
    }
    // 0x800125BC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800125C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800125C4: nop

    // 0x800125C8: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800125CC:
    // 0x800125CC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x800125D0: lwc1        $f6, 0x5C94($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5C94);
    // 0x800125D4: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800125D8: b           L_8001260C
    // 0x800125DC: swc1        $f8, 0x68($a1)
    MEM_W(0X68, ctx->r5) = ctx->f8.u32l;
        goto L_8001260C;
    // 0x800125DC: swc1        $f8, 0x68($a1)
    MEM_W(0X68, ctx->r5) = ctx->f8.u32l;
    // 0x800125E0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_800125E4:
    // 0x800125E4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800125E8: bgez        $v0, L_800125FC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800125EC: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800125FC;
    }
    // 0x800125EC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800125F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800125F4: nop

    // 0x800125F8: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_800125FC:
    // 0x800125FC: lui         $at, 0x8015
    ctx->r1 = S32(0X8015 << 16);
    // 0x80012600: lwc1        $f18, 0x5C94($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5C94);
    // 0x80012604: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80012608: swc1        $f6, 0x68($a1)
    MEM_W(0X68, ctx->r5) = ctx->f6.u32l;
L_8001260C:
    // 0x8001260C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80012610: lwc1        $f4, 0x6C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80012614: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x80012618: lbu         $t9, 0x75($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X75);
    // 0x8001261C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80012620: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80012624: nop

    // 0x80012628: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001262C: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80012630: nop

    // 0x80012634: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80012638: swc1        $f6, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f6.u32l;
L_8001263C:
    // 0x8001263C: bne         $a3, $t0, L_8001265C
    if (ctx->r7 != ctx->r8) {
        // 0x80012640: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8001265C;
    }
    // 0x80012640: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80012644: jal         0x80012C40
    // 0x80012648: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    Audio_AudioListRemove(rdram, ctx);
        goto after_0;
    // 0x80012648: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8001264C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80012650: lw          $a0, 0xC($a1)
    ctx->r4 = MEM_W(ctx->r5, 0XC);
    // 0x80012654: jal         0x80012C00
    // 0x80012658: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    Audio_AudioListPushFront(rdram, ctx);
        goto after_1;
    // 0x80012658: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    after_1:
L_8001265C:
    // 0x8001265C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80012660:
    // 0x80012660: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012664: jr          $ra
    // 0x80012668: nop

    return;
    // 0x80012668: nop

;}
RECOMP_FUNC void Audio_ChooseActiveSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800198C0: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x800198C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800198C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800198CC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800198D0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800198D4: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800198D8: andi        $s5, $a0, 0xFF
    ctx->r21 = ctx->r4 & 0XFF;
    // 0x800198DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800198E0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800198E4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800198E8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800198EC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800198F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800198F4: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800198F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800198FC: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80019900: addiu       $s1, $sp, 0x6C
    ctx->r17 = ADD32(ctx->r29, 0X6C);
    // 0x80019904: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x80019908: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_8001990C:
    // 0x8001990C: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x80019910: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80019914: andi        $t7, $t3, 0xFF
    ctx->r15 = ctx->r11 & 0XFF;
    // 0x80019918: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x8001991C: addu        $a3, $s1, $t6
    ctx->r7 = ADD32(ctx->r17, ctx->r14);
    // 0x80019920: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
    // 0x80019924: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80019928: bne         $at, $zero, L_8001990C
    if (ctx->r1 != 0) {
        // 0x8001992C: sb          $s4, 0x4($a3)
        MEM_B(0X4, ctx->r7) = ctx->r20;
            goto L_8001990C;
    }
    // 0x8001992C: sb          $s4, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r20;
    // 0x80019930: sll         $t8, $s5, 4
    ctx->r24 = S32(ctx->r21 << 4);
    // 0x80019934: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80019938: subu        $t8, $t8, $s5
    ctx->r24 = SUB32(ctx->r24, ctx->r21);
    // 0x8001993C: addiu       $t5, $t5, -0x79A0
    ctx->r13 = ADD32(ctx->r13, -0X79A0);
    // 0x80019940: sll         $t8, $t8, 6
    ctx->r24 = S32(ctx->r24 << 6);
    // 0x80019944: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x80019948: lbu         $s3, 0x2B($t9)
    ctx->r19 = MEM_BU(ctx->r25, 0X2B);
    // 0x8001994C: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
    // 0x80019950: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80019954: beq         $s7, $s3, L_80019D4C
    if (ctx->r23 == ctx->r19) {
        // 0x80019958: sll         $t6, $s5, 4
        ctx->r14 = S32(ctx->r21 << 4);
            goto L_80019D4C;
    }
    // 0x80019958: sll         $t6, $s5, 4
    ctx->r14 = S32(ctx->r21 << 4);
    // 0x8001995C: subu        $t6, $t6, $s5
    ctx->r14 = SUB32(ctx->r14, ctx->r21);
    // 0x80019960: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x80019964: addu        $ra, $t5, $t6
    ctx->r31 = ADD32(ctx->r13, ctx->r14);
    // 0x80019968: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8001996C: addiu       $s6, $zero, 0x30
    ctx->r22 = ADD32(0, 0X30);
    // 0x80019970: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
L_80019974:
    // 0x80019974: multu       $s3, $s6
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019978: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x8001997C: mflo        $t7
    ctx->r15 = lo;
    // 0x80019980: addu        $t2, $ra, $t7
    ctx->r10 = ADD32(ctx->r31, ctx->r15);
    // 0x80019984: lbu         $t8, 0x28($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X28);
    // 0x80019988: bnel        $fp, $t8, L_800199B0
    if (ctx->r30 != ctx->r24) {
        // 0x8001998C: lbu         $t9, 0x29($t2)
        ctx->r25 = MEM_BU(ctx->r10, 0X29);
            goto L_800199B0;
    }
    goto skip_0;
    // 0x8001998C: lbu         $t9, 0x29($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X29);
    skip_0:
    // 0x80019990: lw          $t9, 0x24($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X24);
    // 0x80019994: and         $t6, $t9, $v0
    ctx->r14 = ctx->r25 & ctx->r2;
    // 0x80019998: bnel        $v0, $t6, L_800199B0
    if (ctx->r2 != ctx->r14) {
        // 0x8001999C: lbu         $t9, 0x29($t2)
        ctx->r25 = MEM_BU(ctx->r10, 0X29);
            goto L_800199B0;
    }
    goto skip_1;
    // 0x8001999C: lbu         $t9, 0x29($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X29);
    skip_1:
    // 0x800199A0: lbu         $t7, 0x29($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X29);
    // 0x800199A4: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800199A8: sb          $t8, 0x29($t2)
    MEM_B(0X29, ctx->r10) = ctx->r24;
    // 0x800199AC: lbu         $t9, 0x29($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X29);
L_800199B0:
    // 0x800199B0: bnel        $t9, $zero, L_800199DC
    if (ctx->r25 != 0) {
        // 0x800199B4: lbu         $t6, 0x28($t2)
        ctx->r14 = MEM_BU(ctx->r10, 0X28);
            goto L_800199DC;
    }
    goto skip_2;
    // 0x800199B4: lbu         $t6, 0x28($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X28);
    skip_2:
    // 0x800199B8: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x800199BC: jal         0x800197AC
    // 0x800199C0: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_0;
    // 0x800199C0: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    after_0:
    // 0x800199C4: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x800199C8: addiu       $t5, $t5, -0x79A0
    ctx->r13 = ADD32(ctx->r13, -0X79A0);
    // 0x800199CC: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x800199D0: b           L_80019D34
    // 0x800199D4: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
        goto L_80019D34;
    // 0x800199D4: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
    // 0x800199D8: lbu         $t6, 0x28($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X28);
L_800199DC:
    // 0x800199DC: beq         $t6, $zero, L_80019D34
    if (ctx->r14 == 0) {
        // 0x800199E0: nop
    
            goto L_80019D34;
    }
    // 0x800199E0: nop

    // 0x800199E4: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800199E8: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x800199EC: addiu       $t7, $t7, 0x5D28
    ctx->r15 = ADD32(ctx->r15, 0X5D28);
    // 0x800199F0: bnel        $t7, $v0, L_80019A08
    if (ctx->r15 != ctx->r2) {
        // 0x800199F4: lw          $t8, 0x4($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X4);
            goto L_80019A08;
    }
    goto skip_3;
    // 0x800199F4: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    skip_3:
    // 0x800199F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800199FC: b           L_80019A40
    // 0x80019A00: swc1        $f4, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f4.u32l;
        goto L_80019A40;
    // 0x80019A00: swc1        $f4, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f4.u32l;
    // 0x80019A04: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
L_80019A08:
    // 0x80019A08: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80019A0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019A10: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80019A14: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019A18: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x80019A1C: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80019A20: lwc1        $f2, 0x0($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80019A24: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80019A28: nop

    // 0x80019A2C: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80019A30: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80019A34: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80019A38: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80019A3C: swc1        $f6, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f6.u32l;
L_80019A40:
    // 0x80019A40: lw          $v0, 0x24($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X24);
    // 0x80019A44: andi        $v1, $v0, 0xFF00
    ctx->r3 = ctx->r2 & 0XFF00;
    // 0x80019A48: srl         $t6, $v1, 8
    ctx->r14 = S32(U32(ctx->r3) >> 8);
    // 0x80019A4C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80019A50: sll         $t8, $v0, 11
    ctx->r24 = S32(ctx->r2 << 11);
    // 0x80019A54: bgez        $t8, L_80019A98
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80019A58: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80019A98;
    }
    // 0x80019A58: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80019A5C: subu        $v0, $s7, $t7
    ctx->r2 = SUB32(ctx->r23, ctx->r15);
    // 0x80019A60: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019A64: lwc1        $f0, 0x1C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80019A68: mflo        $t9
    ctx->r25 = lo;
    // 0x80019A6C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80019A70: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80019A74: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80019A78: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80019A7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80019A80: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80019A84: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80019A88: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80019A8C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80019A90: b           L_80019B98
    // 0x80019A94: sw          $t6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r14;
        goto L_80019B98;
    // 0x80019A94: sw          $t6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r14;
L_80019A98:
    // 0x80019A98: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80019A9C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80019AA0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80019AA4: lwc1        $f0, 0x1C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80019AA8: subu        $v0, $s7, $v1
    ctx->r2 = SUB32(ctx->r23, ctx->r3);
    // 0x80019AAC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80019AB0: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80019AB4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80019AB8: nop

    // 0x80019ABC: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80019AC0: beql        $t8, $zero, L_80019B10
    if (ctx->r24 == 0) {
        // 0x80019AC4: mfc1        $t8, $f8
        ctx->r24 = (int32_t)ctx->f8.u32l;
            goto L_80019B10;
    }
    goto skip_4;
    // 0x80019AC4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    skip_4:
    // 0x80019AC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80019ACC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80019AD0: sub.s       $f8, $f0, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80019AD4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80019AD8: nop

    // 0x80019ADC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80019AE0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80019AE4: nop

    // 0x80019AE8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x80019AEC: bne         $t8, $zero, L_80019B04
    if (ctx->r24 != 0) {
        // 0x80019AF0: nop
    
            goto L_80019B04;
    }
    // 0x80019AF0: nop

    // 0x80019AF4: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80019AF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80019AFC: b           L_80019B1C
    // 0x80019B00: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_80019B1C;
    // 0x80019B00: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_80019B04:
    // 0x80019B04: b           L_80019B1C
    // 0x80019B08: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_80019B1C;
    // 0x80019B08: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80019B0C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
L_80019B10:
    // 0x80019B10: nop

    // 0x80019B14: bltz        $t8, L_80019B04
    if (SIGNED(ctx->r24) < 0) {
        // 0x80019B18: nop
    
            goto L_80019B04;
    }
    // 0x80019B18: nop

L_80019B1C:
    // 0x80019B1C: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019B20: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80019B24: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80019B28: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80019B2C: mflo        $t9
    ctx->r25 = lo;
    // 0x80019B30: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80019B34: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80019B38: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80019B3C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x80019B40: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80019B44: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80019B48: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80019B4C: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x80019B50: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x80019B54: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80019B58: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80019B5C: sw          $t7, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r15;
    // 0x80019B60: lwc1        $f2, 0x0($t9)
    ctx->f2.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80019B64: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80019B68: nop

    // 0x80019B6C: bc1fl       L_80019B9C
    if (!c1cs) {
        // 0x80019B70: lw          $v1, 0x24($t2)
        ctx->r3 = MEM_W(ctx->r10, 0X24);
            goto L_80019B9C;
    }
    goto skip_5;
    // 0x80019B70: lw          $v1, 0x24($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X24);
    skip_5:
    // 0x80019B74: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80019B78: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x80019B7C: lwc1        $f0, 0x1C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80019B80: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80019B84: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80019B88: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x80019B8C: nop

    // 0x80019B90: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80019B94: sw          $t9, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r25;
L_80019B98:
    // 0x80019B98: lw          $v1, 0x24($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X24);
L_80019B9C:
    // 0x80019B9C: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x80019BA0: and         $t6, $v1, $at
    ctx->r14 = ctx->r3 & ctx->r1;
    // 0x80019BA4: srl         $t8, $t6, 16
    ctx->r24 = S32(U32(ctx->r14) >> 16);
    // 0x80019BA8: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x80019BAC: beq         $t7, $zero, L_80019BD8
    if (ctx->r15 == 0) {
        // 0x80019BB0: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80019BD8;
    }
    // 0x80019BB0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80019BB4: multu       $t7, $t7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019BB8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80019BBC: lwc1        $f6, -0x6F54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6F54);
    // 0x80019BC0: mflo        $t9
    ctx->r25 = lo;
    // 0x80019BC4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80019BC8: nop

    // 0x80019BCC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80019BD0: b           L_80019BDC
    // 0x80019BD4: div.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
        goto L_80019BDC;
    // 0x80019BD4: div.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
L_80019BD8:
    // 0x80019BD8: lwc1        $f2, -0x6F50($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6F50);
L_80019BDC:
    // 0x80019BDC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80019BE0: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80019BE4: bc1f        L_80019C60
    if (!c1cs) {
        // 0x80019BE8: nop
    
            goto L_80019C60;
    }
    // 0x80019BE8: nop

    // 0x80019BEC: lbu         $t6, 0x28($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X28);
    // 0x80019BF0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80019BF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019BF8: bnel        $t6, $at, L_80019D30
    if (ctx->r14 != ctx->r1) {
        // 0x80019BFC: andi        $s0, $s3, 0xFF
        ctx->r16 = ctx->r19 & 0XFF;
            goto L_80019D30;
    }
    goto skip_6;
    // 0x80019BFC: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    skip_6:
    // 0x80019C00: lbu         $t8, 0x2C($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2C);
    // 0x80019C04: lui         $at, 0x602
    ctx->r1 = S32(0X602 << 16);
    // 0x80019C08: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x80019C0C: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80019C10: or          $a0, $t7, $at
    ctx->r4 = ctx->r15 | ctx->r1;
    // 0x80019C14: jal         0x8001E8F0
    // 0x80019C18: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    AudioThread_QueueCmdS8(rdram, ctx);
        goto after_1;
    // 0x80019C18: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    after_1:
    // 0x80019C1C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x80019C20: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80019C24: addiu       $t5, $t5, -0x79A0
    ctx->r13 = ADD32(ctx->r13, -0X79A0);
    // 0x80019C28: lw          $t6, 0x24($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X24);
    // 0x80019C2C: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x80019C30: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x80019C34: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x80019C38: bgezl       $t8, L_80019D30
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80019C3C: andi        $s0, $s3, 0xFF
        ctx->r16 = ctx->r19 & 0XFF;
            goto L_80019D30;
    }
    goto skip_7;
    // 0x80019C3C: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
    skip_7:
    // 0x80019C40: sw          $ra, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r31;
    // 0x80019C44: jal         0x800197AC
    // 0x80019C48: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_2;
    // 0x80019C48: andi        $a1, $s3, 0xFF
    ctx->r5 = ctx->r19 & 0XFF;
    after_2:
    // 0x80019C4C: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80019C50: addiu       $t5, $t5, -0x79A0
    ctx->r13 = ADD32(ctx->r13, -0X79A0);
    // 0x80019C54: lw          $ra, 0x58($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X58);
    // 0x80019C58: b           L_80019D2C
    // 0x80019C5C: andi        $s3, $s0, 0xFF
    ctx->r19 = ctx->r16 & 0XFF;
        goto L_80019D2C;
    // 0x80019C5C: andi        $s3, $s0, 0xFF
    ctx->r19 = ctx->r16 & 0XFF;
L_80019C60:
    // 0x80019C60: lbu         $t7, 0x5D20($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5D20);
    // 0x80019C64: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x80019C68: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80019C6C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80019C70: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80019C74: addu        $t6, $t9, $s5
    ctx->r14 = ADD32(ctx->r25, ctx->r21);
    // 0x80019C78: addu        $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x80019C7C: lbu         $t4, 0x5CE0($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X5CE0);
    // 0x80019C80: or          $t1, $t4, $zero
    ctx->r9 = ctx->r12 | 0;
    // 0x80019C84: blez        $t1, L_80019D2C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80019C88: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_80019D2C;
    }
    // 0x80019C88: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_80019C8C:
    // 0x80019C8C: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x80019C90: addu        $a3, $s1, $t8
    ctx->r7 = ADD32(ctx->r17, ctx->r24);
    // 0x80019C94: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80019C98: lw          $v1, 0x20($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X20);
    // 0x80019C9C: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x80019CA0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x80019CA4: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x80019CA8: bne         $at, $zero, L_80019D18
    if (ctx->r1 != 0) {
        // 0x80019CAC: or          $a2, $t3, $zero
        ctx->r6 = ctx->r11 | 0;
            goto L_80019D18;
    }
    // 0x80019CAC: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80019CB0: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80019CB4: beq         $at, $zero, L_80019CC8
    if (ctx->r1 == 0) {
        // 0x80019CB8: andi        $a0, $v0, 0xFF
        ctx->r4 = ctx->r2 & 0XFF;
            goto L_80019CC8;
    }
    // 0x80019CB8: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80019CBC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80019CC0: andi        $t9, $s2, 0xFF
    ctx->r25 = ctx->r18 & 0XFF;
    // 0x80019CC4: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
L_80019CC8:
    // 0x80019CC8: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80019CCC: beq         $at, $zero, L_80019D10
    if (ctx->r1 == 0) {
        // 0x80019CD0: andi        $t3, $t1, 0xFF
        ctx->r11 = ctx->r9 & 0XFF;
            goto L_80019D10;
    }
    // 0x80019CD0: andi        $t3, $t1, 0xFF
    ctx->r11 = ctx->r9 & 0XFF;
    // 0x80019CD4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80019CD8:
    // 0x80019CD8: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80019CDC: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x80019CE0: lw          $t7, -0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X8);
    // 0x80019CE4: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80019CE8: addu        $a0, $s1, $t6
    ctx->r4 = ADD32(ctx->r17, ctx->r14);
    // 0x80019CEC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80019CF0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80019CF4: lbu         $t9, -0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X4);
    // 0x80019CF8: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x80019CFC: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80019D00: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80019D04: bne         $at, $zero, L_80019CD8
    if (ctx->r1 != 0) {
        // 0x80019D08: sb          $t9, 0x4($a0)
        MEM_B(0X4, ctx->r4) = ctx->r25;
            goto L_80019CD8;
    }
    // 0x80019D08: sb          $t9, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r25;
    // 0x80019D0C: lw          $v1, 0x20($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X20);
L_80019D10:
    // 0x80019D10: sw          $v1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r3;
    // 0x80019D14: sb          $s3, 0x4($a3)
    MEM_B(0X4, ctx->r7) = ctx->r19;
L_80019D18:
    // 0x80019D18: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80019D1C: andi        $t8, $t3, 0xFF
    ctx->r24 = ctx->r11 & 0XFF;
    // 0x80019D20: slt         $at, $t8, $t0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80019D24: bne         $at, $zero, L_80019C8C
    if (ctx->r1 != 0) {
        // 0x80019D28: or          $t3, $t8, $zero
        ctx->r11 = ctx->r24 | 0;
            goto L_80019C8C;
    }
    // 0x80019D28: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
L_80019D2C:
    // 0x80019D2C: andi        $s0, $s3, 0xFF
    ctx->r16 = ctx->r19 & 0XFF;
L_80019D30:
    // 0x80019D30: lui         $v0, 0x800
    ctx->r2 = S32(0X800 << 16);
L_80019D34:
    // 0x80019D34: multu       $s0, $s6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019D38: mflo        $t7
    ctx->r15 = lo;
    // 0x80019D3C: addu        $t9, $ra, $t7
    ctx->r25 = ADD32(ctx->r31, ctx->r15);
    // 0x80019D40: lbu         $s3, 0x2B($t9)
    ctx->r19 = MEM_BU(ctx->r25, 0X2B);
    // 0x80019D44: bne         $s7, $s3, L_80019974
    if (ctx->r23 != ctx->r19) {
        // 0x80019D48: nop
    
            goto L_80019974;
    }
    // 0x80019D48: nop

L_80019D4C:
    // 0x80019D4C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x80019D50: lbu         $t6, 0x5D20($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5D20);
    // 0x80019D54: lui         $t1, 0x800C
    ctx->r9 = S32(0X800C << 16);
    // 0x80019D58: addiu       $s6, $zero, 0x30
    ctx->r22 = ADD32(0, 0X30);
    // 0x80019D5C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80019D60: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x80019D64: addu        $t7, $t8, $s5
    ctx->r15 = ADD32(ctx->r24, ctx->r21);
    // 0x80019D68: addu        $t1, $t1, $t7
    ctx->r9 = ADD32(ctx->r9, ctx->r15);
    // 0x80019D6C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80019D70: lbu         $t1, 0x5CE0($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X5CE0);
    // 0x80019D74: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80019D78: blez        $s2, L_80019DEC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80019D7C: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80019DEC;
    }
    // 0x80019D7C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80019D80: sll         $t9, $s5, 4
    ctx->r25 = S32(ctx->r21 << 4);
    // 0x80019D84: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80019D88: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80019D8C: addu        $ra, $t5, $t9
    ctx->r31 = ADD32(ctx->r13, ctx->r25);
    // 0x80019D90: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80019D94: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80019D98:
    // 0x80019D98: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x80019D9C: addu        $t8, $s1, $t6
    ctx->r24 = ADD32(ctx->r17, ctx->r14);
    // 0x80019DA0: lbu         $t7, 0x4($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X4);
    // 0x80019DA4: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x80019DA8: andi        $t6, $t3, 0xFF
    ctx->r14 = ctx->r11 & 0XFF;
    // 0x80019DAC: multu       $t7, $s6
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019DB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80019DB4: mflo        $t9
    ctx->r25 = lo;
    // 0x80019DB8: addu        $v0, $ra, $t9
    ctx->r2 = ADD32(ctx->r31, ctx->r25);
    // 0x80019DBC: lbu         $v1, 0x28($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X28);
    // 0x80019DC0: bne         $fp, $v1, L_80019DD0
    if (ctx->r30 != ctx->r3) {
        // 0x80019DC4: nop
    
            goto L_80019DD0;
    }
    // 0x80019DC4: nop

    // 0x80019DC8: b           L_80019DDC
    // 0x80019DCC: sb          $a0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r4;
        goto L_80019DDC;
    // 0x80019DCC: sb          $a0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r4;
L_80019DD0:
    // 0x80019DD0: bnel        $v1, $at, L_80019DE0
    if (ctx->r3 != ctx->r1) {
        // 0x80019DD4: slt         $at, $t6, $a2
        ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80019DE0;
    }
    goto skip_8;
    // 0x80019DD4: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
    skip_8:
    // 0x80019DD8: sb          $a1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r5;
L_80019DDC:
    // 0x80019DDC: slt         $at, $t6, $a2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r6) ? 1 : 0;
L_80019DE0:
    // 0x80019DE0: bne         $at, $zero, L_80019D98
    if (ctx->r1 != 0) {
        // 0x80019DE4: or          $t3, $t6, $zero
        ctx->r11 = ctx->r14 | 0;
            goto L_80019D98;
    }
    // 0x80019DE4: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x80019DE8: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_80019DEC:
    // 0x80019DEC: blez        $t1, L_80019FEC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80019DF0: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_80019FEC;
    }
    // 0x80019DF0: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80019DF4: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x80019DF8: addiu       $t7, $t7, -0x66C8
    ctx->r15 = ADD32(ctx->r15, -0X66C8);
    // 0x80019DFC: sll         $t8, $s5, 6
    ctx->r24 = S32(ctx->r21 << 6);
    // 0x80019E00: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x80019E04: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
L_80019E08:
    // 0x80019E08: sll         $t9, $t3, 3
    ctx->r25 = S32(ctx->r11 << 3);
    // 0x80019E0C: addu        $s3, $a2, $t9
    ctx->r19 = ADD32(ctx->r6, ctx->r25);
    // 0x80019E10: lbu         $a1, 0x4($s3)
    ctx->r5 = MEM_BU(ctx->r19, 0X4);
    // 0x80019E14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019E18: bne         $s7, $a1, L_80019E28
    if (ctx->r23 != ctx->r5) {
        // 0x80019E1C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80019E28;
    }
    // 0x80019E1C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80019E20: b           L_80019F08
    // 0x80019E24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019F08;
    // 0x80019E24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80019E28:
    // 0x80019E28: multu       $a1, $s6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019E2C: sll         $t6, $s5, 4
    ctx->r14 = S32(ctx->r21 << 4);
    // 0x80019E30: subu        $t6, $t6, $s5
    ctx->r14 = SUB32(ctx->r14, ctx->r21);
    // 0x80019E34: sll         $t6, $t6, 6
    ctx->r14 = S32(ctx->r14 << 6);
    // 0x80019E38: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x80019E3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80019E40: mflo        $t7
    ctx->r15 = lo;
    // 0x80019E44: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x80019E48: lbu         $a3, 0x28($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X28);
    // 0x80019E4C: bne         $a3, $at, L_80019EB0
    if (ctx->r7 != ctx->r1) {
        // 0x80019E50: nop
    
            goto L_80019EB0;
    }
    // 0x80019E50: nop

    // 0x80019E54: lw          $t9, 0x24($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X24);
    // 0x80019E58: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80019E5C: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x80019E60: bgezl       $t6, L_80019EA8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80019E64: sb          $t8, 0x28($a0)
        MEM_B(0X28, ctx->r4) = ctx->r24;
            goto L_80019EA8;
    }
    goto skip_9;
    // 0x80019E64: sb          $t8, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r24;
    skip_9:
    // 0x80019E68: andi        $a0, $s5, 0xFF
    ctx->r4 = ctx->r21 & 0XFF;
    // 0x80019E6C: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x80019E70: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80019E74: sb          $t1, 0xBE($sp)
    MEM_B(0XBE, ctx->r29) = ctx->r9;
    // 0x80019E78: jal         0x800197AC
    // 0x80019E7C: sb          $t3, 0xBC($sp)
    MEM_B(0XBC, ctx->r29) = ctx->r11;
    Audio_RemoveSfxBankEntry(rdram, ctx);
        goto after_3;
    // 0x80019E7C: sb          $t3, 0xBC($sp)
    MEM_B(0XBC, ctx->r29) = ctx->r11;
    after_3:
    // 0x80019E80: lui         $t5, 0x8015
    ctx->r13 = S32(0X8015 << 16);
    // 0x80019E84: addiu       $t5, $t5, -0x79A0
    ctx->r13 = ADD32(ctx->r13, -0X79A0);
    // 0x80019E88: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80019E8C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80019E90: lbu         $t1, 0xBE($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0XBE);
    // 0x80019E94: lbu         $t3, 0xBC($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0XBC);
    // 0x80019E98: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x80019E9C: b           L_80019F08
    // 0x80019EA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019F08;
    // 0x80019EA0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80019EA4: sb          $t8, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r24;
L_80019EA8:
    // 0x80019EA8: b           L_80019F08
    // 0x80019EAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019F08;
    // 0x80019EAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80019EB0:
    // 0x80019EB0: bne         $a3, $zero, L_80019EC4
    if (ctx->r7 != 0) {
        // 0x80019EB4: nop
    
            goto L_80019EC4;
    }
    // 0x80019EB4: nop

    // 0x80019EB8: sb          $s4, 0x4($s3)
    MEM_B(0X4, ctx->r19) = ctx->r20;
    // 0x80019EBC: b           L_80019F08
    // 0x80019EC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80019F08;
    // 0x80019EC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80019EC4:
    // 0x80019EC4: blez        $t0, L_80019EFC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80019EC8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80019EFC;
    }
    // 0x80019EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80019ECC:
    // 0x80019ECC: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80019ED0: addu        $a0, $s1, $t7
    ctx->r4 = ADD32(ctx->r17, ctx->r15);
    // 0x80019ED4: lbu         $t9, 0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4);
    // 0x80019ED8: bnel        $v0, $t9, L_80019EEC
    if (ctx->r2 != ctx->r25) {
        // 0x80019EDC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80019EEC;
    }
    goto skip_10;
    // 0x80019EDC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_10:
    // 0x80019EE0: sb          $s4, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r20;
    // 0x80019EE4: andi        $a1, $t1, 0xFF
    ctx->r5 = ctx->r9 & 0XFF;
    // 0x80019EE8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80019EEC:
    // 0x80019EEC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80019EF0: slt         $at, $t6, $t0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80019EF4: bne         $at, $zero, L_80019ECC
    if (ctx->r1 != 0) {
        // 0x80019EF8: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_80019ECC;
    }
    // 0x80019EF8: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_80019EFC:
    // 0x80019EFC: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80019F00: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x80019F04: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_80019F08:
    // 0x80019F08: bne         $fp, $v1, L_80019FD8
    if (ctx->r30 != ctx->r3) {
        // 0x80019F0C: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_80019FD8;
    }
    // 0x80019F0C: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x80019F10: blez        $t0, L_80019FCC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80019F14: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80019FCC;
    }
    // 0x80019F14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80019F18:
    // 0x80019F18: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80019F1C: addu        $a0, $s1, $t7
    ctx->r4 = ADD32(ctx->r17, ctx->r15);
    // 0x80019F20: lbu         $a3, 0x4($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0X4);
    // 0x80019F24: beq         $s7, $a3, L_80019FB8
    if (ctx->r23 == ctx->r7) {
        // 0x80019F28: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_80019FB8;
    }
    // 0x80019F28: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80019F2C: multu       $a3, $s6
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80019F30: sll         $t9, $s5, 4
    ctx->r25 = S32(ctx->r21 << 4);
    // 0x80019F34: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x80019F38: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80019F3C: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x80019F40: mflo        $t8
    ctx->r24 = lo;
    // 0x80019F44: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80019F48: lbu         $t9, 0x28($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X28);
    // 0x80019F4C: beql        $t4, $t9, L_80019FBC
    if (ctx->r12 == ctx->r25) {
        // 0x80019F50: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80019FBC;
    }
    goto skip_11;
    // 0x80019F50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_11:
    // 0x80019F54: blez        $t0, L_80019F90
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80019F58: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80019F90;
    }
    // 0x80019F58: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80019F5C:
    // 0x80019F5C: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x80019F60: addu        $t8, $a2, $t6
    ctx->r24 = ADD32(ctx->r6, ctx->r14);
    // 0x80019F64: lbu         $t7, 0x4($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X4);
    // 0x80019F68: bnel        $v0, $t7, L_80019F7C
    if (ctx->r2 != ctx->r15) {
        // 0x80019F6C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80019F7C;
    }
    goto skip_12;
    // 0x80019F6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_12:
    // 0x80019F70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019F74: andi        $s0, $t1, 0xFF
    ctx->r16 = ctx->r9 & 0XFF;
    // 0x80019F78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80019F7C:
    // 0x80019F7C: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x80019F80: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80019F84: bne         $at, $zero, L_80019F5C
    if (ctx->r1 != 0) {
        // 0x80019F88: or          $s0, $t9, $zero
        ctx->r16 = ctx->r25 | 0;
            goto L_80019F5C;
    }
    // 0x80019F88: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x80019F8C: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
L_80019F90:
    // 0x80019F90: bnel        $fp, $t2, L_80019FBC
    if (ctx->r30 != ctx->r10) {
        // 0x80019F94: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80019FBC;
    }
    goto skip_13;
    // 0x80019F94: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_13:
    // 0x80019F98: addiu       $a1, $t0, 0x1
    ctx->r5 = ADD32(ctx->r8, 0X1);
    // 0x80019F9C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80019FA0: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80019FA4: andi        $t8, $s2, 0xFF
    ctx->r24 = ctx->r18 & 0XFF;
    // 0x80019FA8: sb          $a3, 0x4($s3)
    MEM_B(0X4, ctx->r19) = ctx->r7;
    // 0x80019FAC: sb          $s4, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r20;
    // 0x80019FB0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80019FB4: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
L_80019FB8:
    // 0x80019FB8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80019FBC:
    // 0x80019FBC: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x80019FC0: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80019FC4: bne         $at, $zero, L_80019F18
    if (ctx->r1 != 0) {
        // 0x80019FC8: or          $a1, $t7, $zero
        ctx->r5 = ctx->r15 | 0;
            goto L_80019F18;
    }
    // 0x80019FC8: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_80019FCC:
    // 0x80019FCC: bnel        $t0, $a1, L_80019FDC
    if (ctx->r8 != ctx->r5) {
        // 0x80019FD0: addiu       $t3, $t3, 0x1
        ctx->r11 = ADD32(ctx->r11, 0X1);
            goto L_80019FDC;
    }
    goto skip_14;
    // 0x80019FD0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    skip_14:
    // 0x80019FD4: sb          $s4, 0x4($s3)
    MEM_B(0X4, ctx->r19) = ctx->r20;
L_80019FD8:
    // 0x80019FD8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
L_80019FDC:
    // 0x80019FDC: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x80019FE0: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80019FE4: bne         $at, $zero, L_80019E08
    if (ctx->r1 != 0) {
        // 0x80019FE8: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_80019E08;
    }
    // 0x80019FE8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
L_80019FEC:
    // 0x80019FEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80019FF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80019FF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80019FF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80019FFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001A000: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001A004: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001A008: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001A00C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001A010: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001A014: jr          $ra
    // 0x8001A018: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8001A018: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void Audio_UpdateSfxVolumeMod(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AA90: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8001AA94: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x8001AA98: addiu       $t8, $t8, -0x6578
    ctx->r24 = ADD32(ctx->r24, -0X6578);
    // 0x8001AA9C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8001AAA0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8001AAA4: lhu         $v1, 0xC($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC);
    // 0x8001AAA8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8001AAAC: beq         $v1, $zero, L_8001AADC
    if (ctx->r3 == 0) {
        // 0x8001AAB0: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_8001AADC;
    }
    // 0x8001AAB0: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x8001AAB4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8001AAB8: beq         $t0, $zero, L_8001AAD4
    if (ctx->r8 == 0) {
        // 0x8001AABC: sh          $t9, 0xC($v0)
        MEM_H(0XC, ctx->r2) = ctx->r25;
            goto L_8001AAD4;
    }
    // 0x8001AABC: sh          $t9, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r25;
    // 0x8001AAC0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8001AAC4: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8001AAC8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001AACC: jr          $ra
    // 0x8001AAD0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x8001AAD0: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_8001AAD4:
    // 0x8001AAD4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8001AAD8: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
L_8001AADC:
    // 0x8001AADC: jr          $ra
    // 0x8001AAE0: nop

    return;
    // 0x8001AAE0: nop

;}
RECOMP_FUNC void BoBaseShield_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E628: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002E62C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E630: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E634: jal         0x80187520
    // 0x8002E638: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    LOOKUP_FUNC(0x80187520)(rdram, ctx);
        goto after_0;
    // 0x8002E638: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_0:
    // 0x8002E63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E640: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002E644: jr          $ra
    // 0x8002E648: nop

    return;
    // 0x8002E648: nop

;}
RECOMP_FUNC void Audio_PlaySfxModulated(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D10C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8001D110: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001D114: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x8001D118: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x8001D11C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8001D120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D124: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8001D128: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8001D12C: addiu       $t6, $t6, 0x5E78
    ctx->r14 = ADD32(ctx->r14, 0X5E78);
    // 0x8001D130: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x8001D134: addiu       $a3, $a3, 0x5E74
    ctx->r7 = ADD32(ctx->r7, 0X5E74);
    // 0x8001D138: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8001D13C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8001D140: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8001D144: jal         0x80019218
    // 0x8001D148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x8001D148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8001D14C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D150: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8001D154: jr          $ra
    // 0x8001D158: nop

    return;
    // 0x8001D158: nop

;}
RECOMP_FUNC void HUD_RadarMark_Boss_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800897B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800897B4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800897B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800897BC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x800897C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800897C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800897C8: jal         0x800B8DD0
    // 0x800897CC: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x800897CC: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_0:
    // 0x800897D0: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x800897D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800897D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800897DC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800897E0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800897E4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800897E8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800897EC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800897F0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800897F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800897F8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800897FC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80089800: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089804: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80089808: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8008980C: jal         0x80005C34
    // 0x80089810: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80089810: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80089814: jal         0x80006EB8
    // 0x80089818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80089818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8008981C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80089820: lui         $t2, 0x102
    ctx->r10 = S32(0X102 << 16);
    // 0x80089824: addiu       $t2, $t2, 0x4830
    ctx->r10 = ADD32(ctx->r10, 0X4830);
    // 0x80089828: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x8008982C: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80089830: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x80089834: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80089838: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8008983C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80089840: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80089844: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80089848: jr          $ra
    // 0x8008984C: nop

    return;
    // 0x8008984C: nop

;}
RECOMP_FUNC void Graphics_Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800999D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800999DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800999E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800999E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800999E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800999EC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800999F0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x800999F4: addiu       $a0, $a0, 0x19A0
    ctx->r4 = ADD32(ctx->r4, 0X19A0);
    // 0x800999F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800999FC: jal         0x80099980
    // 0x80099A00: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    Graphics_ClearPrintBuffer(rdram, ctx);
        goto after_0;
    // 0x80099A00: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_0:
    // 0x80099A04: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80099A08: addiu       $a0, $a0, 0x19A0
    ctx->r4 = ADD32(ctx->r4, 0X19A0);
    // 0x80099A0C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80099A10: jal         0x80002E80
    // 0x80099A14: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    Lib_vsPrintf(rdram, ctx);
        goto after_1;
    // 0x80099A14: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80099A18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80099A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099A20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80099A24: jr          $ra
    // 0x80099A28: nop

    return;
    // 0x80099A28: nop

;}
RECOMP_FUNC void Player_SetupOnFootShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ACDC0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800ACDC4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800ACDC8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800ACDCC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800ACDD0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800ACDD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800ACDD8: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800ACDDC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800ACDE0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800ACDE4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800ACDE8: jal         0x80035E48
    // 0x800ACDEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    PlayerShot_Initialize(rdram, ctx);
        goto after_0;
    // 0x800ACDEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x800ACDF0: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800ACDF4: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800ACDF8: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800ACDFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800ACE00: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACE04: lwc1        $f20, -0x79C0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X79C0);
    // 0x800ACE08: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800ACE0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ACE10: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ACE14: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x800ACE18: addiu       $s1, $s1, -0x4438
    ctx->r17 = ADD32(ctx->r17, -0X4438);
    // 0x800ACE1C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACE20: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ACE24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800ACE28: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800ACE2C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800ACE30: jal         0x80005E90
    // 0x800ACE34: nop

    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x800ACE34: nop

    after_1:
    // 0x800ACE38: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800ACE3C: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800ACE40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACE44: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800ACE48: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ACE4C: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800ACE50: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800ACE54: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800ACE58: jal         0x80005D44
    // 0x800ACE5C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x800ACE5C: nop

    after_2:
    // 0x800ACE60: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800ACE64: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800ACE68: lwc1        $f16, 0x134($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800ACE6C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACE70: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800ACE74: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800ACE78: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ACE7C: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800ACE80: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800ACE84: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800ACE88: jal         0x80005FE0
    // 0x800ACE8C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x800ACE8C: nop

    after_3:
    // 0x800ACE90: lwc1        $f8, 0x154($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X154);
    // 0x800ACE94: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACE98: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800ACE9C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800ACEA0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800ACEA4: jal         0x80005D44
    // 0x800ACEA8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x800ACEA8: nop

    after_4:
    // 0x800ACEAC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800ACEB0: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800ACEB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800ACEB8: swc1        $f22, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f22.u32l;
    // 0x800ACEBC: bne         $t6, $at, L_800ACED4
    if (ctx->r14 != ctx->r1) {
        // 0x800ACEC0: swc1        $f22, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->f22.u32l;
            goto L_800ACED4;
    }
    // 0x800ACEC0: swc1        $f22, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f22.u32l;
    // 0x800ACEC4: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800ACEC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800ACECC: b           L_800ACEE4
    // 0x800ACED0: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
        goto L_800ACEE4;
    // 0x800ACED0: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
L_800ACED4:
    // 0x800ACED4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x800ACED8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ACEDC: nop

    // 0x800ACEE0: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_800ACEE4:
    // 0x800ACEE4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACEE8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800ACEEC: jal         0x80006A20
    // 0x800ACEF0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_5;
    // 0x800ACEF0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    after_5:
    // 0x800ACEF4: lwc1        $f4, 0x114($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800ACEF8: lwc1        $f6, 0xE8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800ACEFC: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800ACF00: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800ACF04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800ACF08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800ACF0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACF10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800ACF14: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ACF18: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800ACF1C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800ACF20: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800ACF24: jal         0x80005E90
    // 0x800ACF28: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x800ACF28: nop

    after_6:
    // 0x800ACF2C: lwc1        $f8, 0xE4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800ACF30: lwc1        $f10, 0x134($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800ACF34: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACF38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800ACF3C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ACF40: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800ACF44: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x800ACF48: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800ACF4C: jal         0x80005D44
    // 0x800ACF50: nop

    Matrix_RotateX(rdram, ctx);
        goto after_7;
    // 0x800ACF50: nop

    after_7:
    // 0x800ACF54: lwc1        $f6, 0xF8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x800ACF58: lwc1        $f8, 0xF0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XF0);
    // 0x800ACF5C: lwc1        $f16, 0x134($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800ACF60: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACF64: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800ACF68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800ACF6C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800ACF70: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x800ACF74: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800ACF78: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800ACF7C: jal         0x80005FE0
    // 0x800ACF80: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_8;
    // 0x800ACF80: nop

    after_8:
    // 0x800ACF84: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800ACF88: lw          $a2, 0x80($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X80);
    // 0x800ACF8C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800ACF90: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800ACF94: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACF98: jal         0x80005B00
    // 0x800ACF9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_9;
    // 0x800ACF9C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_9:
    // 0x800ACFA0: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800ACFA4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800ACFA8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800ACFAC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACFB0: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x800ACFB4: jal         0x80005B00
    // 0x800ACFB8: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x800ACFB8: lui         $a2, 0x41C8
    ctx->r6 = S32(0X41C8 << 16);
    after_10:
    // 0x800ACFBC: lwc1        $f8, 0x154($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X154);
    // 0x800ACFC0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACFC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800ACFC8: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800ACFCC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800ACFD0: jal         0x80005D44
    // 0x800ACFD4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_11;
    // 0x800ACFD4: nop

    after_11:
    // 0x800ACFD8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800ACFDC: swc1        $f22, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f22.u32l;
    // 0x800ACFE0: swc1        $f22, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f22.u32l;
    // 0x800ACFE4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800ACFE8: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800ACFEC: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    // 0x800ACFF0: jal         0x80006970
    // 0x800ACFF4: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    Matrix_MultVec3f(rdram, ctx);
        goto after_12;
    // 0x800ACFF4: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x800ACFF8: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800ACFFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AD000: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800AD004: swc1        $f18, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f18.u32l;
    // 0x800AD008: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800AD00C: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x800AD010: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800AD014: swc1        $f4, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f4.u32l;
    // 0x800AD018: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800AD01C: swc1        $f6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f6.u32l;
    // 0x800AD020: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800AD024: lwc1        $f8, 0x74($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800AD028: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AD02C: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x800AD030: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800AD034: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800AD038: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800AD03C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AD040: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
    // 0x800AD044: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800AD048: lwc1        $f8, 0x138($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800AD04C: sb          $t9, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r25;
    // 0x800AD050: swc1        $f18, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f18.u32l;
    // 0x800AD054: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800AD058: swc1        $f16, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f16.u32l;
    // 0x800AD05C: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800AD060: sw          $t1, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r9;
    // 0x800AD064: sw          $t2, 0x58($s2)
    MEM_W(0X58, ctx->r18) = ctx->r10;
    // 0x800AD068: sh          $t0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r8;
    // 0x800AD06C: lw          $t3, 0x1C4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X1C4);
    // 0x800AD070: sw          $t3, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r11;
    // 0x800AD074: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AD078: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800AD07C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800AD080: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800AD084: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800AD088: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800AD08C: jr          $ra
    // 0x800AD090: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AD090: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Effect_Effect395_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081C5C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80081C60: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80081C64: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80081C68: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80081C6C: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80081C70: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80081C74: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80081C78: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80081C7C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80081C80: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80081C84: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80081C88: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x80081C8C: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
    // 0x80081C90: beq         $v1, $zero, L_80081CAC
    if (ctx->r3 == 0) {
        // 0x80081C94: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_80081CAC;
    }
    // 0x80081C94: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80081C98: beq         $v1, $at, L_80081CAC
    if (ctx->r3 == ctx->r1) {
        // 0x80081C9C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80081CAC;
    }
    // 0x80081C9C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80081CA0: beq         $v1, $at, L_80081CAC
    if (ctx->r3 == ctx->r1) {
        // 0x80081CA4: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80081CAC;
    }
    // 0x80081CA4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80081CA8: beq         $v1, $at, L_80081CAC
    if (ctx->r3 == ctx->r1) {
        // 0x80081CAC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80081CAC;
    }
L_80081CAC:
    // 0x80081CAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80081CB0: beq         $v1, $at, L_80081CD0
    if (ctx->r3 == ctx->r1) {
        // 0x80081CB4: addiu       $a0, $a0, -0x7DCC
        ctx->r4 = ADD32(ctx->r4, -0X7DCC);
            goto L_80081CD0;
    }
    // 0x80081CB4: addiu       $a0, $a0, -0x7DCC
    ctx->r4 = ADD32(ctx->r4, -0X7DCC);
    // 0x80081CB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80081CBC: beq         $v1, $at, L_80081CD0
    if (ctx->r3 == ctx->r1) {
        // 0x80081CC0: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80081CD0;
    }
    // 0x80081CC0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80081CC4: beq         $v1, $at, L_80081CD0
    if (ctx->r3 == ctx->r1) {
        // 0x80081CC8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80081CD0;
    }
    // 0x80081CC8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80081CCC: beq         $v1, $at, L_80081CD0
    if (ctx->r3 == ctx->r1) {
        // 0x80081CD0: sltiu       $at, $v1, 0xD
        ctx->r1 = ctx->r3 < 0XD ? 1 : 0;
            goto L_80081CD0;
    }
L_80081CD0:
    // 0x80081CD0: sltiu       $at, $v1, 0xD
    ctx->r1 = ctx->r3 < 0XD ? 1 : 0;
    // 0x80081CD4: beq         $at, $zero, L_80082F18
    if (ctx->r1 == 0) {
        // 0x80081CD8: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_80082F18;
    }
    // 0x80081CD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80081CDC: addu        $at, $at, $t6
    gpr jr_addend_80081CE4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80081CE0: lw          $t6, 0x75A8($at)
    ctx->r14 = ADD32(ctx->r1, 0X75A8);
    // 0x80081CE4: jr          $t6
    // 0x80081CE8: nop

    switch (jr_addend_80081CE4 >> 2) {
        case 0: goto L_80081CEC; break;
        case 1: goto L_80081E14; break;
        case 2: goto L_80081F20; break;
        case 3: goto L_8008213C; break;
        case 4: goto L_800821DC; break;
        case 5: goto L_80082244; break;
        case 6: goto L_800822DC; break;
        case 7: goto L_8008233C; break;
        case 8: goto L_800824D8; break;
        case 9: goto L_80082814; break;
        case 10: goto L_800829C4; break;
        case 11: goto L_80082E64; break;
        case 12: goto L_80082F0C; break;
        default: switch_error(__func__, 0x80081CE4, 0x800D75A8);
    }
    // 0x80081CE8: nop

L_80081CEC:
    // 0x80081CEC: lhu         $t7, 0x50($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X50);
    // 0x80081CF0: bne         $t7, $zero, L_80081D08
    if (ctx->r15 != 0) {
        // 0x80081CF4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80081D08;
    }
    // 0x80081CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80081CF8: jal         0x80060FBC
    // 0x80081CFC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_0;
    // 0x80081CFC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_0:
    // 0x80081D00: b           L_80082F18
    // 0x80081D04: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80081D04: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80081D08:
    // 0x80081D08: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80081D0C: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80081D10: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80081D14: bnel        $t9, $zero, L_80081DC0
    if (ctx->r25 != 0) {
        // 0x80081D18: lw          $a0, 0x40($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X40);
            goto L_80081DC0;
    }
    goto skip_0;
    // 0x80081D18: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    skip_0:
    // 0x80081D1C: jal         0x80004EB0
    // 0x80081D20: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x80081D20: nop

    after_1:
    // 0x80081D24: jal         0x80004EB0
    // 0x80081D28: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x80081D28: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80081D2C: jal         0x80004EB0
    // 0x80081D30: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x80081D30: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80081D34: jal         0x80004EB0
    // 0x80081D38: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x80081D38: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x80081D3C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80081D40: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80081D44: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80081D48: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081D4C: lwc1        $f10, 0x40($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80081D50: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80081D54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80081D58: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80081D5C: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80081D60: lwc1        $f18, 0x75DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X75DC);
    // 0x80081D64: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80081D68: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80081D6C: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80081D70: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80081D74: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80081D78: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80081D7C: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80081D80: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80081D84: add.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80081D88: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80081D8C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80081D90: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80081D94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80081D98: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80081D9C: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80081DA0: lwc1        $f6, 0x5C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80081DA4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80081DA8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80081DAC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80081DB0: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80081DB4: jal         0x8007C484
    // 0x80081DB8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Effect_ElectricArc_Spawn(rdram, ctx);
        goto after_5;
    // 0x80081DB8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80081DBC: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
L_80081DC0:
    // 0x80081DC0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80081DC4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80081DC8: jal         0x8006351C
    // 0x80081DCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_6;
    // 0x80081DCC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_6:
    // 0x80081DD0: beq         $v0, $zero, L_80081DFC
    if (ctx->r2 == 0) {
        // 0x80081DD4: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_80081DFC;
    }
    // 0x80081DD4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x80081DD8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80081DDC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80081DE0: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80081DE4: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x80081DE8: jal         0x8007B344
    // 0x80081DEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_7;
    // 0x80081DEC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_7:
    // 0x80081DF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80081DF4: jal         0x80060FBC
    // 0x80081DF8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_8;
    // 0x80081DF8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_8:
L_80081DFC:
    // 0x80081DFC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80081E00: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081E04: nop

    // 0x80081E08: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x80081E0C: b           L_80082F18
    // 0x80081E10: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80081E10: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80081E14:
    // 0x80081E14: lhu         $t1, 0x50($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X50);
    // 0x80081E18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80081E1C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80081E20: bnel        $t1, $zero, L_80081E3C
    if (ctx->r9 != 0) {
        // 0x80081E24: lwc1        $f6, 0x68($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
            goto L_80081E3C;
    }
    goto skip_1;
    // 0x80081E24: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    skip_1:
    // 0x80081E28: jal         0x80060FBC
    // 0x80081E2C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_9;
    // 0x80081E2C: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_9:
    // 0x80081E30: b           L_80082F18
    // 0x80081E34: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80081E34: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
    // 0x80081E38: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
L_80081E3C:
    // 0x80081E3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80081E40: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80081E44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80081E48: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80081E4C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80081E50: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
    // 0x80081E54: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80081E58: swc1        $f10, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f10.u32l;
    // 0x80081E5C: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x80081E60: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80081E64: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80081E68: andi        $t3, $t2, 0x7
    ctx->r11 = ctx->r10 & 0X7;
    // 0x80081E6C: bne         $t3, $zero, L_80081E8C
    if (ctx->r11 != 0) {
        // 0x80081E70: addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
            goto L_80081E8C;
    }
    // 0x80081E70: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80081E74: lh          $t4, 0x44($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X44);
    // 0x80081E78: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80081E7C: sh          $t5, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r13;
    // 0x80081E80: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x80081E84: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80081E88: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
L_80081E8C:
    // 0x80081E8C: lh          $t8, 0x44($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X44);
    // 0x80081E90: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80081E94: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80081E98: bne         $t8, $zero, L_80081EC8
    if (ctx->r24 != 0) {
        // 0x80081E9C: lui         $a3, 0x3CA3
        ctx->r7 = S32(0X3CA3 << 16);
            goto L_80081EC8;
    }
    // 0x80081E9C: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x80081EA0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80081EA4: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80081EA8: lui         $a3, 0x3CA3
    ctx->r7 = S32(0X3CA3 << 16);
    // 0x80081EAC: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80081EB0: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80081EB4: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80081EB8: jal         0x8009BC2C
    // 0x80081EBC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x80081EBC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x80081EC0: b           L_80081EE4
    // 0x80081EC4: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
        goto L_80081EE4;
    // 0x80081EC4: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
L_80081EC8:
    // 0x80081EC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80081ECC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80081ED0: ori         $a3, $a3, 0xD70A
    ctx->r7 = ctx->r7 | 0XD70A;
    // 0x80081ED4: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80081ED8: jal         0x8009BC2C
    // 0x80081EDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80081EDC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x80081EE0: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
L_80081EE4:
    // 0x80081EE4: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x80081EE8: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x80081EEC: jal         0x8006351C
    // 0x80081EF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_12;
    // 0x80081EF0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x80081EF4: beq         $v0, $zero, L_80081F18
    if (ctx->r2 == 0) {
        // 0x80081EF8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80081F18;
    }
    // 0x80081EF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80081EFC: jal         0x80060FBC
    // 0x80081F00: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_13;
    // 0x80081F00: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_13:
    // 0x80081F04: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80081F08: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80081F0C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80081F10: jal         0x8007D0E0
    // 0x80081F14: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_14;
    // 0x80081F14: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_14:
L_80081F18:
    // 0x80081F18: b           L_80082F18
    // 0x80081F1C: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80081F1C: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80081F20:
    // 0x80081F20: lhu         $t9, 0x50($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X50);
    // 0x80081F24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80081F28: bnel        $t9, $zero, L_80081F44
    if (ctx->r25 != 0) {
        // 0x80081F2C: lh          $v0, 0x44($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X44);
            goto L_80081F44;
    }
    goto skip_2;
    // 0x80081F2C: lh          $v0, 0x44($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X44);
    skip_2:
    // 0x80081F30: jal         0x80060FBC
    // 0x80081F34: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_15;
    // 0x80081F34: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_15:
    // 0x80081F38: b           L_80082F18
    // 0x80081F3C: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80081F3C: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
    // 0x80081F40: lh          $v0, 0x44($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X44);
L_80081F44:
    // 0x80081F44: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80081F48: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80081F4C: beq         $v0, $zero, L_80081F78
    if (ctx->r2 == 0) {
        // 0x80081F50: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_80081F78;
    }
    // 0x80081F50: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80081F54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80081F58: beq         $v0, $at, L_80082004
    if (ctx->r2 == ctx->r1) {
        // 0x80081F5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80082004;
    }
    // 0x80081F5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80081F60: beq         $v0, $at, L_80082004
    if (ctx->r2 == ctx->r1) {
        // 0x80081F64: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80082004;
    }
    // 0x80081F64: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80081F68: beq         $v0, $at, L_80081FBC
    if (ctx->r2 == ctx->r1) {
        // 0x80081F6C: addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
            goto L_80081FBC;
    }
    // 0x80081F6C: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80081F70: b           L_80082004
    // 0x80081F74: nop

        goto L_80082004;
    // 0x80081F74: nop

L_80081F78:
    // 0x80081F78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80081F7C: lwc1        $f10, 0x75E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X75E0);
    // 0x80081F80: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80081F84: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80081F88: jal         0x8009BC2C
    // 0x80081F8C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_16;
    // 0x80081F8C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x80081F90: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80081F94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80081F98: lwc1        $f4, 0x70($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80081F9C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80081FA0: nop

    // 0x80081FA4: bc1f        L_80082004
    if (!c1cs) {
        // 0x80081FA8: nop
    
            goto L_80082004;
    }
    // 0x80081FA8: nop

    // 0x80081FAC: lh          $t0, 0x44($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X44);
    // 0x80081FB0: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80081FB4: b           L_80082004
    // 0x80081FB8: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
        goto L_80082004;
    // 0x80081FB8: sh          $t1, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r9;
L_80081FBC:
    // 0x80081FBC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80081FC0: lwc1        $f8, 0x75E4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75E4);
    // 0x80081FC4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80081FC8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80081FCC: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80081FD0: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x80081FD4: jal         0x8009BC2C
    // 0x80081FD8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_17;
    // 0x80081FD8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_17:
    // 0x80081FDC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80081FE0: lwc1        $f4, 0x75E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X75E8);
    // 0x80081FE4: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80081FE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80081FEC: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80081FF0: nop

    // 0x80081FF4: bc1f        L_80082004
    if (!c1cs) {
        // 0x80081FF8: nop
    
            goto L_80082004;
    }
    // 0x80081FF8: nop

    // 0x80081FFC: jal         0x80060FBC
    // 0x80082000: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_18;
    // 0x80082000: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_18:
L_80082004:
    // 0x80082004: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80082008: lw          $t2, 0x7DB0($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7DB0);
    // 0x8008200C: andi        $t3, $t2, 0x3
    ctx->r11 = ctx->r10 & 0X3;
    // 0x80082010: bnel        $t3, $zero, L_800820E0
    if (ctx->r11 != 0) {
        // 0x80082014: lw          $a0, 0x40($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X40);
            goto L_800820E0;
    }
    goto skip_3;
    // 0x80082014: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    skip_3:
    // 0x80082018: jal         0x80004EB0
    // 0x8008201C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_19;
    // 0x8008201C: nop

    after_19:
    // 0x80082020: jal         0x80004EB0
    // 0x80082024: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_20;
    // 0x80082024: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x80082028: jal         0x80004EB0
    // 0x8008202C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_21;
    // 0x8008202C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_21:
    // 0x80082030: jal         0x80004EB0
    // 0x80082034: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_22;
    // 0x80082034: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x80082038: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8008203C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80082040: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80082044: lwc1        $f2, 0x70($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80082048: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008204C: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80082050: lwc1        $f18, 0x75EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X75EC);
    // 0x80082054: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80082058: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008205C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80082060: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80082064: lw          $a3, 0x54($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X54);
    // 0x80082068: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x8008206C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80082070: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80082074: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80082078: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8008207C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80082080: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80082084: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80082088: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008208C: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80082090: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80082094: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80082098: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8008209C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800820A0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800820A4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800820A8: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800820AC: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800820B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800820B4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800820B8: lwc1        $f8, 0x75F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75F0);
    // 0x800820BC: lwc1        $f6, 0x5C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x800820C0: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800820C4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800820C8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800820CC: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800820D0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800820D4: jal         0x8007C120
    // 0x800820D8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Effect_Effect390_Spawn(rdram, ctx);
        goto after_23;
    // 0x800820D8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_23:
    // 0x800820DC: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
L_800820E0:
    // 0x800820E0: addiu       $a1, $s0, 0x4
    ctx->r5 = ADD32(ctx->r16, 0X4);
    // 0x800820E4: addiu       $a2, $sp, 0x5C
    ctx->r6 = ADD32(ctx->r29, 0X5C);
    // 0x800820E8: jal         0x8006351C
    // 0x800820EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    Object_CheckCollision(rdram, ctx);
        goto after_24;
    // 0x800820EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_24:
    // 0x800820F0: beq         $v0, $zero, L_80082124
    if (ctx->r2 == 0) {
        // 0x800820F4: lui         $a3, 0x4040
        ctx->r7 = S32(0X4040 << 16);
            goto L_80082124;
    }
    // 0x800820F4: lui         $a3, 0x4040
    ctx->r7 = S32(0X4040 << 16);
    // 0x800820F8: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800820FC: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80082100: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80082104: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x80082108: addiu       $t6, $s0, 0x80
    ctx->r14 = ADD32(ctx->r16, 0X80);
    // 0x8008210C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80082110: jal         0x8007B344
    // 0x80082114: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    Effect_Effect384_Spawn(rdram, ctx);
        goto after_25;
    // 0x80082114: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_25:
    // 0x80082118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008211C: jal         0x80060FBC
    // 0x80082120: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    Object_Kill(rdram, ctx);
        goto after_26;
    // 0x80082120: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_26:
L_80082124:
    // 0x80082124: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80082128: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008212C: nop

    // 0x80082130: swc1        $f6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f6.u32l;
    // 0x80082134: b           L_80082F18
    // 0x80082138: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80082138: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_8008213C:
    // 0x8008213C: lh          $t8, 0x44($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X44);
    // 0x80082140: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80082144: sb          $t7, 0x35($s0)
    MEM_B(0X35, ctx->r16) = ctx->r15;
    // 0x80082148: beq         $t8, $zero, L_80082178
    if (ctx->r24 == 0) {
        // 0x8008214C: lui         $t9, 0x8018
        ctx->r25 = S32(0X8018 << 16);
            goto L_80082178;
    }
    // 0x8008214C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80082150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80082154: jal         0x80060FBC
    // 0x80082158: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_27;
    // 0x80082158: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_27:
    // 0x8008215C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80082160: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80082164: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80082168: jal         0x8007D0E0
    // 0x8008216C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    Effect_FireSmoke1_Spawn4(rdram, ctx);
        goto after_28;
    // 0x8008216C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_28:
    // 0x80082170: b           L_800821C8
    // 0x80082174: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
        goto L_800821C8;
    // 0x80082174: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_80082178:
    // 0x80082178: lw          $t9, -0x7D80($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7D80);
    // 0x8008217C: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80082180: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x80082184: lwc1        $f8, 0x138($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X138);
    // 0x80082188: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008218C: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x80082190: sub.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x80082194: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80082198: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8008219C: nop

    // 0x800821A0: bc1fl       L_800821C8
    if (!c1cs) {
        // 0x800821A4: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_800821C8;
    }
    goto skip_4;
    // 0x800821A4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    skip_4:
    // 0x800821A8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800821AC: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800821B0: jal         0x8006F0D8
    // 0x800821B4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    ActorEvent_PinkExplosion_Spawn(rdram, ctx);
        goto after_29;
    // 0x800821B4: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    after_29:
    // 0x800821B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800821BC: jal         0x80060FBC
    // 0x800821C0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_30;
    // 0x800821C0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_30:
    // 0x800821C4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
L_800821C8:
    // 0x800821C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800821CC: nop

    // 0x800821D0: swc1        $f4, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f4.u32l;
    // 0x800821D4: b           L_80082F18
    // 0x800821D8: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x800821D8: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_800821DC:
    // 0x800821DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800821E0: lwc1        $f8, 0x75F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X75F4);
    // 0x800821E4: lwc1        $f6, 0x70($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800821E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800821EC: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800821F0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800821F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800821F8: lh          $t0, 0x4A($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X4A);
    // 0x800821FC: lh          $t1, 0x46($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X46);
    // 0x80082200: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80082204: swc1        $f10, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f10.u32l;
    // 0x80082208: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8008220C: sh          $t2, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r10;
    // 0x80082210: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x80082214: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082218: lwc1        $f4, 0x75F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X75F8);
    // 0x8008221C: lwc1        $f10, 0x58($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80082220: lh          $t3, 0x4A($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4A);
    // 0x80082224: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80082228: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8008222C: bgez        $t3, L_8008223C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80082230: swc1        $f6, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
            goto L_8008223C;
    }
    // 0x80082230: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x80082234: jal         0x80060FBC
    // 0x80082238: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_31;
    // 0x80082238: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_31:
L_8008223C:
    // 0x8008223C: b           L_80082F18
    // 0x80082240: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80082240: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80082244:
    // 0x80082244: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80082248: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8008224C: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80082250: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80082254: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80082258: jal         0x80081A8C
    // 0x8008225C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    func_effect_80081A8C(rdram, ctx);
        goto after_32;
    // 0x8008225C: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    after_32:
    // 0x80082260: lh          $t8, 0x44($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X44);
    // 0x80082264: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80082268: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8008226C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80082270: lh          $t5, 0x4A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4A);
    // 0x80082274: lh          $t6, 0x46($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X46);
    // 0x80082278: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008227C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80082280: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80082284: sh          $t7, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r15;
    // 0x80082288: lh          $t9, 0x4A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X4A);
    // 0x8008228C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80082290: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80082294: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80082298: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8008229C: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800822A0: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800822A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800822A8: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800822AC: add.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800822B0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800822B4: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x800822B8: bltz        $t9, L_800822CC
    if (SIGNED(ctx->r25) < 0) {
        // 0x800822BC: swc1        $f10, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
            goto L_800822CC;
    }
    // 0x800822BC: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x800822C0: lhu         $t0, 0x50($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X50);
    // 0x800822C4: bne         $t0, $zero, L_800822D4
    if (ctx->r8 != 0) {
        // 0x800822C8: nop
    
            goto L_800822D4;
    }
    // 0x800822C8: nop

L_800822CC:
    // 0x800822CC: jal         0x80060FBC
    // 0x800822D0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_33;
    // 0x800822D0: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_33:
L_800822D4:
    // 0x800822D4: b           L_80082F18
    // 0x800822D8: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x800822D8: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_800822DC:
    // 0x800822DC: lh          $t1, 0x4A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X4A);
    // 0x800822E0: lh          $t2, 0x46($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X46);
    // 0x800822E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800822E8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800822EC: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x800822F0: sh          $t3, 0x4A($s0)
    MEM_H(0X4A, ctx->r16) = ctx->r11;
    // 0x800822F4: lwc1        $f4, 0x75FC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X75FC);
    // 0x800822F8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800822FC: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80082300: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80082304: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80082308: jal         0x8009BC2C
    // 0x8008230C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_34;
    // 0x8008230C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_34:
    // 0x80082310: lh          $t4, 0x4A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4A);
    // 0x80082314: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80082318: bltz        $t4, L_8008232C
    if (SIGNED(ctx->r12) < 0) {
        // 0x8008231C: nop
    
            goto L_8008232C;
    }
    // 0x8008231C: nop

    // 0x80082320: lhu         $t5, 0x50($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X50);
    // 0x80082324: bne         $t5, $zero, L_80082334
    if (ctx->r13 != 0) {
        // 0x80082328: nop
    
            goto L_80082334;
    }
    // 0x80082328: nop

L_8008232C:
    // 0x8008232C: jal         0x80060FBC
    // 0x80082330: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_35;
    // 0x80082330: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_35:
L_80082334:
    // 0x80082334: b           L_80082F18
    // 0x80082338: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80082338: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_8008233C:
    // 0x8008233C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80082340: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80082344: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x80082348: beq         $v0, $at, L_80082400
    if (ctx->r2 == ctx->r1) {
        // 0x8008234C: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_80082400;
    }
    // 0x8008234C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80082350: bne         $v0, $at, L_80082F18
    if (ctx->r2 != ctx->r1) {
        // 0x80082354: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_80082F18;
    }
    // 0x80082354: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80082358: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8008235C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80082360: andi        $t7, $t6, 0x3
    ctx->r15 = ctx->r14 & 0X3;
    // 0x80082364: bnel        $t7, $zero, L_80082388
    if (ctx->r15 != 0) {
        // 0x80082368: lwc1        $f6, 0x10($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80082388;
    }
    goto skip_5;
    // 0x80082368: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    skip_5:
    // 0x8008236C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80082370: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80082374: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80082378: lw          $a3, 0x70($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X70);
    // 0x8008237C: jal         0x80081A8C
    // 0x80082380: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_effect_80081A8C(rdram, ctx);
        goto after_36;
    // 0x80082380: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_36:
    // 0x80082384: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
L_80082388:
    // 0x80082388: lwc1        $f8, 0x60($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8008238C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80082390: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80082394: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80082398: lwc1        $f6, 0x64($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8008239C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800823A0: lhu         $t9, 0x50($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X50);
    // 0x800823A4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800823A8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x800823AC: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800823B0: lwc1        $f4, 0x68($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800823B4: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800823B8: lwc1        $f8, 0x58($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800823BC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800823C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800823C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800823C8: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800823CC: swc1        $f6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f6.u32l;
    // 0x800823D0: beq         $t9, $zero, L_800823F0
    if (ctx->r25 == 0) {
        // 0x800823D4: swc1        $f10, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
            goto L_800823F0;
    }
    // 0x800823D4: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x800823D8: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800823DC: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800823E0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800823E4: nop

    // 0x800823E8: bc1f        L_800823F8
    if (!c1cs) {
        // 0x800823EC: nop
    
            goto L_800823F8;
    }
    // 0x800823EC: nop

L_800823F0:
    // 0x800823F0: jal         0x80060FBC
    // 0x800823F4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_37;
    // 0x800823F4: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_37:
L_800823F8:
    // 0x800823F8: b           L_80082F18
    // 0x800823FC: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x800823FC: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80082400:
    // 0x80082400: lw          $t0, 0x7DB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7DB0);
    // 0x80082404: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80082408: andi        $t1, $t0, 0x3
    ctx->r9 = ctx->r8 & 0X3;
    // 0x8008240C: bnel        $t1, $zero, L_80082444
    if (ctx->r9 != 0) {
        // 0x80082410: lwc1        $f18, 0x10($s0)
        ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
            goto L_80082444;
    }
    goto skip_6;
    // 0x80082410: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    skip_6:
    // 0x80082414: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x80082418: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8008241C: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80082420: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80082424: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80082428: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8008242C: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80082430: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80082434: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80082438: jal         0x80081A8C
    // 0x8008243C: nop

    func_effect_80081A8C(rdram, ctx);
        goto after_38;
    // 0x8008243C: nop

    after_38:
    // 0x80082440: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
L_80082444:
    // 0x80082444: lwc1        $f16, 0x60($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80082448: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8008244C: lwc1        $f12, 0x64($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80082450: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80082454: lwc1        $f18, 0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80082458: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8008245C: add.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x80082460: lwc1        $f14, 0x58($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80082464: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80082468: add.s       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8008246C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80082470: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80082474: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    // 0x80082478: swc1        $f12, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f12.u32l;
    // 0x8008247C: sub.s       $f18, $f14, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80082480: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x80082484: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x80082488: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8008248C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80082490: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80082494: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80082498: jal         0x800A73E4
    // 0x8008249C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Play_CheckDynaFloorCollision(rdram, ctx);
        goto after_39;
    // 0x8008249C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_39:
    // 0x800824A0: bne         $v0, $zero, L_800824B4
    if (ctx->r2 != 0) {
        // 0x800824A4: lwc1        $f14, 0x6C($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
            goto L_800824B4;
    }
    // 0x800824A4: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800824A8: lhu         $t3, 0x50($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X50);
    // 0x800824AC: bne         $t3, $zero, L_800824D0
    if (ctx->r11 != 0) {
        // 0x800824B0: nop
    
            goto L_800824D0;
    }
    // 0x800824B0: nop

L_800824B4:
    // 0x800824B4: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800824B8: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800824BC: jal         0x8007B228
    // 0x800824C0: lw          $a3, 0x70($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X70);
    Effect_Effect381_Spawn(rdram, ctx);
        goto after_40;
    // 0x800824C0: lw          $a3, 0x70($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X70);
    after_40:
    // 0x800824C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800824C8: jal         0x80060FBC
    // 0x800824CC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_41;
    // 0x800824CC: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_41:
L_800824D0:
    // 0x800824D0: b           L_80082F18
    // 0x800824D4: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x800824D4: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_800824D8:
    // 0x800824D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800824DC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800824E0: addiu       $a0, $a0, 0x79A8
    ctx->r4 = ADD32(ctx->r4, 0X79A8);
    // 0x800824E4: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x800824E8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800824EC: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x800824F0: jal         0x8009BC2C
    // 0x800824F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_42;
    // 0x800824F4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_42:
    // 0x800824F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800824FC: lwc1        $f10, -0xEDC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XEDC);
    // 0x80082500: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082504: lwc1        $f4, 0x7600($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7600);
    // 0x80082508: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8008250C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80082510: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80082514: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082518: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8008251C: jal         0x80005E90
    // 0x80082520: nop

    Matrix_RotateY(rdram, ctx);
        goto after_43;
    // 0x80082520: nop

    after_43:
    // 0x80082524: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80082528: lwc1        $f8, -0xEE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XEE0);
    // 0x8008252C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082530: lwc1        $f10, 0x7604($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7604);
    // 0x80082534: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80082538: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x8008253C: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80082540: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80082544: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80082548: jal         0x80005D44
    // 0x8008254C: nop

    Matrix_RotateX(rdram, ctx);
        goto after_44;
    // 0x8008254C: nop

    after_44:
    // 0x80082550: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80082554: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80082558: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008255C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082560: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x80082564: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x80082568: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8008256C: lh          $t4, 0x44($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X44);
    // 0x80082570: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80082574: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80082578: blez        $t4, L_80082590
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8008257C: addiu       $a2, $sp, 0x50
        ctx->r6 = ADD32(ctx->r29, 0X50);
            goto L_80082590;
    }
    // 0x8008257C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80082580: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80082584: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80082588: nop

    // 0x8008258C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_80082590:
    // 0x80082590: jal         0x80006A20
    // 0x80082594: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_45;
    // 0x80082594: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_45:
    // 0x80082598: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8008259C: addiu       $v1, $v1, -0xEF0
    ctx->r3 = ADD32(ctx->r3, -0XEF0);
    // 0x800825A0: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800825A4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800825A8: lh          $v0, 0x44($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X44);
    // 0x800825AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800825B0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800825B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800825B8: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x800825BC: swc1        $f10, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f10.u32l;
    // 0x800825C0: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800825C4: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800825C8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800825CC: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800825D0: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800825D4: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800825D8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800825DC: beq         $v0, $zero, L_80082600
    if (ctx->r2 == 0) {
        // 0x800825E0: swc1        $f6, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
            goto L_80082600;
    }
    // 0x800825E0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800825E4: beq         $v0, $at, L_80082718
    if (ctx->r2 == ctx->r1) {
        // 0x800825E8: addiu       $a0, $s0, 0x70
        ctx->r4 = ADD32(ctx->r16, 0X70);
            goto L_80082718;
    }
    // 0x800825E8: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x800825EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800825F0: beql        $v0, $at, L_80082798
    if (ctx->r2 == ctx->r1) {
        // 0x800825F4: lhu         $t5, 0x50($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X50);
            goto L_80082798;
    }
    goto skip_7;
    // 0x800825F4: lhu         $t5, 0x50($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X50);
    skip_7:
    // 0x800825F8: b           L_8008280C
    // 0x800825FC: nop

        goto L_8008280C;
    // 0x800825FC: nop

L_80082600:
    // 0x80082600: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80082604: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80082608: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x8008260C: jal         0x80081BEC
    // 0x80082610: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    func_effect_80081BEC(rdram, ctx);
        goto after_46;
    // 0x80082610: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_46:
    // 0x80082614: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082618: lwc1        $f18, 0x7608($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7608);
    // 0x8008261C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082620: lwc1        $f8, 0x760C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X760C);
    // 0x80082624: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80082628: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8008262C: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x80082630: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x80082634: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x80082638: jal         0x8009BC2C
    // 0x8008263C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_47;
    // 0x8008263C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_47:
    // 0x80082640: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80082644: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80082648: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x8008264C: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80082650: addiu       $v0, $v0, 0x130
    ctx->r2 = ADD32(ctx->r2, 0X130);
    // 0x80082654: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x80082658: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8008265C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80082660: bc1f        L_8008280C
    if (!c1cs) {
        // 0x80082664: nop
    
            goto L_8008280C;
    }
    // 0x80082664: nop

    // 0x80082668: sb          $zero, 0x3598($v0)
    MEM_B(0X3598, ctx->r2) = 0;
    // 0x8008266C: sb          $zero, 0x3624($v0)
    MEM_B(0X3624, ctx->r2) = 0;
    // 0x80082670: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x80082674: lwc1        $f14, 0x8($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80082678: lwc1        $f12, 0x4($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8008267C: jal         0x80081BEC
    // 0x80082680: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_effect_80081BEC(rdram, ctx);
        goto after_48;
    // 0x80082680: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_48:
    // 0x80082684: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80082688: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008268C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80082690: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80082694: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80082698: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x8008269C: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x800826A0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800826A4: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x800826A8: sw          $a2, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r6;
    // 0x800826AC: addiu       $a1, $a1, -0x7CA8
    ctx->r5 = ADD32(ctx->r5, -0X7CA8);
    // 0x800826B0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x800826B4: addiu       $a3, $a3, -0x7CC0
    ctx->r7 = ADD32(ctx->r7, -0X7CC0);
    // 0x800826B8: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x800826BC: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x800826C0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800826C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x800826C8: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    // 0x800826CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800826D0: sw          $t1, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r9;
    // 0x800826D4: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800826D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800826DC: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    // 0x800826E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800826E4: swc1        $f6, 0x18EC($at)
    MEM_W(0X18EC, ctx->r1) = ctx->f6.u32l;
    // 0x800826E8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800826EC: swc1        $f8, 0x18E8($at)
    MEM_W(0X18E8, ctx->r1) = ctx->f8.u32l;
    // 0x800826F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800826F4: addiu       $t3, $zero, 0x96
    ctx->r11 = ADD32(0, 0X96);
    // 0x800826F8: sh          $t3, -0xEA0($at)
    MEM_H(-0XEA0, ctx->r1) = ctx->r11;
    // 0x800826FC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80082700: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x80082704: sh          $t4, -0xEA2($at)
    MEM_H(-0XEA2, ctx->r1) = ctx->r12;
    // 0x80082708: lh          $t5, 0x44($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X44);
    // 0x8008270C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80082710: b           L_8008280C
    // 0x80082714: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
        goto L_8008280C;
    // 0x80082714: sh          $t6, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r14;
L_80082718:
    // 0x80082718: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8008271C: lwc1        $f10, 0x7610($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7610);
    // 0x80082720: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80082724: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80082728: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x8008272C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80082730: jal         0x8009BC2C
    // 0x80082734: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_49;
    // 0x80082734: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_49:
    // 0x80082738: lhu         $t7, 0x50($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X50);
    // 0x8008273C: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80082740: addiu       $a3, $a3, -0x7CC0
    ctx->r7 = ADD32(ctx->r7, -0X7CC0);
    // 0x80082744: bne         $t7, $zero, L_8008280C
    if (ctx->r15 != 0) {
        // 0x80082748: nop
    
            goto L_8008280C;
    }
    // 0x80082748: nop

    // 0x8008274C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80082750: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80082754: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80082758: beq         $t8, $zero, L_80082778
    if (ctx->r24 == 0) {
        // 0x8008275C: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80082778;
    }
    // 0x8008275C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80082760: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80082764: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80082768: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8008276C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80082770: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082774: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
L_80082778:
    // 0x80082778: lh          $t3, 0x44($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X44);
    // 0x8008277C: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x80082780: lh          $t2, -0xEA0($t2)
    ctx->r10 = MEM_H(ctx->r10, -0XEA0);
    // 0x80082784: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80082788: sh          $t4, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r12;
    // 0x8008278C: b           L_8008280C
    // 0x80082790: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
        goto L_8008280C;
    // 0x80082790: sh          $t2, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r10;
    // 0x80082794: lhu         $t5, 0x50($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X50);
L_80082798:
    // 0x80082798: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8008279C: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x800827A0: bne         $t5, $zero, L_800827F4
    if (ctx->r13 != 0) {
        // 0x800827A4: lui         $a2, 0x3DCC
        ctx->r6 = S32(0X3DCC << 16);
            goto L_800827F4;
    }
    // 0x800827A4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800827A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800827AC: lwc1        $f4, 0x7614($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7614);
    // 0x800827B0: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x800827B4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x800827B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800827BC: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800827C0: jal         0x8009BC2C
    // 0x800827C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_50;
    // 0x800827C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_50:
    // 0x800827C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800827CC: lwc1        $f8, 0x70($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800827D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800827D4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800827D8: nop

    // 0x800827DC: bc1f        L_8008280C
    if (!c1cs) {
        // 0x800827E0: nop
    
            goto L_8008280C;
    }
    // 0x800827E0: nop

    // 0x800827E4: jal         0x80060FBC
    // 0x800827E8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_51;
    // 0x800827E8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_51:
    // 0x800827EC: b           L_8008280C
    // 0x800827F0: nop

        goto L_8008280C;
    // 0x800827F0: nop

L_800827F4:
    // 0x800827F4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800827F8: lwc1        $f10, 0x7618($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7618);
    // 0x800827FC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80082800: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80082804: jal         0x8009BC2C
    // 0x80082808: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_52;
    // 0x80082808: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_52:
L_8008280C:
    // 0x8008280C: b           L_80082F18
    // 0x80082810: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80082810: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80082814:
    // 0x80082814: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80082818: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x8008281C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80082820: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80082824: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80082828: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8008282C: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80082830: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80082834: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80082838: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x8008283C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80082840: swc1        $f12, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f12.u32l;
    // 0x80082844: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80082848: jal         0x80005100
    // 0x8008284C: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    Math_Atan2F(rdram, ctx);
        goto after_53;
    // 0x8008284C: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_53:
    // 0x80082850: jal         0x8009F768
    // 0x80082854: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_54;
    // 0x80082854: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_54:
    // 0x80082858: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8008285C: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80082860: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80082864: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80082868: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8008286C: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80082870: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80082874: jal         0x80005100
    // 0x80082878: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_55;
    // 0x80082878: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_55:
    // 0x8008287C: jal         0x8009F768
    // 0x80082880: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    Math_RadToDeg(rdram, ctx);
        goto after_56;
    // 0x80082880: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    after_56:
    // 0x80082884: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082888: lwc1        $f6, 0x761C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X761C);
    // 0x8008288C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80082890: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80082894: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80082898: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8008289C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800828A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800828A4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800828A8: jal         0x80005E90
    // 0x800828AC: nop

    Matrix_RotateY(rdram, ctx);
        goto after_57;
    // 0x800828AC: nop

    after_57:
    // 0x800828B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800828B4: lwc1        $f4, 0x7620($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7620);
    // 0x800828B8: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800828BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800828C0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800828C4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800828C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800828CC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800828D0: jal         0x80005D44
    // 0x800828D4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_58;
    // 0x800828D4: nop

    after_58:
    // 0x800828D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800828DC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x800828E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800828E4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800828E8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800828EC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800828F0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800828F4: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x800828F8: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800828FC: jal         0x80006A20
    // 0x80082900: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_59;
    // 0x80082900: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    after_59:
    // 0x80082904: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80082908: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x8008290C: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80082910: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x80082914: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80082918: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008291C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80082920: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80082924: sh          $t7, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r15;
    // 0x80082928: swc1        $f6, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f6.u32l;
    // 0x8008292C: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
    // 0x80082930: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x80082934: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x80082938: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8008293C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x80082940: jal         0x8009BC2C
    // 0x80082944: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_60;
    // 0x80082944: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_60:
    // 0x80082948: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8008294C: lui         $a2, 0x3C23
    ctx->r6 = S32(0X3C23 << 16);
    // 0x80082950: lui         $a3, 0x3DCC
    ctx->r7 = S32(0X3DCC << 16);
    // 0x80082954: ori         $a3, $a3, 0xCCCD
    ctx->r7 = ctx->r7 | 0XCCCD;
    // 0x80082958: ori         $a2, $a2, 0xD70A
    ctx->r6 = ctx->r6 | 0XD70A;
    // 0x8008295C: addiu       $a0, $s0, 0x5C
    ctx->r4 = ADD32(ctx->r16, 0X5C);
    // 0x80082960: lui         $a1, 0xC28C
    ctx->r5 = S32(0XC28C << 16);
    // 0x80082964: jal         0x8009BC2C
    // 0x80082968: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_61;
    // 0x80082968: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_61:
    // 0x8008296C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80082970: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80082974: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082978: lwc1        $f6, 0x7624($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7624);
    // 0x8008297C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80082980: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80082984: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80082988: addiu       $a0, $s0, 0x70
    ctx->r4 = ADD32(ctx->r16, 0X70);
    // 0x8008298C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80082990: jal         0x8009BC2C
    // 0x80082994: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_62;
    // 0x80082994: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_62:
    // 0x80082998: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008299C: lwc1        $f10, 0x70($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X70);
    // 0x800829A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800829A4: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x800829A8: nop

    // 0x800829AC: bc1f        L_800829BC
    if (!c1cs) {
        // 0x800829B0: nop
    
            goto L_800829BC;
    }
    // 0x800829B0: nop

    // 0x800829B4: jal         0x80060FBC
    // 0x800829B8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_63;
    // 0x800829B8: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_63:
L_800829BC:
    // 0x800829BC: b           L_80082F18
    // 0x800829C0: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x800829C0: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_800829C4:
    // 0x800829C4: lh          $v0, 0x44($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X44);
    // 0x800829C8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800829CC: beql        $v0, $zero, L_800829EC
    if (ctx->r2 == 0) {
        // 0x800829D0: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800829EC;
    }
    goto skip_8;
    // 0x800829D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_8:
    // 0x800829D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800829D8: beq         $v0, $at, L_80082BB8
    if (ctx->r2 == ctx->r1) {
        // 0x800829DC: lui         $a0, 0x8017
        ctx->r4 = S32(0X8017 << 16);
            goto L_80082BB8;
    }
    // 0x800829DC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x800829E0: b           L_80082BD8
    // 0x800829E4: sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
        goto L_80082BD8;
    // 0x800829E4: sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    // 0x800829E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800829EC:
    // 0x800829EC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x800829F0: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x800829F4: swc1        $f4, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f4.u32l;
    // 0x800829F8: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
    // 0x800829FC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80082A00: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80082A04: bne         $v0, $at, L_80082A60
    if (ctx->r2 != ctx->r1) {
        // 0x80082A08: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_80082A60;
    }
    // 0x80082A08: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80082A0C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80082A10: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80082A14: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80082A18: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80082A1C: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x80082A20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082A24: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80082A28: sw          $a2, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r6;
    // 0x80082A2C: addiu       $a1, $a1, -0x7CA8
    ctx->r5 = ADD32(ctx->r5, -0X7CA8);
    // 0x80082A30: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80082A34: addiu       $a3, $a3, -0x7CC0
    ctx->r7 = ADD32(ctx->r7, -0X7CC0);
    // 0x80082A38: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x80082A3C: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x80082A40: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80082A44: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082A48: addiu       $t1, $zero, 0x19
    ctx->r9 = ADD32(0, 0X19);
    // 0x80082A4C: sw          $t1, -0x7CA4($at)
    MEM_W(-0X7CA4, ctx->r1) = ctx->r9;
    // 0x80082A50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082A54: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80082A58: sw          $t2, -0x7B80($at)
    MEM_W(-0X7B80, ctx->r1) = ctx->r10;
    // 0x80082A5C: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
L_80082A60:
    // 0x80082A60: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80082A64: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80082A68: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80082A6C: addiu       $a3, $a3, -0x7CC0
    ctx->r7 = ADD32(ctx->r7, -0X7CC0);
    // 0x80082A70: addiu       $a0, $a0, -0x7CB0
    ctx->r4 = ADD32(ctx->r4, -0X7CB0);
    // 0x80082A74: bne         $v0, $zero, L_80082A9C
    if (ctx->r2 != 0) {
        // 0x80082A78: addiu       $v1, $v1, -0x7CAC
        ctx->r3 = ADD32(ctx->r3, -0X7CAC);
            goto L_80082A9C;
    }
    // 0x80082A78: addiu       $v1, $v1, -0x7CAC
    ctx->r3 = ADD32(ctx->r3, -0X7CAC);
    // 0x80082A7C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80082A80: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80082A84: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80082A88: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80082A8C: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80082A90: addiu       $t6, $zero, 0x32
    ctx->r14 = ADD32(0, 0X32);
    // 0x80082A94: sh          $t6, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r14;
    // 0x80082A98: lh          $v0, 0x46($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X46);
L_80082A9C:
    // 0x80082A9C: beq         $v0, $zero, L_80082AA8
    if (ctx->r2 == 0) {
        // 0x80082AA0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80082AA8;
    }
    // 0x80082AA0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80082AA4: sh          $t7, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r15;
L_80082AA8:
    // 0x80082AA8: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x80082AAC: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80082AB0: bne         $t9, $zero, L_80082B90
    if (ctx->r25 != 0) {
        // 0x80082AB4: nop
    
            goto L_80082B90;
    }
    // 0x80082AB4: nop

    // 0x80082AB8: lhu         $t0, 0x50($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X50);
    // 0x80082ABC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80082AC0: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80082AC4: bne         $t0, $zero, L_80082B90
    if (ctx->r8 != 0) {
        // 0x80082AC8: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80082B90;
    }
    // 0x80082AC8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80082ACC: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x80082AD0: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80082AD4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80082AD8: lwc1        $f6, 0x40($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80082ADC: lwc1        $f4, 0x7D20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80082AE0: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80082AE4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80082AE8: lwc1        $f8, 0x48($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80082AEC: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80082AF0: jal         0x80005100
    // 0x80082AF4: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    Math_Atan2F(rdram, ctx);
        goto after_64;
    // 0x80082AF4: sub.s       $f14, $f8, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f6.fl;
    after_64:
    // 0x80082AF8: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80082AFC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082B00: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082B04: lwc1        $f8, 0x7628($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7628);
    // 0x80082B08: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80082B0C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082B10: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80082B14: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x80082B18: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80082B1C: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80082B20: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80082B24: swc1        $f6, 0x18EC($at)
    MEM_W(0X18EC, ctx->r1) = ctx->f6.u32l;
    // 0x80082B28: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80082B2C: lwc1        $f10, 0x40($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X40);
    // 0x80082B30: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80082B34: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x80082B38: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80082B3C: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80082B40: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x80082B44: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80082B48: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80082B4C: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80082B50: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80082B54: lwc1        $f4, 0x44($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X44);
    // 0x80082B58: mul.s       $f6, $f16, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80082B5C: sub.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80082B60: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80082B64: jal         0x80005100
    // 0x80082B68: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_65;
    // 0x80082B68: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_65:
    // 0x80082B6C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80082B70: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80082B74: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x80082B78: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082B7C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80082B80: lwc1        $f10, 0x762C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X762C);
    // 0x80082B84: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082B88: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80082B8C: swc1        $f8, 0x18E8($at)
    MEM_W(0X18E8, ctx->r1) = ctx->f8.u32l;
L_80082B90:
    // 0x80082B90: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80082B94: lh          $t1, -0xEA0($t1)
    ctx->r9 = MEM_H(ctx->r9, -0XEA0);
    // 0x80082B98: bnel        $t1, $zero, L_80082BD8
    if (ctx->r9 != 0) {
        // 0x80082B9C: sh          $zero, 0x30($s0)
        MEM_H(0X30, ctx->r16) = 0;
            goto L_80082BD8;
    }
    goto skip_9;
    // 0x80082B9C: sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
    skip_9:
    // 0x80082BA0: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x80082BA4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80082BA8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80082BAC: sh          $t2, -0xE1A($at)
    MEM_H(-0XE1A, ctx->r1) = ctx->r10;
    // 0x80082BB0: b           L_80082BD4
    // 0x80082BB4: sh          $t3, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r11;
        goto L_80082BD4;
    // 0x80082BB4: sh          $t3, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r11;
L_80082BB8:
    // 0x80082BB8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80082BBC: addiu       $a0, $a0, 0x79A8
    ctx->r4 = ADD32(ctx->r4, 0X79A8);
    // 0x80082BC0: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x80082BC4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80082BC8: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x80082BCC: jal         0x8009BC2C
    // 0x80082BD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_66;
    // 0x80082BD0: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_66:
L_80082BD4:
    // 0x80082BD4: sh          $zero, 0x30($s0)
    MEM_H(0X30, ctx->r16) = 0;
L_80082BD8:
    // 0x80082BD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082BDC: lwc1        $f4, 0x7630($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7630);
    // 0x80082BE0: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80082BE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80082BE8: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80082BEC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80082BF0: lw          $a1, 0x18E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X18E8);
    // 0x80082BF4: addiu       $a0, $a0, -0xEE0
    ctx->r4 = ADD32(ctx->r4, -0XEE0);
    // 0x80082BF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80082BFC: jal         0x8009BD38
    // 0x80082C00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_67;
    // 0x80082C00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_67:
    // 0x80082C04: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082C08: lwc1        $f10, 0x7634($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7634);
    // 0x80082C0C: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80082C10: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80082C14: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80082C18: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80082C1C: lw          $a1, 0x18EC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X18EC);
    // 0x80082C20: addiu       $a0, $a0, -0xEDC
    ctx->r4 = ADD32(ctx->r4, -0XEDC);
    // 0x80082C24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80082C28: jal         0x8009BD38
    // 0x80082C2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToAngle(rdram, ctx);
        goto after_68;
    // 0x80082C2C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_68:
    // 0x80082C30: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80082C34: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80082C38: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80082C3C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80082C40: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082C44: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80082C48: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80082C4C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80082C50: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80082C54: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082C58: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x80082C5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80082C60: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x80082C64: lwc1        $f4, 0x7638($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7638);
    // 0x80082C68: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80082C6C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80082C70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082C74: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80082C78: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80082C7C: jal         0x80005E90
    // 0x80082C80: nop

    Matrix_RotateY(rdram, ctx);
        goto after_69;
    // 0x80082C80: nop

    after_69:
    // 0x80082C84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80082C88: lwc1        $f8, -0xEE0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XEE0);
    // 0x80082C8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082C90: lwc1        $f6, 0x763C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X763C);
    // 0x80082C94: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80082C98: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80082C9C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80082CA0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80082CA4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80082CA8: jal         0x80005D44
    // 0x80082CAC: nop

    Matrix_RotateX(rdram, ctx);
        goto after_70;
    // 0x80082CAC: nop

    after_70:
    // 0x80082CB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80082CB4: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80082CB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082CBC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80082CC0: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80082CC4: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80082CC8: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80082CCC: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80082CD0: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x80082CD4: jal         0x80006A20
    // 0x80082CD8: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_71;
    // 0x80082CD8: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    after_71:
    // 0x80082CDC: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80082CE0: addiu       $v0, $v0, -0xEF0
    ctx->r2 = ADD32(ctx->r2, -0XEF0);
    // 0x80082CE4: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80082CE8: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80082CEC: lh          $t4, 0x44($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X44);
    // 0x80082CF0: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80082CF4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80082CF8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80082CFC: addiu       $a0, $s0, 0x60
    ctx->r4 = ADD32(ctx->r16, 0X60);
    // 0x80082D00: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80082D04: swc1        $f4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f4.u32l;
    // 0x80082D08: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80082D0C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80082D10: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082D14: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80082D18: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x80082D1C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80082D20: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80082D24: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80082D28: bne         $t4, $zero, L_80082D84
    if (ctx->r12 != 0) {
        // 0x80082D2C: swc1        $f8, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
            goto L_80082D84;
    }
    // 0x80082D2C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x80082D30: lwc1        $f6, 0x7640($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7640);
    // 0x80082D34: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80082D38: jal         0x8009BC2C
    // 0x80082D3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_72;
    // 0x80082D3C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_72:
    // 0x80082D40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082D44: lwc1        $f4, 0x7644($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7644);
    // 0x80082D48: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80082D4C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80082D50: addiu       $a0, $s0, 0x64
    ctx->r4 = ADD32(ctx->r16, 0X64);
    // 0x80082D54: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x80082D58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80082D5C: jal         0x8009BC2C
    // 0x80082D60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_73;
    // 0x80082D60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_73:
    // 0x80082D64: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082D68: lwc1        $f10, 0x7648($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7648);
    // 0x80082D6C: addiu       $a0, $s0, 0x68
    ctx->r4 = ADD32(ctx->r16, 0X68);
    // 0x80082D70: lui         $a1, 0x4248
    ctx->r5 = S32(0X4248 << 16);
    // 0x80082D74: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80082D78: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80082D7C: jal         0x8009BC2C
    // 0x80082D80: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_74;
    // 0x80082D80: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_74:
L_80082D84:
    // 0x80082D84: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80082D88: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x80082D8C: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x80082D90: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x80082D94: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80082D98: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80082D9C: lwc1        $f8, 0x138($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X138);
    // 0x80082DA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80082DA4: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x80082DA8: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80082DAC: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80082DB0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x80082DB4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80082DB8: jal         0x80006A20
    // 0x80082DBC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_75;
    // 0x80082DBC: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    after_75:
    // 0x80082DC0: lhu         $t6, 0x50($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X50);
    // 0x80082DC4: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80082DC8: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80082DCC: bne         $t6, $zero, L_80082E5C
    if (ctx->r14 != 0) {
        // 0x80082DD0: nop
    
            goto L_80082E5C;
    }
    // 0x80082DD0: nop

    // 0x80082DD4: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80082DD8: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x80082DDC: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80082DE0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80082DE4: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80082DE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082DEC: lwc1        $f4, 0x60($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80082DF0: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80082DF4: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80082DF8: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80082DFC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80082E00: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80082E04: nop

    // 0x80082E08: bc1f        L_80082E5C
    if (!c1cs) {
        // 0x80082E0C: nop
    
            goto L_80082E5C;
    }
    // 0x80082E0C: nop

    // 0x80082E10: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80082E14: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80082E18: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80082E1C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80082E20: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80082E24: lwc1        $f8, 0x64($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X64);
    // 0x80082E28: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80082E2C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80082E30: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x80082E34: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80082E38: nop

    // 0x80082E3C: bc1f        L_80082E5C
    if (!c1cs) {
        // 0x80082E40: nop
    
            goto L_80082E5C;
    }
    // 0x80082E40: nop

    // 0x80082E44: lw          $t7, 0x498($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X498);
    // 0x80082E48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082E4C: bne         $t7, $zero, L_80082E5C
    if (ctx->r15 != 0) {
        // 0x80082E50: nop
    
            goto L_80082E5C;
    }
    // 0x80082E50: nop

    // 0x80082E54: jal         0x800A6CD0
    // 0x80082E58: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    Player_ApplyDamage(rdram, ctx);
        goto after_76;
    // 0x80082E58: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_76:
L_80082E5C:
    // 0x80082E5C: b           L_80082F18
    // 0x80082E60: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80082E60: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80082E64:
    // 0x80082E64: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80082E68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80082E6C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80082E70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80082E74: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80082E78: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80082E7C: lwc1        $f6, 0x58($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80082E80: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80082E84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80082E88: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80082E8C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80082E90: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80082E94: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
    // 0x80082E98: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80082E9C: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x80082EA0: swc1        $f8, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f8.u32l;
    // 0x80082EA4: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80082EA8: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80082EAC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80082EB0: nop

    // 0x80082EB4: bc1f        L_80082EC0
    if (!c1cs) {
        // 0x80082EB8: nop
    
            goto L_80082EC0;
    }
    // 0x80082EB8: nop

    // 0x80082EBC: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80082EC0:
    // 0x80082EC0: lwc1        $f6, 0x764C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X764C);
    // 0x80082EC4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80082EC8: jal         0x8009BC2C
    // 0x80082ECC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_77;
    // 0x80082ECC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_77:
    // 0x80082ED0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80082ED4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80082ED8: lwc1        $f10, 0x6C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80082EDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80082EE0: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x80082EE4: nop

    // 0x80082EE8: bc1t        L_80082EFC
    if (c1cs) {
        // 0x80082EEC: nop
    
            goto L_80082EFC;
    }
    // 0x80082EEC: nop

    // 0x80082EF0: lhu         $t8, 0x50($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X50);
    // 0x80082EF4: bne         $t8, $zero, L_80082F04
    if (ctx->r24 != 0) {
        // 0x80082EF8: nop
    
            goto L_80082F04;
    }
    // 0x80082EF8: nop

L_80082EFC:
    // 0x80082EFC: jal         0x80060FBC
    // 0x80082F00: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    Object_Kill(rdram, ctx);
        goto after_78;
    // 0x80082F00: addiu       $a1, $s0, 0x80
    ctx->r5 = ADD32(ctx->r16, 0X80);
    after_78:
L_80082F04:
    // 0x80082F04: b           L_80082F18
    // 0x80082F08: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
        goto L_80082F18;
    // 0x80082F08: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80082F0C:
    // 0x80082F0C: jal         0x8007A28C
    // 0x80082F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Effect383_Update(rdram, ctx);
        goto after_79;
    // 0x80082F10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x80082F14: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
L_80082F18:
    // 0x80082F18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80082F1C: bnel        $v1, $at, L_80082F44
    if (ctx->r3 != ctx->r1) {
        // 0x80082F20: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80082F44;
    }
    goto skip_10;
    // 0x80082F20: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    skip_10:
    // 0x80082F24: lh          $t9, 0x44($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X44);
    // 0x80082F28: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80082F2C: bnel        $t9, $at, L_80082F44
    if (ctx->r25 != ctx->r1) {
        // 0x80082F30: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80082F44;
    }
    goto skip_11;
    // 0x80082F30: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    skip_11:
    // 0x80082F34: jal         0x8007FE88
    // 0x80082F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_EnemyShot_Update(rdram, ctx);
        goto after_80;
    // 0x80082F38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_80:
    // 0x80082F3C: lh          $v1, 0x4E($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4E);
    // 0x80082F40: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_80082F44:
    // 0x80082F44: beq         $at, $zero, L_80082F64
    if (ctx->r1 == 0) {
        // 0x80082F48: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80082F64;
    }
    // 0x80082F48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80082F4C: beq         $v1, $at, L_80082F64
    if (ctx->r3 == ctx->r1) {
        // 0x80082F50: lui         $a0, 0x8018
        ctx->r4 = S32(0X8018 << 16);
            goto L_80082F64;
    }
    // 0x80082F50: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x80082F54: lw          $a0, -0x7D80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7D80);
    // 0x80082F58: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80082F5C: jal         0x8007A774
    // 0x80082F60: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    Effect_CheckPlayerCollision(rdram, ctx);
        goto after_81;
    // 0x80082F60: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    after_81:
L_80082F64:
    // 0x80082F64: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80082F68: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80082F6C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80082F70: jr          $ra
    // 0x80082F74: nop

    return;
    // 0x80082F74: nop

;}
RECOMP_FUNC void Effect_Effect350_Spawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80062D04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80062D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80062D0C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x80062D10: swc1        $f14, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f14.u32l;
    // 0x80062D14: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80062D18: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80062D1C: addiu       $v0, $v0, 0x37E0
    ctx->r2 = ADD32(ctx->r2, 0X37E0);
    // 0x80062D20: addiu       $a2, $a2, 0x130
    ctx->r6 = ADD32(ctx->r6, 0X130);
    // 0x80062D24: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
L_80062D28:
    // 0x80062D28: bne         $t6, $zero, L_80062DA0
    if (ctx->r14 != 0) {
        // 0x80062D2C: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80062DA0;
    }
    // 0x80062D2C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80062D30: jal         0x80061474
    // 0x80062D34: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80062D34: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80062D38: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80062D3C: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80062D40: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80062D44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80062D48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80062D4C: addiu       $t8, $zero, 0x15E
    ctx->r24 = ADD32(0, 0X15E);
    // 0x80062D50: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80062D54: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
    // 0x80062D58: sh          $t8, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r24;
    // 0x80062D5C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x80062D60: lwc1        $f6, 0x7940($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x80062D64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80062D68: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80062D6C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80062D70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80062D74: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80062D78: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    // 0x80062D7C: swc1        $f8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f8.u32l;
    // 0x80062D80: sh          $t9, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r25;
    // 0x80062D84: addiu       $a0, $a2, 0x1C
    ctx->r4 = ADD32(ctx->r6, 0X1C);
    // 0x80062D88: swc1        $f0, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f0.u32l;
    // 0x80062D8C: swc1        $f10, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f10.u32l;
    // 0x80062D90: jal         0x800612B8
    // 0x80062D94: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_1;
    // 0x80062D94: swc1        $f16, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f16.u32l;
    after_1:
    // 0x80062D98: b           L_80062DB0
    // 0x80062D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80062DB0;
    // 0x80062D9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062DA0:
    // 0x80062DA0: addiu       $a2, $a2, 0x8C
    ctx->r6 = ADD32(ctx->r6, 0X8C);
    // 0x80062DA4: bnel        $a2, $v0, L_80062D28
    if (ctx->r6 != ctx->r2) {
        // 0x80062DA8: lbu         $t6, 0x0($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X0);
            goto L_80062D28;
    }
    goto skip_0;
    // 0x80062DA8: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    skip_0:
    // 0x80062DAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80062DB0:
    // 0x80062DB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80062DB4: jr          $ra
    // 0x80062DB8: nop

    return;
    // 0x80062DB8: nop

;}
RECOMP_FUNC void Background_DrawPartialStarfield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DE68: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8003DE6C: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x8003DE70: lui         $at, 0x43F0
    ctx->r1 = S32(0X43F0 << 16);
    // 0x8003DE74: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x8003DE78: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x8003DE7C: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x8003DE80: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8003DE84: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8003DE88: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8003DE8C: addiu       $t2, $t2, 0x7E64
    ctx->r10 = ADD32(ctx->r10, 0X7E64);
    // 0x8003DE90: addiu       $t1, $t1, -0x7BE0
    ctx->r9 = ADD32(ctx->r9, -0X7BE0);
    // 0x8003DE94: lui         $s3, 0xE700
    ctx->r19 = S32(0XE700 << 16);
    // 0x8003DE98: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8003DE9C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8003DEA0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8003DEA4: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x8003DEA8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x8003DEAC: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x8003DEB0: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x8003DEB4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x8003DEB8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x8003DEBC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8003DEC0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8003DEC4: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DEC8: lui         $t8, 0xBA00
    ctx->r24 = S32(0XBA00 << 16);
    // 0x8003DECC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x8003DED0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003DED4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8003DED8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003DEDC: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8003DEE0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DEE4: ori         $t8, $t8, 0x1402
    ctx->r24 = ctx->r24 | 0X1402;
    // 0x8003DEE8: lui         $t9, 0x30
    ctx->r25 = S32(0X30 << 16);
    // 0x8003DEEC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003DEF0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8003DEF4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8003DEF8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8003DEFC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DF00: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x8003DF04: lui         $t8, 0xFFFE
    ctx->r24 = S32(0XFFFE << 16);
    // 0x8003DF08: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003DF0C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8003DF10: ori         $t8, $t8, 0x793C
    ctx->r24 = ctx->r24 | 0X793C;
    // 0x8003DF14: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8003DF18: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8003DF1C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8003DF20: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003DF24: lui         $t6, 0xB900
    ctx->r14 = S32(0XB900 << 16);
    // 0x8003DF28: lui         $t7, 0xF0A
    ctx->r15 = S32(0XF0A << 16);
    // 0x8003DF2C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003DF30: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8003DF34: ori         $t7, $t7, 0x4000
    ctx->r15 = ctx->r15 | 0X4000;
    // 0x8003DF38: ori         $t6, $t6, 0x31D
    ctx->r14 = ctx->r14 | 0X31D;
    // 0x8003DF3C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8003DF40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8003DF44: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003DF48: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8003DF4C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8003DF50: c.le.s      $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f30.fl <= ctx->f0.fl;
    // 0x8003DF54: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8003DF58: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x8003DF5C: addiu       $v0, $v0, -0x7BDC
    ctx->r2 = ADD32(ctx->r2, -0X7BDC);
    // 0x8003DF60: bc1f        L_8003DF74
    if (!c1cs) {
        // 0x8003DF64: addiu       $s0, $s0, -0x7BD8
        ctx->r16 = ADD32(ctx->r16, -0X7BD8);
            goto L_8003DF74;
    }
    // 0x8003DF64: addiu       $s0, $s0, -0x7BD8
    ctx->r16 = ADD32(ctx->r16, -0X7BD8);
    // 0x8003DF68: sub.s       $f4, $f0, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x8003DF6C: swc1        $f4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f4.u32l;
    // 0x8003DF70: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
L_8003DF74:
    // 0x8003DF74: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003DF78: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8003DF7C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8003DF80: c.le.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl <= ctx->f2.fl;
    // 0x8003DF84: lui         $ra, 0x8018
    ctx->r31 = S32(0X8018 << 16);
    // 0x8003DF88: addiu       $s2, $zero, 0x1F4
    ctx->r18 = ADD32(0, 0X1F4);
    // 0x8003DF8C: bc1fl       L_8003DFA4
    if (!c1cs) {
        // 0x8003DF90: c.lt.s      $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
            goto L_8003DFA4;
    }
    goto skip_0;
    // 0x8003DF90: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    skip_0:
    // 0x8003DF94: sub.s       $f6, $f2, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f28.fl;
    // 0x8003DF98: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8003DF9C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003DFA0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
L_8003DFA4:
    // 0x8003DFA4: nop

    // 0x8003DFA8: bc1fl       L_8003DFC0
    if (!c1cs) {
        // 0x8003DFAC: c.lt.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
            goto L_8003DFC0;
    }
    goto skip_1;
    // 0x8003DFAC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    skip_1:
    // 0x8003DFB0: add.s       $f8, $f0, $f30
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f30.fl;
    // 0x8003DFB4: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x8003DFB8: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8003DFBC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
L_8003DFC0:
    // 0x8003DFC0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8003DFC4: bc1f        L_8003DFD8
    if (!c1cs) {
        // 0x8003DFC8: nop
    
            goto L_8003DFD8;
    }
    // 0x8003DFC8: nop

    // 0x8003DFCC: add.s       $f10, $f2, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f28.fl;
    // 0x8003DFD0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8003DFD4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
L_8003DFD8:
    // 0x8003DFD8: lw          $ra, -0x7D68($ra)
    ctx->r31 = MEM_W(ctx->r31, -0X7D68);
    // 0x8003DFDC: lw          $t4, -0x7D78($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D78);
    // 0x8003DFE0: lw          $t5, -0x7D70($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D70);
    // 0x8003DFE4: sw          $ra, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r31;
    // 0x8003DFE8: mov.s       $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    ctx->f26.fl = ctx->f2.fl;
    // 0x8003DFEC: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8003DFF0: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x8003DFF4: jal         0x80023250
    // 0x8003DFF8: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8003DFF8: sw          $t5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r13;
    after_0:
    // 0x8003DFFC: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8003E000: jal         0x80023090
    // 0x8003E004: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003E004: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8003E008: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8003E00C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8003E010: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8003E014: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8003E018: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8003E01C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003E020: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8003E024: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8003E028: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003E02C: addiu       $t2, $t2, 0x7E64
    ctx->r10 = ADD32(ctx->r10, 0X7E64);
    // 0x8003E030: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x8003E034: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8003E038: lw          $ra, 0x60($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X60);
    // 0x8003E03C: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8003E040: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8003E044: lui         $s1, 0xF600
    ctx->r17 = S32(0XF600 << 16);
    // 0x8003E048: lui         $s0, 0xF700
    ctx->r16 = S32(0XF700 << 16);
L_8003E04C:
    // 0x8003E04C: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8003E050: lwc1        $f6, 0x0($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8003E054: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8003E058: add.s       $f2, $f4, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8003E05C: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x8003E060: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8003E064: add.s       $f12, $f6, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x8003E068: c.le.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl <= ctx->f2.fl;
    // 0x8003E06C: nop

    // 0x8003E070: bc1fl       L_8003E080
    if (!c1cs) {
        // 0x8003E074: c.le.s      $f22, $f12
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl <= ctx->f12.fl;
            goto L_8003E080;
    }
    goto skip_2;
    // 0x8003E074: c.le.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl <= ctx->f12.fl;
    skip_2:
    // 0x8003E078: sub.s       $f2, $f2, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x8003E07C: c.le.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f22.fl <= ctx->f12.fl;
L_8003E080:
    // 0x8003E080: sub.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8003E084: bc1fl       L_8003E094
    if (!c1cs) {
        // 0x8003E088: sub.s       $f12, $f12, $f18
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
            goto L_8003E094;
    }
    goto skip_3;
    // 0x8003E088: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
    skip_3:
    // 0x8003E08C: sub.s       $f12, $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f28.fl;
    // 0x8003E090: sub.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f18.fl;
L_8003E094:
    // 0x8003E094: mul.s       $f8, $f14, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8003E098: nop

    // 0x8003E09C: mul.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8003E0A0: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003E0A4: add.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8003E0A8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8003E0AC: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8003E0B0: nop

    // 0x8003E0B4: sll         $t9, $t0, 16
    ctx->r25 = S32(ctx->r8 << 16);
    // 0x8003E0B8: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8003E0BC: bltz        $t6, L_8003E16C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8003E0C0: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_8003E16C;
    }
    // 0x8003E0C0: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8003E0C4: slti        $at, $t6, 0x140
    ctx->r1 = SIGNED(ctx->r14) < 0X140 ? 1 : 0;
    // 0x8003E0C8: beq         $at, $zero, L_8003E16C
    if (ctx->r1 == 0) {
        // 0x8003E0CC: nop
    
            goto L_8003E16C;
    }
    // 0x8003E0CC: nop

    // 0x8003E0D0: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8003E0D4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003E0D8: nop

    // 0x8003E0DC: mul.s       $f6, $f14, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8003E0E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003E0E4: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003E0E8: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8003E0EC: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8003E0F0: nop

    // 0x8003E0F4: sll         $t8, $t1, 16
    ctx->r24 = S32(ctx->r9 << 16);
    // 0x8003E0F8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003E0FC: slt         $at, $s4, $t9
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003E100: beq         $at, $zero, L_8003E16C
    if (ctx->r1 == 0) {
        // 0x8003E104: or          $t1, $t9, $zero
        ctx->r9 = ctx->r25 | 0;
            goto L_8003E16C;
    }
    // 0x8003E104: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x8003E108: slt         $at, $t9, $s5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8003E10C: beq         $at, $zero, L_8003E16C
    if (ctx->r1 == 0) {
        // 0x8003E110: andi        $a2, $t0, 0x3FF
        ctx->r6 = ctx->r8 & 0X3FF;
            goto L_8003E16C;
    }
    // 0x8003E110: andi        $a2, $t0, 0x3FF
    ctx->r6 = ctx->r8 & 0X3FF;
    // 0x8003E114: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003E118: andi        $a3, $t1, 0x3FF
    ctx->r7 = ctx->r9 & 0X3FF;
    // 0x8003E11C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8003E120: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8003E124: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003E128: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8003E12C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003E130: sll         $t6, $a2, 14
    ctx->r14 = S32(ctx->r6 << 14);
    // 0x8003E134: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003E138: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8003E13C: sw          $s0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r16;
    // 0x8003E140: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x8003E144: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x8003E148: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8003E14C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003E150: or          $t8, $t6, $s1
    ctx->r24 = ctx->r14 | ctx->r17;
    // 0x8003E154: or          $t6, $t6, $t7
    ctx->r14 = ctx->r14 | ctx->r15;
    // 0x8003E158: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8003E15C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8003E160: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8003E164: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8003E168: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8003E16C:
    // 0x8003E16C: bne         $t3, $s2, L_8003E04C
    if (ctx->r11 != ctx->r18) {
        // 0x8003E170: addiu       $ra, $ra, 0x4
        ctx->r31 = ADD32(ctx->r31, 0X4);
            goto L_8003E04C;
    }
    // 0x8003E170: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x8003E174: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003E178: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8003E17C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8003E180: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003E184: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8003E188: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8003E18C: lui         $t9, 0xBA00
    ctx->r25 = S32(0XBA00 << 16);
    // 0x8003E190: ori         $t9, $t9, 0x602
    ctx->r25 = ctx->r25 | 0X602;
    // 0x8003E194: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8003E198: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8003E19C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003E1A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8003E1A4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8003E1A8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8003E1AC: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8003E1B0: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x8003E1B4: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x8003E1B8: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x8003E1BC: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x8003E1C0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8003E1C4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8003E1C8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x8003E1CC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8003E1D0: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x8003E1D4: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x8003E1D8: jr          $ra
    // 0x8003E1DC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8003E1DC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void FoBase_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FE78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008FE7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008FE80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008FE84: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008FE88: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8008FE8C: lw          $t7, -0x7C24($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7C24);
    // 0x8008FE90: lw          $t6, -0x7C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C28);
    // 0x8008FE94: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008FE98: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008FE9C: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8008FEA0: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8008FEA4: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8008FEA8: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8008FEAC: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8008FEB0: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8008FEB4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8008FEB8: jal         0x800BA1D0
    // 0x8008FEBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    RCP_SetupDL_29(rdram, ctx);
        goto after_0;
    // 0x8008FEBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8008FEC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8008FEC4: addiu       $v1, $v1, 0x7E64
    ctx->r3 = ADD32(ctx->r3, 0X7E64);
    // 0x8008FEC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FECC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8008FED0: addiu       $t4, $t4, 0x3090
    ctx->r12 = ADD32(ctx->r12, 0X3090);
    // 0x8008FED4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8008FED8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008FEDC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8008FEE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008FEE4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8008FEE8: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8008FEEC: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8008FEF0: lw          $t6, -0x7C24($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7C24);
    // 0x8008FEF4: lw          $t5, -0x7C28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7C28);
    // 0x8008FEF8: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8008FEFC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8008FF00: lui         $a2, 0x8018
    ctx->r6 = S32(0X8018 << 16);
    // 0x8008FF04: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8008FF08: lw          $a3, -0x7CC8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X7CC8);
    // 0x8008FF0C: lw          $a2, -0x7CD0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X7CD0);
    // 0x8008FF10: lw          $a1, -0x7CD8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7CD8);
    // 0x8008FF14: lw          $a0, -0x7CE0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7CE0);
    // 0x8008FF18: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8008FF1C: jal         0x800B98A8
    // 0x8008FF20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    RCP_SetupDL_34(rdram, ctx);
        goto after_1;
    // 0x8008FF20: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x8008FF24: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8008FF28: lui         $t2, 0xBA00
    ctx->r10 = S32(0XBA00 << 16);
    // 0x8008FF2C: ori         $t2, $t2, 0xC02
    ctx->r10 = ctx->r10 | 0XC02;
    // 0x8008FF30: addiu       $v1, $v1, 0x7E64
    ctx->r3 = ADD32(ctx->r3, 0X7E64);
    // 0x8008FF34: addiu       $t1, $zero, 0x2000
    ctx->r9 = ADD32(0, 0X2000);
    // 0x8008FF38: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8008FF3C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FF40: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x8008FF44: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8008FF48: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008FF4C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8008FF50: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8008FF54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FF58: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8008FF5C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008FF60: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8008FF64: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8008FF68: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FF6C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8008FF70: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8008FF74: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8008FF78: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8008FF7C: lwc1        $f4, 0xE0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0XE0);
    // 0x8008FF80: lwc1        $f8, 0xDC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XDC);
    // 0x8008FF84: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8008FF88: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8008FF8C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8008FF90: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8008FF94: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8008FF98: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x8008FF9C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8008FFA0: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8008FFA4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8008FFA8: ori         $t4, $t8, 0xFF
    ctx->r12 = ctx->r24 | 0XFF;
    // 0x8008FFAC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8008FFB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FFB4: lui         $t9, 0x601
    ctx->r25 = S32(0X601 << 16);
    // 0x8008FFB8: addiu       $t9, $t9, -0x2A40
    ctx->r25 = ADD32(ctx->r25, -0X2A40);
    // 0x8008FFBC: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8008FFC0: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008FFC4: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8008FFC8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008FFCC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8008FFD0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8008FFD4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8008FFD8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8008FFDC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8008FFE0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8008FFE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008FFE8: jr          $ra
    // 0x8008FFEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008FFEC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void Object_SetShadowDL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005BAB4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8005BAB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005BABC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8005BAC0: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8005BAC4: slti        $at, $a0, 0x140
    ctx->r1 = SIGNED(ctx->r4) < 0X140 ? 1 : 0;
    // 0x8005BAC8: bne         $at, $zero, L_8005BAE0
    if (ctx->r1 != 0) {
        // 0x8005BACC: addiu       $at, $zero, 0x176
        ctx->r1 = ADD32(0, 0X176);
            goto L_8005BAE0;
    }
    // 0x8005BACC: addiu       $at, $zero, 0x176
    ctx->r1 = ADD32(0, 0X176);
    // 0x8005BAD0: beq         $a0, $at, L_8005BB30
    if (ctx->r4 == ctx->r1) {
        // 0x8005BAD4: lw          $t8, 0xBC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XBC);
            goto L_8005BB30;
    }
    // 0x8005BAD4: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x8005BAD8: b           L_8005C5E0
    // 0x8005BADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005BADC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005BAE0:
    // 0x8005BAE0: slti        $at, $a0, 0xE8
    ctx->r1 = SIGNED(ctx->r4) < 0XE8 ? 1 : 0;
    // 0x8005BAE4: bne         $at, $zero, L_8005BB10
    if (ctx->r1 != 0) {
        // 0x8005BAE8: addiu       $t7, $a0, -0xC0
        ctx->r15 = ADD32(ctx->r4, -0XC0);
            goto L_8005BB10;
    }
    // 0x8005BAE8: addiu       $t7, $a0, -0xC0
    ctx->r15 = ADD32(ctx->r4, -0XC0);
    // 0x8005BAEC: addiu       $t6, $a0, -0x124
    ctx->r14 = ADD32(ctx->r4, -0X124);
    // 0x8005BAF0: sltiu       $at, $t6, 0x1C
    ctx->r1 = ctx->r14 < 0X1C ? 1 : 0;
    // 0x8005BAF4: beq         $at, $zero, L_8005C5DC
    if (ctx->r1 == 0) {
        // 0x8005BAF8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8005C5DC;
    }
    // 0x8005BAF8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005BAFC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005BB00: addu        $at, $at, $t6
    gpr jr_addend_8005BB08 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8005BB04: lw          $t6, 0x6164($at)
    ctx->r14 = ADD32(ctx->r1, 0X6164);
    // 0x8005BB08: jr          $t6
    // 0x8005BB0C: nop

    switch (jr_addend_8005BB08 >> 2) {
        case 0: goto L_8005BE68; break;
        case 1: goto L_8005BF30; break;
        case 2: goto L_8005BF30; break;
        case 3: goto L_8005BF30; break;
        case 4: goto L_8005BF30; break;
        case 5: goto L_8005C5DC; break;
        case 6: goto L_8005C5DC; break;
        case 7: goto L_8005C5DC; break;
        case 8: goto L_8005C5DC; break;
        case 9: goto L_8005C5DC; break;
        case 10: goto L_8005C5DC; break;
        case 11: goto L_8005C5DC; break;
        case 12: goto L_8005C5DC; break;
        case 13: goto L_8005C5DC; break;
        case 14: goto L_8005C5DC; break;
        case 15: goto L_8005C5DC; break;
        case 16: goto L_8005C5DC; break;
        case 17: goto L_8005C5DC; break;
        case 18: goto L_8005C5DC; break;
        case 19: goto L_8005C5DC; break;
        case 20: goto L_8005C5DC; break;
        case 21: goto L_8005C5DC; break;
        case 22: goto L_8005C5DC; break;
        case 23: goto L_8005C5DC; break;
        case 24: goto L_8005BE98; break;
        case 25: goto L_8005C5DC; break;
        case 26: goto L_8005C5DC; break;
        case 27: goto L_8005C5BC; break;
        default: switch_error(__func__, 0x8005BB08, 0x800D6164);
    }
    // 0x8005BB0C: nop

L_8005BB10:
    // 0x8005BB10: sltiu       $at, $t7, 0x28
    ctx->r1 = ctx->r15 < 0X28 ? 1 : 0;
    // 0x8005BB14: beq         $at, $zero, L_8005C5DC
    if (ctx->r1 == 0) {
        // 0x8005BB18: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8005C5DC;
    }
    // 0x8005BB18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005BB1C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005BB20: addu        $at, $at, $t7
    gpr jr_addend_8005BB28 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8005BB24: lw          $t7, 0x61D4($at)
    ctx->r15 = ADD32(ctx->r1, 0X61D4);
    // 0x8005BB28: jr          $t7
    // 0x8005BB2C: nop

    switch (jr_addend_8005BB28 >> 2) {
        case 0: goto L_8005C06C; break;
        case 1: goto L_8005C5DC; break;
        case 2: goto L_8005C5DC; break;
        case 3: goto L_8005BBE0; break;
        case 4: goto L_8005C5DC; break;
        case 5: goto L_8005C5DC; break;
        case 6: goto L_8005BBE0; break;
        case 7: goto L_8005C5DC; break;
        case 8: goto L_8005BBE0; break;
        case 9: goto L_8005C5DC; break;
        case 10: goto L_8005C5DC; break;
        case 11: goto L_8005C5DC; break;
        case 12: goto L_8005C5DC; break;
        case 13: goto L_8005C5DC; break;
        case 14: goto L_8005C5DC; break;
        case 15: goto L_8005C5DC; break;
        case 16: goto L_8005C5DC; break;
        case 17: goto L_8005C5DC; break;
        case 18: goto L_8005C5DC; break;
        case 19: goto L_8005C5DC; break;
        case 20: goto L_8005C5DC; break;
        case 21: goto L_8005C5DC; break;
        case 22: goto L_8005C5DC; break;
        case 23: goto L_8005C520; break;
        case 24: goto L_8005C5DC; break;
        case 25: goto L_8005C5DC; break;
        case 26: goto L_8005C5DC; break;
        case 27: goto L_8005C5DC; break;
        case 28: goto L_8005C5DC; break;
        case 29: goto L_8005C5DC; break;
        case 30: goto L_8005C5DC; break;
        case 31: goto L_8005C5DC; break;
        case 32: goto L_8005C5DC; break;
        case 33: goto L_8005C5DC; break;
        case 34: goto L_8005C5DC; break;
        case 35: goto L_8005C5DC; break;
        case 36: goto L_8005C5DC; break;
        case 37: goto L_8005C248; break;
        case 38: goto L_8005C110; break;
        case 39: goto L_8005C3E8; break;
        default: switch_error(__func__, 0x8005BB28, 0x800D61D4);
    }
    // 0x8005BB2C: nop

L_8005BB30:
    // 0x8005BB30: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005BB34: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005BB38: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005BB3C: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005BB40: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005BB44: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8005BB48: addu        $t3, $t3, $t9
    ctx->r11 = ADD32(ctx->r11, ctx->r25);
    // 0x8005BB4C: lh          $t3, 0x17E($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X17E);
    // 0x8005BB50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005BB54: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BB58: bne         $t3, $zero, L_8005BBC8
    if (ctx->r11 != 0) {
        // 0x8005BB5C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8005BBC8;
    }
    // 0x8005BB5C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005BB60: lwc1        $f0, 0x6274($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6274);
    // 0x8005BB64: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005BB68: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BB6C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005BB70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005BB74: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8005BB78: jal         0x80005C34
    // 0x8005BB7C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Matrix_Scale(rdram, ctx);
        goto after_0;
    // 0x8005BB7C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x8005BB80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BB84: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8005BB88: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005BB8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BB90: jal         0x80005D44
    // 0x8005BB94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x8005BB94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8005BB98: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BB9C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BBA0: jal         0x80006EB8
    // 0x8005BBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x8005BBA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8005BBA8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BBAC: lui         $t7, 0x103
    ctx->r15 = S32(0X103 << 16);
    // 0x8005BBB0: addiu       $t7, $t7, -0x5760
    ctx->r15 = ADD32(ctx->r15, -0X5760);
    // 0x8005BBB4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005BBB8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005BBBC: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8005BBC0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005BBC4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8005BBC8:
    // 0x8005BBC8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BBCC: addiu       $a0, $s0, 0x7E64
    ctx->r4 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BBD0: jal         0x800B8DD0
    // 0x8005BBD4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8005BBD4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_3:
    // 0x8005BBD8: b           L_8005C5E0
    // 0x8005BBDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005BBDC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005BBE0:
    // 0x8005BBE0: lw          $t8, 0xBC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XBC);
    // 0x8005BBE4: lui         $t3, 0x8016
    ctx->r11 = S32(0X8016 << 16);
    // 0x8005BBE8: addiu       $t3, $t3, 0x3FE0
    ctx->r11 = ADD32(ctx->r11, 0X3FE0);
    // 0x8005BBEC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005BBF0: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005BBF4: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8005BBF8: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8005BBFC: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005BC00: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005BC04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8005BC08: addu        $v1, $t9, $t3
    ctx->r3 = ADD32(ctx->r25, ctx->r11);
    // 0x8005BC0C: lh          $v0, 0xB4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0XB4);
    // 0x8005BC10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005BC14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BC18: beq         $v0, $at, L_8005BC34
    if (ctx->r2 == ctx->r1) {
        // 0x8005BC1C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8005BC34;
    }
    // 0x8005BC1C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005BC20: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x8005BC24: beq         $v0, $at, L_8005BCA8
    if (ctx->r2 == ctx->r1) {
        // 0x8005BC28: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005BCA8;
    }
    // 0x8005BC28: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BC2C: b           L_8005BD70
    // 0x8005BC30: nop

        goto L_8005BD70;
    // 0x8005BC30: nop

L_8005BC34:
    // 0x8005BC34: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005BC38: lwc1        $f0, 0x6278($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6278);
    // 0x8005BC3C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005BC40: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BC44: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005BC48: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005BC4C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8005BC50: jal         0x80005C34
    // 0x8005BC54: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x8005BC54: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x8005BC58: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BC5C: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8005BC60: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005BC64: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BC68: jal         0x80005D44
    // 0x8005BC6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8005BC6C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8005BC70: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BC74: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BC78: jal         0x80006EB8
    // 0x8005BC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8005BC7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8005BC80: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BC84: lui         $t7, 0x103
    ctx->r15 = S32(0X103 << 16);
    // 0x8005BC88: addiu       $t7, $t7, -0x5FF0
    ctx->r15 = ADD32(ctx->r15, -0X5FF0);
    // 0x8005BC8C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005BC90: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005BC94: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8005BC98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005BC9C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005BCA0: b           L_8005C5E0
    // 0x8005BCA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005BCA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005BCA8:
    // 0x8005BCA8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BCAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005BCB0: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8005BCB4: jal         0x800B8DD0
    // 0x8005BCB8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    RCP_SetupDL(rdram, ctx);
        goto after_7;
    // 0x8005BCB8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x8005BCBC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8005BCC0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005BCC4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BCC8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8005BCCC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8005BCD0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005BCD4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005BCD8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005BCDC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005BCE0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BCE4: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x8005BCE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005BCEC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005BCF0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005BCF4: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005BCF8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005BCFC: lwc1        $f4, 0x150($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X150);
    // 0x8005BD00: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BD04: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005BD08: mul.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005BD0C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005BD10: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BD14: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005BD18: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005BD1C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005BD20: jal         0x80005C34
    // 0x8005BD24: nop

    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x8005BD24: nop

    after_8:
    // 0x8005BD28: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BD2C: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x8005BD30: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005BD34: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BD38: jal         0x80005D44
    // 0x8005BD3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x8005BD3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8005BD40: jal         0x80006EB8
    // 0x8005BD44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x8005BD44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8005BD48: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BD4C: lui         $t8, 0x102
    ctx->r24 = S32(0X102 << 16);
    // 0x8005BD50: addiu       $t8, $t8, 0x4AC0
    ctx->r24 = ADD32(ctx->r24, 0X4AC0);
    // 0x8005BD54: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005BD58: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005BD5C: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8005BD60: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005BD64: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005BD68: b           L_8005C5E0
    // 0x8005BD6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005BD6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005BD70:
    // 0x8005BD70: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8005BD74: lw          $v0, 0x7DB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7DB0);
    // 0x8005BD78: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x8005BD7C: addiu       $v1, $v1, -0x334
    ctx->r3 = ADD32(ctx->r3, -0X334);
    // 0x8005BD80: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x8005BD84: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8005BD88: andi        $t9, $v0, 0x7
    ctx->r25 = ctx->r2 & 0X7;
    // 0x8005BD8C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005BD90: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x8005BD94: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005BD98: lwc1        $f14, 0x627C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X627C);
    // 0x8005BD9C: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8005BDA0: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x8005BDA4: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8005BDA8: lwc1        $f2, 0x0($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8005BDAC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005BDB0: add.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8005BDB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005BDB8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BDBC: add.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8005BDC0: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005BDC4: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8005BDC8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BDCC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8005BDD0: jal         0x80005C34
    // 0x8005BDD4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x8005BDD4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_11:
    // 0x8005BDD8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BDDC: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x8005BDE0: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005BDE4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BDE8: jal         0x80005E90
    // 0x8005BDEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_12;
    // 0x8005BDEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x8005BDF0: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005BDF4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BDF8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005BDFC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8005BE00: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8005BE04: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005BE08: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BE0C: jal         0x80005B00
    // 0x8005BE10: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_13;
    // 0x8005BE10: lui         $a3, 0x41F0
    ctx->r7 = S32(0X41F0 << 16);
    after_13:
    // 0x8005BE14: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BE18: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BE1C: jal         0x80006EB8
    // 0x8005BE20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x8005BE20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8005BE24: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BE28: lui         $t5, 0xB700
    ctx->r13 = S32(0XB700 << 16);
    // 0x8005BE2C: addiu       $t6, $zero, 0x2000
    ctx->r14 = ADD32(0, 0X2000);
    // 0x8005BE30: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005BE34: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005BE38: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005BE3C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005BE40: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BE44: lui         $t9, 0x103
    ctx->r25 = S32(0X103 << 16);
    // 0x8005BE48: addiu       $t9, $t9, 0x2780
    ctx->r25 = ADD32(ctx->r25, 0X2780);
    // 0x8005BE4C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005BE50: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005BE54: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x8005BE58: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005BE5C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8005BE60: b           L_8005C5E0
    // 0x8005BE64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005BE64: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005BE68:
    // 0x8005BE68: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BE6C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BE70: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BE74: lui         $t5, 0x603
    ctx->r13 = S32(0X603 << 16);
    // 0x8005BE78: addiu       $t5, $t5, 0x4B90
    ctx->r13 = ADD32(ctx->r13, 0X4B90);
    // 0x8005BE7C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005BE80: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005BE84: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005BE88: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005BE8C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005BE90: b           L_8005C5E0
    // 0x8005BE94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005BE94: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005BE98:
    // 0x8005BE98: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8005BE9C: lw          $t6, -0x7D80($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D80);
    // 0x8005BEA0: lw          $t7, 0x1C8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C8);
    // 0x8005BEA4: bne         $t7, $zero, L_8005BED8
    if (ctx->r15 != 0) {
        // 0x8005BEA8: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005BED8;
    }
    // 0x8005BEA8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BEAC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005BEB4: jal         0x800B8DD0
    // 0x8005BEB8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_15;
    // 0x8005BEB8: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_15:
    // 0x8005BEBC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BEC0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8005BEC4: addiu       $t3, $zero, 0xC8
    ctx->r11 = ADD32(0, 0XC8);
    // 0x8005BEC8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005BECC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005BED0: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005BED4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8005BED8:
    // 0x8005BED8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BEDC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005BEE0: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8005BEE4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BEE8: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005BEEC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005BEF0: jal         0x80005D44
    // 0x8005BEF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_16;
    // 0x8005BEF4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_16:
    // 0x8005BEF8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8005BEFC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005BF00: jal         0x8005980C
    // 0x8005BF04: nop

    Graphics_SetScaleMtx(rdram, ctx);
        goto after_17;
    // 0x8005BF04: nop

    after_17:
    // 0x8005BF08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BF0C: lui         $t6, 0x103
    ctx->r14 = S32(0X103 << 16);
    // 0x8005BF10: addiu       $t6, $t6, -0x5760
    ctx->r14 = ADD32(ctx->r14, -0X5760);
    // 0x8005BF14: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005BF18: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005BF1C: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005BF20: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005BF24: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005BF28: b           L_8005C5E0
    // 0x8005BF2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005BF2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005BF30:
    // 0x8005BF30: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8005BF34: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8005BF38: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8005BF3C: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x8005BF40: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005BF44: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8005BF48: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8005BF4C: lwc1        $f16, -0xED8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XED8);
    // 0x8005BF50: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005BF54: lwc1        $f18, 0x6280($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6280);
    // 0x8005BF58: mul.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8005BF5C: jal         0x80023250
    // 0x8005BF60: nop

    __cosf_recomp(rdram, ctx);
        goto after_18;
    // 0x8005BF60: nop

    after_18:
    // 0x8005BF64: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005BF68: lw          $t9, 0x1A88($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1A88);
    // 0x8005BF6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005BF70: lw          $a0, 0xB8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB8);
    // 0x8005BF74: bne         $t9, $at, L_8005BFA4
    if (ctx->r25 != ctx->r1) {
        // 0x8005BF78: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8005BFA4;
    }
    // 0x8005BF78: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BF7C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BF80: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BF84: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8005BF88: addiu       $t5, $zero, -0xA6
    ctx->r13 = ADD32(0, -0XA6);
    // 0x8005BF8C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005BF90: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005BF94: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005BF98: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005BF9C: b           L_8005BFCC
    // 0x8005BFA0: addiu       $at, $zero, 0x125
    ctx->r1 = ADD32(0, 0X125);
        goto L_8005BFCC;
    // 0x8005BFA0: addiu       $at, $zero, 0x125
    ctx->r1 = ADD32(0, 0X125);
L_8005BFA4:
    // 0x8005BFA4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005BFA8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005BFAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005BFB0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8005BFB4: addiu       $t8, $zero, -0x6A
    ctx->r24 = ADD32(0, -0X6A);
    // 0x8005BFB8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005BFBC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005BFC0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005BFC4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005BFC8: addiu       $at, $zero, 0x125
    ctx->r1 = ADD32(0, 0X125);
L_8005BFCC:
    // 0x8005BFCC: beq         $a0, $at, L_8005BFFC
    if (ctx->r4 == ctx->r1) {
        // 0x8005BFD0: addiu       $at, $zero, 0x126
        ctx->r1 = ADD32(0, 0X126);
            goto L_8005BFFC;
    }
    // 0x8005BFD0: addiu       $at, $zero, 0x126
    ctx->r1 = ADD32(0, 0X126);
    // 0x8005BFD4: beq         $a0, $at, L_8005C024
    if (ctx->r4 == ctx->r1) {
        // 0x8005BFD8: lui         $t6, 0x600
        ctx->r14 = S32(0X600 << 16);
            goto L_8005C024;
    }
    // 0x8005BFD8: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x8005BFDC: addiu       $at, $zero, 0x127
    ctx->r1 = ADD32(0, 0X127);
    // 0x8005BFE0: beq         $a0, $at, L_8005C048
    if (ctx->r4 == ctx->r1) {
        // 0x8005BFE4: lui         $t9, 0x600
        ctx->r25 = S32(0X600 << 16);
            goto L_8005C048;
    }
    // 0x8005BFE4: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8005BFE8: addiu       $at, $zero, 0x128
    ctx->r1 = ADD32(0, 0X128);
    // 0x8005BFEC: beql        $a0, $at, L_8005C04C
    if (ctx->r4 == ctx->r1) {
        // 0x8005BFF0: lw          $v0, 0x0($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X0);
            goto L_8005C04C;
    }
    goto skip_0;
    // 0x8005BFF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x8005BFF4: b           L_8005C5E0
    // 0x8005BFF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005BFF8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005BFFC:
    // 0x8005BFFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C000: lui         $t4, 0x603
    ctx->r12 = S32(0X603 << 16);
    // 0x8005C004: addiu       $t4, $t4, 0x6840
    ctx->r12 = ADD32(ctx->r12, 0X6840);
    // 0x8005C008: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005C00C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005C010: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8005C014: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005C018: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005C01C: b           L_8005C5E0
    // 0x8005C020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005C020: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C024:
    // 0x8005C024: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C028: lui         $t7, 0x603
    ctx->r15 = S32(0X603 << 16);
    // 0x8005C02C: addiu       $t7, $t7, 0x6CD0
    ctx->r15 = ADD32(ctx->r15, 0X6CD0);
    // 0x8005C030: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005C034: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005C038: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8005C03C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005C040: b           L_8005C5E0
    // 0x8005C044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005C044: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C048:
    // 0x8005C048: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8005C04C:
    // 0x8005C04C: lui         $t3, 0x603
    ctx->r11 = S32(0X603 << 16);
    // 0x8005C050: addiu       $t3, $t3, 0x63B0
    ctx->r11 = ADD32(ctx->r11, 0X63B0);
    // 0x8005C054: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8005C058: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8005C05C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005C060: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8005C064: b           L_8005C5E0
    // 0x8005C068: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005C068: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C06C:
    // 0x8005C06C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005C070: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C074: lwc1        $f0, 0x6284($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6284);
    // 0x8005C078: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005C07C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C080: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8005C084: addiu       $t6, $zero, -0x6A
    ctx->r14 = ADD32(0, -0X6A);
    // 0x8005C088: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005C08C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005C090: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005C094: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005C098: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8005C09C: lui         $a3, 0x8016
    ctx->r7 = S32(0X8016 << 16);
    // 0x8005C0A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C0A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005C0A8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8005C0AC: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8005C0B0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8005C0B4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005C0B8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005C0BC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005C0C0: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x8005C0C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005C0C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005C0CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005C0D0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005C0D4: lw          $a3, 0x40F0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X40F0);
    // 0x8005C0D8: jal         0x80005C34
    // 0x8005C0DC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_19;
    // 0x8005C0DC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_19:
    // 0x8005C0E0: jal         0x80006EB8
    // 0x8005C0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_20;
    // 0x8005C0E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_20:
    // 0x8005C0E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C0EC: lui         $t5, 0x603
    ctx->r13 = S32(0X603 << 16);
    // 0x8005C0F0: addiu       $t5, $t5, 0x4B90
    ctx->r13 = ADD32(ctx->r13, 0X4B90);
    // 0x8005C0F4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005C0F8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005C0FC: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005C100: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005C104: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005C108: b           L_8005C5E0
    // 0x8005C10C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005C10C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C110:
    // 0x8005C110: jal         0x800BA550
    // 0x8005C114: nop

    RCP_SetupDL_48(rdram, ctx);
        goto after_21;
    // 0x8005C114: nop

    after_21:
    // 0x8005C118: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005C11C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005C120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005C124: jal         0x800B8DD0
    // 0x8005C128: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    RCP_SetupDL(rdram, ctx);
        goto after_22;
    // 0x8005C128: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_22:
    // 0x8005C12C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005C130: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C134: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x8005C138: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x8005C13C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005C140: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005C144: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005C148: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005C14C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C150: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8005C154: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C158: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005C15C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005C160: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005C164: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005C168: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C16C: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8005C170: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8005C174: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005C178: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005C17C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005C180: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005C184: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8005C188: addiu       $t8, $t8, 0x3FE0
    ctx->r24 = ADD32(ctx->r24, 0X3FE0);
    // 0x8005C18C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C190: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8005C194: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005C198: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x8005C19C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8005C1A0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005C1A4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005C1A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8005C1AC: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8005C1B0: lw          $a1, 0x114($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X114);
    // 0x8005C1B4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8005C1B8: jal         0x80005D44
    // 0x8005C1BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_23;
    // 0x8005C1BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_23:
    // 0x8005C1C0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8005C1C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C1C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C1CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C1D0: jal         0x80005FE0
    // 0x8005C1D4: lw          $a1, 0x11C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X11C);
    Matrix_RotateZ(rdram, ctx);
        goto after_24;
    // 0x8005C1D4: lw          $a1, 0x11C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X11C);
    after_24:
    // 0x8005C1D8: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8005C1DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C1E0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005C1E4: lwc1        $f0, 0x110($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X110);
    // 0x8005C1E8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005C1EC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C1F0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005C1F4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005C1F8: jal         0x80005C34
    // 0x8005C1FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_25;
    // 0x8005C1FC: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_25:
    // 0x8005C200: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C204: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x8005C208: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005C20C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C210: jal         0x80005D44
    // 0x8005C214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_26;
    // 0x8005C214: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_26:
    // 0x8005C218: jal         0x80006EB8
    // 0x8005C21C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_27;
    // 0x8005C21C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_27:
    // 0x8005C220: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C224: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8005C228: addiu       $t5, $t5, 0x4AC0
    ctx->r13 = ADD32(ctx->r13, 0X4AC0);
    // 0x8005C22C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005C230: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005C234: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005C238: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005C23C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005C240: b           L_8005C5E0
    // 0x8005C244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005C244: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C248:
    // 0x8005C248: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005C24C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005C250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005C254: jal         0x800B8DD0
    // 0x8005C258: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    RCP_SetupDL(rdram, ctx);
        goto after_28;
    // 0x8005C258: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    after_28:
    // 0x8005C25C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005C260: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005C264: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C268: lui         $t7, 0xB700
    ctx->r15 = S32(0XB700 << 16);
    // 0x8005C26C: addiu       $t8, $zero, 0x2000
    ctx->r24 = ADD32(0, 0X2000);
    // 0x8005C270: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8005C274: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8005C278: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8005C27C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005C280: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C284: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8005C288: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C28C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005C290: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005C294: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005C298: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005C29C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C2A0: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8005C2A4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8005C2A8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005C2AC: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005C2B0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005C2B4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005C2B8: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8005C2BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005C2C0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8005C2C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C2C8: jal         0x80005B00
    // 0x8005C2CC: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_29;
    // 0x8005C2CC: lui         $a3, 0x42F0
    ctx->r7 = S32(0X42F0 << 16);
    after_29:
    // 0x8005C2D0: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8005C2D4: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8005C2D8: addiu       $t9, $t9, 0x3FE0
    ctx->r25 = ADD32(ctx->r25, 0X3FE0);
    // 0x8005C2DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8005C2E0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8005C2E4: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8005C2E8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8005C2EC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005C2F0: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8005C2F4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8005C2F8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8005C2FC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C300: lwc1        $f6, 0x6288($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6288);
    // 0x8005C304: lwc1        $f4, 0x118($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X118);
    // 0x8005C308: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C30C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C310: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005C314: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8005C318: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C31C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005C320: jal         0x80005D44
    // 0x8005C324: nop

    Matrix_RotateX(rdram, ctx);
        goto after_30;
    // 0x8005C324: nop

    after_30:
    // 0x8005C328: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8005C32C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C330: lwc1        $f16, 0x628C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X628C);
    // 0x8005C334: lwc1        $f10, 0x11C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X11C);
    // 0x8005C338: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C33C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C340: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8005C344: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C348: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8005C34C: jal         0x80005FE0
    // 0x8005C350: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_31;
    // 0x8005C350: nop

    after_31:
    // 0x8005C354: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8005C358: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C35C: lwc1        $f6, 0x6290($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6290);
    // 0x8005C360: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8005C364: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C368: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C36C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005C370: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C374: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8005C378: jal         0x80005E90
    // 0x8005C37C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_32;
    // 0x8005C37C: nop

    after_32:
    // 0x8005C380: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C384: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005C388: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8005C38C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C390: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x8005C394: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8005C398: jal         0x80005C34
    // 0x8005C39C: lui         $a3, 0x40F0
    ctx->r7 = S32(0X40F0 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_33;
    // 0x8005C39C: lui         $a3, 0x40F0
    ctx->r7 = S32(0X40F0 << 16);
    after_33:
    // 0x8005C3A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C3A4: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x8005C3A8: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005C3AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C3B0: jal         0x80005D44
    // 0x8005C3B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_34;
    // 0x8005C3B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_34:
    // 0x8005C3B8: jal         0x80006EB8
    // 0x8005C3BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_35;
    // 0x8005C3BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_35:
    // 0x8005C3C0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C3C4: lui         $t6, 0x102
    ctx->r14 = S32(0X102 << 16);
    // 0x8005C3C8: addiu       $t6, $t6, 0x4AC0
    ctx->r14 = ADD32(ctx->r14, 0X4AC0);
    // 0x8005C3CC: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8005C3D0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8005C3D4: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8005C3D8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8005C3DC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8005C3E0: b           L_8005C5E0
    // 0x8005C3E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005C3E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C3E8:
    // 0x8005C3E8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005C3EC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005C3F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005C3F4: jal         0x800B8DD0
    // 0x8005C3F8: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    RCP_SetupDL(rdram, ctx);
        goto after_36;
    // 0x8005C3F8: addiu       $a1, $zero, 0x45
    ctx->r5 = ADD32(0, 0X45);
    after_36:
    // 0x8005C3FC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005C400: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C404: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8005C408: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C40C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005C410: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005C414: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005C418: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005C41C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C420: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x8005C424: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8005C428: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005C42C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005C430: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8005C434: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005C438: lw          $t4, 0xBC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XBC);
    // 0x8005C43C: addiu       $t6, $t6, 0x3FE0
    ctx->r14 = ADD32(ctx->r14, 0X3FE0);
    // 0x8005C440: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C444: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8005C448: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8005C44C: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x8005C450: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8005C454: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8005C458: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x8005C45C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8005C460: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x8005C464: lw          $a1, 0x118($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X118);
    // 0x8005C468: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8005C46C: jal         0x80005D44
    // 0x8005C470: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_37;
    // 0x8005C470: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_37:
    // 0x8005C474: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8005C478: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C47C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C480: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8005C484: jal         0x80005FE0
    // 0x8005C488: lw          $a1, 0x11C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X11C);
    Matrix_RotateZ(rdram, ctx);
        goto after_38;
    // 0x8005C488: lw          $a1, 0x11C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X11C);
    after_38:
    // 0x8005C48C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8005C490: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C494: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005C498: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8005C49C: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8005C4A0: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8005C4A4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8005C4A8: jal         0x80005B00
    // 0x8005C4AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_39;
    // 0x8005C4AC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_39:
    // 0x8005C4B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8005C4B4: lwc1        $f0, 0x6294($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6294);
    // 0x8005C4B8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C4BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005C4C0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005C4C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005C4C8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005C4CC: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C4D0: jal         0x80005C34
    // 0x8005C4D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_40;
    // 0x8005C4D4: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_40:
    // 0x8005C4D8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C4DC: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x8005C4E0: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8005C4E4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8005C4E8: jal         0x80005D44
    // 0x8005C4EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_41;
    // 0x8005C4EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_41:
    // 0x8005C4F0: jal         0x80006EB8
    // 0x8005C4F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_42;
    // 0x8005C4F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_42:
    // 0x8005C4F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C4FC: lui         $t4, 0x102
    ctx->r12 = S32(0X102 << 16);
    // 0x8005C500: addiu       $t4, $t4, 0x4AC0
    ctx->r12 = ADD32(ctx->r12, 0X4AC0);
    // 0x8005C504: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8005C508: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8005C50C: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x8005C510: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8005C514: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8005C518: b           L_8005C5E0
    // 0x8005C51C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005C51C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C520:
    // 0x8005C520: jal         0x800BA550
    // 0x8005C524: nop

    RCP_SetupDL_48(rdram, ctx);
        goto after_43;
    // 0x8005C524: nop

    after_43:
    // 0x8005C528: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8005C52C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8005C530: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8005C534: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8005C538: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8005C53C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C540: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8005C544: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8005C548: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8005C54C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8005C550: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005C554: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005C558: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C55C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x8005C560: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8005C564: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8005C568: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8005C56C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005C570: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8005C574: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8005C578: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005C57C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005C580: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8005C584: jal         0x80005C34
    // 0x8005C588: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_44;
    // 0x8005C588: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_44:
    // 0x8005C58C: jal         0x80006EB8
    // 0x8005C590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_45;
    // 0x8005C590: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_45:
    // 0x8005C594: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8005C598: lui         $t5, 0x102
    ctx->r13 = S32(0X102 << 16);
    // 0x8005C59C: addiu       $t5, $t5, 0x4AC0
    ctx->r13 = ADD32(ctx->r13, 0X4AC0);
    // 0x8005C5A0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8005C5A4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8005C5A8: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8005C5AC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8005C5B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8005C5B4: b           L_8005C5E0
    // 0x8005C5B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8005C5E0;
    // 0x8005C5B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C5BC:
    // 0x8005C5BC: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8005C5C0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8005C5C4: addiu       $t8, $t8, -0xEF0
    ctx->r24 = ADD32(ctx->r24, -0XEF0);
    // 0x8005C5C8: sll         $t7, $t6, 7
    ctx->r15 = S32(ctx->r14 << 7);
    // 0x8005C5CC: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8005C5D0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8005C5D4: jal         0x80198310
    // 0x8005C5D8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    Venom1_Ve1Golemech_SetShadow(rdram, ctx);
        goto after_46;
    // 0x8005C5D8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_46:
L_8005C5DC:
    // 0x8005C5DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005C5E0:
    // 0x8005C5E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8005C5E4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x8005C5E8: jr          $ra
    // 0x8005C5EC: nop

    return;
    // 0x8005C5EC: nop

;}
RECOMP_FUNC void Audio_ResetSfx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AB50: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AB54: sb          $zero, 0x5D18($at)
    MEM_B(0X5D18, ctx->r1) = 0;
    // 0x8001AB58: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AB5C: sb          $zero, 0x5D1C($at)
    MEM_B(0X5D1C, ctx->r1) = 0;
    // 0x8001AB60: lui         $at, 0x800C
    ctx->r1 = S32(0X800C << 16);
    // 0x8001AB64: sh          $zero, 0x5D24($at)
    MEM_H(0X5D24, ctx->r1) = 0;
    // 0x8001AB68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001AB6C: lui         $t1, 0x8015
    ctx->r9 = S32(0X8015 << 16);
    // 0x8001AB70: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001AB74: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8001AB78: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8001AB7C: lui         $a0, 0x8015
    ctx->r4 = S32(0X8015 << 16);
    // 0x8001AB80: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001AB84: addiu       $a0, $a0, -0x66E0
    ctx->r4 = ADD32(ctx->r4, -0X66E0);
    // 0x8001AB88: addiu       $a1, $a1, -0x66D8
    ctx->r5 = ADD32(ctx->r5, -0X66D8);
    // 0x8001AB8C: addiu       $a3, $a3, -0x66D0
    ctx->r7 = ADD32(ctx->r7, -0X66D0);
    // 0x8001AB90: addiu       $t0, $t0, -0x6584
    ctx->r8 = ADD32(ctx->r8, -0X6584);
    // 0x8001AB94: addiu       $t1, $t1, -0x6578
    ctx->r9 = ADD32(ctx->r9, -0X6578);
    // 0x8001AB98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AB9C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8001ABA0:
    // 0x8001ABA0: addu        $t6, $a0, $v0
    ctx->r14 = ADD32(ctx->r4, ctx->r2);
    // 0x8001ABA4: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8001ABA8: sb          $zero, 0x0($t6)
    MEM_B(0X0, ctx->r14) = 0;
    // 0x8001ABAC: addu        $t8, $a3, $v0
    ctx->r24 = ADD32(ctx->r7, ctx->r2);
    // 0x8001ABB0: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x8001ABB4: sll         $t3, $v0, 4
    ctx->r11 = S32(ctx->r2 << 4);
    // 0x8001ABB8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ABBC: sb          $a2, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r6;
    // 0x8001ABC0: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x8001ABC4: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x8001ABC8: slti        $at, $t4, 0x5
    ctx->r1 = SIGNED(ctx->r12) < 0X5 ? 1 : 0;
    // 0x8001ABCC: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8001ABD0: addu        $v1, $t1, $t3
    ctx->r3 = ADD32(ctx->r9, ctx->r11);
    // 0x8001ABD4: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8001ABD8: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8001ABDC: bne         $at, $zero, L_8001ABA0
    if (ctx->r1 != 0) {
        // 0x8001ABE0: sh          $zero, 0xC($v1)
        MEM_H(0XC, ctx->r3) = 0;
            goto L_8001ABA0;
    }
    // 0x8001ABE0: sh          $zero, 0xC($v1)
    MEM_H(0XC, ctx->r3) = 0;
    // 0x8001ABE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001ABE8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_8001ABEC:
    // 0x8001ABEC: lui         $t6, 0x8015
    ctx->r14 = S32(0X8015 << 16);
    // 0x8001ABF0: addiu       $t6, $t6, -0x66C8
    ctx->r14 = ADD32(ctx->r14, -0X66C8);
    // 0x8001ABF4: sll         $t5, $v0, 6
    ctx->r13 = S32(ctx->r2 << 6);
    // 0x8001ABF8: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x8001ABFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8001AC00:
    // 0x8001AC00: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x8001AC04: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001AC08: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8001AC0C: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x8001AC10: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8001AC14: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8001AC18: bne         $at, $zero, L_8001AC00
    if (ctx->r1 != 0) {
        // 0x8001AC1C: sb          $a3, 0x4($t8)
        MEM_B(0X4, ctx->r24) = ctx->r7;
            goto L_8001AC00;
    }
    // 0x8001AC1C: sb          $a3, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r7;
    // 0x8001AC20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001AC24: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8001AC28: slti        $at, $t3, 0x5
    ctx->r1 = SIGNED(ctx->r11) < 0X5 ? 1 : 0;
    // 0x8001AC2C: bne         $at, $zero, L_8001ABEC
    if (ctx->r1 != 0) {
        // 0x8001AC30: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_8001ABEC;
    }
    // 0x8001AC30: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x8001AC34: lui         $t0, 0x8015
    ctx->r8 = S32(0X8015 << 16);
    // 0x8001AC38: addiu       $t0, $t0, -0x79A0
    ctx->r8 = ADD32(ctx->r8, -0X79A0);
    // 0x8001AC3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001AC40: addiu       $t2, $zero, 0x30
    ctx->r10 = ADD32(0, 0X30);
    // 0x8001AC44: addiu       $t1, $zero, 0x3C0
    ctx->r9 = ADD32(0, 0X3C0);
L_8001AC48:
    // 0x8001AC48: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AC4C: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x8001AC50: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8001AC54: sll         $t5, $t5, 6
    ctx->r13 = S32(ctx->r13 << 6);
    // 0x8001AC58: addu        $a2, $t0, $t5
    ctx->r6 = ADD32(ctx->r8, ctx->r13);
    // 0x8001AC5C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001AC60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8001AC64: mflo        $t4
    ctx->r12 = lo;
    // 0x8001AC68: addu        $a1, $t0, $t4
    ctx->r5 = ADD32(ctx->r8, ctx->r12);
    // 0x8001AC6C: sb          $a3, 0x2A($a1)
    MEM_B(0X2A, ctx->r5) = ctx->r7;
    // 0x8001AC70: sb          $a3, 0x2B($a1)
    MEM_B(0X2B, ctx->r5) = ctx->r7;
L_8001AC74:
    // 0x8001AC74: multu       $v1, $t2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AC78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001AC7C: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x8001AC80: slti        $at, $t9, 0x13
    ctx->r1 = SIGNED(ctx->r25) < 0X13 ? 1 : 0;
    // 0x8001AC84: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x8001AC88: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x8001AC8C: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x8001AC90: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8001AC94: mflo        $t6
    ctx->r14 = lo;
    // 0x8001AC98: addu        $a1, $a2, $t6
    ctx->r5 = ADD32(ctx->r6, ctx->r14);
    // 0x8001AC9C: sb          $t7, 0x2A($a1)
    MEM_B(0X2A, ctx->r5) = ctx->r15;
    // 0x8001ACA0: bne         $at, $zero, L_8001AC74
    if (ctx->r1 != 0) {
        // 0x8001ACA4: sb          $t8, 0x2B($a1)
        MEM_B(0X2B, ctx->r5) = ctx->r24;
            goto L_8001AC74;
    }
    // 0x8001ACA4: sb          $t8, 0x2B($a1)
    MEM_B(0X2B, ctx->r5) = ctx->r24;
    // 0x8001ACA8: multu       $t9, $t2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001ACAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ACB0: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x8001ACB4: slti        $at, $t5, 0x5
    ctx->r1 = SIGNED(ctx->r13) < 0X5 ? 1 : 0;
    // 0x8001ACB8: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x8001ACBC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8001ACC0: mflo        $t3
    ctx->r11 = lo;
    // 0x8001ACC4: addu        $a1, $a2, $t3
    ctx->r5 = ADD32(ctx->r6, ctx->r11);
    // 0x8001ACC8: sb          $t4, 0x2A($a1)
    MEM_B(0X2A, ctx->r5) = ctx->r12;
    // 0x8001ACCC: bne         $at, $zero, L_8001AC48
    if (ctx->r1 != 0) {
        // 0x8001ACD0: sb          $a3, 0x2B($a1)
        MEM_B(0X2B, ctx->r5) = ctx->r7;
            goto L_8001AC48;
    }
    // 0x8001ACD0: sb          $a3, 0x2B($a1)
    MEM_B(0X2B, ctx->r5) = ctx->r7;
    // 0x8001ACD4: jr          $ra
    // 0x8001ACD8: nop

    return;
    // 0x8001ACD8: nop

;}
RECOMP_FUNC void Audio_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DECC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001DED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001DED4: jal         0x80018FA4
    // 0x8001DED8: nop

    Audio_HandleReset(rdram, ctx);
        goto after_0;
    // 0x8001DED8: nop

    after_0:
    // 0x8001DEDC: bne         $v0, $zero, L_8001DF2C
    if (ctx->r2 != 0) {
        // 0x8001DEE0: nop
    
            goto L_8001DF2C;
    }
    // 0x8001DEE0: nop

    // 0x8001DEE4: jal         0x8001A988
    // 0x8001DEE8: nop

    Audio_ProcessSfxRequests(rdram, ctx);
        goto after_1;
    // 0x8001DEE8: nop

    after_1:
    // 0x8001DEEC: jal         0x8001831C
    // 0x8001DEF0: nop

    Audio_ProcessSeqCmds(rdram, ctx);
        goto after_2;
    // 0x8001DEF0: nop

    after_2:
    // 0x8001DEF4: jal         0x8001AAE4
    // 0x8001DEF8: nop

    Audio_PlayAllSfx(rdram, ctx);
        goto after_3;
    // 0x8001DEF8: nop

    after_3:
    // 0x8001DEFC: jal         0x8001BC20
    // 0x8001DF00: nop

    Audio_UpdatePlayerNoise(rdram, ctx);
        goto after_4;
    // 0x8001DF00: nop

    after_4:
    // 0x8001DF04: jal         0x8001AD44
    // 0x8001DF08: nop

    Audio_UpdateVoice(rdram, ctx);
        goto after_5;
    // 0x8001DF08: nop

    after_5:
    // 0x8001DF0C: jal         0x8001AF50
    // 0x8001DF10: nop

    Audio_UpdateUnkVoiceParam(rdram, ctx);
        goto after_6;
    // 0x8001DF10: nop

    after_6:
    // 0x8001DF14: jal         0x800185F8
    // 0x8001DF18: nop

    Audio_UpdateActiveSequences(rdram, ctx);
        goto after_7;
    // 0x8001DF18: nop

    after_7:
    // 0x8001DF1C: jal         0x80018EE0
    // 0x8001DF20: nop

    Audio_UpdateDelayedSeqCmds(rdram, ctx);
        goto after_8;
    // 0x8001DF20: nop

    after_8:
    // 0x8001DF24: jal         0x8001E920
    // 0x8001DF28: nop

    AudioThread_ScheduleProcessCmds(rdram, ctx);
        goto after_9;
    // 0x8001DF28: nop

    after_9:
L_8001DF2C:
    // 0x8001DF2C: lui         $v0, 0x800C
    ctx->r2 = S32(0X800C << 16);
    // 0x8001DF30: addiu       $v0, $v0, 0x5D40
    ctx->r2 = ADD32(ctx->r2, 0X5D40);
    // 0x8001DF34: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001DF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001DF3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001DF40: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8001DF44: jr          $ra
    // 0x8001DF48: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8001DF48: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void Effect_Effect344_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E014: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007E018: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8007E01C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007E020: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007E024: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8007E028: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8007E02C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8007E030: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8007E034: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8007E038: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8007E03C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8007E040: lw          $t6, -0x7B54($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7B54);
    // 0x8007E044: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007E048: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8007E04C: bne         $t6, $at, L_8007E0B8
    if (ctx->r14 != ctx->r1) {
        // 0x8007E050: addiu       $a3, $sp, 0x48
        ctx->r7 = ADD32(ctx->r29, 0X48);
            goto L_8007E0B8;
    }
    // 0x8007E050: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x8007E054: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8007E058: lwc1        $f6, 0x7D20($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7D20);
    // 0x8007E05C: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8007E060: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8007E064: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x8007E068: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8007E06C: jal         0x801B6E20
    // 0x8007E070: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    Ground_801B6E20(rdram, ctx);
        goto after_0;
    // 0x8007E070: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8007E074: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8007E078: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8007E07C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E080: lwc1        $f2, 0x745C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X745C);
    // 0x8007E084: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8007E088: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8007E08C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8007E090: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8007E094: swc1        $f16, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f16.u32l;
    // 0x8007E098: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007E09C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8007E0A0: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8007E0A4: swc1        $f6, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f6.u32l;
    // 0x8007E0A8: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8007E0AC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8007E0B0: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8007E0B4: swc1        $f16, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f16.u32l;
L_8007E0B8:
    // 0x8007E0B8: lh          $v0, 0x44($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X44);
    // 0x8007E0BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007E0C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007E0C4: beql        $v1, $v0, L_8007E0D8
    if (ctx->r3 == ctx->r2) {
        // 0x8007E0C8: lhu         $t8, 0x50($s2)
        ctx->r24 = MEM_HU(ctx->r18, 0X50);
            goto L_8007E0D8;
    }
    goto skip_0;
    // 0x8007E0C8: lhu         $t8, 0x50($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X50);
    skip_0:
    // 0x8007E0CC: bnel        $v0, $at, L_8007E178
    if (ctx->r2 != ctx->r1) {
        // 0x8007E0D0: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8007E178;
    }
    goto skip_1;
    // 0x8007E0D0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_1:
    // 0x8007E0D4: lhu         $t8, 0x50($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X50);
L_8007E0D8:
    // 0x8007E0D8: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8007E0DC: bnel        $v1, $t9, L_8007E178
    if (ctx->r3 != ctx->r25) {
        // 0x8007E0E0: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8007E178;
    }
    goto skip_2;
    // 0x8007E0E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_2:
    // 0x8007E0E4: jal         0x80004EB0
    // 0x8007E0E8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8007E0E8: nop

    after_1:
    // 0x8007E0EC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8007E0F0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8007E0F4: nop

    // 0x8007E0F8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8007E0FC: nop

    // 0x8007E100: bc1fl       L_8007E178
    if (!c1cs) {
        // 0x8007E104: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8007E178;
    }
    goto skip_3;
    // 0x8007E104: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_3:
    // 0x8007E108: jal         0x80004EB0
    // 0x8007E10C: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x8007E10C: nop

    after_2:
    // 0x8007E110: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8007E114: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007E118: lwc1        $f2, 0x70($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X70);
    // 0x8007E11C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8007E120: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8007E124: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8007E128: lwc1        $f4, 0x8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8007E12C: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E130: lwc1        $f6, 0x7460($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7460);
    // 0x8007E134: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8007E138: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8007E13C: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8007E140: add.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8007E144: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8007E148: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007E14C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8007E150: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x8007E154: lwc1        $f16, 0x7464($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7464);
    // 0x8007E158: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8007E15C: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8007E160: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8007E164: mul.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8007E168: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8007E16C: jal         0x8007D10C
    // 0x8007E170: nop

    Effect_FireSmoke2_Spawn3(rdram, ctx);
        goto after_3;
    // 0x8007E170: nop

    after_3:
    // 0x8007E174: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8007E178:
    // 0x8007E178: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8007E17C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8007E180: addiu       $s0, $s0, 0x130
    ctx->r16 = ADD32(ctx->r16, 0X130);
    // 0x8007E184: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8007E188: addiu       $s5, $zero, 0x64
    ctx->r21 = ADD32(0, 0X64);
    // 0x8007E18C: addiu       $s4, $zero, 0x158
    ctx->r20 = ADD32(0, 0X158);
    // 0x8007E190: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_8007E194:
    // 0x8007E194: lbu         $t0, 0x0($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X0);
    // 0x8007E198: bnel        $s3, $t0, L_8007E228
    if (ctx->r19 != ctx->r8) {
        // 0x8007E19C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007E228;
    }
    goto skip_4;
    // 0x8007E19C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_4:
    // 0x8007E1A0: lhu         $t1, 0x2($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X2);
    // 0x8007E1A4: bnel        $s4, $t1, L_8007E228
    if (ctx->r20 != ctx->r9) {
        // 0x8007E1A8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007E228;
    }
    goto skip_5;
    // 0x8007E1A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_5:
    // 0x8007E1AC: lw          $t2, 0x40($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X40);
    // 0x8007E1B0: beql        $s1, $t2, L_8007E228
    if (ctx->r17 == ctx->r10) {
        // 0x8007E1B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007E228;
    }
    goto skip_6;
    // 0x8007E1B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_6:
    // 0x8007E1B8: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8007E1BC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007E1C0: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8007E1C4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007E1C8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8007E1CC: nop

    // 0x8007E1D0: bc1fl       L_8007E228
    if (!c1cs) {
        // 0x8007E1D4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007E228;
    }
    goto skip_7;
    // 0x8007E1D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x8007E1D8: lwc1        $f16, 0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8007E1DC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007E1E0: sub.s       $f0, $f16, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8007E1E4: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007E1E8: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8007E1EC: nop

    // 0x8007E1F0: bc1fl       L_8007E228
    if (!c1cs) {
        // 0x8007E1F4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007E228;
    }
    goto skip_8;
    // 0x8007E1F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x8007E1F8: lwc1        $f18, 0x8($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8007E1FC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007E200: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8007E204: sub.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8007E208: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x8007E20C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8007E210: nop

    // 0x8007E214: bc1fl       L_8007E228
    if (!c1cs) {
        // 0x8007E218: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007E228;
    }
    goto skip_9;
    // 0x8007E218: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x8007E21C: jal         0x80060FBC
    // 0x8007E220: addiu       $a1, $s2, 0x80
    ctx->r5 = ADD32(ctx->r18, 0X80);
    Object_Kill(rdram, ctx);
        goto after_4;
    // 0x8007E220: addiu       $a1, $s2, 0x80
    ctx->r5 = ADD32(ctx->r18, 0X80);
    after_4:
    // 0x8007E224: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007E228:
    // 0x8007E228: bne         $s1, $s5, L_8007E194
    if (ctx->r17 != ctx->r21) {
        // 0x8007E22C: addiu       $s0, $s0, 0x8C
        ctx->r16 = ADD32(ctx->r16, 0X8C);
            goto L_8007E194;
    }
    // 0x8007E22C: addiu       $s0, $s0, 0x8C
    ctx->r16 = ADD32(ctx->r16, 0X8C);
    // 0x8007E230: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007E234: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8007E238: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8007E23C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8007E240: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E244: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8007E248: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8007E24C: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8007E250: jr          $ra
    // 0x8007E254: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007E254: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Effect_SmallRock_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80061958: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006195C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80061960: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80061964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80061968: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006196C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80061970: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80061974: jal         0x80061474
    // 0x80061978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Effect_Initialize(rdram, ctx);
        goto after_0;
    // 0x80061978: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8006197C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80061980: addiu       $t7, $zero, 0x15A
    ctx->r15 = ADD32(0, 0X15A);
    // 0x80061984: addiu       $t8, $zero, 0x32
    ctx->r24 = ADD32(0, 0X32);
    // 0x80061988: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8006198C: sh          $t7, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r15;
    // 0x80061990: sh          $t8, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r24;
    // 0x80061994: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x80061998: lwc1        $f4, 0x6430($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6430);
    // 0x8006199C: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x800619A0: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800619A4: swc1        $f4, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f4.u32l;
    // 0x800619A8: lw          $t9, -0x7DCC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7DCC);
    // 0x800619AC: addiu       $t0, $zero, 0xC8
    ctx->r8 = ADD32(0, 0XC8);
    // 0x800619B0: bnel        $t9, $at, L_800619E4
    if (ctx->r25 != ctx->r1) {
        // 0x800619B4: lwc1        $f16, 0x24($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
            goto L_800619E4;
    }
    goto skip_0;
    // 0x800619B4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800619B8: sh          $t0, 0x50($s0)
    MEM_H(0X50, ctx->r16) = ctx->r8;
    // 0x800619BC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800619C0: lwc1        $f6, 0x6434($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6434);
    // 0x800619C4: jal         0x80004EB0
    // 0x800619C8: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x800619C8: swc1        $f6, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->f6.u32l;
    after_1:
    // 0x800619CC: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800619D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800619D4: nop

    // 0x800619D8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800619DC: swc1        $f10, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f10.u32l;
    // 0x800619E0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
L_800619E4:
    // 0x800619E4: swc1        $f16, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f16.u32l;
    // 0x800619E8: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800619EC: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x800619F0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800619F4: jal         0x80004EB0
    // 0x800619F8: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x800619F8: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x800619FC: lui         $at, 0x43B4
    ctx->r1 = S32(0X43B4 << 16);
    // 0x80061A00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80061A04: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80061A08: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x80061A0C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80061A10: jal         0x800612B8
    // 0x80061A14: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    Object_SetInfo(rdram, ctx);
        goto after_3;
    // 0x80061A14: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    after_3:
    // 0x80061A18: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80061A1C: lbu         $t1, 0x7C98($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X7C98);
    // 0x80061A20: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80061A24: bnel        $t1, $zero, L_80061A3C
    if (ctx->r9 != 0) {
        // 0x80061A28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80061A3C;
    }
    goto skip_1;
    // 0x80061A28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80061A2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80061A30: nop

    // 0x80061A34: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x80061A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80061A3C:
    // 0x80061A3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80061A40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80061A44: jr          $ra
    // 0x80061A48: nop

    return;
    // 0x80061A48: nop

;}
RECOMP_FUNC void Audio_StopPlayerNoise(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CA24: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x8001CA28: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x8001CA2C: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x8001CA30: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8001CA34: addiu       $t7, $t7, -0x47B0
    ctx->r15 = ADD32(ctx->r15, -0X47B0);
    // 0x8001CA38: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8001CA3C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8001CA40: lbu         $v0, 0x6C($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X6C);
    // 0x8001CA44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001CA48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CA4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8001CA50: beq         $v0, $zero, L_8001CA74
    if (ctx->r2 == 0) {
        // 0x8001CA54: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8001CA74;
    }
    // 0x8001CA54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001CA58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CA5C: beq         $v0, $at, L_8001CAE0
    if (ctx->r2 == ctx->r1) {
        // 0x8001CA60: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001CAE0;
    }
    // 0x8001CA60: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001CA64: beq         $v0, $at, L_8001CAEC
    if (ctx->r2 == ctx->r1) {
        // 0x8001CA68: lui         $t1, 0x8018
        ctx->r9 = S32(0X8018 << 16);
            goto L_8001CAEC;
    }
    // 0x8001CA68: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8001CA6C: b           L_8001CB3C
    // 0x8001CA70: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
        goto L_8001CB3C;
    // 0x8001CA70: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_8001CA74:
    // 0x8001CA74: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x8001CA78: addu        $t9, $t9, $a3
    ctx->r25 = ADD32(ctx->r25, ctx->r7);
    // 0x8001CA7C: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8001CA80: lw          $t8, -0x7D80($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D80);
    // 0x8001CA84: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8001CA88: subu        $t9, $t9, $a3
    ctx->r25 = SUB32(ctx->r25, ctx->r7);
    // 0x8001CA8C: sll         $t9, $t9, 5
    ctx->r25 = S32(ctx->r25 << 5);
    // 0x8001CA90: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8001CA94: lbu         $t0, 0x478($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X478);
    // 0x8001CA98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001CA9C: lui         $a1, 0x1100
    ctx->r5 = S32(0X1100 << 16);
    // 0x8001CAA0: bne         $t0, $at, L_8001CAB4
    if (ctx->r8 != ctx->r1) {
        // 0x8001CAA4: ori         $a1, $a1, 0xB
        ctx->r5 = ctx->r5 | 0XB;
            goto L_8001CAB4;
    }
    // 0x8001CAA4: ori         $a1, $a1, 0xB
    ctx->r5 = ctx->r5 | 0XB;
    // 0x8001CAA8: lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // 0x8001CAAC: b           L_8001CABC
    // 0x8001CAB0: ori         $a2, $a2, 0xF020
    ctx->r6 = ctx->r6 | 0XF020;
        goto L_8001CABC;
    // 0x8001CAB0: ori         $a2, $a2, 0xF020
    ctx->r6 = ctx->r6 | 0XF020;
L_8001CAB4:
    // 0x8001CAB4: lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // 0x8001CAB8: ori         $a2, $a2, 0xF005
    ctx->r6 = ctx->r6 | 0XF005;
L_8001CABC:
    // 0x8001CABC: lw          $a0, 0x47C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X47C);
    // 0x8001CAC0: sb          $a3, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r7;
    // 0x8001CAC4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8001CAC8: jal         0x8001A55C
    // 0x8001CACC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_0;
    // 0x8001CACC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8001CAD0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CAD4: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8001CAD8: b           L_8001CB38
    // 0x8001CADC: lbu         $a3, 0x2B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2B);
        goto L_8001CB38;
    // 0x8001CADC: lbu         $a3, 0x2B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2B);
L_8001CAE0:
    // 0x8001CAE0: lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // 0x8001CAE4: b           L_8001CB38
    // 0x8001CAE8: ori         $a2, $a2, 0xF006
    ctx->r6 = ctx->r6 | 0XF006;
        goto L_8001CB38;
    // 0x8001CAE8: ori         $a2, $a2, 0xF006
    ctx->r6 = ctx->r6 | 0XF006;
L_8001CAEC:
    // 0x8001CAEC: sll         $t2, $a3, 2
    ctx->r10 = S32(ctx->r7 << 2);
    // 0x8001CAF0: addu        $t2, $t2, $a3
    ctx->r10 = ADD32(ctx->r10, ctx->r7);
    // 0x8001CAF4: lw          $t1, -0x7D80($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D80);
    // 0x8001CAF8: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8001CAFC: subu        $t2, $t2, $a3
    ctx->r10 = SUB32(ctx->r10, ctx->r7);
    // 0x8001CB00: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x8001CB04: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8001CB08: lui         $a2, 0x100
    ctx->r6 = S32(0X100 << 16);
    // 0x8001CB0C: lw          $a0, 0x47C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X47C);
    // 0x8001CB10: ori         $a2, $a2, 0xF022
    ctx->r6 = ctx->r6 | 0XF022;
    // 0x8001CB14: lui         $a1, 0x1100
    ctx->r5 = S32(0X1100 << 16);
    // 0x8001CB18: ori         $a1, $a1, 0x802C
    ctx->r5 = ctx->r5 | 0X802C;
    // 0x8001CB1C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8001CB20: sb          $a3, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r7;
    // 0x8001CB24: jal         0x8001A55C
    // 0x8001CB28: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_1;
    // 0x8001CB28: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8001CB2C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CB30: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8001CB34: lbu         $a3, 0x2B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X2B);
L_8001CB38:
    // 0x8001CB38: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
L_8001CB3C:
    // 0x8001CB3C: beq         $a2, $zero, L_8001CB70
    if (ctx->r6 == 0) {
        // 0x8001CB40: sb          $t4, 0x6C($v1)
        MEM_B(0X6C, ctx->r3) = ctx->r12;
            goto L_8001CB70;
    }
    // 0x8001CB40: sb          $t4, 0x6C($v1)
    MEM_B(0X6C, ctx->r3) = ctx->r12;
    // 0x8001CB44: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8001CB48: addu        $t6, $t6, $a3
    ctx->r14 = ADD32(ctx->r14, ctx->r7);
    // 0x8001CB4C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8001CB50: lw          $t5, -0x7D80($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7D80);
    // 0x8001CB54: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8001CB58: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x8001CB5C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x8001CB60: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8001CB64: lw          $a0, 0x47C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X47C);
    // 0x8001CB68: jal         0x8001A55C
    // 0x8001CB6C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    Audio_KillSfxBySourceAndId(rdram, ctx);
        goto after_2;
    // 0x8001CB6C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
L_8001CB70:
    // 0x8001CB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CB74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001CB78: jr          $ra
    // 0x8001CB7C: nop

    return;
    // 0x8001CB7C: nop

;}
RECOMP_FUNC void Camera_UpdateTank360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6848: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800B684C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B6850: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B6854: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B6858: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800B685C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6860: lwc1        $f6, -0x7558($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7558);
    // 0x800B6864: lwc1        $f4, 0xE4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XE4);
    // 0x800B6868: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B686C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B6870: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B6874: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800B6878: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800B687C: jal         0x80005D44
    // 0x800B6880: nop

    Matrix_RotateX(rdram, ctx);
        goto after_0;
    // 0x800B6880: nop

    after_0:
    // 0x800B6884: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6888: lwc1        $f4, -0x7554($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7554);
    // 0x800B688C: lwc1        $f10, 0xEC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XEC);
    // 0x800B6890: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B6894: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B6898: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800B689C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B68A0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B68A4: jal         0x80005FE0
    // 0x800B68A8: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_1;
    // 0x800B68A8: nop

    after_1:
    // 0x800B68AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B68B0: lwc1        $f10, -0x7550($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7550);
    // 0x800B68B4: lwc1        $f8, 0x134($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B68B8: lwc1        $f6, 0x114($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X114);
    // 0x800B68BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B68C0: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B68C4: lwc1        $f10, -0x754C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X754C);
    // 0x800B68C8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B68CC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B68D0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B68D4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B68D8: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800B68DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B68E0: jal         0x80005E90
    // 0x800B68E4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_2;
    // 0x800B68E4: nop

    after_2:
    // 0x800B68E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B68EC: lwc1        $f8, -0x7548($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7548);
    // 0x800B68F0: lwc1        $f4, 0x134($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B68F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B68F8: lwc1        $f6, -0x7544($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7544);
    // 0x800B68FC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800B6900: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B6904: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B6908: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800B690C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800B6910: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800B6914: jal         0x80005D44
    // 0x800B6918: nop

    Matrix_RotateX(rdram, ctx);
        goto after_3;
    // 0x800B6918: nop

    after_3:
    // 0x800B691C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800B6920: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800B6924: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B6928: swc1        $f8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f8.u32l;
    // 0x800B692C: lw          $t6, 0x238($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X238);
    // 0x800B6930: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800B6934: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800B6938: beql        $t6, $zero, L_800B6968
    if (ctx->r14 == 0) {
        // 0x800B693C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800B6968;
    }
    goto skip_0;
    // 0x800B693C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_0:
    // 0x800B6940: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x800B6944: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B6948: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x800B694C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B6950: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800B6954: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800B6958: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800B695C: b           L_800B6980
    // 0x800B6960: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
        goto L_800B6980;
    // 0x800B6960: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800B6964: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800B6968:
    // 0x800B6968: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x800B696C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B6970: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x800B6974: lwc1        $f4, 0x8C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x800B6978: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800B697C: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_800B6980:
    // 0x800B6980: jal         0x80006A20
    // 0x800B6984: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_4;
    // 0x800B6984: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    after_4:
    // 0x800B6988: lw          $t7, 0x238($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X238);
    // 0x800B698C: beql        $t7, $zero, L_800B69E8
    if (ctx->r15 == 0) {
        // 0x800B6990: lwc1        $f8, 0x17C($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X17C);
            goto L_800B69E8;
    }
    goto skip_1;
    // 0x800B6990: lwc1        $f8, 0x17C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X17C);
    skip_1:
    // 0x800B6994: lwc1        $f10, 0x17C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X17C);
    // 0x800B6998: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B699C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B69A0: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800B69A4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800B69A8: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B69AC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800B69B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B69B4: lwc1        $f4, -0x7540($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7540);
    // 0x800B69B8: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B69BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B69C0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800B69C4: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B69C8: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800B69CC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800B69D0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B69D4: jal         0x8009BC2C
    // 0x800B69D8: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x800B69D8: nop

    after_5:
    // 0x800B69DC: b           L_800B6A24
    // 0x800B69E0: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
        goto L_800B6A24;
    // 0x800B69E0: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800B69E4: lwc1        $f8, 0x17C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X17C);
L_800B69E8:
    // 0x800B69E8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800B69EC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B69F0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800B69F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B69F8: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800B69FC: lwc1        $f8, -0x753C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X753C);
    // 0x800B6A00: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x800B6A04: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6A08: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x800B6A0C: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800B6A10: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800B6A14: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800B6A18: jal         0x8009BC2C
    // 0x800B6A1C: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_6;
    // 0x800B6A1C: nop

    after_6:
    // 0x800B6A20: lwc1        $f2, 0x74($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X74);
L_800B6A24:
    // 0x800B6A24: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B6A28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6A2C: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B6A30: add.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800B6A34: lwc1        $f10, -0x7538($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7538);
    // 0x800B6A38: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800B6A3C: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x800B6A40: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800B6A44: lwc1        $f14, 0x2C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800B6A48: lwc1        $f12, 0x78($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800B6A4C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6A50: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800B6A54: add.s       $f8, $f12, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800B6A58: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B6A5C: addiu       $a0, $s0, 0x28
    ctx->r4 = ADD32(ctx->r16, 0X28);
    // 0x800B6A60: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x800B6A64: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800B6A68: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800B6A6C: lwc1        $f16, 0x7C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800B6A70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800B6A74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6A78: add.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800B6A7C: add.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f4.fl;
    // 0x800B6A80: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800B6A84: lwc1        $f0, 0x134($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X134);
    // 0x800B6A88: lwc1        $f18, 0xE8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XE8);
    // 0x800B6A8C: add.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800B6A90: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x800B6A94: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800B6A98: add.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f18.fl;
    // 0x800B6A9C: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x800B6AA0: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800B6AA4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800B6AA8: swc1        $f6, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f6.u32l;
    // 0x800B6AAC: lwc1        $f10, -0x7534($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7534);
    // 0x800B6AB0: jal         0x8009BC2C
    // 0x800B6AB4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_7;
    // 0x800B6AB4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800B6AB8: lwc1        $f8, 0x28($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B6ABC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B6AC0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800B6AC4: neg.s       $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = -ctx->f8.fl;
    // 0x800B6AC8: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800B6ACC: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x800B6AD0: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800B6AD4: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    // 0x800B6AD8: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800B6ADC: jal         0x80006A20
    // 0x800B6AE0: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x800B6AE0: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x800B6AE4: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B6AE8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B6AEC: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B6AF0: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B6AF4: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800B6AF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6AFC: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B6B00: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800B6B04: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800B6B08: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x800B6B0C: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800B6B10: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800B6B14: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B6B18: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6B1C: addiu       $a0, $s0, 0x40
    ctx->r4 = ADD32(ctx->r16, 0X40);
    // 0x800B6B20: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    // 0x800B6B24: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x800B6B28: lwc1        $f10, 0x50($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800B6B2C: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800B6B30: swc1        $f4, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f4.u32l;
    // 0x800B6B34: lwc1        $f8, -0x7530($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7530);
    // 0x800B6B38: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800B6B3C: jal         0x8009BC2C
    // 0x800B6B40: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x800B6B40: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x800B6B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6B48: lwc1        $f6, -0x752C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X752C);
    // 0x800B6B4C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B6B50: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6B54: addiu       $a0, $s0, 0x44
    ctx->r4 = ADD32(ctx->r16, 0X44);
    // 0x800B6B58: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B6B5C: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    // 0x800B6B60: jal         0x8009BC2C
    // 0x800B6B64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x800B6B64: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x800B6B68: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6B6C: lwc1        $f10, -0x7528($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7528);
    // 0x800B6B70: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B6B74: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6B78: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x800B6B7C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B6B80: lui         $a3, 0x4348
    ctx->r7 = S32(0X4348 << 16);
    // 0x800B6B84: jal         0x8009BC2C
    // 0x800B6B88: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x800B6B88: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x800B6B8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6B90: lwc1        $f8, -0x7524($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7524);
    // 0x800B6B94: lwc1        $f4, 0x12C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X12C);
    // 0x800B6B98: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B6B9C: lwc1        $f10, -0x7520($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7520);
    // 0x800B6BA0: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800B6BA4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x800B6BA8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800B6BAC: addiu       $a0, $s0, 0x34
    ctx->r4 = ADD32(ctx->r16, 0X34);
    // 0x800B6BB0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800B6BB4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x800B6BB8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800B6BBC: jal         0x8009BC2C
    // 0x800B6BC0: nop

    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x800B6BC0: nop

    after_12:
    // 0x800B6BC4: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800B6BC8: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B6BCC: beql        $t8, $zero, L_800B6BEC
    if (ctx->r24 == 0) {
        // 0x800B6BD0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800B6BEC;
    }
    goto skip_2;
    // 0x800B6BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x800B6BD4: swc1        $f4, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f4.u32l;
    // 0x800B6BD8: lwc1        $f8, 0x40($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B6BDC: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x800B6BE0: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B6BE4: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x800B6BE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800B6BEC:
    // 0x800B6BEC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B6BF0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800B6BF4: jr          $ra
    // 0x800B6BF8: nop

    return;
    // 0x800B6BF8: nop

;}
RECOMP_FUNC void Player_CheckPolyCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8304: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800A8308: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800A830C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800A8310: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800A8314: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x800A8318: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x800A831C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A8320: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800A8324: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800A8328: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800A832C: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800A8330: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A8334: lwc1        $f8, -0x7AFC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7AFC);
    // 0x800A8338: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A833C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A8340: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800A8344: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A8348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A834C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A8350: jal         0x80005E90
    // 0x800A8354: nop

    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x800A8354: nop

    after_0:
    // 0x800A8358: lwc1        $f16, 0xC0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800A835C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A8360: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A8364: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    // 0x800A8368: lwc1        $f18, 0xC4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC4);
    // 0x800A836C: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800A8370: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x800A8374: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x800A8378: lwc1        $f4, 0xC8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC8);
    // 0x800A837C: jal         0x80006A20
    // 0x800A8380: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_1;
    // 0x800A8380: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800A8384: lw          $v0, 0x1CC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A8388: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A838C: beq         $v0, $at, L_800A839C
    if (ctx->r2 == ctx->r1) {
        // 0x800A8390: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A839C;
    }
    // 0x800A8390: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A8394: bnel        $v0, $at, L_800A8484
    if (ctx->r2 != ctx->r1) {
        // 0x800A8398: lwc1        $f16, 0x2E0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
            goto L_800A8484;
    }
    goto skip_0;
    // 0x800A8398: lwc1        $f16, 0x2E0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
    skip_0:
L_800A839C:
    // 0x800A839C: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x800A83A0: lwc1        $f20, 0xA0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800A83A4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A83A8: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x800A83AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A83B0: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800A83B4: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x800A83B8: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x800A83BC: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800A83C0: sub.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x800A83C4: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x800A83C8: lwc1        $f18, 0x138($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X138);
    // 0x800A83CC: sub.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f20.fl;
    // 0x800A83D0: jal         0x80006A20
    // 0x800A83D4: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_2;
    // 0x800A83D4: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x800A83D8: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A83DC: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A83E0: lwc1        $f18, 0x74($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A83E4: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x800A83E8: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800A83EC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A83F0: add.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x800A83F4: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A83F8: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x800A83FC: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800A8400: addiu       $t7, $sp, 0x54
    ctx->r15 = ADD32(ctx->r29, 0X54);
    // 0x800A8404: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800A8408: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A840C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800A8410: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x800A8414: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800A8418: jal         0x800A8054
    // 0x800A841C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    Play_CheckPolyCollision(rdram, ctx);
        goto after_3;
    // 0x800A841C: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    after_3:
    // 0x800A8420: beq         $v0, $zero, L_800A8478
    if (ctx->r2 == 0) {
        // 0x800A8424: lwc1        $f6, 0x64($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800A8478;
    }
    // 0x800A8424: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800A8428: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x800A842C: jal         0x8009F768
    // 0x800A8430: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    Math_RadToDeg(rdram, ctx);
        goto after_4;
    // 0x800A8430: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    after_4:
    // 0x800A8434: swc1        $f0, 0x104($s0)
    MEM_W(0X104, ctx->r16) = ctx->f0.u32l;
    // 0x800A8438: jal         0x8009F768
    // 0x800A843C: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    Math_RadToDeg(rdram, ctx);
        goto after_5;
    // 0x800A843C: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    after_5:
    // 0x800A8440: lw          $t8, 0x1CC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1CC);
    // 0x800A8444: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A8448: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A844C: swc1        $f0, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = ctx->f0.u32l;
    // 0x800A8450: bne         $t8, $at, L_800A8468
    if (ctx->r24 != ctx->r1) {
        // 0x800A8454: swc1        $f8, 0xC4($s0)
        MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
            goto L_800A8468;
    }
    // 0x800A8454: swc1        $f8, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f8.u32l;
    // 0x800A8458: lui         $at, 0xC0A0
    ctx->r1 = S32(0XC0A0 << 16);
    // 0x800A845C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A8460: nop

    // 0x800A8464: swc1        $f10, 0xC4($s0)
    MEM_W(0XC4, ctx->r16) = ctx->f10.u32l;
L_800A8468:
    // 0x800A8468: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A846C: sw          $t9, 0x1D4($s0)
    MEM_W(0X1D4, ctx->r16) = ctx->r25;
    // 0x800A8470: b           L_800A86C8
    // 0x800A8474: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800A86C8;
    // 0x800A8474: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_800A8478:
    // 0x800A8478: b           L_800A86C8
    // 0x800A847C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800A86C8;
    // 0x800A847C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A8480: lwc1        $f16, 0x2E0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2E0);
L_800A8484:
    // 0x800A8484: lwc1        $f20, 0xA0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800A8488: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A848C: sub.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x800A8490: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A8494: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800A8498: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x800A849C: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x800A84A0: lwc1        $f4, 0x2E4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2E4);
    // 0x800A84A4: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x800A84A8: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800A84AC: lwc1        $f8, 0x2E8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2E8);
    // 0x800A84B0: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800A84B4: jal         0x80006A20
    // 0x800A84B8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_6;
    // 0x800A84B8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x800A84BC: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A84C0: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A84C4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A84C8: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800A84CC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800A84D0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A84D4: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800A84D8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A84DC: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
    // 0x800A84E0: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A84E4: addiu       $t1, $sp, 0x54
    ctx->r9 = ADD32(ctx->r29, 0X54);
    // 0x800A84E8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800A84EC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x800A84F0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800A84F4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800A84F8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800A84FC: jal         0x800A8054
    // 0x800A8500: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    Play_CheckPolyCollision(rdram, ctx);
        goto after_7;
    // 0x800A8500: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    after_7:
    // 0x800A8504: beql        $v0, $zero, L_800A8518
    if (ctx->r2 == 0) {
        // 0x800A8508: lwc1        $f16, 0x2EC($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
            goto L_800A8518;
    }
    goto skip_1;
    // 0x800A8508: lwc1        $f16, 0x2EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
    skip_1:
    // 0x800A850C: b           L_800A86C8
    // 0x800A8510: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800A86C8;
    // 0x800A8510: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A8514: lwc1        $f16, 0x2EC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2EC);
L_800A8518:
    // 0x800A8518: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A851C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A8520: sub.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x800A8524: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800A8528: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x800A852C: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x800A8530: lwc1        $f4, 0x2F0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2F0);
    // 0x800A8534: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x800A8538: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800A853C: lwc1        $f8, 0x2F4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2F4);
    // 0x800A8540: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800A8544: jal         0x80006A20
    // 0x800A8548: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_8;
    // 0x800A8548: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x800A854C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8550: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8554: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A8558: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800A855C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800A8560: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A8564: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800A8568: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A856C: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x800A8570: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A8574: addiu       $t3, $sp, 0x54
    ctx->r11 = ADD32(ctx->r29, 0X54);
    // 0x800A8578: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800A857C: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A8580: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800A8584: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800A8588: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800A858C: jal         0x800A8054
    // 0x800A8590: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    Play_CheckPolyCollision(rdram, ctx);
        goto after_9;
    // 0x800A8590: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    after_9:
    // 0x800A8594: beql        $v0, $zero, L_800A85A8
    if (ctx->r2 == 0) {
        // 0x800A8598: lwc1        $f16, 0x2D4($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2D4);
            goto L_800A85A8;
    }
    goto skip_2;
    // 0x800A8598: lwc1        $f16, 0x2D4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2D4);
    skip_2:
    // 0x800A859C: b           L_800A86C8
    // 0x800A85A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800A86C8;
    // 0x800A85A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800A85A4: lwc1        $f16, 0x2D4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2D4);
L_800A85A8:
    // 0x800A85A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A85AC: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A85B0: sub.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x800A85B4: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800A85B8: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x800A85BC: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x800A85C0: lwc1        $f4, 0x2D8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2D8);
    // 0x800A85C4: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x800A85C8: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800A85CC: lwc1        $f8, 0x2DC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2DC);
    // 0x800A85D0: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800A85D4: jal         0x80006A20
    // 0x800A85D8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_10;
    // 0x800A85D8: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x800A85DC: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A85E0: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A85E4: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A85E8: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800A85EC: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800A85F0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A85F4: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800A85F8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A85FC: addiu       $t4, $sp, 0x60
    ctx->r12 = ADD32(ctx->r29, 0X60);
    // 0x800A8600: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A8604: addiu       $t5, $sp, 0x54
    ctx->r13 = ADD32(ctx->r29, 0X54);
    // 0x800A8608: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800A860C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A8610: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800A8614: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800A8618: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800A861C: jal         0x800A8054
    // 0x800A8620: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    Play_CheckPolyCollision(rdram, ctx);
        goto after_11;
    // 0x800A8620: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    after_11:
    // 0x800A8624: beql        $v0, $zero, L_800A8638
    if (ctx->r2 == 0) {
        // 0x800A8628: lwc1        $f16, 0x2C8($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
            goto L_800A8638;
    }
    goto skip_3;
    // 0x800A8628: lwc1        $f16, 0x2C8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
    skip_3:
    // 0x800A862C: b           L_800A86C8
    // 0x800A8630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800A86C8;
    // 0x800A8630: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800A8634: lwc1        $f16, 0x2C8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X2C8);
L_800A8638:
    // 0x800A8638: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x800A863C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x800A8640: sub.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x800A8644: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x800A8648: addiu       $a2, $sp, 0x6C
    ctx->r6 = ADD32(ctx->r29, 0X6C);
    // 0x800A864C: swc1        $f18, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f18.u32l;
    // 0x800A8650: lwc1        $f4, 0x2CC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2CC);
    // 0x800A8654: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x800A8658: swc1        $f6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f6.u32l;
    // 0x800A865C: lwc1        $f8, 0x2D0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2D0);
    // 0x800A8660: sub.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800A8664: jal         0x80006A20
    // 0x800A8668: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    Matrix_MultVec3fNoTranslate(rdram, ctx);
        goto after_12;
    // 0x800A8668: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    after_12:
    // 0x800A866C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8670: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8674: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800A8678: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800A867C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800A8680: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800A8684: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800A8688: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800A868C: addiu       $t6, $sp, 0x60
    ctx->r14 = ADD32(ctx->r29, 0X60);
    // 0x800A8690: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A8694: addiu       $t7, $sp, 0x54
    ctx->r15 = ADD32(ctx->r29, 0X54);
    // 0x800A8698: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800A869C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A86A0: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800A86A4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800A86A8: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x800A86AC: jal         0x800A8054
    // 0x800A86B0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    Play_CheckPolyCollision(rdram, ctx);
        goto after_13;
    // 0x800A86B0: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    after_13:
    // 0x800A86B4: beql        $v0, $zero, L_800A86C8
    if (ctx->r2 == 0) {
        // 0x800A86B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A86C8;
    }
    goto skip_4;
    // 0x800A86B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x800A86BC: b           L_800A86C8
    // 0x800A86C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800A86C8;
    // 0x800A86C0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A86C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A86C8:
    // 0x800A86C8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800A86CC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800A86D0: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800A86D4: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800A86D8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800A86DC: jr          $ra
    // 0x800A86E0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800A86E0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
