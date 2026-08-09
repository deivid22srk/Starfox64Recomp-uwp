#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void Option_8019A080(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A080: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A084: sw          $zero, -0x6C80($at)
    MEM_W(-0X6C80, ctx->r1) = 0;
    // 0x8019A088: sw          $zero, -0x6C7C($at)
    MEM_W(-0X6C7C, ctx->r1) = 0;
    // 0x8019A08C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A090: sw          $zero, -0x6C78($at)
    MEM_W(-0X6C78, ctx->r1) = 0;
    // 0x8019A094: sw          $zero, -0x6C74($at)
    MEM_W(-0X6C74, ctx->r1) = 0;
    // 0x8019A098: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A09C: sw          $zero, -0x6C70($at)
    MEM_W(-0X6C70, ctx->r1) = 0;
    // 0x8019A0A0: sw          $zero, -0x6C6C($at)
    MEM_W(-0X6C6C, ctx->r1) = 0;
    // 0x8019A0A4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A0A8: sw          $zero, -0x6C68($at)
    MEM_W(-0X6C68, ctx->r1) = 0;
    // 0x8019A0AC: sw          $zero, -0x6C64($at)
    MEM_W(-0X6C64, ctx->r1) = 0;
    // 0x8019A0B0: jr          $ra
    // 0x8019A0B4: nop

    return;
    // 0x8019A0B4: nop

;}
RECOMP_FUNC void Title_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801878D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801878DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801878E0: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801878E4: lw          $t6, -0x7D3C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7D3C);
    // 0x801878E8: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x801878EC: beq         $at, $zero, L_80187A74
    if (ctx->r1 == 0) {
        // 0x801878F0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80187A74;
    }
    // 0x801878F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801878F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801878F8: addu        $at, $at, $t6
    gpr jr_addend_80187900 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801878FC: lw          $t6, 0x6DA8($at)
    ctx->r14 = ADD32(ctx->r1, 0X6DA8);
    // 0x80187900: jr          $t6
    // 0x80187904: nop

    switch (jr_addend_80187900 >> 2) {
        case 0: goto L_80187918; break;
        case 1: goto L_80187978; break;
        case 2: goto L_801879CC; break;
        case 3: goto L_80187A08; break;
        case 4: goto L_80187A2C; break;
        case 5: goto L_80187A58; break;
        case 6: goto L_80187A74; break;
        case 7: goto L_80187908; break;
        default: switch_error(__func__, 0x80187900, 0x801B6DA8);
    }
    // 0x80187904: nop

L_80187908:
    // 0x80187908: jal         0x80187CA8
    // 0x8018790C: nop

    Title_Ranking_Draw(rdram, ctx);
        goto after_0;
    // 0x8018790C: nop

    after_0:
    // 0x80187910: b           L_80187A74
    // 0x80187914: nop

        goto L_80187A74;
    // 0x80187914: nop

L_80187918:
    // 0x80187918: jal         0x801918FC
    // 0x8018791C: nop

    Title_Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8018791C: nop

    after_1:
    // 0x80187920: jal         0x80189208
    // 0x80187924: nop

    Title_Screen_Draw(rdram, ctx);
        goto after_2;
    // 0x80187924: nop

    after_2:
    // 0x80187928: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018792C: jal         0x80005740
    // 0x80187930: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x80187930: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x80187934: jal         0x8018F680
    // 0x80187938: nop

    Title_StarfoxLogo_Draw(rdram, ctx);
        goto after_4;
    // 0x80187938: nop

    after_4:
    // 0x8018793C: jal         0x8018F85C
    // 0x80187940: nop

    Title_CopyrightSymbol_Draw(rdram, ctx);
        goto after_5;
    // 0x80187940: nop

    after_5:
    // 0x80187944: jal         0x8018FC14
    // 0x80187948: nop

    Title_Copyright_Draw(rdram, ctx);
        goto after_6;
    // 0x80187948: nop

    after_6:
    // 0x8018794C: jal         0x8018F8E4
    // 0x80187950: nop

    Title_PressStart_Draw(rdram, ctx);
        goto after_7;
    // 0x80187950: nop

    after_7:
    // 0x80187954: jal         0x801918FC
    // 0x80187958: nop

    Title_Matrix_Push(rdram, ctx);
        goto after_8;
    // 0x80187958: nop

    after_8:
    // 0x8018795C: jal         0x8018F77C
    // 0x80187960: nop

    Title_64Logo_Draw(rdram, ctx);
        goto after_9;
    // 0x80187960: nop

    after_9:
    // 0x80187964: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187968: jal         0x80005740
    // 0x8018796C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_10;
    // 0x8018796C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_10:
    // 0x80187970: b           L_80187A74
    // 0x80187974: nop

        goto L_80187A74;
    // 0x80187974: nop

L_80187978:
    // 0x80187978: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8018797C: lw          $t7, -0x7CB8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7CB8);
    // 0x80187980: beq         $t7, $zero, L_801879B4
    if (ctx->r15 == 0) {
        // 0x80187984: nop
    
            goto L_801879B4;
    }
    // 0x80187984: nop

    // 0x80187988: jal         0x801918FC
    // 0x8018798C: nop

    Title_Matrix_Push(rdram, ctx);
        goto after_11;
    // 0x8018798C: nop

    after_11:
    // 0x80187990: jal         0x8018A2F8
    // 0x80187994: nop

    Title_CsGreatFoxTraveling_Draw(rdram, ctx);
        goto after_12;
    // 0x80187994: nop

    after_12:
    // 0x80187998: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018799C: jal         0x80005740
    // 0x801879A0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x801879A0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_13:
    // 0x801879A4: jal         0x800BB5D0
    // 0x801879A8: nop

    Radio_Draw(rdram, ctx);
        goto after_14;
    // 0x801879A8: nop

    after_14:
    // 0x801879AC: jal         0x80190C9C
    // 0x801879B0: nop

    Title_TitleCard_Draw(rdram, ctx);
        goto after_15;
    // 0x801879B0: nop

    after_15:
L_801879B4:
    // 0x801879B4: jal         0x8018FF74
    // 0x801879B8: nop

    Title_SunGlare_Draw(rdram, ctx);
        goto after_16;
    // 0x801879B8: nop

    after_16:
    // 0x801879BC: jal         0x801906A0
    // 0x801879C0: nop

    Title_Logos_Draw(rdram, ctx);
        goto after_17;
    // 0x801879C0: nop

    after_17:
    // 0x801879C4: b           L_80187A74
    // 0x801879C8: nop

        goto L_80187A74;
    // 0x801879C8: nop

L_801879CC:
    // 0x801879CC: jal         0x801918FC
    // 0x801879D0: nop

    Title_Matrix_Push(rdram, ctx);
        goto after_18;
    // 0x801879D0: nop

    after_18:
    // 0x801879D4: jal         0x8018A990
    // 0x801879D8: nop

    Title_CsTeamRunning_Draw(rdram, ctx);
        goto after_19;
    // 0x801879D8: nop

    after_19:
    // 0x801879DC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801879E0: jal         0x80005740
    // 0x801879E4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x801879E4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_20:
    // 0x801879E8: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x801879EC: lw          $t8, -0x7CBC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7CBC);
    // 0x801879F0: beq         $t8, $zero, L_80187A74
    if (ctx->r24 == 0) {
        // 0x801879F4: nop
    
            goto L_80187A74;
    }
    // 0x801879F4: nop

    // 0x801879F8: jal         0x8018FD08
    // 0x801879FC: nop

    Title_TeamName_Draw(rdram, ctx);
        goto after_21;
    // 0x801879FC: nop

    after_21:
    // 0x80187A00: b           L_80187A74
    // 0x80187A04: nop

        goto L_80187A74;
    // 0x80187A04: nop

L_80187A08:
    // 0x80187A08: jal         0x801918FC
    // 0x80187A0C: nop

    Title_Matrix_Push(rdram, ctx);
        goto after_22;
    // 0x80187A0C: nop

    after_22:
    // 0x80187A10: jal         0x8018B038
    // 0x80187A14: nop

    Title_CsGreatFoxCloseUp_Draw(rdram, ctx);
        goto after_23;
    // 0x80187A14: nop

    after_23:
    // 0x80187A18: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187A1C: jal         0x80005740
    // 0x80187A20: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_24;
    // 0x80187A20: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_24:
    // 0x80187A24: b           L_80187A74
    // 0x80187A28: nop

        goto L_80187A74;
    // 0x80187A28: nop

L_80187A2C:
    // 0x80187A2C: jal         0x801918FC
    // 0x80187A30: nop

    Title_Matrix_Push(rdram, ctx);
        goto after_25;
    // 0x80187A30: nop

    after_25:
    // 0x80187A34: jal         0x8018C114
    // 0x80187A38: nop

    Title_CsTakeOff_Draw(rdram, ctx);
        goto after_26;
    // 0x80187A38: nop

    after_26:
    // 0x80187A3C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187A40: jal         0x80005740
    // 0x80187A44: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_27;
    // 0x80187A44: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_27:
    // 0x80187A48: jal         0x80190C9C
    // 0x80187A4C: nop

    Title_TitleCard_Draw(rdram, ctx);
        goto after_28;
    // 0x80187A4C: nop

    after_28:
    // 0x80187A50: b           L_80187A74
    // 0x80187A54: nop

        goto L_80187A74;
    // 0x80187A54: nop

L_80187A58:
    // 0x80187A58: jal         0x801918FC
    // 0x80187A5C: nop

    Title_Matrix_Push(rdram, ctx);
        goto after_29;
    // 0x80187A5C: nop

    after_29:
    // 0x80187A60: jal         0x8018CB90
    // 0x80187A64: nop

    Title_CsTakeOffSpace_Draw(rdram, ctx);
        goto after_30;
    // 0x80187A64: nop

    after_30:
    // 0x80187A68: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80187A6C: jal         0x80005740
    // 0x80187A70: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_31;
    // 0x80187A70: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_31:
L_80187A74:
    // 0x80187A74: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80187A78: lw          $a1, -0x7D7C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D7C);
    // 0x80187A7C: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187A80: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80187A84: beql        $a1, $zero, L_80187AB0
    if (ctx->r5 == 0) {
        // 0x80187A88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80187AB0;
    }
    goto skip_0;
    // 0x80187A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80187A8C: sw          $zero, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = 0;
    // 0x80187A90: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187A94: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80187A98: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187A9C: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x80187AA0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80187AA4: jal         0x80084688
    // 0x80187AA8: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    Wipe_Draw(rdram, ctx);
        goto after_32;
    // 0x80187AA8: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    after_32:
    // 0x80187AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80187AB0:
    // 0x80187AB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80187AB4: jr          $ra
    // 0x80187AB8: nop

    return;
    // 0x80187AB8: nop

;}
RECOMP_FUNC void Map_Texture_Sphere(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A07E8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x801A07EC: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x801A07F0: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x801A07F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801A07F8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x801A07FC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801A0800: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A0804: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801A0808: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801A080C: addiu       $t5, $zero, 0x30
    ctx->r13 = ADD32(0, 0X30);
    // 0x801A0810: addiu       $t4, $zero, 0x5F
    ctx->r12 = ADD32(0, 0X5F);
L_801A0814:
    // 0x801A0814: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x801A0818: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801A081C: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x801A0820: subu        $t6, $t4, $a1
    ctx->r14 = SUB32(ctx->r12, ctx->r5);
    // 0x801A0824: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801A0828: beq         $at, $zero, L_801A08D8
    if (ctx->r1 == 0) {
        // 0x801A082C: sll         $t7, $t7, 7
        ctx->r15 = S32(ctx->r15 << 7);
            goto L_801A08D8;
    }
    // 0x801A082C: sll         $t7, $t7, 7
    ctx->r15 = S32(ctx->r15 << 7);
    // 0x801A0830: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801A0834: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x801A0838: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A083C: addiu       $t8, $t8, 0xC0
    ctx->r24 = ADD32(ctx->r24, 0XC0);
    // 0x801A0840: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x801A0844: addiu       $t6, $zero, 0x23A0
    ctx->r14 = ADD32(0, 0X23A0);
    // 0x801A0848: subu        $a0, $t6, $t0
    ctx->r4 = SUB32(ctx->r14, ctx->r8);
    // 0x801A084C: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x801A0850: addu        $t7, $s0, $a0
    ctx->r15 = ADD32(ctx->r16, ctx->r4);
    // 0x801A0854: addu        $t9, $s0, $t0
    ctx->r25 = ADD32(ctx->r16, ctx->r8);
    // 0x801A0858: addu        $t1, $t9, $a1
    ctx->r9 = ADD32(ctx->r25, ctx->r5);
    // 0x801A085C: addu        $t2, $t7, $a1
    ctx->r10 = ADD32(ctx->r15, ctx->r5);
    // 0x801A0860: addu        $t3, $a0, $s1
    ctx->r11 = ADD32(ctx->r4, ctx->r17);
    // 0x801A0864: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
L_801A0868:
    // 0x801A0868: lw          $t6, -0x180($a2)
    ctx->r14 = MEM_W(ctx->r6, -0X180);
    // 0x801A086C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A0870: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x801A0874: nop

    // 0x801A0878: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x801A087C: slti        $at, $a0, 0x60
    ctx->r1 = SIGNED(ctx->r4) < 0X60 ? 1 : 0;
    // 0x801A0880: bne         $at, $zero, L_801A088C
    if (ctx->r1 != 0) {
        // 0x801A0884: nop
    
            goto L_801A088C;
    }
    // 0x801A0884: nop

    // 0x801A0888: addiu       $a0, $a0, -0x5F
    ctx->r4 = ADD32(ctx->r4, -0X5F);
L_801A088C:
    // 0x801A088C: bgezl       $a0, L_801A089C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801A0890: addu        $t7, $t0, $a0
        ctx->r15 = ADD32(ctx->r8, ctx->r4);
            goto L_801A089C;
    }
    goto skip_0;
    // 0x801A0890: addu        $t7, $t0, $a0
    ctx->r15 = ADD32(ctx->r8, ctx->r4);
    skip_0:
    // 0x801A0894: addiu       $a0, $a0, 0x5F
    ctx->r4 = ADD32(ctx->r4, 0X5F);
    // 0x801A0898: addu        $t7, $t0, $a0
    ctx->r15 = ADD32(ctx->r8, ctx->r4);
L_801A089C:
    // 0x801A089C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x801A08A0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x801A08A4: addu        $t6, $t3, $a0
    ctx->r14 = ADD32(ctx->r11, ctx->r4);
    // 0x801A08A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x801A08AC: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x801A08B0: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x801A08B4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x801A08B8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x801A08BC: sb          $t7, -0x1($t2)
    MEM_B(-0X1, ctx->r10) = ctx->r15;
    // 0x801A08C0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801A08C4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x801A08C8: subu        $t9, $t4, $t8
    ctx->r25 = SUB32(ctx->r12, ctx->r24);
    // 0x801A08CC: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801A08D0: bnel        $at, $zero, L_801A0868
    if (ctx->r1 != 0) {
        // 0x801A08D4: lwc1        $f4, 0x0($a3)
        ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
            goto L_801A0868;
    }
    goto skip_1;
    // 0x801A08D4: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    skip_1:
L_801A08D8:
    // 0x801A08D8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801A08DC: bne         $v1, $t5, L_801A0814
    if (ctx->r3 != ctx->r13) {
        // 0x801A08E0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_801A0814;
    }
    // 0x801A08E0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801A08E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A08E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A08EC: lwc1        $f8, 0x0($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801A08F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A08F4: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x801A08F8: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A08FC: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x801A0900: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801A0904: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x801A0908: nop

    // 0x801A090C: bc1fl       L_801A0928
    if (!c1cs) {
        // 0x801A0910: lui         $at, 0x42BE
        ctx->r1 = S32(0X42BE << 16);
            goto L_801A0928;
    }
    goto skip_2;
    // 0x801A0910: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    skip_2:
    // 0x801A0914: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A0918: nop

    // 0x801A091C: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x801A0920: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x801A0924: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
L_801A0928:
    // 0x801A0928: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A092C: nop

    // 0x801A0930: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801A0934: nop

    // 0x801A0938: bc1fl       L_801A0948
    if (!c1cs) {
        // 0x801A093C: lw          $s0, 0x8($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X8);
            goto L_801A0948;
    }
    goto skip_3;
    // 0x801A093C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    skip_3:
    // 0x801A0940: swc1        $f2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f2.u32l;
    // 0x801A0944: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
L_801A0948:
    // 0x801A0948: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x801A094C: jr          $ra
    // 0x801A0950: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x801A0950: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void Map_801A9DE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9DE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A9DEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A9DF0: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A9DF4: lw          $t6, -0x2688($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2688);
    // 0x801A9DF8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A9DFC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A9E00: bne         $t6, $zero, L_801A9E38
    if (ctx->r14 != 0) {
        // 0x801A9E04: addiu       $a0, $a0, -0xFF4
        ctx->r4 = ADD32(ctx->r4, -0XFF4);
            goto L_801A9E38;
    }
    // 0x801A9E04: addiu       $a0, $a0, -0xFF4
    ctx->r4 = ADD32(ctx->r4, -0XFF4);
    // 0x801A9E08: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
    // 0x801A9E0C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A9E10: beq         $v0, $at, L_801A9E38
    if (ctx->r2 == ctx->r1) {
        // 0x801A9E14: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_801A9E38;
    }
    // 0x801A9E14: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801A9E18: beq         $v0, $at, L_801A9E38
    if (ctx->r2 == ctx->r1) {
        // 0x801A9E1C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_801A9E38;
    }
    // 0x801A9E1C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A9E20: bne         $v0, $at, L_801A9ED4
    if (ctx->r2 != ctx->r1) {
        // 0x801A9E24: lui         $t7, 0x801D
        ctx->r15 = S32(0X801D << 16);
            goto L_801A9ED4;
    }
    // 0x801A9E24: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A9E28: lw          $t7, -0x26B8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26B8);
    // 0x801A9E2C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A9E30: bnel        $t7, $at, L_801A9ED8
    if (ctx->r15 != ctx->r1) {
        // 0x801A9E34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801A9ED8;
    }
    goto skip_0;
    // 0x801A9E34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_801A9E38:
    // 0x801A9E38: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x801A9E3C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x801A9E40: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801A9E44: beq         $v1, $zero, L_801A9E54
    if (ctx->r3 == 0) {
        // 0x801A9E48: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_801A9E54;
    }
    // 0x801A9E48: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x801A9E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801A9E50: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_801A9E54:
    // 0x801A9E54: lw          $t9, 0x7DB0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7DB0);
    // 0x801A9E58: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x801A9E5C: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x801A9E60: and         $t0, $t9, $v0
    ctx->r8 = ctx->r25 & ctx->r2;
    // 0x801A9E64: beq         $t0, $zero, L_801A9E88
    if (ctx->r8 == 0) {
        // 0x801A9E68: nop
    
            goto L_801A9E88;
    }
    // 0x801A9E68: nop

    // 0x801A9E6C: lw          $t1, 0x78A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X78A0);
    // 0x801A9E70: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x801A9E74: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x801A9E78: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x801A9E7C: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x801A9E80: jal         0x801AD7EC
    // 0x801A9E84: lh          $a2, 0x1AA0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1AA0);
    Map_RemainingLives_Draw(rdram, ctx);
        goto after_0;
    // 0x801A9E84: lh          $a2, 0x1AA0($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X1AA0);
    after_0:
L_801A9E88:
    // 0x801A9E88: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801A9E8C: lhu         $v0, 0x1A34($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1A34);
    // 0x801A9E90: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A9E94: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A9E98: beq         $v0, $at, L_801A9EA8
    if (ctx->r2 == ctx->r1) {
        // 0x801A9E9C: addiu       $v1, $v1, -0x27C4
        ctx->r3 = ADD32(ctx->r3, -0X27C4);
            goto L_801A9EA8;
    }
    // 0x801A9E9C: addiu       $v1, $v1, -0x27C4
    ctx->r3 = ADD32(ctx->r3, -0X27C4);
    // 0x801A9EA0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801A9EA4: bne         $v0, $at, L_801A9ED4
    if (ctx->r2 != ctx->r1) {
        // 0x801A9EA8: lui         $v0, 0x8016
        ctx->r2 = S32(0X8016 << 16);
            goto L_801A9ED4;
    }
L_801A9EA8:
    // 0x801A9EA8: lui         $v0, 0x8016
    ctx->r2 = S32(0X8016 << 16);
    // 0x801A9EAC: lw          $v0, 0x1714($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1714);
    // 0x801A9EB0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801A9EB4: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801A9EB8: beq         $at, $zero, L_801A9EC4
    if (ctx->r1 == 0) {
        // 0x801A9EBC: nop
    
            goto L_801A9EC4;
    }
    // 0x801A9EBC: nop

    // 0x801A9EC0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_801A9EC4:
    // 0x801A9EC4: jal         0x801A9EE4
    // 0x801A9EC8: nop

    Map_TotalHits_Draw(rdram, ctx);
        goto after_1;
    // 0x801A9EC8: nop

    after_1:
    // 0x801A9ECC: jal         0x801A9FD4
    // 0x801A9ED0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    Map_801A9FD4(rdram, ctx);
        goto after_2;
    // 0x801A9ED0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_801A9ED4:
    // 0x801A9ED4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A9ED8:
    // 0x801A9ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A9EDC: jr          $ra
    // 0x801A9EE0: nop

    return;
    // 0x801A9EE0: nop

;}
RECOMP_FUNC void Option_Data_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801962A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801962A8: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801962AC: addiu       $v1, $v1, -0x6ED4
    ctx->r3 = ADD32(ctx->r3, -0X6ED4);
    // 0x801962B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801962B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801962B8: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801962BC: beq         $v0, $zero, L_801962E8
    if (ctx->r2 == 0) {
        // 0x801962C0: nop
    
            goto L_801962E8;
    }
    // 0x801962C0: nop

    // 0x801962C4: beq         $v0, $t1, L_801962F8
    if (ctx->r2 == ctx->r9) {
        // 0x801962C8: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_801962F8;
    }
    // 0x801962C8: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801962CC: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801962D0: beq         $v0, $t2, L_80196330
    if (ctx->r2 == ctx->r10) {
        // 0x801962D4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80196330;
    }
    // 0x801962D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801962D8: beq         $v0, $at, L_80196378
    if (ctx->r2 == ctx->r1) {
        // 0x801962DC: lui         $a0, 0x801C
        ctx->r4 = S32(0X801C << 16);
            goto L_80196378;
    }
    // 0x801962DC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801962E0: b           L_80196690
    // 0x801962E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80196690;
    // 0x801962E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801962E8:
    // 0x801962E8: jal         0x8019669C
    // 0x801962EC: nop

    Option_Data_Select(rdram, ctx);
        goto after_0;
    // 0x801962EC: nop

    after_0:
    // 0x801962F0: b           L_80196690
    // 0x801962F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80196690;
    // 0x801962F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801962F8:
    // 0x801962F8: addiu       $a0, $a0, -0x6E40
    ctx->r4 = ADD32(ctx->r4, -0X6E40);
    // 0x801962FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80196300: lui         $t8, 0x801C
    ctx->r24 = S32(0X801C << 16);
    // 0x80196304: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80196308: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8019630C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80196310: lw          $t8, -0x6CD0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6CD0);
    // 0x80196314: addiu       $t0, $t0, -0x6E34
    ctx->r8 = ADD32(ctx->r8, -0X6E34);
    // 0x80196318: bnel        $t8, $zero, L_80196690
    if (ctx->r24 != 0) {
        // 0x8019631C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80196690;
    }
    goto skip_0;
    // 0x8019631C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80196320: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x80196324: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80196328: b           L_8019668C
    // 0x8019632C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8019668C;
    // 0x8019632C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80196330:
    // 0x80196330: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x80196334: addiu       $a0, $a0, -0x6E40
    ctx->r4 = ADD32(ctx->r4, -0X6E40);
    // 0x80196338: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8019633C: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80196340: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80196344: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80196348: lw          $t4, -0x6CD0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6CD0);
    // 0x8019634C: bne         $t4, $zero, L_8019668C
    if (ctx->r12 != 0) {
        // 0x80196350: lui         $at, 0x8017
        ctx->r1 = S32(0X8017 << 16);
            goto L_8019668C;
    }
    // 0x80196350: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196354: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80196358: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019635C: addiu       $t5, $zero, 0x3E8
    ctx->r13 = ADD32(0, 0X3E8);
    // 0x80196360: sw          $t5, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r13;
    // 0x80196364: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80196368: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019636C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80196370: b           L_8019668C
    // 0x80196374: sw          $t6, -0x6DBC($at)
    MEM_W(-0X6DBC, ctx->r1) = ctx->r14;
        goto L_8019668C;
    // 0x80196374: sw          $t6, -0x6DBC($at)
    MEM_W(-0X6DBC, ctx->r1) = ctx->r14;
L_80196378:
    // 0x80196378: addiu       $a0, $a0, -0x6E40
    ctx->r4 = ADD32(ctx->r4, -0X6E40);
    // 0x8019637C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80196380: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x80196384: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x80196388: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019638C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80196390: lw          $t9, -0x6CD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6CD0);
    // 0x80196394: addiu       $t0, $t0, -0x6E34
    ctx->r8 = ADD32(ctx->r8, -0X6E34);
    // 0x80196398: bnel        $t9, $zero, L_80196690
    if (ctx->r25 != 0) {
        // 0x8019639C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80196690;
    }
    goto skip_1;
    // 0x8019639C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801963A0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x801963A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801963A8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801963AC: beql        $v0, $zero, L_801963D8
    if (ctx->r2 == 0) {
        // 0x801963B0: sw          $t3, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r11;
            goto L_801963D8;
    }
    goto skip_2;
    // 0x801963B0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    skip_2:
    // 0x801963B4: beq         $v0, $at, L_801963E4
    if (ctx->r2 == ctx->r1) {
        // 0x801963B8: nop
    
            goto L_801963E4;
    }
    // 0x801963B8: nop

    // 0x801963BC: beq         $v0, $t1, L_80196448
    if (ctx->r2 == ctx->r9) {
        // 0x801963C0: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80196448;
    }
    // 0x801963C0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801963C4: beql        $v0, $t2, L_8019668C
    if (ctx->r2 == ctx->r10) {
        // 0x801963C8: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_8019668C;
    }
    goto skip_3;
    // 0x801963C8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    skip_3:
    // 0x801963CC: b           L_80196690
    // 0x801963D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80196690;
    // 0x801963D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801963D4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_801963D8:
    // 0x801963D8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x801963DC: b           L_8019668C
    // 0x801963E0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8019668C;
    // 0x801963E0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801963E4:
    // 0x801963E4: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801963E8: lui         $t4, 0x800C
    ctx->r12 = S32(0X800C << 16);
    // 0x801963EC: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801963F0: addiu       $t4, $t4, 0x5D3C
    ctx->r12 = ADD32(ctx->r12, 0X5D3C);
    // 0x801963F4: lui         $a0, 0x940
    ctx->r4 = S32(0X940 << 16);
    // 0x801963F8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801963FC: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x80196400: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80196404: ori         $a0, $a0, 0xA00B
    ctx->r4 = ctx->r4 | 0XA00B;
    // 0x80196408: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x8019640C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x80196410: jal         0x80019218
    // 0x80196414: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80196414: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x80196418: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019641C: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x80196420: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80196424: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80196428: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019642C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80196430: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80196434: swc1        $f4, 0x79A8($at)
    MEM_W(0X79A8, ctx->r1) = ctx->f4.u32l;
    // 0x80196438: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019643C: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80196440: b           L_8019668C
    // 0x80196444: sw          $zero, 0x7990($at)
    MEM_W(0X7990, ctx->r1) = 0;
        goto L_8019668C;
    // 0x80196444: sw          $zero, 0x7990($at)
    MEM_W(0X7990, ctx->r1) = 0;
L_80196448:
    // 0x80196448: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019644C: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x80196450: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x80196454: addiu       $t8, $t8, 0x79A8
    ctx->r24 = ADD32(ctx->r24, 0X79A8);
    // 0x80196458: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8019645C: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x80196460: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80196464: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x80196468: addiu       $t7, $t7, 0x7990
    ctx->r15 = ADD32(ctx->r15, 0X7990);
    // 0x8019646C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80196470: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80196474: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80196478: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019647C: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x80196480: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80196484: lui         $a2, 0x3D4C
    ctx->r6 = S32(0X3D4C << 16);
    // 0x80196488: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
    // 0x8019648C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80196490: lwc1        $f10, 0x73D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X73D8);
    // 0x80196494: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80196498: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019649C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801964A0: jal         0x8009BC2C
    // 0x801964A4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801964A4: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x801964A8: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x801964AC: lw          $v0, 0x7AF8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7AF8);
    // 0x801964B0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801964B4: addiu       $t7, $t7, 0x7990
    ctx->r15 = ADD32(ctx->r15, 0X7990);
    // 0x801964B8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801964BC: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x801964C0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x801964C4: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801964C8: addiu       $t0, $t0, -0x6E34
    ctx->r8 = ADD32(ctx->r8, -0X6E34);
    // 0x801964CC: slti        $at, $a0, 0x64
    ctx->r1 = SIGNED(ctx->r4) < 0X64 ? 1 : 0;
    // 0x801964D0: bne         $at, $zero, L_801964F0
    if (ctx->r1 != 0) {
        // 0x801964D4: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_801964F0;
    }
    // 0x801964D4: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x801964D8: addiu       $t8, $a0, -0x64
    ctx->r24 = ADD32(ctx->r4, -0X64);
    // 0x801964DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801964E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801964E4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x801964E8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801964EC: sb          $t3, 0x7E84($at)
    MEM_B(0X7E84, ctx->r1) = ctx->r11;
L_801964F0:
    // 0x801964F0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801964F4: lui         $t4, 0x800D
    ctx->r12 = S32(0X800D << 16);
    // 0x801964F8: addiu       $t4, $t4, 0x4D10
    ctx->r12 = ADD32(ctx->r12, 0X4D10);
    // 0x801964FC: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x80196500: lui         $t9, 0x8018
    ctx->r25 = S32(0X8018 << 16);
    // 0x80196504: addiu       $t9, $t9, -0x7790
    ctx->r25 = ADD32(ctx->r25, -0X7790);
    // 0x80196508: addiu       $t6, $t4, 0x1F8
    ctx->r14 = ADD32(ctx->r12, 0X1F8);
    // 0x8019650C: bc1fl       L_80196690
    if (!c1cs) {
        // 0x80196510: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80196690;
    }
    goto skip_4;
    // 0x80196510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80196514: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_80196518:
    // 0x80196518: lwl         $at, 0x0($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X0);
    // 0x8019651C: lwr         $at, 0x3($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0X3);
    // 0x80196520: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80196524: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80196528: sw          $at, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r1;
    // 0x8019652C: lwl         $at, -0x8($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, -0X8);
    // 0x80196530: lwr         $at, -0x5($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, -0X5);
    // 0x80196534: sw          $at, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r1;
    // 0x80196538: lwl         $at, -0x4($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, -0X4);
    // 0x8019653C: lwr         $at, -0x1($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, -0X1);
    // 0x80196540: bne         $t4, $t6, L_80196518
    if (ctx->r12 != ctx->r14) {
        // 0x80196544: sw          $at, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r1;
            goto L_80196518;
    }
    // 0x80196544: sw          $at, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r1;
    // 0x80196548: lwl         $at, 0x0($t4)
    ctx->r1 = do_lwl(rdram, ctx->r1, ctx->r12, 0X0);
    // 0x8019654C: lwl         $t6, 0x4($t4)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r12, 0X4);
    // 0x80196550: lwr         $at, 0x3($t4)
    ctx->r1 = do_lwr(rdram, ctx->r1, ctx->r12, 0X3);
    // 0x80196554: lwr         $t6, 0x7($t4)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r12, 0X7);
    // 0x80196558: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x8019655C: jal         0x800C3084
    // 0x80196560: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    Save_Write(rdram, ctx);
        goto after_3;
    // 0x80196560: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    after_3:
    // 0x80196564: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196568: sw          $zero, -0x6E54($at)
    MEM_W(-0X6E54, ctx->r1) = 0;
    // 0x8019656C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196570: sw          $zero, -0x6E50($at)
    MEM_W(-0X6E50, ctx->r1) = 0;
    // 0x80196574: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196578: sw          $zero, -0x6E38($at)
    MEM_W(-0X6E38, ctx->r1) = 0;
    // 0x8019657C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196580: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80196584: sw          $zero, 0x79F8($at)
    MEM_W(0X79F8, ctx->r1) = 0;
    // 0x80196588: addiu       $v0, $v0, -0x19C8
    ctx->r2 = ADD32(ctx->r2, -0X19C8);
    // 0x8019658C: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80196590: lui         $t5, 0x800
    ctx->r13 = S32(0X800 << 16);
    // 0x80196594: addiu       $t7, $t7, 0x3B50
    ctx->r15 = ADD32(ctx->r15, 0X3B50);
    // 0x80196598: addiu       $t8, $zero, 0x48
    ctx->r24 = ADD32(0, 0X48);
    // 0x8019659C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x801965A0: addiu       $t5, $t5, 0x46B0
    ctx->r13 = ADD32(ctx->r13, 0X46B0);
    // 0x801965A4: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x801965A8: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x801965AC: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x801965B0: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x801965B4: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x801965B8: sw          $t5, 0x188($v0)
    MEM_W(0X188, ctx->r2) = ctx->r13;
    // 0x801965BC: sw          $t6, 0x190($v0)
    MEM_W(0X190, ctx->r2) = ctx->r14;
    // 0x801965C0: sw          $t4, 0x194($v0)
    MEM_W(0X194, ctx->r2) = ctx->r12;
    // 0x801965C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801965C8: lwc1        $f18, -0x1A78($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1A78);
    // 0x801965CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801965D0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801965D4: swc1        $f18, -0x1A48($at)
    MEM_W(-0X1A48, ctx->r1) = ctx->f18.u32l;
    // 0x801965D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801965DC: lwc1        $f4, -0x1A60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1A60);
    // 0x801965E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801965E4: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x801965E8: swc1        $f4, -0x1A30($at)
    MEM_W(-0X1A30, ctx->r1) = ctx->f4.u32l;
    // 0x801965EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801965F0: lwc1        $f6, -0x1A74($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1A74);
    // 0x801965F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801965F8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801965FC: swc1        $f6, -0x1A44($at)
    MEM_W(-0X1A44, ctx->r1) = ctx->f6.u32l;
    // 0x80196600: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80196604: lwc1        $f8, -0x1A5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1A5C);
    // 0x80196608: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019660C: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x80196610: swc1        $f8, -0x1A2C($at)
    MEM_W(-0X1A2C, ctx->r1) = ctx->f8.u32l;
    // 0x80196614: addiu       $t7, $t7, -0x1A78
    ctx->r15 = ADD32(ctx->r15, -0X1A78);
    // 0x80196618: addiu       $t3, $t3, -0x1A60
    ctx->r11 = ADD32(ctx->r11, -0X1A60);
    // 0x8019661C: addu        $a0, $v0, $t7
    ctx->r4 = ADD32(ctx->r2, ctx->r15);
    // 0x80196620: addu        $a2, $v0, $t3
    ctx->r6 = ADD32(ctx->r2, ctx->r11);
    // 0x80196624: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80196628: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8019662C: lui         $t9, 0x801B
    ctx->r25 = S32(0X801B << 16);
    // 0x80196630: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x80196634: addiu       $t9, $t9, -0x1A48
    ctx->r25 = ADD32(ctx->r25, -0X1A48);
    // 0x80196638: addiu       $t8, $t8, -0x1A30
    ctx->r24 = ADD32(ctx->r24, -0X1A30);
    // 0x8019663C: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x80196640: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x80196644: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80196648: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8019664C: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80196650: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80196654: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80196658: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8019665C: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80196660: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80196664: swc1        $f16, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f16.u32l;
    // 0x80196668: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8019666C: swc1        $f4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f4.u32l;
    // 0x80196670: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x80196674: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x80196678: jal         0x80188010
    // 0x8019667C: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    Title_GetRankTotalHits(rdram, ctx);
        goto after_4;
    // 0x8019667C: swc1        $f6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f6.u32l;
    after_4:
    // 0x80196680: b           L_80196690
    // 0x80196684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80196690;
    // 0x80196684: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80196688: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8019668C:
    // 0x8019668C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80196690:
    // 0x80196690: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80196694: jr          $ra
    // 0x80196698: nop

    return;
    // 0x80196698: nop

;}
RECOMP_FUNC void Title_CsTeamRunning_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018A338: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8018A33C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8018A340: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    // 0x8018A344: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8018A348: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018A34C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018A350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018A354: lui         $ra, 0x801C
    ctx->r31 = S32(0X801C << 16);
    // 0x8018A358: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8018A35C: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8018A360: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018A364: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x8018A368: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x8018A36C: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x8018A370: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x8018A374: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8018A378: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8018A37C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018A380: addiu       $t5, $t5, -0x7954
    ctx->r13 = ADD32(ctx->r13, -0X7954);
    // 0x8018A384: addiu       $t4, $t4, -0x7958
    ctx->r12 = ADD32(ctx->r12, -0X7958);
    // 0x8018A388: addiu       $t3, $t3, -0x793C
    ctx->r11 = ADD32(ctx->r11, -0X793C);
    // 0x8018A38C: addiu       $t2, $t2, -0x7940
    ctx->r10 = ADD32(ctx->r10, -0X7940);
    // 0x8018A390: addiu       $t1, $t1, -0x7944
    ctx->r9 = ADD32(ctx->r9, -0X7944);
    // 0x8018A394: addiu       $a1, $a1, -0x7CD4
    ctx->r5 = ADD32(ctx->r5, -0X7CD4);
    // 0x8018A398: addiu       $v1, $v1, -0x7CD0
    ctx->r3 = ADD32(ctx->r3, -0X7CD0);
    // 0x8018A39C: addiu       $v0, $v0, -0x7CB0
    ctx->r2 = ADD32(ctx->r2, -0X7CB0);
    // 0x8018A3A0: addiu       $ra, $ra, -0x794C
    ctx->r31 = ADD32(ctx->r31, -0X794C);
    // 0x8018A3A4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018A3A8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8018A3AC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A3B0: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x8018A3B4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A3B8: sw          $a0, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r4;
    // 0x8018A3BC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A3C0: sw          $a0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r4;
    // 0x8018A3C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A3C8: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x8018A3CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A3D0: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x8018A3D4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018A3D8: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x8018A3DC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A3E0: sw          $zero, -0x7CBC($at)
    MEM_W(-0X7CBC, ctx->r1) = 0;
    // 0x8018A3E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A3E8: sw          $zero, -0x7CCC($at)
    MEM_W(-0X7CCC, ctx->r1) = 0;
    // 0x8018A3EC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A3F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018A3F4: sw          $t6, -0x7CC8($at)
    MEM_W(-0X7CC8, ctx->r1) = ctx->r14;
    // 0x8018A3F8: lui         $at, 0x431B
    ctx->r1 = S32(0X431B << 16);
    // 0x8018A3FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A400: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A404: addiu       $t7, $zero, 0x4C
    ctx->r15 = ADD32(0, 0X4C);
    // 0x8018A408: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8018A40C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8018A410: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x8018A414: addiu       $t9, $zero, 0x42
    ctx->r25 = ADD32(0, 0X42);
    // 0x8018A418: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8018A41C: swc1        $f16, -0x7CD8($at)
    MEM_W(-0X7CD8, ctx->r1) = ctx->f16.u32l;
    // 0x8018A420: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8018A424: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8018A428: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A42C: swc1        $f0, -0x7938($at)
    MEM_W(-0X7938, ctx->r1) = ctx->f0.u32l;
    // 0x8018A430: lui         $at, 0xC2B4
    ctx->r1 = S32(0XC2B4 << 16);
    // 0x8018A434: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A438: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A43C: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8018A440: swc1        $f8, -0x7934($at)
    MEM_W(-0X7934, ctx->r1) = ctx->f8.u32l;
    // 0x8018A444: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A448: sw          $t7, -0x7D08($at)
    MEM_W(-0X7D08, ctx->r1) = ctx->r15;
    // 0x8018A44C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A450: sw          $t8, -0x7D04($at)
    MEM_W(-0X7D04, ctx->r1) = ctx->r24;
    // 0x8018A454: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A458: sw          $t9, -0x7D00($at)
    MEM_W(-0X7D00, ctx->r1) = ctx->r25;
    // 0x8018A45C: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x8018A460: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018A464: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A468: addiu       $t7, $zero, 0x1D
    ctx->r15 = ADD32(0, 0X1D);
    // 0x8018A46C: swc1        $f10, -0x7CFC($at)
    MEM_W(-0X7CFC, ctx->r1) = ctx->f10.u32l;
    // 0x8018A470: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A474: swc1        $f18, -0x7CF8($at)
    MEM_W(-0X7CF8, ctx->r1) = ctx->f18.u32l;
    // 0x8018A478: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A47C: swc1        $f18, -0x7CF4($at)
    MEM_W(-0X7CF4, ctx->r1) = ctx->f18.u32l;
    // 0x8018A480: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018A484: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A488: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A48C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8018A490: swc1        $f4, -0x7B2C($at)
    MEM_W(-0X7B2C, ctx->r1) = ctx->f4.u32l;
    // 0x8018A494: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8018A498: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A49C: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x8018A4A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A4A4: lui         $at, 0xC351
    ctx->r1 = S32(0XC351 << 16);
    // 0x8018A4A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018A4AC: lui         $at, 0xC44D
    ctx->r1 = S32(0XC44D << 16);
    // 0x8018A4B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018A4B4: lui         $at, 0x4278
    ctx->r1 = S32(0X4278 << 16);
    // 0x8018A4B8: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8018A4BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A4C0: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8018A4C4: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8018A4C8: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x8018A4CC: sw          $t6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r14;
    // 0x8018A4D0: sw          $t0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r8;
    // 0x8018A4D4: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x8018A4D8: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    // 0x8018A4DC: swc1        $f2, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f2.u32l;
    // 0x8018A4E0: sw          $zero, 0xB8($v0)
    MEM_W(0XB8, ctx->r2) = 0;
    // 0x8018A4E4: sw          $t0, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r8;
    // 0x8018A4E8: swc1        $f0, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f0.u32l;
    // 0x8018A4EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A4F0: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x8018A4F4: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
    // 0x8018A4F8: swc1        $f4, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f4.u32l;
    // 0x8018A4FC: swc1        $f6, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f6.u32l;
    // 0x8018A500: lwc1        $f8, 0x6F0C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F0C);
    // 0x8018A504: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x8018A508: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018A50C: swc1        $f0, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->f0.u32l;
    // 0x8018A510: swc1        $f2, 0xD0($v0)
    MEM_W(0XD0, ctx->r2) = ctx->f2.u32l;
    // 0x8018A514: sw          $t7, 0x118($v0)
    MEM_W(0X118, ctx->r2) = ctx->r15;
    // 0x8018A518: sw          $t8, 0x11C($v0)
    MEM_W(0X11C, ctx->r2) = ctx->r24;
    // 0x8018A51C: swc1        $f0, 0x124($v0)
    MEM_W(0X124, ctx->r2) = ctx->f0.u32l;
    // 0x8018A520: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A524: swc1        $f8, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f8.u32l;
    // 0x8018A528: swc1        $f10, 0x120($v0)
    MEM_W(0X120, ctx->r2) = ctx->f10.u32l;
    // 0x8018A52C: lwc1        $f4, 0x6F10($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F10);
    // 0x8018A530: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x8018A534: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8018A538: swc1        $f0, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f0.u32l;
    // 0x8018A53C: swc1        $f2, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f2.u32l;
    // 0x8018A540: sw          $t9, 0x178($v0)
    MEM_W(0X178, ctx->r2) = ctx->r25;
    // 0x8018A544: sw          $t6, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = ctx->r14;
    // 0x8018A548: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A54C: swc1        $f4, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f4.u32l;
    // 0x8018A550: lwc1        $f6, 0x6F14($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F14);
    // 0x8018A554: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A558: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018A55C: swc1        $f6, -0x7B30($at)
    MEM_W(-0X7B30, ctx->r1) = ctx->f6.u32l;
    // 0x8018A560: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x8018A564: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A568: lui         $at, 0x42E8
    ctx->r1 = S32(0X42E8 << 16);
    // 0x8018A56C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018A570: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018A574: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x8018A578: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
    // 0x8018A57C: lwc1        $f4, 0x6F18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F18);
    // 0x8018A580: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x8018A584: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018A588: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x8018A58C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018A590: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8018A594: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8018A598: swc1        $f2, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f2.u32l;
    // 0x8018A59C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A5A0: swc1        $f4, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f4.u32l;
    // 0x8018A5A4: swc1        $f6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f6.u32l;
    // 0x8018A5A8: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x8018A5AC: swc1        $f10, -0x7948($at)
    MEM_W(-0X7948, ctx->r1) = ctx->f10.u32l;
    // 0x8018A5B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A5B4: swc1        $f0, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f0.u32l;
    // 0x8018A5B8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A5BC: swc1        $f18, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f18.u32l;
    // 0x8018A5C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018A5C4: swc1        $f0, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f0.u32l;
    // 0x8018A5C8: addiu       $t7, $t7, 0x7980
    ctx->r15 = ADD32(ctx->r15, 0X7980);
    // 0x8018A5CC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018A5D0: lwc1        $f8, 0x0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018A5D4: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8018A5D8: lwc1        $f4, 0x0($ra)
    ctx->f4.u32l = MEM_W(ctx->r31, 0X0);
    // 0x8018A5DC: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8018A5E0: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8018A5E4: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x8018A5E8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018A5EC: addiu       $t8, $t8, 0x7988
    ctx->r24 = ADD32(ctx->r24, 0X7988);
    // 0x8018A5F0: addiu       $t9, $t9, 0x79A0
    ctx->r25 = ADD32(ctx->r25, 0X79A0);
    // 0x8018A5F4: addiu       $t6, $t6, 0x79B8
    ctx->r14 = ADD32(ctx->r14, 0X79B8);
    // 0x8018A5F8: addiu       $t7, $t7, 0x79C0
    ctx->r15 = ADD32(ctx->r15, 0X79C0);
    // 0x8018A5FC: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8018A600: addiu       $a3, $a3, 0x7978
    ctx->r7 = ADD32(ctx->r7, 0X7978);
    // 0x8018A604: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018A608: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018A60C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018A610: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8018A614: lw          $a2, 0x0($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X0);
    // 0x8018A618: lwc1        $f14, 0x0($t2)
    ctx->f14.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8018A61C: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8018A620: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x8018A624: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8018A628: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8018A62C: jal         0x801914AC
    // 0x8018A630: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Title_SetCamUp2(rdram, ctx);
        goto after_0;
    // 0x8018A630: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8018A634: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018A638: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018A63C: jr          $ra
    // 0x8018A640: nop

    return;
    // 0x8018A640: nop

;}
RECOMP_FUNC void Option_VsTimeSelection(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019A4DC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8019A4E0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8019A4E4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8019A4E8: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8019A4EC: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8019A4F0: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8019A4F4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8019A4F8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8019A4FC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8019A500: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8019A504: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019A508: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019A50C: lw          $t6, -0x6C84($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6C84);
    // 0x8019A510: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019A514: addiu       $v1, $v1, -0x6E10
    ctx->r3 = ADD32(ctx->r3, -0X6E10);
    // 0x8019A518: bnel        $t6, $zero, L_8019A6B0
    if (ctx->r14 != 0) {
        // 0x8019A51C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8019A6B0;
    }
    goto skip_0;
    // 0x8019A51C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x8019A520: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8019A524: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019A528: addiu       $v0, $v0, -0x6ED4
    ctx->r2 = ADD32(ctx->r2, -0X6ED4);
    // 0x8019A52C: beq         $t7, $zero, L_8019A548
    if (ctx->r15 == 0) {
        // 0x8019A530: nop
    
            goto L_8019A548;
    }
    // 0x8019A530: nop

    // 0x8019A534: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8019A538: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8019A53C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019A540: b           L_8019A6AC
    // 0x8019A544: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_8019A6AC;
    // 0x8019A544: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8019A548:
    // 0x8019A548: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8019A54C: lui         $fp, 0x801C
    ctx->r30 = S32(0X801C << 16);
    // 0x8019A550: lui         $s6, 0x800C
    ctx->r22 = S32(0X800C << 16);
    // 0x8019A554: lui         $s5, 0x800C
    ctx->r21 = S32(0X800C << 16);
    // 0x8019A558: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x8019A55C: lui         $s3, 0x800C
    ctx->r19 = S32(0X800C << 16);
    // 0x8019A560: addiu       $s3, $s3, 0x5D34
    ctx->r19 = ADD32(ctx->r19, 0X5D34);
    // 0x8019A564: addiu       $s4, $s4, -0x6C24
    ctx->r20 = ADD32(ctx->r20, -0X6C24);
    // 0x8019A568: addiu       $s5, $s5, 0x5D28
    ctx->r21 = ADD32(ctx->r21, 0X5D28);
    // 0x8019A56C: addiu       $s6, $s6, 0x5D3C
    ctx->r22 = ADD32(ctx->r22, 0X5D3C);
    // 0x8019A570: addiu       $fp, $fp, -0x6C80
    ctx->r30 = ADD32(ctx->r30, -0X6C80);
    // 0x8019A574: addiu       $s2, $s2, -0x2750
    ctx->r18 = ADD32(ctx->r18, -0X2750);
    // 0x8019A578: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019A57C: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
L_8019A580:
    // 0x8019A580: lbu         $t0, 0x0($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X0);
    // 0x8019A584: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8019A588: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8019A58C: beq         $t0, $zero, L_8019A6A0
    if (ctx->r8 == 0) {
        // 0x8019A590: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8019A6A0;
    }
    // 0x8019A590: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019A594: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8019A598: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x8019A59C: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x8019A5A0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8019A5A4: addiu       $t6, $t6, -0x2768
    ctx->r14 = ADD32(ctx->r14, -0X2768);
    // 0x8019A5A8: addu        $t4, $fp, $t3
    ctx->r12 = ADD32(ctx->r30, ctx->r11);
    // 0x8019A5AC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8019A5B0: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8019A5B4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8019A5B8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8019A5BC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8019A5C0: addu        $s1, $t5, $t6
    ctx->r17 = ADD32(ctx->r13, ctx->r14);
    // 0x8019A5C4: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8019A5C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8019A5CC: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x8019A5D0: jal         0x8019C418
    // 0x8019A5D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    Option_Input_MoveCursor_Y(rdram, ctx);
        goto after_0;
    // 0x8019A5D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_0:
    // 0x8019A5D8: beq         $v0, $zero, L_8019A610
    if (ctx->r2 == 0) {
        // 0x8019A5DC: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8019A610;
    }
    // 0x8019A5DC: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A5E0: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019A5E4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A5E8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A5EC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A5F0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A5F4: jal         0x80019218
    // 0x8019A5F8: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x8019A5F8: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_1:
    // 0x8019A5FC: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8019A600: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A604: sw          $v0, -0x6CC0($at)
    MEM_W(-0X6CC0, ctx->r1) = ctx->r2;
    // 0x8019A608: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019A60C: sw          $v0, 0x78C8($at)
    MEM_W(0X78C8, ctx->r1) = ctx->r2;
L_8019A610:
    // 0x8019A610: lhu         $v0, 0x0($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X0);
    // 0x8019A614: andi        $t7, $v0, 0x8000
    ctx->r15 = ctx->r2 & 0X8000;
    // 0x8019A618: beq         $t7, $zero, L_8019A658
    if (ctx->r15 == 0) {
        // 0x8019A61C: andi        $t9, $v0, 0x4000
        ctx->r25 = ctx->r2 & 0X4000;
            goto L_8019A658;
    }
    // 0x8019A61C: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x8019A620: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A624: ori         $a0, $a0, 0x3
    ctx->r4 = ctx->r4 | 0X3;
    // 0x8019A628: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A62C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A630: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A634: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A638: jal         0x80019218
    // 0x8019A63C: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x8019A63C: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_2:
    // 0x8019A640: jal         0x8019A080
    // 0x8019A644: nop

    Option_8019A080(rdram, ctx);
        goto after_3;
    // 0x8019A644: nop

    after_3:
    // 0x8019A648: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8019A64C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A650: b           L_8019A6AC
    // 0x8019A654: sw          $t8, -0x6C84($at)
    MEM_W(-0X6C84, ctx->r1) = ctx->r24;
        goto L_8019A6AC;
    // 0x8019A654: sw          $t8, -0x6C84($at)
    MEM_W(-0X6C84, ctx->r1) = ctx->r24;
L_8019A658:
    // 0x8019A658: beq         $t9, $zero, L_8019A6A0
    if (ctx->r25 == 0) {
        // 0x8019A65C: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_8019A6A0;
    }
    // 0x8019A65C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x8019A660: ori         $a0, $a0, 0x101D
    ctx->r4 = ctx->r4 | 0X101D;
    // 0x8019A664: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8019A668: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8019A66C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8019A670: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8019A674: jal         0x80019218
    // 0x8019A678: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    Audio_PlaySfx(rdram, ctx);
        goto after_4;
    // 0x8019A678: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_4:
    // 0x8019A67C: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019A680: lw          $t0, -0x6C30($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6C30);
    // 0x8019A684: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A688: sw          $t0, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r8;
    // 0x8019A68C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019A690: jal         0x801924C4
    // 0x8019A694: sw          $zero, -0x6E3C($at)
    MEM_W(-0X6E3C, ctx->r1) = 0;
    Option_Entry_Setup(rdram, ctx);
        goto after_5;
    // 0x8019A694: sw          $zero, -0x6E3C($at)
    MEM_W(-0X6E3C, ctx->r1) = 0;
    after_5:
    // 0x8019A698: b           L_8019A6B0
    // 0x8019A69C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8019A6B0;
    // 0x8019A69C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8019A6A0:
    // 0x8019A6A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019A6A4: bne         $s0, $s7, L_8019A580
    if (ctx->r16 != ctx->r23) {
        // 0x8019A6A8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8019A580;
    }
    // 0x8019A6A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8019A6AC:
    // 0x8019A6AC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8019A6B0:
    // 0x8019A6B0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019A6B4: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8019A6B8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8019A6BC: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8019A6C0: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8019A6C4: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8019A6C8: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8019A6CC: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8019A6D0: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8019A6D4: jr          $ra
    // 0x8019A6D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8019A6D8: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Option_CardLightning_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019BF34: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8019BF38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8019BF3C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8019BF40: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8019BF44: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8019BF48: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8019BF4C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8019BF50: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8019BF54: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8019BF58: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x8019BF5C: lw          $t6, -0x6DEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6DEC);
    // 0x8019BF60: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x8019BF64: addiu       $s1, $s1, -0x6DFC
    ctx->r17 = ADD32(ctx->r17, -0X6DFC);
    // 0x8019BF68: beql        $t6, $zero, L_8019C028
    if (ctx->r14 == 0) {
        // 0x8019BF6C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8019C028;
    }
    goto skip_0;
    // 0x8019BF6C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x8019BF70: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8019BF74: jal         0x8019BDF0
    // 0x8019BF78: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    Option_Menu_Push(rdram, ctx);
        goto after_0;
    // 0x8019BF78: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8019BF7C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x8019BF80: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8019BF84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8019BF88: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x8019BF8C: lui         $s2, 0x801C
    ctx->r18 = S32(0X801C << 16);
    // 0x8019BF90: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019BF94: addiu       $s2, $s2, -0x6DF4
    ctx->r18 = ADD32(ctx->r18, -0X6DF4);
    // 0x8019BF98: addiu       $s3, $s3, -0x6DF0
    ctx->r19 = ADD32(ctx->r19, -0X6DF0);
    // 0x8019BF9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019BFA0: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_8019BFA4:
    // 0x8019BFA4: jal         0x80004EB0
    // 0x8019BFA8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x8019BFA8: nop

    after_1:
    // 0x8019BFAC: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8019BFB0: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x8019BFB4: jal         0x8019C04C
    // 0x8019BFB8: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    Option_CardLightning_Draw(rdram, ctx);
        goto after_2;
    // 0x8019BFB8: swc1        $f6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f6.u32l;
    after_2:
    // 0x8019BFBC: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8019BFC0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019BFC4: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x8019BFC8: bne         $s0, $s4, L_8019BFA4
    if (ctx->r16 != ctx->r20) {
        // 0x8019BFCC: swc1        $f10, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
            goto L_8019BFA4;
    }
    // 0x8019BFCC: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8019BFD0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019BFD4: jal         0x80005740
    // 0x8019BFD8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_3;
    // 0x8019BFD8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_3:
    // 0x8019BFDC: lwc1        $f16, 0x40($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8019BFE0: lui         $at, 0x41B8
    ctx->r1 = S32(0X41B8 << 16);
    // 0x8019BFE4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8019BFE8: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
    // 0x8019BFEC: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8019BFF0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019BFF4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8019BFF8: nop

    // 0x8019BFFC: bc1fl       L_8019C020
    if (!c1cs) {
        // 0x8019C000: swc1        $f2, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
            goto L_8019C020;
    }
    goto skip_1;
    // 0x8019C000: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
    skip_1:
    // 0x8019C004: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x8019C008: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019C00C: nop

    // 0x8019C010: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8019C014: b           L_8019C024
    // 0x8019C018: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
        goto L_8019C024;
    // 0x8019C018: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x8019C01C: swc1        $f2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f2.u32l;
L_8019C020:
    // 0x8019C020: sw          $zero, -0x6DEC($at)
    MEM_W(-0X6DEC, ctx->r1) = 0;
L_8019C024:
    // 0x8019C024: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8019C028:
    // 0x8019C028: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8019C02C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8019C030: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8019C034: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8019C038: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8019C03C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8019C040: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8019C044: jr          $ra
    // 0x8019C048: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8019C048: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Option_CardLightning_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C04C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019C050: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8019C054: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019C058: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019C05C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019C060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C064: jal         0x800B8DD0
    // 0x8019C068: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019C068: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    after_0:
    // 0x8019C06C: jal         0x800032B4
    // 0x8019C070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Lib_InitOrtho(rdram, ctx);
        goto after_1;
    // 0x8019C070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8019C074: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019C078: jal         0x80005708
    // 0x8019C07C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x8019C07C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_2:
    // 0x8019C080: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019C084: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019C088: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8019C08C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019C090: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019C094: lw          $a2, -0x6DF8($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6DF8);
    // 0x8019C098: lw          $a1, -0x6DFC($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6DFC);
    // 0x8019C09C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019C0A0: jal         0x80005B00
    // 0x8019C0A4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_3;
    // 0x8019C0A4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_3:
    // 0x8019C0A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019C0AC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019C0B0: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8019C0B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019C0B8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019C0BC: lw          $a2, -0x6DF0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6DF0);
    // 0x8019C0C0: lw          $a1, -0x6DF4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6DF4);
    // 0x8019C0C4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8019C0C8: jal         0x80005C34
    // 0x8019C0CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_4;
    // 0x8019C0CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_4:
    // 0x8019C0D0: jal         0x80006EB8
    // 0x8019C0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x8019C0D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8019C0D8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8019C0DC: lui         $t0, 0x801
    ctx->r8 = S32(0X801 << 16);
    // 0x8019C0E0: addiu       $t0, $t0, 0x5DF0
    ctx->r8 = ADD32(ctx->r8, 0X5DF0);
    // 0x8019C0E4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8019C0E8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8019C0EC: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8019C0F0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8019C0F4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8019C0F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8019C0FC: jal         0x80005740
    // 0x8019C100: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x8019C100: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x8019C104: jal         0x8000316C
    // 0x8019C108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Lib_InitPerspective(rdram, ctx);
        goto after_7;
    // 0x8019C108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8019C10C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8019C110: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8019C114: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8019C118: jr          $ra
    // 0x8019C11C: nop

    return;
    // 0x8019C11C: nop

;}
RECOMP_FUNC void Map_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A01A8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801A01AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801A01B0: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801A01B4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801A01B8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801A01BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A01C0: jal         0x80005708
    // 0x801A01C4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801A01C4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x801A01C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A01CC: lwc1        $f4, -0x2600($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2600);
    // 0x801A01D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A01D4: lwc1        $f6, -0x25FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25FC);
    // 0x801A01D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A01DC: lwc1        $f8, -0x25F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X25F8);
    // 0x801A01E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A01E4: lwc1        $f10, -0x25E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x801A01E8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A01EC: lwc1        $f16, -0x25DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x801A01F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A01F4: lwc1        $f18, -0x25D8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25D8);
    // 0x801A01F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A01FC: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A0200: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A0204: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A0208: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801A020C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801A0210: lw          $a3, -0x2604($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X2604);
    // 0x801A0214: lw          $a2, -0x2608($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2608);
    // 0x801A0218: lw          $a1, -0x260C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X260C);
    // 0x801A021C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801A0220: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x801A0224: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x801A0228: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x801A022C: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x801A0230: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x801A0234: jal         0x80006E3C
    // 0x801A0238: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x801A0238: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x801A023C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A0240: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A0244: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A0248: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801A024C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A0250: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A0254: lw          $a3, -0x15A0($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X15A0);
    // 0x801A0258: lw          $a2, -0x15A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X15A4);
    // 0x801A025C: lw          $a1, -0x15A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X15A8);
    // 0x801A0260: jal         0x80005B00
    // 0x801A0264: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801A0264: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801A0268: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A026C: jal         0x80006EB8
    // 0x801A0270: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x801A0270: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_3:
    // 0x801A0274: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A0278: lw          $t8, -0x268C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X268C);
    // 0x801A027C: beq         $t8, $zero, L_801A02F8
    if (ctx->r24 == 0) {
        // 0x801A0280: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_801A02F8;
    }
    // 0x801A0280: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A0284: lw          $t9, -0x26BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26BC);
    // 0x801A0288: lui         $s2, 0x8017
    ctx->r18 = S32(0X8017 << 16);
    // 0x801A028C: addiu       $s2, $s2, 0x7BD8
    ctx->r18 = ADD32(ctx->r18, 0X7BD8);
    // 0x801A0290: beq         $t9, $zero, L_801A02F8
    if (ctx->r25 == 0) {
        // 0x801A0294: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_801A02F8;
    }
    // 0x801A0294: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_801A0298:
    // 0x801A0298: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x801A029C: sll         $t1, $s0, 3
    ctx->r9 = S32(ctx->r16 << 3);
    // 0x801A02A0: subu        $t1, $t1, $s0
    ctx->r9 = SUB32(ctx->r9, ctx->r16);
    // 0x801A02A4: beq         $t0, $zero, L_801A02E8
    if (ctx->r8 == 0) {
        // 0x801A02A8: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_801A02E8;
    }
    // 0x801A02A8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x801A02AC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x801A02B0: addiu       $t2, $t2, -0x2E8
    ctx->r10 = ADD32(ctx->r10, -0X2E8);
    // 0x801A02B4: addu        $s1, $t1, $t2
    ctx->r17 = ADD32(ctx->r9, ctx->r10);
    // 0x801A02B8: lw          $t3, 0x18($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X18);
    // 0x801A02BC: beql        $t3, $zero, L_801A02EC
    if (ctx->r11 == 0) {
        // 0x801A02C0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801A02EC;
    }
    goto skip_0;
    // 0x801A02C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801A02C4: jal         0x801AC9A0
    // 0x801A02C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_PathLines_Draw(rdram, ctx);
        goto after_4;
    // 0x801A02C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801A02CC: lw          $t4, 0x14($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X14);
    // 0x801A02D0: beq         $t4, $zero, L_801A02E0
    if (ctx->r12 == 0) {
        // 0x801A02D4: nop
    
            goto L_801A02E0;
    }
    // 0x801A02D4: nop

    // 0x801A02D8: jal         0x801AC200
    // 0x801A02DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Map_Path_Draw(rdram, ctx);
        goto after_5;
    // 0x801A02DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_801A02E0:
    // 0x801A02E0: jal         0x80060D94
    // 0x801A02E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    TexturedLine_DrawPath(rdram, ctx);
        goto after_6;
    // 0x801A02E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_801A02E8:
    // 0x801A02E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801A02EC:
    // 0x801A02EC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x801A02F0: bne         $s0, $at, L_801A0298
    if (ctx->r16 != ctx->r1) {
        // 0x801A02F4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_801A0298;
    }
    // 0x801A02F4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_801A02F8:
    // 0x801A02F8: jal         0x801A8F40
    // 0x801A02FC: nop

    Map_Cursor_draw(rdram, ctx);
        goto after_7;
    // 0x801A02FC: nop

    after_7:
    // 0x801A0300: jal         0x801A9224
    // 0x801A0304: nop

    Map_MeteoMeteors_Draw(rdram, ctx);
        goto after_8;
    // 0x801A0304: nop

    after_8:
    // 0x801A0308: jal         0x801A9448
    // 0x801A030C: nop

    Map_Area6Ships_Draw(rdram, ctx);
        goto after_9;
    // 0x801A030C: nop

    after_9:
    // 0x801A0310: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801A0314: addiu       $s1, $s1, -0x2760
    ctx->r17 = ADD32(ctx->r17, -0X2760);
    // 0x801A0318: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801A031C: addiu       $s2, $zero, 0xF
    ctx->r18 = ADD32(0, 0XF);
L_801A0320:
    // 0x801A0320: jal         0x801A6A98
    // 0x801A0324: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Map_Planet_Draw(rdram, ctx);
        goto after_10;
    // 0x801A0324: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x801A0328: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A032C: bne         $s0, $s2, L_801A0320
    if (ctx->r16 != ctx->r18) {
        // 0x801A0330: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801A0320;
    }
    // 0x801A0330: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801A0334: jal         0x801A8738
    // 0x801A0338: nop

    Map_CorneriaExplosion_Draw(rdram, ctx);
        goto after_11;
    // 0x801A0338: nop

    after_11:
    // 0x801A033C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A0340: jal         0x80005740
    // 0x801A0344: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x801A0344: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_12:
    // 0x801A0348: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A034C: lw          $t5, -0x2694($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2694);
    // 0x801A0350: beq         $t5, $zero, L_801A0360
    if (ctx->r13 == 0) {
        // 0x801A0354: nop
    
            goto L_801A0360;
    }
    // 0x801A0354: nop

    // 0x801A0358: jal         0x801ABF1C
    // 0x801A035C: nop

    Map_GralPepperFace_Draw(rdram, ctx);
        goto after_13;
    // 0x801A035C: nop

    after_13:
L_801A0360:
    // 0x801A0360: jal         0x801AB300
    // 0x801A0364: nop

    Map_BriefingRadio_Update(rdram, ctx);
        goto after_14;
    // 0x801A0364: nop

    after_14:
    // 0x801A0368: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A036C: lw          $t6, -0x103C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X103C);
    // 0x801A0370: beq         $t6, $zero, L_801A0380
    if (ctx->r14 == 0) {
        // 0x801A0374: nop
    
            goto L_801A0380;
    }
    // 0x801A0374: nop

    // 0x801A0378: jal         0x801A5834
    // 0x801A037C: nop

    Map_PathChange_DrawOptions(rdram, ctx);
        goto after_15;
    // 0x801A037C: nop

    after_15:
L_801A0380:
    // 0x801A0380: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A0384: lw          $t7, -0x269C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X269C);
    // 0x801A0388: beq         $t7, $zero, L_801A0398
    if (ctx->r15 == 0) {
        // 0x801A038C: nop
    
            goto L_801A0398;
    }
    // 0x801A038C: nop

    // 0x801A0390: jal         0x801A9910
    // 0x801A0394: nop

    Map_TitleCards_Draw(rdram, ctx);
        goto after_16;
    // 0x801A0394: nop

    after_16:
L_801A0398:
    // 0x801A0398: jal         0x801A9814
    // 0x801A039C: nop

    Map_Wipe_Draw(rdram, ctx);
        goto after_17;
    // 0x801A039C: nop

    after_17:
    // 0x801A03A0: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A03A4: lw          $t8, -0x2698($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2698);
    // 0x801A03A8: beq         $t8, $zero, L_801A03B8
    if (ctx->r24 == 0) {
        // 0x801A03AC: nop
    
            goto L_801A03B8;
    }
    // 0x801A03AC: nop

    // 0x801A03B0: jal         0x801A9A8C
    // 0x801A03B4: nop

    Map_801A9A8C(rdram, ctx);
        goto after_18;
    // 0x801A03B4: nop

    after_18:
L_801A03B8:
    // 0x801A03B8: jal         0x801A9DE8
    // 0x801A03BC: nop

    Map_801A9DE8(rdram, ctx);
        goto after_19;
    // 0x801A03BC: nop

    after_19:
    // 0x801A03C0: jal         0x801A5C90
    // 0x801A03C4: nop

    Map_RestartLevelLifeDown_Draw(rdram, ctx);
        goto after_20;
    // 0x801A03C4: nop

    after_20:
    // 0x801A03C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A03CC: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
    // 0x801A03D0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A03D4: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A03D8: bne         $v0, $at, L_801A0400
    if (ctx->r2 != ctx->r1) {
        // 0x801A03DC: nop
    
            goto L_801A0400;
    }
    // 0x801A03DC: nop

    // 0x801A03E0: lw          $t9, -0x26B8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26B8);
    // 0x801A03E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A03E8: bne         $t9, $at, L_801A0400
    if (ctx->r25 != ctx->r1) {
        // 0x801A03EC: nop
    
            goto L_801A0400;
    }
    // 0x801A03EC: nop

    // 0x801A03F0: jal         0x801A4650
    // 0x801A03F4: nop

    Map_GameOver_Draw(rdram, ctx);
        goto after_21;
    // 0x801A03F4: nop

    after_21:
    // 0x801A03F8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A03FC: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A0400:
    // 0x801A0400: bnel        $v0, $zero, L_801A041C
    if (ctx->r2 != 0) {
        // 0x801A0404: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A041C;
    }
    goto skip_1;
    // 0x801A0404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_1:
    // 0x801A0408: jal         0x801A0D14
    // 0x801A040C: nop

    Map_Prologue_Draw(rdram, ctx);
        goto after_22;
    // 0x801A040C: nop

    after_22:
    // 0x801A0410: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A0414: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
    // 0x801A0418: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_801A041C:
    // 0x801A041C: bne         $v0, $at, L_801A042C
    if (ctx->r2 != ctx->r1) {
        // 0x801A0420: nop
    
            goto L_801A042C;
    }
    // 0x801A0420: nop

    // 0x801A0424: jal         0x801A19A8
    // 0x801A0428: nop

    Map_LylatCard_Draw(rdram, ctx);
        goto after_23;
    // 0x801A0428: nop

    after_23:
L_801A042C:
    // 0x801A042C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A0430: addiu       $s0, $s0, -0x1138
    ctx->r16 = ADD32(ctx->r16, -0X1138);
    // 0x801A0434: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801A0438: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x801A043C: addiu       $s2, $s2, 0x68B0
    ctx->r18 = ADD32(ctx->r18, 0X68B0);
    // 0x801A0440: bne         $v0, $zero, L_801A0498
    if (ctx->r2 != 0) {
        // 0x801A0444: lui         $at, 0xFF
        ctx->r1 = S32(0XFF << 16);
            goto L_801A0498;
    }
    // 0x801A0444: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801A0448: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A044C: lw          $v0, 0x68F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68F4);
    // 0x801A0450: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x801A0454: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801A0458: sll         $t1, $v0, 4
    ctx->r9 = S32(ctx->r2 << 4);
    // 0x801A045C: srl         $t2, $t1, 28
    ctx->r10 = S32(U32(ctx->r9) >> 28);
    // 0x801A0460: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801A0464: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x801A0468: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x801A046C: and         $t0, $v0, $at
    ctx->r8 = ctx->r2 & ctx->r1;
    // 0x801A0470: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A0474: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801A0478: addu        $a1, $t0, $t4
    ctx->r5 = ADD32(ctx->r8, ctx->r12);
    // 0x801A047C: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x801A0480: addiu       $a2, $a2, -0x27C8
    ctx->r6 = ADD32(ctx->r6, -0X27C8);
    // 0x801A0484: jal         0x801A07E8
    // 0x801A0488: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    Map_Texture_Sphere(rdram, ctx);
        goto after_24;
    // 0x801A0488: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    after_24:
    // 0x801A048C: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x801A0490: b           L_801A04A8
    // 0x801A0494: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_801A04A8;
    // 0x801A0494: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_801A0498:
    // 0x801A0498: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801A049C: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x801A04A0: addiu       $s2, $s2, 0x68B0
    ctx->r18 = ADD32(ctx->r18, 0X68B0);
    // 0x801A04A4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
L_801A04A8:
    // 0x801A04A8: lui         $s1, 0x801D
    ctx->r17 = S32(0X801D << 16);
    // 0x801A04AC: addiu       $s1, $s1, -0x113C
    ctx->r17 = ADD32(ctx->r17, -0X113C);
    // 0x801A04B0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801A04B4: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A04B8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x801A04BC: sll         $s0, $t7, 3
    ctx->r16 = S32(ctx->r15 << 3);
    // 0x801A04C0: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x801A04C4: lw          $v0, 0x68D4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68D4);
    // 0x801A04C8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801A04CC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801A04D0: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x801A04D4: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x801A04D8: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x801A04DC: addu        $t4, $t4, $t0
    ctx->r12 = ADD32(ctx->r12, ctx->r8);
    // 0x801A04E0: lw          $t4, 0x1FD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1FD0);
    // 0x801A04E4: and         $t1, $v0, $at
    ctx->r9 = ctx->r2 & ctx->r1;
    // 0x801A04E8: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A04EC: addiu       $t5, $t5, -0x27E8
    ctx->r13 = ADD32(ctx->r13, -0X27E8);
    // 0x801A04F0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A04F4: addu        $t9, $s2, $s0
    ctx->r25 = ADD32(ctx->r18, ctx->r16);
    // 0x801A04F8: addu        $a1, $t1, $t4
    ctx->r5 = ADD32(ctx->r9, ctx->r12);
    // 0x801A04FC: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x801A0500: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x801A0504: jal         0x801A07E8
    // 0x801A0508: addu        $a2, $s0, $t5
    ctx->r6 = ADD32(ctx->r16, ctx->r13);
    Map_Texture_Sphere(rdram, ctx);
        goto after_25;
    // 0x801A0508: addu        $a2, $s0, $t5
    ctx->r6 = ADD32(ctx->r16, ctx->r13);
    after_25:
    // 0x801A050C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801A0510: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A0514: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x801A0518: sll         $s0, $t6, 3
    ctx->r16 = S32(ctx->r14 << 3);
    // 0x801A051C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x801A0520: lw          $v0, 0x68D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68D8);
    // 0x801A0524: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x801A0528: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x801A052C: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x801A0530: srl         $t3, $t2, 28
    ctx->r11 = S32(U32(ctx->r10) >> 28);
    // 0x801A0534: sll         $t0, $t3, 2
    ctx->r8 = S32(ctx->r11 << 2);
    // 0x801A0538: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x801A053C: lw          $t1, 0x1FD0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1FD0);
    // 0x801A0540: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x801A0544: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A0548: addiu       $t5, $t5, -0x27E8
    ctx->r13 = ADD32(ctx->r13, -0X27E8);
    // 0x801A054C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A0550: addu        $t8, $s2, $s0
    ctx->r24 = ADD32(ctx->r18, ctx->r16);
    // 0x801A0554: addiu       $t4, $s0, 0x4
    ctx->r12 = ADD32(ctx->r16, 0X4);
    // 0x801A0558: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x801A055C: addu        $a1, $a1, $at
    ctx->r5 = ADD32(ctx->r5, ctx->r1);
    // 0x801A0560: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x801A0564: jal         0x801A07E8
    // 0x801A0568: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    Map_Texture_Sphere(rdram, ctx);
        goto after_26;
    // 0x801A0568: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    after_26:
    // 0x801A056C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801A0570: lui         $a0, 0x604
    ctx->r4 = S32(0X604 << 16);
    // 0x801A0574: addiu       $a0, $a0, 0x7F80
    ctx->r4 = ADD32(ctx->r4, 0X7F80);
    // 0x801A0578: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801A057C: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x801A0580: bne         $at, $zero, L_801A058C
    if (ctx->r1 != 0) {
        // 0x801A0584: sw          $t7, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r15;
            goto L_801A058C;
    }
    // 0x801A0584: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801A0588: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_801A058C:
    // 0x801A058C: lui         $a1, 0x605
    ctx->r5 = S32(0X605 << 16);
    // 0x801A0590: addiu       $a1, $a1, -0x7080
    ctx->r5 = ADD32(ctx->r5, -0X7080);
    // 0x801A0594: jal         0x80099E28
    // 0x801A0598: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    Lib_Texture_Mottle(rdram, ctx);
        goto after_27;
    // 0x801A0598: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_27:
    // 0x801A059C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801A05A0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801A05A4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801A05A8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801A05AC: jr          $ra
    // 0x801A05B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801A05B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Map_GralPepperFace_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801ABF1C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801ABF20: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x801ABF24: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801ABF28: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801ABF2C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801ABF30: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x801ABF34: jal         0x80005708
    // 0x801ABF38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801ABF38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x801ABF3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801ABF40: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x801ABF44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801ABF48: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801ABF4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801ABF50: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801ABF54: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801ABF58: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801ABF5C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801ABF60: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801ABF64: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801ABF68: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x801ABF6C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x801ABF70: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801ABF74: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801ABF78: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801ABF7C: jal         0x80006E3C
    // 0x801ABF80: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x801ABF80: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801ABF84: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801ABF88: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801ABF8C: jal         0x80006EB8
    // 0x801ABF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x801ABF90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801ABF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801ABF98: jal         0x800B8DD0
    // 0x801ABF9C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801ABF9C: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_3:
    // 0x801ABFA0: jal         0x80005708
    // 0x801ABFA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_4;
    // 0x801ABFA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x801ABFA8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801ABFAC: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801ABFB0: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801ABFB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801ABFB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801ABFBC: lw          $a3, -0x1570($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1570);
    // 0x801ABFC0: lw          $a2, -0x1574($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X1574);
    // 0x801ABFC4: lw          $a1, -0x1578($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1578);
    // 0x801ABFC8: jal         0x80005B00
    // 0x801ABFCC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_5;
    // 0x801ABFCC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x801ABFD0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801ABFD4: lwc1        $f8, 0x7B18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B18);
    // 0x801ABFD8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801ABFDC: lwc1        $f10, -0x156C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X156C);
    // 0x801ABFE0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801ABFE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801ABFE8: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801ABFEC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801ABFF0: jal         0x80005E90
    // 0x801ABFF4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_6;
    // 0x801ABFF4: nop

    after_6:
    // 0x801ABFF8: jal         0x801AD048
    // 0x801ABFFC: nop

    Map_CamMatrixRot(rdram, ctx);
        goto after_7;
    // 0x801ABFFC: nop

    after_7:
    // 0x801AC000: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801AC004: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801AC008: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801AC00C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801AC010: lw          $a2, -0x1584($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X1584);
    // 0x801AC014: lw          $a1, -0x1588($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1588);
    // 0x801AC018: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801AC01C: jal         0x80005C34
    // 0x801AC020: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x801AC020: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_8:
    // 0x801AC024: jal         0x80006EB8
    // 0x801AC028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x801AC028: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801AC02C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC030: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x801AC034: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801AC038: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AC03C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801AC040: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801AC044: lw          $t1, -0x27F0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X27F0);
    // 0x801AC048: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801AC04C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801AC050: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x801AC054: lw          $t3, -0x5D0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5D0);
    // 0x801AC058: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801AC05C: jal         0x80006EB8
    // 0x801AC060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_10;
    // 0x801AC060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x801AC064: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC068: lui         $t6, 0x606
    ctx->r14 = S32(0X606 << 16);
    // 0x801AC06C: addiu       $t6, $t6, -0x5EE0
    ctx->r14 = ADD32(ctx->r14, -0X5EE0);
    // 0x801AC070: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801AC074: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801AC078: lui         $t5, 0x600
    ctx->r13 = S32(0X600 << 16);
    // 0x801AC07C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801AC080: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801AC084: jal         0x80005740
    // 0x801AC088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_11;
    // 0x801AC088: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x801AC08C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AC090: jal         0x800B8DD0
    // 0x801AC094: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_12;
    // 0x801AC094: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_12:
    // 0x801AC098: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC09C: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801AC0A0: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801AC0A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AC0A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801AC0AC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AC0B0: lw          $t9, -0x1568($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1568);
    // 0x801AC0B4: lui         $at, 0x2020
    ctx->r1 = S32(0X2020 << 16);
    // 0x801AC0B8: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x801AC0BC: andi        $t0, $t9, 0xFF
    ctx->r8 = ctx->r25 & 0XFF;
    // 0x801AC0C0: or          $t1, $t0, $at
    ctx->r9 = ctx->r8 | ctx->r1;
    // 0x801AC0C4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801AC0C8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC0CC: lui         $t4, 0xCFCF
    ctx->r12 = S32(0XCFCF << 16);
    // 0x801AC0D0: ori         $t4, $t4, 0xFF00
    ctx->r12 = ctx->r12 | 0XFF00;
    // 0x801AC0D4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801AC0D8: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801AC0DC: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x801AC0E0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801AC0E4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801AC0E8: jal         0x80005708
    // 0x801AC0EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Push(rdram, ctx);
        goto after_13;
    // 0x801AC0EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x801AC0F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AC0F4: lwc1        $f18, -0x1574($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1574);
    // 0x801AC0F8: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x801AC0FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AC100: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801AC104: lui         $a3, 0x801D
    ctx->r7 = S32(0X801D << 16);
    // 0x801AC108: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801AC10C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801AC110: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801AC114: lw          $a3, -0x1570($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X1570);
    // 0x801AC118: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801AC11C: lw          $a1, -0x1578($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1578);
    // 0x801AC120: jal         0x80005B00
    // 0x801AC124: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_14;
    // 0x801AC124: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_14:
    // 0x801AC128: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AC12C: lwc1        $f8, 0x7B1C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B1C);
    // 0x801AC130: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AC134: lwc1        $f10, -0x156C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X156C);
    // 0x801AC138: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801AC13C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AC140: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801AC144: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801AC148: jal         0x80005E90
    // 0x801AC14C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_15;
    // 0x801AC14C: nop

    after_15:
    // 0x801AC150: jal         0x801AD048
    // 0x801AC154: nop

    Map_CamMatrixRot(rdram, ctx);
        goto after_16;
    // 0x801AC154: nop

    after_16:
    // 0x801AC158: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801AC15C: lui         $a2, 0x801D
    ctx->r6 = S32(0X801D << 16);
    // 0x801AC160: lui         $a3, 0x4053
    ctx->r7 = S32(0X4053 << 16);
    // 0x801AC164: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801AC168: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801AC16C: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x801AC170: lw          $a2, -0x157C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X157C);
    // 0x801AC174: lw          $a1, -0x1580($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X1580);
    // 0x801AC178: jal         0x80005C34
    // 0x801AC17C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_17;
    // 0x801AC17C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_17:
    // 0x801AC180: jal         0x80006EB8
    // 0x801AC184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_18;
    // 0x801AC184: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x801AC188: addiu       $a3, $zero, 0x2000
    ctx->r7 = ADD32(0, 0X2000);
    // 0x801AC18C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC190: lui         $t8, 0xB600
    ctx->r24 = S32(0XB600 << 16);
    // 0x801AC194: lui         $t0, 0x600
    ctx->r8 = S32(0X600 << 16);
    // 0x801AC198: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801AC19C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801AC1A0: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x801AC1A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801AC1A8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC1AC: lui         $t1, 0x605
    ctx->r9 = S32(0X605 << 16);
    // 0x801AC1B0: addiu       $t1, $t1, -0x3CB0
    ctx->r9 = ADD32(ctx->r9, -0X3CB0);
    // 0x801AC1B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AC1B8: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801AC1BC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801AC1C0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801AC1C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC1C8: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x801AC1CC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801AC1D0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801AC1D4: sw          $a3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r7;
    // 0x801AC1D8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801AC1DC: jal         0x80005740
    // 0x801AC1E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_19;
    // 0x801AC1E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
    // 0x801AC1E4: jal         0x80005740
    // 0x801AC1E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x801AC1E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_20:
    // 0x801AC1EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801AC1F0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x801AC1F4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x801AC1F8: jr          $ra
    // 0x801AC1FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801AC1FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Map_PlanetAnim2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6EC0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801A6EC4: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801A6EC8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A6ECC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801A6ED0: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801A6ED4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801A6ED8: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x801A6EDC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x801A6EE0: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x801A6EE4: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x801A6EE8: jal         0x80005708
    // 0x801A6EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801A6EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801A6EF0: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x801A6EF4: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A6EF8: addiu       $t7, $t7, -0x25A0
    ctx->r15 = ADD32(ctx->r15, -0X25A0);
    // 0x801A6EFC: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x801A6F00: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x801A6F04: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x801A6F08: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x801A6F0C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6F10: jal         0x80005754
    // 0x801A6F14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_Mult(rdram, ctx);
        goto after_1;
    // 0x801A6F14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801A6F18: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x801A6F1C: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801A6F20: addiu       $t0, $t0, -0xB60
    ctx->r8 = ADD32(ctx->r8, -0XB60);
    // 0x801A6F24: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801A6F28: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801A6F2C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A6F30: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x801A6F34: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x801A6F38: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x801A6F3C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A6F40: bne         $t2, $at, L_801A6FF4
    if (ctx->r10 != ctx->r1) {
        // 0x801A6F44: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801A6FF4;
    }
    // 0x801A6F44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A6F48: bne         $t8, $at, L_801A6FA4
    if (ctx->r24 != ctx->r1) {
        // 0x801A6F4C: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_801A6FA4;
    }
    // 0x801A6F4C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6F50: lwc1        $f4, 0x7940($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x801A6F54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6F58: lwc1        $f6, -0x8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X8);
    // 0x801A6F5C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6F60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A6F64: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A6F68: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A6F6C: jal         0x80005D44
    // 0x801A6F70: nop

    Matrix_RotateX(rdram, ctx);
        goto after_2;
    // 0x801A6F70: nop

    after_2:
    // 0x801A6F74: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6F78: lwc1        $f10, 0x7944($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7944);
    // 0x801A6F7C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6F80: lwc1        $f18, -0xC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XC);
    // 0x801A6F84: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6F88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A6F8C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801A6F90: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A6F94: jal         0x80005E90
    // 0x801A6F98: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A6F98: nop

    after_3:
    // 0x801A6F9C: b           L_801A6FF8
    // 0x801A6FA0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
        goto L_801A6FF8;
    // 0x801A6FA0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_801A6FA4:
    // 0x801A6FA4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6FA8: lwc1        $f6, 0x7948($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7948);
    // 0x801A6FAC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6FB0: lwc1        $f8, 0x0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X0);
    // 0x801A6FB4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6FB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A6FBC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A6FC0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A6FC4: jal         0x80005D44
    // 0x801A6FC8: nop

    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x801A6FC8: nop

    after_4:
    // 0x801A6FCC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6FD0: lwc1        $f18, 0x794C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X794C);
    // 0x801A6FD4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6FD8: lwc1        $f4, -0x4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X4);
    // 0x801A6FDC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A6FE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A6FE4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x801A6FE8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A6FEC: jal         0x80005E90
    // 0x801A6FF0: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x801A6FF0: nop

    after_5:
L_801A6FF4:
    // 0x801A6FF4: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_801A6FF8:
    // 0x801A6FF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A6FFC: lwc1        $f10, 0x7950($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7950);
    // 0x801A7000: lwc1        $f8, 0xC($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0XC);
    // 0x801A7004: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A7008: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A700C: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A7010: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A7014: jal         0x80005FE0
    // 0x801A7018: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_6;
    // 0x801A7018: nop

    after_6:
    // 0x801A701C: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x801A7020: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A7024: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A7028: lwc1        $f0, 0x20($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X20);
    // 0x801A702C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801A7030: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A7034: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A7038: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A703C: jal         0x80005C34
    // 0x801A7040: nop

    Matrix_Scale(rdram, ctx);
        goto after_7;
    // 0x801A7040: nop

    after_7:
    // 0x801A7044: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A7048: jal         0x80006EB8
    // 0x801A704C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_8;
    // 0x801A704C: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_8:
    // 0x801A7050: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x801A7054: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x801A7058: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A705C: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x801A7060: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801A7064: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A7068: bne         $t7, $at, L_801A71C8
    if (ctx->r15 != ctx->r1) {
        // 0x801A706C: subu        $t0, $t0, $t9
        ctx->r8 = SUB32(ctx->r8, ctx->r25);
            goto L_801A71C8;
    }
    // 0x801A706C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x801A7070: addiu       $v1, $v1, -0x16A0
    ctx->r3 = ADD32(ctx->r3, -0X16A0);
    // 0x801A7074: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801A7078: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x801A707C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A7080: lwc1        $f4, 0xA8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XA8);
    // 0x801A7084: lwc1        $f18, 0xB0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x801A7088: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x801A708C: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A7090: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x801A7094: lwc1        $f8, 0xAC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XAC);
    // 0x801A7098: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A709C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801A70A0: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    // 0x801A70A4: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A70A8: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801A70AC: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x801A70B0: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A70B4: jal         0x80005100
    // 0x801A70B8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_9;
    // 0x801A70B8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_9:
    // 0x801A70BC: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x801A70C0: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x801A70C4: jal         0x80005100
    // 0x801A70C8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    Math_Atan2F(rdram, ctx);
        goto after_10;
    // 0x801A70C8: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    after_10:
    // 0x801A70CC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A70D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A70D4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A70D8: lwc1        $f18, -0x25F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25F0);
    // 0x801A70DC: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x801A70E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A70E4: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x801A70E8: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x801A70EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A70F0: lwc1        $f10, 0x7954($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7954);
    // 0x801A70F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x801A70F8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A70FC: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x801A7100: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A7104: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A7108: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x801A710C: swc1        $f2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f2.u32l;
    // 0x801A7110: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A7114: jal         0x80005E90
    // 0x801A7118: nop

    Matrix_RotateY(rdram, ctx);
        goto after_11;
    // 0x801A7118: nop

    after_11:
    // 0x801A711C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A7120: lwc1        $f4, -0x25F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X25F4);
    // 0x801A7124: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x801A7128: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A712C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x801A7130: lwc1        $f18, 0x7958($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7958);
    // 0x801A7134: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A7138: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A713C: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A7140: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A7144: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801A7148: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A714C: jal         0x80005D44
    // 0x801A7150: nop

    Matrix_RotateX(rdram, ctx);
        goto after_12;
    // 0x801A7150: nop

    after_12:
    // 0x801A7154: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7158: lw          $a0, -0x4438($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4438);
    // 0x801A715C: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x801A7160: jal         0x80006970
    // 0x801A7164: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    Matrix_MultVec3f(rdram, ctx);
        goto after_13;
    // 0x801A7164: addiu       $a2, $sp, 0x68
    ctx->r6 = ADD32(ctx->r29, 0X68);
    after_13:
    // 0x801A7168: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x801A716C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x801A7170: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801A7174: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801A7178: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A717C: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x801A7180: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801A7184: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A7188: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x801A718C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A7190: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x801A7194: addiu       $t5, $zero, 0x3C
    ctx->r13 = ADD32(0, 0X3C);
    // 0x801A7198: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x801A719C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x801A71A0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x801A71A4: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801A71A8: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x801A71AC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801A71B0: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x801A71B4: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x801A71B8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801A71BC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801A71C0: jal         0x8000372C
    // 0x801A71C4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Lights_SetOneLight(rdram, ctx);
        goto after_14;
    // 0x801A71C4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_14:
L_801A71C8:
    // 0x801A71C8: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x801A71CC: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A71D0: addiu       $t1, $t1, -0x21E0
    ctx->r9 = ADD32(ctx->r9, -0X21E0);
    // 0x801A71D4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801A71D8: jal         0x80005680
    // 0x801A71DC: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    Matrix_Copy(rdram, ctx);
        goto after_15;
    // 0x801A71DC: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_15:
    // 0x801A71E0: jal         0x80005740
    // 0x801A71E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_16;
    // 0x801A71E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x801A71E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A71EC: lwc1        $f8, -0xC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XC);
    // 0x801A71F0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A71F4: lwc1        $f10, 0x795C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X795C);
    // 0x801A71F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A71FC: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A7200: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801A7204: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x801A7208: swc1        $f18, -0xC($at)
    MEM_W(-0XC, ctx->r1) = ctx->f18.u32l;
    // 0x801A720C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7210: lwc1        $f6, 0x7960($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7960);
    // 0x801A7214: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801A7218: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A721C: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x801A7220: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801A7224: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x801A7228: jr          $ra
    // 0x801A722C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801A722C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Map_PlanetExplosions_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019FC04: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019FC08: lw          $t6, 0x7B48($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7B48);
    // 0x8019FC0C: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019FC10: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8019FC14: beq         $t6, $zero, L_8019FC30
    if (ctx->r14 == 0) {
        // 0x8019FC18: addiu       $t8, $t8, 0x7B90
        ctx->r24 = ADD32(ctx->r24, 0X7B90);
            goto L_8019FC30;
    }
    // 0x8019FC18: addiu       $t8, $t8, 0x7B90
    ctx->r24 = ADD32(ctx->r24, 0X7B90);
    // 0x8019FC1C: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8019FC20: addiu       $a1, $a1, -0x14B8
    ctx->r5 = ADD32(ctx->r5, -0X14B8);
    // 0x8019FC24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8019FC28: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8019FC2C: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
L_8019FC30:
    // 0x8019FC30: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019FC34: lw          $v0, 0x7B90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B90);
    // 0x8019FC38: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x8019FC3C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8019FC40: bne         $a2, $v0, L_8019FC4C
    if (ctx->r6 != ctx->r2) {
        // 0x8019FC44: addiu       $a1, $a1, -0x14B8
        ctx->r5 = ADD32(ctx->r5, -0X14B8);
            goto L_8019FC4C;
    }
    // 0x8019FC44: addiu       $a1, $a1, -0x14B8
    ctx->r5 = ADD32(ctx->r5, -0X14B8);
    // 0x8019FC48: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8019FC4C:
    // 0x8019FC4C: bne         $a3, $v0, L_8019FC58
    if (ctx->r7 != ctx->r2) {
        // 0x8019FC50: nop
    
            goto L_8019FC58;
    }
    // 0x8019FC50: nop

    // 0x8019FC54: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_8019FC58:
    // 0x8019FC58: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019FC5C: lw          $v0, 0x7B94($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B94);
    // 0x8019FC60: bne         $a2, $v0, L_8019FC6C
    if (ctx->r6 != ctx->r2) {
        // 0x8019FC64: nop
    
            goto L_8019FC6C;
    }
    // 0x8019FC64: nop

    // 0x8019FC68: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8019FC6C:
    // 0x8019FC6C: bne         $a3, $v0, L_8019FC78
    if (ctx->r7 != ctx->r2) {
        // 0x8019FC70: nop
    
            goto L_8019FC78;
    }
    // 0x8019FC70: nop

    // 0x8019FC74: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_8019FC78:
    // 0x8019FC78: lui         $v0, 0x8017
    ctx->r2 = S32(0X8017 << 16);
    // 0x8019FC7C: lw          $v0, 0x7B98($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7B98);
    // 0x8019FC80: bne         $a2, $v0, L_8019FC8C
    if (ctx->r6 != ctx->r2) {
        // 0x8019FC84: nop
    
            goto L_8019FC8C;
    }
    // 0x8019FC84: nop

    // 0x8019FC88: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8019FC8C:
    // 0x8019FC8C: bnel        $a3, $v0, L_8019FC9C
    if (ctx->r7 != ctx->r2) {
        // 0x8019FC90: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8019FC9C;
    }
    goto skip_0;
    // 0x8019FC90: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    skip_0:
    // 0x8019FC94: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x8019FC98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8019FC9C:
    // 0x8019FC9C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x8019FCA0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8019FCA4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8019FCA8: bne         $a2, $a0, L_8019FCB4
    if (ctx->r6 != ctx->r4) {
        // 0x8019FCAC: nop
    
            goto L_8019FCB4;
    }
    // 0x8019FCAC: nop

    // 0x8019FCB0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8019FCB4:
    // 0x8019FCB4: bnel        $a3, $a0, L_8019FCC4
    if (ctx->r7 != ctx->r4) {
        // 0x8019FCB8: lw          $v0, 0x4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X4);
            goto L_8019FCC4;
    }
    goto skip_1;
    // 0x8019FCB8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    skip_1:
    // 0x8019FCBC: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x8019FCC0: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
L_8019FCC4:
    // 0x8019FCC4: bne         $a2, $v0, L_8019FCD0
    if (ctx->r6 != ctx->r2) {
        // 0x8019FCC8: nop
    
            goto L_8019FCD0;
    }
    // 0x8019FCC8: nop

    // 0x8019FCCC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8019FCD0:
    // 0x8019FCD0: bnel        $a3, $v0, L_8019FCE0
    if (ctx->r7 != ctx->r2) {
        // 0x8019FCD4: lw          $v0, 0x8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X8);
            goto L_8019FCE0;
    }
    goto skip_2;
    // 0x8019FCD4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    skip_2:
    // 0x8019FCD8: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x8019FCDC: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
L_8019FCE0:
    // 0x8019FCE0: bne         $a2, $v0, L_8019FCEC
    if (ctx->r6 != ctx->r2) {
        // 0x8019FCE4: nop
    
            goto L_8019FCEC;
    }
    // 0x8019FCE4: nop

    // 0x8019FCE8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8019FCEC:
    // 0x8019FCEC: bnel        $a3, $v0, L_8019FCFC
    if (ctx->r7 != ctx->r2) {
        // 0x8019FCF0: lw          $v0, 0xC($v1)
        ctx->r2 = MEM_W(ctx->r3, 0XC);
            goto L_8019FCFC;
    }
    goto skip_3;
    // 0x8019FCF0: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    skip_3:
    // 0x8019FCF4: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x8019FCF8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
L_8019FCFC:
    // 0x8019FCFC: bne         $a2, $v0, L_8019FD08
    if (ctx->r6 != ctx->r2) {
        // 0x8019FD00: nop
    
            goto L_8019FD08;
    }
    // 0x8019FD00: nop

    // 0x8019FD04: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
L_8019FD08:
    // 0x8019FD08: bne         $a3, $v0, L_8019FD14
    if (ctx->r7 != ctx->r2) {
        // 0x8019FD0C: nop
    
            goto L_8019FD14;
    }
    // 0x8019FD0C: nop

    // 0x8019FD10: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
L_8019FD14:
    // 0x8019FD14: jr          $ra
    // 0x8019FD18: nop

    return;
    // 0x8019FD18: nop

;}
RECOMP_FUNC void Title_GreatFoxDeckPlatform_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190A98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80190A9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80190AA0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190AA4: lui         $a1, 0x43C8
    ctx->r5 = S32(0X43C8 << 16);
    // 0x80190AA8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80190AAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80190AB0: ori         $a1, $a1, 0x8000
    ctx->r5 = ctx->r5 | 0X8000;
    // 0x80190AB4: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x80190AB8: lui         $a2, 0xC379
    ctx->r6 = S32(0XC379 << 16);
    // 0x80190ABC: jal         0x80005B00
    // 0x80190AC0: lui         $a3, 0xC1B0
    ctx->r7 = S32(0XC1B0 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_0;
    // 0x80190AC0: lui         $a3, 0xC1B0
    ctx->r7 = S32(0XC1B0 << 16);
    after_0:
    // 0x80190AC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80190AC8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80190ACC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80190AD0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80190AD4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80190AD8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80190ADC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80190AE0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80190AE4: jal         0x80005C34
    // 0x80190AE8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_1;
    // 0x80190AE8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_1:
    // 0x80190AEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190AF0: jal         0x80006EB8
    // 0x80190AF4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80190AF4: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_2:
    // 0x80190AF8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80190AFC: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x80190B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80190B04: lui         $t0, 0x603
    ctx->r8 = S32(0X603 << 16);
    // 0x80190B08: addiu       $t0, $t0, -0x58E0
    ctx->r8 = ADD32(ctx->r8, -0X58E0);
    // 0x80190B0C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80190B10: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80190B14: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x80190B18: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80190B1C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80190B20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80190B24: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80190B28: jr          $ra
    // 0x80190B2C: nop

    return;
    // 0x80190B2C: nop

;}
RECOMP_FUNC void Option_Entry_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80192344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80192348: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x8019234C: lw          $v0, -0x6EDC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6EDC);
    // 0x80192350: slti        $at, $v0, 0x12D
    ctx->r1 = SIGNED(ctx->r2) < 0X12D ? 1 : 0;
    // 0x80192354: bne         $at, $zero, L_8019237C
    if (ctx->r1 != 0) {
        // 0x80192358: addiu       $at, $zero, 0x190
        ctx->r1 = ADD32(0, 0X190);
            goto L_8019237C;
    }
    // 0x80192358: addiu       $at, $zero, 0x190
    ctx->r1 = ADD32(0, 0X190);
    // 0x8019235C: beq         $v0, $at, L_80192478
    if (ctx->r2 == ctx->r1) {
        // 0x80192360: addiu       $at, $zero, 0x3E8
        ctx->r1 = ADD32(0, 0X3E8);
            goto L_80192478;
    }
    // 0x80192360: addiu       $at, $zero, 0x3E8
    ctx->r1 = ADD32(0, 0X3E8);
    // 0x80192364: beq         $v0, $at, L_801923D8
    if (ctx->r2 == ctx->r1) {
        // 0x80192368: addiu       $at, $zero, 0x7D0
        ctx->r1 = ADD32(0, 0X7D0);
            goto L_801923D8;
    }
    // 0x80192368: addiu       $at, $zero, 0x7D0
    ctx->r1 = ADD32(0, 0X7D0);
    // 0x8019236C: beq         $v0, $at, L_80192438
    if (ctx->r2 == ctx->r1) {
        // 0x80192370: nop
    
            goto L_80192438;
    }
    // 0x80192370: nop

    // 0x80192374: b           L_80192480
    // 0x80192378: nop

        goto L_80192480;
    // 0x80192378: nop

L_8019237C:
    // 0x8019237C: slti        $at, $v0, 0xC9
    ctx->r1 = SIGNED(ctx->r2) < 0XC9 ? 1 : 0;
    // 0x80192380: bne         $at, $zero, L_80192398
    if (ctx->r1 != 0) {
        // 0x80192384: addiu       $at, $zero, 0x12C
        ctx->r1 = ADD32(0, 0X12C);
            goto L_80192398;
    }
    // 0x80192384: addiu       $at, $zero, 0x12C
    ctx->r1 = ADD32(0, 0X12C);
    // 0x80192388: beq         $v0, $at, L_80192468
    if (ctx->r2 == ctx->r1) {
        // 0x8019238C: nop
    
            goto L_80192468;
    }
    // 0x8019238C: nop

    // 0x80192390: b           L_80192480
    // 0x80192394: nop

        goto L_80192480;
    // 0x80192394: nop

L_80192398:
    // 0x80192398: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8019239C: bne         $at, $zero, L_801923B8
    if (ctx->r1 != 0) {
        // 0x801923A0: addiu       $t6, $v0, -0x2
        ctx->r14 = ADD32(ctx->r2, -0X2);
            goto L_801923B8;
    }
    // 0x801923A0: addiu       $t6, $v0, -0x2
    ctx->r14 = ADD32(ctx->r2, -0X2);
    // 0x801923A4: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x801923A8: beq         $v0, $at, L_80192458
    if (ctx->r2 == ctx->r1) {
        // 0x801923AC: nop
    
            goto L_80192458;
    }
    // 0x801923AC: nop

    // 0x801923B0: b           L_80192480
    // 0x801923B4: nop

        goto L_80192480;
    // 0x801923B4: nop

L_801923B8:
    // 0x801923B8: sltiu       $at, $t6, 0x1D
    ctx->r1 = ctx->r14 < 0X1D ? 1 : 0;
    // 0x801923BC: beq         $at, $zero, L_80192480
    if (ctx->r1 == 0) {
        // 0x801923C0: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80192480;
    }
    // 0x801923C0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801923C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801923C8: addu        $at, $at, $t6
    gpr jr_addend_801923D0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801923CC: lw          $t6, 0x7238($at)
    ctx->r14 = ADD32(ctx->r1, 0X7238);
    // 0x801923D0: jr          $t6
    // 0x801923D4: nop

    switch (jr_addend_801923D0 >> 2) {
        case 0: goto L_801923E8; break;
        case 1: goto L_801923F8; break;
        case 2: goto L_80192408; break;
        case 3: goto L_80192428; break;
        case 4: goto L_80192418; break;
        case 5: goto L_80192480; break;
        case 6: goto L_80192480; break;
        case 7: goto L_80192480; break;
        case 8: goto L_80192448; break;
        case 9: goto L_80192480; break;
        case 10: goto L_80192480; break;
        case 11: goto L_80192480; break;
        case 12: goto L_80192480; break;
        case 13: goto L_80192480; break;
        case 14: goto L_80192480; break;
        case 15: goto L_80192480; break;
        case 16: goto L_80192480; break;
        case 17: goto L_80192480; break;
        case 18: goto L_80192448; break;
        case 19: goto L_80192480; break;
        case 20: goto L_80192480; break;
        case 21: goto L_80192480; break;
        case 22: goto L_80192480; break;
        case 23: goto L_80192480; break;
        case 24: goto L_80192480; break;
        case 25: goto L_80192480; break;
        case 26: goto L_80192480; break;
        case 27: goto L_80192480; break;
        case 28: goto L_80192448; break;
        default: switch_error(__func__, 0x801923D0, 0x801B7238);
    }
    // 0x801923D4: nop

L_801923D8:
    // 0x801923D8: jal         0x80193864
    // 0x801923DC: nop

    Option_MainMenu_Draw(rdram, ctx);
        goto after_0;
    // 0x801923DC: nop

    after_0:
    // 0x801923E0: b           L_80192480
    // 0x801923E4: nop

        goto L_80192480;
    // 0x801923E4: nop

L_801923E8:
    // 0x801923E8: jal         0x801944F0
    // 0x801923EC: nop

    Option_Versus_Draw(rdram, ctx);
        goto after_1;
    // 0x801923EC: nop

    after_1:
    // 0x801923F0: b           L_80192480
    // 0x801923F4: nop

        goto L_80192480;
    // 0x801923F4: nop

L_801923F8:
    // 0x801923F8: jal         0x80196F9C
    // 0x801923FC: nop

    Option_Ranking_Draw(rdram, ctx);
        goto after_2;
    // 0x801923FC: nop

    after_2:
    // 0x80192400: b           L_80192480
    // 0x80192404: nop

        goto L_80192480;
    // 0x80192404: nop

L_80192408:
    // 0x80192408: jal         0x80194CE4
    // 0x8019240C: nop

    Option_Sound_Draw(rdram, ctx);
        goto after_3;
    // 0x8019240C: nop

    after_3:
    // 0x80192410: b           L_80192480
    // 0x80192414: nop

        goto L_80192480;
    // 0x80192414: nop

L_80192418:
    // 0x80192418: jal         0x80195B74
    // 0x8019241C: nop

    Option_ExpertSound_Draw(rdram, ctx);
        goto after_4;
    // 0x8019241C: nop

    after_4:
    // 0x80192420: b           L_80192480
    // 0x80192424: nop

        goto L_80192480;
    // 0x80192424: nop

L_80192428:
    // 0x80192428: jal         0x80196894
    // 0x8019242C: nop

    Option_Data_Draw(rdram, ctx);
        goto after_5;
    // 0x8019242C: nop

    after_5:
    // 0x80192430: b           L_80192480
    // 0x80192434: nop

        goto L_80192480;
    // 0x80192434: nop

L_80192438:
    // 0x80192438: jal         0x8019AAB4
    // 0x8019243C: nop

    Option_VersusStage_Draw(rdram, ctx);
        goto after_6;
    // 0x8019243C: nop

    after_6:
    // 0x80192440: b           L_80192480
    // 0x80192444: nop

        goto L_80192480;
    // 0x80192444: nop

L_80192448:
    // 0x80192448: jal         0x8019978C
    // 0x8019244C: nop

    Option_VersusMenu_Draw(rdram, ctx);
        goto after_7;
    // 0x8019244C: nop

    after_7:
    // 0x80192450: b           L_80192480
    // 0x80192454: nop

        goto L_80192480;
    // 0x80192454: nop

L_80192458:
    // 0x80192458: jal         0x8019D118
    // 0x8019245C: nop

    Option_NameEntry_Draw(rdram, ctx);
        goto after_8;
    // 0x8019245C: nop

    after_8:
    // 0x80192460: b           L_80192480
    // 0x80192464: nop

        goto L_80192480;
    // 0x80192464: nop

L_80192468:
    // 0x80192468: jal         0x8019DF64
    // 0x8019246C: nop

    Option_Score_Draw(rdram, ctx);
        goto after_9;
    // 0x8019246C: nop

    after_9:
    // 0x80192470: b           L_80192480
    // 0x80192474: nop

        goto L_80192480;
    // 0x80192474: nop

L_80192478:
    // 0x80192478: jal         0x8019E284
    // 0x8019247C: nop

    Option_InvoiceDraw(rdram, ctx);
        goto after_10;
    // 0x8019247C: nop

    after_10:
L_80192480:
    // 0x80192480: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80192484: lw          $t7, -0x7D80($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7D80);
    // 0x80192488: beql        $t7, $zero, L_801924B8
    if (ctx->r15 == 0) {
        // 0x8019248C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801924B8;
    }
    goto skip_0;
    // 0x8019248C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80192490: jal         0x8019BDF0
    // 0x80192494: nop

    Option_Menu_Push(rdram, ctx);
        goto after_11;
    // 0x80192494: nop

    after_11:
    // 0x80192498: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8019249C: lw          $a1, -0x7D7C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7D7C);
    // 0x801924A0: jal         0x80084688
    // 0x801924A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    Wipe_Draw(rdram, ctx);
        goto after_12;
    // 0x801924A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x801924A8: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801924AC: jal         0x80005740
    // 0x801924B0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_13;
    // 0x801924B0: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_13:
    // 0x801924B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801924B8:
    // 0x801924B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801924BC: jr          $ra
    // 0x801924C0: nop

    return;
    // 0x801924C0: nop

;}
RECOMP_FUNC void Title_64Logo_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F77C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018F780: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018F784: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F788: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8018F78C: jal         0x800B8DD0
    // 0x8018F790: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8018F790: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_0:
    // 0x8018F794: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F798: jal         0x80005708
    // 0x8018F79C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x8018F79C: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x8018F7A0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F7A4: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018F7A8: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018F7AC: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8018F7B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018F7B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018F7B8: lw          $a3, -0x6F9C($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X6F9C);
    // 0x8018F7BC: lw          $a2, -0x6FA0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6FA0);
    // 0x8018F7C0: lw          $a1, -0x6FA4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6FA4);
    // 0x8018F7C4: jal         0x80005B00
    // 0x8018F7C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x8018F7C8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x8018F7CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F7D0: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x8018F7D4: lui         $a2, 0x801C
    ctx->r6 = S32(0X801C << 16);
    // 0x8018F7D8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018F7DC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018F7E0: lw          $a2, -0x6F94($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X6F94);
    // 0x8018F7E4: lw          $a1, -0x6F98($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X6F98);
    // 0x8018F7E8: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F7EC: jal         0x80005C34
    // 0x8018F7F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    Matrix_Scale(rdram, ctx);
        goto after_3;
    // 0x8018F7F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_3:
    // 0x8018F7F4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F7F8: lui         $a1, 0x3FC9
    ctx->r5 = S32(0X3FC9 << 16);
    // 0x8018F7FC: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8018F800: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018F804: jal         0x80005D44
    // 0x8018F808: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_4;
    // 0x8018F808: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x8018F80C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018F810: jal         0x80006EB8
    // 0x8018F814: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_5;
    // 0x8018F814: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_5:
    // 0x8018F818: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8018F81C: lw          $v1, 0x7E64($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7E64);
    // 0x8018F820: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8018F824: lui         $t0, 0x601
    ctx->r8 = S32(0X601 << 16);
    // 0x8018F828: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018F82C: sw          $t8, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r24;
    // 0x8018F830: addiu       $t0, $t0, 0x48D0
    ctx->r8 = ADD32(ctx->r8, 0X48D0);
    // 0x8018F834: lui         $t9, 0x600
    ctx->r25 = S32(0X600 << 16);
    // 0x8018F838: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018F83C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8018F840: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018F844: jal         0x80005740
    // 0x8018F848: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x8018F848: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x8018F84C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018F854: jr          $ra
    // 0x8018F858: nop

    return;
    // 0x8018F858: nop

;}
RECOMP_FUNC void Option_VsTimeTrialStageSelect_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B1F8: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8019B1FC: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8019B200: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8019B204: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8019B208: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8019B20C: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8019B210: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8019B214: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8019B218: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8019B21C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8019B220: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8019B224: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x8019B228: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8019B22C: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8019B230: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B234: lwc1        $f22, -0xD58($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0XD58);
    // 0x8019B238: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8019B23C: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019B240: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B244: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x8019B248: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x8019B24C: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x8019B250: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x8019B254: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019B258: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019B25C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019B260: addiu       $s7, $s7, -0xD4C
    ctx->r23 = ADD32(ctx->r23, -0XD4C);
    // 0x8019B264: addiu       $s6, $s6, -0xD44
    ctx->r22 = ADD32(ctx->r22, -0XD44);
    // 0x8019B268: addiu       $s5, $s5, -0xD34
    ctx->r21 = ADD32(ctx->r21, -0XD34);
    // 0x8019B26C: addiu       $s4, $s4, -0xD3C
    ctx->r20 = ADD32(ctx->r20, -0XD3C);
    // 0x8019B270: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8019B274: addiu       $s1, $sp, 0x8C
    ctx->r17 = ADD32(ctx->r29, 0X8C);
    // 0x8019B278: lui         $fp, 0xFA00
    ctx->r30 = S32(0XFA00 << 16);
L_8019B27C:
    // 0x8019B27C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019B280: lw          $t6, 0x1A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A28);
    // 0x8019B284: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x8019B288: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8019B28C: bne         $s2, $t6, L_8019B2A0
    if (ctx->r18 != ctx->r14) {
        // 0x8019B290: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019B2A0;
    }
    // 0x8019B290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019B294: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8019B298: b           L_8019B2A4
    // 0x8019B29C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_8019B2A4;
    // 0x8019B29C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_8019B2A0:
    // 0x8019B2A0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
L_8019B2A4:
    // 0x8019B2A4: jal         0x800B8DD0
    // 0x8019B2A8: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019B2A8: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_0:
    // 0x8019B2AC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8019B2B0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8019B2B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019B2B8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8019B2BC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8019B2C0: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x8019B2C4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8019B2C8: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x8019B2CC: addiu       $t3, $zero, 0x26
    ctx->r11 = ADD32(0, 0X26);
    // 0x8019B2D0: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8019B2D4: or          $t2, $t1, $at
    ctx->r10 = ctx->r9 | ctx->r1;
    // 0x8019B2D8: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8019B2DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B2E0: lwc1        $f4, -0xD54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XD54);
    // 0x8019B2E4: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x8019B2E8: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x8019B2EC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019B2F0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8019B2F4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019B2F8: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8019B2FC: jal         0x8009D0BC
    // 0x8019B300: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x8019B300: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8019B304: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019B308: bne         $s2, $at, L_8019B314
    if (ctx->r18 != ctx->r1) {
        // 0x8019B30C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019B314;
    }
    // 0x8019B30C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019B310: addiu       $s3, $zero, 0x38
    ctx->r19 = ADD32(0, 0X38);
L_8019B314:
    // 0x8019B314: jal         0x800B8DD0
    // 0x8019B318: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8019B318: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_2:
    // 0x8019B31C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8019B320: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8019B324: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019B328: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8019B32C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8019B330: sw          $fp, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r30;
    // 0x8019B334: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8019B338: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8019B33C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8019B340: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8019B344: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8019B348: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8019B34C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B350: lwc1        $f8, -0xD54($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XD54);
    // 0x8019B354: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x8019B358: lw          $a1, 0x0($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X0);
    // 0x8019B35C: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8019B360: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8019B364: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019B368: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019B36C: jal         0x8009D994
    // 0x8019B370: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x8019B370: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8019B374: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B378: lwc1        $f16, -0xD50($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XD50);
    // 0x8019B37C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019B380: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8019B384: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019B388: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8019B38C: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8019B390: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8019B394: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8019B398: bne         $s2, $at, L_8019B27C
    if (ctx->r18 != ctx->r1) {
        // 0x8019B39C: add.s       $f22, $f22, $f16
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
            goto L_8019B27C;
    }
    // 0x8019B39C: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x8019B3A0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8019B3A4: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8019B3A8: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8019B3AC: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x8019B3B0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8019B3B4: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8019B3B8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8019B3BC: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8019B3C0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8019B3C4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8019B3C8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8019B3CC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8019B3D0: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8019B3D4: jr          $ra
    // 0x8019B3D8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8019B3D8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Map_Prologue_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A0D14: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801A0D18: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801A0D1C: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x801A0D20: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x801A0D24: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801A0D28: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801A0D2C: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801A0D30: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801A0D34: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x801A0D38: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801A0D3C: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801A0D40: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801A0D44: jal         0x801A116C
    // 0x801A0D48: nop

    Map_PrologueArwing_Draw(rdram, ctx);
        goto after_0;
    // 0x801A0D48: nop

    after_0:
    // 0x801A0D4C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801A0D50: addiu       $s4, $s4, 0x7E64
    ctx->r20 = ADD32(ctx->r20, 0X7E64);
    // 0x801A0D54: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801A0D58: jal         0x800B8DD0
    // 0x801A0D5C: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A0D5C: addiu       $a1, $zero, 0x51
    ctx->r5 = ADD32(0, 0X51);
    after_1:
    // 0x801A0D60: lui         $s0, 0x8018
    ctx->r16 = S32(0X8018 << 16);
    // 0x801A0D64: addiu       $s0, $s0, -0x6630
    ctx->r16 = ADD32(ctx->r16, -0X6630);
    // 0x801A0D68: lui         $s5, 0xFA00
    ctx->r21 = S32(0XFA00 << 16);
    // 0x801A0D6C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x801A0D70: lui         $t7, 0xB4B4
    ctx->r15 = S32(0XB4B4 << 16);
    // 0x801A0D74: ori         $t7, $t7, 0xB4FF
    ctx->r15 = ctx->r15 | 0XB4FF;
    // 0x801A0D78: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801A0D7C: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x801A0D80: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801A0D84: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x801A0D88: jal         0x800C2928
    // 0x801A0D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Message_GetCharCount(rdram, ctx);
        goto after_2;
    // 0x801A0D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801A0D90: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0D94: lwc1        $f4, -0x2624($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2624);
    // 0x801A0D98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0D9C: lwc1        $f8, -0x2620($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2620);
    // 0x801A0DA0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A0DA4: addiu       $t1, $zero, 0xDA
    ctx->r9 = ADD32(0, 0XDA);
    // 0x801A0DA8: addiu       $t2, $zero, 0x46
    ctx->r10 = ADD32(0, 0X46);
    // 0x801A0DAC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801A0DB0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801A0DB4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801A0DB8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A0DBC: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x801A0DC0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801A0DC4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801A0DC8: jal         0x800C2D3C
    // 0x801A0DCC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    Message_DisplayScrollingText(rdram, ctx);
        goto after_3;
    // 0x801A0DCC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x801A0DD0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801A0DD4: jal         0x800B8DD0
    // 0x801A0DD8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x801A0DD8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_4:
    // 0x801A0DDC: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801A0DE0: lui         $s0, 0x602
    ctx->r16 = S32(0X602 << 16);
    // 0x801A0DE4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A0DE8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801A0DEC: addiu       $s0, $s0, -0x6FD0
    ctx->r16 = ADD32(ctx->r16, -0X6FD0);
    // 0x801A0DF0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x801A0DF4: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801A0DF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801A0DFC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x801A0E00: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x801A0E04: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801A0E08: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x801A0E0C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A0E10: lwc1        $f16, 0x694C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X694C);
    // 0x801A0E14: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A0E18: lwc1        $f18, 0x75C8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X75C8);
    // 0x801A0E1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801A0E20: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801A0E24: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801A0E28: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801A0E2C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x801A0E30: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x801A0E34: jal         0x8009D994
    // 0x801A0E38: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x801A0E38: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801A0E3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A0E40: lwc1        $f4, 0x6950($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6950);
    // 0x801A0E44: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A0E48: lwc1        $f6, 0x75CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75CC);
    // 0x801A0E4C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801A0E50: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801A0E54: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801A0E58: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801A0E5C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801A0E60: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x801A0E64: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801A0E68: jal         0x8009E4B0
    // 0x801A0E6C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8_MirY(rdram, ctx);
        goto after_6;
    // 0x801A0E6C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x801A0E70: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x801A0E74: jal         0x8003DE68
    // 0x801A0E78: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
    Background_DrawPartialStarfield(rdram, ctx);
        goto after_7;
    // 0x801A0E78: addiu       $a1, $zero, 0x76
    ctx->r5 = ADD32(0, 0X76);
    after_7:
    // 0x801A0E7C: addiu       $a0, $zero, 0xCD
    ctx->r4 = ADD32(0, 0XCD);
    // 0x801A0E80: jal         0x8003DE68
    // 0x801A0E84: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    Background_DrawPartialStarfield(rdram, ctx);
        goto after_8;
    // 0x801A0E84: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    after_8:
    // 0x801A0E88: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801A0E8C: jal         0x800B8DD0
    // 0x801A0E90: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_9;
    // 0x801A0E90: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_9:
    // 0x801A0E94: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x801A0E98: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A0E9C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x801A0EA0: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x801A0EA4: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x801A0EA8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A0EAC: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x801A0EB0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801A0EB4: lwc1        $f8, -0x2618($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2618);
    // 0x801A0EB8: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801A0EBC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A0EC0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801A0EC4: addiu       $s3, $s3, -0x2610
    ctx->r19 = ADD32(ctx->r19, -0X2610);
    // 0x801A0EC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801A0ECC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801A0ED0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801A0ED4: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x801A0ED8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801A0EDC: beql        $t7, $zero, L_801A0F2C
    if (ctx->r15 == 0) {
        // 0x801A0EE0: mfc1        $t7, $f10
        ctx->r15 = (int32_t)ctx->f10.u32l;
            goto L_801A0F2C;
    }
    goto skip_0;
    // 0x801A0EE0: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    skip_0:
    // 0x801A0EE4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A0EE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A0EEC: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A0EF0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x801A0EF4: nop

    // 0x801A0EF8: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x801A0EFC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x801A0F00: nop

    // 0x801A0F04: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x801A0F08: bne         $t7, $zero, L_801A0F20
    if (ctx->r15 != 0) {
        // 0x801A0F0C: nop
    
            goto L_801A0F20;
    }
    // 0x801A0F0C: nop

    // 0x801A0F10: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x801A0F14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A0F18: b           L_801A0F38
    // 0x801A0F1C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_801A0F38;
    // 0x801A0F1C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_801A0F20:
    // 0x801A0F20: b           L_801A0F38
    // 0x801A0F24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_801A0F38;
    // 0x801A0F24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801A0F28: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
L_801A0F2C:
    // 0x801A0F2C: nop

    // 0x801A0F30: bltz        $t7, L_801A0F20
    if (SIGNED(ctx->r15) < 0) {
        // 0x801A0F34: nop
    
            goto L_801A0F20;
    }
    // 0x801A0F34: nop

L_801A0F38:
    // 0x801A0F38: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801A0F3C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A0F40: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x801A0F44: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x801A0F48: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801A0F4C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801A0F50: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801A0F54: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x801A0F58: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801A0F5C: lui         $at, 0x42DA
    ctx->r1 = S32(0X42DA << 16);
    // 0x801A0F60: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A0F64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A0F68: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A0F6C: addiu       $s2, $s2, 0x6954
    ctx->r18 = ADD32(ctx->r18, 0X6954);
L_801A0F70:
    // 0x801A0F70: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x801A0F74: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x801A0F78: sll         $t5, $s1, 1
    ctx->r13 = S32(ctx->r17 << 1);
    // 0x801A0F7C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801A0F80: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801A0F84: addu        $t3, $s2, $t2
    ctx->r11 = ADD32(ctx->r18, ctx->r10);
    // 0x801A0F88: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x801A0F8C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A0F90: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A0F94: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x801A0F98: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801A0F9C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801A0FA0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x801A0FA4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x801A0FA8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x801A0FAC: add.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f26.fl;
    // 0x801A0FB0: jal         0x8009D418
    // 0x801A0FB4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_10;
    // 0x801A0FB4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_10:
    // 0x801A0FB8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A0FBC: slti        $at, $s0, 0xD
    ctx->r1 = SIGNED(ctx->r16) < 0XD ? 1 : 0;
    // 0x801A0FC0: bne         $at, $zero, L_801A0F70
    if (ctx->r1 != 0) {
        // 0x801A0FC4: addiu       $s1, $s1, 0x180
        ctx->r17 = ADD32(ctx->r17, 0X180);
            goto L_801A0F70;
    }
    // 0x801A0FC4: addiu       $s1, $s1, 0x180
    ctx->r17 = ADD32(ctx->r17, 0X180);
    // 0x801A0FC8: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x801A0FCC: addiu       $t0, $t0, -0x261C
    ctx->r8 = ADD32(ctx->r8, -0X261C);
    // 0x801A0FD0: lwc1        $f10, 0x0($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801A0FD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801A0FD8: nop

    // 0x801A0FDC: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x801A0FE0: nop

    // 0x801A0FE4: bc1tl       L_801A113C
    if (c1cs) {
        // 0x801A0FE8: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801A113C;
    }
    goto skip_1;
    // 0x801A0FE8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_1:
    // 0x801A0FEC: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x801A0FF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A0FF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801A0FF8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801A0FFC: slti        $at, $t7, 0x7
    ctx->r1 = SIGNED(ctx->r15) < 0X7 ? 1 : 0;
    // 0x801A1000: beq         $at, $zero, L_801A1138
    if (ctx->r1 == 0) {
        // 0x801A1004: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_801A1138;
    }
    // 0x801A1004: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801A1008: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x801A100C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x801A1010: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801A1014: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801A1018: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x801A101C: sw          $s5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r21;
    // 0x801A1020: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801A1024: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A1028: addiu       $s5, $zero, 0xD
    ctx->r21 = ADD32(0, 0XD);
    // 0x801A102C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x801A1030: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801A1034: nop

    // 0x801A1038: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801A103C: beql        $t1, $zero, L_801A108C
    if (ctx->r9 == 0) {
        // 0x801A1040: mfc1        $t1, $f18
        ctx->r9 = (int32_t)ctx->f18.u32l;
            goto L_801A108C;
    }
    goto skip_2;
    // 0x801A1040: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    skip_2:
    // 0x801A1044: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A1048: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A104C: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A1050: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x801A1054: nop

    // 0x801A1058: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x801A105C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x801A1060: nop

    // 0x801A1064: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x801A1068: bne         $t1, $zero, L_801A1080
    if (ctx->r9 != 0) {
        // 0x801A106C: nop
    
            goto L_801A1080;
    }
    // 0x801A106C: nop

    // 0x801A1070: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
    // 0x801A1074: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A1078: b           L_801A1098
    // 0x801A107C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_801A1098;
    // 0x801A107C: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_801A1080:
    // 0x801A1080: b           L_801A1098
    // 0x801A1084: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_801A1098;
    // 0x801A1084: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801A1088: mfc1        $t1, $f18
    ctx->r9 = (int32_t)ctx->f18.u32l;
L_801A108C:
    // 0x801A108C: nop

    // 0x801A1090: bltz        $t1, L_801A1080
    if (SIGNED(ctx->r9) < 0) {
        // 0x801A1094: nop
    
            goto L_801A1080;
    }
    // 0x801A1094: nop

L_801A1098:
    // 0x801A1098: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801A109C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A10A0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x801A10A4: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A10A8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
L_801A10AC:
    // 0x801A10AC: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x801A10B0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x801A10B4: sll         $t8, $s1, 1
    ctx->r24 = S32(ctx->r17 << 1);
    // 0x801A10B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801A10BC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801A10C0: addu        $t6, $s2, $t5
    ctx->r14 = ADD32(ctx->r18, ctx->r13);
    // 0x801A10C4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801A10C8: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A10CC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A10D0: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x801A10D4: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x801A10D8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801A10DC: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x801A10E0: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x801A10E4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x801A10E8: add.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f26.fl;
    // 0x801A10EC: jal         0x8009D418
    // 0x801A10F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_11;
    // 0x801A10F0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x801A10F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A10F8: bne         $s0, $s5, L_801A10AC
    if (ctx->r16 != ctx->r21) {
        // 0x801A10FC: addiu       $s1, $s1, 0x180
        ctx->r17 = ADD32(ctx->r17, 0X180);
            goto L_801A10AC;
    }
    // 0x801A10FC: addiu       $s1, $s1, 0x180
    ctx->r17 = ADD32(ctx->r17, 0X180);
    // 0x801A1100: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x801A1104: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801A1108: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A110C: lwc1        $f18, -0x261C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X261C);
    // 0x801A1110: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x801A1114: nop

    // 0x801A1118: bc1fl       L_801A113C
    if (!c1cs) {
        // 0x801A111C: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_801A113C;
    }
    goto skip_3;
    // 0x801A111C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    skip_3:
    // 0x801A1120: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801A1124: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1128: swc1        $f4, -0x261C($at)
    MEM_W(-0X261C, ctx->r1) = ctx->f4.u32l;
    // 0x801A112C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x801A1130: addiu       $t1, $t9, 0x1
    ctx->r9 = ADD32(ctx->r25, 0X1);
    // 0x801A1134: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
L_801A1138:
    // 0x801A1138: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_801A113C:
    // 0x801A113C: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x801A1140: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x801A1144: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x801A1148: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x801A114C: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801A1150: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801A1154: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801A1158: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801A115C: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801A1160: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801A1164: jr          $ra
    // 0x801A1168: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801A1168: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void Map_BriefingRadio_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AB284: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AB288: addiu       $v1, $v1, -0x26C0
    ctx->r3 = ADD32(ctx->r3, -0X26C0);
    // 0x801AB28C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x801AB290: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x801AB294: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801AB298: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x801AB29C: lw          $t1, -0xBE0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XBE0);
    // 0x801AB2A0: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801AB2A4: lw          $t7, -0x26AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26AC);
    // 0x801AB2A8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801AB2AC: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801AB2B0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x801AB2B4: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x801AB2B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801AB2BC: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x801AB2C0: lw          $t0, -0xBD8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XBD8);
    // 0x801AB2C4: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB2C8: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x801AB2CC: sw          $t0, -0x7CF8($at)
    MEM_W(-0X7CF8, ctx->r1) = ctx->r8;
    // 0x801AB2D0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AB2D4: swc1        $f6, 0x7D68($at)
    MEM_W(0X7D68, ctx->r1) = ctx->f6.u32l;
    // 0x801AB2D8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AB2DC: sw          $t2, -0xFE8($at)
    MEM_W(-0XFE8, ctx->r1) = ctx->r10;
    // 0x801AB2E0: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB2E4: addiu       $t3, $zero, 0x4E
    ctx->r11 = ADD32(0, 0X4E);
    // 0x801AB2E8: sw          $t3, -0x78D8($at)
    MEM_W(-0X78D8, ctx->r1) = ctx->r11;
    // 0x801AB2EC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801AB2F0: addiu       $t4, $zero, 0xA6
    ctx->r12 = ADD32(0, 0XA6);
    // 0x801AB2F4: sw          $t4, -0x78D4($at)
    MEM_W(-0X78D4, ctx->r1) = ctx->r12;
    // 0x801AB2F8: jr          $ra
    // 0x801AB2FC: nop

    return;
    // 0x801AB2FC: nop

;}
RECOMP_FUNC void Title_GetCamRot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191798: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8019179C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801917A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801917A4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801917A8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801917AC: lwc1        $f4, 0x7978($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x801917B0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801917B4: lwc1        $f6, 0x79A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x801917B8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801917BC: lwc1        $f8, 0x7980($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x801917C0: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801917C4: lwc1        $f10, 0x79B8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x801917C8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801917CC: lwc1        $f18, 0x7988($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x801917D0: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801917D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801917D8: lwc1        $f4, 0x79C0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x801917DC: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801917E0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801917E4: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x801917E8: sub.s       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801917EC: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801917F0: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x801917F4: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801917F8: jal         0x80005100
    // 0x801917FC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_0;
    // 0x801917FC: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_0:
    // 0x80191800: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191804: lwc1        $f18, 0x70F8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X70F8);
    // 0x80191808: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x8019180C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80191810: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80191814: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x80191818: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8019181C: jal         0x80005100
    // 0x80191820: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    Math_Atan2F(rdram, ctx);
        goto after_1;
    // 0x80191820: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80191824: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80191828: lwc1        $f6, 0x70FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X70FC);
    // 0x8019182C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80191830: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80191834: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x80191838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019183C: jr          $ra
    // 0x80191840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80191840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void Map_PrologueArwing_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A116C: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x801A1170: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x801A1174: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x801A1178: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A117C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801A1180: addiu       $s0, $s0, -0x4438
    ctx->r16 = ADD32(ctx->r16, -0X4438);
    // 0x801A1184: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801A1188: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A118C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A1190: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x801A1194: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x801A1198: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x801A119C: lui         $a1, 0x3EC4
    ctx->r5 = S32(0X3EC4 << 16);
    // 0x801A11A0: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x801A11A4: sw          $t7, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r15;
    // 0x801A11A8: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x801A11AC: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x801A11B0: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x801A11B4: ori         $a1, $a1, 0x9809
    ctx->r5 = ctx->r5 | 0X9809;
    // 0x801A11B8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A11BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A11C0: jal         0x80005E90
    // 0x801A11C4: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    Matrix_RotateY(rdram, ctx);
        goto after_0;
    // 0x801A11C4: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801A11C8: lui         $a1, 0xBF9C
    ctx->r5 = S32(0XBF9C << 16);
    // 0x801A11CC: ori         $a1, $a1, 0x61AA
    ctx->r5 = ctx->r5 | 0X61AA;
    // 0x801A11D0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A11D4: jal         0x80005D44
    // 0x801A11D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_1;
    // 0x801A11D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801A11DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A11E0: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x801A11E4: jal         0x80006970
    // 0x801A11E8: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    Matrix_MultVec3f(rdram, ctx);
        goto after_2;
    // 0x801A11E8: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_2:
    // 0x801A11EC: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A11F0: addiu       $s0, $s0, -0x26B8
    ctx->r16 = ADD32(ctx->r16, -0X26B8);
    // 0x801A11F4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x801A11F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A11FC: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    // 0x801A1200: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x801A1204: bne         $at, $zero, L_801A1304
    if (ctx->r1 != 0) {
        // 0x801A1208: addiu       $a0, $a0, 0x7E64
        ctx->r4 = ADD32(ctx->r4, 0X7E64);
            goto L_801A1304;
    }
    // 0x801A1208: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A120C: bgez        $v1, L_801A1218
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801A1210: addiu       $a2, $zero, 0x6
        ctx->r6 = ADD32(0, 0X6);
            goto L_801A1218;
    }
    // 0x801A1210: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801A1214: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801A1218:
    // 0x801A1218: bgez        $a2, L_801A1224
    if (SIGNED(ctx->r6) >= 0) {
        // 0x801A121C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_801A1224;
    }
    // 0x801A121C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x801A1220: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_801A1224:
    // 0x801A1224: bgez        $v0, L_801A1230
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801A1228: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801A1230;
    }
    // 0x801A1228: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A122C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801A1230:
    // 0x801A1230: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A1234: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x801A1238: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x801A123C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x801A1240: jal         0x800B8DD0
    // 0x801A1244: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801A1244: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    after_3:
    // 0x801A1248: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801A124C: lw          $v0, 0x7E64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X7E64);
    // 0x801A1250: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801A1254: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x801A1258: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801A125C: sw          $t0, 0x7E64($at)
    MEM_W(0X7E64, ctx->r1) = ctx->r8;
    // 0x801A1260: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1264: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x801A1268: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A126C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801A1270: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801A1274: lwc1        $f6, -0x2618($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2618);
    // 0x801A1278: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x801A127C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x801A1280: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801A1284: nop

    // 0x801A1288: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801A128C: beql        $t3, $zero, L_801A12DC
    if (ctx->r11 == 0) {
        // 0x801A1290: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_801A12DC;
    }
    goto skip_0;
    // 0x801A1290: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_0:
    // 0x801A1294: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A1298: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801A129C: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A12A0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x801A12A4: nop

    // 0x801A12A8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x801A12AC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x801A12B0: nop

    // 0x801A12B4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x801A12B8: bne         $t3, $zero, L_801A12D0
    if (ctx->r11 != 0) {
        // 0x801A12BC: nop
    
            goto L_801A12D0;
    }
    // 0x801A12BC: nop

    // 0x801A12C0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x801A12C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x801A12C8: b           L_801A12E8
    // 0x801A12CC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_801A12E8;
    // 0x801A12CC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_801A12D0:
    // 0x801A12D0: b           L_801A12E8
    // 0x801A12D4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_801A12E8;
    // 0x801A12D4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801A12D8: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_801A12DC:
    // 0x801A12DC: nop

    // 0x801A12E0: bltz        $t3, L_801A12D0
    if (SIGNED(ctx->r11) < 0) {
        // 0x801A12E4: nop
    
            goto L_801A12D0;
    }
    // 0x801A12E4: nop

L_801A12E8:
    // 0x801A12E8: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x801A12EC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A12F0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x801A12F4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x801A12F8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x801A12FC: b           L_801A1310
    // 0x801A1300: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
        goto L_801A1310;
    // 0x801A1300: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_801A1304:
    // 0x801A1304: jal         0x800B8DD0
    // 0x801A1308: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x801A1308: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_4:
    // 0x801A130C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_801A1310:
    // 0x801A1310: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A1314: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801A1318: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x801A131C: bne         $at, $zero, L_801A1340
    if (ctx->r1 != 0) {
        // 0x801A1320: lui         $at, 0x801D
        ctx->r1 = S32(0X801D << 16);
            goto L_801A1340;
    }
    // 0x801A1320: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A1324: lwc1        $f16, -0x2618($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X2618);
    // 0x801A1328: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801A132C: nop

    // 0x801A1330: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x801A1334: nop

    // 0x801A1338: bc1t        L_801A14F8
    if (c1cs) {
        // 0x801A133C: nop
    
            goto L_801A14F8;
    }
    // 0x801A133C: nop

L_801A1340:
    // 0x801A1340: jal         0x80005708
    // 0x801A1344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x801A1344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801A1348: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A134C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A1350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A1354: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801A1358: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801A135C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801A1360: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A1364: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x801A1368: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A136C: lui         $a3, 0x43D7
    ctx->r7 = S32(0X43D7 << 16);
    // 0x801A1370: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x801A1374: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A1378: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A137C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x801A1380: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801A1384: jal         0x80006E3C
    // 0x801A1388: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_6;
    // 0x801A1388: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x801A138C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A1390: jal         0x80006EB8
    // 0x801A1394: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_7;
    // 0x801A1394: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_7:
    // 0x801A1398: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x801A139C: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x801A13A0: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x801A13A4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x801A13A8: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x801A13AC: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x801A13B0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801A13B4: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x801A13B8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A13BC: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x801A13C0: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x801A13C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A13C8: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x801A13CC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801A13D0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801A13D4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801A13D8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801A13DC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A13E0: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801A13E4: jal         0x8000372C
    // 0x801A13E8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    Lights_SetOneLight(rdram, ctx);
        goto after_8;
    // 0x801A13E8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    after_8:
    // 0x801A13EC: jal         0x80005708
    // 0x801A13F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_9;
    // 0x801A13F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x801A13F4: lui         $a2, 0x4392
    ctx->r6 = S32(0X4392 << 16);
    // 0x801A13F8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A13FC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801A1400: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x801A1404: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A1408: lui         $a1, 0xC270
    ctx->r5 = S32(0XC270 << 16);
    // 0x801A140C: jal         0x80005B00
    // 0x801A1410: lui         $a3, 0xC3B4
    ctx->r7 = S32(0XC3B4 << 16);
    Matrix_Translate(rdram, ctx);
        goto after_10;
    // 0x801A1410: lui         $a3, 0xC3B4
    ctx->r7 = S32(0XC3B4 << 16);
    after_10:
    // 0x801A1414: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801A1418: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801A141C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A1420: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801A1424: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A1428: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A142C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A1430: jal         0x80005C34
    // 0x801A1434: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_11;
    // 0x801A1434: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_11:
    // 0x801A1438: lui         $a1, 0xBE86
    ctx->r5 = S32(0XBE86 << 16);
    // 0x801A143C: ori         $a1, $a1, 0xA92
    ctx->r5 = ctx->r5 | 0XA92;
    // 0x801A1440: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A1444: jal         0x80005FE0
    // 0x801A1448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateZ(rdram, ctx);
        goto after_12;
    // 0x801A1448: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_12:
    // 0x801A144C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1450: lwc1        $f6, 0x75D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X75D0);
    // 0x801A1454: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1458: lwc1        $f8, 0x6970($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6970);
    // 0x801A145C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A1460: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A1464: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A1468: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x801A146C: jal         0x80005D44
    // 0x801A1470: nop

    Matrix_RotateX(rdram, ctx);
        goto after_13;
    // 0x801A1470: nop

    after_13:
    // 0x801A1474: lui         $a1, 0xBFC9
    ctx->r5 = S32(0XBFC9 << 16);
    // 0x801A1478: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x801A147C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A1480: jal         0x80005E90
    // 0x801A1484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_14;
    // 0x801A1484: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_14:
    // 0x801A1488: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801A148C: jal         0x80006EB8
    // 0x801A1490: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_15;
    // 0x801A1490: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    after_15:
    // 0x801A1494: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x801A1498: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x801A149C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A14A0: sb          $t7, 0x8C($sp)
    MEM_B(0X8C, ctx->r29) = ctx->r15;
    // 0x801A14A4: sb          $t6, 0x8D($sp)
    MEM_B(0X8D, ctx->r29) = ctx->r14;
    // 0x801A14A8: swc1        $f20, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f20.u32l;
    // 0x801A14AC: swc1        $f20, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f20.u32l;
    // 0x801A14B0: swc1        $f20, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f20.u32l;
    // 0x801A14B4: swc1        $f20, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f20.u32l;
    // 0x801A14B8: swc1        $f20, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f20.u32l;
    // 0x801A14BC: swc1        $f20, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f20.u32l;
    // 0x801A14C0: swc1        $f20, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f20.u32l;
    // 0x801A14C4: swc1        $f20, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f20.u32l;
    // 0x801A14C8: swc1        $f20, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f20.u32l;
    // 0x801A14CC: swc1        $f20, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f20.u32l;
    // 0x801A14D0: sb          $t8, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r24;
    // 0x801A14D4: swc1        $f20, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f20.u32l;
    // 0x801A14D8: swc1        $f20, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f20.u32l;
    // 0x801A14DC: swc1        $f20, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f20.u32l;
    // 0x801A14E0: jal         0x80053658
    // 0x801A14E4: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    Display_Arwing_Skel(rdram, ctx);
        goto after_16;
    // 0x801A14E4: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    after_16:
    // 0x801A14E8: jal         0x80005740
    // 0x801A14EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x801A14EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x801A14F0: jal         0x80005740
    // 0x801A14F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_18;
    // 0x801A14F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
L_801A14F8:
    // 0x801A14F8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A14FC: lwc1        $f16, 0x6970($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6970);
    // 0x801A1500: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A1504: lwc1        $f18, 0x75D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X75D4);
    // 0x801A1508: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A150C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801A1510: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801A1514: swc1        $f4, 0x6970($at)
    MEM_W(0X6970, ctx->r1) = ctx->f4.u32l;
    // 0x801A1518: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x801A151C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x801A1520: jr          $ra
    // 0x801A1524: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x801A1524: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void Option_GetCharIndex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019DCE8: lui         $a2, 0x801B
    ctx->r6 = S32(0X801B << 16);
    // 0x8019DCEC: addiu       $a2, $a2, -0x10A4
    ctx->r6 = ADD32(ctx->r6, -0X10A4);
    // 0x8019DCF0: lbu         $t6, 0x0($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X0);
    // 0x8019DCF4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8019DCF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8019DCFC: beq         $t6, $zero, L_8019DD24
    if (ctx->r14 == 0) {
        // 0x8019DD00: addiu       $v0, $t7, -0x10A4
        ctx->r2 = ADD32(ctx->r15, -0X10A4);
            goto L_8019DD24;
    }
    // 0x8019DD00: addiu       $v0, $t7, -0x10A4
    ctx->r2 = ADD32(ctx->r15, -0X10A4);
    // 0x8019DD04: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
L_8019DD08:
    // 0x8019DD08: beql        $a0, $a1, L_8019DD28
    if (ctx->r4 == ctx->r5) {
        // 0x8019DD0C: addu        $t8, $a2, $v1
        ctx->r24 = ADD32(ctx->r6, ctx->r3);
            goto L_8019DD28;
    }
    goto skip_0;
    // 0x8019DD0C: addu        $t8, $a2, $v1
    ctx->r24 = ADD32(ctx->r6, ctx->r3);
    skip_0:
    // 0x8019DD10: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x8019DD14: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8019DD18: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8019DD1C: bne         $a1, $zero, L_8019DD08
    if (ctx->r5 != 0) {
        // 0x8019DD20: nop
    
            goto L_8019DD08;
    }
    // 0x8019DD20: nop

L_8019DD24:
    // 0x8019DD24: addu        $t8, $a2, $v1
    ctx->r24 = ADD32(ctx->r6, ctx->r3);
L_8019DD28:
    // 0x8019DD28: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8019DD2C: bnel        $t9, $zero, L_8019DD3C
    if (ctx->r25 != 0) {
        // 0x8019DD30: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8019DD3C;
    }
    goto skip_1;
    // 0x8019DD30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x8019DD34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8019DD38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8019DD3C:
    // 0x8019DD3C: jr          $ra
    // 0x8019DD40: nop

    return;
    // 0x8019DD40: nop

;}
RECOMP_FUNC void Map_VenomCloud2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A7684: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801A7688: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801A768C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801A7690: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801A7694: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x801A7698: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801A769C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x801A76A0: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801A76A4: bne         $t6, $at, L_801A76B8
    if (ctx->r14 != ctx->r1) {
        // 0x801A76A8: addiu       $t0, $zero, 0xFF
        ctx->r8 = ADD32(0, 0XFF);
            goto L_801A76B8;
    }
    // 0x801A76A8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x801A76AC: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x801A76B0: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    // 0x801A76B4: addiu       $t0, $zero, 0x40
    ctx->r8 = ADD32(0, 0X40);
L_801A76B8:
    // 0x801A76B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A76BC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A76C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A76C4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x801A76C8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x801A76CC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x801A76D0: jal         0x800B8DD0
    // 0x801A76D4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A76D4: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x801A76D8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801A76DC: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x801A76E0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801A76E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801A76E8: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x801A76EC: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x801A76F0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801A76F4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801A76F8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801A76FC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x801A7700: andi        $t7, $a3, 0xFF
    ctx->r15 = ctx->r7 & 0XFF;
    // 0x801A7704: sll         $t5, $t0, 24
    ctx->r13 = S32(ctx->r8 << 24);
    // 0x801A7708: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x801A770C: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x801A7710: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x801A7714: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801A7718: lw          $t2, -0xB3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB3C);
    // 0x801A771C: andi        $t1, $a2, 0xFF
    ctx->r9 = ctx->r6 & 0XFF;
    // 0x801A7720: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x801A7724: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x801A7728: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x801A772C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x801A7730: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x801A7734: or          $t4, $t9, $t2
    ctx->r12 = ctx->r25 | ctx->r10;
    // 0x801A7738: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801A773C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7740: jal         0x80005708
    // 0x801A7744: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A7744: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801A7748: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x801A774C: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A7750: addiu       $t7, $t7, -0x21E0
    ctx->r15 = ADD32(ctx->r15, -0X21E0);
    // 0x801A7754: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7758: sll         $t5, $t3, 6
    ctx->r13 = S32(ctx->r11 << 6);
    // 0x801A775C: addu        $a1, $t5, $t7
    ctx->r5 = ADD32(ctx->r13, ctx->r15);
    // 0x801A7760: jal         0x80005680
    // 0x801A7764: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A7764: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x801A7768: jal         0x80006EB8
    // 0x801A776C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_3;
    // 0x801A776C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801A7770: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801A7774: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x801A7778: addiu       $t1, $t1, 0x4A40
    ctx->r9 = ADD32(ctx->r9, 0X4A40);
    // 0x801A777C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801A7780: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A7784: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x801A7788: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801A778C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x801A7790: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801A7794: jal         0x80005740
    // 0x801A7798: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x801A7798: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_4:
    // 0x801A779C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801A77A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801A77A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801A77A8: jr          $ra
    // 0x801A77AC: nop

    return;
    // 0x801A77AC: nop

;}
RECOMP_FUNC void Title_ArwingShadow_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DDB8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DDBC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DDC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018DDC4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DDC8: jal         0x80005708
    // 0x8018DDCC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x8018DDCC: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_0:
    // 0x8018DDD0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8018DDD4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DDD8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DDDC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018DDE0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8018DDE4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8018DDE8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8018DDEC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018DDF0: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018DDF4: lwc1        $f4, -0x7B14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7B14);
    // 0x8018DDF8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018DDFC: lwc1        $f6, 0x7050($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7050);
    // 0x8018DE00: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DE04: lwc1        $f10, -0x6FB0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6FB0);
    // 0x8018DE08: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8018DE0C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8018DE10: lwc1        $f18, -0x6FB8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6FB8);
    // 0x8018DE14: lui         $at, 0x42A8
    ctx->r1 = S32(0X42A8 << 16);
    // 0x8018DE18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DE1C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018DE20: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DE24: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8018DE28: lwc1        $f10, 0x7054($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7054);
    // 0x8018DE2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018DE30: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8018DE34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DE38: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018DE3C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8018DE40: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8018DE44: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018DE48: add.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8018DE4C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8018DE50: jal         0x80005B00
    // 0x8018DE54: nop

    Matrix_Translate(rdram, ctx);
        goto after_1;
    // 0x8018DE54: nop

    after_1:
    // 0x8018DE58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DE5C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DE60: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DE64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DE68: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DE6C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DE70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8018DE74: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018DE78: jal         0x80005C34
    // 0x8018DE7C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_2;
    // 0x8018DE7C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_2:
    // 0x8018DE80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DE84: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x8018DE88: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x8018DE8C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x8018DE90: jal         0x80005E90
    // 0x8018DE94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x8018DE94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x8018DE98: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018DE9C: jal         0x80006EB8
    // 0x8018DEA0: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_4;
    // 0x8018DEA0: addiu       $a0, $a2, 0x7E64
    ctx->r4 = ADD32(ctx->r6, 0X7E64);
    after_4:
    // 0x8018DEA4: jal         0x800BA140
    // 0x8018DEA8: nop

    RCP_SetupDL_64(rdram, ctx);
        goto after_5;
    // 0x8018DEA8: nop

    after_5:
    // 0x8018DEAC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018DEB0: addiu       $a2, $a2, 0x7E64
    ctx->r6 = ADD32(ctx->r6, 0X7E64);
    // 0x8018DEB4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8018DEB8: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x8018DEBC: addiu       $t2, $zero, -0x10
    ctx->r10 = ADD32(0, -0X10);
    // 0x8018DEC0: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x8018DEC4: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x8018DEC8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8018DECC: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018DED0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8018DED4: lui         $t5, 0x603
    ctx->r13 = S32(0X603 << 16);
    // 0x8018DED8: addiu       $t5, $t5, 0x2580
    ctx->r13 = ADD32(ctx->r13, 0X2580);
    // 0x8018DEDC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8018DEE0: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x8018DEE4: lui         $t4, 0x600
    ctx->r12 = S32(0X600 << 16);
    // 0x8018DEE8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018DEEC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8018DEF0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8018DEF4: jal         0x80005740
    // 0x8018DEF8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_6;
    // 0x8018DEF8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_6:
    // 0x8018DEFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DF00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018DF04: jr          $ra
    // 0x8018DF08: nop

    return;
    // 0x8018DF08: nop

;}
RECOMP_FUNC void Map_RemainingLives_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AD7EC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801AD7F0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x801AD7F4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AD7F8: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AD7FC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801AD800: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x801AD804: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x801AD808: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801AD80C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x801AD810: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x801AD814: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AD818: jal         0x800B8DD0
    // 0x801AD81C: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801AD81C: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_0:
    // 0x801AD820: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AD824: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801AD828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AD82C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AD830: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801AD834: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801AD838: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AD83C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801AD840: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AD844: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AD848: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x801AD84C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x801AD850: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x801AD854: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x801AD858: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x801AD85C: lui         $a2, 0x602
    ctx->r6 = S32(0X602 << 16);
    // 0x801AD860: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801AD864: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x801AD868: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801AD86C: addiu       $a2, $a2, -0x2370
    ctx->r6 = ADD32(ctx->r6, -0X2370);
    // 0x801AD870: addiu       $a1, $a1, -0x23F0
    ctx->r5 = ADD32(ctx->r5, -0X23F0);
    // 0x801AD874: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801AD878: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x801AD87C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801AD880: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801AD884: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801AD888: jal         0x8009C320
    // 0x801AD88C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x801AD88C: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    after_1:
    // 0x801AD890: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AD894: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801AD898: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x801AD89C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AD8A0: lui         $t4, 0xFFFF
    ctx->r12 = S32(0XFFFF << 16);
    // 0x801AD8A4: ori         $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 | 0XFF;
    // 0x801AD8A8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801AD8AC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801AD8B0: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801AD8B4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801AD8B8: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x801AD8BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AD8C0: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x801AD8C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AD8C8: add.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x801AD8CC: lui         $a1, 0x602
    ctx->r5 = S32(0X602 << 16);
    // 0x801AD8D0: lui         $a2, 0x602
    ctx->r6 = S32(0X602 << 16);
    // 0x801AD8D4: add.s       $f18, $f22, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x801AD8D8: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    // 0x801AD8DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x801AD8E0: addiu       $a2, $a2, -0x2328
    ctx->r6 = ADD32(ctx->r6, -0X2328);
    // 0x801AD8E4: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x801AD8E8: addiu       $a1, $a1, -0x2360
    ctx->r5 = ADD32(ctx->r5, -0X2360);
    // 0x801AD8EC: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x801AD8F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AD8F4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801AD8F8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801AD8FC: jal         0x8009C320
    // 0x801AD900: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_2;
    // 0x801AD900: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x801AD904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AD908: jal         0x800B8DD0
    // 0x801AD90C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x801AD90C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_3:
    // 0x801AD910: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801AD914: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AD918: lui         $t8, 0xFFFF
    ctx->r24 = S32(0XFFFF << 16);
    // 0x801AD91C: ori         $t8, $t8, 0xFF
    ctx->r24 = ctx->r24 | 0XFF;
    // 0x801AD920: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AD924: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801AD928: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801AD92C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AD930: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801AD934: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x801AD938: bnel        $at, $zero, L_801AD9A8
    if (ctx->r1 != 0) {
        // 0x801AD93C: lui         $at, 0x4204
        ctx->r1 = S32(0X4204 << 16);
            goto L_801AD9A8;
    }
    goto skip_0;
    // 0x801AD93C: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    skip_0:
    // 0x801AD940: jal         0x8008BCBC
    // 0x801AD944: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    HUD_CountDigits(rdram, ctx);
        goto after_4;
    // 0x801AD944: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x801AD948: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x801AD94C: addiu       $t0, $t9, -0x8
    ctx->r8 = ADD32(ctx->r25, -0X8);
    // 0x801AD950: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801AD954: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
    // 0x801AD958: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AD95C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801AD960: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x801AD964: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AD968: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801AD96C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x801AD970: add.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f20.fl + ctx->f4.fl;
    // 0x801AD974: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x801AD978: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AD97C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801AD980: add.s       $f10, $f22, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x801AD984: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AD988: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801AD98C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801AD990: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801AD994: jal         0x8009FEA0
    // 0x801AD998: nop

    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_5;
    // 0x801AD998: nop

    after_5:
    // 0x801AD99C: b           L_801AD9D8
    // 0x801AD9A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_801AD9D8;
    // 0x801AD9A0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801AD9A4: lui         $at, 0x4204
    ctx->r1 = S32(0X4204 << 16);
L_801AD9A8:
    // 0x801AD9A8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801AD9AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x801AD9B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AD9B4: add.s       $f4, $f20, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f18.fl;
    // 0x801AD9B8: add.s       $f10, $f22, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x801AD9BC: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801AD9C0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x801AD9C4: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x801AD9C8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801AD9CC: jal         0x8009FEA0
    // 0x801AD9D0: nop

    Graphics_DisplaySmallNumber(rdram, ctx);
        goto after_6;
    // 0x801AD9D0: nop

    after_6:
    // 0x801AD9D4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_801AD9D8:
    // 0x801AD9D8: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801AD9DC: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x801AD9E0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x801AD9E4: jr          $ra
    // 0x801AD9E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801AD9E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Map_Setup_Play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019F164: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8019F168: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8019F16C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019F170: lw          $t7, 0x78A0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78A0);
    // 0x8019F174: lui         $t9, 0x8016
    ctx->r25 = S32(0X8016 << 16);
    // 0x8019F178: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8019F17C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F180: addiu       $t9, $t9, 0x1AA0
    ctx->r25 = ADD32(ctx->r25, 0X1AA0);
    // 0x8019F184: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8019F188: sw          $t6, -0x268C($at)
    MEM_W(-0X268C, ctx->r1) = ctx->r14;
    // 0x8019F18C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8019F190: lh          $t0, 0x0($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X0);
    // 0x8019F194: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F198: addiu       $v1, $v1, 0x7C38
    ctx->r3 = ADD32(ctx->r3, 0X7C38);
    // 0x8019F19C: slti        $at, $t0, 0x64
    ctx->r1 = SIGNED(ctx->r8) < 0X64 ? 1 : 0;
    // 0x8019F1A0: bne         $at, $zero, L_8019F1B0
    if (ctx->r1 != 0) {
        // 0x8019F1A4: lui         $a1, 0x8017
        ctx->r5 = S32(0X8017 << 16);
            goto L_8019F1B0;
    }
    // 0x8019F1A4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x8019F1A8: addiu       $t1, $zero, 0x63
    ctx->r9 = ADD32(0, 0X63);
    // 0x8019F1AC: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
L_8019F1B0:
    // 0x8019F1B0: lui         $a2, 0x8017
    ctx->r6 = S32(0X8017 << 16);
    // 0x8019F1B4: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F1B8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x8019F1BC: addiu       $a3, $a3, 0x78E8
    ctx->r7 = ADD32(ctx->r7, 0X78E8);
    // 0x8019F1C0: addiu       $a0, $a0, 0x78D0
    ctx->r4 = ADD32(ctx->r4, 0X78D0);
    // 0x8019F1C4: addiu       $a2, $a2, 0x78F0
    ctx->r6 = ADD32(ctx->r6, 0X78F0);
    // 0x8019F1C8: addiu       $a1, $a1, 0x78B0
    ctx->r5 = ADD32(ctx->r5, 0X78B0);
L_8019F1CC:
    // 0x8019F1CC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8019F1D0: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8019F1D4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8019F1D8: sltu        $at, $a0, $a3
    ctx->r1 = ctx->r4 < ctx->r7 ? 1 : 0;
    // 0x8019F1DC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8019F1E0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8019F1E4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8019F1E8: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x8019F1EC: sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
    // 0x8019F1F0: bne         $at, $zero, L_8019F1CC
    if (ctx->r1 != 0) {
        // 0x8019F1F4: sw          $t2, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r10;
            goto L_8019F1CC;
    }
    // 0x8019F1F4: sw          $t2, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r10;
    // 0x8019F1F8: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019F1FC: lui         $a0, 0x8017
    ctx->r4 = S32(0X8017 << 16);
    // 0x8019F200: addiu       $a0, $a0, 0x7C48
    ctx->r4 = ADD32(ctx->r4, 0X7C48);
    // 0x8019F204: addiu       $v1, $v1, 0x7C3C
    ctx->r3 = ADD32(ctx->r3, 0X7C3C);
    // 0x8019F208: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8019F20C: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
L_8019F210:
    // 0x8019F210: bnel        $t3, $zero, L_8019F220
    if (ctx->r11 != 0) {
        // 0x8019F214: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8019F220;
    }
    goto skip_0;
    // 0x8019F214: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x8019F218: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8019F21C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8019F220:
    // 0x8019F220: bnel        $v1, $a0, L_8019F210
    if (ctx->r3 != ctx->r4) {
        // 0x8019F224: lw          $t3, 0x0($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X0);
            goto L_8019F210;
    }
    goto skip_1;
    // 0x8019F224: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8019F228: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x8019F22C: lbu         $t4, 0x7930($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X7930);
    // 0x8019F230: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F234: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019F238: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x8019F23C: jal         0x801A6480
    // 0x8019F240: sw          $t4, -0x26C4($at)
    MEM_W(-0X26C4, ctx->r1) = ctx->r12;
    Map_GetPlanetId(rdram, ctx);
        goto after_0;
    // 0x8019F240: sw          $t4, -0x26C4($at)
    MEM_W(-0X26C4, ctx->r1) = ctx->r12;
    after_0:
    // 0x8019F244: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019F248: addiu       $v1, $v1, -0x26AC
    ctx->r3 = ADD32(ctx->r3, -0X26AC);
    // 0x8019F24C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8019F250: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F254: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019F258: sw          $v0, -0x26B0($at)
    MEM_W(-0X26B0, ctx->r1) = ctx->r2;
    // 0x8019F25C: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x8019F260: jal         0x8019FD1C
    // 0x8019F264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    Map_PlanetSaveSlot_Setup(rdram, ctx);
        goto after_1;
    // 0x8019F264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8019F268: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F26C: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019F270: sw          $v0, -0x2680($at)
    MEM_W(-0X2680, ctx->r1) = ctx->r2;
    // 0x8019F274: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x8019F278: jal         0x8019FD1C
    // 0x8019F27C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    Map_PlanetSaveSlot_Setup(rdram, ctx);
        goto after_2;
    // 0x8019F27C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x8019F280: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019F284: lw          $a0, -0x7DCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7DCC);
    // 0x8019F288: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8019F28C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019F290: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8019F294: lbu         $t6, 0x3180($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X3180);
    // 0x8019F298: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8019F29C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8019F2A0: bne         $t6, $at, L_8019F2C8
    if (ctx->r14 != ctx->r1) {
        // 0x8019F2A4: nop
    
            goto L_8019F2C8;
    }
    // 0x8019F2A4: nop

    // 0x8019F2A8: lw          $t7, 0x7B48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7B48);
    // 0x8019F2AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F2B0: sw          $a1, -0x2674($at)
    MEM_W(-0X2674, ctx->r1) = ctx->r5;
    // 0x8019F2B4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F2B8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019F2BC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8019F2C0: jal         0x8019FD1C
    // 0x8019F2C4: sw          $a1, 0x7BB0($at)
    MEM_W(0X7BB0, ctx->r1) = ctx->r5;
    Map_PlanetSaveSlot_Setup(rdram, ctx);
        goto after_3;
    // 0x8019F2C4: sw          $a1, 0x7BB0($at)
    MEM_W(0X7BB0, ctx->r1) = ctx->r5;
    after_3:
L_8019F2C8:
    // 0x8019F2C8: jal         0x800C3084
    // 0x8019F2CC: nop

    Save_Write(rdram, ctx);
        goto after_4;
    // 0x8019F2CC: nop

    after_4:
    // 0x8019F2D0: jal         0x8019F97C
    // 0x8019F2D4: nop

    Map_Level_CamSetup(rdram, ctx);
        goto after_5;
    // 0x8019F2D4: nop

    after_5:
    // 0x8019F2D8: jal         0x8019F83C
    // 0x8019F2DC: nop

    Map_PathStatus_Setup(rdram, ctx);
        goto after_6;
    // 0x8019F2DC: nop

    after_6:
    // 0x8019F2E0: jal         0x8019FA1C
    // 0x8019F2E4: nop

    Map_CurrentPlanet_SetAlpha(rdram, ctx);
        goto after_7;
    // 0x8019F2E4: nop

    after_7:
    // 0x8019F2E8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019F2EC: lw          $v0, -0x26C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26C4);
    // 0x8019F2F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019F2F4: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x8019F2F8: beq         $v0, $zero, L_8019F31C
    if (ctx->r2 == 0) {
        // 0x8019F2FC: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8019F31C;
    }
    // 0x8019F2FC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019F300: beq         $v0, $at, L_8019F344
    if (ctx->r2 == ctx->r1) {
        // 0x8019F304: lui         $t2, 0x801D
        ctx->r10 = S32(0X801D << 16);
            goto L_8019F344;
    }
    // 0x8019F304: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x8019F308: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019F30C: beq         $v0, $at, L_8019F36C
    if (ctx->r2 == ctx->r1) {
        // 0x8019F310: lui         $t5, 0x801D
        ctx->r13 = S32(0X801D << 16);
            goto L_8019F36C;
    }
    // 0x8019F310: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x8019F314: b           L_8019F390
    // 0x8019F318: nop

        goto L_8019F390;
    // 0x8019F318: nop

L_8019F31C:
    // 0x8019F31C: lw          $t9, -0x26AC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26AC);
    // 0x8019F320: lui         $t1, 0x801B
    ctx->r9 = S32(0X801B << 16);
    // 0x8019F324: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F328: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8019F32C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x8019F330: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8019F334: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8019F338: lw          $t1, -0xB34($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB34);
    // 0x8019F33C: b           L_8019F390
    // 0x8019F340: sw          $t1, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r9;
        goto L_8019F390;
    // 0x8019F340: sw          $t1, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r9;
L_8019F344:
    // 0x8019F344: lw          $t2, -0x26AC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X26AC);
    // 0x8019F348: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x8019F34C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F350: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8019F354: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x8019F358: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8019F35C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8019F360: lw          $t4, -0xB30($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB30);
    // 0x8019F364: b           L_8019F390
    // 0x8019F368: sw          $t4, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r12;
        goto L_8019F390;
    // 0x8019F368: sw          $t4, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r12;
L_8019F36C:
    // 0x8019F36C: lw          $t5, -0x26AC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X26AC);
    // 0x8019F370: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8019F374: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F378: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8019F37C: subu        $t6, $t6, $t5
    ctx->r14 = SUB32(ctx->r14, ctx->r13);
    // 0x8019F380: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8019F384: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8019F388: lw          $t7, -0xB2C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB2C);
    // 0x8019F38C: sw          $t7, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r15;
L_8019F390:
    // 0x8019F390: lw          $t8, 0x7B48($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B48);
    // 0x8019F394: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019F398: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8019F39C: jal         0x8019FC04
    // 0x8019F3A0: sw          $t9, 0x7B48($at)
    MEM_W(0X7B48, ctx->r1) = ctx->r25;
    Map_PlanetExplosions_Setup(rdram, ctx);
        goto after_8;
    // 0x8019F3A0: sw          $t9, 0x7B48($at)
    MEM_W(0X7B48, ctx->r1) = ctx->r25;
    after_8:
    // 0x8019F3A4: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x8019F3A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019F3AC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F3B0: sw          $zero, -0x103C($at)
    MEM_W(-0X103C, ctx->r1) = 0;
    // 0x8019F3B4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F3B8: sw          $zero, -0x1030($at)
    MEM_W(-0X1030, ctx->r1) = 0;
    // 0x8019F3BC: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8019F3C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019F3C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F3C8: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x8019F3CC: swc1        $f4, -0x1020($at)
    MEM_W(-0X1020, ctx->r1) = ctx->f4.u32l;
    // 0x8019F3D0: addiu       $v0, $v0, -0x1018
    ctx->r2 = ADD32(ctx->r2, -0X1018);
    // 0x8019F3D4: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x8019F3D8: addiu       $v1, $v1, -0x1028
    ctx->r3 = ADD32(ctx->r3, -0X1028);
    // 0x8019F3DC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8019F3E0: lui         $t0, 0x801D
    ctx->r8 = S32(0X801D << 16);
    // 0x8019F3E4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8019F3E8: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8019F3EC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8019F3F0: lw          $t0, -0x26C4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X26C4);
    // 0x8019F3F4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019F3F8: lui         $at, 0x8016
    ctx->r1 = S32(0X8016 << 16);
    // 0x8019F3FC: beq         $t0, $zero, L_8019F408
    if (ctx->r8 == 0) {
        // 0x8019F400: addiu       $t2, $zero, 0x5
        ctx->r10 = ADD32(0, 0X5);
            goto L_8019F408;
    }
    // 0x8019F400: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x8019F404: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_8019F408:
    // 0x8019F408: sw          $zero, 0x1A98($at)
    MEM_W(0X1A98, ctx->r1) = 0;
    // 0x8019F40C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F410: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
    // 0x8019F414: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x8019F418: sw          $t2, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r10;
    // 0x8019F41C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019F420: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8019F424: jr          $ra
    // 0x8019F428: nop

    return;
    // 0x8019F428: nop

;}
RECOMP_FUNC void Option_RankingPlanetRoute_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019896C: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x80198970: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x80198974: sdc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X58, ctx->r29);
    // 0x80198978: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x8019897C: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x80198980: mtc1        $a1, $f28
    ctx->f28.u32l = ctx->r5;
    // 0x80198984: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80198988: addiu       $s2, $s2, -0x4C40
    ctx->r18 = ADD32(ctx->r18, -0X4C40);
    // 0x8019898C: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x80198990: sw          $fp, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r30;
    // 0x80198994: sw          $s7, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r23;
    // 0x80198998: sw          $s6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r22;
    // 0x8019899C: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x801989A0: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x801989A4: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x801989A8: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x801989AC: sdc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X60, ctx->r29);
    // 0x801989B0: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x801989B4: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x801989B8: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x801989BC: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x801989C0: sw          $a2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r6;
    // 0x801989C4: jal         0x80005708
    // 0x801989C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_0;
    // 0x801989C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x801989CC: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x801989D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801989D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801989D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801989DC: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x801989E0: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x801989E4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x801989E8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x801989EC: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801989F0: swc1        $f26, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f26.u32l;
    // 0x801989F4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x801989F8: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801989FC: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x80198A00: swc1        $f26, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f26.u32l;
    // 0x80198A04: jal         0x80006E3C
    // 0x80198A08: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    Matrix_LookAt(rdram, ctx);
        goto after_1;
    // 0x80198A08: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80198A0C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80198A10: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x80198A14: jal         0x80006EB8
    // 0x80198A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_2;
    // 0x80198A18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80198A1C: jal         0x800032B4
    // 0x80198A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Lib_InitOrtho(rdram, ctx);
        goto after_3;
    // 0x80198A20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80198A24: lui         $t8, 0x8018
    ctx->r24 = S32(0X8018 << 16);
    // 0x80198A28: addiu       $t8, $t8, -0x7790
    ctx->r24 = ADD32(ctx->r24, -0X7790);
    // 0x80198A2C: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x80198A30: lw          $t3, 0x108($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X108);
    // 0x80198A34: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80198A38: lhu         $t2, 0x4A($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X4A);
    // 0x80198A3C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80198A40: lwc1        $f24, -0xECC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0XECC);
    // 0x80198A44: sw          $zero, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = 0;
    // 0x80198A48: blez        $t3, L_8019911C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80198A4C: sw          $t2, 0xF4($sp)
        MEM_W(0XF4, ctx->r29) = ctx->r10;
            goto L_8019911C;
    }
    // 0x80198A4C: sw          $t2, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r10;
    // 0x80198A50: sll         $t4, $s1, 3
    ctx->r12 = S32(ctx->r17 << 3);
    // 0x80198A54: subu        $t4, $t4, $s1
    ctx->r12 = SUB32(ctx->r12, ctx->r17);
    // 0x80198A58: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80198A5C: lwc1        $f30, 0x7404($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X7404);
    // 0x80198A60: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80198A64: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    // 0x80198A68: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80198A6C: lui         $fp, 0x801B
    ctx->r30 = S32(0X801B << 16);
    // 0x80198A70: addiu       $fp, $fp, -0x1194
    ctx->r30 = ADD32(ctx->r30, -0X1194);
    // 0x80198A74: lwc1        $f22, 0x7408($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7408);
    // 0x80198A78: sw          $t5, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r13;
    // 0x80198A7C: lui         $s7, 0xFA00
    ctx->r23 = S32(0XFA00 << 16);
    // 0x80198A80: lui         $s5, 0x600
    ctx->r21 = S32(0X600 << 16);
L_80198A84:
    // 0x80198A84: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x80198A88: lbu         $s4, 0x5F($t6)
    ctx->r20 = MEM_BU(ctx->r14, 0X5F);
    // 0x80198A8C: srl         $t7, $s4, 4
    ctx->r15 = S32(U32(ctx->r20) >> 4);
    // 0x80198A90: andi        $t9, $t7, 0xF
    ctx->r25 = ctx->r15 & 0XF;
    // 0x80198A94: sltiu       $at, $t9, 0xE
    ctx->r1 = ctx->r25 < 0XE ? 1 : 0;
    // 0x80198A98: or          $s4, $t9, $zero
    ctx->r20 = ctx->r25 | 0;
    // 0x80198A9C: beq         $at, $zero, L_80198F60
    if (ctx->r1 == 0) {
        // 0x80198AA0: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_80198F60;
    }
    // 0x80198AA0: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x80198AA4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x80198AA8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80198AAC: addu        $at, $at, $t2
    gpr jr_addend_80198AB4 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80198AB0: lw          $t2, 0x740C($at)
    ctx->r10 = ADD32(ctx->r1, 0X740C);
    // 0x80198AB4: jr          $t2
    // 0x80198AB8: nop

    switch (jr_addend_80198AB4 >> 2) {
        case 0: goto L_80198C18; break;
        case 1: goto L_80198E84; break;
        case 2: goto L_80198DA8; break;
        case 3: goto L_80198D0C; break;
        case 4: goto L_80198D0C; break;
        case 5: goto L_80198D0C; break;
        case 6: goto L_80198F60; break;
        case 7: goto L_80198F60; break;
        case 8: goto L_80198F60; break;
        case 9: goto L_80198F60; break;
        case 10: goto L_80198F60; break;
        case 11: goto L_80198F60; break;
        case 12: goto L_80198F60; break;
        case 13: goto L_80198ABC; break;
        default: switch_error(__func__, 0x80198AB4, 0x801B740C);
    }
    // 0x80198AB8: nop

L_80198ABC:
    // 0x80198ABC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198AC0: jal         0x800B8DD0
    // 0x80198AC4: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x80198AC4: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    after_4:
    // 0x80198AC8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198ACC: lui         $t4, 0xF000
    ctx->r12 = S32(0XF000 << 16);
    // 0x80198AD0: ori         $t4, $t4, 0xFF
    ctx->r12 = ctx->r12 | 0XFF;
    // 0x80198AD4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80198AD8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80198ADC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80198AE0: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80198AE4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198AE8: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x80198AEC: lui         $t6, 0x1F00
    ctx->r14 = S32(0X1F00 << 16);
    // 0x80198AF0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80198AF4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80198AF8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80198AFC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80198B00: jal         0x80005708
    // 0x80198B04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_5;
    // 0x80198B04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80198B08: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80198B0C: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80198B10: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80198B14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80198B18: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80198B1C: jal         0x80005B00
    // 0x80198B20: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_6;
    // 0x80198B20: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_6:
    // 0x80198B24: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80198B28: lwc1        $f6, 0x7444($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7444);
    // 0x80198B2C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80198B30: lwc1        $f8, -0xED0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XED0);
    // 0x80198B34: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80198B38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80198B3C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80198B40: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80198B44: jal         0x80005FE0
    // 0x80198B48: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_7;
    // 0x80198B48: nop

    after_7:
    // 0x80198B4C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80198B50: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80198B54: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80198B58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80198B5C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80198B60: jal         0x80005C34
    // 0x80198B64: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x80198B64: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_8:
    // 0x80198B68: jal         0x80006EB8
    // 0x80198B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x80198B6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80198B70: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80198B74: lwc1        $f0, 0x7448($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7448);
    // 0x80198B78: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198B7C: sll         $t3, $s4, 2
    ctx->r11 = S32(ctx->r20 << 2);
    // 0x80198B80: addu        $s1, $fp, $t3
    ctx->r17 = ADD32(ctx->r30, ctx->r11);
    // 0x80198B84: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80198B88: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80198B8C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80198B90: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80198B94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80198B98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80198B9C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80198BA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198BA4: addiu       $t5, $zero, -0x80
    ctx->r13 = ADD32(0, -0X80);
    // 0x80198BA8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80198BAC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80198BB0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80198BB4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80198BB8: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80198BBC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198BC0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80198BC4: lui         $t9, 0x1F00
    ctx->r25 = S32(0X1F00 << 16);
    // 0x80198BC8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80198BCC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80198BD0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80198BD4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80198BD8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80198BDC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80198BE0: jal         0x80005C34
    // 0x80198BE4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_10;
    // 0x80198BE4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_10:
    // 0x80198BE8: jal         0x80006EB8
    // 0x80198BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_11;
    // 0x80198BEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80198BF0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198BF4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80198BF8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80198BFC: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80198C00: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80198C04: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80198C08: jal         0x80005740
    // 0x80198C0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_12;
    // 0x80198C0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_12:
    // 0x80198C10: b           L_801990CC
    // 0x80198C14: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
        goto L_801990CC;
    // 0x80198C14: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
L_80198C18:
    // 0x80198C18: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80198C1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80198C20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198C24: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80198C28: jal         0x800B8DD0
    // 0x80198C2C: add.s       $f20, $f28, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f28.fl + ctx->f16.fl;
    RCP_SetupDL(rdram, ctx);
        goto after_13;
    // 0x80198C2C: add.s       $f20, $f28, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f28.fl + ctx->f16.fl;
    after_13:
    // 0x80198C30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198C34: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80198C38: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80198C3C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80198C40: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80198C44: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80198C48: jal         0x80005708
    // 0x80198C4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_14;
    // 0x80198C4C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x80198C50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80198C54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80198C58: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80198C5C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80198C60: sub.s       $f4, $f24, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x80198C64: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80198C68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80198C6C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80198C70: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80198C74: jal         0x80005B00
    // 0x80198C78: nop

    Matrix_Translate(rdram, ctx);
        goto after_15;
    // 0x80198C78: nop

    after_15:
    // 0x80198C7C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80198C80: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80198C84: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80198C88: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80198C8C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80198C90: jal         0x80005C34
    // 0x80198C94: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_16;
    // 0x80198C94: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_16:
    // 0x80198C98: jal         0x80006EB8
    // 0x80198C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_17;
    // 0x80198C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x80198CA0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198CA4: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x80198CA8: addu        $s1, $fp, $t2
    ctx->r17 = ADD32(ctx->r30, ctx->r10);
    // 0x80198CAC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80198CB0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80198CB4: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80198CB8: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80198CBC: lui         $a1, 0x4190
    ctx->r5 = S32(0X4190 << 16);
    // 0x80198CC0: lui         $a2, 0xC1A0
    ctx->r6 = S32(0XC1A0 << 16);
    // 0x80198CC4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x80198CC8: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80198CCC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80198CD0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80198CD4: jal         0x80005B00
    // 0x80198CD8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_18;
    // 0x80198CD8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_18:
    // 0x80198CDC: jal         0x80006EB8
    // 0x80198CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_19;
    // 0x80198CE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x80198CE4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198CE8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80198CEC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80198CF0: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80198CF4: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x80198CF8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80198CFC: jal         0x80005740
    // 0x80198D00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_20;
    // 0x80198D00: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_20:
    // 0x80198D04: b           L_801990CC
    // 0x80198D08: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
        goto L_801990CC;
    // 0x80198D08: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
L_80198D0C:
    // 0x80198D0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198D10: jal         0x800B8DD0
    // 0x80198D14: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_21;
    // 0x80198D14: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_21:
    // 0x80198D18: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198D1C: addiu       $t7, $zero, -0x70
    ctx->r15 = ADD32(0, -0X70);
    // 0x80198D20: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80198D24: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80198D28: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80198D2C: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80198D30: jal         0x80005708
    // 0x80198D34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_22;
    // 0x80198D34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_22:
    // 0x80198D38: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80198D3C: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80198D40: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80198D44: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80198D48: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80198D4C: jal         0x80005B00
    // 0x80198D50: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_23;
    // 0x80198D50: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_23:
    // 0x80198D54: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80198D58: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80198D5C: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80198D60: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80198D64: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80198D68: jal         0x80005C34
    // 0x80198D6C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_24;
    // 0x80198D6C: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_24:
    // 0x80198D70: jal         0x80006EB8
    // 0x80198D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_25;
    // 0x80198D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_25:
    // 0x80198D78: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198D7C: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    // 0x80198D80: addu        $t8, $fp, $t4
    ctx->r24 = ADD32(ctx->r30, ctx->r12);
    // 0x80198D84: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80198D88: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80198D8C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80198D90: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x80198D94: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80198D98: jal         0x80005740
    // 0x80198D9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_26;
    // 0x80198D9C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_26:
    // 0x80198DA0: b           L_801990CC
    // 0x80198DA4: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
        goto L_801990CC;
    // 0x80198DA4: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
L_80198DA8:
    // 0x80198DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198DAC: jal         0x800B8DD0
    // 0x80198DB0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_27;
    // 0x80198DB0: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_27:
    // 0x80198DB4: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80198DB8: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80198DBC: addiu       $t9, $zero, 0x46
    ctx->r25 = ADD32(0, 0X46);
    // 0x80198DC0: addiu       $t2, $zero, 0x64
    ctx->r10 = ADD32(0, 0X64);
    // 0x80198DC4: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80198DC8: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80198DCC: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x80198DD0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80198DD4: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80198DD8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x80198DDC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80198DE0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80198DE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198DE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80198DEC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80198DF0: jal         0x8000372C
    // 0x80198DF4: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    Lights_SetOneLight(rdram, ctx);
        goto after_28;
    // 0x80198DF4: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_28:
    // 0x80198DF8: jal         0x80005708
    // 0x80198DFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_29;
    // 0x80198DFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_29:
    // 0x80198E00: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80198E04: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80198E08: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80198E0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80198E10: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80198E14: jal         0x80005B00
    // 0x80198E18: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_30;
    // 0x80198E18: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_30:
    // 0x80198E1C: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x80198E20: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x80198E24: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80198E28: jal         0x80005D44
    // 0x80198E2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_31;
    // 0x80198E2C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_31:
    // 0x80198E30: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80198E34: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x80198E38: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80198E3C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80198E40: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80198E44: jal         0x80005C34
    // 0x80198E48: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_32;
    // 0x80198E48: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_32:
    // 0x80198E4C: jal         0x80006EB8
    // 0x80198E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_33;
    // 0x80198E50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_33:
    // 0x80198E54: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198E58: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80198E5C: addu        $t9, $fp, $t7
    ctx->r25 = ADD32(ctx->r30, ctx->r15);
    // 0x80198E60: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80198E64: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80198E68: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80198E6C: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x80198E70: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80198E74: jal         0x80005740
    // 0x80198E78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_34;
    // 0x80198E78: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_34:
    // 0x80198E7C: b           L_801990CC
    // 0x80198E80: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
        goto L_801990CC;
    // 0x80198E80: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
L_80198E84:
    // 0x80198E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198E88: jal         0x800B8DD0
    // 0x80198E8C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_35;
    // 0x80198E8C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_35:
    // 0x80198E90: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x80198E94: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x80198E98: addiu       $t8, $zero, 0x46
    ctx->r24 = ADD32(0, 0X46);
    // 0x80198E9C: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x80198EA0: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80198EA4: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x80198EA8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80198EAC: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80198EB0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80198EB4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80198EB8: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80198EBC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80198EC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198EC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80198EC8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80198ECC: jal         0x8000372C
    // 0x80198ED0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    Lights_SetOneLight(rdram, ctx);
        goto after_36;
    // 0x80198ED0: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_36:
    // 0x80198ED4: jal         0x80005708
    // 0x80198ED8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_37;
    // 0x80198ED8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_37:
    // 0x80198EDC: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80198EE0: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80198EE4: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80198EE8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80198EEC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80198EF0: jal         0x80005B00
    // 0x80198EF4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_38;
    // 0x80198EF4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_38:
    // 0x80198EF8: lui         $a1, 0x3EB2
    ctx->r5 = S32(0X3EB2 << 16);
    // 0x80198EFC: ori         $a1, $a1, 0xB8C2
    ctx->r5 = ctx->r5 | 0XB8C2;
    // 0x80198F00: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80198F04: jal         0x80005D44
    // 0x80198F08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateX(rdram, ctx);
        goto after_39;
    // 0x80198F08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_39:
    // 0x80198F0C: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x80198F10: mfc1        $a2, $f30
    ctx->r6 = (int32_t)ctx->f30.u32l;
    // 0x80198F14: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x80198F18: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80198F1C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80198F20: jal         0x80005C34
    // 0x80198F24: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_40;
    // 0x80198F24: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_40:
    // 0x80198F28: jal         0x80006EB8
    // 0x80198F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_41;
    // 0x80198F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x80198F30: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198F34: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    // 0x80198F38: addu        $t8, $fp, $t4
    ctx->r24 = ADD32(ctx->r30, ctx->r12);
    // 0x80198F3C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80198F40: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80198F44: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80198F48: lw          $t5, 0x0($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X0);
    // 0x80198F4C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80198F50: jal         0x80005740
    // 0x80198F54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_42;
    // 0x80198F54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_42:
    // 0x80198F58: b           L_801990CC
    // 0x80198F5C: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
        goto L_801990CC;
    // 0x80198F5C: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
L_80198F60:
    // 0x80198F60: lui         $s6, 0x606
    ctx->r22 = S32(0X606 << 16);
    // 0x80198F64: addiu       $s6, $s6, -0x3DD0
    ctx->r22 = ADD32(ctx->r22, -0X3DD0);
    // 0x80198F68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80198F6C: jal         0x800B8DD0
    // 0x80198F70: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    RCP_SetupDL(rdram, ctx);
        goto after_43;
    // 0x80198F70: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    after_43:
    // 0x80198F74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198F78: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80198F7C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80198F80: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80198F84: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80198F88: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80198F8C: jal         0x80005708
    // 0x80198F90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Push(rdram, ctx);
        goto after_44;
    // 0x80198F90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_44:
    // 0x80198F94: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80198F98: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x80198F9C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80198FA0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80198FA4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80198FA8: jal         0x80005B00
    // 0x80198FAC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Translate(rdram, ctx);
        goto after_45;
    // 0x80198FAC: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_45:
    // 0x80198FB0: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80198FB4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80198FB8: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80198FBC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80198FC0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80198FC4: jal         0x80005C34
    // 0x80198FC8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_46;
    // 0x80198FC8: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_46:
    // 0x80198FCC: jal         0x80006EB8
    // 0x80198FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_47;
    // 0x80198FD0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x80198FD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80198FD8: sll         $t4, $s4, 2
    ctx->r12 = S32(ctx->r20 << 2);
    // 0x80198FDC: addu        $s1, $fp, $t4
    ctx->r17 = ADD32(ctx->r30, ctx->r12);
    // 0x80198FE0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80198FE4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80198FE8: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x80198FEC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80198FF0: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80198FF4: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x80198FF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80198FFC: beq         $s3, $at, L_80199080
    if (ctx->r19 == ctx->r1) {
        // 0x80199000: addiu       $t5, $t5, -0x1158
        ctx->r13 = ADD32(ctx->r13, -0X1158);
            goto L_80199080;
    }
    // 0x80199000: addiu       $t5, $t5, -0x1158
    ctx->r13 = ADD32(ctx->r13, -0X1158);
    // 0x80199004: beq         $s1, $t5, L_80199080
    if (ctx->r17 == ctx->r13) {
        // 0x80199008: lui         $t6, 0x801B
        ctx->r14 = S32(0X801B << 16);
            goto L_80199080;
    }
    // 0x80199008: lui         $t6, 0x801B
    ctx->r14 = S32(0X801B << 16);
    // 0x8019900C: addiu       $t6, $t6, -0x1168
    ctx->r14 = ADD32(ctx->r14, -0X1168);
    // 0x80199010: beq         $s1, $t6, L_80199080
    if (ctx->r17 == ctx->r14) {
        // 0x80199014: lui         $s3, 0x801B
        ctx->r19 = S32(0X801B << 16);
            goto L_80199080;
    }
    // 0x80199014: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80199018: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x8019901C: addiu       $t7, $t7, -0x1178
    ctx->r15 = ADD32(ctx->r15, -0X1178);
    // 0x80199020: bne         $s1, $t7, L_8019904C
    if (ctx->r17 != ctx->r15) {
        // 0x80199024: addiu       $s3, $s3, 0x4A40
        ctx->r19 = ADD32(ctx->r19, 0X4A40);
            goto L_8019904C;
    }
    // 0x80199024: addiu       $s3, $s3, 0x4A40
    ctx->r19 = ADD32(ctx->r19, 0X4A40);
    // 0x80199028: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019902C: lui         $t2, 0x4040
    ctx->r10 = S32(0X4040 << 16);
    // 0x80199030: ori         $t2, $t2, 0x40FF
    ctx->r10 = ctx->r10 | 0X40FF;
    // 0x80199034: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80199038: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8019903C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80199040: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
    // 0x80199044: b           L_80199064
    // 0x80199048: nop

        goto L_80199064;
    // 0x80199048: nop

L_8019904C:
    // 0x8019904C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80199050: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80199054: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80199058: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8019905C: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80199060: sw          $s7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r23;
L_80199064:
    // 0x80199064: jal         0x80006EB8
    // 0x80199068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_48;
    // 0x80199068: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_48:
    // 0x8019906C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80199070: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80199074: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80199078: sw          $s3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r19;
    // 0x8019907C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
L_80199080:
    // 0x80199080: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199084: lwc1        $f0, 0x744C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X744C);
    // 0x80199088: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8019908C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80199090: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80199094: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80199098: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8019909C: jal         0x80005C34
    // 0x801990A0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_49;
    // 0x801990A0: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_49:
    // 0x801990A4: jal         0x80006EB8
    // 0x801990A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_50;
    // 0x801990A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x801990AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801990B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801990B4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801990B8: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x801990BC: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x801990C0: jal         0x80005740
    // 0x801990C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_51;
    // 0x801990C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_51:
    // 0x801990C8: lw          $t7, 0xF4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF4);
L_801990CC:
    // 0x801990CC: lw          $t9, 0xFC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XFC);
    // 0x801990D0: srav        $t2, $t7, $t9
    ctx->r10 = S32(SIGNED(ctx->r15) >> (ctx->r25 & 31));
    // 0x801990D4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x801990D8: beql        $t3, $zero, L_801990F4
    if (ctx->r11 == 0) {
        // 0x801990DC: lw          $t4, 0xFC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XFC);
            goto L_801990F4;
    }
    goto skip_0;
    // 0x801990DC: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    skip_0:
    // 0x801990E0: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x801990E4: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x801990E8: jal         0x80199198
    // 0x801990EC: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    Option_RankingRouteMedal_Draw(rdram, ctx);
        goto after_52;
    // 0x801990EC: mov.s       $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    ctx->f14.fl = ctx->f28.fl;
    after_52:
    // 0x801990F0: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
L_801990F4:
    // 0x801990F4: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x801990F8: lw          $t7, 0x108($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X108);
    // 0x801990FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199100: lwc1        $f6, -0xEC8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XEC8);
    // 0x80199104: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x80199108: addiu       $t6, $t5, 0x2
    ctx->r14 = ADD32(ctx->r13, 0X2);
    // 0x8019910C: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x80199110: sw          $t8, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r24;
    // 0x80199114: bne         $t8, $t7, L_80198A84
    if (ctx->r24 != ctx->r15) {
        // 0x80199118: add.s       $f24, $f24, $f6
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f6.fl;
            goto L_80198A84;
    }
    // 0x80199118: add.s       $f24, $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f6.fl;
L_8019911C:
    // 0x8019911C: jal         0x80005740
    // 0x80199120: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_53;
    // 0x80199120: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_53:
    // 0x80199124: jal         0x80192738
    // 0x80199128: nop

    Option_ScrollPlanetTexture(rdram, ctx);
        goto after_54;
    // 0x80199128: nop

    after_54:
    // 0x8019912C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199130: lwc1        $f8, -0xED0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XED0);
    // 0x80199134: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199138: lwc1        $f10, 0x7450($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7450);
    // 0x8019913C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80199140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80199144: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80199148: jal         0x8000316C
    // 0x8019914C: swc1        $f16, -0xED0($at)
    MEM_W(-0XED0, ctx->r1) = ctx->f16.u32l;
    Lib_InitPerspective(rdram, ctx);
        goto after_55;
    // 0x8019914C: swc1        $f16, -0xED0($at)
    MEM_W(-0XED0, ctx->r1) = ctx->f16.u32l;
    after_55:
    // 0x80199150: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x80199154: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80199158: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x8019915C: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x80199160: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x80199164: ldc1        $f28, 0x58($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X58);
    // 0x80199168: ldc1        $f30, 0x60($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X60);
    // 0x8019916C: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x80199170: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x80199174: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x80199178: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x8019917C: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x80199180: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x80199184: lw          $s6, 0x80($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X80);
    // 0x80199188: lw          $s7, 0x84($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X84);
    // 0x8019918C: lw          $fp, 0x88($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X88);
    // 0x80199190: jr          $ra
    // 0x80199194: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80199194: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void Map_801A48C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A48C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801A48C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801A48C8: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A48CC: addiu       $s0, $s0, -0x25B0
    ctx->r16 = ADD32(ctx->r16, -0X25B0);
    // 0x801A48D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A48D4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x801A48D8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A48DC: lwc1        $f4, 0x77CC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77CC);
    // 0x801A48E0: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A48E4: addiu       $a0, $a0, -0x25CC
    ctx->r4 = ADD32(ctx->r4, -0X25CC);
    // 0x801A48E8: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x801A48EC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x801A48F0: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A48F4: jal         0x8009BC2C
    // 0x801A48F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_0;
    // 0x801A48F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801A48FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4900: lwc1        $f6, 0x77D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77D0);
    // 0x801A4904: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A4908: addiu       $a0, $a0, -0x25C8
    ctx->r4 = ADD32(ctx->r4, -0X25C8);
    // 0x801A490C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x801A4910: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x801A4914: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A4918: jal         0x8009BC2C
    // 0x801A491C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_1;
    // 0x801A491C: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801A4920: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4924: lwc1        $f8, 0x77D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X77D4);
    // 0x801A4928: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A492C: addiu       $a0, $a0, -0x2604
    ctx->r4 = ADD32(ctx->r4, -0X2604);
    // 0x801A4930: lw          $a1, 0x8($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X8);
    // 0x801A4934: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x801A4938: lui         $a3, 0x42C8
    ctx->r7 = S32(0X42C8 << 16);
    // 0x801A493C: jal         0x8009BC2C
    // 0x801A4940: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A4940: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x801A4944: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4948: lwc1        $f18, -0x25CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X25CC);
    // 0x801A494C: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A4950: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4954: lwc1        $f6, -0x25C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25C8);
    // 0x801A4958: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x801A495C: lwc1        $f4, 0x4($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4);
    // 0x801A4960: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4964: lwc1        $f10, -0x2604($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2604);
    // 0x801A4968: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801A496C: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801A4970: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x801A4974: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A4978: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x801A497C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801A4980: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801A4984: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4988: mul.s       $f8, $f16, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x801A498C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801A4990: lwc1        $f18, -0x1598($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1598);
    // 0x801A4994: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801A4998: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A499C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A49A0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A49A4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x801A49A8: div.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801A49AC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801A49B0: lwc1        $f10, 0x77D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X77D8);
    // 0x801A49B4: mul.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801A49B8: nop

    // 0x801A49BC: mul.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801A49C0: jal         0x80023090
    // 0x801A49C4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x801A49C4: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x801A49C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A49CC: lwc1        $f4, 0x77DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X77DC);
    // 0x801A49D0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A49D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801A49D8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801A49DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A49E0: lwc1        $f10, -0x25CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X25CC);
    // 0x801A49E4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A49E8: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801A49EC: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A49F0: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x801A49F4: jal         0x80023090
    // 0x801A49F8: swc1        $f4, -0x260C($at)
    MEM_W(-0X260C, ctx->r1) = ctx->f4.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x801A49F8: swc1        $f4, -0x260C($at)
    MEM_W(-0X260C, ctx->r1) = ctx->f4.u32l;
    after_4:
    // 0x801A49FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A4A00: lwc1        $f6, 0x77E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X77E0);
    // 0x801A4A04: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A4A08: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801A4A0C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801A4A10: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4A14: lwc1        $f4, -0x25C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X25C8);
    // 0x801A4A18: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A4A1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A4A20: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x801A4A24: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x801A4A28: swc1        $f6, -0x2608($at)
    MEM_W(-0X2608, ctx->r1) = ctx->f6.u32l;
    // 0x801A4A2C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801A4A30: jr          $ra
    // 0x801A4A34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801A4A34: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void Map_ChangePath(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A53C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801A53CC: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x801A53D0: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A53D4: addiu       $t1, $t1, -0x26AC
    ctx->r9 = ADD32(ctx->r9, -0X26AC);
    // 0x801A53D8: addiu       $a3, $a3, -0xB60
    ctx->r7 = ADD32(ctx->r7, -0XB60);
    // 0x801A53DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801A53E0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801A53E4: addiu       $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
    // 0x801A53E8: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A53EC: lw          $t6, -0x1028($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X1028);
    // 0x801A53F0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A53F4: xori        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 ^ 0X1;
    // 0x801A53F8: sw          $t7, -0x1028($at)
    MEM_W(-0X1028, ctx->r1) = ctx->r15;
    // 0x801A53FC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x801A5400: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A5404: mflo        $t8
    ctx->r24 = lo;
    // 0x801A5408: addu        $v1, $a3, $t8
    ctx->r3 = ADD32(ctx->r7, ctx->r24);
    // 0x801A540C: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x801A5410: beql        $a2, $a1, L_801A5480
    if (ctx->r6 == ctx->r5) {
        // 0x801A5414: lw          $a1, 0x30($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X30);
            goto L_801A5480;
    }
    goto skip_0;
    // 0x801A5414: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    skip_0:
    // 0x801A5418: jal         0x801A655C
    // 0x801A541C: nop

    Map_GetPathId(rdram, ctx);
        goto after_0;
    // 0x801A541C: nop

    after_0:
    // 0x801A5420: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801A5424: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5428: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801A542C: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x801A5430: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x801A5434: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x801A5438: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x801A543C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A5440: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A5444: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x801A5448: addiu       $t1, $t1, -0x26AC
    ctx->r9 = ADD32(ctx->r9, -0X26AC);
    // 0x801A544C: sw          $zero, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = 0;
    // 0x801A5450: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x801A5454: lui         $t5, 0x801B
    ctx->r13 = S32(0X801B << 16);
    // 0x801A5458: addiu       $t5, $t5, -0xB60
    ctx->r13 = ADD32(ctx->r13, -0XB60);
    // 0x801A545C: sll         $t4, $a0, 3
    ctx->r12 = S32(ctx->r4 << 3);
    // 0x801A5460: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x801A5464: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x801A5468: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x801A546C: addiu       $a3, $a3, -0xB60
    ctx->r7 = ADD32(ctx->r7, -0XB60);
    // 0x801A5470: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x801A5474: addiu       $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
    // 0x801A5478: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x801A547C: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
L_801A5480:
    // 0x801A5480: beq         $a2, $a1, L_801A54D0
    if (ctx->r6 == ctx->r5) {
        // 0x801A5484: nop
    
            goto L_801A54D0;
    }
    // 0x801A5484: nop

    // 0x801A5488: jal         0x801A655C
    // 0x801A548C: nop

    Map_GetPathId(rdram, ctx);
        goto after_1;
    // 0x801A548C: nop

    after_1:
    // 0x801A5490: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A5494: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5498: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A549C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x801A54A0: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x801A54A4: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x801A54A8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801A54AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A54B0: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A54B4: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A54B8: lui         $a3, 0x801B
    ctx->r7 = S32(0X801B << 16);
    // 0x801A54BC: addiu       $t1, $t1, -0x26AC
    ctx->r9 = ADD32(ctx->r9, -0X26AC);
    // 0x801A54C0: addiu       $a3, $a3, -0xB60
    ctx->r7 = ADD32(ctx->r7, -0XB60);
    // 0x801A54C4: sw          $zero, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = 0;
    // 0x801A54C8: addiu       $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
    // 0x801A54CC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_801A54D0:
    // 0x801A54D0: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A54D4: addiu       $t2, $t2, -0x1134
    ctx->r10 = ADD32(ctx->r10, -0X1134);
    // 0x801A54D8: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x801A54DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A54E0: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801A54E4: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801A54E8: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x801A54EC: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x801A54F0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801A54F4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801A54F8: addiu       $t3, $t3, -0x2E8
    ctx->r11 = ADD32(ctx->r11, -0X2E8);
    // 0x801A54FC: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x801A5500: addu        $v1, $t9, $t3
    ctx->r3 = ADD32(ctx->r25, ctx->r11);
    // 0x801A5504: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x801A5508: sw          $zero, 0x14($v1)
    MEM_W(0X14, ctx->r3) = 0;
    // 0x801A550C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801A5510: lw          $t4, -0x26B0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X26B0);
    // 0x801A5514: lui         $t5, 0x801D
    ctx->r13 = S32(0X801D << 16);
    // 0x801A5518: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A551C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x801A5520: lw          $t5, -0x1028($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X1028);
    // 0x801A5524: bne         $t5, $zero, L_801A554C
    if (ctx->r13 != 0) {
        // 0x801A5528: nop
    
            goto L_801A554C;
    }
    // 0x801A5528: nop

    // 0x801A552C: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A5530: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5534: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x801A5538: mflo        $t6
    ctx->r14 = lo;
    // 0x801A553C: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x801A5540: lw          $t8, 0x2C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2C);
    // 0x801A5544: b           L_801A55C8
    // 0x801A5548: sw          $t8, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r24;
        goto L_801A55C8;
    // 0x801A5548: sw          $t8, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r24;
L_801A554C:
    // 0x801A554C: lw          $t9, -0x26C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X26C4);
    // 0x801A5550: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A5554: beql        $t9, $at, L_801A5598
    if (ctx->r25 == ctx->r1) {
        // 0x801A5558: lw          $a0, 0x0($t1)
        ctx->r4 = MEM_W(ctx->r9, 0X0);
            goto L_801A5598;
    }
    goto skip_1;
    // 0x801A5558: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    skip_1:
    // 0x801A555C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x801A5560: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5564: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A5568: mflo        $t3
    ctx->r11 = lo;
    // 0x801A556C: addu        $v1, $a3, $t3
    ctx->r3 = ADD32(ctx->r7, ctx->r11);
    // 0x801A5570: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    // 0x801A5574: beql        $a2, $a1, L_801A5588
    if (ctx->r6 == ctx->r5) {
        // 0x801A5578: lw          $t4, 0x2C($v1)
        ctx->r12 = MEM_W(ctx->r3, 0X2C);
            goto L_801A5588;
    }
    goto skip_2;
    // 0x801A5578: lw          $t4, 0x2C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2C);
    skip_2:
    // 0x801A557C: b           L_801A55C8
    // 0x801A5580: sw          $a1, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r5;
        goto L_801A55C8;
    // 0x801A5580: sw          $a1, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r5;
    // 0x801A5584: lw          $t4, 0x2C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2C);
L_801A5588:
    // 0x801A5588: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A558C: b           L_801A55C8
    // 0x801A5590: sw          $t4, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r12;
        goto L_801A55C8;
    // 0x801A5590: sw          $t4, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r12;
    // 0x801A5594: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
L_801A5598:
    // 0x801A5598: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A559C: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A55A0: mflo        $t5
    ctx->r13 = lo;
    // 0x801A55A4: addu        $v1, $a3, $t5
    ctx->r3 = ADD32(ctx->r7, ctx->r13);
    // 0x801A55A8: lw          $v0, 0x34($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X34);
    // 0x801A55AC: beql        $a2, $v0, L_801A55C0
    if (ctx->r6 == ctx->r2) {
        // 0x801A55B0: lw          $t6, 0x2C($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X2C);
            goto L_801A55C0;
    }
    goto skip_3;
    // 0x801A55B0: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
    skip_3:
    // 0x801A55B4: b           L_801A55C8
    // 0x801A55B8: sw          $v0, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r2;
        goto L_801A55C8;
    // 0x801A55B8: sw          $v0, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r2;
    // 0x801A55BC: lw          $t6, 0x2C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2C);
L_801A55C0:
    // 0x801A55C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A55C4: sw          $t6, -0x26A8($at)
    MEM_W(-0X26A8, ctx->r1) = ctx->r14;
L_801A55C8:
    // 0x801A55C8: lui         $a1, 0x801D
    ctx->r5 = S32(0X801D << 16);
    // 0x801A55CC: jal         0x801A655C
    // 0x801A55D0: lw          $a1, -0x26A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X26A8);
    Map_GetPathId(rdram, ctx);
        goto after_2;
    // 0x801A55D0: lw          $a1, -0x26A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X26A8);
    after_2:
    // 0x801A55D4: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x801A55D8: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x801A55DC: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A55E0: addiu       $t8, $t8, -0x2E8
    ctx->r24 = ADD32(ctx->r24, -0X2E8);
    // 0x801A55E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801A55E8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x801A55EC: lw          $a2, 0x0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X0);
    // 0x801A55F0: lui         $t3, 0x8017
    ctx->r11 = S32(0X8017 << 16);
    // 0x801A55F4: lui         $t2, 0x801D
    ctx->r10 = S32(0X801D << 16);
    // 0x801A55F8: addiu       $t3, $t3, 0x7BD8
    ctx->r11 = ADD32(ctx->r11, 0X7BD8);
    // 0x801A55FC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x801A5600: addiu       $t2, $t2, -0x1134
    ctx->r10 = ADD32(ctx->r10, -0X1134);
    // 0x801A5604: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x801A5608: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x801A560C: lui         $t1, 0x801D
    ctx->r9 = S32(0X801D << 16);
    // 0x801A5610: addu        $a1, $t9, $t3
    ctx->r5 = ADD32(ctx->r25, ctx->r11);
    // 0x801A5614: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801A5618: addiu       $t1, $t1, -0x26AC
    ctx->r9 = ADD32(ctx->r9, -0X26AC);
    // 0x801A561C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x801A5620: sw          $a3, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r7;
    // 0x801A5624: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x801A5628: beq         $t0, $a2, L_801A5638
    if (ctx->r8 == ctx->r6) {
        // 0x801A562C: sw          $t4, 0x14($v1)
        MEM_W(0X14, ctx->r3) = ctx->r12;
            goto L_801A5638;
    }
    // 0x801A562C: sw          $t4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r12;
    // 0x801A5630: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801A5634: bne         $a2, $at, L_801A5644
    if (ctx->r6 != ctx->r1) {
        // 0x801A5638: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_801A5644;
    }
L_801A5638:
    // 0x801A5638: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x801A563C: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x801A5640: sw          $v0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r2;
L_801A5644:
    // 0x801A5644: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5648: sw          $zero, -0x1160($at)
    MEM_W(-0X1160, ctx->r1) = 0;
    // 0x801A564C: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A5650: addiu       $t5, $zero, 0x64
    ctx->r13 = ADD32(0, 0X64);
    // 0x801A5654: sw          $t5, -0x115C($at)
    MEM_W(-0X115C, ctx->r1) = ctx->r13;
    // 0x801A5658: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A565C: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A5660: lw          $t6, -0x26A8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26A8);
    // 0x801A5664: sw          $a3, -0x1158($at)
    MEM_W(-0X1158, ctx->r1) = ctx->r7;
    // 0x801A5668: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A566C: sw          $a3, -0x1154($at)
    MEM_W(-0X1154, ctx->r1) = ctx->r7;
    // 0x801A5670: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801A5674: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x801A5678: lw          $t8, 0x7B48($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7B48);
    // 0x801A567C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5680: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x801A5684: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801A5688: jal         0x801A6368
    // 0x801A568C: sw          $t6, 0x7B90($at)
    MEM_W(0X7B90, ctx->r1) = ctx->r14;
    Map_CurrentLevel_Setup(rdram, ctx);
        goto after_3;
    // 0x801A568C: sw          $t6, 0x7B90($at)
    MEM_W(0X7B90, ctx->r1) = ctx->r14;
    after_3:
    // 0x801A5690: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A5694: lw          $a0, -0x26A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26A8);
    // 0x801A5698: lui         $t4, 0x801B
    ctx->r12 = S32(0X801B << 16);
    // 0x801A569C: addiu       $t4, $t4, -0xB60
    ctx->r12 = ADD32(ctx->r12, -0XB60);
    // 0x801A56A0: sll         $t3, $a0, 3
    ctx->r11 = S32(ctx->r4 << 3);
    // 0x801A56A4: subu        $t3, $t3, $a0
    ctx->r11 = SUB32(ctx->r11, ctx->r4);
    // 0x801A56A8: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x801A56AC: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x801A56B0: lw          $a1, 0x2C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X2C);
    // 0x801A56B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A56B8: beql        $a1, $at, L_801A571C
    if (ctx->r5 == ctx->r1) {
        // 0x801A56BC: lw          $a1, 0x30($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X30);
            goto L_801A571C;
    }
    goto skip_4;
    // 0x801A56BC: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
    skip_4:
    // 0x801A56C0: jal         0x801A655C
    // 0x801A56C4: nop

    Map_GetPathId(rdram, ctx);
        goto after_4;
    // 0x801A56C4: nop

    after_4:
    // 0x801A56C8: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A56CC: lw          $a0, -0x26A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X26A8);
    // 0x801A56D0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x801A56D4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A56D8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801A56DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801A56E0: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x801A56E4: sw          $t5, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r13;
    // 0x801A56E8: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x801A56EC: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x801A56F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801A56F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A56F8: lui         $t3, 0x801B
    ctx->r11 = S32(0X801B << 16);
    // 0x801A56FC: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x801A5700: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A5704: addiu       $t3, $t3, -0xB60
    ctx->r11 = ADD32(ctx->r11, -0XB60);
    // 0x801A5708: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801A570C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801A5710: sw          $t8, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = ctx->r24;
    // 0x801A5714: addu        $v1, $t9, $t3
    ctx->r3 = ADD32(ctx->r25, ctx->r11);
    // 0x801A5718: lw          $a1, 0x30($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X30);
L_801A571C:
    // 0x801A571C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801A5720: beql        $a1, $at, L_801A5764
    if (ctx->r5 == ctx->r1) {
        // 0x801A5724: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801A5764;
    }
    goto skip_5;
    // 0x801A5724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x801A5728: jal         0x801A655C
    // 0x801A572C: nop

    Map_GetPathId(rdram, ctx);
        goto after_5;
    // 0x801A572C: nop

    after_5:
    // 0x801A5730: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x801A5734: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801A5738: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x801A573C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801A5740: sll         $t8, $v0, 3
    ctx->r24 = S32(ctx->r2 << 3);
    // 0x801A5744: sw          $t4, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = ctx->r12;
    // 0x801A5748: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x801A574C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801A5750: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A5754: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x801A5758: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x801A575C: sw          $t6, -0x2D0($at)
    MEM_W(-0X2D0, ctx->r1) = ctx->r14;
    // 0x801A5760: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801A5764:
    // 0x801A5764: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801A5768: jr          $ra
    // 0x801A576C: nop

    return;
    // 0x801A576C: nop

;}
RECOMP_FUNC void Option_Ranking_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80196FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80196FA4: jal         0x801973C0
    // 0x80196FA8: nop

    Option_RankingMenu_Draw(rdram, ctx);
        goto after_0;
    // 0x80196FA8: nop

    after_0:
    // 0x80196FAC: jal         0x8019B9C0
    // 0x80196FB0: nop

    Option_DrawMenuLabel(rdram, ctx);
        goto after_1;
    // 0x80196FB0: nop

    after_1:
    // 0x80196FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80196FB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80196FBC: jr          $ra
    // 0x80196FC0: nop

    return;
    // 0x80196FC0: nop

;}
RECOMP_FUNC void Title_CsGreatFox_Setup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801894E8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x801894EC: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x801894F0: sw          $fp, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r30;
    // 0x801894F4: sw          $s7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r23;
    // 0x801894F8: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x801894FC: sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // 0x80189500: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x80189504: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x80189508: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x8018950C: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x80189510: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x80189514: sdc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X68, ctx->r29);
    // 0x80189518: sdc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X60, ctx->r29);
    // 0x8018951C: sdc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X58, ctx->r29);
    // 0x80189520: sdc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X50, ctx->r29);
    // 0x80189524: sdc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X48, ctx->r29);
    // 0x80189528: sdc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X40, ctx->r29);
    // 0x8018952C: addiu       $t6, $zero, 0x320
    ctx->r14 = ADD32(0, 0X320);
    // 0x80189530: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189534: sw          $t6, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = ctx->r14;
    // 0x80189538: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8018953C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80189540: sw          $t7, 0x7C98($at)
    MEM_W(0X7C98, ctx->r1) = ctx->r15;
    // 0x80189544: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189548: lwc1        $f30, 0x6E6C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X6E6C);
    // 0x8018954C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80189550: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80189554: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189558: lwc1        $f26, 0x6E70($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X6E70);
    // 0x8018955C: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x80189560: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80189564: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80189568: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8018956C: lui         $s2, 0x801B
    ctx->r18 = S32(0X801B << 16);
    // 0x80189570: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x80189574: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x80189578: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x8018957C: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x80189580: lui         $s7, 0x801B
    ctx->r23 = S32(0X801B << 16);
    // 0x80189584: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80189588: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018958C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80189590: addiu       $s0, $s0, 0x7CA0
    ctx->r16 = ADD32(ctx->r16, 0X7CA0);
    // 0x80189594: addiu       $s7, $s7, 0x7CF0
    ctx->r23 = ADD32(ctx->r23, 0X7CF0);
    // 0x80189598: addiu       $s6, $s6, 0x7CC8
    ctx->r22 = ADD32(ctx->r22, 0X7CC8);
    // 0x8018959C: addiu       $s5, $s5, 0x7D18
    ctx->r21 = ADD32(ctx->r21, 0X7D18);
    // 0x801895A0: addiu       $s4, $s4, 0x7C70
    ctx->r20 = ADD32(ctx->r20, 0X7C70);
    // 0x801895A4: addiu       $s3, $s3, 0x7C48
    ctx->r19 = ADD32(ctx->r19, 0X7C48);
    // 0x801895A8: addiu       $s2, $s2, 0x7C20
    ctx->r18 = ADD32(ctx->r18, 0X7C20);
    // 0x801895AC: addiu       $s1, $s1, 0x7BF8
    ctx->r17 = ADD32(ctx->r17, 0X7BF8);
    // 0x801895B0: addiu       $fp, $zero, 0x80
    ctx->r30 = ADD32(0, 0X80);
L_801895B4:
    // 0x801895B4: jal         0x80004EB0
    // 0x801895B8: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x801895B8: nop

    after_0:
    // 0x801895BC: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x801895C0: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x801895C4: jal         0x80004EB0
    // 0x801895C8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801895C8: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
    after_1:
    // 0x801895CC: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x801895D0: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x801895D4: add.s       $f10, $f8, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f28.fl;
    // 0x801895D8: jal         0x80004EB0
    // 0x801895DC: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_2;
    // 0x801895DC: swc1        $f10, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f10.u32l;
    after_2:
    // 0x801895E0: mul.s       $f16, $f0, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x801895E4: add.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x801895E8: jal         0x80004EB0
    // 0x801895EC: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    Rand_ZeroOne(rdram, ctx);
        goto after_3;
    // 0x801895EC: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    after_3:
    // 0x801895F0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801895F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801895F8: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801895FC: addiu       $t7, $t7, 0x7CC8
    ctx->r15 = ADD32(ctx->r15, 0X7CC8);
    // 0x80189600: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80189604: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80189608: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8018960C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80189610: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80189614: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80189618: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8018961C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80189620: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x80189624: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x80189628: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x8018962C: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80189630: sw          $a0, -0x4($s6)
    MEM_W(-0X4, ctx->r22) = ctx->r4;
    // 0x80189634: sw          $fp, -0x4($s7)
    MEM_W(-0X4, ctx->r23) = ctx->r30;
    // 0x80189638: addiu       $t6, $t9, 0x5
    ctx->r14 = ADD32(ctx->r25, 0X5);
    // 0x8018963C: sw          $t6, -0x4($s5)
    MEM_W(-0X4, ctx->r21) = ctx->r14;
    // 0x80189640: bne         $s0, $t7, L_801895B4
    if (ctx->r16 != ctx->r15) {
        // 0x80189644: sw          $zero, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = 0;
            goto L_801895B4;
    }
    // 0x80189644: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x80189648: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018964C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80189650: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189654: sw          $a0, -0x7964($at)
    MEM_W(-0X7964, ctx->r1) = ctx->r4;
    // 0x80189658: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018965C: sw          $a0, -0x7CC0($at)
    MEM_W(-0X7CC0, ctx->r1) = ctx->r4;
    // 0x80189660: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189664: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x80189668: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018966C: sw          $zero, -0x7CB0($at)
    MEM_W(-0X7CB0, ctx->r1) = 0;
    // 0x80189670: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189674: sw          $zero, -0x7CAC($at)
    MEM_W(-0X7CAC, ctx->r1) = 0;
    // 0x80189678: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x8018967C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189680: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189684: addiu       $t8, $zero, 0x65
    ctx->r24 = ADD32(0, 0X65);
    // 0x80189688: swc1        $f10, -0x6F90($at)
    MEM_W(-0X6F90, ctx->r1) = ctx->f10.u32l;
    // 0x8018968C: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80189690: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80189694: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189698: addiu       $t9, $zero, 0x6A
    ctx->r25 = ADD32(0, 0X6A);
    // 0x8018969C: swc1        $f16, -0x6F8C($at)
    MEM_W(-0X6F8C, ctx->r1) = ctx->f16.u32l;
    // 0x801896A0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801896A4: swc1        $f0, -0x6F88($at)
    MEM_W(-0X6F88, ctx->r1) = ctx->f0.u32l;
    // 0x801896A8: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801896AC: swc1        $f0, -0x6F84($at)
    MEM_W(-0X6F84, ctx->r1) = ctx->f0.u32l;
    // 0x801896B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801896B4: swc1        $f20, 0x7BDC($at)
    MEM_W(0X7BDC, ctx->r1) = ctx->f20.u32l;
    // 0x801896B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801896BC: swc1        $f20, 0x7BE0($at)
    MEM_W(0X7BE0, ctx->r1) = ctx->f20.u32l;
    // 0x801896C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801896C4: sw          $zero, 0x7BD4($at)
    MEM_W(0X7BD4, ctx->r1) = 0;
    // 0x801896C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801896CC: sw          $zero, 0x7BD8($at)
    MEM_W(0X7BD8, ctx->r1) = 0;
    // 0x801896D0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801896D4: swc1        $f20, -0x6F80($at)
    MEM_W(-0X6F80, ctx->r1) = ctx->f20.u32l;
    // 0x801896D8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801896DC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801896E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801896E4: addiu       $t6, $zero, 0x5C
    ctx->r14 = ADD32(0, 0X5C);
    // 0x801896E8: swc1        $f18, -0x6F7C($at)
    MEM_W(-0X6F7C, ctx->r1) = ctx->f18.u32l;
    // 0x801896EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801896F0: swc1        $f0, 0x7BB0($at)
    MEM_W(0X7BB0, ctx->r1) = ctx->f0.u32l;
    // 0x801896F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801896F8: swc1        $f0, 0x7BB4($at)
    MEM_W(0X7BB4, ctx->r1) = ctx->f0.u32l;
    // 0x801896FC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189700: sw          $zero, 0x7BD0($at)
    MEM_W(0X7BD0, ctx->r1) = 0;
    // 0x80189704: lui         $at, 0xC461
    ctx->r1 = S32(0XC461 << 16);
    // 0x80189708: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018970C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189710: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80189714: swc1        $f4, 0x7BB8($at)
    MEM_W(0X7BB8, ctx->r1) = ctx->f4.u32l;
    // 0x80189718: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x8018971C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80189720: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189724: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x80189728: swc1        $f6, 0x7BBC($at)
    MEM_W(0X7BBC, ctx->r1) = ctx->f6.u32l;
    // 0x8018972C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189730: swc1        $f22, 0x7BC0($at)
    MEM_W(0X7BC0, ctx->r1) = ctx->f22.u32l;
    // 0x80189734: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189738: swc1        $f22, 0x7BC4($at)
    MEM_W(0X7BC4, ctx->r1) = ctx->f22.u32l;
    // 0x8018973C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189740: swc1        $f20, -0x7938($at)
    MEM_W(-0X7938, ctx->r1) = ctx->f20.u32l;
    // 0x80189744: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x80189748: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018974C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189750: addiu       $v1, $v1, -0x7978
    ctx->r3 = ADD32(ctx->r3, -0X7978);
    // 0x80189754: swc1        $f8, -0x7934($at)
    MEM_W(-0X7934, ctx->r1) = ctx->f8.u32l;
    // 0x80189758: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018975C: sw          $t8, -0x7AB8($at)
    MEM_W(-0X7AB8, ctx->r1) = ctx->r24;
    // 0x80189760: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189764: sw          $t9, -0x7AB4($at)
    MEM_W(-0X7AB4, ctx->r1) = ctx->r25;
    // 0x80189768: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018976C: sw          $t6, -0x7AB0($at)
    MEM_W(-0X7AB0, ctx->r1) = ctx->r14;
    // 0x80189770: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189774: sw          $t7, -0x7AAC($at)
    MEM_W(-0X7AAC, ctx->r1) = ctx->r15;
    // 0x80189778: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x8018977C: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80189780: sw          $t8, -0x7AA8($at)
    MEM_W(-0X7AA8, ctx->r1) = ctx->r24;
    // 0x80189784: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x80189788: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8018978C: sw          $t9, -0x7AA4($at)
    MEM_W(-0X7AA4, ctx->r1) = ctx->r25;
    // 0x80189790: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x80189794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189798: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8018979C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801897A0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x801897A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801897A8: swc1        $f20, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f20.u32l;
    // 0x801897AC: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x801897B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801897B4: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x801897B8: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x801897BC: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
    // 0x801897C0: sw          $zero, -0x7CB8($at)
    MEM_W(-0X7CB8, ctx->r1) = 0;
    // 0x801897C4: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x801897C8: addiu       $v0, $v0, -0x79A8
    ctx->r2 = ADD32(ctx->r2, -0X79A8);
    // 0x801897CC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801897D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801897D4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801897D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801897DC: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801897E0: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x801897E4: lui         $t1, 0x801C
    ctx->r9 = S32(0X801C << 16);
    // 0x801897E8: lui         $t2, 0x801C
    ctx->r10 = S32(0X801C << 16);
    // 0x801897EC: lui         $t3, 0x801C
    ctx->r11 = S32(0X801C << 16);
    // 0x801897F0: addiu       $t3, $t3, -0x7954
    ctx->r11 = ADD32(ctx->r11, -0X7954);
    // 0x801897F4: addiu       $t2, $t2, -0x7958
    ctx->r10 = ADD32(ctx->r10, -0X7958);
    // 0x801897F8: addiu       $t1, $t1, -0x793C
    ctx->r9 = ADD32(ctx->r9, -0X793C);
    // 0x801897FC: addiu       $t0, $t0, -0x7940
    ctx->r8 = ADD32(ctx->r8, -0X7940);
    // 0x80189800: addiu       $a1, $a1, -0x7944
    ctx->r5 = ADD32(ctx->r5, -0X7944);
    // 0x80189804: swc1        $f20, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f20.u32l;
    // 0x80189808: swc1        $f20, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f20.u32l;
    // 0x8018980C: swc1        $f20, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f20.u32l;
    // 0x80189810: swc1        $f20, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f20.u32l;
    // 0x80189814: swc1        $f30, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f30.u32l;
    // 0x80189818: swc1        $f20, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f20.u32l;
    // 0x8018981C: swc1        $f20, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f20.u32l;
    // 0x80189820: swc1        $f20, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f20.u32l;
    // 0x80189824: swc1        $f28, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f28.u32l;
    // 0x80189828: swc1        $f20, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f20.u32l;
    // 0x8018982C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80189830: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x80189834: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80189838: lwc1        $f8, 0x6E74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6E74);
    // 0x8018983C: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80189840: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80189844: lui         $t4, 0x801C
    ctx->r12 = S32(0X801C << 16);
    // 0x80189848: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8018984C: addiu       $t5, $t5, -0x7948
    ctx->r13 = ADD32(ctx->r13, -0X7948);
    // 0x80189850: addiu       $t4, $t4, -0x794C
    ctx->r12 = ADD32(ctx->r12, -0X794C);
    // 0x80189854: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189858: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8018985C: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80189860: swc1        $f20, -0x7D64($at)
    MEM_W(-0X7D64, ctx->r1) = ctx->f20.u32l;
    // 0x80189864: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189868: swc1        $f0, -0x7D60($at)
    MEM_W(-0X7D60, ctx->r1) = ctx->f0.u32l;
    // 0x8018986C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80189870: swc1        $f20, -0x7D5C($at)
    MEM_W(-0X7D5C, ctx->r1) = ctx->f20.u32l;
    // 0x80189874: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80189878: addiu       $t6, $t6, 0x7980
    ctx->r14 = ADD32(ctx->r14, 0X7980);
    // 0x8018987C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80189880: lwc1        $f6, 0x0($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80189884: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80189888: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8018988C: lwc1        $f16, 0x0($t4)
    ctx->f16.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80189890: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80189894: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x80189898: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8018989C: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801898A0: addiu       $t7, $t7, 0x7988
    ctx->r15 = ADD32(ctx->r15, 0X7988);
    // 0x801898A4: addiu       $t8, $t8, 0x79A0
    ctx->r24 = ADD32(ctx->r24, 0X79A0);
    // 0x801898A8: addiu       $t9, $t9, 0x79B8
    ctx->r25 = ADD32(ctx->r25, 0X79B8);
    // 0x801898AC: addiu       $t6, $t6, 0x79C0
    ctx->r14 = ADD32(ctx->r14, 0X79C0);
    // 0x801898B0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801898B4: addiu       $a3, $a3, 0x7978
    ctx->r7 = ADD32(ctx->r7, 0X7978);
    // 0x801898B8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801898BC: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x801898C0: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x801898C4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801898C8: lw          $a2, 0x0($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X0);
    // 0x801898CC: lwc1        $f14, 0x0($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X0);
    // 0x801898D0: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801898D4: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x801898D8: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x801898DC: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801898E0: jal         0x801914AC
    // 0x801898E4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    Title_SetCamUp2(rdram, ctx);
        goto after_4;
    // 0x801898E4: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x801898E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801898EC: sw          $zero, 0x7BF0($at)
    MEM_W(0X7BF0, ctx->r1) = 0;
    // 0x801898F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801898F4: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x801898F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801898FC: jal         0x8001D444
    // 0x80189900: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_5;
    // 0x80189900: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_5:
    // 0x80189904: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x80189908: ldc1        $f20, 0x40($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X40);
    // 0x8018990C: ldc1        $f22, 0x48($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X48);
    // 0x80189910: ldc1        $f24, 0x50($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X50);
    // 0x80189914: ldc1        $f26, 0x58($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X58);
    // 0x80189918: ldc1        $f28, 0x60($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X60);
    // 0x8018991C: ldc1        $f30, 0x68($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X68);
    // 0x80189920: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80189924: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x80189928: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x8018992C: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80189930: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x80189934: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x80189938: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x8018993C: lw          $s7, 0x8C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X8C);
    // 0x80189940: lw          $fp, 0x90($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X90);
    // 0x80189944: jr          $ra
    // 0x80189948: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80189948: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void Option_InvoiceDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019E284: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8019E288: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8019E28C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8019E290: addiu       $s3, $s3, 0x7E64
    ctx->r19 = ADD32(ctx->r19, 0X7E64);
    // 0x8019E294: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8019E298: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8019E29C: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8019E2A0: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8019E2A4: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8019E2A8: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8019E2AC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8019E2B0: addiu       $t6, $zero, 0xDE
    ctx->r14 = ADD32(0, 0XDE);
    // 0x8019E2B4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8019E2B8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8019E2BC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8019E2C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8019E2C4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8019E2C8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8019E2CC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8019E2D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8019E2D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8019E2D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E2DC: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    // 0x8019E2E0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x8019E2E4: jal         0x8009F574
    // 0x8019E2E8: addiu       $a3, $zero, 0x127
    ctx->r7 = ADD32(0, 0X127);
    Graphics_FillRectangle(rdram, ctx);
        goto after_0;
    // 0x8019E2E8: addiu       $a3, $zero, 0x127
    ctx->r7 = ADD32(0, 0X127);
    after_0:
    // 0x8019E2EC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E2F0: jal         0x800B8DD0
    // 0x8019E2F4: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8019E2F4: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_1:
    // 0x8019E2F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019E2FC: lui         $s0, 0x800
    ctx->r16 = S32(0X800 << 16);
    // 0x8019E300: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x8019E304: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x8019E308: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019E30C: addiu       $s5, $s5, -0xC30
    ctx->r21 = ADD32(ctx->r21, -0XC30);
    // 0x8019E310: addiu       $s4, $s4, -0xC10
    ctx->r20 = ADD32(ctx->r20, -0XC10);
    // 0x8019E314: addiu       $s0, $s0, 0x680
    ctx->r16 = ADD32(ctx->r16, 0X680);
    // 0x8019E318: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019E31C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8019E320: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8019E324: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8019E328: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x8019E32C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8019E330: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8019E334: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8019E338: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8019E33C: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8019E340: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x8019E344: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8019E348: addiu       $a1, $a1, 0x0
    ctx->r5 = ADD32(ctx->r5, 0X0);
    // 0x8019E34C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E350: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8019E354: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x8019E358: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019E35C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8019E360: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019E364: jal         0x8009C320
    // 0x8019E368: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_2;
    // 0x8019E368: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8019E36C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8019E370: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019E374: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8019E378: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8019E37C: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8019E380: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8019E384: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8019E388: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8019E38C: addiu       $a1, $a1, 0x400
    ctx->r5 = ADD32(ctx->r5, 0X400);
    // 0x8019E390: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8019E394: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E398: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8019E39C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x8019E3A0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019E3A4: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8019E3A8: jal         0x8009C320
    // 0x8019E3AC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_3;
    // 0x8019E3AC: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8019E3B0: lui         $s0, 0x800
    ctx->r16 = S32(0X800 << 16);
    // 0x8019E3B4: addiu       $s0, $s0, 0x17A0
    ctx->r16 = ADD32(ctx->r16, 0X17A0);
    // 0x8019E3B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8019E3BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8019E3C0:
    // 0x8019E3C0: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x8019E3C4: lwc1        $f6, 0x4($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8019E3C8: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8019E3CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019E3D0: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x8019E3D4: addiu       $t7, $t7, 0x6A0
    ctx->r15 = ADD32(ctx->r15, 0X6A0);
    // 0x8019E3D8: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8019E3DC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8019E3E0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E3E4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019E3E8: bgez        $s2, L_8019E3F8
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8019E3EC: sra         $t6, $s2, 1
        ctx->r14 = S32(SIGNED(ctx->r18) >> 1);
            goto L_8019E3F8;
    }
    // 0x8019E3EC: sra         $t6, $s2, 1
    ctx->r14 = S32(SIGNED(ctx->r18) >> 1);
    // 0x8019E3F0: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x8019E3F4: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_8019E3F8:
    // 0x8019E3F8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x8019E3FC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8019E400: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8019E404: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8019E408: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019E40C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8019E410: jal         0x8009C320
    // 0x8019E414: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_4;
    // 0x8019E414: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x8019E418: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8019E41C: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x8019E420: bne         $at, $zero, L_8019E3C0
    if (ctx->r1 != 0) {
        // 0x8019E424: addiu       $s2, $s2, 0x1000
        ctx->r18 = ADD32(ctx->r18, 0X1000);
            goto L_8019E3C0;
    }
    // 0x8019E424: addiu       $s2, $s2, 0x1000
    ctx->r18 = ADD32(ctx->r18, 0X1000);
    // 0x8019E428: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x8019E42C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019E430: lwc1        $f4, 0x4($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8019E434: lwc1        $f18, 0x4($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8019E438: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8019E43C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8019E440: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8019E444: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8019E448: addiu       $a1, $a1, 0x16A0
    ctx->r5 = ADD32(ctx->r5, 0X16A0);
    // 0x8019E44C: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8019E450: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E454: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8019E458: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8019E45C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019E460: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8019E464: jal         0x8009C320
    // 0x8019E468: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_5;
    // 0x8019E468: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8019E46C: lui         $s0, 0x800
    ctx->r16 = S32(0X800 << 16);
    // 0x8019E470: addiu       $s0, $s0, 0x38C0
    ctx->r16 = ADD32(ctx->r16, 0X38C0);
    // 0x8019E474: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8019E478: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8019E47C:
    // 0x8019E47C: mtc1        $s1, $f18
    ctx->f18.u32l = ctx->r17;
    // 0x8019E480: lwc1        $f16, 0x8($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8019E484: lwc1        $f10, 0x8($s5)
    ctx->f10.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8019E488: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8019E48C: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x8019E490: addiu       $t1, $t1, 0x17C0
    ctx->r9 = ADD32(ctx->r9, 0X17C0);
    // 0x8019E494: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8019E498: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8019E49C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E4A0: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8019E4A4: bgez        $s2, L_8019E4B4
    if (SIGNED(ctx->r18) >= 0) {
        // 0x8019E4A8: sra         $t0, $s2, 1
        ctx->r8 = S32(SIGNED(ctx->r18) >> 1);
            goto L_8019E4B4;
    }
    // 0x8019E4A8: sra         $t0, $s2, 1
    ctx->r8 = S32(SIGNED(ctx->r18) >> 1);
    // 0x8019E4AC: addiu       $at, $s2, 0x1
    ctx->r1 = ADD32(ctx->r18, 0X1);
    // 0x8019E4B0: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_8019E4B4:
    // 0x8019E4B4: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    // 0x8019E4B8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8019E4BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8019E4C0: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8019E4C4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019E4C8: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8019E4CC: jal         0x8009C320
    // 0x8019E4D0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_6;
    // 0x8019E4D0: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_6:
    // 0x8019E4D4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8019E4D8: slti        $at, $s1, 0x40
    ctx->r1 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x8019E4DC: bne         $at, $zero, L_8019E47C
    if (ctx->r1 != 0) {
        // 0x8019E4E0: addiu       $s2, $s2, 0x1000
        ctx->r18 = ADD32(ctx->r18, 0X1000);
            goto L_8019E47C;
    }
    // 0x8019E4E0: addiu       $s2, $s2, 0x1000
    ctx->r18 = ADD32(ctx->r18, 0X1000);
    // 0x8019E4E4: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8019E4E8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019E4EC: lwc1        $f10, 0x8($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8019E4F0: lwc1        $f6, 0x8($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8019E4F4: lui         $a1, 0x800
    ctx->r5 = S32(0X800 << 16);
    // 0x8019E4F8: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8019E4FC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8019E500: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019E504: addiu       $a1, $a1, 0x37C0
    ctx->r5 = ADD32(ctx->r5, 0X37C0);
    // 0x8019E508: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8019E50C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E510: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8019E514: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x8019E518: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019E51C: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8019E520: jal         0x8009C320
    // 0x8019E524: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_7;
    // 0x8019E524: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_7:
    // 0x8019E528: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E52C: jal         0x800B8DD0
    // 0x8019E530: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_8;
    // 0x8019E530: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_8:
    // 0x8019E534: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019E538: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8019E53C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8019E540: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8019E544: sw          $t4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r12;
    // 0x8019E548: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8019E54C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8019E550: lui         $s2, 0x801
    ctx->r18 = S32(0X801 << 16);
    // 0x8019E554: addiu       $s2, $s2, -0x1E90
    ctx->r18 = ADD32(ctx->r18, -0X1E90);
    // 0x8019E558: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019E55C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8019E560:
    // 0x8019E560: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8019E564: lwc1        $f6, 0xC($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8019E568: lwc1        $f4, 0xC($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8019E56C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019E570: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8019E574: addu        $a1, $s2, $t7
    ctx->r5 = ADD32(ctx->r18, ctx->r15);
    // 0x8019E578: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E57C: addiu       $a2, $zero, 0xBC
    ctx->r6 = ADD32(0, 0XBC);
    // 0x8019E580: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8019E584: add.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8019E588: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8019E58C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019E590: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8019E594: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8019E598: jal         0x8009D418
    // 0x8019E59C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_9;
    // 0x8019E59C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_9:
    // 0x8019E5A0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019E5A4: slti        $at, $s0, 0x1E
    ctx->r1 = SIGNED(ctx->r16) < 0X1E ? 1 : 0;
    // 0x8019E5A8: bne         $at, $zero, L_8019E560
    if (ctx->r1 != 0) {
        // 0x8019E5AC: addiu       $s1, $s1, 0x178
        ctx->r17 = ADD32(ctx->r17, 0X178);
            goto L_8019E560;
    }
    // 0x8019E5AC: addiu       $s1, $s1, 0x178
    ctx->r17 = ADD32(ctx->r17, 0X178);
    // 0x8019E5B0: lui         $s1, 0x8016
    ctx->r17 = S32(0X8016 << 16);
    // 0x8019E5B4: addiu       $s1, $s1, 0x1714
    ctx->r17 = ADD32(ctx->r17, 0X1714);
    // 0x8019E5B8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019E5BC: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8019E5C0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8019E5C4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8019E5C8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x8019E5CC: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8019E5D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8019E5D4: jal         0x8008BCBC
    // 0x8019E5D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    HUD_CountDigits(rdram, ctx);
        goto after_10;
    // 0x8019E5D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_10:
    // 0x8019E5DC: addiu       $s2, $zero, 0xD
    ctx->r18 = ADD32(0, 0XD);
    // 0x8019E5E0: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019E5E4: lwc1        $f16, 0x18($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X18);
    // 0x8019E5E8: lwc1        $f18, 0x18($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X18);
    // 0x8019E5EC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x8019E5F0: mflo        $t1
    ctx->r9 = lo;
    // 0x8019E5F4: addiu       $t2, $t1, -0xD
    ctx->r10 = ADD32(ctx->r9, -0XD);
    // 0x8019E5F8: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8019E5FC: nop

    // 0x8019E600: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019E604: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8019E608: sub.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x8019E60C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8019E610: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8019E614: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x8019E618: jal         0x800A100C
    // 0x8019E61C: nop

    Graphics_DisplayLargeNumber(rdram, ctx);
        goto after_11;
    // 0x8019E61C: nop

    after_11:
    // 0x8019E620: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8019E624: sll         $a0, $s0, 6
    ctx->r4 = S32(ctx->r16 << 6);
    // 0x8019E628: jal         0x8008BCBC
    // 0x8019E62C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    HUD_CountDigits(rdram, ctx);
        goto after_12;
    // 0x8019E62C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_12:
    // 0x8019E630: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8019E634: lwc1        $f16, 0x1C($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X1C);
    // 0x8019E638: lwc1        $f4, 0x1C($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x8019E63C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8019E640: mflo        $t6
    ctx->r14 = lo;
    // 0x8019E644: addiu       $t7, $t6, -0xD
    ctx->r15 = ADD32(ctx->r14, -0XD);
    // 0x8019E648: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8019E64C: nop

    // 0x8019E650: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8019E654: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019E658: sub.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8019E65C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8019E660: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8019E664: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8019E668: jal         0x800A100C
    // 0x8019E66C: nop

    Graphics_DisplayLargeNumber(rdram, ctx);
        goto after_13;
    // 0x8019E66C: nop

    after_13:
    // 0x8019E670: lui         $t0, 0x801C
    ctx->r8 = S32(0X801C << 16);
    // 0x8019E674: lw          $t0, -0x6F70($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6F70);
    // 0x8019E678: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x8019E67C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8019E680: beq         $t0, $zero, L_8019E6FC
    if (ctx->r8 == 0) {
        // 0x8019E684: lui         $s1, 0x801
        ctx->r17 = S32(0X801 << 16);
            goto L_8019E6FC;
    }
    // 0x8019E684: lui         $s1, 0x801
    ctx->r17 = S32(0X801 << 16);
    // 0x8019E688: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8019E68C: lui         $t3, 0x7800
    ctx->r11 = S32(0X7800 << 16);
    // 0x8019E690: ori         $t3, $t3, 0xC0
    ctx->r11 = ctx->r11 | 0XC0;
    // 0x8019E694: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8019E698: sw          $t1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r9;
    // 0x8019E69C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8019E6A0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x8019E6A4: addiu       $s1, $s1, -0x2E10
    ctx->r17 = ADD32(ctx->r17, -0X2E10);
    // 0x8019E6A8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8019E6AC:
    // 0x8019E6AC: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x8019E6B0: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8019E6B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8019E6B8: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8019E6BC: lwc1        $f16, 0x14($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8019E6C0: lwc1        $f8, 0x14($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8019E6C4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8019E6C8: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019E6CC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8019E6D0: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8019E6D4: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8019E6D8: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x8019E6DC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8019E6E0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019E6E4: add.s       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8019E6E8: jal         0x8009D994
    // 0x8019E6EC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_14;
    // 0x8019E6EC: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_14:
    // 0x8019E6F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019E6F4: bne         $s0, $s2, L_8019E6AC
    if (ctx->r16 != ctx->r18) {
        // 0x8019E6F8: addiu       $s1, $s1, 0x500
        ctx->r17 = ADD32(ctx->r17, 0X500);
            goto L_8019E6AC;
    }
    // 0x8019E6F8: addiu       $s1, $s1, 0x500
    ctx->r17 = ADD32(ctx->r17, 0X500);
L_8019E6FC:
    // 0x8019E6FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8019E700: lhu         $v0, -0x2756($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2756);
    // 0x8019E704: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019E708: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8019E70C: andi        $t4, $v0, 0x10
    ctx->r12 = ctx->r2 & 0X10;
    // 0x8019E710: beq         $t4, $zero, L_8019E738
    if (ctx->r12 == 0) {
        // 0x8019E714: andi        $t5, $v0, 0x20
        ctx->r13 = ctx->r2 & 0X20;
            goto L_8019E738;
    }
    // 0x8019E714: andi        $t5, $v0, 0x20
    ctx->r13 = ctx->r2 & 0X20;
    // 0x8019E718: lw          $a0, -0xBF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XBF0);
    // 0x8019E71C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019E720: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8019E724: sw          $a0, -0xBF0($at)
    MEM_W(-0XBF0, ctx->r1) = ctx->r4;
    // 0x8019E728: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8019E72C: bne         $at, $zero, L_8019E738
    if (ctx->r1 != 0) {
        // 0x8019E730: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_8019E738;
    }
    // 0x8019E730: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019E734: sw          $zero, -0xBF0($at)
    MEM_W(-0XBF0, ctx->r1) = 0;
L_8019E738:
    // 0x8019E738: lui         $a0, 0x801B
    ctx->r4 = S32(0X801B << 16);
    // 0x8019E73C: beq         $t5, $zero, L_8019E754
    if (ctx->r13 == 0) {
        // 0x8019E740: lw          $a0, -0xBF0($a0)
        ctx->r4 = MEM_W(ctx->r4, -0XBF0);
            goto L_8019E754;
    }
    // 0x8019E740: lw          $a0, -0xBF0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XBF0);
    // 0x8019E744: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8019E748: bgez        $a0, L_8019E754
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8019E74C: nop
    
            goto L_8019E754;
    }
    // 0x8019E74C: nop

    // 0x8019E750: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
L_8019E754:
    // 0x8019E754: lhu         $v1, -0x276E($v1)
    ctx->r3 = MEM_HU(ctx->r3, -0X276E);
    // 0x8019E758: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8019E75C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019E760: andi        $t6, $v1, 0x800
    ctx->r14 = ctx->r3 & 0X800;
    // 0x8019E764: beq         $t6, $zero, L_8019E77C
    if (ctx->r14 == 0) {
        // 0x8019E768: andi        $t8, $v1, 0x400
        ctx->r24 = ctx->r3 & 0X400;
            goto L_8019E77C;
    }
    // 0x8019E768: andi        $t8, $v1, 0x400
    ctx->r24 = ctx->r3 & 0X400;
    // 0x8019E76C: addu        $v0, $s4, $t7
    ctx->r2 = ADD32(ctx->r20, ctx->r15);
    // 0x8019E770: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019E774: sub.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x8019E778: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
L_8019E77C:
    // 0x8019E77C: beq         $t8, $zero, L_8019E798
    if (ctx->r24 == 0) {
        // 0x8019E780: andi        $t0, $v1, 0x200
        ctx->r8 = ctx->r3 & 0X200;
            goto L_8019E798;
    }
    // 0x8019E780: andi        $t0, $v1, 0x200
    ctx->r8 = ctx->r3 & 0X200;
    // 0x8019E784: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8019E788: addu        $v0, $s4, $t9
    ctx->r2 = ADD32(ctx->r20, ctx->r25);
    // 0x8019E78C: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019E790: add.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8019E794: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
L_8019E798:
    // 0x8019E798: beq         $t0, $zero, L_8019E7B4
    if (ctx->r8 == 0) {
        // 0x8019E79C: andi        $t2, $v1, 0x100
        ctx->r10 = ctx->r3 & 0X100;
            goto L_8019E7B4;
    }
    // 0x8019E79C: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x8019E7A0: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8019E7A4: addu        $v0, $s5, $t1
    ctx->r2 = ADD32(ctx->r21, ctx->r9);
    // 0x8019E7A8: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019E7AC: sub.s       $f16, $f4, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x8019E7B0: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8019E7B4:
    // 0x8019E7B4: beq         $t2, $zero, L_8019E7D8
    if (ctx->r10 == 0) {
        // 0x8019E7B8: sw          $a0, -0xBF0($at)
        MEM_W(-0XBF0, ctx->r1) = ctx->r4;
            goto L_8019E7D8;
    }
    // 0x8019E7B8: sw          $a0, -0xBF0($at)
    MEM_W(-0XBF0, ctx->r1) = ctx->r4;
    // 0x8019E7BC: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8019E7C0: addu        $v0, $s5, $t3
    ctx->r2 = ADD32(ctx->r21, ctx->r11);
    // 0x8019E7C4: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8019E7C8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019E7CC: add.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8019E7D0: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x8019E7D4: sw          $a0, -0xBF0($at)
    MEM_W(-0XBF0, ctx->r1) = ctx->r4;
L_8019E7D8:
    // 0x8019E7D8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8019E7DC: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8019E7E0: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8019E7E4: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8019E7E8: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8019E7EC: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8019E7F0: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8019E7F4: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8019E7F8: jr          $ra
    // 0x8019E7FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8019E7FC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Option_DrawCardLabel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C120: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8019C124: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8019C128: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8019C12C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8019C130: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8019C134: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8019C138: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8019C13C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8019C140: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019C144: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019C148: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8019C14C: nop

    // 0x8019C150: bc1tl       L_8019C408
    if (c1cs) {
        // 0x8019C154: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8019C408;
    }
    goto skip_0;
    // 0x8019C154: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x8019C158: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8019C15C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8019C160: bc1tl       L_8019C408
    if (c1cs) {
        // 0x8019C164: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8019C408;
    }
    goto skip_1;
    // 0x8019C164: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8019C168: beq         $v0, $zero, L_8019C2DC
    if (ctx->r2 == 0) {
        // 0x8019C16C: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8019C2DC;
    }
    // 0x8019C16C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019C170: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8019C174: beq         $v0, $at, L_8019C19C
    if (ctx->r2 == ctx->r1) {
        // 0x8019C178: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8019C19C;
    }
    // 0x8019C178: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019C17C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019C180: beq         $v0, $at, L_8019C23C
    if (ctx->r2 == ctx->r1) {
        // 0x8019C184: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8019C23C;
    }
    // 0x8019C184: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019C188: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019C18C: beq         $v0, $at, L_8019C374
    if (ctx->r2 == ctx->r1) {
        // 0x8019C190: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_8019C374;
    }
    // 0x8019C190: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019C194: b           L_8019C408
    // 0x8019C198: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8019C408;
    // 0x8019C198: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8019C19C:
    // 0x8019C19C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019C1A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C1A4: jal         0x800B8DD0
    // 0x8019C1A8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019C1A8: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_0:
    // 0x8019C1AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019C1B0: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x8019C1B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C1B8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019C1BC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8019C1C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019C1C4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8019C1C8: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8019C1CC: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8019C1D0: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x8019C1D4: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x8019C1D8: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x8019C1DC: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8019C1E0: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8019C1E4: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x8019C1E8: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8019C1EC: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x8019C1F0: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8019C1F4: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x8019C1F8: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8019C1FC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8019C200: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019C204: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019C208: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019C20C: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019C210: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8019C214: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8019C218: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8019C21C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8019C220: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x8019C224: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x8019C228: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x8019C22C: jal         0x8009C320
    // 0x8019C230: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x8019C230: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8019C234: b           L_8019C408
    // 0x8019C238: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8019C408;
    // 0x8019C238: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8019C23C:
    // 0x8019C23C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019C240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C244: jal         0x800B8DD0
    // 0x8019C248: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8019C248: addiu       $a1, $zero, 0x4E
    ctx->r5 = ADD32(0, 0X4E);
    after_2:
    // 0x8019C24C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019C250: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8019C254: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C258: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8019C25C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8019C260: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8019C264: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8019C268: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8019C26C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8019C270: sll         $t7, $t4, 24
    ctx->r15 = S32(ctx->r12 << 24);
    // 0x8019C274: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8019C278: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x8019C27C: sll         $t1, $t8, 16
    ctx->r9 = S32(ctx->r24 << 16);
    // 0x8019C280: andi        $t3, $t0, 0xFF
    ctx->r11 = ctx->r8 & 0XFF;
    // 0x8019C284: sll         $t5, $t3, 8
    ctx->r13 = S32(ctx->r11 << 8);
    // 0x8019C288: or          $t2, $t7, $t1
    ctx->r10 = ctx->r15 | ctx->r9;
    // 0x8019C28C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x8019C290: andi        $t9, $t4, 0xFF
    ctx->r25 = ctx->r12 & 0XFF;
    // 0x8019C294: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8019C298: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8019C29C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8019C2A0: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019C2A4: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019C2A8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019C2AC: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019C2B0: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8019C2B4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x8019C2B8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8019C2BC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8019C2C0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x8019C2C4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x8019C2C8: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x8019C2CC: jal         0x8009D0BC
    // 0x8019C2D0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_3;
    // 0x8019C2D0: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8019C2D4: b           L_8019C408
    // 0x8019C2D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8019C408;
    // 0x8019C2D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8019C2DC:
    // 0x8019C2DC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019C2E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C2E4: jal         0x800B8DD0
    // 0x8019C2E8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_4;
    // 0x8019C2E8: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_4:
    // 0x8019C2EC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019C2F0: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x8019C2F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C2F8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x8019C2FC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8019C300: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8019C304: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8019C308: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x8019C30C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8019C310: sll         $t5, $t2, 24
    ctx->r13 = S32(ctx->r10 << 24);
    // 0x8019C314: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8019C318: andi        $t6, $t4, 0xFF
    ctx->r14 = ctx->r12 & 0XFF;
    // 0x8019C31C: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8019C320: andi        $t1, $t7, 0xFF
    ctx->r9 = ctx->r15 & 0XFF;
    // 0x8019C324: sll         $t0, $t1, 8
    ctx->r8 = S32(ctx->r9 << 8);
    // 0x8019C328: or          $t8, $t5, $t9
    ctx->r24 = ctx->r13 | ctx->r25;
    // 0x8019C32C: or          $t3, $t8, $t0
    ctx->r11 = ctx->r24 | ctx->r8;
    // 0x8019C330: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x8019C334: or          $t6, $t3, $t4
    ctx->r14 = ctx->r11 | ctx->r12;
    // 0x8019C338: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8019C33C: lwc1        $f16, 0x50($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019C340: lwc1        $f18, 0x54($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019C344: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019C348: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019C34C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8019C350: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8019C354: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8019C358: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019C35C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8019C360: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8019C364: jal         0x8009D994
    // 0x8019C368: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_5;
    // 0x8019C368: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_5:
    // 0x8019C36C: b           L_8019C408
    // 0x8019C370: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8019C408;
    // 0x8019C370: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8019C374:
    // 0x8019C374: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019C378: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C37C: jal         0x800B8DD0
    // 0x8019C380: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    RCP_SetupDL(rdram, ctx);
        goto after_6;
    // 0x8019C380: addiu       $a1, $zero, 0x4C
    ctx->r5 = ADD32(0, 0X4C);
    after_6:
    // 0x8019C384: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8019C388: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8019C38C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019C390: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8019C394: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8019C398: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8019C39C: lw          $t1, 0x60($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X60);
    // 0x8019C3A0: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8019C3A4: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8019C3A8: sll         $t8, $t1, 24
    ctx->r24 = S32(ctx->r9 << 24);
    // 0x8019C3AC: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x8019C3B0: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x8019C3B4: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8019C3B8: andi        $t5, $t6, 0xFF
    ctx->r13 = ctx->r14 & 0XFF;
    // 0x8019C3BC: sll         $t9, $t5, 8
    ctx->r25 = S32(ctx->r13 << 8);
    // 0x8019C3C0: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x8019C3C4: or          $t7, $t4, $t9
    ctx->r15 = ctx->r12 | ctx->r25;
    // 0x8019C3C8: andi        $t0, $t1, 0xFF
    ctx->r8 = ctx->r9 & 0XFF;
    // 0x8019C3CC: or          $t2, $t7, $t0
    ctx->r10 = ctx->r15 | ctx->r8;
    // 0x8019C3D0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8019C3D4: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8019C3D8: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8019C3DC: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8019C3E0: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8019C3E4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8019C3E8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8019C3EC: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x8019C3F0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8019C3F4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x8019C3F8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x8019C3FC: jal         0x8009D418
    // 0x8019C400: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_7;
    // 0x8019C400: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x8019C404: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8019C408:
    // 0x8019C408: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8019C40C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8019C410: jr          $ra
    // 0x8019C414: nop

    return;
    // 0x8019C414: nop

;}
RECOMP_FUNC void Option_Map_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801928BC: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x801928C0: addiu       $a0, $a0, -0x7CC0
    ctx->r4 = ADD32(ctx->r4, -0X7CC0);
    // 0x801928C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x801928C8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x801928CC: lui         $at, 0x8018
    ctx->r1 = S32(0X8018 << 16);
    // 0x801928D0: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x801928D4: bne         $v1, $v0, L_80192920
    if (ctx->r3 != ctx->r2) {
        // 0x801928D8: addiu       $t0, $v0, 0x20
        ctx->r8 = ADD32(ctx->r2, 0X20);
            goto L_80192920;
    }
    // 0x801928D8: addiu       $t0, $v0, 0x20
    ctx->r8 = ADD32(ctx->r2, 0X20);
    // 0x801928DC: sw          $zero, -0x7BF0($at)
    MEM_W(-0X7BF0, ctx->r1) = 0;
    // 0x801928E0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801928E4: sw          $t6, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r14;
    // 0x801928E8: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801928EC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x801928F0: sw          $t7, 0x7834($at)
    MEM_W(0X7834, ctx->r1) = ctx->r15;
    // 0x801928F4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801928F8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x801928FC: sw          $t8, 0x783C($at)
    MEM_W(0X783C, ctx->r1) = ctx->r24;
    // 0x80192900: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80192904: sw          $zero, 0x7B40($at)
    MEM_W(0X7B40, ctx->r1) = 0;
    // 0x80192908: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x8019290C: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80192910: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80192914: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80192918: jr          $ra
    // 0x8019291C: sw          $t9, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r25;
    return;
    // 0x8019291C: sw          $t9, -0x274C($at)
    MEM_W(-0X274C, ctx->r1) = ctx->r25;
L_80192920:
    // 0x80192920: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x80192924: bne         $at, $zero, L_80192930
    if (ctx->r1 != 0) {
        // 0x80192928: sw          $t0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r8;
            goto L_80192930;
    }
    // 0x80192928: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x8019292C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_80192930:
    // 0x80192930: jr          $ra
    // 0x80192934: nop

    return;
    // 0x80192934: nop

;}
RECOMP_FUNC void Title_Logos_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801906A0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801906A4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x801906A8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x801906AC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x801906B0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x801906B4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x801906B8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x801906BC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x801906C0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x801906C4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x801906C8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x801906CC: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801906D0: lw          $v0, 0x7BD4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7BD4);
    // 0x801906D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801906D8: beql        $v0, $at, L_80190924
    if (ctx->r2 == ctx->r1) {
        // 0x801906DC: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80190924;
    }
    goto skip_0;
    // 0x801906DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
    // 0x801906E0: beq         $v0, $zero, L_801906FC
    if (ctx->r2 == 0) {
        // 0x801906E4: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_801906FC;
    }
    // 0x801906E4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801906E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801906EC: beq         $v0, $at, L_8019080C
    if (ctx->r2 == ctx->r1) {
        // 0x801906F0: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_8019080C;
    }
    // 0x801906F0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801906F4: b           L_80190924
    // 0x801906F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80190924;
    // 0x801906F8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_801906FC:
    // 0x801906FC: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80190700: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190704: jal         0x800B8DD0
    // 0x80190708: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x80190708: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_0:
    // 0x8019070C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80190710: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80190714: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x80190718: addiu       $s5, $zero, -0x100
    ctx->r21 = ADD32(0, -0X100);
    // 0x8019071C: lw          $s3, 0x0($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X0);
    // 0x80190720: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80190724: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x80190728: addiu       $t6, $s3, 0x8
    ctx->r14 = ADD32(ctx->r19, 0X8);
    // 0x8019072C: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x80190730: sw          $s4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r20;
    // 0x80190734: lwc1        $f4, 0x7BDC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7BDC);
    // 0x80190738: lui         $a2, 0x601
    ctx->r6 = S32(0X601 << 16);
    // 0x8019073C: addiu       $a2, $a2, 0x47C0
    ctx->r6 = ADD32(ctx->r6, 0X47C0);
    // 0x80190740: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80190744: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80190748: addiu       $a1, $a1, 0x4140
    ctx->r5 = ADD32(ctx->r5, 0X4140);
    // 0x8019074C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190750: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80190754: addiu       $a3, $zero, 0x100
    ctx->r7 = ADD32(0, 0X100);
    // 0x80190758: addiu       $t1, $zero, 0xD
    ctx->r9 = ADD32(0, 0XD);
    // 0x8019075C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80190760: or          $t0, $t9, $s5
    ctx->r8 = ctx->r25 | ctx->r21;
    // 0x80190764: sw          $t0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r8;
    // 0x80190768: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019076C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x80190770: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80190774: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80190778: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019077C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80190780: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80190784: jal         0x8009C320
    // 0x80190788: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_1;
    // 0x80190788: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8019078C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80190790: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80190794: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190798: lw          $s3, 0x0($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X0);
    // 0x8019079C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801907A0: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801907A4: addiu       $t2, $s3, 0x8
    ctx->r10 = ADD32(ctx->r19, 0X8);
    // 0x801907A8: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x801907AC: sw          $s4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r20;
    // 0x801907B0: lwc1        $f16, 0x7BE0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7BE0);
    // 0x801907B4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801907B8: lui         $a2, 0x601
    ctx->r6 = S32(0X601 << 16);
    // 0x801907BC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801907C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801907C4: addiu       $a2, $a2, 0x48B0
    ctx->r6 = ADD32(ctx->r6, 0X48B0);
    // 0x801907C8: addiu       $a1, $a1, 0x47E0
    ctx->r5 = ADD32(ctx->r5, 0X47E0);
    // 0x801907CC: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x801907D0: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x801907D4: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x801907D8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x801907DC: or          $t6, $t5, $s5
    ctx->r14 = ctx->r13 | ctx->r21;
    // 0x801907E0: sw          $t6, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r14;
    // 0x801907E4: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x801907E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801907EC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801907F0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x801907F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801907F8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801907FC: jal         0x8009C320
    // 0x80190800: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_CI4(rdram, ctx);
        goto after_2;
    // 0x80190800: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80190804: b           L_80190924
    // 0x80190808: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_80190924;
    // 0x80190808: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8019080C:
    // 0x8019080C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x80190810: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190814: jal         0x800B8DD0
    // 0x80190818: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_3;
    // 0x80190818: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_3:
    // 0x8019081C: lui         $s4, 0xFA00
    ctx->r20 = S32(0XFA00 << 16);
    // 0x80190820: addiu       $s5, $zero, -0x100
    ctx->r21 = ADD32(0, -0X100);
    // 0x80190824: lw          $s3, 0x0($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X0);
    // 0x80190828: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019082C: lui         $s7, 0x600
    ctx->r23 = S32(0X600 << 16);
    // 0x80190830: addiu       $t8, $s3, 0x8
    ctx->r24 = ADD32(ctx->r19, 0X8);
    // 0x80190834: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x80190838: sw          $s4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r20;
    // 0x8019083C: lwc1        $f8, 0x7BDC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7BDC);
    // 0x80190840: lui         $s6, 0x801C
    ctx->r22 = S32(0X801C << 16);
    // 0x80190844: addiu       $s6, $s6, -0x6F88
    ctx->r22 = ADD32(ctx->r22, -0X6F88);
    // 0x80190848: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8019084C: lui         $s4, 0x801C
    ctx->r20 = S32(0X801C << 16);
    // 0x80190850: addiu       $s7, $s7, 0x6EA0
    ctx->r23 = ADD32(ctx->r23, 0X6EA0);
    // 0x80190854: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80190858: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8019085C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80190860: addiu       $fp, $zero, 0x50
    ctx->r30 = ADD32(0, 0X50);
    // 0x80190864: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80190868: or          $t2, $t1, $s5
    ctx->r10 = ctx->r9 | ctx->r21;
    // 0x8019086C: sw          $t2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r10;
    // 0x80190870: lui         $s5, 0x801C
    ctx->r21 = S32(0X801C << 16);
    // 0x80190874: lui         $s3, 0x801C
    ctx->r19 = S32(0X801C << 16);
    // 0x80190878: addiu       $s3, $s3, -0x6F90
    ctx->r19 = ADD32(ctx->r19, -0X6F90);
    // 0x8019087C: addiu       $s5, $s5, -0x6F8C
    ctx->r21 = ADD32(ctx->r21, -0X6F8C);
    // 0x80190880: addiu       $s4, $s4, -0x6F84
    ctx->r20 = ADD32(ctx->r20, -0X6F84);
L_80190884:
    // 0x80190884: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x80190888: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8019088C: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80190890: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80190894: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80190898: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8019089C: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x801908A0: sll         $t3, $s1, 1
    ctx->r11 = S32(ctx->r17 << 1);
    // 0x801908A4: addu        $a1, $s7, $t3
    ctx->r5 = ADD32(ctx->r23, ctx->r11);
    // 0x801908A8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801908AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801908B0: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x801908B4: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x801908B8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801908BC: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x801908C0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801908C4: jal         0x8009D418
    // 0x801908C8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_4;
    // 0x801908C8: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x801908CC: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x801908D0: bne         $s0, $fp, L_80190884
    if (ctx->r16 != ctx->r30) {
        // 0x801908D4: addiu       $s1, $s1, 0x800
        ctx->r17 = ADD32(ctx->r17, 0X800);
            goto L_80190884;
    }
    // 0x801908D4: addiu       $s1, $s1, 0x800
    ctx->r17 = ADD32(ctx->r17, 0X800);
    // 0x801908D8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801908DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801908E0: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x801908E4: lwc1        $f8, 0x0($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0X0);
    // 0x801908E8: lwc1        $f18, 0x0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801908EC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801908F0: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x801908F4: lui         $a1, 0x601
    ctx->r5 = S32(0X601 << 16);
    // 0x801908F8: addiu       $a1, $a1, -0x4160
    ctx->r5 = ADD32(ctx->r5, -0X4160);
    // 0x801908FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80190900: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80190904: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x80190908: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8019090C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80190910: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x80190914: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x80190918: jal         0x8009D418
    // 0x8019091C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_5;
    // 0x8019091C: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_5:
    // 0x80190920: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80190924:
    // 0x80190924: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80190928: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8019092C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80190930: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80190934: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80190938: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8019093C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80190940: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80190944: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80190948: jr          $ra
    // 0x8019094C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8019094C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void Option_Sound_Speaker_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801952B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801952B8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801952BC: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x801952C0: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x801952C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801952C8: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x801952CC: lw          $t6, -0x6D7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6D7C);
    // 0x801952D0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x801952D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801952D8: bnel        $a0, $t6, L_80195718
    if (ctx->r4 != ctx->r14) {
        // 0x801952DC: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80195718;
    }
    goto skip_0;
    // 0x801952DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_0:
    // 0x801952E0: lw          $v1, -0x6EB4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6EB4);
    // 0x801952E4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801952E8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801952EC: beq         $v1, $zero, L_8019531C
    if (ctx->r3 == 0) {
        // 0x801952F0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8019531C;
    }
    // 0x801952F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801952F4: beq         $v0, $a0, L_80195328
    if (ctx->r2 == ctx->r4) {
        // 0x801952F8: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_80195328;
    }
    // 0x801952F8: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x801952FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80195300: beq         $v0, $a2, L_801953CC
    if (ctx->r2 == ctx->r6) {
        // 0x80195304: lui         $a1, 0x801C
        ctx->r5 = S32(0X801C << 16);
            goto L_801953CC;
    }
    // 0x80195304: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80195308: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8019530C: beq         $v0, $at, L_80195460
    if (ctx->r2 == ctx->r1) {
        // 0x80195310: nop
    
            goto L_80195460;
    }
    // 0x80195310: nop

    // 0x80195314: b           L_8019549C
    // 0x80195318: nop

        goto L_8019549C;
    // 0x80195318: nop

L_8019531C:
    // 0x8019531C: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80195320: b           L_8019549C
    // 0x80195324: sw          $t7, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r15;
        goto L_8019549C;
    // 0x80195324: sw          $t7, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r15;
L_80195328:
    // 0x80195328: addiu       $a1, $a1, -0x6E88
    ctx->r5 = ADD32(ctx->r5, -0X6E88);
    // 0x8019532C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80195330: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80195334: addiu       $s0, $s0, -0x15D0
    ctx->r16 = ADD32(ctx->r16, -0X15D0);
    // 0x80195338: beq         $t8, $zero, L_80195348
    if (ctx->r24 == 0) {
        // 0x8019533C: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_80195348;
    }
    // 0x8019533C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195340: b           L_8019549C
    // 0x80195344: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_8019549C;
    // 0x80195344: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80195348:
    // 0x80195348: lwc1        $f2, 0x73B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73B0);
    // 0x8019534C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195350: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x80195354: addiu       $v0, $v0, -0x1560
    ctx->r2 = ADD32(ctx->r2, -0X1560);
    // 0x80195358: lwc1        $f0, 0x73B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73B4);
    // 0x8019535C: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x80195360: lwc1        $f18, -0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, -0X18);
    // 0x80195364: beq         $s0, $v0, L_80195398
    if (ctx->r16 == ctx->r2) {
        // 0x80195368: lwc1        $f16, -0x14($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, -0X14);
            goto L_80195398;
    }
    // 0x80195368: lwc1        $f16, -0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, -0X14);
L_8019536C:
    // 0x8019536C: add.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80195370: lwc1        $f12, -0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0X20);
    // 0x80195374: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80195378: add.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8019537C: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80195380: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x80195384: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80195388: swc1        $f14, -0x50($s0)
    MEM_W(-0X50, ctx->r16) = ctx->f14.u32l;
    // 0x8019538C: swc1        $f10, -0x4C($s0)
    MEM_W(-0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x80195390: bne         $s0, $v0, L_8019536C
    if (ctx->r16 != ctx->r2) {
        // 0x80195394: swc1        $f12, -0x58($s0)
        MEM_W(-0X58, ctx->r16) = ctx->f12.u32l;
            goto L_8019536C;
    }
    // 0x80195394: swc1        $f12, -0x58($s0)
    MEM_W(-0X58, ctx->r16) = ctx->f12.u32l;
L_80195398:
    // 0x80195398: lwc1        $f12, -0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0X20);
    // 0x8019539C: add.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x801953A0: add.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x801953A4: swc1        $f14, -0x18($s0)
    MEM_W(-0X18, ctx->r16) = ctx->f14.u32l;
    // 0x801953A8: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x801953AC: swc1        $f10, -0x14($s0)
    MEM_W(-0X14, ctx->r16) = ctx->f10.u32l;
    // 0x801953B0: swc1        $f12, -0x20($s0)
    MEM_W(-0X20, ctx->r16) = ctx->f12.u32l;
    // 0x801953B4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801953B8: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x801953BC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x801953C0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801953C4: b           L_8019549C
    // 0x801953C8: sw          $t9, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r25;
        goto L_8019549C;
    // 0x801953C8: sw          $t9, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r25;
L_801953CC:
    // 0x801953CC: addiu       $a1, $a1, -0x6E88
    ctx->r5 = ADD32(ctx->r5, -0X6E88);
    // 0x801953D0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x801953D4: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801953D8: addiu       $s0, $s0, -0x15D0
    ctx->r16 = ADD32(ctx->r16, -0X15D0);
    // 0x801953DC: bne         $t0, $zero, L_8019549C
    if (ctx->r8 != 0) {
        // 0x801953E0: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_8019549C;
    }
    // 0x801953E0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801953E4: lwc1        $f2, 0x73B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73B8);
    // 0x801953E8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801953EC: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801953F0: addiu       $v0, $v0, -0x1560
    ctx->r2 = ADD32(ctx->r2, -0X1560);
    // 0x801953F4: lwc1        $f0, 0x73BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73BC);
    // 0x801953F8: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x801953FC: lwc1        $f18, -0x18($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, -0X18);
    // 0x80195400: beq         $s0, $v0, L_80195434
    if (ctx->r16 == ctx->r2) {
        // 0x80195404: lwc1        $f16, -0x14($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, -0X14);
            goto L_80195434;
    }
    // 0x80195404: lwc1        $f16, -0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, -0X14);
L_80195408:
    // 0x80195408: sub.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8019540C: lwc1        $f12, -0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0X20);
    // 0x80195410: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80195414: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80195418: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8019541C: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x80195420: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80195424: swc1        $f14, -0x50($s0)
    MEM_W(-0X50, ctx->r16) = ctx->f14.u32l;
    // 0x80195428: swc1        $f10, -0x4C($s0)
    MEM_W(-0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x8019542C: bne         $s0, $v0, L_80195408
    if (ctx->r16 != ctx->r2) {
        // 0x80195430: swc1        $f12, -0x58($s0)
        MEM_W(-0X58, ctx->r16) = ctx->f12.u32l;
            goto L_80195408;
    }
    // 0x80195430: swc1        $f12, -0x58($s0)
    MEM_W(-0X58, ctx->r16) = ctx->f12.u32l;
L_80195434:
    // 0x80195434: lwc1        $f12, -0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, -0X20);
    // 0x80195438: sub.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x8019543C: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80195440: swc1        $f14, -0x18($s0)
    MEM_W(-0X18, ctx->r16) = ctx->f14.u32l;
    // 0x80195444: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80195448: swc1        $f10, -0x14($s0)
    MEM_W(-0X14, ctx->r16) = ctx->f10.u32l;
    // 0x8019544C: swc1        $f12, -0x20($s0)
    MEM_W(-0X20, ctx->r16) = ctx->f12.u32l;
    // 0x80195450: addiu       $t1, $v1, 0x1
    ctx->r9 = ADD32(ctx->r3, 0X1);
    // 0x80195454: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80195458: b           L_8019549C
    // 0x8019545C: sw          $t1, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r9;
        goto L_8019549C;
    // 0x8019545C: sw          $t1, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r9;
L_80195460:
    // 0x80195460: jal         0x80004EB0
    // 0x80195464: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_0;
    // 0x80195464: nop

    after_0:
    // 0x80195468: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8019546C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80195470: lui         $a1, 0x801C
    ctx->r5 = S32(0X801C << 16);
    // 0x80195474: addiu       $a1, $a1, -0x6E88
    ctx->r5 = ADD32(ctx->r5, -0X6E88);
    // 0x80195478: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8019547C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80195480: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80195484: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80195488: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8019548C: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x80195490: nop

    // 0x80195494: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x80195498: sw          $a0, -0x6EB4($at)
    MEM_W(-0X6EB4, ctx->r1) = ctx->r4;
L_8019549C:
    // 0x8019549C: lui         $s1, 0x801C
    ctx->r17 = S32(0X801C << 16);
    // 0x801954A0: addiu       $s1, $s1, -0x6EA8
    ctx->r17 = ADD32(ctx->r17, -0X6EA8);
    // 0x801954A4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x801954A8: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801954AC: addiu       $s0, $s0, -0x6E84
    ctx->r16 = ADD32(ctx->r16, -0X6E84);
    // 0x801954B0: beq         $v1, $zero, L_801954D0
    if (ctx->r3 == 0) {
        // 0x801954B4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801954D0;
    }
    // 0x801954B4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801954B8: beq         $v0, $a0, L_801955D4
    if (ctx->r2 == ctx->r4) {
        // 0x801954BC: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_801955D4;
    }
    // 0x801954BC: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801954C0: beq         $v0, $a2, L_801956DC
    if (ctx->r2 == ctx->r6) {
        // 0x801954C4: lui         $s0, 0x801C
        ctx->r16 = S32(0X801C << 16);
            goto L_801956DC;
    }
    // 0x801954C4: lui         $s0, 0x801C
    ctx->r16 = S32(0X801C << 16);
    // 0x801954C8: b           L_801957C8
    // 0x801954CC: nop

        goto L_801957C8;
    // 0x801954CC: nop

L_801954D0:
    // 0x801954D0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x801954D4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801954D8: bne         $t4, $zero, L_801957C8
    if (ctx->r12 != 0) {
        // 0x801954DC: nop
    
            goto L_801957C8;
    }
    // 0x801954DC: nop

    // 0x801954E0: lwc1        $f0, 0x73C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73C0);
    // 0x801954E4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801954E8: lwc1        $f2, 0x73C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73C4);
    // 0x801954EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801954F0: lwc1        $f10, -0x1620($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1620);
    // 0x801954F4: lwc1        $f18, -0x161C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X161C);
    // 0x801954F8: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    // 0x801954FC: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80195500: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80195504: swc1        $f16, -0x1620($at)
    MEM_W(-0X1620, ctx->r1) = ctx->f16.u32l;
    // 0x80195508: swc1        $f4, -0x161C($at)
    MEM_W(-0X161C, ctx->r1) = ctx->f4.u32l;
    // 0x8019550C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195510: lwc1        $f6, -0x1628($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1628);
    // 0x80195514: lwc1        $f10, -0x1624($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1624);
    // 0x80195518: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8019551C: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x80195520: swc1        $f8, -0x1628($at)
    MEM_W(-0X1628, ctx->r1) = ctx->f8.u32l;
    // 0x80195524: swc1        $f16, -0x1624($at)
    MEM_W(-0X1624, ctx->r1) = ctx->f16.u32l;
    // 0x80195528: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019552C: lwc1        $f18, -0x15E8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X15E8);
    // 0x80195530: lwc1        $f6, -0x15E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15E4);
    // 0x80195534: lwc1        $f10, -0x15F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X15F0);
    // 0x80195538: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8019553C: lwc1        $f18, -0x15EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X15EC);
    // 0x80195540: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80195544: swc1        $f4, -0x15E8($at)
    MEM_W(-0X15E8, ctx->r1) = ctx->f4.u32l;
    // 0x80195548: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8019554C: swc1        $f8, -0x15E4($at)
    MEM_W(-0X15E4, ctx->r1) = ctx->f8.u32l;
    // 0x80195550: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80195554: swc1        $f16, -0x15F0($at)
    MEM_W(-0X15F0, ctx->r1) = ctx->f16.u32l;
    // 0x80195558: swc1        $f4, -0x15EC($at)
    MEM_W(-0X15EC, ctx->r1) = ctx->f4.u32l;
    // 0x8019555C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195560: lwc1        $f6, -0x15B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15B0);
    // 0x80195564: lwc1        $f10, -0x15AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X15AC);
    // 0x80195568: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8019556C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80195570: swc1        $f8, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->f8.u32l;
    // 0x80195574: swc1        $f16, -0x15AC($at)
    MEM_W(-0X15AC, ctx->r1) = ctx->f16.u32l;
    // 0x80195578: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019557C: lwc1        $f18, -0x15B8($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X15B8);
    // 0x80195580: lwc1        $f6, -0x15B4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15B4);
    // 0x80195584: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80195588: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x8019558C: swc1        $f4, -0x15B8($at)
    MEM_W(-0X15B8, ctx->r1) = ctx->f4.u32l;
    // 0x80195590: swc1        $f8, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = ctx->f8.u32l;
    // 0x80195594: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195598: lwc1        $f10, -0x1578($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1578);
    // 0x8019559C: lwc1        $f18, -0x1574($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1574);
    // 0x801955A0: lwc1        $f6, -0x1580($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1580);
    // 0x801955A4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x801955A8: lwc1        $f10, -0x157C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X157C);
    // 0x801955AC: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x801955B0: swc1        $f16, -0x1578($at)
    MEM_W(-0X1578, ctx->r1) = ctx->f16.u32l;
    // 0x801955B4: sub.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x801955B8: swc1        $f4, -0x1574($at)
    MEM_W(-0X1574, ctx->r1) = ctx->f4.u32l;
    // 0x801955BC: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x801955C0: swc1        $f8, -0x1580($at)
    MEM_W(-0X1580, ctx->r1) = ctx->f8.u32l;
    // 0x801955C4: swc1        $f16, -0x157C($at)
    MEM_W(-0X157C, ctx->r1) = ctx->f16.u32l;
    // 0x801955C8: sw          $a2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r6;
    // 0x801955CC: b           L_801957C8
    // 0x801955D0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
        goto L_801957C8;
    // 0x801955D0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
L_801955D4:
    // 0x801955D4: addiu       $s0, $s0, -0x6E84
    ctx->r16 = ADD32(ctx->r16, -0X6E84);
    // 0x801955D8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x801955DC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801955E0: bne         $t6, $zero, L_801957C8
    if (ctx->r14 != 0) {
        // 0x801955E4: nop
    
            goto L_801957C8;
    }
    // 0x801955E4: nop

    // 0x801955E8: lwc1        $f0, 0x73C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X73C8);
    // 0x801955EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801955F0: lwc1        $f2, 0x73CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X73CC);
    // 0x801955F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801955F8: lwc1        $f18, -0x1620($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1620);
    // 0x801955FC: lwc1        $f6, -0x161C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X161C);
    // 0x80195600: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x80195604: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80195608: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8019560C: swc1        $f4, -0x1620($at)
    MEM_W(-0X1620, ctx->r1) = ctx->f4.u32l;
    // 0x80195610: swc1        $f8, -0x161C($at)
    MEM_W(-0X161C, ctx->r1) = ctx->f8.u32l;
    // 0x80195614: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195618: lwc1        $f10, -0x1628($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1628);
    // 0x8019561C: lwc1        $f18, -0x1624($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1624);
    // 0x80195620: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80195624: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80195628: swc1        $f16, -0x1628($at)
    MEM_W(-0X1628, ctx->r1) = ctx->f16.u32l;
    // 0x8019562C: swc1        $f4, -0x1624($at)
    MEM_W(-0X1624, ctx->r1) = ctx->f4.u32l;
    // 0x80195630: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195634: lwc1        $f6, -0x15E8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15E8);
    // 0x80195638: lwc1        $f10, -0x15E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X15E4);
    // 0x8019563C: lwc1        $f18, -0x15F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X15F0);
    // 0x80195640: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80195644: lwc1        $f6, -0x15EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15EC);
    // 0x80195648: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8019564C: swc1        $f8, -0x15E8($at)
    MEM_W(-0X15E8, ctx->r1) = ctx->f8.u32l;
    // 0x80195650: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x80195654: swc1        $f16, -0x15E4($at)
    MEM_W(-0X15E4, ctx->r1) = ctx->f16.u32l;
    // 0x80195658: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8019565C: swc1        $f4, -0x15F0($at)
    MEM_W(-0X15F0, ctx->r1) = ctx->f4.u32l;
    // 0x80195660: swc1        $f8, -0x15EC($at)
    MEM_W(-0X15EC, ctx->r1) = ctx->f8.u32l;
    // 0x80195664: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195668: lwc1        $f10, -0x15B0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X15B0);
    // 0x8019566C: lwc1        $f18, -0x15AC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X15AC);
    // 0x80195670: sub.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80195674: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80195678: swc1        $f16, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->f16.u32l;
    // 0x8019567C: swc1        $f4, -0x15AC($at)
    MEM_W(-0X15AC, ctx->r1) = ctx->f4.u32l;
    // 0x80195680: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195684: lwc1        $f6, -0x15B8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X15B8);
    // 0x80195688: lwc1        $f10, -0x15B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X15B4);
    // 0x8019568C: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80195690: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80195694: swc1        $f8, -0x15B8($at)
    MEM_W(-0X15B8, ctx->r1) = ctx->f8.u32l;
    // 0x80195698: swc1        $f16, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = ctx->f16.u32l;
    // 0x8019569C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801956A0: lwc1        $f18, -0x1578($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1578);
    // 0x801956A4: lwc1        $f6, -0x1574($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1574);
    // 0x801956A8: lwc1        $f10, -0x1580($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1580);
    // 0x801956AC: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x801956B0: lwc1        $f18, -0x157C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X157C);
    // 0x801956B4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x801956B8: swc1        $f4, -0x1578($at)
    MEM_W(-0X1578, ctx->r1) = ctx->f4.u32l;
    // 0x801956BC: add.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801956C0: swc1        $f8, -0x1574($at)
    MEM_W(-0X1574, ctx->r1) = ctx->f8.u32l;
    // 0x801956C4: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x801956C8: swc1        $f16, -0x1580($at)
    MEM_W(-0X1580, ctx->r1) = ctx->f16.u32l;
    // 0x801956CC: swc1        $f4, -0x157C($at)
    MEM_W(-0X157C, ctx->r1) = ctx->f4.u32l;
    // 0x801956D0: sw          $a2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r6;
    // 0x801956D4: b           L_801957C8
    // 0x801956D8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_801957C8;
    // 0x801956D8: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_801956DC:
    // 0x801956DC: addiu       $s0, $s0, -0x6E84
    ctx->r16 = ADD32(ctx->r16, -0X6E84);
    // 0x801956E0: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x801956E4: bne         $t8, $zero, L_801957C8
    if (ctx->r24 != 0) {
        // 0x801956E8: nop
    
            goto L_801957C8;
    }
    // 0x801956E8: nop

    // 0x801956EC: jal         0x80004EB0
    // 0x801956F0: nop

    Rand_ZeroOne(rdram, ctx);
        goto after_1;
    // 0x801956F0: nop

    after_1:
    // 0x801956F4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801956F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801956FC: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x80195700: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80195704: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80195708: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8019570C: b           L_801957C8
    // 0x80195710: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
        goto L_801957C8;
    // 0x80195710: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80195714: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80195718:
    // 0x80195718: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019571C: swc1        $f0, -0x1620($at)
    MEM_W(-0X1620, ctx->r1) = ctx->f0.u32l;
    // 0x80195720: swc1        $f0, -0x161C($at)
    MEM_W(-0X161C, ctx->r1) = ctx->f0.u32l;
    // 0x80195724: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195728: lwc1        $f16, -0x1660($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1660);
    // 0x8019572C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195730: swc1        $f16, -0x1628($at)
    MEM_W(-0X1628, ctx->r1) = ctx->f16.u32l;
    // 0x80195734: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195738: lwc1        $f18, -0x1650($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1650);
    // 0x8019573C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195740: swc1        $f18, -0x1624($at)
    MEM_W(-0X1624, ctx->r1) = ctx->f18.u32l;
    // 0x80195744: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195748: swc1        $f0, -0x15E8($at)
    MEM_W(-0X15E8, ctx->r1) = ctx->f0.u32l;
    // 0x8019574C: swc1        $f0, -0x15E4($at)
    MEM_W(-0X15E4, ctx->r1) = ctx->f0.u32l;
    // 0x80195750: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195754: lwc1        $f4, -0x165C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X165C);
    // 0x80195758: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019575C: swc1        $f4, -0x15F0($at)
    MEM_W(-0X15F0, ctx->r1) = ctx->f4.u32l;
    // 0x80195760: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195764: lwc1        $f6, -0x164C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X164C);
    // 0x80195768: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019576C: swc1        $f6, -0x15EC($at)
    MEM_W(-0X15EC, ctx->r1) = ctx->f6.u32l;
    // 0x80195770: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195774: swc1        $f0, -0x15B0($at)
    MEM_W(-0X15B0, ctx->r1) = ctx->f0.u32l;
    // 0x80195778: swc1        $f0, -0x15AC($at)
    MEM_W(-0X15AC, ctx->r1) = ctx->f0.u32l;
    // 0x8019577C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195780: lwc1        $f8, -0x1658($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1658);
    // 0x80195784: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195788: swc1        $f8, -0x15B8($at)
    MEM_W(-0X15B8, ctx->r1) = ctx->f8.u32l;
    // 0x8019578C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195790: lwc1        $f10, -0x1648($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X1648);
    // 0x80195794: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x80195798: swc1        $f10, -0x15B4($at)
    MEM_W(-0X15B4, ctx->r1) = ctx->f10.u32l;
    // 0x8019579C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801957A0: swc1        $f0, -0x1578($at)
    MEM_W(-0X1578, ctx->r1) = ctx->f0.u32l;
    // 0x801957A4: swc1        $f0, -0x1574($at)
    MEM_W(-0X1574, ctx->r1) = ctx->f0.u32l;
    // 0x801957A8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801957AC: lwc1        $f16, -0x1654($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1654);
    // 0x801957B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801957B4: swc1        $f16, -0x1580($at)
    MEM_W(-0X1580, ctx->r1) = ctx->f16.u32l;
    // 0x801957B8: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801957BC: lwc1        $f18, -0x1644($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1644);
    // 0x801957C0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801957C4: swc1        $f18, -0x157C($at)
    MEM_W(-0X157C, ctx->r1) = ctx->f18.u32l;
L_801957C8:
    // 0x801957C8: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801957CC: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801957D0: addiu       $s1, $s1, -0x15D0
    ctx->r17 = ADD32(ctx->r17, -0X15D0);
    // 0x801957D4: addiu       $s0, $s0, -0x1640
    ctx->r16 = ADD32(ctx->r16, -0X1640);
    // 0x801957D8: or          $t3, $s0, $zero
    ctx->r11 = ctx->r16 | 0;
L_801957DC:
    // 0x801957DC: or          $t4, $sp, $zero
    ctx->r12 = ctx->r29 | 0;
    // 0x801957E0: addiu       $t2, $s0, 0x30
    ctx->r10 = ADD32(ctx->r16, 0X30);
L_801957E4:
    // 0x801957E4: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x801957E8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x801957EC: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x801957F0: sw          $at, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r1;
    // 0x801957F4: lw          $at, -0x8($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X8);
    // 0x801957F8: sw          $at, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r1;
    // 0x801957FC: lw          $at, -0x4($t3)
    ctx->r1 = MEM_W(ctx->r11, -0X4);
    // 0x80195800: bne         $t3, $t2, L_801957E4
    if (ctx->r11 != ctx->r10) {
        // 0x80195804: sw          $at, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r1;
            goto L_801957E4;
    }
    // 0x80195804: sw          $at, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r1;
    // 0x80195808: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x8019580C: sw          $at, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r1;
    // 0x80195810: lw          $t2, 0x4($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X4);
    // 0x80195814: sw          $t2, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r10;
    // 0x80195818: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8019581C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80195820: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80195824: jal         0x8019C120
    // 0x80195828: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_2;
    // 0x80195828: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_2:
    // 0x8019582C: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x80195830: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80195834: bnel        $at, $zero, L_801957DC
    if (ctx->r1 != 0) {
        // 0x80195838: or          $t3, $s0, $zero
        ctx->r11 = ctx->r16 | 0;
            goto L_801957DC;
    }
    goto skip_1;
    // 0x80195838: or          $t3, $s0, $zero
    ctx->r11 = ctx->r16 | 0;
    skip_1:
    // 0x8019583C: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80195840: addiu       $s0, $s0, -0x1640
    ctx->r16 = ADD32(ctx->r16, -0X1640);
    // 0x80195844: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80195848:
    // 0x80195848: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8019584C: lw          $t5, -0x6EB4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X6EB4);
    // 0x80195850: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80195854: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x80195858: beq         $t5, $at, L_801958B8
    if (ctx->r13 == ctx->r1) {
        // 0x8019585C: subu        $t6, $t6, $s1
        ctx->r14 = SUB32(ctx->r14, ctx->r17);
            goto L_801958B8;
    }
    // 0x8019585C: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x80195860: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80195864: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80195868: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x8019586C: or          $t0, $sp, $zero
    ctx->r8 = ctx->r29 | 0;
L_80195870:
    // 0x80195870: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80195874: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80195878: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8019587C: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x80195880: lw          $at, -0x8($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X8);
    // 0x80195884: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x80195888: lw          $at, -0x4($t7)
    ctx->r1 = MEM_W(ctx->r15, -0X4);
    // 0x8019588C: bne         $t7, $t9, L_80195870
    if (ctx->r15 != ctx->r25) {
        // 0x80195890: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_80195870;
    }
    // 0x80195890: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x80195894: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x80195898: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x8019589C: lw          $t9, 0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X4);
    // 0x801958A0: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x801958A4: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x801958A8: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x801958AC: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x801958B0: jal         0x8019C120
    // 0x801958B4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_3;
    // 0x801958B4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_3:
L_801958B8:
    // 0x801958B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801958BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801958C0: bne         $s1, $at, L_80195848
    if (ctx->r17 != ctx->r1) {
        // 0x801958C4: nop
    
            goto L_80195848;
    }
    // 0x801958C4: nop

    // 0x801958C8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801958CC: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x801958D0: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x801958D4: jr          $ra
    // 0x801958D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x801958D8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void Option_ExpertSound_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80195944: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80195948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8019594C: lui         $t6, 0x801C
    ctx->r14 = S32(0X801C << 16);
    // 0x80195950: lw          $t6, -0x6CE4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6CE4);
    // 0x80195954: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x80195958: addiu       $a3, $a3, -0x6D70
    ctx->r7 = ADD32(ctx->r7, -0X6D70);
    // 0x8019595C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80195960: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80195964: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x80195968: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8019596C: lui         $a2, 0x4244
    ctx->r6 = S32(0X4244 << 16);
    // 0x80195970: jal         0x8019C66C
    // 0x80195974: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    Option_Input_Sound_X(rdram, ctx);
        goto after_0;
    // 0x80195974: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x80195978: beq         $v0, $zero, L_801959C4
    if (ctx->r2 == 0) {
        // 0x8019597C: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801959C4;
    }
    // 0x8019597C: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80195980: lui         $t7, 0x800C
    ctx->r15 = S32(0X800C << 16);
    // 0x80195984: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80195988: addiu       $t7, $t7, 0x5D3C
    ctx->r15 = ADD32(ctx->r15, 0X5D3C);
    // 0x8019598C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80195990: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80195994: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80195998: ori         $a0, $a0, 0x2
    ctx->r4 = ctx->r4 | 0X2;
    // 0x8019599C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801959A0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801959A4: jal         0x80019218
    // 0x801959A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x801959A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x801959AC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801959B0: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x801959B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801959B8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801959BC: nop

    // 0x801959C0: sw          $t9, -0x6CE4($at)
    MEM_W(-0X6CE4, ctx->r1) = ctx->r25;
L_801959C4:
    // 0x801959C4: lui         $t0, 0x8017
    ctx->r8 = S32(0X8017 << 16);
    // 0x801959C8: lw          $t0, 0x7AF8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X7AF8);
    // 0x801959CC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801959D0: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801959D4: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801959D8: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x801959DC: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x801959E0: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x801959E4: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x801959E8: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801959EC: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x801959F0: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x801959F4: beql        $t2, $zero, L_80195A3C
    if (ctx->r10 == 0) {
        // 0x801959F8: andi        $t6, $v0, 0x4000
        ctx->r14 = ctx->r2 & 0X4000;
            goto L_80195A3C;
    }
    goto skip_0;
    // 0x801959F8: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
    skip_0:
    // 0x801959FC: jal         0x8001DA90
    // 0x80195A00: lbu         $a0, -0x6CE1($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6CE1);
    Audio_PlaySoundTestTrack(rdram, ctx);
        goto after_2;
    // 0x80195A00: lbu         $a0, -0x6CE1($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X6CE1);
    after_2:
    // 0x80195A04: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80195A08: lw          $t4, 0x7AF8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7AF8);
    // 0x80195A0C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80195A10: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80195A14: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80195A18: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80195A1C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80195A20: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80195A24: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80195A28: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80195A2C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80195A30: sw          $t3, -0x6CE0($at)
    MEM_W(-0X6CE0, ctx->r1) = ctx->r11;
    // 0x80195A34: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x80195A38: andi        $t6, $v0, 0x4000
    ctx->r14 = ctx->r2 & 0X4000;
L_80195A3C:
    // 0x80195A3C: beq         $t6, $zero, L_80195B3C
    if (ctx->r14 == 0) {
        // 0x80195A40: lui         $t7, 0x801C
        ctx->r15 = S32(0X801C << 16);
            goto L_80195B3C;
    }
    // 0x80195A40: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x80195A44: lw          $t7, -0x6CE0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6CE0);
    // 0x80195A48: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80195A4C: ori         $a0, $a0, 0x101D
    ctx->r4 = ctx->r4 | 0X101D;
    // 0x80195A50: bne         $t7, $zero, L_80195AE0
    if (ctx->r15 != 0) {
        // 0x80195A54: lui         $a1, 0x800C
        ctx->r5 = S32(0X800C << 16);
            goto L_80195AE0;
    }
    // 0x80195A54: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80195A58: lui         $t8, 0x800C
    ctx->r24 = S32(0X800C << 16);
    // 0x80195A5C: addiu       $t8, $t8, 0x5D3C
    ctx->r24 = ADD32(ctx->r24, 0X5D3C);
    // 0x80195A60: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80195A64: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80195A68: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80195A6C: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x80195A70: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x80195A74: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80195A78: jal         0x80019218
    // 0x80195A7C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_3;
    // 0x80195A7C: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_3:
    // 0x80195A80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80195A84: addiu       $a1, $zero, 0x24
    ctx->r5 = ADD32(0, 0X24);
    // 0x80195A88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80195A8C: jal         0x8001D444
    // 0x80195A90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    Audio_PlaySequence(rdram, ctx);
        goto after_4;
    // 0x80195A90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_4:
    // 0x80195A94: lui         $t1, 0x8017
    ctx->r9 = S32(0X8017 << 16);
    // 0x80195A98: lw          $t1, 0x7AF8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7AF8);
    // 0x80195A9C: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80195AA0: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80195AA4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80195AA8: addiu       $t9, $zero, 0x3E8
    ctx->r25 = ADD32(0, 0X3E8);
    // 0x80195AAC: sw          $t9, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r25;
    // 0x80195AB0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80195AB4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80195AB8: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80195ABC: sw          $zero, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = 0;
    // 0x80195AC0: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x80195AC4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80195AC8: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80195ACC: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80195AD0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80195AD4: sw          $t0, -0x6DBC($at)
    MEM_W(-0X6DBC, ctx->r1) = ctx->r8;
    // 0x80195AD8: b           L_80195B3C
    // 0x80195ADC: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
        goto L_80195B3C;
    // 0x80195ADC: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
L_80195AE0:
    // 0x80195AE0: lui         $t3, 0x800C
    ctx->r11 = S32(0X800C << 16);
    // 0x80195AE4: addiu       $t3, $t3, 0x5D3C
    ctx->r11 = ADD32(ctx->r11, 0X5D3C);
    // 0x80195AE8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80195AEC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80195AF0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80195AF4: jal         0x80019218
    // 0x80195AF8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_5;
    // 0x80195AF8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_5:
    // 0x80195AFC: lui         $a0, 0x1001
    ctx->r4 = S32(0X1001 << 16);
    // 0x80195B00: jal         0x800182F4
    // 0x80195B04: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_6;
    // 0x80195B04: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_6:
    // 0x80195B08: lui         $a0, 0x1101
    ctx->r4 = S32(0X1101 << 16);
    // 0x80195B0C: jal         0x800182F4
    // 0x80195B10: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    Audio_QueueSeqCmd(rdram, ctx);
        goto after_7;
    // 0x80195B10: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_7:
    // 0x80195B14: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x80195B18: lw          $t4, 0x7AF8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7AF8);
    // 0x80195B1C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80195B20: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80195B24: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80195B28: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80195B2C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x80195B30: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80195B34: lhu         $v0, -0x2768($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2768);
    // 0x80195B38: sw          $zero, -0x6CE0($at)
    MEM_W(-0X6CE0, ctx->r1) = 0;
L_80195B3C:
    // 0x80195B3C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80195B40: beq         $t6, $zero, L_80195B64
    if (ctx->r14 == 0) {
        // 0x80195B44: lui         $v0, 0x801C
        ctx->r2 = S32(0X801C << 16);
            goto L_80195B64;
    }
    // 0x80195B44: lui         $v0, 0x801C
    ctx->r2 = S32(0X801C << 16);
    // 0x80195B48: addiu       $v0, $v0, -0x6CE8
    ctx->r2 = ADD32(ctx->r2, -0X6CE8);
    // 0x80195B4C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80195B50: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80195B54: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80195B58: bne         $at, $zero, L_80195B64
    if (ctx->r1 != 0) {
        // 0x80195B5C: sw          $t8, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r24;
            goto L_80195B64;
    }
    // 0x80195B5C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80195B60: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80195B64:
    // 0x80195B64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80195B68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80195B6C: jr          $ra
    // 0x80195B70: nop

    return;
    // 0x80195B70: nop

;}
RECOMP_FUNC void Option_Ranking_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80196EFC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80196F00: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80196F04: jal         0x80196FC4
    // 0x80196F08: nop

    Option_Ranking_Select(rdram, ctx);
        goto after_0;
    // 0x80196F08: nop

    after_0:
    // 0x80196F0C: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x80196F10: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x80196F14: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80196F18: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x80196F1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80196F20: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x80196F24: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80196F28: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80196F2C: lhu         $t8, -0x2768($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X2768);
    // 0x80196F30: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x80196F34: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x80196F38: andi        $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 & 0X4000;
    // 0x80196F3C: beq         $t9, $zero, L_80196F8C
    if (ctx->r25 == 0) {
        // 0x80196F40: ori         $a0, $a0, 0x21
        ctx->r4 = ctx->r4 | 0X21;
            goto L_80196F8C;
    }
    // 0x80196F40: ori         $a0, $a0, 0x21
    ctx->r4 = ctx->r4 | 0X21;
    // 0x80196F44: lui         $t0, 0x800C
    ctx->r8 = S32(0X800C << 16);
    // 0x80196F48: addiu       $t0, $t0, 0x5D3C
    ctx->r8 = ADD32(ctx->r8, 0X5D3C);
    // 0x80196F4C: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x80196F50: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x80196F54: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80196F58: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80196F5C: jal         0x80019218
    // 0x80196F60: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_1;
    // 0x80196F60: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_1:
    // 0x80196F64: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x80196F68: sw          $zero, 0x7898($at)
    MEM_W(0X7898, ctx->r1) = 0;
    // 0x80196F6C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196F70: addiu       $t1, $zero, 0x3E8
    ctx->r9 = ADD32(0, 0X3E8);
    // 0x80196F74: sw          $t1, -0x6EDC($at)
    MEM_W(-0X6EDC, ctx->r1) = ctx->r9;
    // 0x80196F78: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196F7C: sw          $zero, -0x6ED4($at)
    MEM_W(-0X6ED4, ctx->r1) = 0;
    // 0x80196F80: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x80196F84: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80196F88: sw          $t2, -0x6DBC($at)
    MEM_W(-0X6DBC, ctx->r1) = ctx->r10;
L_80196F8C:
    // 0x80196F8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80196F90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80196F94: jr          $ra
    // 0x80196F98: nop

    return;
    // 0x80196F98: nop

;}
RECOMP_FUNC void Map_PathLineBox_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AA1CC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x801AA1D0: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x801AA1D4: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x801AA1D8: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x801AA1DC: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x801AA1E0: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x801AA1E4: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x801AA1E8: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x801AA1EC: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x801AA1F0: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x801AA1F4: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x801AA1F8: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x801AA1FC: sdc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X50, ctx->r29);
    // 0x801AA200: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x801AA204: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x801AA208: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x801AA20C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801AA210: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801AA214: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801AA218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AA21C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801AA220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801AA224: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x801AA228: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801AA22C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801AA230: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801AA234: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801AA238: lui         $s5, 0x8017
    ctx->r21 = S32(0X8017 << 16);
    // 0x801AA23C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AA240: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801AA244: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801AA248: addiu       $s5, $s5, 0x7B90
    ctx->r21 = ADD32(ctx->r21, 0X7B90);
    // 0x801AA24C: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AA250: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x801AA254: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
    // 0x801AA258: lui         $s6, 0xFA00
    ctx->r22 = S32(0XFA00 << 16);
    // 0x801AA25C: add.s       $f28, $f4, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f4.fl + ctx->f6.fl;
L_801AA260:
    // 0x801AA260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AA264: jal         0x800B8DD0
    // 0x801AA268: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801AA268: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_0:
    // 0x801AA26C: slti        $at, $s3, 0x6
    ctx->r1 = SIGNED(ctx->r19) < 0X6 ? 1 : 0;
    // 0x801AA270: beq         $at, $zero, L_801AA390
    if (ctx->r1 == 0) {
        // 0x801AA274: addiu       $s2, $zero, 0xFF
        ctx->r18 = ADD32(0, 0XFF);
            goto L_801AA390;
    }
    // 0x801AA274: addiu       $s2, $zero, 0xFF
    ctx->r18 = ADD32(0, 0XFF);
    // 0x801AA278: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x801AA27C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AA280: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x801AA284: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AA288: slt         $at, $s3, $fp
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r30) ? 1 : 0;
    // 0x801AA28C: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x801AA290: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
    // 0x801AA294: beq         $at, $zero, L_801AA33C
    if (ctx->r1 == 0) {
        // 0x801AA298: add.s       $f22, $f8, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
            goto L_801AA33C;
    }
    // 0x801AA298: add.s       $f22, $f8, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801AA29C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x801AA2A0: jal         0x801A655C
    // 0x801AA2A4: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    Map_GetPathId(rdram, ctx);
        goto after_1;
    // 0x801AA2A4: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    after_1:
    // 0x801AA2A8: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x801AA2AC: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x801AA2B0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801AA2B4: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801AA2B8: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x801AA2BC: lw          $t7, -0x2E8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2E8);
    // 0x801AA2C0: sltiu       $at, $t7, 0x5
    ctx->r1 = ctx->r15 < 0X5 ? 1 : 0;
    // 0x801AA2C4: beq         $at, $zero, L_801AA300
    if (ctx->r1 == 0) {
        // 0x801AA2C8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_801AA300;
    }
    // 0x801AA2C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801AA2CC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AA2D0: addu        $at, $at, $t7
    gpr jr_addend_801AA2D8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801AA2D4: lw          $t7, 0x7A3C($at)
    ctx->r15 = ADD32(ctx->r1, 0X7A3C);
    // 0x801AA2D8: jr          $t7
    // 0x801AA2DC: nop

    switch (jr_addend_801AA2D8 >> 2) {
        case 0: goto L_801AA2E0; break;
        case 1: goto L_801AA2EC; break;
        case 2: goto L_801AA2F8; break;
        case 3: goto L_801AA2EC; break;
        case 4: goto L_801AA2F8; break;
        default: switch_error(__func__, 0x801AA2D8, 0x801B7A3C);
    }
    // 0x801AA2DC: nop

L_801AA2E0:
    // 0x801AA2E0: addiu       $s4, $zero, 0x10
    ctx->r20 = ADD32(0, 0X10);
    // 0x801AA2E4: b           L_801AA300
    // 0x801AA2E8: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
        goto L_801AA300;
    // 0x801AA2E8: addiu       $s1, $zero, 0x40
    ctx->r17 = ADD32(0, 0X40);
L_801AA2EC:
    // 0x801AA2EC: addiu       $s1, $zero, 0xAF
    ctx->r17 = ADD32(0, 0XAF);
    // 0x801AA2F0: b           L_801AA300
    // 0x801AA2F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_801AA300;
    // 0x801AA2F4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_801AA2F8:
    // 0x801AA2F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x801AA2FC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801AA300:
    // 0x801AA300: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA304: andi        $t1, $s1, 0xFF
    ctx->r9 = ctx->r17 & 0XFF;
    // 0x801AA308: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x801AA30C: sll         $t0, $s4, 24
    ctx->r8 = S32(ctx->r20 << 24);
    // 0x801AA310: andi        $t4, $s2, 0xFF
    ctx->r12 = ctx->r18 & 0XFF;
    // 0x801AA314: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x801AA318: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x801AA31C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AA320: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801AA324: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x801AA328: ori         $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 | 0XFF;
    // 0x801AA32C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AA330: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x801AA334: b           L_801AA354
    // 0x801AA338: add.s       $f16, $f24, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f24.fl + ctx->f20.fl;
        goto L_801AA354;
    // 0x801AA338: add.s       $f16, $f24, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f24.fl + ctx->f20.fl;
L_801AA33C:
    // 0x801AA33C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA340: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801AA344: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801AA348: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x801AA34C: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x801AA350: add.s       $f16, $f24, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f24.fl + ctx->f20.fl;
L_801AA354:
    // 0x801AA354: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801AA358: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AA35C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AA360: add.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x801AA364: lwc1        $f6, 0x7A50($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7A50);
    // 0x801AA368: lui         $a1, 0x604
    ctx->r5 = S32(0X604 << 16);
    // 0x801AA36C: addiu       $a1, $a1, 0x47A0
    ctx->r5 = ADD32(ctx->r5, 0X47A0);
    // 0x801AA370: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x801AA374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AA378: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801AA37C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x801AA380: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x801AA384: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x801AA388: jal         0x8009D418
    // 0x801AA38C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_2;
    // 0x801AA38C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_2:
L_801AA390:
    // 0x801AA390: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AA394: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AA398: lui         $a1, 0x604
    ctx->r5 = S32(0X604 << 16);
    // 0x801AA39C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801AA3A0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801AA3A4: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x801AA3A8: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x801AA3AC: add.s       $f8, $f24, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f24.fl + ctx->f20.fl;
    // 0x801AA3B0: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x801AA3B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AA3B8: addiu       $a1, $a1, 0x7550
    ctx->r5 = ADD32(ctx->r5, 0X7550);
    // 0x801AA3BC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801AA3C0: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x801AA3C4: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x801AA3C8: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x801AA3CC: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x801AA3D0: jal         0x8009D418
    // 0x801AA3D4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_RGBA16(rdram, ctx);
        goto after_3;
    // 0x801AA3D4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x801AA3D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801AA3DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801AA3E0: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x801AA3E4: bne         $s3, $at, L_801AA260
    if (ctx->r19 != ctx->r1) {
        // 0x801AA3E8: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_801AA260;
    }
    // 0x801AA3E8: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x801AA3EC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x801AA3F0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801AA3F4: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801AA3F8: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x801AA3FC: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x801AA400: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x801AA404: ldc1        $f30, 0x50($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X50);
    // 0x801AA408: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x801AA40C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x801AA410: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x801AA414: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x801AA418: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x801AA41C: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x801AA420: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x801AA424: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x801AA428: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x801AA42C: jr          $ra
    // 0x801AA430: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x801AA430: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void Option_Versus_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801944F0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801944F4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801944F8: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801944FC: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80194500: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80194504: jal         0x8019B9C0
    // 0x80194508: nop

    Option_DrawMenuLabel(rdram, ctx);
        goto after_0;
    // 0x80194508: nop

    after_0:
    // 0x8019450C: jal         0x8019BDF0
    // 0x80194510: nop

    Option_Menu_Push(rdram, ctx);
        goto after_1;
    // 0x80194510: nop

    after_1:
    // 0x80194514: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x80194518: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x8019451C: addiu       $s1, $s1, -0x1668
    ctx->r17 = ADD32(ctx->r17, -0X1668);
    // 0x80194520: addiu       $s0, $s0, -0x1788
    ctx->r16 = ADD32(ctx->r16, -0X1788);
    // 0x80194524: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
L_80194528:
    // 0x80194528: beql        $t6, $zero, L_8019456C
    if (ctx->r14 == 0) {
        // 0x8019452C: addiu       $s0, $s0, 0x60
        ctx->r16 = ADD32(ctx->r16, 0X60);
            goto L_8019456C;
    }
    goto skip_0;
    // 0x8019452C: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    skip_0:
    // 0x80194530: lw          $at, 0x38($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X38);
    // 0x80194534: lw          $t8, 0x3C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X3C);
    // 0x80194538: lw          $a3, 0x44($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X44);
    // 0x8019453C: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x80194540: lw          $at, 0x40($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X40);
    // 0x80194544: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x80194548: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8019454C: sw          $at, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r1;
    // 0x80194550: lw          $at, 0x48($s0)
    ctx->r1 = MEM_W(ctx->r16, 0X48);
    // 0x80194554: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80194558: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8019455C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80194560: jal         0x8019BAB8
    // 0x80194564: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    Option_DrawMenuCard(rdram, ctx);
        goto after_2;
    // 0x80194564: sw          $at, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r1;
    after_2:
    // 0x80194568: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
L_8019456C:
    // 0x8019456C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80194570: bnel        $at, $zero, L_80194528
    if (ctx->r1 != 0) {
        // 0x80194574: lw          $t6, 0x5C($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X5C);
            goto L_80194528;
    }
    goto skip_1;
    // 0x80194574: lw          $t6, 0x5C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X5C);
    skip_1:
    // 0x80194578: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8019457C: lw          $t9, -0x6E58($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6E58);
    // 0x80194580: lui         $t2, 0x801B
    ctx->r10 = S32(0X801B << 16);
    // 0x80194584: addiu       $t2, $t2, -0x1788
    ctx->r10 = ADD32(ctx->r10, -0X1788);
    // 0x80194588: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8019458C: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x80194590: sll         $t0, $t0, 5
    ctx->r8 = S32(ctx->r8 << 5);
    // 0x80194594: addiu       $t1, $t0, 0x4C
    ctx->r9 = ADD32(ctx->r8, 0X4C);
    // 0x80194598: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8019459C: lw          $at, 0x0($t3)
    ctx->r1 = MEM_W(ctx->r11, 0X0);
    // 0x801945A0: sw          $at, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r1;
    // 0x801945A4: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    // 0x801945A8: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801945AC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801945B0: lw          $a2, 0x8($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X8);
    // 0x801945B4: jal         0x8019BBA4
    // 0x801945B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    Option_DrawMenuArwing(rdram, ctx);
        goto after_3;
    // 0x801945B8: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_3:
    // 0x801945BC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801945C0: jal         0x80005740
    // 0x801945C4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_4;
    // 0x801945C4: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_4:
    // 0x801945C8: lui         $s0, 0x801B
    ctx->r16 = S32(0X801B << 16);
    // 0x801945CC: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801945D0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801945D4: addiu       $s1, $s1, -0x1668
    ctx->r17 = ADD32(ctx->r17, -0X1668);
    // 0x801945D8: addiu       $s0, $s0, -0x1788
    ctx->r16 = ADD32(ctx->r16, -0X1788);
    // 0x801945DC: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
L_801945E0:
    // 0x801945E0: beql        $t6, $zero, L_80194650
    if (ctx->r14 == 0) {
        // 0x801945E4: addiu       $s0, $s0, 0x60
        ctx->r16 = ADD32(ctx->r16, 0X60);
            goto L_80194650;
    }
    goto skip_2;
    // 0x801945E4: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    skip_2:
    // 0x801945E8: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x801945EC: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
    // 0x801945F0: or          $t0, $sp, $zero
    ctx->r8 = ctx->r29 | 0;
    // 0x801945F4: c.le.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl <= ctx->f20.fl;
    // 0x801945F8: addiu       $t8, $s0, 0x30
    ctx->r24 = ADD32(ctx->r16, 0X30);
    // 0x801945FC: bc1tl       L_80194650
    if (c1cs) {
        // 0x80194600: addiu       $s0, $s0, 0x60
        ctx->r16 = ADD32(ctx->r16, 0X60);
            goto L_80194650;
    }
    goto skip_3;
    // 0x80194600: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
    skip_3:
L_80194604:
    // 0x80194604: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x80194608: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8019460C: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80194610: sw          $at, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r1;
    // 0x80194614: lw          $at, -0x8($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X8);
    // 0x80194618: sw          $at, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r1;
    // 0x8019461C: lw          $at, -0x4($t9)
    ctx->r1 = MEM_W(ctx->r25, -0X4);
    // 0x80194620: bne         $t9, $t8, L_80194604
    if (ctx->r25 != ctx->r24) {
        // 0x80194624: sw          $at, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r1;
            goto L_80194604;
    }
    // 0x80194624: sw          $at, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r1;
    // 0x80194628: lw          $at, 0x0($t9)
    ctx->r1 = MEM_W(ctx->r25, 0X0);
    // 0x8019462C: sw          $at, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r1;
    // 0x80194630: lw          $t8, 0x4($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X4);
    // 0x80194634: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80194638: lw          $a3, 0xC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC);
    // 0x8019463C: lw          $a2, 0x8($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8);
    // 0x80194640: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x80194644: jal         0x8019C120
    // 0x80194648: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    Option_DrawCardLabel(rdram, ctx);
        goto after_5;
    // 0x80194648: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_5:
    // 0x8019464C: addiu       $s0, $s0, 0x60
    ctx->r16 = ADD32(ctx->r16, 0X60);
L_80194650:
    // 0x80194650: bnel        $s0, $s1, L_801945E0
    if (ctx->r16 != ctx->r17) {
        // 0x80194654: lw          $t6, 0x58($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X58);
            goto L_801945E0;
    }
    goto skip_4;
    // 0x80194654: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
    skip_4:
    // 0x80194658: jal         0x8019BF34
    // 0x8019465C: nop

    Option_CardLightning_Update(rdram, ctx);
        goto after_6;
    // 0x8019465C: nop

    after_6:
    // 0x80194660: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80194664: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80194668: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8019466C: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x80194670: jr          $ra
    // 0x80194674: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80194674: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Map_Idle_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AD11C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801AD120: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801AD124: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801AD128: lw          $t6, 0x7AF8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7AF8);
    // 0x801AD12C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x801AD130: addiu       $t8, $t8, -0x2768
    ctx->r24 = ADD32(ctx->r24, -0X2768);
    // 0x801AD134: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801AD138: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x801AD13C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x801AD140: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801AD144: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x801AD148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801AD14C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801AD150: andi        $t9, $v1, 0x8000
    ctx->r25 = ctx->r3 & 0X8000;
    // 0x801AD154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801AD158: beq         $t9, $zero, L_801AD238
    if (ctx->r25 == 0) {
        // 0x801AD15C: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_801AD238;
    }
    // 0x801AD15C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x801AD160: lui         $t2, 0x8016
    ctx->r10 = S32(0X8016 << 16);
    // 0x801AD164: lhu         $t2, 0x1A34($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1A34);
    // 0x801AD168: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801AD16C: lui         $t3, 0x801D
    ctx->r11 = S32(0X801D << 16);
    // 0x801AD170: bne         $t2, $at, L_801AD1D0
    if (ctx->r10 != ctx->r1) {
        // 0x801AD174: lui         $t6, 0x8017
        ctx->r14 = S32(0X8017 << 16);
            goto L_801AD1D0;
    }
    // 0x801AD174: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x801AD178: lw          $t3, -0x26C4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X26C4);
    // 0x801AD17C: lui         $t4, 0x801D
    ctx->r12 = S32(0X801D << 16);
    // 0x801AD180: beq         $t3, $zero, L_801AD1D0
    if (ctx->r11 == 0) {
        // 0x801AD184: nop
    
            goto L_801AD1D0;
    }
    // 0x801AD184: nop

    // 0x801AD188: lw          $t4, -0x1030($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1030);
    // 0x801AD18C: bne         $t4, $zero, L_801AD1D0
    if (ctx->r12 != 0) {
        // 0x801AD190: nop
    
            goto L_801AD1D0;
    }
    // 0x801AD190: nop

    // 0x801AD194: jal         0x8001D6DC
    // 0x801AD198: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Audio_PlayMapMenuSfx(rdram, ctx);
        goto after_0;
    // 0x801AD198: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x801AD19C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AD1A0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD1A4: sw          $t1, -0x103C($at)
    MEM_W(-0X103C, ctx->r1) = ctx->r9;
    // 0x801AD1A8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD1AC: sw          $zero, -0x102C($at)
    MEM_W(-0X102C, ctx->r1) = 0;
    // 0x801AD1B0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD1B4: sw          $zero, -0x1024($at)
    MEM_W(-0X1024, ctx->r1) = 0;
    // 0x801AD1B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD1BC: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x801AD1C0: sw          $t5, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r13;
    // 0x801AD1C4: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD1C8: b           L_801AD700
    // 0x801AD1CC: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
        goto L_801AD700;
    // 0x801AD1CC: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
L_801AD1D0:
    // 0x801AD1D0: lw          $t6, 0x78B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X78B0);
    // 0x801AD1D4: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x801AD1D8: lw          $t7, 0x78B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X78B4);
    // 0x801AD1DC: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AD1E0: sw          $t6, 0x7C58($at)
    MEM_W(0X7C58, ctx->r1) = ctx->r14;
    // 0x801AD1E4: lui         $at, 0x8017
    ctx->r1 = S32(0X8017 << 16);
    // 0x801AD1E8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801AD1EC: lui         $t9, 0x8017
    ctx->r25 = S32(0X8017 << 16);
    // 0x801AD1F0: addiu       $t9, $t9, 0x78B0
    ctx->r25 = ADD32(ctx->r25, 0X78B0);
    // 0x801AD1F4: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x801AD1F8: sw          $t7, 0x7C5C($at)
    MEM_W(0X7C5C, ctx->r1) = ctx->r15;
    // 0x801AD1FC: addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // 0x801AD200: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x801AD204: addiu       $t8, $t8, 0x7C58
    ctx->r24 = ADD32(ctx->r24, 0X7C58);
    // 0x801AD208: addu        $v0, $a0, $t8
    ctx->r2 = ADD32(ctx->r4, ctx->r24);
    // 0x801AD20C: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x801AD210: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x801AD214: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x801AD218: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x801AD21C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801AD220: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
    // 0x801AD224: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x801AD228: jal         0x801A659C
    // 0x801AD22C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    Map_SetState_ZoomPlanet(rdram, ctx);
        goto after_1;
    // 0x801AD22C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_1:
    // 0x801AD230: b           L_801AD704
    // 0x801AD234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801AD704;
    // 0x801AD234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801AD238:
    // 0x801AD238: andi        $t6, $v1, 0x1000
    ctx->r14 = ctx->r3 & 0X1000;
    // 0x801AD23C: beq         $t6, $zero, L_801AD2E8
    if (ctx->r14 == 0) {
        // 0x801AD240: lui         $t7, 0x801D
        ctx->r15 = S32(0X801D << 16);
            goto L_801AD2E8;
    }
    // 0x801AD240: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801AD244: lw          $t7, -0x26BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26BC);
    // 0x801AD248: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801AD24C: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x801AD250: bnel        $t7, $at, L_801AD2EC
    if (ctx->r15 != ctx->r1) {
        // 0x801AD254: lb          $t5, 0x3($v0)
        ctx->r13 = MEM_B(ctx->r2, 0X3);
            goto L_801AD2EC;
    }
    goto skip_0;
    // 0x801AD254: lb          $t5, 0x3($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X3);
    skip_0:
    // 0x801AD258: lhu         $t8, 0x1A34($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1A34);
    // 0x801AD25C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801AD260: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801AD264: bnel        $t8, $at, L_801AD2EC
    if (ctx->r24 != ctx->r1) {
        // 0x801AD268: lb          $t5, 0x3($v0)
        ctx->r13 = MEM_B(ctx->r2, 0X3);
            goto L_801AD2EC;
    }
    goto skip_1;
    // 0x801AD268: lb          $t5, 0x3($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X3);
    skip_1:
    // 0x801AD26C: lw          $t9, -0x1030($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1030);
    // 0x801AD270: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AD274: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AD278: beq         $t9, $zero, L_801AD2AC
    if (ctx->r25 == 0) {
        // 0x801AD27C: lui         $a0, 0x4900
        ctx->r4 = S32(0X4900 << 16);
            goto L_801AD2AC;
    }
    // 0x801AD27C: lui         $a0, 0x4900
    ctx->r4 = S32(0X4900 << 16);
    // 0x801AD280: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801AD284: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801AD288: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801AD28C: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801AD290: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801AD294: ori         $a0, $a0, 0x100A
    ctx->r4 = ctx->r4 | 0X100A;
    // 0x801AD298: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801AD29C: jal         0x80019218
    // 0x801AD2A0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    Audio_PlaySfx(rdram, ctx);
        goto after_2;
    // 0x801AD2A0: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x801AD2A4: b           L_801AD704
    // 0x801AD2A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801AD704;
    // 0x801AD2A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801AD2AC:
    // 0x801AD2AC: jal         0x8001D6DC
    // 0x801AD2B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    Audio_PlayMapMenuSfx(rdram, ctx);
        goto after_3;
    // 0x801AD2B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x801AD2B4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AD2B8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD2BC: sw          $t1, -0x103C($at)
    MEM_W(-0X103C, ctx->r1) = ctx->r9;
    // 0x801AD2C0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD2C4: sw          $zero, -0x102C($at)
    MEM_W(-0X102C, ctx->r1) = 0;
    // 0x801AD2C8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD2CC: sw          $zero, -0x1024($at)
    MEM_W(-0X1024, ctx->r1) = 0;
    // 0x801AD2D0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD2D4: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x801AD2D8: sw          $t3, -0x26BC($at)
    MEM_W(-0X26BC, ctx->r1) = ctx->r11;
    // 0x801AD2DC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD2E0: b           L_801AD700
    // 0x801AD2E4: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
        goto L_801AD700;
    // 0x801AD2E4: sw          $zero, -0x26B4($at)
    MEM_W(-0X26B4, ctx->r1) = 0;
L_801AD2E8:
    // 0x801AD2E8: lb          $t5, 0x3($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X3);
L_801AD2EC:
    // 0x801AD2EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801AD2F0: lb          $t4, 0x2($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X2);
    // 0x801AD2F4: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x801AD2F8: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x801AD2FC: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801AD300: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801AD304: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x801AD308: nop

    // 0x801AD30C: bc1t        L_801AD3A0
    if (c1cs) {
        // 0x801AD310: lui         $at, 0xC2A0
        ctx->r1 = S32(0XC2A0 << 16);
            goto L_801AD3A0;
    }
    // 0x801AD310: lui         $at, 0xC2A0
    ctx->r1 = S32(0XC2A0 << 16);
    // 0x801AD314: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801AD318: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AD31C: lwc1        $f8, 0x7B78($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B78);
    // 0x801AD320: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AD324: addiu       $v0, $v0, -0x25F4
    ctx->r2 = ADD32(ctx->r2, -0X25F4);
    // 0x801AD328: mul.s       $f12, $f14, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x801AD32C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801AD330: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x801AD334: sub.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x801AD338: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801AD33C: nop

    // 0x801AD340: bc1fl       L_801AD358
    if (!c1cs) {
        // 0x801AD344: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_801AD358;
    }
    goto skip_2;
    // 0x801AD344: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x801AD348: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801AD34C: b           L_801AD3A0
    // 0x801AD350: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_801AD3A0;
    // 0x801AD350: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x801AD354: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_801AD358:
    // 0x801AD358: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AD35C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801AD360: nop

    // 0x801AD364: bc1fl       L_801AD37C
    if (!c1cs) {
        // 0x801AD368: swc1        $f2, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
            goto L_801AD37C;
    }
    goto skip_3;
    // 0x801AD368: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    skip_3:
    // 0x801AD36C: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x801AD370: b           L_801AD3A0
    // 0x801AD374: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_801AD3A0;
    // 0x801AD374: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
    // 0x801AD378: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
L_801AD37C:
    // 0x801AD37C: lwc1        $f4, 0x7B7C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7B7C);
    // 0x801AD380: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801AD384: div.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x801AD388: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801AD38C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801AD390: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801AD394: nop

    // 0x801AD398: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x801AD39C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_801AD3A0:
    // 0x801AD3A0: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x801AD3A4: nop

    // 0x801AD3A8: bc1t        L_801AD3F4
    if (c1cs) {
        // 0x801AD3AC: lui         $at, 0x801B
        ctx->r1 = S32(0X801B << 16);
            goto L_801AD3F4;
    }
    // 0x801AD3AC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AD3B0: lwc1        $f8, 0x7B80($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7B80);
    // 0x801AD3B4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AD3B8: addiu       $v0, $v0, -0x25F0
    ctx->r2 = ADD32(ctx->r2, -0X25F0);
    // 0x801AD3BC: mul.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x801AD3C0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801AD3C4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AD3C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801AD3CC: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801AD3D0: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x801AD3D4: lwc1        $f6, 0x7B84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7B84);
    // 0x801AD3D8: div.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x801AD3DC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x801AD3E0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801AD3E4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801AD3E8: nop

    // 0x801AD3EC: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x801AD3F0: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_801AD3F4:
    // 0x801AD3F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AD3F8: lw          $v0, -0xFEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XFEC);
    // 0x801AD3FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AD400: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x801AD404: bne         $t1, $v0, L_801AD44C
    if (ctx->r9 != ctx->r2) {
        // 0x801AD408: nop
    
            goto L_801AD44C;
    }
    // 0x801AD408: nop

    // 0x801AD40C: beq         $at, $zero, L_801AD418
    if (ctx->r1 == 0) {
        // 0x801AD410: andi        $a0, $a1, 0xFF
        ctx->r4 = ctx->r5 & 0XFF;
            goto L_801AD418;
    }
    // 0x801AD410: andi        $a0, $a1, 0xFF
    ctx->r4 = ctx->r5 & 0XFF;
    // 0x801AD414: andi        $a0, $a2, 0xFF
    ctx->r4 = ctx->r6 & 0XFF;
L_801AD418:
    // 0x801AD418: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801AD41C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x801AD420: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x801AD424: jal         0x8001D15C
    // 0x801AD428: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Audio_SetSfxMapModulation(rdram, ctx);
        goto after_4;
    // 0x801AD428: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_4:
    // 0x801AD42C: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AD430: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801AD434: lw          $v0, -0xFEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XFEC);
    // 0x801AD438: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x801AD43C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801AD440: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AD444: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AD448: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
L_801AD44C:
    // 0x801AD44C: bne         $v0, $zero, L_801AD4A4
    if (ctx->r2 != 0) {
        // 0x801AD450: nop
    
            goto L_801AD4A4;
    }
    // 0x801AD450: nop

    // 0x801AD454: bne         $a3, $t1, L_801AD4A4
    if (ctx->r7 != ctx->r9) {
        // 0x801AD458: lui         $a0, 0x800C
        ctx->r4 = S32(0X800C << 16);
            goto L_801AD4A4;
    }
    // 0x801AD458: lui         $a0, 0x800C
    ctx->r4 = S32(0X800C << 16);
    // 0x801AD45C: lui         $a1, 0x1100
    ctx->r5 = S32(0X1100 << 16);
    // 0x801AD460: ori         $a1, $a1, 0x204C
    ctx->r5 = ctx->r5 | 0X204C;
    // 0x801AD464: addiu       $a0, $a0, 0x5D28
    ctx->r4 = ADD32(ctx->r4, 0X5D28);
    // 0x801AD468: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x801AD46C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x801AD470: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    // 0x801AD474: jal         0x8001D10C
    // 0x801AD478: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    Audio_PlaySfxModulated(rdram, ctx);
        goto after_5;
    // 0x801AD478: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x801AD47C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AD480: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD484: sw          $t1, -0xFEC($at)
    MEM_W(-0XFEC, ctx->r1) = ctx->r9;
    // 0x801AD488: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AD48C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801AD490: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x801AD494: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801AD498: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801AD49C: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801AD4A0: lw          $v0, -0xFEC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XFEC);
L_801AD4A4:
    // 0x801AD4A4: bne         $t1, $v0, L_801AD4F0
    if (ctx->r9 != ctx->r2) {
        // 0x801AD4A8: nop
    
            goto L_801AD4F0;
    }
    // 0x801AD4A8: nop

    // 0x801AD4AC: bne         $a3, $zero, L_801AD4F0
    if (ctx->r7 != 0) {
        // 0x801AD4B0: nop
    
            goto L_801AD4F0;
    }
    // 0x801AD4B0: nop

    // 0x801AD4B4: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    // 0x801AD4B8: nop

    // 0x801AD4BC: bc1f        L_801AD4F0
    if (!c1cs) {
        // 0x801AD4C0: nop
    
            goto L_801AD4F0;
    }
    // 0x801AD4C0: nop

    // 0x801AD4C4: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x801AD4C8: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x801AD4CC: ori         $a0, $a0, 0x204C
    ctx->r4 = ctx->r4 | 0X204C;
    // 0x801AD4D0: bc1f        L_801AD4F0
    if (!c1cs) {
        // 0x801AD4D4: nop
    
            goto L_801AD4F0;
    }
    // 0x801AD4D4: nop

    // 0x801AD4D8: jal         0x8001A838
    // 0x801AD4DC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    Audio_KillSfxById(rdram, ctx);
        goto after_6;
    // 0x801AD4DC: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_6:
    // 0x801AD4E0: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD4E4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801AD4E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AD4EC: sw          $zero, -0xFEC($at)
    MEM_W(-0XFEC, ctx->r1) = 0;
L_801AD4F0:
    // 0x801AD4F0: lui         $t2, 0x8017
    ctx->r10 = S32(0X8017 << 16);
    // 0x801AD4F4: lw          $t2, 0x7AF8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7AF8);
    // 0x801AD4F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x801AD4FC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AD500: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801AD504: subu        $t3, $t3, $t2
    ctx->r11 = SUB32(ctx->r11, ctx->r10);
    // 0x801AD508: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x801AD50C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x801AD510: lhu         $v0, -0x2780($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X2780);
    // 0x801AD514: addiu       $v1, $v1, -0x25EC
    ctx->r3 = ADD32(ctx->r3, -0X25EC);
    // 0x801AD518: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801AD51C: andi        $t4, $v0, 0x10
    ctx->r12 = ctx->r2 & 0X10;
    // 0x801AD520: beq         $t4, $zero, L_801AD554
    if (ctx->r12 == 0) {
        // 0x801AD524: andi        $t5, $v0, 0x2000
        ctx->r13 = ctx->r2 & 0X2000;
            goto L_801AD554;
    }
    // 0x801AD524: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
    // 0x801AD528: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801AD52C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AD530: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AD534: lwc1        $f6, 0x7B88($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7B88);
    // 0x801AD538: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x801AD53C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x801AD540: nop

    // 0x801AD544: bc1f        L_801AD554
    if (!c1cs) {
        // 0x801AD548: nop
    
            goto L_801AD554;
    }
    // 0x801AD548: nop

    // 0x801AD54C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801AD550: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_801AD554:
    // 0x801AD554: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AD558: beq         $t5, $zero, L_801AD590
    if (ctx->r13 == 0) {
        // 0x801AD55C: addiu       $v1, $v1, -0x25EC
        ctx->r3 = ADD32(ctx->r3, -0X25EC);
            goto L_801AD590;
    }
    // 0x801AD55C: addiu       $v1, $v1, -0x25EC
    ctx->r3 = ADD32(ctx->r3, -0X25EC);
    // 0x801AD560: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801AD564: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801AD568: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801AD56C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AD570: lwc1        $f4, 0x7B8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7B8C);
    // 0x801AD574: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801AD578: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x801AD57C: nop

    // 0x801AD580: bc1fl       L_801AD594
    if (!c1cs) {
        // 0x801AD584: andi        $t6, $v0, 0x8
        ctx->r14 = ctx->r2 & 0X8;
            goto L_801AD594;
    }
    goto skip_4;
    // 0x801AD584: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    skip_4:
    // 0x801AD588: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801AD58C: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_801AD590:
    // 0x801AD590: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
L_801AD594:
    // 0x801AD594: beq         $t6, $zero, L_801AD5D4
    if (ctx->r14 == 0) {
        // 0x801AD598: andi        $t7, $v0, 0x4
        ctx->r15 = ctx->r2 & 0X4;
            goto L_801AD5D4;
    }
    // 0x801AD598: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x801AD59C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AD5A0: addiu       $v1, $v1, -0x25FC
    ctx->r3 = ADD32(ctx->r3, -0X25FC);
    // 0x801AD5A4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801AD5A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801AD5AC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801AD5B0: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x801AD5B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AD5B8: sub.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x801AD5BC: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801AD5C0: nop

    // 0x801AD5C4: bc1fl       L_801AD5D8
    if (!c1cs) {
        // 0x801AD5C8: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_801AD5D8;
    }
    goto skip_5;
    // 0x801AD5C8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    skip_5:
    // 0x801AD5CC: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801AD5D0: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_801AD5D4:
    // 0x801AD5D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
L_801AD5D8:
    // 0x801AD5D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x801AD5DC: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AD5E0: beq         $t7, $zero, L_801AD610
    if (ctx->r15 == 0) {
        // 0x801AD5E4: addiu       $v1, $v1, -0x25FC
        ctx->r3 = ADD32(ctx->r3, -0X25FC);
            goto L_801AD610;
    }
    // 0x801AD5E4: addiu       $v1, $v1, -0x25FC
    ctx->r3 = ADD32(ctx->r3, -0X25FC);
    // 0x801AD5E8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801AD5EC: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801AD5F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AD5F4: add.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x801AD5F8: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x801AD5FC: nop

    // 0x801AD600: bc1fl       L_801AD614
    if (!c1cs) {
        // 0x801AD604: andi        $t8, $v0, 0x2
        ctx->r24 = ctx->r2 & 0X2;
            goto L_801AD614;
    }
    goto skip_6;
    // 0x801AD604: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    skip_6:
    // 0x801AD608: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801AD60C: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_801AD610:
    // 0x801AD610: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
L_801AD614:
    // 0x801AD614: beq         $t8, $zero, L_801AD64C
    if (ctx->r24 == 0) {
        // 0x801AD618: andi        $t9, $v0, 0x1
        ctx->r25 = ctx->r2 & 0X1;
            goto L_801AD64C;
    }
    // 0x801AD618: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x801AD61C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AD620: addiu       $v1, $v1, -0x2600
    ctx->r3 = ADD32(ctx->r3, -0X2600);
    // 0x801AD624: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801AD628: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x801AD62C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801AD630: add.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x801AD634: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x801AD638: nop

    // 0x801AD63C: bc1f        L_801AD64C
    if (!c1cs) {
        // 0x801AD640: nop
    
            goto L_801AD64C;
    }
    // 0x801AD640: nop

    // 0x801AD644: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801AD648: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_801AD64C:
    // 0x801AD64C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801AD650: beq         $t9, $zero, L_801AD680
    if (ctx->r25 == 0) {
        // 0x801AD654: addiu       $v1, $v1, -0x2600
        ctx->r3 = ADD32(ctx->r3, -0X2600);
            goto L_801AD680;
    }
    // 0x801AD654: addiu       $v1, $v1, -0x2600
    ctx->r3 = ADD32(ctx->r3, -0X2600);
    // 0x801AD658: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801AD65C: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x801AD660: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801AD664: sub.s       $f0, $f10, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x801AD668: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x801AD66C: nop

    // 0x801AD670: bc1f        L_801AD680
    if (!c1cs) {
        // 0x801AD674: nop
    
            goto L_801AD680;
    }
    // 0x801AD674: nop

    // 0x801AD678: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x801AD67C: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
L_801AD680:
    // 0x801AD680: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AD684: lw          $v0, -0xFF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XFF0);
    // 0x801AD688: bne         $v0, $zero, L_801AD6E0
    if (ctx->r2 != 0) {
        // 0x801AD68C: nop
    
            goto L_801AD6E0;
    }
    // 0x801AD68C: nop

    // 0x801AD690: bne         $t0, $t1, L_801AD6E0
    if (ctx->r8 != ctx->r9) {
        // 0x801AD694: lui         $a3, 0x800C
        ctx->r7 = S32(0X800C << 16);
            goto L_801AD6E0;
    }
    // 0x801AD694: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x801AD698: lui         $t2, 0x800C
    ctx->r10 = S32(0X800C << 16);
    // 0x801AD69C: addiu       $a3, $a3, 0x5D34
    ctx->r7 = ADD32(ctx->r7, 0X5D34);
    // 0x801AD6A0: addiu       $t2, $t2, 0x5D3C
    ctx->r10 = ADD32(ctx->r10, 0X5D3C);
    // 0x801AD6A4: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x801AD6A8: lui         $a1, 0x800C
    ctx->r5 = S32(0X800C << 16);
    // 0x801AD6AC: addiu       $a1, $a1, 0x5D28
    ctx->r5 = ADD32(ctx->r5, 0X5D28);
    // 0x801AD6B0: ori         $a0, $a0, 0x4C
    ctx->r4 = ctx->r4 | 0X4C;
    // 0x801AD6B4: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x801AD6B8: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    // 0x801AD6BC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801AD6C0: jal         0x80019218
    // 0x801AD6C4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    Audio_PlaySfx(rdram, ctx);
        goto after_7;
    // 0x801AD6C4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_7:
    // 0x801AD6C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801AD6CC: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD6D0: sw          $t1, -0xFF0($at)
    MEM_W(-0XFF0, ctx->r1) = ctx->r9;
    // 0x801AD6D4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AD6D8: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801AD6DC: lw          $v0, -0xFF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XFF0);
L_801AD6E0:
    // 0x801AD6E0: bnel        $t1, $v0, L_801AD704
    if (ctx->r9 != ctx->r2) {
        // 0x801AD6E4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801AD704;
    }
    goto skip_7;
    // 0x801AD6E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x801AD6E8: bne         $t0, $zero, L_801AD700
    if (ctx->r8 != 0) {
        // 0x801AD6EC: lui         $a0, 0x1100
        ctx->r4 = S32(0X1100 << 16);
            goto L_801AD700;
    }
    // 0x801AD6EC: lui         $a0, 0x1100
    ctx->r4 = S32(0X1100 << 16);
    // 0x801AD6F0: jal         0x8001A838
    // 0x801AD6F4: ori         $a0, $a0, 0x4C
    ctx->r4 = ctx->r4 | 0X4C;
    Audio_KillSfxById(rdram, ctx);
        goto after_8;
    // 0x801AD6F4: ori         $a0, $a0, 0x4C
    ctx->r4 = ctx->r4 | 0X4C;
    after_8:
    // 0x801AD6F8: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801AD6FC: sw          $zero, -0xFF0($at)
    MEM_W(-0XFF0, ctx->r1) = 0;
L_801AD700:
    // 0x801AD700: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801AD704:
    // 0x801AD704: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801AD708: jr          $ra
    // 0x801AD70C: nop

    return;
    // 0x801AD70C: nop

;}
RECOMP_FUNC void Option_VsStageSelect2_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B3DC: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8019B3E0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8019B3E4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x8019B3E8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x8019B3EC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x8019B3F0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x8019B3F4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x8019B3F8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x8019B3FC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8019B400: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x8019B404: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x8019B408: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x8019B40C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8019B410: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8019B414: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B418: lwc1        $f22, -0xD2C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0XD2C);
    // 0x8019B41C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8019B420: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8019B424: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B428: lui         $s3, 0x801B
    ctx->r19 = S32(0X801B << 16);
    // 0x8019B42C: lui         $s4, 0x801B
    ctx->r20 = S32(0X801B << 16);
    // 0x8019B430: lui         $s5, 0x801B
    ctx->r21 = S32(0X801B << 16);
    // 0x8019B434: lui         $s6, 0x801B
    ctx->r22 = S32(0X801B << 16);
    // 0x8019B438: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8019B43C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8019B440: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x8019B444: addiu       $s6, $s6, -0xD20
    ctx->r22 = ADD32(ctx->r22, -0XD20);
    // 0x8019B448: addiu       $s5, $s5, -0xD18
    ctx->r21 = ADD32(ctx->r21, -0XD18);
    // 0x8019B44C: addiu       $s4, $s4, -0xD08
    ctx->r20 = ADD32(ctx->r20, -0XD08);
    // 0x8019B450: addiu       $s3, $s3, -0xD10
    ctx->r19 = ADD32(ctx->r19, -0XD10);
    // 0x8019B454: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8019B458: addiu       $s1, $sp, 0x8C
    ctx->r17 = ADD32(ctx->r29, 0X8C);
    // 0x8019B45C: addiu       $fp, $zero, -0x100
    ctx->r30 = ADD32(0, -0X100);
    // 0x8019B460: lui         $s7, 0xFA00
    ctx->r23 = S32(0XFA00 << 16);
L_8019B464:
    // 0x8019B464: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8019B468: lw          $t6, 0x1A28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A28);
    // 0x8019B46C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8019B470: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8019B474: bne         $s2, $t6, L_8019B484
    if (ctx->r18 != ctx->r14) {
        // 0x8019B478: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8019B484;
    }
    // 0x8019B478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019B47C: b           L_8019B488
    // 0x8019B480: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
        goto L_8019B488;
    // 0x8019B480: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
L_8019B484:
    // 0x8019B484: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
L_8019B488:
    // 0x8019B488: jal         0x800B8DD0
    // 0x8019B48C: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x8019B48C: addiu       $a1, $zero, 0x55
    ctx->r5 = ADD32(0, 0X55);
    after_0:
    // 0x8019B490: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8019B494: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019B498: addiu       $a3, $zero, 0x30
    ctx->r7 = ADD32(0, 0X30);
    // 0x8019B49C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8019B4A0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8019B4A4: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8019B4A8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8019B4AC: addiu       $t3, $zero, 0x26
    ctx->r11 = ADD32(0, 0X26);
    // 0x8019B4B0: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B4B4: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x8019B4B8: or          $t2, $t1, $fp
    ctx->r10 = ctx->r9 | ctx->r30;
    // 0x8019B4BC: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8019B4C0: lwc1        $f4, -0xD28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XD28);
    // 0x8019B4C4: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8019B4C8: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x8019B4CC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8019B4D0: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x8019B4D4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019B4D8: swc1        $f20, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f20.u32l;
    // 0x8019B4DC: jal         0x8009D0BC
    // 0x8019B4E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_CI8(rdram, ctx);
        goto after_1;
    // 0x8019B4E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8019B4E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019B4E8: jal         0x800B8DD0
    // 0x8019B4EC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    RCP_SetupDL(rdram, ctx);
        goto after_2;
    // 0x8019B4EC: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    after_2:
    // 0x8019B4F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8019B4F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8019B4F8: addiu       $a2, $zero, 0x38
    ctx->r6 = ADD32(0, 0X38);
    // 0x8019B4FC: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8019B500: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8019B504: sw          $s7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r23;
    // 0x8019B508: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8019B50C: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8019B510: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B514: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8019B518: or          $t7, $t6, $fp
    ctx->r15 = ctx->r14 | ctx->r30;
    // 0x8019B51C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8019B520: lwc1        $f8, -0xD28($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XD28);
    // 0x8019B524: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8019B528: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x8019B52C: add.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x8019B530: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x8019B534: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8019B538: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x8019B53C: jal         0x8009D994
    // 0x8019B540: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_3;
    // 0x8019B540: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8019B544: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x8019B548: lwc1        $f16, -0xD24($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XD24);
    // 0x8019B54C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8019B550: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8019B554: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8019B558: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x8019B55C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x8019B560: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8019B564: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    // 0x8019B568: bne         $s2, $at, L_8019B464
    if (ctx->r18 != ctx->r1) {
        // 0x8019B56C: add.s       $f22, $f22, $f16
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
            goto L_8019B464;
    }
    // 0x8019B56C: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x8019B570: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8019B574: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8019B578: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8019B57C: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x8019B580: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x8019B584: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x8019B588: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8019B58C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x8019B590: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x8019B594: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x8019B598: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8019B59C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x8019B5A0: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x8019B5A4: jr          $ra
    // 0x8019B5A8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8019B5A8: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void Option_VsOKConfirm_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019B5AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8019B5B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8019B5B4: lui         $a0, 0x801C
    ctx->r4 = S32(0X801C << 16);
    // 0x8019B5B8: jal         0x8019C824
    // 0x8019B5BC: addiu       $a0, $a0, -0x6E18
    ctx->r4 = ADD32(ctx->r4, -0X6E18);
    Option_Color_FlashRed(rdram, ctx);
        goto after_0;
    // 0x8019B5BC: addiu       $a0, $a0, -0x6E18
    ctx->r4 = ADD32(ctx->r4, -0X6E18);
    after_0:
    // 0x8019B5C0: lui         $v1, 0x801C
    ctx->r3 = S32(0X801C << 16);
    // 0x8019B5C4: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B5C8: lwc1        $f4, -0x6E18($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6E18);
    // 0x8019B5CC: addiu       $v1, $v1, -0x6E14
    ctx->r3 = ADD32(ctx->r3, -0X6E14);
    // 0x8019B5D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8019B5D4: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019B5D8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8019B5DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B5E0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8019B5E4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8019B5E8: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8019B5EC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B5F0: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B5F4: bc1t        L_8019B630
    if (c1cs) {
        // 0x8019B5F8: lui         $t8, 0x8017
        ctx->r24 = S32(0X8017 << 16);
            goto L_8019B630;
    }
    // 0x8019B5F8: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8019B5FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8019B600: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8019B604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8019B608: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8019B60C: lui         $at, 0x801C
    ctx->r1 = S32(0X801C << 16);
    // 0x8019B610: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8019B614: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x8019B618: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8019B61C: c.eq.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl == ctx->f16.fl;
    // 0x8019B620: nop

    // 0x8019B624: bc1f        L_8019B630
    if (!c1cs) {
        // 0x8019B628: nop
    
            goto L_8019B630;
    }
    // 0x8019B628: nop

    // 0x8019B62C: sw          $t7, -0x6E10($at)
    MEM_W(-0X6E10, ctx->r1) = ctx->r15;
L_8019B630:
    // 0x8019B630: lw          $t8, 0x7DB0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7DB0);
    // 0x8019B634: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x8019B638: and         $t9, $t8, $v0
    ctx->r25 = ctx->r24 & ctx->r2;
    // 0x8019B63C: beql        $t9, $zero, L_8019B6CC
    if (ctx->r25 == 0) {
        // 0x8019B640: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8019B6CC;
    }
    goto skip_0;
    // 0x8019B640: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8019B644: jal         0x800B8DD0
    // 0x8019B648: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x8019B648: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_1:
    // 0x8019B64C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8019B650: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8019B654: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8019B658: addiu       $a0, $a0, 0x7E64
    ctx->r4 = ADD32(ctx->r4, 0X7E64);
    // 0x8019B65C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8019B660: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8019B664: andi        $t0, $t1, 0xFF
    ctx->r8 = ctx->r9 & 0XFF;
    // 0x8019B668: sll         $t4, $t0, 16
    ctx->r12 = S32(ctx->r8 << 16);
    // 0x8019B66C: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8019B670: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8019B674: sll         $t6, $t0, 8
    ctx->r14 = S32(ctx->r8 << 8);
    // 0x8019B678: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x8019B67C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8019B680: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8019B684: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x8019B688: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x8019B68C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8019B690: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8019B694: lui         $at, 0x430F
    ctx->r1 = S32(0X430F << 16);
    // 0x8019B698: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8019B69C: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x8019B6A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8019B6A4: lui         $a1, 0x700
    ctx->r5 = S32(0X700 << 16);
    // 0x8019B6A8: addiu       $a1, $a1, 0x3650
    ctx->r5 = ADD32(ctx->r5, 0X3650);
    // 0x8019B6AC: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x8019B6B0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8019B6B4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8019B6B8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8019B6BC: swc1        $f18, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f18.u32l;
    // 0x8019B6C0: jal         0x8009D994
    // 0x8019B6C4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_2;
    // 0x8019B6C4: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8019B6C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8019B6CC:
    // 0x8019B6CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8019B6D0: jr          $ra
    // 0x8019B6D4: nop

    return;
    // 0x8019B6D4: nop

;}
RECOMP_FUNC void Map_GetPathId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A655C: lui         $v0, 0x801B
    ctx->r2 = S32(0X801B << 16);
    // 0x801A6560: addiu       $v0, $v0, -0x2E8
    ctx->r2 = ADD32(ctx->r2, -0X2E8);
    // 0x801A6564: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801A6568: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
L_801A656C:
    // 0x801A656C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x801A6570: bnel        $a0, $t6, L_801A6588
    if (ctx->r4 != ctx->r14) {
        // 0x801A6574: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_801A6588;
    }
    goto skip_0;
    // 0x801A6574: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x801A6578: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x801A657C: beql        $a1, $t7, L_801A6594
    if (ctx->r5 == ctx->r15) {
        // 0x801A6580: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801A6594;
    }
    goto skip_1;
    // 0x801A6580: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x801A6584: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801A6588:
    // 0x801A6588: bne         $v1, $a2, L_801A656C
    if (ctx->r3 != ctx->r6) {
        // 0x801A658C: addiu       $v0, $v0, 0x1C
        ctx->r2 = ADD32(ctx->r2, 0X1C);
            goto L_801A656C;
    }
    // 0x801A658C: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x801A6590: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_801A6594:
    // 0x801A6594: jr          $ra
    // 0x801A6598: nop

    return;
    // 0x801A6598: nop

;}
RECOMP_FUNC void Option_RankInPos_Check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8019C8C4: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8019C8C8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8019C8CC: lui         $v1, 0x8017
    ctx->r3 = S32(0X8017 << 16);
    // 0x8019C8D0: lw          $v1, 0x7B48($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7B48);
    // 0x8019C8D4: lui         $a3, 0x801C
    ctx->r7 = S32(0X801C << 16);
    // 0x8019C8D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8019C8DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8019C8E0: blez        $v1, L_8019C934
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8019C8E4: addiu       $a3, $a3, -0x7DE0
        ctx->r7 = ADD32(ctx->r7, -0X7DE0);
            goto L_8019C934;
    }
    // 0x8019C8E4: addiu       $a3, $a3, -0x7DE0
    ctx->r7 = ADD32(ctx->r7, -0X7DE0);
    // 0x8019C8E8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8019C8EC: addiu       $a0, $t6, 0x7B50
    ctx->r4 = ADD32(ctx->r14, 0X7B50);
    // 0x8019C8F0: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8019C8F4: addu        $a1, $t7, $a0
    ctx->r5 = ADD32(ctx->r15, ctx->r4);
    // 0x8019C8F8: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
L_8019C8FC:
    // 0x8019C8FC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8019C900: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8019C904: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8019C908: and         $t8, $v1, $a2
    ctx->r24 = ctx->r3 & ctx->r6;
    // 0x8019C90C: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8019C910: andi        $t7, $t9, 0x1
    ctx->r15 = ctx->r25 & 0X1;
    // 0x8019C914: andi        $t6, $v1, 0xFF00
    ctx->r14 = ctx->r3 & 0XFF00;
    // 0x8019C918: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8019C91C: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8019C920: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x8019C924: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8019C928: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8019C92C: bne         $at, $zero, L_8019C8FC
    if (ctx->r1 != 0) {
        // 0x8019C930: addu        $v0, $v0, $t6
        ctx->r2 = ADD32(ctx->r2, ctx->r14);
            goto L_8019C8FC;
    }
    // 0x8019C930: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
L_8019C934:
    // 0x8019C934: lui         $a0, 0x8018
    ctx->r4 = S32(0X8018 << 16);
    // 0x8019C938: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8019C93C: addiu       $a1, $a1, -0x7786
    ctx->r5 = ADD32(ctx->r5, -0X7786);
    // 0x8019C940: addiu       $a0, $a0, -0x7790
    ctx->r4 = ADD32(ctx->r4, -0X7790);
    // 0x8019C944: addiu       $v1, $sp, 0x24
    ctx->r3 = ADD32(ctx->r29, 0X24);
L_8019C948:
    // 0x8019C948: lbu         $t8, 0x40($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X40);
    // 0x8019C94C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8019C950: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x8019C954: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8019C958: bne         $at, $zero, L_8019C948
    if (ctx->r1 != 0) {
        // 0x8019C95C: sw          $t8, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r24;
            goto L_8019C948;
    }
    // 0x8019C95C: sw          $t8, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r24;
    // 0x8019C960: lui         $v1, 0x8016
    ctx->r3 = S32(0X8016 << 16);
    // 0x8019C964: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8019C968: lw          $v1, 0x1714($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1714);
    // 0x8019C96C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019C970: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_8019C974:
    // 0x8019C974: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x8019C978: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8019C97C: bnel        $at, $zero, L_8019CAC8
    if (ctx->r1 != 0) {
        // 0x8019C980: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8019CAC8;
    }
    goto skip_0;
    // 0x8019C980: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_0:
    // 0x8019C984: bne         $v1, $t0, L_8019CAB8
    if (ctx->r3 != ctx->r8) {
        // 0x8019C988: lui         $t9, 0x801C
        ctx->r25 = S32(0X801C << 16);
            goto L_8019CAB8;
    }
    // 0x8019C988: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8019C98C: addiu       $t9, $t9, -0x7DB8
    ctx->r25 = ADD32(ctx->r25, -0X7DB8);
    // 0x8019C990: sltu        $at, $a3, $t9
    ctx->r1 = ctx->r7 < ctx->r25 ? 1 : 0;
    // 0x8019C994: beq         $at, $zero, L_8019CAD0
    if (ctx->r1 == 0) {
        // 0x8019C998: or          $t0, $a2, $zero
        ctx->r8 = ctx->r6 | 0;
            goto L_8019CAD0;
    }
    // 0x8019C998: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8019C99C: lui         $t7, 0x801C
    ctx->r15 = S32(0X801C << 16);
    // 0x8019C9A0: addiu       $t7, $t7, -0x7DE0
    ctx->r15 = ADD32(ctx->r15, -0X7DE0);
    // 0x8019C9A4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x8019C9A8: lui         $t5, 0x8017
    ctx->r13 = S32(0X8017 << 16);
    // 0x8019C9AC: lui         $t4, 0x8016
    ctx->r12 = S32(0X8016 << 16);
    // 0x8019C9B0: addiu       $t4, $t4, 0x1AA0
    ctx->r12 = ADD32(ctx->r12, 0X1AA0);
    // 0x8019C9B4: addiu       $t5, $t5, 0x78A0
    ctx->r13 = ADD32(ctx->r13, 0X78A0);
    // 0x8019C9B8: addu        $a3, $a2, $t7
    ctx->r7 = ADD32(ctx->r6, ctx->r15);
L_8019C9BC:
    // 0x8019C9BC: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8019C9C0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8019C9C4: beql        $v1, $t6, L_8019C9D8
    if (ctx->r3 == ctx->r14) {
        // 0x8019C9C8: lw          $t8, 0x0($t5)
        ctx->r24 = MEM_W(ctx->r13, 0X0);
            goto L_8019C9D8;
    }
    goto skip_1;
    // 0x8019C9C8: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    skip_1:
    // 0x8019C9CC: b           L_8019CAD0
    // 0x8019C9D0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_8019CAD0;
    // 0x8019C9D0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8019C9D4: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
L_8019C9D8:
    // 0x8019C9D8: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x8019C9DC: addu        $t2, $a2, $t6
    ctx->r10 = ADD32(ctx->r6, ctx->r14);
    // 0x8019C9E0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8019C9E4: addu        $t7, $t4, $t9
    ctx->r15 = ADD32(ctx->r12, ctx->r25);
    // 0x8019C9E8: lh          $t1, 0x0($t7)
    ctx->r9 = MEM_H(ctx->r15, 0X0);
    // 0x8019C9EC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8019C9F0: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8019C9F4: bnel        $at, $zero, L_8019CAA8
    if (ctx->r1 != 0) {
        // 0x8019C9F8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8019CAA8;
    }
    goto skip_2;
    // 0x8019C9F8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_2:
    // 0x8019C9FC: bne         $t3, $t1, L_8019CA9C
    if (ctx->r11 != ctx->r9) {
        // 0x8019CA00: addiu       $t8, $sp, 0x4C
        ctx->r24 = ADD32(ctx->r29, 0X4C);
            goto L_8019CA9C;
    }
    // 0x8019CA00: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x8019CA04: sltu        $at, $t2, $t8
    ctx->r1 = ctx->r10 < ctx->r24 ? 1 : 0;
    // 0x8019CA08: beq         $at, $zero, L_8019CAD0
    if (ctx->r1 == 0) {
        // 0x8019CA0C: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_8019CAD0;
    }
    // 0x8019CA0C: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x8019CA10: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8019CA14: lui         $t5, 0x801C
    ctx->r13 = S32(0X801C << 16);
    // 0x8019CA18: addiu       $t5, $t5, -0x7DE0
    ctx->r13 = ADD32(ctx->r13, -0X7DE0);
    // 0x8019CA1C: addu        $t2, $t0, $t6
    ctx->r10 = ADD32(ctx->r8, ctx->r14);
    // 0x8019CA20: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
L_8019CA24:
    // 0x8019CA24: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8019CA28: addu        $t7, $t5, $t0
    ctx->r15 = ADD32(ctx->r13, ctx->r8);
    // 0x8019CA2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8019CA30: bne         $t9, $t1, L_8019CA4C
    if (ctx->r25 != ctx->r9) {
        // 0x8019CA34: or          $t3, $zero, $zero
        ctx->r11 = 0 | 0;
            goto L_8019CA4C;
    }
    // 0x8019CA34: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8019CA38: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8019CA3C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8019CA40: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x8019CA44: beq         $v1, $t8, L_8019CA54
    if (ctx->r3 == ctx->r24) {
        // 0x8019CA48: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8019CA54;
    }
    // 0x8019CA48: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
L_8019CA4C:
    // 0x8019CA4C: b           L_8019CAD0
    // 0x8019CA50: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_8019CAD0;
    // 0x8019CA50: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_8019CA54:
    // 0x8019CA54: lui         $t9, 0x801C
    ctx->r25 = S32(0X801C << 16);
    // 0x8019CA58: addiu       $t9, $t9, -0x7E58
    ctx->r25 = ADD32(ctx->r25, -0X7E58);
    // 0x8019CA5C: addu        $t4, $t6, $t9
    ctx->r12 = ADD32(ctx->r14, ctx->r25);
L_8019CA60:
    // 0x8019CA60: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8019CA64: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8019CA68: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8019CA6C: bne         $t3, $s0, L_8019CA60
    if (ctx->r11 != ctx->r16) {
        // 0x8019CA70: addu        $a2, $a2, $t7
        ctx->r6 = ADD32(ctx->r6, ctx->r15);
            goto L_8019CA60;
    }
    // 0x8019CA70: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8019CA74: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8019CA78: beq         $at, $zero, L_8019CA88
    if (ctx->r1 == 0) {
        // 0x8019CA7C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8019CA88;
    }
    // 0x8019CA7C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8019CA80: b           L_8019CAD0
    // 0x8019CA84: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
        goto L_8019CAD0;
    // 0x8019CA84: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_8019CA88:
    // 0x8019CA88: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8019CA8C: bne         $a3, $a0, L_8019CA24
    if (ctx->r7 != ctx->r4) {
        // 0x8019CA90: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8019CA24;
    }
    // 0x8019CA90: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8019CA94: b           L_8019CAD4
    // 0x8019CA98: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8019CAD4;
    // 0x8019CA98: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8019CA9C:
    // 0x8019CA9C: b           L_8019CAD0
    // 0x8019CAA0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
        goto L_8019CAD0;
    // 0x8019CAA0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8019CAA4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_8019CAA8:
    // 0x8019CAA8: bne         $t0, $a0, L_8019C9BC
    if (ctx->r8 != ctx->r4) {
        // 0x8019CAAC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8019C9BC;
    }
    // 0x8019CAAC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8019CAB0: b           L_8019CAD4
    // 0x8019CAB4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8019CAD4;
    // 0x8019CAB4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8019CAB8:
    // 0x8019CAB8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8019CABC: b           L_8019CAD4
    // 0x8019CAC0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8019CAD4;
    // 0x8019CAC0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8019CAC4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8019CAC8:
    // 0x8019CAC8: bne         $a2, $a0, L_8019C974
    if (ctx->r6 != ctx->r4) {
        // 0x8019CACC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8019C974;
    }
    // 0x8019CACC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_8019CAD0:
    // 0x8019CAD0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8019CAD4:
    // 0x8019CAD4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8019CAD8: jr          $ra
    // 0x8019CADC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8019CADC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void Map_Fade_Update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A6A24: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A6A28: addiu       $v1, $v1, -0x26A0
    ctx->r3 = ADD32(ctx->r3, -0X26A0);
    // 0x801A6A2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801A6A30: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801A6A34: addiu       $a1, $a1, -0x7CC0
    ctx->r5 = ADD32(ctx->r5, -0X7CC0);
    // 0x801A6A38: beq         $v0, $zero, L_801A6A50
    if (ctx->r2 == 0) {
        // 0x801A6A3C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_801A6A50;
    }
    // 0x801A6A3C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801A6A40: beq         $v0, $at, L_801A6A70
    if (ctx->r2 == ctx->r1) {
        // 0x801A6A44: lui         $a1, 0x8018
        ctx->r5 = S32(0X8018 << 16);
            goto L_801A6A70;
    }
    // 0x801A6A44: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x801A6A48: jr          $ra
    // 0x801A6A4C: nop

    return;
    // 0x801A6A4C: nop

L_801A6A50:
    // 0x801A6A50: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801A6A54: beq         $v0, $zero, L_801A6A64
    if (ctx->r2 == 0) {
        // 0x801A6A58: addiu       $t6, $v0, -0x5
        ctx->r14 = ADD32(ctx->r2, -0X5);
            goto L_801A6A64;
    }
    // 0x801A6A58: addiu       $t6, $v0, -0x5
    ctx->r14 = ADD32(ctx->r2, -0X5);
    // 0x801A6A5C: jr          $ra
    // 0x801A6A60: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    return;
    // 0x801A6A60: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_801A6A64:
    // 0x801A6A64: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801A6A68: jr          $ra
    // 0x801A6A6C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    return;
    // 0x801A6A6C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_801A6A70:
    // 0x801A6A70: addiu       $a1, $a1, -0x7CC0
    ctx->r5 = ADD32(ctx->r5, -0X7CC0);
    // 0x801A6A74: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801A6A78: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801A6A7C: beq         $a0, $v0, L_801A6A8C
    if (ctx->r4 == ctx->r2) {
        // 0x801A6A80: addiu       $t7, $v0, 0xF
        ctx->r15 = ADD32(ctx->r2, 0XF);
            goto L_801A6A8C;
    }
    // 0x801A6A80: addiu       $t7, $v0, 0xF
    ctx->r15 = ADD32(ctx->r2, 0XF);
    // 0x801A6A84: jr          $ra
    // 0x801A6A88: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    return;
    // 0x801A6A88: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_801A6A8C:
    // 0x801A6A8C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x801A6A90: jr          $ra
    // 0x801A6A94: nop

    return;
    // 0x801A6A94: nop

;}
RECOMP_FUNC void Map_TitleCards_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9910: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801A9914: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801A9918: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A991C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A9920: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x801A9924: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801A9928: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801A992C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x801A9930: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x801A9934: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A9938: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x801A993C: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A9940: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A9944: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801A9948: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801A994C: lw          $t8, 0x6A84($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A84);
    // 0x801A9950: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x801A9954: jal         0x800B8DD0
    // 0x801A9958: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A9958: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    after_0:
    // 0x801A995C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A9960: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801A9964: lui         $at, 0x801D
    ctx->r1 = S32(0X801D << 16);
    // 0x801A9968: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801A996C: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x801A9970: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801A9974: lwc1        $f4, -0x1594($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1594);
    // 0x801A9978: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A997C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A9980: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x801A9984: nop

    // 0x801A9988: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x801A998C: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x801A9990: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801A9994: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x801A9998: lui         $t7, 0x801B
    ctx->r15 = S32(0X801B << 16);
    // 0x801A999C: addiu       $t7, $t7, -0x7CC
    ctx->r15 = ADD32(ctx->r15, -0X7CC);
    // 0x801A99A0: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x801A99A4: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x801A99A8: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x801A99AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801A99B0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801A99B4: blezl       $t8, L_801A9A28
    if (SIGNED(ctx->r24) <= 0) {
        // 0x801A99B8: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801A9A28;
    }
    goto skip_0;
    // 0x801A99B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
    // 0x801A99BC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x801A99C0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801A99C4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A99C8: nop

    // 0x801A99CC: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
L_801A99D0:
    // 0x801A99D0: mtc1        $s0, $f10
    ctx->f10.u32l = ctx->r16;
    // 0x801A99D4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x801A99D8: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801A99DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801A99E0: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A99E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A99E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801A99EC: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x801A99F0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x801A99F4: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x801A99F8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x801A99FC: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x801A9A00: mflo        $t9
    ctx->r25 = lo;
    // 0x801A9A04: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x801A9A08: jal         0x8009D994
    // 0x801A9A0C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    Lib_TextureRect_IA8(rdram, ctx);
        goto after_1;
    // 0x801A9A0C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_1:
    // 0x801A9A10: lw          $t1, 0x8($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X8);
    // 0x801A9A14: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801A9A18: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x801A9A1C: bnel        $at, $zero, L_801A99D0
    if (ctx->r1 != 0) {
        // 0x801A9A20: lw          $v0, 0x4($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X4);
            goto L_801A99D0;
    }
    goto skip_1;
    // 0x801A9A20: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x801A9A24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_801A9A28:
    // 0x801A9A28: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801A9A2C: lui         $s0, 0x801D
    ctx->r16 = S32(0X801D << 16);
    // 0x801A9A30: addiu       $s0, $s0, -0x1590
    ctx->r16 = ADD32(ctx->r16, -0X1590);
    // 0x801A9A34: lui         $a0, 0x801D
    ctx->r4 = S32(0X801D << 16);
    // 0x801A9A38: addiu       $a0, $a0, -0x1594
    ctx->r4 = ADD32(ctx->r4, -0X1594);
    // 0x801A9A3C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x801A9A40: lui         $a1, 0x437F
    ctx->r5 = S32(0X437F << 16);
    // 0x801A9A44: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x801A9A48: jal         0x8009BC2C
    // 0x801A9A4C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    Math_SmoothStepToF(rdram, ctx);
        goto after_2;
    // 0x801A9A4C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_2:
    // 0x801A9A50: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x801A9A54: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A9A58: ldc1        $f8, 0x79E0($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, 0X79E0);
    // 0x801A9A5C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x801A9A60: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801A9A64: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x801A9A68: swc1        $f16, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f16.u32l;
    // 0x801A9A6C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801A9A70: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x801A9A74: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x801A9A78: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801A9A7C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801A9A80: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801A9A84: jr          $ra
    // 0x801A9A88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x801A9A88: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void Map_Area6Ships_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A9448: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x801A944C: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x801A9450: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801A9454: addiu       $s1, $s1, -0xB60
    ctx->r17 = ADD32(ctx->r17, -0XB60);
    // 0x801A9458: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x801A945C: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x801A9460: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x801A9464: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x801A9468: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x801A946C: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x801A9470: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x801A9474: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x801A9478: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x801A947C: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x801A9480: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x801A9484: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x801A9488: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x801A948C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x801A9490: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x801A9494: lw          $t6, 0x5C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X5C);
    // 0x801A9498: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A949C: lui         $v1, 0x801D
    ctx->r3 = S32(0X801D << 16);
    // 0x801A94A0: bne         $t6, $zero, L_801A94B8
    if (ctx->r14 != 0) {
        // 0x801A94A4: nop
    
            goto L_801A94B8;
    }
    // 0x801A94A4: nop

    // 0x801A94A8: lw          $t7, -0x26AC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26AC);
    // 0x801A94AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801A94B0: bnel        $a0, $t7, L_801A97D0
    if (ctx->r4 != ctx->r15) {
        // 0x801A94B4: lw          $ra, 0x84($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X84);
            goto L_801A97D0;
    }
    goto skip_0;
    // 0x801A94B4: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    skip_0:
L_801A94B8:
    // 0x801A94B8: lw          $v1, -0x26AC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X26AC);
    // 0x801A94BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801A94C0: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A94C4: bne         $a0, $v1, L_801A94F4
    if (ctx->r4 != ctx->r3) {
        // 0x801A94C8: addiu       $s0, $zero, -0x1
        ctx->r16 = ADD32(0, -0X1);
            goto L_801A94F4;
    }
    // 0x801A94C8: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x801A94CC: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
    // 0x801A94D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801A94D4: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A94D8: bne         $v0, $at, L_801A94F4
    if (ctx->r2 != ctx->r1) {
        // 0x801A94DC: nop
    
            goto L_801A94F4;
    }
    // 0x801A94DC: nop

    // 0x801A94E0: lw          $t8, -0x26A4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X26A4);
    // 0x801A94E4: beq         $t8, $zero, L_801A94F4
    if (ctx->r24 == 0) {
        // 0x801A94E8: nop
    
            goto L_801A94F4;
    }
    // 0x801A94E8: nop

    // 0x801A94EC: b           L_801A94FC
    // 0x801A94F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
        goto L_801A94FC;
    // 0x801A94F0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_801A94F4:
    // 0x801A94F4: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801A94F8: lw          $v0, -0x26BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X26BC);
L_801A94FC:
    // 0x801A94FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801A9500: beq         $v0, $at, L_801A9510
    if (ctx->r2 == ctx->r1) {
        // 0x801A9504: lui         $s2, 0x8013
        ctx->r18 = S32(0X8013 << 16);
            goto L_801A9510;
    }
    // 0x801A9504: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A9508: bne         $a0, $v1, L_801A9528
    if (ctx->r4 != ctx->r3) {
        // 0x801A950C: addiu       $a1, $zero, 0x2E
        ctx->r5 = ADD32(0, 0X2E);
            goto L_801A9528;
    }
    // 0x801A950C: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
L_801A9510:
    // 0x801A9510: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A9514: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A9518: jal         0x800B8DD0
    // 0x801A951C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A951C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    after_0:
    // 0x801A9520: b           L_801A9564
    // 0x801A9524: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
        goto L_801A9564;
    // 0x801A9524: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
L_801A9528:
    // 0x801A9528: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801A952C: addiu       $s2, $s2, 0x7E64
    ctx->r18 = ADD32(ctx->r18, 0X7E64);
    // 0x801A9530: jal         0x800B8DD0
    // 0x801A9534: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    RCP_SetupDL(rdram, ctx);
        goto after_1;
    // 0x801A9534: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x801A9538: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A953C: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x801A9540: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A9544: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801A9548: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x801A954C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x801A9550: lw          $t1, 0x5C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X5C);
    // 0x801A9554: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801A9558: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A955C: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801A9560: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
L_801A9564:
    // 0x801A9564: lui         $t4, 0x8017
    ctx->r12 = S32(0X8017 << 16);
    // 0x801A9568: lw          $t4, 0x7DB0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X7DB0);
    // 0x801A956C: swc1        $f28, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f28.u32l;
    // 0x801A9570: swc1        $f28, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f28.u32l;
    // 0x801A9574: and         $t5, $t4, $s0
    ctx->r13 = ctx->r12 & ctx->r16;
    // 0x801A9578: beq         $t5, $zero, L_801A97CC
    if (ctx->r13 == 0) {
        // 0x801A957C: swc1        $f28, 0xC0($sp)
        MEM_W(0XC0, ctx->r29) = ctx->f28.u32l;
            goto L_801A97CC;
    }
    // 0x801A957C: swc1        $f28, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f28.u32l;
    // 0x801A9580: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x801A9584: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x801A9588: lui         $t6, 0x602
    ctx->r14 = S32(0X602 << 16);
    // 0x801A958C: addiu       $t6, $t6, -0x1660
    ctx->r14 = ADD32(ctx->r14, -0X1660);
    // 0x801A9590: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A9594: lui         $s1, 0x801B
    ctx->r17 = S32(0X801B << 16);
    // 0x801A9598: lui         $fp, 0x801D
    ctx->r30 = S32(0X801D << 16);
    // 0x801A959C: lui         $s7, 0x801D
    ctx->r23 = S32(0X801D << 16);
    // 0x801A95A0: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x801A95A4: lui         $s3, 0x801D
    ctx->r19 = S32(0X801D << 16);
    // 0x801A95A8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x801A95AC: addiu       $s0, $s0, -0x4C40
    ctx->r16 = ADD32(ctx->r16, -0X4C40);
    // 0x801A95B0: addiu       $s3, $s3, -0x16A0
    ctx->r19 = ADD32(ctx->r19, -0X16A0);
    // 0x801A95B4: addiu       $s4, $s4, -0x4438
    ctx->r20 = ADD32(ctx->r20, -0X4438);
    // 0x801A95B8: addiu       $s7, $s7, -0x25F0
    ctx->r23 = ADD32(ctx->r23, -0X25F0);
    // 0x801A95BC: addiu       $fp, $fp, -0x25F4
    ctx->r30 = ADD32(ctx->r30, -0X25F4);
    // 0x801A95C0: addiu       $s1, $s1, -0x328
    ctx->r17 = ADD32(ctx->r17, -0X328);
    // 0x801A95C4: lwc1        $f26, 0x79D8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X79D8);
    // 0x801A95C8: sw          $t6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r14;
    // 0x801A95CC: addiu       $s6, $sp, 0xC4
    ctx->r22 = ADD32(ctx->r29, 0XC4);
    // 0x801A95D0: addiu       $s5, $sp, 0xB8
    ctx->r21 = ADD32(ctx->r29, 0XB8);
L_801A95D4:
    // 0x801A95D4: jal         0x80005708
    // 0x801A95D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Push(rdram, ctx);
        goto after_2;
    // 0x801A95D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801A95DC: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801A95E0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A95E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A95E8: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x801A95EC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A95F0: jal         0x80005E90
    // 0x801A95F4: nop

    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A95F4: nop

    after_3:
    // 0x801A95F8: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x801A95FC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801A9600: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801A9604: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A9608: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x801A960C: jal         0x80005B00
    // 0x801A9610: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    Matrix_Translate(rdram, ctx);
        goto after_4;
    // 0x801A9610: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    after_4:
    // 0x801A9614: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x801A9618: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A961C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A9620: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801A9624: mul.s       $f16, $f10, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x801A9628: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801A962C: jal         0x80005E90
    // 0x801A9630: nop

    Matrix_RotateY(rdram, ctx);
        goto after_5;
    // 0x801A9630: nop

    after_5:
    // 0x801A9634: jal         0x801AD048
    // 0x801A9638: nop

    Map_CamMatrixRot(rdram, ctx);
        goto after_6;
    // 0x801A9638: nop

    after_6:
    // 0x801A963C: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A9640: lwc1        $f18, 0x6A80($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6A80);
    // 0x801A9644: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A9648: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A964C: mul.s       $f4, $f26, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f18.fl);
    // 0x801A9650: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801A9654: jal         0x80005E90
    // 0x801A9658: nop

    Matrix_RotateY(rdram, ctx);
        goto after_7;
    // 0x801A9658: nop

    after_7:
    // 0x801A965C: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x801A9660: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801A9664: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801A9668: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A966C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A9670: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A9674: jal         0x80005C34
    // 0x801A9678: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_8;
    // 0x801A9678: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    after_8:
    // 0x801A967C: jal         0x80006EB8
    // 0x801A9680: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_9;
    // 0x801A9680: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x801A9684: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801A9688: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801A968C: jal         0x80006970
    // 0x801A9690: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_10;
    // 0x801A9690: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_10:
    // 0x801A9694: lwc1        $f6, 0xA8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XA8);
    // 0x801A9698: lwc1        $f8, 0xC4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801A969C: lwc1        $f18, 0xB0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XB0);
    // 0x801A96A0: lwc1        $f4, 0xCC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x801A96A4: sub.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x801A96A8: lwc1        $f10, 0xAC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XAC);
    // 0x801A96AC: lwc1        $f16, 0xC8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x801A96B0: sub.s       $f22, $f18, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801A96B4: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x801A96B8: sub.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801A96BC: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x801A96C0: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x801A96C4: jal         0x80005100
    // 0x801A96C8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    Math_Atan2F(rdram, ctx);
        goto after_11;
    // 0x801A96C8: sqrt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = sqrtf(ctx->f0.fl);
    after_11:
    // 0x801A96CC: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x801A96D0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x801A96D4: jal         0x80005100
    // 0x801A96D8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    Math_Atan2F(rdram, ctx);
        goto after_12;
    // 0x801A96D8: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_12:
    // 0x801A96DC: lwc1        $f10, 0x0($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X0);
    // 0x801A96E0: neg.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = -ctx->f0.fl;
    // 0x801A96E4: swc1        $f28, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f28.u32l;
    // 0x801A96E8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x801A96EC: swc1        $f28, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f28.u32l;
    // 0x801A96F0: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801A96F4: swc1        $f30, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f30.u32l;
    // 0x801A96F8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A96FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801A9700: mul.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x801A9704: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A9708: jal         0x80005E90
    // 0x801A970C: nop

    Matrix_RotateY(rdram, ctx);
        goto after_13;
    // 0x801A970C: nop

    after_13:
    // 0x801A9710: lwc1        $f8, 0x0($fp)
    ctx->f8.u32l = MEM_W(ctx->r30, 0X0);
    // 0x801A9714: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A9718: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A971C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x801A9720: sub.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x801A9724: mul.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x801A9728: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801A972C: jal         0x80005D44
    // 0x801A9730: nop

    Matrix_RotateX(rdram, ctx);
        goto after_14;
    // 0x801A9730: nop

    after_14:
    // 0x801A9734: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x801A9738: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801A973C: jal         0x80006970
    // 0x801A9740: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    Matrix_MultVec3f(rdram, ctx);
        goto after_15;
    // 0x801A9740: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_15:
    // 0x801A9744: lwc1        $f4, 0xC4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x801A9748: lwc1        $f8, 0xC8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x801A974C: lwc1        $f16, 0xCC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x801A9750: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x801A9754: addiu       $t2, $zero, 0x50
    ctx->r10 = ADD32(0, 0X50);
    // 0x801A9758: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x801A975C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801A9760: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x801A9764: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x801A9768: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801A976C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x801A9770: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x801A9774: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801A9778: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x801A977C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801A9780: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801A9784: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x801A9788: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801A978C: jal         0x8000372C
    // 0x801A9790: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    Lights_SetOneLight(rdram, ctx);
        goto after_16;
    // 0x801A9790: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_16:
    // 0x801A9794: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x801A9798: lui         $t6, 0x600
    ctx->r14 = S32(0X600 << 16);
    // 0x801A979C: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x801A97A0: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x801A97A4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801A97A8: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x801A97AC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801A97B0: jal         0x80005740
    // 0x801A97B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_17;
    // 0x801A97B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x801A97B8: lui         $t8, 0x801B
    ctx->r24 = S32(0X801B << 16);
    // 0x801A97BC: addiu       $t8, $t8, -0x2E8
    ctx->r24 = ADD32(ctx->r24, -0X2E8);
    // 0x801A97C0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x801A97C4: bne         $s1, $t8, L_801A95D4
    if (ctx->r17 != ctx->r24) {
        // 0x801A97C8: nop
    
            goto L_801A95D4;
    }
    // 0x801A97C8: nop

L_801A97CC:
    // 0x801A97CC: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
L_801A97D0:
    // 0x801A97D0: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x801A97D4: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x801A97D8: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x801A97DC: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x801A97E0: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x801A97E4: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x801A97E8: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x801A97EC: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x801A97F0: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x801A97F4: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x801A97F8: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x801A97FC: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x801A9800: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x801A9804: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x801A9808: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x801A980C: jr          $ra
    // 0x801A9810: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x801A9810: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void Map_PathLine_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801AC80C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801AC810: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801AC814: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801AC818: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801AC81C: bne         $a0, $at, L_801AC830
    if (ctx->r4 != ctx->r1) {
        // 0x801AC820: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_801AC830;
    }
    // 0x801AC820: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801AC824: addiu       $a2, $zero, 0xF0
    ctx->r6 = ADD32(0, 0XF0);
    // 0x801AC828: b           L_801AC838
    // 0x801AC82C: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
        goto L_801AC838;
    // 0x801AC82C: addiu       $a3, $zero, 0xA0
    ctx->r7 = ADD32(0, 0XA0);
L_801AC830:
    // 0x801AC830: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x801AC834: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_801AC838:
    // 0x801AC838: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801AC83C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801AC840: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
    // 0x801AC844: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x801AC848: jal         0x800B8DD0
    // 0x801AC84C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801AC84C: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x801AC850: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801AC854: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x801AC858: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC85C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801AC860: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801AC864: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801AC868: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801AC86C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801AC870: lw          $t8, -0x1154($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X1154);
    // 0x801AC874: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x801AC878: ori         $at, $at, 0x5000
    ctx->r1 = ctx->r1 | 0X5000;
    // 0x801AC87C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x801AC880: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x801AC884: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801AC888: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC88C: andi        $t5, $a3, 0xFF
    ctx->r13 = ctx->r7 & 0XFF;
    // 0x801AC890: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x801AC894: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801AC898: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x801AC89C: sll         $t4, $a2, 24
    ctx->r12 = S32(ctx->r6 << 24);
    // 0x801AC8A0: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x801AC8A4: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x801AC8A8: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801AC8AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801AC8B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC8B4: jal         0x80005708
    // 0x801AC8B8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801AC8B8: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_1:
    // 0x801AC8BC: lui         $v0, 0x801D
    ctx->r2 = S32(0X801D << 16);
    // 0x801AC8C0: addiu       $v0, $v0, -0x1150
    ctx->r2 = ADD32(ctx->r2, -0X1150);
    // 0x801AC8C4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC8C8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801AC8CC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801AC8D0: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AC8D4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x801AC8D8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x801AC8DC: jal         0x80005B00
    // 0x801AC8E0: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    Matrix_Translate(rdram, ctx);
        goto after_2;
    // 0x801AC8E0: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    after_2:
    // 0x801AC8E4: jal         0x801AD048
    // 0x801AC8E8: nop

    Map_CamMatrixRot(rdram, ctx);
        goto after_3;
    // 0x801AC8E8: nop

    after_3:
    // 0x801AC8EC: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AC8F0: lwc1        $f4, 0x7B2C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7B2C);
    // 0x801AC8F4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AC8F8: lwc1        $f6, 0x6B30($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6B30);
    // 0x801AC8FC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC900: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    // 0x801AC904: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801AC908: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801AC90C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801AC910: jal         0x80005FE0
    // 0x801AC914: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x801AC914: nop

    after_4:
    // 0x801AC918: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801AC91C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801AC920: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC924: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801AC928: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801AC92C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801AC930: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801AC934: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801AC938: jal         0x80005C34
    // 0x801AC93C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x801AC93C: lw          $a0, -0x4C40($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C40);
    after_5:
    // 0x801AC940: jal         0x80006EB8
    // 0x801AC944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x801AC944: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801AC948: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801AC94C: lui         $t2, 0x605
    ctx->r10 = S32(0X605 << 16);
    // 0x801AC950: addiu       $t2, $t2, -0x2980
    ctx->r10 = ADD32(ctx->r10, -0X2980);
    // 0x801AC954: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801AC958: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801AC95C: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x801AC960: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x801AC964: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x801AC968: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801AC96C: jal         0x80005740
    // 0x801AC970: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x801AC970: addiu       $a0, $a0, -0x4C40
    ctx->r4 = ADD32(ctx->r4, -0X4C40);
    after_7:
    // 0x801AC974: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AC978: lwc1        $f10, 0x6B30($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6B30);
    // 0x801AC97C: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801AC980: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801AC984: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801AC988: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801AC98C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x801AC990: swc1        $f18, 0x6B30($at)
    MEM_W(0X6B30, ctx->r1) = ctx->f18.u32l;
    // 0x801AC994: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801AC998: jr          $ra
    // 0x801AC99C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801AC99C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void Map_PlanetShadow_Draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801A77B0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801A77B4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801A77B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801A77BC: addiu       $s0, $s0, 0x7E64
    ctx->r16 = ADD32(ctx->r16, 0X7E64);
    // 0x801A77C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801A77C4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801A77C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801A77CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801A77D0: jal         0x800B8DD0
    // 0x801A77D4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    RCP_SetupDL(rdram, ctx);
        goto after_0;
    // 0x801A77D4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    after_0:
    // 0x801A77D8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801A77DC: addiu       $s1, $s1, -0x4C40
    ctx->r17 = ADD32(ctx->r17, -0X4C40);
    // 0x801A77E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801A77E4: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801A77E8: lui         $t0, 0x801B
    ctx->r8 = S32(0X801B << 16);
    // 0x801A77EC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801A77F0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801A77F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801A77F8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x801A77FC: addiu       $t0, $t0, -0xB60
    ctx->r8 = ADD32(ctx->r8, -0XB60);
    // 0x801A7800: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x801A7804: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x801A7808: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x801A780C: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x801A7810: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x801A7814: lw          $t1, 0x24($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X24);
    // 0x801A7818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801A781C: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x801A7820: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x801A7824: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x801A7828: jal         0x80005708
    // 0x801A782C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    Matrix_Push(rdram, ctx);
        goto after_1;
    // 0x801A782C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x801A7830: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x801A7834: lui         $t6, 0x801D
    ctx->r14 = S32(0X801D << 16);
    // 0x801A7838: addiu       $t6, $t6, -0x21E0
    ctx->r14 = ADD32(ctx->r14, -0X21E0);
    // 0x801A783C: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x801A7840: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x801A7844: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x801A7848: jal         0x80005680
    // 0x801A784C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Copy(rdram, ctx);
        goto after_2;
    // 0x801A784C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_2:
    // 0x801A7850: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801A7854: lui         $t7, 0x801D
    ctx->r15 = S32(0X801D << 16);
    // 0x801A7858: addiu       $t7, $t7, -0x1F60
    ctx->r15 = ADD32(ctx->r15, -0X1F60);
    // 0x801A785C: beq         $a1, $t7, L_801A7878
    if (ctx->r5 == ctx->r15) {
        // 0x801A7860: lui         $t8, 0x801D
        ctx->r24 = S32(0X801D << 16);
            goto L_801A7878;
    }
    // 0x801A7860: lui         $t8, 0x801D
    ctx->r24 = S32(0X801D << 16);
    // 0x801A7864: addiu       $t8, $t8, -0x2020
    ctx->r24 = ADD32(ctx->r24, -0X2020);
    // 0x801A7868: beq         $a1, $t8, L_801A7878
    if (ctx->r5 == ctx->r24) {
        // 0x801A786C: lui         $t9, 0x801D
        ctx->r25 = S32(0X801D << 16);
            goto L_801A7878;
    }
    // 0x801A786C: lui         $t9, 0x801D
    ctx->r25 = S32(0X801D << 16);
    // 0x801A7870: addiu       $t9, $t9, -0x1FE0
    ctx->r25 = ADD32(ctx->r25, -0X1FE0);
    // 0x801A7874: bne         $a1, $t9, L_801A788C
    if (ctx->r5 != ctx->r25) {
        // 0x801A7878: lui         $a1, 0x4049
        ctx->r5 = S32(0X4049 << 16);
            goto L_801A788C;
    }
L_801A7878:
    // 0x801A7878: lui         $a1, 0x4049
    ctx->r5 = S32(0X4049 << 16);
    // 0x801A787C: ori         $a1, $a1, 0xFDB
    ctx->r5 = ctx->r5 | 0XFDB;
    // 0x801A7880: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A7884: jal         0x80005E90
    // 0x801A7888: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    Matrix_RotateY(rdram, ctx);
        goto after_3;
    // 0x801A7888: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
L_801A788C:
    // 0x801A788C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801A7890: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A7894: lwc1        $f6, 0x7988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x801A7898: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x801A789C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801A78A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801A78A4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801A78A8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801A78AC: jal         0x80005FE0
    // 0x801A78B0: nop

    Matrix_RotateZ(rdram, ctx);
        goto after_4;
    // 0x801A78B0: nop

    after_4:
    // 0x801A78B4: lui         $at, 0x801B
    ctx->r1 = S32(0X801B << 16);
    // 0x801A78B8: lwc1        $f0, 0x798C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X798C);
    // 0x801A78BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801A78C0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801A78C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801A78C8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801A78CC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801A78D0: jal         0x80005C34
    // 0x801A78D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    Matrix_Scale(rdram, ctx);
        goto after_5;
    // 0x801A78D4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_5:
    // 0x801A78D8: jal         0x80006EB8
    // 0x801A78DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    Matrix_SetGfxMtx(rdram, ctx);
        goto after_6;
    // 0x801A78DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801A78E0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801A78E4: lui         $t4, 0x606
    ctx->r12 = S32(0X606 << 16);
    // 0x801A78E8: addiu       $t4, $t4, -0x3DD0
    ctx->r12 = ADD32(ctx->r12, -0X3DD0);
    // 0x801A78EC: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x801A78F0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801A78F4: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
    // 0x801A78F8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x801A78FC: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x801A7900: jal         0x80005740
    // 0x801A7904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    Matrix_Pop(rdram, ctx);
        goto after_7;
    // 0x801A7904: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x801A7908: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801A790C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x801A7910: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x801A7914: jr          $ra
    // 0x801A7918: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801A7918: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
