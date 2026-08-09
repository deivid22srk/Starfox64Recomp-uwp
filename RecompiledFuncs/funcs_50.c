#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Map_PathChange_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A4AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A4AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A4AF0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A4AF4: lw          $v0, -0x26B4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26B4);
    // 0x801A4AF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801A4AFC: beq         $v0, $zero, L_801A4B20
    if (ctx->r2 == 0) {
        // 0x801A4B00: nop
    
            goto L_801A4B20;
    }
    // 0x801A4B00: nop

    // 0x801A4B04: beq         $v0, $v1, L_801A4B30
    if (ctx->r2 == ctx->r3) {
        // 0x801A4B08: lui         $t6, 0x801D
        ctx->r14 = S32(0X801D << 16);
            goto L_801A4B30;
    }
    // 0x801A4B08: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A4B0C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A4B10: beq         $v0, $at, L_801A4BE0
    if (ctx->r2 == ctx->r1) {
        // 0x801A4B14: lui         $a1, 0x801D
        ctx->r5 = S32(0X801D << 16);
            goto L_801A4BE0;
    }
    // 0x801A4B14: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A4B18: b           L_801A4D00
    // 0x801A4B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A4D00;
    // 0x801A4B1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A4B20:
    // 0x801A4B20: jal         0x801A4D7C
    // 0x801A4B24: nop

    Map_PathChange_Input(rdram, ctx);
        goto after_0;
    // 0x801A4B24: nop

    after_0:
    // 0x801A4B28: b           L_801A4D00
    // 0x801A4B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801A4D00;
    // 0x801A4B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A4B30:
    // 0x801A4B30: lw          $t6, -0x1024($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1024);
    // 0x801A4B34: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A4B38: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A4B3C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801A4B40: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801A4B44: lw          $t8, -0x1000($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1000);
    // 0x801A4B48: bnel        $t8, $zero, L_801A4D00
    if (ctx->r24 != 0) {
        // 0x801A4B4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801A4D00;
    }
    goto skip_0;
    // 0x801A4B4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801A4B50: lw          $t9, -0x1030($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1030);
    // 0x801A4B54: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801A4B58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4B5C: beq         $t9, $zero, L_801A4BC4
    if (ctx->r25 == 0) {
        // 0x801A4B60: nop
    
            goto L_801A4BC4;
    }
    // 0x801A4B60: nop

    // 0x801A4B64: lw          $t0, 0x78A0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X78A0);
    // 0x801A4B68: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x801A4B6C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x801A4B70: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801A4B74: lh          $t2, 0x1AA0($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X1AA0);
    // 0x801A4B78: beq         $t2, $zero, L_801A4BB0
    if (ctx->r10 == 0) {
        // 0x801A4B7C: nop
    
            goto L_801A4BB0;
    }
    // 0x801A4B7C: nop

    // 0x801A4B80: jal         0x8001D520
    // 0x801A4B84: nop

    Audio_PlayDeathSequence(rdram, ctx);
        goto after_1;
    // 0x801A4B84: nop

    after_1:
    // 0x801A4B88: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A4B8C: addiu       $a1, $a1, -0x2634
    ctx->r5 = ADD32(ctx->r5, -0X2634);
    // 0x801A4B90: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801A4B94: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x801A4B98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4B9C: sw          $zero, -0x2630($at)
    MEM_W(-0X2630, ctx->r1) = 0;
    // 0x801A4BA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4BA4: addiu       $t3, $zero, 0x78
    ctx->r11 = ADD32(0, 0X78);
    // 0x801A4BA8: b           L_801A4BC8
    // 0x801A4BAC: sw          $t3, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = ctx->r11;
        goto L_801A4BC8;
    // 0x801A4BAC: sw          $t3, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = ctx->r11;
L_801A4BB0:
    // 0x801A4BB0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4BB4: sw          $v1, -0x262C($at)
    MEM_W(-0X262C, ctx->r1) = ctx->r3;
    // 0x801A4BB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4BBC: b           L_801A4BC8
    // 0x801A4BC0: sw          $zero, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = 0;
        goto L_801A4BC8;
    // 0x801A4BC0: sw          $zero, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = 0;
L_801A4BC4:
    // 0x801A4BC4: sw          $zero, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = 0;
L_801A4BC8:
    // 0x801A4BC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4BCC: sw          $zero, -0x103C($at)
    MEM_W(-0X103C, ctx->r1) = 0;
    // 0x801A4BD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4BD4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801A4BD8: b           L_801A4CFC
    // 0x801A4BDC: sw          $t4, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r12;
        goto L_801A4CFC;
    // 0x801A4BDC: sw          $t4, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = ctx->r12;
L_801A4BE0:
    // 0x801A4BE0: addiu       $a1, $a1, -0x2634
    ctx->r5 = ADD32(ctx->r5, -0X2634);
    // 0x801A4BE4: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x801A4BE8: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A4BEC: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A4BF0: beq         $t5, $zero, L_801A4C2C
    if (ctx->r13 == 0) {
        // 0x801A4BF4: lui         $t3, 0x801D
        ctx->r11 = S32(0X801D << 16);
            goto L_801A4C2C;
    }
    // 0x801A4BF4: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801A4BF8: lw          $t6, -0x2648($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2648);
    // 0x801A4BFC: addiu       $at, $zero, 0x6E
    ctx->r1 = ADD32(0, 0X6E);
    // 0x801A4C00: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A4C04: bne         $t6, $at, L_801A4C2C
    if (ctx->r14 != ctx->r1) {
        // 0x801A4C08: nop
    
            goto L_801A4C2C;
    }
    // 0x801A4C08: nop

    // 0x801A4C0C: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x801A4C10: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x801A4C14: addiu       $t9, $t9, 0x1AA0
    ctx->r25 = ADD32(ctx->r25, 0X1AA0);
    // 0x801A4C18: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x801A4C1C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x801A4C20: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x801A4C24: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x801A4C28: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_801A4C2C:
    // 0x801A4C2C: lw          $t2, -0x2648($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2648);
    // 0x801A4C30: bnel        $t2, $zero, L_801A4D00
    if (ctx->r10 != 0) {
        // 0x801A4C34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801A4D00;
    }
    goto skip_1;
    // 0x801A4C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801A4C38: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x801A4C3C: lw          $t3, -0x26C4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X26C4);
    // 0x801A4C40: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A4C44: lw          $a0, -0x1024($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1024);
    // 0x801A4C48: beq         $t3, $zero, L_801A4C54
    if (ctx->r11 == 0) {
        // 0x801A4C4C: nop
    
            goto L_801A4C54;
    }
    // 0x801A4C4C: nop

    // 0x801A4C50: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_801A4C54:
    // 0x801A4C54: jal         0x801A4D0C
    // 0x801A4C58: nop

    Map_PathChange_UpdateEntry(rdram, ctx);
        goto after_2;
    // 0x801A4C58: nop

    after_2:
    // 0x801A4C5C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A4C60: lw          $t4, -0x1024($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1024);
    // 0x801A4C64: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x801A4C68: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801A4C6C: bne         $t4, $zero, L_801A4CEC
    if (ctx->r12 != 0) {
        // 0x801A4C70: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A4CEC;
    }
    // 0x801A4C70: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4C74: lw          $t5, 0x78B0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X78B0);
    // 0x801A4C78: lw          $t6, 0x78B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78B4);
    // 0x801A4C7C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A4C80: sw          $t5, 0x7C58($at)
    MEM_W(0X7C58, ctx->r1) = ctx->r13;
    // 0x801A4C84: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A4C88: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801A4C8C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801A4C90: sw          $t6, 0x7C5C($at)
    MEM_W(0X7C5C, ctx->r1) = ctx->r14;
    // 0x801A4C94: addiu       $t8, $t8, 0x78B0
    ctx->r24 = ADD32(ctx->r24, 0X78B0);
    // 0x801A4C98: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x801A4C9C: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x801A4CA0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801A4CA4: addiu       $t7, $t7, 0x7C58
    ctx->r15 = ADD32(ctx->r15, 0X7C58);
    // 0x801A4CA8: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x801A4CAC: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x801A4CB0: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x801A4CB4: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x801A4CB8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801A4CBC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4CC0: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801A4CC4: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x801A4CC8: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x801A4CCC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801A4CD0: sw          $zero, -0x1038($at)
    MEM_W(-0X1038, ctx->r1) = 0;
    // 0x801A4CD4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4CD8: sw          $zero, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = 0;
    // 0x801A4CDC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4CE0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801A4CE4: b           L_801A4CF4
    // 0x801A4CE8: sw          $t3, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r11;
        goto L_801A4CF4;
    // 0x801A4CE8: sw          $t3, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r11;
L_801A4CEC:
    // 0x801A4CEC: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801A4CF0: sw          $t4, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r12;
L_801A4CF4:
    // 0x801A4CF4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4CF8: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
L_801A4CFC:
    // 0x801A4CFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A4D00:
    // 0x801A4D00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A4D04: jr          $ra
    // 0x801A4D08: nop

    return;
    // 0x801A4D08: nop

;}
RECOMP_FUNC void Option_VsSelectionArrows_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B6D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019B6DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019B6E0: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x8019B6E4: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8019B6E8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8019B6EC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019B6F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B6F4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B6F8: jal         0x800B8DD0
    // 0x8019B6FC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019B6FC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8019B700: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B704: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B708: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B70C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B710: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8019B714: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8019B718: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x8019B71C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8019B720: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8019B724: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8019B728: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8019B72C: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x8019B730: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8019B734: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8019B738: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8019B73C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8019B740: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x8019B744: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8019B748: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8019B74C: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8019B750: ori         $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 | 0XFF;
    // 0x8019B754: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8019B758: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019B75C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019B760: addiu       $a1, $a1, 0x4010
    ctx->r5 = ADD32(ctx->r5, 0X4010);
    // 0x8019B764: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8019B768: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8019B76C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019B770: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019B774: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019B778: jal         0x8009E1E8
    // 0x8019B77C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8_MirX(rdram, ctx);
        goto after_1;
    // 0x8019B77C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8019B780: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019B784: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8019B788: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B78C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B790: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019B794: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8019B798: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B79C: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x8019B7A0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B7A4: addiu       $a1, $a1, 0x4010
    ctx->r5 = ADD32(ctx->r5, 0X4010);
    // 0x8019B7A8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019B7AC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8019B7B0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8019B7B4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019B7B8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019B7BC: jal         0x8009D994
    // 0x8019B7C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x8019B7C0: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8019B7C4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019B7C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019B7CC: jr          $ra
    // 0x8019B7D0: nop

    return;
    // 0x8019B7D0: nop

;}
RECOMP_FUNC void Map_PathLinePos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ACD90: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x801ACD94: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801ACD98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801ACD9C: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x801ACDA0: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x801ACDA4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801ACDA8: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x801ACDAC: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x801ACDB0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801ACDB4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801ACDB8: addiu       $t7, $t7, -0x2E8
    ctx->r15 = ADD32(ctx->r15, -0X2E8);
    // 0x801ACDBC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801ACDC0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801ACDC4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x801ACDC8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x801ACDCC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x801ACDD0: bne         $t0, $v1, L_801ACDE4
    if (ctx->r8 != ctx->r3) {
        // 0x801ACDD4: addiu       $t1, $zero, 0xE
        ctx->r9 = ADD32(0, 0XE);
            goto L_801ACDE4;
    }
    // 0x801ACDD4: addiu       $t1, $zero, 0xE
    ctx->r9 = ADD32(0, 0XE);
    // 0x801ACDD8: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801ACDDC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801ACDE0: nop

L_801ACDE4:
    // 0x801ACDE4: bne         $a1, $v1, L_801ACDF8
    if (ctx->r5 != ctx->r3) {
        // 0x801ACDE8: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_801ACDF8;
    }
    // 0x801ACDE8: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x801ACDEC: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801ACDF0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801ACDF4: nop

L_801ACDF8:
    // 0x801ACDF8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801ACDFC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801ACE00: bne         $t1, $v1, L_801ACE14
    if (ctx->r9 != ctx->r3) {
        // 0x801ACE04: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_801ACE14;
    }
    // 0x801ACE04: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x801ACE08: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801ACE0C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801ACE10: nop

L_801ACE14:
    // 0x801ACE14: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801ACE18: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801ACE1C: bne         $v1, $zero, L_801ACE28
    if (ctx->r3 != 0) {
        // 0x801ACE20: addiu       $t4, $zero, 0x3
        ctx->r12 = ADD32(0, 0X3);
            goto L_801ACE28;
    }
    // 0x801ACE20: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801ACE24: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
L_801ACE28:
    // 0x801ACE28: bne         $t2, $v1, L_801ACE34
    if (ctx->r10 != ctx->r3) {
        // 0x801ACE2C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_801ACE34;
    }
    // 0x801ACE2C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801ACE30: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
L_801ACE34:
    // 0x801ACE34: bne         $t3, $v1, L_801ACE40
    if (ctx->r11 != ctx->r3) {
        // 0x801ACE38: nop
    
            goto L_801ACE40;
    }
    // 0x801ACE38: nop

    // 0x801ACE3C: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
L_801ACE40:
    // 0x801ACE40: bne         $t4, $v1, L_801ACE4C
    if (ctx->r12 != ctx->r3) {
        // 0x801ACE44: nop
    
            goto L_801ACE4C;
    }
    // 0x801ACE44: nop

    // 0x801ACE48: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
L_801ACE4C:
    // 0x801ACE4C: bne         $t5, $v1, L_801ACE5C
    if (ctx->r13 != ctx->r3) {
        // 0x801ACE50: lui         $at, 0x4496
        ctx->r1 = S32(0X4496 << 16);
            goto L_801ACE5C;
    }
    // 0x801ACE50: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801ACE54: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801ACE58: nop

L_801ACE5C:
    // 0x801ACE5C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801ACE60: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x801ACE64: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801ACE68: bnel        $v1, $at, L_801ACE78
    if (ctx->r3 != ctx->r1) {
        // 0x801ACE6C: lw          $a0, 0x8($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X8);
            goto L_801ACE78;
    }
    goto skip_0;
    // 0x801ACE6C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x801ACE70: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x801ACE74: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
L_801ACE78:
    // 0x801ACE78: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x801ACE7C: bne         $a1, $a0, L_801ACE88
    if (ctx->r5 != ctx->r4) {
        // 0x801ACE80: nop
    
            goto L_801ACE88;
    }
    // 0x801ACE80: nop

    // 0x801ACE84: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_801ACE88:
    // 0x801ACE88: bne         $t0, $a0, L_801ACE98
    if (ctx->r8 != ctx->r4) {
        // 0x801ACE8C: lui         $at, 0x4248
        ctx->r1 = S32(0X4248 << 16);
            goto L_801ACE98;
    }
    // 0x801ACE8C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801ACE90: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801ACE94: nop

L_801ACE98:
    // 0x801ACE98: bne         $t1, $a0, L_801ACEA4
    if (ctx->r9 != ctx->r4) {
        // 0x801ACE9C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801ACEA4;
    }
    // 0x801ACE9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801ACEA0: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_801ACEA4:
    // 0x801ACEA4: bne         $a0, $zero, L_801ACEB0
    if (ctx->r4 != 0) {
        // 0x801ACEA8: addiu       $t1, $zero, 0x38
        ctx->r9 = ADD32(0, 0X38);
            goto L_801ACEB0;
    }
    // 0x801ACEA8: addiu       $t1, $zero, 0x38
    ctx->r9 = ADD32(0, 0X38);
    // 0x801ACEAC: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
L_801ACEB0:
    // 0x801ACEB0: bne         $t2, $a0, L_801ACEBC
    if (ctx->r10 != ctx->r4) {
        // 0x801ACEB4: nop
    
            goto L_801ACEBC;
    }
    // 0x801ACEB4: nop

    // 0x801ACEB8: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_801ACEBC:
    // 0x801ACEBC: bne         $t3, $a0, L_801ACEC8
    if (ctx->r11 != ctx->r4) {
        // 0x801ACEC0: nop
    
            goto L_801ACEC8;
    }
    // 0x801ACEC0: nop

    // 0x801ACEC4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_801ACEC8:
    // 0x801ACEC8: bne         $t4, $a0, L_801ACED4
    if (ctx->r12 != ctx->r4) {
        // 0x801ACECC: nop
    
            goto L_801ACED4;
    }
    // 0x801ACECC: nop

    // 0x801ACED0: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_801ACED4:
    // 0x801ACED4: bne         $t5, $a0, L_801ACEE0
    if (ctx->r13 != ctx->r4) {
        // 0x801ACED8: nop
    
            goto L_801ACEE0;
    }
    // 0x801ACED8: nop

    // 0x801ACEDC: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
L_801ACEE0:
    // 0x801ACEE0: bnel        $a0, $at, L_801ACEF0
    if (ctx->r4 != ctx->r1) {
        // 0x801ACEE4: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_801ACEF0;
    }
    goto skip_1;
    // 0x801ACEE4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    skip_1:
    // 0x801ACEE8: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x801ACEEC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
L_801ACEF0:
    // 0x801ACEF0: bne         $a0, $at, L_801ACF00
    if (ctx->r4 != ctx->r1) {
        // 0x801ACEF4: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_801ACF00;
    }
    // 0x801ACEF4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801ACEF8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801ACEFC: nop

L_801ACF00:
    // 0x801ACF00: multu       $a0, $t1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801ACF04: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801ACF08: addiu       $t0, $t0, -0xB60
    ctx->r8 = ADD32(ctx->r8, -0XB60);
    // 0x801ACF0C: mflo        $t8
    ctx->r24 = lo;
    // 0x801ACF10: addu        $v0, $t0, $t8
    ctx->r2 = ADD32(ctx->r8, ctx->r24);
    // 0x801ACF14: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x801ACF18: multu       $v1, $t1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801ACF1C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x801ACF20: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x801ACF24: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x801ACF28: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x801ACF2C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801ACF30: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801ACF34: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801ACF38: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x801ACF3C: mflo        $t9
    ctx->r25 = lo;
    // 0x801ACF40: addu        $a1, $t0, $t9
    ctx->r5 = ADD32(ctx->r8, ctx->r25);
    // 0x801ACF44: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x801ACF48: lwc1        $f12, 0x14($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X14);
    // 0x801ACF4C: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x801ACF50: sub.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x801ACF54: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x801ACF58: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x801ACF5C: sub.s       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x801ACF60: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801ACF64: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801ACF68: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801ACF6C: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801ACF70: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x801ACF74: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x801ACF78: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801ACF7C: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x801ACF80: add.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801ACF84: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801ACF88: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x801ACF8C: mul.s       $f8, $f4, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x801ACF90: div.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801ACF94: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x801ACF98: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801ACF9C: div.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x801ACFA0: mul.s       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801ACFA4: nop

    // 0x801ACFA8: mul.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801ACFAC: add.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x801ACFB0: add.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x801ACFB4: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x801ACFB8: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x801ACFBC: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801ACFC0: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x801ACFC4: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801ACFC8: mul.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x801ACFCC: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801ACFD0: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x801ACFD4: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801ACFD8: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x801ACFDC: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x801ACFE0: neg.s       $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = -ctx->f16.fl;
    // 0x801ACFE4: add.s       $f22, $f10, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801ACFE8: div.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801ACFEC: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801ACFF0: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x801ACFF4: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801ACFF8: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801ACFFC: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x801AD000: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801AD004: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AD008: mul.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x801AD00C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x801AD010: swc1        $f6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f6.u32l;
    // 0x801AD014: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x801AD018: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801AD01C: swc1        $f12, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f12.u32l;
    // 0x801AD020: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
    // 0x801AD024: swc1        $f22, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f22.u32l;
    // 0x801AD028: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x801AD02C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
    // 0x801AD030: lwc1        $f6, 0x60($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X60);
    // 0x801AD034: swc1        $f6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f6.u32l;
    // 0x801AD038: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    // 0x801AD03C: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x801AD040: jr          $ra
    // 0x801AD044: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x801AD044: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Map_PathInfo_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AA434: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x801AA438: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x801AA43C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x801AA440: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x801AA444: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x801AA448: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x801AA44C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x801AA450: mtc1        $a1, $f28
    ctx->f28.u32l = ctx->r5;
    // 0x801AA454: mtc1        $a2, $f30
    ctx->f30.u32l = ctx->r6;
    // 0x801AA458: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x801AA45C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x801AA460: addiu       $s7, $s7, 0x7E64
    ctx->r23 = ADD32(ctx->r23, 0X7E64);
    // 0x801AA464: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x801AA468: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x801AA46C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x801AA470: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x801AA474: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x801AA478: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x801AA47C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x801AA480: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x801AA484: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801AA488: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801AA48C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801AA490: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x801AA494: jal         0x800B8DD0
    // 0x801AA498: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801AA498: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x801AA49C: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x801AA4A0: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x801AA4A4: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x801AA4A8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801AA4AC: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x801AA4B0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801AA4B4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801AA4B8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801AA4BC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801AA4C0: addiu       $t0, $t0, -0x60C
    ctx->r8 = ADD32(ctx->r8, -0X60C);
    // 0x801AA4C4: sll         $t9, $s1, 2
    ctx->r25 = S32(ctx->r17 << 2);
    // 0x801AA4C8: addu        $s0, $t9, $t0
    ctx->r16 = ADD32(ctx->r25, ctx->r8);
    // 0x801AA4CC: jal         0x800A13EC
    // 0x801AA4D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Graphics_GetSmallTextWidth(rdram, ctx);
        goto after_1;
    // 0x801AA4D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_1:
    // 0x801AA4D4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x801AA4D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AA4DC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801AA4E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801AA4E4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801AA4E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AA4EC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801AA4F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AA4F4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801AA4F8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801AA4FC: add.s       $f18, $f28, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f28.fl + ctx->f16.fl;
    // 0x801AA500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AA504: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x801AA508: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801AA50C: sub.s       $f16, $f30, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x801AA510: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x801AA514: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801AA518: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x801AA51C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801AA520: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AA524: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801AA528: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x801AA52C: jal         0x800A1200
    // 0x801AA530: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_2;
    // 0x801AA530: nop

    after_2:
    // 0x801AA534: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801AA538: addiu       $t4, $t4, 0x7B70
    ctx->r12 = ADD32(ctx->r12, 0X7B70);
    // 0x801AA53C: sll         $s2, $s3, 2
    ctx->r18 = S32(ctx->r19 << 2);
    // 0x801AA540: addu        $s0, $s2, $t4
    ctx->r16 = ADD32(ctx->r18, ctx->r12);
    // 0x801AA544: jal         0x8008BCBC
    // 0x801AA548: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    HUD_CountDigits(rdram, ctx);
        goto after_3;
    // 0x801AA548: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_3:
    // 0x801AA54C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x801AA550: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x801AA554: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AA558: addiu       $t6, $t5, -0x8
    ctx->r14 = ADD32(ctx->r13, -0X8);
    // 0x801AA55C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x801AA560: add.s       $f4, $f28, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f28.fl + ctx->f10.fl;
    // 0x801AA564: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801AA568: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AA56C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801AA570: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x801AA574: add.s       $f6, $f30, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f30.fl + ctx->f10.fl;
    // 0x801AA578: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x801AA57C: add.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x801AA580: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801AA584: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AA588: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x801AA58C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AA590: jal         0x8009FEA0
    // 0x801AA594: nop

    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_4;
    // 0x801AA594: nop

    after_4:
    // 0x801AA598: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801AA59C: lhu         $v0, 0x1A34($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A34);
    // 0x801AA5A0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801AA5A4: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801AA5A8: bne         $v0, $at, L_801AA5B8
    if (ctx->r2 != ctx->r1) {
        // 0x801AA5AC: lui         $s1, 0xFF
        ctx->r17 = S32(0XFF << 16);
            goto L_801AA5B8;
    }
    // 0x801AA5AC: lui         $s1, 0xFF
    ctx->r17 = S32(0XFF << 16);
    // 0x801AA5B0: lw          $v1, 0x7B48($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7B48);
    // 0x801AA5B4: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
L_801AA5B8:
    // 0x801AA5B8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801AA5BC: beq         $v0, $at, L_801AA5D0
    if (ctx->r2 == ctx->r1) {
        // 0x801AA5C0: lw          $v1, 0x8C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X8C);
            goto L_801AA5D0;
    }
    // 0x801AA5C0: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x801AA5C4: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801AA5C8: bnel        $v0, $at, L_801AA5E0
    if (ctx->r2 != ctx->r1) {
        // 0x801AA5CC: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_801AA5E0;
    }
    goto skip_0;
    // 0x801AA5CC: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
L_801AA5D0:
    // 0x801AA5D0: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801AA5D4: lw          $v1, 0x7B48($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7B48);
    // 0x801AA5D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801AA5DC: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
L_801AA5E0:
    // 0x801AA5E0: beq         $at, $zero, L_801AA730
    if (ctx->r1 == 0) {
        // 0x801AA5E4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801AA730;
    }
    // 0x801AA5E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801AA5E8: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801AA5EC: addiu       $t9, $t9, 0x7B50
    ctx->r25 = ADD32(ctx->r25, 0X7B50);
    // 0x801AA5F0: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801AA5F4: addu        $t0, $s2, $t9
    ctx->r8 = ADD32(ctx->r18, ctx->r25);
    // 0x801AA5F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801AA5FC: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801AA600: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // 0x801AA604: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
L_801AA608:
    // 0x801AA608: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x801AA60C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x801AA610: and         $t3, $t2, $s1
    ctx->r11 = ctx->r10 & ctx->r17;
    // 0x801AA614: beql        $t3, $zero, L_801AA720
    if (ctx->r11 == 0) {
        // 0x801AA618: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801AA720;
    }
    goto skip_1;
    // 0x801AA618: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x801AA61C: trunc.w.s   $f10, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    ctx->f10.u32l = TRUNC_W_S(ctx->f30.fl);
    // 0x801AA620: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801AA624: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AA628: trunc.w.s   $f16, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    ctx->f16.u32l = TRUNC_W_S(ctx->f28.fl);
    // 0x801AA62C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x801AA630: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801AA634: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x801AA638: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x801AA63C: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x801AA640: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x801AA644: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801AA648: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x801AA64C: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801AA650: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x801AA654: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x801AA658: cvt.s.w     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801AA65C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AA660: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801AA664: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AA668: addiu       $t2, $t2, 0x6AD0
    ctx->r10 = ADD32(ctx->r10, 0X6AD0);
    // 0x801AA66C: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801AA670: addiu       $t6, $t6, 0x6AE8
    ctx->r14 = ADD32(ctx->r14, 0X6AE8);
    // 0x801AA674: addiu       $t5, $t5, 0x6ADC
    ctx->r13 = ADD32(ctx->r13, 0X6ADC);
    // 0x801AA678: addiu       $t4, $t4, 0x6AF4
    ctx->r12 = ADD32(ctx->r12, 0X6AF4);
    // 0x801AA67C: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801AA680: addu        $s2, $v0, $t4
    ctx->r18 = ADD32(ctx->r2, ctx->r12);
    // 0x801AA684: addu        $s3, $v0, $t5
    ctx->r19 = ADD32(ctx->r2, ctx->r13);
    // 0x801AA688: addu        $s4, $v0, $t6
    ctx->r20 = ADD32(ctx->r2, ctx->r14);
    // 0x801AA68C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x801AA690: addu        $s6, $v0, $t2
    ctx->r22 = ADD32(ctx->r2, ctx->r10);
    // 0x801AA694: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x801AA698: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x801AA69C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AA6A0: mfc1        $s5, $f8
    ctx->r21 = (int32_t)ctx->f8.u32l;
    // 0x801AA6A4: jal         0x800B8DD0
    // 0x801AA6A8: nop

    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x801AA6A8: nop

    after_5:
    // 0x801AA6AC: lw          $v1, 0x0($s7)
    ctx->r3 = MEM_W(ctx->r23, 0X0);
    // 0x801AA6B0: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801AA6B4: add.s       $f16, $f22, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f22.fl + ctx->f20.fl;
    // 0x801AA6B8: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x801AA6BC: sw          $t3, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r11;
    // 0x801AA6C0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801AA6C4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x801AA6C8: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x801AA6CC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x801AA6D0: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801AA6D4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x801AA6D8: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x801AA6DC: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x801AA6E0: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x801AA6E4: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x801AA6E8: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x801AA6EC: ori         $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 | 0XFF;
    // 0x801AA6F0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801AA6F4: sub.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f24.fl;
    // 0x801AA6F8: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x801AA6FC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801AA700: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x801AA704: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801AA708: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801AA70C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801AA710: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x801AA714: jal         0x800A1200
    // 0x801AA718: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_6;
    // 0x801AA718: nop

    after_6:
    // 0x801AA71C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801AA720:
    // 0x801AA720: sra         $t7, $s1, 8
    ctx->r15 = S32(SIGNED(ctx->r17) >> 8);
    // 0x801AA724: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x801AA728: bne         $s0, $fp, L_801AA608
    if (ctx->r16 != ctx->r30) {
        // 0x801AA72C: or          $s1, $t7, $zero
        ctx->r17 = ctx->r15 | 0;
            goto L_801AA608;
    }
    // 0x801AA72C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
L_801AA730:
    // 0x801AA730: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x801AA734: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801AA738: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801AA73C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801AA740: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x801AA744: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x801AA748: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x801AA74C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x801AA750: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x801AA754: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x801AA758: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x801AA75C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x801AA760: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x801AA764: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x801AA768: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x801AA76C: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x801AA770: jr          $ra
    // 0x801AA774: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x801AA774: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Option_ExpertSound_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801958DC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801958E0: addiu       $a0, $a0, -0x6D70
    ctx->r4 = ADD32(ctx->r4, -0X6D70);
    // 0x801958E4: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x801958E8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801958EC: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x801958F0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801958F4: sw          $zero, -0x6CE4($at)
    MEM_W(-0X6CE4, ctx->r1) = 0;
    // 0x801958F8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x801958FC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80195900: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80195904: sw          $zero, -0x6CE8($at)
    MEM_W(-0X6CE8, ctx->r1) = 0;
    // 0x80195908: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019590C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80195910: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80195914: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80195918: sw          $zero, -0x6CE0($at)
    MEM_W(-0X6CE0, ctx->r1) = 0;
    // 0x8019591C: addiu       $v0, $v0, -0x6CE8
    ctx->r2 = ADD32(ctx->r2, -0X6CE8);
    // 0x80195920: addiu       $v1, $v1, -0x6D68
    ctx->r3 = ADD32(ctx->r3, -0X6D68);
L_80195924:
    // 0x80195924: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80195928: swc1        $f0, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f0.u32l;
    // 0x8019592C: swc1        $f0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f0.u32l;
    // 0x80195930: swc1        $f0, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80195934: bne         $v1, $v0, L_80195924
    if (ctx->r3 != ctx->r2) {
        // 0x80195938: swc1        $f0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
            goto L_80195924;
    }
    // 0x80195938: swc1        $f0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8019593C: jr          $ra
    // 0x80195940: nop

    return;
    // 0x80195940: nop

;}
RECOMP_FUNC void Option_Versus_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80193C4C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80193C50: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80193C54: addiu       $t0, $t0, -0x6ED4
    ctx->r8 = ADD32(ctx->r8, -0X6ED4);
    // 0x80193C58: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80193C5C: sw          $s7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r23;
    // 0x80193C60: sw          $s6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r22;
    // 0x80193C64: sw          $s5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r21;
    // 0x80193C68: sw          $s4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r20;
    // 0x80193C6C: sw          $s3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r19;
    // 0x80193C70: sw          $s2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r18;
    // 0x80193C74: sw          $s1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r17;
    // 0x80193C78: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x80193C7C: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x80193C80: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x80193C84: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80193C88: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80193C8C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80193C90: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80193C94: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80193C98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193C9C: beq         $v1, $zero, L_80193CD4
    if (ctx->r3 == 0) {
        // 0x80193CA0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80193CD4;
    }
    // 0x80193CA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80193CA4: beq         $v1, $at, L_80193FA4
    if (ctx->r3 == ctx->r1) {
        // 0x80193CA8: lui         $s1, 0x8017
        ctx->r17 = S32(0X8017 << 16);
            goto L_80193FA4;
    }
    // 0x80193CA8: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x80193CAC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80193CB0: beq         $v1, $at, L_80194124
    if (ctx->r3 == ctx->r1) {
        // 0x80193CB4: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_80194124;
    }
    // 0x80193CB4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80193CB8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80193CBC: beq         $v0, $at, L_801941C8
    if (ctx->r2 == ctx->r1) {
        // 0x80193CC0: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_801941C8;
    }
    // 0x80193CC0: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80193CC4: beq         $v0, $at, L_80193D10
    if (ctx->r2 == ctx->r1) {
        // 0x80193CC8: lui         $s0, 0x801B
        ctx->r16 = S32(0X801B << 16);
            goto L_80193D10;
    }
    // 0x80193CC8: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80193CCC: b           L_801944B0
    // 0x80193CD0: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_801944B0;
    // 0x80193CD0: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_80193CD4:
    // 0x80193CD4: jal         0x80193B04
    // 0x80193CD8: nop

    Option_Versus_Setup(rdram, ctx);
        goto after_0;
    // 0x80193CD8: nop

    after_0:
    // 0x80193CDC: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80193CE0: lw          $t6, -0x6DB8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DB8);
    // 0x80193CE4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80193CE8: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x80193CEC: bne         $t6, $zero, L_80193D08
    if (ctx->r14 != 0) {
        // 0x80193CF0: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_80193D08;
    }
    // 0x80193CF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193CF4: lw          $t7, -0x6ED4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6ED4);
    // 0x80193CF8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193CFC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80193D00: b           L_801944AC
    // 0x80193D04: sw          $t8, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r24;
        goto L_801944AC;
    // 0x80193D04: sw          $t8, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r24;
L_80193D08:
    // 0x80193D08: b           L_801944AC
    // 0x80193D0C: sw          $t9, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r25;
        goto L_801944AC;
    // 0x80193D0C: sw          $t9, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r25;
L_80193D10:
    // 0x80193D10: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193D14: lwc1        $f30, 0x7370($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X7370);
    // 0x80193D18: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80193D1C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80193D20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193D24: lwc1        $f26, 0x7374($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X7374);
    // 0x80193D28: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193D2C: lwc1        $f24, 0x7378($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X7378);
    // 0x80193D30: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193D34: lwc1        $f22, 0x737C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X737C);
    // 0x80193D38: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80193D3C: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x80193D40: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x80193D44: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x80193D48: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80193D4C: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x80193D50: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80193D54: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x80193D58: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80193D5C: addiu       $s2, $s2, -0x1058
    ctx->r18 = ADD32(ctx->r18, -0X1058);
    // 0x80193D60: addiu       $s1, $s1, -0x1064
    ctx->r17 = ADD32(ctx->r17, -0X1064);
    // 0x80193D64: addiu       $s7, $s7, -0x176C
    ctx->r23 = ADD32(ctx->r23, -0X176C);
    // 0x80193D68: addiu       $s3, $s3, -0x1070
    ctx->r19 = ADD32(ctx->r19, -0X1070);
    // 0x80193D6C: addiu       $s6, $s6, -0x1770
    ctx->r22 = ADD32(ctx->r22, -0X1770);
    // 0x80193D70: addiu       $s5, $s5, -0x107C
    ctx->r21 = ADD32(ctx->r21, -0X107C);
    // 0x80193D74: addiu       $s4, $s4, -0x174C
    ctx->r20 = ADD32(ctx->r20, -0X174C);
    // 0x80193D78: addiu       $s0, $s0, -0x1788
    ctx->r16 = ADD32(ctx->r16, -0X1788);
L_80193D7C:
    // 0x80193D7C: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80193D80: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80193D84: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80193D88: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80193D8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193D90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80193D94: bc1fl       L_80193DC4
    if (!c1cs) {
        // 0x80193D98: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_80193DC4;
    }
    goto skip_0;
    // 0x80193D98: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_0:
    // 0x80193D9C: lwc1        $f4, 0x7380($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7380);
    // 0x80193DA0: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80193DA4: swc1        $f6, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80193DA8: lwc1        $f8, 0x44($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80193DAC: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x80193DB0: nop

    // 0x80193DB4: bc1fl       L_80193DC4
    if (!c1cs) {
        // 0x80193DB8: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_80193DC4;
    }
    goto skip_1;
    // 0x80193DB8: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_1:
    // 0x80193DBC: swc1        $f22, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f22.u32l;
    // 0x80193DC0: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
L_80193DC4:
    // 0x80193DC4: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80193DC8: nop

    // 0x80193DCC: bc1fl       L_80193DF8
    if (!c1cs) {
        // 0x80193DD0: lw          $a1, 0x0($s5)
        ctx->r5 = MEM_W(ctx->r21, 0X0);
            goto L_80193DF8;
    }
    goto skip_2;
    // 0x80193DD0: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    skip_2:
    // 0x80193DD4: add.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x80193DD8: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x80193DDC: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80193DE0: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x80193DE4: nop

    // 0x80193DE8: bc1fl       L_80193DF8
    if (!c1cs) {
        // 0x80193DEC: lw          $a1, 0x0($s5)
        ctx->r5 = MEM_W(ctx->r21, 0X0);
            goto L_80193DF8;
    }
    goto skip_3;
    // 0x80193DEC: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    skip_3:
    // 0x80193DF0: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x80193DF4: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
L_80193DF8:
    // 0x80193DF8: jal         0x8009BC2C
    // 0x80193DFC: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80193DFC: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_1:
    // 0x80193E00: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x80193E04: lui         $a3, 0x4046
    ctx->r7 = S32(0X4046 << 16);
    // 0x80193E08: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x80193E0C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80193E10: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x80193E14: jal         0x8009BC2C
    // 0x80193E18: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80193E18: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_2:
    // 0x80193E1C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80193E20: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80193E24: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80193E28: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80193E2C: jal         0x8009BC2C
    // 0x80193E30: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80193E30: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_3:
    // 0x80193E34: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80193E38: sltu        $at, $s1, $s2
    ctx->r1 = ctx->r17 < ctx->r18 ? 1 : 0;
    // 0x80193E3C: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x80193E40: addiu       $s4, $s4, 0x60
    ctx->r20 = ADD32(ctx->r20, 0X60);
    // 0x80193E44: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80193E48: addiu       $s6, $s6, 0x60
    ctx->r22 = ADD32(ctx->r22, 0X60);
    // 0x80193E4C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80193E50: bne         $at, $zero, L_80193D7C
    if (ctx->r1 != 0) {
        // 0x80193E54: addiu       $s7, $s7, 0x60
        ctx->r23 = ADD32(ctx->r23, 0X60);
            goto L_80193D7C;
    }
    // 0x80193E54: addiu       $s7, $s7, 0x60
    ctx->r23 = ADD32(ctx->r23, 0X60);
    // 0x80193E58: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80193E5C: lw          $t1, -0x6E5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6E5C);
    // 0x80193E60: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x80193E64: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80193E68: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193E6C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80193E70: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80193E74: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80193E78: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x80193E7C: addiu       $s7, $s7, -0x19C8
    ctx->r23 = ADD32(ctx->r23, -0X19C8);
    // 0x80193E80: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80193E84: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80193E88: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80193E8C: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80193E90: mflo        $t2
    ctx->r10 = lo;
    // 0x80193E94: addu        $a0, $s7, $t2
    ctx->r4 = ADD32(ctx->r23, ctx->r10);
    // 0x80193E98: jal         0x8009BC2C
    // 0x80193E9C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    Math_SmoothStepToF(rdram, ctx);
        goto after_4;
    // 0x80193E9C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_4:
    // 0x80193EA0: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x80193EA4: lw          $t3, -0x6E5C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6E5C);
    // 0x80193EA8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80193EAC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80193EB0: multu       $t3, $s4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193EB4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80193EB8: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80193EBC: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80193EC0: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80193EC4: mflo        $t4
    ctx->r12 = lo;
    // 0x80193EC8: addu        $a0, $s7, $t4
    ctx->r4 = ADD32(ctx->r23, ctx->r12);
    // 0x80193ECC: jal         0x8009BC2C
    // 0x80193ED0: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    Math_SmoothStepToF(rdram, ctx);
        goto after_5;
    // 0x80193ED0: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_5:
    // 0x80193ED4: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80193ED8: addiu       $s5, $s5, -0x6E58
    ctx->r21 = ADD32(ctx->r21, -0X6E58);
    // 0x80193EDC: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80193EE0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80193EE4: addiu       $a0, $a0, 0x1A38
    ctx->r4 = ADD32(ctx->r4, 0X1A38);
    // 0x80193EE8: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193EEC: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x80193EF0: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x80193EF4: addiu       $s6, $s6, -0x1788
    ctx->r22 = ADD32(ctx->r22, -0X1788);
    // 0x80193EF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193EFC: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80193F00: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x80193F04: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80193F08: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80193F0C: lwc1        $f4, -0x107C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X107C);
    // 0x80193F10: mflo        $t7
    ctx->r15 = lo;
    // 0x80193F14: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x80193F18: lwc1        $f18, 0x3C($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X3C);
    // 0x80193F1C: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80193F20: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80193F24: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x80193F28: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80193F2C: addiu       $s1, $s1, -0x1064
    ctx->r17 = ADD32(ctx->r17, -0X1064);
    // 0x80193F30: addiu       $s3, $s3, -0x1070
    ctx->r19 = ADD32(ctx->r19, -0X1070);
    // 0x80193F34: bc1f        L_801944AC
    if (!c1cs) {
        // 0x80193F38: addiu       $s0, $s0, -0x1788
        ctx->r16 = ADD32(ctx->r16, -0X1788);
            goto L_801944AC;
    }
    // 0x80193F38: addiu       $s0, $s0, -0x1788
    ctx->r16 = ADD32(ctx->r16, -0X1788);
    // 0x80193F3C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80193F40: addiu       $v0, $v0, -0x1058
    ctx->r2 = ADD32(ctx->r2, -0X1058);
L_80193F44:
    // 0x80193F44: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80193F48: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80193F4C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80193F50: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x80193F54: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80193F58: swc1        $f20, -0x40($s0)
    MEM_W(-0X40, ctx->r16) = ctx->f20.u32l;
    // 0x80193F5C: swc1        $f6, -0x44($s0)
    MEM_W(-0X44, ctx->r16) = ctx->f6.u32l;
    // 0x80193F60: bne         $s1, $v0, L_80193F44
    if (ctx->r17 != ctx->r2) {
        // 0x80193F64: swc1        $f8, -0x48($s0)
        MEM_W(-0X48, ctx->r16) = ctx->f8.u32l;
            goto L_80193F44;
    }
    // 0x80193F64: swc1        $f8, -0x48($s0)
    MEM_W(-0X48, ctx->r16) = ctx->f8.u32l;
    // 0x80193F68: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80193F6C: lw          $t1, -0x6E5C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6E5C);
    // 0x80193F70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80193F74: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193F78: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193F7C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80193F80: mflo        $t2
    ctx->r10 = lo;
    // 0x80193F84: addu        $v0, $s7, $t2
    ctx->r2 = ADD32(ctx->r23, ctx->r10);
    // 0x80193F88: swc1        $f24, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f24.u32l;
    // 0x80193F8C: swc1        $f30, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f30.u32l;
    // 0x80193F90: sw          $v1, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = ctx->r3;
    // 0x80193F94: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x80193F98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193F9C: b           L_801944AC
    // 0x80193FA0: sw          $v1, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r3;
        goto L_801944AC;
    // 0x80193FA0: sw          $v1, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r3;
L_80193FA4:
    // 0x80193FA4: addiu       $s1, $s1, 0x7AF8
    ctx->r17 = ADD32(ctx->r17, 0X7AF8);
    // 0x80193FA8: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80193FAC: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80193FB0: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80193FB4: addiu       $s5, $s5, -0x6E58
    ctx->r21 = ADD32(ctx->r21, -0X6E58);
    // 0x80193FB8: addiu       $t8, $t8, -0x6E78
    ctx->r24 = ADD32(ctx->r24, -0X6E78);
    // 0x80193FBC: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80193FC0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80193FC4: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80193FC8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80193FCC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80193FD0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80193FD4: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80193FD8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80193FDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80193FE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80193FE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80193FE8: jal         0x8019C418
    // 0x80193FEC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_6;
    // 0x80193FEC: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_6:
    // 0x80193FF0: beq         $v0, $zero, L_80194024
    if (ctx->r2 == 0) {
        // 0x80193FF4: lui         $s0, 0x800C
        ctx->r16 = S32(0X800C << 16);
            goto L_80194024;
    }
    // 0x80193FF4: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80193FF8: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x80193FFC: addiu       $s3, $s3, 0x5D3C
    ctx->r19 = ADD32(ctx->r19, 0X5D3C);
    // 0x80194000: addiu       $a3, $s0, 0x5D34
    ctx->r7 = ADD32(ctx->r16, 0X5D34);
    // 0x80194004: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x80194008: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019400C: ori         $a0, $a0, 0x22
    ctx->r4 = ctx->r4 | 0X22;
    // 0x80194010: addiu       $a1, $s2, 0x5D28
    ctx->r5 = ADD32(ctx->r18, 0X5D28);
    // 0x80194014: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80194018: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8019401C: jal         0x80019218
    // 0x80194020: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x80194020: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_7:
L_80194024:
    // 0x80194024: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x80194028: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8019402C: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80194030: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80194034: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x80194038: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8019403C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80194040: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x80194044: lui         $s2, 0x800C
    ctx->r18 = S32(0X800C << 16);
    // 0x80194048: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8019404C: andi        $t2, $v0, 0x9000
    ctx->r10 = ctx->r2 & 0X9000;
    // 0x80194050: addiu       $s3, $s3, 0x5D3C
    ctx->r19 = ADD32(ctx->r19, 0X5D3C);
    // 0x80194054: addiu       $s2, $s2, 0x5D28
    ctx->r18 = ADD32(ctx->r18, 0X5D28);
    // 0x80194058: beq         $t2, $zero, L_801940D0
    if (ctx->r10 == 0) {
        // 0x8019405C: addiu       $s0, $s0, 0x5D34
        ctx->r16 = ADD32(ctx->r16, 0X5D34);
            goto L_801940D0;
    }
    // 0x8019405C: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
    // 0x80194060: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80194064: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    // 0x80194068: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8019406C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80194070: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80194074: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80194078: jal         0x80019218
    // 0x8019407C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    Audio_PlaySfx(rdram, ctx);
        goto after_8;
    // 0x8019407C: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_8:
    // 0x80194080: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x80194084: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194088: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019408C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80194090: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80194094: lwc1        $f10, -0x107C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X107C);
    // 0x80194098: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x8019409C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801940A0: swc1        $f10, -0x6DF8($at)
    MEM_W(-0X6DF8, ctx->r1) = ctx->f10.u32l;
    // 0x801940A4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801940A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801940AC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801940B0: sw          $zero, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = 0;
    // 0x801940B4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x801940B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801940BC: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801940C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801940C4: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x801940C8: sw          $t5, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r13;
    // 0x801940CC: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
L_801940D0:
    // 0x801940D0: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    // 0x801940D4: beq         $t8, $zero, L_801944AC
    if (ctx->r24 == 0) {
        // 0x801940D8: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_801944AC;
    }
    // 0x801940D8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801940DC: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x801940E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x801940E4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801940E8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801940EC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801940F0: jal         0x80019218
    // 0x801940F4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x801940F4: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_9:
    // 0x801940F8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801940FC: sw          $zero, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = 0;
    // 0x80194100: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194104: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x80194108: sw          $t9, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r25;
    // 0x8019410C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80194110: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80194114: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194118: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019411C: b           L_801944AC
    // 0x80194120: sw          $t1, -0x6DBC($at)
    MEM_W(-0X6DBC, ctx->r1) = ctx->r9;
        goto L_801944AC;
    // 0x80194120: sw          $t1, -0x6DBC($at)
    MEM_W(-0X6DBC, ctx->r1) = ctx->r9;
L_80194124:
    // 0x80194124: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194128: lwc1        $f26, 0x7384($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X7384);
    // 0x8019412C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194130: lwc1        $f28, 0x7388($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X7388);
    // 0x80194134: addiu       $a0, $a0, 0x1A38
    ctx->r4 = ADD32(ctx->r4, 0X1A38);
    // 0x80194138: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8019413C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80194140: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80194144: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x80194148: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019414C: addiu       $s5, $s5, -0x6E58
    ctx->r21 = ADD32(ctx->r21, -0X6E58);
    // 0x80194150: sw          $a1, -0x6E88($at)
    MEM_W(-0X6E88, ctx->r1) = ctx->r5;
    // 0x80194154: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x80194158: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x8019415C: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x80194160: multu       $t3, $s4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80194164: addiu       $s6, $s6, -0x1788
    ctx->r22 = ADD32(ctx->r22, -0X1788);
    // 0x80194168: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8019416C: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x80194170: mflo        $t4
    ctx->r12 = lo;
    // 0x80194174: addu        $v0, $s6, $t4
    ctx->r2 = ADD32(ctx->r22, ctx->r12);
    // 0x80194178: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8019417C: lwc1        $f16, 0x44($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80194180: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80194184: sub.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f28.fl;
    // 0x80194188: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8019418C: sub.s       $f18, $f16, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x80194190: swc1        $f6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f6.u32l;
    // 0x80194194: lwc1        $f16, 0x24($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80194198: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019419C: sub.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f26.fl;
    // 0x801941A0: swc1        $f18, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f18.u32l;
    // 0x801941A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801941A8: sub.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f26.fl;
    // 0x801941AC: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x801941B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801941B4: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x801941B8: swc1        $f8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f8.u32l;
    // 0x801941BC: sw          $a1, -0x6E84($at)
    MEM_W(-0X6E84, ctx->r1) = ctx->r5;
    // 0x801941C0: b           L_801944AC
    // 0x801941C4: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_801944AC;
    // 0x801941C4: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_801941C8:
    // 0x801941C8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801941CC: lw          $t6, -0x6E88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E88);
    // 0x801941D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801941D4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801941D8: bne         $t6, $at, L_80194264
    if (ctx->r14 != ctx->r1) {
        // 0x801941DC: lui         $s3, 0x801B
        ctx->r19 = S32(0X801B << 16);
            goto L_80194264;
    }
    // 0x801941DC: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x801941E0: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x801941E4: addiu       $s5, $s5, -0x6E58
    ctx->r21 = ADD32(ctx->r21, -0X6E58);
    // 0x801941E8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x801941EC: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x801941F0: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x801941F4: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801941F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801941FC: lwc1        $f26, 0x738C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X738C);
    // 0x80194200: addiu       $s6, $s6, -0x1788
    ctx->r22 = ADD32(ctx->r22, -0X1788);
    // 0x80194204: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194208: lwc1        $f28, 0x7390($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X7390);
    // 0x8019420C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80194210: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80194214: mflo        $t8
    ctx->r24 = lo;
    // 0x80194218: addu        $v0, $s6, $t8
    ctx->r2 = ADD32(ctx->r22, ctx->r24);
    // 0x8019421C: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80194220: lwc1        $f10, 0x44($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80194224: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80194228: add.s       $f4, $f18, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f28.fl;
    // 0x8019422C: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80194230: add.s       $f16, $f10, $f28
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x80194234: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x80194238: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8019423C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80194240: add.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x80194244: swc1        $f16, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f16.u32l;
    // 0x80194248: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019424C: add.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x80194250: swc1        $f8, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f8.u32l;
    // 0x80194254: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80194258: swc1        $f16, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f16.u32l;
    // 0x8019425C: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x80194260: sw          $t9, -0x6DEC($at)
    MEM_W(-0X6DEC, ctx->r1) = ctx->r25;
L_80194264:
    // 0x80194264: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194268: lwc1        $f26, 0x7394($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X7394);
    // 0x8019426C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194270: lwc1        $f28, 0x7398($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X7398);
    // 0x80194274: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194278: lwc1        $f30, 0x739C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X739C);
    // 0x8019427C: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x80194280: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80194284: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194288: lwc1        $f22, 0x73A0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X73A0);
    // 0x8019428C: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80194290: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x80194294: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194298: addiu       $s6, $s6, -0x1788
    ctx->r22 = ADD32(ctx->r22, -0X1788);
    // 0x8019429C: addiu       $s5, $s5, -0x6E58
    ctx->r21 = ADD32(ctx->r21, -0X6E58);
    // 0x801942A0: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x801942A4: lwc1        $f20, 0x73A4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X73A4);
    // 0x801942A8: addiu       $s3, $s3, -0x19F8
    ctx->r19 = ADD32(ctx->r19, -0X19F8);
    // 0x801942AC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x801942B0: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
L_801942B4:
    // 0x801942B4: beql        $s2, $t1, L_80194324
    if (ctx->r18 == ctx->r9) {
        // 0x801942B8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80194324;
    }
    goto skip_4;
    // 0x801942B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x801942BC: multu       $s2, $s4
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801942C0: sll         $t3, $s2, 2
    ctx->r11 = S32(ctx->r18 << 2);
    // 0x801942C4: addu        $t4, $s3, $t3
    ctx->r12 = ADD32(ctx->r19, ctx->r11);
    // 0x801942C8: mflo        $t2
    ctx->r10 = lo;
    // 0x801942CC: addu        $s0, $s6, $t2
    ctx->r16 = ADD32(ctx->r22, ctx->r10);
    // 0x801942D0: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x801942D4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x801942D8: c.lt.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl < ctx->f0.fl;
    // 0x801942DC: nop

    // 0x801942E0: bc1fl       L_8019431C
    if (!c1cs) {
        // 0x801942E4: sw          $zero, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = 0;
            goto L_8019431C;
    }
    goto skip_5;
    // 0x801942E4: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    skip_5:
    // 0x801942E8: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801942EC: sub.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x801942F0: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x801942F4: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x801942F8: sub.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x801942FC: lw          $a3, 0x4($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X4);
    // 0x80194300: swc1        $f8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f8.u32l;
    // 0x80194304: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80194308: jal         0x8009BC2C
    // 0x8019430C: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_10;
    // 0x8019430C: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    after_10:
    // 0x80194310: b           L_80194324
    // 0x80194314: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80194324;
    // 0x80194314: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80194318: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
L_8019431C:
    // 0x8019431C: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x80194320: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80194324:
    // 0x80194324: bnel        $s2, $s1, L_801942B4
    if (ctx->r18 != ctx->r17) {
        // 0x80194328: lw          $t1, 0x0($s5)
        ctx->r9 = MEM_W(ctx->r21, 0X0);
            goto L_801942B4;
    }
    goto skip_6;
    // 0x80194328: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    skip_6:
    // 0x8019432C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x80194330: lw          $t5, -0x6E84($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6E84);
    // 0x80194334: bnel        $t5, $zero, L_801944B0
    if (ctx->r13 != 0) {
        // 0x80194338: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_801944B0;
    }
    goto skip_7;
    // 0x80194338: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_7:
    // 0x8019433C: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80194340: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x80194344: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80194348: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x8019434C: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x80194350: bne         $v1, $zero, L_80194368
    if (ctx->r3 != 0) {
        // 0x80194354: addu        $v0, $s6, $t6
        ctx->r2 = ADD32(ctx->r22, ctx->r14);
            goto L_80194368;
    }
    // 0x80194354: addu        $v0, $s6, $t6
    ctx->r2 = ADD32(ctx->r22, ctx->r14);
    // 0x80194358: lui         $at, 0x4301
    ctx->r1 = S32(0X4301 << 16);
    // 0x8019435C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80194360: b           L_80194374
    // 0x80194364: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
        goto L_80194374;
    // 0x80194364: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80194368:
    // 0x80194368: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019436C: nop

    // 0x80194370: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
L_80194374:
    // 0x80194374: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80194378: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8019437C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80194380: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80194384: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80194388: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8019438C: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80194390: jal         0x8009BC2C
    // 0x80194394: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_11;
    // 0x80194394: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    after_11:
    // 0x80194398: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x8019439C: lui         $at, 0xC178
    ctx->r1 = S32(0XC178 << 16);
    // 0x801943A0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801943A4: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801943A8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801943AC: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x801943B0: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x801943B4: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801943B8: mflo        $t8
    ctx->r24 = lo;
    // 0x801943BC: addu        $a0, $s6, $t8
    ctx->r4 = ADD32(ctx->r22, ctx->r24);
    // 0x801943C0: jal         0x8009BC2C
    // 0x801943C4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x801943C4: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_12:
    // 0x801943C8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801943CC: lw          $t9, -0x6E5C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6E5C);
    // 0x801943D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801943D4: lwc1        $f22, 0x73A8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X73A8);
    // 0x801943D8: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801943DC: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x801943E0: addiu       $s7, $s7, -0x19C8
    ctx->r23 = ADD32(ctx->r23, -0X19C8);
    // 0x801943E4: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x801943E8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x801943EC: lui         $a1, 0xC120
    ctx->r5 = S32(0XC120 << 16);
    // 0x801943F0: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801943F4: mflo        $t1
    ctx->r9 = lo;
    // 0x801943F8: addu        $a0, $s7, $t1
    ctx->r4 = ADD32(ctx->r23, ctx->r9);
    // 0x801943FC: jal         0x8009BC2C
    // 0x80194400: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x80194400: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_13:
    // 0x80194404: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x80194408: lw          $t2, -0x6E5C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6E5C);
    // 0x8019440C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80194410: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80194414: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80194418: lui         $a1, 0x4316
    ctx->r5 = S32(0X4316 << 16);
    // 0x8019441C: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x80194420: mflo        $t3
    ctx->r11 = lo;
    // 0x80194424: addu        $a0, $s7, $t3
    ctx->r4 = ADD32(ctx->r23, ctx->r11);
    // 0x80194428: jal         0x8009BC2C
    // 0x8019442C: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x8019442C: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_14:
    // 0x80194430: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80194434: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80194438: addiu       $a0, $a0, 0x1A38
    ctx->r4 = ADD32(ctx->r4, 0X1A38);
    // 0x8019443C: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80194440: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x80194444: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80194448: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
    // 0x8019444C: mflo        $t6
    ctx->r14 = lo;
    // 0x80194450: addu        $v0, $s6, $t6
    ctx->r2 = ADD32(ctx->r22, ctx->r14);
    // 0x80194454: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80194458: c.eq.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl == ctx->f18.fl;
    // 0x8019445C: nop

    // 0x80194460: bc1fl       L_801944B0
    if (!c1cs) {
        // 0x80194464: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_801944B0;
    }
    goto skip_8;
    // 0x80194464: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_8:
    // 0x80194468: lwc1        $f4, 0x3C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8019446C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80194470: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x80194474: c.eq.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl == ctx->f4.fl;
    // 0x80194478: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8019447C: addiu       $t8, $t5, 0xFF
    ctx->r24 = ADD32(ctx->r13, 0XFF);
    // 0x80194480: addiu       $t1, $t9, 0xA
    ctx->r9 = ADD32(ctx->r25, 0XA);
    // 0x80194484: bc1f        L_801944AC
    if (!c1cs) {
        // 0x80194488: lui         $at, 0x801C
        ctx->r1 = S32(0X801C << 16);
            goto L_801944AC;
    }
    // 0x80194488: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019448C: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x80194490: sw          $t1, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r9;
    // 0x80194494: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80194498: sw          $v1, 0x78AC($at)
    MEM_W(0X78AC, ctx->r1) = ctx->r3;
    // 0x8019449C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801944A0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801944A4: jal         0x801924C4
    // 0x801944A8: sw          $t2, -0x6E3C($at)
    MEM_W(-0X6E3C, ctx->r1) = ctx->r10;
    Option_Entry_Setup(rdram, ctx);
        goto after_15;
    // 0x801944A8: sw          $t2, -0x6E3C($at)
    MEM_W(-0X6E3C, ctx->r1) = ctx->r10;
    after_15:
L_801944AC:
    // 0x801944AC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_801944B0:
    // 0x801944B0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801944B4: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801944B8: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801944BC: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x801944C0: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x801944C4: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x801944C8: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x801944CC: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x801944D0: lw          $s2, 0x64($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X64);
    // 0x801944D4: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x801944D8: lw          $s4, 0x6C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X6C);
    // 0x801944DC: lw          $s5, 0x70($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X70);
    // 0x801944E0: lw          $s6, 0x74($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X74);
    // 0x801944E4: lw          $s7, 0x78($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X78);
    // 0x801944E8: jr          $ra
    // 0x801944EC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801944EC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Map_TotalHits_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9EE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A9EE8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A9EEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A9EF0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A9EF4: jal         0x800B8DD0
    // 0x801A9EF8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A9EF8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x801A9EFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A9F00: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801A9F04: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A9F08: addiu       $t0, $t0, 0x7E64
    ctx->r8 = ADD32(ctx->r8, 0X7E64);
    // 0x801A9F0C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x801A9F10: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x801A9F14: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x801A9F18: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801A9F1C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x801A9F20: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A9F24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801A9F28: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x801A9F2C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x801A9F30: addiu       $t9, $t9, 0x74FC
    ctx->r25 = ADD32(ctx->r25, 0X74FC);
    // 0x801A9F34: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A9F38: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A9F3C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A9F40: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x801A9F44: jal         0x800A1200
    // 0x801A9F48: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_1;
    // 0x801A9F48: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_1:
    // 0x801A9F4C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x801A9F50: jal         0x8008BCBC
    // 0x801A9F54: lw          $a0, 0x1714($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1714);
    HUD_CountDigits(rdram, ctx);
        goto after_2;
    // 0x801A9F54: lw          $a0, 0x1714($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1714);
    after_2:
    // 0x801A9F58: sll         $t1, $v0, 3
    ctx->r9 = S32(ctx->r2 << 3);
    // 0x801A9F5C: addiu       $t2, $zero, 0x47
    ctx->r10 = ADD32(0, 0X47);
    // 0x801A9F60: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x801A9F64: lw          $a2, 0x1714($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1714);
    // 0x801A9F68: subu        $a0, $t2, $t1
    ctx->r4 = SUB32(ctx->r10, ctx->r9);
    // 0x801A9F6C: jal         0x8009FEA0
    // 0x801A9F70: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_3;
    // 0x801A9F70: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_3:
    // 0x801A9F74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A9F78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A9F7C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801A9F80: addiu       $t3, $t3, 0x7508
    ctx->r11 = ADD32(ctx->r11, 0X7508);
    // 0x801A9F84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A9F88: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A9F8C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A9F90: addiu       $a0, $zero, 0x8F
    ctx->r4 = ADD32(0, 0X8F);
    // 0x801A9F94: jal         0x800A1200
    // 0x801A9F98: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    Graphics_DisplaySmallText(rdram, ctx);
        goto after_4;
    // 0x801A9F98: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    after_4:
    // 0x801A9F9C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A9FA0: jal         0x8008BCBC
    // 0x801A9FA4: lw          $a0, -0x27C4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27C4);
    HUD_CountDigits(rdram, ctx);
        goto after_5;
    // 0x801A9FA4: lw          $a0, -0x27C4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X27C4);
    after_5:
    // 0x801A9FA8: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x801A9FAC: addiu       $t5, $zero, 0xA7
    ctx->r13 = ADD32(0, 0XA7);
    // 0x801A9FB0: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A9FB4: lw          $a2, -0x27C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X27C4);
    // 0x801A9FB8: subu        $a0, $t5, $t4
    ctx->r4 = SUB32(ctx->r13, ctx->r12);
    // 0x801A9FBC: jal         0x8009FEA0
    // 0x801A9FC0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_6;
    // 0x801A9FC0: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    after_6:
    // 0x801A9FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A9FC8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A9FCC: jr          $ra
    // 0x801A9FD0: nop

    return;
    // 0x801A9FD0: nop

;}
RECOMP_FUNC void Map_LylatCard_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A19A8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801A19AC: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801A19B0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801A19B4: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x801A19B8: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801A19BC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801A19C0: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801A19C4: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801A19C8: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x801A19CC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801A19D0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801A19D4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801A19D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801A19DC: jal         0x800B8DD0
    // 0x801A19E0: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A19E0: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x801A19E4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x801A19E8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A19EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A19F0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801A19F4: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x801A19F8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801A19FC: lwc1        $f4, -0x1564($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1564);
    // 0x801A1A00: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A1A04: lui         $s1, 0x601
    ctx->r17 = S32(0X601 << 16);
    // 0x801A1A08: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A1A0C: addiu       $s1, $s1, -0x2A70
    ctx->r17 = ADD32(ctx->r17, -0X2A70);
    // 0x801A1A10: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801A1A14: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801A1A18: nop

    // 0x801A1A1C: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x801A1A20: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801A1A24: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801A1A28: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x801A1A2C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801A1A30: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801A1A34: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801A1A38: lui         $at, 0x4290
    ctx->r1 = S32(0X4290 << 16);
    // 0x801A1A3C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A1A40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A1A44: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A1A48: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_801A1A4C:
    // 0x801A1A4C: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x801A1A50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801A1A54: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801A1A58: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801A1A5C: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // 0x801A1A60: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x801A1A64: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801A1A68: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A1A6C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A1A70: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x801A1A74: add.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x801A1A78: jal         0x8009D994
    // 0x801A1A7C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x801A1A7C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801A1A80: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A1A84: bne         $s0, $s2, L_801A1A4C
    if (ctx->r16 != ctx->r18) {
        // 0x801A1A88: addiu       $s1, $s1, 0x2A0
        ctx->r17 = ADD32(ctx->r17, 0X2A0);
            goto L_801A1A4C;
    }
    // 0x801A1A88: addiu       $s1, $s1, 0x2A0
    ctx->r17 = ADD32(ctx->r17, 0X2A0);
    // 0x801A1A8C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801A1A90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A1A94: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801A1A98: addiu       $a1, $a1, -0x1FF0
    ctx->r5 = ADD32(ctx->r5, -0X1FF0);
    // 0x801A1A9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801A1AA0: addiu       $a2, $zero, 0xA8
    ctx->r6 = ADD32(0, 0XA8);
    // 0x801A1AA4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801A1AA8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801A1AAC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A1AB0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A1AB4: jal         0x8009D994
    // 0x801A1AB8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x801A1AB8: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801A1ABC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x801A1AC0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801A1AC4: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801A1AC8: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801A1ACC: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x801A1AD0: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801A1AD4: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801A1AD8: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801A1ADC: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801A1AE0: jr          $ra
    // 0x801A1AE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x801A1AE4: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Title_GetRankTotalHits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80188010: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80188014: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80188018: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8018801C: addiu       $a3, $a3, -0x7DE0
    ctx->r7 = ADD32(ctx->r7, -0X7DE0);
    // 0x80188020: addiu       $v1, $v1, -0x7E58
    ctx->r3 = ADD32(ctx->r3, -0X7E58);
    // 0x80188024: addiu       $a0, $a0, -0x7DE0
    ctx->r4 = ADD32(ctx->r4, -0X7DE0);
    // 0x80188028: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_8018802C:
    // 0x8018802C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80188030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80188034: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80188038:
    // 0x80188038: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8018803C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80188040: bne         $a1, $a2, L_80188038
    if (ctx->r5 != ctx->r6) {
        // 0x80188044: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80188038;
    }
    // 0x80188044: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80188048: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x8018804C: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x80188050: bne         $at, $zero, L_8018802C
    if (ctx->r1 != 0) {
        // 0x80188054: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8018802C;
    }
    // 0x80188054: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80188058: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8018805C: addiu       $t1, $t6, -0x7790
    ctx->r9 = ADD32(ctx->r14, -0X7790);
    // 0x80188060: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80188064: addiu       $a2, $a2, -0x7DB8
    ctx->r6 = ADD32(ctx->r6, -0X7DB8);
    // 0x80188068: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8018806C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80188070: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80188074:
    // 0x80188074: lbu         $t8, 0x18($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X18);
    // 0x80188078: lbu         $t0, 0x36($t1)
    ctx->r8 = MEM_BU(ctx->r9, 0X36);
    // 0x8018807C: lbu         $t6, 0x19($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X19);
    // 0x80188080: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x80188084: lbu         $t8, 0x1A($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X1A);
    // 0x80188088: sb          $zero, 0x3($a2)
    MEM_B(0X3, ctx->r6) = 0;
    // 0x8018808C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80188090: sb          $t6, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r14;
    // 0x80188094: blez        $t0, L_8018814C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80188098: sb          $t8, 0x2($a2)
        MEM_B(0X2, ctx->r6) = ctx->r24;
            goto L_8018814C;
    }
    // 0x80188098: sb          $t8, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r24;
    // 0x8018809C: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801880A0: addiu       $t9, $t9, -0x7DE0
    ctx->r25 = ADD32(ctx->r25, -0X7DE0);
    // 0x801880A4: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    // 0x801880A8: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x801880AC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801880B0: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x801880B4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x801880B8: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x801880BC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x801880C0: addiu       $t7, $t7, -0x7790
    ctx->r15 = ADD32(ctx->r15, -0X7790);
    // 0x801880C4: addiu       $t9, $t9, -0x7E58
    ctx->r25 = ADD32(ctx->r25, -0X7E58);
    // 0x801880C8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x801880CC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801880D0: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x801880D4: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
L_801880D8:
    // 0x801880D8: lhu         $t4, 0x5E($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X5E);
    // 0x801880DC: lbu         $t2, 0x5E($t3)
    ctx->r10 = MEM_BU(ctx->r11, 0X5E);
    // 0x801880E0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801880E4: sll         $t6, $t4, 28
    ctx->r14 = S32(ctx->r12 << 28);
    // 0x801880E8: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x801880EC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x801880F0: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x801880F4: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x801880F8: or          $t2, $t2, $t9
    ctx->r10 = ctx->r10 | ctx->r25;
    // 0x801880FC: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80188100: sll         $t9, $t4, 29
    ctx->r25 = S32(ctx->r12 << 29);
    // 0x80188104: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80188108: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8018810C: srl         $t6, $t9, 31
    ctx->r14 = S32(U32(ctx->r25) >> 31);
    // 0x80188110: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80188114: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80188118: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x8018811C: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x80188120: andi        $t7, $t4, 0x1
    ctx->r15 = ctx->r12 & 0X1;
    // 0x80188124: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x80188128: lw          $t8, 0x8($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X8);
    // 0x8018812C: sll         $t6, $t4, 30
    ctx->r14 = S32(ctx->r12 << 30);
    // 0x80188130: sw          $t9, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r25;
    // 0x80188134: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80188138: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x8018813C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80188140: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x80188144: bne         $a1, $t0, L_801880D8
    if (ctx->r5 != ctx->r8) {
        // 0x80188148: sw          $t6, 0x8($t5)
        MEM_W(0X8, ctx->r13) = ctx->r14;
            goto L_801880D8;
    }
    // 0x80188148: sw          $t6, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r14;
L_8018814C:
    // 0x8018814C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80188150: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80188154: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80188158: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8018815C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x80188160: bne         $at, $zero, L_80188074
    if (ctx->r1 != 0) {
        // 0x80188164: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_80188074;
    }
    // 0x80188164: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x80188168: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018816C: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80188170: lw          $v1, -0x7DE0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7DE0);
    // 0x80188174: lw          $v0, -0x7DDC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7DDC);
    // 0x80188178: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8018817C: addiu       $a0, $a0, -0x7DD8
    ctx->r4 = ADD32(ctx->r4, -0X7DD8);
    // 0x80188180: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80188184: beq         $at, $zero, L_80188190
    if (ctx->r1 == 0) {
        // 0x80188188: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_80188190;
    }
    // 0x80188188: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018818C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80188190:
    // 0x80188190: addiu       $a1, $a1, -0x7DB8
    ctx->r5 = ADD32(ctx->r5, -0X7DB8);
    // 0x80188194: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80188198:
    // 0x80188198: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8018819C: beql        $at, $zero, L_801881AC
    if (ctx->r1 == 0) {
        // 0x801881A0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_801881AC;
    }
    goto skip_0;
    // 0x801881A0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x801881A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801881A8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_801881AC:
    // 0x801881AC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801881B0: beql        $at, $zero, L_801881C0
    if (ctx->r1 == 0) {
        // 0x801881B4: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_801881C0;
    }
    goto skip_1;
    // 0x801881B4: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_1:
    // 0x801881B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801881BC: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_801881C0:
    // 0x801881C0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801881C4: beql        $at, $zero, L_801881D4
    if (ctx->r1 == 0) {
        // 0x801881C8: lw          $v0, 0xC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XC);
            goto L_801881D4;
    }
    goto skip_2;
    // 0x801881C8: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    skip_2:
    // 0x801881CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801881D0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
L_801881D4:
    // 0x801881D4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801881D8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801881DC: beq         $at, $zero, L_801881E8
    if (ctx->r1 == 0) {
        // 0x801881E0: nop
    
            goto L_801881E8;
    }
    // 0x801881E0: nop

    // 0x801881E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801881E8:
    // 0x801881E8: bnel        $a0, $a1, L_80188198
    if (ctx->r4 != ctx->r5) {
        // 0x801881EC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80188198;
    }
    goto skip_3;
    // 0x801881EC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_3:
    // 0x801881F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801881F4: jr          $ra
    // 0x801881F8: nop

    return;
    // 0x801881F8: nop

;}
RECOMP_FUNC void Title_Ranking_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80187B00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80187B04: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80187B08: addiu       $a2, $a2, -0x7D40
    ctx->r6 = ADD32(ctx->r6, -0X7D40);
    // 0x80187B0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80187B10: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80187B14: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80187B18: addiu       $a0, $a0, -0x7D78
    ctx->r4 = ADD32(ctx->r4, -0X7D78);
    // 0x80187B1C: beq         $v1, $zero, L_80187B38
    if (ctx->r3 == 0) {
        // 0x80187B20: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80187B38;
    }
    // 0x80187B20: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80187B24: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80187B28: beq         $v0, $at, L_80187B6C
    if (ctx->r2 == ctx->r1) {
        // 0x80187B2C: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_80187B6C;
    }
    // 0x80187B2C: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80187B30: b           L_80187C60
    // 0x80187B34: addiu       $a0, $a0, -0x7D78
    ctx->r4 = ADD32(ctx->r4, -0X7D78);
        goto L_80187C60;
    // 0x80187B34: addiu       $a0, $a0, -0x7D78
    ctx->r4 = ADD32(ctx->r4, -0X7D78);
L_80187B38:
    // 0x80187B38: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80187B3C: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x80187B40: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187B44: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x80187B48: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187B4C: addiu       $t7, $zero, 0x1C2
    ctx->r15 = ADD32(0, 0X1C2);
    // 0x80187B50: sw          $t7, -0x7D44($at)
    MEM_W(-0X7D44, ctx->r1) = ctx->r15;
    // 0x80187B54: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80187B58: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80187B5C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187B60: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x80187B64: b           L_80187C60
    // 0x80187B68: sw          $t9, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r25;
        goto L_80187C60;
    // 0x80187B68: sw          $t9, -0x7D58($at)
    MEM_W(-0X7D58, ctx->r1) = ctx->r25;
L_80187B6C:
    // 0x80187B6C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80187B70: lw          $t0, -0x7D44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7D44);
    // 0x80187B74: beq         $t0, $zero, L_80187C04
    if (ctx->r8 == 0) {
        // 0x80187B78: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80187C04;
    }
    // 0x80187B78: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187B7C: lwc1        $f12, 0x7978($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x80187B80: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187B84: lwc1        $f14, 0x7980($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x80187B88: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187B8C: lwc1        $f4, 0x79B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x80187B90: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187B94: lwc1        $f6, 0x79C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x80187B98: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x80187B9C: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80187BA0: lw          $a3, 0x79A0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X79A0);
    // 0x80187BA4: lw          $a2, 0x7988($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7988);
    // 0x80187BA8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80187BAC: jal         0x800B6F50
    // 0x80187BB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Camera_SetStarfieldPos(rdram, ctx);
        goto after_0;
    // 0x80187BB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80187BB4: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x80187BB8: addiu       $v0, $v0, -0x7BD4
    ctx->r2 = ADD32(ctx->r2, -0X7BD4);
    // 0x80187BBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80187BC0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80187BC4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80187BC8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x80187BCC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80187BD0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80187BD4: lui         $a0, 0x103C
    ctx->r4 = S32(0X103C << 16);
    // 0x80187BD8: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x80187BDC: lw          $t1, -0x7D44($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7D44);
    // 0x80187BE0: bne         $t1, $at, L_80187C38
    if (ctx->r9 != ctx->r1) {
        // 0x80187BE4: nop
    
            goto L_80187C38;
    }
    // 0x80187BE4: nop

    // 0x80187BE8: jal         0x800182F4
    // 0x80187BEC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x80187BEC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80187BF0: lui         $a0, 0x113C
    ctx->r4 = S32(0X113C << 16);
    // 0x80187BF4: jal         0x800182F4
    // 0x80187BF8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x80187BF8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_2:
    // 0x80187BFC: b           L_80187C38
    // 0x80187C00: nop

        goto L_80187C38;
    // 0x80187C00: nop

L_80187C04:
    // 0x80187C04: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187C08: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x80187C0C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187C10: sw          $zero, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = 0;
    // 0x80187C14: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80187C18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80187C1C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80187C20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80187C24: jal         0x8001DC6C
    // 0x80187C28: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_3;
    // 0x80187C28: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    after_3:
    // 0x80187C2C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80187C30: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187C34: sw          $t2, -0x7D3C($at)
    MEM_W(-0X7D3C, ctx->r1) = ctx->r10;
L_80187C38:
    // 0x80187C38: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80187C3C: addiu       $a0, $a0, -0x7D78
    ctx->r4 = ADD32(ctx->r4, -0X7D78);
    // 0x80187C40: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x80187C44: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80187C48: bne         $t3, $at, L_80187C60
    if (ctx->r11 != ctx->r1) {
        // 0x80187C4C: lui         $t4, 0x801C
        ctx->r12 = S32(0X801C << 16);
            goto L_80187C60;
    }
    // 0x80187C4C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80187C50: lw          $t4, -0x7D44($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7D44);
    // 0x80187C54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80187C58: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80187C5C: sw          $t5, -0x7D44($at)
    MEM_W(-0X7D44, ctx->r1) = ctx->r13;
L_80187C60:
    // 0x80187C60: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80187C64: lw          $t6, -0x7D58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D58);
    // 0x80187C68: bne         $t6, $zero, L_80187C98
    if (ctx->r14 != 0) {
        // 0x80187C6C: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_80187C98;
    }
    // 0x80187C6C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80187C70: lw          $t7, 0x7DB0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7DB0);
    // 0x80187C74: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80187C78: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80187C7C: bnel        $t8, $at, L_80187C9C
    if (ctx->r24 != ctx->r1) {
        // 0x80187C80: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80187C9C;
    }
    goto skip_0;
    // 0x80187C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80187C84: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80187C88: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80187C8C: beq         $at, $zero, L_80187C98
    if (ctx->r1 == 0) {
        // 0x80187C90: addiu       $t9, $v0, 0x1
        ctx->r25 = ADD32(ctx->r2, 0X1);
            goto L_80187C98;
    }
    // 0x80187C90: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80187C94: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_80187C98:
    // 0x80187C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80187C9C:
    // 0x80187C9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80187CA0: jr          $ra
    // 0x80187CA4: nop

    return;
    // 0x80187CA4: nop

;}
RECOMP_FUNC void Option_Sound_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80194CE4: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80194CE8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80194CEC: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80194CF0: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80194CF4: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80194CF8: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80194CFC: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80194D00: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80194D04: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80194D08: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x80194D0C: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x80194D10: jal         0x8019B9C0
    // 0x80194D14: nop

    Option_DrawMenuLabel(rdram, ctx);
        goto after_0;
    // 0x80194D14: nop

    after_0:
    // 0x80194D18: jal         0x801952B4
    // 0x80194D1C: nop

    Option_Sound_Speaker_Draw(rdram, ctx);
        goto after_1;
    // 0x80194D1C: nop

    after_1:
    // 0x80194D20: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80194D24: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x80194D28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194D2C: jal         0x800B8DD0
    // 0x80194D30: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x80194D30: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_2:
    // 0x80194D34: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x80194D38: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x80194D3C: addiu       $s6, $s6, -0x102C
    ctx->r22 = ADD32(ctx->r22, -0X102C);
    // 0x80194D40: addiu       $s5, $s5, -0x1058
    ctx->r21 = ADD32(ctx->r21, -0X1058);
    // 0x80194D44: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80194D48: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80194D4C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80194D50: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80194D54: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80194D58: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80194D5C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80194D60: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194D64: lwc1        $f8, -0x1000($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1000);
    // 0x80194D68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80194D6C: lwc1        $f10, 0x73AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X73AC);
    // 0x80194D70: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80194D74: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80194D78: lui         $a1, 0x604
    ctx->r5 = S32(0X604 << 16);
    // 0x80194D7C: addiu       $a1, $a1, 0x47A0
    ctx->r5 = ADD32(ctx->r5, 0X47A0);
    // 0x80194D80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194D84: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80194D88: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80194D8C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80194D90: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80194D94: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80194D98: jal         0x8009D418
    // 0x80194D9C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_3;
    // 0x80194D9C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_3:
    // 0x80194DA0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194DA4: jal         0x800B8DD0
    // 0x80194DA8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80194DA8: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_4:
    // 0x80194DAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80194DB0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80194DB4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194DB8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80194DBC: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x80194DC0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80194DC4: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80194DC8: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80194DCC: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80194DD0: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80194DD4: lwc1        $f16, 0x4($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80194DD8: lwc1        $f18, 0x4($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80194DDC: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80194DE0: addiu       $a1, $a1, 0x5CD0
    ctx->r5 = ADD32(ctx->r5, 0X5CD0);
    // 0x80194DE4: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x80194DE8: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80194DEC: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80194DF0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80194DF4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80194DF8: jal         0x8009D994
    // 0x80194DFC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x80194DFC: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80194E00: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80194E04: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80194E08: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x80194E0C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80194E10: addiu       $s4, $s4, -0x6D78
    ctx->r20 = ADD32(ctx->r20, -0X6D78);
    // 0x80194E14: addiu       $s0, $s0, -0x6D90
    ctx->r16 = ADD32(ctx->r16, -0X6D90);
    // 0x80194E18: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80194E1C:
    // 0x80194E1C: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80194E20: bnel        $s2, $t2, L_80194E3C
    if (ctx->r18 != ctx->r10) {
        // 0x80194E24: swc1        $f20, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
            goto L_80194E3C;
    }
    goto skip_0;
    // 0x80194E24: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    skip_0:
    // 0x80194E28: jal         0x8019C824
    // 0x80194E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Option_Color_FlashRed(rdram, ctx);
        goto after_6;
    // 0x80194E2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80194E30: b           L_80194E40
    // 0x80194E34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_80194E40;
    // 0x80194E34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80194E38: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
L_80194E3C:
    // 0x80194E3C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80194E40:
    // 0x80194E40: slti        $at, $s2, 0x4
    ctx->r1 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x80194E44: bne         $at, $zero, L_80194E1C
    if (ctx->r1 != 0) {
        // 0x80194E48: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80194E1C;
    }
    // 0x80194E48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80194E4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194E50: lwc1        $f4, -0x6D90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D90);
    // 0x80194E54: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80194E58: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80194E5C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80194E60: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80194E64: addiu       $a1, $a1, 0x6280
    ctx->r5 = ADD32(ctx->r5, 0X6280);
    // 0x80194E68: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194E6C: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x80194E70: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80194E74: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80194E78: andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
    // 0x80194E7C: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x80194E80: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80194E84: sll         $t8, $s1, 8
    ctx->r24 = S32(ctx->r17 << 8);
    // 0x80194E88: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x80194E8C: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x80194E90: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80194E94: ori         $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 | 0XFF;
    // 0x80194E98: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
    // 0x80194E9C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80194EA0: lwc1        $f8, 0x8($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80194EA4: lwc1        $f10, 0x8($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80194EA8: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80194EAC: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80194EB0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80194EB4: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80194EB8: jal         0x8009D994
    // 0x80194EBC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_7;
    // 0x80194EBC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x80194EC0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194EC4: lwc1        $f16, -0x6D8C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6D8C);
    // 0x80194EC8: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80194ECC: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80194ED0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80194ED4: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80194ED8: addiu       $a1, $a1, 0x64F0
    ctx->r5 = ADD32(ctx->r5, 0X64F0);
    // 0x80194EDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194EE0: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x80194EE4: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x80194EE8: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80194EEC: andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
    // 0x80194EF0: sll         $t4, $s1, 16
    ctx->r12 = S32(ctx->r17 << 16);
    // 0x80194EF4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x80194EF8: sll         $t6, $s1, 8
    ctx->r14 = S32(ctx->r17 << 8);
    // 0x80194EFC: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80194F00: sw          $t2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r10;
    // 0x80194F04: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80194F08: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x80194F0C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80194F10: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80194F14: lwc1        $f4, 0xC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
    // 0x80194F18: lwc1        $f6, 0xC($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80194F1C: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80194F20: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80194F24: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80194F28: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80194F2C: jal         0x8009D994
    // 0x80194F30: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_8;
    // 0x80194F30: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_8:
    // 0x80194F34: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194F38: lwc1        $f8, -0x6D88($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6D88);
    // 0x80194F3C: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80194F40: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80194F44: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80194F48: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x80194F4C: addiu       $a1, $a1, 0x69C0
    ctx->r5 = ADD32(ctx->r5, 0X69C0);
    // 0x80194F50: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194F54: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x80194F58: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x80194F5C: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80194F60: andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
    // 0x80194F64: sll         $t2, $s1, 16
    ctx->r10 = S32(ctx->r17 << 16);
    // 0x80194F68: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x80194F6C: sll         $t4, $s1, 8
    ctx->r12 = S32(ctx->r17 << 8);
    // 0x80194F70: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x80194F74: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x80194F78: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x80194F7C: ori         $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 | 0XFF;
    // 0x80194F80: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80194F84: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80194F88: lwc1        $f16, 0x10($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X10);
    // 0x80194F8C: lwc1        $f18, 0x10($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80194F90: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80194F94: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80194F98: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80194F9C: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80194FA0: jal         0x8009D994
    // 0x80194FA4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_9;
    // 0x80194FA4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x80194FA8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80194FAC: lwc1        $f4, -0x6D84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6D84);
    // 0x80194FB0: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80194FB4: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x80194FB8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80194FBC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80194FC0: addiu       $a1, $a1, 0x6D10
    ctx->r5 = ADD32(ctx->r5, 0X6D10);
    // 0x80194FC4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80194FC8: mfc1        $s2, $f6
    ctx->r18 = (int32_t)ctx->f6.u32l;
    // 0x80194FCC: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x80194FD0: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80194FD4: andi        $s1, $s2, 0xFF
    ctx->r17 = ctx->r18 & 0XFF;
    // 0x80194FD8: sll         $t0, $s1, 16
    ctx->r8 = S32(ctx->r17 << 16);
    // 0x80194FDC: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x80194FE0: sll         $t2, $s1, 8
    ctx->r10 = S32(ctx->r17 << 8);
    // 0x80194FE4: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80194FE8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x80194FEC: or          $t3, $t1, $t2
    ctx->r11 = ctx->r9 | ctx->r10;
    // 0x80194FF0: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x80194FF4: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80194FF8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80194FFC: lwc1        $f8, 0x14($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X14);
    // 0x80195000: lwc1        $f10, 0x14($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80195004: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80195008: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8019500C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80195010: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80195014: jal         0x8009D994
    // 0x80195018: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_10;
    // 0x80195018: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_10:
    // 0x8019501C: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80195020: lui         $s1, 0x801
    ctx->r17 = S32(0X801 << 16);
    // 0x80195024: addiu       $s1, $s1, -0x1ED0
    ctx->r17 = ADD32(ctx->r17, -0X1ED0);
    // 0x80195028: bne         $t5, $zero, L_801950A0
    if (ctx->r13 != 0) {
        // 0x8019502C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801950A0;
    }
    // 0x8019502C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80195030: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x80195034: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80195038: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8019503C: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x80195040: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x80195044: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80195048: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8019504C: lwc1        $f16, 0x18($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X18);
    // 0x80195050: lwc1        $f18, 0x18($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X18);
    // 0x80195054: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80195058: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8019505C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80195060: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80195064: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80195068: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019506C: jal         0x8009E1E8
    // 0x80195070: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8_MirX(rdram, ctx);
        goto after_11;
    // 0x80195070: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_11:
    // 0x80195074: lwc1        $f4, 0x1C($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X1C);
    // 0x80195078: lwc1        $f6, 0x1C($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X1C);
    // 0x8019507C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80195080: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80195084: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80195088: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x8019508C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80195090: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80195094: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80195098: jal         0x8009D994
    // 0x8019509C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_12;
    // 0x8019509C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_12:
L_801950A0:
    // 0x801950A0: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x801950A4: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801950A8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801950AC: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x801950B0: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x801950B4: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x801950B8: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801950BC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801950C0: lbu         $v1, 0x7C74($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X7C74);
    // 0x801950C4: lui         $a1, 0x801
    ctx->r5 = S32(0X801 << 16);
    // 0x801950C8: addiu       $a1, $a1, -0x3270
    ctx->r5 = ADD32(ctx->r5, -0X3270);
    // 0x801950CC: beq         $v1, $zero, L_801950F4
    if (ctx->r3 == 0) {
        // 0x801950D0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_801950F4;
    }
    // 0x801950D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801950D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801950D8: beq         $v1, $at, L_80195120
    if (ctx->r3 == ctx->r1) {
        // 0x801950DC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80195120;
    }
    // 0x801950DC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801950E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801950E4: beq         $v1, $at, L_80195154
    if (ctx->r3 == ctx->r1) {
        // 0x801950E8: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80195154;
    }
    // 0x801950E8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801950EC: b           L_80195184
    // 0x801950F0: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
        goto L_80195184;
    // 0x801950F0: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
L_801950F4:
    // 0x801950F4: lwc1        $f8, 0x20($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X20);
    // 0x801950F8: lwc1        $f10, 0x20($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X20);
    // 0x801950FC: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x80195100: addiu       $a3, $zero, 0xD
    ctx->r7 = ADD32(0, 0XD);
    // 0x80195104: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80195108: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8019510C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x80195110: jal         0x8009D994
    // 0x80195114: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_13;
    // 0x80195114: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_13:
    // 0x80195118: b           L_80195184
    // 0x8019511C: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
        goto L_80195184;
    // 0x8019511C: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
L_80195120:
    // 0x80195120: lwc1        $f16, 0x24($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X24);
    // 0x80195124: lwc1        $f18, 0x24($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X24);
    // 0x80195128: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8019512C: addiu       $a1, $a1, 0x76E0
    ctx->r5 = ADD32(ctx->r5, 0X76E0);
    // 0x80195130: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x80195134: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80195138: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8019513C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80195140: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80195144: jal         0x8009D994
    // 0x80195148: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_14;
    // 0x80195148: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x8019514C: b           L_80195184
    // 0x80195150: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
        goto L_80195184;
    // 0x80195150: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
L_80195154:
    // 0x80195154: lwc1        $f4, 0x28($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X28);
    // 0x80195158: lwc1        $f6, 0x28($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X28);
    // 0x8019515C: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80195160: addiu       $a1, $a1, 0x7210
    ctx->r5 = ADD32(ctx->r5, 0X7210);
    // 0x80195164: addiu       $a2, $zero, 0x58
    ctx->r6 = ADD32(0, 0X58);
    // 0x80195168: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x8019516C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x80195170: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80195174: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80195178: jal         0x8009D994
    // 0x8019517C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_15;
    // 0x8019517C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_15:
    // 0x80195180: lui         $at, 0x4326
    ctx->r1 = S32(0X4326 << 16);
L_80195184:
    // 0x80195184: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195188: lui         $at, 0x4355
    ctx->r1 = S32(0X4355 << 16);
    // 0x8019518C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80195190: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80195194: addiu       $a1, $a1, 0x6E50
    ctx->r5 = ADD32(ctx->r5, 0X6E50);
    // 0x80195198: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019519C: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x801951A0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x801951A4: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x801951A8: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x801951AC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801951B0: jal         0x8009D994
    // 0x801951B4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_16;
    // 0x801951B4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_16:
    // 0x801951B8: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801951BC: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801951C0: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x801951C4: addiu       $s2, $s2, -0x1410
    ctx->r18 = ADD32(ctx->r18, -0X1410);
    // 0x801951C8: addiu       $s0, $s0, -0x14B8
    ctx->r16 = ADD32(ctx->r16, -0X14B8);
    // 0x801951CC: addiu       $s1, $s1, -0x1560
    ctx->r17 = ADD32(ctx->r17, -0X1560);
L_801951D0:
    // 0x801951D0: or          $t4, $s1, $zero
    ctx->r12 = ctx->r17 | 0;
    // 0x801951D4: or          $t5, $sp, $zero
    ctx->r13 = ctx->r29 | 0;
    // 0x801951D8: addiu       $t3, $s1, 0x30
    ctx->r11 = ADD32(ctx->r17, 0X30);
L_801951DC:
    // 0x801951DC: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x801951E0: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x801951E4: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x801951E8: sw          $at, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r1;
    // 0x801951EC: lw          $at, -0x8($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X8);
    // 0x801951F0: sw          $at, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r1;
    // 0x801951F4: lw          $at, -0x4($t4)
    ctx->r1 = MEM_W(ctx->r12, -0X4);
    // 0x801951F8: bne         $t4, $t3, L_801951DC
    if (ctx->r12 != ctx->r11) {
        // 0x801951FC: sw          $at, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r1;
            goto L_801951DC;
    }
    // 0x801951FC: sw          $at, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r1;
    // 0x80195200: lw          $at, 0x0($t4)
    ctx->r1 = MEM_W(ctx->r12, 0X0);
    // 0x80195204: sw          $at, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r1;
    // 0x80195208: lw          $t3, 0x4($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X4);
    // 0x8019520C: sw          $t3, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r11;
    // 0x80195210: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80195214: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80195218: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8019521C: jal         0x8019C120
    // 0x80195220: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_17;
    // 0x80195220: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_17:
    // 0x80195224: or          $t8, $s0, $zero
    ctx->r24 = ctx->r16 | 0;
    // 0x80195228: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
    // 0x8019522C: addiu       $t7, $s0, 0x30
    ctx->r15 = ADD32(ctx->r16, 0X30);
L_80195230:
    // 0x80195230: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80195234: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x80195238: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8019523C: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x80195240: lw          $at, -0x8($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X8);
    // 0x80195244: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x80195248: lw          $at, -0x4($t8)
    ctx->r1 = MEM_W(ctx->r24, -0X4);
    // 0x8019524C: bne         $t8, $t7, L_80195230
    if (ctx->r24 != ctx->r15) {
        // 0x80195250: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_80195230;
    }
    // 0x80195250: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x80195254: lw          $at, 0x0($t8)
    ctx->r1 = MEM_W(ctx->r24, 0X0);
    // 0x80195258: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8019525C: lw          $t7, 0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X4);
    // 0x80195260: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x80195264: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x80195268: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8019526C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80195270: jal         0x8019C120
    // 0x80195274: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_18;
    // 0x80195274: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_18:
    // 0x80195278: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x8019527C: bne         $s0, $s2, L_801951D0
    if (ctx->r16 != ctx->r18) {
        // 0x80195280: addiu       $s1, $s1, 0x38
        ctx->r17 = ADD32(ctx->r17, 0X38);
            goto L_801951D0;
    }
    // 0x80195280: addiu       $s1, $s1, 0x38
    ctx->r17 = ADD32(ctx->r17, 0X38);
    // 0x80195284: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80195288: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8019528C: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x80195290: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80195294: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80195298: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8019529C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x801952A0: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x801952A4: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x801952A8: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x801952AC: jr          $ra
    // 0x801952B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x801952B0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Option_ScrollPlanetTexture(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192738: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019273C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80192740: addiu       $v1, $v1, -0x6C18
    ctx->r3 = ADD32(ctx->r3, -0X6C18);
    // 0x80192744: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80192748: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019274C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80192750: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80192754: bne         $v0, $at, L_801927B4
    if (ctx->r2 != ctx->r1) {
        // 0x80192758: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_801927B4;
    }
    // 0x80192758: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x8019275C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80192760: lw          $v0, 0x68F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68F4);
    // 0x80192764: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80192768: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8019276C: sll         $t7, $v0, 4
    ctx->r15 = S32(ctx->r2 << 4);
    // 0x80192770: srl         $t8, $t7, 28
    ctx->r24 = S32(U32(ctx->r15) >> 28);
    // 0x80192774: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80192778: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x8019277C: lw          $t0, 0x1FD0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1FD0);
    // 0x80192780: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80192784: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x80192788: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019278C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x80192790: addu        $a1, $t6, $t0
    ctx->r5 = ADD32(ctx->r14, ctx->r8);
    // 0x80192794: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x80192798: addiu       $a2, $a2, -0x27C8
    ctx->r6 = ADD32(ctx->r6, -0X27C8);
    // 0x8019279C: jal         0x801A07E8
    // 0x801927A0: lw          $a0, 0x68D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68D0);
    Map_Texture_Sphere(rdram, ctx);
        goto after_0;
    // 0x801927A0: lw          $a0, 0x68D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68D0);
    after_0:
    // 0x801927A4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801927A8: addiu       $v1, $v1, -0x6C18
    ctx->r3 = ADD32(ctx->r3, -0X6C18);
    // 0x801927AC: b           L_801927B8
    // 0x801927B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_801927B8;
    // 0x801927B0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801927B4:
    // 0x801927B4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_801927B8:
    // 0x801927B8: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x801927BC: addiu       $a3, $a3, -0x6C14
    ctx->r7 = ADD32(ctx->r7, -0X6C14);
    // 0x801927C0: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x801927C4: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x801927C8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x801927CC: sll         $v0, $t2, 3
    ctx->r2 = S32(ctx->r10 << 3);
    // 0x801927D0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x801927D4: lw          $v1, 0x68D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X68D4);
    // 0x801927D8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801927DC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801927E0: sll         $t5, $v1, 4
    ctx->r13 = S32(ctx->r3 << 4);
    // 0x801927E4: srl         $t7, $t5, 28
    ctx->r15 = S32(U32(ctx->r13) >> 28);
    // 0x801927E8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801927EC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801927F0: lw          $t9, 0x1FD0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1FD0);
    // 0x801927F4: and         $t4, $v1, $at
    ctx->r12 = ctx->r3 & ctx->r1;
    // 0x801927F8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801927FC: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x80192800: addiu       $t6, $t6, -0x27E8
    ctx->r14 = ADD32(ctx->r14, -0X27E8);
    // 0x80192804: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80192808: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8019280C: addu        $a1, $t4, $t9
    ctx->r5 = ADD32(ctx->r12, ctx->r25);
    // 0x80192810: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x80192814: lw          $a0, 0x68B0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68B0);
    // 0x80192818: jal         0x801A07E8
    // 0x8019281C: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    Map_Texture_Sphere(rdram, ctx);
        goto after_1;
    // 0x8019281C: addu        $a2, $v0, $t6
    ctx->r6 = ADD32(ctx->r2, ctx->r14);
    after_1:
    // 0x80192820: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80192824: addiu       $a3, $a3, -0x6C14
    ctx->r7 = ADD32(ctx->r7, -0X6C14);
    // 0x80192828: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8019282C: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80192830: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80192834: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80192838: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8019283C: lw          $v1, 0x68D8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X68D8);
    // 0x80192840: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80192844: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x80192848: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x8019284C: srl         $t5, $t3, 28
    ctx->r13 = S32(U32(ctx->r11) >> 28);
    // 0x80192850: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80192854: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80192858: lw          $t8, 0x1FD0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1FD0);
    // 0x8019285C: and         $t2, $v1, $at
    ctx->r10 = ctx->r3 & ctx->r1;
    // 0x80192860: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80192864: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x80192868: addiu       $t9, $t9, -0x27E8
    ctx->r25 = ADD32(ctx->r25, -0X27E8);
    // 0x8019286C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80192870: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80192874: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x80192878: addu        $a1, $t2, $t8
    ctx->r5 = ADD32(ctx->r10, ctx->r24);
    // 0x8019287C: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x80192880: addu        $a2, $t4, $t9
    ctx->r6 = ADD32(ctx->r12, ctx->r25);
    // 0x80192884: jal         0x801A07E8
    // 0x80192888: lw          $a0, 0x68B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68B4);
    Map_Texture_Sphere(rdram, ctx);
        goto after_2;
    // 0x80192888: lw          $a0, 0x68B4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X68B4);
    after_2:
    // 0x8019288C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80192890: addiu       $a3, $a3, -0x6C14
    ctx->r7 = ADD32(ctx->r7, -0X6C14);
    // 0x80192894: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80192898: addiu       $t0, $t6, 0x1
    ctx->r8 = ADD32(ctx->r14, 0X1);
    // 0x8019289C: slti        $at, $t0, 0x4
    ctx->r1 = SIGNED(ctx->r8) < 0X4 ? 1 : 0;
    // 0x801928A0: bne         $at, $zero, L_801928AC
    if (ctx->r1 != 0) {
        // 0x801928A4: sw          $t0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r8;
            goto L_801928AC;
    }
    // 0x801928A4: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x801928A8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_801928AC:
    // 0x801928AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801928B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801928B4: jr          $ra
    // 0x801928B8: nop

    return;
    // 0x801928B8: nop

;}
RECOMP_FUNC void Map_ZoomPlanet_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A1C14: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801A1C18: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A1C1C: addiu       $t0, $t0, -0x26B8
    ctx->r8 = ADD32(ctx->r8, -0X26B8);
    // 0x801A1C20: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801A1C24: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x801A1C28: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801A1C2C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801A1C30: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801A1C34: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801A1C38: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801A1C3C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A1C40: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x801A1C44: sltiu       $at, $t6, 0x16
    ctx->r1 = ctx->r14 < 0X16 ? 1 : 0;
    // 0x801A1C48: beq         $at, $zero, L_801A22C8
    if (ctx->r1 == 0) {
        // 0x801A1C4C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_801A22C8;
    }
    // 0x801A1C4C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801A1C50: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1C54: addu        $at, $at, $t6
    gpr jr_addend_801A1C5C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A1C58: lw          $t6, 0x75F8($at)
    ctx->r14 = ADD32(ctx->r1, 0X75F8);
    // 0x801A1C5C: jr          $t6
    // 0x801A1C60: nop

    switch (jr_addend_801A1C5C >> 2) {
        case 0: goto L_801A1C64; break;
        case 1: goto L_801A1DB0; break;
        case 2: goto L_801A1EF4; break;
        case 3: goto L_801A22B8; break;
        case 4: goto L_801A22C8; break;
        case 5: goto L_801A22C8; break;
        case 6: goto L_801A22C8; break;
        case 7: goto L_801A22C8; break;
        case 8: goto L_801A22C8; break;
        case 9: goto L_801A22C8; break;
        case 10: goto L_801A1EA4; break;
        case 11: goto L_801A22C8; break;
        case 12: goto L_801A22C8; break;
        case 13: goto L_801A22C8; break;
        case 14: goto L_801A22C8; break;
        case 15: goto L_801A22C8; break;
        case 16: goto L_801A22C8; break;
        case 17: goto L_801A22C8; break;
        case 18: goto L_801A22C8; break;
        case 19: goto L_801A22C8; break;
        case 20: goto L_801A21A4; break;
        case 21: goto L_801A2248; break;
        default: switch_error(__func__, 0x801A1C5C, 0x801B75F8);
    }
    // 0x801A1C60: nop

L_801A1C64:
    // 0x801A1C64: jal         0x801A1AE8
    // 0x801A1C68: nop

    Map_ZoomPlanet_Setup(rdram, ctx);
        goto after_0;
    // 0x801A1C68: nop

    after_0:
    // 0x801A1C6C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1C70: lwc1        $f0, 0x7650($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7650);
    // 0x801A1C74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1C78: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A1C7C: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A1C80: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
    // 0x801A1C84: addiu       $a0, $a0, -0x263C
    ctx->r4 = ADD32(ctx->r4, -0X263C);
    // 0x801A1C88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801A1C8C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x801A1C90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1C94: swc1        $f4, -0x1578($at)
    MEM_W(-0X1578, ctx->r1) = ctx->f4.u32l;
    // 0x801A1C98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1C9C: swc1        $f6, -0x1574($at)
    MEM_W(-0X1574, ctx->r1) = ctx->f6.u32l;
    // 0x801A1CA0: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x801A1CA4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A1CA8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1CAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A1CB0: swc1        $f8, -0x1570($at)
    MEM_W(-0X1570, ctx->r1) = ctx->f8.u32l;
    // 0x801A1CB4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1CB8: swc1        $f0, -0x1588($at)
    MEM_W(-0X1588, ctx->r1) = ctx->f0.u32l;
    // 0x801A1CBC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1CC0: swc1        $f0, -0x1584($at)
    MEM_W(-0X1584, ctx->r1) = ctx->f0.u32l;
    // 0x801A1CC4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1CC8: swc1        $f0, -0x1580($at)
    MEM_W(-0X1580, ctx->r1) = ctx->f0.u32l;
    // 0x801A1CCC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1CD0: swc1        $f0, -0x157C($at)
    MEM_W(-0X157C, ctx->r1) = ctx->f0.u32l;
    // 0x801A1CD4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1CD8: swc1        $f10, -0x156C($at)
    MEM_W(-0X156C, ctx->r1) = ctx->f10.u32l;
    // 0x801A1CDC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A1CE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1CE4: addiu       $v1, $v1, -0x26A4
    ctx->r3 = ADD32(ctx->r3, -0X26A4);
    // 0x801A1CE8: sw          $zero, -0x1568($at)
    MEM_W(-0X1568, ctx->r1) = 0;
    // 0x801A1CEC: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801A1CF0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801A1CF4: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A1CF8: lw          $t8, -0x26AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26AC);
    // 0x801A1CFC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1D00: sw          $zero, -0x2684($at)
    MEM_W(-0X2684, ctx->r1) = 0;
    // 0x801A1D04: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A1D08: bne         $t8, $at, L_801A1D18
    if (ctx->r24 != ctx->r1) {
        // 0x801A1D0C: lui         $s0, 0x801D
        ctx->r16 = S32(0X801D << 16);
            goto L_801A1D18;
    }
    // 0x801A1D0C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A1D10: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x801A1D14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_801A1D18:
    // 0x801A1D18: addiu       $s0, $s0, -0x2628
    ctx->r16 = ADD32(ctx->r16, -0X2628);
    // 0x801A1D1C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A1D20: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x801A1D24: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x801A1D28: addiu       $v1, $v1, -0x48
    ctx->r3 = ADD32(ctx->r3, -0X48);
    // 0x801A1D2C: addiu       $v0, $v0, -0x2E8
    ctx->r2 = ADD32(ctx->r2, -0X2E8);
L_801A1D30:
    // 0x801A1D30: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // 0x801A1D34: sw          $zero, -0x3C($v0)
    MEM_W(-0X3C, ctx->r2) = 0;
    // 0x801A1D38: sw          $zero, -0x20($v0)
    MEM_W(-0X20, ctx->r2) = 0;
    // 0x801A1D3C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801A1D40: bne         $v0, $v1, L_801A1D30
    if (ctx->r2 != ctx->r3) {
        // 0x801A1D44: sw          $zero, -0x58($v0)
        MEM_W(-0X58, ctx->r2) = 0;
            goto L_801A1D30;
    }
    // 0x801A1D44: sw          $zero, -0x58($v0)
    MEM_W(-0X58, ctx->r2) = 0;
    // 0x801A1D48: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A1D4C: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x801A1D50: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A1D54: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801A1D58: sw          $t2, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = ctx->r10;
    // 0x801A1D5C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A1D60: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801A1D64: sw          $t3, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = ctx->r11;
    // 0x801A1D68: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801A1D6C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A1D70: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x801A1D74: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801A1D78: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x801A1D7C: sw          $t4, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = ctx->r12;
    // 0x801A1D80: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x801A1D84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1D88: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A1D8C: lw          $t6, -0x26B8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26B8);
    // 0x801A1D90: swc1        $f16, -0x14C4($at)
    MEM_W(-0X14C4, ctx->r1) = ctx->f16.u32l;
    // 0x801A1D94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1D98: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x801A1D9C: sw          $t5, -0x14C8($at)
    MEM_W(-0X14C8, ctx->r1) = ctx->r13;
    // 0x801A1DA0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1DA4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801A1DA8: b           L_801A22C8
    // 0x801A1DAC: sw          $t7, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r15;
        goto L_801A22C8;
    // 0x801A1DAC: sw          $t7, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r15;
L_801A1DB0:
    // 0x801A1DB0: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A1DB4: addiu       $v1, $v1, -0x26A4
    ctx->r3 = ADD32(ctx->r3, -0X26A4);
    // 0x801A1DB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801A1DBC: bne         $v0, $zero, L_801A1E64
    if (ctx->r2 != 0) {
        // 0x801A1DC0: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801A1E64;
    }
    // 0x801A1DC0: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A1DC4: lw          $t8, -0x26AC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26AC);
    // 0x801A1DC8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A1DCC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A1DD0: bne         $t8, $at, L_801A1E24
    if (ctx->r24 != ctx->r1) {
        // 0x801A1DD4: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_801A1E24;
    }
    // 0x801A1DD4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A1DD8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A1DDC: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801A1DE0: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801A1DE4: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x801A1DE8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A1DEC: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x801A1DF0: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801A1DF4: lui         $a0, 0x940
    ctx->r4 = S32(0X940 << 16);
    // 0x801A1DF8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A1DFC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x801A1E00: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x801A1E04: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A1E08: ori         $a0, $a0, 0xA00B
    ctx->r4 = ctx->r4 | 0XA00B;
    // 0x801A1E0C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801A1E10: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A1E14: jal         0x80019218
    // 0x801A1E18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x801A1E18: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x801A1E1C: b           L_801A22C8
    // 0x801A1E20: nop

        goto L_801A22C8;
    // 0x801A1E20: nop

L_801A1E24:
    // 0x801A1E24: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x801A1E28: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x801A1E2C: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801A1E30: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A1E34: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A1E38: ori         $a0, $a0, 0x3012
    ctx->r4 = ctx->r4 | 0X3012;
    // 0x801A1E3C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801A1E40: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A1E44: jal         0x80019218
    // 0x801A1E48: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801A1E48: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x801A1E4C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A1E50: lw          $t4, -0x26B8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26B8);
    // 0x801A1E54: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1E58: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801A1E5C: b           L_801A22C8
    // 0x801A1E60: sw          $t5, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r13;
        goto L_801A22C8;
    // 0x801A1E60: sw          $t5, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r13;
L_801A1E64:
    // 0x801A1E64: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A1E68: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x801A1E6C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A1E70: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x801A1E74: bne         $t6, $at, L_801A1E9C
    if (ctx->r14 != ctx->r1) {
        // 0x801A1E78: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_801A1E9C;
    }
    // 0x801A1E78: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x801A1E7C: addiu       $t1, $t1, -0x7CC0
    ctx->r9 = ADD32(ctx->r9, -0X7CC0);
    // 0x801A1E80: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x801A1E84: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A1E88: xori        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 ^ 0XFF;
    // 0x801A1E8C: bne         $v0, $at, L_801A1E9C
    if (ctx->r2 != ctx->r1) {
        // 0x801A1E90: sw          $t8, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r24;
            goto L_801A1E9C;
    }
    // 0x801A1E90: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x801A1E94: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1E98: sw          $zero, -0x14CC($at)
    MEM_W(-0X14CC, ctx->r1) = 0;
L_801A1E9C:
    // 0x801A1E9C: b           L_801A22C8
    // 0x801A1EA0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_801A22C8;
    // 0x801A1EA0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_801A1EA4:
    // 0x801A1EA4: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A1EA8: lw          $t2, -0x14CC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X14CC);
    // 0x801A1EAC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801A1EB0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A1EB4: bne         $t2, $at, L_801A22C8
    if (ctx->r10 != ctx->r1) {
        // 0x801A1EB8: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_801A22C8;
    }
    // 0x801A1EB8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A1EBC: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x801A1EC0: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x801A1EC4: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801A1EC8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A1ECC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A1ED0: ori         $a0, $a0, 0x3012
    ctx->r4 = ctx->r4 | 0X3012;
    // 0x801A1ED4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801A1ED8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A1EDC: jal         0x80019218
    // 0x801A1EE0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x801A1EE0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_3:
    // 0x801A1EE4: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801A1EE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1EEC: b           L_801A22C8
    // 0x801A1EF0: sw          $t4, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r12;
        goto L_801A22C8;
    // 0x801A1EF0: sw          $t4, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r12;
L_801A1EF4:
    // 0x801A1EF4: jal         0x801A2674
    // 0x801A1EF8: nop

    Map_801A2674(rdram, ctx);
        goto after_4;
    // 0x801A1EF8: nop

    after_4:
    // 0x801A1EFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A1F00: addiu       $v0, $v0, -0x25B0
    ctx->r2 = ADD32(ctx->r2, -0X25B0);
    // 0x801A1F04: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1F08: lwc1        $f4, -0x2604($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2604);
    // 0x801A1F0C: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A1F10: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A1F14: addiu       $s0, $s0, -0x2628
    ctx->r16 = ADD32(ctx->r16, -0X2628);
    // 0x801A1F18: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x801A1F1C: nop

    // 0x801A1F20: bc1f        L_801A20BC
    if (!c1cs) {
        // 0x801A1F24: nop
    
            goto L_801A20BC;
    }
    // 0x801A1F24: nop

    // 0x801A1F28: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x801A1F2C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A1F30: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A1F34: bne         $t5, $zero, L_801A20BC
    if (ctx->r13 != 0) {
        // 0x801A1F38: lui         $a0, 0x1900
        ctx->r4 = S32(0X1900 << 16);
            goto L_801A20BC;
    }
    // 0x801A1F38: lui         $a0, 0x1900
    ctx->r4 = S32(0X1900 << 16);
    // 0x801A1F3C: lui         $t6, 0x800C
    ctx->r14 = S32(0X800C << 16);
    // 0x801A1F40: addiu       $t6, $t6, 0x5D3C
    ctx->r14 = ADD32(ctx->r14, 0X5D3C);
    // 0x801A1F44: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A1F48: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A1F4C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801A1F50: ori         $a0, $a0, 0x4013
    ctx->r4 = ctx->r4 | 0X4013;
    // 0x801A1F54: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A1F58: jal         0x80019218
    // 0x801A1F5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x801A1F5C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_5:
    // 0x801A1F60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801A1F64: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x801A1F68: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A1F6C: lw          $t7, -0x26AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26AC);
    // 0x801A1F70: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A1F74: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801A1F78: bne         $t7, $at, L_801A20BC
    if (ctx->r15 != ctx->r1) {
        // 0x801A1F7C: addiu       $s1, $s1, -0x14A8
        ctx->r17 = ADD32(ctx->r17, -0X14A8);
            goto L_801A20BC;
    }
    // 0x801A1F7C: addiu       $s1, $s1, -0x14A8
    ctx->r17 = ADD32(ctx->r17, -0X14A8);
    // 0x801A1F80: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1F84: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x801A1F88: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801A1F8C: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x801A1F90: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x801A1F94: lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // 0x801A1F98: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A1F9C: sw          $a0, -0x14B8($at)
    MEM_W(-0X14B8, ctx->r1) = ctx->r4;
    // 0x801A1FA0: addiu       $s0, $s0, -0x1250
    ctx->r16 = ADD32(ctx->r16, -0X1250);
    // 0x801A1FA4: addiu       $s6, $s6, -0x12C8
    ctx->r22 = ADD32(ctx->r22, -0X12C8);
    // 0x801A1FA8: addiu       $s5, $s5, -0x11D8
    ctx->r21 = ADD32(ctx->r21, -0X11D8);
    // 0x801A1FAC: addiu       $s4, $s4, -0x1340
    ctx->r20 = ADD32(ctx->r20, -0X1340);
    // 0x801A1FB0: addiu       $s3, $s3, -0x13B8
    ctx->r19 = ADD32(ctx->r19, -0X13B8);
    // 0x801A1FB4: addiu       $s2, $s2, -0x1430
    ctx->r18 = ADD32(ctx->r18, -0X1430);
L_801A1FB8:
    // 0x801A1FB8: jal         0x80004EB0
    // 0x801A1FBC: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x801A1FBC: nop

    after_6:
    // 0x801A1FC0: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A1FC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A1FC8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801A1FCC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801A1FD0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801A1FD4: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x801A1FD8: swc1        $f16, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f16.u32l;
    // 0x801A1FDC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801A1FE0: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801A1FE4: jal         0x80004EB0
    // 0x801A1FE8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x801A1FE8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    after_7:
    // 0x801A1FEC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1FF0: lwc1        $f18, 0x7654($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7654);
    // 0x801A1FF4: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801A1FF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A1FFC: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801A2000: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A2004: jal         0x80004EB0
    // 0x801A2008: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x801A2008: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    after_8:
    // 0x801A200C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801A2010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A2014: nop

    // 0x801A2018: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801A201C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801A2020: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x801A2024: nop

    // 0x801A2028: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801A202C: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801A2030: nop

    // 0x801A2034: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801A2038: jal         0x80004EB0
    // 0x801A203C: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x801A203C: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    after_9:
    // 0x801A2040: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801A2044: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A2048: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x801A204C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A2050: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x801A2054: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801A2058: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x801A205C: nop

    // 0x801A2060: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x801A2064: nop

    // 0x801A2068: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801A206C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801A2070: jal         0x80004EB0
    // 0x801A2074: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x801A2074: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    after_10:
    // 0x801A2078: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x801A207C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A2080: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801A2084: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A2088: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801A208C: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A2090: addiu       $t8, $t8, -0x1228
    ctx->r24 = ADD32(ctx->r24, -0X1228);
    // 0x801A2094: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801A2098: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801A209C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x801A20A0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x801A20A4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A20A8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x801A20AC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x801A20B0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x801A20B4: bne         $s0, $t8, L_801A1FB8
    if (ctx->r16 != ctx->r24) {
        // 0x801A20B8: swc1        $f4, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f4.u32l;
            goto L_801A1FB8;
    }
    // 0x801A20B8: swc1        $f4, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f4.u32l;
L_801A20BC:
    // 0x801A20BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A20C0: addiu       $v0, $v0, -0x25B0
    ctx->r2 = ADD32(ctx->r2, -0X25B0);
    // 0x801A20C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A20C8: lwc1        $f8, -0x25CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25CC);
    // 0x801A20CC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A20D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801A20D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A20D8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x801A20DC: nop

    // 0x801A20E0: bc1f        L_801A22C8
    if (!c1cs) {
        // 0x801A20E4: nop
    
            goto L_801A22C8;
    }
    // 0x801A20E4: nop

    // 0x801A20E8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801A20EC: lwc1        $f16, -0x25C8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25C8);
    // 0x801A20F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A20F4: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x801A20F8: nop

    // 0x801A20FC: bc1f        L_801A22C8
    if (!c1cs) {
        // 0x801A2100: nop
    
            goto L_801A22C8;
    }
    // 0x801A2100: nop

    // 0x801A2104: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A2108: lwc1        $f4, -0x2604($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2604);
    // 0x801A210C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2110: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x801A2114: nop

    // 0x801A2118: bc1f        L_801A22C8
    if (!c1cs) {
        // 0x801A211C: nop
    
            goto L_801A22C8;
    }
    // 0x801A211C: nop

    // 0x801A2120: lwc1        $f6, -0x25B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25B8);
    // 0x801A2124: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2128: lwc1        $f8, -0x25F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801A212C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2130: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A2134: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x801A2138: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A213C: addiu       $v1, $v1, -0x26C4
    ctx->r3 = ADD32(ctx->r3, -0X26C4);
    // 0x801A2140: addiu       $v0, $v0, -0x26F4
    ctx->r2 = ADD32(ctx->r2, -0X26F4);
    // 0x801A2144: bc1f        L_801A22C8
    if (!c1cs) {
        // 0x801A2148: nop
    
            goto L_801A22C8;
    }
    // 0x801A2148: nop

    // 0x801A214C: sw          $a0, -0x269C($at)
    MEM_W(-0X269C, ctx->r1) = ctx->r4;
    // 0x801A2150: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2154: sw          $a0, -0x2694($at)
    MEM_W(-0X2694, ctx->r1) = ctx->r4;
    // 0x801A2158: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A215C: sw          $zero, -0x2700($at)
    MEM_W(-0X2700, ctx->r1) = 0;
    // 0x801A2160: sw          $zero, -0x26FC($at)
    MEM_W(-0X26FC, ctx->r1) = 0;
    // 0x801A2164: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2168: sw          $zero, -0x26F8($at)
    MEM_W(-0X26F8, ctx->r1) = 0;
L_801A216C:
    // 0x801A216C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A2170: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x801A2174: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x801A2178: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x801A217C: bne         $v0, $v1, L_801A216C
    if (ctx->r2 != ctx->r3) {
        // 0x801A2180: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_801A216C;
    }
    // 0x801A2180: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801A2184: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2188: jal         0x801A2304
    // 0x801A218C: sw          $zero, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = 0;
    Map_GralPepper_Talk(rdram, ctx);
        goto after_11;
    // 0x801A218C: sw          $zero, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = 0;
    after_11:
    // 0x801A2190: beq         $v0, $zero, L_801A22C8
    if (ctx->r2 == 0) {
        // 0x801A2194: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_801A22C8;
    }
    // 0x801A2194: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x801A2198: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A219C: b           L_801A22C8
    // 0x801A21A0: sw          $t9, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r25;
        goto L_801A22C8;
    // 0x801A21A0: sw          $t9, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r25;
L_801A21A4:
    // 0x801A21A4: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801A21A8: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x801A21AC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x801A21B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x801A21B4: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x801A21B8: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x801A21BC: sll         $v0, $t2, 1
    ctx->r2 = S32(ctx->r10 << 1);
    // 0x801A21C0: addu        $t3, $t3, $v0
    ctx->r11 = ADD32(ctx->r11, ctx->r2);
    // 0x801A21C4: lhu         $t3, -0x2768($t3)
    ctx->r11 = MEM_HU(ctx->r11, -0X2768);
    // 0x801A21C8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x801A21CC: addiu       $t5, $zero, 0x15
    ctx->r13 = ADD32(0, 0X15);
    // 0x801A21D0: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x801A21D4: beq         $t4, $zero, L_801A21E0
    if (ctx->r12 == 0) {
        // 0x801A21D8: lui         $v0, 0x801D
        ctx->r2 = S32(0X801D << 16);
            goto L_801A21E0;
    }
    // 0x801A21D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A21DC: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_801A21E0:
    // 0x801A21E0: lhu         $v1, -0x2780($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X2780);
    // 0x801A21E4: addiu       $v0, $v0, -0x2604
    ctx->r2 = ADD32(ctx->r2, -0X2604);
    // 0x801A21E8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A21EC: andi        $t6, $v1, 0x10
    ctx->r14 = ctx->r3 & 0X10;
    // 0x801A21F0: beq         $t6, $zero, L_801A220C
    if (ctx->r14 == 0) {
        // 0x801A21F4: andi        $t7, $v1, 0x2000
        ctx->r15 = ctx->r3 & 0X2000;
            goto L_801A220C;
    }
    // 0x801A21F4: andi        $t7, $v1, 0x2000
    ctx->r15 = ctx->r3 & 0X2000;
    // 0x801A21F8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A21FC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A2200: nop

    // 0x801A2204: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801A2208: swc1        $f18, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f18.u32l;
L_801A220C:
    // 0x801A220C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2210: beq         $t7, $zero, L_801A22C8
    if (ctx->r15 == 0) {
        // 0x801A2214: addiu       $v0, $v0, -0x2604
        ctx->r2 = ADD32(ctx->r2, -0X2604);
            goto L_801A22C8;
    }
    // 0x801A2214: addiu       $v0, $v0, -0x2604
    ctx->r2 = ADD32(ctx->r2, -0X2604);
    // 0x801A2218: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801A221C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A2220: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A2224: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2228: lwc1        $f8, -0x25F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801A222C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A2230: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x801A2234: nop

    // 0x801A2238: bc1f        L_801A22C8
    if (!c1cs) {
        // 0x801A223C: nop
    
            goto L_801A22C8;
    }
    // 0x801A223C: nop

    // 0x801A2240: b           L_801A22C8
    // 0x801A2244: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
        goto L_801A22C8;
    // 0x801A2244: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_801A2248:
    // 0x801A2248: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A224C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2250: sw          $v0, -0x269C($at)
    MEM_W(-0X269C, ctx->r1) = ctx->r2;
    // 0x801A2254: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2258: sw          $v0, -0x2694($at)
    MEM_W(-0X2694, ctx->r1) = ctx->r2;
    // 0x801A225C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2260: sw          $zero, -0x2700($at)
    MEM_W(-0X2700, ctx->r1) = 0;
    // 0x801A2264: sw          $zero, -0x26FC($at)
    MEM_W(-0X26FC, ctx->r1) = 0;
    // 0x801A2268: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A226C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2270: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A2274: addiu       $v1, $v1, -0x26C4
    ctx->r3 = ADD32(ctx->r3, -0X26C4);
    // 0x801A2278: addiu       $v0, $v0, -0x26F4
    ctx->r2 = ADD32(ctx->r2, -0X26F4);
    // 0x801A227C: sw          $zero, -0x26F8($at)
    MEM_W(-0X26F8, ctx->r1) = 0;
L_801A2280:
    // 0x801A2280: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801A2284: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x801A2288: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x801A228C: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x801A2290: bne         $v0, $v1, L_801A2280
    if (ctx->r2 != ctx->r3) {
        // 0x801A2294: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_801A2280;
    }
    // 0x801A2294: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801A2298: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A229C: jal         0x801A2304
    // 0x801A22A0: sw          $zero, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = 0;
    Map_GralPepper_Talk(rdram, ctx);
        goto after_12;
    // 0x801A22A0: sw          $zero, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = 0;
    after_12:
    // 0x801A22A4: beq         $v0, $zero, L_801A22C8
    if (ctx->r2 == 0) {
        // 0x801A22A8: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_801A22C8;
    }
    // 0x801A22A8: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801A22AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A22B0: b           L_801A22C8
    // 0x801A22B4: sw          $t8, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r24;
        goto L_801A22C8;
    // 0x801A22B4: sw          $t8, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = ctx->r24;
L_801A22B8:
    // 0x801A22B8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x801A22BC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801A22C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A22C4: sw          $t9, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r25;
L_801A22C8:
    // 0x801A22C8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A22CC: addiu       $a0, $a0, -0x263C
    ctx->r4 = ADD32(ctx->r4, -0X263C);
    // 0x801A22D0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x801A22D4: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x801A22D8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x801A22DC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801A22E0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A22E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801A22E8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801A22EC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x801A22F0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x801A22F4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x801A22F8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x801A22FC: jr          $ra
    // 0x801A2300: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801A2300: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Option_MainMenu_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192D58: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80192D5C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80192D60: addiu       $t0, $t0, -0x6ED4
    ctx->r8 = ADD32(ctx->r8, -0X6ED4);
    // 0x80192D64: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80192D68: sw          $s7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r23;
    // 0x80192D6C: sw          $s6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r22;
    // 0x80192D70: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x80192D74: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x80192D78: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x80192D7C: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x80192D80: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80192D84: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80192D88: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80192D8C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80192D90: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80192D94: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80192D98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80192D9C: beq         $v1, $zero, L_80192DE0
    if (ctx->r3 == 0) {
        // 0x80192DA0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80192DE0;
    }
    // 0x80192DA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80192DA4: beq         $v1, $at, L_80193114
    if (ctx->r3 == ctx->r1) {
        // 0x80192DA8: lui         $s4, 0x8017
        ctx->r20 = S32(0X8017 << 16);
            goto L_80193114;
    }
    // 0x80192DA8: lui         $s4, 0x8017
    ctx->r20 = S32(0X8017 << 16);
    // 0x80192DAC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80192DB0: beq         $v1, $at, L_801934A0
    if (ctx->r3 == ctx->r1) {
        // 0x80192DB4: lui         $a0, 0x8016
        ctx->r4 = S32(0X8016 << 16);
            goto L_801934A0;
    }
    // 0x80192DB4: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80192DB8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80192DBC: beq         $v0, $at, L_80193544
    if (ctx->r2 == ctx->r1) {
        // 0x80192DC0: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_80193544;
    }
    // 0x80192DC0: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80192DC4: beq         $v0, $at, L_801937C0
    if (ctx->r2 == ctx->r1) {
        // 0x80192DC8: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801937C0;
    }
    // 0x80192DC8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80192DCC: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80192DD0: beq         $v0, $at, L_80192E8C
    if (ctx->r2 == ctx->r1) {
        // 0x80192DD4: lui         $s0, 0x801B
        ctx->r16 = S32(0X801B << 16);
            goto L_80192E8C;
    }
    // 0x80192DD4: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80192DD8: b           L_80193830
    // 0x80192DDC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_80193830;
    // 0x80192DDC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80192DE0:
    // 0x80192DE0: jal         0x801929F0
    // 0x80192DE4: nop

    Option_MainMenu_Setup(rdram, ctx);
        goto after_0;
    // 0x80192DE4: nop

    after_0:
    // 0x80192DE8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80192DEC: lw          $t6, -0x6DBC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DBC);
    // 0x80192DF0: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80192DF4: addiu       $a1, $a1, -0x1A48
    ctx->r5 = ADD32(ctx->r5, -0X1A48);
    // 0x80192DF8: bne         $t6, $zero, L_80192E18
    if (ctx->r14 != 0) {
        // 0x80192DFC: lui         $a2, 0x801B
        ctx->r6 = S32(0X801B << 16);
            goto L_80192E18;
    }
    // 0x80192DFC: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80192E00: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80192E04: lw          $t7, -0x6ED4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6ED4);
    // 0x80192E08: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192E0C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80192E10: b           L_8019382C
    // 0x80192E14: sw          $t8, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r24;
        goto L_8019382C;
    // 0x80192E14: sw          $t8, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r24;
L_80192E18:
    // 0x80192E18: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80192E1C: addiu       $s1, $s1, -0x6E50
    ctx->r17 = ADD32(ctx->r17, -0X6E50);
    // 0x80192E20: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80192E24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192E28: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x80192E2C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80192E30: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80192E34: lwc1        $f4, -0x1A18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1A18);
    // 0x80192E38: addiu       $s2, $s2, -0x6E54
    ctx->r18 = ADD32(ctx->r18, -0X6E54);
    // 0x80192E3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192E40: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80192E44: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80192E48: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80192E4C: lwc1        $f6, -0x1A10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1A10);
    // 0x80192E50: addiu       $a2, $a2, -0x1A30
    ctx->r6 = ADD32(ctx->r6, -0X1A30);
    // 0x80192E54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192E58: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80192E5C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80192E60: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x80192E64: lwc1        $f8, -0x1A08($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A08);
    // 0x80192E68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192E6C: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80192E70: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x80192E74: lwc1        $f10, -0x1A00($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1A00);
    // 0x80192E78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192E7C: addiu       $t2, $zero, 0x3E8
    ctx->r10 = ADD32(0, 0X3E8);
    // 0x80192E80: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
    // 0x80192E84: b           L_8019382C
    // 0x80192E88: sw          $t2, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r10;
        goto L_8019382C;
    // 0x80192E88: sw          $t2, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r10;
L_80192E8C:
    // 0x80192E8C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192E90: lwc1        $f24, 0x7334($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X7334);
    // 0x80192E94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192E98: lwc1        $f22, 0x7338($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7338);
    // 0x80192E9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80192EA0: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x80192EA4: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80192EA8: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x80192EAC: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x80192EB0: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x80192EB4: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x80192EB8: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80192EBC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80192EC0: addiu       $s3, $s3, -0x19E0
    ctx->r19 = ADD32(ctx->r19, -0X19E0);
    // 0x80192EC4: addiu       $s2, $s2, -0x1A48
    ctx->r18 = ADD32(ctx->r18, -0X1A48);
    // 0x80192EC8: addiu       $s7, $s7, -0x19B0
    ctx->r23 = ADD32(ctx->r23, -0X19B0);
    // 0x80192ECC: addiu       $s6, $s6, -0x1A90
    ctx->r22 = ADD32(ctx->r22, -0X1A90);
    // 0x80192ED0: addiu       $s5, $s5, -0x198C
    ctx->r21 = ADD32(ctx->r21, -0X198C);
    // 0x80192ED4: addiu       $s1, $s1, -0x1A30
    ctx->r17 = ADD32(ctx->r17, -0X1A30);
    // 0x80192ED8: addiu       $s4, $s4, -0x19AC
    ctx->r20 = ADD32(ctx->r20, -0X19AC);
    // 0x80192EDC: addiu       $s0, $s0, -0x19C8
    ctx->r16 = ADD32(ctx->r16, -0X19C8);
L_80192EE0:
    // 0x80192EE0: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80192EE4: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x80192EE8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192EEC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80192EF0: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80192EF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80192EF8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80192EFC: bc1fl       L_80192F2C
    if (!c1cs) {
        // 0x80192F00: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_80192F2C;
    }
    goto skip_0;
    // 0x80192F00: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_0:
    // 0x80192F04: lwc1        $f16, 0x733C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X733C);
    // 0x80192F08: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x80192F0C: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    // 0x80192F10: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80192F14: c.lt.s      $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f22.fl < ctx->f4.fl;
    // 0x80192F18: nop

    // 0x80192F1C: bc1fl       L_80192F2C
    if (!c1cs) {
        // 0x80192F20: lwc1        $f0, 0x20($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
            goto L_80192F2C;
    }
    goto skip_1;
    // 0x80192F20: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    skip_1:
    // 0x80192F24: swc1        $f22, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f22.u32l;
    // 0x80192F28: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
L_80192F2C:
    // 0x80192F2C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80192F30: nop

    // 0x80192F34: bc1fl       L_80192F60
    if (!c1cs) {
        // 0x80192F38: lw          $a1, 0x0($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X0);
            goto L_80192F60;
    }
    goto skip_2;
    // 0x80192F38: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x80192F3C: add.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x80192F40: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80192F44: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80192F48: c.lt.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl < ctx->f8.fl;
    // 0x80192F4C: nop

    // 0x80192F50: bc1fl       L_80192F60
    if (!c1cs) {
        // 0x80192F54: lw          $a1, 0x0($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X0);
            goto L_80192F60;
    }
    goto skip_3;
    // 0x80192F54: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    skip_3:
    // 0x80192F58: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x80192F5C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
L_80192F60:
    // 0x80192F60: jal         0x8009BC2C
    // 0x80192F64: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x80192F64: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_1:
    // 0x80192F68: lui         $a2, 0x3E19
    ctx->r6 = S32(0X3E19 << 16);
    // 0x80192F6C: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x80192F70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80192F74: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x80192F78: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80192F7C: jal         0x8009BC2C
    // 0x80192F80: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x80192F80: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_2:
    // 0x80192F84: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80192F88: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80192F8C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80192F90: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80192F94: lw          $a3, 0x0($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X0);
    // 0x80192F98: jal         0x8009BC2C
    // 0x80192F9C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x80192F9C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_3:
    // 0x80192FA0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80192FA4: addiu       $t3, $t3, -0x19C8
    ctx->r11 = ADD32(ctx->r11, -0X19C8);
    // 0x80192FA8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80192FAC: sltu        $at, $s3, $t3
    ctx->r1 = ctx->r19 < ctx->r11 ? 1 : 0;
    // 0x80192FB0: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    // 0x80192FB4: addiu       $s4, $s4, 0x60
    ctx->r20 = ADD32(ctx->r20, 0X60);
    // 0x80192FB8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80192FBC: addiu       $s5, $s5, 0x60
    ctx->r21 = ADD32(ctx->r21, 0X60);
    // 0x80192FC0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80192FC4: addiu       $s7, $s7, 0x60
    ctx->r23 = ADD32(ctx->r23, 0X60);
    // 0x80192FC8: bne         $at, $zero, L_80192EE0
    if (ctx->r1 != 0) {
        // 0x80192FCC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80192EE0;
    }
    // 0x80192FCC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80192FD0: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80192FD4: addiu       $s5, $s5, -0x6E5C
    ctx->r21 = ADD32(ctx->r21, -0X6E5C);
    // 0x80192FD8: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x80192FDC: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x80192FE0: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80192FE4: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80192FE8: addiu       $a0, $a0, 0x1A38
    ctx->r4 = ADD32(ctx->r4, 0X1A38);
    // 0x80192FEC: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x80192FF0: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80192FF4: addiu       $s3, $s3, -0x19C8
    ctx->r19 = ADD32(ctx->r19, -0X19C8);
    // 0x80192FF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80192FFC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x80193000: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80193004: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
    // 0x80193008: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8019300C: mflo        $t6
    ctx->r14 = lo;
    // 0x80193010: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80193014: lwc1        $f10, 0x3C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X3C);
    // 0x80193018: lwc1        $f16, -0x1A90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1A90);
    // 0x8019301C: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80193020: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80193024: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x80193028: addiu       $a2, $a2, -0x1A30
    ctx->r6 = ADD32(ctx->r6, -0X1A30);
    // 0x8019302C: addiu       $a1, $a1, -0x1A48
    ctx->r5 = ADD32(ctx->r5, -0X1A48);
    // 0x80193030: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193034: bc1f        L_8019382C
    if (!c1cs) {
        // 0x80193038: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8019382C;
    }
    // 0x80193038: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8019303C: swc1        $f20, -0x19A8($at)
    MEM_W(-0X19A8, ctx->r1) = ctx->f20.u32l;
    // 0x80193040: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193044: lwc1        $f18, -0x1A48($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1A48);
    // 0x80193048: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019304C: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193050: swc1        $f18, -0x19B0($at)
    MEM_W(-0X19B0, ctx->r1) = ctx->f18.u32l;
    // 0x80193054: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193058: lwc1        $f4, -0x1A30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1A30);
    // 0x8019305C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193060: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80193064: swc1        $f4, -0x19AC($at)
    MEM_W(-0X19AC, ctx->r1) = ctx->f4.u32l;
    // 0x80193068: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019306C: swc1        $f20, -0x1948($at)
    MEM_W(-0X1948, ctx->r1) = ctx->f20.u32l;
    // 0x80193070: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193074: lwc1        $f6, -0x1A44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1A44);
    // 0x80193078: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019307C: mflo        $t9
    ctx->r25 = lo;
    // 0x80193080: swc1        $f6, -0x1950($at)
    MEM_W(-0X1950, ctx->r1) = ctx->f6.u32l;
    // 0x80193084: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193088: lwc1        $f8, -0x1A2C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A2C);
    // 0x8019308C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193090: addu        $s0, $s3, $t9
    ctx->r16 = ADD32(ctx->r19, ctx->r25);
    // 0x80193094: swc1        $f8, -0x194C($at)
    MEM_W(-0X194C, ctx->r1) = ctx->f8.u32l;
    // 0x80193098: addu        $s2, $a1, $v0
    ctx->r18 = ADD32(ctx->r5, ctx->r2);
    // 0x8019309C: addu        $s1, $a2, $v0
    ctx->r17 = ADD32(ctx->r6, ctx->r2);
    // 0x801930A0: lwc1        $f10, 0x0($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X0);
    // 0x801930A4: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801930A8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801930AC: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x801930B0: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x801930B4: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801930B8: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x801930BC: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x801930C0: lwc1        $f18, 0x4($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X4);
    // 0x801930C4: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x801930C8: swc1        $f20, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->f20.u32l;
    // 0x801930CC: swc1        $f20, 0xE0($s0)
    MEM_W(0XE0, ctx->r16) = ctx->f20.u32l;
    // 0x801930D0: swc1        $f20, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->f20.u32l;
    // 0x801930D4: swc1        $f20, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f20.u32l;
    // 0x801930D8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801930DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801930E0: swc1        $f4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f4.u32l;
    // 0x801930E4: swc1        $f16, 0x13C($s0)
    MEM_W(0X13C, ctx->r16) = ctx->f16.u32l;
    // 0x801930E8: swc1        $f10, 0x138($s0)
    MEM_W(0X138, ctx->r16) = ctx->f10.u32l;
    // 0x801930EC: swc1        $f8, 0xDC($s0)
    MEM_W(0XDC, ctx->r16) = ctx->f8.u32l;
    // 0x801930F0: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    // 0x801930F4: swc1        $f6, 0xD8($s0)
    MEM_W(0XD8, ctx->r16) = ctx->f6.u32l;
    // 0x801930F8: sw          $t1, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = ctx->r9;
    // 0x801930FC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80193100: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x80193104: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193108: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8019310C: b           L_8019382C
    // 0x80193110: sw          $t3, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r11;
        goto L_8019382C;
    // 0x80193110: sw          $t3, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r11;
L_80193114:
    // 0x80193114: addiu       $s4, $s4, 0x7AF8
    ctx->r20 = ADD32(ctx->r20, 0X7AF8);
    // 0x80193118: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8019311C: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80193120: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80193124: addiu       $s5, $s5, -0x6E5C
    ctx->r21 = ADD32(ctx->r21, -0X6E5C);
    // 0x80193128: addiu       $t8, $t8, -0x6E80
    ctx->r24 = ADD32(ctx->r24, -0X6E80);
    // 0x8019312C: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80193130: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80193134: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80193138: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8019313C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80193140: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80193144: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80193148: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8019314C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80193150: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80193154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80193158: jal         0x8019C418
    // 0x8019315C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_4;
    // 0x8019315C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_4:
    // 0x80193160: beq         $v0, $zero, L_80193194
    if (ctx->r2 == 0) {
        // 0x80193164: lui         $s0, 0x800C
        ctx->r16 = S32(0X800C << 16);
            goto L_80193194;
    }
    // 0x80193164: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x80193168: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x8019316C: addiu       $s7, $s7, 0x5D3C
    ctx->r23 = ADD32(ctx->r23, 0X5D3C);
    // 0x80193170: addiu       $a3, $s0, 0x5D34
    ctx->r7 = ADD32(ctx->r16, 0X5D34);
    // 0x80193174: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x80193178: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019317C: ori         $a0, $a0, 0x22
    ctx->r4 = ctx->r4 | 0X22;
    // 0x80193180: addiu       $a1, $s6, 0x5D28
    ctx->r5 = ADD32(ctx->r22, 0X5D28);
    // 0x80193184: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80193188: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8019318C: jal         0x80019218
    // 0x80193190: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80193190: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_5:
L_80193194:
    // 0x80193194: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80193198: lui         $s0, 0x800C
    ctx->r16 = S32(0X800C << 16);
    // 0x8019319C: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x801931A0: lui         $s7, 0x800C
    ctx->r23 = S32(0X800C << 16);
    // 0x801931A4: addiu       $s7, $s7, 0x5D3C
    ctx->r23 = ADD32(ctx->r23, 0X5D3C);
    // 0x801931A8: addiu       $s6, $s6, 0x5D28
    ctx->r22 = ADD32(ctx->r22, 0X5D28);
    // 0x801931AC: bne         $t9, $zero, L_801932B8
    if (ctx->r25 != 0) {
        // 0x801931B0: addiu       $s0, $s0, 0x5D34
        ctx->r16 = ADD32(ctx->r16, 0X5D34);
            goto L_801932B8;
    }
    // 0x801931B0: addiu       $s0, $s0, 0x5D34
    ctx->r16 = ADD32(ctx->r16, 0X5D34);
    // 0x801931B4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801931B8: lw          $t1, -0x6E38($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6E38);
    // 0x801931BC: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801931C0: addiu       $s1, $s1, -0x6E50
    ctx->r17 = ADD32(ctx->r17, -0X6E50);
    // 0x801931C4: beq         $t1, $zero, L_801932B8
    if (ctx->r9 == 0) {
        // 0x801931C8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801932B8;
    }
    // 0x801931C8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801931CC: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x801931D0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801931D4: addiu       $t6, $t6, -0x6E70
    ctx->r14 = ADD32(ctx->r14, -0X6E70);
    // 0x801931D8: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x801931DC: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x801931E0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x801931E4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801931E8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801931EC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801931F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x801931F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801931F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801931FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80193200: jal         0x8019C418
    // 0x80193204: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_6;
    // 0x80193204: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    after_6:
    // 0x80193208: beq         $v0, $zero, L_801932B8
    if (ctx->r2 == 0) {
        // 0x8019320C: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_801932B8;
    }
    // 0x8019320C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80193210: ori         $a0, $a0, 0x22
    ctx->r4 = ctx->r4 | 0X22;
    // 0x80193214: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80193218: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019321C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80193220: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80193224: jal         0x80019218
    // 0x80193228: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x80193228: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    after_7:
    // 0x8019322C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80193230: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80193234: addiu       $s3, $s3, -0x19C8
    ctx->r19 = ADD32(ctx->r19, -0X19C8);
    // 0x80193238: beq         $v0, $zero, L_80193280
    if (ctx->r2 == 0) {
        // 0x8019323C: lui         $t1, 0x800
        ctx->r9 = S32(0X800 << 16);
            goto L_80193280;
    }
    // 0x8019323C: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x80193240: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80193244: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x80193248: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019324C: addiu       $s3, $s3, -0x19C8
    ctx->r19 = ADD32(ctx->r19, -0X19C8);
    // 0x80193250: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80193254: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80193258: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x8019325C: addiu       $t7, $t7, 0x4C50
    ctx->r15 = ADD32(ctx->r15, 0X4C50);
    // 0x80193260: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x80193264: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80193268: sw          $t7, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r15;
    // 0x8019326C: sw          $t8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r24;
    // 0x80193270: sw          $t9, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r25;
    // 0x80193274: swc1        $f18, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f18.u32l;
    // 0x80193278: b           L_801932B0
    // 0x8019327C: swc1        $f4, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f4.u32l;
        goto L_801932B0;
    // 0x8019327C: swc1        $f4, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f4.u32l;
L_80193280:
    // 0x80193280: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x80193284: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80193288: lui         $at, 0x4258
    ctx->r1 = S32(0X4258 << 16);
    // 0x8019328C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80193290: addiu       $t1, $t1, 0x3B50
    ctx->r9 = ADD32(ctx->r9, 0X3B50);
    // 0x80193294: addiu       $t2, $zero, 0x48
    ctx->r10 = ADD32(0, 0X48);
    // 0x80193298: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8019329C: sw          $t1, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r9;
    // 0x801932A0: sw          $t2, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r10;
    // 0x801932A4: sw          $t3, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->r11;
    // 0x801932A8: swc1        $f6, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f6.u32l;
    // 0x801932AC: swc1        $f8, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f8.u32l;
L_801932B0:
    // 0x801932B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801932B4: sw          $v0, 0x79F8($at)
    MEM_W(0X79F8, ctx->r1) = ctx->r2;
L_801932B8:
    // 0x801932B8: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x801932BC: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x801932C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801932C4: bne         $t4, $at, L_801933B8
    if (ctx->r12 != ctx->r1) {
        // 0x801932C8: addiu       $s3, $s3, -0x19C8
        ctx->r19 = ADD32(ctx->r19, -0X19C8);
            goto L_801933B8;
    }
    // 0x801932C8: addiu       $s3, $s3, -0x19C8
    ctx->r19 = ADD32(ctx->r19, -0X19C8);
    // 0x801932CC: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801932D0: lw          $t5, -0x6E38($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6E38);
    // 0x801932D4: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x801932D8: addiu       $s2, $s2, -0x6E54
    ctx->r18 = ADD32(ctx->r18, -0X6E54);
    // 0x801932DC: beq         $t5, $zero, L_801933B8
    if (ctx->r13 == 0) {
        // 0x801932E0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801933B8;
    }
    // 0x801932E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801932E4: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x801932E8: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801932EC: addiu       $t1, $t1, -0x6E68
    ctx->r9 = ADD32(ctx->r9, -0X6E68);
    // 0x801932F0: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x801932F4: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x801932F8: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801932FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80193300: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80193304: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80193308: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8019330C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80193310: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80193314: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80193318: jal         0x8019C418
    // 0x8019331C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_8;
    // 0x8019331C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_8:
    // 0x80193320: beq         $v0, $zero, L_801933B8
    if (ctx->r2 == 0) {
        // 0x80193324: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_801933B8;
    }
    // 0x80193324: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80193328: ori         $a0, $a0, 0x22
    ctx->r4 = ctx->r4 | 0X22;
    // 0x8019332C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80193330: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80193334: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80193338: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8019333C: jal         0x80019218
    // 0x80193340: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    Audio_PlaySfx(rdram, ctx);
        goto after_9;
    // 0x80193340: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    after_9:
    // 0x80193344: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80193348: lui         $t6, 0x800
    ctx->r14 = S32(0X800 << 16);
    // 0x8019334C: addiu       $t6, $t6, 0x46B0
    ctx->r14 = ADD32(ctx->r14, 0X46B0);
    // 0x80193350: beq         $t2, $zero, L_80193390
    if (ctx->r10 == 0) {
        // 0x80193354: addiu       $t7, $zero, 0x40
        ctx->r15 = ADD32(0, 0X40);
            goto L_80193390;
    }
    // 0x80193354: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80193358: lui         $at, 0x42FA
    ctx->r1 = S32(0X42FA << 16);
    // 0x8019335C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80193360: lui         $at, 0x4317
    ctx->r1 = S32(0X4317 << 16);
    // 0x80193364: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80193368: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x8019336C: addiu       $t3, $t3, 0x4C50
    ctx->r11 = ADD32(ctx->r11, 0X4C50);
    // 0x80193370: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x80193374: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80193378: sw          $t3, 0x188($s3)
    MEM_W(0X188, ctx->r19) = ctx->r11;
    // 0x8019337C: sw          $t4, 0x190($s3)
    MEM_W(0X190, ctx->r19) = ctx->r12;
    // 0x80193380: sw          $t5, 0x194($s3)
    MEM_W(0X194, ctx->r19) = ctx->r13;
    // 0x80193384: swc1        $f10, 0x198($s3)
    MEM_W(0X198, ctx->r19) = ctx->f10.u32l;
    // 0x80193388: b           L_801933B8
    // 0x8019338C: swc1        $f16, 0x19C($s3)
    MEM_W(0X19C, ctx->r19) = ctx->f16.u32l;
        goto L_801933B8;
    // 0x8019338C: swc1        $f16, 0x19C($s3)
    MEM_W(0X19C, ctx->r19) = ctx->f16.u32l;
L_80193390:
    // 0x80193390: lui         $at, 0x4305
    ctx->r1 = S32(0X4305 << 16);
    // 0x80193394: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193398: lui         $at, 0x4317
    ctx->r1 = S32(0X4317 << 16);
    // 0x8019339C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801933A0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x801933A4: sw          $t6, 0x188($s3)
    MEM_W(0X188, ctx->r19) = ctx->r14;
    // 0x801933A8: sw          $t7, 0x190($s3)
    MEM_W(0X190, ctx->r19) = ctx->r15;
    // 0x801933AC: sw          $t8, 0x194($s3)
    MEM_W(0X194, ctx->r19) = ctx->r24;
    // 0x801933B0: swc1        $f18, 0x198($s3)
    MEM_W(0X198, ctx->r19) = ctx->f18.u32l;
    // 0x801933B4: swc1        $f4, 0x19C($s3)
    MEM_W(0X19C, ctx->r19) = ctx->f4.u32l;
L_801933B8:
    // 0x801933B8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x801933BC: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x801933C0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801933C4: multu       $t9, $s2
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801933C8: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801933CC: ori         $a0, $a0, 0x20
    ctx->r4 = ctx->r4 | 0X20;
    // 0x801933D0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x801933D4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801933D8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801933DC: mflo        $t1
    ctx->r9 = lo;
    // 0x801933E0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x801933E4: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x801933E8: andi        $t2, $v0, 0x9000
    ctx->r10 = ctx->r2 & 0X9000;
    // 0x801933EC: beql        $t2, $zero, L_80193454
    if (ctx->r10 == 0) {
        // 0x801933F0: andi        $t8, $v0, 0x4000
        ctx->r24 = ctx->r2 & 0X4000;
            goto L_80193454;
    }
    goto skip_4;
    // 0x801933F0: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
    skip_4:
    // 0x801933F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801933F8: jal         0x80019218
    // 0x801933FC: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    Audio_PlaySfx(rdram, ctx);
        goto after_10;
    // 0x801933FC: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    after_10:
    // 0x80193400: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x80193404: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193408: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019340C: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80193410: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80193414: lwc1        $f6, -0x1A90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1A90);
    // 0x80193418: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x8019341C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193420: swc1        $f6, -0x6DF8($at)
    MEM_W(-0X6DF8, ctx->r1) = ctx->f6.u32l;
    // 0x80193424: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80193428: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019342C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80193430: sw          $zero, -0x6E44($at)
    MEM_W(-0X6E44, ctx->r1) = 0;
    // 0x80193434: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80193438: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8019343C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x80193440: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193444: addiu       $t5, $zero, 0xB
    ctx->r13 = ADD32(0, 0XB);
    // 0x80193448: sw          $t5, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r13;
    // 0x8019344C: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x80193450: andi        $t8, $v0, 0x4000
    ctx->r24 = ctx->r2 & 0X4000;
L_80193454:
    // 0x80193454: beq         $t8, $zero, L_8019382C
    if (ctx->r24 == 0) {
        // 0x80193458: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8019382C;
    }
    // 0x80193458: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019345C: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x80193460: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80193464: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80193468: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8019346C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80193470: jal         0x80019218
    // 0x80193474: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    Audio_PlaySfx(rdram, ctx);
        goto after_11;
    // 0x80193474: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    after_11:
    // 0x80193478: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019347C: addiu       $v1, $v1, -0x7D7C
    ctx->r3 = ADD32(ctx->r3, -0X7D7C);
    // 0x80193480: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80193484: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80193488: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019348C: sw          $t9, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r25;
    // 0x80193490: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193494: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80193498: b           L_8019382C
    // 0x8019349C: sw          $t1, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r9;
        goto L_8019382C;
    // 0x8019349C: sw          $t1, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = ctx->r9;
L_801934A0:
    // 0x801934A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801934A4: lwc1        $f2, 0x7340($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7340);
    // 0x801934A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801934AC: lwc1        $f24, 0x7344($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X7344);
    // 0x801934B0: addiu       $a0, $a0, 0x1A38
    ctx->r4 = ADD32(ctx->r4, 0X1A38);
    // 0x801934B4: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x801934B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801934BC: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x801934C0: sb          $t2, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r10;
    // 0x801934C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801934C8: addiu       $s5, $s5, -0x6E5C
    ctx->r21 = ADD32(ctx->r21, -0X6E5C);
    // 0x801934CC: sw          $a1, -0x6E88($at)
    MEM_W(-0X6E88, ctx->r1) = ctx->r5;
    // 0x801934D0: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x801934D4: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x801934D8: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x801934DC: multu       $t3, $s4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801934E0: addiu       $s3, $s3, -0x19C8
    ctx->r19 = ADD32(ctx->r19, -0X19C8);
    // 0x801934E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801934E8: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x801934EC: mflo        $t4
    ctx->r12 = lo;
    // 0x801934F0: addu        $v0, $s3, $t4
    ctx->r2 = ADD32(ctx->r19, ctx->r12);
    // 0x801934F4: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801934F8: lwc1        $f8, 0x44($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801934FC: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80193500: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x80193504: lwc1        $f16, 0x18($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80193508: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8019350C: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x80193510: lwc1        $f8, 0x24($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80193514: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80193518: sub.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x8019351C: swc1        $f10, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f10.u32l;
    // 0x80193520: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80193524: sub.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80193528: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x8019352C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80193530: swc1        $f10, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f10.u32l;
    // 0x80193534: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x80193538: sw          $a1, -0x6E84($at)
    MEM_W(-0X6E84, ctx->r1) = ctx->r5;
    // 0x8019353C: b           L_8019382C
    // 0x80193540: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
        goto L_8019382C;
    // 0x80193540: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_80193544:
    // 0x80193544: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80193548: lw          $t6, -0x6E88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E88);
    // 0x8019354C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80193550: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80193554: bne         $t6, $at, L_801935E0
    if (ctx->r14 != ctx->r1) {
        // 0x80193558: addiu       $s2, $zero, 0x6
        ctx->r18 = ADD32(0, 0X6);
            goto L_801935E0;
    }
    // 0x80193558: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8019355C: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80193560: addiu       $s5, $s5, -0x6E5C
    ctx->r21 = ADD32(ctx->r21, -0X6E5C);
    // 0x80193564: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80193568: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x8019356C: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80193570: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193574: addiu       $s3, $s3, -0x19C8
    ctx->r19 = ADD32(ctx->r19, -0X19C8);
    // 0x80193578: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019357C: lwc1        $f2, 0x7348($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7348);
    // 0x80193580: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193584: lwc1        $f24, 0x734C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X734C);
    // 0x80193588: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8019358C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80193590: mflo        $t8
    ctx->r24 = lo;
    // 0x80193594: addu        $v0, $s3, $t8
    ctx->r2 = ADD32(ctx->r19, ctx->r24);
    // 0x80193598: lwc1        $f10, 0x48($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8019359C: lwc1        $f6, 0x44($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X44);
    // 0x801935A0: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801935A4: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801935A8: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x801935AC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x801935B0: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x801935B4: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801935B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801935BC: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x801935C0: swc1        $f8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f8.u32l;
    // 0x801935C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801935C8: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x801935CC: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x801935D0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801935D4: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x801935D8: swc1        $f18, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f18.u32l;
    // 0x801935DC: sw          $t9, -0x6DEC($at)
    MEM_W(-0X6DEC, ctx->r1) = ctx->r25;
L_801935E0:
    // 0x801935E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801935E4: lwc1        $f2, 0x7350($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7350);
    // 0x801935E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801935EC: lwc1        $f24, 0x7354($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X7354);
    // 0x801935F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801935F4: lwc1        $f22, 0x7358($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7358);
    // 0x801935F8: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x801935FC: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80193600: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193604: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80193608: addiu       $s5, $s5, -0x6E5C
    ctx->r21 = ADD32(ctx->r21, -0X6E5C);
    // 0x8019360C: addiu       $s3, $s3, -0x19C8
    ctx->r19 = ADD32(ctx->r19, -0X19C8);
    // 0x80193610: addiu       $s4, $zero, 0x60
    ctx->r20 = ADD32(0, 0X60);
    // 0x80193614: addiu       $s1, $s1, -0x19F8
    ctx->r17 = ADD32(ctx->r17, -0X19F8);
    // 0x80193618: lwc1        $f20, 0x735C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X735C);
    // 0x8019361C: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
L_80193620:
    // 0x80193620: beql        $v1, $t1, L_801936A0
    if (ctx->r3 == ctx->r9) {
        // 0x80193624: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_801936A0;
    }
    goto skip_5;
    // 0x80193624: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_5:
    // 0x80193628: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019362C: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80193630: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x80193634: addu        $t4, $s1, $t3
    ctx->r12 = ADD32(ctx->r17, ctx->r11);
    // 0x80193638: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8019363C: lui         $a1, 0x431E
    ctx->r5 = S32(0X431E << 16);
    // 0x80193640: mflo        $t2
    ctx->r10 = lo;
    // 0x80193644: addu        $s0, $s3, $t2
    ctx->r16 = ADD32(ctx->r19, ctx->r10);
    // 0x80193648: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x8019364C: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x80193650: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80193654: nop

    // 0x80193658: bc1fl       L_80193698
    if (!c1cs) {
        // 0x8019365C: sw          $zero, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = 0;
            goto L_80193698;
    }
    goto skip_6;
    // 0x8019365C: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    skip_6:
    // 0x80193660: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80193664: sub.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80193668: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x8019366C: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    // 0x80193670: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80193674: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    // 0x80193678: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x8019367C: jal         0x8009BC2C
    // 0x80193680: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_12;
    // 0x80193680: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    after_12:
    // 0x80193684: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80193688: lwc1        $f2, 0x7360($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7360);
    // 0x8019368C: b           L_8019369C
    // 0x80193690: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
        goto L_8019369C;
    // 0x80193690: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80193694: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
L_80193698:
    // 0x80193698: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
L_8019369C:
    // 0x8019369C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801936A0:
    // 0x801936A0: bnel        $v1, $s2, L_80193620
    if (ctx->r3 != ctx->r18) {
        // 0x801936A4: lw          $t1, 0x0($s5)
        ctx->r9 = MEM_W(ctx->r21, 0X0);
            goto L_80193620;
    }
    goto skip_7;
    // 0x801936A4: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    skip_7:
    // 0x801936A8: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801936AC: lw          $t5, -0x6E84($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6E84);
    // 0x801936B0: bnel        $t5, $zero, L_80193830
    if (ctx->r13 != 0) {
        // 0x801936B4: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80193830;
    }
    goto skip_8;
    // 0x801936B4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_8:
    // 0x801936B8: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x801936BC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801936C0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801936C4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801936C8: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x801936CC: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801936D0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801936D4: sll         $t6, $t6, 5
    ctx->r14 = S32(ctx->r14 << 5);
    // 0x801936D8: beq         $v1, $zero, L_801936E8
    if (ctx->r3 == 0) {
        // 0x801936DC: addu        $v0, $s3, $t6
        ctx->r2 = ADD32(ctx->r19, ctx->r14);
            goto L_801936E8;
    }
    // 0x801936DC: addu        $v0, $s3, $t6
    ctx->r2 = ADD32(ctx->r19, ctx->r14);
    // 0x801936E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801936E4: bne         $v1, $at, L_801936F8
    if (ctx->r3 != ctx->r1) {
        // 0x801936E8: lui         $at, 0x42F0
        ctx->r1 = S32(0X42F0 << 16);
            goto L_801936F8;
    }
L_801936E8:
    // 0x801936E8: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801936EC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801936F0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801936F4: nop

L_801936F8:
    // 0x801936F8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801936FC: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x80193700: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x80193704: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80193708: jal         0x8009BC2C
    // 0x8019370C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_13;
    // 0x8019370C: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    after_13:
    // 0x80193710: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80193714: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80193718: lui         $a2, 0x3E80
    ctx->r6 = S32(0X3E80 << 16);
    // 0x8019371C: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193720: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80193724: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x80193728: mflo        $t8
    ctx->r24 = lo;
    // 0x8019372C: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    // 0x80193730: jal         0x8009BC2C
    // 0x80193734: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    Math_SmoothStepToF(rdram, ctx);
        goto after_14;
    // 0x80193734: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    after_14:
    // 0x80193738: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x8019373C: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80193740: addiu       $a0, $a0, 0x1A38
    ctx->r4 = ADD32(ctx->r4, 0X1A38);
    // 0x80193744: multu       $v1, $s4
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80193748: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8019374C: addiu       $t1, $t9, 0x4
    ctx->r9 = ADD32(ctx->r25, 0X4);
    // 0x80193750: sb          $t1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r9;
    // 0x80193754: mflo        $t2
    ctx->r10 = lo;
    // 0x80193758: addu        $v0, $s3, $t2
    ctx->r2 = ADD32(ctx->r19, ctx->r10);
    // 0x8019375C: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80193760: c.eq.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl == ctx->f10.fl;
    // 0x80193764: nop

    // 0x80193768: bc1fl       L_80193830
    if (!c1cs) {
        // 0x8019376C: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80193830;
    }
    goto skip_9;
    // 0x8019376C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_9:
    // 0x80193770: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x80193774: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80193778: addiu       $v0, $v0, -0x6EDC
    ctx->r2 = ADD32(ctx->r2, -0X6EDC);
    // 0x8019377C: c.eq.s      $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f22.fl == ctx->f16.fl;
    // 0x80193780: addiu       $t4, $t1, 0xFF
    ctx->r12 = ADD32(ctx->r9, 0XFF);
    // 0x80193784: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80193788: bc1fl       L_80193830
    if (!c1cs) {
        // 0x8019378C: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80193830;
    }
    goto skip_10;
    // 0x8019378C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    skip_10:
    // 0x80193790: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80193794: bne         $v1, $at, L_801937B0
    if (ctx->r3 != ctx->r1) {
        // 0x80193798: sw          $v1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r3;
            goto L_801937B0;
    }
    // 0x80193798: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8019379C: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x801937A0: lw          $t5, -0x6E54($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6E54);
    // 0x801937A4: beq         $t5, $zero, L_801937B0
    if (ctx->r13 == 0) {
        // 0x801937A8: nop
    
            goto L_801937B0;
    }
    // 0x801937A8: nop

    // 0x801937AC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
L_801937B0:
    // 0x801937B0: jal         0x801924C4
    // 0x801937B4: nop

    Option_Entry_Setup(rdram, ctx);
        goto after_15;
    // 0x801937B4: nop

    after_15:
    // 0x801937B8: b           L_80193830
    // 0x801937BC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_80193830;
    // 0x801937BC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_801937C0:
    // 0x801937C0: addiu       $v1, $v1, -0x7D7C
    ctx->r3 = ADD32(ctx->r3, -0X7D7C);
    // 0x801937C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801937C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801937CC: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x801937D0: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x801937D4: beq         $at, $zero, L_801937E4
    if (ctx->r1 == 0) {
        // 0x801937D8: addiu       $t6, $v0, 0x12
        ctx->r14 = ADD32(ctx->r2, 0X12);
            goto L_801937E4;
    }
    // 0x801937D8: addiu       $t6, $v0, 0x12
    ctx->r14 = ADD32(ctx->r2, 0X12);
    // 0x801937DC: b           L_8019382C
    // 0x801937E0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_8019382C;
    // 0x801937E0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_801937E4:
    // 0x801937E4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801937E8: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x801937EC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801937F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801937F4: sw          $v0, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r2;
    // 0x801937F8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801937FC: sw          $v0, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r2;
    // 0x80193800: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193804: sw          $zero, 0x7AE0($at)
    MEM_W(0X7AE0, ctx->r1) = 0;
    // 0x80193808: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019380C: sw          $t7, -0x7D84($at)
    MEM_W(-0X7D84, ctx->r1) = ctx->r15;
    // 0x80193810: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80193814: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80193818: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019381C: sw          $zero, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = 0;
    // 0x80193820: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80193824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80193828: sw          $t8, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r24;
L_8019382C:
    // 0x8019382C: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80193830:
    // 0x80193830: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80193834: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80193838: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8019383C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x80193840: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80193844: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x80193848: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x8019384C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x80193850: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x80193854: lw          $s6, 0x5C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X5C);
    // 0x80193858: lw          $s7, 0x60($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X60);
    // 0x8019385C: jr          $ra
    // 0x80193860: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80193860: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Title_EngineGlowParticles_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D80C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8018D810: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8018D814: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x8018D818: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8018D81C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x8018D820: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x8018D824: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8018D828: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8018D82C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8018D830: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8018D834: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8018D838: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8018D83C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x8018D840: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018D844: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018D848: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8018D84C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018D850: lw          $v1, -0x7F00($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F00);
    // 0x8018D854: lui         $s7, 0x801C
    ctx->r23 = S32(0X801C << 16);
    // 0x8018D858: addiu       $s7, $s7, -0x7EF8
    ctx->r23 = ADD32(ctx->r23, -0X7EF8);
    // 0x8018D85C: blez        $v1, L_8018DAF0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8018D860: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8018DAF0;
    }
    // 0x8018D860: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018D864: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D868: lwc1        $f24, 0x703C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X703C);
    // 0x8018D86C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D870: lwc1        $f22, 0x7040($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7040);
    // 0x8018D874: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D878: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D87C: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8018D880: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
L_8018D884:
    // 0x8018D884: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x8018D888: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018D88C: addiu       $t8, $t8, 0x7FC0
    ctx->r24 = ADD32(ctx->r24, 0X7FC0);
    // 0x8018D890: beq         $v0, $zero, L_8018D8C0
    if (ctx->r2 == 0) {
        // 0x8018D894: addu        $s1, $s0, $t8
        ctx->r17 = ADD32(ctx->r16, ctx->r24);
            goto L_8018D8C0;
    }
    // 0x8018D894: addu        $s1, $s0, $t8
    ctx->r17 = ADD32(ctx->r16, ctx->r24);
    // 0x8018D898: beq         $v0, $fp, L_8018D924
    if (ctx->r2 == ctx->r30) {
        // 0x8018D89C: lui         $t2, 0x801B
        ctx->r10 = S32(0X801B << 16);
            goto L_8018D924;
    }
    // 0x8018D89C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018D8A0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8018D8A4: beq         $v0, $at, L_8018D9F0
    if (ctx->r2 == ctx->r1) {
        // 0x8018D8A8: lui         $t0, 0x801B
        ctx->r8 = S32(0X801B << 16);
            goto L_8018D9F0;
    }
    // 0x8018D8A8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018D8AC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018D8B0: addiu       $t7, $t7, -0x7EF8
    ctx->r15 = ADD32(ctx->r15, -0X7EF8);
    // 0x8018D8B4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8018D8B8: b           L_8018DAE0
    // 0x8018D8BC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
        goto L_8018DAE0;
    // 0x8018D8BC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8018D8C0:
    // 0x8018D8C0: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018D8C4: addiu       $t9, $t9, -0x7FA0
    ctx->r25 = ADD32(ctx->r25, -0X7FA0);
    // 0x8018D8C8: addu        $s6, $s0, $t9
    ctx->r22 = ADD32(ctx->r16, ctx->r25);
    // 0x8018D8CC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x8018D8D0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018D8D4: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8018D8D8: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8018D8DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D8E0: jal         0x8009BC2C
    // 0x8018D8E4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8018D8E4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_0:
    // 0x8018D8E8: lwc1        $f2, 0x0($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8018D8EC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D8F0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018D8F4: c.le.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl <= ctx->f4.fl;
    // 0x8018D8F8: nop

    // 0x8018D8FC: bc1f        L_8018D90C
    if (!c1cs) {
        // 0x8018D900: nop
    
            goto L_8018D90C;
    }
    // 0x8018D900: nop

    // 0x8018D904: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
    // 0x8018D908: sw          $fp, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r30;
L_8018D90C:
    // 0x8018D90C: lw          $v1, -0x7F00($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F00);
    // 0x8018D910: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018D914: addiu       $t1, $t1, -0x7EF8
    ctx->r9 = ADD32(ctx->r9, -0X7EF8);
    // 0x8018D918: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8018D91C: b           L_8018DAE0
    // 0x8018D920: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
        goto L_8018DAE0;
    // 0x8018D920: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
L_8018D924:
    // 0x8018D924: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8018D928: addiu       $t3, $t3, 0x7F20
    ctx->r11 = ADD32(ctx->r11, 0X7F20);
    // 0x8018D92C: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8018D930: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8018D934: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8018D938: addiu       $t6, $t6, 0x7E80
    ctx->r14 = ADD32(ctx->r14, 0X7E80);
    // 0x8018D93C: addiu       $t5, $t5, 0x7DE0
    ctx->r13 = ADD32(ctx->r13, 0X7DE0);
    // 0x8018D940: addiu       $t4, $t4, 0x7FC0
    ctx->r12 = ADD32(ctx->r12, 0X7FC0);
    // 0x8018D944: addu        $s3, $s0, $t3
    ctx->r19 = ADD32(ctx->r16, ctx->r11);
    // 0x8018D948: addiu       $t2, $t2, 0x7D40
    ctx->r10 = ADD32(ctx->r10, 0X7D40);
    // 0x8018D94C: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018D950: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018D954: addu        $a0, $s0, $t2
    ctx->r4 = ADD32(ctx->r16, ctx->r10);
    // 0x8018D958: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x8018D95C: addu        $s1, $s0, $t4
    ctx->r17 = ADD32(ctx->r16, ctx->r12);
    // 0x8018D960: addu        $s4, $s0, $t5
    ctx->r20 = ADD32(ctx->r16, ctx->r13);
    // 0x8018D964: addu        $s5, $s0, $t6
    ctx->r21 = ADD32(ctx->r16, ctx->r14);
    // 0x8018D968: jal         0x8009BC2C
    // 0x8018D96C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x8018D96C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x8018D970: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8018D974: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018D978: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018D97C: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x8018D980: jal         0x8009BC2C
    // 0x8018D984: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x8018D984: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_2:
    // 0x8018D988: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8018D98C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8018D990: lui         $a1, 0xC1C8
    ctx->r5 = S32(0XC1C8 << 16);
    // 0x8018D994: lw          $a2, 0x0($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X0);
    // 0x8018D998: jal         0x8009BC2C
    // 0x8018D99C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x8018D99C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_3:
    // 0x8018D9A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018D9A4: lwc1        $f8, 0x7044($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7044);
    // 0x8018D9A8: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D9AC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8018D9B0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018D9B4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8018D9B8: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D9BC: lwc1        $f18, 0x0($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D9C0: c.lt.s      $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f18.fl < ctx->f26.fl;
    // 0x8018D9C4: nop

    // 0x8018D9C8: bc1f        L_8018D9D8
    if (!c1cs) {
        // 0x8018D9CC: nop
    
            goto L_8018D9D8;
    }
    // 0x8018D9CC: nop

    // 0x8018D9D0: swc1        $f26, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f26.u32l;
    // 0x8018D9D4: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
L_8018D9D8:
    // 0x8018D9D8: lw          $v1, -0x7F00($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F00);
    // 0x8018D9DC: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8018D9E0: addiu       $t9, $t9, -0x7EF8
    ctx->r25 = ADD32(ctx->r25, -0X7EF8);
    // 0x8018D9E4: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8018D9E8: b           L_8018DAE0
    // 0x8018D9EC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
        goto L_8018DAE0;
    // 0x8018D9EC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
L_8018D9F0:
    // 0x8018D9F0: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018D9F4: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018D9F8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x8018D9FC: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8018DA00: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8018DA04: addiu       $t5, $t5, 0x7E80
    ctx->r13 = ADD32(ctx->r13, 0X7E80);
    // 0x8018DA08: addiu       $t4, $t4, 0x7DE0
    ctx->r12 = ADD32(ctx->r12, 0X7DE0);
    // 0x8018DA0C: addiu       $t3, $t3, 0x7F20
    ctx->r11 = ADD32(ctx->r11, 0X7F20);
    // 0x8018DA10: addiu       $t2, $t2, 0x7D40
    ctx->r10 = ADD32(ctx->r10, 0X7D40);
    // 0x8018DA14: addiu       $t1, $t1, -0x7FA0
    ctx->r9 = ADD32(ctx->r9, -0X7FA0);
    // 0x8018DA18: addiu       $t0, $t0, 0x7FC0
    ctx->r8 = ADD32(ctx->r8, 0X7FC0);
    // 0x8018DA1C: addu        $s1, $s0, $t0
    ctx->r17 = ADD32(ctx->r16, ctx->r8);
    // 0x8018DA20: addu        $s6, $s0, $t1
    ctx->r22 = ADD32(ctx->r16, ctx->r9);
    // 0x8018DA24: addu        $s2, $s0, $t2
    ctx->r18 = ADD32(ctx->r16, ctx->r10);
    // 0x8018DA28: addu        $s3, $s0, $t3
    ctx->r19 = ADD32(ctx->r16, ctx->r11);
    // 0x8018DA2C: addu        $s4, $s0, $t4
    ctx->r20 = ADD32(ctx->r16, ctx->r12);
    // 0x8018DA30: jal         0x80004EB0
    // 0x8018DA34: addu        $s5, $s0, $t5
    ctx->r21 = ADD32(ctx->r16, ctx->r13);
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8018DA34: addu        $s5, $s0, $t5
    ctx->r21 = ADD32(ctx->r16, ctx->r13);
    after_4:
    // 0x8018DA38: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DA3C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DA40: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018DA44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA48: nop

    // 0x8018DA4C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018DA50: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8018DA54: jal         0x80004EB0
    // 0x8018DA58: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8018DA58: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    after_5:
    // 0x8018DA5C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018DA60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018DA64: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8018DA68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA6C: nop

    // 0x8018DA70: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018DA74: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018DA78: jal         0x80004EB0
    // 0x8018DA7C: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8018DA7C: swc1        $f8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f8.u32l;
    after_6:
    // 0x8018DA80: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8018DA84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018DA88: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018DA8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA90: swc1        $f26, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f26.u32l;
    // 0x8018DA94: mul.s       $f18, $f0, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018DA98: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8018DA9C: jal         0x80004EB0
    // 0x8018DAA0: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8018DAA0: swc1        $f4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f4.u32l;
    after_7:
    // 0x8018DAA4: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8018DAA8: jal         0x80004EB0
    // 0x8018DAAC: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8018DAAC: swc1        $f8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f8.u32l;
    after_8:
    // 0x8018DAB0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018DAB4: lwc1        $f6, 0x7048($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7048);
    // 0x8018DAB8: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
    // 0x8018DABC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018DAC0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8018DAC4: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018DAC8: addiu       $t7, $t7, -0x7EF8
    ctx->r15 = ADD32(ctx->r15, -0X7EF8);
    // 0x8018DACC: add.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8018DAD0: swc1        $f18, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f18.u32l;
    // 0x8018DAD4: lw          $v1, -0x7F00($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F00);
    // 0x8018DAD8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8018DADC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8018DAE0:
    // 0x8018DAE0: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8018DAE4: sltu        $at, $s7, $v0
    ctx->r1 = ctx->r23 < ctx->r2 ? 1 : 0;
    // 0x8018DAE8: bne         $at, $zero, L_8018D884
    if (ctx->r1 != 0) {
        // 0x8018DAEC: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8018D884;
    }
    // 0x8018DAEC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8018DAF0:
    // 0x8018DAF0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8018DAF4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8018DAF8: addiu       $t0, $t0, -0x7B18
    ctx->r8 = ADD32(ctx->r8, -0X7B18);
    // 0x8018DAFC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018DB00: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018DB04: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8018DB08: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8018DB0C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018DB10: lui         $s0, 0x8017
    ctx->r16 = S32(0X8017 << 16);
    // 0x8018DB14: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x8018DB18: addu        $s7, $t9, $t0
    ctx->r23 = ADD32(ctx->r25, ctx->r8);
    // 0x8018DB1C: addiu       $s1, $s1, 0x7988
    ctx->r17 = ADD32(ctx->r17, 0X7988);
    // 0x8018DB20: addiu       $s0, $s0, 0x7978
    ctx->r16 = ADD32(ctx->r16, 0X7978);
    // 0x8018DB24: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018DB28: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018DB2C: lwc1        $f8, 0x0($s7)
    ctx->f8.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8018DB30: lwc1        $f10, 0x8($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X8);
    // 0x8018DB34: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x8018DB38: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8018DB3C: jal         0x80005100
    // 0x8018DB40: sub.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f10.fl;
    Math_Atan2F(rdram, ctx);
        goto after_9;
    // 0x8018DB40: sub.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f10.fl;
    after_9:
    // 0x8018DB44: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018DB48: lwc1        $f8, 0x0($s7)
    ctx->f8.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8018DB4C: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018DB50: lwc1        $f10, 0x8($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X8);
    // 0x8018DB54: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8018DB58: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8018DB5C: lwc1        $f8, 0x7980($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x8018DB60: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x8018DB64: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8018DB68: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x8018DB6C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8018DB70: lwc1        $f6, 0x4($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X4);
    // 0x8018DB74: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8018DB78: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8018DB7C: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8018DB80: jal         0x80005100
    // 0x8018DB84: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_10;
    // 0x8018DB84: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_10:
    // 0x8018DB88: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x8018DB8C: addiu       $s6, $s6, 0x7E64
    ctx->r22 = ADD32(ctx->r22, 0X7E64);
    // 0x8018DB90: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB94: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8018DB98: jal         0x800B8DD0
    // 0x8018DB9C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x8018DB9C: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    after_11:
    // 0x8018DBA0: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8018DBA4: lui         $t3, 0xFDFD
    ctx->r11 = S32(0XFDFD << 16);
    // 0x8018DBA8: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x8018DBAC: addiu       $t1, $a1, 0x8
    ctx->r9 = ADD32(ctx->r5, 0X8);
    // 0x8018DBB0: sw          $t1, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r9;
    // 0x8018DBB4: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8018DBB8: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x8018DBBC: sw          $t3, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r11;
    // 0x8018DBC0: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8018DBC4: lui         $t6, 0xFBFB
    ctx->r14 = S32(0XFBFB << 16);
    // 0x8018DBC8: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x8018DBCC: addiu       $t4, $a1, 0x8
    ctx->r12 = ADD32(ctx->r5, 0X8);
    // 0x8018DBD0: sw          $t4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r12;
    // 0x8018DBD4: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x8018DBD8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8018DBDC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8018DBE0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018DBE4: lw          $v1, -0x7F00($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F00);
    // 0x8018DBE8: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8018DBEC: addiu       $s1, $s1, 0x7FC0
    ctx->r17 = ADD32(ctx->r17, 0X7FC0);
    // 0x8018DBF0: blez        $v1, L_8018DD78
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8018DBF4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8018DD78;
    }
    // 0x8018DBF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018DBF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018DBFC: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x8018DC00: addiu       $s3, $s3, -0x4C40
    ctx->r19 = ADD32(ctx->r19, -0X4C40);
    // 0x8018DC04: lwc1        $f24, 0x704C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X704C);
L_8018DC08:
    // 0x8018DC08: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018DC0C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8018DC10: addiu       $t9, $t9, 0x7D40
    ctx->r25 = ADD32(ctx->r25, 0X7D40);
    // 0x8018DC14: c.eq.s      $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f26.fl == ctx->f10.fl;
    // 0x8018DC18: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x8018DC1C: addiu       $t0, $t0, 0x7DE0
    ctx->r8 = ADD32(ctx->r8, 0X7DE0);
    // 0x8018DC20: addu        $s2, $s0, $t9
    ctx->r18 = ADD32(ctx->r16, ctx->r25);
    // 0x8018DC24: bc1f        L_8018DC40
    if (!c1cs) {
        // 0x8018DC28: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8018DC40;
    }
    // 0x8018DC28: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018DC2C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8018DC30: addiu       $t8, $t8, 0x7FC0
    ctx->r24 = ADD32(ctx->r24, 0X7FC0);
    // 0x8018DC34: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8018DC38: b           L_8018DD68
    // 0x8018DC3C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
        goto L_8018DD68;
    // 0x8018DC3C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
L_8018DC40:
    // 0x8018DC40: lwc1        $f20, 0x6C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8018DC44: lwc1        $f22, 0x70($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8018DC48: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8018DC4C: addiu       $t1, $t1, 0x7E80
    ctx->r9 = ADD32(ctx->r9, 0X7E80);
    // 0x8018DC50: lui         $fp, 0x603
    ctx->r30 = S32(0X603 << 16);
    // 0x8018DC54: addiu       $fp, $fp, 0x20E0
    ctx->r30 = ADD32(ctx->r30, 0X20E0);
    // 0x8018DC58: addu        $s5, $s0, $t1
    ctx->r21 = ADD32(ctx->r16, ctx->r9);
    // 0x8018DC5C: addu        $s4, $s0, $t0
    ctx->r20 = ADD32(ctx->r16, ctx->r8);
    // 0x8018DC60: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    // 0x8018DC64: jal         0x80005708
    // 0x8018DC68: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    Matrix_Push(rdram, ctx);
        goto after_12;
    // 0x8018DC68: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    after_12:
    // 0x8018DC6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC70: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8018DC74: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018DC78: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8018DC7C: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x8018DC80: jal         0x80005B00
    // 0x8018DC84: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_13;
    // 0x8018DC84: lw          $a3, 0x0($s5)
    ctx->r7 = MEM_W(ctx->r21, 0X0);
    after_13:
    // 0x8018DC88: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018DC8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018DC94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DC98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DC9C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018DCA0: jal         0x80005C34
    // 0x8018DCA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_14;
    // 0x8018DCA4: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    after_14:
    // 0x8018DCA8: lwc1        $f18, 0x20($s7)
    ctx->f18.u32l = MEM_W(ctx->r23, 0X20);
    // 0x8018DCAC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018DCB0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCB4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8018DCB8: mul.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x8018DCBC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8018DCC0: jal         0x80005FE0
    // 0x8018DCC4: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_15;
    // 0x8018DCC4: nop

    after_15:
    // 0x8018DCC8: lwc1        $f6, 0x18($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X18);
    // 0x8018DCCC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018DCD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCD4: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8018DCD8: mul.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8018DCDC: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8018DCE0: jal         0x80005D44
    // 0x8018DCE4: nop

    Matrix_RotateX(rdram, ctx);
        goto after_16;
    // 0x8018DCE4: nop

    after_16:
    // 0x8018DCE8: lwc1        $f4, 0x1C($s7)
    ctx->f4.u32l = MEM_W(ctx->r23, 0X1C);
    // 0x8018DCEC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018DCF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCF4: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x8018DCF8: mul.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f24.fl);
    // 0x8018DCFC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8018DD00: jal         0x80005E90
    // 0x8018DD04: nop

    Matrix_RotateY(rdram, ctx);
        goto after_17;
    // 0x8018DD04: nop

    after_17:
    // 0x8018DD08: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8018DD0C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018DD10: jal         0x80005E90
    // 0x8018DD14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_18;
    // 0x8018DD14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_18:
    // 0x8018DD18: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x8018DD1C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8018DD20: jal         0x80005D44
    // 0x8018DD24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_19;
    // 0x8018DD24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_19:
    // 0x8018DD28: jal         0x80006EB8
    // 0x8018DD2C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_20;
    // 0x8018DD2C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_20:
    // 0x8018DD30: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8018DD34: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x8018DD38: addiu       $t4, $a1, 0x8
    ctx->r12 = ADD32(ctx->r5, 0X8);
    // 0x8018DD3C: sw          $t4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r12;
    // 0x8018DD40: sw          $fp, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r30;
    // 0x8018DD44: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8018DD48: jal         0x80005740
    // 0x8018DD4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_21;
    // 0x8018DD4C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_21:
    // 0x8018DD50: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018DD54: lw          $v1, -0x7F00($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7F00);
    // 0x8018DD58: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8018DD5C: addiu       $t7, $t7, 0x7FC0
    ctx->r15 = ADD32(ctx->r15, 0X7FC0);
    // 0x8018DD60: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8018DD64: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_8018DD68:
    // 0x8018DD68: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018DD6C: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8018DD70: bne         $at, $zero, L_8018DC08
    if (ctx->r1 != 0) {
        // 0x8018DD74: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8018DC08;
    }
    // 0x8018DD74: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8018DD78:
    // 0x8018DD78: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8018DD7C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018DD80: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018DD84: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x8018DD88: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8018DD8C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8018DD90: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8018DD94: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8018DD98: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8018DD9C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x8018DDA0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8018DDA4: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x8018DDA8: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x8018DDAC: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x8018DDB0: jr          $ra
    // 0x8018DDB4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8018DDB4: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void Option_VS_N64Console_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199EA8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80199EAC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80199EB0: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80199EB4: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80199EB8: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80199EBC: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80199EC0: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80199EC4: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x80199EC8: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x80199ECC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80199ED0: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80199ED4: jal         0x800BA490
    // 0x80199ED8: nop

    RCP_SetupDL_76(rdram, ctx);
        goto after_0;
    // 0x80199ED8: nop

    after_0:
    // 0x80199EDC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80199EE0: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80199EE4: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80199EE8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80199EEC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80199EF0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80199EF4: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80199EF8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80199EFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80199F00: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x80199F04: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80199F08: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80199F0C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80199F10: lui         $at, 0x42AE
    ctx->r1 = S32(0X42AE << 16);
    // 0x80199F14: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80199F18: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80199F1C: lui         $s3, 0x701
    ctx->r19 = S32(0X701 << 16);
    // 0x80199F20: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80199F24: addiu       $s3, $s3, -0x1660
    ctx->r19 = ADD32(ctx->r19, -0X1660);
    // 0x80199F28: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80199F2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80199F30: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_80199F34:
    // 0x80199F34: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80199F38: sll         $t9, $s1, 1
    ctx->r25 = S32(ctx->r17 << 1);
    // 0x80199F3C: addu        $a1, $s3, $t9
    ctx->r5 = ADD32(ctx->r19, ctx->r25);
    // 0x80199F40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80199F44: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80199F48: addiu       $a2, $zero, 0x90
    ctx->r6 = ADD32(0, 0X90);
    // 0x80199F4C: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80199F50: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80199F54: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80199F58: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80199F5C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80199F60: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x80199F64: jal         0x8009D418
    // 0x80199F68: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_1;
    // 0x80199F68: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x80199F6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80199F70: bne         $s0, $s4, L_80199F34
    if (ctx->r16 != ctx->r20) {
        // 0x80199F74: addiu       $s1, $s1, 0x7E0
        ctx->r17 = ADD32(ctx->r17, 0X7E0);
            goto L_80199F34;
    }
    // 0x80199F74: addiu       $s1, $s1, 0x7E0
    ctx->r17 = ADD32(ctx->r17, 0X7E0);
    // 0x80199F78: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80199F7C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80199F80: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80199F84: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x80199F88: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x80199F8C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80199F90: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80199F94: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80199F98: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80199F9C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80199FA0: jr          $ra
    // 0x80199FA4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80199FA4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Option_ExpertSound_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195B74: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80195B78: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80195B7C: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80195B80: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80195B84: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80195B88: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80195B8C: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x80195B90: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80195B94: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80195B98: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x80195B9C: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80195BA0: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80195BA4: jal         0x8019B9C0
    // 0x80195BA8: nop

    Option_DrawMenuLabel(rdram, ctx);
        goto after_0;
    // 0x80195BA8: nop

    after_0:
    // 0x80195BAC: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x80195BB0: addiu       $s5, $s5, 0x7E64
    ctx->r21 = ADD32(ctx->r21, 0X7E64);
    // 0x80195BB4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80195BB8: jal         0x800B8DD0
    // 0x80195BBC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x80195BBC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_1:
    // 0x80195BC0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80195BC4: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80195BC8: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80195BCC: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80195BD0: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80195BD4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80195BD8: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80195BDC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80195BE0: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x80195BE4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80195BE8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80195BEC: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80195BF0: addiu       $a1, $a1, 0x79F0
    ctx->r5 = ADD32(ctx->r5, 0X79F0);
    // 0x80195BF4: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80195BF8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80195BFC: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x80195C00: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80195C04: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80195C08: lui         $at, 0x4244
    ctx->r1 = S32(0X4244 << 16);
    // 0x80195C0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195C10: lui         $at, 0x42A2
    ctx->r1 = S32(0X42A2 << 16);
    // 0x80195C14: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80195C18: addiu       $a3, $zero, 0xE
    ctx->r7 = ADD32(0, 0XE);
    // 0x80195C1C: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80195C20: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x80195C24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80195C28: jal         0x8009D994
    // 0x80195C2C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x80195C2C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80195C30: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80195C34: addiu       $s1, $s1, -0x6CE4
    ctx->r17 = ADD32(ctx->r17, -0X6CE4);
    // 0x80195C38: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80195C3C: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80195C40: lui         $at, 0x42A4
    ctx->r1 = S32(0X42A4 << 16);
    // 0x80195C44: div         $zero, $t8, $s2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r18)));
    // 0x80195C48: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80195C4C: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80195C50: mflo        $t9
    ctx->r25 = lo;
    // 0x80195C54: addiu       $s0, $s0, -0x1308
    ctx->r16 = ADD32(ctx->r16, -0X1308);
    // 0x80195C58: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80195C5C: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x80195C60: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80195C64: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x80195C68: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80195C6C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80195C70: bne         $s2, $zero, L_80195C7C
    if (ctx->r18 != 0) {
        // 0x80195C74: nop
    
            goto L_80195C7C;
    }
    // 0x80195C74: nop

    // 0x80195C78: break       7
    do_break(2149145720);
L_80195C7C:
    // 0x80195C7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80195C80: bne         $s2, $at, L_80195C94
    if (ctx->r18 != ctx->r1) {
        // 0x80195C84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80195C94;
    }
    // 0x80195C84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80195C88: bne         $t8, $at, L_80195C94
    if (ctx->r24 != ctx->r1) {
        // 0x80195C8C: nop
    
            goto L_80195C94;
    }
    // 0x80195C8C: nop

    // 0x80195C90: break       6
    do_break(2149145744);
L_80195C94:
    // 0x80195C94: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80195C98: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195C9C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80195CA0: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80195CA4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80195CA8: jal         0x8009D994
    // 0x80195CAC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x80195CAC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80195CB0: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80195CB4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80195CB8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80195CBC: div         $zero, $t5, $s2
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r18)));
    // 0x80195CC0: bne         $s2, $zero, L_80195CCC
    if (ctx->r18 != 0) {
        // 0x80195CC4: nop
    
            goto L_80195CCC;
    }
    // 0x80195CC4: nop

    // 0x80195CC8: break       7
    do_break(2149145800);
L_80195CCC:
    // 0x80195CCC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80195CD0: bne         $s2, $at, L_80195CE4
    if (ctx->r18 != ctx->r1) {
        // 0x80195CD4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80195CE4;
    }
    // 0x80195CD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80195CD8: bne         $t5, $at, L_80195CE4
    if (ctx->r13 != ctx->r1) {
        // 0x80195CDC: nop
    
            goto L_80195CE4;
    }
    // 0x80195CDC: nop

    // 0x80195CE0: break       6
    do_break(2149145824);
L_80195CE4:
    // 0x80195CE4: mfhi        $t6
    ctx->r14 = hi;
    // 0x80195CE8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80195CEC: addu        $t8, $s0, $t7
    ctx->r24 = ADD32(ctx->r16, ctx->r15);
    // 0x80195CF0: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80195CF4: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x80195CF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80195CFC: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x80195D00: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x80195D04: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80195D08: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80195D0C: jal         0x8009D994
    // 0x80195D10: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x80195D10: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x80195D14: jal         0x8019B7D4
    // 0x80195D18: nop

    Option_AcceptCancel_Draw(rdram, ctx);
        goto after_5;
    // 0x80195D18: nop

    after_5:
    // 0x80195D1C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80195D20: jal         0x800B8DD0
    // 0x80195D24: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x80195D24: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_6:
    // 0x80195D28: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80195D2C: lui         $t4, 0x3232
    ctx->r12 = S32(0X3232 << 16);
    // 0x80195D30: ori         $t4, $t4, 0xC8FF
    ctx->r12 = ctx->r12 | 0XC8FF;
    // 0x80195D34: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80195D38: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x80195D3C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80195D40: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80195D44: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80195D48: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x80195D4C: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x80195D50: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80195D54: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80195D58: lui         $s4, 0x604
    ctx->r20 = S32(0X604 << 16);
    // 0x80195D5C: addiu       $s4, $s4, 0x47A0
    ctx->r20 = ADD32(ctx->r20, 0X47A0);
    // 0x80195D60: addiu       $s0, $s0, -0xFBC
    ctx->r16 = ADD32(ctx->r16, -0XFBC);
    // 0x80195D64: addiu       $s3, $s3, -0xFCC
    ctx->r19 = ADD32(ctx->r19, -0XFCC);
    // 0x80195D68: addiu       $s2, $s2, -0xFDC
    ctx->r18 = ADD32(ctx->r18, -0XFDC);
    // 0x80195D6C: addiu       $s1, $s1, -0xFEC
    ctx->r17 = ADD32(ctx->r17, -0XFEC);
L_80195D70:
    // 0x80195D70: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80195D74: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x80195D78: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80195D7C: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80195D80: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80195D84: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80195D88: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80195D8C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80195D90: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x80195D94: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x80195D98: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80195D9C: jal         0x8009D418
    // 0x80195DA0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_7;
    // 0x80195DA0: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x80195DA4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80195DA8: addiu       $t5, $t5, -0xFAC
    ctx->r13 = ADD32(ctx->r13, -0XFAC);
    // 0x80195DAC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80195DB0: sltu        $at, $s0, $t5
    ctx->r1 = ctx->r16 < ctx->r13 ? 1 : 0;
    // 0x80195DB4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80195DB8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80195DBC: bne         $at, $zero, L_80195D70
    if (ctx->r1 != 0) {
        // 0x80195DC0: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80195D70;
    }
    // 0x80195DC0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80195DC4: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80195DC8: lw          $t6, -0x6CE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6CE0);
    // 0x80195DCC: beq         $t6, $zero, L_80195FDC
    if (ctx->r14 == 0) {
        // 0x80195DD0: nop
    
            goto L_80195FDC;
    }
    // 0x80195DD0: nop

    // 0x80195DD4: jal         0x8001C3EC
    // 0x80195DD8: nop

    Audio_UpdateFrequencyAnalysis(rdram, ctx);
        goto after_8;
    // 0x80195DD8: nop

    after_8:
    // 0x80195DDC: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x80195DE0: addiu       $s6, $s6, -0x6CE8
    ctx->r22 = ADD32(ctx->r22, -0X6CE8);
    // 0x80195DE4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80195DE8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80195DEC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80195DF0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80195DF4: bne         $a1, $a0, L_80195E08
    if (ctx->r5 != ctx->r4) {
        // 0x80195DF8: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_80195E08;
    }
    // 0x80195DF8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80195DFC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80195E00: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80195E04: nop

L_80195E08:
    // 0x80195E08: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80195E0C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195E10: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80195E14: addiu       $a2, $a2, -0x6CE8
    ctx->r6 = ADD32(ctx->r6, -0X6CE8);
    // 0x80195E18: addiu       $s0, $s0, -0x6D68
    ctx->r16 = ADD32(ctx->r16, -0X6D68);
    // 0x80195E1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80195E20: div.s       $f0, $f2, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f8.fl);
L_80195E24:
    // 0x80195E24: beql        $a0, $zero, L_80195E38
    if (ctx->r4 == 0) {
        // 0x80195E28: lbu         $t7, 0x0($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X0);
            goto L_80195E38;
    }
    goto skip_0;
    // 0x80195E28: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    skip_0:
    // 0x80195E2C: bnel        $a1, $a0, L_80195E64
    if (ctx->r5 != ctx->r4) {
        // 0x80195E30: lbu         $t8, 0x0($v1)
        ctx->r24 = MEM_BU(ctx->r3, 0X0);
            goto L_80195E64;
    }
    goto skip_1;
    // 0x80195E30: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    skip_1:
    // 0x80195E34: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
L_80195E38:
    // 0x80195E38: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80195E3C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80195E40: bgez        $t7, L_80195E54
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80195E44: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80195E54;
    }
    // 0x80195E44: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80195E48: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80195E4C: nop

    // 0x80195E50: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80195E54:
    // 0x80195E54: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80195E58: b           L_80195E8C
    // 0x80195E5C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
        goto L_80195E8C;
    // 0x80195E5C: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x80195E60: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
L_80195E64:
    // 0x80195E64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80195E68: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80195E6C: bgez        $t8, L_80195E80
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80195E70: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80195E80;
    }
    // 0x80195E70: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80195E74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80195E78: nop

    // 0x80195E7C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80195E80:
    // 0x80195E80: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80195E84: sub.s       $f16, $f2, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80195E88: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
L_80195E8C:
    // 0x80195E8C: beql        $a0, $zero, L_80195EA0
    if (ctx->r4 == 0) {
        // 0x80195E90: lbu         $t9, 0x1($v1)
        ctx->r25 = MEM_BU(ctx->r3, 0X1);
            goto L_80195EA0;
    }
    goto skip_2;
    // 0x80195E90: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    skip_2:
    // 0x80195E94: bnel        $a1, $a0, L_80195ECC
    if (ctx->r5 != ctx->r4) {
        // 0x80195E98: lbu         $t3, 0x1($v1)
        ctx->r11 = MEM_BU(ctx->r3, 0X1);
            goto L_80195ECC;
    }
    goto skip_3;
    // 0x80195E98: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    skip_3:
    // 0x80195E9C: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
L_80195EA0:
    // 0x80195EA0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80195EA4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80195EA8: bgez        $t9, L_80195EBC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80195EAC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80195EBC;
    }
    // 0x80195EAC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80195EB0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80195EB4: nop

    // 0x80195EB8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80195EBC:
    // 0x80195EBC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80195EC0: b           L_80195EF4
    // 0x80195EC4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
        goto L_80195EF4;
    // 0x80195EC4: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80195EC8: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
L_80195ECC:
    // 0x80195ECC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80195ED0: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x80195ED4: bgez        $t3, L_80195EE8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80195ED8: cvt.s.w     $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80195EE8;
    }
    // 0x80195ED8: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80195EDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195EE0: nop

    // 0x80195EE4: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80195EE8:
    // 0x80195EE8: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80195EEC: sub.s       $f6, $f2, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80195EF0: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
L_80195EF4:
    // 0x80195EF4: beql        $a0, $zero, L_80195F08
    if (ctx->r4 == 0) {
        // 0x80195EF8: lbu         $t4, 0x2($v1)
        ctx->r12 = MEM_BU(ctx->r3, 0X2);
            goto L_80195F08;
    }
    goto skip_4;
    // 0x80195EF8: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
    skip_4:
    // 0x80195EFC: bnel        $a1, $a0, L_80195F34
    if (ctx->r5 != ctx->r4) {
        // 0x80195F00: lbu         $t5, 0x2($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0X2);
            goto L_80195F34;
    }
    goto skip_5;
    // 0x80195F00: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
    skip_5:
    // 0x80195F04: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
L_80195F08:
    // 0x80195F08: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80195F0C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80195F10: bgez        $t4, L_80195F24
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80195F14: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80195F24;
    }
    // 0x80195F14: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80195F18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195F1C: nop

    // 0x80195F20: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80195F24:
    // 0x80195F24: mul.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80195F28: b           L_80195F5C
    // 0x80195F2C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
        goto L_80195F5C;
    // 0x80195F2C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x80195F30: lbu         $t5, 0x2($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2);
L_80195F34:
    // 0x80195F34: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80195F38: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80195F3C: bgez        $t5, L_80195F50
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80195F40: cvt.s.w     $f6, $f10
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80195F50;
    }
    // 0x80195F40: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80195F44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195F48: nop

    // 0x80195F4C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80195F50:
    // 0x80195F50: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80195F54: sub.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80195F58: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
L_80195F5C:
    // 0x80195F5C: beql        $a0, $zero, L_80195F70
    if (ctx->r4 == 0) {
        // 0x80195F60: lbu         $t6, 0x3($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X3);
            goto L_80195F70;
    }
    goto skip_6;
    // 0x80195F60: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    skip_6:
    // 0x80195F64: bnel        $a1, $a0, L_80195F9C
    if (ctx->r5 != ctx->r4) {
        // 0x80195F68: lbu         $t7, 0x3($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X3);
            goto L_80195F9C;
    }
    goto skip_7;
    // 0x80195F68: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    skip_7:
    // 0x80195F6C: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
L_80195F70:
    // 0x80195F70: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80195F74: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80195F78: bgez        $t6, L_80195F8C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80195F7C: cvt.s.w     $f10, $f16
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80195F8C;
    }
    // 0x80195F7C: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80195F80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80195F84: nop

    // 0x80195F88: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_80195F8C:
    // 0x80195F8C: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80195F90: b           L_80195FC4
    // 0x80195F94: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
        goto L_80195FC4;
    // 0x80195F94: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x80195F98: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
L_80195F9C:
    // 0x80195F9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80195FA0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80195FA4: bgez        $t7, L_80195FB8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80195FA8: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80195FB8;
    }
    // 0x80195FA8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80195FAC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80195FB0: nop

    // 0x80195FB4: add.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f16.fl;
L_80195FB8:
    // 0x80195FB8: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80195FBC: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80195FC0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_80195FC4:
    // 0x80195FC4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80195FC8: bne         $s0, $a2, L_80195E24
    if (ctx->r16 != ctx->r6) {
        // 0x80195FCC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80195E24;
    }
    // 0x80195FCC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80195FD0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80195FD4: b           L_8019602C
    // 0x80195FD8: nop

        goto L_8019602C;
    // 0x80195FD8: nop

L_80195FDC:
    // 0x80195FDC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x80195FE0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195FE4: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x80195FE8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80195FEC: addiu       $s1, $s1, -0x6CE8
    ctx->r17 = ADD32(ctx->r17, -0X6CE8);
    // 0x80195FF0: lwc1        $f22, 0x73D0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X73D0);
    // 0x80195FF4: addiu       $s0, $s0, -0x6D68
    ctx->r16 = ADD32(ctx->r16, -0X6D68);
L_80195FF8:
    // 0x80195FF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195FFC: lwc1        $f6, 0x73D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X73D4);
    // 0x80196000: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80196004: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80196008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019600C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80196010: jal         0x8009BC2C
    // 0x80196014: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_9;
    // 0x80196014: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x80196018: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8019601C: bne         $s0, $s1, L_80195FF8
    if (ctx->r16 != ctx->r17) {
        // 0x80196020: nop
    
            goto L_80195FF8;
    }
    // 0x80196020: nop

    // 0x80196024: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x80196028: addiu       $s6, $s6, -0x6CE8
    ctx->r22 = ADD32(ctx->r22, -0X6CE8);
L_8019602C:
    // 0x8019602C: jal         0x800032B4
    // 0x80196030: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Lib_InitOrtho(rdram, ctx);
        goto after_10;
    // 0x80196030: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_10:
    // 0x80196034: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80196038: jal         0x800B8DD0
    // 0x8019603C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    RCP_SetupDL(rdram, ctx);
        goto after_11;
    // 0x8019603C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_11:
    // 0x80196040: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80196044: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x80196048: jal         0x80005708
    // 0x8019604C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_12;
    // 0x8019604C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80196050: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80196054: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80196058: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8019605C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80196060: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80196064: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x80196068: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8019606C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80196070: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80196074: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80196078: swc1        $f24, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f24.u32l;
    // 0x8019607C: jal         0x80006E3C
    // 0x80196080: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_13;
    // 0x80196080: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    after_13:
    // 0x80196084: jal         0x80006EB8
    // 0x80196088: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_14;
    // 0x80196088: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_14:
    // 0x8019608C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80196090: lwc1        $f20, -0xFFC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0XFFC);
    // 0x80196094: lui         $at, 0x41F8
    ctx->r1 = S32(0X41F8 << 16);
    // 0x80196098: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x8019609C: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x801960A0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801960A4: addiu       $s2, $s2, -0xF88
    ctx->r18 = ADD32(ctx->r18, -0XF88);
    // 0x801960A8: addiu       $s0, $s0, -0x6D68
    ctx->r16 = ADD32(ctx->r16, -0X6D68);
    // 0x801960AC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x801960B0: lui         $s3, 0x600
    ctx->r19 = S32(0X600 << 16);
L_801960B4:
    // 0x801960B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801960B8: lwc1        $f2, -0xFAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0XFAC);
    // 0x801960BC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801960C0: lwc1        $f12, -0xFA8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0XFA8);
    // 0x801960C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801960C8: lwc1        $f14, -0xFA4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0XFA4);
    // 0x801960CC: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x801960D0: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801960D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801960D8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801960DC: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x801960E0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801960E4: lwc1        $f16, -0xFA0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XFA0);
    // 0x801960E8: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x801960EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801960F0: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x801960F4: lwc1        $f16, -0xF9C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF9C);
    // 0x801960F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801960FC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80196100: div.s       $f8, $f18, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80196104: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80196108: lwc1        $f16, -0xF98($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XF98);
    // 0x8019610C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80196110: div.s       $f8, $f18, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80196114: sub.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x80196118: add.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x8019611C: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80196120: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80196124: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80196128: div.s       $f8, $f18, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8019612C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80196130: add.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x80196134: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80196138: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x8019613C: nop

    // 0x80196140: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x80196144: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x80196148: or          $t5, $t7, $t4
    ctx->r13 = ctx->r15 | ctx->r12;
    // 0x8019614C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80196150: add.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80196154: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80196158: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8019615C: nop

    // 0x80196160: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80196164: sll         $t3, $t9, 8
    ctx->r11 = S32(ctx->r25 << 8);
    // 0x80196168: or          $t7, $t5, $t3
    ctx->r15 = ctx->r13 | ctx->r11;
    // 0x8019616C: ori         $t4, $t7, 0xFF
    ctx->r12 = ctx->r15 | 0XFF;
    // 0x80196170: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80196174: jal         0x80005708
    // 0x80196178: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_15;
    // 0x80196178: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8019617C: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x80196180: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80196184: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x80196188: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8019618C: addu        $t9, $s2, $t8
    ctx->r25 = ADD32(ctx->r18, ctx->r24);
    // 0x80196190: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80196194: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80196198: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8019619C: lw          $a3, -0xFF8($a3)
    ctx->r7 = MEM_W(ctx->r7, -0XFF8);
    // 0x801961A0: jal         0x80005B00
    // 0x801961A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_16;
    // 0x801961A4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_16:
    // 0x801961A8: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x801961AC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x801961B0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801961B4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801961B8: lw          $a1, -0xFF4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0XFF4);
    // 0x801961BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801961C0: jal         0x80005C34
    // 0x801961C4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_17;
    // 0x801961C4: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    after_17:
    // 0x801961C8: jal         0x80006EB8
    // 0x801961CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_18;
    // 0x801961CC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_18:
    // 0x801961D0: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x801961D4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801961D8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801961DC: sw          $t7, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r15;
    // 0x801961E0: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x801961E4: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x801961E8: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x801961EC: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x801961F0: lw          $t8, -0xF94($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XF94);
    // 0x801961F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801961F8: jal         0x80005740
    // 0x801961FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x801961FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x80196200: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80196204: lwc1        $f16, -0xFF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XFF0);
    // 0x80196208: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8019620C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80196210: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80196214: bne         $s4, $at, L_801960B4
    if (ctx->r20 != ctx->r1) {
        // 0x80196218: add.s       $f20, $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
            goto L_801960B4;
    }
    // 0x80196218: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x8019621C: jal         0x80005740
    // 0x80196220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x80196220: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x80196224: jal         0x8000316C
    // 0x80196228: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    Lib_InitPerspective(rdram, ctx);
        goto after_21;
    // 0x80196228: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_21:
    // 0x8019622C: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80196230: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80196234: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80196238: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x8019623C: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80196240: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80196244: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x80196248: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x8019624C: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80196250: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80196254: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x80196258: jr          $ra
    // 0x8019625C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8019625C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void Map_Starfield_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A078C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A0790: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x801A0794: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A0798: jal         0x80006F20
    // 0x801A079C: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    Memory_FreeAll(rdram, ctx);
        goto after_0;
    // 0x801A079C: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    after_0:
    // 0x801A07A0: jal         0x800A5D6C
    // 0x801A07A4: nop

    Play_GenerateStarfield(rdram, ctx);
        goto after_1;
    // 0x801A07A4: nop

    after_1:
    // 0x801A07A8: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x801A07AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A07B0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A07B4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A07B8: swc1        $f4, -0x7BE0($at)
    MEM_W(-0X7BE0, ctx->r1) = ctx->f4.u32l;
    // 0x801A07BC: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x801A07C0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801A07C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A07C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801A07CC: swc1        $f6, -0x7BDC($at)
    MEM_W(-0X7BDC, ctx->r1) = ctx->f6.u32l;
    // 0x801A07D0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A07D4: swc1        $f0, -0x7BD4($at)
    MEM_W(-0X7BD4, ctx->r1) = ctx->f0.u32l;
    // 0x801A07D8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801A07DC: swc1        $f0, -0x7BD0($at)
    MEM_W(-0X7BD0, ctx->r1) = ctx->f0.u32l;
    // 0x801A07E0: jr          $ra
    // 0x801A07E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801A07E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Option_Vs_Point_Selection(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A2E0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8019A2E4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8019A2E8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8019A2EC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8019A2F0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8019A2F4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8019A2F8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8019A2FC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8019A300: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8019A304: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8019A308: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019A30C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019A310: lw          $t6, -0x6C94($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C94);
    // 0x8019A314: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019A318: addiu       $v1, $v1, -0x6E10
    ctx->r3 = ADD32(ctx->r3, -0X6E10);
    // 0x8019A31C: bnel        $t6, $zero, L_8019A4B0
    if (ctx->r14 != 0) {
        // 0x8019A320: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8019A4B0;
    }
    goto skip_0;
    // 0x8019A320: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8019A324: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8019A328: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A32C: addiu       $v0, $v0, -0x6ED4
    ctx->r2 = ADD32(ctx->r2, -0X6ED4);
    // 0x8019A330: beq         $t7, $zero, L_8019A34C
    if (ctx->r15 == 0) {
        // 0x8019A334: nop
    
            goto L_8019A34C;
    }
    // 0x8019A334: nop

    // 0x8019A338: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8019A33C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8019A340: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019A344: b           L_8019A4AC
    // 0x8019A348: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_8019A4AC;
    // 0x8019A348: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8019A34C:
    // 0x8019A34C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8019A350: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x8019A354: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8019A358: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x8019A35C: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8019A360: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8019A364: addiu       $s3, $s3, 0x5D34
    ctx->r19 = ADD32(ctx->r19, 0X5D34);
    // 0x8019A368: addiu       $s4, $s4, -0x6C2C
    ctx->r20 = ADD32(ctx->r20, -0X6C2C);
    // 0x8019A36C: addiu       $s5, $s5, 0x5D28
    ctx->r21 = ADD32(ctx->r21, 0X5D28);
    // 0x8019A370: addiu       $s6, $s6, 0x5D3C
    ctx->r22 = ADD32(ctx->r22, 0X5D3C);
    // 0x8019A374: addiu       $fp, $fp, -0x6C80
    ctx->r30 = ADD32(ctx->r30, -0X6C80);
    // 0x8019A378: addiu       $s2, $s2, -0x2750
    ctx->r18 = ADD32(ctx->r18, -0X2750);
    // 0x8019A37C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019A380: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
L_8019A384:
    // 0x8019A384: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x8019A388: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8019A38C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8019A390: beq         $t0, $zero, L_8019A4A0
    if (ctx->r8 == 0) {
        // 0x8019A394: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8019A4A0;
    }
    // 0x8019A394: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019A398: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8019A39C: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x8019A3A0: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x8019A3A4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8019A3A8: addiu       $t6, $t6, -0x2768
    ctx->r14 = ADD32(ctx->r14, -0X2768);
    // 0x8019A3AC: addu        $t4, $fp, $t3
    ctx->r12 = ADD32(ctx->r30, ctx->r11);
    // 0x8019A3B0: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8019A3B4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8019A3B8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8019A3BC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019A3C0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8019A3C4: addu        $s1, $t5, $t6
    ctx->r17 = ADD32(ctx->r13, ctx->r14);
    // 0x8019A3C8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8019A3CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8019A3D0: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x8019A3D4: jal         0x8019C418
    // 0x8019A3D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_0;
    // 0x8019A3D8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8019A3DC: beq         $v0, $zero, L_8019A410
    if (ctx->r2 == 0) {
        // 0x8019A3E0: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8019A410;
    }
    // 0x8019A3E0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A3E4: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019A3E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A3EC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A3F0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A3F4: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A3F8: jal         0x80019218
    // 0x8019A3FC: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019A3FC: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_1:
    // 0x8019A400: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8019A404: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019A408: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8019A40C: sw          $t8, 0x78A4($at)
    MEM_W(0X78A4, ctx->r1) = ctx->r24;
L_8019A410:
    // 0x8019A410: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8019A414: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x8019A418: beq         $t9, $zero, L_8019A458
    if (ctx->r25 == 0) {
        // 0x8019A41C: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_8019A458;
    }
    // 0x8019A41C: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x8019A420: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A424: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019A428: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A42C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A430: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A434: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A438: jal         0x80019218
    // 0x8019A43C: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019A43C: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_2:
    // 0x8019A440: jal         0x8019A080
    // 0x8019A444: nop

    Option_8019A080(rdram, ctx);
        goto after_3;
    // 0x8019A444: nop

    after_3:
    // 0x8019A448: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x8019A44C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A450: b           L_8019A4AC
    // 0x8019A454: sw          $t0, -0x6C94($at)
    MEM_W(-0X6C94, ctx->r1) = ctx->r8;
        goto L_8019A4AC;
    // 0x8019A454: sw          $t0, -0x6C94($at)
    MEM_W(-0X6C94, ctx->r1) = ctx->r8;
L_8019A458:
    // 0x8019A458: beq         $t1, $zero, L_8019A4A0
    if (ctx->r9 == 0) {
        // 0x8019A45C: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8019A4A0;
    }
    // 0x8019A45C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A460: ori         $a0, $a0, 0x101D
    ctx->r4 = ctx->r4 | 0X101D;
    // 0x8019A464: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A468: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A46C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A470: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A474: jal         0x80019218
    // 0x8019A478: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8019A478: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_4:
    // 0x8019A47C: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8019A480: lw          $t2, -0x6C30($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6C30);
    // 0x8019A484: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A488: sw          $t2, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r10;
    // 0x8019A48C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A490: jal         0x801924C4
    // 0x8019A494: sw          $zero, -0x6E3C($at)
    MEM_W(-0X6E3C, ctx->r1) = 0;
    Option_Entry_Setup(rdram, ctx);
        goto after_5;
    // 0x8019A494: sw          $zero, -0x6E3C($at)
    MEM_W(-0X6E3C, ctx->r1) = 0;
    after_5:
    // 0x8019A498: b           L_8019A4B0
    // 0x8019A49C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8019A4B0;
    // 0x8019A49C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8019A4A0:
    // 0x8019A4A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019A4A4: bne         $s0, $s7, L_8019A384
    if (ctx->r16 != ctx->r23) {
        // 0x8019A4A8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8019A384;
    }
    // 0x8019A4A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8019A4AC:
    // 0x8019A4AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8019A4B0:
    // 0x8019A4B0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019A4B4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8019A4B8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8019A4BC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8019A4C0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8019A4C4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8019A4C8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8019A4CC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8019A4D0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8019A4D4: jr          $ra
    // 0x8019A4D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8019A4D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Map_801A05B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A05B4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801A05B8: addiu       $v1, $sp, 0x30
    ctx->r3 = ADD32(ctx->r29, 0X30);
    // 0x801A05BC: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
L_801A05C0:
    // 0x801A05C0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801A05C4: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x801A05C8: bne         $at, $zero, L_801A05C0
    if (ctx->r1 != 0) {
        // 0x801A05CC: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_801A05C0;
    }
    // 0x801A05CC: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x801A05D0: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801A05D4: addiu       $a1, $a1, -0x7790
    ctx->r5 = ADD32(ctx->r5, -0X7790);
    // 0x801A05D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801A05DC:
    // 0x801A05DC: lbu         $a0, 0x36($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X36);
    // 0x801A05E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A05E4: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A05E8: blez        $a0, L_801A06F0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x801A05EC: addiu       $t7, $sp, 0x30
        ctx->r15 = ADD32(ctx->r29, 0X30);
            goto L_801A06F0;
    }
    // 0x801A05EC: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x801A05F0: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x801A05F4: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x801A05F8: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x801A05FC: addiu       $t9, $t9, -0x7790
    ctx->r25 = ADD32(ctx->r25, -0X7790);
    // 0x801A0600: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x801A0604: andi        $a3, $a0, 0x3
    ctx->r7 = ctx->r4 & 0X3;
    // 0x801A0608: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x801A060C: beq         $a3, $zero, L_801A0654
    if (ctx->r7 == 0) {
        // 0x801A0610: addu        $v1, $t6, $t7
        ctx->r3 = ADD32(ctx->r14, ctx->r15);
            goto L_801A0654;
    }
    // 0x801A0610: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801A0614: sll         $t5, $zero, 1
    ctx->r13 = S32(0 << 1);
    // 0x801A0618: addu        $t2, $t0, $t5
    ctx->r10 = ADD32(ctx->r8, ctx->r13);
    // 0x801A061C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
L_801A0620:
    // 0x801A0620: lhu         $t6, 0x5E($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X5E);
    // 0x801A0624: lbu         $t3, 0x5E($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X5E);
    // 0x801A0628: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x801A062C: bgez        $t8, L_801A0638
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801A0630: or          $a3, $t3, $zero
        ctx->r7 = ctx->r11 | 0;
            goto L_801A0638;
    }
    // 0x801A0630: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x801A0634: addiu       $a3, $t3, 0x100
    ctx->r7 = ADD32(ctx->r11, 0X100);
L_801A0638:
    // 0x801A0638: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801A063C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x801A0640: addiu       $t2, $t2, 0x2
    ctx->r10 = ADD32(ctx->r10, 0X2);
    // 0x801A0644: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x801A0648: bne         $t1, $a2, L_801A0620
    if (ctx->r9 != ctx->r6) {
        // 0x801A064C: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_801A0620;
    }
    // 0x801A064C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801A0650: beq         $a2, $a0, L_801A06F0
    if (ctx->r6 == ctx->r4) {
        // 0x801A0654: sll         $t1, $a2, 1
        ctx->r9 = S32(ctx->r6 << 1);
            goto L_801A06F0;
    }
L_801A0654:
    // 0x801A0654: sll         $t1, $a2, 1
    ctx->r9 = S32(ctx->r6 << 1);
    // 0x801A0658: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x801A065C: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
L_801A0660:
    // 0x801A0660: lhu         $t6, 0x5E($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X5E);
    // 0x801A0664: lbu         $t3, 0x5E($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X5E);
    // 0x801A0668: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x801A066C: bgez        $t8, L_801A0678
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801A0670: or          $a3, $t3, $zero
        ctx->r7 = ctx->r11 | 0;
            goto L_801A0678;
    }
    // 0x801A0670: or          $a3, $t3, $zero
    ctx->r7 = ctx->r11 | 0;
    // 0x801A0674: addiu       $a3, $t3, 0x100
    ctx->r7 = ADD32(ctx->r11, 0X100);
L_801A0678:
    // 0x801A0678: lhu         $t6, 0x60($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X60);
    // 0x801A067C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801A0680: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x801A0684: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x801A0688: lbu         $a3, 0x60($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X60);
    // 0x801A068C: bgez        $t8, L_801A0698
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801A0690: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_801A0698;
    }
    // 0x801A0690: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801A0694: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
L_801A0698:
    // 0x801A0698: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801A069C: lhu         $t6, 0x62($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X62);
    // 0x801A06A0: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x801A06A4: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x801A06A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801A06AC: bgez        $t8, L_801A06B8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801A06B0: lbu         $a3, 0x62($t2)
        ctx->r7 = MEM_BU(ctx->r10, 0X62);
            goto L_801A06B8;
    }
    // 0x801A06B0: lbu         $a3, 0x62($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X62);
    // 0x801A06B4: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
L_801A06B8:
    // 0x801A06B8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801A06BC: lhu         $t6, 0x64($t2)
    ctx->r14 = MEM_HU(ctx->r10, 0X64);
    // 0x801A06C0: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x801A06C4: sll         $t8, $t6, 28
    ctx->r24 = S32(ctx->r14 << 28);
    // 0x801A06C8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801A06CC: bgez        $t8, L_801A06D8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801A06D0: lbu         $a3, 0x64($t2)
        ctx->r7 = MEM_BU(ctx->r10, 0X64);
            goto L_801A06D8;
    }
    // 0x801A06D0: lbu         $a3, 0x64($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X64);
    // 0x801A06D4: addiu       $a3, $a3, 0x100
    ctx->r7 = ADD32(ctx->r7, 0X100);
L_801A06D8:
    // 0x801A06D8: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x801A06DC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x801A06E0: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x801A06E4: addu        $t5, $t9, $a3
    ctx->r13 = ADD32(ctx->r25, ctx->r7);
    // 0x801A06E8: bne         $t1, $t4, L_801A0660
    if (ctx->r9 != ctx->r12) {
        // 0x801A06EC: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_801A0660;
    }
    // 0x801A06EC: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_801A06F0:
    // 0x801A06F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x801A06F4: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x801A06F8: bne         $at, $zero, L_801A05DC
    if (ctx->r1 != 0) {
        // 0x801A06FC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_801A05DC;
    }
    // 0x801A06FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801A0700: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801A0704: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x801A0708: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x801A070C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801A0710: beql        $at, $zero, L_801A0720
    if (ctx->r1 == 0) {
        // 0x801A0714: addiu       $v1, $sp, 0x38
        ctx->r3 = ADD32(ctx->r29, 0X38);
            goto L_801A0720;
    }
    goto skip_0;
    // 0x801A0714: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    skip_0:
    // 0x801A0718: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801A071C: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
L_801A0720:
    // 0x801A0720: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_801A0724:
    // 0x801A0724: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801A0728: beql        $at, $zero, L_801A0738
    if (ctx->r1 == 0) {
        // 0x801A072C: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_801A0738;
    }
    goto skip_1;
    // 0x801A072C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x801A0730: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801A0734: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_801A0738:
    // 0x801A0738: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801A073C: beql        $at, $zero, L_801A074C
    if (ctx->r1 == 0) {
        // 0x801A0740: lw          $v0, 0x8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X8);
            goto L_801A074C;
    }
    goto skip_2;
    // 0x801A0740: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x801A0744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801A0748: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
L_801A074C:
    // 0x801A074C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801A0750: beql        $at, $zero, L_801A0760
    if (ctx->r1 == 0) {
        // 0x801A0754: lw          $v0, 0xC($v1)
        ctx->r2 = MEM_W(ctx->r3, 0XC);
            goto L_801A0760;
    }
    goto skip_3;
    // 0x801A0754: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    skip_3:
    // 0x801A0758: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801A075C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_801A0760:
    // 0x801A0760: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x801A0764: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801A0768: beq         $at, $zero, L_801A0774
    if (ctx->r1 == 0) {
        // 0x801A076C: nop
    
            goto L_801A0774;
    }
    // 0x801A076C: nop

    // 0x801A0770: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_801A0774:
    // 0x801A0774: bnel        $v1, $a1, L_801A0724
    if (ctx->r3 != ctx->r5) {
        // 0x801A0778: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_801A0724;
    }
    goto skip_4;
    // 0x801A0778: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x801A077C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801A0780: jr          $ra
    // 0x801A0784: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801A0784: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Map_Input_CursorY(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A5770: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801A5774: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A5778: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801A577C: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x801A5780: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801A5784: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A5788: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801A578C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801A5790: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x801A5794: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801A5798: lb          $v0, -0x2765($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2765);
    // 0x801A579C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801A57A0: addiu       $a0, $a0, -0x102C
    ctx->r4 = ADD32(ctx->r4, -0X102C);
    // 0x801A57A4: slti        $at, $v0, -0x27
    ctx->r1 = SIGNED(ctx->r2) < -0X27 ? 1 : 0;
    // 0x801A57A8: bne         $at, $zero, L_801A57C0
    if (ctx->r1 != 0) {
        // 0x801A57AC: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801A57C0;
    }
    // 0x801A57AC: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A57B0: slti        $at, $v0, 0x28
    ctx->r1 = SIGNED(ctx->r2) < 0X28 ? 1 : 0;
    // 0x801A57B4: beq         $at, $zero, L_801A57C0
    if (ctx->r1 == 0) {
        // 0x801A57B8: nop
    
            goto L_801A57C0;
    }
    // 0x801A57B8: nop

    // 0x801A57BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801A57C0:
    // 0x801A57C0: beq         $v0, $zero, L_801A57E8
    if (ctx->r2 == 0) {
        // 0x801A57C4: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_801A57E8;
    }
    // 0x801A57C4: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A57C8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A57CC: addiu       $a0, $a0, -0x102C
    ctx->r4 = ADD32(ctx->r4, -0X102C);
    // 0x801A57D0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x801A57D4: bne         $t8, $zero, L_801A57E0
    if (ctx->r24 != 0) {
        // 0x801A57D8: nop
    
            goto L_801A57E0;
    }
    // 0x801A57D8: nop

    // 0x801A57DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801A57E0:
    // 0x801A57E0: b           L_801A57EC
    // 0x801A57E4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_801A57EC;
    // 0x801A57E4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_801A57E8:
    // 0x801A57E8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_801A57EC:
    // 0x801A57EC: beq         $v1, $zero, L_801A5820
    if (ctx->r3 == 0) {
        // 0x801A57F0: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_801A5820;
    }
    // 0x801A57F0: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A57F4: lui         $t9, 0x800C
    ctx->r25 = S32(0X800C << 16);
    // 0x801A57F8: addiu       $t9, $t9, 0x5D3C
    ctx->r25 = ADD32(ctx->r25, 0X5D3C);
    // 0x801A57FC: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A5800: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A5804: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x801A5808: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x801A580C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A5810: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801A5814: jal         0x80019218
    // 0x801A5818: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x801A5818: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x801A581C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_801A5820:
    // 0x801A5820: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801A5824: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A5828: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801A582C: jr          $ra
    // 0x801A5830: nop

    return;
    // 0x801A5830: nop

;}
RECOMP_FUNC void Option_DrawMenuCard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BAB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019BABC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019BAC0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019BAC4: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019BAC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019BACC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8019BAD0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8019BAD4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8019BAD8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8019BADC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019BAE0: jal         0x800B8DD0
    // 0x8019BAE4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019BAE4: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_0:
    // 0x8019BAE8: jal         0x800032B4
    // 0x8019BAEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Lib_InitOrtho(rdram, ctx);
        goto after_1;
    // 0x8019BAEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019BAF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BAF4: jal         0x80005708
    // 0x8019BAF8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8019BAF8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x8019BAFC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BB00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019BB04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019BB08: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019BB0C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8019BB10: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8019BB14: jal         0x80005B00
    // 0x8019BB18: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8019BB18: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8019BB1C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BB20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019BB24: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019BB28: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019BB2C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8019BB30: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8019BB34: jal         0x80005C34
    // 0x8019BB38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x8019BB38: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x8019BB3C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BB40: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8019BB44: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8019BB48: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019BB4C: jal         0x80005D44
    // 0x8019BB50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_5;
    // 0x8019BB50: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x8019BB54: jal         0x80006EB8
    // 0x8019BB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x8019BB58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8019BB5C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8019BB60: lui         $t0, 0x801
    ctx->r8 = S32(0X801 << 16);
    // 0x8019BB64: addiu       $t0, $t0, 0x5550
    ctx->r8 = ADD32(ctx->r8, 0X5550);
    // 0x8019BB68: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8019BB6C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8019BB70: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8019BB74: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8019BB78: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8019BB7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BB80: jal         0x80005740
    // 0x8019BB84: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x8019BB84: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_7:
    // 0x8019BB88: jal         0x8000316C
    // 0x8019BB8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Lib_InitPerspective(rdram, ctx);
        goto after_8;
    // 0x8019BB8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8019BB90: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019BB94: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019BB98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019BB9C: jr          $ra
    // 0x8019BBA0: nop

    return;
    // 0x8019BBA0: nop

;}
RECOMP_FUNC void Option_VsMenuCard_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B8C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8019B8CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8019B8D0: jal         0x8019BDF0
    // 0x8019B8D4: nop

    Option_Menu_Push(rdram, ctx);
        goto after_0;
    // 0x8019B8D4: nop

    after_0:
    // 0x8019B8D8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019B8DC: lw          $t6, -0x6E58($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E58);
    // 0x8019B8E0: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x8019B8E4: addiu       $t9, $t9, -0x1788
    ctx->r25 = ADD32(ctx->r25, -0X1788);
    // 0x8019B8E8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019B8EC: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019B8F0: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8019B8F4: addiu       $t8, $t7, 0x38
    ctx->r24 = ADD32(ctx->r15, 0X38);
    // 0x8019B8F8: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8019B8FC: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x8019B900: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x8019B904: lw          $t2, 0x4($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X4);
    // 0x8019B908: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8019B90C: sw          $t2, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r10;
    // 0x8019B910: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x8019B914: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8019B918: sw          $at, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r1;
    // 0x8019B91C: lw          $a3, 0xC($t0)
    ctx->r7 = MEM_W(ctx->r8, 0XC);
    // 0x8019B920: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8019B924: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8019B928: lw          $at, 0x10($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X10);
    // 0x8019B92C: jal         0x8019BAB8
    // 0x8019B930: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    Option_DrawMenuCard(rdram, ctx);
        goto after_1;
    // 0x8019B930: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    after_1:
    // 0x8019B934: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019B938: jal         0x80005740
    // 0x8019B93C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_2;
    // 0x8019B93C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x8019B940: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8019B944: lw          $t3, -0x6E58($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6E58);
    // 0x8019B948: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x8019B94C: addiu       $t5, $t5, -0x1788
    ctx->r13 = ADD32(ctx->r13, -0X1788);
    // 0x8019B950: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8019B954: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x8019B958: sll         $t4, $t4, 5
    ctx->r12 = S32(ctx->r12 << 5);
    // 0x8019B95C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8019B960: addiu       $t8, $t6, 0x30
    ctx->r24 = ADD32(ctx->r14, 0X30);
    // 0x8019B964: or          $t9, $sp, $zero
    ctx->r25 = ctx->r29 | 0;
L_8019B968:
    // 0x8019B968: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8019B96C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8019B970: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8019B974: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x8019B978: lw          $at, -0x8($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X8);
    // 0x8019B97C: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x8019B980: lw          $at, -0x4($t6)
    ctx->r1 = MEM_W(ctx->r14, -0X4);
    // 0x8019B984: bne         $t6, $t8, L_8019B968
    if (ctx->r14 != ctx->r24) {
        // 0x8019B988: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_8019B968;
    }
    // 0x8019B988: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x8019B98C: lw          $at, 0x0($t6)
    ctx->r1 = MEM_W(ctx->r14, 0X0);
    // 0x8019B990: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8019B994: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8019B998: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x8019B99C: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8019B9A0: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x8019B9A4: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8019B9A8: jal         0x8019C120
    // 0x8019B9AC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_3;
    // 0x8019B9AC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_3:
    // 0x8019B9B0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8019B9B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8019B9B8: jr          $ra
    // 0x8019B9BC: nop

    return;
    // 0x8019B9BC: nop

;}
RECOMP_FUNC void Option_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801920C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801920C8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801920CC: addiu       $v1, $v1, -0x6E88
    ctx->r3 = ADD32(ctx->r3, -0X6E88);
    // 0x801920D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801920D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801920D8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801920DC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801920E0: blez        $v0, L_801920EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801920E4: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801920EC;
    }
    // 0x801920E4: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801920E8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_801920EC:
    // 0x801920EC: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801920F0: addiu       $v1, $v1, -0x6E84
    ctx->r3 = ADD32(ctx->r3, -0X6E84);
    // 0x801920F4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801920F8: blez        $v0, L_80192104
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801920FC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80192104;
    }
    // 0x801920FC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80192100: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80192104:
    // 0x80192104: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x80192108: addiu       $v1, $v1, 0x784C
    ctx->r3 = ADD32(ctx->r3, 0X784C);
    // 0x8019210C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80192110: beq         $v0, $zero, L_80192130
    if (ctx->r2 == 0) {
        // 0x80192114: nop
    
            goto L_80192130;
    }
    // 0x80192114: nop

    // 0x80192118: beq         $v0, $at, L_80192154
    if (ctx->r2 == ctx->r1) {
        // 0x8019211C: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80192154;
    }
    // 0x8019211C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80192120: beq         $v0, $v1, L_80192168
    if (ctx->r2 == ctx->r3) {
        // 0x80192124: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80192168;
    }
    // 0x80192124: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192128: b           L_80192170
    // 0x8019212C: nop

        goto L_80192170;
    // 0x8019212C: nop

L_80192130:
    // 0x80192130: lw          $t8, 0x783C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X783C);
    // 0x80192134: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80192138: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019213C: bne         $t8, $zero, L_80192170
    if (ctx->r24 != 0) {
        // 0x80192140: addiu       $a1, $zero, 0x17
        ctx->r5 = ADD32(0, 0X17);
            goto L_80192170;
    }
    // 0x80192140: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80192144: jal         0x8001DC6C
    // 0x80192148: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    Audio_SetAudioSpec(rdram, ctx);
        goto after_0;
    // 0x80192148: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_0:
    // 0x8019214C: b           L_80192170
    // 0x80192150: nop

        goto L_80192170;
    // 0x80192150: nop

L_80192154:
    // 0x80192154: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192158: jal         0x80191B20
    // 0x8019215C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    Option_Setup(rdram, ctx);
        goto after_1;
    // 0x8019215C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    after_1:
    // 0x80192160: b           L_80192170
    // 0x80192164: nop

        goto L_80192170;
    // 0x80192164: nop

L_80192168:
    // 0x80192168: jal         0x80192190
    // 0x8019216C: sw          $v1, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r3;
    Option_Entry_Update(rdram, ctx);
        goto after_2;
    // 0x8019216C: sw          $v1, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = ctx->r3;
    after_2:
L_80192170:
    // 0x80192170: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80192174: addiu       $v0, $v0, 0x7DB0
    ctx->r2 = ADD32(ctx->r2, 0X7DB0);
    // 0x80192178: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8019217C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80192180: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80192184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80192188: jr          $ra
    // 0x8019218C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8019218C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Title_NextState_Check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80190E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80190E6C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80190E70: lw          $t6, -0x7D3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D3C);
    // 0x80190E74: bne         $t6, $zero, L_80190E8C
    if (ctx->r14 != 0) {
        // 0x80190E78: nop
    
            goto L_80190E8C;
    }
    // 0x80190E78: nop

    // 0x80190E7C: jal         0x80190FD0
    // 0x80190E80: nop

    Title_NextState_OptionMenu(rdram, ctx);
        goto after_0;
    // 0x80190E80: nop

    after_0:
    // 0x80190E84: b           L_80190E98
    // 0x80190E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80190E98;
    // 0x80190E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80190E8C:
    // 0x80190E8C: jal         0x80190EA4
    // 0x80190E90: nop

    Title_NextState_TitleScreen(rdram, ctx);
        goto after_1;
    // 0x80190E90: nop

    after_1:
    // 0x80190E94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80190E98:
    // 0x80190E98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80190E9C: jr          $ra
    // 0x80190EA0: nop

    return;
    // 0x80190EA0: nop

;}
RECOMP_FUNC void Option_RankingPlanetName_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019882C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80198830: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80198834: mtc1        $a3, $f12
    ctx->f12.u32l = ctx->r7;
    // 0x80198838: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8019883C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80198840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80198844: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80198848: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8019884C: lui         $at, 0x4268
    ctx->r1 = S32(0X4268 << 16);
    // 0x80198850: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198854: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x80198858: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x8019885C: nop

    // 0x80198860: bc1fl       L_80198960
    if (!c1cs) {
        // 0x80198864: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80198960;
    }
    goto skip_0;
    // 0x80198864: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80198868: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019886C: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x80198870: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80198874: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80198878: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8019887C: sll         $t7, $a3, 1
    ctx->r15 = S32(ctx->r7 << 1);
    // 0x80198880: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80198884: bc1f        L_8019895C
    if (!c1cs) {
        // 0x80198888: lui         $v0, 0x8018
        ctx->r2 = S32(0X8018 << 16);
            goto L_8019895C;
    }
    // 0x80198888: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x8019888C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80198890: lbu         $v0, -0x7731($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X7731);
    // 0x80198894: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80198898: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019889C: srl         $t9, $v0, 4
    ctx->r25 = S32(U32(ctx->r2) >> 4);
    // 0x801988A0: andi        $t0, $t9, 0xF
    ctx->r8 = ctx->r25 & 0XF;
    // 0x801988A4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801988A8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801988AC: lw          $t2, -0x1154($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1154);
    // 0x801988B0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801988B4: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x801988B8: swc1        $f12, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f12.u32l;
    // 0x801988BC: jal         0x800B8DD0
    // 0x801988C0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801988C0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x801988C4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801988C8: addiu       $a1, $a1, 0x7E64
    ctx->r5 = ADD32(ctx->r5, 0X7E64);
    // 0x801988CC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801988D0: lui         $t5, 0xFFFF
    ctx->r13 = S32(0XFFFF << 16);
    // 0x801988D4: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x801988D8: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x801988DC: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x801988E0: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x801988E4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801988E8: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x801988EC: jal         0x800A13EC
    // 0x801988F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    Graphics_GetSmallTextWidth(rdram, ctx);
        goto after_1;
    // 0x801988F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801988F4: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801988F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801988FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80198900: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80198904: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80198908: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019890C: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80198910: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80198914: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80198918: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8019891C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80198920: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80198924: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80198928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019892C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80198930: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80198934: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x80198938: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019893C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80198940: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80198944: trunc.w.s   $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80198948: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019894C: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x80198950: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80198954: jal         0x800A1200
    // 0x80198958: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_2;
    // 0x80198958: nop

    after_2:
L_8019895C:
    // 0x8019895C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80198960:
    // 0x80198960: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80198964: jr          $ra
    // 0x80198968: nop

    return;
    // 0x80198968: nop

;}
RECOMP_FUNC void Map_Titania_DrawRings2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A7A84: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A7A88: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801A7A8C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A7A90: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A7A94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A7A98: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801A7A9C: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801A7AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A7AA4: jal         0x800B8DD0
    // 0x801A7AA8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A7AA8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_0:
    // 0x801A7AAC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A7AB0: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A7AB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7AB8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A7ABC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801A7AC0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A7AC4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A7AC8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801A7ACC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x801A7AD0: addiu       $t0, $t0, -0xB60
    ctx->r8 = ADD32(ctx->r8, -0XB60);
    // 0x801A7AD4: lui         $at, 0xFFAF
    ctx->r1 = S32(0XFFAF << 16);
    // 0x801A7AD8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801A7ADC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801A7AE0: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A7AE4: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x801A7AE8: lw          $t1, 0x24($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X24);
    // 0x801A7AEC: ori         $at, $at, 0xAF00
    ctx->r1 = ctx->r1 | 0XAF00;
    // 0x801A7AF0: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x801A7AF4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801A7AF8: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A7AFC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801A7B00: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7B04: lui         $t6, 0x491F
    ctx->r14 = S32(0X491F << 16);
    // 0x801A7B08: ori         $t6, $t6, 0xF00
    ctx->r14 = ctx->r14 | 0XF00;
    // 0x801A7B0C: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801A7B10: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801A7B14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801A7B18: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801A7B1C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A7B20: jal         0x80005708
    // 0x801A7B24: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A7B24: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x801A7B28: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x801A7B2C: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A7B30: addiu       $t9, $t9, -0x21E0
    ctx->r25 = ADD32(ctx->r25, -0X21E0);
    // 0x801A7B34: sll         $t8, $t7, 6
    ctx->r24 = S32(ctx->r15 << 6);
    // 0x801A7B38: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x801A7B3C: jal         0x80005680
    // 0x801A7B40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A7B40: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x801A7B44: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x801A7B48: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7B4C: lwc1        $f8, 0x7994($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7994);
    // 0x801A7B50: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x801A7B54: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A7B58: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A7B5C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801A7B60: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A7B64: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A7B68: jal         0x80005FE0
    // 0x801A7B6C: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_3;
    // 0x801A7B6C: nop

    after_3:
    // 0x801A7B70: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x801A7B74: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x801A7B78: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A7B7C: jal         0x80005D44
    // 0x801A7B80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801A7B80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x801A7B84: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A7B88: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A7B8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A7B90: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A7B94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A7B98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A7B9C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A7BA0: jal         0x80005C34
    // 0x801A7BA4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x801A7BA4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x801A7BA8: jal         0x80006EB8
    // 0x801A7BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x801A7BAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801A7BB0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A7BB4: lui         $t4, 0x605
    ctx->r12 = S32(0X605 << 16);
    // 0x801A7BB8: addiu       $t4, $t4, -0x3220
    ctx->r12 = ADD32(ctx->r12, -0X3220);
    // 0x801A7BBC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801A7BC0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801A7BC4: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801A7BC8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801A7BCC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A7BD0: jal         0x80005740
    // 0x801A7BD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x801A7BD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801A7BD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A7BDC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801A7BE0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801A7BE4: jr          $ra
    // 0x801A7BE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801A7BE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void Title_SetCamUp2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801914AC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801914B0: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801914B4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801914B8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801914BC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801914C0: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801914C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801914C8: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x801914CC: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x801914D0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x801914D4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x801914D8: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801914DC: swc1        $f20, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f20.u32l;
    // 0x801914E0: swc1        $f20, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f20.u32l;
    // 0x801914E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801914E8: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x801914EC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x801914F0: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x801914F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801914F8: jal         0x80005B00
    // 0x801914FC: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x801914FC: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80191500: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191504: lwc1        $f6, 0x70E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X70E0);
    // 0x80191508: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8019150C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80191510: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191514: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80191518: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8019151C: jal         0x80005E90
    // 0x80191520: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_1;
    // 0x80191520: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80191524: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191528: lwc1        $f10, 0x70E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X70E4);
    // 0x8019152C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80191530: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80191534: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80191538: mul.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8019153C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80191540: jal         0x80005D44
    // 0x80191544: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x80191544: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80191548: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019154C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80191550: jal         0x80006970
    // 0x80191554: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    Matrix_MultVec3f(rdram, ctx);
        goto after_3;
    // 0x80191554: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_3:
    // 0x80191558: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8019155C: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x80191560: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x80191564: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80191568: lwc1        $f4, 0x48($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8019156C: swc1        $f4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f4.u32l;
    // 0x80191570: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80191574: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80191578: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x8019157C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80191580: swc1        $f20, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f20.u32l;
    // 0x80191584: swc1        $f20, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f20.u32l;
    // 0x80191588: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8019158C: lw          $a3, 0x58($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X58);
    // 0x80191590: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80191594: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80191598: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8019159C: jal         0x80005B00
    // 0x801915A0: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x801915A0: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x801915A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801915A8: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801915AC: jal         0x80005E90
    // 0x801915B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x801915B0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x801915B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801915B8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801915BC: jal         0x80005D44
    // 0x801915C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_6;
    // 0x801915C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_6:
    // 0x801915C4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801915C8: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x801915CC: jal         0x80006970
    // 0x801915D0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    Matrix_MultVec3f(rdram, ctx);
        goto after_7;
    // 0x801915D0: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_7:
    // 0x801915D4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801915D8: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x801915DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801915E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801915E4: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x801915E8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x801915EC: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x801915F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801915F4: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x801915F8: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x801915FC: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80191600: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x80191604: swc1        $f20, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f20.u32l;
    // 0x80191608: swc1        $f20, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f20.u32l;
    // 0x8019160C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80191610: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80191614: jal         0x80005E90
    // 0x80191618: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_8;
    // 0x80191618: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    after_8:
    // 0x8019161C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80191620: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80191624: jal         0x80005D44
    // 0x80191628: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_9;
    // 0x80191628: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_9:
    // 0x8019162C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80191630: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80191634: jal         0x80006970
    // 0x80191638: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x80191638: addiu       $a2, $sp, 0x44
    ctx->r6 = ADD32(ctx->r29, 0X44);
    after_10:
    // 0x8019163C: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80191640: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80191644: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191648: swc1        $f6, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f6.u32l;
    // 0x8019164C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80191650: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191654: swc1        $f8, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f8.u32l;
    // 0x80191658: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019165C: swc1        $f10, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f10.u32l;
    // 0x80191660: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80191664: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80191668: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019166C: jr          $ra
    // 0x80191670: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80191670: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Title_NextState_OptionMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190FD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80190FD4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80190FD8: addiu       $a0, $a0, -0x274C
    ctx->r4 = ADD32(ctx->r4, -0X274C);
    // 0x80190FDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80190FE0: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80190FE4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80190FE8: addiu       $t0, $t0, -0x7D80
    ctx->r8 = ADD32(ctx->r8, -0X7D80);
    // 0x80190FEC: bnel        $t6, $zero, L_80191110
    if (ctx->r14 != 0) {
        // 0x80190FF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80191110;
    }
    goto skip_0;
    // 0x80190FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80190FF4: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80190FF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80190FFC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80191000: beq         $v1, $zero, L_80191018
    if (ctx->r3 == 0) {
        // 0x80191004: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80191018;
    }
    // 0x80191004: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80191008: beq         $v0, $at, L_801910B0
    if (ctx->r2 == ctx->r1) {
        // 0x8019100C: lui         $v1, 0x801C
        ctx->r3 = S32(0X801C << 16);
            goto L_801910B0;
    }
    // 0x8019100C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80191010: b           L_80191110
    // 0x80191014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80191110;
    // 0x80191014: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80191018:
    // 0x80191018: lw          $t7, 0x7AF8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7AF8);
    // 0x8019101C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80191020: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80191024: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80191028: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8019102C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x80191030: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x80191034: andi        $t9, $v0, 0x1000
    ctx->r25 = ctx->r2 & 0X1000;
    // 0x80191038: bne         $t9, $zero, L_80191048
    if (ctx->r25 != 0) {
        // 0x8019103C: andi        $t1, $v0, 0x8000
        ctx->r9 = ctx->r2 & 0X8000;
            goto L_80191048;
    }
    // 0x8019103C: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
    // 0x80191040: beql        $t1, $zero, L_80191110
    if (ctx->r9 == 0) {
        // 0x80191044: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80191110;
    }
    goto skip_1;
    // 0x80191044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
L_80191048:
    // 0x80191048: bne         $v1, $zero, L_8019110C
    if (ctx->r3 != 0) {
        // 0x8019104C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_8019110C;
    }
    // 0x8019104C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80191050: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x80191054: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80191058: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x8019105C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80191060: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80191064: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80191068: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019106C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80191070: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80191074: jal         0x80019218
    // 0x80191078: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_0;
    // 0x80191078: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8019107C: lui         $a0, 0x101E
    ctx->r4 = S32(0X101E << 16);
    // 0x80191080: jal         0x800182F4
    // 0x80191084: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_1;
    // 0x80191084: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80191088: lui         $a0, 0x111E
    ctx->r4 = S32(0X111E << 16);
    // 0x8019108C: jal         0x800182F4
    // 0x80191090: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_2;
    // 0x80191090: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_2:
    // 0x80191094: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80191098: addiu       $v1, $v1, -0x7D7C
    ctx->r3 = ADD32(ctx->r3, -0X7D7C);
    // 0x8019109C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801910A0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801910A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801910A8: b           L_8019110C
    // 0x801910AC: sw          $t3, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r11;
        goto L_8019110C;
    // 0x801910AC: sw          $t3, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = ctx->r11;
L_801910B0:
    // 0x801910B0: addiu       $v1, $v1, -0x7D7C
    ctx->r3 = ADD32(ctx->r3, -0X7D7C);
    // 0x801910B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801910B8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x801910BC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801910C0: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x801910C4: beq         $at, $zero, L_801910D8
    if (ctx->r1 == 0) {
        // 0x801910C8: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_801910D8;
    }
    // 0x801910C8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x801910CC: addiu       $t4, $v0, 0x12
    ctx->r12 = ADD32(ctx->r2, 0X12);
    // 0x801910D0: b           L_8019110C
    // 0x801910D4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
        goto L_8019110C;
    // 0x801910D4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_801910D8:
    // 0x801910D8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801910DC: sw          $t5, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r13;
    // 0x801910E0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801910E4: sw          $t6, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r14;
    // 0x801910E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801910EC: sw          $zero, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = 0;
    // 0x801910F0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801910F4: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x801910F8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801910FC: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x80191100: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80191104: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80191108: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8019110C:
    // 0x8019110C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80191110:
    // 0x80191110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80191114: jr          $ra
    // 0x80191118: nop

    return;
    // 0x80191118: nop

;}
RECOMP_FUNC void Option_Input_MoveCursor_Y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C418: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8019C41C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8019C420: bne         $a1, $zero, L_8019C430
    if (ctx->r5 != 0) {
        // 0x8019C424: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8019C430;
    }
    // 0x8019C424: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8019C428: jr          $ra
    // 0x8019C42C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8019C42C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019C430:
    // 0x8019C430: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x8019C434: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8019C438: addiu       $t8, $t8, -0x2768
    ctx->r24 = ADD32(ctx->r24, -0X2768);
    // 0x8019C43C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019C440: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019C444: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8019C448: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8019C44C: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8019C450: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8019C454: lb          $t1, 0x3($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X3);
    // 0x8019C458: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019C45C: lb          $a3, 0x2($t0)
    ctx->r7 = MEM_B(ctx->r8, 0X2);
    // 0x8019C460: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x8019C464: bne         $t9, $at, L_8019C48C
    if (ctx->r25 != ctx->r1) {
        // 0x8019C468: negu        $t1, $t1
        ctx->r9 = SUB32(0, ctx->r9);
            goto L_8019C48C;
    }
    // 0x8019C468: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
    // 0x8019C46C: slti        $at, $a3, 0x29
    ctx->r1 = SIGNED(ctx->r7) < 0X29 ? 1 : 0;
    // 0x8019C470: beq         $at, $zero, L_8019C484
    if (ctx->r1 == 0) {
        // 0x8019C474: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_8019C484;
    }
    // 0x8019C474: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8019C478: slti        $at, $a3, -0x28
    ctx->r1 = SIGNED(ctx->r7) < -0X28 ? 1 : 0;
    // 0x8019C47C: beql        $at, $zero, L_8019C4B0
    if (ctx->r1 == 0) {
        // 0x8019C480: lw          $a3, 0x10($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X10);
            goto L_8019C4B0;
    }
    goto skip_0;
    // 0x8019C480: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    skip_0:
L_8019C484:
    // 0x8019C484: jr          $ra
    // 0x8019C488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8019C488: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019C48C:
    // 0x8019C48C: slti        $at, $t1, 0x29
    ctx->r1 = SIGNED(ctx->r9) < 0X29 ? 1 : 0;
    // 0x8019C490: beq         $at, $zero, L_8019C4A4
    if (ctx->r1 == 0) {
        // 0x8019C494: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_8019C4A4;
    }
    // 0x8019C494: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8019C498: slti        $at, $t1, -0x28
    ctx->r1 = SIGNED(ctx->r9) < -0X28 ? 1 : 0;
    // 0x8019C49C: beql        $at, $zero, L_8019C4B0
    if (ctx->r1 == 0) {
        // 0x8019C4A0: lw          $a3, 0x10($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X10);
            goto L_8019C4B0;
    }
    goto skip_1;
    // 0x8019C4A0: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
    skip_1:
L_8019C4A4:
    // 0x8019C4A4: jr          $ra
    // 0x8019C4A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8019C4A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019C4AC: lw          $a3, 0x10($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X10);
L_8019C4B0:
    // 0x8019C4B0: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8019C4B4: beq         $at, $zero, L_8019C4CC
    if (ctx->r1 == 0) {
        // 0x8019C4B8: negu        $t2, $a3
        ctx->r10 = SUB32(0, ctx->r7);
            goto L_8019C4CC;
    }
    // 0x8019C4B8: negu        $t2, $a3
    ctx->r10 = SUB32(0, ctx->r7);
    // 0x8019C4BC: slt         $at, $t2, $t0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8019C4C0: beql        $at, $zero, L_8019C4D0
    if (ctx->r1 == 0) {
        // 0x8019C4C4: lw          $a3, 0x20($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X20);
            goto L_8019C4D0;
    }
    goto skip_2;
    // 0x8019C4C4: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    skip_2:
    // 0x8019C4C8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8019C4CC:
    // 0x8019C4CC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
L_8019C4D0:
    // 0x8019C4D0: lw          $t1, 0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4);
    // 0x8019C4D4: bne         $t1, $zero, L_8019C578
    if (ctx->r9 != 0) {
        // 0x8019C4D8: nop
    
            goto L_8019C578;
    }
    // 0x8019C4D8: nop

    // 0x8019C4DC: beql        $t0, $zero, L_8019C56C
    if (ctx->r8 == 0) {
        // 0x8019C4E0: sw          $zero, 0x4($a3)
        MEM_W(0X4, ctx->r7) = 0;
            goto L_8019C56C;
    }
    goto skip_3;
    // 0x8019C4E0: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    skip_3:
    // 0x8019C4E4: blez        $t0, L_8019C510
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8019C4E8: addiu       $t3, $a2, 0x1
        ctx->r11 = ADD32(ctx->r6, 0X1);
            goto L_8019C510;
    }
    // 0x8019C4E8: addiu       $t3, $a2, 0x1
    ctx->r11 = ADD32(ctx->r6, 0X1);
    // 0x8019C4EC: slt         $at, $a1, $t3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8019C4F0: beq         $at, $zero, L_8019C510
    if (ctx->r1 == 0) {
        // 0x8019C4F4: sw          $t3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r11;
            goto L_8019C510;
    }
    // 0x8019C4F4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8019C4F8: lw          $t5, 0xC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC);
    // 0x8019C4FC: bnel        $t5, $zero, L_8019C510
    if (ctx->r13 != 0) {
        // 0x8019C500: sw          $a1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r5;
            goto L_8019C510;
    }
    goto skip_4;
    // 0x8019C500: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    skip_4:
    // 0x8019C504: b           L_8019C510
    // 0x8019C508: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8019C510;
    // 0x8019C508: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8019C50C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
L_8019C510:
    // 0x8019C510: bgezl       $t0, L_8019C544
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8019C514: lw          $a1, 0x0($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X0);
            goto L_8019C544;
    }
    goto skip_5;
    // 0x8019C514: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    skip_5:
    // 0x8019C518: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8019C51C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8019C520: bgez        $t7, L_8019C540
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8019C524: sw          $t7, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r15;
            goto L_8019C540;
    }
    // 0x8019C524: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8019C528: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8019C52C: bnel        $t9, $zero, L_8019C540
    if (ctx->r25 != 0) {
        // 0x8019C530: sw          $zero, 0x0($a0)
        MEM_W(0X0, ctx->r4) = 0;
            goto L_8019C540;
    }
    goto skip_6;
    // 0x8019C530: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    skip_6:
    // 0x8019C534: b           L_8019C540
    // 0x8019C538: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
        goto L_8019C540;
    // 0x8019C538: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x8019C53C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8019C540:
    // 0x8019C540: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
L_8019C544:
    // 0x8019C544: lw          $t2, 0x14($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X14);
    // 0x8019C548: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x8019C54C: blez        $a1, L_8019C560
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8019C550: sw          $t3, 0x4($a3)
        MEM_W(0X4, ctx->r7) = ctx->r11;
            goto L_8019C560;
    }
    // 0x8019C550: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x8019C554: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8019C558: subu        $t5, $a1, $t4
    ctx->r13 = SUB32(ctx->r5, ctx->r12);
    // 0x8019C55C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_8019C560:
    // 0x8019C560: b           L_8019C578
    // 0x8019C564: lw          $t1, 0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4);
        goto L_8019C578;
    // 0x8019C564: lw          $t1, 0x4($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4);
    // 0x8019C568: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
L_8019C56C:
    // 0x8019C56C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8019C570: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8019C574: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
L_8019C578:
    // 0x8019C578: blez        $t1, L_8019C584
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8019C57C: addiu       $t7, $t1, -0x1
        ctx->r15 = ADD32(ctx->r9, -0X1);
            goto L_8019C584;
    }
    // 0x8019C57C: addiu       $t7, $t1, -0x1
    ctx->r15 = ADD32(ctx->r9, -0X1);
    // 0x8019C580: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
L_8019C584:
    // 0x8019C584: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8019C588: beql        $v0, $t8, L_8019C598
    if (ctx->r2 == ctx->r24) {
        // 0x8019C58C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8019C598;
    }
    goto skip_7;
    // 0x8019C58C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_7:
    // 0x8019C590: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8019C594: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8019C598:
    // 0x8019C598: jr          $ra
    // 0x8019C59C: nop

    return;
    // 0x8019C59C: nop

;}
RECOMP_FUNC void Map_PathStatus_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F83C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F840: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F844: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019F848: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019F84C: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x8019F850: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019F854: sw          $zero, -0x2690($at)
    MEM_W(-0X2690, ctx->r1) = 0;
    // 0x8019F858: addiu       $t3, $t3, 0x4BD0
    ctx->r11 = ADD32(ctx->r11, 0X4BD0);
    // 0x8019F85C: addiu       $a1, $a1, 0x4750
    ctx->r5 = ADD32(ctx->r5, 0X4750);
    // 0x8019F860: addiu       $a0, $a0, -0x2E8
    ctx->r4 = ADD32(ctx->r4, -0X2E8);
    // 0x8019F864: addiu       $v1, $v1, 0x7BD8
    ctx->r3 = ADD32(ctx->r3, 0X7BD8);
    // 0x8019F868: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8019F86C: addiu       $t1, $zero, 0xB
    ctx->r9 = ADD32(0, 0XB);
    // 0x8019F870: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8019F874: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8019F878: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_8019F87C:
    // 0x8019F87C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8019F880: beql        $a2, $v0, L_8019F8A4
    if (ctx->r6 == ctx->r2) {
        // 0x8019F884: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8019F8A4;
    }
    goto skip_0;
    // 0x8019F884: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_0:
    // 0x8019F888: beql        $a3, $v0, L_8019F8A4
    if (ctx->r7 == ctx->r2) {
        // 0x8019F88C: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8019F8A4;
    }
    goto skip_1;
    // 0x8019F88C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_1:
    // 0x8019F890: beql        $t0, $v0, L_8019F8A4
    if (ctx->r8 == ctx->r2) {
        // 0x8019F894: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8019F8A4;
    }
    goto skip_2;
    // 0x8019F894: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_2:
    // 0x8019F898: bne         $t1, $v0, L_8019F8A8
    if (ctx->r9 != ctx->r2) {
        // 0x8019F89C: nop
    
            goto L_8019F8A8;
    }
    // 0x8019F89C: nop

    // 0x8019F8A0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8019F8A4:
    // 0x8019F8A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019F8A8:
    // 0x8019F8A8: bnel        $t2, $v0, L_8019F8B8
    if (ctx->r10 != ctx->r2) {
        // 0x8019F8AC: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_8019F8B8;
    }
    goto skip_3;
    // 0x8019F8AC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_3:
    // 0x8019F8B0: sw          $a3, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r7;
    // 0x8019F8B4: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_8019F8B8:
    // 0x8019F8B8: sw          $zero, 0x18($a0)
    MEM_W(0X18, ctx->r4) = 0;
    // 0x8019F8BC: swc1        $f0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f0.u32l;
    // 0x8019F8C0: beql        $a2, $v0, L_8019F8E4
    if (ctx->r6 == ctx->r2) {
        // 0x8019F8C4: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8019F8E4;
    }
    goto skip_4;
    // 0x8019F8C4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    skip_4:
    // 0x8019F8C8: beql        $a3, $v0, L_8019F8E4
    if (ctx->r7 == ctx->r2) {
        // 0x8019F8CC: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8019F8E4;
    }
    goto skip_5;
    // 0x8019F8CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    skip_5:
    // 0x8019F8D0: beql        $t0, $v0, L_8019F8E4
    if (ctx->r8 == ctx->r2) {
        // 0x8019F8D4: sw          $zero, 0x4($v1)
        MEM_W(0X4, ctx->r3) = 0;
            goto L_8019F8E4;
    }
    goto skip_6;
    // 0x8019F8D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    skip_6:
    // 0x8019F8D8: bne         $t1, $v0, L_8019F8E8
    if (ctx->r9 != ctx->r2) {
        // 0x8019F8DC: nop
    
            goto L_8019F8E8;
    }
    // 0x8019F8DC: nop

    // 0x8019F8E0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
L_8019F8E4:
    // 0x8019F8E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8019F8E8:
    // 0x8019F8E8: bne         $t2, $v0, L_8019F8F4
    if (ctx->r10 != ctx->r2) {
        // 0x8019F8EC: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8019F8F4;
    }
    // 0x8019F8EC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8019F8F0: sw          $a3, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r7;
L_8019F8F4:
    // 0x8019F8F4: addiu       $a1, $a1, 0x60
    ctx->r5 = ADD32(ctx->r5, 0X60);
    // 0x8019F8F8: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
    // 0x8019F8FC: swc1        $f0, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->f0.u32l;
    // 0x8019F900: bne         $a1, $t3, L_8019F87C
    if (ctx->r5 != ctx->r11) {
        // 0x8019F904: addiu       $a0, $a0, 0x38
        ctx->r4 = ADD32(ctx->r4, 0X38);
            goto L_8019F87C;
    }
    // 0x8019F904: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x8019F908: jr          $ra
    // 0x8019F90C: nop

    return;
    // 0x8019F90C: nop

;}
RECOMP_FUNC void Option_Ranking_SaveData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019D624: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x8019D628: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019D62C: addiu       $v0, $v0, -0x6EB0
    ctx->r2 = ADD32(ctx->r2, -0X6EB0);
    // 0x8019D630: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8019D634: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8019D638: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8019D63C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8019D640: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8019D644: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8019D648: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8019D64C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8019D650: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8019D654: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8019D658: lw          $t9, 0x7B48($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7B48);
    // 0x8019D65C: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x8019D660: sb          $t6, 0x142($sp)
    MEM_B(0X142, ctx->r29) = ctx->r14;
    // 0x8019D664: sb          $t7, 0x143($sp)
    MEM_B(0X143, ctx->r29) = ctx->r15;
    // 0x8019D668: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8019D66C: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x8019D670: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8019D674: lh          $t7, 0x1AA0($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X1AA0);
    // 0x8019D678: lw          $t9, 0x7BB4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7BB4);
    // 0x8019D67C: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019D680: sb          $t8, 0x144($sp)
    MEM_B(0X144, ctx->r29) = ctx->r24;
    // 0x8019D684: lw          $t8, 0x7BB0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X7BB0);
    // 0x8019D688: sb          $t6, 0x122($sp)
    MEM_B(0X122, ctx->r29) = ctx->r14;
    // 0x8019D68C: sb          $t7, 0x116($sp)
    MEM_B(0X116, ctx->r29) = ctx->r15;
    // 0x8019D690: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8019D694: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8019D698: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019D69C: lw          $t8, 0x7BB8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7BB8);
    // 0x8019D6A0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8019D6A4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8019D6A8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8019D6AC: or          $v1, $t7, $t9
    ctx->r3 = ctx->r15 | ctx->r25;
    // 0x8019D6B0: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019D6B4: addiu       $t8, $t8, 0x7BB0
    ctx->r24 = ADD32(ctx->r24, 0X7BB0);
    // 0x8019D6B8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8019D6BC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8019D6C0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8019D6C4: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8019D6C8: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x8019D6CC: sllv        $t6, $t9, $a0
    ctx->r14 = S32(ctx->r25 << (ctx->r4 & 31));
    // 0x8019D6D0: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x8019D6D4: or          $t7, $v1, $t6
    ctx->r15 = ctx->r3 | ctx->r14;
    // 0x8019D6D8: sllv        $t6, $t8, $t9
    ctx->r14 = S32(ctx->r24 << (ctx->r25 & 31));
    // 0x8019D6DC: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8019D6E0: or          $v1, $t7, $t6
    ctx->r3 = ctx->r15 | ctx->r14;
    // 0x8019D6E4: addiu       $t9, $a0, 0x2
    ctx->r25 = ADD32(ctx->r4, 0X2);
    // 0x8019D6E8: sllv        $t6, $t8, $t9
    ctx->r14 = S32(ctx->r24 << (ctx->r25 & 31));
    // 0x8019D6EC: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8019D6F0: or          $t7, $v1, $zero
    ctx->r15 = ctx->r3 | 0;
    // 0x8019D6F4: or          $v1, $t7, $t6
    ctx->r3 = ctx->r15 | ctx->r14;
    // 0x8019D6F8: addiu       $t9, $a0, 0x3
    ctx->r25 = ADD32(ctx->r4, 0X3);
    // 0x8019D6FC: or          $t7, $v1, $zero
    ctx->r15 = ctx->r3 | 0;
    // 0x8019D700: sllv        $t6, $t8, $t9
    ctx->r14 = S32(ctx->r24 << (ctx->r25 & 31));
    // 0x8019D704: or          $v1, $t7, $t6
    ctx->r3 = ctx->r15 | ctx->r14;
    // 0x8019D708: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019D70C: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8019D710: sb          $v1, 0x10A($sp)
    MEM_B(0X10A, ctx->r29) = ctx->r3;
    // 0x8019D714: addiu       $t4, $t4, 0x7B6C
    ctx->r12 = ADD32(ctx->r12, 0X7B6C);
    // 0x8019D718: addiu       $a2, $a2, 0x7B50
    ctx->r6 = ADD32(ctx->r6, 0X7B50);
    // 0x8019D71C: addiu       $v0, $sp, 0x64
    ctx->r2 = ADD32(ctx->r29, 0X64);
    // 0x8019D720: addiu       $t0, $t0, 0x7B90
    ctx->r8 = ADD32(ctx->r8, 0X7B90);
    // 0x8019D724: addiu       $a3, $a3, 0x7B70
    ctx->r7 = ADD32(ctx->r7, 0X7B70);
    // 0x8019D728: lui         $t3, 0xFF
    ctx->r11 = S32(0XFF << 16);
    // 0x8019D72C: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x8019D730: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
L_8019D734:
    // 0x8019D734: lbu         $t8, 0x8D($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X8D);
    // 0x8019D738: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8019D73C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8019D740: andi        $t9, $t8, 0xFFF7
    ctx->r25 = ctx->r24 & 0XFFF7;
    // 0x8019D744: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x8019D748: bne         $at, $zero, L_8019D75C
    if (ctx->r1 != 0) {
        // 0x8019D74C: sb          $t9, 0x8D($v0)
        MEM_B(0X8D, ctx->r2) = ctx->r25;
            goto L_8019D75C;
    }
    // 0x8019D74C: sb          $t9, 0x8D($v0)
    MEM_B(0X8D, ctx->r2) = ctx->r25;
    // 0x8019D750: ori         $t8, $t9, 0x8
    ctx->r24 = ctx->r25 | 0X8;
    // 0x8019D754: addiu       $v1, $v1, -0x100
    ctx->r3 = ADD32(ctx->r3, -0X100);
    // 0x8019D758: sb          $t8, 0x8D($v0)
    MEM_B(0X8D, ctx->r2) = ctx->r24;
L_8019D75C:
    // 0x8019D75C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8019D760: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8019D764: sb          $v1, 0x8C($v0)
    MEM_B(0X8C, ctx->r2) = ctx->r3;
    // 0x8019D768: bne         $t1, $a1, L_8019D774
    if (ctx->r9 != ctx->r5) {
        // 0x8019D76C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8019D774;
    }
    // 0x8019D76C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8019D770: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_8019D774:
    // 0x8019D774: bnel        $t2, $a1, L_8019D784
    if (ctx->r10 != ctx->r5) {
        // 0x8019D778: lbu         $t9, 0x8D($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X8D);
            goto L_8019D784;
    }
    goto skip_0;
    // 0x8019D778: lbu         $t9, 0x8D($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X8D);
    skip_0:
    // 0x8019D77C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8019D780: lbu         $t9, 0x8D($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X8D);
L_8019D784:
    // 0x8019D784: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8019D788: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8019D78C: andi        $t6, $t9, 0xFF0F
    ctx->r14 = ctx->r25 & 0XFF0F;
    // 0x8019D790: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8019D794: sb          $t7, 0x8D($v0)
    MEM_B(0X8D, ctx->r2) = ctx->r15;
    // 0x8019D798: and         $t9, $v1, $t3
    ctx->r25 = ctx->r3 & ctx->r11;
    // 0x8019D79C: lbu         $t6, 0x8D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8D);
    // 0x8019D7A0: sra         $t7, $t9, 16
    ctx->r15 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8019D7A4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8019D7A8: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x8019D7AC: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x8019D7B0: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8019D7B4: sb          $t9, 0x8D($v0)
    MEM_B(0X8D, ctx->r2) = ctx->r25;
    // 0x8019D7B8: lbu         $t8, 0x8D($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X8D);
    // 0x8019D7BC: andi        $t6, $v1, 0xFF00
    ctx->r14 = ctx->r3 & 0XFF00;
    // 0x8019D7C0: sra         $t9, $t6, 8
    ctx->r25 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8019D7C4: andi        $t6, $t9, 0x1
    ctx->r14 = ctx->r25 & 0X1;
    // 0x8019D7C8: andi        $t7, $t8, 0xFFFE
    ctx->r15 = ctx->r24 & 0XFFFE;
    // 0x8019D7CC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8019D7D0: sb          $t9, 0x8D($v0)
    MEM_B(0X8D, ctx->r2) = ctx->r25;
    // 0x8019D7D4: lbu         $t6, 0x8D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8D);
    // 0x8019D7D8: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8019D7DC: andi        $t8, $t9, 0x2
    ctx->r24 = ctx->r25 & 0X2;
    // 0x8019D7E0: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x8019D7E4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8019D7E8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8019D7EC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8019D7F0: bne         $a2, $t4, L_8019D734
    if (ctx->r6 != ctx->r12) {
        // 0x8019D7F4: sb          $t9, 0x8B($v0)
        MEM_B(0X8B, ctx->r2) = ctx->r25;
            goto L_8019D734;
    }
    // 0x8019D7F4: sb          $t9, 0x8B($v0)
    MEM_B(0X8B, ctx->r2) = ctx->r25;
    // 0x8019D7F8: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x8019D7FC: addiu       $t1, $t6, -0x7790
    ctx->r9 = ADD32(ctx->r14, -0X7790);
    // 0x8019D800: lui         $s1, 0x8018
    ctx->r17 = S32(0X8018 << 16);
    // 0x8019D804: addiu       $s1, $s1, -0x7704
    ctx->r17 = ADD32(ctx->r17, -0X7704);
    // 0x8019D808: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8019D80C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8019D810: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x8019D814: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    // 0x8019D818: addiu       $t4, $sp, 0x118
    ctx->r12 = ADD32(ctx->r29, 0X118);
    // 0x8019D81C: addiu       $t5, $sp, 0x10C
    ctx->r13 = ADD32(ctx->r29, 0X10C);
    // 0x8019D820: addiu       $ra, $sp, 0x100
    ctx->r31 = ADD32(ctx->r29, 0X100);
    // 0x8019D824: addiu       $s0, $sp, 0x64
    ctx->r16 = ADD32(ctx->r29, 0X64);
    // 0x8019D828: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
L_8019D82C:
    // 0x8019D82C: lbu         $t8, 0x18($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X18);
    // 0x8019D830: lbu         $t7, 0x19($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X19);
    // 0x8019D834: lbu         $t9, 0x1A($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X1A);
    // 0x8019D838: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
    // 0x8019D83C: sb          $t7, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r15;
    // 0x8019D840: lbu         $t6, 0x36($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X36);
    // 0x8019D844: lbu         $t8, 0x40($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X40);
    // 0x8019D848: lhu         $t7, 0x4A($t3)
    ctx->r15 = MEM_HU(ctx->r11, 0X4A);
    // 0x8019D84C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019D850: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8019D854: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8019D858: sb          $t9, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r25;
    // 0x8019D85C: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
    // 0x8019D860: sb          $t8, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r24;
    // 0x8019D864: sb          $t7, 0x0($ra)
    MEM_B(0X0, ctx->r31) = ctx->r15;
L_8019D868:
    // 0x8019D868: lbu         $t6, 0x5F($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5F);
    // 0x8019D86C: lbu         $t9, 0x5E($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5E);
    // 0x8019D870: lhu         $a0, 0x5E($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X5E);
    // 0x8019D874: srl         $t8, $t6, 4
    ctx->r24 = S32(U32(ctx->r14) >> 4);
    // 0x8019D878: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8019D87C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8019D880: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8019D884: andi        $t8, $t6, 0xFF0F
    ctx->r24 = ctx->r14 & 0XFF0F;
    // 0x8019D888: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8019D88C: sll         $t6, $a0, 28
    ctx->r14 = S32(ctx->r4 << 28);
    // 0x8019D890: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x8019D894: srl         $t9, $t6, 31
    ctx->r25 = S32(U32(ctx->r14) >> 31);
    // 0x8019D898: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8019D89C: sll         $t8, $t9, 3
    ctx->r24 = S32(ctx->r25 << 3);
    // 0x8019D8A0: andi        $t7, $t8, 0x8
    ctx->r15 = ctx->r24 & 0X8;
    // 0x8019D8A4: andi        $t9, $t6, 0xFFF7
    ctx->r25 = ctx->r14 & 0XFFF7;
    // 0x8019D8A8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8019D8AC: sll         $t6, $a0, 29
    ctx->r14 = S32(ctx->r4 << 29);
    // 0x8019D8B0: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8019D8B4: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8019D8B8: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8019D8BC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8019D8C0: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x8019D8C4: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x8019D8C8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8019D8CC: sll         $t6, $a0, 30
    ctx->r14 = S32(ctx->r4 << 30);
    // 0x8019D8D0: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x8019D8D4: srl         $t8, $t6, 31
    ctx->r24 = S32(U32(ctx->r14) >> 31);
    // 0x8019D8D8: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8019D8DC: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x8019D8E0: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x8019D8E4: andi        $t8, $t6, 0xFFFD
    ctx->r24 = ctx->r14 & 0XFFFD;
    // 0x8019D8E8: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x8019D8EC: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x8019D8F0: or          $t8, $t7, $zero
    ctx->r24 = ctx->r15 | 0;
    // 0x8019D8F4: andi        $t7, $t8, 0xFE
    ctx->r15 = ctx->r24 & 0XFE;
    // 0x8019D8F8: andi        $t9, $a0, 0x1
    ctx->r25 = ctx->r4 & 0X1;
    // 0x8019D8FC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8019D900: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x8019D904: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8019D908: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8019D90C: bne         $a1, $a2, L_8019D868
    if (ctx->r5 != ctx->r6) {
        // 0x8019D910: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_8019D868;
    }
    // 0x8019D910: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
    // 0x8019D914: addiu       $t1, $t1, 0xE
    ctx->r9 = ADD32(ctx->r9, 0XE);
    // 0x8019D918: sltu        $at, $t1, $s1
    ctx->r1 = ctx->r9 < ctx->r17 ? 1 : 0;
    // 0x8019D91C: addiu       $a3, $a3, 0x3
    ctx->r7 = ADD32(ctx->r7, 0X3);
    // 0x8019D920: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8019D924: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8019D928: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8019D92C: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8019D930: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x8019D934: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x8019D938: bne         $at, $zero, L_8019D82C
    if (ctx->r1 != 0) {
        // 0x8019D93C: addiu       $s0, $s0, 0xE
        ctx->r16 = ADD32(ctx->r16, 0XE);
            goto L_8019D82C;
    }
    // 0x8019D93C: addiu       $s0, $s0, 0xE
    ctx->r16 = ADD32(ctx->r16, 0XE);
    // 0x8019D940: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019D944: lw          $v0, -0x6F6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6F6C);
    // 0x8019D948: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019D94C: addiu       $t1, $t8, -0x7790
    ctx->r9 = ADD32(ctx->r24, -0X7790);
    // 0x8019D950: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x8019D954: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8019D958: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x8019D95C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8019D960: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8019D964: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8019D968: lui         $s5, 0x8018
    ctx->r21 = S32(0X8018 << 16);
    // 0x8019D96C: addiu       $s5, $s5, -0x7704
    ctx->r21 = ADD32(ctx->r21, -0X7704);
    // 0x8019D970: addu        $t5, $t7, $t1
    ctx->r13 = ADD32(ctx->r15, ctx->r9);
    // 0x8019D974: addu        $t4, $t9, $t1
    ctx->r12 = ADD32(ctx->r25, ctx->r9);
    // 0x8019D978: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8019D97C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8019D980: or          $t3, $t1, $zero
    ctx->r11 = ctx->r9 | 0;
    // 0x8019D984: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8019D988: addiu       $s4, $sp, 0x100
    ctx->r20 = ADD32(ctx->r29, 0X100);
    // 0x8019D98C: addiu       $s3, $sp, 0x10C
    ctx->r19 = ADD32(ctx->r29, 0X10C);
    // 0x8019D990: addiu       $s2, $sp, 0x118
    ctx->r18 = ADD32(ctx->r29, 0X118);
    // 0x8019D994: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x8019D998: addiu       $s0, $sp, 0x124
    ctx->r16 = ADD32(ctx->r29, 0X124);
    // 0x8019D99C: lw          $ra, 0x150($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X150);
    // 0x8019D9A0: sw          $v0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r2;
L_8019D9A4:
    // 0x8019D9A4: bne         $t1, $t4, L_8019D9B4
    if (ctx->r9 != ctx->r12) {
        // 0x8019D9A8: nop
    
            goto L_8019D9B4;
    }
    // 0x8019D9A8: nop

    // 0x8019D9AC: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x8019D9B0: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
L_8019D9B4:
    // 0x8019D9B4: multu       $a3, $s1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019D9B8: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8019D9BC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8019D9C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8019D9C4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8019D9C8: mflo        $t6
    ctx->r14 = lo;
    // 0x8019D9CC: addu        $a0, $s0, $t6
    ctx->r4 = ADD32(ctx->r16, ctx->r14);
    // 0x8019D9D0: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x8019D9D4: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    // 0x8019D9D8: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x8019D9DC: addu        $t6, $s2, $a3
    ctx->r14 = ADD32(ctx->r18, ctx->r7);
    // 0x8019D9E0: sb          $t9, 0x15($t0)
    MEM_B(0X15, ctx->r8) = ctx->r25;
    // 0x8019D9E4: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8019D9E8: sb          $t7, 0x16($t0)
    MEM_B(0X16, ctx->r8) = ctx->r15;
    // 0x8019D9EC: addu        $t7, $s3, $a3
    ctx->r15 = ADD32(ctx->r19, ctx->r7);
    // 0x8019D9F0: sb          $t8, 0x17($t0)
    MEM_B(0X17, ctx->r8) = ctx->r24;
    // 0x8019D9F4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8019D9F8: addu        $t6, $s4, $a3
    ctx->r14 = ADD32(ctx->r20, ctx->r7);
    // 0x8019D9FC: sb          $t9, 0x35($t2)
    MEM_B(0X35, ctx->r10) = ctx->r25;
    // 0x8019DA00: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x8019DA04: sll         $t7, $a3, 3
    ctx->r15 = S32(ctx->r7 << 3);
    // 0x8019DA08: subu        $t7, $t7, $a3
    ctx->r15 = SUB32(ctx->r15, ctx->r7);
    // 0x8019DA0C: sb          $t8, 0x3F($t2)
    MEM_B(0X3F, ctx->r10) = ctx->r24;
    // 0x8019DA10: addiu       $t8, $sp, 0x64
    ctx->r24 = ADD32(ctx->r29, 0X64);
    // 0x8019DA14: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8019DA18: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8019DA1C: sh          $t9, 0x4A($t3)
    MEM_H(0X4A, ctx->r11) = ctx->r25;
L_8019DA20:
    // 0x8019DA20: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8019DA24: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8019DA28: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x8019DA2C: srl         $t7, $t9, 4
    ctx->r15 = S32(U32(ctx->r25) >> 4);
    // 0x8019DA30: lbu         $t9, 0x5F($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5F);
    // 0x8019DA34: sb          $t6, 0x5E($v1)
    MEM_B(0X5E, ctx->r3) = ctx->r14;
    // 0x8019DA38: sll         $t6, $t7, 4
    ctx->r14 = S32(ctx->r15 << 4);
    // 0x8019DA3C: andi        $t7, $t9, 0xFF0F
    ctx->r15 = ctx->r25 & 0XFF0F;
    // 0x8019DA40: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8019DA44: sll         $t9, $a0, 28
    ctx->r25 = S32(ctx->r4 << 28);
    // 0x8019DA48: sb          $t8, 0x5F($v1)
    MEM_B(0X5F, ctx->r3) = ctx->r24;
    // 0x8019DA4C: srl         $t6, $t9, 31
    ctx->r14 = S32(U32(ctx->r25) >> 31);
    // 0x8019DA50: lbu         $t9, 0x5F($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5F);
    // 0x8019DA54: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8019DA58: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8019DA5C: andi        $t6, $t9, 0xFFF7
    ctx->r14 = ctx->r25 & 0XFFF7;
    // 0x8019DA60: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8019DA64: sll         $t9, $a0, 29
    ctx->r25 = S32(ctx->r4 << 29);
    // 0x8019DA68: sb          $t7, 0x5F($v1)
    MEM_B(0X5F, ctx->r3) = ctx->r15;
    // 0x8019DA6C: srl         $t8, $t9, 31
    ctx->r24 = S32(U32(ctx->r25) >> 31);
    // 0x8019DA70: lbu         $t9, 0x5F($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5F);
    // 0x8019DA74: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8019DA78: andi        $t7, $t6, 0x4
    ctx->r15 = ctx->r14 & 0X4;
    // 0x8019DA7C: andi        $t8, $t9, 0xFFFB
    ctx->r24 = ctx->r25 & 0XFFFB;
    // 0x8019DA80: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8019DA84: sll         $t9, $a0, 30
    ctx->r25 = S32(ctx->r4 << 30);
    // 0x8019DA88: sb          $t6, 0x5F($v1)
    MEM_B(0X5F, ctx->r3) = ctx->r14;
    // 0x8019DA8C: srl         $t7, $t9, 31
    ctx->r15 = S32(U32(ctx->r25) >> 31);
    // 0x8019DA90: lbu         $t9, 0x5F($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5F);
    // 0x8019DA94: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8019DA98: andi        $t6, $t8, 0x2
    ctx->r14 = ctx->r24 & 0X2;
    // 0x8019DA9C: andi        $t7, $t9, 0xFFFD
    ctx->r15 = ctx->r25 & 0XFFFD;
    // 0x8019DAA0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8019DAA4: sb          $t8, 0x5F($v1)
    MEM_B(0X5F, ctx->r3) = ctx->r24;
    // 0x8019DAA8: or          $t7, $t8, $zero
    ctx->r15 = ctx->r24 | 0;
    // 0x8019DAAC: andi        $t8, $t7, 0xFE
    ctx->r24 = ctx->r15 & 0XFE;
    // 0x8019DAB0: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x8019DAB4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8019DAB8: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8019DABC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8019DAC0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8019DAC4: bne         $a1, $a2, L_8019DA20
    if (ctx->r5 != ctx->r6) {
        // 0x8019DAC8: sb          $t9, 0x5D($v1)
        MEM_B(0X5D, ctx->r3) = ctx->r25;
            goto L_8019DA20;
    }
    // 0x8019DAC8: sb          $t9, 0x5D($v1)
    MEM_B(0X5D, ctx->r3) = ctx->r25;
    // 0x8019DACC: bne         $t1, $t5, L_8019DADC
    if (ctx->r9 != ctx->r13) {
        // 0x8019DAD0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_8019DADC;
    }
    // 0x8019DAD0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8019DAD4: b           L_8019DADC
    // 0x8019DAD8: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
        goto L_8019DADC;
    // 0x8019DAD8: or          $a3, $ra, $zero
    ctx->r7 = ctx->r31 | 0;
L_8019DADC:
    // 0x8019DADC: addiu       $t1, $t1, 0xE
    ctx->r9 = ADD32(ctx->r9, 0XE);
    // 0x8019DAE0: bne         $t1, $s5, L_8019D9A4
    if (ctx->r9 != ctx->r21) {
        // 0x8019DAE4: addiu       $t3, $t3, 0x2
        ctx->r11 = ADD32(ctx->r11, 0X2);
            goto L_8019D9A4;
    }
    // 0x8019DAE4: addiu       $t3, $t3, 0x2
    ctx->r11 = ADD32(ctx->r11, 0X2);
    // 0x8019DAE8: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8019DAEC: sw          $ra, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r31;
    // 0x8019DAF0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019DAF4: jal         0x800C3084
    // 0x8019DAF8: sb          $t7, -0x76A6($at)
    MEM_B(-0X76A6, ctx->r1) = ctx->r15;
    Save_Write(rdram, ctx);
        goto after_0;
    // 0x8019DAF8: sb          $t7, -0x76A6($at)
    MEM_B(-0X76A6, ctx->r1) = ctx->r15;
    after_0:
    // 0x8019DAFC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8019DB00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8019DB04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8019DB08: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8019DB0C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8019DB10: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8019DB14: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8019DB18: jr          $ra
    // 0x8019DB1C: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x8019DB1C: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void Map_SetState_ZoomPlanet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A659C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A65A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A65A4: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x801A65A8: jal         0x8001A838
    // 0x801A65AC: ori         $a0, $a0, 0x4C
    ctx->r4 = ctx->r4 | 0X4C;
    Audio_KillSfxById(rdram, ctx);
        goto after_0;
    // 0x801A65AC: ori         $a0, $a0, 0x4C
    ctx->r4 = ctx->r4 | 0X4C;
    after_0:
    // 0x801A65B0: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x801A65B4: jal         0x8001A838
    // 0x801A65B8: ori         $a0, $a0, 0x204C
    ctx->r4 = ctx->r4 | 0X204C;
    Audio_KillSfxById(rdram, ctx);
        goto after_1;
    // 0x801A65B8: ori         $a0, $a0, 0x204C
    ctx->r4 = ctx->r4 | 0X204C;
    after_1:
    // 0x801A65BC: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A65C0: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x801A65C4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801A65C8: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801A65CC: beq         $t6, $at, L_801A65FC
    if (ctx->r14 == ctx->r1) {
        // 0x801A65D0: addiu       $a3, $a3, 0x5D34
        ctx->r7 = ADD32(ctx->r7, 0X5D34);
            goto L_801A65FC;
    }
    // 0x801A65D0: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801A65D4: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x801A65D8: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x801A65DC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801A65E0: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801A65E4: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801A65E8: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x801A65EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801A65F0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801A65F4: jal         0x80019218
    // 0x801A65F8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801A65F8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
L_801A65FC:
    // 0x801A65FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A6600: sw          $zero, -0x1038($at)
    MEM_W(-0X1038, ctx->r1) = 0;
    // 0x801A6604: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A6608: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801A660C: sw          $t8, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r24;
    // 0x801A6610: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A6614: sw          $zero, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = 0;
    // 0x801A6618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A661C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A6620: jr          $ra
    // 0x801A6624: nop

    return;
    // 0x801A6624: nop

;}
RECOMP_FUNC void Option_DrawMenuArwing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BBA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8019BBA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019BBAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8019BBB0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8019BBB4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8019BBB8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019BBBC: lw          $t6, -0x6E44($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6E44);
    // 0x8019BBC0: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019BBC4: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8019BBC8: beq         $t6, $zero, L_8019BC34
    if (ctx->r14 == 0) {
        // 0x8019BBCC: lui         $a2, 0x801C
        ctx->r6 = S32(0X801C << 16);
            goto L_8019BC34;
    }
    // 0x8019BBCC: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8019BBD0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8019BBD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019BBD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019BBDC: lwc1        $f6, -0x6E08($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6E08);
    // 0x8019BBE0: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8019BBE4: lw          $a3, -0x6E00($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6E00);
    // 0x8019BBE8: lw          $a2, -0x6E0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6E0C);
    // 0x8019BBEC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019BBF0: jal         0x8019BC44
    // 0x8019BBF4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Option_DrawArwing(rdram, ctx);
        goto after_0;
    // 0x8019BBF4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8019BBF8: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8019BBFC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019BC00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019BC04: lwc1        $f18, -0x6E08($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6E08);
    // 0x8019BC08: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8019BC0C: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8019BC10: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8019BC14: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8019BC18: lw          $a3, -0x6E04($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6E04);
    // 0x8019BC1C: lw          $a2, -0x6E0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6E0C);
    // 0x8019BC20: lwc1        $f14, 0x24($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8019BC24: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019BC28: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8019BC2C: jal         0x8019BC44
    // 0x8019BC30: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    Option_DrawArwing(rdram, ctx);
        goto after_1;
    // 0x8019BC30: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
L_8019BC34:
    // 0x8019BC34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8019BC38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8019BC3C: jr          $ra
    // 0x8019BC40: nop

    return;
    // 0x8019BC40: nop

;}
RECOMP_FUNC void Title_PressStart_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F8E4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8018F8E8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8018F8EC: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x8018F8F0: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x8018F8F4: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x8018F8F8: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x8018F8FC: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8018F900: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8018F904: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018F908: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018F90C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8018F910: lw          $t6, -0x274C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X274C);
    // 0x8018F914: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x8018F918: addiu       $s0, $s0, 0x7BCC
    ctx->r16 = ADD32(ctx->r16, 0X7BCC);
    // 0x8018F91C: bne         $t6, $zero, L_8018FBE8
    if (ctx->r14 != 0) {
        // 0x8018F920: lui         $s3, 0x801B
        ctx->r19 = S32(0X801B << 16);
            goto L_8018FBE8;
    }
    // 0x8018F920: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x8018F924: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018F928: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018F92C: addiu       $s3, $s3, 0x7BC8
    ctx->r19 = ADD32(ctx->r19, 0X7BC8);
    // 0x8018F930: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018F934: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8018F938: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8018F93C: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x8018F940: jal         0x8009BC2C
    // 0x8018F944: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x8018F944: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8018F948: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8018F94C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018F950: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018F954: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018F958: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8018F95C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8018F960: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018F964: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8018F968: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    // 0x8018F96C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018F970: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018F974: c.eq.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl == ctx->f10.fl;
    // 0x8018F978: nop

    // 0x8018F97C: bc1f        L_8018F9B0
    if (!c1cs) {
        // 0x8018F980: nop
    
            goto L_8018F9B0;
    }
    // 0x8018F980: nop

    // 0x8018F984: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018F988: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8018F98C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8018F990: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8018F994: nop

    // 0x8018F998: bc1fl       L_8018F9B0
    if (!c1cs) {
        // 0x8018F99C: swc1        $f0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
            goto L_8018F9B0;
    }
    goto skip_0;
    // 0x8018F99C: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    skip_0:
    // 0x8018F9A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018F9A4: b           L_8018F9B0
    // 0x8018F9A8: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
        goto L_8018F9B0;
    // 0x8018F9A8: swc1        $f18, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f18.u32l;
    // 0x8018F9AC: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
L_8018F9B0:
    // 0x8018F9B0: lw          $t9, 0x7AF8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7AF8);
    // 0x8018F9B4: bgez        $t9, L_8018FB00
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018F9B8: nop
    
            goto L_8018FB00;
    }
    // 0x8018F9B8: nop

    // 0x8018F9BC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8018F9C0: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x8018F9C4: jal         0x800B8DD0
    // 0x8018F9C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8018F9C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8018F9CC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018F9D0: lui         $t2, 0x3C3C
    ctx->r10 = S32(0X3C3C << 16);
    // 0x8018F9D4: ori         $t2, $t2, 0xFFC8
    ctx->r10 = ctx->r10 | 0XFFC8;
    // 0x8018F9D8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8018F9DC: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x8018F9E0: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8018F9E4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018F9E8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018F9EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F9F0: lwc1        $f6, -0x1B9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1B9C);
    // 0x8018F9F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018F9F8: lwc1        $f8, -0x1B98($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1B98);
    // 0x8018F9FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018FA00: lwc1        $f4, -0x1B94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1B94);
    // 0x8018FA04: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018FA08: lwc1        $f10, -0x1B90($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1B90);
    // 0x8018FA0C: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x8018FA10: lui         $a2, 0x602
    ctx->r6 = S32(0X602 << 16);
    // 0x8018FA14: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8018FA18: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8018FA1C: addiu       $a2, $a2, -0x24B0
    ctx->r6 = ADD32(ctx->r6, -0X24B0);
    // 0x8018FA20: addiu       $a1, $a1, -0x28B0
    ctx->r5 = ADD32(ctx->r5, -0X28B0);
    // 0x8018FA24: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FA28: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8018FA2C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8018FA30: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8018FA34: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    // 0x8018FA38: jal         0x8009D0BC
    // 0x8018FA3C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_2;
    // 0x8018FA3C: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8018FA40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FA44: jal         0x800B8DD0
    // 0x8018FA48: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8018FA48: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_3:
    // 0x8018FA4C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018FA50: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8018FA54: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8018FA58: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8018FA5C: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x8018FA60: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8018FA64: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8018FA68: lui         $s1, 0x601
    ctx->r17 = S32(0X601 << 16);
    // 0x8018FA6C: addiu       $s1, $s1, 0x23F0
    ctx->r17 = ADD32(ctx->r17, 0X23F0);
    // 0x8018FA70: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8018FA74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018FA78: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8018FA7C: nop

    // 0x8018FA80: andi        $t7, $a0, 0xFF
    ctx->r15 = ctx->r4 & 0XFF;
    // 0x8018FA84: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8018FA88: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8018FA8C: sll         $t0, $t7, 8
    ctx->r8 = S32(ctx->r15 << 8);
    // 0x8018FA90: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x8018FA94: ori         $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 | 0XFF;
    // 0x8018FA98: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018FA9C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8018FAA0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018FAA4: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_8018FAA8:
    // 0x8018FAA8: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8018FAAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018FAB0: lwc1        $f6, -0x1B8C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1B8C);
    // 0x8018FAB4: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018FAB8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018FABC: lwc1        $f16, -0x1B88($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1B88);
    // 0x8018FAC0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FAC4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8018FAC8: addiu       $a2, $zero, 0xB0
    ctx->r6 = ADD32(0, 0XB0);
    // 0x8018FACC: mul.s       $f10, $f4, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8018FAD0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8018FAD4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FAD8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018FADC: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8018FAE0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018FAE4: jal         0x8009D994
    // 0x8018FAE8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x8018FAE8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x8018FAEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018FAF0: bne         $s0, $s3, L_8018FAA8
    if (ctx->r16 != ctx->r19) {
        // 0x8018FAF4: addiu       $s1, $s1, 0x2C0
        ctx->r17 = ADD32(ctx->r17, 0X2C0);
            goto L_8018FAA8;
    }
    // 0x8018FAF4: addiu       $s1, $s1, 0x2C0
    ctx->r17 = ADD32(ctx->r17, 0X2C0);
    // 0x8018FAF8: b           L_8018FBEC
    // 0x8018FAFC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8018FBEC;
    // 0x8018FAFC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8018FB00:
    // 0x8018FB00: jal         0x800B8DD0
    // 0x8018FB04: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_5;
    // 0x8018FB04: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_5:
    // 0x8018FB08: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8018FB0C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8018FB10: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8018FB14: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018FB18: sw          $t3, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r11;
    // 0x8018FB1C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018FB20: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8018FB24: lui         $s1, 0x601
    ctx->r17 = S32(0X601 << 16);
    // 0x8018FB28: addiu       $s1, $s1, -0x1CA0
    ctx->r17 = ADD32(ctx->r17, -0X1CA0);
    // 0x8018FB2C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8018FB30: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018FB34: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x8018FB38: nop

    // 0x8018FB3C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x8018FB40: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8018FB44: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8018FB48: sll         $t9, $t6, 8
    ctx->r25 = S32(ctx->r14 << 8);
    // 0x8018FB4C: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x8018FB50: ori         $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 | 0XFF;
    // 0x8018FB54: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8018FB58: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8018FB5C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8018FB60: lui         $at, 0x433C
    ctx->r1 = S32(0X433C << 16);
    // 0x8018FB64: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8018FB68: lui         $at, 0x42CA
    ctx->r1 = S32(0X42CA << 16);
    // 0x8018FB6C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018FB70: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
L_8018FB74:
    // 0x8018FB74: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x8018FB78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FB7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8018FB80: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018FB84: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8018FB88: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    // 0x8018FB8C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018FB90: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FB94: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8018FB98: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x8018FB9C: add.s       $f18, $f16, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f24.fl;
    // 0x8018FBA0: jal         0x8009D994
    // 0x8018FBA4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_6;
    // 0x8018FBA4: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_6:
    // 0x8018FBA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018FBAC: bne         $s0, $s3, L_8018FB74
    if (ctx->r16 != ctx->r19) {
        // 0x8018FBB0: addiu       $s1, $s1, 0x2D0
        ctx->r17 = ADD32(ctx->r17, 0X2D0);
            goto L_8018FB74;
    }
    // 0x8018FBB0: addiu       $s1, $s1, 0x2D0
    ctx->r17 = ADD32(ctx->r17, 0X2D0);
    // 0x8018FBB4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8018FBB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FBBC: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x8018FBC0: addiu       $a1, $a1, -0x1700
    ctx->r5 = ADD32(ctx->r5, -0X1700);
    // 0x8018FBC4: add.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x8018FBC8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8018FBCC: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    // 0x8018FBD0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8018FBD4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8018FBD8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x8018FBDC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8018FBE0: jal         0x8009D994
    // 0x8018FBE4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_7;
    // 0x8018FBE4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_7:
L_8018FBE8:
    // 0x8018FBE8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8018FBEC:
    // 0x8018FBEC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018FBF0: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018FBF4: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8018FBF8: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8018FBFC: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x8018FC00: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x8018FC04: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x8018FC08: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x8018FC0C: jr          $ra
    // 0x8018FC10: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8018FC10: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Title_SunGlare_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FF74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018FF78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018FF7C: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8018FF80: lw          $t6, 0x7BD8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7BD8);
    // 0x8018FF84: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018FF88: beql        $t6, $zero, L_80190138
    if (ctx->r14 == 0) {
        // 0x8018FF8C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80190138;
    }
    goto skip_0;
    // 0x8018FF8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8018FF90: lwc1        $f0, 0x7BB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7BB8);
    // 0x8018FF94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018FF98: lwc1        $f4, 0x70B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X70B8);
    // 0x8018FF9C: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x8018FFA0: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8018FFA4: nop

    // 0x8018FFA8: bc1f        L_80190110
    if (!c1cs) {
        // 0x8018FFAC: nop
    
            goto L_80190110;
    }
    // 0x8018FFAC: nop

    // 0x8018FFB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018FFB4: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8018FFB8: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8018FFBC: nop

    // 0x8018FFC0: bc1f        L_80190110
    if (!c1cs) {
        // 0x8018FFC4: nop
    
            goto L_80190110;
    }
    // 0x8018FFC4: nop

    // 0x8018FFC8: lw          $t7, -0x7CC0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CC0);
    // 0x8018FFCC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018FFD0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018FFD4: blez        $t7, L_80190110
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8018FFD8: nop
    
            goto L_80190110;
    }
    // 0x8018FFD8: nop

    // 0x8018FFDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8018FFE0: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x8018FFE4: addiu       $t2, $t2, 0x7BD0
    ctx->r10 = ADD32(ctx->r10, 0X7BD0);
    // 0x8018FFE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8018FFEC: nop

    // 0x8018FFF0: bc1fl       L_80190010
    if (!c1cs) {
        // 0x8018FFF4: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_80190010;
    }
    goto skip_1;
    // 0x8018FFF4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_1:
    // 0x8018FFF8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8018FFFC: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80190000: beq         $at, $zero, L_8019000C
    if (ctx->r1 == 0) {
        // 0x80190004: addiu       $t8, $v0, 0x2
        ctx->r24 = ADD32(ctx->r2, 0X2);
            goto L_8019000C;
    }
    // 0x80190004: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x80190008: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8019000C:
    // 0x8019000C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_80190010:
    // 0x80190010: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80190014: addiu       $t2, $t2, 0x7BD0
    ctx->r10 = ADD32(ctx->r10, 0X7BD0);
    // 0x80190018: bc1f        L_80190030
    if (!c1cs) {
        // 0x8019001C: nop
    
            goto L_80190030;
    }
    // 0x8019001C: nop

    // 0x80190020: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80190024: blez        $v0, L_80190030
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80190028: addiu       $t9, $v0, -0x2
        ctx->r25 = ADD32(ctx->r2, -0X2);
            goto L_80190030;
    }
    // 0x80190028: addiu       $t9, $v0, -0x2
    ctx->r25 = ADD32(ctx->r2, -0X2);
    // 0x8019002C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
L_80190030:
    // 0x80190030: jal         0x800B8DD0
    // 0x80190034: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80190034: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x80190038: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019003C: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80190040: addiu       $t2, $t2, 0x7BD0
    ctx->r10 = ADD32(ctx->r10, 0X7BD0);
    // 0x80190044: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80190048: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019004C: lui         $t4, 0xBA00
    ctx->r12 = S32(0XBA00 << 16);
    // 0x80190050: ori         $t4, $t4, 0x402
    ctx->r12 = ctx->r12 | 0X402;
    // 0x80190054: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80190058: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8019005C: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80190060: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80190064: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80190068: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019006C: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x80190070: ori         $t7, $t7, 0x602
    ctx->r15 = ctx->r15 | 0X602;
    // 0x80190074: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80190078: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8019007C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80190080: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80190084: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80190088: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8019008C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80190090: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80190094: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80190098: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8019009C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801900A0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801900A4: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801900A8: addiu       $a1, $a1, -0x2A40
    ctx->r5 = ADD32(ctx->r5, -0X2A40);
    // 0x801900AC: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801900B0: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x801900B4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801900B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801900BC: lwc1        $f8, -0x6F80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6F80);
    // 0x801900C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801900C4: lwc1        $f10, -0x6F7C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6F7C);
    // 0x801900C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801900CC: lwc1        $f16, 0x7BB0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7BB0);
    // 0x801900D0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801900D4: lwc1        $f18, 0x7BB4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7BB4);
    // 0x801900D8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x801900DC: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x801900E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801900E4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801900E8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801900EC: jal         0x8009D418
    // 0x801900F0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_1;
    // 0x801900F0: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801900F4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801900F8: addiu       $v0, $v0, -0x6F80
    ctx->r2 = ADD32(ctx->r2, -0X6F80);
    // 0x801900FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190100: lwc1        $f6, 0x70BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X70BC);
    // 0x80190104: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80190108: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019010C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_80190110:
    // 0x80190110: jal         0x801918FC
    // 0x80190114: nop

    Title_Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x80190114: nop

    after_2:
    // 0x80190118: jal         0x80190144
    // 0x8019011C: nop

    Title_Sun_Draw(rdram, ctx);
        goto after_3;
    // 0x8019011C: nop

    after_3:
    // 0x80190120: jal         0x801903B8
    // 0x80190124: nop

    Title_SunGlare2_Draw(rdram, ctx);
        goto after_4;
    // 0x80190124: nop

    after_4:
    // 0x80190128: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019012C: jal         0x80005740
    // 0x80190130: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_5;
    // 0x80190130: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_5:
    // 0x80190134: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80190138:
    // 0x80190138: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019013C: jr          $ra
    // 0x80190140: nop

    return;
    // 0x80190140: nop

;}
RECOMP_FUNC void Option_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191B20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191B24: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x80191B28: addiu       $t0, $t0, -0x19C8
    ctx->r8 = ADD32(ctx->r8, -0X19C8);
    // 0x80191B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191B30: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80191B34: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80191B38: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80191B3C: sb          $t6, 0x7E78($at)
    MEM_B(0X7E78, ctx->r1) = ctx->r14;
    // 0x80191B40: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80191B44: lui         $t4, 0x800
    ctx->r12 = S32(0X800 << 16);
    // 0x80191B48: addiu       $t7, $t7, 0x3B50
    ctx->r15 = ADD32(ctx->r15, 0X3B50);
    // 0x80191B4C: addiu       $t8, $zero, 0x48
    ctx->r24 = ADD32(0, 0X48);
    // 0x80191B50: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80191B54: addiu       $t4, $t4, 0x46B0
    ctx->r12 = ADD32(ctx->r12, 0X46B0);
    // 0x80191B58: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x80191B5C: lui         $v1, 0x801B
    ctx->r3 = S32(0X801B << 16);
    // 0x80191B60: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80191B64: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80191B68: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80191B6C: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x80191B70: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x80191B74: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x80191B78: sw          $t9, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r25;
    // 0x80191B7C: sw          $t4, 0x188($t0)
    MEM_W(0X188, ctx->r8) = ctx->r12;
    // 0x80191B80: sw          $t5, 0x190($t0)
    MEM_W(0X190, ctx->r8) = ctx->r13;
    // 0x80191B84: sw          $a3, 0x194($t0)
    MEM_W(0X194, ctx->r8) = ctx->r7;
    // 0x80191B88: addiu       $a0, $a0, -0x1A48
    ctx->r4 = ADD32(ctx->r4, -0X1A48);
    // 0x80191B8C: addiu       $v0, $v0, -0x1A60
    ctx->r2 = ADD32(ctx->r2, -0X1A60);
    // 0x80191B90: addiu       $a2, $a2, -0x1A30
    ctx->r6 = ADD32(ctx->r6, -0X1A30);
    // 0x80191B94: addiu       $a1, $a1, -0x1A78
    ctx->r5 = ADD32(ctx->r5, -0X1A78);
    // 0x80191B98: addiu       $v1, $v1, -0x1A48
    ctx->r3 = ADD32(ctx->r3, -0X1A48);
L_80191B9C:
    // 0x80191B9C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80191BA0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80191BA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80191BA8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80191BAC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80191BB0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80191BB4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80191BB8: swc1        $f4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f4.u32l;
    // 0x80191BBC: bne         $at, $zero, L_80191B9C
    if (ctx->r1 != 0) {
        // 0x80191BC0: swc1        $f6, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->f6.u32l;
            goto L_80191B9C;
    }
    // 0x80191BC0: swc1        $f6, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f6.u32l;
    // 0x80191BC4: lui         $v1, 0x8018
    ctx->r3 = S32(0X8018 << 16);
    // 0x80191BC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80191BCC: addiu       $v1, $v1, -0x7790
    ctx->r3 = ADD32(ctx->r3, -0X7790);
    // 0x80191BD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80191BD4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_80191BD8:
    // 0x80191BD8: beq         $a0, $v0, L_80191C00
    if (ctx->r4 == ctx->r2) {
        // 0x80191BDC: addu        $t6, $v1, $a0
        ctx->r14 = ADD32(ctx->r3, ctx->r4);
            goto L_80191C00;
    }
    // 0x80191BDC: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x80191BE0: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80191BE4: sll         $t8, $t7, 30
    ctx->r24 = S32(ctx->r15 << 30);
    // 0x80191BE8: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80191BEC: andi        $t4, $t9, 0x1
    ctx->r12 = ctx->r25 & 0X1;
    // 0x80191BF0: bnel        $t4, $zero, L_80191C04
    if (ctx->r12 != 0) {
        // 0x80191BF4: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80191C04;
    }
    goto skip_0;
    // 0x80191BF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80191BF8: b           L_80191C10
    // 0x80191BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_80191C10;
    // 0x80191BFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80191C00:
    // 0x80191C00: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80191C04:
    // 0x80191C04: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x80191C08: bne         $at, $zero, L_80191BD8
    if (ctx->r1 != 0) {
        // 0x80191C0C: nop
    
            goto L_80191BD8;
    }
    // 0x80191C0C: nop

L_80191C10:
    // 0x80191C10: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191C14: sw          $a1, -0x6E38($at)
    MEM_W(-0X6E38, ctx->r1) = ctx->r5;
    // 0x80191C18: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191C1C: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80191C20: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191C24: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x80191C28: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191C2C: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x80191C30: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191C34: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x80191C38: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80191C3C: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80191C40: sb          $t5, 0x1A38($at)
    MEM_B(0X1A38, ctx->r1) = ctx->r13;
    // 0x80191C44: lui         $a0, 0x8016
    ctx->r4 = S32(0X8016 << 16);
    // 0x80191C48: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x80191C4C: addiu       $a0, $a0, 0x1A34
    ctx->r4 = ADD32(ctx->r4, 0X1A34);
    // 0x80191C50: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x80191C54: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80191C58: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x80191C5C: addiu       $a2, $a2, -0x6E5C
    ctx->r6 = ADD32(ctx->r6, -0X6E5C);
    // 0x80191C60: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80191C64: bne         $v0, $at, L_80191C8C
    if (ctx->r2 != ctx->r1) {
        // 0x80191C68: sw          $zero, 0x0($a2)
        MEM_W(0X0, ctx->r6) = 0;
            goto L_80191C8C;
    }
    // 0x80191C68: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80191C6C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80191C70: lw          $t6, -0x7DCC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7DCC);
    // 0x80191C74: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80191C78: bne         $a3, $t6, L_80191C8C
    if (ctx->r7 != ctx->r14) {
        // 0x80191C7C: nop
    
            goto L_80191C8C;
    }
    // 0x80191C7C: nop

    // 0x80191C80: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80191C84: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80191C88: andi        $v0, $zero, 0xFFFF
    ctx->r2 = 0 & 0XFFFF;
L_80191C8C:
    // 0x80191C8C: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80191C90: addiu       $a3, $a3, -0x6E58
    ctx->r7 = ADD32(ctx->r7, -0X6E58);
    // 0x80191C94: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80191C98: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191C9C: sw          $zero, -0x6E54($at)
    MEM_W(-0X6E54, ctx->r1) = 0;
    // 0x80191CA0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191CA4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x80191CA8: sw          $zero, -0x6E50($at)
    MEM_W(-0X6E50, ctx->r1) = 0;
    // 0x80191CAC: addiu       $a0, $a0, 0x79F8
    ctx->r4 = ADD32(ctx->r4, 0X79F8);
    // 0x80191CB0: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80191CB4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80191CB8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191CBC: sw          $zero, 0x7DB0($at)
    MEM_W(0X7DB0, ctx->r1) = 0;
    // 0x80191CC0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191CC4: sw          $zero, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = 0;
    // 0x80191CC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191CCC: sw          $zero, -0x6E88($at)
    MEM_W(-0X6E88, ctx->r1) = 0;
    // 0x80191CD0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191CD4: sw          $zero, -0x6E84($at)
    MEM_W(-0X6E84, ctx->r1) = 0;
    // 0x80191CD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191CDC: addiu       $t7, $zero, 0x3E8
    ctx->r15 = ADD32(0, 0X3E8);
    // 0x80191CE0: sw          $t7, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r15;
    // 0x80191CE4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80191CE8: beq         $v0, $at, L_80191CFC
    if (ctx->r2 == ctx->r1) {
        // 0x80191CEC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80191CFC;
    }
    // 0x80191CEC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80191CF0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80191CF4: bne         $v0, $at, L_80191E14
    if (ctx->r2 != ctx->r1) {
        // 0x80191CF8: lui         $t7, 0x800D
        ctx->r15 = S32(0X800D << 16);
            goto L_80191E14;
    }
    // 0x80191CF8: lui         $t7, 0x800D
    ctx->r15 = S32(0X800D << 16);
L_80191CFC:
    // 0x80191CFC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80191D00: bne         $v0, $at, L_80191DC8
    if (ctx->r2 != ctx->r1) {
        // 0x80191D04: addiu       $t9, $zero, 0xD
        ctx->r25 = ADD32(0, 0XD);
            goto L_80191DC8;
    }
    // 0x80191D04: addiu       $t9, $zero, 0xD
    ctx->r25 = ADD32(0, 0XD);
    // 0x80191D08: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x80191D0C: lw          $v0, 0x7B48($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B48);
    // 0x80191D10: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x80191D14: lbu         $a0, 0x3189($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X3189);
    // 0x80191D18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191D1C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80191D20: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80191D24: sw          $t9, 0x7B90($at)
    MEM_W(0X7B90, ctx->r1) = ctx->r25;
    // 0x80191D28: bne         $t2, $a0, L_80191D6C
    if (ctx->r10 != ctx->r4) {
        // 0x80191D2C: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80191D6C;
    }
    // 0x80191D2C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80191D30: lbu         $t4, 0xE($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XE);
    // 0x80191D34: andi        $t5, $t4, 0xFFFB
    ctx->r13 = ctx->r12 & 0XFFFB;
    // 0x80191D38: ori         $t6, $t5, 0x4
    ctx->r14 = ctx->r13 | 0X4;
    // 0x80191D3C: beq         $a1, $zero, L_80191D50
    if (ctx->r5 == 0) {
        // 0x80191D40: sb          $t6, 0xE($v1)
        MEM_B(0XE, ctx->r3) = ctx->r14;
            goto L_80191D50;
    }
    // 0x80191D40: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
    // 0x80191D44: ori         $t9, $t6, 0x8
    ctx->r25 = ctx->r14 | 0X8;
    // 0x80191D48: b           L_80191D5C
    // 0x80191D4C: sb          $t9, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r25;
        goto L_80191D5C;
    // 0x80191D4C: sb          $t9, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r25;
L_80191D50:
    // 0x80191D50: lbu         $t5, 0xE($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XE);
    // 0x80191D54: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80191D58: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
L_80191D5C:
    // 0x80191D5C: jal         0x800C3084
    // 0x80191D60: nop

    Save_Write(rdram, ctx);
        goto after_0;
    // 0x80191D60: nop

    after_0:
    // 0x80191D64: b           L_80191DC8
    // 0x80191D68: nop

        goto L_80191DC8;
    // 0x80191D68: nop

L_80191D6C:
    // 0x80191D6C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80191D70: bne         $t3, $a0, L_80191DC8
    if (ctx->r11 != ctx->r4) {
        // 0x80191D74: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_80191DC8;
    }
    // 0x80191D74: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191D78: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80191D7C: sw          $t2, 0x7BB0($at)
    MEM_W(0X7BB0, ctx->r1) = ctx->r10;
    // 0x80191D80: lbu         $t7, 0xF($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XF);
    // 0x80191D84: andi        $t8, $t7, 0xFFFB
    ctx->r24 = ctx->r15 & 0XFFFB;
    // 0x80191D88: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80191D8C: beq         $a1, $zero, L_80191DAC
    if (ctx->r5 == 0) {
        // 0x80191D90: sb          $t9, 0xF($v1)
        MEM_B(0XF, ctx->r3) = ctx->r25;
            goto L_80191DAC;
    }
    // 0x80191D90: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
    // 0x80191D94: or          $t5, $t9, $zero
    ctx->r13 = ctx->r25 | 0;
    // 0x80191D98: ori         $t8, $t5, 0x8
    ctx->r24 = ctx->r13 | 0X8;
    // 0x80191D9C: sb          $t8, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r24;
    // 0x80191DA0: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80191DA4: b           L_80191DC0
    // 0x80191DA8: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
        goto L_80191DC0;
    // 0x80191DA8: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
L_80191DAC:
    // 0x80191DAC: lbu         $t5, 0xF($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0XF);
    // 0x80191DB0: ori         $t8, $t5, 0x1
    ctx->r24 = ctx->r13 | 0X1;
    // 0x80191DB4: sb          $t8, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r24;
    // 0x80191DB8: ori         $t9, $t8, 0x2
    ctx->r25 = ctx->r24 | 0X2;
    // 0x80191DBC: sb          $t9, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r25;
L_80191DC0:
    // 0x80191DC0: jal         0x800C3084
    // 0x80191DC4: nop

    Save_Write(rdram, ctx);
        goto after_1;
    // 0x80191DC4: nop

    after_1:
L_80191DC8:
    // 0x80191DC8: jal         0x80188010
    // 0x80191DCC: nop

    Title_GetRankTotalHits(rdram, ctx);
        goto after_2;
    // 0x80191DCC: nop

    after_2:
    // 0x80191DD0: jal         0x8019C8C4
    // 0x80191DD4: nop

    Option_RankInPos_Check(rdram, ctx);
        goto after_3;
    // 0x80191DD4: nop

    after_3:
    // 0x80191DD8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80191DDC: addiu       $v1, $v1, -0x6F6C
    ctx->r3 = ADD32(ctx->r3, -0X6F6C);
    // 0x80191DE0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80191DE4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80191DE8: beq         $v0, $at, L_80191E00
    if (ctx->r2 == ctx->r1) {
        // 0x80191DEC: addiu       $t3, $zero, 0x2
        ctx->r11 = ADD32(0, 0X2);
            goto L_80191E00;
    }
    // 0x80191DEC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80191DF0: addiu       $t5, $zero, 0xC8
    ctx->r13 = ADD32(0, 0XC8);
    // 0x80191DF4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191DF8: b           L_80191F80
    // 0x80191DFC: sw          $t5, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r13;
        goto L_80191F80;
    // 0x80191DFC: sw          $t5, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r13;
L_80191E00:
    // 0x80191E00: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x80191E04: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191E08: sw          $t6, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r14;
    // 0x80191E0C: b           L_80191F80
    // 0x80191E10: nop

        goto L_80191F80;
    // 0x80191E10: nop

L_80191E14:
    // 0x80191E14: lw          $t7, 0x2870($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2870);
    // 0x80191E18: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80191E1C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80191E20: beq         $t7, $zero, L_80191F7C
    if (ctx->r15 == 0) {
        // 0x80191E24: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80191F7C;
    }
    // 0x80191E24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80191E28: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80191E2C: lw          $t8, 0x78AC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X78AC);
    // 0x80191E30: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x80191E34: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80191E38: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191E3C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80191E40: lwc1        $f14, 0x71A4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X71A4);
    // 0x80191E44: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80191E48: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80191E4C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191E50: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x80191E54: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x80191E58: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80191E5C: addiu       $a2, $a2, -0x1A90
    ctx->r6 = ADD32(ctx->r6, -0X1A90);
    // 0x80191E60: addiu       $a3, $a3, -0x1A30
    ctx->r7 = ADD32(ctx->r7, -0X1A30);
    // 0x80191E64: lwc1        $f0, 0x71A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X71A8);
    // 0x80191E68: addiu       $t1, $zero, 0x6
    ctx->r9 = ADD32(0, 0X6);
    // 0x80191E6C: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
L_80191E70:
    // 0x80191E70: beq         $a0, $t3, L_80191EC4
    if (ctx->r4 == ctx->r11) {
        // 0x80191E74: nop
    
            goto L_80191EC4;
    }
    // 0x80191E74: nop

    // 0x80191E78: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80191E7C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80191E80: addu        $t4, $a2, $v1
    ctx->r12 = ADD32(ctx->r6, ctx->r3);
    // 0x80191E84: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80191E88: addu        $t5, $a3, $v1
    ctx->r13 = ADD32(ctx->r7, ctx->r3);
    // 0x80191E8C: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80191E90: mflo        $t9
    ctx->r25 = lo;
    // 0x80191E94: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x80191E98: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x80191E9C: swc1        $f14, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f14.u32l;
    // 0x80191EA0: swc1        $f2, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f2.u32l;
    // 0x80191EA4: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
    // 0x80191EA8: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x80191EAC: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x80191EB0: swc1        $f12, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f12.u32l;
    // 0x80191EB4: swc1        $f16, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f16.u32l;
    // 0x80191EB8: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x80191EBC: swc1        $f8, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f8.u32l;
    // 0x80191EC0: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
L_80191EC4:
    // 0x80191EC4: beql        $a0, $t2, L_80191F1C
    if (ctx->r4 == ctx->r10) {
        // 0x80191EC8: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80191F1C;
    }
    goto skip_1;
    // 0x80191EC8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    skip_1:
    // 0x80191ECC: multu       $a0, $a1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80191ED0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80191ED4: addu        $t7, $a2, $v1
    ctx->r15 = ADD32(ctx->r6, ctx->r3);
    // 0x80191ED8: lwc1        $f18, 0x4($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X4);
    // 0x80191EDC: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x80191EE0: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x80191EE4: mflo        $t6
    ctx->r14 = lo;
    // 0x80191EE8: addu        $v0, $t0, $t6
    ctx->r2 = ADD32(ctx->r8, ctx->r14);
    // 0x80191EEC: swc1        $f0, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->f0.u32l;
    // 0x80191EF0: swc1        $f14, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->f14.u32l;
    // 0x80191EF4: swc1        $f2, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f2.u32l;
    // 0x80191EF8: swc1        $f2, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->f2.u32l;
    // 0x80191EFC: sw          $zero, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = 0;
    // 0x80191F00: swc1        $f0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->f0.u32l;
    // 0x80191F04: swc1        $f12, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->f12.u32l;
    // 0x80191F08: swc1        $f16, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f16.u32l;
    // 0x80191F0C: sw          $zero, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = 0;
    // 0x80191F10: swc1        $f18, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->f18.u32l;
    // 0x80191F14: swc1        $f4, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f4.u32l;
    // 0x80191F18: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_80191F1C:
    // 0x80191F1C: bne         $a0, $t1, L_80191E70
    if (ctx->r4 != ctx->r9) {
        // 0x80191F20: nop
    
            goto L_80191E70;
    }
    // 0x80191F20: nop

    // 0x80191F24: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80191F28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191F2C: swc1        $f2, 0xF8($t0)
    MEM_W(0XF8, ctx->r8) = ctx->f2.u32l;
    // 0x80191F30: swc1        $f2, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->f2.u32l;
    // 0x80191F34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191F38: swc1        $f6, 0xFC($t0)
    MEM_W(0XFC, ctx->r8) = ctx->f6.u32l;
    // 0x80191F3C: lwc1        $f8, 0x71AC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X71AC);
    // 0x80191F40: lui         $at, 0x4311
    ctx->r1 = S32(0X4311 << 16);
    // 0x80191F44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191F48: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80191F4C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80191F50: swc1        $f14, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f14.u32l;
    // 0x80191F54: sw          $t2, 0x11C($t0)
    MEM_W(0X11C, ctx->r8) = ctx->r10;
    // 0x80191F58: swc1        $f12, 0xE0($t0)
    MEM_W(0XE0, ctx->r8) = ctx->f12.u32l;
    // 0x80191F5C: swc1        $f12, 0xE4($t0)
    MEM_W(0XE4, ctx->r8) = ctx->f12.u32l;
    // 0x80191F60: sw          $t2, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->r10;
    // 0x80191F64: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191F68: swc1        $f8, 0x104($t0)
    MEM_W(0X104, ctx->r8) = ctx->f8.u32l;
    // 0x80191F6C: swc1        $f10, 0xD8($t0)
    MEM_W(0XD8, ctx->r8) = ctx->f10.u32l;
    // 0x80191F70: swc1        $f18, 0xDC($t0)
    MEM_W(0XDC, ctx->r8) = ctx->f18.u32l;
    // 0x80191F74: b           L_80191F80
    // 0x80191F78: sw          $t3, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r11;
        goto L_80191F80;
    // 0x80191F78: sw          $t3, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r11;
L_80191F7C:
    // 0x80191F7C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
L_80191F80:
    // 0x80191F80: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191F84: sw          $zero, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = 0;
    // 0x80191F88: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191F8C: sw          $zero, -0x6ECC($at)
    MEM_W(-0X6ECC, ctx->r1) = 0;
    // 0x80191F90: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80191F94: sw          $zero, -0x6EC4($at)
    MEM_W(-0X6EC4, ctx->r1) = 0;
    // 0x80191F98: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191F9C: jal         0x80006F20
    // 0x80191FA0: sw          $t3, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = ctx->r11;
    Memory_FreeAll(rdram, ctx);
        goto after_4;
    // 0x80191FA0: sw          $t3, 0x784C($at)
    MEM_W(0X784C, ctx->r1) = ctx->r11;
    after_4:
    // 0x80191FA4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80191FA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80191FAC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191FB0: swc1        $f4, -0x7BE0($at)
    MEM_W(-0X7BE0, ctx->r1) = ctx->f4.u32l;
    // 0x80191FB4: lui         $at, 0x4370
    ctx->r1 = S32(0X4370 << 16);
    // 0x80191FB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80191FBC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80191FC0: jal         0x800A5D6C
    // 0x80191FC4: swc1        $f6, -0x7BDC($at)
    MEM_W(-0X7BDC, ctx->r1) = ctx->f6.u32l;
    Play_GenerateStarfield(rdram, ctx);
        goto after_5;
    // 0x80191FC4: swc1        $f6, -0x7BDC($at)
    MEM_W(-0X7BDC, ctx->r1) = ctx->f6.u32l;
    after_5:
    // 0x80191FC8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80191FCC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191FD0: addiu       $v0, $zero, 0xE1
    ctx->r2 = ADD32(0, 0XE1);
    // 0x80191FD4: swc1        $f2, 0x7978($at)
    MEM_W(0X7978, ctx->r1) = ctx->f2.u32l;
    // 0x80191FD8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191FDC: swc1        $f2, 0x7980($at)
    MEM_W(0X7980, ctx->r1) = ctx->f2.u32l;
    // 0x80191FE0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80191FE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80191FE8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191FEC: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x80191FF0: swc1        $f8, 0x7988($at)
    MEM_W(0X7988, ctx->r1) = ctx->f8.u32l;
    // 0x80191FF4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80191FF8: swc1        $f2, 0x79A0($at)
    MEM_W(0X79A0, ctx->r1) = ctx->f2.u32l;
    // 0x80191FFC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192000: swc1        $f2, 0x79B8($at)
    MEM_W(0X79B8, ctx->r1) = ctx->f2.u32l;
    // 0x80192004: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192008: swc1        $f2, 0x79C0($at)
    MEM_W(0X79C0, ctx->r1) = ctx->f2.u32l;
    // 0x8019200C: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80192010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80192014: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192018: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8019201C: swc1        $f10, -0x6DDC($at)
    MEM_W(-0X6DDC, ctx->r1) = ctx->f10.u32l;
    // 0x80192020: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192024: swc1        $f2, -0x6DD8($at)
    MEM_W(-0X6DD8, ctx->r1) = ctx->f2.u32l;
    // 0x80192028: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019202C: sw          $v0, -0x6DD4($at)
    MEM_W(-0X6DD4, ctx->r1) = ctx->r2;
    // 0x80192030: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192034: sw          $v0, -0x6DD0($at)
    MEM_W(-0X6DD0, ctx->r1) = ctx->r2;
    // 0x80192038: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019203C: sw          $v0, -0x6DCC($at)
    MEM_W(-0X6DCC, ctx->r1) = ctx->r2;
    // 0x80192040: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192044: sw          $v1, -0x6DC8($at)
    MEM_W(-0X6DC8, ctx->r1) = ctx->r3;
    // 0x80192048: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019204C: sw          $v1, -0x6DC4($at)
    MEM_W(-0X6DC4, ctx->r1) = ctx->r3;
    // 0x80192050: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192054: sw          $v1, -0x6DC0($at)
    MEM_W(-0X6DC0, ctx->r1) = ctx->r3;
    // 0x80192058: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019205C: lwc1        $f18, 0x71B0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X71B0);
    // 0x80192060: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192064: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80192068: swc1        $f18, -0x6E08($at)
    MEM_W(-0X6E08, ctx->r1) = ctx->f18.u32l;
    // 0x8019206C: lui         $at, 0xC302
    ctx->r1 = S32(0XC302 << 16);
    // 0x80192070: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80192074: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192078: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x8019207C: swc1        $f4, -0x6E0C($at)
    MEM_W(-0X6E0C, ctx->r1) = ctx->f4.u32l;
    // 0x80192080: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192084: swc1        $f2, -0x6E04($at)
    MEM_W(-0X6E04, ctx->r1) = ctx->f2.u32l;
    // 0x80192088: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019208C: swc1        $f2, -0x6E00($at)
    MEM_W(-0X6E00, ctx->r1) = ctx->f2.u32l;
    // 0x80192090: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80192094: swc1        $f6, -0x6E14($at)
    MEM_W(-0X6E14, ctx->r1) = ctx->f6.u32l;
    // 0x80192098: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019209C: sw          $zero, -0x6DBC($at)
    MEM_W(-0X6DBC, ctx->r1) = 0;
    // 0x801920A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801920A4: sw          $zero, -0x6DB8($at)
    MEM_W(-0X6DB8, ctx->r1) = 0;
    // 0x801920A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801920AC: jal         0x8001D444
    // 0x801920B0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_6;
    // 0x801920B0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_6:
    // 0x801920B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801920B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801920BC: jr          $ra
    // 0x801920C0: nop

    return;
    // 0x801920C0: nop

;}
RECOMP_FUNC void Option_RankingTeamPresence_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80198608: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8019860C: sdc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X48, ctx->r29);
    // 0x80198610: sw          $s4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r20;
    // 0x80198614: sw          $s3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r19;
    // 0x80198618: mtc1        $a3, $f30
    ctx->f30.u32l = ctx->r7;
    // 0x8019861C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80198620: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80198624: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x80198628: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8019862C: sw          $s7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r23;
    // 0x80198630: sw          $s6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r22;
    // 0x80198634: sw          $s5, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r21;
    // 0x80198638: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x8019863C: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x80198640: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x80198644: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80198648: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x8019864C: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80198650: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80198654: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80198658: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8019865C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80198660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80198664: lui         $at, 0x431A
    ctx->r1 = S32(0X431A << 16);
    // 0x80198668: c.lt.s      $f4, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f4.fl < ctx->f30.fl;
    // 0x8019866C: nop

    // 0x80198670: bc1fl       L_801987E8
    if (!c1cs) {
        // 0x80198674: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_801987E8;
    }
    goto skip_0;
    // 0x80198674: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_0:
    // 0x80198678: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019867C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80198680: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80198684: c.lt.s      $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f30.fl < ctx->f6.fl;
    // 0x80198688: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8019868C: bc1fl       L_801987E8
    if (!c1cs) {
        // 0x80198690: lw          $ra, 0x74($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X74);
            goto L_801987E8;
    }
    goto skip_1;
    // 0x80198690: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    skip_1:
    // 0x80198694: jal         0x800B8DD0
    // 0x80198698: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80198698: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x8019869C: sll         $t6, $s3, 3
    ctx->r14 = S32(ctx->r19 << 3);
    // 0x801986A0: subu        $t6, $t6, $s3
    ctx->r14 = SUB32(ctx->r14, ctx->r19);
    // 0x801986A4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x801986A8: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
    // 0x801986AC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x801986B0: lui         $v0, 0x8018
    ctx->r2 = S32(0X8018 << 16);
    // 0x801986B4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x801986B8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801986BC: lhu         $t2, -0x7732($v0)
    ctx->r10 = MEM_HU(ctx->r2, -0X7732);
    // 0x801986C0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801986C4: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801986C8: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801986CC: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801986D0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801986D4: sll         $t9, $t2, 29
    ctx->r25 = S32(ctx->r10 << 29);
    // 0x801986D8: sll         $t4, $t2, 30
    ctx->r12 = S32(ctx->r10 << 30);
    // 0x801986DC: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x801986E0: srl         $t5, $t4, 31
    ctx->r13 = S32(U32(ctx->r12) >> 31);
    // 0x801986E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801986E8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x801986EC: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x801986F0: lui         $fp, 0x801B
    ctx->r30 = S32(0X801B << 16);
    // 0x801986F4: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x801986F8: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x801986FC: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x80198700: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80198704: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80198708: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8019870C: sw          $t1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r9;
    // 0x80198710: sw          $t3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r11;
    // 0x80198714: sw          $t6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r14;
    // 0x80198718: addiu       $s5, $s5, -0xF18
    ctx->r21 = ADD32(ctx->r21, -0XF18);
    // 0x8019871C: addiu       $s6, $s6, -0xF30
    ctx->r22 = ADD32(ctx->r22, -0XF30);
    // 0x80198720: addiu       $s7, $s7, -0xF24
    ctx->r23 = ADD32(ctx->r23, -0XF24);
    // 0x80198724: addiu       $fp, $fp, -0xF3C
    ctx->r30 = ADD32(ctx->r30, -0XF3C);
    // 0x80198728: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x8019872C: addiu       $s3, $sp, 0x9C
    ctx->r19 = ADD32(ctx->r29, 0X9C);
    // 0x80198730: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80198734: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
L_80198738:
    // 0x80198738: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8019873C: beql        $t7, $zero, L_801987D8
    if (ctx->r15 == 0) {
        // 0x80198740: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801987D8;
    }
    goto skip_2;
    // 0x80198740: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_2:
    // 0x80198744: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80198748: addu        $t9, $s5, $s0
    ctx->r25 = ADD32(ctx->r21, ctx->r16);
    // 0x8019874C: addu        $t3, $s6, $s0
    ctx->r11 = ADD32(ctx->r22, ctx->r16);
    // 0x80198750: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80198754: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80198758: sw          $s4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r20;
    // 0x8019875C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80198760: addu        $t8, $s7, $s0
    ctx->r24 = ADD32(ctx->r23, ctx->r16);
    // 0x80198764: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80198768: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8019876C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80198770: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80198774: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x80198778: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x8019877C: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x80198780: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x80198784: or          $t3, $t7, $t1
    ctx->r11 = ctx->r15 | ctx->r9;
    // 0x80198788: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x8019878C: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x80198790: add.s       $f4, $f30, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f30.fl + ctx->f26.fl;
    // 0x80198794: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80198798: addu        $t6, $fp, $s0
    ctx->r14 = ADD32(ctx->r30, ctx->r16);
    // 0x8019879C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801987A0: add.s       $f6, $f4, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x801987A4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801987A8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x801987AC: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x801987B0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801987B4: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x801987B8: sub.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x801987BC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801987C0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801987C4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801987C8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x801987CC: jal         0x800A1200
    // 0x801987D0: nop

    Graphics_DisplaySmallText(rdram, ctx);
        goto after_1;
    // 0x801987D0: nop

    after_1:
    // 0x801987D4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_801987D8:
    // 0x801987D8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801987DC: bne         $s1, $s3, L_80198738
    if (ctx->r17 != ctx->r19) {
        // 0x801987E0: add.s       $f22, $f22, $f24
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f24.fl;
            goto L_80198738;
    }
    // 0x801987E0: add.s       $f22, $f22, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f24.fl;
    // 0x801987E4: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
L_801987E8:
    // 0x801987E8: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801987EC: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801987F0: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801987F4: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x801987F8: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x801987FC: ldc1        $f30, 0x48($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X48);
    // 0x80198800: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x80198804: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x80198808: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x8019880C: lw          $s3, 0x5C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X5C);
    // 0x80198810: lw          $s4, 0x60($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X60);
    // 0x80198814: lw          $s5, 0x64($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X64);
    // 0x80198818: lw          $s6, 0x68($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X68);
    // 0x8019881C: lw          $s7, 0x6C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X6C);
    // 0x80198820: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x80198824: jr          $ra
    // 0x80198828: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80198828: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Map_801A2674(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A2674: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801A2678: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A267C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A2680: jal         0x801A48C0
    // 0x801A2684: lwc1        $f12, -0x159C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X159C);
    Map_801A48C0(rdram, ctx);
        goto after_0;
    // 0x801A2684: lwc1        $f12, -0x159C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X159C);
    after_0:
    // 0x801A2688: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A268C: jal         0x801A4A38
    // 0x801A2690: lwc1        $f12, -0x159C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X159C);
    Map_801A4A38(rdram, ctx);
        goto after_1;
    // 0x801A2690: lwc1        $f12, -0x159C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X159C);
    after_1:
    // 0x801A2694: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A2698: addiu       $v0, $v0, -0x159C
    ctx->r2 = ADD32(ctx->r2, -0X159C);
    // 0x801A269C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A26A0: lwc1        $f6, 0x76B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X76B8);
    // 0x801A26A4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A26A8: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A26AC: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A26B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A26B4: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x801A26B8: addiu       $a1, $a1, -0xB60
    ctx->r5 = ADD32(ctx->r5, -0XB60);
    // 0x801A26BC: addiu       $v1, $v1, -0x2700
    ctx->r3 = ADD32(ctx->r3, -0X2700);
    // 0x801A26C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A26C4: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x801A26C8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x801A26CC: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801A26D0: lw          $t0, -0x26AC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X26AC);
L_801A26D4:
    // 0x801A26D4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801A26D8: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x801A26DC: bgez        $t7, L_801A26E8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801A26E0: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_801A26E8;
    }
    // 0x801A26E0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801A26E4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801A26E8:
    // 0x801A26E8: beql        $a0, $t0, L_801A2714
    if (ctx->r4 == ctx->r8) {
        // 0x801A26EC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801A2714;
    }
    goto skip_0;
    // 0x801A26EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x801A26F0: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A26F4: mflo        $t9
    ctx->r25 = lo;
    // 0x801A26F8: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x801A26FC: lw          $t1, 0x24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X24);
    // 0x801A2700: addiu       $t2, $t1, -0x10
    ctx->r10 = ADD32(ctx->r9, -0X10);
    // 0x801A2704: bgez        $t2, L_801A2710
    if (SIGNED(ctx->r10) >= 0) {
        // 0x801A2708: sw          $t2, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r10;
            goto L_801A2710;
    }
    // 0x801A2708: sw          $t2, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r10;
    // 0x801A270C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
L_801A2710:
    // 0x801A2710: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_801A2714:
    // 0x801A2714: slti        $at, $a0, 0xF
    ctx->r1 = SIGNED(ctx->r4) < 0XF ? 1 : 0;
    // 0x801A2718: bne         $at, $zero, L_801A26D4
    if (ctx->r1 != 0) {
        // 0x801A271C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801A26D4;
    }
    // 0x801A271C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801A2720: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x801A2724: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x801A2728: addiu       $a2, $a2, -0x2E8
    ctx->r6 = ADD32(ctx->r6, -0X2E8);
    // 0x801A272C: addiu       $v1, $v1, 0x7BD8
    ctx->r3 = ADD32(ctx->r3, 0X7BD8);
    // 0x801A2730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801A2734: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
L_801A2738:
    // 0x801A2738: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x801A273C: beql        $t4, $zero, L_801A2768
    if (ctx->r12 == 0) {
        // 0x801A2740: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_801A2768;
    }
    goto skip_1;
    // 0x801A2740: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x801A2744: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A2748: mflo        $t5
    ctx->r13 = lo;
    // 0x801A274C: addu        $v0, $a2, $t5
    ctx->r2 = ADD32(ctx->r6, ctx->r13);
    // 0x801A2750: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x801A2754: addiu       $t7, $t6, -0x10
    ctx->r15 = ADD32(ctx->r14, -0X10);
    // 0x801A2758: bgez        $t7, L_801A2764
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801A275C: sw          $t7, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r15;
            goto L_801A2764;
    }
    // 0x801A275C: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x801A2760: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
L_801A2764:
    // 0x801A2764: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_801A2768:
    // 0x801A2768: bne         $a0, $a1, L_801A2738
    if (ctx->r4 != ctx->r5) {
        // 0x801A276C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801A2738;
    }
    // 0x801A276C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801A2770: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A2774: bne         $t0, $at, L_801A27A8
    if (ctx->r8 != ctx->r1) {
        // 0x801A2778: lui         $a0, 0x801B
        ctx->r4 = S32(0X801B << 16);
            goto L_801A27A8;
    }
    // 0x801A2778: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801A277C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A2780: lwc1        $f10, 0x76BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X76BC);
    // 0x801A2784: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A2788: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A278C: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x801A2790: lui         $a1, 0x41A0
    ctx->r5 = S32(0X41A0 << 16);
    // 0x801A2794: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A2798: jal         0x8009BC2C
    // 0x801A279C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A279C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801A27A0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A27A4: lw          $t0, -0x26AC($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X26AC);
L_801A27A8:
    // 0x801A27A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A27AC: bne         $t0, $at, L_801A27D8
    if (ctx->r8 != ctx->r1) {
        // 0x801A27B0: lui         $a0, 0x801B
        ctx->r4 = S32(0X801B << 16);
            goto L_801A27D8;
    }
    // 0x801A27B0: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x801A27B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A27B8: lwc1        $f16, 0x76C0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X76C0);
    // 0x801A27BC: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x801A27C0: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A27C4: addiu       $a0, $a0, 0x0
    ctx->r4 = ADD32(ctx->r4, 0X0);
    // 0x801A27C8: lui         $a1, 0x4170
    ctx->r5 = S32(0X4170 << 16);
    // 0x801A27CC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A27D0: jal         0x8009BC2C
    // 0x801A27D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_3;
    // 0x801A27D4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
L_801A27D8:
    // 0x801A27D8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A27DC: addiu       $v0, $v0, -0x2690
    ctx->r2 = ADD32(ctx->r2, -0X2690);
    // 0x801A27E0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801A27E4: lui         $a0, 0x102D
    ctx->r4 = S32(0X102D << 16);
    // 0x801A27E8: addiu       $t1, $t9, -0x10
    ctx->r9 = ADD32(ctx->r25, -0X10);
    // 0x801A27EC: bgez        $t1, L_801A27F8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x801A27F0: sw          $t1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r9;
            goto L_801A27F8;
    }
    // 0x801A27F0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801A27F4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_801A27F8:
    // 0x801A27F8: jal         0x800182F4
    // 0x801A27FC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_4;
    // 0x801A27FC: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_4:
    // 0x801A2800: lui         $a0, 0x112D
    ctx->r4 = S32(0X112D << 16);
    // 0x801A2804: jal         0x800182F4
    // 0x801A2808: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_5;
    // 0x801A2808: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_5:
    // 0x801A280C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A2810: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801A2814: jr          $ra
    // 0x801A2818: nop

    return;
    // 0x801A2818: nop

;}
RECOMP_FUNC void Option_VersusStage_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80199FA8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80199FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80199FB0: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80199FB4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80199FB8: addiu       $v0, $v0, -0x6C24
    ctx->r2 = ADD32(ctx->r2, -0X6C24);
    // 0x80199FBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80199FC0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80199FC4: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x80199FC8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199FCC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80199FD0: lw          $t6, 0x78A4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78A4);
    // 0x80199FD4: sw          $zero, -0x6CC4($at)
    MEM_W(-0X6CC4, ctx->r1) = 0;
    // 0x80199FD8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199FDC: swc1        $f2, -0x6E18($at)
    MEM_W(-0X6E18, ctx->r1) = ctx->f2.u32l;
    // 0x80199FE0: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x80199FE4: lw          $t8, 0x1A28($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1A28);
    // 0x80199FE8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80199FEC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80199FF0: sw          $t7, -0x6C2C($at)
    MEM_W(-0X6C2C, ctx->r1) = ctx->r15;
    // 0x80199FF4: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80199FF8: lw          $t9, -0x6CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6CC0);
    // 0x80199FFC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A000: sw          $t8, -0x6C28($at)
    MEM_W(-0X6C28, ctx->r1) = ctx->r24;
    // 0x8019A004: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019A008: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019A00C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8019A010: sw          $t9, 0x78C8($at)
    MEM_W(0X78C8, ctx->r1) = ctx->r25;
    // 0x8019A014: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A018: swc1        $f0, -0x6CA8($at)
    MEM_W(-0X6CA8, ctx->r1) = ctx->f0.u32l;
    // 0x8019A01C: swc1        $f0, -0x6CA4($at)
    MEM_W(-0X6CA4, ctx->r1) = ctx->f0.u32l;
    // 0x8019A020: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A024: swc1        $f0, -0x6CA0($at)
    MEM_W(-0X6CA0, ctx->r1) = ctx->f0.u32l;
    // 0x8019A028: swc1        $f0, -0x6C9C($at)
    MEM_W(-0X6C9C, ctx->r1) = ctx->f0.u32l;
    // 0x8019A02C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A030: sw          $zero, -0x6C94($at)
    MEM_W(-0X6C94, ctx->r1) = 0;
    // 0x8019A034: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A038: sw          $zero, -0x6C8C($at)
    MEM_W(-0X6C8C, ctx->r1) = 0;
    // 0x8019A03C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A040: sw          $zero, -0x6C84($at)
    MEM_W(-0X6C84, ctx->r1) = 0;
    // 0x8019A044: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A048: swc1        $f0, -0x6E14($at)
    MEM_W(-0X6E14, ctx->r1) = ctx->f0.u32l;
    // 0x8019A04C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A050: sw          $zero, -0x6E10($at)
    MEM_W(-0X6E10, ctx->r1) = 0;
    // 0x8019A054: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A058: swc1        $f2, -0x6C98($at)
    MEM_W(-0X6C98, ctx->r1) = ctx->f2.u32l;
    // 0x8019A05C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A060: swc1        $f2, -0x6C90($at)
    MEM_W(-0X6C90, ctx->r1) = ctx->f2.u32l;
    // 0x8019A064: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A068: jal         0x8019A080
    // 0x8019A06C: swc1        $f2, -0x6C88($at)
    MEM_W(-0X6C88, ctx->r1) = ctx->f2.u32l;
    Option_8019A080(rdram, ctx);
        goto after_0;
    // 0x8019A06C: swc1        $f2, -0x6C88($at)
    MEM_W(-0X6C88, ctx->r1) = ctx->f2.u32l;
    after_0:
    // 0x8019A070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019A074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019A078: jr          $ra
    // 0x8019A07C: nop

    return;
    // 0x8019A07C: nop

;}
RECOMP_FUNC void Option_VsStageSelect_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019AFFC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8019B000: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019B004: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019B008: lw          $v0, -0x6ED4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6ED4);
    // 0x8019B00C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019B010: bnel        $v0, $zero, L_8019B028
    if (ctx->r2 != 0) {
        // 0x8019B014: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8019B028;
    }
    goto skip_0;
    // 0x8019B014: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8019B018: lw          $t6, -0x6C30($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C30);
    // 0x8019B01C: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8019B020: beq         $t6, $at, L_8019B03C
    if (ctx->r14 == ctx->r1) {
        // 0x8019B024: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8019B03C;
    }
    // 0x8019B024: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8019B028:
    // 0x8019B028: bne         $v0, $at, L_8019B0C0
    if (ctx->r2 != ctx->r1) {
        // 0x8019B02C: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_8019B0C0;
    }
    // 0x8019B02C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019B030: lw          $t7, -0x6C30($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C30);
    // 0x8019B034: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8019B038: beq         $t7, $at, L_8019B0C0
    if (ctx->r15 == ctx->r1) {
        // 0x8019B03C: lui         $at, 0x42BC
        ctx->r1 = S32(0X42BC << 16);
            goto L_8019B0C0;
    }
L_8019B03C:
    // 0x8019B03C: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x8019B040: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B044: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B048: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B04C: swc1        $f4, -0x6C40($at)
    MEM_W(-0X6C40, ctx->r1) = ctx->f4.u32l;
    // 0x8019B050: lui         $at, 0x42B0
    ctx->r1 = S32(0X42B0 << 16);
    // 0x8019B054: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019B058: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B05C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B060: swc1        $f6, -0x6C38($at)
    MEM_W(-0X6C38, ctx->r1) = ctx->f6.u32l;
    // 0x8019B064: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x8019B068: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019B06C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B070: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8019B074: jal         0x800B8DD0
    // 0x8019B078: swc1        $f8, -0x6C34($at)
    MEM_W(-0X6C34, ctx->r1) = ctx->f8.u32l;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019B078: swc1        $f8, -0x6C34($at)
    MEM_W(-0X6C34, ctx->r1) = ctx->f8.u32l;
    after_0:
    // 0x8019B07C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B080: lwc1        $f12, -0x6C40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6C40);
    // 0x8019B084: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B088: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8019B08C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8019B090: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8019B094: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8019B098: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019B09C: lw          $a2, -0x6C34($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6C34);
    // 0x8019B0A0: lwc1        $f14, -0x6C38($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X6C38);
    // 0x8019B0A4: jal         0x8019B6D8
    // 0x8019B0A8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Option_VsSelectionArrows_Draw(rdram, ctx);
        goto after_1;
    // 0x8019B0A8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_1:
    // 0x8019B0AC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019B0B0: jal         0x8019C824
    // 0x8019B0B4: addiu       $a0, $a0, -0x6C90
    ctx->r4 = ADD32(ctx->r4, -0X6C90);
    Option_Color_FlashRed(rdram, ctx);
        goto after_2;
    // 0x8019B0B4: addiu       $a0, $a0, -0x6C90
    ctx->r4 = ADD32(ctx->r4, -0X6C90);
    after_2:
    // 0x8019B0B8: b           L_8019B0D0
    // 0x8019B0BC: nop

        goto L_8019B0D0;
    // 0x8019B0BC: nop

L_8019B0C0:
    // 0x8019B0C0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019B0C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8019B0C8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B0CC: swc1        $f10, -0x6C90($at)
    MEM_W(-0X6C90, ctx->r1) = ctx->f10.u32l;
L_8019B0D0:
    // 0x8019B0D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B0D4: lwc1        $f16, -0x6C90($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X6C90);
    // 0x8019B0D8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019B0DC: addiu       $a0, $a0, -0x6C8C
    ctx->r4 = ADD32(ctx->r4, -0X6C8C);
    // 0x8019B0E0: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019B0E4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8019B0E8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8019B0EC: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019B0F0: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x8019B0F4: beq         $v1, $zero, L_8019B118
    if (ctx->r3 == 0) {
        // 0x8019B0F8: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_8019B118;
    }
    // 0x8019B0F8: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x8019B0FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8019B100: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8019B104: bne         $t3, $zero, L_8019B118
    if (ctx->r11 != 0) {
        // 0x8019B108: sw          $t3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r11;
            goto L_8019B118;
    }
    // 0x8019B108: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8019B10C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019B110: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B114: sw          $t5, -0x6E10($at)
    MEM_W(-0X6E10, ctx->r1) = ctx->r13;
L_8019B118:
    // 0x8019B118: lw          $t6, 0x7DB0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7DB0);
    // 0x8019B11C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B120: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B124: and         $t7, $t6, $v0
    ctx->r15 = ctx->r14 & ctx->r2;
    // 0x8019B128: beq         $t7, $zero, L_8019B1BC
    if (ctx->r15 == 0) {
        // 0x8019B12C: addiu       $a1, $zero, 0x53
        ctx->r5 = ADD32(0, 0X53);
            goto L_8019B1BC;
    }
    // 0x8019B12C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8019B130: jal         0x800B8DD0
    // 0x8019B134: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x8019B134: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_3:
    // 0x8019B138: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B13C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B140: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8019B144: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8019B148: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x8019B14C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8019B150: andi        $t0, $t1, 0xFF
    ctx->r8 = ctx->r9 & 0XFF;
    // 0x8019B154: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8019B158: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x8019B15C: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8019B160: sll         $t2, $t0, 16
    ctx->r10 = S32(ctx->r8 << 16);
    // 0x8019B164: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x8019B168: sll         $t4, $t0, 8
    ctx->r12 = S32(ctx->r8 << 8);
    // 0x8019B16C: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8019B170: ori         $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 | 0XFF;
    // 0x8019B174: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8019B178: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8019B17C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8019B180: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B184: lwc1        $f4, -0xD60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XD60);
    // 0x8019B188: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B18C: lwc1        $f6, -0xD5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XD5C);
    // 0x8019B190: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B194: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x8019B198: addiu       $a1, $a1, 0x1270
    ctx->r5 = ADD32(ctx->r5, 0X1270);
    // 0x8019B19C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B1A0: addiu       $a2, $zero, 0x70
    ctx->r6 = ADD32(0, 0X70);
    // 0x8019B1A4: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8019B1A8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019B1AC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019B1B0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019B1B4: jal         0x8009D994
    // 0x8019B1B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_4;
    // 0x8019B1B8: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_4:
L_8019B1BC:
    // 0x8019B1BC: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019B1C0: lw          $t7, -0x6C30($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6C30);
    // 0x8019B1C4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x8019B1C8: bne         $t7, $at, L_8019B1E0
    if (ctx->r15 != ctx->r1) {
        // 0x8019B1CC: nop
    
            goto L_8019B1E0;
    }
    // 0x8019B1CC: nop

    // 0x8019B1D0: jal         0x8019B1F8
    // 0x8019B1D4: nop

    Option_VsTimeTrialStageSelect_Draw(rdram, ctx);
        goto after_5;
    // 0x8019B1D4: nop

    after_5:
    // 0x8019B1D8: b           L_8019B1EC
    // 0x8019B1DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8019B1EC;
    // 0x8019B1DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019B1E0:
    // 0x8019B1E0: jal         0x8019B3DC
    // 0x8019B1E4: nop

    Option_VsStageSelect2_Draw(rdram, ctx);
        goto after_6;
    // 0x8019B1E4: nop

    after_6:
    // 0x8019B1E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019B1EC:
    // 0x8019B1EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8019B1F0: jr          $ra
    // 0x8019B1F4: nop

    return;
    // 0x8019B1F4: nop

;}
RECOMP_FUNC void Map_Level_CamSetup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F97C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019F980: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019F984: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8019F988: jal         0x801A25C8
    // 0x8019F98C: lw          $a0, -0x26AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26AC);
    Map_GetPlanetCamZDist(rdram, ctx);
        goto after_0;
    // 0x8019F98C: lw          $a0, -0x26AC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26AC);
    after_0:
    // 0x8019F990: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019F994: addiu       $v1, $v1, -0x15AC
    ctx->r3 = ADD32(ctx->r3, -0X15AC);
    // 0x8019F998: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8019F99C: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x8019F9A0: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x8019F9A4: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x8019F9A8: addiu       $t8, $t8, -0xB60
    ctx->r24 = ADD32(ctx->r24, -0XB60);
    // 0x8019F9AC: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8019F9B0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8019F9B4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8019F9B8: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8019F9BC: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8019F9C0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8019F9C4: addiu       $a0, $a0, -0x2600
    ctx->r4 = ADD32(ctx->r4, -0X2600);
    // 0x8019F9C8: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8019F9CC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8019F9D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F9D4: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8019F9D8: swc1        $f6, -0x260C($at)
    MEM_W(-0X260C, ctx->r1) = ctx->f6.u32l;
    // 0x8019F9DC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8019F9E0: addiu       $a1, $a1, -0x25FC
    ctx->r5 = ADD32(ctx->r5, -0X25FC);
    // 0x8019F9E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F9E8: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x8019F9EC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8019F9F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019F9F4: swc1        $f10, -0x2608($at)
    MEM_W(-0X2608, ctx->r1) = ctx->f10.u32l;
    // 0x8019F9F8: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8019F9FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019FA00: swc1        $f2, -0x25F8($at)
    MEM_W(-0X25F8, ctx->r1) = ctx->f2.u32l;
    // 0x8019FA04: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019FA08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019FA0C: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x8019FA10: swc1        $f18, -0x2604($at)
    MEM_W(-0X2604, ctx->r1) = ctx->f18.u32l;
    // 0x8019FA14: jr          $ra
    // 0x8019FA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8019FA18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void Map_Cursor_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A8F40: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A8F44: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801A8F48: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801A8F4C: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A8F50: lw          $t6, -0x2684($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2684);
    // 0x801A8F54: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A8F58: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A8F5C: beq         $t6, $zero, L_801A9138
    if (ctx->r14 == 0) {
        // 0x801A8F60: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_801A9138;
    }
    // 0x801A8F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801A8F64: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801A8F68: addiu       $t8, $zero, 0x50
    ctx->r24 = ADD32(0, 0X50);
    // 0x801A8F6C: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x801A8F70: addiu       $t0, $zero, 0x32
    ctx->r8 = ADD32(0, 0X32);
    // 0x801A8F74: addiu       $t1, $zero, 0x32
    ctx->r9 = ADD32(0, 0X32);
    // 0x801A8F78: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x801A8F7C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x801A8F80: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x801A8F84: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801A8F88: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x801A8F8C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x801A8F90: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A8F94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A8F98: jal         0x8000372C
    // 0x801A8F9C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    Lights_SetOneLight(rdram, ctx);
        goto after_0;
    // 0x801A8F9C: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_0:
    // 0x801A8FA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A8FA4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A8FA8: jal         0x800B8DD0
    // 0x801A8FAC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A8FAC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_1:
    // 0x801A8FB0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A8FB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A8FB8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A8FBC: addiu       $s0, $s0, -0x1550
    ctx->r16 = ADD32(ctx->r16, -0X1550);
    // 0x801A8FC0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A8FC4: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x801A8FC8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801A8FCC: addiu       $a0, $a0, -0x1558
    ctx->r4 = ADD32(ctx->r4, -0X1558);
    // 0x801A8FD0: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801A8FD4: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A8FD8: jal         0x8009BC2C
    // 0x801A8FDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A8FDC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801A8FE0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801A8FE4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801A8FE8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A8FEC: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x801A8FF0: nop

    // 0x801A8FF4: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x801A8FF8: nop

    // 0x801A8FFC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801A9000: c.eq.s      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.fl == ctx->f16.fl;
    // 0x801A9004: nop

    // 0x801A9008: bc1f        L_801A903C
    if (!c1cs) {
        // 0x801A900C: nop
    
            goto L_801A903C;
    }
    // 0x801A900C: nop

    // 0x801A9010: lwc1        $f0, -0x1554($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1554);
    // 0x801A9014: lwc1        $f18, 0x0($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A9018: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x801A901C: c.eq.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl == ctx->f18.fl;
    // 0x801A9020: nop

    // 0x801A9024: bc1f        L_801A903C
    if (!c1cs) {
        // 0x801A9028: nop
    
            goto L_801A903C;
    }
    // 0x801A9028: nop

    // 0x801A902C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A9030: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A9034: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801A9038: swc1        $f8, -0x1558($at)
    MEM_W(-0X1558, ctx->r1) = ctx->f8.u32l;
L_801A903C:
    // 0x801A903C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A9040: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801A9044: jal         0x80005708
    // 0x801A9048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_3;
    // 0x801A9048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801A904C: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A9050: lw          $t5, -0x26AC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26AC);
    // 0x801A9054: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A9058: addiu       $t7, $t7, -0x25A0
    ctx->r15 = ADD32(ctx->r15, -0X25A0);
    // 0x801A905C: sll         $t6, $t5, 6
    ctx->r14 = S32(ctx->r13 << 6);
    // 0x801A9060: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x801A9064: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A9068: jal         0x80005754
    // 0x801A906C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_4;
    // 0x801A906C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x801A9070: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A9074: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A9078: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A907C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A9080: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A9084: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A9088: lw          $a2, -0x1558($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X1558);
    // 0x801A908C: jal         0x80005B00
    // 0x801A9090: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x801A9090: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_5:
    // 0x801A9094: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A9098: lwc1        $f10, 0x79D0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79D0);
    // 0x801A909C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A90A0: lwc1        $f6, 0x6A7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A7C);
    // 0x801A90A4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A90A8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A90AC: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x801A90B0: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A90B4: jal         0x80005E90
    // 0x801A90B8: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x801A90B8: nop

    after_6:
    // 0x801A90BC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A90C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A90C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801A90C8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801A90CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A90D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A90D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A90D8: jal         0x80005C34
    // 0x801A90DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x801A90DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_7:
    // 0x801A90E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A90E4: jal         0x80006EB8
    // 0x801A90E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x801A90E8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_8:
    // 0x801A90EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801A90F0: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x801A90F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A90F8: lui         $t2, 0x602
    ctx->r10 = S32(0X602 << 16);
    // 0x801A90FC: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x801A9100: sw          $t0, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r8;
    // 0x801A9104: addiu       $t2, $t2, -0x2310
    ctx->r10 = ADD32(ctx->r10, -0X2310);
    // 0x801A9108: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x801A910C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801A9110: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x801A9114: jal         0x80005740
    // 0x801A9118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_9;
    // 0x801A9118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801A911C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A9120: lwc1        $f18, 0x6A7C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6A7C);
    // 0x801A9124: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x801A9128: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A912C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A9130: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A9134: swc1        $f8, 0x6A7C($at)
    MEM_W(0X6A7C, ctx->r1) = ctx->f8.u32l;
L_801A9138:
    // 0x801A9138: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801A913C: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801A9140: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801A9144: jr          $ra
    // 0x801A9148: nop

    return;
    // 0x801A9148: nop

;}
RECOMP_FUNC void Option_VersusMenu_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019978C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80199790: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80199794: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80199798: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8019979C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801997A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801997A4: jal         0x8019B8C8
    // 0x801997A8: nop

    Option_VsMenuCard_Draw(rdram, ctx);
        goto after_0;
    // 0x801997A8: nop

    after_0:
    // 0x801997AC: jal         0x80199EA8
    // 0x801997B0: nop

    Option_VS_N64Console_Draw(rdram, ctx);
        goto after_1;
    // 0x801997B0: nop

    after_1:
    // 0x801997B4: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x801997B8: addiu       $s1, $s1, -0x2750
    ctx->r17 = ADD32(ctx->r17, -0X2750);
    // 0x801997BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801997C0: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x801997C4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_801997C8:
    // 0x801997C8: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x801997CC: bnel        $s2, $t6, L_801997E0
    if (ctx->r18 != ctx->r14) {
        // 0x801997D0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801997E0;
    }
    goto skip_0;
    // 0x801997D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801997D4: jal         0x80199820
    // 0x801997D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Option_VS_HandicapSet_Draw(rdram, ctx);
        goto after_2;
    // 0x801997D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801997DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801997E0:
    // 0x801997E0: bne         $s0, $s3, L_801997C8
    if (ctx->r16 != ctx->r19) {
        // 0x801997E4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_801997C8;
    }
    // 0x801997E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801997E8: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x801997EC: lbu         $t7, -0x6C3C($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X6C3C);
    // 0x801997F0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x801997F4: bnel        $t7, $at, L_80199808
    if (ctx->r15 != ctx->r1) {
        // 0x801997F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80199808;
    }
    goto skip_1;
    // 0x801997F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801997FC: jal         0x8019B5AC
    // 0x80199800: nop

    Option_VsOKConfirm_Draw(rdram, ctx);
        goto after_3;
    // 0x80199800: nop

    after_3:
    // 0x80199804: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80199808:
    // 0x80199808: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8019980C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80199810: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80199814: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80199818: jr          $ra
    // 0x8019981C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8019981C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Title_UpdateEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801877F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801877F4: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801877F8: addiu       $v1, $v1, -0x7D58
    ctx->r3 = ADD32(ctx->r3, -0X7D58);
    // 0x801877FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80187800: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80187804: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80187808: blez        $v0, L_80187814
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8018780C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80187814;
    }
    // 0x8018780C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80187810: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80187814:
    // 0x80187814: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80187818: addiu       $v1, $v1, -0x7D54
    ctx->r3 = ADD32(ctx->r3, -0X7D54);
    // 0x8018781C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80187820: blez        $v0, L_8018782C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80187824: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8018782C;
    }
    // 0x80187824: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80187828: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_8018782C:
    // 0x8018782C: lw          $t8, -0x7D3C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7D3C);
    // 0x80187830: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80187834: beq         $at, $zero, L_801878C0
    if (ctx->r1 == 0) {
        // 0x80187838: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_801878C0;
    }
    // 0x80187838: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018783C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80187840: addu        $at, $at, $t8
    gpr jr_addend_80187848 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80187844: lw          $t8, 0x6D88($at)
    ctx->r24 = ADD32(ctx->r1, 0X6D88);
    // 0x80187848: jr          $t8
    // 0x8018784C: nop

    switch (jr_addend_80187848 >> 2) {
        case 0: goto L_80187860; break;
        case 1: goto L_80187878; break;
        case 2: goto L_80187888; break;
        case 3: goto L_80187898; break;
        case 4: goto L_801878A8; break;
        case 5: goto L_801878B8; break;
        case 6: goto L_801878C0; break;
        case 7: goto L_80187850; break;
        default: switch_error(__func__, 0x80187848, 0x801B6D88);
    }
    // 0x8018784C: nop

L_80187850:
    // 0x80187850: jal         0x80187B00
    // 0x80187854: nop

    Title_Ranking_Update(rdram, ctx);
        goto after_0;
    // 0x80187854: nop

    after_0:
    // 0x80187858: b           L_801878C0
    // 0x8018785C: nop

        goto L_801878C0;
    // 0x8018785C: nop

L_80187860:
    // 0x80187860: jal         0x801888E8
    // 0x80187864: nop

    Title_Screen_Update(rdram, ctx);
        goto after_1;
    // 0x80187864: nop

    after_1:
    // 0x80187868: jal         0x8019111C
    // 0x8018786C: nop

    Title_Screen_Input(rdram, ctx);
        goto after_2;
    // 0x8018786C: nop

    after_2:
    // 0x80187870: b           L_801878C0
    // 0x80187874: nop

        goto L_801878C0;
    // 0x80187874: nop

L_80187878:
    // 0x80187878: jal         0x8018994C
    // 0x8018787C: nop

    Title_CsGreatFoxTraveling_Update(rdram, ctx);
        goto after_3;
    // 0x8018787C: nop

    after_3:
    // 0x80187880: b           L_801878C0
    // 0x80187884: nop

        goto L_801878C0;
    // 0x80187884: nop

L_80187888:
    // 0x80187888: jal         0x8018A644
    // 0x8018788C: nop

    Title_CsTeamRunning_Update(rdram, ctx);
        goto after_4;
    // 0x8018788C: nop

    after_4:
    // 0x80187890: b           L_801878C0
    // 0x80187894: nop

        goto L_801878C0;
    // 0x80187894: nop

L_80187898:
    // 0x80187898: jal         0x8018ACEC
    // 0x8018789C: nop

    Title_CsGreatFoxCloseUp_Update(rdram, ctx);
        goto after_5;
    // 0x8018789C: nop

    after_5:
    // 0x801878A0: b           L_801878C0
    // 0x801878A4: nop

        goto L_801878C0;
    // 0x801878A4: nop

L_801878A8:
    // 0x801878A8: jal         0x8018B5C4
    // 0x801878AC: nop

    Title_CsTakeOff_Update(rdram, ctx);
        goto after_6;
    // 0x801878AC: nop

    after_6:
    // 0x801878B0: b           L_801878C0
    // 0x801878B4: nop

        goto L_801878C0;
    // 0x801878B4: nop

L_801878B8:
    // 0x801878B8: jal         0x8018C644
    // 0x801878BC: nop

    Title_CsTakeOffSpace_Update(rdram, ctx);
        goto after_7;
    // 0x801878BC: nop

    after_7:
L_801878C0:
    // 0x801878C0: jal         0x80190E64
    // 0x801878C4: nop

    Title_NextState_Check(rdram, ctx);
        goto after_8;
    // 0x801878C4: nop

    after_8:
    // 0x801878C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801878CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801878D0: jr          $ra
    // 0x801878D4: nop

    return;
    // 0x801878D4: nop

;}
RECOMP_FUNC void Map_801A9FD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9FD4: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x801A9FD8: sw          $ra, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r31;
    // 0x801A9FDC: sw          $s3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r19;
    // 0x801A9FE0: sw          $s2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r18;
    // 0x801A9FE4: sw          $s1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r17;
    // 0x801A9FE8: sw          $s0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r16;
    // 0x801A9FEC: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x801A9FF0: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x801A9FF4: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x801A9FF8: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x801A9FFC: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x801AA000: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x801AA004: beq         $a0, $zero, L_801AA018
    if (ctx->r4 == 0) {
        // 0x801AA008: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_801AA018;
    }
    // 0x801AA008: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801AA00C: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x801AA010: b           L_801AA050
    // 0x801AA014: lw          $s3, 0x7B48($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X7B48);
        goto L_801AA050;
    // 0x801AA014: lw          $s3, 0x7B48($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X7B48);
L_801AA018:
    // 0x801AA018: lhu         $v0, 0x1A34($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A34);
    // 0x801AA01C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801AA020: lui         $s3, 0x8017
    ctx->r19 = S32(0X8017 << 16);
    // 0x801AA024: beq         $v0, $at, L_801AA034
    if (ctx->r2 == ctx->r1) {
        // 0x801AA028: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_801AA034;
    }
    // 0x801AA028: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801AA02C: bnel        $v0, $at, L_801AA040
    if (ctx->r2 != ctx->r1) {
        // 0x801AA030: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801AA040;
    }
    goto skip_0;
    // 0x801AA030: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_0:
L_801AA034:
    // 0x801AA034: lw          $s3, 0x7B48($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X7B48);
    // 0x801AA038: sw          $s3, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r19;
    // 0x801AA03C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_801AA040:
    // 0x801AA040: bne         $v0, $at, L_801AA050
    if (ctx->r2 != ctx->r1) {
        // 0x801AA044: lw          $s3, 0x98($sp)
        ctx->r19 = MEM_W(ctx->r29, 0X98);
            goto L_801AA050;
    }
    // 0x801AA044: lw          $s3, 0x98($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X98);
    // 0x801AA048: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801AA04C: lw          $s3, -0x2654($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X2654);
L_801AA050:
    // 0x801AA050: jal         0x801AA1CC
    // 0x801AA054: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    Map_PathLineBox_Draw(rdram, ctx);
        goto after_0;
    // 0x801AA054: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x801AA058: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801AA05C: lhu         $v0, 0x1A34($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A34);
    // 0x801AA060: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801AA064: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AA068: beq         $v0, $at, L_801AA078
    if (ctx->r2 == ctx->r1) {
        // 0x801AA06C: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_801AA078;
    }
    // 0x801AA06C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801AA070: bnel        $v0, $at, L_801AA080
    if (ctx->r2 != ctx->r1) {
        // 0x801AA074: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_801AA080;
    }
    goto skip_1;
    // 0x801AA074: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    skip_1:
L_801AA078:
    // 0x801AA078: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
    // 0x801AA07C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_801AA080:
    // 0x801AA080: bne         $v0, $at, L_801AA08C
    if (ctx->r2 != ctx->r1) {
        // 0x801AA084: nop
    
            goto L_801AA08C;
    }
    // 0x801AA084: nop

    // 0x801AA088: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_801AA08C:
    // 0x801AA08C: jal         0x80005708
    // 0x801AA090: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801AA090: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801AA094: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x801AA098: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AA09C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AA0A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AA0A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AA0A8: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x801AA0AC: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x801AA0B0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801AA0B4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AA0B8: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801AA0BC: swc1        $f24, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f24.u32l;
    // 0x801AA0C0: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x801AA0C4: swc1        $f24, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f24.u32l;
    // 0x801AA0C8: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x801AA0CC: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x801AA0D0: jal         0x80006E3C
    // 0x801AA0D4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_2;
    // 0x801AA0D4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x801AA0D8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801AA0DC: jal         0x80006EB8
    // 0x801AA0E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x801AA0E0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_3:
    // 0x801AA0E4: lui         $at, 0xC226
    ctx->r1 = S32(0XC226 << 16);
    // 0x801AA0E8: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801AA0EC: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x801AA0F0: blez        $s3, L_801AA18C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x801AA0F4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801AA18C;
    }
    // 0x801AA0F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801AA0F8: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801AA0FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AA100: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801AA104: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AA108: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AA10C: lwc1        $f30, 0x7A34($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X7A34);
    // 0x801AA110: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AA114: lwc1        $f28, 0x7A38($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X7A38);
    // 0x801AA118: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801AA11C: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x801AA120: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801AA124: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801AA128: lui         $s1, 0x8017
    ctx->r17 = S32(0X8017 << 16);
    // 0x801AA12C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801AA130: addiu       $s1, $s1, 0x7B90
    ctx->r17 = ADD32(ctx->r17, 0X7B90);
    // 0x801AA134: swc1        $f10, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f10.u32l;
    // 0x801AA138: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_801AA13C:
    // 0x801AA13C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x801AA140: beql        $s2, $a3, L_801AA178
    if (ctx->r18 == ctx->r7) {
        // 0x801AA144: lwc1        $f18, 0x78($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
            goto L_801AA178;
    }
    goto skip_2;
    // 0x801AA144: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    skip_2:
    // 0x801AA148: add.s       $f16, $f24, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x801AA14C: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x801AA150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AA154: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801AA158: jal         0x801AA434
    // 0x801AA15C: nop

    Map_PathInfo_Draw(rdram, ctx);
        goto after_4;
    // 0x801AA15C: nop

    after_4:
    // 0x801AA160: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801AA164: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x801AA168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AA16C: jal         0x801AA778
    // 0x801AA170: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    Map_PathPlanet_Draw(rdram, ctx);
        goto after_5;
    // 0x801AA170: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x801AA174: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
L_801AA178:
    // 0x801AA178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801AA17C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801AA180: add.s       $f22, $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f30.fl;
    // 0x801AA184: bne         $s0, $s3, L_801AA13C
    if (ctx->r16 != ctx->r19) {
        // 0x801AA188: add.s       $f20, $f20, $f18
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
            goto L_801AA13C;
    }
    // 0x801AA188: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
L_801AA18C:
    // 0x801AA18C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AA190: jal         0x80005740
    // 0x801AA194: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x801AA194: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x801AA198: lw          $ra, 0x74($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X74);
    // 0x801AA19C: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801AA1A0: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x801AA1A4: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x801AA1A8: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x801AA1AC: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x801AA1B0: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x801AA1B4: lw          $s0, 0x64($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X64);
    // 0x801AA1B8: lw          $s1, 0x68($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X68);
    // 0x801AA1BC: lw          $s2, 0x6C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X6C);
    // 0x801AA1C0: lw          $s3, 0x70($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X70);
    // 0x801AA1C4: jr          $ra
    // 0x801AA1C8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x801AA1C8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Option_RankingName_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197D30: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80197D34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80197D38: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80197D3C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80197D40: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80197D44: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80197D48: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80197D4C: jal         0x800B8DD0
    // 0x80197D50: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80197D50: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x80197D54: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197D58: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80197D5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80197D60: addiu       $t1, $t1, 0x7E64
    ctx->r9 = ADD32(ctx->r9, 0X7E64);
    // 0x80197D64: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80197D68: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x80197D6C: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x80197D70: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x80197D74: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80197D78: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80197D7C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x80197D80: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80197D84: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80197D88: lui         $t3, 0x8018
    ctx->r11 = S32(0X8018 << 16);
    // 0x80197D8C: addiu       $t3, $t3, -0x7790
    ctx->r11 = ADD32(ctx->r11, -0X7790);
    // 0x80197D90: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80197D94: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x80197D98: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80197D9C: lbu         $t5, 0x18($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X18);
    // 0x80197DA0: lbu         $t7, 0x19($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X19);
    // 0x80197DA4: lbu         $t9, 0x1A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1A);
    // 0x80197DA8: addiu       $t2, $sp, 0x2C
    ctx->r10 = ADD32(ctx->r29, 0X2C);
    // 0x80197DAC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80197DB0: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80197DB4: sb          $zero, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = 0;
    // 0x80197DB8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80197DBC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80197DC0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80197DC4: sb          $t5, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r13;
    // 0x80197DC8: sb          $t7, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r15;
    // 0x80197DCC: jal         0x800A0094
    // 0x80197DD0: sb          $t9, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r25;
    Graphics_DisplayLargeText(rdram, ctx);
        goto after_1;
    // 0x80197DD0: sb          $t9, 0x2E($sp)
    MEM_B(0X2E, ctx->r29) = ctx->r25;
    after_1:
    // 0x80197DD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80197DD8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80197DDC: jr          $ra
    // 0x80197DE0: nop

    return;
    // 0x80197DE0: nop

;}
RECOMP_FUNC void Map_PlanetSaveSlot_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FD1C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8019FD20: sltiu       $at, $a0, 0x14
    ctx->r1 = ctx->r4 < 0X14 ? 1 : 0;
    // 0x8019FD24: beq         $at, $zero, L_8019FE1C
    if (ctx->r1 == 0) {
        // 0x8019FD28: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_8019FE1C;
    }
    // 0x8019FD28: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8019FD2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019FD30: addu        $at, $at, $t6
    gpr jr_addend_8019FD38 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8019FD34: lw          $t6, 0x7544($at)
    ctx->r14 = ADD32(ctx->r1, 0X7544);
    // 0x8019FD38: jr          $t6
    // 0x8019FD3C: nop

    switch (jr_addend_8019FD38 >> 2) {
        case 0: goto L_8019FDA8; break;
        case 1: goto L_8019FD40; break;
        case 2: goto L_8019FD6C; break;
        case 3: goto L_8019FD48; break;
        case 4: goto L_8019FE1C; break;
        case 5: goto L_8019FD78; break;
        case 6: goto L_8019FDE4; break;
        case 7: goto L_8019FDD8; break;
        case 8: goto L_8019FD9C; break;
        case 9: goto L_8019FDFC; break;
        case 10: goto L_8019FE1C; break;
        case 11: goto L_8019FD90; break;
        case 12: goto L_8019FDB4; break;
        case 13: goto L_8019FDC0; break;
        case 14: goto L_8019FDCC; break;
        case 15: goto L_8019FE1C; break;
        case 16: goto L_8019FD84; break;
        case 17: goto L_8019FD54; break;
        case 18: goto L_8019FD60; break;
        case 19: goto L_8019FDF0; break;
        default: switch_error(__func__, 0x8019FD38, 0x801B7544);
    }
    // 0x8019FD3C: nop

L_8019FD40:
    // 0x8019FD40: b           L_8019FE1C
    // 0x8019FD44: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
        goto L_8019FE1C;
    // 0x8019FD44: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8019FD48:
    // 0x8019FD48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8019FD4C: b           L_8019FE1C
    // 0x8019FD50: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FD50: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FD54:
    // 0x8019FD54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8019FD58: b           L_8019FE1C
    // 0x8019FD5C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FD5C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FD60:
    // 0x8019FD60: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8019FD64: b           L_8019FE1C
    // 0x8019FD68: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FD68: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FD6C:
    // 0x8019FD6C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8019FD70: b           L_8019FE1C
    // 0x8019FD74: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FD74: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FD78:
    // 0x8019FD78: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8019FD7C: b           L_8019FE1C
    // 0x8019FD80: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FD80: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FD84:
    // 0x8019FD84: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8019FD88: b           L_8019FE1C
    // 0x8019FD8C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FD8C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FD90:
    // 0x8019FD90: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8019FD94: b           L_8019FE1C
    // 0x8019FD98: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FD98: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FD9C:
    // 0x8019FD9C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8019FDA0: b           L_8019FE1C
    // 0x8019FDA4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FDA4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FDA8:
    // 0x8019FDA8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8019FDAC: b           L_8019FE1C
    // 0x8019FDB0: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FDB0: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FDB4:
    // 0x8019FDB4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x8019FDB8: b           L_8019FE1C
    // 0x8019FDBC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FDBC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FDC0:
    // 0x8019FDC0: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x8019FDC4: b           L_8019FE1C
    // 0x8019FDC8: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FDC8: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FDCC:
    // 0x8019FDCC: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8019FDD0: b           L_8019FE1C
    // 0x8019FDD4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FDD4: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FDD8:
    // 0x8019FDD8: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8019FDDC: b           L_8019FE1C
    // 0x8019FDE0: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FDE0: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FDE4:
    // 0x8019FDE4: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x8019FDE8: b           L_8019FE1C
    // 0x8019FDEC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FDEC: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FDF0:
    // 0x8019FDF0: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8019FDF4: b           L_8019FE1C
    // 0x8019FDF8: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
        goto L_8019FE1C;
    // 0x8019FDF8: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FDFC:
    // 0x8019FDFC: lui         $t7, 0x8018
    ctx->r15 = S32(0X8018 << 16);
    // 0x8019FE00: lw          $t7, -0x7D84($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D84);
    // 0x8019FE04: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8019FE08: bne         $t7, $zero, L_8019FE18
    if (ctx->r15 != 0) {
        // 0x8019FE0C: nop
    
            goto L_8019FE18;
    }
    // 0x8019FE0C: nop

    // 0x8019FE10: b           L_8019FE18
    // 0x8019FE14: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
        goto L_8019FE18;
    // 0x8019FE14: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
L_8019FE18:
    // 0x8019FE18: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_8019FE1C:
    // 0x8019FE1C: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8019FE20: beq         $a1, $zero, L_8019FE48
    if (ctx->r5 == 0) {
        // 0x8019FE24: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8019FE48;
    }
    // 0x8019FE24: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8019FE28: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019FE2C: beq         $a1, $at, L_8019FE78
    if (ctx->r5 == ctx->r1) {
        // 0x8019FE30: lui         $t4, 0x8017
        ctx->r12 = S32(0X8017 << 16);
            goto L_8019FE78;
    }
    // 0x8019FE30: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8019FE34: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019FE38: beq         $a1, $at, L_8019FEE0
    if (ctx->r5 == ctx->r1) {
        // 0x8019FE3C: lui         $t7, 0x8017
        ctx->r15 = S32(0X8017 << 16);
            goto L_8019FEE0;
    }
    // 0x8019FE3C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019FE40: b           L_8019FF40
    // 0x8019FE44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8019FF40;
    // 0x8019FE44: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8019FE48:
    // 0x8019FE48: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019FE4C: addiu       $t8, $t8, -0x7790
    ctx->r24 = ADD32(ctx->r24, -0X7790);
    // 0x8019FE50: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x8019FE54: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8019FE58: sll         $t9, $a1, 29
    ctx->r25 = S32(ctx->r5 << 29);
    // 0x8019FE5C: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x8019FE60: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8019FE64: bne         $t1, $zero, L_8019FF3C
    if (ctx->r9 != 0) {
        // 0x8019FE68: ori         $t3, $a1, 0x4
        ctx->r11 = ctx->r5 | 0X4;
            goto L_8019FF3C;
    }
    // 0x8019FE68: ori         $t3, $a1, 0x4
    ctx->r11 = ctx->r5 | 0X4;
    // 0x8019FE6C: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x8019FE70: b           L_8019FF3C
    // 0x8019FE74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8019FF3C;
    // 0x8019FE74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8019FE78:
    // 0x8019FE78: lw          $t4, 0x79F8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X79F8);
    // 0x8019FE7C: lui         $t1, 0x8018
    ctx->r9 = S32(0X8018 << 16);
    // 0x8019FE80: addiu       $t1, $t1, -0x7790
    ctx->r9 = ADD32(ctx->r9, -0X7790);
    // 0x8019FE84: beq         $t4, $zero, L_8019FEBC
    if (ctx->r12 == 0) {
        // 0x8019FE88: addu        $a0, $v0, $t1
        ctx->r4 = ADD32(ctx->r2, ctx->r9);
            goto L_8019FEBC;
    }
    // 0x8019FE88: addu        $a0, $v0, $t1
    ctx->r4 = ADD32(ctx->r2, ctx->r9);
    // 0x8019FE8C: lui         $t5, 0x8018
    ctx->r13 = S32(0X8018 << 16);
    // 0x8019FE90: addiu       $t5, $t5, -0x7790
    ctx->r13 = ADD32(ctx->r13, -0X7790);
    // 0x8019FE94: addu        $a0, $v0, $t5
    ctx->r4 = ADD32(ctx->r2, ctx->r13);
    // 0x8019FE98: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8019FE9C: sll         $t6, $a1, 27
    ctx->r14 = S32(ctx->r5 << 27);
    // 0x8019FEA0: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x8019FEA4: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8019FEA8: bne         $t8, $zero, L_8019FF3C
    if (ctx->r24 != 0) {
        // 0x8019FEAC: ori         $t0, $a1, 0x10
        ctx->r8 = ctx->r5 | 0X10;
            goto L_8019FF3C;
    }
    // 0x8019FEAC: ori         $t0, $a1, 0x10
    ctx->r8 = ctx->r5 | 0X10;
    // 0x8019FEB0: sb          $t0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r8;
    // 0x8019FEB4: b           L_8019FF3C
    // 0x8019FEB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8019FF3C;
    // 0x8019FEB8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8019FEBC:
    // 0x8019FEBC: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8019FEC0: sll         $t2, $a1, 30
    ctx->r10 = S32(ctx->r5 << 30);
    // 0x8019FEC4: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8019FEC8: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8019FECC: bne         $t4, $zero, L_8019FF3C
    if (ctx->r12 != 0) {
        // 0x8019FED0: ori         $t6, $a1, 0x2
        ctx->r14 = ctx->r5 | 0X2;
            goto L_8019FF3C;
    }
    // 0x8019FED0: ori         $t6, $a1, 0x2
    ctx->r14 = ctx->r5 | 0X2;
    // 0x8019FED4: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x8019FED8: b           L_8019FF3C
    // 0x8019FEDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8019FF3C;
    // 0x8019FEDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8019FEE0:
    // 0x8019FEE0: lw          $t7, 0x79F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X79F8);
    // 0x8019FEE4: lui         $t4, 0x8018
    ctx->r12 = S32(0X8018 << 16);
    // 0x8019FEE8: addiu       $t4, $t4, -0x7790
    ctx->r12 = ADD32(ctx->r12, -0X7790);
    // 0x8019FEEC: beq         $t7, $zero, L_8019FF24
    if (ctx->r15 == 0) {
        // 0x8019FEF0: addu        $a0, $v0, $t4
        ctx->r4 = ADD32(ctx->r2, ctx->r12);
            goto L_8019FF24;
    }
    // 0x8019FEF0: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x8019FEF4: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x8019FEF8: addiu       $t8, $t8, -0x7790
    ctx->r24 = ADD32(ctx->r24, -0X7790);
    // 0x8019FEFC: addu        $a0, $v0, $t8
    ctx->r4 = ADD32(ctx->r2, ctx->r24);
    // 0x8019FF00: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8019FF04: sll         $t9, $a1, 28
    ctx->r25 = S32(ctx->r5 << 28);
    // 0x8019FF08: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x8019FF0C: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x8019FF10: bne         $t1, $zero, L_8019FF3C
    if (ctx->r9 != 0) {
        // 0x8019FF14: ori         $t3, $a1, 0x8
        ctx->r11 = ctx->r5 | 0X8;
            goto L_8019FF3C;
    }
    // 0x8019FF14: ori         $t3, $a1, 0x8
    ctx->r11 = ctx->r5 | 0X8;
    // 0x8019FF18: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x8019FF1C: b           L_8019FF3C
    // 0x8019FF20: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8019FF3C;
    // 0x8019FF20: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8019FF24:
    // 0x8019FF24: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x8019FF28: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8019FF2C: bne         $t6, $zero, L_8019FF3C
    if (ctx->r14 != 0) {
        // 0x8019FF30: ori         $t8, $a1, 0x1
        ctx->r24 = ctx->r5 | 0X1;
            goto L_8019FF3C;
    }
    // 0x8019FF30: ori         $t8, $a1, 0x1
    ctx->r24 = ctx->r5 | 0X1;
    // 0x8019FF34: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x8019FF38: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8019FF3C:
    // 0x8019FF3C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8019FF40:
    // 0x8019FF40: jr          $ra
    // 0x8019FF44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8019FF44: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void Option_OrdinalNumbers_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80197A3C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80197A40: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80197A44: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80197A48: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80197A4C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80197A50: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x80197A54: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x80197A58: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x80197A5C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x80197A60: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80197A64: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80197A68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197A6C: jal         0x800B8DD0
    // 0x80197A70: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80197A70: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x80197A74: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80197A78: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80197A7C: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x80197A80: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80197A84: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80197A88: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80197A8C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80197A90: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80197A94: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80197A98: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80197A9C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80197AA0: beq         $t0, $at, L_80197B04
    if (ctx->r8 == ctx->r1) {
        // 0x80197AA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80197B04;
    }
    // 0x80197AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197AA8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80197AAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197AB0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80197AB4: cvt.s.w     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80197AB8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80197ABC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80197AC0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197AC4: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80197AC8: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80197ACC: lui         $a1, 0x801B
    ctx->r5 = S32(0X801B << 16);
    // 0x80197AD0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x80197AD4: lw          $a1, -0x1304($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1304);
    // 0x80197AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197ADC: sub.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x80197AE0: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80197AE4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80197AE8: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80197AEC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x80197AF0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80197AF4: jal         0x8009D994
    // 0x80197AF8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x80197AF8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_1:
    // 0x80197AFC: b           L_80197B8C
    // 0x80197B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80197B8C;
    // 0x80197B00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80197B04:
    // 0x80197B04: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80197B08: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80197B0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80197B10: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80197B14: cvt.s.w     $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    ctx->f24.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80197B18: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80197B1C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197B20: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80197B24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80197B28: cvt.s.w     $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    ctx->f22.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80197B2C: lui         $a1, 0x501
    ctx->r5 = S32(0X501 << 16);
    // 0x80197B30: addiu       $a1, $a1, -0x5FB0
    ctx->r5 = ADD32(ctx->r5, -0X5FB0);
    // 0x80197B34: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80197B38: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80197B3C: sub.s       $f0, $f24, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x80197B40: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80197B44: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80197B48: sub.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f18.fl;
    // 0x80197B4C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80197B50: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80197B54: jal         0x8009D994
    // 0x80197B58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x80197B58: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80197B5C: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80197B60: lui         $a1, 0x501
    ctx->r5 = S32(0X501 << 16);
    // 0x80197B64: addiu       $a1, $a1, -0x60A0
    ctx->r5 = ADD32(ctx->r5, -0X60A0);
    // 0x80197B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197B6C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80197B70: addiu       $a3, $zero, 0xF
    ctx->r7 = ADD32(0, 0XF);
    // 0x80197B74: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80197B78: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80197B7C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80197B80: jal         0x8009D994
    // 0x80197B84: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x80197B84: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x80197B88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80197B8C:
    // 0x80197B8C: jal         0x800B8DD0
    // 0x80197B90: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80197B90: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_4:
    // 0x80197B94: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80197B98: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80197B9C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80197BA0: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80197BA4: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x80197BA8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80197BAC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80197BB0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80197BB4: beq         $a0, $zero, L_80197BDC
    if (ctx->r4 == 0) {
        // 0x80197BB8: lui         $a1, 0x800
        ctx->r5 = S32(0X800 << 16);
            goto L_80197BDC;
    }
    // 0x80197BB8: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80197BBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80197BC0: beq         $a0, $at, L_80197C2C
    if (ctx->r4 == ctx->r1) {
        // 0x80197BC4: lui         $a1, 0x800
        ctx->r5 = S32(0X800 << 16);
            goto L_80197C2C;
    }
    // 0x80197BC4: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80197BC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80197BCC: beq         $a0, $at, L_80197C7C
    if (ctx->r4 == ctx->r1) {
        // 0x80197BD0: lui         $a1, 0x800
        ctx->r5 = S32(0X800 << 16);
            goto L_80197C7C;
    }
    // 0x80197BD0: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80197BD4: b           L_80197CCC
    // 0x80197BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80197CCC;
    // 0x80197BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80197BDC:
    // 0x80197BDC: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80197BE0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197BE4: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80197BE8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197BEC: add.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x80197BF0: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x80197BF4: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x80197BF8: sub.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x80197BFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80197C00: addiu       $a2, $a2, 0x3AB8
    ctx->r6 = ADD32(ctx->r6, 0X3AB8);
    // 0x80197C04: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80197C08: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80197C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197C10: addiu       $a1, $a1, 0x3A70
    ctx->r5 = ADD32(ctx->r5, 0X3A70);
    // 0x80197C14: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80197C18: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80197C1C: jal         0x8009C320
    // 0x80197C20: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_5;
    // 0x80197C20: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x80197C24: b           L_80197D18
    // 0x80197C28: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80197D18;
    // 0x80197C28: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80197C2C:
    // 0x80197C2C: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80197C30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197C34: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80197C38: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197C3C: add.s       $f8, $f22, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x80197C40: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x80197C44: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80197C48: sub.s       $f16, $f24, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x80197C4C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80197C50: addiu       $a2, $a2, 0x3930
    ctx->r6 = ADD32(ctx->r6, 0X3930);
    // 0x80197C54: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80197C58: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80197C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197C60: addiu       $a1, $a1, 0x38E0
    ctx->r5 = ADD32(ctx->r5, 0X38E0);
    // 0x80197C64: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80197C68: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80197C6C: jal         0x8009C320
    // 0x80197C70: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_6;
    // 0x80197C70: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_6:
    // 0x80197C74: b           L_80197D18
    // 0x80197C78: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80197D18;
    // 0x80197C78: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80197C7C:
    // 0x80197C7C: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80197C80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197C84: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80197C88: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80197C8C: add.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f18.fl;
    // 0x80197C90: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x80197C94: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x80197C98: sub.s       $f8, $f24, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f6.fl;
    // 0x80197C9C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80197CA0: addiu       $a2, $a2, 0x39A8
    ctx->r6 = ADD32(ctx->r6, 0X39A8);
    // 0x80197CA4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80197CA8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80197CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80197CB0: addiu       $a1, $a1, 0x3950
    ctx->r5 = ADD32(ctx->r5, 0X3950);
    // 0x80197CB4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80197CB8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80197CBC: jal         0x8009C320
    // 0x80197CC0: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_7;
    // 0x80197CC0: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_7:
    // 0x80197CC4: b           L_80197D18
    // 0x80197CC8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
        goto L_80197D18;
    // 0x80197CC8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80197CCC:
    // 0x80197CCC: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80197CD0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80197CD4: lui         $at, 0x4198
    ctx->r1 = S32(0X4198 << 16);
    // 0x80197CD8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80197CDC: add.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl + ctx->f10.fl;
    // 0x80197CE0: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x80197CE4: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x80197CE8: sub.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x80197CEC: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x80197CF0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80197CF4: addiu       $a2, $a2, 0x3B28
    ctx->r6 = ADD32(ctx->r6, 0X3B28);
    // 0x80197CF8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80197CFC: addiu       $a1, $a1, 0x3AE0
    ctx->r5 = ADD32(ctx->r5, 0X3AE0);
    // 0x80197D00: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x80197D04: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80197D08: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80197D0C: jal         0x8009C320
    // 0x80197D10: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_8;
    // 0x80197D10: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x80197D14: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80197D18:
    // 0x80197D18: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x80197D1C: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x80197D20: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x80197D24: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80197D28: jr          $ra
    // 0x80197D2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80197D2C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Map_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E99C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8019E9A0: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8019E9A4: sw          $s7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r23;
    // 0x8019E9A8: sw          $s6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r22;
    // 0x8019E9AC: sw          $s5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r21;
    // 0x8019E9B0: sw          $s4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r20;
    // 0x8019E9B4: sw          $s3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r19;
    // 0x8019E9B8: sw          $s2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r18;
    // 0x8019E9BC: sw          $s1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r17;
    // 0x8019E9C0: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
    // 0x8019E9C4: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x8019E9C8: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8019E9CC: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8019E9D0: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8019E9D4: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8019E9D8: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8019E9DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019E9E0: jal         0x8001DC6C
    // 0x8019E9E4: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    Audio_SetAudioSpec(rdram, ctx);
        goto after_0;
    // 0x8019E9E4: addiu       $a1, $zero, 0x118
    ctx->r5 = ADD32(0, 0X118);
    after_0:
    // 0x8019E9E8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8019E9EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8019E9F0: sb          $t6, 0x7E78($at)
    MEM_B(0X7E78, ctx->r1) = ctx->r14;
    // 0x8019E9F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019E9F8: jal         0x80188010
    // 0x8019E9FC: sw          $zero, 0x7DB0($at)
    MEM_W(0X7DB0, ctx->r1) = 0;
    Title_GetRankTotalHits(rdram, ctx);
        goto after_1;
    // 0x8019E9FC: sw          $zero, 0x7DB0($at)
    MEM_W(0X7DB0, ctx->r1) = 0;
    after_1:
    // 0x8019EA00: jal         0x801A05B4
    // 0x8019EA04: nop

    Map_801A05B4(rdram, ctx);
        goto after_2;
    // 0x8019EA04: nop

    after_2:
    // 0x8019EA08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EA0C: sw          $v0, -0x27C4($at)
    MEM_W(-0X27C4, ctx->r1) = ctx->r2;
    // 0x8019EA10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EA14: sw          $zero, -0x2680($at)
    MEM_W(-0X2680, ctx->r1) = 0;
    // 0x8019EA18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EA1C: sw          $zero, -0x267C($at)
    MEM_W(-0X267C, ctx->r1) = 0;
    // 0x8019EA20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EA24: sw          $zero, -0x2674($at)
    MEM_W(-0X2674, ctx->r1) = 0;
    // 0x8019EA28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EA2C: sw          $zero, -0x2670($at)
    MEM_W(-0X2670, ctx->r1) = 0;
    // 0x8019EA30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EA34: sw          $zero, -0x266C($at)
    MEM_W(-0X266C, ctx->r1) = 0;
    // 0x8019EA38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EA3C: sw          $zero, -0x2634($at)
    MEM_W(-0X2634, ctx->r1) = 0;
    // 0x8019EA40: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x8019EA44: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x8019EA48: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8019EA4C: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8019EA50: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8019EA54: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8019EA58: addiu       $a0, $a0, -0x14B8
    ctx->r4 = ADD32(ctx->r4, -0X14B8);
    // 0x8019EA5C: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8019EA60: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019EA64: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019EA68: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8019EA6C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8019EA70: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8019EA74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019EA78: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x8019EA7C: lui         $s2, 0x801D
    ctx->r18 = S32(0X801D << 16);
    // 0x8019EA80: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x8019EA84: lui         $s4, 0x801D
    ctx->r20 = S32(0X801D << 16);
    // 0x8019EA88: lui         $s5, 0x801D
    ctx->r21 = S32(0X801D << 16);
    // 0x8019EA8C: lui         $s6, 0x801D
    ctx->r22 = S32(0X801D << 16);
    // 0x8019EA90: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8019EA94: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8019EA98: addiu       $s0, $s0, -0x1250
    ctx->r16 = ADD32(ctx->r16, -0X1250);
    // 0x8019EA9C: addiu       $s6, $s6, -0x12C8
    ctx->r22 = ADD32(ctx->r22, -0X12C8);
    // 0x8019EAA0: addiu       $s5, $s5, -0x11D8
    ctx->r21 = ADD32(ctx->r21, -0X11D8);
    // 0x8019EAA4: addiu       $s4, $s4, -0x1340
    ctx->r20 = ADD32(ctx->r20, -0X1340);
    // 0x8019EAA8: addiu       $s3, $s3, -0x13B8
    ctx->r19 = ADD32(ctx->r19, -0X13B8);
    // 0x8019EAAC: addiu       $s2, $s2, -0x1430
    ctx->r18 = ADD32(ctx->r18, -0X1430);
    // 0x8019EAB0: addiu       $s1, $s1, -0x14A8
    ctx->r17 = ADD32(ctx->r17, -0X14A8);
    // 0x8019EAB4: lwc1        $f22, 0x7520($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7520);
    // 0x8019EAB8: addiu       $s7, $zero, 0xFF
    ctx->r23 = ADD32(0, 0XFF);
L_8019EABC:
    // 0x8019EABC: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x8019EAC0: sw          $zero, 0x50($s1)
    MEM_W(0X50, ctx->r17) = 0;
    // 0x8019EAC4: sw          $s7, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r23;
    // 0x8019EAC8: sw          $s7, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r23;
    // 0x8019EACC: swc1        $f20, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f20.u32l;
    // 0x8019EAD0: jal         0x80004EB0
    // 0x8019EAD4: swc1        $f20, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f20.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x8019EAD4: swc1        $f20, 0x50($s3)
    MEM_W(0X50, ctx->r19) = ctx->f20.u32l;
    after_3:
    // 0x8019EAD8: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8019EADC: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8019EAE0: jal         0x80004EB0
    // 0x8019EAE4: swc1        $f6, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_4;
    // 0x8019EAE4: swc1        $f6, 0x28($s4)
    MEM_W(0X28, ctx->r20) = ctx->f6.u32l;
    after_4:
    // 0x8019EAE8: mul.s       $f8, $f0, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8019EAEC: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8019EAF0: jal         0x80004EB0
    // 0x8019EAF4: swc1        $f10, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_5;
    // 0x8019EAF4: swc1        $f10, 0x50($s4)
    MEM_W(0X50, ctx->r20) = ctx->f10.u32l;
    after_5:
    // 0x8019EAF8: mul.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8019EAFC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8019EB00: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8019EB04: nop

    // 0x8019EB08: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019EB0C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8019EB10: nop

    // 0x8019EB14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019EB18: jal         0x80004EB0
    // 0x8019EB1C: swc1        $f6, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_6;
    // 0x8019EB1C: swc1        $f6, 0x28($s5)
    MEM_W(0X28, ctx->r21) = ctx->f6.u32l;
    after_6:
    // 0x8019EB20: mul.s       $f8, $f0, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8019EB24: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019EB28: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8019EB2C: nop

    // 0x8019EB30: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8019EB34: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8019EB38: nop

    // 0x8019EB3C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8019EB40: jal         0x80004EB0
    // 0x8019EB44: swc1        $f18, 0x50($s5)
    MEM_W(0X50, ctx->r21) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_7;
    // 0x8019EB44: swc1        $f18, 0x50($s5)
    MEM_W(0X50, ctx->r21) = ctx->f18.u32l;
    after_7:
    // 0x8019EB48: mul.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8019EB4C: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8019EB50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019EB54: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019EB58: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8019EB5C: nop

    // 0x8019EB60: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8019EB64: nop

    // 0x8019EB68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019EB6C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019EB70: jal         0x80004EB0
    // 0x8019EB74: swc1        $f18, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_8;
    // 0x8019EB74: swc1        $f18, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->f18.u32l;
    after_8:
    // 0x8019EB78: mul.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x8019EB7C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8019EB80: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019EB84: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019EB88: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8019EB8C: nop

    // 0x8019EB90: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8019EB94: nop

    // 0x8019EB98: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019EB9C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019EBA0: jal         0x80004EB0
    // 0x8019EBA4: swc1        $f18, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_9;
    // 0x8019EBA4: swc1        $f18, 0x50($s6)
    MEM_W(0X50, ctx->r22) = ctx->f18.u32l;
    after_9:
    // 0x8019EBA8: mul.s       $f4, $f0, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8019EBAC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8019EBB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019EBB4: nop

    // 0x8019EBB8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8019EBBC: jal         0x80004EB0
    // 0x8019EBC0: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_10;
    // 0x8019EBC0: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    after_10:
    // 0x8019EBC4: mul.s       $f10, $f0, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x8019EBC8: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8019EBCC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019EBD0: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x8019EBD4: addiu       $t9, $t9, -0x1228
    ctx->r25 = ADD32(ctx->r25, -0X1228);
    // 0x8019EBD8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8019EBDC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019EBE0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019EBE4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8019EBE8: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8019EBEC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8019EBF0: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8019EBF4: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8019EBF8: bne         $s0, $t9, L_8019EABC
    if (ctx->r16 != ctx->r25) {
        // 0x8019EBFC: swc1        $f18, 0x4C($s0)
        MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
            goto L_8019EABC;
    }
    // 0x8019EBFC: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x8019EC00: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC04: sw          $zero, -0x2688($at)
    MEM_W(-0X2688, ctx->r1) = 0;
    // 0x8019EC08: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC0C: sw          $zero, -0x2684($at)
    MEM_W(-0X2684, ctx->r1) = 0;
    // 0x8019EC10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC14: sw          $zero, -0xFF0($at)
    MEM_W(-0XFF0, ctx->r1) = 0;
    // 0x8019EC18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC1C: sw          $zero, -0xFEC($at)
    MEM_W(-0XFEC, ctx->r1) = 0;
    // 0x8019EC20: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8019EC24: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019EC28: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC2C: sw          $zero, -0x2700($at)
    MEM_W(-0X2700, ctx->r1) = 0;
    // 0x8019EC30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC34: swc1        $f20, -0x1548($at)
    MEM_W(-0X1548, ctx->r1) = ctx->f20.u32l;
    // 0x8019EC38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC3C: swc1        $f0, -0x1508($at)
    MEM_W(-0X1508, ctx->r1) = ctx->f0.u32l;
    // 0x8019EC40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC44: sw          $zero, -0x26FC($at)
    MEM_W(-0X26FC, ctx->r1) = 0;
    // 0x8019EC48: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC4C: swc1        $f20, -0x1544($at)
    MEM_W(-0X1544, ctx->r1) = ctx->f20.u32l;
    // 0x8019EC50: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC54: swc1        $f0, -0x1504($at)
    MEM_W(-0X1504, ctx->r1) = ctx->f0.u32l;
    // 0x8019EC58: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC5C: sw          $zero, -0x26F8($at)
    MEM_W(-0X26F8, ctx->r1) = 0;
    // 0x8019EC60: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC64: swc1        $f20, -0x1540($at)
    MEM_W(-0X1540, ctx->r1) = ctx->f20.u32l;
    // 0x8019EC68: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EC6C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019EC70: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8019EC74: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019EC78: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8019EC7C: addiu       $a1, $a1, -0x14CC
    ctx->r5 = ADD32(ctx->r5, -0X14CC);
    // 0x8019EC80: addiu       $v0, $v0, -0x14FC
    ctx->r2 = ADD32(ctx->r2, -0X14FC);
    // 0x8019EC84: addiu       $a0, $a0, -0x153C
    ctx->r4 = ADD32(ctx->r4, -0X153C);
    // 0x8019EC88: addiu       $v1, $v1, -0x26F4
    ctx->r3 = ADD32(ctx->r3, -0X26F4);
    // 0x8019EC8C: swc1        $f0, -0x1500($at)
    MEM_W(-0X1500, ctx->r1) = ctx->f0.u32l;
L_8019EC90:
    // 0x8019EC90: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8019EC94: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8019EC98: swc1        $f20, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f20.u32l;
    // 0x8019EC9C: swc1        $f0, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8019ECA0: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8019ECA4: swc1        $f20, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f20.u32l;
    // 0x8019ECA8: swc1        $f0, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8019ECAC: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8019ECB0: swc1        $f20, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f20.u32l;
    // 0x8019ECB4: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8019ECB8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8019ECBC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8019ECC0: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8019ECC4: swc1        $f20, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = ctx->f20.u32l;
    // 0x8019ECC8: bne         $v0, $a1, L_8019EC90
    if (ctx->r2 != ctx->r5) {
        // 0x8019ECCC: swc1        $f0, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = ctx->f0.u32l;
            goto L_8019EC90;
    }
    // 0x8019ECCC: swc1        $f0, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8019ECD0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019ECD4: swc1        $f20, -0x25E0($at)
    MEM_W(-0X25E0, ctx->r1) = ctx->f20.u32l;
    // 0x8019ECD8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019ECDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019ECE0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019ECE4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019ECE8: swc1        $f4, -0x25DC($at)
    MEM_W(-0X25DC, ctx->r1) = ctx->f4.u32l;
    // 0x8019ECEC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019ECF0: swc1        $f20, -0x25D8($at)
    MEM_W(-0X25D8, ctx->r1) = ctx->f20.u32l;
    // 0x8019ECF4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019ECF8: lwc1        $f6, 0x7524($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7524);
    // 0x8019ECFC: addiu       $v0, $v0, -0x2600
    ctx->r2 = ADD32(ctx->r2, -0X2600);
    // 0x8019ED00: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019ED04: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8019ED08: lwc1        $f8, 0x7528($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7528);
    // 0x8019ED0C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019ED10: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x8019ED14: addiu       $a0, $a0, -0x25F8
    ctx->r4 = ADD32(ctx->r4, -0X25F8);
    // 0x8019ED18: addiu       $v1, $v1, -0x25FC
    ctx->r3 = ADD32(ctx->r3, -0X25FC);
    // 0x8019ED1C: swc1        $f20, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f20.u32l;
    // 0x8019ED20: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019ED24: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8019ED28: lwc1        $f10, 0x752C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X752C);
    // 0x8019ED2C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8019ED30: addiu       $a1, $a1, -0x25F4
    ctx->r5 = ADD32(ctx->r5, -0X25F4);
    // 0x8019ED34: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019ED38: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
    // 0x8019ED3C: lwc1        $f16, 0x7530($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7530);
    // 0x8019ED40: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8019ED44: addiu       $t0, $t0, -0x25F0
    ctx->r8 = ADD32(ctx->r8, -0X25F0);
    // 0x8019ED48: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019ED4C: swc1        $f16, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f16.u32l;
    // 0x8019ED50: lwc1        $f18, 0x7534($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7534);
    // 0x8019ED54: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x8019ED58: addiu       $t1, $t1, -0x25EC
    ctx->r9 = ADD32(ctx->r9, -0X25EC);
    // 0x8019ED5C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x8019ED60: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x8019ED64: addiu       $t3, $t3, -0x25E4
    ctx->r11 = ADD32(ctx->r11, -0X25E4);
    // 0x8019ED68: addiu       $t2, $t2, -0x25E8
    ctx->r10 = ADD32(ctx->r10, -0X25E8);
    // 0x8019ED6C: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8019ED70: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8019ED74: swc1        $f20, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f20.u32l;
    // 0x8019ED78: swc1        $f20, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f20.u32l;
    // 0x8019ED7C: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8019ED80: lwc1        $f8, 0x0($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8019ED84: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8019ED88: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8019ED8C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8019ED90: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8019ED94: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x8019ED98: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x8019ED9C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019EDA0: addiu       $t7, $t7, -0x2604
    ctx->r15 = ADD32(ctx->r15, -0X2604);
    // 0x8019EDA4: addiu       $t6, $t6, -0x2608
    ctx->r14 = ADD32(ctx->r14, -0X2608);
    // 0x8019EDA8: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x8019EDAC: addiu       $a3, $a3, -0x260C
    ctx->r7 = ADD32(ctx->r7, -0X260C);
    // 0x8019EDB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019EDB4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019EDB8: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x8019EDBC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8019EDC0: lwc1        $f14, 0x0($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019EDC4: lw          $a2, 0x0($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X0);
    // 0x8019EDC8: jal         0x801AD718
    // 0x8019EDCC: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    Map_SetCamRot(rdram, ctx);
        goto after_11;
    // 0x8019EDCC: lwc1        $f12, 0x0($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X0);
    after_11:
    // 0x8019EDD0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019EDD4: addiu       $v0, $v0, -0x2760
    ctx->r2 = ADD32(ctx->r2, -0X2760);
    // 0x8019EDD8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8019EDDC:
    // 0x8019EDDC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8019EDE0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8019EDE4: slti        $at, $v1, 0xF
    ctx->r1 = SIGNED(ctx->r3) < 0XF ? 1 : 0;
    // 0x8019EDE8: bne         $at, $zero, L_8019EDDC
    if (ctx->r1 != 0) {
        // 0x8019EDEC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8019EDDC;
    }
    // 0x8019EDEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8019EDF0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EDF4: sw          $zero, -0x26A0($at)
    MEM_W(-0X26A0, ctx->r1) = 0;
    // 0x8019EDF8: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019EDFC: sw          $s7, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r23;
    // 0x8019EE00: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019EE04: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x8019EE08: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019EE0C: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x8019EE10: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8019EE14: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x8019EE18: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019EE1C: swc1        $f20, 0x7D20($at)
    MEM_W(0X7D20, ctx->r1) = ctx->f20.u32l;
    // 0x8019EE20: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE24: sw          $zero, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = 0;
    // 0x8019EE28: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019EE2C: sh          $zero, 0x1A36($at)
    MEM_H(0X1A36, ctx->r1) = 0;
    // 0x8019EE30: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE34: swc1        $f20, -0x15A8($at)
    MEM_W(-0X15A8, ctx->r1) = ctx->f20.u32l;
    // 0x8019EE38: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE3C: swc1        $f20, -0x15A4($at)
    MEM_W(-0X15A4, ctx->r1) = ctx->f20.u32l;
    // 0x8019EE40: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE44: jal         0x801A0788
    // 0x8019EE48: swc1        $f20, -0x15A0($at)
    MEM_W(-0X15A0, ctx->r1) = ctx->f20.u32l;
    Map_Starfield_Setup(rdram, ctx);
        goto after_12;
    // 0x8019EE48: swc1        $f20, -0x15A0($at)
    MEM_W(-0X15A0, ctx->r1) = ctx->f20.u32l;
    after_12:
    // 0x8019EE4C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019EE50: sw          $zero, -0x7D80($at)
    MEM_W(-0X7D80, ctx->r1) = 0;
    // 0x8019EE54: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019EE58: sw          $zero, -0x7D7C($at)
    MEM_W(-0X7D7C, ctx->r1) = 0;
    // 0x8019EE5C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE60: sw          $zero, -0x2648($at)
    MEM_W(-0X2648, ctx->r1) = 0;
    // 0x8019EE64: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE68: sw          $zero, -0x2644($at)
    MEM_W(-0X2644, ctx->r1) = 0;
    // 0x8019EE6C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE70: sw          $zero, -0x2640($at)
    MEM_W(-0X2640, ctx->r1) = 0;
    // 0x8019EE74: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE78: sw          $zero, -0x269C($at)
    MEM_W(-0X269C, ctx->r1) = 0;
    // 0x8019EE7C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE80: sw          $zero, -0x2698($at)
    MEM_W(-0X2698, ctx->r1) = 0;
    // 0x8019EE84: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE88: sw          $zero, -0x2694($at)
    MEM_W(-0X2694, ctx->r1) = 0;
    // 0x8019EE8C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EE90: swc1        $f20, -0x1594($at)
    MEM_W(-0X1594, ctx->r1) = ctx->f20.u32l;
    // 0x8019EE94: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019EE98: lwc1        $f6, 0x7538($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7538);
    // 0x8019EE9C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EEA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8019EEA4: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8019EEA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019EEAC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8019EEB0: jal         0x8001D444
    // 0x8019EEB4: swc1        $f6, -0x1590($at)
    MEM_W(-0X1590, ctx->r1) = ctx->f6.u32l;
    Audio_PlaySequence(rdram, ctx);
        goto after_13;
    // 0x8019EEB4: swc1        $f6, -0x1590($at)
    MEM_W(-0X1590, ctx->r1) = ctx->f6.u32l;
    after_13:
    // 0x8019EEB8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EEBC: sw          $zero, -0x103C($at)
    MEM_W(-0X103C, ctx->r1) = 0;
    // 0x8019EEC0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EEC4: sw          $zero, -0x1038($at)
    MEM_W(-0X1038, ctx->r1) = 0;
    // 0x8019EEC8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EECC: sw          $zero, -0x1030($at)
    MEM_W(-0X1030, ctx->r1) = 0;
    // 0x8019EED0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019EED4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019EED8: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019EEDC: sw          $zero, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = 0;
    // 0x8019EEE0: addiu       $a0, $a0, -0x2E8
    ctx->r4 = ADD32(ctx->r4, -0X2E8);
    // 0x8019EEE4: addiu       $v0, $v0, -0x27C0
    ctx->r2 = ADD32(ctx->r2, -0X27C0);
    // 0x8019EEE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8019EEEC:
    // 0x8019EEEC: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8019EEF0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8019EEF4: slti        $at, $v1, 0x18
    ctx->r1 = SIGNED(ctx->r3) < 0X18 ? 1 : 0;
    // 0x8019EEF8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8019EEFC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x8019EF00: bne         $at, $zero, L_8019EEEC
    if (ctx->r1 != 0) {
        // 0x8019EF04: sw          $zero, -0x8($a0)
        MEM_W(-0X8, ctx->r4) = 0;
            goto L_8019EEEC;
    }
    // 0x8019EF04: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x8019EF08: jal         0x801A6694
    // 0x8019EF0C: nop

    Map_PositionPlanets(rdram, ctx);
        goto after_14;
    // 0x8019EF0C: nop

    after_14:
    // 0x8019EF10: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x8019EF14: lhu         $v0, 0x1A34($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A34);
    // 0x8019EF18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8019EF1C: beq         $v0, $zero, L_8019EF34
    if (ctx->r2 == 0) {
        // 0x8019EF20: nop
    
            goto L_8019EF34;
    }
    // 0x8019EF20: nop

    // 0x8019EF24: beq         $v0, $at, L_8019EF54
    if (ctx->r2 == ctx->r1) {
        // 0x8019EF28: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8019EF54;
    }
    // 0x8019EF28: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8019EF2C: beq         $v0, $at, L_8019EF44
    if (ctx->r2 == ctx->r1) {
        // 0x8019EF30: nop
    
            goto L_8019EF44;
    }
    // 0x8019EF30: nop

L_8019EF34:
    // 0x8019EF34: jal         0x8019F600
    // 0x8019EF38: nop

    Map_Setup_Menu(rdram, ctx);
        goto after_15;
    // 0x8019EF38: nop

    after_15:
    // 0x8019EF3C: b           L_8019EF5C
    // 0x8019EF40: nop

        goto L_8019EF5C;
    // 0x8019EF40: nop

L_8019EF44:
    // 0x8019EF44: jal         0x8019F164
    // 0x8019EF48: nop

    Map_Setup_Play(rdram, ctx);
        goto after_16;
    // 0x8019EF48: nop

    after_16:
    // 0x8019EF4C: b           L_8019EF5C
    // 0x8019EF50: nop

        goto L_8019EF5C;
    // 0x8019EF50: nop

L_8019EF54:
    // 0x8019EF54: jal         0x8019F42C
    // 0x8019EF58: nop

    Map_Setup_GameOver(rdram, ctx);
        goto after_17;
    // 0x8019EF58: nop

    after_17:
L_8019EF5C:
    // 0x8019EF5C: jal         0x801A914C
    // 0x8019EF60: nop

    Map_PositionCursor(rdram, ctx);
        goto after_18;
    // 0x8019EF60: nop

    after_18:
    // 0x8019EF64: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019EF68: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019EF6C: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8019EF70: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8019EF74: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019EF78: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8019EF7C: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x8019EF80: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x8019EF84: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019EF88: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8019EF8C: addiu       $s4, $s4, -0x47F0
    ctx->r20 = ADD32(ctx->r20, -0X47F0);
    // 0x8019EF90: addiu       $v0, $v0, -0x6BF0
    ctx->r2 = ADD32(ctx->r2, -0X6BF0);
    // 0x8019EF94: addiu       $t3, $t3, -0x4BF0
    ctx->r11 = ADD32(ctx->r11, -0X4BF0);
    // 0x8019EF98: addiu       $t2, $t2, -0x6FF0
    ctx->r10 = ADD32(ctx->r10, -0X6FF0);
    // 0x8019EF9C: addiu       $t1, $t1, 0x6C10
    ctx->r9 = ADD32(ctx->r9, 0X6C10);
    // 0x8019EFA0: addiu       $t0, $t0, 0x4810
    ctx->r8 = ADD32(ctx->r8, 0X4810);
    // 0x8019EFA4: addiu       $a3, $a3, 0x2410
    ctx->r7 = ADD32(ctx->r7, 0X2410);
    // 0x8019EFA8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8019EFAC: addiu       $a1, $a1, -0x23F0
    ctx->r5 = ADD32(ctx->r5, -0X23F0);
    // 0x8019EFB0: addiu       $a0, $a0, -0x47F0
    ctx->r4 = ADD32(ctx->r4, -0X47F0);
    // 0x8019EFB4: addiu       $s3, $zero, 0x34
    ctx->r19 = ADD32(0, 0X34);
    // 0x8019EFB8: addiu       $s2, $zero, 0x44
    ctx->r18 = ADD32(0, 0X44);
    // 0x8019EFBC: addiu       $s1, $zero, 0x52
    ctx->r17 = ADD32(0, 0X52);
    // 0x8019EFC0: addiu       $s0, $zero, 0x37
    ctx->r16 = ADD32(0, 0X37);
    // 0x8019EFC4: addiu       $ra, $zero, 0x51
    ctx->r31 = ADD32(0, 0X51);
    // 0x8019EFC8: addiu       $t5, $zero, 0x4B
    ctx->r13 = ADD32(0, 0X4B);
    // 0x8019EFCC: addiu       $t4, $zero, 0x54
    ctx->r12 = ADD32(0, 0X54);
    // 0x8019EFD0: addiu       $v1, $zero, 0x6A
    ctx->r3 = ADD32(0, 0X6A);
L_8019EFD4:
    // 0x8019EFD4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8019EFD8: sltu        $at, $v0, $s4
    ctx->r1 = ctx->r2 < ctx->r20 ? 1 : 0;
    // 0x8019EFDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8019EFE0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8019EFE4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8019EFE8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8019EFEC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8019EFF0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8019EFF4: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8019EFF8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8019EFFC: sb          $v1, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r3;
    // 0x8019F000: sb          $t4, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r12;
    // 0x8019F004: sb          $t5, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r13;
    // 0x8019F008: sb          $ra, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r31;
    // 0x8019F00C: sb          $s0, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r16;
    // 0x8019F010: sb          $s1, -0x1($t1)
    MEM_B(-0X1, ctx->r9) = ctx->r17;
    // 0x8019F014: sb          $s2, -0x1($t2)
    MEM_B(-0X1, ctx->r10) = ctx->r18;
    // 0x8019F018: sb          $s3, -0x1($t3)
    MEM_B(-0X1, ctx->r11) = ctx->r19;
    // 0x8019F01C: bne         $at, $zero, L_8019EFD4
    if (ctx->r1 != 0) {
        // 0x8019F020: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8019EFD4;
    }
    // 0x8019F020: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8019F024: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x8019F028: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x8019F02C: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8019F030: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x8019F034: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8019F038: lui         $s3, 0xFF
    ctx->r19 = S32(0XFF << 16);
    // 0x8019F03C: ori         $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 | 0XFFFF;
    // 0x8019F040: addiu       $s4, $s4, 0x1FD0
    ctx->r20 = ADD32(ctx->r20, 0X1FD0);
    // 0x8019F044: addiu       $s6, $s6, 0x68F8
    ctx->r22 = ADD32(ctx->r22, 0X68F8);
    // 0x8019F048: addiu       $s1, $s1, 0x68D4
    ctx->r17 = ADD32(ctx->r17, 0X68D4);
    // 0x8019F04C: addiu       $s2, $s2, 0x68B0
    ctx->r18 = ADD32(ctx->r18, 0X68B0);
    // 0x8019F050: addiu       $s0, $s0, -0x27E8
    ctx->r16 = ADD32(ctx->r16, -0X27E8);
    // 0x8019F054: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
L_8019F058:
    // 0x8019F058: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8019F05C: swc1        $f20, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f20.u32l;
    // 0x8019F060: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8019F064: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8019F068: srl         $t6, $t9, 28
    ctx->r14 = S32(U32(ctx->r25) >> 28);
    // 0x8019F06C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019F070: addu        $t9, $s4, $t7
    ctx->r25 = ADD32(ctx->r20, ctx->r15);
    // 0x8019F074: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8019F078: and         $t8, $v0, $s3
    ctx->r24 = ctx->r2 & ctx->r19;
    // 0x8019F07C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8019F080: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8019F084: jal         0x801A07E8
    // 0x8019F088: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    Map_Texture_Sphere(rdram, ctx);
        goto after_19;
    // 0x8019F088: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    after_19:
    // 0x8019F08C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019F090: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8019F094: bne         $s1, $s6, L_8019F058
    if (ctx->r17 != ctx->r22) {
        // 0x8019F098: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8019F058;
    }
    // 0x8019F098: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8019F09C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019F0A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019F0A4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0A8: sw          $zero, -0x27F0($at)
    MEM_W(-0X27F0, ctx->r1) = 0;
    // 0x8019F0AC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F0B0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8019F0B4: sw          $t9, 0x7B40($at)
    MEM_W(0X7B40, ctx->r1) = ctx->r25;
    // 0x8019F0B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0BC: sw          $zero, -0x26B8($at)
    MEM_W(-0X26B8, ctx->r1) = 0;
    // 0x8019F0C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0C4: sw          $zero, -0x113C($at)
    MEM_W(-0X113C, ctx->r1) = 0;
    // 0x8019F0C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0CC: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x8019F0D0: sw          $t8, -0x1138($at)
    MEM_W(-0X1138, ctx->r1) = ctx->r24;
    // 0x8019F0D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0D8: swc1        $f0, -0x100C($at)
    MEM_W(-0X100C, ctx->r1) = ctx->f0.u32l;
    // 0x8019F0DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0E0: swc1        $f0, -0x1008($at)
    MEM_W(-0X1008, ctx->r1) = ctx->f0.u32l;
    // 0x8019F0E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0E8: swc1        $f20, -0x1144($at)
    MEM_W(-0X1144, ctx->r1) = ctx->f20.u32l;
    // 0x8019F0EC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0F0: swc1        $f20, -0x1140($at)
    MEM_W(-0X1140, ctx->r1) = ctx->f20.u32l;
    // 0x8019F0F4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F0F8: sw          $zero, -0x1160($at)
    MEM_W(-0X1160, ctx->r1) = 0;
    // 0x8019F0FC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F100: sw          $zero, -0x115C($at)
    MEM_W(-0X115C, ctx->r1) = 0;
    // 0x8019F104: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F108: sw          $s7, -0x1158($at)
    MEM_W(-0X1158, ctx->r1) = ctx->r23;
    // 0x8019F10C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F110: sw          $s7, -0x1154($at)
    MEM_W(-0X1154, ctx->r1) = ctx->r23;
    // 0x8019F114: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F118: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8019F11C: sw          $t6, -0x14CC($at)
    MEM_W(-0X14CC, ctx->r1) = ctx->r14;
    // 0x8019F120: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8019F124: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8019F128: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8019F12C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8019F130: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8019F134: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8019F138: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x8019F13C: lw          $s0, 0x5C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X5C);
    // 0x8019F140: lw          $s1, 0x60($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X60);
    // 0x8019F144: lw          $s2, 0x64($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X64);
    // 0x8019F148: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x8019F14C: lw          $s4, 0x6C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X6C);
    // 0x8019F150: lw          $s5, 0x70($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X70);
    // 0x8019F154: lw          $s6, 0x74($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X74);
    // 0x8019F158: lw          $s7, 0x78($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X78);
    // 0x8019F15C: jr          $ra
    // 0x8019F160: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8019F160: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
